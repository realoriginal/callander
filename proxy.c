#define _GNU_SOURCE
#include "proxy.h"

#include "axon.h"
#include "darwin.h"
#include "freestanding.h"
#include "resolver.h"
#include "telemetry.h"

#include <errno.h>
#include <limits.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <sched.h>

struct shared_mutex {
	atomic_int state;
};

static inline void shared_mutex_lock_slow_path(struct shared_mutex *mutex, int state)
{
	do {
		if (state == 2 || fs_cmpxchg(&mutex->state, 1, 2) != 0) {
			fs_futex((int *)&mutex->state, FUTEX_WAIT, 2, NULL);
		}
		state = fs_cmpxchg(&mutex->state, 0, 2);
	} while(state);
}

__attribute__((always_inline))
__attribute__((nonnull(1)))
static inline void shared_mutex_lock(struct shared_mutex *mutex)
{
	int state = fs_cmpxchg(&mutex->state, 0, 1);
	if (__builtin_expect(state, 0)) {
		shared_mutex_lock_slow_path(mutex, state);
	}
}

static inline void shared_mutex_unlock_slow_path(struct shared_mutex *mutex)
{
	atomic_store_explicit(&mutex->state, 0, memory_order_relaxed);
	fs_futex((int *)&mutex->state, FUTEX_WAKE, 1, NULL);
}

static inline void shared_mutex_unlock(struct shared_mutex *mutex)
{
	int state = atomic_fetch_sub(&mutex->state, 1);
	if (state != 1) {
		shared_mutex_unlock_slow_path(mutex);
	}
}

static inline uint32_t bitset_for_id(uint32_t id)
{
	return 1 << (id & 0x1f);
}

static inline void shared_mutex_lock_id_slow_path(struct shared_mutex *mutex, uint32_t id, int state)
{
	do {
		intptr_t result;
		if (state == 2) {
			result = FS_SYSCALL(__NR_futex, (intptr_t)&mutex->state, FUTEX_WAIT_BITSET, 2, 0, 0, bitset_for_id(id));
		} else if (state == 1) {
			if (fs_cmpxchg(&mutex->state, 1, 2) != 0) {
				result = FS_SYSCALL(__NR_futex, (intptr_t)&mutex->state, FUTEX_WAIT_BITSET, 2, 0, 0, bitset_for_id(id));
			} else {
				result = 0;
			}
		} else if (state > 2) {
			if (state == (int)((id & ~(1 << 31)) + 3)) {
				atomic_store_explicit(&mutex->state, 2, memory_order_relaxed);
				return;
			}
			result = FS_SYSCALL(__NR_futex, (intptr_t)&mutex->state, FUTEX_WAIT_BITSET, state, 0, 0, bitset_for_id(id));
		} else {
			result = 0;
		}
		if (result < 0) {
			switch (result) {
				case -EINTR:
				case -EAGAIN:
					break;
				default:
					DIE("futex wait bitset failed", fs_strerror(result));
			}
		}
		state = fs_cmpxchg(&mutex->state, 0, 2);
	} while(state);
}

__attribute__((always_inline))
__attribute__((nonnull(1)))
static inline void shared_mutex_lock_id(struct shared_mutex *mutex, uint32_t id)
{
	int state = fs_cmpxchg(&mutex->state, 0, 1);
	if (__builtin_expect(state, 0)) {
		shared_mutex_lock_id_slow_path(mutex, id, state);
	}
}

static inline bool shared_mutex_unlock_handoff(struct shared_mutex *mutex, uint32_t id)
{
	int state = atomic_exchange(&mutex->state, (id & ~(1 << 31)) + 3);
	if (state == 1) {
		return false;
	}
	return FS_SYSCALL(__NR_futex, (intptr_t)&mutex->state, FUTEX_WAKE_BITSET, INT_MAX, 0, 0, bitset_for_id(id)) > 0;
}

#define REUSED_PAGE_COUNT 1024

typedef struct {
	struct shared_mutex write_lock __attribute__((aligned(64)));
	uint32_t current_id;
	struct shared_mutex read_lock __attribute__((aligned(64)));
	union {
		char data[sizeof(response_message)];
		response_message message;
	} response_buffer;
	intptr_t response_cursor;
	int idle_worker_count __attribute__((aligned(64)));
	struct shared_mutex pages_lock __attribute__((aligned(64)));
	uint32_t next_page;
	intptr_t pages[REUSED_PAGE_COUNT];
	uint16_t page_counts[REUSED_PAGE_COUNT];
	struct resolver_config_cache resolver_config_cache;
	hello_message hello;
	int fd_counts[4096];
} shared_page;

static shared_page *shared;

static void setup_shared(void)
{
	void *mapped = fs_mmap(NULL, (sizeof(shared_page) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1), PROT_READ | PROT_WRITE, MAP_SHARED, SHARED_PAGE_FD, 0);
	if (fs_is_map_failed(mapped)) {
		DIE("mmap failed");
	}
	shared_page *expected = NULL;
	if (!atomic_compare_exchange_strong(&shared, &expected, (shared_page *)mapped)) {
		fs_munmap(mapped, (sizeof(shared_page) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1));
	}
}

static void remote_exited(void)
{
	DIE("remote exited");
}

static void read_until_response(intptr_t id)
{
	for (;;) {
		if (shared->response_cursor == sizeof(response_message)) {
			intptr_t read_message_id = shared->response_buffer.message.id;
			if (read_message_id == id) {
				shared->response_cursor = 0;
				shared->response_buffer.message.id = 0;
				return;
			}
			shared_mutex_unlock_handoff(&shared->read_lock, read_message_id);
			shared_mutex_lock_id(&shared->read_lock, id);
			continue;
		}
		for (;;) {
			// read some more bytes
			int result = fs_read(PROXY_FD, &shared->response_buffer.data[shared->response_cursor], sizeof(response_message) - shared->response_cursor);
			if (result <= 0) {
				if (result == -EINTR) {
					continue;
				}
				shared_mutex_unlock(&shared->read_lock);
				if (result == 0) {
					remote_exited();
				}
				DIE("error reading response", fs_strerror(result));
			}
			shared->response_cursor += result;
			break;
		}
	}
}

intptr_t proxy_call(int syscall, proxy_arg args[6])
{
	intptr_t send_id = proxy_send(syscall, args);
	if (syscall & TARGET_NO_RESPONSE) {
		return 0;
	}
	intptr_t result = proxy_wait(send_id, args);
	if ((syscall & PROXY_NO_WORKER) == 0) {
		atomic_fetch_add_explicit(&shared->idle_worker_count, 1, memory_order_relaxed);
	}
	return result;
}

static intptr_t simple_locked_call(int syscall, intptr_t arg1, intptr_t arg2, intptr_t arg3, intptr_t arg4, intptr_t arg5, intptr_t arg6)
{
	request_message request;
	request.template.nr = syscall;
	request.template.is_in = 0;
	request.template.is_out = 0;
	request.id = shared->current_id++;
	request.values[0] = arg1;
	request.values[1] = arg2;
	request.values[2] = arg3;
	request.values[3] = arg4;
	request.values[4] = arg5;
	request.values[5] = arg6;
	intptr_t result = fs_write_all(PROXY_FD, (const char *)&request, sizeof(request));
	if (result < (ssize_t)sizeof(request)) {
		if (result >= 0) {
			remote_exited();
		}
		DIE("error during send", fs_strerror(result));
	}
	if (syscall & PROXY_NO_RESPONSE) {
		return 0;
	}
	shared_mutex_lock_id(&shared->read_lock, request.id);
	read_until_response(request.id);
	result = shared->response_buffer.message.result;
	shared_mutex_unlock(&shared->read_lock);
	return result;
}

#define WORKER_STACK_SIZE 2 * 1024 * 1024

static void spawn_worker(void)
{
	switch (proxy_get_target_platform()) {
		case TARGET_PLATFORM_LINUX: {
			intptr_t worker_func_addr = simple_locked_call(TARGET_NR_GET_PROCESS_DATA_ADDRESS, 0, 0, 0, 0, 0, 0);
			intptr_t stack_addr = simple_locked_call(__NR_mmap, 0, WORKER_STACK_SIZE, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS | MAP_STACK | MAP_GROWSDOWN, -1, 0);
			if (fs_is_map_failed((void *)stack_addr)) {
				DIE("unable to map a worker stack", fs_strerror(stack_addr));
				return;
			}
			simple_locked_call(__NR_clone | TARGET_NO_RESPONSE, CLONE_VM | CLONE_FS | CLONE_FILES | CLONE_SYSVSEM | CLONE_SIGHAND | CLONE_THREAD | CLONE_SETTLS, stack_addr + WORKER_STACK_SIZE, 0, 0, 0, worker_func_addr);
			atomic_fetch_add_explicit(&shared->idle_worker_count, 1, memory_order_relaxed);
			break;
		}
		case TARGET_PLATFORM_DARWIN:
			break;
		default:
			unknown_target();
	}
}

intptr_t proxy_send(int syscall, proxy_arg args[6])
{
	if (shared == NULL) {
		setup_shared();
	}
	// prepare request
	request_message request;
	request.template.nr = syscall;
	request.template.is_in = 0;
	request.template.is_out = 0;
	struct iovec iov[7];
	iov[0].iov_base = &request;
	iov[0].iov_len = sizeof(request);
	int vec_index = 1;
	for (int i = 0; i < 6; i++) {
		intptr_t value = args[i].value;
		intptr_t size = args[i].size;
		if (value && size) {
			intptr_t masked_size = size & ~PROXY_ARGUMENT_MASK;
			request.values[i] = masked_size;
			if (size & PROXY_ARGUMENT_INPUT) {
				request.template.is_in |= 1 << i;
				iov[vec_index].iov_base = (void *)value;
				iov[vec_index].iov_len = masked_size;
				vec_index++;
			}
			if (size & PROXY_ARGUMENT_OUTPUT) {
				request.template.is_out |= 1 << i;
			}
		} else {
			request.values[i] = value;
		}
	}
	if ((shared->hello.target_platform == TARGET_PLATFORM_DARWIN) != ((syscall & DARWIN_SYSCALL_BASE) == DARWIN_SYSCALL_BASE)) {
		switch (syscall & ~PROXY_NO_WORKER) {
			case TARGET_NR_PEEK:
				break;
			case TARGET_NR_POKE:
				break;
			case TARGET_NR_CALL:
				break;
			case TARGET_NR_GET_PROCESS_DATA_ADDRESS:
				break;
			default:
				if (shared->hello.target_platform == TARGET_PLATFORM_DARWIN) {
					DIE("attempted to send linux syscall to darwin target", syscall & ~(PROXY_NO_RESPONSE | PROXY_NO_WORKER));
				} else {
					DIE("attempted to send darwin syscall to linux target", (uintptr_t)(syscall & ~(PROXY_NO_RESPONSE | PROXY_NO_WORKER)));
				}
				break;
		}
	}
	shared_mutex_lock(&shared->write_lock);
	if ((syscall & (PROXY_NO_RESPONSE | PROXY_NO_WORKER)) == 0) {
		if (atomic_fetch_sub_explicit(&shared->idle_worker_count, 1, memory_order_relaxed) == 0) {
			spawn_worker();
		}
	}
	request.id = shared->current_id++;
	// write request
	int result = fs_writev_all(PROXY_FD, iov, vec_index);
	shared_mutex_unlock(&shared->write_lock);
	if (result <= 0) {
		if (result == 0) {
			remote_exited();
		}
		if (result == -EFAULT) {
			return -EFAULT;
		}
		DIE("error sending", fs_strerror(result));
	}
	return request.id;
}

intptr_t proxy_wait(intptr_t send_id, proxy_arg args[6])
{
	// prepare to read response data
	struct iovec iov[6];
	int vec_index = 0;
	for (int i = 0; i < 6; i++) {
		intptr_t value = args[i].value;
		intptr_t size = args[i].size;
		if ((size & PROXY_ARGUMENT_MASK) == PROXY_ARGUMENT_MASK && value) {
			iov[vec_index].iov_base = (void *)value;
			iov[vec_index].iov_len = size & ~PROXY_ARGUMENT_MASK;
			vec_index++;
		}
	}
	for (int i = 0; i < 6; i++) {
		intptr_t value = args[i].value;
		intptr_t size = args[i].size;
		if ((size & PROXY_ARGUMENT_MASK) == PROXY_ARGUMENT_OUTPUT && value) {
			iov[vec_index].iov_base = (void *)value;
			iov[vec_index].iov_len = size & ~PROXY_ARGUMENT_MASK;
			vec_index++;
		}
	}
	// read response
	shared_mutex_lock_id(&shared->read_lock, send_id);
	read_until_response(send_id);
	// read response bytes into output buffers
	if (vec_index) {
		intptr_t result = fs_readv_all(PROXY_FD, iov, vec_index);
		if (result <= 0) {
			shared_mutex_unlock(&shared->read_lock);
			if (result == 0) {
				remote_exited();
			}
			DIE("error receiving", fs_strerror(result));
		}
	}
	// return result to caller
	intptr_t result = shared->response_buffer.message.result;
	shared_mutex_unlock(&shared->read_lock);
	return result;
}

enum target_platform proxy_get_target_platform(void)
{
	if (shared == NULL) {
		setup_shared();
	}
	return (enum target_platform)shared->hello.target_platform;
}

void proxy_peek(intptr_t addr, size_t size, void *out_buffer)
{
	PROXY_CALL(TARGET_NR_PEEK | PROXY_NO_WORKER, proxy_value(addr), proxy_out(out_buffer, size));
}

size_t proxy_peek_string(intptr_t addr, size_t buffer_size, void *out_buffer)
{
	char *buffer = out_buffer;
	do {
		intptr_t rounded_up = (addr + PAGE_SIZE) & ~(PAGE_SIZE-1);
		size_t readable_size = rounded_up - addr;
		if (readable_size > buffer_size) {
			readable_size = buffer_size;
		}
		proxy_peek(addr, readable_size, buffer);
		for (size_t i = 0; i < readable_size; i++) {
			if (*buffer == '\0') {
				return buffer - (char *)out_buffer;
			}
			buffer++;
		}
		buffer_size -= readable_size;
		addr += readable_size;
	} while (buffer_size > 0);
	return buffer - (char *)out_buffer;
}

void proxy_poke(intptr_t addr, size_t size, const void *buffer)
{
	PROXY_SEND(TARGET_NR_POKE | PROXY_NO_WORKER, proxy_value(addr), proxy_in(buffer, size));
}

static inline int page_count(size_t size)
{
	return (size + (PAGE_SIZE-1)) / PAGE_SIZE;
}

static intptr_t page_alloc(int page_count)
{
	shared_mutex_lock(&shared->pages_lock);
	for (size_t i = 0; i < shared->next_page; i++) {
		if (shared->page_counts[i] >= page_count) {
			intptr_t result = shared->pages[i];
			if (shared->page_counts[i] > page_count) {
				// split, use head
				shared->pages[i] += page_count;
				shared->page_counts[i] -= page_count;
			} else {
				// use entire
				int last = --shared->next_page;
				shared->page_counts[i] = shared->page_counts[last];
				shared->pages[i] = shared->pages[last];
			}
			shared_mutex_unlock(&shared->pages_lock);
			return result;
		}
	}
	shared_mutex_unlock(&shared->pages_lock);
	intptr_t result = PROXY_CALL(__NR_mmap, proxy_value(0), proxy_value(page_count * PAGE_SIZE), proxy_value(PROT_READ | PROT_WRITE), proxy_value(MAP_PRIVATE | MAP_ANONYMOUS), proxy_value(-1), proxy_value(0));
	if (fs_is_map_failed((void *)result)) {
		DIE("failed to alloc", fs_strerror(result));
	}
	return result;
}

static void page_free(intptr_t addr, int page_count)
{
	intptr_t next = addr + page_count * PAGE_SIZE;
	shared_mutex_lock(&shared->pages_lock);
	for (size_t i = 0; i < shared->next_page; i++) {
		if (shared->pages[i] == next) {
			shared->pages[i] = addr;
			shared->page_counts[i] += page_count;
			shared_mutex_unlock(&shared->pages_lock);
			return;
		}
		if (shared->pages[i] + shared->page_counts[i] * PAGE_SIZE == addr) {
			shared->page_counts[i] += page_count;
			shared_mutex_unlock(&shared->pages_lock);
			return;
		}
	}
	if (shared->next_page == REUSED_PAGE_COUNT) {
		shared_mutex_unlock(&shared->pages_lock);
		// unmap the page
		PROXY_SEND(__NR_munmap | PROXY_NO_RESPONSE, proxy_value(addr), proxy_value(page_count * PAGE_SIZE));
		return;
	}
	int index = shared->next_page++;
	shared->pages[index] = addr;
	shared->page_counts[index] = page_count;
	shared_mutex_unlock(&shared->pages_lock);
}

intptr_t proxy_alloc(size_t size)
{
	if (size == 0) {
		return 0;
	}
	return page_alloc(page_count(size));
}

void proxy_free(intptr_t addr, size_t size)
{
	if (addr == 0) {
		return;
	}
	page_free(addr, page_count(size));
}

void install_proxy(int fd)
{
	// Setup the proxy
	if (fd == -1) {
		int sockfd = fs_socket(AF_INET, SOCK_STREAM, 0);
		if (sockfd < 0) {
			DIE("error creating socket", fs_strerror(sockfd));
		}
		int reuse = 1;
		int result = fs_setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, (const char *)&reuse, sizeof(reuse));
		if (result < 0) {
			DIE("error setting reuseaddr", fs_strerror(result));
		}

		struct sockaddr_in addr;
		addr.sin_family = AF_INET; 
		addr.sin_addr.s_addr = fs_htonl(0);
		addr.sin_port = fs_htons(8484);
		result = fs_bind(sockfd, &addr, sizeof(addr));
		if (result < 0) {
			DIE("error binding", fs_strerror(result));
		}

		result = fs_listen(sockfd, 1);
		if (result < 0) {
			DIE("error listening", fs_strerror(result));
		}

		fd = fs_accept(sockfd, NULL, NULL);
		if (fd < 0) {
			DIE("error accepting", fs_strerror(fd));
		}
		fs_close(sockfd);
	} else {
		int result = fs_fcntl(fd, F_SETFL, O_RDWR);
		if (result < 0) {
			DIE("error setting flags", fs_strerror(result));
		}
	}

	int flags = 1;
	int result = fs_setsockopt(fd, SOL_TCP, TCP_NODELAY, (void *)&flags, sizeof(flags));
	if (result < 0) {
		DIE("Failed to disable nagle on socket", fs_strerror(result));
	}

	if (fd != PROXY_FD) {
		result = fs_dup2(fd, PROXY_FD);
		if (result < 0) {
			DIE("error duping", fs_strerror(result));
		}

		fs_close(fd);
	}

	int memfd = fs_memfd_create("proxy", 0);
	if (result < 0) {
		DIE("unable to create memfd", fs_strerror(result));
	}

	result = fs_ftruncate(memfd, (sizeof(shared_page) + PAGE_SIZE - 1) & ~(PAGE_SIZE - 1));
    if (result == -1) {
		DIE("unable to ftruncate", fs_strerror(result));
	}

	result = fs_dup2(memfd, SHARED_PAGE_FD);
	if (result < 0) {
		DIE("error duping", fs_strerror(result));
	}

	fs_close(memfd);

	setup_shared();
	result = fs_read_all(PROXY_FD, (char *)&shared->hello, sizeof(shared->hello));
	if (result < (intptr_t)sizeof(shared->hello)) {
		if (result == 0) {
			DIE("client disconnected");
		}
		DIE("unable to read startup message", fs_strerror(result));
	}
}

int *get_fd_counts(void)
{
	if (shared == NULL) {
		setup_shared();
	}
	return &shared->fd_counts[0];
}

struct resolver_config_cache *get_resolver_config_cache(void)
{
	if (shared == NULL) {
		setup_shared();
	}
	return &shared->resolver_config_cache;
}

noreturn void unknown_target(void)
{
	switch (shared->hello.target_platform) {
		case TARGET_PLATFORM_LINUX:
			DIE("invalid operation for linux target");
			break;
		case TARGET_PLATFORM_DARWIN:
			DIE("invalid operation for darwin target");
			break;
		default:
			DIE("unknown target platform");
			break;
	}
	__builtin_unreachable();
}

#include "search.h"

#include "freestanding.h"
#include "loader.h"

#include <errno.h>
#include <linux/limits.h>
#include <limits.h>
#include <string.h>

// open_executable_in_paths looks for an executable file matching name in paths 
int open_executable_in_paths(const char *name, const char *paths, bool require_executable, uid_t uid, gid_t gid) {
	// Check for absolute or relative path
	const char *end = fs_strchr(name, '/');
	if (*end != '\0') {
		int result = fs_openat(AT_FDCWD, name, O_RDONLY | O_CLOEXEC, 0);
		if (result < 0) {
			return result;
		}
		if (require_executable) {
			struct fs_stat stat;
			int err = verify_allowed_to_exec(result, &stat, uid, gid);
			if (err < 0) {
				fs_close(result);
				return -ENOEXEC;
			}
		}
		return result;
	}
	if (paths == NULL) {
		return -ENOEXEC;
	}
	// Resolve name inside each of the paths in paths
	size_t name_len = end - name;
	if (name_len > PATH_MAX - 2) {
		return -ENAMETOOLONG;
	}
	// Fill tail
	char buf[PATH_MAX];
	size_t end_pos = PATH_MAX - (name_len + 2);
	buf[end_pos] = '/';
	memcpy(&buf[end_pos + 1], name, name_len + 1);
	const char *path = paths;
	// Try each path
	for (;;) {
		const char *next_path = fs_strchr(path, ':');
		if (next_path != path) {
			size_t path_len = next_path - path;
			if (path[path_len - 1] == '/') {
				--path_len;
			}
			if (path_len <= end_pos) {
				char *full_path = &buf[end_pos - path_len];
				memcpy(full_path, path, path_len);
				int result = fs_openat(AT_FDCWD, full_path, O_RDONLY | O_CLOEXEC, 0);
				if (result >= 0) {
					if (!require_executable) {
						return result;
					}
					struct fs_stat stat;
					if (verify_allowed_to_exec(result, &stat, uid, gid) == 0) {
						return result;
					}
					fs_close(result);
				}
			}
		}
		if (*next_path == '\0') {
			return -EEXIST;
		}
		path = &next_path[1];
	}
}


SYSCALL_DEF(io_setup, 0, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(io_destroy, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(io_submit, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_COUNT_OF(2), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(io_cancel, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(io_getevents, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_COUNT_OF(3), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setxattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2), SYSCALL_ARG_IS_XATTR_FLAGS)
SYSCALL_DEF(lsetxattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2), SYSCALL_ARG_IS_XATTR_FLAGS)
SYSCALL_DEF(fsetxattr, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2), SYSCALL_ARG_IS_XATTR_FLAGS)
SYSCALL_DEF(getxattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2))
SYSCALL_DEF(lgetxattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2))
SYSCALL_DEF(fgetxattr, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2))
SYSCALL_DEF(listxattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(llistxattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(flistxattr, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(removexattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING)
SYSCALL_DEF(lremovexattr, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING)
SYSCALL_DEF(fremovexattr, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_STRING)
SYSCALL_DEF(getcwd, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(lookup_dcookie, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(eventfd2, 0, SYSCALL_ARG_IS_COUNT, SYSCALL_ARG_IS_EVENTFD_FLAGS)
SYSCALL_DEF(epoll_create1, 0, SYSCALL_ARG_IS_EPOLL_FLAGS)
SYSCALL_DEF(epoll_ctl, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER), SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(epoll_pwait, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(dup, SYSCALL_RETURNS_FD, SYSCALL_ARG_IS_FD)
SYSCALL_DEF(dup3, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFLAGS)
SYSCALL_DEF(fcntl, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_FCNTL), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(inotify_init1, 0, SYSCALL_ARG_IS_INOTIFY_INIT_FLAGS)
SYSCALL_DEF(inotify_add_watch, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_INOTIFY_EVENT_MASK)
SYSCALL_DEF(inotify_rm_watch, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(ioctl, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_IOCTL), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(ioprio_set, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(ioprio_get, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(flock, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FLOCK_OPERATION)
SYSCALL_DEF(mknodat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_MODE, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(mkdirat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_MODE)
SYSCALL_DEF(unlinkat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_REMOVEAT_FLAGS)
SYSCALL_DEF(symlinkat, 0, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(linkat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(renameat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(umount2, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_UMOUNT_FLAGS)
SYSCALL_DEF(mount, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF_EMPTY()
SYSCALL_DEF(pivot_root, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(statfs, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(fstatfs, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(truncate, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(ftruncate, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(fallocate, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(faccessat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ACCESS_MODE, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(chdir, 0, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(fchdir, 0, SYSCALL_ARG_IS_FD)
SYSCALL_DEF(chroot, 0, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(fchmod, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_MODE)
SYSCALL_DEF(fchmodat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_MODE, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(fchownat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(fchown, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(openat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_OPEN_FLAGS, SYSCALL_ARG_IS_MODEFLAGS_OF(2))
SYSCALL_DEF(close, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_FD)
SYSCALL_DEF(vhangup, 0)
SYSCALL_DEF(pipe2, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_OFLAGS)
SYSCALL_DEF(quotactl, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getdents64, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1))
SYSCALL_DEF(lseek, SYSCALL_RETURNS_OFFSET, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_SEEK_WHENCE)
SYSCALL_DEF(read, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(write, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(readv, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1))
SYSCALL_DEF(writev, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1))
SYSCALL_DEF(pread64, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(pwrite64, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(preadv, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(pwritev, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(sendfile, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(pselect6, 0, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(ppoll, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(0), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(3))
SYSCALL_DEF(signalfd4, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_SIGNALFD_FLAGS)
SYSCALL_DEF(vmsplice, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_SPLICE_FLAGS)
SYSCALL_DEF(splice, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SPLICE_FLAGS)
SYSCALL_DEF(tee, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(readlinkat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2))
SYSCALL_DEF(newfstatat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(fstat, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sync, 0)
SYSCALL_DEF(fsync, 0, SYSCALL_ARG_IS_FD)
SYSCALL_DEF(fdatasync, 0, SYSCALL_ARG_IS_FD)
SYSCALL_DEF(sync_file_range, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_SYNC_FILE_RANGE_FLAGS)
SYSCALL_DEF(timerfd_create, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_TIMERFD_FLAGS)
SYSCALL_DEF(timerfd_settime, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_TIMERFD_SETTIME_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(timerfd_gettime, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(utimensat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(acct, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(capget, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(capset, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(personality, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER))
SYSCALL_DEF(exit, SYSCALL_RETURNS_NEVER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(exit_group, SYSCALL_RETURNS_NEVER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(waitid, 0, SYSCALL_ARG_IS_WAITIDTYPE, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_WAIT_FLAGS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(set_tid_address, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(unshare, 0, SYSCALL_ARG_IS_UNSHARE_FLAGS)
SYSCALL_DEF(futex, SYSCALL_CAN_BE_FROM_ANYWHERE | SYSCALL_IS_RESTARTABLE, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_FUTEX_OP), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(set_robust_list, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(0))
SYSCALL_DEF(get_robust_list, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(nanosleep, SYSCALL_IS_RESTARTABLE | SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getitimer, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ITIMER_WHICH, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setitimer, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ITIMER_WHICH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(kexec_load, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_COUNT_OF(2), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(init_module, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(delete_module, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(timer_create, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(timer_gettime, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(timer_getoverrun, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(timer_settime, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_TIMER_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(timer_delete, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(clock_settime, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(clock_gettime, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(clock_getres, 0, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(clock_nanosleep, SYSCALL_IS_RESTARTABLE, SYSCALL_ARG_IS_CLOCK_ID, SYSCALL_ARG_IS_TIMER_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(syslog, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(ptrace, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_PTRACE_REQUEST), SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sched_setparam, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sched_setscheduler, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sched_getscheduler, 0, SYSCALL_ARG_IS_PID)
SYSCALL_DEF(sched_getparam, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sched_setaffinity, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_SIZE_OF(2), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sched_getaffinity, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_SIZE_OF(2), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sched_yield, SYSCALL_RETURNS_ERROR)
SYSCALL_DEF(sched_get_priority_max, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(sched_get_priority_min, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(sched_rr_get_interval, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(restart_syscall, SYSCALL_CAN_BE_FROM_ANYWHERE)
SYSCALL_DEF(kill, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_SIGNUM)
SYSCALL_DEF(tkill, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_SIGNUM)
SYSCALL_DEF(tgkill, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_SIGNUM)
SYSCALL_DEF(sigaltstack, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(rt_sigsuspend, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(rt_sigaction, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_SIGNUM, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(rt_sigprocmask, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_SIGHOW, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(rt_sigpending, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(rt_sigtimedwait, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(rt_sigqueueinfo, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(rt_sigreturn, SYSCALL_RETURNS_NEVER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setpriority, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(getpriority, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(reboot, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setregid, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(setgid, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(setreuid, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(setuid, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(setresuid, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(getresuid, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setresgid, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(getresgid, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setfsuid, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(setfsgid, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(times, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setpgid, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(getpgid, 0, SYSCALL_ARG_IS_PID)
SYSCALL_DEF(getsid, 0, SYSCALL_ARG_IS_PID)
SYSCALL_DEF(setsid, 0)
SYSCALL_DEF(getgroups, 0, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setgroups, 0, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(uname, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sethostname, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(setdomainname, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(getrlimit, 0, SYSCALL_ARG_IS_RLIMIT, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setrlimit, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_RLIMIT), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getrusage, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(umask, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(prctl, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_PRCTL), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getcpu, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(gettimeofday, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(settimeofday, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(adjtimex, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getpid, SYSCALL_RETURNS_SELF_PID)
SYSCALL_DEF(getppid, 0)
SYSCALL_DEF(getuid, 0)
SYSCALL_DEF(geteuid, 0)
SYSCALL_DEF(getgid, 0)
SYSCALL_DEF(getegid, 0)
SYSCALL_DEF(gettid, 0)
SYSCALL_DEF(sysinfo, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mq_open, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_OPEN_FLAGS, SYSCALL_ARG_IS_MODEFLAGS_OF(1), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mq_unlink, 0, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(mq_timedsend, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mq_timedreceive, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mq_notify, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mq_getsetattr, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(msgget, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SHM_FLAGS)
SYSCALL_DEF(msgctl, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(msgrcv, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SHM_FLAGS)
SYSCALL_DEF(msgsnd, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_SHM_FLAGS)
SYSCALL_DEF(semget, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SEM_FLAGS)
SYSCALL_DEF(semctl, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SEMCTL_COMMAND, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(semtimedop, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(semop, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1))
SYSCALL_DEF(semget, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SEM_FLAGS)
SYSCALL_DEF(shmctl, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_SHMCTL_COMMAND, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(shmat, SYSCALL_RETURNS_ADDRESS, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SHM_FLAGS)
SYSCALL_DEF(shmdt, 0, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(socket, SYSCALL_RETURNS_FD, SYSCALL_ARG_IS_SOCKET_DOMAIN, SYSCALL_ARG_IS_SOCKET_TYPE, SYSCALL_ARG_IS_SOCKET_PROTOCOL)
SYSCALL_DEF(socketpair, 0, SYSCALL_ARG_IS_SOCKET_DOMAIN, SYSCALL_ARG_IS_SOCKET_TYPE, SYSCALL_ARG_IS_SOCKET_PROTOCOL, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(bind, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(listen, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(accept, SYSCALL_RETURNS_FD, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(connect, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(getsockname, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getpeername, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(sendto, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_MSG_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(4))
SYSCALL_DEF(recvfrom, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_MSG_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(setsockopt, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_SOCKET_LEVEL, SYSCALL_ARG_IS_SOCKET_OPTION, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(3))
SYSCALL_DEF(getsockopt, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_SOCKET_LEVEL, SYSCALL_ARG_IS_SOCKET_OPTION, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(shutdown, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_SHUTDOWN_HOW)
SYSCALL_DEF(sendmsg, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_MSG_FLAGS)
SYSCALL_DEF(recvmsg, SYSCALL_RETURNS_SIZE, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_MSG_FLAGS)
SYSCALL_DEF(readahead, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(brk, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(munmap, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(mremap, SYSCALL_RETURNS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_REMAP_FLAGS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(add_key, 0, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2), SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(request_key, 0, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(keyctl, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(clone, 0, SYSCALL_ARG_IS_CLONEFLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(execve, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mmap, SYSCALL_RETURNS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_PROT, SYSCALL_ARG_IS_MAP_FLAGS, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFFSET)
SYSCALL_DEF(fadvise64, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(swapon, 0, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_SWAP_FLAGS)
SYSCALL_DEF(swapoff, 0, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(mprotect, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_PROT)
SYSCALL_DEF(msync, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_MSYNC_FLAGS)
SYSCALL_DEF(mlock, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(munlock, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(mlockall, 0, SYSCALL_ARG_IS_MLOCKALL_FLAGS)
SYSCALL_DEF(munlockall, 0)
SYSCALL_DEF(mincore, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(2), SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(madvise, SYSCALL_RETURNS_ERROR, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_MADVISE)
SYSCALL_DEF(remap_file_pages, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_PROT, SYSCALL_ARG_IS_OFFSET, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(mbind, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(3), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(get_mempolicy, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(set_mempolicy, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(2))
SYSCALL_DEF(migrate_pages, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_COUNT_OF(2), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(move_pages, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_COUNT_OF(2), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(rt_tgsigqueueinfo, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(perf_event_open, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_PERF_EVENT_OPEN_FLAGS)
SYSCALL_DEF(accept4, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SOCKET_FLAGS)
SYSCALL_DEF(recvmmsg, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_MSG_FLAGS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF(wait4, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_WAIT_FLAGS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(prlimit64, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_RLIMIT), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(fanotify_init, 0, SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(fanotify_mark, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH)
SYSCALL_DEF(name_to_handle_at, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(open_by_handle_at, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_OPEN_FLAGS)
SYSCALL_DEF(clock_adjtime, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(syncfs, 0, SYSCALL_ARG_IS_FD)
SYSCALL_DEF(setns, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_UNSHARE_FLAGS)
SYSCALL_DEF(sendmmsg, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_MSG_FLAGS)
SYSCALL_DEF(process_vm_readv, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(3), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(process_vm_writev, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(3), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(kcmp, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(finit_module, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_MODULE_INIT_FLAGS)
SYSCALL_DEF(sched_setattr, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(sched_getattr, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(renameat2, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(seccomp, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_SECCOMP_OPERATION), SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(getrandom, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_GETRANDOM_FLAGS)
SYSCALL_DEF(memfd_create, 0, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_MEMFD_FLAGS)
SYSCALL_DEF(bpf, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_BPF_COMMAND), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1))
SYSCALL_DEF(execveat, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(userfaultfd, 0, SYSCALL_ARG_IS_USERFAULTFD_FLAGS)
SYSCALL_DEF(membarrier, 0, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_MEMBARRIER_COMMAND), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(mlock2, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(copy_file_range, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(preadv2, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(pwritev2, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(1), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(pkey_mprotect, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_PROT, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(pkey_alloc, 0, SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(pkey_free, 0, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(statx, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_REMOVEAT_FLAGS, SYSCALL_ARG_IS_STATX_MASK, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(io_getevents, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_COUNT_OF(3), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(rseq, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(0), SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(kexec_file_load, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_SIZE_OF(3), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF_EMPTY()
SYSCALL_DEF(pidfd_send_signal, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_SIGNUM, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(io_uring_setup, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(io_uring_enter, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(4))
SYSCALL_DEF(io_uring_register, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(2))
SYSCALL_DEF(open_tree, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(move_mount, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(fsopen, 0, SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(fsconfig, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER), SYSCALL_ARG_IS_STRING, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(fsmount, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(fspick, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(pidfd_open, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(clone3, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0))
SYSCALL_DEF(close_range, 0, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(openat2, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(2))
SYSCALL_DEF(pidfd_getfd, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(faccessat2, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_ACCESS_MODE, SYSCALL_ARG_IS_ACCESSAT_FLAGS)
SYSCALL_DEF(process_madvise, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(epoll_pwait2, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(1), SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(mount_setattr, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PATH, SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(3))
SYSCALL_DEF(quotactl_fd, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_PRESERVED(SYSCALL_ARG_IS_INTEGER), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS)
SYSCALL_DEF(landlock_create_ruleset, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(landlock_add_rule, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(landlock_restrict_self, 0, SYSCALL_ARG_IS_FD, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(memfd_secret, 0, SYSCALL_ARG_IS_MEMFD_FLAGS)
SYSCALL_DEF(process_mrelease, 0, SYSCALL_ARG_IS_PID, SYSCALL_ARG_IS_FLAGS)
SYSCALL_DEF(futex_waitv, SYSCALL_IS_RESTARTABLE, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_COUNT_OF(0), SYSCALL_ARG_IS_FLAGS, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_INTEGER)
SYSCALL_DEF(set_mempolicy_home_node, 0, SYSCALL_ARG_IS_ADDRESS, SYSCALL_ARG_IS_SIZE_OF(0), SYSCALL_ARG_IS_INTEGER, SYSCALL_ARG_IS_FLAGS)

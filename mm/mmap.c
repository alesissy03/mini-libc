// SPDX-License-Identifier: BSD-3-Clause

#include <sys/mman.h>
#include <errno.h>
#include <internal/syscall.h>

void *mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset)
{
	/* TODO: Implement mmap(). */
	long long result = syscall(__NR_mmap, addr, length, prot, flags, fd, offset);
	if (result < 0) {
		errno = -result;
		return MAP_FAILED;
	}
	return (void *)result;
}

void *mremap(void *old_address, size_t old_size, size_t new_size, int flags)
{
	/* TODO: Implement mremap(). */
	long long new_address = syscall(__NR_mremap, old_address, old_size, new_size, flags);
	if (new_address < 0) {
		errno = -new_address;
		return MAP_FAILED;
	}
	return (void *)new_address;
}

int munmap(void *addr, size_t length)
{
	/* TODO: Implement munmap(). */
	int result = (int)syscall(__NR_munmap, addr, length);
	if (result != 0) {
		errno = -result;
		return -1;
	}
	return result;
}

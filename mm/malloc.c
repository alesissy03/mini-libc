// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

void *malloc(size_t size)
{
	/* TODO: Implement malloc(). */
	// taken from stackoverflow
	int *plen;
    int len = size + sizeof( size );
    plen = mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    *plen = len;
    return (void*)(&plen[1]);
}

void *calloc(size_t nmemb, size_t size)
{
	/* TODO: Implement calloc(). */
	int *plen;
    int len = size + sizeof( size );
    plen = mmap(0, len, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);
    *plen = len;
	memset(plen, 0, nmemb * size);
    return (void*)(&plen[1]);
}

void free(void *ptr)
{
	/* TODO: Implement free(). */
	// taken from stackoverflow
	int *plen = (int*)ptr;
    int len;
    plen--;
    len = *plen;
    munmap((void*)plen, len);
}

void *realloc(void *ptr, size_t size)
{
	/* TODO: Implement realloc(). */
	if (ptr == NULL) {
		return malloc(size);
	}
	if (size == 0) {
		free(ptr);
		return NULL;
	}
	void *newptr = malloc(size);
	if (newptr == NULL) {
		return NULL;
	}
	int *plen = (int *)ptr;
	plen--;
	size_t old_size = *plen;
	size_t copy_size = old_size < size ? old_size : size;
	memcpy(newptr, ptr, copy_size);
	free(ptr);
	return newptr;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
	/* TODO: Implement reallocarray(). */
	if (nmemb == 0 || size == 0) {
		free(ptr);
		return NULL;
	}
	size_t new_size = nmemb * size;
	if (ptr == NULL) {
		return malloc(new_size);
	}
	void *newptr = malloc(new_size);
	if (newptr == NULL) {
		return NULL;
	}
	int *plen = (int *)ptr;
	plen--;
	size_t old_size = *plen;
	size_t copy_size = old_size < size ? old_size : new_size;
	memcpy(newptr, ptr, copy_size);
	free(ptr);
	return newptr;
}

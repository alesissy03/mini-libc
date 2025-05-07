// SPDX-License-Identifier: BSD-3-Clause

// overall inspiration from Techie Delight, Aticleworld and Stackoverflow

#include <string.h>

char *strcpy(char *destination, const char *source)
{
	/* TODO: Implement strcpy(). */
	if (destination == NULL) {
		return NULL;
	}
	if (source == NULL) {
		return destination;
	}
	char *ptr = destination;
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return ptr;
}

char *strncpy(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncpy(). */
	if (destination == NULL) {
		return NULL;
	}
	if (source == NULL || len == 0) {
		return destination;
	}
	char *ptr = destination;
	size_t ctr = 0;
	while (*source != '\0') {
		if (ctr == len) {
			break;
		}
		*ptr = *source;
		ptr++;
		source++;
		ctr++;
	}
	while(1) {
		if (ctr == len) {
			break;
		}
		*ptr = '\0';
		ptr++;
		ctr++;
	}
	return destination;
}

char *strcat(char *destination, const char *source)
{
	/* TODO: Implement strcat(). */
	if (destination == NULL) {
		return NULL;
	}
	if (source == NULL) {
		return destination;
	}
	int len = strlen(destination);
	char *ptr = destination;
	for (int i = 0; i < len; i++) {
		destination++;
	}
	while (*source != '\0') {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = '\0';
	return ptr;
}

char *strncat(char *destination, const char *source, size_t len)
{
	/* TODO: Implement strncat(). */
	if (destination == NULL) {
		return NULL;
	}
	if (source == NULL || len == 0) {
		return destination;
	}
	char* ptr = destination + strlen(destination);
	while (*source != '\0' && len--) {
		*ptr = *source;
		ptr++;
		source++;
	}
	*ptr = '\0';
	return destination;
}

int strcmp(const char *str1, const char *str2)
{
	/* TODO: Implement strcmp(). */
	if (strlen(str1) < strlen(str2)) {
		return -1;
	}
	if (strlen(str1) > strlen(str2)) {
		return 1;
	}
	while (*str1 != '\0') {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}
		str1++;
		str2++;
	}
	return 0;
}

int strncmp(const char *str1, const char *str2, size_t len)
{
	/* TODO: Implement strncmp(). */
	if (strlen(str1) < len && strlen(str1) < strlen(str2)) {
		return -1;
	}
	if (strlen(str2) < len && strlen(str2) < strlen(str1)) {
		return 1;
	}
	while (*str1 != '\0' && len != 0) {
		if (*str1 < *str2) {
			return -1;
		} else if (*str1 > *str2) {
			return 1;
		}
		str1++;
		str2++;
		len--;
	}
	return 0;
}

size_t strlen(const char *str)
{
	size_t i = 0;

	for (; *str != '\0'; str++, i++)
		;

	return i;
}

char *strchr(const char *str, int c)
{
	/* TODO: Implement strchr(). */
	if (str == NULL) {
		return NULL;
	}
	while (*str != '\0') {
		if (*str == c) {
			return (char *)str;
		}
		str++;
	}
	return NULL;
}

char *strrchr(const char *str, int c)
{
	/* TODO: Implement strrchr(). */
	if (str == NULL) {
		return NULL;
	}

	char *found = 0;
	while (*str != '\0') {
		if (*str == c) {
			found = (char *)str;
		}
		str++;
	}
	return found;
}

char *strstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strstr(). */
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}
	while (*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;
		while (*n != '\0' && *h == *n) {
			h++;
			n++;
		}
		if (*n == '\0') {
			return (char *)haystack;
		}
		haystack++;
	}
	return NULL;
}

char *strrstr(const char *haystack, const char *needle)
{
	/* TODO: Implement strrstr(). */
	if (haystack == NULL || needle == NULL) {
		return NULL;
	}
	char *found = 0;
	while (*haystack != '\0') {
		const char *h = haystack;
		const char *n = needle;
		while (*n != '\0' && *h == *n) {
			h++;
			n++;
		}
		if (*n == '\0') {
			found = (char *)haystack;
		}
		haystack++;
	}
	return found;
}

void *memcpy(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memcpy(). */
	if (destination == NULL || source == NULL) {
		return NULL;
	}
	char *dest = (char *)destination;
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++) {
		dest[i] = src[i];
	}
	return destination;
}

void *memmove(void *destination, const void *source, size_t num)
{
	/* TODO: Implement memmove(). */
	unsigned char *dest = (unsigned char *)destination;
	const unsigned char *src = (const unsigned char *)source;
	if (dest == src) {
		return destination;
	}
	if (dest < src || dest >= src + num) {
		while (num--) {
			*dest = *src;
			dest++;
			src++;
		}
	} else {
		dest += num - 1;
		src += num -1;
		while (num--) {
			*dest = *src;
			dest--;
			src--;
		}
	}
	return destination;
}

int memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	/* TODO: Implement memcmp(). */
	unsigned char *p1 = (unsigned char *)ptr1;
	unsigned char *p2 = (unsigned char *)ptr2;
	if (ptr1 == ptr2) {
		return 0;
	}
	for (size_t i = 0; i < num; i++) {
		if (*p1 < *p2) {
			return -1;
		} else if (*p1 > *p2) {
			return 1;
		}
		p1++;
		p2++;
	}
	return 0;
}

void *memset(void *source, int value, size_t num)
{
	/* TODO: Implement memset(). */
	char *src = (char *)source;
	for (size_t i = 0; i < num; i++) {
		*src = value;
		src++;
	}
	source = src;
	return source;
}

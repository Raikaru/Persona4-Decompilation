#ifndef RW_SHIM_STRING_H
#define RW_SHIM_STRING_H
#include <stddef.h>
extern void *memcpy(void *dest, const void *src, size_t count);
extern void *memset(void *dest, int value, size_t count);
extern void *memmove(void *dest, const void *src, size_t count);
extern int memcmp(const void *a, const void *b, size_t count);
extern size_t strlen(const char *string);
extern char *strcpy(char *dest, const char *src);
extern char *strncpy(char *dest, const char *src, size_t count);
extern char *strcat(char *dest, const char *src);
extern int strcmp(const char *a, const char *b);
extern int strncmp(const char *a, const char *b, size_t count);
extern char *strchr(const char *string, int ch);
extern char *strrchr(const char *string, int ch);
extern char *strstr(const char *string, const char *sub);
extern char *strncat(char *dest, const char *src, size_t count);
extern char *strtok(char *string, const char *delimiters);
#endif

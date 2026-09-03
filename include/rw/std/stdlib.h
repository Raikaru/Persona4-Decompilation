#ifndef RW_SHIM_STDLIB_H
#define RW_SHIM_STDLIB_H
#include <stddef.h>
extern void *malloc(size_t size);
extern void free(void *ptr);
extern void *realloc(void *ptr, size_t size);
extern void *calloc(size_t count, size_t size);
extern int abs(int value);
extern int atoi(const char *string);
extern long atol(const char *string);
extern double atof(const char *string);
extern void qsort(void *base, size_t count, size_t size, int (*compare)(const void *, const void *));
#endif

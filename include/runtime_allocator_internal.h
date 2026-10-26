#ifndef RUNTIME_ALLOCATOR_INTERNAL_H
#define RUNTIME_ALLOCATOR_INTERNAL_H

#include "type.h"

/* EE pointers, allocation sizes and counts are 32-bit. The cores remain ASM. */
void *calloc(u32 count, u32 size);
void *_calloc_r(void *reent, u32 count, u32 size);
void *malloc(u32 size);
void *_malloc_r(void *reent, u32 size);
void *realloc(void *pointer, u32 size);
void *_realloc_r(void *reent, void *pointer, u32 size);

#endif

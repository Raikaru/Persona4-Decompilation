#ifndef RW_SHIM_STDDEF_H
#define RW_SHIM_STDDEF_H
typedef unsigned int size_t;
typedef int ptrdiff_t;
#ifndef NULL
#define NULL ((void *)0)
#endif
#define offsetof(t, m) ((size_t)&(((t *)0)->m))
#endif

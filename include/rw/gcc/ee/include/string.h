/*
 * The sky2 headers reach for the GCC EE toolchain's string.h by its install
 * path: `#include <../gcc/ee/include/string.h>` in the os/sky ostypes block,
 * which the compiler resolves against every -I directory in turn. This file
 * sits where that relative path lands from include/rw/sky2 (and from
 * include/rw/std), and forwards to the shim the rest of the tree already
 * uses so there is one set of libc prototypes, not two.
 */
#ifndef RW_SHIM_GCC_EE_STRING_H
#define RW_SHIM_GCC_EE_STRING_H
#include <string.h>
#endif /* RW_SHIM_GCC_EE_STRING_H */

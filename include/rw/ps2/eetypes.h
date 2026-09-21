/*
 * eetypes.h - the Emotion Engine scalar types the RenderWare sky2 headers
 * need, for MWCCPS2.
 *
 * The vendored sky2 headers (include/rw/sky2, RenderWare 3.5 PS2 SDK) were
 * exported for Sony's GCC EE toolchain and open with `#include <eetypes.h>`,
 * a Sony SDK header this tree does not carry. Only two of its names are
 * actually reachable from those headers - `long128` and `u_long128`, in the
 * RwInt128 typedefs - and MWCCPS2 spells the 128-bit type `__int128` instead
 * (measured: `long128` is not a keyword, `__int128` compiles at 16 bytes).
 * The remaining fixed-width names are here because Sony's header defines
 * them and driver code reaches for them, not because the RenderWare headers
 * do.
 *
 * `long` is 64 bits under this compiler's EABI64 (measured: sizeof(long) is
 * 8, same as long long), so sky2's `typedef long RwInt64` is already correct
 * and needs no help from here.
 */
#ifndef RW_SHIM_EETYPES_H
#define RW_SHIM_EETYPES_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long s64;
typedef unsigned long u64;
typedef __int128 s128;
typedef unsigned __int128 u128;

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;

typedef __int128 long128;
typedef unsigned __int128 u_long128;

typedef float f32;

#endif /* RW_SHIM_EETYPES_H */

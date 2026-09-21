/*
 * eetypes.h - the Emotion Engine scalar types the CRI sources need, for
 * ee-gcc 2.96.
 *
 * This is deliberately NOT the same file as include/rw/ps2/eetypes.h. That
 * one serves the RenderWare block, which MWCCPS2 compiles, and it spells the
 * 128-bit type `__int128` because that is what Metrowerks accepts. ee-gcc
 * 2.96 predates `__int128` entirely and does not know Sony's `long128`
 * keyword either (both measured), so the same header cannot serve both.
 *
 * Here the 128-bit types use GCC's `mode(TI)`, which this compiler does
 * accept. Only `u_long128` is actually reached, by `dtx.c`'s RPC buffer,
 * where what matters is that it is sixteen bytes and sixteen-byte aligned.
 *
 * See include/cri/ps2/libcdvd.h for how these shims are validated: every
 * function that touches them is compared byte-for-byte against retail, so a
 * wrong width stops matching immediately.
 */
#ifndef CRI_SHIM_EETYPES_H
#define CRI_SHIM_EETYPES_H

typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef long long s64;
typedef unsigned long long u64;
typedef int s128 __attribute__((mode(TI)));
typedef unsigned int u128 __attribute__((mode(TI)));

typedef unsigned char u_char;
typedef unsigned short u_short;
typedef unsigned int u_int;
typedef unsigned long u_long;

typedef int long128 __attribute__((mode(TI)));
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef float f32;

#endif /* CRI_SHIM_EETYPES_H */

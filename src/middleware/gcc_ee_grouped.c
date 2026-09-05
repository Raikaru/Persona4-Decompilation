#include "include_asm.h"
#include "type.h"

/* EE-GCC middleware and runtime, reclassified out of first-party.

   These functions carry a byte-level signature MWCCPS2 b210 provably cannot produce
   and ee-gcc produces exactly:

     * absolute getter - `lui rX,%hi(sym) / jr $ra / load rY,%lo(sym)(rX)` with
       rX != rY. b210 always reuses the destination register for the address.
       Measured on func_004c3410 across 8 source spellings, 4 register/lifetime
       pragmas, all 772 pragma probes and 9,039 permute_ast compiles - never below
       nd 2. Every ee-gcc 2.9/2.95/2.96 at -O2 is exact.
       Scratch: https://decomp.me/scratch/r8hUx
     * framed tail jump - `addiu $sp,-N / sd $ra / ld $ra / j target / addiu $sp,N`.
       b210 emits only 8, 28 or 32 bytes across all 18 combinations of
       optimization_level x tailcall x schedule, never retail's 24.
       ee-gcc2.96 -O2 is exact.

   Location corroborates authorship independently. Ignoring the promoted placeholders
   themselves - counting them would be circular, since they are the thing in question -
   ALL 34 getter-signature and 259 of 265 tail-jump-signature functions in the image
   are flanked by genuine third-party code on both sides, and none lies inside a
   first-party run. The 29 here are the scanned subset still filed as first-party.

   Vendor of the tail-jump/getter groups is deliberately not claimed: 18 sit between CRI ADX functions, one between
   Sony ROFS functions, and the 0x00446-0x0044b block sits between Sony libmc2 and
   CRI ADX with no way to tell which owns it. Filed by toolchain, not vendor.

   This changes no bytes. None of the files these came from is linked, only markers
   moved, and the image and SLUS sha1s are unchanged.
*/

/* tailjump signature; moved from code1_0044.c */
// FUN_004460F0 NONMATCHING
#ifdef NON_MATCHING
void func_004460f0(void) {
    func_00446108();
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004460f0);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B8D8 NONMATCHING
#ifdef NON_MATCHING
s64 func_0044b8d8(s64 arg0) {
    return func_004470f0(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b8d8);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B8F0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0044b8f0(s64 arg0) {
    return func_00447b88(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b8f0);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B908 NONMATCHING
#ifdef NON_MATCHING
s32 func_0044b908(s64 arg0, s32 arg1) {
    return func_00447d00(arg0, arg1);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b908);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B920 NONMATCHING
#ifdef NON_MATCHING
f32 func_0044b920(f32 arg0) {
    return func_00448d10(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b920);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B938 NONMATCHING
#ifdef NON_MATCHING
f32 func_0044b938(f32 arg0) {
    return func_00449120(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b938);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B950 NONMATCHING
#ifdef NON_MATCHING
f32 func_0044b950(f32 arg0, f32 arg1) {
    return func_004494b8(arg0, arg1);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b950);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B968 NONMATCHING
#ifdef NON_MATCHING
f32 func_0044b968(f32 arg0) {
    return func_00449680(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b968);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B980 NONMATCHING
#ifdef NON_MATCHING
f32 func_0044b980(f32 arg0, f32 arg1) {
    return func_00449938(arg0, arg1);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b980);
#endif

/* tailjump signature; moved from code1_0044.c */
// FUN_0044B998 NONMATCHING
#ifdef NON_MATCHING
f32 func_0044b998(f32 arg0) {
    return func_0044a4d0(arg0);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_0044b998);
#endif

/* getter signature; moved from code1_004c.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004C3410 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00714C3C[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004c3410(void)
{
    return D_00714C3C[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c3410);
#endif

/* getter signature; moved from code1_004c.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004CC1E0 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00719998[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004cc1e0(void)
{
    return D_00719998[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc1e0);
#endif

/* getter signature; moved from code1_004d.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004D3190 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00723F20[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_004d3190(void)
{
    return D_00723F20[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3190);
#endif

/* getter signature; moved from code1_004d.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004D3688 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00724E58[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_004d3688(void)
{
    return D_00724E58[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3688);
#endif

/* getter signature; moved from code1_004d.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004D3698 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00724E60[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_004d3698(void)
{
    return D_00724E60[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3698);
#endif

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004E3DA8 NONMATCHING
#ifdef NON_MATCHING
extern u8 D_00731C7C[];
/* measured: schedule on keeps the lbu in the jr delay slot. */
#pragma schedule on
u8 func_004e3da8(void)
{
    return D_00731C7C[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3da8);
#endif

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004E3DB8 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00731C78[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004e3db8(void)
{
    return D_00731C78[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3db8);
#endif

// FUN_004E3DC8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e3dc8);
// FUN_004E3FB0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e3fb0);
/* getter signature; moved from code1_004e.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004E4180 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00731C3C[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004e4180(void)
{
    return D_00731C3C[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4180);
#endif

// FUN_004E4190
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4190);
/* getter signature; moved from code1_004e.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004E4280 NONMATCHING
#ifdef NON_MATCHING
extern s8 D_00731C01[];
/* measured: schedule on keeps the lb in the jr delay slot. */
#pragma schedule on
s8 func_004e4280(void)
{
    return D_00731C01[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4280);
#endif

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004E4290 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00731C34[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004e4290(void)
{
    return D_00731C34[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4290);
#endif

// FUN_004E42A0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e42a0);
// FUN_004E4308
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4308);
// FUN_004E4340
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4340);
// FUN_004E4378
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4378);
// FUN_004E43B0
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e43b0);
// FUN_004E43E8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e43e8);
// FUN_004E43F8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e43f8);
// FUN_004E4438
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4438);
// FUN_004E44D8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e44d8);
// FUN_004E4528
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4528);
// FUN_004E45F8
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e45f8);
// FUN_004E4608
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4608);
// FUN_004E4618
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4618);
// FUN_004E4638
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4638);
// FUN_004E4648
INCLUDE_ASM("asm/nonmatchings/code1_0044", func_004e4648);
/* getter signature; moved from code1_004e.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004E4688 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00731C70[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004e4688(void)
{
    return D_00731C70[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4688);
#endif

/* getter signature; moved from code1_004f.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_004F54B0 NONMATCHING
#ifdef NON_MATCHING
extern u32 D_00743A54[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u32 func_004f54b0(void)
{
    return D_00743A54[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f54b0);
#endif

/* getter signature; moved from code1_0050.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_0050BCA0 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_0074586C[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_0050bca0(void)
{
    return D_0074586C[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bca0);
#endif

/* getter signature; moved from code1_0050.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_0050CA80 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00745878[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_0050ca80(void)
{
    return D_00745878[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ca80);
#endif

/* getter signature; moved from code1_0051.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_00510E40 NONMATCHING
#ifdef NON_MATCHING
extern u8 *D_00745888[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u8 *func_00510e40(void)
{
    return D_00745888[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510e40);
#endif

/* getter signature; moved from code1_0051.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_00513790 NONMATCHING
#ifdef NON_MATCHING
extern u8 *D_00745AC0[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
u8 *func_00513790(void)
{
    return D_00745AC0[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513790);
#endif

/* getter signature; moved from code1_0052.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_005230C8 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00745ABC[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_005230c8(void)
{
    return D_00745ABC[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005230c8);
#endif

/* getter signature; moved from code1_0052.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_0052B9F0 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00745C84[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_0052b9f0(void)
{
    return D_00745C84[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b9f0);
#endif

/* getter signature; moved from code1_0052.c */
/* measured (2026-08-07): nd 2; battery: K&R empty and old-style definitions, named pointer temps, extern D[1]/D[2], D[1]/D[2] indices, u32/s32/pointer return widths, schedule on/off, and optimization_level 1. No form changes retail's $v1 address base versus b210's $v0 result/base reuse. Committed at nd 2. */
// FUN_0052BA10 NONMATCHING
#ifdef NON_MATCHING
extern s32 D_00745C6C[];
/* measured: schedule on keeps the lw in the jr delay slot. */
#pragma schedule on
s32 func_0052ba10(void)
{
    return D_00745C6C[0];
}
/* measured: schedule off brackets the candidate. */
#pragma schedule off
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052ba10);
#endif

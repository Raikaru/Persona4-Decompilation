#include "include_asm.h"
#include "type.h"

/* EE-GCC middleware, reclassified out of first-party.

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

   Vendor is deliberately not claimed: 18 sit between CRI ADX functions, one between
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
// FUN_004C3410 NONMATCHING
#ifdef NON_MATCHING
u32 func_004c3410(void)
{
    u32 segment = 0x00710000;

    return *(u32 *)(segment + 0x4C3C);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004c3410);
#endif

/* getter signature; moved from code1_004c.c */
// FUN_004CC1E0 NONMATCHING
#ifdef NON_MATCHING
u32 func_004cc1e0(void)
{
    u32 segment = 0x00710000;

    return *(u32 *)(segment + 0x9998);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004c", func_004cc1e0);
#endif

/* getter signature; moved from code1_004d.c */
// FUN_004D3190 NONMATCHING
#ifdef NON_MATCHING
s32 func_004d3190(void)
{
    return D_00723F20[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3190);
#endif

/* getter signature; moved from code1_004d.c */
// FUN_004D3688 NONMATCHING
#ifdef NON_MATCHING
s32 func_004d3688(void)
{
    return D_00724E58[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3688);
#endif

/* getter signature; moved from code1_004d.c */
// FUN_004D3698 NONMATCHING
#ifdef NON_MATCHING
s32 func_004d3698(void)
{
    return D_00724E60[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004d", func_004d3698);
#endif

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-03): nd 2 residual = global-address base register only: retail lui $3 + lbu $2, b210 always lui $2 + lbu $2 (base reuses $v0). Tried 16 spellings (array/scalar, pointer local, u32 base cast, literal/segment ptr, volatile, register, opt_level 3, comma, two-stmt, decl-then-assign) - all nd 2. Same floor in code1_004c/004d/004f-0052: 19 accessors tree-wide, none matched. schedule on keeps load in jr delay slot (tail nop is all-zero window padding). */
// FUN_004E3DA8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3da8);

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-03): nd 2 residual = global-address base register only: retail lui $3 + lw $2, b210 always lui $2 + lw $2 (base reuses $v0). Tried 16 spellings (array/scalar, pointer local, u32 base cast, literal/segment ptr, volatile, register, opt_level 3, comma, two-stmt, decl-then-assign) - all nd 2. Same floor in code1_004c/004d/004f-0052: 19 accessors tree-wide, none matched. schedule on keeps load in jr delay slot (tail nop is all-zero window padding). */
// FUN_004E3DB8
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e3db8);

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-03): nd 2 residual = global-address base register only: retail lui $3 + lw $2, b210 always lui $2 + lw $2 (base reuses $v0). Tried 16 spellings (array/scalar, pointer local, u32 base cast, literal/segment ptr, volatile, register, opt_level 3, comma, two-stmt, decl-then-assign) - all nd 2. Same floor in code1_004c/004d/004f-0052: 19 accessors tree-wide, none matched. schedule on keeps load in jr delay slot (tail nop is all-zero window padding). */
// FUN_004E4180
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4180);

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-03): nd 2 residual = global-address base register only: retail lui $3 + lb $2, b210 always lui $2 + lb $2 (base reuses $v0). Tried 16 spellings (array/scalar, pointer local, u32 base cast, literal/segment ptr, volatile, register, opt_level 3, comma, two-stmt, decl-then-assign) - all nd 2. Same floor in code1_004c/004d/004f-0052: 19 accessors tree-wide, none matched. schedule on keeps load in jr delay slot (tail nop is all-zero window padding). */
// FUN_004E4280
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4280);

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-03): nd 2 residual = global-address base register only: retail lui $3 + lw $2, b210 always lui $2 + lw $2 (base reuses $v0). Tried 16 spellings (array/scalar, pointer local, u32 base cast, literal/segment ptr, volatile, register, opt_level 3, comma, two-stmt, decl-then-assign) - all nd 2. Same floor in code1_004c/004d/004f-0052: 19 accessors tree-wide, none matched. schedule on keeps load in jr delay slot (tail nop is all-zero window padding). */
// FUN_004E4290
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4290);

/* getter signature; moved from code1_004e.c */
/* measured (2026-08-03): nd 2 residual = global-address base register only: retail lui $3 + lw $2, b210 always lui $2 + lw $2 (base reuses $v0). Tried 16 spellings (array/scalar, pointer local, u32 base cast, literal/segment ptr, volatile, register, opt_level 3, comma, two-stmt, decl-then-assign) - all nd 2. Same floor in code1_004c/004d/004f-0052: 19 accessors tree-wide, none matched. schedule on keeps load in jr delay slot (tail nop is all-zero window padding). */
// FUN_004E4688
INCLUDE_ASM("asm/nonmatchings/code1_004e", func_004e4688);

/* getter signature; moved from code1_004f.c */
// FUN_004F54B0 NONMATCHING
#ifdef NON_MATCHING
u32 func_004f54b0(void) {
    u32 segment = 0x00740000;
    return *(u32 *)(segment + 0x3a54);
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_004f", func_004f54b0);
#endif

/* getter signature; moved from code1_0050.c */
// FUN_0050BCA0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0050bca0(void)
{
    return D_0074586C[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050bca0);
#endif

/* getter signature; moved from code1_0050.c */
// FUN_0050CA80 NONMATCHING
#ifdef NON_MATCHING
s32 func_0050ca80(void)
{
    return D_00745878[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0050", func_0050ca80);
#endif

/* getter signature; moved from code1_0051.c */
// FUN_00510E40 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00510e40(void) {
    return D_00745888[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00510e40);
#endif

/* getter signature; moved from code1_0051.c */
// FUN_00513790 NONMATCHING
#ifdef NON_MATCHING
u8 *func_00513790(void) {
    return D_00745AC0[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0051", func_00513790);
#endif

/* getter signature; moved from code1_0052.c */
// FUN_005230C8 NONMATCHING
#ifdef NON_MATCHING
s32 func_005230c8(void)
{
    return D_00745ABC[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_005230c8);
#endif

/* getter signature; moved from code1_0052.c */
// FUN_0052B9F0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0052b9f0(void)
{
    return D_00745C84[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052b9f0);
#endif

/* getter signature; moved from code1_0052.c */
// FUN_0052BA10 NONMATCHING
#ifdef NON_MATCHING
s32 func_0052ba10(void)
{
    return D_00745C6C[0];
}
#else
INCLUDE_ASM("asm/nonmatchings/code1_0052", func_0052ba10);
#endif

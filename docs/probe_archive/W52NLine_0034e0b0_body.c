/*
 * Probe archive for func_0034e0b0 (src/promoted/nLine.c).
 *
 * Status: NONMATCHING.  This is the best semantically faithful clean-C
 * floor found during the 2026-09-02 source-shape probes: object 468B,
 * retail window 480B, normalized_diff 35 (reloc-masked).
 *
 * Measurement:
 *   python tools/fndiff.py docs/probe_archive/W52NLine_0034e0b0_body.c \
 *       func_0034e0b0 --addr 0034e0b0
 *
 * The target remains INCLUDE_ASM in src/promoted/nLine.c.  The clean body
 * preserves the retail alpha read before func_00457120, reproduces the
 * complete data flow and all four corner calls, but b210's register
 * allocation and scheduling do not reproduce the retail stream.
 * With the measured peephole/common-subexpression pragmas, the remaining
 * differences are concentrated in the saved-register assignment, alpha
 * narrowing/call setup, commutative add operand order, and the resulting
 * instruction alignment.  No inline asm, volatile access, or
 * register-allocation steering is used here.
 *
 * The lower nd23 alpha-last probe was rejected: it moves the observable
 * alpha field load across func_00457120 without a non-mutation guarantee.
 * Other rejected probes included the prior u8/u32 declaration and alias
 * families, the 96-combination float/alpha source-order search, alternate
 * f0d0 color widths and ABI spellings, and the allowed optimization pragmas.
 * The original build/WBHygiene_func_0034e0b0_archive.txt body measured nd87
 * when directly recompiled; this archive supersedes that stale floor.
 */
#include "type.h"

extern f32 D_008872F8[];
extern f32 D_0088467C[];
extern u8 *func_00457120(void);
extern s16 func_0034e360(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_0034ee90(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2);
extern void func_0034f0d0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3, u8 arg4, u8 arg5, u8 arg6, u8 arg7);

#pragma peephole off
#pragma opt_common_subs off
// FUN_0034E0B0
void func_0034e0b0(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2)
{
    u8 alpha;
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
    alpha = *(u8 *)(arg0 + 0x994);
    y = fparg1 + *(f32 *)(arg0 + 0x9A0);
    x = fparg0 + *(f32 *)(arg0 + 0x99C);
    z = D_008872F8[0] - D_0088467C[0];
    scale = 1.0f / *(f32 *)(func_00457120() + 0x80);
    func_0034f0d0(arg0 + 0x690, x, y, z, scale, 0xFA, 0xE3, 0x27, alpha);
    func_0034f0d0(arg0 + 0x6D0, x, y + 480.0f, z, scale, 0xFA, 0xE3, 0x27, alpha);
    func_0034f0d0(arg0 + 0x710, x + 640.0f, y + 480.0f, z, scale, 0xFA, 0xE3, 0x27, alpha);
    func_0034f0d0(arg0 + 0x750, x + 640.0f, y, z, scale, 0xFA, 0xE3, 0x27, alpha);
    *(s16 *)(arg0 + 0x1670) = func_0034e360(arg0, fparg0, fparg1, 640.0f, 448.0f);
    func_0034ee90(arg0, fparg0, fparg1, fparg2);
}
#pragma opt_common_subs on
#pragma peephole on

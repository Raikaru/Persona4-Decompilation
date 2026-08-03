/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleCalc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(const void *file, u32 line);
extern u32 D_0064E9C0[];
extern u8 *func_00457120(void);
extern u8 *func_003e9700(s32 a0);
extern void func_003e42a0(void *a0, void *a1, void *a2);
extern void func_003e4180(void *a0);
extern void func_0045af60(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, f32 fparg0);
extern void func_003e40b0(f32 *a0, f32 *a1);
extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
extern void func_003dcc70(void *a0, void *a1, void *a2);
extern s32 func_003e0f80(void);
extern void func_003e0870(s32 a0, void *a1, s32 a2, f32 fparg0);
extern void func_003e0f40(s32 a0);
extern f32 D_00761144;
extern f32 D_00761148;
extern f32 D_00761150;
extern f32 D_00761434;
extern f32 D_00761438;
extern f32 D_007614E8;
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern f32 D_00761470;
f32 func_003716d0(f32 fparg0);
typedef struct { f32 x, y, z, w; } ShuffleVec4;
typedef struct { f32 x, y, z; } ShuffleVec3;
typedef struct { f32 v[9]; s32 flag; } ShuffleOut;
f32 func_00373cb0(f32 fparg0, f32 fparg1, s32 arg0, f32 fparg2);
static inline f32 ShfMul(f32 left, f32 right) { return left * right; }
static inline s32 ShfOr(s32 left, s32 right) { return left | right; }

/* measured: retail's `mul.s $f1,$f0,$f1` (const × value) vs mwcc b210's
   `mul.s $f1,$f1,$f0` (value × const) at the 60.0f*var_3 multiply — the ONLY
   differing word (nd 2) once the source uses a value-first inline helper
   ShfMul((f32)var_3, 60.0f) plus a hoisted `s32 w = sp30[0]` local (retail
   re-issues `sra $v1,$a0,1` for the -320.0f divisor instead of CSE-ing the
   shift). Flipping the helper to const-first, plain (60.0f*(f32)var_3), or a
   pre-materialized f32 local makes the constant load hoist before the cvt and
   re-colors var_3 from $v1 to $a1 (nd 51). Commutative FP-mul scheduling
   floor; also tried ternary (nd 55) and two-return forms. nd 2. */
// FUN_00371260
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371260);

/* measured: identical to func_00371260 (same layout, 84.0f instead of
   100.0f): single residual is the commutative `mul.s $f1,$f0,$f1` vs
   `mul.s $f1,$f1,$f0` operand swap at 60.0f*var_3; same spellings tried as
   the 00371260 note, all give nd 2 or worse. FP-mul scheduling floor. nd 2. */
// FUN_003713B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003713b0);

// FUN_00371500
void func_00371500(u8 *arg0, f32 fparg0, u8 *arg1) {
    s32 sp50[8];
    u8 *temp_16;

    temp_16 = func_00457120() + 0x68;
    func_003e8970(&sp50[0], func_003e89c0());
    *(f32 *)(arg1 + 0) = fparg0 * (*(f32 *)temp_16 * (1.0f + (-(*(f32 *)(arg0 + 0)) / (f32)(sp50[0] >> 1))));
    *(f32 *)(arg1 + 4) = fparg0 * (*(f32 *)(temp_16 + 4) * (1.0f + (-(*(f32 *)(arg0 + 4)) / (f32)(sp50[1] >> 1))));
    *(f32 *)(arg1 + 8) = fparg0;
}

// FUN_003715E0
void func_003715e0(u8 *arg0, u8 *arg1, f32 fparg0) {
    f32 temp_f20;
    s32 sp50[8];
    u8 *temp_16;

    temp_f20 = func_003716d0(fparg0);
    temp_16 = func_00457120() + 0x68;
    func_003e8970(&sp50[0], func_003e89c0());
    *(f32 *)(arg1 + 0) = temp_f20 * (*(f32 *)temp_16 * (1.0f + (-(*(f32 *)(arg0 + 0)) / (f32)(sp50[0] >> 1))));
    *(f32 *)(arg1 + 4) = temp_f20 * (*(f32 *)(temp_16 + 4) * (1.0f + (-(*(f32 *)(arg0 + 4)) / (f32)(sp50[1] >> 1))));
    *(f32 *)(arg1 + 8) = temp_f20;
}

/* measured: re-tested this wave. `s32 sp30[8]` (same 8-word pattern as
   func_00371500's sp50[8]) fixes the frame to 0x50 with the slot at 0x30, and
   `temp_2 = func_00457120() + 0x68` reproduces retail's $s0 base hoist. The
   residual (nd 11) is then the recorded $v0/$v1 coalescing — retail keeps the
   load in $v1 and the rounded-half shift result in $v0 (lw $v1/sra $v0/bgez
   $v1/addiu $v0/sra $v0/mtc1 $v0); mwcc b210 always colors load->$v0,
   result->$v1 (6 words) — plus the return's evaluation order (5 words: b210
   hoists the divisor lwc1/mul above the numerator mtc1/cvt and transposes
   the div.s operands; hoisting `f = (f32)var_2` does not move it). Tried
   named locals, m2c if-form, inline two-return, u32/or spellings, hoisted
   cvt — all nd >= 6. $v0/$v1 coalescing + FP-eval-order floor. */
// FUN_003716D0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003716d0);

// FUN_00371780
void func_00371780(u8 *arg0, u8 *arg1) {
    func_003e42a0(arg0, arg1, func_003e9700(*(s32 *)(func_00457120() + 4)));
}

/* measured: best nd 29. Hoisting the ratio ahead of the rounding block
   (retail computes the div chain first) rotates saved regs to $s1/$s0/$s2
   (retail $s2/$s1/$s0; 3 decl orders probed, nd 29), on top of the recorded
   $v0/$v1 rounding-coalescing floor and two mul.s operand swaps. */
// FUN_003717E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003717e0);

// FUN_00371990
void func_00371990(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, f32 fparg1) {
    *(s16 *)(arg0 + 0) = 0;
    *(f32 *)(arg0 + 4) = fparg1;
    *(f32 *)(arg0 + 8) = fparg0;
    if (arg1 != NULL) {
        *(ShuffleVec3 *)(arg0 + 0x18) = *(ShuffleVec3 *)(arg1 + 0);
        *(ShuffleVec3 *)(arg0 + 0xC) = *(ShuffleVec3 *)(arg1 + 0);
    } else {
        *(ShuffleVec3 *)(arg0 + 0x18) = *(ShuffleVec3 *)(arg0 + 0xC);
    }
    if (arg2 == NULL) {
        func_0046d730(&D_0064E9C0, 0x17C);
    }
    *(ShuffleVec3 *)(arg0 + 0x24) = *(ShuffleVec3 *)(arg2 + 0);
}

/* measured: recipe A applied (s32 lhu local, u32 copy, (s32) cast on the
   or-result, x+x doubling) — the old s16-cast note is stale: b210 now emits
   the single bare bltz with clean srl/andi/or in both half-scalers. Residual
   (best nd 60): (1) the increment re-load `lhu` is CSE'd away (candidate
   `addiu $v0,$a0,1` reuses the 1st load, which stays live across the whole
   half-scaler and colors $a0 vs retail $v0 — the recorded Load-CSE floor,
   cf. func_003720c0); (2) the recorded or-fold/cvt-scratch in both arms
   (`or $v0,$v1,$v0` + `cvt.s.w $f0,$f0` vs retail `or $v1,$v1,$v0` +
   `cvt.s.w $f1,$f0`, cf. func_00372960); (3) b210 folds the +0.0f call-arg
   add (retail mtc1 $0/add.s into $f12); (4) the store-lerp compiles to
   adda/madd ACC chains (retail plain mul.s/add.s; split mul/add statements
   tried, identical). Ternary half-scalers (func_003720c0's trick) only
   reverse the srl/andi order here. u16-sign-test residual after recipe. */
// FUN_00371A60
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371a60);

/* measured: retail computes the ceil-half trick as `or $t0,$t0,$v1` (dest = srl
   result reg) in the FIRST negative branch, but mwcc b210 always folds the or
   into $v1 (andi result reg) there while matching retail exactly in the second
   branch; the same 2 words (or/mtc1) differ with every spelling tried:
   ((u32)x>>1)|(x&1), (x&1)|((u32)x>>1), and a `u32 u; u|=…` local (which made
   BOTH branches wrong, nd 4). $v1-register-coloring floor. nd 2. */
// FUN_00371BA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371ba0);

/* measured: full cubic-Bezier reconstruction (recipe A half-scalers,
   00373cb0(var_f12,8,0,4), v = 1.0f - t, per-component f6/f5/f4/f3 terms and
   `t*f3 + v*f4 + t*f5 + t*f6` mula/madda/madda/madd accumulation): components
   1-2 are byte-identical to retail and component 3 differs only in register
   numbers (b210 schedules its P1 chain before the P0 chain and reuses $f1 for
   the P1 term where retail keeps P0 first with $f3/$f4; decl orders tried) —
   on top of the recorded family: the increment's re-load `lhu` is CSE'd with
   the 1st half-scaler's load (1 word missing, value colored $a0 vs retail
   $v0 — Load-CSE, cf. func_003720c0) and the or-fold/cvt-scratch in both
   half-scalers (cf. func_00372960). nd 102, ~30 of it alignment-shift noise.
   Load-CSE + $v1-coloring + FP-scheduling floor. */
// FUN_00371C70
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371c70);

/* measured: same $v1-fold floor as func_00371ba0 — retail `or $a2,$a2,$v1`
   (dest = srl result reg) in the negative half-scaler branch; mwcc b210
   always folds the or into $v1 (andi result reg): 2 words (or/mtc1) differ,
   nd 4 (2 padding). Tried direct ((u32)x>>1)|(x&1), swapped operands
   (nd 6), and an inline ShfOr helper (identical nd 4). Everything else — the
   three struct copies, f0+f0 doubling, store order — matches. $v1
   register-coloring floor. */
// FUN_00371E50
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371e50);

/* measured: best nd 48. Structure, sp50 diffs, call args, arg1 adds all
   match; the lerp must be computed BEFORE the 003e0f80 call (inline-arg
   form puts temp_2 across the call -> spurious saved $s3, frame 0x70).
   Residuals: (1) saved-reg rotation arg0/arg1/temp_16 = s1/s0/s2 vs retail
   s2/s1/s0 (decl orders tried; temp_16 is a plain int local used across
   calls); (2) the half-scaler's recorded or-fold + cvt-scratch (4 words);
   (3) mwcc emits `add.s $f1,$f20,$f0` and `madd.s $f20,$f1,$f2` with the
   SECOND source operand in fs regardless of source order (fparg0-in-fs is
   stable across both operand orders; the madd flip would reverse the
   div/sub evaluation order). FP-add operand-order floor. */
// FUN_00371F40
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371f40);

/* measured: best nd 61. The FP-acc lerp arg and the inline 2nd half-scaler
   (ternary, h+h doubling) match retail, and the or-fold/cvt-scratch floor
   (cf. func_00372960 note) is confined to the 1st half-scaler - but the
   increment's field read `(u16)(*(u16*)(arg0+0) + 1)` is CSE'd by b210 with
   the 1st half-scaler's load (no intervening store), keeping that value
   live across the whole half-scaler: retail re-loads (lhu) before the
   addiu, so the candidate loses 1 word and the long-lived value gets
   colored $a0 (retail $v0), cascading through srl/andi/or/mtc1 (9 words).
   Local-based `(u16)(temp_2+1)` kills the reload (still $a0); inline field
   reads in the half-scaler re-trigger the u16 always-true duplication.
   Load-CSE-coloring floor. Re-tested this wave with recipe A (s32
   local, u32 copy, (s32)-cast or-result, x+x doubling; 1st half-scaler if/else,
   2nd as inline ternary per this note): nd 61 confirmed; the ternary variants
   (hoisted h, fully-inline call arg, swapped arm order) leave the srl/andi
   order reversed or fold the +0.0f and never reach retail's $f0 cvt; the
   load-CSE $a0 cascade dominates the residual. Load-CSE-coloring floor. */
// FUN_003720C0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003720c0);

/* measured: nd 121 with a full C body (wave 6 left this uncommitted and did not
   report it). Object size already equals the 416-byte window, so the residual is
   allocation/scheduling rather than missing work; it needs a fresh attempt with
   the half-scaler recipe proven on func_00372960 in the same file. */
// FUN_00372200
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00372200);

/* measured: same $v1-or-fold floor as func_00371ba0/00371e50, both
   half-scaler branches: retail `or $a0,$a0,$v1` (dest = srl result reg),
   mwcc b210 folds into $v1 (andi result reg) — 4 words (or/mtc1 ×2) differ,
   nd 6 (2 padding). Tried direct and swapped operand orders — identical.
   Everything else (struct copies, assert, f20 store) matches. */
// FUN_003723A0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003723a0);

/* measured: full reconstruction (recipe A half-scalers, 00373cb0(0,var_f12,8,4),
   f32 sp40[3]/sp30[4] stack slots at 0x40/0x30 reproducing retail's 0x3C gap
   and 0x50 frame, func_003e40b0, per-component `f18 + (sp30*t - t*(t*(sp30+
   sp40)))` mula/msub chains) — the ENTIRE tail (diffs, scales, all three
   mula/msub components, epilogue) is byte-identical modulo a 1-word shift:
   b210 CSEs the increment's re-load `lhu` with the 1st half-scaler's load
   (no intervening store), losing 1 word and coloring the long-lived value
   $a0 (retail $v0), cascading through srl/andi/or/mtc1 (nd 91, ~30 of it
   alignment-shift noise), on top of the recorded or-fold/cvt-scratch in both
   half-scalers (cf. func_003720c0/00372960). Load-CSE + $v1-coloring floor. */
// FUN_003724F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003724f0);

/* measured: re-tested with recipe A + full reconstruction (sp40[3]/sp30[4]
   array slots, 003e40b0, per-component `f18 + (t*(sp30-sp40) - t*(sp30*t))`
   mula/msub chains): nd 91 (down from the recorded 99). The entire tail
   (diffs, scales, all three mula/msub components, epilogue) is content-
   identical; residual is the recorded family: b210 CSEs the increment's
   re-load `lhu` with the 1st half-scaler's load (missing 1 word, long-lived
   value colored $a0 vs retail $v0 — Load-CSE, cf. func_003720c0), the
   or-fold/cvt-scratch in both half-scalers (cf. func_00372960), and the w
   load (field30) still hoists above the sp30 loads (retail lwc1 sp30 before
   lwc1 w; 6 decl orders identical). Load-CSE + $v1-coloring floor. */
/* measured: best nd 99 (~60 pure shift). First half-scaler (byte-identical
   source to func_003720c0's matching one) colors value->$a1, var_f1->$f0 and
   hoists the w load above the bltz here (6 decl orders, w local, single
   value var all identical) - a coloring floor specific to this call/FMA
   pressure; everything after it matches incl. all mula/msub chains. */
// FUN_003726B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003726b0);

// FUN_00372870
void func_00372870(u8 *arg0, s16 a1, s16 a2, u8 *arg3, ShuffleVec4 *arg4) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 2) = a2;
    *(s16 *)(arg0 + 4) = a1;
    if (arg3 != NULL) {
        *(ShuffleVec4 *)(arg0 + 0x18) = *(ShuffleVec4 *)(arg3 + 0);
        *(ShuffleVec4 *)(arg0 + 0x8) = *(ShuffleVec4 *)(arg3 + 0);
    } else {
        *(ShuffleVec4 *)(arg0 + 0x18) = *(ShuffleVec4 *)(arg0 + 0x8);
    }
    if (arg4 == NULL) {
        func_0046d730(&D_0064E9C0, 0x2B6);
    }
    *(ShuffleVec4 *)(arg0 + 0x28) = *(ShuffleVec4 *)(arg4 + 0);
}

/* measured: rule-2 transpose DOES fix the old residual (the two polynomial
   final madd.s now emit retail's product-first order via `var_f0*var_f1` /
   `var_f1*var_f2` source order) and the 00373cb0/003dcc70/vec4-copy/Horner/
   add-back/mula-madd tail all match — but the half-scalers then dominate:
   with the only clean-structure spelling (s32 lhu temp, `u=(u32)temp`,
   `(f32)(s32)((u>>1)|(u&1))`, `var=var+var`; u16/u32 locals duplicate the
   else block, s16/(s16) casts add dsll32/dsra32 or lh) mwcc b210 emits
   `or $v0,$v1,$v0` (dest = andi-result reg; retail `or $v1,$v1,$v0` dest =
   srl-result reg — the recorded or-fold) and converts through $f0
   (`cvt.s.w $f0,$f0; add.s $f12,$f0,$f0` vs retail `cvt.s.w $f12,$f0;
   add.s $f12,$f12,$f12`) — 4 words x 3 half-scalers, nd 13. Re-tested this
   wave with recipe A + a fully rebuilt byte-identical tail (ShuffleOut out,
   0.0f-seeded Horner, var_f0*var_f1/var_f1*var_f2 final products, add-back):
   every non-half-scaler word matches; nd 13 confirmed = 12 real + 1 pad.
   or-fold / cvt-scratch coloring floor. */
// FUN_00372960
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00372960);

// FUN_00372C30
void func_00372c30(u8 *arg0, s16 arg1, s16 arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 2) = arg2;
    *(s16 *)(arg0 + 4) = arg1;
    if (arg3 != NULL) {
        *(ShuffleVec4 *)(arg0 + 0x18) = *(ShuffleVec4 *)(arg3 + 0);
        *(ShuffleVec4 *)(arg0 + 0x8) = *(ShuffleVec4 *)(arg3 + 0);
    } else {
        *(ShuffleVec4 *)(arg0 + 0x18) = *(ShuffleVec4 *)(arg0 + 0x8);
    }
    if (arg5 == NULL) {
        func_0046d730(&D_0064E9C0, 0x2E0);
    }
    if (arg4 == NULL) {
        func_0046d730(&D_0064E9C0, 0x2E1);
    }
    *(ShuffleVec4 *)(arg0 + 0x38) = *(ShuffleVec4 *)(arg5 + 0);
    *(ShuffleVec4 *)(arg0 + 0x28) = *(ShuffleVec4 *)(arg4 + 0);
}

/* measured: same half-scaler floor as func_00372960 (or-fold: mwcc emits
   `or $v0,$v1,$v0` dest = andi-result reg vs retail `or $v1,$v1,$v0` dest =
   srl-result reg, plus cvt through $f0 scratch + `add.s $f12,$f0,$f0` vs
   retail cvt-to-$f12 + `add.s $f12,$f12,$f12`) - 4 words x 3 half-scalers,
   nd 13 (1 pad). Everything else matches on the s32/u-local spelling:
   0.5f head, out/B/A decl order (stack slots reverse), both 2.0f muls
   (branch1 needs the two-statement `t = temp; t = t * 2.0f` form for
   retail's fs=temp order; branch2 is one-statement), 00373cb0/003dcc70
   calls, Horner with transposed final madds, mula/madd tail. */
// FUN_00372D60
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00372d60);

// FUN_003730F0
void func_003730f0(u8 *p, s16 a1, s16 a2, ShuffleVec3 *arg3, f32 fparg0, f32 fparg1) {
    ShuffleVec3 sp;

    sp = *arg3;
    *(s16 *)(p + 0) = 0;
    *(s16 *)(p + 2) = a2;
    *(s16 *)(p + 4) = a1;
    *(ShuffleVec4 *)(p + 0x18) = *(ShuffleVec4 *)(p + 8);
    *(ShuffleVec3 *)(p + 0x28) = sp;
    *(f32 *)(p + 0x34) = fparg0;
    *(f32 *)(p + 0x38) = fparg1;
}

// FUN_00373170
s32 func_00373170(u8 *arg0) {
    f32 sp20[4];
    f32 var_f12;
    f32 var_f13;
    f32 var_f14;
    f32 t;
    u32 v3;
    u32 v2;
    u32 value;
    u32 value2;
    u32 value3;

    v3 = *(u16 *)arg0;
    v2 = *(u16 *)(arg0 + 2);
    if (!((s32)v3 < (s32)v2)) {
        return 1;
    }
    *(u16 *)arg0 = v3 + 1;
    value = *(u16 *)arg0;
    if (value >= 0) {
        var_f12 = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        var_f12 = (f32)value;
        var_f12 += var_f12;
    }
    value2 = *(u16 *)(arg0 + 4);
    if (value2 >= 0) {
        var_f13 = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        var_f13 = (f32)value2;
        var_f13 += var_f13;
    }
    value3 = *(u16 *)(arg0 + 2);
    if (value3 >= 0) {
        var_f14 = (f32)value3;
    } else {
        value3 = (value3 >> 1) | (value3 & 1);
        var_f14 = (f32)value3;
        var_f14 += var_f14;
    }
    t = func_00373cb0(var_f12, var_f13, 0, var_f14);
    func_003dc740(&sp20[0], arg0 + 0x28, 0, 0.0f + *(f32 *)(arg0 + 0x34) + t * (*(f32 *)(arg0 + 0x38) - *(f32 *)(arg0 + 0x34)));
    *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x24) * sp20[3] - (*(f32 *)(arg0 + 0x18) * sp20[0] + *(f32 *)(arg0 + 0x1C) * sp20[1] + *(f32 *)(arg0 + 0x20) * sp20[2]);
    *(f32 *)(arg0 + 0x8) = *(f32 *)(arg0 + 0x1C) * sp20[2] - *(f32 *)(arg0 + 0x20) * sp20[1];
    *(f32 *)(arg0 + 0xC) = *(f32 *)(arg0 + 0x20) * sp20[0] - *(f32 *)(arg0 + 0x18) * sp20[2];
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0x18) * sp20[1] - *(f32 *)(arg0 + 0x1C) * sp20[0];
    *(f32 *)(arg0 + 0x8) = 0.0f + *(f32 *)(arg0 + 0x8) + sp20[0] * *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg0 + 0xC) = 0.0f + *(f32 *)(arg0 + 0xC) + sp20[1] * *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg0 + 0x10) = 0.0f + *(f32 *)(arg0 + 0x10) + sp20[2] * *(f32 *)(arg0 + 0x24);
    *(f32 *)(arg0 + 0x8) = 0.0f + *(f32 *)(arg0 + 0x8) + *(f32 *)(arg0 + 0x18) * sp20[3];
    *(f32 *)(arg0 + 0xC) = 0.0f + *(f32 *)(arg0 + 0xC) + *(f32 *)(arg0 + 0x1C) * sp20[3];
    *(f32 *)(arg0 + 0x10) = 0.0f + *(f32 *)(arg0 + 0x10) + *(f32 *)(arg0 + 0x20) * sp20[3];
    return 0;
}

// FUN_003733D0
void func_003733d0(u8 *p, s16 a1, s8 a2, s8 a3) {
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 6) = a1;
    *(u8 *)(p + 1) = a2;
    *(u8 *)(p + 0) = a2;
    *(u8 *)(p + 2) = a3;
}

/* measured: best nd 27 on the clean s32/u-local spelling. Everything else
   matches (lhu heads, assert, div, lbu diff, adda/madd f3*f2, the
   0x4F000000 guard bodies and store) except: (1) the three half-scalers'
   recorded or-fold + cvt-through-$f0 scratch (4 words each, cf.
   func_00372960 note); (2) the increment's recorded store/mask 2-reg
   split (`andi $v0,$v1,0xffff; sh $v1` vs retail `sh; andi` on one reg,
   cf. 00373610); (3) the guard's branch polarity: retail `c.ole.s
   $f0,$f1; bc1t` to the out-of-line sub path, mwcc canonicalises the
   negated compare by swapping the if/else bodies and emits bc1f — all
   four spellings of the compare probed (`!(t>=C)` -> c.olt.s $f1,$f0,
   `!(C<=t)` -> c.ole.s + body swap, `t<C` -> c.lt.s, `t<=C` -> c.ole.s
   $f1,$f0). FP regs fixed via temp_f2-before-var_f1 decl order. */
// FUN_003733F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003733f0);

// FUN_00373590
void func_00373590(u8 *arg0, s16 arg1, s8 arg2, u8 arg3) {
    if ((arg3 & 0xFF) >= 5) {
        func_0046d730(&D_0064E9C0, 0x350);
    }
    *(s16 *)(arg0 + 2) = 0;
    *(s16 *)(arg0 + 4) = arg1;
    *(s8 *)(arg0 + 0) = arg2;
    *(s8 *)(arg0 + 1) = arg3;
}

/* measured: the counter increment chain `lhu;addiu;sh;andi` — retail orders
   sh $v0 BEFORE andi $v1,$v0,0xffff (store raw, mask for the test); mwcc
   b210 always hoists the andi above the sh (2 words differ, nd 4 = 2 real + 2
   padding). Tried: (u16) cast, s32 v with &=0xFFFF in place, store-then-
   reload (emits a real lhu instead), m2c's exact double-mask with named
   temp_2_3, and inline (temp_2 & 0xFFFF) — identical andi-first schedule
   every time. Everything else (the >= slt/bnez layout, descending beq
   switch chain 4,3,2,1,0 with case 0 shared exit, assert 0x379, func_0045af60
   calls) matches. Store/mask scheduling floor. */
// FUN_00373610
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00373610);

/* measured: best nd 244 (~240 cascade shift from one fold): case 3/4's
   `0.0f + 224.0f + 120.0f * 0.0f` y-chain - retail keeps 0.0f as a runtime
   register (mtc1 $0; adda/madd) but b210's mul-by-zero rule folds it (also
   `0.0f*reg`, `(f32)(arg1-arg1)`, `(f32)arg1-(f32)arg1` probed). All other
   jtbl-switch chains and asserts are mwcc-native. Zero-fold floor. */
// FUN_00373750
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00373750);

// FUN_00373C20
void func_00373c20(u8 *arg0) {
    ShuffleVec3 sp30;
    ShuffleVec3 sp20;
    u8 *temp_2;

    temp_2 = func_003e9700(*(s32 *)(func_00457120() + 4));
    sp30 = *(ShuffleVec3 *)(temp_2 + 0x30);
    sp20.x = *(f32 *)(arg0 + 0) - sp30.x;
    sp20.y = *(f32 *)(arg0 + 4) - sp30.y;
    sp20.z = *(f32 *)(arg0 + 8) - sp30.z;
    func_003e4180(&sp20);
}

// FUN_00373CB0
f32 func_00373cb0(f32 fparg0, f32 fparg1, s32 arg0, f32 fparg2) {
    f32 temp_f20;

    if (fparg0 < fparg1) {
        return 0.0f;
    }
    if (fparg0 < fparg2) {
        temp_f20 = fparg2 - fparg1;
        if (temp_f20 <= 0.0f) {
            func_0046d730(&D_0064E9C0, 0x3DD);
        }
        switch (arg0) {
        case 0:
            return (fparg0 - fparg1) / temp_f20;
        case 1:
            return func_0044b7b0((D_00761470 * (fparg0 - fparg1)) / temp_f20);
        case 2:
            return 1.0f - func_0044b610((D_00761470 * (fparg0 - fparg1)) / temp_f20);
        default:
            func_0046d730(&D_0064E9C0, 0x3E9);
        }
    }
    return 1.0f;
}

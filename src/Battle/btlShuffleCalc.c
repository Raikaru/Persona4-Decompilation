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

/* measured: re-tested this wave — nd 2 confirmed (1 real word + 1 pad).
   retail's `mul.s $f1,$f0,$f1` (const × value) vs mwcc b210's
   `mul.s $f1,$f1,$f0` (value × const) at the 60.0f*var_3 multiply — the ONLY
   differing word once the source uses a value-first inline helper
   a value-first inline multiply ((f32)var_3 * 60.0f) plus raw/temp_2=raw+0x68 base hoist (retail
   re-issues `sra $v1,$a0,1` for the -320.0f divisor instead of CSE-ing the
   shift; the assert mul needs a value-first inline multiply (value * 100.0f) to match, plain
   `value*100.0f` swaps ITS operands). Flipping the helper to const-first,
   plain (60.0f*(f32)var_3), a pre-materialized f32 local, or a two-statement
   mul-then-div makes the constant load hoist before the cvt and re-colors
   var_3 from $v1 to $a1 (nd 51). Commutative FP-mul scheduling floor. */
/* re-measured wave 14: the m2c draft (src/generated/code1_0037.c) round-half
   spelling (`var_3 = sp30>>1; if (sp30<0) var_3 = (s32)(sp30+1)>>1;`) with a
   raw base hoist reproduces the same nd-51 const-first pathology — the nd-2
   spelling (value-first inline mul + exact base hoist) remains untranscribed.
   Confirmed floor. */
// FUN_00371260
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371260);
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
   the div.s operands; hoisting `f = (f32)var_2` and num/den locals does not
   move it). Tried named locals, m2c if-form, inline two-return, u32/or
   spellings, hoisted cvt, decl-order rotations — all nd 11.
   $v0/$v1 coalescing + FP-eval-order floor. */
/* measured: re-tested this wave — nd 11 CONFIRMED (same floor). The round-half
   spelling that reproduces retail's `sra;bgez;addiu;sra` branch is the m2c
   two-statement form: `var_2 = sp30 >> 1; if (sp30 < 0) { var_2 = (s32)(sp30 +
   1) >> 1; }` (single-expression or if/else forms compile to `slt;addu;sra`,
   nd 17-20). Residual unchanged: (1) $v0/$v1 coalescing — mine `lw $v0;
   sra $v1,$v0` vs retail `lw $v1; sra $v0,$v1` (load in $v1, shift result in
   $v0; 6 words); (2) return evaluation order — mine `lwc1/mul.s
   $f1,$f20,$f0; cvt $f0; div.s $f0,$f0,$f1` vs retail `mtc1/cvt $f1;
   lwc1/mul.s $f0,$f20,$f0; div.s $f0,$f1,$f0` (numerator-first div; 5
   words). $v0/$v1 coalescing + FP-eval-order floor, nd 11. */
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

/* MATCHED this wave via lever 1 (parameter width): the two half-scaler args
   must be u32, not s32. With s32 args, `arg >> 1` compiles to arithmetic
   `sra` (retail uses logical `srl`) and the or-fold colors into the andi
   result reg; with u32 args the srl/andi/or/mtc1 chain is byte-identical
   (old note's "u32 locals" probe only covered locals, not the parameters).
   Recipe: u32 arg + `if (v >= 0) { f = (f32)v; } else { v = (v>>1)|(v&1);
   f = (f32)(s32)v; f += f; }`, then ShuffleVec3 struct-copy loop. */
// FUN_00371BA0
void func_00371ba0(u8 *arg0, u8 *arg1, u32 arg2, u32 arg3) {
    f32 f0;
    s32 i;

    *(s16 *)(arg0 + 0) = 0;
    if (arg3 >= 0) {
        f0 = (f32)arg3;
    } else {
        arg3 = (arg3 >> 1) | (arg3 & 1);
        f0 = (f32)(s32)arg3;
        f0 += f0;
    }
    *(f32 *)(arg0 + 4) = f0;
    if (arg2 >= 0) {
        f0 = (f32)arg2;
    } else {
        arg2 = (arg2 >> 1) | (arg2 & 1);
        f0 = (f32)(s32)arg2;
        f0 += f0;
    }
    *(f32 *)(arg0 + 8) = f0;
    for (i = 0; i < 4; i++) {
        *(ShuffleVec3 *)(arg0 + 0x18 + i * 12) = *(ShuffleVec3 *)(arg1 + i * 12);
    }
}
/* measured: re-tested this wave — BEST nd 38 (recorded 102 -> 38) with a
   full cubic-Bezier reconstruction (u32 value local, recipe-A half-scalers,
   `t*f3 + v*f4 + t*f5 + t*f6` mula/madda/madda/madd accumulation; 3 decl
   orders + 2 increment spellings probed). Residuals: (1) the Load-CSE floor
   (cf. func_003720c0) — b210 CSEs the increment's re-load `lhu` with the
   1st half-scaler's load, keeping the value live across the whole half-scaler
   and coloring it $a1 vs retail $v0 (cascades thro srl/andi/or/mtc1, ~9
   words); (2) compare polarity: mwcc emits `c.olt.s $f0,$f1; bc1f` for
   `var_f1 < field4` vs retail `c.olt.s $f1,$f0; bc1t`; (3) P0-vs-P1 mula/madd
   chain scheduling + $f-register renumbering in component 3. Load-CSE +
   FP-scheduling floor. */
// FUN_00371C70
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371c70);
// FUN_00371E50
void func_00371e50(u8 *arg0, u32 arg1, ShuffleVec3 *arg2, ShuffleVec3 *arg3, ShuffleVec3 *arg4, f32 fparg0, f32 fparg1) {
    ShuffleVec3 sp30;
    ShuffleVec3 sp20;
    ShuffleVec3 sp10;
    f32 f0;

    sp30 = *arg2;
    sp20 = *arg3;
    sp10 = *arg4;
    *(s16 *)(arg0 + 0) = 0;
    if (arg1 >= 0) {
        f0 = (f32)arg1;
    } else {
        arg1 = (arg1 >> 1) | (arg1 & 1);
        f0 = (f32)(s32)arg1;
        f0 += f0;
    }
    *(f32 *)(arg0 + 4) = f0;
    *(f32 *)(arg0 + 0x18) = fparg0;
    *(f32 *)(arg0 + 0x1C) = fparg1;
    *(ShuffleVec3 *)(arg0 + 0x20) = sp30;
    *(ShuffleVec3 *)(arg0 + 0x2C) = sp20;
    *(ShuffleVec3 *)(arg0 + 0x38) = sp10;
}
/* measured: re-tested this wave — BEST nd 6 (4 real + 2 relocated), recorded
   48 -> 6, with a full rebuild (u32 value local recipe-A half-scaler, lerp
   computed BEFORE func_003e0f80, sp50[3] subs, 003e0870/003e42a0/003e0f40
   calls, *= accumulators). Everything matches except TWO fixed order-swaps
   (4 words): (1) prologue `move $s1,$a1` before `mov.s $f20,$f12` vs retail
   f20-first (arg-save order of the f32 saved reg); (2) the func_003e0870
   call `move $a2,$zero` before `mov.s $f12,$f20` vs retail mov.s $f12 first
   (same documented floor in mt_sceneFunc.c FUN_002...2nd 003e0870 call;
   named-zero local does not reorder). Saved-reg rotation (s2/s1/s0) now
   matches retail. FP-arg-scheduling floor, nd 6. */
// FUN_00371F40
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371f40);
/* measured: re-tested this wave — BEST nd 35 (recorded 61 -> 35) with a full
   rebuild (u32 value local, recipe-A half-scalers, `var_f12 + 0.0f` then
   div, 00371160 lerp arg). `#pragma opt_propagation off` (FLYDraw's lever)
   improves the 1st half-scaler value coloring $a1 -> $a0 but does NOT break
   the Load-CSE: b210 still CSEs the increment's re-load `lhu` with the 1st
   half-scaler's load (offset 104: `andi $v0,$a0,0xffff` vs retail `lhu
   $v0,($s0)`), keeping the value live across the whole half-scaler and
   coloring it $a0 vs retail $v0 (cascades thro srl/andi/or/mtc1). Also
   remnant: compare polarity `c.olt.s $f0,$f1; bc1f` vs retail `c.olt.s
   $f1,$f0; bc1t`, and the 2nd half-scaler + lerp mula/madd scheduling.
   Load-CSE + compare-polarity floor. */
// FUN_003720C0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003720c0);
/* measured: re-tested this wave — BEST nd 32 (recorded 121 -> 32) with a full
   rebuild: u32 value locals, recipe-A half-scalers, compound-assignment
   increment `value2 = (*(u16 *)arg0 += 1)` (FLBtlresultsimple lever: sh before
   andi), split store-then-accumulate tail math (`f18 + (p1-p0)*t` then `+= f7`
   with f7 = field30*(t - 2t*t); split removes the single-expression reorder
   nd 46->33). Residuals: (1) FP register-allocation cascade — my `t` lands in
   $f6 vs retail $f8, shifting all factor/diff FP regs ($f4/$f3/$f2 vs retail
   $f7/$f6/$f5); (2) compare polarity: `if (var_f1 < field4) return 1;` emits
   `c.olt.s $f0,$f1; bc1f`; goto-form `if (v<f) goto cont; return 1;` gives
   `bc1t` (nd 32, 1 better). FP-coloring + compare-polarity floor. */
// FUN_00372200
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00372200);
// FUN_003723A0
void func_003723a0(u8 *arg0, u32 arg1, u32 arg2, u8 *arg3, u8 *arg4, f32 fparg0) {
    f32 f0;

    *(s16 *)(arg0 + 0) = 0;
    if (arg2 >= 0) {
        f0 = (f32)arg2;
    } else {
        arg2 = (arg2 >> 1) | (arg2 & 1);
        f0 = (f32)(s32)arg2;
        f0 += f0;
    }
    *(f32 *)(arg0 + 4) = f0;
    if (arg1 >= 0) {
        f0 = (f32)arg1;
    } else {
        arg1 = (arg1 >> 1) | (arg1 & 1);
        f0 = (f32)(s32)arg1;
        f0 += f0;
    }
    *(f32 *)(arg0 + 8) = f0;
    if (arg3 != NULL) {
        *(ShuffleVec3 *)(arg0 + 0x18) = *(ShuffleVec3 *)(arg3 + 0);
        *(ShuffleVec3 *)(arg0 + 0xC) = *(ShuffleVec3 *)(arg3 + 0);
    } else {
        *(ShuffleVec3 *)(arg0 + 0x18) = *(ShuffleVec3 *)(arg0 + 0xC);
    }
    if (arg4 == NULL) {
        func_0046d730(&D_0064E9C0, 0x24F);
    }
    *(ShuffleVec3 *)(arg0 + 0x24) = *(ShuffleVec3 *)(arg4 + 0);
    *(f32 *)(arg0 + 0x30) = fparg0;
}
/* measured: re-tested this wave — BEST nd 11 (recorded 91 -> 11) with a full
   rebuild: u32 value local, recipe-A half-scalers, `#pragma opt_propagation
   off` (FLYDraw lever: fixes the 1st half-scaler value coloring $a1->$a0),
   sp40 declared BEFORE sp30 (stack slots 0x40/0x30 — the decl-order swap
   alone took nd 27->11), func_003e40b0(&sp30,&sp40), per-component
   `f18 + (sp30*t - t*(t*(sp30+sp40)))` mula/msub. Residual (all documented
   floors): (1) Load-CSE — b210 CSEs the increment's re-load `lhu` with the
   1st half-scaler load (offset 108 `andi $v0,$a0,0xffff` vs `lhu $v0,($s0)`),
   value colored $a0 vs retail $v0 (5 words); (2) compare polarity `c.olt.s
   $f0,$f1; bc1f` vs retail `c.olt.s $f1,$f0; bc1t` (all 4 compare spellings
   probed elsewhere, floor); (3) func_00373cb0 arg order: `move $a0,$zero`
   before `lwc1 $f14` vs retail f14-first (constant-vs-load order).
   Load-CSE + compare-polarity floor, nd 11. */
// FUN_003724F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003724f0);
/* measured: re-tested this wave — BEST nd 11 (recorded 99 -> 11) with a full
   rebuild: u32 value local, recipe-A half-scalers, `#pragma opt_propagation
   off` (fixes 1st half-scaler value coloring $a1->$a0), sp40 declared BEFORE
   sp30 (0x40/0x30 slots), func_003e40b0(&sp30,&sp40), per-component
   `f18 + (t*(sp30-sp40) - t*(sp30*t))` mula/msub. Residual is the SAME
   documented 11-word floor as func_003724f0: (1) Load-CSE — b210 CSEs the
   increment re-load `lhu` with the 1st half-scaler load (offset 108 `andi
   $v0,$a0,0xffff` vs `lhu $v0,($s0)`), value colored $a0 vs retail $v0 (5
   words); (2) compare polarity `c.olt.s $f0,$f1; bc1f` vs retail `c.olt.s
   $f1,$f0; bc1t`; (3) func_00373cb0 arg order `move $a0,$zero` before
   `lwc1 $f14` vs retail f14-first. Load-CSE + compare-polarity floor, nd 11. */
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

/* measured: re-tested this wave (fresh reconstruction). The counter
   increment chain `lhu;addiu;sh;andi` — retail orders sh $v0 BEFORE andi
   $v1,$v0,0xffff (store raw, mask for the test); mwcc b210 always hoists
   the andi above the sh (2 words differ, nd 4 = 2 real + 2 padding).
   Tried: (u16) cast, s32 v with &=0xFFFF in place, store-then-reload
   (emits a real lhu instead), m2c's exact double-mask with named
   temp_2_3, and inline (temp_2 & 0xFFFF) — identical andi-first schedule
   every time. Everything else (the >= slt/bnez layout, descending beq
   switch chain 4,3,2,1,0 with case 0 shared exit, assert 0x379,
   func_0045af60 calls) matches. Store/mask scheduling floor. */
/* re-measured wave 14: compound-assignment increment
   (`v = (*(u16 *)(arg0 + 2) += 1)` + `(v & 0xFFFF)` compare, FLBtlresultsimple
   lever) and a real ascending-case switch BOTH regress hard (nd 53-57 vs
   recorded 4) because the fresh reconstruction lost the recorded if/else-if
   descending dispatch shape; the recorded nd-4 increment spelling remains
   untranscribed. Store/mask scheduling floor confirmed. */
// FUN_00373610
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00373610);
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

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
extern void func_003e0870(s32 a0, void *a1, f32 fparg0, s32 a2);
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
typedef struct ShuffleCalcUnit {
    u16 count;
    u16 pad02;
    f32 duration;
    f32 rate;
    f32 output[3];
    f32 start[3];
    f32 target[3];
    f32 scale;
} ShuffleCalcUnit;
f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0);

/* SOLVED -- this was recorded here as a "Commutative FP-mul scheduling floor"
   and re-confirmed as a floor through wave 14. The nd-2 spelling those notes
   called untranscribed is the body below, and the LAST word came from a named
   f32 constant local assigned before the base hoist:

       k = 100.0f;
       temp_16 = func_00457120() + 0x68;
       if (*(f32 *)temp_16 * k <= 0.0f) { ... }

   Retail materializes the constant into the LOWER FP register and loads the
   value into the higher one; with the literal written inline b210 does the
   reverse and emits `mul.s $f1,$f1,$f0` where retail has `mul.s $f1,$f0,$f1`.
   A named local pins the materialization order. The identical one-line change
   also matched func_003713b0, its 84.0f twin. Keep `s32 sp30[8]` for the 0x50
   frame with the slot at 0x30, a `u8 *` base hoist, `sp30[0] / 2` for the
   rounded halving in the scale numerator and `sp30[n] >> 1` in the two
   perspective terms -- retail genuinely uses both halving forms. */
// FUN_00371260
void func_00371260(u8 *arg0) {
    s32 sp30[8];
    u8 *temp_16;
    f32 scale;
    f32 k;

    k = 100.0f;
    temp_16 = func_00457120() + 0x68;
    if (*(f32 *)temp_16 * k <= 0.0f) {
        func_0046d730(D_0064E9C0, 0x109);
    }
    func_003e8970(&sp30[0], func_003e89c0());
    scale = (60.0f * (f32)(sp30[0] / 2)) / (k * *(f32 *)temp_16);
    *(f32 *)(arg0 + 0) = scale * (*(f32 *)temp_16 * (1.0f + (-320.0f / (f32)(sp30[0] >> 1))));
    *(f32 *)(arg0 + 4) = scale * (*(f32 *)(temp_16 + 4) * (1.0f + (-224.0f / (f32)(sp30[1] >> 1))));
    *(f32 *)(arg0 + 8) = scale;
}
// FUN_003713B0
void func_003713b0(u8 *arg0) {
    s32 sp30[8];
    u8 *temp_16;
    f32 scale;
    f32 k;

    k = 84.0f;
    temp_16 = func_00457120() + 0x68;
    if (*(f32 *)temp_16 * k <= 0.0f) {
        func_0046d730(D_0064E9C0, 0x109);
    }
    func_003e8970(&sp30[0], func_003e89c0());
    scale = (60.0f * (f32)(sp30[0] / 2)) / (k * *(f32 *)temp_16);
    *(f32 *)(arg0 + 0) = scale * (*(f32 *)temp_16 * (1.0f + (-320.0f / (f32)(sp30[0] >> 1))));
    *(f32 *)(arg0 + 4) = scale * (*(f32 *)(temp_16 + 4) * (1.0f + (-224.0f / (f32)(sp30[1] >> 1))));
    *(f32 *)(arg0 + 8) = scale;
}
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
f32 func_003716d0(f32 fparg0) {
    s32 sp30[8];
    u8 *temp_16;

    temp_16 = func_00457120() + 0x68;
    if (fparg0 * *(f32 *)temp_16 <= 0.0f) {
        func_0046d730(D_0064E9C0, 0x145);
    }
    func_003e8970(&sp30[0], func_003e89c0());
    return (f32)(sp30[0] / 2) / (fparg0 * *(f32 *)temp_16);
}
// FUN_00371780
void func_00371780(u8 *arg0, u8 *arg1) {
    func_003e42a0(arg0, arg1, func_003e9700(*(s32 *)(func_00457120() + 4)));
}

/* measured: best nd 29. Hoisting the ratio ahead of the rounding block
   (retail computes the div chain first) rotates saved regs to $s1/$s0/$s2
   (retail $s2/$s1/$s0; 3 decl orders probed, nd 29), on top of the recorded
   $v0/$v1 rounding-coalescing floor and two mul.s operand swaps. */
// FUN_003717E0
s32 func_003717e0(u8 *arg0, u8 *arg1) {
    s32 sp40[8];
    u8 *temp_16;
    f32 x;
    f32 y;

    temp_16 = func_00457120() + 0x68;
    if (*(f32 *)(arg0 + 8) <= 0.0f || *(f32 *)temp_16 <= 0.0f ||
        *(f32 *)(temp_16 + 4) <= 0.0f) {
        func_0046d730(D_0064E9C0, 0x15F);
    }
    func_003e8970(&sp40[0], func_003e89c0());
    x = (f32)(sp40[0] / 2) *
        -((*(f32 *)(arg0 + 0) / *(f32 *)(arg0 + 8)) / *(f32 *)temp_16 - 1.0f);
    *(f32 *)(arg1 + 0) = x;
    y = (f32)(sp40[1] / 2) *
        -((*(f32 *)(arg0 + 4) / *(f32 *)(arg0 + 8)) / *(f32 *)(temp_16 + 4) - 1.0f);
    *(f32 *)(arg1 + 4) = y;
    if (x >= 0.0f && x < 640.0f && y >= 0.0f && y < 448.0f) {
        return 1;
    }
    return 0;
}
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

/* measured: func_00371a60 is a live MATCH (object 312B / 320B window /
   normalized_diff 0). Both int-to-float sites use plain `(f32)(u32)`
   casts. Difference-first float locals reproduce retail's separate
   subtraction, multiply, and add sequence; `*(u16 *)arg0 += 1` preserves
   the retail count reload. */
// FUN_00371A60
s32 func_00371a60(u8 *arg0, s32 arg1) {
    f32 half;
    f32 zero;
    f32 temp_f0;
    f32 temp_f5;
    f32 diff0;
    f32 diff1;
    f32 diff2;

    zero = 0.0f;
    half = (f32)(u32)*(u16 *)arg0;
    if (!(half < *(f32 *)(arg0 + 4))) {
        return 1;
    }
    *(u16 *)arg0 += 1;
    half = (f32)(u32)*(u16 *)arg0;
    temp_f0 = func_00373cb0(half + zero, *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 4), arg1);
    temp_f5 = *(f32 *)(arg0 + 0x18);
    diff0 = *(f32 *)(arg0 + 0x24) - temp_f5;
    diff1 = *(f32 *)(arg0 + 0x28) - *(f32 *)(arg0 + 0x1C);
    diff2 = *(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x20);
    diff0 = diff0 * temp_f0;
    diff1 = diff1 * temp_f0;
    diff2 = diff2 * temp_f0;
    *(f32 *)(arg0 + 0xC) = diff0 + temp_f5;
    *(f32 *)(arg0 + 0x10) = diff1 + *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0x14) = diff2 + *(f32 *)(arg0 + 0x20);
    return 0;
}
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
/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
// FUN_00371C70 NONMATCHING
#ifdef NON_MATCHING
s32 func_00371c70(u8 *arg0) {
    f32 var_f12;
    f32 var_f1;
    f32 inv;
    f32 f3;
    f32 f4;
    f32 f5;
    f32 f6;
    u32 temp_2;
    u32 temp_2_2;

    temp_2 = *(u16 *)(arg0 + 0);
    if ((s32)temp_2 >= 0) {
        var_f1 = (f32)temp_2;
    } else {
        var_f1 = (f32)((temp_2 >> 1) | (temp_2 & 1));
        var_f1 += var_f1;
    }
    if (var_f1 < *(f32 *)(arg0 + 4)) {
        temp_2_2 = *(u16 *)(arg0 + 0) + 1;
        *(u16 *)(arg0 + 0) = (u16)temp_2_2;
        temp_2_2 = *(u16 *)(arg0 + 0);
        if ((s32)temp_2_2 >= 0) {
            var_f12 = (f32)temp_2_2;
        } else {
            var_f12 = (f32)((temp_2_2 >> 1) | (temp_2_2 & 1));
            var_f12 += var_f12;
        }
        var_f12 = func_00373cb0(0, var_f12, *(f32 *)(arg0 + 8), *(f32 *)(arg0 + 4));
        inv = 1.0f - var_f12;

        f6 = *(f32 *)(arg0 + 0x3C) * var_f12;
        f6 = var_f12 * f6;
        f5 = 3.0f * *(f32 *)(arg0 + 0x30);
        f5 = f5 * inv;
        f5 = var_f12 * f5;
        f4 = *(f32 *)(arg0 + 0x18) * inv;
        f4 = inv * f4;
        f3 = 3.0f * *(f32 *)(arg0 + 0x24);
        f3 = f3 * inv;
        f3 = inv * f3;
        *(f32 *)(arg0 + 0xC) = var_f12 * f3 + inv * f4 + var_f12 * f5 + var_f12 * f6;

        f6 = *(f32 *)(arg0 + 0x40) * var_f12;
        f6 = var_f12 * f6;
        f5 = 3.0f * *(f32 *)(arg0 + 0x34);
        f5 = f5 * inv;
        f5 = var_f12 * f5;
        f4 = *(f32 *)(arg0 + 0x1C) * inv;
        f4 = inv * f4;
        f3 = 3.0f * *(f32 *)(arg0 + 0x28);
        f3 = f3 * inv;
        f3 = inv * f3;
        *(f32 *)(arg0 + 0x10) = var_f12 * f3 + inv * f4 + var_f12 * f5 + var_f12 * f6;

        f6 = *(f32 *)(arg0 + 0x44) * var_f12;
        f6 = var_f12 * f6;
        f5 = 3.0f * *(f32 *)(arg0 + 0x38);
        f5 = f5 * inv;
        f5 = var_f12 * f5;
        f4 = *(f32 *)(arg0 + 0x20) * inv;
        f4 = inv * f4;
        f3 = *(f32 *)(arg0 + 0x2C) * 3.0f;
        f3 = f3 * inv;
        f3 = inv * f3;
        *(f32 *)(arg0 + 0x14) = var_f12 * f3 + inv * f4 + var_f12 * f5 + var_f12 * f6;
        return 0;
    }
    return 1;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371c70);
#endif
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
// FUN_00371F40
void func_00371f40(u8 *arg0, f32 fparg0, u8 *arg1) {
    f32 temp_f20;
    s32 temp_16;
    f32 sp50[3];
    u32 value;
    f32 half;

    if (*(f32 *)(arg0 + 4) <= 0.0f) {
        func_0046d730(&D_0064E9C0, 0x1EF);
    }
    value = *(u16 *)arg0;
    if (value >= 0) {
        half = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        half = (f32)(s32)value;
        half += half;
    }
    temp_f20 = *(f32 *)(arg0 + 0x18) + ((half + fparg0) / *(f32 *)(arg0 + 4)) * (*(f32 *)(arg0 + 0x1C) - *(f32 *)(arg0 + 0x18));
    temp_16 = func_003e0f80();
    sp50[0] = *(f32 *)(arg0 + 0x38) - *(f32 *)(arg0 + 0x2C);
    sp50[1] = *(f32 *)(arg0 + 0x3C) - *(f32 *)(arg0 + 0x30);
    sp50[2] = *(f32 *)(arg0 + 0x40) - *(f32 *)(arg0 + 0x34);
    func_003e0870(temp_16, arg0 + 0x20, temp_f20, 0);
    func_003e42a0(arg1, &sp50[0], (void *)temp_16);
    *(f32 *)(arg1 + 0) += *(f32 *)(arg0 + 0x2C);
    *(f32 *)(arg1 + 4) += *(f32 *)(arg0 + 0x30);
    *(f32 *)(arg1 + 8) += *(f32 *)(arg0 + 0x34);
    func_003e0f40(temp_16);
}
// FUN_003720C0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003720c0);
/* measured: func_00372200 is a live MATCH (object 416B / 416B window /
   normalized_diff 0). Both int-to-float sites use plain `(f32)(u16)`
   casts. Difference-first locals reproduce retail's separate interpolation
   subtraction and multiply sequence. */
// FUN_00372200
s32 func_00372200(u8 *arg0) {
    f32 t;
    f32 t2;
    f32 d0;
    f32 d1;
    f32 d2;
    f32 diff0;
    f32 diff1;
    f32 diff2;

    d2 = *(f32 *)(arg0 + 4);
    t = (f32)(u16)*(u16 *)(arg0 + 0);
    if (!(t < d2)) {
        return 1;
    }
    if (*(f32 *)(arg0 + 4) <= 0.0f) {
        func_0046d730(&D_0064E9C0, 0x22F);
    }
    t = (f32)(u16)(*(u16 *)(arg0 + 0) += 1);
    t = t + 0.0f;
    d2 = *(f32 *)(arg0 + 4);
    t = t / d2;
    t2 = 2.0f * t;
    t2 = t2 * t;
    t2 = t - t2;
    d0 = *(f32 *)(arg0 + 0x30) * t2;
    d1 = *(f32 *)(arg0 + 0x34) * t2;
    d2 = *(f32 *)(arg0 + 0x38) * t2;
    diff0 = *(f32 *)(arg0 + 0x24) - *(f32 *)(arg0 + 0x18);
    diff1 = *(f32 *)(arg0 + 0x28) - *(f32 *)(arg0 + 0x1C);
    diff2 = *(f32 *)(arg0 + 0x2C) - *(f32 *)(arg0 + 0x20);
    diff0 = diff0 * t;
    diff1 = diff1 * t;
    diff2 = diff2 * t;
    *(f32 *)(arg0 + 0xC) = diff0 + *(f32 *)(arg0 + 0x18);
    *(f32 *)(arg0 + 0x10) = diff1 + *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0x14) = diff2 + *(f32 *)(arg0 + 0x20);
    *(f32 *)(arg0 + 0xC) += d0;
    *(f32 *)(arg0 + 0x10) += d1;
    *(f32 *)(arg0 + 0x14) += d2;
    return 0;
}
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
/* Cluster transfer: the named ShuffleCalcUnit/count-pointer shape and
   corrected helper argument order match this 440-byte body in its 448-byte
   retail window (normalized_diff 0). */
// FUN_003724F0
/* measured: func_003724f0 object 440B/window 448B normalized_diff 0; this
   pragma is required (without opt_propagation off, normalized_diff 26). */
#pragma opt_propagation off
s32 func_003724f0(ShuffleCalcUnit *unit) {
    u32 value2;
    u16 *count;
    u32 value;
    f32 sp40[3];
    f32 sp30[3];
    f32 temp_f20;
    f32 temp_f1;
    f32 temp_f2;
    f32 var_f12;
    f32 var_f1;

    count = &unit->count;
    value = *count;
    if (value >= 0) {
        var_f1 = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        var_f1 = (f32)value;
        var_f1 += var_f1;
    }
    if (!(var_f1 < unit->duration)) {
        return 1;
    }
    unit->count = (u16)(unit->count + 1);
    value2 = unit->count;
    if (value2 >= 0) {
        var_f12 = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        var_f12 = (f32)value2;
        var_f12 += var_f12;
    }
    temp_f2 = unit->rate;
    temp_f1 = unit->duration;
    temp_f20 = func_00373cb0(var_f12, temp_f2, temp_f1, 0);
    sp40[0] = unit->start[0] - unit->target[0];
    sp40[1] = unit->start[1] - unit->target[1];
    sp40[2] = unit->start[2] - unit->target[2];
    func_003e40b0(&sp30[0], &sp40[0]);
    temp_f2 = sp30[0];
    temp_f1 = unit->scale;
    sp30[0] = temp_f2 * temp_f1;
    temp_f2 = sp30[1];
    temp_f1 = unit->scale;
    sp30[1] = temp_f2 * temp_f1;
    temp_f2 = sp30[2];
    temp_f1 = unit->scale;
    sp30[2] = temp_f2 * temp_f1;
    temp_f2 = sp30[0] + sp40[0];
    unit->output[0] = unit->start[0] +
        (sp30[0] * temp_f20 - temp_f20 * (temp_f20 * temp_f2));
    temp_f2 = sp30[1] + sp40[1];
    unit->output[1] = unit->start[1] +
        (sp30[1] * temp_f20 - temp_f20 * (temp_f20 * temp_f2));
    temp_f2 = sp30[2] + sp40[2];
    unit->output[2] = unit->start[2] +
        (sp30[2] * temp_f20 - temp_f20 * (temp_f20 * temp_f2));
    return 0;
}
/* measured: func_003724f0 object 440B/window 448B normalized_diff 0; restore
   normal propagation before the next function. */
#pragma opt_propagation on
/* Cluster transfer: the same named ShuffleCalcUnit/count-pointer and helper
   call shape matches the second 440-byte member in its 448-byte window
   (normalized_diff 0); only its measured FP tail spelling differs. */
// FUN_003726B0
/* measured: func_003726b0 object 440B/window 448B normalized_diff 0; this
   pragma is required (without opt_propagation off, normalized_diff 26). */
#pragma opt_propagation off
s32 func_003726b0(ShuffleCalcUnit *unit) {
    u32 value2;
    u16 *count;
    u32 value;
    f32 sp40[3];
    f32 sp30[3];
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f20;
    f32 var_f12;
    f32 var_f1;

    count = &unit->count;
    value = *count;
    if (value >= 0) {
        var_f1 = (f32)value;
    } else {
        value = (value >> 1) | (value & 1);
        var_f1 = (f32)value;
        var_f1 += var_f1;
    }
    if (!(var_f1 < unit->duration)) {
        return 1;
    }
    unit->count = (u16)(unit->count + 1);
    value2 = unit->count;
    if (value2 >= 0) {
        var_f12 = (f32)value2;
    } else {
        value2 = (value2 >> 1) | (value2 & 1);
        var_f12 = (f32)value2;
        var_f12 += var_f12;
    }
    temp_f1 = unit->rate;
    temp_f20 = func_00373cb0(var_f12, temp_f1, unit->duration, 0);
    sp40[0] = unit->start[0] - unit->target[0];
    sp40[1] = unit->start[1] - unit->target[1];
    sp40[2] = unit->start[2] - unit->target[2];
    func_003e40b0(&sp30[0], &sp40[0]);
    temp_f2 = sp30[0];
    temp_f1 = unit->scale;
    sp30[0] = temp_f2 * temp_f1;
    temp_f2 = sp30[1];
    sp30[1] = temp_f2 * temp_f1;
    temp_f2 = sp30[2];
    sp30[2] = temp_f2 * temp_f1;
    unit->output[0] = unit->start[0] +
        (temp_f20 * (sp30[0] - sp40[0]) - temp_f20 * (sp30[0] * temp_f20));
    unit->output[1] = unit->start[1] +
        (temp_f20 * (sp30[1] - sp40[1]) - temp_f20 * (sp30[1] * temp_f20));
    unit->output[2] = unit->start[2] +
        (temp_f20 * (sp30[2] - sp40[2]) - temp_f20 * (sp30[2] * temp_f20));
    return 0;
}
/* measured: func_003726b0 object 440B/window 448B normalized_diff 0; restore
   normal propagation before the next function. */
#pragma opt_propagation on
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
    t = func_00373cb0(var_f12, var_f13, var_f14, 0);
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

/* measured: func_003733f0 is a live MATCH (object 416B / window 416B /
   normalized_diff 0). Plain casts reproduce all conversion sites:
   `(f32)(u16)` for both count values, `(f32)(s32)` for the signed
   byte-difference, `(f32)(u32)` for the byte base, and `(u8)` for the
   final float-to-byte narrowing. */
// FUN_003733F0
s32 func_003733f0(u8 *arg0) {
    f32 temp_f2;
    f32 var_f1;
    f32 var_f3;
    f32 var_f0;
    u32 base;
    s32 diff;

    if ((s32)*(u16 *)(arg0 + 4) >= (s32)*(u16 *)(arg0 + 6)) {
        return 1;
    }
    if ((s32)*(u16 *)(arg0 + 6) <= 0) {
        func_0046d730(&D_0064E9C0, 0x344);
    }
    var_f1 = (f32)(u16)*(u16 *)(arg0 + 6);
    var_f0 = (f32)(u16)(*(u16 *)(arg0 + 4) += 1);
    var_f3 = var_f0 / var_f1;
    base = *(u8 *)(arg0 + 1);
    diff = (s32)*(u8 *)(arg0 + 2) - (s32)base;
    temp_f2 = (f32)(s32)diff;
    var_f0 = (f32)(u32)base;
    var_f1 = 0.0f + var_f0 + var_f3 * temp_f2;
    *(u8 *)(arg0 + 0) = (u8)var_f1;
    return 0;
}

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

/* Both notes previously here were wrong. The store/mask order and the dispatch
   shape are each source-drivable, but only TOGETHER: the compound assignment's
   value fixes sh-before-andi, and the positive-condition guard branching out to
   a single trailing `return 0` gives retail's shared zero-return block. Wave 14
   tried the compound assignment alone and regressed to nd 53-57 because it also
   inlined the zero return, which shifts every branch target after it. Cases are
   declared ascending so b210 reverses the comparisons to retail's 4,3,2,1,0
   while laying the bodies out 1,2,3,4. */
// FUN_00373610
s32 func_00373610(u8 *arg0)
{
    s32 bumped;

    if (arg0[1] == 0) {
        return 1;
    }
    /* measured: the compound assignment's VALUE keeps the bumped counter in one
       register, so the sh lands before the compare mask as retail does; a
       separate increment-then-store pair hoists the andi above the sh. */
    bumped = (*(u16 *)(arg0 + 2) += 1);
    /* measured: testing the positive condition and letting it branch out to the
       single trailing `return 0` reproduces retail's slt/bnez to one shared
       zero-return block; an inline `return 0` here duplicates the block. */
    if (!((s32)(bumped & 0xFFFF) < (s32)*(u16 *)(arg0 + 4))) {
        /* Cases declared ascending: b210 emits the comparisons in reverse
           (4,3,2,1,0) while laying the bodies out in declaration order. */
        switch (arg0[1]) {
        case 0:
            break;
        case 1:
            func_0045af60(1, arg0[0], 5, 1);
            break;
        case 2:
            func_0045af60(1, arg0[0], 5, 2);
            break;
        case 3:
            func_0045af60(1, arg0[0], 5, 3);
            break;
        case 4:
            func_0045af60(1, arg0[0], 5, 4);
            break;
        default:
            func_0046d730(D_0064E9C0, 0x379);
            break;
        }
        arg0[1] = 0;
        return 1;
    }
    return 0;
}

/* measured: archived permuter seed; see the build/ archive header for its object/window/normalized_diff. */
// FUN_00373750 NONMATCHING
#ifdef NON_MATCHING
void func_00373750(s32 arg0, s32 arg1, f32 *arg2) {
    f32 f0;
    f32 f1;
    f32 f2;
    f32 f3;
    f32 f4;

    if (arg2 == NULL) {
        func_0046d730(&D_0064E9C0, 0x38C);
    }
    switch (arg1) {
    case 3:
    case 4:
        f3 = (f32)(arg1 - 1);
        f1 = 0.5f;
        f0 = (f32)arg0;
        *arg2 = 320.0f + 100.0f * (f0 - f1 * f3);
        f1 = 120.0f;
        f0 = 224.0f;
        f2 = 0.0f;
        arg2[1] = f0 + f2 * f1;
        return;
    case 5:
        if (arg0 < 3) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.0f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 3);
        f4 = 0.5f;
        f3 = f3 - f4;
        f1 = 100.0f;
        f0 = 320.0f;
        f2 = 0.0f;
        *arg2 = f0 + f2 + f1 * f3;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f2 * f4;
        return;
    case 6:
        if (arg0 < 3) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.0f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 3);
        f1 = 1.0f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        f4 = 0.0f;
        *arg2 = f0 + f4 + f1 * f2;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f4 * f3;
        return;
    case 7:
        if (arg0 < 4) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.5f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 4);
        f1 = 1.0f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        f4 = 0.0f;
        *arg2 = f0 + f4 + f1 * f2;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f4 * f3;
        return;
    case 8:
        if (arg0 < 4) {
            f2 = 100.0f;
            f0 = (f32)arg0;
            f1 = 1.5f;
            f1 = f0 - f1;
            *arg2 = 320.0f + f2 * f1;
            f2 = 120.0f;
            f1 = -0.5f;
            f0 = 224.0f;
            f3 = 0.0f;
            arg2[1] = f0 + f3 + f2 * f1;
            return;
        }
        f3 = (f32)(arg0 - 4);
        f1 = 1.5f;
        f2 = f3 - f1;
        f1 = 100.0f;
        f0 = 320.0f;
        f4 = 0.0f;
        *arg2 = f0 + f4 + f1 * f2;
        f1 = 120.0f;
        f0 = 224.0f;
        arg2[1] = f0 + f4 * f3;
        return;
    default:
        func_0046d730(&D_0064E9C0, 0x3BF);
        return;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00373750);
#endif

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
f32 func_00373cb0(f32 fparg0, f32 fparg1, f32 fparg2, s32 arg0) {
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

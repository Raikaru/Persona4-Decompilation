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
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern f32 D_00761470;
f32 func_003716d0(f32 fparg0);
typedef struct { f32 x, y, z, w; } ShuffleVec4;
typedef struct { f32 x, y, z; } ShuffleVec3;
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


/* measured: retail keeps sp30[0] in $v1 and the rounded-half shift result in
   $v0 (lw $v1/sra $v0/addiu $v0/sra $v0/mtc1 $v0), while mwcc b210 always
   colors the load into $v0 and the result into $v1 (same 6 words differ).
   Tried named locals (x/y), m2c if-form, inline two-return (object ballooned
   to 220B, div duplicated), and u32/or spellings — identical nd 6. $v0/$v1
   coalescing floor. */
// FUN_003716D0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003716d0);


// FUN_00371780
void func_00371780(u8 *arg0, u8 *arg1) {
    func_003e42a0(arg0, arg1, func_003e9700(*(s32 *)(func_00457120() + 4)));
}


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


/* measured: same u16-sign-test floor as func_00372200/00373610 — the
   `lhu;bltz` half-scaler chains. mwcc b210 materializes any (s16) cast as
   dsll32/dsra32 and (with a u16 local) duplicates the else block with two
   redundant bltz tests; s16-typed locals give a single branch but still the
   dsll/dsra pair and a WRONG negative path (srl of the sign-extended value
   instead of the raw). Tried all cast forms; identical artifacts. Everything
   else in the function (the +0.0f arg copy, 00373cb0 call, interpolation)
   matches. s16-cast materialization floor. */
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

// FUN_00371F40
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00371f40);


// FUN_003720C0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003720c0);


/* measured: the two `lhu;bltz` half-scaler chains (the s16 sign test on a
   u16 field, `(f32)x` conversion, `(f32)((u32)x>>1)|(x&1)` + x+x doubling) —
   mwcc b210 materializes the (s16) cast as dsll32/dsra32 and then emits the
   else-block TWICE with two redundant bltz tests (one on the sign-extended
   value, one on the raw value), blowing the layout to nd 109+. Tried
   (s32)(s16), plain (s16), test on a fresh load, s16-view local, and the
   exact m2c masked form (temp_2_3 = x & 0xFFFF) — identical double-branch
   artifact every time. Retail tests the raw register directly (bltz $v0),
   which no spelling I tried produces. s16-cast materialization floor. */
// FUN_00372200
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00372200);


/* measured: same $v1-or-fold floor as func_00371ba0/00371e50, both
   half-scaler branches: retail `or $a0,$a0,$v1` (dest = srl result reg),
   mwcc b210 folds into $v1 (andi result reg) — 4 words (or/mtc1 ×2) differ,
   nd 6 (2 padding). Tried direct and swapped operand orders — identical.
   Everything else (struct copies, assert, f20 store) matches. */
// FUN_003723A0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003723a0);


// FUN_003724F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_003724f0);


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
INCLUDE_ASM("asm/nonmatchings/btlShuffleCalc", func_00373170);


// FUN_003733D0
void func_003733d0(u8 *p, s16 a1, s8 a2, s8 a3) {
    *(u16 *)(p + 4) = 0;
    *(u16 *)(p + 6) = a1;
    *(u8 *)(p + 1) = a2;
    *(u8 *)(p + 0) = a2;
    *(u8 *)(p + 2) = a3;
}


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

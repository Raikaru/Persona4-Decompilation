/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldLmap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

extern void (*jtbl_008873EC[])(void *);
typedef struct Vec3 { f32 x; f32 y; f32 z; } Vec3;
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern void (*D_00887300[])(s32, s32);
extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern void func_00440b68();
extern void func_00442088(u8 *dst, u8 *src);
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_00454bd0(u8 *ptr);
extern s32 func_004553c0(u8 *ptr);
extern s32 func_00455f70(u8 *param, s32 *out);
extern s32 func_0046af60(s32 param);
extern s32 func_0046a750(s32 param);
extern void func_0046b0d0(void *ptr);
extern u8 *func_00451fc0();
extern void func_003e0f40(u8 *param);
extern void func_00145080();
extern void func_003f6440(s32 param, s32 value);
extern u8 *func_00460990();
extern void func_00460ac0(void *param, u8 *work);
extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, f32, f32, void *);
extern f32 func_003e40b0(f32 *param, f32 *out);
extern u8 *func_0047a2f0(s32 param);
extern void func_0047a180();
extern u8 *func_00457120();
extern void func_00457630(u8 *param, u8 *src, u8 *dst, s32 mode);
extern f32 func_0044b7b0(f32 param);
extern f32 func_0044b610(f32 param);
extern s64 func_001060b0();
extern s32 func_001060c0();
extern s64 func_00110960(s64 param, s32 param2);
extern s32 func_00106330(s32 id);
extern u8 *func_003e0f80();
extern void func_00144c90(s32 a, s32 b);
extern void func_00144ed0(s64 param);
extern s64 func_001546a0(s32 a, s32 b);
extern s32 func_00144f60();
extern u8 *func_0014b450();
extern f32 func_0014b4d0();
extern s32 func_00145270(s32 param);
extern s32 func_0018ced0();
extern void func_0018c7e0();
extern void func_00122640(s32 a, s32 b);
extern s32 func_00122720();
extern void func_00122520(s32 a, s32 b);
extern s32 func_00452490(u8 *param);
extern u8 *func_0029db50(s32 a, s32 b, s32 c, s32 d);
extern void func_003e9cb0(s32 param, u8 *src, s32 mode);
extern void func_004577d0(u8 *param, f32 value);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
extern void func_00189600(u8 *param, s32 a, s32 b, f32 value);
void func_00187f50(void);
void func_00188030(void);
extern u8 D_005F1EF8[];
extern u8 D_005F1FB8[];
extern u8 D_005F1FA8[];
extern u8 D_005F1FD0[];
extern u8 D_005F1FF0[];
extern u8 D_005F1E40[];
extern u8 D_005F1E60[];
extern u8 D_005F1E80[];
extern u8 D_005F1EA0[];
extern u8 D_005F1EC0[];
extern u8 D_005F1EE0[];
extern u8 D_005F1F10[];
extern u8 D_005F1F30[];
extern u8 D_005F1F50[];
extern u8 D_005F1F70[];
extern u8 D_005F1F90[];
extern u8 D_005F2010[];
extern u8 D_005F2030[];
extern u8 D_005F2050[];
extern u8 D_005F2070[];
extern u8 D_005F2090[];
extern s32 func_00186ac0(u8 *arg0);
extern s32 func_00188be0(u8 *arg0);
extern s32 func_001891d0(u8 *arg0);
extern u8 D_005F2180[];
extern f32 D_005F20B0[];
extern f32 D_005F20B4[];
extern f32 D_005F20B8[];
extern f32 D_005F20BC[];
extern f32 D_005F20C0[];
extern f32 D_005F20C4[];
extern f32 D_005F2130[];
extern f32 D_005F2134[];
extern f32 D_005F2138[];
extern f32 D_005F213C[];
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern f32 D_005F1E20[];
extern u16 D_008C024E;
extern u16 D_008C0252;
extern u8 D_00795E60[];
extern char iGpffff9f68;
extern char iGpffff9f70;
extern f32 iGpffff84a4;
extern f32 iGpffff8538;
void func_00188200(u8 *arg0, u8 *arg1);
void func_00188320(u8 *arg0, u8 *arg1);
void func_00188590(u8 *arg0, u8 *arg1, s32 arg2);
void func_00188690(u8 *arg0, u8 *arg1, s32 arg2);
void func_001887f0(u8 *arg0, u8 *arg1, s32 arg2);
void func_00188940(u8 *arg0, u8 *arg1, s32 arg2);
u8 *func_00188f20(u8 *arg0, s32 arg1, u8 *arg2);
void func_00189060(u8 *arg0, s32 arg1, f32 fparg0);
u8 *func_00189550(u8 *arg0);
void func_00189600(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0);

// FUN_001866D0
s32 func_001866d0(u8 *arg0)
{
    s32 sp8C;
    u8 sp40[0x4C];
    s32 temp_17_2;
    s32 temp_3;
    s64 temp_17;
    s64 temp_18;
    s64 temp_3_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        temp_17 = (s16)func_001060b0();
        temp_18 = (s8)func_00110960(temp_17, func_001060c0() & 0xFF);
        temp_17_2 = func_001060c0() & 0xFF;
        if (func_00106330(0x8A) == 1) {
            if ((s8)temp_18 == 1) {
                func_00442088(sp40, D_005F1E40);
            } else {
                func_00442088(sp40, D_005F1E60);
            }
        } else {
            temp_3_2 = (s8)temp_18;
            if (temp_3_2 == 0) {
                if ((temp_17_2 & 0xFF) < 4) {
                    func_00442088(sp40, D_005F1E80);
                } else {
                    func_00442088(sp40, D_005F1EA0);
                }
            } else if (temp_3_2 == 2) {
                func_00442088(sp40, D_005F1EC0);
            } else if (temp_3_2 == 1) {
                func_00442088(sp40, D_005F1EE0);
            } else {
                func_0046d730(D_005F1EF8, 0xC5);
            }
        }
        func_00440b68(&iGpffff9f68, D_005F1EF8, 0xC8);
        *(u8 **)(temp_16 + 4) = func_00454a60(sp40, 1);
        *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
        /* fallthrough */
    case 1:
        if (func_004553c0(*(u8 **)(temp_16 + 4)) != 0) {
            *(s32 *)(*(u8 **)(temp_16 + 8) + 0x38) = func_0046af60(func_00455f70(D_005F1F10, &sp8C));
            *(s32 *)(*(u8 **)(temp_16 + 8) + 0x3C) = func_0046af60(func_00455f70(D_005F1F30, &sp8C));
            *(s32 *)(*(u8 **)(temp_16 + 8) + 0x40) = func_0046af60(func_00455f70(D_005F1F50, &sp8C));
            *(s32 *)(*(u8 **)(temp_16 + 8) + 0x44) = func_0046af60(func_00455f70(D_005F1F70, &sp8C));
            *(s32 *)(*(u8 **)(temp_16 + 8) + 0x48) = func_0046af60(func_00455f70(D_005F1F90, &sp8C));
            *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
        }
        break;
    case 2:
        if ((func_0046a750(*(s32 *)(*(u8 **)(temp_16 + 8) + 0x38)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(temp_16 + 8) + 0x3C)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(temp_16 + 8) + 0x40)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(temp_16 + 8) + 0x44)) != 0) && (func_0046a750(*(s32 *)(*(u8 **)(temp_16 + 8) + 0x48)) != 0)) {
            *(s32 *)temp_16 = *(s32 *)temp_16 + 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00186A60
void func_00186a60(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(*(u8 **)(temp_4 + 8) + 4) = 1;
    func_00454bd0(*(u8 **)(temp_4 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

/* measured: retail materialises the tail 0.0f store as mtc1 $0,$f1 + swc1
   (mtc1 hoisted above the blez); mwcc b210 constant-folds every spelling of
   `*(f32 *)(ptr+4) = 0.0f` (literal, (f32)(s32)0, named local) into `sw $0`
   (nd 2: missing mtc1 + swc1-vs-sw; branch offsets cascade). FP-zero-store
   fold floor. */
// FUN_00186AC0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00186ac0);

// FUN_00186C90
void func_00186c90(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00186CC0
u8 *func_00186cc0(u8 *arg0, u8 *arg1, f32 fparg0, f32 fparg1, u8 *arg2, u8 *arg3, s32 arg4, s32 arg5)
{
    u8 *temp_2_2;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_5;

    func_0044ea90(D_005F1EF8, 0x175);
    temp_2_2 = (u8 *)D_008873F4[0](1, 0x2C, 0x40000);
    if (temp_2_2 == NULL) {
        return NULL;
    }
    temp_2 = (u8 *)func_00451fc0(arg0, D_005F1FB8, 0xF, 0, 0, func_00186ac0, func_00186c90, temp_2_2);
    temp_3 = temp_2_2 + 4;
    *(u8 **)(temp_2_2 + 4) = arg1;
    *(f32 *)(temp_2_2 + 0xC) = fparg0;
    *(f32 *)(temp_2_2 + 0x10) = fparg1;
    temp_5 = temp_2_2 + 8;
    *(u8 **)(temp_2_2 + 8) = arg2;
    *(u8 **)(temp_2_2 + 0x28) = arg3;
    *(s32 *)(temp_2_2 + 0x1C) = arg4;
    *(s32 *)(temp_2_2 + 0x20) = arg4;
    *(s32 *)(temp_2_2 + 0x24) = arg5;
    if (arg2 != NULL) {
        *(s32 *)(*(u8 **)temp_3 + 8) = 0x43960000;
        *(s32 *)(*(u8 **)temp_5 + 8) = 0x43C80000;
    }
    return temp_2;
}

// FUN_00186E10
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * constant 1 (addiu $a1, $zero, 1) inside the loop body at both store sites;
 * retail hoists it to the preheader. The pragma restores the hoist (nd 35 -> 0). */
#pragma opt_loop_invariants on
void func_00186e10(u8 *arg0)
{
    s32 var_7;
    u8 *var_6;

    var_7 = 0;
    while (var_7 < 5) {
        if ((u32)*(u32 *)arg0 > 8U) {
            var_6 = arg0 + (var_7 * 4);
            *(s32 *)(var_6 + 0x4C) = 0;
            *(s32 *)(var_6 + 0x60) = 0;
        } else {
            if (*(s32 *)(arg0 + 0xC) != var_7) {
                var_6 = arg0 + (var_7 * 4);
                *(s32 *)(var_6 + 0x4C) = 1;
            } else {
                var_6 = arg0 + (var_7 * 4);
                *(s32 *)(var_6 + 0x4C) = 0;
            }
            if (*(s32 *)(arg0 + 0xC) == var_7) {
                *(s32 *)(var_6 + 0x60) = 1;
            } else {
                *(s32 *)(var_6 + 0x60) = 0;
            }
        }
        var_7 += 1;
    }
}
/* measured: see annotation above. */
#pragma opt_loop_invariants off

extern s32 func_00186eb0(u8 *arg0);

/* measured: retail fills each jal/branch delay slot with the following call's
   first arg setup (move $a0 / addiu $a1) while mwcc b210 always emits nop,
   shifting every subsequent call block by one word; also $4 = arg0 moves are
   re-emitted per call where retail reuses them, and the case-0/7 bodies need
   per-site scheduling fixes (nd ~820 of 952 words, attempted decl orders,
   pragma, comparison forms). Delay-slot fill floor. */
// FUN_00186EB0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00186eb0);

// FUN_00187DA0
void func_00187da0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_0046b0d0(*(u8 **)(temp_16 + 0x24));
    func_0046b0d0(*(u8 **)(temp_16 + 0x2C));
    func_0046b0d0(*(u8 **)(temp_16 + 0x30));
    func_0046b0d0(*(u8 **)(temp_16 + 0x28));
    func_0046b0d0(*(u8 **)(temp_16 + 0x34));
    func_0046b0d0(*(u8 **)(temp_16 + 0x38));
    func_0046b0d0(*(u8 **)(temp_16 + 0x3C));
    func_0046b0d0(*(u8 **)(temp_16 + 0x40));
    func_0046b0d0(*(u8 **)(temp_16 + 0x44));
    func_0046b0d0(*(u8 **)(temp_16 + 0x48));
    func_00145080();
    func_003e0f40(*(u8 **)(temp_16 + 0x18));
    func_00454bd0(*(u8 **)(temp_16 + 0x20));
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00187E80
u8 *func_00187e80(u8 *arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2_2;
    u8 *temp_2;

    func_0044ea90(D_005F1EF8, 0x343);
    temp_2_2 = (u8 *)D_008873F4[0](1, 0x178, 0x40000);
    if (temp_2_2 == NULL) {
        return NULL;
    }
    temp_2 = (u8 *)func_00451fc0(arg0, &iGpffff9f70, 0xF, 0, 0, func_00186eb0, func_00187da0, temp_2_2);
    *(s32 *)(temp_2_2 + 0xC) = arg1;
    *(s32 *)(temp_2_2 + 0x10) = -1;
    *(s32 *)(temp_2_2 + 8) = arg2;
    return temp_2;
}

// FUN_00187F50
void func_00187f50(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x71009);
}

// FUN_00188030
void func_00188030(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x7100D);
}

// FUN_00188110
void func_00188110(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    tbl[0](1, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x72001);
}

/* measured: retail materialises the f12/f13 constants (lui+mtc1) BEFORE the
   arg1 loads and interleaves f13's loads into f12's add->cvt latency; mwcc
   b210 emits the loads first and does not interleave (nd 40 in the chains).
   Retail also places the f14 = arg1[8] load after the f16 constant and before
   the a0 lui; mwcc sinks it to just before the jal (load-sinking floor).
   Tried inline, f32 locals, and pointer-last func_0025ecd0 prototype (that
   one fixes the a7-last emission, kept in the file); all nd 56. */
// FUN_00188200
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188200);

/* measured: at 4 attempts. Progress: pragma opt_loop_invariants + decl order
   (var_17 first) + 102.0f (0x42CC0000, not 100.0) fixed the frame (-0x60,
   f20 save), the loop-counter registers, and the outer-loop mul hoist; the
   madd.s/adda.s fused form compiles correctly. Remaining nd 135 is the
   argument-evaluation-order family: retail materialises constants before
   loads in every chain (e.g. f12 = -44.0f + arg1[0] uses 0xC2300000 = -44.0,
   not -40.0) and interleaves f13's loads into f12's add->cvt latency; mwcc
   emits load-first serialised chains and sinks the inner call's f14=arg1[8]
   load. Also retail fills the post-jal delay slot with move $s1 while mwcc
   emits nop (delay-slot-fill floor, see func_00186eb0). */
// FUN_00188320
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188320);

/* measured: retail hoists the f14 = arg1[8] load (lwc1 $f14, 8($s1)) up into
   the float-arg cluster (right after the f16 materialisation, before the a0
   lui); mwcc b210 always sinks it to just before the jal (after the a7 pair),
   nd 14. Tried inline arg, hoisted f32 local (spills to f20), pre-call
   assignment, and register f32 local - all identical. Load-sinking floor
   (arg-evaluation-order family). */
// FUN_00188590
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188590);

/* measured: retail interleaves the f13 chain's loads between f12's add.s and
   its cvt.w.s (sum in a fresh $f2), and places the f14 = arg1[8] load right
   after the f16 constant; mwcc b210 serialises the chains (sum reused in $f0,
   no interleave) and sinks the f14 load below the int args. Tried inline and
   f32 locals for sx/sy; identical nd 29. Argument-evaluation-order +
   load-sinking floor family (see also func_00188590/00188200 notes). */
// FUN_00188690
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188690);

/* measured: identical to func_00188690 - retail interleaves the f13 chain
   into f12's add->cvt latency (sum in fresh $f2) and loads f14 = arg1[8]
   right after the f16 constant; mwcc b210 serialises the chains and sinks the
   f14 load below the int args. Tried inline spelling only; nd 27.
   Argument-evaluation-order + load-sinking floor family. */
// FUN_001887F0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_001887f0);

/* measured: at 4 attempts. s32 locals for the scaled offsets (sel/idx) fix
   the two addu operand orders (retail addu $v0,$v0,$s2; lever #10 confirmed).
   Remaining nd 120 is the standard family: (1) argument-evaluation order -
   retail materialises the f12/f13 constants before the arg1 loads and
   interleaves f13's chain into f12's add->cvt latency (sum in fresh $f2);
   mwcc emits load-first serialised chains; (2) call 3's f13 = (f32)(s32)0.0f
   FOLDS to mtc1 $0,$f13 in mwcc while retail emits the cvt.w.s/cvt.s.w chain
   reusing the f15 zero - needs a runtime zero local, but a zero local assigned
   before the call shifts the whole cluster (tried, nd 145); (3) call 4's
   f14 = arg1[8] load sunk below the int args; (4) post-jal delay slot nop
   (retail fills with ld $ra). */
// FUN_00188940
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188940);

// FUN_00188BE0
/* measured: without opt_loop_invariants MWCC rematerializes the loop-invariant
 * ~2 mask (addiu $v1, $zero, -3) inside the loop body; retail hoists it to the
 * preheader. The pragma restores the hoist. */
#pragma opt_loop_invariants on
s32 func_00188be0(u8 *arg0)
{
    Vec3 sp30;
    Vec3 sp20;
    f32 temp_f1;
    s32 temp_2;
    s32 temp_3;
    s32 var_5;
    u8 *temp_16;
    u8 *temp_2_2;
    u8 *temp_4_2;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_5 = 0;
    while (var_5 < 5) {
        if (var_5 == *(s32 *)(temp_16 + 0x5C)) {
            temp_4 = *(u8 **)(*(u8 **)(temp_16 + 8) + (var_5 * 4));
            *(s32 *)(temp_4 + 0x28) = *(s32 *)(temp_4 + 0x28) | 2;
        } else {
            temp_4_2 = *(u8 **)(*(u8 **)(temp_16 + 8) + (var_5 * 4));
            *(s32 *)(temp_4_2 + 0x28) = *(s32 *)(temp_4_2 + 0x28) & ~2;
        }
        var_5 += 1;
    }
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        *(s32 *)temp_16 = temp_3 + 1;
        break;
    case 1:
        break;
    case 2:
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144));
        temp_f1 = *(f32 *)(temp_2_2 + 0x30);
        temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
        temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
        sp30.x = *(f32 *)(temp_2_2 + 0xC) - temp_f1;
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144));
        temp_f1 = *(f32 *)(temp_2_2 + 0x34);
        temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
        temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
        sp30.y = *(f32 *)(temp_2_2 + 0x10) - temp_f1;
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144));
        temp_f1 = *(f32 *)(temp_2_2 + 0x38);
        temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
        temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
        sp30.z = *(f32 *)(temp_2_2 + 0x14) - temp_f1;
        func_003e40b0(&sp30.x, &sp30.x);
        sp30.x = sp30.x * *(f32 *)(temp_16 + 0x54);
        sp30.y = sp30.y * *(f32 *)(temp_16 + 0x54);
        sp30.z = sp30.z * *(f32 *)(temp_16 + 0x54);
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144));
        temp_f1 = *(f32 *)(temp_2_2 + 0x30);
        sp20.x = sp30.x + temp_f1;
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144));
        temp_f1 = *(f32 *)(temp_2_2 + 0x34);
        sp20.y = sp30.y + temp_f1;
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144));
        temp_f1 = *(f32 *)(temp_2_2 + 0x38);
        sp20.z = sp30.z + temp_f1;
        temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
        temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
        sp30.x = *(f32 *)(temp_2_2 + 0xC) - sp20.x;
        temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
        temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
        sp30.y = *(f32 *)(temp_2_2 + 0x10) - sp20.y;
        temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
        temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
        sp30.z = *(f32 *)(temp_2_2 + 0x14) - sp20.z;
        func_003e40b0(&sp30.x, &sp30.x);
        if (*(f32 *)(temp_16 + 0x48) * sp30.x + *(f32 *)(temp_16 + 0x4C) * sp30.y + *(f32 *)(temp_16 + 0x50) * sp30.z <= 0.0f) {
            temp_2 = *(s32 *)(temp_16 + 0x58) * 0xC;
            temp_2_2 = (u8 *)(temp_2 + (s32)temp_16);
            *(Vec3 *)(&sp20.x) = *(Vec3 *)(temp_2_2 + 0xC);
            *(s32 *)(temp_16 + 0x5C) = *(s32 *)(temp_16 + 0x58);
            *(s32 *)(temp_16 + 0x58) = -1;
            *(s32 *)temp_16 = 1;
        }
        func_0047a180(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144), &sp20.x, 0);
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
/* measured: see annotation above. */
#pragma opt_loop_invariants off

// FUN_00188EF0
void func_00188ef0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00188F20
u8 *func_00188f20(u8 *arg0, s32 arg1, u8 *arg2)
{
    u8 *temp_18;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;
    s32 var_16;

    func_0044ea90(D_005F1EF8, 0x622);
    temp_2 = (u8 *)D_008873F4[0](1, 0x60, 0x40000);
    if (temp_2 == NULL) {
        return NULL;
    }
    temp_18 = (u8 *)func_00451fc0(arg0, D_005F2180, 0xF, 0, 0, func_00188be0, func_00188ef0, temp_2);
    *(s32 *)(temp_2 + 4) = arg1;
    *(u8 **)(temp_2 + 8) = arg2;
    *(s32 *)(temp_2 + 0x58) = -1;
    *(s32 *)(temp_2 + 0x5C) = -1;
    var_16 = 0;
    while (var_16 < 5) {
        temp_2_2 = func_0047a2f0(*(s32 *)(*(u8 **)(arg2 + (var_16 * 4)) + 0x144));
        temp_3 = temp_2 + (var_16 * 0xC);
        *(Vec3 *)(temp_3 + 0xC) = *(Vec3 *)(temp_2_2 + 0x30);
        var_16 += 1;
    }
    return temp_18;
}

/* measured: retail repeats the (func_0047a2f0 + addr + sub.s) sequence three
   times with func-result load ($f1) right after each jal; mwcc b210 matches
   blocks 1-2 but in block 3 hoists the address computation before the func-
   result load, flipping $f0/$f1 roles and the sub.s (nd 9). Tried statement
   locals, inline expressions, declaration orders, distinct locals: block 3
   allocator floor. */
// FUN_00189060
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00189060);

static inline f32 mulFp(f32 left, f32 right) { return left * right; }

// FUN_001891D0
s32 func_001891d0(u8 *arg0)
{
    f32 sp40[3];
    f32 temp_f20;
    f32 temp_f2_2;
    f32 temp_f2;
    s32 temp_3_2;
    s32 temp_3_3;
    s32 temp_3_4;
    s32 temp_3;
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_2_2;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_00457120();
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        *(s32 *)temp_16 = temp_3 + 1;
        break;
    case 1:
        break;
    case 2:
        temp_f20 = func_0044b7b0((iGpffff84a4 * (f32)*(s32 *)(temp_16 + 0x24)) / (f32)*(s32 *)(temp_16 + 0x28));
        temp_3_2 = *(s32 *)(temp_16 + 0x30) * 0x18;
        sp40[0] = *(f32 *)((u8 *)D_005F2190 + temp_3_2) - *(f32 *)(temp_16 + 4);
        sp40[1] = *(f32 *)((u8 *)D_005F2194 + temp_3_2) - *(f32 *)(temp_16 + 8);
        sp40[2] = *(f32 *)((u8 *)D_005F2198 + temp_3_2) - *(f32 *)(temp_16 + 0xC);
        temp_f2 = mulFp(func_003e40b0(&sp40[0], &sp40[0]), temp_f20);
        sp40[0] = sp40[0] * temp_f2;
        sp40[1] = sp40[1] * temp_f2;
        sp40[2] = sp40[2] * temp_f2;
        *(f32 *)(temp_16 + 4) = *(f32 *)(temp_16 + 4) + sp40[0];
        *(f32 *)(temp_16 + 8) = *(f32 *)(temp_16 + 8) + sp40[1];
        *(f32 *)(temp_16 + 0xC) = *(f32 *)(temp_16 + 0xC) + sp40[2];
        temp_3_3 = *(s32 *)(temp_16 + 0x30) * 0x18;
        sp40[0] = *(f32 *)((u8 *)D_005F219C + temp_3_3) - *(f32 *)(temp_16 + 0x10);
        sp40[1] = *(f32 *)((u8 *)D_005F21A0 + temp_3_3) - *(f32 *)(temp_16 + 0x14);
        sp40[2] = *(f32 *)((u8 *)D_005F21A4 + temp_3_3) - *(f32 *)(temp_16 + 0x18);
        temp_f2_2 = mulFp(func_003e40b0(&sp40[0], &sp40[0]), temp_f20);
        sp40[0] = sp40[0] * temp_f2_2;
        sp40[1] = sp40[1] * temp_f2_2;
        sp40[2] = sp40[2] * temp_f2_2;
        *(f32 *)(temp_16 + 0x10) = *(f32 *)(temp_16 + 0x10) + sp40[0];
        *(f32 *)(temp_16 + 0x14) = *(f32 *)(temp_16 + 0x14) + sp40[1];
        *(f32 *)(temp_16 + 0x18) = *(f32 *)(temp_16 + 0x18) + sp40[2];
        func_00457630(func_00457120(), temp_16 + 4, temp_16 + 0x10, 0);
        temp_3_4 = *(s32 *)(temp_16 + 0x24) + 1;
        *(s32 *)(temp_16 + 0x24) = temp_3_4;
        if (*(s32 *)(temp_16 + 0x28) < temp_3_4) {
            temp_17 = (u8 *)D_005F2190 + (*(s32 *)(temp_16 + 0x30) * 0x18);
            func_00457630(func_00457120(), temp_17, temp_17 + 0xC, 0);
            temp_2 = (u8 *)D_005F2190 + (*(s32 *)(temp_16 + 0x30) * 0x18);
            *(Vec3 *)(temp_16 + 4) = *(Vec3 *)(temp_2 + 0);
            temp_2_2 = (u8 *)D_005F219C + (*(s32 *)(temp_16 + 0x30) * 0x18);
            *(Vec3 *)(temp_16 + 0x10) = *(Vec3 *)(temp_2_2 + 0);
            *(s32 *)(temp_16 + 0x24) = 0;
            *(s32 *)temp_16 = 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_00189520
void func_00189520(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00189550
u8 *func_00189550(u8 *arg0)
{
    u8 *temp_2_2;
    u8 *temp_2;

    func_0044ea90(D_005F1EF8, 0x735);
    temp_2_2 = (u8 *)D_008873F4[0](1, 0x34, 0x40000);
    if (temp_2_2 == NULL) {
        return NULL;
    }
    temp_2 = (u8 *)func_00451fc0(arg0, D_005F2180, 0xF, 0, 0, func_001891d0, func_00189520, temp_2_2);
    *(s32 *)(temp_2_2 + 0x30) = -1;
    return temp_2;
}

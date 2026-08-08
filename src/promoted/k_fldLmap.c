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

/* measured re-triage: switch CFG candidate reproduces the main state/update
   path, but MWCC b210 still folds the retail mtc1 $0 + swc1 zero store to
   sw $0 and leaves the candidate 8 bytes short of the retail window. Best
   candidate: normalized_diff 103, object 456/464; discarded. */
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

/* measured re-triage: generated-style candidate covers the complete
   initialisation and state-machine body, but its call/branch scheduling and
   delay-slot placement diverge substantially. Best candidate:
   normalized_diff 2871, object 3964/3824; discarded. */
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

/* measured re-triage: corrected generated-style candidate has the complete
   color-call setup and exact size, but MWCC b210 serialises the retail
   constant-before-load and cross-chain float scheduling. Best candidate:
   normalized_diff 154, object 288/288; discarded. */
// FUN_00188200
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188200);




/* measured re-triage: corrected loop/call CFG and declaration order produce
   exact size, but MWCC b210 differs in the repeated float argument
   materialisation and call scheduling. Best candidate:
   normalized_diff 321, object 624/624; discarded. */
// FUN_00188320
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188320);

/* measured re-triage: candidate reproduces the complete setup and color call (object 244/256). Retail hoists the f14 = arg1[8] load immediately after the f16 constant, before integer argument materialisation; MWCC b210 sinks it below the integer arguments in every tested spelling. Tried inline load, f32 local, pre-call assignment, and register f32 local; best exact C residual is normalized_diff 24. Committed at nd 24. */
// FUN_00188590 NONMATCHING
#ifdef NON_MATCHING
void func_00188590(u8 *arg0, u8 *arg1, s32 arg2)
{
    s32 temp_3;
    u8 *temp_2;
    f32 temp_f14;
    temp_2 = func_00460990();
    *(void (**)(void))(temp_2 + 8) = (void (*)(void))func_00188030;
    *(s32 *)(temp_2 + 0x10) = 0;
    func_00460ac0(D_00795E60, temp_2);
    temp_3 = arg2 * 0x18;
    temp_f14 = *(f32 *)(arg1 + 8);
    func_0025ecd0(0xFF0000, 2, arg2, *(s32 *)(arg0 + 0x34), 0, 0, 0, (f32)(s32)(*(f32 *)arg1 + *(f32 *)((u8 *)D_005F20B0 + temp_3)), (f32)(s32)(*(f32 *)(arg1 + 4) + *(f32 *)((u8 *)D_005F20B4 + temp_3)), temp_f14, 0.0f, 1.0f, 1.0f, D_00795E60);
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188590);
#endif

/* measured re-triage: corrected two-call body has the expected setup and
   near-retail size, but MWCC b210 sinks the f14 load below the integer
   arguments and does not interleave the f13 chain. Best candidate:
   normalized_diff 82, object 344/352; discarded. */
// FUN_00188690
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188690);

/* measured re-triage: corrected two-call body has exact size, but MWCC b210
   sinks the f14 load below the integer arguments and serialises the f13
   chain. Best candidate: normalized_diff 79, object 336/336; discarded. */
// FUN_001887F0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_001887f0);



/* measured re-triage: corrected four-call body is complete but exceeds the
   retail window by one word and retains the float argument-order/scheduling
   residual. Best candidate: normalized_diff 376, object 676/672; discarded. */
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

/* measured re-triage: reconstructed state/zero/nonzero light-map updates. Retail uses addu $v0,$v0,$s0 for each of the three scaled vertex addresses; mwcc emits addu $v0,$s0,$v0 despite matching all other instructions and leaves a 4-byte tail gap. Tried direct expressions, reusable scaled-offset locals, and integer-domain address arithmetic; best exact C residual is normalized_diff 15, object 364/368. Committed at nd 15. */
// FUN_00189060 NONMATCHING
#ifdef NON_MATCHING
void func_00189060(u8 *arg0, s32 arg1, f32 fparg0)
{
    f32 *temp_4_2;
    s32 temp_4;
    u8 *temp_16;
    temp_16 = *(u8 **)(arg0 + 0x38);
    *(f32 *)(temp_16 + 0x54) = fparg0;
    temp_4 = *(s32 *)temp_16;
    if (((temp_4 != 1) || (*(s32 *)(temp_16 + 0x5C) != arg1)) && ((temp_4 != 2) || (*(s32 *)(temp_16 + 0x58) != arg1))) {
        if (fparg0 != 0.0f) {
            *(s32 *)(temp_16 + 0x58) = arg1;
            *(s32 *)(temp_16 + 0x5C) = -1;
            *(f32 *)(temp_16 + (*(s32 *)(temp_16 + 0x58) * 0xC) + 0xC) = *(f32 *)(temp_16 + (*(s32 *)(temp_16 + 0x58) * 0xC) + 0xC) - *(f32 *)(func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144)) + 0x30);
            *(f32 *)(temp_16 + (*(s32 *)(temp_16 + 0x58) * 0xC) + 0x10) = *(f32 *)(temp_16 + (*(s32 *)(temp_16 + 0x58) * 0xC) + 0x10) - *(f32 *)(func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144)) + 0x34);
            *(f32 *)(temp_16 + (*(s32 *)(temp_16 + 0x58) * 0xC) + 0x14) = *(f32 *)(temp_16 + (*(s32 *)(temp_16 + 0x58) * 0xC) + 0x14) - *(f32 *)(func_0047a2f0(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144)) + 0x38);
            temp_4_2 = (f32 *)(temp_16 + 0x48);
            func_003e40b0(temp_4_2, temp_4_2);
            *(s32 *)temp_16 = 2;
            return;
        }
        *(s32 *)(temp_16 + 0x58) = -1;
        *(s32 *)(temp_16 + 0x5C) = arg1;
        func_0047a180(*(s32 *)(*(u8 **)(temp_16 + 4) + 0x144), temp_16 + (arg1 * 0xC) + 0xC, 0);
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00189060);
#endif

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

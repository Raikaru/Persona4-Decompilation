#include "include_asm.h"
/* Persona 4 USA decompilation - effBlurFilter.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*jtbl_008873EC[])(void *ptr);

/* Defined below in this file; called above its definition. */
extern u8 *func_004ab960(u16 *arg0, u16 arg1);

extern char D_00714380[];
extern u8 D_00714394[];
extern u8 D_00714398[];
extern u8 D_0071439C[];
extern u8 D_007143A0[];
extern char D_00714450[];
extern u8 D_00714464[];
extern u8 D_00714468[];
extern u8 D_0071446C[];
extern u8 D_00714470[];

extern void func_0046d730(const char *file, s32 line);
extern void func_0044ea90(const char *file, s32 line);
extern void func_003f6690(s32 param, void *out);
extern void func_003f6440(s32 param, s32 value);
extern void (*D_00887300[])(u32 state, u32 value);
extern void (*D_00887314[])(s32, void *, s32, void *, s32);
extern u32 D_00922D90[];
extern u8 D_00714368[];
extern void func_0048a070(s64 arg);
extern void func_0048a0e0(void);
extern void func_00489f80(void);
extern void func_0048a000(void);
extern s32 func_004a7e30(u8 *arg0, void *arg1);
extern void func_004a8250(u8 *arg0, void *arg1);
extern void func_004a8440(u8 *arg0, void *arg1);
extern void func_004a86c0(u8 *arg0, void *arg1);
extern void func_00460ac0(s32 param, void *work);
extern s32 func_004814d0(u16 param);
extern void *func_0043f9c8(void *dest, s32 value, s32 size);
extern void func_0043f810(void *dst, const void *src, u32 size);
extern void func_003ef3a0(void *ptr);
extern f32 fGpffff80f8;
extern void func_004a8a50(u8 *arg0, u8 *arg1);
extern void func_004a8da0(u8 *arg0, u8 *arg1);
extern void func_004a8890(u8 *arg0, s32 *arg1);
extern s32 func_00481390(void *ptr);
extern s32 func_00481300(u16 param);
extern s32 func_00484490(void);
extern u16 *func_004844d0(u8 *obj);
extern u8 D_00714390[];
extern u8 D_007143A4[];
extern u8 D_00714460[];
extern u8 D_00714474[];
extern u8 *func_004aaee0(u32 arg0, s32 arg1);
extern u8 *func_004ab420(u32 arg0, s32 arg1);

typedef struct BlurRefObj {
    s32 f0;
    s32 f4;
} BlurRefObj;

extern void *func_004abb00(BlurRefObj *param_1);
extern void func_004aba70(void *param_1);

extern f32 func_0044b7b0(f32 fparg0);
extern s32 func_0044dcd8(f32 a);
extern s32 func_0044b310(s32 a);
extern s32 func_0044e100(s64 a, s32 b);
extern s32 func_0044e168(s64 a, s32 b);
extern f32 func_0044e7d8(s32 a);
extern f32 fGpffff8084;
extern s64 fGpffff8018;
extern s64 fGpffff8010;
extern s64 fGpffff8020;
extern s64 fGpffff8010;
extern s64 fGpffff8020;

extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
extern f32 func_0048aff0(u8 *a, s32 b, s32 c);
extern f32 func_0048a650(f32 a);
extern f32 fGpffff8044;
extern f32 fGpffff80f0;
extern void func_004a8bb0(u8 *a, u8 *b);
extern void func_004a8f90(u8 *a, u8 *b);
extern void func_004a9180(u8 *a, u8 *b);

/* measured: optimization_level 1 plus the swapped integer declaration order and
   a block-local threshold produce object 488B/window 496B and only the two
   zero-padding tail words differ in the standalone probe (nd 2). Compound
   overflow masking keeps the OR/ANDI result in the retail destination
   register; the candidate body follows the 004A8F90 sibling skeleton. */
/* measured: func_004a8bb0 O1 bracket, standalone probe object 488B/window 496B,
   normalized_diff 2 (retail-only zero-padding tail). */
#pragma optimization_level 1
// FUN_004A8BB0
void func_004a8bb0(u8 *a, u8 *b) {
    int *param_1 = (int *)a;
    float *param_2 = (float *)b;
    int iVar4;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } uVar2;
    int iVar1;
    float fVar6;
    float alphaF;
    float temp_f1;
    u32 alpha;
    s32 var_4;

    iVar1 = *param_1;
    if (!(iVar1 <= 0x64)) {
        func_0046d730(D_00714380, 0x190);
    }
    uVar2.packed = (u32)param_1[3];
    alpha = (u32)uVar2.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        if (((int *)param_2)[0] == 0) {
            float threshold;
            if (!(param_2[1] <= fGpffff8084)) {
                func_004a8a50(a, (u8 *)param_2);
            }
            fVar6 = func_0044b7b0(param_2[1]);
            param_2[6] = 1.0f + ((float *)param_1)[6] * fVar6;
            temp_f1 = alphaF * func_0044e7d8(func_0044e168(fGpffff8018, func_0044e100(fGpffff8020, func_0044b310(func_0044dcd8(param_2[1])))));
            threshold = 2.1474836e9f;
            if (threshold <= temp_f1) {
                goto alpha_big;
            }
            var_4 = (s32)temp_f1;
            var_4 &= 0xFF;
            goto alpha_done;
        alpha_big:
            var_4 = (s32)(temp_f1 - threshold);
            var_4 |= 0x80000000;
            var_4 &= 0xFF;
        alpha_done:
            *((u8 *)param_2 + 0xF) = (u8)var_4;
            param_2[1] = param_2[1] + ((float *)param_1)[2];
        } else {
            *((u8 *)param_2 + 0xF) = 0;
            ((int *)param_2)[0] = ((int *)param_2)[0] - 1;
        }
        param_2 = param_2 + 0x34 / 4;
    }
}
/* measured: closes func_004a8bb0 O1 bracket; restore O2 for the next function. */
#pragma optimization_level 2

extern u32 func_004bd050(u32 param);
extern f32 func_004bd0b0(u32 param);
extern f32 func_0044b610(f32 param);
extern f32 fGpffff80f4;
extern f32 fGpffff80cc;
/* measured: re-measured this wave at nd 12 (6 rows, one block) with a full
   candidate rebuilt from the m2c (int literals 810/650 -> addiu+mtc1+cvt,
   reverse decl order t23..t1, chains written `t21 + (810 - t20 - t21) *
   rand` with the product as the madd's fs operand). Chain 1, chain 2's
   adda/madd, the 4th/5th madd sites and all stores match byte-for-byte.
   Residual is exactly two coupled facts: (1) mwcc b210 CSEs fGpffff80cc*t20
   across the `t21 = t21 + fcc*t20; t23 = 0.5f*t1 + fcc*t20;` pair - it
   emits mul.s(prod); adda.s 0+prod; madd.s(0.5f,t1); add.s, where retail
   mula-seeds 0.5f*t1 first, then mul.s(prod), add.s, madd.s(fcc,t20)
   re-deriving the product; (2) the chain-2 sub-chain temps swap ($f1/$f2
   vs retail $f2/$f1) as a knock-on of the CSE block's $f1 use. New
   spellings this wave: f32 prod local (2 placements, nd 108-111), (f32)
   cast on one product (folds, nd 12), &fGpffff80cc deref (nd 46). Both
   statement orders tried. FMA-CSE fusion floor. */
// FUN_004A8DA0
void func_004a8da0(u8 *arg0, u8 *arg1) {
    f32 temp_f23;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    u8 *temp_16;

    *(u32 *)arg1 = func_004bd050(0) % (u32)(*(s32 *)(arg0 + 4) + 1);
    *(f32 *)(arg1 + 4) = fGpffff80f4;
    temp_16 = arg1 + 8;
    *(s32 *)(arg1 + 0x10) = *(s32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x14) = *(f32 *)(arg0 + 0x14);
    *(s32 *)(arg1 + 0xC) = *(s32 *)(arg0 + 0xC);
    temp_f20 = 0.5f * (f32)*(s32 *)(arg0 + 0x28);
    temp_f22 = fGpffff8084 * (2.0f * (func_004bd0b0(0) - 0.5f));
    temp_f21 = *(f32 *)(arg0 + 0x30);
    temp_f21 = temp_f21 + (810.0f - temp_f20 - temp_f21) * func_004bd0b0(0);
    temp_f21 = (f32)(0.5f * temp_f21);
    temp_f23 = *(f32 *)(arg0 + 0x2C);
    temp_f23 = temp_f23 + (650.0f - temp_f20 - temp_f23) * func_004bd0b0(0);
    temp_f23 = (f32)(0.5f * temp_f23);
    temp_f21 = temp_f21 + fGpffff80cc * temp_f20;
    temp_f23 = temp_f23 + fGpffff80cc * temp_f20;
    temp_f21 = *(f32 *)(arg0 + 0x1C) + temp_f21 * func_0044b610(temp_f22);
    temp_f23 = *(f32 *)(arg0 + 0x20) + temp_f23 * func_0044b7b0(temp_f22);
    *(f32 *)(temp_16 + 0x14) = temp_f21;
    *(f32 *)(temp_16 + 0x18) = temp_f23;
    *(f32 *)(temp_16 + 0x1C) = temp_f21 - temp_f20;
    *(f32 *)(temp_16 + 0x20) = temp_f23 - temp_f20;
    *(f32 *)(temp_16 + 0x24) = temp_f21 + temp_f20;
    *(f32 *)(temp_16 + 0x28) = temp_f23 + temp_f20;
}

/* measured: cluster transfer from func_004a8bb0 — changing only the assert
   line to 575 and the recursive helper to func_004a8da0 preserves the exact
   488B candidate body/window 496B with only the two retail zero-padding tail
   words outside the standalone object (nd 2). */
/* measured: func_004a8f90 O1 bracket, standalone probe object 488B/window 496B,
   normalized_diff 2 (retail-only zero-padding tail). */
#pragma optimization_level 1
// FUN_004A8F90
void func_004a8f90(u8 *a, u8 *b) {
    int *param_1 = (int *)a;
    float *param_2 = (float *)b;
    int iVar4;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } uVar2;
    int iVar1;
    float fVar6;
    float alphaF;
    float temp_f1;
    u32 alpha;
    s32 var_4;

    iVar1 = *param_1;
    if (!(iVar1 <= 0x64)) {
        func_0046d730(D_00714380, 575);
    }
    uVar2.packed = (u32)param_1[3];
    alpha = (u32)uVar2.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        if (((int *)param_2)[0] == 0) {
            float threshold;
            if (!(param_2[1] <= fGpffff8084)) {
                func_004a8da0(a, (u8 *)param_2);
            }
            fVar6 = func_0044b7b0(param_2[1]);
            param_2[6] = 1.0f + ((float *)param_1)[6] * fVar6;
            temp_f1 = alphaF * func_0044e7d8(func_0044e168(fGpffff8018, func_0044e100(fGpffff8010, func_0044b310(func_0044dcd8(param_2[1])))));
            threshold = 2.1474836e9f;
            if (threshold <= temp_f1) {
                goto alpha_big;
            }
            var_4 = (s32)temp_f1;
            var_4 &= 0xFF;
            goto alpha_done;
        alpha_big:
            var_4 = (s32)(temp_f1 - threshold);
            var_4 |= 0x80000000;
            var_4 &= 0xFF;
        alpha_done:
            *((u8 *)param_2 + 0xF) = (u8)var_4;
            param_2[1] = param_2[1] + ((float *)param_1)[2];
        } else {
            *((u8 *)param_2 + 0xF) = 0;
            ((int *)param_2)[0] = ((int *)param_2)[0] - 1;
        }
        param_2 = param_2 + 0x34 / 4;
    }
}
/* measured: closes func_004a8f90 O1 bracket; restore O2 for the next function. */
#pragma optimization_level 2
// FUN_004A9180
void func_004a9180(u8 *a, u8 *b) {
    int *param_1 = (int *)a;
    float *param_2 = (float *)b;
    int iVar1;
    union { struct { u8 r; u8 g; u8 b2; u8 a; } rgba; u32 packed; } uVar2;
    int iVar4;
    int iVar5;
    float fVar6;
    int iVar7;
    float fVar8;
    float alphaF;
    int iVar9;
    u32 alpha;

    iVar1 = *param_1;
    uVar2.packed = (u32)param_1[3];
    alpha = (u32)uVar2.rgba.a;
    if (alpha >= 0) {
        alphaF = (float)alpha;
    } else {
        alpha = (alpha >> 1) | (alpha & 1);
        alphaF = (float)alpha;
        alphaF += alphaF;
    }

    for (iVar4 = 0; iVar4 < iVar1; iVar4 = iVar4 + 1) {
        if (!(*param_2 < 0.0f)) {
            fVar6 = func_0044b7b0(param_2[1]);
            param_2[6] = ((float *)param_1)[6] * fVar6 * (1.0f - *param_2) + 1.0f;
            ((int *)param_2)[3] = param_1[3];
            fVar6 = alphaF * (1.0f - *param_2);
            *((u8 *)param_2 + 0xf) = (u8)(u32)fVar6;
            iVar7 = (int)((float)param_1[10] * *param_2);
            iVar9 = (int)((float *)param_1)[8];
            iVar5 = (int)((float *)param_1)[9];
            param_2[7] = (float)iVar9;
            param_2[8] = (float)iVar5;
            param_2[9] = (float)(iVar9 - iVar7);
            param_2[10] = (float)(iVar5 - iVar7);
            param_2[0xb] = (float)(iVar9 + iVar7);
            param_2[0xc] = (float)(iVar5 + iVar7);
            param_2[1] = param_2[1] + ((float *)param_1)[7];
            fVar6 = ((float *)param_1)[1];
            fVar8 = *param_2;
            *param_2 = fVar8 + fVar6;
            if (!(fVar8 + fVar6 <= 1.0f)) {
                param_2[1] = 0.0f;
                *param_2 = 0.0f;
                ((int *)param_2)[4] = param_1[4];
                param_2[5] = ((float *)param_1)[5];
            }
        }
        else {
            *param_2 = *param_2 + ((float *)param_1)[1];
        }
        param_2 = param_2 + 0xd;
    }
}
// FUN_004A93D0
void func_004a93d0(u8 *arg0) {
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    u8 *base;
    u8 *obj;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (b == 0) {
        *(s32 *)(base + 0x10) = 0x43A00000;
        *(s32 *)(base + 0x14) = 0x43600000;
        *(s32 *)(base + 0x18) = 0;
        *(s32 *)(base + 0x1C) = 0;
        *(s32 *)(base + 0x20) = 0x44200000;
        *(s32 *)(base + 0x24) = 0x43E00000;
        *(s32 *)(base + 4) = *(s32 *)(obj + 0x28);
    }
    if (a >= b) {
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp6C = *(s32 *)(arg0 + 0x10);
        pt = &sp6C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp68 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x64($sp)      \n"
            :
            : "r"(&sp68), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
        *(s32 *)base = *(volatile s32 *)&sp64;
        *(f32 *)(base + 0xC) = 1.0f + fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 8) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        return;
    }
    *(s8 *)(base + 3) = 0;
}

// FUN_004A9590
void func_004a9590(u8 *arg0) {
    s32 sp12C;
    u8 sp20[0x108];
    u8 *base;

    base = *(u8 **)(arg0 + 0x24) + 0xC0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x24) + 0xC3) > 0) {
        func_003f6690(3, &sp12C);
        if (func_004a7e30(base, sp20) != 0) {
            D_00887300[0](1, D_00922D90[0]);
            func_003f6440(3, 0x31001);
            func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
            D_00887314[0](3, sp20, 4, D_00714368, 6);
            func_0048a0e0();
        }
        func_003f6440(3, sp12C);
        D_00887300[0](1, 0);
    }
}

// FUN_004A9690
void func_004a9690(u8 *arg0) {
    f32 vec[4];
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    u8 *base;
    u8 *obj;
    s32 b;
    s32 a;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 g;
    f32 prod;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(f32 *)(base + 0x14) = 320.0f;
            *(f32 *)(base + 0x18) = 224.0f;
            *(f32 *)(base + 0x1C) = 320.0f - f;
            *(f32 *)(base + 0x20) = 224.0f - f;
            *(f32 *)(base + 0x24) = 320.0f + f;
            *(f32 *)(base + 0x28) = 224.0f + f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            g = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x14) = vec[0];
            *(f32 *)(base + 0x18) = vec[1];
            *(f32 *)(base + 0x1C) = vec[0] - g;
            *(f32 *)(base + 0x20) = vec[1] - g;
            *(f32 *)(base + 0x24) = vec[0] + g;
            *(f32 *)(base + 0x28) = vec[1] + g;
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp7C = *(s32 *)(arg0 + 0x10);
        pt = &sp7C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp78 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x74($sp)      \n"
            :
            : "r"(&sp78), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 4) = *(volatile s32 *)&sp74;
        *(f32 *)(base + 0x10) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a) + 1.0f;
        *(f32 *)(base + 0xC) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 8) = *(s32 *)(obj + 0x28);
    } else {
        *(s8 *)(base + 7) = 0;
    }
}

typedef struct BlurGsQuad {
    f32 x, y;
    u8 pad0[0x38];
    f32 x1, y1;
    u8 pad1[0x38];
    f32 x2, y2;
    u8 pad2[0x38];
    f32 x3, y3;
    u8 pad3[0x38];
} BlurGsQuad;

// FUN_004A98D0
void func_004a98d0(u8 *arg0) {
    s32 sp24C;
    s32 sp248;
    u8 sp140[0xFC];
    u8 sp40[0x100];
    s32 *temp_16;
    u8 *temp_18;
    u8 *temp_3;
    void (**setState)(u32, u32);
    void (**sendPacket)(s32, void *, s32, void *, s32);

    temp_3 = *(u8 **)(arg0 + 0x24);
    temp_18 = temp_3 + 0xC0;
    if (*(u8 *)(temp_3 + 0xC7) > 0) {
        temp_16 = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        func_003f6690(2, &sp24C);
        func_003f6690(3, &sp248);
        setState = (void (**)(u32, u32))D_00887300;
        (*setState)((u32)1, *(u32 *)temp_16);
        func_00489f80();
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x31001);
        func_004a8250(temp_18 + 4, sp140);
        sendPacket = (void (**)(s32, void *, s32, void *, s32))D_00887314;
        (*sendPacket)(3, sp140, 4, D_00714368, 6);
        func_0048a000();
        func_003f6440(2, sp24C | 0x10);
        if (func_004a7e30(temp_18 + 4, sp40) != 0) {
            (*setState)(1, D_00922D90[0]);
            func_003f6440(3, 0x31001);
            func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
            (*sendPacket)(3, sp40, 4, D_00714368, 6);
            func_0048a0e0();
        }
        (*setState)(1, 0);
        func_003f6440(3, sp248);
        func_003f6440(2, sp24C);
    }
}

// FUN_004A9AA0
u8 *func_004a9aa0(u8 *arg0) {
    s32 i;
    u8 *alloc;
    u8 *base;
    u32 count;

    base = arg0 + 0xC0;
    if (!(*(u32 *)base <= 0x64)) {
        func_0046d730(D_00714380, 0x169);
    }
    count = *(u32 *)base;
    func_0044ea90(D_00714380, 0x16F);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        func_004a8a50(base, item);
        *(f32 *)(item + 4) = fGpffff80f8;
    }
    return alloc;
}

// FUN_004A9BA0
void func_004a9ba0(void *param_1) {
    (*jtbl_008873EC)(param_1);
}

// FUN_004A9BD0
void func_004a9bd0(u8 *arg0) {
    f32 vec[4];
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(s32 *)(base + 0x1C) = 0x43A00000;
            *(s32 *)(base + 0x20) = 0x43600000;
            *(f32 *)(base + 0x24) = f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            *(f32 *)(base + 0x24) = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x1C) = vec[0];
            *(f32 *)(base + 0x20) = vec[1];
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp8C = *(s32 *)(arg0 + 0x10);
        pt = &sp8C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp88 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sp88), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp84;
        *(f32 *)(base + 0x18) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 0x14) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
        func_004a8bb0(base, list);
    } else {
        *(s32 *)(base + 0xC) = 0;
    }
}
// FUN_004A9DD0
void func_004a9dd0(u8 *arg0) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 count;
    s32 *table;
    s32 i;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    if (*(s32 *)(obj + 0xCC) & 0xFF000000) {
        table = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        count = *(s32 *)base;
        if (!(count <= 0x64)) {
            func_0046d730(D_00714380, 0x1BA);
        }
        for (i = 0; i < count; i++) {
            if (*(s32 *)list == 0 && *(u8 *)(list + 0xF) > 0) {
                func_004a8890(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// FUN_004A9EA0
void func_004a9ea0(u8 *arg0) {
    u8 *base;
    u32 count;
    u8 *alloc;
    s32 i;

    base = arg0 + 0xC0;
    if (!(*(u32 *)base <= 0x28)) {
        func_0046d730(D_00714380, 0x292);
    }
    count = *(u32 *)base;
    func_0044ea90(D_00714380, 0x298);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        *(s32 *)(item + 4) = 0;
        *(s32 *)item = 0;
        *(s32 *)(item + 0x10) = *(s32 *)(arg0 + 0xD0);
        *(f32 *)(item + 0x14) = *(f32 *)(arg0 + 0xD4);
        *(f32 *)item = -(*(f32 *)(arg0 + 0xC8) * (f32)i);
    }
}

// FUN_004A9FA0
void func_004a9fa0(void *param_1) {
    (*jtbl_008873EC)(param_1);
}

// FUN_004A9FD0
void func_004a9fd0(u8 *arg0) {
    f32 vec[4];
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(s32 *)(base + 0x20) = 0x43A00000;
            *(s32 *)(base + 0x24) = 0x43600000;
            *(s32 *)(base + 0x28) = (s32)f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            *(s32 *)(base + 0x28) = (s32)func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x20) = vec[0];
            *(f32 *)(base + 0x24) = vec[1];
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp8C = *(s32 *)(arg0 + 0x10);
        pt = &sp8C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp88 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sp88), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp84;
        *(f32 *)(base + 0x1C) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 0x14) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
        func_004a9180(base, list);
    } else {
        *(s32 *)(base + 0xC) = 0;
    }
}

// FUN_004AA1F0
void func_004aa1f0(u8 *arg0) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 *table;
    s32 count;
    s32 i;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    if (*(s32 *)(obj + 0xCC) & 0xFF000000) {
        table = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        count = *(s32 *)base;
        for (i = 0; i < count; i++) {
            if (!(*(f32 *)list < 0.0f) && (*(u8 *)(list + 0xF) > 0)) {
                func_004a8890(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// FUN_004AA2B0
void func_004aa2b0(u8 *arg0) {
    s32 sp6C;
    s32 sp68;
    s32 sp64;
    u8 *base;
    u8 *obj;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (b == 0) {
        *(s32 *)(base + 0x10) = 0x43A00000;
        *(s32 *)(base + 0x14) = 0x43600000;
        *(s32 *)(base + 0x18) = 0;
        *(s32 *)(base + 0x1C) = 0;
        *(s32 *)(base + 0x20) = 0x44200000;
        *(s32 *)(base + 0x24) = 0x43E00000;
        *(s32 *)(base + 4) = *(s32 *)(obj + 0x28);
    }
    if (a >= b) {
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp6C = *(s32 *)(arg0 + 0x10);
        pt = &sp6C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp68 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x64($sp)      \n"
            :
            : "r"(&sp68), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)base = *(volatile s32 *)&sp64;
        *(f32 *)(base + 0xC) = 1.0f + func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 8) = func_0048aff0(obj + 0x60, b, a);
    } else {
        *(s8 *)(base + 3) = 0;
    }
}

// FUN_004AA460
void func_004aa460(u8 *arg0) {
    s32 sp12C;
    u8 sp20[0x108];
    void *setState;
    u8 *base;

    base = *(u8 **)(arg0 + 0x24) + 0xC0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x24) + 0xC3) > 0) {
        func_003f6690(3, &sp12C);
        func_004a8440(base, sp20);
        setState = (void *)D_00887300;
        (*(void (**)(u32, u32))setState)(1, D_00922D90[0]);
        func_003f6440(3, 0x31001);
        func_0048a070(0x9FC00A | ((s64)0x6FC << 0x20));
        D_00887314[0](3, sp20, 4, D_00714368, 6);
        func_0048a0e0();
        (*(void (**)(u32, u32))setState)(1, 0);
        func_003f6440(3, sp12C);
    }
}
// FUN_004AA560
u8 *func_004aa560(u8 *arg0) {
    s32 i;
    u8 *alloc;
    u8 *base;
    u32 count;

    base = arg0 + 0xC0;
    if (!(*(u32 *)base <= 0x64)) {
        func_0046d730(D_00714380, 0x218);
    }
    count = *(u32 *)base;
    func_0044ea90(D_00714380, 0x21E);
    alloc = (u8 *)(*jtbl_008873E8)(count * 0x34, 0x40000);
    for (i = 0; i < (s32)count; i++) {
        u8 *item = alloc + i * 0x34;
        func_004a8da0(base, item);
        *(f32 *)(item + 4) = fGpffff80f8;
    }
    return alloc;
}

// FUN_004AA660
void func_004aa660(void *param_1) {
    (*jtbl_008873EC)(param_1);
}

// FUN_004AA690
void func_004aa690(u8 *arg0) {
    f32 vec[4];
    s32 sp8C;
    s32 sp88;
    s32 sp84;
    u8 *obj;
    u8 *base;
    s32 b;
    s32 a;
    u8 *list;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 prod;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(s32 *)(base + 0x1C) = 0x43A00000;
            *(s32 *)(base + 0x20) = 0x43600000;
            *(f32 *)(base + 0x24) = f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            *(f32 *)(base + 0x24) = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 0x1C) = vec[0];
            *(f32 *)(base + 0x20) = vec[1];
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp8C = *(s32 *)(arg0 + 0x10);
        pt = &sp8C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp88 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $2, 0x437F        \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $2, $vf10    \n"
            "ppach $2, $0, $2      \n"
            "ppacb $2, $0, $2      \n"
            "sw $2, 0x84($sp)      \n"
            :
            : "r"(&sp88), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp84;
        *(f32 *)(base + 0x18) = fGpffff80f0 * func_0048aff0(obj + 0x34, b, a);
        *(f32 *)(base + 0x14) = fGpffff80f0 * func_0048aff0(obj + 0x60, b, a);
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
        func_004a8f90(base, list);
    } else {
        *(s32 *)(base + 0xC) = 0;
    }
}

// FUN_004AA890
void func_004aa890(u8 *arg0) {
    u8 *list;
    u8 *obj;
    u8 *base;
    s32 count;
    s32 *table;
    s32 i;

    list = *(u8 **)(arg0 + 0x20);
    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    if (*(s32 *)(obj + 0xCC) & 0xFF000000) {
        table = *(s32 **)(*(u8 **)(arg0 + 0x28) + 8);
        count = *(s32 *)base;
        if (!(count <= 0x64)) {
            func_0046d730(D_00714380, 0x269);
        }
        for (i = 0; i < count; i++) {
            if (*(s32 *)list == 0 && *(u8 *)(list + 0xF) > 0) {
                func_004a8890(list + 8, table);
            }
            list += 0x34;
        }
    }
}

// FUN_004AA960
void func_004aa960(u8 *arg0) {
    s32 sp3C;
    s32 sp38;
    s32 sp34;
    u8 *obj;
    u8 *base;
    s32 a;
    s32 b;
    s32 tmp;
    s32 *pt;
    f32 scale;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (b == 0) {
        *(s32 *)(base + 8) = 0;
        *(s32 *)(base + 0xC) = 0;
        *(s32 *)(base + 0x10) = 0x44200000;
        *(s32 *)(base + 0x14) = 0x43E00000;
        *(s32 *)(base + 4) = *(s32 *)(obj + 0x28);
    }
    if (a >= b) {
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp3C = *(s32 *)(arg0 + 0x10);
        pt = &sp3C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp38 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 0x34($sp)      \n"
            :
            : "r"(&sp38), "f"(scale)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)base = *(volatile s32 *)&sp34;
    } else {
        *(s8 *)(base + 3) = 0;
    }
}
// FUN_004AAA90
void func_004aaa90(u8 *arg0) {
    s32 sp12C;
    u8 sp20[0x108];
    u8 *base;

    base = *(u8 **)(arg0 + 0x24) + 0xC0;
    if (*(u8 *)(*(u8 **)(arg0 + 0x24) + 0xC3) > 0) {
        func_003f6690(3, &sp12C);
        func_004a86c0(base, sp20);
        D_00887300[0](1, 0);
        func_003f6440(3, 0x31001);
        D_00887314[0](3, sp20, 4, D_00714368, 6);
        func_003f6440(3, sp12C);
    }
}

// FUN_004AAB50
void func_004aab50(u8 *arg0) {
    f32 vec[4];
    s32 sp7C;
    s32 sp78;
    s32 sp74;
    u8 *base;
    u8 *obj;
    s32 b;
    s32 a;
    s32 tmp;
    s32 *pt;
    f32 scale;
    f32 f;
    f32 g;
    f32 prod;

    obj = *(u8 **)(arg0 + 0x24);
    base = obj + 0xC0;
    a = *(s32 *)(obj + 0xB8);
    if (a == 0) {
        b = 0;
    } else {
        b = *(s32 *)(arg0 + 0x1C);
    }
    if (a >= b) {
        f = func_0048aff0(obj + 0x8C, b, a);
        if (*(u8 *)(obj + 0xBC) != 0) {
            *(f32 *)(base + 4) = 320.0f;
            *(f32 *)(base + 8) = 224.0f;
            *(f32 *)(base + 0x14) = 320.0f - f;
            *(f32 *)(base + 0x18) = 224.0f - f;
            *(f32 *)(base + 0x1C) = 320.0f + f;
            *(f32 *)(base + 0x20) = 224.0f + f;
        } else {
            prod = f * *(f32 *)(arg0 + 0x14);
            __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0) : "$vf10", "memory");
            g = func_0048a650(prod);
            __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(vec) : "$vf10", "memory");
            *(f32 *)(base + 4) = vec[0];
            *(f32 *)(base + 8) = vec[1];
            *(f32 *)(base + 0x14) = vec[0] - g;
            *(f32 *)(base + 0x18) = vec[1] - g;
            *(f32 *)(base + 0x1C) = vec[0] + g;
            *(f32 *)(base + 0x20) = vec[1] + g;
        }
        tmp = func_0048abd0(obj, obj + 0x24, b, a);
        sp7C = *(s32 *)(arg0 + 0x10);
        pt = &sp7C;
        scale = fGpffff8044;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $2, %1           \n"
            "nop                   \n"
            "qmtc2.ni $2, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmove.xyzw $vf11, $vf10 \n"
            :
            : "r"(pt), "f"(scale)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp78 = tmp;
        __asm__ volatile(
            "lw $2, 0(%0)          \n"
            "pextlb $2, $0, $2     \n"
            "pextlh $2, $0, $2     \n"
            "qmtc2.ni $2, $vf10    \n"
            "vitof0.xyzw $vf10, $vf10 \n"
            "mfc1 $3, %1           \n"
            "nop                   \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vmul.xyzw $vf10, $vf10, $vf11 \n"
            "lui $3, 0x437F        \n"
            "qmtc2.ni $3, $vf2     \n"
            "vmulx.xyzw $vf10, $vf10, $vf2x \n"
            "vftoi0.xyzw $vf10, $vf10 \n"
            "qmfc2.ni $3, $vf10    \n"
            "ppach $3, $0, $3      \n"
            "ppacb $3, $0, $3      \n"
            "sw $3, 0x74($sp)      \n"
            :
            : "r"(&sp78), "f"(scale)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
                /* measured: the inline COP2 ppacb store writes this slot; mwcc b210
           hoists the reload above the asm, so the read is volatile. */
*(s32 *)(base + 0xC) = *(volatile s32 *)&sp74;
        *(s32 *)(base + 0x10) = *(s32 *)(obj + 0x28);
    } else {
        *(s8 *)(base + 0xF) = 0;
    }
}
// FUN_004AAD30
void func_004aad30(u8 *arg0) {
    s32 sp24C;
    s32 sp248;
    u8 sp140[0xFC];
    u8 sp40[0xF8];
    u8 *temp_16;
    u8 *temp_18;
    u8 *temp_3;
    void *setState;

    temp_3 = *(u8 **)(arg0 + 0x24);
    temp_18 = temp_3 + 0xC0;
    if (*(u8 *)(temp_3 + 0xCF) > 0) {
        temp_16 = *(u8 **)(*(u8 **)(arg0 + 0x28) + 8);
        func_003f6690(2, &sp24C);
        func_003f6690(3, &sp248);
        setState = (void *)D_00887300;
        (*(void (**)(u32, u32))setState)((u32)1, *(u32 *)temp_16);
        func_00489f80();
        func_003f6440(2, 0x44);
        func_003f6440(3, 0x31001);
        func_004a86c0(temp_18 + 0xC, sp140);
        *(s32 *)(sp140 + 0x10) = 0;
        *(s32 *)(sp140 + 0x14) = 0;
        *(s32 *)(sp140 + 0x50) = 0;
        *(s32 *)(sp140 + 0x54) = 0x3F800000;
        *(s32 *)(sp140 + 0x90) = 0x3F800000;
        *(s32 *)(sp140 + 0x94) = 0x3F800000;
        *(s32 *)(sp140 + 0xD0) = 0x3F800000;
        *(s32 *)(sp140 + 0xD4) = 0;
        temp_16 = (u8 *)D_00887314;
        (*(void (**)(s32, void *, s32, void *, s32))temp_16)(3, sp140, 4, D_00714368, 6);
        func_0048a000();
        func_003f6440(2, sp24C | 0x10);
        func_004a86c0(temp_18 + 0xC, sp40);
        (*((void (**)(u32, u32))setState))(1, 0);
        func_003f6440(3, 0x31001);
        (*(void (**)(s32, void *, s32, void *, s32))temp_16)(3, sp40, 4, D_00714368, 6);
        func_003f6440(3, sp248);
        func_003f6440(2, sp24C);
    }
}

/* measured: retail keeps arg0/$s5, arg1/$s4, hoists 0x60 into $s1 (temp_4
   via addu); mwcc b210 recompiled from equivalent C hoists the 0xFFFF mask
   into $s1/$s4 instead and rotates the saved registers (arg0 -> $s2, size/
   alloc swapped), nd 25 (14 rows). Tried 5 declaration orders, u16/u32 arg0,
   fn-pointer and mask temps, both assert cast forms - identical result.
   Saved-register rotation floor. */
/* measured: archived candidate body in build/BLUR_004aaee0_body.c; object 372B/window 384B, normalized_diff 42. COP2 sqc2 is retained in the archive only; live source is restored to the bare retail include. */
// FUN_004AAEE0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004aaee0);
/* measured: re-measured this wave at nd 4 (2 rows) with a full candidate
   body (separate obj/obj2 locals; rest of function byte-identical). The
   only residual is the pre-jal arg-materialisation order: retail emits
   `daddu $a0,$v0` (bare local) before `lhu $a1,0x1c($s1)` (load); mwcc
   b210 always emits the load first — its complexity rule materialises
   loaded/computed args early, bare locals late. Tried 8 prior spellings
   plus this wave: load hoisted into a local pre-call, load before the
   if-block (nd 24), obj2-first declaration order, s32 obj2 + cast,
   nested-if, #pragma schedule on (nd 46) — all nd 4. Same shape as the
   documented bpc 00245420 floor (retail move-before-load). */
// FUN_004AB060
u8 *func_004ab060(u8 *arg0) {
    s32 temp_2_2;
    s32 temp_2_3;
    u8 *temp_2;

    temp_2_2 = (s32)func_00484490();
    if (temp_2_2 == 0) {
        func_0046d730(D_00714380, 0x660);
    }
    temp_2 = (u8 *)func_004aaee0(*(u16 *)(arg0 + 0xC), temp_2_2);
    if (temp_2 == 0) {
        func_0046d730(D_00714380, 0x662);
    }
    temp_2_3 = (s32)func_004844d0(arg0);
    if ((temp_2_3 != 0) && (*(s8 *)(D_007143A0 + *(s32 *)(temp_2 + 0x18) * 24) != 0)) {
        *(s32 *)(temp_2 + 0x28) = (s32)func_004ab960((u16 *)temp_2_3, *(u16 *)(arg0 + 0x1C));
    }
    return temp_2;
}

// FUN_004AB5A0
u8 *func_004ab5a0(void *param_1) {
    u8 *tmp;
    u16 *tex;

    tmp = (u8 *)func_00484490();
    if (tmp == 0) {
        func_0046d730(D_00714380, 0x72B);
    }
    tmp = func_004ab420(*(u16 *)((char *)param_1 + 0xC), (s32)tmp);
    if (tmp == 0) {
        func_0046d730(D_00714380, 0x72D);
    }
    tex = func_004844d0(param_1);
    if ((tex != 0) && (*(s8 *)(D_00714470 + *(s32 *)(tmp + 0x18) * 24) != 0)) {
        *(s32 *)(tmp + 0x28) = (s32)func_004ab960(tex, *(u16 *)((char *)param_1 + 0x1C));
    }
    return tmp;
}

// FUN_004AB140
void func_004ab140(void *param_1) {
    if (*(void **)((char *)param_1 + 0x20) != 0) {
        ((void (*)(void *))(*(u32 *)(D_00714394 + *(s32 *)((char *)param_1 + 0x18) * 24)))(*(void **)((char *)param_1 + 0x20));
    }
    if (*(void **)((char *)param_1 + 0x28) != 0) {
        func_004aba70(*(void **)((char *)param_1 + 0x28));
    }
    (*jtbl_008873EC)(param_1);
}

// FUN_004AB1C0
u8 *func_004ab1c0(void *param_1) {
    u8 *tmp;

    tmp = func_004aaee0(*(u16 *)((char *)param_1 + 0x18), *(s32 *)((char *)param_1 + 0x24));
    if ((*(void **)((char *)param_1 + 0x28) != 0) && (*(s8 *)(D_007143A0 + *(s32 *)(tmp + 0x18) * 24) != 0)) {
        *(s32 *)(tmp + 0x28) = (s32)func_004abb00(*(void **)((char *)param_1 + 0x28));
    }
    return tmp;
}

// FUN_004AB250
void func_004ab250(void *param_1) {
    *(s32 *)((char *)param_1 + 0x1C) = 0;
}

// FUN_004AB260
void func_004ab260(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_00714398 + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x1C) += 1;
}

// FUN_004AB2C0
void func_004ab2c0(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071439C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
}

// FUN_004AB300
void func_004ab300(u8 *param_1) {
    u8 *p;
    if (*(s32 *)(param_1 + 0x1C) > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
// FUN_004AB360
void func_004ab360(u8 *param_1) {
    s32 count;
    u8 *p;
    ((void (*)(void *))(*(u32 *)(D_00714398 + *(s32 *)(param_1 + 0x18) * 24)))(param_1);
    count = *(s32 *)(param_1 + 0x1C) + 1;
    *(s32 *)(param_1 + 0x1C) = count;
    if (count > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
typedef signed __int128 s128;

// FUN_004AB3F0
s128 func_004ab3f0(void *param_1, const void *param_2) {
    s128 temp = *(const s128 *)param_2;
    *(s128 *)param_1 = temp;
    return temp;
}

// FUN_004AB400
void func_004ab400(void *param_1, s32 param_2) {
    *(s32 *)((char *)param_1 + 0x10) = param_2;
}

// FUN_004AB410
void func_004ab410(void *param_1, f32 param_2) {
    *(f32 *)((char *)param_1 + 0x14) = param_2;
}

/* measured: re-measured this wave at nd 6 (3 rows) — matches the recorded
   floor exactly with a new best spelling. Two new insights got here from
   nd 32: (1) writing the assert as `(u32)size + 0x60 >= 0x200U` (u32 add)
   stops mwcc CSE-ing size+0x60 into a saved register across the two jals
   (the CSE shifted the whole allocation); (2) declaring alloc BEFORE size
   fixes the s2/s3 swap. Residual is one constant-cache choice: retail
   hoists 0x60 into $s1 (used once as `addu $a0,$s3,$s1` at the data site,
   immediates at the other 3 sites), mwcc b210 hoists 0xFFFF instead and
   emits `and $v1,$s5,$s1` at the second mask (retail `andi $v1,$s5,0xffff`)
   plus `addiu $a0,$s3,0x60` at the data site. Tried: u16/s32/u32 arg0,
   `s32 off = 0x60` variable (4-site and 2-site, both nd 89 — register
   pressure), modulo mask, decl orders — identical 3 rows. Constant-cache
   floor, same family as func_004aaee0. */
// FUN_004AB420 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/effBlurFilter", func_004ab420);
// FUN_004AB680
void func_004ab680(void *param_1) {
    if (*(void **)((char *)param_1 + 0x20) != 0) {
        ((void (*)(void *))(*(u32 *)(D_00714464 + *(s32 *)((char *)param_1 + 0x18) * 24)))(*(void **)((char *)param_1 + 0x20));
    }
    if (*(void **)((char *)param_1 + 0x28) != 0) {
        func_004aba70(*(void **)((char *)param_1 + 0x28));
    }
    (*jtbl_008873EC)(param_1);
}

// FUN_004AB700
u8 *func_004ab700(void *param_1) {
    u8 *tmp;

    tmp = func_004ab420(*(u16 *)((char *)param_1 + 0x18), *(s32 *)((char *)param_1 + 0x24));
    if ((*(void **)((char *)param_1 + 0x28) != 0) && (*(s8 *)(D_00714470 + *(s32 *)(tmp + 0x18) * 24) != 0)) {
        *(s32 *)(tmp + 0x28) = (s32)func_004abb00(*(void **)((char *)param_1 + 0x28));
    }
    return tmp;
}

// FUN_004AB790
void func_004ab790(void *param_1) {
    *(s32 *)((char *)param_1 + 0x1C) = 0;
}

// FUN_004AB7A0
void func_004ab7a0(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_00714468 + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x1C) += 1;
}

// FUN_004AB800
void func_004ab800(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071446C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
}

// FUN_004AB840
void func_004ab840(u8 *param_1) {
    u8 *p;
    if (*(s32 *)(param_1 + 0x1C) > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
// FUN_004AB8A0
void func_004ab8a0(u8 *param_1) {
    s32 count;
    u8 *p;
    ((void (*)(void *))(*(u32 *)(D_00714468 + *(s32 *)(param_1 + 0x18) * 24)))(param_1);
    count = *(s32 *)(param_1 + 0x1C) + 1;
    *(s32 *)(param_1 + 0x1C) = count;
    if (count > 0) {
        p = *(u8 **)(param_1 + 0x24);
        *(s32 *)(param_1 + 0x2C) = 0;
        *(s32 *)(param_1 + 0x30) = 0;
        func_00460ac0(func_004814d0(*(u16 *)(p + 0x28)), param_1 + 0x2C);
    }
}
// FUN_004AB930
s128 func_004ab930(void *param_1, const void *param_2) {
    s128 temp = *(const s128 *)param_2;
    *(s128 *)param_1 = temp;
    return temp;
}

// FUN_004AB940
void func_004ab940(void *param_1, s32 param_2) {
    *(s32 *)((char *)param_1 + 0x10) = param_2;
}

// FUN_004AB950
void func_004ab950(void *param_1, f32 param_2) {
    *(f32 *)((char *)param_1 + 0x14) = param_2;
}

// FUN_004AB960
u8 *func_004ab960(u16 *arg0, u16 arg1) {
    u8 *tmp;
    s32 t;

    func_0044ea90(D_00714450, 0x171);
    tmp = (u8 *)(*jtbl_008873E8)(0xC, 0x40000);
    func_0043f9c8(tmp, 0, 0xC);
    if (tmp == 0) {
        func_0046d730(D_00714380, 0x7B0);
    }
    t = arg1 & 0xFFFF;
    *(s32 *)(tmp + 0) = t;
    *(s32 *)(tmp + 4) = 1;
    switch (t) {
    case 1:
        *(s32 *)(tmp + 8) = func_00481390(arg0);
        break;
    case 4:
        *(s32 *)(tmp + 8) = func_00481300(*arg0);
        break;
    default:
        func_0046d730(D_00714380, 0x7BC);
        break;
    }
    return tmp;
}

// FUN_004ABA70
void func_004aba70(void *param_1) {
    s32 n;

    if (*(s32 *)((char *)param_1 + 4) == 0) {
        func_0046d730(D_00714380, 0x7C5);
    }
    n = *(s32 *)((char *)param_1 + 4) - 1;
    *(s32 *)((char *)param_1 + 4) = n;
    if (n == 0) {
        if (*(s32 *)((char *)param_1 + 0) != 4) {
            func_003ef3a0(*(void **)((char *)param_1 + 8));
        }
        (*jtbl_008873EC)(param_1);
    }
}

// FUN_004ABB00
void *func_004abb00(BlurRefObj *param_1) {
    if (param_1->f4 == 0) {
        func_0046d730(D_00714380, 0x7D7);
    }
    param_1->f4 += 1;
    return param_1;
}


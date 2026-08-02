#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit evtPolygonMovie.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef signed __int128 s128;

typedef struct {
    s128 a;
    s128 b;
} s2x128;

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern void func_002852a0(s32 arg0, s32 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_002909a0(s32 arg0);
extern void func_00290940(s32 arg0);
extern void func_00442088();
extern void func_0026c770(f32 *param_1, f32 *param_2, f32 *param_3);
extern void func_0026c680(f32 *param_1);
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern u8 D_00748340[];
extern u8 D_0063C6A0[];
extern u8 D_0063C7A0[];
extern u8 D_0063C7C0[];
extern u8 D_0063C7E0[];
extern u8 D_0063C800[];
extern void (*jtbl_008873EC[])(void *ptr);
extern s128 D_0063C700;
extern s128 D_0063C710;
extern s128 D_0063C720[];
extern s128 D_0063C780;
extern s128 D_0063C790;

/* Without opt_loop_invariants the two lerp loops allocate the s2 value into
   $f0 (sub.s $f1,$f0,$f2, mtc1 $0,$f0 re-materialized inside the loop, madd.s
   result in $f0) vs retail's $f1 with the mtc1 hoisted to the preheader;
   expression variants (temps, product-first, (int)-cast addressing) never
   moved the allocation. measured: pragma on nd ~110 -> 0. */
#pragma opt_loop_invariants on

// FUN_0028F990
void func_0028f990(s32 arg0, f32 fparg0, f32 *arg1, f32 *arg2, f32 *arg3)
{
    f32 sp90[4];
    f32 sp80[4];
    f32 sp70[4];
    f32 sp60[4];
    f32 *var_16;
    f32 *var_18;

    var_18 = arg1;
    var_16 = arg3;
    if (var_16 == NULL) {
        func_0046d730(D_0063C6A0, 0x8F);
    }
    if (arg0 == 0) {
        fparg0 = 0.0f;
    }
    if (var_18 != NULL) {
        if (arg2 == NULL) {
            s32 var_5 = 6;

            do {
                s32 temp_4 = *(s32 *)var_18;
                s32 temp_3 = *(s32 *)(var_18 + 1);

                var_18 += 2;
                var_5 -= 1;
                *(s32 *)var_16 = temp_4;
                *(s32 *)(var_16 + 1) = temp_3;
                var_16 += 2;
            } while (var_5 > 0);
            return;
        }
        {
            s32 var_4;

            for (var_4 = 0; var_4 < 4; var_4++) {
                var_16[var_4 + 8] = var_18[var_4 + 8] + fparg0 * (arg2[var_4 + 8] - var_18[var_4 + 8]);
            }
        }
        {
            s32 var_4_2;

            for (var_4_2 = 0; var_4_2 < 4; var_4_2++) {
                var_16[var_4_2] = var_18[var_4_2] + fparg0 * (arg2[var_4_2] - var_18[var_4_2]);
            }
        }
        sp90[0] = var_18[4];
        sp90[1] = var_18[5];
        sp90[2] = var_18[6];
        sp80[0] = arg2[4];
        sp80[1] = arg2[5];
        sp80[2] = arg2[6];
        func_0026c770(&sp90[0], &sp80[0], &sp70[0]);
        sp60[0] = sp70[0] * fparg0 + var_18[4];
        sp60[1] = sp70[1] * fparg0 + var_18[5];
        sp60[2] = sp70[2] * fparg0 + var_18[6];
        func_0026c680(&sp60[0]);
        var_16[4] = sp60[0];
        var_16[5] = sp60[1];
        var_16[6] = sp60[2];
    }
}
#pragma opt_loop_invariants off

// FUN_0028FB90
u8 *func_0028fb90(void)
{
    u8 *work;

    func_0044ea90(D_00748340, 0x52);
    work = D_008873F4[0](1, 0x114, 0x40000);
    func_002852a0(1, 0x114);
    if (work == NULL) {
        func_0046d730(D_0063C6A0, 0x12D);
        return NULL;
    }
    func_0043f9c8(work, 0, 0x114);
    return work;
}

// FUN_0028FC40
INCLUDE_ASM("asm/nonmatchings/evtPolygonMovie", func_0028fc40);

// FUN_00290470
void func_00290470(s32 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        if (func_002909a0(arg1) == 1) {
            func_00290940(arg1);
        }
        jtbl_008873EC[0](arg0);
        func_002852a0(1, -0x114);
    }
}

// FUN_002904F0
s32 *func_002904f0(s32 **arg0)
{
    s2x128 sp30;
    s32 *temp;

    sp30 = *(s2x128 *)&D_0063C700;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    func_002852a0(4, 0x20);
    func_0043f810(temp, &sp30, 0x20);
    *arg0 = temp;
    return temp;
}

// FUN_002905A0
s32 *func_002905a0(s32 **arg0)
{
    u8 sp30[0x54];
    s128 *src;
    s128 *dst;
    s32 count;
    s32 *temp;

    src = &D_0063C720[0];
    dst = (s128 *)&sp30[0];
    count = 5;
    do {
        s128 temp;

        temp = *src;
        src++;
        count--;
        *dst = temp;
        dst++;
    } while (count > 0);
    *(f32 *)dst = *(f32 *)src;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x54, 0x40000);
    func_002852a0(5, 0x54);
    func_0043f810(temp, &sp30[0], 0x54);
    *arg0 = temp;
    return temp;
}

// FUN_00290660
s32 *func_00290660(s32 **arg0)
{
    s2x128 sp30;
    s32 *temp;

    sp30 = *(s2x128 *)&D_0063C780;
    func_0044ea90(D_00748340, 0x52);
    temp = (s32 *)D_008873F4[0](1, 0x20, 0x40000);
    func_002852a0(6, 0x20);
    func_0043f810(temp, &sp30, 0x20);
    *arg0 = temp;
    return temp;
}

// FUN_00290710
void func_00290710(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5)
{
    s32 temp;

    if (arg2 == 0) {
        func_0046d730(D_0063C6A0, 0x36B);
    }
    if (arg3 == 0) {
        func_0046d730(D_0063C6A0, 0x36C);
    }
    if (arg4 == 0) {
        func_0046d730(D_0063C6A0, 0x36D);
    }
    if (arg5 == 0) {
        func_0046d730(D_0063C6A0, 0x36E);
    }
    temp = (arg0 / 10) * 10;
    func_00442088(arg2, D_0063C7A0, temp, arg0, arg1);
    func_00442088(arg3, D_0063C7C0, temp, arg0, arg1);
    func_00442088(arg4, D_0063C7E0, temp, arg0, arg1);
    func_00442088(arg5, D_0063C800, temp, arg0, arg1);
}

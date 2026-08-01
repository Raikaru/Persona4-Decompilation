/* Whole-file translation unit: src/Camp/cmpSystem.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"

extern char D_005E57F0[];
extern char D_005E5810[];
extern char D_005E5830[];
extern char D_005E5850[];
extern u8 D_0064A790[];
extern u8 D_0064D460[];
extern u8 D_0064D6B0[];
extern u8 D_0064D900[];
extern u8 D_0064DB50[];
extern u8 D_0064DDA0[];
extern u8 D_0064DFF0[];
extern u8 D_0064E240[];
extern char D_0064E270[];

s8 func_002bab80(void *);
s32 func_003544f0(void);
void func_0043f9c8(void *, s32, s32);
void *func_0046a770(char *);
s32 func_0046d200(void *, u8);
void func_0046d730(char *, s32);
s32 func_0035fa20(u8 *, u32);

// FUN_0035F5B0
/* measured: removing this regresses func_0035f5b0 from nd 0 to nd 118
   (loop-invariant hoisting of the D_0064D6B0 base and the store-constant
   3 is required for the retail layout). */
#pragma opt_loop_invariants on
void func_0035f5b0(u8 *arg0)
{
    void *spr2;
    void *spr1;
    void *spr3;
    void *spr4;
    s32 *slot;
    s16 i4;
    s16 i1;
    s16 i3;
    s16 i2;
    s16 i5;
    u8 byte;
    u8 *p;
    u8 *src;

    func_0043f9c8(arg0, 0, 0x708);
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(u8 *)arg0 = 0xFF;
    *(s32 *)(arg0 + 0x18) = -1;
    *(s32 *)(arg0 + 0x14) = 0;
    for (i1 = 0; i1 < 3; i1++) {
        *(s16 *)(arg0 + i1 * 2 + 0x28) = 0;
    }
    *(f32 *)(arg0 + 0x40) = 0x12F;
    *(s32 *)(arg0 + 0x44) = 0x43050000;
    for (i2 = 0; i2 < 0x1D; i2++) {
        src = &D_0064D6B0[i2 * 0x14];
        p = arg0 + i2 * 0x30;
        *(f32 *)(p + 0x58) = *(f32 *)(src + 0);
        *(f32 *)(p + 0x5C) = *(f32 *)(src + 4);
        *(u8 *)(p + 0x62) = *(u8 *)(src + 8);
    }
    for (i3 = 0; i3 <= 0; i3++) {
        p = arg0 + (s32)(s64)i3 * 0x30;
        *(s32 *)(p + 0x5C8) = 0;
        *(s32 *)(p + 0x5B8) = 0;
        *(s32 *)(p + 0x5C4) = 0;
        *(s32 *)(p + 0x5BC) = 0;
        *(u8 *)(p + 0x5D1) = 0;
        *(u8 *)(p + 0x5D0) = 0;
        *(s32 *)(p + 0x5E0) = 0;
        *(s32 *)(p + 0x5E4) = 3;
    }
    spr2 = func_0046a770(D_005E5830);
    if (spr2 == NULL) {
        func_0046d730(D_0064E270, 0x15B);
    }
    spr1 = func_0046a770(D_005E5850);
    if (spr1 == NULL) {
        func_0046d730(D_0064E270, 0x15D);
    }
    *(s32 *)(arg0 + 0x700) = (s32)(spr3 = func_0046a770(D_005E57F0));
    if (spr3 == NULL) {
        func_0046d730(D_0064E270, 0x15F);
    }
    spr4 = func_0046a770(D_005E5810);
    if (spr4 == NULL) {
        func_0046d730(D_0064E270, 0x161);
    }
    for (i4 = 0; i4 < 0x2A; i4++) {
        if (i4 < 0x25) {
            slot = (s32 *)(arg0 + i4 * 4 + 0x658);
            byte = D_0064E240[i4];
            *slot = func_0046d200(spr1, byte);
        } else if (i4 < 0x28) {
            slot = (s32 *)(arg0 + i4 * 4 + 0x658);
            byte = D_0064E240[i4];
            *slot = func_0046d200(spr2, byte);
        } else if (i4 < 0x29) {
            slot = (s32 *)(arg0 + i4 * 4 + 0x658);
            byte = D_0064E240[i4];
            *slot = func_0046d200(spr3, byte);
        } else {
            slot = (s32 *)(arg0 + i4 * 4 + 0x658);
            byte = D_0064E240[i4];
            *slot = func_0046d200(spr4, byte);
        }
        if (*slot == 0) {
            func_0046d730(D_0064E270, 0x171);
        }
    }
    *(u8 *)(arg0 + 0x3C) = func_002bab80(&D_0064A790[0]);
    for (i5 = 0; i5 < 0xB; i5++) {
        p = arg0 + (s32)(s64)i5 * 0xA;
        *(s16 *)(p + 0x5E8) = 1;
        *(s16 *)(p + 0x5EE) = 1;
    }
    *(s16 *)(arg0 + 0x22) = 0;
    *(s16 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x38) = func_003544f0();
    func_0035fa20(arg0, 0);
}
/* measured: see the annotation above the matching `on` pragma (func_0035f5b0). */
#pragma opt_loop_invariants off

// FUN_0035FA00
s32 func_0035fa00(s32 arg0, s32 arg1, s16 arg2)
{
    u8 *temp_3;
    s32 var_4;

    var_4 = arg1 * 2;
    temp_3 = (u8 *)(var_4 + arg0);
    *(s16 *)(temp_3 + 0x2E) = *(s16 *)(temp_3 + 0x28);
    *(s16 *)(temp_3 + 0x28) = arg2;
    return 1;
}

// FUN_0035FA20
s32 func_0035fa20(u8 *arg0, u32 arg1)
{
    u8 *var_16;
    s32 var_4;
    s32 var_5;
    u8 *temp_3;
    u8 *temp_4;

    var_16 = NULL;
    if (*(u32 *)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (var_4 = 0; var_4 < 0x1D; var_4++) {
        temp_3 = arg0 + var_4 * 0x30;
        *(f32 *)(temp_3 + 0x48) = *(f32 *)(temp_3 + 0x58);
        *(f32 *)(temp_3 + 0x4C) = *(f32 *)(temp_3 + 0x5C);
        *(u8 *)(temp_3 + 0x60) = *(u8 *)(temp_3 + 0x62);
    }
    switch (arg1) {
    case 0:
        var_16 = &D_0064D460[0];
        *(s32 *)(arg0 + 0x1C) = 3;
        *(s16 *)(arg0 + 0x34) = 0;
        break;
    case 1:
        var_16 = &D_0064D6B0[0];
        *(s32 *)(arg0 + 0x1C) = 3;
        *(s16 *)(arg0 + 0x34) = 0;
        break;
    case 2:
        var_16 = &D_0064D900[0];
        *(s32 *)(arg0 + 0x1C) = 3;
        *(s16 *)(arg0 + 0x34) = 0;
        break;
    case 3:
        var_16 = &D_0064DB50[0];
        *(s32 *)(arg0 + 0x1C) = 0xC;
        *(s16 *)(arg0 + 0x34) = 0xF;
        func_0043f9c8(arg0 + 0x5E8, 0, 0x6E);
        break;
    case 4:
        var_16 = &D_0064DDA0[0];
        *(s32 *)(arg0 + 0x1C) = 0xC;
        *(s16 *)(arg0 + 0x34) = 0xF;
        break;
    case 5:
        var_16 = &D_0064DFF0[0];
        *(s32 *)(arg0 + 0x1C) = 0xC;
        *(s16 *)(arg0 + 0x34) = 0xF;
        break;
    default:
        func_0046d730(D_0064E270, 0x1CF);
        break;
    }
    if (var_16 != NULL) {
        for (var_5 = 0; var_5 < 0x1D; var_5++) {
            temp_4 = var_16 + var_5 * 0x14;
            temp_3 = arg0 + var_5 * 0x30;
            *(f32 *)(temp_3 + 0x50) = *(f32 *)(temp_4 + 0);
            *(f32 *)(temp_3 + 0x54) = *(f32 *)(temp_4 + 4);
            *(u8 *)(temp_3 + 0x61) = *(u8 *)(temp_4 + 8);
            *(s32 *)(temp_3 + 0x70) = *(s32 *)(temp_4 + 0xC);
            *(s32 *)(temp_3 + 0x74) = *(s32 *)(temp_4 + 0x10);
        }
        *(u32 *)(arg0 + 0x18) = arg1;
        *(s16 *)(arg0 + 0x20) = 0;
    }
    return 1;
}

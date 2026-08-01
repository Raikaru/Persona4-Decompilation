/* Whole-file translation unit: src/Main/init.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"

extern void func_00440b68(...);
extern void func_0043f810(void *dest, const void *src, u32 size);
extern void *func_00454a60(const char *path, s32 flags);
extern void func_00454bd0(void *handle);
extern s32 func_004553c0(void *handle);
extern s32 func_00451de0();
extern void func_0044ea90(const void *file, u32 line);
extern void func_00104c50(void);
extern s32 func_00123730(s32);
extern void func_002aaa80(void);
extern void func_002aaaa0(void);
extern s32 func_004522d0(s32);
extern s32 func_0045a890();
extern void func_001029a0(s32, s32, s32, s32);
extern void func_001113b0(void);
extern void (*jtbl_008873EC[])(u8 *);
extern void *(*D_008873F4[])(s32, s32, u32);
extern char D_00762CB8;
extern char D_00762CC0;
extern char D_005E46A0[];
extern char D_005E46C0[];
extern char D_005E46D0[];
extern char D_005E46E8[];
extern u8 D_0079BF00[];

// FUN_001117C0
s32 func_001117c0(u8 *arg0)
{
    u8 *temp_16;
    s32 temp_3;
    u8 *temp_2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_3 = *(s32 *)temp_16;
    switch (temp_3) {
    case 0:
        func_00440b68(&D_00762CB8, &D_00762CC0, 0x1FA);
        *(u8 **)(temp_16 + 4) = func_00454a60(D_005E46A0, 0);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        if (func_004553c0(*(u8 **)(temp_16 + 4)) == 1) {
            temp_2 = *(u8 **)(temp_16 + 4);
            func_0043f810(&D_0079BF00, *(u8 **)(temp_2 + 0x110), *(s32 *)(temp_2 + 0x118));
            func_00454bd0(*(u8 **)(temp_16 + 4));
            *(u8 **)(temp_16 + 4) = NULL;
            func_00104c50();
            return -1;
        }
        break;
    }
    return 0;
}

// FUN_001118A0
void func_001118a0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_00454bd0(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

// FUN_001118F0
s32 func_001118f0(void)
{
    s32 temp_2;
    s32 var_2;

    func_0044ea90(&D_00762CC0, 0x21E);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    var_2 = func_00451de0(D_005E46C0, 0x100, 0, 0, func_001117c0, func_001118a0, temp_2);
    return var_2 == 0 ? 0 : var_2;
}

// FUN_00111990
s32 func_00111990(u8 *arg0)
{
    typedef s32 (*StepCallback)(void);
    StepCallback callbacks[8];
    u32 *var_7;
    u32 *var_6;
    s32 var_5;
    s32 temp_3_2;
    s32 temp_3;
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    var_7 = (u32 *)D_005E46D0;
    var_6 = (u32 *)callbacks;
    var_5 = 3;
    do {
        temp_3 = var_7[0];
        temp_2 = var_7[1];
        var_7 += 2;
        var_5 -= 1;
        var_6[0] = temp_3;
        var_6[1] = temp_2;
        var_6 += 2;
    } while (var_5 > 0);
    temp_3_2 = *(s32 *)temp_16;
    switch (temp_3_2) {
    case 0:
        if ((func_0045a890(0, var_5, var_6, var_7) != 0) && (func_0045a890(1) != 0)) {
            *(s32 *)(temp_16 + 4) = 0;
            *(s32 *)temp_16 = 1;
            func_002aaa80();
        }
        break;
    case 1:
        if (callbacks[*(s32 *)(temp_16 + 4)] == NULL) {
            func_002aaaa0();
            func_00123730(0);
            return -1;
        }
        *(s32 *)(temp_16 + 8) = (s32)callbacks[*(s32 *)(temp_16 + 4)]();
        *(s32 *)temp_16 = 2;
        break;
    case 2:
        if (func_004522d0(*(s32 *)(temp_16 + 8)) == 3) {
            *(s32 *)(temp_16 + 4) += 1;
            *(s32 *)temp_16 = 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

// FUN_00111AE0
void func_00111ae0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
    func_001113b0();
    func_001029a0(0x1B, 0, 0, 5);
}

// FUN_00111B30
s32 func_00111b30(void)
{
    s32 temp_2;

    func_0044ea90(&D_00762CC0, 0x288);
    temp_2 = (s32)D_008873F4[0](1, 0xC, 0x40000);
    if (temp_2 == 0) {
        return 0;
    }
    return func_00451de0(D_005E46E8, 0x100, 0, 0, func_00111990, func_00111ae0, temp_2);
}

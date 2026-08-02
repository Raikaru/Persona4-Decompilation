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
extern void func_0025ecd0(s32, s32, s32, s32, s32, s32, s32, void *, f32, f32, f32, f32, f32, f32);
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
extern void func_00186ac0();
extern void func_00186eb0();
extern void func_00188be0();
extern void func_001891d0();
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
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_001866d0);

// FUN_00186A60
void func_00186a60(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    *(s32 *)(*(u8 **)(temp_4 + 8) + 4) = 1;
    func_00454bd0(*(u8 **)(temp_4 + 4));
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

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
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00186e10);

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
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00187f50);

// FUN_00188030
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188030);

// FUN_00188110
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188110);

// FUN_00188200
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188200);

// FUN_00188320
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188320);

// FUN_00188590
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188590);

// FUN_00188690
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188690);

// FUN_001887F0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_001887f0);

// FUN_00188940
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188940);

// FUN_00188BE0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00188be0);

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

// FUN_00189060
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_00189060);

// FUN_001891D0
INCLUDE_ASM("asm/nonmatchings/k_fldLmap", func_001891d0);

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

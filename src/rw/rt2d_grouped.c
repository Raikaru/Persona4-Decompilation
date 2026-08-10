/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"

/* Canonical grouped function declarations. */
void func_003d5830(u8 *value);
void func_003d5990(s32 object, u32 first, u32 second);
u32 func_003d60e0(u32 object, u32 value);
u32 func_003d7b30(u32 value);

extern s32 func_003df8a0(s32 value);
extern s32 *func_003df890(s32 value);
extern void func_003df7f0(s32 value);
extern void func_003e0f40(s32 value);
extern s32 func_003e1220(s32, s32, s32, s32, s32, s32);
extern s32 func_003e2910(s32, void *, s32);
extern s32 func_003df360(s32, void *, s32);
extern void func_003d6010(u8 *value);
extern void func_003d5000(u8 *value);
extern void func_003d5fb0(u8 *value);
extern void func_003e12f0(s32 value);
extern u8 *func_003d6c10(u8 *dst, u8 *src);
extern u8 *func_003e05d0(u8 *value);
extern u8 *func_003d6fb0(u8 *dst, u8 *src);
extern void *(*D_008873F8[])(s32, s32);
extern s32 (*D_008873C8[])(s32, s32);
extern s32 D_0070B650[];
extern s32 D_0070B680[];
extern u8 D_0070B610[];
extern s32 D_0072483C;
extern s32 iGpffffb744;
extern s32 iGpffffb748;
extern s32 iGpffffab24;
extern s32 iGpffffab28;
extern s32 func_003d70c0(s32 value);
extern s32 func_003d7150(s32 value);
extern s32 func_003d7260(s32 value);
extern s32 func_003d72a0(s32 value);
extern s32 func_003d7350(s32 value, s32 arg1);
extern s32 func_003d77f0(s32 value, s32 arg1);
extern s32 func_003d75b0(s32 value, s32 arg1);
extern s32 func_003d79b0(s32 value);
extern s32 func_003d8150(void);
extern s32 func_003e8930(s32, s32, s32 (*)(s32), s32 (*)(s32));
extern s32 func_003c4310(s32, s32, s32 (*)(s32), s32 (*)(s32), s32 (*)(s32, s32));
extern s32 func_003c4340(s32, s32 (*)(s32, s32), s32 (*)(s32, s32), s32 (*)(s32));
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern void func_003d7c50(void *value);
extern void *func_003d7a20(s32 value);

/* Source unit: src/rw/rt2d_003d5830.c (1 function markers) */

extern void (*DAT_008873ec_abs[])(void);

/* measured: optimization_level 3 probe for func_003d5830. */
#pragma optimization_level 3
// FUN_003D5830
void func_003d5830(u8 *value)
{
    DAT_008873ec_abs[0]();
}
/* measured: close optimization_level 3 for func_003d5830. */
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d5990.c (1 function markers) */

// FUN_003D5840
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d5840);
/* measured: optimization_level 3 probe for func_003d5990. */
#pragma optimization_level 3
// FUN_003D5990
void func_003d5990(s32 object, u32 first, u32 second)
{
    *(u32*)(object + 0x18) = first;
    *(u32*)(object + 0x1c) = second;
}
/* measured: close optimization_level 3 for func_003d5990. */
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d60e0.c (1 function markers) */

/* measured: schedule on probe for func_003d60e0. */
#pragma schedule on
// FUN_003D60E0
u32 func_003d60e0(u32 object, u32 value)
{
    *(u32 *)(object + 0x14) = value;
    return object;
}
/* measured: close schedule on for func_003d60e0. */
#pragma schedule off

/* Source unit: src/rw/rt2d_003d7b30.c (1 function markers) */

// FUN_003D60F0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d60f0);
// FUN_003D6170
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6170);
// FUN_003D6230
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6230);
// FUN_003D6350
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6350);
// FUN_003D65E0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d65e0);
// FUN_003D6680
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6680);
// FUN_003D6790
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6790);
// FUN_003D68B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d68b0);
/* measured: optimization_level 3 probe for func_003d6900 and func_003d6b70. */
#pragma optimization_level 3
// FUN_003D6900
/* measured: tailcall on reproduces the retail direct jump to func_003e05d0. */
#pragma tailcall on
/* measured: schedule on probe for func_003d6900 tail delay. */
#pragma schedule on
void func_003d6900(u8 *arg0, u8 *arg1)
{
    *(f32 *)(arg0 + 0) = *(f32 *)(arg1 + 8);
    *(f32 *)(arg0 + 4) = *(f32 *)(arg1 + 0xC);
    *(s32 *)(arg0 + 8) = 0;
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg1 + 0x10);
    *(f32 *)(arg0 + 0x14) = *(f32 *)(arg1 + 0x14);
    *(s32 *)(arg0 + 0x18) = 0;
    *(s32 *)(arg0 + 0x20) = 0;
    *(s32 *)(arg0 + 0x24) = 0;
    *(s32 *)(arg0 + 0x28) = 0;
    *(f32 *)(arg0 + 0x30) = *(f32 *)(arg1 + 0x18);
    *(f32 *)(arg0 + 0x34) = *(f32 *)(arg1 + 0x1C);
    func_003e05d0((u8 *)((*(s32 *)(arg0 + 0x38) = 0), arg0));
}
/* measured: close schedule on for func_003d6900. */
#pragma schedule off
/* measured: close tailcall for func_003d6900. */
#pragma tailcall off
/* measured: close optimization_level 3 for func_003d6900. */
#pragma optimization_level 2
// FUN_003D6950
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6950);
// FUN_003D6A00
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6a00);
// FUN_003D6AA0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6aa0);
/* measured: optimization_level 3 probe for func_003d6b70. */
#pragma optimization_level 3
/* measured: schedule on probe for func_003d6b70 load order. */
#pragma schedule on
// FUN_003D6B70
void func_003d6b70(u8 *arg0, u8 *arg1, u8 *arg2)
{
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    a = *(f32 *)(arg1 + 0xC);
    b = *(f32 *)(arg2 + 0x10);
    c = *(f32 *)(arg1 + 8);
    d = *(f32 *)(arg2 + 8);
    *(f32 *)(arg0 + 8) = c * d + a * b;
    *(f32 *)(arg0 + 0xC) =
        *(f32 *)(arg1 + 8) * *(f32 *)(arg2 + 0xC) +
        *(f32 *)(arg1 + 0xC) * *(f32 *)(arg2 + 0x14);
    *(f32 *)(arg0 + 0x10) =
        *(f32 *)(arg1 + 0x10) * *(f32 *)(arg2 + 8) +
        *(f32 *)(arg1 + 0x14) * *(f32 *)(arg2 + 0x10);
    *(f32 *)(arg0 + 0x14) =
        *(f32 *)(arg1 + 0x10) * *(f32 *)(arg2 + 0xC) +
        *(f32 *)(arg1 + 0x14) * *(f32 *)(arg2 + 0x14);
    *(f32 *)(arg0 + 0x18) =
        *(f32 *)(arg1 + 0x18) + *(f32 *)(arg2 + 0x18);
    *(f32 *)(arg0 + 0x1C) =
        *(f32 *)(arg1 + 0x1C) + *(f32 *)(arg2 + 0x1C);
}
/* measured: close schedule on for func_003d6b70. */
#pragma schedule off
/* measured: close optimization_level 3 for func_003d6900 and func_003d6b70. */
#pragma optimization_level 2
/* measured: optimization_level 1 probe for func_003d6c10 load scheduling. */
#pragma optimization_level 1
/* measured: schedule on probe for func_003d6c10 delay-slot placement. */
#pragma schedule on
// FUN_003D6C10
u8 *func_003d6c10(u8 *arg0, u8 *arg1)
{
    f32 value0;
    f32 value1;
    f32 value2;
    f32 value3;
    f32 value4;
    f32 value5;
    u8 *result;

    value0 = *(f32 *)(arg1 + 0);
    result = arg0;
    value1 = *(f32 *)(arg1 + 4);
    value2 = *(f32 *)(arg1 + 0x10);
    value3 = *(f32 *)(arg1 + 0x14);
    value4 = *(f32 *)(arg1 + 0x30);
    value5 = *(f32 *)(arg1 + 0x34);
    *(f32 *)(arg0 + 0) = value0;
    *(f32 *)(arg0 + 4) = value1;
    *(f32 *)(arg0 + 8) = value2;
    *(f32 *)(arg0 + 0xC) = value3;
    *(f32 *)(arg0 + 0x10) = value4;
    *(f32 *)(arg0 + 0x14) = value5;
    return result;
}
/* measured: close schedule on probe for func_003d6c10. */
#pragma schedule off
/* measured: close optimization_level 1 for func_003d6c10. */
#pragma optimization_level 2
// FUN_003D6C50
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6c50);
// FUN_003D6D50
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6d50);
// FUN_003D6E80
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6e80);
// FUN_003D6F90
void func_003d6f90(void)
{
}
// FUN_003D6FA0
void func_003d6fa0(void)
{
}
// FUN_003D6FB0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d6fb0);
/* measured: schedule on probe for func_003d70c0 instruction order. */
#pragma schedule on
// FUN_003D70C0
s32 func_003d70c0(s32 arg0)
{
    s32 result;
    s32 value;

    result = arg0;
    value = func_003e1220(0x44, iGpffffab24, 4, iGpffffab28,
                          iGpffffb748, 0x40135);
    iGpffffb748 = value;
    if (value == 0) {
        goto set_zero;
    }
cleanup:
    func_003d5fb0(D_0070B610);
    func_003d5000((u8 *)D_0070B650);
    func_003d5000((u8 *)D_0070B680);
    iGpffffb744++;
    return result;
set_zero:
    result = 0;
    goto cleanup;
}
/* measured: close schedule on for func_003d70c0. */
#pragma schedule off
/* measured: no_branch_likely on probe for func_003d7150 plain branch. */
#pragma no_branch_likely on
/* measured: schedule on probe for func_003d7150 instruction order. */
#pragma schedule on
// FUN_003D7150
s32 func_003d7150(s32 arg0)
{
    s32 value;

    iGpffffb744--;
    func_003d6010(D_0070B610);
    value = iGpffffb748;
    if (value != 0) {
        func_003e12f0(value);
        iGpffffb748 = 0;
    }
    return arg0;
}
/* measured: close schedule on for func_003d7150. */
#pragma schedule off
/* measured: close no_branch_likely on for func_003d7150. */
#pragma no_branch_likely off
/* measured: schedule on probe for func_003d71b0 prologue ordering. */
#pragma schedule on
/* measured: no_branch_likely on probe for func_003d71b0 plain branch. */
#pragma no_branch_likely on
// FUN_003D71B0
s32 func_003d71b0(void)
{
    s32 result;

    if (func_003e8930(0, 0x135, func_003d70c0, func_003d7150) < 0) {
        return 0;
    }
    D_0072483C = func_003c4310(0x30, 0x135, func_003d7260,
                               func_003d72a0, func_003d7350);
    result = func_003c4340(0x135, func_003d77f0, func_003d75b0,
                            func_003d79b0) >= 0;
    if (result != 0) {
        result = D_0072483C >= 0;
    }
    return result;
}
/* measured: close no_branch_likely on probe for func_003d71b0. */
#pragma no_branch_likely off
/* measured: close schedule on probe for func_003d71b0. */
#pragma schedule off
/* measured: schedule on probe for func_003d7260 prologue argument setup. */
#pragma schedule on
// FUN_003D7260
s32 func_003d7260(s32 arg0)
{
    func_0043f9c8((void *)(arg0 + D_0072483C), 0, 0x30);
    return arg0;
}
/* measured: close schedule on probe for func_003d7260. */
#pragma schedule off
// FUN_003D72A0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d72a0);
// FUN_003D7350
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7350);
// FUN_003D7490
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7490);
// FUN_003D75B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d75b0);
// FUN_003D76D0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d76d0);
// FUN_003D77F0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d77f0);
// FUN_003D79B0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d79b0);
// FUN_003D7A20
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7a20);
// FUN_003D7AC0
INCLUDE_ASM("asm/nonmatchings/rt2d_grouped", func_003d7ac0);
/* measured: schedule on probe for func_003d7b30 return delay slot. */
#pragma schedule on
// FUN_003D7B30
u32 func_003d7b30(u32 value)
{
    return 0x40;
}
/* measured: close schedule on for func_003d7b30. */
#pragma schedule off
#pragma optimization_level 2

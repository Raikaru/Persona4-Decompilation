#include "include_asm.h"
#include "type.h"

extern void func_002bb550(s8 arg0);
extern void (*D_008873EC[])(...);

extern void func_003549d0();
extern void func_00442de8(void *dst, const void *src, u32 size);

extern void func_0046d730(const void *module, u32 line);
extern u32 D_0064B310[];

extern f32 D_00761260;

typedef struct Float2
{
    f32 x;
    f32 y;
} Float2;



extern s32 func_0034c210(void);

// FUN_00354230
void func_00354230(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_002bb550(*(s8 *)(temp_16 + 8));
    (*D_008873EC)(temp_16);
}



// FUN_00354490
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00354490);

// FUN_003544F0
s32 func_003544f0(void)
{
    return 50;
}

// FUN_003547C0
void func_003547c0(s32 *arg0, u8 *arg1)
{
    func_003549d0();
    if (arg1 == NULL) {
        *arg0 = 3;
        return;
    }
    func_00442de8((u8 *)arg0 + 0x10, arg1, 0x100);
    *arg0 = 0;
}



// FUN_003549D0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003549d0);

// FUN_00355070
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355070);

// FUN_00355300
void func_00355300(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = arg1;
}

// FUN_00355310
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355310);

// FUN_00355370
void func_00355370(u8 *arg0, u8 *arg1)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(u32 *)(temp_4 + 0x38) = 0x3F800000;
        *(u32 *)(temp_4 + 0x3C) = 0x3F800000;
    } else {
        *(f32 *)(temp_4 + 0x38) = *(f32 *)(arg1 + 0);
        *(f32 *)(temp_4 + 0x3C) = *(f32 *)(arg1 + 4);
    }
}



// FUN_003553B0
void func_003553b0(u8 *arg0, f32 *arg1)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        func_0046d730(D_0064B310, 0x5CD);
    }
    arg1[0] = *(f32 *)(temp_16 + 0x38);
    arg1[1] = *(f32 *)(temp_16 + 0x3C);
}



// FUN_00355460
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00355460);

// FUN_003558A0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003558a0);

// FUN_00356140
void func_00356140(u8 *arg0)
{
    (*D_008873EC)(*(u8 **)(arg0 + 0x38));
}



// FUN_00356170
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00356170);

// FUN_003561D0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_003561d0);

// FUN_00356820
s32 func_00356820(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

// FUN_00359340
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_00359340);

// FUN_003593B0
void func_003593b0(u8 *arg0)
{
    *(f32 *)(arg0 + 0x34) *= 0.5f;
    *(f32 *)(arg0 + 0x30) *= -0.5f;
}



// FUN_003596A0
s32 func_003596a0(u8 *arg0) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = *(s16 *)(arg0 + 0x20);

    while (i < 43) {
        if (v < *(s32 *)(arg0 + i * 48 + 0x17C)) {
            flag = 0;
        }
        i++;
    }
    return flag & func_0034c210();
}

// FUN_003599A0
void func_003599a0(u8 *arg0)
{
    *(u32 *)(arg0 + 0x30) = 0x42700000;
    *(f32 *)(arg0 + 0x34) = D_00761260;
}



// FUN_0035AEC0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035aec0);

// FUN_0035AF10
void func_0035af10(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}



// FUN_0035AFA0
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035afa0);

// FUN_0035BE70
INCLUDE_ASM("asm/nonmatchings/code1_0035", func_0035be70);

// FUN_0035BEC0
void func_0035bec0(u8 *arg0)
{
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_003549d0(temp_16 + 0x30);
    (*D_008873EC)(temp_16);
}



// FUN_0035C670
void func_0035c670(u8 *arg0, f32 *arg1)
{
    *(Float2 *)arg1 = *(Float2 *)(*(u8 **)(arg0 + 0x38));
}

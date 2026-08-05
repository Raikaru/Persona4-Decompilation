#include "include_asm.h"
#include "type.h"

extern void memset(void *destination, s32 value, u32 size);

extern u8 *func_00452560(void);
extern void func_0045af60(s32 bank, s32 channel, s32 cue, s32 variant);
extern s32 func_00212180(s32);
extern void func_00216c40(s32, s32);
extern void func_001f7620(s16 channel, s32 fadeFrames);



extern void func_0046b0d0(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);

// FUN_00211950
void func_00211950(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x20);
    *(s32 *)(arg0 + 4) = arg1;
    *(s32 *)(arg0 + 0x10) = 1;
}



// FUN_002119A0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002119a0);

// FUN_00211F90
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211f90);

// FUN_00212100
void func_00212100(s32 arg0) {
    u8 *temp_16;

    temp_16 = (u8 *)func_00452560() + 0x75C;
    if (func_00212180(arg0) != 0) {
        func_0045af60(1, 0xE, 2, 2);
        *(s16 *)(temp_16 + 0xE) = 0;
        *(u16 *)(temp_16 + 8) |= 8;
    }
}



// FUN_002121B0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002121b0);

// FUN_00212240
void func_00212240(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560() + 0x76C) = arg1;
}



// FUN_00213840
void func_00213840(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0046b0d0((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_00213AB0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213ab0);

// FUN_00213B80
void func_00213b80(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x1;
}

// FUN_00213BE0
void func_00213be0(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x4;
}

// FUN_00213C10
void func_00213c10(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x2;
}

// FUN_00213C70
void func_00213c70(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x100;
}

// FUN_00213CD0
void func_00213cd0(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x10);
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 0) |= 0x100;
}



// FUN_00216B40
void func_00216b40(s32 arg0, s32 arg1) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x12) = 0;
    *(s16 *)(temp_16 + 0x14) = 1;
    *(s32 *)(temp_16 + 0x24) = arg1;
    func_00216c40(arg0, 0x20);
    *(u16 *)(temp_16 + 0x10) &= 0xFFF3;
}



// FUN_00216BB0
void func_00216bb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x12) = 1;
    *(s16 *)(temp_16 + 0x14) = 1;
    *(s32 *)(temp_16 + 0x20) = arg1;
    *(s32 *)(temp_16 + 0x18) = arg2;
    *(s32 *)(temp_16 + 0x1C) = arg3;
    func_00216c40(arg0, 0x20);
    *(u16 *)(temp_16 + 0x10) &= 0xFFF3;
}



// FUN_00216C40
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216c40);

// FUN_00216CA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216ca0);

// FUN_00216D70
void func_00216d70(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560() + 0x86C) = arg1;
}



// FUN_00216DA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216da0);

// FUN_00216DF0
void func_00216df0(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x40);
    *(s32 *)(arg0 + 0x18) = -1;
    *(s32 *)(arg0 + 0x3C) = arg1;
    *(s16 *)(arg0 + 0x28) = -1;
    *(s32 *)(arg0 + 0x2C) = -1;
}



// FUN_00216E50
void func_00216e50(void)
{
}

// FUN_00218260
void func_00218260(void) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x28) = -1;
    *(s32 *)(temp_16 + 0x2C) = -1;
    func_001f7620(1, 0);
    *(u16 *)(temp_16 + 0x10) &= 0xFFEF;
}



// FUN_002183C0
void func_002183c0(void) {
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    temp_16 = temp_2 + 0x84C;
    *(s16 *)(temp_16 + 0x28) = -1;
    *(s32 *)(temp_16 + 0x2C) = -1;
    func_001f7620(1, 0);
    *(u16 *)(temp_16 + 0x10) &= 0xFFEF;
}

// FUN_00218420
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218420);

// FUN_00218500
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218500);

// FUN_002186C0
void func_002186c0(u8 *arg0, s32 arg1) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    *(s32 *)(temp_2 + 0x8C8) = arg1;
    *(s16 *)(temp_2 + 0x8C2) = 2;
}

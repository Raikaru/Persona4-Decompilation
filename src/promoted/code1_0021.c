#include "include_asm.h"
#include "type.h"

extern s32 iGpffffa598;
extern void func_00442088(u8 *dst, const char *fmt, s32 arg);
extern void func_00278450(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00271b70(s32 arg0);
extern void func_00277ad0(s32 arg0, s32 arg1);
extern void func_00201350(void);
extern void func_002112c0(u8 *arg0, u8 *arg1);
extern void func_00211650(u8 *arg0);

extern void memset(void *destination, s32 value, u32 size);

extern u8 *func_00452560();
extern void func_0045af60(s32 bank, s32 channel, s32 cue, s32 variant);
extern s32 func_00212180(s32);
extern void func_00216c40(s32, s32);
extern void func_001f7620(s16 channel, s32 fadeFrames);



extern void func_0046b0d0(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);

// FUN_00210C70
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00210c70);
// FUN_002112C0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002112c0);
// FUN_00211650
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211650);
// FUN_00211950
void func_00211950(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x20);
    *(s32 *)(arg0 + 4) = arg1;
    *(s32 *)(arg0 + 0x10) = 1;
}



// FUN_002119A0
void func_002119a0(u8 **arg0) {
    u8 *p = *arg0;
    u8 *next;

    while (p != NULL) {
        next = *(u8 **)(p + 0x24);
        *(u16 *)(*(u8 **)p + 0xA0) -= 1;
        jtbl_008873EC[0](p);
        p = next;
    }
    *arg0 = NULL;
}

// FUN_00211A10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211a10);
// FUN_00211AD0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211ad0);
// FUN_00211BA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211ba0);
// FUN_00211F90
void func_00211f90(s32 arg0, u8 *arg1) {
    u8 sp30[0x20];
    u8 *b = (u8 *)func_00452560(*(s32 *)(arg1 + 4));

    func_00201350();
    if ((*(u16 *)(arg1 + 8) & 0x10) == 0) {
        return;
    }
    if (*(s32 *)(arg1 + 0x10) == 0) {
        return;
    }
    func_002112c0(arg1, sp30);
    func_00211650(b);
}

// FUN_00212010
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212010);
// FUN_00212040
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212040);
// FUN_00212070
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212070);
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



// FUN_00212180
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212180);
// FUN_002121B0
void func_002121b0(void)
{
    u8 *work;
    u8 *sub;

    work = (u8 *)func_00452560();
    sub = work + 0x75C;
    *(s16 *)(work + 0x770) = 0;
    *(s16 *)(work + 0x772) = 5;
    func_0043f9c8(sub + 0x18, 0, 4);
    *(u16 *)(sub + 8) = *(u16 *)(sub + 8) | 0x10;
}

// FUN_00212210
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212210);
// FUN_00212240
void func_00212240(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560() + 0x76C) = arg1;
}



// FUN_00212270
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212270);
// FUN_002136F0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002136f0);
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

// FUN_002138A0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002138a0);
// FUN_00213990
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213990);
// FUN_002139D0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002139d0);
// FUN_00213A10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213a10);
// FUN_00213A50
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213a50);
// FUN_00213A80
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213a80);
// FUN_00213AB0
void func_00213ab0(s32 arg0, u8 *arg1) {
    func_0043f9c8(arg1, 0, 0x18);
    *(f32 *)(arg1 + 0x10) = 0.5f;
    *(f32 *)(arg1 + 0x14) = 170.0f;
    *(s16 *)(arg1 + 0xC) = 10;
    *(s16 *)(arg1 + 6) = -2;
    *(s16 *)(arg1 + 4) = -2;
}

// FUN_00213B10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213b10);
// FUN_00213B30
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213b30);
// FUN_00213B50
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213b50);
// FUN_00213B80
void func_00213b80(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x1;
}

// FUN_00213BB0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213bb0);
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

// FUN_00213C40
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213c40);
// FUN_00213C70
void func_00213c70(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x100;
}

// FUN_00213CA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213ca0);
// FUN_00213CD0
void func_00213cd0(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x10);
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 0) |= 0x100;
}



// FUN_00213D20
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213d20);
// FUN_00213E20
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00213e20);
// FUN_002142B0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002142b0);
// FUN_00215C10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00215c10);
// FUN_002161D0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002161d0);
// FUN_002167F0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002167f0);
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
void func_00216c40(s32 arg0, s32 arg1) {
    u8 *b = (u8 *)func_00452560();
    u8 *p = b + 0x84C;

    *(s32 *)(b + 0x850) = arg1;
    if (arg1 < 0) {
        *(u16 *)(p + 0x10) |= 1;
    } else {
        *(u16 *)(p + 0x10) &= 0xFFFE;
    }
}

// FUN_00216CA0
void func_00216ca0(void) {
    u8 *b = (u8 *)func_00452560() + 0x84C;

    if (*(s32 *)b != 0) {
        func_00271b70(*(s32 *)b);
        *(s32 *)b = 0;
    }
    func_00277ad0(*(s32 *)(b + 0x18), 0);
    *(u16 *)(b + 0x10) &= 0xFFFD;
    *(u16 *)(b + 0x16) = 0;
    *(s32 *)(b + 8) = *(s32 *)(b + 4);
}

// FUN_00216D10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216d10);
// FUN_00216D40
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216d40);
// FUN_00216D70
void func_00216d70(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560() + 0x86C) = arg1;
}



// FUN_00216DA0
void func_00216da0(u8 *arg0, s32 arg1) {
    u8 sp20[0x80];

    func_00442088(sp20, (const char *)&iGpffffa598, arg1);
    func_00278450(arg0, 1, sp20);
}

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

// FUN_00216E60
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00216e60);
// FUN_00218160
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218160);
// FUN_00218200
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218200);
// FUN_00218230
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218230);
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



// FUN_002182C0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002182c0);
// FUN_00218360
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218360);
// FUN_00218390
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218390);
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
void func_00218420(void)
{
    u8 *work;
    u8 *sub;

    work = (u8 *)func_00452560();
    sub = work + 0x84C;
    *(s16 *)(work + 0x874) = -1;
    *(s32 *)(work + 0x880) = 0;
    *(s32 *)(sub + 0x2C) = func_002774d0(func_001f3b80(0xCB));
    *(s32 *)(sub + 0x30) = 0;
    *(s32 *)(sub + 0x38) = 0;
    *(s16 *)(sub + 0x2A) = 8;
    func_001f62b0();
    *(u16 *)(sub + 0x10) = *(u16 *)(sub + 0x10) | 0x10;
}

// FUN_002184A0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002184a0);
// FUN_002184D0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002184d0);
// FUN_00218500
void func_00218500(void)
{
    u8 *work;
    u8 *sub;
    s32 handle;

    work = (u8 *)func_00452560();
    sub = work + 0x84C;
    *(s16 *)(work + 0x874) = -1;
    handle = *(s32 *)(work + 0x878);
    if (handle != -1) {
        func_002777f0(handle);
        *(s32 *)(sub + 0x2C) = -1;
    }
    *(u16 *)(sub + 0x10) = *(u16 *)(sub + 0x10) & 0xFFEF;
}

// FUN_00218560
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218560);
// FUN_00218690
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218690);
// FUN_002186C0
void func_002186c0(u8 *arg0, s32 arg1) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    *(s32 *)(temp_2 + 0x8C8) = arg1;
    *(s16 *)(temp_2 + 0x8C2) = 2;
}

// FUN_00218700
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218700);
// FUN_00218730
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00218730);
// FUN_0021A7B0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021a7b0);
// FUN_0021AE60
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021ae60);
// FUN_0021AE80
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021ae80);
// FUN_0021AEB0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021aeb0);
// FUN_0021AFA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021afa0);
// FUN_0021B0A0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b0a0);
// FUN_0021B190
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b190);
// FUN_0021B1E0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b1e0);
// FUN_0021B1F0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b1f0);
// FUN_0021B310
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b310);
// FUN_0021B330
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b330);
// FUN_0021B500
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b500);
// FUN_0021B630
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b630);
// FUN_0021BBB0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021bbb0);
// FUN_0021BE10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021be10);
// FUN_0021BE60
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021be60);
// FUN_0021BE70
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021be70);
// FUN_0021BE80
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021be80);
// FUN_0021D440
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021d440);
// FUN_0021D470
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021d470);
// FUN_0021D4A0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021d4a0);
// FUN_0021D920
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021d920);
// FUN_0021D980
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021d980);
// FUN_0021DAB0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021dab0);
// FUN_0021DB10
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021db10);
// FUN_0021DB40
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021db40);
// FUN_0021DBA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021dba0);
// FUN_0021DC50
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021dc50);
// FUN_0021DDA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021dda0);
// FUN_0021DE60
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021de60);
// FUN_0021DE90
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021de90);
// FUN_0021E050
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021e050);
// FUN_0021E110
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021e110);
// FUN_0021E9A0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021e9a0);
// FUN_0021EB60
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021eb60);
// FUN_0021EC40
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021ec40);
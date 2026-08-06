#include "include_asm.h"
#include "type.h"
extern void func_001bdeb0();

s32 func_00452380(u8 *arg0);

extern u8 D_006290F0[];

u16 *func_00452560(void);

extern u8 D_00629640[];

extern u8 D_006296B0[];

extern u8 D_00629700[];

void func_001c8d50(void);

extern u8 *DAT_0076449c;

void func_002258b0(float arg0, float arg1);

void func_00455ea0(s32 arg0, s32 arg1, s32 arg2);



extern void (*jtbl_008873EC[])(void *arg0);
extern s32 func_0011b360(s32 arg0);

// FUN_00221910
s32 func_00221910(void)
{
    return func_00452380(D_006290F0) != 0;
}



// FUN_00221940
s32 func_00221940(void)
{
    return ((*func_00452560() & 0x10) != 0) ^ 1;
}



// FUN_002231E0
void func_002231e0(void) {
    u16 *temp_2;

    temp_2 = (u16 *)(func_00452560());
    *(s32 *)((u8 *)(temp_2) + 8) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        func_0021dda0();
        *(s32 *)((u8 *)(temp_2) + 4) = 4;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 5;
}

// FUN_00223270
s32 func_00223270(void)
{
    return func_00452380(D_00629640) != 0;
}



// FUN_002236C0
void func_002236c0(void)
{
    u8 *p;
    s32 h;

    p = (u8 *)func_00452560();
    if (*(u16 *)p & 4) {
        h = *(s32 *)(p + 0x4C);
        if (h != 0) {
            func_0011b360(h);
            *(s32 *)(p + 0x4C) = 0;
        }
    }
    (*jtbl_008873EC)(p);
}

// FUN_00223830
void func_00223830(void) {
    u16 *temp_2;

    temp_2 = (u16 *)(func_00452560());
    *(s16 *)((u8 *)(temp_2) + 0x48) = 0;
    if (*(u16 *)((u8 *)(temp_2) + 0) & 4) {
        func_0021dda0();
        *(s32 *)((u8 *)(temp_2) + 4) = 6;
        return;
    }
    *(s32 *)((u8 *)(temp_2) + 4) = 7;
}

// FUN_002238C0
s32 func_002238c0(void)
{
    return func_00452380(D_006296B0) != 0;
}



// FUN_00223EE0
void func_00223ee0(void)
{
    u8 *p;
    s32 h;

    p = (u8 *)func_00452560();
    h = *(s32 *)(p + 0x44);
    if (h != 0) {
        func_0011b360(h);
        *(s32 *)(p + 0x44) = 0;
    }
    (*jtbl_008873EC)(p);
}

// FUN_002240B0
s32 func_002240b0(void)
{
    return func_00452380(D_00629700) != 0;
}



// FUN_00224970
void func_00224970(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
        func_001c8d50();
    }
}



// FUN_00225860
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225860);

// FUN_00225BD0
void func_00225bd0(void)
{
    func_002258b0(0.0f, 2.0f);
}



// FUN_00225E50
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00225e50);

// FUN_00227770
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_00227770);

// FUN_00228480
void func_00228480(u8 *arg0) {
    if (func_00243ce0(*(s32 *)((u8 *)(*(u8 **)((u8 *)(*(u8 **)((u8 *)(arg0) + 0xE0)) + 0x30)) + 0xA64)) == 0) {
        func_001bfb70(arg0);
    }
}

// FUN_00228A60
void func_00228a60(void)
{
    func_001bdeb0();
}

// FUN_00228D00
void func_00228d00(u8 *arg0) {
    if (func_001f0ff0(*(u8 **)((u8 *)(arg0) + 0xE0)) != 0) {
        func_001bdeb0(arg0);
    }
}

// FUN_0022A6B0
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022a6b0);

// FUN_0022B040
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022b040);

// FUN_0022BA40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022ba40);

// FUN_0022BAC0
s32 func_0022bac0(void)
{
    return 0;
}

// FUN_0022BC80
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022bc80);

// FUN_0022BD00
s32 func_0022bd00(void)
{
    return *(s32 *)(DAT_0076449c + 0xBA0) != 0;
}



// FUN_0022CED0
void func_0022ced0(s32 arg0)
{
    func_00455ea0(*(s32 *)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}

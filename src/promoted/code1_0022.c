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
extern void func_001c97b0(void *arg0);
extern s32 func_001bc560(u8 *arg0, u8 *arg1);
extern void func_0019de70(u8 *arg0, u16 arg1);

extern u8 *func_00193bf0(u64 uid, u64 mask);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 func_00452490(u8 *arg0);
extern u8 *func_001b0c80(u8 *arg0);
extern void func_001f2eb0(u8 *arg0, s32 arg1);
extern void func_001f7530(void);

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
void func_00225860(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    if ((temp_3 != NULL) && ((*(u16 *)(temp_3 + 0x1A) & 1) != 0)) {
        temp_5 = *(u16 *)(DAT_0076449c + 0xC00);
        if (temp_5 == 1) {
            func_001c97b0(arg0);
        }
    }
}

// FUN_00225BD0
void func_00225bd0(void)
{
    func_002258b0(0.0f, 2.0f);
}



// FUN_00225E50
void func_00225e50(u8 *arg0)
{
    s32 iVar1;

    iVar1 = *(s32 *)(arg0 + 0xE0);
    if ((((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u8 *)(*(s32 *)(iVar1 + 0x30) + 0xA2) != 0)) &&
        (((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u16 *)(DAT_0076449c + 0xC00) == 1))) {
        func_001c97b0(arg0);
    }
}

// FUN_00227770
void func_00227770(u8 *arg0)
{
    u8 *temp_3;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0x12C);
    if (temp_5 != NULL) {
        temp_3 = *(u8 **)(arg0 + 0xE0);
        if ((temp_3 != NULL) &&
            ((*(u16 *)(temp_3 + 0x1A) & 1) != 0) &&
            (func_001bc560(arg0, temp_5) != 0)) {
            func_0019de70(*(u8 **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}


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
s32 func_0022a6b0(s64 *arg0) {
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        func_00106390(0x15FF, 1);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// FUN_0022B040
s32 func_0022b040(s64 *arg0)
{
    u8 *temp_4;

    if (func_00193bf0(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// FUN_0022BA40
INCLUDE_ASM("asm/nonmatchings/code1_0022", func_0022ba40);

// FUN_0022BAC0
s32 func_0022bac0(void)
{
    return 0;
}

// FUN_0022BC80
s32 func_0022bc80(s32 arg0) {
    u8 *b = DAT_0076449c;
    u8 *o = *(u8 **)(b + 0xBA0);

    if (o == NULL) {
        return 0;
    }
    if (*(u16 *)(b + 0xBA4) != (arg0 & 0xFFFF)) {
        return 0;
    }
    if (func_00452490(o) == 0) {
        *(s32 *)(DAT_0076449c + 0xBA0) = 0;
        return 0;
    }
    return 1;
}

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

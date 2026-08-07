#include "include_asm.h"
#include "type.h"
extern u16 D_008C024E[];

extern void func_0046a340(s32 arg0);
extern void func_0027a370();
extern void func_0027a400();

extern s32 func_002746a0(void);
extern void func_00273f70(u8 *arg0);
extern void func_00273cc0(u8 *arg0, u8 *arg1);

extern s32 D_008815B0[];

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0027bf10(s32 arg0);

extern u16 D_008817E8[];
extern u8 *func_00276290();
extern u8 *func_002762f0();



// FUN_002706F0
s32 func_002706f0(u8 *arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_00273f70(arg1);
    func_00273cc0(NULL, arg1);
    return 0;
}



// FUN_00270E30
s32 func_00270e30(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107ce0(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_00270E90
s32 func_00270e90(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107dc0(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_00270EF0
s32 func_00270ef0(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107f00(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_00270F50
s32 func_00270f50(void) {
    s32 temp_2;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_2 = func_00108e10() & 0xFFFF;
    if (temp_2 != 0) {
        func_00107fe0(temp_2 & 0xFFFF);
    }
    return 0;
}

// FUN_002746C0
void func_002746c0(s32 arg0, s32 arg1)
{
    D_008815B0[arg0] = arg1;
}



// FUN_002761F0
u8 *func_002761f0(s32 arg0, u8 *arg1, s32 arg2)
{
    u8 *var_2;

    var_2 = func_00276290(arg0, arg2);
    if (var_2 == NULL) {
        var_2 = func_002762f0(arg0, arg1, arg2);
        if (var_2 == NULL)
            var_2 = NULL;
    }
    return var_2;
}

// FUN_0027A490
void func_0027a490(void)
{
    func_0027a370();
}

// FUN_0027A4B0
void func_0027a4b0(void)
{
    func_0027a400();
}

// FUN_0027A5E0
void func_0027a5e0(s32 *arg0, s32 arg1)
{
    memset(arg0, 0, 0x1C);
    *arg0 = func_0027bf10(arg1);
}



// FUN_0027A650
void func_0027a650(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s8 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 9) = 0;
    *(s16 *)(arg0 + 0xE) = 0;
    *(s16 *)(arg0 + 0x10) = 0;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s8 *)(arg0 + 0xA) = 0;
    *(s8 *)(arg0 + 0xB) = 0;
    *(s8 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0xD) = 0xFF;
}



// FUN_0027A710
void func_0027a710(s32 arg0) {
    s32 i;
    s32 *p;
    s32 v;

    for (i = 0; i < 0x20; i++) {
        p = (s32 *)(arg0 + i * 4);
        v = *p;
        if (v != 0) {
            func_0046a340(v);
            *p = 0;
        }
    }
}

// FUN_0027B1C0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027b1c0);

// FUN_0027B4C0
void func_0027b4c0(s32 *arg0)
{
    s32 temp;

    temp = *arg0;
    if (!(temp & 0x80000) && ((u32)(temp & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}

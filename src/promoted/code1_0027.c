#include "include_asm.h"
#include "type.h"
extern s32 D_0063BF80[];
extern u16 D_008C024E[];

extern void func_0046a340(s32 arg0);
extern void func_0027a370();
extern void func_0027a400();

extern s32 func_002746a0(void);
extern void func_002e0f20(void);
extern s32 func_00277840();
extern void func_00273f70(u8 *arg0);
extern void func_00273cc0(u8 *arg0, u8 *arg1);

extern s32 D_008815B0[];

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0027bf10(s32 arg0);

extern u16 D_008817E8[];
extern u8 *func_00276290();
extern u8 *func_002762f0();
extern void func_0027b5a0(s32 arg0);
extern u8 D_007964C0[];
extern u8 DAT_008817EC_abs[];
extern s32 func_00278110(void);
extern void func_00278a70(s32 arg0);
extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);



// FUN_00270100
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270100);
// FUN_00270390
s32 func_00270390(void)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_002e0f20();
    return 0;
}
// FUN_002703D0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_002703d0);
// FUN_002704F0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_002704f0);
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



// FUN_00270750
s32 func_00270750(void)
{
    func_002746a0();
    return 0;
}
// FUN_00270780
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270780);
// FUN_00270870
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270870);
// FUN_00270910
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270910);
// FUN_002709B0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_002709b0);
// FUN_00270A80
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270a80);
// FUN_00270B80
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270b80);
// FUN_00270CA0
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_00270ca0);
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

// FUN_0027A400
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027a400);
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



// FUN_0027A630
void func_0027a630(u8 *arg0)
{
    *(s32 *)arg0 = 0;
    *(u16 *)(arg0 + 4) = 0xFFFF;
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



// FUN_0027A690
void func_0027a690(u8 *arg0)
{
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 8) = 0;
    *(s16 *)(arg0 + 0xC) = 0;
    *(s16 *)(arg0 + 0xE) = -1;
    *(s16 *)(arg0 + 0x10) = -1;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s16 *)(arg0 + 0x14) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
// FUN_0027A6F0
void func_0027a6f0(s32 *arg0)
{
    *arg0 &= ~0xF00;
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

// FUN_0027A780
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027a780);
// FUN_0027A970
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027a970);
// FUN_0027AC50
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027ac50);
// FUN_0027AE90
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027ae90);
// FUN_0027B100
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027b100);
// FUN_0027B1C0
/* measured: opt_loop_invariants hoists mask/count/const-1 into preheader */
#pragma opt_loop_invariants on
s32 func_0027b1c0(s16 *arg0)
{
    s32 i = 0;
    u16 mask;
    s32 count;
    s32 bit;
    s16 *p;

    mask = D_008C024E[0];
    count = *(s16 *)((u8 *)arg0 + 0x16);
    for (; i < count; i++) {
        p = (s16 *)((u8 *)arg0 + i * 4 + 0x18);
        bit = *p;
        if ((1 << bit) & mask) {
            return *(s16 *)((u8 *)p + 2);
        }
    }
    return -1;
}
/* measured: opt_loop_invariants off */
#pragma opt_loop_invariants off

// FUN_0027B230
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027b230);
// FUN_0027B310
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027b310);
// FUN_0027B4C0
void func_0027b4c0(s32 *arg0)
{
    s32 temp;

    temp = *arg0;
    if (!(temp & 0x80000) && ((u32)(temp & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}

// FUN_0027B500
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027b500);
// FUN_0027B5D0
void func_0027b5d0(s32 arg0)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32))(temp_2 + 8) = func_0027b5a0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0(D_007964C0, temp_2);
}
// FUN_0027B690
void func_0027b690(void)
{
    u8 *temp_16;
    u8 *var_3;

    var_3 = *(u8 **)DAT_008817EC_abs;
    while (var_3 != NULL) {
        temp_16 = *(u8 **)(var_3 + 4);
        func_00278a70(*(s32 *)(var_3 + 8));
        var_3 = temp_16;
    }
}
// FUN_0027B7C0
s32 func_0027b7c0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    *(s32 *)(func_00277840() + 0x14) = 0;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0);
    }
    return 1;
}
// FUN_0027B830
s32 func_0027b830(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)func_00277840();
    *(s32 *)(base + 0x14) = 1;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 1);
    }
    return 1;
}
// FUN_0027B8A0
s32 func_0027b8a0(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)func_00277840();
    *(s32 *)(base + 0x14) = 2;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 2);
    }
    return 1;
}
// FUN_0027B910
s32 func_0027b910(s32 arg0)
{
    u8 *base;
    s32 (*temp_2)(s32, s32);

    base = (u8 *)func_00277840();
    *(s32 *)(base + 0x14) = 3;
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 3);
    }
    return 1;
}
// FUN_0027B980
s32 func_0027b980(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 4);
    }
    return 1;
}
// FUN_0027B9E0
s32 func_0027b9e0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 5);
    }
    return 1;
}
// FUN_0027BA40
s32 func_0027ba40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 6);
    }
    return 1;
}
// FUN_0027BAA0
s32 func_0027baa0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 7);
    }
    return 1;
}
// FUN_0027BB00
s32 func_0027bb00(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 8);
    }
    return 1;
}
// FUN_0027BB60
s32 func_0027bb60(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 9);
    }
    return 1;
}
// FUN_0027BBC0
s32 func_0027bbc0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xA);
    }
    return 1;
}
// FUN_0027BC20
s32 func_0027bc20(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xB);
    }
    return 1;
}
// FUN_0027BC80
s32 func_0027bc80(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xC);
    }
    return 1;
}
// FUN_0027BCE0
s32 func_0027bce0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0xD);
    }
    return 1;
}
// FUN_0027BD40
s32 func_0027bd40(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x10);
    }
    return 1;
}
// FUN_0027BDA0
s32 func_0027bda0(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x11);
    }
    return 1;
}
// FUN_0027BE00
s32 func_0027be00(s32 arg0)
{
    s32 (*temp_2)(s32, s32);

    func_00277840();
    temp_2 = *(s32 (**)(s32, s32))func_00277840(arg0);
    if (temp_2 != NULL) {
        return temp_2(arg0, 0x12);
    }
    return 1;
}
// FUN_0027BEC0
s32 func_0027bec0(void)
{
    s32 temp_2;

    temp_2 = func_00278110();
    if (!(temp_2 & 0x80000) || ((temp_2 & 0x300) < 0x100)) {
        return 1;
    }
    return 0;
}
// FUN_0027BF10
s32 func_0027bf10(s32 arg0)
{
    return D_0063BF80[arg0];
}
// FUN_0027BF30
INCLUDE_ASM("asm/nonmatchings/code1_0027", func_0027bf30);
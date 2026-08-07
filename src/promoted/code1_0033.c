#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

// P4 retail reaches the battle-data object pointer at gp-0x4A68,
// i.e. absolute 0x007690f0 - 0x4a68 = 0x00764688, GP-relative.
extern int iGpffffb598;
extern u16 D_008C024E[];
extern s32 func_0029cc00(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern u32 func_002e7a60(void);

typedef struct {
    s32 lo;
    s32 hi;
} S8iodata;

extern void func_00364320(S8iodata arg0, s32 arg1, s32 arg2, f32 fparg0);

void func_002b82d0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5);

void func_002b8340(u8 *arg0, s8 arg1, s16 arg2, s16 arg3, f32 fparg0, f32 fparg1);



// FUN_00331560
s32 func_00331560(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 4);
}



// FUN_003315A0
void func_003315a0(void)
{
    *(s8 *)(*(int *)(iGpffffb598 + 0x38) + 0x45) = 1;
}



// FUN_003315C0
s32 func_003315c0(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x24);
}



// FUN_003315E0
s32 func_003315e0(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x28);
}



// FUN_00331600
s32 func_00331600(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x2C);
}



// FUN_00331620
s32 func_00331620(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 0x30);
}



// FUN_00331640
s8 func_00331640(void)
{
    return *(s8 *)(*(int *)(iGpffffb598 + 0x38) + 0x44);
}



// FUN_00331660
s32 func_00331660(void)
{
    return *(s32 *)(*(int *)(*(int *)(iGpffffb598 + 0x38) + 0x20) + 0x110);
}



// FUN_003319C0
s32 func_003319c0(void) {
    s32 r;

    if ((D_008C024E[0] & 0x800) != 0) {
        func_00106390(func_0029cc00(0), 1);
        r = 1;
    } else {
        r = 0;
    }
    return r;
}

// FUN_00331F90
void func_00331f90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00332B60
void func_00332b60(u8 *arg0, u8 *arg1)
{
    func_00364320(*(S8iodata *)(arg1 + 0x1E0), 0xFF, func_002e7a60(), 1.0f);
}

// FUN_0033D310
s32 func_0033d310(u8 *arg0)
{
    return *(s32 *)(arg0 + 0x38);
}

// FUN_0033D320
void func_0033d320(u8 *arg0, s32 arg1, s8 arg2) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    if (arg2 == 0) {
        *(s16 *)(p + 4) |= (s16)((1 << arg1) & 0xFFFF);
    } else if (arg2 == 1) {
        *(s16 *)(p + 4) &= (s16)((1 << arg1) ^ 0xFFFF);
    }
}

// FUN_0033D3D0
void func_0033d3d0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
}

// FUN_0033D4B0
void func_0033d4b0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s64 arg5)
{
    func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}



// FUN_0033D520
void func_0033d520(u8 *arg0, s8 arg1, s16 arg2, s64 arg3, f32 fparg0, f32 fparg1)
{
    func_002b8340(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, fparg0, fparg1);
}

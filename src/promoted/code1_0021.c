#include "include_asm.h"
#include "type.h"

extern s32 iGpffffa598;
extern u8 *iGpffffb3ac;
extern s32 iGpffffb470;
extern void func_00442088(u8 *dst, const char *fmt, s32 arg);
extern void func_00278450(u8 *arg0, s32 arg1, u8 *arg2);
extern void func_00271b70(s32 arg0);
extern void func_00277ad0(s32 arg0, s32 arg1);
extern void func_00201350(void);
extern void func_002112c0(u8 *arg0, u8 *arg1);
extern void func_00211650(u8 *arg0, u8 *arg1);

extern void memset(void *destination, s32 value, u32 size);

extern u8 *func_00452560();
extern f32 func_0044b610(f32 fparg0);
extern f32 func_0044b7b0(f32 fparg0);
extern void func_00364c90(s64 arg0, s32 arg1, f32 fparg0, f32 fparg1,
                           f32 fparg2, f32 fparg3, s32 arg2);
extern f32 fGpffff837c;
extern f32 fGpffff8378;
extern u8 *iGpffffb414;
extern f32 *iGpffffb40c;
extern u8 *func_00105510(s16 arg0);
extern u32 func_00105210(s16 arg0);
extern void func_00105990(s16 arg0, u32 value);
extern u8 func_001059e0(s32 arg0);
extern s32 func_00106020(s32 arg0);
extern u8 func_00106600(s16 arg0);
extern void func_00106620(s32 arg0, s32 value);
extern void func_00231ef0(u8 *arg0, u8 arg1);
extern void func_0045af60(s32 bank, s32 channel, s32 cue, s32 variant);
extern s32 func_00212180(s32);
extern void func_00216c40(s32, s32);
extern void func_001f7620(s16 channel, s32 fadeFrames);
extern void func_00454bd0(u8 *arg0);
extern s32 func_00106330(s32 arg0);
extern s32 func_00243ce0(u8 *arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_006290C0[];
extern u8 D_006290D0[];
extern void func_0044ea90(const void *arg0, s32 arg1);
extern void func_0043f810(void *dst, void *src, u32 size);
extern s32 func_00451fc0(s32 arg0, void *data, s32 priority, s32 arg3,
                         s32 arg4, void *init, void *close, void *work);
extern s32 func_0036e690(s32 arg0, void *arg1);
extern s32 func_002215c0(s32 arg0);
extern void func_00460ac0(void *arg0, void *arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern s32 func_00122720(void);
extern u8 D_00796340[];
extern s32 func_0046a750(s32 arg0);
extern s32 func_0021d4a0(s32 arg0);
extern u8 *iGpffffb3c4;
extern void func_0043f9c8(void *dst, s32 value, u32 size);
extern s32 func_0046aea0(void *arg0);
extern u8 D_00626C30[];
extern u8 D_00626CA0[];
extern void func_00212270(u8 *arg0);



extern void func_0046b0d0(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern s32 func_00213a80(void);
extern s32 func_00452380(void *arg0);
extern u8 D_00626C80[];
extern void func_0021b310();
extern s32 func_00221940(s32 arg0);
extern void func_0036e870(s32 arg0);
extern void func_00221770(s32 arg0);
extern u8 D_006290E0[];
extern s32 func_00451de0(void *data, s32 arg1, s32 arg2, s32 arg3,
                         void *init, void *close, void *buf);
extern void func_0021dc50(s32 arg0, s32 *arg1);
extern void func_0021dd60(void);
extern u8 *func_0010ace0(s64 arg0);
extern s32 func_0010b6f0(void);
extern void func_0010c980(u8 *arg0, s32 arg1);
extern s32 func_0010c6f0(u8 *arg0);
extern void func_0010c5a0(u8 *arg0, u8 *arg1);
extern u8 *func_0010a900(u16 arg0);
extern void func_00201720(void *arg0, f32 arg1, f32 arg2);
extern void func_00201650(void *arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4,
                          s32 arg5, s32 arg6, s32 arg7, s32 arg8);
extern void func_00201300(s32 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
extern void func_002016e0(u8 *arg0, s16 arg1, s16 arg2, f32 arg3);
extern void func_00201950(u8 *arg0, s32 arg1, s32 arg2);
extern void func_00201990(u8 *arg0, s32 arg1, s32 arg2);
extern void func_002019d0(u8 *arg0, f32 arg1, f32 arg2);
extern s32 func_00243e90(s32 arg0);
extern u8 *func_001b1540(void);
extern void func_002142b0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern void func_002161d0(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern void func_00215c10(s32 *arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern f32 fGpffff84a0;
extern void func_0021b330(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2);
extern s32 func_00231f80(s32 arg0);
extern s32 func_002428f0(u8 *arg0, s32 arg1);
extern f32 fGpffff8498;
extern f32 fGpffff8200;
extern s32 func_0021dba0(void);
extern void func_00210c70(u8 *arg0, u8 *arg1);
extern void func_0020ff00(u8 *arg0, u8 *arg1);
extern void func_0021e110(u8 *arg0, u8 *arg1);
extern void func_0021e9a0(u8 *arg0, u8 *arg1);
extern void func_0021eb60(u8 *arg0);
extern void func_0021ec40(s32 arg0);

static inline f32 ws14_mul(f32 left, f32 right)
{
    return left * right;
}

static inline f32 ws14_add(f32 left, f32 right)
{
    return left + right;
}
static inline f32 ws14_sub(f32 left, f32 right)
{
    return left - right;
}



// FUN_00210C70
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00210c70);
// FUN_002112C0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_002112c0);
// FUN_00211650
void func_00211650(u8 *arg0, u8 *arg1)
{
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_00201820(s32 arg0);
    extern s32 func_0021be60(void);
    extern void func_0021b630(f32 f0, f32 f1, f32 f2, f32 f3, f32 f4,
                              f32 f5, f32 f6, f32 f7, s32 arg0, f32 f8);
    extern f32 fGpffff84a0;
    struct FnFrame {
        u8 color[4];
    } frame;
    s32 color;
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    s32 temp_16;
    s32 var_17;

    D_00887300[0](1, func_0021be60());
    func_00201820(2);
    frame.color[0] = 0x52;
    frame.color[1] = 0xF3;
    frame.color[2] = 0;
    temp_16 = *(s32 *)(arg1 + 4);
    for (var_17 = 0; var_17 < temp_16; var_17++) {
        frame.color[3] = (s8)*(u16 *)(arg1 + 8 + (var_17 << 1));
        color = *(s32 *)frame.color;
        func_0021b630(21.0f + (f32)(var_17 * 0x14),
                      386.0f, 0.0f, 22.0f, 22.0f,
                      114.0f, 197.0f, 136.0f, color, 219.0f);
    }
    temp_f22 = *(f32 *)arg1;
    if (!(temp_f22 <= 0.0f)) {
        frame.color[0] = 0x52;
        frame.color[1] = 0xF3;
        frame.color[2] = 0;
        frame.color[3] = 0xFF;
        temp_f21 = 21.0f * temp_f22;
        temp_f20 = ws14_mul(temp_f22, -10.5f);
        temp_f20 = ws14_add(fGpffff84a0, temp_f20);
        func_0021b630(14.0f, temp_f20, 0.0f, 12.0f, temp_f21,
                      37.0f, 218.0f, 49.0f, *(s32 *)frame.color, 239.0f);
        func_0021b630(26.0f, temp_f20, 0.0f, 112.0f, temp_f21,
                      49.0f, 218.0f, 49.0f, *(s32 *)frame.color, 239.0f);
        func_0021b630(138.0f, temp_f20, 0.0f, 12.0f, temp_f21,
                      49.0f, 218.0f, 37.0f, *(s32 *)frame.color, 239.0f);
        func_00201820(0);
        frame.color[0] = 0xD;
        frame.color[1] = 0x1B;
        frame.color[2] = 0;
        frame.color[3] = 0xFF;
        func_0021b630(24.0f, fGpffff84a0 + ws14_mul(temp_f22, -9.5f),
                      0.0f, 116.0f, 19.0f * temp_f22, 136.0f,
                      235.0f, 252.0f, *(s32 *)frame.color, 254.0f);
        return;
    }
    func_00201820(0);
}
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
void func_00211a10(u8 **arg0)
{
    u8 *var_4;
    u8 *var_17;
    u8 *temp_16;
    u8 *temp_3;

    var_4 = *arg0;
    var_17 = var_4;
    goto loop_test;
loop_body:
    *(s32 *)(var_4 + 0x10) = *(s32 *)(var_4 + 0x10) + 1;
    if ((*(u16 *)(var_4 + 0x14) & 1) == 0) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        if (*arg0 == var_4) {
            *arg0 = temp_16;
        } else {
            *(u8 **)(var_17 + 0x24) = temp_16;
        }
        temp_3 = *(u8 **)(var_4 + 0);
        *(u16 *)(temp_3 + 0xA0) = *(u16 *)(temp_3 + 0xA0) - 1;
        jtbl_008873EC[0](var_4);
        var_4 = temp_16;
    } else {
        var_17 = var_4;
        var_4 = *(u8 **)(var_4 + 0x24);
    }
    goto loop_test;
loop_test:
    if (var_4 != NULL) {
        goto loop_body;
    }
}
// FUN_00211AD0
void func_00211ad0(u8 *arg0, u8 *arg1)
{
    s32 *temp_2;
    u16 temp_4;
    u8 *var_18;

    temp_2 = (s32 *)func_00452560(*(s32 *)(arg1 + 4));
    if ((*temp_2 & 1) != 0) {
        func_00201350();
        var_18 = *(u8 **)arg1;
        goto loop_test;
loop_body:
        func_00210c70(arg1, var_18);
        var_18 = *(u8 **)(var_18 + 0x24);
loop_test:
        if (var_18 != NULL) {
            goto loop_body;
        }
        temp_4 = *(u16 *)(arg1 + 8);
        if ((temp_4 & 8) != 0) {
            if (*(u16 *)(arg1 + 0xE) < 0x3C) {
                func_0020ff00((u8 *)temp_2, arg1);
                return;
            }
            *(u16 *)(arg1 + 8) = temp_4 & 0xFFF7;
        }
    }
}
// FUN_00211BA0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00211ba0);
// FUN_00211F90
void func_00211f90(s32 arg0, u8 *arg1) {
    extern void func_00211650();
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
void func_00212010(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) | 1;
}
// FUN_00212040
void func_00212040(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) & 0xFFFE;
}
// FUN_00212070
void func_00212070(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;

    p = func_00452560();
    sub = p + 0x75C;
    *(s16 *)(p + 0x766) = 0;
    if (*(u8 *)(*(u8 **)(arg1 + 0x30) + 0xA2) == 0) {
        *(u16 *)(sub + 8) |= 4;
    } else {
        *(u16 *)(sub + 8) &= 0xFFFB;
    }
    func_0045af60(1, 0xF, 2, 0xD);
    *(u16 *)(sub + 8) |= 2;
}
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
s32 func_00212180(s32 arg0)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560() + 0x764) & 8) != 0;
    return flag ^ 1;
}
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
void func_00212210(void)
{
    u8 *p;

    p = func_00452560();
    *(s16 *)(p + 0x772) = 0;
    *(u16 *)(p + 0x764) = *(u16 *)(p + 0x764) & 0xFFEF;
}
// FUN_00212240
void func_00212240(u8 *arg0, s32 arg1) {
    *(s32 *)((u8 *)func_00452560() + 0x76C) = arg1;
}



// FUN_00212270
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_00212270);
// FUN_002136F0
s32 func_002136f0(void)
{
    s16 temp_2_2;
    u8 *temp_2;
    s32 temp_2_3;
    s32 temp_3;

    temp_2 = func_00452560();
    *(s32 *)(temp_2 + 8) = 0;
    *(s32 *)(temp_2 + 0xC) = 0;
    func_00460ac0(&D_00796340, temp_2 + 8);
    temp_2_2 = *(s16 *)(temp_2 + 0);
    switch (temp_2_2) {
    case 0:
        goto block_14;
    case 1:
        if (func_0046a750(*(s32 *)(temp_2 + 4)) != 0) {
            *(s16 *)(temp_2 + 0) = 2;
        }
        goto block_14;
    case 2:
        if (*(s32 *)(temp_2 + 0x40) != 0) {
            func_0045af60(1, 0, 5, 0);
            *(s16 *)(temp_2 + 0) = 3;
        case 3:
            temp_2_3 = *(s32 *)(temp_2 + 0x38);
            if (temp_2_3 < 0x24) {
                *(s32 *)(temp_2 + 0x38) = temp_2_3 + 1;
            } else if ((*(s32 *)(temp_2 + 0x44) == 1) &&
                       (*(s32 *)(temp_2 + 0x3C) == 0)) {
                *(s16 *)(temp_2 + 0) = 4;
            }
        }
        goto block_14;
    case 4:
        temp_3 = *(s32 *)(temp_2 + 0x38);
        *(s32 *)(temp_2 + 0x38) = temp_3 + 1;
        if (temp_3 >= 0x34) {
            *(s16 *)(temp_2 + 0) = 5;
        }
        goto block_14;
    case 5:
        return -1;
    default:
block_14:
        return 0;
    }
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

// FUN_002138A0
void func_002138a0(s32 arg0)
{
    f32 *temp_2;
    u8 *temp_17;

    temp_17 = func_00452560();
    func_0044ea90(&D_00626C30, 0x3A);
    temp_2 = (f32 *)jtbl_008873E8[0](0x48, 0x40000);
    func_0043f9c8(temp_2, 0, 0x48);
    *(s32 *)((u8 *)temp_2 + 4) = func_0046aea0(&D_00626CA0);
    *(s16 *)((u8 *)temp_2 + 0) = 1;
    *(void **)((u8 *)temp_2 + 0x10) = (void *)func_00212270;
    *(f32 **)((u8 *)temp_2 + 0x18) = temp_2;
    *(s32 *)(temp_17 + 0x778) =
        func_00451fc0(arg0, &D_00626C80, 0xF, 0, 0,
                      (void *)func_002136f0, (void *)func_00213840,
                      temp_2);
}
// FUN_00213990
void func_00213990(void)
{
    u8 *p;
    s32 value;

    p = func_00452560(*(s32 **)((u8 *)func_00452560() + 0x778));
    value = 1;
    *(s32 *)(p + 0x40) = value;
}
// FUN_002139D0
s32 func_002139d0(void)
{
    return *(s32 *)(func_00452560(*(s32 **)((u8 *)func_00452560() + 0x778)) + 0x38) >= 0x24;
}
// FUN_00213A10
void func_00213a10(void)
{
    u8 *p;
    s32 value;

    p = func_00452560(*(s32 **)((u8 *)func_00452560() + 0x778));
    value = 1;
    *(s32 *)(p + 0x44) = value;
}
// FUN_00213A50
s32 func_00213a50(void)
{
    s32 flag;

    flag = func_00213a80() != 0;
    return flag ^ 1;
}
// FUN_00213A80
s32 func_00213a80(void)
{
    return func_00452380(&D_00626C80) != 0;
}
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
void func_00213b10(u8 *arg0)
{
    *(s32 *)(arg0 + 0xA10) |= 1;
    *(s16 *)(arg0 + 0xA18) = 0;
}
// FUN_00213B30
void func_00213b30(u8 *arg0)
{
    *(s32 *)(arg0 + 0xA10) |= 2;
    *(s16 *)(arg0 + 0xA1A) = 0;
}
// FUN_00213B50
void func_00213b50(void)
{
    u8 *p;

    p = func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~1;
}
// FUN_00213B80
void func_00213b80(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x1;
}

// FUN_00213BB0
void func_00213bb0(void)
{
    u8 *p;

    p = func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~4;
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

// FUN_00213C40
void func_00213c40(void)
{
    u8 *p;

    p = func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~2;
}
// FUN_00213C70
void func_00213c70(void)
{
    u8 *p;

    p = (u8 *)func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) | 0x100;
}

// FUN_00213CA0
void func_00213ca0(void)
{
    u8 *p;

    p = func_00452560();
    *(s32 *)(p + 0x80C) = *(s32 *)(p + 0x80C) & ~0x100;
}
// FUN_00213CD0
void func_00213cd0(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x10);
    *(s32 *)(arg0 + 0xC) = arg1;
    *(s32 *)(arg0 + 0) |= 0x100;
}



// FUN_00213D20
void func_00213d20(u8 *arg0)
{
    u8 *entry;

    entry = *(u8 **)(iGpffffb3ac + 0x17C);
    while (entry != NULL) {
        if ((*(s32 *)arg0 & 1) != 0) {
            if (*(s16 *)(entry + 0xA16) > -2) {
                *(s16 *)(entry + 0xA16) = *(s16 *)(entry + 0xA16) - 1;
            }
        } else {
            if (*(s16 *)(entry + 0xA16) < 0x19) {
                *(s16 *)(entry + 0xA16) = *(s16 *)(entry + 0xA16) + 1;
            }
        }
        if ((*(s32 *)arg0 & 2) == 0) {
            *(s16 *)(entry + 0xA14) = *(s16 *)(entry + 0xA14) - 2;
            if (*(s16 *)(entry + 0xA14) < 0) {
                *(s16 *)(entry + 0xA14) = 0;
            }
        } else {
            if (*(s16 *)(entry + 0xA14) < 8) {
                *(s16 *)(entry + 0xA14) = *(s16 *)(entry + 0xA14) + 1;
            }
        }
        entry = *(u8 **)(entry + 0xA68);
    }
    if ((*(s32 *)arg0 & 4) != 0) {
        if (*(s16 *)(arg0 + 4) < 10) {
            *(s16 *)(arg0 + 4) = *(s16 *)(arg0 + 4) + 1;
        }
    } else {
        if (*(s16 *)(arg0 + 4) > 0) {
            *(s16 *)(arg0 + 4) = *(s16 *)(arg0 + 4) - 1;
        }
    }
}
// FUN_00213E20
void func_00213e20(u8 *arg0, u8 *arg1)
{
    extern s32 func_002326c0(s32 arg0);
    s32 value;

    value = func_002326c0(*(s32 *)(arg0 + 0xA64));
    *(s32 *)(arg1 + 0x14) = value;
    if (value == 0) {
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0xAF;
        *(u8 *)(arg1 + 2) = 0x20;
        *(u8 *)(arg1 + 4) = 0xFE;
        *(u8 *)(arg1 + 5) = 0xFF;
        *(u8 *)(arg1 + 6) = 0x22;
        *(u8 *)(arg1 + 8) = 0xFF;
        *(u8 *)(arg1 + 9) = 0xFF;
        *(u8 *)(arg1 + 0xA) = 0xFF;
        *(u8 *)(arg1 + 0xC) = 0;
        *(u8 *)(arg1 + 0xD) = 0;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0xAF;
        *(u8 *)(arg1 + 0x12) = 0x20;
        return;
    }
    switch (value) {
    case 2:
        *(u8 *)(arg1 + 0) = 0x8E;
        *(u8 *)(arg1 + 1) = 6;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0xFF;
        *(u8 *)(arg1 + 5) = 0x41;
        *(u8 *)(arg1 + 6) = 0x40;
        *(u8 *)(arg1 + 8) = 0x7B;
        *(u8 *)(arg1 + 9) = 0xB;
        *(u8 *)(arg1 + 0xA) = 1;
        *(u8 *)(arg1 + 0xC) = 0xFF;
        *(u8 *)(arg1 + 0xD) = 0x41;
        *(u8 *)(arg1 + 0xE) = 0x40;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0x41;
        *(u8 *)(arg1 + 0x12) = 0x40;
        return;
    case 4:
        *(u8 *)(arg1 + 0) = 0x4E;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0xF2;
        *(u8 *)(arg1 + 4) = 0x76;
        *(u8 *)(arg1 + 5) = 0x40;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0xE;
        *(u8 *)(arg1 + 9) = 1;
        *(u8 *)(arg1 + 0xA) = 0x7B;
        *(u8 *)(arg1 + 0xC) = 0x76;
        *(u8 *)(arg1 + 0xD) = 0x40;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0x76;
        *(u8 *)(arg1 + 0x11) = 0x40;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 8:
        *(u8 *)(arg1 + 0) = 0x42;
        *(u8 *)(arg1 + 1) = 0x6D;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0x76;
        *(u8 *)(arg1 + 5) = 0xA3;
        *(u8 *)(arg1 + 6) = 0;
        *(u8 *)(arg1 + 8) = 5;
        *(u8 *)(arg1 + 9) = 0x49;
        *(u8 *)(arg1 + 0xA) = 7;
        *(u8 *)(arg1 + 0xC) = 0x76;
        *(u8 *)(arg1 + 0xD) = 0xA3;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0x76;
        *(u8 *)(arg1 + 0x11) = 0xA3;
        *(u8 *)(arg1 + 0x12) = 0;
        return;
    case 0x10:
        *(u8 *)(arg1 + 0) = 0xAF;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0xB8;
        *(u8 *)(arg1 + 4) = 0xCE;
        *(u8 *)(arg1 + 5) = 0x21;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0x5F;
        *(u8 *)(arg1 + 9) = 0;
        *(u8 *)(arg1 + 0xA) = 0x5C;
        *(u8 *)(arg1 + 0xC) = 0xCE;
        *(u8 *)(arg1 + 0xD) = 0x21;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0xCE;
        *(u8 *)(arg1 + 0x11) = 0x21;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 1:
        *(u8 *)(arg1 + 0) = 0x8E;
        *(u8 *)(arg1 + 1) = 6;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0xFF;
        *(u8 *)(arg1 + 5) = 0x41;
        *(u8 *)(arg1 + 6) = 0x40;
        *(u8 *)(arg1 + 8) = 0x7B;
        *(u8 *)(arg1 + 9) = 0xB;
        *(u8 *)(arg1 + 0xA) = 1;
        *(u8 *)(arg1 + 0xC) = 0xFF;
        *(u8 *)(arg1 + 0xD) = 0x41;
        *(u8 *)(arg1 + 0xE) = 0x40;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0x41;
        *(u8 *)(arg1 + 0x12) = 0x40;
        return;
    case 0x20:
        *(u8 *)(arg1 + 0) = 0x4E;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0xF2;
        *(u8 *)(arg1 + 4) = 0x76;
        *(u8 *)(arg1 + 5) = 0x40;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0xE;
        *(u8 *)(arg1 + 9) = 1;
        *(u8 *)(arg1 + 0xA) = 0x7B;
        *(u8 *)(arg1 + 0xC) = 0x76;
        *(u8 *)(arg1 + 0xD) = 0x40;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0x76;
        *(u8 *)(arg1 + 0x11) = 0x40;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 0x40:
        *(u8 *)(arg1 + 0) = 0x3B;
        *(u8 *)(arg1 + 1) = 0x38;
        *(u8 *)(arg1 + 2) = 0xFF;
        *(u8 *)(arg1 + 4) = 0x59;
        *(u8 *)(arg1 + 5) = 0x57;
        *(u8 *)(arg1 + 6) = 0xE8;
        *(u8 *)(arg1 + 8) = 0xD;
        *(u8 *)(arg1 + 9) = 0x30;
        *(u8 *)(arg1 + 0xA) = 0x6E;
        *(u8 *)(arg1 + 0xC) = 0x59;
        *(u8 *)(arg1 + 0xD) = 0x57;
        *(u8 *)(arg1 + 0xE) = 0xE8;
        *(u8 *)(arg1 + 0x10) = 0x59;
        *(u8 *)(arg1 + 0x11) = 0x57;
        *(u8 *)(arg1 + 0x12) = 0xE8;
        return;
    case 0x80:
        *(u8 *)(arg1 + 0) = 0x96;
        *(u8 *)(arg1 + 1) = 0x96;
        *(u8 *)(arg1 + 2) = 0x96;
        *(u8 *)(arg1 + 4) = 0xFF;
        *(u8 *)(arg1 + 5) = 0xFF;
        *(u8 *)(arg1 + 6) = 0xFF;
        *(u8 *)(arg1 + 8) = 0x2B;
        *(u8 *)(arg1 + 9) = 0x2B;
        *(u8 *)(arg1 + 0xA) = 0x2B;
        *(u8 *)(arg1 + 0xC) = 0xFF;
        *(u8 *)(arg1 + 0xD) = 0xFF;
        *(u8 *)(arg1 + 0xE) = 0xFF;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0xFF;
        *(u8 *)(arg1 + 0x12) = 0xFF;
        return;
    case 0x80000:
        *(u8 *)(arg1 + 0) = 0;
        *(u8 *)(arg1 + 1) = 0;
        *(u8 *)(arg1 + 2) = 0;
        *(u8 *)(arg1 + 4) = 0;
        *(u8 *)(arg1 + 5) = 0;
        *(u8 *)(arg1 + 6) = 0;
        *(u8 *)(arg1 + 8) = 0x53;
        *(u8 *)(arg1 + 9) = 0x53;
        *(u8 *)(arg1 + 0xA) = 0x53;
        *(u8 *)(arg1 + 0xC) = 0;
        *(u8 *)(arg1 + 0xD) = 0;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0x89;
        *(u8 *)(arg1 + 0x11) = 0x89;
        *(u8 *)(arg1 + 0x12) = 0x89;
        return;
    default:
        *(s32 *)(arg1 + 0x14) = 0;
        *(u8 *)(arg1 + 0) = 0xFF;
        *(u8 *)(arg1 + 1) = 0xAF;
        *(u8 *)(arg1 + 2) = 0x20;
        *(u8 *)(arg1 + 4) = 0xFE;
        *(u8 *)(arg1 + 5) = 0xFF;
        *(u8 *)(arg1 + 6) = 0x22;
        *(u8 *)(arg1 + 8) = 0xFF;
        *(u8 *)(arg1 + 9) = 0xFF;
        *(u8 *)(arg1 + 0xA) = 0xFF;
        *(u8 *)(arg1 + 0xC) = 0;
        *(u8 *)(arg1 + 0xD) = 0;
        *(u8 *)(arg1 + 0xE) = 0;
        *(u8 *)(arg1 + 0x10) = 0xFF;
        *(u8 *)(arg1 + 0x11) = 0xAF;
        *(u8 *)(arg1 + 0x12) = 0x20;
        return;
    }
}
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
void func_00216d10(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x85C) = *(u16 *)(p + 0x85C) | 8;
}
// FUN_00216D40
void func_00216d40(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x85C) = *(u16 *)(p + 0x85C) | 4;
}
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
void func_00218160(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;
    s32 value;

    p = func_00452560();
    sub = p + 0x84C;
    *(s16 *)(p + 0x874) = -1;
    *(s32 *)(p + 0x880) = 0;
    *(s32 *)(p + 0x878) = *(s32 *)(p + 0x98);
    value = ((*(u16 *)(*(u8 **)(arg1 + 0x30) + 0xA4) - 2) * 3) + 5;
    *(s32 *)(sub + 0x30) = value + func_00231d70(3);
    *(s32 *)(sub + 0x38) = 0;
    *(s16 *)(sub + 0x2A) = 8;
    func_001f62b0();
    *(u16 *)(sub + 0x10) |= 0x10;
}
// FUN_00218200
s32 func_00218200(void)
{
    return ~(*(s16 *)((u8 *)func_00452560() + 0x874)) != 0;
}
// FUN_00218230
s16 func_00218230(void)
{
    return *(s16 *)((u8 *)func_00452560() + 0x874);
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



// FUN_002182C0
void func_002182c0(u8 *arg0, u8 *arg1)
{
    u8 *p;
    u8 *sub;
    s32 value;

    p = func_00452560();
    sub = p + 0x84C;
    *(s16 *)(p + 0x874) = -1;
    *(s32 *)(p + 0x880) = 0;
    *(s32 *)(p + 0x878) = *(s32 *)(p + 0x98);
    value = ((*(u16 *)(*(u8 **)(arg1 + 0x30) + 0xA4) - 2) * 3) + 0x1A;
    *(s32 *)(sub + 0x30) = value + func_00231d70(3);
    *(s32 *)(sub + 0x38) = 0;
    *(s16 *)(sub + 0x2A) = 8;
    func_001f62b0();
    *(u16 *)(sub + 0x10) |= 0x10;
}
// FUN_00218360
s32 func_00218360(void)
{
    return ~(*(s16 *)((u8 *)func_00452560() + 0x874)) != 0;
}
// FUN_00218390
s16 func_00218390(void)
{
    return *(s16 *)((u8 *)func_00452560() + 0x874);
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
s32 func_002184a0(void)
{
    return ~(*(s16 *)((u8 *)func_00452560() + 0x874)) != 0;
}
// FUN_002184D0
s16 func_002184d0(void)
{
    return *(s16 *)((u8 *)func_00452560() + 0x874);
}
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
void func_00218560(u8 *arg0, u8 *arg1)
{
    u8 *sub;

    sub = func_00452560() + 0x8C0;
    if (func_00106330(0x38) != 0) {
        *(u16 *)sub |= 4;
    } else {
        *(u16 *)sub &= 0xFFFB;
    }
    if (func_00243ce0(*(u8 **)(*(u8 **)(arg1 + 0x30) + 0xA64)) != 0) {
        *(u16 *)sub |= 8;
    } else {
        *(u16 *)sub &= 0xFFF7;
    }
    if (*(u8 *)(*(u8 **)(arg1 + 0x30) + 0xA2) == 1 &&
        (*(u16 *)(iGpffffb3c4 +
                  (*(u16 *)(*(u8 **)(*(u8 **)(arg1 + 0x30) + 0xA64) + 2) * 0x3C)) &
         0x4000) != 0) {
        *(u16 *)sub |= 8;
    }
    func_0045af60(1, 0xE, 2, 0xE);
    *(u16 *)sub &= 0xFFEF;
    *(u8 **)(sub + 8) = arg1;
    *(s16 *)(sub + 2) = 1;
    *(s16 *)(sub + 4) = 0;
}
// FUN_00218690
s32 func_00218690(void)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560() + 0x8C0) & 2) != 0;
    return flag ^ 1;
}
// FUN_002186C0
void func_002186c0(u8 *arg0, s32 arg1) {
    u8 *temp_2;

    temp_2 = (u8 *)func_00452560();
    *(s32 *)(temp_2 + 0x8C8) = arg1;
    *(s16 *)(temp_2 + 0x8C2) = 2;
}

// FUN_00218700
void func_00218700(void)
{
    u8 *p;

    p = func_00452560();
    *(s16 *)(p + 0x8C2) = 4;
}
// FUN_00218730
void func_00218730(void)
{
    u8 *p;

    p = func_00452560();
    *(u16 *)(p + 0x8C0) = *(u16 *)(p + 0x8C0) | 0x10;
}
// FUN_0021A7B0
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021a7b0);
// FUN_0021AE60
void func_0021ae60(u8 *arg0, u8 *arg1)
{
    *(f32 *)(arg1 + 0) = -1.0f;
    *(f32 *)(arg1 + 4) = 1.0f;
    *(s16 *)(arg1 + 0x10) = -1;
}
// FUN_0021AE80
void func_0021ae80(s32 arg0)
{
    func_0021b310(arg0 + 0xA3C);
}
// FUN_0021AEB0
void func_0021aeb0(s32 arg0, u8 *arg1, s32 arg2, f32 fparg0, f32 fparg1, f32 fparg2)
{
    f32 temp_f0;
    f32 var_f20;
    u16 *temp_4;
    u16 *temp_4_2;

    var_f20 = fparg2;
    if (arg2 != 0) {
        temp_4 = *(u16 **)(arg1 + 0xA64);
        if ((temp_4 != NULL) &&
            (func_002428f0((u8 *)temp_4, 0) == 0)) {
            temp_4_2 = *(u16 **)(arg1 + 0xA64);
            if ((*temp_4_2 & 0x20) != 0) {
                if ((func_00231ed0((s32)temp_4_2) & 0xFFFF) <= 1) {
                    goto callback;
                }
            }
            if (!(var_f20 <= 0.0f)) {
                temp_f0 = fGpffff8498;
                if (var_f20 < temp_f0) {
                    var_f20 = temp_f0;
                }
            }
        }
callback:
        func_0021b330(arg0, arg1 + 0xA3C, fparg0, fparg1, var_f20);
    }
}
// FUN_0021AFA0
void func_0021afa0(void)
{
    u8 *p;
    u8 *work;
    u32 i;
s16 value0;
s16 value1;

    i = 0;
    goto outer_test;
outer_body:
    p = *(u8 **)(iGpffffb3ac + (i * 8) + 0x178);
    goto loop_test;
loop_body:
    if (*(u8 **)(p + 0xA64) != NULL) {
        work = p + 0xA28;
        if (*(s16 *)(p + 0xA38) >= 0 &&
            *(s16 *)(p + 0xA38) < 0xC) {
            value0 = (s16)func_00231ed0(*(s32 *)(p + 0xA64));
            value1 = (s16)func_00231f80(*(s32 *)(p + 0xA64));
            *(s16 *)(work + 0x10) = -1;
            *(f32 *)work = -1.0f;
            *(f32 *)(work + 4) = (f32)value0 / (f32)value1;
        }
    }
    p = *(u8 **)(p + 0xA6C);
loop_test:
    if (p != NULL) {
        goto loop_body;
    }
    i++;
outer_test:
    if (i < 2U) {
        goto outer_body;
    }
}
/* MATCHED: unsigned-return conversion idiom and block-scope DatUnit pointer
   declaration reproduce retail exactly; object 240B / window 240B / nd 0.
   A u16 return declaration matches func_00231f80's definition but regresses
   this call site to object 244B / nd 137, so the call-site s32 return view is
   intentional. */
// FUN_0021B0A0
f32 func_0021b0a0(u8 *arg0)
{
    typedef struct DatUnit DatUnit;
    extern s32 func_00231ed0(DatUnit *arg0);
    extern s32 func_00231f80(DatUnit *arg0);
    f32 var_f20;
    f32 var_f0;
    u32 temp_2;
    u32 temp_2_2;

    if (*(s32 *)(arg0 + 0xA64) == 0) {
        return 0.0f;
    }
    temp_2 = (u32)func_00231f80((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f20 = (f32)temp_2;
    if (var_f20 == 0.0f) {
        return 0.0f;
    }
    temp_2_2 = (u32)func_00231ed0((DatUnit *)*(s32 *)(arg0 + 0xA64));
    var_f0 = (f32)temp_2_2;
    return var_f0 / var_f20;
}
// FUN_0021B190
void func_0021b190(u8 *arg0, s32 arg1)
{
    func_0043f9c8(arg0, 0, 4);
    *(s32 *)arg0 = arg1;
}
// FUN_0021B1E0
void func_0021b1e0(void)
{
}
// FUN_0021B1F0
// measured: loop-invariant constant hoisting probe for func_0021b1f0.
#pragma opt_loop_invariants on
void func_0021b1f0(s32 arg0, s32 *arg1)
{
    f32 temp_f0;
    f32 temp_f3;
    s16 temp_3;
    u8 *var_7;
    u32 var_6;
    u8 *temp_5;

    if ((*(s32 *)func_00452560(*arg1) & 1) != 0) {
        var_6 = 0;
        while (var_6 < 2U) {
            var_7 = *(u8 **)(iGpffffb3ac + var_6 * 8 + 0x178);
            while (var_7 != NULL) {
                if (*(s32 *)(var_7 + 0xA64) != 0) {
                    temp_5 = var_7 + 0xA28;
                    temp_f0 = *(f32 *)(var_7 + 0xA28);
                    if (!(temp_f0 < 0.0f)) {
                        *(f32 *)(temp_5 + 0xC) = temp_f0;
                        *(f32 *)(temp_5 + 8) = *(f32 *)(temp_5 + 4);
                        *(s32 *)temp_5 = (s32)0xBF800000;
                        *(s16 *)(temp_5 + 0x10) = 0;
                    }
                    temp_3 = *(s16 *)(temp_5 + 0x10);
                    if (temp_3 >= 0 && temp_3 < 0xD) {
                        if (temp_3 < 0xC) {
                            temp_f3 = *(f32 *)(temp_5 + 8);
                            temp_f0 = (f32)temp_3 / 12.0f;
                            *(f32 *)(temp_5 + 4) =
                                temp_f0 * (*(f32 *)(temp_5 + 0xC) -
                                           temp_f3) +
                                (0.0f + temp_f3);
                        } else {
                            *(f32 *)(temp_5 + 4) = *(f32 *)(temp_5 + 0xC);
                        }
                        *(s16 *)(temp_5 + 0x10) =
                            *(s16 *)(temp_5 + 0x10) + 1;
                    }
                }
                var_7 = *(u8 **)(var_7 + 0xA6C);
            }
            var_6 += 1;
        }
    }
}
// measured: restore loop-invariant baseline after func_0021b1f0.
#pragma opt_loop_invariants off
// FUN_0021B310
void func_0021b310(u8 *arg0, s32 arg1)
{
    if (arg1 != 0) {
        *(s32 *)(arg0 + 0) = 0;
    }
    *(s32 *)(arg0 + 4) = arg1;
}
/* archived body: build/D21B_0021b330_body.c; object 452B; retail window 464B;
   normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C.
   Best legal plain-C body; residual is saved FPU parameter coloring and 12B
   tail padding. */
/* object 452B; retail window 464B; normalized_diff 6; differing offsets 0x28, 0x30, 0xF8, 0x11C, 0x12C, 0x13C; best legal plain-C body; residual is saved FPU parameter-coloring and 12B tail padding. */
// FUN_0021B330
void func_0021b330(s32 arg0, u8 *arg1, f32 fparg0, f32 fparg1, f32 fparg2)
{
    extern f32 fGpffff849c;
    u8 *context;
    s32 value;
    f32 amount;

    context = func_00452560();
    if (*(s32 *)(arg1 + 4) != 0) {
        value = *(s32 *)arg1;
        *(s32 *)arg1 = value + 1;
        amount = (f32)(value + 1) / 4.0f;
        if (amount > 1.0f) {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (amount != 0.0f) {
        fparg1 = (1.0f - amount) * 5.5f + fparg1 + 0.0f;
        func_00201720(context, 1.0f, amount);
        func_00201650(context, 10, 0, fparg0, fparg1, 0x19, 0x19, 0x19, 0xFF);
        if (!(fparg2 <= fGpffff849c)) {
            func_00201720(context, fparg2, amount);
            func_00201650(context, 10, 1,
                          (1.0f - fparg2) * 5.0f + fparg0 + 0.0f,
                          fparg1, 0xFF, 0xFF, 0x51, 0xFF);
        }
        func_00201720(context, 1.0f, 1.0f);
    }
}
// FUN_0021B500
void func_0021b500(u8 *arg0, s32 arg1, f32 fparg0, f32 fparg1,
                   f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5)
{
    union {
        s32 word;
        u8 bytes[4];
    } spC;

    spC.word = arg1;
    *(f32 *)(arg0 + 0) = fparg0;
    *(f32 *)(arg0 + 4) = fparg1;
    *(f32 *)(arg0 + 8) = fparg2;
    *(f32 *)(arg0 + 0x20) = (f32)(u32)spC.bytes[0];
    *(f32 *)(arg0 + 0x24) = (f32)(u32)spC.bytes[1];
    *(f32 *)(arg0 + 0x28) = (f32)(u32)spC.bytes[2];
    *(f32 *)(arg0 + 0x2C) = (f32)(u32)spC.bytes[3];
    *(f32 *)(arg0 + 0x10) = fparg3;
    *(f32 *)(arg0 + 0x14) = fparg4;
    *(f32 *)(arg0 + 0x18) = fparg5;
}
// FUN_0021B630
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021b630);
// FUN_0021BBB0
void func_0021bbb0(s32 arg0, u16 arg1)
{
    extern void (*D_00887300[])(s32 arg0, s32 arg1);
    extern void func_00365f00(f32 f0, s64 arg0, s32 arg1, s32 arg2,
                              f32 f1, f32 f2, s32 arg3, f32 f3, s32 arg4,
                              f32 f4);
    extern void func_003f6440(s32 arg0, s32 arg1);
    extern void func_0045c870(u8 *arg0, s32 arg1);
    extern void func_00489f80(void);
    extern void func_0048a000(void);
    extern f32 fGpffff84a4;
    extern f32 fGpffff84cc;
    union {
        f32 value;
        u8 bytes[4];
    } color;
    union {
        f32 f;
        s32 i;
    } color_value;
    union {
        f32 f;
        s32 i;
    } arg_color_copy;
    struct {
        s32 low;
        s32 high;
    } coords;
    f32 scale;

    coords.low = 0x43A00000;
    coords.high = 0x43640000;
    D_00887300[0](1, 0);
    arg1 = arg1 & 0xFFFF;
    if ((arg1 >= 0x21) && (arg1 < 0x30)) {
        color.bytes[0] = 0;
        color.bytes[1] = 0;
        color.bytes[2] = 0;
        scale = 400.0f *
                (1.0f - func_0044b610(
                    fGpffff84a4 * ((f32)(arg1 - 0x21) / 15.0f)));
        func_00489f80();
        func_003f6440(3, 0x31801);
        color.bytes[3] = 0;
        func_0045c870(color.bytes, 0);
        color.bytes[3] = 0xFF;
        color_value.f = color.value;
        func_00365f00(0.0f, *(s64 *)&coords,
                      color_value.i, color_value.i,
                      scale, 0.0f, 0x24, fGpffff84cc, 0, 1.0f);
        func_0048a000();
        func_003f6440(3, 0x37801);
    }
    if (arg1 >= 3) {
        if (arg1 < 0x21) {
            func_003f6440(2, 0x48);
            scale = 400.0f *
                    func_0044b7b0(
                        fGpffff84a4 * ((f32)(arg1 - 3) / 30.0f));
            arg_color_copy.f = *(f32 *)&arg0;
            func_00365f00(0.0f, *(s64 *)&coords,
                          arg_color_copy.i, arg_color_copy.i,
                          scale, 0.0f, 0x24, fGpffff84cc, 0, 1.0f);
            func_003f6440(2, 0x44);
        } else if (arg1 < 0x30) {
            func_003f6440(2, 0x48);
            func_0045c870((u8 *)&arg0, 0);
            func_003f6440(2, 0x44);
        }
    }
}
// FUN_0021BE10
void func_0021be10(u8 *arg0, s32 arg1)
{
    func_0043f9c8(arg0, 0, 0xC);
    *(s32 *)(arg0 + 8) = arg1;
    *(s16 *)(arg0 + 4) = 1;
}
// FUN_0021BE60
s32 func_0021be60(void)
{
    return iGpffffb470;
}
// FUN_0021BE70
void func_0021be70(void)
{
}
// FUN_0021BE80
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021be80);
// FUN_0021D440
void func_0021d440(void)
{
    u8 *p;

    p = func_00452560();
    *(s16 *)(p + 0x9E6) = 0;
    *(u16 *)(p + 0x9E4) = *(u16 *)(p + 0x9E4) | 1;
}
// FUN_0021D470
s32 func_0021d470(void)
{
    s32 flag;

    flag = (*(u16 *)((u8 *)func_00452560() + 0x9E4) & 1) != 0;
    return flag ^ 1;
}
// FUN_0021D4A0
s32 func_0021d4a0(s32 arg0)
{
    extern s32 func_0036e8a0(s32 arg0);
    extern s32 func_002218e0(s32 arg0);
    extern void func_0036e7e0(s32 arg0);
    extern void func_0021e110(u8 *arg0, u8 *arg1);
    extern s32 func_002216b0(s32 arg0);
    extern s32 func_0036e840(s32 arg0);
    extern void func_0036e810(s32 arg0);
    extern s32 func_00221740(s32 arg0);
    extern void func_002216e0(s32 arg0);
    extern s32 func_002230e0(s32 arg0);
    extern s32 func_00223730(s32 arg0);
    extern s32 func_00223f40(s32 arg0);
    extern s32 func_00223240(s32 arg0);
    extern void func_002231e0(s32 arg0);
    extern s32 func_00223890(s32 arg0);
    extern void func_00223830(s32 arg0);
    extern s32 func_00224080(s32 arg0);
    extern void func_00224040(s32 arg0);
    extern s32 func_0036e8d0(void);
    extern s32 func_00221910(void);
    extern s32 func_00223270(void);
    extern s32 func_002238c0(void);
    extern s32 func_002240b0(void);
    u8 *work;
    s32 flags;
    s32 ready;

    work = func_00452560();
    switch (*(s32 *)(work + 4)) {
    case 1:
        *(s32 *)(work + 4) = 2;
        break;
    case 2:
        flags = *(s32 *)work;
        if ((flags & 1) == 0 || (flags & 4) == 0) {
            if ((flags & 2) != 0) {
                ready = 1;
                if ((*(s32 *)(work + 0x60) & 1) != 0 &&
                    func_0036e8a0(*(s32 *)(work + 0x938)) != 0) {
                    ready = 0;
                }
                if (func_002218e0(*(s32 *)(work + 0x93C)) != 0) {
                    ready = 0;
                }
                if (ready != 0) {
                    flags = *(s32 *)work;
                    flags &= ~2;
                    *(s32 *)work = flags;
                    flags |= 4;
                    *(s32 *)work = flags;
                }
            }
            break;
        }
    case 3:
        flags = *(s32 *)(work + 0x60);
        if ((flags & 1) != 0) {
            func_0036e7e0(*(s32 *)(work + 0x938));
            *(s32 *)(work + 4) = 4;
        } else {
            func_0021e110(work + 0x60, work + 8);
            func_002216b0(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 4) = 5;
        }
        break;
    case 4:
        if (func_0036e840(*(s32 *)(work + 0x938)) == 0) {
            func_0036e810(*(s32 *)(work + 0x938));
            *(s32 *)(work + 0x938) = 0;
            func_0021e110(work + 0x60, work + 8);
            func_002216b0(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 4) = 5;
        }
        break;
    case 5:
        if (func_00221740(*(s32 *)(work + 0x93C)) == 0) {
            func_002216e0(*(s32 *)(work + 0x93C));
            *(s32 *)(work + 0x93C) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 2) != 0) {
                func_0021e9a0(work + 0x60, work + 8);
                *(s32 *)(work + 0x940) = func_002230e0(arg0);
                *(s32 *)(work + 4) = 6;
            } else if ((flags & 8) != 0) {
                func_0021e9a0(work + 0x60, work + 8);
                *(s32 *)(work + 0x944) = func_00223730(arg0);
                *(s32 *)(work + 4) = 7;
            } else if ((flags & 0x10) != 0) {
                func_0021e9a0(work + 0x60, work + 8);
                func_0021eb60(work + 0x60);
                *(s32 *)(work + 0x948) = func_00223f40(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
                func_0021e9a0(work + 0x60, work + 8);
                func_0021eb60(work + 0x60);
                func_0021ec40((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 6:
        if (func_00223240(*(s32 *)(work + 0x940)) == 0) {
            func_002231e0(*(s32 *)(work + 0x940));
            *(s32 *)(work + 0x940) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 8) != 0) {
                *(s32 *)(work + 0x944) = func_00223730(arg0);
                *(s32 *)(work + 4) = 7;
            } else if ((flags & 0x10) != 0) {
                func_0021eb60(work + 0x60);
                *(s32 *)(work + 0x948) = func_00223f40(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
                func_0021eb60(work + 0x60);
                func_0021ec40((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 7:
        if (func_00223890(*(s32 *)(work + 0x944)) == 0) {
            func_00223830(*(s32 *)(work + 0x944));
            *(s32 *)(work + 0x944) = 0;
            flags = *(s32 *)(work + 0x60);
            if ((flags & 0x10) != 0) {
                *(s32 *)(work + 0x948) = func_00223f40(arg0);
                *(s32 *)(work + 4) = 8;
            } else {
            func_0021ec40((s32)(work + 0x60));
                *(s32 *)(work + 4) = 9;
            }
        }
        break;
    case 8:
        if (func_00224080(*(s32 *)(work + 0x948)) == 0) {
            func_00224040(*(s32 *)(work + 0x948));
            *(s32 *)(work + 0x948) = 0;
            *(s32 *)(work + 4) = 9;
        }
        break;
    case 9:
        if (func_0036e8d0() == 0 &&
            func_00221910() == 0 &&
            func_00223270() == 0 &&
            func_002238c0() == 0 &&
            func_002240b0() == 0) {
            *(s32 *)(work + 4) = 0;
        }
        break;
    }
    return 0;
}
// FUN_0021D920
void func_0021d920(void)
{
    u8 *p;
    s32 value;

    p = func_00452560();
    value = *(s32 *)(p + 0x934);
    if (value != 0) {
        func_00454bd0((u8 *)value);
    }
    jtbl_008873EC[0](p);
}
// FUN_0021D980
s32 func_0021d980(s32 arg0, u16 *arg1)
{
    u8 *work;
    s32 result;

    func_0044ea90(&D_006290D0, 0x3A);
    work = (u8 *)jtbl_008873E8[0](0x94C, 0x40000);
    func_0043f9c8(work, 0, 0x94C);
    result = func_00451fc0(arg0, &D_006290C0, 0xF, 0, 0,
                           (void *)func_0021d4a0, (void *)func_0021d920, work);
    func_0043f810(work + 8, arg1, 0x58);
    if ((*arg1 & 1) != 0) {
        *(s32 *)(work + 0x60) |= 1;
    }
    *(s32 *)(work + 4) = 1;
    if ((*(s32 *)(work + 0x60) & 1) != 0) {
        *(s32 *)(work + 0x938) = func_0036e690(result, work + 0x48);
    }
    *(s32 *)(work + 0x93C) = func_002215c0(result);
    return result;
}
// FUN_0021DAB0
void func_0021dab0(void)
{
    u8 *p;

    p = func_00452560();
    if ((*(s32 *)(p + 0x60) & 1) != 0) {
        func_0036e870(*(s32 *)(p + 0x938));
    }
    func_00221770(*(s32 *)(p + 0x93C));
    *(s32 *)p |= 2;
}
// FUN_0021DB10
s32 func_0021db10(void)
{
    return (*(s32 *)func_00452560() & 2) != 0;
}
// FUN_0021DB40
s32 func_0021db40(void)
{
    u8 *p;
    s32 temp;

    p = func_00452560();
    if (*(s32 *)(p + 0x938) != 0) {
        return 0;
    }
    temp = *(s32 *)(p + 0x93C);
    if (temp != 0) {
        return func_00221940(temp);
    }
    return 0;
}
// FUN_0021DBA0
s32 func_0021dba0(void)
{
    u8 *p;
    s32 value;

    p = func_00452560();
    *(s32 *)(p + 4) = 0;
    *(s32 *)(p + 8) = 0;
    func_00460ac0(&D_00796340, p + 4);
    value = *(s32 *)p + 1;
    *(s32 *)p = value;
    if (value == 0xC) {
        func_00122520(1, 1);
        goto exit;
    }
    if (value <= 0xC) {
        goto exit;
    }
    if (func_00122720() != 0) {
        return -1;
    }
exit:
    return 0;
}
// FUN_0021DC50
void func_0021dc50(s32 arg0, s32 *arg1)
{
    f32 var_f20;
    f32 temp_f0;
    f32 temp_f1;
    f32 sp38[2];
    f32 var_f1;

    func_00201350();
    var_f20 = (f32)*(s32 *)(arg1 + 0) / 12.0f;
    if (!(var_f20 <= 1.0f)) {
        var_f20 = 1.0f;
    }
    sp38[0] = 0.0f;
    sp38[1] = -500.0f;
    sp38[0] = sp38[0] + var_f20 * (800.0f * func_0044b7b0(fGpffff837c));
    temp_f0 = func_0044b610(fGpffff837c);
    temp_f1 = 800.0f * temp_f0;
    sp38[1] = sp38[1] + var_f20 * temp_f1;
    func_00364c90(*(s64 *)sp38, 0xFF, 0.0f,
                  1500.0f, 1000.0f, fGpffff8378, 0);
}
// FUN_0021DDA0
void func_0021dda0(void)
{
    u8 *work;

    if (func_00452380(&D_006290E0) == 0) {
        func_0044ea90(&D_006290D0, 0x3A);
        work = (u8 *)jtbl_008873E8[0](0x34, 0x40000);
        func_0043f9c8(work, 0, 0x34);
        func_00451de0(&D_006290E0, 0x10, 0, 0,
                      (void *)func_0021dba0, (void *)func_0021dd60, work);
        *(void **)(work + 0xC) = (void *)func_0021dc50;
        *(u8 **)(work + 0x14) = work;
    }
}
// FUN_0021DE60
s32 func_0021de60(void)
{
    return func_00452380(&D_006290E0) == 0;
}
/* measured: plain-C reconstruction reaches object size 440B against the
   448B retail window at normalized_diff 16. The complete control flow,
   conversion/clamp logic, and GP table accesses match; residuals are the
   table-float load versus integer-to-float conversion scheduling (retail
   loads the table value first) plus the eight-byte retail tail pad. Parked
   because nd <= 25. Committed at nd 16. */
/* measured: artifact replay produced object_size 456B against the 448B retail window, normalized_diff 303, and 108 differing words (reloc-masked). */
// FUN_0021DE90 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021de90);
// FUN_0021E050
s32 func_0021e050(u8 *arg0)
{
    s32 value;

    value = *(s32 *)(arg0 + 8);
    if (value <= 0) {
        return 0;
    }
    if ((*(u16 *)arg0 & 8) == 0 && (func_00106330(0x1403) != 0)) {
        if (func_00106330(0x1420) != 0) {
            value = (s32)(2.0f * (f32)value);
        } else if (func_00106330(0x1421) != 0) {
            value = 1;
        }
    }
    return value;
}
// FUN_0021E110
INCLUDE_ASM("asm/nonmatchings/code1_0021", func_0021e110);
/* measured: plain-C reconstruction reaches object size 448B against the
   448B retail window at normalized_diff 7. The prologue, calls, loop
   addressing, and arithmetic all match; the residual is register naming in
   the final sign-extension/clamp sequence. Re-measured at nd 94 after later
   declaration-environment changes in this file. */
/* measured: the per-slot clamp must be one s16 local (`sum`, compared with `> 0x63`):
   the dsll32/dsra32 canonicalisation, slti and li then share $v0 as retail; an s32
   temporary with an (s16) compare colours the sign-extension into $v1. The named
   call-result operand on the left keeps the addu order (v1 + v0). */
// FUN_0021E9A0
void func_0021e9a0(u8 *arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_2;
    s32 var_16;
    s32 var_17;
    u8 *temp_19;
    u8 *temp_20;
    s32 temp_21;
    s16 sum;
    temp_17 = (s32)func_00105510(1);
    temp_2 = (s32)func_00105210(1);
    if ((func_001059e0(temp_2) & 0xFF) < 0x63) {
        temp_16 = temp_2 + *(s32 *)(arg0 + 4);
        func_00105990(1, temp_16);
        func_00231ef0((u8 *)temp_17, func_001059e0(temp_16));
    }
    var_16 = *(s32 *)(arg1 + 8);
    if (var_16 <= 0) {
        var_16 = 0;
    } else if ((*(u16 *)arg1 & 8) == 0 && func_00106330(0x1403) != 0) {
        if (func_00106330(0x1420) != 0) {
            var_16 = (s32)(2.0f * (f32)var_16);
        } else if (func_00106330(0x1421) != 0) {
            var_16 = 1;
        }
    }
    func_00106020(var_16);
    var_17 = 0;
    while (var_17 < *(s32 *)(arg1 + 0x30)) {
        temp_19 = arg1 + var_17 * 4;
        temp_20 = temp_19 + 0x24;
        temp_21 = (s16)(func_00106600(*(s16 *)(temp_19 + 0x24)) & 0xFF);
        sum = temp_21 + *(s16 *)(temp_19 + 0x26);
        if (sum > 0x63) {
            sum = 0x63;
        }
        func_00106620(*(s16 *)temp_20, (u8)sum);
        var_17 += 1;
    }
}
// FUN_0021EB60
void func_0021eb60(u8 *arg0)
{
    s32 limit;
    s32 value;
    u8 *persona;
    s32 i;

    limit = func_0010b6f0() & 0xFFFF;
    i = 0;
    while (i < limit) {
        value = *(s32 *)(arg0 + (i * 4) + 8);
        if (value != 0) {
            persona = func_0010ace0((s64)(s16)i);
            func_0010c980(persona, value);
            if (func_0010c6f0(persona) != 0) {
                func_0010c5a0(persona, arg0 + (i * 0x88) + 0x38);
            }
        }
        i += 1;
    }
}
// FUN_0021EC40
void func_0021ec40(s32 arg0)
{
    s32 temp_2;
    s32 temp_19;
    s32 var_16;

    var_16 = 0;
    goto loop_test;
loop_body:
    temp_19 = *(s32 *)((u8 *)arg0 + (var_16 * 4) + 0x6A4);
    if (temp_19 != 0) {
        temp_2 = (s32)func_0010a900(*(u16 *)((u8 *)arg0 + (var_16 * 2) + 0x69A));
        func_0010c980((u8 *)temp_2, temp_19);
        if (func_0010c6f0((u8 *)temp_2) != 0) {
            func_0010c5a0((u8 *)temp_2,
                          (u8 *)arg0 + (var_16 * 0x88) + 0x6B4);
        }
    }
    var_16 += 1;
loop_test:
    if (var_16 < 4) {
        goto loop_body;
    }
}

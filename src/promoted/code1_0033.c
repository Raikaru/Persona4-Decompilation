#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

// P4 retail reaches the battle-data object pointer at gp-0x4A68,
// i.e. absolute 0x007690f0 - 0x4a68 = 0x00764688, GP-relative.
extern int iGpffffb598;
extern u16 D_008C024E[];
extern s32 func_0029cc00(s32 arg0);
extern s32 func_00106330(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern u32 func_002e7a60(void);

typedef struct {
    s32 lo;
    s32 hi;
} S8iodata;

extern void func_00364320(S8iodata arg0, s32 arg1, s32 arg2, f32 fparg0);

void func_002b82d0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5);

void func_002b8340(u8 *arg0, s8 arg1, s16 arg2, s16 arg3,
                    f32 fparg0, f32 fparg1);
extern void func_002b8300(u8 *arg0, s8 arg1, s16 arg2, s16 arg3,
 f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern void func_0046b0d0(void *ptr);

typedef struct {
    f32 x;
    f32 y;
} F2_0033;

typedef struct {
    s32 sp30;
    s16 sp34;
    s16 pad36;
    s32 sp38;
    s32 sp3c;
} D9D0Locals;

extern void func_002bdea0(void);
extern void func_00308f40(void);
extern void (*D_00887300[])(s32, s32);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_002b8270(u8 *arg0, F2_0033 arg1, F2_0033 arg2,
                           u32 arg3, s32 arg4, s32 arg5);

extern void func_00457140(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s8 iGpffffb59c;
extern s32 func_00452380(const void *arg0);
extern s32 func_0015f660(void);
extern void func_001029a0(s32 arg0, void *arg1, s32 arg2, s32 arg3);
extern void func_001238c0(s32 arg0);
extern u8 D_00644E80[];
extern u8 D_00644E98[];
extern u8 D_00644EB0[];
extern void func_0044ea90(const void *arg0, s32 arg1);
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3,
                         s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern s32 func_0046aea0(void *arg0);
extern u8 D_0064A458[];
extern u8 D_0064A470[];
extern u8 D_0064A480[];
extern s32 func_0033e1e0(u8 *arg0);
extern void func_0033e4b0(u8 *arg0);
extern s32 func_002b2a30(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern f32 func_002b2aa0(s32 arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3);
extern s32 func_002b2cb0(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s16 func_002b2d00(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s8 arg4);
extern s32 func_0046a750(s32 arg0, s32 arg1);
extern s32 func_002859e0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00293ed0(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 func_00293fc0(s32 arg0);
extern s32 func_002940a0(s32 arg0, s32 *arg1, s32 *arg2,
                         s16 *arg3, s32 *arg4);
extern void func_00144c90(s32 arg0, s32 arg1);
extern void func_00144e10(s32 arg0);
extern void func_00144ed0(s32 arg0);
extern s32 func_00144f60(void);
extern void func_00452080(s32 arg0);
extern s32 func_00452490(s32 arg0);
extern u8 *func_00457120(void);
extern void func_004577d0(u8 *arg0, f32 arg1);
extern f32 func_0014b4d0(void);
extern s32 func_0014b450(void);
extern void func_003e9cb0(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00122720(void);
extern s32 func_0033de90(u8 *arg0, s32 arg1);
extern void func_0025ecd0(f32 fparg0, f32 fparg1,
                           s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                           s32 arg4, s32 arg5, s32 arg6,
                           f32 fparg2, f32 fparg3, f32 fparg4, f32 fparg5,
                           void *arg7);
extern u8 D_007955C0[];



// FUN_00331560
s32 func_00331560(void)
{
    return *(s32 *)(*(int *)(iGpffffb598 + 0x38) + 4);
}



// FUN_00331580
s32 func_00331580(void)
{
    return *(s8 *)(*(int *)(iGpffffb598 + 0x38)) == 6;
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



// FUN_00331680
s32 func_00331680(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (func_0015f660() != 0) {
            func_00457140(0, 0, 0, 0xFF);
            func_001029a0(0x16, 0, 0, 2);
            func_001238c0(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
        iGpffffb59c += 1;
        break;
    case 2:
        if (func_00452380(D_00644E80) == 0) {
            func_001238c0(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00331770
s32 func_00331770(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (func_0015f660() != 0) {
            func_00457140(0, 0, 0, 0xFF);
            func_001029a0(0x17, 0, 0, 2);
            func_001238c0(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
        iGpffffb59c += 1;
        break;
    case 2:
        if (func_00452380(D_00644E98) == 0) {
            func_001238c0(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00331860
s32 func_00331860(void)
{
    switch (iGpffffb59c) {
    case 0:
        if (func_0015f660() != 0) {
            func_00457140(0, 0, 0, 0xFF);
            func_001029a0(0x18, 0, 0, 2);
            func_001238c0(0);
            iGpffffb59c += 1;
        }
        break;
    case 1:
        iGpffffb59c += 1;
        break;
    case 2:
        if (func_00452380(D_00644EB0) == 0) {
            func_001238c0(1);
            iGpffffb59c = 0;
            return 1;
        }
        break;
    case 3:
    case 4:
    case 5:
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
// FUN_00331950
s32 func_00331950(void)
{
    func_002bdea0();
    func_00308f40();
    return 1;
}
// FUN_00331980
s32 func_00331980(void)
{
    return func_00106330(func_0029cc00(0)) != 0;
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

// FUN_00331A20
INCLUDE_ASM("asm/nonmatchings/code1_0033", func_00331a20);
// FUN_00331F90
void func_00331f90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// FUN_00332A80
void func_00332a80(void)
{
    void (**tbl)(s32, s32);

    tbl = (void (**)(s32, s32))(u32)D_00887300;
    tbl[0](6, 1);
    tbl[0](8, 1);
    tbl[0](0xC, 1);
    tbl[0](7, 2);
    tbl[0](9, 2);
    tbl[0](2, 4);
    tbl[0](0xE, 0);
    func_003f6440(2, 0x44);
    func_003f6440(3, 0x7100D);
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

// FUN_0033D390
s32 func_0033d390(u8 *arg0, s32 arg1)
{
    return (*(s16 *)(*(u8 **)(arg0 + 0x38) + 4) & ((1 << arg1) & 0xFFFF)) >> arg1;
}
// FUN_0033D3C0
void func_0033d3c0(u8 *arg0, f32 arg1)
{
    *(f32 *)(*(u8 **)(arg0 + 0x38) + 8) = arg1;
}
// FUN_0033D3D0
void func_0033d3d0(u8 *arg0, s32 arg1)
{
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xFC) = arg1;
}

// FUN_0033D3E0
void func_0033d3e0(u8 *arg0, F2_0033 p1, F2_0033 p2,
                   u32 arg3, u32 arg4, s16 arg5)
{
    func_002b8270(*(u8 **)(arg0 + 0x38) + 4, p1, p2, arg3, arg4, arg5);
}
// FUN_0033D420
void func_0033d420(u8 *arg0, F2_0033 p1, F2_0033 p2,
                   u32 arg3, s8 arg4, u32 arg5, s16 arg6)
{
    u8 *p;

    p = *(u8 **)(arg0 + 0x38);
    func_002b8270(p + 4, p1, p2, arg3, arg5, arg6);
    *(s8 *)(p + 0x3B) = arg4;
    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) |= 0x400;
    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) &= (s16)~2;
}
// FUN_0033D4B0
void func_0033d4b0(u8 *arg0, s8 arg1, s8 arg2, s8 arg3, s16 arg4, s64 arg5)
{
    func_002b82d0(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, arg4, arg5);
}

// FUN_0033D4E0
void func_0033d4e0(u8 *arg0, s8 arg1, s16 arg2, s64 arg3, f32 fparg0, f32 fparg1)
{
    func_002b8300(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3,
                   fparg0, fparg1, fparg0, fparg1);
}
// FUN_0033D520
void func_0033d520(u8 *arg0, s8 arg1, s16 arg2, s64 arg3, f32 fparg0, f32 fparg1)
{
    func_002b8340(*(u8 **)(arg0 + 0x38) + 4, arg1, arg2, arg3, fparg0, fparg1);
}

// FUN_0033D550
/* measured: opt_propagation off preserves the per-call field loads and the
   argument materialisation order for func_002b8300. */
#pragma opt_propagation off
void func_0033d550(u8 *arg0)
{
    extern void func_002b82d0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3,
                               s16 arg4, s16 arg5);
    extern void func_002b8300(u8 *arg0, f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                               s8 arg1, s16 arg2, s16 arg3);
    s16 h;
    u8 b1;
    u8 b2;
    f32 f0;
    f32 f1;
    u8 *p;

    *(s16 *)(*(u8 **)(arg0 + 0x38) + 4) |= 1;

    func_002b8270(*(u8 **)(arg0 + 0x38) + 4,
                  *(F2_0033 *)(*(u8 **)(arg0 + 0x38) + 0x2C),
                  *(F2_0033 *)(*(u8 **)(arg0 + 0x38) + 0x1C),
                  0,
                  *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x36),
                  0);

    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x5E);
    p = *(u8 **)(arg0 + 0x38) + 4;
    b1 = *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x62);
    b2 = *(u8 *)(*(u8 **)(arg0 + 0x38) + 0x60);
    func_002b82d0(p, b1, b2, 0, h, 0);

    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0xC8);
    p = *(u8 **)(arg0 + 0x38) + 4;
    f0 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0xC4);
    f1 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0xBC);
    func_002b8340(p, 0, h, 0, f0, f1);

    f1 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x8C);
    f0 = *(f32 *)(*(u8 **)(arg0 + 0x38) + 0x94);
    h = *(s16 *)(*(u8 **)(arg0 + 0x38) + 0x88);
    p = *(u8 **)(arg0 + 0x38) + 4;
    func_002b8300(p, f0, f1, f0, f1, 0, h, 0);
}
/* measured: restore opt_propagation for the rest of the translation unit. */
#pragma opt_propagation on
// FUN_0033D630
INCLUDE_ASM("asm/nonmatchings/code1_0033", func_0033d630);
// FUN_0033D9D0
 s32 func_0033d9d0(u8 *arg0)
 {
     D9D0Locals locals;
     s32 temp_4_2;
     s8 temp_4;
     u8 *temp_16;
     u8 *temp_17;
     u8 *temp_17_2;

     temp_16 = *(u8 **)(arg0 + 0x38);
     temp_4 = *(s8 *)temp_16;
     switch (temp_4) {
     case 0:
         *(s32 *)(temp_16 + 4) = func_00293ed0(
             0x5A, *(s8 *)(temp_16 + 0x10) + 1, 0, 0);
         *(s8 *)temp_16 = *(s8 *)temp_16 + 1;
     default:
         goto out;
     case 1:
         if ((func_00293fc0(*(s32 *)(temp_16 + 4)) != 0) &&
             (func_002940a0(*(s32 *)(temp_16 + 4), &locals.sp3c,
                            &locals.sp38, &locals.sp34, &locals.sp30) == 1)) {
             func_00144c90(locals.sp3c, locals.sp38);
             func_00144e10(locals.sp34);
             func_00144ed0(3);
             *(s8 *)temp_16 = *(s8 *)temp_16 + 1;
         }
         goto out;
     case 2:
         if (func_00144f60() != 0) {
             *(s32 *)(temp_16 + 8) = func_002859e0(
                 0x5A, *(s8 *)(temp_16 + 0x10) + 1, 0);
             *(s32 *)(temp_16 + 0xC) = func_0033de90(arg0, 0x58);
             *(s8 *)temp_16 = *(s8 *)temp_16 + 1;
         }
         goto out;
     case 3:
         if (func_00452490(*(s32 *)(temp_16 + 8)) != 1) {
             temp_4_2 = *(s32 *)(temp_16 + 4);
             if (temp_4_2 != 0) {
                 func_00452080(temp_4_2);
             }
             *(s8 *)temp_16 = *(s8 *)temp_16 + 1;
         }
         goto out;
     case 4:
     case 5:
         *(s8 *)temp_16 = (s8)(temp_4 + 1);
         goto out;
     case 6:
         func_00144c90(8, 3);
         func_00144e10(1);
         *(s8 *)temp_16 = *(s8 *)temp_16 + 1;
         goto out;
     case 7:
         if (func_00144f60() == 0) {
             goto out;
         }
         if (func_0015f660() == 0) {
             goto out;
         }
         temp_17 = func_00457120();
         func_004577d0(temp_17, func_0014b4d0());
         temp_17_2 = func_00457120();
         func_003e9cb0(*(s32 *)(temp_17_2 + 4), func_0014b450(), 0);
         func_00122640(1, 0xA);
         *(s8 *)temp_16 = *(s8 *)temp_16 + 1;
     case 8:
         if (func_00122720() != 0) {
             return -1;
         }
         goto out;
     out:
         return 0;
     }
 }
// FUN_0033DC60
void func_0033dc60(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0033E1E0
s32 func_0033e1e0(u8 *arg0)
{
    u8 *p;
    s16 value;

    p = *(u8 **)(arg0 + 0x38);
    switch (*(s8 *)p) {
    case 0:
        if (func_0046a750(*(s32 *)(p + 4), 3) == 0) {
            return 0;
        }
        *(s8 *)p = 1;
        break;
    case 1:
        break;
    default:
        break;
    case 2:
        if (*(s16 *)(p + 0x24) > *(s16 *)(p + 0x26)) {
            goto update;
        }
        *(s8 *)p = 3;
        if (*(f32 *)(p + 0x1C) >= 640.0f) {
            *(s8 *)p = 1;
            return 0;
        }
    update:
        *(f32 *)(p + 0x1C) = func_002b2aa0(
            *(s8 *)(p + 0x2A), *(f32 *)(p + 0x0C), *(f32 *)(p + 0x14),
            (f32)*(s16 *)(p + 0x26), (f32)*(s16 *)(p + 0x24));
        *(f32 *)(p + 0x20) = func_002b2aa0(
            *(s8 *)(p + 0x2A), *(f32 *)(p + 0x10), *(f32 *)(p + 0x18),
            (f32)*(s16 *)(p + 0x26), (f32)*(s16 *)(p + 0x24));
        value = *(s16 *)(p + 0x28);
        if (value > 0) {
            *(s16 *)(p + 0x28) = func_002b2d00(value, 1, 0, 0, 1);
        } else {
            *(s16 *)(p + 0x26) = func_002b2cb0(
                *(s16 *)(p + 0x26), 1, *(s16 *)(p + 0x24), 0, 1);
        }
        func_0033e4b0(arg0);
        break;
    case 3:
        func_0033e4b0(arg0);
        break;
    }
    return 0;
}
// FUN_0033E3A0
void func_0033e3a0(u8 *arg0)
{
    func_0046b0d0((void *)*(u8 **)(*(u8 **)(arg0 + 0x38) + 4));
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
// FUN_0033E3F0
s32 func_0033e3f0(u8 *arg0)
{
    s32 result;
    u8 *work;

    func_0044ea90(D_0064A458, 0x85);
    work = D_008873F4[0](1, 0x2C, 0x40000);
    result = func_00451fc0(arg0, D_0064A470, 0xF, 0, 0,
                           (void *)func_0033e1e0, (void *)func_0033e3a0,
                           work);
    work[0] = 0;
    *(s32 *)(work + 4) = func_0046aea0(D_0064A480);
    return result;
}
// FUN_0033E4B0
void func_0033e4b0(u8 *arg0)
{
    u8 *work;
    s32 color;
    f32 x;
    f32 y;

    work = *(u8 **)(arg0 + 0x38);
    color = func_002b2a30(0xFF, 0xFF, 0xFF, 0xFF);
    x = *(f32 *)(work + 0x1C);
    y = *(f32 *)(work + 0x20);
    func_0025ecd0(x, y, color, 0xFF, 1, *(s32 *)(work + 4),
                  1, 0, 0, 104.0f, 0.0f, 1.0f, 1.0f, D_007955C0);
}
// FUN_0033E540
void func_0033e540(u8 *arg0, F2_0033 arg1, F2_0033 arg2, s16 arg3, s16 arg4)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x38);
    *(F2_0033 *)(temp_4 + 0x1C) = arg1;
    *(F2_0033 *)(temp_4 + 0x0C) = *(F2_0033 *)(temp_4 + 0x1C);
    *(F2_0033 *)(temp_4 + 0x14) = arg2;
    *(s16 *)(temp_4 + 0x24) = arg3;
    *(s16 *)(temp_4 + 0x26) = 0;
    *(s16 *)(temp_4 + 0x28) = arg4;
    *(s8 *)temp_4 = 2;
}
// FUN_0033E5A0
s32 func_0033e5a0(u8 *arg0)
{
    return *(s8 *)(*(u8 **)(arg0 + 0x38)) != 0;
}

#include "include_asm.h"
#include "type.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern s32 func_00106330(s32 arg0);
extern s32 func_00273970(u8 *arg0);
extern void func_0026d810();
extern s32 func_00451fc0(s32 arg0, void *arg1, s32 arg2, s32 arg3,
                         s32 arg4, void (*arg5)(void), void (*arg6)(void),
                         s32 arg7);
extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 func_0026db60(void);
extern void func_0026dc30(void);
extern s32 func_0026dee0(void);
extern u8 *func_001452b0(s32 arg0);
extern void func_0026dd60(u8 *arg0);
extern void func_0026d440(void);
extern void func_0026a020(u8 *arg0);
extern void func_0026c310(u8 *arg0);
extern void func_004b11d0(void *arg0, s32 arg1);
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void func_00440bb8(u32 *arg0, s32 arg1, s32 arg2,
                           s32 (*arg3)(u8 **arg0, u8 **arg1));
extern void func_0044ea90(void *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern void func_0043f9c8(void *arg0, void *arg1, s32 arg2);
extern u8 D_0088152F[];
extern s32 D_00638FD0[];
extern s32 D_00639020[];
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;
static inline f32 func_00263220_mul(f32 left, f32 right)
{
    return left * right;
}
extern void func_00267b20(s32 arg0, s32 arg1, s32 arg3,
                          s64 arg4, s64 arg5,
                          f32 fparg0, f32 fparg1, f32 fparg2,
                          f32 fparg3, f32 fparg4, f32 fparg5);
typedef struct {
    s32 stack40[0x13];
    u8 pad8C[4];
    s32 stack90[0x13];
    u8 padDC[4];
    f32 pos[3];
    f32 spEC;
} Code1_00267800Frame;
static inline u8 *func_00267800_index(u8 *base, s32 index)
{
    return base + (index << 2);
}
static inline u8 *func_00267800_index90(u8 *base, s32 index)
{
    return base + (index << 2) + 0x90;
}
static inline f32 func_00267800_mul(f32 left, f32 right)
{
    return left * right;
}
extern char iGpffffa6c4;
extern void (*D_00887300[])(u32 state, u32 value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(s32, s32, s8 *, s32, s32, s32, f32, f32, f32);
static inline u32 *func_0026e010_add_offset(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}
static inline u8 *func_0026f1e0_add(u8 *base, u32 index)
{
    return base + index;
}

extern u8 *func_00452560();
extern s32 func_00452490();

extern s32 func_0025ef20(u8 *arg0);
extern u8 D_00637420[];

extern s32 func_00106880(s16 arg0);



extern u8 *func_00460990(void);
extern void func_00460ac0(u8 *arg0, u8 *arg1);
extern void func_00266cc0(s32 arg0, s32 arg1);

extern void func_0025f230(void *arg0);
extern void (*jtbl_008873EC[])(u8 *arg0);
extern u8 *(*D_008873F4[])(s32 arg0, s32 arg1, s32 arg2);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern void func_0046d730(void *arg0, s32 arg1);
extern s32 func_00266ba0(u8 *arg0);
extern s32 func_0045a8d0(s32 arg0, s32 arg1);
extern s32 func_004598e0(s32 arg0);
extern void func_001104d0(s32 arg0, s32 *arg1, s32 *arg2);
extern s32 func_0025f110(u8 *arg0);
extern u8 D_00638F90[];
extern void func_002674b0(s32 arg0, u8 *arg1);
extern char D_00637348[];
extern s32 func_00452380(void *arg0);
extern void func_00452080(s32 arg0);
extern void func_0025f430(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          u8 *arg4, s32 arg5, s16 arg6, s16 arg7,
                          f32 arg8, f32 arg9, f32 arg10, f32 arg11,
                          f32 arg12, f32 arg13);
extern void func_00263cb0(s32 arg0);
extern void func_00274660(u32 param_1, int param_2);
extern s32 func_00266950(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_00266a40(u32 arg0, s32 arg1);
extern void func_00266a90(u8 *arg0);
extern s32 func_00266ae0(s32 arg0);
extern void func_00106390(s32 arg0, s32 arg1);
extern s32 func_00108e10(void);
extern s32 func_00107ce0(s32 arg0);
extern s32 func_00107dc0(s32 arg0);
extern void func_00108290(s32 arg0, s32 arg1);
extern void func_00264cb0(s32 arg0, s32 arg1);
extern s32 func_00110c50(s32 arg0, s32 arg1);
extern s32 func_0043c6a0(s32 arg0);
extern f32 func_0044b7b0(f32 fparg0);
extern void func_00262de0(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern void func_00261560(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern s32 func_002746a0();
extern s64 func_0010d660(s32 arg0);
extern s64 func_0010d6d0(s32 arg0);
extern void func_00442088();
extern s32 D_008815B0[];
extern void func_00273f70(u8 *arg0);
extern void func_002739e0(s32 arg0, u8 *arg1);
extern u8 iGpffffa734;
extern f32 func_003e4180(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern u8 *func_00457120(void);
extern void func_004b1470(s32 arg0, f32 *arg1);
extern void func_00106620(s32 arg0, s32 arg1);

extern s32 func_00110580(s32 arg0);
extern s32 func_00110d30(s32 arg0);
extern void func_003f6440(s32 arg0, s32 arg1);
extern void func_00489f80(void);
extern void func_0045d6e0(void *arg0, void *arg1, f32 arg2, s32 arg3);
extern void func_0048a000(void);
extern s32 func_0025f2c0(s32 arg0, s32 arg1, u8 *arg2);
extern void func_0025f620(s32 arg0, u8 arg1, s32 arg2, s32 arg3,
                          s16 arg4, s16 arg5, Code1_0026Callback arg6,
                          s32 arg7, f32 arg8, f32 arg9, f32 arg10);
// FUN_00260510
void func_00260510(void)
{
    s32 temp_2;
    u8 *temp_2_2;

    temp_2 = func_00452380(D_00637348);
    if (temp_2 != 0) {
        temp_2_2 = func_00452560(temp_2);
        *(s32 *)(temp_2_2 + 8) |= 1;
    }
}
// FUN_00260560
void func_00260560(void)
{
    s32 temp_2;

    temp_2 = func_00452380(D_00637348);
    if (temp_2 != 0) {
        func_00452080(temp_2);
    }
}
/* measured: declaring func_0025f430's halfword parameters as s16 reproduces
   retail's zero/pointer/constant/halfword setup order; object 88B, retail
   window 96B with zero tail, normalized_diff 0. */
// FUN_002605A0
void func_002605a0(s32 arg0, s32 arg1, s8 *arg2, s32 arg3, s32 arg4,
                   u8 *arg5, f32 fparg0, f32 fparg1, f32 fparg2)
{
    s8 temp_7;

    temp_7 = *(s8 *)(arg2 + arg3);
    if (temp_7 != 0xA) {
        func_0025f430(arg0, arg1, 0, temp_7, *(u8 **)(arg5 + 0x10), 1,
                      *(s16 *)(arg5 + 0), *(s16 *)(arg5 + 2), fparg0, fparg1, fparg2,
                      *(f32 *)(arg5 + 4), *(f32 *)(arg5 + 8), *(f32 *)(arg5 + 0xC));
    }
}
// FUN_00260600
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260600);
// FUN_00260E60
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00260e60);
// FUN_00261560
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00261560);
// FUN_00262DE0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00262de0);
// FUN_00263220
/* measured: optimization-level probe for 00263220 register colouring */
#pragma optimization_level 1
s32 func_00263220(Code1_00263220State *arg0, s32 arg1, s32 arg2)
{
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f1;
    f32 temp_f1_2;
    s32 temp_2;
    s32 temp_17;
    s32 temp_3;
    s32 var_16;

    temp_17 = arg0->field20 + 1;
    arg0->field20 = temp_17;
    temp_3 = arg2 - arg1;
    if (temp_3 == 1) {
        temp_f0 = func_0044b7b0((fGpffff84a4 * (f32)temp_17) /
                                15.0f);
        temp_f1 = temp_f0 * (f32)(arg2 - arg1);
        temp_f0 = (f32)arg1;
        temp_f0 = temp_f0 + temp_f1;
        temp_2 = (s32)temp_f0;
        arg0->field18 = temp_2;
        arg0->field1C =
            (s32)(94.0f * (temp_f1 - (f32)(temp_2 - arg1)));
        if (temp_17 >= 0xF) {
            arg0->field18 = arg2;
            arg0->field1C = 0;
            return 1;
        }
            goto block_8;
        }
    if (arg1 < arg2) {
        var_16 = temp_3 * 3;
    } else {
        var_16 = (arg1 - arg2) * 3;
    }
    temp_f1_2 =
        (1.0f + func_0044b7b0(fGpffff8574 +
                               (fGpffff82fc * (f32)temp_17) /
                               (f32)var_16)) /
        2.0f;
    temp_f1_2 = temp_f1_2 * (f32)(arg2 - arg1);
    temp_f0_2 = (f32)arg1;
    temp_f0_2 = temp_f0_2 + temp_f1_2;
    temp_2 = (s32)temp_f0_2;
    arg0->field18 = temp_2;
    arg0->field1C =
        (s32)(94.0f * (temp_f1_2 - (f32)(temp_2 - arg1)));
    if (temp_17 >= var_16) {
        arg0->field18 = arg2;
        arg0->field1C = 0;
        return 1;
    }
block_8:
    return 0;
}
/* measured: closes optimization-level probe for 00263220 */
#pragma optimization_level 2
// FUN_00263460
s32 func_00263460(s32 arg0)
{
    s32 sp3C;
    s32 sp38;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_2_6;
    s32 temp_2_7;
    s32 temp_2_8;
    u8 *temp_2;

    temp_2 = func_00452560();
    func_001104d0(*(s32 *)(temp_2 + 0xC), &sp3C, &sp38);
    switch (*(u32 *)temp_2) {
    case 0:
        *(s32 *)(temp_2 + 4) = func_0025ef20(D_00637420);
        *(u32 *)temp_2 = 1;
        goto block_25;
    case 1:
        if (func_0025f110((u8 *)*(s32 *)(temp_2 + 4)) != 0) {
            *(u32 *)temp_2 = 2;
            *(s32 *)(temp_2 + 0x14) =
                func_00266950(arg0, *(s32 *)(temp_2 + 4),
                              *(s32 *)(temp_2 + 8));
            if (func_00106330(0x1471) != 0) {
                func_00106390(0x1471, 0);
                return -1;
            }
        }
        goto block_25;
    case 2:
        *(u32 *)temp_2 = 3;
        *(s32 *)(temp_2 + 0x20) = 0;
        *(s32 *)(temp_2 + 0x18) = *(s32 *)(temp_2 + 0xC);
        func_00266a40(*(s32 *)(temp_2 + 0x14), sp3C);
        /* fall through */
    case 3:
        temp_2_3 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_3;
        if (temp_2_3 > 0xA) {
            *(u32 *)temp_2 = 4;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 8:
        temp_2_4 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_4;
        if (temp_2_4 > 0x1E) {
            func_00266a90((u8 *)*(s32 *)(temp_2 + 0x14));
            *(u32 *)temp_2 = 0xA;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 4:
        temp_2_5 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_5;
        if (temp_2_5 > 5) {
            *(u32 *)temp_2 = 5;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 9:
        temp_2_6 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_6;
        if (temp_2_6 > 0xA) {
            *(u32 *)temp_2 = 8;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 5:
        if (func_00263220((Code1_00263220State *)temp_2, *(s32 *)(temp_2 + 0xC),
                          *(s32 *)(temp_2 + 0x10)) != 0) {
            *(u32 *)temp_2 = 6;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        func_001104d0(*(s32 *)(temp_2 + 0x18), &sp3C, &sp38);
        func_00266a40(*(s32 *)(temp_2 + 0x14), sp3C);
        goto block_25;
    case 7:
        temp_2_7 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_7;
        if (temp_2_7 > 0xA) {
            *(u32 *)temp_2 = 9;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 6:
        temp_2_8 = *(s32 *)(temp_2 + 0x20) + 1;
        *(s32 *)(temp_2 + 0x20) = temp_2_8;
        if (temp_2_8 > 5) {
            *(u32 *)temp_2 = 7;
            *(s32 *)(temp_2 + 0x20) = 0;
        }
        goto block_25;
    case 10:
        func_00266a90((u8 *)*(s32 *)(temp_2 + 0x14));
        /* fall through */
    case 11:
        if (func_00266ae0(*(s32 *)(temp_2 + 0x14)) != 0) {
            return -1;
        }
    default:
        goto block_25;
    }
block_25:
    func_00264cb0(arg0, *(s32 *)(temp_2 + 8));
    return 0;
}
// FUN_00263730
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263730);
// FUN_00263CB0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00263cb0);
// FUN_00264CB0
void func_00264cb0(s32 arg0, s32 arg1)
{
    u8 *temp_2;

    temp_2 = func_00460990();
    *(void (**)(s32))(temp_2 + 8) = func_00263cb0;
    *(s32 *)(temp_2 + 0x10) = arg0;
    func_00460ac0((u8 *)arg1, temp_2);
}
// FUN_00264D10
void func_00264d10(void)
{
    s32 temp_4;
    u8 *temp_2;

    temp_2 = func_00452560();
    if (func_00452490((u8 *)*(s32 *)(temp_2 + 0x14)) != 0) {
        func_00452080(*(s32 *)(temp_2 + 0x14));
    }
    temp_4 = *(s32 *)(temp_2 + 4);
    if (temp_4 != 0) {
        func_0025f230((void *)temp_4);
    }
    (*jtbl_008873EC)(temp_2);
}
// FUN_00266A40
s32 func_00266a40(u32 unk, s32 arg1) {
    u8 *temp_2 = func_00452560();

    if (*(s32 *)(temp_2 + 0x10) != arg1) {
        *(s32 *)(temp_2 + 4) |= 1;
        *(s32 *)(temp_2 + 0x14) = arg1;
    }
    return 0;
}



// FUN_00266A90
void func_00266a90(u8 *arg0) {
    u8 *p;

    if (func_00452490(arg0) != 0) {
        p = func_00452560(arg0);
        *(s32 *)(p + 4) |= 2;
    }
}

// FUN_00266AE0
s32 func_00266ae0(s32 arg0)
{
    u8 *temp_2;
    s32 temp_4;

    if (func_00452490() != 0) {
        temp_2 = func_00452560(arg0);
        temp_4 = *(s32 *)(temp_2 + 4);
        if ((temp_4 & 1) && !(temp_4 & 4)) {
            return 0;
        }
        if (*(s32 *)temp_2 == 1) {
            return 1;
        }
        return 0;
    }
    return 1;
}
// FUN_00266B70
void func_00266b70(void) {
    func_0025ef20(D_00637420);
}



// FUN_00266BA0
s32 func_00266ba0(u8 *arg0)
{
    s32 sp3C;
    s32 sp38;
    u8 *work;
    s32 temp;
    s32 state;

    work = func_00452560();
    func_001104d0(*(s32 *)(work + 0xC), &sp3C, &sp38);
    state = *(s32 *)(work + 0);
    switch (state) {
    case 0:
        *(s32 *)(work + 4) = func_0025ef20(D_00638F90);
        *(s32 *)(work + 0) = 1;
        break;
    case 1:
        if (func_0025f110((u8 *)*(s32 *)(work + 4)) != 0) {
            *(s32 *)(work + 0) = 2;
            *(s32 *)(work + 0x14) = 0;
        }
        break;
    case 2:
        temp = *(s32 *)(work + 0x14) + 1;
        *(s32 *)(work + 0x14) = temp;
        if (temp >= 0x3C) {
            *(s32 *)(work + 0) = 3;
        }
        break;
    case 3:
    case 4:
        return -1;
    default:
        break;
    }
    func_002674b0((s32)arg0, (u8 *)*(s32 *)(work + 8));
    return 0;
}
// FUN_00266CC0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00266cc0);
// FUN_002674B0
void func_002674b0(s32 arg0, u8 *arg1) {
    u8 *p;

    p = func_00460990();
    *(void **)(p + 0x8) = (void *)func_00266cc0;
    *(s32 *)(p + 0x10) = arg0;
    func_00460ac0(arg1, p);
}

// FUN_00267510
void func_00267510(u8 *arg0) {
    u8 *p;
    s32 v;

    p = func_00452560();
    v = *(s32 *)(p + 4);
    if (v != 0) {
        func_0025f230((void *)v);
    }
    jtbl_008873EC[0](p);
}

// FUN_00267570
s32 func_00267570(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    u8 *work;
    s32 result;

    if (arg3 == 0) {
        func_0046d730(D_00638FA0, 0xF2);
    }
    func_0044ea90(D_00638FA0, 0xF3);
    work = D_008873F4[0](1, 0x18, 0x40000);
    *(s32 *)(work + 0) = 0;
    *(s32 *)(work + 8) = arg3;
    *(s32 *)(work + 0xC) = arg1;
    *(s32 *)(work + 0x10) = arg2;
    result = func_00451fc0(arg0, D_00638FB0, 0xF, 0, 0,
                           (void (*)(void))func_00266ba0,
                           (void (*)(void))func_00267510, (s32)work);
    func_0045a8d0(3, 0);
    func_004598e0(0xA);
    return result;
}
static inline f32 func_0026_div_140(f32 value)
{
    return value / 140.0f;
}
// FUN_00267670
void func_00267670(u8 **arg0)
{
    u8 *base;
    u8 *var_18;
    u8 *temp_17;
    f32 old;
    f32 result;
    u8 *temp_4;
    f32 temp_f12;
    extern void func_002e2240(void *arg0, void *arg1, void *arg2);
    extern f32 D_00761514;
    extern f32 D_00761658;
    extern f32 D_0076165C;
    extern f32 D_00761260;
    extern s32 func_00267800(u8 **arg0, u8 *arg1);
    extern f32 func_002677a0(f32 arg0, f32 arg1, f32 arg2, f32 arg3,
                              f32 arg4);

    base = (u8 *)arg0;
    *(s32 *)(base + 0xC) = 0xFF;
    var_18 = *(u8 **)(*(u8 **)base + 8);
    goto loop_test;
loop_body:
    temp_17 = *(u8 **)(var_18 + 0xC);
    if (func_00267800(arg0, *(u8 **)(var_18 + 0x14)) != 0) {
        temp_4 = *(u8 **)base;
        func_002e2240(temp_4, temp_4 + 4, var_18);
    }
    var_18 = temp_17;
loop_test:
    if (var_18 != NULL) {
        goto loop_body;
    }
    if ((*(f32 *)(base + 4) > 0.0f) ||
        (*(u16 *)(*(u8 **)base + 0x10) != 0)) {
        *(f32 *)(base + 4) += 1.0f;
        if (*(f32 *)(base + 8) == 0.0f) {
            *(f32 *)(base + 8) = D_00761514;
            return;
        }
        temp_f12 = func_0026_div_140(*(f32 *)(base + 4));
        result = func_002677a0(D_00761658, D_00761658,
                               D_0076165C, D_00761260, temp_f12);
        old = *(f32 *)(base + 8);
        *(f32 *)(base + 8) = result * old + old;
    }
}
/* measured: optimization_level 1 and the right-associated first two terms produce the retail FPU chain; exact match nd 0 (obj 88B/window 96B). */
/* measured: opens optimization_level 1 to preserve retail's FPU term and accumulator order (nd 0). */
#pragma optimization_level 1
// FUN_002677A0
f32 func_002677a0(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 u;
    f32 k;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    u = 1.0f - t;
    k = 3.0f * u;
    a = t * (t * t);
    b = t * (k * t);
    c = u * (u * u);
    d = t * (k * u);
    return p0 * c + p1 * d + p2 * b + p3 * a;
}
/* measured: closes the optimization_level bracket (nd 0). */
#pragma optimization_level 2

/* Reconstruction attempt reached object/window parity but normalized_diff 279;
   archived at build/WU01_00267800.c and reverted to the assembly fallback. */
// FUN_00267800
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267800);
// FUN_00267B20
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_00267b20);
// FUN_00268A70
s32 func_00268a70(u8 *arg0)
{
    s32 temp_2;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_2 = *(s32 *)temp_16 - 1;
    *(s32 *)temp_16 = temp_2;
    if (temp_2 < 0) {
        func_004b1150((u8 *)*(s32 *)(temp_16 + 4));
        *(s32 *)(temp_16 + 4) = 0;
        return -1;
    }
    return 0;
}

// FUN_00268AD0
void func_00268ad0(u8 *arg0)
{
    u8 *temp_16;
    u8 *temp_4;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(u8 **)(temp_16 + 4);
    if (temp_4 != NULL) {
        func_004b1150(temp_4);
        *(u8 **)(temp_16 + 4) = NULL;
    }
    jtbl_008873EC[0](temp_16);
}

// FUN_0026CEF0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026cef0);
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 1
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
#pragma opt_propagation off
// FUN_0026DB60
s32 func_0026db60(void)
{
    s32 var_17;
    u8 *var_16;
    s32 temp_4;
    s32 temp_3;
    u8 *var_2;
    func_0026d440();
    var_17 = 1;
    goto outer_test;
outer_body:
    var_16 = func_001452b0(var_17);
    goto inner_test;
inner_body:
    func_0026a020(var_16);
    var_16 = *(u8 **)(var_16 + 0x138);
inner_test:
    if (var_16 != NULL) {
        goto inner_body;
    }
    var_17 += 1;
outer_test:
    if (var_17 < 0x16) {
        goto outer_body;
    }
    var_2 = func_001452b0(7);
    temp_3 = 1;
    goto second_test;
second_body:
    temp_4 = *(s32 *)(var_2 + 0x148);
    if (temp_4 == temp_3) {
        func_0026c310(var_2);
        goto second_exit;
    }
    var_2 = *(u8 **)(var_2 + 0x138);
second_test:
    if (var_2 != NULL) {
        goto second_body;
    }
second_exit:
    return 0;
}
/* measured: closes opt_propagation off probe for func_0026db60. */
#pragma opt_propagation on
/* measured: closes optimization_level 1 register-coloring probe for func_0026db60. */
#pragma optimization_level 2
// FUN_0026DC30
void func_0026dc30(void)
{
    func_0026d810();
}

/* measured: opt_propagation off probe for func_0026dc50 float load scheduling. */
#pragma opt_propagation off
// FUN_0026DC50
s32 func_0026dc50(u8 **arg0, u8 **arg1)
{
    struct DC50Frame {
        f32 v40[3];
        u8 pad4C[0x24];
        f32 v70[3];
        u8 pad7C[4];
        f32 v80[3];
        u8 pad8C[0x24];
        f32 vB0[3];
        u8 padBC[4];
        f32 vC0[3];
        u8 padCC[4];
        f32 vD0[3];
        u8 padDC[4];
        f32 vE0[3];
        u8 padEC[4];
    } frame;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 *temp_B0;
    f32 *temp_70;
    f32 temp_c1;
    f32 temp_c2;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = func_00457120();
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f0 = *(f32 *)(temp_2 + 0x30);
    temp_f2 = *(f32 *)(temp_2 + 0x34);
    temp_f1 = *(f32 *)(temp_2 + 0x38);
    frame.vC0[0] = temp_f0;
    frame.vC0[1] = temp_f2;
    frame.vC0[2] = temp_f1;
    temp_16 = *arg1;
    temp_2 = *arg0;
    func_004b1470(*(s32 *)(temp_2 + 0x144), frame.v80);
    func_004b1470(*(s32 *)(temp_16 + 0x144), frame.v40);
    temp_B0 = frame.vB0;
    temp_70 = frame.v70;
    frame.vE0[0] = temp_B0[0] - frame.vC0[0];
    temp_c1 = frame.vC0[1];
    frame.vE0[1] = temp_B0[1] - temp_c1;
    temp_c2 = frame.vC0[2];
    frame.vE0[2] = temp_B0[2] - temp_c2;
    frame.vD0[0] = temp_70[0] - frame.vC0[0];
    frame.vD0[1] = temp_70[1] - frame.vC0[1];
    frame.vD0[2] = temp_70[2] - frame.vC0[2];
    temp_f20 = func_003e4180(frame.vE0);
    return (s32)(temp_f20 - func_003e4180(frame.vD0));
}
/* measured: closes opt_propagation off probe for func_0026dc50. */
#pragma opt_propagation on
// FUN_0026DD60
void func_0026dd60(u8 *arg0)
{
    s32 output_index;
    u32 *result;
    s32 count;
    u8 *base;
    s32 index;

    count = 0;
    base = arg0;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(arg0 + 0x28) & 2) {
        if (*(s32 *)(arg0 + 0x144) != 0) {
            switch (*(s8 *)(arg0 + 0x140)) {
            case 0:
                count += 1;
                break;
            }
        }
    }
loop_7_next:
    arg0 = *(u8 **)(arg0 + 0x138);
loop_7_test:
    if (arg0 != NULL) {
        goto loop_7_body;
    }
    if (count != 0) {
        func_0044ea90(D_0063B580, 0x96);
        result = (u32 *)jtbl_008873E8[0](count * 4, 0x40000);
        index = 0;
        arg0 = base;
        goto loop_16_test;
loop_16_body:
        if (*(s32 *)(arg0 + 0x28) & 2) {
            if (*(s32 *)(arg0 + 0x144) != 0) {
                switch (*(s8 *)(arg0 + 0x140)) {
                case 0:
                    result[index] = (u32)arg0;
                    index += 1;
                    break;
                }
            }
        }
loop_16_next:
        arg0 = *(u8 **)(arg0 + 0x138);
        goto loop_16_test;
loop_16_test:
        if (arg0 != NULL) {
            goto loop_16_body;
        }
        func_00440bb8(result, count, 4, func_0026dc50);
        output_index = 0;
        goto loop_19_test;
loop_19_body:
        func_004b11d0(D_005DC7D0,
                      *(s32 *)((u8 *)result[output_index] + 0x144));
        output_index += 1;
loop_19_test:
        if (output_index < count) {
            goto loop_19_body;
        }
        jtbl_008873EC[0]((u8 *)result);
    }
}
// FUN_0026DEE0
s32 func_0026dee0(void)
{
    s32 temp_5;
    s8 temp_3;
    u8 *var_16;

    var_16 = func_001452b0(6);
    func_0026dd60(var_16);
    goto loop_test;
loop_body:
    if (*(s32 *)(var_16 + 0x28) & 2) {
        temp_5 = *(s32 *)(var_16 + 0x144);
        if (temp_5 != 0) {
            temp_3 = *(s8 *)(var_16 + 0x140);
            switch (temp_3) {
            case 0:
                break;
            case 1:
                func_004b11d0(D_005DC824, temp_5);
                break;
            }
        }
    }
    var_16 = *(u8 **)(var_16 + 0x138);
loop_test:
    if (var_16 != NULL) {
        goto loop_body;
    }
    return 0;
}
// FUN_0026DF80
s32 func_0026df80(void)
{
    s32 temp_2;

    temp_2 = func_00451fc0(0, D_0063B5A0, 0x10, 0, 0,
                           (void (*)(void))func_0026db60, func_0026dc30, 0);
    func_00451fc0(temp_2, D_0063B5C0, 0x10, 0, 0,
                  (void (*)(void))func_0026dee0, NULL, 0);
    return temp_2;
}
/* measured: jtbl_008873E8 array addressing fixes the retail absolute
   lui/lw. Local aliases, pointer-width casts, declaration-order, and goto
   loop spellings all retain the 0x50 frame and nd 20 (object 204B/window
   208B); the remaining register/scheduling rows are parked. Committed at
   nd 20. */
// FUN_0026E010
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026e010);
// FUN_0026E350
s32 func_0026e350(void)
{
    return iGpffffb4bc;
}

// FUN_0026E360
s32 func_0026e360(s64 arg0) {
    s32 temp_2 = func_00106880((s16) arg0);

    if (temp_2 & 1) {
        return 0;
    }
    if (temp_2 & 2) {
        return 1;
    }
    if (temp_2 & 4) {
        return 2;
    }
    if (temp_2 & 8) {
        return 3;
    }
    if (temp_2 & 0x10) {
        return 4;
    }
    if (temp_2 & 0x20) {
        return 5;
    }
    if (temp_2 & 0x40) {
        return 6;
    }
    if (temp_2 & 0x4000) {
        return 9;
    }
    if (temp_2 & 0x8000) {
        return 0xB;
    }
    if (temp_2 & 0x10000) {
        return 0xD;
    }
    if (temp_2 & 0x20000) {
        return 0xE;
    }
    if (temp_2 & 0x40000) {
        return 0xC;
    }
    return 0xD;
}

/* measured: opt_propagation off probe for func_0026e4c0 field-load order. */
#pragma opt_propagation off
// FUN_0026E4C0
s32 func_0026e4c0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xD) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off probe for func_0026e4c0. */
#pragma opt_propagation on
// FUN_0026E560
s32 func_0026e560(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off forces func_0026e590 field-load order. */
#pragma opt_propagation off
// FUN_0026E590
s32 func_0026e590(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xC) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e590. */
#pragma opt_propagation on
/* measured: opt_propagation off forces func_0026e630 field-load order. */
#pragma opt_propagation off
// FUN_0026E630
s32 func_0026e630(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e630. */
#pragma opt_propagation on
// FUN_0026E6D0
s32 func_0026e6d0(void)
{
    func_002746a0();
    return 0;
}
/* measured: opt_propagation off preserves field-load order for func_0026e700. */
#pragma opt_propagation off
// FUN_0026E700
s32 func_0026e700(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s8 *)(arg1 + 0xF) = (s8)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    *(s16 *)(arg1 + 0x1E) = (s16)((var_2 << 8) | (u8)temp_3_3);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e700. */
#pragma opt_propagation on
/* measured: opt_common_subs off forces func_0026e7f0 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves field-load order for func_0026e7f0. */
#pragma opt_propagation off
// FUN_0026E7F0
s32 func_0026e7f0(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    s32 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_5;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (temp_3[2] - 1) & 0xFF;
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_5 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() == 0) {
        goto success;
    }
    if (func_002746a0() != 1) {
        return 0;
    }
success:
    *(s32 *)arg1 = temp_4 << 4;
    *(s32 *)(arg1 + 4) = temp_5 << 3;
    return 0;
}
/* measured: closing opt_common_subs off for func_0026e7f0. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026e7f0. */
#pragma opt_propagation on
// FUN_0026E910
s32 func_0026e910(void)
{
    func_00274660(1, 1);
    return 1;
}
/* measured: opt_propagation off preserves decode and field-store order for func_0026e940. */
#pragma opt_propagation off
// FUN_0026E940
s32 func_0026e940(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    func_00274660(0x20, 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026e940. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ea50. */
#pragma opt_propagation off
// FUN_0026EA50
s32 func_0026ea50(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    s32 temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (func_00106330(0x3B) == 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (iGpffffa730 != 0) {
        goto direct_store;
    }
    temp_6 = func_00273970(*(u8 **)(arg1 + 0x14));
    temp_7 = temp_6 << 4;
    temp_6 = temp_7 - temp_6;
    temp_7 = temp_6 << 2;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = temp_7;
    goto after_store;
direct_store:
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
after_store:
    iGpffffa730 = -1;
    iGpffffb4bc = 1;
    func_00274660(0x10, 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026ea50. */
#pragma opt_propagation on
// FUN_0026EBA0
s32 func_0026eba0(void)
{
    func_00274660(1, 1);
    func_00274660(2, 1);
    return 1;
}
/* measured: opt_propagation off preserves target scan preheader ordering. */
#pragma opt_propagation off
/* measured: opt_loop_invariants on hoists the decode mask assignment to the target preheader. */
#pragma opt_loop_invariants on
// FUN_0026EBE0
s32 func_0026ebe0(s32 arg0, u8 *arg1)
{
    s32 temp_3;
    s32 var_16;
    s32 temp_3_5;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_6;
    u8 *temp_3_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    var_16 = 0;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_5 + temp_3_4);
    goto scan_loop;
decode:
    if ((temp_3_2 & 0xF0) == (temp_3_6 = 0xF0)) {
        var_16 += (((temp_3_2 & 0xF) - 1) * 2) + 1;
        goto scan_loop;
    }
    if ((u32)temp_3_2 < 0x80U) {
        goto scan_loop;
    }
    var_16 += 1;
    goto scan_loop;
scan_loop:
    temp_3 = var_16;
    var_16 += 1;
    temp_3_2 = *(s8 *)(temp_3_3 + temp_3);
    temp_3_5 = 0xA;
    if (temp_3_2 != temp_3_5) {
        goto decode;
    }
    func_0043f9c8(&D_00881530, 0, 0x80);
    func_0043f810(&D_00881530,
                  (void *)(*(s32 *)(arg1 + 0x10) + *(s32 *)(arg1 + 0x18)),
                  var_16);
    *((u8 *)((s32)&D_0088152F + var_16)) = 0;
    func_00274660(4, 1);
    *(s32 *)(arg1 + 0x18) = *(s32 *)(arg1 + 0x18) + var_16;
    return 0;
}
/* measured: closes the opt_loop_invariants and opt_propagation probes at the file baseline. */
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ed00. */
#pragma opt_propagation off
// FUN_0026ED00
s32 func_0026ed00(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;

    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    if (func_00106330(0x3A) == 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = 0x23;
    } else {
        temp_3_4 = *(s32 *)(arg1 + 0x18);
        temp_3_5 = *(s32 *)(arg1 + 0x10);
        temp_3 = (u8 *)(temp_3_5 + temp_3_4);
        temp_3_3 = (temp_3[0] - 1) & 0xFF;
        temp_3_2 = temp_3[1];
        if (temp_3_2 == 0xFF) {
            var_2 = 0;
        } else {
            var_2 = (temp_3_2 - 1) & 0xFF;
        }
        var_2 &= 0xFF;
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) =
            (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    }
    return 0;
}
/* measured: closing opt_propagation off for func_0026ed00. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves decode and state-store order for func_0026ee00. */
#pragma opt_propagation off
// FUN_0026EE00
s32 func_0026ee00(s32 arg0, u8 *arg1)
{
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    s32 temp_4;
    s32 temp_6;
    u8 *temp_7;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_4 = (s32)(s16)((var_2 << 8) | (u8)temp_3_3);
    if (func_002746a0() != 0) {
        return 0;
    }
    if (*(s32 *)(*(u8 **)(arg1 + 0x14) + 0x34) != 0) {
        *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x38) = 1;
    }
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x30) = arg0;
    *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C) = (s32)(s16)temp_4;
    temp_7 = *(u8 **)(arg1 + 0x14) + 0x3C;
    temp_6 = *(s32 *)(*(u8 **)(arg1 + 0x14) + 0x3C);
    if (temp_6 < 0) {
        *(s32 *)temp_7 = 0;
    }
    return 0;
}
/* measured: closing opt_propagation off for func_0026ee00. */
#pragma opt_propagation on
// FUN_0026EF00
s32 func_0026ef00(s32 arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    *(s8 *)(arg1 + 0xF) = 0x14;
    *(s16 *)(arg1 + 0x1E) = 0x20;
    iGpffffb4bc = 0;
    return 0;
}
/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026ef60. */
#pragma opt_common_subs off
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026ef60. */
#pragma opt_propagation off
// FUN_0026EF60
s32 func_0026ef60(s32 arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_18;
    s32 sp30[5];
    u8 *var_4;
    u8 *var_5;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    s32 temp_index;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_index = (((var_2 & 0xFF) << 8) |
                  (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    temp_17 = temp_q1;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_6 = temp_3[3];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_6 - 1) & 0xFF;
    }
    temp_q2 = (s64)(s16)((((var_2_2 & 0xFF) << 8) |
                          (temp_4 & 0xFF)));
    temp_18 = temp_q2;

    if (func_002746a0(temp_4) != 0) {
        return 0;
    }
    var_4 = (u8 *)&D_0063BA30[0];
    var_5 = (u8 *)&sp30[0];
    var_3 = 5;
    do {
        temp_2 = *(s32 *)var_4;
        var_4 += 4;
        var_3 -= 1;
        *(s32 *)var_5 = temp_2;
        var_5 += 4;
    } while (var_3 > 0);
    func_00106390(temp_18 + sp30[temp_17], 1);
    return 0;
}
/* measured: closing opt_propagation off for func_0026ef60. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026ef60. */
#pragma opt_common_subs on
/* measured: opt_common_subs off reconstructs the retail packed-index sequence for func_0026f0a0. */
#pragma opt_common_subs off
/* measured: opt_propagation off reconstructs the retail field-load and byte-code sequence for func_0026f0a0. */
#pragma opt_propagation off
// FUN_0026F0A0
s32 func_0026f0a0(s32 arg0, u8 *arg1)
{
    s32 temp_17;
    s32 temp_q1;
    s32 temp_q2;
    s32 temp_18;
    s32 sp30[5];
    u8 *var_4;
    u8 *var_5;
    s32 temp_2;
    s32 temp_3_3;
    s32 temp_3_5;
    s32 temp_3_4;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 var_3;

    s32 temp_index;
    s32 temp_3_2;
    s32 temp_3_6;
    u8 *temp_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    temp_index = (((var_2 & 0xFF) << 8) |
                  (temp_3_3 & 0xFF));
    temp_q1 = (s64)(s16)temp_index;
    temp_17 = temp_q1;
    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_4 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_6 = temp_3[3];
    if ((u8)temp_3_6 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_6 - 1) & 0xFF;
    }
    temp_q2 = (s64)(s16)((((var_2_2 & 0xFF) << 8) |
                          (temp_4 & 0xFF)));
    temp_18 = temp_q2;

    if (func_002746a0(temp_4) != 0) {
        return 0;
    }
    var_4 = (u8 *)&D_0063BA30[0];
    var_5 = (u8 *)&sp30[0];
    var_3 = 5;
    do {
        temp_2 = *(s32 *)var_4;
        var_4 += 4;
        var_3 -= 1;
        *(s32 *)var_5 = temp_2;
        var_5 += 4;
    } while (var_3 > 0);
    func_00106390(temp_18 + sp30[temp_17], 0);
    return 0;
}
/* measured: closing opt_propagation off for func_0026f0a0. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026f0a0. */
#pragma opt_common_subs on
// FUN_0026F1E0
s32 func_0026f1e0(s32 arg0, u32 arg1, s32 arg2)
{
    s32 temp_16;
    s32 temp_4;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 var_2;
    u8 temp_3_2;
    u8 *temp_3;
    u8 *self;

    self = (u8 *)arg1;
    temp_3_4 = *(s32 *)(self + 0x18);
    temp_3_5 = *(s32 *)(self + 0x10);
    temp_3 = func_0026f1e0_add((u8 *)temp_3_5, (u32)temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if (temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_16 = (u16)(s16)((var_2 << 8) | (u8)temp_4);
    temp_16 &= 0xFFFF;
    if (func_002746a0(temp_4) != 0) {
        return 0;
    }
    if (D_008815B0[temp_16 & 0xFFFF] != 0) {
        func_00273f70(self);
        func_002739e0(temp_16 & 0xFF, self);
    }
    return 0;
}
// FUN_0026F2C0
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f2c0);
/* measured: optimization_level 0 probe for the retail redundant return branch. */
#pragma optimization_level 0
// FUN_0026F5A0
s32 func_0026f5a0(void)
{
    if (func_002746a0() != 2) {
        return 0;
    }
    return 0;
}
/* measured: closes optimization_level 0 around func_0026f5a0. */
#pragma optimization_level 2
/* measured: opt_common_subs off preserves the per-decode pointer recompute for func_0026f5e0. */
/* measured: opt_propagation off preserves the byte-decode temporary liveness for func_0026f5e0. */
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
// FUN_0026F5E0
s32 func_0026f5e0(s32 arg0, u8 *arg1)
{
    s32 first;
    s32 second;
    s32 third;
    s32 fourth;
    s32 sp20[5];
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_3;
    s32 temp_3_2;
    s32 var_2_1;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 temp_2;
    s32 *src;
    s32 *dst;
    s32 i;
    u8 *temp_3;

    if (func_002746a0() != 3) {
        return 0;
    }

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_3_3 = (s32)((temp_3[0] - 1) & 0xFF);
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_1 = 0;
    } else {
        var_2_1 = (temp_3_2 - 1) & 0xFF;
    }
    first = (s64)(s16)(((var_2_1 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[2] - 1) & 0xFF);
    temp_3_2 = temp_3[3];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_2 - 1) & 0xFF;
    }
    second = (s64)(s16)(((var_2_2 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[4] - 1) & 0xFF);
    temp_3_2 = temp_3[5];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_3 = 0;
    } else {
        var_2_3 = (temp_3_2 - 1) & 0xFF;
    }
    third = (s64)(s16)(((var_2_3 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_4 + temp_3_5);
    temp_3_3 = (s32)((temp_3[6] - 1) & 0xFF);
    temp_3_2 = temp_3[7];
    if ((u8)temp_3_2 == 0xFF) {
        var_2_4 = 0;
    } else {
        var_2_4 = (temp_3_2 - 1) & 0xFF;
    }
    fourth = (s64)(s16)(((var_2_4 & 0xFF) << 8) | (temp_3_3 & 0xFF));

    switch (first) {
    case 0:
        src = (s32 *)&D_0063BA30[0];
        dst = &sp20[0];
        i = 5;
        do {
            temp_2 = *src;
            src += 1;
            i -= 1;
            *dst = temp_2;
            dst += 1;
        } while (i > 0);
        func_00106390(third + sp20[second], fourth);
        break;
    case 1:
        if (fourth != 0) {
            func_00107ce0(func_00108e10());
        } else {
            func_00107dc0(func_00108e10());
        }
        break;
    case 2:
    case 3:
        func_00108290(func_00108e10(), fourth & 0xFFFF);
        break;
    case 6:
    default:
        break;
    }
    return 0;
}
/* measured: closing opt_common_subs off for func_0026f5e0. */
#pragma opt_common_subs on
/* measured: closing opt_propagation off for func_0026f5e0. */
#pragma opt_propagation on
#pragma pop
// FUN_0026F860
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026f860);
// FUN_0026FBA0
s32 func_0026fba0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088(&sp20, &iGpffffa734, func_0010d660(1));
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    return 0;
}
// FUN_0026FC20
s32 func_0026fc20(s32 arg0, u8 *arg1)
{
    s8 sp20[0x20];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088(&sp20, &iGpffffa734, func_0010d6d0(1));
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    return 0;
}
// FUN_0026FCA0
s32 func_0026fca0(s32 arg0, u8 *arg1)
{
    s8 sp20[0x23];

    if (func_002746a0() != 0) {
        return 0;
    }
    func_00442088(&sp20, &iGpffffa734, func_0010d6d0(1));
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    sp20[0] = -0x7D;
    sp20[1] = -0xA;
    sp20[2] = 0;
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    func_00442088(&sp20, &iGpffffa734, func_0010d660(1));
    func_00273f70(arg1);
    func_00273cc0(&sp20, arg1);
    return 0;
}
// FUN_0026FD90
INCLUDE_ASM("asm/nonmatchings/code1_0026", func_0026fd90);
/* measured: opt_common_subs off forces func_0026fff0 field reloads. */
#pragma opt_common_subs off
/* measured: opt_propagation off preserves func_0026fff0 decode scheduling. */
#pragma opt_propagation off
// FUN_0026FFF0
s32 func_0026fff0(s32 arg0, u8 *arg1)
{
    s32 temp_16;
    s32 temp_17;
    s32 temp_4;
    s32 var_2;
    s32 var_2_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_2;
    s32 temp_3_4b;
    u8 *temp_3;
    u8 *temp_3_3;

    temp_3_4 = *(s32 *)(arg1 + 0x18);
    temp_3_5 = *(s32 *)(arg1 + 0x10);
    temp_3 = (u8 *)(temp_3_5 + temp_3_4);
    temp_4 = (temp_3[0] - 1) & 0xFF;
    temp_3_2 = temp_3[1];
    if ((u8)temp_3_2 == 0xFF) {
        var_2 = 0;
    } else {
        var_2 = (temp_3_2 - 1) & 0xFF;
    }
    var_2 &= 0xFF;
    temp_16 = (s32)(s16)((var_2 << 8) | (u8)temp_4);
    temp_3_6 = *(s32 *)(arg1 + 0x18);
    temp_3_7 = *(s32 *)(arg1 + 0x10);
    temp_3_3 = (u8 *)(temp_3_6 + temp_3_7);
    temp_4 = (temp_3_3[2] - 1) & 0xFF;
    temp_3_4b = temp_3_3[3];
    if ((u8)temp_3_4b == 0xFF) {
        var_2_2 = 0;
    } else {
        var_2_2 = (temp_3_4b - 1) & 0xFF;
    }
    var_2_2 &= 0xFF;
    temp_17 = (s32)(s16)((var_2_2 << 8) | (u8)temp_4);
    if (func_002746a0(temp_4) != 0) {
        return 0;
    }
    func_00106620((s16)temp_16, temp_17 & 0xFF);
    return 0;
}
/* measured: closing opt_propagation off for func_0026fff0. */
#pragma opt_propagation on
/* measured: closing opt_common_subs off for func_0026fff0. */
#pragma opt_common_subs on

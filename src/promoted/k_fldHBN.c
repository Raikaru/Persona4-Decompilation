/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
#include "field_light_internal.h"

extern u8 *func_00155280(void);
extern void func_00160180(void);
extern void (*DAT_008873EC[])(void *);
extern s32 func_0014eec0(void);
extern void func_00442830(void *arg0, const char *arg1);
extern void func_00442088();
extern s32 func_00454570(void *arg0);
extern void func_00440b68(char *arg0, const char *arg1, s32 arg2);
extern u8 *func_00454a60(void *arg0, s32 arg1);
extern char D_005F1108[];
extern char D_005F1118[];
extern char D_005F1130[];
extern char D_005F1150[];
extern char D_005F1170[];
extern char D_005F1190[];
extern char D_005F11B0[];
extern char D_005F11D0[];
extern u8 *iGpffff9db0;
extern char iGpffff9ef0;
extern s32 func_004553c0(u8 *arg0);
extern u8 *func_00455f70(void *arg0, u32 *arg1);
extern void func_0044ea90(void *arg0, s32 arg1);
extern void func_0043f810(void *arg0, void *arg1, s32 arg2);
extern void func_00454bd0(void *arg0);
extern void *(*D_008873F4[])(size_t, size_t, u32);

// FUN_0015F8E0
u8 *func_0015f8e0(s32 arg0, s32 arg1)
{
    char spB0[0x80];
    char sp30[0x80];

    if (func_0014eec0() == 0)
    {
        func_00442830(&spB0, D_005F1118);
        func_00442088(&sp30, D_005F1130, arg0 & 0xFFFF, arg1 & 0xFFFF);
        if (func_00454570(&sp30) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x17D);
        return func_00454a60(&sp30, 0);
    }
    return (u8 *)1;
}

// FUN_0015F9B0
s32 func_0015f9b0(u8 *arg0, u16 **arg1, s32 arg2, s32 arg3)
{
    u32 sp9C;
    char sp50[0x40];
    u8 *var_18;
    u16 *temp_2;

    if (arg0 == NULL)
    {
        return 1;
    }
    if ((func_0014eec0() == 0) && (func_004553c0(arg0) == 0))
    {
        return 0;
    }
    if (func_0014eec0() == 0)
    {
        sp9C = *(u32 *)(arg0 + 0x118);
        var_18 = (u8 *)*(u32 **)(arg0 + 0x110);
    }
    else
    {
        func_00442088(&sp50, D_005F1150, arg2 & 0xFFFF, arg3 & 0xFFFF);
        var_18 = func_00455f70(&sp50, &sp9C);
    }
    if (var_18 != NULL)
    {
        func_0044ea90(D_005F1108, 0x1AE);
        temp_2 = (u16 *)D_008873F4[0](1, (s32)(sp9C), 0x40000);
        *arg1 = temp_2;
        func_0043f810(temp_2, var_18, sp9C);
    }
    if (func_0014eec0() == 0)
    {
        func_00454bd0(arg0);
    }
    return 1;
}
/* 1052/1056 bytes: field colors are four-byte values passed after the
   three floats. Lifetime analysis preserves the separate cursor/counter
   phases. See docs/probe_archive/HBN_0015fb00_color_value_recovery.md. */
// FUN_0015FB00
#pragma push
#pragma opt_lifetimes on
void func_0015fb00(u8 *arg0, s32 arg1)
{
    extern s32 func_00145fc0(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146080(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146140(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146200(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_001462c0(u16 arg0, f32 *arg1, f32 fparg0);
    extern s32 func_00146380(u16 arg0, f32 *arg1, f32 fparg0);
    extern u8 *func_00145270(s32 arg0);
    extern s32 func_0014a200(void);
    extern s32 func_0014a270(void);
    u8 *r13;
    u32 c1;
    u8 *r2;
    u32 c2;
    u32 c3;

    if (arg0 != NULL) {
        if (*(u32 *)(arg0 + 4) == 0x10000) {
            r13 = arg0 + 0x28;
        } else if (*(u32 *)(arg0 + 4) == 0x10001) {
            r13 = arg0 + 0x30;
        } else if (*(u32 *)(arg0 + 4) == 0x10002) {
            r13 = arg0 + 0x38;
        } else {
            r13 = arg0 + 0x48;
        }
        for (c1 = 0; c1 < *(u32 *)(arg0 + 8);) {
            if ((((func_0014a200() == 0) && (func_0014a270() == 0)) || (arg1 == 1)) && ((arg1 != 1) || (((*(u16 *)r13 & 0x3FF) != 0x3FE) && ((*(u16 *)r13 & 0x3FF) != 0x3FF)))) {
                func_00145d60(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 8), *(f32 *)(r13 + 0x14), *(f32 *)(r13 + 0x18), *(f32 *)(r13 + 0x1C), *(FieldRgba8 *)(r13 + 4));
            }
            c1++;
            r13 += 0x20;
        }
        r2 = r13;
        for (c2 = 0; c2 < *(u32 *)(arg0 + 0x10);) {
            if ((((func_0014a200() == 0) && (func_0014a270() == 0)) || (arg1 == 1)) && ((arg1 != 1) || ((*(u16 *)r2 & 0x3FF) != 0x3FF))) {
                func_00145fc0(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
            }
            c2++;
            r2 += 0x14;
        }
        if (((func_0014a200() == 0) && (func_0014a270() == 0)) || (((func_0014a270() == 1) && (arg1 == 1)))) {
            for (c2 = 0; c2 < *(u32 *)(arg0 + 0x18);) {
                func_00146080(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
                c2++;
                r2 += 0x14;
            }
        }
        if (((func_0014a200() == 0) && (func_0014a270() == 0)) || (arg1 == 1)) {
            for (c3 = 0; c3 < *(u32 *)(arg0 + 0x20);) {
                func_00146140(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
                c3++;
                r2 += 0x14;
            }
            if (*(u32 *)(arg0 + 4) > 0x10000U) {
                for (c3 = 0; c3 < *(u32 *)(arg0 + 0x28);) {
                    func_00146200(*(u16 *)r2 & 0x3FF, (f32 *)(r2 + 4), *(f32 *)(r2 + 0x10));
                    c3++;
                    r2 += 0x14;
                }
            }
            if (*(u32 *)(arg0 + 4) > 0x10001U) {
                r13 = r2;
                for (c1 = 0; c1 < *(u32 *)(arg0 + 0x30);) {
                    func_00145e90(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 8), *(f32 *)(r13 + 0x14), *(f32 *)(r13 + 0x18), *(f32 *)(r13 + 0x1C), *(FieldRgba8 *)(r13 + 4));
                    {
                        u8 *resource = func_00145270(((*(u16 *)r13 & 0x3FF) | 0x5400) & 0xFFFF);
                        *(s32 *)(resource + 0x18C) = *(u16 *)(r13 + 2);
                    }
                    c1++;
                    r13 += 0x20;
                }
            }
            if (*(u32 *)(arg0 + 4) > 0x10002U) {
                for (c1 = 0; c1 < *(u32 *)(arg0 + 0x38);) {
                    func_001462c0(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 4), *(f32 *)(r13 + 0x10));
                    c1++;
                    r13 += 0x14;
                }
                for (c1 = 0; c1 < *(u32 *)(arg0 + 0x40);) {
                    func_00146380(*(u16 *)r13 & 0x3FF, (f32 *)(r13 + 4), *(f32 *)(r13 + 0x10));
                    c1++;
                    r13 += 0x14;
                }
            }
        }
    }
}
#pragma pop
// FUN_0015FF20
u8 *func_0015ff20(u16 arg0, s32 arg1)
{
    char spB0[0x80];
    char sp30[0x80];
    s32 temp_16;

    temp_16 = arg0;
    if (temp_16 == -1)
    {
        return NULL;
    }
    if (func_0014eec0() == 0)
    {
        func_00442830(&spB0, D_005F1118);
        func_00442088(&sp30, D_005F1170, temp_16, arg1 & 0xFFFF);
        if (func_00454570(&sp30) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x27D);
        return func_00454a60(&sp30, 0);
    }
    return (u8 *)1;
}

// FUN_00160000
s32 func_00160000(u8 *arg0)
{
    u32 sp8C;
    char sp40[0x40];
    u8 *var_16;
    u8 *temp_2;

    if (arg0 == NULL)
    {
        return 1;
    }
    if ((func_0014eec0() == 0) && (func_004553c0(arg0) == 0))
    {
        return 0;
    }
    if (func_0014eec0() == 0)
    {
        sp8C = *(u32 *)(arg0 + 0x118);
        var_16 = *(u8 **)(arg0 + 0x110);
    }
    else
    {
        temp_2 = (u8 *)iGpffff9db0;
        func_00442088(&sp40, D_005F1190, *(s32 *)(temp_2 + 0), *(s32 *)(temp_2 + 4));
        var_16 = func_00455f70(&sp40, &sp8C);
    }
    if (var_16 != NULL)
    {
        func_00160180();
        *(s32 *)((u8 *)func_00155280() + 0x18D8) = sp8C / 44;
        func_0044ea90(D_005F1108, 0x2AD);
        temp_2 = D_008873F4[0](1, (s32)(sp8C), 0x40000);
        *(u8 **)((u8 *)func_00155280() + 0x18DC) = temp_2;
        func_0043f810(*(void **)((u8 *)func_00155280() + 0x18DC), var_16, sp8C);
    }
    if (func_0014eec0() == 0)
    {
        func_00454bd0(arg0);
    }
    return 1;
}




// FUN_00160180
void func_00160180(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x18DC) != 0) {
        *(s32 *)((u8 *)func_00155280() + 0x18D8) = 0;
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x18DC));
        *(s32 *)((u8 *)func_00155280() + 0x18DC) = 0;
    }
}

// FUN_001601E0
u8 *func_001601e0(s32 arg0)
{
    char spA0[0x80];
    char sp20[0x80];

    if (func_0014eec0() == 0)
    {
        func_00442830(&spA0, D_005F1118);
        func_00442088(&sp20, D_005F11B0, arg0 & 0xFFFF);
        if (func_00454570(&sp20) == 0)
        {
            return NULL;
        }
        func_00440b68(&iGpffff9ef0, D_005F1108, 0x2E0);
        return func_00454a60(&sp20, 0);
    }
    return (u8 *)1;
}

// FUN_001602A0
s32 func_001602a0(u8 *arg0, s32 arg1)
{
    u32 sp7C;
    char sp30[0x40];
    u8 *var_16;
    u8 *temp_2;

    if (arg0 == NULL)
    {
        return 1;
    }
    if (func_0014eec0() == 0)
    {
        if (func_004553c0(arg0) != 0)
        {
            func_0044ea90(D_005F1108, 0x2F9);
            var_16 = D_008873F4[0](1, (s32)(*(u32 *)(arg0 + 0x118)), 0x40000);
            *(u8 **)((u8 *)func_00155280() + 0x1854) = var_16;
            *(u32 *)((u8 *)func_00155280() + 0x1858) = *(u32 *)(arg0 + 0x118);
            func_0043f810(*(void **)((u8 *)func_00155280() + 0x1854), *(void **)(arg0 + 0x110), *(u32 *)(arg0 + 0x118));
            func_00454bd0(arg0);
            return 1;
        }
    }
    else
    {
        func_00442088(&sp30, D_005F11D0, arg1 & 0xFFFF);
        temp_2 = func_00455f70(&sp30, &sp7C);
        if (temp_2 != NULL)
        {
            func_0044ea90(D_005F1108, 0x30C);
            var_16 = D_008873F4[0](1, (s32)(sp7C), 0x40000);
            *(u8 **)((u8 *)func_00155280() + 0x1854) = var_16;
            *(u32 *)((u8 *)func_00155280() + 0x1858) = sp7C;
            func_0043f810(*(void **)((u8 *)func_00155280() + 0x1854), temp_2, sp7C);
        }
        return 1;
    }
    return 0;
}

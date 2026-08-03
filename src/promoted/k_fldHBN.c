/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

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
extern u8 *(*D_008873F4[])(s32, s32, s32);

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
        temp_2 = (u16 *)D_008873F4[0](1, sp9C, 0x40000);
        *arg1 = temp_2;
        func_0043f810(temp_2, var_18, sp9C);
    }
    if (func_0014eec0() == 0)
    {
        func_00454bd0(arg0);
    }
    return 1;
}
/* measured: retail loads the u32 field at entry+4 through an unaligned
   lwr $6,0x4($17)/lwl $6,0x7($17) pair at BOTH func_00145d60/func_00145e90
   call sites (2 pairs, 4 words); mwcc b210 emits plain `lw` for every
   construct tried at a 4-aligned displacement: byte- and halfword-
   pointer cast derefs, packed structs (#pragma pack 1/2, #pragma
   options align=packed, __attribute__((packed))) with the field at
   packed offset 4, local vs
   parameter bases, and (u32) of a u64 load — b210 emits lwl/lwr ONLY at
   displacements %4 != 0 (packed offset 2) while retail 2.4.1 tracks the
   byte-derived base alignment. Everything else in this function matched
   exactly (registers s3/s2/s1/s0/s4 via decl order, if/else-if switch
   chain, all 8 loops, sltu conditions); the u32-arg load is also emitted
   before the lwc1 args where retail places lwr/lwl after them, and the 2
   missing pairs cascade the branch targets, nd 189. Unaligned-load
   codegen-version floor, same family as the ldr/ldl notes in
   y_fclCombineDraw.c/shdPersona.c. */
// FUN_0015FB00
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_0015fb00);
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
        temp_2 = D_008873F4[0](1, sp8C, 0x40000);
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
            var_16 = D_008873F4[0](1, *(u32 *)(arg0 + 0x118), 0x40000);
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
            var_16 = D_008873F4[0](1, sp7C, 0x40000);
            *(u8 **)((u8 *)func_00155280() + 0x1854) = var_16;
            *(u32 *)((u8 *)func_00155280() + 0x1858) = sp7C;
            func_0043f810(*(void **)((u8 *)func_00155280() + 0x1854), temp_2, sp7C);
        }
        return 1;
    }
    return 0;
}

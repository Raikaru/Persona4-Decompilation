/* Consolidated Persona 4 source units. */
/* Original translation unit shdWindow.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

extern void func_0044ea90(const void *file, s32 line);
extern void func_0046d730(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern u8 D_00637190[];
extern u8 D_00637248[];
extern u8 D_00637270[];
extern u8 D_00796670[];
extern u16 D_008C024E[];
extern u16 D_008C0276[];
extern s32 func_00451fc0(s32, u8 *, s32, s32, s32, void (*)(u8 *), void (*)(u8 *), u8 *);
extern s32 func_0025e170(s32);
extern void func_0025e4a0(s32, s32);
extern void func_0045af60(s32, s32, s32, s32);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *, void *);
extern u8 *func_00274570(u32, u32, u32, u32, u32, u32, u32, u32);
extern s32 func_00273970(u8 *);
extern u8 *func_002736d0(u8 **, s32);
extern s32 func_002738d0(u8 *);
extern void func_00272a10(u8 *, f32, f32);
extern void func_00272ba0(u8 *, s32);
extern void func_00273170(u8 *, s32, s32);
extern void func_00271b70(u8 *);
extern f32 iGpffff8094;
extern f32 func_0044b7b0(f32);
extern void func_00366670(s32, s32, s32, s32, s32, s32, s32, s32,
                         f32, f32, f32, f32, s32, s32);
extern void func_0025dd30(f32, f32, s32, u8 *);


// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// measured: opt_loop_invariants on fixes the parameter allocation and pre-loop
// mask placement; declaring var_17 after the three list-walk locals gives the
// retail $s4/$s3/$s2/$s1 allocation (old declaration order was nd 22).
#pragma opt_loop_invariants on
// FUN_0025DB00
s32 func_0025db00(f32 fparg0, f32 fparg1, s32 arg0, s32 arg1, s32 arg2,
                  s32 arg3)
{
    u8 *sp9C;
    s32 temp_22;
    u8 *var_18;
    u8 *var_19;
    s32 var_20;
    s32 var_17;

    arg1 |= -0x100;
    if (arg2 >= 0x17) {
        func_0046d730(&D_00637248, 0x75);
    }
    temp_22 = *(s32 *)((u8 *)&D_00637190 + arg2 * 8);
    var_17 = 0;
    sp9C = func_00274570(0, 0, 2, 0, 0, 0xFF, temp_22, 0);
    temp_22 = func_00273970(sp9C) * 0x1C;

    while (sp9C != NULL) {
        var_18 = func_002736d0(&sp9C, 0);
        if (var_18 == NULL) {
            var_18 = sp9C;
            sp9C = NULL;
        }
        var_19 = var_18;
        var_20 = 0;
        while (var_19 != NULL) {
            var_20 += func_002738d0(var_19);
            var_19 = *(u8 **)(var_19 + 0x24);
        }
        if (arg3 != 0) {
            func_00272a10(var_18,
                          fparg0 - (f32)var_20 / 2.0f,
                          fparg1 + 28.0f * (f32)var_17 - (f32)temp_22 / 2.0f);
        } else {
            func_00272a10(var_18, fparg0, fparg1);
        }
        func_00272ba0(var_18, arg1);
        func_00273170(var_18, 1, 0);
        func_00271b70(var_18);
        var_17++;
    }
    return var_17 * 0x1C;
}
// measured: closes the func_0025db00 loop-invariant bracket.
#pragma opt_loop_invariants off

// measured: retail allocates arg0->$s3, arg1->$s2, temp_16->$s0, temp_17->$s1
// and loads D_00637260-6C with absolute lui/lwc1 (fixed by declaring them
// arrays); mwcc b210 instead shifts every saved register down by one
// (arg0->$s2, arg1->$s1) and reorders the var_f22 float computation, so the
// whole 14-arg func_00366670 / 9-arg func_00274ed0 call region rotates. Tried
// 3 declaration orders and the sp array vs 4 separate scalar locals, all nd
// 216-224. Saved-register rotation + float-order floor.
// FUN_0025DD30
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025dd30);

// FUN_0025E170
s32 func_0025e170(s32 arg0)
{
    u8 *p;
    s32 temp_18;
    s32 temp_3_2;
    s32 temp_2_2;
    s32 temp_2_4;
    s32 temp_3;
    u16 temp_3_3;
    u8 *temp_2;
    u8 *temp_2_3;

    p = (u8 *)func_00452560();
    temp_3 = *(s32 *)p;
    switch (temp_3) {
    case 0:
        *(s32 *)p = 2;
        *(s32 *)(p + 4) = *(s32 *)(p + 4) | 1;
        temp_3_2 = *(s32 *)(p + 0x1C) | 1;
        *(s32 *)(p + 0x1C) = temp_3_2;
        *(s32 *)(p + 0x1C) = temp_3_2 & ~2;
        temp_18 = *(s32 *)(p + 0xC);
        if (temp_18 >= 0x17) {
            func_0046d730(&D_00637248, 0x7D);
        }
        switch (((*(s32 *)((u8 *)&D_00637190 + temp_18 * 8 + 4)) >> 16)) {
        case 1:
            *(s32 *)(p + 0x14) = 1;
            break;
        }
        /* fallthrough */
    case 2:
        *(s32 *)p = 3;
        *(s32 *)(p + 0x10) = 0;
        /* fallthrough */
    case 3:
        temp_2_2 = *(s32 *)(p + 0x10) + 1;
        *(s32 *)(p + 0x10) = temp_2_2;
        if (temp_2_2 >= 5) {
            *(s32 *)(p + 0x10) = 0;
            *(s32 *)p = 6;
        }
        goto block_37;
    case 6:
        temp_18 = *(s32 *)(p + 0xC);
        if (temp_18 >= 0x17) {
            func_0046d730(&D_00637248, 0x79);
        }
        temp_3_3 = *(u16 *)((u8 *)&D_00637190 + temp_18 * 8 + 4);
        switch (temp_3_3) {
        case 0:
            break;
        case 1:
            if ((D_008C024E[0] & 0x40) || (D_008C024E[0] & 0x20)) {
                *(s32 *)(p + 4) = *(s32 *)(p + 4) | 4;
                func_0045af60(0, 0, 0, 1);
            }
            break;
        case 2:
            if (D_008C0276[0] & 0x8000) {
                if (*(s32 *)(p + 0x14) != 0) {
                    func_0045af60(0, 0, 0, 0);
                }
                *(s32 *)(p + 0x14) = 0;
            } else if (D_008C0276[0] & 0x2000) {
                if (*(s32 *)(p + 0x14) != 1) {
                    func_0045af60(0, 0, 0, 0);
                }
                *(s32 *)(p + 0x14) = 1;
            } else if (D_008C024E[0] & 0x40) {
                *(s32 *)(p + 4) = *(s32 *)(p + 4) | 4;
                func_0045af60(0, 0, 0, 1);
            }
            break;
        }
        if (*(s32 *)(p + 4) & 4) {
            *(s32 *)p = 1;
            temp_2_4 = *(s32 *)(p + 0x1C) & ~1;
            *(s32 *)(p + 0x1C) = temp_2_4;
            *(s32 *)(p + 0x1C) = temp_2_4 | 2;
        }
        goto block_37;
    case 1:
        if (!(*(s32 *)(p + 0x1C) & 2)) {
            return -1;
        }
        goto block_37;
    }
block_37:
    temp_2_3 = (u8 *)func_00460990();
    *(void (**)(s32, s32))(temp_2_3 + 8) = func_0025e4a0;
    *(s32 *)(temp_2_3 + 0x10) = arg0;
    func_00460ac0(&D_00796670, temp_2_3);
    return 0;
}

// measured: the two-argument callback type keeps the work pointer in $s0;
// switch(action), an explicit action=0 for the bit-2 arm, and the ternary
// count clamp reproduce retail's branch layout. Packing the color channels
// through (s8)(s32) preserves the retail sign-extension sequence.
// FUN_0025E4A0
void func_0025e4a0(s32 arg0, s32 arg1)
{
    u8 *p;
    u8 *temp_5;
    s32 action;
    s32 flags;
    s32 count;
    f32 temp_f20;
    f32 frac;
    u32 color;

    p = (u8 *)func_00452560(arg1);
    temp_5 = p + 0x18;
    action = 0;
    flags = *(s32 *)(p + 0x1C);
    if (flags & 1) {
        count = *(s32 *)(temp_5 + 0x10);
        if (count < 5) {
            *(s32 *)(temp_5 + 0x10) = count + 1;
        } else {
            *(s32 *)(temp_5 + 4) = flags & ~1;
            *(s32 *)(temp_5 + 0x10) = 7;
        }
        action = 1;
    } else if (flags & 2) {
        count = *(s32 *)(temp_5 + 0x10);
        if (count > 0) {
            *(s32 *)(temp_5 + 0x10) = count - 1;
        } else {
            *(s32 *)(temp_5 + 4) = flags & ~2;
        }
        action = 0;
    }

    switch (action) {
    case 1:
        count = *(s32 *)(temp_5 + 0x10);
        count = count < 3 ? count : 3;
        temp_f20 = func_0044b7b0((iGpffff8094 * (f32)count) / 3.0f);
        func_00366670(
            92,
            (s32)(74.0f + 150.0f * (1.0f - temp_f20)),
            456,
            (s32)(300.0f * temp_f20),
            0x2D2D2D,
            255,
            1,
            0,
            0.0f,
            0.0f,
            1.0f,
            1.0f,
            0,
            0);
        func_0025dd30(92.0f, 74.0f, (s32)(255.0f * temp_f20), p);
        break;
    case 0:
        count = *(s32 *)(temp_5 + 0x10);
        count = count < 3 ? count : 3;
        frac = (f32)count / 3.0f;
        temp_f20 = 255.0f * frac;
        color = 0x2D2D2D00 | (((s8)(s32)(255.0f * frac)) & 0xFF);
        func_00366670(
            92,
            (s32)(74.0f + 150.0f * (1.0f - frac)),
            456,
            (s32)(10.0f + 290.0f * frac),
            color >> 8,
            color & 0xFF,
            1,
            0,
            0.0f,
            0.0f,
            1.0f,
            1.0f,
            0,
            0);
        func_0025dd30(92.0f, 74.0f, (s32)temp_f20, p);
        break;
    }
}

// FUN_0025E7C0
void func_0025e7c0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_0025E800
void func_0025e800(s32 arg0, s32 arg1, s32 arg2)
{
    u8 *temp_2;

    func_0044ea90(&D_00637248, 0x204);
    temp_2 = D_008873F4[0](1, 0x2C, 0x40000);
    *(s32 *)(temp_2 + 8) = arg1;
    *(s32 *)(temp_2 + 0xC) = arg2;
    func_00451fc0(arg0, D_00637270, 0xF, 0, 0, (void (*)(u8 *))func_0025e170, (void (*)(u8 *))func_0025e7c0, temp_2);
}

// FUN_0025E8B0
void func_0025e8b0(void) {
    u8 *p = (u8 *)func_00452560();
    s32 v = *(s32 *)(p + 0x4);

    if (!(v & 4)) {
        *(s32 *)(p + 0x4) = v | 4;
    }
}

// FUN_0025E8F0
s32 func_0025e8f0(void)
{
    u8 *p;
    s32 v17;
    s32 b;
    u16 t;

    p = (u8 *)func_00452560();
    v17 = 0;
    if (*(s32 *)(p + 4) & 4) {
        v17 = 1;
    }
    b = *(s32 *)(p + 0xC);
    if (b >= 0x17) {
        func_0046d730(&D_00637248, 0x79);
    }
    t = *(u16 *)((u8 *)&D_00637190 + b * 8 + 4);
    switch (t) {
    case 0:
        return 1;
    case 1:
        if (v17 != 0) {
            return 1;
        }
        goto ret0;
    case 2:
        if (v17 != 0) {
            return *(s32 *)(p + 0x14) + 1;
        }
        goto ret0;
    default:
    ret0:
        return 0;
    }
}


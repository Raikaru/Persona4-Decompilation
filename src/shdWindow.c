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
extern void func_0025e4a0(s32);
extern void func_0045af60(s32, s32, s32, s32);
extern u8 *func_00460990(void);
extern void func_00460ac0(void *, void *);

#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// measured: retail saves a1->$s0, a2->$s1 (then reuses $s1 for the loop
// counter var_17), a3->$s5, f12->$f21, f13->$f20, and allocates var_18->$s2,
// var_19->$s3, var_20->$s4, temp_22->$s6; mwcc b210 instead emits a spurious
// `move $s5, $a0` and allocates the counter var_17->$s3 / var_20->$s0, so
// every reference rotates. Float math is instruction-identical (sub.s/madd.s
// sequence matches); only the saved-register allocation differs. Tried 3-int
// and 4-int signatures, 5 declaration orders, and the m2c goto-loop shape, all
// nd 101. Saved-register rotation floor.
// FUN_0025DB00
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025db00);

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
    *(void (**)(s32))(temp_2_3 + 8) = func_0025e4a0;
    *(s32 *)(temp_2_3 + 0x10) = arg0;
    func_00460ac0(&D_00796670, temp_2_3);
    return 0;
}

// measured: retail keeps the work pointer in $s0 only (frame 0x40, saves
// $s0 + $f20), computing temp_5=p+0x18 and temp_4=[p+0x1C] into scratch
// $a1/$a0/$a2; mwcc b210 instead allocates the pointer to $s1 and saves BOTH
// $s0 and $s1 (frame 0x50), so every reference and the 14-arg func_00366670
// call rotate. Logic (accumulator adda.s/madd.s float math, the (s8) byte
// extraction, and the 14-arg call) is correct; only the saved-register/
// frame allocation differs. Tried 4 declaration orders and inlining temp_5,
// all nd 143-187. Saved-register rotation floor.
// FUN_0025E4A0
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025e4a0);

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


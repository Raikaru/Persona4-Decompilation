/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"
extern void func_003549d0();
extern void (*jtbl_008873EC[])(void *ptr);
extern s32 func_00354830();

extern void func_0036df30(u8 *arg0);
extern void func_0036d8b0(void);
extern void *func_00457120(void);
extern void func_004577d0(void *arg0, f32 arg1);
extern s32 func_0038cec0(void *arg0);
extern s32 func_00388bd0(void *arg0);
extern s32 func_0038d790(void *arg0);
extern void func_0034f1e0(void);
extern void func_00374d20(u8 *arg0);
extern void func_00371990(u8 *arg0, u8 *arg1, u8 *arg2);
extern void func_00371ba0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern void func_00370410(u8 *arg0);
extern void func_00370a80(u8 *arg0);
extern void func_003723a0(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372870(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4);
extern void func_00372c30(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3, u8 *arg4, u8 *arg5);
extern void func_003730f0(u8 *arg0, s32 arg1, s32 arg2, void *arg3);
extern void func_003733d0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_00373590(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);

typedef struct { f32 x, y, z; } ShuffleVec3;

extern s32 func_00442088(char *buf, const char *fmt, ...);
extern char D_0064EA80[];
extern void func_003547c0(s32 *arg0, u8 *arg1);
extern char D_0064EA20[];
extern void func_0046d730(const void *file, u32 line);
extern f32 func_00373cb0(f32 fparg0, f32 fparg1, s32 arg0, f32 fparg2);
extern s64 func_001060b0(void);
extern s32 func_00110d60(s16 value);
extern char iGpffffa9d0;
extern s32 iGpffffa9c8;
extern u8 *func_00454a60(u8 *param, s32 mode);
extern void func_00440b68();
extern void func_00371f40(u8 *arg0, f32 fparg0, u8 *arg1);
extern void func_00373f00(u8 *arg0);
extern void func_00371e50(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4);
extern void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 *arg3, u8 *arg4, f32 fparg0);
extern void func_0046b0d0(void *ptr);
extern void func_0044ea90(const void *file, s32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);
extern f32 func_00373c20(u8 *arg0);
extern s32 func_00106330(s32 arg0);
extern void func_0036c900(void);
extern void func_0036d990(u8 *arg0, u8 *arg1);
extern void func_0043f9c8(u8 *arg0, s32 arg1, s32 arg2);
extern void func_0045af60(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00373750(s32 arg0, s32 arg1, void *arg2);
extern s32 func_00451fc0(u8 *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5, void *arg6, u8 *arg7);
extern void func_003781d0(u8 *arg0, s32 arg1);
extern void func_00378260(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4);
extern char D_0064EA60[];
extern f32 iGpffff83e0;
extern s32 func_00371a60(u8 *arg0, s32 arg1);
extern s32 func_00371c70(u8 *arg0);
extern void func_00370640(u8 *arg0);
extern s32 func_003720c0(u8 *arg0);
extern s32 func_00372200(u8 *arg0);
extern s32 func_003724f0(u8 *arg0);
extern s32 func_003726b0(u8 *arg0);
extern s32 func_00372960(u8 *arg0);
extern s32 func_00372d60(u8 *arg0);
extern void func_00370cd0(u8 *arg0);
extern s32 func_00373170(u8 *arg0);
extern void func_003733f0(u8 *arg0);
extern void func_00373610(u8 *arg0);
extern void func_00375f00(u8 *arg0, s32 arg1);
extern s32 func_004553c0(s32 arg0);
extern s32 func_00455ea0(s32 arg0, s32 arg1, void *arg2);
extern void func_0043f810(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_0046af60(s32 arg0);
extern void func_0036d230(s32 arg0);
extern s32 func_0046a750(s32 arg0);
extern void func_00454bd0(s32 arg0);
extern void func_003768e0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, f32 fparg0);
extern f32 func_00375a70(u8 *arg0, s32 arg1);
extern f32 iGpffff8170;
extern void func_003766f0(f32 **arg0, s32 arg1, s32 arg2, u8 *arg3);
extern void func_00376800(u8 **arg0, s32 arg1);
extern void func_00374910(u8 *arg0);
extern void func_00375d50(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1);
extern void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1);
extern void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5);
extern void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);


// FUN_00373E10
void func_00373e10(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    if (arg2 > 8) {
        func_0046d730(D_0064EA20, 0x53);
    }
    if ((arg3 < 0) || (arg3 > 4)) {
        func_0046d730(D_0064EA20, 0x54);
    }
    *(s32 *)(arg0 + 0x1F2A8) = arg1;
    *(s32 *)(arg0 + 0x1F304) = arg2;
    *(s32 *)(arg0 + 0x1F2FC) = arg3;
    *(s32 *)(arg0 + 0x1F300) = arg4;
    *(s32 *)(arg0 + 0x1F30C) = 0;
    func_00373f00(arg0);
}


// FUN_00373F00
void func_00373f00(u8 *arg0) {
    s32 count;
    s32 v;
    s32 i;
    u8 *p;

    func_0043f9c8(arg0 + 0x1F1D0, 0, 0x40);
    func_0043f9c8(arg0 + 0x1D6A0, 0, 0x1B30);
    *(u16 *)(arg0 + 0x1F2F4) = 0;
    *(s32 *)(arg0 + 0x1F2F8) = 0;
    *(u16 *)(arg0 + 0x1F2F0) = 0;
    *(u16 *)(arg0 + 0x1F2F2) = 0;
    *(s32 *)(arg0 + 0x1F308) = -1;
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    v = *(s32 *)(arg0 + 0x1F2FC);
    switch (v) {
    case 0:
    case 1:
    case 2:
        *(s32 *)(arg0 + 0x1F310) = 0x42480000;
        break;
    case 3:
    case 4:
        *(s32 *)(arg0 + 0x1F310) = 0x41200000;
        break;
    default:
        func_0046d730(D_0064EA20, 0x7C);
        break;
    }
    for (i = 0; i < count; i++) {
        p = (u8 *)(arg0 + i * 0xE8);
        *(u16 *)(p + 0x1D6A0) |= 2;
    }
}


// FUN_003740B0
void func_003740b0(u8 *arg0, s32 arg1) {
    s32 count;
    s32 i;
    u8 *p;

    if ((func_00106330(0x1403) != 0) && (func_00106330(0x142B) != 0)) {
        func_0036c900();
    }
    count = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    for (i = 0; i < count; i++) {
        func_0036d990(arg0 + i * 0xFB0, (u8 *)(arg1 + (i % *(s32 *)(arg0 + 0x1F304)) * 8));
        p = (u8 *)(arg0 + i * 0xE8);
        *(s32 *)(p + 0x1D720) = 0;
        *(s32 *)(p + 0x1D714) = 0;
        *(s32 *)(p + 0x1D718) = 0x3F800000;
        *(s32 *)(p + 0x1D71C) = 0;
    }
}


// FUN_003741F0
void func_003741f0(u8 *arg0) {
    s32 temp_17;
    s32 temp_2;

    temp_17 = !(func_00110d60((s16)func_001060b0()) & 1);
    func_00440b68(&iGpffffa9d0, D_0064EA20, 0xB5);
    temp_2 = (s32)(func_00454a60(*(u8 **)((u8 *)&iGpffffa9c8 + temp_17 * 4), 1));
    *(s32 *)(arg0 + 0x1F2E8) = temp_2;
    if (temp_2 == 0) {
        func_0046d730(D_0064EA20, 0xB6);
    }
    *(s32 *)(arg0 + 0x1F2EC) = 0;
}


/* measured: retail allocates arg0=$s0, r=$s1, i=$s2, idx=$s3, p=$s4 in the three
   case-0 allocation loops and case 1's check loop; mwcc b210 swaps idx into $s2
   and i into $s3 with otherwise identical instructions (nd 95, obj 848B). All
   real structure is solved and verified: the irregular switch nests case 1's
   label INSIDE case 0's if (so the if-true path falls through and the if-false
   path hits default's shared return 0), case 2's return 1 sits before default,
   idx continues across the 9/3/3-iteration loops (2 counters i/j per m2c names),
   and the D_008873F4/sp6C/0x102/0x109/0x10F/0x110 call pattern is exact.
   Saved-register rotation floor. */
// FUN_003742B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003742b0);


// FUN_00374610
void func_00374610(u8 *arg0) {
    s32 i;
    s32 j;
    s32 k;
    u8 *p;
    s32 v;

    for (i = 0; i < 3; i++) {
        p = (u8 *)(arg0 + i * 4 + 0x1F2DC);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (j = 0; j < 3; j++) {
        p = (u8 *)(arg0 + j * 4 + 0x1F2AC);
        v = *(s32 *)p;
        if (v != 0) {
            func_0046b0d0((void *)v);
            *(s32 *)p = 0;
        }
    }
    for (k = 0; k < 9; k++) {
        p = (u8 *)(arg0 + k * 4 + 0x1F2B8);
        v = *(s32 *)p;
        if (v != 0) {
            jtbl_008873EC[0]((void *)v);
            *(s32 *)p = 0;
        }
    }
}


/* measured: retail emits mov.s $f13,$f12 (6th arg 0.0f of the func_00375d50 call)
   right after move $a1, before the $a2/$a3 setup; mwcc b210 emits it after them
   (nd 6). Everything else in this function is solved and documented: stack locals
   sp68[2]@0x68, sp58[3]@0x58, sp48[3]@0x48, sp30[6]@0x30 (first declared gets the
   highest slot; arrays align to floor-pow2(size); sp30 is 24 bytes so the 0x3C
   store survives DSE); func_00375dd0/00375d50 need the 6-param prototype
   (u8*,s32,f32*,f32*,f32,f32) so floats stay single in $f12/$f13 (old-style ()
   promotes them to double); func_003760f0 needs f32* args 5/6; the loop-test
   reload of *(arg0+0x1F304) doubles as func_00373750's 2nd arg. Argument
   materialization scheduling floor. */
// FUN_00374730
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374730);


// FUN_00374910
void func_00374910(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
}


// FUN_00374960
void func_00374960(u8 *arg0) {
    func_0036d8b0();
    func_004577d0(func_00457120(), *(f32 *)(arg0 + 0x1F310));
    *(s32 *)(arg0 + 0x1F298) = func_0038cec0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F294) = func_00388bd0((void *)*(s32 *)(arg0 + 0x1F2A8));
    *(s32 *)(arg0 + 0x1F29C) = func_0038d790((void *)*(s32 *)(arg0 + 0x1F2A8));
}


// FUN_00374A10
void func_00374a10(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);

    switch (*(u32 *)(p + 4)) {
    case 0:
        break;
    case 1:
        if (func_00371a60(p + 0xC, 0) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 2:
        if (func_00371a60(p + 0xC, 1) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 3:
        if (func_00371a60(p + 0xC, 2) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 4:
        if (func_00371c70(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 5:
        func_00370640(p + 0xC);
        break;
    case 6:
        if (func_003720c0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 7:
        if (func_00372200(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 8:
        if (func_003724f0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    case 9:
        if (func_003726b0(p + 0xC) != 0) {
            *(u32 *)(p + 4) = 0;
        }
        break;
    default:
        func_0046d730(D_0064EA20, 0x1F5);
        break;
    }
    switch (*(s32 *)(p + 8)) {
    case 0:
        break;
    case 1:
        if (func_00372960(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    case 2:
        if (func_00372d60(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    case 3:
        func_00370cd0(p + 0x6C);
        break;
    case 4:
        if (func_00373170(p + 0x6C) != 0) {
            *(s32 *)(p + 8) = 0;
        }
        break;
    default:
        func_0046d730(D_0064EA20, 0x218);
        break;
    }
    func_003733f0(p + 0xD8);
    func_00373610(p + 0xE0);
    if ((func_00375910(p) != 0) && (*(u16 *)p & 1)) {
        func_00375f00(arg0, arg1);
        *(u16 *)p &= 0xFFFE;
    }
}


// FUN_00374CF0
void func_00374cf0(u8 *arg0) {
    func_0036df30(*(u8 **)arg0);
}


// FUN_00374D20
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00374d20);


/* measured: retail allocates count=$s2, i=$s3, p16=$s0, p21=$s5, p22=$s6 with
   the func_00374cf0 constant-address arg materialised AFTER the a0/a2 setup;
   mwcc b210 rotates count to $s5/p16 to $s1 and hoists the lui/addiu of
   func_00374cf0 before a0 (nd 194, obj 1092B). Everything else is solved: the
   0x70-byte color buffer at 0xB0 with the 0xFF bytes at 0x6C-0x6E, alpha at
   0x6F, arrA0[4] at 0xA0, the (s32)func_00374cf0 / (s32)&arrA0[i] casts the
   prototype demands, the mode switch with goto common from cases 0/1/2 (n/2,
   n/3, iGpffff8170), the u16 (x>>1)|(x&1) doubling for var_f20, and the
   func_003768e0/00375a70 tail loop. Arg-materialisation + saved-register
   rotation floor. */
// FUN_003753F0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003753f0);


// FUN_003757F0
void func_003757f0(u8 *arg0) {
    func_0034f1e0();
    if (*(u16 *)(arg0 + 0x1F2F4) & 4) {
        func_0036df30(arg0 + *(s32 *)(arg0 + 0x1F308) * 0xFB0);
    }
    if (*(u16 *)(arg0 + 0x1F2F4) & 8) {
        func_00374d20(arg0);
    }
}


// FUN_00375890
void func_00375890(u8 *arg0, s32 arg1, s32 arg2) {
    if (arg2) {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) |= 2;
    } else {
        *(u16 *)((u8 *)(arg1 * 0xE8) + (u32)arg0 + 0x1D6A0) &= 0xFFFD;
    }
}


// FUN_00375910
s32 func_00375910(u8 *arg0) {
    s32 b;

    b = func_00375970(arg0) != 0;
    if (b) {
        b = func_00375a00(arg0) != 0;
    }
    if (b) {
        b = func_00375a50(arg0) != 0;
    }
    return b;
}


// FUN_00375970
s32 func_00375970(u8 *arg0) {
    f32 var_f1;
    s32 temp_3;
    u32 temp_2;

    temp_3 = *(s32 *)(arg0 + 4);
    switch (temp_3) {
    case 0:
    case 5:
        return 1;
    default:
        temp_2 = *(u16 *)(arg0 + 0xC);
        if (temp_2 >= 0) {
            var_f1 = (f32)temp_2;
        } else {
            temp_2 = (temp_2 >> 1) | (temp_2 & 1);
            var_f1 = (f32)temp_2;
            var_f1 += var_f1;
        }
        return var_f1 >= *(f32 *)(arg0 + 0x10);
    }
}


// FUN_00375A00
s32 func_00375a00(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 8);
    switch (v) {
    case 0:
    case 3:
        return 1;
    default:
        return *(u16 *)(arg0 + 0x6C) >= *(u16 *)(arg0 + 0x6E);
    }
}


// FUN_00375A50
s32 func_00375a50(u8 *arg0) {
    return *(u16 *)(arg0 + 0xDC) >= *(u16 *)(arg0 + 0xDE);
}


/* measured: retail keeps idx in $a1 (arg1's dead register) and arg0 in $a0, recomputing
   addu $v1,$a1,$a0 per load (nd 29); mwcc b210 CSEs the base add into $a0 across the
   branch and keeps idx in $v0. Tried u16/u32 temps, s32/u8* arg0, inline vs named idx,
   operand orderings — all nd 29. Base-address CSE scheduling floor. */
// FUN_00375A70
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375a70);


// FUN_00375B40
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375b40);


// FUN_00375D50
void func_00375d50(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 1;
}


// FUN_00375DD0
void func_00375dd0(u8 *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 fparg0, f32 fparg1) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371990((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3);
    *(s32 *)(p + 0x1D6A4) = 2;
}


// FUN_00375E50
void func_00375e50(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00371ba0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg4, arg2, arg3);
    *(s32 *)(p + 0x1D6A4) = 4;
}


// FUN_00375EC0
void func_00375ec0(u8 *arg0, s32 arg1) {
    u8 *p = (u8 *)(arg1 * 0xE8) + (u32)arg0;
    *(u16 *)(p + 0x1D6A0) |= 1;
}


/* measured: retail keeps arg0/s1, idx/s0, p/s2 in three saved registers, using p for all
   four uses; mwcc b210 folds arg0+idx into one register (p/s0) and reads arg0 from a0
   directly, needing only two saved registers (nd 38). All variants with idx/p/arg0
   declaration permutations and operand orderings produce the same nd. */
// FUN_00375F00
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00375f00);


// FUN_00375FA0
void func_00375fa0(u8 *arg0, s32 arg1, s32 arg2, u8 *arg3, u8 *arg4, u8 *arg5) {
    ShuffleVec3 v3;
    ShuffleVec3 v4;
    ShuffleVec3 v5;
    s32 idx;

    v3 = *(ShuffleVec3 *)arg3;
    v4 = *(ShuffleVec3 *)arg4;
    v5 = *(ShuffleVec3 *)arg5;
    idx = arg1 * 0xE8;
    func_00371e50((u8 *)(arg0 + idx + 0x1D6AC), arg2, (f32 *)&v3, (f32 *)&v4, (f32 *)&v5);
    *(s32 *)((u8 *)idx + (u32)arg0 + 0x1D6A4) = 6;
}


// FUN_00376070
void func_00376070(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_003723a0((u8 *)(arg0 + idx + 0x1D6AC), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A4) = 8;
}


// FUN_003760F0
void func_003760f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 *arg4, f32 *arg5) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372870((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5);
    *(s32 *)(p + 0x1D6A8) = 1;
}


// FUN_00376170
void func_00376170(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 idx = arg1 * 0xE8;
    u8 *p = (u8 *)idx + (u32)arg0;

    func_00372c30((u8 *)(arg0 + idx + 0x1D70C), (u8 *)arg2, (u8 *)arg3, (u8 *)arg4, (u8 *)arg5, (u8 *)arg6);
    *(s32 *)(p + 0x1D6A8) = 2;
}


// FUN_003761F0
void func_003761f0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, void *arg4) {
    ShuffleVec3 v;
    s32 idx;
    u8 *p;

    v = *(ShuffleVec3 *)arg4;
    idx = arg1 * 0xE8;
    p = (u8 *)idx + (u32)arg0;
    func_003730f0((u8 *)(arg0 + idx + 0x1D70C), arg2, arg3, &v);
    *(s32 *)(p + 0x1D6A8) = 4;
}


// FUN_00376290
void func_00376290(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_003733d0((u8 *)(arg0 + idx + 0x1D778), arg2, arg3, arg4);
}


// FUN_003762E0
void func_003762e0(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 idx = arg1 * 0xE8;

    func_00373590((u8 *)(arg0 + idx + 0x1D780), arg2, arg3, arg4);
}


// FUN_00376330
void func_00376330(u8 *arg0, s32 arg1, f32 *arg2) {
    u8 *p = (u8 *)(arg0 + arg1 * 0xE8 + 0x1D6A0);
    switch (*(u32 *)(p + 4)) {
    case 0:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x18);
        return;
    case 1:
    case 2:
    case 3:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    case 5:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x54);
        return;
    case 4:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x48);
        return;
    case 6:
        func_00371160(p + 0x38, p + 0x2C, p + 0x44, arg2, p, *(f32 *)(p + 0x28));
        return;
    case 7:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    case 8:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
    case 9:
        *(ShuffleVec3 *)arg2 = *(ShuffleVec3 *)(p + 0x30);
        return;
    default:
        func_0046d730(D_0064EA20, 0x4DA);
        return;
    }
}


/* measured: retail emits the two saved-register setup moves (mov.s $f20,$f12 then
   move $s1,$a2) with the FP move first; mwcc b210 emits the GPR move first (nd 4).
   Everything else is solved: u8 *arg0, idx/p locals, the full 0-9 case switch, and
   func_00371f40's interleaved prototype (u8*, f32, u8*) which fixes the pre-jal
   materialisation order. Saved-register setup-order scheduling floor. */
// FUN_003764B0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003764b0);

// FUN_00376590
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00376590);


// FUN_003766F0
void func_003766f0(f32 **arg0, s32 arg1, s32 arg2, u8 *arg3) {
    f32 **var_19;
    f32 *temp_2;
    f32 *temp_3;
    f32 key;

    func_0044ea90(D_0064EA20, 0x589);
    temp_2 = (f32 *)D_008873F4[0](1, 0x10, 0x40000);
    if (temp_2 == NULL) {
        func_0046d730(D_0064EA20, 0x58A);
    }
    key = func_00373c20(arg3);
    *(s32 *)(temp_2 + 1) = arg1;
    *(s32 *)(temp_2 + 2) = arg2;
    temp_2[0] = key;
    var_19 = arg0;
    while ((temp_3 = *var_19) != NULL) {
        if (!(temp_2[0] <= temp_3[0])) break;
        var_19 = (f32 **)(temp_3 + 3);
    }
    if (temp_3 == NULL) {
        *var_19 = temp_2;
        *(f32 **)(temp_2 + 3) = NULL;
        return;
    }
    *(f32 **)(temp_2 + 3) = temp_3;
    *var_19 = temp_2;
}


// FUN_00376800
void func_00376800(u8 **arg0, s32 arg1) {
    u8 *var_16;

    var_16 = *arg0;
    while (var_16 != NULL) {
        (*(void (**)(s32))(var_16 + 4))(*(s32 *)(var_16 + 8));
        var_16 = *(u8 **)(var_16 + 0xC);
    }
    if (arg1 != 0) {
        func_00376880(arg0);
    }
}


/* measured: retail re-loads *arg0 at the top of each iteration; mwcc b210 CSEs it with the
   loop test at the bottom and keeps it in $a0, so the body is one load short (nd 18). */
// FUN_00376880
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00376880);


// FUN_003768E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_003768e0);


/* measured: the camera-matrix normalisation block uses the FPU accumulator idiom
   (mula.s $f4,$f4 / madda.s $f11,$f11 / madda.s $f12,$f12 / madd.s $f1,$f3,$f3
   then 2.0f/... and the 9 rotation-matrix element products) which m2c marks
   M2C_ERROR; no C float spelling reproduces the ACC-fused instructions
   byte-for-byte (same floor as btlAICommand func_001de370, effBlurFilter
   func_004a8da0, and sibling func_00378280/00374d20). The rest decodes cleanly:
   arg2 vec or arg0+arg1*0xE8+0x1D6B8 vec into sp1B8, the sp70 vec, the
   func_0036de70/0036deb0 half extents into sp80..spAC (with -f22/-f21 negations),
   the 4-iteration loop storing rotated vecs and doubled-alpha colors
   (u8 (x>>1)|(x&1) idiom) into sp+var_16*0x40+0xB0, and the D_00887300/
   D_00887310/func_00364c50/00364c70 tail. FPU FMA-fusion floor. */
// FUN_00377930
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377930);


// FUN_00377E10
s32 func_00377e10(u8 *arg0) {
    s32 *p = *(s32 **)(arg0 + 0x38);

    if (func_00378220() == 0) {
        *p = func_00354830((u8 *)p + 8);
    }
    return 0;
}


// FUN_00377E60
void func_00377e60(u8 *arg0) {
    u8 *p = *(u8 **)(arg0 + 0x38);

    func_003549d0(p + 8);
    jtbl_008873EC[0](p);
}


/* measured: retail allocates the copy loops as dst=$a0, i=$a1, p=$v0, 0xFF=$v1
   (0xFF hoisted to the preheader); mwcc b210 rotates i to $v0/$a0 and p to $v1,
   materialising 0xFF inside the loop — every instruction is otherwise identical
   (nd 64, obj 800B = window). Everything else in this function is solved: the
   stack layout spA0[3]@0xA0 / sp90[3]@0x90 / sp60[4][3]@0x60 / sp50[4]@0x50 /
   sp40[4]@0x40, the element-wise spill copies via a block-scoped f32* q, the
   +30/-30 shared materialisation (temp_f1 = 30.0f, stores via -temp_f1), the gp
   value in temp_f0/temp_f0_2, the two 4-iteration copy loops to mem[i*0x24+0x120]
   and +0x1B0, and func_00451fc0's 8-arg call. Temp-register rotation floor. */
// FUN_00377EB0
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00377eb0);


// FUN_003781D0
void func_003781d0(u8 *arg0, s32 arg1) {
    char buf[0x100];
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    func_00442088(buf, D_0064EA80, arg1 & 0xFF);
    func_003547c0((s32 *)(temp_16 + 8), (u8 *)buf);
    *(s32 *)temp_16 = 0;
}


// FUN_00378220
s32 func_00378220(u8 *arg0) {
    return *(u32 *)(*(u8 **)(arg0 + 0x38)) != 0;
}


// FUN_00378240
s32 func_00378240(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x120;
}


// FUN_00378250
s32 func_00378250(u8 *arg0) {
    return *(s32 *)(arg0 + 0x38) + 0x1B0;
}


// FUN_00378260
void func_00378260(u8 *arg0, u8 arg1, u8 arg2, u8 arg3, s32 arg4) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    temp[0x11C] = arg1;
    temp[0x11D] = arg2;
    temp[0x11E] = arg3;
    *(s32 *)(temp + 4) = arg4;
}


/* measured: retail's loop body uses the FPU accumulator idiom (adda.s $f2,$f3 /
   msuba.s $f6,$f0 / msub.s $f4,$f5,$f4 after the signed (3-i)/2 and (3-i)%2
   splits) which m2c marks M2C_ERROR; no C float spelling reproduces the
   ACC-fused instructions byte-for-byte (same floor as btlAICommand func_001de370
   and effBlurFilter func_004a8da0). The rest decodes cleanly: u8 arg1 stored to
   p[0x11F], p = *(u8**)(arg0+0x38), the (*(s32*)(p+4)!=0) branch loading
   iGpffff8308/iGpffff8218, the byte-to-float (x>>1)|(x&1) doubling idiom, the
   float-to-byte clamp via c.le.s 0x4F000000 with 0x80000000 or, and the
   4-iteration loop storing 0xFF/alpha to p[i*0x24+0x12C..]. FPU FMA-fusion
   floor. */
// FUN_00378280
INCLUDE_ASM("asm/nonmatchings/btlShuffleDraw", func_00378280);


// FUN_00378500
s32 func_00378500(u8 *arg0) {
    u8 *temp = *(u8 **)(arg0 + 0x38);
    if ((u8)(*(u32 *)temp != 0) != 0) {
        return *(u32 *)(*(u8 **)(temp + 0x14));
    }
    return 0;
}


// FUN_00378530
s32 func_00378530(s32 arg0, s32 arg1) {
    s32 var_2;

    switch (arg1) {
    case 0:
        return arg0;
    case 1:
        return arg0;
    case 2:
        return arg0;
    case 3:
        return arg0 * 2;
    case 4:
        if (arg0 < 6) {
            var_2 = arg0 * 6;
        } else {
            var_2 = arg0 * 3;
        }
        return var_2;
    default:
        func_0046d730(&D_0064EA20, 0x854);
        return 0;
    }
}

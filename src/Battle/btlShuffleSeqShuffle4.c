#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle4.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"

extern void func_0046d730(const void *file, u32 line);
extern u32 RpRandom();
extern s32 func_00378530(s32 a, s32 b);
extern s32 func_003717e0(u8 *a, f32 *b);
extern f32 RwV2dLength(f32 *a);
extern f32 func_003e41e0(f32 *a, f32 *b);
extern void func_00375dd0(u8 *ctx, s32 idx, f32 *a, f32 *b, f32 c, f32 d);
extern void func_00376170(u8 *ctx, s32 idx, u16 start, u16 end, f32 *from, f32 *rot, f32 *axis);
extern s32 func_0037d270(u8 *a, s64 b, s64 c);
extern s32 func_00378a70(u8 *a, s32 b);
extern s32 func_00379240(u8 *a);
extern s32 func_00379420(u8 *a);
extern void func_0038d060(u8 *a);
extern void func_0038d0d0(u8 *a, s32 b);
extern void func_0038d0a0(u8 *a);
extern void func_00375b40(u8 *a, s32 b, u16 c, u16 d);
extern void func_003799d0(u8 *a);
extern s32 func_003789d0(u8 *a, s32 b);
extern void func_003713b0(u8 *a);
extern s32 func_00378930(u8 *a, s32 b);
extern void func_00375d50(u8 *a, s32 b, f32 e, f32 f, f32 *c, f32 *d);
extern void func_003760f0(u8 *a, s32 b, u16 c, u16 d, f32 *e, f32 *f);
extern void func_00376290(u8 *a, s32 b, s32 c, s32 d, s32 e);
extern void func_0038d2c0(u8 *a);
extern void func_0036dc60(u8 *a, f32 *b, f32 d, f32 *c);
extern void func_00375ec0(u8 *a, s32 b);
extern s32 datGetFlag(s32 a);
extern void func_003798d0(u8 *a, s32 b);
extern void func_00389110(u8 *a);
extern s32 func_00389160(u8 *a);
extern void func_0038d160(u8 *a);
extern void func_00388f20(u8 *a);
extern s32 func_00375910(u8 *a);
extern s32 func_00379150(u8 *a, s32 b, s32 c);
extern s32 func_0036de60(u8 *a);
extern void func_0038d1d0(u8 *a);
extern void func_00388f40(u8 *a);
extern s32 func_00379c70(u8 *a, s32 b);
extern void func_00378f90(u8 *a, s32 b, s32 c);
extern void func_00375890(u8 *a, s32 b, s32 c);
extern void func_00379090(u8 *a, s32 b, u16 c, s32 d);
extern void func_00378ec0(u8 *a, s32 b);
extern s32 func_00379d70(u8 *a);
extern s32 func_00379a70(u8 *a);
extern s32 func_00379920(u8 *a);
extern void func_00106390(s32 a, s32 b);
extern void func_0037c720(u8 *arg0);
extern void func_0037d460(u8 *arg0);
extern void func_0037d630(u8 *arg0, s32 arg1, u16 arg2, u16 arg3);
extern void func_0037d840(u8 *arg0);
extern void func_0037ca60(u8 *arg0, s32 arg1, f32 *arg2);

extern u16 D_008C024E[];

extern u32 D_0064EB20[];
extern u16 D_008C027A[];
extern u8 D_0064E6BA[];
extern u8 D_0064E6BB[];
extern u8 D_0064E6CA[];
extern u8 D_0064E6CB[];
extern f32 iGpffff83f0;
extern f32 iGpffff83f4;
extern f32 iGpffff83e8;
extern f32 iGpffff83ec;

/* 824/832 bytes; 19 resolved relocations; eight zero alignment bytes.
 * Promoted byte snapshots preserve signed inclusive spans; u16 casts retain
 * retail truncation before the count checks and mode dispatch. */
// FUN_0037C720
void func_0037c720(u8 *arg0) {
    u8 *base;
    s32 idx;
    s32 lo1;
    s32 d1;
    s32 hi1;
    f32 ratio1;
    f32 v1;
    u16 t1;
    s32 lo2;
    s32 d2;
    s32 hi2;
    f32 ratio2;
    f32 v2;
    s32 t2;
    s32 mode;

    base = arg0 + 0x1F1D0;
    idx = *(s32 *)(arg0 + 0x1F304);
    lo1 = D_0064E6BA[idx * 2];
    hi1 = D_0064E6BB[idx * 2];
    ratio1 = (f32)(u32)(RpRandom() & 0xFFF) / 4096.0f;
    d1 = hi1 - lo1 + 1;
    v1 = (f32)d1 * ratio1 + (f32)lo1;
    t1 = (u16)v1;
    *(u16 *)(base + 0xA) = t1;
    if (*(u16 *)(base + 0xA) > 0x10) {
        func_0046d730(&D_0064EB20[0], 0x32);
    }
    if (*(s32 *)(arg0 + 0x1F300) == 3) {
        *(s16 *)(base + 0x2C) = 0;
    } else {
        lo2 = D_0064E6CA[idx * 2];
        hi2 = D_0064E6CB[idx * 2];
        ratio2 = (f32)(u32)(RpRandom() & 0xFFF) / 4096.0f;
        d2 = hi2 - lo2 + 1;
        v2 = (f32)d2 * ratio2 + (f32)lo2;
        t2 = (u16)v2;
        mode = *(s32 *)(arg0 + 0x1F300);
        switch (mode) {
        case 0:
            *(s16 *)(base + 2) = 10;
            break;
        case 1:
            *(s16 *)(base + 2) = 8;
            break;
        case 2:
            *(s16 *)(base + 2) = 5;
            break;
        default:
            func_0046d730(&D_0064EB20[0], 0x49);
            break;
        }
        if (t2 <= 0) {
            t2 = 1;
        }
        *(s16 *)(base + 0x2C) = t2;
    }
    if (*(u16 *)(base + 0x2C) > 0x10) {
        func_0046d730(&D_0064EB20[0], 0x4E);
    }
}

// measured: plain C reaches object 2052B/window 2064B but leaves normalized_diff
// 190; all case CFGs and stack frame match, but retail's FPU MAC schedules differ.
// Restored the bare assembly fallback.
// FUN_0037CA60 NONMATCHING
#ifdef NON_MATCHING
void func_0037ca60(u8 *arg0, s32 arg1, f32 *arg2) {
    s32 n;
    if (*(s32 *)(arg0 + 0x1F2FC) != 3) {
        func_0046d730(&D_0064EB20[0], 0x5B);
    }
    n = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    switch (n) {
    case 6:
        arg2[0] = 320.0f + 80.0f * ((f32)(arg1 % 3) - 1.0f);
        arg2[1] = 224.0f + 100.0f * ((f32)(arg1 / 3) - 0.5f);
        break;
    case 8:
        if (arg1 < 4) {
            arg2[0] = 320.0f + 80.0f * ((f32)arg1 - 1.5f);
            arg2[1] = 174.0f;
        } else {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 4) - 1.5f);
            arg2[1] = 274.0f;
        }
        break;
    case 10:
        if (arg1 < 3) {
            arg2[0] = 320.0f + 80.0f * ((f32)arg1 - 1.0f);
            arg2[1] = 74.0f;
        } else if (arg1 < 5) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 3) - 0.5f);
            arg2[1] = 174.0f;
        } else if (arg1 < 7) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 5) - 0.5f);
            arg2[1] = 274.0f;
        } else {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 7) - 1.0f);
            arg2[1] = 374.0f;
        }
        break;
    case 12:
        if (arg1 < 3) {
            arg2[0] = 320.0f + 80.0f * ((f32)arg1 - 1.0f);
            arg2[1] = 74.0f;
        } else if (arg1 < 6) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 3) - 1.0f);
            arg2[1] = 174.0f;
        } else if (arg1 < 9) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 6) - 1.0f);
            arg2[1] = 274.0f;
        } else {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 9) - 1.0f);
            arg2[1] = 374.0f;
        }
        break;
    case 14:
        if (arg1 < 4) {
            arg2[0] = 320.0f + 80.0f * ((f32)arg1 - 1.5f);
            arg2[1] = 74.0f;
        } else if (arg1 < 7) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 4) - 1.0f);
            arg2[1] = 174.0f;
        } else if (arg1 < 11) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 7) - 1.5f);
            arg2[1] = 274.0f;
        } else {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 11) - 1.0f);
            arg2[1] = 374.0f;
        }
        break;
    case 16:
        if (arg1 < 4) {
            arg2[0] = 320.0f + 80.0f * ((f32)arg1 - 1.5f);
            arg2[1] = 74.0f;
        } else if (arg1 < 8) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 4) - 1.5f);
            arg2[1] = 174.0f;
        } else if (arg1 < 12) {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 8) - 1.5f);
            arg2[1] = 274.0f;
        } else {
            arg2[0] = 320.0f + 80.0f * ((f32)(arg1 - 12) - 1.5f);
            arg2[1] = 374.0f;
        }
        break;
    default:
        func_0046d730(&D_0064EB20[0], 0x116);
        break;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle4", func_0037ca60);
#endif
// FUN_0037D270
s32 func_0037d270(u8 *arg0, s64 arg1, s64 arg2) {
    f32 spA8[2];
    f32 spA0[2];
    s64 sp98;
    s64 sp90;
    f32 best1dist;
    f32 best2dist;
    f32 arg2x;
    f32 arg2y;
    f32 dist;
    f32 dot;
    u16 cur16;
    s32 n;
    s32 i;
    s32 cur;
    s32 best1;
    s32 best2;

    sp90 = arg1;
    sp98 = arg2;
    arg2y = *(f32 *)((u8 *)&sp98 + 4);
    arg2x = *(f32 *)&sp98;
    func_003e41e0((f32 *)&sp90, (f32 *)&sp90);
    cur16 = *(u16 *)(arg0 + 0x1F1D4);
    n = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    best1dist = 1088.0f;
    cur = cur16 & 0xFFFF;
    best1 = cur;
    best2dist = 0.0f;
    best2 = cur;
    i = 0;
    for (; i < n; i++) {
        if (i == cur) {
            continue;
        }
        func_003717e0(arg0 + i * 0xE8 + 0x1D6B8, spA0);
        spA8[0] = spA0[0] - arg2x;
        spA8[1] = spA0[1] - arg2y;
        dist = RwV2dLength(spA8);
        func_003e41e0(spA8, spA8);
        dot = *(f32 *)&sp90 * spA8[0] + *(f32 *)((u8 *)&sp90 + 4) * spA8[1];
        if (dot > iGpffff83f0) {
            if (dist < best1dist) {
                best1dist = dist;
                best1 = i & 0xFFFF;
            }
        } else if (-dot > iGpffff83f4 && dist > best2dist) {
            best2dist = dist;
            best2 = i & 0xFFFF;
        }
    }
    if ((best1 & 0xFFFF) == cur) {
        best1 = best2 & 0xFFFF;
    }
    return best1;
}

// FUN_0037D460
void func_0037d460(u8 *arg0) {
    u8 *base = arg0 + 0x1F1D0;
    f32 sp48[2];
    s64 sp40;
    u8 *p;
    s32 n;
    u16 cur;
    u16 ret;

    p = (u8 *)sp48;
    n = 8;
    if (p != NULL) {
        do {
            *p = 0;
            p += 1;
            n -= 1;
        } while (n != 0);
    }
    if (*(s32 *)(arg0 + 0x1F2FC) != 3) {
        func_0046d730(&D_0064EB20[0], 0x1A6);
    }
    cur = *(u16 *)(base + 4);
    func_003717e0(arg0 + cur * 0xE8 + 0x1D6B8, (f32 *)&sp40);
    if (D_008C027A[0] & 0x1000) {
        sp48[1] -= 1.0f;
    }
    if (D_008C027A[0] & 0x4000) {
        sp48[1] += 1.0f;
    }
    if (D_008C027A[0] & 0x8000) {
        sp48[0] -= 1.0f;
    }
    if (D_008C027A[0] & 0x2000) {
        sp48[0] += 1.0f;
    }
    if (RwV2dLength(sp48) != 0.0f) {
        ret = (u16)(func_0037d270(arg0, *(s64 *)sp48, sp40) & 0xFFFF);
        if (ret != (cur & 0xFFFF)) {
            *(u16 *)(base + 4) = ret;
            func_0045af60(0, 4, 0, 0);
        }
    }
}

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

// FUN_0037D630
void func_0037d630(u8 *arg0, s32 arg1, u16 arg2, u16 arg3) {
    u8 *base = arg0 + 0x1F1D0;
    s32 off;
    u8 *p;
    f32 sp80[3];
    f32 rot[4];
    f32 axis[4];
    f32 f12;
    f32 f13;

    off = arg1 * 0xE8;
    p = (u8 *)(off + (s32)arg0);
    if (*(s32 *)(p + 0x1D6A4) == 5) {
        *(Vec3f *)sp80 = *(Vec3f *)(p + 0x1D6C4);
    } else {
        *(Vec3f *)sp80 = *(Vec3f *)(p + 0x1D6B8);
    }
    f12 = arg2;
    f13 = arg3;
    func_00375dd0(arg0, arg1, 0, sp80, f12, f13);
    axis[3] = iGpffff83e8;
    axis[0] = 0.0f;
    axis[1] = iGpffff83ec;
    axis[2] = 0.0f;
    rot[3] = 0.0f;
    rot[0] = 0.0f;
    rot[1] = 1.0f;
    rot[2] = 0.0f;
    func_00376170(arg0, arg1, arg2, arg3, NULL, rot, axis);
    *(u16 *)(base + 6) |= (1 << arg1) & 0xFFFF;
    if (!(*(u16 *)base & 2)) {
        *(s32 *)(base + 0x30) = arg1;
        *(u16 *)base |= 2;
        return;
    }
    *(s32 *)(base + 0x34) = arg1;
    *(u16 *)base |= 4;
}



// measured: plain C reproduces the shuffle loop and frame; only the commutative multiply operand order differs at two instructions (normalized_diff 2), with object 540B versus retail window 544B. Parked because nd <= 25.
// Committed at nd 2.
// measured: explicit `(f32)` cast on the right multiply operand preserves retail's mul.s operand order; object 540B, retail window 544B, normalized_diff 0.
// Verified live MATCH.
// FUN_0037D840
void func_0037d840(u8 *arg0) {
    u8 buf[0xFB0];
    u8 *var_8;
    u8 *var_7;
    u8 *var_6;
    s32 var_5;
    s32 n;
    s32 var_18;
    s32 var_16;
    s32 temp_3;
    s32 t1;
    s32 t2;
    f32 var_f1;
    f32 temp_f0;

    if (*(s32 *)(arg0 + 0x1F2FC) != 3) {
        func_0046d730(&D_0064EB20[0], 0x23B);
    }
    n = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    var_18 = n - 1;
    while (var_18 > 0) {
        temp_3 = RpRandom() & 0xFFF;
        var_f1 = (f32)(u32)temp_3;
        temp_f0 = var_f1 / 4096.0f;
        temp_f0 = (f32)(var_18 + 1) * (f32)temp_f0;
        var_16 = (s32)temp_f0;
        if ((var_18 < 0) || (var_18 >= n)) {
            func_0046d730(&D_0064EB20[0], 0x243);
        }
        if ((var_16 < 0) || (var_16 >= n)) {
            func_0046d730(&D_0064EB20[0], 0x244);
        }
        var_8 = arg0 + var_18 * 0xFB0;
        var_6 = buf;
        var_5 = 0x1F6;
        var_7 = var_8;
        do {
            t1 = *(s32 *)(var_7 + 0);
            t2 = *(s32 *)(var_7 + 4);
            var_7 += 8;
            var_5 -= 1;
            *(s32 *)(var_6 + 0) = t1;
            *(s32 *)(var_6 + 4) = t2;
            var_6 += 8;
        } while (var_5 > 0);
        var_7 = arg0 + var_16 * 0xFB0;
        var_5 = 0x1F6;
        var_6 = var_7;
        do {
            t1 = *(s32 *)(var_6 + 0);
            t2 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_5 -= 1;
            *(s32 *)(var_8 + 0) = t1;
            *(s32 *)(var_8 + 4) = t2;
            var_8 += 8;
        } while (var_5 > 0);
        var_6 = buf;
        var_5 = 0x1F6;
        do {
            t1 = *(s32 *)(var_6 + 0);
            t2 = *(s32 *)(var_6 + 4);
            var_6 += 8;
            var_5 -= 1;
            *(s32 *)(var_7 + 0) = t1;
            *(s32 *)(var_7 + 4) = t2;
            var_7 += 8;
        } while (var_5 > 0);
        var_18 -= 1;
    }
}

/* Deal state machine for the fourth shuffle layout, the twin of the three in
   code1_0037.c.  Releasing a held card and drawing a free card are inline
   helpers that retail expands in place.  The frame arguments of the card
   animation setters are u16 throughout, so the (u16) conversions happen at
   each call.  measured: 4904B of code in the 4912B window (two zero words). */
static inline void shuffle4Release(u8 *arg0, s32 card, u16 frames)
{
    u8 *base = arg0 + 0x1F1D0;
    f32 rot[4];
    f32 axis[4];

    func_00375ec0(arg0, card);
    axis[3] = iGpffff83ec;
    axis[0] = 0.0f;
    axis[1] = iGpffff83ec;
    axis[2] = 0.0f;
    rot[3] = 1.0f;
    rot[0] = 0.0f;
    rot[1] = 0.0f;
    rot[2] = 0.0f;
    func_00376170(arg0, card, 0, frames, NULL, rot, axis);
    *(u16 *)(base + 6) &= ~(1 << card);
    if (*(u16 *)base & 4) {
        *(s32 *)(base + 0x34) = -1;
        *(u16 *)base &= 0xFFFB;
    } else {
        *(s32 *)(base + 0x30) = -1;
        *(u16 *)base &= 0xFFFD;
    }
}

static inline u16 shuffle4PickFree(u8 *arg0)
{
    u8 *base = arg0 + 0x1F1D0;
    s32 n;
    u16 c;

    n = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    do {
        c = n * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
    } while (*(u16 *)(base + 6) & (u16)(1 << c));
    return c;
}

/* measured: without loop-invariant hoisting the pick loop keeps its work base
   in the loop body (674 differing words). */
#pragma opt_loop_invariants on
// FUN_0037DA60
s32 func_0037da60(u8 *arg0)
{
    f32 pos[2];
    f32 vec[3];
    f32 rot[4];
    f32 scale;
    f32 t;
    u8 *sbase;
    u8 *deck;
    s32 total;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 card;
    u16 c;
    u16 limit;
    u16 speed;

    scale = 1.0f - (0.5f * (f32)(*(s32 *)(arg0 + 0x1F304) - 3)) / 5.0f;
    sbase = arg0 + 0x1F1D0;
    total = func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC));
    switch (*(u32 *)(arg0 + 0x1F2F8)) {
    case 0:
        if (func_00378a70(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        func_0037c720(arg0);
        if (func_00379240(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 1;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (func_00379420(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 2;
    case 2:
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0) {
            break;
        }
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 3;
        break;
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 4;
            *(u16 *)(sbase + 8) = 0;
            for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
                func_00375b40(arg0, i, (u16)i, (u16)i + 10);
                *(u16 *)(arg0 + 0x1F1D6) ^= (u16)(1 << i);
            }
            func_0045af60(0, 4, 0, 1);
            func_0045af60(1, 0, 5, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            func_003799d0(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0x14;
        }
        break;
    case 4:
        if (func_003789d0(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u32 *)(arg0 + 0x1F2F8) = 6;
        *(u16 *)(sbase + 8) = 0;
        *(u16 *)(sbase + 6) = 0;
        func_003713b0((u8 *)vec);
        for (i = 0; i < *(s32 *)(arg0 + 0x1F304); i++) {
            func_00375dd0(arg0, i, NULL, vec, (u16)i, (u16)(i + 10));
        }
        func_0045af60(1, 0, 5, 2);
    case 6:
        if (func_00378930(arg0, *(s32 *)(arg0 + 0x1F304)) == 0) {
            break;
        }
        func_003713b0((u8 *)vec);
        rot[3] = 1.0f;
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = 0.0f;
        for (i = 0; i < total; i++) {
            func_00375d50(arg0, i, 0.0f, 0.0f, vec, vec);
            func_003760f0(arg0, i, 0, 0, rot, rot);
            func_00376290(arg0, i, 0, 0xFF, 0xFF);
        }
        func_0038d2c0(*(u8 **)(arg0 + 0x1F298));
        *(u16 *)(arg0 + 0x1F2F4) |= 1;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        for (i = 0; i < total; i++) {
            func_0037ca60(arg0, i, pos);
            func_0036dc60(arg0 + i * 0xFB0, pos, 67.0f, vec);
            t = scale * i;
            func_00375dd0(arg0, i, NULL, vec, (u16)t, (u16)(5.0f + t));
            func_00375ec0(arg0, i);
        }
        func_0045af60(1, 0, 5, 2);
    case 5:
        if (func_00378930(arg0, total) == 0) {
            break;
        }
        if (datGetFlag(0x1432) == 0) {
            func_003798d0(arg0, 2);
            *(u32 *)(arg0 + 0x1F2F8) = 0x15;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u16 *)(arg0 + 0x1F2F4) |= 2;
            break;
        }
        func_0037d840(arg0);
        if (*(u16 *)(sbase + 0x2C) > 0) {
            for (k = 0; k < *(u16 *)(sbase + 0x2C); k++) {
                *(u16 *)(sbase + k * 2 + 0xC) = shuffle4PickFree(arg0);
                func_0037d630(arg0, *(u16 *)(sbase + k * 2 + 0xC), 0, *(u16 *)(sbase + 2));
            }
            func_0045af60(1, 0, 5, 1);
            *(u16 *)(arg0 + 0x1F2F0) = 0;
            *(u32 *)(arg0 + 0x1F2F8) = 7;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 9;
        }
        break;
    case 7:
        if (func_003789d0(arg0, total) == 0) {
            break;
        }
        switch (*(s32 *)(arg0 + 0x1F300)) {
        case 0:
            limit = 5;
            break;
        case 1:
            limit = 3;
            break;
        case 2:
            limit = 1;
            break;
        default:
            func_0046d730(&D_0064EB20[0], 0x26C);
            limit = 0;
            break;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < limit) {
            break;
        }
        for (j = 0; j < *(u16 *)(sbase + 0x2C); j++) {
            speed = *(u16 *)(sbase + 2);
            card = *(u16 *)(sbase + j * 2 + 0xC);
            shuffle4Release(arg0, card, speed);
        }
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 8;
        *(u16 *)(arg0 + 0x1F2F0) = 0;
    case 8:
        if (func_003789d0(arg0, total) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 9;
        *(u16 *)(sbase + 8) = 0;
    case 9:
        func_00389110(*(u8 **)(arg0 + 0x1F294));
        *(u32 *)(arg0 + 0x1F2F8) = 0xA;
    case 10:
        if (func_00389160(*(u8 **)(arg0 + 0x1F294)) == 0) {
            break;
        }
        func_0038d160(*(u8 **)(arg0 + 0x1F298));
        func_00388f20(*(u8 **)(arg0 + 0x1F294));
        deck = *(u8 **)(arg0 + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 3);
        *(u32 *)(arg0 + 0x1F2F8) = 0xB;
    case 11:
        if ((D_008C024E[0] & 0x40) != 0) {
            if (*(u16 *)(sbase + 6) & (u16)(1 << *(u16 *)(sbase + 4))) {
                break;
            }
            func_0037d630(arg0, *(u16 *)(sbase + 4), 0, 0xA);
            *(u32 *)(arg0 + 0x1F2F8) = 0xC;
            func_0045af60(1, 0, 5, 1);
        } else {
            func_0037d460(arg0);
        }
        break;
    case 12:
        if (func_00375910(arg0 + *(u16 *)(sbase + 4) * 0xE8 + 0x1D6A0) == 0) {
            break;
        }
        if ((*(u16 *)sbase & 2) && (*(u16 *)sbase & 4)) {
            *(u32 *)(arg0 + 0x1F2F8) = 0xD;
            *(u16 *)(arg0 + 0x1F2F0) = 0;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 0xB;
        }
        break;
    case 13:
        if (func_00379150(arg0, *(s32 *)(sbase + 0x30), *(s32 *)(sbase + 0x34)) != 0 &&
            func_0036de60(arg0 + *(s32 *)(sbase + 0x30) * 0xFB0) != 2) {
            func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
            func_0038d1d0(*(u8 **)(arg0 + 0x1F298));
            func_00388f40(*(u8 **)(arg0 + 0x1F294));
            *(u32 *)(arg0 + 0x1F2F8) = 0xE;
            break;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0xA) {
            break;
        }
        shuffle4Release(arg0, *(s32 *)(sbase + 0x34), 0xA);
        shuffle4Release(arg0, *(s32 *)(sbase + 0x30), 0xA);
        func_0045af60(1, 0, 5, 1);
        if (++*(u16 *)(sbase + 8) >= *(u16 *)(sbase + 0xA)) {
            func_0038d0a0(*(u8 **)(arg0 + 0x1F298));
            func_0038d1d0(*(u8 **)(arg0 + 0x1F298));
            func_00388f40(*(u8 **)(arg0 + 0x1F294));
            func_00379c70(arg0, -1);
            *(u32 *)(arg0 + 0x1F2F8) = 0x12;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 0xB;
        }
        break;
    case 14:
        for (i = 0; i < total; i++) {
            if (i != *(s32 *)(sbase + 0x30) && i != *(s32 *)(sbase + 0x34)) {
                func_00378f90(arg0, i, 0x14);
            }
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xF;
    case 15:
        if (func_00378a70(arg0, total) == 0) {
            break;
        }
        for (i = 0; i < total; i++) {
            if (i != *(s32 *)(sbase + 0x30) && i != *(s32 *)(sbase + 0x34)) {
                func_00375890(arg0, i, 0);
            }
        }
        func_00379090(arg0, *(s32 *)(sbase + 0x30), 0xA, 1);
        func_00379090(arg0, *(s32 *)(sbase + 0x34), 0xA, -1);
        *(u32 *)(arg0 + 0x1F2F8) = 0x10;
    case 16:
        if (func_00378a70(arg0, total) == 0) {
            break;
        }
        *(u16 *)((u8 *)(*(s32 *)(sbase + 0x34) * 0xE8) + (u32)arg0 + 0x1D6A0) &= 0xFFFD;
        func_00378ec0(arg0, *(s32 *)(sbase + 0x30));
        *(u16 *)sbase |= 8;
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 0x11;
    case 17:
        if (func_00375910(arg0 + *(s32 *)(sbase + 0x30) * 0xE8 + 0x1D6A0) != 0) {
            break;
        }
        func_00379c70(arg0, *(s32 *)(sbase + 0x30));
        *(u32 *)(arg0 + 0x1F2F8) = 0x12;
    case 18:
        if (func_00379d70(arg0) == 0) {
            break;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0x13;
    case 19:
        return 1;
    case 20:
        if (func_00379a70(arg0) == 0) {
            break;
        }
        if (*(s32 *)(arg0 + 0x1F248) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 0x13;
        } else {
            *(u32 *)(arg0 + 0x1F2F8) = 3;
        }
        break;
    case 21:
        if (func_00379920(arg0) == 0) {
            break;
        }
        if (*(u16 *)(arg0 + 0x1F2F4) & 2) {
            *(u16 *)(arg0 + 0x1F2F4) = *(u16 *)(arg0 + 0x1F2F4) & 0xFFFD;
        }
        if (++*(u16 *)(arg0 + 0x1F2F0) < 0x1E) {
            break;
        }
        func_00106390(0x1432, 1);
        *(u32 *)(arg0 + 0x1F2F8) = 5;
        break;
    default:
        func_0046d730(&D_0064EB20[0], 0x3F6);
        break;
    }
    return 0;
}
#pragma opt_loop_invariants off

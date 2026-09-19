#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle4.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"

extern void func_0046d730(const void *file, u32 line);
extern u32 func_003b7060();
extern s32 func_00378530(s32 a, s32 b);
extern void func_003717e0(u8 *a, f32 *b);
extern f32 func_003e41b0(f32 *a);
extern f32 func_003e41e0(f32 *a, f32 *b);
extern void func_00375dd0(u8 *ctx, s32 idx, f32 *a, f32 *b, f32 c, f32 d);
extern void func_00376170(u8 *ctx, s32 a, s32 b, s32 c, s32 d, s32 *e, s32 *f);
extern s32 func_0037d270(u8 *a, s64 b, s64 c);
extern s32 func_00378a70(u8 *a, s32 b);
extern s32 func_00379240(u8 *a);
extern s32 func_00379420(u8 *a);
extern void func_0038d060(s32 a);
extern void func_0038d0d0(s32 a, s32 b);
extern void func_0038d0a0(s32 a);
extern void func_00375b40(u8 *a, s32 b, s32 c, s32 d);
extern void func_003799d0(u8 *a);
extern s32 func_003789d0(u8 *a, s32 b);
extern void func_003713b0(f32 *a);
extern s32 func_00378930(u8 *a, s32 b);
extern void func_00375d50(u8 *a, s32 b, f32 *c, f32 *d, f32 e, f32 f);
extern void func_003760f0(u8 *a, s32 b, s32 c, s32 d, s32 *e, s32 *f);
extern void func_00376290(u8 *a, s32 b, s32 c, s32 d, s32 e);
extern void func_0038d2c0(s32 a);
extern void func_0036dc60(u8 *a, f32 *b, f32 *c, f32 d);
extern void func_00375ec0(u8 *a, s32 b);
extern s32 func_00106330(s32 a);
extern void func_003798d0(u8 *a, s32 b);
extern void func_00389110(s32 a);
extern s32 func_00389160(s32 a);
extern void func_0038d160(s32 a);
extern void func_00388f20(s32 a);
extern s32 func_00375910(u8 *a);
extern s32 func_00379150(u8 *a, s32 b, s32 c);
extern s32 func_0036de60(u8 *a);
extern void func_0038d1d0(s32 a);
extern void func_00388f40(s32 a);
extern void func_00379c70(u8 *a, s32 b);
extern void func_00378f90(u8 *a, s32 b, s32 c);
extern void func_00375890(u8 *a, s32 b, s32 c);
extern void func_00379090(u8 *a, s32 b, s32 c, s32 d);
extern void func_00378ec0(u8 *a, s32 b);
extern s32 func_00379d70(u8 *a);
extern s32 func_00379a70(u8 *a);
extern s32 func_00379920(u8 *a);
extern void func_00106390(s32 a, s32 b);

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
    ratio1 = (f32)(u32)(func_003b7060() & 0xFFF) / 4096.0f;
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
        ratio2 = (f32)(u32)(func_003b7060() & 0xFFF) / 4096.0f;
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
        dist = func_003e41b0(spA8);
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
    if (func_003e41b0(sp48) != 0.0f) {
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

typedef struct ShufflePos {
    s32 f60;   /* 0x60 */
    f32 f64;   /* 0x64 */
    s32 f68;   /* 0x68 */
    f32 f6C;   /* 0x6C */
    s32 f70;   /* 0x70 */
    s32 f74;   /* 0x74 */
    s32 f78;   /* 0x78 */
    s32 f7C;   /* 0x7C */
} ShufflePos;

// FUN_0037D630
void func_0037d630(u8 *arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8 *base = arg0 + 0x1F1D0;
    s32 off;
    u8 *p;
    f32 sp80[3];
    ShufflePos sp;
    f32 f12;
    f32 f13;

    off = arg1 * 0xE8;
    p = (u8 *)(off + (s32)arg0);
    if (*(s32 *)(p + 0x1D6A4) == 5) {
        *(Vec3f *)sp80 = *(Vec3f *)(p + 0x1D6C4);
    } else {
        *(Vec3f *)sp80 = *(Vec3f *)(p + 0x1D6B8);
    }
    f12 = (f32)(u32)arg2;
    f13 = (f32)(u32)arg3;
    func_00375dd0(arg0, arg1, 0, sp80, f12, f13);
    sp.f6C = iGpffff83e8;
    sp.f60 = 0;
    sp.f64 = iGpffff83ec;
    sp.f68 = 0;
    sp.f7C = 0;
    sp.f70 = 0;
    sp.f74 = 0x3F800000;
    sp.f78 = 0;
    func_00376170(arg0, arg1, arg2, arg3, 0, &sp.f70, &sp.f60);
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
        temp_3 = func_003b7060() & 0xFFF;
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

/* measured: cold reconstruction from m2c (509-line func, 22-case jtbl_00752AE0 switch 0-21 with fall-through 4/6/5, 7/8/9/10/11, 14/15/16/17/18/19, case-6 f20 inline as (1.0f-((0.5f*(f32)(cnt-3))/5.0f))*(f32)i with (f32)(u32)((s32)x&0xFFFF) and random (f32)(u32)(rnd&0xFFF) with (f32)n*(rf/4096.0f) per shuffle idiom, D_008C024E[0] absolute per 7i and 36dc60 float per $f12) + romwright (635 lines, arity s32(u8*), frame 144B) + Ghidra (464 lines) + IDA (397 lines) into file idiom. probe 1084 words (baseline m2c de-noised 1098, loopinv 1081 best single, arr+loopinv 1084 honest inside gate; common 1096, schedule 1095, dead 1082, others tie/worse; pair loopinv+dead 1084 worse). fnalign retail 1225/object 1190 (-35, -2.86% inside 1188-1262 3% gate; assignment 1228 vs 1190 -38). 574 edits +10 reloc-only. subscript FB0 tie 1084, colour swap tie, tmp-first tie; address hoist matches retail ($17 base, $19 n); 7n N/A (separate counters var_16*), 7r N/A (no single-product+add in retail or candidate, all mul/div, no adda/madd/mula). Walls: saved-reg rotation, FPR colouring, frame -0xD0 vs -0x120 (32B short), stack slots shifted, plus recorded b210 floors (or-fold or $v0 vs $v1, cvt-scratch $f0 vs $f1, guard bc1f vs bc1t, andi sunk) same as 381a70. Banked guarded floor; production stays ASM. */
// FUN_0037DA60 NONMATCHING
#ifdef NON_MATCHING
#pragma opt_loop_invariants on
s32 func_0037da60(u8 *arg0) {
    extern void func_0036dc60(u8 *, f32 *, f32 *, f32);
    f32 sp118[2];
    u8 sp108[16];
    s32 spFC;
    s32 spF8;
    s32 spF4;
    s32 spF0;
    s32 spEC;
    s32 spE8;
    s32 spE4;
    s32 spE0;
    f32 spDC;
    s32 spD8;
    f32 spD4;
    s32 spD0;
    s32 spCC;
    s32 spC8;
    s32 spC4;
    s32 spC0;
    f32 spBC;
    s32 spB8;
    f32 spB4;
    s32 spB0;
    s32 spAC;
    s32 spA8;
    s32 spA4;
    s32 spA0;
    f32 sp9C;
    s32 sp98;
    f32 sp94;
    s32 sp90;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f1;
    f32 temp_f1_2;
    f32 temp_f1_3;
    f32 var_f12;
    f32 var_f12_2;
    f32 var_f13;
    f32 var_f13_2;
    f32 var_f1;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_4;
    s32 temp_18;
    s32 temp_18_2;
    s32 temp_19;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_5;
    s32 temp_3_2;
    s32 temp_4;
    s32 temp_6;
    s32 var_16;
    s32 var_16_2;
    s32 var_16_3;
    s32 var_16_4;
    s32 var_16_5;
    s32 var_16_6;
    s32 var_18;
    s32 var_19;
    s32 var_3;
    s32 var_4;
    s32 var_4_2;
    s32 var_4_3;
    u16 temp_21;
    u16 temp_22;
    u16 temp_2_4;
    u16 temp_2_7;
    u16 temp_3;
    u16 temp_3_3;
    u16 temp_3_4;
    u16 temp_3_5;
    u16 temp_3_6;
    u16 temp_3_7;
    u16 temp_4_2;
    u16 temp_5;
    u32 temp_2;
    u8 *temp_16_3;
    u8 *temp_16_5;
    u8 *temp_16_6;
    u8 *temp_17;
    u8 *temp_2_6;
    u8 *temp_4_3;

    temp_4 = (s32)(*(s32 *)(arg0 + 0x1F304));
    temp_17 = (u8 *)(arg0 + 0x1F1D0);
    temp_19 = (s32)(func_00378530(temp_4, *(s32 *)(arg0 + 0x1F2FC)));
    temp_2 = (u32)(*(u32 *)(arg0 + 0x1F2F8));
    switch (temp_2) {                               /* switch 1 */
    case 0:                                         /* switch 1 */
        if (func_00378a70(arg0, *(s32 *)(arg0 + 0x1F304)) != 0) {
            func_0037c720(arg0);
            if (func_00379240(arg0) != 0) {
                *(u32 *)(arg0 + 0x1F2F8) = 1U;
            } else {
                *(u32 *)(arg0 + 0x1F2F8) = 2U;
            }
        }
block_143:
        return 0;
    case 1:                                         /* switch 1 */
        if (func_00379420(arg0) != 0) {
            *(u32 *)(arg0 + 0x1F2F8) = 2U;
        case 2:                                     /* switch 1 */
            temp_3 = (u16)(*(u16 *)(arg0 + 0x1F2F0) + 1);
            *(u16 *)(arg0 + 0x1F2F0) = temp_3;
            if ((temp_3 & 0xFFFF) >= 0) {
                temp_16 = (s32)(*(s32 *)(arg0 + 0x1F298));
                func_0038d060(temp_16);
                func_0038d0d0(temp_16, 1);
                *(u32 *)(arg0 + 0x1F2F8) = 3U;
            }
        }
        goto block_143;
    case 3:                                         /* switch 1 */
        if (D_008C024E[0] & 0x40) {
            func_0038d0a0(*(s32 *)(arg0 + 0x1F298));
            *(u16 *)(arg0 + 0x1F2F0) = 0U;
            *(u32 *)(arg0 + 0x1F2F8) = 4U;
            *(u16 *)(temp_17 + 8) = 0U;
            var_16 = 0;
loop_13:
            if (var_16 < *(s32 *)(arg0 + 0x1F304)) {
                temp_6 = var_16 & 0xFFFF;
                func_00375b40(arg0, var_16, temp_6, (temp_6 + 0xA) & 0xFFFF);
                *(u16 *)(arg0 + 0x1F1D6) = (u16) (*(u16 *)(arg0 + 0x1F1D6) ^ ((1 << var_16) & 0xFFFF));
                var_16 += 1;
                goto loop_13;
            }
            func_0045af60(0, 4, 0, 1);
            func_0045af60(1, 0, 5, 1);
        } else if (D_008C024E[0] & 0x20) {
            func_003799d0(arg0);
            *(u32 *)(arg0 + 0x1F2F8) = 0x14U;
        }
        goto block_143;
    case 4:                                         /* switch 1 */
        if (func_003789d0(arg0, *(s32 *)(arg0 + 0x1F304)) != 0) {
            *(u16 *)(arg0 + 0x1F2F0) = 0U;
            *(u32 *)(arg0 + 0x1F2F8) = 6U;
            *(u16 *)(temp_17 + 8) = 0U;
            *(u16 *)(temp_17 + 6) = 0U;
            func_003713b0((f32 *)sp108);
            var_16_2 = 0;
loop_26:
            if (var_16_2 < *(s32 *)(arg0 + 0x1F304)) {
                var_f12 = (f32)(u32)(var_16_2 & 0xFFFF);
                var_f13 = (f32)(u32)((var_16_2 + 0xA) & 0xFFFF);
                func_00375dd0(arg0, var_16_2, 0, (f32 *)sp108, var_f12, var_f13);
                var_16_2 += 1;
                goto loop_26;
            }
            func_0045af60(1, 0, 5, 2);
        case 6:                                     /* switch 1 */
            if (func_00378930(arg0, *(s32 *)(arg0 + 0x1F304)) != 0) {
                func_003713b0((f32 *)sp108);
                spFC = 0x3F800000;
                spF0 = 0;
                spF4 = 0;
                spF8 = 0;
                var_16_3 = 0;
loop_31:
                if (var_16_3 < temp_19) {
                    func_00375d50(arg0, var_16_3, (f32 *)sp108, (f32 *)sp108, 0.0f, 0.0f);
                    func_003760f0(arg0, var_16_3, 0, 0, &spF0, &spF0);
                    func_00376290(arg0, var_16_3, 0, 0xFF, 0xFF);
                    var_16_3 += 1;
                    goto loop_31;
                }
                func_0038d2c0(*(s32 *)(arg0 + 0x1F298));
                *(u16 *)(arg0 + 0x1F2F4) = (u16) (*(u16 *)(arg0 + 0x1F2F4) | 1);
                *(u16 *)(arg0 + 0x1F2F0) = 0U;
                *(u32 *)(arg0 + 0x1F2F8) = 5U;
                var_16_4 = 0;
loop_46:
                if (var_16_4 < temp_19) {
                    func_0037ca60(arg0, var_16_4, sp118);
                    func_0036dc60(arg0 + (var_16_4 * 0xFB0), sp118, (f32 *)sp108, 67.0f);
                    temp_f1 = (1.0f - ((0.5f * (f32)(temp_4 - 3)) / 5.0f)) * (f32)var_16_4;
                    var_f12_2 = (f32)(u32)((s32)temp_f1 & 0xFFFF);
                    temp_f1_2 = temp_f1 + 5.0f;
                    var_f13_2 = (f32)(u32)((s32)temp_f1_2 & 0xFFFF);
                    func_00375dd0(arg0, var_16_4, 0, (f32 *)sp108, var_f12_2, var_f13_2);
                    func_00375ec0(arg0, var_16_4);
                    var_16_4 += 1;
                    goto loop_46;
                }
                func_0045af60(1, 0, 5, 2);
            case 5:                                 /* switch 1 */
                if (func_00378930(arg0, temp_19) != 0) {
                    if (func_00106330(0x1432) == 0) {
                        func_003798d0(arg0, 2);
                        *(u32 *)(arg0 + 0x1F2F8) = 0x15U;
                        *(u16 *)(arg0 + 0x1F2F0) = 0U;
                        *(u16 *)(arg0 + 0x1F2F4) = (u16) (*(u16 *)(arg0 + 0x1F2F4) | 2);
                    } else {
                        func_0037d840(arg0);
                        temp_2_4 = (u16)(*(u16 *)(temp_17 + 0x2C));
                        if ((s32) temp_2_4 > 0) {
                            var_19 = 0;
                            if ((s32) temp_2_4 > 0) {
loop_63:
                                if (var_19 < (s32) *(u16 *)(temp_17 + 0x2C)) {
                                    temp_16_2 = (s32)(func_00378530(*(s32 *)(arg0 + 0x1F304), *(s32 *)(arg0 + 0x1F2FC)));
                                    do {
                                        temp_2_5 = func_003b7060() & 0xFFF;
                                        var_f1 = (f32)(u32)temp_2_5;
                                        temp_f1_3 = (f32)temp_16_2 * (var_f1 / 4096.0f);
                                        var_3 = (s32)temp_f1_3;
                                        temp_4_2 = (u16)(var_3 & 0xFFFF);
                                    } while (*(u16 *)((arg0 + 0x1F1D0) + 6) & ((1 << temp_4_2) & 0xFFFF));
                                    temp_2_6 = (u8 *)(temp_17 + (var_19 * 2));
                                    *(u16 *)(temp_2_6 + 0xC) = temp_4_2;
                                    func_0037d630(arg0, (s32) *(u16 *)(temp_2_6 + 0xC), 0, (s32) *(u16 *)(temp_17 + 2));
                                    var_19 += 1;
                                    goto loop_63;
                                }
                            }
                            func_0045af60(1, 0, 5, 1);
                            *(u16 *)(arg0 + 0x1F2F0) = 0U;
                            *(u32 *)(arg0 + 0x1F2F8) = 7U;
                        } else {
                            *(u32 *)(arg0 + 0x1F2F8) = 9U;
                        }
                    }
                }
            }
        }
        goto block_143;
    case 7:                                         /* switch 1 */
        if (func_003789d0(arg0, temp_19) != 0) {
            temp_3_2 = (s32)(*(s32 *)(arg0 + 0x1F300));
            switch (temp_3_2) {                     /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                var_4_3 = 5;
                break;
            case 1:                                 /* switch 2 */
                var_4_3 = 3;
                break;
            case 2:                                 /* switch 2 */
                var_4_3 = 1;
                break;
            default:                                /* switch 2 */
                func_0046d730(&D_0064EB20, 0x26C);
                var_4_3 = 0;
                break;
            }
            temp_3_3 = (u16)(*(u16 *)(arg0 + 0x1F2F0) + 1);
            *(u16 *)(arg0 + 0x1F2F0) = temp_3_3;
            if ((temp_3_3 & 0xFFFF) >= (var_4_3 & 0xFFFF)) {
                var_18 = 0;
                if ((s32) *(u16 *)(temp_17 + 0x2C) > 0) {
                    temp_16_3 = (u8 *)(arg0 + 0x1F1D0);
loop_82:
                    if (var_18 < (s32) *(u16 *)(temp_17 + 0x2C)) {
                        temp_22 = (u16)(*(u16 *)(temp_17 + 2));
                        temp_21 = (u16)(*(u16 *)((temp_17 + (var_18 * 2)) + 0xC));
                        func_00375ec0(arg0, (s32) temp_21);
                        temp_f0 = (f32)(s32)(iGpffff83ec);
                        spDC = temp_f0;
                        spD0 = 0;
                        spD4 = temp_f0;
                        spD8 = 0;
                        spEC = 0x3F800000;
                        spE0 = 0;
                        spE4 = 0;
                        spE8 = 0;
                        func_00376170(arg0, (s32) temp_21, 0, (s32) temp_22, 0, &spE0, &spD0);
                        *(u16 *)(temp_16_3 + 6) = (u16) (*(u16 *)(temp_16_3 + 6) & (~(1 << temp_21) & 0xFFFF));
                        if (*(u16 *)(arg0 + 0x1F1D0) & 4) {
                            *(s32 *)(temp_16_3 + 0x34) = -1;
                            *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) & 0xFFFB);
                        } else {
                            *(s32 *)(temp_16_3 + 0x30) = -1;
                            *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) & 0xFFFD);
                        }
                        var_18 += 1;
                        goto loop_82;
                    }
                }
                func_0045af60(1, 0, 5, 1);
                *(u32 *)(arg0 + 0x1F2F8) = 8U;
                *(u16 *)(arg0 + 0x1F2F0) = 0U;
            case 8:                                 /* switch 1 */
                if (func_003789d0(arg0, temp_19) != 0) {
                    *(u32 *)(arg0 + 0x1F2F8) = 9U;
                case 9:                             /* switch 1 */
                    *(u16 *)(temp_17 + 8) = 0U;
                    func_00389110(*(s32 *)(arg0 + 0x1F294));
                    *(u32 *)(arg0 + 0x1F2F8) = 0xAU;
                case 10:                            /* switch 1 */
                    if (func_00389160(*(s32 *)(arg0 + 0x1F294)) != 0) {
                        func_0038d160(*(s32 *)(arg0 + 0x1F298));
                        func_00388f20(*(s32 *)(arg0 + 0x1F294));
                        temp_16_4 = (s32)(*(s32 *)(arg0 + 0x1F298));
                        func_0038d060(temp_16_4);
                        func_0038d0d0(temp_16_4, 3);
                        *(u32 *)(arg0 + 0x1F2F8) = 0xBU;
                    case 11:                        /* switch 1 */
                        if (D_008C024E[0] & 0x40) {
                            temp_5 = (u16)(*(u16 *)(temp_17 + 4));
                            if (!(*(u16 *)(temp_17 + 6) & ((1 << temp_5) & 0xFFFF))) {
                                func_0037d630(arg0, (s32) temp_5, 0, 0xA);
                                *(u32 *)(arg0 + 0x1F2F8) = 0xCU;
                                func_0045af60(1, 0, 5, 1);
                            }
                        } else {
                            func_0037d460(arg0);
                        }
                    }
                }
            }
        }
        goto block_143;
    case 12:                                        /* switch 1 */
        if (func_00375910(arg0 + (*(u16 *)(temp_17 + 4) * 0xE8) + 0x1D6A0) != 0) {
            temp_3_4 = (u16)(*(u16 *)(arg0 + 0x1F1D0));
            if ((temp_3_4 & 2) && (temp_3_4 & 4)) {
                *(u32 *)(arg0 + 0x1F2F8) = 0xDU;
                *(u16 *)(arg0 + 0x1F2F0) = 0U;
            } else {
                *(u32 *)(arg0 + 0x1F2F8) = 0xBU;
            }
        }
        goto block_143;
    case 13:                                        /* switch 1 */
        if ((func_00379150(arg0, *(s32 *)(temp_17 + 0x30), *(s32 *)(temp_17 + 0x34)) != 0) && (func_0036de60(arg0 + (*(s32 *)(temp_17 + 0x30) * 0xFB0)) != 2)) {
            func_0038d0a0(*(s32 *)(arg0 + 0x1F298));
            func_0038d1d0(*(s32 *)(arg0 + 0x1F298));
            func_00388f40(*(s32 *)(arg0 + 0x1F294));
            *(u32 *)(arg0 + 0x1F2F8) = 0xEU;
        } else {
            temp_3_5 = (u16)(*(u16 *)(arg0 + 0x1F2F0) + 1);
            *(u16 *)(arg0 + 0x1F2F0) = temp_3_5;
            if ((temp_3_5 & 0xFFFF) >= 0xA) {
                temp_18 = (s32)(*(s32 *)(temp_17 + 0x34));
                temp_16_5 = (u8 *)(arg0 + 0x1F1D0);
                func_00375ec0(arg0, temp_18);
                temp_f0_2 = (f32)(s32)(iGpffff83ec);
                spBC = temp_f0_2;
                spB0 = 0;
                spB4 = temp_f0_2;
                spB8 = 0;
                spCC = 0x3F800000;
                spC0 = 0;
                spC4 = 0;
                spC8 = 0;
                func_00376170(arg0, temp_18, 0, 0xA, 0, &spC0, &spB0);
                *(u16 *)(temp_16_5 + 6) = (u16) (*(u16 *)(temp_16_5 + 6) & (~(1 << temp_18) & 0xFFFF));
                if (*(u16 *)(arg0 + 0x1F1D0) & 4) {
                    *(s32 *)(temp_16_5 + 0x34) = -1;
                    *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) & 0xFFFB);
                } else {
                    *(s32 *)(temp_16_5 + 0x30) = -1;
                    *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) & 0xFFFD);
                }
                temp_18_2 = (s32)(*(s32 *)(temp_17 + 0x30));
                temp_16_6 = (u8 *)(arg0 + 0x1F1D0);
                func_00375ec0(arg0, temp_18_2);
                temp_f0_3 = (f32)(s32)(iGpffff83ec);
                sp9C = temp_f0_3;
                sp90 = 0;
                sp94 = temp_f0_3;
                sp98 = 0;
                spAC = 0x3F800000;
                spA0 = 0;
                spA4 = 0;
                spA8 = 0;
                func_00376170(arg0, temp_18_2, 0, 0xA, 0, &spA0, &sp90);
                *(u16 *)(temp_16_6 + 6) = (u16) (*(u16 *)(temp_16_6 + 6) & (~(1 << temp_18_2) & 0xFFFF));
                if (*(u16 *)(arg0 + 0x1F1D0) & 4) {
                    *(s32 *)(temp_16_6 + 0x34) = -1;
                    *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) & 0xFFFB);
                } else {
                    *(s32 *)(temp_16_6 + 0x30) = -1;
                    *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) & 0xFFFD);
                }
                func_0045af60(1, 0, 5, 1);
                temp_2_7 = (u16)(*(u16 *)(temp_17 + 8) + 1);
                *(u16 *)(temp_17 + 8) = temp_2_7;
                if ((temp_2_7 & 0xFFFF) >= (s32) *(u16 *)(temp_17 + 0xA)) {
                    func_0038d0a0(*(s32 *)(arg0 + 0x1F298));
                    func_0038d1d0(*(s32 *)(arg0 + 0x1F298));
                    func_00388f40(*(s32 *)(arg0 + 0x1F294));
                    func_00379c70(arg0, -1);
                    *(u32 *)(arg0 + 0x1F2F8) = 0x12U;
                } else {
                    *(u32 *)(arg0 + 0x1F2F8) = 0xBU;
                }
            }
        }
        goto block_143;
    case 14:                                        /* switch 1 */
        var_16_5 = 0;
loop_116:
        if (var_16_5 < temp_19) {
            if ((var_16_5 != *(s32 *)(temp_17 + 0x30)) && (var_16_5 != *(s32 *)(temp_17 + 0x34))) {
                func_00378f90(arg0, var_16_5, 0x14);
            }
            var_16_5 += 1;
            goto loop_116;
        }
        *(u32 *)(arg0 + 0x1F2F8) = 0xFU;
        /* fallthrough */
    case 15:                                        /* switch 1 */
        if (func_00378a70(arg0, temp_19) != 0) {
            var_16_6 = 0;
loop_124:
            if (var_16_6 < temp_19) {
                if ((var_16_6 != *(s32 *)(temp_17 + 0x30)) && (var_16_6 != *(s32 *)(temp_17 + 0x34))) {
                    func_00375890(arg0, var_16_6, 0);
                }
                var_16_6 += 1;
                goto loop_124;
            }
            func_00379090(arg0, *(s32 *)(temp_17 + 0x30), 0xA, 1);
            func_00379090(arg0, *(s32 *)(temp_17 + 0x34), 0xA, -1);
            *(u32 *)(arg0 + 0x1F2F8) = 0x10U;
        case 16:                                    /* switch 1 */
            if (func_00378a70(arg0, temp_19) != 0) {
                temp_4_3 = (u8 *)((*(s32 *)(temp_17 + 0x34) * 0xE8) + arg0);
                *(u16 *)(temp_4_3 + 0x1D6A0) = (u16) (*(u16 *)(temp_4_3 + 0x1D6A0) & 0xFFFD);
                func_00378ec0(arg0, *(s32 *)(temp_17 + 0x30));
                *(u16 *)(arg0 + 0x1F1D0) = (u16) (*(u16 *)(arg0 + 0x1F1D0) | 8);
                func_0045af60(1, 0, 5, 1);
                *(u32 *)(arg0 + 0x1F2F8) = 0x11U;
            case 17:                                /* switch 1 */
                if (func_00375910(arg0 + (*(s32 *)(temp_17 + 0x30) * 0xE8) + 0x1D6A0) == 0) {
                    func_00379c70(arg0, *(s32 *)(temp_17 + 0x30));
                    *(u32 *)(arg0 + 0x1F2F8) = 0x12U;
                case 18:                            /* switch 1 */
                    if (func_00379d70(arg0) != 0) {
                        *(u32 *)(arg0 + 0x1F2F8) = 0x13U;
                    case 19:                        /* switch 1 */
                        return 1;
                    }
                    goto block_143;
                }
                goto block_143;
            }
            goto block_143;
        }
        goto block_143;
    case 20:                                        /* switch 1 */
        if (func_00379a70(arg0) != 0) {
            if (*(s32 *)(arg0 + 0x1F248) != 0) {
                *(u32 *)(arg0 + 0x1F2F8) = 0x13U;
            } else {
                *(u32 *)(arg0 + 0x1F2F8) = 3U;
            }
        }
        goto block_143;
    case 21:                                        /* switch 1 */
        if (func_00379920(arg0) != 0) {
            temp_3_6 = (u16)(*(u16 *)(arg0 + 0x1F2F4));
            if (temp_3_6 & 2) {
                *(u16 *)(arg0 + 0x1F2F4) = (u16) (temp_3_6 & 0xFFFD);
            }
            temp_3_7 = (u16)(*(u16 *)(arg0 + 0x1F2F0) + 1);
            *(u16 *)(arg0 + 0x1F2F0) = temp_3_7;
            if ((temp_3_7 & 0xFFFF) >= 0x1E) {
                func_00106390(0x1432, 1);
                *(u32 *)(arg0 + 0x1F2F8) = 5U;
            }
        }
        goto block_143;
    default:                                        /* switch 1 */
        func_0046d730(&D_0064EB20, 0x3F6);
        goto block_143;
    }
}
#pragma opt_loop_invariants off
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle4", func_0037da60);
#endif

#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle4.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

extern void func_0046d730(const void *file, u32 line);
extern u32 func_003b7060();
extern s32 func_00378530(s32 a, s32 b);
extern void func_003717e0(u8 *a, f32 *b);
extern f32 func_003e41b0(f32 *a);
extern f32 func_003e41e0(f32 *a, f32 *b);
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
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
extern void func_0036dc60(u8 *a, f32 *b, f32 *c, s32 d);
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

extern u16 D_008C024E;

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

// measured: plain C reaches object 828B/window 832B but leaves normalized_diff 485;
// the retail MAC register order, saved-register rotation, and fix2float operand
// order remain divergent. Restored the bare assembly fallback.
// FUN_0037C720
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle4", func_0037c720);

// measured: plain C reaches object 2052B/window 2064B but leaves normalized_diff
// 190; all case CFGs and stack frame match, but retail's FPU MAC schedules differ.
// Restored the bare assembly fallback.
// FUN_0037CA60
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle4", func_0037ca60);
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
// FUN_0037D840 NONMATCHING
#ifdef NON_MATCHING
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
        temp_f0 = (f32)(var_18 + 1) * temp_f0;
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
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle4", func_0037d840);
#endif

// measured: retail hoists $f20 = 1.0f - ((0.5f*(f32)(temp_4-3))/5.0f) into the
// prologue (mul.s/div.s/sub.s before the switch) and has a -0x120 frame with
// sp90..sp118 stack locals; mwcc b210 computes that expression inline in the
// case-6 loop and lays out a -0xb0 frame, producing an object 96B larger than
// the 4912B window (nd 1108). The 22-entry jump table (jtbl_00752AE0, cases
// 0-21) is byte-identical, but the fall-through switch state machine (cases
// 4/6/5, 7/8/9/10/11, 14/15/16/17/18/19) plus ~30 external calls and the
// prologue hoist make the frame/codegen too divergent to pursue within budget.
// Tried: faithful m2c transcription with all extern decls. Kept INCLUDE_ASM.
// FUN_0037DA60 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle4", func_0037da60);

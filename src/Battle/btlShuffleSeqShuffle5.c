#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle5.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
/* Per-unit form: functions 0037F430/0037F550 match byte-exactly; */
/* 0037EF40/0037F6E0 remain bare fallbacks with measured floors (see markers). */
#include "type.h"

typedef struct ShuffleSub {
    u16 flags;      /* 0x00 */
    u16 unk_02;     /* 0x02 */
    u16 unk_04;     /* 0x04 */
    u8 _pad06[2];
    s32 count_08;   /* 0x08 */
    s32 list[7];    /* 0x0C */
    s32 count_28;   /* 0x28 */
} ShuffleSub;       /* 0x2C */

typedef struct ShuffleContext {
    u8 _pad000[0x1F1D0];
    ShuffleSub sub;         /* 0x1F1D0 */
    u8 _pad1FC[0x4C];
    s32 unk_1F248;          /* 0x1F248 */
    u8 _pad24C[0x48];
    s32 id_1F294;           /* 0x1F294 */
    s32 id_1F298;           /* 0x1F298 */
    u8 _pad2A0[0x58];
    u16 counter_1F2F0;      /* 0x1F2F0 */
    u16 flags_1F2F4;        /* 0x1F2F4 */
    u32 state_1F2F8;        /* 0x1F2F8 */
    s32 mode_1F2FC;         /* 0x1F2FC */
    s32 subState_1F300;     /* 0x1F300 */
    s32 count_1F304;        /* 0x1F304 */
} ShuffleContext;           /* 0x1F308 */

extern void func_0046d730(const void *file, u32 line);
extern u32 func_003b7060();
extern s32 func_0037ed90(u8 *ctx, s32 slot);
extern s32 func_00379150(u8 *ctx, s32 a, s32 b);
extern void func_00389090(s32 a, s32 b);
extern s32 func_00378530(s32 a, s32 b);
extern s32 func_00378a70(u8 *ctx, s32 n);
extern s32 func_00379240(u8 *ctx);
extern s32 func_00379420(u8 *ctx);
extern void func_0038d060(s32 a);
extern void func_0038d0d0(s32 a, s32 b);
extern void func_0038d0a0(s32 a);
extern void func_0038d2c0(s32 a);
extern void func_00389110(s32 a);
extern void func_00388fd0(s32 a);
extern s32 func_00389160(s32 a);
extern void func_0038d1f0(s32 a);
extern void func_00388f60(s32 a);
extern void func_00389040(s32 a);
extern void func_003890f0(s32 a);
extern void func_00389020(s32 a);
extern void func_0038d280(s32 a);
extern void func_00388fb0(s32 a);
extern s32 func_0037f430(u8 *ctx);
extern s32 func_0037f550(u8 *ctx);
extern void func_00378f90(u8 *ctx, s32 a, s32 b);
extern void func_00375890(u8 *ctx, s32 a, s32 b);
extern void func_00379090(u8 *ctx, s32 a, s32 b, s32 c);
extern void func_00378ec0(u8 *ctx, s32 a);
extern s32 func_00379c70(u8 *ctx, s32 a);
extern s32 func_00379d70(u8 *ctx);
extern s32 func_00379a70(u8 *ctx);
extern s32 func_00379920(u8 *ctx);
extern void func_003799d0(u8 *ctx);
extern void func_003798d0(u8 *ctx, s32 a);
extern s32 func_00106330(s32 a);
extern void func_00106390(s32 a, s32 b);
extern void func_003717e0(u8 *a, f32 *b);
extern void func_0036dc60(u8 *unit, f32 *src, f32 *dst, f32 scale);
extern void func_00375d50(u8 *ctx, s32 idx, f32 *a, f32 *b, f32 c, f32 d);
extern void func_00376070(u8 *ctx, s32 a, s32 b, s32 c, f32 *d, f32 *e, f32 f);
extern void func_003760f0(u8 *ctx, s32 a, s32 b, s32 c, f32 *d, f32 *e);
extern void func_00376290(u8 *ctx, s32 a, s32 b, s32 c, s32 d);
extern void func_003762e0(u8 *ctx, s32 a, s32 b, s32 c, s32 d);
extern s32 func_00375910(u8 *a);
extern s32 func_00375970(u8 *a);
extern void func_00373750(s32 a, s32 b, f32 *c);
extern void func_0037ef40(u8 *ctx);

extern u32 D_0064EB40[];
extern u16 D_008C024E[];


// measured: field-by-field and aggregate pair-buffer candidates reach object 1260B
// versus the retail 1264B window but remain normalized_diff 344; the three
// interleaved shuffle-copy loops retain divergent register scheduling. Restored
// the bare assembly fallback.
// FUN_0037EF40 NONMATCHING
#ifdef NON_MATCHING
void func_0037ef40(u8 *arg0) {
    s32 n;
    s32 i;
    s32 k;
    s32 c;
    u32 rnd;
    u64 *d;
    u64 *s;
    s32 t;
    u64 bufA[502];
    u64 bufB[502];
    u64 bufC[502];

    if (*(s32 *)(arg0 + 0x1F2FC) != 4) {
        func_0046d730(&D_0064EB40[0], 0xBD);
    }
    n = *(s32 *)(arg0 + 0x1F304);
    if (n < 6) {
        for (i = 0; i < 6; i += 2) {
            c = n;
            k = c - 1;
            while (k > 0) {
                rnd = func_003b7060();
                c = (s32)((f32)c * ((f32)(rnd & 0xFFF) / 4096.0f));
                if (k < 0 || n <= k) {
                    func_0046d730(&D_0064EB40[0], 0xCB);
                }
                if (c < 0 || n <= c) {
                    func_0046d730(&D_0064EB40[0], 0xCC);
                }
                d = (u64 *)bufC;
                s = (u64 *)((s32)arg0 + (i * n + k) * 0xFB0);
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + (i * n + k) * 0xFB0);
                s = (u64 *)((s32)arg0 + (i * n + c) * 0xFB0);
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + (i * n + c) * 0xFB0);
                s = (u64 *)bufC;
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + ((i + 1) * n + k) * 0xFB0);
                s = (u64 *)bufA;
                t = 0x1F6;
                do {
                    s[0] = d[0];
                    s[1] = d[1];
                    s += 2;
                    d += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + ((i + 1) * n + k) * 0xFB0);
                s = (u64 *)((s32)arg0 + ((i + 1) * n + c) * 0xFB0);
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + ((i + 1) * n + c) * 0xFB0);
                s = (u64 *)bufA;
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                k = c - 1;
            }
        }
    } else {
        for (i = 0; i < 3; i++) {
            c = n;
            k = c - 1;
            while (k > 0) {
                rnd = func_003b7060();
                c = (s32)((f32)c * ((f32)(rnd & 0xFFF) / 4096.0f));
                if (k < 0 || n <= k) {
                    func_0046d730(&D_0064EB40[0], 0xDF);
                }
                if (c < 0 || n <= c) {
                    func_0046d730(&D_0064EB40[0], 0xE0);
                }
                d = (u64 *)bufB;
                s = (u64 *)((s32)arg0 + (i * n + k) * 0xFB0);
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + (i * n + k) * 0xFB0);
                s = (u64 *)((s32)arg0 + (i * n + c) * 0xFB0);
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                d = (u64 *)((s32)arg0 + (i * n + c) * 0xFB0);
                s = (u64 *)bufB;
                t = 0x1F6;
                do {
                    d[0] = s[0];
                    d[1] = s[1];
                    d += 2;
                    s += 2;
                    t--;
                } while (t > 0);
                k = c - 1;
            }
        }
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle5", func_0037ef40);
#endif
// FUN_0037F430
s32 func_0037f430(u8 *arg0)
{
    ShuffleContext *ctx = (ShuffleContext *)arg0;
    ShuffleSub *sub = &ctx->sub;
    s32 var_20;
    s32 var_19;
    s32 temp_2;
    s32 temp_17;

    var_20 = 0;
    temp_17 = func_0037ed90(arg0, 4);
    for (var_19 = 0; var_19 < 3; var_19++) {
        if (sub->flags & ((0x10 << var_19) & 0xFFFF)) {
            temp_2 = func_0037ed90(arg0, var_19);
            if (func_00379150(arg0, temp_2, temp_17) != 0) {
                var_20 = 1;
                func_00389090(ctx->id_1F294, temp_2);
            }
        }
    }
    if (var_20 != 0) {
        func_00389090(ctx->id_1F294, temp_17);
    }
    return var_20;
}


// FUN_0037F550
s32 func_0037f550(u8 *arg0)
{
    ShuffleContext *ctx = (ShuffleContext *)arg0;
    ShuffleSub *sub = &ctx->sub;
    s32 var_20;
    s32 var_19;
    s32 temp_2;
    s32 temp_18;
    s32 temp_17;
    s32 temp_22;
    s32 temp_3;

    var_20 = 0;
    sub->count_28 = 0;
    temp_17 = func_0037ed90(arg0, 4);
    temp_3 = sub->count_28;
    sub->count_28 = temp_3 + 1;
    sub->list[temp_3] = temp_17;
    for (var_19 = 0; var_19 < 3; var_19++) {
        if (sub->flags & ((0x10 << var_19) & 0xFFFF)) {
            temp_18 = func_0037ed90(arg0, var_19);
            temp_22 = func_0037ed90(arg0, 8 - var_19);
            if ((func_00379150(arg0, temp_18, temp_17) != 0) && (func_00379150(arg0, temp_17, temp_22) != 0)) {
                var_20 = 1;
                temp_3 = sub->count_28;
                sub->count_28 = temp_3 + 1;
                *(s32 *)((u8 *)sub + (temp_3 * 4) + 0xC) = temp_18;
                temp_3 = sub->count_28;
                sub->count_28 = temp_3 + 1;
                *(s32 *)((u8 *)sub + (temp_3 * 4) + 0xC) = temp_22;
            }
        }
    }
    if (sub->count_28 > 7) {
        func_0046d730(&D_0064EB40[0], 0x132);
    }
    return var_20;
}


// Measured floor (nd 3631, obj 4768/win 4768): callee-saved allocation differs
// (arg0 $s1 vs retail $s0, temp_20 $s0 vs $s4, temp_17 $s5 vs $s1), spC0/spB0
// stack spill slots are folded away, and the state-machine body register
// choices cascade. Remaining structural regions: case-4 loop_50/loop_52 FPU
// scheduling, the case-12/13 block shapes, and block_140's loop. The jump
// table, switch dispatch, madd/msub/adda FPU sequences, and all callees match.
/* Faithful C reconstruction of the shuffle-5 state machine (4768B window).
   First probe nd 1061; switch structure, float constants and callee
   conventions verified against retail. Open: 128-bit quad locals (sq/lq
   vs sw/lw), stack-frame size (-0x120 vs -0x170), s-reg assignment, COP1
   madd/msub fusion, and scheduler ordering throughout. */
// FUN_0037F6E0 NONMATCHING
#ifdef NON_MATCHING
s32 func_0037f6e0(u8 *arg0)
{
    u8 *temp_19;
    u8 *temp_22;
    u8 *temp_23;
    u8 *temp_30;
    u8 *temp_4_3;
    s32 temp_4;
    s32 temp_5;
    s32 var_18;
    s32 temp_20;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_2_5;
    s32 temp_3;
    s32 var_17;
    s32 var_17_2;
    s32 var_17_3;
    s32 var_17_4;
    s32 var_17_5;
    s32 var_20;
    s32 var_20_2;
    s32 var_20_3;
    s32 var_21;
    s32 var_21_2;
    s32 var_21_3;
    s32 var_2;
    s32 var_2_2;
    s32 var_2_3;
    s32 var_2_4;
    s32 var_4;
    s32 var_4_2;
    s32 var_5;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_22_2;
    s32 temp_23_2;
    u16 temp_17;
    u16 temp_17_2;
    u16 temp_2_6;
    u16 temp_3_2;
    u16 temp_3_3;
    u16 temp_3_4;
    u16 temp_4_2;
    u32 temp_2;
    f32 var_f0;
    f32 var_f12;
    f32 var_f13;
    f32 var_f13_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 sp16C;
    f32 sp168;
    f32 sp13C;
    f32 sp14C;
    f32 unksp134;
    f32 sp130[2];
    s32 sp160;
    s32 sp15C;
    s32 sp10C;
    s32 sp108;
    s32 sp104;
    s32 sp100;
    s32 spF0;
    s32 spE0;
    s32 spD0;
    s32 spC0;
    s32 spB0;
    s32 sp158;
    s32 sp148;
    s32 sp138;
    s32 sp120;
    s32 sp110;
    s32 func_00378930(u8 *, s32);
    s32 func_0045af60();
temp_19 = (u8 *)(arg0 + 0x1F1D0);
    temp_4 = (s32)((*( s32 *)((u8 *)(arg0) + 0x1F304)));
    if (temp_4 < 6) {
        var_18 = temp_4 * 2;
    } else {
        var_18 = temp_4;
    }
    temp_20 = (s32)(func_00378530(temp_4, (*( s32 *)((u8 *)(arg0) + 0x1F2FC))));
    temp_17 = (u16)((*( u16 *)((u8 *)(temp_19) + 2)));
    temp_2 = (u32)((*( u32 *)((u8 *)(arg0) + 0x1F2F8)));
    switch (temp_2) {                               /* switch 1 */
    case 0:                                         /* switch 1 */
        if (func_00378a70(arg0, (*( s32 *)((u8 *)(arg0) + 0x1F304))) != 0) {
            temp_3 = (s32)((*( s32 *)((u8 *)(arg0) + 0x1F300)));
            switch (temp_3) {                       /* switch 2; irregular */
            case 0:                                 /* switch 2 */
                (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) | 0x70);
                break;
            case 1:                                 /* switch 2 */
                temp_2_2 = func_003b7060() & 0xFFF;
                if (temp_2_2 >= 0) {
                    var_f1 = (f32) temp_2_2;
                } else {
                    var_f1 = 2.0f * (f32) (((u32) temp_2_2 >> 1) | (temp_2_2 & 1));
                }
                (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) | 0x70);
                (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) & (~(0x10 << (s32)(3.0f * (var_f1 / 4096.0f))) & 0xFFFF));
                break;
            case 2:                                 /* switch 2 */
                temp_2_3 = func_003b7060() & 0xFFF;
                if (temp_2_3 >= 0) {
                    var_f1_2 = (f32) temp_2_3;
                } else {
                    var_f1_2 = 2.0f * (f32) (((u32) temp_2_3 >> 1) | (temp_2_3 & 1));
                }
                (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) | ((0x10 << (s32)(3.0f * (var_f1_2 / 4096.0f))) & 0xFFFF));
                break;
            default:                                /* switch 2 */
                func_0046d730(&D_0064EB40, 0x41);
                break;
            }
            (*( s16 *)((u8 *)((arg0 + 0x1F1D0)) + 2)) = 5;
            if (func_00379240(arg0) != 0) {
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 1U;
            } else {
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 2U;
            }
        }
block_140:
        var_21 = 0;
loop_163:
        switch (var_21) {                           /* switch 5; irregular */
        case 0:                                     /* switch 5 */
            var_2 = 2 & 0xFFFF;
block_149:
            if ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) & (var_2 & 0xFFFF)) {
                var_20 = var_18 * var_21;
                spC0 = (s32) (arg0 + 0x1F304);
                spB0 = var_18 * (var_21 + 1);
loop_161:
                if (var_20 < spB0) {
                    temp_17_2 = (u16)((*( u16 *)((u8 *)(arg0) + 0x1F1D2)));
                    if ((s32)(spC0) < 6) {

                    }
                    temp_23 = (u8 *)(arg0 + (var_20 * 0xE8));
                    if (func_00375910(temp_23 + 0x1D6A0) != 0) {
                        func_003717e0(temp_23 + 0x1D6B8, sp130);
                        if (!(unksp134 < 508.0f)) {
                            M2C_ERROR(/* unknown instruction: adda.s $f0, $f3 */);
                            unksp134 = M2C_ERROR(/* unknown instruction: msub.s $f0, $f2, $f1 */);
                        }
                        temp_22 = (u8 *)(arg0 + (var_20 * 0xFB0));
                        func_0036dc60(temp_22, (f32 *) sp130, (f32 *)&sp120, 86.0f);
                        unksp134 += 120.0f;
                        func_0036dc60(temp_22, (f32 *) sp130, (f32 *)&sp110, 86.0f);
                        if ((s32) temp_17_2 >= 0) {
                            var_f13 = (f32) temp_17_2;
                        } else {
                            var_f13 = 2.0f * (f32) ((temp_17_2 >> 1) | (temp_17_2 & 1));
                        }
                        func_00375d50(arg0, var_20, (f32 *)&sp120, (f32 *)&sp110, 0.0f, var_f13);
                    }
                    var_20 += 1;
                    goto loop_161;
                }
            }
            var_21 += 1;
            goto loop_163;
        case 1:                                     /* switch 5 */
            var_2 = 4;
            goto block_149;
        case 2:                                     /* switch 5 */
            var_2 = 8;
            goto block_149;
        default:                                    /* switch 5 */
            func_0046d730(&D_0064EB40, 0x8C);
            var_2 = 0;
            goto block_149;
        }
        return 0;
    case 1:                                         /* switch 1 */
        if (func_00379420(arg0) != 0) {
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 2U;
        case 2:                                     /* switch 1 */
            temp_3_2 = (u16)((*( u16 *)((u8 *)(arg0) + 0x1F2F0)) + 1);
            (*( u16 *)((u8 *)(arg0) + 0x1F2F0)) = temp_3_2;
            if ((temp_3_2 & 0xFFFF) >= 0) {
                temp_17_3 = (s32)((*( s32 *)((u8 *)(arg0) + 0x1F298)));
                func_0038d060(temp_17_3);
                func_0038d0d0(temp_17_3, 1);
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 3U;
            }
        }
        goto block_140;
    case 3:                                         /* switch 1 */
        if (D_008C024E[0] & 0x40) {
            func_0038d0a0((*( s32 *)((u8 *)(arg0) + 0x1F298)));
            (*( u16 *)((u8 *)(arg0) + 0x1F2F0)) = 0U;
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 4U;
            var_17 = 0;
loop_36:
            temp_5 = (s32)((*( s32 *)((u8 *)(arg0) + 0x1F304)));
            if (var_17 < temp_5) {
                func_00373750(var_17, temp_5, &sp168);
                sp16C -= 400.0f;
                func_0036dc60(arg0 + (var_17 * 0xFB0), &sp168, (f32 *)&sp158, 86.0f);
                temp_2_4 = var_17 & 0xFFFF;
                if (temp_2_4 >= 0) {
                    var_f12 = (f32) temp_2_4;
                } else {
                    var_f12 = 2.0f * (f32) (((u32) temp_2_4 >> 1) | (temp_2_4 & 1));
                }
                temp_2_5 = (var_17 + 8) & 0xFFFF;
                if (temp_2_5 >= 0) {
                    var_f13_2 = (f32) temp_2_5;
                } else {
                    var_f13_2 = 2.0f * (f32) (((u32) temp_2_5 >> 1) | (temp_2_5 & 1));
                }
                func_00375d50(arg0, var_17, NULL, (f32 *)&sp158, var_f12, var_f13_2);
                var_17 += 1;
                goto loop_36;
            }
            func_0045af60(0, 4, 0, 1);
            func_0045af60(1, 0, 5, 4);
        } else if (D_008C024E[0] & 0x20) {
            func_003799d0(arg0);
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0x10U;
        }
        goto block_140;
    case 4:                                         /* switch 1 */
        if (func_00378930(arg0, (*( s32 *)((u8 *)(arg0) + 0x1F304))) != 0) {
            sp158 = 0;
            sp15C = 0;
            sp160 = 0;
            sp10C = 0;
            sp100 = 0;
            sp104 = 0x3F800000;
            sp108 = 0;
            var_21_2 = 0;
loop_43:
            if (var_21_2 < temp_20) {
                func_00375d50(arg0, var_21_2, (f32 *)&sp158, (f32 *)&sp158, 0.0f, 0.0f);
                func_003760f0(arg0, var_21_2, 0, 0, (f32 *)&sp100, (f32 *)&sp100);
                func_00376290(arg0, var_21_2, 0, 0xFF, 0xFF);
                var_21_2 += 1;
                goto loop_43;
            }
            func_0037ef40(arg0);
            (*( u16 *)((u8 *)(arg0) + 0x1F2F4)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F2F4)) | 1);
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 5U;
            (*( u16 *)((u8 *)(arg0) + 0x1F2F0)) = 0U;
            (*( s32 *)((u8 *)(temp_19) + 8)) = 0;
            var_20_2 = 0;
            spE0 = (temp_17 & 0xFFFF) * 2;
loop_52:
            if (var_20_2 < 3) {
                var_21_3 = 0;
                M2C_ERROR(/* unknown instruction: adda.s $f0, $f1 */);
                spF0 = var_20_2 * var_18;
                temp_23_2 = var_20_2 * 7;
                spD0 = spE0 + temp_23_2;
loop_50:
                if (var_21_3 < var_18) {
                    sp168 = 314.0f + (f32) ((((s32) (var_20_2 * 3) / 3) - 1) * 0x6B);
                    sp16C = M2C_ERROR(/* unknown instruction: madd.s $f20, $f2, $f3 */);
                    M2C_ERROR(/* unknown instruction: adda.s $f0, $f20 */);
                    sp16C = M2C_ERROR(/* unknown instruction: msub.s $f0, $f1, $f2 */);
                    temp_22_2 = var_21_3 + spF0;
                    temp_30 = (u8 *)(arg0 + (temp_22_2 * 0xFB0));
                    func_0036dc60(temp_30, &sp168, (f32 *)&sp148, 86.0f);
                    sp16C += 600.0f;
                    func_0036dc60(temp_30, &sp168, (f32 *)&sp138, 86.0f);
                    if ((s32) temp_17 >= 0) {
                        var_f0 = (f32) temp_17;
                    } else {
                        var_f0 = 2.0f * (f32) ((temp_17 >> 1) | (temp_17 & 1));
                    }
                    func_00376070(arg0, temp_22_2, temp_23_2 & 0xFFFF, spD0 & 0xFFFF, (f32 *)&sp148, (f32 *)&sp138, 5.0f * ((sp13C - sp14C) / var_f0));
                    var_21_3 += 1;
                    goto loop_50;
                }
                func_003762e0(arg0, spF0, (temp_23_2 + 1) & 0xFFFF, 0, 4);
                var_20_2 += 1;
                goto loop_52;
            }
        case 5:                                     /* switch 1 */
            var_17_2 = 0;
loop_66:
            switch (var_17_2) {                     /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                var_20_3 = 2 & 0xFFFF;
block_62:
                if (!((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) & (var_20_3 & 0xFFFF)) && (func_00375970(arg0 + (var_17_2 * var_18 * 0xE8) + 0x1D6A0) != 0)) {
                    (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) | var_20_3);
                    (*( s32 *)((u8 *)(temp_19) + 8)) = (s32) ((*( s32 *)((u8 *)(temp_19) + 8)) + 1);
                }
                var_17_2 += 1;
                goto loop_66;
            case 1:                                 /* switch 3 */
                var_20_3 = 4;
                goto block_62;
            case 2:                                 /* switch 3 */
                var_20_3 = 8;
                goto block_62;
            default:                                /* switch 3 */
                func_0046d730(&D_0064EB40, 0x8C);
                var_20_3 = 0;
                goto block_62;
            }
            if ((*( s32 *)((u8 *)(temp_19) + 8)) == 3) {
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 6U;
            }
        }
        goto block_140;
    case 6:                                         /* switch 1 */
        if (func_00106330(0x1433) == 0) {
            func_003798d0(arg0, 3);
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0x11U;
            (*( u16 *)((u8 *)(arg0) + 0x1F2F0)) = 0U;
            (*( u16 *)((u8 *)(arg0) + 0x1F2F4)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F2F4)) | 2);
        } else {
            func_00389110((*( s32 *)((u8 *)(arg0) + 0x1F294)));
            func_00388fd0((*( s32 *)((u8 *)(arg0) + 0x1F294)));
            func_0038d2c0((*( s32 *)((u8 *)(arg0) + 0x1F298)));
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 7U;
        case 7:                                     /* switch 1 */
            if (func_00389160((*( s32 *)((u8 *)(arg0) + 0x1F294))) != 0) {
                func_0038d1f0((*( s32 *)((u8 *)(arg0) + 0x1F298)));
                func_00388f60((*( s32 *)((u8 *)(arg0) + 0x1F294)));
                temp_17_4 = (s32)((*( s32 *)((u8 *)(arg0) + 0x1F298)));
                func_0038d060(temp_17_4);
                func_0038d0d0(temp_17_4, 2);
                func_00389040((*( s32 *)((u8 *)(arg0) + 0x1F294)));
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 8U;
            case 8:                                 /* switch 1 */
                if (D_008C024E[0] & 0x40) {
                    temp_4_2 = (u16)((*( u16 *)((u8 *)(temp_19) + 4)));
                    switch (temp_4_2) {             /* switch 4; irregular */
                    case 0:                         /* switch 4 */
                        var_2_2 = 2 & 0xFFFF;
                        break;
                    case 1:                         /* switch 4 */
                        var_2_2 = 4;
                        break;
                    case 2:                         /* switch 4 */
                        var_2_2 = 8;
                        break;
                    default:                        /* switch 4 */
                        func_0046d730(&D_0064EB40, 0x8C);
                        var_2_2 = 0;
                        break;
                    }
                    (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) & (~(var_2_2 & 0xFFFF) & 0xFFFF));
                    func_0045af60(1, 2, 5, 5);
                    temp_2_6 = (u16)((*( u16 *)((u8 *)(temp_19) + 4)) + 1);
                    (*( u16 *)((u8 *)(temp_19) + 4)) = temp_2_6;
                    if ((temp_2_6 & 0xFFFF) == 3) {
                        func_003890f0((*( s32 *)((u8 *)(arg0) + 0x1F294)));
                        func_0038d0a0((*( s32 *)((u8 *)(arg0) + 0x1F298)));
                        (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 9U;
                    } else if ((*( u16 *)((u8 *)(temp_19) + 4)) == 2) {
                        func_0037f430(arg0);
                    }
                }
            }
        }
        goto block_140;
    case 9:                                         /* switch 1 */
        if (func_00378a70(arg0, temp_20) != 0) {
            func_00389020((*( s32 *)((u8 *)(arg0) + 0x1F294)));
            func_0038d280((*( s32 *)((u8 *)(arg0) + 0x1F298)));
            func_00388fb0((*( s32 *)((u8 *)(arg0) + 0x1F294)));
            if (func_0037f550(arg0) != 0) {
                var_17_3 = 0;
loop_99:
                if (var_17_3 < temp_20) {
                    var_4 = 0;
loop_94:
                    if (var_4 >= (*( s32 *)((u8 *)(temp_19) + 0x28))) {
                        var_2_3 = 0;
                    } else if (var_17_3 == (*( s32 *)((u8 *)((temp_19 + (var_4 * 4))) + 0xC))) {
                        var_2_3 = 1;
                    } else {
                        var_4 += 1;
                        goto loop_94;
                    }
                    if (var_2_3 == 0) {
                        func_00378f90(arg0, var_17_3, 0x14);
                    }
                    var_17_3 += 1;
                    goto loop_99;
                }
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xAU;
            } else {
                func_00379c70(arg0, -1);
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xEU;
            }
        }
        goto block_140;
    case 10:                                        /* switch 1 */
        if (func_00378a70(arg0, temp_20) != 0) {
            var_17_4 = 0;
loop_113:
            if (var_17_4 < temp_20) {
                var_4_2 = 0;
loop_108:
                if (var_4_2 >= (*( s32 *)((u8 *)(temp_19) + 0x28))) {
                    var_2_4 = 0;
                } else if (var_17_4 == (*( s32 *)((u8 *)((temp_19 + (var_4_2 * 4))) + 0xC))) {
                    var_2_4 = 1;
                } else {
                    var_4_2 += 1;
                    goto loop_108;
                }
                if (var_2_4 == 0) {
                    func_00375890(arg0, var_17_4, 0);
                }
                var_17_4 += 1;
                goto loop_113;
            }
            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xBU;
        case 11:                                    /* switch 1 */
            if (func_00378a70(arg0, temp_20) != 0) {
                var_17_5 = 0;
loop_118:
                if (var_17_5 < (*( s32 *)((u8 *)(temp_19) + 0x28))) {
                    func_00379090(arg0, (*( s32 *)((u8 *)((temp_19 + (var_17_5 * 4))) + 0xC)), 0xA, 1);
                    var_17_5 += 1;
                    goto loop_118;
                }
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xCU;
            case 12:                                /* switch 1 */
                if (func_00378a70(arg0, temp_20) != 0) {
                    var_5 = 1;
loop_123:
                    if (var_5 < (*( s32 *)((u8 *)(temp_19) + 0x28))) {
                        temp_4_3 = (u8 *)(arg0 + ((*( s32 *)((u8 *)((temp_19 + (var_5 * 4))) + 0xC)) * 0xE8));
                        (*( u16 *)((u8 *)(temp_4_3) + 0x1D6A0)) = (u16) ((*( u16 *)((u8 *)(temp_4_3) + 0x1D6A0)) & 0xFFFD);
                        var_5 += 1;
                        goto loop_123;
                    }
                    func_00378ec0(arg0, (*( s32 *)((u8 *)(temp_19) + 0xC)));
                    (*( u16 *)((u8 *)(arg0) + 0x1F1D0)) = (u16) ((*( u16 *)((u8 *)(arg0) + 0x1F1D0)) | 0x80);
                    func_0045af60(1, 0, 5, 1);
                    (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xDU;
                case 13:                            /* switch 1 */
                    if (func_00375910(arg0 + ((*( s32 *)((u8 *)(temp_19) + 0xC)) * 0xE8) + 0x1D6A0) == 0) {
                        func_00379c70(arg0, (*( s32 *)((u8 *)(temp_19) + 0xC)));
                        (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xEU;
                    case 14:                        /* switch 1 */
                        if (func_00379d70(arg0) != 0) {
                            (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xFU;
                        case 15:                    /* switch 1 */
                            return 1;
                        }
                        goto block_140;
                    }
                    goto block_140;
                }
                goto block_140;
            }
            goto block_140;
        }
        goto block_140;
    case 16:                                        /* switch 1 */
        if (func_00379a70(arg0) != 0) {
            if ((*( s32 *)((u8 *)(arg0) + 0x1F248)) != 0) {
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 0xFU;
            } else {
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 3U;
            }
        }
        goto block_140;
    case 17:                                        /* switch 1 */
        if (func_00379920(arg0) != 0) {
            temp_3_3 = (u16)((*( u16 *)((u8 *)(arg0) + 0x1F2F4)));
            if (temp_3_3 & 2) {
                (*( u16 *)((u8 *)(arg0) + 0x1F2F4)) = (u16) (temp_3_3 & 0xFFFD);
            }
            temp_3_4 = (u16)((*( u16 *)((u8 *)(arg0) + 0x1F2F0)) + 1);
            (*( u16 *)((u8 *)(arg0) + 0x1F2F0)) = temp_3_4;
            if ((temp_3_4 & 0xFFFF) >= 0x1E) {
                func_00106390(0x1433, 1);
                (*( u32 *)((u8 *)(arg0) + 0x1F2F8)) = 6U;
            }
        }
        goto block_140;
    default:                                        /* switch 1 */
        func_0046d730(&D_0064EB40, 0x295);
        goto block_140;
    }

}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle5", func_0037f6e0);
#endif

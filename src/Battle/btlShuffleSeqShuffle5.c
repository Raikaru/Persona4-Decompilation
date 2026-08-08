#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle5.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
/* Per-unit guarded form: functions 0037F430/0037F550 match byte-exactly; */
/* 0037EF40/0037F6E0 are NONMATCHING with measured floors (see markers). */
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
extern void func_0045af60(s32 a, s32 b, s32 c, s32 d);
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
// FUN_0037EF40
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle5", func_0037ef40);


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


// FUN_0037F6E0 NONMATCHING
// Measured floor (nd 3631, obj 4768/win 4768): callee-saved allocation differs
// (arg0 $s1 vs retail $s0, temp_20 $s0 vs $s4, temp_17 $s5 vs $s1), spC0/spB0
// stack spill slots are folded away, and the state-machine body register
// choices cascade. Remaining structural regions: case-4 loop_50/loop_52 FPU
// scheduling, the case-12/13 block shapes, and block_140's loop. The jump
// table, switch dispatch, madd/msub/adda FPU sequences, and all callees match.
#ifdef NON_MATCHING
s32 func_0037f6e0(u8 *arg0)
{
    ShuffleContext *ctx = (ShuffleContext *)arg0;
    ShuffleSub *sub = &ctx->sub;
    u16 temp_17;
    s32 temp_4;
    s32 var_18;
    s32 temp_20;
    s32 var_21;
    s32 var_2;
    s32 var_20;
    s32 var_19;
    s32 idx;
    s32 temp_3;
    s32 var_4;
    s32 var_5;
    s32 temp_22_2;
    s32 temp_23_2;
    s32 spF0;
    u64 spE0;
    u64 spD0;
    u64 spC0;
    u64 spB0;
    f32 sp168[2];
    f32 sp158[3];
    f32 sp148[2];
    f32 sp138[2];
    f32 sp130[2];
    f32 sp120[2];
    f32 sp110[2];
    f32 sp100[4];
    u16 temp_2_6;
    u16 temp_3_2;
    u16 temp_3_3;
    u16 temp_3_4;
    u32 temp_2;
    f32 var_f1;
    f32 var_f1_2;
    f32 var_f12;
    f32 var_f13;
    f32 var_f13_2;
    f32 var_f0;

    temp_4 = ctx->count_1F304;
    if (temp_4 < 6) {
        var_18 = temp_4 * 2;
    } else {
        var_18 = temp_4;
    }
    temp_20 = func_00378530(temp_4, ctx->mode_1F2FC);
    temp_17 = sub->unk_02;
    temp_2 = ctx->state_1F2F8;
    switch (temp_2) {
    case 0:
        if (func_00378a70(arg0, ctx->count_1F304) != 0) {
            temp_3 = ctx->subState_1F300;
            switch (temp_3) {
            case 0:
                *(u16 *)((u8 *)arg0 + 0x1F1D0) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F1D0) | 0x70);
                break;
            case 1:
                temp_3 = func_003b7060() & 0xFFF;
                if (temp_3 >= 0) {
                    var_f1 = (f32)temp_3;
                } else {
                    var_f1 = (f32)(s32)(((u32)temp_3 >> 1) | (temp_3 & 1)) + (f32)(s32)(((u32)temp_3 >> 1) | (temp_3 & 1));
                }
                *(u16 *)((u8 *)arg0 + 0x1F1D0) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F1D0) | 0x70);
                *(u16 *)((u8 *)arg0 + 0x1F1D0) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F1D0) & (~(0x10 << (s32)(3.0f * (var_f1 / 4096.0f))) & 0xFFFF));
                break;
            case 2:
                temp_3 = func_003b7060() & 0xFFF;
                if (temp_3 >= 0) {
                    var_f1_2 = (f32)temp_3;
                } else {
                    var_f1_2 = (f32)(s32)(((u32)temp_3 >> 1) | (temp_3 & 1)) + (f32)(s32)(((u32)temp_3 >> 1) | (temp_3 & 1));
                }
                *(u16 *)((u8 *)arg0 + 0x1F1D0) = (u16)(*(u16 *)((u8 *)arg0 + 0x1F1D0) | ((0x10 << (s32)(3.0f * (var_f1_2 / 4096.0f))) & 0xFFFF));
                break;
            default:
                func_0046d730(&D_0064EB40[0], 0x41);
                break;
            }
            *(s16 *)((u8 *)arg0 + 0x1F1D0 + 2) = 5;
            if (func_00379240(arg0) != 0) {
                ctx->state_1F2F8 = 1;
            } else {
                ctx->state_1F2F8 = 2;
            }
        }
        goto block_140;
    case 1:
        if (func_00379420(arg0) != 0) {
            ctx->state_1F2F8 = 2;
        case 2:
            temp_3_2 = (u16)(ctx->counter_1F2F0 + 1);
            ctx->counter_1F2F0 = temp_3_2;
            if ((temp_3_2 & 0xFFFF) >= 0) {
                idx = ctx->id_1F298;
                func_0038d060(idx);
                func_0038d0d0(idx, 1);
                ctx->state_1F2F8 = 3;
            }
        }
        goto block_140;
    case 3:
        if (D_008C024E[0] & 0x40) {
            func_0038d0a0(ctx->id_1F298);
            ctx->counter_1F2F0 = 0;
            ctx->state_1F2F8 = 4;
            var_19 = 0;
            while (var_19 < ctx->count_1F304) {
                func_00373750(var_19, ctx->count_1F304, &sp168[0]);
                sp168[1] -= 400.0f;
                func_0036dc60(arg0 + (var_19 * 0xFB0), &sp168[0], &sp148[0], 84.0f);
                idx = var_19 & 0xFFFF;
                if (idx >= 0) {
                    var_f12 = (f32)idx;
                } else {
                    var_f12 = (f32)(s32)(((u32)idx >> 1) | (idx & 1)) + (f32)(s32)(((u32)idx >> 1) | (idx & 1));
                }
                idx = (var_19 + 8) & 0xFFFF;
                if (idx >= 0) {
                    var_f13_2 = (f32)idx;
                } else {
                    var_f13_2 = (f32)(s32)(((u32)idx >> 1) | (idx & 1)) + (f32)(s32)(((u32)idx >> 1) | (idx & 1));
                }
                func_00375d50(arg0, var_19, NULL, &sp148[0], var_f12, var_f13_2);
                var_19 += 1;
            }
            func_0045af60(0, 4, 0, 1);
            func_0045af60(1, 0, 5, 4);
        } else if (D_008C024E[0] & 0x20) {
            func_003799d0(arg0);
            ctx->state_1F2F8 = 0x10;
        }
        goto block_140;
    case 4:
        if (func_00378930(arg0, ctx->count_1F304) != 0) {
            sp158[0] = 0.0f;
            sp158[1] = 0.0f;
            sp158[2] = 0.0f;
            sp100[3] = 0.0f;
            sp100[0] = 0.0f;
            sp100[1] = 1.0f;
            sp100[2] = 0.0f;
            var_21 = 0;
            while (var_21 < temp_20) {
                func_00375d50(arg0, var_21, &sp158[0], &sp158[0], 0.0f, 0.0f);
                func_003760f0(arg0, var_21, 0, 0, &sp100[0], &sp100[0]);
                func_00376290(arg0, var_21, 0, 0xFF, 0xFF);
                var_21 += 1;
            }
            func_0037ef40(arg0);
            ctx->flags_1F2F4 = (u16)(ctx->flags_1F2F4 | 1);
            ctx->state_1F2F8 = 5;
            ctx->counter_1F2F0 = 0;
            sub->count_08 = 0;
            var_20 = 0;
            spE0 = (u64)(temp_17 & 0xFFFF) * 2;
            while (var_20 < 3) {
                var_19 = 0;
                spF0 = var_20 * var_18;
                temp_23_2 = var_20 * 7;
                spD0 = spE0 + (u64)temp_23_2;
                while (var_19 < var_18) {
                    sp168[0] = 314.0f + (f32)((((var_20 * 3) / 3) - 1) * 0x6B);
                    sp168[1] = 236.0f + 120.0f * (f32)(((var_20 * 3) % 3) - 1);
                    temp_22_2 = var_19 + spF0;
                    func_0036dc60(arg0 + (temp_22_2 * 0xFB0), &sp168[0], &sp148[0], 84.0f);
                    sp168[1] += 600.0f;
                    func_0036dc60(arg0 + (temp_22_2 * 0xFB0), &sp168[0], &sp138[0], 84.0f);
                    if (temp_17 >= 0) {
                        var_f0 = (f32)temp_17;
                    } else {
                        var_f0 = (f32)((temp_17 >> 1) | (temp_17 & 1)) + (f32)((temp_17 >> 1) | (temp_17 & 1));
                    }
                    func_00376070(arg0, temp_22_2, temp_23_2 & 0xFFFF, (u32)spD0 & 0xFFFF, &sp148[0], &sp138[0], 5.0f * ((sp138[1] - sp148[1]) / var_f0));
                    var_19 += 1;
                }
                func_003762e0(arg0, spF0, (temp_23_2 + 1) & 0xFFFF, 0, 4);
                var_20 += 1;
            }
        case 5:
            var_19 = 0;
            for (;;) {
                switch (var_19) {
                case 0:
                    var_2 = 2 & 0xFFFF;
                    break;
                case 1:
                    var_2 = 4;
                    break;
                case 2:
                    var_2 = 8;
                    break;
                default:
                    func_0046d730(&D_0064EB40[0], 0x8C);
                    var_2 = 0;
                    break;
                }
                if (!(sub->flags & (var_2 & 0xFFFF)) && func_00375970(arg0 + (var_19 * var_18 * 0xE8) + 0x1D6A0) != 0) {
                    sub->flags = (u16)(sub->flags | var_2);
                    sub->count_08 = sub->count_08 + 1;
                }
                var_19 += 1;
                if (var_19 >= 3) {
                    break;
                }
            }
            if (sub->count_08 == 3) {
                ctx->state_1F2F8 = 6;
            }
        }
        goto block_140;
    case 6:
        if (func_00106330(0x1433) == 0) {
            func_003798d0(arg0, 3);
            ctx->state_1F2F8 = 0x11;
            ctx->counter_1F2F0 = 0;
            ctx->flags_1F2F4 = (u16)(ctx->flags_1F2F4 | 2);
        } else {
            func_00389110(ctx->id_1F294);
            func_00388fd0(ctx->id_1F294);
            func_0038d2c0(ctx->id_1F298);
            ctx->state_1F2F8 = 7;
        case 7:
            if (func_00389160(ctx->id_1F294) != 0) {
                func_0038d1f0(ctx->id_1F298);
                func_00388f60(ctx->id_1F294);
                idx = ctx->id_1F298;
                func_0038d060(idx);
                func_0038d0d0(idx, 2);
                func_00389040(ctx->id_1F294);
                ctx->state_1F2F8 = 8;
            case 8:
                if (D_008C024E[0] & 0x40) {
                    temp_2_6 = sub->unk_04;
                    switch (temp_2_6) {
                    case 0:
                        var_2 = 2 & 0xFFFF;
                        break;
                    case 1:
                        var_2 = 4;
                        break;
                    case 2:
                        var_2 = 8;
                        break;
                    default:
                        func_0046d730(&D_0064EB40[0], 0x8C);
                        var_2 = 0;
                        break;
                    }
                    sub->flags = (u16)(sub->flags & (~(var_2 & 0xFFFF) & 0xFFFF));
                    func_0045af60(1, 2, 5, 5);
                    sub->unk_04 = (u16)(sub->unk_04 + 1);
                    if ((sub->unk_04 & 0xFFFF) == 3) {
                        func_003890f0(ctx->id_1F294);
                        func_0038d0a0(ctx->id_1F298);
                        ctx->state_1F2F8 = 9;
                    } else if (sub->unk_04 == 2) {
                        func_0037f430(arg0);
                    }
                }
            }
        }
        goto block_140;
    case 9:
        if (func_00378a70(arg0, temp_20) != 0) {
            func_00389020(ctx->id_1F294);
            func_0038d280(ctx->id_1F298);
            func_00388fb0(ctx->id_1F294);
            if (func_0037f550(arg0) != 0) {
                var_19 = 0;
                while (var_19 < temp_20) {
                    var_4 = 0;
                    while (var_4 < sub->count_28) {
                        if (var_19 == sub->list[var_4]) {
                            var_5 = 1;
                            goto found;
                        }
                        var_4 += 1;
                    }
                    var_5 = 0;
                found:
                    if (var_5 == 0) {
                        func_00378f90(arg0, var_19, 0x14);
                    }
                    var_19 += 1;
                }
                ctx->state_1F2F8 = 0xA;
            } else {
                func_00379c70(arg0, -1);
                ctx->state_1F2F8 = 0xE;
            }
        }
        goto block_140;
    case 10:
        if (func_00378a70(arg0, temp_20) != 0) {
            var_19 = 0;
            while (var_19 < temp_20) {
                var_4 = 0;
                while (var_4 < sub->count_28) {
                    if (var_19 == sub->list[var_4]) {
                        var_5 = 1;
                        goto found2;
                    }
                    var_4 += 1;
                }
                var_5 = 0;
            found2:
                if (var_5 == 0) {
                    func_00375890(arg0, var_19, 0);
                }
                var_19 += 1;
            }
            ctx->state_1F2F8 = 0xB;
        case 11:
            if (func_00378a70(arg0, temp_20) != 0) {
                var_19 = 0;
                while (var_19 < sub->count_28) {
                    func_00379090(arg0, sub->list[var_19], 0xA, 1);
                    var_19 += 1;
                }
                ctx->state_1F2F8 = 0xC;
            case 12:
                if (func_00378a70(arg0, temp_20) != 0) {
                    var_5 = 1;
                    while (var_5 < sub->count_28) {
                        *(u16 *)((u8 *)arg0 + (sub->list[var_5] * 0xE8) + 0x1D6A0) = (u16)(*(u16 *)((u8 *)arg0 + (sub->list[var_5] * 0xE8) + 0x1D6A0) & 0xFFFD);
                        var_5 += 1;
                    }
                    func_00378ec0(arg0, sub->list[0]);
                    sub->flags = (u16)(sub->flags | 0x80);
                    func_0045af60(1, 0, 5, 1);
                    ctx->state_1F2F8 = 0xD;
                case 13:
                    if (func_00375910(arg0 + (sub->list[0] * 0xE8) + 0x1D6A0) == 0) {
                        func_00379c70(arg0, sub->list[0]);
                        ctx->state_1F2F8 = 0xE;
                    case 14:
                        if (func_00379d70(arg0) != 0) {
                            ctx->state_1F2F8 = 0xF;
                        case 15:
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
    case 16:
        if (func_00379a70(arg0) != 0) {
            if (ctx->unk_1F248 != 0) {
                ctx->state_1F2F8 = 0xF;
            } else {
                ctx->state_1F2F8 = 3;
            }
        }
        goto block_140;
    case 17:
        if (func_00379920(arg0) != 0) {
            temp_3_4 = ctx->flags_1F2F4;
            if (temp_3_4 & 2) {
                ctx->flags_1F2F4 = (u16)(temp_3_4 & 0xFFFD);
            }
            temp_3_3 = (u16)(ctx->counter_1F2F0 + 1);
            ctx->counter_1F2F0 = temp_3_3;
            if ((temp_3_3 & 0xFFFF) >= 0x1E) {
                func_00106390(0x1433, 1);
                ctx->state_1F2F8 = 6;
            }
        }
        goto block_140;
    default:
        func_0046d730(&D_0064EB40[0], 0x295);
        goto block_140;
    }
block_140:
    var_21 = 0;
    for (;;) {
        switch (var_21) {
        case 0:
            var_2 = 2 & 0xFFFF;
            goto block_149;
        case 1:
            var_2 = 4;
            goto block_149;
        case 2:
            var_2 = 8;
            goto block_149;
        default:
            func_0046d730(&D_0064EB40[0], 0x8C);
            var_2 = 0;
            goto block_149;
        }
    block_149:
        if (sub->flags & (var_2 & 0xFFFF)) {
            var_20 = var_18 * var_21;
            spC0 = (u64)(u32)((u8 *)arg0 + 0x1F304);
            spB0 = (u64)var_18 * (u64)(var_21 + 1);
            while (var_20 < spB0) {
                temp_17 = *(u16 *)((u8 *)arg0 + 0x1F1D2);
                idx = *(s32 *)((u32)spC0);
                if (func_00375910(arg0 + (var_20 * 0xE8) + 0x1D6A0) != 0) {
                    func_003717e0(arg0 + (var_20 * 0xE8) + 0x1D6B8, &sp130[0]);
                    if (sp130[1] >= 508.0f) {
                        sp130[1] = sp130[1] - 120.0f * (f32)((idx < 6) ? (idx << 1) : idx);
                    }
                    func_0036dc60(arg0 + (var_20 * 0xFB0), &sp130[0], &sp120[0], 84.0f);
                    sp130[1] += 120.0f;
                    func_0036dc60(arg0 + (var_20 * 0xFB0), &sp130[0], &sp110[0], 84.0f);
                    if (temp_17 >= 0) {
                        var_f13 = (f32)temp_17;
                    } else {
                        var_f13 = (f32)((temp_17 >> 1) | (temp_17 & 1)) + (f32)((temp_17 >> 1) | (temp_17 & 1));
                    }
                    func_00375d50(arg0, var_20, &sp120[0], &sp110[0], 0.0f, var_f13);
                }
                var_20 += 1;
            }
        }
        var_21 += 1;
        if (var_21 >= 3) {
            break;
        }
    }
    return 0;
}
#else
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle5", func_0037f6e0);
#endif

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


// Measured floor (nd 3631, obj 4768/win 4768): callee-saved allocation differs
// (arg0 $s1 vs retail $s0, temp_20 $s0 vs $s4, temp_17 $s5 vs $s1), spC0/spB0
// stack spill slots are folded away, and the state-machine body register
// choices cascade. Remaining structural regions: case-4 loop_50/loop_52 FPU
// scheduling, the case-12/13 block shapes, and block_140's loop. The jump
// table, switch dispatch, madd/msub/adda FPU sequences, and all callees match.
// FUN_0037F6E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleSeqShuffle5", func_0037f6e0);

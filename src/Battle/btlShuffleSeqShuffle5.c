#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle5.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
/* Recovered functions retain the retail card-row state machine and layouts. */
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
    u8 *id_1F294;           /* 0x1F294 */
    u8 *id_1F298;           /* 0x1F298 */
    u8 _pad29C[0x54];
    u16 counter_1F2F0;      /* 0x1F2F0 */
    u8 _pad2F2[2];
    u16 flags_1F2F4;        /* 0x1F2F4 */
    u8 _pad2F6[2];
    u32 state_1F2F8;        /* 0x1F2F8 */
    s32 mode_1F2FC;         /* 0x1F2FC */
    s32 subState_1F300;     /* 0x1F300 */
    s32 count_1F304;        /* 0x1F304 */
} ShuffleContext;           /* 0x1F308 */

extern void func_0046d730(const void *file, u32 line);
extern u32 RpRandom(void);
extern s32 func_0037ed90(u8 *ctx, s32 slot);
extern s32 func_00379150(u8 *ctx, s32 a, s32 b);
extern void func_00389090(u8 *a, s32 b);
extern s32 func_00378530(s32 a, s32 b);
extern s32 func_00378a70(u8 *ctx, s32 n);
extern s32 func_00378930(u8 *ctx, s32 n);
extern s32 func_0045af60(s16 index, s16 stream, s16 arg2, s16 arg3);
extern s32 func_00379240(u8 *ctx);
extern s32 func_00379420(u8 *ctx);
extern void func_0038d060(u8 *a);
extern void func_0038d0d0(u8 *a, s32 b);
extern void func_0038d0a0(u8 *a);
extern void func_0038d2c0(u8 *a);
extern void func_00389110(u8 *a);
extern void func_00388fd0(u8 *a);
extern s32 func_00389160(u8 *a);
extern void func_0038d1f0(u8 *a);
extern void func_00388f60(u8 *a);
extern void func_00389040(u8 *a);
extern void func_003890f0(u8 *a);
extern void func_00389020(u8 *a);
extern void func_0038d280(u8 *a);
extern void func_00388fb0(u8 *a);
extern s32 func_0037f430(u8 *ctx);
extern s32 func_0037f550(u8 *ctx);
extern void func_00378f90(u8 *ctx, s32 a, s32 b);
extern void func_00375890(u8 *ctx, s32 a, s32 b);
extern void func_00379090(u8 *ctx, s32 a, u16 b, s32 c);
extern void func_00378ec0(u8 *ctx, s32 a);
extern s32 func_00379c70(u8 *ctx, s32 a);
extern s32 func_00379d70(u8 *ctx);
extern s32 func_00379a70(u8 *ctx);
extern s32 func_00379920(u8 *ctx);
extern void func_003799d0(u8 *ctx);
extern void func_003798d0(u8 *ctx, s32 a);
extern s32 datGetFlag(s32 a);
extern void func_00106390(s32 a, s32 b);
extern s32 func_003717e0(u8 *a, u8 *b);
extern void func_0036dc60(u8 *unit, f32 *src, f32 scale, f32 *dst);
extern void func_00375d50(u8 *ctx, s32 idx, f32 start, f32 end, f32 *from, f32 *to);
extern void func_00376070(u8 *ctx, s32 idx, u16 start, u16 end, f32 *from, f32 *to, f32 speed);
extern void func_003760f0(u8 *ctx, s32 a, u16 b, u16 c, f32 *d, f32 *e);
extern void func_00376290(u8 *ctx, s32 a, s32 b, s32 c, s32 d);
extern void func_003762e0(u8 *ctx, s32 a, s32 b, s32 c, s32 d);
extern s32 func_00375910(u8 *a);
extern s32 func_00375970(u8 *a);
extern void func_00373750(s32 a, s32 b, f32 *c);
extern void func_0037ef40(u8 *ctx);

extern u32 D_0064EB40[];
extern u16 D_008C024E[];


typedef struct {
    s32 words[0x3EC];
} ShuffleCardRecord;

/* measured: 1260B in the 1264B window. Swapping whole 0xFB0-byte card
   records emits retail's word-pair copy loops, and indexing the deck as
   cards[rowStart + k] under loop-invariant hoisting reproduces retail's
   row-product-then-counter preheader order. */
#pragma opt_loop_invariants on
// FUN_0037EF40
void func_0037ef40(u8 *arg0) {
    ShuffleCardRecord *cards;
    ShuffleCardRecord tmp0;
    ShuffleCardRecord tmp2;
    ShuffleCardRecord tmp1;
    s32 n;
    s32 i;
    s32 k;
    s32 c;
    s32 first;
    s32 second;

    cards = (ShuffleCardRecord *)arg0;
    if (*(s32 *)(arg0 + 0x1F2FC) != 4) {
        func_0046d730(&D_0064EB40[0], 0xBD);
    }
    n = *(s32 *)(arg0 + 0x1F304);
    if (n < 6) {
        for (i = 0; i < 6; i += 2) {
            first = i * n;
            second = (i + 1) * n;
            for (k = n - 1; k > 0; k--) {
                c = (k + 1) * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
                if (k < 0 || k >= n) {
                    func_0046d730(&D_0064EB40[0], 0xCB);
                }
                if (c < 0 || c >= n) {
                    func_0046d730(&D_0064EB40[0], 0xCC);
                }
                tmp0 = cards[first + k];
                cards[first + k] = cards[first + c];
                cards[first + c] = tmp0;
                tmp1 = cards[second + k];
                cards[second + k] = cards[second + c];
                cards[second + c] = tmp1;
            }
        }
    } else {
        for (i = 0; i < 3; i++) {
            first = i * n;
            for (k = *(s32 *)(arg0 + 0x1F304) - 1; k > 0; k--) {
                c = (k + 1) * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
                if (k < 0 || k >= n) {
                    func_0046d730(&D_0064EB40[0], 0xDF);
                }
                if (c < 0 || c >= n) {
                    func_0046d730(&D_0064EB40[0], 0xE0);
                }
                tmp2 = cards[first + k];
                cards[first + k] = cards[first + c];
                cards[first + c] = tmp2;
            }
        }
    }
}
#pragma opt_loop_invariants off
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

/* Three-row shuffle state machine. Row population and continuous motion use
   separate vector objects; smaller decks repeat their cards to fill a row.
   Measured in the whole owner with b210 -O2: 4760 bytes, exact retail words.
   Lifetime splitting preserves the independent state-machine phases, while
   loop-invariant hoisting retains the row products and vector addresses. */
#pragma push
#pragma opt_loop_invariants on

static inline u16 shuffle5RowMask(s32 row)
{
    switch (row) {
    case 0:
        return 2;
    case 1:
        return 4;
    case 2:
        return 8;
    default:
        func_0046d730(&D_0064EB40, 0x8C);
        return 0;
    }
}

static inline s32 shuffle5Contains(u8 *state, s32 card)
{
    s32 slot;
    for (slot = 0; slot < *(s32 *)(state + 0x28); slot++) {
        if (card == *(s32 *)(state + slot * 4 + 0xC)) {
            return 1;
        }
    }
    return 0;
}

static inline s32 shuffle5MovingRowSize(s32 count)
{
    return count < 6 ? count * 2 : count;
}

#pragma opt_lifetimes on
// FUN_0037F6E0
s32 func_0037f6e0(u8 *work)
{
    f32 screen[2];
    f32 origin[3];
    f32 from[3];
    f32 to[3];
    f32 movingScreen[2];
    f32 movingFrom[3];
    f32 movingTo[3];
    f32 rotation[4];
    s32 column;
    s32 randomIndex;
    u8 *state;
    u8 *card;
    u8 *deck;
    s32 rowSize;
    s32 total;
    s32 i;
    s32 j;
    s32 k;
    s32 index;
    s32 initialCount;
    u16 speed;
    u16 mask;
    u16 input;

    state = work + 0x1F1D0;
    initialCount = *(s32 *)(work + 0x1F304);
    if (initialCount < 6) {
        rowSize = initialCount * 2;
    } else {
        rowSize = initialCount;
    }
    total = func_00378530(initialCount, *(s32 *)(work + 0x1F2FC));
    speed = *(u16 *)(state + 2);
    switch (*(u32 *)(work + 0x1F2F8)) {
    case 0:
        if (func_00378a70(work, *(s32 *)(work + 0x1F304)) == 0) {
            break;
        }
        {
            u16 *rowFlags = (u16 *)(work + 0x1F1D0);
            switch (*(s32 *)(work + 0x1F300)) {
            case 0:
                *rowFlags |= 0x70;
                break;
            case 1:
                randomIndex = (s32)(3.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f));
                *rowFlags |= 0x70;
                *rowFlags &= ~(0x10 << randomIndex);
                break;
            case 2:
                *rowFlags |= 0x10 << (s32)(3.0f * ((f32)(RpRandom() & 0xFFF) / 4096.0f));
                break;
            default:
                func_0046d730(&D_0064EB40, 0x41);
                break;
            }
            rowFlags[1] = 5;
        }
        if (func_00379240(work) != 0) {
            *(u32 *)(work + 0x1F2F8) = 1;
        } else {
            *(u32 *)(work + 0x1F2F8) = 2;
        }
        break;
    case 1:
        if (func_00379420(work) == 0) {
            break;
        }
        *(u32 *)(work + 0x1F2F8) = 2;
    case 2:
        /* Retail tests the zero-extended increment with bltz (0037F9D8).
           The branch is unreachable, but removing it changes the code. */
        if (++*(u16 *)(work + 0x1F2F0) < 0) {
            break;
        }
        deck = *(u8 **)(work + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 1);
        *(u32 *)(work + 0x1F2F8) = 3;
        break;
    case 3:
        input = D_008C024E[0];
        if (input & 0x40) {
            func_0038d0a0(*(u8 **)(work + 0x1F298));
            *(u16 *)(work + 0x1F2F0) = 0;
            *(u32 *)(work + 0x1F2F8) = 4;
            for (i = 0; i < *(s32 *)(work + 0x1F304); i++) {
                func_00373750(i, *(s32 *)(work + 0x1F304), screen);
                screen[1] -= 400.0f;
                func_0036dc60(work + i * 0xFB0, screen, 84.0f, origin);
                func_00375d50(work, i, (u16)i, (u16)(i + 8), NULL, origin);
            }
            func_0045af60(0, 4, 0, 1);
            func_0045af60(1, 0, 5, 4);
        } else if (input & 0x20) {
            func_003799d0(work);
            *(u32 *)(work + 0x1F2F8) = 16;
        }
        break;
    case 4:
        if (func_00378930(work, *(s32 *)(work + 0x1F304)) == 0) {
            break;
        }
        origin[0] = 0.0f;
        origin[1] = 0.0f;
        origin[2] = 0.0f;
        rotation[3] = 0.0f;
        rotation[0] = 0.0f;
        rotation[1] = 1.0f;
        rotation[2] = 0.0f;
        for (j = 0; j < total; j++) {
            func_00375d50(work, j, 0.0f, 0.0f, origin, origin);
            func_003760f0(work, j, 0, 0, rotation, rotation);
            func_00376290(work, j, 0, 0xFF, 0xFF);
        }
        func_0037ef40(work);
        *(u16 *)(work + 0x1F2F4) |= 1;
        *(u32 *)(work + 0x1F2F8) = 5;
        *(u16 *)(work + 0x1F2F0) = 0;
        *(s32 *)(state + 8) = 0;
        for (i = 0; i < 3; i++) {
            for (column = 0; column < rowSize; column++) {
                screen[0] = 314.0f + (f32)((i * 3 / 3 - 1) * 107);
                screen[1] = (0.0f + 236.0f) + 120.0f * (f32)((i * 3) % 3 - 1);
                screen[1] = (0.0f + screen[1]) - 120.0f * (f32)(rowSize + 1 - column % rowSize);
                index = column + i * rowSize;
                card = work + index * 0xFB0;
                func_0036dc60(card, screen, 84.0f, from);
                screen[1] += 600.0f;
                func_0036dc60(card, screen, 84.0f, to);
                func_00376070(work, index, (u16)(i * 7), (u16)((u16)speed * 2 + i * 7), from, to,
                             5.0f * ((to[1] - from[1]) / (f32)speed));
            }
            func_003762e0(work, i * rowSize, (u16)(i * 7 + 1), 0, 4);
        }
    case 5:
        for (i = 0; i < 3; i++) {
            mask = shuffle5RowMask(i);
            if ((*(u16 *)state & mask) == 0 && func_00375970(work + i * rowSize * 0xE8 + 0x1D6A0) != 0) {
                *(u16 *)state |= mask;
                ++*(s32 *)(state + 8);
            }
        }
        if (*(s32 *)(state + 8) == 3) {
            *(u32 *)(work + 0x1F2F8) = 6;
        }
        break;
    case 6:
        if (datGetFlag(0x1433) == 0) {
            func_003798d0(work, 3);
            *(u32 *)(work + 0x1F2F8) = 17;
            *(u16 *)(work + 0x1F2F0) = 0;
            *(u16 *)(work + 0x1F2F4) |= 2;
            break;
        }
        func_00389110(*(u8 **)(work + 0x1F294));
        func_00388fd0(*(u8 **)(work + 0x1F294));
        func_0038d2c0(*(u8 **)(work + 0x1F298));
        *(u32 *)(work + 0x1F2F8) = 7;
    case 7:
        if (func_00389160(*(u8 **)(work + 0x1F294)) == 0) {
            break;
        }
        func_0038d1f0(*(u8 **)(work + 0x1F298));
        func_00388f60(*(u8 **)(work + 0x1F294));
        deck = *(u8 **)(work + 0x1F298);
        func_0038d060(deck);
        func_0038d0d0(deck, 2);
        func_00389040(*(u8 **)(work + 0x1F294));
        *(u32 *)(work + 0x1F2F8) = 8;
    case 8:
        if (D_008C024E[0] & 0x40) {
            mask = shuffle5RowMask(*(u16 *)(state + 4));
            *(u16 *)state &= (u16)~mask;
            func_0045af60(1, 2, 5, 5);
            if (++*(u16 *)(state + 4) == 3) {
                func_003890f0(*(u8 **)(work + 0x1F294));
                func_0038d0a0(*(u8 **)(work + 0x1F298));
                *(u32 *)(work + 0x1F2F8) = 9;
            } else if (*(u16 *)(state + 4) == 2) {
                func_0037f430(work);
            }
        }
        break;
    case 9:
        if (func_00378a70(work, total) == 0) {
            break;
        }
        func_00389020(*(u8 **)(work + 0x1F294));
        func_0038d280(*(u8 **)(work + 0x1F298));
        func_00388fb0(*(u8 **)(work + 0x1F294));
        if (func_0037f550(work) != 0) {
            for (i = 0; i < total; i++) {
                if (!shuffle5Contains(state, i)) {
                    func_00378f90(work, i, 0x14);
                }
            }
            *(u32 *)(work + 0x1F2F8) = 10;
        } else {
            func_00379c70(work, -1);
            *(u32 *)(work + 0x1F2F8) = 14;
        }
        break;
    case 10:
        if (func_00378a70(work, total) == 0) {
            break;
        }
        for (i = 0; i < total; i++) {
            if (!shuffle5Contains(state, i)) {
                func_00375890(work, i, 0);
            }
        }
        *(u32 *)(work + 0x1F2F8) = 11;
    case 11:
        if (func_00378a70(work, total) == 0) {
            break;
        }
        for (i = 0; i < *(s32 *)(state + 0x28); i++) {
            func_00379090(work, *(s32 *)(state + i * 4 + 0xC), 0xA, 1);
        }
        *(u32 *)(work + 0x1F2F8) = 12;
    case 12:
        if (func_00378a70(work, total) == 0) {
            break;
        }
        for (j = 1; j < *(s32 *)(state + 0x28); j++) {
            *(u16 *)(work + *(s32 *)(state + j * 4 + 0xC) * 0xE8 + 0x1D6A0) &= 0xFFFD;
        }
        func_00378ec0(work, *(s32 *)(state + 0xC));
        *(u16 *)state |= 0x80;
        func_0045af60(1, 0, 5, 1);
        *(u32 *)(work + 0x1F2F8) = 13;
    case 13:
        if (func_00375910(work + *(s32 *)(state + 0xC) * 0xE8 + 0x1D6A0) != 0) {
            break;
        }
        func_00379c70(work, *(s32 *)(state + 0xC));
        *(u32 *)(work + 0x1F2F8) = 14;
    case 14:
        if (func_00379d70(work) == 0) {
            break;
        }
        *(u32 *)(work + 0x1F2F8) = 15;
    case 15:
        return 1;
    case 16:
        if (func_00379a70(work) != 0) {
            if (*(s32 *)(work + 0x1F248) != 0) {
                *(u32 *)(work + 0x1F2F8) = 15;
            } else {
                *(u32 *)(work + 0x1F2F8) = 3;
            }
        }
        break;
    case 17:
        if (func_00379920(work) != 0) {
            if (*(u16 *)(work + 0x1F2F4) & 2) {
                *(u16 *)(work + 0x1F2F4) &= 0xFFFD;
            }
            if (++*(u16 *)(work + 0x1F2F0) >= 0x1E) {
                func_00106390(0x1433, 1);
                *(u32 *)(work + 0x1F2F8) = 6;
            }
        }
        break;
    default:
        func_0046d730(&D_0064EB40, 0x295);
        break;
    }
    for (k = 0; k < 3; k++) {
        mask = shuffle5RowMask(k);
        if (*(u16 *)state & mask) {
            for (i = rowSize * k; i < rowSize * (k + 1); i++) {
                speed = *(u16 *)(work + 0x1F1D2);
                j = shuffle5MovingRowSize(*(s32 *)(work + 0x1F304));
                card = work + i * 0xE8;
                if (func_00375910(card + 0x1D6A0) != 0) {
                    func_003717e0(card + 0x1D6B8, (u8 *)movingScreen);
                    if (!(movingScreen[1] < 508.0f)) {
                        movingScreen[1] = (0.0f + movingScreen[1]) - 120.0f * (f32)j;
                    }
                    card = work + i * 0xFB0;
                    func_0036dc60(card, movingScreen, 84.0f, movingFrom);
                    movingScreen[1] += 120.0f;
                    func_0036dc60(card, movingScreen, 84.0f, movingTo);
                    func_00375d50(work, i, 0.0f, (f32)speed, movingFrom, movingTo);
                }
            }
        }
    }
    return 0;
}
#pragma pop

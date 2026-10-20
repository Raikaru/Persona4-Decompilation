#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle5.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
/* Recovered functions retain the retail card-row state machine and layouts. */
#include "type.h"
#include "member_access.h"

#include "btl_shuffle_sequence_internal.h"

extern void kAssertFail(const void *file, u32 line);
extern u32 RpRandom(void);
extern s32 btlShuffleSeqFindNearestCard(u8 *context, s32 gridIndex);
extern s32 btlShuffleSeqCheck(u8 *context, s32 firstIndex, s32 secondIndex);
extern void btlShuffleDrawViewAddGlowCard(u8 *drawWork, s32 input);
extern s32 btlShuffleDrawTableLookup(s32 cardCount, s32 pattern);
extern s32 btlShuffleSeqPick(u8 *context, s32 count);
extern s32 btlShuffleSeqCountA(u8 *context, s32 count);
extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);
extern s32 btlShuffleSeqLoadRecord(u8 *context);
extern s32 btlShuffleSeqStep(u8 *context);
extern void btlShuffleDrawCardActivate(u8 *drawWork);
extern void btlShuffleDrawCardSetDetail(u8 *drawWork, s32 input);
extern void btlShuffleDrawCardEndDetail(u8 *drawWork);
extern void btlShuffleDrawCardStartBands(u8 *drawWork);
extern void btlShuffleDrawViewStartCue(u8 *drawWork);
extern void btlShuffleDrawViewStartPatternFade(u8 *drawWork);
extern s32 btlShuffleDrawViewIsCueIdle(u8 *drawWork);
extern void btlShuffleDrawCardStartSelection(u8 *drawWork);
extern void btlShuffleDrawViewStartFrameFade(u8 *drawWork);
extern void btlShuffleDrawViewStartGlow(u8 *drawWork);
extern void btlShuffleDrawViewClearGlow(u8 *drawWork);
extern void btlShuffleDrawViewEndPatternFade(u8 *drawWork);
extern void btlShuffleDrawCardEndSelection(u8 *drawWork);
extern void btlShuffleDrawViewEndFrameFade(u8 *drawWork);
extern /* measured: both row-match checks also match with surrounding loop-invariant extraction enabled. */
s32 btlShuffleSeq5Check(u8 *context);
extern s32 btlShuffleSeq5Check2(u8 *context);
extern void btlShuffleSeqSetMode(u8 *context, s32 cardIndex, s32 frames);
extern void btlShuffleDrawPoll(u8 *context, s32 cardIndex, s32 enabled);
extern void btlShuffleSeqUpdateMode(u8 *ctx, s32 idx, u16 mode, s32 direction);
extern void btlShuffleSeqMoveB(u8 *context, s32 cardIndex);
extern s32 btlShuffleSeqCardCount(u8 *context, s32 cardIndex);
extern s32 btlShuffleSeqDispatch(u8 *context);
extern s32 btlShuffleSeqStateCheck(u8 *context);
extern s32 btlShuffleSeqFlag(u8 *context);
extern void btlShuffleSeqReset(u8 *context);
extern void btlShuffleSeqClearA(u8 *context, s32 count);
extern s32 datGetFlag(s32 bit);
extern void datSetFlag(s32 flagId, s32 enabled);
extern s32 btlShuffleCalcUpdateSpeed(u8 *point, u8 *screen);
extern void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 scale, f32 *dst);
extern void btlShuffleDrawMoveCard(u8 *context, s32 cardIndex, f32 delay, f32 duration, f32 *start, f32 *target);
extern void btlShuffleDrawSetRange(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target, f32 displacement);
extern void btlShuffleDrawSetQuat(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target);
extern void btlShuffleDrawSetFrames(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start);
extern void btlShuffleDrawSetFrameFlags(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start);
extern s32 btlShuffleDrawStateA(u8 *record);
extern s32 btlShuffleDrawStateB(u8 *record);
extern void btlShuffleCalcFillTable(s32 cardIndex, s32 cardCount, f32 *screen);
extern void btlShuffleSeq5Shuffle(u8 *context);

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
/* Shuffle repeated row pairs together for small decks, or each independent row for larger decks. */
// FUN_0037EF40
void btlShuffleSeq5Shuffle(u8 *context) {
    BtlShuffleContext *shuffleContext = (BtlShuffleContext *)(context);
    ShuffleCardRecord *cards;
    ShuffleCardRecord firstSwap;
    ShuffleCardRecord rowSwap;
    ShuffleCardRecord secondSwap;
    s32 n;
    s32 i;
    s32 k;
    s32 c;
    s32 first;
    s32 second;

    cards = (ShuffleCardRecord *)context;
    if (((BtlShuffleContext *)context)->pattern != 4) {
        kAssertFail(&D_0064EB40[0], 0xBD);
    }
    /* measured: the typed context alias preserves the original loop allocation. */
    n = shuffleContext->cardCount;
    if (n < 6) {
        for (i = 0; i < 6; i += 2) {
            first = i * n;
            second = (i + 1) * n;
            for (k = n - 1; k > 0; k--) {
                c = (k + 1) * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
                if (k < 0 || k >= n) {
                    kAssertFail(&D_0064EB40[0], 0xCB);
                }
                if (c < 0 || c >= n) {
                    kAssertFail(&D_0064EB40[0], 0xCC);
                }
                firstSwap = cards[first + k];
                cards[first + k] = cards[first + c];
                cards[first + c] = firstSwap;
                secondSwap = cards[second + k];
                cards[second + k] = cards[second + c];
                cards[second + c] = secondSwap;
            }
        }
    } else {
        for (i = 0; i < 3; i++) {
            first = i * n;
            for (k = ((BtlShuffleContext *)context)->cardCount - 1; k > 0; k--) {
                c = (k + 1) * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
                if (k < 0 || k >= n) {
                    kAssertFail(&D_0064EB40[0], 0xDF);
                }
                if (c < 0 || c >= n) {
                    kAssertFail(&D_0064EB40[0], 0xE0);
                }
                rowSwap = cards[first + k];
                cards[first + k] = cards[first + c];
                cards[first + c] = rowSwap;
            }
        }
    }
}
/* Highlight row cards matching the center card and report whether any row matches. */
// FUN_0037F430
s32 btlShuffleSeq5Check(u8 *context)
{
    BtlShuffleContext *ctx = (BtlShuffleContext *)context;
    BtlShuffleRowState *sub = (BtlShuffleRowState *)&ctx->sequenceFlags;
    s32 hasMatch;
    s32 rowIndex;
    s32 rowCard;
    s32 centerCard;

    hasMatch = 0;
    centerCard = btlShuffleSeqFindNearestCard(context, 4);
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (sub->flags & ((0x10 << rowIndex) & 0xFFFF)) {
            rowCard = btlShuffleSeqFindNearestCard(context, rowIndex);
            if (btlShuffleSeqCheck(context, rowCard, centerCard) != 0) {
                hasMatch = 1;
                btlShuffleDrawViewAddGlowCard(ctx->viewTask, rowCard);
            }
        }
    }
    if (hasMatch != 0) {
        btlShuffleDrawViewAddGlowCard(ctx->viewTask, centerCard);
    }
    return hasMatch;
}


/* Collect the center card and each complete matching row pair for the result phase. */
// FUN_0037F550
s32 btlShuffleSeq5Check2(u8 *context)
{
    BtlShuffleContext *ctx = (BtlShuffleContext *)context;
    BtlShuffleRowState *sub = (BtlShuffleRowState *)&ctx->sequenceFlags;
    s32 hasMatch;
    s32 rowIndex;
    s32 card;
    s32 firstCard;
    s32 centerCard;
    s32 lastCard;
    s32 slotIndex;

    hasMatch = 0;
    sub->cardCount = 0;
    centerCard = btlShuffleSeqFindNearestCard(context, 4);
    slotIndex = sub->cardCount;
    sub->cardCount = slotIndex + 1;
    sub->cards[slotIndex] = centerCard;
    for (rowIndex = 0; rowIndex < 3; rowIndex++) {
        if (sub->flags & ((0x10 << rowIndex) & 0xFFFF)) {
            firstCard = btlShuffleSeqFindNearestCard(context, rowIndex);
            lastCard = btlShuffleSeqFindNearestCard(context, 8 - rowIndex);
            if ((btlShuffleSeqCheck(context, firstCard, centerCard) != 0) && (btlShuffleSeqCheck(context, centerCard, lastCard) != 0)) {
                hasMatch = 1;
                slotIndex = sub->cardCount;
                sub->cardCount = slotIndex + 1;
                /* Append both ends of the matching row to the result list. */
                ((BtlShuffleRowState *)sub)->cards[slotIndex] = firstCard;
                slotIndex = sub->cardCount;
                sub->cardCount = slotIndex + 1;
                ((BtlShuffleRowState *)sub)->cards[slotIndex] = lastCard;
            }
        }
    }
    if (sub->cardCount > 7) {
        kAssertFail(&D_0064EB40[0], 0x132);
    }
    return hasMatch;
}

/* Three-row shuffle state machine. Row population and continuous motion use
   separate vector objects; smaller decks repeat their cards to fill a row.
   Measured in the whole owner with b210 -O2: 4760 bytes, exact retail words.
   Lifetime splitting preserves the independent state-machine phases, while
   loop-invariant hoisting retains the row products and vector addresses. */
#pragma push

/* Return the stop flag for one of the three valid shuffle rows. */
static inline u16 btlShuffleRowMask(s32 row)
{
    switch (row) {
    case 0:
        return 2;
    case 1:
        return 4;
    case 2:
        return 8;
    default:
        kAssertFail(&D_0064EB40, 0x8C);
        return 0;
    }
}

/* Test whether the row state contains the supplied card index. */
static inline s32 btlShuffleRowContains(u8 *state, s32 card)
{
    s32 slot;
    for (slot = 0; slot < ((BtlShuffleRowState *)state)->cardCount; slot++) {
        if (card == ((BtlShuffleRowState *)state)->cards[slot]) {
            return 1;
        }
    }
    return 0;
}

/* Repeat short decks twice to populate a continuously moving row. */
static inline s32 btlShuffleMovingRowSize(s32 count)
{
    return count < 6 ? count * 2 : count;
}

/* measured: baseline nd147; typed pointer reuse, typed parameter cache, scoped locals, inverted if/else did not match (best nd147); retain opt_lifetimes on. */
#pragma opt_lifetimes on
/* Run the three moving rows, stopping them on input and resolving matching card groups. */
// FUN_0037F6E0
s32 btlShuffleSeq5Run(u8 *work)
{
    BtlShuffleRowState *rowState = (BtlShuffleRowState *)(work + 0x1F1D0);
    BtlShuffleContext *shuffleContext = (BtlShuffleContext *)(work);
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
    /* measured: the typed context alias preserves the original loop allocation. */
    initialCount = shuffleContext->cardCount;
    if (initialCount < 6) {
        rowSize = initialCount * 2;
    } else {
        rowSize = initialCount;
    }
    total = btlShuffleDrawTableLookup(initialCount, ((BtlShuffleContext *)work)->pattern);
    speed = ((BtlShuffleRowState *)state)->frames;
    /* measured: typing this dispatch read shrinks Run to 4592 bytes; all phase stores remain typed. */
    switch (shuffleContext->phase) {
    case 0:
        if (btlShuffleSeqPick(work, ((BtlShuffleContext *)work)->cardCount) == 0) {
            break;
        }
        {
            u16 *rowFlags = (u16 *)(work + 0x1F1D0);
            switch (((BtlShuffleContext *)work)->difficulty) {
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
                kAssertFail(&D_0064EB40, 0x41);
                break;
            }
            rowFlags[1] = 5;
        }
        if (btlShuffleSeqLoadRecord(work) != 0) {
            ((BtlShuffleContext *)work)->phase = 1;
        } else {
            ((BtlShuffleContext *)work)->phase = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(work) == 0) {
            break;
        }
        ((BtlShuffleContext *)work)->phase = 2;
    case 2:
        /* Retail tests the zero-extended increment with bltz (0037F9D8).
           The branch is unreachable, but removing it changes the code. */
        if (++((BtlShuffleContext *)work)->elapsed < 0) {
            break;
        }
        deck = ((BtlShuffleContext *)work)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 1);
        ((BtlShuffleContext *)work)->phase = 3;
        break;
    case 3:
        input = D_008C024E[0];
        if (input & 0x40) {
            btlShuffleDrawCardEndDetail(((BtlShuffleContext *)work)->cardTask);
            ((BtlShuffleContext *)work)->elapsed = 0;
            ((BtlShuffleContext *)work)->phase = 4;
            for (i = 0; i < shuffleContext->cardCount; i++) {
                btlShuffleCalcFillTable(i, shuffleContext->cardCount, screen);
                screen[1] -= 400.0f;
                btlShuffleCardScaleVec(work + i * 0xFB0, screen, 84.0f, origin);
                btlShuffleDrawMoveCard(work, i, (u16)i, (u16)(i + 8), NULL, origin);
            }
            sdkSndStartStream(0, 4, 0, 1);
            sdkSndStartStream(1, 0, 5, 4);
        } else if (input & 0x20) {
            btlShuffleSeqReset(work);
            ((BtlShuffleContext *)work)->phase = 16;
        }
        break;
    case 4:
        if (btlShuffleSeqCountA(work, ((BtlShuffleContext *)work)->cardCount) == 0) {
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
            btlShuffleDrawMoveCard(work, j, 0.0f, 0.0f, origin, origin);
            btlShuffleDrawSetQuat(work, j, 0, 0, rotation, rotation);
            btlShuffleDrawSetFrames(work, j, 0, 0xFF, 0xFF);
        }
        btlShuffleSeq5Shuffle(work);
        ((BtlShuffleContext *)work)->flags |= 1;
        ((BtlShuffleContext *)work)->phase = 5;
        ((BtlShuffleContext *)work)->elapsed = 0;
        ((BtlShuffleRowState *)state)->stoppedRows = 0;
        for (i = 0; i < 3; i++) {
            for (column = 0; column < rowSize; column++) {
                screen[0] = 314.0f + (f32)((i * 3 / 3 - 1) * 107);
                screen[1] = (0.0f + 236.0f) + 120.0f * (f32)((i * 3) % 3 - 1);
                screen[1] = (0.0f + screen[1]) - 120.0f * (f32)(rowSize + 1 - column % rowSize);
                index = column + i * rowSize;
                card = work + index * 0xFB0;
                btlShuffleCardScaleVec(card, screen, 84.0f, from);
                screen[1] += 600.0f;
                btlShuffleCardScaleVec(card, screen, 84.0f, to);
                btlShuffleDrawSetRange(work, index, (u16)(i * 7), (u16)((u16)speed * 2 + i * 7), from, to,
                             5.0f * ((to[1] - from[1]) / (f32)speed));
            }
            btlShuffleDrawSetFrameFlags(work, i * rowSize, (u16)(i * 7 + 1), 0, 4);
        }
    case 5:
        for (i = 0; i < 3; i++) {
            mask = btlShuffleRowMask(i);
            if ((((BtlShuffleRowState *)state)->flags & mask) == 0 && btlShuffleDrawStateB(work + i * rowSize * 0xE8 + 0x1D6A0) != 0) {
                ((BtlShuffleRowState *)state)->flags |= mask;
                ++((BtlShuffleRowState *)state)->stoppedRows;
            }
        }
        if (((BtlShuffleRowState *)state)->stoppedRows == 3) {
            ((BtlShuffleContext *)work)->phase = 6;
        }
        break;
    case 6:
        if (datGetFlag(0x1433) == 0) {
            btlShuffleSeqClearA(work, 3);
            ((BtlShuffleContext *)work)->phase = 17;
            ((BtlShuffleContext *)work)->elapsed = 0;
            ((BtlShuffleContext *)work)->flags |= 2;
            break;
        }
        btlShuffleDrawViewStartCue(shuffleContext->viewTask);
        btlShuffleDrawViewStartPatternFade(((BtlShuffleContext *)work)->viewTask);
        btlShuffleDrawCardStartBands(((BtlShuffleContext *)work)->cardTask);
        ((BtlShuffleContext *)work)->phase = 7;
    case 7:
        if (btlShuffleDrawViewIsCueIdle(shuffleContext->viewTask) == 0) {
            break;
        }
        btlShuffleDrawCardStartSelection(shuffleContext->cardTask);
        btlShuffleDrawViewStartFrameFade(shuffleContext->viewTask);
        deck = ((BtlShuffleContext *)work)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 2);
        btlShuffleDrawViewStartGlow(((BtlShuffleContext *)work)->viewTask);
        ((BtlShuffleContext *)work)->phase = 8;
    case 8:
        if (D_008C024E[0] & 0x40) {
            mask = btlShuffleRowMask(rowState->row);
            ((BtlShuffleRowState *)state)->flags &= (u16)~mask;
            sdkSndStartStream(1, 2, 5, 5);
            if (++rowState->row == 3) {
                btlShuffleDrawViewClearGlow(((BtlShuffleContext *)work)->viewTask);
                btlShuffleDrawCardEndDetail(((BtlShuffleContext *)work)->cardTask);
                ((BtlShuffleContext *)work)->phase = 9;
            } else if (((BtlShuffleRowState *)state)->row == 2) {
                btlShuffleSeq5Check(work);
            }
        }
        break;
    case 9:
        if (btlShuffleSeqPick(work, total) == 0) {
            break;
        }
        btlShuffleDrawViewEndPatternFade(shuffleContext->viewTask);
        btlShuffleDrawCardEndSelection(((BtlShuffleContext *)work)->cardTask);
        btlShuffleDrawViewEndFrameFade(((BtlShuffleContext *)work)->viewTask);
        if (btlShuffleSeq5Check2(work) != 0) {
            for (i = 0; i < total; i++) {
                if (!btlShuffleRowContains(state, i)) {
                    btlShuffleSeqSetMode(work, i, 0x14);
                }
            }
            ((BtlShuffleContext *)work)->phase = 10;
        } else {
            btlShuffleSeqCardCount(work, -1);
            ((BtlShuffleContext *)work)->phase = 14;
        }
        break;
    case 10:
        if (btlShuffleSeqPick(work, total) == 0) {
            break;
        }
        for (i = 0; i < total; i++) {
            if (!btlShuffleRowContains(state, i)) {
                btlShuffleDrawPoll(work, i, 0);
            }
        }
        ((BtlShuffleContext *)work)->phase = 11;
    case 11:
        if (btlShuffleSeqPick(work, total) == 0) {
            break;
        }
        for (i = 0; i < ((BtlShuffleRowState *)state)->cardCount; i++) {
            btlShuffleSeqUpdateMode(work, ((BtlShuffleRowState *)state)->cards[i], 0xA, 1);
        }
        ((BtlShuffleContext *)work)->phase = 12;
    case 12:
        if (btlShuffleSeqPick(work, total) == 0) {
            break;
        }
        for (j = 1; j < ((BtlShuffleRowState *)state)->cardCount; j++) {
            /* Clear the second pose flag on the remaining result cards. */
            shuffleContext->cards[((BtlShuffleRowState *)state)->cards[j]].flags &= 0xFFFD;
        }
        btlShuffleSeqMoveB(work, ((BtlShuffleRowState *)state)->cards[0]);
        ((BtlShuffleRowState *)state)->flags |= 0x80;
        sdkSndStartStream(1, 0, 5, 1);
        ((BtlShuffleContext *)work)->phase = 13;
    case 13:
        if (btlShuffleDrawStateA(work + rowState->cards[0] * 0xE8 + 0x1D6A0) != 0) {
            break;
        }
        btlShuffleSeqCardCount(work, ((BtlShuffleRowState *)state)->cards[0]);
        ((BtlShuffleContext *)work)->phase = 14;
    case 14:
        if (btlShuffleSeqDispatch(work) == 0) {
            break;
        }
        ((BtlShuffleContext *)work)->phase = 15;
    case 15:
        return 1;
    case 16:
        if (btlShuffleSeqStateCheck(work) != 0) {
            if (((BtlShuffleContext *)work)->unk1F248 != 0) {
                ((BtlShuffleContext *)work)->phase = 15;
            } else {
                ((BtlShuffleContext *)work)->phase = 3;
            }
        }
        break;
    case 17:
        if (btlShuffleSeqFlag(work) != 0) {
            if (MEMBER(u16, work, BtlShuffleContext, flags) & 2) {
                ((BtlShuffleContext *)work)->flags &= 0xFFFD;
            }
            if (++((BtlShuffleContext *)work)->elapsed >= 0x1E) {
                datSetFlag(0x1433, 1);
                ((BtlShuffleContext *)work)->phase = 6;
            }
        }
        break;
    default:
        kAssertFail(&D_0064EB40, 0x295);
        break;
    }
    for (k = 0; k < 3; k++) {
        mask = btlShuffleRowMask(k);
        if (((BtlShuffleRowState *)state)->flags & mask) {
            for (i = rowSize * k; i < rowSize * (k + 1); i++) {
                speed = shuffleContext->sequenceFrames;
                j = btlShuffleMovingRowSize(shuffleContext->cardCount);
                card = work + i * 0xE8;
                if (btlShuffleDrawStateA(card + 0x1D6A0) != 0) {
                    btlShuffleCalcUpdateSpeed(card + 0x1D6B8, (u8 *)movingScreen);
                    if (!(movingScreen[1] < 508.0f)) {
                        movingScreen[1] = (0.0f + movingScreen[1]) - 120.0f * (f32)j;
                    }
                    card = work + i * 0xFB0;
                    btlShuffleCardScaleVec(card, movingScreen, 84.0f, movingFrom);
                    movingScreen[1] += 120.0f;
                    btlShuffleCardScaleVec(card, movingScreen, 84.0f, movingTo);
                    btlShuffleDrawMoveCard(work, i, 0.0f, (f32)speed, movingFrom, movingTo);
                }
            }
        }
    }
    return 0;
}
#pragma pop

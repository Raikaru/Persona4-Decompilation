#include "include_asm.h"
/* Persona 4 USA decompilation - btlShuffleSeqShuffle4.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_shuffle_sequence_internal.h"

extern void kAssertFail(const void *file, u32 line);
extern u32 RpRandom();
extern s32 btlShuffleDrawTableLookup(s32 a, s32 b);
extern s32 btlShuffleCalcUpdateSpeed(u8 *a, f32 *b);
extern f32 RwV2dLength(f32 *a);
extern f32 func_003e41e0(f32 *a, f32 *b);
extern void btlShuffleDrawMoveCardB(u8 *ctx, s32 idx, f32 *a, f32 *b, f32 c, f32 d);
extern void btlShuffleDrawSetArc(u8 *ctx, s32 idx, u16 start, u16 end, f32 *from, f32 *rot, f32 *axis);
extern s32 btlShuffleSeq4Dist(u8 *a, s64 b, s64 c);
extern s32 btlShuffleSeqPick(u8 *a, s32 b);
extern s32 btlShuffleSeqLoadRecord(u8 *a);
extern s32 btlShuffleSeqStep(u8 *a);
extern void btlShuffleDrawCardActivate(u8 *a);
extern void btlShuffleDrawCardSetDetail(u8 *a, s32 b);
extern void btlShuffleDrawCardEndDetail(u8 *a);
extern void btlShuffleDrawSetPose(u8 *a, s32 b, u16 c, u16 d);
extern void btlShuffleSeqReset(u8 *a);
extern s32 btlShuffleSeqCountB(u8 *a, s32 b);
extern void btlShuffleCalcResetTrack(u8 *a);
extern s32 btlShuffleSeqCountA(u8 *a, s32 b);
extern void btlShuffleDrawMoveCard(u8 *a, s32 b, f32 e, f32 f, f32 *c, f32 *d);
extern void btlShuffleDrawSetQuat(u8 *a, s32 b, u16 c, u16 d, f32 *e, f32 *f);
extern void btlShuffleDrawSetFrames(u8 *a, s32 b, s32 c, s32 d, s32 e);
extern void btlShuffleDrawCardStartBands(u8 *a);
extern void btlShuffleCardScaleVec(u8 *a, f32 *b, f32 d, f32 *c);
extern void btlShuffleDrawClearFlags(u8 *a, s32 b);
extern s32 datGetFlag(s32 a);
extern void btlShuffleSeqClearA(u8 *a, s32 b);
extern void btlShuffleDrawViewStartCue(u8 *a);
extern s32 btlShuffleDrawViewIsCueIdle(u8 *a);
extern void btlShuffleDrawCardStartCount(u8 *a);
extern void btlShuffleDrawViewSetHold(u8 *a);
extern s32 btlShuffleDrawStateA(u8 *a);
extern s32 btlShuffleSeqCheck(u8 *a, s32 b, s32 c);
extern s32 btlShuffleCardGetKind(u8 *a);
extern void btlShuffleDrawCardEndCount(u8 *a);
extern void btlShuffleDrawViewClearHold(u8 *a);
extern s32 btlShuffleSeqCardCount(u8 *a, s32 b);
extern void btlShuffleSeqSetMode(u8 *a, s32 b, s32 c);
extern void btlShuffleDrawPoll(u8 *a, s32 b, s32 c);
extern void btlShuffleSeqUpdateMode(u8 *a, s32 b, u16 c, s32 d);
extern void btlShuffleSeqMoveB(u8 *a, s32 b);
extern s32 btlShuffleSeqDispatch(u8 *a);
extern s32 btlShuffleSeqStateCheck(u8 *a);
extern s32 btlShuffleSeqFlag(u8 *a);
extern void datSetFlag(s32 a, s32 b);
extern void btlShuffleSeq4Init(u8 *input);
extern void btlShuffleSeq4Step(u8 *input);
extern void btlShuffleSeq4Move(u8 *input, s32 value, u16 option, u16 extra);
extern void btlShuffleSeq4Shuffle(u8 *input);
extern void btlShuffleSeq4Layout(u8 *input, s32 value, f32 *option);

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
/* Choose the grid attempt limit and initial held-card count for this difficulty. */
// FUN_0037C720
void btlShuffleSeq4Init(u8 *context) {
    u8 *base;
    s32 idx;
    s32 minAttempts;
    s32 attemptSpan;
    s32 maxAttempts;
    f32 attemptFraction;
    f32 attemptValue;
    u16 attemptLimit;
    s32 minCards;
    s32 cardSpan;
    s32 maxCards;
    f32 cardFraction;
    f32 cardValue;
    s32 cardCount;
    s32 mode;

    base = context + 0x1F1D0;
    idx = ((BtlShuffleContext *)context)->cardCount;
    minAttempts = D_0064E6BA[idx * 2];
    maxAttempts = D_0064E6BB[idx * 2];
    attemptFraction = (f32)(u32)(RpRandom() & 0xFFF) / 4096.0f;
    attemptSpan = maxAttempts - minAttempts + 1;
    attemptValue = (f32)attemptSpan * attemptFraction + (f32)minAttempts;
    attemptLimit = (u16)attemptValue;
    /* measured: this retained grid/context access changes allocation or address operands when typed independently. */
    *(u16 *)(base + 0xA) = attemptLimit;
    if (((BtlShuffleGridState *)base)->attemptLimit > 0x10) {
        kAssertFail(&D_0064EB20[0], 0x32);
    }
    if (*(s32 *)(context + 0x1F300) == 3) {
        *(s16 *)&((BtlShuffleGridState *)base)->cardCount = 0;
    } else {
        minCards = D_0064E6CA[idx * 2];
        maxCards = D_0064E6CB[idx * 2];
        cardFraction = (f32)(u32)(RpRandom() & 0xFFF) / 4096.0f;
        cardSpan = maxCards - minCards + 1;
        cardValue = (f32)cardSpan * cardFraction + (f32)minCards;
        cardCount = (u16)cardValue;
        mode = ((BtlShuffleContext *)context)->difficulty;
        switch (mode) {
        case 0:
            *(s16 *)&((BtlShuffleGridState *)base)->frames = 10;
            break;
        case 1:
            *(s16 *)&((BtlShuffleGridState *)base)->frames = 8;
            break;
        case 2:
            *(s16 *)&((BtlShuffleGridState *)base)->frames = 5;
            break;
        default:
            kAssertFail(&D_0064EB20[0], 0x49);
            break;
        }
        if (cardCount <= 0) {
            cardCount = 1;
        }
        *(s16 *)&((BtlShuffleGridState *)base)->cardCount = cardCount;
    }
    if (*(u16 *)(base + 0x2C) > 0x10) {
        kAssertFail(&D_0064EB20[0], 0x4E);
    }
}

/* Screen position of slot `arg1` for the layout size n returned by func_00378530 (6, 8, 10, 12,
   14 or 16 slots), written to arg2.  measured against retail:
   - retail builds the position in a two-float stack local (0x48($sp)) and copies it to arg2 at
     the join; a struct local plus a struct copy-out reproduces the 0x50 frame (a plain f32[2] is
     promoted to FPRs, and writing arg2 directly leaves a 0x40 frame);
   - in the arms that convert arg1 directly retail loads 80.0f before the int-to-float
     conversion.  Under opt_propagation off a named `step` local is loaded where it is written,
     which reproduces that order; the arms that convert `arg1 - k` keep the inline constant;
   - opt_propagation off would otherwise share the `arg0 + 0x1F2FC` address between its two uses
     (retail rebuilds it with lui/addu each time); spelling the second use as a word index off
     0x1F2F8 keeps them separate. */
typedef struct ShuffleSlotPos { f32 x; f32 y; } ShuffleSlotPos;

// FUN_0037CA60
#pragma push
#pragma opt_propagation off
void btlShuffleSeq4Layout(u8 *context, s32 slotIndex, f32 *screen) {
    ShuffleSlotPos pos;
    s32 n;
    if (((BtlShuffleContext *)context)->pattern != 3) {
        kAssertFail(&D_0064EB20[0], 0x5B);
    }
    n = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount, ((s32 *)(context + 0x1F2F8))[1]);
    switch (n) {
    case 6:
        pos.x = 320.0f + 80.0f * ((f32)(slotIndex % 3) - 1.0f);
        pos.y = 224.0f + 100.0f * ((f32)(slotIndex / 3) - 0.5f);
        break;
    case 8:
        if (slotIndex < 4) {
            f32 step = 80.0f;
            pos.x = 320.0f + step * ((f32)slotIndex - 1.5f);
            pos.y = 174.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 4) - 1.5f);
            pos.y = 274.0f;
        }
        break;
    case 10:
        if (slotIndex < 3) {
            f32 step = 80.0f;
            pos.x = 320.0f + step * ((f32)slotIndex - 1.0f);
            pos.y = 74.0f;
        } else if (slotIndex < 5) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 3) - 0.5f);
            pos.y = 174.0f;
        } else if (slotIndex < 7) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 5) - 0.5f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 7) - 1.0f);
            pos.y = 374.0f;
        }
        break;
    case 12:
        if (slotIndex < 3) {
            f32 step = 80.0f;
            pos.x = 320.0f + step * ((f32)slotIndex - 1.0f);
            pos.y = 74.0f;
        } else if (slotIndex < 6) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 3) - 1.0f);
            pos.y = 174.0f;
        } else if (slotIndex < 9) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 6) - 1.0f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 9) - 1.0f);
            pos.y = 374.0f;
        }
        break;
    case 14:
        if (slotIndex < 4) {
            f32 step = 80.0f;
            pos.x = 320.0f + step * ((f32)slotIndex - 1.5f);
            pos.y = 74.0f;
        } else if (slotIndex < 7) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 4) - 1.0f);
            pos.y = 174.0f;
        } else if (slotIndex < 11) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 7) - 1.5f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 11) - 1.0f);
            pos.y = 374.0f;
        }
        break;
    case 16:
        if (slotIndex < 4) {
            f32 step = 80.0f;
            pos.x = 320.0f + step * ((f32)slotIndex - 1.5f);
            pos.y = 74.0f;
        } else if (slotIndex < 8) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 4) - 1.5f);
            pos.y = 174.0f;
        } else if (slotIndex < 12) {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 8) - 1.5f);
            pos.y = 274.0f;
        } else {
            pos.x = 320.0f + 80.0f * ((f32)(slotIndex - 12) - 1.5f);
            pos.y = 374.0f;
        }
        break;
    default:
        kAssertFail(&D_0064EB20[0], 0x116);
        break;
    }
    *(ShuffleSlotPos *)screen = pos;
}
#pragma pop
/* Find the nearest card along the input direction, falling back to the farthest opposite card. */
// FUN_0037D270
s32 btlShuffleSeq4Dist(u8 *context, s64 packedDirection, s64 packedOrigin) {
    f32 delta[2];
    f32 screen[2];
    s64 origin;
    s64 direction;
    f32 nearestDistance;
    f32 farthestDistance;
    f32 originX;
    f32 originY;
    f32 dist;
    f32 dot;
    u16 cursor;
    s32 n;
    s32 i;
    s32 currentCard;
    s32 nearestCard;
    s32 farthestCard;

    direction = packedDirection;
    origin = packedOrigin;
    originY = ((BtlShuffleScreenPoint *)&origin)->point.y;
    originX = *(f32 *)&origin;
    func_003e41e0((f32 *)&direction, (f32 *)&direction);
    cursor = ((BtlShuffleContext *)context)->sequenceChoice;
    n = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount, ((BtlShuffleContext *)context)->pattern);
    nearestDistance = 1088.0f;
    currentCard = cursor & 0xFFFF;
    nearestCard = currentCard;
    farthestDistance = 0.0f;
    farthestCard = currentCard;
    i = 0;
    for (; i < n; i++) {
        if (i == currentCard) {
            continue;
        }
        btlShuffleCalcUpdateSpeed(context + i * 0xE8 + 0x1D6B8, screen);
        delta[0] = screen[0] - originX;
        delta[1] = screen[1] - originY;
        dist = RwV2dLength(delta);
        func_003e41e0(delta, delta);
        dot = *(f32 *)&direction * delta[0] + ((BtlShuffleScreenPoint *)&direction)->point.y * delta[1];
        if (dot > iGpffff83f0) {
            if (dist < nearestDistance) {
                nearestDistance = dist;
                nearestCard = i & 0xFFFF;
            }
        } else if (-dot > iGpffff83f4 && dist > farthestDistance) {
            farthestDistance = dist;
            farthestCard = i & 0xFFFF;
        }
    }
    if ((nearestCard & 0xFFFF) == currentCard) {
        nearestCard = farthestCard & 0xFFFF;
    }
    return nearestCard;
}

/* Read directional input and move the grid cursor to a neighboring card. */
// FUN_0037D460
void btlShuffleSeq4Step(u8 *context) {
    u8 *base = context + 0x1F1D0;
    f32 direction[2];
    s64 position;
    u8 *clearCursor;
    s32 bytesRemaining;
    u16 cur;
    u16 ret;

    clearCursor = (u8 *)direction;
    bytesRemaining = 8;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            bytesRemaining -= 1;
        } while (bytesRemaining != 0);
    }
    if (((BtlShuffleContext *)context)->pattern != 3) {
        kAssertFail(&D_0064EB20[0], 0x1A6);
    }
    /* measured: this retained grid/context access changes allocation or address operands when typed independently. */
    cur = *(u16 *)(base + 4);
    btlShuffleCalcUpdateSpeed(context + cur * 0xE8 + 0x1D6B8, (f32 *)&position);
    if (D_008C027A[0] & 0x1000) {
        direction[1] -= 1.0f;
    }
    if (D_008C027A[0] & 0x4000) {
        direction[1] += 1.0f;
    }
    if (D_008C027A[0] & 0x8000) {
        direction[0] -= 1.0f;
    }
    if (D_008C027A[0] & 0x2000) {
        direction[0] += 1.0f;
    }
    if (RwV2dLength(direction) != 0.0f) {
        ret = (u16)(btlShuffleSeq4Dist(context, *(s64 *)direction, position) & 0xFFFF);
        if (ret != (cur & 0xFFFF)) {
            ((BtlShuffleGridState *)base)->cursor = ret;
            sdkSndStartStream(0, 4, 0, 0);
        }
    }
}

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

/* Move and turn a card, recording it in one of the two held-card slots. */
// FUN_0037D630
void btlShuffleSeq4Move(u8 *context, s32 cardIndex, u16 startFrame, u16 endFrame) {
    u8 *base = context + 0x1F1D0;
    s32 off;
    u8 *p;
    f32 position[3];
    f32 rot[4];
    f32 axis[4];
    f32 startTime;
    f32 endTime;

    off = cardIndex * 0xE8;
    p = (u8 *)(off + (s32)context);
    /* Track kind five selects an alternate position in the pose prefix; the complete variant union is not yet known. */
    if (*(s32 *)(p + 0x1D6A4) == 5) {
        *(Vec3f *)position = *(Vec3f *)(p + 0x1D6C4);
    } else {
        *(Vec3f *)position = *(Vec3f *)(p + 0x1D6B8);
    }
    startTime = startFrame;
    endTime = endFrame;
    btlShuffleDrawMoveCardB(context, cardIndex, 0, position, startTime, endTime);
    axis[3] = iGpffff83e8;
    axis[0] = 0.0f;
    axis[1] = iGpffff83ec;
    axis[2] = 0.0f;
    rot[3] = 0.0f;
    rot[0] = 0.0f;
    rot[1] = 1.0f;
    rot[2] = 0.0f;
    btlShuffleDrawSetArc(context, cardIndex, startFrame, endFrame, NULL, rot, axis);
    ((BtlShuffleGridState *)base)->heldMask |= (1 << cardIndex) & 0xFFFF;
    if (!(((BtlShuffleGridState *)base)->flags & 2)) {
        ((BtlShuffleGridState *)base)->firstCard = cardIndex;
        ((BtlShuffleGridState *)base)->flags |= 2;
        return;
    }
    ((BtlShuffleGridState *)base)->secondCard = cardIndex;
    ((BtlShuffleGridState *)base)->flags |= 4;
}



// measured: plain C reproduces the shuffle loop and frame; only the commutative multiply operand order differs at two instructions (normalized_diff 2), with object 540B versus retail window 544B. Parked because nd <= 25.
// Committed at nd 2.
// measured: explicit `(f32)` cast on the right multiply operand preserves retail's mul.s operand order; object 540B, retail window 544B, normalized_diff 0.
// Verified live MATCH.
/* Shuffle complete card records with a descending Fisher-Yates pass. */
// FUN_0037D840
void btlShuffleSeq4Shuffle(u8 *context) {
    u8 buf[0xFB0];
    u8 *firstCursor;
    u8 *secondCursor;
    u8 *copyCursor;
    s32 pairsRemaining;
    s32 n;
    s32 lastIndex;
    s32 randomIndex;
    s32 randomBits;
    s32 t1;
    s32 t2;
    f32 randomValue;
    f32 randomFraction;

    /* measured: this retained grid/context access changes allocation or address operands when typed independently. */
    if (*(s32 *)(context + 0x1F2FC) != 3) {
        kAssertFail(&D_0064EB20[0], 0x23B);
    }
    n = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount, ((BtlShuffleContext *)context)->pattern);
    lastIndex = n - 1;
    while (lastIndex > 0) {
        randomBits = RpRandom() & 0xFFF;
        randomValue = (f32)(u32)randomBits;
        randomFraction = randomValue / 4096.0f;
        randomFraction = (f32)(lastIndex + 1) * (f32)randomFraction;
        randomIndex = (s32)randomFraction;
        if ((lastIndex < 0) || (lastIndex >= n)) {
            kAssertFail(&D_0064EB20[0], 0x243);
        }
        if ((randomIndex < 0) || (randomIndex >= n)) {
            kAssertFail(&D_0064EB20[0], 0x244);
        }
        firstCursor = context + lastIndex * 0xFB0;
        copyCursor = buf;
        pairsRemaining = 0x1F6;
        secondCursor = firstCursor;
        do {
            t1 = ((BtlShuffleCopyPair *)secondCursor)->first;
            t2 = ((BtlShuffleCopyPair *)secondCursor)->second;
            secondCursor += 8;
            pairsRemaining -= 1;
            ((BtlShuffleCopyPair *)copyCursor)->first = t1;
            ((BtlShuffleCopyPair *)copyCursor)->second = t2;
            copyCursor += 8;
        } while (pairsRemaining > 0);
        secondCursor = context + randomIndex * 0xFB0;
        pairsRemaining = 0x1F6;
        copyCursor = secondCursor;
        do {
            t1 = ((BtlShuffleCopyPair *)copyCursor)->first;
            t2 = ((BtlShuffleCopyPair *)copyCursor)->second;
            copyCursor += 8;
            pairsRemaining -= 1;
            ((BtlShuffleCopyPair *)firstCursor)->first = t1;
            ((BtlShuffleCopyPair *)firstCursor)->second = t2;
            firstCursor += 8;
        } while (pairsRemaining > 0);
        copyCursor = buf;
        pairsRemaining = 0x1F6;
        do {
            t1 = ((BtlShuffleCopyPair *)copyCursor)->first;
            t2 = ((BtlShuffleCopyPair *)copyCursor)->second;
            copyCursor += 8;
            pairsRemaining -= 1;
            ((BtlShuffleCopyPair *)secondCursor)->first = t1;
            ((BtlShuffleCopyPair *)secondCursor)->second = t2;
            secondCursor += 8;
        } while (pairsRemaining > 0);
        lastIndex -= 1;
    }
}

/* Deal state machine for the fourth shuffle layout, the twin of the three in
   code1_0037.c.  Releasing a held card and drawing a free card are inline
   helpers that retail expands in place.  The frame arguments of the card
   animation setters are u16 throughout, so the (u16) conversions happen at
   each call.  measured: 4904B of code in the 4912B window (two zero words). */
static inline void shuffle4Release(u8 *context, s32 card, u16 frames)
{
    u8 *base = context + 0x1F1D0;
    f32 rot[4];
    f32 axis[4];

    btlShuffleDrawClearFlags(context, card);
    axis[3] = iGpffff83ec;
    axis[0] = 0.0f;
    axis[1] = iGpffff83ec;
    axis[2] = 0.0f;
    rot[3] = 1.0f;
    rot[0] = 0.0f;
    rot[1] = 0.0f;
    rot[2] = 0.0f;
    btlShuffleDrawSetArc(context, card, 0, frames, NULL, rot, axis);
    ((BtlShuffleGridState *)base)->heldMask &= ~(1 << card);
    if (((BtlShuffleGridState *)base)->flags & 4) {
        ((BtlShuffleGridState *)base)->secondCard = -1;
        ((BtlShuffleGridState *)base)->flags &= 0xFFFB;
    } else {
        ((BtlShuffleGridState *)base)->firstCard = -1;
        ((BtlShuffleGridState *)base)->flags &= 0xFFFD;
    }
}

static inline u16 shuffle4PickFree(u8 *context)
{
    u8 *base = context + 0x1F1D0;
    s32 n;
    u16 c;

    /* measured: this retained grid/context access changes allocation or address operands when typed independently. */
    n = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount, *(s32 *)(context + 0x1F2FC));
    do {
        c = n * ((f32)(RpRandom() & 0xFFF) / 4096.0f);
    } while (((BtlShuffleGridState *)base)->heldMask & (u16)(1 << c));
    return c;
}

/* measured: without loop-invariant hoisting the pick loop keeps its work base
   in the loop body (674 differing words). */
#pragma opt_loop_invariants on
/* Run the grid reveal, two-card matching and result sequence. */
// FUN_0037DA60
s32 btlShuffleSeq4Run(u8 *context)
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

    /* measured: this retained grid/context access changes allocation or address operands when typed independently. */
    scale = 1.0f - (0.5f * (f32)(*(s32 *)(context + 0x1F304) - 3)) / 5.0f;
    sbase = context + 0x1F1D0;
    total = btlShuffleDrawTableLookup(*(s32 *)(context + 0x1F304), ((BtlShuffleContext *)context)->pattern);
    /* measured: typing only this dispatch read shrinks Run to 4684 bytes and changes its allocation; stores remain typed. */
    switch (*(u32 *)(context + 0x1F2F8)) {
    case 0:
        if (btlShuffleSeqPick(context, ((BtlShuffleContext *)context)->cardCount) == 0) {
            break;
        }
        btlShuffleSeq4Init(context);
        if (btlShuffleSeqLoadRecord(context) != 0) {
            ((BtlShuffleContext *)context)->phase = 1;
        } else {
            ((BtlShuffleContext *)context)->phase = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(context) == 0) {
            break;
        }
        ((BtlShuffleContext *)context)->phase = 2;
    case 2:
        if (++((BtlShuffleContext *)context)->elapsed < 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 1);
        ((BtlShuffleContext *)context)->phase = 3;
        break;
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            btlShuffleDrawCardEndDetail(((BtlShuffleContext *)context)->cardTask);
            ((BtlShuffleContext *)context)->elapsed = 0;
            ((BtlShuffleContext *)context)->phase = 4;
            ((BtlShuffleGridState *)sbase)->attempts = 0;
            for (i = 0; i < ((BtlShuffleContext *)context)->cardCount; i++) {
                btlShuffleDrawSetPose(context, i, (u16)i, (u16)i + 10);
                /* The flag halfword belongs to the variant motion/grid prefix, not a field of the shared partial pose type. */
                *(u16 *)(context + 0x1F1D6) ^= (u16)(1 << i);
            }
            sdkSndStartStream(0, 4, 0, 1);
            sdkSndStartStream(1, 0, 5, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(context);
            ((BtlShuffleContext *)context)->phase = 0x14;
        }
        break;
    case 4:
        if (btlShuffleSeqCountB(context, *(s32 *)(context + 0x1F304)) == 0) {
            break;
        }
        ((BtlShuffleContext *)context)->elapsed = 0;
        ((BtlShuffleContext *)context)->phase = 6;
        ((BtlShuffleGridState *)sbase)->attempts = 0;
        ((BtlShuffleGridState *)sbase)->heldMask = 0;
        btlShuffleCalcResetTrack((u8 *)vec);
        for (i = 0; i < ((BtlShuffleContext *)context)->cardCount; i++) {
            btlShuffleDrawMoveCardB(context, i, NULL, vec, (u16)i, (u16)(i + 10));
        }
        sdkSndStartStream(1, 0, 5, 2);
    case 6:
        if (btlShuffleSeqCountA(context, ((BtlShuffleContext *)context)->cardCount) == 0) {
            break;
        }
        btlShuffleCalcResetTrack((u8 *)vec);
        rot[3] = 1.0f;
        rot[0] = 0.0f;
        rot[1] = 0.0f;
        rot[2] = 0.0f;
        for (i = 0; i < total; i++) {
            btlShuffleDrawMoveCard(context, i, 0.0f, 0.0f, vec, vec);
            btlShuffleDrawSetQuat(context, i, 0, 0, rot, rot);
            btlShuffleDrawSetFrames(context, i, 0, 0xFF, 0xFF);
        }
        btlShuffleDrawCardStartBands(((BtlShuffleContext *)context)->cardTask);
        ((BtlShuffleContext *)context)->flags |= 1;
        ((BtlShuffleContext *)context)->elapsed = 0;
        ((BtlShuffleContext *)context)->phase = 5;
        for (i = 0; i < total; i++) {
            btlShuffleSeq4Layout(context, i, pos);
            btlShuffleCardScaleVec(context + i * 0xFB0, pos, 67.0f, vec);
            t = scale * i;
            btlShuffleDrawMoveCardB(context, i, NULL, vec, (u16)t, (u16)(5.0f + t));
            btlShuffleDrawClearFlags(context, i);
        }
        sdkSndStartStream(1, 0, 5, 2);
    case 5:
        if (btlShuffleSeqCountA(context, total) == 0) {
            break;
        }
        if (datGetFlag(0x1432) == 0) {
            btlShuffleSeqClearA(context, 2);
            ((BtlShuffleContext *)context)->phase = 0x15;
            ((BtlShuffleContext *)context)->elapsed = 0;
            ((BtlShuffleContext *)context)->flags |= 2;
            break;
        }
        btlShuffleSeq4Shuffle(context);
        if (((BtlShuffleGridState *)sbase)->cardCount > 0) {
            for (k = 0; k < *(u16 *)(sbase + 0x2C); k++) {
                ((BtlShuffleGridState *)sbase)->cards[k] = shuffle4PickFree(context);
                btlShuffleSeq4Move(context, ((BtlShuffleGridState *)sbase)->cards[k], 0, ((BtlShuffleGridState *)sbase)->frames);
            }
            sdkSndStartStream(1, 0, 5, 1);
            ((BtlShuffleContext *)context)->elapsed = 0;
            ((BtlShuffleContext *)context)->phase = 7;
        } else {
            ((BtlShuffleContext *)context)->phase = 9;
        }
        break;
    case 7:
        if (btlShuffleSeqCountB(context, total) == 0) {
            break;
        }
        switch (((BtlShuffleContext *)context)->difficulty) {
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
            kAssertFail(&D_0064EB20[0], 0x26C);
            limit = 0;
            break;
        }
        if (++*(u16 *)(context + 0x1F2F0) < limit) {
            break;
        }
        for (j = 0; j < *(u16 *)(sbase + 0x2C); j++) {
            speed = ((BtlShuffleGridState *)sbase)->frames;
            card = ((BtlShuffleGridState *)sbase)->cards[j];
            shuffle4Release(context, card, speed);
        }
        sdkSndStartStream(1, 0, 5, 1);
        ((BtlShuffleContext *)context)->phase = 8;
        ((BtlShuffleContext *)context)->elapsed = 0;
    case 8:
        if (btlShuffleSeqCountB(context, total) == 0) {
            break;
        }
        ((BtlShuffleContext *)context)->phase = 9;
    case 9:
        ((BtlShuffleGridState *)sbase)->attempts = 0;
        btlShuffleDrawViewStartCue(((BtlShuffleContext *)context)->viewTask);
        ((BtlShuffleContext *)context)->phase = 0xA;
    case 10:
        if (btlShuffleDrawViewIsCueIdle(*(u8 **)(context + 0x1F294)) == 0) {
            break;
        }
        btlShuffleDrawCardStartCount(*(u8 **)(context + 0x1F298));
        btlShuffleDrawViewSetHold(((BtlShuffleContext *)context)->viewTask);
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 3);
        ((BtlShuffleContext *)context)->phase = 0xB;
    case 11:
        if ((D_008C024E[0] & 0x40) != 0) {
            if (((BtlShuffleGridState *)sbase)->heldMask & (u16)(1 << ((BtlShuffleGridState *)sbase)->cursor)) {
                break;
            }
            btlShuffleSeq4Move(context, ((BtlShuffleGridState *)sbase)->cursor, 0, 0xA);
            ((BtlShuffleContext *)context)->phase = 0xC;
            sdkSndStartStream(1, 0, 5, 1);
        } else {
            btlShuffleSeq4Step(context);
        }
        break;
    case 12:
        if (btlShuffleDrawStateA(context + ((BtlShuffleGridState *)sbase)->cursor * 0xE8 + 0x1D6A0) == 0) {
            break;
        }
        if ((((BtlShuffleGridState *)sbase)->flags & 2) && (((BtlShuffleGridState *)sbase)->flags & 4)) {
            ((BtlShuffleContext *)context)->phase = 0xD;
            ((BtlShuffleContext *)context)->elapsed = 0;
        } else {
            ((BtlShuffleContext *)context)->phase = 0xB;
        }
        break;
    case 13:
        if (btlShuffleSeqCheck(context, *(s32 *)(sbase + 0x30), *(s32 *)(sbase + 0x34)) != 0 &&
            btlShuffleCardGetKind(context + ((BtlShuffleGridState *)sbase)->firstCard * 0xFB0) != 2) {
            btlShuffleDrawCardEndDetail(*(u8 **)(context + 0x1F298));
            btlShuffleDrawCardEndCount(((BtlShuffleContext *)context)->cardTask);
            btlShuffleDrawViewClearHold(((BtlShuffleContext *)context)->viewTask);
            ((BtlShuffleContext *)context)->phase = 0xE;
            break;
        }
        if (++((BtlShuffleContext *)context)->elapsed < 0xA) {
            break;
        }
        shuffle4Release(context, ((BtlShuffleGridState *)sbase)->secondCard, 0xA);
        shuffle4Release(context, ((BtlShuffleGridState *)sbase)->firstCard, 0xA);
        sdkSndStartStream(1, 0, 5, 1);
        if (++((BtlShuffleGridState *)sbase)->attempts >= ((BtlShuffleGridState *)sbase)->attemptLimit) {
            btlShuffleDrawCardEndDetail(*(u8 **)(context + 0x1F298));
            btlShuffleDrawCardEndCount(((BtlShuffleContext *)context)->cardTask);
            btlShuffleDrawViewClearHold(((BtlShuffleContext *)context)->viewTask);
            btlShuffleSeqCardCount(context, -1);
            ((BtlShuffleContext *)context)->phase = 0x12;
        } else {
            ((BtlShuffleContext *)context)->phase = 0xB;
        }
        break;
    case 14:
        for (i = 0; i < total; i++) {
            if (i != ((BtlShuffleGridState *)sbase)->firstCard && i != ((BtlShuffleGridState *)sbase)->secondCard) {
                btlShuffleSeqSetMode(context, i, 0x14);
            }
        }
        ((BtlShuffleContext *)context)->phase = 0xF;
    case 15:
        if (btlShuffleSeqPick(context, total) == 0) {
            break;
        }
        for (i = 0; i < total; i++) {
            if (i != ((BtlShuffleGridState *)sbase)->firstCard && i != ((BtlShuffleGridState *)sbase)->secondCard) {
                btlShuffleDrawPoll(context, i, 0);
            }
        }
        btlShuffleSeqUpdateMode(context, ((BtlShuffleGridState *)sbase)->firstCard, 0xA, 1);
        btlShuffleSeqUpdateMode(context, ((BtlShuffleGridState *)sbase)->secondCard, 0xA, -1);
        ((BtlShuffleContext *)context)->phase = 0x10;
    case 16:
        if (btlShuffleSeqPick(context, total) == 0) {
            break;
        }
        *(u16 *)((u8 *)(((BtlShuffleGridState *)sbase)->secondCard * 0xE8) + (u32)context + 0x1D6A0) &= 0xFFFD;
        btlShuffleSeqMoveB(context, ((BtlShuffleGridState *)sbase)->firstCard);
        ((BtlShuffleGridState *)sbase)->flags |= 8;
        sdkSndStartStream(1, 0, 5, 1);
        ((BtlShuffleContext *)context)->phase = 0x11;
    case 17:
        if (btlShuffleDrawStateA(context + *(s32 *)(sbase + 0x30) * 0xE8 + 0x1D6A0) != 0) {
            break;
        }
        btlShuffleSeqCardCount(context, ((BtlShuffleGridState *)sbase)->firstCard);
        ((BtlShuffleContext *)context)->phase = 0x12;
    case 18:
        if (btlShuffleSeqDispatch(context) == 0) {
            break;
        }
        ((BtlShuffleContext *)context)->phase = 0x13;
    case 19:
        return 1;
    case 20:
        if (btlShuffleSeqStateCheck(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->unk1F248 != 0) {
            ((BtlShuffleContext *)context)->phase = 0x13;
        } else {
            ((BtlShuffleContext *)context)->phase = 3;
        }
        break;
    case 21:
        if (btlShuffleSeqFlag(context) == 0) {
            break;
        }
        if (*(u16 *)(context + 0x1F2F4) & 2) {
            *(u16 *)(context + 0x1F2F4) = ((BtlShuffleContext *)context)->flags & 0xFFFD;
        }
        if (++((BtlShuffleContext *)context)->elapsed < 0x1E) {
            break;
        }
        datSetFlag(0x1432, 1);
        ((BtlShuffleContext *)context)->phase = 5;
        break;
    default:
        kAssertFail(&D_0064EB20[0], 0x3F6);
        break;
    }
    return 0;
}
#pragma opt_loop_invariants off

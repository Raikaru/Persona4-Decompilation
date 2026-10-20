/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00379e90-0037bc80 */

#include "include_asm.h"
#include "type.h"
#include "btl_shuffle_state_internal.h"
extern void btlShuffleCalcResetPose(u8 *output);
extern void btlShuffleDrawInitCard(u8 *context, s32 cardIndex, s32 output, f32 *endFrame, f32 *controlPoints, f32 *origin,
                           f32 angle, f32 endAngle);
extern f32 cosf(f32 angle);
extern f32 sinf(f32 angle);
extern f32 fGpffff80d8;
extern f32 fGpffff83e4;
extern f32 fGpffff837c;
extern void btlShuffleDrawSetTiming(u8 *context, s32 cardIndex, s32 delay, s32 duration, f32 *start);
static inline f32 btlShuffleAddPoseDepth(f32 a, f32 b) {
    return a + b;
}

static inline u8 *btlShuffleAddCardOffset(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}

void btlShuffleCalcRotatePointAroundAxis(u8 *center, u8 *axis, u8 *point, f32 angle, u8 *output);

#pragma push
#pragma opt_propagation off
/* Build the single-axis card pose, or return its transformed origin. */
// FUN_00379E90
void btlShuffleInitSingleAxisPose(u8 *context, s32 cardIndex, f32 *output) {
    struct {
        f32 axisX;
        f32 axisY;
        f32 axisZ;
        f32 pad4c;
        f32 eyeX;
        f32 eyeY;
        f32 eyeZ;
        f32 pad5c;
        f32 originX;
        f32 originY;
        f32 originZ;
    } work;
    f32 originZ;

    btlShuffleCalcResetPose((u8 *)&work.originX);
    work.originY = work.originY - 25.0f;
    work.eyeX = work.originX;
    work.eyeY = work.originY;
    originZ = work.originZ;
    work.eyeZ = btlShuffleAddPoseDepth(originZ, 200.0f);
    work.axisX = 0.0f;
    work.axisY = cosf(fGpffff80d8);
    work.axisZ = -sinf(fGpffff80d8);
    if (output != NULL) {
        btlShuffleCalcRotatePointAroundAxis((u8 *)&work.eyeX, (u8 *)&work.axisX, (u8 *)&work.originX, 0.0f, (u8 *)output);
        return;
    }
    btlShuffleDrawInitCard(context, cardIndex, 0, &work.axisX, &work.eyeX, &work.originX, 0.0f, 0.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_dead_assignments off
#pragma opt_loop_invariants on
/* Run the single-axis shuffle sequence; return one only after the terminal phase. */
/* measured: dedicated typed aliases preserve the retail reload schedule where access-site-only typing does not. */
// FUN_00379F90
s32 btlShuffleSeq1Run(u8 *context) {
    BtlShuffleContext *contextFields = (BtlShuffleContext *)(context);
    BtlShuffleSequence *sequenceFields;
    BtlShuffleSequence *timingFields;
    extern s32 btlShuffleSeqPick(u8 *context, s32 count);
    extern s32 btlShuffleSeqLoadRecord(u8 *context);
    extern s32 btlShuffleSeqStep(u8 *context);
    extern void btlShuffleDrawCardActivate(u8 *drawWork);
    extern void btlShuffleDrawCardSetDetail(u8 *drawWork, s32 input);
    extern void btlShuffleDrawCardEndDetail(u8 *drawWork);
    extern s32 btlShuffleDrawStateB(u8 *record);
    extern s32 btlShuffleDrawStateA(u8 *record);
    extern void btlShuffleDrawSetPose(u8 *context, s32 cardIndex, u16 delay, u16 duration);
    extern void btlShuffleDrawPoll(u8 *context, s32 cardIndex, s32 enabled);
    extern void btlShuffleDrawSetFrames(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start);
    extern s32 btlShuffleDrawCheck(u8 *context, u8 *output);
    extern void btlShuffleDrawViewClearHold(u8 *drawWork);
    extern void btlShuffleDrawViewStartCue(u8 *drawWork);
    extern s32 btlShuffleDrawViewIsCueIdle(u8 *drawWork);
    extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);
    extern void kAssertFail(const void *file, u32 line);
    extern char D_0064EAC0[];
    extern u16 D_008C024E[];
    extern s32 datGetFlag(s32 bit);
    extern void datSetFlag(s32 flagId, s32 enabled);
    extern u16 btlShuffleSeqRoll(void);
    extern s32 btlShuffleSeqRecord(u8 *context, s32 cardIndex, s32 frames);
    extern void btlShuffleSeqMoveA(u8 *context, s32 cardIndex);
    extern void btlShuffleSeqClearA(u8 *context, s32 count);
    extern s32 btlShuffleSeqFlag(u8 *context);
    extern void btlShuffleSeqReset(u8 *context);
    extern s32 btlShuffleSeqStateCheck(u8 *context);
    extern s32 btlShuffleSeqCardCount(u8 *context, s32 cardIndex);
    extern s32 btlShuffleSeqDispatch(u8 *context);
    struct {
        BtlShufflePoseVector base;
        BtlShufflePoseVector first;
        BtlShufflePoseVector second;
        BtlShufflePoseVector output;
    } work;
    BtlShufflePoseVector v2;
    BtlShufflePoseVector v1;
    BtlShufflePoseVector v0;
    f32 factor;
    f32 base;
    u8 *sequence;
    u8 *timing;
    u8 *deck;
    s32 frameSpacing;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 j;
    s32 offset;
    f32 thirdX;
    s32 k;
    s32 activatedCount;
    s32 m;
    sequence = context + 0x1F1D0;
    sequenceFields = (BtlShuffleSequence *)(sequence);
    frameSpacing = (u16)(((BtlShuffleSequence *)sequence)->frames / ((BtlShuffleContext *)context)->cardCount);
    switch (((BtlShuffleContext *)context)->phase) {
    case 0:
        if (((BtlShuffleContext *)context)->unk1F30C != 0) {
            ((BtlShuffleContext *)context)->elapsed = contextFields->elapsed + 1;
            if (btlShuffleSeqPick(context, contextFields->cardCount) == 0) {
                break;
            }
        }
        timing = context + 0x1F1D0;
    timingFields = (BtlShuffleSequence *)(timing);
        switch (((BtlShuffleContext *)context)->difficulty) {
        case 0:
            ((BtlShuffleSequence *)timing)->frames = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            ((BtlShuffleSequence *)timing)->frames = 0x14;
            factor = 0.7f;
            break;
        case 2:
            ((BtlShuffleSequence *)timing)->frames = 0x10;
            factor = 0.8f;
            break;
        default:
            kAssertFail(D_0064EAC0, 0x38);
            break;
        }
        ((BtlShuffleSequence *)timing)->frames = timingFields->frames * (1.0f + factor * (contextFields->cardCount - 3) / 5.0f);
        ((BtlShuffleContext *)context)->elapsed = 0;
        ((BtlShuffleSequence *)sequence)->selectedCard = -1;
        if (btlShuffleSeqLoadRecord(context) != 0) {
            contextFields->phase = 1;
        } else {
            contextFields->phase = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(context) == 0) {
            break;
        }
        contextFields->phase = 2;
    case 2: {
        if (++((BtlShuffleContext *)context)->elapsed < 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 1);
        contextFields->phase = 3;
        break;
    }
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            deck = ((BtlShuffleContext *)context)->cardTask;
            btlShuffleDrawCardEndDetail(deck);
            ((BtlShuffleContext *)context)->elapsed = 0;
            contextFields->phase = 4;
            ((BtlShuffleSequence *)sequence)->count = 0;
            for (i = 0; i < contextFields->cardCount; i++) {
                work.base = ((BtlShuffleContext *)context)->cards[i].position;
                btlShuffleInitSingleAxisPose(context, 0, &work.output.x);
                dx = work.output.x - work.base.x;
                thirdX = work.base.x + dx / 3.0f;
                work.first.x = 150.0f + thirdX;
                dy = work.output.y - work.base.y;
                work.first.y = work.base.y + dy / 3.0f;
                dz = work.output.z - work.base.z;
                work.first.z = work.base.z - dz;
                work.second.x = work.base.x + (2.0f * dx) / 3.0f + 150.0f;
                work.second.y = work.base.y + (2.0f * dy) / 3.0f;
                work.second.z = work.base.z + dz;
                m = (u16)frameSpacing * i;
                btlShuffleDrawSetTiming(context, i, (u16)m, (u16)(m + 0x14), &work.base.x);
            }
            sdkSndStartStream(0, 4, 0, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(context);
            contextFields->phase = 0xE;
        }
        break;
    case 4:
        base = 0.0f;
        for (k = 0; k < contextFields->cardCount; k++) {
            if (btlShuffleDrawStateB(context + k * 0xE8 + 0x1D6A0) != 0) {
                btlShuffleDrawSetPose(context, k, 0, 0xA);
                activatedCount = ((BtlShuffleSequence *)sequence)->count;
                offset = ((u16)frameSpacing * (contextFields->cardCount - activatedCount)) & 0xFFFF;
                if (activatedCount >= contextFields->cardCount) {
                    kAssertFail(D_0064EAC0, 0x5F);
                }
                btlShuffleInitSingleAxisPose(context, k, (f32 *)0);
                v2 = ((BtlShuffleContext *)context)->cards[k].axis;
                v1 = ((BtlShuffleContext *)context)->cards[k].eye;
                v0 = ((BtlShuffleContext *)context)->cards[k].origin;
                btlShuffleDrawInitCard(context, k, offset, &v2.x, &v1.x, &v0.x, base, base + (360.0f / (f32)contextFields->cardCount) * (f32)(contextFields->cardCount - activatedCount));
                (sequenceFields->count)++;
            }
        }
        ((BtlShuffleContext *)context)->elapsed = contextFields->elapsed + 1;
        if (((BtlShuffleSequence *)sequence)->count != contextFields->cardCount) {
            break;
        }
        contextFields->phase = 5;
        ((BtlShuffleSequence *)sequence)->flags = ((BtlShuffleSequence *)sequence)->flags | 1;
        contextFields->elapsed = 0;
        ((BtlShuffleSequence *)sequence)->choice = btlShuffleSeqRoll();
    case 5: {
        if (++((BtlShuffleContext *)context)->elapsed < ((BtlShuffleSequence *)sequence)->choice) {
            break;
        }
        contextFields->phase = 7;
    }
    case 7:
        if (datGetFlag(0x1431) == 0) {
            btlShuffleSeqClearA(context, 1);
            contextFields->phase = 0xF;
            ((BtlShuffleContext *)context)->elapsed = 0;
            ((BtlShuffleContext *)context)->flags = contextFields->flags | 2;
            break;
        }
        btlShuffleDrawViewStartCue(((BtlShuffleContext *)context)->viewTask);
        contextFields->phase = 8;
    case 8:
        if (btlShuffleDrawViewIsCueIdle(((BtlShuffleContext *)context)->viewTask) == 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 2);
        contextFields->phase = 9;
    case 9:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        ((BtlShuffleSequence *)sequence)->selectedCard = btlShuffleDrawCheck(context, (u8 *)0);
        btlShuffleDrawViewClearHold(((BtlShuffleContext *)context)->viewTask);
        btlShuffleDrawCardEndDetail(((BtlShuffleContext *)context)->cardTask);
        sdkSndStartStream(1, 2, 2, 0xD);
        contextFields->phase = 0xA;
        break;
    case 10:
        if (btlShuffleDrawStateB(context + (((BtlShuffleSequence *)sequence)->selectedCard * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        btlShuffleSeqMoveA(context, sequenceFields->selectedCard);
        for (j = 0; j < contextFields->cardCount; j++) {
            if (j != sequenceFields->selectedCard) {
                btlShuffleDrawSetFrames(context, j, 0xF, 0xFF, 0);
            }
        }
        sdkSndStartStream(1, 0, 5, 1);
        contextFields->phase = 0xB;
    case 11:
        if (btlShuffleDrawStateA(context + (((BtlShuffleSequence *)sequence)->selectedCard * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (j = 0; j < contextFields->cardCount; j++) {
            if (j != sequenceFields->selectedCard) {
                btlShuffleDrawPoll(context, j, 0);
            }
        }
        ((BtlShuffleSequence *)sequence)->flags = ((BtlShuffleSequence *)sequence)->flags & 0xFFFE;
        btlShuffleSeqCardCount(context, sequenceFields->selectedCard);
        contextFields->phase = 0xC;
        break;
    case 12:
        if (btlShuffleSeqDispatch(context) == 0) {
            break;
        }
        contextFields->phase = 0xD;
    case 13:
        return 1;
    case 14:
        if (btlShuffleSeqStateCheck(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->unk1F248 != 0) {
            contextFields->phase = 0xD;
        } else {
            contextFields->phase = 3;
        }
        break;
    case 15:
        if (btlShuffleSeqFlag(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->flags & 2) {
            contextFields->flags = contextFields->flags & 0xFFFD;
        }
        if (++((BtlShuffleContext *)context)->elapsed < 0x1E) {
            break;
        }
        datSetFlag(0x1431, 1);
        contextFields->phase = 7;
        break;
    default:
        kAssertFail(D_0064EAC0, 0x1B6);
        break;
    }
    if (((BtlShuffleSequence *)sequence)->flags & 1) {
        for (j = 0; j < contextFields->cardCount; j++) {
            if (j != ((BtlShuffleSequence *)sequence)->selectedCard) {
                btlShuffleSeqRecord(context, j, frameSpacing);
            }
        }
    }
    return 0;
}
#pragma pop

void btlShuffleCalcRotatePointAroundAxis(u8 *center, u8 *axis, u8 *point, f32 angle, u8 *output);

#pragma push
#pragma opt_propagation on
/* Choose the card pose axis from the signed index parity. */
// FUN_0037AB50
void btlShuffleInitAlternatingPose(u8 *context, s32 cardIndex, f32 *output) {
    struct {
        f32 axisX;
        f32 axisY;
        f32 axisZ;
        f32 pad5c;
        f32 eyeX;
        f32 eyeY;
        f32 eyeZ;
        f32 pad6c;
        f32 originX;
        f32 originY;
        f32 originZ;
    } work;
    f32 axisScale;
    f32 originZ;
    f32 zero;
    s32 parity;

    btlShuffleCalcResetPose((u8 *)&work.originX);
    work.originY = work.originY - 25.0f;
    work.eyeX = work.originX;
    work.eyeY = work.originY;
    originZ = work.originZ;
    work.eyeZ = btlShuffleAddPoseDepth(originZ, 200.0f);
    parity = cardIndex & 1;
    if ((cardIndex < 0) && (parity != 0)) {
        parity -= 2;
    }
    if (parity == 0) {
        axisScale = -cosf(fGpffff83e4);
        work.axisX = axisScale * sinf(fGpffff837c);
        axisScale = -cosf(fGpffff83e4);
        work.axisY = axisScale * cosf(fGpffff837c);
        work.axisZ = sinf(fGpffff83e4);
        zero = 0.0f;
    } else {
        axisScale = -cosf(fGpffff83e4);
        work.axisX = axisScale * sinf(fGpffff837c);
        axisScale = cosf(fGpffff83e4);
        work.axisY = axisScale * cosf(fGpffff837c);
        work.axisZ = -sinf(fGpffff83e4);
        zero = 0.0f;
    }
    if (output != NULL) {
        btlShuffleCalcRotatePointAroundAxis((u8 *)&work.eyeX, (u8 *)&work.axisX,
                      (u8 *)&work.originX, zero, (u8 *)output);
        return;
    }
    btlShuffleDrawInitCard(context, cardIndex, 0, &work.axisX, &work.eyeX,
                  &work.originX, zero, zero);
}
#pragma pop

extern s32 btlShuffleSeqPick(u8 *context, s32 count);
extern s32 btlShuffleSeqLoadRecord(u8 *context);
extern s32 btlShuffleSeqStep(u8 *context);
extern void btlShuffleDrawCardActivate(u8 *drawWork);
extern void btlShuffleDrawCardSetDetail(u8 *drawWork, s32 input);
extern void btlShuffleDrawCardEndDetail(u8 *drawWork);
extern s32 btlShuffleDrawStateB(u8 *record);
extern s32 btlShuffleDrawStateA(u8 *record);
extern void btlShuffleDrawSetPose(u8 *context, s32 cardIndex, u16 delay, u16 duration);
extern void btlShuffleDrawPoll(u8 *context, s32 cardIndex, s32 enabled);
extern void btlShuffleDrawSetFrames(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start);
extern s32 btlShuffleDrawCheck(u8 *context, u8 *output);
extern void btlShuffleDrawViewClearHold(u8 *drawWork);
extern void btlShuffleDrawViewStartCue(u8 *drawWork);
extern s32 btlShuffleDrawViewIsCueIdle(u8 *drawWork);
extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);
extern void kAssertFail(const void *file, u32 line);
extern char D_0064EAE0[];
extern char D_0064EB00[];
extern u16 D_008C024E[];
extern s32 datGetFlag(s32 bit);
extern void datSetFlag(s32 flagId, s32 enabled);
extern u16 btlShuffleSeqRoll(void);
extern s32 btlShuffleSeqRecord(u8 *context, s32 cardIndex, s32 frames);
extern void btlShuffleSeqMoveA(u8 *context, s32 cardIndex);
extern void btlShuffleSeqClearA(u8 *context, s32 count);
extern s32 btlShuffleSeqFlag(u8 *context);
extern void btlShuffleSeqReset(u8 *context);
extern s32 btlShuffleSeqStateCheck(u8 *context);
extern s32 btlShuffleSeqCardCount(u8 *context, s32 cardIndex);
extern s32 btlShuffleSeqDispatch(u8 *context);
#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants on
/* Run the alternating-axis shuffle sequence, preserving deliberate fallthrough between completed phases. */
/* measured: dedicated typed aliases preserve the retail reload schedule where access-site-only typing does not. */
// FUN_0037AD10
s32 btlShuffleSeq2Run(u8 *context) {
    BtlShuffleContext *contextFields = (BtlShuffleContext *)(context);
    BtlShuffleSequence *sequenceFields;
    BtlShuffleSequence *timingFields;
    struct {
        BtlShufflePoseVector base;
        BtlShufflePoseVector first;
        BtlShufflePoseVector second;
        BtlShufflePoseVector output;
    } work;
    BtlShufflePoseVector v2;
    BtlShufflePoseVector v1;
    BtlShufflePoseVector v0;
    f32 factor;
    f32 base;
    u8 *sequence;
    u8 *timing;
    u8 *deck;
    s32 frameSpacing;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 i;
    s32 j;
    s32 offset;
    f32 xOff;
    f32 thirdY;
    s32 k;
    s32 activatedCount;
    s32 m;
    sequence = context + 0x1F1D0;
    sequenceFields = (BtlShuffleSequence *)(sequence);
    frameSpacing = (u16)(((BtlShuffleSequence *)sequence)->frames / contextFields->cardCount);
    switch (((BtlShuffleContext *)context)->phase) {
    case 0:
        if (btlShuffleSeqPick(context, contextFields->cardCount) == 0) {
            break;
        }
        timing = context + 0x1F1D0;
    timingFields = (BtlShuffleSequence *)(timing);
        switch (((BtlShuffleContext *)context)->difficulty) {
        case 0:
            ((BtlShuffleSequence *)timing)->frames = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            ((BtlShuffleSequence *)timing)->frames = 0x14;
            factor = 0.7f;
            break;
        case 2:
            ((BtlShuffleSequence *)timing)->frames = 0x10;
            factor = 0.8f;
            break;
        default:
            kAssertFail(D_0064EAE0, 0x3A);
            break;
        }
        ((BtlShuffleSequence *)timing)->frames = timingFields->frames * (1.0f + factor * (((BtlShuffleContext *)context)->cardCount - 3) / 5.0f);
        ((BtlShuffleSequence *)sequence)->selectedCard = -1;
        if (btlShuffleSeqLoadRecord(context) != 0) {
            contextFields->phase = 1;
        } else {
            contextFields->phase = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(context) == 0) {
            break;
        }
        contextFields->phase = 2;
    case 2: {
        if (++((BtlShuffleContext *)context)->elapsed < 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 1);
        contextFields->phase = 3;
        break;
    }
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            deck = ((BtlShuffleContext *)context)->cardTask;
            btlShuffleDrawCardEndDetail(deck);
            ((BtlShuffleContext *)context)->elapsed = 0;
            contextFields->phase = 4;
            ((BtlShuffleSequence *)sequence)->count = 0;
            for (i = 0; i < ((BtlShuffleContext *)context)->cardCount; i++) {
                xOff = 150.0f;
                work.base = ((BtlShuffleContext *)context)->cards[i].position;
                btlShuffleInitAlternatingPose(context, 0, &work.output.x);
                if (i % 2 == 0) {
                    xOff = xOff * -1.0f;
                }
                dx = work.output.x - work.base.x;
                work.first.x = xOff + (work.base.x + dx / 3.0f);
                dy = work.output.y - work.base.y;
                thirdY = work.base.y + dy / 3.0f;
                work.first.y = 100.0f + thirdY;
                dz = work.output.z - work.base.z;
                work.first.z = work.base.z + dz;
                work.second.x = xOff + (work.base.x + (2.0f * dx) / 3.0f);
                work.second.y = 100.0f + (work.base.y + (2.0f * dy) / 3.0f);
                work.second.z = work.first.z;
                m = (u16)frameSpacing * i;
                btlShuffleDrawSetTiming(context, i, (u16)m, (u16)(m + 0x14), &work.base.x);
            }
            sdkSndStartStream(0, 4, 0, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(context);
            contextFields->phase = 0xE;
        }
        break;
    case 4:
        base = 0.0f;
        for (k = 0; k < ((BtlShuffleContext *)context)->cardCount; k++) {
            if (btlShuffleDrawStateB(context + k * 0xE8 + 0x1D6A0) != 0) {
                btlShuffleDrawSetPose(context, k, 0, 0xA);
                activatedCount = ((BtlShuffleSequence *)sequence)->count;
                offset = ((u16)frameSpacing * (contextFields->cardCount - activatedCount)) & 0xFFFF;
                if (activatedCount >= contextFields->cardCount) {
                    kAssertFail(D_0064EAE0, 0x6B);
                }
                btlShuffleInitAlternatingPose(context, k, (f32 *)0);
                v2 = ((BtlShuffleContext *)context)->cards[k].axis;
                v1 = ((BtlShuffleContext *)context)->cards[k].eye;
                v0 = ((BtlShuffleContext *)context)->cards[k].origin;
                btlShuffleDrawInitCard(context, k, offset, &v2.x, &v1.x, &v0.x, base, base + (360.0f / (f32)contextFields->cardCount) * (f32)(contextFields->cardCount - activatedCount));
                (sequenceFields->count)++;
            }
        }
        ((BtlShuffleContext *)context)->elapsed = contextFields->elapsed + 1;
        if (((BtlShuffleSequence *)sequence)->count != contextFields->cardCount) {
            break;
        }
        contextFields->phase = 5;
        ((BtlShuffleSequence *)sequence)->flags = ((BtlShuffleSequence *)sequence)->flags | 1;
        contextFields->elapsed = 0;
        ((BtlShuffleSequence *)sequence)->choice = btlShuffleSeqRoll();
    case 5: {
        if (++((BtlShuffleContext *)context)->elapsed < ((BtlShuffleSequence *)sequence)->choice) {
            break;
        }
        contextFields->phase = 7;
    }
    case 7:
        if (datGetFlag(0x1431) == 0) {
            btlShuffleSeqClearA(context, 1);
            contextFields->phase = 0xF;
            ((BtlShuffleContext *)context)->elapsed = 0;
            ((BtlShuffleContext *)context)->flags = contextFields->flags | 2;
            break;
        }
        btlShuffleDrawViewStartCue(((BtlShuffleContext *)context)->viewTask);
        contextFields->phase = 8;
    case 8:
        if (btlShuffleDrawViewIsCueIdle(((BtlShuffleContext *)context)->viewTask) == 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 2);
        contextFields->phase = 9;
    case 9:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        ((BtlShuffleSequence *)sequence)->selectedCard = btlShuffleDrawCheck(context, (u8 *)0);
        btlShuffleDrawViewClearHold(((BtlShuffleContext *)context)->viewTask);
        btlShuffleDrawCardEndDetail(((BtlShuffleContext *)context)->cardTask);
        sdkSndStartStream(1, 2, 2, 0xD);
        contextFields->phase = 0xA;
        break;
    case 10:
        if (btlShuffleDrawStateB(context + (((BtlShuffleSequence *)sequence)->selectedCard * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        btlShuffleSeqMoveA(context, sequenceFields->selectedCard);
        for (j = 0; j < ((BtlShuffleContext *)context)->cardCount; j++) {
            if (j != sequenceFields->selectedCard) {
                btlShuffleDrawSetFrames(context, j, 0xF, 0xFF, 0);
            }
        }
        sdkSndStartStream(1, 0, 5, 1);
        contextFields->phase = 0xB;
    case 11:
        if (btlShuffleDrawStateA(context + (((BtlShuffleSequence *)sequence)->selectedCard * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (j = 0; j < ((BtlShuffleContext *)context)->cardCount; j++) {
            if (j != sequenceFields->selectedCard) {
                btlShuffleDrawPoll(context, j, 0);
            }
        }
        ((BtlShuffleSequence *)sequence)->flags = ((BtlShuffleSequence *)sequence)->flags & 0xFFFE;
        btlShuffleSeqCardCount(context, sequenceFields->selectedCard);
        contextFields->phase = 0xC;
        break;
    case 12:
        if (btlShuffleSeqDispatch(context) == 0) {
            break;
        }
        contextFields->phase = 0xD;
    case 13:
        return 1;
    case 14:
        if (btlShuffleSeqStateCheck(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->unk1F248 != 0) {
            contextFields->phase = 0xD;
        } else {
            contextFields->phase = 3;
        }
        break;
    case 15:
        if (btlShuffleSeqFlag(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->flags & 2) {
            contextFields->flags = contextFields->flags & 0xFFFD;
        }
        if (++((BtlShuffleContext *)context)->elapsed < 0x1E) {
            break;
        }
        datSetFlag(0x1431, 1);
        contextFields->phase = 7;
        break;
    default:
        kAssertFail(D_0064EAE0, 0x19E);
        break;
    }
    if (((BtlShuffleSequence *)sequence)->flags & 1) {
        for (j = 0; j < ((BtlShuffleContext *)context)->cardCount; j++) {
            if (j != ((BtlShuffleSequence *)sequence)->selectedCard) {
                btlShuffleSeqRecord(context, j, frameSpacing);
            }
        }
    }
    return 0;
}
#pragma pop

void btlShuffleCalcRotatePointAroundAxis(u8 *center, u8 *axis, u8 *point, f32 angle, u8 *output);

#pragma push
#pragma opt_propagation on
/* Choose one of three card pose axes by index modulo three. */
// FUN_0037B8C0
void btlShuffleInitThreeAxisPose(u8 *context, s32 cardIndex, f32 *output) {
    struct {
        f32 axisX;
        f32 axisY;
        f32 axisZ;
        f32 pad5c;
        f32 eyeX;
        f32 eyeY;
        f32 eyeZ;
        f32 pad6c;
        f32 originX;
        f32 originY;
        f32 originZ;
    } work;
    f32 axisScale;
    s32 phase;

    btlShuffleCalcResetPose((u8 *)&work.originX);
    work.originY = work.originY - 25.0f;
    work.eyeX = work.originX;
    work.eyeY = work.originY;
    work.eyeZ = btlShuffleAddPoseDepth(work.originZ, 200.0f);
    phase = cardIndex % 3;
    switch (phase) {
    case 0:
        work.axisX = 0.0f;
        work.axisY = cosf(fGpffff80d8);
        work.axisZ = -sinf(fGpffff80d8);
        break;
    case 1:
        axisScale = -cosf(fGpffff80d8);
        work.axisX = axisScale * sinf(fGpffff837c);
        axisScale = -cosf(fGpffff80d8);
        work.axisY = axisScale * cosf(fGpffff837c);
        work.axisZ = sinf(fGpffff80d8);
        break;
    case 2:
        axisScale = -cosf(fGpffff80d8);
        work.axisX = axisScale * sinf(fGpffff837c);
        axisScale = cosf(fGpffff80d8);
        work.axisY = axisScale * cosf(fGpffff837c);
        work.axisZ = -sinf(fGpffff80d8);
        break;
    }
    if (output != NULL) {
        btlShuffleCalcRotatePointAroundAxis((u8 *)&work.eyeX, (u8 *)&work.axisX,
                      (u8 *)&work.originX, 0.0f, (u8 *)output);
        return;
    }
    btlShuffleDrawInitCard(context, cardIndex, 0, &work.axisX, &work.eyeX,
                  &work.originX, 0.0f, 0.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Build two Bezier control points with one of three lateral offsets and assign card timing. */
// FUN_0037BAC0
void btlShuffleCalcSetBezierTiming(u8 *context, s32 cardIndex, s32 output, s32 endFrame) {
    struct {
        BtlShufflePoseVector base;
        BtlShufflePoseVector first;
        BtlShufflePoseVector second;
        BtlShufflePoseVector output;
    } points;
    f32 xOffset;
    f32 yOffset;
    s32 remainder;

    xOffset = 150.0f;
    yOffset = 100.0f;
    points.base = ((BtlShuffleContext *)btlShuffleAddCardOffset(cardIndex * 0xE8, context))->cards[0].position;
    btlShuffleInitThreeAxisPose(context, 0, &points.output.x);
    remainder = cardIndex % 3;
    switch (remainder) {
    case 0:
        yOffset = yOffset * (f32)(remainder - remainder);
        break;
    case 1:
        xOffset = xOffset * -1.0f;
        break;
    case 2:
        break;
    }
    points.first.x = xOffset +
                     (points.base.x +
                      (points.output.x - points.base.x) / 3.0f);
    points.first.y = yOffset +
                     (points.base.y +
                      (points.output.y - points.base.y) / 3.0f);
    points.first.z = points.base.z +
                     (points.output.z - points.base.z);
    points.second.x = xOffset +
                      (points.base.x +
                       (2.0f * (points.output.x - points.base.x)) / 3.0f);
    points.second.y = yOffset +
                      (points.base.y +
                       (2.0f * (points.output.y - points.base.y)) / 3.0f);
    points.second.z = points.first.z;
    btlShuffleDrawSetTiming(context, cardIndex, output, endFrame, &points.base.x);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_loop_invariants on
/* Run the three-axis shuffle sequence and its staggered Bezier card entrances. */
/* measured: dedicated typed aliases preserve the retail reload schedule where access-site-only typing does not. */
// FUN_0037BC80
s32 btlShuffleSeq3Run(u8 *context) {
    BtlShuffleContext *contextFields = (BtlShuffleContext *)(context);
    BtlShuffleSequence *sequenceFields;
    BtlShuffleSequence *timingFields;
    BtlShufflePoseVector v2;
    BtlShufflePoseVector v1;
    BtlShufflePoseVector v0;
    f32 factor;
    f32 base;
    u8 *sequence;
    u8 *timing;
    u8 *deck;
    s32 frameSpacing;
    s32 i;
    s32 j;
    s32 offset;
    s32 k;
    s32 activatedCount;
    s32 m;
    sequence = context + 0x1F1D0;
    sequenceFields = (BtlShuffleSequence *)(sequence);
    frameSpacing = (u16)(((BtlShuffleSequence *)sequence)->frames / contextFields->cardCount);
    switch (((BtlShuffleContext *)context)->phase) {
    case 0:
        if (btlShuffleSeqPick(context, contextFields->cardCount) == 0) {
            break;
        }
        timing = context + 0x1F1D0;
    timingFields = (BtlShuffleSequence *)(timing);
        switch (((BtlShuffleContext *)context)->difficulty) {
        case 0:
            ((BtlShuffleSequence *)timing)->frames = 0x1A;
            factor = 0.6f;
            break;
        case 1:
            ((BtlShuffleSequence *)timing)->frames = 0x14;
            factor = 0.7f;
            break;
        case 2:
            ((BtlShuffleSequence *)timing)->frames = 0x10;
            factor = 0.8f;
            break;
        default:
            kAssertFail(D_0064EB00, 0x3A);
            break;
        }
        ((BtlShuffleSequence *)timing)->frames = timingFields->frames * (1.0f + factor * (((BtlShuffleContext *)context)->cardCount - 3) / 5.0f);
        ((BtlShuffleSequence *)sequence)->selectedCard = -1;
        if (btlShuffleSeqLoadRecord(context) != 0) {
            contextFields->phase = 1;
        } else {
            contextFields->phase = 2;
        }
        break;
    case 1:
        if (btlShuffleSeqStep(context) == 0) {
            break;
        }
        contextFields->phase = 2;
    case 2: {
        if (++((BtlShuffleContext *)context)->elapsed < 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 1);
        contextFields->phase = 3;
        break;
    }
    case 3:
        if ((D_008C024E[0] & 0x40) != 0) {
            deck = ((BtlShuffleContext *)context)->cardTask;
            btlShuffleDrawCardEndDetail(deck);
            ((BtlShuffleContext *)context)->elapsed = 0;
            contextFields->phase = 4;
            ((BtlShuffleSequence *)sequence)->count = 0;
            for (i = 0; i < ((BtlShuffleContext *)context)->cardCount; i++) {
                m = (u16)frameSpacing * i;
                btlShuffleCalcSetBezierTiming(context, i, (u16)m, (u16)(m + 0x14));
            }
            sdkSndStartStream(0, 4, 0, 1);
        } else if ((D_008C024E[0] & 0x20) != 0) {
            btlShuffleSeqReset(context);
            contextFields->phase = 0xE;
        }
        break;
    case 4:
        base = 0.0f;
        for (k = 0; k < ((BtlShuffleContext *)context)->cardCount; k++) {
            if (btlShuffleDrawStateB(context + k * 0xE8 + 0x1D6A0) != 0) {
                btlShuffleDrawSetPose(context, k, 0, 0xA);
                offset = ((u16)frameSpacing * (contextFields->cardCount - k)) & 0xFFFF;
                activatedCount = ((BtlShuffleSequence *)sequence)->count;
                if (activatedCount >= contextFields->cardCount) {
                    kAssertFail(D_0064EB00, 0x72);
                }
                btlShuffleInitThreeAxisPose(context, k, (f32 *)0);
                btlShuffleSeqRecord(context, k, offset);
                v2 = ((BtlShuffleContext *)context)->cards[k].axis;
                v1 = ((BtlShuffleContext *)context)->cards[k].eye;
                v0 = ((BtlShuffleContext *)context)->cards[k].origin;
                btlShuffleDrawInitCard(context, k, offset, &v2.x, &v1.x, &v0.x, base, base + (360.0f / (f32)contextFields->cardCount) * (f32)(contextFields->cardCount - activatedCount));
                (sequenceFields->count)++;
            }
        }
        ((BtlShuffleContext *)context)->elapsed = contextFields->elapsed + 1;
        if (((BtlShuffleSequence *)sequence)->count != contextFields->cardCount) {
            break;
        }
        contextFields->phase = 5;
        ((BtlShuffleSequence *)sequence)->flags = ((BtlShuffleSequence *)sequence)->flags | 1;
        contextFields->elapsed = 0;
        ((BtlShuffleSequence *)sequence)->choice = btlShuffleSeqRoll();
    case 5: {
        if (++((BtlShuffleContext *)context)->elapsed < ((BtlShuffleSequence *)sequence)->choice) {
            break;
        }
        contextFields->phase = 7;
    }
    case 7:
        if (datGetFlag(0x1431) == 0) {
            btlShuffleSeqClearA(context, 1);
            contextFields->phase = 0xF;
            ((BtlShuffleContext *)context)->elapsed = 0;
            ((BtlShuffleContext *)context)->flags = contextFields->flags | 2;
            break;
        }
        btlShuffleDrawViewStartCue(((BtlShuffleContext *)context)->viewTask);
        contextFields->phase = 8;
    case 8:
        if (btlShuffleDrawViewIsCueIdle(((BtlShuffleContext *)context)->viewTask) == 0) {
            break;
        }
        deck = ((BtlShuffleContext *)context)->cardTask;
        btlShuffleDrawCardActivate(deck);
        btlShuffleDrawCardSetDetail(deck, 2);
        contextFields->phase = 9;
    case 9:
        if ((D_008C024E[0] & 0x40) == 0) {
            break;
        }
        ((BtlShuffleSequence *)sequence)->selectedCard = btlShuffleDrawCheck(context, (u8 *)0);
        btlShuffleDrawViewClearHold(((BtlShuffleContext *)context)->viewTask);
        btlShuffleDrawCardEndDetail(((BtlShuffleContext *)context)->cardTask);
        sdkSndStartStream(1, 2, 2, 0xD);
        contextFields->phase = 0xA;
        break;
    case 10:
        if (btlShuffleDrawStateB(context + (((BtlShuffleSequence *)sequence)->selectedCard * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        btlShuffleSeqMoveA(context, sequenceFields->selectedCard);
        for (j = 0; j < ((BtlShuffleContext *)context)->cardCount; j++) {
            if (j != sequenceFields->selectedCard) {
                btlShuffleDrawSetFrames(context, j, 0xF, 0xFF, 0);
            }
        }
        sdkSndStartStream(1, 0, 5, 1);
        contextFields->phase = 0xB;
    case 11:
        if (btlShuffleDrawStateA(context + (((BtlShuffleSequence *)sequence)->selectedCard * 0xE8) + 0x1D6A0) == 0) {
            break;
        }
        for (j = 0; j < ((BtlShuffleContext *)context)->cardCount; j++) {
            if (j != sequenceFields->selectedCard) {
                btlShuffleDrawPoll(context, j, 0);
            }
        }
        ((BtlShuffleSequence *)sequence)->flags = ((BtlShuffleSequence *)sequence)->flags & 0xFFFE;
        btlShuffleSeqCardCount(context, sequenceFields->selectedCard);
        contextFields->phase = 0xC;
        break;
    case 12:
        if (btlShuffleSeqDispatch(context) == 0) {
            break;
        }
        contextFields->phase = 0xD;
    case 13:
        return 1;
    case 14:
        if (btlShuffleSeqStateCheck(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->unk1F248 != 0) {
            contextFields->phase = 0xD;
        } else {
            contextFields->phase = 3;
        }
        break;
    case 15:
        if (btlShuffleSeqFlag(context) == 0) {
            break;
        }
        if (((BtlShuffleContext *)context)->flags & 2) {
            contextFields->flags = contextFields->flags & 0xFFFD;
        }
        if (++((BtlShuffleContext *)context)->elapsed < 0x1E) {
            break;
        }
        datSetFlag(0x1431, 1);
        contextFields->phase = 7;
        break;
    default:
        kAssertFail(D_0064EB00, 0x1AF);
        break;
    }
    if (((BtlShuffleSequence *)sequence)->flags & 1) {
        for (j = 0; j < ((BtlShuffleContext *)context)->cardCount; j++) {
            if (j != ((BtlShuffleSequence *)sequence)->selectedCard) {
                btlShuffleSeqRecord(context, j, frameSpacing);
            }
        }
    }
    return 0;
}
#pragma pop

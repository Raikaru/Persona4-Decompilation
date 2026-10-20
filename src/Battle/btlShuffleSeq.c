/* Original translation unit btlShuffleSeq.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "include_asm.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "btl_shuffle_sequence_internal.h"

typedef struct Vec3f {
    f32 x, y, z;
} Vec3f;

typedef struct ShuffleUnit {
    u8 data[0xE8];
} ShuffleUnit;

extern void kAssertFail(const void *file, u32 line);
extern u32 RpRandom();
extern s32 datGetFlag(s32 bit);
extern s32 btlShuffleDrawStateB(u8 *record);
extern s32 btlShuffleDrawStateC(u8 *record);
extern s32 btlShuffleDrawStateD(u8 *record);
extern void btlShuffleCardScaleVec(u8 *unit, f32 *src, f32 *scale, f32 dst);
extern void btlShuffleDrawMoveCard(u8 *context, s32 cardIndex, f32 delay, f32 duration, f32 *start, f32 *target);
extern void btlShuffleDrawMoveCardB(u8 *context, s32 cardIndex, f32 *start, f32 *target, f32 delay, f32 duration);
extern void btlShuffleDrawInitCard(u8 *a, s32 b, s32 c, f32 *d, f32 *e, f32 *f, f32 g, f32 h);
extern void btlShuffleDrawSetQuat(u8 *context, s32 cardIndex, u16 delay, u16 duration, f32 *start, f32 *target);
extern void btlShuffleDrawSetFrames(u8 *context, s32 cardIndex, s32 delay, s32 duration, s32 start);
extern void func_003dc740(void *dst, void *src, s32 c, f32 d);
extern s32 btlShuffleCardGetKind(u8 *work);
extern u16 btlShuffleCardStateFlags(u8 *card);
extern s32 btlShuffleDrawTableLookup(s32 cardCount, s32 pattern);

/* measured: the operands must travel through this helper's parameters to get
   retail's offset-first `addu $v1,$v0,$s2` at the reused record base; writing
   `arg0 + offset` gives base-first, and naming the offset in an s32 local fixes
   the order but costs a fourth saved register and grows the frame to 0x80. */
static inline u32 seqRecord(u32 offset, u32 base)
{
    return offset + base;
}
extern void btlShuffleDrawViewReset(u8 *context);
extern s32 btlShuffleSeq1Run(u8 *context);
extern s32 btlShuffleSeq2Run(u8 *context);
extern s32 btlShuffleSeq3Run(u8 *context);
extern s32 btlShuffleSeq4Run(u8 *context);
extern s32 btlShuffleSeq5Run(u8 *work);
extern s32 btlShuffleResultSpawn(s32 parentTask, s32 cardKind, s32 personaId, s32 rate);
extern s32 btlShuffleRosterHasResult(s32 drawWork);
extern s32 btlShuffleRosterRequestResult(s32 drawWork);
extern void btlShuffleDrawReset(u8 *context);
extern void btlShuffleDrawFrame(u8 *context);
extern void btlShuffleDrawViewClearFlags(s32 drawWork);
extern void btlShuffleEffRelease(s32 task);
extern void btlShuffleDrawCardReset(s32 drawWork);
extern void fclMiscEnsureMesWindow(s32 a);
extern void fclMesWindowShowItemRecord(s32 record);
extern void nmMesWindowStepCurrent(s32 release);
extern s32 nmMesWindowCurrentOpenState(void);
extern void nmMesWindowCloseCurrent(s32 release);
extern void nmMesWindowResetCurrent(void);
extern s32 nmMesWindowCurrentAnimFlag(void);
extern void memset(void *dst, s32 c, s32 n);
extern u8 nmMesWindowOpenCurrent(u8 *message);
extern void nmMesWindowSetCurrentParam(s32 recordIndex);
extern void nmMesWindowSetCurrentFlag(s32 cursor);
extern void nmMesWindowRequestRefresh(void);
extern void nmMesWindowShowCurrentRecord(s32 recordIndex);
extern void strcpy(char *dst, s32 value);
extern char *datCalcGetSlotRecord(s32 slotIndex);
extern void nmMesWindowSetCurrentString(s32 variable, void *text);
extern void btlShuffleDrawViewSetFade(s32 drawWork, s32 input, s32 green, s32 blue);
extern s32 btlShuffleDrawViewIsFadeDone(s32 drawWork);
extern s32 btlShuffleDrawViewIsStepIdle(s32 drawWork);
extern void btlShuffleDrawViewRequestStep(s32 drawWork, s32 input, s32 green, s32 blue);
extern void btlShuffleDrawViewClearFade(s32 drawWork);
extern void btlShuffleCardInit(u8 *card, u8 *specification);
extern void btlShuffleCardReset(u8 *card);

extern char D_0064EAA0[];
extern s64 D_0064EAB0[];
extern f32 D_0064EAB8[];
extern s32 D_00763AD0;
extern s32 D_00763AD4;


/* 804/816 bytes; eight resolved relocations and twelve zero alignment bytes.
 * CSE-off recomputes the two swap record bases; LICM-on hoists the inner
 * descriptor-count address while retaining each count reload. Together they
 * preserve retail's register allocation. The word buffer holds one 0xFB0-byte
 * record and is completely written before it is read. */
#pragma opt_common_subs off
#pragma opt_loop_invariants on
/* Reorder whole card records to agree with the repeating descriptor list. */
// FUN_00378600
void btlShuffleSeqCardSetup(u8 *context)
{
    BtlShuffleContext *shuffleContext = (BtlShuffleContext *)(context);
    s32 buf[0x3EC];
    s32 mode;
    s32 n;
    s32 i;
    s32 j;
    s32 genus;
    s32 ok;
    s32 genus2;
    u8 *pi;
    u8 *ps;
    u8 *pd;
    s32 k;
    s32 t1;
    s32 t2;
    u8 *card;
    u8 *desc;

    mode = ((BtlShuffleContext *)context)->pattern;
    switch (mode) {
    case 0:
    case 1:
    case 2:
        return;
    case 3:
    case 4:
    default:
        break;
    }
    n = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount, mode);
    i = 0;
    while (i < n - 1) {
        desc = context + (i % ((BtlShuffleContext *)context)->cardCount) * 8 + 0x1F250;
        card = context + i * 0xFB0;
        genus = ((BtlShuffleCardSpec *)desc)->kind;
        if (genus == btlShuffleCardGetKind(card)) {
            if ((genus == 0) && (((BtlShuffleCardSpec *)desc)->id != (btlShuffleCardStateFlags(card) & 0xFFFF))) {
                ok = 0;
            } else {
                ok = 1;
            }
        } else {
            ok = 0;
        }
        if (ok == 0) {
            j = i + 1;
            while (j < n - 1) {
                /* measured: the typed object alias preserves reloads that access-site casts would merge. */
                desc = context + (i % shuffleContext->cardCount) * 8 + 0x1F250;
                card = context + j * 0xFB0;
                genus2 = ((BtlShuffleCardSpec *)desc)->kind;
                if (genus2 == btlShuffleCardGetKind(card)) {
                    if ((genus2 == 0) && (((BtlShuffleCardSpec *)desc)->id != (btlShuffleCardStateFlags(card) & 0xFFFF))) {
                        ok = 0;
                    } else {
                        ok = 1;
                    }
                } else {
                    ok = 0;
                }
                if (ok != 0) {
                    break;
                }
                j++;
            }
            if (j >= n) {
                kAssertFail(D_0064EAA0, 0x56);
            }
            pi = context + i * 0xFB0;
            pd = (u8 *)buf;
            k = 0x1F6;
            ps = pi;
            do {
                t1 = ((BtlShuffleCopyPair *)ps)->first;
                t2 = ((BtlShuffleCopyPair *)ps)->second;
                ps += 8;
                k -= 1;
                ((BtlShuffleCopyPair *)pd)->first = t1;
                ((BtlShuffleCopyPair *)pd)->second = t2;
                pd += 8;
            } while (k > 0);
            ps = context + j * 0xFB0;
            k = 0x1F6;
            pd = ps;
            do {
                t1 = ((BtlShuffleCopyPair *)pd)->first;
                t2 = ((BtlShuffleCopyPair *)pd)->second;
                pd += 8;
                k -= 1;
                ((BtlShuffleCopyPair *)pi)->first = t1;
                ((BtlShuffleCopyPair *)pi)->second = t2;
                pi += 8;
            } while (k > 0);
            pd = (u8 *)buf;
            k = 0x1F6;
            do {
                t1 = ((BtlShuffleCopyPair *)pd)->first;
                t2 = ((BtlShuffleCopyPair *)pd)->second;
                pd += 8;
                k -= 1;
                ((BtlShuffleCopyPair *)ps)->first = t1;
                ((BtlShuffleCopyPair *)ps)->second = t2;
                ps += 8;
            } while (k > 0);
        }
        i++;
    }
}
/* Restore the translation unit defaults for the following functions. */
#pragma opt_common_subs on
#pragma opt_loop_invariants off

/* Return nonzero once every requested card has completed its first motion track. */
// FUN_00378930
s32 btlShuffleSeqCountA(u8 *context, s32 count) {
    s32 i;

    i = 0;
    while (i < count) {
        if (btlShuffleDrawStateB(context + i * 0xE8 + 0x1D6A0) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

/* Return nonzero once every requested card has completed its rotation track. */
// FUN_003789D0
s32 btlShuffleSeqCountB(u8 *context, s32 count) {
    s32 i;

    i = 0;
    while (i < count) {
        if (btlShuffleDrawStateC(context + i * 0xE8 + 0x1D6A0) == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

/* Require every card to finish all three animation tracks before continuing. */
// FUN_00378A70
s32 btlShuffleSeqPick(u8 *context, s32 count) {
    s32 i;
    s32 r;
    s32 ok1;
    s32 ok2;

    i = 0;
    while (i < count) {
        if (btlShuffleDrawStateB(context + i * 0xE8 + 0x1D6A0) == 0) {
            r = 0;
            goto join1;
        }
        i++;
    }
    r = 1;
join1:
    ok1 = (r != 0);
    if (ok1 != 0) {
        i = 0;
        while (i < count) {
            if (btlShuffleDrawStateC(context + i * 0xE8 + 0x1D6A0) == 0) {
                r = 0;
                goto join2;
            }
            i++;
        }
        r = 1;
join2:
        ok1 = (r != 0);
    }
    ok2 = (ok1 != 0);
    if (ok2 != 0) {
        i = 0;
        while (i < count) {
            if (btlShuffleDrawStateD(context + i * 0xE8 + 0x1D6A0) == 0) {
                r = 0;
                goto join3;
            }
            i++;
        }
        r = 1;
join3:
        ok2 = (r != 0);
    }
    return ok2;
}

/* Return the gated reveal delay; the enabled path still consumes one random value. */
// FUN_00378BF0
u16 btlShuffleSeqRoll(void) {
    f32 x;

    if (datGetFlag(0x1431) == 0) {
        return 0x1A;
    }
    RpRandom();
    x = 0.0f;
    return (u16)x;
}

/* The one-word `addu` operand order this note called a floor is fixed by using
   the inline helper PER USE instead of through a named local. The note was right
   that naming the base costs a fourth saved register and grows the frame to
   0x80 -- that applies to an inline helper assigned to a local too. Re-expanding
   the helper at each field access carries the operand order through its
   parameters while leaving no value live across the call, so the frame stays
   0x70. Casting the integer-domain base to `u8 *` before adding the field offset
   is what keeps retail's per-group lui/ori $at expansion rather than one hoisted
   lui. */
/* Start the next circular card segment from its current pose and angle. */
// FUN_00378C80
s32 btlShuffleSeqRecord(u8 *context, s32 cardIndex, s32 frames)
{
    f32 axis[3];
    f32 eye[3];
    f32 origin[3];
    f32 angle;

    if (btlShuffleDrawStateB(context + (cardIndex * 0xE8) + 0x1D6A0) != 0) {
        /* measured: the record base is spelled offset-first in the integer domain
           at every use so b210 emits retail's `addu $v1,$v0,$s2`; a named local or
           an inline helper fixes the order too but costs a fourth saved register
           and grows the frame from 0x70 to 0x80. */
        *(Vec3f *)&axis[0] = *(Vec3f *)&((BtlShuffleContext *)((u8 *)seqRecord(cardIndex * 0xE8, (u32)context)))->cards[0].axis;
        *(Vec3f *)&eye[0] = *(Vec3f *)&((BtlShuffleContext *)((u8 *)seqRecord(cardIndex * 0xE8, (u32)context)))->cards[0].eye;
        *(Vec3f *)&origin[0] = *(Vec3f *)&((BtlShuffleContext *)((u8 *)seqRecord(cardIndex * 0xE8, (u32)context)))->cards[0].origin;
        /* The circular-motion angle overlaps the alternate-position vector. */
        angle = ((BtlShuffleContext *)((u8 *)seqRecord(cardIndex * 0xE8, (u32)context)))->cards[0].angle;
        if (!(angle <= 360.0f)) {
            angle = angle - 360.0f;
        }
        btlShuffleDrawInitCard(context, cardIndex, frames, &axis[0], &eye[0], &origin[0], angle,
                      angle + (360.0f / (f32)((BtlShuffleContext *)context)->cardCount));
        return 1;
    }
    return 0;
}

/* Move a selected card to the screen center over fifteen frames. */
// FUN_00378DF0
void btlShuffleSeqMoveA(u8 *context, s32 cardIndex) {
    f32 screen[2];
    f32 position[3];
    f32 rotation[4];

    screen[0] = 316.0f;
    screen[1] = 211.0f;
    btlShuffleCardScaleVec(context + cardIndex * 0xFB0, screen, position, 160.0f);
    btlShuffleDrawMoveCard(context, cardIndex, 0.0f, 15.0f, NULL, position);
    rotation[3] = 0.0f;
    rotation[0] = 0.0f;
    rotation[1] = 1.0f;
    rotation[2] = 0.0f;
    btlShuffleDrawSetQuat(context, cardIndex, 0, 0xF, NULL, rotation);
}

/* Snap a selected card to the center and begin its facing rotation. */
// FUN_00378EC0
void btlShuffleSeqMoveB(u8 *context, s32 cardIndex) {
    f32 screen[2];
    f32 position[3];
    f32 rotation[4];

    screen[0] = 316.0f;
    screen[1] = 211.0f;
    btlShuffleCardScaleVec(context + cardIndex * 0xFB0, screen, position, 160.0f);
    btlShuffleDrawMoveCard(context, cardIndex, 0.0f, 0.0f, position, position);
    rotation[3] = 0.0f;
    rotation[0] = 0.0f;
    rotation[1] = 1.0f;
    rotation[2] = 0.0f;
    btlShuffleDrawSetQuat(context, cardIndex, 0, 0xF, NULL, rotation);
}

/* Move a card outward in depth and fade it over the requested duration. */
// FUN_00378F90
/* measured: O1 probe for the negative conversion's destination register and tail padding. */
#pragma optimization_level 1
void btlShuffleSeqSetMode(u8 *context, s32 cardIndex, s32 frames) {
    f32 position[3];
    f32 duration;
    s32 halfFrames;

    *(Vec3f *)&position[0] = *(Vec3f *)&((BtlShuffleContext *)((u8 *)seqRecord(cardIndex * 0xE8, (u32)context)))->cards[0].position;
    position[2] = position[2] + 800.0f;
    if (frames >= 0) {
        duration = (f32)frames;
    } else {
        halfFrames = (u32)frames >> 1;
        halfFrames |= frames & 1;
        duration = (f32)halfFrames;
        duration = duration + duration;
    }
    btlShuffleDrawMoveCardB(context, cardIndex, NULL, &position[0], 0.0f, duration);
    btlShuffleDrawSetFrames(context, cardIndex, frames, 0xFF, 0);
}
/* measured: optimization level 1 is required to match func_00379090. */
#pragma optimization_level 1
/* reconstructed from the retail disassembly and Ghidra decompile; scoped
   lverify reports an exact byte match for the 192-byte function window. */
/* Rotate a result card by a signed quarter-turn over the requested frame interval. */
// FUN_00379090
void btlShuffleSeqUpdateMode(u8 *ctx, s32 idx, u16 mode, s32 direction) {
    struct S {
        u64 pair;
        f32 z;
    };
    struct S tmp;
    f32 rotation[4];
    s32 angle;
    u64 pair;
    f32 value;

    if ((s16)direction > 0) {
        angle = 0x5A;
    } else {
        angle = -0x5A;
    }
    {
        register u8 *axisBytes = (u8 *)&tmp;

        pair = D_0064EAB0[0];
        value = D_0064EAB8[0];
        tmp.pair = pair;
        tmp.z = value;
        func_003dc740((void *)&rotation[0], (void *)axisBytes, 0, (f32)angle);
        btlShuffleDrawSetQuat(ctx, idx, 0, mode, 0, (f32 *)&rotation[0]);
    }
}
/* measured: restore optimization level 2 after the O1 target probe; required by following functions. */
#pragma optimization_level 2








/* Compare card kinds and, for persona cards, the encoded persona identifiers. */
// FUN_00379150
s32 btlShuffleSeqCheck(u8 *context, s32 firstIndex, s32 secondIndex) {
    u8 *firstCard;
    u8 *secondCard;
    s32 kind;
    u16 firstId;
    u16 secondId;

    firstCard = context + firstIndex * 0xFB0;
    kind = btlShuffleCardGetKind(firstCard);
    secondCard = context + secondIndex * 0xFB0;
    if (kind == btlShuffleCardGetKind(secondCard)) {
        if (kind == 0) {
            firstId = btlShuffleCardStateFlags(firstCard);
            secondId = btlShuffleCardStateFlags(secondCard);
            if (firstId != secondId) {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
/* measured: nd 211, frame floor. Object 496B vs window 480B (overflows). mwcc emits
   frame -0x40 with sp30 at 0x3c; retail uses -0x70 with sp30 at 0x30 (0x30-0x70
   unused slack). The loop counter colors $a0 (retail: $a1) with the `== 2`
   constant reloaded as `addiu $v0,2` each iteration (retail hoists it into
   $a0). `#pragma opt_loop_invariants on` does NOT hoist it and does not change
   the frame. All other bytes (prologue, loop body, both 0x142A/0x142B branches)
   match modulo the register shift. GP globals: -0x5620->D_00763AD0,
   -0x561C->D_00763AD4 (GP base 0x007690F0). sp30 must be `char[...]` (s32* ->
   char* is illegal in mwcc). 4 attempts. */
/* measured probe: hoist loop-invariant record type for func_00379240. */
#pragma opt_loop_invariants on
/* Collect replacement-card slots and open the enabled replacement message. */
// FUN_00379240
s32 btlShuffleSeqLoadRecord(u8 *context) {
    u8 *base;
    char textBuffer[64];
    s32 i;
    s32 type;
    s32 count;
    char *text;

    base = context + 0x1F210;
    if (datGetFlag(0x1403) == 0) {
        return 0;
    }

    memset(base, 0, 0x2C);
    i = 0;
    type = 2;
    while (i < ((BtlShuffleContext *)context)->cardCount) {
        if (((BtlShuffleCardSpec *)(context + i * 8 + 0x1F250))->kind == type) {
            count = ((BtlShuffleReplacementState *)base)->cardCount;
            ((BtlShuffleReplacementState *)base)->cardCount = count + 1;
            ((BtlShuffleReplacementState *)base)->cards[count] = i;
        }
        i++;
    }

    if (((BtlShuffleReplacementState *)base)->cardCount > 0) {
        if (datGetFlag(0x142A) != 0) {
            strcpy(textBuffer, D_00763AD0);
            /* Keep the archive selector in its signed word representation. */
            nmMesWindowOpenCurrent((u8 *)(((BtlShuffleContext *)context)->textureBlobs[0]));
            text = datCalcGetSlotRecord(0x14);
            nmMesWindowSetCurrentString(0, text);
            nmMesWindowSetCurrentString(1, textBuffer);
            nmMesWindowShowCurrentRecord(0xF);
            ((BtlShuffleReplacementState *)base)->phase = 0;
            return 1;
        }
        if (datGetFlag(0x142B) != 0) {
            strcpy(textBuffer, D_00763AD4);
            nmMesWindowOpenCurrent((u8 *)(((BtlShuffleContext *)context)->textureBlobs[0]));
            text = datCalcGetSlotRecord(0x14);
            nmMesWindowSetCurrentString(0, text);
            nmMesWindowSetCurrentString(1, textBuffer);
            nmMesWindowShowCurrentRecord(0xF);
            ((BtlShuffleReplacementState *)base)->phase = 3;
            return 1;
        }
    }
    return 0;
}
/* measured: restore the translation unit's prior loop-invariant setting. */
#pragma opt_loop_invariants off


typedef struct ShufflePair {
    f32 x;
    f32 y;
} ShufflePair;

/* 1192/1200 bytes with eight zero alignment bytes. The comma expression
 * snapshots the random scale before loading the record count, preserving
 * retail's `mul.s $f0,$f0,$f1` operand order. */
/* Run the message, fade and descriptor replacement sequence. */
// FUN_00379420

s32 btlShuffleSeqStep(u8 *context) {
    BtlShuffleContext *shuffleContext = (BtlShuffleContext *)(context);
    s32 *seq;
    s32 i1;
    s32 i4;
    s32 index;
    u8 *entry4;
    s32 *step1;
    s32 *step4;
    s32 total1;
    s32 total4;
    s32 k1;
    s32 k4;
    u32 random;
    f32 fraction;

    seq = (s32 *)(context + 0x1F210);
    switch (*seq) {
    case 0:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            btlShuffleDrawViewSetFade(*(s32 *)&((BtlShuffleContext *)context)->viewTask, 0xFF, 0xFF, 0xFF);
            *seq = 1;
            nmMesWindowResetCurrent();
        }
        goto done;

    case 1:
        /* measured: the typed object alias preserves reloads that access-site casts would merge. */
        if (btlShuffleDrawViewIsFadeDone(*(s32 *)&shuffleContext->viewTask) == 0) {
            goto done;
        }
        sdkSndStartStream(1, 5, 2, 0);
        i1 = 0;
        while (i1 < ((BtlShuffleReplacementState *)seq)->cardCount) {
            u8 *entry1;
            u8 *source;
            ShufflePair *dstPair;
            ShufflePair *srcPair;
            u8 *sourceRecord;
            source = context + 0x1F304;
            do {
                f32 scale;
                random = RpRandom() & 0xFFF;
                fraction = (f32)random / 4096.0f;
                fraction = (scale = fraction, (f32)*(s32 *)source * scale);
                index = (s32)fraction;
            } while (btlShuffleCardGetKind(context + index * 0xFB0) != 0);
            source = context + index * 8;
            entry1 = (u8 *)(seq + i1 + 1);
            srcPair = (ShufflePair *)(source + 0x1F250);
            dstPair = (ShufflePair *)(context + *(s32 *)entry1 * 8 + 0x1F250);
            *dstPair = *srcPair;

            total1 = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount,
                                   ((BtlShuffleContext *)context)->pattern);
            k1 = *(s32 *)entry1;
            sourceRecord = source + 0x1F250;
            step1 = (s32 *)(context + 0x1F304);
            while (k1 < total1) {
                btlShuffleCardInit(context + k1 * 0xFB0, sourceRecord);
                k1 += *step1;
            }
            i1++;
        }
        btlShuffleDrawViewClearFade(*(s32 *)&shuffleContext->viewTask);
        btlShuffleDrawViewRequestStep(*(s32 *)&((BtlShuffleContext *)context)->viewTask, 0xFF, 0xFF, 0xFF);
        *seq = 2;
        /* fallthrough */

    case 2:
        if (btlShuffleDrawViewIsStepIdle(*(s32 *)&((BtlShuffleContext *)context)->viewTask) != 0) {
            return 1;
        }
        goto done;

    case 3:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            btlShuffleDrawViewSetFade(*(s32 *)&((BtlShuffleContext *)context)->viewTask, 0xFF, 0, 0);
            *seq = 4;
            nmMesWindowResetCurrent();
        }
        goto done;

    case 4:
        if (btlShuffleDrawViewIsFadeDone(*(s32 *)&shuffleContext->viewTask) == 0) {
            goto done;
        }
        sdkSndStartStream(1, 5, 2, 1);
        i4 = 0;
        while (i4 < ((BtlShuffleReplacementState *)seq)->cardCount) {
            entry4 = (u8 *)(seq + i4 + 1);
            ((BtlShuffleCardSpec *)(context + *(s32 *)entry4 * 8 + 0x1F250))->kind = 3;
            total4 = btlShuffleDrawTableLookup(((BtlShuffleContext *)context)->cardCount,
                                   ((BtlShuffleContext *)context)->pattern);
            k4 = *(s32 *)entry4;
            step4 = (s32 *)(context + 0x1F304);
            while (k4 < total4) {
                btlShuffleCardReset(context + k4 * 0xFB0);
                k4 += *step4;
            }
            i4++;
        }
        btlShuffleDrawViewClearFade(*(s32 *)&shuffleContext->viewTask);
        btlShuffleDrawViewRequestStep(*(s32 *)&((BtlShuffleContext *)context)->viewTask, 0, 0, 0);
        *seq = 5;
        /* fallthrough */

    case 5:
        if (btlShuffleDrawViewIsStepIdle(*(s32 *)&((BtlShuffleContext *)context)->viewTask) != 0) {
            return 1;
        }
        goto done;

    default:
        break;
    }

done:
    return 0;
}

/* Open a sequence message and reset its acknowledgement phase. */
// FUN_003798D0
void btlShuffleSeqClearA(u8 *context, s32 count) {
    ((BtlShuffleMessageState *)(context + 0x1F23C))->phase = 0;
    /* Keep the archive selector in its signed word representation. */
    fclMiscEnsureMesWindow(((BtlShuffleContext *)context)->textureBlobs[1]);
    fclMesWindowShowItemRecord(count);
}

/* Wait for the current sequence message to close. */
// FUN_00379920
s32 btlShuffleSeqFlag(u8 *context) {
    u8 *base = context + 0x1F23C;

    switch (((BtlShuffleMessageState *)base)->phase) {
    case 0:
        ((BtlShuffleMessageState *)base)->phase = 1;
        /* fallthrough */
    case 1:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            nmMesWindowCloseCurrent(1);
            ((BtlShuffleMessageState *)base)->phase = 2;
            nmMesWindowResetCurrent();
        }
        break;
    case 2:
        return 1;
    default:
        break;
    }
    return 0;
}

/* Open the cancellation confirmation and clear its result state. */
// FUN_003799D0
void btlShuffleSeqReset(u8 *context) {
    memset(context + 0x1F244, 0, 8);
    /* Keep the archive selector in its signed word representation. */
    nmMesWindowOpenCurrent((u8 *)(((BtlShuffleContext *)context)->textureBlobs[0]));
    nmMesWindowSetCurrentParam(0x14);
    nmMesWindowSetCurrentFlag(0);
    nmMesWindowRequestRefresh();
    nmMesWindowShowCurrentRecord(0x13);
    sdkSndStartStream(0, 4, 0, 2);
}

/* Wait for confirmation and retain its yes/no result. */
// FUN_00379A70
s32 btlShuffleSeqStateCheck(u8 *context) {
    u8 *base = context + 0x1F244;

    switch (((BtlShuffleMessageState *)base)->phase) {
    case 0:
        ((BtlShuffleMessageState *)base)->phase = 1;
        /* fallthrough */
    case 1:
        nmMesWindowStepCurrent(1);
        if (nmMesWindowCurrentOpenState() == 0) {
            s32 r = nmMesWindowCurrentAnimFlag();
            switch (r) {
            case 0:
                ((BtlShuffleMessageState *)base)->result = 1;
                break;
            case 1:
                ((BtlShuffleMessageState *)base)->result = 0;
                break;
            default:
                kAssertFail(D_0064EAA0, 0x22F);
                break;
            }
            nmMesWindowCloseCurrent(1);
            ((BtlShuffleMessageState *)base)->phase = 2;
            nmMesWindowResetCurrent();
        }
        break;
    case 2:
        return 1;
    default:
        break;
    }
    return 0;
}

/* Dispatch the active shuffle pattern after resetting the draw view. */
// FUN_00379B70
s32 btlShuffleSeqCardTask(u8 *context) {
    s32 state;

    btlShuffleDrawViewReset(context);
    state = ((BtlShuffleContext *)context)->pattern;
    switch (state) {
    case 0:
        return btlShuffleSeq1Run(context);
    case 1:
        return btlShuffleSeq2Run(context);
    case 2:
        return btlShuffleSeq3Run(context);
    case 3:
        return btlShuffleSeq4Run(context);
    case 4:
        return btlShuffleSeq5Run(context);
    default:
        kAssertFail(D_0064EAA0, 0x25A);
        return 0;
    }
}

/* Create the selected card result task and record the active selection. */
// FUN_00379C70
s32 btlShuffleSeqCardCount(u8 *context, s32 cardIndex) {
    s32 personaId = 0;
    s32 cardKind;
    s32 result;

    if (cardIndex < 0) {
        cardKind = -1;
    } else {
        u8 *p = context + cardIndex * 0xFB0;
        cardKind = btlShuffleCardGetKind(p);
        if (cardKind == 0) {
            personaId = btlShuffleCardStateFlags(p) & 0xFFFF;
        }
        ((BtlShuffleContext *)context)->flags |= 4;
    }
    ((BtlShuffleContext *)context)->revealCard = cardIndex;
    result = btlShuffleResultSpawn(((BtlShuffleContext *)context)->parentTask, cardKind, personaId, ((BtlShuffleContext *)context)->pattern);
    *(s32 *)&((BtlShuffleContext *)context)->rosterTask = result;
    return result;
}

/* Wait for the result task, rebuilding the deck when another round is requested. */
// FUN_00379D70
s32 btlShuffleSeqDispatch(u8 *context) {
    BtlShuffleContext *shuffleContext = (BtlShuffleContext *)(context);
    /* measured: the separate context alias preserves the task-result saved-register set. */
    if (btlShuffleRosterHasResult(*(s32 *)&shuffleContext->rosterTask) != 0) {
        s32 r = btlShuffleRosterRequestResult(*(s32 *)&shuffleContext->rosterTask);
        *(s32 *)&((BtlShuffleContext *)context)->rosterTask = 0;
        switch (r) {
        case 1:
            return 1;
        case 2:
            btlShuffleSeqCardSetup(context);
            btlShuffleDrawReset(context);
            btlShuffleDrawFrame(context);
            btlShuffleDrawViewClearFlags(*(s32 *)&((BtlShuffleContext *)context)->viewTask);
            btlShuffleEffRelease(*(s32 *)&((BtlShuffleContext *)context)->trailTask);
            btlShuffleDrawCardReset(*(s32 *)&((BtlShuffleContext *)context)->cardTask);
            return 0;
        default:
            kAssertFail(D_0064EAA0, 0x296);
            return 1;
        }
    }
    return 0;
}

#include "btl_target_state_packet_internal.h"
#include "include_asm.h"
#include "type.h"
#include "cmm_internal.h"
#include "effect_instance_internal.h"

extern s32 D_006367C0[];
extern void sdkSndStartChannel(s32 channelIndex, const char *path);
extern void memset(void *input, s32 secondInput, s32 thirdInput);
extern s32 cmmRankUpStepSparkle(s32 *sparkle, u8 *card);
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 iGpffffb480;




extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern f32 sinf(f32 input);
extern void PrimDrawPoints(void *colors, void *positions, f32 depth,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 angle, f32 depth, s32 preserveState);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 00250ad0-002518d0 */



/* Animate and draw one rank-up sparkle; return nonzero after its fade or burst finishes. */
// FUN_00250AD0
s32 cmmRankUpStepSparkle(s32 *sparkle, u8 *card)
{
    CmmRankUpCardTask *cardWork = (CmmRankUpCardTask *)card;

    /* Sparkle records have 0x20-byte stride, flags at +0, position at +4/+8 and timers at +0xC..0x18; typing changed MWCC scheduling. */
    extern s32 shdSpriteDrawNowEx(f32 x, f32 y, f32 depth, s32 color, u8 alpha, s32 entryId, s32 entryOffset, u8 * pack, s32 flags, s16 width, s16 height, f32 rotation, f32 scaleX, f32 scaleY);
    extern u32 RpRandom(void);
    extern f32 sinf(f32 sparkle);
    f32 ra;
    f32 ry;
    f32 fade;
    f32 scale;
    f32 size;
    f32 level;
    f32 fade2;
    f32 rx;
    s32 flags;

    flags = sparkle[0];
    if ((flags & 2) || (flags & 4)) {
        if (flags & 4) {
            scale = 0.6f;
        } else {
            scale = 1.0f;
        }
        if (flags & 8) {
            sparkle[4]++;
        }
        fade = sinf(1.5707964f + (1.5707964f * (f32)sparkle[4]) / 30.0f);
        level = sinf((3.1415927f * (f32)sparkle[3]) / 120.0f);
        size = 42.0f * scale;
        shdSpriteDrawNowEx(*(f32 *)&sparkle[1] - size, *(f32 *)&sparkle[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.1f + 0.2f * level) * fade), 0x1B, 0, ((CmmRankUpCardTask *)card)->slot10.sprites, 1,
                      (s16)size, (s16)size, 0.0f, scale, scale);
        level = (f32)RpRandom() / 2147483648.0f;
        shdSpriteDrawNowEx(*(f32 *)&sparkle[1] - size, *(f32 *)&sparkle[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.1f + 0.4f * level) * fade), 0x1B, 0, cardWork->slot10.sprites, 1,
                      (s16)size, (s16)size, 0.0f, scale, scale);
        level = (1.0f + sinf(-1.5707964f + (6.2831855f * (f32)sparkle[5]) / (f32)sparkle[6])) / 2.0f;
        size = 42.0f * 0.6f;
        shdSpriteDrawNowEx(*(f32 *)&sparkle[1] - size, *(f32 *)&sparkle[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.3f * level) * fade), 0x1B, 0, cardWork->slot10.sprites, 1,
                      (s16)size, (s16)size, (360.0f * (f32)sparkle[3]) / 120.0f, 0.6f, 0.6f);
        level += 0.2f * ((f32)RpRandom() / 2147483648.0f) - 0.1f;
        if (level < 0.0f) {
            level = 0.0f;
        } else if (!(level <= 1.0f)) {
            level = 1.0f;
        }
        shdSpriteDrawNowEx(*(f32 *)&sparkle[1] - size, *(f32 *)&sparkle[2] - size, 0.0f, 0xFFFFFF,
                      (u8)(255.0f * (0.3f * level) * fade), 0x1B, 0, cardWork->slot10.sprites, 1,
                      (s16)size, (s16)size, (360.0f * (f32)sparkle[3]) / 120.0f, 0.6f, 0.6f);
        if (++sparkle[5] >= sparkle[6]) {
            sparkle[5] = 0;
            sparkle[6] = (s32)(60.0f + 40.0f * ((f32)RpRandom() / 2147483648.0f));
        }
        if (++sparkle[3] >= 120) {
            sparkle[3] = 0;
        }
        if (sparkle[4] >= 30) {
            return 1;
        }
    } else {
    fade2 = sinf(1.5707964f - (1.5707964f * (f32)sparkle[3]) / 30.0f);
    scale = 1.0f + (0.6f * ((f32)RpRandom() / 2147483648.0f) - 0.3f);
    ra = (f32)RpRandom() / 2147483648.0f;
    ry = (f32)RpRandom() / 2147483648.0f;
    rx = (f32)RpRandom() / 2147483648.0f;
    shdSpriteDrawNowEx((*(f32 *)&sparkle[1] + (f32)p4_0025_span(1.0f, rx)) - 19.0f * scale,
                  (*(f32 *)&sparkle[2] + (f32)p4_0025_span(1.0f, ry)) - 19.0f * scale,
                  0.0f, 0xFFFFFF, (u8)(fade2 * (f32)(p4_0025_span(127.0f, ra) + 128)),
                  0x2F, 0, ((CmmRankUpCardTask *)card)->slot10.sprites, 1, 0, 0, 0.0f, scale, scale);
    if (++sparkle[3] >= 30) {
        return 1;
    }
    }
    return 0;
}

/* Reserve and zero the first free 0x20-byte sparkle in the selected pool (12, 4 or 3 slots). */
// FUN_00251570
u8 *cmmRankUpReserveSparkle(s32 workAddress, s32 poolKind) {
    u8 *slot;
    s32 slotIndex;

    if (poolKind != 0) {
        goto select_second;
    }
    slot = (u8 *)((u8 *)((CmmRankUpWork *)workAddress)->unk_780);
    slotIndex = 0;
    goto first_test;
first_body:
    if ((*(u32 *)slot & 1) == 0) {
        memset(slot, 0, 0x20);
        *(u32 *)slot |= 1;
        return slot;
    }
    slot += 0x20;
    slotIndex += 1;
first_test:
    if (slotIndex >= 0xC) {
        goto done;
    }
    goto first_body;
select_second:
    if ((u32)(poolKind - 1) >= 2U) {
        goto select_third;
    }
    slot = (u8 *)((u8 *)((CmmRankUpWork *)workAddress)->unk_780 + 0x180);
    slotIndex = 0;
    goto second_test;
second_body:
    if ((*(u32 *)slot & 1) == 0) {
        memset(slot, 0, 0x20);
        *(u32 *)slot |= 1;
        return slot;
    }
    slot += 0x20;
    slotIndex += 1;
second_test:
    if (slotIndex >= 4) {
        goto done;
    }
    goto second_body;
select_third:
    if (poolKind != 3) {
        goto done;
    }
    slot = (u8 *)((u8 *)((CmmRankUpWork *)workAddress)->unk_780 + 0x200);
    slotIndex = 0;
    goto third_test;
third_body:
    if ((*(u32 *)slot & 1) == 0) {
        memset(slot, 0, 0x20);
        *(u32 *)slot |= 1;
        return slot;
    }
    slot += 0x20;
    slotIndex += 1;
third_test:
    if (slotIndex < 3) {
        goto third_body;
    }
done:
    return NULL;
}

/* Step all three sparkle pools and clear the active bit when a sparkle finishes. */
// FUN_002516F0
void cmmRankUpStepSparklePools(u8 *work, u8 *card) {
    /* Sparkle records have 0x20-byte stride, flags at +0, position at +4/+8 and timers at +0xC..0x18; typing changed MWCC scheduling. */
    s32 firstIndex;
    s32 *secondSparkle;
    s32 *thirdSparkle;
    s32 secondIndex;
    s32 thirdIndex;
    s32 *firstSparkle;

    firstSparkle = (s32 *)(work + 0x780);
    firstIndex = 0;
    goto loop_5_test;
loop_5_body:
    if ((*firstSparkle & 1) && (cmmRankUpStepSparkle(firstSparkle, card) != 0)) {
        *firstSparkle &= ~1;
    }
    firstSparkle = (s32 *)((u8 *)firstSparkle + 0x20);
    firstIndex += 1;
loop_5_test:
    if (firstIndex < 0xC) {
        goto loop_5_body;
    }
    secondSparkle = (s32 *)(work + 0x900);
    secondIndex = 0;
    goto loop_11_test;
loop_11_body:
    if ((*secondSparkle & 1) && (cmmRankUpStepSparkle(secondSparkle, card) != 0)) {
        *secondSparkle &= ~1;
    }
    secondSparkle = (s32 *)((u8 *)secondSparkle + 0x20);
    secondIndex += 1;
loop_11_test:
    if (secondIndex < 4) {
        goto loop_11_body;
    }
    thirdSparkle = (s32 *)(work + 0x980);
    thirdIndex = 0;
    goto loop_17_test;
loop_17_body:
    if ((*thirdSparkle & 1) && (cmmRankUpStepSparkle(thirdSparkle, card) != 0)) {
        *thirdSparkle &= ~1;
    }
    thirdSparkle = (s32 *)((u8 *)thirdSparkle + 0x20);
    thirdIndex += 1;
loop_17_test:
    if (thirdIndex < 3) {
        goto loop_17_body;
    }
}

/* Request fade-out (bit 3) on active sparkles in the first two pools. */
// FUN_00251850
void cmmRankUpFadeSparklePools(u8 *work) {
    /* Sparkle records have 0x20-byte stride, flags at +0, position at +4/+8 and timers at +0xC..0x18; typing changed MWCC scheduling. */
    s32 firstIndex;
    u8 *firstSparkle;
    u8 *secondSparkle;
    s32 secondFlags;
    s32 firstFlags;
    s32 secondIndex;

    firstSparkle = work + 0x780;
    firstIndex = 0;
    goto loop_test;
loop_4:
    firstFlags = *(s32 *)firstSparkle;
    if (firstFlags & 1) {
        *(s32 *)firstSparkle = firstFlags | 8;
    }
    firstSparkle += 0x20;
    firstIndex += 1;
loop_test:
    if (firstIndex < 0xC) {
        goto loop_4;
    }
    secondSparkle = work + 0x900;
    secondIndex = 0;
    goto loop_9_test;
loop_9:
    secondFlags = *(s32 *)secondSparkle;
    if (secondFlags & 1) {
        *(s32 *)secondSparkle = secondFlags | 8;
    }
    secondSparkle += 0x20;
    secondIndex += 1;
loop_9_test:
    if (secondIndex < 4) {
        goto loop_9;
    }
}

/* Select the rank-up sound for ranks 0 through 12; other ranks leave the channel unchanged. */
// FUN_002518D0
void cmmRankUpPlayRankSound(s32 rank) {
    if ((rank > 0) && (rank < 10)) {
        sdkSndStartChannel(2, D_00635C00);
        return;
    }
    if (rank == 10) {
        sdkSndStartChannel(2, D_00635C00);
        return;
    }
    if (rank == 0) {
        sdkSndStartChannel(2, D_00635C20);
        return;
    }
    if (rank == 11) {
        sdkSndStartChannel(2, D_00635C40);
        return;
    }
    if (rank == 12) {
        sdkSndStartChannel(2, D_00635C60);
    }
}


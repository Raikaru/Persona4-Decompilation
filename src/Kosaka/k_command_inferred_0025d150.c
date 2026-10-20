#include "btl_action_internal.h"
#include "datPersona_internal.h"
#include "Kosaka/k_command_internal.h"
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"

static inline f32 p4_0025_mul_add(f32 left, f32 right, f32 base) {
    return left * right + base;
}
static inline f32 p4_0025_add(f32 left, f32 right) {
    return left + right;
}
extern s32 D_006367C0[];
extern void memcpy(void *, void *, s32);
extern s16 D_00636A40[];
extern char D_00635C00[];
extern char D_00635C20[];
extern char D_00635C40[];
extern char D_00635C60[];
extern s32 cutinDrawTaskCreate(s32 unused, s32 packedIds);
extern s32 taskRecordIsDone(s32 task);
extern void taskRecordRequestSecondary(s32 task);
extern void taskRecordSetPosition(s32 task, s64 packedPosition);
extern s32 iGpffffb480;



void fadeBegin(void);
s32 fadeIsIdle(void);

s16 datGetPartyId(s32 idx);
void datSetPartyId(s32 idx, s32 pcId);
s16 datGetEquippedItemByUnit(s16 unitId, s16 slotIndex);
void datAssignEquippedItem(s16 unitId, s16 slotIndex, s16 itemId);
s32 kwlnTaskIsLinked(s32 target);
void taskRecordRequestPrimary(s32 task);
s32 mcIconTaskCreate(u8 *parent, s32 mode);
s32 mcIconTaskPoll(void);
extern u8 D_00635BF0[];
extern u8 D_007963D0[];
extern u16 D_008C024E[];
extern f32 fGpffff8200;
extern f32 cosf(f32);
extern f32 sinf(f32);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern void PrimDrawPoints(void *colors, void *positions, f32 farg0,
                           s32 count, s32 primitiveType, s32 preserveState);
extern void PrimDrawRadialTriangle(s32 centerX, s32 centerY, void *color, s32 radius,
                           f32 farg0, f32 farg1, s32 preserveState);






/* Whole units of `range` covered by the random fraction `unit`. */
static inline u32 p4_0025_span(f32 range, f32 unit)
{
    return (u32)(range * unit);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0025; members 0025d150-0025d850 */

/* Each copied persona-template entry contains two halfwords; the second is
 * passed to datPersonaLoadRecord as its template identifier. */
typedef struct PersonaTemplateEntry { u16 unk00, templateId; } PersonaTemplateEntry;

// FUN_0025D150
s32 scrCommonSetItemCount(void) {
    s16 itemId;

    itemId = scrGetParamInt(0);
    datItemSetCount(itemId, scrGetParamInt(1) & 0xFF);
    return 1;
}

/* measured probe: opt_propagation off tests d1b0 saved-register colouring. */
// Intent: Common script command PARTY_IN (p4flow Common 0x0038): adds a character to a party slot if absent [inferred]
/* Keep existing party members; fill the first empty slot or replace the final slot. */
// FUN_0025D1B0
s32 scrCommonPartyIn(void) {
    s32 emptySlotIndex;
    s64 memberId;
    s32 slotIndex;
    s32 inserted;

    inserted = 0;
    slotIndex = 0;
    goto loop_4_test;
loop_4:
    memberId = datGetPartyId(slotIndex);
    if ((s32)memberId == scrGetParamInt(0)) {
        inserted = 1;
    }
    slotIndex += 1;
loop_4_test:
    if (slotIndex < 3) {
        goto loop_4;
    }
    if (inserted != 0) {
        goto block_4;
    }
    emptySlotIndex = 0;
    goto loop_10_test;
loop_10:
    if ((s64)datGetPartyId(emptySlotIndex) == 0) {
        datSetPartyId(emptySlotIndex, (s32)(s64)(s16)scrGetParamInt(0));
        inserted = 1;
        goto block_4;
    }
    emptySlotIndex += 1;
loop_10_test:
    if (emptySlotIndex < 3) {
        goto loop_10;
    }
block_4:
    if (inserted == 0) {
        datSetPartyId(2, (s32)(s64)(s16)scrGetParamInt(0));
    }
    return 1;
}

/* measured probe: restore opt_propagation after d1b0. */
// Intent: Common script command PARTY_OUT (p4flow Common 0x0039): clears the party slot holding a character [inferred]
/* Remove every party slot holding the requested member. */
// FUN_0025D2D0
s32 scrCommonPartyOut(void) {
    s16 memberId;
    s32 slotIndex;

    slotIndex = 0;
    while (slotIndex < 3) {
        memberId = datGetPartyId(slotIndex);
        if (memberId == scrGetParamInt(0)) {
            datSetPartyId(slotIndex, 0);
        }
        slotIndex++;
    }
    return 1;
}

/* Fetch a character stat using signed-halfword identifiers and publish the integer result. */
// FUN_0025D350
s32 scrCommonGetCharStat(void) {
    s16 characterId;
    s16 statId;

    characterId = scrGetParamInt(0);
    statId = scrGetParamInt(1);
    scrSetReturnInt((s32)datGetEquippedItemByUnit(characterId, statId));
    return 1;
}

/* Set a character stat from three operands narrowed to signed halfwords. */
// FUN_0025D3C0
s32 scrCommonSetCharStat(void) {
    s16 characterId;
    s16 statId;

    characterId = scrGetParamInt(0);
    statId = scrGetParamInt(1);
    datAssignEquippedItem(characterId, statId, (s16)scrGetParamInt(2));
    return 1;
}

/* Start the flagged icon task on the first command frame, then wait for a nonzero result. */
// FUN_0025D440
s32 K_Cmd_ICON_START_FLAGGED_WAIT(void) {
    s32 result;

    if (scrGetCmdTimer() == 0) {
        mcIconTaskCreate(0, 1);
        goto block_4;
    }
    result = mcIconTaskPoll();
    if (result != 0) {
        scrSetReturnInt(result);
        return 1;
    }
block_4:
    return 0;
}

/* Start the icon task once and yield until its poll returns a result. */
// FUN_0025D4B0
s32 K_Cmd_ICON_START_WAIT(void) {
    s32 result;

    if (scrGetCmdTimer() == 0) {
        mcIconTaskCreate(0, 0);
    } else {
        result = mcIconTaskPoll();
        if (result != 0) {
            scrSetReturnInt(result);
            return 1;
        }
    }
    return 0;
}

// FUN_0025D520
s32 scrCommonNop(void)
{
    return 1;
}

/* Return the signed-halfword member identifier in the script-selected party slot. */
// FUN_0025D530
s32 scrCommonGetPartyMember(void)
{
    scrSetReturnInt((s16)datGetPartyId(scrGetParamInt(0)));
    return 1;
}

/* Load the selected persona template and replace the destination record. */
// FUN_0025D580
s32 scrCommonLoadPersonaRecord(void) {
    u8 recordTable[0x30];
    s16 record[18];
    s16 *source;
    s16 *destination;
    u16 selectedId;
    s16 secondHalfword;
    s16 firstHalfword;
    s32 destinationRecord;
    u16 personaId;
    s32 pairsRemaining;
    personaId = scrGetParamInt(0) & 0xFFFF;
    source = D_00636A40;
    destination = (s16 *)recordTable;
    pairsRemaining = 9;
    do {
        firstHalfword = *source;
        secondHalfword = *(source + 1);
        source += 2;
        pairsRemaining -= 1;
        *destination = firstHalfword;
        *(destination + 1) = secondHalfword;
        destination += 2;
    } while (pairsRemaining > 0);
    selectedId = (u16)personaId;
    if (selectedId == 1) {
        return 1;
    }
    destinationRecord = (s32)datPersonaGetRecord(personaId);
    datPersonaLoadRecord(
        (u8 *)record,
        ((PersonaTemplateEntry *)recordTable)[personaId & 0xFFFF].templateId,
        (u8 *)destinationRecord);
    memcpy((void *)destinationRecord, record, 0x30);
    return 1;
}

/* Create a cut-in task, wait for readiness, and then set its position and return its handle. */
// FUN_0025D650
s32 K_Cmd_CUTIN_DRAW_START(void) {
    struct {
        f32 f0;
        f32 f1;
        s32 pad;
        s16 h0;
        s16 h1;
    } local;
    s32 flags;
    s32 cutinId;

    local.f0 = (f32)scrGetParamInt(0);
    local.f1 = (f32)scrGetParamInt(1);
    cutinId = scrGetParamInt(2);
    flags = scrGetParamInt(3);
    if (scrGetCmdTimer() == 0) {
        local.h0 = (s16)cutinId;
        local.h1 = (s16)flags;
        iGpffffb480 = cutinDrawTaskCreate(0, *(s32 *)&local.h0);
        goto block_4;
    }
    if (taskRecordIsDone(iGpffffb480) != 0) {
        taskRecordRequestSecondary(iGpffffb480);
        taskRecordSetPosition(iGpffffb480, *(s64 *)&local.f0);
        scrSetReturnInt(iGpffffb480);
        iGpffffb480 = 0;
        return 1;
    }
block_4:
    return 0;
}

/* Request task shutdown on the first command frame and complete on the next frame. */
// FUN_0025D760
s32 K_Cmd_TASK_DESTROY(void) {
    s32 task;

    task = scrGetParamInt(0);
    if (scrGetCmdTimer() == 0) {
        if (kwlnTaskIsLinked(task) != 0) {
            taskRecordRequestPrimary(task);
        }
    } else {
        return 1;
    }
    return 0;
}

/* `x > 0xA` here, not the equivalent `x >= 0xB`: b210 compiles `>= K` by
   materialising the comparison into $v0, and `> K-1` by branching through the
   assembler temp as retail does (slti $at,$v0,0xB / bnez $at). Identical
   semantics, different branch form - this was the whole nd-2 residual. Found by
   permute_ast (MATCH at 113 compiles) and reduced with permute_min; the winner
   had rewritten the constant as `> (0xB & 0xFFFF) - 1`, which is the same thing.
   Un-chaining the && and negating the inner test do NOT help - both stay nd 2. */
/* Begin fading on command frame ten and wait until the fade controller becomes idle. */
// FUN_0025D7E0
s32 K_Cmd_FADE_BEGIN_WAIT(void) {
    if (scrGetCmdTimer() == 0xA) {
        fadeBegin();
        goto block_5;
    }
    if ((scrGetCmdTimer() > 0xA) && (fadeIsIdle() != 0)) {
        return 1;
    }
block_5:
    return 0;
}

/* Build a 30-segment annular strip with offset inner vertices, then draw its central radial primitive. */
// FUN_0025D850
void K_SineRingDraw(f32 centerX, f32 centerY, f32 depth, s32 packedColor) {
    struct {
        u8 colors[0x100];
        f32 points[0x7C];
    } local;
    s32 segmentIndex;
    f32 *pointCursor;
    u8 *colorCursor;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    f32 startAngle;
    f32 angleDegrees;
    f32 innerSine;
    f32 outerSine;
    f32 innerAngle;
    f32 angleRadians;
    f32 outerCosineOffset;
    f32 innerCosineOffset;

    pointCursor = local.points;
    colorCursor = local.colors;
    segmentIndex = 0;
    red = (u8)((u32)packedColor >> 0x18);
    green = (u8)((u32)packedColor >> 0x10);
    blue = (u8)((u32)packedColor >> 8);
    alpha = (u8)packedColor;
    goto loop_test;
loop_body:
    angleDegrees = 12.0f * (f32)segmentIndex;
    angleRadians = fGpffff8200 * angleDegrees;
    outerSine = sinf(angleRadians);
    outerCosineOffset = 8.5f * cosf(angleRadians);
    pointCursor[0] = p4_0025_mul_add(8.5f, outerSine, centerX + outerCosineOffset);
    pointCursor[1] = p4_0025_add(
        p4_0025_mul_add(8.5f, -outerSine, centerY), outerCosineOffset);
    innerAngle = fGpffff8200 * (6.0f + angleDegrees);
    innerSine = sinf(innerAngle);
    innerCosineOffset = 7.0f * cosf(innerAngle);
    pointCursor[2] = p4_0025_mul_add(7.0f, innerSine, centerX + innerCosineOffset);
    pointCursor[3] = p4_0025_add(
        p4_0025_mul_add(7.0f, -innerSine, centerY), innerCosineOffset);
    pointCursor += 4;
    colorCursor[0] = red;
    colorCursor[1] = green;
    colorCursor[2] = blue;
    colorCursor[3] = alpha;
    colorCursor[4] = red;
    colorCursor[5] = green;
    colorCursor[6] = blue;
    colorCursor[7] = alpha;
    colorCursor += 8;
    segmentIndex += 1;
loop_test:
    if (segmentIndex < 0x1E) {
        goto loop_body;
    }
    pointCursor[0] = local.points[0];
    pointCursor[1] = local.points[1];
    pointCursor[2] = local.points[2];
    pointCursor[3] = local.points[3];
    colorCursor[0] = (u8)((u32)packedColor >> 0x18);
    colorCursor[1] = (u8)((u32)packedColor >> 0x10);
    colorCursor[2] = (u8)((u32)packedColor >> 8);
    colorCursor[3] = (u8)packedColor;
    colorCursor[4] = (u8)((u32)packedColor >> 0x18);
    colorCursor[5] = (u8)((u32)packedColor >> 0x10);
    colorCursor[6] = (u8)((u32)packedColor >> 8);
    colorCursor[7] = (u8)packedColor;
    shdEnableBlendFlag();
    PrimDrawPoints(local.colors, local.points, depth, 0x3E, 4, 1);
    local.colors[0] = 0xDC;
    local.colors[1] = 0xDC;
    local.colors[2] = 0xDC;
    local.colors[3] = 0xFF;
    startAngle = 180.0f;
    PrimDrawRadialTriangle((s32)centerX, (s32)centerY, local.colors, 8, startAngle, depth, 1);
    shdDisableBlendFlag();
}


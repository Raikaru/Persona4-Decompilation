#include "operand_order_internal.h"
#include "byte_address_internal.h"
#include "member_access.h"
#include "btl_effect_internal.h"
#include "btl_unit_record_internal.h"
#include "btl_unit_packet_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_skill_target_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
#include "effect_instance_internal.h"
#include "btl_skill_internal.h"
#include "rw_types_internal.h"
typedef struct DatUnit DatUnit;

extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
extern s32 datCalcSkillElement(u8 *unit, u16 skillId);
extern u8 *iGpffffb3c0;
extern u8 *iGpffffb3cc;


extern u8 *iGpffff9db0;
extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0;
extern s32 iGpffffb430;
extern s32 iGpffffb434;
extern s32 iGpffffb438;
extern u8 D_005F6BF0[];
extern u8 D_005F66C0[];
extern u64 iGpffffa090;
extern u16 iGpffffa098;
extern s32 iGpffffb43c;
extern u8 D_005F65D0[];
extern u8 D_005F65B0[];
extern u8 D_005F65C0[];

extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern RwV3d D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern RwV3d D_0060A100;
extern u8 *(*D_008873E8[])(s32 data, s32 value);


/* Widen a signed motion-table halfword to the return-value integer domain. measured: retail sign-
 * extends the loaded halfword to 64 bits explicitly; direct casts at the callers drop that
 * extension. */
static inline s64 btlUnitExtendSignedHalfword(s16 value)
{
    return value;
}

extern f32 mdlGetLayerWeight(s32 model, s32 layer);
extern void mdlSetLayerTime(void *model, s32 layer, f32 frameValue);
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

#pragma push
#pragma pop
/* Return motion-table frames divided by the requested and per-motion playback rates. */
// FUN_001991C0
s16 btlUnitMotionFrames(u8 *unit, u16 motion, f32 rate)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 motionId;
    u8 type;
    u8 *entry;

    type = ((BtlUnit *)unit)->genus;
    switch (type) {
    case 1:
        result = ((s64)(s16)(btlFormationLookupSlot(unit, motion)));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = typedUnit->genus;
        table = D_005F6CA0 + (type * 0x1E);
        value = btlUnitExtendSignedHalfword(
            table[offset = motion & 0xFFFF]);
        if ((((BtlUnit *)unit)->stateFlags & 0x100) &&
            (type == 0) &&
            (((BtlUnit *)unit)->charId == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = ((s64)(s16)(value));
finish:
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        /* measured: a signed scalar motion index keeps the retail register allocation;
         * byteAddressAdd does not. */
        entry = (u8 *)operandOrderAdd((s32)motionId * 10, (s32)*(u8 * *)&typedUnit->motionRates);
        return (s64)(s32)((f32)((BtlMotionRate *)entry)->unk0 /
            (rate * ((f32)((BtlMotionRate *)entry)->rate / 100.0f)));
    }
    return 0;
}

/* Return the scaled follow-up interval; a negative table interval yields zero. */
// FUN_00199350
s16 btlUnitMotionFollowFrames(u8 *unit, u16 motion, f32 rate)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    u8 type;
    u8 *entry;
    s16 numerator;

    type = ((BtlUnit *)unit)->genus;
    switch (type) {
    case 1:
        result = ((s64)(s16)(btlFormationLookupSlot(unit, motion)));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = typedUnit->genus;
        table = D_005F6CA0 + (type * 0x1E);
        value = btlUnitExtendSignedHalfword(
            table[offset = motion & 0xFFFF]);
        if ((((BtlUnit *)unit)->stateFlags & 0x100) &&
            (type == 0) &&
            (((BtlUnit *)unit)->charId == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = ((s64)(s16)(value));
finish:
{
    s32 motionId;
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        /* measured: a signed scalar motion index keeps the retail register allocation;
         * byteAddressAdd does not. */
        entry = (u8 *)operandOrderAdd((s32)motionId * 10, (s32)*(u8 * *)&typedUnit->motionRates);
        numerator = ((BtlMotionRate *)entry)->unk4;
        if (numerator < 0) {
            return 0;
        }
        return (s64)(s32)((f32)numerator /
            (rate * ((f32)((BtlMotionRate *)entry)->rate / 100.0f)));
    }
}
return 0;
}

/* Return the frame length of a motion's model animation, divided by the given rate and the motion
 * table's playback rate when the motion has a table entry. */
// FUN_00199500
s16 btlUnitMotionModelFrames(u8 *unit, u16 motion, f32 rate)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    extern f32 mdlGetLayerKeyTime(s32 model, s32 layer, s64 animationIndex);
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 motionId;
    f32 modelFrames;
    u8 type;
    u8 *entry;

    if (!(((BtlUnit *)unit)->flags2 & 2)) {
        return 0;
    }
    type = ((BtlUnit *)unit)->genus;
    switch (type) {
    case 1:
        result = ((s64)(s16)(btlFormationLookupSlot(unit, motion)));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = typedUnit->genus;
        table = D_005F6CA0 + (type * 0x1E);
        value = btlUnitExtendSignedHalfword(
            table[offset = motion & 0xFFFF]);
        if ((((BtlUnit *)unit)->stateFlags & 0x100) &&
            (type == 0) &&
            (((BtlUnit *)unit)->charId == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = ((s64)(s16)(value));
finish:
    modelFrames = mdlGetLayerKeyTime((s32)((BtlUnit *)unit)->layerHandle, 0, result);
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        entry = (u8 *)(s32)byteAddressAdd(motionId * 10, (u8 *)((s32)(u8 *)((BtlUnit *)unit)->motionRates));
        return (s64)(s32)(modelFrames /
            (rate * ((f32)((BtlMotionRate *)entry)->rate / 100.0f)));
    }
    return (s64)(s32)modelFrames;
}

/* Resolve the final halfword of a motion row, defaulting to six when unavailable. */
// FUN_001996D0
s16 btlUnitGetMotionTableFrames(u8 *unit, u16 motion)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    u8 *table;
    s32 offset;
    s64 result;
    s64 value;
    s32 motionId;
    u8 type;
    u8 *entry;

    if (!(((BtlUnit *)unit)->flags2 & 2)) {
        return 6;
    }
    type = ((BtlUnit *)unit)->genus;
    switch (type) {
    case 1:
        result = ((s64)(s16)(btlFormationLookupSlot(unit, motion)));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = typedUnit->genus;
        table = D_005F6CA0 + (type * 0x1E);
        value = btlUnitExtendSignedHalfword(
            table[offset = motion & 0xFFFF]);
        if ((((BtlUnit *)unit)->stateFlags & 0x100) &&
            (type == 0) &&
            (((BtlUnit *)unit)->charId == 1) &&
            (offset == 1)) {
            value = 0x1C;
        }
        goto value_done;
    default:
        result = 0;
        goto finish;
    }
value_done:
    result = ((s64)(s16)(value));
finish:
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        entry = (u8 *)(s32)byteAddressAdd(motionId * 10, (u8 *)((s32)(u8 *)((BtlUnit *)unit)->motionRates));
        return ((BtlMotionRate *)entry)->unk8;
    }
    return 6;
}

/* Return the current layer-zero frame, or zero when the model is absent. */
// FUN_00199830
s64 btlUnitModelAnimFrame(u8 *unit) {
    if (((BtlUnit *)unit)->flags2 & 2) {
        return (s64)(s16)(s32)mdlGetLayerWeight((s32)((BtlUnit *)unit)->layerHandle, 0);
    }
    return 0;
}

/* Seek layer zero only while the unit owns a loaded model. */
// FUN_00199890
void btlUnitSetModelAnimFrame(u8 *unit, s32 frame)
{
    if ((((BtlUnit *)unit)->flags2 & 2) != 0)
        mdlSetLayerTime(((BtlUnit *)unit)->layerHandle, 0, (f32)frame);
}

/* Formation class values occupy the first halfword of each four-byte hit-class pair. Classify the
 * requested motion and read the formation-specific class value when applicable. */
// FUN_001998E0
s32 btlUnitMotionClassValue(u8 *unit, s32 motion)
{
    BtlUnitEnemyRecord *classRecord;

    s32 index;
    s32 result;
    s64 signedResult;
    u8 kind;
    u16 id;
    s32 offset;
    s32 base;
    s32 finalResult;

    kind = ((BtlUnit *)unit)->genus;
    if (kind == 1) {
        index = motion & 0xFFFF;
        switch (index) {
        case 4:
        case 5:
        case 6:
        case 7:
            result = 0;
            goto classification_done_001998e0;
        default:
            goto result_invalid_001998e0;
        }
    } else {
        index = motion & 0xFFFF;
        switch (index) {
        case 5:
            result = 0;
            goto classification_done_001998e0;
        case 6:
        case 7:
            result = 1;
            goto classification_done_001998e0;
        default:
            goto result_invalid_001998e0;
        }
    }
result_invalid_001998e0:
    result = -1;
classification_done_001998e0:
    signedResult = (s64)(s16)result;
    if (signedResult == -1) {
        return 1;
    }
    if (kind == 1) {
        id = ((BtlUnit *)unit)->charId;
        offset = id * 0xE8;
        base = (s32)iGpffffb3cc;
        offset = offset + base;
        index = (s16)result;
        classRecord = (BtlUnitEnemyRecord *)(u8 *)(s32)byteAddressAdd(index * 4, (u8 *)(offset));
        finalResult = classRecord->hitClasses[0].classValue;
        goto function_done_001998e0;
    }
    finalResult = 1;
function_done_001998e0:
    return finalResult;
}

/* measured: the hit ordinal is s64 and motion is u16; with propagation off, retail keeps the entry
 * mask and indexes the table late with an unsigned halfword. */
#pragma opt_propagation off
// FUN_001999F0
s16 btlUnitMotionHitFrames(u8 *unit, u16 motion, f32 rate, s64 hitOrdinal)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    u16 index;
    s16 motionClass;
    u8 type;
    s64 value;
    s64 mappedMotion;
    s32 numerator;
    s16 denominator;
    s32 offset;
    s32 base;
    u16 tableIndex;

    type = ((BtlUnit *)unit)->genus;
    if (type == 1) {
        index = motion & 0xFFFF;
        switch (index) {
        case 4:
        case 5:
        case 6:
        case 7:
            motionClass = ((s64)(s16)(0));
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    } else {
        index = motion & 0xFFFF;
        switch (index) {
        case 5:
            motionClass = ((s64)(s16)(0));
            goto classification_done_001999f0;
        case 6:
        case 7:
            motionClass = ((s64)(s16)(1));
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    }
result_invalid_001999f0:
    motionClass = ((s64)(s16)(-1));
classification_done_001999f0:
    if (motionClass == -1) {
        return 0;
    }
    switch (type) {
    case 1:
        {
            value = ((s64)(s16)(btlFormationLookupSlot(unit, motion)));
        }
        switch (value) {
        case -1:
            goto lookup_001999f0;
        default:
            goto finish_001999f0;
        }
    case 0:
    case 2:
lookup_001999f0:
        type = typedUnit->genus;
        mappedMotion = btlUnitExtendSignedHalfword(
            ((u8 (*)[0x1E])D_005F6CA0)[type][(u16)motion]);
        if ((((BtlUnit *)unit)->stateFlags & 0x100) &&
            (type == 0) &&
            (((BtlUnit *)unit)->charId == 1) &&
            (index == 1)) {
            mappedMotion = ((s64)(s16)(0x1C));
        }
        goto value_done_001999f0;
    default:
        value = 0;
        goto finish_001999f0;
    }
value_done_001999f0:
    value = ((s64)(s16)(mappedMotion));
finish_001999f0:
    if (typedUnit->genus == 1) {
        {
            s64 product;
            offset = ((BtlUnit *)unit)->charId * 0xE8;
            base = (s32)iGpffffb3cc;
            offset = ((offset) + (base));
            offset = (s32)byteAddressAdd((s32)(s16)motionClass * 4, (u8 *)(offset));
            numerator = ((BtlUnitEnemyRecord *)(u8 *)offset)->hitClasses[0].hitInterval;
            product = (s64)(s16)(numerator * (s16)hitOrdinal);
            /* Retail normalizes the requested motion again at this lookup,
             * independently of the earlier classification/override mapping. */
            numerator = (s32)product +
                        ((BtlMotionRate *)(u8 *)(*(s32 *)&((BtlUnit *)unit)->motionRates +
                                        (s32)((u32)motion % 0x10000U) * 0xA))->unk0;
            product = (s64)(s16)numerator;
            numerator = (s32)product;
        }
    } else {
        offset = ((BtlUnit *)unit)->charId * 0x14C;
        base = (s32)iGpffffb3c0;
        offset = ((offset) + (base));
        offset = (s32)byteAddressAdd((s32)motionClass * 0x12, (u8 *)(offset));
        offset = (s32)byteAddressAdd((s32)(u16)hitOrdinal * 2, (u8 *)(offset));
        numerator = ((BtlUnitPartyRecord *)(u8 *)offset)->hitIntervals[0];
    }
    base = (s32)((BtlUnit *)unit)->motionRates;
    denominator = ((BtlMotionRate *)(u8 *)(s32)byteAddressAdd((s16)value * 0xA, (u8 *)(base)))->rate;
    return (s16)(s32)((f32)numerator /
                      (rate * ((f32)denominator / 100.0f)));
}

/* Select the opening mode from skill flags, battle state, or the calculated skill element. */
// FUN_00199D00
#pragma push
s32 btlUnitOpeningMotionMode(s32 unused, u8 *unit, s16 skill, s32 openingMode)
{
    s32 skillId;
    u32 offset;
    u16 skillFlags;
    s64 skillElement;
    s16 element;

    skillId = (s64)(s16)skill;
    if (skillId == -1 || skillId >= 0x1B8)
        return 1;
    if (btlTargetIsEntryActive(skill) != 0) {
        offset = (u32)skillId << 2;
        skillFlags = *(u16 *)((u32)iGpffffb3bc + MEMBER_OFFSET(BtlSkillFlags, flags) + offset);
        if ((skillFlags & 0x200) == 0) {
            if ((openingMode == 0) || ((skillFlags & 1) == 0)) {
                return 1;
            }
            return 2;
        }
        if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) != 0 &&
            openingMode == 0) {
            return 1;
        }
        return 0;
    }
    skillElement = datCalcSkillElement((u8 *)((BtlUnit *)unit)->datUnit, (u16)skill);
    element = (s16)skillElement;
    switch (element) {
    case 0x10:
    case 0x11:
        return 1;
    default:
        return 3;
    }
}

#pragma pop
// FUN_00199E50
void btlUnitHoldPendingAnim(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* Apply a valid packet motion request; values outside the thirty-motion domain are ignored. */
// FUN_00199E70
u32 btlUnitPlayMotionPacketUpdate(void *workData)
{
    u8 *packet = (u8 *)workData;
    s16 motion;
    s32 frame;
    f32 rate;
    u16 option;

    motion = ((BtlUnitMotionPacket *)packet)->motion;
    if (motion >= 0 && motion < 0x1E) {
        workData = ((BtlUnitMotionPacket *)packet)->unit;
        frame = ((BtlUnitMotionPacket *)packet)->frame;
        rate = ((BtlUnitMotionPacket *)packet)->rate;
        option = ((BtlUnitMotionPacket *)packet)->option;
        btlUnitSetMotion((u8 *)workData, motion, frame, rate, option);
    }
    return 1;
}

// FUN_00199EC0
void btlUnitReleasePendingAnim(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}


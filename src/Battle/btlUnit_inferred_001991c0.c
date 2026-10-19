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
extern s32 datCalcSkillElement(u8 *data, u16 value);
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


/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *btlUnitAddRecordOffset(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 btlUnitAddOffsetToBase(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *btlUnitOffsetWordTable(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 btlUnitAddBaseToOffset(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 btlUnitOne(void)
{
    return 1;
}
static inline s64 btlUnitExtendSignedHalfword(s16 value)
{
    return value;
}
static inline s32 btlUnitMotionTableAddress(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 btlUnitAddProgress(f32 left, f32 right)
{
    return left + right;
}
static inline void btlUnitStoreListEndpoint(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    /* offset selects a genus-list endpoint; retain byte addressing for the retail operand-order helper. */
    *(u8 **)(address + offset) = stored;
}

extern f32 mdlGetLayerWeight(s32 data, s32 value);
extern void mdlSetLayerTime(void *data, s32 value, f32 option);
static inline void btlUnitSetMotionOrdered(s16 value, u8 *data, u16 option, f32 rate, u16 flags)
{
    btlUnitSetMotion(data, value, option, rate, flags);
}
static inline void btlUnitStartProcedureOrdered(s32 option, s32 data, s32 value, s32 rate)
{
    scrStartProcedureChecked(data, value, option, rate);
}
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 data, s32 value);
extern s32 iGpffffb444;

static inline void btlUnitInitChildOrdered(u16 value, u8 *data)
{
    btlUnitInitChild(data, value);
}
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 001991c0-00199ec0 */

/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
#pragma push
#pragma pop
/* measured: opt_propagation off is scoped to func_001990d0. */
/* measured: closes opt_propagation around func_001990d0. */
// FUN_001991C0
/* measured: typing the initial genus load or the remaining table-pointer load changes MATCH to MISMATCH. */
/* Return motion-table frames divided by the requested and per-motion playback rates. */
s16 btlUnitMotionFrames(u8 *unit, u16 motion, f32 rate)
{
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
        result = btlUnitExtendSignedHalfword(btlFormationLookupSlot(unit, motion));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(unit + 0xA2);
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
    result = btlUnitExtendSignedHalfword(value);
finish:
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        entry = (u8 *)btlUnitAddBaseToOffset(
            (s32)motionId * 10, (s32)*(u8 **)(unit + 0x9F8));
        return (s64)(s32)((f32)((BtlMotionRate *)entry)->unk0 /
            (rate * ((f32)((BtlMotionRate *)entry)->rate / 100.0f)));
    }
    return 0;
}

// FUN_00199350
/* measured: typing the initial genus load or the remaining table-pointer load changes MATCH to MISMATCH. */
/* Return the scaled follow-up interval; a negative table interval yields zero. */
s16 btlUnitMotionFollowFrames(u8 *unit, u16 motion, f32 rate)
{
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
        result = btlUnitExtendSignedHalfword(btlFormationLookupSlot(unit, motion));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(unit + 0xA2);
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
    result = btlUnitExtendSignedHalfword(value);
finish:
{
    s32 motionId;
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        entry = (u8 *)btlUnitAddBaseToOffset(
            (s32)motionId * 10, (s32)*(u8 **)(unit + 0x9F8));
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

// FUN_00199500
/* measured: typing the initial genus load changes MATCH to MISMATCH; the later genus access is typed. */
/* Read model animation length and scale it by the available motion-table playback rate. */
s16 btlUnitMotionModelFrames(u8 *unit, u16 motion, f32 rate)
{
    extern f32 mdlGetLayerKeyTime(s32 unit, s32 motion, s64 rate);
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
        result = btlUnitExtendSignedHalfword(btlFormationLookupSlot(unit, motion));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(unit + 0xA2);
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
    result = btlUnitExtendSignedHalfword(value);
finish:
    modelFrames = mdlGetLayerKeyTime((s32)((BtlUnit *)unit)->layerHandle, 0, result);
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        entry = (u8 *)btlUnitAddBaseToOffset(
            motionId * 10, (s32)(u8 *)((BtlUnit *)unit)->motionRates);
        return (s64)(s32)(modelFrames /
            (rate * ((f32)((BtlMotionRate *)entry)->rate / 100.0f)));
    }
    return (s64)(s32)modelFrames;
}

// FUN_001996D0
/* measured: typing the initial genus load changes MATCH to MISMATCH; the later genus access is typed. */
/* Resolve the final halfword of a motion row, defaulting to six when unavailable. */
s16 btlUnitGetMotionTableFrames(u8 *unit, u16 motion)
{
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
        result = btlUnitExtendSignedHalfword(btlFormationLookupSlot(unit, motion));
        switch (result) {
        case -1:
            goto compute;
        default:
            goto finish;
        }
    case 0:
    case 2:
compute:
        type = *(u8 *)(unit + 0xA2);
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
    result = btlUnitExtendSignedHalfword(value);
finish:
    motionId = (s32)(s16)result;
    if (motionId < ((BtlUnit *)unit)->motionCount) {
        entry = (u8 *)btlUnitAddBaseToOffset(
            motionId * 10, (s32)(u8 *)((BtlUnit *)unit)->motionRates);
        return ((BtlMotionRate *)entry)->unk8;
    }
    return 6;
}

// FUN_00199830
s64 btlUnitModelAnimFrame(u8 *unit) {
    if (((BtlUnit *)unit)->flags2 & 2) {
        return (s64)(s16)(s32)mdlGetLayerWeight((s32)((BtlUnit *)unit)->layerHandle, 0);
    }
    return 0;
}

// FUN_00199890
void btlUnitSetModelAnimFrame(u8 *unit, s32 frame)
{
    if ((((BtlUnit *)unit)->flags2 & 2) != 0)
        mdlSetLayerTime(((BtlUnit *)unit)->layerHandle, 0, (f32)frame);
}

/* measured: opt_propagation off is scoped to func_001998e0. */
// FUN_001998E0
/* The 0xE8-stride formation records lack a complete shared layout; keep the signed class-value access at +0x1A. */
/* Classify the requested motion and read the formation-specific class value when applicable. */
s32 btlUnitMotionClassValue(u8 *unit, s32 motion)
{
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
        finalResult = *(s16 *)((u8 *)btlUnitAddBaseToOffset(
            index * 4, offset) + 0x1A);
        goto function_done_001998e0;
    }
    finalResult = 1;
function_done_001998e0:
    return finalResult;
}

/* measured: closes opt_propagation around func_001998e0. */
/* Measured: the hit ordinal is s64 and motion is u16. Propagation off
   retains the entry mask and the late unsigned-halfword table index. */
/* measured: func_001999f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001999F0
/* measured: remaining genus/table spelling changes lose MATCH; mixed 0xE8/0x14C formation hit records remain partial. */
/* Resolve the hit interval for a motion class and ordinal, then apply playback-rate scaling. */
s16 btlUnitMotionHitFrames(u8 *unit, u16 motion, f32 rate, s64 hitOrdinal)
{
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
            motionClass = btlUnitExtendSignedHalfword(0);
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    } else {
        index = motion & 0xFFFF;
        switch (index) {
        case 5:
            motionClass = btlUnitExtendSignedHalfword(0);
            goto classification_done_001999f0;
        case 6:
        case 7:
            motionClass = btlUnitExtendSignedHalfword(1);
            goto classification_done_001999f0;
        default:
            goto result_invalid_001999f0;
        }
    }
result_invalid_001999f0:
    motionClass = btlUnitExtendSignedHalfword(-1);
classification_done_001999f0:
    if (motionClass == -1) {
        return 0;
    }
    switch (type) {
    case 1:
        {
            value = btlUnitExtendSignedHalfword(btlFormationLookupSlot(unit, motion));
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
        type = *(u8 *)(unit + 0xA2);
        mappedMotion = btlUnitExtendSignedHalfword(
            *(u8 *)((u8 *)D_005F6CA0 + type * 0x1E + (u16)motion));
        if ((((BtlUnit *)unit)->stateFlags & 0x100) &&
            (type == 0) &&
            (((BtlUnit *)unit)->charId == 1) &&
            (index == 1)) {
            mappedMotion = btlUnitExtendSignedHalfword(0x1C);
        }
        goto value_done_001999f0;
    default:
        value = 0;
        goto finish_001999f0;
    }
value_done_001999f0:
    value = btlUnitExtendSignedHalfword(mappedMotion);
finish_001999f0:
    if (*(u8 *)(unit + 0xA2) == 1) {
        {
            s64 product;
            offset = ((BtlUnit *)unit)->charId * 0xE8;
            base = (s32)iGpffffb3cc;
            offset = btlUnitAddBaseToOffset(offset, base);
            offset = btlUnitAddBaseToOffset(
                (s32)(s16)motionClass * 4, offset);
            numerator = *(s16 *)((u8 *)offset + 0x1C);
            product = (s64)(s16)(numerator * (s16)hitOrdinal);
            /* Retail normalizes the requested motion again at this lookup,
             * independently of the earlier classification/override mapping. */
            numerator = (s32)product +
                        *(s16 *)((u8 *)(*(s32 *)(unit + 0x9F8) +
                                        (s32)((u32)motion % 0x10000U) * 0xA));
            product = (s64)(s16)numerator;
            numerator = (s32)product;
        }
    } else {
        offset = ((BtlUnit *)unit)->charId * 0x14C;
        base = (s32)iGpffffb3c0;
        offset = btlUnitAddBaseToOffset(offset, base);
        offset = btlUnitAddBaseToOffset(
            (s32)motionClass * 0x12, offset);
        offset = btlUnitAddBaseToOffset(
            (s32)(u16)hitOrdinal * 2, offset);
        numerator = *(s16 *)((u8 *)(offset + 0x1A));
    }
    base = (s32)((BtlUnit *)unit)->motionRates;
    denominator = *(s16 *)((u8 *)(btlUnitAddBaseToOffset(
        (s16)value * 0xA, base) + 2));
    return (s16)(s32)((f32)numerator /
                      (rate * ((f32)denominator / 100.0f)));
}

/* Measured: 336B/336B, nd 0. Keep the full-width ID for the predicate;
   scoped propagation preserves the staged unsigned table offset. */
// FUN_00199D00
/* Skill flag rows are four bytes with flags at +2; their full layout is unresolved, so retain the halfword table read. */
/* Select the opening mode from skill flags, battle state, or the calculated skill element. */
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
        skillFlags = *(u16 *)((u32)iGpffffb3bc + 2U + offset);
        if ((skillFlags & 0x200) == 0) {
            if ((openingMode == 0) || ((skillFlags & 1) == 0)) {
                return 1;
            }
            return 2;
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x200000) != 0 &&
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

// FUN_00199E70
/* Apply a valid packet motion request; values outside the thirty-motion domain are ignored. */
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


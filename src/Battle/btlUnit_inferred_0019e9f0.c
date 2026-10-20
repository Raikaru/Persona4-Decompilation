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
#include "datPersona_internal.h"
#include "datUnit_internal.h"
#include "btl_unit_look_internal.h"
#include "btl_unit_record_internal.h"
#include "dat_skill_entry_internal.h"
typedef RwV3d P4_95730_Vec3;
typedef struct P4_95730_Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} P4_95730_Vec4;
typedef struct P4_95730_Bytes4 {
    u8 x;
    u8 y;
    u8 z;
    u8 w;
} P4_95730_Bytes4;
typedef struct DatUnit DatUnit;

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac; /* active battle context */
extern u8 *iGpffffb3b8; /* skill table, DatSkillEntry rows */
extern s32 btlActionAnyTargetHitRowFlagged(u8 *action);
extern s32 btlTargetIsEntryActive(s16 context);
extern u8 *iGpffffb3c0; /* party visual records, stride 0x14C */
extern u8 *iGpffffb3cc; /* enemy visual records, stride 0xE8 */


extern u8 *iGpffff9db0;
extern u8 *D_0076449C; /* active battle context */
extern u8 *iGpffffb3ac; /* active battle context */
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0; /* child visual records, stride 0x58 */
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

extern s32 datCalcIsDead(u8 *unit, s32 hpDelta);
extern s32 iGpffffb3b0;
extern s32 iGpffffb284;
extern s32 iGpffffb280;
extern u8 iGpffffa0a0;
extern u8 D_005F6BE0[];
extern u8 D_007F17B0[];
extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter,
                         f32 *outTop, f32 *outBottom, u32 options);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern void RtQuatTransformVectors(void *out, const void *in, s32 count,
                          const void *quat);
extern P4_95730_Vec3 D_0060A0D0;
extern f32 fGpffff82d0;
extern f32 fGpffff811c;
extern f32 fGpffff8198;
extern f32 fGpffff82d8;
extern f32 fGpffff82d4;
extern f32 fGpffff80f0;
extern f32 fGpffff82dc;
extern f32 fGpffff8048;
extern u8 D_0060A0E0[];
extern P4_95730_Vec3 D_0060A100;
extern u8 *(*D_008873E8[])(s32 arg0, s32 arg1);


/* Retail computes the unit record address as index-times-stride plus base;
   MWCCPS2 emits a commutative addu in the order the operands reach it, so the
   order has to come from an inline's parameter list. */
static inline u8 *p4_unit_00195530(s32 offset, u8 *base)
{
    return (u8 *)(offset + (s32)base);
}
static inline s32 p4_base_add_0019f050(s32 offset, s32 base)
{
    return base + offset;
}
static inline s32 *p4_entries_001900a0(s32 offset, s32 *base)
{
    return (s32 *)((s32)base + offset);
}
static inline s32 p4_base_add_00194590(s32 offset, s32 base)
{
    return offset + base;
}
static inline u8 p4_one_00194470(void)
{
    return 1;
}
static inline s64 p4_sign16_001991c0(s16 value)
{
    return value;
}
static inline s32 p4_table_001951f0(s32 modeOffset, s32 charOffset,
                                    s32 base)
{
    return modeOffset + charOffset + base;
}
static inline f32 p4_add_0019a680(f32 left, f32 right)
{
    return left + right;
}
static inline void p4_d550_store(u8 *value, u8 *base, u32 index, u32 offset)
{
    u8 *address;
    u8 *stored;

    stored = value;
    address = base;
    address = (u8 *)((u32)(index << 3) + (u32)(address, address));
    *(u8 **)(address + offset) = stored;
}

static inline void p4_call_00198920(s16 arg1, u8 *arg0, u16 arg2, f32 arg3, u16 arg4)
{
    btlUnitSetMotion(arg0, arg1, arg2, arg3, arg4);
}
static inline void p4_call_0029db50(s32 arg2, s32 arg0, s32 arg1, s32 arg3)
{
    scrStartProcedureChecked(arg0, arg1, arg2, arg3);
}
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlLookAtSetupSetRange(void *model, float pitchLimit, float yawLimit);
extern f32 DAT_0076112c;



extern u8 *btlUnitCreate(s32 genus);
extern void btlUnitInitFromRecord(u8 *unit, s32 characterId);



extern s32 datPersonaNamePart1(s16 unitId);
extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 datPersonaNamePart1Alt(s16 unitId);
extern s32 iGpffffb444;
extern s32 btlUnitIsMoving(u8 *unit);
extern s32 btlUnitIdleAnimTick(u8 *action);
extern u8 *btlUnitCreateLookAtPacket(u8 *unit, f32 *targetPos, s32 flags);
extern s32 datCalcIsLowHp(u8 *unit);
extern u8 *btlUnitCreateAnimPacket(u8 *unit, s32 id, s32 blendFrameCount, s32 speed, f32 mode);
extern s32 datPersonaGetRosterSlot(s32 unitId);
extern void btlActionSetState(u8 *action, u32 state);
extern void func_001b08d0(void *);
extern void btlActionSetUnit(u8 *action, u8 *unit);
extern u8 *btlActionCreate(void);
extern s32 btlActionQueuePush(u8 *action);
extern s32 btlUnitApplyEncounterRoster(u8 *action);
extern s32 datCalcEnemyHasExtendedFlag(u8 *unit);
extern void btlUnitInitChild(u8 *unit, u16 characterId);
extern void btlUnitApplyBodySizeScale(u8 *unit);

static inline void p4_call_0019ef30(u16 arg1, u8 *arg0)
{
    btlUnitInitChild(arg0, arg1);
}
extern void btlUnitHoldPendingLookAt(u8 *context);
extern s32 btlUnitLookAtSidePacketUpdate(u8 *work);
extern void btlUnitReleasePendingLookAt(u8 *context);
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019e9f0-0019ff60 */

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
#pragma push
#pragma pop
/* Measured: 1164 instruction bytes in the 1168-byte window, three resolved
 * relocations and a four-byte zero tail. This callback uses the packet creator's
 * u32 (void *) contract. Modes 1..4 initialize every timing value; the retail
 * constructor callers use modes 3 or 4. The packet is 20 bytes.
 * Disabling propagation locally retains the alpha result's memory/merge
 * lifetime. Publication remains the actual four-byte color-by-value operation. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale (0x3B808081, written here as a
 * literal) for every factor; with default optimisation b210 does the same.
 * `v41` and `chk` are function-scope locals so they keep retail's saved
 * registers. On the `i == 2 && alpha < 0xFE` path retail compares 0xE8
 * against the `mode` left from an earlier entry (0x0019CDE0); the C reads
 * `mode` uninitialised there in the same way. */
#pragma push
#pragma pop
/* measured: opt_propagation off plus named call_angle locals preserve retail's stack reloads before mdlLookAtSetupSetRange. */
#pragma push
/* measured: restore pragma state after func_0019df20. */
#pragma pop
// FUN_0019E9F0
u8 *btlUnitCreateLookAtSidePacket(u8 *unit, s16 sideFlags)
{
    /* Create a side-mask look-at refresh packet and its pending-work hooks. */
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x11A, 8);
    *(void **)&((BtlPacket *)packet)->initFunc = (void *)btlUnitHoldPendingLookAt;
    *(void **)&((BtlPacket *)packet)->updateFunc = (void *)btlUnitLookAtSidePacketUpdate;
    *(void **)&((BtlPacket *)packet)->destroyFunc = (void *)btlUnitReleasePendingLookAt;
    work = *(u8 **)&((BtlPacket *)packet)->workData;
    ((BtlUnitLookSideWork *)work)->unit = unit;
    *(s16 *)&((BtlUnitLookSideWork *)work)->flags = sideFlags;

    return packet;
}

// FUN_0019EA60
void btlUnitInitFromRecord(u8 *unit, s32 characterId)
{
    /* measured: repeated typed datUnit loads hoist unit+0xA64;
     * subsequent data-pointer reloads preserve byte aliasing. */
    /* Initialize visual scale, bounds and motion rows from the genus-specific record. */
    extern void btlUiInitSpritePair(u8 *task, u8 *work);
    u8 *data;
    f32 height;
    f32 radius;
    f32 partyScale;
    f32 enemyScale;
    f32 childScale;
    u16 recordId;
    s32 partyOffset;
    s32 enemyOffset;
    s32 childOffset;
    u16 partyScalePercent;
    u16 enemyScalePercent;
    u16 childScalePercent;
    u16 radiusValue;
    u16 heightValue;
    u8 genus;
    u8 *unitData;

    recordId = characterId & 0xFFFF;
    ((BtlUnit *)unit)->charId = characterId;
    genus = ((BtlUnit *)unit)->genus;
    switch (genus) {
    case 0:
        *(s16 *)&((DatUnit *)(*(u8 **)&((BtlUnit *)unit)->datUnit))->id = recordId;
        datUnitInit((DatUnit *)*(u8 **)(unit + 0xA64), 0, recordId);
        partyOffset = characterId * 0x14C;
        partyScalePercent = ((BtlUnitPartyRecord *)((u8 *)((u32)partyOffset + (u32)iGpffffb3c0)))->scalePercent;
        partyScale = (f32)(u32)partyScalePercent;
        ((BtlUnit *)unit)->scale = partyScale / 100.0f;
        *(s32 *)&((BtlUnit *)unit)->flags2 |= 4;
        data = iGpffffb3c0 + partyOffset;
        *(u8 **)&((BtlUnit *)unit)->motionRates = iGpffffb3c0 + partyOffset + 0x3C;
        *(s16 *)&((BtlUnit *)unit)->motionCount = 0x1B;
        if ((u32)(characterId - 3) < 3U) {
            unitData = *(u8 **)(unit + 0xA64);
            ((DatUnit *)unitData)->flags |= 0x1000;
        }
        break;
    case 1:
        *(s16 *)&((DatUnit *)(*(u8 **)(unit + 0xA64)))->id = recordId;
        enemyOffset = characterId * 0xE8;
        enemyScalePercent = ((BtlUnitEnemyRecord *)((u8 *)((u32)enemyOffset + (u32)iGpffffb3cc)))->scalePercent;
        enemyScale = (f32)(u32)enemyScalePercent;
        ((BtlUnit *)unit)->scale = enemyScale / 100.0f;
        *(s32 *)&((BtlUnit *)unit)->flags2 |= 4;
        data = iGpffffb3cc + enemyOffset;
        *(u8 **)&((BtlUnit *)unit)->motionRates = iGpffffb3cc + enemyOffset + 0x2A;
        *(s16 *)&((BtlUnit *)unit)->motionCount = 0x13;
        break;
    case 2:
        childOffset = characterId * 0x58;
        childScalePercent = ((BtlUnitChildRecord *)((u8 *)((u32)childOffset + (u32)iGpffffb3e0)))->scalePercent;
        childScale = (f32)(u32)childScalePercent;
        ((BtlUnit *)unit)->scale = childScale / 100.0f;
        *(s32 *)&((BtlUnit *)unit)->flags2 |= 4;
        data = iGpffffb3e0 + childOffset + 2;
        *(u8 **)&((BtlUnit *)unit)->motionRates = iGpffffb3e0 + childOffset + 0x1A;
        *(s16 *)&((BtlUnit *)unit)->motionCount = 6;
        break;
    case 3:
    default:
        break;
    }
    ((BtlUnit *)unit)->sphereCenter.x = (f32)(s16)*(s16 *)&((BtlUnitBoundsRecord *)data)->x;
    ((BtlUnit *)unit)->sphereCenter.y = (f32)(s16)*(s16 *)&((BtlUnitBoundsRecord *)data)->y;
    ((BtlUnit *)unit)->sphereCenter.z = (f32)(s16)*(s16 *)&((BtlUnitBoundsRecord *)data)->z;
    heightValue = ((BtlUnitBoundsRecord *)data)->height;
    height = (f32)(u32)heightValue;
    ((BtlUnit *)unit)->unk_8c = height;
    radiusValue = ((BtlUnitBoundsRecord *)data)->radius;
    radius = (f32)(u32)radiusValue;
    ((BtlUnit *)unit)->sphereRadius = radius;
    btlUiInitSpritePair(unit, ((BtlUnit *)unit)->unk_a10);
}

// FUN_0019EDA0
u8 *btlUnitGetRecordPtr(u8 *unit, s32 motion)
{
    /* Select normal or alternate bounds according to motion and DOWN status. */
    s32 characterId;
    s32 motionIndex;
    u8 *partyRecord;
    u8 *enemyRecord;
    s32 alternateBounds;
    s32 unitData;

    characterId = ((BtlUnit *)unit)->charId;
    motionIndex = motion & 0xFFFF;
    switch (motionIndex) {
    case 9:
    case 10:
        alternateBounds = 1;
        break;
    case 2:
        unitData = *(s32 *)&((BtlUnit *)unit)->datUnit;
        if ((unitData != 0) && (datCalcChkBadStatus(unitData, 0x100000) != 0)) {
            alternateBounds = 1;
            break;
        }
    default:
        alternateBounds = 0;
    }
    switch (((BtlUnit *)unit)->genus) {
    case 0:
        if (alternateBounds != 0) {
            partyRecord = iGpffffb3c0 + characterId * 0x14C + 0xA;
        } else {
            partyRecord = iGpffffb3c0 + characterId * 0x14C;
        }
        return partyRecord;
    case 1:
        if (alternateBounds != 0) {
            enemyRecord = iGpffffb3cc + characterId * 0xE8 + 0xA;
        } else {
            enemyRecord = iGpffffb3cc + characterId * 0xE8;
        }
        return enemyRecord;
    case 2:
        return iGpffffb3e0 + characterId * 0x58 + 2;
    default:
        return NULL;
    }
}

// FUN_0019EF30
void btlUnitInitChild(u8 *unit, u16 characterId) {
    /* measured: typed childUnit reloads hoist unit+0xA0C and change five words;
     * retain the post-allocation byte-addressed accesses. */
    /* Create the optional child unit lazily, then initialize its character record. */
    extern void btlUnitInitFromRecord(u8 *unit, u16 characterId);
    if (*(u8 **)&((BtlUnit *)unit)->childUnit == NULL) {
        *(u8 **)(unit + 0xA0C) = btlUnitCreate(2);
    }
    btlUnitInitFromRecord(*(u8 **)(unit + 0xA0C), characterId);
}

// FUN_0019EF90
/* measured: opt_propagation off reproduces ef90's retail address setup order. */
/* measured: func_0019ef90 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
u8 *btlUnitFindInSideById(s32 genus, s32 characterId)
{
    /* Walk one genus list backward to find a matching character id. */
    u8 *base;
    u8 *unit;
    u32 address;

    base = iGpffffb3ac;
    genus = (u16)genus;
    address = (u32)p4_unit_00195530((u16)genus * 8, base) + 0x17C;
    unit = *(u8 **)address;
    characterId = (u16)characterId;
    while (unit != NULL) {
        if (((BtlUnit *)unit)->charId == characterId) {
            return unit;
        }
        unit = *(u8 **)&((BtlUnit *)unit)->prevUnit;
    }
    return NULL;
}

/* measured: closes opt_propagation around ef90. */
/* measured: func_0019f050, func_0019f0f0, func_0019f5f0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_0019EFE0
u8 *btlUnitFindById(s32 unitId)
{
    /* Search all four genus lists for the unit id. */
    u8 *unit;
    u8 *battle;
    u32 genusIndex;

    genusIndex = 0;
    battle = iGpffffb3ac;
    unitId = (u16)unitId;
    for (; genusIndex < 4; genusIndex++) {
        unit = ((BtlBattleState *)battle)->unitLists[genusIndex * 2 + 1];
        while (unit != NULL) {
            if (*(s32 *)&((BtlUnit *)unit)->id == unitId) {
                return unit;
            }
            unit = *(u8 **)&((BtlUnit *)unit)->prevUnit;
        }
    }
    return NULL;
}

// FUN_0019F050
s32 btlUnitGetDataRow(u8 *unit)
{
    /* Return the genus-specific character/persona data row. */
    u16 id;
    u8 genus;
    s32 result;

    result = 0;
    id = ((BtlUnit *)unit)->charId;
    genus = ((BtlUnit *)unit)->genus;
    switch (genus) {
    case 0:
        result = datPersonaNamePart1Alt((s16)id);
        break;
    case 1:
        result = p4_base_add_0019f050((u32)id * 0x15,
                                      (s32)iGpffffb444);
        break;
    case 2:
        result = (s32)datPersonaGetRow(id);
        break;
    default:
        break;
    }
    return result;
}

/* Identical body to btlUnitGetDataRow (its type-0 callee datPersonaNamePart1 has the same
 * body as datPersonaNamePart1Alt); a separate retail function at its own address. */
// FUN_0019F0F0
s32 btlUnitGetDataRowAlt(u8 *unit)
{
    u16 id;
    u8 genus;
    s32 result;

    result = 0;
    id = ((BtlUnit *)unit)->charId;
    genus = ((BtlUnit *)unit)->genus;
    switch (genus) {
    case 0:
        result = datPersonaNamePart1((s16)id);
        break;
    case 1:
    case 2:
        result = 0;
        switch (genus) {
        case 0:
            result = datPersonaNamePart1Alt((s16)id);
            break;
        case 1:
            result = p4_base_add_0019f050((u32)id * 0x15,
                                          (s32)iGpffffb444);
            break;
        case 2:
            result = (s32)datPersonaGetRow(id);
            break;
        default:
            break;
        }
        break;
    default:
        break;
    }
    return result;
}

#pragma push
/* measured: func_0019f1d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* measured: func_0019f1d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* measured: func_0019f1d0 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_0019F1D0
void btlUnitApplyBodySizeScale(u8 *unit)
{
    /* Scale eligible units into a size band, choosing a factor from the unit id low bits. */
    extern u8 *iGpffffb3c4;
    u8 *resource;
    f32 radius;
    f32 height;
    f32 minRadius;
    f32 minHeight;
    f32 factor;
    f32 lower;
    f32 scale;
    f32 upper;
    f32 lowerHeight;
    f32 upperHeight;
    u16 band;
    s32 bound;

    if (((BtlUnit *)unit)->genus == 1) {
        resource = *(u8 **)&((BtlUnit *)unit)->datUnit;
        if (resource != NULL &&
            (((BtlUnitBodySizeRecord *)(iGpffffb3c4 + ((DatUnit *)resource)->id * 0x3C))->flags & 0x8000)) {
            return;
        }
    }

    scale = ((BtlUnit *)unit)->scale;
    radius = (f32)(s32)(((BtlUnit *)unit)->sphereRadius * scale);
    height = (f32)(s32)(((BtlUnit *)unit)->unk_8c * scale);
    lowerHeight = 200.0f;
    if (!(radius <= lowerHeight) || !(height <= 400.0f) ||
        radius < 50.0f || height < 100.0f) {
        return;
    }

    if (height <= lowerHeight) {
        if (radius <= 75.0f) {
            band = 0;
        } else if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= lowerHeight) {
            band = 2;
        }
    } else if (height <= 300.0f) {
        if (radius <= 125.0f) {
            band = 1;
        } else if (radius <= lowerHeight) {
            band = 2;
        }
    } else {
        band = 2;
    }

    switch (band) {
    case 0:
        minRadius = 50.0f;
        minHeight = 100.0f;
        upper = 74.0f;
        lower = 199.0f;
        break;
    case 1:
        minRadius = 76.0f;
        minHeight = 201.0f;
        upper = 124.0f;
        bound = 299;
        lower = (f32)bound;
        break;
    case 2:
        minRadius = 126.0f;
        bound = 301;
        minHeight = (f32)bound;
        upper = 199.0f;
        bound = 399;
        lower = (f32)bound;
        break;
    }

    if (!(upper <= radius)) {
        upper = upper / radius;
    } else {
        upper = 1.0f;
    }
    if (!(lower <= height)) {
        upperHeight = lower / height;
    } else {
        upperHeight = 1.0f;
    }
    upper = upper < upperHeight ? upper : upperHeight;

    if (minRadius < radius) {
        lower = minRadius / radius;
    } else {
        lower = -1.0f;
    }
    if (minHeight < height) {
        lowerHeight = minHeight / height;
    } else {
        lowerHeight = -1.0f;
    }
    upperHeight = 0.0f;
    if (!(lower <= upperHeight) && !(lowerHeight <= upperHeight)) {
        lower = lower > lowerHeight ? lower : lowerHeight;
    } else {
        lower = 1.0f;
    }

    switch (((BtlUnit *)unit)->id & 3) {
    case 0:
        factor = upper;
        break;
    case 1:
        factor = (0.0f + lower) + 0.5f * (upper - lower);
        break;
    case 2:
        factor = lower;
        break;
    case 3:
        factor = 1.0f;
        break;
    }
    ((BtlUnit *)unit)->scale = factor * scale;
    ((BtlUnit *)unit)->flags2 |= 4;
}

#pragma pop
// FUN_0019F5F0
u8 *btlActionCreateWork(s32 genus, u16 characterId, u16 *unitData)
{
    /* measured: repeated typed action flags retain action+0x1A in a temporary;
     * later flag accesses preserve the original byte-addressed shape. */
    /* Create and enqueue a party or enemy action with its unit and encounter flags. */
    s32 unitGenus;
    s32 partyFlags;
    s32 partyFlagsWithForty;
    s32 partyFlagsWithEighty;
    s32 partyFlagsWithTwoHundred;
    s32 enemyFlags;
    s32 enemyFlagsWithHundred;
    s32 enemyFlagsWithForty;
    u8 *actionUnit;
    u8 *action;
    u8 *unit;

    action = NULL;
    unitGenus = genus & 0xFFFF;
    switch (unitGenus) {
    case 0:
        unit = btlUnitCreate(0);
        action = btlActionCreate();
        btlActionSetUnit(action, unit);
        btlActionQueuePush(action);
        func_001b08d0(action);
        btlActionSetState(action, 1);
        if ((characterId & 0xFFFF) == 1) {
            *(s16 *)&((BtlAction *)action)->state = 5;
            ((BtlBattleState *)iGpffffb3ac)->selectedAction = action;
        }
        p4_call_0019ef30(((DatPersonaRecord *)datPersonaGetRecord(characterId))->id,
                         unit);
        /* The roster-slot pointer aliases hit-row storage at +0x3F0 during creation;
         * the shared action layout does not yet describe that union. */
        *(s32 *)(action + 0x3F0) = datPersonaGetRosterSlot((s16)characterId);
        ((BtlAction *)action)->unk_1a |= 0x10;
        break;
    case 1:
        unit = btlUnitCreate(1);
        action = btlActionCreate();
        btlActionSetUnit(action, unit);
        btlActionQueuePush(action);
        func_001b08d0(action);
        btlActionSetState(action, 1);
        break;
    default:
        break;
    }
    if (unitData != NULL) {
        *(u16 **)&((BtlUnit *)unit)->datUnit = unitData;
        btlUnitInitFromRecord(unit, (u16)(characterId & 0xFFFF));
        if (unitGenus == 1 &&
            (*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0) {
            btlUnitApplyBodySizeScale(unit);
        }
        if (datCalcIsDead((u8 *)unitData, 0) != 0) {
            *(s32 *)&((BtlUnit *)unit)->flags3 |= 1;
        }
    }
    actionUnit = *(u8 **)&((BtlAction *)action)->unit;
    *(s32 *)&((BtlUnit *)actionUnit)->flags3 |= 8;
    *(u16 *)(action + 0x1A) |= 8;
    switch (unitGenus) {
    case 0:
        *(u16 *)(action + 0x1A) |= 0x200;
        partyFlags = *(s32 *)&((BtlUnit *)unit)->flags3 | 0x20;
        *(s32 *)&((BtlUnit *)unit)->flags3 = partyFlags;
        partyFlagsWithForty = partyFlags | 0x40;
        *(s32 *)&((BtlUnit *)unit)->flags3 = partyFlagsWithForty;
        partyFlagsWithEighty = partyFlagsWithForty | 0x80;
        *(s32 *)&((BtlUnit *)unit)->flags3 = partyFlagsWithEighty;
        partyFlagsWithTwoHundred = partyFlagsWithEighty | 0x200;
        *(s32 *)&((BtlUnit *)unit)->flags3 = partyFlagsWithTwoHundred;
        *(s32 *)&((BtlUnit *)unit)->flags3 = partyFlagsWithTwoHundred | 0x4000;
        break;
    case 1:
        if (unitData != NULL && datCalcEnemyHasExtendedFlag((u8 *)unitData) != 0) {
            enemyFlags = *(s32 *)&((BtlUnit *)unit)->flags3 | 0x20;
            *(s32 *)&((BtlUnit *)unit)->flags3 = enemyFlags;
            enemyFlagsWithHundred = enemyFlags | 0x100;
            *(s32 *)&((BtlUnit *)unit)->flags3 = enemyFlagsWithHundred;
            enemyFlagsWithForty = enemyFlagsWithHundred | 0x40;
            *(s32 *)&((BtlUnit *)unit)->flags3 = enemyFlagsWithForty;
            *(s32 *)&((BtlUnit *)unit)->flags3 = enemyFlagsWithForty | 0x400;
        }
        break;
    default:
        break;
    }
    btlUnitApplyEncounterRoster(action);
    return action;
}

// FUN_0019F8A0
s32 btlUnitIdleAnimTick(u8 *action)
{
    /* measured: repeated typed timer/unit accesses save action+0x24/+0x30
     * in extra registers (436B versus the 416B window); retain those reloads. */
    /* Count down an idle animation delay, refusing unavailable or nonresting units. */
    s32 remainingFrames;
    u16 *unitData;

    if (((BtlAction *)action)->idleWeaponAnimTimer < 0) {
        *(s32 *)(action + 0x24) = (effMiscRand(0) % 240U) + 0x78;
    }
    remainingFrames = *(s32 *)(action + 0x24);
    if (remainingFrames == 0) {
        if (btlUnitIsAtRestMotion(*(u8 **)&((BtlAction *)action)->unit) == 0) {
            return 0;
        }
        if (datCalcChkBadStatus(*(s32 *)&((BtlUnit *)(*(u8 **)(action + 0x30)))->datUnit,
                          0x100000) != 0) {
            return 0;
        }
        if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(action + 0x30) + 0xA64),
                          0xFFFFF) != 0) {
            return 0;
        }
        unitData = *(u16 **)(*(u8 **)(action + 0x30) + 0xA64);
        if ((*unitData & 0x200) != 0) {
            return 0;
        }
        if (datCalcIsLowHp((u8 *)unitData) != 0 ||
            datCalcIsDead(*(u8 **)(*(u8 **)(action + 0x30) + 0xA64), 0) != 0) {
            return 0;
        }
        if ((s16)btlUnitModelAnimFrame(*(u8 **)(action + 0x30)) < 4) {
            btlPacketEnqueue(btlUnitCreateAnimPacket(*(u8 **)(action + 0x30),
                                         0x11, 4, 0, 1.0f),
                          0);
            *(s32 *)(action + 0x24) = -1;
        }
        return 1;
    }
    *(s32 *)(action + 0x24) = remainingFrames - 1;
    return 0;
}

// FUN_0019FA40
void btlUnitTickIdleAnims(void)
{
    /* Tick idle animations for active party actions in states 1 or 5. */
    u16 flags;
    u16 state;
    u8 *unit;
    u8 *action;

    action = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (action != NULL) {
        flags = ((BtlAction *)action)->unk_1a;
        if ((flags & 0x200) != 0 && (flags & 1) != 0) {
            unit = *(u8 **)&((BtlAction *)action)->unit;
            if ((*(s32 *)&((BtlUnit *)unit)->flags3 & 8) != 0 &&
                btlUnitIsMoving(unit) == 0) {
                state = ((BtlAction *)action)->currState;
                switch (state) {
                case 1:
                case 5:
                    btlUnitIdleAnimTick(action);
                    break;
                default:
                    break;
                }
            }
        }
        action = *(u8 **)&((BtlAction *)action)->next;
    }
}

// FUN_0019FAF0
void btlUnitRequestLookAtOthers(u8 *excludedAction)
{
    /* measured: repeated typed datUnit loads retain unit+0xA64 across calls;
     * subsequent data-pointer reloads remain byte-addressed. */
    /* Request look-at packets for eligible party actions except the supplied action. */
    f32 anchorPosition[3];
    u16 state;
    u8 *action;
    u8 *unit;

    action = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (action != NULL) {
        if ((((BtlAction *)action)->unk_1a & 1) != 0) {
            unit = *(u8 **)&((BtlAction *)action)->unit;
            if ((*(s32 *)&((BtlUnit *)unit)->flags3 & 8) != 0 &&
                btlUnitIsAtRestMotion(unit) != 0 &&
                btlUnitIsMoving(unit) == 0 &&
                datCalcChkBadStatus(*(s32 *)&((BtlUnit *)unit)->datUnit, 0x100000) == 0 &&
                datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0xFFFFF) == 0 &&
                datCalcIsLowHp(*(u8 **)(unit + 0xA64)) == 0 &&
                datCalcIsDead(*(u8 **)(unit + 0xA64), 0) == 0) {
                state = ((BtlAction *)action)->currState;
                switch (state) {
                case 1:
                case 5:
                    if (excludedAction != action) {
                        btlUnitGetAnchorPose(unit, NULL, NULL, anchorPosition);
                        btlPacketEnqueue(btlUnitCreateLookAtPacket(unit, anchorPosition, 0), 1);
                    }
                    break;
                default:
                    break;
                }
            }
        }
        action = *(u8 **)&((BtlAction *)action)->next;
    }
}

// FUN_0019FC60
void btlUnitNoop(void) {
    /* Empty retail hook; no side effects. */
}

/* measured: opt_propagation off with named table pointers preserves retail load order. */
#pragma push
/* measured: func_0019fc70 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0019FC70
s32 btlActionSkillReachesTargets(u8 *action)
{
    /* measured: repeated typed unit loads save action+0x30 in s2
     * (508B versus the 496B window); retain the later unit reload. */
    /* measured: early returns replace the shared return blocks and give nd 283
     * (484B in the 496B window); retain the explicit dispatch/return branches. */
    /* Check target classification and per-character attack/skill exclusions. */
    u16 skillId;
    u16 characterId;
    s32 skillIndex;
    u16 result;
    u8 *unit;

    skillId = ((BtlAction *)action)->unk_6e;
    result = (u16)btlSkillClassifyTargets(action, NULL, skillId, 0);
    unit = *(u8 **)&((BtlAction *)action)->unit;
    characterId = ((DatUnit *)(*(u8 **)&((BtlUnit *)unit)->datUnit))->id;
    if (result != 0)
        goto result_zero_0019fc70;

    skillIndex = skillId & 0xFFFF;
    if ((((DatSkillEntry *)iGpffffb3b8)[skillIndex].flags00 & 2) != 0) {
        switch (((BtlUnit *)unit)->genus) {
        case 1:
            goto type_one_0019fc70;
        default:
            goto result_one_0019fc70;
        }
type_one_0019fc70:
        if (btlActionAnyTargetHitRowFlagged(action) != 0) {
            {
                u8 *table18;
                table18 = iGpffffb3cc;
                if ((((BtlUnitEnemyRecord *)p4_unit_00195530((u16)characterId * 0xE8, table18))->flags &
                     0x100) != 0) {
                    return 1;
                }
            }
        }
        {
            u8 *table22;
            table22 = iGpffffb3cc;
            if (((BtlUnitEnemyRecord *)p4_unit_00195530((u16)characterId * 0xE8, table22))->unk22 == 1)
                return 0;
        }
result_one_0019fc70:
        return 1;
    }
    if (btlTargetIsEntryActive((s16)skillId) != 0) {
        {
            u8 *flagsTable;
            flagsTable = (u8 *)iGpffffb3bc;
            if ((((BtlSkillFlags *)p4_unit_00195530(skillIndex * 4, flagsTable))->flags & 1) == 0)
                return 0;
        }
        /* Deliberately write case 0 before case 1: MWCC tests the last-written case first. */
        switch (((BtlUnit *)(*(u8 **)(action + 0x30)))->genus) {
        case 0:
        default:
            goto second_default_0019fc70;
        case 1:
            goto second_type_one_0019fc70;
        }
second_type_one_0019fc70:
        {
            u8 *table26;
            table26 = iGpffffb3cc;
            if (((BtlUnitEnemyRecord *)p4_unit_00195530((u16)characterId * 0xE8, table26))->unk26 == 1)
                return 0;
        }
second_default_0019fc70:
        return 1;
    }
result_zero_0019fc70:
    return 0;
}

#pragma pop
/* measured: opt_propagation off is scoped to func_0019fe60. */
/* measured: func_0019fe60 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0019FE60
s32 btlUnitIsUnavailable(u8 *action, s32 skillId, s32 allowStatus)
{
    /* Reject status- or record-excluded units for the supplied skill. */
    u16 characterId;
    u8 *unit;
    u8 *unitData;
    u8 *table;
    u8 *table2;
    u8 kind;
    u8 status;

    unit = *(u8 **)&((BtlAction *)action)->unit;
    unitData = *(u8 **)&((BtlUnit *)unit)->datUnit;
    characterId = ((DatUnit *)unitData)->id;
    kind = ((BtlUnit *)unit)->genus;
    switch (kind) {
    case 0:
        status = datCalcGetCharacterTableKind(unitData);
        if (status == 5) {
            return 1;
        }
        if (status == 3) {
            table = (u8 *)iGpffffb3bc;
            if ((((BtlSkillFlags *)p4_unit_00195530((skillId & 0xFFFF) * 4, table))->flags &
                 0x8000) != 0 ||
                allowStatus == 0) {
                return 1;
            }
        }
        break;
    case 1:
        table2 = iGpffffb3cc;
        if (((BtlUnitEnemyRecord *)p4_unit_00195530((characterId & 0xFFFF) * 0xE8, table2))->unk22 == 1) {
            return 1;
        }
        break;
    default:
        break;
    }
    return 0;
}

/* measured: closes opt_propagation around func_0019fe60. */
/* measured: func_0019ff60 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// FUN_0019FF60
s32 btlActionCanFollowUpAfterEnemiesDown(u8 *action)
{
    /* measured: repeated typed unit/datUnit loads retain +0x30/+0xA64
     * across calls (492B versus the 480B window); retain those reloads. */
    /* Collect available party follow-up actions when every surviving enemy is DOWN. */
    u8 *selectedAction;
    u8 *entry;
    u8 *unit;
    u16 enemyCount;

    selectedAction = ((BtlBattleState *)iGpffffb3ac)->selectedAction;
    if (datCalcIsDead(*(u8 **)&((BtlUnit *)(*(u8 **)&((BtlAction *)selectedAction)->unit))->datUnit, 0) != 0 ||
        datCalcChkBadStatus(*(s32 *)&((BtlUnit *)(*(u8 **)(selectedAction + 0x30)))->datUnit,
                       0x100117) != 0) {
        return 0;
    }
    if (((BtlUnit *)(*(u8 **)&((BtlAction *)action)->unit))->genus == 1 &&
        datCalcIsDead(*(u8 **)&((BtlUnit *)(*(u8 **)(action + 0x30)))->datUnit, 0) != 0) {
        return 0;
    }
    ((BtlBattleState *)iGpffffb3ac)->partyActionCount = 0;
    enemyCount = 0;
    entry = ((BtlBattleState *)iGpffffb3ac)->actions;
    for (; entry != NULL; entry = *(u8 **)&((BtlAction *)entry)->next) {
        if ((((BtlAction *)entry)->unk_1a & 1) == 0) continue;
        unit = *(u8 **)&((BtlAction *)entry)->unit;
        if ((*(s32 *)&((BtlUnit *)unit)->flags3 & 8) == 0 ||
            datCalcIsDead(*(u8 **)&((BtlUnit *)unit)->datUnit, 0) != 0) continue;
        if (((BtlUnit *)unit)->genus == 1) {
            if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000) == 0) return 0;
            enemyCount++;
        } else if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100117) == 0 &&
                   selectedAction != entry) {
            ((BtlBattleState *)iGpffffb3ac)->partyActions[((BtlBattleState *)iGpffffb3ac)->partyActionCount] = entry;
            (((BtlBattleState *)iGpffffb3ac)->partyActionCount)++;
        }
    }
    if (enemyCount == 0) return 0;
    return ((BtlBattleState *)iGpffffb3ac)->partyActionCount >= 1;
}


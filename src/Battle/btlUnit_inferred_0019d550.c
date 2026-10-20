#include "btl_unit_packet_internal.h"
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

extern void (*D_00887300[])(s32 data, s32 value);
extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac;
extern u8 *iGpffffb3b8;
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

static inline void btlUnitSetMotionOrdered(s16 value, u8 *data, u16 option, f32 rate, u16 flags)
{
    btlUnitSetMotion(data, value, option, rate, flags);
}
static inline void btlUnitStartProcedureOrdered(s32 option, s32 data, s32 value, s32 rate)
{
    scrStartProcedureChecked(data, value, option, rate);
}
extern u8 iGpffffa4d8;
extern void btlCameraSetUnitSlotValue(u8 *unit, s32 slotIndex, s32 slotValue);
extern void btlTargetRemoveRadiusNode(u8 *unit);
extern void btlEffectDestroyPlacementEntry(s32 placement);
extern void btlEffectFreeNodePool(s32 pool);
extern void btlUnitUnlinkAndFree(u8 *incomingUnit);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

static inline void btlUnitInitChildOrdered(u16 value, u8 *data)
{
    btlUnitInitChild(data, value);
}
extern void (*jtbl_008873EC[])(void *data);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitReleaseModel(u8 *unit);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019d550-0019d550 */

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
/* measured: typing the remaining pool clear or the two saved list-link loads changes MATCH to MISMATCH. */
/* Release owned resources, detach radius/camera state, unlink the genus list and free the unit. */
// FUN_0019D550
void btlUnitUnlinkAndFree(u8 *incomingUnit)
{
    BtlUnit *typedUnit;
    u8 *unit;
    u8 genus;
    s32 placement;
    s32 nodePool;
    s8 cameraSlot;
    u8 *next;
    u8 *previous;
    u8 *child;

    unit = incomingUnit;
    typedUnit = (BtlUnit *)unit;
    genus = ((BtlUnit *)incomingUnit)->genus;
    btlUnitReleaseModel(unit);
    child = (u8 *)((BtlUnit *)unit)->childUnit;
    if (child != NULL)
        btlUnitUnlinkAndFree(child);
    placement = ((BtlUnitResources *)(unit + 0xA04))->placement;
    if (placement != 0) {
        btlEffectDestroyPlacementEntry(placement);
        ((BtlUnitResources *)(unit + 0xA04))->placement = 0;
    }
    nodePool = ((BtlUnitResources *)(unit + 0xA04))->nodePool;
    if (nodePool != 0) {
        btlEffectFreeNodePool(nodePool);
        *(s32 *)&((BtlUnit *)unit)->effectNodePool = 0;
    }
    btlTargetRemoveRadiusNode(unit);
    cameraSlot = ((BtlUnit *)unit)->cameraSlot;
    if (cameraSlot >= 0)
        btlCameraSetUnitSlotValue(unit, cameraSlot, 0);
    next = *(u8 * *)&typedUnit->nextUnit;
    if (next != NULL)
        ((BtlUnit *)next)->prevUnit = ((BtlUnit *)unit)->prevUnit;
    else
        btlUnitStoreListEndpoint((u8 *)((BtlUnit *)unit)->prevUnit, iGpffffb3ac,
                      (u32)genus & 0xFF, 0x17C);
    previous = *(u8 * *)&typedUnit->prevUnit;
    if (previous != NULL)
        ((BtlUnit *)previous)->nextUnit = ((BtlUnit *)unit)->nextUnit;
    else
        btlUnitStoreListEndpoint((u8 *)((BtlUnit *)unit)->nextUnit, iGpffffb3ac,
                      (u32)genus & 0xFF, 0x178);
    jtbl_008873EC[0](unit);
}


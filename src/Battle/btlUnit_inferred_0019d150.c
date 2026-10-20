#include "member_access.h"
#include "btl_unit_movement_internal.h"
#include "mdl_file_internal.h"
#include "btl_effect_internal.h"
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

extern void memset(void *data, s32 value, s32 option);

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
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;



extern u8 *btlUnitCreate(s32 genus);



extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

static inline void btlUnitInitChildOrdered(u16 value, u8 *data)
{
    btlUnitInitChild(data, value);
}
extern void chkmemAllocSiteTag(void *file, s32 line);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern void mdlQueueModelForDraw(void *queue, void *model);
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019d150-0019d210 */

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
/* Queue visible, nontransparent models unless their model flags suppress drawing. */
// FUN_0019D150
void btlUnitQueueAllModelsForDraw(void)
{
    u8 *model;
    u8 *node;
    u32 i;

    for (i = 0; i < 4; i++) {
        node = ((BtlBattleState *)iGpffffb3ac)->unitLists[i * 2 + 1];
        while (node != NULL) {
            if ((((BtlUnit *)node)->flags2 & 2) != 0 &&
                (((BtlUnit *)node)->flags3 & 2) != 0 &&
                ((BtlUnit *)node)->cols[0].alpha > 0) {
                model = ((BtlUnit *)node)->layerHandle;
                if ((((MdlFileModel *)model)->flags & 0x20) == 0) {
                    mdlQueueModelForDraw(D_00794150, model);
                }
            }
            node = (u8 *)((BtlUnit *)node)->prevUnit;
        }
    }
}

/* measured: typing the remaining genus/camera-slot accesses loses MATCH; list address helpers preserve retail operand order. */
/* Allocate a 0xA70-byte unit, initialize movement/model state, and append it to its genus list. */
// FUN_0019D210
u8 *btlUnitCreate(s32 genus)
{
    BtlUnit *typedUnit;
    f32 movementRate;
    s32 battleAddress;
    s32 listOffset;
    u32 unitId;
    u8 *unit;
    u8 *tail;

    chkmemAllocSiteTag(D_005F6D10, 0x3A);
    unit = (u8 *)D_008873E8[0](0xA70, 0x40000);
    typedUnit = (BtlUnit *)unit;
    memset(unit, 0, 0xA70);
    ((BtlUnit *)unit)->genus = genus;
    if (iGpffffa0a8 >= 0x0FFFFFFFU) {
        iGpffffa0a8 = 1;
    }
    unitId = iGpffffa0a8;
    iGpffffa0a8 = unitId + 1;
    ((BtlUnit *)unit)->id = unitId;
    btlPacketResetUnit(unit);
    ((BtlUnit *)unit)->unk_8c = 150.0f;
    ((BtlUnit *)unit)->sphereRadius = 50.0f;
    ((BtlUnit *)unit)->sphereCenter.x = 0.0f;
    ((BtlUnit *)unit)->sphereCenter.y = 0.5f * ((BtlUnit *)unit)->unk_8c;
    ((BtlUnit *)unit)->sphereCenter.z = 0.0f;
    ((BtlUnitMovement *)(unit + 0xC4))->activity = 0;
    ((BtlUnitMovement *)(unit + 0xC4))->speed = 27.0f;
    if (typedUnit->genus == 0) {
        movementRate = 10.0f;
    } else {
        movementRate = 14.0f;
    }
    ((BtlUnitMovement *)(unit + 0xC4))->unk430 = 0.5f * movementRate;
    ((BtlUnit *)unit)->motionRate = 1.0f;
    /* Negative camera slots have no camera ownership to release. */
    ((BtlUnit *)unit)->cameraSlot = -1;
    ((BtlUnitResources *)(unit + 0xA04))->placement = btlEffectCreatePlacementEntry(unit);
    ((BtlUnitResources *)(unit + 0xA04))->nodePool = btlEffectAllocNodePool();
    ((BtlUnit *)unit)->prevUnit = NULL;
    listOffset = (genus & 0xFF) * 8;
    battleAddress = (s32)iGpffffb3ac;
    tail = *(u8 **)((u8 *)btlUnitOffsetWordTable(
        MEMBER_OFFSET(BtlBattleState, unitLists[0]), (s32 *)battleAddress) + listOffset);
    if (tail != NULL) {
        ((BtlUnit *)tail)->prevUnit = (BtlUnit *) unit;
        ((BtlUnit *)unit)->nextUnit = (BtlUnit *)
            ((BtlBattleState *)((u8 *)btlUnitAddBaseToOffset(
                listOffset, (s32)iGpffffb3ac)))->unitLists[0];
    } else {
        ((BtlBattleState *)((u8 *)btlUnitAddBaseToOffset(
            listOffset, battleAddress)))->unitLists[1] = unit;
        ((BtlUnit *)unit)->nextUnit = NULL;
    }
    ((BtlBattleState *)((u8 *)btlUnitAddBaseToOffset(
        listOffset, (s32)iGpffffb3ac)))->unitLists[0] = unit;
    return unit;
}


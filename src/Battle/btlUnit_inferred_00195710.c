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

extern void btlUnitOverridePacketUpdate(u8 *packet);

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






extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00195710-00195730 */

extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s64 btlPacketEnqueue(u8 *context, u32 value);
extern void btlPacketStepSide(s32 side);
extern void btlUnitHoldPendingOverride(u8 *context);
/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
// FUN_00195710
void btlUnitReleasePendingOverride(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}

/* measured: access-site flag updates change MATCH to MISMATCH; a distinct typed work alias retains all three flag updates. */
/* Create an override work block; bits 1/2/4 identify supplied position, quaternion and color. */
// FUN_00195730
u8 *btlUnitCreateOverridePacket(u8 *unit, u8 *position, u8 *rotation, u8 *color)
{
    BtlUnitOverridePacket *workFields;
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x11C, 0x28);
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlUnitHoldPendingOverride;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlUnitOverridePacketUpdate;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingOverride;
    work = (u8 *)((BtlPacket *)packet)->workData;
    workFields = (BtlUnitOverridePacket *)work;
    ((BtlUnitOverridePacket *)work)->unit = unit;
    ((BtlUnitOverridePacket *)work)->flags = 0;
    if (position != NULL) {
        ((BtlUnitOverridePacket *)work)->position = *(RwV3d *)position;
        workFields->flags |= 1;
    }
    if (rotation != NULL) {
        ((BtlUnitOverridePacket *)work)->rotation = *(RtQuat *)rotation;
        workFields->flags |= 2;
    }
    if (color != NULL) {
        ((BtlUnitOverridePacket *)work)->color = *(RwRGBA *)color;
        workFields->flags |= 4;
    }
    return packet;
}


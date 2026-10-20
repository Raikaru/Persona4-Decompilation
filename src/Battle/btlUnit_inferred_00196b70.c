#include "btl_unit_movement_internal.h"
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



/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00196b70-001973d0 */

extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s64 btlPacketEnqueue(u8 *context, u32 value);
extern void btlPacketStepSide(s32 side);
extern void btlTargetResetWork(void *work);
extern s32 btlRouteFindPath(u8 *route, f32 *start, f32 *end, f32 radius);
extern s32 btlRouteBuildArc(u8 *route, const f32 *startXZ, const f32 *endXZ, const f32 *centerXZ);
extern f32 RwV3dNormalize(f32 *data, f32 *value);
/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
// FUN_00196B70
void btlUnitClearMoveFlags(u8 *unit) {
    ((BtlUnit *)unit)->stateFlags &= ~1;
    ((BtlUnit *)unit)->movementFlags &= ~BTLUNIT_MOVEMENTFLAGS_MOVE;
}

// FUN_00196BA0
void btlUnitClearRotateFlags(u8 *unit) {
    ((BtlUnit *)unit)->stateFlags &= ~2;
    ((BtlUnit *)unit)->movementFlags &= ~BTLUNIT_MOVEMENTFLAGS_ROTATE;
}

/* measured: access-site scale typing changes MATCH to MISMATCH; a distinct typed unit alias preserves the final reload. */
/* Combine the scaled motion-table distance with the target anchor or bounding sphere fallback. */
// FUN_00196BD0
f32 btlUnitGetMotionDistance(u8 *unit, u8 *target, u16 motion)
{
    BtlUnit *unitFields = (BtlUnit *)unit;
    f32 distance;
    f32 anchorHeight;
    u8 *table;
    s32 motionId;

    motionId = (s16)btlUnitGetMotionId(unit, motion);
    if (motionId < (s32)((BtlUnit *)unit)->motionCount) {
        table = (u8 *)((BtlUnit *)unit)->motionRates;
        distance = ((BtlUnit *)unit)->scale *
                   (f32)((BtlMotionRate *)btlUnitAddBaseToOffset(
                       motionId * 0xA, (s32)(table, table)))->unk6;
        anchorHeight = btlUnitGetActionAnchorHeight(unit, target, motion);
        if (!(anchorHeight < 0.0f)) {
            distance += anchorHeight;
            goto add_base_00196bd0;
        }
        distance += ((BtlUnit *)target)->sphereRadius * ((BtlUnit *)target)->scale;
        distance += ((BtlUnit *)target)->sphereCenter.z * ((BtlUnit *)target)->scale;
add_base_00196bd0:
        distance += ((BtlUnit *)unit)->sphereCenter.z *
                    unitFields->scale;
    } else {
        distance = 0.0f;
    }
    return distance;
}

// FUN_00196CE0
void btlUnitHoldPendingMove(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* The vector snapshot preserves all three coordinates before flattening Y.
   Separate vector/pair objects retain their natural stack lifetimes. Native
   proof: 1736 executable bytes, ten resolved calls, 150 unchanged siblings. */
/* measured: distinct typed unit/work aliases preserve scalar accesses that moved instructions with access-site fields. */
/* Advance direct or routed movement; completion waits until both move and rotate activity clear. */
// FUN_00196D00
u32 btlUnitMovePacketUpdate(void *workData)
{
    BtlUnit *unitFields;
    BtlUnitMovePacket *packetWorkFields;
    union MovementVector {
        RwV3d vector;
        f32 values[3];
    } direction;
    union MovementVector flatTarget;
    union MovementVector position;
    f32 routeStart[2];
    f32 routeEnd[2];
    f32 routeCenter[2];
    u8 *packetWork;
    u8 *unit;
    u16 state;
    s32 flags;
    u16 workState;
    s32 mask;
    u8 active;
    u8 *work;
    u16 index;

    packetWork = (u8 *)workData;
    packetWorkFields = (BtlUnitMovePacket *)packetWork;
    unit = ((BtlUnitMovePacket *)packetWork)->unit;
    unitFields = (BtlUnit *)unit;
    flags = ((BtlUnitMovePacket *)packetWork)->flags;
    if ((flags & 8) != 0) {
        state = ((BtlUnitMovePacket *)packetWork)->state;
        switch (state) {
        case 0:
            if ((flags & 0x10) != 0) {
                btlUnitGetAnchorPose(unit, (u8 *)position.values, NULL, NULL);
                ((BtlUnitMovePacket *)packetWork)->destination = position.vector;
            }
            ((BtlUnitMovePacket *)packetWork)->state = ((BtlUnitMovePacket *)packetWork)->state + 1;
            /* fallthrough */
        case 1:
            btlTargetResetWork(unit + 0xEC);
            ((BtlUnit *)unit)->stoppingDistance = ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
            ((BtlUnit *)unit)->stateFlags = packetWorkFields->flags;
            ((BtlUnitMovement *)(unit + 0xC4))->speed = 2.0f * (13.5f * ((BtlUnitMovePacket *)packetWork)->speed);
            if ((((BtlUnit *)unit)->stateFlags & 1) == 0) {
                ((BtlTargetRoute *)(unit + 0xEC))->points[0].x = ((BtlUnit *)unit)->pos.x;
                ((BtlTargetRoute *)(unit + 0xEC))->points[0].z = ((BtlUnit *)unit)->pos.z;
                ((BtlTargetRoute *)(unit + 0xEC))->points[1].x = ((BtlUnitMovePacket *)packetWork)->destination.x;
                ((BtlTargetRoute *)(unit + 0xEC))->points[1].z = ((BtlUnitMovePacket *)packetWork)->destination.z;
                ((BtlTargetRoute *)(unit + 0xEC))->count = 2;
                ((BtlUnit *)unit)->movementFlags &= 0xFFDF;
                ((BtlUnit *)unit)->movementFlags |= 1;
                ((BtlUnit *)unit)->movementFlags |= 0x10;
                direction.values[0] = ((BtlUnit *)unit)->pos.x - ((BtlUnitMovePacket *)packetWork)->destination.x;
                direction.values[1] = ((BtlUnit *)unit)->pos.y - ((BtlUnitMovePacket *)packetWork)->destination.y;
                direction.values[2] = ((BtlUnit *)unit)->pos.z - ((BtlUnitMovePacket *)packetWork)->destination.z;
                direction.values[1] = 0.0f;
                RwV3dNormalize(direction.values, direction.values);
                direction.values[0] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                direction.values[1] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                direction.values[2] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                ((BtlUnit *)unit)->moveDestination.x = packetWorkFields->destination.x + direction.values[0];
                ((BtlUnit *)unit)->moveDestination.y = packetWorkFields->destination.y + direction.values[1];
                ((BtlUnit *)unit)->moveDestination.z = packetWorkFields->destination.z + direction.values[2];
            } else {
                if (packetWorkFields->stoppingDistance != 0.0f) {
                    direction.values[0] = ((BtlUnit *)unit)->pos.x - ((BtlUnitMovePacket *)packetWork)->destination.x;
                    direction.values[1] = ((BtlUnit *)unit)->pos.y - ((BtlUnitMovePacket *)packetWork)->destination.y;
                    direction.values[2] = ((BtlUnit *)unit)->pos.z - ((BtlUnitMovePacket *)packetWork)->destination.z;
                    direction.values[1] = 0.0f;
                    RwV3dNormalize(direction.values, direction.values);
                    direction.values[0] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                    direction.values[1] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                    direction.values[2] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                    position.values[0] = packetWorkFields->destination.x + direction.values[0];
                    position.values[1] = packetWorkFields->destination.y + direction.values[1];
                    position.values[2] = packetWorkFields->destination.z + direction.values[2];
                } else {
                    position.vector = ((BtlUnitMovePacket *)packetWork)->destination;
                }
                position.values[1] = ((BtlUnit *)unit)->pos.y;
                ((BtlUnit *)unit)->pos = position.vector;
                ((BtlUnit *)unit)->flags2 |= 4;
                unitFields->stateFlags &= ~1;
                ((BtlUnit *)unit)->movementFlags &= 0xFFDF;
                ((BtlUnit *)unit)->movementFlags &= 0xFFFE;
                ((BtlUnit *)unit)->movementFlags &= 0xFFEF;
                ((BtlUnit *)unit)->moveDestination = position.vector;
            }
            ((BtlUnitMovePacket *)packetWork)->state = ((BtlUnitMovePacket *)packetWork)->state + 1;
            goto done;
        case 2:
            workState = ((BtlUnit *)unit)->movementFlags;
            mask = workState & 1;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            mask = workState & 2;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            return 1;
        default:
            goto done;
        }
    } else {
        state = ((BtlUnitMovePacket *)packetWork)->state;
        switch (state) {
        case 0:
            if ((flags & 0x10) != 0) {
                btlUnitGetAnchorPose(unit, (u8 *)position.values, NULL, NULL);
                ((BtlUnitMovePacket *)packetWork)->destination = position.vector;
            }
            ((BtlUnitMovePacket *)packetWork)->state = ((BtlUnitMovePacket *)packetWork)->state + 1;
            /* fallthrough */
        case 1:
            btlTargetResetWork(unit + 0xEC);
            ((BtlUnit *)unit)->stoppingDistance = ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
            ((BtlUnit *)unit)->stateFlags = packetWorkFields->flags;
            ((BtlUnitMovement *)(unit + 0xC4))->speed = 2.0f * (13.5f * ((BtlUnitMovePacket *)packetWork)->speed);
            routeStart[0] = ((BtlUnit *)unit)->pos.x;
            routeStart[1] = ((BtlUnit *)unit)->pos.z;
            routeEnd[0] = packetWorkFields->destination.x;
            routeEnd[1] = ((BtlUnitMovePacket *)packetWork)->destination.z;
            if ((packetWorkFields->flags & 0x80) == 0) {
                btlRouteFindPath(unit + 0xEC, routeStart, routeEnd, 50.0f);
            } else {
                btlUnitGetGroupBounds(3, 1, &position.vector, NULL, NULL, 1);
                routeCenter[0] = position.values[0];
                routeCenter[1] = position.values[2];
                btlRouteBuildArc(unit + 0xEC, routeStart, routeEnd, routeCenter);
            }
            index = ((BtlTargetRoute *)(unit + 0xEC))->count;
            if (index == 0) {
                ((BtlUnit *)unit)->moveDestination = ((BtlUnitMovePacket *)packetWork)->destination;
            } else {
                /* The route tail uses a pre-offset byte cursor to preserve the indexed address helper. */
                work = (u8 *)btlUnitAddBaseToOffset(index * 8, (s32)unit);
                direction.values[0] = ((BtlTargetRoute *)(unit + 0xEC))->points[index - 2].x;
                direction.values[1] = 0.0f;
                direction.values[2] = ((BtlTargetRoute *)(unit + 0xEC))->points[index - 2].z;
                flatTarget.vector = ((BtlUnitMovePacket *)packetWork)->destination;
                flatTarget.values[1] = 0.0f;
                direction.values[0] = direction.values[0] - flatTarget.values[0];
                direction.values[1] = direction.values[1] - flatTarget.values[1];
                direction.values[2] = direction.values[2] - flatTarget.values[2];
                RwV3dNormalize(direction.values, direction.values);
                direction.values[0] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                direction.values[1] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                direction.values[2] *= ((BtlUnitMovePacket *)packetWork)->stoppingDistance;
                flatTarget.values[0] += direction.values[0];
                flatTarget.values[1] += direction.values[1];
                flatTarget.values[2] += direction.values[2];
                ((BtlUnit *)unit)->moveDestination = flatTarget.vector;
            }
            ((BtlUnitMovePacket *)packetWork)->state = ((BtlUnitMovePacket *)packetWork)->state + 1;
            /* fallthrough */
        case 2:
            workState = ((BtlTargetRoute *)(unit + 0xEC))->state;
            if (workState == 2) {
                ((BtlUnit *)unit)->movementFlags &= 0xFFDF;
                ((BtlUnit *)unit)->movementFlags |= 1;
                ((BtlUnit *)unit)->movementFlags |= 0x10;
                ((BtlUnitMovePacket *)packetWork)->state = ((BtlUnitMovePacket *)packetWork)->state + 1;
                goto done;
            } else if (workState == 3) {
                ((BtlTargetRoute *)(unit + 0xEC))->points[0].x = ((BtlUnit *)unit)->pos.x;
                ((BtlTargetRoute *)(unit + 0xEC))->points[0].z = ((BtlUnit *)unit)->pos.z;
                ((BtlTargetRoute *)(unit + 0xEC))->points[1].x = ((BtlUnitMovePacket *)packetWork)->destination.x;
                ((BtlTargetRoute *)(unit + 0xEC))->points[1].z = ((BtlUnitMovePacket *)packetWork)->destination.z;
                ((BtlTargetRoute *)(unit + 0xEC))->count = 2;
                ((BtlUnit *)unit)->movementFlags &= 0xFFDF;
                ((BtlUnit *)unit)->movementFlags |= 1;
                ((BtlUnit *)unit)->movementFlags |= 0x10;
                ((BtlUnitMovePacket *)packetWork)->state = ((BtlUnitMovePacket *)packetWork)->state + 1;
                goto done;
            }
            goto done;
        case 3:
            workState = ((BtlUnit *)unit)->movementFlags;
            mask = workState & 1;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            mask = workState & 2;
            active = (mask != 0);
            if (active != 0) {
                goto done;
            }
            return 1;
        default:
            goto done;
        }
    }
done:
    ((BtlUnitMovePacket *)packetWork)->counter += 1;
    return 0;
}

// FUN_001973D0
void btlUnitReleasePendingMove(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}


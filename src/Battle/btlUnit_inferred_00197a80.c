#include "btl_unit_movement_internal.h"
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
extern f32 func_0044b950(f32 left, f32 right);
extern f32 fGpffff8048;
extern void func_003dc740(void *dst, const void *src, s32 mode, f32 angle);
extern u8 D_0060A0E0[];
extern void btlUnitRequestLookAt(u8 *unit);
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
extern float btlFormationGetScale(int unit);
extern s32 btlUnitArcMovePacketUpdate(u8 *packetWork);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00197a80-00197f30 */

/* measured: opt_propagation off is scoped to func_001927c0. */
/* measured: closes opt_propagation around func_001927c0. */
/* measured: opt_propagation off is scoped to func_001928c0. */
/* measured: opt_loop_invariants on is scoped to func_001928c0. */
/* measured: closes opt_loop_invariants around func_001928c0. */
/* measured: closes opt_propagation around func_001928c0. */
/* measured: optimization_level 1 with the index and value locals declared
   before the loop reproduces func_00194470 exactly, object 284 bytes against
   the 288-byte window at nd 0; -O2 reorders the initialisation. */
/* measured: opt_propagation off is scoped to func_00194590. */
/* measured: closes opt_propagation around func_00194590. */
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: optimization_level 1 reproduces the retail loop initialisation order. */
/* measured: opt_propagation off keeps the per-use u8/u16 conversions and the
   named scaled index (`off = k * 6`) from being folded into one address. */
/* measured: closes the propagation bracket; the file default is on. */
/* measured: opt_propagation off preserves the COP1 chain's intermediate colouring. */
/* measured: func_00197a80 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Advance the arc displacement, or apply the indexed vertical-offset curve for the alternate mode. */
// FUN_00197A80
s32 btlUnitArcMovePacketUpdate(u8 *packetWork)
{
    u8 *unit;
    RwV3d transformed;
    RwV3d delta;
    RwV3d position;
    f32 arcHeight;
    f32 progress;
    s32 finished;
    unit = ((BtlUnitArcMovePacket *)packetWork)->unit;
    if (datCalcUsesWeaponProperties(((BtlUnitArcMovePacket *)packetWork)->mode) != 0) {
        if (((BtlUnitArcMovePacket *)packetWork)->counter == 0) {
            ((BtlUnitArcMovePacket *)packetWork)->progress = 0.5f;
            ((BtlUnitArcMovePacket *)packetWork)->start =
                ((BtlUnit *)unit)->pos;
            RtQuatTransformVectors(&transformed, &D_0060A100, 1, unit + 0x1C);
            ((BtlUnitArcMovePacket *)packetWork)->delta.x = 400.0f * transformed.x;
            ((BtlUnitArcMovePacket *)packetWork)->delta.y = 400.0f * transformed.y;
            ((BtlUnitArcMovePacket *)packetWork)->delta.z = 400.0f * transformed.z;
        }
        progress = ((BtlUnitArcMovePacket *)packetWork)->progress;
        progress += 0.03125f;
        ((BtlUnitArcMovePacket *)packetWork)->progress = progress;
        arcHeight = 0.0f + (-1.0f) +
                  ((-2.0f * progress) * progress) +
                  (4.0f * progress);
        progress = 2.0f * (arcHeight - 0.5f);
        if (progress < fGpffff82d4) {
            delta.x = ((BtlUnitArcMovePacket *)packetWork)->delta.x * progress;
            delta.y = ((BtlUnitArcMovePacket *)packetWork)->delta.y * progress;
            delta.z = ((BtlUnitArcMovePacket *)packetWork)->delta.z * progress;
            finished = 0;
        } else {
            delta = ((BtlUnitArcMovePacket *)packetWork)->delta;
            finished = 1;
        }
        position.x = ((BtlUnitArcMovePacket *)packetWork)->start.x + delta.x;
        position.y = ((BtlUnitArcMovePacket *)packetWork)->start.y + delta.y;
        position.z = ((BtlUnitArcMovePacket *)packetWork)->start.z + delta.z;
        ((BtlUnit *)unit)->pos = position;
        ((BtlUnit *)unit)->flags2 |= 4;
        ((BtlUnitArcMovePacket *)packetWork)->counter = ((BtlUnitArcMovePacket *)packetWork)->counter + 1;
        return finished;
    }
    ((BtlUnit *)unit)->posOffset.x = 0.0f;
    ((BtlUnit *)unit)->posOffset.y =
        ((BtlUnitArcMovePacket *)packetWork)->scale * D_005F6C10[((BtlUnitArcMovePacket *)packetWork)->counter];
    ((BtlUnit *)unit)->posOffset.z = 0.0f;
    ((BtlUnit *)unit)->flags2 |= 4;
    return ++((BtlUnitArcMovePacket *)packetWork)->counter >= 0x23U;
}

/* measured: restore opt_propagation after func_00197a80 FPR temporary colouring probe. */
/* Allocate arc work with the starting counter and the formation scale. */
// FUN_00197CC0
u8 *btlUnitCreateArcMovePacket(s32 unitAddress, s16 mode, s16 counter)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)btlPacketAlloc(0x10C, 0x28);
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlUnitArcMovePacketUpdate;
    work = (u8 *)((BtlPacket *)packet)->workData;
    *(s32 *)work = unitAddress;
    ((BtlUnitArcMovePacket *)work)->mode = mode;
    ((BtlUnitArcMovePacket *)work)->counter = counter;
    ((BtlUnitArcMovePacket *)work)->scale = btlFormationGetScale(unitAddress);
    return packet;
}

// FUN_00197D50
void btlUnitHoldPendingRotate(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* measured: access-site flags/counter typing changes MATCH to MISMATCH; a distinct typed packet alias preserves both accesses. */
/* Start an immediate facing change or a deferred rotation and wait for its activity bit to clear. */
// FUN_00197D70
s32 btlUnitRotatePacketUpdate(u8 *packetWork)
{
    BtlUnitRotatePacket *packetWorkFields = (BtlUnitRotatePacket *)packetWork;
    u8 *unit;
    RtQuat rotation;
    RwV3d output;
    f32 dx;
    f32 dz;
    s32 flags;
    s32 mask;
    u8 active;
    s32 result;

    unit = ((BtlUnitRotatePacket *)packetWork)->unit;
    if (((BtlUnitRotatePacket *)packetWork)->counter == 0) {
        if ((((BtlUnitRotatePacket *)packetWork)->flags & 0x1000) != 0) {
            dx = ((BtlUnitRotatePacket *)packetWork)->target.x - ((BtlUnit *)unit)->pos.x;
            dz = ((BtlUnitRotatePacket *)packetWork)->target.z - ((BtlUnit *)unit)->pos.z;
            if ((dx != 0.0f) || (dz != 0.0f)) {
                func_003dc740(&rotation, D_0060A0E0, 0,
                              fGpffff8048 * func_0044b950(dx, dz));
                if ((((BtlUnit *)unit)->flags3 & 0x2000) == 0) {
                    ((BtlUnit *)unit)->rot = rotation;
                    ((BtlUnit *)unit)->flags2 |= 4;
                }
            }
            ((BtlUnit *)unit)->stateFlags &= ~2;
            ((BtlUnit *)unit)->movementFlags &= 0xFFFD;
            btlUnitRequestLookAt(unit);
        } else {
            if ((((BtlUnitRotatePacket *)packetWork)->flags & 0x20) != 0) {
                btlUnitGetAnchorPose(unit, NULL, NULL, (f32 *)&output);
                ((BtlUnitRotatePacket *)packetWork)->target = output;
            }
            flags = packetWorkFields->flags;
            ((BtlUnitMovement *)(unit + 0xC4))->rotationTarget =
                ((BtlUnitRotatePacket *)packetWork)->target;
            ((BtlUnitMovement *)(unit + 0xC4))->unk440 = 0;
            ((BtlUnit *)unit)->stoppingDistance = 0.0f;
            ((BtlUnit *)unit)->stateFlags = flags;
            ((BtlUnit *)unit)->movementFlags |= 2;
        }
    }
    mask = ((BtlUnit *)unit)->movementFlags & 2;
    active = (mask != 0);
    if (active == 0) {
        result = 1;
    } else {
        packetWorkFields->counter += 1;
        result = 0;
    }
    return result;
}

// FUN_00197F30
void btlUnitReleasePendingRotate(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}


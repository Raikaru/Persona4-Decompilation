#include "operand_order_internal.h"
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

/* measured: optimization_level 1, with the index and value locals declared before the loop, keeps
 * retail's loop initialisation order; -O2 reorders it. */
#pragma push
#pragma pop
/* measured: the hit ordinal is s64 and motion is u16; with propagation off, retail keeps the entry
 * mask and indexes the table late with an unsigned halfword. */
#pragma push
#pragma pop
// FUN_0019A660
void btlUnitHoldPendingEnemyDodge(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* Integrate outward and return phases of a bounded dodge displacement, then clear the offset. */
// FUN_0019A680
s32 btlUnitEnemyDodgePacketUpdate(u8 *packetWork)
{
    BtlUnitDodgePacket *typedPacketWork = (BtlUnitDodgePacket *)packetWork;
    RwV3d direction;
    f32 progress;
    f32 returnProgress;
    f32 nextProgress;
    f32 nextOutProgress;
    f32 returnStep;
    f32 velocity;
    f32 offset;
    f32 distance;
    u8 *unit;

    unit = ((BtlUnitDodgePacket *)packetWork)->unit;
    distance = fGpffff811c *
             (((BtlUnit *)unit)->sphereRadius * ((BtlUnit *)unit)->scale);
    if (!(distance <= 100.0f))
        distance = 100.0f;
    if (((BtlUnitDodgePacket *)packetWork)->counter == 0) {
        ((BtlUnitDodgePacket *)packetWork)->progress = 0.0f;
        ((BtlUnitDodgePacket *)packetWork)->velocity = fGpffff8198;
    }
    velocity = ((BtlUnitDodgePacket *)packetWork)->velocity;
    if (!(velocity < 0.0f)) {
        progress = ((BtlUnitDodgePacket *)packetWork)->progress;
        nextOutProgress = (1.0f - progress) * velocity;
        typedPacketWork->velocity = velocity + fGpffff82d8;
        progress = ((BtlUnitDodgePacket *)packetWork)->progress;
        offset = distance * progress;
        nextOutProgress = operandOrderAddFloat(progress, nextOutProgress);
        ((BtlUnitDodgePacket *)packetWork)->progress = nextOutProgress;
        if (!(nextOutProgress < fGpffff82d4))
            typedPacketWork->velocity = fGpffff82dc;
        goto block_11;
    }
    returnStep = -velocity;
    returnProgress = ((BtlUnitDodgePacket *)packetWork)->progress;
    nextProgress = returnProgress * returnStep;
    returnStep = fGpffff80f0;
    typedPacketWork->velocity = velocity - returnStep;
    returnProgress = ((BtlUnitDodgePacket *)packetWork)->progress;
    offset = distance * returnProgress;
    nextProgress = returnProgress - nextProgress;
    ((BtlUnitDodgePacket *)packetWork)->progress = nextProgress;
    if (nextProgress <= returnStep) {
        if ((((BtlUnit *)unit)->flags3 & 0x400) == 0) {
            ((BtlUnit *)unit)->posOffset.x = 0.0f;
            ((BtlUnit *)unit)->posOffset.y = 0.0f;
            ((BtlUnit *)unit)->posOffset.z = 0.0f;
            ((BtlUnit *)unit)->flags2 |= 4;
        }
        return 1;
    }
block_11:
    if ((((BtlUnit *)unit)->flags3 & 0x400) == 0) {
        RtQuatTransformVectors(&direction, &D_0060A0D0, 1, unit + 0x1C);
        ((BtlUnit *)unit)->posOffset.x = direction.x * offset;
        ((BtlUnit *)unit)->posOffset.y = direction.y * offset;
        ((BtlUnit *)unit)->posOffset.z = direction.z * offset;
        ((BtlUnit *)unit)->flags2 |= 4;
    }
    typedPacketWork->counter += 1;
    return 0;
}

// FUN_0019A840
void btlUnitReleasePendingEnemyDodge(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}


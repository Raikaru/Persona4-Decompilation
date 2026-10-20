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
extern s32 btlBossRemapSkillPair();
extern void btlUnitModelLoadPacketInit(u8 *packetData);
extern s32 btlUnitModelMotionPacketUpdate();
extern void btlUnitReleaseModel(u8 *unit);
extern void btlUnitHideModel();
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 0019b530-0019b680 */

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
// FUN_0019B530
void btlUnitReleasePendingModelLoad(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}

/* Create model-load work, using the boss remap when present and genus/model defaults otherwise. */
// FUN_0019B550
u8 *btlUnitCreateModelLoadPacket(u8 *unit, u16 modelId, s16 motion)
{
    u8 *work;
    u8 *packet;

    packet = (u8 *)btlPacketAlloc(0x10F, 0x10);
    ((BtlPacket *)packet)->flags &= 0xFE;
    ((BtlPacket *)packet)->initFunc = (BtlPacketFunc)btlUnitModelLoadPacketInit;
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlUnitModelMotionPacketUpdate;
    ((BtlPacket *)packet)->destroyFunc = (BtlPacketFunc)btlUnitReleasePendingModelLoad;
    work = (u8 *)((BtlPacket *)packet)->workData;
    ((BtlUnitModelLoadPacket *)work)->unit = unit;
    ((BtlUnitModelLoadPacket *)work)->motion = motion;
    if (btlBossRemapSkillPair(unit, (s16 *)(work + 4), (s16 *)(work + 6)) == 0) {
        ((BtlUnitModelLoadPacket *)work)->genus = ((BtlUnit *)unit)->genus + 1;
        ((BtlUnitModelLoadPacket *)work)->modelId = modelId;
    }
    return packet;
}

// FUN_0019B620
void btlUnitHoldPendingModelRelease(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* Release the unit model and clear its visibility state. */
// FUN_0019B640
s32 btlUnitModelReleasePacketUpdate(u8 *packetWork) {
    u8 *unit;

    unit = ((BtlUnitPacketReference *)packetWork)->unit;
    btlUnitReleaseModel(unit);
    btlUnitHideModel(unit);
    return 1;
}

// FUN_0019B680
void btlUnitReleasePendingModelRelease(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}


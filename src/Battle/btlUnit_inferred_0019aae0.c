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
#include "btl_unit_internal.h"

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


extern f32 mdlGetLayerWeight(s32 model, s32 layer);
extern void mdlSetLayerTime(void *model, s32 layer, f32 frameValue);

extern u8 iGpffffa4d8;
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *unit, s32 mode);
extern void btlUnitApplyModelState(u8 *unit, s32 mode);


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
 * retail's initialisation order; -O2 reorders it. */
#pragma push
#pragma pop
/* measured: the hit ordinal is s64 and motion is u16; with propagation off, retail keeps the entry
 * mask and loads the unsigned-halfword table index late. */
#pragma push
#pragma pop
// FUN_0019AAE0
void btlUnitHoldPendingMotionSpeed(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + 1;
}

/* Restart the current motion with the requested rate/options while preserving its frame. */
// FUN_0019AB00
u32 btlUnitMotionSpeedPacketUpdate(void *workData)
{
    BtlUnit *typedUnit;
    u8 *packetWork = (u8 *)workData;
    u8 *unit;
    u16 frame;
    u16 option;
    f32 rate;
    s32 savedFrame;
    s16 narrowFrame;
    s16 motion;

    option = ((BtlUnitMotionSpeedPacket *)packetWork)->option;
    rate = ((BtlUnitMotionSpeedPacket *)packetWork)->rate;
    frame = ((BtlUnitMotionSpeedPacket *)packetWork)->frame;
    unit = ((BtlUnitMotionSpeedPacket *)packetWork)->unit;
    typedUnit = (BtlUnit *)unit;
    if (((BtlUnit *)unit)->flags2 & 2) {
        btlUnitClearModelState(unit, 4);
        if (*(s32 *)&typedUnit->flags2 & 2)
            narrowFrame = (s32)(s16)(s32)mdlGetLayerWeight((s32)((BtlUnit *)unit)->layerHandle, 0);
        else
            narrowFrame = 0;
        savedFrame = narrowFrame;
        /* The comma expression loads currentMotion before the unit argument is set up, matching
         * retail's order. */
        btlUnitSetMotion((unit), ((motion = ((BtlUnit *)unit)->currentMotion, motion)), (frame), (rate), (option));
        if (*(s32 *)&typedUnit->flags2 & 2)
            mdlSetLayerTime(((BtlUnit *)unit)->layerHandle, 0, (f32)savedFrame);
        btlUnitApplyModelState(unit, 4);
    }
    return 1;
}

// FUN_0019AC20
void btlUnitReleasePendingMotionSpeed(u8 *packetWork)
{
    ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount = ((BtlUnit *)((BtlUnitPacketReference *)packetWork)->unit)->pendingPacketCount + -1;
}


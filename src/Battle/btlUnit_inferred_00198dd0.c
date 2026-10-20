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
#include "btl_unit_internal.h"

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
extern s32 datCalcIsLowHp(u8 *unit);
extern s32 datCalcIsGuarding(s32 unitFlags);

extern void (*jtbl_008873EC[])(void *data);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* Choose the rest motion from status/HP/guard/death state; replace playback only when already at
 * rest. */
// FUN_00198DD0
#pragma push
void btlUnitUpdateStatusMotion(u8 *unit, u16 frame)
{
    BtlUnit *unitFields = (BtlUnit *)unit;
    s16 restMotion;
    s64 value;
    u16 motionOption;
    u16 nextMotion;
    s32 atRest;
    s32 available;
    s32 keyEmpty;
    s16 motionId;
    extern s32 mdlIsLayerKeyEmpty(u8 *model, u32 layer, s16 animation);
    extern s32 datCalcChkBadStatus();

    restMotion = 0;
    if (datCalcIsLowHp((u8 *)((BtlUnit *)unit)->datUnit) != 0) {
        if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
            motionId = (s16)(btlUnitGetMotionId(unit, 0x12) & 0xFFFF);
            if (mdlLayerHasAnimation(((BtlUnit *)unit)->layerHandle, 0, motionId) == 0) {
                available = 0;
            } else {
                keyEmpty = mdlIsLayerKeyEmpty(unitFields->layerHandle, 0, motionId);
                if (keyEmpty == 1) {
                    available = 0;
                } else {
                    available = 1;
                }
            }
        } else {
            available = 0;
        }
        if (available != 0) {
            restMotion = 0x12;
        }
    }
    if (datCalcChkBadStatus((s32)unitFields->datUnit, 0xFFFFF) != 0) {
        restMotion = 3;
    }
    if (datCalcChkBadStatus((s32)unitFields->datUnit, 0x100000) != 0) {
        restMotion = 0xA;
    }
    if (datCalcIsGuarding((s32)unitFields->datUnit) != 0) {
        restMotion = 0x18;
    }
    if (datCalcChkBadStatus((s32)unitFields->datUnit, 0x100) != 0) {
        restMotion = 0;
    }
    if ((datCalcIsDead((u8 *)unitFields->datUnit, 0) != 0) && ((((BtlUnit *)unit)->flags3 & 0x20) != 0)) {
        if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
            motionId = (s16)(btlUnitGetMotionId(unit, 0x13) & 0xFFFF);
            if (mdlLayerHasAnimation(((BtlUnit *)unit)->layerHandle, 0, motionId) == 0) {
                available = 0;
            } else {
                keyEmpty = mdlIsLayerKeyEmpty(unitFields->layerHandle, 0, motionId);
                if (keyEmpty == 1) {
                    available = 0;
                } else {
                    available = 1;
                }
            }
        } else {
            available = 0;
        }
        if (available != 0) {
            restMotion = 0x13;
        }
    }
    value = (s64)restMotion;
    if (value != 0x13) {
        motionOption = 1;
        nextMotion = *(u16 *)&((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion;
    } else {
        motionOption = 2;
        nextMotion = 0;
    }
    {
        u8 kind;
        s16 currentMotion;

        kind = ((BtlUnit *)unit)->genus;
        switch (kind) {
        case 0:
        case 1:
            if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
                currentMotion = ((BtlUnit *)unit)->currentMotion;
            } else {
                currentMotion = 0;
            }
            atRest = (s32)(((BtlUnit *)unit)->restMotion == (s16)currentMotion);
            break;
        default:
            atRest = 0;
            break;
        }
    }
    if ((atRest != 0) && ((s64)(((BtlUnit *)unit)->restMotion) != value)) {
        btlUnitSetMotion(unit, restMotion, frame, 1.0f, motionOption);
    }
    ((BtlUnit *)unit)->restMotion = restMotion;
    *(u16 *)&((BtlUnitRestMotion *)(unit + 0x9EC))->nextMotion = nextMotion;
    ((BtlUnit *)unit)->restRate = 1.0f;
    ((BtlUnit *)unit)->restOption = motionOption;
}


#pragma pop

#include "mdl_file_internal.h"
#include "btl_action_internal.h"
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

extern s32 scrStartProcedureChecked(s32 priority, s32 source, s32 size, s32 procedureIndex);
extern void mdlSetLayerWeight(u8 *model, s32 layer, f32 speed);
extern u8 iGpffffa4d8;
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern f32 DAT_0076112c;






extern s32 iGpffffb444;
extern void btlUnitInitChild(u8 *unit, u16 characterId);

extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];


extern s64 btlUnitGetMotionId(u8 *unit, u16 motion);
extern s16 btlUnitMotionFrames(u8 *unit, u16 motion, f32 rate);
extern void btlUnitSetMotion(u8 *unit, s16 motion, u16 frame, f32 rate, u16 option);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0019; members 00198380-00198380 */

extern s32 btlUnitGetMotionState(u8 *unit);
extern u32 btlUnitIsAtRestMotion(u8 *unit);
extern u32 btlUnitIsWalkingMotion(u8 *unit);
extern s64 btlUnitModelAnimFrame(u8 *unit);
static inline u32 btlUnitAddMotionOffset(u32 offset, u32 base)
{
    return offset + base;
}
/* measured: opt_propagation off is scoped to func_001949d0. */
/* measured: closes opt_propagation for func_001949d0. */
/* measured: declaration-corrected C candidate for func_00198380. */
/* Update motion-layer weight and walking/rest transitions, including completion and held-frame modes. */
/* measured: separate typed aliases retain the motion/handle reloads that moved instructions with access-site fields. */
// FUN_00198380
void btlUnitUpdateMotionLayer(u8 *unit) {
    BtlUnit *unitFields = (BtlUnit *)unit;
    f32 walkRate;
    s16 restMotion;
    s16 blendOverride;
    u32 motionIndex;
    s32 currentFrame;
    s32 currentMotion;
    u16 motionFlags;
    u16 movementFlags;
    u16 motionOption;
    u16 blendFrames;
    u8 *model;

    if (((BtlUnit *)unit)->flags2 & 2) {
        model = (u8 *)(((BtlUnit *)unit)->layerHandle);
        motionFlags = (u16)(((BtlUnit *)unit)->unk_9d8);
        if (motionFlags & 2) {
            mdlSetLayerWeight(model, 0, 0.0f);
            return;
        }
        if ((motionFlags & 4) && ((s16)btlUnitModelAnimFrame(unit) >= ((BtlUnit *)unit)->holdMotionFrame) && (((BtlUnit *)unit)->holdMotionTicks > 0)) {
            mdlSetLayerWeight(model, 0, 0.0f);
            unitFields->holdMotionTicks = (s16) (unitFields->holdMotionTicks - 1);
            return;
        }
        mdlSetLayerWeight(unitFields->layerHandle, 0, ((BtlUnit *)unit)->motionRate);
        if (!(unitFields->unk_9d8 & 8)) {
            movementFlags = (u16)(((BtlUnit *)unit)->movementFlags);
            if ((movementFlags & 1) && !(movementFlags & 4)) {
                if (btlUnitIsWalkingMotion(unit) == 0) {
                    if (((BtlUnit *)unit)->stateFlags & 4) {
                        walkRate = 2.0f;
                    } else {
                        walkRate = 1.0f;
                    }
                    btlUnitSetMotion(unit, 1, 4U, walkRate, 1);
                }
            } else if ((btlUnitIsWalkingMotion(unit) != 0) && (btlUnitIsAtRestMotion(unit) == 0)) {
                btlUnitSetMotion(unit, ((BtlUnit *)unit)->restMotion, 6U, ((BtlUnit *)unit)->restRate, ((BtlUnit *)unit)->restOption);
            }
        }
        motionOption = (u16)(((BtlUnit *)unit)->motionOption);
        switch (motionOption) {
        case 1:
        case 2:
            break;
        case 0:
            if (((MdlFileModel *)model)->finished == 1) {
                restMotion = (s16)(((BtlUnit *)unit)->restMotion);
                if (restMotion != (s16)btlUnitGetMotionState(unit)) {
                    blendOverride = (s16)(((BtlUnit *)unit)->restBlendFrames);
                    if (blendOverride > 0) {
                        blendFrames = blendOverride & 0xFFFF;
                    } else {
                        switch (restMotion) {
                        case 3:
                        case 0xE:
                        case 0x12:
                        case 0x18:
                            motionIndex = (u16)btlUnitGetMotionId(unit, restMotion & 0xFFFF);
                            if ((s32)motionIndex < (s32)(((BtlUnit *)unit)->motionCount)) {
                                blendFrames = (u16)((u16)((BtlMotionRate *)btlUnitAddMotionOffset(motionIndex * 0xA, (u32)(s32)((BtlUnit *)unit)->motionRates))->unk8);
                            } else {
                                blendFrames = 6;
                            }
                            break;
                        default:
                            blendFrames = 0;
                            break;
                        }
                    }
                    btlUnitSetMotion(unit, unitFields->restMotion, blendFrames, ((BtlUnit *)unit)->restRate, ((BtlUnit *)unit)->restOption);
                }
            }
            break;
        case 3:
            if (!(((MdlFileModel *)model)->unk108 < 1.0f)) {
                currentMotion = (s16)btlUnitGetMotionState(unit);
                currentFrame = (s16)btlUnitModelAnimFrame(unit);
                if (currentFrame >= (s16)btlUnitMotionFrames(unit, currentMotion & 0xFFFF, 1.0f)) {
                    mdlSetLayerWeight(model, 0, 0.0f);
                }
            }
            break;
        case 4:
            if ((((MdlFileModel *)model)->finished == 1) && ((s16)btlUnitGetMotionState(unit) != 0xE)) {
                btlUnitSetMotion(unit, 0xE, 0U, 1.0f, 1);
            }
            break;
        case 5:
            if ((((MdlFileModel *)model)->finished == 1) && ((s16)btlUnitGetMotionState(unit) != 0x10)) {
                btlUnitSetMotion(unit, 0x10, 0U, 1.0f, 1);
            }
            break;
        }
        ((BtlUnit *)unit)->unk_9d8 = (u16) (((BtlUnit *)unit)->unk_9d8 & 0xFFF7);
    }
}


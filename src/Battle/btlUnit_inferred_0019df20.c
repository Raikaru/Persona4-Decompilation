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
#include "btl_unit_look_internal.h"
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

extern f32 fGpffff8474;
extern u8 D_005F6CA0[];
extern f32 D_005F6C10[];
extern u8 *iGpffffb3ac; /* active battle context */
extern u8 *iGpffffb3b8; /* skill table, DatSkillEntry rows */
extern u8 *iGpffffb3c0; /* party visual records, stride 0x14C */
extern u8 *iGpffffb3cc; /* enemy visual records, stride 0xE8 */


extern u8 *iGpffff9db0;
extern u8 *D_0076449C; /* active battle context */
extern u8 *iGpffffb3ac; /* active battle context */
extern u8 *iGpffffb414;
extern u8 *iGpffffb3e0; /* child visual records, stride 0x58 */
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


extern u8 iGpffffa4d8;
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlSetBlendWeight(void *model, float value);
extern void mdlLookAtSetupSetRange(void *model, float pitchLimit, float yawLimit);
extern f32 DAT_0076112c;


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

/* measured: optimization_level 1 with the index and value locals declared before the loop keeps
 * retail's initialisation order; -O2 reorders it. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: disabling propagation keeps the alpha result in memory across the merge, as retail
 * does. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale for every factor; on the i == 2 && alpha < 0xFE path it
 * reads a stale mode, as the C does. */
#pragma push
#pragma pop
/* measured: opt_propagation off plus named call_angle locals preserve retail's stack reloads before mdlLookAtSetupSetRange. */
#pragma push
/* Aim the selected unit, or active party units, at the packet's world point.
 * The selected action's unit gets the wider yaw range. */
// FUN_0019DF20
s32 btlUnitSetLookAtRanges(u8 *work)
{
    BtlUnit *typedUnit;
    u8 *unit;

    if ((((BtlUnitLookPointWork *)work)->flags & 1) != 0) {
        f32 pitchLimit;
        f32 yawLimit;
        f32 callPitch;
        f32 callYaw;
        s32 enabled;

        unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
        typedUnit = (BtlUnit *)unit;
        while (unit != NULL) {
            if ((*(s32 *)&((BtlUnit *)unit)->flags3 & 8) != 0) {
                if (&pitchLimit != NULL) {
                    pitchLimit = 70.0f;
                }
                if (&yawLimit != NULL) {
                    yawLimit =
                        ((u8 *)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit ==
                         unit) ? 70.0f : 60.0f;
                }
                callYaw = yawLimit;
                callPitch = pitchLimit;
                enabled = *(s32 *)&((BtlUnit *)unit)->flags2 & 2;
                if (enabled != 0) {
                    mdlLookAtSetupSetRange(((BtlUnit *)unit)->layerHandle, callPitch, callYaw);
                }
                /* The flags are read a second time through typedUnit, as retail does. */
        if ((*(s32 *)&typedUnit->flags2 & 2) != 0) {
                    mdlSetBlendWeight(((BtlUnit *)unit)->layerHandle, 0.25f);
                }
                *(s16 *)&((BtlUnit *)unit)->lookAtMode = 1;
                ((BtlUnit *)unit)->lookAtTargetPos =
                    ((BtlUnitLookPointWork *)work)->point;
                btlUnitApplyModelState(unit, 3);
            }
            unit = *(u8 **)&((BtlUnit *)unit)->prevUnit;
            typedUnit = (BtlUnit *)unit;
        }
    } else {
        f32 pitchLimit;
        f32 yawLimit;
        f32 callPitch;
        f32 callYaw;
        s32 enabled;

        unit = ((BtlUnitLookPointWork *)work)->unit;
        typedUnit = (BtlUnit *)unit;
        if (&pitchLimit != NULL) {
            pitchLimit = 70.0f;
        }
        if (&yawLimit != NULL) {
            yawLimit =
                ((u8 *)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit == unit) ?
                70.0f : 60.0f;
        }
        callYaw = yawLimit;
        callPitch = pitchLimit;
        enabled = *(s32 *)&((BtlUnit *)unit)->flags2 & 2;
        if (enabled != 0) {
            mdlLookAtSetupSetRange(((BtlUnit *)unit)->layerHandle, callPitch, callYaw);
        }
        /* The flags are read a second time through typedUnit, as retail does. */
        if ((*(s32 *)&typedUnit->flags2 & 2) != 0) {
            mdlSetBlendWeight(((BtlUnit *)unit)->layerHandle, 0.25f);
        }
        *(s16 *)&((BtlUnit *)unit)->lookAtMode = 1;
        ((BtlUnit *)unit)->lookAtTargetPos =
            ((BtlUnitLookPointWork *)work)->point;
        btlUnitApplyModelState(unit, 3);
    }
    return 1;
}
#pragma pop


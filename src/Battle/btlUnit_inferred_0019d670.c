#include "member_access.h"
#include "scene_task_internal.h"
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
#include "btl_unit_look_internal.h"
#include "model_battle_internal.h"
#include "resrc_manager_internal.h"
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

extern void (*D_00887300[])(s32 arg0, s32 arg1);
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
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
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
extern void btlCameraSetUnitSlotValue(u8 *unit, s32 slotIndex, s32 slotValue);
extern void btlTargetRemoveRadiusNode(u8 *unit);
extern int mdlHasActiveMode(void *model);
extern void mdlSetLookAtActive(void *model);
extern void mdlSetLookAtRequested(void *model);
extern u8 *resrcMngFindResById(u8 *manager, u16 resourceId);
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern void mdlSetBattleStateFlag(void *model);
extern void mdlSetAlphaBlend(void *model);
extern void mdlSetLookStateWord(void *model, u16 value);
extern u16 mdlGetLookStateWord(void *model);
extern f32 fGpffff80fc;
extern u8 D_007940F0[];
extern void mdlClearBattleStateFlag(void *model);
extern void mdlClearAlphaBlend(void *model);
extern void mdlSetBlendWeight(void *model, float value);
extern void mdlLookAtSetupSetRange(void *model, float pitchLimit, float yawLimit);
extern f32 DAT_0076112c;


extern void btlUnitClearModelState(u8 *unit, s32 mode);
extern void btlUnitApplyModelState(u8 *unit, s32 mode);
extern u8 *btlSoundGetCharacterBank(u8 *unit);


extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern s32 iGpffffb444;

extern void btlUnitFreeRemovedUnits(void);
extern void (*jtbl_008873EC[])(void *arg0);
extern u8 D_005F6C00[];
extern u8 D_005F6D10[];
extern u8 D_005F6010[];
extern u8 D_005F6020[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void btlUnitUpdateLookAtTarget(u8 *unit);
extern u8 iGpffffa088;
extern u32 iGpffffa0a8;
extern u8 D_00794150[];

/* measured: optimization_level 1 keeps retail's loop initialisation order with the index and value
 * locals declared before the loop; -O2 reorders it. */
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: propagation is disabled so the alpha result stays in memory across the merge, as in
 * retail. */
#pragma push
#pragma pop
/* Retail reloads the 1/255 colour scale for every factor, and on the i == 2 && alpha < 0xFE path
 * reads mode uninitialised; the C does the same. */
#pragma push
#pragma pop
/* Unlink and release all four genus lists, including camera-slot ownership. */
// FUN_0019D670
void btlUnitFreeRemovedUnits(void)
{
    /* List links are reloaded after each callback because the callbacks may change them. */
    u8 *unit;
    u8 *nextUnit;
    u32 genusIndex;
    u8 *nextLink;
    u8 *previousLink;
    u8 genus;
    s8 cameraSlot;

    for (genusIndex = 0; genusIndex < 4; genusIndex++) {
        unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[genusIndex * 2];
        while (unit != NULL) {
            nextUnit = *(u8 **)&((BtlUnit *)unit)->nextUnit;
            genus = ((BtlUnit *)unit)->genus;
            btlUnitReleaseAllResources(unit);
            btlTargetRemoveRadiusNode(unit);
            cameraSlot = ((BtlUnit *)unit)->cameraSlot;
            if (cameraSlot >= 0)
                btlCameraSetUnitSlotValue(unit, cameraSlot, 0);
            nextLink = MEMBER(u8 *, unit, BtlUnit, nextUnit);
            if (nextLink != NULL)
                *(u8 **)&((BtlUnit *)nextLink)->prevUnit = *(u8 **)&((BtlUnit *)unit)->prevUnit;
            else
                ((BtlBattleState *)iGpffffb3ac)->unitLists[(genus & 0xFF) * 2 + 1] =
                    *(u8 **)&((BtlUnit *)unit)->prevUnit;
            previousLink = MEMBER(u8 *, unit, BtlUnit, prevUnit);
            if (previousLink != NULL)
                *(u8 **)&((BtlUnit *)previousLink)->nextUnit = MEMBER(u8 *, unit, BtlUnit, nextUnit);
            else
                ((BtlBattleState *)iGpffffb3ac)->unitLists[(genus & 0xFF) * 2] =
                    MEMBER(u8 *, unit, BtlUnit, nextUnit);
            jtbl_008873EC[0](unit);
            unit = nextUnit;
        }
    }
}

/* Enable one model presentation mode; modes 1..4 affect draw/look/sound state, while mode 6 marks
 * the scene resource. */
// FUN_0019D7A0
void btlUnitApplyModelState(u8 *unit, s32 mode)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    /* Typed layerHandle loads would hoist the address into a saved register, so only the separate
     * typed pointer is used for the other reloads. */
    s32 stateFlags;
    u16 sceneDrawId;
    u16 selectedMode;
    u8 *resource;
    u8 *model;
    u8 *soundModel;
    if ((*(s32 *)&((BtlUnit *)unit)->flags2 & 2) != 0) {
        selectedMode = (u16)mode;
        switch (selectedMode) {
        case 6:
            sceneDrawId = ((BtlUnit *)unit)->sceneDrawId;
            if ((sceneDrawId != 0) &&
                (((s32)(sceneDrawId & 0xFFC00) >> 10) == 1)) {
                /* Scene mode six marks the resource-manager record, not the model. */
                resource = resrcMngFindResById(((SceneContext *)iGpffff9db0)->manager.pointer, sceneDrawId);
                *(s32 *)&((ResrcRecord *)resource)->handle22C = 0x34;
                *(s32 *)&((ResrcRecord *)resource)->unk28 |= 0x04000000;
                return;
            }
            break;
        case 1:
            stateFlags = ((BtlBattleState *)iGpffffb3ac)->battleFlags;
            if (((stateFlags & 0x100) == 0) ||
                (((BtlUnit *)unit)->genus != 0)) {
                if (((stateFlags & 0x200) == 0) ||
                    (((BtlUnit *)unit)->genus != 1)) {
                    mdlSetBattleStateFlag(((BtlUnit *)unit)->layerHandle);
                    *(u8 **)&((Model *)(typedUnit->layerHandle))->queue =
                        D_007940F0;
                    ((Model *)(typedUnit->layerHandle))->limit =
                        fGpffff80fc;
                    model = typedUnit->layerHandle;
                    ((Model *)model)->targetLimit =
                        ((Model *)model)->limit;
                    *(s32 *)&((Model *)(typedUnit->layerHandle))->limitRate =
                        0x3F800000;
                    return;
                }
            }
            break;
        case 2:
            mdlSetAlphaBlend(((BtlUnit *)unit)->layerHandle);
            return;
        case 3:
            mdlSetLookStateWord(((BtlUnit *)unit)->layerHandle, (u16)((mdlGetLookStateWord(typedUnit->layerHandle) &
                   0xFFFF) | 0x1000));
            mdlSetLookStateWord(typedUnit->layerHandle, (u16)((mdlGetLookStateWord(typedUnit->layerHandle) &
                   0xFFFF) | 0x2000));
            stateFlags = mdlGetLookStateWord(typedUnit->layerHandle) & 0xFFFF;
            stateFlags = stateFlags & -0x801;
            mdlSetLookStateWord(typedUnit->layerHandle, (u16)stateFlags);
            return;
        case 4:
            ((Model *)(((BtlUnit *)unit)->layerHandle))->motion.request =
                (s32)btlSoundGetCharacterBank(unit);
            soundModel = typedUnit->layerHandle;
            ((Model *)soundModel)->motion.flags |= 0x10;
            break;
        case 0:
        case 5:
            break;
        }
    }
}

/* Undo the selected model presentation mode and reset its associated state. */
// FUN_0019D990
void btlUnitClearModelState(u8 *unit, s32 mode)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    /* Typed layerHandle loads would hoist the address into a saved register, so only the separate
     * typed pointer is used for the other reloads. */
    s32 lookFlags;
    u16 sceneDrawId;
    u32 selectedMode;
    u8 *resource;
    u8 *model;
    if ((*(s32 *)&((BtlUnit *)unit)->flags2 & 2) != 0) {
        selectedMode = (u32)mode & 0xFFFF;
        switch (selectedMode) {
        case 6:
            sceneDrawId = ((BtlUnit *)unit)->sceneDrawId;
            if ((sceneDrawId != 0) &&
                (((s32)(sceneDrawId & 0xFFC00) >> 10) == 1)) {
                /* Scene mode six marks the resource-manager record, not the model. */
                resource = resrcMngFindResById(((SceneContext *)iGpffff9db0)->manager.pointer, sceneDrawId);
                *(s32 *)&((ResrcRecord *)resource)->unk28 &= 0xFBFFFFFF;
                return;
            }
            break;
        case 1:
            mdlClearBattleStateFlag(((BtlUnit *)unit)->layerHandle);
            model = typedUnit->layerHandle;
            ((Model *)model)->drawFlags &= 0xE2;
            return;
        case 2:
            mdlClearAlphaBlend(((BtlUnit *)unit)->layerHandle);
            return;
        case 3:
            mdlSetBlendWeight(((BtlUnit *)unit)->layerHandle, DAT_0076112c);
            mdlLookAtSetupSetRange(typedUnit->layerHandle, 70.0f, 80.0f);
            mdlSetLookAtActive(typedUnit->layerHandle);
            mdlSetLookAtRequested(typedUnit->layerHandle);
            lookFlags = mdlGetLookStateWord(typedUnit->layerHandle) & 0xFFFF;
            lookFlags = lookFlags & -0x2001;
            mdlSetLookStateWord(typedUnit->layerHandle, (u16)lookFlags);
            lookFlags = mdlGetLookStateWord(typedUnit->layerHandle) & 0xFFFF;
            lookFlags = lookFlags & -0x1001;
            mdlSetLookStateWord(typedUnit->layerHandle, (u16)lookFlags);
            *(s16 *)&((BtlUnit *)unit)->lookAtMode = 0;
            return;
        case 4:
            model = ((BtlUnit *)unit)->layerHandle;
            ((Model *)model)->motion.flags &= 0xFFEF;
            ((Model *)(((BtlUnit *)unit)->layerHandle))->motion.request = 0;
            break;
        case 0:
        case 5:
            break;
        }
    }
}

/* Mode dispatch is an explicit goto chain because a switch would test zero first and drop the
 * default branch. */
// FUN_0019DB40
void btlUnitUpdateLookAtTarget(u8 *unit)
{
    BtlUnit *typedUnit = (BtlUnit *)unit;
    extern void mdlSetLookAtTargetPoint(void *model, void *target);
    extern s32 mdlComputeIndexedAttachMatrix(void *model, s32 index, void *destination);
    extern f32 DAT_007613f8;
    extern u8 *btlUnitFindById(s32 unitId);
    P4_95730_Vec3 lookPoint;
    P4_95730_Vec3 scaledCenter;
    P4_95730_Vec3 rotatedCenter;
    P4_95730_Vec3 modelScaledCenter;
    P4_95730_Vec3 modelRotatedCenter;
    s16 motion;
    u8 *target;

    if (*(s32 *)&((BtlUnit *)unit)->flags2 & 2) {
        if (*(s32 *)&((BtlUnit *)unit)->flags2 & 2) {
            motion = ((BtlUnit *)unit)->currentMotion;
        } else {
            motion = 0;
        }
        if (motion == 0x11) {
            goto case11;
        }
        if (motion != 0) {
            goto def;
        }
        goto case0;
    case11:
        if (mdlHasActiveMode(((BtlUnit *)unit)->layerHandle) != 0) {
            mdlSetLookAtRequested(typedUnit->layerHandle);
        }
        return;
    def:
        if (mdlHasActiveMode(typedUnit->layerHandle) != 0) {
            mdlSetLookAtActive(typedUnit->layerHandle);
            mdlSetLookAtRequested(((BtlUnit *)unit)->layerHandle);
        }
        return;
    case0:
            if (*(s32 *)&((BtlUnit *)unit)->datUnit != 0 && datCalcChkBadStatus(*(s32 *)&((BtlUnit *)unit)->datUnit, 0x100) != 0) {
                if (mdlHasActiveMode(((BtlUnit *)unit)->layerHandle) != 0) {
                    mdlSetLookAtRequested(typedUnit->layerHandle);
                }
                return;
            }
            if (((BtlUnit *)unit)->lookAtMode != 0 && !(((Model *)(((BtlUnit *)unit)->layerHandle))->layerBlend < 1.0f) && !(mdlGetLookStateWord(((BtlUnit *)unit)->layerHandle) & 0x200)) {
                switch (typedUnit->lookAtMode) {
                case 1:
                    mdlSetLookAtTargetPoint(typedUnit->layerHandle, &((BtlUnit *)unit)->lookAtTargetPos);
                    return;
                case 2:
                    if (*(s32 *)&((BtlUnit *)unit)->lookAtTargetId != 0) {
                        target = btlUnitFindById(*(s32 *)&((BtlUnit *)unit)->lookAtTargetId & 0xFFFF);
                        if (target != NULL && target != unit) {
                            if (!(*(s32 *)&((BtlUnit *)target)->flags2 & 2)) {
                                scaledCenter.x = ((BtlUnit *)target)->sphereCenter.x * ((BtlUnit *)target)->scale;
                                scaledCenter.y = ((BtlUnit *)target)->sphereCenter.y * ((BtlUnit *)target)->scale;
                                scaledCenter.z = ((BtlUnit *)target)->sphereCenter.z * ((BtlUnit *)target)->scale;
                                RtQuatTransformVectors(&rotatedCenter, &scaledCenter, 1, &((BtlUnit *)target)->rot);
                                lookPoint.x = rotatedCenter.x + ((BtlUnit *)target)->pos.x;
                                lookPoint.y = rotatedCenter.y + ((BtlUnit *)target)->pos.y;
                                lookPoint.z = rotatedCenter.z + ((BtlUnit *)target)->pos.z;
                            } else if (mdlComputeIndexedAttachMatrix(((BtlUnit *)target)->layerHandle, 0, &lookPoint) == 0) {
                                modelScaledCenter.x = ((BtlUnit *)target)->sphereCenter.x * ((BtlUnit *)target)->scale;
                                modelScaledCenter.y = ((BtlUnit *)target)->sphereCenter.y * ((BtlUnit *)target)->scale;
                                modelScaledCenter.z = ((BtlUnit *)target)->sphereCenter.z * ((BtlUnit *)target)->scale;
                                RtQuatTransformVectors(&modelRotatedCenter, &modelScaledCenter, 1, &((BtlUnit *)target)->rot);
                                lookPoint.x = modelRotatedCenter.x + ((BtlUnit *)target)->pos.x;
                                lookPoint.y = modelRotatedCenter.y + ((BtlUnit *)target)->pos.y;
                                lookPoint.z = modelRotatedCenter.z + ((BtlUnit *)target)->pos.z;
                            }
                            lookPoint.y += ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale * DAT_007613f8;
                            mdlSetLookAtTargetPoint(typedUnit->layerHandle, &lookPoint);
                            return;
                        }
                        mdlSetLookAtRequested(typedUnit->layerHandle);
                        *(s32 *)&typedUnit->lookAtTargetId = 0;
                    }
                    break;
                }
            }
    }
}


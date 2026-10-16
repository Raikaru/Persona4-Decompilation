#include "rw_types_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
typedef struct BtlTarget BtlTarget;
typedef struct BtlCamera BtlCamera;
typedef struct BtlUnitStateWork BtlUnitStateWork;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnit DatUnit;
typedef struct KwlnTask KwlnTask;
typedef struct Model Model;
typedef struct RwMatrix RwMatrix;
extern u8 *iGpffff9db0;
extern u8 D_006355C0[], D_006355E0[], D_00635600[];
extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
/* Retail forwards the matrix result as well as all three inputs. */
typedef struct BtlAction BtlAction;
extern void btlActionRunPresentation(u8 *packet);
extern void btlActionRunMotionSequence(u8 *packet);
extern RwRGBA iGpffffb45c;
extern char D_007636C0[8];
extern char D_007636C8[8];
extern char D_007636D0[8];
extern u8 D_0062E070[];
extern void btlUnitSetColor(BtlUnit *unit, RwRGBA color);
extern void btlCameraUpdateEffectList();


extern u8 D_006290F0[];

extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern u8 D_00635560[], D_00635580[];
extern u8 iGpffffa4d8[4];

extern u8 D_00629640[];
extern u8 D_00629738[];
extern s32 func_00243ce0(u8 *arg0);
extern void btlCameraFrameTarget(u8 *arg0, f32 arg1, f32 arg2);
extern u16 btlTargetGetUnitIndex(BtlTarget *target);
extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;
extern f32 tanf(f32 angle);
extern u32 btlCameraClampOffsetToLimit(f32 *pose, f32 *out);
extern f32 fGpffff8110;
extern u8 D_0060A100[];
extern f32 fGpffff8100;
extern f32 fGpffff810c;
extern f32 fGpffff8128;
extern f32 fGpffff813c;
extern f32 fGpffff809c;
extern f32 fGpffff8030;
extern f32 fGpffff803c;
extern f32 fGpffff8098;
extern f32 fGpffff8118;
extern f32 fGpffff8174;
extern f32 fGpffff8178;
extern f32 fGpffff817c;
extern void btlCameraFrameActorTarget(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration);
extern s32 btlActionSkillReachesTargets(u8 *action);

extern u8 D_006296B0[];
extern u8 D_006296E8[];

extern u8 D_00629700[];


extern u8 *DAT_0076449c;
extern void btlCameraFrameAim(u8 *arg0);
extern s32 btlCameraUnitAnimFinished(u8 *arg0, u8 *arg1);
extern void btlUnitSetChildValue(BtlUnitStateWork *work, u16 value);
extern void btlUnitFaceTarget(BtlUnit *unit, const RwV3d *target);
extern s32 btlCameraSelectMode(u8 *camera);
extern void btlCameraUpdateMode(u8 *camera);
extern s32 btlUnitSkillBlocked(u8 *action, u8 *subordinate);
extern void btlCameraSelectEncounterPreset(u8 *camera);

extern u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask);
extern void datSetFlag(s32 arg0, s32 arg1);
extern u8 *btlActionFindByUnit(s32 arg0);





extern void (*jtbl_008873EC[])(void *arg0);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
extern void btlMainCurveReset(u16 *param_1, f32 *param_2);
extern void btlCameraCopyPoseSnapshot(f32 *arg0, f32 *arg1);
extern void btlCameraCopyPose(f32 *arg0, f32 *arg1);
extern void btlMainCurveSetPoses(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern u32 datCalcRandomBelow(u32 arg0);
extern u8 D_0060A0E0[];
extern u8 D_006348B0[];
extern u8 D_00634CB0[];
extern u8 D_006350B0[];
extern u8 *iGpffffb414;
extern u8 D_0062A5F0[];
extern u8 D_0062AD40[];
extern u8 D_0062B490[];
extern u8 D_0062BBE0[];
extern u8 D_0062C330[];
extern s32 btlActionGetActiveOrQueueFront(void);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern f32 fGpffff834c;
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
extern void btlTargetPositionToCell(s16 *outX, s16 *outZ, f32 *position);
extern u8 *iGpffffb3e0;
extern s32 btlActionHasNoTargetClass(u32 action);

extern u8 *btlCameraCreateSetStatePacket(u8 *arg0, s32 arg1);
extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern u8 *btlPacketCreateEffectCounter(s32 arg0, s32 arg1);
extern void btlCameraStartEffect(u8 *arg0, u8 *arg1, s32 arg2);
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern u8 D_00632240[];
extern u8 *btlUnitFindInSideById(s32 arg0, s32 arg1);
extern void btlUnitHideModel(u8 *arg0);
extern void datCalcClearAllBuffs(u8 *arg0);
extern u8 D_0062D920[];
extern void btlActionFinishPresentation(s64 *arg0);
extern s32 btlFormationAllocWork(u32 param_1);
extern u8 *btlFormationGetRecord(s32 arg0);
extern void btlFormationCopyRecord(int destination, u32 source);
extern BtlPacket *btlUnitCreateColorPacket(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
extern void btlTargetClearResultBuffer(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlUnitCreateAnimPacket(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlSoundCreateStreamPacket(u16 channel, const char *streamName);
extern BtlPacket *btlFormationCreatePacket(u32 arg0, u32 arg1, u32 arg2, u16 arg3, u32 arg4);
extern void btlFormationSetPlacement(u32 arg0);
extern u8 D_006354B0[];
extern u8 *iGpffffb444;
extern u8 *iGpffffb3ac;
extern void btlCameraFrameActionCutscene(u8 *camera);
extern u8 D_00629750[], D_00629EA0[], D_0062CA80[], D_0062D1D0[];
extern u8 D_0062E7C0[], D_0062EF10[], D_0062F660[], D_0062FDB0[];
extern u8 D_00630500[], D_00630C50[], D_006313A0[], D_00631AF0[];
extern u8 D_006355A0[];

extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 unit, u16 effect);
extern BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
extern BtlPacket *btlUnitCreateRotateTowardUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u32 flags);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rotation, u32 flags);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPosition, f32 speed, u32 flags);
extern u32 datCalcIsDead(void *unit, s32 hpDelta);
extern s32 datCalcIsGuarding(u16 *unit);
extern s32 btlUnitSlotValueOrOne(s32 action);
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern BtlPacket *btlFormationCreateSlotPacket(u16 group, u16 mask);
extern f32 fGpffff80e4;
extern f32 btlTargetQuatAngle(void *first, void *second);
extern s32 CrossfadeRequest(s16 frames);

/* Source unit: src/promoted/code1_0022.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0022.c; members 00225e50-0022ae00 */

extern void btlCameraSelectEncounterPreset(u8 *camera);
extern void btlCameraFrameTarget(u8 *camera, f32 distanceOffset, f32 duration);
extern u8 *btlFormationGetRecord(s32 arg0);
extern s32 btlUnitSkillBlocked(u8 *arg0, u8 *arg1);
extern s32 datCalcIsGuarding(u16 *unitData);
extern void btlMainApplyUnitBaseColors(u8 *unit);
static inline s32 func_00225ec0_flag(u8 *action)
{
    u16 battle;

    if (action == NULL) {
        return 1;
    }
    if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
        battle = *(u16 *)(iGpffffb3ac + 0x108);
        switch (battle) {
        case 0x21:
        case 0x22:
            return 0;
        }
    } else {
        battle = *(u16 *)(iGpffffb3ac + 0x108);
        switch (battle) {
        case 0x16:
        case 0x24:
            return 0;
        }
    }
    return 1;
}
static inline u16 btlUnitRosterIndex(u8 *unit)
{
    u8 *node;
    u16 index;

    if (unit[0xA2] != 0) {
        return 0;
    }
    index = 0;
    for (node = *(u8 **)(iGpffffb3ac + 0x17C); node != NULL; node = *(u8 **)(node + 0xA68)) {
        if (unit == node) {
            break;
        }
        index++;
    }
    return index;
}
#pragma push
#pragma pop
/* 896/896 bytes and all 17 relocations resolve exactly.
 * Keep the opaque byte branch-local, snapshot coordinates before opacity
 * conversion, and pack the color before preparing the overlay dimensions. */
#pragma push
#pragma pop
/* 1036/1040 bytes; 26 code relocations and all nine switch entries exact. */
#pragma push
#pragma pop
/* 1688/1696 bytes; all 36 resolved code relocations exact. */
/* Measured: 800/800 bytes, 20 resolved relocations, zero differences.
 * Disabling common-subexpression folding preserves the wrapping target walk. */
/* measured 00225d00 plain-C reconstruction matches the complete 256-byte retail window at normalized_diff 0. */
// Intent: Tick the camera aim on the actor during the action. [inferred]
// FUN_00225E50
void btlCameraTickAimOnActor(u8 *arg0)
{
    s32 iVar1;

    iVar1 = *(s32 *)(arg0 + 0xE0);
    if ((((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u8 *)(*(s32 *)(iVar1 + 0x30) + 0xA2) != 0)) &&
        (((iVar1 != 0) && ((*(u16 *)(iVar1 + 0x1A) & 1) != 0)) &&
         (*(u16 *)(DAT_0076449c + 0xC00) == 1))) {
        btlCameraFrameAim(arg0);
    }
}

// Intent: Frame the camera for the action cutscene. [inferred]
// FUN_00225EC0
void btlCameraFrameActionCutscene(u8 *camera)
{
    extern void btlUnitGetSphereWorldCenter(u8 *arg0, f32 *arg1);
    extern f32 btlUnitGetGroupBounds(u32 arg0, u32 arg1, void *arg2, f32 *arg3, void *arg4, u32 arg5);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 tanf(f32 x);
    extern void btlCameraFrameStatusRoll(u8 *arg0, f32 arg1, f32 arg2);
    extern void btlAct_ENEMY_ALL(u8 *arg0);
    extern void btlMainApplyUnitBaseColors(u8 *arg0);
    struct PosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    };
    struct PosePair poses;
    struct PosePair rec718;
    struct PosePair rec618;
    f32 top;
    RwV3d groupCenter;
    RwV3d unitCenter;
    RwV3d point;
    RwV3d delta;
    u8 *record;
    u8 *unit;
    u8 *action;
    s32 var17;
    s32 var16;
    f32 radius;
    f32 height;
    f32 scale;
    f32 px;
    f32 py;
    f32 pz;
    f32 len;
    u32 frames;

    action = *(u8 **)(camera + 0xE0);
    var16 = func_00225ec0_flag(action);
    var17 = 0;
    unit = *(u8 **)(action + 0x30);
    radius = *(f32 *)(unit + 0x90) * *(f32 *)(unit + 0x2C);
    switch (*(u16 *)(iGpffffb3ac + 0x108)) {
    case 10:
        if (*(s32 *)(iGpffffb3ac + 0xC04) == *(s32 *)(action + 8)) {
            if (*(s32 *)(iGpffffb3ac + 0xC08) != 0 && datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100) == 0) {
                btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 8);
            }
            return;
        }
        break;
    }
    *(s32 *)(iGpffffb3ac + 0xC04) = *(s32 *)(action + 8);
    *(s32 *)(iGpffffb3ac + 0xC08) = 0;
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (*(u8 *)(unit + 0xA2) == 0) {
        btlUnitGetGroupBounds(2, 1, &groupCenter, NULL, NULL, 1);
        btlUnitGetSphereWorldCenter(unit, (f32 *)&unitCenter);
        unitCenter.y = 0.0f;
        groupCenter.y = 0.0f;
        delta.x = unitCenter.x - groupCenter.x;
        delta.y = unitCenter.y - groupCenter.y;
        delta.z = unitCenter.z - groupCenter.z;
        len = RwV3dNormalize(&delta, &delta);
        scale = fGpffff80fc * len;
        px = delta.x;
        px *= scale;
        py = delta.y;
        py *= scale;
        pz = delta.z;
        pz *= scale;
        groupCenter.x = groupCenter.x + px;
        groupCenter.y = groupCenter.y + py;
        groupCenter.z = groupCenter.z + pz;
        point.x = unitCenter.x;
        height = *(f32 *)(unit + 0x8C) * *(f32 *)(unit + 0x2C);
        point.y = point.y + fGpffff8100 * height;
        point.z = unitCenter.z;
        btlCameraLookAtQuat(&poses.secondRotation, &point, &groupCenter, D_0060A0E0);
        len = tanf(0.5f * *(f32 *)(camera + 0xB8));
        radius = (4.0f * radius) / len;
        delta.x = point.x - groupCenter.x;
        delta.y = point.y - groupCenter.y;
        delta.z = point.z - groupCenter.z;
        RwV3dNormalize(&delta, &delta);
        poses.second.x = point.x + delta.x * radius;
        poses.second.y = point.y + delta.y * radius;
        poses.second.z = point.z + delta.z * radius;
        if (!(poses.second.y <= 700.0f)) {
            var17 = 1;
        }
    } else {
        if (func_00243ce0(*(u8 **)(unit + 0xA64)) != 0) {
            if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100000) == 0) {
                record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x718;
                btlCameraLookAtQuat(&rec718.firstRotation, record + 4, record + 0x10, D_0060A0E0);
                rec718.first = *(RwV3d *)(record + 4);
                btlCameraLookAtQuat(&rec718.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
                rec718.second = *(RwV3d *)(record + 0x1C);
                frames = *(u16 *)record;
                scale = (f32)frames / 30.0f;
                btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24), (f32 *)&rec718.first, (f32 *)&rec718.second, 1);
                btlCameraSetDuration(iGpffffb3ac + 0x24, scale);
                btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
            } else {
                record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
                btlCameraLookAtQuat(&rec618.firstRotation, record + 4, record + 0x10, D_0060A0E0);
                rec618.first = *(RwV3d *)(record + 4);
                btlCameraLookAtQuat(&rec618.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
                rec618.second = *(RwV3d *)(record + 0x1C);
                frames = *(u16 *)record;
                scale = (f32)frames / 30.0f;
                btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24), (f32 *)&rec618.first, (f32 *)&rec618.second, 1);
                btlCameraSetDuration(iGpffffb3ac + 0x24, scale);
                btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
            }
            return;
        }
        btlUnitGetGroupBounds(2, 1, &unitCenter, &top, NULL, 1);
        btlUnitGetSphereWorldCenter(unit, (f32 *)&groupCenter);
        poses.second = poses.first;
        if (poses.second.y < 1.25f * top) {
            poses.second.y = 1.25f * top;
        }
        btlCameraLookAtQuat(&poses.secondRotation, &poses.second, &groupCenter, D_0060A0E0);
    }
    len = btlTargetQuatAngle(&poses.firstRotation, &poses.secondRotation);
    if (var17 != 0 || (!(len <= fGpffff80e4) && var16 == 1)) {
        btlMainApplyUnitBaseColors(NULL);
        if (*(u8 *)(unit + 0xA2) == 1 && func_00243ce0(*(u8 **)(unit + 0xA64)) != 0) {
            btlCameraFrameStatusRoll(camera, 2.25f, 2.0f);
        } else {
            btlAct_ENEMY_ALL(camera);
        }
        if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100) == 0) {
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 1);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 8);
        } else {
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        }
        *(s32 *)(iGpffffb3ac + 0xC08) = 1;
        return;
    }
    if (poses.first.y < 25.0f) {
        poses.first.y = 25.0f;
    }
    if (poses.second.y < 25.0f) {
        poses.second.y = 25.0f;
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    if (var16 != 0) {
        scale = 2.5f;
    } else {
        scale = 1.25f;
    }
    btlCameraSetDuration(camera, scale);
}

// Intent: Frame the camera on the actor and target pair with height and scale. [inferred]
// FUN_002266B0
/* measured: opt_scalarize off retains the real horizontal vector stores.
 * Staged radius scaling and the scoped two-halfword skill table give
 * 1420/1424 bytes, 21 code relocations and zero normalized differences. */
/* measured: btlCameraFrameActorTarget MATCH -> MISMATCH without this pragma. */
#pragma opt_scalarize off
void btlCameraFrameActorTarget(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d targetSnapshot;
    RwV3d center;
    RwV3d direction;
    RwV3d eye;
    RwV3d originalDirection;
    f32 targetXZ[2];
    f32 projected[2];
    f32 eyeXZ[2];
    f32 centerXZ[2];
    f32 previousView[2];
    f32 perpendicular[2];
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *actor;
    u8 *target;
    u16 skill;
    f32 actorHeight;
    f32 separation;
    f32 centerOffset;
    f32 targetRadius;
    f32 lateralRadius;
    f32 side;
    f32 targetZ;
    f32 targetY;
    f32 fitRadius;
    f32 distance;
    f32 stepX;
    f32 stepY;
    f32 stepZ;
    f32 endDistance;

    actor = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    target = *(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x38) + 0x30);
    btlUnitGetSphereWorldCenter((BtlUnit *)actor, &actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, &targetPosition);
    actorHeight = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
    actorPosition.y = (0.0f + actorPosition.y) + heightScale * actorHeight;
    if (!((0.0f + actorPosition.y) + 0.5f * actorHeight < 450.0f)) {
        actorPosition.y = (0.0f + actorPosition.y) - fGpffff8030 * actorHeight;
    }
    direction.x = actorPosition.x - targetPosition.x;
    direction.y = actorPosition.y - targetPosition.y;
    direction.z = actorPosition.z - targetPosition.z;
    separation = RwV3dNormalize(&direction, &direction);
    previousView[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    previousView[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(previousView, previousView);
    centerOffset = fGpffff8128 * separation;
    center.x = direction.x * centerOffset;
    center.y = direction.y * centerOffset;
    center.z = direction.z * centerOffset;
    center.x = center.x + targetPosition.x;
    center.y = center.y + targetPosition.y;
    center.z = center.z + targetPosition.z;
    perpendicular[0] = direction.x;
    perpendicular[1] = direction.z;
    targetSnapshot = targetPosition;
    targetRadius = *(f32 *)(target + 0x90);
    targetRadius = targetRadius * *(f32 *)(target + 0x2C);
    lateralRadius = 1.5f * targetRadius;
    {
        f32 x = perpendicular[0];
        perpendicular[0] = perpendicular[1];
        perpendicular[1] = -x;
    }
    side = perpendicular[0] * previousView[0] + perpendicular[1] * previousView[1];
    targetY = targetSnapshot.y;
    eye.y = (0.0f + targetY) + 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    if (!(side < 0.0f)) {
        eye.x = (0.0f + targetSnapshot.x) + direction.z * lateralRadius;
        targetZ = targetSnapshot.z;
        eye.z = (0.0f + targetZ) - direction.x * lateralRadius;
    } else {
        eye.x = (0.0f + targetSnapshot.x) - direction.z * lateralRadius;
        targetZ = targetSnapshot.z;
        eye.z = (0.0f + targetZ) + direction.x * lateralRadius;
    }
    originalDirection = direction;
    btlCameraLookAtQuat(&poses.firstRotation, &eye, &center, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &poses.firstRotation);
    centerXZ[0] = center.x;
    centerXZ[1] = center.z;
    eyeXZ[0] = eye.x;
    eyeXZ[1] = eye.z;
    targetXZ[0] = targetSnapshot.x;
    targetXZ[1] = targetZ;
    fitRadius = btlTargetAngleBetween((u8 *)centerXZ, (u8 *)eyeXZ, (u8 *)targetXZ, (u8 *)projected);
    fitRadius = (0.0f + fitRadius) + scale * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
    eye.x = projected[0];
    eye.y = targetY;
    eye.z = projected[1];
    distance = fitRadius / tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    if (distance < 200.0f) {
        distance = 200.0f;
    }
    skill = *(u16 *)(*(u8 **)(camera + 0xE0) + 0x6E);
    if (skill < 0x1B8) {
        u16 (*table)[2] = (u16 (*)[2])iGpffffb3bc;
        if ((table[skill][1] & 0x400) != 0) {
            distance = distance + 150.0f;
        }
    }
    stepX = direction.x * (distance - 15.0f);
    stepY = direction.y * (distance - 15.0f);
    stepZ = direction.z * (distance - 15.0f);
    if (!(side < 0.0f)) {
        f32 radius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
        eye.x = (0.0f + eye.x) - originalDirection.z * radius;
        eye.z = (0.0f + eye.z) + originalDirection.x * radius;
    }
    eye.y = (0.0f + targetY) + 0.25f * (*(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C));
    poses.first.x = eye.x + stepX;
    poses.first.y = eye.y + stepY;
    poses.first.z = eye.z + stepZ;
    poses.secondRotation = poses.firstRotation;
    endDistance = 100.0f + (distance + distanceOffset);
    poses.second.x = (0.0f + eye.x) + direction.x * endDistance;
    poses.second.y = (0.0f + eye.y) + direction.y * endDistance;
    poses.second.z = (0.0f + eye.z) + direction.z * endDistance;
    if (poses.first.y < 25.0f) {
        poses.first.y = 25.0f;
    }
    if (poses.second.y < 25.0f) {
        poses.second.y = 25.0f;
    }
    btlCameraClampOffsetToLimit((f32 *)&poses.first, (f32 *)&poses.first);
    btlCameraClampOffsetToLimit((f32 *)&poses.second, (f32 *)&poses.second);
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), actor + 4, (f32 *)(target + 4), 50.0f, 3);
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    btlCameraSetDuration(camera, duration);
}

// Intent: Tick the camera mode state machine. [inferred]
// FUN_00226C40
/* 1516/1520 bytes, 48 resolved code relocations and all
 * seven switch targets match retail; four zero tail-alignment bytes. */
/* measured: btlCameraTickModeState MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
void btlCameraTickModeState(u8 *camera)
{
    RwRGBA color;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *subordinate;
    u8 *target;
    u8 *node;
    u8 *record;
    u32 index;
    u32 ordinal;
    u16 partyIndex;
    u16 variant;
    u32 frames;
    s32 matchesSubordinate;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    subordinate = *(u8 **)(unit + 0xA0C);
    if (action != NULL && *(u8 *)(unit + 0xA2) == 0) {
        index = 0;
        while ((action = *(u8 **)(camera + 0xE0)),
               (u16)index < *(u16 *)(action + 0x6A)) {
            target = *(u8 **)(action + 0x38 + (u16)index * 4);
            target = *(u8 **)(target + 0x30);
            if (*(u8 *)(target + 0xA2) == 1) {
                btlUnitFaceTarget((BtlUnit *)target, (const RwV3d *)(unit + 4));
            }
            index = (u16)(index + 1);
        }
    }
    *(u16 *)(camera + 0x110) = btlCameraSelectMode(camera);
    matchesSubordinate = subordinate != NULL &&
        btlUnitSkillBlocked(*(u8 **)(camera + 0xE0), subordinate) != 0;
    if (matchesSubordinate && *(u16 *)(camera + 0x110) != 1) {
        btlUnitHideModel(subordinate);
        color.red = *(u8 *)(subordinate + 0x30);
        color.green = *(u8 *)(subordinate + 0x31);
        color.blue = *(u8 *)(subordinate + 0x32);
        color.alpha = 0;
        btlUnitSetColor((BtlUnit *)subordinate, color);
    }
    btlUnitSetChildValue((BtlUnitStateWork *)subordinate, 0);
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
    case 1:
    case 2:
    case 4:
        btlCameraUpdateMode(camera);
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) != 1) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) != 0) {
            break;
        }
        target = *(u8 **)(action + 0x38);
        if (action == target) {
            break;
        }
        if (*(u8 *)(*(u8 **)(target + 0x30) + 0xA2) != 0) {
            break;
        }
        btlCameraSetupActionGeometry(action, NULL, NULL, 0.0f, 8);
        break;
    case 3:
    case 5:
        action = *(u8 **)(camera + 0xE0);
        unit = *(u8 **)(action + 0x30);
        variant = datCalcRandomBelow(2);
        if (*(u8 *)(unit + 0xA2) != 0) {
            partyIndex = 0;
        } else {
            ordinal = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node) {
                    break;
                }
                ordinal = (u16)(ordinal + 1);
                node = *(u8 **)(node + 0xA68);
            }
            partyIndex = (u16)ordinal;
        }
        record = *(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x68 + (u16)variant * 0x34 + 0x3A8;
        btlCameraLookAtQuat(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
        selected.first = *(RwV3d *)(record + 4);
        btlCameraLookAtQuat(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
        selected.second = *(RwV3d *)(record + 0x1C);
        frames = *(u16 *)record;
        duration = (f32)frames / 30.0f;
        btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                      (f32 *)&selected.first, (f32 *)&selected.second, 1);
        btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        break;
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            btlCameraLookAtQuat(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        } else {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            btlCameraLookAtQuat(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        }
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        break;
    default:
        break;
    }
}

/* measured: btlCameraApplyMode, btlCameraTickUnitAnim MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// Intent: Apply the camera mode selected for the current action. [inferred]
// FUN_00227230
/* 1336/1344 bytes, 48 resolved code relocations and all
 * seven switch targets match retail; eight zero tail-alignment bytes. */
void btlCameraApplyMode(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *record;
    u16 targetFlags;
    u16 variant;
    u32 frames;

    *(u16 *)(camera + 0x110) = btlCameraSelectMode(camera);
    targetFlags = btlTargetGetUnitIndex((BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38));
    *(u32 *)(camera + 0x12C) = 0;
    action = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
        btlUnitSetChildValue(*(BtlUnitStateWork **)(*(u8 **)(action + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
        break;
    case 1:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
            btlCameraUpdateMode(camera);
            break;
        }
    case 2:
        if (((u16)targetFlags & 2) == 0) {
            btlCameraFrameActorTarget(camera, 0.0f, 3.0f, 0.0f, 2.0f);
            break;
        }
    case 4:
        if (((u16)targetFlags & 2) == 0) {
            if (func_00243ce0(*(u8 **)(*(u8 **)(*(u8 **)(camera + 0xE0) + 0x30) + 0xA64)) != 0 &&
                btlActionSkillReachesTargets(*(u8 **)(camera + 0xE0)) != 0) {
                btlCameraFrameTarget(camera, 0.0f, 0.75f);
                break;
            }
            btlCameraFrameActorTarget(camera, 0.0f, 3.0f, 0.0f, 2.0f);
            break;
        }
    case 3:
    case 5:
        if (((u16)targetFlags & 2) != 0) {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
            btlCameraLookAtQuat(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            selected.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            selected.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&selected.first, (f32 *)&selected.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
            break;
        }
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            btlCameraLookAtQuat(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        } else {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            btlCameraLookAtQuat(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        }
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        break;
    default:
        break;
    }
}

// Intent: Tick a camera unit animation until it finishes. [inferred]
// FUN_00227770
void btlCameraTickUnitAnim(u8 *arg0)
{
    u8 *temp_3;
    u8 *temp_5;

    temp_5 = *(u8 **)(arg0 + 0x12C);
    if (temp_5 != NULL) {
        temp_3 = *(u8 **)(arg0 + 0xE0);
        if ((temp_3 != NULL) &&
            ((*(u16 *)(temp_3 + 0x1A) & 1) != 0) &&
            (btlCameraUnitAnimFinished(arg0, temp_5) != 0)) {
            btlUnitSetChildValue(*(BtlUnitStateWork **)(arg0 + 0x12C), *(u16 *)(arg0 + 0x130));
        }
    }
}

// Intent: Apply the party-member camera pose by ordinal. [inferred]
// FUN_002277E0
/* measured: opt_common_subs off preserves per-use 16-bit ordinal masks.
 * Independent target/party ordinals and the materialized subordinate predicate
 * give 1620/1632 bytes, 50 code relocations and zero normalized differences.
 * Each pose pair is two contiguous seven-float poses, without padding. */
/* measured: btlCameraApplyPartyPose MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
void btlCameraApplyPartyPose(u8 *camera)
{
    RwRGBA color;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *subordinate;
    u8 *target;
    u8 *node;
    u8 *record;
    u32 index;
    u32 ordinal;
    u16 partyIndex;
    u16 variant;
    u32 frames;
    s32 matchesSubordinate;

    action = *(u8 **)(camera + 0xE0);
    unit = *(u8 **)(action + 0x30);
    subordinate = *(u8 **)(unit + 0xA0C);
    if (action != NULL && *(u8 *)(unit + 0xA2) == 0) {
        index = 0;
        while ((action = *(u8 **)(camera + 0xE0)),
               (u16)index < *(u16 *)(action + 0x6A)) {
            target = *(u8 **)(action + 0x38 + (u16)index * 4);
            target = *(u8 **)(target + 0x30);
            if (*(u8 *)(target + 0xA2) == 1) {
                btlUnitFaceTarget((BtlUnit *)target, (const RwV3d *)(unit + 4));
            }
            index = (u16)(index + 1);
        }
    }
    *(u16 *)(camera + 0x110) = btlCameraSelectMode(camera);
    matchesSubordinate = subordinate != NULL &&
        btlUnitSkillBlocked(*(u8 **)(camera + 0xE0), subordinate) != 0;
    if (matchesSubordinate && *(u16 *)(camera + 0x110) != 1) {
        btlUnitHideModel(subordinate);
        color.red = *(u8 *)(subordinate + 0x30);
        color.green = *(u8 *)(subordinate + 0x31);
        color.blue = *(u8 *)(subordinate + 0x32);
        color.alpha = 0;
        btlUnitSetColor((BtlUnit *)subordinate, color);
    }
    btlUnitSetChildValue((BtlUnitStateWork *)subordinate, 0);
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
    case 1:
        btlCameraUpdateMode(camera);
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) != 1) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) != 0) {
            break;
        }
        target = *(u8 **)(action + 0x38);
        if (*(u8 *)(*(u8 **)(target + 0x30) + 0xA2) != 0) {
            break;
        }
        btlCameraSetupActionGeometry(action, NULL, NULL, 0.0f, 8);
        break;
    case 2:
    case 4:
        action = *(u8 **)(camera + 0xE0);
        if (*(u16 *)(action + 0x6A) == 1 &&
            *(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0 &&
            (target = *(u8 **)(action + 0x38), action != target) &&
            *(u8 *)(*(u8 **)(target + 0x30) + 0xA2) == 0) {
            btlCameraUpdateMode(camera);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 8);
            break;
        }
    case 3:
    case 5:
        action = *(u8 **)(camera + 0xE0);
        unit = *(u8 **)(action + 0x30);
        variant = datCalcRandomBelow(2);
        if (*(u8 *)(unit + 0xA2) != 0) {
            partyIndex = 0;
        } else {
            ordinal = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node) {
                    break;
                }
                ordinal = (u16)(ordinal + 1);
                node = *(u8 **)(node + 0xA68);
            }
            partyIndex = (u16)ordinal;
        }
        record = *(u8 **)(iGpffffb3ac + 0xB98) +
                 (u16)partyIndex * 0x68 + (u16)variant * 0x34 + 0x3A8;
        btlCameraLookAtQuat(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
        selected.first = *(RwV3d *)(record + 4);
        btlCameraLookAtQuat(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
        selected.second = *(RwV3d *)(record + 0x1C);
        frames = *(u16 *)record;
        duration = (f32)frames / 30.0f;
        btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                      (f32 *)&selected.first, (f32 *)&selected.second, 1);
        btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        break;
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            btlCameraLookAtQuat(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        } else {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            btlCameraLookAtQuat(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        }
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        break;
    default:
        break;
    }
}

/* measured: closing opt_common_subs off for btlCameraApplyPartyPose. */
/* measured: btlActionRunMotionSequence, btlActionRunPresentation, btlCameraApplyEncounterMode, btlCameraApplyTablePose, btlCameraFramePair, btlCameraSetActorPose, btlCameraSetFixedPose, btlCameraSetRandomPartyPose, btlCameraSetRandomSkillPose, btlCameraSetRecordedPose, btlCameraSetSnapshotPose, btlEncounterFinishStep, btlEncounterResetSlots, btlEncounterStartCameraState, btlEncounterStartSequence MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs on
// Intent: Apply the encounter camera mode for each camera state. [inferred]
// FUN_00227E40
/* measured: 1168/1168 bytes, 44 code relocations and zero differences.
 * Preserve the switch fallthrough's repeated target-kind tests and the
 * three distinct, contiguous seven-float pose pairs. No extra pragma. */
void btlCameraApplyEncounterMode(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } selected, player, other;
    f32 duration;
    u8 *action;
    u8 *record;
    u16 targetFlags;
    u16 variant;
    u32 frames;

    *(u16 *)(camera + 0x110) = btlCameraSelectMode(camera);
    targetFlags = btlTargetGetUnitIndex((BtlTarget *)(*(u8 **)(camera + 0xE0) + 0x38));
    *(u32 *)(camera + 0x12C) = 0;
    action = *(u8 **)(camera + 0xE0);
    if ((*(u16 *)(action + 0x1A) & 0x10) != 0) {
        btlUnitSetChildValue(*(BtlUnitStateWork **)(*(u8 **)(action + 0x30) + 0xA0C), 1);
    }
    switch (*(u16 *)(camera + 0x110)) {
    case 0:
        break;
    case 1:
    case 2:
        if (((u16)targetFlags & 2) == 0) {
            btlCameraSelectEncounterPreset(camera);
            break;
        }
        /* Fall through: state 4 has its own identical target-kind test. */
    case 4:
        if (((u16)targetFlags & 2) == 0) {
            btlCameraSelectEncounterPreset(camera);
            break;
        }
        /* Fall through to the shared selected-target camera. */
    case 3:
    case 5:
        if (((u16)targetFlags & 2) != 0) {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
            btlCameraLookAtQuat(&selected.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            selected.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&selected.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            selected.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&selected.first, (f32 *)&selected.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
            btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
            break;
        }
        /* Fall through: absent genus-1 targets use the state-6 camera. */
    case 6:
        action = *(u8 **)(camera + 0xE0);
        if ((*(u16 *)(action + 0x1A) & 1) == 0) {
            break;
        }
        if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
            record = *(u8 **)(iGpffffb3ac + 0xB98) + 0x618;
            btlCameraLookAtQuat(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        } else {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            btlCameraLookAtQuat(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        }
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
        break;
    default:
        break;
    }
}

// Intent: Set a random skill camera pose from the table. [inferred]
// FUN_002282D0
void btlCameraSetRandomSkillPose(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u32 temp_2_2;
    u8 *base;
    u16 *raw;
    u8 *temp_17;
    extern void btlMainApplyUnitBaseColors(u8 *arg0);
    extern void btlCameraFrameActionPair(u8 *camera);

    if (func_00243ce0(
            (u8 *)*(s32 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA64)) != 0) {
        btlMainApplyUnitBaseColors(0);
        index = (u32)(datCalcRandomBelow(2) & 0xFFFF);
        base = *(u8 **)(DAT_0076449c + 0xB98);
        temp_17 = base + index * 0x34 + 0x548;
        btlCameraLookAtQuat(work.quat1, temp_17 + 4, temp_17 + 0x10,
                      D_0060A0E0);
        work.first = *(Vec3 *)(temp_17 + 4);
        btlCameraLookAtQuat(work.quat2, temp_17 + 0x1C, temp_17 + 0x28,
                      D_0060A0E0);
        work.second = *(Vec3 *)(temp_17 + 0x1C);
        raw = (u16 *)temp_17;
        temp_2_2 = *raw;
        if (temp_2_2 >= 0) {
            var_f1 = (f32)temp_2_2;
        } else {
            temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
            var_f1 = (f32)(s32)temp_2_2;
            var_f1 = var_f1 + var_f1;
        }
        var_f1 = var_f1 / 30.0f;
        btlMainCurveSetPoses((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                      (f32 *)&work.second, 1);
        btlCameraSetDuration(DAT_0076449c + 0x24, var_f1);
        btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0, 1);
        return;
    }
    btlCameraFrameActionPair(arg0);
}

// Intent: Tick the skill pose while the unit is free. [inferred]
// FUN_00228480
void btlCameraTickUnitPose(u8 *arg0) {
    if (func_00243ce0((u8 *)*(s32 *)((u8 *)(*(u8 **)((u8 *)(*(u8 **)((u8 *)(arg0) + 0xE0)) + 0x30)) + 0xA64)) == 0) {
        btlCameraFrameUnitTight(arg0);
    }
}

// Intent: Set the fixed camera pose with a 0.75 s duration. [inferred]
// FUN_002284D0
void btlCameraSetFixedPose(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        f32 first[7];
        Vec3 second;
        f32 third[4];
    } work;
    f32 *temp_16;
    u8 *temp_2;

    btlCameraCopyPose((f32 *)&work.first, (f32 *)(arg0 + 0x9C));
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = (f32 *)(temp_2 + 0x6B4);
    btlCameraLookAtQuat(work.third, temp_16, (u8 *)temp_16 + 0xC, D_0060A0E0);
    work.second = *(Vec3 *)temp_16;
    btlMainCurveSetPoses((u16 *)arg0, (f32 *)&work.first, (f32 *)&work.second, 1);
    btlCameraSetDuration(arg0, 0.75f);
}

// Intent: Set a random record camera pose. [inferred]
// FUN_00228580
void btlCameraSetRandomRecordPose(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u16 temp_2_2;
    u8 *base;
    u8 *temp_16;
    u8 *temp_2;

    index = (u32)(datCalcRandomBelow(2) & 0xFFFF);
    base = *(u8 **)(DAT_0076449c + 0xB98);
    temp_2 = base + index * 0x34;
    temp_16 = temp_2 + 0x64C;
    btlCameraLookAtQuat(work.quat1, temp_16 + 4, temp_16 + 0x10, D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    btlCameraLookAtQuat(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
        D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    var_f1 = (f32)temp_2_2 / 30.0f;
    btlMainCurveSetPoses((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    btlCameraSetDuration(DAT_0076449c + 0x24, var_f1);
}

// Intent: Set a random selected camera pose from the pose table. [inferred]
// FUN_002286C0
void btlCameraSetRandomSelectedPose(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 index;
    u16 temp_2_2;
    u8 *base;
    u8 *temp_16;
    u8 *temp_2;

    index = (u32)(datCalcRandomBelow(2) & 0xFFFF);
    base = *(u8 **)(DAT_0076449c + 0xB98);
    temp_2 = base + index * 0x34;
    temp_16 = temp_2 + 0x5B0;
    btlCameraLookAtQuat(work.quat1, temp_16 + 4, temp_16 + 0x10, D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    btlCameraLookAtQuat(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
        D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    var_f1 = (f32)temp_2_2 / 30.0f;
    btlMainCurveSetPoses((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    btlCameraSetDuration(DAT_0076449c + 0x24, var_f1);
}

// Intent: Apply a camera pose from the fixed table entry. [inferred]
// FUN_00228800
void btlCameraApplyTablePose(s32 arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vector3;
    struct {
        Vector3 position;
        u8 transform[20];
    } values;
    f32 *temp;

    temp = (f32 *)(*(u8 **)(DAT_0076449c + 0xB98) + 0x6CC);
    btlCameraLookAtQuat(values.transform, temp, temp + 3, D_0060A0E0);
    values.position = *(Vector3 *)temp;
    btlMainCurveReset((u16 *)(DAT_0076449c + 0x24), (f32 *)&values.position);
    btlCameraCopyPoseSnapshot((f32 *)((u8 *)arg0 + 0x9C), (f32 *)&values.position);
}

// Intent: Set the recorded camera pose from the pose table. [inferred]
// FUN_00228890
void btlCameraSetRecordedPose(void)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    u32 temp_2_2;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = *(u8 **)(DAT_0076449c + 0xB98);
    temp_16 = temp_2 + 0x6E4;
    btlCameraLookAtQuat(work.quat1, temp_16 + 4, temp_16 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16 + 4);
    btlCameraLookAtQuat(work.quat2, temp_16 + 0x1C, temp_16 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16 + 0x1C);
    temp_2_2 = *(u16 *)temp_16;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    btlMainCurveSetPoses((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    btlCameraSetDuration(DAT_0076449c + 0x24, var_f1);
}

// Intent: Start a random effect camera sequence for the unit. [inferred]
// FUN_002289B0
void btlCameraStartRandomEffect(u8 *arg0)
{
    u16 temp_16;
    u32 flag_offset;
    u32 index_offset;
    u8 *temp_2;
    u8 *target;

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(temp_2 + 0x30);
    temp_16 = *(u16 *)(temp_2 + 0xA4);
    flag_offset = (effMiscRand(0) & 1) * 0xF4;
    index_offset = (temp_16 & 0xFFFF) * 0x1E8;
    target = (u8 *)&D_00632240 + index_offset;
    btlCameraStartEffect(arg0, target + flag_offset, 8);
    btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0.0f, 3);
}

// Intent: Tick the camera effect list. [inferred]
// FUN_00228A60
void btlCameraTickEffects(void)
{
    btlCameraUpdateEffectList();
}

// Intent: Set a random camera pose from a party member. [inferred]
// FUN_00228A80
void btlCameraSetRandomPartyPose(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    s32 temp_5;
    s32 var_2;
    u8 *var_4;
    s32 var_3;
    u16 temp_16;
    u32 flag_offset;
    u32 index_offset;
    u32 temp_2_2;
    u8 *temp_16_2;
    u8 *temp_17;
    u8 *temp_2;
    extern u8 D_00633740[];

    temp_17 = *(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30);
    temp_16 = *(u16 *)(temp_17 + 0xA4);
    if (btlActionHasNoTargetClass((u32)*(u8 **)(arg0 + 0xE0)) != 0) {
        flag_offset = (effMiscRand(0) & 1) * 0xF4;
        index_offset = ((temp_16 & 0xFFFF) - 2) * 0x1E8;
        btlCameraStartEffect(arg0, (u8 *)&D_00633740 + index_offset + flag_offset, 8);
        btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0, 3);
        return;
    }
    temp_5 = datCalcRandomBelow(2) & 0xFFFF;
    if (*(u8 *)(temp_17 + 0xA2) != 0) {
        var_2 = 0;
    } else {
        var_3 = 0;
        var_4 = *(u8 **)(DAT_0076449c + 0x17C);
        goto loop_7_check;
loop_7:
        if (temp_17 == var_4) {
            goto loop_7_done;
        }
        var_3 = (var_3 + 1) & 0xFFFF;
        var_4 = *(u8 **)(var_4 + 0xA68);
        goto loop_7_check;
loop_7_check:
        if (var_4 != NULL) {
            goto loop_7;
        }
loop_7_done:
        var_2 = var_3 & 0xFFFF;
    }
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
             ((var_2 & 0xFFFF) * 0x68) +
             ((temp_5 & 0xFFFF) * 0x34);
    temp_16_2 = temp_2 + 0x3A8;
    btlCameraLookAtQuat(work.quat1, temp_16_2 + 4, temp_16_2 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16_2 + 4);
    btlCameraLookAtQuat(work.quat2, temp_16_2 + 0x1C, temp_16_2 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16_2 + 0x1C);
    temp_2_2 = *(u16 *)temp_16_2;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    btlMainCurveSetPoses((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    btlCameraSetDuration(DAT_0076449c + 0x24, var_f1);
    btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0, 0x100);
}

// Intent: Tick the effect list when the unit is active. [inferred]
// FUN_00228D00
void btlCameraTickEffectsIfActive(u8 *arg0) {
    if (btlActionHasNoTargetClass((u32)*(u8 **)((u8 *)(arg0) + 0xE0)) != 0) {
        btlCameraUpdateEffectList(arg0);
    }
}

// Intent: Set the camera pose for the actor. [inferred]
// FUN_00228D50
void btlCameraSetActorPose(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    struct Work {
        Vec3 first;
        f32 quat1[4];
        Vec3 second;
        f32 quat2[4];
    } work;
    f32 var_f1;
    s32 temp_5;
    s32 var_2;
    u8 *var_4;
    s32 var_3;
    u32 temp_2_2;
    u8 *temp_16;
    u8 *temp_16_2;
    u8 *temp_2;

    if (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0xE0) + 0x30) + 0xA2) == 0) {
        btlCameraFrameActionCutscene(arg0);
        return;
    }
    temp_16 = *(u8 **)(*(u8 **)(DAT_0076449c + 0x170) + 0x30);
    temp_5 = datCalcRandomBelow(2) & 0xFFFF;
    if (*(u8 *)(temp_16 + 0xA2) != 0) {
        var_2 = 0;
    } else {
        var_3 = 0;
        var_4 = *(u8 **)(DAT_0076449c + 0x17C);
        goto loop_7_check;
loop_7:
        if (temp_16 == var_4) {
            goto loop_7_done;
        }
        var_3 = (var_3 + 1) & 0xFFFF;
        var_4 = *(u8 **)(var_4 + 0xA68);
        goto loop_7_check;
loop_7_check:
        if (var_4 != NULL) {
            goto loop_7;
        }
loop_7_done:
        var_2 = var_3 & 0xFFFF;
    }
    temp_2 = *(u8 **)(DAT_0076449c + 0xB98) +
             ((var_2 & 0xFFFF) * 0x68) +
             ((temp_5 & 0xFFFF) * 0x34);
    temp_16_2 = temp_2 + 0x3A8;
    btlCameraLookAtQuat(work.quat1, temp_16_2 + 4, temp_16_2 + 0x10,
                  D_0060A0E0);
    work.first = *(Vec3 *)(temp_16_2 + 4);
    btlCameraLookAtQuat(work.quat2, temp_16_2 + 0x1C, temp_16_2 + 0x28,
                  D_0060A0E0);
    work.second = *(Vec3 *)(temp_16_2 + 0x1C);
    temp_2_2 = *(u16 *)temp_16_2;
    if (temp_2_2 >= 0) {
        var_f1 = (f32)temp_2_2;
    } else {
        temp_2_2 = (temp_2_2 >> 1) | (temp_2_2 & 1);
        var_f1 = (f32)(s32)temp_2_2;
        var_f1 = var_f1 + var_f1;
    }
    var_f1 = var_f1 / 30.0f;
    btlMainCurveSetPoses((u16 *)(DAT_0076449c + 0x24), (f32 *)&work.first,
                  (f32 *)&work.second, 1);
    btlCameraSetDuration(DAT_0076449c + 0x24, var_f1);
    btlCameraSetupActionGeometry(*(u8 **)(arg0 + 0xE0), NULL, NULL, 0, 0x100);
}

// Intent: Set the camera pose from the snapshot table or the frame. [inferred]
// FUN_00228F60
void btlCameraSetSnapshotPose(u8 *arg0)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vector3;
    struct {
        Vector3 position;
        u8 transform[20];
    } values;
    f32 *temp;
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0xE0);
    temp_2 = *(u8 **)(temp_2 + 0x30);
    if (*(u8 *)(temp_2 + 0xA2) != 0) {
        goto body;
    }
    btlCameraFrameActionCutscene(arg0);
    return;
body:
    temp = (f32 *)(*(u8 **)(DAT_0076449c + 0xB98) + 0x6CC);
    btlCameraLookAtQuat(values.transform, temp, temp + 3, D_0060A0E0);
    values.position = *(Vector3 *)temp;
    btlMainCurveReset((u16 *)(DAT_0076449c + 0x24), (f32 *)&values.position);
    btlCameraCopyPoseSnapshot((f32 *)((u8 *)arg0 + 0x9C), (f32 *)&values.position);
}

/* 2444/2448 bytes; all 56 resolved code relocations exact. */
// Intent: Frame the camera on the actor and target pair with a full pose set. [inferred]
// FUN_00229020
void btlCameraFramePair(u8 *camera)
{
    RwV3d firstCenter;
    RwV3d secondCenter;
    RwV3d lookAt;
    RwV3d anchor;
    RwV3d direction;
    f32 firstXZ[2];
    f32 projectedXZ[2];
    f32 sideXZ[2];
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    };
    struct {
        f32 lookAtXZ[2];
        f32 anchorXZ[2];
        f32 perpendicular[2];
        f32 cameraSide[2];
        struct CameraPosePair poses;
    } geometry;
    struct CameraPosePair player, other;
    f32 side;
    f32 radius;
    f32 firstHeight;
    f32 secondHeight;
    f32 distance;
    f32 scale;
    f32 angle;
    f32 duration;
    u8 *action;
    u8 *unit;
    u8 *first;
    u8 *second;
    u8 *target;
    u8 *record;
    u32 index;
    u32 frames;
    u16 variant;
    s32 reverseSide;
    s32 allowCut;
    s32 forceActorSide;

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL) {
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            index = 0;
            while ((action = *(u8 **)(camera + 0xE0)),
                   (u16)index < *(u16 *)(action + 0x6A)) {
                target = *(u8 **)(action + 0x38 + (index & 0xFFFF) * 4);
                target = *(u8 **)(target + 0x30);
                if (*(u8 *)(target + 0xA2) == 1) {
                    btlUnitFaceTarget((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
    }
    if (action == NULL) {
        allowCut = 1;
    } else if (*(u8 *)(*(u8 **)(action + 0x30) + 0xA2) == 0) {
        switch (*(u16 *)(iGpffffb3ac + 0x108)) {
        case 0x21:
        case 0x22:
            allowCut = 0;
            break;
        default:
            goto allow_cut;
        }
    } else {
        switch (*(u16 *)(iGpffffb3ac + 0x108)) {
        case 0x16:
        case 0x24:
            allowCut = 0;
            break;
        default:
allow_cut:
            allowCut = 1;
            break;
        }
    }
    second = *(u8 **)(action + 0x30);
    if (*(u8 *)(second + 0xA2) == 0) {
        target = (u8 *)*(u32 *)(camera + 0xE0);
        first = second;
        target = *(u8 **)(target + 0x38);
        second = *(u8 **)(target + 0x30);
        reverseSide = 0;
        forceActorSide = 1;
    } else {
        target = *(u8 **)((u8 *)*(u32 *)(camera + 0xE0) + 0x38);
        first = *(u8 **)(target + 0x30);
        reverseSide = 1;
        forceActorSide = 0;
    }
    if (*(u8 *)(first + 0xA2) == *(u8 *)(second + 0xA2)) {
        if (*(u8 *)(first + 0xA2) == 0) {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x64C;
            btlCameraLookAtQuat(&player.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            player.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&player.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            player.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&player.first, (f32 *)&player.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        } else {
            variant = datCalcRandomBelow(2);
            record = *(u8 **)(iGpffffb3ac + 0xB98) + (u16)variant * 0x34 + 0x5B0;
            btlCameraLookAtQuat(&other.firstRotation, record + 4, record + 0x10, D_0060A0E0);
            other.first = *(RwV3d *)(record + 4);
            btlCameraLookAtQuat(&other.secondRotation, record + 0x1C, record + 0x28, D_0060A0E0);
            other.second = *(RwV3d *)(record + 0x1C);
            frames = *(u16 *)record;
            duration = (f32)frames / 30.0f;
            btlMainCurveSetPoses((u16 *)(iGpffffb3ac + 0x24),
                          (f32 *)&other.first, (f32 *)&other.second, 1);
            btlCameraSetDuration(iGpffffb3ac + 0x24, duration);
        }
        return;
    }

    btlCameraCopyPose((f32 *)&geometry.poses.first, (f32 *)(camera + 0x9C));
    btlUnitGetGridSphereCenter((BtlUnit *)first, &firstCenter);
    btlUnitGetGridSphereCenter((BtlUnit *)second, &secondCenter);
    radius = *(f32 *)(first + 0x90) * *(f32 *)(first + 0x2C);
    firstHeight = (0.0f + firstCenter.y) + 0.5f *
        (*(f32 *)(first + 0x8C) * *(f32 *)(first + 0x2C));
    secondHeight = (0.0f + secondCenter.y) + 0.5f *
        (*(f32 *)(second + 0x8C) * *(f32 *)(second + 0x2C));
    direction.x = firstCenter.x - secondCenter.x;
    direction.y = firstCenter.y - secondCenter.y;
    direction.z = firstCenter.z - secondCenter.z;
    scale = fGpffff8118 * RwV3dNormalize(&direction, &direction);
    lookAt.x = direction.x * scale;
    lookAt.y = direction.y * scale;
    lookAt.z = direction.z * scale;
    lookAt.x += secondCenter.x;
    lookAt.y += secondCenter.y;
    lookAt.z += secondCenter.z;
    geometry.cameraSide[0] = *(f32 *)(camera + 0x9C) - lookAt.x;
    geometry.cameraSide[1] = *(f32 *)(camera + 0xA4) - lookAt.z;
    func_003e41e0(geometry.cameraSide, geometry.cameraSide);
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.cameraSide[0] + geometry.perpendicular[1] * geometry.cameraSide[1];
    if (reverseSide == 0) {
        scale = 1.5f * radius;
    } else {
        scale = 2.5f * radius;
    }
    if (!(side < 0.0f)) {
        anchor.x = (0.0f + firstCenter.x) + direction.z * scale;
        anchor.z = (0.0f + firstCenter.z) - direction.x * scale;
    } else {
        anchor.x = (0.0f + firstCenter.x) - direction.z * scale;
        anchor.z = (0.0f + firstCenter.z) + direction.x * scale;
    }
    if (reverseSide == 0) {
        if (firstHeight < secondHeight) {
            anchor.y = firstHeight;
            lookAt.y = (0.0f + lookAt.y) - fGpffff8118 * secondHeight;
        } else {
            anchor.y = (0.0f + firstCenter.y) - fGpffff8030 * firstHeight;
            lookAt.y = (0.0f + lookAt.y) + fGpffff8030 * secondHeight;
        }
        distance = 2.5f * radius;
    } else {
        anchor.y = firstHeight;
        lookAt.y = (0.0f + lookAt.y) - fGpffff8118 * secondHeight;
        distance = 3.5f * radius;
    }
    btlCameraLookAtQuat(&geometry.poses.secondRotation, &anchor, &lookAt, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &geometry.poses.secondRotation);
    geometry.lookAtXZ[0] = lookAt.x;
    geometry.lookAtXZ[1] = lookAt.z;
    geometry.anchorXZ[0] = anchor.x;
    geometry.anchorXZ[1] = anchor.z;
    firstXZ[0] = firstCenter.x;
    firstXZ[1] = firstCenter.z;
    scale = btlTargetAngleBetween((u8 *)geometry.lookAtXZ, (u8 *)geometry.anchorXZ, (u8 *)firstXZ, (u8 *)projectedXZ);
    scale += distance;
    distance = scale;
    anchor.x = projectedXZ[0];
    anchor.z = projectedXZ[1];
    distance /= tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
    direction.x *= distance;
    direction.y *= distance;
    direction.z *= distance;
    if (side < 0.0f) {
        scale = distance * tanf(fGpffff8110 * (0.5f * *(f32 *)(camera + 0xB8)));
        scale *= 0.21875f;
        firstHeight = scale;
        firstHeight *= 1.25f;
        sideXZ[0] = direction.x;
        sideXZ[1] = direction.z;
        func_003e41e0(sideXZ, sideXZ);
        anchor.x = (0.0f + anchor.x) + sideXZ[1] * firstHeight;
        anchor.z = (0.0f + anchor.z) - sideXZ[0] * firstHeight;
    }
    geometry.poses.second.x = anchor.x + direction.x;
    geometry.poses.second.y = anchor.y + direction.y;
    geometry.poses.second.z = anchor.z + direction.z;
    if (geometry.poses.second.y < 25.0f) {
        geometry.poses.second.y = 25.0f;
    }
    angle = btlTargetQuatAngle(&geometry.poses.firstRotation, &geometry.poses.secondRotation);
    if (forceActorSide == 1 || !(angle <= fGpffff80e4)) {
        if (allowCut == 1) {
            geometry.poses.firstRotation = geometry.poses.secondRotation;
            RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1, &geometry.poses.secondRotation);
            scale = 200.0f + distance;
            direction.x *= scale;
            direction.y *= scale;
            direction.z *= scale;
            geometry.poses.first.x = anchor.x + direction.x;
            geometry.poses.first.y = anchor.y + direction.y;
            geometry.poses.first.z = anchor.z + direction.z;
            if (geometry.poses.first.y < 25.0f) {
                geometry.poses.first.y = 25.0f;
            }
            CrossfadeRequest(5);
        }
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&geometry.poses.first, (f32 *)&geometry.poses.second, 1);
    btlCameraSetDuration(camera, 1.5f);
}

/* measured: opt_propagation off preserves btlEncounterStartSequence's initial GP-load/store order (nd 0). */
/* measured: btlEncounterStartSequence MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: Start the encounter presentation sequence (formation, camera state, packets). [inferred]
// FUN_002299B0
void btlEncounterStartSequence(u8 *arg0)
{
    u8 *saved_arg0;
    u32 payload[8];
    s32 temp_17;
    u8 *var_16;
    u8 *temp_5;
    temp_5 = DAT_0076449c;
    *(s16 *)(temp_5 + 0xC34) = 0;
    saved_arg0 = arg0;
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(s32 *)(temp_3 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3;
        temp_3 = DAT_0076449c;
        *(u16 *)(temp_3 + 0x18) =
            (u16)(*(u16 *)(temp_3 + 0x18) | 0x23);
    }
    btlActionFinishPresentation((s64 *)saved_arg0);
    temp_17 = btlFormationAllocWork(0);
    btlFormationCopyRecord((int)temp_17, (u32)btlFormationGetRecord(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)btlActionGetActiveOrQueueFront();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2;
        temp_2 = btlCameraCreateSetStatePacket(saved_arg0, 0x2D);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        btlPacketEnqueue(temp_2, 0);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)btlUnitCreateColorPacket((BtlUnit *)(*(u8 **)(saved_arg0 + 0x30)),
                              0xFFFFFF, 0x50, 0, 4, 0);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        btlPacketEnqueue(temp_2, 1);
    }
    var_16 = saved_arg0;
    {
        s32 temp_2;
        u8 *temp_2_5;

        temp_2 = (s32)btlUnitFindInSideById(1, 0x106);
        if (temp_2 == 0) {
            goto after_ef90;
        }
        var_16 = (u8 *)btlActionFindByUnit(temp_2);
        btlTargetClearResultBuffer((u8 *)payload);
        payload[2] = 0x100000;
        temp_2_5 = (u8 *)btlTargetCreateDataPacket((s32)(u32)var_16, (s32)(u32)var_16,
                                      (void *)payload, 1, 1);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        btlPacketEnqueue(temp_2_5, 1);
        temp_2_5 = btlUnitCreateAnimPacket(*(u8 **)(var_16 + 0x30),
                                 9, 0, 0, 1.0f);
        *(u16 *)(temp_2_5 + 0x48) = 0x20;
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)saved_arg0;
        btlPacketEnqueue(temp_2_5, 0);
after_ef90:
        ;
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_006354B0);
        *(u16 *)(temp_2 + 0x48) = 2;
        btlPacketEnqueue(temp_2, 1);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)btlFormationCreatePacket((u32)temp_17,
                                    *(u32 *)(saved_arg0 + 0x30),
                                    *(u32 *)(var_16 + 0x30), 0, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        btlPacketEnqueue(temp_2, 2);
    }
    {
        u8 *temp_2;
        temp_2 = (u8 *)btlFormationCreatePacket((u32)temp_17,
                                    *(u32 *)(saved_arg0 + 0x30),
                                    *(u32 *)(var_16 + 0x30), 1, 0x200);
        *(s64 *)(temp_2 + 0x60) = *(s64 *)saved_arg0;
        btlPacketEnqueue(temp_2, 2);
    }
    btlFormationSetPlacement(temp_17);
}

/* measured: close opt_propagation after btlEncounterStartSequence (nd 0). */
/* measured: btlActionRunPresentation MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: Finish the encounter step; return 1 while the action is still active. [inferred]
// FUN_00229C40
s32 btlEncounterFinishStep(u8 *arg0)
{
    u8 *temp_2_2;
    u8 *temp_2;
    u8 *temp_4_3;

    if (btlUnitRecordFindByActionUID(*(u64 *)arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        temp_2 = (u8 *)btlUnitFindInSideById(1, 0x106);
        if (temp_2 != NULL) {
            temp_2_2 = (u8 *)btlActionFindByUnit((s32)temp_2);
            *(u16 *)(temp_2_2 + 0x1A) =
                (u16)(*(u16 *)(temp_2_2 + 0x1A) | 8);
            *(s32 *)(*(u8 **)(temp_2_2 + 0x30) + 0x9C) |= 8;
            *(u16 *)(*(u8 **)(*(u8 **)(temp_2_2 + 0x30) + 0xA64)) &= 0xFFDF;
        }
        *(u16 *)(arg0 + 0x1A) =
            (u16)(*(u16 *)(arg0 + 0x1A) & 0xFFF7);
        *(u16 *)(arg0 + 0x1A) =
            (u16)(*(u16 *)(arg0 + 0x1A) | 0x400);
        *(s32 *)(*(u8 **)(arg0 + 0x30) + 0x9C) &= ~8;
        btlUnitHideModel(*(u8 **)(arg0 + 0x30));
        datCalcClearAllBuffs(*(u8 **)(*(u8 **)(arg0 + 0x30) + 0xA64));
        btlUnitUpdateStatusMotion(*(u8 **)(arg0 + 0x30), 0);
        btlUnitSetMotion(*(u8 **)(arg0 + 0x30), 0, 0, 1.0f, 1);
        *(u8 **)(DAT_0076449c + 0xB98) = &D_0062D920[0];
        temp_4_3 = DAT_0076449c;
        *(s32 *)(temp_4_3 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// Intent: Run the action presentation packet sequence. [inferred]
// FUN_00229DA0
/* 2312/2320 bytes; 75 resolved code relocations and nine switch entries exact. */
void btlActionRunPresentation(u8 *action)
{
    s32 formation;
    u8 *packet;
    u8 *initialAnimation;
    u8 *formationPacket;
    u8 *sequencePacket;
    u8 *statusAnimation;
    u8 *returnPacket;
    u8 *finishPacket;
    u8 *returnTarget;
    u8 *unit;
    u8 *returnUnit;
    u8 *node;
    u8 *returnNode;
    u32 targetIndex;
    u32 returnIndex;
    u16 slot;
    u32 rosterIndex;
    u32 delay;
    u32 positionOffset;
    s16 animationFrames;
    union {
        u32 words[8];
        u16 halves[16];
        u8 bytes[0x20];
    } targetParams, statusParams;

    formation = btlFormationAllocWork(0);
    btlFormationCopyRecord(formation, (u32)btlFormationGetRecord(0xC));
    *(u32 *)(iGpffffb3ac + 0xC) |= 0x80000;

    packet = (u8 *)btlEffectCreateSpriteFramePacket(*(u32 *)(action + 0x30),
                                *(u16 *)(action + 0x6E));
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 3);

    packet = btlCameraCreateSetStatePacket(action, 0x1A);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 0);

    initialAnimation = btlUnitCreateAnimPacket(*(u8 **)(action + 0x30), 0xF, 0, 2, 1.0f);
    *(u64 *)(initialAnimation + 0x60) = *(u64 *)action;
    *(u16 *)(initialAnimation + 0x4A) = 0xC8;
    btlPacketEnqueue(initialAnimation, 0);

    if (*(u16 *)(action + 0x6A) == 1) {
        packet = (u8 *)btlUnitCreateRotateTowardUnitPacket(
            *(BtlUnit **)(action + 0x30),
            *(BtlUnit **)(*(u8 **)(action + 0x38) + 0x30), 2);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        btlPacketEnqueue(packet, 0);
    } else {
        packet = (u8 *)btlUnitCreateRotatePacket(
            *(BtlUnit **)(action + 0x30), (const RwV3d *)D_006354C0, 2);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        btlPacketEnqueue(packet, 1);
    }

    unit = *(u8 **)(action + 0x30);
    formationPacket = (u8 *)btlFormationCreatePacket((u32)formation, (u32)unit,
                                         (u32)unit, 0, 0x200);
    *(u64 *)(formationPacket + 0x60) = *(u64 *)action;
    btlPacketEnqueue(formationPacket, 2);

    packet = (u8 *)btlSoundCreateChannelCuePacket(0xC, 5, 0xE);
    *(u16 *)(packet + 0x48) = 0x5A;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 1);

    btlTargetClearResultBuffer(targetParams.bytes);
    targetParams.words[2] = 0x100;
    btlTargetClearResultBuffer(statusParams.bytes);
    statusParams.words[3] = 0x100001;
    delay = 0;
    targetIndex = 0;
    while ((u16)targetIndex < *(u16 *)(action + 0x6A)) {
        u8 *target = *(u8 **)(action + (u32)(u16)targetIndex * 4 + 0x38);
        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0)
            goto next_target;
        if (*(u16 *)(unit + 0xA4) == 1)
            goto next_target;
        if ((*(u16 *)(target + 0x1A) & 1) == 0)
            goto next_target;
        if (datCalcIsDead(*(u8 **)(unit + 0xA64), 0) != 0)
            goto next_target;

        unit = *(u8 **)(target + 0x30);
        if (unit[0xA2] != 0) {
            slot = 0;
        } else {
            rosterIndex = 0;
            node = *(u8 **)(iGpffffb3ac + 0x17C);
            while (node != NULL) {
                if (unit == node)
                    break;
                rosterIndex = (u16)(rosterIndex + 1);
                node = *(u8 **)(node + 0xA68);
            }
            slot = (u16)rosterIndex;
        }

        formationPacket = (u8 *)btlFormationCreatePacket((u32)formation,
            *(u32 *)(action + 0x30), (u32)unit, 1, 0x200);
        *(u16 *)(formationPacket + 0x48) = (u16)delay;
        *(u64 *)(formationPacket + 0x60) = *(u64 *)action;
        btlPacketEnqueue(formationPacket, 2);

        packet = (u8 *)btlSoundCreateChannelCuePacket(0xC, 5, 0xE);
        *(u16 *)(packet + 0x48) = 0x6C;
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        btlPacketEnqueue(packet, 1);

        positionOffset = (u32)slot * 12;
        unit = *(u8 **)(target + 0x30);
        btlTargetPositionToCell((s16 *)(unit + 0x94), (s16 *)(unit + 0x96),
                      (f32 *)(D_00635500 + positionOffset));
        *(u16 *)(target + 0x1A) &= 0xFFF7;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x20;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 8;
        **(u16 **)(*(u8 **)(target + 0x30) + 0xA64) |= 0x10;

        if (datCalcChkBadStatus((s32)*(u8 **)(*(u8 **)(target + 0x30) + 0xA64),
                          0x100000) != 0) {
            statusAnimation = btlUnitCreateAnimPacket(*(u8 **)(target + 0x30),
                                            0xB, 0, 0, 1.0f);
            statusAnimation[0] = 0xB;
            *(u64 *)(statusAnimation + 8) = *(u64 *)(formationPacket + 0x58);
            *(u64 *)(statusAnimation + 0x60) = *(u64 *)action;
            btlPacketEnqueue(statusAnimation, 0);

            packet = (u8 *)btlTargetCreateDataPacket((s32)(u32)target, (s32)(u32)target,
                                         statusParams.bytes, 1, 1);
            packet[0] = 4;
            *(u64 *)(packet + 8) = *(u64 *)(statusAnimation + 0x58);
            *(u64 *)(packet + 0x60) = *(u64 *)action;
            btlPacketEnqueue(packet, 1);
            animationFrames = btlUnitMotionModelFrames(*(u8 **)(target + 0x30), 0xB, 1.0f);
        } else {
            animationFrames = 0;
        }

        sequencePacket = (u8 *)btlUnitCreateMovePacket(
            *(BtlUnit **)(target + 0x30),
            (const RwV3d *)(D_006354D0 + positionOffset), 0.5f, 8);
        sequencePacket[0] = 0xB;
        *(u64 *)(sequencePacket + 8) = *(u64 *)(formationPacket + 0x58);
        *(s16 *)(sequencePacket + 0x48) = animationFrames;
        *(u64 *)(sequencePacket + 0x60) = *(u64 *)action;
        btlPacketEnqueue(sequencePacket, 1);

        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(target + 0x30),
                                                 (const RwV3d *)D_006354C0, 0);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(sequencePacket + 0x58);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        btlPacketEnqueue(packet, 1);

        if (datCalcIsGuarding(*(u16 **)(*(u8 **)(target + 0x30) + 0xA64)) != 0)
            targetParams.halves[15] |= 0x80;
        else
            targetParams.halves[15] &= 0xFF7F;
        packet = (u8 *)btlTargetCreateDataPacket((s32)(u32)target, (s32)(u32)target,
                                     targetParams.bytes, 1, 1);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(sequencePacket + 0x58);
        *(u16 *)(packet + 0x48) = 8;
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        btlPacketEnqueue(packet, 1);

        switch (*(u16 *)(*(u8 **)(target + 0x30) + 0xA4)) {
        case 2:
            datSetFlag(0x15CF, 1);
            break;
        case 3:
            datSetFlag(0x15D0, 1);
            break;
        case 4:
            datSetFlag(0x15D1, 1);
            break;
        case 6:
            datSetFlag(0x15D2, 1);
            break;
        case 8:
            datSetFlag(0x15D3, 1);
            break;
        case 7:
            datSetFlag(0x15D4, 1);
            break;
        }
        delay += (u16)btlUnitSlotValueOrOne(0x17B);
next_target:
        targetIndex = (u16)(targetIndex + 1);
    }

    *(u16 *)(iGpffffb3ac + 0x18) = 0;
    *(u32 *)(iGpffffb3ac + 0xC) &= 0xFFBFFFFF;
    finishPacket = btlCameraCreateSetStatePacket(action, 0x2C);
    finishPacket[0] = 4;
    *(u64 *)(finishPacket + 8) = *(u64 *)(initialAnimation + 0x58);
    if (formationPacket != NULL) {
        finishPacket[0x10] = 4;
        *(u64 *)(finishPacket + 0x18) = *(u64 *)(formationPacket + 0x58);
    }
    *(u64 *)(finishPacket + 0x60) = *(u64 *)action;
    btlPacketEnqueue(finishPacket, 0);

    packet = (u8 *)btlFormationCreateSlotPacket(2, 0xFFF);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(finishPacket + 0x58);
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 0);

    packet = btlUnitCreateAnimPacket(*(u8 **)(action + 0x30), 0xB, 0, 0, 1.0f);
    packet[0] = 4;
    *(u64 *)(packet + 8) = *(u64 *)(finishPacket + 0x58);
    *(u16 *)(packet + 0x4A) = 0x60;
    *(u64 *)(packet + 0x60) = *(u64 *)action;
    btlPacketEnqueue(packet, 0);

    returnIndex = 0;
    while ((u16)returnIndex < *(u16 *)(action + 0x6A)) {
        returnTarget = *(u8 **)(action + (u32)(u16)returnIndex * 4 + 0x38);
        returnUnit = *(u8 **)(returnTarget + 0x30);
        if (returnUnit[0xA2] != 0)
            goto next_return_target;
        if (*(u16 *)(returnUnit + 0xA4) == 1)
            goto next_return_target;
        if ((*(u16 *)(returnTarget + 0x1A) & 1) == 0)
            goto next_return_target;
        if (datCalcIsDead(*(u8 **)(returnUnit + 0xA64), 0) != 0)
            goto next_return_target;

        returnUnit = *(u8 **)(returnTarget + 0x30);
        if (returnUnit[0xA2] == 0) {
            returnNode = *(u8 **)(iGpffffb3ac + 0x17C);
            while (returnNode != NULL) {
                if (returnUnit == returnNode)
                    break;
                returnNode = *(u8 **)(returnNode + 0xA68);
            }
        }

        returnPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)returnUnit,
                                                       NULL, fGpffff809c, 0x18);
        returnPacket[0] = 4;
        *(u64 *)(returnPacket + 8) = *(u64 *)(finishPacket + 0x58);
        *(u64 *)(returnPacket + 0x60) = *(u64 *)action;
        btlPacketEnqueue(returnPacket, 1);

        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(returnTarget + 0x30),
                                                 (const RwV3d *)D_006354C0, 0);
        packet[0] = 4;
        *(u64 *)(packet + 8) = *(u64 *)(returnPacket + 0x58);
        *(u64 *)(packet + 0x60) = *(u64 *)action;
        btlPacketEnqueue(packet, 1);
next_return_target:
        returnIndex = (u16)(returnIndex + 1);
    }
    btlFormationSetPlacement((u32)formation);
}

// Intent: Wait until the target presentation finishes, then clear its flag. [inferred]
// FUN_0022A6B0
s32 btlEncounterWaitCleared(s64 *arg0) {
    u8 *temp_4;

    if (btlUnitRecordFindByActionUID(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        datSetFlag(0x15FF, 1);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

/* The scan records the last affected entry; when none exists, retail tests
   `last` without a store (an unwritten saved register at 0022a80c). The C
   keeps that exact test of the uninitialised local. */
// Intent: Run the unit motion request sequence for the action. [inferred]
// FUN_0022A730
void btlActionRunMotionSequence(u8 *arg0)
{
    extern u8 *btlUnitCreateMotionRequestPacket(u8 *arg0, u16 arg1);
    extern f32 btlUnitGetGroupBounds(u32 arg0, u32 arg1, RwV3d *arg2, f32 *arg3, f32 *arg4, u32 arg5);
    extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
    extern u8 D_00635530[];
    union {
        u32 words[8];
        u8 bytes[0x20];
    } params;
    RwV3d center;
    s32 moveDelay;
    u8 *entry;
    s32 delay;
    s32 count;
    u8 *last;
    u8 *other;
    u8 *unit;
    u8 *target;
    u8 *move;
    u8 *packet;

    *(u32 *)(iGpffffb3ac + 0xC) |= 0x80000;
    count = 0;
    for (entry = *(u8 **)(iGpffffb3ac + 0x174); entry != NULL; entry = *(u8 **)(entry + 0x450)) {
        if ((*(u16 *)(entry + 0x1A) & 1) == 0) {
            continue;
        }
        unit = *(u8 **)(entry + 0x30);
        if ((*(u32 *)(unit + 0x9C) & 8) == 0) {
            continue;
        }
        if (datCalcIsDead(*(u8 **)(unit + 0xA64), 0) == 0) {
            packet = btlUnitCreateMotionRequestPacket(unit, 0);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
        }
        if (datCalcChkBadStatus(*(s32 *)(unit + 0xA64), 0x100) != 0) {
            last = entry;
            count++;
        }
    }
    if (last == NULL) {
        return;
    }
    packet = (u8 *)btlFormationCreateSlotPacket(2, 0xFFF);
    *(s16 *)(packet + 0x48) = 8;
    *(s64 *)(packet + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(packet, 0);
    packet = btlPacketCreateEffectCounter(*(s32 *)(last + 0x30), count == 1 ? 0xAC : 0xAD);
    *(s64 *)(packet + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(packet, 3);
    btlTargetClearResultBuffer(params.bytes);
    params.words[3] = 0x100;
    btlUnitGetGroupBounds(2, 1, &center, NULL, NULL, 1);
    if (count != 1) {
        packet = btlCameraCreateSetStatePacket(arg0, 0x2C);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 0);
    }
    delay = 12;
    for (other = *(u8 **)(iGpffffb3ac + 0x174); other != NULL; other = *(u8 **)(other + 0x450)) {
        if ((*(u16 *)(other + 0x1A) & 1) == 0) {
            continue;
        }
        target = *(u8 **)(other + 0x30);
        if ((*(u32 *)(target + 0x9C) & 8) == 0) {
            continue;
        }
        if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100) == 0) {
            continue;
        }
        *(u16 *)(other + 0x1A) |= 8;
        **(u16 **)(*(u8 **)(other + 0x30) + 0xA64) &= 0xFFDF;
        **(u16 **)(*(u8 **)(other + 0x30) + 0xA64) &= 0xFFF7;
        **(u16 **)(*(u8 **)(other + 0x30) + 0xA64) &= 0xFFEF;
        btlTargetPositionToCell((s16 *)(target + 0x94), (s16 *)(target + 0x96), (f32 *)(D_00635530 + btlUnitRosterIndex(target) * 12));
        if (count == 1) {
            packet = btlCameraCreateSetStatePacket(other, 10);
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
        }
        packet = (u8 *)btlFormationCreatePacket(*(u32 *)(iGpffffb3ac + 0xD74), (u32)target, (u32)target, 1, 0);
        *(s16 *)(packet + 0x48) = delay;
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 2);
        packet = (u8 *)btlTargetCreateDataPacket((s32)other, (s32)other, params.bytes, 1, 1);
        *(s16 *)(packet + 0x48) = delay;
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 1);
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(*(BtlUnit **)(other + 0x30), 0);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 1);
        if (count == 1) {
            moveDelay = delay + 0x22;
            packet = btlCameraCreateSetStatePacket(other, 0x2C);
            *(s16 *)(packet + 0x48) = moveDelay;
            *(s64 *)(packet + 0x60) = *(s64 *)arg0;
            btlPacketEnqueue(packet, 0);
        } else {
            moveDelay = delay + 0x1A;
        }
        move = (u8 *)btlUnitCreateMovePacket((BtlUnit *)target, NULL, fGpffff809c, 0x18);
        *(s16 *)(move + 0x48) = moveDelay;
        *(s64 *)(move + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(move, 1);
        packet = (u8 *)btlUnitCreateRotatePacket(*(BtlUnit **)(other + 0x30), &center, 0);
        *packet = 4;
        *(s64 *)(packet + 8) = *(s64 *)(move + 0x58);
        *(s64 *)(packet + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(packet, 1);
        delay += 4;
    }
}

// Intent: Wait for the presentation to finish, then clear the release flags. [inferred]
// FUN_0022ABD0
s32 btlEncounterReleaseFlags(s64 *arg0) {
    u8 *temp_4;

    if (btlUnitRecordFindByActionUID(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        datSetFlag(0x15FF, 0);
        datSetFlag(0x15CF, 0);
        datSetFlag(0x15D0, 0);
        datSetFlag(0x15D1, 0);
        datSetFlag(0x15D2, 0);
        datSetFlag(0x15D3, 0);
        datSetFlag(0x15D4, 0);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// Intent: Start the camera state packet and effect counter for the encounter. [inferred]
// FUN_0022ACB0
void btlEncounterStartCameraState(u8 *arg0)
{
    u8 *temp_2;
    u8 *temp_2_2;

    *(s32 *)(DAT_0076449c + 0xC) |= 0x80000;
    temp_2 = btlCameraCreateSetStatePacket(arg0, 0x2C);
    *(s64 *)(temp_2 + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(temp_2, 0);
    temp_2_2 = btlPacketCreateEffectCounter(*(s32 *)(arg0 + 0x30), 0xAF);
    *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
    btlPacketEnqueue(temp_2_2, 3);
}

// Intent: Wait for the release events to finish. [inferred]
// FUN_0022AD40
s32 btlEncounterWaitReleaseEvents(s64 *arg0) {
    u8 *temp_4;

    if (btlUnitRecordFindByActionUID(*arg0,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        datSetFlag(0x1435, 0);
        datSetFlag(0x15C5, 0);
        datSetFlag(0x15C6, 0);
        datSetFlag(0x15C7, 0);
        datSetFlag(0x15C8, 0);
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) &= 0xFFF7FFFF;
        return 0;
    }
    return 1;
}

// Intent: Reset the encounter slot indices. [inferred]
// FUN_0022AE00
void btlEncounterResetSlots(u8 *arg0)
{
    struct {
        u8 data[0x10];
        u8 pad[0x10];
    } sp;
    s32 sp38;
    s32 temp_16;

    datSetFlag(0x15C0, 0);
    *(s8 *)(DAT_0076449c + 0xC10) = -1;
    *(s8 *)(DAT_0076449c + 0xC13) = -1;
    *(s8 *)(DAT_0076449c + 0xC28) = -1;
    *(s8 *)(DAT_0076449c + 0xC22) = -1;
    *(s8 *)(DAT_0076449c + 0xC1A) = -1;
    *(s8 *)(DAT_0076449c + 0xC12) = -1;
    *(s8 *)(DAT_0076449c + 0xC18) = -1;
    {
        u8 *temp_3;
        temp_3 = *(u8 **)(arg0 + 0x30);
        *(u16 *)(temp_3 + 0x9D8) =
            (u16)(*(u16 *)(temp_3 + 0x9D8) & 0xFFDF);
    }
    {
        u8 *temp_4;
        temp_4 = DAT_0076449c;
        *(s32 *)(temp_4 + 0xC) |= 0x400000;
    }
    {
        u8 *temp_3_2;
        temp_3_2 = DAT_0076449c;
        *(u16 *)(temp_3_2 + 0x18) =
            (u16)(*(u16 *)(temp_3_2 + 0x18) | 0x23);
    }
    btlActionFinishPresentation((s64 *)arg0);
    temp_16 = btlFormationAllocWork(0);
    btlFormationCopyRecord((int)temp_16, (u32)btlFormationGetRecord(0xC));
    {
        u8 *temp_2;
        temp_2 = (u8 *)btlActionGetActiveOrQueueFront();
        if (temp_2 != NULL) {
            *(u16 *)(temp_2 + 0x18) =
                (u16)(*(u16 *)(temp_2 + 0x18) | 8);
        }
    }
    {
        u8 *temp_4_2;
        temp_4_2 = DAT_0076449c;
        *(s32 *)(temp_4_2 + 0xC) |= 0x80000;
    }
    {
        u8 *temp_2_2;
        temp_2_2 = btlUnitCreateAnimPacket(*(u8 **)(arg0 + 0x30),
                                 0xC, 0, 0, 1.0f);
        *(s64 *)(temp_2_2 + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(temp_2_2, 0);
    }
    {
        u8 *temp_2_3;
        temp_2_3 = (u8 *)btlUnitCreateMotionSettlePacket((BtlUnit *)(*(u8 **)(arg0 + 0x30)));
        *(s16 *)(temp_2_3 + 0x48) = 1;
        *(s64 *)(temp_2_3 + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(temp_2_3, 0);
    }
    btlTargetClearResultBuffer((u8 *)sp.data);
    *(s32 *)(sp.data + 8) = 0x100000;
    {
        u8 *temp_2_4;
        temp_2_4 = (u8 *)btlTargetCreateDataPacket((s32)(u32)arg0, (s32)(u32)arg0,
                                      (void *)sp.data, 1, 1);
        *(s64 *)(temp_2_4 + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(temp_2_4, 1);
    }
    {
        u8 *temp_5;
        u8 *temp_2_5;
        temp_5 = *(u8 **)(arg0 + 0x30);
        temp_2_5 = (u8 *)btlFormationCreatePacket((u32)temp_16, (u32)temp_5, (u32)temp_5, 0, 0x200);
        *(s64 *)(temp_2_5 + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(temp_2_5, 2);
    }
    {
        u8 *temp_5_2;
        u8 *temp_2_6;
        temp_5_2 = *(u8 **)(arg0 + 0x30);
        temp_2_6 = (u8 *)btlFormationCreatePacket((u32)temp_16, (u32)temp_5_2, (u32)temp_5_2, 1, 0x200);
        *(s64 *)(temp_2_6 + 0x60) = *(s64 *)arg0;
        btlPacketEnqueue(temp_2_6, 2);
    }
    btlFormationSetPlacement(temp_16);
}


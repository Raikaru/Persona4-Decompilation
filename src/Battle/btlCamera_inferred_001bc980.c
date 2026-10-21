#include "list_item_internal.h"
#include "rw_geometry_internal.h"
#include "btl_equipment_count_internal.h"
#include "model_callbacks_internal.h"
#include "btl_camera_palette_internal.h"
#include "effect_geometry_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"
#include "include_asm.h"
#include "type.h"
#include "btl_camera_sequence_internal.h"
#include "rw_frame_internal.h"

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void btlUnitSetFlags(u8 *unit, s32 flags);
extern void btlUnitClearFlags(u8 *unit, s32 flags);
extern void (*jtbl_008873EC[])(void *);
extern f32 D_00922CA0[];
extern f32 D_00922CA4[];
extern f32 D_00922CA8[];
extern f32 D_00922CAC[];
extern f32 D_00922CB0[];
extern f32 D_00922CB4[];
extern f32 D_00922CB8[];
extern f32 D_00922CBC[];
extern s32 D_00922CC0[];

extern u8 *D_0076449C;
extern u8 *btlPacketAlloc(s32 packetType, s32 workSize);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *value);
extern u32 iGpffffa0b8;
extern void btlUnitGetSphereWorldCenter(u8 *unit, f32 *dst);
extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern u8 D_005FB400[];
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern void btlCameraSetState(s32 state, BtlAction *action, u32 clearUnitFlags);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
extern void btlCameraCopyPose(f32 *destination, f32 *source);
extern void mdlBlendTranslationRotation(f32 *result, f32 *from, f32 *to, f32 blend);
extern u32 btlMainCurveAppendKeyframe(u16 *curve, f32 *position, f32 *rotation);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 fGpffff8430;
extern s32 kwlnGetCamera(void);
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
extern void btlCameraUpdateUnitInRangeFlags(void);
extern u8 D_005F72B0[];
extern f32 fGpffff8314;
extern f32 fGpffff8318;
extern f32 fGpffff831c;
extern f32 fGpffff8320;
extern f32 fGpffff8324;
extern f32 fGpffff8328;
extern f32 fGpffff832c;
extern f32 fGpffff8184;
extern f32 fGpffff8104;
extern f32 fGpffff8054;
extern f32 fGpffff8058;
extern f32 fGpffff805c;
extern f32 fGpffff8060;
extern f32 fGpffff8108;


void mdlEffectSetSequenceRequest(s32 sequence, s16 sequenceId, s32 firstValue, s32 secondValue);


#pragma push
#pragma pop

extern s32 btlActionGetQueueSecond(void);
extern void mdlBlendTranslationRotation(f32 *result, f32 *from, f32 *to, f32 blend);
/* Reads an action target for camera visibility geometry from the twelve-entry action target list. */
static inline u8 *btlCameraGetVisibilityTarget(u8 *action, u16 index)
{
    return ((BtlAction *)action)->targets[index];
}
struct RwV3d;
/* measured: retail keeps the branch-fed scalar in func_001b19c0 unrebuilt, and its work pointers
 * have disjoint lifetimes, so opt_lifetimes is on. */
#pragma push
#pragma pop
/* Keeps full-width dependency snapshots and a branch-materialized final mode. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Build four curve keyframes between supplied poses, or begin from the current pose. */
// FUN_001BC980
s32 btlCameraPlayPoseSequence(u8 *work)
{
    struct C980Frame {
        f32 interpolatedPose[4];
        u8 gap40[0x10];
        f32 firstPosition[3];
        f32 firstRotation[4];
        f32 secondPosition[3];
        f32 secondRotation[4];
        u8 tail[8];
    } frame;
    s32 curveAddress;
    u8 *battle;
    u8 *battleAfterAppend;

    btlCameraSetState(1, (BtlAction *)((BtlCameraPoseSequence *)work)->action, 1);
    if (((BtlCameraPoseSequence *)work)->useCurrentPose != 0) {
        btlCameraCopyPose(frame.firstPosition, (f32 *)(D_0076449C + 0xC0));
    } else {
        btlCameraLookAtQuat(frame.firstRotation, work + 4, work + 0x10, D_0060A0E0);
        *(BtlCameraPosition *)frame.firstPosition =
            ((BtlCameraPoseSequence *)work)->firstPosition;
    }
    btlCameraLookAtQuat(frame.secondRotation, work + 0x1C, work + 0x28, D_0060A0E0);
    *(BtlCameraPosition *)frame.secondPosition =
        ((BtlCameraPoseSequence *)work)->secondPosition;
    battle = D_0076449C;
    curveAddress = (s32)(battle + 0x24);
    ((BtlBattleState *)battle)->camera.curveFlags = 1;
    ((BtlBattleState *)battle)->camera.curveIndex = 0;
    ((BtlBattleState *)battle)->camera.curveNext = 0;
    ((BtlBattleState *)battle)->camera.curveCount = 0;
    ((BtlBattleState *)battle)->camera.unk80 = 0;
    ((BtlBattleState *)battle)->camera.unk7C = 0;
    btlMainCurveAppendKeyframe((u16 *)curveAddress, frame.firstPosition, frame.firstRotation);
    mdlBlendTranslationRotation(frame.interpolatedPose, frame.firstPosition, frame.secondPosition, fGpffff82f8);
    btlMainCurveAppendKeyframe((u16 *)curveAddress, frame.interpolatedPose, frame.interpolatedPose + 3);
    mdlBlendTranslationRotation(frame.interpolatedPose, frame.firstPosition, frame.secondPosition, fGpffff80c8);
    btlMainCurveAppendKeyframe((u16 *)curveAddress, frame.interpolatedPose, frame.interpolatedPose + 3);
    btlMainCurveAppendKeyframe((u16 *)curveAddress, frame.secondPosition, frame.secondRotation);
    battleAfterAppend = D_0076449C;
    ((BtlBattleState *)battleAfterAppend)->camera.curveDuration =
        (60.0f * (2.0f * ((BtlCameraPoseSequence *)work)->duration)) / 2.0f;
    /* Retail stores the IEEE-754 bits for 0.5 directly into curveStep. */
    *(s32 *)&((BtlBattleState *)battleAfterAppend)->camera.curveStep = 0x3F000000;
    ((BtlBattleState *)battleAfterAppend)->camera.curveFlags &= 0xFFF5;
    ((BtlBattleState *)battleAfterAppend)->camera.curveFlags |= 4;
    return 1;
}

/* Allocate the 0x44-byte two-pose packet; missing first inputs select the current pose. */
// FUN_001BCB50
u8 *btlCameraCreatePoseSequencePacket(s32 action, u8 *firstPosition, u8 *firstFocus, f32 firstValue,
                  u8 *secondPosition, u8 *secondFocus, f32 secondValue, f32 duration)
{
    u8 *packet;
    u8 *work;

    packet = (u8 *)(btlPacketAlloc(0x201, 0x44));
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlCameraPlayPoseSequence;
    work = (u8 *)((BtlPacket *)packet)->workData;
    ((BtlCameraPoseSequence *)work)->action = action;
    ((BtlCameraPoseSequence *)work)->duration = duration;
    if ((firstPosition != NULL) && (firstFocus != NULL)) {
        ((BtlCameraPoseSequence *)work)->firstPosition =
            *(BtlCameraPosition *)firstPosition;
        ((BtlCameraPoseSequence *)work)->firstFocus =
            *(BtlCameraPosition *)firstFocus;
        ((BtlCameraPoseSequence *)work)->useCurrentPose = 0;
    } else {
        ((BtlCameraPoseSequence *)work)->useCurrentPose = 1;
    }
    ((BtlCameraPoseSequence *)work)->secondPosition =
        *(BtlCameraPosition *)secondPosition;
    ((BtlCameraPoseSequence *)work)->secondFocus =
        *(BtlCameraPosition *)secondFocus;
    ((BtlCameraPoseSequence *)work)->firstValue = firstValue;
    ((BtlCameraPoseSequence *)work)->secondValue = secondValue;
    return packet;
}

/* Forward the four initialized command-work values to the external camera command handler. */
// FUN_001BCC80
s32 btlCameraRunPacketCommand(u8 *work) {
    mdlEffectSetSequenceRequest(((BtlCameraCommand *)work)->value, ((BtlCameraCommand *)work)->option, ((BtlCameraCommand *)work)->first,
                  ((BtlCameraCommand *)work)->second);
    return 1;
}

/* Allocate a 0x10-byte camera-command work record and install its update callback. */
// FUN_001BCCC0
u8 *btlCameraCreatePacketCommand(s32 value, s16 option, s32 first, s32 second) {
    u8 *packet;
    u8 *work;

    packet = (u8 *)(btlPacketAlloc(0x202, 0x10));
    ((BtlPacket *)packet)->updateFunc = (BtlPacketFunc)btlCameraRunPacketCommand;
    work = (u8 *)((u8 *)((BtlPacket *)packet)->workData);
    ((BtlCameraCommand *)work)->value = value;
    ((BtlCameraCommand *)work)->option = option;
    ((BtlCameraCommand *)work)->first = first;
    ((BtlCameraCommand *)work)->second = second;
    return packet;
}

#pragma push
/* measured: loop-invariant hoisting is needed for retail's target cursor and alpha mode loads. */
#pragma opt_loop_invariants on
/* Set visibility and fade flags from action membership and the horizontal camera corridor; mode bits select exclusions. */
// FUN_001BCD40
void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode)
{
    extern void btlUnitSetFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitClearFlags(BtlUnit *unit, u16 flags);
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, struct RwV3d *dst);
    extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *projection);
    struct {
        f32 first[2];
        f32 second[2];
        f32 point[2];
        f32 closest[2];
        f32 center[3];
    } geometry;
    u8 *current;
    u8 *unit;
    u16 targetGroups;
    f32 distance;
    BtlAction *actionData = (BtlAction *)action;
    BtlAction *currentData;
    BtlUnit *unitData;

    if ((((BtlBattleState *)D_0076449C)->battleFlags & 4) != 0)
        return;

    if (first != NULL && second != NULL) {
        geometry.first[0] = ((f32 *)first)[0];
        geometry.first[1] = ((f32 *)first)[2];
        geometry.second[0] = second[0];
        geometry.second[1] = second[2];
    } else {
        radius = 0.0f;
    }

    targetGroups = 0;
    if ((mode & 0x10) != 0) {
        s32 index;
        index = 0;
        while ((index & 0xFFFF) < actionData->unk_6a) {
            targetGroups |= (u16)(1u << ((BtlAction *)btlCameraGetVisibilityTarget(action, index))->unit->genus);
            index = (index + 1) & 0xFFFF;
        }
    }

    for (current = ((BtlBattleState *)D_0076449C)->actions; current != NULL;
         current = (u8 *)currentData->next) {
        currentData = (BtlAction *)current;
        if ((currentData->unk_1a & 1) == 0)
            continue;
        unit = (u8 *)currentData->unit;
        unitData = (BtlUnit *)unit;
        if ((unitData->flags3 & 8) == 0)
            continue;

        if ((mode & 0x20) != 0 && current != action) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
            continue;
        }
        if ((mode & 0x100) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            if ((mode & 0x400) != 0) btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
            continue;
        }
        if (current == ((BtlBattleState *)D_0076449C)->selectedAction && (mode & 4) != 0) {
            btlUnitClearFlags((BtlUnit *)unit, 2);
            btlUnitSetFlags((BtlUnit *)unit, 4);
            if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
            continue;
        }
        if (action != NULL) {
            if (current == action && (mode & 1) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
                continue;
            }
            if ((targetGroups & (1u << unitData->genus)) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
                continue;
            }
            if ((mode & 0x800) != 0 && current == (u8 *)(uintptr_t)btlActionGetQueueSecond()) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                btlUnitSetFlags((BtlUnit *)unit, 4);
                if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
                continue;
            }
            if ((mode & 2) != 0) {
                s32 index;
                index = 0;
                while ((index & 0xFFFF) < actionData->unk_6a) {
                    if (current == btlCameraGetVisibilityTarget(action, index)) {
                        btlUnitClearFlags((BtlUnit *)unit, 2);
                        btlUnitSetFlags((BtlUnit *)unit, 4);
                        if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
                        break;
                    }
                    index = (index + 1) & 0xFFFF;
                }
                if ((index & 0xFFFF) != actionData->unk_6a ||
                    current == actionData->parameters.followUp)
                    continue;
            }
            if (unitData->genus == actionData->unit->genus &&
                (mode & 8) != 0) {
                btlUnitClearFlags((BtlUnit *)unit, 2);
                if ((mode & 0x40) == 0) unitData->cols[1].alpha = 0xFF;
                continue;
            }
        }

        if (first != NULL && second != NULL) {
            btlUnitGetSphereWorldCenter((BtlUnit *)unit, (struct RwV3d *)geometry.center);
            geometry.point[0] = geometry.center[0];
            geometry.point[1] = geometry.center[2];
            distance = btlTargetAngleBetween((u8 *)geometry.first, (u8 *)geometry.second,
                                     (u8 *)geometry.point, (u8 *)geometry.closest);
            distance = 0.0f + distance - unitData->sphereRadius * unitData->scale;
            if (((geometry.first[0] < geometry.closest[0] ||
                  !(geometry.second[0] <= geometry.closest[0])) &&
                 (!(geometry.first[0] <= geometry.closest[0]) ||
                  geometry.second[0] < geometry.closest[0])) ||
                ((geometry.first[1] < geometry.closest[1] ||
                  !(geometry.second[1] <= geometry.closest[1])) &&
                 (!(geometry.first[1] <= geometry.closest[1]) ||
                  geometry.second[1] < geometry.closest[1])))
                continue;
        } else {
            distance = 0.0f;
        }
        if (distance <= radius) {
            btlUnitSetFlags((BtlUnit *)unit, 2);
            if ((mode & 0x80) == 0) unitData->cols[1].alpha = 0;
            if ((mode & 0x200) != 0) btlUnitClearFlags((BtlUnit *)unit, 4);
        }
    }
}
#pragma pop

/* measured: retail recomputes the outer index after the preheader branch and reuses the masked loop
 * counter a second time instead of folding it. */
#pragma opt_common_subs off
/* Clear the low camera visibility flags on both battle-side unit lists. */
// FUN_001BD300
void btlCameraClearAllUnitFlags(void)
{
    s32 sideIndex;
    s32 index;
    u8 *unit;

    sideIndex = 0;
    goto outer_check;
outer_body:
    index = sideIndex & 0xFFFF;
    unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[index * 2];
    goto inner_check;
inner_body:
    btlUnitClearFlags(unit, 0xF);
    unit = (u8 *)((BtlUnit *)unit)->nextUnit;
inner_check:
    if (unit != NULL) goto inner_body;
    sideIndex = (sideIndex + 1) & 0xFFFF;
outer_check:
    if ((sideIndex & 0xFFFF) < 2) goto outer_body;
}

/* Mark eligible units within their scaled radius plus 200 units of the camera modelling position. */
// FUN_001BD390
void btlCameraUpdateUnitInRangeFlags(void)
{
    extern void btlUnitSetFlags();
    extern s32 datCalcEnemyHasExtendedFlag(u8 *unit);
    extern f32 RwV3dLength(f32 *value);
    u8 *current;
    s32 counter;
    u8 *base;
    s32 index;
    s32 ability;
    f32 values[3];
    f32 delta[3];

    base = (u8 *)&((RwFrame *)((RwCamera *)kwlnGetCamera())->object.object.parent)->modelling;
    counter = 0;
    goto outer_check;
outer_body:
    index = counter & 0xFFFF;
    current = ((BtlBattleState *)iGpffffb3ac)->unitLists[index * 2];
    goto inner_check;
inner_body:
    ability = (s32)((BtlUnit *)current)->datUnit;
    if ((ability != 0 && datCalcEnemyHasExtendedFlag((u8 *)ability) != 0) ||
        (((BtlUnit *)current)->flags3 & 8) != 0) {
        btlUnitGetSphereWorldCenter(current, values);
        delta[0] = ((RwMatrixTag *)base)->pos.x - values[0];
        delta[1] = ((RwMatrixTag *)base)->pos.y - values[1];
        delta[2] = ((RwMatrixTag *)base)->pos.z - values[2];
        if (RwV3dLength(delta) <=
            0.0f + 200.0f +
            ((BtlUnit *)current)->sphereRadius * ((BtlUnit *)current)->scale) {
            btlUnitSetFlags(current, 1);
        } else {
            btlUnitClearFlags(current, 1);
        }
    }
    current = (u8 *)((BtlUnit *)current)->nextUnit;
inner_check:
    if (current != NULL) goto inner_body;
    counter = (counter + 1) & 0xFFFF;
outer_check:
    if ((counter & 0xFFFF) < 2) goto outer_body;
}

/* measured: common-subexpression optimization goes back on here because btlCameraMarkUnitFramed
 * only matches retail with it enabled. */
#pragma opt_common_subs on
// FUN_001BD4F0
/* Mark the unit framed/visible and clear the alternate visibility flag. */
void btlCameraMarkUnitFramed(u8 *unit) {
    btlUnitSetFlags(unit, 0xA);
    btlUnitClearFlags(unit, 4);
}

// FUN_001BD530
/* Clear the framed/visible camera flags on the supplied unit address. */
void btlCameraClearUnitFramed(u32 unitAddress) {
    btlUnitClearFlags((u8 *)unitAddress, 0xA);
}


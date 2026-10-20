#include "operand_order_internal.h"
#include "member_access.h"
#include "btl_unit_record_internal.h"
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

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_effect_internal.h"
#include "btl_unit_internal.h"
#include "btl_action_internal.h"
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
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
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *arg0);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern u32 iGpffffa0b8;
extern u8 D_005FB400[];

extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
extern f32 btlTargetSmoothStep(f32 value, f32 *state);
extern u32 btlCameraSampleKeyframes(u8 *curveWork, f32 *position, f32 *rotation);
extern u32 btlCameraAdvanceKeyframes(u8 *curveWork, f32 deltaTime);
extern f32 fGpffff8430;
extern f32 fGpffff8048;
extern u8 D_005F74C0[];
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

s32 btlTargetIsSlotAlive(u8 *context);





#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001bbf40-001bc330 */

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Set the linear camera transition duration and clear the spring/easing mode bits. */
// FUN_001BBF40
void btlCameraSetTransitionDuration(u8 *camera, f32 seconds) {
    ((BtlCamera *)camera)->curveDuration = (f32) ((60.0f * seconds) / 2.0f);
    ((BtlCamera *)camera)->curveFlags = (u16) (((BtlCamera *)camera)->curveFlags & 0xFFFD);
    ((BtlCamera *)camera)->curveFlags = (u16) (((BtlCamera *)camera)->curveFlags & 0xFFFB);
    ((BtlCamera *)camera)->curveFlags = (u16) (((BtlCamera *)camera)->curveFlags & 0xFFF7);
}

/* Compute the selected linear, spring, or eased time step and publish the sampled camera pose.
 * Measured: the MEMBER step store avoids an extra +0x94 temporary in all three typed forms. */
// FUN_001BBF90
void btlCameraUpdateTransition(u8 *camera)
{
    f32 progress;
    f32 nextProgress;
    f32 timeStep;
    u16 flags;
    u8 *battle;

    flags = ((BtlCamera *)camera)->curveFlags;
    if ((flags & 2) != 0) {
        timeStep =
            btlTargetSmoothStep(1.0f, (f32 *)(camera + 0x84)) -
            ((BtlCamera *)camera)->transitionTime;
    } else if ((flags & 4) != 0) {
        progress = ((BtlCamera *)camera)->curveStep;
        if (progress < fGpffff8430) {
            nextProgress = progress + (1.0f / ((BtlCamera *)camera)->curveDuration);
            MEMBER(f32, camera, BtlCamera, curveStep) = nextProgress;
            progress = 0.0f + (-1.0f) +
                      ((-2.0f * nextProgress) * nextProgress) +
                      (4.0f * nextProgress);
            timeStep =
                (2.0f * (progress - 0.5f)) -
                ((BtlCamera *)camera)->transitionTime;
        } else {
            timeStep = 0.0f;
        }
    } else if ((flags & 8) != 0) {
        if (((BtlCamera *)camera)->springElapsed >
            (0.5f * ((BtlCamera *)camera)->curveDuration)) {
            timeStep =
                operandOrderMultiply(btlTargetSmoothStep(1.0f, (f32 *)(camera + 0x84)), 2.0f) -
                ((BtlCamera *)camera)->transitionTime;
        } else {
            timeStep = 0.0f;
        }
    } else {
        timeStep = 1.0f / ((BtlCamera *)camera)->curveDuration;
    }
    ((BtlCamera *)camera)->transitionTime =
        ((BtlCamera *)camera)->transitionTime + timeStep;
    btlCameraAdvanceKeyframes(camera, timeStep);
    battle = D_0076449C;
    btlCameraSampleKeyframes(battle + 0x24, (f32 *)(battle + 0xC0),
                  (f32 *)(battle + 0xCC));
}

/* Reject a camera action for acting-unit status mask 0x60 or a special hit on any target. */
// FUN_001BC140
s32 btlCameraIsActionBlocked(u8 *camera) {
    u8 *action;

    action = (u8 *)((u8 *)((BtlCamera *)camera)->action);
    if (action == NULL) {
        return 0;
    }
    if (datCalcChkBadStatus((s32)((BtlAction *)action)->unit->datUnit, 0x60) != 0) {
        return 1;
    }
    return (s32)(btlActionAnyTargetSpecialHit(action) != 0);
}

/* Reject camera targeting for flagged 0x58-byte child-unit records or skills with exclusion bit 0x10. */
// FUN_001BC1B0
s32 btlCameraIsTargetEligible(u8 *camera)
{
    u8 *childUnit;
    u8 *action;
    BtlSkillFlags *base;
    s32 index;

    action = (u8 *)((BtlCamera *)camera)->action;
    childUnit = (u8 *)((BtlAction *)action)->unit->childUnit;
    index = ((BtlAction *)action)->unk_6e;
    if ((childUnit != NULL) &&
        (((BtlUnitChildRecord *)iGpffffb3e0)[((BtlUnit *)childUnit)->charId].unk00 & 1)) {
        return 0;
    }
    base = iGpffffb3bc;
    if ((base[index & 0xFFFF].flags & 0x10) != 0) {
        return 0;
    }
    return 1;
}

/* measured: opt_propagation off probe for bc240 table-address order. */
// FUN_001BC240
/* Honor the battle override, otherwise require an eligible skill with priority bit 0x20. */
s32 btlCameraIsTargetPrioritized(s32 cameraOrSkill)
{
    s32 result;
    u8 *temp;
    u8 *base;

    if ((((BtlBattleState *)(u8 *)iGpffffb3ac)->flags & 0x200000) != 0) {
        result = 1;
        goto done;
    }
    temp = (u8 *)((BtlCamera *)cameraOrSkill)->action;
    cameraOrSkill = ((BtlAction *)temp)->unk_6e;
    temp = (u8 *)((BtlAction *)temp)->unit->childUnit;
    if ((temp != NULL) &&
        ((((BtlUnitChildRecord *)iGpffffb3e0)[((BtlUnit *)temp)->charId].unk00) & 1) != 0) {
        result = 0;
        goto check20;
    }
    base = (u8 *)iGpffffb3bc;
    if ((((BtlSkillFlags *)(u8 *)(((cameraOrSkill & 0xFFFF) << 2) + (u32)base))->flags &
         0x10) != 0) {
        result = 0;
        goto check20;
    }
    result = 1;
check20:
    if (result == 0) {
        goto final_zero;
    }
    base = (u8 *)iGpffffb3bc;
    if ((((BtlSkillFlags *)(u8 *)(((cameraOrSkill & 0xFFFF) << 2) + (u32)base))->flags &
         0x20) != 0) {
        result = 1;
        goto done;
    }
final_zero:
    result = 0;
done:
    return result;
}

/* measured: close opt_propagation probe for bc240. */
/* Test the current action slot and action mode three. Measured: the MEMBER action reload differs
 * in access-site, local-pointer and array forms across the slot predicate. */
// FUN_001BC330
s32 btlCameraIsOrbitAction(u8 *camera) {
    u8 *action = (u8 *)((BtlCamera *)camera)->action;
    if (action == NULL) {
        return 0;
    }
    if (btlTargetIsSlotAlive(action) == 0) {
        return 1;
    }
    return ((BtlAction *)MEMBER(u8 *, camera, BtlCamera, action))->unk_6c == 3;
}


/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00223ed0-00225d00 */

#include "rw_types_internal.h"
#include "member_access.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
#include "btl_effect_internal.h"
#include "btl_unit_internal.h"
#include "btl_action_internal.h"
#include "btl_camera_internal.h"
#include "btl_result_ui_internal.h"

/* Camera control subobject at battle+0xC00; pair framing writes aimMode,
 * and the skill preset selector controls whether TickFrame updates the view. */
typedef struct BtlCameraControl {
    u16 aimMode;
    u8 pad02[0xA];
    s32 updateFrame;
} BtlCameraControl;
typedef struct BtlTarget BtlTarget;

/* Same target-array layout consumed by btlTargetGetUnitIndex in btlTarget.c. */
struct BtlTarget {
    BtlAction *targetedActions[12];
    u8 pad30[2];
    u16 targetedCount;
};

typedef struct BtlUnit BtlUnit;

typedef struct KwlnTask KwlnTask;

extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
u8 *kwlnTaskGetTaskByName(s8 *name);
u32 kwlnTaskGetWork(void *task);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag();
extern void memset();
extern u8 D_00629738[];
extern s32 btlResultFriendPsUpdate(u8 *sdkTaskBytes);
extern void btlResultSummaryOnEventAlt();
extern void btlResultSummaryDestroy(u8 *sdkTaskBytes);
extern s32 btlUnitMotionClassValue(u8 *, s32);
extern s32 btlUnitIsUnavailable(u8 *, s32, s32);
extern void btlCameraWaitMotionFrames(u8 *);
extern void btlCameraSelectPreset(int);
extern s32 datCalcEnemyHasTableFlag(u8 *);
extern void btlCameraFrameTarget(u8 *, f32, f32);
extern void btlCameraFrameWrapTargetWalk(u8 *, f32, f32);
extern u16 btlTargetGetUnitIndex(BtlTarget *target);
extern s32 btlActionAnyTargetHitRowFlagged(u8 *);
extern void btlCameraApplyPosePair(u8 *);
extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *projection);
extern void btlTargetBlendVectors(void *rotation, void *first, void *second);
extern void btlCameraCopyPoseTarget(f32 *destination, f32 *source);
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;
extern f32 tanf(f32 angle);
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
extern void btlCameraSetLimitFrame(u8 *camera, f32 suppliedLimit, s32 reverse, s32 preserveSide);
extern void btlCameraFrameActorTarget(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration);
extern u8 D_00629700[];
void btlCameraUpdateFrame(void);
extern u8 *DAT_0076449c; /* active battle state */
extern void btlCameraFrameAim(u8 *);
extern void btlUnitFaceTarget(BtlUnit *unit, const RwV3d *target);
extern void btlCameraSelectEncounterPreset(u8 *camera);
extern void (*jtbl_008873EC[])(void *);
extern void shdPersonaFinishPhase(u8 *);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
extern void btlMainCurveReset(u16 *, f32 *);
extern void btlCameraCopyPose(f32 *, f32 *);
extern void btlMainCurveSetPoses(u16 *, f32 *, f32 *, u16);
extern void btlCameraSetDuration(u8 *, f32);
extern u8 D_0060A0E0[];
extern s32 btlCurrentUnitId(void);
extern u32 datCalcChkBadStatus(s32, u32);
extern void btlCameraSetupActionGeometry(u8 *, u8 *, f32 *, f32, u16);
extern u8 *iGpffffb3ac;
extern s32 datCalcIsGuarding(u16 *unitFlags);
extern f32 btlTargetQuatAngle(void *right, void *left);
#pragma push
#pragma opt_propagation on
// Intent: Result summary event callback (same body as the overlay callback). [inferred]
// FUN_00223ED0
void btlResultSummaryOnEventAlt(s32 event, u16 *flags, s32 eventData)
{
    if ((*flags & 2) != 0) {
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Destroy the result summary task work. [inferred]
/* b210: typing the persona-window zero-store adds four bytes; its read remains typed. */
// FUN_00223EE0
void btlResultSummaryDestroy(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *work;
    s32 window;

    work = (u8 *)kwlnTaskGetWork(task);
    window = (s32)((BtlResultSummaryWork *)work)->personaWindow;
    if (window != 0) {
        shdPersonaFinishPhase((u8 *)window);
        MEMBER(s32, work, BtlResultSummaryWork, personaWindow) = 0;
    }
    (*jtbl_008873EC)(work);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Create the result summary task. [inferred]
// FUN_00223F40
s32 btlResultSummaryCreate(s32 parent)
{
    u8 *work;
    s32 task;
    u16 *parentWork;

    chkmemAllocSiteTag(&D_00629738, 0x3A);
    work = (u8 *)(*jtbl_008873E8)(0x4C, 0x40000);
    memset(work, 0, 0x4C);
    task = (s32)((s32)kwlnTaskCreateChild((void *)(parent), (const void *)(&D_00629700), 0xF, 0, 0, btlResultFriendPsUpdate, btlResultSummaryDestroy, (u8 *)(work)));
    parentWork = (u16 *)(kwlnTaskGetWork((void *)parent));
    ((BtlResultSummaryWork *)work)->state = 0;
    ((BtlResultSummaryWork *)work)->parentWork = (u8 *)parentWork;
    memset(work + 8, 0, 0x30);
    ((PrimQueueNode *)(work + 8))->callback = (void *)btlResultSummaryOnEventAlt;
    ((PrimQueueNode *)(work + 8))->argument.data = (u8 *)(work);
    ((BtlResultSummaryWork *)work)->flags = (u16)(((BtlResultSummaryWork *)work)->flags | 1);
    return task;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Start the result summary task. [inferred]
// FUN_00224040
void btlResultSummaryStart(KwlnTask *task)
{
    u16 *work;

    work = (u16 *)kwlnTaskGetWork(task);
    btlShuffleStartOverlay();
    ((BtlResultSummaryWork *)work)->state = 5;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Report whether the result summary is ready. [inferred]
// FUN_00224080
s32 btlResultSummaryIsReady(KwlnTask *task)
{
    return *(u16 *)kwlnTaskGetWork(task) & 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Report whether the result summary task exists by name. [inferred]
// FUN_002240B0
s32 btlResultSummaryExists(void)
{
    return kwlnTaskGetTaskByName((s8 *)D_00629700) != 0;
}
#pragma pop

/* Select the encounter camera's eye/focus preset from the actor's party
 * ordinal and the roster's highest-priority status. Preserve both complete
 * position/quaternion poses across the immediate/interpolated transition.
 * The presence predicate returns a signed halfword before conversion to the
 * unsigned preset index; this retains both retail narrowing operations.
 * Scoped propagation and distinct selector lifetimes reproduce native b210
 * O2: 876/880 bytes, 34 fully resolved relocations, four zero tail bytes.
 */
extern s32 datCalcEnemyHasExtendedFlag(u8 *unit);
extern s32 datCalcIsGuarding(u16 *unitFlags);
extern void btlMainApplyUnitBaseColors(u8 *unit);
extern f32 fGpffff80e8;
extern u8 D_00634870[];
extern f32 D_00634874[];
extern f32 D_00634878[];
extern u8 D_0063487C[];
static inline s16 btlCameraPresetPresence(s32 present)
{
    return present != 0;
}

#pragma push
#pragma opt_propagation off
// Intent: Select the encounter camera preset from the party ordinal and roster status. [inferred]
/* b210: remaining reset-store and action/DatUnit reloads individually differ when typed. */
// FUN_002240E0
void btlCameraSelectEncounterPreset(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    f32 z;
    u8 *enemy;
    s32 reset;
    s32 hasStatus;
    s32 hasPriorityStatus;
    u8 *unit;
    u16 variant;
    u8 *ally;
    f32 x;
    f32 y;
    struct EyeFocus { RwV3d eye; RwV3d focus; } *record;
    u8 *partyMember;
    u16 previousState;
    u32 ordinal;
    u16 partyIndex;

    previousState = ((BtlBattleState *)iGpffffb3ac)->camera.stateHistory[0];
    switch (previousState) {
    case 2:
    case 0x22:
    case 0x28:
    case 0x29:
        reset = 0;
        break;
    default:
        reset = 1;
        break;
    }
    if (((BtlCamera *)camera)->forceTransition != 0) {
        reset = 1;
        MEMBER(s32, camera, BtlCamera, forceTransition) = 0;
    }
    unit = (u8 *)((BtlCamera *)camera)->action->unit;
    if (((BtlUnit *)unit)->genus != 0) {
        partyIndex = 0;
    } else {
        ordinal = 0;
        partyMember = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
        while (partyMember != NULL) {
            if (unit == partyMember) {
                break;
            }
            ordinal = (u16)(ordinal + 1);
            partyMember = (u8 *)((BtlUnit *)partyMember)->prevUnit;
        }
        partyIndex = (u16)ordinal;
    }
    hasStatus = 0;
    hasPriorityStatus = 0;
    enemy = ((BtlBattleState *)iGpffffb3ac)->unitLists[2];
    while (enemy != NULL) {
        if ((((BtlUnit *)enemy)->flags3 & 8) != 0 &&
            (u8 *)((BtlUnit *)enemy)->datUnit != NULL &&
            datCalcEnemyHasExtendedFlag((u8 *)((BtlUnit *)enemy)->datUnit) != 0) {
            if (datCalcChkBadStatus(MEMBER(s32, enemy, BtlUnit, datUnit), 0x100000) != 0) {
                hasStatus = 1;
            }
            if (datCalcIsGuarding(MEMBER(u16 *, enemy, BtlUnit, datUnit)) != 0) {
                hasPriorityStatus = 1;
            }
        }
        enemy = (u8 *)((BtlUnit *)enemy)->nextUnit;
    }
    variant = hasPriorityStatus != 0 ? 2 : (u16)btlCameraPresetPresence(hasStatus);
    if (btlCurrentUnitId() == 0x208 && (u16)variant == 0) {
        ally = ((BtlBattleState *)iGpffffb3ac)->unitLists[0];
        while (ally != NULL) {
            if ((((BtlUnit *)ally)->flags3 & 8) != 0 &&
                (u8 *)((BtlUnit *)ally)->datUnit != NULL &&
                datCalcChkBadStatus((s32)((BtlUnit *)ally)->datUnit, 0x100) != 0) {
                variant = 2;
                break;
            }
            ally = (u8 *)((BtlUnit *)ally)->nextUnit;
        }
    }
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (btlCurrentUnitId() != 0x215) {
        record = (struct EyeFocus *)(((BtlBattleState *)iGpffffb3ac)->boss.recordTable +
                 (u16)partyIndex * 0x48 + (u16)variant * 0x18);
        btlCameraLookAtQuat(&poses.secondRotation, &record->eye, &record->focus, D_0060A0E0);
        poses.second = record->eye;
    } else {
        btlCameraLookAtQuat(&poses.secondRotation, D_00634870, D_0063487C, D_0060A0E0);
        x = *(f32 *)D_00634870;
        y = D_00634874[0];
        z = D_00634878[0];
        poses.second.x = x;
        poses.second.y = y;
        poses.second.z = z;
    }
    if (reset != 0) {
        btlMainApplyUnitBaseColors(NULL);
        btlCameraSetupActionGeometry(MEMBER(u8 *, camera, BtlCamera, action), NULL, NULL, 0.0f, 0x100);
        btlMainCurveReset((u16 *)camera, (f32 *)&poses.second);
    } else {
        btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
        btlCameraSetDuration(camera, fGpffff80e8);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
/* Select a skill camera preset from the roster status and actor party index.
 * The word-sized priority predicate and the later halfword preset have
 * separate lifetimes, preserving the retail narrowing and register reuse.
 * measured: native b210 -O2, 1312/1312 bytes and 46 resolved relocations.
 *
 * Original retail omission: with target mask 2, global flag 0x400, skill
 * classification 0 and encounter other than 0x215, the branch at 0x22466C
 * falls through to the final pose consumer without writing the second pose.
 * Preserve that path and its unwritten automatic storage. The corresponding
 * target-mask-1 path returns immediately; neither path is given new state.
 */
// Intent: Select the skill camera preset from the roster and actor party index. [inferred]
/* b210: remaining action/DatUnit reloads individually change instructions when typed. */
// FUN_00224450
void btlCameraSelectSkillPreset(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    extern s32 datCalcEnemyHasExtendedFlag(u8 *unit);
    extern s32 datCalcIsGuarding(u16 *unitFlags);
    extern s32 btlCurrentUnitId(void);
    extern u32 btlEffectCollectGenusMask(s32 selection);
    extern void btlCameraReleaseOcclusion(u8 *camera);
    extern u8 D_00634890[];
    extern u8 D_0063489C[];
    u8 *battleWork;
    u16 previousState;
    u8 *enemy;
    s32 hasStatus;
    u32 hasPriorityStatus;
    u16 preset;
    s32 reset;
    u16 skill;
    s32 targetGroups;
    s32 classification;
    s32 unitData;
    s32 selectedPreset;
    u8 *ally;
    s32 targetMask;
    u8 *action;
    u8 *actor2;
    u8 *actor1;
    s32 partyIndex2;
    s32 ordinal2;
    u8 *partyMember2;
    s32 partyIndex1;
    u8 *partyMember1;
    s32 ordinal1;
    u8 *recordBase2;
    u8 *recordBase1;
    u8 *recordBase;
    u8 *record2;
    u8 *record1;
    u8 *record;

    ((BtlCameraControl *)(DAT_0076449c + 0xC00))->updateFrame = 0;
    battleWork = DAT_0076449c;
    previousState = ((BtlBattleState *)battleWork)->camera.stateHistory[0];
    switch (previousState) {
    case 2:
    case 0x21:
    case 0x28:
    case 0x29:
        reset = 0;
        break;
    default:
        reset = 1;
        break;
    }
    hasStatus = 0;
    hasPriorityStatus = 0;
    enemy = ((BtlBattleState *)battleWork)->unitLists[2];
    while (enemy != NULL) {
        if ((((BtlUnit *)enemy)->flags3 & 8) != 0) {
            unitData = (s32)((BtlUnit *)enemy)->datUnit;
            if (unitData != 0 && datCalcEnemyHasExtendedFlag((u8 *)unitData) != 0) {
                if (datCalcChkBadStatus(MEMBER(s32, enemy, BtlUnit, datUnit), 0x100000) != 0) {
                    hasStatus = 1;
                }
                if (datCalcIsGuarding(MEMBER(u16 *, enemy, BtlUnit, datUnit)) != 0) {
                    hasPriorityStatus = 1;
                }
            }
        }
        enemy = (u8 *)((BtlUnit *)enemy)->nextUnit;
    }
    if (hasPriorityStatus != 0) {
        selectedPreset = 2;
    } else {
        selectedPreset = (u16)btlCameraPresetPresence(hasStatus);
    }
    preset = selectedPreset & 0xFFFF;
    if (btlCurrentUnitId() == 0x208 && (preset & 0xFFFF) == 0) {
        ally = ((BtlBattleState *)DAT_0076449c)->unitLists[0];
        while (ally != NULL) {
            if ((((BtlUnit *)ally)->flags3 & 8) != 0) {
                unitData = (s32)((BtlUnit *)ally)->datUnit;
                if (unitData != 0 && datCalcChkBadStatus(unitData, 0x100) != 0) {
                    preset = 2;
                    break;
                }
            }
            ally = (u8 *)((BtlUnit *)ally)->nextUnit;
        }
    }
    action = (u8 *)((BtlCamera *)camera)->action;
    skill = ((BtlAction *)action)->unk_6e;
    targetGroups = btlEffectCollectGenusMask((s32)(action + 0x98)) & 0xFFFF;
    classification = btlSkillClassifyTargets(MEMBER(u8 *, camera, BtlCamera, action), 0, skill, 0) & 0xFFFF;
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    targetMask = targetGroups & 0xFFFF;
    if (targetMask == 2) {
        if ((((BtlBattleState *)DAT_0076449c)->battleFlags & 0x400) != 0 && (classification & 0xFFFF) == 0) {
            btlCameraReleaseOcclusion(camera);
            ((BtlCameraControl *)(DAT_0076449c + 0xC00))->updateFrame = 1;
        } else {
            actor2 = (u8 *)((BtlAction *)MEMBER(u8 *, camera, BtlCamera, action))->unit;
            if (((BtlUnit *)actor2)->genus != 0) {
                partyIndex2 = 0;
            } else {
                ordinal2 = 0;
                partyMember2 = ((BtlBattleState *)DAT_0076449c)->unitLists[1];
                goto group2_party_check;
group2_party_body:
                if (actor2 == partyMember2) {
                    goto group2_party_done;
                }
                ordinal2 = (ordinal2 + 1) & 0xFFFF;
                partyMember2 = (u8 *)((BtlUnit *)partyMember2)->prevUnit;
                goto group2_party_check;
group2_party_check:
                if (partyMember2 != NULL) {
                    goto group2_party_body;
                }
group2_party_done:
                partyIndex2 = ordinal2 & 0xFFFF;
            }
            recordBase2 = ((BtlBattleState *)DAT_0076449c)->boss.recordTable + ((partyIndex2 & 0xFFFF) * 0x48) + ((preset & 0xFFFF) * 0x18);
            record2 = recordBase2 + 0x120;
            btlCameraLookAtQuat(&poses.secondRotation, record2, record2 + 0xC, D_0060A0E0);
            poses.second = *(RwV3d *)record2;
        }
    } else if (targetMask == 1) {
        if ((classification & 0xFFFF) != 0) {
            actor1 = (u8 *)((BtlAction *)MEMBER(u8 *, camera, BtlCamera, action))->unit;
            if (((BtlUnit *)actor1)->genus != 0) {
                partyIndex1 = 0;
            } else {
                ordinal1 = 0;
                partyMember1 = ((BtlBattleState *)DAT_0076449c)->unitLists[1];
                goto group1_party_check;
group1_party_body:
                if (actor1 == partyMember1) {
                    goto group1_party_done;
                }
                ordinal1 = (ordinal1 + 1) & 0xFFFF;
                partyMember1 = (u8 *)((BtlUnit *)partyMember1)->prevUnit;
group1_party_check:
                if (partyMember1 != NULL) {
                    goto group1_party_body;
                }
group1_party_done:
                partyIndex1 = ordinal1 & 0xFFFF;
            }
            recordBase1 = ((BtlBattleState *)DAT_0076449c)->boss.recordTable + ((partyIndex1 & 0xFFFF) * 0x48) + ((preset & 0xFFFF) * 0x18);
            record1 = recordBase1 + 0x240;
            btlCameraLookAtQuat(&poses.secondRotation, record1, record1 + 0xC, D_0060A0E0);
            poses.second = *(RwV3d *)record1;
        } else {
            btlCameraReleaseOcclusion(camera);
            ((BtlCameraControl *)(DAT_0076449c + 0xC00))->updateFrame = 1;
            return;
        }
    } else {
        recordBase = ((BtlBattleState *)DAT_0076449c)->boss.recordTable + ((preset & 0xFFFF) * 0x18);
        record = recordBase + 0x360;
        btlCameraLookAtQuat(&poses.secondRotation, record, record + 0xC, D_0060A0E0);
        poses.second = *(RwV3d *)record;
    }
    if (btlCurrentUnitId() == 0x215) {
        btlCameraLookAtQuat(&poses.secondRotation, D_00634890, D_0063489C, D_0060A0E0);
        poses.second = *(RwV3d *)D_00634890;
    }
    if (reset != 0) {
        btlCameraSetupActionGeometry(MEMBER(u8 *, camera, BtlCamera, action), NULL, NULL, 0.0f, 0x100);
        btlMainCurveReset((u16 *)camera, (f32 *)&poses.second);
        return;
    }
    btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first, (f32 *)&poses.second, 1);
    btlCameraSetDuration(camera, 0.75f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Per-frame camera tick, run while the camera flag is set. [inferred]
// FUN_00224970
void btlCameraTickFrame(void)
{
    if (((BtlCameraControl *)(DAT_0076449c + 0xC00))->updateFrame != 0) {
        btlCameraUpdateFrame();
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Apply actor and target pair height offsets and return the framing distance. [inferred]
// FUN_002249A0
/* measured: ordinary C, 1780/1792 bytes, 32 code relocations and zero
 * normalized differences; the remaining 12 bytes are zero tail alignment. */
f32 btlCameraApplyPairOffsets(u8 *actor, u8 *target, RwV3d *actorPosition, RwV3d *targetPosition)
{
    u32 actorKind;
    f32 height;

    btlUnitGetSphereWorldCenter((BtlUnit *)actor, actorPosition);
    btlUnitGetSphereWorldCenter((BtlUnit *)target, targetPosition);

    actorKind = ((BtlUnit *)actor)->genus;
    if (actorKind == 0 && ((BtlUnit *)target)->genus == 1) {
        switch (((BtlUnit *)target)->charId) {
        case 0x100:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 3.5f;
        case 0x101:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x102:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff8030 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8100 * height;
            return 4.5f;
        case 0x103:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 5.0f;
        case 0x110:
        case 0x111:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 5.0f;
        case 0x104:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8128 * height;
            return 4.5f;
        case 0x105:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x106:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - 0.75f * height;
            return 5.0f;
        case 0x10F:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x107:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff813c * height;
            return 4.5f;
        case 0x108:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 5.0f;
        case 0x10A:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x112:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 4.5f;
        case 0x113:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 6.5f;
        }
    } else if (actorKind == 1 && ((BtlUnit *)target)->genus == 0) {
        switch (((BtlUnit *)actor)->charId) {
        case 0x100: {
            f32 coefficient;
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            coefficient = fGpffff8100;
            actorPosition->y = (0.0f + actorPosition->y) - coefficient * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) + coefficient * height;
            return 4.5f;
        }
        case 0x102:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff813c * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8100 * height;
            return 5.5f;
        case 0x110:
        case 0x111:
            height = ((BtlUnit *)actor)->unk_8c * ((BtlUnit *)actor)->scale;
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8030 * height;
            height = ((BtlUnit *)target)->unk_8c * ((BtlUnit *)target)->scale;
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8128 * height;
            return 5.0f;
        }
    }
    return 3.5f;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Frame the camera on the target with a distance offset and duration. [inferred]
/* b210: remaining sphere scale/radius and action reloads individually differ when typed. */
// FUN_002250A0
/* 1688/1696 bytes; all 36 resolved code relocations exact. */
#pragma opt_scalarize off
void btlCameraFrameTarget(u8 *camera, f32 distanceOffset, f32 duration)
{
    RwV3d actorPosition;
    RwV3d targetPosition;
    RwV3d basePosition;
    RwV3d focus;
    RwV3d offset;
    RwV3d direction;
    RwV3d eye;
    f32 baseXZ[2];
    f32 projectionXZ[2];
    struct {
        f32 perpendicular[2];
        f32 horizontal[2];
        f32 focusXZ[2];
        f32 eyeXZ[2];
        RtQuat yaw;
    } geometry;
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    u8 *action;
    u8 *actor;
    u8 *target;
    u8 *farUnit;
    u8 *nearUnit;
    f32 framingScale;
    f32 actorRadius;
    f32 targetRadius;
    f32 length;
    f32 sideOffset;
    f32 along;
    f32 baseZ;
    f32 baseHeight;
    f32 side;
    f32 extent;
    f32 halfAngle;
    f32 distance;
    u16 flags;

    action = (u8 *)((BtlCamera *)camera)->action;
    actor = (u8 *)((BtlAction *)action)->unit;
    target = (u8 *)((BtlTarget *)(action + 0x38))->targetedActions[0]->unit;
    framingScale = btlCameraApplyPairOffsets(actor, target, &actorPosition, &targetPosition);
    actorRadius = ((BtlUnit *)actor)->sphereRadius * ((BtlUnit *)actor)->scale;
    targetRadius = ((BtlUnit *)target)->sphereRadius * ((BtlUnit *)target)->scale;
    geometry.horizontal[0] = ((BtlCamera *)camera)->pose.pos.x - actorPosition.x;
    geometry.horizontal[1] = ((BtlCamera *)camera)->pose.pos.z - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    if (((BtlUnit *)actor)->genus == 0) {
        btlTargetBlendVectors((u8 *)&geometry.yaw, (u8 *)&actorPosition, (u8 *)&targetPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * targetRadius;
        offset.y = offset.y * targetRadius;
        offset.z = offset.z * targetRadius;
        targetPosition.x = targetPosition.x + offset.x;
        targetPosition.y = targetPosition.y + offset.y;
        targetPosition.z = targetPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = actor;
        farUnit = target;
        basePosition = actorPosition;
        sideOffset = 1.25f * (MEMBER(f32, actor, BtlUnit, sphereRadius) * MEMBER(f32, actor, BtlUnit, scale));
        along = fGpffff8128 * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    } else {
        btlTargetBlendVectors((u8 *)&geometry.yaw, (u8 *)&targetPosition, (u8 *)&actorPosition);
        RtQuatTransformVectors(&offset, (const RwV3d *)D_0060A100, 1, &geometry.yaw);
        offset.x = offset.x * actorRadius;
        offset.y = offset.y * actorRadius;
        offset.z = offset.z * actorRadius;
        actorPosition.x = actorPosition.x + offset.x;
        actorPosition.y = actorPosition.y + offset.y;
        actorPosition.z = actorPosition.z + offset.z;
        direction.x = actorPosition.x - targetPosition.x;
        direction.y = actorPosition.y - targetPosition.y;
        direction.z = actorPosition.z - targetPosition.z;
        length = RwV3dNormalize(&direction, &direction);
        nearUnit = target;
        farUnit = actor;
        basePosition = targetPosition;
        sideOffset = 0.5f * (MEMBER(f32, target, BtlUnit, sphereRadius) * MEMBER(f32, target, BtlUnit, scale));
        along = fGpffff80fc * length;
        focus.x = direction.x * along;
        focus.y = direction.y * along;
        focus.z = direction.z * along;
        baseHeight = basePosition.y;
        eye.y = baseHeight;
    }
    focus.x = focus.x + targetPosition.x;
    focus.y = focus.y + targetPosition.y;
    focus.z = focus.z + targetPosition.z;
    geometry.perpendicular[0] = direction.z;
    geometry.perpendicular[1] = -direction.x;
    side = geometry.perpendicular[0] * geometry.horizontal[0] + geometry.perpendicular[1] * geometry.horizontal[1];
    if (!(side < 0.0f)) {
        eye.x = (0.0f + basePosition.x) + direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) - direction.x * sideOffset;
    } else {
        eye.x = (0.0f + basePosition.x) - direction.z * sideOffset;
        baseZ = basePosition.z;
        eye.z = (0.0f + baseZ) + direction.x * sideOffset;
    }
    btlCameraLookAtQuat(&poses.secondRotation, &eye, &focus, D_0060A0E0);
    RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                           &poses.secondRotation);
    geometry.focusXZ[0] = focus.x;
    geometry.focusXZ[1] = focus.z;
    geometry.eyeXZ[0] = eye.x;
    geometry.eyeXZ[1] = eye.z;
    baseXZ[0] = basePosition.x;
    baseXZ[1] = baseZ;
    extent = btlTargetAngleBetween((u8 *)geometry.focusXZ, (u8 *)geometry.eyeXZ,
                          (u8 *)baseXZ, (u8 *)projectionXZ);
    extent = (0.0f + extent) + framingScale *
        (((BtlUnit *)nearUnit)->sphereRadius * ((BtlUnit *)nearUnit)->scale);
    eye.x = projectionXZ[0];
    eye.y = baseHeight;
    eye.z = projectionXZ[1];
    halfAngle = 0.5f * ((BtlCamera *)camera)->fovRad;
    distance = extent / tanf(fGpffff8110 * halfAngle);
    distance = distance + distanceOffset;
    if (distance < 100.0f) {
        distance = 100.0f;
    }
    direction.x = direction.x * distance;
    direction.y = direction.y * distance;
    direction.z = direction.z * distance;
    poses.second.x = eye.x + direction.x;
    poses.second.y = eye.y + direction.y;
    poses.second.z = eye.z + direction.z;
    if (poses.second.y < 22.5f) {
        poses.second.y = 22.5f;
    }
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (!(btlTargetQuatAngle(&poses.firstRotation,
                        &poses.secondRotation) <= fGpffff80dc)) {
        btlCameraCopyPoseTarget((f32 *)&poses.first, (f32 *)&poses.second);
        flags = 3;
    } else {
        flags = 0xC3;
    }
    btlCameraSetupActionGeometry(MEMBER(u8 *, camera, BtlCamera, action), farUnit + 4,
                  (f32 *)&poses.second, 50.0f, flags);
    if (duration == 0.0f) {
        btlCameraCopyPoseTarget((f32 *)&poses.first, (f32 *)&poses.second);
        RtQuatTransformVectors(&direction, (const RwV3d *)D_0060A100, 1,
                               &poses.firstRotation);
        direction.x = direction.x * 150.0f;
        direction.y = direction.y * 150.0f;
        direction.z = direction.z * 150.0f;
        poses.second.x = poses.first.x + direction.x;
        poses.second.y = poses.first.y + direction.y;
        poses.second.z = poses.first.z + direction.z;
        if (poses.second.y < 22.5f) {
            poses.second.y = 22.5f;
        }
        btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        btlCameraSetDuration(camera, 2.0f);
    } else {
        btlMainCurveSetPoses((u16 *)camera, (f32 *)&poses.first,
                      (f32 *)&poses.second, 1);
        btlCameraSetDuration(camera, duration);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
// Intent: Choose the camera frame mode for a unit pair from the party flags. [inferred]
/* b210: typing the action reload before the hit-row query changes instructions. */
// FUN_00225740
void btlCameraFrameUnitPair(u8 *camera)
{
    u16 targetGroups;
    u8 *action;
    u8 *actor;
    u8 *base;
    extern s32 datCalcEnemyHasTableFlag(u8 *unit);
    base = camera;
    ((BtlCameraControl *)(DAT_0076449c + 0xC00))->aimMode = 0;
    action = (u8 *)((BtlCamera *)base)->action;
    actor = (u8 *)((BtlAction *)action)->unit;
    targetGroups = btlTargetGetUnitIndex((BtlTarget *)(action + 0x38));
    if (((BtlUnit *)actor)->genus == 0) {
        if ((targetGroups & 0xFFFF & 1) == 0) {
            if (btlActionAnyTargetHitRowFlagged(MEMBER(u8 *, base, BtlCamera, action)) == 0) {
                btlCameraFrameTarget(base, 0.0f, 1.0f);
            }
        } else {
            btlCameraApplyPosePair(base);
            ((BtlCameraControl *)(DAT_0076449c + 0xC00))->aimMode = 1;
        }
    } else if ((targetGroups & 0xFFFF & 2) == 0) {
        if (datCalcEnemyHasTableFlag((u8 *)(s32)((BtlUnit *)actor)->datUnit) != 0) {
            btlCameraFrameTarget(base, 0.0f, 1.0f);
            return;
        }
        btlCameraApplyPosePair(base);
        ((BtlCameraControl *)(DAT_0076449c + 0xC00))->aimMode = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
// Intent: Tick the camera aim for the active action. [inferred]
// FUN_00225860
void btlCameraTickAim(u8 *camera)
{
    u16 mode;
    u8 *action;

    action = (u8 *)((BtlCamera *)camera)->action;
    if ((action != NULL) && ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        mode = ((BtlCameraControl *)(DAT_0076449c + 0xC00))->aimMode;
        if (mode == 1) {
            btlCameraFrameAim(camera);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
// Intent: Frame the camera on a wrapping target walk. [inferred]
/* b210: typing the wrapping target-slot reload changes instructions; BtlTarget defines its proven layout. */
// FUN_002258B0
/* Measured: 800/800 bytes, 20 resolved relocations, zero differences.
 * Disabling common-subexpression folding preserves the wrapping target walk. */
#pragma opt_common_subs off
void btlCameraFrameWrapTargetWalk(u8 *camera, f32 distanceOffset, f32 duration)
{
    u8 *action;
    u8 *unit;
    u8 *target;
    u32 index;
    f32 scale;
    f32 heightScale;

    action = (u8 *)((BtlCamera *)camera)->action;
    if (action != NULL && (((BtlAction *)action)->unk_1a & 1) != 0) {
        if (action != NULL &&
            ((BtlUnit *)(unit = (u8 *)((BtlAction *)action)->unit))->genus == 0) {
            index = 0;
            while ((action = (u8 *)((BtlCamera *)camera)->action),
                   (u16)index < ((BtlAction *)action)->unk_6a) {
                target = ((BtlAction *)action)->targets[(u16)index];
                target = (u8 *)((BtlAction *)target)->unit;
                if (((BtlUnit *)target)->genus == 1) {
                    btlUnitFaceTarget((BtlUnit *)target, (const RwV3d *)(unit + 4));
                }
                index = (u16)(index + 1);
            }
        }
        unit = (u8 *)((BtlAction *)action)->unit;
        if (((BtlUnit *)unit)->genus == 0) {
            btlCameraSetLimitFrame(camera, 0.0f, 0, 1);
            return;
        }
        target = (u8 *)((BtlTarget *)(action + 0x38))->targetedActions[0]->unit;
        scale = 1.5f;
        heightScale = fGpffff803c;
        switch (((BtlUnit *)unit)->charId) {
        case 0x100:
            scale = 1.75f;
            heightScale = 0.0f;
            break;
        case 0x101:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x102:
            scale = 3.75f;
            if (datCalcChkBadStatus((s32)((BtlUnit *)target)->datUnit, 0x100000) == 0) {
                heightScale = fGpffff8174;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x103:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x104:
            scale = 4.5f;
            if (datCalcChkBadStatus((s32)((BtlUnit *)target)->datUnit, 0x100000) == 0) {
                heightScale = fGpffff8030;
            } else {
                heightScale = fGpffff8178;
            }
            break;
        case 0x105:
            scale = 3.5f;
            heightScale = fGpffff8098;
            break;
        case 0x106:
            scale = 2.25f;
            heightScale = 0.0f;
            break;
        case 0x10F:
            scale = 3.5f;
            if (datCalcChkBadStatus((s32)((BtlUnit *)target)->datUnit, 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x107:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        case 0x108:
            scale = 3.5f;
            if (datCalcChkBadStatus((s32)((BtlUnit *)target)->datUnit, 0x100000) == 0) {
                heightScale = 0.0f;
            } else {
                heightScale = fGpffff817c;
            }
            break;
        case 0x10A:
            scale = 3.5f;
            if (datCalcChkBadStatus((s32)((BtlUnit *)target)->datUnit, 0x100000) == 0) {
                heightScale = fGpffff8118;
            } else {
                heightScale = 0.0f;
            }
            break;
        case 0x10B:
            scale = 3.5f;
            heightScale = 0.0f;
            break;
        case 0x112:
            scale = 3.0f;
            heightScale = 0.0f;
            break;
        default:
            break;
        }
        btlCameraFrameActorTarget(camera, heightScale, scale, distanceOffset, duration);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
#pragma opt_common_subs on
// Intent: Frame the camera on a wrapped target with a default duration. [inferred]
// FUN_00225BD0
void btlCameraFrameWrapTarget(u8 *camera)
{
    btlCameraFrameWrapTargetWalk(camera, 0.0f, 2.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
#pragma opt_common_subs on
// Intent: Tick the camera while waiting for the target motion. [inferred]
/* b210: remaining action reloads individually differ when typed; outer unit/target members are typed. */
// FUN_00225C00
void btlCameraTickTargetWait(u8 *cameraOrMotion)
{
    u8 *self;
    u8 *action;

    self = cameraOrMotion;
    action = (u8 *)((BtlCamera *)self)->action;
    if (action != NULL) {
        if (datCalcEnemyHasTableFlag((u8 *)((BtlAction *)action)->unit->datUnit) != 0) {
            if (btlUnitIsUnavailable(MEMBER(u8 *, self, BtlCamera, action), 0, 0) != 0) {
                btlCameraFrameWrapTargetWalk(self, 0.0f, 0.75f);
            } else {
                btlCameraFrameTarget(self, 0.0f, 0.75f);
            }
            cameraOrMotion = (u8 *)(s64)(s16)btlUnitMotionClassValue(
                (u8 *)((BtlAction *)MEMBER(u8 *, self, BtlCamera, action))->unit, 4);
            ((BtlCamera *)self)->presetRepeatCount =
                btlUnitMotionHitFrames((u8 *)((BtlCamera *)self)->action->unit,
                              4, 1.0f, (s64)((u32)cameraOrMotion & 0xFFFF));
            ((BtlCamera *)self)->presetUseCount = 0;
            ((BtlCamera *)self)->presetTarget = (s32)((BtlTarget *)(MEMBER(u8 *, self, BtlCamera, action) + 0x38))->targetedActions[0];
            return;
        }
        btlCameraWaitMotionFrames(self);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
#pragma opt_common_subs on
#pragma optimization_level 1
// Intent: Tick the camera preset selection after the action flag. [inferred]
// FUN_00225D00
void btlCameraTickSelectPreset(u8 *camera)
{
    u32 waitFrames;
    s32 elapsed;
    u8 *action;
    extern s32 datCalcEnemyHasTableFlag(u8 *unit);

    action = (u8 *)((BtlCamera *)camera)->action;
    if ((action != NULL) &&
        (((BtlAction *)action)->unk_6a == 1) &&
        (((BtlCamera *)camera)->presetTarget == (s32)((BtlTarget *)(action + 0x38))->targetedActions[0]) &&
        ((((BtlAction *)action)->unk_1a & 1) != 0)) {
        if (datCalcEnemyHasTableFlag((u8 *)((BtlAction *)action)->unit->datUnit) == 0) {
            btlCameraSelectPreset((int)camera);
            return;
        }
        waitFrames = ((BtlCamera *)camera)->presetRepeatCount;
        elapsed = ((BtlCamera *)camera)->presetUseCount + 1;
        ((BtlCamera *)camera)->presetUseCount = elapsed;
        elapsed = (u16)elapsed;
        if (waitFrames != elapsed) {
            return;
        }
        if (btlUnitIsUnavailable((u8 *)((BtlCamera *)camera)->action, 0, 0) != 0) {
            btlCameraFrameWrapTargetWalk(camera, 400.0f, fGpffff809c);
            return;
        }
        btlCameraFrameTarget(camera, 400.0f, fGpffff809c);
    }
}
#pragma pop

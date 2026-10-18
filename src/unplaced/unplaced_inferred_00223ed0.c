/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00223ed0-00225d00 */

#include "rw_types_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_skill_internal.h"
#include "btl_cond_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
typedef struct BtlTarget BtlTarget;

typedef struct BtlUnit BtlUnit;

typedef struct KwlnTask KwlnTask;

extern u32 datCalcChkBadStatus(s32 unit, u32 mask);
u8 *kwlnTaskGetTaskByName(s8 *name);
u32 kwlnTaskGetWork(void *task);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void chkmemAllocSiteTag();
extern void memset();
extern u8 D_00629738[];
extern s32 btlResultFriendPsUpdate(u8 *task);
extern void btlResultSummaryOnEventAlt();
extern void btlResultSummaryDestroy(u8 *task);
extern s32 btlUnitMotionClassValue(u8 *arg0, s32 arg1);
extern s32 btlUnitIsUnavailable(u8 *arg0, s32 arg1, s32 arg2);
extern void btlCameraWaitMotionFrames(u8 *arg0);
extern void btlCameraSelectPreset(int param_1);
extern s32 datCalcEnemyHasTableFlag(u8 *arg0);
extern void btlCameraFrameTarget(u8 *arg0, f32 arg1, f32 arg2);
extern void btlCameraFrameWrapTargetWalk(u8 *arg0, f32 arg1, f32 arg2);
extern u16 btlTargetGetUnitIndex(BtlTarget *target);
extern s32 btlActionAnyTargetHitRowFlagged(u8 *arg0);
extern void btlCameraApplyPosePair(u8 *arg0);
extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
extern f32 func_003e41e0(f32 *out, f32 *in);
extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *rotation);
extern f32 btlTargetAngleBetween(u8 *first, u8 *second, u8 *point, u8 *out);
extern void btlTargetBlendVectors(void *out, void *first, void *second);
extern void btlCameraCopyPoseTarget(f32 *out, f32 *in);
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
extern void btlCameraSetLimitFrame(u8 *camera, f32 angleLimit, s32 reverseSide, s32 forceActorSide);
extern void btlCameraFrameActorTarget(u8 *camera, f32 heightScale, f32 scale, f32 distanceOffset, f32 duration);
extern u8 D_00629700[];
void btlCameraUpdateFrame(void);
extern u8 *DAT_0076449c;
extern void btlCameraFrameAim(u8 *arg0);
extern void btlUnitFaceTarget(BtlUnit *unit, const RwV3d *target);
extern void btlCameraSelectEncounterPreset(u8 *camera);
extern void (*jtbl_008873EC[])(void *arg0);
extern void shdPersonaFinishPhase(u8 *arg0);
extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
extern void btlMainCurveReset(u16 *param_1, f32 *param_2);
extern void btlCameraCopyPose(f32 *arg0, f32 *arg1);
extern void btlMainCurveSetPoses(u16 *param_1, f32 *param_2, f32 *param_3, u16 param_4);
extern void btlCameraSetDuration(u8 *arg0, f32 arg1);
extern u8 D_0060A0E0[];
extern s32 btlCurrentUnitId(void);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
extern void btlCameraSetupActionGeometry(u8 *arg0, u8 *arg1, f32 *arg2, f32 arg4, u16 arg3);
extern u8 *iGpffffb3ac;
extern s32 datCalcIsGuarding(u16 *unit);
extern f32 btlTargetQuatAngle(void *first, void *second);
#pragma push
#pragma opt_propagation on
// Intent: Result summary event callback (same body as the overlay callback). [inferred]
// FUN_00223ED0
void btlResultSummaryOnEventAlt(s32 arg0, u16 *arg1, s32 arg2)
{
    if ((*arg1 & 2) != 0) {
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Destroy the result summary task work. [inferred]
// FUN_00223EE0
void btlResultSummaryDestroy(u8 *sdkTaskBytes)
{
    KwlnTask *task = (KwlnTask *)sdkTaskBytes;
    u8 *p;
    s32 h;

    p = (u8 *)kwlnTaskGetWork(task);
    h = *(s32 *)(p + 0x44);
    if (h != 0) {
        shdPersonaFinishPhase((u8 *)h);
        *(s32 *)(p + 0x44) = 0;
    }
    (*jtbl_008873EC)(p);
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Create the result summary task. [inferred]
// FUN_00223F40
s32 btlResultSummaryCreate(s32 arg0)
{
    u8 *temp_2;
    s32 temp_16;
    u16 *temp_2_2;

    chkmemAllocSiteTag(&D_00629738, 0x3A);
    temp_2 = (u8 *)(*jtbl_008873E8)(0x4C, 0x40000);
    memset(temp_2, 0, 0x4C);
    temp_16 = (s32)((s32)kwlnTaskCreateChild((void *)(arg0), (const void *)(&D_00629700), 0xF, 0, 0, btlResultFriendPsUpdate, btlResultSummaryDestroy, (u8 *)(temp_2)));
    temp_2_2 = (u16 *)(kwlnTaskGetWork((void *)arg0));
    *(s32 *)((u8 *)(temp_2) + 4) = 0;
    *(u16 **)((u8 *)(temp_2) + 0x3C) = (u16 *)(temp_2_2);
    memset((u8 *)(temp_2) + 8, 0, 0x30);
    *(void (**)(u16 *))((u8 *)(temp_2) + 0x10) = (void (*)(u16 *))(btlResultSummaryOnEventAlt);
    *(u8 **)((u8 *)(temp_2) + 0x18) = (u8 *)(temp_2);
    *(u16 *)((u8 *)(temp_2) + 0) = (u16)(*(u16 *)((u8 *)(temp_2) + 0) | 1);
    return temp_16;
}
#pragma pop

#pragma push
#pragma opt_propagation on
// Intent: Start the result summary task. [inferred]
// FUN_00224040
void btlResultSummaryStart(KwlnTask *task)
{
    u16 *temp_16;

    temp_16 = (u16 *)kwlnTaskGetWork(task);
    btlShuffleStartOverlay();
    *(s32 *)(temp_16 + 2) = 5;
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
extern s32 datCalcEnemyHasExtendedFlag(u8 *unitData);
extern s32 datCalcIsGuarding(u16 *unitData);
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

    previousState = *(u16 *)(iGpffffb3ac + 0x108);
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
    if (*(s32 *)(camera + 0x148) != 0) {
        reset = 1;
        *(s32 *)(camera + 0x148) = 0;
    }
    unit = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
    if (*(u8 *)(unit + 0xA2) != 0) {
        partyIndex = 0;
    } else {
        ordinal = 0;
        partyMember = *(u8 **)(iGpffffb3ac + 0x17C);
        while (partyMember != NULL) {
            if (unit == partyMember) {
                break;
            }
            ordinal = (u16)(ordinal + 1);
            partyMember = *(u8 **)(partyMember + 0xA68);
        }
        partyIndex = (u16)ordinal;
    }
    hasStatus = 0;
    hasPriorityStatus = 0;
    enemy = *(u8 **)(iGpffffb3ac + 0x180);
    while (enemy != NULL) {
        if ((*(u32 *)(enemy + 0x9C) & 8) != 0 &&
            *(u8 **)(enemy + 0xA64) != NULL &&
            datCalcEnemyHasExtendedFlag(*(u8 **)(enemy + 0xA64)) != 0) {
            if (datCalcChkBadStatus(*(s32 *)(enemy + 0xA64), 0x100000) != 0) {
                hasStatus = 1;
            }
            if (datCalcIsGuarding(*(u16 **)(enemy + 0xA64)) != 0) {
                hasPriorityStatus = 1;
            }
        }
        enemy = *(u8 **)(enemy + 0xA6C);
    }
    variant = hasPriorityStatus != 0 ? 2 : (u16)btlCameraPresetPresence(hasStatus);
    if (btlCurrentUnitId() == 0x208 && (u16)variant == 0) {
        ally = *(u8 **)(iGpffffb3ac + 0x178);
        while (ally != NULL) {
            if ((*(u32 *)(ally + 0x9C) & 8) != 0 &&
                *(u8 **)(ally + 0xA64) != NULL &&
                datCalcChkBadStatus(*(s32 *)(ally + 0xA64), 0x100) != 0) {
                variant = 2;
                break;
            }
            ally = *(u8 **)(ally + 0xA6C);
        }
    }
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    if (btlCurrentUnitId() != 0x215) {
        record = (struct EyeFocus *)(*(u8 **)(iGpffffb3ac + 0xB98) +
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
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
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
// FUN_00224450
void btlCameraSelectSkillPreset(u8 *camera)
{
    struct CameraPosePair {
        RwV3d first;
        RtQuat firstRotation;
        RwV3d second;
        RtQuat secondRotation;
    } poses;
    extern s32 datCalcEnemyHasExtendedFlag(u8 *unitData);
    extern s32 datCalcIsGuarding(u16 *unitData);
    extern s32 btlCurrentUnitId(void);
    extern u32 btlEffectCollectGenusMask(s32 targets);
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

    *(s32 *)(DAT_0076449c + 0xC0C) = 0;
    battleWork = DAT_0076449c;
    previousState = *(u16 *)(battleWork + 0x108);
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
    enemy = *(u8 **)(battleWork + 0x180);
    while (enemy != NULL) {
        if ((*(s32 *)(enemy + 0x9C) & 8) != 0) {
            unitData = *(s32 *)(enemy + 0xA64);
            if (unitData != 0 && datCalcEnemyHasExtendedFlag((u8 *)unitData) != 0) {
                if (datCalcChkBadStatus(*(s32 *)(enemy + 0xA64), 0x100000) != 0) {
                    hasStatus = 1;
                }
                if (datCalcIsGuarding(*(u16 **)(enemy + 0xA64)) != 0) {
                    hasPriorityStatus = 1;
                }
            }
        }
        enemy = *(u8 **)(enemy + 0xA6C);
    }
    if (hasPriorityStatus != 0) {
        selectedPreset = 2;
    } else {
        selectedPreset = (u16)btlCameraPresetPresence(hasStatus);
    }
    preset = selectedPreset & 0xFFFF;
    if (btlCurrentUnitId() == 0x208 && (preset & 0xFFFF) == 0) {
        ally = *(u8 **)(DAT_0076449c + 0x178);
        while (ally != NULL) {
            if ((*(s32 *)(ally + 0x9C) & 8) != 0) {
                unitData = *(s32 *)(ally + 0xA64);
                if (unitData != 0 && datCalcChkBadStatus(unitData, 0x100) != 0) {
                    preset = 2;
                    break;
                }
            }
            ally = *(u8 **)(ally + 0xA6C);
        }
    }
    action = *(u8 **)(camera + 0xE0);
    skill = *(u16 *)(action + 0x6E);
    targetGroups = btlEffectCollectGenusMask((s32)(action + 0x98)) & 0xFFFF;
    classification = btlSkillClassifyTargets(*(u8 **)(camera + 0xE0), 0, skill, 0) & 0xFFFF;
    btlCameraCopyPose((f32 *)&poses.first, (f32 *)(camera + 0x9C));
    targetMask = targetGroups & 0xFFFF;
    if (targetMask == 2) {
        if ((*(s32 *)(DAT_0076449c + 0x10) & 0x400) != 0 && (classification & 0xFFFF) == 0) {
            btlCameraReleaseOcclusion(camera);
            *(s32 *)(DAT_0076449c + 0xC0C) = 1;
        } else {
            actor2 = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
            if (*(u8 *)(actor2 + 0xA2) != 0) {
                partyIndex2 = 0;
            } else {
                ordinal2 = 0;
                partyMember2 = *(u8 **)(DAT_0076449c + 0x17C);
                goto group2_party_check;
group2_party_body:
                if (actor2 == partyMember2) {
                    goto group2_party_done;
                }
                ordinal2 = (ordinal2 + 1) & 0xFFFF;
                partyMember2 = *(u8 **)(partyMember2 + 0xA68);
                goto group2_party_check;
group2_party_check:
                if (partyMember2 != NULL) {
                    goto group2_party_body;
                }
group2_party_done:
                partyIndex2 = ordinal2 & 0xFFFF;
            }
            recordBase2 = *(u8 **)(DAT_0076449c + 0xB98) + ((partyIndex2 & 0xFFFF) * 0x48) + ((preset & 0xFFFF) * 0x18);
            record2 = recordBase2 + 0x120;
            btlCameraLookAtQuat(&poses.secondRotation, record2, record2 + 0xC, D_0060A0E0);
            poses.second = *(RwV3d *)record2;
        }
    } else if (targetMask == 1) {
        if ((classification & 0xFFFF) != 0) {
            actor1 = *(u8 **)(*(u8 **)(camera + 0xE0) + 0x30);
            if (*(u8 *)(actor1 + 0xA2) != 0) {
                partyIndex1 = 0;
            } else {
                ordinal1 = 0;
                partyMember1 = *(u8 **)(DAT_0076449c + 0x17C);
                goto group1_party_check;
group1_party_body:
                if (actor1 == partyMember1) {
                    goto group1_party_done;
                }
                ordinal1 = (ordinal1 + 1) & 0xFFFF;
                partyMember1 = *(u8 **)(partyMember1 + 0xA68);
group1_party_check:
                if (partyMember1 != NULL) {
                    goto group1_party_body;
                }
group1_party_done:
                partyIndex1 = ordinal1 & 0xFFFF;
            }
            recordBase1 = *(u8 **)(DAT_0076449c + 0xB98) + ((partyIndex1 & 0xFFFF) * 0x48) + ((preset & 0xFFFF) * 0x18);
            record1 = recordBase1 + 0x240;
            btlCameraLookAtQuat(&poses.secondRotation, record1, record1 + 0xC, D_0060A0E0);
            poses.second = *(RwV3d *)record1;
        } else {
            btlCameraReleaseOcclusion(camera);
            *(s32 *)(DAT_0076449c + 0xC0C) = 1;
            return;
        }
    } else {
        recordBase = *(u8 **)(DAT_0076449c + 0xB98) + ((preset & 0xFFFF) * 0x18);
        record = recordBase + 0x360;
        btlCameraLookAtQuat(&poses.secondRotation, record, record + 0xC, D_0060A0E0);
        poses.second = *(RwV3d *)record;
    }
    if (btlCurrentUnitId() == 0x215) {
        btlCameraLookAtQuat(&poses.secondRotation, D_00634890, D_0063489C, D_0060A0E0);
        poses.second = *(RwV3d *)D_00634890;
    }
    if (reset != 0) {
        btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), NULL, NULL, 0.0f, 0x100);
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
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
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

    actorKind = actor[0xA2];
    if (actorKind == 0 && target[0xA2] == 1) {
        switch (*(u16 *)(target + 0xA4)) {
        case 0x100:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 3.5f;
        case 0x101:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8100 * height;
            return 4.5f;
        case 0x103:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 5.0f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 5.0f;
        case 0x104:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8128 * height;
            return 4.5f;
        case 0x105:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff8118 * height;
            return 4.5f;
        case 0x106:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.75f * height;
            return 5.0f;
        case 0x10F:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x107:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff813c * height;
            return 4.5f;
        case 0x108:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + 0.5f * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - 0.25f * height;
            return 5.0f;
        case 0x10A:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8128 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff803c * height;
            return 6.0f;
        case 0x112:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8118 * height;
            return 4.5f;
        case 0x113:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8118 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) - fGpffff810c * height;
            return 6.5f;
        }
    } else if (actorKind == 1 && target[0xA2] == 0) {
        switch (*(u16 *)(actor + 0xA4)) {
        case 0x100: {
            f32 coefficient;
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            coefficient = fGpffff8100;
            actorPosition->y = (0.0f + actorPosition->y) - coefficient * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + coefficient * height;
            return 4.5f;
        }
        case 0x102:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) - fGpffff813c * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
            targetPosition->y = (0.0f + targetPosition->y) + fGpffff8100 * height;
            return 5.5f;
        case 0x110:
        case 0x111:
            height = *(f32 *)(actor + 0x8C) * *(f32 *)(actor + 0x2C);
            actorPosition->y = (0.0f + actorPosition->y) + fGpffff8030 * height;
            height = *(f32 *)(target + 0x8C) * *(f32 *)(target + 0x2C);
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

    action = *(u8 **)(camera + 0xE0);
    actor = *(u8 **)(action + 0x30);
    target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
    framingScale = btlCameraApplyPairOffsets(actor, target, &actorPosition, &targetPosition);
    actorRadius = *(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C);
    targetRadius = *(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C);
    geometry.horizontal[0] = *(f32 *)(camera + 0x9C) - actorPosition.x;
    geometry.horizontal[1] = *(f32 *)(camera + 0xA4) - actorPosition.z;
    func_003e41e0(geometry.horizontal, geometry.horizontal);

    if (*(u8 *)(actor + 0xA2) == 0) {
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
        sideOffset = 1.25f * (*(f32 *)(actor + 0x90) * *(f32 *)(actor + 0x2C));
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
        sideOffset = 0.5f * (*(f32 *)(target + 0x90) * *(f32 *)(target + 0x2C));
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
        (*(f32 *)(nearUnit + 0x90) * *(f32 *)(nearUnit + 0x2C));
    eye.x = projectionXZ[0];
    eye.y = baseHeight;
    eye.z = projectionXZ[1];
    halfAngle = 0.5f * *(f32 *)(camera + 0xB8);
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
    btlCameraSetupActionGeometry(*(u8 **)(camera + 0xE0), farUnit + 4,
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
// FUN_00225740
void btlCameraFrameUnitPair(u8 *arg0)
{
    u16 temp_4;
    u8 *temp_2;
    u8 *temp_16;
    u8 *base;
    extern s32 datCalcEnemyHasTableFlag(u8 *arg0);
    base = arg0;
    *(u16 *)(DAT_0076449c + 0xC00) = 0;
    temp_2 = *(u8 **)(base + 0xE0);
    temp_16 = *(u8 **)(temp_2 + 0x30);
    temp_4 = btlTargetGetUnitIndex((BtlTarget *)(temp_2 + 0x38));
    if (*(u8 *)(temp_16 + 0xA2) == 0) {
        if ((temp_4 & 0xFFFF & 1) == 0) {
            if (btlActionAnyTargetHitRowFlagged(*(u8 **)(base + 0xE0)) == 0) {
                btlCameraFrameTarget(base, 0.0f, 1.0f);
            }
        } else {
            btlCameraApplyPosePair(base);
            *(u16 *)(DAT_0076449c + 0xC00) = 1;
        }
    } else if ((temp_4 & 0xFFFF & 2) == 0) {
        if (datCalcEnemyHasTableFlag((u8 *)*(s32 *)(temp_16 + 0xA64)) != 0) {
            btlCameraFrameTarget(base, 0.0f, 1.0f);
            return;
        }
        btlCameraApplyPosePair(base);
        *(u16 *)(DAT_0076449c + 0xC00) = 1;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
// Intent: Tick the camera aim for the active action. [inferred]
// FUN_00225860
void btlCameraTickAim(u8 *arg0)
{
    u16 temp_5;
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0xE0);
    if ((temp_3 != NULL) && ((*(u16 *)(temp_3 + 0x1A) & 1) != 0)) {
        temp_5 = *(u16 *)(DAT_0076449c + 0xC00);
        if (temp_5 == 1) {
            btlCameraFrameAim(arg0);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
// Intent: Frame the camera on a wrapping target walk. [inferred]
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

    action = *(u8 **)(camera + 0xE0);
    if (action != NULL && (*(u16 *)(action + 0x1A) & 1) != 0) {
        if (action != NULL &&
            *(u8 *)((unit = *(u8 **)(action + 0x30)) + 0xA2) == 0) {
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
        unit = *(u8 **)(action + 0x30);
        if (*(u8 *)(unit + 0xA2) == 0) {
            btlCameraSetLimitFrame(camera, 0.0f, 0, 1);
            return;
        }
        target = *(u8 **)(*(u8 **)(action + 0x38) + 0x30);
        scale = 1.5f;
        heightScale = fGpffff803c;
        switch (*(u16 *)(unit + 0xA4)) {
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
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
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
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
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
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
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
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
                heightScale = 0.0f;
            } else {
                heightScale = fGpffff817c;
            }
            break;
        case 0x10A:
            scale = 3.5f;
            if (datCalcChkBadStatus(*(s32 *)(target + 0xA64), 0x100000) == 0) {
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
void btlCameraFrameWrapTarget(u8 *arg0)
{
    btlCameraFrameWrapTargetWalk(arg0, 0.0f, 2.0f);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma opt_scalarize on
#pragma opt_common_subs on
// Intent: Tick the camera while waiting for the target motion. [inferred]
// FUN_00225C00
void btlCameraTickTargetWait(u8 *arg0)
{
    u8 *self;
    u8 *temp_3;

    self = arg0;
    temp_3 = *(u8 **)(self + 0xE0);
    if (temp_3 != NULL) {
        if (datCalcEnemyHasTableFlag((u8 *)*(s32 *)(*(u8 **)(temp_3 + 0x30) + 0xA64)) != 0) {
            if (btlUnitIsUnavailable(*(u8 **)(self + 0xE0), 0, 0) != 0) {
                btlCameraFrameWrapTargetWalk(self, 0.0f, 0.75f);
            } else {
                btlCameraFrameTarget(self, 0.0f, 0.75f);
            }
            arg0 = (u8 *)(s64)(s16)btlUnitMotionClassValue(
                *(u8 **)(*(u8 **)(self + 0xE0) + 0x30), 4);
            *(s16 *)(self + 0x10E) =
                btlUnitMotionHitFrames(*(u8 **)(*(u8 **)(self + 0xE0) + 0x30),
                              4, 1.0f, (s64)((u32)arg0 & 0xFFFF));
            *(s16 *)(self + 0x10C) = 0;
            *(s32 *)(self + 0x100) = *(s32 *)(*(u8 **)(self + 0xE0) + 0x38);
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
void btlCameraTickSelectPreset(u8 *arg0)
{
    u32 temp_4;
    s32 temp_3;
    u8 *temp_5;
    extern s32 datCalcEnemyHasTableFlag(u8 *arg0);

    temp_5 = *(u8 **)(arg0 + 0xE0);
    if ((temp_5 != NULL) &&
        (*(u16 *)(temp_5 + 0x6A) == 1) &&
        (*(s32 *)(arg0 + 0x100) == *(s32 *)(temp_5 + 0x38)) &&
        ((*(u16 *)(temp_5 + 0x1A) & 1) != 0)) {
        if (datCalcEnemyHasTableFlag((u8 *)*(s32 *)(*(u8 **)(temp_5 + 0x30) + 0xA64)) == 0) {
            btlCameraSelectPreset((int)arg0);
            return;
        }
        temp_4 = *(u16 *)(arg0 + 0x10E);
        temp_3 = *(u16 *)(arg0 + 0x10C) + 1;
        *(u16 *)(arg0 + 0x10C) = temp_3;
        temp_3 = (u16)temp_3;
        if (temp_4 != temp_3) {
            return;
        }
        if (btlUnitIsUnavailable(*(u8 **)(arg0 + 0xE0), 0, 0) != 0) {
            btlCameraFrameWrapTargetWalk(arg0, 400.0f, fGpffff809c);
            return;
        }
        btlCameraFrameTarget(arg0, 400.0f, fGpffff809c);
    }
}
#pragma pop

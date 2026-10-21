#include "member_access.h"
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
#include "datUnit_internal.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"
#include "resrc_manager_internal.h"
#include "model_battle_internal.h"
#include "kwln_task_internal.h"
#include "btl_sound_internal.h"
/* resrcMngCreate allocates RESRC_TYPE_MAX list heads (resrcManager.c). */
typedef struct ResrcManager {
    u8 *resLists[RESRC_TYPE_MAX];
} ResrcManager;

/* scrScriptProcess.c sets up this context; scrGetMessageManager and the status-window setup below
 * read its messageWindow word. */
typedef struct ScrScriptWork {
    u8 pad00[0x130];
    s32 messageWindow;
} ScrScriptWork;

/* Unit-ID-indexed targeting rules: both tests below use the 0x58-byte stride. */
typedef struct BtlBossTargetRule {
    u16 flags;
    u8 pad02[0x56];
} BtlBossTargetRule;

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
extern u8 *resrcMngFindResById(u8 *manager, u16 resourceId);
extern u16 datCalcMaxHp(DatUnit *unit);
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern u32 datGetScriptValue(s32 index);
extern void datSetScriptValue(s32 index, u32 value);
extern void btlEncounterSetSequence(s32 start, s32 update, s32 argument);
extern void mdlScale(Model *model, const RwV3d *scale, int combineOp);
/* Retail forwards the matrix result as well as all three inputs. */
extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
typedef struct BtlAction BtlAction;
extern void btlActionSetState(BtlAction *action, u16 state);
extern void btlActionRunPresentation(u8 *action);
extern void btlActionRunMotionSequence(u8 *action);
extern RwRGBA iGpffffb45c;
extern char D_007636C0[8];
extern char D_007636C8[8];
extern char D_007636D0[8];
extern u8 D_0062E070[];
extern void mdlSetFrameColorByName(void *model, s32 name, u8 alpha);
extern s32 datCalcAddHp(DatUnit *unit, s32 hpDelta);
extern void datCalcClearBuffLevel(u8 *unit, s32 buffIndex);
extern RtQuat *func_003dc740(RtQuat *out, const RwV3d *axis, f32 angle, s32 mode);
extern void btlUnitSetRot(BtlUnit *unit, const RtQuat *rot);
extern void btlUnitSetColor(BtlUnit *unit, RwRGBA col);
extern u32 datCalcClearBadStatus(s32 unit, u32 badStatus);
extern void btlUnitShowModel(u8 *unit);
extern u32 datGetFlag(s32 bit);


extern u8 D_006290F0[];

u32 kwlnTaskGetWork(void *task);
extern u8 D_00629698[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern u8 D_00795F20[];
extern u8 D_006296D0[];
extern u8 D_008C0240[0x94];
extern u8 D_00635560[], D_00635580[];
extern u8 iGpffffa4d8[4];
extern u8 *btlTargetCreateProcedurePacket(s32 action, s32 scriptKind, u8 *procedureName);
extern u8 *btlPacketAllocZeroed(void *callback, void *data);
extern BtlPacket *btlEffectCreateMessagePacket(u8 *color, u16 fadeMode);
extern BtlPacket *btlEffectCreateFadeLevelPacket(u16 level);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
extern u8 *btlUnitCreateModelLoadPacket(u8 *unit, u16 modelId, s16 motion);
extern BtlPacket *btlBossCreateLoadEndBgmPacket(s32 id);
extern BtlPacket *btlBossCreateReleaseEndBgmPacket(void);
extern BtlPacket *btlBossCreateStepEndBgmPacket(void);
extern BtlPacket *btlBossCreateStopEndBgmPacket(void);
extern BtlPacket *btlCreateTimingPacket(u32 value);
extern BtlPacket *btlMainCreateFadePacket(s32 arg, s16 mode);
extern BtlPacket *btlMainCreateColorFadePacket(s32 arg);
extern BtlPacket *btlMainCreateColorSetPacket(s32 arg);

extern u8 D_00629640[];
extern u8 D_00629738[];
extern f32 fGpffff80fc;
extern f32 fGpffff80dc;
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

extern u8 D_006296B0[];
extern u8 D_006296E8[];

extern u8 D_00629700[];


extern u8 *DAT_0076449c; /* active battle state */
extern s32 btlUnitSkillBlocked(u8 *action, u8 *subordinate);

extern u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask);
extern void datSetFlag(s32 flagId, s32 enabled);
extern s32 kwlnTaskIsLinked(void *target);
extern u8 *btlActionFindByUnit(s32 unit);
extern void btlTargetSetDefeatState(u8 *context, s32 argument);
extern void btlSoundStopBgmIfEnabled(void);


u8 *H_Cdvd_GetArchiveEntry(u8 *request, s32 entryIndex, s32 *size);


extern void (*jtbl_008873EC[])(void *value);
extern void btlSoundFadeOutBgm(s16 fadeDuration);
extern void sdkSndPlayCue(s32 value, s32 option);
extern u32 datCalcRandomBelow(u32 limit);
extern u8 D_0060A0E0[];
extern s32 btlCurrentUnitId(void);
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
extern u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
extern f32 fGpffff834c;
extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
extern void btlUnitSetPos(u8 *unit, s32 *pos);
extern void btlTargetPositionToCell(s16 *outX, s16 *outZ, f32 *position);
extern u8 *iGpffffb3e0;
extern s32 btlActionHasNoTargetClass(u32 action);
extern s32 btlTargetCanSelectEntry(u8 *context, s16 value, s32 option);
extern s32 btlBossTargetBlocked(u8 *action);
extern s32 btlBossSkillResultBlocked(u8 *action);

extern s64 btlPacketEnqueue(u8 *context, u32 value);
extern u8 D_00632240[];
extern u8 *btlUnitFindInSideById(s32 genus, s32 characterId);
extern u8 D_0062D920[];
extern void btlActionFinishPresentation(s64 *action);
extern s32 btlFormationAllocWork(u32 mode);
extern void btlFormationSetSlot(s32 formation, u32 resource);
extern u8 *btlFormationGetRecord(s32 index);
extern void btlFormationCopyRecord(int destination, u32 source);
extern BtlPacket *btlUnitCreateColorPacket(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
extern void btlTargetClearResultBuffer(u8 *result);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlUnitCreateAnimPacket(u8 *unit, s32 id, s32 blendFrameCount, s32 speed, f32 mode);
extern BtlPacket *btlFormationCreatePacket(u32 formation, u32 sourceUnit, u32 targetUnit, u16 side, u32 flags);
extern void btlFormationSetPlacement(u32 formation);
extern u8 D_006354B0[];
extern u8 *iGpffffb444;
extern u8 *iGpffffb3ac; /* active battle state, GP-relative alias */
extern u8 *scrStartProcedureIndex(s32 priority, u8 *header, s32 procedureIndex);
extern void scrSetTaskProc(u8 *task, u8 *proc);
extern u8 *datPersonaNamePart1Alt(s16 unitId);
extern void itfMesWindowSetString(u8 *handle, s32 slotIndex, u8 *text);
extern void kwlnTaskAddChild(u8 *parent, u8 *child);
extern u8 D_00629750[], D_00629EA0[], D_0062CA80[], D_0062D1D0[];
extern u8 D_0062E7C0[], D_0062EF10[], D_0062F660[], D_0062FDB0[];
extern u8 D_00630500[], D_00630C50[], D_006313A0[], D_00631AF0[];
extern u8 D_006355A0[];
extern void btlUnitInitChild(u8 *unit, u16 characterId);
extern void datAssignEquippedItem(s16 unitId, s16 slotIndex, s16 itemId);
extern u16 datCalcMaxHpById(s16 unitId);
extern u16 datCalcMaxSpById(s16 unitId);
extern void datSetUnitHp(s16 unitId, s16 hp);
extern void datSetUnitSp(s16 unitId, s16 sp);
extern void datCalcClearBadStatusById(s16 unitId, u32 mask);
extern s32 btlActionQueuePush(u8 *action);

extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern u32 datCalcIsDead(void *unit, s32 hpDelta);
extern u8 D_006354C0[], D_006354D0[], D_00635500[];
extern f32 fGpffff80e4;

extern void btlCameraApplyPartyPose(u8 *camera);
extern void btlEncounterStartSequence(u8 *action);
extern s32 btlEncounterFinishStep(u8 *action);
extern void btlActionRunPresentation(u8 *action);
extern s32 btlEncounterWaitCleared(s64 *actionUid);
extern void btlActionRunMotionSequence(u8 *action);
extern s32 btlEncounterReleaseFlags(s64 *actionUid);
extern void btlEncounterStartCameraState(u8 *action);
extern s32 btlEncounterWaitReleaseEvents(s64 *actionUid);
extern void btlEncounterResetSlots(u8 *action);
extern s32 btlEncounterWaitIdle(s64 *actionUid);

#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Fade the battle BGM over 45 frames and complete this sequence packet. */
// FUN_0022B0B0
s32 btlEncounterSetState2D(void)
{
    btlSoundFadeOutBgm(0x2D);
    return 1;
}

// Play the cue when battle flag 0x40 is set.
// FUN_0022B0E0
s32 btlEncounterPlayCueIfFlag40(void)
{
    if (((BtlBattleState *)DAT_0076449c)->flags & 0x40) {
        sdkSndPlayCue(6, 1);
    }
    return 1;
}

// Run the formation presentation sequence for an action.
// FUN_0022B120
void btlActionRunFormationSequence(u8 *action)
{
    u8 *actor;
    s32 openingFormation;
    s32 closingFormation;
    u8 *wait1;
    u8 *wait0;
    u8 *anchor;
    u8 *cleanup;
    u8 *packet;
    RwV3d rotation;

    actor = (u8*)((BtlAction *)action)->unit;
    ((BtlBattleState *)DAT_0076449c)->flags |= 0x400000;
    ((BtlBattleState *)DAT_0076449c)->actionEndFlags |= 0x23;
    btlActionFinishPresentation((s64 *)action);
    openingFormation = btlFormationAllocWork(0);
    closingFormation = btlFormationAllocWork(0);
    btlFormationCopyRecord(openingFormation, (u32)btlFormationGetRecord(0xC));
    btlFormationCopyRecord(closingFormation, (u32)btlFormationGetRecord(0xD));
    ((BtlBattleState *)DAT_0076449c)->flags |= 0x80000;

    anchor = btlTargetCreateProcedurePacket((s32)action, 3, D_00635560);
    ((BtlPacket *)anchor)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(anchor, 1);

    packet = btlPacketAllocZeroed((void *)btlEncounterSetState2D, action);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = ((BtlPacket *)anchor)->uid;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = btlUnitCreateAnimPacket(actor, 0x13, 0, 2, 1.0f);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)packet)->delay = 2;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 0);

    packet = (u8 *)btlBossCreateStepEndBgmPacket();
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)packet)->delay = 0x33;
    btlPacketEnqueue(packet, 1);

    wait1 = (u8 *)btlFormationCreatePacket((u32)openingFormation, (u32)actor, (u32)actor, 0, 0x200);
    ((BtlPacket *)wait1)->dependencyKind = 4;
    ((BtlPacket *)wait1)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)wait1)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(wait1, 2);

    wait0 = (u8 *)btlFormationCreatePacket((u32)openingFormation, (u32)actor, (u32)actor, 1, 0x200);
    ((BtlPacket *)wait0)->dependencyKind = 4;
    ((BtlPacket *)wait0)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)wait0)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(wait0, 2);

    packet = (u8 *)btlEffectCreateMessagePacket(iGpffffa4d8, 0x1E);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)packet)->delay = 0x19A;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    rotation.x = 0.0f;
    rotation.y = 0.0f;
    rotation.z = (f32)3000;
    packet = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)actor, &rotation, 2);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = ((BtlPacket *)wait1)->uid;
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = ((BtlPacket *)wait0)->uid;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 0);

    anchor = (u8 *)btlUnitCreateModelReleasePacket((BtlUnit *)actor);
    ((BtlPacket *)anchor)->dependencyKind = 4;
    ((BtlPacket *)anchor)->dependencyUID = MEMBER(u64, wait1, BtlPacket, uid);
    ((BtlPacket *)anchor)->dependencyKind2 = 4;
    ((BtlPacket *)anchor)->dependencyUID2 = MEMBER(u64, wait0, BtlPacket, uid);
    ((BtlPacket *)anchor)->delay = 1;
    ((BtlPacket *)anchor)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(anchor, 1);

    packet = (u8 *)btlBossCreateStopEndBgmPacket();
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, wait1, BtlPacket, uid);
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = MEMBER(u64, wait0, BtlPacket, uid);
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    cleanup = (u8 *)btlBossCreateReleaseEndBgmPacket();
    ((BtlPacket *)cleanup)->dependencyKind = 4;
    ((BtlPacket *)cleanup)->dependencyUID = MEMBER(u64, wait1, BtlPacket, uid);
    ((BtlPacket *)cleanup)->dependencyKind2 = 4;
    ((BtlPacket *)cleanup)->dependencyUID2 = MEMBER(u64, wait0, BtlPacket, uid);
    ((BtlPacket *)cleanup)->delay = 3;
    ((BtlPacket *)cleanup)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(cleanup, 1);

    wait0 = btlUnitCreateModelLoadPacket(actor, 0x10E, 0x216);
    ((BtlPacket *)wait0)->dependencyKind = 4;
    ((BtlPacket *)wait0)->dependencyUID = ((BtlPacket *)anchor)->uid;
    ((BtlPacket *)wait0)->delay = 2;
    ((BtlPacket *)wait0)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(wait0, 1);

    anchor = btlTargetCreateProcedurePacket((s32)action, 3, D_00635580);
    ((BtlPacket *)anchor)->dependencyKind = 4;
    ((BtlPacket *)anchor)->dependencyUID = ((BtlPacket *)wait0)->uid;
    ((BtlPacket *)anchor)->delay = 2;
    ((BtlPacket *)anchor)->duration = 0xC;
    ((BtlPacket *)anchor)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(anchor, 1);

    packet = btlPacketAllocZeroed((void *)btlEncounterPlayCueIfFlag40, action);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = ((BtlPacket *)anchor)->uid;
    ((BtlPacket *)packet)->delay = 1;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlBossCreateLoadEndBgmPacket(0x10E);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = ((BtlPacket *)cleanup)->uid;
    ((BtlPacket *)packet)->delay = 1;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlUnitCreateColorPacket((BtlUnit *)actor, 0xFFFFFFFFU, 1, 0, 3, 0);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)packet)->delay = 2;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlEffectCreateFadeLevelPacket(0x1E);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)packet)->delay = 4;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    wait0 = (u8 *)btlFormationCreatePacket((u32)closingFormation, (u32)actor, (u32)actor, 0, 0x200);
    ((BtlPacket *)wait0)->dependencyKind = 4;
    ((BtlPacket *)wait0)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)wait0)->delay = 2;
    ((BtlPacket *)wait0)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(wait0, 2);

    wait1 = (u8 *)btlFormationCreatePacket((u32)closingFormation, (u32)actor, (u32)actor, 1, 0x200);
    ((BtlPacket *)wait1)->dependencyKind = 4;
    ((BtlPacket *)wait1)->dependencyUID = MEMBER(u64, anchor, BtlPacket, uid);
    ((BtlPacket *)wait1)->delay = 2;
    ((BtlPacket *)wait1)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(wait1, 2);

    packet = (u8 *)btlCreateTimingPacket(0x10);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = ((BtlPacket *)wait0)->uid;
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = ((BtlPacket *)wait1)->uid;
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, wait0, BtlPacket, uid);
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = MEMBER(u64, wait1, BtlPacket, uid);
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlMainCreateColorFadePacket(0x10);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, wait0, BtlPacket, uid);
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = MEMBER(u64, wait1, BtlPacket, uid);
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 1);

    packet = (u8 *)btlMainCreateColorSetPacket(8);
    ((BtlPacket *)packet)->dependencyKind = 4;
    ((BtlPacket *)packet)->dependencyUID = MEMBER(u64, wait0, BtlPacket, uid);
    ((BtlPacket *)packet)->dependencyKind2 = 4;
    ((BtlPacket *)packet)->dependencyUID2 = MEMBER(u64, wait1, BtlPacket, uid);
    ((BtlPacket *)packet)->actionUID = ((BtlAction *)action)->uid;
    btlPacketEnqueue(packet, 0);

    btlFormationSetPlacement((u32)closingFormation);
    btlFormationSetPlacement((u32)openingFormation);
}

/* measured: btlEncounterFinishSetup only matches retail's loop code generation with loop-invariant
 * hoisting enabled. */
#pragma opt_loop_invariants on
// Finish encounter setup once the presentation completes.
// FUN_0022B870
s32 btlEncounterFinishSetup(u8 *action)
{
    extern void btlUnitInitFromRecord(u8 *unit, s32 characterId);
    extern s32 btlActionQueuePush(u8 *action);
    extern s32 btlActionGetQueueFront(void);
    extern void btlBossCollectTargets(u8 *preferredAction);
    extern u8 *btlSoundGetCharacterBank(u8 *unit);
    extern u8 D_00630C50[];
    u32 index;
    s32 value;
    s32 emptySlot;
    u8 *unitData;

    if (btlUnitRecordFindByActionUID(((BtlAction *)action)->uid,
                      ((u64)0x3FFFFFFF << 32) | 0xFFFFFFFF) == NULL) {
        ((BtlBattleState *)DAT_0076449c)->flags &= 0xFFF7FFFF;
        btlUnitInitFromRecord((u8*)((BtlAction *)action)->unit, 0x10E);
        datUnitInit((DatUnit *)((u8*)((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->datUnit), 1, 0x10E);
        datSetFlag(0x15FF, 1);
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = &D_00630C50[0];
        ((BtlBattleState *)DAT_0076449c)->bossRecordVariant = 1;
        ((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->flags3 |= 0x2000;
        ((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->flags3 &= 0xFFFF7FFF;
        ((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->flags3 &= ~0x20;
        unitData = (u8*)((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->datUnit;
        ((DatUnit *)unitData)->flags |= 0x20;
        ((BtlAction *)action)->unk_1a |= 0x100;
        btlActionQueuePush(action);
        btlBossCollectTargets((u8 *)btlActionGetQueueFront());
        index = 0;
        emptySlot = -1;
        goto loop_test;
loop_body:
        /* Retail indexes the battle state base by byte offset per cue slot rather than indexing the
         * cue array directly. */
        *(s8 *)&((BtlBattleState *)(DAT_0076449c + index))->bossCuePrefix[0] = emptySlot;
        index++;
loop_test:
        if (index < 0x1E) {
            goto loop_body;
        }
        value = (s32)btlSoundGetCharacterBank(MEMBER(u8 *, action, BtlAction, unit));
        /* The unit pointer is read through a raw pointer cast because a typed field access changes
         * the generated code. */
        ((Model *)((BtlUnit *)*(u8 * *)&((BtlAction *)(action))->unit)->layerHandle)->motion.request = value;
        btlUnitUpdateStatusMotion(*(u8 * *)&((BtlAction *)(action))->unit, 6);
        datSetFlag(0x15C0, 0);
        ((BtlBattleState *)DAT_0076449c)->boss.displayedIds[3] = 0;
        ((BtlBattleState *)DAT_0076449c)->boss.displayedStates[3] = 0;
        ((BtlBattleState *)DAT_0076449c)->queueFlags |= 0x10;
        return 0;
    }
    return 1;
}

/* measured: optimization level 1 keeps retail's loop branch shape. Clears the defeat state of unit
 * 0x10E and stops its BGM; retail ignores the supplied ID. */
/* Find unit 0x10E in the battle's third unit list, clear the defeat state on its action, and stop
 * the BGM. The supplied ID is ignored. */
// FUN_0022BA40
void btlEncounterResetUnit(u16 unusedId)
{
    s32 value;
    s32 id;
    u8 *unit;

    unit = ((BtlBattleState *)DAT_0076449c)->unitLists[2];
    id = 0x10E;
    goto check;
body:
    value = ((BtlUnit *)unit)->charId;
    if (value == id) {
        goto found;
    }
    unit = (u8 *)((BtlUnit *)unit)->nextUnit;
check:
    if (unit != NULL) {
        goto body;
    }
found:
    if (unit != NULL) {
        unit = (u8 *)btlActionFindByUnit((s32)unit);
        if (unit != NULL) {
            btlTargetSetDefeatState(unit, 0);
            btlSoundStopBgmIfEnabled();
        }
    }
}

// FUN_0022BAC0
/* Finish the reset-unit sequence immediately; the dispatcher clears callbacks on a zero update result. */
s32 btlEncounterFinishResetSequence(void)
{
    return 0;
}

// Show the unit status window for the given slot.
// FUN_0022BAD0
s32 btlUnitStatusWindowShow(u8 *action, u16 slotIndex)
{
    u8 *target;
    u8 *handle;
    u8 *state;
    u8 *unit;
    u8 *slot;
    u8 *formationData;

    slot = &((u8 *)(((u32)slotIndex & 0xFFFF) * 4))
        [(u32)iGpffffb3ac];
    if (((BtlBattleState *)slot)->boss.displayedIds[0] != (s32)((BtlAction *)action)->id) {
        goto changed;
    }
    if (((BtlBattleState *)slot)->boss.displayedStates[0] != (s32)((BtlAction *)action)->unk_20) {
        goto changed;
    }
    return 0;
changed:
    if (action == NULL) {
        target = ((BtlBattleState *)iGpffffb3ac)->selectedAction;
    } else {
        target = action;
    }
    formationData = btlFormationGetRecord(0);
    handle = scrStartProcedureIndex(
        ((KwlnTask *)((BtlBattleState *)iGpffffb3ac)->cutinTaskParent)->unk20Value - 1,
        formationData, slotIndex);
    scrSetTaskProc(handle, target);
    state = (u8 *)kwlnTaskGetWork(handle);
    if (((ScrScriptWork *)state)->messageWindow >= 0) {
        unit = (u8*)((BtlAction *)target)->unit;
        if (((BtlUnit *)unit)->genus == 0) {
            itfMesWindowSetString(
                MEMBER(u8 *, state, ScrScriptWork, messageWindow), 0,
                datPersonaNamePart1Alt((s16)((BtlUnit *)unit)->charId));
        } else {
            itfMesWindowSetString(
                (u8*)((ScrScriptWork *)state)->messageWindow, 0,
                iGpffffb444 + (u16)(((BtlUnit *)unit)->charId) * 0x15);
        }
    }
    kwlnTaskAddChild((u8*)((BtlBattleState *)iGpffffb3ac)->cutinTaskParent, handle);
    ((BtlBattleState *)iGpffffb3ac)->boss.statusTask = handle;
    ((BtlBattleState *)iGpffffb3ac)->boss.statusSlot = slotIndex;
    *(s32 *)&((BtlBattleState *)(&((u8 *)(((u32)slotIndex & 0xFFFF) * 4))
              [(u32)iGpffffb3ac]))->boss.displayedIds[0] =
        MEMBER(s32, action, BtlAction, id);
    *(s32 *)&((BtlBattleState *)(&((u8 *)(((u32)slotIndex & 0xFFFF) * 4))
              [(u32)iGpffffb3ac]))->boss.displayedStates[0] =
        (s32)((BtlAction *)action)->unk_20;
    return 1;
}

// Report whether the status task is linked to the given slot.
// FUN_0022BC80
s32 btlTaskSlotIsLinked(s32 slotIndex) {
    u8 *battle = DAT_0076449c;
    u8 *task = ((BtlBattleState *)battle)->boss.statusTask;

    if (task == NULL) {
        return 0;
    }
    if (((BtlBattleState *)battle)->boss.statusSlot != (slotIndex & 0xFFFF)) {
        return 0;
    }
    if (kwlnTaskIsLinked(task) == 0) {
        ((BtlBattleState *)DAT_0076449c)->boss.statusTask = 0;
        return 0;
    }
    return 1;
}

// Report whether a status task is set.
// FUN_0022BD00
s32 btlTaskSlotIsSet(void)
{
    return ((BtlBattleState *)DAT_0076449c)->boss.statusTask != 0;
}

/* Return nonzero if the current encounter's sound track rule has the boss flag set. */
// FUN_0022BD20
/* Test encounter-entry flag 0x20, which gates boss setup, resource loading, and boss action voices. */
s32 btlEncounterIsBoss(void)
{
    return (((BtlSoundTrackRule *)(iGpffffb414 +
                     ((BtlSoundEncounterRecord *)(u8 *)((BtlBattleState *)DAT_0076449c)->encounterRecord)->trackRule * 0x18))->flags &
            0x20) != 0;
}

/* measured: retail hoists the signed empty-slot sentinel into the clearing loop's preheader. */
#pragma push
// Initialise the encounter globals for each battle ID.
// FUN_0022BD60
void btlEncounterInitGlobals(void)
{
    u32 i;

    ((BtlBattleState *)DAT_0076449c)->flags |= 0x200000;
    ((BtlBattleState *)DAT_0076449c)->battleFlags |= 1;
    switch (btlCurrentUnitId()) {
    case 0x200:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_00629750;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x201:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_00629EA0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x202:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062A5F0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x203:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x400;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062B490;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x204:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062CA80;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x205:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x200;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062D1D0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x206:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062D920;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        ((BtlBattleState *)DAT_0076449c)->bossPhase = 0;
        break;
    case 0x207:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062E7C0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x208:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062EF10;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x209:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x80;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x800;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062F660;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x20A:
        ((BtlBattleState *)DAT_0076449c)->flags &= ~0x400U;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x100;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x200;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062FDB0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x20B:
    case 0x215:
        ((BtlBattleState *)DAT_0076449c)->flags &= ~0x400U;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x200;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x2000;
        if (btlCurrentUnitId() == 0x20B) {
            ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_00630500;
        } else {
            ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_00630C50;
        }
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x20C:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        break;
    case 0x20D:
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x80;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_006313A0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        break;
    case 0x214:
        ((BtlBattleState *)DAT_0076449c)->flags &= ~0x400U;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 2;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x1000000;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x100;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x200;
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_00631AF0;
        ((BtlBattleState *)DAT_0076449c)->bossSlotTable = D_006355A0;
        datSetFlag(0x1438, 1);
        break;
    }
    for (i = 0; i < 30; i++) {
        *(s8 *)&((BtlBattleState *)(DAT_0076449c + i))->bossCuePrefix[0] = -1;
    }
}

#pragma pop
/* Allocates the encounter formation slots for each battle id; each lookup/allocate/set/store
 * sequence reloads its global, as retail does. */
// FUN_0022C430
void btlFormationAllocEncounterSlots(void)
{
    u8 *data;
    s32 formation;

    switch (btlCurrentUnitId()) {
    case 0x200:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x201:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        break;
    case 0x202:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        break;
    case 0x203:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x204:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x205:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x206:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        data = btlFormationGetRecord(9);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[5] = formation;
        break;
    case 0x207:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        break;
    case 0x208:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x209:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(5);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[1] = formation;
        data = btlFormationGetRecord(6);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[2] = formation;
        data = btlFormationGetRecord(7);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[3] = formation;
        break;
    case 0x20A:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x20B:
    case 0x215:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    case 0x20D:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(5);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[1] = formation;
        data = btlFormationGetRecord(6);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[2] = formation;
        data = btlFormationGetRecord(7);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[3] = formation;
        break;
    case 0x214:
        data = btlFormationGetRecord(4);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[0] = formation;
        data = btlFormationGetRecord(8);
        formation = btlFormationAllocWork(2);
        btlFormationSetSlot(formation, (u32)data);
        ((BtlBattleState *)DAT_0076449c)->boss.formations[4] = formation;
        break;
    }
}

// Look up the formation slot index for a unit.
// FUN_0022CB90
s32 btlFormationLookupSlot(u8 *unit, u16 slotIndex)
{
    s32 slotTable;
    s8 overrideSlot;
    u16 unitId;
    u8 *battle;
    u16 slot;

    if (((BtlUnit *)unit)->genus != 1) {
        return -1;
    }
    battle = DAT_0076449c;
    slotTable = (s32)((BtlBattleState *)battle)->bossSlotTable;
    if (slotTable == 0) {
        return -1;
    }
    unitId = ((BtlUnit *)unit)->charId;
    switch (unitId) {
    case 0x10D:
    case 0x110:
    case 0x111:
        return ((u8 *)slotTable)[slotIndex & 0xFFFF];
    case 0x10F:
        slot = (u16)slotIndex;
        if (((slot == 0) || (slot == 0x12)) &&
            (((BtlBattleState *)battle)->bossPhase != 3)) {
            return 0xB;
        }
        return ((u8 *)slotTable)[slotIndex & 0xFFFF];
    default:
        overrideSlot = ((s8 *)((u32)&((BtlBattleState *)battle)->bossCuePrefix[0] + (u32)(slotIndex & 0xFFFF)))[0];
        if (overrideSlot >= 0) {
            return overrideSlot;
        }
        return ((u8 *)slotTable)[slotIndex & 0xFFFF];
    }
}

/* measured: retail does not propagate the formation index and slot cursor into the loop body. */
#pragma opt_propagation off
// Clear the formation slots and their placements.
// FUN_0022CC90
void btlFormationClearSlots(void)
{
    extern void H_Cdvd_Destroy(s32 cdvd);
    extern void btlFormationSetPlacement(s32 value, u8 *option);
    s16 i;
    s32 value;
    s32 signedSlot;
    s32 index;
    s16 index16;
    u8 *slot;
    u8 *base;

    switch (btlCurrentUnitId()) {
    case 0x214:
        datPersonaClearRoster();
        datPersonaAddRosterMember(1);
        datPersonaSelectRosterMemberById(1);
        datAssignEquippedItem(1, 0, 1);
        break;
    }
    i = 0;
    while (i < 8) {
        base = DAT_0076449c;
        slot = base + i * 4;
        value = ((BtlBattleState *)slot)->boss.formations[0];
        if (value != 0) {
            index16 = i;
            signedSlot = (s32)(s64)(s16)index16;
            index = signedSlot * 4;
            btlFormationSetPlacement(value, base);
            base = DAT_0076449c;
            *(s32 *)&((BtlBattleState *)(base + index))->boss.formations[0] = 0;
        }
        i++;
    }
    value = ((BtlBattleState *)DAT_0076449c)->bossEndBgmHandle;
    if (value != 0) {
        H_Cdvd_Destroy(value);
        ((BtlBattleState *)DAT_0076449c)->bossEndBgmHandle = 0;
    }
    value = ((BtlBattleState *)DAT_0076449c)->bossPakHandle;
    if (value != 0) {
        H_Cdvd_Destroy(value);
        ((BtlBattleState *)DAT_0076449c)->bossPakHandle = 0;
    }
}

/* measured: btlUnitApplyPacketEffects and btlUnitReactToDeath need copy propagation turned back on. */
#pragma opt_propagation on
// Return the encounter record for an index, or NULL.
// FUN_0022CDB0
u8 *btlEncounterGetRecord(s32 index)
{
    s32 encounterId;
    u8 *record;

    if ((((BtlBattleState *)DAT_0076449c)->battleFlags & 0x10) == 0) {
        return NULL;
    }
    encounterId = btlCurrentUnitId();
    switch (encounterId) {
    case 0x20B:
        if (((BtlBattleState *)DAT_0076449c)->bossRecordVariant == 0) {
            record = (u8 *)((s32)&D_00634CB0 +
                           ((index & 0xFFFF) * 0x14));
        } else {
            record = (u8 *)((s32)&D_006350B0 +
                           ((index & 0xFFFF) * 0x14));
        }
        break;
    case 0x215:
        record = (u8 *)((s32)&D_006350B0 +
                       ((index & 0xFFFF) * 0x14));
        break;
    default:
        record = (u8 *)((s32)&D_006348B0 +
                       ((index & 0xFFFF) * 0x14));
        break;
    }
    if ((((BtlCameraStateRecord *)record)->initialize == 0) &&
        (((BtlCameraStateRecord *)record)->update == 0)) {
        record = NULL;
    }
    return record;
}

// Return the formation record for an index.
// FUN_0022CED0
u8 *btlFormationGetRecord(s32 index)
{
    return H_Cdvd_GetArchiveEntry((u8 *)((BtlBattleState *)DAT_0076449c)->bossPakHandle, index & 0xFFFF, 0);
}

// Return the action anchor height for a unit.
// FUN_0022CF00
f32 btlUnitGetActionAnchorHeight(u8 *source, u8 *unit, u16 actionKind) {
    s32 kind;
    u16 unitId;

    if (!(((BtlBattleState *)DAT_0076449c)->flags & 0x200000)) {
        return -1.0f;
    }
    if (((BtlUnit *)unit)->genus != 1) {
        return -1.0f;
    }
    kind = actionKind & 0xFFFF;
    if ((kind != 4) && (kind != 0xC) &&
        (kind != 5) && (kind != 7)) {
        return -1.0f;
    }
    unitId = ((BtlUnit *)unit)->charId;
    switch (unitId) {
    case 0x100:
        return 100.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x101:
        return 25.0f + (((BtlUnit *)unit)->sphereRadius *
                        ((BtlUnit *)unit)->scale);
    case 0x102:
        return 150.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x103:
        return 150.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x110:
        return 150.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x111:
        return 150.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x104:
        return 50.0f + (((BtlUnit *)unit)->sphereRadius *
                        ((BtlUnit *)unit)->scale);
    case 0x105:
        return 200.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x106:
        return 250.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x10F:
        return 250.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x107:
        return 200.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x108:
        return 300.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x10A:
        return 500.0f + (((BtlUnit *)unit)->sphereRadius *
                         ((BtlUnit *)unit)->scale);
    case 0x113:
        return 75.0f + (((BtlUnit *)unit)->sphereRadius *
                        ((BtlUnit *)unit)->scale);
    case 0x109:
    case 0x10B:
    case 0x10C:
    case 0x10D:
    case 0x10E:
    case 0x112:
    default:
        goto fail;
    }
fail:
    return -1.0f;
}

// Select the formation slot for the action's unit.
// FUN_0022D200
s32 btlActionSelectFormationSlot(u8 *action)
{
    u8 *global;
    u8 *unit;
    u16 unitId;
    u16 skill;

    global = iGpffffb3ac;
    if ((((BtlBattleState *)global)->flags & 0x200000) == 0) {
        return 0;
    }
    if ((((BtlAction *)action)->unk_1a & 1) == 0) {
        return 0;
    }
    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 1) {
        return 0;
    }
    unitId = ((BtlUnit *)unit)->charId;
    switch (unitId) {
    case 0x100:
        skill = ((BtlAction *)action)->unk_6e;
        return skill == 0x160 ? ((BtlBattleState *)global)->boss.formations[4] : ((BtlBattleState *)global)->boss.formations[0];
    case 0x103:
        skill = ((BtlAction *)action)->unk_6e;
        if (skill == 0x166 || skill == 0x167 || skill == 0x168) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        return ((BtlBattleState *)global)->boss.formations[0];
    case 0x104:
        skill = ((BtlAction *)action)->unk_6e;
        return skill == 0x169 ? ((BtlBattleState *)global)->boss.formations[4] : ((BtlBattleState *)global)->boss.formations[0];
    case 0x106:
    case 0x10F:
        skill = ((BtlAction *)action)->unk_6e;
        if (skill == 0x16D || skill == 0x173 || skill == 0x174 ||
            skill == 0x175 || skill == 0x176 || skill == 0x177) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        return skill == 0x172 ? ((BtlBattleState *)global)->boss.formations[5] : ((BtlBattleState *)global)->boss.formations[0];
    case 0x105:
        skill = ((BtlAction *)action)->unk_6e;
        if (skill == 0x16B) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        if (skill == 0x16A) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        return skill == 0x16C ? ((BtlBattleState *)global)->boss.formations[4] : ((BtlBattleState *)global)->boss.formations[0];
    case 0x108:
        skill = ((BtlAction *)action)->unk_6e;
        if (skill == 0x17A) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        return skill == 0x17C ? ((BtlBattleState *)global)->boss.formations[4] : ((BtlBattleState *)global)->boss.formations[0];
    case 0x10A:
    case 0x113:
        skill = ((BtlAction *)action)->unk_6e;
        if (skill == 0x17F || skill == 0x186) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        return skill == 0x180 ? ((BtlBattleState *)global)->boss.formations[4] : ((BtlBattleState *)global)->boss.formations[0];
    case 0x10B:
    case 0x10E:
        skill = ((BtlAction *)action)->unk_6e;
        if (skill == 0x181 || skill == 0x18B || skill == 0x182 || skill == 0x185) {
            return ((BtlBattleState *)global)->boss.formations[4];
        }
        return ((BtlBattleState *)global)->boss.formations[0];
    default:
        return ((BtlBattleState *)global)->boss.formations[0];
    }
}

// Report whether an action has a formation slot.
// FUN_0022D540
s32 btlActionHasFormationSlot(u8 *action, u8 *slots) {
    u16 unitId;
    u8 *unit;
    u8 *battle;

    battle = DAT_0076449c;
    if (!( ((BtlBattleState *)battle)->flags & 0x200000)) {
        return 0;
    }
    if (!(((BtlAction *)action)->unk_1a & 1)) {
        return 0;
    }
    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 1) {
        return 0;
    }
    unitId = ((BtlUnit *)unit)->charId;
    switch (unitId) {
    case 0x112:
    case 0x109:
        ((s32 *)slots)[0] = ((BtlBattleState *)battle)->boss.formations[1];
        ((s32 *)slots)[1] = ((BtlBattleState *)DAT_0076449c)->boss.formations[2];
        ((s32 *)slots)[2] = ((BtlBattleState *)DAT_0076449c)->boss.formations[3];
        return 1;
    default:
        return 0;
    }
}

/* Update the unit HP gauge from the packet. The unused source parameter is real, and the counter is
 * updated as unsigned but clamped as signed. */
// FUN_0022D600
void btlUnitUpdateHpGauge(void *source, u8 *packet, s32 *hpDelta)
{
    u8 *unit;
    u8 *resource;
    void *model;
    u32 hp;
    u32 maxHp;
    u32 remaining;
    s32 percentage;
    RwV3d scale;
    RwV3d translation;

    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0)
        return;
    unit = (u8*)((BtlAction *)packet)->unit;
    if (((BtlUnit *)unit)->genus != 1)
        return;
    switch (((BtlUnit *)unit)->charId) {
    case 0x102:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000))
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
        else
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        break;
    case 0x103:
        resource = resrcMngFindResById(((ResrcManager *)iGpffff9db0)->resLists[2], 0x2804);
        if (resource == NULL || ((ResrcRecord *)resource)->slotHandle[1] == NULL)
            break;
        hp = ((DatUnit *)(u8*)((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->datUnit)->hp;
        maxHp = datCalcMaxHp(((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->datUnit);
        scale.x = ((BtlUnit *)((u8 *)((BtlAction *)(packet))->unit))->scale;
        scale.y = ((BtlUnit *)*(u8 * *)&((BtlAction *)(packet))->unit)->scale;
        scale.z = ((BtlUnit *)*(u8 * *)&((BtlAction *)(packet))->unit)->scale;
        translation.x = 0.0f;
        translation.y = 0.0f;
        translation.z = -450.0f;
        if (hp < maxHp) {
            mdlScale(MEMBER(Model *, resource, ResrcRecord, slotHandle[1]), &scale, 0);
            mdlTranslateMatrix(MEMBER(RwMatrix *, resource, ResrcRecord, slotHandle[1]), &translation, 2);
            model = MEMBER(void *, resource, ResrcRecord, slotHandle[1]);
            mdlSetFrameColorByName(model, (s32)D_006355C0, 0xFF);
        }
        if (hp * 100 <= maxHp * 50) {
            mdlScale(MEMBER(Model *, resource, ResrcRecord, slotHandle[1]), &scale, 0);
            mdlTranslateMatrix(MEMBER(RwMatrix *, resource, ResrcRecord, slotHandle[1]), &translation, 2);
            model = MEMBER(void *, resource, ResrcRecord, slotHandle[1]);
            mdlSetFrameColorByName(model, (s32)D_006355E0, 0xFF);
        }
        if (hp * 100 <= maxHp * 75) {
            mdlScale(MEMBER(Model *, resource, ResrcRecord, slotHandle[1]), &scale, 0);
            mdlTranslateMatrix(MEMBER(RwMatrix *, resource, ResrcRecord, slotHandle[1]), &translation, 2);
            model = MEMBER(void *, resource, ResrcRecord, slotHandle[1]);
            mdlSetFrameColorByName(model, (s32)D_00635600, 0xFF);
        }
        break;
    case 0x104:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000))
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
        else
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        break;
    case 0x105:
        if (!datGetFlag(0x15C0)) {
            if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000))
                ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
            else
                ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        } else {
            remaining = datGetScriptValue(0x7A);
            remaining += (u32)*hpDelta;
            if ((s32)remaining <= 0) {
                btlEncounterSetSequence((s32)btlEncounterResetSlots, (s32)btlEncounterWaitIdle, (s32)packet);
                remaining = 0;
            }
            datSetScriptValue(0x7A, remaining);
        }
        break;
    case 0x106:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000) &&
            ((BtlBattleState *)iGpffffb3ac)->bossPhase == 0)
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
        else
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        if (((BtlBattleState *)iGpffffb3ac)->bossPhase == 0 || *hpDelta >= 0)
            break;
        packet = btlUnitFindInSideById(1, 0x10F);
        if (packet == NULL)
            break;
        datCalcAddHp(((BtlUnit *)packet)->datUnit, *hpDelta);
        packet = btlActionFindByUnit((s32)packet);
        /* The paired unit has an active packet; retail deliberately falls through. */
    case 0x10F:
        if (((BtlBattleState *)iGpffffb3ac)->bossPhase == 0)
            break;
        if (((BtlBattleState *)iGpffffb3ac)->bossPhase == 1)
            percentage = 40;
        else if (((BtlBattleState *)iGpffffb3ac)->bossPhase == 2)
            percentage = 60;
        else
            percentage = 100;
        if (btlCond_MYHP(packet, 100 - percentage) ||
            ((DatUnit *)(u8*)((BtlUnit *)(u8*)((BtlAction *)packet)->unit)->datUnit)->hp < 2)
            btlEncounterSetSequence((s32)btlEncounterStartSequence, (s32)btlEncounterFinishStep, (s32)packet);
        break;
    case 0x107:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000))
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
        else
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        break;
    case 0x10B:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000))
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
        else
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        break;
    case 0x112:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100000))
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = 3;
        else
            ((BtlBattleState *)iGpffffb3ac)->pendingBossCue = -1;
        break;
    }
}

// Selects the unit's record table by battle id.
// FUN_0022DB90
void btlUnitSelectRecordTable(u8 *action) {
    u16 id;
    u8 *unit;
    u8 *battle;

    battle = DAT_0076449c;
    if ((((BtlBattleState *)battle)->flags & 0x200000) &&
        (unit = (u8 *)((BtlAction *)action)->unit, ((BtlUnit *)unit)->genus == 1)) {
        id = ((BtlUnit *)unit)->charId;
        switch (id) {
        case 0x102:
            ((BtlBattleState *)battle)->boss.recordTable = D_0062A5F0;
            return;
        case 0x10D:
            ((BtlBattleState *)battle)->boss.recordTable = D_0062AD40;
            return;
        case 0x103:
            ((BtlBattleState *)battle)->boss.recordTable = D_0062B490;
            return;
        case 0x110:
            ((BtlBattleState *)battle)->boss.recordTable = D_0062BBE0;
            return;
        case 0x111:
            ((BtlBattleState *)battle)->boss.recordTable = D_0062C330;
            break;
        }
    }
}

/* Applies packet flags to the unit state. node must be declared before started; swapping them
 * changes which saved registers retail uses. */
// FUN_0022DC70
void btlUnitApplyPacketFlags(u8 *packet)
{
    u8 *node;
    s32 started;
    u8 *unit;
    s32 *counter;

    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
        return;
    unit = (u8*)((BtlAction *)packet)->unit;
    if (((BtlUnit *)unit)->genus != 1) {
        switch (btlCurrentUnitId()) {
        case 0x215:
            if (((BtlAction *)packet)->unk_6c == 2 && ((BtlAction *)packet)->unk_6e == 0x115)
                btlEncounterSetSequence((s32)btlEncounterResetUnit, (s32)btlEncounterFinishResetSequence, (s32)packet);
            break;
        }
        return;
    }
    switch (((BtlUnit *)unit)->charId) {
    case 0x100:
        if (((BtlAction *)packet)->unk_6c == 2) {
            if (((BtlAction *)packet)->unk_6e == 0x160)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 13;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
        }
        break;
    case 0x101:
        if (((BtlAction *)packet)->unk_6c == 2 || ((BtlAction *)packet)->unk_6c == 1) {
            if (((BtlAction *)packet)->unk_6e == 0x161)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[1] = 12;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[1] = -1;
        }
        break;
    case 0x102:
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062A5F0;
        if (((BtlAction *)packet)->unk_6c == 2) {
            if (((BtlAction *)packet)->unk_6e == 0x163)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 12;
            else if (((BtlAction *)packet)->unk_6e == 0x162)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 13;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
        }
        break;
    case 0x10D:
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062AD40;
        break;
    case 0x103:
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062B490;
        if (((BtlAction *)packet)->unk_6c == 2) {
            if (((BtlAction *)packet)->unk_6e == 0x166)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 12;
            else if (((BtlAction *)packet)->unk_6e == 0x167)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 13;
            else if (((BtlAction *)packet)->unk_6e == 0x168)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 14;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
        }
        break;
    case 0x110:
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062BBE0;
        break;
    case 0x111:
        ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062C330;
        break;
    case 0x104:
        if (((BtlAction *)packet)->unk_6c == 2) {
            if (((BtlAction *)packet)->unk_6e == 0x169)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 12;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
        }
        break;
    case 0x105:
        if (((BtlAction *)packet)->unk_6c == 2) {
            switch (((BtlAction *)packet)->unk_6e) {
            case 0x16B:
                ((BtlBattleState *)DAT_0076449c)->bossCuePrefix[0] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[0] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[21] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[15] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[7] = 14;
                ((BtlBattleState *)DAT_0076449c)->pendingBossCue = 15;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 17;
                ((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->unk_9d8 |= 0x20;
                break;
            case 0x16A:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -2;
                break;
            case 0x16C:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -2;
                break;
            default:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
                break;
            }
        }
        break;
    case 0x106:
        if (((BtlAction *)packet)->unk_6c == 2 || ((BtlAction *)packet)->unk_6c == 1) {
            switch (((BtlAction *)packet)->unk_6e) {
            case 0x16E:
            case 0x16F:
            case 0x170:
            case 0x171:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 12;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[1] = -1;
                ((BtlBattleState *)DAT_0076449c)->flags |= 0x400000;
                ((BtlBattleState *)DAT_0076449c)->actionEndFlags |= 2;
                break;
            default:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[1] = -1;
                break;
            }
        }
        break;
    case 0x107:
        if (((BtlAction *)packet)->unk_6c == 2) {
            if (((BtlAction *)packet)->unk_6e == 0x178)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 13;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
        }
        break;
    case 0x108:
        if (((BtlAction *)packet)->unk_6c == 2) {
            switch (((BtlAction *)packet)->unk_6e) {
            case 0x17B:
            case 0x184:
                btlEncounterSetSequence((s32)btlActionRunPresentation, (s32)btlEncounterWaitCleared, (s32)packet);
                MEMBER(u16, packet, BtlAction, unk_6c) = 8;
                btlActionSetState((BtlAction *)packet, 25);
                ((BtlBattleState *)DAT_0076449c)->bossMotionCountdown = 3;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
                break;
            case 0x17A:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -2;
                break;
            case 0x17C:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -2;
                break;
            default:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
                break;
            }
        }
        started = 0;
        counter = (s32 *)(DAT_0076449c + 0xC38);
        if (*counter > 0) {
            *counter -= 1;
            if (((BtlBattleState *)DAT_0076449c)->bossMotionCountdown <= 0) {
                node = ((BtlBattleState *)DAT_0076449c)->actions;
                while (node != NULL) {
                    if ((((BtlAction *)node)->unk_1a & 1) != 0) {
                        unit = (u8*)((BtlAction *)node)->unit;
                        if ((((BtlUnit *)unit)->flags3 & 8) != 0 &&
                            datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)unit)->datUnit, 0x100) == 0)
                            break;
                    }
                    node = (u8*)((BtlAction *)node)->next;
                }
                if (node != NULL) {
                    btlEncounterSetSequence((s32)btlActionRunMotionSequence, (s32)btlEncounterReleaseFlags, (s32)packet);
                    started = 1;
                }
            }
        }
        counter = (s32 *)(DAT_0076449c + 0xC3C);
        if (*counter > 0 && started == 0) {
            *counter -= 1;
            if (((BtlBattleState *)DAT_0076449c)->bossCameraCountdown <= 0 && datGetFlag(0x1435) != 0)
                btlEncounterSetSequence((s32)btlEncounterStartCameraState, (s32)btlEncounterWaitReleaseEvents, (s32)packet);
        }
        break;
    case 0x10A:
    case 0x113:
        if (((BtlAction *)packet)->unk_6c == 2) {
            switch (((BtlAction *)packet)->unk_6e) {
            case 0x17D:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 12;
                break;
            case 0x17E:
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 13;
                break;
            case 0x17F:
            case 0x186:
                ((BtlBattleState *)DAT_0076449c)->bossCuePrefix[0] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[0] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[21] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[15] = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[7] = 14;
                ((BtlBattleState *)DAT_0076449c)->pendingBossCue = 14;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 18;
                ((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->unk_9d8 |= 0x20;
                break;
            case 0x180:
                ((BtlBattleState *)DAT_0076449c)->bossCuePrefix[0] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[0] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[21] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[15] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[7] = -1;
                ((BtlBattleState *)DAT_0076449c)->pendingBossCue = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -2;
                ((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->unk_9d8 &= ~0x20;
                break;
            default:
                if (((BtlBattleState *)DAT_0076449c)->bossCuePrefix[0] == 14)
                    ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 17;
                else
                    ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
                break;
            }
        }
        break;
    case 0x10B:
    case 0x10E:
        if (((BtlAction *)packet)->unk_6c == 2) {
            if (((BtlAction *)packet)->unk_6e == 0x10B) {
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 12;
                ((BtlBattleState *)DAT_0076449c)->flags |= 0x400000;
                ((BtlBattleState *)DAT_0076449c)->actionEndFlags |= 7;
            } else if (((BtlAction *)packet)->unk_6e == 0x185)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 4;
            else if (((BtlAction *)packet)->unk_6e == 0x182)
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = 13;
            else
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[5] = -1;
        }
        break;
    }
}

// Reports whether the action matches the expected skill.
// FUN_0022E4F0
s32 btlActionMatchesSkill(u8 *action, s32 skillId) {
    u16 unitId;
    u8 *unit;
    u8 *battle;

    battle = DAT_0076449c;
    if (!( ((BtlBattleState *)battle)->flags & 0x200000)) {
        return 0;
    }
    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 1) {
        return 0;
    }
    unitId = ((BtlUnit *)unit)->charId;
    switch (unitId) {
    case 0x102:
        if (skillId == 0x163) {
            return 1;
        }
        goto notMatched;
    case 0x100:
        if (skillId == 0x160) {
            return 1;
        }
        goto notMatched;
    case 0x103:
        if (skillId == 0x166) {
            return 1;
        }
        if (skillId == 0x167) {
            return 1;
        }
        goto notMatched;
    case 0x10A:
    case 0x113:
        if (((BtlBattleState *)battle)->bossCuePrefix[0] == 0xE) {
            return 1;
        }
        if (skillId == 0x17E) {
            return 1;
        }
        goto notMatched;
    case 0x108:
        if (skillId == 0x17C) {
            return 1;
        }
        goto notMatched;
    }
notMatched:
    return 0;
}

/* Applies the encounter roster to the unit; enqueue always receives the target, including four
 * unconditional calls for battle 0x215. */
// FUN_0022E630
s32 btlUnitApplyEncounterRoster(u8 *action)
{
    u8 *unit;
    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0) {
        return 0;
    }
    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus != 1) {
        switch (btlCurrentUnitId()) {
        case 0x214:
            datPersonaClearRoster();
            datPersonaAddRosterMember(0xE0);
            datPersonaSelectRosterMemberById(0xE0);
            btlUnitInitChild(unit, 0xE0);
            datAssignEquippedItem(1, 0, 4);
            ((BtlAction *)action)->flags |= 0x40;
            break;
        case 0x215:
            datPersonaClearRoster();
            datPersonaAddRosterMember(0xE1);
            datPersonaSelectRosterMemberById(0xE1);
            btlUnitInitChild(unit, 0xE1);
            datSetUnitHp(1, (s16)datCalcMaxHpById(1));
            datSetUnitSp(1, (s16)datCalcMaxSpById(1));
            datCalcClearBadStatusById(1, -1);
            ((BtlAction *)action)->flags |= 0x40;
            break;
        }
        return 0;
    }
    switch (((BtlUnit *)unit)->charId) {
    case 0x100:
        ((BtlUnit *)unit)->flags3 |= 0x4000;
        break;
    case 0x102:
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        break;
    case 0x104:
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        ((BtlUnit *)unit)->datUnit->flags |= 0x20;
        break;
    case 0x105:
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        break;
    case 0x106:
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        ((BtlUnit *)unit)->datUnit->flags |= 0x20;
        ((BtlAction *)action)->unk_1a |= 0x100;
        btlActionQueuePush(action);
        break;
    case 0x10F:
        ((BtlAction *)action)->unk_1a &= ~8;
        ((BtlAction *)action)->unk_1a |= 0x100;
        ((BtlUnit *)unit)->flags3 &= ~8;
        ((BtlUnit *)unit)->flags3 |= 0x2000;
        ((BtlUnit *)unit)->datUnit->flags |= 0x20;
        ((BtlUnit *)unit)->unk_9d8 |= 0x20;
        btlActionQueuePush(action);
        break;
    case 0x107:
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        break;
    case 0x109:
        ((BtlAction *)action)->unk_1a |= 0x200;
        ((BtlAction *)action)->unk_1a |= 0x10;
        btlUnitInitChild(unit, 0xCE);
        break;
    case 0x10A:
        ((BtlAction *)action)->unk_1a |= 0x100;
        btlActionQueuePush(action);
        break;
    case 0x10B:
        ((BtlUnit *)unit)->datUnit->flags |= 0x20;
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        break;
    case 0x10E:
        ((BtlUnit *)unit)->flags3 |= 0x2000;
        ((BtlUnit *)unit)->flags3 &= ~0x8000;
        if (btlCurrentUnitId() != 0x215) {
            ((BtlUnit *)unit)->datUnit->flags |= 0x20;
            ((BtlAction *)action)->unk_1a |= 0x100;
            btlActionQueuePush(action);
        } else {
            datSetFlag(0x15C0, 1);
            ((BtlAction *)action)->unk_1a |= 0x2000;
            btlActionQueuePush(action);
            btlActionQueuePush(action);
            btlActionQueuePush(action);
            btlActionQueuePush(action);
        }
        break;
    case 0x112:
        ((BtlUnit *)unit)->flags3 |= 0x8000;
        ((BtlAction *)action)->unk_1a |= 0x10;
        btlUnitInitChild(unit, 7);
        break;
    case 0x113:
        ((BtlUnit *)unit)->datUnit->flags |= 0x20;
        break;
    }
    return 1;
}

// Realigns enemy cells for battle 0x202.
// FUN_0022EAD0
s32 btlUnitRealignCells(void) {
    struct {
        s32 xBits;
        s32 yBits;
        f32 z;
    } position;
    u8 *unit;

    if (!( ((BtlBattleState *)DAT_0076449c)->flags & 0x200000)) {
        return 0;
    }
    switch (btlCurrentUnitId()) {
    case 0x202:
        unit = ((BtlBattleState *)DAT_0076449c)->unitLists[2];
        goto loop_check;
loop_body:
        if (((BtlUnit *)unit)->charId == 0x10D) {
            position.xBits = 0x439B0000;
            position.yBits = 0;
            position.z = fGpffff834c;
            btlTargetPositionToCell((s16 *)&((BtlUnit *)unit)->unk_94, (s16 *)&((BtlUnit *)unit)->unk_96,
                          (f32 *)&position.xBits);
            btlUnitSetPos(unit, &position.xBits);
        }
        unit = (u8 *)((BtlUnit *)unit)->nextUnit;
loop_check:
        if (unit != NULL) {
            goto loop_body;
        }
        break;
    default:
        break;
    }
    return 1;
}

/* Applies packet effects to the unit selected by battle id. */
// FUN_0022EBA0
s32 btlUnitApplyPacketEffects(u8 *packet)
{
    u8 *unit;
    u8 *other;
    u8 *target;
    u8 *node;
    void *model;
    u32 index;
    RtQuat rotation;

    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0)
        return 1;
    unit = (u8*)((BtlAction *)packet)->unit;
    if (((BtlUnit *)unit)->genus != 1)
        return 1;
    switch (((BtlUnit *)unit)->charId) {
    case 0x105:
        if (((BtlAction *)packet)->unk_6c == 2) {
            switch (((BtlAction *)packet)->unk_6e) {
            case 0x16A:
                ((BtlBattleState *)DAT_0076449c)->bossCuePrefix[0] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[0] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[21] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[15] = -1;
                ((BtlBattleState *)DAT_0076449c)->bossCueTail[7] = -1;
                ((BtlBattleState *)DAT_0076449c)->pendingBossCue = -1;
                break;
            }
        }
        if (((BtlBattleState *)DAT_0076449c)->bossCuePrefix[0] == 0xE)
            ((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->unk_9d8 |= 0x20;
        else
            ((BtlUnit *)MEMBER(u8 *, packet, BtlAction, unit))->unk_9d8 &= ~0x20;
        break;
    case 0x106:
        if (((BtlAction *)packet)->unk_6c != 2)
            break;
        other = btlUnitFindInSideById(1, 0x10F);
        if (other == 0 || ((BtlUnit *)other)->layerHandle == 0)
            break;
        switch (((BtlAction *)packet)->unk_6e) {
        case 0x16E:
            model = (void*)((BtlUnit *)other)->layerHandle;
            mdlSetFrameColorByName(model, (s32)D_007636C0, 0);
            model = MEMBER(void *, other, BtlUnit, layerHandle);
            mdlSetFrameColorByName(model, (s32)D_007636C8, 0);
            model = MEMBER(void *, other, BtlUnit, layerHandle);
            mdlSetFrameColorByName(model, (s32)D_007636D0, 255);
            ((BtlBattleState *)DAT_0076449c)->bossPhase = 1;
            ((DatUnit *)((BtlUnit *)unit)->datUnit)->flags |= 0x20;
            target = btlActionFindByUnit((s32)other);
            ((BtlAction *)target)->unk_1a &= ~0x400;
            datCalcAddHp(((BtlUnit *)other)->datUnit, 0xFFFFFFF);
            btlUnitSetMotion(other, 0, 0, 1.0f, 1);
            btlUnitShowModel(other);
            break;
        case 0x16F:
            model = (void*)((BtlUnit *)other)->layerHandle;
            mdlSetFrameColorByName(model, (s32)D_007636C0, 0);
            model = MEMBER(void *, other, BtlUnit, layerHandle);
            mdlSetFrameColorByName(model, (s32)D_007636C8, 255);
            model = MEMBER(void *, other, BtlUnit, layerHandle);
            mdlSetFrameColorByName(model, (s32)D_007636D0, 255);
            ((BtlBattleState *)DAT_0076449c)->bossPhase = 2;
            ((DatUnit *)((BtlUnit *)unit)->datUnit)->flags |= 0x20;
            target = btlActionFindByUnit((s32)other);
            ((BtlAction *)target)->unk_1a &= ~0x400;
            datCalcAddHp(((BtlUnit *)other)->datUnit, 0xFFFFFFF);
            btlUnitSetMotion(other, 0, 0, 1.0f, 1);
            btlUnitShowModel(other);
            break;
        case 0x170:
            model = (void*)((BtlUnit *)other)->layerHandle;
            mdlSetFrameColorByName(model, (s32)D_007636C0, 255);
            model = MEMBER(void *, other, BtlUnit, layerHandle);
            mdlSetFrameColorByName(model, (s32)D_007636C8, 255);
            model = MEMBER(void *, other, BtlUnit, layerHandle);
            mdlSetFrameColorByName(model, (s32)D_007636D0, 255);
            /* fall through */
        case 0x171:
            ((BtlBattleState *)DAT_0076449c)->bossPhase = 3;
            ((DatUnit *)((BtlUnit *)unit)->datUnit)->flags |= 0x20;
            datCalcAddHp(((BtlUnit *)other)->datUnit, 0xFFFFFFF);
            btlUnitUpdateStatusMotion(other, 0);
            btlUnitSetMotion(other, 0, 0, 1.0f, 1);
            ((BtlBattleState *)DAT_0076449c)->boss.recordTable = D_0062E070;
            target = btlActionFindByUnit((s32)other);
            ((BtlAction *)packet)->unk_1a &= ~8;
            ((BtlUnit *)unit)->flags3 &= ~8;
            ((BtlAction *)target)->unk_1a |= 8;
            ((BtlAction *)target)->unk_1a &= ~0x400;
            ((BtlUnit *)other)->flags3 |= 8;
            if (MEMBER(u16, packet, BtlAction, unk_6e) == 0x171) {
                MEMBER(u32, other, BtlUnit, flags3) &= ~0x2000;
                func_003dc740(&rotation, (const RwV3d *)D_0060A0E0, 180.0f, 0);
                btlUnitSetRot((BtlUnit *)other, &rotation);
                MEMBER(u32, other, BtlUnit, flags3) |= 0x2000;
                btlUnitShowModel(other);
            }
            break;
        }
        break;
    case 0x108:
        if (((BtlAction *)packet)->unk_6c != 2 || ((BtlAction *)packet)->unk_6e != 0x17A)
            break;
        if (datGetFlag(0x15C0) != 0) {
            datSetFlag(0x15C5, 1);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C1) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 1);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C2) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 1);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C3) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 1);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x15C4) != 0) {
            datSetFlag(0x15C5, 0);
            datSetFlag(0x15C6, 0);
            datSetFlag(0x15C7, 0);
            datSetFlag(0x15C8, 0);
            datSetFlag(0x15C5 + datCalcRandomBelow(4), 1);
            datSetFlag(0x1435, 1);
        }
        if (datGetFlag(0x1435) != 0)
            ((BtlBattleState *)DAT_0076449c)->bossCameraCountdown = 3;
        break;
    case 0x10A:
    case 0x113:
        if (((BtlAction *)packet)->unk_6e != 0x180)
            break;
        node = ((BtlBattleState *)DAT_0076449c)->actions;
        while (node != 0) {
            if ((((BtlAction *)node)->unk_1a & 1) != 0) {
                unit = (u8*)((BtlAction *)node)->unit;
                if ((((BtlUnit *)unit)->flags3 & 8) != 0 && (u8*)((BtlUnit *)unit)->datUnit != 0)
                    datCalcClearBuffLevel((u8*)((BtlUnit *)unit)->datUnit, 0x14);
            }
            node = (u8*)((BtlAction *)node)->next;
        }
        break;
    case 0x10E:
        if (((BtlAction *)packet)->unk_6e != 0x181)
            break;
        ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x20000000;
        target = ((BtlAction *)packet)->parameters.followUp;
        if (target != 0) {
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->flags3 &= ~8;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->cols[4] = iGpffffb45c;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->unk44 = iGpffffb45c;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->unk48 = iGpffffb45c;
            btlUnitSetColor((BtlUnit *)(u8*)((BtlAction *)target)->unit, iGpffffb45c);
            datCalcClearBadStatus((s32)(u8 *)((BtlUnit *)MEMBER(u8 *, target, BtlAction, unit))->datUnit, 0xFFF7FFFF);
            unit = MEMBER(u8 *, target, BtlAction, unit);
            if ((((BtlUnit *)unit)->flags2 & 2) != 0)
                ((BtlUnit *)unit)->unk_9d8 |= 0x10;
        } else {
            index = 0;
            goto targets_check;
targets_body:
            target = ((BtlAction *)packet)->targets[index];
            if (((BtlBattleState *)DAT_0076449c)->selectedAction == target)
                ((BtlBattleState *)DAT_0076449c)->battleFlags |= 0x10000000;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->flags3 &= ~8;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->cols[4] = iGpffffb45c;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->unk44 = iGpffffb45c;
            ((BtlUnit *)(u8*)((BtlAction *)target)->unit)->unk48 = iGpffffb45c;
            btlUnitSetColor((BtlUnit *)(u8*)((BtlAction *)target)->unit, iGpffffb45c);
            datCalcClearBadStatus((s32)(u8 *)((BtlUnit *)MEMBER(u8 *, target, BtlAction, unit))->datUnit, 0xFFF7FFFF);
            unit = MEMBER(u8 *, target, BtlAction, unit);
            if ((((BtlUnit *)unit)->flags2 & 2) != 0)
                ((BtlUnit *)unit)->unk_9d8 |= 0x10;
            index++;
targets_check:
            if (index < ((BtlAction *)packet)->unk_6a)
                goto targets_body;
        }
        break;
    }
    return 1;
}

// React to the death of unit 0x102 with an animation.
// FUN_0022F520
s32 btlUnitReactToDeath(void)
{
    struct {
        s64 a;
        s64 b;
        s64 c;
    } result;
    s32 encounterId;
    u8 *firstBoss;
    u8 *secondBoss;
    if ((((BtlBattleState *)DAT_0076449c)->flags & 0x200000) == 0) {
        return 0;
    }
    encounterId = btlCurrentUnitId();
    switch (encounterId) {
    case 0x202: {
        u8 *firstAction;
        u8 *firstUnit;
        firstBoss = btlUnitFindInSideById(1, 0x102);
        if ((firstBoss == NULL) ||
            (datCalcIsDead((s32 *)((BtlUnit *)firstBoss)->datUnit, 0) != 0)) {
            btlTargetClearResultBuffer((u8 *)&result);
            *(s32 *)&result = 0xFFF00001;
            firstAction = ((BtlBattleState *)DAT_0076449c)->actions;
            goto firstActionCheck;
firstActionBody:
            if ((((BtlAction *)firstAction)->unk_1a & 1) != 0) {
                firstUnit = (u8 *)((BtlAction *)firstAction)->unit;
                if ((((BtlUnit *)firstUnit)->genus == 1) &&
                    (((BtlUnit *)firstUnit)->charId != 0x102) &&
                    (datCalcIsDead((s32 *)((BtlUnit *)firstUnit)->datUnit, 0) == 0)) {
                    btlPacketEnqueue(
                        (u8 *)btlTargetCreateDataPacket((s32)(u32)firstAction, (s32)(u32)firstAction,
                                            (void *)&result, 1, 1),
                        1);
                    btlPacketEnqueue(
                        btlUnitCreateAnimPacket(firstUnit, 2, 0, 0, 1.0f),
                        1);
                }
            }
            firstAction = (u8 *)((BtlAction *)firstAction)->next;
firstActionCheck:
            if (firstAction != NULL) {
                goto firstActionBody;
            }
            return 1;
        }
        goto notTriggered;
    }
    case 0x203: {
        u8 *secondUnit;
        u8 *secondAction;
        secondBoss = btlUnitFindInSideById(1, 0x103);
        if ((secondBoss == NULL) ||
            (datCalcIsDead((s32 *)((BtlUnit *)secondBoss)->datUnit, 0) != 0)) {
            btlTargetClearResultBuffer((u8 *)&result);
            *(s32 *)&result = 0xFFF00001;
            secondAction = ((BtlBattleState *)DAT_0076449c)->actions;
            goto secondActionCheck;
secondActionBody:
            if ((((BtlAction *)secondAction)->unk_1a & 1) != 0) {
                secondUnit = (u8 *)((BtlAction *)secondAction)->unit;
                if ((((BtlUnit *)secondUnit)->genus == 1) &&
                    (((BtlUnit *)secondUnit)->charId != 0x103) &&
                    (datCalcIsDead((s32 *)((BtlUnit *)secondUnit)->datUnit, 0) == 0)) {
                    btlPacketEnqueue(
                        (u8 *)btlTargetCreateDataPacket((s32)(u32)secondAction, (s32)(u32)secondAction,
                                            (void *)&result, 1, 1),
                        1);
                    btlPacketEnqueue(
                        btlUnitCreateAnimPacket(secondUnit, 2, 0, 0, 1.0f),
                        1);
                }
            }
            secondAction = (u8 *)((BtlAction *)secondAction)->next;
secondActionCheck:
            if (secondAction != NULL) {
                goto secondActionBody;
            }
            return 1;
        }
        goto notTriggered;
    }
    default:
        goto notTriggered;
    }
notTriggered:
    return 0;
}

// Return the entry position for a unit.
// FUN_0022F7D0
s32 btlUnitGetEntryPosition(u8 *unit, u8 *position) {
    s32 encounterId;
    u8 *activeAction;
    u8 *unitData;

    encounterId = btlCurrentUnitId();
    switch (encounterId) {
    case 0x208:
        activeAction = (u8 *)btlActionGetActiveOrQueueFront();
        if (activeAction != NULL) {
            unitData = (u8 *)((BtlUnit *)(u8 *)((BtlAction *)activeAction)->unit)->datUnit;
            if ((unitData != NULL) && (datCalcChkBadStatus((s32)unitData, 0x100) == 0)) {
                return 0;
            }
        }
        btlUnitGetGridSphereCenter(((BtlAction *)((BtlBattleState *)DAT_0076449c)->selectedAction)->unit,
                      (RwV3d *)position);
        return 1;
    case 0x10E:
        ((BtlCameraPosition *)position)->x = 0;
        ((BtlCameraPosition *)position)->y = 0;
        ((BtlCameraPosition *)position)->z = (f32)0xBB8;
        return 1;
    default:
        return 0;
    }
}

/* Identify skill 0x169 for enabled enemy unit 0x104 during boss encounters; all other cases return zero. */
// FUN_0022F8B0
s32 btlBossSkillRestoresMotionBeforeHits(u8 *action, s32 skillId)
{
    u8 *unit;

    if (((BtlBattleState *)DAT_0076449c)->flags & 0x200000) {
        goto check_flag;
    }
    return 0;
check_flag:
    if (((BtlAction *)action)->unk_1a & 1) {
        goto loadUnit;
    }
    return 0;
loadUnit:
    unit = (u8 *)((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus == 1) {
        goto check_id;
    }
    return 0;
check_id:
    switch (((BtlUnit *)unit)->charId) {
    case 0x104:
        if (skillId != 0x169) {
            goto fail;
        }
        goto done;
    default:
        goto fail;
    }
done:
    return 1;
fail:
    return 0;
}

/* Return nonzero if a boss-battle targeting rule prevents the action from targeting the subordinate
 * unit. */
// FUN_0022F950
/* Report whether the unit's skill is blocked. */
s32 btlUnitSkillBlocked(u8 *action, u8 *subordinate) {
    s32 paired;
    s16 skill;
    u8 *unit;

    if ((s32)((BtlBattleState *)DAT_0076449c)->flags & 0x200000) {
        if (((BtlBossTargetRule *)(iGpffffb3e0 +
                    (((BtlUnit *)subordinate)->charId * 0x58)))->flags & 1) {
            paired = btlActionHasNoTargetClass((u32)action);
            skill = (s16)((BtlAction *)action)->unk_6e;
            unit = subordinate;
            return (btlTargetCanSelectEntry(unit, skill, paired) != 0) ^ 1;
        }
        if ((btlActionHasNoTargetClass((u32)action) == 0) &&
            (((BtlBossTargetRule *)(iGpffffb3e0 +
                     (MEMBER(u16, subordinate, BtlUnit, charId) * 0x58)))->flags & 0x20)) {
            return 1;
        }
        if (btlBossSkillResultBlocked(action) == 1) {
            return 1;
        }
        if (btlBossTargetBlocked(action) == 0) {
            return 1;
        }
    }
    return 0;
}

// Report whether the slot is open for the unit.
// FUN_0022FA90
s32 btlUnitSlotIsOpen(u8 *action, s16 slotIndex)
{
    u8 *battle;

    battle = DAT_0076449c;
    if (!( ((BtlBattleState *)battle)->flags & 0x200000)) {
        return 1;
    }
    if (!(((BtlAction *)action)->unk_1a & 1)) {
        return 1;
    }
    if (((BtlUnit *)(u8 *)((BtlAction *)action)->unit)->genus != 1) {
        return 1;
    }
    return *(s8 *)&((BtlBattleState *)((u32)(s32)slotIndex + (u32)battle))->bossCuePrefix[0] != -2;
}

// Report whether the encounter skips the presentation.
// FUN_0022FB10
s32 btlEncounterSkipsPresentation(void)
{
    s32 encounterId;

    if (!(((BtlBattleState *)DAT_0076449c)->flags & 0x200000)) {
        return 1;
    }
    encounterId = btlCurrentUnitId();
    switch (encounterId) {
    case 0x209:
    case 0x20C:
    case 0x20D:
        return 1;
    default:
        return 0;
    }
}


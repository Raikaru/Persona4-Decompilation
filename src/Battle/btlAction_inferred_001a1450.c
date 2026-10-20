#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
#include "datPersona_internal.h"
#include "datUnit_internal.h"
#include "btl_effect_internal.h"
#include "dat_skill_entry_internal.h"
#include "btl_skill_internal.h"

/* Enemy battle-table rows have a proven 0xE8 stride. The two movement
 * variants interleave their speed selector with an unknown halfword. */
typedef struct BtlEnemyMovement {
    u16 speedIndex;
    u16 unk02;
} BtlEnemyMovement;
typedef struct BtlEnemyBattleParameters {
    u8 pad00[0x18];
    s16 flags;                  /* 0x18 */
    u8 pad1A[8];
    s16 cameraMode;             /* 0x22 */
    BtlEnemyMovement movement[2]; /* 0x24 */
    u8 pad2C[0xE8 - 0x2C];
} BtlEnemyBattleParameters;
typedef char BtlEnemyBattleParametersSizeCheck[
    sizeof(BtlEnemyBattleParameters) == 0xE8 ? 1 : -1];
/* Signed view of the BtlPacket scheduling header used by the action packet chains:
 * same offsets as BtlPacket's dependencyKind/dependencyUID/uid/actionUID; a packet
 * with dependencyKind 4 waits for the packet whose uid is dependencyUid. */
typedef struct BtlPacketTiming {
    s8 dependencyKind;  /* 0x00: 4 waits for dependencyUid */
    u8 pad01[7];
    s64 dependencyUid;  /* 0x08 */
    u8 pad10[0x37];
    u8 flags;           /* 0x47 */
    s16 delay;          /* 0x48 */
    s16 duration;       /* 0x4A */
    u8 pad4C[0xC];
    s64 uid;            /* 0x58 */
    s64 actionUid;      /* 0x60 */
} BtlPacketTiming;
typedef struct BtlPacket BtlPacket;
extern BtlPacket *btlFormationCreateNamedPacket(u32 resource, const char *path, u16 mode);
u32 datCalcRandomBelow(u32 limit);
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument, u32 extraArgument, u32 flags);
static inline u8 *btlActionCreateTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)btlTargetCreateTargetPacket((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void btlActionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *btlActionCreateRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
static inline u8 *btlActionCreateRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)btlUnitCreateMotionSettlePacket(unit);
}
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
static inline void *btlActionCreateMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 callbackIndex, s32 argument, s32 extraArgument, s32 flags);
extern void btlUnitGetAnchorPose(u8 *, u8 *, f32 *, f32 *);
extern f32 btlTargetVectorDistance(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[]; /* movement speed table */

void btlActionSetState(BtlAction *action, u16 state);
u8 *btlUnitRecordFindByActionUID(u64 uid, u64 mask);
static inline s32 btlActionAddAddressOffset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 btlActionNormalizeUnitIndex(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}
void btlSoundBumpStatusCounters(void);

void btlTargetResolveSelectedSkill(u8 *context);
void btlTargetResetCommandRecord(u8 *record);
extern void btlEffectCollectTargetUnits(u8 *action, u8 *selection, u32 sideFlags, u32 filterFlags, u32 statusMask);
void btlEffectSelectNearestEntry(void *action, void *targets);

s32 btlUnitIsMoving(u8 *unit);

void btlActionFinishPresentation(BtlAction *action);
void btlAICommandPickAiTarget(void *action, s32 value);
BtlPacket *btlFormationCreateSlotPacket(u16 groupMask, u16 flags);
s64 btlPacketEnqueue(u8 *context, u32 value);

extern u8 *D_0076449C; /* active battle state */
extern u8 *iGpffffb3ac;
extern void btlAiSelectStatusCommand(u8 *action, u8 *command, u32 status);
extern s32 btlSoundSelectCureableStatuses(u8 *action);
extern s32 btlSoundIsStatusCounterHigh(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceA(u8 *action);
extern s32 btlSoundPickStatusTalkVoiceB(u8 *action);
extern void btlSoundCancelPlayback(void);
extern s32 btlSoundPickResistVoice(u8 *unit);
extern void btlSoundStopBank3(void);
extern void btlVoicePlayIdCue(s32 context, s32 value);
extern void btlVoiceFadeOut(void);
extern void btlEncounterEntryClearMessageFade(s32 task);
extern void btlEncounterEntrySetMessageFade(s32 task);
extern void btlMessageSetup(u8 *task, u8 *action);
extern s32 btlMessageIsIdle(s32 task);
extern void btlMessageSetPendingValue(u8 *task, s32 value);
extern void btlMessageSetDone(s32 task);
extern void btlMessageSetHidden(s32 task);
extern u8 *btlUnitCreateColorPacket(u8 *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
extern u8 *btlUnitCreateShowPacket(u8 *unit);
extern u8 *btlUnitCreateHidePacket(u8 *unit);
extern u16 btlSelectionGetTargetMark(s32 task);
extern u32 btlEffectCollectGenusMask(s32 selection);
extern void btlSelectionResetUnitFlags(s32 task);
extern u32 btlSelectionGetFormationEntryAlt(s32 task);
extern u32 btlSelectionGetFormationEntry(s32 task);
extern s32 btlActionBuffCondition(u8 *action, s32 skillId, s32 targetMode);
extern void btlSelectionClearTargetMark(s32 task);
extern void btlPanelOnTargetAction(s32 unusedTask, s32 unusedAction);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
u32 btlEffectHasAiProcedure(void *object);
void btlAICommandSetUnitAction();
u32 btlAICommandTryReleaseProc();
s32 datCalcDefaultSkillId(u8 *unit);
u32 btlFormationCurrentEntry(void *formation);
void btlFormationEntrySetSelected(s32 selection, u64 *key);

extern u8 *iGpffffb3b8;
void btlEffectSelectTargetByStatus(u8 *action, u8 *selection);
void btlSelectionMarkTargets(s32 task, u8 *action, u8 *targets, s16 skill);
extern void btlDamageSetActive(s32 task);
void btlUnitRequestLookAtOthers(u8 *excludedAction);
u8 datCalcGetCharacterTableKind(u8 *unit);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
static inline u8 *btlActionCreateLookAtUnitPacketBytes(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
u8 *btlUnitCreateMotionRequestPacket(u8 *unit, u16 value);
extern void btlTargetResetRecordCounter(u8 *record);
extern BtlPacket *btlUnitCreateMoveToUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, f32 param, f32 speed, u32 flags);
extern BtlPacket *btlFormationCreateWaitPacket(u32 actor, u32 target, u16 mode);
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32 unit);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
extern void btlTargetClearResultBuffer(u8 *result);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *unit);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
u8 *btlPacketCreateImmediate(void);
extern BtlPacket *btlFormationCreateReturnPacket(u16 flags);
BtlPacket *btlMainCreateColorSetPacket(s32 arg);
BtlPacket *btlEffectCreateReleasePacket(u16 mode);
u8 *btlPacketCreateFinishEffect(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
extern s32 datCalcGetElementAffinity(u8 *unit, s32 elementIndex);
u8 *btlSoundLoadPacketNew(const void *request);
s32 btlTargetCanControlDamagePhase(void);
extern void btlMessageInstallWindow(s32 task, u8 *window);
u8 *btlSoundLoadTaskStart(void);
extern s32 btlMessageIsActiveAlt2(s32 task);
extern s32 btlMessageGetResultAlt2(s32 task);
u8 *btlSoundReleaseTaskStart(void);
extern void btlMessageRelease(s32 task);
extern void btlDamageSetSource(u8 *task, s32 source);
s32 btlActionCanFollowUpAfterEnemiesDown(u8 *action);
s64 *btlActionGetQueueFront(void);
s32 btlEffectFindUnitMatchingCallback(u8 *context, s32 value, s32 mode, s32 flags, s32 options,
                  s32 (*predicate)(u8 *context, s64 value));
s32 btlTargetGetStatusEffectMsgCode(u8 *action, u8 *target);
s32 datCalcSkillElement(u8 *unit, u16 skillId);
u8 *btlSoundStopTaskStart(void);
s32 btlAICommandNomalStatusCheck(u8 *action, s64 value);
u32 btlCountUnitRecordsById(u32 id);
u8 *btlCutinCreatePacket(u8 *request);
extern void btlMessageStartLong(u8 *task, u8 *action);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *unit, u8 *targetUnit, s32 flags);
u8 *btlPacketAllocZeroed(s32 callback, s32 data);
u8 *btlEffectCreateFormationPacket(s32 formation, s32 unit, s32 duration, s64 key, s32 flags);
extern s32 btlMessageIsActiveAlt(s32 task);
extern s32 btlMessageGetResultAlt(s32 task);
u8 *func_001f99c0(u8 *context, u16 value, s32 mode, s32 flags, s32 options);
u8 *btlCutinCreateEndPacket(void);
u8 *btlCutinCreateStartPacket(void);
u8 *btlFormationCreateDefaultPacket(void);
extern void btlMessageResetAlt(s32 task);
s16 btlCameraSelectFormationIndex(void);
s32 btlSideCountNotBad(s32 sideMask, s32 excludedStatus);
u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
s64 datCalcFindStrongBuff(u8 *unit);
s32 btlSoundRollStatusCure(u8 *action);
s32 btlActionGetCounter420(BtlAction *action);

u8 *btlPacketCreateSpriteTable(u32 sprite, u16 frame);
extern void btlUnitInitChild(u8 *unit, u16 characterId);
extern s32 datGetFlag(s32 bit);
BtlPacket *btlFormationCreatePacket(u32 formation, u32 sourceUnit, u32 targetUnit, u16 side, u32 flags);
BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
extern f32 D_0076144C; /* anchor-return speed multiplier */

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a1450-001adb80 */

extern s32 btlActionAnyTargetDownOrHitFlagged(u8 *action);
extern void btlActionGetEffectIndices(BtlAction *action, u16 skillId, u8 *effectIndices);
extern void btlActionFinishPresentation(BtlAction *action);
extern s32 btlActionLinkedUnitIsActive(BtlAction *action);
/* Preserve offset-first target copies; canonical action-field rewrites changed TargetUpdate's allocation. */
static inline void btlActionCopySelectedTarget(u8 *action, const u16 *index)
{
    ((BtlAction *)action)->targets[*index] = ((BtlAction *)action)->parameters.candidates[*index];
}
static inline u8 *btlActionGetSelectionAddress(u32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline u32 btlActionGetFormationResource(
    const BtlBattleState *snappedBase, s32 signedSlot)
{
    return (u32)snappedBase->formations[signedSlot];
}
/* Candidate slots are action+0x98+i*4; byte origin preserves PursuitUpdate's measured narrow-index reads. */
static inline u8 *btlActionGetCandidate(u8 *action, const u16 *index)
{
    return ((BtlAction *)action)->parameters.candidates[*index];
}
/* Readiness uses battle opening side (+0x1A) and a flag word (+0x290) absent from BtlBattleState. */
static inline u8 *btlActionGetIndexedHitResult(u8 *action, const u16 *index)
{
    return action + (u32)*index * 0x20 + 0xF0;
}
/* Only the field origin is available: retain the signed halfword in the enemy table's proven 0xE8 stride. */
static inline s16 btlActionGetStridedCameraField(u16 unitId, s16 *firstField)
{
    return *(s16 *)((u8 *)firstField + (u16)unitId * 0xE8);
}
static inline s32 btlActionUsesCloseCamera(u8 *unit, s32 noPartner)
{
    extern u8 *iGpffffb3cc;
    /* The separate four-byte skill-flag table has no shared record declaration. */
    /* Raw BtlUnit/DatUnit fields retain AttackUpdate's measured inlined lifetimes. */
    u8 *ctx = (u8*)((BtlUnit *)unit)->datUnit;
    u16 unitId = ((DatUnit *)ctx)->id;
    s32 result;

    switch (((BtlUnit *)unit)->genus) {
    case 0:
        {
            s32 state = datCalcGetCharacterTableKind(ctx) & 0xFF;

            if (state == 5) {
                result = 1;
                break;
            }
            if (state != 3) {
                goto fail;
            }
            if (!(((BtlSkillFlags *)iGpffffb3bc)->flags & 0x8000) && noPartner != 0) {
                goto fail;
            }
            result = 1;
        }
        break;
    case 1:
        if (btlActionGetStridedCameraField(unitId, (s16 *)(iGpffffb3cc + 0x22)) == 1) {
            result = 1;
        } else {
            goto fail;
        }
        break;
    default:
    fail:
        result = 0;
        break;
    }
    return result;
}
static inline s64 btlActionGetPacketUid(u8 *packet)
{
    /* Typed BtlPacket.uid changed AttackUpdate's cross-call address lifetime. */
    return *(s64 *)(packet + 0x58);
}
static inline u8 btlActionGetUnitGenus(u8 *unit)
{
    /* Byte-origin access avoids changing AttackUpdate's retained field addresses. */
    return unit[0xA2];
}
static inline s32 btlActionAddEffectDelay(s32 frames)
{
    s32 delay;
    delay = frames + 6;
    return delay;
}
static inline u8 *btlActionGetIndexedHitBase(u8 *action, const u16 *index)
{
    return action + (*index << 5);
}
static inline s32 btlActionGetFormationAddress(BtlBattleState *table, u16 index)
{
    return (s32)table->formations[index];
}
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
#pragma push
#pragma pop
/* measured: opt_propagation off plus one named local per address term. mwcc
   keeps source operand order for `named + named` (addu off,base / addu idx,sum
   as retail) but commutes an inline product on the left (`a * k + b` emits
   addu b,a*k); the table base must be copied first so its lw leads the block. */
/* measured: restore propagation for the rest of the unit. */
// FUN_001A1450
/* Prepare command presentation, orient the unit lists, and initialize the command-panel wait state. */
/* Raw offsets preserve the measured offset-first helper expressions and the unsigned delay halfword absent from BtlAction. */
void btlActionCommandInit(s64 *action)
{
    RwV3d sourceRotation;
    RwV3d destination;
    u16 actionType;
    u16 actionTypeAfter;
    u8 *rotatePacket;
    u8 *rotatePacketB;
    u8 *ambientPacket;
    u8 *targetPacket;
    u8 *lookAtPacket;
    u8 *lookAtDeactivatePacket;
    u8 *cameraPacket;
    u8 *listUnit;
    u8 *listUnit2;

    extern void btlUnitGetGridSphereCenter(u8 *unit, f32 *dst);
    extern s32 btlUnitIsMoving(u8 *unit);

    extern void btlPacketEnqueue(u8 *context, s32 value);
    extern void btlPanelInit(s32 unused, u8 *actionAddress);
    extern void btlEncounterEntrySetEmphasis(s32 task);

    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x1000) &&
        (((BtlAction *)action)->unk_1a & 1) &&
        ((BtlAction *)action)->unit->genus == 0) {
        btlActionSetState((BtlAction *)action, 9);
        return;
    }
    btlActionFinishPresentation((BtlAction *)action);
    actionType = ((BtlAction *)action)->oldState;
    if ((actionType != 0x25) && (actionType != 4) && (actionType != 6) &&
        (actionType != 5) && (((BtlBattleState *)iGpffffb3ac)->camera.state != 2)) {
        btlUnitGetAnchorPose(
            (u8 *)((BtlAction *)action)->unit, NULL, 0, (f32 *)&sourceRotation);
        listUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[1];
        goto loop_14_test;
loop_14_body:
        if (datCalcChkBadStatus((s32)(u8 *)((BtlUnit *)listUnit)->datUnit, 0x100) != 0) {
            btlUnitGetGridSphereCenter(
                (u8*)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit,
                (f32 *)&destination);
        } else {
            destination = sourceRotation;
        }
        rotatePacket = btlActionCreateRotatePacketBytes(listUnit, &destination, 2);
        ((BtlPacket *)rotatePacket)->actionUID = *action;
        btlPacketEnqueue(rotatePacket, 0);
        listUnit = (u8 *)((BtlUnit *)listUnit)->prevUnit;
loop_14_test:
        if (listUnit != NULL) {
            goto loop_14_body;
        }
        listUnit2 = ((BtlBattleState *)iGpffffb3ac)->unitLists[3];
        goto loop_19_test;
loop_19_body:
        if (btlUnitIsMoving(listUnit2) == 0) {
            btlUnitGetAnchorPose(listUnit2, NULL, 0, (f32 *)&sourceRotation);
            rotatePacketB = btlActionCreateRotatePacketBytes(listUnit2, &sourceRotation, 2);
            ((BtlPacket *)rotatePacketB)->actionUID = *action;
            btlPacketEnqueue(rotatePacketB, 0);
        }
        listUnit2 = (u8 *)((BtlUnit *)listUnit2)->prevUnit;
loop_19_test:
        if (listUnit2 != NULL) {
            goto loop_19_body;
        }
        ambientPacket = (u8 *)btlFormationCreateSlotPacket(3, 0x8001);
        ((BtlPacket *)ambientPacket)->actionUID = *action;
        btlPacketEnqueue(ambientPacket, 0);
        if (((BtlAction *)action)->unk_28 == 0) {
            targetPacket = btlActionCreateTargetPacketBytes((u8 *)action, 0x1D, 0, 0, 0);
            ((BtlPacket *)targetPacket)->actionUID = *action;
            btlPacketEnqueue(targetPacket, 1);
        }
    }
    {
        u8 *battleUnit;

        battleUnit = (u8 *)((BtlAction *)action)->unit;
        if (((BtlUnit *)battleUnit)->genus == 0) {
            lookAtPacket = btlActionCreateLookAtUnitPacketBytes(NULL, battleUnit, 2);
            ((BtlPacket *)lookAtPacket)->actionUID = *action;
            btlPacketEnqueue(lookAtPacket, 1);
        } else {
            lookAtDeactivatePacket = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 2);
            ((BtlPacket *)lookAtDeactivatePacket)->actionUID = *action;
            btlPacketEnqueue(lookAtDeactivatePacket, 1);
        }
    }
    btlPacketEnqueue(
        (u8 *)btlUnitCreateLookAtDeactivatePacket(
            (BtlUnit *)*(s32 *)(u8 *)btlActionAddAddressOffset(0x30, (s32)action), 0),
        1);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x21);
    ((BtlPacket *)cameraPacket)->actionUID = *action;
    btlPacketEnqueue(cameraPacket, 0);
    btlTargetResetCommandRecord((u8 *)action + 0x38);
    actionTypeAfter = *(u16 *)(u8 *)btlActionAddAddressOffset(0x10, (s32)action);
    if ((actionTypeAfter != 0x25) && (actionTypeAfter != 6) && (actionTypeAfter != 5)) {
        btlPanelInit(((BtlBattleState *)iGpffffb3ac)->uiTask, (u8 *)action);
        btlEncounterEntrySetEmphasis(((BtlBattleState *)iGpffffb3ac)->uiTask);
    }
    btlUnitRequestLookAtOthers((u8 *)action);
    ((BtlBattleState *)iGpffffb3ac)->flags |= 0x20000;
    ((BtlAction *)action)->commandDelay = 0;
    ((BtlAction *)action)->unk_420 = 0;
}

/* measured 001a17d0: obj 1192B/window 1200B (-8B, -0.7% inside, 2-instr slack); 0 words via `python3 tools/measure_guarded.py src/promoted/code1_001a.c func_001a17d0`, 0 edits (+28 reloc-only) 298/298 via `python3 tools/fnalign.py src/promoted/code1_001a.c func_001a17d0 --candidate /tmp/candF_f32.c --quiet`; Jal 36 both sides. Switch v4 &0xFFFF reverse 2,0/default (compiler checks 0 first, matching retail layout; was if/else with bne losing andi+beq+b); switch v10 numeric 1,2,3,10 (compiler checks 10,3,2,1, matching retail; was reverse 10,3,2/1 checking 1 first); s32 f (was u16, fixes $a0 vs $v1 + extra andi); tail before check9 (was 9 before tail, fixing 37/37 pure hole/lump exactly equal, 294/297 inside hiding swap, edits 120->0). Production MATCH. */
// FUN_001A17D0
/* Drive command-panel selection, temporary condition messages, and the ready/automatic transitions. */
/* Raw action fields retain MATCH: replacing them with BtlAction members changed this state's frame and allocation. */
void btlActionCommandUpdate(u8 *action)
{
    extern u8 *btlCameraCreateSetStatePacket(u8 *action, s32 state);
    extern u16 D_008C024C[];
    s32 panelState;
    u16 waitFrames;
    u16 actionKind;
    s32 condition;
    s32 checkCondition;
    s16 messageId;
    u8 *cameraPacket;
    u8 *actionCursor;

    btlUnitNoop();
    btlUnitTickIdleAnims();
    btlDamageSetActive(((BtlBattleState *)iGpffffb3ac)->uiTask);
    if (*(s32 *)(action + 0x420) == 1) {
        waitFrames = *(u16 *)(action + 0x41C);
        if (waitFrames == 0) {
            btlPanelSetActive(((BtlBattleState *)iGpffffb3ac)->uiTask);
            ((BtlAction *)action)->unk_420 = 0;
        } else {
            ((BtlAction *)action)->commandDelay = waitFrames - 1;
        }
        return;
    }
    panelState = btlPanelGetState(((BtlBattleState *)iGpffffb3ac)->uiTask) & 0xFFFF;
    if ((D_008C024C[0] & 8) != 0 && (panelState & 0xFFFF) == 1 && (((BtlBattleState *)iGpffffb3ac)->flags & 0x1000) == 0) {
        if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x20000) != 0) {
            if (btlPanelIsCommandSelectionActive(((BtlBattleState *)iGpffffb3ac)->uiTask) == 1) {
                if (btlPanelIsReady(((BtlBattleState *)iGpffffb3ac)->uiTask) == 0) {
                    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x10000) == 0) {
                        btlSelectionSetTargetFlag(((BtlBattleState *)iGpffffb3ac)->uiTask);
                        ((BtlBattleState *)iGpffffb3ac)->flags = ((BtlBattleState *)iGpffffb3ac)->flags | 0x10000;
                        btlEncounterEntrySetRetracted(((BtlBattleState *)iGpffffb3ac)->uiTask);
                        btlPanelSetFlag(((BtlBattleState *)iGpffffb3ac)->uiTask);
                        cameraPacket = btlCameraCreateSetStatePacket(action, 40);
                        ((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
                        btlPacketEnqueue(cameraPacket, 0);
                    }
                    return;
                }
            }
        }
    } else {
        if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x10000) != 0) {
            btlSelectionClearTargetFlag(((BtlBattleState *)iGpffffb3ac)->uiTask);
            ((BtlBattleState *)iGpffffb3ac)->flags = ((BtlBattleState *)iGpffffb3ac)->flags & ~0x10000;
            btlEncounterEntryClearRetracted(((BtlBattleState *)iGpffffb3ac)->uiTask);
            btlPanelClearFlag(((BtlBattleState *)iGpffffb3ac)->uiTask);
            cameraPacket = btlCameraCreateSetStatePacket(action, 33);
            ((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(cameraPacket, 0);
        }
    }
    switch (panelState & 0xFFFF) {
    case 2: {
        actionKind = ((BtlAction *)action)->unk_6c;
        switch (actionKind) {
        case 1:
        case 2:
            condition = (u16)btlActionEscapeCondition(action, ((BtlAction *)action)->unk_6e, 0);
            checkCondition = 1;
            break;
        case 3:
            condition = (u16)btlActionEscapeCondition(action, ((BtlAction *)action)->unk_6e, 1);
            checkCondition = 1;
            break;
        case 10:
            condition = 0;
            checkCondition = 1;
            break;
        default:
            condition = 0;
            checkCondition = 0;
            break;
        }
        if (checkCondition != 0) {
            messageId = btlConditionMessageId(condition);
            if (messageId != 0) {
                sdkSndStartStream(0, 15, 0, 8);
                btlUiSelectEffect((s32)((BtlAction *)action)->unit, messageId);
                ((BtlAction *)action)->commandDelay = 6;
                ((BtlAction *)action)->unk_420 = 1;
                btlPanelSetClosing(((BtlBattleState *)iGpffffb3ac)->uiTask);
                return;
            } else {
                btlEncounterEntryClearEmphasis(((BtlBattleState *)iGpffffb3ac)->uiTask);
                btlPanelSetFlag(((BtlBattleState *)iGpffffb3ac)->uiTask);
                btlActionSetState((BtlAction *)action, 6);
                return;
            }
        }
        goto tail;
    }
    case 0:
        goto tail;
    default:
        goto check9;
    }
tail:
    ((BtlAction *)action)->flags = ((BtlAction *)action)->flags | 2;
    btlDamageClearActive(((BtlBattleState *)iGpffffb3ac)->uiTask);
    btlPanelReleaseText(((BtlBattleState *)iGpffffb3ac)->uiTask);
    btlPanelReset(((BtlBattleState *)iGpffffb3ac)->uiTask);
    btlEncounterEntryClearEmphasis(((BtlBattleState *)iGpffffb3ac)->uiTask);
    for (actionCursor = ((BtlBattleState *)iGpffffb3ac)->actions; actionCursor != 0; actionCursor = (u8*)((BtlAction *)actionCursor)->next) {
    }
    btlActionSetState((BtlAction *)action, 15);
    return;
check9:
    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x1000) != 0) {
        btlDamageClearActive(((BtlBattleState *)iGpffffb3ac)->uiTask);
        btlPanelReleaseText(((BtlBattleState *)iGpffffb3ac)->uiTask);
        btlPanelReset(((BtlBattleState *)iGpffffb3ac)->uiTask);
        btlEncounterEntryClearEmphasis(((BtlBattleState *)iGpffffb3ac)->uiTask);
        for (actionCursor = ((BtlBattleState *)iGpffffb3ac)->actions; actionCursor != 0; actionCursor = (u8*)((BtlAction *)actionCursor)->next) {
        }
        btlActionSetState((BtlAction *)action, 9);
    }
    return;
}

// FUN_001A1C80
/* Build selectable targets for the chosen command and initialize their camera and selection marks. */
/* Raw selection/table offsets retain MATCH; canonical action-field accesses changed this state's frame. */
void btlActionTargetInit(u8 *action)
{
    u8 *lookAtUnit;
    s32 unitIndex;
    u8 entryType;
    u8 *packet;

    switch (((BtlAction *)action)->unk_6c) {
    case 4:
        btlEffectCollectTargetUnits(action, action + 0x98, 2, 0, 0);
        unitIndex = btlActionNormalizeUnitIndex(*(u16 *)(action + 0x6E));
        break;
    default:
        unitIndex = ((BtlAction *)action)->unk_6e;
        entryType = ((DatSkillEntry *)btlActionAddAddressOffset(unitIndex * 0x28,
                                               (u32)iGpffffb3b8))->unknown04[4];
        switch (entryType) {
        case 1:
        case 2:
            {
                extern void btlEffectCollectTargetUnits(
                    u8 *action, u8 *selection, u8 sideFlags, u8 filterFlags, u32 statusMask);
                btlEffectCollectTargetUnits(
                    action,
                    action + 0x98,
                    ((DatSkillEntry *)btlActionAddAddressOffset(unitIndex * 0x28,
                                                  (u32)iGpffffb3b8))->unknown04[5],
                    ((DatSkillEntry *)btlActionAddAddressOffset(unitIndex * 0x28,
                                                  (u32)iGpffffb3b8))->unknown04[6],
                    0);
            }
            break;
        default:
            btlSkillClassifyTargets(action, action + 0x98, unitIndex & 0xFFFF, 0);
            break;
        }
        break;
    }
init_1c80:
    btlEffectSelectNearestEntry(action, action + 0x98);
    entryType = ((DatSkillEntry *)btlActionAddAddressOffset(
        ((BtlAction *)action)->unk_6e * 0x28, (u32)iGpffffb3b8))->unknown04[4];
    switch (entryType) {
    case 1:
    case 2:
        goto type12_2_1c80;
    default:
        goto typeother_2_1c80;
    }
type12_2_1c80:
    lookAtUnit = NULL;
    goto after_type_1c80;
typeother_2_1c80:
    btlEffectSelectTargetByStatus(action, action + 0x98);
after_type_1c80:
    btlSelectionMarkTargets(
        ((BtlBattleState *)D_0076449C)->uiTask,
        action,
        action + 0x98,
        (s64)(s16)unitIndex);
    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x22);
    ((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    btlDamageSetActive(((BtlBattleState *)D_0076449C)->uiTask);
    btlUnitRequestLookAtOthers(action);
    if (lookAtUnit != NULL) {
        packet = btlActionCreateLookAtUnitPacketBytes(NULL, *(u8 **)(lookAtUnit + 0x30), 1);
        btlPacketEnqueue(packet, 1);
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)(s32)((BtlAction *)lookAtUnit)->unit, 0);
        btlPacketEnqueue(packet, 1);
    }
}

#pragma push
// FUN_001A1EA0
/* Accept or cancel target selection, copy the selected action records, and validate the command. */
/* Raw action/selection offsets retain MATCH; the typed action rewrite changed the frame and register allocation. */
void btlActionTargetUpdate(u8 *action) {
    extern u16 D_008C024C[];
    extern void btlUnitTickIdleAnims(void);
    extern void btlUnitNoop(void);
    extern s32 btlConditionMessageId(s32 condition);
    extern void btlUiSelectEffect(s32 unit, u32 entryId);
    extern void btlPanelSetActive(s32 task);
    extern void btlPanelReset(s32 task);
    extern void btlPanelClearFlag(s32 task);
    extern void btlSelectionSetTargetFlag(s32 task);
    extern void btlSelectionClearTargetFlag(s32 task);
    extern void btlDamageClearActive(s32 task);
    extern void btlEncounterEntryClearRetracted(s32 task);
    extern void btlEncounterEntrySetRetracted(s32 task);
    extern void btlEncounterEntrySetEmphasis(s32 task);
    extern void btlEncounterEntryClearEmphasis(s32 task);
    extern void btlPanelReleaseText(s32 task);
    s32 selectionState;
    s32 selectedAddress;
    s32 battleFlags;
    s32 selectionMode;
    u16 targetIndex;
    s32 condition;
    s32 messageId;
    u16 targetCount;
    u16 actionKind;
    u8 *enterCamera;
    u8 *exitCamera;
    u8 *selectedAction;
    u8 *selectedUnit;
    u8 targetMode;
    u8 *selectionBattle;
    u8 *enteredBattle;
    u8 *exitedBattle;
    u8 *battle;
    u8 *actionCursor;
    u8 *clearCursor;

    btlUnitNoop();
    btlUnitTickIdleAnims();
    selectionState = btlSelectionGetTargetMark((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask)) & 0xFFFF;
    if ((D_008C024C[0] & 8) && !(selectionState & 0xFFFF)) {
        battleFlags = (((BtlBattleState *)iGpffffb3ac)->flags);
        if (battleFlags & 0x20000) {
            if (!(battleFlags & 0x10000) && ((btlEffectCollectGenusMask((s32)(action + 0x98)) & 0xFFFF) != 1)) {
                btlSelectionSetTargetFlag((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
                enteredBattle = iGpffffb3ac;
                (((BtlBattleState *)enteredBattle)->flags) = (s32) ((((BtlBattleState *)enteredBattle)->flags) | 0x10000);
                btlEncounterEntrySetRetracted((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
                enterCamera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x28);
                (((BtlPacket *)enterCamera)->actionUID) = (s64) (*(s64*)action);
                btlPacketEnqueue(enterCamera, 0U);
            }
            return;
        }
        goto select_action;
    }
    battle = iGpffffb3ac;
    if ((((BtlBattleState *)battle)->flags) & 0x10000) {
        btlSelectionClearTargetFlag((s32)((u8 *)((BtlBattleState *)battle)->uiTask));
        exitedBattle = iGpffffb3ac;
        (((BtlBattleState *)exitedBattle)->flags) = (s32) ((((BtlBattleState *)exitedBattle)->flags) & 0xFFFEFFFF);
        btlEncounterEntryClearRetracted((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
        exitCamera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x22);
        (((BtlPacket *)exitCamera)->actionUID) = (s64) (*(s64*)action);
        btlPacketEnqueue(exitCamera, 0U);
    }
select_action:
    selectionMode = selectionState & 0xFFFF;
    switch (selectionMode) {
    case 0:
        selectionBattle = iGpffffb3ac;
        if ((((BtlBattleState *)selectionBattle)->flags) & 0x1000) {
            btlDamageClearActive((s32)((u8 *)((BtlBattleState *)selectionBattle)->uiTask));
            btlPanelReleaseText((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlSelectionResetUnitFlags((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlPanelReset((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlEncounterEntryClearEmphasis((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            actionCursor = (((BtlBattleState *)iGpffffb3ac)->actions);
            while (actionCursor != NULL) {
                actionCursor = (u8*)((BtlAction *)actionCursor)->next;
            }
            btlActionSetState((BtlAction *)action, 9);
            btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(0, 1), 1U);
            return;
        }
        selectedAction = (u8 *)btlSelectionGetFormationEntryAlt((s32)((u8 *)((BtlBattleState *)selectionBattle)->uiTask));
        if (selectedAction != NULL) {
            selectedUnit = (*(u8**)(selectedAction + 0x30));
            if ((((BtlUnit *)(selectedUnit))->genus) == 1) {
                btlPacketEnqueue((u8*)btlActionCreateLookAtUnitPacketBytes(NULL, selectedUnit, 1), 1U);
                btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(((BtlAction *)selectedAction)->unit, 0), 1U);
                return;
            }
        }
        btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(0, 3), 1U);
        return;
    case 1:
        targetMode = ((DatSkillEntry *)btlActionGetSelectionAddress(*(u16 *)(action + 0x6E) * 0x28, iGpffffb3b8))->unknown04[4];
        switch (targetMode) {
        case 1:
        case 2: {
            targetIndex = 0;
            while ((targetCount = ((BtlAction *)action)->unk_d0, targetIndex < (s32)targetCount)) {
                btlActionCopySelectedTarget(action, &targetIndex);
                targetIndex++;
            }
            (((BtlAction *)action)->unk_6a) = targetCount;
        } break;
        default: {
            selectedAddress = (s32)btlSelectionGetFormationEntry((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            (((BtlAction *)action)->targets[0]) = (u8*)selectedAddress;
            (((BtlAction *)action)->unk_6a) = 1U;
            btlFormationEntrySetSelected((s32)(action + 0x98), (u64 *)(u32)selectedAddress);
        } break;
        }
        actionKind = (*(u16*)(action + 0x6C));
        switch (actionKind) {
        case 1:
        case 2:
            condition = btlActionBuffCondition(action, (s32) (((BtlAction *)action)->unk_6e), 0) & 0xFFFF;
            break;
        case 3:
            condition = btlActionBuffCondition(action, (s32) (((BtlAction *)action)->unk_6e), 1) & 0xFFFF;
            break;
        default:
            condition = 0;
            break;
        }
        messageId = (s16)btlConditionMessageId(condition);
        if (messageId != 0) {
            sdkSndStartStream(0, 0xF, 0, 8);
            btlUiSelectEffect((s32)((BtlAction *)action)->unit, (u32)messageId);
            btlSelectionClearTargetMark((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            return;
        }
        switch (((BtlAction *)action)->unk_6c) {
        case 4: {
            btlSelectionResetUnitFlags((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlPanelOnTargetAction((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask), (s32)(((BtlAction *)action)->targets[0]));
            btlActionSetState((BtlAction *)action, 5);
            return;
        } break;
        default: {
            (((BtlAction *)action)->flags) = (u16) ((((BtlAction *)action)->flags) | 2);
            btlDamageClearActive((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlPanelReleaseText((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlSelectionResetUnitFlags((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlPanelReset((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            btlEncounterEntryClearEmphasis((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
            clearCursor = (((BtlBattleState *)iGpffffb3ac)->actions);
            while (clearCursor != NULL) {
                clearCursor = (u8*)((BtlAction *)clearCursor)->next;
            }
            btlActionSetState((BtlAction *)action, 0xF);
            return;
        } break;
        }
    case 2:
        btlPacketEnqueue((u8*)btlUnitCreateLookAtDeactivatePacket(0, 1), 1U);
        btlSelectionResetUnitFlags((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
        btlEncounterEntrySetEmphasis(((BtlBattleState *)iGpffffb3ac)->uiTask);
        btlPanelClearFlag((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
        btlPanelSetActive((s32)((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask));
        btlActionSetState((BtlAction *)action, 5);
        /* fallthrough */
    case 3:
        return;
    }
}

#pragma pop
// FUN_001A24A0
/* Enter the opening phase of the analyze presentation. */
void btlActionAnalyzeInit(BtlAction *action)
{
    ((BtlAction *)action)->unk_41c = 1;
}

/* measured: 1564/1568 bytes, 47 resolved relocations, four zero tail bytes.
 * Loop invariants hoist the first scan's true value and each unsigned wrap
 * bound as retail does. Stored short cursor and widened index stay distinct. */
// FUN_001A24B0
#pragma push
/* measured: func_001a24b0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Hide unrelated actors, browse distinct unit records, and restore presentation when analyze closes. */
/* Raw action and indexed selection offsets retain MATCH; canonical action fields changed this state's frame. */
void btlActionAnalyzeUpdate(u8 *action)
{
    extern u16 D_008C024C[];
    extern s32 sdkSndStartStream(s16 index, s16 stream, s16 value, s16 flags);

    if (btlCountUnitRecordsById(0x800) != 0) {
        return;
    }
    switch (*(s32 *)(action + 0x41C)) {
    case 1: {
        u8 *openingPacket;
        u8 *iter;
        s32 hasOther;
        u8 *selected;
        s16 index;

        openingPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
        ((BtlPacket *)openingPacket)->actionUID = *(s64 *)action;
        btlPacketEnqueue(openingPacket, 0);
        iter = ((BtlBattleState *)D_0076449C)->actions;
        while (iter != NULL) {
            u8 *packet;
            if (((BtlAction *)iter)->unk_1a & 1) {
                if (action == iter || !(((BtlAction *)iter)->unk_1a & 8)) {
                    packet = btlUnitCreateHidePacket((u8*)((BtlAction *)iter)->unit);
                } else {
                    packet = btlUnitCreateColorPacket((u8*)((BtlAction *)iter)->unit, 0xFFFFFF, 8, 0, 4, 0);
                }
                ((BtlPacket *)packet)->actionUID = *(s64 *)action;
                btlPacketEnqueue(packet, 0);
            }
            iter = (u8*)((BtlAction *)iter)->next;
        }
        selected = ((BtlAction *)action)->targets[0];
        btlEffectCollectTargetUnits(action, action + 0x98, 2, 0, 0);
        hasOther = 0;
        *(u16 *)(action + 0xD2) = *(u16 *)(action + 0xD0);
        index = 0;
        while ((s16)index < ((BtlAction *)action)->unk_d0) {
            u8 **slot = (u8 **)(action + (s16)index * 4 + 0x98);
            if (*slot == selected) {
                ((BtlAction *)action)->unk_d2 = index;
            }
            if (((BtlUnit *)((u8*)((BtlAction *)*slot)->unit))->charId !=
                ((BtlUnit *)((u8*)((BtlAction *)selected)->unit))->charId) {
                hasOther = 1;
            }
            index++;
        }
        btlEncounterEntrySetMessageFade(((BtlBattleState *)D_0076449C)->uiTask);
        btlMessageSetup((u8 *)((BtlBattleState *)D_0076449C)->uiTask, selected);
        if (hasOther) {
            btlMessageSetHidden(((BtlBattleState *)D_0076449C)->uiTask);
        }
        btlActionFinishPresentation((BtlAction *)action);
        {
            u8 *cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)selected, 1);
            ((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(cameraPacket, 0);
        }
        btlSoundCancelPlayback();
        btlSoundStopBank3();
        if (btlTargetCanControlDamagePhase() == 1) {
            ((BtlBattleState *)D_0076449C)->flags &= ~0x2000;
            btlDamageSetSource((u8 *)((BtlBattleState *)D_0076449C)->uiTask, 0);
        }
        ((BtlAction *)action)->unk_41c = 2;
        break;
    }
    case 2: {
        if (btlMessageIsIdle(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
            u8 *unit = (u8*)((BtlAction *)((BtlAction *)action)->targets[0])->unit;
            if (unit != NULL) {
                s32 resource = btlSoundPickResistVoice(unit);
                if (resource >= 0) {
                    btlVoicePlayIdCue((u16)resource, 1);
                }
            }
            ((BtlAction *)action)->unk_41c = 3;
        }
        break;
    }
    case 3: {
        u16 input = D_008C024C[1];
        if ((input & 8) || (input & 4)) {
            u8 *selected = *(u8 **)(action + 0x38);
            u16 previous = *(u16 *)(action + 0xD2);
            s32 selectedIndex;
            s16 cursor = (s16)previous;
            if (input & 8) {
                s32 count = ((BtlAction *)action)->unk_d0;
                while ((selectedIndex = (s16)cursor) < count) {
                    u8 *candidate = ((BtlAction *)action)->parameters.candidates[selectedIndex];
                    if (((BtlUnit *)((u8*)((BtlAction *)candidate)->unit))->charId !=
                        ((BtlUnit *)((u8*)((BtlAction *)selected)->unit))->charId) {
                        break;
                    }
                    cursor++;
                }
                if (count == selectedIndex) {
                    cursor = 0;
                    while ((selectedIndex = (s16)cursor) < (u16)previous) {
                        u8 *candidate = ((BtlAction *)action)->parameters.candidates[selectedIndex];
                        if (((BtlUnit *)((u8*)((BtlAction *)candidate)->unit))->charId !=
                            ((BtlUnit *)((u8*)((BtlAction *)selected)->unit))->charId) {
                            break;
                        }
                        cursor++;
                    }
                }
            } else {
                while ((selectedIndex = (s16)cursor) >= 0) {
                    u8 *candidate = ((BtlAction *)action)->parameters.candidates[selectedIndex];
                    if (((BtlUnit *)((u8*)((BtlAction *)candidate)->unit))->charId !=
                        ((BtlUnit *)((u8*)((BtlAction *)selected)->unit))->charId) {
                        break;
                    }
                    cursor--;
                }
                if (selectedIndex < 0) {
                    cursor = ((BtlAction *)action)->unk_d0 - 1;
                    while ((selectedIndex = (s16)cursor) > (u16)previous) {
                        u8 *candidate = ((BtlAction *)action)->parameters.candidates[selectedIndex];
                        if (((BtlUnit *)((u8*)((BtlAction *)candidate)->unit))->charId !=
                            ((BtlUnit *)((u8*)((BtlAction *)selected)->unit))->charId) {
                            break;
                        }
                        cursor--;
                    }
                }
            }
            if ((u16)previous != selectedIndex) {
                sdkSndStartStream(0, 0, 0, 5);
                ((BtlAction *)action)->targets[0] = *(u8 **)((u8 *)btlActionAddAddressOffset(selectedIndex * 4, (s32)action) + 0x98);
                ((BtlAction *)action)->unk_d2 = cursor;
                btlMessageSetPendingValue((u8 *)((BtlBattleState *)D_0076449C)->uiTask, *(s32 *)(action + 0x38));
            }
        } else if ((input & 0x40) || (input & 0x20)) {
            sdkSndStartStream(0, 0, 0, 4);
            if (btlTargetCanControlDamagePhase() == 1) {
                ((BtlBattleState *)D_0076449C)->flags |= 0x2000;
                btlDamageSetSource((u8 *)((BtlBattleState *)D_0076449C)->uiTask, 1);
            }
            ((BtlAction *)action)->unk_41c = 4;
        }
        break;
    }
    case 4: {
        u8 *iter;
        u8 *packet;
        btlVoiceFadeOut();
        iter = ((BtlBattleState *)D_0076449C)->actions;
        while (iter != NULL) {
            if ((((BtlAction *)iter)->unk_1a & 1) && !(((BtlAction *)iter)->unk_1a & 0x400)) {
                if (action == iter) {
                    packet = btlUnitCreateShowPacket((u8*)((BtlAction *)iter)->unit);
                } else {
                    packet = btlUnitCreateColorPacket((u8*)((BtlAction *)iter)->unit, (u32)-1, 0, 0, 3, 0);
                }
                ((BtlPacket *)packet)->actionUID = *(s64 *)action;
                btlPacketEnqueue(packet, 0);
            }
            iter = (u8*)((BtlAction *)iter)->next;
        }
        btlEncounterEntryClearMessageFade(((BtlBattleState *)D_0076449C)->uiTask);
        btlMessageSetDone(((BtlBattleState *)D_0076449C)->uiTask);
        btlActionSetState((BtlAction *)action, ((BtlAction *)action)->state);
        ((BtlAction *)action)->unk_41c = 0;
        break;
    }
    }
}

#pragma pop
// FUN_001A2AD0
/* Reset the command record and redirect eligible party actors to automatic selection. */
void btlActionAiInit(BtlAction *action) {
    btlTargetResetCommandRecord((u8 *)action + 0x38);
    if ((((BtlBattleState *)D_0076449C)->flags & 0x1000) == 0) {
        return;
    }
    if ((((BtlAction *)action)->unk_1a & 1) == 0) {
        return;
    }
    if (((BtlAction *)action)->unit->genus != 0) {
        return;
    }
    btlActionSetState(action, 9);
}

// FUN_001A2B50
/* Wait for AI selection to finish, mark the action ready, and preserve the accelerated-action flag. */
void btlActionAiUpdate(u8 *action)
{
    s32 battleFlags;

    if (btlEffectHasAiProcedure(action + 0x38) == 0) {
        btlAICommandSetUnitAction(action, action + 0x38);
    }
    if (btlAICommandTryReleaseProc(action + 0x38) != 0) {
        battleFlags = ((BtlBattleState *)D_0076449C)->flags;
        if ((battleFlags & 0x1000) &&
            (battleFlags & 0x04000000) &&
            ((BtlAction *)action)->unit->genus == 1) {
            ((BtlAction *)action)->flags |= 0x4000;
        }
        ((BtlAction *)action)->flags |= 2;
        btlActionSetState((BtlAction *)action, 0xF);
    }
}

// FUN_001A2C10
/* Reset the command record and choose an initial classified target. */
void btlActionAutoInit(s64 *action) {
    btlTargetResetCommandRecord((u8 *)action + 0x38);
    btlSkillClassifyTargets((u8 *)action, (u8 *)action + 0x98, 0, 0);
    btlEffectSelectNearestEntry(NULL, action + 0x13);
}

// FUN_001A2C70
/* Select the unit default skill and current target, then advance to action readiness. */
/* Raw selection aliases retain the signed stores and selected-pointer word representation absent from BtlAction. */
void btlActionAutoUpdate(u8 *action)
{
    u8 *battleUnit;

    ((BtlAction *)action)->unk_6c = 1;
    ((BtlAction *)action)->unk_6e =
        datCalcDefaultSkillId((u8 *)((BtlUnit *)(*(u8 **)(action + 0x30)))->datUnit);
    *(s32 *)(action + 0x38) = btlFormationCurrentEntry(action + 0x98);
    ((BtlAction *)action)->unk_6a = 1;
    btlFormationEntrySetSelected((s32)(action + 0x98), (u64*)((BtlAction *)action)->targets[0]);
    battleUnit = (u8*)((BtlAction *)action)->unit;
    if ((((BtlUnit *)battleUnit)->genus == 0) && (((BtlUnit *)(battleUnit))->charId == 1)) {
        btlPacketEnqueue(btlActionCreateTargetPacketBytes(action, 1, 0, 0, 0), 1);
    }
    if (((BtlBattleState *)D_0076449C)->flags & 0x04000000) {
        ((BtlAction *)action)->flags |= 0x4000;
    }
    ((BtlAction *)action)->flags |= 2;
    btlActionSetState((BtlAction *)action, 0xF);
}

// FUN_001A2D60
void btlActionSupportInit(void)
{
}

/* MATCHED: 1072 bytes of code and the 64-byte table at 0x00746FD0 resolve
   exactly.  This is D_005f6e20[10].update, a void action callback, so the
   packet UID that func_00194590 returns is discarded here.  The u8
   conversion plus the explicit signed guard reproduce retail's redundant
   `bltz` range check - the two words an earlier pass could not place -
   and opt_propagation off with opt_common_subs off keep that lowering
   together with the repeated `(u8*)((BtlUnit *)unit)->datUnit` loads that retail
   reloads rather than folding. */
// FUN_001A2D70
#pragma push
/* measured: func_001a2d70 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* Clear the selected buff levels and enqueue their presentation, or choose status recovery/the next state. */
void btlActionSupportUpdate(u8 *action) {
    extern void btlActionSetState(u8 *, u16);
    extern u8 *btlCameraCreateSetStatePacket(u8 *, u16);

    s32 state;
    s32 kind;
    u8 *unit;
    u8 *packet;

    void datCalcClearBuffLevel(u8 *unit, s32 buffIndex);


    if (btlCountUnitRecordsById(0x506) == 0) {
        unit = (u8 *)((BtlAction *)action)->unit;
        kind = (u8)datCalcFindStrongBuff((u8 *)((BtlUnit *)unit)->datUnit);
        if (kind < 0) {
            goto fallback;
        }
        switch (kind) {
        case 0:
        case 1:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 30;
            } else {
                state = 31;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 0);
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 1);
            break;
        case 2:
        case 4:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 32;
            } else {
                state = 33;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 4);
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 2);
            break;
        case 3:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 34;
            } else {
                state = 35;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 3);
            break;
        case 5:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 36;
            } else {
                state = 37;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 5);
            break;
        case 6:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 38;
            } else {
                state = 39;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 6);
            break;
        case 7:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 40;
            } else {
                state = 41;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 7);
            break;
        case 8:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 80;
            } else {
                state = 81;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 8);
            break;
        case 9:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 82;
            } else {
                state = 83;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 9);
            break;
        case 10:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 84;
            } else {
                state = 85;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 10);
            break;
        case 11:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 86;
            } else {
                state = 87;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 11);
            break;
        case 12:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 130;
            } else {
                state = 131;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 12);
            break;
        case 13:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 132;
            } else {
                state = 133;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 13);
            break;
        case 14:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 134;
            } else {
                state = 135;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 14);
            break;
        case 15:
            if (((BtlUnit *)unit)->genus == 0) {
                state = 136;
            } else {
                state = 137;
            }
            datCalcClearBuffLevel((u8 *)((BtlUnit *)unit)->datUnit, 15);
            break;
        default:
            state = 0;
            break;
        }
        if (state != 0) {
            btlActionFinishPresentation((BtlAction *)action);
            packet = btlCameraCreateSetStatePacket((u8 *)action, 10);
            ((BtlPacket *)packet)->actionUID = *(s64 *)action;
            btlPacketEnqueue(packet, 0);
            packet = btlActionCreateMessagePacketBytes((s32)((BtlAction *)action)->unit, (s32)state);
            ((BtlPacket *)packet)->actionUID = *(s64 *)action;
            btlPacketEnqueue(packet, 3);
        } else {
fallback:
            if (btlSoundRollStatusCure((u8 *)action) != 0) {
                btlActionSetState((u8 *)action, 11);
            } else {
                btlActionSetState((u8 *)action, 3);
            }
        }
    }
}

#pragma pop
// FUN_001A31A0
/* Initialize status-recovery progress after advancing the shared status counters. */
void btlActionBadInit(u8 *action)
{
    btlSoundBumpStatusCounters();
    ((BtlAction *)action)->unk_41c = 1;
    ((BtlAction *)action)->unk_420 = 0;
}

#pragma push
/* Recover an incapacitated action or select its next state. The unit status
 * remains a 32-bit word through the low20 selector. Camera and animation
 * packets remain alive until their published UIDs have been consumed. */
// FUN_001A31E0
/* Raw action/packet offsets retain MATCH; both canonical action fields and typed packet headers changed code generation. */
void btlActionBadUpdate(BtlAction *actionState)
{
    u8 *action = (u8 *)actionState;
    u32 badStatus;
    s32 allowRecovery;
    s32 resultFlags;
    u8 *cameraPacket;
    u8 *animationPacket;
    u16 animationDelay;
    u16 animationDuration;
    f32 animationSpeed;
    f32 rotation[3];
    LargeBattleHitResult result;

    if (btlCountUnitRecordsById(0x506) == 0 && btlCountUnitRecordsById(0x105) == 0) {
        btlActionFinishPresentation((BtlAction *)action);
        badStatus = datCalcGetBadStatus((s32)((BtlUnit *)(*(u8 **)(action + 0x30)))->datUnit);
        if (datCalcChkBadStatus((s32)((BtlUnit *)(*(u8 **)(action + 0x30)))->datUnit, 0x100000) != 0 &&
            *(s32 *)(action + 0x420) == 0) {
            allowRecovery = 1;
            if (datCalcChkBadStatus((s32)((BtlUnit *)(*(u8 **)(action + 0x30)))->datUnit, 1) != 0 &&
                btlSoundIsStatusCounterHigh(action) == 0) {
                allowRecovery = 0;
            }
            if (allowRecovery != 0) {
                cameraPacket = (u8 *)btlCameraCreateSetStatePacket(actionState, 0x31);
                ((BtlPacketTiming *)cameraPacket)->actionUid = *(s64 *)action;
                btlPacketEnqueue(cameraPacket, 0);
                if (((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) {
                    u8 *packet;
                    btlUnitGetAnchorPose(*(u8 **)(action + 0x30), NULL, NULL, rotation);
                    packet = (u8 *)btlUnitCreateRotatePacket(((BtlAction *)action)->unit,
                                                            (const RwV3d *)rotation, 2);
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u32 flags = ((BtlBattleState *)iGpffffb3ac)->flags;
                    if ((flags & 0x1000) && (flags & 0x04000000)) {
                        animationSpeed = 1.75f;
                        animationDelay = 12;
                        animationDuration = 4;
                    } else {
                        animationSpeed = 1.0f;
                        animationDelay = 30;
                        animationDuration = 8;
                    }
                }
                animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                                               11, 0, animationSpeed, 0);
                animationPacket[0] = 4;
                ((BtlPacketTiming *)animationPacket)->dependencyUid = ((BtlPacketTiming *)cameraPacket)->uid;
                ((BtlPacketTiming *)animationPacket)->delay = animationDelay;
                ((BtlPacketTiming *)animationPacket)->actionUid = *(s64 *)action;
                btlPacketEnqueue(animationPacket, 0);
                {
                    u8 *packet = (u8 *)btlVoiceCreatePacket(actionState, 3, 0, 0, 0);
                    packet[0] = 4;
                    ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
                    btlPacketEnqueue(packet, 1);
                }
                btlTargetClearResultBuffer((u8 *)&result);
                result.removedStatus = 0x100001;
                {
                    u8 *packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    packet[0] = 4;
                    ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                {
                    u8 *packet = (u8 *)btlUnitCreateMotionSettlePacket(*(BtlUnit **)(action + 0x30));
                    packet[0] = 4;
                    ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
                    ((BtlPacketTiming *)packet)->duration = animationDuration;
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u8 *packet = (u8 *)btlTargetCreateTargetPacket((u32)action, 0x11, 0, 0, 0);
                    packet[0] = 4;
                    ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)animationPacket)->uid;
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                ((BtlAction *)action)->unk_41c = 1;
            } else {
                {
                    u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u8 *packet = (u8 *)btlTargetCreateTargetPacket((u32)action, 0x12, 0, 0, 0);
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                {
                    u8 *unit = (u8*)((BtlAction *)action)->unit;
                    u8 *packet;
                    s32 message;
                    if (((BtlUnit *)unit)->genus == 0) {
                        message = 0x68;
                    } else {
                        message = 0x69;
                    }
                    packet = (u8 *)btlPacketCreateEffectCounter((s32)unit, message);
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 3);
                }
                ((BtlAction *)action)->unk_41c = 0;
            }
            btlPacketEnqueue((u8 *)btlUnitCreateLookAtUnitPacket(NULL, *(BtlUnit **)(action + 0x30), 1), 1);
            btlPacketEnqueue((u8 *)btlUnitCreateLookAtDeactivatePacket(((BtlAction *)action)->unit, 0), 1);
            ((BtlAction *)action)->flags |= 0x200;
            ((BtlAction *)action)->unk_420 = 1;
            return;
        }
        resultFlags = btlSoundSelectCureableStatuses(action);
        if (resultFlags != 0) {
            s32 message;
            {
                u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                btlPacketEnqueue(packet, 0);
            }
            btlTargetClearResultBuffer((u8 *)&result);
            result.removedStatus = resultFlags;
            {
                u8 *packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                ((BtlPacketTiming *)packet)->delay = 0x12;
                btlPacketEnqueue(packet, 1);
            }
            message = btlSoundPickStatusTalkVoiceB(action);
            if (message > 0) {
                u8 *packet = (u8 *)btlPacketCreateEffectCounter((s32)((BtlAction *)action)->unit, message);
                ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                btlPacketEnqueue(packet, 3);
            }
            return;
        }
        if (((BtlAction *)action)->unk_41c != 0) {
            if (badStatus & 0x116) {
                s32 message;
                btlAiSelectStatusCommand(action, action + 0x38, badStatus);
                ((BtlAction *)action)->flags |= 2;
                message = btlSoundPickStatusTalkVoiceA(action);
                if (message > 0) {
                    {
                        u8 *packet = (u8 *)btlCameraCreateSetStatePacket(actionState, 10);
                        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                        btlPacketEnqueue(packet, 0);
                    }
                    {
                        u8 *packet = (u8 *)btlPacketCreateEffectCounter((s32)((BtlAction *)action)->unit, message);
                        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                        btlPacketEnqueue(packet, 3);
                    }
                }
                {
                    u8 *packet = (u8 *)btlTargetCreateTargetPacket((u32)action, 0x1E, 0, 0, 0);
                    ((BtlPacketTiming *)packet)->delay = 0x18;
                    ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                btlActionSetState(actionState, 15);
                return;
            }
            btlActionSetStateWithDelay(actionState, 3, 1);
            return;
        }
        btlTargetResetCommandRecord(action + 0x38);
        ((BtlAction *)action)->flags &= 0xFFF7;
        if (btlSoundCanReceiveStatus(action) != 0) {
            btlActionSetState(actionState, 27);
            return;
        }
        btlActionSetState(actionState, 32);
    }
}

#pragma pop
#pragma push
/* The mode is established by the action selector before entering this state.
   Movement and target-animation packets are separate dependency owners. */
// FUN_001A3840
/* Raw cooperation/packet offsets retain MATCH; typed packet headers changed the frame and register allocation. */
void btlActionCooperateInit(register BtlAction *actionState)
{
    u8 *action;
    u8 *movementPacket;
    u8 *animationPacket;
    u8 *target;
    s16 mode;
    s32 resultFlags;
    f32 distance;
    struct { s16 slot; } selectedEffect;
    u16 targetFrame;
    u16 targetAnimation;
    u16 sourceAnimation;
    u16 beforeVoice;
    u16 afterVoice;
    u16 formationMode;
    u16 displayMode;
    LargeBattleHitResult result;
    s32 delayedFrame;

    action = (u8 *)actionState;
    target = (u8*)((BtlAction *)action)->cooperation.target;
    mode = ((BtlAction *)action)->cooperation.mode;
    switch (mode) {
    case 1:
        resultFlags = 0x100001;
        sourceAnimation = 27;
        targetAnimation = 28;
        targetFrame = 0;
        {
            u8 *targetUnit = (u8*)((BtlAction *)target)->unit;
            u8 *sourceUnit = (u8*)((BtlAction *)action)->unit;
            f32 sourceRadius = ((BtlUnit *)(sourceUnit))->sphereRadius;
            f32 sourceScale = ((BtlUnit *)(sourceUnit))->scale;
            f32 targetRadius = ((BtlUnit *)(targetUnit))->sphereRadius;
            f32 targetScale = ((BtlUnit *)(targetUnit))->scale;
            distance = 50.0f + (sourceRadius * sourceScale + targetRadius * targetScale);
        }
        selectedEffect.slot = -1;
        displayMode = 14;
        formationMode = 1;
        beforeVoice = 0;
        afterVoice = 12;
        ((BtlAction *)action)->unk_1a |= 0x800;
        break;
    case 0:
        resultFlags = 30;
        sourceAnimation = 29;
        targetAnimation = 2;
        targetFrame = (u16)btlUnitMotionFrames(*(u8 **)(action + 0x30), 29, 1.0f);
        distance = 50.0f + btlUnitGetMotionDistance((u8*)((BtlAction *)action)->unit,
                                        (u8*)((BtlAction *)target)->unit, 29);
        displayMode = 15;
        selectedEffect.slot = 40;
        formationMode = 0;
        beforeVoice = 10;
        afterVoice = 11;
        ((BtlAction *)action)->unk_1a |= 0x1000;
        break;
    }
    btlActionFinishPresentation((BtlAction *)action);
    btlTargetResetRecordCounter(action + 0x38);
    ((BtlAction *)action)->targets[0] = target;
    ((BtlAction *)action)->unk_6a = 1;
    if ((u16)beforeVoice != 0) {
        {
            u8 *packet;
            packet = (u8 *)btlVoiceCreatePacket((BtlAction *)action, beforeVoice,
                             ((BtlUnit *)((u8*)((BtlAction *)target)->unit))->charId, 0, 0);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
        }
    }
    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) == 0) {
        {
            u8 *packet;
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 25);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 0);
        }
        movementPacket = (u8 *)btlUnitCreateMoveToUnitPacket(((BtlAction *)action)->unit,
                        ((BtlAction *)target)->unit, distance, fGpffff811c, 10);
        ((BtlPacketTiming *)movementPacket)->actionUid = *(s64 *)action;
        btlPacketEnqueue(movementPacket, 0);
    } else {
        movementPacket = btlPacketCreateImmediate();
        ((BtlPacketTiming *)movementPacket)->actionUid = *(s64 *)action;
        btlPacketEnqueue(movementPacket, 0);
    }
    {
        u8 *packet;
        packet = btlPacketCreateSpriteTable(*(u32 *)(action + 0x30), displayMode);
        packet[0] = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(movementPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        btlPacketEnqueue(packet, 3);
    }
    {
        u8 *packet;
        packet = (u8 *)btlFormationCreateWaitPacket(*(u32 *)(action + 0x30), *(u32 *)(target + 0x30), formationMode);
        packet[0] = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(movementPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 42);
        packet[0] = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(movementPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    if ((u16)afterVoice != 0) {
        {
            u8 *packet;
            packet = (u8 *)btlVoiceCreatePacket((BtlAction *)action, afterVoice,
                             ((BtlUnit *)((u8*)((BtlAction *)target)->unit))->charId, 0, 0);
            packet[0] = 4;
            ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)movementPacket)->uid;
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
        }
    }
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                             (s16)sourceAnimation, 0, 1.0f, 0);
        packet[0] = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(movementPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        ((BtlPacketTiming *)packet)->duration = btlUnitMotionModelFrames(*(u8 **)(action + 0x30), sourceAnimation, 1.0f);
        btlPacketEnqueue(packet, 0);
    }
    animationPacket = (u8 *)btlUnitCreateAnimPacket(((BtlAction *)target)->unit,
                                                  (s16)targetAnimation, 0, 1.0f, 0);
    animationPacket[0] = 4;
    ((BtlPacketTiming *)animationPacket)->dependencyUid = *(s64 *)(movementPacket + 0x58);
    ((BtlPacketTiming *)animationPacket)->actionUid = *(s64 *)action;
    delayedFrame = (s16)targetFrame;
    ((BtlPacketTiming *)animationPacket)->delay = targetFrame;
    btlPacketEnqueue(animationPacket, 0);
    if (selectedEffect.slot != -1) {
        {
            u8 *packet;
            const BtlBattleState *resourceBase;
            resourceBase = (const BtlBattleState *)iGpffffb3ac;
            packet = (u8 *)btlFormationCreatePacket(btlActionGetFormationResource(resourceBase, selectedEffect.slot),
                                        (u32)((BtlAction *)action)->unit, *(u32 *)(target + 0x30), 1, 0);
            packet[0] = 4;
            ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)movementPacket)->uid;
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            ((BtlPacketTiming *)packet)->delay = delayedFrame;
            btlPacketEnqueue(packet, 2);
        }
    }
    btlTargetClearResultBuffer((u8 *)&result);
    result.removedStatus = resultFlags;
    {
        u8 *packet;
        packet = (u8 *)btlTargetCreateDataPacket((s32)target, (s32)target, &result, 1, 1);
        packet[0] = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)animationPacket)->uid;
        ((BtlPacketTiming *)packet)->delay = delayedFrame;
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
    }
}

#pragma pop
// FUN_001A3D50
/* Wait for this action packet chain, clear its cooperation mode, and publish completion flags. */
/* Raw halfwords cover the cooperation mode and battle-state bits not declared in the shared layouts. */
void btlActionCooperateUpdate(BtlAction *action)
{
    if (btlUnitRecordFindByActionUID(*(s64 *)action, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        ((BtlAction *)action)->cooperation.mode = -1;
        ((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 7;
        btlActionSetState(action, 0x20);
    }
}

// FUN_001A3DE0
/* Expose the action completion counter to the packet wait callback. */
s32 btlActionGetCounter420(BtlAction *action)
{
    return ((BtlAction *)action)->unk_420;
}

// FUN_001A3DF0
/* Release linked models and decide whether a follow-up prompt can be offered. */
/* Raw +0x90 reads the reference action from BtlAction's still-opaque command-record span. */
void btlActionPursuitMesInit(BtlAction *action)
{
    s32 status;
    u8 *iter;
    u8 *packet;
    s64 *current;

    iter = ((BtlBattleState *)D_0076449C)->actions;
    goto loop_test;
loop_body:
    if (btlActionLinkedUnitIsActive((BtlAction *)iter) != 0) {
        packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)((u8 *)((BtlAction *)iter)->unit))->childUnit);
        ((BtlPacket *)packet)->actionUID = *(s64 *)iter;
        btlPacketEnqueue(packet, 1);
    }
    iter = (u8 *)((BtlAction *)iter)->next;
loop_test:
    if (iter != NULL) {
        goto loop_body;
    }
    status = 1;
    current = btlActionGetQueueFront();
    if ((((BtlAction *)current)->flags & 8) != 0 &&
        btlActionCanFollowUpAfterEnemiesDown((u8 *)current) != 0) {
        status = 0;
    }
    if (status == 1) {
        status = btlEffectFindUnitMatchingCallback(
            (u8 *)action,
            datCalcSkillElement(
                (u8 *)((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->datUnit,
                btlTargetGetStatusEffectMsgCode((u8 *)action, ((BtlAction *)action)->parameters.supportTarget) & 0xFFFF) & 0xFFFF,
            2, 0x80000, 2, btlAICommandNomalStatusCheck);
    }
    if (status == 0) {
        packet = btlSoundStopTaskStart();
        ((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
        btlActionSetState(action, 0x20);
        return;
    }
    if (btlTargetCanControlDamagePhase() == 1) {
        ((BtlBattleState *)D_0076449C)->flags &= ~0x2000;
        btlDamageSetSource((u8 *)((BtlBattleState *)D_0076449C)->uiTask, 0);
    }
    ((BtlAction *)action)->unk_41c = 0;
    ((BtlAction *)action)->unk_420 = 0;
}

// FUN_001A3F90
/* Coordinate the follow-up prompt, cut-in and formation dependencies before dispatching the answer. */
/* Raw action fields retain MATCH after a typed rewrite; the packet +8 halfword is a tagged dependency ID. */
void btlActionPursuitMesUpdate(u8 *action)
{
    struct { s16 mode; u16 unitId; u8 reserved[12]; } cutin;
    BtlAction *partner;
    s64 *queuedAction;
    u16 waitFrames;
    u8 *waitPacket;
    u8 *effectPacket;

    if (*(s32 *)(action + 0x41C) == 0) {
        if ((btlCountUnitRecordsById(0xC00) == 0) && (btlCountUnitRecordsById(0xC04) == 0)) {
            cutin.mode = 2;
            cutin.unitId =
                ((BtlUnit *)(*(u8 **)(action + 0x30)))->charId;
            btlPacketEnqueue(btlCutinCreatePacket((u8 *)&cutin), 1);
            btlActionFinishPresentation((BtlAction *)action);
            btlPacketEnqueue(btlPacketCreateEndSequence(), 1);
            btlPacketEnqueue(btlSoundLoadTaskStart(), 1);
            btlMessageStartLong((u8 *)((BtlBattleState *)D_0076449C)->uiTask, (u8 *)action);
            btlPacketEnqueue((u8 *)btlFormationCreateSlotPacket(3, 0xFFF), 0);
            partner = (void *)btlActionGetQueueFront();
            btlPacketEnqueue(
                btlUnitCreateRotateTowardUnitPacket((u8 *)partner->unit,
                              *(u8 **)(action + 0x30), 2),
                0);
            btlPacketEnqueue(
                btlUnitCreateRotateTowardUnitPacket(*(u8 **)(action + 0x30),
                              (u8 *)partner->unit, 2),
                0);
            btlPacketEnqueue(
                (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)partner->unit, 0),
                1);
            btlPacketEnqueue(
                btlActionCreateLookAtUnitPacketBytes(*(u8 **)(action + 0x30),
                              (u8 *)partner->unit, 0),
                1);
            btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x30), 0);
            waitPacket = btlPacketAllocZeroed((s32)btlActionGetCounter420, (s32)action);
            btlPacketEnqueue(waitPacket, 1);
            btlPacketEnqueue(
                btlEffectCreateFormationPacket((s32)((BtlBattleState *)D_0076449C)->formations[35],
                              (s32)((BtlAction *)action)->unit, 0,
                              ((BtlPacketTiming *)waitPacket)->uid, 0xC000),
                2);
            if (btlTargetCanControlDamagePhase() == 1) {
                ((BtlBattleState *)D_0076449C)->flags |= 0x2000;
                btlDamageSetSource((u8 *)((BtlBattleState *)D_0076449C)->uiTask, 1);
            }
            ((BtlAction *)action)->unk_41c = 1;
        }
    } else if (*(s32 *)(action + 0x420) == 0) {
        if (btlMessageIsActiveAlt(((BtlBattleState *)D_0076449C)->uiTask) != 0) {
            if (btlMessageGetResultAlt(((BtlBattleState *)D_0076449C)->uiTask) != 0) {
                btlPacketEnqueue(func_001f99c0((u8 *)action, 8, 0, 0, 0), 1);
                effectPacket = btlCutinCreateStartPacket();
                ((BtlPacketTiming *)effectPacket)->dependencyKind = 0xA;
                ((BtlPacketCondition *)effectPacket)->value.id = 0xC00;
                ((BtlPacketTiming *)effectPacket)->actionUid = *(s64 *)action;
                btlPacketEnqueue(effectPacket, 1);
                btlPacketEnqueue(btlFormationCreateDefaultPacket(), 1);
            }
            btlPacketEnqueue(btlSoundReleaseTaskStart(), 1);
            ((BtlAction *)action)->unk_420 = 1;
            ((BtlAction *)action)->pursuitDelay = 6;
        }
    } else {
        waitFrames = *(u16 *)(action + 0x424);
        if (waitFrames == 0) {
            btlPacketEnqueue((u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3), 1);
            if (btlMessageGetResultAlt(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
                queuedAction = btlActionGetQueueFront();
                btlPacketEnqueue(btlTargetCreateActionPacket((u8 *)queuedAction, 2), 1);
                ((BtlAction *)queuedAction)->flags |= 0x8000;
                btlActionSetState((BtlAction *)action, 0xE);
            } else {
                btlActionSetState((BtlAction *)action, 0x20);
            }
            btlMessageResetAlt(((BtlBattleState *)D_0076449C)->uiTask);
            return;
        }
        ((BtlAction *)action)->pursuitDelay = waitFrames - 1;
    }
}

// FUN_001A4390
void btlActionPursuitInit(void)
{
}

/* Recovered action selection. Configured b210 -O2 emits 1092 retail bytes
 * plus 12 zero alignment bytes. The workspace keeps the signed element in
 * actual halfword storage and both twelve-entry target lists at their observed
 * 16-byte alignment. Scalarization is disabled for this storage; propagation
 * is disabled to preserve the unit load before the element's signed-word
 * promotion. The affinity provider retains its canonical s32 input. */
#pragma push
/* Keep the promoted shuffle count and output base at their explicit
 * phase boundaries. The index reference preserves each narrow read. */
/* Select eligible targets, preserving the reference action when required,
 * then queue voice, cut-in and dependent formation packets. Both local
 * target lists hold twelve entries; single-target selection requires
 * a nonempty eligible set. */
/* measured: func_001a43a0 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001A43A0
/* Raw action/unit accesses retain MATCH; separate scalar and unit-member rewrites both changed allocation. */
void btlActionPursuitUpdate(u8 *action)
{
    extern s8 datCalcGetBuffStatus(u8 *unit, s32 buffIndex);
    extern BtlPacket *btlVoiceCreatePacket(BtlAction *action, u16 callbackIndex, s32 argument, s32 extraArgument, s32 flags);
    struct {
        s16 element;
        u8 *preferred[12] __attribute__((aligned(16)));
        u8 *other[12] __attribute__((aligned(16)));
    } targets;
    u8 *candidate;
    u8 *referenceAction;
    u16 scanIndex;
    u16 otherCount;
    u16 preferredCount;
    u8 *workspace;
    u16 skill;
    s32 hasReferenceAction;
    u16 targetMode;
    s32 rawElement;
    u8 *task;

    if (btlCountUnitRecordsById(0xC00) != 0) {
        return;
    }
    referenceAction = ((BtlAction *)action)->parameters.supportTarget;
    skill = btlTargetGetStatusEffectMsgCode(action, referenceAction);
    targetMode = btlSkillClassifyTargets(action, action + 0x98, skill, 0);
    rawElement = datCalcSkillElement((u8*)((BtlUnit *)((BtlAction *)action)->unit)->datUnit, skill);
    hasReferenceAction = 0;
    otherCount = 0;
    preferredCount = 0;
    scanIndex = 0;
    targets.element = (s16)rawElement;
    for (; scanIndex < ((BtlAction *)action)->unk_d0; scanIndex++) {
        candidate = btlActionGetCandidate(action, &scanIndex);
        if (!(((BtlAction *)candidate)->unk_1a & 1)) {
            continue;
        }
        workspace = (u8*)((BtlAction *)candidate)->unit;
        if (datCalcIsDead(*(s32 *)(workspace + 0xA64), 0) != 0) {
            continue;
        }
        if (datCalcGetBuffStatus(*(u8 **)(workspace + 0xA64), 0x10) > 0) {
            continue;
        }
        {
            u8 *affinityUnit = *(u8 **)(workspace + 0xA64);
            s32 affinityElement = targets.element;

            if (datCalcGetElementAffinity(affinityUnit, affinityElement) & 0x7000000) {
                continue;
            }
        }
        if (datCalcChkBadStatus((s32)((BtlUnit *)workspace)->datUnit, 0x100000) == 0) {
            targets.preferred[preferredCount++] = candidate;
        }
        if (referenceAction != candidate) {
            targets.other[otherCount++] = candidate;
        } else {
            hasReferenceAction = 1;
        }
    }
    btlTargetResetCommandRecord(action + 0x38);
    ((BtlAction *)action)->unk_6c = 2;
    ((BtlAction *)action)->unk_6e = skill;
    if (targetMode == 0) {
        if (preferredCount > 0) {
            ((BtlAction *)action)->targets[0] = targets.preferred[datCalcRandomBelow(preferredCount)];
        } else if (hasReferenceAction) {
            ((BtlAction *)action)->targets[0] = referenceAction;
        } else {
            ((BtlAction *)action)->targets[0] = targets.other[datCalcRandomBelow(otherCount)];
        }
        ((BtlAction *)action)->unk_6a = 1;
    } else {
        s32 availableCount;
        s32 shuffleLimit;
        u16 outputStart;
        u16 shuffleIndex;

        shuffleIndex = 0;
        availableCount = otherCount;
        shuffleLimit = availableCount * 3;
        for (; shuffleIndex < shuffleLimit; shuffleIndex++) {
            u16 firstIndex = datCalcRandomBelow(availableCount);
            u16 secondIndex = datCalcRandomBelow(availableCount);

            if (firstIndex != secondIndex) {
                u8 *savedTarget = targets.other[firstIndex];

                targets.other[firstIndex] = targets.other[secondIndex];
                targets.other[secondIndex] = savedTarget;
            }
        }
        if (hasReferenceAction) {
            ((BtlAction *)action)->targets[0] = referenceAction;
            *(u16 *)(action + 0x6A) = 1;
            outputStart = 1;
        } else {
            ((BtlAction *)action)->unk_6a = 0;
            outputStart = 0;
        }
        if (availableCount > 1) {
            if (availableCount == 2) {
                otherCount = 1;
            } else {
                otherCount = datCalcRandomBelow(availableCount - 1) + 1;
            }
        }
        {
            u16 copyIndex;
            u8 *outputBase;
            s32 appendCount;

            copyIndex = 0;
            outputBase = action + outputStart * 4;
            appendCount = otherCount;
            for (; copyIndex < appendCount; copyIndex++) {
                *(u8 **)(outputBase + copyIndex * 4 + 0x38) = targets.other[copyIndex];
            }
        }
        ((BtlAction *)action)->unk_6a += otherCount;
    }
    ((BtlAction *)action)->flags |= 2;
    task = (u8 *)btlVoiceCreatePacket((BtlAction *)action, 9, 0, 0, 0);
    ((BtlPacket *)task)->actionUID = *(u64 *)action;
    btlPacketEnqueue(task, 1);
    workspace = btlCutinCreateEndPacket();
    ((BtlPacket *)workspace)->actionUID = *(u64 *)action;
    btlPacketEnqueue(workspace, 1);
    task = btlFormationCreateDefaultPacket();
    task[0] = 4;
    ((BtlPacketTiming *)task)->dependencyUid = ((BtlPacket *)workspace)->uid;
    btlPacketEnqueue(task, 1);
    btlActionSetState((BtlAction *)action, 0xF);
}

#pragma pop
// FUN_001A47F0
void btlActionReadyInit(void)
{
}

#pragma push
/* measured: b210 -O2 with this scoped setting emits 1148/1152 exact bytes.
 * The ushort counter wrap and offset-first helper preserve retail's operation
 * order. All 39 code relocations and the 52-byte switch table were resolved. */
/* measured: func_001a4800 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
// FUN_001A4800
/* Wait for the participating actions before dispatching the selected action
 * type and submitting its target-state and camera packets. */
/* Wait for participating actions, resolve the selected command, and choose its presentation state. */
/* Raw skill and readiness words lie in opaque shared spans; integer-address helpers preserve measured operand order. */
void btlActionReadyUpdate(u8 *actionBytes)
{
    extern void btlTargetSavePair(u8 *target);
    extern s32 btlActionSkillReachesTargets(u8 *action);
    extern void btlActionRollGroupRatio(s32 context);
    extern s32 btlSoundCanReceiveStatus(u8 *action);
    extern void btlUnitApplyPacketFlags(u8 *packet);
    s32 loopIndex;
    s32 delayFlag;
    s32 actionIndex;
    s32 personaId;
    u16 actionKind;
    u8 *otherAction;
    BtlBattleState *battleState;
    if (((s32)(btlCountUnitRecordsById(0x506)) == (s32)(0)) && ((s32)(btlCountUnitRecordsById(0xC05)) == (s32)(0))) {
        actionIndex = 0;
        while ((s32)(loopIndex = actionIndex & 0xFFFF) < (s32)(((BtlAction *)actionBytes)->unk_6a)) {
            otherAction = (u8 *)((((BtlAction *)actionBytes)->targets[actionIndex & 0xFFFF]));
            if ((s32)(actionBytes) == (s32)(otherAction)) {
                goto incr;
            }
            if (!((((BtlAction *)otherAction)->unk_1a) & 1)) {
                goto incr;
            }
            if (((s32)(datCalcIsDead(((s32)((BtlUnit *)((u8 *)(((s32)((BtlAction *)otherAction)->unit))))->datUnit), 0)) != (s32)(0))) {
                goto incr;
            }
            if ((((BtlAction *)otherAction)->currState) != 1) {
                goto donecheck;
            }
incr:
            actionIndex = (actionIndex + 1) & 0xFFFF;
        }
donecheck:
        if (loopIndex == (((BtlAction *)actionBytes)->unk_6a)) {
            if (!((((BtlAction *)actionBytes)->flags) & 4)) {
                btlTargetSavePair(actionBytes + 0x38);
            }
            (((BtlAction *)actionBytes)->flags) = (u16)((u16) ((((BtlAction *)actionBytes)->flags) & 0xFFFD));
            delayFlag = 0;
            actionKind = (u16)((u16)((((BtlAction *)actionBytes)->unk_6c)));
            switch (actionKind) {
            case 1:
            case 2:
            case 3:
                delayFlag = 1;
                /* fallthrough */
            case 9:
                btlTargetResolveSelectedSkill(actionBytes);
                if ((((DatSkillEntry *)btlActionAddAddressOffset(((BtlAction *)actionBytes)->unk_6e * 0x28, (s32)iGpffffb3b8))->kind24) == 5) {
                    btlActionSetState((BtlAction *)actionBytes, 0x20U);
                } else if ((((BtlAction *)actionBytes)->targetBlock.message.blocked) == 1) {
                    btlActionSetState((BtlAction *)actionBytes, 0x17U);
                } else if ((s32)(btlActionSkillReachesTargets(actionBytes)) != (s32)(0)) {
                    (((BtlAction *)actionBytes)->flags) = (u16)((u16) ((((BtlAction *)actionBytes)->flags) & 0xFFEF));
                    btlActionSetState((BtlAction *)actionBytes, 0x10U);
                } else {
                    (((BtlAction *)actionBytes)->flags) = (u16)((u16) ((((BtlAction *)actionBytes)->flags) | 0x10));
                    btlActionSetState((BtlAction *)actionBytes, 0x11U);
                }
                break;
            case 7:
            case 8:
            case 11:
                btlActionSetState((BtlAction *)actionBytes, 0x19U);
                break;
            case 6:
                if ((s32)((((BtlUnit *)((u8 *)((BtlAction *)actionBytes)->unit))->genus)) == (s32)(0)) {
                    if ((s32)(datGetFlag(0x38)) != (s32)(0)) {
                        personaId = 5;
                    } else {
                        personaId = 8;
                    }
                    if (((s32)(datPersonaFindSkillSlot((u8 *)datPersonaGetRecord(personaId & 0xFFFF), 0x114)) != (s32)(-1)) || ((battleState = (BtlBattleState *)iGpffffb3ac)->openingSide == 1 && (battleState->queueFlags & 2))) {
                        btlPacketEnqueue(btlActionCreateTargetPacketBytes(actionBytes, 8, 0, 0, 3), 1);
                        btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 8), 0);
                        btlActionSetDelayBytes(actionBytes, 0x1D, 0xC);
                    } else {
                        btlActionRollGroupRatio(0);
                        btlPacketEnqueue(btlActionCreateTargetPacketBytes(actionBytes, 3, 0, 0, 2), 1);
                        btlPacketEnqueue(btlTargetCreateActionPacket(actionBytes, 0U), 1);
                        btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 1), 0);
                        if ((s32)(btlSoundCanReceiveStatus(actionBytes)) != (s32)(0)) {
                            btlActionSetDelayBytes(actionBytes, 0x1B, 0xC);
                        } else {
                            btlActionSetDelayBytes(actionBytes, 0x20, 0xC);
                        }
                    }
                } else {
                    btlActionSetState((BtlAction *)actionBytes, 0x1DU);
                }
                break;
            case 12:
                btlActionSetState((BtlAction *)actionBytes, 0x1DU);
                break;
            case 5:
                btlActionSetState((BtlAction *)actionBytes, 0x1AU);
                break;
            case 10:
                btlActionSetState((BtlAction *)actionBytes, 7U);
                break;
            }
            if ((delayFlag != 0) && ((s32)(btlActionAnyTargetDownOrHitFlagged(actionBytes)) != (s32)(0))) {
                (((BtlAction *)actionBytes)->flags) = (u16)((u16) ((((BtlAction *)actionBytes)->flags) | 8));
            } else {
                (((BtlAction *)actionBytes)->flags) = (u16)((u16) ((((BtlAction *)actionBytes)->flags) & 0xFFF7));
            }
            btlUnitApplyPacketFlags(actionBytes);
        }
    }
}

#pragma pop
/* Measured 2026-09-30 with the coherent motion-provider family: 2336 bytes,
 * zero instruction differences. Both motion locals use the provider's u16
 * selector domain; no wide temporary or local ABI override is needed.
 * Scoped lifetime optimization and preserved assignments retain the range
 * predicate and speed-table control flow. Position and rotation providers
 * consume three and four floats respectively. Action actors are kind 0/1,
 * created by 0019f5f0; the selector's other retail cases remain intact. */
// FUN_001A4C80
#pragma push
/* measured: func_001a4c80 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: func_001a4c80 MATCH -> MISMATCH without this pragma. */
#pragma opt_dead_assignments off
/* Compute the source approach position and speed, retaining paired-target and encounter restrictions. */
/* Raw skill/enemy-table fields retain their measured offset-first indexing; shared tables lack these full record layouts. */
void btlActionMoveTargetInit(u8 *actionBytes)
{
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    extern void btlUnitGetGridSphereCenterTowardTarget(BtlUnit *unit, BtlUnit *target, RwV3d *outPosition);
    extern void btlUnitGetSlotPose(u8 *unit, u8 *anchorUnit, u8 *targetUnit, s32 motion,
                            f32 *outPosition, f32 *outRotation, s32 slot);
    extern void btlTargetBlendVectors(u8 *rotation, u8 *first, u8 *second);
    extern f32 RwV3dLength(const RwV3d *vector);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *vector);
    extern s32 datCalcEnemyHasExtendedFlag(u8 *unit);
    extern s32 btlActionAnyTargetHitRowFlagged(u8 *action);
    extern s32 btlActionAnyTargetFlagged(u8 *action);
    extern s32 btlActionHasNoTargetClass(u32 action);
    extern s32 btlEncounterSkipsPresentation(void);
    extern f32 fGpffff8360;
    union { RwV3d vector; f32 values[3]; } destination;
    RwV3d awayDirection;
    RwV3d homeOffset;
    RwV3d unitCenter;
    RwV3d targetCenter;
    f32 rotation[4];
    BtlAction *action;
    BtlUnit *unit;
    BtlUnit *targetUnit;
    u16 skill;
    s32 skillOffset;
    u8 *subunit;
    s32 proceed;
    s32 reposition;
    s32 inRange;
    s32 canPosition;
    f32 distance;
    f32 speed;

    action = (BtlAction *)actionBytes;
    skill = action->unk_6e;
    skillOffset = skill * 4;
    if ((*(u16 *)((u32)skillOffset + (u32)((u8 *)iGpffffb3bc) + 2) & 0x8000) != 0) {
        return;
    }
    if ((((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x2000) != 0) {
        return;
    }
    proceed = 1;
    inRange = 0;
    reposition = 0;
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateLookAtUnitPacket(NULL, (BtlUnit *)action->unit, 3);
        ((BtlPacket *)packet)->actionUID = action->uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket((BtlUnit *)action->unit, 0);
        ((BtlPacket *)packet)->actionUID = action->uid;
        btlPacketEnqueue(packet, 1);
    }
    action->flags |= 0x200;
    if ((((DatSkillEntry *)(iGpffffb3b8 + skill * 0x28))->flags00 & 2) != 0) {
        s32 pairedTargets;
        BtlUnit *predicateUnit;
        pairedTargets = btlActionAnyTargetFlagged((u8 *)action);
        predicateUnit = action->unit;
        do {
            switch (predicateUnit->genus) {
            case 0: {
                u8 *data;
                u16 unitId;
                s32 ranged;
                u32 rangeTable;
                u32 rangeOffset;
                data = ((u8 *)predicateUnit->datUnit);
                unitId = ((DatUnit *)data)->id;
                ranged = 1;
                switch (predicateUnit->genus) {
                case 0:
                    {
                        s32 classification;
                        classification = datCalcGetCharacterTableKind(data) & 0xFF;
                        if (classification == 5) {
                            ranged = 1;
                        } else if (classification == 3 && ((*(u16 *)((u32)skillOffset + (u32)((u8 *)iGpffffb3bc) + 2) & 0x8000) != 0 || pairedTargets == 0)) {
                            ranged = 1;
                        } else {
                            goto range_ineligible;
                        }
                    }
                    break;
                case 1:
                    rangeTable = (u32)iGpffffb3cc;
                    rangeOffset = (u32)unitId * 0xE8;
                    if (((BtlEnemyBattleParameters *)(rangeOffset + rangeTable))->cameraMode == 1) {
                        ranged = 1;
                    } else {
                        goto range_ineligible;
                    }
                    break;
                default:
range_ineligible:
                    ranged = 0;
                    break;
                }
                if (ranged != 0) {
                    BtlAction *rangeTarget;
                    rangeTarget = (*(BtlAction **)action->unk_38);
                    unit = action->unit;
                    targetUnit = rangeTarget->unit;
                    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) != 0 && unit->genus != targetUnit->genus) {
                        proceed = 0;
                    } else {
                        btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                        btlUnitGetGridSphereCenterTowardTarget((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                        if (btlTargetVectorDistance(&unitCenter, &targetCenter) < 500.0f) {
                            inRange = 1;
                            proceed = 0;
                        } else {
                            distance = 500.0f;
                        }
                    }
                    goto range_done;
                }
            }
            default:
                break;
            }
            {
                u16 motion;
                unit = action->unit;
                if (unit->genus == 0) {
                    if ((*(u16 *)((u32)skillOffset + (u32)((u8 *)iGpffffb3bc) + 2) & 0x8000) != 0) {
                        motion = 7;
                    } else if (pairedTargets != 0) {
                        motion = 5;
                    } else {
                        motion = (u16)(btlActionAnyTargetHitRowFlagged((u8 *)action) != 0 ? 0xC : 4);
                    }
                } else {
                    motion = (u16)(btlActionAnyTargetHitRowFlagged((u8 *)action) != 0 ? 0xC : 4);
                }
                distance = btlUnitGetMotionDistance((u8 *)action->unit, (u8 *)(*(BtlAction **)action->unk_38)->unit, motion);
            }
range_done:
            ;
        } while (0);
        if ((action->flags & 0x4000) != 0) {
            reposition = 1;
        }
    } else {
        unit = action->unit;
        switch (unit->genus) {
        case 0:
            {
                s32 paired;
                s32 openingMotion;
                targetUnit = (*(BtlAction **)action->unk_38)->unit;
                subunit = (u8 *)((BtlUnit *)((u8 *)unit))->childUnit;
                paired = btlActionHasNoTargetClass((u32)action);
                openingMotion = btlUnitOpeningMotionMode((s32)subunit, (u8 *)unit, (s16)skill, paired) & 0xFFFF;
                canPosition = btlTargetCanSelectEntry(subunit, (s16)skill, paired);
                btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                btlUnitGetGridSphereCenterTowardTarget((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                speed = btlTargetVectorDistance(&unitCenter, &targetCenter);
                speed = speed - unit->sphereRadius * unit->scale;
                speed = speed - targetUnit->sphereRadius * targetUnit->scale;
                if (canPosition == 0 || btlEncounterSkipsPresentation() == 0 || speed < 300.0f || speed - 300.0f < 200.0f) {
                    action->flags |= 0x10;
                    proceed = 0;
                } else {
                    speed = speed + unit->sphereRadius * unit->scale;
                    speed = speed + targetUnit->sphereRadius * targetUnit->scale;
                    btlUnitGetSlotPose(subunit, (u8 *)unit, (u8 *)targetUnit, (s16)openingMotion, destination.values, NULL, 2);
                    distance = btlTargetVectorDistance(&destination.vector, &targetCenter);
                    {
                        f32 limit;
                        limit = 300.0f;
                        limit = limit + unit->sphereRadius * unit->scale;
                        limit = limit + targetUnit->sphereRadius * targetUnit->scale;
                        if (distance < limit) {
                            distance = limit;
                        }
                    }
                    btlUnitGetSlotPose(subunit, (u8 *)unit, NULL, -1, destination.values, NULL, 0);
                    homeOffset.x = destination.vector.x - unitCenter.x;
                    homeOffset.z = destination.vector.z - unitCenter.z;
                    homeOffset.y = 0.0f;
                    distance = distance + RwV3dLength(&homeOffset);
                    if (speed < distance) {
                        action->flags |= 0x10;
                        proceed = 0;
                    }
                }
            }
            break;
        case 1:
            {
                u16 motion;
                motion = (u16)(btlActionAnyTargetHitRowFlagged((u8 *)action) != 0 ? 0xC : 4);
                distance = btlUnitGetMotionDistance((u8 *)action->unit, (u8 *)(*(BtlAction **)action->unk_38)->unit, motion);
            }
            break;
        }
    }
    if (proceed == 0) {
        return;
    }
    btlActionFinishPresentation((BtlAction *)action);
    {
        u16 speedIndex;
        u16 unitId;
        u16 speedVariant;
        u8 kind;
        u32 table;
        u32 offset;
        u32 record;
        u32 selector;
        u8 *packet;
        proceed = 0;
        speedIndex = 2;
        speedVariant = (u16)(!(((DatSkillEntry *)(iGpffffb3b8 + action->unk_6e * 0x28))->flags00 & 2));
        unit = action->unit;
        unitId = ((DatUnit *)unit->datUnit)->id;
        kind = unit->genus;
        switch (kind) {
        case 0:
            break;
        case 1:
            table = (u32)iGpffffb3cc;
            offset = (u32)unitId * 0xE8;
            record = offset + table;
            selector = (u16)speedVariant * 4;
            speedIndex = *(u16 *)(selector + record + 0x24);
            break;
        }
        speed = D_005F6D20[speedIndex];
        if (reposition == 1) {
            if (inRange == 0) {
                targetUnit = (*(BtlAction **)action->unk_38)->unit;
                btlUnitGetSphereWorldCenter((BtlUnit *)unit, &unitCenter);
                btlUnitGetGridSphereCenterTowardTarget((BtlUnit *)targetUnit, (BtlUnit *)unit, &targetCenter);
                awayDirection.x = unitCenter.x - targetCenter.x;
                awayDirection.z = unitCenter.z - targetCenter.z;
                awayDirection.y = 0.0f;
                RwV3dNormalize(&awayDirection, &awayDirection);
                {
                    f32 span;
                    span = unit->sphereRadius * unit->scale;
                    span = span + targetUnit->sphereRadius * targetUnit->scale;
                    span = span + distance;
                    span = span + 50.0f;
                    awayDirection.x = awayDirection.x * span;
                    awayDirection.y = awayDirection.y * span;
                    awayDirection.z = awayDirection.z * span;
                }
                destination.vector.x = targetCenter.x + awayDirection.x;
                destination.vector.y = targetCenter.y + awayDirection.y;
                destination.vector.z = targetCenter.z + awayDirection.z;
                destination.vector.y = unit->pos.y;
                btlTargetBlendVectors((u8 *)rotation, (u8 *)destination.values, (u8 *)&targetCenter);
                packet = btlUnitCreateOverridePacket((u8 *)unit, (u8 *)destination.values, (u8 *)rotation, NULL);
                ((BtlPacket *)packet)->actionUID = action->uid;
                btlPacketEnqueue(packet, 0);
                speed = speed * fGpffff8360;
                proceed = proceed | 8;
            } else {
                speed = speed * 1.25f;
            }
        }
        if (datCalcEnemyHasExtendedFlag(((u8 *)(*(BtlAction **)action->unk_38)->unit->datUnit)) == 0) {
            proceed = proceed | 0x40;
        }
        packet = (u8 *)btlUnitCreateMoveToUnitPacket((BtlUnit *)action->unit, (BtlUnit *)(*(BtlAction **)action->unk_38)->unit, distance, speed, proceed);
        ((BtlPacket *)packet)->actionUID = action->uid;
        btlPacketEnqueue(packet, 0);
        if (packet != NULL && inRange == 0) {
            if (reposition == 0) {
                packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x16);
                ((BtlPacket *)packet)->actionUID = action->uid;
                btlPacketEnqueue(packet, 0);
            } else {
                packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x17);
                ((BtlPacket *)packet)->actionUID = action->uid;
                btlPacketEnqueue(packet, 0);
            }
        }
        action->flags &= 0xFFEF;
    }
}

#pragma pop
// FUN_001A55A0
/* After source movement stops, dispatch the command to its attack, skill or alternate handler. */
void btlActionMoveTargetUpdate(BtlAction *action) {
    u16 actionState;

    if (btlUnitIsMoving((u8 *)((BtlAction *)action)->unit) == 0) {
        switch (((BtlAction *)action)->unk_6c) {
        case 1:
            actionState = 0x12;
            break;
        case 2:
        case 3:
            actionState = 0x13;
            break;
        case 9:
            actionState = 0x14;
            break;
        default:
            actionState = 0;
            break;
        }
        btlActionSetState(action, actionState);
    }
}

/* Measured: 656/656 bytes and 15 resolved relocations match retail.
 * Preserve unit/UID reloads across queue callbacks and the ordered distance test. */
#pragma push
/* measured: func_001a5650 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_001a5650 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001A5650
/* Return toward the anchor pose when necessary; otherwise dispatch the selected command immediately. */
/* Raw table words preserve the measured offset-first speed lookup; the action delay selector is loaded as a halfword. */
void btlActionMoveHomeInit(s64 *action)
{
    RwV3d destination;
    u32 recordOffset, recordAddress, variantOffset;
    f32 speed, scale;
    u16 slotIndex;
    u16 actionKind;
    u16 actionState;
    u16 speedIndex;
    u16 nextState;
    u16 recordIndex;
    u8 unitMode;
    u8 *battleUnit;
    u8 *movePacket;
    u8 *cameraPacket;
    u8 *tableBase;
    u8 *actionUnit;

    battleUnit = (u8 *)((BtlAction *)action)->unit;
    tableBase = D_0076449C;
    if (((s32)((BtlBattleState *)tableBase)->flags & 0x400000) &&
        (((BtlBattleState *)tableBase)->actionEndFlags & 2)) {
        recordIndex = ((BtlAction *)action)->unk_6c;
        switch (recordIndex) {
        case 1:
            actionState = 0x12;
            break;
        case 2:
        case 3:
            actionState = 0x13;
            break;
        case 9:
            actionState = 0x14;
            break;
        default:
            actionState = 0;
            break;
        }
        btlActionSetState((BtlAction *)action, actionState);
        return;
    }
    btlUnitGetAnchorPose(battleUnit, (u8 *)&destination, NULL, NULL);
    if (!(btlTargetVectorDistance((RwV3d *)(battleUnit + 4), &destination) <= 75.0f)) {
        btlActionFinishPresentation((BtlAction *)action);
        speedIndex = 2;
        slotIndex = (!(((DatSkillEntry *)iGpffffb3b8)[((BtlAction *)action)->unk_6e].flags00 & 2)) & 0xFFFF;
        actionUnit = (u8 *)((BtlAction *)action)->unit;
        recordIndex = ((DatUnit *)((BtlUnit *)actionUnit)->datUnit)->id;
        unitMode = ((BtlUnit *)actionUnit)->genus;
        switch (unitMode) {
        case 0:
            break;
        case 1:
            tableBase = iGpffffb3cc;
            recordOffset = recordIndex * 0xE8;
            recordAddress = recordOffset + (u32)tableBase;
            variantOffset = slotIndex * 4;
            speedIndex = *(u16 *)(variantOffset + recordAddress + 0x24);
            break;
        }
        speed = D_005F6D20[speedIndex];
        scale = D_0076144C;
        movePacket = (u8 *)btlUnitCreateMovePacket(
            (BtlUnit *)actionUnit, &destination,
            speed * scale, 0);
        ((BtlPacket *)movePacket)->actionUID = *action;
        btlPacketEnqueue(movePacket, 1);
        cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x18);
        ((BtlPacket *)cameraPacket)->actionUID = *action;
        btlPacketEnqueue(cameraPacket, 0);
        return;
    }
    actionKind = ((BtlAction *)action)->unk_6c;
    switch (actionKind) {
    case 1:
        nextState = 0x12;
        break;
    case 2:
    case 3:
        nextState = 0x13;
        break;
    case 9:
        nextState = 0x14;
        break;
    default:
        nextState = 0;
        break;
    }
    btlActionSetState((BtlAction *)action, nextState);
}

#pragma pop
// FUN_001A58E0
/* Wait for anchor movement to stop before dispatching the command handler. */
void btlActionMoveHomeUpdate(BtlAction *action) {
    u16 actionState;

    if (btlUnitIsMoving((u8 *)((BtlAction *)action)->unit) == 0) {
        switch (((BtlAction *)action)->unk_6c) {
        case 1:
            actionState = 0x12;
            break;
        case 2:
        case 3:
            actionState = 0x13;
            break;
        case 9:
            actionState = 0x14;
            break;
        default:
            actionState = 0;
            break;
        }
        btlActionSetState(action, actionState);
    }
}

// FUN_001A5990
void btlActionAttackInit(void)
{
}

/* 2026-10-03 storage repair: preserve action/packet UIDs as doublewords
   and select true 0x20-byte hit records. The old narrowing measurements above
   are historical, not type evidence. See Large_Battle_storage_20261003.md.
   2026-10-08: opt_loop_invariants on lowers fnalign from 837 to 752 edits.
 * 2026-10-09: 752 -> 709: the m2c label loops are while loops.
 * 696: range tests in retail's slti $at form.
 * 666: type sweep.
 * 660: swap sweep.
 * 652: type sweep.
 * 651: type sweep.
 * 646: temporary conversion lever (0, 2).
 * 642: temporary conversion lever (0, 2).
 * 2026-10-10: 642 -> 614 aligned edits by replacing seven undefined or
 * redundant sign-extension shifts with explicit signed-halfword/byte casts.
 * The local 001d15a0 provider returns s16; measured in battle lane scratch.
 * sdiff struct 413 -> 395: arg0 accessed through a u8 * local; the (u8 *)(s64 *) cast at every use made MWCC CSE and spill field addresses.
 * sdiff struct 395 -> 393: the two close-camera decisions through one inline helper (btlCloseCamera_001a59a0) instead of m2c's switch/goto copies.
 * fnalign 575 -> 545: the 0x13/0x10 selection as a flag test with the 0x13 call first (no goto block_224), as in func_001a7720.
 * fnalign 545 -> 527: the tail state switch (cases 1,3,2 and default both set state 0x20) as in the matched-path sibling 001a7720, with the real btlActionSetState(BtlAction *, u16) prototype (retail daddiu per arm, one shared call).
 * fnalign 527 -> 521: btlCloseCamera reads the unit id before the switch, sends every failing path to one shared result = 0 (default arm, goto fail) and tests the 0x8000 flag first (retail polarity).
 * fnalign 521 -> 493: integer-cast +0x30 unit reads at selected sites (b210 does not CSE the address across calls, as retail).
 * fnalign 493 -> 455: integer-cast field-base reads (no cross-call address CSE).
 * fnalign 455 -> 453: integer-cast field-base reads (second pass).
 * 2026-10-12 measured: fnalign 453 -> 452; the hit-effect flag is a word (retail sw/lw), not s16.
 * 2026-10-12 measured: fnalign 452 -> 405; let the timing APIs narrow their u16 motion argument, without a shared masked temporary.
 * 2026-10-12 measured: fnalign 405 -> 343; captured regalloc requires the source unit before the phase locals. Sound query contracts now match their providers.
 * 2026-10-12 frame audit: fnalign 343 -> 340, frame 0x3C0 -> 0x3B0; voice option is s32 and the target count is already bounded by u16, so no masked spill is needed.
 * 2026-10-12 row lifetime: fnalign 340 -> 335; retain the unbiased target-plus-hit-stride base, restoring retail's separate row spill and +0xF0 payload address (frame 0x3C0).
 * 2026-10-12 UID accessor: fnalign 335 -> 331, frame 0x3C0 -> 0x3B0; inline packet UID reads eliminate the cross-call +0x58 address spill.
 * 2026-10-12 kind accessor: fnalign 331 -> 327, frame 0x3B0 -> 0x3A0; reload the source-unit kind directly rather than spilling its field address.
 * 2026-10-12 effect-unit accessor: fnalign 327 -> 325; inline unit reads in the effect phase replace one spilled-address reload with retail's direct +0x30 load.
 * 2026-10-12 paired-effect unit: fnalign 325 -> 322; the first paired-effect constructor reloads its unit through the existing accessor rather than a spilled field address.
 * 2026-10-12 target layout: fnalign 322 -> 318, frame 0x3A0 -> 0x380; type the target action's effect/flags at 0xDC/0xDE, removing both hoisted field-address spills.
 * 2026-10-12 target unit member: fnalign 318 -> 309, frame 0x380 -> 0x370; recover the target's +0x30 unit field and remove its cross-call address spill.
 * 2026-10-12 selected-action layout: fnalign 309 -> 239, frame 0x370 -> 0x340; the selected action shares the typed +0x30 unit member, eliminating three quadword field-address spills and the redundant accessor.
 * 2026-10-12 animation packet type: fnalign 239 -> 218, frame 0x340 -> retail 0x330; keep the constructor's BtlPacket pointer type, avoiding a coalesced 16-byte byte-pointer spill.
 * 2026-10-12 hit-count consumers: fnalign 218 -> 214; preserve the signed-halfword normalization of the byte-loaded hit count and its conditional snapshot, matching retail's two sign extensions.
 * 2026-10-12 captured spill order: fnalign 214 -> 93, every frameslots offset now agrees at 0x330; declare the surviving packet/result pointers beside their aliases (b210 graph replay preserves their spill choices).
 * 2026-10-12 count/selector joins: fnalign 93 -> 88; keep the repeat-count snapshot signed and the branch-selected effect-table index full-width, removing two non-retail masks.
 * 2026-10-12 row phases: fnalign 88 -> 82; use unsigned byte-address indices inside both loops and recompute the hit-result view after the repeat phase, separate from the retained hitRow snapshot.
 * 2026-10-12 opening scan index: fnalign 82 -> 74; narrow the row index independently from the masked loop bound, preserving retail's separate halfword normalizations.
 * 2026-10-12 opening packet contract: fnalign 74 -> 72; use the matched sibling's BtlPacket *(u32, u16) constructor signature to preserve native halfword argument evaluation.
 * 2026-10-12 paired-target flag: fnalign 72 -> 70; normalize the masked flag before inverting it, matching retail's sltu/xori sequence.
 * 2026-10-12 motion dispatch: fnalign 70 -> 62; recover the two-case switch instead of the empty negated if, preserving retail's two positive tests and default jump.
 * 2026-10-12 camera table order: fnalign 62 -> 56; place the table base before the native halfword index so b210 evaluates the global load before scaling, as in both retail camera checks.
 * 2026-10-12 animation timing dispatch: fnalign 56 -> 54; restore the two-case delay switch, including its explicit default packet-delay path.
 * 2026-10-12 distance-packet address word: fnalign 54 -> 52; read the existing unit-address word at the integer ABI boundary instead of hoisting a pointer-to-integer conversion across the distance branch.
 * 2026-10-12 result-packet address word: fnalign 52 -> 50; likewise read the selected unit as the constructor's native integer address, restoring source/target argument materialization order.
 * 2026-10-12 camera reaching definitions: fnalign 50 -> 23; assign the predicate in each successful case rather than eagerly initializing it, matching both retail constant/load order and the case-1 success jump.
 * 2026-10-12 reaction reaching definitions: fnalign 23 -> 15; retain the truthy byte/random gate values and the ID comparison's shared one until the common decision test, without an extra boolean-result block.
 * 2026-10-12 post-repeat row accessor: fnalign 15 -> 8; reread the halfword index through the byte-row accessor, then retain the caller's typed result snapshot. Retail's lhu/move and every 0x330-frame offset now agree.
 * 2026-10-12 effect-index API: fnalign 8 -> 6; the canonical callee consumes only the skill key's low halfword and remains byte-exact with u16. Its sole C caller now materializes the native halfword argument in retail order.
 * 2026-10-12 camera field origin: fnalign 6 -> 4; pass the first signed-halfword field to the strided reader, preserving the GP load and both retail index-first addu operands. Four branch-target differences remain.
 * 2026-10-12 selected-target join: fnalign 4 -> 3; select into a separate target local before handing it to the packet phase. The coalesced copy retains retail's intermediate branch-only join without emitting an instruction.
 * 2026-10-12 reaction short circuits: fnalign 3 -> 0; stage the real gate values and jump directly to reaction construction on each shortcut. Only the fallback predicate passes through the common boolean test.
 */
#pragma push
/* measured: initial loop-invariant hoisting reduced fnalign from 837 to 752 edits. */
/* measured: func_001a59a0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001A59A0
/* Build attack animation, repeated-hit, reaction and result packet chains with their frame dependencies. */
/* Raw action/indexed-row offsets retain MATCH after canonical scalar rewrites; tagged packet sub-gates remain opaque. */
void btlActionAttackUpdate(s64 *actionWords) {
    u8 *actionBytes = (u8 *)actionWords;
    u8 *battleUnit;
    extern s64 btlPacketEnqueue(u8 *context, u32 value);
    extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern u8 *btlUnitCreateArcMovePacket();
    extern u8 *btlUnitCreateRotateTowardUnitPacket();
    extern u8 *btlCameraCreateSetStatePacket();
    /* Retail's call at 0x001A6F38 returns the packet in $v0, consumed by
       the +0/+8/+0x60 stores at 0x001A6F48..58. The provider's existing
       void spelling omits that live return; this pointer result is required. */
    extern u8 *btlCameraCreatePacketCommand(s32 value, s16 option, s32 first, s32 second);
    extern BtlPacket *btlFormationCreateMovePacket(u32 source, u32 target, f32 distance, u16 mode);
    extern u8 *btlFormationCreateWaitPacket();
    extern u8 *btlFormationCreatePacket();
    extern u16 btlTargetGetUnitIndex(BtlTarget *target);
    extern s32 btlTargetCheckUnitIdGroup();
    extern void btlTargetClearResultBuffer(u8 *result);
    extern s32 btlActionAnyTargetSpecialHit();
    extern s32 btlActionTargetsHaveDamageResult();
    extern u32 btlActionAnyTargetHasSpecialResult(u8 *action);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
    extern u8 *btlTargetCreateRecordPacket();
    extern u8 *btlTargetCreateTargetPacket();
    extern s32 btlSoundCanReceiveStatus();
    extern void btlSoundGetPrimaryVoiceSlots(u8 *unit, s32 actionKind, s32 special, s16 *bankOut, s16 *slotOut);
    extern void btlSoundGetSecondaryVoiceSlots(u8 *unit, u32 actionKind, s32 special, s16 *bankOut, s16 *slotOut);
    extern BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
    extern u8 *func_001f99c0(u8 *action, u16 voice, s32 option, s32 argument, s32 flags);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 sprite, u16 frame);
    extern u8 *btlPacketCreateEffectCounter();
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3cc;
    extern f32 fGpffff8128;
    extern f32 fGpffff8358;

    typedef struct BtlAttackTarget {
        u8 prefix[0x30];
        u8 *unit;         /* 0x30 */
        u8 unknown34[0xDC - 0x34];
        u16 effect;       /* 0xDC */
        u16 targetFlags;  /* 0xDE */
    } BtlAttackTarget;
    typedef struct BtlActionHitCursor {
        u8 actionPrefix[0xF0];
        LargeBattleHitResult result;
    } BtlActionHitCursor;
    s16 hitCue;
    s16 hitVariant;
    /* 001a0290 writes both signed halfword effect indices. */
    s16 effectIndices[2];
    /* The constructor copies ten bytes; mode 3 uses the first four. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    RwV3d targetPosition;
    LargeBattleHitResult result;
    BtlPacket *hitAnimPacketSaved;
    BtlPacket *hitAnimPacket;
    u8 *leadPacketSaved;
    u8 *leadPacket;
    u8 *counterAnimPacketSaved;
    u8 *counterAnimPacket;
    s64 hitPacketUid;
    s32 hitTiming;
    s32 hitMotion;
    s32 reactionUnitCount;
    s32 earlyDelta;
    s32 lateDelta;
    u16 hitIndexCounter;
    s32 unitFlag10E;
    s32 hasReaction;
    s32 hasTargetE4;
    s32 hasTargetFlags6;
    s32 isPrimaryHit;
    s32 setEffectFlags;
    s32 counterPending;
    s32 shortRangeFlag;
    u32 hitIndex;
    LargeBattleHitResult *hitResultSaved;
    LargeBattleHitResult *hitResultPtr;
    u16 targetIndex;
    u16 hitRowIndex;
    s32 actionFlagSaved;
    s32 hasCounterUnit;
    s32 baseDurationSaved;
    s32 animDuration;
    s32 timingValueWide;
    s32 timingValueShifted;
    s16 hitRowCount;
    s32 targetFlagDASaved;
    s32 hitCount;
    s32 lastHitIndex;
    s32 hitRowLimit;
    BtlActionHitCursor *hitRow;
    u32 *addedStatus;
    s32 reactionRoll;
    s32 counterUnitId;
    s32 hitRowNumber;
    s32 targetNumber;
    f32 timeScale;
    s32 timingAdjustment;
    f32 shortRangeDistance;
    s32 actionFlag;
    s16 counterUnitId16;
    s16 auxEffectIndex;
    s16 auxEffectIndexTarget;
    s32 hitTimingBase;
    s32 startDelay;
    s32 animDelay;
    s32 timingRemaining;
    s32 hitDelay;
    s32 counterDuration;
    s32 timingDelta;
    s32 targetRowIndex;
    s32 actionVariant;
    s32 hasStatusFlag;
    s32 hitEffectIndex;
    s32 reactionCueFlag;
    s32 closeCameraResult;
    s32 closeCameraResultB;
    s32 unitIndex;
    BtlAttackTarget *targetView;
    BtlAttackTarget *focusTarget;
    BtlAttackTarget *selectedTarget;
    s64 animUid;
    s64 actionUid;
    s32 timingValue16;
    s16 hitCountShort;
    s32 baseDuration;
    s32 reactionRemaining;
    s16 scaledBase;
    s32 timingValue;
    s32 actionDuration;
    s32 actionKind;
    s8 rowMotion;
    u16 targetCount;
    u32 randomRoll;
    s16 targetFlagDA;
    u8 *cameraEventPacket;
    u8 *cuePacket;
    u8 *effectPacket;
    u8 *effectPacketB;
    u8 *resultPacket;
    u8 *reactionPacket;
    u8 *rotatePacketTarget;
    u8 *actionPacket;
    u8 *rotatePacketFocus;
    u8 *cameraPacketFocus;
    u8 *movePacket;
    u8 *animPacketFocus;
    u8 *animPacketTarget;
    u8 *nearMovePacket;
    u8 *cuePacketB;
    u8 *rotatePacket;
    u8 *effectPacketC;
    u8 *cuePacketC;
    u8 *effectPacketD;
    u8 *cuePacketD;
    u8 *cuePacketE;
    u8 *cuePacketF;
    u8 *effectPacketE;
    u8 *effectPacketF;
    u8 *cuePacketG;
    u8 *cuePacketH;
    u8 *rotateToPointPacket;
    u8 *cuePacketI;
    u8 *effectPacketG;
    u8 *effectPacketH;
    u8 *effectPacketI;
    u8 *effectPacketJ;
    u8 *hitPacket;
    u8 *shakePacket;
    u8 *resultPacketB;
    u8 *statusPacket;
    u8 *statPacket;
    u8 *cuePacketJ;
    u8 *actionPacketB;
    u8 *reactionPacketB;
    u8 *reactionPacketC;
    u8 *actionPacketC;
    u8 *actionPacketD;
    u8 *unitStatePacket;
    u8 *unitStatePacketB;
    u8 *unitStatePacketC;
    u8 *unitStatePacketD;
    u8 *statePacket;
    u8 *battleStatePtrD;
    u8 *battleStatePtrB;
    u8 *cutinUnit;
    u8 *unitEntry;
    u8 *focusUnit;
    u8 *battleStatePtr;
    u8 *battleStatePtrC;
    u8 *focusUnitB;
    u8 *focusUnitC;
    u8 *focusUnitD;
    u8 *focusUnitE;
    u8 *targetRow;
    u8 *cameraPacket;
    u8 *effectPacketK;

    /* hitTimingBase init removed */
    btlActionFinishPresentation((BtlAction *)actionBytes);
    actionUid = (s64)(((s64)((BtlAction *)actionBytes)->uid));
    hitPacketUid = 0;
    battleUnit = (u8 *)((*(u8 **)(actionBytes + (0x30))));
    actionFlag = (s32)(s32)(((*(u16 *)(actionBytes + (0x18))) & 0x4000) != 0);
    actionFlagSaved = actionFlag;
    hasCounterUnit = (s32)(s32)((*(s64 **)(actionBytes + (0x88))) != NULL);
    if (actionFlag != 0) {
        timeScale = 1.75f;
    } else {
        timeScale = 1.0f;
    }
    reactionUnitCount = 0;
    unitFlag10E = 0;
    hasReaction = 0;
    hasStatusFlag = 0;
    hasTargetE4 = 0;
    hasTargetFlags6 = 0;
    counterPending = 0;
    setEffectFlags = 0;
    btlPacketEnqueue((u8 *)btlEffectCreateSpriteFramePacket((u32)battleUnit, (*(u16 *)(actionBytes + (0x6E)))), 3);
    btlActionGetEffectIndices((BtlAction *)actionBytes, (*(u16 *)(actionBytes + (0x6E))), (u8 *)effectIndices);
    if ((*(u16 *)(actionBytes + (0x6A))) == 1) {
        rotatePacket = (u8 *)(btlUnitCreateRotateTowardUnitPacket((*(u8 **)(actionBytes + (0x30))), ((u8*)((BtlAction *)((BtlAction *)actionBytes)->targets[0])->unit), 0));
        (((BtlPacketTiming *)rotatePacket)->actionUid) = actionUid;
        btlPacketEnqueue(rotatePacket, 0);
    } else {
        btlUnitGetGroupBounds(btlTargetGetUnitIndex((BtlTarget *)(actionBytes + 0x38)) & 0xFFFF, 1, &targetPosition, 0, 0, 1);
        rotateToPointPacket = (u8 *)(btlUnitCreateRotatePacket((((BtlAction *)actionBytes)->unit), &targetPosition, 0));
        (((BtlPacketTiming *)rotateToPointPacket)->actionUid) = actionUid;
        btlPacketEnqueue(rotateToPointPacket, 0);
    }
    unitIndex = 0;
    targetCount = (u16)((*(u16 *)(actionBytes + (0x6A))));
    while (((s32)unitIndex & 0xFFFF) < (s32) targetCount) {
        unitEntry = (u8 *)((((BtlAction *)actionBytes)->targets[unitIndex & 0xFFFF]));
        targetRowIndex = 0;
        while ((targetRowIndex & 0xFFFF) < (s32) (((BtlAction *)unitEntry)->targetBlock.hitRowCount)) {
            targetRow = (u8 *)(unitEntry + ((u16)targetRowIndex << 5));
            if (((s32)((BtlAction *)targetRow)->targetBlock.hitRows[0].addedStatus) & 0x100000) {
                hasStatusFlag = 1;
            }
            if ((((BtlAction *)targetRow)->targetBlock.hitRows[0].flags) & 4) {
                unitFlag10E = 1;
            }
            targetRowIndex = (targetRowIndex + 1) & 0xFFFF;
        }
        if ((((BtlAction *)unitEntry)->targetBlock.reactionFlag) != 0) {
            hasReaction = 1;
            reactionUnitCount += 1;
        }
        if ((((BtlAction *)unitEntry)->targetBlock.specialHitFlag) != 0) {
            hasTargetE4 = 1;
        }
        if ((((BtlAction *)unitEntry)->targetBlock.targetFlags) & 6) {
            hasTargetFlags6 = 1;
        }
        unitIndex = ((s32)unitIndex + 1) & 0xFFFF;
    }
    if (unitFlag10E != 0) {
        actionKind = 0xC;
        actionVariant = 0;
        setEffectFlags = 1;
    } else if (actionFlagSaved != 0) {
        actionKind = 4;
        actionVariant = 0;
    } else if (hasTargetFlags6 != 0) {
        actionKind = 5;
        actionVariant = 2;
        setEffectFlags = 1;
    } else {
        actionKind = 4;
        actionVariant = 0;
    }
    if ((hasStatusFlag == 1) && (actionFlagSaved == 0) && (targetCount == 1) && !((((BtlBattleState *)iGpffffb3ac)->battleFlags) & 0x2000)) {
        counterPending = 1;
    }
    if ((btlActionGetUnitGenus(battleUnit) != 0) || (actionKind == 4) || (actionKind == 0xC)) {
        actionDuration = btlUnitMotionFrames(battleUnit, actionKind, timeScale);
    } else {
        actionDuration = btlUnitMotionHitFrames(battleUnit, actionKind, timeScale, 0);
    }
    baseDuration = btlUnitMotionModelFrames(battleUnit, actionKind, timeScale);
    baseDurationSaved = (s32) baseDuration;
    /* Retail truncates the scaled difference, caps it at 25, then narrows each sum. */
    timingValue = (s16)actionDuration;
    if (actionDuration < baseDuration) {
        timingAdjustment = (s32)(fGpffff8128 * (f32)(baseDuration - actionDuration));
        if (timingAdjustment > 0x19) {
            timingAdjustment = 25;
        }
        timingValue = (s16)(timingValue + (s16)timingAdjustment);
    }
    if ((hasReaction != 0) || (hasTargetE4 != 0)) {
        timingValue = (s16)(timingValue + 8);
    }
    if (hasCounterUnit != 0) {
        counterDuration = (btlUnitMotionModelFrames(((u8*)((BtlAction *)((BtlAction *)actionBytes)->parameters.followUp)->unit), 0x1A, 1.0f)) - 4;
        if (actionDuration < counterDuration) {
            earlyDelta = counterDuration - actionDuration;
            lateDelta = 0;
        } else {
            earlyDelta = 0;
            lateDelta = actionDuration - counterDuration;
        }
        timingValue = (s16)(timingValue + 0xC);
    } else {
        earlyDelta = 0;
        lateDelta = 0;
    }
    leadPacket = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)battleUnit, (s16)actionKind, 0, timeScale, actionVariant & 0xFFFF));
    leadPacketSaved = (u8 *)(leadPacket);
    (((BtlPacketTiming *)leadPacket)->delay) = (s16) earlyDelta;
    (((BtlPacketTiming *)leadPacket)->actionUid) = actionUid;
    btlPacketEnqueue(leadPacket, 0);
    animUid = ((BtlPacketTiming *)leadPacket)->uid;
    if (hasCounterUnit == 0) {
        if ((((BtlAction *)actionBytes)->unk_6a) == 1) {
            if (btlActionGetUnitGenus(battleUnit) == 0) {
                if (((hasTargetFlags6 == 0) && (hasStatusFlag == 0)) || (actionFlagSaved == 1)) {
                    closeCameraResult = btlActionUsesCloseCamera((u8*)((BtlAction *)actionBytes)->unit, hasTargetFlags6);
                    if (closeCameraResult != 0) {
                        cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0xC));
                    } else {
                        cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0xB));
                    }
                } else {
                    cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0x10));
                }
            } else if ((hasStatusFlag == 0) || (actionFlagSaved == 1)) {
                closeCameraResultB = btlActionUsesCloseCamera((u8*)((BtlAction *)actionBytes)->unit, hasTargetFlags6);
                if (closeCameraResultB != 0) {
                    cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0xC));
                } else {
                    cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0xB));
                }
            } else {
                cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0xD));
            }
        } else {
            cameraPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0x2C));
        }
        (((BtlPacketTiming *)cameraPacket)->dependencyKind) = 5;
        (((BtlPacketTiming *)cameraPacket)->dependencyUid) = animUid;
        (((BtlPacketTiming *)cameraPacket)->actionUid) = actionUid;
        btlPacketEnqueue(cameraPacket, 0);
    }
    if (unitFlag10E != 0) {
        if (actionDuration > 6) {
            startDelay = actionDuration - 6;
        } else {
            startDelay = 0;
        }
        animDuration = (s32) (btlUnitMotionFollowFrames(battleUnit, actionKind, timeScale));
        if (btlActionGetUnitGenus(battleUnit) == 0) {
            cameraEventPacket = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0xE));
            (((BtlPacketTiming *)cameraEventPacket)->dependencyKind) = 4;
            (((BtlPacketTiming *)cameraEventPacket)->dependencyUid) = (s64) (((BtlPacketTiming *)leadPacketSaved)->uid);
            (((BtlPacketTiming *)cameraEventPacket)->delay) = startDelay;
            (((BtlPacketTiming *)cameraEventPacket)->actionUid) = actionUid;
            btlPacketEnqueue(cameraEventPacket, 0);
        }
        cuePacket = (u8 *)(btlSoundCreateChannelCuePacket(0xC, 2, 9));
        (((BtlPacketTiming *)cuePacket)->dependencyKind) = 5;
        (((BtlPacketTiming *)cuePacket)->dependencyUid) = animUid;
        if (animDuration > 8) {
            animDelay = animDuration - 8;
        } else {
            animDelay = 0;
        }
        (((BtlPacketTiming *)cuePacket)->delay) = animDelay;
        (((BtlPacketTiming *)cuePacket)->actionUid) = actionUid;
        btlPacketEnqueue(cuePacket, 1);
        effectPacket = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[31]), battleUnit, battleUnit, 1, 0));
        (((BtlPacketTiming *)effectPacket)->dependencyKind) = 5;
        (((BtlPacketTiming *)effectPacket)->dependencyUid) = animUid;
        (((BtlPacketTiming *)effectPacket)->delay) = (s16) animDuration;
        (((BtlPacketTiming *)effectPacket)->actionUid) = actionUid;
        btlPacketEnqueue(effectPacket, 2);
        effectPacketB = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[28]), battleUnit, battleUnit, 1, 0));
        (((BtlPacketTiming *)effectPacketB)->dependencyKind) = 5;
        (((BtlPacketTiming *)effectPacketB)->dependencyUid) = animUid;
        (((BtlPacketTiming *)effectPacketB)->delay) = startDelay;
        (((BtlPacketTiming *)effectPacketB)->actionUid) = actionUid;
        btlPacketEnqueue(effectPacketB, 2);
        btlTargetClearResultBuffer((u8 *)&result);
        result.addedStatus = 0x100000;
        resultPacket = (u8 *)(btlTargetCreateDataPacket((s32)(actionBytes), (s32)(actionBytes), &result, 1U, 1U));
        (((BtlPacketTiming *)resultPacket)->dependencyKind) = 5;
        (((BtlPacketTiming *)resultPacket)->dependencyUid) = animUid;
        scaledBase = (s16)baseDurationSaved;
        (((BtlPacketTiming *)resultPacket)->delay) = (s16) (scaledBase - (scaledBase >> 2));
        (((BtlPacketTiming *)resultPacket)->actionUid) = actionUid;
        btlPacketEnqueue(resultPacket, 1);
        if ((actionFlagSaved == 0) && ((((BtlUnit *)((u8 *)(((u8*)((BtlAction *)actionBytes)->unit))))->genus) == 0)) {
            reactionPacket = (u8 *)(btlTargetCreateTargetPacket(actionBytes, 0x19, 0, 0, 0));
            (((BtlPacketTiming *)reactionPacket)->dependencyKind) = 4;
            (((BtlPacketTiming *)reactionPacket)->dependencyUid) = (s64) (((BtlPacketTiming *)resultPacket)->uid);
            (((BtlPacketTiming *)reactionPacket)->actionUid) = actionUid;
            btlPacketEnqueue(reactionPacket, 1);
        }
    }
    targetIndex = 0;
    timingValue16 = (s16)timingValue;
    timingValueWide = (s32) timingValue16;
    timingValueShifted = timingValue16 + 0xC;
    while ((targetNumber = (s32) targetIndex) < (s32) (*(u16 *)(actionBytes + (0x6A)))) {
        targetView = (BtlAttackTarget *)((((BtlAction *)actionBytes)->targets[targetIndex]));
        hitRowCount = ((BtlAction *)targetView)->targetBlock.hitRowCount;
        if (actionFlagSaved != 0) {
            targetFlagDA = 1;
        } else {
            targetFlagDA = (u8)((((BtlAction *)targetView)->targetBlock.hitRepeatCount));
        }
        targetFlagDASaved = targetFlagDA;
        hitTiming = (s32) actionDuration;
        if (actionDuration > 3) {
            hitTimingBase = actionDuration - 3;
        } else {
            hitTimingBase = 0;
        }
        if (hasCounterUnit == 0) {
            rotatePacketTarget = (u8 *)(btlUnitCreateRotateTowardUnitPacket(targetView->unit, battleUnit, 2));
            (((BtlPacketTiming *)rotatePacketTarget)->dependencyKind) = 5;
            (((BtlPacketTiming *)rotatePacketTarget)->dependencyUid) = animUid;
            (((BtlPacketTiming *)rotatePacketTarget)->delay) = hitTimingBase;
            (((BtlPacketTiming *)rotatePacketTarget)->flags) = (u8) ((((BtlPacketTiming *)rotatePacketTarget)->flags) & 0xDF);
            (((BtlPacketTiming *)rotatePacketTarget)->actionUid) = actionUid;
            btlPacketEnqueue(rotatePacketTarget, 1);
            if ((((BtlAction *)targetView)->targetBlock.specialHitFlag) != 0) {
                selectedTarget = (BtlAttackTarget *)actionBytes;
            } else {
                selectedTarget = targetView;
            }
            focusTarget = selectedTarget;
        } else {
            focusTarget = (BtlAttackTarget *)((((BtlAction *)actionBytes)->parameters.followUp));
            actionPacket = (u8 *)(func_001f99c0((u8 *)focusTarget, 0xD, 0U, 0, 0));
            (((BtlPacketTiming *)actionPacket)->delay) = (s16) lateDelta;
            (((BtlPacketTiming *)actionPacket)->actionUid) = actionUid;
            btlPacketEnqueue(actionPacket, 1);
            rotatePacketFocus = (u8 *)(btlUnitCreateRotateTowardUnitPacket(targetView->unit, battleUnit, 2));
            (((BtlPacketTiming *)rotatePacketFocus)->delay) = (s16) lateDelta;
            (((BtlPacketTiming *)rotatePacketFocus)->actionUid) = actionUid;
            btlPacketEnqueue(rotatePacketFocus, 0);
            cameraPacketFocus = (u8 *)(btlCameraCreateSetStatePacket(actionBytes, 0x11));
            (((BtlPacketTiming *)cameraPacketFocus)->delay) = (s16) lateDelta;
            (((BtlPacketTiming *)cameraPacketFocus)->actionUid) = actionUid;
            (((BtlPacketTiming *)cameraPacketFocus)->duration) = (s16) timingValueShifted;
            btlPacketEnqueue(cameraPacketFocus, 0);
            movePacket = (u8 *)(btlFormationCreateWaitPacket(focusTarget->unit, targetView->unit, 2));
            (((BtlPacketTiming *)movePacket)->delay) = (s16) lateDelta;
            (((BtlPacketTiming *)movePacket)->actionUid) = actionUid;
            btlPacketEnqueue(movePacket, 0);
            animPacketFocus = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)focusTarget->unit, 0x1A, 0, 1.0f, 0));
            (((BtlPacketTiming *)animPacketFocus)->delay) = (s16) lateDelta;
            (((BtlPacketTiming *)animPacketFocus)->actionUid) = actionUid;
            btlPacketEnqueue(animPacketFocus, 0);
            animPacketTarget = (u8 *)(btlUnitCreateAnimPacket((BtlUnit *)targetView->unit, 0x1A, 0, 1.0f, 2));
            (((BtlPacketTiming *)animPacketTarget)->delay) = (s16) lateDelta;
            (((BtlPacketTiming *)animPacketTarget)->actionUid) = actionUid;
            btlPacketEnqueue(animPacketTarget, 0);
            setEffectFlags = 1;
        }
        if (btlActionGetUnitGenus(battleUnit) == 0) {
            if ((btlTargetCheckUnitIdGroup(battleUnit) != 0) && (focusUnit = focusTarget->unit, ((((BtlUnit *)((u8 *)(focusUnit)))->genus) == 1))) {
                shortRangeFlag = (s32)(((((BtlEnemyBattleParameters *)(((s32)iGpffffb3cc) + ((((BtlUnit *)((u8 *)(focusUnit)))->charId) * 0xE8)))->flags) & 0x40) != 0) ^ 1;
            } else {
                shortRangeFlag = 0;
            }
        } else {
            shortRangeFlag = 0;
        }
        if ((counterPending == 1) && (targetNumber == 0) && (btlActionGetUnitGenus(battleUnit) == 0) && ((((BtlAction *)actionBytes)->unk_6a) == 1) && (hasReaction == 0)) {
            if (shortRangeFlag != 0) {
                shortRangeDistance = fGpffff8358;
            } else {
                shortRangeDistance = 400.0f;
            }
            nearMovePacket = (u8 *)(btlFormationCreateMovePacket((u32)battleUnit, *(u32 *)&targetView->unit, shortRangeDistance, 3));
            (((BtlPacketTiming *)nearMovePacket)->dependencyKind) = 5;
            (((BtlPacketTiming *)nearMovePacket)->dependencyUid) = animUid;
            (((BtlPacketTiming *)nearMovePacket)->actionUid) = actionUid;
            btlPacketEnqueue(nearMovePacket, 0);
            setEffectFlags = 1;
        }
        hitRowIndex = 0;
        hitCountShort = (s16)targetFlagDASaved;
        hitCount = (s32) hitCountShort;
        lastHitIndex = hitCountShort - 1;
        hitRowLimit = (s16)hitRowCount;
        while ((hitRowNumber = (s32) hitRowIndex) < hitRowLimit) {
            hitIndexCounter = 0;
            hitRow = (BtlActionHitCursor *)((u8 *)targetView + ((u32)hitRowIndex << 5));
            while ((s32)(hitIndex = (s32) hitIndexCounter) < hitCount) {
                rowMotion = hitRow->result.motion;
                hitMotion = (s32) rowMotion;
                switch (rowMotion) {
                case 9:
                case 0x13:
                    if (hitIndex != lastHitIndex) {
                        hitMotion = 2;
                    }
                    break;
                }
                if ((targetView->effect & 0x404) || (hitRow->result.flags & 4)) {
                    isPrimaryHit = 0;
                } else {
                    isPrimaryHit = 1;
                }
                hitAnimPacket = (BtlPacket *)(btlUnitCreateAnimPacket((BtlUnit *)focusTarget->unit, (s16)hitMotion, 0, 1.0f, 0));
                hitAnimPacketSaved = hitAnimPacket;
                (((BtlPacketTiming *)hitAnimPacket)->dependencyKind) = 5;
                (((BtlPacketTiming *)hitAnimPacket)->dependencyUid) = animUid;
                switch (hitMotion) {
                case 0x17:
                case -3:
                    if (hitTiming > 6) {
                        hitDelay = hitTiming - 6;
                    } else {
                        hitDelay = 0;
                    }
                    (((BtlPacketTiming *)hitAnimPacketSaved)->delay) = hitDelay;
                    break;
                default:
                    (((BtlPacketTiming *)hitAnimPacketSaved)->delay) = (s16) hitTiming;
                    break;
                }
                if ((*(s32 *)((u8 *)(u32)(targetView) + (0xE4))) != 0) {
                    (((BtlPacketTiming *)hitAnimPacketSaved)->delay) = (s16) ((((BtlPacketTiming *)hitAnimPacketSaved)->delay) + 5);
                    hitTimingBase += 5;
                }
                (((BtlPacketTiming *)hitAnimPacketSaved)->actionUid) = actionUid;
                btlPacketEnqueue((u8 *)hitAnimPacketSaved, 0);
                hitPacketUid = ((BtlPacketTiming *)hitAnimPacketSaved)->uid;
                if ((targetView->effect & 4) && (unitFlag10E == 0)) {
                    cuePacketB = (u8 *)(btlSoundCreateChannelCuePacket(0xD, 1, 0xF));
                    (((BtlPacketTiming *)cuePacketB)->dependencyKind) = 5;
                    (((BtlPacketTiming *)cuePacketB)->dependencyUid) = animUid;
                    (((BtlPacketTiming *)cuePacketB)->delay) = (s16) hitTiming;
                    btlPacketEnqueue(cuePacketB, 1);
                }
                if ((((BtlAction *)targetView)->targetBlock.specialHitFlag) != 0) {
                    effectPacketC = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[9]), battleUnit, targetView->unit, 1, 0));
                    (((BtlPacketTiming *)effectPacketC)->dependencyKind) = 5;
                    (((BtlPacketTiming *)effectPacketC)->dependencyUid) = animUid;
                    (((BtlPacketTiming *)effectPacketC)->delay) = (s16) hitTiming;
                    btlPacketEnqueue(effectPacketC, 1);
                    cuePacketC = (u8 *)(btlSoundCreateChannelCuePacket(0xD, 2, 0xB));
                    (((BtlPacketTiming *)cuePacketC)->dependencyKind) = 5;
                    (((BtlPacketTiming *)cuePacketC)->dependencyUid) = animUid;
                    (((BtlPacketTiming *)cuePacketC)->delay) = (s16) hitTiming;
                    btlPacketEnqueue(cuePacketC, 1);
                }
                if (targetView->effect == 0x400) {
                    effectPacketD = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[10]), battleUnit, focusTarget->unit, 1, 0));
                    (((BtlPacketTiming *)effectPacketD)->dependencyKind) = 5;
                    (((BtlPacketTiming *)effectPacketD)->dependencyUid) = hitPacketUid;
                    btlPacketEnqueue(effectPacketD, 1);
                    cuePacketD = (u8 *)(btlSoundCreateChannelCuePacket(0xC, 2, 0xC));
                    (((BtlPacketTiming *)cuePacketD)->dependencyKind) = 5;
                    (((BtlPacketTiming *)cuePacketD)->dependencyUid) = hitPacketUid;
                    btlPacketEnqueue(cuePacketD, 1);
                }
                btlSoundGetPrimaryVoiceSlots(battleUnit, hitIndex, hasTargetFlags6, &hitCue, &hitVariant);
                if ((hitCue >= 0) && (hitVariant >= 0)) {
                    cuePacketE = (u8 *)(btlSoundCreateChannelCuePacket(0xD, hitCue, hitVariant));
                    (((BtlPacketTiming *)cuePacketE)->dependencyKind) = 5;
                    (((BtlPacketTiming *)cuePacketE)->dependencyUid) = animUid;
                    (((BtlPacketTiming *)cuePacketE)->delay) = hitTimingBase;
                    btlPacketEnqueue(cuePacketE, 1);
                }
                if (isPrimaryHit != 0) {
                    if ((targetView->targetFlags & 6) && (actionFlagSaved == 0)) {
                        if (hitIndex != lastHitIndex) {
                            effectPacketK = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[6]), battleUnit, focusTarget->unit, 1, 0));
                        } else {
                            effectPacketK = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[7]), battleUnit, focusTarget->unit, 1, 0));
                        }
                        (((BtlPacketTiming *)effectPacketK)->dependencyKind) = 5;
                        (((BtlPacketTiming *)effectPacketK)->dependencyUid) = animUid;
                        (((BtlPacketTiming *)effectPacketK)->delay) = hitTimingBase;
                        (((BtlPacketTiming *)effectPacketK)->actionUid) = actionUid;
                        btlPacketEnqueue(effectPacketK, 2);
                        if (hitIndex == lastHitIndex) {
                            cuePacketF = (u8 *)(btlSoundCreateChannelCuePacket(0xC, 0, 9));
                            (((BtlPacketTiming *)cuePacketF)->dependencyKind) = 5;
                            (((BtlPacketTiming *)cuePacketF)->dependencyUid) = animUid;
                            (((BtlPacketTiming *)cuePacketF)->delay) = hitTimingBase;
                            btlPacketEnqueue(cuePacketF, 1);
                        }
                    }
                    effectPacketE = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[effectIndices[0]]), battleUnit, focusTarget->unit, 1, 0));
                    (((BtlPacketTiming *)effectPacketE)->dependencyKind) = 5;
                    (((BtlPacketTiming *)effectPacketE)->dependencyUid) = animUid;
                    (((BtlPacketTiming *)effectPacketE)->delay) = hitTimingBase;
                    btlPacketEnqueue(effectPacketE, 2);
                    if (effectIndices[1] >= 0) {
                        effectPacketF = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[effectIndices[1]]), battleUnit, focusTarget->unit, 1, 0));
                        (((BtlPacketTiming *)effectPacketF)->dependencyKind) = 5;
                        (((BtlPacketTiming *)effectPacketF)->dependencyUid) = animUid;
                        (((BtlPacketTiming *)effectPacketF)->delay) = hitTimingBase;
                        btlPacketEnqueue(effectPacketF, 2);
                    }
                    if (actionFlagSaved == 0) {
                        btlSoundGetSecondaryVoiceSlots(battleUnit, hitIndex, hasTargetFlags6, &hitCue, &hitVariant);
                        if ((hitCue >= 0) && (hitVariant >= 0)) {
                            cuePacketG = (u8 *)(btlSoundCreateChannelCuePacket(0xA, hitCue, hitVariant));
                            (((BtlPacketTiming *)cuePacketG)->dependencyKind) = 5;
                            (((BtlPacketTiming *)cuePacketG)->dependencyUid) = animUid;
                            (((BtlPacketTiming *)cuePacketG)->delay) = hitTimingBase;
                            btlPacketEnqueue(cuePacketG, 1);
                        }
                        if ((hitIndex == lastHitIndex) && ((((BtlAction *)targetView)->targetBlock.reactionFlag) == 0) && (hitRow->result.addedStatus & 0x7FFFE)) {
                            cuePacketH = (u8 *)(btlSoundCreateChannelCuePacket(0xF, 2, 0xF));
                            (((BtlPacketTiming *)cuePacketH)->dependencyKind) = 5;
                            (((BtlPacketTiming *)cuePacketH)->dependencyUid) = animUid;
                            (((BtlPacketTiming *)cuePacketH)->delay) = hitTimingBase;
                            btlPacketEnqueue(cuePacketH, 1);
                        }
                    } else {
                        cuePacketI = (u8 *)(btlSoundCreateChannelCuePacket(0xA, 2, 0x14));
                        (((BtlPacketTiming *)cuePacketI)->dependencyKind) = 5;
                        (((BtlPacketTiming *)cuePacketI)->dependencyUid) = animUid;
                        (((BtlPacketTiming *)cuePacketI)->delay) = hitTimingBase;
                        btlPacketEnqueue(cuePacketI, 1);
                    }
                    effectPacketG = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[8]), battleUnit, focusTarget->unit, 1, 0));
                    (((BtlPacketTiming *)effectPacketG)->dependencyKind) = 5;
                    (((BtlPacketTiming *)effectPacketG)->dependencyUid) = animUid;
                    (((BtlPacketTiming *)effectPacketG)->delay) = hitTimingBase;
                    btlPacketEnqueue(effectPacketG, 2);
                }
                if (hitIndex != lastHitIndex) {
                    timingDelta = (btlUnitMotionHitFrames(battleUnit, actionKind, timeScale, (hitIndex + 1) & 0xFFFF)) - hitTiming;
                    hitTiming += timingDelta;
                    hitTimingBase += timingDelta;
                } else if ((counterPending != 0) && ((((BtlAction *)targetView)->targetBlock.reactionFlag) == 0)) {
                    if (shortRangeFlag != 0) {
                        hitEffectIndex = 0x1D;
                    } else {
                        hitEffectIndex = 0x1E;
                    }
                    focusUnitB = (u8 *)(focusTarget->unit);
                    counterAnimPacket = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[hitEffectIndex]), focusUnitB, focusUnitB, 1, 0));
                    counterAnimPacketSaved = (u8 *)(counterAnimPacket);
                    (((BtlPacketTiming *)counterAnimPacket)->dependencyKind) = 5;
                    (((BtlPacketTiming *)counterAnimPacket)->dependencyUid) = hitPacketUid;
                    (((BtlPacketTiming *)counterAnimPacket)->delay) = 1;
                    (((BtlPacketTiming *)counterAnimPacket)->actionUid) = actionUid;
                    btlPacketEnqueue(counterAnimPacket, 2);
                    if (shortRangeFlag != 0) {
                        focusUnitC = (u8 *)(focusTarget->unit);
                        effectPacketH = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[32]), focusUnitC, focusUnitC, 1, 0));
                        (((BtlPacketTiming *)effectPacketH)->dependencyKind) = 5;
                        (((BtlPacketTiming *)effectPacketH)->dependencyUid) = (s64) btlActionGetPacketUid(counterAnimPacketSaved);
                        (((BtlPacketTiming *)effectPacketH)->actionUid) = actionUid;
                        btlPacketEnqueue(effectPacketH, 2);
                        focusUnitD = (u8 *)(focusTarget->unit);
                        effectPacketI = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[31]), focusUnitD, focusUnitD, 1, 0));
                        (((BtlPacketTiming *)effectPacketI)->dependencyKind) = 5;
                        (((BtlPacketTiming *)effectPacketI)->dependencyUid) = (s64) btlActionGetPacketUid(counterAnimPacketSaved);
                        (((BtlPacketTiming *)effectPacketI)->delay) = 0x14;
                        (((BtlPacketTiming *)effectPacketI)->actionUid) = actionUid;
                        btlPacketEnqueue(effectPacketI, 2);
                        focusUnitE = (u8 *)(focusTarget->unit);
                        effectPacketJ = (u8 *)(btlFormationCreatePacket(((s32)((BtlBattleState *)iGpffffb3ac)->formations[31]), focusUnitE, focusUnitE, 1, 0));
                        (((BtlPacketTiming *)effectPacketJ)->dependencyKind) = 5;
                        (((BtlPacketTiming *)effectPacketJ)->dependencyUid) = (s64) btlActionGetPacketUid(counterAnimPacketSaved);
                        (((BtlPacketTiming *)effectPacketJ)->delay) = 0x1A;
                        (((BtlPacketTiming *)effectPacketJ)->actionUid) = actionUid;
                        btlPacketEnqueue(effectPacketJ, 2);
                    } else {
                        hitPacket = (u8 *)(btlUnitCreateArcMovePacket(focusTarget->unit, (s16) (((BtlAction *)actionBytes)->unk_6e), 0));
                        (((BtlPacketTiming *)hitPacket)->dependencyKind) = 5;
                        (((BtlPacketTiming *)hitPacket)->dependencyUid) = (s64) btlActionGetPacketUid(counterAnimPacketSaved);
                        (((BtlPacketTiming *)hitPacket)->actionUid) = actionUid;
                        btlPacketEnqueue(hitPacket, 1);
                        shakePacket = (u8 *)(btlCameraCreatePacketCommand(0x14, 0x32, 0, 5));
                        (((BtlPacketTiming *)shakePacket)->dependencyKind) = 5;
                        (((BtlPacketTiming *)shakePacket)->dependencyUid) = (s64) btlActionGetPacketUid(counterAnimPacketSaved);
                        (((BtlPacketTiming *)shakePacket)->actionUid) = actionUid;
                        btlPacketEnqueue(shakePacket, 1);
                    }
                }
                hitIndexCounter += 1;
            }
            hitResultPtr = (LargeBattleHitResult *)btlActionGetIndexedHitResult((u8 *)targetView, &hitRowIndex);
            hitResultSaved = hitResultPtr;
            resultPacketB = (u8 *)(btlTargetCreateDataPacket((s32)(actionBytes), (s32)(focusTarget), hitResultPtr, targetView->effect, targetView->targetFlags));
            (((BtlPacketTiming *)resultPacketB)->dependencyKind) = 5;
            (((BtlPacketTiming *)resultPacketB)->dependencyUid) = animUid;
            (((BtlPacketTiming *)resultPacketB)->delay) = hitTimingBase;
            (((BtlPacketTiming *)resultPacketB)->actionUid) = actionUid;
            btlPacketEnqueue(resultPacketB, 1);
            statusPacket = (u8 *)(btlPacketCreateHitDisplay((s32)(battleUnit), *(s32 *)&focusTarget->unit, (((BtlAction *)actionBytes)->unk_6e), targetView->effect, targetView->targetFlags, 0, 1, hitResultSaved, 0));
            (((BtlPacketTiming *)statusPacket)->dependencyKind) = 5;
            (((BtlPacketTiming *)statusPacket)->dependencyUid) = animUid;
            (((BtlPacketTiming *)statusPacket)->delay) = hitTimingBase;
            if (hitTimingBase < timingValueWide) {
                timingRemaining = timingValueWide - hitTimingBase;
            } else {
                timingRemaining = 0;
            }
            (((BtlPacketTiming *)statusPacket)->duration) = timingRemaining;
            (((BtlPacketTiming *)statusPacket)->actionUid) = actionUid;
            btlPacketEnqueue(statusPacket, 3);
            if ((hitRowNumber == 0) && (hitResultSaved->hpDelta != 0)) {
                statPacket = (u8 *)(btlPacketCreateUnitCounter((s32)(focusTarget->unit), 0, 0));
                (((BtlPacketTiming *)statPacket)->dependencyKind) = 5;
                (((BtlPacketTiming *)statPacket)->dependencyUid) = animUid;
                (((BtlPacketTiming *)statPacket)->delay) = hitTimingBase;
                (((BtlPacketTiming *)statPacket)->flags) = (u8) ((((BtlPacketTiming *)statPacket)->flags) & 0xDF);
                (((BtlPacketTiming *)statPacket)->actionUid) = actionUid;
                btlPacketEnqueue(statPacket, 3);
            }
            /* Retail retains this address and reloads its word at the later branch. */
            addedStatus = &hitRow->result.addedStatus;
            if ((hitRow->result.addedStatus & 0x100000) && ((((BtlUnit *)((u8 *)(focusTarget->unit)))->genus) == 1)) {
                cuePacketJ = (u8 *)(btlSoundCreateChannelCuePacket(0xD, 2, 8));
                (((BtlPacketTiming *)cuePacketJ)->dependencyKind) = 5;
                (((BtlPacketTiming *)cuePacketJ)->dependencyUid) = animUid;
                (((BtlPacketTiming *)cuePacketJ)->delay) = hitTimingBase;
                (((BtlPacketTiming *)cuePacketJ)->actionUid) = actionUid;
                btlPacketEnqueue(cuePacketJ, 1);
            }
            if ((actionFlagSaved == 0) && ((((BtlUnit *)((u8 *)(focusTarget->unit)))->genus) == 1)) {
                if (reactionUnitCount > 0) {
                    if ((((BtlUnit *)((u8 *)((*(u8 **)(actionBytes + (0x30))))))->genus) == 0) {
                        reactionRoll = btlSideCountNotBad(2, 0x80000) & 0xFFFF;
                        reactionCueFlag = ((BtlAction *)actionBytes)->unk_28;
                        if (reactionCueFlag > 0) {
                            goto createReaction;
                        }
                        reactionCueFlag = 1;
                        if (((BtlUnit *)(*(u8 **)(actionBytes + 0x30)))->charId == reactionCueFlag) {
                            goto createReaction;
                        }
                        reactionCueFlag = datCalcRandomBelow(0x64);
                        if ((u32)reactionCueFlag >= 0x32U) {
                            goto createReaction;
                        }
                        if ((((BtlUnit *)((u8 *)(((u8*)((BtlAction *)actionBytes)->unit))))->genus) != 0) {
                            reactionCueFlag = 0;
                        } else {
                            battleStatePtr = (u8 *)(iGpffffb3ac);
                            if ((((BtlBattleState *)battleStatePtr)->unkA70) != -1) {
                                reactionRemaining = (s16)(reactionRoll - reactionUnitCount);
                                if (reactionRemaining <= 0) {
                                    randomRoll = btlSideCountNotBad(2, 0x80000) & 0xFFFF;
                                    battleStatePtrD = (u8 *)(iGpffffb3ac);
                                    if (((u32) ((s16) (((BtlBattleState *)battleStatePtrD)->unkA72) >> 1) >= randomRoll) && (counterUnitId16 = (((BtlBattleState *)battleStatePtrD)->unkA70), counterUnitId = (s32) counterUnitId16, (counterUnitId16 != (s16)btlCameraSelectFormationIndex()))) {
                                        reactionCueFlag = 1;
                                    } else {
                                        goto block_222;
                                    }
                                } else if (((s16) (((BtlBattleState *)battleStatePtr)->unkA72) >> 1) >= reactionRemaining) {
                                    reactionCueFlag = 1;
                                } else {
                                    goto block_222;
                                }
                            } else {
block_222:
                                reactionCueFlag = 0;
                            }
                        }
                        if (reactionCueFlag != 0) {
createReaction:
                            reactionPacketB = (u8 *)(btlTargetCreateTargetPacket(actionBytes, 0x13, reactionUnitCount, 0, 0));
                            (((BtlPacketTiming *)reactionPacketB)->dependencyKind) = 4;
                            (((BtlPacketTiming *)reactionPacketB)->dependencyUid) = hitPacketUid;
                            (((BtlPacketTiming *)reactionPacketB)->actionUid) = actionUid;
                            btlPacketEnqueue(reactionPacketB, 1);
                        } else {
                            actionPacketB = (u8 *)(func_001f99c0(actionBytes, 0x10, reactionUnitCount, 0, 0));
                            (((BtlPacketTiming *)actionPacketB)->dependencyKind) = 4;
                            (((BtlPacketTiming *)actionPacketB)->dependencyUid) = hitPacketUid;
                            btlPacketEnqueue(actionPacketB, 1);
                        }
                    }
                } else if (*addedStatus & 0x100000) {
                    reactionPacketC = (u8 *)(btlTargetCreateTargetPacket(actionBytes, 0x18, (s32) targetView->targetFlags, 1, 0));
                    (((BtlPacketTiming *)reactionPacketC)->dependencyKind) = 5;
                    (((BtlPacketTiming *)reactionPacketC)->dependencyUid) = hitPacketUid;
                    (((BtlPacketTiming *)reactionPacketC)->actionUid) = actionUid;
                    btlPacketEnqueue(reactionPacketC, 1);
                } else if (reactionUnitCount == 0) {
                    if (btlActionTargetsHaveDamageResult((s64 *)actionBytes, 1) != 0) {
                        actionPacketC = (u8 *)(func_001f99c0(actionBytes, 0xF, 0U, 0, 0));
                        (((BtlPacketTiming *)actionPacketC)->dependencyKind) = 5;
                        (((BtlPacketTiming *)actionPacketC)->dependencyUid) = hitPacketUid;
                        btlPacketEnqueue(actionPacketC, 1);
                    } else if ((btlActionAnyTargetHasSpecialResult(actionBytes) == 1) && (btlActionAnyTargetSpecialHit(actionBytes) == 0)) {
                        actionPacketD = (u8 *)(func_001f99c0(actionBytes, 0x11, 0U, 0, 0));
                        (((BtlPacketTiming *)actionPacketD)->dependencyKind) = 5;
                        (((BtlPacketTiming *)actionPacketD)->dependencyUid) = hitPacketUid;
                        btlPacketEnqueue(actionPacketD, 1);
                    }
                }
            }
            hitRowIndex += 1;
        }
        unitStatePacket = (u8 *)(btlTargetCreateRecordPacket(targetView));
        (((BtlPacketTiming *)unitStatePacket)->dependencyKind) = 5;
        (((BtlPacketTiming *)unitStatePacket)->dependencyUid) = animUid;
        (((BtlPacketTiming *)unitStatePacket)->delay) = hitTimingBase;
        (((BtlPacketTiming *)unitStatePacket)->actionUid) = actionUid;
        btlPacketEnqueue(unitStatePacket, 1);
        auxEffectIndex = (s16)(((s16)((BtlAction *)actionBytes)->targetBlock.message.messageCode));
        if ((auxEffectIndex != 0) && !((((BtlAction *)actionBytes)->targetBlock.unk_d8) & 1)) {
            unitStatePacketB = (u8 *)(btlPacketCreateEffectCounter(((u8*)((BtlAction *)actionBytes)->unit), auxEffectIndex));
            (((BtlPacketTiming *)unitStatePacketB)->dependencyKind) = 5;
            (((BtlPacketTiming *)unitStatePacketB)->dependencyUid) = animUid;
            (((BtlPacketTiming *)unitStatePacketB)->delay) = hitTimingBase;
            (((BtlPacketTiming *)unitStatePacketB)->flags) = (u8) ((((BtlPacketTiming *)unitStatePacketB)->flags) & 0xDF);
            (((BtlPacketTiming *)unitStatePacketB)->actionUid) = actionUid;
            btlPacketEnqueue(unitStatePacketB, 3);
        } else {
            auxEffectIndexTarget = (s16)(((s16)((BtlAction *)targetView)->targetBlock.message.messageCode));
            if (auxEffectIndexTarget != 0) {
                unitStatePacketC = (u8 *)(btlPacketCreateEffectCounter(targetView->unit, auxEffectIndexTarget));
                (((BtlPacketTiming *)unitStatePacketC)->dependencyKind) = 5;
                (((BtlPacketTiming *)unitStatePacketC)->dependencyUid) = animUid;
                (((BtlPacketTiming *)unitStatePacketC)->delay) = hitTimingBase;
                (((BtlPacketTiming *)unitStatePacketC)->flags) = (u8) ((((BtlPacketTiming *)unitStatePacketC)->flags) & 0xDF);
                (((BtlPacketTiming *)unitStatePacketC)->actionUid) = actionUid;
                btlPacketEnqueue(unitStatePacketC, 3);
            }
        }
        targetIndex += 1;
    }
    unitStatePacketD = (u8 *)(btlTargetCreateRecordPacket(actionBytes));
    (((BtlPacketTiming *)unitStatePacketD)->dependencyKind) = 5;
    (((BtlPacketTiming *)unitStatePacketD)->dependencyUid) = animUid;
    (((BtlPacketTiming *)unitStatePacketD)->delay) = hitTimingBase;
    (((BtlPacketTiming *)unitStatePacketD)->actionUid) = actionUid;
    btlPacketEnqueue(unitStatePacketD, 1);
    if (!((((BtlAction *)actionBytes)->flags) & 4)) {
        statePacket = (u8 *)(btlTargetCreateActionPacket(actionBytes, (((BtlAction *)actionBytes)->targetBlock.resultFlags)));
        (((BtlPacketTiming *)statePacket)->dependencyKind) = 5;
        (((BtlPacketTiming *)statePacket)->dependencyUid) = animUid;
        (((BtlPacketTiming *)statePacket)->delay) = hitTimingBase;
        (((BtlPacketTiming *)statePacket)->actionUid) = actionUid;
        btlPacketEnqueue(statePacket, 1);
    }
    if (setEffectFlags != 0) {
        battleStatePtrC = (u8 *)(iGpffffb3ac);
        (((BtlBattleState *)battleStatePtrC)->flags) = (s32) ((((BtlBattleState *)battleStatePtrC)->flags) | 0x400000);
        battleStatePtrB = (u8 *)(iGpffffb3ac);
        (((BtlBattleState *)battleStatePtrB)->actionEndFlags) = (u16) ((((BtlBattleState *)battleStatePtrB)->actionEndFlags) | 0xF);
    }
    cutinUnit = (u8 *)((((BtlAction *)actionBytes)->parameters.support));
    if (cutinUnit != NULL) {
        cutin.mode = 3;
        cutin.unitId = (u16)((((BtlUnit *)((u8 *)(((u8*)((BtlAction *)cutinUnit)->unit))))->charId));
        btlPacketEnqueue(btlSoundLoadPacketNew(&cutin), 1);
    }
    if (btlSoundCanReceiveStatus((s64 *)actionBytes) != 0) {
        btlActionSetState((BtlAction *)actionBytes, 0x1BU);
        return;
    }
    {
        u16 state;

        switch (((BtlAction *)actionBytes)->unk_6c) {
        case 1:
        case 3:
        case 2:
            state = 0x20;
            break;
        default:
            state = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)actionBytes, state);
    }
}

#pragma pop
// FUN_001A7710
void btlActionSkillInit(void)
{
}

#pragma push
/* measured: loop-invariant hoisting is required for retail's hit-loop preheader (506 -> 33 edits when introduced). */
/* measured: func_001a7720 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// FUN_001A7720
/* Sequence skill presentation, linked-unit effects, per-target results and recovery using packet UIDs. */
/* Raw action/row offsets retain MATCH after canonical rewrites; extra packet gates use tagged narrow/wide payloads. */
void btlActionSkillUpdate(u8 *actionBytes) {

    extern s32 btlCreateSetFlagsPacket(u32);
    extern s64 btlPacketEnqueue(u8 *context, u32 value);
    extern u8 *btlPacketCreateImmediate(void);
    extern u8 *btlPacketAllocZeroed(void *callback, void *data);
    extern s32 btlUnitGetPersonaAlphaColor(u8 *context);
    extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
    extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern u8 *btlUnitCreateArcMovePacket(s32 unitAddress, s16 mode, s16 counter);
    extern s32 btlUnitCreateRotateTowardUnitPacket();
    extern s32 btlUnitGetMotionState(u8 *unit);
    extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
    extern BtlPacket *btlUnitCreateModelFramePacket(BtlUnit *unit, s16 value);
    extern BtlPacket *btlUnitCreateMotionSpeedPacket(BtlUnit *unit, u16 value, f32 speed, u16 mode);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *unit, u16 modelId, s16 motion);
    extern BtlPacket *btlUnitCreateColorPacket(BtlUnit *unit, u32 targetColor, s16 startFrame, s16 duration, u8 mode, u8 flags);
    extern BtlPacket *btlUnitCreateLookAtPacket(BtlUnit *unit, const RwV3d *targetPos, u16 flags);
    extern s32 btlUnitCreateLookAtDeactivatePacket(void *, u16);
    extern void btlActionFinishPresentation(BtlAction *action);
    extern void btlMainSkillColorPairDefaults(u16 skill, s32 *color, s32 *tint); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    extern s32 btlMainSkillColorDefault(u16 skill); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    extern s32 btlMainSkillTintDefault(s32 skill);
    extern void btlMainSkillColorPairDefaultsAlt(u16 skill, s32 *color, s32 *tint); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    extern BtlPacket* btlMainCreateColorLerpPacket(u32 startColor, u32 targetColor, u32 duration);
    extern BtlPacket* btlCreateTimingPacket(u32 value);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 lightColor, s32 ambientColor, s32 fogColor, u32 duration, u16 flags);
    /* lint: allow H011 -- retail zero-extends the mode with andi 0xffff: this caller saw a u16 parameter. */
    extern BtlPacket *btlMainCreateFadePacket(s32 arg, u16 mode);
    extern BtlPacket* btlMainCreateTintPacket(u32 targetColor, u32 duration);
    extern BtlPacket* btlMainCreateColorFadePacket(s32 arg);
    extern BtlPacket* btlMainCreateColorSetPacket(s32 arg);
    extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
    extern u8 *btlCameraCreatePacketCommand(s32 value, s16 option, s32 first, s32 second);
    extern BtlPacket *btlFormationCreateStepPacket();
    extern BtlPacket *btlFormationCreateTurnPacket(u32 actor, u32 targetAction, u32 partnerAction, u16 skill);
    extern BtlPacket *btlFormationCreateWaitPacket(u32 actor, u32 target, u16 mode);
    extern s32 btlFormationAllocWork(u32 mode);
    extern void btlFormationSetPlacement(u32 formation);
    extern u32 btlFormationGetFlags(s32 record);
    extern BtlPacket *btlFormationCreatePacket(u32 formation, u32 sourceUnit, u32 targetUnit, u16 side, u32 flags);
    extern u16 btlTargetGetUnitIndex(BtlTarget *target);
    extern s32 btlUnitSlotValueOrOne(u16 unitId); /* lint: allow H011 -- retail passes the lhu skill unconverted */
    /* lint: allow H011 -- retail passes these u16 arguments without conversion:
     * this caller saw u16 parameters (the definitions take u32/s32). */
    extern void btlFormationFormatName(u16 value, char *destination); /* lint: allow H011 -- retail passes the u16 unconverted */
    extern BtlPacket *btlMainCreateUnitTintPacket(BtlAction *action, u16 selector, u32 duration); /* lint: allow H011 -- retail passes the u16 unconverted */
    extern void btlTargetClearResultBuffer(u8 *result);
    extern s32 btlActionAnyTargetHitRowStatus(u8 *action);
    extern s32 btlActionAnyTargetSpecialHit(u8 *action);
    extern s32 btlActionSameGenusTargetsHaveDelta(u8 *action);
    extern s32 btlActionAnyTargetClearsDeathStatus(u8 *action);
    extern s32 btlActionTargetsHaveDamageResult(u8 *action, s32 mode);
    extern u32 btlActionAnyTargetHasSpecialResult(u8 *action);
    extern s32 btlActionHasNoTargetClass();
    extern s32 btlTargetGroupStateMatches(u8 *context);
    extern s32 btlTargetIsSlotAlive(u8 *context);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
    extern u8 * btlTargetCreateRecordPacket(u8 *action);
    extern u8 * btlTargetCreateHitPacket(u8 *action);
    extern s32 btlTargetCreateTargetPacket();
    extern s32 btlSoundCanReceiveStatus(u8 *action);
    extern BtlPacket* btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
    extern BtlPacket* btlSoundCreateSkillSEPacket(u16 skillId, u16 flags);
    extern u8 *btlSoundCreateMarkReadyPacket(u32 value);
    extern u8 *btlSoundCreateClearReadyPacket(u32 value);
    extern s32 func_001f99c0();
    extern u8 *btlCutinCreatePacket(u8 *request);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern u8 *btlPacketCreateFinishEffect(void);
    extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 sprite, u16 frame);
    extern BtlPacket *btlPacketCreateSpriteStep(u32 sprite, u16 frame);
    extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
    extern u8 *btlPacketCreateHpRatio(u8 *unit);
    extern void btlPanelSetValueText(u8 *window, s32 value);
    extern s32 btlActionSelectFormationSlot(u8 *action);
    extern s32 btlActionHasFormationSlot(u8 *action, u8 *slots);
    extern s32 btlActionMatchesSkill(u8 *action, s32 skillId);
    extern s32 btlUnitApplyPacketEffects(u8 *packet);
    extern s32 btlBossSkillRestoresMotionBeforeHits(u8 *action, s32 skillId);
    extern s32 btlUnitSkillBlocked(u8 *action, u8 *subordinate);
    extern s32 btlBossActionBlocked();
    extern s32 btlBossSkillAllowed(u8 *action);
    extern u16 datCalcGetHp(s32 unit);
    extern s32 datCalcUsesWeaponProperties(s32 skillId);
    /* lint: allow H011 -- the definition is an asm function returning int. */
    extern int func_0043c6a0(int value);
    extern u8 *iGpffffb3ac;
    extern u8 *iGpffffb3b8;
    extern u8 *iGpffffb3cc;

    /* Action fields read here; offsets from the retail loads. */
    typedef struct BtlSkillAction {
        u8 pad00[0x18];
        u16 flags;          /* 0x18 */
        u16 flags1A;        /* 0x1A */
        u8 pad1C[0x14];
        u8 *unit;           /* 0x30 */
        u8 pad34[4];
        s32 *target;        /* 0x38 */
        u8 pad3C[0x2E];
        u16 targetCount;    /* 0x6A */
        u16 kind;           /* 0x6C */
        s16 skill;          /* 0x6E */
        u16 field70;        /* 0x70 */
        u8 pad72[0x16];
        s32 *followAction;  /* 0x88 */
        u8 *cutinPartner;   /* 0x8C */
        u8 pad90[0x48];
        u8 fieldD8;         /* 0xD8 */
        u8 padD9[2];
        u8 stateBits;       /* 0xDB */
        u8 padDC[0x10];
        s16 fieldEC;        /* 0xEC */
        s16 fieldEE;        /* 0xEE */
    } BtlSkillAction;
    typedef struct BtlActionHitCursor {
        u8 actionPrefix[0xF0];
        LargeBattleHitResult result;
    } BtlActionHitCursor;
    s64 chainUid;
    BtlPacketTiming *animPacket;
    s32 cameraFirst;
    s32 cameraSecond;
    /* 0022d540 returns the three formation effect handles together. */
    s32 effectHandles[3];
    /* Both cut-in constructors copy ten bytes; modes 3/4 use four. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    RwV3d targetPosition;
    LargeBattleHitResult result;
    /* Retail reserves 0x60 bytes for the formatted formation name. */
    char formation[96];
    u8 *spRow;
    u8 *primaryTarget;
    u8 *linkedUnit;
    BtlPacketTiming *skillSoundPacket;
    BtlPacket *targetRecoveryCameraPacket;
    BtlPacketTiming *reactionFormationPacket;
    BtlPacketTiming *reflectedFormationPacket;
    BtlPacketTiming *followMovementPacket;
    BtlPacketTiming *impactFormationPacket;
    s32 formationHandle;
    s64 sceneUid;
    s64 animEndUid;
    s64 formationEndUid;
    s64 cutinEndTime;
    s16 skill;
    s16 cameraState;
    s16 animMotion;
    s16 hitDelay;
    s16 hitWait;                                      /* compiler-managed */
    s32 damageFrames;
    s32 baseDelay;
    s32 crossSideHits;
    s32 statusHits;
    u16 targetIndex;
    u16 hitIndex;
    u16 rowHitCount;
    u16 hitTimer;
    u16 hitTimeTotal;
    u16 statusMask;
    u16 motionFrames;
    u16 windupFrames;
    s32 actionFlag4000;
    s32 rotateFirst;
    s32 randomFlag;
    /* Independent 0/1 phase decisions remain live across packet callbacks. */
    s32 endsEncounter;
    s32 restoreMotionSpeed;
    s32 settleMotion;
    s32 sacrificeActor;
    s32 restoreBeforeHits;
    s32 skipMotionRecovery;
    s32 reuseLinkedModel;
    u16 skillKeyCopy;
    s32 skillS32;
    u16 skillU16;
    u16 skillKey;
    s32 targetIndexS32;
    s32 motionFramesS32;
    s32 *hitResultPtr;
    s32 hasFollowAction;
    s32 noOverride;
    s32 skillFlag2;
    s32 altCamera;
    s32 isKind3;
    s32 skillSpecial;
    s32 hasCutinPartner;
    s32 bossCheck;
    s32 hitModeDelay;
    s32 isSkill16;
    s64 formationEndUid2;
    u16 hitDelta;
    s32 hitFlags;
    s32 sameSideTarget;
    BtlActionHitCursor *hitRow;
    s8 *hitMotion;
    s16 *hpTransfer;
    s16 hitDelayS16;
    s32 hitIndexS32;
    u16 animBlend;
    s32 rotateFlags;
    f32 targetScale;
    f32 motionFramesF;
    f32 areaScale;
    f32 scaleLimit;
    f32 animSpeed;
    f32 motionSpeed;
    s16 lastActor;
    s32 skillIndex;
    s32 followSkill;
    s32 targetFieldEC;
    s32 timingFrames;
    s32 recoveryFrames;
    s32 animDuration;
    s16 colorDelay;
    s32 cameraDelay;
    s32 formationDelay;
    s32 *hitResult;
    s32 statusTotal;
    s32 cameraKind;
    s32 targetHitValue;
    s32 skillFlagsOffset;
    s32 skillEndFrame;
    s32 targetGroup2;
    s32 hitRowWord;
    s32 hitField14;
    s32 targetGroup;
    s32 hasCutin;
    s32 pendingFollow;
    s32 chanceMiss;
    s32 cameraMode;
    s32 cameraStateA;
    s32 cameraStateB;
    s32 cameraStateC;
    s32 followState;
    s32 hitDelayBase;
    u8 *targetAction;
    u8 *followActionPtr;
    u8 *firstTarget;
    u8 *firstTargetEntry;
    u8 *effectiveAction;
    s32 *targetList;
    s64 actionId;
    s64 lateChainUid;
    s32 recoveryBase;
    s16 skillFramesKey;
    s64 side;
    s32 skillFrames;
    s16 skillKind;
    s16 skillKindRow;
    s16 skillKindUnit;
    s32 motionId;
    s32 statusRemaining;
    s32 motionState;
    s64 cutinUid;
    s32 blendFrames;
    s32 motionDelay;
    s32 motionIdRaw;
    s32 hitMode;
    s8 unitSide;
    u32 motionFramesCopy;
    u16 flagsSnapshot;
    u32 flags1ASnapshot;
    u32 statusTotal2;
    u8 stateBitsCopy;
    s32 hitSide;
    BtlPacketTiming *sourceOpeningAnimationPacket;
    u8 *unit;
    BtlPacketTiming *hitElementFormationPacket;
    BtlPacketTiming *hitModelFramePacket;
    u8 *cameraTargetUnit;
    BtlPacketTiming *impactCameraCommandPacket;
    BtlPacketTiming *hitMotionSettlePacket;
    BtlPacketTiming *hitTargetRotationPacket;
    BtlPacketTiming *applyEffectsPacket;
    BtlPacketTiming *hitResultPacket;
    BtlPacketTiming *targetHitPacket;
    BtlPacketTiming *targetRecordPacket;
    BtlPacketTiming *sourceRecordPacket;
    BtlPacketTiming *sourceActionPacket;
    BtlPacketTiming *sourceEffectCounterPacket;
    BtlPacketTiming *targetEffectCounterPacket;
    BtlPacketTiming *followEffectCounterPacket;
    BtlPacketTiming *targetUnitCounterPacket;
    BtlPacketTiming *targetDownSoundPacket;
    u8 *hitRowBase;
    BtlPacketTiming *hitDisplayPacket;
    BtlPacketTiming *skillSpritePacket;
    BtlPacketTiming *transferResultPacket;
    BtlPacketTiming *transferDisplayPacket;
    BtlPacketTiming *sourceHpRatioPacket;
    BtlPacketTiming *transferCounterPacket;
    BtlPacketTiming *followSkillPacket;
    BtlPacketTiming *reactionVoicePacket;
    BtlPacketTiming *reactionTargetPacket;
    BtlPacketTiming *statusTargetPacket;
    BtlPacketTiming *sameSideVoicePacket;
    BtlPacketTiming *followUpVoicePacket;
    BtlPacketTiming *actionSpritePacket;
    BtlPacketTiming *specialHitVoicePacket;
    BtlPacketTiming *actorResultDisplayPacket;
    BtlPacketTiming *actorResultCounterPacket;
    BtlPacketTiming *actorResultSettlePacket;
    BtlPacketTiming *actorHideWaitPacket;
    BtlPacketTiming *actorHidePacket;
    BtlPacketTiming *actorHideFormationPacket;
    BtlPacketTiming *actorHideSoundPacket;
    BtlPacketTiming *recoverySettlePacket;
    u8 *linkedGroupLookAtStopPacket;
    BtlPacketTiming *recoveryTimingPacket;
    BtlPacketTiming *recoveryFadePacket;
    BtlPacketTiming *recoveryColorFadePacket;
    BtlPacketTiming *recoveryColorSetPacket;
    BtlPacketTiming *recoveryCameraPacket;
    BtlPacketTiming *recoveryGroupCameraPacket;
    BtlPacketTiming *sourceColorRestorePacket;
    BtlPacketTiming *linkedFadePacket;
    BtlPacketTiming *linkedReleaseEffectPacket;
    BtlPacketTiming *endEncounterFlagsPacket;
    BtlPacketTiming *cutinStartPacket;
    BtlPacketTiming *endSequencePacket;
    BtlPacketTiming *cutinEndPacket;
    BtlPacketTiming *cutinVoicePacket;
    BtlPacketTiming *cutinSoundPacket;
    BtlPacketTiming *openingFormationPacket;
    BtlPacketTiming *linkedTurnPacket;
    BtlPacketTiming *cutinModelLoadPacket;
    u8 *linkedModelLoadPacket;
    u8 *linkedModelWaitPacket;
    BtlPacketTiming *linkedEffectWaitPacket;
    BtlPacketTiming *linkedOpeningEffectPacket;
    BtlPacketTiming *linkedOpeningSoundPacket;
    BtlPacketTiming *sourceCastAnimationPacket;
    BtlPacketTiming *clearUnitSoundFlagPacket;
    BtlPacketTiming *clearSoundReadyPacket;
    BtlPacketTiming *linkedCastEffectPacket;
    BtlPacketTiming *linkedCastSoundPacket;
    BtlPacketTiming *linkedCastTrailPacket;
    BtlPacketTiming *sourceDimPacket;
    BtlPacketTiming *linkedCastAnimationPacket;
    BtlPacketTiming *linkedAlphaPacket;
    BtlPacketTiming *linkedCastCuePacket;
    BtlPacketTiming *linkedHitCameraPacket;
    u8 *alternateLookAtStopPacket;
    BtlPacketTiming *alternateCastAnimationPacket;
    BtlPacketTiming *alternateFormationPacket;
    BtlPacketTiming *alternateCastCameraPacket;
    BtlPacketTiming *alternateGroupCameraPacket;
    BtlPacketTiming *alternateCastEffectPacket;
    u8 *enemyLookAtStopPacket;
    BtlPacketTiming *enemyCastAnimationPacket;
    BtlPacketTiming *enemyMotionWaitPacket;
    BtlPacketTiming *enemyCastCameraPacket;
    BtlPacketTiming *enemyCastWaitPacket;
    BtlPacketTiming *enemyFormationPacket;
    BtlPacketTiming *selectedTargetRotationPacket;
    BtlPacketTiming *enemyFormationCameraPacket;
    BtlPacketTiming *enemyCastEffectPacket;
    BtlPacketTiming *enemyCastSoundPacket;
    BtlPacketTiming *sourceOpeningEffectPacket;
    BtlPacketTiming *sourceOpeningSoundPacket;
    BtlPacketTiming *sourceOpeningCameraPacket;
    BtlPacketTiming *sourceActionAnimationPacket;
    BtlPacketTiming *sourceTargetWaitPacket;
    BtlPacketTiming *sourceActionCameraPacket;
    BtlPacketTiming *targetGroupRotationPacket;
    BtlPacketTiming *skillColorLerpPacket;
    BtlPacketTiming *skillColorWorkPacket;
    BtlPacketTiming *skillTintPacket;
    BtlPacketTiming *sourceTintPacket;
    BtlPacketTiming *followActionCameraPacket;
    BtlPacketTiming *followActionVoicePacket;
    BtlPacketTiming *followActionAnimationPacket;
    BtlPacketTiming *followTargetAnimationPacket;
    BtlPacketTiming *encounterRotationPacket;
    BtlPacketTiming *followFormationCameraPacket;
    BtlPacketTiming *followTargetWaitPacket;
    BtlPacketTiming *followTargetRotationPacket;
    BtlPacketTiming *followTargetRecoveryPacket;
    BtlPacketTiming *followSourceRotationPacket;
    BtlPacketTiming *skillNameWaitPacket;
    BtlPacketTiming *openingSkillFormationPacket;
    BtlPacketTiming *openingCueQueuePacket;
    BtlPacketTiming *targetHpRatioPacket;
    u8 *sourceFocusPacket;
    BtlPacketTiming *targetCueQueuePacket;
    BtlPacketTiming *reflectedSkillFormationPacket;
    BtlPacketTiming *reflectedCueQueuePacket;
    BtlPacketTiming *targetFocusPacket;
    BtlPacketTiming *targetLookAtSourcePacket;
    BtlPacketTiming *targetLookAtStopPacket;
    BtlPacketTiming *targetGroupLookAtPacket;
    BtlPacketTiming *linkedHidePacket;
    BtlPacketTiming *earlyColorRestorePacket;
    u8 *sourceLookAtStopPacket;
    BtlPacketTiming *earlyTargetRotationPacket;
    BtlPacketTiming *earlyFinishEffectPacket;
    BtlPacketTiming *reflectedSoundPacket;
    BtlPacketTiming *absorbedSoundPacket;
    BtlPacketTiming *hitAnimationPacket;
    BtlPacketTiming *hitArcMovePacket;
    u8 *groupLookAtStopPacket;
    u8 *specialStateBattle;
    u8 *sourceStateBattle;
    u8 *followStateBattle;
    u8 *reactionCountBattle;
    u8 *hiddenSourceUnit;
    u8 *effectBattle;
    u8 *linkedStateBattle;
    u8 *alternateStateBattle;
    u8 *enemyStateBattle;
    u8 *acceleratedStateBattle;
    u8 *sourceFlagsBattle;
    u8 *followFlagsBattle;
    u8 *hitTargetUnit;
    u8 *transferSourceUnit;
    u8 *reactionBattle;
    u8 *resultSourceUnit;
    u8 *hidingSourceUnit;
    u8 *rotationBattle;
    u8 *cutinBattle;
    u8 *linkedFlagsBattle;
    u8 *alternateFlagsBattle;
    u8 *enemyFlagsBattle;
    u8 *acceleratedFlagsBattle;
    u8 *specialFlagsBattle;
    u8 *openingSourceUnit;
    u8 *elementTargetUnit;
    u8 *impactTargetUnit;
    u8 *hidingEffectUnit;
    BtlPacketTiming *openingAnimationPacket;
    BtlPacketTiming *linkedAnimationPacket;
    BtlPacketTiming *skillFormationPacket;
    BtlPacketTiming *actorResultPacket;
    BtlPacketTiming *openingCameraPacket;
    BtlPacketTiming *skillNamePacket;
    BtlPacketTiming *earlyMotionRecoveryPacket;
    BtlPacketTiming *targetElementCuePacket;

    BtlSkillAction *act = (BtlSkillAction *)actionBytes;

    unit = (u8 *)(act->unit);
    unitSide = (s8)((s8)((BtlUnit *)(unit))->genus);
    linkedUnit = (u8 *)((u8 *)((BtlUnit *)(unit))->childUnit);
    skill = (s16)(act->skill);
    primaryTarget = (u8 *)(act->target);
    actionFlag4000 = (s32)((act->flags & 0x4000)) != (s32)(0);
    formationEndUid = 0;
    cutinEndTime = 0;
    crossSideHits = 0;
    statusHits = 0;
    statusMask = 0;
    hitDelay = 0;
    baseDelay = 0;
    hasCutin = 0;
    randomFlag = 0;
    endsEncounter = 0;
    restoreMotionSpeed = 0;
    settleMotion = 0;
    sacrificeActor = 0;
    restoreBeforeHits = 0;
    skipMotionRecovery = 0;
    reuseLinkedModel = 0;
    hasFollowAction = (s32)(s32)(act->followAction) != (s32)(0);
    noOverride = (s32)(btlTargetIsSlotAlive(actionBytes)) == (s32)(0);
    windupFrames = 6;
    skillIndex = skill;
    skillFlag2 = (s32)(s32)((((DatSkillEntry *)iGpffffb3b8)[skillIndex].flags00 & 2)) != (s32)(0);
    altCamera = ((act->flags1A & 0x10) != 0) && skillFlag2 == 0;
    isKind3 = (s32)(s32)(act->kind == 3);
    rotateFirst = (s32)(btlActionHasNoTargetClass(actionBytes));
    skillSpecial = (s32)(btlTargetIsEntryActive(skill));
    hasCutinPartner = (s32)(s32)(act->cutinPartner) != (s32)(0);
    reactionFormationPacket = 0;
    actionId = (s64)((BtlAction *)actionBytes)->uid;
    btlActionFinishPresentation((BtlAction *)actionBytes);
    side = (s8)unitSide;
    if ((side == 1) && (((BtlBattleState *)iGpffffb3ac)->flags & 0x200000)) {
        actionFlag4000 = 0;
    }
    if (actionFlag4000 == 0) {
        formationHandle = (s32)(btlFormationAllocWork(1));
    } else {
        skillKind = (s16)datCalcSkillElement(NULL, (u16)skill);
        switch (skillKind) {                           /* switch 1; irregular */
        case 16:                                    /* switch 1 */
            formationHandle = (s32)((s32)((BtlBattleState *)iGpffffb3ac)->formations[38]);
            break;
        case 17:                                    /* switch 1 */
            formationHandle = (s32)((s32)((BtlBattleState *)iGpffffb3ac)->formations[39]);
            break;
        default:                                    /* switch 1 */
            formationHandle = (s32)((s32)((BtlBattleState *)iGpffffb3ac)->formations[37]);
            break;
        }
    }
    flags1ASnapshot = (u16)(act->flags1A);
    if (!(flags1ASnapshot & 1)) {
        pendingFollow = 0;
    } else {
        BtlUnit *partner = (((BtlAction *)actionBytes)->unit)->childUnit;
        if (!(flags1ASnapshot & 0x10)) {
            pendingFollow = 0;
        } else if (partner->flags2 & 2) {
            pendingFollow = 1;
        } else {
            pendingFollow = 0;
        }
    }
    if (pendingFollow != 0) {
        reuseLinkedModel = 1;
    }
    bossCheck = (s32)(s32)(btlBossSkillAllowed(actionBytes));
    if (side >= 0) {
        if (reuseLinkedModel != 0) {
            rotateFlags = 0x1002;
        } else {
            rotateFlags = 0;
        }
        if (rotateFirst != 0) {
            selectedTargetRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(act->unit, ((u8*)((BtlAction *)act->target)->unit), rotateFlags));
            selectedTargetRotationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)selectedTargetRotationPacket, 0);
        } else if (side == 0) {
            btlUnitGetGroupBounds((u16)btlTargetGetUnitIndex((BtlTarget *)(actionBytes + 0x38)), 1, &targetPosition, 0, 0, 1);
            targetGroupRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotatePacket(((BtlAction *)actionBytes)->unit, &targetPosition, rotateFlags));
            targetGroupRotationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)targetGroupRotationPacket, 0);
        } else {
            rotationBattle = (u8 *)(iGpffffb3ac);
            if (((BtlBattleState *)rotationBattle)->flags & 0x200000) {
                btlUnitGetGridSphereCenter((((BtlAction *)((BtlBattleState *)rotationBattle)->selectedAction)->unit), &targetPosition);
                encounterRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotatePacket(((BtlAction *)actionBytes)->unit, &targetPosition, rotateFlags));
                encounterRotationPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)encounterRotationPacket, 0);
            }
        }
        if (bossCheck != 0) {
            sourceFocusPacket = (u8 *)(btlActionCreateLookAtUnitPacketBytes(0, act->unit, 3));
            ((BtlPacket *)sourceFocusPacket)->actionUID = *(s64 *)actionBytes;
            btlPacketEnqueue((u8 *)sourceFocusPacket, 1);
            sourceLookAtStopPacket = (u8 *)(btlUnitCreateLookAtDeactivatePacket(act->unit, 0));
            ((BtlPacket *)sourceLookAtStopPacket)->actionUID = *(s64 *)actionBytes;
            btlPacketEnqueue((u8 *)sourceLookAtStopPacket, 1);
        } else {
            groupLookAtStopPacket = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
            ((BtlPacket *)groupLookAtStopPacket)->actionUID = *(s64 *)actionBytes;
            btlPacketEnqueue((u8 *)groupLookAtStopPacket, 1);
        }
        act->flags = (u16) (act->flags | 0x200);
        targetHitPacket = (BtlPacketTiming *)(btlTargetCreateHitPacket(actionBytes));
        targetHitPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)targetHitPacket, 1);
    }
    skillFlagsOffset = skillIndex * 4;
    if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x100) {
        hitMode = 3;
    } else {
        hitMode = 1;
    }
    hitModeDelay = (s16)hitMode;
    if (isKind3 == 0) {
        skillSpritePacket = (BtlPacketTiming *)(btlEffectCreateSpriteFramePacket(*(u32 *)(actionBytes + 0x30), (u16) skill));
        skillSpritePacket->delay = (s16) hitModeDelay;
        skillSpritePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)skillSpritePacket, 3);
    } else {
        actionSpritePacket = (BtlPacketTiming *)(btlPacketCreateSpriteStep((u32)((BtlAction *)actionBytes)->unit, act->field70));
        actionSpritePacket->delay = (s16) hitModeDelay;
        actionSpritePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)actionSpritePacket, 3);
    }
    if (altCamera == 1) {
        if ((isKind3 == 0) && (noOverride == 0)) {
            if ((hasCutinPartner == 0) && (reuseLinkedModel == 0)) {
                if (side == 0) {
                    if (!(act->flags & 0x40) && ((((s32)(btlActionAnyTargetHitRowStatus(actionBytes)) != (s32)(0)) && (datCalcRandomBelow(0x64U) < 0x14U)) || (((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x1000))) {
                        hasCutin = 1;
                        act->flags = (u16) (act->flags | 0x40);
                        cutinBattle = (u8 *)(iGpffffb3ac);
                        ((BtlBattleState *)cutinBattle)->battleFlags = (s32) (((BtlBattleState *)cutinBattle)->battleFlags & ~0x1000);
                    }
                } else if ((side == 1) && (((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x800)) {
                    flagsSnapshot = (u16)(act->flags);
                    if (!(flagsSnapshot & 0x40)) {
                        hasCutin = 1;
                        act->flags = (u16) (flagsSnapshot | 0x40);
                    }
                }
            }
            skillU16 = skill;
            isSkill16 = ((s16)datCalcSkillElement(NULL, (u16)skillU16) == 0x10);
            if ((s32)(btlActionHasFormationSlot(actionBytes, (u8 *)effectHandles)) == (s32)(0)) {
                effectBattle = (u8 *)(iGpffffb3ac);
                effectHandles[0] = ((s32)((BtlBattleState *)effectBattle)->formations[11]);
                effectHandles[1] = ((s32)((BtlBattleState *)effectBattle)->formations[12]);
                effectHandles[2] = ((s32)((BtlBattleState *)effectBattle)->formations[13]);
            }
            if (((s32)(btlTargetIsEntryActive(skill)) == (s32)(0)) && ((s32)(btlActionAnyTargetSpecialHit(actionBytes)) == (s32)(0))) {
                targetGroup = (s32)((u16)btlTargetGetUnitIndex((BtlTarget *)(actionBytes + 0x38)));
                if ((side == 0) && (((u16)targetGroup) == 2)) {
                    randomFlag = (s32)((effMiscRand(0) & 1)) != (s32)(0);
                } else if ((side == 1) && (((u16)targetGroup) == 1)) {
                    randomFlag = 1;
                }
            }
            if (((s32)(btlUnitSkillBlocked(actionBytes, linkedUnit)) != (s32)(0)) || (((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x40)) {
                randomFlag = 1;
            }
            if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x4000) {
                randomFlag = 1;
                baseDelay = 2;
            }
            if ((side == 0) && (btlTargetGroupStateMatches(actionBytes) != 0) && (skillIndex != 0xF4)) {
                restoreBeforeHits = 1;
                randomFlag = 1;
                hasCutin = 0;
                linkedGroupLookAtStopPacket = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
                ((BtlPacket *)linkedGroupLookAtStopPacket)->actionUID = *(s64 *)actionBytes;
                btlPacketEnqueue((u8 *)linkedGroupLookAtStopPacket, 1);
                linkedFlagsBattle = (u8 *)(iGpffffb3ac);
                ((BtlBattleState *)linkedFlagsBattle)->flags = (s32) (((BtlBattleState *)linkedFlagsBattle)->flags | 0x400000);
                linkedStateBattle = (u8 *)(iGpffffb3ac);
                ((BtlBattleState *)linkedStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)linkedStateBattle)->actionEndFlags | 6);
            }
            motionState = (s16)btlUnitGetMotionState(act->unit);
            switch (motionState) {
            case 0:
            case 0x11:
                blendFrames = 0;
                break;
            default:
                blendFrames = 6;
                break;
            }
            if (hasCutin != 0) {
                btlPacketEnqueue((u8 *)btlSoundCreateUnitFlagSetPacket((BtlUnit *)act->unit), 0);
            } else if (isSkill16 != 0) {
                btlPacketEnqueue((u8 *)(btlSoundCreateMarkReadyPacket((u32)act->unit)), 0);
            }
            if (reuseLinkedModel != 0) {
                openingAnimationPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
            } else {
                openingAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 0xD, (u16)blendFrames, 1.0f, 4));
            }
            openingAnimationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)openingAnimationPacket, 0);
            cutinUid = openingAnimationPacket->uid;
            if (reuseLinkedModel == 0) {
                recoveryFrames = btlUnitMotionModelFrames(act->unit, 0xD, 1.0f);
                recoveryFrames += (s16)blendFrames;
            } else {
                recoveryFrames = 0;
            }
            if (reuseLinkedModel != 0) {
                openingCameraPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
            } else {
                if (side == 0) {
                    cameraStateB = 0x14;
                } else {
                    cameraStateB = 0x15;
                }
                openingCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, (u16)cameraStateB));
            }
            openingCameraPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)openingCameraPacket, 0);
            sceneUid = openingCameraPacket->uid;
            if (hasCutin != 0) {
                cutin.mode = 4;
                cutin.unitId = (u16)((((BtlUnit *)((u8 *)(act->unit)))->charId));
                cutinStartPacket = (BtlPacketTiming *)(btlCutinCreatePacket((u8 *)&cutin));
                cutinStartPacket->dependencyKind = 4;
                cutinStartPacket->dependencyUid = cutinUid;
                cutinStartPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)cutinStartPacket, 1);
                cutinEndPacket = (BtlPacketTiming *)btlCutinCreateEndPacket();
                cutinEndPacket->dependencyKind = 4;
                cutinEndPacket->dependencyUid = cutinStartPacket->uid;
                cutinEndPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)cutinEndPacket, 1);
                cutinVoicePacket = (BtlPacketTiming *)(func_001f99c0(actionBytes, 1, ((BtlUnit *)(linkedUnit))->charId, 0, 1));
                cutinVoicePacket->dependencyKind = 5;
                cutinVoicePacket->dependencyUid = cutinEndPacket->uid;
                cutinVoicePacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)cutinVoicePacket, 1);
                cutinSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 0xB));
                cutinSoundPacket->dependencyKind = 5;
                cutinSoundPacket->dependencyUid = cutinEndPacket->uid;
                cutinSoundPacket->actionUid = *(s64 *)actionBytes;
                btlPacketEnqueue((u8 *)cutinSoundPacket, 1);
                cutinUid = cutinEndPacket->uid;
                cutinEndTime = cutinUid;
                recoveryFrames = 0;
            }
            openingFormationPacket = (BtlPacketTiming *)(btlFormationCreateStepPacket(actionBytes,(s32)((act->flags & 0x10)) != (s32)(0), 1));
            openingFormationPacket->dependencyKind = 4;
            openingFormationPacket->dependencyUid = cutinUid;
            openingFormationPacket->delay = (s16) (recoveryFrames - (recoveryFrames >> 3));
            openingFormationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)openingFormationPacket, 0);
            formationEndUid = openingFormationPacket->uid;
            if (rotateFirst != 0) {
                targetList = (s32 *)(act->target);
            } else {
                targetList = 0;
            }
            linkedTurnPacket = (BtlPacketTiming *)(btlFormationCreateTurnPacket((u32)linkedUnit, (u32)actionBytes, (u32)targetList, skillU16));
            linkedTurnPacket->dependencyKind = 5;
            linkedTurnPacket->dependencyUid = formationEndUid;
            linkedTurnPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedTurnPacket, 0);
            if (reuseLinkedModel == 0) {
                if (hasCutin != 0) {
                    cutinModelLoadPacket = (BtlPacketTiming *)(btlUnitCreateModelLoadPacket((u8 *)linkedUnit, ((BtlUnit *)(linkedUnit))->charId, 0x1D));
                    linkedAnimationPacket = (BtlPacketTiming *)((u8 *)cutinModelLoadPacket);
                    cutinModelLoadPacket->dependencyKind = 5;
                    cutinModelLoadPacket->dependencyUid = cutinEndTime;
                    (((BtlPacket *)cutinModelLoadPacket)->dependencyKind3) = 5;
                    (((BtlPacket *)cutinModelLoadPacket)->dependencyUID3) = formationEndUid;
                } else {
                    linkedModelLoadPacket = (u8 *)(btlUnitCreateModelLoadPacket((u8 *)linkedUnit, ((BtlUnit *)(linkedUnit))->charId, 0xD));
                    linkedAnimationPacket = (BtlPacketTiming *)(linkedModelLoadPacket);
                    ((BtlPacketTiming *)linkedModelLoadPacket)->delay = recoveryFrames;
                }
                linkedAnimationPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)linkedAnimationPacket, 1);
            } else {
                linkedModelWaitPacket = (u8 *)(btlPacketCreateImmediate());
                linkedAnimationPacket = (BtlPacketTiming *)(linkedModelWaitPacket);
                ((BtlPacketTiming *)linkedModelWaitPacket)->delay = recoveryFrames;
                btlPacketEnqueue((u8 *)linkedAnimationPacket, 0);
            }
            linkedEffectWaitPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
            linkedEffectWaitPacket->dependencyKind = 4;
            linkedEffectWaitPacket->dependencyUid = linkedAnimationPacket->uid;
            linkedEffectWaitPacket->delay = 0xC;
            linkedEffectWaitPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedEffectWaitPacket, 1);
            linkedOpeningEffectPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket(effectHandles[0], (*(s32 *)(actionBytes + 0x30)), 0, (linkedEffectWaitPacket->uid), 0x100));
            linkedOpeningEffectPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedOpeningEffectPacket, 2);
            linkedOpeningSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 3));
            linkedOpeningSoundPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedOpeningSoundPacket, 1);
            openingSourceUnit = (u8 *)(act->unit);
            skillFramesKey = (s16)btlUnitOpeningMotionMode((s32)((BtlUnit *)(openingSourceUnit))->childUnit, openingSourceUnit, skill, rotateFirst);
            skillFrames = (s32)(btlUnitMotionFrames(((u8 *)((BtlUnit *)((u8 *)(act->unit)))->childUnit), (u16)skillFramesKey, 1.0f));
            damageFrames = (s32) skillFrames;
            windupFrames = (u16)(btlUnitGetMotionTableFrames(act->unit, 0x10));
            chainUid = linkedAnimationPacket->uid;
            skillEndFrame = skillFrames + 0x12;
            if (baseDelay < skillEndFrame) {
                timingFrames = skillEndFrame - baseDelay;
            } else {
                timingFrames = 0;
            }
            sourceCastAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 0xF, 0, 1.0f, 5));
            sourceCastAnimationPacket->dependencyKind = 4;
            sourceCastAnimationPacket->dependencyUid = chainUid;
            sourceCastAnimationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)sourceCastAnimationPacket, 0);
            if (hasCutin != 0) {
                clearUnitSoundFlagPacket = (BtlPacketTiming *)(btlSoundCreateUnitFlagClearPacket((BtlUnit *)act->unit));
                clearUnitSoundFlagPacket->dependencyKind = 4;
                clearUnitSoundFlagPacket->dependencyUid = sourceCastAnimationPacket->uid;
                clearUnitSoundFlagPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)clearUnitSoundFlagPacket, 0);
            } else if (isSkill16 != 0) {
                clearSoundReadyPacket = (BtlPacketTiming *)(btlSoundCreateClearReadyPacket((u32)act->unit));
                clearSoundReadyPacket->dependencyKind = 4;
                clearSoundReadyPacket->dependencyUid = sourceCastAnimationPacket->uid;
                clearSoundReadyPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)clearSoundReadyPacket, 0);
            }
            recoveryBase = (s32)(btlUnitMotionFrames(act->unit, 0xFU, 1.0f));
            linkedCastEffectPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket(effectHandles[1], (*(s32 *)(actionBytes + 0x30)), 0, 0, 0x100));
            linkedCastEffectPacket->dependencyKind = 4;
            linkedCastEffectPacket->dependencyUid = chainUid;
            linkedCastEffectPacket->delay = (s16) recoveryBase;
            linkedCastEffectPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedCastEffectPacket, 2);
            linkedCastSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 4));
            linkedCastSoundPacket->dependencyKind = 4;
            linkedCastSoundPacket->dependencyUid = chainUid;
            linkedCastSoundPacket->delay = (s16)recoveryBase + 2;
            linkedCastSoundPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedCastSoundPacket, 1);
            linkedCastTrailPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket(effectHandles[2], (*(s32 *)(actionBytes + 0x30)), 0, 0, 0x100));
            linkedCastTrailPacket->dependencyKind = 4;
            linkedCastTrailPacket->dependencyUid = chainUid;
            linkedCastTrailPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedCastTrailPacket, 2);
            sourceDimPacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)act->unit, 0xFF808080, 0, 0xC, 4, 0));
            sourceDimPacket->dependencyKind = 4;
            sourceDimPacket->dependencyUid = chainUid;
            sourceDimPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)sourceDimPacket, 1);
            linkedCastAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)linkedUnit, skillFramesKey, 0, 1.0f, 2));
            animPacket = (BtlPacketTiming *)(linkedCastAnimationPacket);
            linkedCastAnimationPacket->dependencyKind = 4;
            linkedCastAnimationPacket->dependencyUid = chainUid;
            linkedCastAnimationPacket->delay = 0xF;
            linkedCastAnimationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
            linkedAlphaPacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)linkedUnit, (u32)(btlUnitGetPersonaAlphaColor(linkedUnit)), 8, 0, 3, 1));
            linkedAlphaPacket->dependencyKind = 4;
            linkedAlphaPacket->dependencyUid = animPacket->uid;
            linkedAlphaPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedAlphaPacket, 1);
            linkedCastCuePacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xD, 2, 5));
            linkedCastCuePacket->dependencyKind = 4;
            linkedCastCuePacket->dependencyUid = animPacket->uid;
            linkedCastCuePacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)linkedCastCuePacket, 1);
            if ((randomFlag == 1) && (restoreBeforeHits == 0) && !((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x40)) {
                if (side == 0) {
                    cameraStateC = 0x19;
                } else {
                    cameraStateC = 0x1A;
                }
                linkedHitCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, (u16)cameraStateC));
                linkedHitCameraPacket->dependencyKind = 4;
                linkedHitCameraPacket->dependencyUid = animPacket->uid;
                if (damageFrames >= baseDelay) {
                    cameraDelay = damageFrames - baseDelay;
                } else {
                    cameraDelay = 0;
                }
                linkedHitCameraPacket->delay = cameraDelay;
                linkedHitCameraPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)linkedHitCameraPacket, 0);
            }
            animEndUid = animPacket->uid;
        } else if ((isKind3 == 1) || (noOverride == 1)) {
            if ((side == 0) && (btlTargetGroupStateMatches(actionBytes) != 0) && (skillIndex != 0xF4)) {
                restoreBeforeHits = 1;
                randomFlag = 1;
                alternateLookAtStopPacket = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
                ((BtlPacket *)alternateLookAtStopPacket)->actionUID = *(s64 *)actionBytes;
                btlPacketEnqueue((u8 *)alternateLookAtStopPacket, 1);
                alternateFlagsBattle = (u8 *)(iGpffffb3ac);
                ((BtlBattleState *)alternateFlagsBattle)->flags = (s32) (((BtlBattleState *)alternateFlagsBattle)->flags | 0x400000);
                alternateStateBattle = (u8 *)(iGpffffb3ac);
                ((BtlBattleState *)alternateStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)alternateStateBattle)->actionEndFlags | 6);
            }
            alternateCastAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 0x16, 6, 1.0f, 0));
            animPacket = (BtlPacketTiming *)(alternateCastAnimationPacket);
            alternateCastAnimationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
            sceneUid = animPacket->uid;
            chainUid = 0;
                    timingFrames = btlUnitMotionFrames(act->unit, 0x16U, 1.0f) + 6;
            if (!((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x40)) {
                if ((s32)(btlActionHasNoTargetClass(actionBytes)) == (s32)(1)) {
                    alternateFormationPacket = (BtlPacketTiming *)(btlFormationCreateStepPacket(actionBytes, 0, 1));
                    alternateFormationPacket->dependencyKind = 4;
                    alternateFormationPacket->dependencyUid = animPacket->uid;
                    alternateFormationPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)alternateFormationPacket, 0);
                }
                if (randomFlag == 0) {
                    alternateCastCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x19));
                    alternateCastCameraPacket->dependencyKind = 4;
                    alternateCastCameraPacket->dependencyUid = animPacket->uid;
                    alternateCastCameraPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)alternateCastCameraPacket, 0);
                } else {
                    alternateGroupCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x1B));
                    alternateGroupCameraPacket->dependencyKind = 4;
                    alternateGroupCameraPacket->dependencyUid = animPacket->uid;
                    alternateGroupCameraPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)alternateGroupCameraPacket, 0);
                }
            }
            if (noOverride == 0) {
                alternateCastEffectPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket((s32)((BtlBattleState *)iGpffffb3ac)->formations[33], ((s32)((BtlAction *)actionBytes)->unit), btlActionAddEffectDelay(timingFrames), 0, 0x100));
                alternateCastEffectPacket->dependencyKind = 4;
                alternateCastEffectPacket->dependencyUid = animPacket->uid;
                btlPacketEnqueue((u8 *)alternateCastEffectPacket, 1);
            }
        }
    } else if ((altCamera == 0) && (side == 1)) {
        restoreMotionSpeed = 1;
        if ((s32)(btlBossSkillRestoresMotionBeforeHits(actionBytes, skillIndex)) != (s32)(0)) {
            restoreBeforeHits = 1;
            hasCutin = 0;
            enemyLookAtStopPacket = (u8 *)(btlUnitCreateLookAtDeactivatePacket(0, 3));
            ((BtlPacket *)enemyLookAtStopPacket)->actionUID = *(s64 *)actionBytes;
            btlPacketEnqueue((u8 *)enemyLookAtStopPacket, 1);
            enemyFlagsBattle = (u8 *)(iGpffffb3ac);
            ((BtlBattleState *)enemyFlagsBattle)->flags = (s32) (((BtlBattleState *)enemyFlagsBattle)->flags | 0x400000);
            enemyStateBattle = (u8 *)(iGpffffb3ac);
            ((BtlBattleState *)enemyStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)enemyStateBattle)->actionEndFlags | 6);
        }
        if (actionFlag4000 == 0) {
            animSpeed = 1.0f;
        } else {
            animSpeed = 2.0f;
            skipMotionRecovery = 1;
            acceleratedFlagsBattle = (u8 *)(iGpffffb3ac);
            ((BtlBattleState *)acceleratedFlagsBattle)->flags = (s32) (((BtlBattleState *)acceleratedFlagsBattle)->flags | 0x400000);
            acceleratedStateBattle = (u8 *)(iGpffffb3ac);
            ((BtlBattleState *)acceleratedStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)acceleratedStateBattle)->actionEndFlags | 0x47);
        }
        if ((skillFlag2 == 1) || ((s32)(btlTargetIsEntryActive(skill)) != (s32)(0))) {
            animMotion = 4;
            animBlend = 2;
        } else {
            animMotion = 8;
            animBlend = 3;
        }
        if ((s32)((((BtlUnit *)((u8 *)(act->unit)))->genus)) == (s32)(1)) {
            if ((s32)(btlActionMatchesSkill(actionBytes, skillIndex)) != (s32)(0)) {
                animBlend = 2;
                restoreMotionSpeed = 0;
                skipMotionRecovery = 1;
                specialFlagsBattle = (u8 *)(iGpffffb3ac);
                ((BtlBattleState *)specialFlagsBattle)->flags = (s32) (((BtlBattleState *)specialFlagsBattle)->flags | 0x400000);
                specialStateBattle = (u8 *)(iGpffffb3ac);
                ((BtlBattleState *)specialStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)specialStateBattle)->actionEndFlags | 7);
            } else if (btlActionGetStridedCameraField(((BtlUnit *)(act->unit))->charId, (s16 *)(iGpffffb3cc + 0x18)) & 1) {
                animBlend = 0;
                settleMotion = 1;
                restoreMotionSpeed = 0;
            }
        }
        if (!((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x100)) {
            if ((s32)(btlUnitSlotIsOpen(actionBytes, animMotion)) != (s32)(0)) {
                enemyCastAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, animMotion, 6, animSpeed, animBlend));
                animPacket = (BtlPacketTiming *)(enemyCastAnimationPacket);
                enemyCastAnimationPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            } else {
                enemyMotionWaitPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
                animPacket = (BtlPacketTiming *)(enemyMotionWaitPacket);
                enemyMotionWaitPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            }
            if ((actionFlag4000 == 0) && ((s32)(btlBossActionBlocked(actionBytes, skillIndex)) != (s32)(0))) {
                enemyCastCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x15));
                enemyCastCameraPacket->dependencyKind = 4;
                enemyCastCameraPacket->dependencyUid = animPacket->uid;
                enemyCastCameraPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)enemyCastCameraPacket, 0);
            }
        } else {
            enemyCastWaitPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
            animPacket = (BtlPacketTiming *)(enemyCastWaitPacket);
            enemyCastWaitPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
        }
        sceneUid = animPacket->uid;
        chainUid = 0;
            timingFrames = btlUnitMotionFrames(act->unit, (u16) animMotion, animSpeed) + 6;
        if (!((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x40) && (restoreBeforeHits == 0)) {
            enemyFormationPacket = (BtlPacketTiming *)(btlFormationCreateStepPacket(actionBytes,(s32)((act->flags & 0x10)) != (s32)(0), 1));
            enemyFormationPacket->dependencyKind = 4;
            enemyFormationPacket->dependencyUid = animPacket->uid;
            if (actionFlag4000 == 0) {
                if (timingFrames > 0xc) {
                    formationDelay = timingFrames - 0xC;
                } else {
                    formationDelay = 0;
                }
                enemyFormationPacket->delay = formationDelay;
            }
            enemyFormationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)enemyFormationPacket, 0);
            formationEndUid = enemyFormationPacket->uid;
            enemyFormationCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x1A));
            enemyFormationCameraPacket->dependencyKind = 4;
            enemyFormationCameraPacket->dependencyUid = formationEndUid;
            enemyFormationCameraPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)enemyFormationCameraPacket, 0);
        }
        if ((skillFlag2 == 0) && (noOverride == 0)) {
            followState = (s32)(btlActionSelectFormationSlot(actionBytes));
            if (followState == 0) {
                followState = (s32)((BtlBattleState *)iGpffffb3ac)->formations[15];
            }
            enemyCastEffectPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket(followState, (*(s32 *)(actionBytes + 0x30)), btlActionAddEffectDelay(timingFrames), 0, 0x100));
            enemyCastEffectPacket->dependencyKind = 4;
            enemyCastEffectPacket->dependencyUid = animPacket->uid;
            btlPacketEnqueue((u8 *)enemyCastEffectPacket, 1);
            enemyCastSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 7));
            enemyCastSoundPacket->dependencyKind = 4;
            enemyCastSoundPacket->dependencyUid = animPacket->uid;
            btlPacketEnqueue((u8 *)enemyCastSoundPacket, 1);
        }
    } else if ((altCamera == 0) && (side == 0)) {
        skipMotionRecovery = 1;
        sourceOpeningEffectPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket((s32)((BtlBattleState *)iGpffffb3ac)->formations[45], ((s32)((BtlAction *)actionBytes)->unit), 0, 0, 0x100));
        sourceOpeningEffectPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)sourceOpeningEffectPacket, 2);
        sourceOpeningAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 6, 0, 1.0f, 2));
        sourceOpeningAnimationPacket->duration = (s16)(btlUnitMotionModelFrames(act->unit, 6, 1.0f));
        sourceOpeningAnimationPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)sourceOpeningAnimationPacket, 0);
        sourceOpeningSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 0x11));
        sourceOpeningSoundPacket->delay = 1;
        sourceOpeningSoundPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)sourceOpeningSoundPacket, 1);
        sourceOpeningCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x12));
        sourceOpeningCameraPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)sourceOpeningCameraPacket, 0);
        sourceActionAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)act->unit, 7, 6, 1.0f, 2));
        animPacket = (BtlPacketTiming *)(sourceActionAnimationPacket);
        sourceActionAnimationPacket->dependencyKind = 4;
        sourceActionAnimationPacket->dependencyUid = sourceOpeningAnimationPacket->uid;
        sourceActionAnimationPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)animPacket, 0);
        sceneUid = 0;
        chainUid = animPacket->uid;
        timingFrames = btlUnitMotionFrames(act->unit, 7U, 1.0f) + 6;
        if (act->targetCount == 1) {
            firstTarget = (u8 *)(act->target);
            if ((s32)(firstTarget) != (s32)(0)) {
                sourceTargetWaitPacket = (BtlPacketTiming *)(btlFormationCreateWaitPacket((u32)act->unit, (u32)((u8*)((BtlAction *)firstTarget)->unit), 4));
                sourceTargetWaitPacket->dependencyKind = 4;
                sourceTargetWaitPacket->dependencyUid = chainUid;
                sourceTargetWaitPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)sourceTargetWaitPacket, 0);
            }
        }
        sourceActionCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x13));
        sourceActionCameraPacket->dependencyKind = 4;
        sourceActionCameraPacket->dependencyUid = chainUid;
        sourceActionCameraPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)sourceActionCameraPacket, 0);
        sourceFlagsBattle = (u8 *)(iGpffffb3ac);
        ((BtlBattleState *)sourceFlagsBattle)->flags = (s32) (((BtlBattleState *)sourceFlagsBattle)->flags | 0x400000);
        sourceStateBattle = (u8 *)(iGpffffb3ac);
        ((BtlBattleState *)sourceStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)sourceStateBattle)->actionEndFlags | 0xF);
    }
    skillKey = (s16)skill;
    btlMainSkillColorPairDefaults(skillKey, &cameraFirst, &cameraSecond);
    skillColorLerpPacket = (BtlPacketTiming *)(btlMainCreateColorLerpPacket(cameraFirst, cameraSecond, 0x10));
    skillColorLerpPacket->dependencyKind = 4;
    skillColorLerpPacket->dependencyUid = sceneUid;
    skillColorLerpPacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)skillColorLerpPacket, 1);
    cameraKind = (s32)(btlMainSkillColorDefault(skillKey));
    btlMainSkillColorPairDefaultsAlt(skillKey, &cameraFirst, &cameraSecond);
    skillColorWorkPacket = (BtlPacketTiming *)(btlMainCreateColorWorkPacket(cameraKind, cameraFirst, cameraSecond, 0x10, ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags & 2) ? 1 : 0)));
    skillColorWorkPacket->dependencyKind = 4;
    skillColorWorkPacket->dependencyUid = sceneUid;
    skillColorWorkPacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)skillColorWorkPacket, 1);
    skillTintPacket = (BtlPacketTiming *)(btlMainCreateTintPacket(btlMainSkillTintDefault((u16) skill), 0x10));
    skillTintPacket->dependencyKind = 4;
    skillTintPacket->dependencyUid = sceneUid;
    skillTintPacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)skillTintPacket, 1);
    sourceTintPacket = (BtlPacketTiming *)(btlMainCreateUnitTintPacket((BtlAction *)actionBytes, (u16) skill, 8));
    sourceTintPacket->dependencyKind = 4;
    sourceTintPacket->dependencyUid = sceneUid;
    sourceTintPacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)sourceTintPacket, 1);
    if (hasFollowAction != 0) {
        followActionPtr = (u8 *)(act->followAction);
        firstTargetEntry = (u8 *)(act->target);
        primaryTarget = (u8 *)(firstTargetEntry);
        followMovementPacket = (BtlPacketTiming *)(btlFormationCreateWaitPacket((u32)(*(u8 **)(followActionPtr + 0x30)), (u32)(*(u8 **)(firstTargetEntry + 0x30)), 2));
        followMovementPacket->dependencyKind = 4;
        followMovementPacket->dependencyUid = chainUid;
        followMovementPacket->delay = timingFrames;
        followMovementPacket->duration = (s16) ((btlUnitMotionModelFrames((*( u8 ** )((u8 *)((s32 *)(u32)followActionPtr) + (0x30))), 0x1A, 1.0f)) - 1);
        followMovementPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followMovementPacket, 0);
        followActionCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x1E));
        followActionCameraPacket->dependencyKind = 4;
        followActionCameraPacket->dependencyUid = chainUid;
        followActionCameraPacket->delay = timingFrames;
        followActionCameraPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followActionCameraPacket, 0);
        followActionVoicePacket = (BtlPacketTiming *)(func_001f99c0((s32 *)(u32)followActionPtr, 0xD, 0U, 0, 0));
        followActionVoicePacket->dependencyKind = 4;
        followActionVoicePacket->dependencyUid = chainUid;
        followActionVoicePacket->delay = timingFrames;
        followActionVoicePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followActionVoicePacket, 1);
        followActionAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(followActionPtr + 0x30), 0x1A, 0, 1.0f, 0));
        followActionAnimationPacket->dependencyKind = 4;
        followActionAnimationPacket->dependencyUid = chainUid;
        followActionAnimationPacket->delay = timingFrames;
        followActionAnimationPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followActionAnimationPacket, 0);
        followTargetAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(firstTargetEntry + 0x30), 0x1A, 0, 1.0f, 2));
        followTargetAnimationPacket->dependencyKind = 4;
        followTargetAnimationPacket->dependencyUid = chainUid;
        followTargetAnimationPacket->delay = timingFrames;
        followTargetAnimationPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followTargetAnimationPacket, 0);
        chainUid = followMovementPacket->uid;
        timingFrames = 0;
        followFormationCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x1A));
        followFormationCameraPacket->dependencyKind = 4;
        followFormationCameraPacket->dependencyUid = chainUid;
        followFormationCameraPacket->delay = 0;
        followFormationCameraPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followFormationCameraPacket, 0);
        followTargetWaitPacket = (BtlPacketTiming *)(btlFormationCreateWaitPacket((u32)(*(u8 **)(followActionPtr + 0x30)), (u32)(*(u8 **)(firstTargetEntry + 0x30)), 3));
        followTargetWaitPacket->dependencyKind = 4;
        followTargetWaitPacket->dependencyUid = chainUid;
        followTargetWaitPacket->delay = 0;
        followTargetWaitPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followTargetWaitPacket, 0);
        followTargetRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket(*(u8 **)(firstTargetEntry + 0x30), act->unit, 2));
        followTargetRotationPacket->dependencyKind = 4;
        followTargetRotationPacket->dependencyUid = chainUid;
        followTargetRotationPacket->delay = 0;
        followTargetRotationPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followTargetRotationPacket, 1);
        followTargetRecoveryPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)(u8*)((BtlAction *)firstTargetEntry)->unit, 0xA, 0, 1.0f, 1));
        followTargetRecoveryPacket->dependencyKind = 4;
        followTargetRecoveryPacket->dependencyUid = chainUid;
        followTargetRecoveryPacket->delay = 0;
        followTargetRecoveryPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followTargetRecoveryPacket, 0);
        followSourceRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket((u8*)((BtlAction *)followActionPtr)->unit, act->unit, 2));
        followSourceRotationPacket->dependencyKind = 4;
        followSourceRotationPacket->dependencyUid = chainUid;
        followSourceRotationPacket->delay = 0;
        followSourceRotationPacket->flags = (u8) (followSourceRotationPacket->flags & 0xDF);
        followSourceRotationPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followSourceRotationPacket, 1);
        followFlagsBattle = (u8 *)(iGpffffb3ac);
        ((BtlBattleState *)followFlagsBattle)->flags = (s32) (((BtlBattleState *)followFlagsBattle)->flags | 0x400000);
        followStateBattle = (u8 *)(iGpffffb3ac);
        ((BtlBattleState *)followStateBattle)->actionEndFlags = (u16) (((BtlBattleState *)followStateBattle)->actionEndFlags | 0xF);
    }
    btlFormationFormatName(skillKey, formation);
    if (hasCutin != 0) {
        skillNameWaitPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
        skillNameWaitPacket->dependencyKind = 4;
        skillNameWaitPacket->dependencyUid = chainUid;
        skillNameWaitPacket->delay = timingFrames;
        btlPacketEnqueue((u8 *)skillNameWaitPacket, 1);
        if (actionFlag4000 == 0) {
            skillNamePacket = (BtlPacketTiming *)(btlFormationCreateNamedPacket(formationHandle, formation, 1));
        } else {
            skillNamePacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
        }
        skillNamePacket->dependencyKind = 5;
        skillNamePacket->dependencyUid = cutinEndTime;
        (((BtlPacket *)skillNamePacket)->dependencyKind3) = 5;
        ((BtlPacket *)skillNamePacket)->dependencyUID3 = skillNameWaitPacket->uid;
        skillNamePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)skillNamePacket, 1);
        if (actionFlag4000 == 0) {
            skillSoundPacket = (BtlPacketTiming *)(btlSoundCreateSkillSEPacket(skillKey, 1));
        } else {
            skillSoundPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
        }
        skillSoundPacket->dependencyKind = 5;
        skillSoundPacket->dependencyUid = cutinEndTime;
        btlPacketEnqueue((u8 *)skillSoundPacket, 1);
    } else {
        if (actionFlag4000 == 0) {
            skillNamePacket = (BtlPacketTiming *)(btlFormationCreateNamedPacket(formationHandle, formation, 0));
        } else {
            skillNamePacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
        }
        skillNamePacket->dependencyKind = 4;
        skillNamePacket->dependencyUid = chainUid;
        skillNamePacket->delay = timingFrames;
        skillNamePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)skillNamePacket, 1);
        if (actionFlag4000 == 0) {
            skillSoundPacket = (BtlPacketTiming *)(btlSoundCreateSkillSEPacket(skillKey, 0));
        } else {
            skillSoundPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
        }
        skillSoundPacket->dependencyKind = 4;
        skillSoundPacket->dependencyUid = skillNamePacket->uid;
        btlPacketEnqueue((u8 *)skillSoundPacket, 1);
    }
    primaryTarget = (act->targetCount == 1) ? ((hasFollowAction != 0) ? (u8 *)(act->followAction) : primaryTarget) : (u8 *)(actionBytes);
    openingSkillFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(actionBytes + 0x30), *(u32 *)(primaryTarget + 0x30), 0, 0));
    skillFormationPacket = (BtlPacketTiming *)(openingSkillFormationPacket);
    openingSkillFormationPacket->dependencyKind = 4;
    openingSkillFormationPacket->dependencyUid = skillNamePacket->uid;
    (((BtlPacket *)openingSkillFormationPacket)->dependencyKind2) = 4;
    ((BtlPacket *)openingSkillFormationPacket)->dependencyUID2 = skillSoundPacket->uid;
    if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x80) {
        skillFormationPacket->actionUid = actionId;
    }
    btlPacketEnqueue((u8 *)skillFormationPacket, 2);
    formationEndUid2 = skillFormationPacket->uid;
    if (actionFlag4000 == 0) {
        openingCueQueuePacket = (BtlPacketTiming *)(btlSoundCreateCueQueuePacket(0));
        openingCueQueuePacket->dependencyKind = 5;
        openingCueQueuePacket->dependencyUid = skillFormationPacket->uid;
        btlPacketEnqueue((u8 *)openingCueQueuePacket, 1);
    }
    targetRecoveryCameraPacket = 0;
    cameraState = 0x18;
    hitTimeTotal = 0;
    if (actionFlag4000 != 0) {
        hitDelayBase = 4;
    } else {
        hitDelayBase = (s32)((u16)btlUnitSlotValueOrOne(skillKey));
    }
    hitDelta = (u16)hitDelayBase;
    hitWait = 0;
    targetIndex = 0;
    skillS32 = (s32)(u32)skill;
    skillKeyCopy = skillKey;
    while ((targetIndexS32 = (s32)targetIndex) < act->targetCount) {
            /* Per-target signed index, bound once like an inlined helper parameter; retail keeps targetIndexS32 as a word. */
            s32 targetPos = targetIndexS32;
            targetAction = (u8 *)(((s32*)((BtlAction *)actionBytes)->targets[targetIndex]));
            rowHitCount = (u16) *(u8 *)(targetAction + 0xD9);
            hitTimer = 0;
            hitFlags = (s32)(s32)(btlFormationGetFlags((s32)(targetAction) + 0xD8));
            if (hasFollowAction != 0) {
                effectiveAction = (u8 *)(act->followAction);
            } else if (((BtlAction *)targetAction)->targetBlock.specialHitFlag != 0) {
                effectiveAction = (u8 *)(actionBytes);
            } else {
                effectiveAction = (u8 *)(targetAction);
            }
            targetHitValue = (s32)(*(s32 *)(targetAction + 0xE0));
            if ((targetHitValue != 0) && ((s32)((((BtlUnit *)((u8 *)(act->unit)))->genus)) != (s32)((((BtlUnit *)((u8 *)((u8*)((BtlAction *)effectiveAction)->unit)))->genus)))) {
                crossSideHits += 1;
            }
            if ((*( s32 * )((u8 *)(((s32)(targetAction) + ((u32)rowHitCount << 5))) + (0xD8))) & 0x100000) {
                statusHits += 1;
                statusMask |= ((BtlAction *)targetAction)->targetBlock.targetFlags;
            }
            hitTargetUnit = (u8 *)(*(u8 **)(effectiveAction + 0x30));
            hitSide = (u8)(((BtlUnit *)(hitTargetUnit))->genus);
            sameSideTarget = (hitSide == 1) ? ((((BtlEnemyBattleParameters *)(iGpffffb3cc + ((BtlUnit *)(hitTargetUnit))->charId * 0xE8))->flags & 0x40) != 0) ^ 1 : 1;
            if ((targetHitValue != 0) || (((BtlAction *)targetAction)->targetBlock.specialHitFlag != 0)) {
                cameraState = 0x1E;
            }
            targetHpRatioPacket = (BtlPacketTiming *)(btlPacketCreateHpRatio(hitTargetUnit));
            targetHpRatioPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)targetHpRatioPacket, 1);
            if ((*(u16 *)(targetAction + 0xDC) != 0x400) && (((BtlAction *)targetAction)->targetBlock.specialHitFlag != 1)) {
                skillFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(actionBytes + 0x30), *(u32 *)(effectiveAction + 0x30), 1, hitFlags | 0x1000));
                if ((s32)(targetRecoveryCameraPacket) == (s32)(0)) {
                    if (!((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x2000)) {
                        skillFormationPacket->dependencyKind = 4;
                        skillFormationPacket->dependencyUid = skillNamePacket->uid;
                        (((BtlPacket *)skillFormationPacket)->dependencyKind2) = 4;
                        ((BtlPacket *)skillFormationPacket)->dependencyUID2 = skillSoundPacket->uid;
                    } else {
                        skillFormationPacket->dependencyKind = 4;
                        skillFormationPacket->dependencyUid = formationEndUid2;
                    }
                    (((BtlPacketTiming *)skillFormationPacket)->delay) = hitTimeTotal;
                } else {
                    skillFormationPacket->dependencyKind = 4;
                    skillFormationPacket->dependencyUid = ((BtlPacket *)(u8 *)targetRecoveryCameraPacket)->uid;
                }
                if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x80) {
                    skillFormationPacket->actionUid = actionId;
                }
                btlPacketEnqueue((u8 *)skillFormationPacket, 2);
                if (actionFlag4000 == 0) {
                    targetCueQueuePacket = (BtlPacketTiming *)(btlSoundCreateCueQueuePacket(1));
                    targetCueQueuePacket->dependencyKind = 5;
                    targetCueQueuePacket->dependencyUid = skillFormationPacket->uid;
                    btlPacketEnqueue((u8 *)targetCueQueuePacket, 1);
                } else {
                    skillKindRow = (s16)datCalcSkillElement(NULL, skillKeyCopy);
                    switch (skillKindRow) {                /* switch 2; irregular */
                    case 16:                            /* switch 2 */
                        targetElementCuePacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0x16));
                        break;
                    case 17:                            /* switch 2 */
                        targetElementCuePacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0x19));
                        break;
                    default:                            /* switch 2 */
                        targetElementCuePacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0x15));
                        break;
                    }
                    targetElementCuePacket->dependencyKind = 5;
                    targetElementCuePacket->dependencyUid = skillFormationPacket->uid;
                    btlPacketEnqueue((u8 *)targetElementCuePacket, 1);
                }
            } else {
                reflectedSkillFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(actionBytes + 0x30), *(u32 *)(effectiveAction + 0x30), 1, hitFlags | 0xC00));
                skillFormationPacket = (BtlPacketTiming *)(reflectedSkillFormationPacket);
                reflectedSkillFormationPacket->dependencyKind = 4;
                reflectedSkillFormationPacket->dependencyUid = skillNamePacket->uid;
                (((BtlPacket *)reflectedSkillFormationPacket)->dependencyKind2) = 4;
                ((BtlPacket *)reflectedSkillFormationPacket)->dependencyUID2 = skillSoundPacket->uid;
                (((BtlPacketTiming *)reflectedSkillFormationPacket)->delay) = hitTimeTotal;
                if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x80) {
                    skillFormationPacket->actionUid = actionId;
                }
                btlPacketEnqueue((u8 *)skillFormationPacket, 2);
                if ((((BtlAction *)targetAction)->targetBlock.hitOutcome != 0x400) && (*(s32 *)(targetAction + 0xE4) == 1) && (targetPos == 0)) {
                    reflectedFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket(formationHandle, *(u32 *)(actionBytes + 0x30), *(u32 *)(effectiveAction + 0x30), 1, hitFlags | 0x1000));
                    reflectedFormationPacket->dependencyKind = 5;
                    reflectedFormationPacket->dependencyUid = skillFormationPacket->uid;
                    if ((((BtlAction *)targetAction)->targetBlock.specialHitFlag != 0) && ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 8)) {
                        reflectedFormationPacket->delay = 8;
                    }
                    reflectedFormationPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)reflectedFormationPacket, 2);
                    if (actionFlag4000 == 0) {
                        reflectedCueQueuePacket = (BtlPacketTiming *)(btlSoundCreateCueQueuePacket(1));
                        reflectedCueQueuePacket->dependencyKind = 5;
                        reflectedCueQueuePacket->dependencyUid = reflectedFormationPacket->uid;
                        btlPacketEnqueue((u8 *)reflectedCueQueuePacket, 1);
                    }
                }
            }
            if (rotateFirst != 0) {
                if (bossCheck != 0) {
                    targetFocusPacket = (BtlPacketTiming *)(btlActionCreateLookAtUnitPacketBytes(0, *(u8 **)(effectiveAction + 0x30), 3));
                    targetFocusPacket->dependencyKind = 5;
                    targetFocusPacket->dependencyUid = skillFormationPacket->uid;
                    targetFocusPacket->actionUid = *(s64 *)actionBytes;
                    btlPacketEnqueue((u8 *)targetFocusPacket, 1);
                    if ((s32)(effectiveAction) != (s32)(actionBytes)) {
                        targetLookAtSourcePacket = (BtlPacketTiming *)(btlActionCreateLookAtUnitPacketBytes((u8*)((BtlAction *)effectiveAction)->unit, act->unit, 0));
                        targetLookAtSourcePacket->dependencyKind = 5;
                        targetLookAtSourcePacket->dependencyUid = skillFormationPacket->uid;
                        targetLookAtSourcePacket->actionUid = *(s64 *)actionBytes;
                        btlPacketEnqueue((u8 *)targetLookAtSourcePacket, 1);
                    } else {
                        targetLookAtStopPacket = (BtlPacketTiming *)(btlUnitCreateLookAtDeactivatePacket((u8*)((BtlAction *)effectiveAction)->unit, 0));
                        targetLookAtStopPacket->dependencyKind = 5;
                        targetLookAtStopPacket->dependencyUid = skillFormationPacket->uid;
                        targetLookAtStopPacket->actionUid = *(s64 *)actionBytes;
                        btlPacketEnqueue((u8 *)targetLookAtStopPacket, 1);
                    }
                    act->flags = (u16) (act->flags | 0x200);
                }
            } else if ((targetPos == 0) && (side == 0)) {
                targetGroup2 = (s32)((u16)btlTargetGetUnitIndex((BtlTarget *)(actionBytes + 0x38)));
                if (targetGroup2 == 2) {
                    btlUnitGetGroupBounds(targetGroup2, 1, &targetPosition, 0, 0, 1);
                    targetGroupLookAtPacket = (BtlPacketTiming *)(btlUnitCreateLookAtPacket(0, &targetPosition, 1));
                    targetGroupLookAtPacket->dependencyKind = 5;
                    targetGroupLookAtPacket->dependencyUid = skillFormationPacket->uid;
                    targetGroupLookAtPacket->actionUid = *(s64 *)actionBytes;
                    btlPacketEnqueue((u8 *)targetGroupLookAtPacket, 1);
                }
            }
            if (restoreBeforeHits == 1) {
                if ((s32)(targetRecoveryCameraPacket) == (s32)(0)) {
                    if ((altCamera == 1) && (isKind3 == 0) && (noOverride == 0)) {
                        linkedHidePacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)linkedUnit, 0, 0, 0, 4, 0));
                        linkedHidePacket->dependencyKind = 5;
                        linkedHidePacket->dependencyUid = skillFormationPacket->uid;
                        linkedHidePacket->actionUid = actionId;
                        btlPacketEnqueue((u8 *)linkedHidePacket, 0);
                    }
                    if (skipMotionRecovery == 0) {
                        if (restoreMotionSpeed == 0) {
                            earlyMotionRecoveryPacket = (BtlPacketTiming *)(btlUnitCreateMotionRequestPacket(act->unit, windupFrames));
                        } else {
                            /* Retail 001a9e5c/001ab480/001ab668 pass 1.0f in $f12. */
                            earlyMotionRecoveryPacket = (BtlPacketTiming *)(btlUnitCreateMotionSpeedPacket((BtlUnit *)((u8*)((BtlAction *)actionBytes)->unit), 0, 1.0f, 0));
                        }
                        earlyMotionRecoveryPacket->dependencyKind = 5;
                        earlyMotionRecoveryPacket->dependencyUid = skillFormationPacket->uid;
                        earlyMotionRecoveryPacket->actionUid = actionId;
                        btlPacketEnqueue((u8 *)earlyMotionRecoveryPacket, 0);
                    }
                    earlyColorRestorePacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)act->unit, -1, 0, 0, 3, 0));
                    earlyColorRestorePacket->dependencyKind = 5;
                    earlyColorRestorePacket->dependencyUid = skillFormationPacket->uid;
                    earlyColorRestorePacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)earlyColorRestorePacket, 1);
                }
                if ((s32)(effectiveAction) != (s32)(actionBytes)) {
                    earlyTargetRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket((u8*)((BtlAction *)effectiveAction)->unit, act->unit, 2));
                    earlyTargetRotationPacket->dependencyKind = 5;
                    earlyTargetRotationPacket->dependencyUid = skillFormationPacket->uid;
                    earlyTargetRotationPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)earlyTargetRotationPacket, 0);
                }
                earlyFinishEffectPacket = (BtlPacketTiming *)(btlPacketCreateFinishEffect());
                earlyFinishEffectPacket->dependencyKind = 5;
                earlyFinishEffectPacket->dependencyUid = skillFormationPacket->uid;
                earlyFinishEffectPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)earlyFinishEffectPacket, 0);
                targetRecoveryCameraPacket = (BtlPacket *)(btlCameraCreateSetStatePacket((BtlAction *)effectiveAction, 0x1C));
                (((BtlPacketTiming *)targetRecoveryCameraPacket)->dependencyKind) = 5;
                ((BtlPacketTiming *)targetRecoveryCameraPacket)->dependencyUid = skillFormationPacket->uid;
                if (!((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x80)) {
                    (((BtlPacket *)targetRecoveryCameraPacket)->dependencyKind3) = 0xB;
                    ((BtlPacket *)targetRecoveryCameraPacket)->dependencyUID3 = skillFormationPacket->uid;
                    (((BtlPacketTiming *)targetRecoveryCameraPacket)->duration) = 0x12;
                } else {
                    (((BtlPacket *)targetRecoveryCameraPacket)->dependencyKind3) = 4;
                    ((BtlPacket *)targetRecoveryCameraPacket)->dependencyUID3 = skillFormationPacket->uid;
                }
                (((BtlPacketTiming *)targetRecoveryCameraPacket)->actionUid) = actionId;
                btlPacketEnqueue((u8 *)targetRecoveryCameraPacket, 0);
            }
            if (*(s32 *)(targetAction + 0xE4) != 0) {
                reactionFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket((u32)((BtlBattleState *)iGpffffb3ac)->formations[9], (u32)((BtlAction *)actionBytes)->unit, *(u32 *)(targetAction + 0x30), 1, 0));
                if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 4) {
                    reactionFormationPacket->dependencyKind = 0xB;
                    reactionFormationPacket->dependencyUid = skillFormationPacket->uid;
                } else {
                    reactionFormationPacket->dependencyKind = 5;
                    reactionFormationPacket->dependencyUid = formationEndUid2;
                }
                btlPacketEnqueue((u8 *)reactionFormationPacket, 1);
                reflectedSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xD, 2, 0xB));
                reflectedSoundPacket->dependencyKind = 5;
                reflectedSoundPacket->dependencyUid = reactionFormationPacket->uid;
                btlPacketEnqueue((u8 *)reflectedSoundPacket, 1);
            }
            if (*(u16 *)(targetAction + 0xDC) == 0x400) {
                reactionFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket((u32)((BtlBattleState *)iGpffffb3ac)->formations[10], (u32)((BtlAction *)actionBytes)->unit, *(u32 *)(effectiveAction + 0x30), 1, 0));
                if ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 4) {
                    reactionFormationPacket->dependencyKind = 0xB;
                    reactionFormationPacket->dependencyUid = skillFormationPacket->uid;
                } else {
                    reactionFormationPacket->dependencyKind = 5;
                    reactionFormationPacket->dependencyUid = formationEndUid2;
                }
                btlPacketEnqueue((u8 *)reactionFormationPacket, 1);
                absorbedSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xC, 2, 0xC));
                absorbedSoundPacket->dependencyKind = 5;
                absorbedSoundPacket->dependencyUid = reactionFormationPacket->uid;
                btlPacketEnqueue((u8 *)absorbedSoundPacket, 1);
                hitDelay = 0xA;
            }
            hitIndex = 0;
            while ((hitIndexS32 = (s32) hitIndex) < (s32)rowHitCount) {
                motionSpeed = 1.0f;
                                hitRow = (BtlActionHitCursor *)(targetAction + ((u32)hitIndex << 5));
                /* The two later predicates reload the signed byte after intervening calls. */
                hitMotion = &hitRow->result.motion;
                if (hitRow->result.motion == 9) {
                    motionFrames = (u16)btlUnitMotionFollowFrames((u8*)((BtlAction *)effectiveAction)->unit, 9, motionSpeed);
                    motionFramesCopy = motionFrames;
                    if (((s32) motionFramesCopy > 0) && ((s32) motionFramesCopy < 0xA)) {
                        motionFramesF = (f32) motionFramesCopy;
                        motionSpeed = motionFramesF / 10.0f;
                        motionFrames = 0xA;
                    }
                }
                hitAnimationPacket = (BtlPacketTiming *)(btlUnitCreateAnimPacket((BtlUnit *)*(u8 **)(effectiveAction + 0x30), *hitMotion, 0, motionSpeed, 0));
                animPacket = (BtlPacketTiming *)(hitAnimationPacket);
                hitAnimationPacket->dependencyKind = 0xB;
                hitAnimationPacket->dependencyUid = skillFormationPacket->uid;
                (((BtlPacketTiming *)hitAnimationPacket)->delay) = hitTimer;
                if ((*(s32 *)(targetAction + 0xE4) != 0) && ((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 8)) {
                    (((BtlPacketTiming *)animPacket)->delay) = (u16) ((s16) (((BtlPacket *)animPacket)->delay) + 8);
                }
                animPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
                if ((hitIndexS32 == (s32)rowHitCount - 1) && (hitRow->result.addedStatus & 0x100000) && (actionFlag4000 == 0) && (sameSideTarget == 1) && (((BtlAction *)targetAction)->targetBlock.reactionFlag == 0) && (*hitMotion == 9) && ((s32)(datCalcUsesWeaponProperties(skillKeyCopy)) == (s32)(0))) {
                    motionFramesS32 = (s32) motionFrames;
                    if (motionFramesS32 >= 0x19) {
                        motionDelay = 0;
                    } else {
                        motionDelay = 0x19 - motionFramesS32;
                    }
                    hitArcMovePacket = (BtlPacketTiming *)(btlUnitCreateArcMovePacket(*(s32 *)(effectiveAction + 0x30), skill, (s16)motionDelay));
                    hitArcMovePacket->dependencyKind = 4;
                    hitArcMovePacket->dependencyUid = animPacket->uid;
                    hitArcMovePacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)hitArcMovePacket, 0);
                    if (act->targetCount == 1) {
                        skillKindUnit = (s16)datCalcSkillElement((u8 *)((BtlUnit *)act->unit)->datUnit, skillKeyCopy);
                        switch (skillKindUnit) {            /* switch 3; irregular */
                        case 1:                         /* switch 3 */
                            motionIdRaw = 0x29;
                            break;
                        case 2:                         /* switch 3 */
                            motionIdRaw = 0x2B;
                            break;
                        case 3:                         /* switch 3 */
                            motionIdRaw = 0x2A;
                            break;
                        case 4:                         /* switch 3 */
                            motionIdRaw = 0x2C;
                            break;
                        default:                        /* switch 3 */
                            motionIdRaw = -1;
                            break;
                        }
                        motionId = (s16)motionIdRaw;
                        if (motionId != -1) {
                            elementTargetUnit = (u8 *)((u8*)((BtlAction *)effectiveAction)->unit);
                            hitElementFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket((u32)((BtlBattleState *)iGpffffb3ac)->formations[motionId], (u32)elementTargetUnit, (u32)elementTargetUnit, 1, 0));
                            hitElementFormationPacket->dependencyKind = 4;
                            hitElementFormationPacket->dependencyUid = animPacket->uid;
                            hitElementFormationPacket->actionUid = actionId;
                            btlPacketEnqueue((u8 *)hitElementFormationPacket, 2);
                        }
                    }
                    if (motionFramesS32 > 0x19) {
                        hitModelFramePacket = (BtlPacketTiming *)(btlUnitCreateModelFramePacket((BtlUnit *)((u8*)((BtlAction *)effectiveAction)->unit), (s16)(motionFramesS32 - 0x19)));
                        hitModelFramePacket->dependencyKind = 4;
                        hitModelFramePacket->dependencyUid = animPacket->uid;
                        hitModelFramePacket->actionUid = actionId;
                        btlPacketEnqueue((u8 *)hitModelFramePacket, 0);
                    }
                    impactTargetUnit = (u8 *)(*(u8 **)(effectiveAction + 0x30));
                    impactFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket((u32)((BtlBattleState *)iGpffffb3ac)->formations[31], (u32)impactTargetUnit, (u32)impactTargetUnit, 1, 0));
                    impactFormationPacket->dependencyKind = 4;
                    impactFormationPacket->dependencyUid = animPacket->uid;
                    if (motionFramesS32 >= 0x19) {
                        motionFramesS32 = 0x19;
                    }
                    impactFormationPacket->delay = (s16) motionFramesS32;
                    impactFormationPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)impactFormationPacket, 2);
                    cameraTargetUnit = (u8 *)(*(u8 **)(effectiveAction + 0x30));
                    targetScale = ((BtlUnit *)(cameraTargetUnit))->scale;
                    areaScale = ((((BtlUnit *)(cameraTargetUnit))->sphereRadius * targetScale * (((BtlUnit *)(cameraTargetUnit))->unk_8c * targetScale)) / (f32) 0x2710);
                    scaleLimit = 2.0f;
                    if (areaScale < scaleLimit) {
                        areaScale = scaleLimit;
                    } else {
                        scaleLimit = 5.0f;
                        if (!(areaScale <= scaleLimit)) {
                            areaScale = scaleLimit;
                        }
                    }
                    impactCameraCommandPacket = (BtlPacketTiming *)(btlCameraCreatePacketCommand(0x12, (s16)(s32)((80.0f * areaScale) / 5.0f), 0, 6));
                    impactCameraCommandPacket->dependencyKind = 5;
                    impactCameraCommandPacket->dependencyUid = impactFormationPacket->uid;
                    impactCameraCommandPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)impactCameraCommandPacket, 1);
                    hitMotionSettlePacket = (BtlPacketTiming *)(btlUnitCreateMotionSettlePacket((BtlUnit *)((u8*)((BtlAction *)effectiveAction)->unit)));
                    hitMotionSettlePacket->dependencyKind = 5;
                    hitMotionSettlePacket->dependencyUid = animPacket->uid;
                    hitMotionSettlePacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)hitMotionSettlePacket, 0);
                }
                if ((restoreBeforeHits == 0) && ((*hitMotion != -1) || ((s32)((((BtlUnit *)((u8 *)((u8*)((BtlAction *)targetAction)->unit)))->genus)) != (s32)((((BtlUnit *)((u8 *)(act->unit)))->genus)))) && ((s32)(datCalcChkBadStatus((s32)((u8 *)((BtlUnit *)((u8 *)(*(u8 **)(targetAction + 0x30))))->datUnit), 0x180001)) == (s32)(0))) {
                    hitTargetRotationPacket = (BtlPacketTiming *)(btlUnitCreateRotateTowardUnitPacket((u8*)((BtlAction *)targetAction)->unit, act->unit, 2));
                    if ((((BtlAction *)targetAction)->targetBlock.specialHitFlag != 0) && ((s32)((u8 *)reactionFormationPacket) != (s32)(0))) {
                        hitTargetRotationPacket->dependencyKind = 5;
                        hitTargetRotationPacket->dependencyUid = reactionFormationPacket->uid;
                    } else {
                        hitTargetRotationPacket->dependencyKind = 5;
                        hitTargetRotationPacket->dependencyUid = animPacket->uid;
                    }
                    hitTargetRotationPacket->flags = (u8) (hitTargetRotationPacket->flags & 0xDF);
                    hitTargetRotationPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)hitTargetRotationPacket, 1);
                }
                if (((BtlBattleState *)iGpffffb3ac)->flags & 0x200000) {
                    applyEffectsPacket = (BtlPacketTiming *)(btlPacketAllocZeroed((void *)btlUnitApplyPacketEffects, (void *)actionBytes));
                    applyEffectsPacket->dependencyKind = 5;
                    applyEffectsPacket->dependencyUid = animPacket->uid;
                    applyEffectsPacket->delay = hitDelay;
                    applyEffectsPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)applyEffectsPacket, 1);
                }
                hitResult = (s32 *)&hitRow->result;
                hitResultPtr = (s32 *)(hitResult);
                hitResultPacket = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(actionBytes), (s32)(effectiveAction), hitResult, *(u16 *)(targetAction + 0xDC), *(u16 *)(targetAction + 0xDE)));
                hitResultPacket->dependencyKind = 5;
                hitResultPacket->dependencyUid = animPacket->uid;
                hitResultPacket->delay = hitDelay;
                hitResultPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)hitResultPacket, 1);
                targetRecordPacket = (BtlPacketTiming *)(btlTargetCreateRecordPacket(targetAction));
                targetRecordPacket->dependencyKind = 5;
                targetRecordPacket->dependencyUid = animPacket->uid;
                targetRecordPacket->delay = hitDelay;
                targetRecordPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)targetRecordPacket, 1);
                if (((s32)(targetPos) == (s32)((act->targetCount - 1))) && (hitIndexS32 == (s32)((((BtlAction *)targetAction)->targetBlock.hitRowCount - 1)))) {
                    sourceRecordPacket = (BtlPacketTiming *)(btlTargetCreateRecordPacket(actionBytes));
                    sourceRecordPacket->dependencyKind = 5;
                    sourceRecordPacket->dependencyUid = animPacket->uid;
                    sourceRecordPacket->delay = hitDelay;
                    sourceRecordPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)sourceRecordPacket, 1);
                }
                if ((targetPos == 0) && (hitIndexS32 == 0) && !(act->flags & 4)) {
                    sourceActionPacket = (BtlPacketTiming *)(btlTargetCreateActionPacket(actionBytes, act->stateBits));
                    sourceActionPacket->dependencyKind = 5;
                    sourceActionPacket->dependencyUid = animPacket->uid;
                    sourceActionPacket->delay = hitDelay;
                    sourceActionPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)sourceActionPacket, 1);
                }
                if (hitIndexS32 == (s32)((((BtlAction *)targetAction)->targetBlock.hitRowCount - 1))) {
                    if ((act->fieldEC != 0) && !(act->fieldD8 & 1)) {
                        hitRowWord = (s32)((*( s32 * )((u8 *)(((s32)(actionBytes) + ((u32)hitIndex << 5))) + (0x104))));
                        if (hitRowWord != 0) {
                            btlPanelSetValueText((u8 *)(((BtlBattleState *)iGpffffb3ac)->messageWindow), func_0043c6a0(hitRowWord));
                        }
                        sourceEffectCounterPacket = (BtlPacketTiming *)(btlPacketCreateEffectCounter(*(s32 *)(actionBytes + 0x30), act->fieldEC));
                        sourceEffectCounterPacket->dependencyKind = 5;
                        sourceEffectCounterPacket->dependencyUid = animPacket->uid;
                        sourceEffectCounterPacket->flags = (u8) (sourceEffectCounterPacket->flags & 0xDF);
                        sourceEffectCounterPacket->actionUid = actionId;
                        btlPacketEnqueue((u8 *)sourceEffectCounterPacket, 3);
                    } else {
                        if (*(s16 *)(targetAction + 0xEC) != 0) {
                            hitField14 = hitRow->result.field14;
                            if (hitField14 != 0) {
                                btlPanelSetValueText((u8 *)(((BtlBattleState *)iGpffffb3ac)->messageWindow), func_0043c6a0(hitField14));
                            }
                            targetEffectCounterPacket = (BtlPacketTiming *)(btlPacketCreateEffectCounter(*(s32 *)(targetAction + 0x30), (s16)((BtlAction *)targetAction)->targetBlock.message.messageCode));
                            targetEffectCounterPacket->dependencyKind = 5;
                            targetEffectCounterPacket->dependencyUid = animPacket->uid;
                            targetEffectCounterPacket->flags = (u8) (targetEffectCounterPacket->flags & 0xDF);
                            targetEffectCounterPacket->actionUid = actionId;
                            btlPacketEnqueue((u8 *)targetEffectCounterPacket, 3);
                        } else if (hasFollowAction != 0) {
                            targetFieldEC = (s16)((s16)((BtlAction *)effectiveAction)->targetBlock.message.messageCode);
                            if (targetFieldEC != 0) {
                                followEffectCounterPacket = (BtlPacketTiming *)(btlPacketCreateEffectCounter((s32)((BtlAction *)effectiveAction)->unit, targetFieldEC));
                                followEffectCounterPacket->dependencyKind = 5;
                                followEffectCounterPacket->dependencyUid = animPacket->uid;
                                followEffectCounterPacket->flags = (u8) (followEffectCounterPacket->flags & 0xDF);
                                followEffectCounterPacket->actionUid = actionId;
                                btlPacketEnqueue((u8 *)followEffectCounterPacket, 3);
                            }
                        }
                    }
                }
                if ((s32)(*hitResultPtr) != (s32)(0)) {
                    targetUnitCounterPacket = (BtlPacketTiming *)(btlPacketCreateUnitCounter((s32)((u8*)((BtlAction *)effectiveAction)->unit), 0, 0));
                    targetUnitCounterPacket->dependencyKind = 5;
                    targetUnitCounterPacket->dependencyUid = animPacket->uid;
                    targetUnitCounterPacket->delay = hitDelay;
                    targetUnitCounterPacket->flags = (u8) (targetUnitCounterPacket->flags & 0xDF);
                    targetUnitCounterPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)targetUnitCounterPacket, 3);
                }
                if ((hitRow->result.addedStatus & 0x100000) && ((s32)((((BtlUnit *)((u8 *)((u8*)((BtlAction *)effectiveAction)->unit)))->genus)) == (s32)(1))) {
                    targetDownSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xD, 2, 8));
                    targetDownSoundPacket->dependencyKind = 5;
                    targetDownSoundPacket->dependencyUid = animPacket->uid;
                    targetDownSoundPacket->delay = hitDelay;
                    targetDownSoundPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)targetDownSoundPacket, 1);
                }
                if (*(u16 *)((u8 *)hitRow + 0x10E) & 0x20) {
                    endsEncounter = 1;
                    ((BtlBattleState *)iGpffffb3ac)->endState = 3;
                }
                if (*(u16 *)((u8 *)hitRow + 0x10E) & 0x40) {
                    sacrificeActor = 1;
                }
                hitRowBase = btlActionGetIndexedHitBase(targetAction, &hitIndex);
                hitDisplayPacket = (BtlPacketTiming *)(btlPacketCreateHitDisplay((s32)(act->unit), (s32)((u8*)((BtlAction *)effectiveAction)->unit), skillS32, ((BtlAction *)targetAction)->targetBlock.hitOutcome, ((BtlAction *)targetAction)->targetBlock.targetFlags, hitIndex, rowHitCount, hitResultPtr, 0));
                hitDisplayPacket->dependencyKind = 5;
                hitDisplayPacket->dependencyUid = animPacket->uid;
                hitDisplayPacket->delay = hitDelay;
                hitDisplayPacket->flags = (u8) (hitDisplayPacket->flags & 0xDF);
                hitDisplayPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)hitDisplayPacket, 3);
                hpTransfer = (s16 *)(hitRowBase + 0x108);
                if ((((BtlAction *)hitRowBase)->targetBlock.hitRows[0].hpTransfer > 0) || (hitRow->result.spTransfer > 0)) {
                    hitDelayS16 = (s16)(hitDelay + 0x2B);
                    btlTargetClearResultBuffer((u8 *)&result);
                    spRow = btlActionGetIndexedHitResult(targetAction, &hitIndex);
                    result.hpDelta = *hpTransfer;
                    result.spDelta = (s32) ((LargeBattleHitResult *)spRow)->spTransfer;
                    transferResultPacket = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(actionBytes), (s32)(actionBytes), &result, 1U, 1U));
                    transferResultPacket->dependencyKind = 4;
                    transferResultPacket->dependencyUid = animPacket->uid;
                    transferResultPacket->delay = hitDelayS16;
                    transferResultPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)transferResultPacket, 1);
                    transferSourceUnit = (u8 *)(act->unit);
                    transferDisplayPacket = (BtlPacketTiming *)(btlPacketCreateHitDisplay((s32)(transferSourceUnit), (s32)(transferSourceUnit), -1, 1U, 1U, hitIndex, rowHitCount, &result, 0));
                    transferDisplayPacket->dependencyKind = 4;
                    transferDisplayPacket->dependencyUid = animPacket->uid;
                    transferDisplayPacket->delay = hitDelayS16;
                    transferDisplayPacket->actionUid = actionId;
                    btlPacketEnqueue((u8 *)transferDisplayPacket, 3);
                    if (result.hpDelta != 0) {
                        if (hitIndexS32 == 0) {
                            sourceHpRatioPacket = (BtlPacketTiming *)(btlPacketCreateHpRatio(act->unit));
                            sourceHpRatioPacket->actionUid = actionId;
                            btlPacketEnqueue((u8 *)sourceHpRatioPacket, 1);
                        }
                        transferCounterPacket = (BtlPacketTiming *)(btlPacketCreateUnitCounter((s32)(act->unit), 0, 0));
                        transferCounterPacket->dependencyKind = 4;
                        transferCounterPacket->dependencyUid = animPacket->uid;
                        transferCounterPacket->delay = hitDelayS16;
                        transferCounterPacket->actionUid = actionId;
                        btlPacketEnqueue((u8 *)transferCounterPacket, 3);
                    }
                }
                hitTimer += 7;
                hitIndex += 1;
            }
            if (hitWait < (s32) hitTimer) {
                hitWait = hitTimer;
            }
            hitTimeTotal += hitDelta;
            targetIndex += 1;
    }
    lateChainUid = animPacket->uid;
    followSkill = (s16)(act->fieldEE);
    if (followSkill != -1) {
        followSkillPacket = (BtlPacketTiming *)(btlTargetCreateTargetPacket(actionBytes, (u16)followSkill, 0, 0, 0));
        followSkillPacket->dependencyKind = 5;
        followSkillPacket->dependencyUid = lateChainUid;
        followSkillPacket->delay = (s16) hitWait;
        followSkillPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)followSkillPacket, 1);
    } else if (crossSideHits > 0) {
        if (side == 0) {
            statusTotal = (s32)((u16)btlSideCountNotBad(2, 0x80000));
            if (((BtlAction *)actionBytes)->unk_28 <= 0 && ((BtlUnit *)(act->unit))->charId != 1 && datCalcRandomBelow(0x64U) < 0x32U) {
                if ((s32)((((BtlUnit *)((u8 *)(act->unit)))->genus)) != (s32)(0)) {
                    chanceMiss = 0;
                } else {
                    reactionBattle = (u8 *)(iGpffffb3ac);
                    if (((BtlBattleState *)reactionBattle)->unkA70 != -1) {
                        statusRemaining = (s16)(statusTotal - crossSideHits);
                        if (statusRemaining <= 0) {
                            statusTotal2 = (u32)((u16)btlSideCountNotBad(2, 0x80000));
                            reactionCountBattle = (u8 *)(iGpffffb3ac);
                            if (((u32)(((BtlBattleState *)reactionCountBattle)->unkA72 >> 1) >= statusTotal2) && (lastActor = ((BtlBattleState *)reactionCountBattle)->unkA70, (lastActor != btlCameraSelectFormationIndex()))) {
                                chanceMiss = 1;
                            } else {
                                goto block_406;
                            }
                        } else if ((((BtlBattleState *)reactionBattle)->unkA72 >> 1) >= statusRemaining) {
                            chanceMiss = 1;
                        } else {
                            goto block_406;
                        }
                    } else {
block_406:
                        chanceMiss = 0;
                    }
                }
            } else {
                goto reactionPacket;
            }
            if (chanceMiss != 0) {
reactionPacket:
                reactionTargetPacket = (BtlPacketTiming *)(btlTargetCreateTargetPacket(actionBytes, 0x13, crossSideHits, 0, 0));
                reactionTargetPacket->dependencyKind = 5;
                reactionTargetPacket->dependencyUid = lateChainUid;
                reactionTargetPacket->delay = (s16) hitWait;
                reactionTargetPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)reactionTargetPacket, 1);
                        } else {
                reactionVoicePacket = (BtlPacketTiming *)(func_001f99c0(actionBytes, 0x10, crossSideHits, 0, 0));
                reactionVoicePacket->dependencyKind = 5;
                reactionVoicePacket->dependencyUid = lateChainUid;
                reactionVoicePacket->delay = (s16) hitWait;
                btlPacketEnqueue((u8 *)reactionVoicePacket, 1);
            }
        }
    } else if ((statusHits > 0) && (stateBitsCopy = act->stateBits, ((stateBitsCopy & 1) != 0)) && !(stateBitsCopy & 2) && ((s64)((((BtlUnit *)((u8 *)(act->unit)))->genus)) == (s64)(0))) {
        statusTargetPacket = (BtlPacketTiming *)(btlTargetCreateTargetPacket(actionBytes, 0x18, (s32) statusMask, statusHits, 0));
        statusTargetPacket->dependencyKind = 5;
        statusTargetPacket->dependencyUid = lateChainUid;
        statusTargetPacket->delay = (s16) hitWait;
        statusTargetPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)statusTargetPacket, 1);
    } else if ((rotateFirst != 0) && (side == 0) && (btlActionSameGenusTargetsHaveDelta(actionBytes) != 0) && (btlActionAnyTargetClearsDeathStatus(actionBytes) == 0)) {
        sameSideVoicePacket = (BtlPacketTiming *)(func_001f99c0(act->target, 0x12, 0U, 0, 0));
        sameSideVoicePacket->dependencyKind = 5;
        sameSideVoicePacket->dependencyUid = lateChainUid;
        sameSideVoicePacket->delay = (s16) hitWait;
        btlPacketEnqueue((u8 *)sameSideVoicePacket, 1);
    } else if (crossSideHits == 0) {
        if ((s32)(btlActionTargetsHaveDamageResult(actionBytes, 1)) != (s32)(0)) {
            followUpVoicePacket = (BtlPacketTiming *)(func_001f99c0(actionBytes, 0xF, 0U, 0, 0));
            followUpVoicePacket->dependencyKind = 5;
            followUpVoicePacket->dependencyUid = lateChainUid;
            followUpVoicePacket->delay = (s16) hitWait;
            btlPacketEnqueue((u8 *)followUpVoicePacket, 1);
        } else if (((s32)(btlActionAnyTargetHasSpecialResult(actionBytes)) == (s32)(1)) && ((s32)(btlActionAnyTargetSpecialHit(actionBytes)) == (s32)(0)) && (sacrificeActor == 0)) {
            specialHitVoicePacket = (BtlPacketTiming *)(func_001f99c0(actionBytes, 0x11, 0U, 0, 0));
            specialHitVoicePacket->dependencyKind = 5;
            specialHitVoicePacket->dependencyUid = lateChainUid;
            specialHitVoicePacket->delay = (s16) hitWait;
            btlPacketEnqueue((u8 *)specialHitVoicePacket, 1);
        }
    }
    if (sacrificeActor != 0) {
        if (restoreBeforeHits == 1) {
            targetRecoveryCameraPacket = (BtlPacket *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x1B));
            (((BtlPacketTiming *)targetRecoveryCameraPacket)->dependencyKind) = 0xB;
            ((BtlPacketTiming *)targetRecoveryCameraPacket)->dependencyUid = skillFormationPacket->uid;
            (((BtlPacketTiming *)targetRecoveryCameraPacket)->delay) = 0x18;
            (((BtlPacketTiming *)targetRecoveryCameraPacket)->actionUid) = actionId;
            btlPacketEnqueue((u8 *)targetRecoveryCameraPacket, 0);
        }
        if ((s32)((((BtlUnit *)((u8 *)(act->unit)))->genus)) == (s32)(0)) {
            btlTargetClearResultBuffer((u8 *)&result);
            result.hpDelta = -((s32)(datCalcGetHp(((s32)((BtlUnit *)((u8 *)(act->unit)))->datUnit)) & 0xFFFF) - 1);
            actorResultPacket = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(actionBytes), (s32)(actionBytes), &result, 1U, 1U));
            if (restoreBeforeHits == 1) {
                actorResultPacket->dependencyKind = 4;
                actorResultPacket->dependencyUid = (s64)((s64) (((BtlPacketTiming *)targetRecoveryCameraPacket)->uid));
            } else {
                actorResultPacket->dependencyKind = 0xB;
                actorResultPacket->dependencyUid = (s64)((s64) skillFormationPacket->uid);
            }
            actorResultPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorResultPacket, 1);
            resultSourceUnit = (u8 *)(act->unit);
            actorResultDisplayPacket = (BtlPacketTiming *)(btlPacketCreateHitDisplay((s32)(resultSourceUnit), (s32)(resultSourceUnit), -1, 0U, 0U, 0U, 1U, &result, 0));
            actorResultDisplayPacket->dependencyKind = 4;
            actorResultDisplayPacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
            actorResultDisplayPacket->flags = (u8) (actorResultDisplayPacket->flags & 0xDF);
            actorResultDisplayPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorResultDisplayPacket, 3);
            actorResultCounterPacket = (BtlPacketTiming *)(btlPacketCreateUnitCounter((s32)(act->unit), 0, 0));
            actorResultCounterPacket->dependencyKind = 4;
            actorResultCounterPacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
            actorResultCounterPacket->flags = (u8) (actorResultCounterPacket->flags & 0xDF);
            actorResultCounterPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorResultCounterPacket, 3);
        } else {
            btlTargetClearResultBuffer((u8 *)&result);
            result.addedStatus = 0x80000;
            actorResultPacket = (BtlPacketTiming *)(btlTargetCreateDataPacket((s32)(actionBytes), (s32)(actionBytes), &result, 1U, 1U));
            if (restoreBeforeHits == 1) {
                actorResultPacket->dependencyKind = 4;
                actorResultPacket->dependencyUid = (s64)((s64) (((BtlPacketTiming *)targetRecoveryCameraPacket)->uid));
            } else {
                actorResultPacket->dependencyKind = 0xB;
                actorResultPacket->dependencyUid = (s64)((s64) skillFormationPacket->uid);
            }
            actorResultPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorResultPacket, 1);
        }
        if (skipMotionRecovery == 0) {
            if (settleMotion == 0) {
                if (restoreMotionSpeed == 0) {
                    animPacket = (BtlPacketTiming *)(btlUnitCreateMotionRequestPacket(act->unit, windupFrames));
                } else {
                    animPacket = (BtlPacketTiming *)(btlUnitCreateMotionSpeedPacket((BtlUnit *)((u8*)((BtlAction *)actionBytes)->unit), 0, 1.0f, 0));
                }
                animPacket->dependencyKind = 4;
                animPacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
                animPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            } else {
                actorResultSettlePacket = (BtlPacketTiming *)(btlUnitCreateMotionSettlePacket((BtlUnit *)act->unit));
                animPacket = (BtlPacketTiming *)(actorResultSettlePacket);
                actorResultSettlePacket->dependencyKind = 4;
                actorResultSettlePacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
                actorResultSettlePacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)animPacket, 0);
            }
        }
        hidingSourceUnit = (u8 *)(act->unit);
        if ((s32)((BtlUnit *)hidingSourceUnit)->flags3 & 0x20) {
            actorHideWaitPacket = (BtlPacketTiming *)(btlPacketCreateImmediate());
            actorHideWaitPacket->dependencyKind = 4;
            actorHideWaitPacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
            actorHideWaitPacket->duration = 0x3C;
            actorHideWaitPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorHideWaitPacket, 1);
        } else {
            actorHidePacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)hidingSourceUnit, 0xFFFFFF, 6, 0, 4, 0));
            actorHidePacket->dependencyKind = 4;
            actorHidePacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
            actorHidePacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorHidePacket, 1);
            hidingEffectUnit = (u8 *)(act->unit);
            actorHideFormationPacket = (BtlPacketTiming *)(btlFormationCreatePacket((u32)((BtlBattleState *)iGpffffb3ac)->formations[17], (u32)hidingEffectUnit, (u32)hidingEffectUnit, 0, 0));
            actorHideFormationPacket->dependencyKind = 4;
            actorHideFormationPacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
            actorHideFormationPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorHideFormationPacket, 2);
            actorHideSoundPacket = (BtlPacketTiming *)(btlSoundCreateChannelCuePacket(0xA, 2, 0xA));
            actorHideSoundPacket->dependencyKind = 4;
            actorHideSoundPacket->dependencyUid = (s64)((s64) actorResultPacket->uid);
            actorHideSoundPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)actorHideSoundPacket, 1);
            hiddenSourceUnit = (u8 *)(act->unit);
            ((BtlUnit *)hiddenSourceUnit)->flags3 |= 0x100;
        }
    } else if (skipMotionRecovery == 0) {
        if (settleMotion == 0) {
            if (restoreMotionSpeed == 0) {
                animPacket = (BtlPacketTiming *)(btlUnitCreateMotionRequestPacket(act->unit, windupFrames));
            } else {
                animPacket = (BtlPacketTiming *)(btlUnitCreateMotionSpeedPacket((BtlUnit *)((u8*)((BtlAction *)actionBytes)->unit), 0, 1.0f, 0));
            }
            animPacket->dependencyKind = 0xB;
            animPacket->dependencyUid = skillFormationPacket->uid;
            if (side == 0) {
                animPacket->delay = cameraState;
            } else {
                animPacket->delay = 8;
                if (cameraState > 8) {
                    animDuration = cameraState - 8;
                } else {
                    animDuration = 0;
                }
                animPacket->duration = animDuration;
            }
            animPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
        } else {
            recoverySettlePacket = (BtlPacketTiming *)(btlUnitCreateMotionSettlePacket((BtlUnit *)act->unit));
            animPacket = (BtlPacketTiming *)(recoverySettlePacket);
            recoverySettlePacket->dependencyKind = 0xB;
            recoverySettlePacket->dependencyUid = skillFormationPacket->uid;
            recoverySettlePacket->delay = cameraState;
            recoverySettlePacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)animPacket, 0);
        }
    }
    recoveryTimingPacket = (BtlPacketTiming *)(btlCreateTimingPacket(0x10));
    recoveryTimingPacket->dependencyKind = 4;
    recoveryTimingPacket->dependencyUid = animPacket->uid;
    recoveryTimingPacket->flags = (u8) (recoveryTimingPacket->flags & 0xDF);
    recoveryTimingPacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)recoveryTimingPacket, 1);
    if (endsEncounter != 0) {
        cameraMode = 2;
    } else {
        cameraMode = 0;
    }
    recoveryFadePacket = (BtlPacketTiming *)(btlMainCreateFadePacket(0x10, (u16)cameraMode));
    recoveryFadePacket->dependencyKind = 4;
    recoveryFadePacket->dependencyUid = animPacket->uid;
    recoveryFadePacket->flags = (u8) (recoveryFadePacket->flags & 0xDF);
    recoveryFadePacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)recoveryFadePacket, 1);
    recoveryColorFadePacket = (BtlPacketTiming *)(btlMainCreateColorFadePacket(0x10));
    recoveryColorFadePacket->dependencyKind = 4;
    recoveryColorFadePacket->dependencyUid = animPacket->uid;
    recoveryColorFadePacket->flags = (u8) (recoveryColorFadePacket->flags & 0xDF);
    recoveryColorFadePacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)recoveryColorFadePacket, 1);
    recoveryColorSetPacket = (BtlPacketTiming *)(btlMainCreateColorSetPacket(8));
    recoveryColorSetPacket->dependencyKind = 4;
    recoveryColorSetPacket->dependencyUid = skillFormationPacket->uid;
    recoveryColorSetPacket->flags = (u8) (recoveryColorSetPacket->flags & 0xDF);
    recoveryColorSetPacket->actionUid = actionId;
    btlPacketEnqueue((u8 *)recoveryColorSetPacket, 0);
    if ((altCamera == 1) && (isKind3 == 0) && (noOverride == 0)) {
        if (randomFlag == 0) {
            if (!((((BtlSkillFlags *)(skillFlagsOffset + (s32)((u8 *)iGpffffb3bc)))->flags) & 0x40)) {
                if (side == 0) {
                    cameraStateA = 0x19;
                } else {
                    cameraStateA = 0x1A;
                }
                recoveryCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, (u16)cameraStateA));
                recoveryCameraPacket->dependencyKind = 5;
                recoveryCameraPacket->dependencyUid = formationEndUid;
                recoveryCameraPacket->actionUid = actionId;
                btlPacketEnqueue((u8 *)recoveryCameraPacket, 0);
            }
        } else {
            recoveryGroupCameraPacket = (BtlPacketTiming *)(btlCameraCreateSetStatePacket((BtlAction *)actionBytes, 0x1D));
            recoveryGroupCameraPacket->dependencyKind = 5;
            recoveryGroupCameraPacket->dependencyUid = formationEndUid;
            recoveryGroupCameraPacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)recoveryGroupCameraPacket, 0);
        }
        if (endsEncounter == 0) {
            sourceColorRestorePacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)act->unit, -1, 0, 0xC, 3, 0));
            sourceColorRestorePacket->dependencyKind = 0xB;
            sourceColorRestorePacket->dependencyUid = skillFormationPacket->uid;
            sourceColorRestorePacket->actionUid = actionId;
            btlPacketEnqueue((u8 *)sourceColorRestorePacket, 1);
        }
        linkedFadePacket = (BtlPacketTiming *)(btlUnitCreateColorPacket((BtlUnit *)linkedUnit, 0xFFFFFF, 8, 0, 4, 0));
        linkedFadePacket->dependencyKind = 0xB;
        linkedFadePacket->dependencyUid = skillFormationPacket->uid;
        colorDelay = (rotateFirst != 0 && skillSpecial != 0) ? 7 : 0xF;
        linkedFadePacket->delay = colorDelay;
        linkedFadePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)linkedFadePacket, 1);
        linkedReleaseEffectPacket = (BtlPacketTiming *)(btlEffectCreateFormationPacket((s32)((BtlBattleState *)iGpffffb3ac)->formations[27], (s32)linkedUnit, damageFrames, 0, 0x2100));
        linkedReleaseEffectPacket->dependencyKind = 4;
        linkedReleaseEffectPacket->dependencyUid = animEndUid;
        linkedReleaseEffectPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)linkedReleaseEffectPacket, 2);
    }
    if (endsEncounter == 1) {
        endEncounterFlagsPacket = (BtlPacketTiming *)(btlCreateSetFlagsPacket(0x80));
        endEncounterFlagsPacket->dependencyKind = 4;
        endEncounterFlagsPacket->dependencyUid = skillFormationPacket->uid;
        endEncounterFlagsPacket->delay = 0xC;
        endEncounterFlagsPacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)endEncounterFlagsPacket, 1);
        endSequencePacket = (BtlPacketTiming *)(btlPacketCreateEndSequence());
        endSequencePacket->dependencyKind = 4;
        endSequencePacket->dependencyUid = animPacket->uid;
        endSequencePacket->flags = (u8) (endSequencePacket->flags & 0xDF);
        endSequencePacket->actionUid = actionId;
        btlPacketEnqueue((u8 *)endSequencePacket, 1);
    }
    if (actionFlag4000 == 0) {
        btlFormationSetPlacement(formationHandle);
    }
    if (hasCutinPartner != 0) {
        u8 *partner = act->cutinPartner;

        cutin.mode = 3;
        cutin.unitId = ((BtlUnit *)((u8*)((BtlAction *)partner)->unit))->charId;
        btlPacketEnqueue((u8 *)(btlSoundLoadPacketNew((u8 *)&cutin)), 1);
    }
    if ((s32)(btlSoundCanReceiveStatus(actionBytes)) != (s32)(0)) {
        btlActionSetState((BtlAction *)actionBytes, 0x1B);
        return;
    }
    {
        u16 state;

        switch (act->kind) {
        case 1:
        case 3:
        case 2:
            state = 0x20;
            break;
        default:
            state = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)actionBytes, state);
    }
}

#pragma pop
// FUN_001ABBA0
void btlActionSummonInit(void)
{
}

/* Measured 2026-09-28: 2384/2384 bytes, resolved code/data references and
 * all 70 sibling functions unchanged. Packed colors, the halfword skill
 * selector, and packet/ID lifetimes retain the 0x170 frame. The formation
 * filename is a 128-byte string; encounter insertion returns DatUnit*. */
// FUN_001ABBB0
#pragma push
/* measured: func_001abbb0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Play the summon presentation and initialize up to three new encounter actors and their resources. */
/* Raw packet offsets retain MATCH after both UID and signed-header rewrites changed allocation; encounter +0xC68 is opaque. */
void btlActionSummonUpdate(s64 *actionBytes)
{
    typedef struct DatUnit DatUnit;
    typedef struct DatUnitEc DatUnitEc;
    extern s32 btlFormationAllocWork(u32 mode);
    extern void btlFormationSetPlacement(u32 formation);
    extern BtlPacket *btlEffectCreateSpriteFramePacket(u32 sprite, u16 frame);
    extern u8 *btlTargetCreateHitPacket(u8 *action);
    extern void btlMainSkillColorPairDefaults(u32 skill, s32 *color, s32 *tint);
    extern s32 btlMainSkillColorDefault(s32 skill);
    extern s32 btlMainSkillTintDefault(s32 skill);
    extern void btlMainSkillColorPairDefaultsAlt(u32 skill, s32 *color, s32 *tint);
    extern BtlPacket *btlMainCreateColorLerpPacket(u32 startColor, u32 targetColor, u32 duration);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 lightColor, s32 ambientColor, s32 fogColor, u32 duration, u16 flags);
    extern BtlPacket *btlMainCreateTintPacket(u32 targetColor, u32 duration);
    extern BtlPacket *btlSoundCreateSkillSEPacket(u16 skillId, u16 flags);
    extern u8 *btlPacketCreateImmediate(void);
    extern u8 *btlActionCreateWork(s32 genus, u16 characterId, u16 *unitData);
    extern void btlUnitInitFromRecord(u8 *unit, s32 characterId);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *unit, u16 modelId, s16 motion);
    extern BtlPacket *btlUnitCreateResourceLoadPacket(BtlUnit *unit, u16 id, u16 flags);
    extern BtlPacket *btlCreateTimingPacket(u32 value);
    extern BtlPacket *btlMainCreateFadePacket(s32 arg, s16 mode);
    extern BtlPacket *btlMainCreateColorFadePacket(s32 arg);
    extern s32 btlSoundCanReceiveStatus(u8 *action);
    /* Unit APIs consume pointers; formation APIs consume their EE word representation. */
    typedef union BtlSummonUnitReference {
        BtlUnit *pointer;
        u32 address;
        s32 signedAddress;
    } BtlSummonUnitReference;
    typedef struct BtlSummonAction {
        s64 actionUid;
        u8 unknown08[0x28];
        BtlSummonUnitReference unitRef;
        u8 unknown34[0x38];
        u16 mode;
        s16 skillValue;
        u8 unknown70[6];
        u16 ids[3];
    } BtlSummonAction;
    s32 firstColor;
    s32 secondColor;
    char formationName[128];
    s32 formationStarted;
    s32 skillFlagsOffset;
    BtlSummonAction *action;
    s64 actionUid;
    s16 skillId;
    u8 *formationNamePacket;
    s64 castingUid;
    u16 skillKey;
    u32 skillValue;
    s32 formationHandle;
    u8 *castingPacket;
    BtlUnit *unit;
    s64 sequenceUid;
    s32 castingFrames;
    u8 *skillSoundPacket;
    u8 *lastPacket;
    u32 summonIndex;

    action = (BtlSummonAction *)actionBytes;
    skillId = action->skillValue;
    actionUid = action->actionUid;
    btlActionFinishPresentation((BtlAction *)actionBytes);
    formationHandle = btlFormationAllocWork(1);
    skillKey = (u16)skillId;
    skillValue = skillKey;
    {
        u8 *packet;
        packet = (u8 *)btlEffectCreateSpriteFramePacket((u32)action->unitRef.pointer, skillKey);
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 3);
    }
    {
        u8 *packet;
        packet = btlTargetCreateHitPacket((u8 *)action);
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = btlTargetCreateActionPacket((u8 *)action, 0);
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    castingPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)action->unitRef.pointer, 8, 6, 1.0f, 0);
    ((BtlPacketTiming *)castingPacket)->actionUid = actionUid;
    btlPacketEnqueue(castingPacket, 0);
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x15);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(castingPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 0);
    }
    castingUid = *(s64 *)(castingPacket + 0x58);
    castingFrames = btlUnitMotionFrames((u8 *)action->unitRef.pointer, 8, 1.0f);
    btlMainSkillColorPairDefaults(skillValue, &firstColor, &secondColor);
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorLerpPacket((u32)firstColor, (u32)secondColor, 0x10);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = castingUid;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        s32 kind;
        u8 *packet;
        kind = btlMainSkillColorDefault(skillValue);
        btlMainSkillColorPairDefaultsAlt(skillValue, &firstColor, &secondColor);
        packet = (u8 *)btlMainCreateColorWorkPacket(kind, firstColor, secondColor, 0x10, 0);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = castingUid;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateTintPacket(btlMainSkillTintDefault(skillValue), 0x10);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = castingUid;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateUnitTintPacket((BtlAction *)action, skillValue, 0x10);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = castingUid;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    btlFormationFormatName(skillValue, formationName);
    formationNamePacket = (u8 *)btlFormationCreateNamedPacket(formationHandle, formationName, 0);
    *formationNamePacket = 4;
    ((BtlPacketTiming *)formationNamePacket)->dependencyUid = 0;
    ((BtlPacketTiming *)formationNamePacket)->delay = castingFrames + 6;
    ((BtlPacketTiming *)formationNamePacket)->actionUid = actionUid;
    btlPacketEnqueue(formationNamePacket, 1);
    skillSoundPacket = (u8 *)btlSoundCreateSkillSEPacket(skillKey, 0);
    *skillSoundPacket = 4;
    ((BtlPacketTiming *)skillSoundPacket)->dependencyUid = *(s64 *)(formationNamePacket + 0x58);
    btlPacketEnqueue(skillSoundPacket, 1);
    {
        u8 *packet;
        u8 *nextPacket;
        packet = (u8 *)btlFormationCreatePacket(formationHandle, action->unitRef.address, action->unitRef.address, 0, 0);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(formationNamePacket + 0x58);
        *(packet + 0x10) = 4;
        ((BtlPacket *)packet)->dependencyUID2 = *(s64 *)(skillSoundPacket + 0x58);
        btlPacketEnqueue(packet, 2);
        nextPacket = (u8 *)btlSoundCreateCueQueuePacket(0);
        *nextPacket = 5;
        ((BtlPacketTiming *)nextPacket)->dependencyUid = ((BtlPacketTiming *)packet)->uid;
        btlPacketEnqueue(nextPacket, 1);
    }
    sequenceUid = ((BtlPacketTiming *)formationNamePacket)->uid;
    lastPacket = btlPacketCreateImmediate();
    *lastPacket = 4;
    ((BtlPacketTiming *)lastPacket)->dependencyUid = sequenceUid;
    ((BtlPacketTiming *)lastPacket)->delay = 0x18;
    ((BtlPacketTiming *)lastPacket)->actionUid = actionUid;
    btlPacketEnqueue(lastPacket, 1);
    lastPacket = btlEffectCreateFormationPacket((s32)((BtlBattleState *)iGpffffb3ac)->formations[15], action->unitRef.signedAddress, 0, ((BtlPacketTiming *)lastPacket)->uid, 0x100);
    *lastPacket = 4;
    ((BtlPacketTiming *)lastPacket)->dependencyUid = *(s64 *)(castingPacket + 0x58);
    ((BtlPacketTiming *)lastPacket)->actionUid = actionUid;
    btlPacketEnqueue(lastPacket, 1);
    {
        u8 *packet;
        packet = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 7);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)castingPacket)->uid;
        btlPacketEnqueue(packet, 1);
    }
    formationStarted = 0;
    summonIndex = 0;
    skillFlagsOffset = (s32)skillId * 4;
    for (; (u16)summonIndex < 3; summonIndex = (u16)(summonIndex + 1)) {
        u16 unitId;
        u8 *summonedAction;
        unitId = action->ids[(u16)summonIndex];
        if (unitId == 0) {
            break;
        }
        summonedAction = btlActionCreateWork(1, unitId, NULL);
        unit = ((BtlSummonUnitReference *)(summonedAction + 0x30))->pointer;
        unit->datUnit = datUnitAddEncounterUnit((DatUnitEc*)((BtlBattleState *)iGpffffb3ac)->encounterRecord, unitId);
        btlUnitInitFromRecord((u8 *)unit, unitId & 0xFFFF);
        unit->unk_94 = action->unitRef.pointer->unk_94;
        unit->unk_96 = action->unitRef.pointer->unk_96;
        unit->pos = action->unitRef.pointer->pos;
        if (formationStarted == 0) {
            {
                u8 *packet;
                packet = (u8 *)btlFormationCreateReturnPacket(0);
                *packet = 4;
                ((BtlPacketTiming *)packet)->dependencyUid = sequenceUid;
                ((BtlPacketTiming *)packet)->actionUid = actionUid;
                btlPacketEnqueue(packet, 0);
            }
            {
                u8 *packet;
                packet = (u8 *)btlFormationCreateSlotPacket(1, 0xFFF);
                *packet = 4;
                ((BtlPacketTiming *)packet)->dependencyUid = sequenceUid;
                ((BtlPacketTiming *)packet)->actionUid = actionUid;
                btlPacketEnqueue(packet, 0);
            }
            if ((*(u16 *)((u32)skillFlagsOffset + (u32)((u8 *)iGpffffb3bc) + 2) & 0x40) == 0) {
                {
                    u8 *packet;
                    packet = (u8 *)btlEffectCreateReleasePacket(5);
                    *packet = 4;
                    ((BtlPacketTiming *)packet)->dependencyUid = sequenceUid;
                    ((BtlPacketTiming *)packet)->actionUid = actionUid;
                    btlPacketEnqueue(packet, 0);
                }
                {
                    u8 *packet;
                    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x2D);
                    *packet = 4;
                    ((BtlPacketTiming *)packet)->dependencyUid = sequenceUid;
                    ((BtlPacketTiming *)packet)->actionUid = actionUid;
                    btlPacketEnqueue(packet, 0);
                }
            }
            formationStarted = 1;
        }
        {
            u8 *modelPacket;
            u8 *resourcePacket;
            u8 *formationPacket;
            modelPacket = btlUnitCreateModelLoadPacket((u8 *)unit, unitId, 0x7E);
            *modelPacket = 4;
            ((BtlPacketTiming *)modelPacket)->dependencyUid = sequenceUid;
            ((BtlPacketTiming *)modelPacket)->actionUid = actionUid;
            btlPacketEnqueue(modelPacket, 1);
            resourcePacket = (u8 *)btlUnitCreateResourceLoadPacket((BtlUnit *)unit, unitId, 0x10);
            *resourcePacket = 4;
            ((BtlPacketTiming *)resourcePacket)->dependencyUid = ((BtlPacketTiming *)modelPacket)->uid;
            btlPacketEnqueue(resourcePacket, 1);
            formationPacket = (u8 *)btlFormationCreatePacket(formationHandle, action->unitRef.address, ((BtlSummonUnitReference *)(summonedAction + 0x30))->address, 1, 0x100);
            *formationPacket = 4;
            ((BtlPacketTiming *)formationPacket)->dependencyUid = *(s64 *)(resourcePacket + 0x58);
            *(formationPacket + 0x10) = 4;
            ((BtlPacket *)formationPacket)->dependencyUID2 = ((BtlPacketTiming *)skillSoundPacket)->uid;
            ((BtlPacketTiming *)formationPacket)->actionUid = actionUid;
            btlPacketEnqueue(formationPacket, 2);
            lastPacket = formationPacket;
            {
                u8 *cuePacket;
                cuePacket = (u8 *)btlSoundCreateCueQueuePacket(1);
                *cuePacket = 5;
                ((BtlPacketTiming *)cuePacket)->dependencyUid = *(s64 *)(formationPacket + 0x58);
                btlPacketEnqueue(cuePacket, 1);
            }
            if (((u16)summonIndex == 0) && (action->ids[1] == 0)) {
                u8 *messagePacket;
                messagePacket = (u8 *)btlPacketCreateEffectCounter(((BtlSummonUnitReference *)(summonedAction + 0x30))->signedAddress, 0x9F);
                *messagePacket = 5;
                ((BtlPacketTiming *)messagePacket)->dependencyUid = ((BtlPacketTiming *)formationPacket)->uid;
                ((BtlPacketTiming *)messagePacket)->delay = 0x1C;
                btlPacketEnqueue(messagePacket, 3);
            }
            {
                u8 *colorPacket;
                colorPacket = btlUnitCreateColorPacket((u8 *)unit, -1, 0xC, 0, 3, 1);
                *colorPacket = 4;
                ((BtlPacketTiming *)colorPacket)->dependencyUid = *(s64 *)(resourcePacket + 0x58);
                *(colorPacket + 0x10) = 0xB;
                ((BtlPacket *)colorPacket)->dependencyUID2 = ((BtlPacketTiming *)formationPacket)->uid;
                ((BtlPacketTiming *)colorPacket)->delay = 1;
                ((BtlPacketTiming *)colorPacket)->actionUid = actionUid;
                btlPacketEnqueue(colorPacket, 1);
            }
            sequenceUid = ((BtlPacketTiming *)resourcePacket)->uid;
        }
    }
    {
        u8 *packet;
        packet = (u8 *)btlActionCreateTargetPacketBytes((u8 *)action, 9, 0, 0, 0);
        *packet = 0xB;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(lastPacket + 0x58);
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCreateTimingPacket(0x10);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(lastPacket + 0x58);
        *(packet + 0x47) &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(lastPacket + 0x58);
        *(packet + 0x47) &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorFadePacket(0x10);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(lastPacket + 0x58);
        *(packet + 0x47) &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorSetPacket(8);
        *packet = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)lastPacket)->uid;
        *(packet + 0x47) &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = actionUid;
        btlPacketEnqueue(packet, 0);
    }
    btlFormationSetPlacement(formationHandle);
    if (btlSoundCanReceiveStatus((u8 *)action) != 0) {
        btlActionSetState((BtlAction *)action, 0x1B);
    } else {
        u16 nextState;
        switch (action->mode) {
        case 1:
        case 3:
        case 2:
            nextState = 0x20;
            break;
        default:
            nextState = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)action, nextState);
    }
}

#pragma pop
// FUN_001AC500
/* Select assist targets and establish the formation/camera presentation before readiness. */
void btlActionAssistInit(BtlAction *action) {
    u8 *resetPacket;
    u8 *cameraPacket;

    btlActionFinishPresentation(action);
    btlTargetResetCommandRecord((u8 *)action + 0x38);
    btlAICommandPickAiTarget(action, 0);
    btlActionFinishPresentation(action);
    resetPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    ((BtlPacket *)resetPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(resetPacket, 0);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket(action, 0x2C);
    ((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(cameraPacket, 0);
    ((BtlAction *)action)->flags |= 2;
}

// FUN_001AC5B0
/* Wait for outstanding assist presentation packets, then mark the action ready. */
void btlActionAssistUpdate(BtlAction *action) {
    if ((btlCountUnitRecordsById(0x506) == 0) && (btlCountUnitRecordsById(0x800) == 0)) {
        ((BtlAction *)action)->flags = (u16) (((BtlAction *)action)->flags | 0x100);
        btlActionSetState(action, 0xFU);
    }
}

// FUN_001AC620
/* Release active linked-unit models before running the action event callback. */
void btlActionEventInit(void) {
    u8 *actionCursor = ((BtlBattleState *)D_0076449C)->actions;
    u8 *releasePacket;

    while (actionCursor != NULL) {
        if (btlActionLinkedUnitIsActive((BtlAction *)actionCursor) != 0) {
            releasePacket = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)((u8 *)((BtlAction *)actionCursor)->unit))->childUnit);
            ((BtlPacket *)releasePacket)->actionUID = *(s64 *)actionCursor;
            btlPacketEnqueue(releasePacket, 1);
        }
        actionCursor = (u8 *)((BtlAction *)actionCursor)->next;
    }
}

// FUN_001AC6A0
/* Poll the installed event callback and resume the saved action state when it returns zero. */
/* Raw +0x440 retains the installed callback's function-pointer type; BtlAction exposes that slot as void *. */
void btlActionEventUpdate(BtlAction *action) {
    if (((s32 (*)(void))action->unk_440)() == 0) {
        btlActionSetState(action, *(u16 *)((u8 *)action + 0x43C));
    }
}

// FUN_001AC6F0
void btlActionErrorInit(void)
{
}

// FUN_001AC700
/* Present the failed action with its unit-specific motion, camera and effect message, then recover. */
/* Raw action/packet offsets retain MATCH; both action-scalar and signed packet-header rewrites changed instructions. */
void btlActionErrorUpdate(u8 *action) {
    s64 packetIdentity;
    s32 alternateAction;
    s32 animationChoice;
    f32 speed;
    u16 actionKind;
    u8 *animationPacket;

    BtlPacket *btlEffectCreateSpriteFramePacket(u32 sprite, u16 frame);
    BtlPacket *btlPacketCreateSpriteStep(u32 sprite, u16 frame);
    BtlPacket *btlMainCreateFadePacket(s32 arg, s16 mode);
    BtlPacket *btlCreateTimingPacket(u32 value);
    BtlPacket *btlMainCreateColorFadePacket(s32 arg);


    struct {
        u16 resource;
        u16 animation;
        u16 frames;
        u16 cameraState;
    } selection;

    btlActionFinishPresentation((BtlAction *)action);
    alternateAction = (*(u16 *)(action + 0x6C) == 3);
    packetIdentity = *(s64 *)action;
    if (alternateAction == 0) {
        u8 *packet;
        packet = (u8 *)btlEffectCreateSpriteFramePacket(*(s32 *)(action + 0x30),
                               ((BtlAction *)action)->unk_6e);
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 3);
    } else {
        u8 *packet;
        packet = (u8 *)btlPacketCreateSpriteStep((s32)((BtlAction *)action)->unit,
                               ((BtlAction *)action)->parameters.item);
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 3);
    }
    if (((BtlUnit *)(*(u8 **)(action + 0x30)))->genus == 0) {
        if (alternateAction == 0) {
            selection.animation = (s64)0xD;
            selection.resource = (s64)0xB;
        } else {
            selection.animation = (s64)0x16;
            selection.resource = (s64)0x21;
        }
        selection.cameraState = 0x14;
        selection.frames = btlUnitMotionModelFrames(*(u8 **)(action + 0x30),
                               selection.animation, 1.0f);
        speed = 1.0f;
    } else {
        if (btlTargetIsEntryActive((s16)((BtlAction *)action)->unk_6e) != 0) {
            animationChoice = 4;
        } else {
            animationChoice = 8;
        }
        selection.animation = (u16)animationChoice;
        selection.resource = (s64)0xF;
        selection.cameraState = 0x15;
        if (((BtlAction *)action)->flags & 0x4000) {
            speed = 2.0f;
        } else {
            speed = 1.0f;
        }
        selection.frames = btlUnitMotionFrames((u8*)((BtlAction *)action)->unit,
                               selection.animation, speed);
    }
    animationPacket = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(action + 0x30),
                                 (s16)selection.animation, 6, speed, 0);
    ((BtlPacketTiming *)animationPacket)->actionUid = packetIdentity;
    ((BtlPacketTiming *)animationPacket)->duration = (s16)((selection.frames & 0xFFFF) + 6);
    btlPacketEnqueue(animationPacket, 0);
    {
        u8 *packet;
        packet = btlEffectCreateFormationPacket(
            btlActionGetFormationAddress((BtlBattleState *)D_0076449C, (u16)selection.resource),
            (s32)((BtlAction *)action)->unit, 0,
            *(s64 *)(animationPacket + 0x58), 0x100);
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 2);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, selection.cameraState);
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 0);
    }
    {
        u8 *packet;
        packet = (u8 *)btlActionCreateMessagePacketBytes(*(s32 *)(action + 0x30),
                               (s16)((BtlAction *)action)->targetBlock.message.messageCode);
        ((BtlPacketTiming *)packet)->dependencyKind = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 3);
    }
    {
        u8 *packet;
        packet = btlTargetCreateActionPacket(action, 0);
        ((BtlPacketTiming *)packet)->dependencyKind = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlCreateTimingPacket(0x10);
        ((BtlPacketTiming *)packet)->dependencyKind = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
        ((BtlPacketTiming *)packet)->flags &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
        ((BtlPacketTiming *)packet)->dependencyKind = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
        ((BtlPacketTiming *)packet)->flags &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorFadePacket(0x10);
        ((BtlPacketTiming *)packet)->dependencyKind = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(animationPacket + 0x58);
        ((BtlPacketTiming *)packet)->flags &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorSetPacket(8);
        ((BtlPacketTiming *)packet)->dependencyKind = 4;
        ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)animationPacket)->uid;
        ((BtlPacketTiming *)packet)->flags &= ~0x20;
        ((BtlPacketTiming *)packet)->actionUid = packetIdentity;
        btlPacketEnqueue(packet, 0);
    }
    if (btlSoundCanReceiveStatus(action) != 0) {
        btlActionSetState((BtlAction *)action, 0x1B);
        return;
    }
    actionKind = ((BtlAction *)action)->unk_6c;
    {
        u16 nextState;
        switch (actionKind) {
        case 1:
        case 3:
        case 2:
            nextState = 0x20;
            break;
        default:
            nextState = 0x20;
            break;
        }
        btlActionSetState((BtlAction *)action, nextState);
    }
}

// FUN_001ACB10
/* Apply the selected endurance flag, or restore the saved state when no endurance skill is pending. */
/* Raw +0x3F4 accesses the endurance-state variant of hit storage; shared layouts do not declare that variant. */
void btlActionEndureInit(u8 *action)
{
    u16 skillId;
    u8 *unitStatePtr;

    skillId = *(u16 *)(action + 0x3F4);
    switch (skillId) {
    case 0x20F:
        unitStatePtr = (u8 *)((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->datUnit;
        *(u16 *)unitStatePtr = *(u16 *)unitStatePtr | 0x400;
        break;
    case 0x210:
        unitStatePtr = (u8 *)((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->datUnit;
        *(u16 *)unitStatePtr = *(u16 *)unitStatePtr | 0x800;
        break;
    }
    if (((BtlAction *)action)->targetBlock.recovery.enduranceSkill == 0) {
        unitStatePtr = (u8 *)((BtlAction *)action)->unit;
        ((BtlUnit *)unitStatePtr)->flags3 = (s32)((BtlUnit *)unitStatePtr)->flags3 & ~0x10;
        btlActionSetState((BtlAction *)action, (u16)((BtlAction *)action)->unk_430);
    }
}

// FUN_001ACBB0
/* Present endurance activation, consume its item when required, and apply the full-HP recovery result. */
/* Raw endurance/unit offsets retain MATCH; canonical unit accesses changed allocation, and +0x3F4 is state-specific. */
void btlActionEndureUpdate(u8 *action) {
    LargeBattleHitResult damageResult;
    s32 value;
    s32 remainingCount;
    s32 prevFlags;
    s32 flagAdded;
    s64 secondPacketTag;
    s64 firstPacketTag;
    s64 messageIdVariant;
    s64 messageId;
    s64 messageIdDefault;
    u16 skillId;
    u8 *battleUnit;
    u8 *messagePacket;
    u8 *damagePacket;
    u8 *unitPacket;
    u8 *statusPacket;
    u8 *statPacket;
    u8 *removeFlagsPacket;

    s32 datItemCount(s16 itemId);
    u8 *btlCreateRemoveFlagsPacket(s32 flags);
    u8 *btlPacketCreateImmediate(void);
    void btlTargetClearResultBuffer(u8 *result);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);

    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
    void btlActionSetState(u8 *action, u16 state);
    u8 *btlPacketCreateHpRatio(u8 *unit);
    u32 datCalcGetHp(u8 *unit);
    u32 datCalcMaxHp(u8 *unit);

    battleUnit = *(u8 **)((u8 *)action + 0x30);
    ((BtlUnit *)battleUnit)->flags3 &= ~0x10;
    if (btlCountUnitRecordsById(0xFF03) == 0) {
        prevFlags = ((BtlBattleState *)D_0076449C)->flags;
        if (!(prevFlags & 0x80000)) {
            ((BtlBattleState *)D_0076449C)->flags = prevFlags | 0x80000;
            flagAdded = 1;
        } else {
            flagAdded = 0;
        }
        skillId = *(u16 *)(action + 0x3F4);
        switch (skillId) {
        case 0x210:
            if (((BtlUnit *)battleUnit)->genus == 0) {
                messageIdVariant = 0x3E;
            } else {
                messageIdVariant = 0x3F;
            }
            messageId = (s16)messageIdVariant;
            break;
        case 0x154:
            messageId = 0x9B;
            break;
        case 0x231:
            messageId = 0xB4;
            break;
        case 0x232:
            messageId = 0xB6;
            break;
        default:
            if (((BtlUnit *)battleUnit)->genus == 0) {
                messageIdDefault = 0x3C;
            } else {
                messageIdDefault = 0x3D;
            }
            messageId = (s16)messageIdDefault;
            break;
        }
        value = (s16)messageId;
        messagePacket = btlActionCreateMessagePacketBytes((s32)(u8*)((BtlAction *)action)->unit,
                                 value);
        ((BtlPacketTiming *)messagePacket)->delay = 8;
        ((BtlPacket *)messagePacket)->actionUID = *(s64 *)action;
        btlPacketEnqueue(messagePacket, 3);
        firstPacketTag = ((BtlPacket *)messagePacket)->uid;
        messagePacket = btlPacketCreateImmediate();
        ((BtlPacketTiming *)messagePacket)->delay = 8;
        ((BtlPacket *)messagePacket)->actionUID = *(s64 *)action;
        btlPacketEnqueue(messagePacket, 0);
        secondPacketTag = ((BtlPacket *)messagePacket)->uid;
        if (*(u16 *)(action + 0x3F4) == 0x154) {
            remainingCount = datItemCount(0x340) & 0xFF;
            if (remainingCount > 0) {
                datItemSetCount(0x340, (remainingCount - 1) & 0xFF);
            }
        }
        if (((BtlAction *)action)->targetBlock.recovery.enduranceSkill == 0x210) {
            btlTargetClearResultBuffer((u8 *)&damageResult);
            value = datCalcMaxHp(*(u8 **)(battleUnit + 0xA64)) & 0xFFFF;
            damageResult.hpDelta = value - (datCalcGetHp((u8*)((BtlUnit *)battleUnit)->datUnit) & 0xFFFF);
            damagePacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action,
                                     &damageResult, 1, 1);
            ((BtlPacketTiming *)damagePacket)->dependencyKind = 4;
            ((BtlPacketTiming *)damagePacket)->dependencyUid = secondPacketTag;
            ((BtlPacket *)damagePacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(damagePacket, 1);
            unitPacket = btlPacketCreateHpRatio(battleUnit);
            ((BtlPacketTiming *)unitPacket)->dependencyKind = 4;
            ((BtlPacketTiming *)unitPacket)->dependencyUid = secondPacketTag;
            ((BtlPacket *)unitPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(unitPacket, 1);
            statusPacket = btlPacketCreateHitDisplay((s32)battleUnit, (s32)battleUnit, -1, 0, 0,
                                     0, 1, (u8 *)&damageResult, 0);
            ((BtlPacketTiming *)statusPacket)->dependencyKind = 4;
            ((BtlPacketTiming *)statusPacket)->dependencyUid = secondPacketTag;
            ((BtlPacket *)statusPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(statusPacket, 3);
            statPacket = btlPacketCreateUnitCounter((s32)battleUnit, 0, 0);
            ((BtlPacketTiming *)statPacket)->dependencyKind = 4;
            ((BtlPacketTiming *)statPacket)->dependencyUid = secondPacketTag;
            ((BtlPacket *)statPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(statPacket, 3);
        }
        if (flagAdded != 0) {
            removeFlagsPacket = btlCreateRemoveFlagsPacket(0x80000);
            ((BtlPacketTiming *)removeFlagsPacket)->dependencyKind = 4;
            ((BtlPacketTiming *)removeFlagsPacket)->dependencyUid = firstPacketTag;
            ((BtlPacket *)removeFlagsPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(removeFlagsPacket, 0);
        }
        btlActionSetState(action, *(u16 *)(action + 0x430));
    }
}

// FUN_001ACF40
void btlActionWaitInit(void)
{
}

// FUN_001ACF50
u8 *btlPacketCreateImmediate(void);
s32 btlUnitGetMotionState(u8 *unit);

void btlTargetClearResultBuffer(u8 *result);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
s32 btlSoundCanReceiveStatus(u8 *action);

/* Present the wait command and its optional recovery/status packet before selecting the next state. */
/* Raw action/packet offsets retain MATCH; scalar and packet-header rewrites both changed this state's frame. */
void btlActionWaitUpdate(u8 *action) {
    LargeBattleHitResult result;
    u16 actionKind;
    u8 *packet;
    u8 *battleUnit;
    void btlActionFinishPresentation();
    u8 *recoveryPacket;

    switch (*(u16 *)(action + 0x6C)) {
    case 7:
        btlActionFinishPresentation();
        packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3);
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
        if (*(s16 *)(action + 0xEC) != 0) {
            packet = btlActionCreateMessagePacketBytes(*(s32 *)(action + 0x30), (s16)((BtlAction *)action)->targetBlock.message.messageCode);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 3);
        } else {
            battleUnit = (u8*)((BtlAction *)action)->unit;
            if (((s32)((BtlUnit *)battleUnit)->flags3 & 0x4000) != 0) {
                actionKind = ((BtlAction *)action)->unk_6c;
            } else {
                actionKind = 8;
            }
            packet = btlPacketCreateSpriteTable((u32)battleUnit, actionKind & 0xFFFF);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 3);
        }
        packet = func_001f99c0(action, 0x16, 0, 0, 0);
        ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
        if (((s32)((BtlUnit *)*(u8 **)(action + 0x30))->flags3 & 0x4000) != 0) {
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x32);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 0);
            if ((s16)btlUnitGetMotionState(*(u8 **)(action + 0x30)) != 0x11) {
                recoveryPacket = btlActionCreateRecoveryPacketBytes((BtlUnit *)(u8*)((BtlAction *)action)->unit);
                ((BtlPacketTiming *)recoveryPacket)->actionUid = *(s64 *)action;
                btlPacketEnqueue(recoveryPacket, 0);
            } else {
                recoveryPacket = btlPacketCreateImmediate();
                ((BtlPacketTiming *)recoveryPacket)->actionUid = *(s64 *)action;
                btlPacketEnqueue(recoveryPacket, 0);
            }
            btlTargetClearResultBuffer((u8 *)&result);
            result.flags |= 0x80;
            packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
            ((BtlPacketTiming *)packet)->dependencyKind = 4;
            ((BtlPacketTiming *)packet)->dependencyUid = *(s64 *)(recoveryPacket + 0x58);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 1);
            packet = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)(u8*)((BtlAction *)action)->unit, 0x18, 6, 1.0f, 1);
            ((BtlPacketTiming *)packet)->dependencyKind = 4;
            ((BtlPacketTiming *)packet)->dependencyUid = ((BtlPacketTiming *)recoveryPacket)->uid;
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 0);
        } else {
            packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0xA);
            ((BtlPacketTiming *)packet)->actionUid = *(s64 *)action;
            btlPacketEnqueue(packet, 0);
        }
        break;
    case 8:
    case 11:
        break;
    }
    btlPacketEnqueue(btlTargetCreateActionPacket(action, 0), 1);
    if ((btlSoundCanReceiveStatus(action) != 0) && (((BtlAction *)action)->unk_6c != 8)) {
        btlActionSetState((BtlAction *)action, 0x1B);
        return;
    }
    btlActionSetState((BtlAction *)action, 0x20);
}

// FUN_001AD280
/* Focus the actors for an escape confirmation prompt and initialize its message phase. */
/* Raw selected-action pointers and the ten-byte cut-in buffer retain existing provider word/byte boundaries. */
void btlActionEscapeMesInit(u8 *action)
{
    s16 cutinParams[8];
    u8 *lookAtPacket;
    u8 *resetPacket;
    u8 *cameraPacket;
    u8 *cutinPacket;

    btlActionFinishPresentation((BtlAction *)action);
    lookAtPacket = btlActionCreateLookAtUnitPacketBytes(
        (u8*)((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unit,
        *(u8 **)(action + 0x30),
        0);
    ((BtlPacket *)lookAtPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(lookAtPacket, 1);
    lookAtPacket = btlActionCreateLookAtUnitPacketBytes(
        (u8*)((BtlAction *)action)->unit,
        (u8*)((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unit,
        0);
    ((BtlPacket *)lookAtPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(lookAtPacket, 1);
    ((BtlAction *)action)->flags |= 0x200;
    resetPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    ((BtlPacket *)resetPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(resetPacket, 0);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 9);
    ((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(cameraPacket, 0);
    cutinParams[0] = 5;
    cutinPacket = btlSoundLoadPacketNew((u8 *)&cutinParams[0]);
    ((BtlPacket *)cutinPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(cutinPacket, 1);
    if (btlTargetCanControlDamagePhase() == 1) {
        ((BtlBattleState *)D_0076449C)->flags &= ~0x2000;
        btlDamageSetSource((u8 *)((BtlBattleState *)D_0076449C)->uiTask, 0);
    }
    ((BtlAction *)action)->unk_41c = 0;
}

// FUN_001AD3E0
/* Wait for presentation completion, obtain the escape answer, and release the prompt resources. */
/* Raw phase-word accesses retain MATCH; replacing them with BtlAction fields changed this state's frame. */
void btlActionEscapeMesUpdate(u8 *action)
{
    u8 *packet;

    if (*(s32 *)(action + 0x41C) != 0) {
        goto common;
    }
    if (btlUnitRecordFindByActionUID(*(s64 *)action, 0x3FFFFFFFFFFFFFFFLL) != 0) {
        goto done;
    }
    btlMessageInstallWindow(((BtlBattleState *)D_0076449C)->uiTask, action);
    packet = btlSoundLoadTaskStart();
    ((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    ((BtlAction *)action)->unk_41c = 1;
common:
    if (btlMessageIsActiveAlt2(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
        goto done;
    }
    if (btlTargetCanControlDamagePhase() != 1) {
        goto after_flag;
    }
    ((BtlBattleState *)D_0076449C)->flags |= 0x2000;
    btlDamageSetSource((u8 *)((BtlBattleState *)D_0076449C)->uiTask, 1);
after_flag:
    if (btlMessageGetResultAlt2(((BtlBattleState *)D_0076449C)->uiTask) != 0) {
        goto alternate;
    }
    btlActionSetState((BtlAction *)action, 0x1D);
    goto after_state;
alternate:
    btlActionSetState((BtlAction *)action, 0x20);
after_state:
    packet = btlSoundReleaseTaskStart();
    ((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    btlMessageRelease(((BtlBattleState *)D_0076449C)->uiTask);
done:
    return;
}

// FUN_001AD540
void btlActionEscapeInit(void)
{
}

// FUN_001AD550
/* measured: func_001ad550 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Collect eligible escaping actors and sequence their movement, hiding and encounter-end dependencies. */
/* Raw packet offsets retain MATCH after signed-header rewriting; escape count and tagged packet gates are opaque. */
void btlActionEscapeUpdate(s64 *actionBytes)
{
    #include "rw_types_internal.h"
    extern void btlUnitGetSphereWorldCenter(BtlUnit *unit, RwV3d *dst);
    extern RwV3d *RtQuatTransformVectors(RwV3d *out, const RwV3d *in, s32 count, const RtQuat *quat);
    extern BtlPacket *btlCreateSetFlagsPacket(u32 flags);
    extern RwV3d D_0060A100;
    extern f32 fGpffff8218;
    BtlAction *action;
    RwV3d escapeDestination;
    RwV3d sphereCenter;
    RwV3d escapeOffset;
    BtlAction *collected[12];
    union {
        RtQuat rotation;
        f32 values[4];
    } facing;
    u8 *spritePacket;
    u8 *movementPacket;
    BtlAction *escapingAction;
    BtlAction *actionCursor;
    s64 lastPacketUid;
    s32 collectedParty;
    s32 groupEscape;
    u16 count;
    u16 actionIndex;

    action = (BtlAction *)actionBytes;
    btlActionFinishPresentation((BtlAction *)actionBytes);
    spritePacket = btlPacketCreateSpriteTable((u32)action->unit, 6);
    ((BtlPacketTiming *)spritePacket)->actionUid = action->uid;
    btlPacketEnqueue(spritePacket, 3);
    collectedParty = 0;
    groupEscape = 0;
    count = 0;
    lastPacketUid = 0;
    switch (action->unit->genus) {
    case 0:
        if (action->unk_6c != 0xC) {
            ((BtlBattleState *)iGpffffb3ac)->escapeCount = ((BtlBattleState *)iGpffffb3ac)->escapeCount + 1;
            groupEscape = 1;
            for (actionCursor = (BtlAction*)((BtlBattleState *)iGpffffb3ac)->actions; actionCursor != NULL; actionCursor = actionCursor->next) {
                if ((actionCursor->unk_1a & 1) != 0) {
                    if (actionCursor->unit->genus == 0) {
                        if (datCalcIsDead((s32)actionCursor->unit->datUnit, 0) == 0) {
                            if (datCalcChkBadStatus((s32)actionCursor->unit->datUnit, 0x100001) == 0) {
                                collected[count] = actionCursor;
                                count++;
                            }
                        }
                    }
                }
            }
            collectedParty = 1;
        } else {
            collected[0] = action;
            count = 1;
            action->flags |= 0x20;
            action->unk_1a &= 0xFFF7;
        }
        break;
    case 1:
        collected[0] = action;
        count = 1;
        action->flags |= 0x20;
        action->unk_1a &= 0xFFF7;
        break;
    }
    if (collectedParty == 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)collected[0], 0xA);
            ((BtlPacketTiming *)pkt)->actionUid = action->uid;
            btlPacketEnqueue(pkt, 0);
        }
    }
    if (action->unit->genus == 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlSoundCreateCuePacket(0xF, 2, 0);
            *pkt = 5;
            ((BtlPacketTiming *)pkt)->dependencyUid = *(s64 *)(spritePacket + 0x58);
            ((BtlPacketTiming *)pkt)->delay = 0x1A;
            ((BtlPacketTiming *)pkt)->actionUid = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
        if (action->unk_6c == 0xC) {
            {
                u8 *pkt;
                pkt = btlActionCreateTargetPacketBytes((u8 *)action, 7, 0, 0, 0);
                ((BtlPacketTiming *)pkt)->actionUid = action->uid;
                btlPacketEnqueue(pkt, 1);
            }
        } else if (groupEscape == 1) {
            {
                u8 *pkt;
                pkt = btlPacketCreateEndSequence();
                *pkt = 5;
                ((BtlPacketTiming *)pkt)->dependencyUid = ((BtlPacketTiming *)spritePacket)->uid;
                ((BtlPacketTiming *)pkt)->delay = 0x10;
                ((BtlPacketTiming *)pkt)->actionUid = action->uid;
                btlPacketEnqueue(pkt, 1);
            }
        }
    } else {
        {
            u8 *pkt;
            pkt = (u8 *)btlSoundCreateChannelCuePacket(0xC, 2, 0xF);
            *pkt = 5;
            ((BtlPacketTiming *)pkt)->dependencyUid = ((BtlPacketTiming *)spritePacket)->uid;
            ((BtlPacketTiming *)pkt)->delay = 0x16;
            ((BtlPacketTiming *)pkt)->actionUid = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
        {
            u8 *pkt;
            pkt = btlActionCreateTargetPacketBytes((u8 *)action, 6, 0, 0, 0);
            ((BtlPacketTiming *)pkt)->delay = 0xC;
            ((BtlPacketTiming *)pkt)->actionUid = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
    }
    for (actionIndex = 0; actionIndex < count; actionIndex++) {
        escapingAction = collected[actionIndex];
        btlUnitGetSphereWorldCenter((BtlUnit *)escapingAction->unit, &sphereCenter);
        btlUnitGetAnchorPose((u8 *)escapingAction->unit, NULL, facing.values, NULL);
        RtQuatTransformVectors(&escapeOffset, &D_0060A100, 1, &facing.rotation);
        if (action->unit->genus == 0) {
            escapeOffset.x = escapeOffset.x * 500.0f;
            escapeOffset.y = escapeOffset.y * 500.0f;
            escapeOffset.z = escapeOffset.z * 500.0f;
            escapeDestination.x = sphereCenter.x + escapeOffset.x;
            escapeDestination.y = sphereCenter.y + escapeOffset.y;
            escapeDestination.z = sphereCenter.z + escapeOffset.z;
            movementPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)escapingAction->unit, &escapeDestination, 0.5f, 0);
        } else {
            if (((BtlEnemyBattleParameters *)(iGpffffb3cc + escapingAction->unit->charId * 0xE8))->cameraMode != 1) {
                escapeOffset.x = escapeOffset.x * 129.6f;
                escapeOffset.y = escapeOffset.y * 129.6f;
                escapeOffset.z = escapeOffset.z * 129.6f;
                escapeDestination.x = sphereCenter.x + escapeOffset.x;
                escapeDestination.y = sphereCenter.y + escapeOffset.y;
                escapeDestination.z = sphereCenter.z + escapeOffset.z;
            } else {
                escapeDestination = sphereCenter;
            }
            movementPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)escapingAction->unit, &escapeDestination, fGpffff8218, 4);
        }
        *movementPacket = 5;
        ((BtlPacketTiming *)movementPacket)->dependencyUid = ((BtlPacketTiming *)spritePacket)->uid;
        ((BtlPacketTiming *)movementPacket)->delay = 0x10;
        ((BtlPacketTiming *)movementPacket)->actionUid = action->uid;
        btlPacketEnqueue(movementPacket, 1);
        {
            u8 *pkt;
            pkt = btlUnitCreateColorPacket((u8 *)escapingAction->unit, 0xFFFFFF, 8, 0, 4, 0);
            *pkt = 5;
            ((BtlPacketTiming *)pkt)->dependencyUid = ((BtlPacketTiming *)movementPacket)->uid;
            ((BtlPacketTiming *)pkt)->delay = 0xC;
            ((BtlPacketTiming *)pkt)->actionUid = action->uid;
            btlPacketEnqueue(pkt, 1);
            lastPacketUid = ((BtlPacketTiming *)pkt)->uid;
        }
    }
    if (groupEscape != 0) {
        {
            u8 *pkt;
            pkt = (u8 *)btlCreateSetFlagsPacket(0x80);
            *pkt = 4;
            ((BtlPacketTiming *)pkt)->dependencyUid = lastPacketUid;
            *(pkt + 0x10) = 0xA;
            ((BtlPacketCondition *)pkt)[1].value.id = 0x801;
            ((BtlPacketTiming *)pkt)->actionUid = action->uid;
            btlPacketEnqueue(pkt, 1);
        }
        ((BtlBattleState *)iGpffffb3ac)->endState = 3;
    }
    {
        u8 *pkt;
        pkt = btlTargetCreateActionPacket((u8 *)action, 0);
        ((BtlPacketTiming *)pkt)->actionUid = action->uid;
        btlPacketEnqueue(pkt, 1);
    }
    btlActionSetState((BtlAction *)action, 0x20);
}

/* Measured: 644/656 bytes, 22 resolved relocations and 12 zero tail bytes.
 * Packet submissions retain callback-visible unit, UID and global reloads. */
#pragma push
/* measured: func_001adb80 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: func_001adb80 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_001ADB80
/* Release the prior linked model, select and initialize the new persona, and queue the change effects. */
/* Raw action/roster offsets access the state-specific persona selector and pending record absent from shared layouts. */
void btlActionPersonaInit(s64 *action)
{
    u16 person;
    u32 unit;
    s32 needsIntro;
    s32 actionFlags;
    u8 *introPacket;
    u8 *actionPacket;
    u8 *cameraPacket;
    u8 *animPacket;
    u8 *effectPacket;
    u8 *pendingRecord;
    u8 *resultPacket;
    u8 *followPacket;
    u8 *battleUnit;
    u8 *linkedUnit;

    actionFlags = ((BtlAction *)action)->unk_1a;
    if ((actionFlags & 1) == 0) {
        needsIntro = 0;
    } else {
        battleUnit = (u8 *)((BtlAction *)action)->unit;
        linkedUnit = (u8 *)((BtlUnit *)battleUnit)->childUnit;
        if ((actionFlags & 0x10) == 0) {
            needsIntro = 0;
        } else if (((s32)((BtlUnit *)linkedUnit)->flags2 & 2) != 0) {
            needsIntro = 1;
        } else {
            needsIntro = 0;
        }
    }
    if (needsIntro != 0) {
        introPacket = (u8 *)btlUnitCreateModelReleasePacket(
            ((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->childUnit);
        ((BtlPacket *)introPacket)->actionUID = *(s64 *)action;
        btlPacketEnqueue(introPacket, 1);
    }
    btlActionFinishPresentation((BtlAction *)action);
    actionPacket = btlPacketCreateSpriteTable(
        (u32)((BtlAction *)action)->unit,
        ((BtlAction *)action)->unk_6c);
    ((BtlPacket *)actionPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(actionPacket, 3);
    cameraPacket = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 0x1F);
    ((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(cameraPacket, 0);
    animPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)(u8 *)((BtlAction *)action)->unit,
                             0x19, 0, 1.0f, 0);
    ((BtlPacket *)animPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(animPacket, 0);
    effectPacket = func_001f99c0((u8 *)action, 0x15, 0, 0, 0);
    ((BtlPacket *)effectPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(effectPacket, 1);
    if (((BtlUnit *)((u8 *)((BtlAction *)action)->unit))->genus == 0) {
        datPersonaSelectRosterMemberById(((BtlAction *)action)->parameters.persona);
        person = ((BtlAction *)action)->parameters.persona;
        btlUnitInitChild((u8 *)((BtlAction *)action)->unit, person);
        datPersonaRemoveSelectedRosterMember();
        if (datGetFlag(0x3C) != 0) {
            pendingRecord = (u8*)((BtlAction *)action)->targetBlock.recovery.savedCursors;
            if (pendingRecord != NULL) {
                ((s16 (*)[2])pendingRecord)[1][1] = 0;
                ((s16 (*)[2])((BtlAction *)action)->targetBlock.recovery.savedCursors)[1][0] = 0;
            }
        }
    }
    unit = (u32)((BtlAction *)action)->unit;
    resultPacket = (u8 *)btlFormationCreatePacket(
        (s32)((BtlBattleState *)D_0076449C)->formations[14],
        unit, unit,
        0, 0);
    ((BtlPacketTiming *)resultPacket)->delay = 0xF;
    ((BtlPacket *)resultPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(resultPacket, 2);
    followPacket = (u8 *)btlSoundCreateChannelCuePacket(0xA, 2, 6);
    ((BtlPacketTiming *)followPacket)->dependencyKind = 5;
    ((BtlPacketTiming *)followPacket)->dependencyUid = ((BtlPacket *)resultPacket)->uid;
    ((BtlPacket *)followPacket)->actionUID = *(s64 *)action;
    btlPacketEnqueue(followPacket, 1);
    ((BtlBattleState *)D_0076449C)->flags |= 0x400000;
    ((BtlBattleState *)D_0076449C)->actionEndFlags |= 5;
}
#pragma pop


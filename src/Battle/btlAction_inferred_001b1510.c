#include "btl_action_internal.h"
#include "btl_effect_internal.h"
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

#include "rw_types_internal.h"
#include "btl_skill_internal.h"
#include "btl_target_state_packet_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "datPersona_internal.h"
#include "btl_unit_internal.h"
extern s32 datItemCount(s16 id);
typedef struct KwlnTask KwlnTask;
typedef struct BtlUnit BtlUnit;
typedef struct BtlPacket BtlPacket;
typedef struct DatUnitEc DatUnitEc;
typedef struct DatUnit DatUnit;
typedef struct BtlAction BtlAction;
extern void (*D_00887300[])();
extern void btlEncounterEntrySetRetracted(u8 *);
extern s32 btlEncountRollChance(u8 *);
extern s32 btlShuffleSelectMember(u8 *, s16, s32);
extern s32 datCalcGetBadStatus(s32);
extern void btlEncounterStart(u8 *);
extern s32 btlShuffleCreate(s32, u8 *);
extern void btlShuffleCancel(s32);
extern s32 datCalcGetLevel(s32);
extern s32 btlIsLeaderStandardUnit(u8 *);
extern void memset(void *dst, s32 value, s32 size);
extern s32 iGpffffb3ac;
extern u8 *iGpffffb3e0;
extern void btlMainLoadBattleFieldScene();
extern void btlUnitRecordCommitPending(void);
extern s32 fadeBeginReturnTransition(s32, s32);
extern s32 btlFormationAllocWork(s32);
extern BtlPacket *btlFormationCreateNamedPacket(u32, const char *, u16);
extern u8 *btlSoundCreateSkillSEPacket(s32, s32);
extern u8 *btlMainCreateColorLerpPacket(s32, s32, s32);
extern BtlPacket *btlMainCreateColorWorkPacket(s32 first, s32 second, s32 third, u32 frames, u16 mode);
extern u8 *btlMainCreateTintPacket(s32, s32);
extern void btlTargetClearResultBuffer(u8 *);
extern u8 *btlPacketCreateHpRatio(u8 *);
extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern u8 *btlCreateTimingPacket(s32);
extern u8 *btlMainCreateFadePacket(s32, s32);
extern u8 *btlMainCreateColorFadePacket(s32);
extern u16 datCalcGetHp(s32 unit);
extern u16 datCalcGetSp(s32 unit);
extern void btlMainSkillColorPairDefaults(u32, s32 *, s32 *);
extern s32 btlMainSkillColorDefault(s32);
extern s32 btlMainSkillTintDefault(s32);
extern void btlMainSkillColorPairDefaultsAlt(u32, s32 *, s32 *);
extern void btlFormationSetPlacement(s32);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *);
extern u32 kwlnTaskGetWork(s32);
extern s32 func_00459760(s32);
extern void sdkSndPlayCue(s32, s32);
extern void btlEncounterSetFinish(s32 task);
extern u32 datCalcIsDead(s32, s32);
extern u8 *btlUnitRecordFindByActionUID(u64, u64);
extern s32 btlSoundIsPlaybackActive(void);
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
extern void btlUnitGetAnchorPose(u8 *unit, u8 *position, f32 *rotation, f32 *direction);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *direction, u32 flags);
extern s64 btlPacketEnqueue(u8 *, u32);
extern void btlActionSetState(BtlAction *, u16);
extern void nmMesWindowStepCurrentRelease(void);
extern s32 nmMesWindowCurrentOpenState(void);
extern s32 nmMesWindowCurrentAnimFlag(void);
extern void nmMesWindowReleaseCurrent(void);
extern void nmMesWindowResetCurrent(void);

extern u8 *D_0076449C;
extern s32 func_0022bd20(void);
extern void btlEncounterInitGlobals(void);
extern s32 btlStatusWindowShowSlot4(u8 *);
extern u32 btlCountUnitRecords(void);
extern BtlPacket *btlTargetCreateTargetPacket(u32, u16, u32, u32, u32);
extern void btlUnitShowModel(u8 *);
extern void btlUnitHideModel(u8 *);
extern s32 btlCurrentUnitId(void);
extern void loadingSpinnerRequestHide(void);
extern void btlFadeStart(s32);
extern s32 btlStatusWindowShowSlot0(u8 *);
extern s32 btlBossIsAllowedAction(void);
extern s32 btlTaskSlotLinkedSlot4(void);
extern void sdkSndResetChannel(s32, s32);
extern void fadeBeginTransition(s32, s32);
extern void H_Fade_SetCustomColor(s32, s32, s32);
extern void btlMainUnloadFieldScene(void);
extern u8 D_005F7180[];
extern u8 D_005F7184[];
extern u8 D_005F7000[];

extern u8 D_005F6FE8[];
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void (*D_005F6E20[])(u8 *);
extern u32 datCalcRandomBelow(u32);
extern u32 datCalcChkBadStatus(s32, u32);
extern void btlBossCollectTargets(u8 *);
extern s32 datCalcUnitClass(u8 *);
extern void btlActionQueueSortByRank(s32);
extern void btlActionQueueRequeueLeadingEnemies(s32);
extern u32 iGpffffa0b8;
extern void fclMiscSetExternalWord(u32);
extern void btlMainSetupCameraAndEffects(void);
extern u32 datGetFlag(s32);
extern BtlPacket *btlVoiceCreateIdPacket(u16);
extern u8 *btlSoundCreateWaitPacket(void);
extern u8 *btlBossCreateLoadPakPacket(void);
extern s32 btlBossMapUnitIdToEntryId(void);
extern BtlPacket *btlBossCreateLoadEndBgmPacket(s32);
extern void loadingSpinnerRequestShow(void);
extern void hFadeSetCustomWhite(void);
s64 btlPacketEnqueue(u8 *, u32);
extern s32 btlShuffleIsIdle(s32 task);
extern void func_001eb7f0(void);
extern s32 func_001eb860(void);
extern s32 btlTaskSlotLinkedSlot0(void);
extern s32 btlStatusWindowShowSlot1(u8 *);
extern s32 btlTaskSlotLinkedSlot1(void);
extern void btlDamageSetSource(u8 *, s32);
BtlPacket *btlFormationCreateSlotPacket(u16, u16);
extern u8 nmMesWindowOpenCurrent(u8 *message);
void nmMesWindowShowCurrentRecord(u32);
void nmMesWindowSetCurrentFlag(u32);
void nmMesWindowSetCurrentParam(u32);
extern u8 D_005FB400[];
static inline u8 *func_001bf3a0_add(s32 offset, u8 *base)
{
    return (u8 *)(offset + (u32)base);
}
static inline f32 func_001ba790_mul(f32 left, f32 right)
{
    return left * right;
}
extern BtlPacket *btlFormationCreatePacket(u32, u32, u32, u16, u32);
extern u8 *btlPacketCreateImmediate(void);
extern BtlPacket *btlTargetCreateEmptyPacket(void);
extern void btlSoundStopBank3(void);
extern void btlDamageStartFlash(s32);
extern void btlEncounterSetReady(s32 task);
extern s32 btlEncounterIsIntroDone(s32 task);
extern u16 D_008C024C[];
extern u16 D_008C024E[];
extern s32 btlShuffleIsCanceled(s32 task);
extern s32 btlEncounterIsInactive(s32);
extern s32 btlShuffleIsBusy(s32 task);
extern s32 fadeStatus(void);
extern BtlPacket *btlUnitCreateColorPacket(BtlUnit *, u32, s16, s16, u8, u8);
extern void btlCameraSuppressEncounterCallback(void);
extern u8 *datUnitGetRecord(s16);
extern void btlPanelReset(s32);
extern void datCalcSetHp(s32, u16);
extern void datCalcSetSp(s32, u16);
extern u16 datCalcMaxHp(DatUnit *);
extern u16 datCalcMaxSp(DatUnit *);
extern s32 datCalcAddHp(DatUnit *, s32);
extern s32 datCalcAddSp(DatUnit *, s32);
extern s32 datCalcHasSkill(u8 *, s32);
extern u32 datCalcClearBadStatus(s32, u32);
extern void datCalcClearAllBuffs(u8 *);
extern u8 D_0060A0E0[];
extern f32 fGpffff82f8;
extern f32 fGpffff80c8;
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






extern u8 *btlActionFindByUnit(s32);
#pragma push
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_001b; members 001b1510-001b5e40 */

/* Fade-out's phase-specific word at +0xC is distinct from WIN's delay pair. */
typedef struct BtlMainFadeOutWork {
    s32 phase;
    s32 unk04;
    s32 frame;
    s32 finishRequested;
} BtlMainFadeOutWork;

/* The result task receives a finish request in its first word; its second
 * word remains nonzero while the result UI is running. */
typedef struct BtlResultWork {
    s32 flags;
    s32 running;
} BtlResultWork;

typedef struct BtlCameraColorReal {
    f32 red, green, blue, alpha;
} BtlCameraColorReal;
/* Convert packed color channels to the zero-to-one range. */
static inline void btlCameraNormalizeColor(BtlCameraColorReal *result, const u8 *bytes)
{
    result->red = (1.0f / 255.0f) * (f32)bytes[0];
    result->green = (1.0f / 255.0f) * (f32)bytes[1];
    result->blue = (1.0f / 255.0f) * (f32)bytes[2];
    result->alpha = (1.0f / 255.0f) * (f32)bytes[3];
}
/* Modulate all four normalized channels by the ambient color. */
static inline void btlCameraMultiplyColor(BtlCameraColorReal *result, const BtlCameraColorReal *base, const BtlCameraColorReal *ambient)
{
    result->red = base->red * ambient->red;
    result->green = base->green * ambient->green;
    result->blue = base->blue * ambient->blue;
    result->alpha = base->alpha * ambient->alpha;
}
/* Modulate packed 0xFF808080 by the ambient channels and round back to bytes. */
static inline s32 btlCameraBlendAmbient(f32 ambientRed, f32 ambientGreen,
                                       f32 ambientBlue, f32 ambientAlpha)
{
    union BtlCameraPackedColor { s32 word; u8 bytes[4]; } color;
    BtlCameraColorReal normalized;
    BtlCameraColorReal ambient;
    s32 redByte, greenByte, blueByte, alphaByte;
    color.word = (s32)0xFF808080U;
    btlCameraNormalizeColor(&normalized, color.bytes);
    ambient.red = ambientRed;
    ambient.green = ambientGreen;
    ambient.blue = ambientBlue;
    ambient.alpha = ambientAlpha;
    btlCameraMultiplyColor(&normalized, &normalized, &ambient);
    redByte = (s32)(normalized.red * 255.0f + 0.5f);
    color.bytes[0] = redByte;
    greenByte = (s32)(normalized.green * 255.0f + 0.5f);
    color.bytes[1] = greenByte;
    blueByte = (s32)(normalized.blue * 255.0f + 0.5f);
    color.bytes[2] = blueByte;
    alphaByte = (s32)(normalized.alpha * 255.0f + 0.5f);
    color.bytes[3] = alphaByte;
    return color.word;
}
struct RwV3d;
// FUN_001B1510
/* Use the first pending follow-up action, falling back to the front of the ordinary order queue. */
s32 btlActionGetActiveOrQueueFront(void)
{
    s32 *slot;
    u8 *battle;

    battle = D_0076449C;
    slot = (s32 *)(battle + 0x2CC);
    if (((BtlBattleState *)battle)->activeActions[0] == 0) {
        slot = (s32 *)(battle + 0x29C);
    }
    return *slot;
}

// FUN_001B1540
s32 btlActionGetQueueFront(void)
{
    return ((BtlBattleState *)iGpffffb3ac)->actionQueue[0];
}

// FUN_001B1550
s32 btlActionGetActive(void)
{
    return ((BtlBattleState *)iGpffffb3ac)->activeActions[0];
}

// FUN_001B1560
s32 btlActionGetQueueSecond(void)
{
    return ((BtlBattleState *)iGpffffb3ac)->actionQueue[1];
}

// FUN_001B1570
s32 btlActionGetQueueEntry(u16 index) {
    if (index >= 0xC) {
        return 0;
    }
    return ((s32 *)(D_0076449C + 0x29C))[index];
}

// FUN_001B15B0
/* Resume an idle follow-up or dispatch the queue front, applying pending side and boss reordering. */
void btlActionUpdateQueue(void)
{
    u16 queueFlags;
    u8 *unit;
    u8 *activeAction;
    u8 *countBattle;
    u8 *activeBattle;
    u8 *enemyOrderBattle;
    u8 *partyOrderBattle;
    u8 *bossOrderBattle;
    u8 *advanceBattle;
    u8 *dispatchedBattle;
    u8 *action;
    u8 *bossBattle;
    u8 *actionSlot;
    u8 *battle;

    battle = D_0076449C;
    queueFlags = ((BtlBattleState *)battle)->queueFlags;
    if ((queueFlags & 1) == 0) goto done;
    if ((*(s32 *)&((BtlBattleState *)battle)->flags & 0x80000) != 0) goto done;
    if ((queueFlags & 8) == 0) goto done;
    actionSlot = battle + 0x2CC;
    action = *(u8 **)actionSlot;
    if (action != NULL) {
        if (((BtlAction *)action)->currState != 1) goto done;
        ((BtlAction *)action)->flags |= 4;
        activeAction = *(u8 **)actionSlot;
        btlActionSetState((BtlAction *)activeAction, *(u16 *)&((BtlAction *)activeAction)->unk_16);
        countBattle = D_0076449C;
        ((BtlBattleState *)countBattle)->actionCount += 1;
        activeBattle = D_0076449C;
        ((BtlBattleState *)activeBattle)->queueFlags &= 0xFFF7;
        goto done;
    }
    actionSlot = D_0076449C + 0x29C;
    if (((BtlBattleState *)D_0076449C)->actionCount == 0) goto after_count;
    if ((queueFlags & 2) != 0) {
        action = *(u8 **)actionSlot;
        if (((BtlUnit *)*(u8 * *)&((BtlAction *)action)->unit)->genus == 1) {
            btlActionQueueSortByRank(1);
            btlActionQueueRequeueLeadingEnemies(1);
            enemyOrderBattle = D_0076449C;
            ((BtlBattleState *)enemyOrderBattle)->queueFlags &= 0xFFFD;
        }
    }
    if ((((BtlBattleState *)D_0076449C)->queueFlags & 4) != 0) {
        action = *(u8 **)actionSlot;
        if (((BtlUnit *)*(u8 * *)&((BtlAction *)action)->unit)->genus == 0) {
            btlActionQueueSortByRank(1);
            btlActionQueueRequeueLeadingEnemies(1);
            partyOrderBattle = D_0076449C;
            ((BtlBattleState *)partyOrderBattle)->queueFlags &= 0xFFFB;
        }
    }
    bossBattle = D_0076449C;
    if ((*(s32 *)&((BtlBattleState *)bossBattle)->flags & 0x200000) != 0 &&
        (((BtlBattleState *)bossBattle)->queueFlags & 0x10) != 0) {
        btlBossCollectTargets(0);
        bossOrderBattle = D_0076449C;
        ((BtlBattleState *)bossOrderBattle)->queueFlags &= 0xFFEF;
    }
after_count:
    action = *(u8 **)actionSlot;
    if (action == NULL) goto done;
    if (((BtlAction *)action)->currState != 1) goto done;
    unit = *(u8 * *)&((BtlAction *)action)->unit;
    if (((BtlUnit *)unit)->genus == 0) {
        if ((s16)datCalcUnitClass(*(u8 * *)&((BtlUnit *)unit)->datUnit) == 4) {
            *(s16 *)&((BtlAction *)*(u8 **)actionSlot)->state = 5;
        } else {
            *(s16 *)&((BtlAction *)*(u8 **)actionSlot)->state = 8;
        }
    } else {
        *(s16 *)&((BtlAction *)*(u8 **)actionSlot)->state = 8;
    }
    btlActionSetState((BtlAction *)*(u8 **)actionSlot, 2);
    advanceBattle = D_0076449C;
    ((BtlBattleState *)advanceBattle)->queueFlags &= 0xFFF7;
    dispatchedBattle = D_0076449C;
    ((BtlBattleState *)dispatchedBattle)->actionCount += 1;
done:
    ;
}

// FUN_001B1800
/* Request an advance and enable action-queue processing. */
void btlActionEnableQueue(void)
{
    u8 *advanceBattle;
    u8 *enableBattle;

    advanceBattle = D_0076449C;
    ((BtlBattleState *)advanceBattle)->queueFlags |= 8;
    enableBattle = D_0076449C;
    ((BtlBattleState *)enableBattle)->queueFlags |= 1;
}

// FUN_001B1830
void btlActionDisableQueue(void) {
    ((BtlBattleState *)D_0076449C)->queueFlags &= 0xFFFE;
}

// FUN_001B1850
/* Clear the complete queue-control block and both twelve-slot action arrays. */
void btlActionResetQueueState(void)
{
    memset(D_0076449C + 0x290, 0, 0x6C);
}

// FUN_001B1880
/* Clear active follow-ups and queue flags without discarding the ordinary order queue. */
void btlActionResetActiveState(void)
{
    ((BtlBattleState *)D_0076449C)->queueFlags = 0;
    ((BtlBattleState *)D_0076449C)->unk298 = 0;
    memset(D_0076449C + 0x2CC, 0, 0x30);
}

// FUN_001B18C0
void btlMainNonInit(void)
{
}

// FUN_001B18D0
s32 btlMainNonUpdate(void)
{
    return 0;
}

// FUN_001B18E0
/* Fade battle sound channels and increment the persistent battle counter. */
void btlMainInitInit(void) {
    btlSoundFadeChannel(2, 0);
    btlSoundFadeChannel(3, 0);
    btlSoundFadeOutBgm(0);
    datSetScriptValue(0x78, datGetScriptValue(0x78) + 1);
}

// FUN_001B1940
/* Select the next encounter descriptor and initialize encounter globals when required. */
s32 btlMainInitUpdate(void) {
    /* Typed encounter indexing changed codegen (100B trial); C84 is the four-byte encounter-pointer array. */
    u8 *b = D_0076449C;
    s32 off = ((BtlBattleState *)b)->encounterIndex << 2;

    ((BtlBattleState *)b)->encounterRecord = *(s32 *)(off + (s32)b + 0xC84);
    b = D_0076449C;
    ((BtlBattleState *)b)->encounterIndex = ((BtlBattleState *)b)->encounterIndex + 1;
    if (func_0022bd20() != 0) {
        btlEncounterInitGlobals();
    }
    return 3;
}

// FUN_001B19A0
void btlMainSceneSetInit(void)
{
    btlMainLoadBattleFieldScene();
}

/* measured: opt_rebuildconditionals off for func_001b19c0 branch-fed scalar. */
/* measured: btlMainSceneSetUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_001B19C0
/* Wait for field loading and outstanding packets, then queue voice and optional boss resources. */
s32 btlMainSceneSetUpdate(void)
{
    extern s32 btlMainStepFieldSceneLoad(void);
    extern u32 btlCountUnitRecords(void);
    extern void fclMiscSetExternalWord(u32);
    extern void btlMainSetupCameraAndEffects(void);
    extern u32 datGetFlag(s32);
    extern BtlPacket *btlVoiceCreateIdPacket(u16);
    extern s64 btlPacketEnqueue(u8 *, u32);
    extern u8 *btlSoundCreateWaitPacket(void);
    extern s32 func_0022bd20(void);
    extern u8 *btlBossCreateLoadPakPacket(void);
    extern s32 btlBossMapUnitIdToEntryId(void);
    extern s32 btlCurrentUnitId(void);
    extern void loadingSpinnerRequestShow(void);
    extern void hFadeSetCustomWhite(void);
    s32 voiceId;
    s32 endBgmEntry;
    s32 encounterId;
    u8 *voicePacket;
    u8 *waitPacket;

    if (btlMainStepFieldSceneLoad() == 0) {
        goto done;
    }
    if (btlCountUnitRecords() != 0) {
        goto done;
    }
    fclMiscSetExternalWord(1);
    btlMainSetupCameraAndEffects();
    if (datGetFlag(0x38) == 0) {
        goto set_zero;
    }
    voiceId = 1;
    goto got_var;
set_zero:
    voiceId = 0;
got_var:
    voicePacket = (u8 *)btlVoiceCreateIdPacket((u16)(voiceId & 0xFFFF));
    btlPacketEnqueue(voicePacket, 1);
    waitPacket = btlSoundCreateWaitPacket();
    *(s8 *)&((BtlPacket *)waitPacket)->dependencyKind = 4;
    *(s64 *)&((BtlPacket *)waitPacket)->dependencyUID = *(s64 *)&((BtlPacket *)voicePacket)->uid;
    btlPacketEnqueue(waitPacket, 1);
    if (func_0022bd20() != 0) {
        btlPacketEnqueue(btlBossCreateLoadPakPacket(), 1);
        endBgmEntry = btlBossMapUnitIdToEntryId();
        if (endBgmEntry != -1) {
            btlPacketEnqueue((u8 *)btlBossCreateLoadEndBgmPacket(endBgmEntry), 1);
        }
    }
    encounterId = btlCurrentUnitId();
    switch (encounterId) {
    case 0x20B:
    case 0x215:
        loadingSpinnerRequestShow();
        hFadeSetCustomWhite();
        break;
    }
    return 5;
done:
    return 0;
}

/* measured: close opt_rebuildconditionals off for func_001b19c0. */
/* measured: btlMainWinInit MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals on
// FUN_001B1B20
void btlMainContinuousInit(void)
{
}

// FUN_001B1B30
/* Wait for enemy actions to finish before selecting and preparing the next encounter wave. */
s32 btlMainContinuousUpdate(void)
{
    /* Typed encounter indexing changed one instruction (564B trial); retain the C84 four-byte slot calculation. */
    extern u8 *btlTargetCreateTargetPacket(u8 *, s32, s32, s32, s32);
    extern void btlDamageSetSource(u8 *, s32);
    extern void btlSelectionClearTargetFlag(s32);
    extern void btlEncounterEntryClearRetracted(s32 task);
    extern void btlEncounterEntryClearEmphasis(s32 task);
    extern void func_001eb7f0(void);
    u8 *node;
    s32 state;
    u8 *unit;
    u8 *work;
    u8 *next;

    state = 1;
    node = ((BtlBattleState *)(u8 *)iGpffffb3ac)->actions;
    goto first_check;
first_body:
    if ((((BtlAction *)node)->unk_1a & 1) != 0) {
        unit = *(u8 * *)&((BtlAction *)node)->unit;
        if (((BtlUnit *)unit)->genus == 1) {
            state = 0;
        } else {
            btlActionSetState((BtlAction *)node, 1);
            ((BtlAction *)node)->flags &= 0x7FFF;
            ((BtlAction *)node)->flags &= 0xFFFB;
        }
    }
    node = *(u8 * *)&((BtlAction *)node)->next;
first_check:
    if (node != NULL) goto first_body;
    *(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags &= 0xFFFFFF7F;
    *(s32 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->flags &= 0xFFF7FFFF;
    if (state == 0) goto done;
    *(u16 *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->endState = 0;
    work = (u8 *)iGpffffb3ac;
    ((BtlBattleState *)work)->encounterRecord =
        *(s32 *)(((((BtlBattleState *)work)->encounterIndex << 2) + (s32)work) + 0xC84);
    work = (u8 *)iGpffffb3ac;
    ((BtlBattleState *)work)->encounterIndex = ((BtlBattleState *)work)->encounterIndex + 1;
    btlActionResetActiveState();
    work = (u8 *)iGpffffb3ac;
    *(s32 *)&((BtlBattleState *)work)->flags &= 0xFFFEFFFF;
    btlSelectionClearTargetFlag(((BtlBattleState *)(u8 *)iGpffffb3ac)->uiTask);
    btlPacketEnqueue(
        (u8 *)btlTargetCreateTargetPacket(((BtlBattleState *)(u8 *)iGpffffb3ac)->selectedAction,
                            0x1F, 0, 0, 0),
        1);
    next = ((BtlBattleState *)(u8 *)iGpffffb3ac)->actions;
    goto second_check;
second_body:
    if ((((BtlAction *)next)->unk_1a & 1) != 0) {
        unit = *(u8 * *)&((BtlAction *)next)->unit;
        if (((BtlUnit *)unit)->genus == 0 &&
            *(s32 *)&((BtlUnit *)unit)->datUnit != 0) {
            btlPacketEnqueue(btlTargetCreateActionPacket(next, 2), 1);
        }
    }
    next = *(u8 * *)&((BtlAction *)next)->next;
second_check:
    if (next != NULL) goto second_body;
    btlEncounterEntryClearEmphasis(((BtlBattleState *)(u8 *)iGpffffb3ac)->uiTask);
    btlEncounterEntryClearRetracted(((BtlBattleState *)(u8 *)iGpffffb3ac)->uiTask);
    if (func_001eb860() == 1) {
        work = (u8 *)iGpffffb3ac;
        *(s32 *)&((BtlBattleState *)work)->flags |= 0x2000;
        btlDamageSetSource(*(u8 * *)&((BtlBattleState *)(u8 *)iGpffffb3ac)->uiTask, 1);
        func_001eb7f0();
    }
    return 5;
done:
    return 0;
}

/* Round-3 reconstruction: retain the u16 model ID, table-entry reloads,
 * switch dispatch and full-width status-roll locals.
 * See docs/probe_archive/BattleSetup_001b1d70_20260926_body.c and the
 * corrected model-ID contract survey, Prototype_mismatch_00477c40_00478140_20260926.md. */
// FUN_001B1D70
/* Create party/enemy actions, reuse loaded models, and select the initial side and queue order. */
void btlMainUnitCreateInit(void) {
    /* Typed action/unit/packet fields changed MWCC codegen (1576B trial); retain the proven byte offsets for MATCH. */
    extern s32 iGpffffb414;
    extern u8 *btlActionCreateWork(s32, u16, u16 *);
    extern u32 datCalcClearBadStatus(s32, u32);
    extern void *mdlFindModelObject(u32, u16, u32);
    extern u8 *btlUnitCreateModelLoadPacket(u8 *, u16, s16);
    extern void SceneDraw_SetDirectionalOnly(u16, u32);
    extern void btlUnitApplyModelState(u8 *, s32);
    extern void btlUnitSetRandomAnimFrame(u8 *);
    extern void mdlRunDataCallback(void *model);
    extern u8 *mdlGetClump(u8 *);
    extern void mdlClumpSetEnvMapState(u8 *);
    extern s32 btlUnitGetMoveStateCode(void);
    extern void btlActionQueueSortKeepingKind(s32);
    extern s32 btlActionQueueMoveToFront(s32);
    extern s32 datCalcStatusElement(s32, s32);
    extern s32 datCalcGetAffinity(u8 *, s32);
    extern u32 datCalcSetBadStatus(s32 unit, u32 badStatus);
    extern void btlCameraAssignFormationSlots(s32, s32);
    extern void btlUnitSetPos(u8 *, f32 *);
    u8 *dataOrModel;
    u8 *unit;
    u32 unitIndex;
    f32 position[3];
    s32 recordOrModel;
    u32 *entry;
    u8 *list;
    s64 previousLoadUID;
    s32 firstStatusElement;
    s32 secondStatusElement;
    u8 *enemyUnit;
    u32 i;
    u8 *actionOrPacket;
    u16 id;
    s32 modelFlags;

    previousLoadUID = 0;
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        i = 0;
        while (i < 4) {
            recordOrModel = *(s32 *)((u32)D_0076449C + i * 4 + 0xC74);
            if (recordOrModel == 0)
                break;
            dataOrModel = *(u8 **)(recordOrModel + 4);
            id = *(u16 *)(dataOrModel + 2);
            actionOrPacket = btlActionCreateWork(0, id, (u16 *)dataOrModel);
            unit = *(u8 **)(actionOrPacket + 0x30);
            datCalcClearBadStatus(*(s32 *)(unit + 0xA64), 0xFFF7FFFF);
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFDF;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFF7;
            *(u16 *)(*(u8 **)(unit + 0xA64)) &= 0xFFEF;
            recordOrModel = (s32)mdlFindModelObject((u16)(*(u8 *)(unit + 0xA2) + 1), id, 0);
            *(s32 *)(unit + 0xA00) = recordOrModel;
            if (recordOrModel == 0) {
                actionOrPacket = btlUnitCreateModelLoadPacket(unit, id, 0x36);
                *actionOrPacket = 4;
                *(s64 *)(actionOrPacket + 8) = previousLoadUID;
                btlPacketEnqueue(actionOrPacket, 1);
                previousLoadUID = *(s64 *)(actionOrPacket + 0x58);
            } else {
                modelFlags = *(s32 *)(unit + 0x98) | 2;
                *(s32 *)(unit + 0x98) = modelFlags;
                *(s32 *)(unit + 0x98) = modelFlags | 8;
                *(u16 *)(unit + 0x9FE) = MT_Scene_CreateModelCharRes(id, *(void **)(unit + 0xA00));
                SceneDraw_SetDirectionalOnly(*(u16 *)(unit + 0x9FE), 1);
                btlUnitApplyModelState(unit, 1);
                btlUnitUpdateStatusMotion(unit, 0);
                btlUnitSetMotion(unit, ((BtlUnit *)unit)->restMotion, 0, ((BtlUnit *)unit)->restRate, ((BtlUnit *)unit)->restOption);
                btlUnitSetRandomAnimFrame(unit);
                dataOrModel = *(u8 **)(unit + 0xA00);
                if (*(s32 *)(dataOrModel + 0x2D0) == 0) {
                    mdlRunDataCallback(dataOrModel);
                }
                btlUnitApplyModelState(unit, 4);
                btlUnitShowModel(unit);
                *(s32 *)(*(u8 **)(unit + 0xA00) + 0xD8) |= 0x400;
                mdlClumpSetEnvMapState(mdlGetClump(*(u8 **)(unit + 0xA00)));
            }
            i++;
        }
        *(u8 *)(D_0076449C + 0xC64) = (u8)i;
    }
    list = *(u8 **)(*(u8 **)(D_0076449C + 0xC68) + 4);
    unitIndex = 0;
    while (unitIndex < 6) {
        if (*(u16 *)(list + 2) != 0 && datCalcIsDead((s32)list, 0) == 0) {
            btlActionCreateWork(1, *(s16 *)(list + 2), (u16 *)list);
        }
        unitIndex++;
        list += 0x30;
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x100) != 0) {
        entry = (u32 *)((u8 *)iGpffffb414 + (u32)*(u16 *)(*(u8 **)(D_0076449C + 0xC68) + 8) * 0x18);
        if ((*entry & 0x20) != 0) {
            if ((*entry & 0x10) == 0) {
                *(u16 *)(D_0076449C + 0x1A) = 0;
            }
            btlBossCollectTargets((u8 *)0);
        } else {
            *(u16 *)(D_0076449C + 0x1A) = btlUnitGetMoveStateCode();
            switch (*(u16 *)(D_0076449C + 0x1A)) {
            case 0:
                btlActionQueueSortByRank(1);
                btlActionQueueRequeueLeadingEnemies(1);
                if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) != 0) {
                    btlActionQueueMoveToFront(*(s32 *)(D_0076449C + 0x170));
                }
                break;
            case 1:
                btlActionQueueSortByRank(0);
                btlActionQueueSortKeepingKind(0);
                btlActionQueueMoveToFront(*(s32 *)(D_0076449C + 0x170));
                *(u16 *)(D_0076449C + 0x290) |= 2;
                if ((*entry & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
                break;
            case 2:
                btlActionQueueSortByRank(0);
                btlActionQueueSortKeepingKind(1);
                btlActionQueueRequeueLeadingEnemies(1);
                *(u16 *)(D_0076449C + 0x290) |= 4;
                if ((*entry & 0x200) == 0) {
                    *(u32 *)(D_0076449C + 0xC) |= 0x100000;
                }
                break;
            }
        }
        if (((*(u16 *)(D_0076449C + 0xC70) & 8) != 0) && ((*entry & 0x100) == 0) &&
            ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0)) {
            firstStatusElement = (s16)datCalcStatusElement(-1, 4);
            secondStatusElement = (s16)datCalcStatusElement(-1, 2);
            for (enemyUnit = *(u8 **)(D_0076449C + 0x180); enemyUnit != NULL; enemyUnit = *(u8 **)(enemyUnit + 0xA6C)) {
                if (*(u8 **)(enemyUnit + 0xA64) != NULL) {
                    if ((datCalcGetAffinity(*(u8 **)(enemyUnit + 0xA64), secondStatusElement) & 0x27000000) == 0 && (s32)datCalcRandomBelow(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(enemyUnit + 0xA64), 2);
                    }
                    if ((datCalcGetAffinity(*(u8 **)(enemyUnit + 0xA64), firstStatusElement) & 0x27000000) == 0 && (s32)datCalcRandomBelow(100) < 0) {
                        datCalcSetBadStatus(*(s32 *)(enemyUnit + 0xA64), 4);
                    }
                }
            }
        }
    }
    if ((*(u32 *)(D_0076449C + 0xC) & 0x20000000) == 0) {
        btlCameraAssignFormationSlots(1, 0);
        return;
    }
    btlCameraAssignFormationSlots(0, 0);
    position[1] = 0.0f;
    for (enemyUnit = *(u8 **)(D_0076449C + 0x180); enemyUnit != NULL; enemyUnit = *(u8 **)(enemyUnit + 0xA6C)) {
        position[0] = (f32)(*(s16 *)(enemyUnit + 0x94) * 0x19 - 0x6D6);
        position[2] = (f32)(*(s16 *)(enemyUnit + 0x96) * 0x19 - 0x6D6);
        btlUnitSetPos(enemyUnit, position);
    }
}

/* Opening positions use complete vectors and a quaternion: the formation and
 * sphere-center providers write all components. The two list rows are eight
 * bytes apart and are reloaded between passes. Packets wait on full 64-bit UIDs.
 * Retail keeps the redundant actor comparison at 001b2aa0. The unreachable
 * inner block is retained as source rather than changing the surrounding test. */
/* measured: scoped opt_lifetimes on with these disjoint work-pointer
 * lifetimes reproduces the complete 4156-byte retail body; all 122 owner
 * siblings, allocated data and 122 exact-position references are preserved.
 * The separate retained-height caller-domain proof remains required. */
#pragma push
/* measured: btlMainUnitCreateUpdate MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
// FUN_001B2380
s32 btlMainUnitCreateUpdate(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (4184B trial); retain the proven byte offsets for MATCH. */
    extern void btlSoundPlayRetailSelectTrack(void);
    extern void btlShuffleStart(s32 task);
    extern s32 iGpffffb414;
    extern s32 btlActionGetQueueFront(void);
    extern void btlUnitGetGridSphereCenter(BtlUnit *unit, RwV3d *dst);
    extern f32 btlUnitGetGroupBounds(u32 groupFlags, u32 excludedFlags, RwV3d *outCenter, f32 *outTop, f32 *outBottom, u32 options);
    extern void btlTargetAddRadiusNode(u8 *, u8 *);
    extern void btlTargetBlendVectors(u8 *rotation, u8 *from, u8 *to);
    extern void btlUnitSetRot(BtlUnit *unit, const RtQuat *rotation);
    extern void btlUnitSetPos(BtlUnit *unit, const RwV3d *position);
    extern BtlPacket *btlUnitCreateModelFramePacket(BtlUnit *unit, s16 value);
    extern BtlPacket *btlUnitCreateMotionRequestPacket(BtlUnit *unit, u16 value);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const RwV3d *targetPos, f32 speed, u32 flags);
    extern BtlPacket *btlUnitCreateRotateTowardUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u32 flags);
    extern void btlFadeStartImmediate(void);
    extern u32 datCalcSetBadStatus(s32 unit, u32 badStatus);
    extern u32 datCalcIsLowHp(s32 unit);
        extern void datCalcApplyBuffMask(u8 *, s32, s64);
    extern f32 RwV3dNormalize(RwV3d *out, const RwV3d *in);
    extern f32 fGpffff8128;
    extern f32 fGpffff8170;
    extern f32 fGpffff82cc;
    /* ENCOUNT rows are 0x18 bytes: flags, two halfword result fields,
     * five enemy IDs and three remaining halfwords. No local copy is made. */
    typedef struct BattleOpeningEncounter {
        u32 flags;
        u16 field04;
        u16 field06;
        u16 enemyIds[5];
        u16 field12[3];
    } BattleOpeningEncounter;
    u8 *action;
    u32 hasSkill213;
    u32 hasSkill214;
    u32 hasSkill215;
    s16 unitClassOrFrames;
    u16 mode;
    /* Rotation finishes before packet construction. This work pointer is
     * reassigned before every later actor/packet use; unit independently
     * traverses the party placement and both bonus scans. */
    u8 *nodeOrPacket;
    u16 animationFrames;
    u8 *movePacket;
    u8 *rotatePacket;
    u8 *recoveryPacket;
    s32 hasSkill;
    u32 group;
    u8 *unit;
    u32 nextState;
    s32 value;
    BattleOpeningEncounter *formation;
    f32 spacingIncrement;
    f32 scale;
    f32 approachDistance;
    f32 distance;
    RtQuat rotation;
    RwV3d position;
    RwV3d targetDirection;
    RwV3d groupCenter;
    RwV3d actorCenter;
    RwV3d offset;

    if (btlCountUnitRecords() == 0) {
      /* Valid special continuations have a fresh, nonempty enemy row from
       * the authenticated normal encounter queue. That prepass supplies Y
       * before a dead party unit reuses it. Script/direct descriptors have
       * one wave: their normal dead-unit path never reads this position,
       * and their live-unit path receives a complete formation vector.
       * The separate resource/history review proves this caller boundary;
       * arbitrary fabricated special/empty-row states are outside it. */
      btlSoundPlayRetailSelectTrack();
      formation = (BattleOpeningEncounter *)((u32)iGpffffb414 + (u32)*(u16 *)(*(s32 *)(D_0076449C + 0xc68) + 8) * 0x18);
      action = (u8 *)btlActionGetQueueFront();
      if ((((action == 0) || (*(u8 *)(*(s32 *)(action + 0x30) + 0xa2) == 1)) ||
          (value = datCalcIsDead(*(u32 *)(*(s32 *)(action + 0x30) + 0xa64),0), value == 1)) ||
         (value = datCalcChkBadStatus(*(u32 *)(*(s32 *)(action + 0x30) + 0xa64),0x100000), value == 1
         )) {
        action = *(u8 **)(D_0076449C + 0x170);
      }
      btlUnitGetGridSphereCenter((BtlUnit *)*(void **)(action + 0x30), &groupCenter);
      for (group = 0; (s32)(group & 0xffff) < 2; group = (group + 1) & 0xffff) {
        if (((*(u32 *)(D_0076449C + 0xc) & 0x20000000) == 0) || ((group & 0xffff) != 0)) {
          for (nodeOrPacket = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178); nodeOrPacket != NULL;
              nodeOrPacket = *(u8 **)(nodeOrPacket + 0xa6c)) {
            btlTargetAddRadiusNode(nodeOrPacket,NULL);
            if ((group & 0xffff) == 0) {
              btlUnitGetAnchorPose(nodeOrPacket,NULL,(f32 *)&rotation,NULL);
            }
            else {
              position.x = (f32)(*(s16 *)(nodeOrPacket + 0x94) * 0x19 - 0x6d6);
              position.y = *(f32 *)(nodeOrPacket + 8);
              position.z = (f32)(*(s16 *)(nodeOrPacket + 0x96) * 0x19 - 0x6d6);
              btlTargetBlendVectors((u8 *)&rotation,(u8 *)&position,(u8 *)&groupCenter);
            }
            btlUnitSetRot((BtlUnit *)nodeOrPacket, &rotation);
          }
        }
      }
      btlUnitGetGroupBounds(2,0,&groupCenter,NULL,NULL,1);
      spacingIncrement = 0.0f;
      for (unit = *(u8 **)(D_0076449C + 0x178); unit != NULL;
          unit = *(u8 **)(unit + 0xa6c)) {
        btlUnitShowModel(unit);
        value = datCalcIsDead(*(u32 *)(unit + 0xa64),0);
        if (value != 0) {
          datCalcSetBadStatus(*(s32 *)(unit + 0xa64),0x80000);
          datCalcSetHp(*(u32 *)(unit + 0xa64),0);
          *(u32 *)(unit + 0x9c) |= 1;
          btlUnitUpdateStatusMotion(unit,0);
          btlPacketEnqueue((u8 *)btlSoundCreateUnitFlagSetPacket((BtlUnit *)unit),1);
          btlPacketEnqueue((u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x13, 0, 1.0f, 2),1);
          btlPacketEnqueue((u8 *)btlUnitCreateModelFramePacket((BtlUnit *)unit,
              btlUnitMotionModelFrames(unit,0x13,1.0f)),1);
          btlPacketEnqueue((u8 *)btlSoundCreateUnitFlagClearPacket((BtlUnit *)unit),1);
          if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) != 0) {
            position.x = (f32)(*(s16 *)(unit + 0x94) * 0x19 - 0x6d6);
            position.z = (f32)(*(s16 *)(unit + 0x96) * 0x19 - 0x6d6);
            btlUnitSetPos((BtlUnit *)unit, &position);
          }
        } else {
          btlUnitGetAnchorPose(unit,(u8 *)&position,NULL,(f32 *)&targetDirection);
          btlUnitGetGroupBounds(2,0,&groupCenter,NULL,NULL,1);
          if ((*(u32 *)(D_0076449C + 0xc) & 0x20000000) == 0) {
            mode = *(u16 *)(D_0076449C + 0x1a);
            switch (mode) {
            case 2:
            {
              if ((formation->flags & 0x200) != 0) goto normal_opening;
              if (*(u8 **)(*(s32 *)(D_0076449C + 0x170) + 0x30) != unit) {
                offset.x = groupCenter.x - position.x;
                offset.z = groupCenter.z - position.z;
                offset.y = 0.0f;
                approachDistance = fGpffff8170 * RwV3dNormalize(&offset,&offset);
                if (approachDistance <= 150.0f) {
                  btlUnitSetPos((BtlUnit *)unit, &position);
                }
                else {
                  if (!(approachDistance <= 300.0f)) {
                    approachDistance = 300.0f;
                  }
                  offset.x = offset.x * approachDistance;
                  offset.y = offset.y * approachDistance;
                  offset.z = offset.z * approachDistance;
                  offset.x = offset.x + position.x;
                  offset.y = offset.y + position.y;
                  offset.z = offset.z + position.z;
                  offset.y = position.y;
                  btlUnitSetPos((BtlUnit *)unit, &offset);
                }
                btlPacketEnqueue((u8 *)btlUnitCreateRotateTowardUnitPacket((BtlUnit *)unit, (BtlUnit *)*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30), 2),1);
              } else {
                offset.x = position.x - groupCenter.x;
                offset.z = position.z - groupCenter.z;
                offset.y = 0.0f;
                RwV3dNormalize(&offset,&offset);
                offset.x = offset.x * 300.0f;
                offset.y = offset.y * 300.0f;
                offset.z = offset.z * 300.0f;
                offset.x = offset.x + position.x;
                offset.y = offset.y + position.y;
                offset.z = offset.z + position.z;
                offset.y = position.y;
                btlUnitSetPos((BtlUnit *)unit, &offset);
              }
              animationFrames = btlUnitMotionModelFrames(unit,0xb,1.0f);
              nodeOrPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0xb, 0, 1.0f, 0);
              if (animationFrames > 8) {
                value = animationFrames - 8;
              } else {
                value = 0;
              }
              *(s16 *)(nodeOrPacket + 0x4a) = value;
              btlPacketEnqueue(nodeOrPacket,1);
              movePacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)unit, &position, fGpffff82cc, 8);
              *movePacket = 4;
              *(u64 *)(movePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
              btlPacketEnqueue(movePacket,1);
              rotatePacket = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &targetDirection, 0);
              *rotatePacket = 4;
              *(u64 *)(rotatePacket + 8) = *(u64 *)(movePacket + 0x58);
              btlPacketEnqueue(rotatePacket,1);
            }
            goto unit_done;
            case 0:
            case 1:
              goto normal_opening;
            default:
              goto unit_done;
            }
normal_opening:
            {
              if ((D_0076449C[0xc64] != 1) && ((*(u32 *)(D_0076449C + 0x10) & 1) == 0)) {
                nodeOrPacket = *(u8 **)(action + 0x30);
                if (nodeOrPacket == unit) {
                  distance = 500.0f;
                  if (nodeOrPacket != unit) {
                    btlUnitGetGridSphereCenter((BtlUnit *)nodeOrPacket, &actorCenter);
                    offset.x = groupCenter.x - actorCenter.x;
                    offset.y = groupCenter.y - actorCenter.y;
                    offset.z = groupCenter.z - actorCenter.z;
                    scale = fGpffff8128 * RwV3dNormalize(&offset,&offset);
                    offset.x = offset.x * scale;
                    offset.y = offset.y * scale;
                    offset.z = offset.z * scale;
                    groupCenter.x = actorCenter.x + offset.x;
                    groupCenter.y = actorCenter.y + offset.y;
                    groupCenter.z = actorCenter.z + offset.z;
                    spacingIncrement = spacingIncrement + 75.0f;
                    distance = distance + spacingIncrement;
                  }
                  groupCenter.y = position.y;
                  offset.x = position.x - groupCenter.x;
                  offset.y = position.y - position.y;
                  offset.z = position.z - groupCenter.z;
                  RwV3dNormalize(&offset,&offset);
                  offset.x = offset.x * distance;
                  offset.y = offset.y * distance;
                  offset.z = offset.z * distance;
                  offset.x = offset.x + position.x;
                  offset.y = offset.y + position.y;
                  offset.z = offset.z + position.z;
                  btlUnitSetPos((BtlUnit *)unit, &offset);
                }
                else {
                  btlUnitGetGridSphereCenter((BtlUnit *)nodeOrPacket, &groupCenter);
                  groupCenter.y = position.y;
                  offset.x = groupCenter.x - position.x;
                  offset.y = position.y - position.y;
                  offset.z = groupCenter.z - position.z;
                  distance = (f32)RwV3dNormalize(&offset,&offset);
                  if (!(distance <= 600.0f)) {
                    offset.x = offset.x * 500.0f;
                    offset.y = offset.y * 500.0f;
                    offset.z = offset.z * 500.0f;
                  }
                  else {
                    distance = distance - 100.0f;
                    offset.x = offset.x * distance;
                    offset.y = offset.y * distance;
                    offset.z = offset.z * distance;
                  }
                  offset.x = offset.x + position.x;
                  offset.y = offset.y + position.y;
                  offset.z = offset.z + position.z;
                  btlUnitSetPos((BtlUnit *)unit, &offset);
                }
                nodeOrPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)unit, &position, fGpffff82cc, 8);
                btlPacketEnqueue(nodeOrPacket,1);
                rotatePacket = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &targetDirection, 0);
                *rotatePacket = 4;
                *(u64 *)(rotatePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
                btlPacketEnqueue(rotatePacket,1);
                value = datCalcChkBadStatus(*(u32 *)(unit + 0xa64),0xfffff);
                if (((value == 0) &&
                    (value = datCalcIsLowHp(*(s32 *)(unit + 0xa64)), value == 0)) &&
                   ((*(u8 **)(action + 0x30) != unit ||
                    (unitClassOrFrames = datCalcUnitClass(*(u8 **)(unit + 0xa64)), unitClassOrFrames == 4)))) {
                  recoveryPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x11, 4, 1.0f, 0);
                  *recoveryPacket = 4;
                  *(u64 *)(recoveryPacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
                  *(u16 *)(recoveryPacket + 0x48) = 4;
                  btlPacketEnqueue(recoveryPacket,1);
                }
              }
            }
          }
          else {
            value = datCalcChkBadStatus(*(u32 *)(unit + 0xa64),0x180001);
            if (value != 0) {
              btlTargetBlendVectors((u8 *)&rotation,(u8 *)&position,(u8 *)&groupCenter);
              btlPacketEnqueue(btlUnitCreateOverridePacket(unit,(u8 *)&position,(u8 *)&rotation,0),0);
              btlPacketEnqueue((u8 *)btlUnitCreateMotionRequestPacket((BtlUnit *)unit, 0),0);
            } else {
              offset.x = position.x - groupCenter.x;
              offset.z = position.z - groupCenter.z;
              offset.y = 0.0f;
              RwV3dNormalize(&offset,&offset);
              offset.x = offset.x * 100.0f;
              offset.y = offset.y * 100.0f;
              offset.z = offset.z * 100.0f;
              offset.x = offset.x + groupCenter.x;
              offset.y = offset.y + groupCenter.y;
              offset.z = offset.z + groupCenter.z;
              offset.y = position.y;
              btlTargetBlendVectors((u8 *)&rotation,(u8 *)&offset,(u8 *)&position);
              btlPacketEnqueue(btlUnitCreateOverridePacket(unit,(u8 *)&offset,(u8 *)&rotation,0),0);
              nodeOrPacket = (u8 *)btlUnitCreateMovePacket((BtlUnit *)unit, &position, fGpffff82cc, 8);
              btlPacketEnqueue(nodeOrPacket,0);
              rotatePacket = (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, &targetDirection, 0);
              *rotatePacket = 4;
              *(u64 *)(rotatePacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
              btlPacketEnqueue(rotatePacket,1);
              value = datCalcChkBadStatus(*(u32 *)(unit + 0xa64),0xfffff);
              if (((value == 0) &&
                  (value = datCalcIsLowHp(*(s32 *)(unit + 0xa64)), value == 0)) &&
                 ((*(u8 **)(action + 0x30) != unit ||
                  (unitClassOrFrames = datCalcUnitClass(*(u8 **)(unit + 0xa64)), unitClassOrFrames == 4)))) {
                recoveryPacket = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)unit, 0x11, 4, 1.0f, 0);
                *recoveryPacket = 4;
                *(u64 *)(recoveryPacket + 8) = *(u64 *)(nodeOrPacket + 0x58);
                *(u16 *)(recoveryPacket + 0x48) = 4;
                btlPacketEnqueue(recoveryPacket,1);
              }
            }
          }
        }
unit_done:
        ;
      }
      for (group = 0; (s32)(group & 0xffff) < 2; group = (group + 1) & 0xffff) {
        hasSkill213 = 0;
        hasSkill214 = 0;
        hasSkill215 = 0;
        for (unit = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178); unit != 0;
            unit = *(u8 **)(unit + 0xa6c)) {
          if (*(u8 **)(unit + 0xa64) != NULL) {
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x213);
            if (hasSkill != 0) {
              hasSkill213 = 1;
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x214);
            if (hasSkill != 0) {
              hasSkill214 = 1;
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x215);
            if (hasSkill != 0) {
              hasSkill215 = 1;
            }
          }
        }
        for (unit = *(u8 **)(D_0076449C + (u16)group * 8 + 0x178); unit != 0;
            unit = *(u8 **)(unit + 0xa6c)) {
          if (*(u8 **)(unit + 0xa64) != NULL) {
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x202);
            if (((hasSkill != 0) || (datCalcCountSlotsWithValue(*(u8 **)(unit + 0xa64),0x53) != 0)
                ) || (hasSkill214 == 1)) {
              datCalcApplyBuffMask(*(u8 **)(unit + 0xa64),5,1);
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x203);
            if (((hasSkill != 0) || (datCalcCountSlotsWithValue(*(u8 **)(unit + 0xa64),0x54) != 0)
                ) || (hasSkill213 == 1)) {
              datCalcApplyBuffMask(*(u8 **)(unit + 0xa64),0x40,1);
            }
            hasSkill = datCalcHasSkill(*(u8 **)(unit + 0xa64),0x204);
            if (((hasSkill != 0) || (datCalcCountSlotsWithValue(*(u8 **)(unit + 0xa64),0x55) != 0)
                ) || (hasSkill215 == 1)) {
              datCalcApplyBuffMask(*(u8 **)(unit + 0xa64),0x110,1);
            }
            **(u16 **)(unit + 0xa64) = **(u16 **)(unit + 0xa64) & 0xf3ff;
          }
        }
      }
      if ((formation->field04 != 0) && (formation->field06 > 0)) {
        *(s16 *)(D_0076449C + 0xcd0) = formation->field04;
        *(u16 *)(D_0076449C + 0xcd2) = formation->field06;
        *(u32 *)(D_0076449C + 0xcdc) = 1;
      }
      btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 2),0);
      if ((*(u32 *)(D_0076449C + 0xc) & 0x100000) != 0) {
        btlShuffleStart(*(s32 *)(D_0076449C + 0xdd4));
        *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) & 0xffefffff;
      }
      if ((*(u32 *)(D_0076449C + 0x10) & 1) == 0) {
        value = btlCurrentUnitId();
        switch (value) {
        case 0x20b:
        case 0x215:
          loadingSpinnerRequestHide();
          break;
        }
        btlFadeStartImmediate();
        value = func_001eb860();
        if (value == 1) {
          *(u32 *)(D_0076449C + 0xc) = *(u32 *)(D_0076449C + 0xc) | 0x2000;
          btlDamageSetSource(*(u8 **)(D_0076449C + 0xdd4),1);
        }
        else {
          u8 *battle = D_0076449C;
          *(u32 *)(battle + 0xc) = *(u32 *)(battle + 0xc) & 0xffffdfff;
          func_001eb7f0();
        }
      }
      nextState = 6;
    }
    else {
      nextState = 0;
    }
    return nextState;
}

#pragma pop
/* 744/752 bytes; twenty resolved relocations; eight zero alignment bytes.
 * Keep full-width dependency snapshots and branch-materialized final mode. */
#pragma push
/* measured: btlMainUnitLoadInit MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// FUN_001B33C0
/* Chain enemy model loads and entry effects, followed by panel and voice playback packets. */
void btlMainUnitLoadInit(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (748B trial); retain the proven byte offsets for MATCH. */
    extern u8 *btlUnitCreateModelLoadPacket(u8 *, u16, s16);
    extern u8 *btlEffectCreateFormationPacket(s32, s32, s32, s64, s32);
    extern u8 *btlEffectCreateLoadPacket(void);
    extern u8 *func_00202b60(s32);
    extern u8 *btlSoundCreateLoadPlaybackPacket(s32);
    extern s32 iGpffffb450;
    s32 groupMode;
    s32 first;
    u8 *unitPacket;
    u8 *motionPacket;
    s64 previousUnitUID;
    s64 previousMotionUID;
    u8 *unit;
    u8 *cursor;
    u16 unitCount;
    u8 *followupPacket;
    u8 *simplePacket;
    u8 *effectPacket;
    u8 *panelPacket;
    u8 *finishPacket;
    s32 flags;
    s32 finishMode;
    s16 motionMode;

    first = 1;
    previousUnitUID = 0;
    previousMotionUID = 0;
    unitCount = 0;
    unit = *(u8 **)(D_0076449C + 0x180);
    cursor = unit;
    while (cursor != NULL) {
        unitCount++;
        cursor = *(u8 **)(cursor + 0xA6C);
    }
    groupMode = (unitCount < 4) + 1;
    while (unit != NULL) {
        unitPacket = btlUnitCreateModelLoadPacket(unit, *(u16 *)(unit + 0xA4), 0x3E);
        *(s8 *)(unitPacket + 0) = 4;
        *(s64 *)(unitPacket + 8) = previousUnitUID;
        btlPacketEnqueue(unitPacket, 1);
        previousUnitUID = *(s64 *)(unitPacket + 0x58);
        if (!(*(s32 *)(D_0076449C + 0x10) & 1)) {
            motionPacket = btlEffectCreateFormationPacket(iGpffffb450, (s32)unit, 0, 0, 0);
            motionMode = 4;
            *(s8 *)(motionPacket + 0) = 4;
            *(s64 *)(motionPacket + 8) = *(s64 *)(unitPacket + 0x58);
            if (first == 1) {
                *(s16 *)(motionPacket + 0x48) = 1;
            } else {
                *(s8 *)(motionPacket + 0x10) = 5;
                *(s64 *)(motionPacket + 0x18) = previousMotionUID;
                if (groupMode) {
                    motionMode = 8;
                }
                *(s16 *)(motionPacket + 0x48) = motionMode;
            }
            btlPacketEnqueue(motionPacket, 2);
            previousMotionUID = *(s64 *)(motionPacket + 0x58);
            followupPacket = (u8 *)btlUnitCreateColorPacket((BtlUnit *)unit, 0xFFFFFFFF, 0xC, 0, 3, 1);
            *(s8 *)(followupPacket + 0) = 4;
            *(s64 *)(followupPacket + 8) = *(s64 *)(unitPacket + 0x58);
            *(s8 *)(followupPacket + 0x10) = 5;
            *(s64 *)(followupPacket + 0x18) = previousMotionUID;
            *(s16 *)(followupPacket + 0x48) = 0x1D;
            btlPacketEnqueue(followupPacket, 1);
        } else {
            simplePacket = (u8 *)btlUnitCreateColorPacket((BtlUnit *)unit, 0xFFFFFFFF, 0, 0, 3, 1);
            *(s8 *)(simplePacket + 0) = 4;
            *(s64 *)(simplePacket + 8) = *(s64 *)(unitPacket + 0x58);
            *(s16 *)(simplePacket + 0x48) = 2;
            btlPacketEnqueue(simplePacket, 1);
            previousMotionUID = *(s64 *)(simplePacket + 0x58);
        }
        first = 0;
        unit = *(u8 **)(unit + 0xA6C);
    }
    flags = *(s32 *)(D_0076449C + 0xC);
    if (!(flags & 0x20000000)) {
        effectPacket = btlEffectCreateLoadPacket();
        *(s8 *)(effectPacket + 0) = 4;
        *(s64 *)(effectPacket + 8) = previousUnitUID;
        btlPacketEnqueue(effectPacket, 1);
        panelPacket = func_00202b60(*(s32 *)(D_0076449C + 0xDD4));
        *(s8 *)(panelPacket + 0) = 4;
        *(s64 *)(panelPacket + 8) = *(s64 *)(effectPacket + 0x58);
        btlPacketEnqueue(panelPacket, 1);
        if (datGetFlag(0x38) != 0) {
            finishMode = 1;
        } else {
            finishMode = 0;
        }
        finishPacket = btlSoundCreateLoadPlaybackPacket((u16)finishMode);
        *(s8 *)(finishPacket + 0) = 4;
        *(s64 *)(finishPacket + 8) = *(s64 *)(panelPacket + 0x58);
        btlPacketEnqueue(finishPacket, 1);
    }
}

#pragma pop
// FUN_001B36B0
/* Wait for loads and shuffle setup, then apply enemy visibility and enter the start phase. */
s32 btlMainUnitLoadUpdate(void)
{
    s32 flags;
    u8 *battle;
    u8 *unit;

    if (btlCountUnitRecords() == 0) {
        battle = D_0076449C;
        flags = *(s32 *)&((BtlBattleState *)battle)->flags;
        if ((flags & 0x100000) == 0) {
            if ((flags & 0x20000000) == 0) {
                btlPacketEnqueue((u8 *)btlTargetCreateTargetPacket((u32)((BtlBattleState *)battle)->selectedAction, 0, 0, 0, 0), 1);
            }
            unit = ((BtlBattleState *)D_0076449C)->unitLists[2];
            goto check;
loop:
            if ((*(s32 *)&((BtlUnit *)unit)->flags3 & 8) != 0) {
                btlUnitShowModel(unit);
            } else {
                btlUnitHideModel(unit);
            }
            unit = *(u8 * *)&((BtlUnit *)unit)->nextUnit;
check:
            if (unit != NULL) {
                goto loop;
            }
            return 7;
        }
    }
    return 0;
}

// FUN_001B3790
/* Begin the battle fade and temporarily hold party motions for supported boss openings. */
void btlMainStartInit(void)
{
    s32 encounterId;
    u8 *unit;

    if ((*(s32 *)&((BtlBattleState *)D_0076449C)->battleFlags & 1) == 0) {
        goto done;
    }
    encounterId = btlCurrentUnitId();
    switch (encounterId) {
    case 0x20B:
    case 0x215:
        loadingSpinnerRequestHide();
        break;
    default:
        break;
    }
    btlFadeStart(3);
    if (btlStatusWindowShowSlot0((u8 *)*(s32 *)&((BtlBattleState *)D_0076449C)->selectedAction) == 0) {
        goto done;
    }
    if (btlBossIsAllowedAction() == 0) {
        goto done;
    }
    unit = ((BtlBattleState *)D_0076449C)->unitLists[1];
    goto check;
loop:
    ((BtlUnit *)unit)->unk_9d8 = ((BtlUnit *)unit)->unk_9d8 | 0x40;
    btlUnitSetMotion(unit, 0, 0, 1.0f, 1);
    unit = *(u8 * *)&((BtlUnit *)unit)->prevUnit;
check:
    if (unit != NULL) {
        goto loop;
    }
done:
    return;
}

/* measured: narrowing func_00198920's integer parameter declaration to the
   retail s16/u16/s16 widths reorders the loop call's argument loads; object
   372 bytes in the 384-byte window, normalized_diff 0. */
// FUN_001B3870
/* Wait for opening UI work, restore party motion, and enable the action queue. */
s32 btlMainStartUpdate(void)
{
    u8 *damageBattle;
    u8 *readyBattle;
    u8 *quietBattle;
    u8 *unit;

    if (btlShuffleIsIdle(((BtlBattleState *)D_0076449C)->uiTask) != 1) goto done;
    if (btlCountUnitRecords() != 0) goto done;
    if (btlTaskSlotLinkedSlot0() != 0) goto done;
    if (btlTaskSlotLinkedSlot1() != 0) goto done;
    if (btlStatusWindowShowSlot1(((BtlBattleState *)D_0076449C)->selectedAction) != 0) {
        return 0;
    }
    if (btlBossIsAllowedAction() != 0) {
        unit = ((BtlBattleState *)D_0076449C)->unitLists[1];
        goto check;
loop:
        ((BtlUnit *)unit)->unk_9d8 &= 0xFFBF;
        btlUnitUpdateStatusMotion(unit, 0);
        btlUnitSetMotion(unit, ((BtlUnit *)unit)->restMotion, 8, ((BtlUnit *)unit)->restRate, ((BtlUnit *)unit)->restOption);
        unit = *(u8 * *)&((BtlUnit *)unit)->prevUnit;
check:
        if (unit != NULL) goto loop;
    }
    if (func_001eb860() == 1) {
        damageBattle = D_0076449C;
        *(s32 *)&((BtlBattleState *)damageBattle)->flags |= 0x2000;
        btlDamageSetSource(*(u8 * *)&((BtlBattleState *)D_0076449C)->uiTask, 1);
    } else {
        quietBattle = D_0076449C;
        *(s32 *)&((BtlBattleState *)quietBattle)->flags &= ~0x2000;
        func_001eb7f0();
    }
    btlActionEnableQueue();
    readyBattle = D_0076449C;
    *(s32 *)&((BtlBattleState *)readyBattle)->flags |= 0x800;
    return 8;
done:
    return 0;
}

// FUN_001B39F0
void btlMainActionInit(void)
{
}

/* 1268/1280 bytes (retail ends in three words of padding); relocations:
   iGpffffb3ac / D_0076449C (the same battle-work pointer under both of this
   file's names), iGpffffb414, iGpffffb410 and the called functions.
   Levers: the state switch falls from the 1/3 body into case 2 so the final
   test reuses `state`; the "slot occupied" read goes through D_0076449C,
   which is what makes retail reload the pointer there; the two unit loops
   use separate cursors; the rank is taken before the CE0 load; the s32 at
   0xCE4 is passed straight to the s16 parameter; the declaration order
   pick/unit/alive/total/hurt gives retail's saved-register colouring. */
// FUN_001B3A00
/* Handle battle-end state, collect result data and select revival, victory or defeat processing. */
s32 btlMainActionUpdate(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (1284B trial); retain the proven byte offsets for MATCH. */
    extern s32 iGpffffb414;
    extern s32 iGpffffb410;
    u16 state;
    u8 *pick;
    u8 *unit;
    u16 alive;
    u16 total;
    s32 hurt;
    u8 *member;
    s32 status;
    s16 diff;
    s16 rank;

    if ((*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x80) != 0) {
        btlActionDisableQueue();
        btlEncounterEntrySetRetracted(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4));
        btlDamageSetSource(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4), 0);
        state = *(u16 *)((u8 *)iGpffffb3ac + 0x1C);
        switch (state) {
        case 1:
        case 3:
            if (state == 3) {
                memset((u8 *)iGpffffb3ac + 0xCAC, 0, 0x58);
                *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xDFFFFFFF;
            } else {
                u16 id = *(u16 *)((u8 *)iGpffffb3ac + 0xC6C);

                if (id < 3 && ((s32 *)(D_0076449C + 0xC84))[id] != 0) {
                    *(s32 *)((u8 *)iGpffffb3ac + 0xC) |= 0x20000000;
                    return 11;
                }
                *(s32 *)((u8 *)iGpffffb3ac + 0xC) &= 0xDFFFFFFF;
            }
            pick = (u8 *)btlActionGetActiveOrQueueFront();
            hurt = 0;
            if (pick != NULL) {
                switch (*(u16 *)(pick + 0x6E)) {
                case 0x100:
                case 0x101:
                case 0x102:
                    *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 2;
                    hurt = 1;
                    break;
                }
            }
            total = 0;
            alive = 0;
            for (unit = *(u8 **)((u8 *)iGpffffb3ac + 0x17C); unit != NULL; unit = *(u8 **)(unit + 0xA68)) {
                if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0) {
                    total++;
                } else {
                    *(u16 *)((u8 *)iGpffffb3ac + alive * 2 + 0xCBE) = *(u16 *)(*(u8 **)(unit + 0xA64) + 2);
                    alive++;
                    total++;
                }
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xCCC) = total;
            *(s32 *)((u8 *)iGpffffb3ac + 0xCC8) = alive;
            *(s32 *)((u8 *)iGpffffb3ac + 0xCE8) = *(u16 *)((u8 *)iGpffffb3ac + 0xC5A);
            if (*(u16 *)((u8 *)iGpffffb3ac + 0xC5A) > 0) {
                *(s32 *)((u8 *)iGpffffb3ac + 0xCE4) /= *(u16 *)((u8 *)iGpffffb3ac + 0xC5A);
            }
            if (*(u16 *)((u8 *)iGpffffb3ac + 0x1C) != 3 && btlEncountRollChance(pick) != 0 &&
                btlShuffleSelectMember((u8 *)iGpffffb3ac + 0xCEC, *(s32 *)((u8 *)iGpffffb3ac + 0xCE4), hurt) != 0) {
                *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 1;
            }
            if (func_0022bd20() != 0) {
                *(u16 *)((u8 *)iGpffffb3ac + 0xCAC) |= 8;
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xCB8) = btlCurrentUnitId();
            if (*(s32 *)((u8 *)iGpffffb414 + btlCurrentUnitId() * 0x18) & 0x2000) {
                rank = datCalcGetLevel(*(s32 *)(*(u8 **)(*(u8 **)((u8 *)iGpffffb3ac + 0x170) + 0x30) + 0xA64)) & 0xFF;
                diff = *(s16 *)((u8 *)iGpffffb3ac + 0xCE0) - rank;
                if (diff < 0) {
                    diff = 0;
                } else if (diff > 5) {
                    diff = 5;
                }
                *(u16 *)((u8 *)iGpffffb3ac + 0xCBC) = *(u8 *)((u8 *)iGpffffb410 + diff);
            }
            for (member = *(u8 **)((u8 *)iGpffffb3ac + 0x17C); member != NULL; member = *(u8 **)(member + 0xA68)) {
                if (*(s32 *)(member + 0xA64) != 0) {
                    status = datCalcGetBadStatus(*(s32 *)(member + 0xA64));
                    datCalcClearBadStatus(*(s32 *)(member + 0xA64), 0xFFF7FFFF);
                    if ((status & 0x100000) == 0) {
                        btlUnitUpdateStatusMotion(member, 6);
                    }
                }
            }
            if ((*(u16 *)((u8 *)iGpffffb3ac + 0xCAC) & 1) != 0 &&
                (*(s32 *)((u8 *)iGpffffb3ac + 0xC) & 0x20000000) == 0) {
                btlEncounterStart(*(u8 **)((u8 *)iGpffffb3ac + 0xDD4));
            }
            *(s32 *)((u8 *)iGpffffb3ac + 0xDD0) =
                btlShuffleCreate(*(s32 *)((u8 *)iGpffffb3ac + 0xDC8), (u8 *)iGpffffb3ac + 0xCAC);
            btlShuffleCancel(*(s32 *)((u8 *)iGpffffb3ac + 0xDD0));
            state = *(u16 *)((u8 *)iGpffffb3ac + 0x1C);
            if (state == 1) {
                return (*(s32 *)((u8 *)iGpffffb3ac + 0x10) & 2) ? 12 : 11;
            }
            /* fallthrough */
        case 2:
            if (state == 2) {
                if (*(s32 *)((u8 *)iGpffffb3ac + 0x10) & 0x20000000) {
                    return 12;
                }
                return btlIsLeaderStandardUnit((u8 *)iGpffffb3ac) ? 9 : 13;
            }
            return 14;
        }
    }
    return 0;
}

// FUN_001B3F00
/* Open the revival prompt and queue its formation and camera setup. */
void btlMainRevivalMesInit(void) {
    s64 *p = *(s64 * *)&((BtlBattleState *)D_0076449C)->selectedAction;
    u8 *t;

    nmMesWindowOpenCurrent((u8 *)(&D_005F7000));
    nmMesWindowShowCurrentRecord(1);
    nmMesWindowSetCurrentFlag(0);
    nmMesWindowSetCurrentParam(0);
    t = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)&((BtlPacket *)t)->actionUID = *p;
    btlPacketEnqueue(t, 0);
    btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)(NULL), (u16)(0x2B)), 0);
}

// FUN_001B3FB0
/* Wait for the revival prompt and select revival or resumed action processing. */
s32 btlMainRevivalMesUpdate(void)
{
    nmMesWindowStepCurrentRelease();
    if (nmMesWindowCurrentOpenState() == 0) {
        if (nmMesWindowCurrentAnimFlag() == 0) {
            btlEncounterEntryClearRetracted(((BtlBattleState *)iGpffffb3ac)->uiTask);
            nmMesWindowReleaseCurrent();
            nmMesWindowResetCurrent();
            return 10;
        }
        *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags &= 0xFF7FFFFF;
        nmMesWindowReleaseCurrent();
        nmMesWindowResetCurrent();
        return 8;
    }
    return 0;
}

/* measured: MATCH. Each follow-up packet chains to the +0x58 of the packet
   it follows (the SE packet, the per-unit formation packet, the result
   packet), not to its own. Short-lived packets use `next` so they never
   take a saved register; locals are declared in retail's $s7..$s0 order. */
// FUN_001B4060
/* Queue the party revival formation, HP/SP restoration and dependent camera/display sequence. */
void btlMainRevivalInit(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (1508B trial); retain the proven byte offsets for MATCH. */
    union {
        u8 bytes[0x20];
        s32 words[8];
    } result;
    char formation[0x80];
    s32 camA;
    s32 camB;
    u16 maxSp;
    u8 *sePacket;
    u8 *unitAction;
    u8 *unit;
    s64 last;
    s32 form;
    u8 *packet;
    u8 *action;
    u8 *next;
    u8 *camera;
    u16 maxHp;
    s32 id;
    u32 target;

    action = *(u8 **)(iGpffffb3ac + 0x170);
    last = 0;
    form = btlFormationAllocWork(0);
    btlFormationFormatName(0x13D, formation);
    packet = (u8 *)btlFormationCreateNamedPacket(form, formation, 0);
    *(s64 *)(packet + 0x60) = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    sePacket = btlSoundCreateSkillSEPacket(0x13D, 0);
    *sePacket = 4;
    *(s64 *)(sePacket + 8) = *(s64 *)(packet + 0x58);
    *(s64 *)(sePacket + 0x60) = *(s64 *)action;
    btlPacketEnqueue(sePacket, 1);
    btlMainSkillColorPairDefaults(0x13D, &camA, &camB);
    next = btlMainCreateColorLerpPacket(camA, camB, 0x10);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    id = btlMainSkillColorDefault(0x13D);
    btlMainSkillColorPairDefaultsAlt(0x13D, &camA, &camB);
    next = (u8 *)btlMainCreateColorWorkPacket(id, camA, camB, 0x10, 0);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateTintPacket(btlMainSkillTintDefault(0x13D), 0x10);
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    target = *(u32 *)(action + 0x30);
    packet = (u8 *)btlFormationCreatePacket(form, target, target, 0, 0);
    *packet = 4;
    *(s64 *)(packet + 8) = *(s64 *)(sePacket + 0x58);
    *(s64 *)(packet + 0x60) = *(s64 *)action;
    btlPacketEnqueue(packet, 2);
    next = (u8 *)btlSoundCreateCueQueuePacket(0);
    *next = 5;
    *(s64 *)(next + 8) = *(s64 *)(packet + 0x58);
    btlPacketEnqueue(next, 1);
    for (unit = *(u8 **)(iGpffffb3ac + 0x178); unit != NULL; unit = *(u8 **)(unit + 0xA6C)) {
        unitAction = btlActionFindByUnit((s32)unit);
        btlTargetClearResultBuffer(result.bytes);
        maxHp = datCalcMaxHp(*(DatUnit **)(unit + 0xA64));
        maxSp = datCalcMaxSp(*(DatUnit **)(unit + 0xA64));
        result.words[0] = maxHp - datCalcGetHp(*(s32 *)(unit + 0xA64));
        result.words[1] = maxSp - datCalcGetSp(*(s32 *)(unit + 0xA64));
        if (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0) {
            result.words[3] = 0x80000;
        }
        next = btlPacketCreateHpRatio(unit);
        *(s64 *)(next + 0x60) = *(s64 *)action;
        btlPacketEnqueue(next, 1);
        packet = (u8 *)btlFormationCreatePacket(form, (u32)unit, (u32)unit, 1, 0);
        packet[0] = 4;
        *(s64 *)(packet + 8) = *(s64 *)(sePacket + 0x58);
        packet[0x10] = 4;
        *(s64 *)(packet + 0x18) = last;
        *(s64 *)(packet + 0x60) = *(s64 *)action;
        btlPacketEnqueue(packet, 2);
        next = (u8 *)btlSoundCreateCueQueuePacket(1);
        *next = 5;
        *(s64 *)(next + 8) = *(s64 *)(packet + 0x58);
        btlPacketEnqueue(next, 1);
        camera = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)(unitAction), (u16)(0x1B));
        camera[0] = 5;
        *(s64 *)(camera + 8) = *(s64 *)(packet + 0x58);
        camera[0x20] = 0xB;
        *(s64 *)(camera + 0x28) = *(s64 *)(packet + 0x58);
        *(s16 *)(camera + 0x4A) = 0x12;
        *(s64 *)(camera + 0x60) = *(s64 *)action;
        btlPacketEnqueue(camera, 0);
        last = *(s64 *)(camera + 0x58);
        if ((result.words[3] & 0x80000) != 0 && (*(s32 *)(unit + 0x9C) & 0x200) != 0) {
            next = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)(unit), (s16)(0x14), (u16)(0), 1.0f, (u16)(0));
            *next = 0xB;
            *(s64 *)(next + 8) = *(s64 *)(packet + 0x58);
            *(s64 *)(next + 0x60) = *(s64 *)action;
            btlPacketEnqueue(next, 1);
        }
        unitAction = (u8 *)btlTargetCreateDataPacket((s32)unitAction, (s32)unitAction, result.bytes, 1, 1);
        *unitAction = 0xB;
        *(s64 *)(unitAction + 8) = *(s64 *)(packet + 0x58);
        *(s64 *)(unitAction + 0x60) = *(s64 *)action;
        btlPacketEnqueue(unitAction, 1);
        if (result.words[0] != 0) {
            next = btlPacketCreateUnitCounter((s32)unit, 0, 0);
            *next = 4;
            *(s64 *)(next + 8) = *(s64 *)(unitAction + 0x58);
            next[0x47] &= 0xDF;
            btlPacketEnqueue(next, 3);
        }
        next = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, result.bytes, 0);
        *next = 4;
        *(s64 *)(next + 8) = *(s64 *)(unitAction + 0x58);
        next[0x47] &= 0xDF;
        btlPacketEnqueue(next, 3);
    }
    next = btlCreateTimingPacket(0x10);
    *next = 4;
    *(s64 *)(next + 8) = last;
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateFadePacket(0x10, 0);
    *next = 4;
    *(s64 *)(next + 8) = last;
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    next = btlMainCreateColorFadePacket(0x10);
    *next = 4;
    *(s64 *)(next + 8) = last;
    *(s64 *)(next + 0x60) = *(s64 *)action;
    btlPacketEnqueue(next, 1);
    btlFormationSetPlacement(form);
}

// FUN_001B4630
/* Wait for revival packets, consume the item and resume actions or retain the battle-end state. */
s32 btlMainRevivalUpdate(void)
{
    s64 *actionUID;
    u8 *endedBattle;
    u8 *resumedBattle;
    u8 *resultBattle;

    actionUID = (s64 *)(((BtlBattleState *)D_0076449C)->selectedAction);
    if (btlUnitRecordFindByActionUID(*actionUID, (s64)0x3FFFFFFFFFFFFFFF) == 0) {
        datItemSetCount(0x31E, ((datItemCount(0x31E) & 0xFF) - 1) & 0xFF);
        btlActionEnableQueue();
        if (btlCheckBattleEnd() == 0) {
            resumedBattle = D_0076449C;
            *(s32 *)&((BtlBattleState *)resumedBattle)->flags &= ~0x80;
            if (func_001eb860() == 1) {
                btlDamageSetSource(*(u8 * *)&((BtlBattleState *)D_0076449C)->uiTask, 1);
            }
            btlPacketEnqueue((u8 *)btlCameraCreateSetStatePacket((BtlAction *)(actionUID), (u16)(0x24)), 0);
        } else {
            endedBattle = D_0076449C;
            *(s32 *)&((BtlBattleState *)endedBattle)->flags |= 0x80;
            resultBattle = D_0076449C;
            *(s32 *)&((BtlBattleState *)resultBattle)->flags |= 0x80000;
        }
        return 8;
    }
    return 0;
}

// FUN_001B4760
/* Show the enemy-defeat status window and hold action processing during its callback. */
void btlMainEnemyDeadInit(void)
{
    btlStatusWindowShowSlot4((u8 *)*(s32 *)&((BtlBattleState *)D_0076449C)->selectedAction);
    *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x80000;
}

// FUN_001B47A0
/* Finish the enemy-defeat callback, restore sound/fade state and choose action or exit processing. */
s32 btlMainEnemyDeadUpdate(void)
{
    s32 nextState;
    u8 *battle;

    if (btlTaskSlotLinkedSlot4() == 0) {
        battle = D_0076449C;
        *(s32 *)&((BtlBattleState *)battle)->flags = *(s32 *)&((BtlBattleState *)battle)->flags & 0xFFF7FFFF;
        sdkSndResetChannel(2, 0);
        if ((*(s32 *)&((BtlBattleState *)D_0076449C)->flags & 0x400) == 0) {
            fadeBeginTransition(1, 0x1E);
            H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
        }
        if ((*(s32 *)&((BtlBattleState *)D_0076449C)->flags & 0x80) != 0) {
            nextState = 0xE;
        } else {
            nextState = 8;
        }
        return nextState;
    }
    return 0;
}

/* The phase index at iGpffffb3ac+0x2FC is the first word of the phase work.
 * Index 11 in D_005F7180 is the WIN phase (btlMainWinInit/btlMainWinUpdate). */
#define BTLMAIN_PHASE_WIN 0xB

// FUN_001B4860
s32 btlMainIsNotWinPhase(s32 *phase)
{
    return *phase != BTLMAIN_PHASE_WIN;
}

/* Complete packet and color phases preserve the live group dependency, all four
 * palette samples and the quaternion's W lane. The color helper follows the SDK
 * normalization, in-place channel product and byte-quantization operation graph.
 * measured b210 -O2: 2688 live bytes, frame0x90; all75 references resolved exactly.
 * The return delay instruction is included; there is no alignment tail.
 * See docs/Battle_camera_sequence_20261005.md for the finite source/native scope. */
// FUN_001B4880
void btlMainWinInit(u8 *phaseWork) {
    /* Typed action/unit/packet fields changed MWCC codegen (2704B trial); retain the proven byte offsets for MATCH. */
    extern void func_001eb7f0(void);
    extern void btlDamageSetSource(u8 *phaseWork, s32);
    extern void func_001eb3b0(u8 *phaseWork);
    extern u8 *btlUnitCreateResourceFreePacket(u8 *phaseWork);
    extern u8 *func_00194c90(void *phaseWork, void *);
    extern u8 *btlEffectCreateFormationPacket(s32 phaseWork, s32, s32, s64, s32);
    extern struct RtQuat *func_003dc740(struct RtQuat *rotation, const struct RwV3d *axis, f32 angle, s32 mode);
    extern s8 *kwlnGetColorBytes(void);
    extern BtlPacket *func_001f99c0(BtlAction *action, u16 voice, s32 option, s32 argument, s32 flags);
    extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *unit, const struct RwV3d *target, f32 speed, u32 flags);
    extern BtlPacket *btlUnitCreateHidePacket(BtlUnit *unit);
    extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrames, f32 speed, u16 mode);
    extern BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);
    extern u32 datCalcIsDead(s32 phaseWork, s32);
    extern f32 fGpffff82cc;
    extern f32 D_0060A110[];
    extern u8 D_0060A0E0[];
    u8 *livingUnit;
    u8 *base;
    u8 *unit;
    u8 *pkt;
    u8 *pkt3;
    u8 *palette;
    s32 livingCount;
    u16 animationFrames;
    s32 remainingAnimationFrames;
    s32 soundFrame;
    struct CameraRotation { BtlCameraSequenceRotation value; } __attribute__((aligned(16)));
    struct CameraRotation rotation;
    BtlCameraSequenceWork *work;
    f32 ambientRed;
    f32 ambientGreen;
    f32 ambientBlue;
    f32 ambientAlpha;
    s32 color;
    work = (BtlCameraSequenceWork *)phaseWork;
    base = (u8 *)btlActionGetActiveOrQueueFront();
    if ((base == 0) || (*(u8 *)(*(u8 **)(base + 0x30) + 0xA2) == 1)) {
        base = *(u8 **)(iGpffffb3ac + 0x170);
    }
    livingCount = 0;
    livingUnit = *(u8 **)(iGpffffb3ac + 0x17C);
    while (livingUnit != 0) {
        if (((*(u32 *)(livingUnit + 0x9C) & 8) != 0) && (datCalcIsDead(*(s32 *)(livingUnit + 0xA64), 0) == 0)) {
            livingCount = (livingCount + 1) & 0xFFFF;
        }
        livingUnit = *(u8 **)(livingUnit + 0xA68);
    }
    if (((livingCount & 0xFFFF) > 1) && ((*(u16 *)(iGpffffb3ac + 0xCAC) & 3) != 0)) {
        work->singleUnit = 0;
    } else {
        work->singleUnit = 1;
    }
    animationFrames = btlUnitMotionModelFrames(*(u8 **)(base + 0x30), 0x15, 1.0f);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        if (animationFrames > 0x28) {
            if (animationFrames > 8) {
                remainingAnimationFrames = animationFrames - 8;
            } else {
                remainingAnimationFrames = 0;
            }
            work->animationFrames = remainingAnimationFrames;
            if (animationFrames > 0x28) {
                soundFrame = animationFrames - 0x28;
            } else {
                soundFrame = 0;
            }
            work->soundFrame = soundFrame;
        } else {
            work->animationFrames = 0x28;
            work->soundFrame = 0;
        }
        work->duration = work->animationFrames;
    } else {
        func_001eb7f0();
        *(s32 *)(iGpffffb3ac + 0xC) = *(s32 *)(iGpffffb3ac + 0xC) & 0xFFFFDFFF;
        btlDamageSetSource(*(u8 **)(iGpffffb3ac + 0xDD4), 0);
        work->animationFrames = animationFrames;
        work->duration = 0x14;
    }
    work->delay = 0xC;
    work->interrupted = 0;
    func_001eb3b0(base + 0x38);
    *(u8 **) (base + 0x38) = base;
    *(u16 *)(base + 0x6A) = 1;
    {
        u8 *actionNode = *(u8 **)(iGpffffb3ac + 0x174);
        while (actionNode != 0) {
            if ((*(u16 *)(actionNode + 0x1A) & 1) != 0) {
                unit = *(u8 **)(actionNode + 0x30);
                if ((*(u8 *)(unit + 0xA2) == 1) && (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) != 0)) {
                    pkt = btlUnitCreateResourceFreePacket(*(u8 **)(actionNode + 0x30));
                    *(s64 *)(pkt + 0x60) = *(s64 *)base;
                    *(u16 *)(pkt + 0x48) = work->delay;
                    btlPacketEnqueue(pkt, 0);
                }
            }
            actionNode = *(u8 **)(actionNode + 0x450);
        }
    }
    pkt = (u8 *)btlUnitCreateAnimPacket(*(BtlUnit **)(base + 0x30), 0x15, 0, 1.0f, 2);
    *(u16 *)(pkt + 0x48) = work->delay;
    *(s64 *)(pkt + 0x60) = *(s64 *)base;
    btlPacketEnqueue(pkt, 0);
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        u8 *const callbackPacket = func_00194c90(btlMainIsNotWinPhase, phaseWork);
        btlPacketEnqueue(callbackPacket, 1);
        {
            u8 *const transitionPacket = btlEffectCreateFormationPacket(*(s32 *)(iGpffffb3ac + 0xDC0), *(s32 *)(base + 0x30), 0, *(s64 *)(callbackPacket + 0x58), 0x34100);
            s32 transitionDelay;
            if (work->delay > 2) {
                transitionDelay = work->delay - 2;
            } else {
                transitionDelay = 0;
            }
            *(s16 *)(transitionPacket + 0x48) = transitionDelay;
            *(s16 *)(transitionPacket + 0x4A) = 6;
            *(s64 *)(transitionPacket + 0x60) = *(s64 *)base;
            btlPacketEnqueue(transitionPacket, 2);
        }
        if (work->singleUnit == 1) {
            unit = *(u8 **)(base + 0x30);
            rotation.value = *(BtlCameraSequenceRotation *)(unit + 0x1C);
        } else {
            rotation = *(struct CameraRotation *)D_0060A110;
        }
        func_003dc740((struct RtQuat *)&rotation, (const struct RwV3d *)D_0060A0E0, 180.0f, 2);
        pkt = btlQuatMatrixPacketCreate((f32 *)&rotation, 0);
        *(s16 *)(pkt + 0x48) = work->delay + 1;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
        pkt = (u8 *)btlMainCreateColorWorkPacket((s32)0xFF808080U, (s32)0xFF88C3FFU, (s32)0xFFCFFCF6U, 0, 0);
        *(s16 *)(pkt + 0x48) = work->delay + 1;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
        palette = (u8 *)kwlnGetColorBytes();
        ambientRed = (1.0f / 255.0f) * (f32)palette[0];
        palette = (u8 *)kwlnGetColorBytes();
        ambientGreen = (1.0f / 255.0f) * (f32)palette[1];
        palette = (u8 *)kwlnGetColorBytes();
        ambientBlue = (1.0f / 255.0f) * (f32)palette[2];
        palette = (u8 *)kwlnGetColorBytes();
        ambientAlpha = (1.0f / 255.0f) * (f32)palette[3];
        color = btlCameraBlendAmbient(ambientRed, ambientGreen, ambientBlue, ambientAlpha);
        pkt = btlColorBlendPacketCreate(color, 0);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
    }
    if (work->singleUnit == 0) {
        u8 *const dependencyPacket = btlFormationCreateActionPacket(base);
        u8 *pkt2;
        u8 *node;
        *(u16 *)(dependencyPacket + 0x48) = work->delay;
        *(s64 *)(dependencyPacket + 0x60) = *(s64 *)base;
        btlPacketEnqueue(dependencyPacket, 0);
        if (((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) && ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0)) {
            pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0);
            *(u16 *)(pkt + 0x48) = work->delay;
            *(s64 *)(pkt + 0x60) = *(s64 *)base;
            btlPacketEnqueue(pkt, 1);
        }
        node = *(u8 **)(iGpffffb3ac + 0x17C);
        while (node != 0) {
            if ((*(u32 *)(node + 0x9C) & 8) != 0) {
                if (datCalcIsDead(*(s32 *)(node + 0xA64), 0) != 0) {
                    u8 *deadPacket = (u8 *)btlUnitCreateHidePacket((BtlUnit *)node);
                    *(u8 *)(deadPacket + 0) = 4;
                    *(s64 *)(deadPacket + 8) = *(s64 *)(dependencyPacket + 0x58);
                    *(s64 *)(deadPacket + 0x60) = *(s64 *)base;
                    btlPacketEnqueue(deadPacket, 0);
                } else if (*(u8 **)(base + 0x30) != node) {
                    pkt2 = (u8 *)btlUnitCreateMovePacket((BtlUnit *)node, NULL, fGpffff82cc, 0x18);
                    *(u8 *)(pkt2 + 0) = 4;
                    *(s64 *)(pkt2 + 8) = *(s64 *)(dependencyPacket + 0x58);
                    *(s64 *)(pkt2 + 0x60) = *(s64 *)base;
                    btlPacketEnqueue(pkt2, 0);
                    pkt3 = (u8 *)btlUnitCreateAnimPacket((BtlUnit *)node, 0x15, 0, 1.0f, 2);
                    *(u8 *)(pkt3 + 0) = 4;
                    *(s64 *)(pkt3 + 8) = *(s64 *)(pkt2 + 0x58);
                    *(s64 *)(pkt3 + 0x60) = *(s64 *)base;
                    btlPacketEnqueue(pkt3, 0);
                }
            }
            node = *(u8 **)(node + 0xA68);
        }
        pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)base, 0x26);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 0);
        return;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
        pkt = (u8 *)btlTargetCreateTargetPacket((u32)base, 0xF, 0, 0, 3);
        *(u16 *)(pkt + 0x48) = work->delay;
        btlPacketEnqueue(pkt, 1);
        pkt = (u8 *)func_001f99c0((BtlAction *)base, 4, 0, 0, 0);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 1);
    }
    {
        u8 *singleUnit = *(u8 **)(iGpffffb3ac + 0x17C);
        while (singleUnit != 0) {
            if (((*(u32 *)(singleUnit + 0x9C) & 8) != 0) && (*(u8 **)(base + 0x30) != singleUnit)) {
                pkt = (u8 *)btlUnitCreateHidePacket((BtlUnit *)singleUnit);
                *(u16 *)(pkt + 0x48) = work->delay;
                *(s64 *)(pkt + 0x60) = *(s64 *)base;
                btlPacketEnqueue(pkt, 0);
            }
            singleUnit = *(u8 **)(singleUnit + 0xA68);
        }
        pkt = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)base, 0x25);
        *(u16 *)(pkt + 0x48) = work->delay;
        *(s64 *)(pkt + 0x60) = *(s64 *)base;
        btlPacketEnqueue(pkt, 0);
    }
}

// FUN_001B5300
/* Wait for the victory sequence and optional shuffle intro, allowing the configured input skip. */
s32 btlMainWinUpdate(u8 *phaseWork)
{
    /* Typed action/unit/packet fields changed MWCC codegen (512B trial); retain the proven byte offsets for MATCH. */
    u8 *p;
    u16 limit;
    s32 hit;

    p = phaseWork;
    if ((*(s32 *)(p + 8) > (*(u16 *)(p + 0xC) + *(u16 *)(p + 0xE))) &&
        (*(s32 *)(p + 0x14) == 0) &&
        ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) &&
        ((D_008C024C[0] & 0x10) != 0 ||
         (D_008C024E[0] & 0x40) != 0)) {
        u8 *work;

        work = (u8 *)btlTargetCreateEmptyPacket();
        *(u16 *)(work + 0x4A) = 0xC;
        btlPacketEnqueue(work, 1);
        btlSoundStopBank3();
        *(s32 *)(p + 0x14) = 1;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0 &&
        (*(s32 *)(p + 8) == *(u16 *)(p + 0x12))) {
        btlDamageStartFlash(*(s32 *)(iGpffffb3ac + 0xDD4));
    }
    if ((*(u16 *)(iGpffffb3ac + 0xCAC) & 1) == 0) {
        goto after_cac;
    }
    limit = *(u16 *)(p + 0xC);
    hit = *(s32 *)(p + 8) < limit;
    if (hit != 0) {
        goto after_cac;
    }
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) != 0) {
        goto after_cac;
    }
    if (*(s32 *)(p + 8) == limit) {
        btlEncounterSetReady(*(s32 *)(iGpffffb3ac + 0xDD4));
        return 0;
    }
    if (btlEncounterIsIntroDone(*(s32 *)(iGpffffb3ac + 0xDD4)) == 0) {
        return 0;
    }
after_cac:
    if ((u32)btlCountUnitRecords() < 3) {
        if (*(s32 *)(p + 0x14) == 0) {
            hit = *(s32 *)(p + 8);
            hit = hit < (*(u16 *)(p + 0xC) + *(u16 *)(p + 0x10));
            if (hit != 0) {
                goto return_zero;
            }
        }
        if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x20000000) == 0) {
            return 0xE;
        }
        return 4;
    }
return_zero:
    return 0;
}

// FUN_001B54E0
/* Queue the protagonist defeat formation or immediate exit, then choose the encounter fade color. */
void btlMainLoseInit(void)
{
    u8 *p;
    u8 *work;

    p = *(u8 * *)&((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit;
    if ((datCalcIsDead(*(s32 *)&((BtlUnit *)p)->datUnit, 0) != 0) &&
        ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x20000000) == 0)) {
        work = (u8 *)btlFormationCreatePacket((u32)*(s32 *)&((BtlBattleState *)iGpffffb3ac)->formations[46], (u32)p, (u32)p, 1, 0);
        *(s64 *)&((BtlPacket *)work)->actionUID = *(s64 *)&((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->uid;
        ((BtlPacket *)work)->delay = 0xF;
        btlPacketEnqueue(work, 2);
        return;
    }
    work = btlPacketCreateImmediate();
    *(s64 *)&((BtlPacket *)work)->actionUID = *(s64 *)&((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->uid;
    ((BtlPacket *)work)->delay = 0x2A;
    btlPacketEnqueue(work, 1);
    fadeBeginTransition(1, 0x1E);
    switch (btlCurrentUnitId()) {
    case 0x214:
        H_Fade_SetCustomColor(0, 0, 0);
        break;
    default:
        H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
        break;
    }
}

// FUN_001B5620
/* Trigger the timed defeat fade, then wait for the action packets and sound playback to finish. */
s32 btlMainLoseUpdate(u8 *phaseWork)
{
    if ((((BtlCameraSequenceWork *)phaseWork)->frame == 0x6E) &&
        (datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8 * *)&((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unit)->datUnit, 0) != 0) &&
        ((*(s32 *)&((BtlBattleState *)D_0076449C)->battleFlags & 0x20000000) == 0)) {
        fadeBeginTransition(1, 1);
        H_Fade_SetCustomColor(0xFF, 0xFF, 0xFF);
    }
    if (btlUnitRecordFindByActionUID(*(s64 *)&((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->uid,
                     (s64)0x3FFFFFFFFFFFFFFF) != 0) {
        return 0;
    }
    if (btlSoundIsPlaybackActive() != 0) {
        return 0;
    }
    return 0xE;
}

// FUN_001B5710
/* Clear battle-ready state and signal result/shuffle completion when applicable. */
void btlMainFadeOutInit(u8 *phaseWork)
{
s32 flags;

    flags = *(s32 *)&((BtlBattleState *)D_0076449C)->flags;
    flags = flags & ~0x800;
    *(s32 *)&((BtlBattleState *)D_0076449C)->flags = flags;
    if (*(u16 *)&((BtlBattleState *)D_0076449C)->endState == 2) {
        goto done;
    }
    flags = *(s32 *)&((BtlBattleState *)D_0076449C)->flags;
    if ((flags & 0x400) == 0) {
        goto fallback;
    }
    if ((flags & 0x40) != 0) {
        if (func_00459760(flags) != 7) {
            sdkSndPlayCue(7, 1);
        }
    }
    ((BtlResultWork *)kwlnTaskGetWork(((BtlBattleState *)D_0076449C)->shuffleTask))->flags |= 1;
    ((BtlMainFadeOutWork *)phaseWork)->finishRequested = 0;
    goto done;
fallback:
    if ((((BtlBattleState *)D_0076449C)->resultFlags & 1) == 0) {
        goto done;
    }
    if ((flags & 0x20000000) != 0) {
        goto done;
    }
    btlEncounterSetFinish(((BtlBattleState *)D_0076449C)->uiTask);
done:
    return;
}

// FUN_001B57F0
/* Wait for shuffle, encounter UI and fade completion before entering final cleanup. */
s32 btlMainFadeOutUpdate(u8 *phaseWork)
{
    /* Typed phase-word access changed codegen (380B trial); +0xC is the signed finish-request word. */
    if (*(u16 *)&((BtlBattleState *)iGpffffb3ac)->endState == 2) {
        goto state_two;
    }
    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x400) == 0) {
        goto no_four_hundred;
    }
    if (*(s32 *)(phaseWork + 0xC) != 0) {
        goto check_status;
    }
    if (btlShuffleIsCanceled(((BtlBattleState *)iGpffffb3ac)->shuffleTask) != 0) {
        goto check_status;
    }
    if ((((BtlBattleState *)iGpffffb3ac)->resultFlags & 1) == 0) {
        goto set_status;
    }
    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x20000000) != 0) {
        goto set_status;
    }
    btlEncounterSetFinish(((BtlBattleState *)iGpffffb3ac)->uiTask);
set_status:
    *(s32 *)(phaseWork + 0xC) = 1;
check_status:
    if (*(s32 *)(phaseWork + 0xC) != 1) {
        goto return_zero;
    }
    if ((((BtlBattleState *)iGpffffb3ac)->resultFlags & 1) == 0) {
        goto status_fallback;
    }
    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x20000000) != 0) {
        goto status_fallback;
    }
    if (btlEncounterIsInactive(((BtlBattleState *)iGpffffb3ac)->uiTask) != 0) {
        goto status_fallback;
    }
    return 0;
status_fallback:
    if (btlShuffleIsBusy(((BtlBattleState *)iGpffffb3ac)->shuffleTask) != 0) {
        goto return_zero;
    }
    return 0xF;
no_four_hundred:
    if (fadeStatus() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two:
    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x20000000) == 0) {
        goto state_two_f;
    }
    if (fadeStatus() == 0) {
        goto return_zero;
    }
    return 0xF;
state_two_f:
    return 0xF;
return_zero:
    return 0;
}

/* 952/960 bytes; forty resolved relocations and eight zero alignment bytes.
 * Preserve full-restoration precedence and signed percentage arithmetic.
 * Reload the battle context, unit list and final task after cleanup callbacks. */
// FUN_001B5970
void btlMainEndInit(void)
{
    /* Typed action/unit/packet fields changed MWCC codegen (972B trial); retain the proven byte offsets for MATCH. */
    s32 restorePartySp;
    s32 restorePartyHp;
    s32 persona;
    s32 unitData;
    s32 uiTask;
    s32 personaId;
    u16 unitId;
    u8 *battle;
    u8 *buffUnit;
    u8 *action;
    u8 *unit;

    if (*(u16 *)(D_0076449C + 0x1C) == 1) {
        if (datGetFlag(0x38) != 0) personaId = 5; else personaId = 8;
        persona = (s32)datPersonaGetRecord(personaId & 0xFFFF);
        restorePartyHp = datPersonaFindSkillSlot((u8 *)persona, 0x10E) != -1;
        restorePartySp = datPersonaFindSkillSlot((u8 *)persona, 0x10F) != -1;
        unit = *(u8 **)(D_0076449C + 0x178);
        goto loop_16_check;
loop_16:
        if ((*(s32 *)(unit + 0xA64) != 0) &&
            (datCalcIsDead(*(s32 *)(unit + 0xA64), 0) == 0)) {
            if (datCalcHasSkill((u8 *)*(s32 *)(unit + 0xA64), 0x224) != 0) {
                datCalcSetHp(*(s32 *)(unit + 0xA64), datCalcMaxHp(*(DatUnit **)(unit + 0xA64)));
                datCalcSetSp(*(s32 *)(unit + 0xA64), datCalcMaxSp(*(DatUnit **)(unit + 0xA64)));
            } else if (datCalcHasSkill((u8 *)*(s32 *)(unit + 0xA64), 0x223) != 0) {
                datCalcAddHp((DatUnit *)*(s32 *)(unit + 0xA64), ((datCalcMaxHp(*(DatUnit **)(unit + 0xA64)) & 0xFFFF) * 100) / 1250);
                datCalcAddSp((DatUnit *)*(s32 *)(unit + 0xA64), ((datCalcMaxSp(*(DatUnit **)(unit + 0xA64)) & 0xFFFF) * 100) / 1250);
            }
            if (restorePartyHp != 0) datCalcAddHp((DatUnit *)*(s32 *)(unit + 0xA64), ((datCalcMaxHp(*(DatUnit **)(unit + 0xA64)) & 0xFFFF) * 100) / 2000);
            if (restorePartySp != 0) datCalcAddSp((DatUnit *)*(s32 *)(unit + 0xA64), ((datCalcMaxSp(*(DatUnit **)(unit + 0xA64)) & 0xFFFF) * 100) / 2000);
        }
        unit = *(u8 **)(unit + 0xA6C);
loop_16_check:
        if (unit != NULL) goto loop_16;
    }
    btlCameraSuppressEncounterCallback();
    btlPanelReset(*(s32 *)(D_0076449C + 0xDD4));
    buffUnit = *(u8 **)(D_0076449C + 0x178);
    goto loop_21_check;
loop_21:
    unitData = *(s32 *)(buffUnit + 0xA64);
    if (unitData != 0) datCalcClearAllBuffs((u8 *)unitData);
    buffUnit = *(u8 **)(buffUnit + 0xA6C);
loop_21_check:
    if (buffUnit != NULL) goto loop_21;
    if (datGetFlag(0x3D) == 0) {
        for (unitId = 1; unitId < 0xB; ++unitId)
            *(s8 *)(datUnitGetRecord(unitId) + 0x10) = 0;
    }
    action = *(u8 **)(D_0076449C + 0x174);
    goto loop_30_check;
loop_30:
    if (*(u16 *)(action + 0xC) != 0x24) btlActionSetState((BtlAction *)action, 0x24);
    action = *(u8 **)(action + 0x450);
loop_30_check:
    if (action != NULL) goto loop_30;
    btlUnitRecordCommitPending();
    battle = D_0076449C;
    if ((*(s32 *)(battle + 0x10) & 0x20000000) &&
        datCalcIsDead(*(s32 *)(*(u8 **)(((BtlBattleState *)battle)->selectedAction + 0x30) + 0xA64), 0) != 0) {
        datCalcSetHp(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 1);
        datCalcClearBadStatus(*(s32 *)(*(u8 **)(*(u8 **)(D_0076449C + 0x170) + 0x30) + 0xA64), 0x80000);
    }
    uiTask = *(s32 *)(D_0076449C + 0xDD4);
    if (uiTask != 0) {
        kwlnTaskDestroyWithHierarchy((KwlnTask *)uiTask);
        *(s32 *)(D_0076449C + 0xDD4) = 0;
    }
}

// FUN_001B5D30
/* Wait for all actions to be released, unload the field scene and select result or exit processing. */
s32 btlMainEndUpdate(void) {
    u8 *p;

    if (*(s32 *)&((BtlBattleState *)D_0076449C)->actions != 0) {
        return 0;
    }
    btlMainUnloadFieldScene();
    p = D_0076449C;
    if ((*(s32 *)&((BtlBattleState *)p)->flags & 0x400) != 0 &&
        *(u16 *)&((BtlBattleState *)p)->endState != 2) {
        return 0x10;
    }
    return 0x11;
}

// FUN_001B5DA0
void btlMainResultInit(void) {
}

// FUN_001B5DB0
/* Wait for the result task, release it, and restore the field fade when appropriate. */
s32 btlMainResultUpdate(void)
{
    u8 *battle;

    if (((BtlResultWork *)kwlnTaskGetWork(((BtlBattleState *)iGpffffb3ac)->shuffleTask))->running != 0) {
        return 0;
    }
    kwlnTaskDestroyWithHierarchy((KwlnTask *)((BtlBattleState *)iGpffffb3ac)->shuffleTask);
    ((BtlBattleState *)iGpffffb3ac)->shuffleTask = 0;
    battle = (u8 *)iGpffffb3ac;
    if ((*(u8 *)&((BtlBattleState *)battle)->isFieldEncounter == 1) &&
        (*(s32 *)&((BtlBattleState *)battle)->flags & 0x400)) {
        fadeBeginReturnTransition(1, 0xC);
    }
    return 0x11;
}

// FUN_001B5E40
void btlMainExitInit(void)
{
    btlUnitRecordCommitPending();
}


#include "member_access.h"
#include "btl_character_camera_internal.h"
#include "btl_effect_internal.h"
#include "list_item_internal.h"
#include "btl_skill_target_internal.h"
#include "btl_skill_internal.h"
#include "btl_packet_create_internal.h"
#include "btl_formation_internal.h"
#include "btl_motion_internal.h"
#include "effect_instance_internal.h"

#include "include_asm.h"
#include "type.h"
#include "btl_target_state_packet_internal.h"
#include "btl_action_internal.h"
typedef struct BtlPacket BtlPacket;
extern BtlPacket *btlFormationCreateNamedPacket(u32 resource, const char *path, u16 mode);
u32 datCalcRandomBelow(u32 limit);
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);
extern BtlPacket *btlUnitCreateAnimPacket(BtlUnit *unit, s16 id, u16 blendFrameCount, f32 speed, u16 mode);

extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument, u32 extraArgument, u32 flags);
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);
u8 *btlUnitRecordFindByActionUID(u64, u64);

void btlTargetResolveSelectedSkill(u8 *);
void btlTargetResetCommandRecord(u8 *);


BtlPacket *btlFormationCreateSlotPacket(u16, u16);
s64 btlPacketEnqueue(u8 *, u32);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;
extern u8 *btlUnitCreateColorPacket(u8 *, u32, s16, s16, u8, u8);
extern BtlPacket *btlUnitCreateModelReleasePacket(BtlUnit *unit);
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
extern f32 fGpffff811c;
extern u32 datCalcGetBadStatus(s32);
extern s16 btlSoundCalcStatusHpSpDelta(u8 *);
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
extern void btlTargetClearResultBuffer(u8 *);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
extern BtlPacket *btlFormationCreateReturnPacket(u16);
extern u8 *btlUnitCreateLookAtSidePacket(u8 *unit, s16 sideFlags);
extern BtlPacket *btlFormationCreateEventPacket(u32 value);
BtlPacket *btlMainCreateColorSetPacket(s32);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
u8 *btlSoundLoadPacketNew(const void *request);
s32 btlTargetCanControlDamagePhase(void);
u8 *btlSoundLoadTaskStart(void);
u8 *btlSoundReleaseTaskStart(void);
extern void btlDamageSetSource(u8 *, s32);
s32 btlActionCanFollowUpAfterEnemiesDown(u8 *);
s64 *btlActionGetQueueFront(void);
s32 btlEffectFindUnitMatchingCallback(u8 *, s32, s32, s32, s32,
                  s32 (*)(u8 *, s64));
u32 btlCountUnitRecordsById(u32);
u8 *btlCutinCreatePacket(u8 *);
u8 *btlUnitCreateRotateTowardUnitPacket(u8 *, u8 *, s32);
u8 *btlPacketAllocZeroed(s32, s32);
u8 *btlEffectCreateFormationPacket(s32, s32, s32, s64, s32);
u8 *func_001f99c0(u8 *, u16, s32, s32, s32);
u8 *btlCutinCreateEndPacket(void);
u8 *btlCutinCreateStartPacket(void);
extern void btlMessageStartShort(u8 *task, u8 *action);
extern s32 btlMessageIsActive(s32 task);
extern s32 btlMessageGetResult(s32 task);
extern void btlMessageReset(s32 task);
s16 btlCameraSelectFormationIndex(void);
s32 btlSideCountNotBad(s32, s32);
u32 datCalcChkBadStatus(s32, u32);

BtlPacket *btlFormationCreatePacket(u32, u32, u32, u16, u32);
BtlPacket *btlSoundCreateChannelCuePacket(u16, u16, u16);
extern f32 D_0076144C;
s32 btlStatusWindowShowSlot3Callback(u8 *);
void btlTaskSlotLinkedSlot3Callback(void);

extern s32 btlActionLinkedUnitIsActive(BtlAction *action);
extern void btlActionSkillUpdate(u8 *);
u8 datCalcGetCharacterTableKind(u8 *unit);
/* firstField is an interior halfword column; retain the 0xE8 row-to-row stride. */

/* Determine close-camera eligibility from unit class and the class-specific camera table. */

/* Ten-byte request copied by btlCutinCreatePacket; case 0 reads the three resource IDs and the
 * count. */
typedef struct BtlCutinRequest {
    u16 kind;
    s16 ids[3];
    s16 count;
} BtlCutinRequest;

typedef struct ActionTargetTable {
    u8 beforeTargets[0xC48];
    u8 *targets[4];
    u16 count;
} ActionTargetTable;
/* Read a selected target through its narrow target slot. measured: the inline wrapper keeps the
 * battle-base load ahead of the target-index shift, as retail does. */
static inline u8 *btlActionGetTarget(ActionTargetTable *table, u16 index)
{
    return table->targets[index];
}

#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* The signed element stays in halfword storage; propagation is off so the unit load precedes the
 * element's sign extension. */
#pragma push
/* Keep the promoted shuffle count and output base at their explicit
 * phase boundaries. The index reference preserves each narrow read. */
/* Select eligible targets, preserving the reference action when required,
 * then queue voice, cut-in and dependent formation packets. Both local
 * target lists hold twelve entries; single-target selection requires
 * a nonempty eligible set. */
#pragma pop
#pragma push
/* measured: the ushort counter wrap and offset-first helper keep retail's operation order. */
#pragma pop
#pragma push
#pragma pop
/* Preserve unit/UID reloads across queue callbacks and the ordered distance test. */
#pragma push
#pragma pop
#pragma push
/* measured: loop-invariant hoisting is needed for retail's loop code shape. */
#pragma pop
#pragma push
/* measured: loop-invariant hoisting produces retail's hit-loop preheader. */
#pragma pop
#pragma push
#pragma pop
/* Packet submissions reload the unit, UID and globals because callbacks can see them. */
#pragma push
#pragma pop
// FUN_001ADE90
void btlActionBadDamageInit(void)
{
}

/* Queue the status-damage result and dependent display, animation and sound. The result is a
 * complete 32-byte object; the ID snapshot follows the status query. */
// FUN_001ADEA0
void btlActionBadDamageUpdate(u8 *action)
{
    u32 datCalcGetBadStatus(s32 unit);
    u8 *unit;
    s64 packetIdentity;
    u32 statusKind;
    u32 badStatus;
    struct {
        s32 hpDelta;
        s32 spDelta;
        u8 otherResults[22];
        u16 flags;
    } result;
    s32 delta;
    u8 *resultPacket;
    u8 *healthPacket;
    u8 *displayPacket;
    u8 *gaugePacket;
    u8 *animationPacket;
    u8 *soundPacket;

    if (btlCountUnitRecordsById(0x700) == 0 && btlCountUnitRecordsById(0x506) == 0 && btlCountUnitRecordsById(0x507) == 0) {
        unit = *(u8* *)&((BtlAction *)action)->unit;
        badStatus = datCalcGetBadStatus(*(s32 *)&((BtlUnit *)unit)->datUnit);
        packetIdentity = *(s64 *)action;
        statusKind = badStatus & 0xFFFFF;
        switch (statusKind) {
        case 0x20:
            {
                btlTargetClearResultBuffer((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)btlSoundCalcStatusHpSpDelta(action);
                result.hpDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)&((BtlPacket *)resultPacket)->delay = 12;
                    btlPacketEnqueue(resultPacket, 1);
                    healthPacket = btlPacketCreateHpRatio(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)healthPacket)->dependencyUID = *(s64 *)&((BtlPacket *)resultPacket)->uid;
                    btlPacketEnqueue(healthPacket, 1);
                    displayPacket = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)displayPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    btlPacketEnqueue(displayPacket, 3);
                    gaugePacket = btlPacketCreateUnitCounter((s32)unit, 0, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)gaugePacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    btlPacketEnqueue(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, action, BtlAction, unit), -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)animationPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    *(animationPacket + 32) = 10;
                    *(s16 *)&((BtlPacketCondition *)animationPacket)[2].value.id = 769;
                    *(s64 *)&((BtlPacket *)animationPacket)->actionUID = packetIdentity;
                    btlPacketEnqueue(animationPacket, 0);
                    soundPacket = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)soundPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    btlPacketEnqueue(soundPacket, 1);
                }
                {
                    u16 actionKind = ((BtlAction *)action)->unk_6c;
                    u16 nextState;
                    switch (actionKind) {
                    case 1:
                    case 3:
                    case 2:
                        nextState = 32;
                        break;
                    default:
                        nextState = 32;
                        break;
                    }
                    btlActionSetState((BtlAction *)action, nextState);
                }
                return;
            }
            break;
        case 0x40:
            {
                btlTargetClearResultBuffer((u8 *)&result);
                result.flags = result.flags | 0x100;
                delta = (s16)btlSoundCalcStatusHpSpDelta(action);
                result.spDelta = delta;
                if (delta < 0) {
                    resultPacket = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)action, &result, 1, 1);
                    *(s16 *)&((BtlPacket *)resultPacket)->delay = 12;
                    btlPacketEnqueue(resultPacket, 1);
                    healthPacket = btlPacketCreateHpRatio(unit);
                    *(healthPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)healthPacket)->dependencyUID = *(s64 *)&((BtlPacket *)resultPacket)->uid;
                    btlPacketEnqueue(healthPacket, 1);
                    displayPacket = btlPacketCreateHitDisplay((s32)unit, (s32)unit, -1, 0, 0, 0, 1, &result, 0);
                    *(displayPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)displayPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    *(displayPacket + 71) = *(displayPacket + 71) & 0xDF;
                    btlPacketEnqueue(displayPacket, 3);
                    gaugePacket = btlPacketCreateUnitCounter((s32)unit, 1, 0);
                    *(gaugePacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)gaugePacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    *(gaugePacket + 71) = *(gaugePacket + 71) & 0xDF;
                    btlPacketEnqueue(gaugePacket, 3);
                    animationPacket = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, action, BtlAction, unit), -2, 0, 1.0f, 0);
                    *(animationPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)animationPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    *(animationPacket + 32) = 10;
                    *(s16 *)&((BtlPacketCondition *)animationPacket)[2].value.id = 769;
                    *(s64 *)&((BtlPacket *)animationPacket)->actionUID = packetIdentity;
                    btlPacketEnqueue(animationPacket, 0);
                    soundPacket = (u8 *)btlSoundCreateChannelCuePacket(10, 2, 24);
                    *(soundPacket + 0) = 4;
                    *(s64 *)&((BtlPacket *)soundPacket)->dependencyUID = MEMBER(s64, resultPacket, BtlPacket, uid);
                    btlPacketEnqueue(soundPacket, 1);
                }
                {
                    u16 actionKind = ((BtlAction *)action)->unk_6c;
                    u16 nextState;
                    switch (actionKind) {
                    case 1:
                    case 3:
                    case 2:
                        nextState = 32;
                        break;
                    default:
                        nextState = 32;
                        break;
                    }
                    btlActionSetState((BtlAction *)action, nextState);
                }
                return;
            }
            break;
        default:
            {
                u16 actionKind = ((BtlAction *)action)->unk_6c;
                u16 nextState;
                switch (actionKind) {
                case 1:
                case 3:
                case 2:
                    nextState = 32;
                    break;
                default:
                    nextState = 32;
                    break;
                }
                btlActionSetState((BtlAction *)action, nextState);
            }
            break;
        }
    }
}

// FUN_001AE3C0
/* Return the action completion counter used by the callback-wait packet. */
s32 btlActionGetCounter428(BtlAction *action)
{
    return ((BtlAction *)(u8 *)action)->unk_428;
}

/* Build the return-to-action packet sequence and select an available target. */
// FUN_001AE3D0
void btlActionRoundupMesInit(u8 *action)
{
    u8 *currentAction;
    u8 *target;
    u32 flags;
    u8 *targetAction;
    u8 *packet;
    /* The cut-in constructor copies ten bytes. Mode 1 uses only the
     * leading mode and unit ID; the remaining representation is opaque. */
    struct { u16 mode, unitId; u8 reserved[6]; } cutin;
    u32 selectedAction;
    s32 changeFormation;
    u32 enemyCount;
    s16 previousFormation;
    u16 targetIndex;

    currentAction = ((BtlBattleState *)iGpffffb3ac)->actions;
    while (currentAction != NULL) {
        if (btlActionLinkedUnitIsActive((BtlAction *)currentAction) != 0) {
            packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)*(u8* *)&((BtlAction *)currentAction)->unit)->childUnit);
            *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)currentAction;
            btlPacketEnqueue(packet, 1);
        }
        currentAction = *(u8* *)&((BtlAction *)currentAction)->next;
    }
    target = NULL;
    if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus == 0) {
        selectedAction = (u32)action;
    } else {
        selectedAction = (u32)((BtlAction *)action)->targets[0];
    }
    if (selectedAction != 0) {
        u16 i;
        u8 *tableBase;
        s32 count;
        u32 current;
        i = 0;
        tableBase = iGpffffb3ac;
        count = ((BtlBattleState *)tableBase)->partyActionCount;
        while ((s32)i < count) {
            current = *(u32 *)&((BtlBattleState *)tableBase)->partyActions[(u32)i];
            if (current == selectedAction) {
                target = (u8 *)selectedAction;
                break;
            }
            i++;
        }
    }
    if (target == NULL) {
        target = btlActionGetTarget((ActionTargetTable *)iGpffffb3ac, (datCalcRandomBelow(((BtlBattleState *)iGpffffb3ac)->partyActionCount) & 0xFFFF));
    }
    cutin.mode = 1;
    cutin.unitId = ((BtlUnit *)*(u8* *)&((BtlAction *)target)->unit)->charId;
    packet = btlSoundLoadPacketNew(&cutin);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    if (((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->genus != 0) {
        changeFormation = 0;
    } else if ((((BtlBattleState *)iGpffffb3ac)->unkA70 != -1) &&
               (enemyCount = btlSideCountNotBad(2, 0x80000) & 0xFFFF,
                (u32)(((BtlBattleState *)iGpffffb3ac)->unkA72 >> 1) >= enemyCount) &&
               (previousFormation = ((BtlBattleState *)iGpffffb3ac)->unkA70,
                previousFormation != (s16)btlCameraSelectFormationIndex())) {
        changeFormation = 1;
    } else {
        changeFormation = 0;
    }
    if (changeFormation != 0) {
        packet = (u8 *)btlFormationCreateReturnPacket(1);
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
    }
    packet = (u8 *)btlUnitCreateAnimPacket(((BtlAction *)((BtlBattleState *)iGpffffb3ac)->selectedAction)->unit, 0, 0, 1.0f, 1);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    targetIndex = 0;
    while ((s32)targetIndex < ((BtlBattleState *)iGpffffb3ac)->partyActionCount) {
        targetAction = ((BtlBattleState *)iGpffffb3ac)->partyActions[(u32)targetIndex];
        packet = (u8 *)btlUnitCreateAnimPacket(((BtlAction *)targetAction)->unit, 0, 0, 1.0f, 1);
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 0);
        targetIndex++;
    }
    packet = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = btlUnitCreateLookAtSidePacket(0, 3);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    packet = (u8 *)btlUnitCreateLookAtDeactivatePacket(NULL, 3);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 1);
    packet = (u8 *)btlFormationCreateEventPacket((u32)action);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = (u8 *)btlMainCreateColorSetPacket(0);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    packet = (u8 *)btlCameraCreateSetStatePacket((BtlAction *)action, 7);
    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
    btlPacketEnqueue(packet, 0);
    flags = ((BtlBattleState *)iGpffffb3ac)->flags;
    flags = flags & 0xFFBFFFFF;
    ((BtlBattleState *)iGpffffb3ac)->flags = flags;
    ((BtlBattleState *)iGpffffb3ac)->actionEndFlags = 0;
    if (btlTargetCanControlDamagePhase() == 1) {
        flags = ((BtlBattleState *)iGpffffb3ac)->flags;
        flags = flags & ~0x2000;
        ((BtlBattleState *)iGpffffb3ac)->flags = flags;
        btlDamageSetSource(*(u8* *)&((BtlBattleState *)iGpffffb3ac)->uiTask, 0);
    }
    *(u8* *)&((BtlAction *)action)->unk_41c = target;
    ((BtlAction *)action)->unk_420 = 0;
    ((BtlAction *)action)->unk_424 = 0;
    ((BtlAction *)action)->unk_428 = 0;
    *(u16 *)&((BtlAction *)action)->unk_42c = 12;
}

// FUN_001AE800
/* Wait for cut-in and voice packets, present the follow-up prompt, then queue the chosen continuation. */
void btlActionRoundupMesUpdate(u8 *action)
{
    u8 *gp2;
    u8 *packet1;
    u8 *packet2;
    u8 *packet3;
    u8 *packet4;
    u16 i;
    u32 loopIndex;
    u8 frame[0x10];

    if (((BtlAction *)action)->unk_424 == 0) {
        if (btlCountUnitRecordsById(0xC00) != 0) {
            return;
        }
        if (btlCountUnitRecordsById(0xC04) != 0) {
            return;
        }
        *(s16 *)frame = 0;
        i = 0;
        gp2 = D_0076449C;
        while ((s32)(loopIndex = i) < ((BtlBattleState *)gp2)->partyActionCount) {
            packet1 = ((BtlBattleState *)gp2)->partyActions[(u32)i];
            *(u16 *)&((BtlCutinRequest *)frame)->ids[(u32)i] =
                ((BtlUnit *)*(u8* *)&((BtlAction *)packet1)->unit)->charId;
            i++;
        }
        *(u16 *)&((BtlCutinRequest *)frame)->count = ((BtlBattleState *)gp2)->partyActionCount;
        packet1 = btlCutinCreatePacket(frame);
        btlPacketEnqueue(packet1, 1);
        packet2 = btlSoundLoadTaskStart();
        *(s16 *)&((BtlPacket *)packet2)->delay = *(s16 *)&((BtlAction *)action)->unk_42c;
        btlPacketEnqueue(packet2, 1);
        packet3 = btlPacketAllocZeroed((s32)btlActionGetCounter428, (s32)action);
        *(s16 *)&((BtlPacket *)packet3)->delay = MEMBER(s16, action, BtlAction, unk_42c);
        btlPacketEnqueue(packet3, 1);
        packet4 = btlEffectCreateFormationPacket(
            *(s32 *)&((BtlBattleState *)D_0076449C)->formations[34],
            *(s32 *)&((BtlAction *)action)->unit, 0,
            *(s64 *)&((BtlPacket *)packet3)->uid, 0x8000);
        *(s16 *)&((BtlPacket *)packet4)->delay = MEMBER(s16, action, BtlAction, unk_42c);
        btlPacketEnqueue(packet4, 2);
        MEMBER(s32, action, BtlAction, unk_424) = 1;
    }

    if (((BtlAction *)action)->unk_420 == 0) {
        if (*(s16 *)&((BtlAction *)action)->unk_42c <= 0) {
            btlMessageStartShort(*(u8* *)&((BtlBattleState *)D_0076449C)->uiTask,
                          *(u8* *)&((BtlAction *)action)->unk_41c);
            MEMBER(s32, action, BtlAction, unk_420) = 1;
        } else {
            MEMBER(s16, action, BtlAction, unk_42c) = *(s16 *)&((BtlAction *)action)->unk_42c - 1;
        }
    }

    if (btlUnitRecordFindByActionUID(*(u64 *)action,
                      0x3FFFFFFFFFFFFFFFULL) != 0) {
        return;
    }

    if (((BtlAction *)action)->unk_428 == 0) {
        if (btlMessageIsActive(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
            return;
        }
        if (btlMessageGetResult(((BtlBattleState *)D_0076449C)->uiTask) == 0) {
            packet1 = btlTargetCreateActionPacket(action, 2);
            ((BtlPacket *)packet1)->actionUID = *(u64 *)action;
            btlPacketEnqueue(packet1, 1);
            ((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unk_434 =
                ((BtlAction *)action)->unk_41c;
            ((BtlAction *)((BtlBattleState *)D_0076449C)->selectedAction)->unk_16 = 0x1F;
            btlActionActiveListPush(*(s32 *)&((BtlBattleState *)D_0076449C)->selectedAction);
            packet2 = (u8 *)btlActionGetQueueFront();
            if ((((BtlUnit *)*(u8* *)&((BtlAction *)packet2)->unit)->genus == 0) &&
                (((BtlAction *)packet2)->unk_28 != 0)) {
                ((BtlAction *)packet2)->flags |= 0x8000;
            }
            btlPacketEnqueue(
                func_001f99c0(MEMBER(u8 *, action, BtlAction, unk_41c), 6, 1, 0, 0), 1);
        } else {
            btlPacketEnqueue(
                func_001f99c0(*(u8* *)&((BtlAction *)action)->unk_41c, 6, 0, 0, 0), 1);
            packet1 = btlCutinCreateStartPacket();
            ((BtlPacket *)packet1)->actionUID = *(u64 *)action;
            btlPacketEnqueue(packet1, 1);
        }

        packet1 = btlSoundReleaseTaskStart();
        ((BtlPacket *)packet1)->actionUID = *(u64 *)action;
        btlPacketEnqueue(packet1, 1);
        packet2 = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 1);
        ((BtlPacket *)packet2)->actionUID = *(u64 *)action;
        btlPacketEnqueue(packet2, 1);
        ((BtlAction *)action)->flags &= 0xFFF7;
        if (btlTargetCanControlDamagePhase() == 1) {
            *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x2000;
            btlDamageSetSource(*(u8* *)&((BtlBattleState *)D_0076449C)->uiTask, 1);
        }
        MEMBER(s32, action, BtlAction, unk_428) = 1;
        ((u16 *)&((BtlAction *)action)->unk_42c)[1] = 6;
        return;
    }

    if (((u16 *)&((BtlAction *)action)->unk_42c)[1] == 0) {
        btlMessageReset(((BtlBattleState *)D_0076449C)->uiTask);
        *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 7;
        btlActionSetState((BtlAction *)action, 0x20);
        return;
    }
    *(u16 *)&((BtlAction *)(action))->roundupTimers[1] = ((u16 *)&((BtlAction *)action)->unk_42c)[1] - 1;
}

// FUN_001AEC20
/* Copy eligible targets and choose the roundup skill from the number of reacting targets. */
void btlActionRoundupInit(u8 *action)
{
    s32 activeCountMasked;
    s32 unitIndex;
    s32 activeCount;
    s32 slotIndex;
    s32 unitCount;
    s32 slotCount;
    u8 *slot;

    btlTargetResetCommandRecord(action + 0x38);
    btlSkillClassifyTargets(action, action + 0x98, 0x100, 0);
    unitIndex = 0;
    goto loop_2_test;
loop_2_body:
    slot = action + ((u16)unitIndex * 4);
    *(s32 *)&((BtlAction *)slot)->targets[0] = *(s32 *)&((BtlAction *)slot)->parameters.candidates[0];
    unitIndex = (unitIndex + 1) & 0xFFFF;
loop_2_test:
    unitCount = ((BtlAction *)action)->unk_d0;
    if ((unitIndex & 0xFFFF) < unitCount) {
        goto loop_2_body;
    }
    ((BtlAction *)action)->unk_6a = unitCount;
    *(s16 *)&((BtlAction *)action)->unk_6c = 2;
    *(s16 *)&((BtlAction *)action)->unk_6e = 0x100;
    btlTargetResolveSelectedSkill(action);
    activeCount = 0;
    slotIndex = 0;
    slotCount = MEMBER(u16, action, BtlAction, unk_6a);
    goto loop_7_test;
loop_7_body:
    if (((BtlAction *)((BtlAction *)action)->targets[(u16)slotIndex])->targetBlock.reactionFlag != 0) {
        activeCount = (activeCount + 1) & 0xFFFF;
    }
    slotIndex = (slotIndex + 1) & 0xFFFF;
loop_7_test:
    if ((slotIndex & 0xFFFF) < slotCount) {
        goto loop_7_body;
    }
    activeCountMasked = activeCount & 0xFFFF;
    if (slotCount == activeCountMasked) {
        MEMBER(s16, action, BtlAction, unk_6e) = 0x102;
        return;
    }
    if (activeCountMasked != 0) {
        MEMBER(s16, action, BtlAction, unk_6e) = 0x100;
        return;
    }
    MEMBER(s16, action, BtlAction, unk_6e) = 0x101;
}

// FUN_001AED50
#pragma push
/* measured: retail keeps loop-invariant action and unit loads hoisted out of the target loop. */
#pragma opt_loop_invariants on
void btlActionRoundupUpdate(u8 *action)
{
    extern s32 btlFormationAllocWork(u32 mode);
    extern void btlFormationSetPlacement(u32 formation);
    extern u32 btlFormationGetFlags(s32 record);
    extern u8 *btlFormationDispatchPacketNew(u32 action, u32, u32);
    extern u8 *btlTargetCreateRecordPacket(u8 *action);
    extern s32 btlUnitSlotValueOrOne(s32 unitId);
    extern void btlBossResetPendingCue(u8 *action);
    extern u32 datCalcChkBadStatus(s32 action, u32);
    extern void btlMainSkillColorPairDefaults(u32 action, s32 *, s32 *);
    extern s32 btlMainSkillColorDefault(s32 skill);
    extern s32 btlMainSkillTintDefault(s32 skill);
    extern void btlMainSkillColorPairDefaultsAlt(u32 action, s32 *, s32 *);
    extern BtlPacket *btlMainCreateColorLerpPacket(u32 action, u32, u32);
    extern BtlPacket *btlMainCreateColorWorkPacket(s32 lightColor, s32 ambientColor, s32 fogColor, u32 duration, u16 flags);
    extern BtlPacket *btlMainCreateTintPacket(u32 action, u32);
    extern BtlPacket *btlCreateTimingPacket(u32 value);
    extern BtlPacket *btlMainCreateFadePacket(s32 action, s16);
    extern BtlPacket *btlMainCreateColorFadePacket(s32 arg);
    extern BtlPacket *btlSoundCreateStreamPacket(u16 action, const char *);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
    extern u8 D_005F6D38[];
    extern u8 D_005F6D48[];
    extern u8 D_005F6D58[];
    extern BtlSkillFlags *iGpffffb3bc;
    s32 outHi;
    s32 outLo;
    s32 partyUnits[3];
    union { u8 bytes[32]; s32 words[8]; } tmpBuf;
    char workBuf[128];
    u8 *namedFormationPacket;
    u8 *formationPacket;
    u32 handle;
    u16 targetDelay;
    s32 skillId;
    u16 targetIndex;
    u8 *rec;
    u16 hitIndex;
    u8 *setupPacket;
    u8 *effectAction;
    u8 *chain;
    u8 *anim;
    u8 *targetOrUnit;
    u8 *target;
    s64 uid;
    s32 aux;
    u32 selector;
    s64 setupUID;
    u16 frameInterval;
    s32 colorKind;
    u32 formationFlags;
    u16 k;
    u8 *list;

    uid = *(s64 *)action;
    handle = btlFormationAllocWork(1);
    for (list = ((BtlBattleState *)iGpffffb3ac)->actions; list != NULL; list = *(u8* *)&((BtlAction *)list)->next) {
        if (((BtlAction *)list)->unk_28 != 0) {
            u8 *packet;
            packet = btlTargetCreateActionPacket(list, 2);
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 1);
        }
    }
    aux = *(s16 *)&((BtlAction *)action)->unk_6e;
    target = ((BtlAction *)action)->targets[0];
    for (k = 0; k < ((BtlBattleState *)iGpffffb3ac)->partyActionCount; k++) {
        partyUnits[k] = (s32)((BtlAction *)((BtlBattleState *)iGpffffb3ac)->partyActions[k])->unit;
    }
    for (; k < 3U; k++) {
        partyUnits[k] = 0;
    }
    {
        u8 *packet;
        packet = btlFormationDispatchPacketNew(partyUnits[0], partyUnits[1], partyUnits[2]);
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    setupPacket = btlCutinCreateEndPacket();
    *setupPacket = 10;
    *(s16 *)&((BtlPacketCondition *)setupPacket)[0].value.id = 0xC00;
    *(setupPacket + 0x10) = 10;
    *(s16 *)&((BtlPacketCondition *)setupPacket)[1].value.id = 0xC05;
    *(s64 *)&((BtlPacket *)setupPacket)->actionUID = uid;
    btlPacketEnqueue(setupPacket, 1);
    {
        u8 *packet;
        packet = (u8 *)btlSoundCreateChannelCuePacket(0xE, 4, 4);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)setupPacket)->uid;
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
    }
    setupUID = MEMBER(s64, setupPacket, BtlPacket, uid);
    {
        u8 *packet;
        packet = func_001f99c0(*(u8* *)&((BtlAction *)action)->unk_434, 7, 0, 0, 0);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, setupPacket, BtlPacket, uid);
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
        btlPacketEnqueue(packet, 1);
    }
    selector = (u16)aux;
    btlMainSkillColorPairDefaults(selector, &outHi, &outLo);
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorLerpPacket((u32)outHi, (u32)outLo, 0x10);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    colorKind = btlMainSkillColorDefault(selector);
    btlMainSkillColorPairDefaultsAlt(selector, &outHi, &outLo);
    /* Palette entries are four bytes; their flags are the second halfword. */
    skillId = (s16)aux;
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorWorkPacket(colorKind, outHi, outLo, 0x10, ((iGpffffb3bc[skillId].flags & 2) ? 1U : 0U));
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        aux = (u16)aux;
        packet = (u8 *)btlMainCreateTintPacket(btlMainSkillTintDefault(aux), 0x10);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateUnitTintPacket((BtlAction *)action, aux, 0x10);
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = setupUID;
        *(s16 *)&((BtlPacket *)packet)->delay = 0x3C;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    btlFormationFormatName(aux, workBuf);
    namedFormationPacket = (u8 *)btlFormationCreateNamedPacket(handle, workBuf, 0);
    *namedFormationPacket = 5;
    *(s64 *)&((BtlPacket *)namedFormationPacket)->dependencyUID = setupUID;
    *(s16 *)&((BtlPacket *)namedFormationPacket)->delay = 0x3C;
    *(s64 *)&((BtlPacket *)namedFormationPacket)->actionUID = uid;
    btlPacketEnqueue(namedFormationPacket, 1);
    for (targetOrUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[0]; targetOrUnit != NULL; targetOrUnit = *(u8* *)&((BtlUnit *)targetOrUnit)->nextUnit) {
        if (datCalcChkBadStatus(*(s32 *)&((BtlUnit *)targetOrUnit)->datUnit, 0x100117) != 0 || datCalcIsDead(MEMBER(s32, targetOrUnit, BtlUnit, datUnit), 0) != 0) {
            u8 *packet;
            packet = btlUnitCreateColorPacket(targetOrUnit, 0xFFFFFF, 0, 0, 4, 0);
            *packet = 4;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)namedFormationPacket)->uid;
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 0);
        }
    }
    formationPacket = (u8 *)btlFormationCreatePacket(handle, *(u32 *)&((BtlAction *)action)->unit, *(u32 *)&((BtlAction *)target)->unit, 0, 0);
    *formationPacket = 4;
    *(s64 *)&((BtlPacket *)formationPacket)->dependencyUID = *(s64 *)&((BtlPacket *)namedFormationPacket)->uid;
    *(s64 *)&((BtlPacket *)formationPacket)->actionUID = uid;
    btlPacketEnqueue(formationPacket, 2);
    {
        u8 *packet;
        switch (skillId) {
        case 0x100:
            packet = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D38);
            break;
        case 0x101:
            packet = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D48);
            break;
        default:
            packet = (u8 *)btlSoundCreateStreamPacket(2, (const char *)D_005F6D58);
            break;
        }
        *packet = 5;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)formationPacket)->uid;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    targetDelay = 0;
    frameInterval = (u16)btlUnitSlotValueOrOne(selector);
    for (targetIndex = 0; targetIndex < ((BtlAction *)action)->unk_6a; targetIndex++) {
        targetOrUnit = ((BtlAction *)action)->targets[(u32)targetIndex];
        btlBossResetPendingCue(targetOrUnit);
        formationFlags = btlFormationGetFlags((s32)(targetOrUnit + 0xD8));
        if (((BtlAction *)targetOrUnit)->targetBlock.specialHitFlag != 0) {
            effectAction = action;
        } else {
            effectAction = targetOrUnit;
        }
        {
            u8 *packet;
            packet = btlPacketCreateHpRatio(*(u8* *)&((BtlAction *)effectAction)->unit);
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 1);
        }
        chain = (u8 *)btlFormationCreatePacket(handle, MEMBER(u32, action, BtlAction, unit), MEMBER(u32, effectAction, BtlAction, unit), 1, formationFlags | 0x1000);
        *chain = 4;
        *(s64 *)&((BtlPacket *)chain)->dependencyUID = MEMBER(s64, namedFormationPacket, BtlPacket, uid);
        *(s16 *)&((BtlPacket *)chain)->delay = targetDelay;
        *(s64 *)&((BtlPacket *)chain)->actionUID = uid;
        btlPacketEnqueue(chain, 2);
        {
            u8 *packet;
            packet = (u8 *)btlSoundCreateChannelCuePacket(0xA, 0, 4);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)chain)->uid;
            btlPacketEnqueue(packet, 1);
        }
        if (MEMBER(s32, targetOrUnit, BtlAction, targetBlock.specialHitFlag) != 0) {
            u8 *packet;
            packet = (u8 *)btlFormationCreatePacket(*(u32 *)&((BtlBattleState *)iGpffffb3ac)->formations[9], MEMBER(u32, action, BtlAction, unit), *(u32 *)&((BtlAction *)targetOrUnit)->unit, 1, 0);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid);
            btlPacketEnqueue(packet, 1);
        }
        if (((BtlAction *)targetOrUnit)->targetBlock.hitOutcome == 0x400) {
            u8 *packet;
            packet = (u8 *)btlFormationCreatePacket(*(u32 *)&((BtlBattleState *)iGpffffb3ac)->formations[10], MEMBER(u32, action, BtlAction, unit), MEMBER(u32, effectAction, BtlAction, unit), 1, 0);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid);
            btlPacketEnqueue(packet, 1);
        }
        for (hitIndex = 0; hitIndex < ((BtlAction *)targetOrUnit)->targetBlock.hitRowCount; hitIndex++) {
            u16 *flags;
            rec = targetOrUnit + ((u32)hitIndex << 5);
            anim = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, effectAction, BtlAction, unit), (s32)((BtlAction *)rec)->targetBlock.hitRows[0].motion, 0, 1.0f, 0);
            *anim = 0xB;
            *(s64 *)&((BtlPacket *)anim)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid);
            *(s64 *)&((BtlPacket *)anim)->actionUID = uid;
            btlPacketEnqueue(anim, 0);
            {
                u8 *packet;
                packet = btlUnitCreateRotateTowardUnitPacket(*(u8* *)&((BtlAction *)targetOrUnit)->unit, MEMBER(u8 *, action, BtlAction, unit), 2);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)anim)->uid;
                *(packet + 0x47) &= (u8)~0x20;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            {
                u8 *packet;
                packet = (u8 *)btlTargetCreateDataPacket((s32)action, (s32)effectAction, (&((const BtlAction *)(rec))->targetBlock.hitRows[0]), MEMBER(u16, targetOrUnit, BtlAction, targetBlock.hitOutcome), ((BtlAction *)targetOrUnit)->targetBlock.targetFlags);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            {
                u8 *packet;
                packet = btlTargetCreateRecordPacket(targetOrUnit);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            if (targetIndex == MEMBER(u16, action, BtlAction, unk_6a) - 1 && hitIndex == MEMBER(u8, targetOrUnit, BtlAction, targetBlock.hitRowCount) - 1) {
                u8 *packet;
                packet = btlTargetCreateRecordPacket(action);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
            }
            if (hitIndex == 0 && ((const LargeBattleHitResult *)&((const BtlAction *)rec)->targetBlock.hitRows[0])[0].hpDelta != 0) {
                u8 *packet;
                packet = btlPacketCreateUnitCounter(MEMBER(s32, effectAction, BtlAction, unit), 0, 0);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                *(packet + 0x47) &= (u8)~0x20;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 3);
            }
            flags = (u16 *)(rec + 0x10E);
            if ((*flags & 1) != 0) {
                u8 *packet;
                btlTargetClearResultBuffer(tmpBuf.bytes);
                tmpBuf.words[3] = 0x100001;
                packet = (u8 *)btlTargetCreateDataPacket((s32)targetOrUnit, (s32)targetOrUnit, tmpBuf.bytes, 1, 1);
                *packet = 4;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 1);
                if ((*flags & 2) != 0) {
                    u8 *recoveryPacket;
                    recoveryPacket = (u8 *)btlUnitCreateAnimPacket(MEMBER(BtlUnit *, targetOrUnit, BtlAction, unit), 0xB, 0, 1.0f, 0);
                    *recoveryPacket = 4;
                    *(s64 *)&((BtlPacket *)recoveryPacket)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                    *(s64 *)&((BtlPacket *)recoveryPacket)->actionUID = uid;
                    btlPacketEnqueue(recoveryPacket, 0);
                    recoveryPacket = (u8 *)btlUnitCreateMotionSettlePacket(MEMBER(BtlUnit *, targetOrUnit, BtlAction, unit));
                    *recoveryPacket = 4;
                    *(s64 *)&((BtlPacket *)recoveryPacket)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                    *(s64 *)&((BtlPacket *)recoveryPacket)->actionUID = uid;
                    btlPacketEnqueue(recoveryPacket, 0);
                }
            }
            {
                u8 *packet;
                packet = btlPacketCreateHitDisplay(MEMBER(s32, action, BtlAction, unit), MEMBER(s32, effectAction, BtlAction, unit), skillId, MEMBER(u16, targetOrUnit, BtlAction, targetBlock.hitOutcome), MEMBER(u16, targetOrUnit, BtlAction, targetBlock.targetFlags), hitIndex, MEMBER(u8, targetOrUnit, BtlAction, targetBlock.hitRowCount), (&((const BtlAction *)(rec))->targetBlock.hitRows[0]), 0);
                *packet = 5;
                *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
                *(packet + 0x47) &= (u8)~0x20;
                *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
                btlPacketEnqueue(packet, 3);
            }
        }
        targetDelay += frameInterval;
    }
    for (targetOrUnit = ((BtlBattleState *)iGpffffb3ac)->unitLists[0]; targetOrUnit != NULL; targetOrUnit = *(u8* *)&((BtlUnit *)targetOrUnit)->nextUnit) {
        if (datCalcChkBadStatus(*(s32 *)&((BtlUnit *)targetOrUnit)->datUnit, 0x100117) != 0 || datCalcIsDead(MEMBER(s32, targetOrUnit, BtlUnit, datUnit), 0) != 0) {
            u8 *packet;
            packet = btlUnitCreateColorPacket(targetOrUnit, -1, 0xC, 0, 3, 0);
            *packet = 0xB;
            *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)chain)->uid;
            *(s16 *)&((BtlPacket *)packet)->delay = 6;
            *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
            btlPacketEnqueue(packet, 0);
        }
    }
    {
        u8 *packet;
        packet = (u8 *)btlCreateTimingPacket(0x10);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)anim)->uid;
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateFadePacket(0x10, 0);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorFadePacket(0x10);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, anim, BtlPacket, uid);
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    {
        u8 *packet;
        packet = (u8 *)btlMainCreateColorSetPacket(8);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = *(s64 *)&((BtlPacket *)chain)->uid;
        *(packet + 0x47) &= (u8)~0x20;
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 0);
    }
    {
        u8 *packet;
        packet = btlFormationDispatchPacketNew(0, 0, 0);
        *packet = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID = MEMBER(s64, chain, BtlPacket, uid);
        *(packet + 0x10) = 4;
        *(s64 *)&((BtlPacket *)packet)->dependencyUID2 = MEMBER(s64, formationPacket, BtlPacket, uid);
        *(s64 *)&((BtlPacket *)packet)->actionUID = uid;
        btlPacketEnqueue(packet, 1);
    }
    btlFormationSetPlacement(handle);
    btlActionSetState((BtlAction *)action, 0x20);
}
#pragma pop

// FUN_001AF9D0
void btlActionPacketInit(void)
{
}

/* Advance to action-end processing once no queued packet retains this action UID. */
// FUN_001AF9E0
void btlActionPacketUpdate(BtlAction *action)
{
    if (btlUnitRecordFindByActionUID(*(s64 *)&((BtlAction *)action)->uid, 0x3FFFFFFFFFFFFFFFLL) == 0) {
        btlActionSetState(action, 0x21U);
    }
}

// FUN_001AFA50
/* Transfer pending action-end flags to the battle controller, or wait for the status-window callback. */
void btlActionEndInit(u8 *action)
{
    if (((BtlAction *)action)->flags & 0x4000) {
        *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 6;
        MEMBER(u16, action, BtlAction, flags) &= 0xBFFF;
    }
    MEMBER(u16, action, BtlAction, flags) &= 0xFEFF;
    if (MEMBER(u16, action, BtlAction, flags) & 0x200) {
        *(s32 *)&((BtlBattleState *)D_0076449C)->flags |= 0x400000;
        ((BtlBattleState *)D_0076449C)->actionEndFlags |= 0x20;
        MEMBER(u16, action, BtlAction, flags) &= 0xFDFF;
    }
    if (btlStatusWindowShowSlot3Callback(action) != 0) {
        *(void (**)(void))(action + 0x440) = btlTaskSlotLinkedSlot3Callback;
        ((BtlAction *)action)->unk_43c = 0x21;
        btlActionSetState((BtlAction *)action, 0x16);
        return;
    }
    MEMBER(u16, action, BtlAction, flags) &= 0xC7FF;
}

/* Finish readiness, queued-order and status processing for this action. */
// FUN_001AFB50
void btlActionEndUpdate(u8 *action)
{
    s32 btlActionCanFollowUpAfterEnemiesDown(u8 *action);
    s32 btlCheckBattleEnd(void);
    s32 btlActionActiveListPush(s32 action);
    s32 btlOrderRemoveActionAll(u8 *action);
    void btlOrderQueueAction(u8 *action);
    void btlOrderSetCurrentAction(u8 *action);
    void btlActionCheckStepTrigger(s32 context);
    void datCalcAdvanceSecondaryBuffs(u8 *unit);
    void btlTargetRecordDefeatReward(u8 *action);
    void datCalcSetHp(s32 unit, u16 hp);
    u32 datCalcSetBadStatus(s32 unit, u32 badStatus);

    u16 entryFlags;
    s32 specialOrder;
    s32 restart;
    s32 dead;
    s32 resetUnit;
    u8 *packet;

    if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x80) == 0) {
        entryFlags = ((BtlAction *)action)->flags;
        specialOrder = (entryFlags & 4) != 0;
        if ((entryFlags & 8) != 0 && btlActionCanFollowUpAfterEnemiesDown(action) != 0) {
            if (btlCountUnitRecordsById(0x504) != 0) {
                return;
            }
            if (btlCountUnitRecordsById(0x506) != 0) {
                return;
            }
            ((BtlAction *)action)->unk_16 = 30;
            btlActionActiveListPush((s32)action);
            restart = 1;
        } else {
            ((BtlAction *)action)->flags = ((BtlAction *)action)->flags & 0xFFF7;
            restart = 0;
        }
        if ((MEMBER(u16, action, BtlAction, flags) & 0x8000) == 0 && specialOrder == 0) {
            *(s32 *)&((BtlAction *)action)->unk_20 = *(s32 *)&((BtlAction *)action)->unk_20 + 1;
        }
        if (btlCheckBattleEnd() == 0) {
            if ((MEMBER(u16, action, BtlAction, flags) & 0x8000) == 0 && specialOrder == 0) {
                if (*(action + 0x29) > 0) {
                    if (*(action + 0x28) == 0 && datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0) == 0) {
                        *(action + 0x29) = *(action + 0x29) - 1;
                    } else {
                        *(action + 0x29) = 0;
                    }
                }
                dead = datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0);
                if ((*(action + 0x28) == 0 && *(action + 0x29) == 0) || dead != 0) {
                    if (dead != 0) {
                        *(action + 0x28) = 0;
                        *(action + 0x29) = 0;
                        btlOrderRemoveActionAll(action);
                    }
                    {
                        u16 unitFlags = ((BtlAction *)action)->unk_1a;
                        if ((unitFlags & 1) == 0) {
                            resetUnit = 0;
                        } else {
                            u8 *unit = *(u8* *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->childUnit;
                            if ((unitFlags & 0x10) == 0) {
                                resetUnit = 0;
                            } else {
                                if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
                                    resetUnit = 1;
                                } else {
                                    resetUnit = 0;
                                }
                            }
                        }
                    }
                    if (resetUnit != 0) {
                        packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->childUnit);
                        *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
                        btlPacketEnqueue(packet, 1);
                    }
                    datCalcAdvanceSecondaryBuffs(*(u8* *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->datUnit);
                    btlActionCheckStepTrigger(1);
                    btlOrderQueueAction(action);
                } else {
                    btlOrderSetCurrentAction(action);
                    btlActionCheckStepTrigger(0);
                }
            } else {
                {
                    u16 unitFlags = ((BtlAction *)action)->unk_1a;
                    if ((unitFlags & 1) == 0) {
                        resetUnit = 0;
                    } else {
                        u8 *unit = *(u8* *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->childUnit;
                        if ((unitFlags & 0x10) == 0) {
                            resetUnit = 0;
                        } else {
                            if ((((BtlUnit *)unit)->flags2 & 2) != 0) {
                                resetUnit = 1;
                            } else {
                                resetUnit = 0;
                            }
                        }
                    }
                }
                if (resetUnit != 0) {
                    packet = (u8 *)btlUnitCreateModelReleasePacket(((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->childUnit);
                    *(s64 *)&((BtlPacket *)packet)->actionUID = *(s64 *)action;
                    btlPacketEnqueue(packet, 1);
                }
                btlOrderQueueAction(action);
            }
        } else {
            *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags = *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags | 0x80;

        }
        if (specialOrder == 0) {
            ((BtlAction *)action)->flags = ((BtlAction *)action)->flags & 0x7FFF;
        }
        if ((*(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags & 0x80) == 0) {
            if (restart != 0) {
                btlActionSetState((BtlAction *)action, 1);
                return;
            }
            if ((MEMBER(u16, action, BtlAction, flags) & 0x20) == 0) {
                btlActionSetState((BtlAction *)action, 0x22);
                return;
            }
            btlOrderRemoveActionAll(action);
            if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus == 1) {
                datCalcSetBadStatus(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0x80000);
                datCalcSetHp(*(s32 *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->datUnit, 0);
            }
            if (btlCheckBattleEnd() != 0) {
                *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags = *(s32 *)&((BtlBattleState *)iGpffffb3ac)->flags | 0x80;
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if ((MEMBER(u16, action, BtlAction, flags) & 0x20) != 0) {
            btlOrderRemoveActionAll(action);
            if (((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->genus == 1) {
                datCalcSetBadStatus(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0x80000);
                datCalcSetHp(*(s32 *)&((BtlUnit *)MEMBER(u8 *, action, BtlAction, unit))->datUnit, 0);
            }
            btlActionSetState((BtlAction *)action, 0x24);
            return;
        }
        if (datCalcIsDead(*(s32 *)&((BtlUnit *)*(u8* *)&((BtlAction *)action)->unit)->datUnit, 0) != 0) {
            btlTargetRecordDefeatReward(action);
            btlActionSetState((BtlAction *)action, 1);
        }
        return;
    }
}


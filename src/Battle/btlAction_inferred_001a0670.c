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
#include "btl_effect_internal.h"
typedef struct BtlPacket BtlPacket;
typedef struct BtlTarget BtlTarget;

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument, u32 extraArgument, u32 flags);
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
extern void btlUnitGetAnchorPose(u8 *, u8 *, f32 *, f32 *);
extern f32 btlTargetVectorDistance(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);



void btlActionFinishPresentation(BtlAction *action);
s64 btlPacketEnqueue(u8 *context, u32 value);
extern void btlUnitSelectRecordTable(u8 *action);
extern void btlTargetClearWork(void *work);
extern void btlDamageStart(u8 *task, u8 *action);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
extern f32 fGpffff811c;
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
extern void btlTargetClearResultBuffer(u8 *result);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *unit);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
s32 btlTargetCanControlDamagePhase(void);
s32 btlEffectFindUnitMatchingCallback(u8 *action, s32 conditionValue, s32 sideMask, s32 statusMask, s32 filterFlags,
                  s32 (*predicate)(u8 *arg0, s64 arg1));
u32 btlCountUnitRecordsById(u32 id);
u8 *func_001f99c0(u8 *, u16, s32, s32, s32);
s16 btlCameraSelectFormationIndex(void);
void btlTargetEndDamagePhase(void);
s32 btlSideCountNotBad(s32 sideMask, s32 excludedStatus);
s32 btlStatusWindowShowSlot2(u8 *unit);
u32 datCalcChkBadStatus(s32 unit, u32 badStatus);
s32 datCalcGetSkillMask(u8 *unit);
s64 datCalcFindStrongBuff(u8 *unit);
s32 datCalcIsGuarding(u16 *unitFlags);
s32 btlSoundRollStatusCure(u8 *action);
s32 btlTaskSlotLinkedSlot2(void);

BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a0670-001a0f40 */

extern void btlActionFinishPresentation(BtlAction *action);
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
/* Leave standby when the unit requests recovery or has its ready flag set. */
// FUN_001A0670
void btlActionStandbyUpdate(BtlAction *action) {
    s32 unitFlags;

    unitFlags = (s32)action->unit->flags3;
    if (unitFlags & 0x10) {
        ((BtlAction *)(action))->unk_430 = 1;
        btlActionSetState(action, 0x18);
        return;
    }
    if (unitFlags & 1) {
        btlActionSetState(action, 0x23);
    }
}

/* Initialize the action turn, handling unit recovery, delays, statuses and presentation. */
// FUN_001A06D0
void btlActionStartInit(BtlAction *action) {
    extern void btlActionSetState(BtlAction *action, u16 state);
    BtlAction *otherAction;
    s32 canAct;
    u32 threshold;
    s16 storedId;
    s32 needsDelay;

    canAct = 1;
    if (action->unit->flags3 & 0x10) {
        action->unk_430 = 2;
        btlActionSetState(action, 0x18);
        return;
    }
    otherAction = (BtlAction *)((BtlBattleState *)D_0076449C)->actions;
    while (otherAction != NULL) {
        if ((action != otherAction) && (otherAction->unk_1a & 1) &&
            (datCalcIsDead((s32)otherAction->unit->datUnit, 0) == 0) &&
            (otherAction->unit->flags3 & 0x10)) {
            canAct = 0;
            break;
        }
        otherAction = otherAction->next;
    }
    btlUnitSelectRecordTable((u8 *)action);
    if (action->flags & 0x8000) {
        btlActionSetState(action, 0x21);
        return;
    }
    btlTargetClearWork(&action->targetBlock);
    if (btlStatusWindowShowSlot2((u8 *)action) != 0) {
        action->unk_440 = (void *)&btlTaskSlotLinkedSlot2;
        action->unk_43c = 2;
        btlActionSetState(action, 0x16);
        return;
    }
    if (action->unit->genus != 0) {
        needsDelay = 0;
    } else if ((((BtlBattleState *)iGpffffb3ac)->unkA70 != -1) &&
               (threshold = btlSideCountNotBad(2, 0x80000) & 0xFFFF,
                (u32)(((BtlBattleState *)iGpffffb3ac)->unkA72 >> 1) >= threshold) &&
               ((storedId = ((BtlBattleState *)iGpffffb3ac)->unkA70) != (s16)btlCameraSelectFormationIndex())) {
        needsDelay = 1;
    } else {
        needsDelay = 0;
    }
    if ((needsDelay != 0) &&
        (datCalcChkBadStatus((s32)action->unit->datUnit, 0x180001) == 0)) {
        actionSetDelayBytes((u8 *)action, 4, 1);
        return;
    }
    if (((BtlBattleState *)iGpffffb3ac)->flags & 0x80000) {
        canAct = 0;
    }
    if (btlTargetCanControlDamagePhase() == 1) {
        ((BtlBattleState *)iGpffffb3ac)->flags |= 0x2000;
    } else {
        ((BtlBattleState *)iGpffffb3ac)->flags &= ~0x2000;
        btlTargetEndDamagePhase();
    }
    if ((s32)action->unk_28 > 0) {
        if (!(((BtlBattleState *)iGpffffb3ac)->battleFlags & 0x20)) {
            btlDamageStart((u8 *)((BtlBattleState *)iGpffffb3ac)->uiTask, (u8 *)action);
            btlPacketEnqueue(func_001f99c0((u8 *)action, 0xE, 0, 0, 0), 1);
        }
    } else {
        action->flags |= 0x400;
        action->unk_1a &= 0xFFBF;
    }
    if ((action->unk_28 == 0) && (action->unk_29 == 0)) {
        action->unk_41c = datCalcGetSkillMask((u8 *)action->unit->datUnit);
    } else {
        action->unk_41c = 0;
    }
    if ((action->unk_41c != 0) ||
        (datCalcIsGuarding((u16 *)action->unit->datUnit) != 0)) {
        canAct = 0;
    }
    if (canAct != 0) {
        if ((action->unit->genus == 0) &&
            (action->unit->charId == 1) &&
            (action->unk_28 == 0) && (action->unk_29 == 0)) {
            ((BtlBattleState *)iGpffffb3ac)->protagonistTurns += 1;
        }
        if ((s8)datCalcFindStrongBuff((u8 *)action->unit->datUnit) >= 0) {
            btlActionSetState(action, 0xA);
            return;
        }
        if (btlSoundRollStatusCure((u8 *)action) != 0) {
            btlActionSetState(action, 0xB);
            return;
        }
        btlActionSetState(action, action->state);
    }
}

/* P4 initializes and copies the complete 0x20-byte target result. The P3FES
 * state-start donor explains the aggregate mechanism, but its result is 0x1c
 * bytes. Typed action/unit members and u16 casts avoid hoisting field addresses
 * and the mask into saved registers. See the 2026-09-20 donor recovery proof. */
/* Apply turn-start passive HP/SP recovery and guard flags before selecting the next state. */
/* Keep the two packet UID loads byte-addressed: typed uid access hoisted
 * resultPacket+0x58 into a saved register and added an instruction (nd 185). */
// FUN_001A0B00
#pragma push
void btlActionStartUpdate(s64 *actionWords) {
    extern void btlTargetClearResultBuffer(u8 *result);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 action, const void *result, u16 effect, u16 targetFlags);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern u8 *btlPacketCreateHpRatio(u8 *unit);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 mode, s16 value);
    extern u16 datCalcMaxHp(DatUnit *unit);
    extern u16 datCalcMaxSp(DatUnit *unit);
    extern BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
    typedef struct ActionResult {
        s32 hpDelta;
        s32 spDelta;
        u32 statusFlags;
        u32 otherStatusFlags;
        s32 value10;
        s32 value14;
        u8 fields18[6];
        u16 flags;
    } ActionResult;
    typedef char ActionResultSizeCheck[sizeof(ActionResult) == 0x20 ? 1 : -1];
    ActionResult result;
    BtlAction *action;
    s64 passiveCue;
    s32 unitHp;
    u8 *unitPacket;
    u8 *cuePacket;
    u8 *resultPacket;
    u8 *statusPacket;
    u8 *statPacket;

    action = (BtlAction *)actionWords;
    if ((((BtlBattleState *)iGpffffb3ac)->flags & 0x80000) == 0 &&
        btlCountUnitRecordsById(0x700) == 0 && btlCountUnitRecordsById(0x504) == 0 &&
        btlCountUnitRecordsById(0x506) == 0 && btlCountUnitRecordsById(0x301) == 0 &&
        btlCountUnitRecordsById(0x104) == 0) {
        btlActionFinishPresentation((BtlAction *)actionWords);
        btlTargetClearResultBuffer((u8 *)&result);
        if (datCalcIsGuarding((u16 *)action->unit->datUnit) != 0) {
            result.flags |= 0x80;
        }
        if ((u32)action->unk_41c != 0) {
            unitHp = (u16)datCalcMaxHp(action->unit->datUnit);
            datCalcMaxSp(action->unit->datUnit);
            passiveCue = 0x16;
            if ((u32)action->unk_41c & 1) {
                result.hpDelta += ((u16)unitHp * 0x64) / 5000;
            }
            if ((u32)action->unk_41c & 2) {
                result.hpDelta += ((u16)unitHp * 0x64) / 2500;
            }
            if ((u32)action->unk_41c & 4) {
                result.hpDelta += ((u16)unitHp * 0x64) / 1666;
            }
            if ((u32)action->unk_41c & 8) {
                result.spDelta += 3;
            }
            if ((u32)action->unk_41c & 0x10) {
                result.spDelta += 5;
            }
            if ((u32)action->unk_41c & 0x20) {
                result.spDelta += 7;
            }
        }
        if ((result.flags != 0) || (result.hpDelta != 0) || (result.spDelta != 0)) {
            if ((result.hpDelta != 0) || (result.spDelta != 0)) {
                unitPacket = btlPacketCreateHpRatio((u8 *)action->unit);
                ((BtlPacket *)unitPacket)->actionUID = action->uid;
                btlPacketEnqueue(unitPacket, 1);
                if ((s16)passiveCue != -1) {
                    cuePacket = (u8 *)btlSoundCreateChannelCuePacket(0xE, 2, (u16)passiveCue);
                    ((BtlPacket *)cuePacket)->actionUID = action->uid;
                    btlPacketEnqueue(cuePacket, 1);
                }
            }
            resultPacket = (u8 *)btlTargetCreateDataPacket((s32)actionWords, (s32)actionWords, &result, 1, 1);
            ((BtlPacket *)resultPacket)->actionUID = action->uid;
            btlPacketEnqueue(resultPacket, 1);
            if ((result.hpDelta != 0) || (result.spDelta != 0)) {
                s32 unit;
                unit = (s32)(u8 *)action->unit;
                statusPacket = btlPacketCreateHitDisplay(unit, unit, -1, 0, 0, 0, 1, &result, 8);
                ((BtlPacket *)statusPacket)->dependencyKind = 4;
                ((BtlPacket *)statusPacket)->dependencyUID = *(s64 *)(resultPacket + 0x58);
                ((BtlPacket *)statusPacket)->flags &= ~0x20;
                btlPacketEnqueue(statusPacket, 3);
                if (result.hpDelta != 0) {
                    statPacket = (u8 *)btlPacketCreateUnitCounter((s32)(u8 *)action->unit, 0, 0);
                    ((BtlPacket *)statPacket)->dependencyKind = 4;
                    ((BtlPacket *)statPacket)->dependencyUID = *(s64 *)(resultPacket + 0x58);
                    ((BtlPacket *)statPacket)->flags &= ~0x20;
                    btlPacketEnqueue(statPacket, 3);
                }
            }
        }
        if ((s8)datCalcFindStrongBuff((u8 *)action->unit->datUnit) >= 0) {
            btlActionSetState((BtlAction *)actionWords, 0xA);
        } else if (btlSoundRollStatusCure((u8 *)actionWords) != 0) {
            btlActionSetState((BtlAction *)actionWords, 0xB);
        } else {
            btlActionSetState((BtlAction *)actionWords, 3);
        }
    }
}

#pragma pop
/* measured: opt_propagation off plus one named local per address term. mwcc
   keeps source operand order for `named + named` (addu off,base / addu idx,sum
   as retail) but commutes an inline product on the left (`a * k + b` emits
   addu b,a*k); the table base must be copied first so its lw leads the block. */
/* measured: btlActionSelectMove MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
/* Return a distant unit to its anchor with the motion-table movement speed. */
// FUN_001A0F40
void btlActionStartHomeInit(BtlAction *action)
{
    RwV3d anchorPosition;
    s32 tableColumn;
    u16 moveId;
    u16 formRow;
    u8 unitKind;
    BtlUnit *battleUnit;
    u8 *movePacket;
    u32 sourceOffset;
    u32 tbl;
    u32 sum;
    u32 idx4;

    battleUnit = action->unit;
    if (((((BtlBattleState *)iGpffffb3ac)->flags & 0x1000) != 0) &&
        ((((BtlAction *)(action))->unk_1a & 1) != 0) &&
        (battleUnit->genus == 0)) {
        ((BtlAction *)(action))->state = 9;
    }
    if (btlActionCanRunNow(action) != 0) {
        btlActionSetState(action, ((BtlAction *)(action))->state);
        return;
    }
    btlUnitGetAnchorPose((u8 *)battleUnit, (u8 *)&anchorPosition, 0, NULL);
    if (!(btlTargetVectorDistance(&battleUnit->pos, &anchorPosition) <= 75.0f)) {
        moveId = 2;
        tableColumn = (u16)(!(iGpffffb3b8[
            (((BtlAction *)(action))->unk_6e * 0x28)] & 2));
        formRow = action->unit->datUnit->id;
        unitKind = (((BtlAction *)(action)))->unit->genus;
        switch (unitKind) {
        case 0:
            break;
        case 1:
            tbl = (u32)iGpffffb3cc;
            sourceOffset = (u32)formRow * 0xE8;
            sum = sourceOffset + tbl;
            idx4 = (u16)tableColumn * 4;
            /* Retain the materialized table byte address: this measured source
             * order preserves retail addu operands for the movement row at +0x24. */
            moveId = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        movePacket = (u8 *)btlUnitCreateMovePacket(
            ((BtlAction *)(action))->unit, &anchorPosition, D_005F6D20[moveId & 0xFFFF], 0);
        ((BtlPacket *)movePacket)->actionUID = (s64)action->uid;
        btlPacketEnqueue(movePacket, 1);
        return;
    }
    btlActionSetState(action, ((BtlAction *)(action))->state);
}


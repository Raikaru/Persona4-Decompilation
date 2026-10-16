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
typedef struct BtlPacket BtlPacket;
typedef struct BtlTarget BtlTarget;

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 kind, u32 a, u32 b, u32 c);
static inline u8 *actionTargetPacketBytes(u8 *action, u16 kind, u32 a, u32 b, u32 c)
{
    return (u8 *)btlTargetCreateTargetPacket((u32)action, kind, a, b, c);
}
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
static inline void actionSetDelayBytes(u8 *action, s32 state, s32 delay)
{
    btlActionSetStateWithDelay((BtlAction *)action, (u16)state, (u16)delay);
}
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
static inline u8 *actionRotatePacketBytes(u8 *unit, void *rot, s32 flags)
{
    return (u8 *)btlUnitCreateRotatePacket((BtlUnit *)unit, (const RwV3d *)rot, (u32)flags);
}
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
static inline u8 *actionRecoveryPacketBytes(BtlUnit *unit)
{
    return (u8 *)btlUnitCreateMotionSettlePacket(unit);
}
extern BtlPacket *btlPacketCreateEffectCounter(s32 unit, s32 message);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern void func_00194ff0(u8 *, u8 *, f32 *, f32 *);
extern f32 btlTargetVectorDistance(const RwV3d *, const RwV3d *);
extern BtlPacket *btlUnitCreateMovePacket(BtlUnit *, const RwV3d *, f32, u32);
extern u8 *iGpffffb3cc;
extern f32 D_005F6D20[];

void btlActionSetState(BtlAction *action, u16 state);
static inline s32 func_001a_add_offset(s32 offset, s32 base)
{
    return offset + base;
}
static inline s32 func_001a_fix_var(s32 value)
{
    if (value == 0) {
        value = -1;
    }
    return value;
}



void btlActionFinishPresentation(BtlAction *action);
s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
extern void btlUnitSelectRecordTable(u8 *arg0);
extern void btlTargetClearWork(void *arg0);
extern void btlDamageStart(u8 *arg0, u8 *arg1);

extern u8 *D_0076449C;
extern u8 *iGpffffb3ac;

extern u8 *iGpffffb3b8;
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *target, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
extern f32 fGpffff811c;
extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
extern void func_001f0a10(u8 *arg0);
extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
extern u8 *btlPacketCreateHpRatio(u8 *arg0);
extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
s32 func_001eb860(void);
s32 btlEffectFindUnitMatchingCallback(u8 *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4,
                  s32 (*arg5)(u8 *arg0, s64 arg1));
u32 btlCountUnitRecordsById(u32 arg0);
u8 *func_001f99c0(u8 *arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
s16 func_001d15a0(void);
void func_001eb7f0(void);
s32 btlSideCountNotBad(s32 arg0, s32 arg1);
s32 func_001fabe0(u8 *arg0);
u32 datCalcChkBadStatus(s32 arg0, u32 arg1);
s32 datCalcGetSkillMask(u8 *arg0);
s64 datCalcFindStrongBuff(u8 *arg0);
s32 datCalcIsStatusBlocked(u16 *arg0);
s32 func_001f6770(u8 *arg0);
s32 func_001fac30(void);

BtlPacket *btlSoundCreateChannelCuePacket(u16 arg0, u16 arg1, u16 arg2);
extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a0670-001a0f40 */

extern void btlActionFinishPresentation(BtlAction *action);
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: close loop-invariant probe for 001A0140. */
// FUN_001A0670
void btlActionStandbyUpdate(BtlAction *action) {
    s32 unitFlags;

    unitFlags = (s32)action->unit->flags3;
    if (unitFlags & 0x10) {
        *(s16 *)((u8 *)action + 0x430) = 1;
        btlActionSetState(action, 0x18);
        return;
    }
    if (unitFlags & 1) {
        btlActionSetState(action, 0x23);
    }
}

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
    otherAction = *(BtlAction **)(D_0076449C + 0x174);
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
    if (func_001fabe0((u8 *)action) != 0) {
        action->unk_440 = (void *)&func_001fac30;
        action->unk_43c = 2;
        btlActionSetState(action, 0x16);
        return;
    }
    if (action->unit->genus != 0) {
        needsDelay = 0;
    } else if ((*(s16 *)(iGpffffb3ac + 0xA70) != -1) &&
               (threshold = btlSideCountNotBad(2, 0x80000) & 0xFFFF,
                (u32)(*(s16 *)(iGpffffb3ac + 0xA72) >> 1) >= threshold) &&
               ((storedId = *(s16 *)(iGpffffb3ac + 0xA70)) != (s16)func_001d15a0())) {
        needsDelay = 1;
    } else {
        needsDelay = 0;
    }
    if ((needsDelay != 0) &&
        (datCalcChkBadStatus((s32)action->unit->datUnit, 0x180001) == 0)) {
        actionSetDelayBytes((u8 *)action, 4, 1);
        return;
    }
    if (*(s32 *)(iGpffffb3ac + 0xC) & 0x80000) {
        canAct = 0;
    }
    if (func_001eb860() == 1) {
        *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
    } else {
        *(s32 *)(iGpffffb3ac + 0xC) &= ~0x2000;
        func_001eb7f0();
    }
    if ((s32)action->unk_28 > 0) {
        if (!(*(s32 *)(iGpffffb3ac + 0x10) & 0x20)) {
            btlDamageStart(*(u8 **)(iGpffffb3ac + 0xDD4), (u8 *)action);
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
        (datCalcIsStatusBlocked((u16 *)action->unit->datUnit) != 0)) {
        canAct = 0;
    }
    if (canAct != 0) {
        if ((action->unit->genus == 0) &&
            (action->unit->charId == 1) &&
            (action->unk_28 == 0) && (action->unk_29 == 0)) {
            *(s32 *)(iGpffffb3ac + 0x20) += 1;
        }
        if ((s8)datCalcFindStrongBuff((u8 *)action->unit->datUnit) >= 0) {
            btlActionSetState(action, 0xA);
            return;
        }
        if (func_001f6770((u8 *)action) != 0) {
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
// FUN_001A0B00
#pragma push
void btlActionStartUpdate(s64 *arg0) {
    extern void func_001f0a10(u8 *arg0);
    extern BtlPacket *btlTargetCreateDataPacket(s32 source, s32 target, const void *result, u16 effect, u16 targetFlags);
    extern u8 *btlPacketCreateHitDisplay(s32 source, s32 target, s32 id, u16 effect, u16 targetFlags, u16 hitIndex, u16 hitCount, const void *result, u16 flags);
    extern u8 *btlPacketCreateHpRatio(u8 *arg0);
    extern u8 *btlPacketCreateUnitCounter(s32 unit, s8 kind, s16 value);
    typedef struct DatUnit DatUnit;
    typedef struct ActionUnitView {
        u8 unknown00[0xA64];
        DatUnit *data;
    } ActionUnitView;
    typedef struct ActionView {
        s64 uid;
        u8 unknown08[0x28];
        ActionUnitView *unit;
        u8 unknown34[0x3E8];
        u32 passiveFlags;
    } ActionView;
    extern u16 datCalcMaxHp(DatUnit *arg0);
    extern u16 datCalcMaxSp(DatUnit *arg0);
    extern BtlPacket *btlSoundCreateChannelCuePacket(u16 channel, u16 cue, u16 variant);
    extern void btlActionSetState(s64 *arg0, u16 arg1);
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
    ActionView *action;
    s64 passiveCue;
    s32 unitHp;
    u8 *unitPacket;
    u8 *cuePacket;
    u8 *resultPacket;
    u8 *statusPacket;
    u8 *statPacket;

    action = (ActionView *)arg0;
    if ((*(s32 *)(iGpffffb3ac + 0xC) & 0x80000) == 0 &&
        btlCountUnitRecordsById(0x700) == 0 && btlCountUnitRecordsById(0x504) == 0 &&
        btlCountUnitRecordsById(0x506) == 0 && btlCountUnitRecordsById(0x301) == 0 &&
        btlCountUnitRecordsById(0x104) == 0) {
        btlActionFinishPresentation((BtlAction *)arg0);
        func_001f0a10((u8 *)&result);
        if (datCalcIsStatusBlocked((u16 *)action->unit->data) != 0) {
            result.flags |= 0x80;
        }
        if (action->passiveFlags != 0) {
            unitHp = (u16)datCalcMaxHp(action->unit->data);
            datCalcMaxSp(action->unit->data);
            passiveCue = 0x16;
            if (action->passiveFlags & 1) {
                result.hpDelta += ((u16)unitHp * 0x64) / 5000;
            }
            if (action->passiveFlags & 2) {
                result.hpDelta += ((u16)unitHp * 0x64) / 2500;
            }
            if (action->passiveFlags & 4) {
                result.hpDelta += ((u16)unitHp * 0x64) / 1666;
            }
            if (action->passiveFlags & 8) {
                result.spDelta += 3;
            }
            if (action->passiveFlags & 0x10) {
                result.spDelta += 5;
            }
            if (action->passiveFlags & 0x20) {
                result.spDelta += 7;
            }
        }
        if ((result.flags != 0) || (result.hpDelta != 0) || (result.spDelta != 0)) {
            if ((result.hpDelta != 0) || (result.spDelta != 0)) {
                unitPacket = btlPacketCreateHpRatio((u8 *)action->unit);
                *(s64 *)(unitPacket + 0x60) = action->uid;
                btlPacketEnqueue(unitPacket, 1);
                if ((s16)passiveCue != -1) {
                    cuePacket = (u8 *)btlSoundCreateChannelCuePacket(0xE, 2, (u16)passiveCue);
                    *(s64 *)(cuePacket + 0x60) = action->uid;
                    btlPacketEnqueue(cuePacket, 1);
                }
            }
            resultPacket = (u8 *)btlTargetCreateDataPacket((s32)arg0, (s32)arg0, &result, 1, 1);
            *(s64 *)(resultPacket + 0x60) = action->uid;
            btlPacketEnqueue(resultPacket, 1);
            if ((result.hpDelta != 0) || (result.spDelta != 0)) {
                s32 unit;
                unit = (s32)(u8 *)action->unit;
                statusPacket = btlPacketCreateHitDisplay(unit, unit, -1, 0, 0, 0, 1, &result, 8);
                *(s8 *)(statusPacket + 0) = 4;
                *(s64 *)(statusPacket + 8) = *(s64 *)(resultPacket + 0x58);
                *(u8 *)(statusPacket + 0x47) &= ~0x20;
                btlPacketEnqueue(statusPacket, 3);
                if (result.hpDelta != 0) {
                    statPacket = (u8 *)btlPacketCreateUnitCounter((s32)(u8 *)action->unit, 0, 0);
                    *(s8 *)(statPacket + 0) = 4;
                    *(s64 *)(statPacket + 8) = *(s64 *)(resultPacket + 0x58);
                    *(u8 *)(statPacket + 0x47) &= ~0x20;
                    btlPacketEnqueue(statPacket, 3);
                }
            }
        }
        if ((s8)datCalcFindStrongBuff((u8 *)action->unit->data) >= 0) {
            btlActionSetState(arg0, 0xA);
        } else if (func_001f6770((u8 *)arg0) != 0) {
            btlActionSetState(arg0, 0xB);
        } else {
            btlActionSetState(arg0, 3);
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
// FUN_001A0F40
void btlActionStartHomeInit(BtlAction *action)
{
    RwV3d sp30;
    s32 tableColumn;
    u16 moveId;
    u16 formRow;
    u8 unitKind;
    u8 *battleUnit;
    u8 *movePacket;
    u32 source_offset;
    u32 tbl;
    u32 sum;
    u32 idx4;

    battleUnit = *(u8 **)((u8 *)action + 0x30);
    if (((*(s32 *)(iGpffffb3ac + 0xC) & 0x1000) != 0) &&
        ((*(u16 *)((u8 *)action + 0x1A) & 1) != 0) &&
        (battleUnit[0xA2] == 0)) {
        *(u16 *)((u8 *)action + 0x14) = 9;
    }
    if (func_001b0e90(action) != 0) {
        btlActionSetState(action, *(u16 *)((u8 *)action + 0x14));
        return;
    }
    func_00194ff0(battleUnit, (u8 *)&sp30, 0, NULL);
    if (!(btlTargetVectorDistance((const RwV3d *)(battleUnit + 4), &sp30) <= 75.0f)) {
        moveId = 2;
        tableColumn = (u16)(!(iGpffffb3b8[
            (*(u16 *)((u8 *)action + 0x6E) * 0x28)] & 2));
        formRow = *(u16 *)(*(u8 **)(*(u8 **)((u8 *)action + 0x30) + 0xA64) + 2);
        unitKind = *(u8 *)(*(u8 **)((u8 *)action + 0x30) + 0xA2);
        switch (unitKind) {
        case 0:
            break;
        case 1:
            tbl = (u32)iGpffffb3cc;
            source_offset = (u32)formRow * 0xE8;
            sum = source_offset + tbl;
            idx4 = (u16)tableColumn * 4;
            moveId = *(u16 *)(idx4 + sum + 0x24);
            break;
        }
        movePacket = (u8 *)btlUnitCreateMovePacket(
            *(BtlUnit **)((u8 *)action + 0x30), &sp30, D_005F6D20[moveId & 0xFFFF], 0);
        *(s64 *)(movePacket + 0x60) = *(s64 *)action;
        btlPacketEnqueue(movePacket, 1);
        return;
    }
    btlActionSetState(action, *(u16 *)((u8 *)action + 0x14));
}


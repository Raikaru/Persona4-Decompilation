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
#include "dat_skill_entry_internal.h"
typedef struct BtlPacket BtlPacket;
typedef struct BtlTarget BtlTarget;
extern BtlPacket *btlUnitCreateLookAtDeactivatePacket(BtlUnit *unit, u16 flags);

/* Existing byte-view callers use these adapters to the provider definitions. */
extern BtlPacket *btlTargetCreateTargetPacket(u32 action, u16 command, u32 argument, u32 extraArgument, u32 flags);
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
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
static inline void *actionMessagePacketBytes(s32 unit, s32 message)
{
    return btlPacketCreateEffectCounter(unit, message);
}
extern u8 *iGpffffb3cc; /* enemy visual records, stride 0xE8 */
extern f32 D_005F6D20[];

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
BtlPacket *btlFormationCreateSlotPacket(u16 groupMask, u16 flags);
s64 btlPacketEnqueue(u8 *context, u32 value);

extern u8 *D_0076449C; /* active battle context */
extern u8 *iGpffffb3ac; /* active battle context */
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);

extern u8 *iGpffffb3b8; /* skill table, DatSkillEntry rows */
u8 datCalcGetCharacterTableKind(u8 *unit);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
static inline u8 *actionLookAtUnit(u8 *unit, u8 *target, s32 flags)
{
    return (u8 *)btlUnitCreateLookAtUnitPacket((BtlUnit *)unit, (BtlUnit *)target, (u16)flags);
}
u8 *btlUnitCreateMotionRequestPacket(u8 *unit, u16 value);
extern f32 fGpffff811c;
BtlPacket *btlMainCreateColorSetPacket(s32 arg);
BtlPacket *btlEffectCreateReleasePacket(u16 mode);
u8 *btlPacketCreateFinishEffect(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
s32 btlEffectFindUnitMatchingCallback(u8 *action, s32 conditionValue, s32 sideMask, s32 statusMask, s32 filterFlags,
                  s32 (*predicate)(u8 *arg0, s64 arg1));

extern f32 D_0076144C;

/* Source unit: src/promoted/code1_001a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_001a.c; members 001a0140-001a05f0 */

/* Returns 1 when a target row of the action's target list carries a flag: kind 0
   scans row +0xF8 for BTL_STATUS_DOWN (0x100000); kind 1 scans row +0x10E for 0x4
   (the 0x4 setter is not identified; the damage calc writes 0x8/0x20/0x40 there). */
// FUN_001A0140
/* measured: loop-invariant probe for 001A0140 preheader materialization. */
/* measured: func_001a0140 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
s32 btlActionAnyTargetDownOrHitFlagged(u8 *action)
{
    /* measured: typed target-array indexing reverses two addu operands;
     * the +0x38 array loads keep the retail base-first address shape. */
    s32 targetIndex;
    u8 unitKind;

    unitKind = *(u8 *)&((BtlUnit *)(*(u8 **)&((BtlAction *)action)->unit))->genus;
    switch (unitKind) {
    case 0:
    {
        s32 hitIndex;
        s32 targetCount;
        s32 hitCount;
        s32 statusMask;
        u8 *target;

        targetIndex = 0;
        targetCount = ((BtlAction *)action)->unk_6a;
        statusMask = 0x100000;
        while ((targetIndex & 0xFFFF) < targetCount) {
            target = *(u8 **)(action + ((u16)targetIndex * 4) + 0x38);
            hitCount = ((BtlAction *)target)->targetBlock.hitRowCount;
            hitIndex = 0;
            while ((hitIndex & 0xFFFF) < hitCount) {
                if ((*(s32 *)&((BtlAction *)target)->targetBlock.hitRows[(u16)hitIndex].addedStatus & statusMask) != 0) {
                    return 1;
                }
                hitIndex = (hitIndex + 1) & 0xFFFF;
            }
            targetIndex = (targetIndex + 1) & 0xFFFF;
        }
        break;
    }
    case 1:
    {
        s32 enemyTargetIndex;
        s32 enemyHitIndex;
        s32 enemyTargetCount;
        s32 enemyHitCount;
        u8 *enemyTarget;

        enemyTargetIndex = 0;
        enemyTargetCount = *(u16 *)&((BtlAction *)action)->unk_6a;
        while ((enemyTargetIndex & 0xFFFF) < enemyTargetCount) {
            enemyTarget = *(u8 **)(action + ((u16)enemyTargetIndex * 4) + 0x38);
            enemyHitCount = ((BtlAction *)enemyTarget)->targetBlock.hitRowCount;
            enemyHitIndex = 0;
            while ((enemyHitIndex & 0xFFFF) < enemyHitCount) {
                if ((((BtlAction *)enemyTarget)->targetBlock.hitRows[(u16)enemyHitIndex].flags & 4) != 0) {
                    return 1;
                }
                enemyHitIndex = (enemyHitIndex + 1) & 0xFFFF;
            }
            enemyTargetIndex = (enemyTargetIndex + 1) & 0xFFFF;
        }
        break;
    }
    default:
        break;
    }
    return 0;
}

/* measured: close loop-invariant probe for 001A0140. */
/* Choose the two effect indices from the action flags and unit category. */
// FUN_001A0290
void btlActionGetEffectIndices(BtlAction *action, u16 skillId, u8 *effectIndices)
{
    /* measured: repeated typed output[1] stores retain output+2 in a saved
     * register (300B vs 288B); keep the second output byte-addressed. */
    s32 slotOffset;
    s32 category;
    BtlUnit *battleUnit;

    if (action->flags & 0x4000) {
        ((s16 *)effectIndices)[0] = 0x24;
        *(s16 *)(effectIndices + 2) = -1;
        return;
    }
    ((s16 *)effectIndices)[0] = 0;
    *(s16 *)(effectIndices + 2) = 3;
    slotOffset = (skillId & 0xFFFF) * 0x28;
    if (((DatSkillEntry *)(iGpffffb3b8 + slotOffset))->flags00 & 2) {
        battleUnit = action->unit;
        if (battleUnit->genus == 0) {
            category = datCalcGetCharacterTableKind((u8 *)battleUnit->datUnit) & 0xFF;
            switch (category) {
            case 0:
            case 1:
            case 6:
                ((s16 *)effectIndices)[0] = 1;
                *(s16 *)(effectIndices + 2) = 4;
                return;
            case 5:
                ((s16 *)effectIndices)[0] = 2;
                *(s16 *)(effectIndices + 2) = 5;
                return;
            case 2:
            case 3:
            case 4:
                break;
            }
        } else {
            switch (battleUnit->charId) {
            case 0x109:
                ((s16 *)effectIndices)[0] = 2;
                *(s16 *)(effectIndices + 2) = 5;
                break;
            }
        }
    }
}

/* Enqueue the requested presentation cleanup packets with the action UID. */
// FUN_001A03B0
void btlActionFinishPresentation(BtlAction *action)
{
    /* measured: a repeated typed unit load saves listUnit+0x30 in s2
     * (580B versus the 576B window); retain the second unit reload. */
    u8 *lookAtDeactivatePacket;
    u8 *ambientPacket;
    u8 *unitPacket;
    u8 *effectPacket;
    u8 *subPacket;
    u8 *cameraPacket;
    u8 *endPacket;
    u8 *battleCtxAlt;
    u8 *battleCtx;
    u8 *battleCtxClear;
    u8 *listUnit;

    battleCtx = D_0076449C;
    if (*(s32 *)&((BtlBattleState *)battleCtx)->flags & 0x400000) {
        if (((BtlBattleState *)battleCtx)->actionEndFlags & 0x20) {
            lookAtDeactivatePacket = (u8 *)btlUnitCreateLookAtDeactivatePacket(0, 3);
            *(s64 *)&((BtlPacket *)lookAtDeactivatePacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(lookAtDeactivatePacket, 1);
        }
        if (((BtlBattleState *)D_0076449C)->actionEndFlags & 2) {
            ambientPacket = (u8 *)btlFormationCreateSlotPacket(3, 0xFFF);
            *(s64 *)&((BtlPacket *)ambientPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(ambientPacket, 0);
        }
        battleCtxAlt = D_0076449C;
        if (((BtlBattleState *)battleCtxAlt)->actionEndFlags & 1) {
            listUnit = ((BtlBattleState *)battleCtxAlt)->actions;
            while (listUnit != NULL) {
                if ((((BtlAction *)listUnit)->unk_1a & 1) &&
                    datCalcIsDead(*(s32 *)&((BtlUnit *)(*(u8 **)&((BtlAction *)listUnit)->unit))->datUnit, 0) == 0) {
                    unitPacket = btlUnitCreateMotionRequestPacket(*(u8 **)(listUnit + 0x30), 0);
                    *(s64 *)&((BtlPacket *)unitPacket)->actionUID = *(s64 *)action;
                    btlPacketEnqueue(unitPacket, 0);
                }
                listUnit = *(u8 **)&((BtlAction *)listUnit)->next;
            }
        }
        if (*(u16 *)&((BtlBattleState *)D_0076449C)->actionEndFlags & 0x10) {
            effectPacket = (u8 *)btlMainCreateColorSetPacket(0);
            *(s64 *)&((BtlPacket *)effectPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(effectPacket, 1);
        }
        if (*(u16 *)&((BtlBattleState *)D_0076449C)->actionEndFlags & 8) {
            subPacket = (u8 *)btlEffectCreateReleasePacket(5);
            *(s64 *)&((BtlPacket *)subPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(subPacket, 1);
        }
        if (*(u16 *)&((BtlBattleState *)D_0076449C)->actionEndFlags & 4) {
            cameraPacket = (u8 *)btlCameraCreateSetStatePacket(action, 0x24);
            *(s64 *)&((BtlPacket *)cameraPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(cameraPacket, 0);
        }
        if (*(u16 *)&((BtlBattleState *)D_0076449C)->actionEndFlags & 0x40) {
            endPacket = btlPacketCreateFinishEffect();
            *(s64 *)&((BtlPacket *)endPacket)->actionUID = *(s64 *)action;
            btlPacketEnqueue(endPacket, 0);
        }
        *(u16 *)&((BtlBattleState *)D_0076449C)->actionEndFlags = 0;
        battleCtxClear = D_0076449C;
        *(s32 *)&((BtlBattleState *)battleCtxClear)->flags &= 0xFFBFFFFF;
    }
}

/* A valid action with a linked child is active when the child's model is loaded. */
// FUN_001A05F0
s32 btlActionLinkedUnitIsActive(BtlAction *action) {
    u16 flags;
    u8 *unitState;

    flags = action->unk_1a;
    if ((flags & 1) == 0) {
        return 0;
    }
    unitState = (u8 *)action->unit->childUnit;
    if ((flags & 0x10) == 0) {
        return 0;
    }
    return (*(s32 *)&((BtlUnit *)unitState)->flags2 & 2) != 0;
}


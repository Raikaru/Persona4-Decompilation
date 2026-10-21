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
extern void btlActionSetStateWithDelay(BtlAction *action, u16 state, u16 delay);
extern BtlPacket *btlUnitCreateRotatePacket(BtlUnit *unit, const RwV3d *rot, u32 flags);
extern BtlPacket *btlUnitCreateMotionSettlePacket(BtlUnit *unit);
extern BtlPacket *btlPacketCreateEffectCounter(s32 effect, s32 limit);
extern u8 *iGpffffb3cc; /* enemy visual records, stride 0xE8 */
extern f32 D_005F6D20[];


void btlActionFinishPresentation(BtlAction *action);
BtlPacket *btlFormationCreateSlotPacket(u16 groupMask, u16 flags);
s64 btlPacketEnqueue(u8 *context, u32 value);

extern u8 *D_0076449C; /* active battle context */
extern u8 *iGpffffb3ac; /* active battle context */
BtlPacket *btlCameraCreateSetStatePacket(BtlAction *action, u16 state);

extern u8 *iGpffffb3b8; /* skill table, DatSkillEntry rows */
u8 datCalcGetCharacterTableKind(u8 *unit);
extern BtlPacket *btlUnitCreateLookAtUnitPacket(BtlUnit *unit, BtlUnit *targetUnit, u16 flags);
u8 *btlUnitCreateMotionRequestPacket(u8 *unit, u16 value);
extern f32 fGpffff811c;
BtlPacket *btlMainCreateColorSetPacket(s32 arg);
BtlPacket *btlEffectCreateReleasePacket(u16 mode);
u8 *btlPacketCreateFinishEffect(void);
u32 datCalcIsDead(s32 unit, s32 hpDelta);
s32 btlEffectFindUnitMatchingCallback(u8 *action, s32 conditionValue, s32 sideMask, s32 statusMask, s32 filterFlags,
                  s32 (*predicate)(u8 *arg0, s64 arg1));

extern f32 D_0076144C;

/* Returns 1 when a target in the action's target list carries a flag: kind 0 checks
 * BTL_STATUS_DOWN, kind 1 checks hit flag 0x4 (setter unidentified). measured: retail hoists loop-
 * invariant loads into the target-scan loop preheader; this function needs loop-invariant
 * optimization on. */
// FUN_001A0140
#pragma opt_loop_invariants on
s32 btlActionAnyTargetDownOrHitFlagged(u8 *action)
{
    /* measured: retail adds the target-array base before the index, which only the byte-offset
     * loads reproduce. */
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
            target = ((BtlAction *)action)->targets[(u16)targetIndex];
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
            enemyTarget = ((BtlAction *)action)->targets[(u16)enemyTargetIndex];
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

/* Choose the two effect indices from the action flags and unit category. */
// FUN_001A0290
void btlActionGetEffectIndices(BtlAction *action, u16 skillId, u8 *effectIndices)
{
    s16 *outputIndices = (s16 *)effectIndices;

    /* measured: typed output[1] stores keep output+2 in a saved register; retail addresses the
     * second output by byte offset. */
    s32 slotOffset;
    s32 category;
    BtlUnit *battleUnit;

    if (action->flags & 0x4000) {
        ((s16 *)effectIndices)[0] = 0x24;
        ((s16 *)effectIndices)[1] = -1;
        return;
    }
    ((s16 *)effectIndices)[0] = 0;
    ((s16 *)effectIndices)[1] = 3;
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
                outputIndices[1] = 4;
                return;
            case 5:
                ((s16 *)effectIndices)[0] = 2;
                outputIndices[1] = 5;
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
                outputIndices[1] = 5;
                break;
            }
        }
    }
}

/* Enqueue the requested presentation cleanup packets with the action UID. */
// FUN_001A03B0
void btlActionFinishPresentation(BtlAction *action)
{
    BtlAction *typedListUnit;
    /* measured: retail reloads the list unit a second time instead of keeping it in a saved
     * register. */
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
            typedListUnit = (BtlAction *)listUnit;
            while (listUnit != NULL) {
                if ((((BtlAction *)listUnit)->unk_1a & 1) &&
                    datCalcIsDead(*(s32 *)&((BtlUnit *)(*(u8 **)&((BtlAction *)listUnit)->unit))->datUnit, 0) == 0) {
                    unitPacket = btlUnitCreateMotionRequestPacket(*(u8 * *)&typedListUnit->unit, 0);
                    *(s64 *)&((BtlPacket *)unitPacket)->actionUID = *(s64 *)action;
                    btlPacketEnqueue(unitPacket, 0);
                }
                listUnit = *(u8 **)&((BtlAction *)listUnit)->next;
                typedListUnit = (BtlAction *)listUnit;
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


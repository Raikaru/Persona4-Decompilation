/* Inferred unit: no __FILE__ evidence; boundaries from shared TU with static helper; members 001b0d00-001b1450 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "member_access.h"
#include "type.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"

extern s32 iGpffffb3ac;
/* Canonical grouped function declarations. */
static u32 btlOrderRemoveAction(BtlAction** actions, u32 capacity, BtlAction* action);
/* Source unit: src/Battle/btlOrder_001b0d00.c */

extern s32 btlActionQueueMoveToBack(u8 *action);
// FUN_001B0D00
/* Remove the first matching action, compacting the fixed-capacity queue. */
static u32 btlOrderRemoveAction(BtlAction** actions, u32 capacity, BtlAction* action)
{
    BtlAction* current;
    s32 index;

    for (index = 0; index < capacity; index++)
    {
        current = *actions;
        if (current != action)
        {
            actions++;
        }
        else
        {
            break;
        }
    }

    if (index == capacity)
    {
        return 0;
    }

    for (; index < capacity - 1; index++)
    {
        *actions = *(actions + 1);
        actions++;
    }

    *actions = NULL;

    return 1;
}

/* Remove all occurrences from the twelve-slot execution queue.
 * Return whether at least one queued action was removed. */
// FUN_001B0DD0
s32 btlOrderRemoveActionAll(u8 *action)
{
    BtlAction **actions;
    s32 result;

    actions = (BtlAction **)((BtlBattleState *)iGpffffb3ac)->actionQueue;
    result = 0;
    while (btlOrderRemoveAction(actions, 0xC, (BtlAction *)action) == 1) {
        result = 1;
    }
    return result;
}

#pragma push
#pragma opt_rebuildconditionals on
#pragma auto_inline on
// FUN_001B13C0
/* Consume follow-up bit 4, or move the action to the back when flag 8 is set. */
void btlOrderQueueAction(u8 *action)
{
    u8 *queuedAction;
    /* MEMBER retains byte-base aliasing only at the measured action-flag store. */
    u8 *battle;

    queuedAction = action;
    if ((((BtlAction *)(queuedAction))->flags & 4) != 0) {
        btlOrderRemoveAction((BtlAction **)((u8 *)iGpffffb3ac + 0x2CC), 0xC, (BtlAction *)queuedAction);
        MEMBER(u16, queuedAction, BtlAction, flags) &= 0xFFFB;
        goto done;
    }
    battle = (u8 *)iGpffffb3ac;
    if ((((BtlBattleState *)(battle))->flags & 8) != 0) {
        /* The selected-action word stores the pointer as its original integer handle. */
        ((BtlBattleState *)(battle))->unk298 = (s32)(queuedAction);
        btlActionQueueMoveToBack(queuedAction);
    }
done:
    battle = (u8 *)iGpffffb3ac;
    ((BtlBattleState *)(battle))->queueFlags |= 8;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma auto_inline on
// FUN_001B1450
/* Route pending follow-ups through the queue, otherwise select the current action. */
void btlOrderSetCurrentAction(u8 *action)
{
    /* MEMBER retains byte-base aliasing only at the measured action-flag store. */
    u8 *battle;
    if ((((BtlAction *)(action))->flags & 4) != 0) {
        btlOrderQueueAction(action);
    } else {
        battle = (u8 *)iGpffffb3ac;
        if ((((BtlBattleState *)(battle))->flags & 8) != 0) {
            /* The selected-action word stores the pointer as its original integer handle. */
            ((BtlBattleState *)(battle))->unk298 = (s32)(action);
        }
        battle = (u8 *)iGpffffb3ac;
        ((BtlBattleState *)(battle))->queueFlags |= 8;
    }
}
#pragma pop

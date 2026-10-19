/* Inferred unit: no __FILE__ evidence; boundaries from shared TU with static helper; members 001b0d00-001b1450 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
#include "btl_action_internal.h"
#include "btl_effect_internal.h"

extern s32 iGpffffb3ac;
/* Canonical grouped function declarations. */
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action);
/* Source unit: src/Battle/btlOrder_001b0d00.c */

extern s32 btlActionQueueMoveToBack(u8 *arg0);
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

// FUN_001B0DD0
/* Remove every occurrence of the action from the execution queue. */
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
    /* Proven BtlAction/BtlBattleState fields stay raw: typed access loses MATCH. */
    u8 *battle;

    queuedAction = action;
    if ((*(u16 *)(queuedAction + 0x18) & 4) != 0) {
        btlOrderRemoveAction((BtlAction **)((u8 *)iGpffffb3ac + 0x2CC), 0xC, (BtlAction *)queuedAction);
        *(u16 *)(queuedAction + 0x18) &= 0xFFFB;
        goto done;
    }
    battle = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(battle + 0xC) & 8) != 0) {
        /* +0x298 stores the selected action; retain pointer-typed store for MWCC. */
        *(u8 **)(battle + 0x298) = queuedAction;
        btlActionQueueMoveToBack(queuedAction);
    }
done:
    battle = (u8 *)iGpffffb3ac;
    *(u16 *)(battle + 0x290) |= 8;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma auto_inline on
// FUN_001B1450
/* Route pending follow-ups through the queue, otherwise select the current action. */
void btlOrderSetCurrentAction(u8 *action)
{
    /* Proven BtlAction/BtlBattleState fields stay raw: typed access loses MATCH. */
    u8 *battle;
    if ((*(u16 *)(action + 0x18) & 4) != 0) {
        btlOrderQueueAction(action);
    } else {
        battle = (u8 *)iGpffffb3ac;
        if ((*(s32 *)(battle + 0xC) & 8) != 0) {
            /* +0x298 stores the selected action; retain pointer-typed store for MWCC. */
            *(u8 **)(battle + 0x298) = action;
        }
        battle = (u8 *)iGpffffb3ac;
        *(u16 *)(battle + 0x290) |= 8;
    }
}
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from shared TU with static helper; members 001b0d00-001b1450 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
typedef struct BtlAction BtlAction;

extern s32 iGpffffb3ac;
/* Canonical grouped function declarations. */
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action);
/* Source unit: src/Battle/btlOrder_001b0d00.c */

extern s32 btlActionQueueMoveToBack(u8 *arg0);
// FUN_001B0D00
static u32 btlOrderRemoveAction(BtlAction** actions, u32 arrSize, BtlAction* action)
{
    BtlAction* curr;
    s32 i;

    for (i = 0; i < arrSize; i++)
    {
        curr = *actions;
        if (curr != action)
        {
            actions++;
        }
        else
        {
            break;
        }
    }

    if (i == arrSize)
    {
        return 0;
    }

    for (; i < arrSize - 1; i++)
    {
        *actions = *(actions + 1);
        actions++;
    }

    *actions = NULL;

    return 1;
}

// FUN_001B0DD0
s32 btlOrderRemoveActionAll(u8 *arg0)
{
    BtlAction **actions;
    s32 result;

    actions = (BtlAction **)((u8 *)iGpffffb3ac + 0x29C);
    result = 0;
    while (btlOrderRemoveAction(actions, 0xC, (BtlAction *)arg0) == 1) {
        result = 1;
    }
    return result;
}

#pragma push
#pragma opt_rebuildconditionals on
#pragma auto_inline on
// FUN_001B13C0
void btlOrderQueueAction(u8 *arg0)
{
    u8 *ptr;
    u8 *global;

    ptr = arg0;
    if ((*(u16 *)(ptr + 0x18) & 4) != 0) {
        btlOrderRemoveAction((BtlAction **)((u8 *)iGpffffb3ac + 0x2CC), 0xC, (BtlAction *)ptr);
        *(u16 *)(ptr + 0x18) &= 0xFFFB;
        goto done;
    }
    global = (u8 *)iGpffffb3ac;
    if ((*(s32 *)(global + 0xC) & 8) != 0) {
        *(u8 **)(global + 0x298) = ptr;
        btlActionQueueMoveToBack(ptr);
    }
done:
    global = (u8 *)iGpffffb3ac;
    *(u16 *)(global + 0x290) |= 8;
}
#pragma pop

#pragma push
#pragma opt_rebuildconditionals on
#pragma auto_inline on
// FUN_001B1450
void btlOrderSetCurrentAction(u8 *arg0)
{
    u8 *global;
    if ((*(u16 *)(arg0 + 0x18) & 4) != 0) {
        btlOrderQueueAction(arg0);
    } else {
        global = (u8 *)iGpffffb3ac;
        if ((*(s32 *)(global + 0xC) & 8) != 0) {
            *(u8 **)(global + 0x298) = arg0;
        }
        global = (u8 *)iGpffffb3ac;
        *(u16 *)(global + 0x290) |= 8;
    }
}
#pragma pop

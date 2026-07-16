/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"
typedef struct BtlAction BtlAction;

/* Canonical grouped function declarations. */
u32 func_001b0d00(BtlAction** actions, u32 arrSize, BtlAction* action);

/* Source unit: src/Battle/btlOrder_001b0d00.c */

// FUN_001B0D00
u32 func_001b0d00(BtlAction** actions, u32 arrSize, BtlAction* action)
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

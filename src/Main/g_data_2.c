#include "type.h"

/* measured: retail reloads the address high half again before the clamp store, which only happens
 * at this optimization level. */


/* Store the preserved game-clear count, saturating unsigned values above ninety-nine. */
// FUN_00110470
#pragma optimization_level 1
void datSetClearCount(u32 value)
{
    *(u32*)0x0079bef4 = value;
    if (*(u32*)0x0079bef4 > 99)
        *(u32*)0x0079bef4 = 99;
}
#pragma optimization_level 2

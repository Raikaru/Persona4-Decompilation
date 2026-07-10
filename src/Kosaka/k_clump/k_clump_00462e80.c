#include "Kosaka/k_clump_internal.h"

// FUN_00462E80
u32 func_00462e80(const u32* state)
{
    if (state == NULL)
    {
        return 0;
    }
    return state[8] != 0;
}

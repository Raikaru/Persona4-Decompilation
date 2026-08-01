/* Source unit: src/Main/g_data_001059e0.c */
#include "type.h"

#define MAX_CHARACTER_LEVEL 99

// 005dd6e0
static const u32 sPlayerExpThreshold[MAX_CHARACTER_LEVEL] =
{
    0, 20, 47, 99, 185, 312, 490, 726, 1030,
    1410, 1873, 2429, 3085, 3851, 4735, 5744, 6888, 8174,
    9612, 11210, 12975, 14917, 17043, 19363, 21885, 24616, 27566,
    30742, 34154, 37810, 41717, 45885, 50321, 55035, 60035, 65328,
    70924, 76830, 83056, 89610, 96499, 103733, 111319, 119267, 127585,
    136280, 145362, 154838, // ! 005dd7a0 !
};

/* Ported from P3FES FUN_0016d280 (verified MATCH there), which is compiled
 * inside the donor's opt_loop_invariants on region. Removing it here measured
 * MATCH nd0 -> MISMATCH nd19 (table address no longer hoisted out of the
 * loop into the preheader). */
#pragma opt_loop_invariants on


// FUN_001059E0
u8 func_001059e0(s32 exp)
{
    u8 level = 0;
    u8 index = 0;

    while (index < MAX_CHARACTER_LEVEL)
    {
        if (exp < (s32)sPlayerExpThreshold[index])
        {
            return level;
        }
        level++;
        index++;
    }

    return MAX_CHARACTER_LEVEL;
}
#pragma opt_loop_invariants off

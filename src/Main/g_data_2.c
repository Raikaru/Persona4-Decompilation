/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00110470)
/* Source unit: src/Main/g_data_2_00110470.c */
#include "type.h"

/* Ported from P3 FUN_0017d7c0. optimization_level 1 is load-bearing: measured
 * without it nd12/object36 (MISMATCH, missing retail's second lui re-materialization
 * before the clamp store), with it nd0/object44 (MATCH); retained. */
// FUN_00110470
#pragma optimization_level 1
void FUN_00110470(u32 value)
{
    *(u32*)0x0079bef4 = value;
    if (*(u32*)0x0079bef4 > 99)
        *(u32*)0x0079bef4 = 99;
}
#pragma optimization_level 2
#endif /* P4_UNIT_00110470 */

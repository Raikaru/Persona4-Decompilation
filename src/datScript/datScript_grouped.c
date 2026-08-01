/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
void func_00246450(u32 value);

/* Source unit: src/datScript/datScript_00246450.c (1 function markers) */

/* measured: removing this pragma takes func_00246450 nd 0 -> nd 16 (object 36 -> 28, window 48). */
#pragma optimization_level 1
// FUN_00246450
void func_00246450(u32 value)
{
    *(u16*)0x00881474 |= 1;
    *(u32*)0x00881468 = value;
}
#pragma optimization_level 2

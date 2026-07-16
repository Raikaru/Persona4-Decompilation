/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
void func_0011b9e0(int task, u32 value);
void func_0011b9f0(int task, u32 value);

/* Source unit: src/Kosaka/k_footstep_0011b9e0.c (1 function markers) */

#pragma schedule off
// FUN_0011B9E0
void func_0011b9e0(int task, u32 value)
{
    *(u32 *)(*(int *)(task + 0x38) + 0x44) = value;
}

/* Source unit: src/Kosaka/k_footstep_0011b9f0.c (1 function markers) */

#pragma schedule off
// FUN_0011B9F0
void func_0011b9f0(int task, u32 value)
{
    *(u32 *)(*(int *)(task + 0x38) + 0x4c4) = value;
}

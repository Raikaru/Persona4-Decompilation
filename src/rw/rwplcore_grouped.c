/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
u32 func_003de270(int param_1);
void func_003df7e0(int param_1, int param_2);
u32 func_003e8920(void);

/* Source unit: src/rw/rwplcore_003de270.c (1 function markers) */
#pragma optimization_level 3

// FUN_003DE270
u32 func_003de270(int param_1)
{
    return *(u32 *)(param_1 + 0x10);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwplcore_003df7e0.c (1 function markers) */
#pragma optimization_level 3

// FUN_003DF7E0
void func_003df7e0(int param_1, int param_2)
{
    *(int *)(param_1 + 4) -= param_2;
}
#pragma optimization_level 2

/* Source unit: src/rw/rwplcore_003e8920.c (1 function markers) */
#pragma optimization_level 3

// FUN_003E8920
u32 func_003e8920(void)
{
    return 0x37002;
}
#pragma optimization_level 2

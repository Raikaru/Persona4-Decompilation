/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
u32 func_0036de60(int work);
u32 func_0038f5c0(const u32* work, s32 index);
u32 func_0038f5e0(int work);
u32 func_0038f5f0(int work);

/* Source unit: src/op_fade/op_fade_0036de60.c (1 function markers) */

// FUN_0036DE60
u32 func_0036de60(int work)
{
    return *(u32*)(work + 4);
}

/* Source unit: src/op_fade/op_fade_0038f5c0.c (1 function markers) */

// FUN_0038F5C0
u32 func_0038f5c0(const u32* work, s32 index)
{
    return *(const u32*)(index * sizeof(u32) + work[2]);
}

/* Source unit: src/op_fade/op_fade_0038f5e0.c (1 function markers) */

// FUN_0038F5E0
u32 func_0038f5e0(int work)
{
    return *(u32*)(work + 0x10);
}

/* Source unit: src/op_fade/op_fade_0038f5f0.c (1 function markers) */

// FUN_0038F5F0
u32 func_0038f5f0(int work)
{
    return *(u32*)(work + 4);
}

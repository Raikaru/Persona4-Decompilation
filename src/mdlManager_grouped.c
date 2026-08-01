/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
void* mdlGetColor(void* mdl);
void* mdlGetMatrix(void* mdl);
void* mdlGetClumpFrame(void* mdl);
void* mdlGetClump(void* mdl);

/* Source unit: src/mdlManager_0047a250.c (1 function markers) */

// FUN_0047A250
void* mdlGetColor(void* mdl)
{
    return (u8*)mdl + 0xd0;
}

/* Source unit: src/mdlManager_0047a2f0.c (1 function markers) */

// FUN_0047A2F0
void* mdlGetMatrix(void* mdl)
{
    return mdl;
}

/* Source unit: src/mdlManager_0047a300.c (1 function markers) */

// FUN_0047A300
void* mdlGetClumpFrame(void* mdl)
{
    void* clump = *(void**)((u8*)mdl + 0xdc);
    return *(void**)((u8*)clump + 4);
}

/* Source unit: src/mdlManager_0047a310.c (1 function markers) */

// FUN_0047A310
void* mdlGetClump(void* mdl)
{
    return *(void**)((u8*)mdl + 0xdc);
}

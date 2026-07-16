/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
void func_0014a2e0(u32 value);
void func_002bd260(u32 value);
void func_002bd270(u32 value);

/* Source unit: src/Event/Fcl/fcl_misc_0014a2e0.c (1 function markers) */

extern u32 PTR_DAT_00762ea0;

// FUN_0014A2E0
void func_0014a2e0(u32 value)
{
    *(u32*)(PTR_DAT_00762ea0 + 0x14) = value;
}

/* Source unit: src/Event/Fcl/fcl_misc_002bd260.c (1 function markers) */

extern u32 D_0076466C;

// FUN_002BD260
void func_002bd260(u32 value)
{
    *(u32*)(D_0076466C + 0x14) = value;
}

/* Source unit: src/Event/Fcl/fcl_misc_002bd270.c (1 function markers) */

extern u32 D_0076466C;

// FUN_002BD270
void func_002bd270(u32 value)
{
    *(u32*)(D_0076466C + 0xc) = value;
}

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
void func_003d5830(void);
void func_003d5990(s32 object, u32 first, u32 second);
u32 func_003d60e0(u32 object, u32 value);
u32 func_003d7b30(void);

/* Source unit: src/rw/rt2d_003d5830.c (1 function markers) */

#pragma alias DAT_008873ec_abs DAT_008873ec
extern void (*DAT_008873ec_abs[])(void);

#pragma optimization_level 3
// FUN_003D5830
void func_003d5830(void)
{
    DAT_008873ec_abs[0]();
}
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d5990.c (1 function markers) */
#pragma optimization_level 3

// FUN_003D5990
void func_003d5990(s32 object, u32 first, u32 second)
{
    *(u32*)(object + 0x18) = first;
    *(u32*)(object + 0x1c) = second;
}
#pragma optimization_level 2

/* Source unit: src/rw/rt2d_003d60e0.c (1 function markers) */

#pragma schedule on
// FUN_003D60E0
u32 func_003d60e0(u32 object, u32 value)
{
    *(u32 *)(object + 0x14) = value;
    return object;
}
#pragma schedule off

/* Source unit: src/rw/rt2d_003d7b30.c (1 function markers) */
#pragma optimization_level 3

// FUN_003D7B30
u32 func_003d7b30(void)
{
    return 0x40;
}
#pragma optimization_level 2

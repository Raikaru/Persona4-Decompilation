/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
u64 func_003b7a80(u64 value);
u64 func_003b82b0(u64 value);
u32 func_003b83f0(int object);
u32 func_003b8510(int object);
u64 func_003b88c0(u64 value);
u64 func_003bf1c0(u64 value);
u64 func_003bf1f0(u64 value);
u64 func_003bf320(u64 value);
u64 func_003c38a0(u64 value);
u64 func_003cad80(u64 value);
u64 func_003caee0(u64 value);
u64 func_003e3800(u64 value);
u64 func_003e3810(u64 value);
u64 func_003e3820(u64 value);

/* Source unit: src/rprandom/rprandom_003b7a80.c (1 function markers) */
/* measured: removing this pragma takes func_003b7a80 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003B7A80
u64 func_003b7a80(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b82b0.c (1 function markers) */
/* measured: removing this pragma takes func_003b82b0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003B82B0
u64 func_003b82b0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b83f0.c (1 function markers) */

#pragma alias DAT_00886498_abs DAT_00886498
extern u32 DAT_00886498_abs[];

#pragma schedule on
/* measured: removing the schedule on/off bracket takes func_003b83f0 nd 0 -> nd 6: retail loads in the jr $ra delay slot; unscheduled it emits lw; jr; nop. */
// FUN_003B83F0
u32 func_003b83f0(int object)
{
    return *(u32 *)(object + DAT_00886498_abs[0]);
}
#pragma schedule off

/* Source unit: src/rprandom/rprandom_003b8510.c (1 function markers) */
/* measured: removing this pragma takes func_003b8510 nd 0 -> nd 6: retail fills the jr $ra delay slot with lw $v0, 0xc($a0); baseline -O2 emits lw; jr; nop. */
#pragma optimization_level 3
// FUN_003B8510
u32 func_003b8510(int object) { return *(u32*)(object + 0xc); }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b88c0.c (1 function markers) */
/* measured: removing this pragma takes func_003b88c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003B88C0
u64 func_003b88c0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf1c0.c (1 function markers) */
/* measured: removing this pragma takes func_003bf1c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003BF1C0
u64 func_003bf1c0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf1f0.c (1 function markers) */
/* measured: removing this pragma takes func_003bf1f0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003BF1F0
u64 func_003bf1f0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf320.c (1 function markers) */
/* measured: removing this pragma takes func_003bf320 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003BF320
u64 func_003bf320(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003c38a0.c (1 function markers) */
/* measured: removing this pragma takes func_003c38a0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003C38A0
u64 func_003c38a0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003cad80.c (1 function markers) */
/* measured: removing this pragma takes func_003cad80 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003CAD80
u64 func_003cad80(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003caee0.c (1 function markers) */
/* measured: removing this pragma takes func_003caee0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003CAEE0
u64 func_003caee0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3800.c (1 function markers) */
/* measured: removing this pragma takes func_003e3800 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003E3800
u64 func_003e3800(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3810.c (1 function markers) */
/* measured: removing this pragma takes func_003e3810 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003E3810
u64 func_003e3810(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003e3820.c (1 function markers) */
/* measured: removing this pragma takes func_003e3820 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3
// FUN_003E3820
u64 func_003e3820(u64 value) { return value; }
#pragma optimization_level 2

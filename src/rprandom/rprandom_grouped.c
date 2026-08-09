/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
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

// FUN_003B7A90
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7a90);

// FUN_003B7AD0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7ad0);

// FUN_003B7B00
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7b00);

// FUN_003B7B20
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7b20);

// FUN_003B7BB0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7bb0);

// FUN_003B7C10
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7c10);

// FUN_003B7CA0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7ca0);

// FUN_003B7E00
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b7e00);

// FUN_003B8050
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b8050);
// FUN_003B82B0
u64 func_003b82b0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b83f0.c (1 function markers) */

extern u32 DAT_00886498_abs[];

#pragma schedule on

// FUN_003B82C0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b82c0);

// FUN_003B82D0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b82d0);

// FUN_003B83D0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b83d0);
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

// FUN_003B8410
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b8410);

// FUN_003B84A0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b84a0);

// FUN_003B8500
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b8500);
// FUN_003B8510
u32 func_003b8510(int object) { return *(u32*)(object + 0xc); }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003b88c0.c (1 function markers) */
/* measured: removing this pragma takes func_003b88c0 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

// FUN_003B8520
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b8520);

// FUN_003B85B0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b85b0);

// FUN_003B85E0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003b85e0);
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

// FUN_003BF1D0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003bf1d0);
// FUN_003BF1F0
u64 func_003bf1f0(u64 value) { return value; }
#pragma optimization_level 2

/* Source unit: src/rprandom/rprandom_003bf320.c (1 function markers) */
/* measured: removing this pragma takes func_003bf320 nd 0 -> nd 8: retail fills the jr $ra delay slot with move $v0,$a0; baseline -O2 emits move; jr; nop. */
#pragma optimization_level 3

// FUN_003BF200
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003bf200);

// FUN_003BF240
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003bf240);

// FUN_003BF280
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003bf280);

// FUN_003BF2D0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003bf2d0);
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

// FUN_003CAD90
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003cad90);

// FUN_003CAE70
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003cae70);

// FUN_003CAEA0
INCLUDE_ASM("asm/nonmatchings/rprandom_grouped", func_003caea0);
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

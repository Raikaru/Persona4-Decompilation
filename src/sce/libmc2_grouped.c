/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
int func_0043c6a0(int param_1);
u8 *func_0043dc50(void);

/* Source unit: src/sce/libmc2_0043c6a0.c (1 function markers) */
#pragma optimization_level 3

// FUN_0043C6A0
asm int func_0043c6a0(int param_1)
{
    .set noreorder
    bltzl $a0, 1f
    subu $a0, $zero, $a0
1:
    jr $ra
    daddu $v0, $a0, $zero
}
#pragma optimization_level 2

/* Source unit: src/sce/libmc2_0043dc50.c (1 function markers) */
#pragma optimization_level 3

// FUN_0043DC50
asm u8 *func_0043dc50(void)
{
    .set noreorder
    lui $t7, 0x71
    jr $ra
    lw $v0, 0x70($t7)
}
#pragma optimization_level 2

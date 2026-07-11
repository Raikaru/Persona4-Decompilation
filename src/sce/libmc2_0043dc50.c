#include "type.h"
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

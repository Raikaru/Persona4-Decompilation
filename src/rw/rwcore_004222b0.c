#include "type.h"
#pragma optimization_level 3

// FUN_004222B0
asm u32 func_004222b0(void)
{
    .set noreorder
    mfc0 $v0, $12
    xori $v0, $v0, 1
    jr $ra
    andi $v0, $v0, 1
}
#pragma optimization_level 2

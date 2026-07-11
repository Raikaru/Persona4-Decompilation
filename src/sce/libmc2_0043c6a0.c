#include "type.h"
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

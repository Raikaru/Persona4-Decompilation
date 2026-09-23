/* PS2 EE runtime function QueryIntrContext, originally held with RW. */
#include "type.h"

// FUN_004222B0
asm u32 QueryIntrContext(void)
{
    .set noreorder
    mfc0 $v0, $12
    xori $v0, $v0, 1
    jr $ra
    andi $v0, $v0, 1
}

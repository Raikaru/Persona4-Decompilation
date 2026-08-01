#include "type.h"

extern u8 *D_00764298;



// FUN_00100220
asm void func_00100220(void)
{
    addiu $3, $0, 0x23
    syscall 0
}



// FUN_00102980
s32 func_00102980(void)
{
    return *(s32 *)(*(u8 **)((u8 *)D_00764298 + 0x38) + 4);
}

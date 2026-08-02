#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(void *ptr);

// FUN_002A2420
INCLUDE_ASM("asm/nonmatchings/nEntry", func_002a2420);

// FUN_002A2600
void func_002a2600(u8 *arg0)
{
    u8 *b = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(b + 0x8) != 0) {
        func_0046b0d0(*(s32 *)(b + 0x8));
        *(s32 *)(b + 0x8) = 0;
    }
    jtbl_008873EC[0](b);
}

// FUN_002A2650
INCLUDE_ASM("asm/nonmatchings/nEntry", func_002a2650);

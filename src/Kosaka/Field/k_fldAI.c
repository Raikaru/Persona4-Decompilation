#include "include_asm.h"
#include "type.h"
extern void func_003e0f40();
extern void (*jtbl_008873EC[])(void *ptr);

// FUN_0017D3C0
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017d3c0);

// FUN_0017E840
void func_0017e840(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x50);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_0017E890
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017e890);

// FUN_0017E980
s32 func_0017e980(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x48);
}

// FUN_0017E990
void func_0017e990(u8 *arg0) {
    *(s32 *)(*(u8 **)(arg0 + 0x38) + 0xC) = 1;
}

// FUN_0017E9B0
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017e9b0);

// FUN_0017EA10
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017ea10);

// FUN_0017ED40
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017ed40);

// FUN_0017F490
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_0017f490);

// FUN_001821D0
void func_001821d0(u8 *arg0) {
    s32 h = *(s32 *)(*(u8 **)(arg0 + 0x38) + 0x10);

    if (h != 0) {
        func_003e0f40(h);
    }
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}

// FUN_00182220
INCLUDE_ASM("asm/nonmatchings/k_fldAI", func_00182220);

#include "type.h"
#include "include_asm.h"

s32 *func_00452560(void);
void func_004ab680(s32 arg0);
void func_004ab140(s32 arg0);
extern void (*jtbl_008873EC[])(void *);

typedef int (*code)(...);
extern code DAT_008873ec_abs[];



// FUN_0028D110
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028d110);

// FUN_0028D1B0
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028d1b0);

// FUN_0028D280
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028d280);

// FUN_0028D310
void func_0028d310(void) {
    s32 *temp_2;
    s32 temp_3;

    temp_2 = func_00452560();
    temp_3 = temp_2[0];
    switch (temp_3) {
    case 0:
        func_004ab680(temp_2[1]);
        break;
    case 1:
        func_004ab140(temp_2[1]);
        break;
    }
    jtbl_008873EC[0](temp_2);
}


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0028D390
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028d390);

// FUN_0028DC30
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028dc30);

// FUN_0028EE00
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028ee00);

// FUN_0028F360
void func_0028f360(void)
{
    extern s32 *func_00452560(void);
    int iVar1;

    iVar1 = (s32)func_00452560();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_0028F3A0
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f3a0);

// FUN_0028F4F0
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f4f0);

// FUN_0028F530
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f530);

// FUN_0028F540
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f540);

// FUN_0028F6C0
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f6c0);

// FUN_0028F770
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f770);

// FUN_0028F800
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f800);

// FUN_0028F8E0
INCLUDE_ASM("asm/nonmatchings/evtMisc", func_0028f8e0);


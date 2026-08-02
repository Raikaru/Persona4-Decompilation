/* Consolidated Persona 4 source units. */
/* Original translation unit shdWindow.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0025DB00
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025db00);

// FUN_0025DD30
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025dd30);

// FUN_0025E170
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025e170);

// FUN_0025E4A0
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025e4a0);

// FUN_0025E7C0
void func_0025e7c0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_0025E800
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025e800);

// FUN_0025E8B0
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025e8b0);

// FUN_0025E8F0
INCLUDE_ASM("asm/nonmatchings/shdWindow", func_0025e8f0);


#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit shdScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0025C790
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025c790);

// FUN_0025CB80
void func_0025cb80(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_0025CBC0
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025cbc0);

// FUN_0025CC70
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025cc70);

// FUN_0025CCB0
INCLUDE_ASM("asm/nonmatchings/shdScript", func_0025ccb0);

/* Consolidated Persona 4 source units. */
/* Original translation unit evtScript.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "include_asm.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_00298370
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298370);

// FUN_00298510
void func_00298510(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}
// FUN_00298550
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298550);

// FUN_00298700
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298700);

// FUN_002987D0
INCLUDE_ASM("asm/nonmatchings/evtScript", func_002987d0);

// FUN_00298990
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298990);

// FUN_00298B80
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298b80);

// FUN_00298C10
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298c10);

// FUN_00298C60
INCLUDE_ASM("asm/nonmatchings/evtScript", func_00298c60);


#include "include_asm.h"
#include "type.h"
extern void (*jtbl_008873EC[])(u8 *arg0);

/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

// FUN_00311900
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311900);
// FUN_00311930
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311930);
// FUN_00311B90
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311b90);
// FUN_00311D00
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311d00);
// FUN_00311D60
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311d60);
// FUN_00311E40
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00311e40);
// FUN_00313690
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313690);
// FUN_003136B0
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_003136b0);
// FUN_00313800
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313800);
// FUN_003139D0
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_003139d0);
// FUN_00313A80
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313a80);
// FUN_00313AE0
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313ae0);
// FUN_00313B50
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313b50);
// FUN_00313D20
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313d20);
// FUN_00313FB0
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00313fb0);
// FUN_00314010
INCLUDE_ASM("asm/nonmatchings/code1_0031", func_00314010);
// FUN_003142F0
void func_003142f0(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
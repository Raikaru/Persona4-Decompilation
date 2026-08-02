/* Consolidated Persona 4 source units. */
/* Original translation unit sdkOt.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0046d730(u8 *file, s32 line);
extern u8 iGpffffaf70;   /* gp - 0x5090 = 0x00764060 */


// FUN_00460AC0
void func_00460ac0(u8 *list, u8 *node)
{
    u8 *tail;

    tail = list;
    if (list == 0) {
        func_0046d730(&iGpffffaf70, 0xBE);
    }
    if (*(u8 **)(list + 4) != 0) {
        tail = *(u8 **)(list + 4);
    }
    if (*(u8 **)(tail + 4) != 0) {
        func_0046d730(&iGpffffaf70, 0xC2);
    }
    *(u8 **)tail = node;
    if (*(u8 **)(node + 4) != 0) {
        *(u8 **)(list + 4) = *(u8 **)(node + 4);
    } else {
        *(u8 **)(list + 4) = node;
    }
}


// FUN_00460B60
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00460b60);


// FUN_00460C70
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00460c70);


// FUN_00460D80
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00460d80);


// FUN_00460E80
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00460e80);


// FUN_00460F80
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00460f80);


// FUN_00461080
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00461080);


// FUN_00461180
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00461180);


// FUN_00461290
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00461290);


// FUN_00461390
INCLUDE_ASM("asm/nonmatchings/sdkOt", func_00461390);

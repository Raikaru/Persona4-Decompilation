/* Source unit: src/frFontEx_00275a40.c */
#include "type.h"
#include "include_asm.h"


/* Ported from P3FES frFontGetHeight (verified MATCH there). The font-height
 * table lives at the address-normalized P4 global D_00763808; the scalar
 * extern + address-of-index form is required to reproduce retail's
 * gp-relative load sequence. */
extern s8 D_00763808;

/* Ported from P3FES frFontGetHeight (verified MATCH there). The font-height
 * table lives at the address-normalized P4 global D_00764670. */
extern s8 D_00764670;




// FUN_00274A20
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00274a20);

// FUN_00274A90
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00274a90);

// FUN_00274CD0
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00274cd0);

// FUN_00274ED0
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00274ed0);

// FUN_00275020
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00275020);

// FUN_002751A0
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_002751a0);

// FUN_00275330
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00275330);

// FUN_002754C0
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_002754c0);

// FUN_00275520
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00275520);

// FUN_00275680
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00275680);

// FUN_00275820
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00275820);

// FUN_00275980
INCLUDE_ASM("asm/nonmatchings/frFontEx", func_00275980);

// FUN_00275A40
s8 func_00275a40(char param_1)
{
    return (&D_00763808)[param_1];
}



// FUN_002BB1C0
s8 func_002bb1c0(char param_1)
{
    return (&D_00764670)[param_1];
}

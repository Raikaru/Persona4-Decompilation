/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldHBN.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern u8 *func_00155280(void);
extern void (*DAT_008873EC[])(void *);

// FUN_0015F8E0
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_0015f8e0);
// FUN_0015F9B0
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_0015f9b0);
// FUN_0015FB00
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_0015fb00);
// FUN_0015FF20
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_0015ff20);
// FUN_00160000
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_00160000);




// FUN_00160180
void func_00160180(void)
{
    if (*(s32 *)((u8 *)func_00155280() + 0x18DC) != 0) {
        *(s32 *)((u8 *)func_00155280() + 0x18D8) = 0;
        (*DAT_008873EC)(*(void **)((u8 *)func_00155280() + 0x18DC));
        *(s32 *)((u8 *)func_00155280() + 0x18DC) = 0;
    }
}

// FUN_001601E0
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_001601e0);
// FUN_001602A0
INCLUDE_ASM("asm/nonmatchings/k_fldHBN", func_001602a0);

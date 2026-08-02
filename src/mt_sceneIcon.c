#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit mt_sceneIcon.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

typedef int (*code)(...);
extern code DAT_008873ec_abs[];

/* gp - 0x5908 = 0x007637E8. */
extern u8 iGpffffa6f8;
extern u8 D_0063B558[];
extern u8 D_0063B568[];
extern void func_00440b68(u8 *fmt, u8 *file, s32 line);
extern u8 *func_00454a60(u8 *path, s32 mode);
extern void func_00456150(u8 *handle);


#pragma alias DAT_008873ec_abs DAT_008873ec

// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// func_00452560 is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// FUN_0026D840
void func_0026d840(void)
{
    func_00440b68(&iGpffffa6f8, D_0063B558, 0x38);
    func_00456150(func_00454a60(D_0063B568, 1));
}

// FUN_0026D890
INCLUDE_ASM("asm/nonmatchings/mt_sceneIcon", func_0026d890);
// FUN_0026D9F0
void func_0026d9f0(void)
{
    int iVar1;

    iVar1 = func_00452560();
    DAT_008873ec_abs[0](iVar1);
}

// FUN_0026DA30
INCLUDE_ASM("asm/nonmatchings/mt_sceneIcon", func_0026da30);
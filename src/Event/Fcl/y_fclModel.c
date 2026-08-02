/* Consolidated Persona 4 source units. */
/* Original translation unit y_fclModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void func_0044ea90(u8 *file, s32 line);
extern u8 D_0064A618[];
extern u8 D_0064A630[];
extern u8 *(*D_008873F4[])(s32 kind, s32 size, s32 align);
extern s32 func_00451fc0(s32 arg0, u8 *name, s32 prio, s32 a3, s32 a4,
                         void (*init)(u8 *), void (*close)(u8 *), u8 *work);
extern void func_00349340(u8 *arg0);
extern void func_00349380(u8 *arg0);

// FUN_003493B0
void func_003493b0(s32 arg0)
{
    u8 *work;

    func_0044ea90(D_0064A618, 0x555);
    work = D_008873F4[0](1, 0x1A0, 0x40000);
    func_00451fc0(arg0, D_0064A630, 0xF, 0, 0, func_00349340, func_00349380, work);
}

// FUN_00349440
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349440);

// FUN_00349B90
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349b90);

// FUN_00349C50
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_00349c50);

// FUN_0034A480
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_0034a480);

// FUN_0034A4F0
INCLUDE_ASM("asm/nonmatchings/y_fclModel", func_0034a4f0);

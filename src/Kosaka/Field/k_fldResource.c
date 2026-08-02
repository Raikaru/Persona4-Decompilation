#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldResource.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00442088(char *dst, char *fmt, u16 a, u16 b);
extern void func_00440b68(u8 *msg, u8 *file, s32 line);
extern s32 func_00454a60(char *path, s32 mode);
extern s32 func_004553c0(s32 handle);
extern char D_005EFC60[];
extern u8 D_005EFC80[];
extern s32 iGpffffb200;   /* gp - 0x4E00 = 0x007642F0 */
extern s32 iGpffffb204;   /* gp - 0x4DFC = 0x007642F4 */
extern u8 iGpffff9df0;    /* gp - 0x6210 = 0x00762EE0 */

// FUN_0014EED0
void func_0014eed0(s32 arg0, s32 arg1)
{
    char path[0x40];

    if (iGpffffb200 == 0) {
        func_00442088(path, D_005EFC60, (u16)arg0, (u16)arg1);
        func_00440b68(&iGpffff9df0, D_005EFC80, 0x9E);
        iGpffffb200 = func_00454a60(path, 1);
    }
}

// FUN_0014EF40
s32 func_0014ef40(void)
{
    if (iGpffffb200 == 0) {
        return 1;
    }
    return func_004553c0(iGpffffb200) != 0;
}

// FUN_0014EF80
s32 func_0014ef80(void)
{
    if (iGpffffb204 == 0) {
        return 1;
    }
    return func_004553c0(iGpffffb204) != 0;
}

// FUN_0014EFC0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014efc0);

// FUN_0014F310
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_0014f310);

// FUN_00150970
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00150970);

// FUN_00150C80
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00150c80);

// FUN_00150CE0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00150ce0);

// FUN_001510C0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001510c0);

// FUN_00151580
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00151580);

// FUN_00151710
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00151710);

// FUN_00151C80
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00151c80);

// FUN_00151F80
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00151f80);

// FUN_00152170
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152170);

// FUN_00152630
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152630);

// FUN_00152930
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152930);

// FUN_00152BB0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152bb0);

// FUN_00152CD0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152cd0);

// FUN_00152E50
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00152e50);

// FUN_00153300
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_00153300);

// FUN_001534A0
INCLUDE_ASM("asm/nonmatchings/k_fldResource", func_001534a0);

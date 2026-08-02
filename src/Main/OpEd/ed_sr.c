#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit ed_sr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
extern void func_0038ee40();
extern s32 *iGpffffb5b8;
extern u8 iGpffffa9f0;

// FUN_0038EE40
INCLUDE_ASM("asm/nonmatchings/ed_sr", func_0038ee40);

// FUN_0038F010
INCLUDE_ASM("asm/nonmatchings/ed_sr", func_0038f010);

// FUN_0038F0B0
INCLUDE_ASM("asm/nonmatchings/ed_sr", func_0038f0b0);

// FUN_0038F160
s32 func_0038f160(void) {
    func_0038ee40();
    if (iGpffffb5b8 == NULL) {
        func_0046d730(&iGpffffa9f0, 0x64);
    }
    if (*iGpffffb5b8 & 1) {
        return 0;
    }
    return -1;
}

// FUN_0038F1C0
INCLUDE_ASM("asm/nonmatchings/ed_sr", func_0038f1c0);

// FUN_0038F220
INCLUDE_ASM("asm/nonmatchings/ed_sr", func_0038f220);

// FUN_0038F290
INCLUDE_ASM("asm/nonmatchings/ed_sr", func_0038f290);

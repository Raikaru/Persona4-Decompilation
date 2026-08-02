/* Original translation unit shdMisc.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

/* gp - 0x5418 = 0x00763CD8, accessed as a 64-bit word (ld/sd). */
extern s64 iGpffffabe8;

// FUN_00364320
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364320);

// FUN_003645C0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_003645c0);

// FUN_00364680
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364680);

// FUN_00364C50
void func_00364c50(void) {
    iGpffffabe8 |= 0x80;
}

// FUN_00364C70
void func_00364c70(void) {
    iGpffffabe8 &= ~0x80;
}

// FUN_00364C90
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364c90);

// FUN_00364FB0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00364fb0);

// FUN_003657D0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_003657d0);

// FUN_00365AC0
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365ac0);

// FUN_00365F00
INCLUDE_ASM("asm/nonmatchings/shdMisc", func_00365f00);


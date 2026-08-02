#include "include_asm.h"
/* Persona 4 USA decompilation - effDistortParticle.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
extern s32 func_00481390();

// FUN_004AF680
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004af680);

// FUN_004AF740
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004af740);

// FUN_004AF8A0
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004af8a0);

// FUN_004AF920
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004af920);

// FUN_004AFA60
void func_004afa60(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x60) = func_00481390(arg1);
}

// FUN_004AFAA0
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004afaa0);

// FUN_004AFB10
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004afb10);

// FUN_004AFC50
void func_004afc50(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x5C);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004AFC80
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004afc80);

// FUN_004AFE20
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004afe20);

// FUN_004B0A80
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004b0a80);

// FUN_004B0CE0
INCLUDE_ASM("asm/nonmatchings/effDistortParticle", func_004b0ce0);

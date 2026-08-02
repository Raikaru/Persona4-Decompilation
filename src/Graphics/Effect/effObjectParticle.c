#include "include_asm.h"
#include "type.h"

// FUN_004AE460
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004ae460);

// FUN_004AE650
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004ae650);

// FUN_004AE6D0
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004ae6d0);

// FUN_004AE880
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004ae880);

// FUN_004AE930
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004ae930);

// FUN_004AEA70
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004aea70);

// FUN_004AEC50
void func_004aec50(u8 *arg0)
{
    u32 temp_4;

    temp_4 = *(u32 *)(arg0 + 0x58);
    if (temp_4 != 0) {
        func_00492d00(temp_4);
    }
}

// FUN_004AEC80
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004aec80);

// FUN_004AED70
INCLUDE_ASM("asm/nonmatchings/effObjectParticle", func_004aed70);

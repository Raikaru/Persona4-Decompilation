#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit tnEffect.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

s32 func_00464100(u8 *arg0, s32 arg1);
u8 *func_003ef2e0(u8 *arg0);




// FUN_00481300
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481300);
// FUN_00481360
void func_00481360(u8 *arg0)
{
    func_00464100(arg0, 1);
}



// FUN_00481390
void func_00481390(u8 *arg0)
{
    u8 *temp_2 = func_003ef2e0((u8 *)func_00464100(arg0, 1));
    s32 temp_4 = (*(s32 *)(temp_2 + 0x50) & ~0xFF) | 2;

    *(s32 *)(temp_2 + 0x50) = temp_4;
    *(s32 *)(temp_2 + 0x50) = (temp_4 & 0xFFFF00FF) | 0x1100;
}

// FUN_004813F0
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_004813f0);

// FUN_00481430
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481430);

// FUN_00481440
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481440);

// FUN_00481450
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481450);

// FUN_00481460
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481460);

// FUN_004814D0
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_004814d0);

// FUN_00481540
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481540);

// FUN_004815B0
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_004815b0);

// FUN_00481660
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481660);

// FUN_004816D0
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_004816d0);

// FUN_00481740
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481740);

// FUN_004818A0
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_004818a0);

// FUN_004818C0
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_004818c0);

// FUN_00481980
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481980);

// FUN_00481A20
INCLUDE_ASM("asm/nonmatchings/tnEffect", func_00481a20);

#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit k_fldEnvironment.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00161460(s32 arg0, s32 arg1, s32 arg2);

extern s16 func_001060b0(void);
extern s32 func_001060c0(void);
extern s8 func_00110960(s64 arg0, s32 arg1);
extern void func_00154720(u16 arg0, u16 arg1, s64 arg2);



// FUN_00153A60
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153a60);

// FUN_00153B20
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153b20);
// FUN_00153B60
void func_00153b60(u8 *arg0, s32 arg1)
{
    u8 *work;

    work = *(u8 **)(arg0 + 0x38);
    *(s32 *)(work + 8) = arg1;
    func_00161460(*(s32 *)(work + 4), arg1, *(s32 *)(work + 0x10));
}



// FUN_00153B90
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153b90);

// FUN_00153BD0
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153bd0);

// FUN_00153C00
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153c00);

// FUN_00153D60
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00153d60);
// FUN_001546A0
void func_001546a0(u16 arg0, u16 arg1)
{
    func_00154720(arg0, arg1, func_00110960(func_001060b0(), func_001060c0() & 0xFF));
}

// FUN_00154720
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00154720);

// FUN_00154B10
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00154b10);

// FUN_00154BE0
INCLUDE_ASM("asm/nonmatchings/k_fldEnvironment", func_00154be0);
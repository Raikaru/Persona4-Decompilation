#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit effModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);



// FUN_004ABD80
INCLUDE_ASM("asm/nonmatchings/effModel", func_004abd80);

// FUN_004ABE60
INCLUDE_ASM("asm/nonmatchings/effModel", func_004abe60);

// FUN_004ABE80
INCLUDE_ASM("asm/nonmatchings/effModel", func_004abe80);

// FUN_004AC0B0
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac0b0);

// FUN_004AC100
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac100);

// FUN_004AC170
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac170);

// FUN_004AC290
void func_004ac290(u8 *arg0) {
    func_00479e60(*(u8 **)(arg0 + 0x94), 0, 0.0f);
}



// FUN_004AC2C0
void func_004ac2c0(u32 *param_1)
{
  if ((param_1[0x23] >= param_1[0x26]) || (param_1[0x23] == 0)) {
    *(f32 *)(param_1 + 9) = 1.0f;
    param_1[0x26] = param_1[0x26] + 1;
  }
}



// FUN_004AC300
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac300);

// FUN_004AC550
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac550);

// FUN_004AC590
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac590);

// FUN_004AC600
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac600);

// FUN_004AC610
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac610);

// FUN_004AC620
void func_004ac620(int param_1, int param_2)
{
  *(int *)(param_1 + 0x28) = param_2;
}

// FUN_004AC630
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac630);

// FUN_004AC640
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac640);

// FUN_004AC8E0
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac8e0);

// FUN_004AC930
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac930);

// FUN_004AC9A0
INCLUDE_ASM("asm/nonmatchings/effModel", func_004ac9a0);

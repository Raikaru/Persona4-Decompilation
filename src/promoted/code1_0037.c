#include "include_asm.h"
#include "type.h"

extern void *func_003e0f80(void);
extern void func_003e0870(void *arg0, void *arg1, f32 fparg0, s32 arg2);
extern void func_003e42a0(void *arg0, void *arg1, void *arg2);
extern void func_003e0f40(void *arg0);
/* Promoted from the canonical function map: every function here is a
   retail window with an INCLUDE_ASM fallback and no C body yet. */

// FUN_00370290
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370290);
// FUN_00370410
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370410);
// FUN_00370640
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370640);
// FUN_00370A80
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370a80);
// FUN_00370CD0
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00370cd0);
// FUN_00371160
void func_00371160(u8 *arg0, u8 *arg1, u8 *arg2, f32 fparg0, u8 *arg3) {
    f32 sp70[3];
    void *temp_16;

    temp_16 = func_003e0f80();
    sp70[0] = *(f32 *)(arg2 + 0) - *(f32 *)(arg0 + 0);
    sp70[1] = *(f32 *)(arg2 + 4) - *(f32 *)(arg0 + 4);
    sp70[2] = *(f32 *)(arg2 + 8) - *(f32 *)(arg0 + 8);
    func_003e0870(temp_16, arg1, fparg0, 0);
    func_003e42a0(arg3, sp70, temp_16);
    *(f32 *)(arg3 + 0) += *(f32 *)(arg0 + 0);
    *(f32 *)(arg3 + 4) += *(f32 *)(arg0 + 4);
    *(f32 *)(arg3 + 8) += *(f32 *)(arg0 + 8);
    func_003e0f40(temp_16);
}
// FUN_00379E90
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00379e90);
// FUN_00379F90
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_00379f90);
// FUN_0037AB50
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037ab50);
// FUN_0037AD10
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037ad10);
// FUN_0037B8C0
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037b8c0);
// FUN_0037BAC0
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037bac0);
// FUN_0037BC80
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037bc80);
// FUN_0037ED90
INCLUDE_ASM("asm/nonmatchings/code1_0037", func_0037ed90);
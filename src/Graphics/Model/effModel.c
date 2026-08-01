/* Consolidated Persona 4 source units. */
/* Original translation unit effModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void func_00479e60(u8 *arg0, s32 arg1, f32 arg2);



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



// FUN_004AC620
void func_004ac620(int param_1, int param_2)
{
  *(int *)(param_1 + 0x28) = param_2;
}

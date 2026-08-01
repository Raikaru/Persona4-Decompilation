/* Consolidated Persona 4 source units. */
/* Original translation unit effParticle.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_004833f0(s32 arg0);
s32 func_004830f0(s32 arg0, s32 arg1);

void func_00481ee0(s32 arg0);
s32 func_00481d80(s32 *arg0);

void func_004829c0(s32 arg0);
s32 func_00482800(s32 *arg0);

extern void func_00492d00(int param_1);



// FUN_00487650
void func_00487650(u8 *arg0, s32 arg1, s32 arg2)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x50);

    if (temp_4 != 0) {
        func_004833f0(temp_4);
    }
    switch (arg2) {
    case 1:
    case 4:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x20080027);
        return;
    case 2:
        *(s32 *)(arg0 + 0x50) = func_004830f0(arg1 & 0xFFFF, 0x200000A7);
        /* fallthrough */
    case 7:
        return;
    }
}



// FUN_00487860
void func_00487860(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x44);

    if (temp_4 != 0) {
        func_00481ee0(temp_4);
    }
    *(s32 *)(arg0 + 0x44) = func_00481d80(arg1);
}



// FUN_00487BA0
void func_00487ba0(u8 *arg0, s32 *arg1)
{
    s32 temp_4 = *(s32 *)(arg0 + 0x48);

    if (temp_4 != 0) {
        func_004829c0(temp_4);
    }
    *(s32 *)(arg0 + 0x48) = func_00482800(arg1);
}



// FUN_00487C00
void func_00487c00(int param_1)
{
  if (*(int *)(param_1 + 0x4c) != 0) {
    func_00492d00(*(int *)(param_1 + 0x4c));
  }
  return;
}

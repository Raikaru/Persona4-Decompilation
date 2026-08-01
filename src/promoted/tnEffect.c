/* Consolidated Persona 4 source units. */
/* Original translation unit tnEffect.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

s32 func_00464100(u8 *arg0, s32 arg1);
u8 *func_003ef2e0(u8 *arg0);



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

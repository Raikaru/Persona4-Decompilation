/* Consolidated Persona 4 source units. */
/* Original translation unit sdkWrap.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void (*jtbl_008873EC[])(s32);

// FUN_00466C60
INCLUDE_ASM("asm/nonmatchings/sdkWrap", func_00466c60);
// FUN_00466E80
INCLUDE_ASM("asm/nonmatchings/sdkWrap", func_00466e80);




// FUN_00467290
void func_00467290(u8 *arg0)
{
    jtbl_008873EC[0](*(s32 *)(arg0 + 0x38));
}

// FUN_004672C0
INCLUDE_ASM("asm/nonmatchings/sdkWrap", func_004672c0);

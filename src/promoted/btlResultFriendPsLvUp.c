#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultFriendPsLvUp.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0046d730(u8 *arg0, s32 arg1);

extern u8 D_00629720[];



// FUN_002238F0
s32 func_002238f0(s64 arg0)
{
    s64 temp_2;

    temp_2 = (s64)(arg0 << 0x30) >> 0x30;
    switch (temp_2) {
    case 2:
        return 0xE2;
    case 3:
        return 0x16C;
    case 4:
        return 0x1F3;
    case 6:
        return 0x27A;
    case 7:
        return 0x301;
    case 8:
        return 0x387;
    default:
        func_0046d730(D_00629720, 0x2C);
        return 0;
    }
}

// FUN_002239A0
INCLUDE_ASM("asm/nonmatchings/btlResultFriendPsLvUp", func_002239a0);

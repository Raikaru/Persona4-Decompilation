#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlShuffleResult.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

s32 func_00383720(u8 *arg0);



// FUN_00380EA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00380ea0);

// FUN_003816E0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_003816e0);

// FUN_00381830
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00381830);

// FUN_00381A70
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00381a70);

// FUN_00382BA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00382ba0);

// FUN_00382EA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00382ea0);

// FUN_00383720
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00383720);
// FUN_00383A40
s32 func_00383a40(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(u16 *)(temp_16 + 4) & 4) {
        return -1;
    }
    if (*(s32 *)(temp_16 + 0x14) == 0) {
        *(s32 *)(temp_16 + 0x14) = func_00383720(temp_16);
    }
    return 0;
}

// FUN_00383AA0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00383aa0);

// FUN_00383AE0
INCLUDE_ASM("asm/nonmatchings/btlShuffleResult", func_00383ae0);
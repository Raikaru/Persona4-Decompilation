#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit btlResultSimple.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0021dda0(void);
extern u16 *func_00452560();

// FUN_0021ED10
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021ed10);

// FUN_0021EF70
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021ef70);

// FUN_0021F340
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021f340);

// FUN_0021F520
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021f520);

// FUN_0021F790
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021f790);

// FUN_0021FA40
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fa40);

// FUN_0021FEA0
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_0021fea0);

// FUN_002214D0
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_002214d0);

// FUN_002215C0
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_002215c0);

// FUN_002216B0
void func_002216b0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    *temp_2 |= 1;
}

// FUN_002216E0
void func_002216e0(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    if (temp_2[0] & 0x80) {
        func_0021dda0();
        *(s32 *)(temp_2 + 2) = 5;
        return;
    }
    *(s16 *)((u8 *)temp_2 + 0x3C) = 0;
    *(s32 *)(temp_2 + 2) = 6;
}

// FUN_00221740
u16 func_00221740(void) {
    u16 *temp_2;

    temp_2 = func_00452560();
    return temp_2[0] & 1;
}

// FUN_00221770
INCLUDE_ASM("asm/nonmatchings/btlResultSimple", func_00221770);

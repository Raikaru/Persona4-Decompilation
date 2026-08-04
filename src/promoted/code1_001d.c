#include "include_asm.h"
#include "type.h"

extern s64 func_0023a6b0(s32 arg0, s64 arg1);

typedef int (*code)(...);

extern int func_001d94d0(int param_1, int param_2, int param_3, int param_4, int param_5, code param_6);
extern s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1);



// FUN_001D4E90
void func_001d4e90(s32 arg0, s32 arg1, s32 arg2, u8 *arg3) {
    *(s32 *)((u8 *)arg3 + 0) = 0;
    *(s32 *)((u8 *)arg3 + 4) = 0;
    *(s32 *)((u8 *)arg3 + 8) = 0;
    *(s32 *)((u8 *)arg3 + 0xC) = 0;
}



// FUN_001D5AC0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d5ac0);

// FUN_001D6300
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6300);

// FUN_001D6570
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6570);

// FUN_001D6A60
void func_001d6a60(void)
{
}

// FUN_001D6A70
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d6a70);

// FUN_001D7700
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7700);

// FUN_001D7A60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7a60);

// FUN_001D7B60
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7b60);

// FUN_001D7BF0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d7bf0);

// FUN_001D9740
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9740);

// FUN_001D97B0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d97b0);

// FUN_001D9820
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9820);

// FUN_001D9890
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9890);

// FUN_001D98E0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d98e0);

// FUN_001D9940
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9940);

// FUN_001D9B90
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001d9b90);

// FUN_001DA130
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da130);

// FUN_001DA1A0
s32 func_001da1a0(void)
{
    return 0;
}

// FUN_001DA1B0
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da1b0);

// FUN_001DA230
s32 btlCond_MYHANSYA(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x02000000) != 0);
}



// FUN_001DA270
s32 btlCond_MYKYUSYU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x04000000) != 0);
}



// FUN_001DA2B0
s32 btlCond_MYMUKOU(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x01000000) != 0);
}



// FUN_001DA2F0
s32 btlCond_MYWEAK(u8 *arg0, s16 arg1) {
    return (s32)((func_0023a6b0(*(s32 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA64), arg1) & 0x08000000) != 0);
}



// FUN_001DA330
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da330);

// FUN_001DA380
INCLUDE_ASM("asm/nonmatchings/code1_001d", func_001da380);

// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

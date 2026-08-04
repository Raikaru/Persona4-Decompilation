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



// FUN_001D6A60
void func_001d6a60(void)
{
}

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



// FUN_001DA3E0
void btlCond_FRKYUSYU(u8 *arg0, s32 arg1) {
    func_001d94d0((int)arg0, arg1, (1 << *(u8 *)((u8 *)*(u8 **)((u8 *)arg0 + 0x30) + 0xA2)) & 0xFFFF, 0x80000, 0, (code)btlCond_MYKYUSYU);
}

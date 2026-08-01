#include "type.h"

extern s32 func_002746a0(void);
extern void func_00273f70(u8 *arg0);
extern void func_00273cc0(u8 *arg0, u8 *arg1);

extern s32 D_008815B0[];

extern void memset(void *arg0, s32 arg1, s32 arg2);
extern s32 func_0027bf10(s32 arg0);

extern u16 D_008817E8[];



// FUN_002706F0
s32 func_002706f0(u8 *arg0, u8 *arg1)
{
    if (func_002746a0() != 0) {
        return 0;
    }
    func_00273f70(arg1);
    func_00273cc0(NULL, arg1);
    return 0;
}



// FUN_002746C0
void func_002746c0(s32 arg0, s32 arg1)
{
    D_008815B0[arg0] = arg1;
}



// FUN_0027A5E0
void func_0027a5e0(s32 *arg0, s32 arg1)
{
    memset(arg0, 0, 0x1C);
    *arg0 = func_0027bf10(arg1);
}



// FUN_0027A650
void func_0027a650(u8 *arg0)
{
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s8 *)(arg0 + 8) = 0;
    *(s8 *)(arg0 + 9) = 0;
    *(s16 *)(arg0 + 0xE) = 0;
    *(s16 *)(arg0 + 0x10) = 0;
    *(s16 *)(arg0 + 0x12) = 0;
    *(s8 *)(arg0 + 0xA) = 0;
    *(s8 *)(arg0 + 0xB) = 0;
    *(s8 *)(arg0 + 0xC) = 0;
    *(u8 *)(arg0 + 0xD) = 0xFF;
}



// FUN_0027B4C0
void func_0027b4c0(s32 *arg0)
{
    s32 temp;

    temp = *arg0;
    if (!(temp & 0x80000) && ((u32)(temp & 0x300) >= 0x100U)) {
        D_008817E8[0] |= 2;
    }
}

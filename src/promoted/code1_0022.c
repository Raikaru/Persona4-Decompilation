#include "type.h"

s32 func_00452380(u8 *arg0);

extern u8 D_006290F0[];

u16 *func_00452560(void);

extern u8 D_00629640[];

extern u8 D_006296B0[];

extern u8 D_00629700[];

void func_001c8d50(void);

extern u8 *DAT_0076449c;

void func_002258b0(float arg0, float arg1);

void func_00455ea0(s32 arg0, s32 arg1, s32 arg2);



// FUN_00221910
s32 func_00221910(void)
{
    return func_00452380(D_006290F0) != 0;
}



// FUN_00221940
s32 func_00221940(void)
{
    return ((*func_00452560() & 0x10) != 0) ^ 1;
}



// FUN_00223270
s32 func_00223270(void)
{
    return func_00452380(D_00629640) != 0;
}



// FUN_002238C0
s32 func_002238c0(void)
{
    return func_00452380(D_006296B0) != 0;
}



// FUN_002240B0
s32 func_002240b0(void)
{
    return func_00452380(D_00629700) != 0;
}



// FUN_00224970
void func_00224970(void)
{
    if (*(s32 *)(DAT_0076449c + 0xC0C) != 0) {
        func_001c8d50();
    }
}



// FUN_00225BD0
void func_00225bd0(void)
{
    func_002258b0(0.0f, 2.0f);
}



// FUN_0022BD00
s32 func_0022bd00(void)
{
    return *(s32 *)(DAT_0076449c + 0xBA0) != 0;
}



// FUN_0022CED0
void func_0022ced0(s32 arg0)
{
    func_00455ea0(*(s32 *)(DAT_0076449c + 0xB90), arg0 & 0xFFFF, 0);
}

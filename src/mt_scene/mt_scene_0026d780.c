#include "type.h"

extern u32 D_00764580;
extern u32 D_00764584;
extern u32 D_00764588;
extern u32 D_0076458C;
extern void func_004b1590();

// FUN_0026D780
void func_0026d780(s32 first, s32 second)
{
    if (second == 0)
    {
        *(u16*)&D_00764580 = 0;
    }
    else
    {
        *(u16*)&D_00764580 = 1;
        if (first == 0)
        {
            *(s16*)&D_00764584 = -1;
        }
        else
        {
            *(u16*)&D_00764584 = (s16)first;
        }
        *(u16*)&D_0076458C = second * 10;
        *(u16*)&D_00764588 = (*(u16*)&D_0076458C << 2) / 10;
        func_004b1590(first, (s16)second);
    }
}

#include "type.h"

extern u32 D_00764580;

#pragma optimization_level 1
// FUN_0026D400
u8 func_0026d400(float* param_1)
{
    if (*(u16*)&D_00764580 == 0)
    {
        return 0;
    }

    param_1[0] = *(volatile float*)(uintptr_t)0x00881500;
    param_1[1] = *(volatile float*)(uintptr_t)0x00881504;
    return 1;
}
#pragma optimization_level 2

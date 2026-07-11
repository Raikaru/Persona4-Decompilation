#include "type.h"
#pragma optimization_level 3
// FUN_00525C30
void func_00525c30(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x148) = second;
    *(u32*)(object + 0x144) = first;
}
#pragma optimization_level 2

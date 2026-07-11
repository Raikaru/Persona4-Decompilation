#include "type.h"
#pragma optimization_level 3

// FUN_003D5990
void func_003d5990(s32 object, u32 first, u32 second)
{
    *(u32*)(object + 0x18) = first;
    *(u32*)(object + 0x1c) = second;
}
#pragma optimization_level 2

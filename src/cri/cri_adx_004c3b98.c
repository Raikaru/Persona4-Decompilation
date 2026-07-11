#include "type.h"
#pragma optimization_level 3
// FUN_004C3B98
void func_004c3b98(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x7c) = second;
    *(u32*)(object + 0x78) = first;
}
#pragma optimization_level 2

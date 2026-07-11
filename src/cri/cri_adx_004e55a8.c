#include "type.h"
#pragma optimization_level 3
// FUN_004E55A8
void func_004e55a8(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x24) = second;
    *(u32*)(object + 0x20) = first;
}
#pragma optimization_level 2

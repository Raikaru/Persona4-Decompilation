#include "type.h"
#pragma optimization_level 3
// FUN_004CED28
void func_004ced28(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x54) = second;
    *(u32*)(object + 0x50) = first;
}
#pragma optimization_level 2

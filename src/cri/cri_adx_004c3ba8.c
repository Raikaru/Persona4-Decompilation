#include "type.h"
#pragma optimization_level 3
// FUN_004C3BA8
void func_004c3ba8(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x84) = second;
    *(u32*)(object + 0x80) = first;
}
#pragma optimization_level 2

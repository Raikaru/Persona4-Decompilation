#include "type.h"
#pragma optimization_level 3
// FUN_004E55B8
void func_004e55b8(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x2c) = second;
    *(u32*)(object + 0x28) = first;
}
#pragma optimization_level 2

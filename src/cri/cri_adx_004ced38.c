#include "type.h"
#pragma optimization_level 3
// FUN_004CED38
void func_004ced38(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x4c) = second;
    *(u32*)(object + 0x48) = first;
}
#pragma optimization_level 2

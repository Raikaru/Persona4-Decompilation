#include "type.h"

#pragma optimization_level 3
// FUN_004C1000
void func_004c1000(int object, u32 value)
{
    *(u32*)(object + 0x54) = value;
}
#pragma optimization_level 2

#include "type.h"

#pragma optimization_level 3
// FUN_004C1010
void func_004c1010(int object, u32 value)
{
    *(u32*)(object + 0x5c) = value;
}
#pragma optimization_level 2

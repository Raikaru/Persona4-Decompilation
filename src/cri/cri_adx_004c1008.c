#include "type.h"

#pragma optimization_level 3
// FUN_004C1008
void func_004c1008(int object, u32 value)
{
    *(u32*)(object + 0x58) = value;
}
#pragma optimization_level 2

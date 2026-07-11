#include "type.h"

#pragma optimization_level 3
// FUN_004D1220
void func_004d1220(int object, u32 value)
{
    *(u32*)(object + 0x58) = value;
}
#pragma optimization_level 2

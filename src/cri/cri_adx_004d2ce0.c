#include "type.h"
#pragma optimization_level 3
// FUN_004D2CE0
u32 func_004d2ce0(int object, u32 value)
{
    *(u32*)(object + 0x2c) = value;
    return 1;
}
#pragma optimization_level 2

#include "type.h"
#pragma optimization_level 3
// FUN_004C0FC0
u32 func_004c0fc0(int object)
{
    *(u32*)(object + 0x4c) = 1;
    return 1;
}
#pragma optimization_level 2

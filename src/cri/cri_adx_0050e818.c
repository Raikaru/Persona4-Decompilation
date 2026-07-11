#include "type.h"
#pragma optimization_level 3
// FUN_0050E818
u32 func_0050e818(int source, int destination)
{
    u32 value;

    value = *(u32*)(source + 0x34);
    *(u32*)(destination + 0x4c) = value;
    return value;
}
#pragma optimization_level 2

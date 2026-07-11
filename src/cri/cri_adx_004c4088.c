#include "type.h"
#pragma optimization_level 3
// FUN_004C4088
void func_004c4088(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x100) = second;
    *(u32*)(object + 0xfc) = first;
}
#pragma optimization_level 2

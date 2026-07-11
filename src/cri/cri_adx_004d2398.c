#include "type.h"
#pragma optimization_level 3
// FUN_004D2398
void func_004d2398(int object, u32 first, u32 second)
{
    *(u32*)(object + 0x3c) = second;
    *(u32*)(object + 0x38) = first;
}
#pragma optimization_level 2

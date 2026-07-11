#include "type.h"

#pragma optimization_level 1
// FUN_00246450
void func_00246450(u32 value)
{
    *(u16*)0x00881474 |= 1;
    *(u32*)0x00881468 = value;
}
#pragma optimization_level 2

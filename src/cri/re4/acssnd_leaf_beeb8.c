/* Recovered contiguous ACSSND byte accessors at 004BEEB8-004BEEC7. */
#include "type.h"

#pragma schedule on
// FUN_004BEEB8
void func_004beeb8(int object, u8 value)
{
    *(u8 *)(object + 0x8c) = value;
}
#pragma schedule off

#pragma optimization_level 3
// FUN_004BEEC0
s8 func_004beec0(int object)
{
    return *(s8 *)(object + 0x8c);
}
#pragma optimization_level 2

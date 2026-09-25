/* The contiguous ADX voice-handle parameter setters and getters. */
#include "type.h"

#pragma optimization_level 3

// FUN_004C1000
void func_004c1000(int object, u32 value)
{
    *(u32 *)(object + 0x54) = value;
}

// FUN_004C1008
void func_004c1008(int object, u32 value)
{
    *(u32 *)(object + 0x58) = value;
}

// FUN_004C1010
void func_004c1010(int object, u32 value)
{
    *(u32 *)(object + 0x5c) = value;
}

// FUN_004C1018
u32 func_004c1018(int object)
{
    return *(u32 *)(object + 0x54);
}

// FUN_004C1020
u32 func_004c1020(int object)
{
    return *(u32 *)(object + 0x58);
}

// FUN_004C1028
u32 func_004c1028(int object)
{
    return *(u32 *)(object + 0x5c);
}

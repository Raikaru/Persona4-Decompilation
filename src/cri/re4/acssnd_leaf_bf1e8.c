/* Recovered contiguous ACSSND word accessors at 004BF1E8-004BF23F. */
#include "type.h"

#pragma optimization_level 3
// FUN_004BF1E8
void func_004bf1e8(int object, u32 value)
{
    *(u32 *)(object + 0xa8) = value;
}

// FUN_004BF1F0
void func_004bf1f0(int object, u32 value)
{
    *(u32 *)(object + 0xac) = value;
}

// FUN_004BF1F8
void func_004bf1f8(int object, u32 value)
{
    *(u32 *)(object + 0xb0) = value;
}

// FUN_004BF200
u32 func_004bf200(int object)
{
    return *(u32 *)(object + 0xa8);
}

// FUN_004BF208
u32 func_004bf208(int object)
{
    return *(u32 *)(object + 0xac);
}

// FUN_004BF210
u32 func_004bf210(int object)
{
    return *(u32 *)(object + 0xb0);
}

// FUN_004BF218
void func_004bf218(int object, u32 value)
{
    *(u32 *)(object + 0xb4) = value;
}

// FUN_004BF220
u32 func_004bf220(int object)
{
    return *(u32 *)(object + 0xb4);
}

// FUN_004BF228
void func_004bf228(int object, u32 value)
{
    *(u32 *)(object + 0xb8) = value;
}

// FUN_004BF230
u32 func_004bf230(int object)
{
    return *(u32 *)(object + 0xb8);
}

// FUN_004BF238
void func_004bf238(int object, u32 value)
{
    *(u32 *)(object + 0xcc) = value;
}
#pragma optimization_level 2

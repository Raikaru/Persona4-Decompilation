#include "type.h"

// FUN_004BF938
void func_004bf938(int object, int value)
{
    u32 previous = *(u32 *)(object + 0xc4);
    *(u32 *)(object + 0xc8) = 1;
    *(u32 *)(object + 0xc4) = previous + (u32)value;
}

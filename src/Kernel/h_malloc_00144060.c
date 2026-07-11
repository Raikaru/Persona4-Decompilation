#include "type.h"

// FUN_00144060
void func_00144060(u32* output, u32 image, u32 width, u32 height)
{
    u64 value;

    value = ((u64)height << 0x38) | ((u64)width << 0x30) |
            ((u64)image << 0x20);
    output[0] = (u32)(value & 0xffffffffULL);
    output[1] = (u32)(value >> 0x20);
    output[2] = 0x50;
    output[3] = 0;
}

#include "type.h"

// FUN_001440D0
void func_001440d0(u32* output, u32 flag, u32 image, u32 height)
{
    u64 value;

    value = ((u64)flag << 0x3b) | ((u64)height << 0x30) |
            ((u64)image << 0x20);
    output[0] = (u32)(value & 0xffffffffULL);
    output[1] = (u32)(value >> 0x20);
    output[2] = 0x51;
    output[3] = 0;
}

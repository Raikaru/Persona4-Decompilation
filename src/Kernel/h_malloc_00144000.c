#include "type.h"

// FUN_00144000
void func_00144000(u32* out, u64 address, s32 a2, s32 a3, s32 a4, s32 a5,
                   s32 a6, u32 a7)
{
    out[0] = ((u32)a6 << 0xf) | a7;
    out[1] = ((u32)a5 << 0xe) | ((u32)a4 << 0xf) |
             ((u32)a3 << 0x1a) | ((u32)a2 << 0x1c);
    out[2] = (u32)(address & 0xffffffffULL);
    out[3] = (u32)(address >> 0x20);
}

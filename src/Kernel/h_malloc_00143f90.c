#include "type.h"

// FUN_00143F90
void func_00143f90(u64* out, u32 a1, s32 a2, u32 a3, u32 a4, u32 a5,
                   u32 a6)
{
    u64 packet;

    packet = ((u64)a1 << 0x3f) |
             ((u64)(u32)(a2 & ~0xf) << 0x20) |
             ((u64)a3 << 0x1f) |
             ((u64)a4 << 0x1c) |
             ((u64)a5 << 0x1a) |
             (u64)a6;
    *out = packet;
}

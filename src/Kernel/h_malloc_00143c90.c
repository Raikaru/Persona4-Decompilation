#include "type.h"

extern void func_00143cf0(u64 texture, u64 packet, u64 source, s32 a3,
                          s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9,
                          s32 a10);

// FUN_00143C90
void func_00143c90(u64 texture, u64 packet, u64 source, s32 a3, s32 a4,
                   s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, s32 a10)
{
    func_00143cf0(texture, packet, source, 0x400, a3, a4, a5, a6, a7, a8,
                  a9);
}

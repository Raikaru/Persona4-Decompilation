#include "type.h"

extern u8 D_007D0F00[];
extern void func_00410370(u64 source, void* bytes, u16* header);
extern void func_003f34e0(void* packet, u32 size);
extern void func_00143c90(u32 texture, void* packet, u32 source, s32 a3,
                           s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9);

// FUN_00143BA0
void func_00143ba0(u64 source, u32 owner, s32 tileIndex, s32 tileCount)
{
    u8 headerBytes[4];
    u16 header[2];
    u32 texture;
    u32 tileBytes;

    func_00410370(source, headerBytes, header);
    texture = header[0] & 0x3fff;
    tileBytes = tileCount * 0x10;
    if (tileBytes < 0x1c1)
    {
        func_00143c90(texture, (void*)&D_007D0F00, owner, 0, 0,
                      tileIndex << 4, tileBytes, 0, 0, 0);
    }
    else
    {
        func_00143c90(texture, (void*)&D_007D0F00, owner, 0, 0,
                      tileIndex << 4, 0x1c0, 0, 0,
                      tileBytes - 0x1c0);
    }
    if (&D_007D0F00 != NULL)
    {
        func_003f34e0((void*)&D_007D0F00, 0x102);
    }
}

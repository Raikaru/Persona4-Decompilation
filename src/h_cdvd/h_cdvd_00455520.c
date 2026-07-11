#include "h_cdvd_internal.h"

extern void func_0043f810(void* destination, const void* source, u32 size);

// FUN_00455520
u32 func_00455520(void* slotData, void* dst, u32 size)
{
    struct HCdvdStreamData
    {
        u8 reserved[0x88];
        u8* fileMemory;
        s32 fileSize;
        s32 fileOffset;
    } *data;
    u32 available;
    u32 amount;

    data = (struct HCdvdStreamData*)((u8*)slotData + 0x70);
    if (data->fileSize > data->fileOffset)
    {
        goto read_file;
    }
    return 0;

read_file:
    available = data->fileSize - data->fileOffset;
    amount = size;
    if (available < amount)
    {
        amount = available;
    }
    func_0043f810(dst, data->fileMemory + data->fileOffset, amount);
    data->fileOffset += amount;
    return amount;
}

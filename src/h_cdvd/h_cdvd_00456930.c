#include "h_cdvd_internal.h"

extern const char D_00711758[];
extern s32 func_004275a8(s32 fd, void* dst, u32 size);

// FUN_00456930
s32 func_00456930(void* slot, void* dst, u32 size)
{
    s32 amount;

    func_004244c8(D_00711758);
    amount = func_004275a8(*(s32*)((u8*)slot + 0x74), dst, size);
    if (amount < 0)
    {
        return 0;
    }
    *(s64*)((u8*)slot + 0x10) += amount;
    return amount;
}

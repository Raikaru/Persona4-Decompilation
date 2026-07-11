#include "h_cdvd_internal.h"

extern const char D_00711748[];
extern s32 func_00427338(s32 fd, void* dst, u32 size);

// FUN_004568A0
s32 func_004568a0(void* slot, void* dst, u32 size)
{
    s32 amount;

    func_004244c8(D_00711748);
    amount = func_00427338(*(s32*)((u8*)slot + 0x74), dst, size);
    if (amount < 0)
    {
        return 0;
    }
    *(u32*)((u8*)slot + 0x38) = 3;
    *(s64*)((u8*)slot + 0x10) += amount;
    return amount;
}

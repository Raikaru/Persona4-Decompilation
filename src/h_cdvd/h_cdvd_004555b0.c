#include "h_cdvd_internal.h"

// FUN_004555B0
u32 func_004555b0(void* slotData)
{
    u8* data = (u8*)slotData + 0x70;
    return -(*(s32*)(data + 0x8c) <= *(s32*)(data + 0x90));
}

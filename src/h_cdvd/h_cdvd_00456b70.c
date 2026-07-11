#include "h_cdvd_internal.h"

extern const char D_00711780[];

// FUN_00456b70
void* func_00456b70(void* contextData, u32 index)
{
    s32 i = index;
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;

    func_004244c8(D_00711780);
    if (i < context->count)
    {
        return context->slots + i * 0x90;
    }
    return NULL;
}

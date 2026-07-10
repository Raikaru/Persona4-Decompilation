#include "h_cdvd_internal.h"

// FUN_00456BE0
void func_00456be0(void* contextData)
{
    HCdvdFileContext* context = (HCdvdFileContext*)contextData;
    func_004244c8(D_007117a0);
    HCDVD_FREE(context->slots);
}

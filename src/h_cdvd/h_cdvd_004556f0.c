#include "h_cdvd_internal.h"

// FUN_004556F0
void func_004556f0(void* contextData)
{
    HCdvdStreamContext* context = (HCdvdStreamContext*)contextData;
    HCDVD_FREE(context->slots);
}

#include "h_cdvd_internal.h"

// FUN_004553C0
u32 func_004553c0(HCdvd* cdvd)
{
    return cdvd->readState == 4;
}

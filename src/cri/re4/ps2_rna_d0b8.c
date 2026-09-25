#include "cri_xpt.h"

extern Sint32 D_0073A748;
extern Sint32 D_0073A740;

// FUN_004ED0B8
Sint32 func_004ed0b8(Uint8 *arg0)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        return *(Sint32 *)(arg0 + 0x30);
    }
    return 0;
}

// FUN_004ED0E8
Sint32 func_004ed0e8(Uint8 *arg0)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        return *(Sint32 *)(arg0 + 0x38);
    }
    return 0;
}

#include "cri_xpt.h"

extern Sint32 D_0073A748;
extern Sint32 D_0073A740;

// FUN_004ED150
Sint32 func_004ed150(Uint8 *arg0)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        return *(Sint32 *)(arg0 + 0x5c);
    }
    return 0;
}

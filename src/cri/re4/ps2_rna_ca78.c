#include "cri_xpt.h"

extern Sint32 D_0073A748;
extern Sint32 D_0073A740;
extern void func_004cd3f0(const Char8 *msg);
extern Char8 D_0075CA30[];
extern Char8 D_0075CA58[];

// FUN_004ECA78
void func_004eca78(void)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        func_004cd3f0(D_0075CA30);
    }
}

// FUN_004ECAC0
void func_004ecac0(void)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        func_004cd3f0(D_0075CA58);
    }
}

// FUN_004ECB08
void func_004ecb08(Uint8 *arg0, Uint32 *out0, Uint32 *out1)
{
    (void)arg0;
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        *out0 = 0;
        *out1 = 48000;
    }
}

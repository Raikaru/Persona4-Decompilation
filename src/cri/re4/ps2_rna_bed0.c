#include "cri_xpt.h"

extern Sint32 D_0073A748;
extern Sint32 D_0073A740;
extern Sint32 func_004e58a0();

// FUN_004EBED0
void func_004ebed0(void *arg0)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        void *tmp = arg0;

        func_004e58a0(0xb, &tmp, 1, NULL, 0);
    }
}

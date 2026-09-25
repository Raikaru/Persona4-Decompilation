#include "cri_xpt.h"

extern Sint32 D_0073A748;
extern Sint32 D_0073A740;
extern void func_004cd3f0(const Char8 *msg);
extern Char8 D_0075CB68[];

// FUN_004ED1F0
void func_004ed1f0(void)
{
    if (D_0073A748 != 1 || D_0073A740 > 0) {
        func_004cd3f0(D_0075CB68);
    }
}

/* b119 candidate for func_003c5510 (0x003c5510), 220B vs 224B,
   differing words (reloc-masked): 27, residual is register colouring
   (GPR temp allocation for the base pointer and the constant set). */

#include "include_asm.h"
#include "type.h"

extern s32 iGpffffb6f0;
extern u8 *iGpffffb6e8;
extern s32 iGpffffb6f4;
extern u8 D_008872E0[];
extern void *func_003e1210(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_003e12f0(u8 *arg0);

#pragma schedule on
s32 func_003c5510(s32 arg0, s32 arg1) {
    s32 temp;
    s32 idx;
    u8 *p;

    iGpffffb6f0 = arg1;
    if (iGpffffb6f4 != 0) {
        goto main;
    }
    temp = (s32)func_003e1210(0xC, 0x32, 4, 0x40502);
    iGpffffb6e8 = (u8 *)temp;
    if (temp == 0) {
        if (iGpffffb6e8 != NULL) {
            func_003e12f0(iGpffffb6e8);
            iGpffffb6e8 = NULL;
        }
        return 0;
    }
main:
    p = D_008872E0;
    idx = iGpffffb6f0;
    p += idx;
    *(s16 *)p = 1;
    p[0x8] = 3;
    p[0x9] = 4;
    p[0xA] = 5;
    p[0xC] = 1;
    p[0x10] = 2;
    p[0x18] = 6;
    p[0x28] = 4;
    p[0x29] = 8;
    p[0x2A] = 0;
    p[0x2B] = 1;
    p[0x2C] = 2;
    iGpffffb6f4 += 1;
    p[0x2D] = 0x10;
    return arg0;
}
#pragma schedule off

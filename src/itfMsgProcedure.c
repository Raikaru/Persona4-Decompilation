/* Whole-file translation unit: src/itfMsgProcedure.c */
/* Original filename recovered from embedded __FILE__ strings. */
#include "type.h"

// Donor calls this implicitly (no prototype), so keep the old-style form:
// the retail code passes $a0 straight through to func_00277840.
extern s32 func_00277840();
extern void func_0046d730(const void *module, u32 line);
extern char D_0063BF60[];

// FUN_0027B6E0
s32 func_0027b6e0(s32 param_1, s32 param_2)
{
    s32 base;
    s32 addr;

    base = func_00277840();
    if (param_2 >= 4) {
        func_0046d730(D_0063BF60, 0x1F);
    }
    addr = param_2 * 4;
    addr += base;
    return *(s32 *)(addr + 4);
}

// FUN_0027B750
void func_0027b750(s32 param_1, s32 param_2, s32 param_3)
{
    s32 base;
    s32 addr;

    base = func_00277840();
    if (param_2 >= 4) {
        func_0046d730(D_0063BF60, 0x27);
    }
    addr = param_2 * 4;
    addr += base;
    *(s32 *)(addr + 4) = param_3;
}

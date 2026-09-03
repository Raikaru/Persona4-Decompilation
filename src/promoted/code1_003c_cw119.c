#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (2004-09)
   rather than the project default b210: retail linked prebuilt RenderWare
   objects next to Atlus's b210 code, and this block carries b119-era idioms
   (`movz` conditional moves that b198/b210 never emit; measured 2026-09-03).
   The compiler is named in config/compiler_units.txt. Fallbacks stay under
   asm/nonmatchings/code1_003c. */

/* gp - 0x48F8 = 0x007647F8 */
extern s32 iGpffffb708;
extern u8 func_003ca740[];
extern u8 func_003ca780[];
extern u8 func_003ca7a0[];

/* measured: schedule on fills ca830's call and return delay slots. */
#pragma schedule on
// FUN_003CA830
u8 *func_003ca830(u8 *arg0) {
    u8 *f60 = func_003ca7a0;
    u8 *f00 = func_003ca740;
    u8 *f40 = func_003ca780;
    u8 *node = arg0 + iGpffffb708;

    *(s32 *)(node + 0) = 0;
    *(s32 *)(node + 4) = 0;
    *(s32 *)(node + 8) = 0;
    *(s32 *)(node + 0x10) = *(s32 *)(arg0 + 0x18);
    *(s32 *)(node + 0x14) = *(s32 *)(arg0 + 0x1C);
    *(s32 *)(node + 0x18) = *(s32 *)(arg0 + 0x10);
    *(u8 **)(arg0 + 0x10) = f60;
    *(u8 **)(arg0 + 0x18) = f00;
    *(u8 **)(arg0 + 0x1C) = f40;
    *(s32 *)(node + 0xC) = 0;
    return arg0;
}

/* measured: closes the schedule bracket. */
#pragma schedule off

extern s32 func_003ce560(s32 arg0, u8 *arg1);
extern s32 func_003df240(s32 arg0, s32 arg1, s32 arg2);
extern s32 func_003c5d10(s32 arg0, u8 *arg1, u8 *arg2);
extern u8 *func_003c9c20(u8 *arg0);
extern s32 func_003cebb0(s32 arg0, u8 *arg1);

/* `movz $s0,$zero,$v0` is the b119 lowering of `call() ? arg0 : 0`. */
// FUN_003CB790
#pragma schedule on
s32 func_003cb790(s32 arg0, s32 arg1, u8 *arg2) {
    return func_003ce560(arg0, arg2) ? arg0 : 0;
}
// FUN_003CB7E0
s32 func_003cb7e0(s32 arg0, s32 arg1, u8 *arg2) {
    return func_003cebb0(arg0, arg2) ? arg0 : 0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

// FUN_003CB870
#pragma schedule on
s32 func_003cb870(s32 arg0, s32 arg1, u8 *arg2) {
    u8 *temp;

    temp = func_003c9c20(arg2);
    *(s32 *)(arg2 + 0x78) = func_003c5d10(arg0, temp, temp + 0x10);
    return *(s32 *)(arg2 + 0x78) ? arg0 : 0;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

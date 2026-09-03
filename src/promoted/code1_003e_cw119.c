#include "include_asm.h"
#include "type.h"

/* RenderWare-derived functions verified with MWCCPS2 3.0.1 b119 (see
   config/compiler_units.txt and docs/matching.md). Fallbacks stay under
   asm/nonmatchings/code1_003e. */

extern s32 (*DAT_0088737c_abs[])(void);
extern s32 func_003ec480(s32 arg0);

/* `movz $s0,$zero,$v0` is the b119 lowering of `call() ? arg0 : 0`. */
// FUN_003E82A0
#pragma schedule on
u8 *func_003e82a0(u8 *arg0) {
    return DAT_0088737c_abs[0]() ? arg0 : NULL;
}
// FUN_003E82E0
u8 *func_003e82e0(u8 *arg0) {
    return func_003ec480(*(s32 *)(arg0 + 0x60)) ? arg0 : NULL;
}
/* measured: closes the schedule bracket; the unit default is off. */
#pragma schedule off

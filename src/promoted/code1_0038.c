/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00383A40)
#include "type.h"

s32 func_00383720(u8 *arg0);

// FUN_00383A40
s32 func_00383a40(u8 *arg0) {
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    if (*(u16 *)(temp_16 + 4) & 4) {
        return -1;
    }
    if (*(s32 *)(temp_16 + 0x14) == 0) {
        *(s32 *)(temp_16 + 0x14) = func_00383720(temp_16);
    }
    return 0;
}
#endif /* P4_UNIT_00383A40 */

#if defined(P4_UNIT_00388BA0)
#include "type.h"

extern void (*D_008873ec[])(s32);

// FUN_00388BA0
void func_00388ba0(u8 *arg0) {
    D_008873ec[0](*(s32 *)(arg0 + 0x38));
}
#endif /* P4_UNIT_00388BA0 */

#if defined(P4_UNIT_00388E20)
#include "type.h"

// FUN_00388E20
s32 func_00388e20(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 2);
}
#endif /* P4_UNIT_00388E20 */

#if defined(P4_UNIT_00389160)
#include "type.h"

// FUN_00389160
s32 func_00389160(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 8);
}
#endif /* P4_UNIT_00389160 */

#if defined(P4_UNIT_00389180)
#include "type.h"

void func_003891b0(u8 *arg0, u8 arg1, u8 arg2, u8 arg3);

// FUN_00389180
void func_00389180(u8 *arg0) {
    func_003891b0(arg0, 0xFF, 0xFF, 0xFF);
}
#endif /* P4_UNIT_00389180 */

#if defined(P4_UNIT_003891E0)
#include "type.h"

// FUN_003891E0
s32 func_003891e0(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x100);
}
#endif /* P4_UNIT_003891E0 */

#if defined(P4_UNIT_00389330)
#include "type.h"

// FUN_00389330
s32 func_00389330(u8 *arg0) {
    return !(*(u16 *)(*(u8 **)(arg0 + 0x38) + 0x4C) & 0x400);
}
#endif /* P4_UNIT_00389330 */

#if defined(P4_UNIT_0038EE10)
#include "type.h"

s32 func_00106330(u32 arg0);

// FUN_0038EE10
s32 func_0038ee10(void) {
    return !func_00106330(0x1472);
}
#endif /* P4_UNIT_0038EE10 */

#if defined(P4_UNIT_0038F600)
#include "type.h"

extern u8 *D_007246AC;

// FUN_0038F600
void func_0038f600(u8 *arg0) {
    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    D_007246AC = arg0;
}
#endif /* P4_UNIT_0038F600 */

#if defined(P4_UNIT_0038FB20)
#include "type.h"

// measured: b210 at -O2 folds (a*0x10)+0x30 into one addiu in the beqz delay
// slot (11 words); schedule on with the constant materialized first reproduces
// retail's hoisted addiu $a1,0x30 + addu $v0,$a1,$v0 delay-slot pair (12 words).
#pragma schedule on

// FUN_0038FB20
s32 func_0038fb20(u8 *arg0) {
    s32 var_2;

    var_2 = 0x30;
    var_2 += *(u16 *)(arg0 + 0x1E) * 0x10;
    if (*(s32 *)arg0 & 1) {
        var_2 += *(u16 *)(arg0 + 0x1C) * 2;
    }
    return var_2;
}
// measured: closing bracket for the schedule-on above; the function body is
// already compiled, so this off only satisfies decomp_lint P001 balance.
#pragma schedule off
#endif /* P4_UNIT_0038FB20 */

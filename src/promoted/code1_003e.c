/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003E05D0)
#include "type.h"

/* measured: removing this pragma takes func_003e05d0 nd 0 -> nd 16: retail fills the
   jr $ra delay slot with sw $v1, 0xc($a0) and hoists move $v0,$a0 before the and;
   baseline -O2 emits lw; lui; ori; and; sw; move; jr; nop. */
#pragma optimization_level 3
// FUN_003E05D0
u8 *func_003e05d0(u8 *arg0) {
    *(s32 *)(arg0 + 0xC) &= 0xFFFDFFFC;
    return arg0;
}
#endif /* P4_UNIT_003E05D0 */

#if defined(P4_UNIT_003E1020)
#include "type.h"

extern s32 D_008866D8;

/* measured: removing this pragma takes func_003e1020 nd 0 -> nd 6: retail fills the
   jr $ra delay slot with sw $a0, -0x54a0($gp); baseline -O2 emits sw; jr; nop. */
#pragma optimization_level 3
// FUN_003E1020
void func_003e1020(s32 arg0) {
    D_008866D8 = arg0;
}
#endif /* P4_UNIT_003E1020 */

#if defined(P4_UNIT_003E3070)
#include "type.h"

// FUN_003E3070 NONMATCHING
s32 func_003e3070(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *var_3;

    var_3 = *(u8 **)(arg0 + 0x10);
    if (var_3 != NULL) {
loop_1:
        if (*(s32 *)(var_3 + 8) != arg1) {
            var_3 = *(u8 **)(var_3 + 0x30);
            if (var_3 == NULL) {
            } else {
                goto loop_1;
            }
        }
    }
    if (var_3 != NULL) {
        *(s32 *)(var_3 + 0x18) = arg2;
        return *(s32 *)var_3;
    }
    return -1;
}
#endif /* P4_UNIT_003E3070 */

#if defined(P4_UNIT_003E30C0)
#include "type.h"

// FUN_003E30C0 NONMATCHING
s32 func_003e30c0(u8 *arg0, s32 arg1, s32 arg2) {
    u8 *var_3;

    var_3 = *(u8 **)(arg0 + 0x10);
    if (var_3 != NULL) {
loop_1:
        if (*(s32 *)(var_3 + 8) != arg1) {
            var_3 = *(u8 **)(var_3 + 0x30);
            if (var_3 == NULL) {
            } else {
                goto loop_1;
            }
        }
    }
    if (var_3 != NULL) {
        *(s32 *)(var_3 + 0x1C) = arg2;
        return *(s32 *)var_3;
    }
    return -1;
}
#endif /* P4_UNIT_003E30C0 */

#if defined(P4_UNIT_003E43A0)
#include "type.h"

extern s32 D_0088731C;

/* measured: removing this pragma takes func_003e43a0 nd 0 -> nd 15: retail fills the
   jr $ra delay slot with sw $v1, -0x485c($gp) and hoists move $v0,$a0 before the
   addiu; baseline -O2 emits lw; addiu; sw; move; jr; nop. */
#pragma optimization_level 3
// FUN_003E43A0
s32 func_003e43a0(s32 arg0) {
    D_0088731C -= 1;
    return arg0;
}
#endif /* P4_UNIT_003E43A0 */

#if defined(P4_UNIT_003E4510)
#include "type.h"

/* measured: removing this pragma takes func_003e4510 nd 0 -> nd 6: retail fills the
   jr $ra delay slot with addiu $v0, $zero, 1; baseline -O2 emits addiu; jr; nop. */
#pragma optimization_level 3
// FUN_003E4510
s32 func_003e4510(void) {
    return 1;
}
#endif /* P4_UNIT_003E4510 */

#if defined(P4_UNIT_003E5510)
#include "type.h"

extern s32 D_00886700;

/* measured: removing this pragma takes func_003e5510 nd 0 -> nd 6: retail fills the
   jr $ra delay slot with sw $a0, -0x5478($gp); baseline -O2 emits sw; jr; nop. */
#pragma optimization_level 3
// FUN_003E5510
void func_003e5510(s32 arg0) {
    D_00886700 = arg0;
}
#endif /* P4_UNIT_003E5510 */

#if defined(P4_UNIT_003E6750)
#include "type.h"

/* measured: removing this pragma takes func_003e6750 nd 0 -> nd 15: retail fills the
   jr $ra delay slot with sw $v1, ($a1) and hoists move $v0,$a0 before the addiu;
   baseline -O2 emits lw; addiu; sw; move; jr; nop. */
#pragma optimization_level 3
// FUN_003E6750
s32 func_003e6750(s32 arg0, s32 *arg1) {
    *arg1 += 1;
    return arg0;
}
#endif /* P4_UNIT_003E6750 */

#if defined(P4_UNIT_003E8910)
#include "type.h"

extern s32 D_00887330;

/* measured: removing this pragma takes func_003e8910 nd 0 -> nd 6: retail fills the
   jr $ra delay slot with lw $v0, -0x4848($gp); baseline -O2 emits lw; jr; nop. */
#pragma optimization_level 3
// FUN_003E8910
s32 func_003e8910(void) {
    return D_00887330;
}
#endif /* P4_UNIT_003E8910 */

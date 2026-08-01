/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00290EC0)
/* Source unit: src/Event/mt_misc_00290ec0.c */
#include "type.h"

/* opt_loop_invariants on: measured nd 124 -> 0, object 292/304 -> 292/304. */
// FUN_00290EC0
void func_00290ec0(int param_1, u32 param_2)
{
    int iVar1;

    iVar1 = *(int *)(param_1 + 4) * 0x2c;
    iVar1 = iVar1 + param_1;

    *(u8 *)(iVar1 + 0x14) = 0;
    *(u32 *)(iVar1 + 0x10) = 0;
    *(u32 *)(iVar1 + 0x38) = 0;
    *(u32 *)(iVar1 + 0x34) = param_2;
    *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;

    return;
}
#endif /* P4_UNIT_00290EC0 */

#if defined(P4_UNIT_00291060)
/* Source unit: src/Event/mt_misc_00291060.c */
#include "type.h"

// FUN_00291060
void func_00291060(u32 *param_1)
{
    *param_1 = 1;
    param_1[2] = 0;

    return;
}
#endif /* P4_UNIT_00291060 */

#if defined(P4_UNIT_00291360)
/* Source unit: src/Event/mt_misc_00291360.c */
#include "type.h"

extern int func_00145250();

// FUN_00291360
u16 func_00291360(int param_1, int param_2)
{
    int lVar2;

    if (param_2 >= 0x10) {
        return 0;
    }

    lVar2 = func_00145250();

    if (lVar2 == 0) {
        return 0;
    }

    return *(u16 *)((u8 *)((int)param_2 * 2) + param_1 + 0x170);
}
#endif /* P4_UNIT_00291360 */

#if defined(P4_UNIT_00298100)
/* Source unit: src/Event/mt_misc_00298100.c */
#include "type.h"

extern int func_0045a3e0();

// FUN_00298100
u64 func_00298100(s16 param_1)
{
    func_0045a3e0(param_1, 1);

    return 0;
}
#endif /* P4_UNIT_00298100 */

#if defined(P4_UNIT_00298190)
/* Source unit: src/Event/mt_misc_00298190.c */
#include "type.h"

extern int func_0045aac0();
extern int func_0045a9a0();

// FUN_00298190
u64 func_00298190(s16 param_1, int param_2)
{
    int iVar1;

    iVar1 = param_2;
    if (iVar1 != 0) {
        func_0045aac0(param_1, 0, param_2);
    }
    else {
        func_0045a9a0(param_1, 0, param_2);
    }

    return 0;
}
#endif /* P4_UNIT_00298190 */

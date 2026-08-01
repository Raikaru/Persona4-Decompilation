/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0025F230)
/* Source unit: src/Event/Fcl/fclShopMisc_0025f230.c */
#include "type.h"

typedef int (*code)(...);

#pragma alias DAT_008873ec_abs DAT_008873ec
extern code DAT_008873ec_abs[];

// func_0046b0d0 is intentionally left undeclared (implicit old-style call,
// exactly as in the P3 donor FUN_0040e580): a typed prototype makes mwcc
// emit andi zero-extensions the retail never has.

// FUN_0025F230
void func_0025f230(u32 param_1)
{
    int i;

    if (param_1 != 0) {
        for (i = 0; i < *(int *)(*(int *)((int)param_1 + 4) + 4); i = i + 1) {
            func_0046b0d0((void *)*(u32 *)(*(int *)((int)param_1 + 8) + i * 4));
        }
        DAT_008873ec_abs[0](param_1);
    }
}
#endif /* P4_UNIT_0025F230 */

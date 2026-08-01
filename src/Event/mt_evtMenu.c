/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00285260)
/* Source unit: src/Event/mt_evtMenu_00285260.c */
#include "type.h"

#pragma alias DAT_00882170_abs DAT_00882170
extern u32 DAT_00882170_abs[];

// FUN_00285260
void func_00285260(void)
{
    int iVar1;
    u32 *puVar2;

    iVar1 = 0;
    puVar2 = (u32 *)DAT_00882170_abs;
    while (iVar1 < 0xd) {
        if (iVar1 != 0) {
            puVar2[iVar1] = 0;
        }
        iVar1 = iVar1 + 1;
    }
}
#endif /* P4_UNIT_00285260 */

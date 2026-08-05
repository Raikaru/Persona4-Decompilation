/* Source unit: src/Event/mt_evtMenu_00285260.c */
#include "type.h"
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

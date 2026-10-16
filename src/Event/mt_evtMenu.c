/* Source unit: src/Event/mt_evtMenu_00285260.c */
#include "type.h"
#include "scene_event_internal.h"
extern u32 DAT_00882170_abs[];




// Intent: Clears menu slot words 1 to 12 of the table at DAT_00882170 (word 0 is kept) [inferred]
// FUN_00285260
void evtMenuClearSlots(void)
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

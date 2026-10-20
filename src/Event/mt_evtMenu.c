/* Source unit: src/Event/mt_evtMenu_00285260.c */
#include "type.h"
#include "scene_event_internal.h"
extern u32 DAT_00882170_abs[]; /* thirteen menu slots; slot zero is preserved */




// Intent: Clears menu slot words 1 to 12 of the table at DAT_00882170 (word 0 is kept) [inferred]
// FUN_00285260
void evtMenuClearSlots(void)
{
    int slotIndex;
    u32 *slots;

    slotIndex = 0;
    slots = (u32 *)DAT_00882170_abs;
    while (slotIndex < 0xd) {
        if (slotIndex != 0) {
            slots[slotIndex] = 0;
        }
        slotIndex = slotIndex + 1;
    }
}

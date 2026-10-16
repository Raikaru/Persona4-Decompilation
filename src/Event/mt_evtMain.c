/* Source unit: src/Event/mt_evtMain.c */

#include "type.h"
#include "scene_event_internal.h"

extern u32 DAT_007645D8;



// Intent: Sets the event flag DAT_007645D8 to 1 when the argument is 1, otherwise to 0 [inferred]
// FUN_0028B270
void evtMainSetFlag(int param_1)
{
    if (param_1 == 1) {
        DAT_007645D8 = 1;
    }
    else {
        DAT_007645D8 = 0;
    }
}

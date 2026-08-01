/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0028B270)
/* Source unit: src/Event/mt_evtMain.c */

#include "type.h"

extern u32 DAT_007645D8;

// FUN_0028B270
void func_0028b270(int param_1)
{
    if (param_1 == 1) {
        DAT_007645D8 = 1;
    }
    else {
        DAT_007645D8 = 0;
    }
}
#endif /* P4_UNIT_0028B270 */

/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0028F960)
/* Source unit: src/Event/mt_evtLoadSave.c */

#include "type.h"

// FUN_0028F960
float func_0028f960(float param_1, float param_2, float param_3, long param_4)
{
    if (param_4 != 0) {
        param_2 = param_2 * (1.0f - param_1) + param_3 * param_1;
    }
    return param_2;
}
#endif /* P4_UNIT_0028F960 */

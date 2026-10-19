/* Source unit: src/Event/mt_evtLoadSave.c */

#include "type.h"



/* Blend current toward target when enabled; otherwise preserve current. */
// FUN_0028F960
float evtLerpFloatIfEnabled(float blend, float current, float target, long enabled)
{
    if (enabled != 0) {
        current = current * (1.0f - blend) + target * blend;
    }
    return current;
}

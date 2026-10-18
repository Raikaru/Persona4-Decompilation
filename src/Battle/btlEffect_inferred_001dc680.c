#include "btl_action_internal.h"
/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlBoss.c; members 001dc680-001dc680 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
u32 btlEffectSelectSelfCandidate(void* object);
/* Seed the action candidate array with the action itself and set the candidate count to one. */
// FUN_001DC680
u32 btlEffectSelectSelfCandidate(void* object)
{
    *(void **)&((BtlAction *)object)->unk_38 = object;
    ((BtlAction *)object)->unk_6a = 1;
    return 1;
}

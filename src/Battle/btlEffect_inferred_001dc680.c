#include "btl_action_internal.h"
/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlBoss.c; members 001dc680-001dc680 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
u32 btlEffectSelectSelfTarget(void* object);
/* Make the action its own sole selected target: first selected-target slot (+0x38) and count (+0x6A). */
// FUN_001DC680
u32 btlEffectSelectSelfTarget(void* object)
{
    *(void **)&((BtlAction *)object)->unk_38 = object;
    ((BtlAction *)object)->unk_6a = 1;
    return 1;
}

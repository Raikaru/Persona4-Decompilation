#include "btl_action_internal.h"

#include "include_asm.h"
#include "type.h"
u32 btlEffectSelectSelfTarget(void* object);
/* Make the action its own sole selected target by setting the first selected-target slot to itself
 * and the count to 1. */
// FUN_001DC680
u32 btlEffectSelectSelfTarget(void* object)
{
    *(void **)&((BtlAction *)object)->unk_38 = object;
    ((BtlAction *)object)->unk_6a = 1;
    return 1;
}

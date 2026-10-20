#include "btl_ai_internal.h"

#include "include_asm.h"
#include "type.h"
u32 btlEffectHasAiProcedure(void* object);
/* Report whether embedded AI command work has either an active procedure byte or a procedure task. */
// FUN_001DEEB0
u32 btlEffectHasAiProcedure(void* object)
{
    if (((BtlAiCommandWork *)object)->procedureActive != 0)
    {
        return 1;
    }
    return (((BtlAiCommandWork *)object)->procedureTask != 0);
}

#include "btl_ai_internal.h"
/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlEffect.c; members 001deeb0-001deeb0 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
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

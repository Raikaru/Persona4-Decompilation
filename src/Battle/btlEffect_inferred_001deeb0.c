/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlEffect.c; members 001deeb0-001deeb0 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
u32 func_001deeb0(void* object);
// FUN_001DEEB0
u32 func_001deeb0(void* object)
{
    if (*(u8*)((u8*)object + 0x30) != 0)
    {
        return 1;
    }
    return (*(u32*)((u8*)object + 0x4C) != 0);
}

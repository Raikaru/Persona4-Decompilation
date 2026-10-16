/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Battle/btlBoss.c; members 001dc680-001dc680 */

/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "include_asm.h"
#include "type.h"
u32 func_001dc680(void* object);
// FUN_001DC680
u32 func_001dc680(void* object)
{
    *(void**)((u8*)object + 0x38) = object;
    *(u16*)((u8*)object + 0x6A) = 1;
    return 1;
}

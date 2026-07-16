/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_003E1210)
/* Source unit: src/rw/rwplcore_003e1210.c (1 function markers) */
#include "type.h"

extern long func_003e1030(int, u32, long, int, long, u32);

#pragma optimization_level 3
// FUN_003E1210
long func_003e1210(int first, u32 second, long third, int fourth)
{
    return func_003e1030(first, second, third, 1, 0, fourth);
}
#pragma optimization_level 2
#endif /* P4_UNIT_003E1210 */

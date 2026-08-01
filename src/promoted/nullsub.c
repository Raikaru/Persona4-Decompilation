/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

/* Empty callback bodies (`jr $ra; nop`) installed in data records. Splat's
   control-flow scan cannot see them because nothing calls them directly, so
   each was folded into the preceding function's window until the boundary was
   recovered in tools/reconcile_function_boundaries.py::DATA_REACHABLE_ENTRIES. */

#if defined(P4_UNIT_001CA580)
#include "type.h"

// FUN_001CA580
void func_001ca580(void) {
}
#endif /* P4_UNIT_001CA580 */

#if defined(P4_UNIT_0047F840)
#include "type.h"

// FUN_0047F840
void func_0047f840(void) {
}
#endif /* P4_UNIT_0047F840 */

#if defined(P4_UNIT_005072D0)
#include "type.h"

// FUN_005072D0
void func_005072d0(void) {
}
#endif /* P4_UNIT_005072D0 */

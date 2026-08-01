/* Consolidated Persona 4 source units. */

/* Empty callback bodies (`jr $ra; nop`) installed in data records. Splat's
   control-flow scan cannot see them because nothing calls them directly, so
   each was folded into the preceding function's window until the boundary was
   recovered in tools/reconcile_function_boundaries.py::DATA_REACHABLE_ENTRIES. */

#include "type.h"



// FUN_001CA580
void func_001ca580(void) {
}



// FUN_0047F840
void func_0047f840(void) {
}



// FUN_005072D0
void func_005072d0(void) {
}

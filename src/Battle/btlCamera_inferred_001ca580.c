
/* Empty callback bodies (`jr $ra; nop`) installed in data records. Splat's
   control-flow scan cannot see them because nothing calls them directly, so
   each was folded into the preceding function's window until the boundary was
   recovered in tools/reconcile_function_boundaries.py::DATA_REACHABLE_ENTRIES. */

#include "type.h"

/* Empty update paired with SetDefaultLimit in camera dispatch state 12. */
// FUN_001CA580
void btlCameraDefaultLimitUpdateNoop(void) {
}


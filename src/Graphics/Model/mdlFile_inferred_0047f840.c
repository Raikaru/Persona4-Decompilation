
/* Empty callback bodies (`jr $ra; nop`) installed in data records. Splat's
   control-flow scan cannot see them because nothing calls them directly, so
   each was folded into the preceding function's window until the boundary was
   recovered in tools/reconcile_function_boundaries.py::DATA_REACHABLE_ENTRIES. */

#include "type.h"

/* Source unit: src/promoted/nullsub.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/nullsub.c; members 0047f840-0047f840 */

// FUN_0047F840
void mdlTrackApplyNoop(void *result, void *target) {
}


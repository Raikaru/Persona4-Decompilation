/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/cmmScript.c); members 0025ff60-0025ff60 */

#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern u32 kwlnTaskGetWork(void *task);
#pragma push
#pragma opt_propagation on
/* Return the first work word shared by script, rank-up and filter task protocols. */
// FUN_0025FF60
s32 cmmScriptTaskGetWorkValue(s32 task)
{
    s32 *p;
    p = (s32 *)kwlnTaskGetWork((void *)(u32)task);
    return p[0];
}
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/cmmScript.c); members 0025ff60-0025ff60 */

#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern u32 kwlnTaskGetWork(void *task);
#pragma push
#pragma opt_propagation on
// Left func_: returns word 0 of a task work area. Blur-filter tasks store their mode there, but cmmRankUp and cmmScript call it on other task types, so no single name fits.
// FUN_0025FF60
s32 func_0025ff60(s32 task)
{
    s32 *p;
    p = (s32 *)kwlnTaskGetWork((void *)(u32)task);
    return p[0];
}
#pragma pop

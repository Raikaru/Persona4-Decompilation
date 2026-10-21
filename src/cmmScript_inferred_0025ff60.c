
#include "include_asm.h"
#include "type.h"
#include "scr_internal.h"
#include "effect_instance_internal.h"
#include "datPersona_internal.h"
extern u32 kwlnTaskGetWork(void *task);
/* Return the first work word shared by script, rank-up and filter task protocols. */
// FUN_0025FF60
s32 cmmScriptTaskGetWorkValue(s32 task)
{
    s32 *p;
    p = (s32 *)kwlnTaskGetWork((void *)(u32)task);
    return p[0];
}

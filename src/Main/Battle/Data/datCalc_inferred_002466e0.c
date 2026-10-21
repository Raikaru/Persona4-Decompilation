#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "datScript_internal.h"

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern u8 D_006359B0[];
extern u8 D_006359C0[];

extern f32 D_00761260;
extern f32 fGpffff811c;


/* IMANISHI (STAFF) sequence poll hook; retail returns without defining a result. Sequence rows hold
 * start, poll and stop hooks. */
// FUN_002466E0
void imanishiStaffPollNoop(void)
{
}


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


/* IMANISHI (STAFF) sequence stop hook; retail performs no teardown. The sequence table row holds
 * start, poll and stop hooks in that order. */
// FUN_002466F0
void imanishiStaffStopNoop(void)
{
}


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
static inline f32 mul_f32_ordered(f32 left, f32 right)
{
    return left * right;
}
static inline f32 add_f32_ordered(f32 left, f32 right)
{
    return left + right;
}



/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 002466f0-002466f0 */
/* IMANISHI (STAFF) sequence stop hook at row 0x005DD250 +12; retail performs no teardown. See sequenceRequest: start/poll/stop use row offsets +4/+8/+12. */
// FUN_002466F0
void imanishiStaffStopNoop(void)
{
}


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



/* Source unit: src/promoted/code1_0024.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0024.c; members 00246580-00246580 */
/* Model-neck-test task update hook: ignores its task and returns zero without changing state. */
// FUN_00246580
s32 mdlNeckTestUpdateNoop(u8 *unusedTask)
{
    return 0;
}


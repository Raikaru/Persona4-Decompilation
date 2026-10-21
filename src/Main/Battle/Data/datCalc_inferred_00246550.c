#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "datScript_internal.h"

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00635990[];
extern u8 D_006359A0[];
extern u8 D_006359B0[];
extern u8 D_006359C0[];

extern void func_00243ed0(void);
extern f32 D_00761260;
extern f32 fGpffff811c;


/* Initialize the playable-character records and return success to the callback table. */
// FUN_00246550
s32 datCalcInitializeCharactersCommand(void)
{
    func_00243ed0();
    return 1;
}


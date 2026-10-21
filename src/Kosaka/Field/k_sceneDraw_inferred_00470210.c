#include "kwln_task_internal.h"
#include "sdk_lbox_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "model_callbacks_internal.h"
#include "sdk_snd_internal.h"
extern MdlNameCallback iGpffffbb2c;
extern MdlTypeCallback iGpffffbb30;
extern MdlNameCallback iGpffffbb34;
extern MdlSetupCallback iGpffffbb38;
extern void (*iGpffffbb3c)();
extern void sdkLboxClear(u8 *task);
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffbb28;
struct RuntimeWork;
extern u8 D_00922C50[];
extern u8 DAT_00922c30_abs[];


struct MdlFlags78ec0;


extern f32 fGpffffbb4c;
extern f32 fGpffffbb48;
extern f32 fGpffffbb50;
extern f32 fGpffffbb54;

extern void sdkLboxClear(u8 *task);
/* Clear the list box and free its task work block. */
// FUN_00470210
void sdkLboxDestroy(u8 *task)
{
    sdkLboxClear(task);
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}


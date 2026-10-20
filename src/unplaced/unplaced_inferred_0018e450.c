/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018e450-0018e4d0 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
#include "rw_types_internal.h"
#include "scene_event_internal.h"
typedef struct FldTestLauncherWork {
    s32 state;
    s32 model;
} FldTestLauncherWork;

extern void mdlDestroyModelObject(s32 model);
extern void (*jtbl_008873EC[])(void *);
void K_Test_Create(s32 parentTask);
/* Unit settings shared by the test launcher routines. */
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018E450
/* Start the test one update after initialization, then remain idle. */
s32 K_Test_LauncherUpdate(u8 *task)
{
    s32 *statePtr;
    s32 state;

    statePtr = (s32 *)((KwlnTask *)task)->work;
    state = *statePtr;
    switch (state) {
    case 0:
        *statePtr = state + 1;
        break;
    case 1:
        K_Test_Create(0);
        *statePtr += 1;
        break;
    case 2:
        break;
    default:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Release an optional model before freeing the launcher allocation. */
// FUN_0018E4D0
void K_Test_LauncherDestroy(u8 *task)
{
    KwlnTask *taskRecord = (KwlnTask *)task;
    s32 model;
    model = ((FldTestLauncherWork *)((KwlnTask *)task)->work)->model;
    if (model != 0) {
        mdlDestroyModelObject(model);
    }
    jtbl_008873EC[0]((void *)taskRecord->work);
}
#pragma pop

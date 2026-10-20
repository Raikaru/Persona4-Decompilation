/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018df30-0018e030 */

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
extern void (*jtbl_008873EC[])(void *);
extern s32 D_0076428C;
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 FldStepNotAtBoundary(void);
extern u8 D_005F54D8[];
extern u8 D_005F54E8[];
/* Supporter work is allocated as 0x14 bytes; creation initializes its timer. */
typedef struct FldSupporterWork {
    s32 state;
    s32 active;
    s32 timer;
    s32 frame;
    u8 pad10[4];
} FldSupporterWork;
extern s32 FldSupporterUpdate(u8 *task);
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018DF30
void FldSupporterDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018DF60
/* Create the supporter only away from field-step boundaries. */
s32 FldSupporterTaskCreate(s32 parent)
{
    s32 taskHandle;
    u8 *work;

    if (FldStepNotAtBoundary() == 0)
        return 0;
    chkmemAllocSiteTag(&D_005F54D8, 0x91);
    work = D_008873F4[0](1, 0x14, 0x40000);
    if (work == NULL)
        return 0;
    taskHandle = (s32)kwlnTaskCreateChild((void *)((u8 *)parent), (const void *)(&D_005F54E8), 0xF, 0, 0, FldSupporterUpdate, FldSupporterDestroy, (u8 *)(work));
    ((FldSupporterWork *)work)->timer = 0x1E;
    return taskHandle;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018E030
/* Change activity and latch the current global frame for the supporter. */
void FldFrameObjSetActive(u8 *task, s32 active)
{
    if (task != NULL) {
        u8 *work = ((KwlnTask *)task)->work;
        ((FldSupporterWork *)work)->active = active;
        ((FldSupporterWork *)work)->frame = D_0076428C;
    }
}
#pragma pop

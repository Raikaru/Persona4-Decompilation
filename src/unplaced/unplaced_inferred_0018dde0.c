/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018df30-0018e030 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
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
extern s32 FldSupporterUpdate(u8 *arg0);
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018DF30
void FldSupporterDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018DF60
s32 FldSupporterTaskCreate(s32 arg0)
{
    s32 temp_2;
    u8 *temp_2_2;

    if (FldStepNotAtBoundary() == 0)
        return 0;
    chkmemAllocSiteTag(&D_005F54D8, 0x91);
    temp_2_2 = D_008873F4[0](1, 0x14, 0x40000);
    if (temp_2_2 == NULL)
        return 0;
    temp_2 = (s32)kwlnTaskCreateChild((void *)((u8 *)arg0), (const void *)(&D_005F54E8), 0xF, 0, 0, FldSupporterUpdate, FldSupporterDestroy, (u8 *)(temp_2_2));
    *(s32 *)(temp_2_2 + 8) = 0x1E;
    return temp_2;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018E030
void FldFrameObjSetActive(u8 *arg0, s32 arg1)
{
    if (arg0 != NULL) {
        u8 *p = *(u8 **)(arg0 + 0x38);
        *(s32 *)(p + 4) = arg1;
        *(s32 *)(p + 0xC) = D_0076428C;
    }
}
#pragma pop

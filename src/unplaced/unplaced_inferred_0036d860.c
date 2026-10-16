/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0036d860-0036d960 */

#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"
#include "rw_types_internal.h"
extern void pscResInit(u8 *arg0);
extern void pscBuildGridIndexTable(void);
extern void pscCameraReset(void);
extern void pscResUpdate(void);
extern s32 pscResAnySlotInUse(void);
extern u8 *kwlnGetCamera(void);
extern void func_003e8180(void *arg0, f32 arg1);
extern void K_View_SetFov(void *arg0, f32 arg1);
extern void K_ClumpLookAtBasis(void *arg0, void *arg1, void *arg2, s32 arg3);
#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_0036D860
void pscResInitScene(u8 *arg0, s32 arg1)
{
    pscResInit(arg0);
    pscBuildGridIndexTable();
    if (arg1 != 0) {
        pscCameraReset();
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_0036D8B0
void pscCameraReset(void)
{
    struct {
        s32 f20;
        s32 f24;
        s32 f28;
        s32 pad2c;
        s32 f30;
        s32 f34;
        s32 f38;
        u8 pad[4];
    } local;
    s32 view;

    view = (s32)kwlnGetCamera();
    func_003e8180((void *)view, 1.0f);
    local.f30 = 0;
    local.f34 = 0;
    local.f38 = 0;
    local.f20 = 0;
    local.f24 = 0;
    local.f28 = 0x43480000;
    K_View_SetFov((void *)view, 100.0f);
    K_ClumpLookAtBasis((void *)view, &local.f30, &local.f20, 0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_0036D940
void pscResTeardown(void *arg0)
{
    pscResDestroy();
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
// FUN_0036D960
s32 pscResIsIdle(void)
{
    pscResUpdate();
    return !pscResAnySlotInUse();
}
#pragma pop

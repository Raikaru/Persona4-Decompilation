/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0036d860-0036d960 */

#include "include_asm.h"
#include "type.h"
#include "message_frame_internal.h"
#include "primitive_point_buffer.h"
#include "fr_font_internal.h"
#include "datPersona_internal.h"
#include "rw_types_internal.h"
extern void pscResInit(u8 *context);
extern void pscBuildGridIndexTable(void);
extern void pscCameraReset(void);
extern void pscResUpdate(void);
extern s32 pscResAnySlotInUse(void);
extern u8 *kwlnGetCamera(void);
extern void func_003e8180(void *object, f32 value);
extern void K_View_SetFov(void *camera, f32 fov);
extern void K_ClumpLookAtBasis(void *object, void *position, void *target, s32 referenceUp);
#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Initialize scene resources and their grid lookup, optionally resetting the camera. */
// FUN_0036D860
void pscResInitScene(u8 *work, s32 resetCamera)
{
    pscResInit(work);
    pscBuildGridIndexTable();
    if (resetCamera != 0) {
        pscCameraReset();
    }
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Place the camera at the origin looking toward (0, 0, 200), with FOV 100. */
// FUN_0036D8B0
void pscCameraReset(void)
{
    /* Integer stores carry float bit patterns for the two three-float vectors.
     * The fourth word of each vector is alignment space, not another coordinate. */
    struct {
        s32 targetXBits;
        s32 targetYBits;
        s32 targetZBits;
        s32 padTarget;
        s32 positionXBits;
        s32 positionYBits;
        s32 positionZBits;
        u8 padPosition[4];
    } vectors;
    s32 camera;

    camera = (s32)kwlnGetCamera();
    func_003e8180((void *)camera, 1.0f);
    vectors.positionXBits = 0;
    vectors.positionYBits = 0;
    vectors.positionZBits = 0;
    vectors.targetXBits = 0;
    vectors.targetYBits = 0;
    /* 0x43480000 is 200.0f; preserve the original integer transport store. */
    vectors.targetZBits = 0x43480000;
    K_View_SetFov((void *)camera, 100.0f);
    K_ClumpLookAtBasis((void *)camera, &vectors.positionXBits, &vectors.targetXBits, 0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Task teardown callback: release the scene resource set. */
// FUN_0036D940
void pscResTeardown(void *unusedTask)
{
    pscResDestroy();
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_loop_invariants off
#pragma opt_propagation on
/* Advance resource processing and report whether every resource slot is unused. */
// FUN_0036D960
s32 pscResIsIdle(void)
{
    pscResUpdate();
    return !pscResAnySlotInUse();
}
#pragma pop

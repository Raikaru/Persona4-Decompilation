#include "member_access.h"
#include "resrc_manager_internal.h"
#include "rw_camera_internal.h"
/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Event/Fcl/fclBankManager.c; members 00155070-001552a0 */

#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
typedef struct FldCameraMatrixPair { s32 first; s32 second; } FldCameraMatrixPair;
#include "field_light_internal.h"
#include "field_frame_internal.h"
#include "rw_types_internal.h"
extern s32 iGpffffb210;
extern void memset(void *dst, s32 value, u32 size);
extern f32 iGpffff853c;
extern f32 iGpffffb290;
extern f32 iGpffffb28c;
extern s32 iGpffffb288;
extern f32 iGpffff8218;
extern f32 iGpffff830c;
extern s32 D_007D2510[];
extern s32 FldMap_IsCurrentInEitherBand(void);
extern u8 *MT_Scene_GetResListHead(s32 );
extern s32 *MT_Scene_GetFrameState(void);
extern void K_View_SetFov(void *, f32 );
extern void func_003e0670(void *, s32 );
extern void func_003e9cb0(s32 , void *, s32 );
extern void FldCameraAdvanceCurve(s32 , s32 );
extern void FldFrame_SetViewOffset(s32 , void *);
extern void FldFrame_SetViewDistance(s32 , f32 );
extern void fldCameraSetFollowHeight(s32 , f32 );
extern void FldFrame_SetSlotVector(s32 , s8 , void *);
extern u8 *FldFrame_GetSlotBuffer(s32 );
extern void FldCameraUpdateLookAt(s32 );
extern s32 kwlnGetCamera(void);
#pragma push
#pragma opt_loop_invariants on
// Intent: Apply the camera parameters from resource 0x14: field of view, view offset, distance, the slot vectors and the frame slot buffer [inferred]
/* Resource camera parameters occupy +0x140..0x304; scalar-pair copies retain load/store order, and MEMBER preserves view-distance aliasing. */
// FUN_00155070
void MT_Scene_ApplyCameraParams(void)
{
    u8 slotMatrix[0x40];
    u8 *cameraResource;
    u8 *slotDestination;
    u8 *matrixSource;
    s32 firstWord;
    s32 secondWord;
    s32 pairsRemaining;
    s32 slotIndex;

    cameraResource = MT_Scene_GetResListHead(0x14);
    if (cameraResource != NULL) {
        K_View_SetFov((void *)kwlnGetCamera(), ((ResrcRecord *)(cameraResource))->cameraFov);
        func_003e0670(slotMatrix, ((ResrcRecord *)(cameraResource))->cameraMatrix);
        func_003e9cb0((s32)((RwCamera *)(kwlnGetCamera()))->object.object.parent, slotMatrix, 0);
        FldCameraAdvanceCurve(MT_Scene_GetFrameState()[1], ((ResrcRecord *)(cameraResource))->cameraCurve);
        FldFrame_SetViewOffset(MT_Scene_GetFrameState()[1], cameraResource + 0x150);
        if ((((ResrcRecord *)(cameraResource))->cameraViewDistance == 0.0f) &&
            (FldMap_IsCurrentInEitherBand() == 1)) {
            MEMBER(f32, cameraResource, ResrcRecord, cameraViewDistance) = 20.0f; /* measured: ResrcRecord.cameraViewDistance: local nd11; MEMBER retains reload behavior. */
        }
        FldFrame_SetViewDistance(MT_Scene_GetFrameState()[1], MEMBER(f32, cameraResource, ResrcRecord, cameraViewDistance)); /* measured: ResrcRecord.cameraViewDistance: local nd11; MEMBER retains reload behavior. */
        fldCameraSetFollowHeight(MT_Scene_GetFrameState()[1], ((ResrcRecord *)(cameraResource))->cameraFollowHeight);
        slotIndex = 0;
        goto loop_test;
loop_body:
        if (((ResrcRecord *)(cameraResource + slotIndex))->cameraSlotEnabled[0] != 0) {
            FldFrame_SetSlotVector(MT_Scene_GetFrameState()[1],
                          (s8)slotIndex,
                          cameraResource + slotIndex * 0xC + 0x184);
        }
        slotIndex += 1;
loop_test:
        if (slotIndex < 0x20) {
            goto loop_body;
        }
        func_003e0670(slotMatrix, ((ResrcRecord *)(cameraResource))->cameraSlotMatrix);
        slotDestination = FldFrame_GetSlotBuffer(MT_Scene_GetFrameState()[1]);
        matrixSource = slotMatrix;
        pairsRemaining = 8;
        do {
            firstWord = ((FldCameraMatrixPair *)matrixSource)->first;
            secondWord = ((FldCameraMatrixPair *)(matrixSource))->second;
            matrixSource += 8;
            pairsRemaining -= 1;
            ((FldCameraMatrixPair *)slotDestination)->first = firstWord;
            ((FldCameraMatrixPair *)(slotDestination))->second = secondWord;
            slotDestination += 8;
        } while (pairsRemaining > 0);
        FldCameraUpdateLookAt(MT_Scene_GetFrameState()[1]);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Clear the scene frame state block [inferred]
// FUN_00155250
void MT_Scene_ResetFrameState(void)
{
    memset(D_007D2510, 0, 0x18F8);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Return the scene frame state block [inferred]
// FUN_00155280
s32 *MT_Scene_GetFrameState(void)
{
    return D_007D2510;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Return the scene-load ready flag: 0 while a field load is in progress, 1 once the scene has loaded [inferred]
// FUN_00155290
s32 FldSceneLoadReady(void)
{
    return iGpffffb210;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants on
// Intent: Set the three fade globals from the state pair: a scale value for state 7 (and state 6 with 6, state 21 with 1), or the defaults otherwise [inferred]
// FUN_001552A0
void MT_Scene_SetFadeForState(u16 fieldKind, u16 baseState) {
    f32 value;

    value = 0.0f;
    if ((fieldKind == 7) && (baseState != 1)) {
        value = iGpffff853c;
    }
    if ((fieldKind == 6) && (baseState == 6)) {
        value = iGpffff853c;
    }
    if ((fieldKind == 0x15) && (baseState == 1)) {
        value = iGpffff853c;
    }
    if (!(value <= 0.0f)) {
        iGpffffb290 = value;
        iGpffffb28c = 128.0f * value;
        iGpffffb288 = 0x40400000;
        return;
    }
    iGpffffb290 = iGpffff8218;
    iGpffffb28c = iGpffff830c;
    iGpffffb288 = 0x40400000;
}
#pragma pop

#include "Kosaka/k_fldFrame_internal.h"
#include "scene_event_internal.h"

/* Inferred unit: no __FILE__ evidence; boundaries from P3 twin src/Event/Fcl/fclBankManager.c; members 00155070-001552a0 */

#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "sdktask.h"
#include "type.h"
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
/* The camera resource has version-specific parameters at +0x140..0x304; bytewise slot/matrix copies retain the measured load/store order. */
// FUN_00155070
void MT_Scene_ApplyCameraParams(void)
{
    u8 slotMatrix[0x40];
    u8 *cameraResource;
    u8 *slotDestination;
    u8 *matrixSource;
    s16 *firstWord;
    s32 secondWord;
    s32 pairsRemaining;
    s32 slotIndex;

    cameraResource = MT_Scene_GetResListHead(0x14);
    if (cameraResource != NULL) {
        K_View_SetFov((void *)kwlnGetCamera(), *(f32 *)(cameraResource + 0x144));
        func_003e0670(slotMatrix, *(s32 *)(cameraResource + 0x148));
        func_003e9cb0(*(s32 *)(kwlnGetCamera() + 4), slotMatrix, 0);
        FldCameraAdvanceCurve(MT_Scene_GetFrameState()[1], *(s32 *)(cameraResource + 0x140));
        FldFrame_SetViewOffset(MT_Scene_GetFrameState()[1], cameraResource + 0x150);
        if ((*(f32 *)(cameraResource + 0x15C) == 0.0f) &&
            (FldMap_IsCurrentInEitherBand() == 1)) {
            *(f32 *)(cameraResource + 0x15C) = 20.0f;
        }
        FldFrame_SetViewDistance(MT_Scene_GetFrameState()[1], *(f32 *)(cameraResource + 0x15C));
        fldCameraSetFollowHeight(MT_Scene_GetFrameState()[1], *(f32 *)(cameraResource + 0x160));
        slotIndex = 0;
        goto loop_test;
loop_body:
        if (*(s8 *)(cameraResource + slotIndex + 0x164) != 0) {
            FldFrame_SetSlotVector(MT_Scene_GetFrameState()[1],
                          (s8)slotIndex,
                          cameraResource + slotIndex * 0xC + 0x184);
        }
        slotIndex += 1;
loop_test:
        if (slotIndex < 0x20) {
            goto loop_body;
        }
        func_003e0670(slotMatrix, *(s32 *)(cameraResource + 0x14C));
        slotDestination = FldFrame_GetSlotBuffer(MT_Scene_GetFrameState()[1]);
        matrixSource = slotMatrix;
        pairsRemaining = 8;
        do {
            firstWord = *(s16 **)matrixSource;
            secondWord = *(s32 *)(matrixSource + 4);
            matrixSource += 8;
            pairsRemaining -= 1;
            *(s16 **)slotDestination = firstWord;
            *(s32 *)(slotDestination + 4) = secondWord;
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

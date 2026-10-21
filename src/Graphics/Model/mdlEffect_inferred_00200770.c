#include "operand_order_internal.h"
#include "btl_skill_target_internal.h"
#include "list_item_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "mdl_effect_internal.h"
#include "btl_unit_internal.h"
#include "btl_packet_create_internal.h"
typedef struct BtlPacket BtlPacket;
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "fr_font_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
typedef struct BtlUnit BtlUnit;
typedef struct BtlAction BtlAction;

extern void datStopPadRumble(void);


typedef struct {
    u8 pad0[2];
    s16 field2;
    s16 field4;
    s16 field6;
    s16 field8;
} P4_00202D20;


extern f32 fGpffff815c;
extern f32 fGpffff83b0;

extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];


extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];

extern u8 D_00625240[];
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
typedef void (*BattleSelectionDraw)(u8 *work, s32 slot, f32 x, f32 y,
                                    u8 opacity, s32 highlighted, s32 showDetail);
extern void btlSelectionDrawSlideIn(u8 *work, u8 *selection, f32 x, f32 y,
                         BattleSelectionDraw drawSelection);

extern void btlSelectionDrawList(u8 *state, u8 *selectionState, f32 inputScaleX, f32 scaleY,
                          BattleSelectionDraw callback);
extern void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 showDetail);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Color4;
typedef struct {
    s32 value3;
    s32 value0;
    s32 value1;
    s32 value2;
    u8 pad[0xC];
    Color4 colors;
} Work4;
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlCameraSetState(s32 state, BtlAction *action, u32 clearUnitFlags);
extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
extern u8 *btlActionFindByUnit(s32 unit);
extern s32 datCalcIsDead(s32 unit, s32 hpDelta);
extern void btlUnitGetAnchorPose(void *unit, void *outPosition, void *outRotation, void *outTarget);
extern void btlUnitSetPos(void *unit, void *pos);
extern void btlUnitSetRot(void *unit, void *rot);
extern u8 *iGpffffb3ac;

extern s32 D_00881444_abs[];
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern u8 D_006253B0[];

// Advances the battle model curve and updates the model matrix from the curve state.
// FUN_00200770
void btlUiUpdateModelCurve(u8 *command)
{
    typedef struct {
        f32 x;
        f32 y;
        f32 z;
    } Vec3;
    typedef struct {
        Vec3 anchorPosition;
        Vec3 anchorRotation;
        u8 pad18[8];
        u8 firstMatrix[0x10];
        u8 basisScratch[0x20];
        u8 secondMatrix[0x40];
        u8 rotationScratch[0x10];
        u8 modelMatrix[0x40];
        Vec3 scaleOrPosition;
    } Frame;
    extern void btlCameraSetupActionGeometry(u8 *action, u8 *first, f32 *second, f32 radius, u16 mode);
    extern u16 btlCameraGetState(void);
    extern void mdlEffectBuildBasisRows(void *output, void *orientation);
    extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
    extern void mdlScale(void *model, f32 *scale, s32 combineOp);
    extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
    extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
    extern void mdlAdvanceModelFromFlags(void *model);
    extern s32 mdlCopyIndexedMatrix(void *model, s32 index, void *destination);
    extern void btlCameraLookAtQuat(void *out, const void *first, const void *second, const void *config);
    extern void btlMainCurveReset(u16 *curve, f32 *pose);
    extern u8 *iGpffffb474;
    Frame frame;
    u8 *modelReference;
    u8 *parameters;
    u32 elapsedFrame;
    u32 duration;
    f32 scale;
    MdlEffectModelReference *reference;

    modelReference = ((MdlEffectCommand *)command)->object;
    reference = (MdlEffectModelReference *)modelReference;
    parameters = ((MdlEffectCommand *)command)->parameters;
    elapsedFrame = ((MdlEffectCommand *)command)->counter;
    duration = ((MdlEffectModelCurve *)parameters)->duration;
    if ((duration >= elapsedFrame) || (duration == 0)) {
        if (elapsedFrame == 0) {
            if (((MdlEffectModelCurve *)parameters)->cameraMode == 0) {
                btlCameraSetState(1, NULL, 1);
                btlCameraSetupActionGeometry(NULL, NULL, NULL, 0.0f, 0x100);
            } else {
                btlCameraSetState(1, NULL, 0);
            }
        }
        if (((btlCameraGetState() & 0xFFFF) == 1) && (*(s32 *)modelReference != 0)) {
            mdlEffectBuildBasisRows(frame.modelMatrix, command + 0x10);
            mdlApplyModelMatrix(*(u8 **)modelReference, frame.modelMatrix, 0);
            scale = ((MdlEffectCommand *)command)->scale * ((MdlEffectModelCurve *)parameters)->scale;
            frame.scaleOrPosition.z = scale;
            frame.scaleOrPosition.y = scale;
            frame.scaleOrPosition.x = scale;
            mdlScale(*(u8 **)modelReference, &frame.scaleOrPosition.x, 2);
            frame.scaleOrPosition.x = ((MdlEffectCommand *)command)->position[0];
            frame.scaleOrPosition.y = ((MdlEffectCommand *)command)->position[1];
            frame.scaleOrPosition.z = ((MdlEffectCommand *)command)->position[2];
            mdlTranslateMatrix((RwMatrix *)*(u8 **)modelReference, (const RwV3d *)&frame.scaleOrPosition, 2);
            mdlSetLayerWeight(*(u8 **)modelReference, 0, ((MdlEffectModelCurve *)parameters)->layerWeight);
            mdlAdvanceModelFromFlags(*(u8 **)modelReference);
            mdlCopyIndexedMatrix(*(u8 **)modelReference, ((MdlEffectModelReference *)modelReference)->matrixIndex, frame.firstMatrix);
            mdlCopyIndexedMatrix(*(u8 **)modelReference, reference->matrixIndex + 1, frame.secondMatrix + 0x10);
            frame.anchorPosition = *(Vec3 *)frame.secondMatrix;
            btlCameraLookAtQuat(&frame.anchorRotation, frame.secondMatrix, frame.rotationScratch, frame.basisScratch);
            btlMainCurveReset((u16 *)(iGpffffb474 + 0x24), (f32 *)(&frame.anchorPosition));
        }
    }
}

// Resets the overlay scale to its default value.
// FUN_00200960
void btlUiResetOverlayScale(void) {
    ((MdlEffectUiState *)D_0076449C)->overlayScale = fGpffff8184;
}

/* Sets the overlay scale from the progress ratio of the current and total counters. */
// FUN_00200980
void btlUiUpdateOverlayScale(u8 *command)
{
    s32 frame;
    s32 duration;
    u8 *parameters;
    f32 progress;
    f32 scaleDelta;
    f32 startScale;

    parameters = ((MdlEffectCommand *)command)->parameters;
    frame = ((MdlEffectCommand *)command)->counter;
    duration = ((MdlEffectOverlayScale *)parameters)->duration;
    if ((duration == 0) || ((u32)duration < (u32)frame)) return;
    startScale = ((MdlEffectOverlayScale *)parameters)->startScale;
    progress = (f32)(u32)frame;
    scaleDelta = (f32)(u32)duration;
    progress /= scaleDelta;
    scaleDelta = ((MdlEffectOverlayScale *)parameters)->endScale - startScale;
    scaleDelta = operandOrderMultiply(progress, scaleDelta);
    progress = scaleDelta + startScale;
    ((MdlEffectUiState *)D_0076449C)->overlayScale = fGpffff81a8 * progress;
}

/* Empty callback; it does not inspect or change state. */
// FUN_00200A50
void btlUiUnitPositionDestroyNoop(void)
{
}

// Re-applies position and rotation to the living units of both sides.
// FUN_00200A60
void btlUiRefreshUnitPositions(u8 *command)
{
    u8 position[0x10];
    u8 rotation[0x10];
    s32 cameraMode;
    s32 datUnit;
    u32 sideIndex;
    u8 *parameters;
    u8 *unit;

    parameters = ((MdlEffectCommand *)command)->parameters;
    if (((MdlEffectCommand *)command)->counter != 0) {
        return;
    }
    btlCameraSetState(1, NULL, 1);
    btlCameraSetupActionGeometry(NULL, NULL, NULL, 0.0f, 0x100);
    cameraMode = ((MdlEffectUnitRefresh *)parameters)->cameraMode;
    switch (cameraMode) {
    case 0:
        btlCameraSetState(0x2C, NULL, 1);
        break;
    case 1:
        btlCameraSetState(0x2D, NULL, 1);
        break;
    case 2:
        btlCameraSetState(0x2E, (BtlAction *)btlActionFindByUnit(D_00881444_abs[0]), 1);
        break;
    case 3:
        btlCameraSetState(6, (BtlAction *)btlActionFindByUnit(D_00881444_abs[0]), 1);
        break;
    }
    if (((MdlEffectUnitRefresh *)parameters)->refreshUnits == 0) {
        return;
    }
    sideIndex = 0;
    while (sideIndex < 2U) {
        unit = ((MdlEffectBattleState *)iGpffffb3ac)->sides[sideIndex].head;
        while (unit != NULL) {
            datUnit = (s32)((BtlUnit *)unit)->datUnit;
            if ((datUnit != 0) && (datCalcIsDead(datUnit, 0) == 0)) {
                btlUnitGetAnchorPose(unit, position, rotation, NULL);
                btlUnitSetPos(unit, position);
                btlUnitSetRot(unit, rotation);
                btlUnitUpdateStatusMotion(unit, 0);
                btlUnitSetMotion(unit, ((BtlUnit *)unit)->restMotion, 0, ((BtlUnit *)unit)->restRate, ((BtlUnit *)unit)->restOption);
            }
            unit = (u8 *)((BtlUnit *)unit)->nextUnit;
        }
        sideIndex += 1;
    }
}

/* Stops controller rumble through datStopPadRumble. */
// FUN_00200C50
void btlUiStopPadRumble(void)
{
    datStopPadRumble();
}


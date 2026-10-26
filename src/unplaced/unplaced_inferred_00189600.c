
#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "member_access.h"
#include "kwln_task_internal.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
#include "rw_types_internal.h"
#include "resrc_manager_internal.h"
#include "scene_light_override_internal.h"
#include "kwln_view_internal.h"
#include "primitive_queue_internal.h"
typedef RwV3d RainVector;

typedef struct FldLmapPresetColumn { f32 value; u8 pad04[0x14]; } FldLmapPresetColumn;

/* Camera move work: two Vec3s, per-frame speeds, frame counters and preset IDs. */
typedef struct FldLmapCameraWork {
    s32 state;
    f32 eye[3];
    f32 target[3];
    f32 eyeStep;
    f32 targetStep;
    s32 frame;
    s32 duration;
    s32 mode;
    s32 preset;
} FldLmapCameraWork;


#include "scene_event_internal.h"
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32, s32);
extern void (*jtbl_008873EC[])(void *);
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
extern void func_003e0f40(s32);
extern s32 *MT_Scene_GetFrameState(void);
extern void FldRc_SetPositionSlotLock(s32 task, s32 slotIndex, s32 locked);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F5340[];
extern u8 D_005F5350[];
extern u8 D_005F5320[];
extern u8 D_005F5330[];
extern s32 kwlnGetCamera(void);
extern f32 fGpffff8218;
extern s16 mdlGetLayerAnimation(s32 model, s32 layer);
extern u8 *mdlGetMatrix(u32 model);
extern f32 RwV3dNormalize(RainVector *dst, const RainVector *src);
extern u8 *K_ClumpLookAtBasis(u8 *object, u8 *position, u8 *target, s32 referenceUp);
extern f32 D_005F2190[];
extern f32 D_005F2194[];
extern f32 D_005F2198[];
extern f32 D_005F219C[];
extern f32 D_005F21A0[];
extern f32 D_005F21A4[];
extern s32 FldNpcControlUpdate(u8 *task);
extern f32 sinf(f32);
extern u8 *PrimQueueDrawPrimitive(void *inputList, s32 primitive, void *vertices, s32 count);
extern s32 frFontExDrawTextDeferredWithCharWidth(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                         const char *str, s32 flags, s32 unused, void *param,
                         s32 charWidth);
extern f32 D_008872F8[];
extern f32 D_00761184;
extern u8 D_00794C60[];
extern u32 D_007EFA00[];
extern s32 FldPanel2dUpdate(u8 *task);
extern void FldPanel2dSelectEntry(s32 entryIndex);
extern s32 func_003bfae0();
extern s32 kwlnGetCamera(void);
extern s32 RwCameraFrustumTestSphere(u8 *, s32);
extern s32 FldStepIndex(void);
extern u8 *iGpffff9db0;
/* Unit settings shared by the camera, panel and NPC routines. */
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Move eye and target toward a preset at the requested speed, or snap when speed is zero. */
// FUN_00189600
void FldLmapCameraMoveTo(u8 *task, s32 mode, s32 preset, f32 speed)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 eyeDirection[4];
    f32 targetDirection[4];
    f32 targetDistance;
    f32 eyeDistance;
    s32 snapOffset;
    s32 state;
    u8 *eye;
    u8 *target;
    u8 *work;

    work = ((KwlnTask *)task)->work;
    kwlnGetCamera();
    state = ((FldLmapCameraWork *)work)->state;
    if ((state != 1) || (((FldLmapCameraWork *)work)->preset != preset)) {
        if (speed != 0.0f) {
            ((FldLmapCameraWork *)work)->mode = mode;
            ((FldLmapCameraWork *)work)->preset = preset;
            eyeDirection[0] = ((FldLmapPresetColumn *)D_005F2190)[preset].value -
                     ((FldLmapCameraWork *)work)->eye[0];
            eyeDirection[1] = ((FldLmapPresetColumn *)D_005F2194)[preset].value -
                     ((FldLmapCameraWork *)work)->eye[1];
            eyeDirection[2] = ((FldLmapPresetColumn *)D_005F2198)[preset].value -
                     ((FldLmapCameraWork *)work)->eye[2];
            eyeDistance = RwV3dNormalize((RainVector *)&eyeDirection[0], (const RainVector *)&eyeDirection[0]);
            targetDirection[0] = ((FldLmapPresetColumn *)D_005F219C)[preset].value -
                     ((FldLmapCameraWork *)work)->target[0];
            targetDirection[1] = ((FldLmapPresetColumn *)D_005F21A0)[preset].value -
                     ((FldLmapCameraWork *)work)->target[1];
            targetDirection[2] = ((FldLmapPresetColumn *)D_005F21A4)[preset].value -
                     ((FldLmapCameraWork *)work)->target[2];
            targetDistance = RwV3dNormalize((RainVector *)&targetDirection[0], (const RainVector *)&targetDirection[0]);
            if (!(eyeDistance <= targetDistance)) {
                ((FldLmapCameraWork *)work)->duration = (s32)(eyeDistance / speed) + 1;
            } else {
                ((FldLmapCameraWork *)work)->duration = (s32)(targetDistance / speed) + 1;
            }
            ((FldLmapCameraWork *)work)->eyeStep =
                eyeDistance / (f32)((FldLmapCameraWork *)work)->duration;
            ((FldLmapCameraWork *)work)->targetStep =
                targetDistance / (f32)((FldLmapCameraWork *)work)->duration;
            ((FldLmapCameraWork *)work)->frame = 0;
            ((FldLmapCameraWork *)work)->state = 2;
            return;
        }
        ((FldLmapCameraWork *)work)->preset = preset;
        snapOffset = preset * 0x18;
        eye = (u8 *)D_005F2190 + snapOffset;
        *(struct Vec3 *)&((FldLmapCameraWork *)work)->eye[0] = *(struct Vec3 *)eye;
        target = (u8 *)D_005F219C + snapOffset;
        *(struct Vec3 *)&((FldLmapCameraWork *)work)->target[0] = *(struct Vec3 *)target;
        K_ClumpLookAtBasis(((u8 *)(uintptr_t)kwlnGetCamera()), eye, target, 0);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Establish the sky/panel render-state preset before queued primitives draw. */
// FUN_00189870
/* measured: retail loads the callback table base once and reuses it for every call. */
#pragma opt_propagation off
void FldSkyApplyDefaultPreset(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](6, 1);
    base[0](8, 1);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Animate panel entry and alternating text slots, then queue their quads and labels. */
// FUN_00189940
/* measured: retail keeps the red value and other constants inside the loop instead of hoisting
 * them, so loop invariants are disabled here. */
#pragma opt_loop_invariants on
s32 FldPanel2dUpdate(u8 *task)
{
    FldPanel2dWork *panelWork;
    u8 *work;
    u8 *primitive;
    f32 depth;
    f32 reciprocalDepth;
    f32 top;
    f32 progress;
    s32 i;

    work = ((KwlnTask *)task)->work;
    panelWork = (FldPanel2dWork *)work;
    if (((FldPanel2dWork *)work)->hidden == 1) {
        return 0;
    }

    switch (((FldPanel2dWork *)work)->state) {
    case 0:
        depth = D_008872F8[0] - (f32)58980;
        reciprocalDepth = 1.0f / depth;
        ((FldPanel2dWork *)work)->side = 0;
        panelWork->slotX[panelWork->side] = 175.0f;
        ((FldPanel2dWork *)work)->vertices[0].x = 0.0f;
        top = (f32)401;
        ((FldPanel2dWork *)work)->vertices[0].y = top;
        ((FldPanel2dWork *)work)->vertices[0].z = depth;
        ((FldPanel2dWork *)work)->vertices[1].x = 25.0f;
        ((FldPanel2dWork *)work)->vertices[1].y = top;
        ((FldPanel2dWork *)work)->vertices[1].z = depth;
        ((FldPanel2dWork *)work)->vertices[2].x = 0.0f;
        progress = (f32)427;
        ((FldPanel2dWork *)work)->vertices[2].y = progress;
        ((FldPanel2dWork *)work)->vertices[2].z = depth;
        ((FldPanel2dWork *)work)->vertices[3].x = 25.0f;
        ((FldPanel2dWork *)work)->vertices[3].y = progress;
        ((FldPanel2dWork *)work)->vertices[3].z = depth;
        ((FldPanel2dWork *)work)->vertices[4].x = 326.0f;
        ((FldPanel2dWork *)work)->vertices[4].y = top;
        ((FldPanel2dWork *)work)->vertices[4].z = depth;
        ((FldPanel2dWork *)work)->vertices[5].x = 660.0f;
        ((FldPanel2dWork *)work)->vertices[5].y = top;
        ((FldPanel2dWork *)work)->vertices[5].z = depth;
        ((FldPanel2dWork *)work)->vertices[6].x = 326.0f;
        ((FldPanel2dWork *)work)->vertices[6].y = progress;
        ((FldPanel2dWork *)work)->vertices[6].z = depth;
        ((FldPanel2dWork *)work)->vertices[7].x = 660.0f;
        ((FldPanel2dWork *)work)->vertices[7].y = progress;
        ((FldPanel2dWork *)work)->vertices[7].z = depth;
        for (i = 0; i < 4; i++) {
            primitive = work + (i << 6);
            ((FldPanel2dWork *)primitive)->vertices[0].reciprocalZ = reciprocalDepth;
            ((FldPanel2dWork *)primitive)->vertices[4].reciprocalZ = reciprocalDepth;
            ((FldPanel2dWork *)primitive)->vertices[0].red = 255.0f;
            ((FldPanel2dWork *)primitive)->vertices[0].green = 0.0f;
            ((FldPanel2dWork *)primitive)->vertices[0].blue = 0.0f;
            ((FldPanel2dWork *)primitive)->vertices[0].alpha = 0.0f;
            ((FldPanel2dWork *)primitive)->vertices[4].red = 255.0f;
            ((FldPanel2dWork *)primitive)->vertices[4].green = 0.0f;
            ((FldPanel2dWork *)primitive)->vertices[4].blue = 0.0f;
            ((FldPanel2dWork *)primitive)->vertices[4].alpha = 0.0f;
        }
        ((FldPanel2dWork *)work)->state += 1;
        break;
    case 1:
        ((FldPanel2dWork *)work)->alpha = sinf((D_00761184 * (f32)((FldPanel2dWork *)work)->animFrame) / 10.0f);
        if (panelWork->animFrame < 10) {
            panelWork->animFrame += 1;
        } else {
            ((FldPanel2dWork *)work)->state += 1;
        }
        ((FldPanel2dWork *)work)->posX = (-300.0f + 0.0f) + 316.0f * panelWork->alpha;
        ((FldPanel2dWork *)work)->posY = ((f32)371 + 0.0f) + 30.0f * panelWork->alpha;
        /* fallthrough */
    case 2:
        sflDataDrawNarrowRoundedFrame((s32)((FldPanel2dWork *)work)->posX, (s32)((FldPanel2dWork *)work)->posY, (f32)59000, 301, 26, 0xFAFF20, 255, 1, 150, 13, D_00794C60, -5.0f, 1.0f, 1.0f);
        sflDataDrawNarrowRoundedFrame(25, 401, (f32)59000, 301, 26, 0x191919, 255, 1, 150, 13, D_00794C60, 0.0f, 1.0f, ((FldPanel2dWork *)work)->alpha);
        if (!(panelWork->alpha < 1.0f)) {
            if (panelWork->textHandles[!panelWork->side] != 0) {
                progress = sinf((D_00761184 * (f32)((FldPanel2dWork *)work)->blinkTimer) / 10.0f);
                panelWork->slotX[panelWork->side] = 175.0f + 336.0f * progress;
                panelWork->slotX[!panelWork->side] = -161.0f + 336.0f * progress;
                if (panelWork->blinkTimer < 10) {
                    panelWork->blinkTimer += 1;
                } else {
                    panelWork->textHandles[panelWork->side] = 0;
                    ((FldPanel2dWork *)work)->side = !(u32)((FldPanel2dWork *)work)->side;
                }
            }
            primitive = PrimQueueDrawPrimitive(D_00794C60, 4, work + 0x20, 4);
            ((PrimQueueNode *)primitive)->callback = FldSkyApplyDefaultPreset;
            ((PrimQueueNode *)primitive)->argument.handle = 0;
            PrimQueueDrawPrimitive(D_00794C60, 4, work + 0x120, 4);
            if (((FldPanel2dWork *)work)->text[0] != NULL) {
                frFontExDrawTextDeferredWithCharWidth((f32)(s32)((FldPanel2dWork *)work)->slotX[0], (f32)399, (f32)58990, -1, 0, 1, ((FldPanel2dWork *)work)->text[0], 8, 0, D_00794C60, -1);
            }
            if (((FldPanel2dWork *)work)->text[1] != NULL) {
                frFontExDrawTextDeferredWithCharWidth((f32)(s32)((FldPanel2dWork *)work)->slotX[1], (f32)399, (f32)58990, -1, 0, 1, ((FldPanel2dWork *)work)->text[1], 8, 0, D_00794C60, -1);
            }
        }
        break;
    case 3:
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
/* Release the panel work block through the active allocator. */
// FUN_00189E90
void FldPanel2dDestroy(u8 *task)
{
    /* Keep the allocator-facing void** work load distinct from typed field aliases. */
    jtbl_008873EC[0]((void *)((KwlnTask *)task)->work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Lazily allocate the panel task and initialize its text from the current area. */
// FUN_00189EC0
void FldPanel2dTaskCreate(void)
{
    u8 *parent;
    u8 *work;
    s32 taskHandle;
    if (((FldFrame *)MT_Scene_GetFrameState())->panelTask == 0) {
        parent = *(u8 **)MT_Scene_GetFrameState();
        chkmemAllocSiteTag(&D_005F5320, 0x17C);
        work = D_008873F4[0](1, 0x230, 0x40000);
        if (work == NULL) {
            taskHandle = 0;
        } else {
            taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(&D_005F5330), 0xF, 0, 0, FldPanel2dUpdate, FldPanel2dDestroy, (u8 *)(work));
        }
        ((FldFrame *)MT_Scene_GetFrameState())->panelTask = (u8 *)taskHandle;
        FldPanel2dSelectEntry(-1);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Destroy the frame-owned panel hierarchy; return whether one was present. */
// FUN_00189FA0
s32 FldPanel2dRelease(void) {
    if (((FldFrame *)MT_Scene_GetFrameState())->panelTask == 0) {
        return 0;
    }
    kwlnTaskDestroyWithHierarchy((KwlnTask *)((FldFrame *)MT_Scene_GetFrameState())->panelTask);
    ((FldFrame *)MT_Scene_GetFrameState())->panelTask = 0;
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018A000
void FldPanel2dSetState(u8 *task, s32 hidden)
{
    ((FldPanel2dWork *)((KwlnTask *)task)->work)->hidden = hidden;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Stage explicit or area-selected text in the inactive slot and restart its slide. */
// FUN_0018A010
void FldPanel2dSelectEntry(s32 entryIndex)
{
    extern u8 D_005F2210[];
    extern u8 D_005F4090[];
    extern u8 D_005F51E0[];
    s32 mode;
    s32 *location;
    s32 *entry;
    s32 index;
    u8 *text;
    u8 *panel;
    s32 slot;
    u8 *selectedText;

    if ((s32)((FldFrame *)(u8 *)MT_Scene_GetFrameState())->panelTask == 0) {
        return;
    }
    if (entryIndex == -1) {
        mode = FldStepIndex();
        if (mode == 0) {
            index = 0;
            location = (s32 *)iGpffff9db0;
            if (*location >= 0x28) {
                selectedText = NULL;
            } else {
                entry = (s32 *)(D_005F51E0 + *location * 4);
                if (*entry != 0) {
                    index = ((u16 *)*entry)[location[1]];
                }
                selectedText = D_005F2210 + index * 0x1A;
            }
        } else {
            selectedText = D_005F4090 + mode * 0x1B;
        }
        text = selectedText;
    } else {
        text = D_005F2210 + entryIndex * 0x1A;
    }
    panel = ((KwlnTask *)((FldFrame *)(u8 *)MT_Scene_GetFrameState())->panelTask)->work;
    slot = ((((FldPanel2dWork *)panel)->side != 0) ^ 1) * 4;
    /* Measured: typed slot arrays (including word aliases) and a typed panel local change codegen. */
    MEMBER(u8 *, slot + (s32)panel, FldPanel2dWork, text[0]) = text;
    slot = ((((FldPanel2dWork *)panel)->side != 0) ^ 1) * 4;
    MEMBER(s32, slot + (s32)panel, FldPanel2dWork, slotXBits[0]) = (s32)0xC3210000;
    ((FldPanel2dWork *)panel)->blinkTimer = 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Mark and stop traversal at an atomic whose bounding sphere reaches the camera frustum. */
// FUN_0018A170
s32 FldRcAtomicFrustumTest(s32 atomic, s32 *visible)
{
    u8 *camera;

    func_003bfae0(atomic);
    camera = ((u8 *)(uintptr_t)kwlnGetCamera());
    if (RwCameraFrustumTestSphere(camera, func_003bfae0(atomic)) != 0) {
        *visible = 1;
        return 0;
    }
    return atomic;
}
#pragma pop

extern unsigned int D_007EFA00[];
extern void FldNpcSetPositionLock(unsigned char *, s32);
extern s32 fldNpcControlIsBusy(unsigned char *);
extern s32 kwlnGetCamera(void);
extern s16 mdlGetLayerAnimation(s32, s32);
#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Release the auxiliary handle and the NPC control allocation. */
// FUN_0018BAD0
void FldNpcControlDestroy(u8 *task) {
    KwlnTask *taskRecord = (KwlnTask *)task;
    s32 handle = ((FldNpcControlWork *)((KwlnTask *)task)->work)->handle;

    if (handle != 0) {
        func_003e0f40(handle);
    }
    /* Keep the allocator-facing void** work load distinct from typed field aliases. */
    jtbl_008873EC[0]((void *)taskRecord->work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Create NPC control work and capture the current camera height. */
// FUN_0018BB20
s32 FldNpcControlTaskCreate(s32 parent, s32 actor)
{
    s32 taskHandle;
    u8 *work;

    chkmemAllocSiteTag(&D_005F5340, 0x2E6);
    work = D_008873F4[0](1, 0x58, 0x40000);
    if (work == NULL)
        return 0;
    taskHandle = (s32)kwlnTaskCreateChild((void *)((u8 *)parent), (const void *)(&D_005F5350), 0xF, 0, 0, FldNpcControlUpdate, FldNpcControlDestroy, (u8 *)(work));
    ((FldNpcControlWork *)work)->actor = actor;
    /* The view's unk80 float is copied as-is; its camera-specific meaning is unknown. */
    ((FldNpcControlWork *)work)->cameraHeight = ((KwlnView *)((u8 *)(uintptr_t)kwlnGetCamera()))->unk80;
    return taskHandle;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Report ready for a missing task or once NPC control reaches state four. */
// FUN_0018BBF0
s32 FldNpcControlReady(u8 *task)
{
    u32 state;

    if (task == NULL) {
        return 1;
    }
    state = ((FldNpcControlWork *)((KwlnTask *)task)->work)->state;
    return state >= 4;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Compare normalized actor and player headings; select a turn animation when outside tolerance. */
// FUN_0018BC20
/* measured: retail's FPU order for this vector normalize only comes out at optimization level 1. */
#pragma optimization_level 1
#pragma push
/* measured: retail loads the shared animation transition constant only once. */
#pragma opt_common_subs on
void FldNpcControlFacePlayer(u8 *task)
{
    FldNpcControlWork *controlWork;
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 *originalHeading;
    f32 *playerHeading;
    f32 actorX;
    f32 actorY;
    f32 actorZ;
    f32 originalZ;
    f32 desiredZ;
    f32 originalX;
    f32 desiredX;
    f32 originalY;
    f32 desiredY;
    u8 *work;
    u8 *matrix;
    void *target;
    s32 zero;

    work = ((KwlnTask *)task)->work;
    controlWork = (FldNpcControlWork *)work;
    matrix = mdlGetMatrix((u32)((ResrcRecord *)(u8 *)((FldNpcControlWork *)work)->actor)->modelHandle164Value);
    originalHeading = (f32 *)(work + 0x30);
    *(struct Vec3 *)originalHeading = *(struct Vec3 *)&((SceneLightMatrix *)matrix)->at;
    RwV3dNormalize((RainVector *)originalHeading, (const RainVector *)originalHeading);
    actorX = ((SceneLightMatrix *)mdlGetMatrix(
        (u32)((ResrcRecord *)(u8 *)controlWork->actor)->modelHandle164Value))->pos.x;
    ((FldNpcControlWork *)work)->headingX = ((SceneLightMatrix *)mdlGetMatrix(
        D_007EFA00[0]))->pos.x - actorX;
    actorY = ((SceneLightMatrix *)mdlGetMatrix(
        (u32)((ResrcRecord *)(u8 *)controlWork->actor)->modelHandle164Value))->pos.y;
    ((FldNpcControlWork *)work)->headingY = ((SceneLightMatrix *)mdlGetMatrix(
        D_007EFA00[0]))->pos.y - actorY;
    actorZ = ((SceneLightMatrix *)mdlGetMatrix(
        (u32)((ResrcRecord *)(u8 *)controlWork->actor)->modelHandle164Value))->pos.z;
    ((FldNpcControlWork *)work)->headingZ = ((SceneLightMatrix *)mdlGetMatrix(
        D_007EFA00[0]))->pos.z - actorZ;
    playerHeading = (f32 *)(work + 0x3C);
    RwV3dNormalize((RainVector *)playerHeading, (const RainVector *)playerHeading);
    originalZ = ((FldNpcControlWork *)work)->savedHeading.z;
    desiredZ = controlWork->headingZ;
    originalX = ((FldNpcControlWork *)work)->savedHeading.x;
    desiredX = controlWork->headingX;
    originalY = ((FldNpcControlWork *)work)->savedHeading.y;
    desiredY = controlWork->headingY;
    if ((originalX * desiredX + originalY * desiredY) +
        originalZ * desiredZ <
        fGpffff8218) {
        ((FldNpcControlWork *)work)->savedAnimation =
            (s16)mdlGetLayerAnimation((u32)((ResrcRecord *)(u8 *)controlWork->actor)->modelHandle164Value, 0);
        target = ((ResrcRecord *)(u8 *)controlWork->actor)->modelHandle164;
        zero = 0;
        mdlDispatchAnimIfPresent(target, zero, 1, 4, 1);
        ((FldNpcControlWork *)work)->state = 5;
        return;
    }
    mdlDispatchAnimIfPresent(((ResrcRecord *)(u8 *)controlWork->actor)->modelHandle164, 0, 3, 8, 0);
    ((FldNpcControlWork *)work)->state = 7;
}
#pragma pop
#pragma pop

#pragma push
#pragma optimization_level 1
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Copy the complete direction vector when starting the transition. The
 * aggregate retains all three source loads with shared constants enabled. */
/* Restore the saved heading, using the turn animation only when outside tolerance. */
// FUN_0018BDD0
#pragma push
/* measured: retail loads the shared animation transition constant only once. */
#pragma opt_common_subs on
void FldNpcControlTurnBack(u8 *task)
{
    FldNpcControlWork *controlWork;
    struct Direction {
        f32 x;
        f32 y;
        f32 z;
    };
    u8 *work;
    u8 *target;
    f32 originalZ;
    f32 desiredZ;
    f32 originalX;
    f32 desiredX;
    f32 originalY;
    f32 desiredY;
    s32 zero;

    work = ((KwlnTask *)task)->work;
    controlWork = (FldNpcControlWork *)work;
    originalZ = ((FldNpcControlWork *)work)->savedHeading.z;
    desiredZ = ((FldNpcControlWork *)work)->headingZ;
    originalX = ((FldNpcControlWork *)work)->savedHeading.x;
    desiredX = ((FldNpcControlWork *)work)->headingX;
    originalY = ((FldNpcControlWork *)work)->savedHeading.y;
    desiredY = ((FldNpcControlWork *)work)->headingY;
    if ((originalX * desiredX + originalY * desiredY) + originalZ * desiredZ <
        fGpffff8218) {
        *(struct Direction *)&controlWork->heading = *(struct Direction *)&controlWork->savedHeading;
        target = (u8 *)((ResrcRecord *)(u8 *)((FldNpcControlWork *)work)->actor)->modelHandle164;
        zero = 0;
        mdlDispatchAnimIfPresent(target, zero, 1, 4, 1);
        ((FldNpcControlWork *)work)->state = 6;
        return;
    }
    mdlDispatchAnimIfPresent((u8 *)((ResrcRecord *)(u8 *)((FldNpcControlWork *)work)->actor)->modelHandle164,
                  0, 0, 8, 1);
    ((FldNpcControlWork *)work)->state = 4;
}
#pragma pop
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Forward the lock to the NPC resource list and its requested position slot. */
// FUN_0018BED0
void FldNpcSetPositionLock(u8 *task, s32 locked) {
    FldNpcControlWork *controlWork;
    u8 *work = ((KwlnTask *)task)->work;
    controlWork = (FldNpcControlWork *)work;

    if ((s32)((FldFrame *)MT_Scene_GetFrameState())->dependentTasks[((FldNpcControlWork *)work)->actorIndex] == 0) {
        return;
    }
    FldRc_SetPositionSlotLock((s32)((FldFrame *)MT_Scene_GetFrameState())->dependentTasks[controlWork->actorIndex],
                  ((FldNpcControlWork *)work)->positionSlot, locked);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Report turn states or the actor state-3 pause as busy. */
// FUN_0018BF50
s32 fldNpcControlIsBusy(u8 *task) {
    /* Interpret the turn counter as signed; actor state is the low halfword of handle220 on the little-endian EE. */
    u8 *work = ((KwlnTask *)task)->work;
    s32 busy = 0;
    s32 state = ((FldNpcControlWork *)work)->state;
    if (state == 5) {
        goto set;
    }
    if (state != 6) {
        goto rest;
    }
set:
    busy = 1;
rest:
    if (((u16 *)&((ResrcRecord *)(u8 *)((FldNpcControlWork *)work)->actor)->handle220)[0] == 3) {
        if ((s32)((FldNpcControlWork *)work)->turnFrames > 0) {
            busy = 1;
        }
    }
    return busy;
}
#pragma pop

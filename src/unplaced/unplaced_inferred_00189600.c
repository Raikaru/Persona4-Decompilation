/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00189600-0018bf50 */

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
typedef RwV3d RainVector;

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
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189600
/* Move eye and target toward a preset at the requested speed, or snap when speed is zero. */
void FldLmapCameraMoveTo(u8 *task, s32 mode, s32 preset, f32 speed)
{
    /* Separate preset/global and matrix aliases retain their measured access widths. */
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    f32 eyeDirection[4];
    f32 targetDirection[4];
    f32 targetDistance;
    f32 eyeDistance;
    s32 presetOffset;
    s32 snapOffset;
    s32 state;
    u8 *eye;
    u8 *target;
    u8 *work;

    work = *(u8 **)(task + 0x38);
    kwlnGetCamera();
    state = ((FldLmapCameraWork *)work)->state;
    if ((state != 1) || (((FldLmapCameraWork *)work)->preset != preset)) {
        if (speed != 0.0f) {
            ((FldLmapCameraWork *)work)->mode = mode;
            ((FldLmapCameraWork *)work)->preset = preset;
            presetOffset = preset * 0x18;
            eyeDirection[0] = *(f32 *)((u8 *)D_005F2190 + presetOffset) -
                     ((FldLmapCameraWork *)work)->eye[0];
            eyeDirection[1] = *(f32 *)((u8 *)D_005F2194 + presetOffset) -
                     ((FldLmapCameraWork *)work)->eye[1];
            eyeDirection[2] = *(f32 *)((u8 *)D_005F2198 + presetOffset) -
                     ((FldLmapCameraWork *)work)->eye[2];
            eyeDistance = RwV3dNormalize((RainVector *)&eyeDirection[0], (const RainVector *)&eyeDirection[0]);
            targetDirection[0] = *(f32 *)((u8 *)D_005F219C + presetOffset) -
                     ((FldLmapCameraWork *)work)->target[0];
            targetDirection[1] = *(f32 *)((u8 *)D_005F21A0 + presetOffset) -
                     ((FldLmapCameraWork *)work)->target[1];
            targetDirection[2] = *(f32 *)((u8 *)D_005F21A4 + presetOffset) -
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
        *(struct Vec3 *)(work + 4) = *(struct Vec3 *)eye;
        target = (u8 *)D_005F219C + snapOffset;
        *(struct Vec3 *)(work + 0x10) = *(struct Vec3 *)target;
        K_ClumpLookAtBasis(((u8 *)(uintptr_t)kwlnGetCamera()), eye, target, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189870
#pragma opt_propagation off
/* Establish the sky/panel render-state preset before queued primitives draw. */
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189940
/* Measured: 1348 executable bytes, 26 resolved relocations, 12 zero tail bytes.
 * Preserve integer-to-float conversions and reloads across rendering callbacks.
 * Indexed addresses stay integer-valued until their final pointer conversion. */
#pragma opt_loop_invariants on
/* Animate panel entry and alternating text slots, then queue their quads and labels. */
s32 FldPanel2dUpdate(u8 *task)
{
    /* Proven work offsets remain raw: typed field access changes MWCC scheduling/aliasing. */
    u8 *work;
    u8 *primitive;
    f32 depth;
    f32 reciprocalDepth;
    f32 top;
    f32 progress;
    s32 i;

    work = *(u8 **)(task + 0x38);
    if (*(s32 *)(work + 4) == 1) {
        return 0;
    }

    switch (*(s32 *)work) {
    case 0:
        depth = D_008872F8[0] - (f32)58980;
        reciprocalDepth = 1.0f / depth;
        *(s32 *)(work + 8) = 0;
        *(f32 *)(((*(s32 *)(work + 8) << 2) + (u32)work + 0x18)) = 175.0f;
        *(f32 *)(work + 0x20) = 0.0f;
        top = (f32)401;
        *(f32 *)(work + 0x24) = top;
        *(f32 *)(work + 0x28) = depth;
        *(f32 *)(work + 0x60) = 25.0f;
        *(f32 *)(work + 0x64) = top;
        *(f32 *)(work + 0x68) = depth;
        *(f32 *)(work + 0xA0) = 0.0f;
        progress = (f32)427;
        *(f32 *)(work + 0xA4) = progress;
        *(f32 *)(work + 0xA8) = depth;
        *(f32 *)(work + 0xE0) = 25.0f;
        *(f32 *)(work + 0xE4) = progress;
        *(f32 *)(work + 0xE8) = depth;
        *(f32 *)(work + 0x120) = 326.0f;
        *(f32 *)(work + 0x124) = top;
        *(f32 *)(work + 0x128) = depth;
        *(f32 *)(work + 0x160) = 660.0f;
        *(f32 *)(work + 0x164) = top;
        *(f32 *)(work + 0x168) = depth;
        *(f32 *)(work + 0x1A0) = 326.0f;
        *(f32 *)(work + 0x1A4) = progress;
        *(f32 *)(work + 0x1A8) = depth;
        *(f32 *)(work + 0x1E0) = 660.0f;
        *(f32 *)(work + 0x1E4) = progress;
        *(f32 *)(work + 0x1E8) = depth;
        for (i = 0; i < 4; i++) {
            primitive = work + (i << 6);
            *(f32 *)(primitive + 0x38) = reciprocalDepth;
            *(f32 *)(primitive + 0x138) = reciprocalDepth;
            *(f32 *)(primitive + 0x40) = 255.0f;
            *(f32 *)(primitive + 0x44) = 0.0f;
            *(f32 *)(primitive + 0x48) = 0.0f;
            *(f32 *)(primitive + 0x4C) = 0.0f;
            *(f32 *)(primitive + 0x140) = 255.0f;
            *(f32 *)(primitive + 0x144) = 0.0f;
            *(f32 *)(primitive + 0x148) = 0.0f;
            *(f32 *)(primitive + 0x14C) = 0.0f;
        }
        *(s32 *)work += 1;
        break;
    case 1:
        *(f32 *)(work + 0x22C) = sinf((D_00761184 * (f32)*(s32 *)(work + 0x220)) / 10.0f);
        if (*(s32 *)(work + 0x220) < 10) {
            *(s32 *)(work + 0x220) += 1;
        } else {
            *(s32 *)work += 1;
        }
        *(f32 *)(work + 0x224) = (-300.0f + 0.0f) + 316.0f * *(f32 *)(work + 0x22C);
        *(f32 *)(work + 0x228) = ((f32)371 + 0.0f) + 30.0f * *(f32 *)(work + 0x22C);
        /* fallthrough */
    case 2:
        sflDataDrawNarrowRoundedFrame((s32)*(f32 *)(work + 0x224), (s32)*(f32 *)(work + 0x228), (f32)59000, 301, 26, 0xFAFF20, 255, 1, 150, 13, D_00794C60, -5.0f, 1.0f, 1.0f);
        sflDataDrawNarrowRoundedFrame(25, 401, (f32)59000, 301, 26, 0x191919, 255, 1, 150, 13, D_00794C60, 0.0f, 1.0f, *(f32 *)(work + 0x22C));
        if (!(*(f32 *)(work + 0x22C) < 1.0f)) {
            if (*(s32 *)((((!(u32)*(s32 *)(work + 8)) << 2) + (u32)work + 0x10)) != 0) {
                progress = sinf((D_00761184 * (f32)*(s32 *)(work + 0xC)) / 10.0f);
                *(f32 *)(((*(s32 *)(work + 8) << 2) + (u32)work + 0x18)) = 175.0f + 336.0f * progress;
                *(f32 *)((((!(u32)*(s32 *)(work + 8)) << 2) + (u32)work + 0x18)) = -161.0f + 336.0f * progress;
                if (*(s32 *)(work + 0xC) < 10) {
                    *(s32 *)(work + 0xC) += 1;
                } else {
                    *(s32 *)(((*(s32 *)(work + 8) << 2) + (u32)work + 0x10)) = 0;
                    *(s32 *)(work + 8) = !(u32)*(s32 *)(work + 8);
                }
            }
            primitive = PrimQueueDrawPrimitive(D_00794C60, 4, work + 0x20, 4);
            *(void (**)(void))(primitive + 8) = FldSkyApplyDefaultPreset;
            *(s32 *)(primitive + 0x10) = 0;
            PrimQueueDrawPrimitive(D_00794C60, 4, work + 0x120, 4);
            if (*(const char **)(work + 0x10) != NULL) {
                frFontExDrawTextDeferredWithCharWidth((f32)(s32)*(f32 *)(work + 0x18), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(work + 0x10), 8, 0, D_00794C60, -1);
            }
            if (*(const char **)(work + 0x14) != NULL) {
                frFontExDrawTextDeferredWithCharWidth((f32)(s32)*(f32 *)(work + 0x1C), (f32)399, (f32)58990, -1, 0, 1, *(const char **)(work + 0x14), 8, 0, D_00794C60, -1);
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189E90
void FldPanel2dDestroy(u8 *task)
{
    /* Keep the allocator-facing void** work load distinct from typed field aliases. */
    jtbl_008873EC[0](*(void **)(task + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189EC0
/* Lazily allocate the panel task and initialize its text from the current area. */
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00189FA0
/* Destroy the frame-owned panel hierarchy; return whether one was present. */
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018A010
/* Stage explicit or area-selected text in the inactive slot and restart its slide. */
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
    /* Integer-indexed panel/frame addresses preserve the measured reload ordering. */
    u8 *panel;
    s32 slot;
    u8 *selectedText;

    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + 0x30) == 0) {
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
                    index = *(u16 *)((u8 *)*entry + *(location + 1) * 2);
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
    panel = *(u8 **)(*(u8 **)((u8 *)MT_Scene_GetFrameState() + 0x30) + 0x38);
    slot = ((*(s32 *)(panel + 8) != 0) ^ 1) * 4;
    *(u8 **)(slot + (s32)panel + 0x10) = text;
    slot = ((*(s32 *)(panel + 8) != 0) ^ 1) * 4;
    *(s32 *)(slot + (s32)panel + 0x18) = (s32)0xC3210000;
    *(s32 *)(panel + 0xC) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018A170
/* Mark and stop traversal at an atomic whose bounding sphere reaches the camera frustum. */
s32 FldRcAtomicFrustumTest(s32 atomic, s32 *visible)
{
    u8 *camera;

    func_003bfae0();
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BAD0
/* Release the auxiliary handle and the NPC control allocation. */
void FldNpcControlDestroy(u8 *task) {
    s32 handle = ((FldNpcControlWork *)((KwlnTask *)task)->work)->handle;

    if (handle != 0) {
        func_003e0f40(handle);
    }
    /* Keep the allocator-facing void** work load distinct from typed field aliases. */
    jtbl_008873EC[0](*(void **)(task + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BB20
/* Create NPC control work and capture the current camera height. */
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
    /* Camera is returned as an opaque handle here; preserve the observed float at +80. */
    ((FldNpcControlWork *)work)->cameraHeight = *(f32 *)(((u8 *)(uintptr_t)kwlnGetCamera()) + 0x80);
    return taskHandle;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Shared animation contracts: CSE retains the common transition constant.
 * The O1 profile still preserves the retail FPU accumulator order. */
// FUN_0018BC20
/* measured: optimization_level 1 preserves retail's FPU scheduling for this
   vector normalize; -O2 reorders it into a mismatching form. */
#pragma optimization_level 1
#pragma push
#pragma opt_common_subs on
/* Compare normalized actor/player headings; select a turn animation when outside tolerance. */
void FldNpcControlFacePlayer(u8 *task)
{
    /* Proven work offsets remain raw: typed field access changes MWCC scheduling/aliasing. */
    /* Separate preset/global and matrix aliases retain their measured access widths. */
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

    work = *(u8 **)(task + 0x38);
    matrix = mdlGetMatrix(*(u32 *)(*(u8 **)(work + 0xC) + 0x164));
    originalHeading = (f32 *)(work + 0x30);
    *(struct Vec3 *)originalHeading = *(struct Vec3 *)(matrix + 0x20);
    RwV3dNormalize((RainVector *)originalHeading, (const RainVector *)originalHeading);
    actorX = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(work + 0xC) + 0x164)) + 0x30);
    *(f32 *)(work + 0x3C) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x30) - actorX;
    actorY = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(work + 0xC) + 0x164)) + 0x34);
    *(f32 *)(work + 0x40) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x34) - actorY;
    actorZ = *(f32 *)(mdlGetMatrix(
        *(u32 *)(*(u8 **)(work + 0xC) + 0x164)) + 0x38);
    *(f32 *)(work + 0x44) = *(f32 *)(mdlGetMatrix(
        D_007EFA00[0]) + 0x38) - actorZ;
    playerHeading = (f32 *)(work + 0x3C);
    RwV3dNormalize((RainVector *)playerHeading, (const RainVector *)playerHeading);
    originalZ = *(f32 *)(work + 0x38);
    desiredZ = *(f32 *)(work + 0x44);
    originalX = *(f32 *)(work + 0x30);
    desiredX = *(f32 *)(work + 0x3C);
    originalY = *(f32 *)(work + 0x34);
    desiredY = *(f32 *)(work + 0x40);
    if ((originalX * desiredX + originalY * desiredY) +
        originalZ * desiredZ <
        fGpffff8218) {
        *(s32 *)(work + 0x2C) =
            (s16)mdlGetLayerAnimation(*(u32 *)(*(u8 **)(work + 0xC) + 0x164), 0);
        target = *(void **)(*(u8 **)(work + 0xC) + 0x164);
        zero = 0;
        mdlDispatchAnimIfPresent(target, zero, 1, 4, 1);
        *(s32 *)work = 5;
        return;
    }
    mdlDispatchAnimIfPresent(*(void **)(*(u8 **)(work + 0xC) + 0x164), 0, 3, 8, 0);
    *(s32 *)work = 7;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 1
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Copy the complete direction vector when starting the transition. The
 * aggregate retains all three source loads with shared constants enabled. */
// FUN_0018BDD0
#pragma push
#pragma opt_common_subs on
/* Restore the saved heading, using the turn animation only when outside tolerance. */
void FldNpcControlTurnBack(u8 *task)
{
    /* Aggregate heading copies and actor model pointers retain their measured access widths. */
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

    work = *(u8 **)(task + 0x38);
    originalZ = *(f32 *)(work + 0x38);
    desiredZ = ((FldNpcControlWork *)work)->headingZ;
    originalX = *(f32 *)(work + 0x30);
    desiredX = ((FldNpcControlWork *)work)->headingX;
    originalY = *(f32 *)(work + 0x34);
    desiredY = ((FldNpcControlWork *)work)->headingY;
    if ((originalX * desiredX + originalY * desiredY) + originalZ * desiredZ <
        fGpffff8218) {
        *(struct Direction *)(work + 0x3C) = *(struct Direction *)(work + 0x30);
        target = *(u8 **)(*(u8 **)(work + 0xC) + 0x164);
        zero = 0;
        mdlDispatchAnimIfPresent(target, zero, 1, 4, 1);
        *(s32 *)work = 6;
        return;
    }
    mdlDispatchAnimIfPresent(*(u8 **)(*(u8 **)(work + 0xC) + 0x164),
                  0, 0, 8, 1);
    *(s32 *)work = 4;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BED0
/* Forward the lock to the NPC resource list and its requested position slot. */
void FldNpcSetPositionLock(u8 *task, s32 locked) {
    /* Typed work access changes codegen; +50/+54 select the actor resource and position slot. */
    u8 *work = *(u8 **)(task + 0x38);

    if (*(s32 *)((u8 *)MT_Scene_GetFrameState() + *(s32 *)(work + 0x50) * 4 + 0x34) == 0) {
        return;
    }
    FldRc_SetPositionSlotLock(*(s32 *)((u8 *)MT_Scene_GetFrameState() + *(s32 *)(work + 0x50) * 4 + 0x34),
                  *(s32 *)(work + 0x54), locked);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018BF50
/* Report turn states or the actor state-3 pause as busy. */
s32 fldNpcControlIsBusy(u8 *task) {
    /* Keep +24 signed (the shared work type is unsigned); actor state uses the partial +220 layout. */
    u8 *work = *(u8 **)(task + 0x38);
    s32 busy = 0;
    s32 state = *(s32 *)work;
    if (state == 5) {
        goto set;
    }
    if (state != 6) {
        goto rest;
    }
set:
    busy = 1;
rest:
    if (*(u16 *)(*(u8 **)(work + 0xC) + 0x220) == 3) {
        if (*(s32 *)(work + 0x24) > 0) {
            busy = 1;
        }
    }
    return busy;
}
#pragma pop

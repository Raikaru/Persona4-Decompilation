#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit effCrossfade.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

/* The task owns a 0x40-byte work block; the embedded submission node starts
 * at +0x10 and carries its callback at +0x18 and owner at +0x20. */
typedef struct CrossfadeWork {
    u8 state;
    u8 pad01;
    u16 frameLimit;
    u16 frame;
    u8 pad06[2];
    s32 raster;
    struct CrossfadeCamera *camera;
    s32 nodeNext;
    s32 nodePrevious;
    void *advance;
    u8 pad1C[4];
    struct CrossfadeWork *owner;
    u8 pad24[0x1C];
} CrossfadeWork;

/* Only the frame link and frame-buffer raster are accessed here. */
typedef struct CrossfadeCamera {
    u8 pad00[4];
    s32 frame;
    u8 pad08[0x58];
    s32 raster;
} CrossfadeCamera;

typedef struct CrossfadeTask {
    u8 pad00[0x38];
    CrossfadeWork *work;
} CrossfadeTask;

extern char D_007145F0[];
extern char D_00714608[];
extern char D_00714618[];
extern u8 *iGpffffbb9c;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 *kwlnTaskGetTaskByName(void *name);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void kAssertFail(const char *file, s32 line);
extern void memset(void *dst, s32 value, u32 size);

extern void mdlEffectDrawCameraFade(u8 *fade);
extern s32 effCrossfadeCaptureDisplay(u8 *object);
extern void mdlEffectReleaseCameraTexture(u8 *object);
extern s32 CrossfadeUpdate(u8 *task);
extern void CrossfadeAdvance(u8 *unusedTask, u8 *work);
extern u8 *func_003e84a0(void);
extern s32 func_003e9320(void);
extern void func_003efd20(void *a, void *b);
extern s32 func_003ec590(s32 a, s32 b, s32 c, s32 d);
extern void RpSkyTexCacheRasterLock(s32 a, s32 b);
extern void RwCameraSetProjectionType(void *a, s32 b);
extern void PrimAppendNode(void *list, void *node);

// Crossfade state machine: state 1 sets up the camera and projection and falls through to state 2, state 2 runs func_004b2780 and advances to state 3, state 3 runs the update through the registered pack, and state 4 runs func_004b2e00 and returns to idle.
// FUN_004B2ED0
s32 CrossfadeUpdate(u8 *task) {
    CrossfadeWork *work;
    s32 raster;

    work = ((CrossfadeTask *)task)->work;
    switch (work->state) {
    case 0:
        return 0;
    case 1:
        if (work->raster != 0) {
            kAssertFail(D_00714608, 0xF2);
        }
        if (work->camera != NULL) {
            kAssertFail(D_00714608, 0xF3);
        }
        work->camera = (CrossfadeCamera *)func_003e84a0();
        if (work->camera == NULL) {
            return 0;
        }
        func_003efd20(work->camera, (void *)func_003e9320());
        if (work->camera->frame == 0) {
            return 0;
        }
        raster = func_003ec590(0x200, 0x100, 0x10, 0x185);
        work->raster = raster;
        if (raster == 0) {
            return 0;
        }
        RpSkyTexCacheRasterLock(raster, 1);
        RwCameraSetProjectionType(work->camera, 2);
        work->camera->raster = work->raster;
        work->frame = 0;
        /* fallthrough */
    case 2:
        if (effCrossfadeCaptureDisplay((u8 *)work) == 0) {
            return 0;
        }
        work->state = 3;
        /* fallthrough */
    case 3:
        if (iGpffffbb9c != 0) {
            work->nodeNext = 0;
            work->nodePrevious = 0;
            PrimAppendNode(iGpffffbb9c, &work->nodeNext);
        }
        break;
    default:
        break;
    case 4:
        mdlEffectReleaseCameraTexture((u8 *)work);
        work->state = 0;
        break;
    }
    return 0;
}

/* The store/mask order recorded here as a floor is source-drivable: using the
   compound assignment's VALUE (see the measured comment at the site) puts the
   sh before the andi. The single-case switch is still what gives the positive
   beq to the out-of-line body. */
// In state 3 advances the frame counter at +4 and moves to state 4 once it reaches the limit at +2.
// FUN_004B30A0
void CrossfadeAdvance(u8 *unusedTask, u8 *work)
{
    s32 nextFrame;

    switch (((CrossfadeWork *)work)->state) {
    case 3:
        mdlEffectDrawCameraFade(work);
        /* measured: using the compound assignment's VALUE keeps the nextFrame
           counter in one register, so the sh lands before the compare mask
           exactly as retail does; a separate increment-then-store pair masks
           first. */
        nextFrame = (((CrossfadeWork *)work)->frame += 1);
        if ((s32)(nextFrame & 0xFFFF) >= (s32)((CrossfadeWork *)work)->frameLimit) {
            ((CrossfadeWork *)work)->state = 4;
        }
        break;
    }
}

// Starts a crossfade on the named task when it is idle: stores state 1 and unusedTask in its work block; returns 1 on success, 0 when the task is missing or busy.
// FUN_004B3110
s32 CrossfadeRequest(s16 frameLimit) {
    u8 *task;
    u8 *work;

    task = (u8 *)kwlnTaskGetTaskByName(D_007145F0);
    if (task == NULL) {
        return 0;
    }
    work = (u8 *)((CrossfadeTask *)task)->work;
    if (((CrossfadeWork *)work)->state != 0) {
        return 0;
    }
    ((CrossfadeWork *)work)->state = 1;
    ((CrossfadeWork *)work)->frameLimit = frameLimit;
    return 1;
}

// Allocates the crossfade work block, registers CrossfadeAdvance and CrossfadeUpdate, and creates the update task at priority frameLimit.
// FUN_004B3180
void CrossfadeCreateTask(s32 priority) {
    u8 *work;

    chkmemAllocSiteTag(D_00714618, 0x171);
    work = (u8 *)(*jtbl_008873E8)(0x40, 0x40000);
    memset(work, 0, 0x40);
    if (work == NULL) {
        kAssertFail(D_00714608, 0x15B);
    }
    ((CrossfadeWork *)work)->advance = (void *)CrossfadeAdvance;
    ((CrossfadeWork *)work)->owner = (CrossfadeWork *)work;
    ((CrossfadeWork *)work)->state = 0;
    (s32)kwlnTaskCreate((const void *)(D_007145F0), priority, 0, 0, CrossfadeUpdate, 0, (u8 *)(work));
}

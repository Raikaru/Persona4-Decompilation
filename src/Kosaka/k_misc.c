#include "Kosaka/k_misc_work_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"

/* Task-work helpers for the Kosaka module. Counterparts of the Persona 3 FES
 * k_misc.c families (delay model destroy / script shutdown / rmd fade); the
 * P4 build adds a countdown to the delay-model-destroy work and a state
 * machine to the rmd fade. */

typedef struct KwlnTask KwlnTask;
typedef struct Model Model;

typedef struct KwlnTask
{
    u8 pad[0x38];
    void* workData; /* 0x38 */
} KwlnTask;

typedef struct RwRGBA
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
} RwRGBA;

/* 4 bytes */
typedef struct ScrShutdownWork
{
    KwlnTask* scrTask; /* 0x00 */
} ScrShutdownWork;

extern void chkmemAllocSiteTag(const void* file, u32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);  /* RwCalloc slot */
extern void (*jtbl_008873EC[])(void*);      /* RwFree slot */

extern u8 kwlnTaskDestroyWithHierarchy(void* task);        /* kwlnTaskDestroyWithHierarchy */
extern u8* mdlGetColor(void* mdl);        /* mdlGetColor */
extern void mdlSetColor(void* mdl, void* color); /* mdlSetColor */
extern char D_005EFB28[];                   /* "k_misc.c" */
extern char D_005EFB40[];                   /* "delay model(RMD) destroy" */
extern char D_005EFB60[];                   /* "script shutdown(kosaka)" */
extern char D_005EFB80[];                   /* "rmd fade(kosaka)" */
static inline s32 kMiscOr(s32 left, s32 right)
{
    left |= right;
    return left;
}
s32 KMisc_DelayMdlFreeUpdate(u8 *task);  /* delay-model-destroy update, sibling unit */
void KMisc_DelayMdlFreeDestroy(u8 *task); /* delay-model-destroy destroy, sibling unit */

// FUN_0014B870
s32 KMisc_CreateDelayMdlFree(Model* mdl, s32 countdown)
{
    DelayMdlFreeWork* work;
    s32 task;

    chkmemAllocSiteTag(D_005EFB28, 0x14C);
    work = (DelayMdlFreeWork*)D_008873F4[0](1, sizeof(DelayMdlFreeWork), 0x40000);
    if (work == NULL)
    {
        return 0;
    }

    task = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005EFB40), 0xF, 0, 0, KMisc_DelayMdlFreeUpdate, KMisc_DelayMdlFreeDestroy, (u8 *)((u8*)work));
    work->mdl = mdl;
    work->countdown = countdown;

    return task;
}

/* Destroy the recorded script task and its hierarchy, then finish this helper task. */
// FUN_0014B930
s32 KMisc_ScrShutdownUpdate(u8 *task)
{
    KwlnTask* scrShutdownTask = (KwlnTask*)task;

    kwlnTaskDestroyWithHierarchy(((ScrShutdownWork*)scrShutdownTask->workData)->scrTask);

    return -1;
}

/* Release the one-shot script-shutdown work after its callback has finished. */
// FUN_0014B960
void KMisc_ScrShutdownDestroy(u8 *task)
{
    KwlnTask* scrShutdownTask = (KwlnTask*)task;

    jtbl_008873EC[0](scrShutdownTask->workData);
}

/* Create a one-shot helper that destroys the supplied script hierarchy. */
// FUN_0014B990
s32 KMisc_CreateScrShutdown(KwlnTask* scrTask)
{
    ScrShutdownWork* work;
    s32 task;

    chkmemAllocSiteTag(D_005EFB28, 0x178);
    work = (ScrShutdownWork*)D_008873F4[0](1, sizeof(ScrShutdownWork), 0x40000);
    if (work == NULL)
    {
        return 0;
    }

    task = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_005EFB60), 0xF, 0, 0, KMisc_ScrShutdownUpdate, KMisc_ScrShutdownDestroy, (u8 *)((u8*)work));
    work->scrTask = scrTask;

    return task;
}

/* Interpolate model alpha to its target over the remaining frames, then hold the final alpha. */
// FUN_0014BA40
s32 KMisc_RmdFadeUpdate(u8 *task)
{
    RmdFadeWork* work;
    u8* rgba;
    RwRGBA color;
    f32 alpha;

    work = (RmdFadeWork *)((KwlnTask *)task)->workData;
    rgba = mdlGetColor(work->mdl);
    color = *(RwRGBA *)rgba;
    switch (work->state) {
    case 0:
        alpha = work->targetAlpha;
        alpha = alpha - work->currentAlpha;
        alpha = alpha / (f32)work->framesRemaining + work->currentAlpha;
        work->currentAlpha = alpha;
        color.a = (u8)alpha;
        mdlSetColor(work->mdl, &color);
        work->framesRemaining--;
        if (work->framesRemaining <= 0) {
            color.a = (u8)work->targetAlpha;
            mdlSetColor(work->mdl, &color);
            work->state = 1;
        }
        break;
    case 1:
        break;
    }
done:
    return 0;
}

/* Release the model fade work without changing the model color. */
// FUN_0014BBB0
void KMisc_RmdFadeDestroy(u8 *task)
{
    KwlnTask* rmdFadeTask = (KwlnTask*)task;

    jtbl_008873EC[0](rmdFadeTask->workData);
}

/* Create a model-alpha interpolation task with explicit starting and target alpha. */
// FUN_0014BBE0
s32 KMisc_CreateRmdFade(s32 parent, s32 model, s32 startAlpha, s32 targetAlpha, s32 frames)
{
    RwRGBA color;
    u8* rgba;
    f32 target;
    f32 current;
    s32 task;
    RmdFadeWork* work;

    rgba = mdlGetColor((void*)model);
    color = *(RwRGBA *)rgba;
    if (model == 0) {
        return 0;
    }
    chkmemAllocSiteTag(D_005EFB28, 0x1C6);
    work = (RmdFadeWork*)D_008873F4[0](1, sizeof(RmdFadeWork), 0x40000);
    if (work == NULL) {
        return 0;
    }
    task = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005EFB80), 0xF, 0, 0, KMisc_RmdFadeUpdate, KMisc_RmdFadeDestroy, (u8 *)((u8*)work));
    work->mdl = (Model*)model;
    target = (f32)(u32)targetAlpha;
    work->targetAlpha = target;
    work->framesRemaining = frames;
    current = (f32)(u32)startAlpha;
    work->currentAlpha = current;
    mdlSetColor((void*)model, &color);
    return task;
}

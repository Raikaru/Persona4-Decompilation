#include "include_asm.h"
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

/* 12 bytes */
typedef struct DelayMdlFreeWork
{
    s32 state;    /* 0x00 */
    s32 countdown; /* 0x04 */
    Model* mdl;   /* 0x08 */
} DelayMdlFreeWork;

/* 4 bytes */
typedef struct ScrShutdownWork
{
    KwlnTask* scrTask; /* 0x00 */
} ScrShutdownWork;

/* 20 bytes */
typedef struct RmdFadeWork
{
    s32 state;           /* 0x00 */
    Model* mdl;          /* 0x04 */
    f32 targetAlpha;     /* 0x08 */
    f32 currentAlpha;    /* 0x0c */
    s32 framesRemaining; /* 0x10 */
} RmdFadeWork;

extern void func_0044ea90(const void* file, u32 line);
extern u8 *(*D_008873F4[])(s32, s32, s32);  /* RwCalloc slot */
extern void (*jtbl_008873EC[])(void*);      /* RwFree slot */
extern s32 func_00451fc0(s32 arg0, char* arg1, s32 arg2, s32 arg3, s32 arg4,
                         s32 (*init)(void*), void (*destroy)(void*), u8* work);
extern u8 func_00452080(void* task);        /* kwlnTaskDestroyWithHierarchy */
extern u8* func_0047a250(void* mdl);        /* mdlGetColor */
extern void func_0047a220(void* mdl, void* color); /* mdlSetColor */
extern char D_005EFB28[];                   /* "k_misc.c" */
extern char D_005EFB40[];                   /* "delay model(RMD) destroy" */
extern char D_005EFB60[];                   /* "script shutdown(kosaka)" */
extern char D_005EFB80[];                   /* "rmd fade(kosaka)" */
static inline s32 kMiscOr(s32 left, s32 right)
{
    left |= right;
    return left;
}
s32 func_0014b780(void*);  /* delay-model-destroy update, sibling unit */
void func_0014b840(void*); /* delay-model-destroy destroy, sibling unit */

// FUN_0014B870
s32 func_0014b870(Model* mdl, s32 countdown)
{
    DelayMdlFreeWork* work;
    s32 task;

    func_0044ea90(D_005EFB28, 0x14C);
    work = (DelayMdlFreeWork*)D_008873F4[0](1, sizeof(DelayMdlFreeWork), 0x40000);
    if (work == NULL)
    {
        return 0;
    }

    task = func_00451fc0(0, D_005EFB40, 0xF, 0, 0, func_0014b780, func_0014b840, (u8*)work);
    work->mdl = mdl;
    work->countdown = countdown;

    return task;
}

// FUN_0014B930
s32 func_0014b930(void* arg0)
{
    KwlnTask* scrShutdownTask = (KwlnTask*)arg0;

    func_00452080(((ScrShutdownWork*)scrShutdownTask->workData)->scrTask);

    return -1;
}

// FUN_0014B960
void func_0014b960(void* arg0)
{
    KwlnTask* scrShutdownTask = (KwlnTask*)arg0;

    jtbl_008873EC[0](scrShutdownTask->workData);
}

// FUN_0014B990
s32 func_0014b990(KwlnTask* scrTask)
{
    ScrShutdownWork* work;
    s32 task;

    func_0044ea90(D_005EFB28, 0x178);
    work = (ScrShutdownWork*)D_008873F4[0](1, sizeof(ScrShutdownWork), 0x40000);
    if (work == NULL)
    {
        return 0;
    }

    task = func_00451fc0(0, D_005EFB60, 0xF, 0, 0, func_0014b930, func_0014b960, (u8*)work);
    work->scrTask = scrTask;

    return task;
}

// FUN_0014BA40
s32 func_0014ba40(void* arg0)
{
    RmdFadeWork* work;
    u8* rgba;
    RwRGBA color;
    f32 alpha;

    work = (RmdFadeWork *)((KwlnTask *)arg0)->workData;
    rgba = func_0047a250(work->mdl);
    color = *(RwRGBA *)rgba;
    switch (work->state) {
    case 0:
        alpha = work->targetAlpha;
        alpha = alpha - work->currentAlpha;
        alpha = alpha / (f32)work->framesRemaining + work->currentAlpha;
        work->currentAlpha = alpha;
        color.a = (u8)alpha;
        func_0047a220(work->mdl, &color);
        work->framesRemaining--;
        if (work->framesRemaining <= 0) {
            color.a = (u8)work->targetAlpha;
            func_0047a220(work->mdl, &color);
            work->state = 1;
        }
        break;
    case 1:
        break;
    }
done:
    return 0;
}

// FUN_0014BBB0
void func_0014bbb0(void* arg0)
{
    KwlnTask* rmdFadeTask = (KwlnTask*)arg0;

    jtbl_008873EC[0](rmdFadeTask->workData);
}

/* Parked at nd 4 with the retail-sized object (432B/432B). Residual rows:
   0x11C/0x15C: candidate `or $v0,$v1,$v0`, retail `or $v1,$v1,$v0`;
   0x120/0x160: candidate `mtc1 $v0,$f0`, retail `mtc1 $v1,$f0`.
   The same two register-coloring residuals repeat for target/current alpha.
   Tried alternate signed/unsigned half temporaries, declaration order,
   in-place OR, aggregate/direct color spellings, reversed OR operands
   (nd 20), differently typed OR operands, a named OR-result local, a
   separate float-conversion local, distinct target/current-arm locals, and
   split float assignments that read the OR result after mtc1 (each nd 4).
   A typed read-after-mtc1 variant grew to 528B/432B at nd 190. All other
   rows match. Committed at nd 4. */
// FUN_0014BBE0 NONMATCHING
INCLUDE_ASM("asm/nonmatchings/k_misc", func_0014bbe0);

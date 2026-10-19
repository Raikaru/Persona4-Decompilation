/* Whole-file translation unit (functions contiguous in retail). */
#include "type.h"
#include "sdk_task_registration.h"
#include "effect_instance_internal.h"

typedef struct ShdFbuf
{
    u8  flags;
    u8  pad1[3];
    u32 firstColor;    /* 0x04 */
    u32 secondColor;    /* 0x08 */
    u32 thirdColor;    /* 0x0C */
    f32 firstValue;   /* 0x10 */
    u32 fourthColor;   /* 0x14 */
    f32 secondValue;   /* 0x18 */
    u32 pad1C; /* 0x1C */
    u32 pad20; /* 0x20 */
} ShdFbuf;

typedef struct ShdTask
{
    s32 effectHandle;   /* 0x00 */
    s32 contextHandle;   /* 0x04 */
    s32 frameLimit;   /* 0x08 */
} ShdTask;

typedef struct ShdFarg
{
    s32 firstValue;    /* 0x00 */
    s32 secondValue;    /* 0x04 */
    f32 firstFloat;    /* 0x08 */
    f32 secondFloat;    /* 0x0C */
} ShdFarg;

/* Allocated as 0x14 bytes by shdEffectCreateBlurTask. */
typedef struct ShdBlurTaskWork {
    s32 state;
    s32 filter;
    s32 unk8;
    s32 renderParameter;
    void *renderContext;
} ShdBlurTaskWork;

/* Only the tail is accessed here; the preceding effect layout is unknown. */
typedef struct ShdEffectRenderParams {
    u8 pad0[0xB8];
    s32 parameter;
    u8 flags;
} ShdEffectRenderParams;

typedef struct ShdEffectParams {
    ShdFbuf framebuffer;
    ShdFarg arguments;
} ShdEffectParams;

extern void chkmemAllocSiteTag(const void *msg, s32 id);

extern u32 kwlnTaskGetWork(void *task);
extern void mdlEffectAdvanceAndFlushWithTable(void *a, void *b);
extern u32 mdlEffectGetWord84(s32 a);
extern void mdlEffectDestroy(u8 *a);
extern u8 *mdlEffectCreateFromResource(s32 a);
extern void kAssertFail(void *file, s32 line);
extern s32 effBlurFilterTaskUpdate(u8 *task);
extern void effBlurFilterTaskDestroy(u8 *task);
extern s32 shdEffectTaskUpdate(u8 *task);
extern void shdEffectTaskDestroy(u8 *task);

extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *ptr);
extern char D_00637290[];
extern char D_006372A0[];
extern char D_00763798;

// Intent: Create the blur-filter task; use the supplied filter handle or create one directly [inferred]
// FUN_0025FAB0
s32 shdEffectCreateBlurTask(s32 parentTask, s32 filterKind, s32 filterHandle, u8 *effect, void *renderContext)
{
    u8 *buf;

    chkmemAllocSiteTag(D_00637290, 0x46);
    buf = D_008873F4[0](1, 0x14, 0x40000);
    ((ShdBlurTaskWork *)buf)->state = 0;
    if (filterHandle != 0)
    {
        ((ShdBlurTaskWork *)buf)->filter = filterHandle;
    }
    else
    {
        ((ShdBlurTaskWork *)buf)->filter = (s32)effBlurFilterDirectCreate(filterKind & 0xFFFF, effect);
    }
    ((ShdBlurTaskWork *)buf)->renderParameter = ((ShdEffectRenderParams *)effect)->parameter;
    ((ShdBlurTaskWork *)buf)->renderContext = renderContext;
    return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)((u8 *)D_006372A0), 0xF, 0, 0, effBlurFilterTaskUpdate, effBlurFilterTaskDestroy, (u8 *)(buf));
}

// Intent: Fill a 0x24-byte frame-buffer parameter block (flag byte, four colours and two floats) into dst [inferred]
// FUN_0025FBB0
void shdEffectFillFbufParams(u8 *dst, u8 flags, u32 firstColor, u32 secondColor, u32 thirdColor, u32 fourthColor,
                   f32 firstValue, f32 secondValue)
{
    ShdFbuf parameters;
    s8 *clearCursor;
    s32 bytesLeft;
    u32 *source;
    u32 *output;
    s32 wordsLeft;
    u32 word;

    clearCursor = (s8 *)&parameters;
    bytesLeft = 0x24;
    if (clearCursor != 0)
    {
        do
        {
            *clearCursor = 0;
            clearCursor++;
            bytesLeft--;
        } while (bytesLeft != 0);
    }
    parameters.flags = flags;
    parameters.firstColor = ((firstColor >> 0x18) & 0xFF) | ((((firstColor >> 0x10) & 0xFF) << 8) |
             (((firstColor & 0xFF) << 0x18) | (((firstColor >> 8) & 0xFF) << 0x10)));
    parameters.secondColor = ((secondColor >> 0x18) & 0xFF) | ((((secondColor >> 0x10) & 0xFF) << 8) |
             (((secondColor & 0xFF) << 0x18) | (((secondColor >> 8) & 0xFF) << 0x10)));
    parameters.thirdColor = ((thirdColor >> 0x18) & 0xFF) | ((((thirdColor >> 0x10) & 0xFF) << 8) |
             (((thirdColor & 0xFF) << 0x18) | (((thirdColor >> 8) & 0xFF) << 0x10)));
    parameters.firstValue = firstValue;
    parameters.fourthColor = ((fourthColor >> 0x18) & 0xFF) | ((((fourthColor >> 0x10) & 0xFF) << 8) |
              (((fourthColor & 0xFF) << 0x18) | (((fourthColor >> 8) & 0xFF) << 0x10)));
    parameters.secondValue = secondValue;
    source = (u32 *)&parameters;
    output = (u32 *)dst;
    wordsLeft = 9;
    do
    {
        word = *source;
        source++;
        wordsLeft--;
        *output = word;
        output++;
    } while (wordsLeft > 0);
}

// Intent: Fill a 0x10-byte parameter block at dst+0x24 from an integer pair and two floats [inferred]
// FUN_0025FD00
void shdEffectSetFargParams(u8 *dst, s32 firstValue, s32 secondValue, f32 firstFloat, f32 secondFloat)
{
    ShdFarg parameters;
    s8 *clearCursor;
    s32 bytesLeft;

    clearCursor = (s8 *)&parameters;
    bytesLeft = 0x10;
    if (clearCursor != 0)
    {
        do
        {
            *clearCursor = 0;
            clearCursor++;
            bytesLeft--;
        } while (bytesLeft != 0);
    }
    parameters.firstValue = firstValue;
    parameters.secondValue = secondValue;
    parameters.firstFloat = firstFloat;
    parameters.secondFloat = secondFloat;
    ((ShdEffectParams *)dst)->arguments = parameters;
}

// Intent: Store a render parameter word and byte in the effect's fields [inferred]
// FUN_0025FD70
void shdEffectSetRenderParams(u8 *effect, s32 parameter, u8 flags)
{
    ((ShdEffectRenderParams *)effect)->parameter = parameter;
    ((ShdEffectRenderParams *)effect)->flags = flags;
}

// Intent: Effect task update: step the effect and return -1 once its counter reaches the limit [inferred]
// FUN_0025FD80
s32 shdEffectTaskUpdate(u8 *task)
{
    ShdTask *work;

    work = (void *)kwlnTaskGetWork(task);
    mdlEffectAdvanceAndFlushWithTable((void *)(u32)work->contextHandle, (void *)(u32)work->effectHandle);
    if (work->frameLimit != 0 && (s32)mdlEffectGetWord84(work->effectHandle) >= work->frameLimit)
    {
        return -1;
    }
    return 0;
}

// Intent: Effect task destroy: release the effect's resource and call the teardown handler [inferred]
// FUN_0025FE00
void shdEffectTaskDestroy(u8 *task)
{
    void *work;

    work = (void *)kwlnTaskGetWork(task);
    mdlEffectDestroy(*(u8 **)work);
    (*jtbl_008873EC)(work);
}

// Intent: Create the effect task from a resource handle, with the effect update and destroy callbacks [inferred]
// FUN_0025FE50
s32 shdEffectTaskCreate(s32 parentTask, s32 resource, s32 frameLimit, void *context)
{
    u8 *buf;

    if (resource == 0)
    {
        kAssertFail(D_00637290, 0xD7);
    }
    if (context == 0)
    {
        kAssertFail(D_00637290, 0xD8);
    }
    chkmemAllocSiteTag(D_00637290, 0xD9);
    buf = D_008873F4[0](1, 0xC, 0x40000);
    *(u8 **)buf = mdlEffectCreateFromResource(resource);
    ((ShdTask *)buf)->contextHandle = (s32)context;
    ((ShdTask *)buf)->frameLimit = frameLimit;
    return (s32)kwlnTaskCreateChild((void *)(u32)parentTask, &D_00763798,
                               0xF, 0, 0, shdEffectTaskUpdate, shdEffectTaskDestroy, buf);
}

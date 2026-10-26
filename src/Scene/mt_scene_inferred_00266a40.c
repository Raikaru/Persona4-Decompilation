#include "sdk_snd_internal.h"
#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "member_access.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
#include "primitive_queue_internal.h"
#include "scene_task_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *, s32, s32,
                           s32 (*)(u8 **arg0, u8 **arg1));
extern void chkmemAllocSiteTag(void *file, s32 line);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *memcpy(void *, const void *, u32);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;

extern void PrimDrawContour(f32 x, f32 y, f32 depth,
                          s32 rgb, s32 alpha, s32 unusedMode, s32 shape,
                          s32 originX, s32 originY,
                          f32 rotation, f32 scaleX, f32 scaleY);
extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);


extern u8 *kwlnTaskGetWork(void* task);
extern s32 kwlnTaskIsLinked();

extern s32 sdkSpritePackCreate(u8 *descriptor);
extern u8 D_00637420[];


extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(u8 *list, u8 *node);
extern void cldTimeChangeDraw(s32 unusedQueue, s32 task);

extern void sdkSpritePackDestroy(void *pack);
extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern void kAssertFail(void *file, s32 line);
extern s32 cldTimeChangeUpdate(u8 *task);
extern s32 sdkSndStopChannel(s32 fadeFrames);
extern void calSplitDayOfYear(s32 dateIndex, s32 *monthOut, s32 *dayOut);
extern s32 shdSpriteEnsureLoaded(u8 *pack);
extern u8 D_00638F90[];
extern void cldTimeChangeQueueDraw(s32 taskHandle, u8 *queue);
extern char D_00637348[];
extern s32 cldDayChangeRequest(u32 unused, s32 day);
extern void cldDayChangeMarkDone(u8 *task);
extern s32 cldDayChangeIsDone(s32 task);
extern f32 sinf(f32 fparg0);
extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity,
                           s32 weather, s32 highlight, f32 scaleX, f32 scaleY,
                           s32 clipLeft, s32 clipWidth, s32 font,
                           s32 forcedHighlight);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;

extern s32 calHasDayEntry(s32 day);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void mdlEffectEmitMaskedTagPair(void);
extern void PrimDrawFlatRectangle(void *colorData, void *rectangleData, f32 depth, s32 preserveState);
extern void mdlEffectEmitTagPair(void);
extern s32 shdSpriteEntryWidth(s32 entryId, s32 entryOffset, u8 *pack);

extern f32 D_007612C4;
/* Convert shape elapsed time to its 140-frame interpolation fraction. measured: retail calls this
 * as a helper in cldShapeListDraw; writing the division inline changes that function's code. */
static inline f32 mtSceneNormalizeShapeTime(f32 value)
{
    return value / 140.0f;
}

/* Locate the indexed scalar in the shape parameter table. */
static inline s32 *mtSceneShapeValueAt(s32 *values, s32 index)
{
    return values + index;
}
typedef struct { const PrimPoint *value[19]; } ContourSourceTable;
/* Select the point-pointer column of an interleaved outline table. measured: retail keeps this
 * lookup as a call, and expanding it inline changes PrimDrawContour register allocation. */
static inline const PrimPoint *const *contourOutlinePoints(const PrimPoint *const *sources, s32 shape)
{
    return sources + shape * 2 + 1;
}
typedef struct { s32 value[19]; } ContourCountTable;
typedef struct { u32 value[4]; } ContourChannels;
/* Read one component of the expanded contour color. measured: retail calls this helper for each
 * channel read, so the read is kept out of line instead of written as a direct array access. */
static inline u32 contourChannelValue(const ContourChannels *color, s32 component)
{
    return color->value[component];
}


/* Select the point-count column of an interleaved outline table. */
static inline const s32 *contourOutlineCount(const s32 *words, s32 shape)
{
    return words + shape * 2 + 1;
}
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: opt_loop_invariants hoists (u8)opacity out of the fade block into the stack spill
 * retail has. */
#pragma push
#pragma pop
/* Switch arms follow retail's jump-table order; locals with disjoint live ranges share one
 * variable, matching retail's register reuse across cases. */
#pragma push
#pragma pop
/* Request a different day by setting bit 0 and recording the requested day. */
// FUN_00266A40
s32 cldDayChangeRequest(u32 unused, s32 day) {
    u8 *work = kwlnTaskGetWork((void*)(unused));

    if (((CldDayChangeRequest *)work)->currentDay != day) {
        ((CldDayChangeRequest *)work)->flags |= 1;
        ((CldDayChangeRequest *)work)->requestedDay = day;
    }
    return 0;
}

/* Mark the linked day-change task complete by setting bit 1. */
// FUN_00266A90
void cldDayChangeMarkDone(u8 *task) {
    u8 *work;

    if (kwlnTaskIsLinked(task) != 0) {
        work = kwlnTaskGetWork((void*)(task));
        ((CldDayChangeRequest *)work)->flags |= 2;
    }
}

/* Report completion unless a live request remains pending without acknowledgement (bit 2). */
// FUN_00266AE0
s32 cldDayChangeIsDone(s32 task)
{
    u8 *work;
    s32 flags;

    if (kwlnTaskIsLinked() != 0) {
        work = kwlnTaskGetWork((void*)(task));
        flags = ((CldDayChangeRequest *)work)->flags;
        if ((flags & 1) && !(flags & 4)) {
            return 0;
        }
        if (((CldDayChangeRequest *)work)->state == 1) {
            return 1;
        }
        return 0;
    }
    return 1;
}

// FUN_00266B70
s32 mtSceneBuildSpriteTable(void) {
    return (s32)sdkSpritePackCreate(D_00637420);
}

/* Load the period-change sprites, wait for readiness, then animate for sixty frames. */
// FUN_00266BA0
s32 cldTimeChangeUpdate(u8 *task)
{
    s32 month;
    s32 day;
    u8 *work;
    s32 elapsedFrames;
    s32 state;

    work = kwlnTaskGetWork((void*)(task));
    calSplitDayOfYear(((CldTimeChangeWork *)work)->firstPeriod, &month, &day);
    state = ((CldTimeChangeWork *)work)->state;
    switch (state) {
    case 0:
        ((CldTimeChangeWork *)work)->sprites.handle = sdkSpritePackCreate(D_00638F90);
        ((CldTimeChangeWork *)work)->state = 1;
        break;
    case 1:
        if (shdSpriteEnsureLoaded((u8 *)((CldTimeChangeWork *)work)->sprites.handle) != 0) {
            ((CldTimeChangeWork *)work)->state = 2;
            ((CldTimeChangeWork *)work)->elapsedFrames = 0;
        }
        break;
    case 2:
        elapsedFrames = ((CldTimeChangeWork *)work)->elapsedFrames + 1;
        ((CldTimeChangeWork *)work)->elapsedFrames = elapsedFrames;
        if (elapsedFrames >= 0x3C) {
            ((CldTimeChangeWork *)work)->state = 3;
        }
        break;
    case 3:
    case 4:
        return -1;
    default:
        break;
    }
    cldTimeChangeQueueDraw((s32)task, (u8 *)((CldTimeChangeWork *)work)->drawQueue);
    return 0;
}

/* Draw the sixty-frame period transition: enter, swap labels, then slide and fade away. */
// FUN_00266CC0
void cldTimeChangeDraw(s32 unusedQueue, s32 task)
{
    extern s32 shdSpriteDrawNowEx(f32, f32, f32, s32, u8, s32, s32, u8 *, s32, s16, s16, f32, f32, f32);
    extern f32 sinf(f32);
    extern s16 datGetDateIndex(void);
    s32 firstPeriod;
    s32 secondPeriod;
    u8 *work;
    s32 elapsedFrames;
    s32 alpha;

    work = kwlnTaskGetWork((void*)(task));
    firstPeriod = *(s32 *)&((CldTimeChangeWork *)work)->firstPeriod;
    secondPeriod = *(s32 *)&((CldTimeChangeWork *)work)->secondPeriod;
    if (calHasDayEntry(datGetDateIndex()) != 0) {
        if (MEMBER(s32, work, CldTimeChangeWork, firstPeriod) == 3) {
            firstPeriod = 6;
        }
        if (MEMBER(s32, work, CldTimeChangeWork, secondPeriod) == 3) {
            secondPeriod = 6;
        }
    }
    switch (*(s32 *)work) {
    case 2:
        elapsedFrames = *(s32 *)&((CldTimeChangeWork *)work)->elapsedFrames;
        if (elapsedFrames < 15) {
            f32 sineAmount = sinf((fGpffff84a4 * (f32)elapsedFrames) / 15.0f);

            shdSpriteDrawNowEx(200.0f * (1.0f - sineAmount), 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)&((CldTimeChangeWork *)work)->sprites.pointer, 1, 0, 0, 0.0f, sineAmount, 1.0f);
            elapsedFrames = MEMBER(s32, work, CldTimeChangeWork, elapsedFrames);
            if (elapsedFrames > 10) {
                alpha = (u8)(255.0f * ((f32)(elapsedFrames - 10) / 5.0f));
                shdSpriteDrawNowEx(0.0f, 0.0f, 0.0f, 0, alpha, firstPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
        } else if (elapsedFrames < 20) {
            shdSpriteDrawNowEx(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)&((CldTimeChangeWork *)work)->sprites.pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            shdSpriteDrawNowEx(0.0f, 0.0f, 0.0f, 0, 0xFF, firstPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, 1.0f, 1.0f);
        } else if (elapsedFrames < 25) {
            f32 sineAmount = sinf((fGpffff84a4 * (f32)(elapsedFrames - 20)) / 5.0f);
            s32 spriteWidth = shdSpriteEntryWidth(0, 0, *(u8 **)&((CldTimeChangeWork *)work)->sprites.pointer);
            f32 remainingScale = 1.0f - sineAmount;

            shdSpriteDrawNowEx(((f32)spriteWidth / 2.0f) * sineAmount, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, remainingScale, 1.0f);
            spriteWidth = shdSpriteEntryWidth(firstPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer));
            shdSpriteDrawNowEx(((f32)spriteWidth / 2.0f) * sineAmount, 0.0f, 0.0f, 0, 0xFF, firstPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, remainingScale, 1.0f);
        } else if (elapsedFrames < 30) {
            f32 remainingScale;
            s32 spriteWidth;
            f32 sineAmount;

            sineAmount = 1.0f - sinf((fGpffff84a4 * (f32)(elapsedFrames - 25)) / 5.0f);
            spriteWidth = shdSpriteEntryWidth(0, 0, *(u8 **)&((CldTimeChangeWork *)work)->sprites.pointer);
            remainingScale = 1.0f - sineAmount;

            shdSpriteDrawNowEx(((f32)spriteWidth / 2.0f) * sineAmount, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, remainingScale, 1.0f);
            spriteWidth = shdSpriteEntryWidth(secondPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer));
            shdSpriteDrawNowEx(((f32)spriteWidth / 2.0f) * sineAmount, 0.0f, 0.0f, 0, 0xFF, secondPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, remainingScale, 1.0f);
        } else if (elapsedFrames < 40) {
            shdSpriteDrawNowEx(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0, 0, *(u8 **)&((CldTimeChangeWork *)work)->sprites.pointer, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            shdSpriteDrawNowEx(0.0f, 0.0f, 0.0f, 0, 0xFF, secondPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, 1.0f, 1.0f);
        } else if (elapsedFrames < 60) {
            f32 sineAmount = sinf((fGpffff84a4 * (f32)(elapsedFrames - 40)) / 20.0f);
            f32 remainingScale = 1.0f - sineAmount;

            alpha = (u8)(255.0f * remainingScale);
            shdSpriteDrawNowEx(-200.0f * sineAmount, 0.0f, 0.0f, 0xFFFFFF, alpha, 0, 0, *(u8 **)&((CldTimeChangeWork *)work)->sprites.pointer, 1, 0, 0, 0.0f, remainingScale, 1.0f);
            elapsedFrames = MEMBER(s32, work, CldTimeChangeWork, elapsedFrames);
            if (elapsedFrames < 45) {
                remainingScale = (f32)(elapsedFrames - 40) / 5.0f;
                alpha = (u8)(255.0f * (1.0f - remainingScale));
                shdSpriteDrawNowEx(0.0f, 0.0f, 0.0f, 0, alpha, secondPeriod + 1, 0, MEMBER(u8 *, work, CldTimeChangeWork, sprites.pointer), 1, 0, 0, 0.0f, 1.0f, 1.0f);
            }
        }
        break;
    }
}

/* Queue the period-transition draw callback with its task handle. */
// FUN_002674B0
void cldTimeChangeQueueDraw(s32 taskHandle, u8 *queue) {
    u8 *node;

    node = PrimAllocQueueNode();
    ((PrimQueueNode *)node)->callback = (void *)cldTimeChangeDraw;
    ((PrimQueueNode *)node)->argument.handle = taskHandle;
    PrimAppendNode(queue, node);
}

/* Destroy an allocated sprite pack before releasing the task work. */
// FUN_00267510
void mtSceneSpriteTableTaskDestroy(u8 *unusedTask) {
    u8 *work;
    s32 spriteHandle;

    work = kwlnTaskGetWork((void*)(unusedTask));
    spriteHandle = ((CldTimeChangeWork *)work)->sprites.handle;
    if (spriteHandle != 0) {
        sdkSpritePackDestroy((void *)spriteHandle);
    }
    jtbl_008873EC[0](work);
}

// Creates the cldTimeChange child task with its work block (cldTimeChange.c alloc site).
// FUN_00267570
s32 cldTimeChangeCreate(s32 parentTask, s32 firstPeriod, s32 secondPeriod, s32 drawQueue)
{
    u8 *work;
    s32 result;

    if (drawQueue == 0) {
        kAssertFail(D_00638FA0, 0xF2);
    }
    chkmemAllocSiteTag(D_00638FA0, 0xF3);
    work = D_008873F4[0](1, 0x18, 0x40000);
    ((CldTimeChangeWork *)work)->state = 0;
    ((CldTimeChangeWork *)work)->drawQueue = drawQueue;
    ((CldTimeChangeWork *)work)->firstPeriod = firstPeriod;
    ((CldTimeChangeWork *)work)->secondPeriod = secondPeriod;
    result = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_00638FB0), 0xF, 0, 0, cldTimeChangeUpdate, mtSceneSpriteTableTaskDestroy, (u8 *)((s32)work));
    sdkSndFadeOutChannel(3, 0);
    sdkSndStopChannel(0xA);
    return result;
}

/* Draw each shape, remove completed entries and grow the shared scale along a cubic curve. */
// FUN_00267670
void cldShapeListDraw(u8 **shapeWork)
{
    u8 *work;
    u8 *node;
    u8 *nextNode;
    f32 previousScale;
    f32 scaleFactor;
    u8 *list;
    f32 time;
    extern void comuDataRemoveAndReleaseNode(void *owner, void *source, void *nodeStorage);
    extern f32 D_00761514;
    extern f32 D_00761658;
    extern f32 D_0076165C;
    extern f32 D_00761260;
    extern s32 cldShapeDraw(u8 **shapeWork, u8 *entry);
    extern f32 MT_Scene_CubicBezier(f32 p0, f32 p1, f32 p2, f32 p3,
                              f32 t);

    work = (u8 *)shapeWork;
    *(s32 *)&((CldShapeWork *)work)->alpha = 0xFF;
    node = *(u8 **)&((CldShapeList *)*(u8 **)work)->head;
    goto loop_test;
loop_body:
    nextNode = *(u8 **)&((CldShapeNode *)node)->link0C;
    if (cldShapeDraw(shapeWork, *(u8 **)&((CldShapeNode *)node)->entry) != 0) {
        list = *(u8 **)work;
        comuDataRemoveAndReleaseNode(list, list + 4, node);
    }
    node = nextNode;
loop_test:
    if (node != NULL) {
        goto loop_body;
    }
    if ((*(f32 *)&((CldShapeWork *)work)->elapsed > 0.0f) ||
        (((CldShapeList *)*(u8 **)work)->count != 0)) {
        MEMBER(f32, work, CldShapeWork, elapsed) += 1.0f;
        if (*(f32 *)&((CldShapeWork *)work)->scale == 0.0f) {
            MEMBER(f32, work, CldShapeWork, scale) = D_00761514;
            return;
        }
        time = mtSceneNormalizeShapeTime(MEMBER(f32, work, CldShapeWork, elapsed));
        scaleFactor = MT_Scene_CubicBezier(D_00761658, D_00761658,
                               D_0076165C, D_00761260, time);
        previousScale = *(f32 *)&((CldShapeWork *)work)->scale;
        *(f32 *)&((CldShapeWork *)work)->scale = scaleFactor * previousScale + previousScale;
    }
}

/* measured: optimization_level 1 with the first two terms right-associated keeps retail's FPU term
 * and accumulator order. */
/* Evaluate a one-dimensional cubic Bezier curve with control values p0..p3 at parameter t. */
// FUN_002677A0
f32 MT_Scene_CubicBezier(f32 p0, f32 p1, f32 p2, f32 p3, f32 t) {
    f32 u;
    f32 k;
    f32 a;
    f32 b;
    f32 c;
    f32 d;

    u = 1.0f - t;
    k = 3.0f * u;
    a = t * (t * t);
    b = t * (k * t);
    c = u * (u * u);
    d = t * (k * u);
    return p0 * c + p1 * d + p2 * b + p3 * a;
}

/* measured: retail builds cldShapeDraw with common-subexpression elimination off. Whole table
 * objects are copied because renderer callbacks may change the item index. */
#pragma opt_common_subs off
/* Draw the indexed contour with depth and opacity derived from the transition scale. */
// FUN_00267800
s32 cldShapeDraw(u8 **shapeWork, u8 *entry)
{
    f32 position[4];
    Code1_00267800ShapeTable shapes;
    Code1_00267800ScaleTable scales;
    s32 alpha;
    s32 shape;
    f32 scale;
    f32 threshold;
    f32 renderScale;
    s32 *shapeSrc;
    s32 *shapeDst;
    u32 *scaleSrc;
    u32 *scaleDst;
    s32 count;

    memcpy(position, ((CldShapeEntry *)entry)->position, sizeof(position));
    position[2] += -136.0f + (150.0f * ((CldShapeWork *)shapeWork)->elapsed) / 120.0f;
    position[0] += 288.0f;
    position[1] += 222.0f;
    shapeSrc = D_00638FD0.value;
    shapeDst = shapes.value;
    count = 19;
    do {
        s32 value = *shapeSrc++;
        count--;
        *shapeDst++ = value;
    } while (count > 0);
    scaleSrc = D_00639020.words;
    scaleDst = scales.words;
    count = 19;
    do {
        u32 value = *scaleSrc++;
        count--;
        *scaleDst++ = value;
    } while (count > 0);
    alpha = 0xFF;
    scale = ((CldShapeWork *)shapeWork)->scale * scales.value[((CldShapeEntry *)entry)->tableIndex];
    position[3] = scale;
    if (scale < (threshold = fGpffff8218)) {
        alpha = (s32)((255.0f * scale) / threshold);
    }
    alpha = (s32)((f32)alpha * ((f32)((CldShapeWork *)shapeWork)->alpha / 255.0f));
    shape = *mtSceneShapeValueAt(shapes.value, ((CldShapeEntry *)entry)->tableIndex);
    if (shape != 9) {
        if (!(scale <= (fGpffff8218))) {
            renderScale = position[3];
            PrimDrawContour(position[0], position[1], 0.0f, 0x76BF48, alpha, 1, shape, 0, 0,
                           4.0f + position[2], renderScale, renderScale);
            renderScale = position[3];
            PrimDrawContour(position[0], position[1], 0.0f, 0x4883BF, alpha, 1, shapes.value[((CldShapeEntry *)entry)->tableIndex], 0, 0,
                           2.0f + position[2], renderScale, renderScale);
            renderScale = position[3];
            PrimDrawContour(position[0], position[1], 0.0f, 0xBF4848, alpha, 1, shapes.value[((CldShapeEntry *)entry)->tableIndex], 0, 0,
                           position[2] - 2.0f, renderScale, renderScale);
        }
        renderScale = position[3];
        PrimDrawContour(position[0], position[1], 0.0f, 0x292929, alpha, 1, shapes.value[((CldShapeEntry *)entry)->tableIndex], 0, 0,
                           position[2], renderScale, renderScale);
    }
    if (!(position[3] < 7.0f)) {
        return 1;
    }
    return 0;
}

/* measured: PrimDrawContour only reproduces retail's code at optimization level 2. */
#pragma optimization_level 2
// FUN_00267B20
/* measured: retail does not cache the special-contour origin, so propagation stays off. */
#pragma opt_propagation off
/* Draw contour fill, outline and closing edge; shape 9 takes the single-pass special path. */
void PrimDrawContour(f32 x, f32 y, f32 depth, s32 rgb, s32 alpha, s32 unusedMode, s32 shape, s32 originX, s32 originY,
                   f32 rotation, f32 scaleX, f32 scaleY)
{
    typedef signed __int128 ContourPacket;
    typedef union {
        struct { s32 x, y, width, height; } fields;
        ContourPacket packet;
    } ContourClip;
    typedef union {
        struct { u8 red, green, blue, alpha; } bytes;
        f32 transfer;
    } ContourColor;
    extern const ContourCountTable D_0063A9E0;
    extern const ContourSourceTable D_0063AA30;
    extern void shdDisableBlendFlag(void);
    ContourColor backdrop;
    ContourColor backdropScratch;
    PrimPoint points[257];
    u8 colors[256 * 4];
    ContourCountTable counts;
    ContourSourceTable sources;
    ContourClip clip;
    ContourClip clipScratch;
    ContourChannels channels;
    s32 specialPointIndex;
    s32 outlinePointIndex;
    s32 fillPointIndex;
    s32 closingPointIndex;
    s32 specialCount;
    s32 outlineCount;
    s32 fillCount;
    const PrimPoint *specialPoints;
    const PrimPoint *outlinePoints;
    const PrimPoint *fillPoints;
    const PrimPoint *closingPoints;
    u8 specialRed;
    u8 specialGreen;
    u8 specialBlue;
    u8 specialAlpha;
    u8 *clearCursor;
    s32 remainingBytes;
    s32 (**renderStates)(RwRenderState, void *);
    u32 combined;
    combined = ((u32)rgb << 8) | (u32)alpha;
    {
        const s32 *src = D_0063A9E0.value;
        s32 *dst = counts.value;
        s32 remaining = 19;
        do {
            s32 value = *src;
            src++;
            remaining--;
            *dst = value;
            dst++;
        } while (remaining > 0);
    }
    {
        const PrimPoint *const *src = D_0063AA30.value;
        const PrimPoint * *dst = sources.value;
        s32 remaining = 19;
        do {
            const PrimPoint * value = *src;
            src++;
            remaining--;
            *dst = value;
            dst++;
        } while (remaining > 0);
    }
    if (!(scaleX < 7.0f) || !(scaleY < 7.0f)) {
        return;
    }
    if (shape == 9) {
        specialCount = counts.value[shape * 2];
        specialPoints = sources.value[shape * 2];
        specialPointIndex = 0;
        specialRed = (combined >> 24) & 0xFF;
        specialGreen = (combined >> 16) & 0xFF;
        specialBlue = (combined >> 8) & 0xFF;
        specialAlpha = combined & 0xFF;
        while (specialPointIndex < specialCount) {
            const f32 *src9 = specialPoints[specialPointIndex].v;
            f32 *dst9 = &points[specialPointIndex].v[0];
            u8 *col9;
            dst9[0] = (x + src9[0]) - specialPoints[0].v[0];
            dst9[1] = (y + src9[1]) - specialPoints[0].v[1];
            col9 = &colors[specialPointIndex * 4];
            col9[0] = specialRed;
            col9[1] = specialGreen;
            col9[2] = specialBlue;
            col9[3] = specialAlpha;
            specialPointIndex++;
        }
        shdEnableBlendFlag();
        PrimDrawTransformed(colors, points, depth, specialCount, 5, 1, originX, originY, rotation, scaleX, scaleY);
        shdDisableBlendFlag();
        return;
    }
    clearCursor = (u8 *)&backdropScratch.transfer;
    remainingBytes = 4;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor++;
            remainingBytes--;
        } while (remainingBytes != 0);
    }
    backdrop.transfer = backdropScratch.transfer;
    clearCursor = (u8 *)&clipScratch.packet;
    remainingBytes = 0x10;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor++;
            remainingBytes--;
        } while (remainingBytes != 0);
    }
    clipScratch.fields.x = 0;
    clipScratch.fields.y = 0;
    clipScratch.fields.width = 0x280;
    clipScratch.fields.height = 0x1E0;
    clip.packet = clipScratch.packet;
    renderStates = D_00887300;
    renderStates[0]((RwRenderState)(0xE), (void *)(0));
    renderStates[0]((RwRenderState)(0xC), (void *)(1));
    renderStates[0]((RwRenderState)(7), (void *)(2));
    renderStates[0]((RwRenderState)(9), (void *)(2));
    renderStates[0]((RwRenderState)(0x14), (void *)(1));
    renderStates[0]((RwRenderState)(6), (void *)(0));
    renderStates[0]((RwRenderState)(8), (void *)(1));
    RpSkyRenderStateSet(3, (void *)(0x31003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawFlatRectangle(&backdrop.transfer, &clip.packet, 10.0f, 0);
    mdlEffectEmitTagPair();
    outlineCount = *contourOutlineCount(counts.value, shape);
    outlinePoints = *contourOutlinePoints(sources.value, shape);
    outlinePointIndex = 0;
    channels.value[0] = (combined >> 24) & 0xFF;
    channels.value[1] = (combined >> 16) & 0xFF;
    channels.value[2] = (combined >> 8) & 0xFF;
    channels.value[3] = combined & 0xFF;
    while (outlinePointIndex < outlineCount) {
        const f32 *srcA = outlinePoints[outlinePointIndex].v;
        f32 *dstA = &points[outlinePointIndex].v[0];
        u8 *colA;
        dstA[0] = (x + srcA[0]) - outlinePoints[0].v[0];
        dstA[1] = (y + srcA[1]) - outlinePoints[0].v[1];
        colA = &colors[outlinePointIndex * 4];
        colA[0] = ((&channels)->value[(0)]);
        colA[1] = ((&channels)->value[(1)]);
        colA[2] = (u8)((&channels)->value[(2)]);
        colA[3] = ((&channels)->value[(3)]);
        outlinePointIndex++;
    }
    shdEnableBlendFlag();
    renderStates = D_00887300;
    renderStates[0]((RwRenderState)(6), (void *)(0));
    renderStates[0]((RwRenderState)(8), (void *)(1));
    RpSkyRenderStateSet(3, (void *)(0x30003));
    RpSkyRenderStateSet(2, (void *)(0x44));
    mdlEffectEmitMaskedTagPair();
    PrimDrawTransformed(colors, points, depth, outlineCount, 5, 0, originX, originY, rotation, scaleX, scaleY);
    mdlEffectEmitTagPair();
    shdDisableBlendFlag();
    fillCount = counts.value[shape * 2];
    fillPoints = sources.value[shape * 2];
    fillPointIndex = 0;
    while (fillPointIndex < fillCount) {
        const f32 *srcB = fillPoints[fillPointIndex].v;
        f32 *dstB = &points[fillPointIndex].v[0];
        u8 *colB;
        dstB[0] = (x + srcB[0]) - fillPoints[0].v[0];
        dstB[1] = (y + srcB[1]) - fillPoints[0].v[1];
        colB = &colors[fillPointIndex * 4];
        colB[0] = ((&channels)->value[(0)]);
        colB[1] = ((&channels)->value[(1)]);
        colB[2] = (u8)((&channels)->value[(2)]);
        colB[3] = ((&channels)->value[(3)]);
        fillPointIndex++;
    }
    if (alpha == 0xFF) {
        shdEnableBlendFlag();
    }
    PrimDrawTransformed(colors, points, 1.0f + depth, fillCount, 5, 1, originX, originY, rotation, scaleX, scaleY);
    if (alpha == 0xFF) {
        shdDisableBlendFlag();
    }
    /* The closing pass walks the outline through its own cursor. */
    closingPoints = outlinePoints;
    closingPointIndex = 1;
    while (closingPointIndex < outlineCount) {
        const f32 *srcC = closingPoints[closingPointIndex].v;
        PrimPoint *dstC = ((points) + (closingPointIndex));
        u8 *colC;
        dstC[-1].v[0] = (x + srcC[0]) - closingPoints[0].v[0];
        dstC[-1].v[1] = (y + srcC[1]) - closingPoints[0].v[1];
        colC = ((colors) + (closingPointIndex) * 4);
        colC[-4] = contourChannelValue(&channels, 0);
        colC[-3] = contourChannelValue(&channels, 1);
        colC[-2] = (u8)contourChannelValue(&channels, 2);
        colC[-1] = ((&channels)->value[(3)]);
        closingPointIndex++;
    }
    if (alpha == 0xFF) {
        shdEnableBlendFlag();
    }
    {
        s32 drawX;
        s32 drawY;
        drawX = (s32)(s16)(s32)(x + ((f32)originX - points[0].v[0]));
        drawY = (s32)(s16)(s32)(y + ((f32)originY - points[0].v[1]));
        PrimDrawTransformed(colors, points, depth, outlineCount - 1, 4, 1, drawX, drawY, rotation, scaleX, scaleY);
    }
    if (alpha == 0xFF) {
        shdDisableBlendFlag();
    }
}


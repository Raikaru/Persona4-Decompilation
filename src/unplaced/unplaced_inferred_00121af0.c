/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00121af0-001223d0 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "calendar_fade_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern f32 fGpffff84a4;
extern u8 iGpffffb1d8;
extern u8 iGpffffb1d4;
extern u8 iGpffffb1d0;
extern f32 sinf();
extern void PrimDrawFlatRectangle(void *, void *, f32 , s32 );
extern void PrimDrawPoints(void *, void *, f32 , s32 ,
                          s32 , s32 );
extern f32 fGpffff8478;
extern f32 cosf(f32 );
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffb1cc;
extern s32 iGpffff9c58;
extern void fclBankTableReset(void);
extern s32 tickerInitBankTable(u8 *unusedTask);
/* The queue allocation is opaque beyond its callback and user-data fields. */
typedef struct FadeQueueNode {
    u8 pad0[8];
    void *callback;
    s32 unkC;
    s32 userData;
} FadeQueueNode;
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(char *list, u8 *node);
extern void fadeUpdateCallback(void *, u8 *);
extern char D_00796340[];
extern s16 clndGetPeriod(void);
extern s16 clndGetDaysSinceApr5(void);
extern void calendarSyncFromDate(void);
extern s32 cldDungeonInStart(s32 );
extern void fclBankTableInit(void);
/* Initialize the bank table from the ticker task callback. */
// FUN_00121AF0
s32 tickerInitBankTable(u8 *unusedTask)
{
    fclBankTableInit();
    return 0;
}

/* Reset the bank table and register its initializer task. */
// FUN_00121B20
void tickerStartTask(void) {
    fclBankTableReset();
    kwlnTaskCreate((const void *)(&iGpffff9c58), 0xF, 0, 0, tickerInitBankTable, 0, (u8 *)(0));
}

/* Step fade-in/out counters and wait for any calendar-change child task. */
// FUN_00121B70
/* Earlier whole-layout typing probe: CalendarFade access changed codegen (nd 306).; access-site and typed-local forms now match. */
s32 fadeTaskStep(u8 *unusedTask) {
    extern s32 calendarStartDayChange(s32 , s32 );
    extern s32 calendarStartTimeChange(s32 , s32 );
    extern s32 clndGetPeriod(void);
    extern s32 clndGetDaysSinceApr5(void);
    extern void calendarSyncFromDate(void);
    s32 previousDay;
    s32 previousPeriod;
    s32 currentDay;
    s32 nextCounter;
    s32 previousCounter;
    s32 currentPeriod;
    s32 duration;
    u32 state;
    u8 *fade;
    CalendarFade *fadeState;

    fade = (u8 *)iGpffffb1cc;
    fadeState = (CalendarFade *)(fade);
    state = ((CalendarFade *)fade)->state;
    switch (state) {
    case 0:
        ((CalendarFade *)fade)->changeRequested = 0;
        break;
    case 1:
        ((CalendarFade *)fade)->drawEnabled = 1;
        ((CalendarFade *)fade)->state = 2;
        break;
    case 2:
        ((CalendarFade *)fade)->drawEnabled = 1;
        nextCounter = ((CalendarFade *)fade)->counter + 1;
        ((CalendarFade *)fade)->counter = nextCounter;
        duration = ((CalendarFade *)fade)->duration;
        if (nextCounter >= duration) {
            fadeState->counter = duration;
            ((CalendarFade *)fade)->state = 3;
        }
        break;
    case 3:
        ((CalendarFade *)fade)->drawEnabled = 1;
        if (((CalendarFade *)fade)->changeRequested != 0) {
            ((CalendarFade *)fade)->state = 6;
        } else if ((((CalendarFade *)fade)->mode == 4) &&
                   (((CalendarFade *)fade)->specialRequested != 0)) {
            ((CalendarFade *)fade)->childTask = cldDungeonInStart(0);
            ((CalendarFade *)fade)->state = 7;
            fadeState->specialRequested = 0;
        }
        break;
    case 4:
        ((CalendarFade *)fade)->drawEnabled = 1;
        ((CalendarFade *)fade)->state = 5;
        break;
    case 5:
        ((CalendarFade *)fade)->drawEnabled = 1;
        previousCounter = ((CalendarFade *)fade)->counter - 1;
        ((CalendarFade *)fade)->counter = previousCounter;
        if (previousCounter <= 0) {
            fadeState->drawEnabled = 0;
            fadeState->counter = 0;
            ((CalendarFade *)fade)->state = 0;
        }
        break;
    case 6:
        previousDay = clndGetDaysSinceApr5();
        previousPeriod = clndGetPeriod();
        calendarSyncFromDate();
        currentDay = clndGetDaysSinceApr5();
        currentPeriod = clndGetPeriod();
        if (previousDay != currentDay) {
            ((CalendarFade *)fade)->childTask = calendarStartDayChange(previousDay, currentDay);
            ((CalendarFade *)fade)->state = 7;
        } else if (previousPeriod != currentPeriod) {
            ((CalendarFade *)fade)->childTask = calendarStartTimeChange(previousPeriod, currentPeriod);
            ((CalendarFade *)fade)->state = 7;
        } else {
            ((CalendarFade *)fade)->changeRequested = 0;
            ((CalendarFade *)fade)->state = 3;
        }
        break;
    case 7:
        if (kwlnTaskGetState(((CalendarFade *)fade)->childTask) == 3) {
            ((CalendarFade *)fade)->changeRequested = 0;
            ((CalendarFade *)fade)->state = 3;
        }
        break;
    }
    return 0;
}

/* Release the shared fade work allocation. */
// FUN_00121DB0
void fadeTaskDestroy(u8 *unusedTask)
{
    jtbl_008873EC[0]((void *)iGpffffb1cc);
    iGpffffb1cc = 0;
}

typedef struct {
    s32 x;
    s32 y;
    s32 width;
    s32 height;
    u8 pad10[0xC];
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FadeWipePacket;

/* Draw a 640-by-480 sine-eased horizontal wipe. */
// FUN_00121DE0
void fadeDrawWipe(void)
{
    extern f32 sinf(void *, f32 );
    FadeWipePacket rectangle;
    u8 *fade;
    s32 duration;
    s32 left;
    s32 right;
    f32 result;
    f32 leftEdge;
    f32 ratio;

    fade = (u8 *)iGpffffb1cc;
    if (fade != NULL) {
        duration = ((CalendarFade *)fade)->duration;
        if (((CalendarFade *)fade)->state >= 4) {
            ratio = (fGpffff84a4 * (f32)((CalendarFade *)fade)->counter) / (f32)duration;
            result = sinf(fade, ratio);
            leftEdge = 640.0f - (640.0f * result);
            left = (s32)leftEdge;
            right = 0x280;
        } else {
            left = 0;
            ratio = (fGpffff84a4 * (f32)((CalendarFade *)fade)->counter) / (f32)duration;
            result = sinf(fade, ratio);
            right = (s32)(640.0f * result);
        }
        rectangle.x = left;
        rectangle.y = 0;
        rectangle.width = right - left;
        rectangle.height = 0x1E0;
        rectangle.alpha = 0xFF;
        rectangle.red = iGpffffb1d8;
        rectangle.green = iGpffffb1d4;
        rectangle.blue = iGpffffb1d0;
        PrimDrawFlatRectangle(&rectangle.red, &rectangle.x, 0.0f, 1);
    }
}

/* Draw the radial fade mesh as 36 adjacent quadrilaterals. */
// FUN_00121F20
void fadeDrawMesh(void)
{
    typedef struct { f32 x, y; } FadePoint;
    typedef struct {
        FadePoint inner;
        FadePoint outer;
    } FadeSpoke;
    typedef struct {
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    } FadeColor;
    extern f32 sinf(f32 );
    FadeSpoke points[0x25];
    FadePoint quad[4];
    FadeColor color[4];
    u8 *fade;
    FadeSpoke *point;
    f32 result;
    f32 angle;
    f32 scale;
    f32 x;
    f32 sine;
    f32 cosine;
    s32 i;

    fade = (u8 *)iGpffffb1cc;
    if (fade != NULL) {
        color[0].alpha = 0xFF;
        color[0].red = iGpffffb1d8;
        color[0].green = iGpffffb1d4;
        color[0].blue = iGpffffb1d0;
        color[3] = color[0];
        color[2] = color[3];
        color[1] = color[2];
        result = sinf(
            (fGpffff84a4 * (f32)((CalendarFade *)fade)->counter) /
            (f32)((CalendarFade *)fade)->duration);
        scale = 600.0f - (600.0f * result);
        angle = 0.0f;
        i = 0;
        while (i < 0x25) {
            x = fGpffff8478 * angle;
            sine = cosf(x);
            cosine = sinf(x);
            point = &points[i];
            point->inner.x = ((scale * sine * 1066.0f) / 1000.0f) + 320.0f;
            point->inner.y = (scale * cosine) + 224.0f;
            point->outer.x = ((sine * 600.0f * 1066.0f) / 1000.0f) + 320.0f;
            point->outer.y = (cosine * 600.0f) + 224.0f;
            angle += 10.0f;
            i++;
        }
        i = 0;
        while (i < 0x24) {
            point = &points[i];
            quad[0] = point->inner;
            quad[1] = point->outer;
            quad[2] = point[1].inner;
            quad[3] = point[1].outer;
            PrimDrawPoints(color, quad, 0.0f, 4, 4, 1);
            i++;
        }
    }
}

/* Dispatch the active fade renderer while preserving the previous render state. */
// FUN_001221A0
/* measured: removing opt_propagation off, including a pointer-to-array base, rematerializes the dispatch base (358 differing bytes). */
#pragma opt_propagation off
void fadeUpdateCallback(void *unusedContext, u8 *fadeWork)
{
    typedef struct {
        s32 x;
        s32 y;
        s32 width;
        s32 height;
        u8 pad10[8];
        u8 red;
        u8 green;
        u8 blue;
        u8 alpha;
    } FadeRectanglePacket;
    extern s32 (*D_00887304[])(s32 unusedContext, void *fadeWork);
    extern void (*D_00887300[])(s32 unusedContext, s32 fadeWork);
    FadeRectanglePacket rectangle;
    void (**base)(s32 unusedContext, s32 fadeWork);
    s32 result;
    s32 state;
    s32 alpha;

    if ((((CalendarFade *)fadeWork)->drawEnabled & 1) != 0) {
        D_00887304[0](0xE, &result);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](7, 2);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](0xB, 6);
        base[0](0xA, 5);
        base[0](2, 4);
        base[0](0xE, 0);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        state = ((CalendarFade *)fadeWork)->mode;
        if (state == 3)
            goto state3;
        if (state == 2)
            goto state2;
        if (state == 4)
            goto draw;
        if (state == 1)
            goto draw;
        if (state == 0 || state != 0)
            goto done;
        goto done;
    draw:
        if (iGpffffb1cc != 0) {
            alpha = ((((CalendarFade *)iGpffffb1cc)->counter * 0xFF) /
                     ((CalendarFade *)iGpffffb1cc)->duration);
            rectangle.x = 0;
            rectangle.y = 0;
            rectangle.width = 0x280;
            rectangle.height = 0x1E0;
            rectangle.alpha = (u8)alpha;
            rectangle.red = iGpffffb1d8;
            rectangle.green = iGpffffb1d4;
            rectangle.blue = iGpffffb1d0;
            PrimDrawFlatRectangle(&rectangle.red, &rectangle.x, 0.0f, 1);
        }
        goto done;
    state2:
        fadeDrawWipe();
        goto done;
    state3:
        fadeDrawMesh();
    done:
        base[0](0xE, result);
    }
}

/* Queue the shared fade work for the render callback. */
// FUN_001223D0
s32 fadeQueueCallback(u8 *unusedTask) {
    u8 *p;
    s32 x;

    p = PrimAllocQueueNode();
    x = iGpffffb1cc;
    if (x == 0) {
        return 0;
    }
    ((FadeQueueNode *)p)->callback = (void *)fadeUpdateCallback;
    ((FadeQueueNode *)p)->userData = x;
    PrimAppendNode(D_00796340, p);
    return 0;
}

extern s32 RpSkyRenderStateSet(s32 , s32 );
extern void (*D_00887300[])(s32 , s32 );
extern s32 RpSkyRenderStateSet(s32 , s32 );
#include "btl_shuffle_draw_internal.h"

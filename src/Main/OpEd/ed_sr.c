#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit ed_sr.c (from __FILE__ assert strings). */
#include "type.h"
#include "member_access.h"
#include "scr_internal.h"
#include "ed_scroll_internal.h"
#include "kwln_task_internal.h"
#include "primitive_queue_internal.h"

/* GP-owned work record shared across the opening/ending TU. */
extern s32 *iGpffffb5b8;
extern u8 iGpffffa9f0;
extern u8 iGpffffa9f8;

/* Shared end-scene helpers (defined in sibling TUs of the same ed_* unit). */
extern void kAssertFail(void *file, s32 line);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void edScrollRelease(void);
extern void edSrStartPlayback(void);
extern void edSrOverlayDraw(void);
extern void edScrollStart(void);
extern u32 edScrollIsActive(void);
extern void edScrollStep(void);
extern void edScrollDrawLines(void);
extern void edResRelease(void);
extern void edResLoadStep(void);
extern void edResRequestLoad(void);
extern u32 edResIsPending(void);
extern void brpParamSetCurrent(u8 *work);
extern void edScrollWorkInit(u8 *work);

/* Window / effect / scripting helpers. */
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, void *node);
extern s32 datGetFlag(s32 bit);
extern s32 fadeStatus(void);
extern s32 fadeState(void);
extern void fadeBeginTransition(s32 mode, s32 duration);
extern s32 kwlnTaskGetTaskByName(void *name);
extern s32 kwlnTaskIsLinked(s32 target);
extern void kwlnTaskAddChild(void *parent, void *child);
extern s32 sdkSndPlayCue(s32 a, s32 b);
extern void sdkSndStopChannel(s32 fadeFrames);
extern s32 mwPlayerCreateReset(s32 parent, s64 movieIndex, void *queueName);
extern s32 mwPlayerGetCurrent(void);

/* Data / jumptable globals. */
extern char D_007964C0[];
extern char D_00796340[];
extern char D_0064F230[];
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Window callbacks (defined below in this file / in this TU). */


// Steps the end-scene state machine: wait for resources, start staff playback, then fade out once
// the scroll and player have both ended.
// FUN_0038EE40
void edSrStep(void) {
    EdSrWork *staffWork;
    s32 v;
    u8 *p;

    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    p = (u8 *)iGpffffb5b8;
    staffWork = (EdSrWork *)p;
    if (!(~*(s32 *)p & 1)) {
        v = ((EdSrWork *)p)->state;
        switch (v) {
        case 0:
            if (edResIsPending() == 0) {
                staffWork->state = 1;
            }
            break;
        case 1:
            edSrStartPlayback();
            break;
        case 2:
            ((EdSrWork *)p)->frame += 1;
            if (datGetFlag(0x1472) != 0) {
                if (mwPlayerGetCurrent() == 0xCC6) {
                    edScrollStart();
                }
            } else if (staffWork->frame == 1) {
                edScrollStart();
                sdkSndPlayCue(0x23, 1);
            }
            if ((edScrollIsActive() == 0) && (kwlnTaskIsLinked(((EdSrWork *)p)->playerTask) == 0)) {
                fadeBeginTransition(fadeState(), 0xA);
                staffWork->state = 3;
                if (datGetFlag(0x1472) == 0) {
                    sdkSndStopChannel(0x3C);
                }
            }
            break;
        case 3:
            if (fadeStatus() != 0) {
                *(s32 *)p &= ~1;
            }
            break;
        }
        edResLoadStep();
        edScrollStep();
    }
}

// Starts playback, creating the player when flag 0x1472 asks for it, and enters the fade-in state.
// FUN_0038F010
void edSrStartPlayback(void) {
    s32 *p;
    s16 v;

    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    p = iGpffffb5b8;
    if (datGetFlag(0x1472) != 0) {
        v = 0x11;
    } else {
        v = 0;
    }
    if (v != 0) {
        ((EdSrWork *)p)->playerTask = mwPlayerCreateReset(((EdSrWork *)p)->task, v, &D_00796340);
    }
    ((EdSrWork *)p)->frame = 0;
    ((EdSrWork *)p)->state = 2;
}

// Queued overlay draw: draws the scroll lines while the work is active.
// FUN_0038F0B0
void edSrOverlayDraw(void) {
    u8 *base;
    s32 previousFogState;

    D_00887304[0](0xE, &previousFogState);
    base = (u8 *)D_00887300;
    (*(void (**)(s32, s32))base)(0xE, 0);
    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    if (!(~*iGpffffb5b8 & 1)) {
        edScrollDrawLines();
    }
    (*(void (**)(s32, s32))base)(0xE, previousFogState);
}
#pragma opt_propagation on

// End-scene task update: steps the state machine and returns 0 while it is active.
// FUN_0038F160
s32 edSrTaskUpdate(u8 *unusedTask) {
    edSrStep();
    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    if (*iGpffffb5b8 & 1) {
        return 0;
    }
    return -1;
}

// Overlay task update: queues the overlay draw callback for this task.
// FUN_0038F1C0
s32 edSrOverlayTaskUpdate(u8 *task) {
    u8 *work;
    s32 v;

    v = *(s32 *)&((KwlnTask *)task)->work;
    work = PrimAllocQueueNode();
    *(s32 *)&((PrimQueueNode *)work)->callback = (s32)edSrOverlayDraw;
    ((PrimQueueNode *)work)->argument.handle = v;
    PrimAppendNode(&D_007964C0, work);
    return 0;
}

// End-scene task destroy: releases the scroll records and resource, then runs the teardown handler.
// FUN_0038F220
void edSrTaskDestroy(u8 *task) {
    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    edScrollRelease();
    edResRelease();
    jtbl_008873EC[0](*(void * *)&((KwlnTask *)task)->work);
}

// Common script command 0x6A, CALL_STAFF_ROLL (no params): creates the staff-roll work and task at
// command frame ten, then returns 1 once the task is gone.
// FUN_0038F290
s32 K_Cmd_CALL_STAFF_ROLL(void) {
    s32 state;
    u8 *w;
    u8 *p;
    s32 r;

    r = scrGetCmdTimer();
    if (r == 0xA) {
        chkmemAllocSiteTag(&iGpffffa9f0, 0x112);
        w = (u8 *)jtbl_008873E8[0](0x1258, 0x40000);
        state = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(&iGpffffa9f8), 0xF, 0, 0, edSrTaskUpdate, edSrTaskDestroy, (u8 *)(w));
        ((EdSrWork *)w)->overlayTask = (s32)kwlnTaskCreate((const void *)(&D_0064F230), 0x97, 1, 2, edSrOverlayTaskUpdate, 0, (u8 *)(0));
        kwlnTaskAddChild((void *)state, (void *)MEMBER(s32, w, EdSrWork, overlayTask));
        ((EdSrWork *)w)->flags = 0;
        brpParamSetCurrent(w + 0xC);
        edScrollWorkInit(w + 0x1C);
        ((EdSrWork *)w)->task = state;
        iGpffffb5b8 = (s32 *)w;
        if (w == NULL) {
            kAssertFail(&iGpffffa9f0, 0x64);
        }
        p = (u8 *)iGpffffb5b8;
        edResRequestLoad();
        ((EdSrWork *)p)->state = 0;
        *(s32 *)p |= 1;
    } else if ((r > 0xA) && (kwlnTaskGetTaskByName(&iGpffffa9f8) == 0)) {
        return 1;
    }
    return 0;
}

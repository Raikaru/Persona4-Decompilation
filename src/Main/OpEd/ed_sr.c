#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit ed_sr.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
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



// Intent: Step the end-scene state machine: wait, start playback, fade out and finish [inferred]
// FUN_0038EE40
/* Typed staff-roll members change b210 address materialization; retain byte/word
 * accesses to ed_scroll_internal.h layouts to keep the retail instructions. */
void edSrStep(void) {
    s32 v;
    u8 *p;

    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    p = (u8 *)iGpffffb5b8;
    if (!(~*(s32 *)p & 1)) {
        v = *(s32 *)(p + 0x124C);
        switch (v) {
        case 0:
            if (edResIsPending() == 0) {
                *(s32 *)(p + 0x124C) = 1;
            }
            break;
        case 1:
            edSrStartPlayback();
            break;
        case 2:
            *(s32 *)(p + 0x1254) += 1;
            if (datGetFlag(0x1472) != 0) {
                if (mwPlayerGetCurrent() == 0xCC6) {
                    edScrollStart();
                }
            } else if (*(s32 *)(p + 0x1254) == 1) {
                edScrollStart();
                sdkSndPlayCue(0x23, 1);
            }
            if ((edScrollIsActive() == 0) && (kwlnTaskIsLinked(*(s32 *)(p + 0x1250)) == 0)) {
                fadeBeginTransition(fadeState(), 0xA);
                *(s32 *)(p + 0x124C) = 3;
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

// Intent: Start playback: create the player when the flag asks for it and enter the fade-in state [inferred]
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

// Intent: Queued overlay draw: draw the scroll lines while the work is active [inferred]
// FUN_0038F0B0
/* measured: typed D_00887300 base local with opt_propagation off keeps
   retail's single lui/addiu hoist into $16 (same fix as cmpMain func_0012cd90). */
#pragma opt_propagation off
void edSrOverlayDraw(void) {
    void (**base)(s32, s32);
    s32 previousFogState;

    D_00887304[0](0xE, &previousFogState);
    base = D_00887300;
    base[0](0xE, 0);
    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    if (!(~*iGpffffb5b8 & 1)) {
        edScrollDrawLines();
    }
    base[0](0xE, previousFogState);
}
#pragma opt_propagation on

// Intent: End-scene task update: step the state machine and return 0 while it is active [inferred]
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

// Intent: Overlay task update: queue the overlay draw callback for this task [inferred]
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

// Intent: End-scene task destroy: release the scroll records and the resource, then run the teardown handler [inferred]
// FUN_0038F220
void edSrTaskDestroy(u8 *task) {
    if (iGpffffb5b8 == NULL) {
        kAssertFail(&iGpffffa9f0, 0x64);
    }
    edScrollRelease();
    edResRelease();
    jtbl_008873EC[0](*(void * *)&((KwlnTask *)task)->work);
}

// Intent: Common script command 0x6A, CALL_STAFF_ROLL (0 params): starts the end-credits scene; returns 1 once the command timer is past 0xA and the task is gone.
// Index: Common table group 0 base 0x63D070; entry 0x63D3C0 = (0x63D3C0 - 0x63D070) / 8 = 0x6A.
// Library: p4flow Common.json 0x006A = CALL_STAFF_ROLL.
// FUN_0038F290
/* Typed staff-roll members change b210 address materialization; retain byte/word
 * accesses to ed_scroll_internal.h layouts to keep the retail instructions. */
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
        *(s32 *)(w + 8) = (s32)kwlnTaskCreate((const void *)(&D_0064F230), 0x97, 1, 2, edSrOverlayTaskUpdate, 0, (u8 *)(0));
        kwlnTaskAddChild((void *)state, (void *)*(s32 *)(w + 8));
        *(s32 *)(w + 0) = 0;
        brpParamSetCurrent(w + 0xC);
        edScrollWorkInit(w + 0x1C);
        *(s32 *)(w + 4) = state;
        iGpffffb5b8 = (s32 *)w;
        if (w == NULL) {
            kAssertFail(&iGpffffa9f0, 0x64);
        }
        p = (u8 *)iGpffffb5b8;
        edResRequestLoad();
        *(s32 *)(p + 0x124C) = 0;
        *(s32 *)p |= 1;
    } else if ((r > 0xA) && (kwlnTaskGetTaskByName(&iGpffffa9f8) == 0)) {
        return 1;
    }
    return 0;
}

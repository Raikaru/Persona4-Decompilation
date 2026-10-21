#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
#include "name_entry_internal.h"
#include "kwln_task_internal.h"
#include "primitive_queue_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

extern u8 D_0063E918[];

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];

extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, void *node);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern void yTimeLimitDrawCallback(u8 *);
extern f32 fGpffff8204;
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                         s32, f32 farg0, s32, s32, s32);
extern u8 D_007485D0[];
extern s32 iGpffffb530;

extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;


struct RwMatrixTag;
extern void sflDataDrawQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s32 centerX, s16 centerY,
                          const struct RwMatrixTag *matrix, void *queue);
extern f32 fGpffff855c;
extern u8 D_0063EDF0[];
extern u8 D_0063EDF8[];
extern u8 D_0063EE00[];
extern u8 D_0063EE08[];
extern u8 D_0063EE10[];
extern u8 D_0063EE18[];
extern u8 D_0063EE20[];
extern u8 D_0063EE28[];
extern u8 D_0063EE30[];
extern u8 D_0063EE38[];
extern u8 D_00882F28[];
extern u8 D_00882F2C[];
typedef signed __int128 s128;
extern s32 (*D_0063E8C0[])(u8 *, s32);
extern s128 D_0063E8D0;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 *iGpffffb540;
extern u8 iGpffffa7e8;
extern void datSetHeroNameParts(u8 *firstName, u8 *lastName);
extern void fadeBeginTransition(s32 mode, s32 duration);
extern void fadeBeginReturnTransition(s32 mode, s32 duration);
extern void yTimeLimitStartRowTransition(u8 *task, s32 mode);
extern void yTimeLimitUpdateInput(u8 *task);
extern void yTimeNameDrawReveal(u8 *task, s32 stage);
extern s32 strncmp(void *, void *, s32);


extern void yTimeNameDrawKeyboard(u8 *task);


/* Existing task-work layout. The tween fields are defined by 002a27c0;
 * 0029fbb0 uses the selection pairs, status halfwords and flash flags.
 * State preceding the background tween is outside this renderer's view. */


#pragma push

extern s32 yTimeNameConfirm(u8 *task);
#pragma pop
extern s32 yTimeNameRevealRows(u8 *task);

/* Per-frame task update: queues a draw node (yTimeLimitDrawCallback) while the track is active and
 * returns -1 once the track is done. */
// FUN_002A1F20
s32 yTimeLimitTaskUpdate(u8 *task) {
    u8 *drawNode;

    if (((NameEntryWork *)((KwlnTask *)task)->work)->phase != 3) {
        drawNode = PrimAllocQueueNode();
        ((PrimQueueNode *)drawNode)->callback = yTimeLimitDrawCallback;
        ((PrimQueueNode *)drawNode)->argument.data = task;
        PrimAppendNode(D_00795E60, drawNode);
        goto success;
    }
    return -1;
success:
    return 0;
}

/* measured: loop-invariant motion hoists the case-zero store constant above the loop entry, as
 * retail does. */
#pragma opt_loop_invariants on
// Draws the time-limit overlay: background rectangle, then the state machine that paints each
// track.
// FUN_002A1FA0
s32 yTimeLimitDraw(u8 *task) {

    u8 colors[4];
    s128 rectangle;
    f32 *rectangleBounds;
    s32 transitionStep;
    s32 inputState;
    s32 answer;
    s32 nextInputState;
    s32 exitFrame;
    s32 phase;
    s32 firstNameOffset;
    s32 lastNameOffset;
    s32 slotIndex;
    NameEntryWork *work;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    rectangleBounds = (f32 *)&rectangle;
    rectangle = D_0063E8D0;
    if (iGpffffb540 == 0) {
        return 0;
    }
    colors[0] = 0;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    PrimDrawFlatRectangle(colors, rectangleBounds, 0.0f, 1);
    phase = work->phase;
    switch (phase) {
    case 0:
        fadeBeginReturnTransition(1, 1);
        slotIndex = 0;
        for (; slotIndex < 6; slotIndex++) {
            work->selectionStatus[slotIndex][0] = 3;
            work->selectionStatus[slotIndex][1] = 0;
        }
        work->unk00 = 0;
        work->inputState = 0;
        work->phase = 1;
        goto block_39;
    case 1:
        transitionStep = work->transitionStep;
        if ((transitionStep < 3) && (D_0063E8C0[transitionStep](task, phase) == 1)) {
            work->transitionStep = work->transitionStep + 1;
        }
        yTimeNameDrawReveal(task, work->transitionStep);
        if (work->transitionStep >= 3) {
            work->transitionStep = 0;
            work->transitionStarted = 0;
            work->frame = 0;
            work->inputState = 1;
            work->phase = 2;
            work->selectionState[1] = 0;
            yTimeLimitStartRowTransition(task, 0);
        }
        goto block_39;
    case 2:
        inputState = work->inputState;
        if (inputState == 1) {
            yTimeLimitUpdateInput(task);
            nextInputState = work->inputState;
            if ((nextInputState != 2) && (nextInputState == 3)) {
                work->transitionStarted = 0;
                work->messageStep = 0;
            }
            goto block_37;
        }
        if (inputState == 3) {
            if (work->transitionStarted == 0) {
                answer = yTimeNameConfirm(task);
                if (answer == 0) {
                    firstNameOffset = 0xE;
                    goto loop_25_cond;
loop_25_body:
                    ((s8 *)D_00882EF0)[firstNameOffset] = 0;
                    ((s8 *)D_00882EF0)[firstNameOffset + 1] = 0;
                    firstNameOffset -= 2;
                    if (firstNameOffset < 0) {
                        goto loop_28_init;
                    }
loop_25_cond:
                    if (strncmp(&iGpffffa7e8,
                                      D_00882EF0 + firstNameOffset, 2) == 0) {
                        goto loop_25_body;
                    }
loop_28_init:
                    lastNameOffset = 0xE;
                    goto loop_28_cond;
loop_28_body:
                    ((s8 *)D_00882ED0)[lastNameOffset] = 0;
                    ((s8 *)D_00882ED0)[lastNameOffset + 1] = 0;
                    lastNameOffset -= 2;
                    if (lastNameOffset < 0) {
                        goto clear_done;
                    }
loop_28_cond:
                    if (strncmp(&iGpffffa7e8,
                                      D_00882ED0 + lastNameOffset, 2) == 0) {
                        goto loop_28_body;
                    }
clear_done:
                    datSetHeroNameParts(D_00882EF0, D_00882ED0);
                    work->frame = 0;
                    work->transitionStarted = 1;
                } else if (answer == 1) {
                    work->inputState = 1;
                }
                goto block_37;
            }
            if (work->frame == 0) {
                fadeBeginTransition(1, 0x1E);
            }
            exitFrame = work->frame;
            if (exitFrame >= 0x1E) {
                work->frame = 0;
                work->phase = 3;
                goto block_39;
            }
            work->frame = exitFrame + 1;
        }
block_37:
        yTimeNameDrawKeyboard(task);
        goto block_39;
    case 3:
        return -1;
    default:
        goto block_39;
    }
block_39:
    return 0;
}

/* Destructor for the time-limit task; frees its work block through the free table. */
// FUN_002A2310
void yTimeLimitTaskDestroy(u8 *task) {
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}


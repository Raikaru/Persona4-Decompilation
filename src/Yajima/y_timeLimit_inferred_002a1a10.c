#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
#include "name_entry_internal.h"
#include "kwln_task_internal.h"

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
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern f32 fGpffff8204;
extern u8 yTimeTrackClear(s32 track);
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                         s32, f32 farg0, s32, s32, s32);
extern void yTimeTrackAdvance(u8 *track);
extern s32 yTimeTrackIsNotDone(u8 *track);
extern s32 yTimeTrackIsIdle(u8 *track);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
extern u8 nmMesWindowOpenCurrent(u8 *message);
extern void nmMesWindowShowCurrentRecord(s32 recordIndex);
extern void nmMesWindowSetCurrentParam(s32 recordIndex);
extern void nmMesWindowSetCurrentFlag(s32 cursor);
extern s32 nmMesWindowCurrentAnim(void);
extern void nmMesWindowResetCurrent(void);
extern s32 nmMesWindowCurrentOpenState(void);

extern s32 nmMesWindowLatchAnimAux(void);
extern void nmMesWindowStepCurrentRelease(void);
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

#pragma push
#pragma pop
/* Run the name-confirmation message window step by step: open it, wait for the player to close it,
 * then reset it. Return the chosen answer once finished, or -1 while still in progress. */
// FUN_002A1A10
/* Run the name confirmation message; return -1 while open, then return the latched answer. */
s32 yTimeNameConfirm(u8 *task) {
    s32 messageStep;
    NameEntryWork *work;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    messageStep = work->messageStep;
    switch (messageStep) {
    case 0:
        iGpffffb52c = 0;
        nmMesWindowResetCurrent();
        nmMesWindowOpenCurrent((u8 *)(D_0063E630));
        nmMesWindowShowCurrentRecord(1);
        nmMesWindowSetCurrentParam(0);
        nmMesWindowSetCurrentFlag(0);
        work->messageStep = 1;
        goto done;
    case 1:
        if (nmMesWindowCurrentOpenState() != 0) {
            nmMesWindowStepCurrentRelease();
            if (nmMesWindowLatchAnimAux() == 0) {
                iGpffffb52c = nmMesWindowCurrentAnim();
            }
        } else {
            work->messageStep = 2;
        }
        goto done;
    case 2:
        nmMesWindowResetCurrent();
        work->messageStep = 0;
        return iGpffffb52c;
    default:
        goto done;
    }
done:
    return -1;
}

/* measured: disabling common-subexpression propagation stops the repeated tween target from being
 * held in a saved register across calls. */
#pragma opt_common_subs off
/* measured: disabling propagation preserves the retail call-site materialization. */
/* Fade in the name-entry background track the first time this is called, then advance it each
 * frame. Return 1 once the tween finishes, otherwise 0. */
// FUN_002A1B20
/* Start and advance the background reveal tween; report completion to the draw-state dispatcher. */
s32 yTimeNameRevealBackground(u8 *task) {
    NameEntryWork *work;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    if (work->transitionStarted == 0) {
        yTimeTrackClear((s32)((u8 *)&work->background));
        yTimeTrackAppendKey((s32)((u8 *)&work->background), 0, 0, 0, 0, fGpffff8204, 0, 10, 20);
        work->transitionStarted = 1;
    }
    yTimeTrackAdvance((u8 *)&work->background);
    if (yTimeTrackIsNotDone((u8 *)&work->background) != 0) {
        goto fail;
    }
    work->transitionStarted = 0;
    return 1;
fail:
    return 0;
}

/* measured: retail rematerializes call-site values instead of propagating them, so propagation
 * stays off for this function. */
#pragma opt_propagation off
/* Start the tween that slides the row origin into place, then advance it each frame. Return 1 once
 * it finishes, otherwise 0. */
// FUN_002A1BD0
/* Slide the keyboard row origin from Y=249 to Y=219 over ten frames. */
s32 yTimeNameRevealOrigin(u8 *task) {
    NameEntryWork *work;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    if (work->transitionStarted == 0) {
        yTimeTrackClear((s32)((u8 *)&work->rowOrigin));
        {
            s32 target;
            s32 value;

            target = (s32)((u8 *)&work->rowOrigin);
            value = 18;
            yTimeTrackAppendKey(target, value, 249, value, 219, fGpffff8204, 0, 0, 10);
        }
        work->transitionStarted = 1;
    }
    yTimeTrackAdvance((u8 *)&work->rowOrigin);
    if (yTimeTrackIsNotDone((u8 *)&work->rowOrigin) != 0) {
        goto fail;
    }
    work->transitionStarted = 0;
    return 1;
fail:
    return 0;
}

/* measured: retail keeps ordinary loop branches, recomputes index arithmetic per use, and reloads
 * global counters. */
/* Stagger the reveal of the name-entry grid, starting one row and its four column cells every six
 * frames, and advance all active cell and row tweens. Return 1 once all six rows have finished,
 * otherwise 0. */
// FUN_002A1C80
/* Stagger the four keyboard columns by row, advance their fades, and finish when all six rows settle. */
s32 yTimeNameRevealRows(u8 *task) {
    s32 columnIndex;
    s32 cellIndex;
    s32 finishedRows;
    s32 rowIndex;
    NameEntryWork *work;
    u8 *newCellTween;
    u8 *cellTween;
    u8 *rowTween;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    if (work->transitionStarted == 0) {
        iGpffffb530 = 0;
        work->transitionStarted = 1;
    }
    if ((iGpffffb530 < 6) && ((work->frame % 6) == 0)) {
        columnIndex = 0;
        while (columnIndex < 4) {
            newCellTween = (u8 *)&work->cells[iGpffffb530 + (columnIndex * 6)];
            yTimeTrackClear((s32)newCellTween);
            yTimeTrackAppendKey((s32)newCellTween, 0, 0, 0, 0, fGpffff8204, 0, 0, 6);
            columnIndex++;
        }
        yTimeTrackAppendKey((s32)((u8 *)&work->rows[iGpffffb530]),
                      0, -2, 0, 0, fGpffff8204, 0, 0, 12);
        iGpffffb530++;
    }
    cellIndex = 0;
    while (cellIndex < 24) {
        cellTween = (u8 *)&work->cells[cellIndex];
        if (yTimeTrackIsIdle(cellTween) == 0) {
            yTimeTrackAdvance(cellTween);
        }
        cellIndex++;
    }
    finishedRows = 0;
    rowIndex = 0;
    while (rowIndex < 6) {
        if (yTimeTrackIsIdle((u8 *)&work->rows[rowIndex]) == 0) {
            rowTween = (u8 *)&work->rows[rowIndex];
            yTimeTrackAdvance(rowTween);
            if (yTimeTrackIsNotDone(rowTween) == 0) {
                finishedRows++;
            }
        }
        rowIndex++;
    }
    if (finishedRows == 6) {
        work->transitionStarted = 0;
        work->frame = 0;
        return 1;
    }
    work->frame += 1;
    return 0;
}


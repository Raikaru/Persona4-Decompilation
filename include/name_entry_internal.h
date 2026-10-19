#ifndef NAME_ENTRY_INTERNAL_H
#define NAME_ENTRY_INTERNAL_H

#include "type.h"

/* Four 0x20-byte keys followed by the counters used by yTimeTrackAdvance.
 * A positive rate decays the remaining distance, zero uses a linear step,
 * and a negative rate selects the sine interpolation path. */
typedef struct NameTweenEntry {
    f32 startX, startY;
    f32 endX, endY;
    f32 stepX, stepY;
    f32 rate;
    s8 delay, hold;
    s16 duration;
} NameTweenEntry;

typedef struct NameTweenState {
    NameTweenEntry entries[4];
    s32 current, count, frame;
    u32 flags; /* bit 0: active; bit 1: finished */
    s32 timer, total;
} NameTweenState;

typedef struct NameEntrySelectionTweens {
    NameTweenState slide, pulse;
} NameEntrySelectionTweens;

/* Existing 0x1C6C-byte name-entry task work. The renderer and its transition
 * callbacks establish the tween arrays, six selection records and phases. */
typedef struct NameEntryWork {
    s32 unk00;
    s32 phase;
    s32 transitionStarted;
    s32 transitionStep;
    s32 messageStep;
    s32 inputState;
    s32 frame;
    s32 cursorColumn;
    s32 cursorRow;
    s32 cellIndex;
    u8 pad28[8];
    s32 previousCellIndex;
    u8 pad34[8];
    s32 changedCellIndex;
    u8 pad40[0x138];
    NameTweenState background;
    NameTweenState rowOrigin;
    NameTweenState modeTransition;
    NameTweenState cells[24];
    NameTweenState rows[6];
    NameEntrySelectionTweens selection[6];
    s32 selectionState[2];
    s16 selectionStatus[6][2];
    s32 selectionFlash[6];
    s32 backgroundFrame;
} NameEntryWork;

typedef char NameTweenEntrySize[(sizeof(NameTweenEntry) == 0x20) ? 1 : -1];
typedef char NameTweenStateSize[(sizeof(NameTweenState) == 0x98) ? 1 : -1];
typedef char NameEntryWorkSize[(sizeof(NameEntryWork) == 0x1C6C) ? 1 : -1];

#endif

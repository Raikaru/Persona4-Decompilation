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
extern f32 yTimeTrackProgress(u8 *track);
extern s32 yTimeTrackCurrentKey(u8 *track, f32 *output);
extern void sdkSpriteDrawNowUnscaled(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void * pack, s32 setStates);
extern s32 sdkSpriteDrawNow(f32 x, f32 y, f32 depth, s32 rgb, u8 alpha, s32 recordIndex, void * pack, s32 setStates, s16 pivotX, s16 pivotY, f32 angle, f32 scaleX, f32 scaleY);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002a; members 002a03b0-002a03b0 */

extern void yTimeNameDrawSelections(u8 *task, s32 preserveStatus);
/* 3888/3888 bytes. Keep the remaining-alpha accumulator separate from
 * the narrowed active alpha, and apply each cursor offset before drawing. */
/* Draw the interactive name-entry keyboard, selection fades, cursor and the two eight-character name buffers. */
// FUN_002A03B0
void yTimeNameDrawKeyboard(u8 *task) {
    KwlnTask *owner = (KwlnTask *)task;
    NameEntryWork *entry;
    extern u8 iGpffffb528[4];
    extern s32 iGpffffb538;
    extern s32 yTimeLimitDrawIdlePulse(u8 *task);
    extern u32 strlen(const void *task);
    extern void strncpy(void *task, const void *, s32);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s32 chr, s32 id, void *str, s32 flags, s32 unused);
    f32 pos[2];
    f32 px;
    f32 py;
    f32 labelX;
    f32 cellX;
    f32 cellY;
    f32 glyphX;
    f32 cursorX;
    s32 selectedCell;
    u8 cellAlpha;
    f32 cellProgress;
    f32 cursorY;
    f32 cursorOfs = -12.0f;
    s32 previousCell;
    s32 changedCell;
    s32 backgroundFrame;
    s32 selectionState;
    s32 nameCursor;
    s32 cursorColumn;
    s32 cursorRow;
    s32 cursorGroup;
    s32 glyphGroup;
    u8 transitionAlpha;
    u8 inactiveAlpha;
    s32 cellIndex;
    u8 activeAlpha;
    s32 glyphRow;
    s32 glyphColumn;
    s32 nameCursorX;
    s32 nameCursorY;
    u32 firstNameLength;
    u32 lastNameLength;
    u32 firstNameIndex;
    s32 firstNameX;
    u32 lastNameIndex;
    s32 lastNameX;
    u8 *inputWork;
    u8 *work;
    u8 *changedTween;
    u8 *cellTween;
    s32 sum;
    u8 *rowBase;
    s32 yBase;
    s32 glyph;
    s32 spriteIndex;

    work = ((KwlnTask *)task)->work;
    entry = (NameEntryWork *)work;
    sdkSpriteDrawNowUnscaled(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xA4, iGpffffb540, 1);
    backgroundFrame = ((NameEntryWork *)work)->backgroundFrame + 1;
    ((NameEntryWork *)work)->backgroundFrame = backgroundFrame;
    if (backgroundFrame > 0x5A0) {
        entry->backgroundFrame = 0;
    }
    sdkSpriteDrawNow(-78.0f, -82.0f, 0.0f, 0x4972FF, 0xFF, 0xB1, iGpffffb540, 1, 0x5B, 0x5B, (f32)(entry->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
    sdkSpriteDrawNow(540.0f, 347.0f, 0.0f, 0x4972FF, 0xFF, 0xB1, iGpffffb540, 1, 0x5B, 0x5B, (f32)(entry->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
    sdkSpriteDrawNowUnscaled(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1);
    sdkSpriteDrawNowUnscaled(0.0f, 346.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1);
    yTimeTrackAdvance((u8 *)&((NameEntryWork *)work)->modeTransition);
    transitionAlpha = (u8)(255.0f * yTimeTrackProgress((u8 *)&entry->modeTransition));
    yTimeTrackCurrentKey((u8 *)&entry->modeTransition, pos);
    px = pos[0];
    py = pos[1];
    selectionState = ((NameEntryWork *)work)->selectionState[1];
    if (selectionState == 0) {
        inactiveAlpha = transitionAlpha & 0xFF;
        activeAlpha = 0;
    } else if (selectionState == 1) {
        s32 remaining = 0xFF;
        activeAlpha = transitionAlpha & 0xFF;
        remaining -= activeAlpha;
        inactiveAlpha = (remaining >> 2) & 0xFF;
    } else if (selectionState == 2) {
        inactiveAlpha = transitionAlpha & 0xFF;
        activeAlpha = ((0xFF - inactiveAlpha) >> 2) & 0xFF;
    }
    sdkSpriteDrawNowUnscaled(px, py, 0.0f, 0xFFFFFF, inactiveAlpha, 0x13, iGpffffb540, 1);
    labelX = 105.0f + px;
    sdkSpriteDrawNowUnscaled(labelX, py, 0.0f, 0xFFFFFF, inactiveAlpha, 0x11, iGpffffb540, 1);
    py = py + 3.0f;
    sdkSpriteDrawNowUnscaled(px, py, 0.0f, 0xFFFFFF, activeAlpha, 0x13, iGpffffb540, 1);
    sdkSpriteDrawNowUnscaled(labelX, py, 0.0f, 0xFFFFFF, activeAlpha, 0x12, iGpffffb540, 1);
    yTimeNameDrawSelections(task, 0);
    if (entry->selectionState[1] != 0) {
        transitionAlpha = 0xFF;
    }
    inputWork = owner->work;
    sdkSpriteDrawNowUnscaled(229.0f, 150.0f, 0.0f, 0x4972FF, transitionAlpha, 0x17, iGpffffb540, 1);
    sdkSpriteDrawNowUnscaled(229.0f, 182.0f, 0.0f, 0x4972FF, transitionAlpha, 0x17, iGpffffb540, 1);
    if (((NameEntryWork *)inputWork)->inputState != 3) {
        nameCursor = iGpffffb538;
        if (nameCursor < 8) {
            nameCursorX = (nameCursor * 0x1C) + 0xE3;
            nameCursorY = 0x97;
        } else {
            nameCursorX = ((nameCursor - 8) * 0x1C) + 0xE3;
            nameCursorY = 0xB7;
        }
        sdkSpriteDrawNowUnscaled((f32)nameCursorX, (f32)nameCursorY, 0.0f, 0xCCFF33, transitionAlpha, 0x18, iGpffffb540, 1);
    }
    yTimeTrackProgress((u8 *)&((NameEntryWork *)work)->rowOrigin);
    yTimeTrackCurrentKey((u8 *)&entry->rowOrigin, pos);
    selectedCell = ((NameEntryWork *)work)->cellIndex / 5;
    previousCell = ((NameEntryWork *)work)->previousCellIndex / 5;
    changedCell = ((NameEntryWork *)work)->changedCellIndex / 5;
    cellIndex = 0;
    while (cellIndex < 0x18) {
        cellX = (f32)(((cellIndex / 6) * 0x94) + 0x19);
        cellY = (f32)(((cellIndex % 6) * 0x19) + 0xE3);
        sdkSpriteDrawNowUnscaled(cellX, cellY, 0.0f, 0x4972FF, 0xFF, 1, iGpffffb540, 1);
        if (cellIndex == 0) {
            sdkSpriteDrawNowUnscaled(18.0f, 219.0f, 0.0f, 0x4972FF, 0xFF, 0x1B, iGpffffb540, 1);
        }
        if (cellIndex == 5) {
            sdkSpriteDrawNowUnscaled(18.0f, 366.0f, 0.0f, 0x4972FF, 0xFF, 0x1C, iGpffffb540, 1);
        }
        if (cellIndex == 0x12) {
            sdkSpriteDrawNowUnscaled((f32)0x24A, 219.0f, 0.0f, 0x4972FF, 0xFF, 0x1D, iGpffffb540, 1);
        }
        if (cellIndex == 0x17) {
            sdkSpriteDrawNowUnscaled((f32)0x24A, 366.0f, 0.0f, 0x4972FF, 0xFF, 0x1E, iGpffffb540, 1);
        }
        if (((NameEntryWork *)work)->inputState != 3) {
            if ((selectedCell != previousCell) && (cellIndex == changedCell)) {
                changedTween = (u8 *)&((NameEntryWork *)work)->cells[cellIndex];
                yTimeTrackClear((s32)changedTween);
                yTimeTrackAppendKey((s32)changedTween, 0, 0, 0, 0,
                              fGpffff8204, 0, 0, 0x14);
            }
            cellTween = (u8 *)&((NameEntryWork *)work)->cells[cellIndex];
            yTimeTrackAdvance(cellTween);
            if (cellIndex == selectedCell) {
                sdkSpriteDrawNowUnscaled(cellX, cellY, 0.0f, 0x49AFFD, 0xFF, 1, iGpffffb540, 1);
                if (cellIndex == 0) {
                    sdkSpriteDrawNowUnscaled(18.0f, pos[1], 0.0f, 0x49AFFD, 0xFF, 0x1B, iGpffffb540, 1);
                }
                if (cellIndex == 5) {
                    sdkSpriteDrawNowUnscaled(18.0f, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, 0xFF, 0x1C, iGpffffb540, 1);
                }
                if (cellIndex == 0x12) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, pos[1], 0.0f, 0x49AFFD, 0xFF, 0x1D, iGpffffb540, 1);
                }
                if (cellIndex == 0x17) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, 0xFF, 0x1E, iGpffffb540, 1);
                }
            } else if (yTimeTrackIsNotDone(cellTween) != 0) {
                cellProgress = yTimeTrackProgress(cellTween);
                cellAlpha = (u8)(255.0f * (1.0f - cellProgress));
                sdkSpriteDrawNowUnscaled(cellX, cellY, 0.0f, 0x49AFFD, cellAlpha, 1, iGpffffb540, 1);
                if (cellIndex == 0) {
                    sdkSpriteDrawNowUnscaled(18.0f, pos[1], 0.0f, 0x49AFFD, cellAlpha, 0x1B, iGpffffb540, 1);
                }
                if (cellIndex == 5) {
                    sdkSpriteDrawNowUnscaled(18.0f, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, cellAlpha, 0x1C, iGpffffb540, 1);
                }
                if (cellIndex == 0x12) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, pos[1], 0.0f, 0x49AFFD, cellAlpha, 0x1D, iGpffffb540, 1);
                }
                if (cellIndex == 0x17) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, (171.0f + pos[1]) - 24.0f, 0.0f, 0x49AFFD, cellAlpha, 0x1E, iGpffffb540, 1);
                }
            }
        }
        cellIndex += 1;
    }
    yTimeLimitDrawIdlePulse(task);
    if (((NameEntryWork *)work)->inputState != 3) {
        cursorRow = ((NameEntryWork *)work)->cursorRow;
        cursorColumn = ((NameEntryWork *)work)->cursorColumn;
        cursorX = (f32)((cursorColumn % 5) * 0x1B);
        cursorGroup = cursorColumn / 5;
        switch (cursorGroup) {
        case 0:
            cursorX += 30.0f;
            break;
        case 1:
            cursorX += 178.0f;
            break;
        case 2:
            cursorX += 326.0f;
            break;
        case 3:
            cursorX += 474.0f;
            break;
        }
        cursorY = (f32)((cursorRow * 0x19) + 0xE5);
        cursorX += cursorOfs;
        cursorY += cursorOfs;
        sdkSpriteDrawNowUnscaled(cursorX, cursorY, 0.0f, 0xCCFF33, 0xFF, 0xF, iGpffffb540, 1);
    }
    for (glyphRow = 0; glyphRow < 6; glyphRow++) {
        glyphColumn = 0;
        rowBase = D_007485D0 + (glyphRow * 0x28);
        yBase = (glyphRow * 25) + 0xE5;
        for (; glyphColumn < 0x14; glyphColumn++) {
            glyph = ((s16 *)rowBase)[glyphColumn];
            if (glyph >= 0) {
                spriteIndex = glyph + 0x20;
                glyphX = (f32)((glyphColumn % 5) * 0x1B);
                glyphGroup = glyphColumn / 5;
                switch (glyphGroup) {
                case 0:
                    glyphX += 30.0f;
                    break;
                case 1:
                    glyphX += 178.0f;
                    break;
                case 2:
                    glyphX += 326.0f;
                    break;
                case 3:
                    glyphX += 474.0f;
                    break;
                }
                sdkSpriteDrawNowUnscaled(glyphX, (f32)yBase, 0.0f, 0x2D2D2D, 0xFF, spriteIndex, iGpffffb540, 1);
            }
        }
    }
    if ((entry->inputState == 3) &&
        (((NameEntryWork *)work)->transitionStarted == 0)) {
        sdkSpriteDrawNowUnscaled(0.0f, 102.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAC, iGpffffb540, 1);
    }
    if ((strlen(D_00882EF0) >> 1) != 0) {
        firstNameLength = (u32)(strlen(D_00882EF0) >> 1);
        sum = 0;
        firstNameX = 0xE7;
        firstNameIndex = 0;
        while (firstNameIndex < firstNameLength) {
            strncpy(iGpffffb528, D_00882EF0 + (firstNameIndex * 2), 2);
            sum += frFontExDrawText((f32)firstNameX, 121.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            firstNameX += 0x1C;
            firstNameIndex += 1;
        }
    }
    if ((strlen(D_00882ED0) >> 1) != 0) {
        lastNameLength = (u32)(strlen(D_00882ED0) >> 1);
        sum = 0;
        lastNameX = 0xE7;
        lastNameIndex = 0;
        while (lastNameIndex < lastNameLength) {
            strncpy(iGpffffb528, D_00882ED0 + (lastNameIndex * 2), 2);
            sum += frFontExDrawText((f32)lastNameX, 153.0f, 0.0f,
                                 0xCCFFFFFF, 0, 0, iGpffffb528, 0, 0);
            lastNameX += 0x1C;
            lastNameIndex += 1;
        }
    }
}


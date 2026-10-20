/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0029e9b0-0029fbb0 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "name_entry_internal.h"
#include "scr_internal.h"
#include "scene_event_internal.h"
#include "sdk_snd_internal.h"
/* sdkSpr.c establishes this 0x2C-byte sample; scales are unsigned Q12. */
typedef struct SdkSpriteSample {
    u32 packAddress, recordIndex;
    f32 x, y;
    union { s8 signedByte; u8 byte; } alphaSubtract;
    u8 fade;
    u8 pad12[2];
    s16 extendX, extendY;
    f32 angle;
    s16 pivotX, pivotY;
    u16 scaleX, scaleY;
    union { f32 value; s32 word; } depth;
    u8 red, green, blue, pad2B;
} SdkSpriteSample;

typedef char *va_list;

#define va_start(ap, last) (ap = (va_list)__builtin_args_info(2))

#define va_end(ap) ((void)0)

extern void scrDiscardArgs(void *, ...);
extern void strncpy(void *, void *, s32 );
extern void yTimeLimitStartRowTransition(u8 *, s32 );
extern s32 iGpffffb538;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 D_00882EDE[];
extern u8 D_00882EFE[];
static inline u8 *code29AddOff(s32 offset, u8 *base) {
    return (u8 *)((u32)offset + (u32)base);
}

extern u8 yTimeTrackClear(s32 );
extern u32 yTimeTrackAppendKey(s32 , s32 , s32 , s32 ,
                          s32 , f32 , s32 , s32 ,
                          s32 );
extern f32 fGpffff8204;
extern void mtMiscDrawSpriteAt(s32 , f32 , f32 , f32 ,
                          f32 , s32 , s32 );
extern void yTimeTrackAdvance(u8 *);
extern s32 yTimeTrackIsIdle(u8 *);
extern s32 yTimeTrackIsNotDone(u8 *);
extern f32 yTimeTrackProgress(u8 *);
extern s32 strncmp(void *, void *, s32 );
extern u32 strlen(const void *);
extern void memcpy(void *, void *, s32 );
extern void yTimeLimitMoveGridCursor(u8 *);
extern s32 D_0076462C;
extern u8 iGpffffa7e8;
extern u8 *iGpffffb540;
extern u8 D_0063E810[];
extern u16 D_008C024E[];
extern s32 D_0063E830[];
extern s32 yTimeTrackCurrentKey(u8 *, f32 *);
extern void sdkSpriteDrawNowUnscaled(f32 , f32 , f32 , s32 , u8 , s32 , void * , s32 );
extern s32 sdkSpriteDrawNow(f32 , f32 , f32 , s32 , u8 , s32 , void * , s32 , s16 , s16 , f32 , f32 , f32 );
#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Accept and discard a variadic script argument list; no arguments are consumed. */
// FUN_0029E9B0
void scrDiscardArgs(void *context, ...)
{
    va_list args;
    va_start(args, context);
    va_end(args);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
// Draws sprite  once at (, ): allocates a node from the sprite table,
// sets alpha from  (0xFF minus it), scales by /, centres it on the
// position when  is 1, then draws and frees the node.
// FUN_0029E9E0
void mtMiscDrawSpriteAt(s32 image, f32 x, f32 y, f32 scaleX, f32 scaleY,
                   s32 alphaSubtract, s32 centered)
{
    /* measured: remaining name-entry byte accesses preserve b210 reload/address scheduling; individual typed substitutions lose MATCH. */
    extern u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex);
    extern f32 sdkSpriteScaledWidth(u8 *sprite);
    extern f32 sdkSpriteScaledHeight(u8 *sprite);
    extern void sdkSpriteDraw(u8 *sample, s32 setStates);
    extern void sdkSpriteFreeNode(void *node);
    f32 height;
    f32 initialWidth;
    f32 initialHeight;
    f32 width;
    u8 *sprite;

    sprite = sdkSpriteNewNode((u32)iGpffffb540, (u32)image);
    ((SdkSpriteSample *)sprite)->depth.word = 0;
    ((SdkSpriteSample *)sprite)->x = x;
    ((SdkSpriteSample *)sprite)->y = y;
    initialWidth = sdkSpriteScaledWidth(sprite);
    initialHeight = sdkSpriteScaledHeight(sprite);
    ((SdkSpriteSample *)sprite)->alphaSubtract.signedByte = (s8)(0xFF - (alphaSubtract & 0xFF));
    ((SdkSpriteSample *)sprite)->scaleX = (u16)(4096.0f * scaleX);
    ((SdkSpriteSample *)sprite)->scaleY = (u16)(4096.0f * scaleY);
    if (centered == 1) {
        width = sdkSpriteScaledWidth(sprite);
        height = sdkSpriteScaledHeight(sprite);
        *(f32 *)(sprite + 8) =
            x - ((0.5f + (width - initialWidth)) / 2.0f);
        *(f32 *)(sprite + 0xC) =
            y - ((0.5f + (height - initialHeight)) / 2.0f);
    }
    sdkSpriteDraw(sprite, 1);
    sdkSpriteFreeNode(sprite);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Queue the input-row mode transition: mode selects the starting and ending Y positions. */
// FUN_0029EBF0
void yTimeLimitStartRowTransition(u8 *task, s32 mode)
{
    s32 x;
    s32 startY;
    s32 endY;
    s32 workAddress;

    workAddress = (s32)((struct KwlnTask *)task)->work;
    if (mode == 0) {
        x = 0xED;
        endY = 0x4C;
        startY = endY;
    } else if (mode == 1) {
        x = 0xED;
        startY = 0x4C;
        endY = 0x49;
    } else {
        x = 0xED;
        endY = 0x4C;
        startY = 0x49;
    }
    yTimeTrackClear(workAddress + 0x2A8);
    yTimeTrackAppendKey(workAddress + 0x2A8, x, startY, x, endY,
                  fGpffff8204, 0, 0, 0xA);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
/* Move the character-grid cursor, skipping invalid cells and wrapping only for newly pressed directions. */
// FUN_0029ECB0
void yTimeLimitMoveGridCursor(u8 *task)
{
    /* measured: remaining name-entry byte accesses preserve b210 reload/address scheduling; individual typed substitutions lose MATCH. */
    extern u16 D_008C027A[];
    extern u8 D_007485D0[];
    u8 *state;
    u8 *entry;
    s32 value;

    state = ((struct KwlnTask *)task)->work;
    ((NameEntryWork *)state)->previousColumn = ((NameEntryWork *)state)->cursorColumn;
    ((NameEntryWork *)state)->previousRow = ((NameEntryWork *)state)->cursorRow;
    ((NameEntryWork *)state)->previousCellIndex = ((NameEntryWork *)state)->cellIndex;
    if (*(u16 *)D_008C027A & 0x4000) {
        do {
            value = *(s32 *)(state + 0x20) + 1;
            *(s32 *)(state + 0x20) = value;
            if (value >= 6) {
                if (*(u16 *)D_008C024E & 0x4000)
                    *(s32 *)(state + 0x20) = 0;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x1000) {
        do {
            value = *(s32 *)(state + 0x20) - 1;
            *(s32 *)(state + 0x20) = value;
            if (value < 0) {
                if (*(u16 *)D_008C024E & 0x1000)
                    *(s32 *)(state + 0x20) = 5;
                else
                    *(s32 *)(state + 0x20) = *(s32 *)(state + 0x2C);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x2000) {
        do {
            value = *(s32 *)(state + 0x1C) + 1;
            *(s32 *)(state + 0x1C) = value;
            if (value >= 20) {
                if (*(u16 *)D_008C024E & 0x2000)
                    *(s32 *)(state + 0x1C) = 0;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    if (*(u16 *)D_008C027A & 0x8000) {
        do {
            value = *(s32 *)(state + 0x1C) - 1;
            *(s32 *)(state + 0x1C) = value;
            if (value < 0) {
                if (*(u16 *)D_008C024E & 0x8000)
                    *(s32 *)(state + 0x1C) = 19;
                else
                    *(s32 *)(state + 0x1C) = *(s32 *)(state + 0x28);
            }
            entry = D_007485D0 + *(s32 *)(state + 0x20) * 0x28;
            entry = code29AddOff(*(s32 *)(state + 0x1C) * 2, entry);
        } while (*(s16 *)entry < 0);
    }
    value = *(s32 *)(state + 0x1C) % 5 + *(s32 *)(state + 0x20) * 5;
    *(s32 *)(state + 0x24) = value;
    value += (*(s32 *)(state + 0x1C) / 5) * 30;
    *(s32 *)(state + 0x24) = value;
    if (value != *(s32 *)(state + 0x30)) {
        *(s32 *)(state + 0x34) = *(s32 *)(state + 0x28);
        *(s32 *)(state + 0x38) = *(s32 *)(state + 0x2C);
        *(s32 *)(state + 0x3C) = *(s32 *)(state + 0x30);
        sdkSndStartStream(0, 0, 0, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Copy a two-byte character into the current name slot and advance, switching rows after slot seven. */
// FUN_0029EF90
void yTimeLimitRecordInput(u8 *task, u8 *character)
{
    s32 position;
    s32 nextPosition;
    u8 *work;

    work = ((struct KwlnTask *)task)->work;
    position = iGpffffb538;
    if (position < 0x10) {
        if (position < 8) {
            strncpy(D_00882EF0 + position * 2, character, 2);
        } else {
            strncpy(D_00882ED0 + (position - 8) * 2, character, 2);
        }
        nextPosition = iGpffffb538 + 1;
        iGpffffb538 = nextPosition;
        if (nextPosition >= 0x10) {
            iGpffffb538 = 0xF;
            return;
        }
        if (nextPosition == 8) {
            ((NameEntryWork *)work)->selectionState[1] = 1;
            yTimeLimitStartRowTransition(task, 1);
        }
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Update name-entry actions and six button states, including insertion, deletion, cursor movement and confirmation. */
// FUN_0029F070
void yTimeLimitUpdateInput(u8 *task)
{
    u8 character[4];
    s32 secondPosition;
    s32 firstPosition;
    s32 position;
    s32 previousPosition;
    s32 nextPosition;
    u8 *cursor;
    s32 canInsert;
    s32 canMoveBack;
    s32 canMoveForward;
    s32 operation;
    s32 firstIndex;
    s32 secondIndex;
    s32 hasFirstSuffix;
    s32 secondSuffixIndex;
    s32 firstBlanks;
    s32 secondBlanks;
    s32 firstSuffixIndex;
    s32 hasSecondSuffix;
    s32 buttonIndex;
    s32 firstShiftIndex;
    s32 secondShiftIndex;
    u8 *work;
    u8 *text;

    work = ((struct KwlnTask *)task)->work;
    buttonIndex = 0;
    while (buttonIndex < 6) {
        ((NameEntryWork *)work)->selectionFlash[buttonIndex] = 0;
        buttonIndex += 1;
    }
    cursor = work + 0x1C4C;
    *(s16 *)cursor = 0;
    operation = 0;
    if (D_0076462C == 0) {
        firstBlanks = 0;
        firstIndex = 0;
        while (firstIndex < 8) {
            if (strncmp(&iGpffffa7e8,
                              D_00882EF0 + (firstIndex * 2), 2) == 0) {
                firstBlanks += 1;
            }
            firstIndex += 1;
        }
        if (firstBlanks < 8) {
            secondBlanks = 0;
            secondIndex = 0;
            while (secondIndex < 8) {
                if (strncmp(&iGpffffa7e8,
                                  D_00882ED0 + (secondIndex * 2), 2) == 0) {
                    secondBlanks += 1;
                }
                secondIndex += 1;
            }
            if (secondBlanks < 8) {
                operation = 1;
                *(s16 *)cursor = 1;
            }
        }
    }
    if ((D_008C024E[0] & 0x800) && (operation > 0)) {
        ((NameEntryWork *)work)->inputState = 3;
        ((NameEntryWork *)work)->selectionFlash[5] = 1;
        sdkSndStartStream(0, 0, 0, 1);
        return;
    }
    cursor = work + 0x1C38;
    *(s16 *)cursor = 0;
    operation = 0;
    if (D_0076462C > 0) {
        operation = 0xA;
    } else if (iGpffffb538 < 8) {
        if ((strlen(D_00882EF0) >> 1) != 0) {
            firstPosition = iGpffffb538;
            if (strncmp(&iGpffffa7e8,
                              D_00882EF0 + (firstPosition * 2), 2) == 0) {
                hasFirstSuffix = 0;
                firstSuffixIndex = firstPosition + 1;
                while (firstSuffixIndex < 8) {
                    if (strncmp(&iGpffffa7e8,
                                      D_00882EF0 + (firstSuffixIndex * 2), 2) != 0) {
                        hasFirstSuffix = 1;
                        break;
                    }
                    firstSuffixIndex += 1;
                }
                if (hasFirstSuffix != 0) {
                    operation = 0x14;
                }
            } else {
                operation = 0x15;
            }
        }
    } else if ((strlen(D_00882ED0) >> 1) != 0) {
        secondPosition = iGpffffb538 - 8;
        if (strncmp(&iGpffffa7e8,
                          D_00882ED0 + (secondPosition * 2), 2) == 0) {
            hasSecondSuffix = 0;
            secondSuffixIndex = secondPosition + 1;
            while (secondSuffixIndex < 8) {
                if (strncmp(&iGpffffa7e8,
                                  D_00882ED0 + (secondSuffixIndex * 2), 2) != 0) {
                    hasSecondSuffix = 1;
                    break;
                }
                secondSuffixIndex += 1;
            }
            if (hasSecondSuffix != 0) {
                operation = 0x1E;
            }
        } else {
            operation = 0x1F;
        }
    }
    if (operation > 0) {
        *(s16 *)cursor = 1;
    }
    if (D_008C024E[0] & 0x20) {
        switch (operation) {
        case 10:
            position = iGpffffb538;
            if (position < 8) {
                strncpy(D_00882EF0 + (position * 2),
                              &iGpffffa7e8, 2);
            } else {
                strncpy(D_00882ED0 + ((position - 8) * 2),
                              &iGpffffa7e8, 2);
            }
            break;
        case 20:
            firstShiftIndex = iGpffffb538;
            firstShiftIndex += 1;
            text = D_00882EF0;
            while (firstShiftIndex < 8) {
                cursor = text + (firstShiftIndex * 2);
                ((s8 *)cursor)[-2] = *(s8 *)cursor;
                ((s8 *)cursor)[-1] = ((s8 *)cursor)[1];
                firstShiftIndex += 1;
            }
            strncpy(D_00882EFE, &iGpffffa7e8, 2);
            break;
        case 21:
            strncpy(D_00882EF0 + (iGpffffb538 * 2),
                          &iGpffffa7e8, 2);
            break;
        case 30:
            secondShiftIndex = iGpffffb538 - 8;
            secondShiftIndex += 1;
            text = D_00882ED0;
            while (secondShiftIndex < 8) {
                cursor = text + (secondShiftIndex * 2);
                ((s8 *)cursor)[-2] = *(s8 *)cursor;
                ((s8 *)cursor)[-1] = ((s8 *)cursor)[1];
                secondShiftIndex += 1;
            }
            strncpy(D_00882EDE, &iGpffffa7e8, 2);
            break;
        case 31:
            strncpy(D_00882ED0 + ((iGpffffb538 - 8) * 2),
                          &iGpffffa7e8, 2);
            break;
        default:
            operation = 0;
            break;
        }
        if (operation > 0) {
            ((NameEntryWork *)work)->selectionFlash[0] = 1;
            sdkSndStartStream(0, 0, 0, 2);
            return;
        }
    }
    cursor = work + 0x1C3C;
    *(s16 *)cursor = 0;
    canInsert = 0;
    if (D_0076462C < 0x10) {
        canInsert = 1;
        *(s16 *)cursor = 1;
    }
    if ((*(u16 *)D_008C024E & 0x40) && (canInsert > 0)) {
        memcpy(character,
                      ((u8 **)D_0063E810)[((NameEntryWork *)work)->cursorRow] +
                          (((NameEntryWork *)work)->cursorColumn * 2),
                      2);
        yTimeLimitRecordInput(task, character);
        ((NameEntryWork *)work)->selectionFlash[1] = 1;
        sdkSndStartStream(0, 0, 0, 1);
        return;
    }
    cursor = work + 0x1C40;
    *(s16 *)cursor = 0;
    canMoveBack = 0;
    if (iGpffffb538 > 0) {
        canMoveBack = 1;
        *(s16 *)cursor = 1;
    }
    if ((*(u16 *)D_008C024E & 4) && (canMoveBack > 0)) {
        previousPosition = iGpffffb538 - 1;
        iGpffffb538 = previousPosition;
        if (previousPosition == 7) {
            ((NameEntryWork *)work)->selectionState[1] = 2;
            yTimeLimitStartRowTransition(task, 2);
        }
        ((NameEntryWork *)work)->selectionFlash[2] = 1;
        sdkSndStartStream(0, 0, 0, 0);
    }
    cursor = work + 0x1C48;
    *(s16 *)cursor = 0;
    canMoveForward = 0;
    if (iGpffffb538 < 0xF) {
        canMoveForward = 1;
        *(s16 *)cursor = 1;
    }
    if ((*(u16 *)D_008C024E & 8) && (canMoveForward > 0)) {
        nextPosition = iGpffffb538 + 1;
        iGpffffb538 = nextPosition;
        if (nextPosition == 8) {
            ((NameEntryWork *)work)->selectionState[1] = 1;
            yTimeLimitStartRowTransition(task, 1);
        }
        ((NameEntryWork *)work)->selectionFlash[4] = 1;
        sdkSndStartStream(0, 0, 0, 0);
    }
    yTimeLimitMoveGridCursor(task);
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Pulse the selected character after 90 idle frames; reset the pulse when input leaves the grid. */
// FUN_0029F790
void yTimeLimitDrawIdlePulse(u8 *task)
{
    /* measured: remaining name-entry byte accesses preserve b210 reload/address scheduling; individual typed substitutions lose MATCH. */
    u8 *work;
    s32 idleFrames;
    s32 page;
    s32 column;
    s32 row;
    f32 x;
    f32 y;
    f32 progress;
    f32 inset;
    f32 cellY;
    f32 cellX;
    f32 scale;
    s32 alpha;

    work = ((struct KwlnTask *)task)->work;
    if (((NameEntryWork *)work)->inputState != 1) {
        if (yTimeTrackIsIdle(work + 0xE0) == 0) {
            yTimeTrackClear((s32)(work + 0xE0));
        }
        return;
    }

    if (((NameEntryWork *)work)->cellIndex == ((NameEntryWork *)work)->previousCellIndex) {
        idleFrames = ((NameEntryWork *)work)->selectionState[0] + 1;
        ((NameEntryWork *)work)->selectionState[0] = idleFrames;
        if (idleFrames >= 0x5A) {
            *(s32 *)(work + 0x1C30) = 0;
            row = ((NameEntryWork *)work)->cursorRow;
            column = ((NameEntryWork *)work)->cursorColumn;
            x = (f32)((column % 5) * 27);
            page = column / 5;
            switch (page) {
            case 0:
                x += 30.0f;
                break;
            case 1:
                x += 178.0f;
                break;
            case 2:
                x += 326.0f;
                break;
            case 3:
                x += 474.0f;
                break;
            }
            y = (f32)(row * 25 + 0xE5);
            yTimeTrackClear((s32)(work + 0xE0));
            yTimeTrackAppendKey((s32)code29AddOff(0xE0, work),
                          (s32)x,
                          (s32)y, (s32)x, (s32)y,
                          fGpffff8204, 0, 0, 0x3C);
        }
    } else {
        ((NameEntryWork *)work)->selectionState[0] = 0;
    }

    if ((yTimeTrackIsIdle(work + 0xE0) == 0) &&
        (yTimeTrackIsNotDone(work + 0xE0) != 0)) {
        yTimeTrackAdvance(work + 0xE0);
        row = ((NameEntryWork *)work)->cursorRow;
        column = ((NameEntryWork *)work)->cursorColumn;
        cellX = (f32)((column % 5) * 27);
        page = column / 5;
        switch (page) {
        case 0:
            cellX += 30.0f;
            break;
        case 1:
            cellX += 178.0f;
            break;
        case 2:
            cellX += 326.0f;
            break;
        case 3:
            cellX += 474.0f;
            break;
        }
        cellY = (f32)(row * 25 + 0xE5);
        inset = -12.0f;
        y = cellY;
        x = cellX + inset;
        y += inset;
        progress = yTimeTrackProgress(work + 0xE0);
        if (progress < 0.5f) {
            alpha = (u8)(255.0f * progress);
            scale = 1.0f + progress;
        } else {
            cellX = 1.0f - progress;
            alpha = (u8)(255.0f * cellX);
            scale = 1.0f + cellX;
        }
        mtMiscDrawSpriteAt(0xF, x, y, scale, scale,
                      alpha, 1);
    }
}
#pragma pop

/* func_0029fbb0, MATCH 2026-10-07. The 6x24-byte slide table is a struct
   array copied in by retail's dword loop. A field address used twice becomes an
   IRO_CommonSubs address temporary, which gives retail's unfolded
   `addiu tmp,sp,K; lw x,0(tmp)` reads; each region-3 field is therefore read
   again in the next expression or call. .originX/.originY are u32: `t17 = tbl[].originX`
   is then a conversion, so copy propagation keeps t17/t18 as declared locals,
   declared in the order the regalloc model needs. */
typedef struct NameButtonPlacement {
    s32 foregroundSprite, backgroundSprite, foregroundX, foregroundY;
    u32 originX, originY;
} NameButtonPlacement;

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
/* Animate one of six name-entry buttons and draw its background, foreground and short selection flash. */
// FUN_0029FBB0
void yTimeLimitDrawButton(u8 *task, s32 selection) {
    NameButtonPlacement slides[6];
    f32 position[2];
    u8 *base;
    s16 *status;
    s16 *previousStatus;
    u8 overlayAlpha;
    u8 *flashTrack;
    s32 originY;
    u8 *slideTrack;
    s32 foregroundSprite;
    u8 color;
    s32 originX;
    s32 x;
    s32 y;
    s32 backgroundSprite;
    s32 foregroundX;
    s32 foregroundY;
    s32 foregroundDrawY;
    s32 foregroundDrawX;
    f32 progress;
    s32 selectionOffset;
    s32 *sourceWords;
    s32 *destinationWords;
    s32 copyCount;
    s32 firstWord;
    s32 secondWord;
    base = ((struct KwlnTask *)task)->work;
    sourceWords = D_0063E830;
    destinationWords = (s32 *)slides;
    copyCount = 0x12;
do_copy:
    firstWord = sourceWords[0];
    secondWord = sourceWords[1];
    sourceWords += 2;
    copyCount -= 1;
    destinationWords[0] = firstWord;
    destinationWords[1] = secondWord;
    destinationWords += 2;
    if (copyCount > 0) {
        goto do_copy;
    }
    slideTrack = base + selection * 0x130 + 0x1510;
    flashTrack = base + selection * 0x130 + 0x15A8;
    selectionOffset = selection * 4;
    status = &((NameEntryWork *)base)->selectionStatus[selection][0];
    previousStatus = &((NameEntryWork *)base)->selectionStatus[selection][1];
    {
        s32 v0 = *status;
        if (v0 == 3) {
            if (v0 != *previousStatus) {
                s32 a0 = slides[selection].originX;
                s32 a1 = slides[selection].originY;
                yTimeTrackClear((s32)slideTrack);
                yTimeTrackAppendKey((s32)slideTrack, a0, a1 + 0x1E, a0, a1, fGpffff8204, 0, 0, 0xA);
                *previousStatus = *status;
            }
            yTimeTrackAdvance(slideTrack);
            progress = yTimeTrackProgress(slideTrack);
            color = (u8)(255.0f * progress);
            yTimeTrackCurrentKey(slideTrack, position);
            x = (s32)position[0];
            y = (s32)position[1];
            sdkSpriteDrawNowUnscaled((f32)x, (f32)y, 0.0f, 0x2D2D2D, color, slides[selection].backgroundSprite, iGpffffb540, 1);
            sdkSpriteDrawNowUnscaled((f32)((x + slides[selection].foregroundX) - (s32)slides[selection].originX), (f32)((y + slides[selection].foregroundY) - (s32)slides[selection].originY), 0.0f, 0x8F8F8F, color, slides[selection].foregroundSprite, iGpffffb540, 1);
            return;
        }
        if (v0 != *previousStatus) {
            if (v0 == 0) {
                s32 a0 = slides[selection].originX;
                s32 a1 = slides[selection].originY;
                yTimeTrackClear((s32)slideTrack);
                if (*previousStatus == 3) {
                    yTimeTrackAppendKey((s32)slideTrack, a0, a1, a0, a1, fGpffff8204, 0, 0, 1);
                } else {
                    yTimeTrackAppendKey((s32)slideTrack, a0, a1, a0, a1, fGpffff8204, 0, 0, 0xA);
                }
            }
            *previousStatus = *status;
        }
        yTimeTrackAdvance(slideTrack);
        progress = yTimeTrackProgress(slideTrack);
        if (*previousStatus == 0) {
            f32 t = 1.0f - progress;
            u32 iv = (u32)(255.0f * t);
            color = (iv >> 1) & 0xFF;
        } else {
            color = 0xFF;
        }
        overlayAlpha = color & 0xFF;
        yTimeTrackCurrentKey(slideTrack, position);
        x = (s32)position[0];
        y = (s32)position[1];
        backgroundSprite = slides[selection].backgroundSprite;
        sdkSpriteDrawNowUnscaled((f32)x, (f32)y, 0.0f, 0x2D2D2D, 0xFF, slides[selection].backgroundSprite, iGpffffb540, 1);
        foregroundSprite = slides[selection].foregroundSprite;
        originY = slides[selection].originY;
        foregroundY = slides[selection].foregroundY;
        foregroundDrawY = (y + slides[selection].foregroundY) - slides[selection].originY;
        originX = slides[selection].originX;
        foregroundX = slides[selection].foregroundX;
        foregroundDrawX = (x + slides[selection].foregroundX) - slides[selection].originX;
        sdkSpriteDrawNowUnscaled((f32)foregroundDrawX, (f32)foregroundDrawY, 0.0f, 0x8F8F8F, 0xFF, slides[selection].foregroundSprite, iGpffffb540, 1);
        sdkSpriteDrawNowUnscaled((f32)x, (f32)y, 0.0f, 0x99, overlayAlpha, backgroundSprite, iGpffffb540, 1);
        sdkSpriteDrawNowUnscaled((f32)foregroundDrawX, (f32)foregroundDrawY, 0.0f, 0xCCFFFF, overlayAlpha, foregroundSprite, iGpffffb540, 1);
        {
            u8 *b2 = code29AddOff(selectionOffset, base);
            s32 *pflag = (s32 *)(b2 + 0x1C50);
            if (*pflag != 0) {
                *pflag = 0;
                x = originX;
                y = originY;
                yTimeTrackClear((s32)flashTrack);
                yTimeTrackAppendKey((s32)flashTrack, originX, originY, originX, originY, fGpffff8204, 0, 0, 2);
            }
        }
        if ((yTimeTrackIsIdle(flashTrack) == 0) && (yTimeTrackIsNotDone(flashTrack) != 0)) {
            yTimeTrackAdvance(flashTrack);
            yTimeTrackProgress(flashTrack);
            overlayAlpha = 0xFF;
            yTimeTrackCurrentKey(flashTrack, position);
            x = (s32)position[0];
            y = (s32)position[1];
            sdkSpriteDrawNow((f32)x, (f32)y, 0.0f, 0xCCFF33, 0xFF, backgroundSprite, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
            sdkSpriteDrawNow((f32)((x + foregroundX) - originX), (f32)((y + foregroundY) - originY), 0.0f, 0x2D2D2D, 0xFF, foregroundSprite, iGpffffb540, 1, 0, 0, 0.0f, 1.0f, 1.0f);
        }
        if ((selection == 0) || (selection == 1) || (selection == 3)) {
            sdkSpriteDrawNowUnscaled((f32)((x + foregroundX) - originX), (f32)((y + foregroundY) - originY), 0.0f, 0xCCFFFF, overlayAlpha, foregroundSprite + 0xB2, iGpffffb540, 1);
        }
    }
}
#pragma pop

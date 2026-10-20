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
extern u32 yTimeTrackAppendKey(s32, s32, s32, s32,
                         s32, f32 farg0, s32, s32, s32);
extern s32 yTimeTrackIsIdle(u8 *track);
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
extern void yTimeNameDrawReveal(u8 *task, s32 stage);

extern void yTimeNameDrawSelections(u8 *task, s32 preserveStatus);


#pragma push
/* measured: retail keeps glyph and row values in separate lifetimes. */
#pragma opt_lifetimes on
/* measured: retail also hoists loop invariants alongside the separate glyph/row lifetimes. */
#pragma opt_loop_invariants on
/* Array-member accesses keep the row's animation address across glyph calls; the grid index is
 * reused by the later, separate glyph loop. */
// FUN_002A12E0
/* Draw the staged name-entry reveal: rotating background, selection slots, cell fades, then sliding glyph rows. */
void yTimeNameDrawReveal(u8 *task, s32 stage) {
    NameEntryWork *work;
    f32 position[2];
    f32 glyphX;
    f32 glyphY;
    f32 rowY;
    f32 cellY;
    f32 cellRowY;
    f32 cellProgress;
    s32 cellIndex;
    s32 rowIndex;
    s32 backgroundFrame;
    s32 glyphGroup;
    s16 character;

    work = (NameEntryWork *)((KwlnTask *)task)->work;
    if ((stage >= 0) && (yTimeTrackIsIdle((u8 *)&work->background) == 0)) {
        u8 alpha;
        alpha = (u8)(255.0f * yTimeTrackProgress((u8 *)&work->background));
        sdkSpriteDrawNowUnscaled(0.0f, 0.0f, 0.0f, 0xFFFFFF, alpha, 0xA4, iGpffffb540, 1);
        backgroundFrame = work->backgroundFrame + 1;
        work->backgroundFrame = backgroundFrame;
        if (backgroundFrame > 0x5A0) {
            work->backgroundFrame = 0;
        }
        sdkSpriteDrawNow(-78.0f, -82.0f, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B,
            (f32)(work->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
        sdkSpriteDrawNow(540.0f, (f32)0x15B, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B,
            (f32)(work->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
        sdkSpriteDrawNowUnscaled(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1);
        sdkSpriteDrawNowUnscaled(0.0f, 346.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1);
    }
    if (stage > 0) {
        yTimeNameDrawSelections(task, 1);
        if (yTimeTrackIsIdle((u8 *)&work->rowOrigin) == 0) {
            yTimeTrackCurrentKey((u8 *)&work->rowOrigin, position);
            yTimeTrackProgress((u8 *)&work->rowOrigin);
        }
    }
    if (stage >= 2) {
        for (cellIndex = 0; cellIndex < 0x18; cellIndex++) {
            NameTweenState *cellTween;
            u8 alpha2;
            cellTween = &work->cells[cellIndex];
            if (yTimeTrackIsIdle((u8 *)cellTween) == 0) {
                cellProgress = yTimeTrackProgress((u8 *)cellTween);
                cellRowY = (f32)((cellIndex % 6) * 0x19 + 0xE3);
                cellY = cellRowY;
                alpha2 = (u8)(255.0f * cellProgress);
                sdkSpriteDrawNowUnscaled((f32)((cellIndex / 6) * 0x94 + 0x19), cellY, 0.0f, 0x4972FF, alpha2, 1, iGpffffb540, 1);
                if (cellIndex == 0) {
                    sdkSpriteDrawNowUnscaled(18.0f, position[1], 0.0f, 0x4972FF, alpha2, 0x1B, iGpffffb540, 1);
                }
                if (cellIndex == 5) {
                    sdkSpriteDrawNowUnscaled(18.0f, (171.0f + position[1]) - 24.0f, 0.0f, 0x4972FF, alpha2, 0x1C, iGpffffb540,
                        1);
                }
                if (cellIndex == 0x12) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, position[1], 0.0f, 0x4972FF, alpha2, 0x1D, iGpffffb540, 1);
                }
                if (cellIndex == 0x17) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, (171.0f + position[1]) - 24.0f, 0.0f, 0x4972FF, alpha2, 0x1E,
                        iGpffffb540, 1);
                }
            }
        }
    }
    if (stage >= 2) {
        for (rowIndex = 0; rowIndex < 6; rowIndex++) {
            if (yTimeTrackIsIdle((u8 *)&work->rows[rowIndex]) == 0) {
                {
                    s32 yBase;
                    u8 *rowBase;
                    cellIndex = 0;
                    rowBase = D_007485D0 + (rowIndex * 0x28);
                    yBase = (rowIndex * 25) + 0xE5;
                    for (; cellIndex < 0x14; cellIndex++) {
                        character = ((s16 *)rowBase)[cellIndex];
                        if (character >= 0) {
                            s32 tex;
                            tex = character + 0x20;
                            glyphX = (f32)((cellIndex % 5) * 0x1B);
                            glyphGroup = cellIndex / 5;
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
                            rowY = (f32)yBase;
                            glyphY = rowY;
                            yTimeTrackProgress((u8 *)&work->rows[rowIndex]);
                            yTimeTrackCurrentKey((u8 *)&work->rows[rowIndex], position);
                            sdkSpriteDrawNowUnscaled(glyphX, glyphY + (f32)(s32)position[1], 0.0f, 0x2D2D2D, 0xFF, tex,
                                iGpffffb540, 1);
                        }
                    }
                }
            }
        }
    }
}
#pragma pop


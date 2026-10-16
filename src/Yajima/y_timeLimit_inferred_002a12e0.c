/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

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
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern s32 func_002a2ca0(u8 *arg0);
extern f32 func_002a2cd0(u8 *arg0);
extern s32 func_002a2c10(u8 *arg0, f32 *arg1);
extern void sdkSpriteDrawNowUnscaled(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4);
extern s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;

typedef struct P4_002aa450_Pair {
    s64 bits;
    f32 value;
} P4_002aa450_Pair;
typedef struct P4_002aa450_Work {
    u8 matrix[0x40];
    P4_002aa450_Pair pair4;
    P4_002aa450_Pair pair3;
    P4_002aa450_Pair pair2;
    P4_002aa450_Pair pair1;
    P4_002aa450_Pair pair0;
} P4_002aa450_Work;
static inline f32 p4_002aa450_mul(f32 left, f32 right) {
    return left * right;
}
struct RwMatrixTag;
extern void func_00366960(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
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
extern void func_002a12e0(u8 *arg0, s32 arg1);

/* Source unit: src/promoted/code1_002a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002a.c; members 002a12e0-002a12e0 */

extern void func_002a02f0(u8 *arg0, s32 arg1);
typedef struct NameTweenEntry {
    f32 startX, startY, endX, endY, stepX, stepY, rate;
    s8 delay, hold;
    s16 duration;
} NameTweenEntry;
typedef struct NameTweenState {
    NameTweenEntry entries[4];
    s32 current, count, frame;
    u32 flags;
    s32 timer, total;
} NameTweenState;
typedef struct NameEntrySelectionTweens {
    NameTweenState slide, pulse;
} NameEntrySelectionTweens;
typedef struct NameEntryRenderWork {
    /* 0x0000 */ u8 stateBeforeBackground[0x178];
    /* 0x0178 */ NameTweenState background;
    /* 0x0210 */ NameTweenState rowOrigin;
    /* 0x02a8 */ NameTweenState modeTransition;
    /* 0x0340 */ NameTweenState cells[24];
    /* 0x1180 */ NameTweenState rows[6];
    /* 0x1510 */ NameEntrySelectionTweens selection[6];
    /* 0x1c30 */ s32 selectionState[2];
    /* 0x1c38 */ s16 selectionStatus[6][2];
    /* 0x1c50 */ s32 selectionFlash[6];
    /* 0x1c68 */ s32 backgroundFrame;
} NameEntryRenderWork;
#pragma push
/* measured: func_002a12e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_lifetimes on
/* measured: func_002a12e0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
/* Array-member accesses retain the row's animation address across glyph
 * calls. The grid index is reused by the later, disjoint glyph loop.
 * 1828 matching code bytes; the 1840-byte window has twelve zero tail bytes. */
// FUN_002A12E0
void func_002a12e0(u8 *arg0, s32 arg1) {
    NameEntryRenderWork *work;
    f32 stack[2];
    f32 glyphX;
    f32 glyphY;
    f32 rowY;
    f32 cellY;
    f32 cellRowY;
    f32 cellProgress;
    s32 i;
    s32 j;
    s32 cnt;
    s32 q;
    s16 character;

    work = *(NameEntryRenderWork **)(arg0 + 0x38);
    if ((arg1 >= 0) && (func_002a2ca0((u8 *)&work->background) == 0)) {
        u8 alpha;
        alpha = (u8)(255.0f * func_002a2cd0((u8 *)&work->background));
        sdkSpriteDrawNowUnscaled(0.0f, 0.0f, 0.0f, 0xFFFFFF, alpha, 0xA4, iGpffffb540, 1);
        cnt = work->backgroundFrame + 1;
        work->backgroundFrame = cnt;
        if (cnt > 0x5A0) {
            work->backgroundFrame = 0;
        }
        sdkSpriteDrawNow(-78.0f, -82.0f, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B,
            (f32)(work->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
        sdkSpriteDrawNow(540.0f, (f32)0x15B, 0.0f, 0x4972FF, alpha, 0xB1, iGpffffb540, 1, 0x5B, 0x5B,
            (f32)(work->backgroundFrame * -0x168) / 1440.0f, 1.0f, 1.0f);
        sdkSpriteDrawNowUnscaled(0.0f, 0.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAF, iGpffffb540, 1);
        sdkSpriteDrawNowUnscaled(0.0f, 346.0f, 0.0f, 0xFFFFFF, 0xFF, 0xAE, iGpffffb540, 1);
    }
    if (arg1 > 0) {
        func_002a02f0(arg0, 1);
        if (func_002a2ca0((u8 *)&work->rowOrigin) == 0) {
            func_002a2c10((u8 *)&work->rowOrigin, stack);
            func_002a2cd0((u8 *)&work->rowOrigin);
        }
    }
    if (arg1 >= 2) {
        for (i = 0; i < 0x18; i++) {
            NameTweenState *cellTween;
            u8 alpha2;
            cellTween = &work->cells[i];
            if (func_002a2ca0((u8 *)cellTween) == 0) {
                cellProgress = func_002a2cd0((u8 *)cellTween);
                cellRowY = (f32)((i % 6) * 0x19 + 0xE3);
                cellY = cellRowY;
                alpha2 = (u8)(255.0f * cellProgress);
                sdkSpriteDrawNowUnscaled((f32)((i / 6) * 0x94 + 0x19), cellY, 0.0f, 0x4972FF, alpha2, 1, iGpffffb540, 1);
                if (i == 0) {
                    sdkSpriteDrawNowUnscaled(18.0f, stack[1], 0.0f, 0x4972FF, alpha2, 0x1B, iGpffffb540, 1);
                }
                if (i == 5) {
                    sdkSpriteDrawNowUnscaled(18.0f, (171.0f + stack[1]) - 24.0f, 0.0f, 0x4972FF, alpha2, 0x1C, iGpffffb540,
                        1);
                }
                if (i == 0x12) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, stack[1], 0.0f, 0x4972FF, alpha2, 0x1D, iGpffffb540, 1);
                }
                if (i == 0x17) {
                    sdkSpriteDrawNowUnscaled((f32)0x24A, (171.0f + stack[1]) - 24.0f, 0.0f, 0x4972FF, alpha2, 0x1E,
                        iGpffffb540, 1);
                }
            }
        }
    }
    if (arg1 >= 2) {
        for (j = 0; j < 6; j++) {
            if (func_002a2ca0((u8 *)&work->rows[j]) == 0) {
                {
                    s32 yBase;
                    u8 *rowBase;
                    i = 0;
                    rowBase = D_007485D0 + (j * 0x28);
                    yBase = (j * 25) + 0xE5;
                    for (; i < 0x14; i++) {
                        character = *(s16 *)(rowBase + (i * 2));
                        if (character >= 0) {
                            s32 tex;
                            tex = character + 0x20;
                            glyphX = (f32)((i % 5) * 0x1B);
                            q = i / 5;
                            switch (q) {
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
                            func_002a2cd0((u8 *)&work->rows[j]);
                            func_002a2c10((u8 *)&work->rows[j], stack);
                            sdkSpriteDrawNowUnscaled(glyphX, glyphY + (f32)(s32)stack[1], 0.0f, 0x2D2D2D, 0xFF, tex,
                                iGpffffb540, 1);
                        }
                    }
                }
            }
        }
    }
}


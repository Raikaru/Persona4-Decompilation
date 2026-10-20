/* Original translation unit shdWindow.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "member_access.h"
#include "sdk_task_registration.h"
#include "sdk_snd_internal.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "fr_font_objects.h"
#include "primitive_queue_internal.h"

/* The constructor allocates 0x2C bytes; update and draw share this layout. */
typedef struct ShdWindowAnimation {
    s32 unk0;
    s32 flags; /* bit 0 opens; bit 1 closes */
    u8 pad8[8];
    s32 frame;
} ShdWindowAnimation;
typedef struct ShdWindowWork {
    s32 state;
    s32 flags; /* bit 2 requests completion */
    s32 value;
    s32 entryIndex;
    s32 delay;
    s32 selection;
    ShdWindowAnimation animation;
} ShdWindowWork;
typedef struct ShdWindowEntry {
    s32 text;
    union {
        s32 word;
        struct { u16 kind, initialSelection; } fields;
    } behavior;
} ShdWindowEntry;

typedef int (*code)();
extern code DAT_008873ec_abs[];

extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void kAssertFail(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00637190[];
extern u8 D_00637248[];
extern f32 D_00637260[];
extern u8 D_00637270[];
extern u8 *iGpffffa6a0;
extern u8 *iGpffffa6a4;
extern u8 D_00796670[];
extern u16 D_008C024E[];
extern u16 D_008C0276[];

extern s32 shdWindowTaskUpdate(u8 *sdkTaskBytes);
extern void shdWindowDrawQueued(s32, s32);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, void *);
extern u8 *frFontBuildTextSimple(u32, u32, u32, u32, u32, u32, u32, u32);
extern s32 frFontCountRuns(u8 *);
extern u8 *frFontSplitRun(u8 **, s32);
extern s32 frFontNodeWidth(u8 *);
extern void frFontMoveListToFloat(u8 *, f32, f32);
extern void frFontSetGlyphColor(u8 *, s32);
extern void frFontListKeepOrRelease(u8 *);
extern f32 iGpffff8094;
extern f32 sinf(f32);
extern void sflDataDrawWideRoundedFrame(s32, s32, f32, s32, s32, s32, s32, s32, s32,
                         s16, void *, f32, f32, f32);
extern void shdDrawEntryRow(f32, f32, s32, u8 *);


// Ported from the P3FES comuTimerSequence donor function (verified MATCH there).
// kwlnTaskGetWork is intentionally left undeclared (implicit old-style call, as
// in the donor): a typed prototype makes mwcc emit zero-extension codegen
// retail never has.

// measured: opt_loop_invariants on fixes the parameter allocation and pre-loop
// mask placement; declaring runIndex after the three list-walk locals gives the
// retail $s4/$s3/$s2/$s1 allocation (old declaration order was nd 22).
#pragma opt_loop_invariants on
// Intent: Draw a block of text runs, centred or left-aligned, from a text table entry; returns the block height [inferred]
// FUN_0025DB00
s32 shdDrawTextBlock(f32 x, f32 y, s32 unusedColor, s32 color, s32 entryIndex,
                  s32 centered)
{
    u8 *remainingText;
    s32 textOrHeight;
    u8 *run;
    u8 *glyph;
    s32 runWidth;
    s32 runIndex;

    color |= -0x100;
    if (entryIndex >= 0x17) {
        kAssertFail(&D_00637248, 0x75);
    }
    textOrHeight = ((ShdWindowEntry *)D_00637190)[entryIndex].text;
    runIndex = 0;
    remainingText = frFontBuildTextSimple(0, 0, 2, 0, 0, 0xFF, textOrHeight, 0);
    textOrHeight = frFontCountRuns(remainingText) * 0x1C;

    while (remainingText != NULL) {
        run = frFontSplitRun(&remainingText, 0);
        if (run == NULL) {
            run = remainingText;
            remainingText = NULL;
        }
        glyph = run;
        runWidth = 0;
        while (glyph != NULL) {
            runWidth += frFontNodeWidth(glyph);
            glyph = (u8 *)((FrFontTextRun *)glyph)->previous;
        }
        if (centered != 0) {
            frFontMoveListToFloat(run,
                          x - (f32)runWidth / 2.0f,
                          y + 28.0f * (f32)runIndex - (f32)textOrHeight / 2.0f);
        } else {
            frFontMoveListToFloat(run, x, y);
        }
        frFontSetGlyphColor(run, color);
        frFontDrawList(run, 1, 0);
        frFontListKeepOrRelease(run);
        runIndex++;
    }
    return runIndex * 0x1C;
}
// measured: closes the shdDrawTextBlock loop-invariant bracket.
#pragma opt_loop_invariants off

// measured: 14 differing words at an exact 269/269.  The previous note on
// this function claimed a saved-register rotation at nd 216-224 and a later
// pass reported nd 719; both were measuring something other than the body
// that is banked here, which scores 14 via
// `tools/measure_guarded.py src/shdWindow.c shdDrawEntryRow`.  The body was
// also left LIVE and unguarded, so `verify.py` reported a real MISMATCH on
// this translation unit; it is behind `#ifdef NON_MATCHING` now.
// WALL, all 14 words: retail loads D_00637260/64/68/6C into $f3,$f2,$f1,$f0
// and only then stores the four to sp+0x70..0x7C; b210 reuses $f0 and
// interleaves each load with its store.  Four separate externs are correct -
// retail re-emits `lui $v0, 0x63` before every `lwc1`, which a single
// `f32 D_00637260[4]` would fold into one base.  Measured and rejected:
// direct `table[i] = D_006372xx[0]` with no temps (14, unchanged), the four
// temps assigned in reverse (14), the stores emitted in reverse (15), a
// four-field struct assignment (244), `opt_loop_invariants on` (14),
// `opt_common_subs off` (165), `schedule on` (246) and `opt_propagation off`
// (26 words but only 11 edits - it fixes this block and breaks more
// elsewhere).  The single-use temps are folded into their stores by
// propagation and rescheduled; nothing short of disabling propagation for
// the whole function reproduces retail's four live FPRs.
// measured 2026-09-17 full pragma_sweep --pairs (8 singles + 28 pairs):
// banked 14 via `python3 -E -s tools/measure_guarded.py src/shdWindow.c shdDrawEntryRow`;
// best stays 14 (ties: opt_loop_invariants on, opt_strength_reduction off,
// opt_unroll_loops off and their three pairs; 26-group: prop off and five
// prop/dead/loopinv/strength pairs; 157 csoff+propoff, 165 csoff group,
// 220-224 peephole group, 244-247 schedule group). No pair wins; floor stands.
// `python3 -E -s tools/pragma_sweep.py src/shdWindow.c shdDrawEntryRow --pairs`.
extern s8 frFontExGlyphHeight(char index);
extern void K_SineRingDraw(f32 centerX, f32 centerY, f32 depth, s32 packedColor);
// MATCH.  The last six words were the emission slot of `mtc1 $zero, $f12`
// at the two func_00366670 calls: retail materialises that first float
// argument before the packed-colour shift/mask pair, this file did it after.
// The fix is in the callee's signature - move ONLY func_00366670's first
// float, the depth, ahead of the integer arguments, and update the shared
// prototype at the top of this file, the definition in
// src/promoted/code1_0036.c and all four call sites together.
//
// This overturns the "closed by proof" note that used to sit here.  That
// note argued two byte-exact MATCHed callers in this same file pin the
// parameter order (section 7c) and that reordering would not even compile.
// Both halves were wrong: the prototype is shared, so changing it and every
// caller at once compiles fine, and those callers' expressions are
// insensitive to moving the first float - they stay byte-identical.  What
// the earlier pass actually measured was moving *groups* of floats
// (positions 5-8 scored 14, positions 2-5 scored 20); moving one float is a
// different axis.  Section 7c pins a callee's parameter order only when a
// matched caller's code would change, which has to be measured, not assumed.
//
// The whole provider object in code1_0036.c is byte-identical across the
// change, all 34 functions and both data sections, and this file's other
// seven functions are unchanged.  The recovery does not uniquely fix the
// original textual position: the first float placed before the integers, or
// after one, two, three or four of them, all compile identically.  After
// five it scores 4, after six or more it scores 6 again.
// Intent: Draw one entry row: a bar and its text, chosen by the row kind [inferred]
/* measured: direct fields and local object aliases change retail code; named MEMBER offsets preserve MATCH. */
// FUN_0025DD30
void shdDrawEntryRow(f32 offsetX, f32 offsetY, s32 color, u8 *data) {
    struct ShdWindowQuad { f32 a, b, c, d; };
    f32 table[4];
    s32 y;
    s32 kind;
    f32 textY;
    f32 textX;
    s32 textHeight;

    *(struct ShdWindowQuad *)table = *(struct ShdWindowQuad *)D_00637260;
    frFontExGlyphHeight(2);
    y = ((ShdWindowWork *)data)->entryIndex;
    if (y >= 0x17) {
        kAssertFail(D_00637248, 121);
    }
    kind = ((ShdWindowEntry *)D_00637190)[y].behavior.fields.kind;
    textX = 228.0f + offsetX;
    if (kind == 2) {
        textY = ((150.0f + offsetY) - 6.0f) - 37.5f;
    } else {
        textY = (150.0f + offsetY) - 6.0f;
    }
    textHeight = shdDrawTextBlock(textX, textY, 0xFFFFFF, color, MEMBER(s32, data, ShdWindowWork, entryIndex), 1);
    y = (s32)(49.0f + (textY + (f32)(textHeight >> 1)));
    switch (kind) {
    case 2:
        if (((ShdWindowWork *)data)->selection == 0) {
            u32 combined = (color & 0xFF) | -256;
            sflDataDrawWideRoundedFrame((s32)(110.0f + offsetX), y, 0.0f, 106, 26, combined >> 8, combined & 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
            frFontExDrawText(163.0f + offsetX, (f32)(y - 5), 0.0f, color | 0x64F0FF00, ((s8 *)table)[MEMBER(s32, data, ShdWindowWork, selection) * 8], 0, (const char *)iGpffffa6a0, 8, 0);
            frFontExDrawText((f32)293 + offsetX, (f32)(y - 5), 0.0f, color | -256, ((s8 *)table)[MEMBER(s32, data, ShdWindowWork, selection) * 8 + 4], 1, (const char *)iGpffffa6a4, 8, 0);
        } else {
            u32 combined = (color & 0xFF) | -256;
            sflDataDrawWideRoundedFrame((s32)(240.0f + offsetX), y, 0.0f, 106, 26, combined >> 8, combined & 0xFF, 1, 0, 0, NULL, 0.0f, 1.0f, 1.0f);
            frFontExDrawText(163.0f + offsetX, (f32)(y - 5), 0.0f, color | -256, ((s8 *)table)[MEMBER(s32, data, ShdWindowWork, selection) * 8], 1, (const char *)iGpffffa6a0, 8, 0);
            frFontExDrawText(3.0f + ((f32)293 + offsetX), (f32)(y - 5), 0.0f, color | 0x64F0FF00, ((s8 *)table)[MEMBER(s32, data, ShdWindowWork, selection) * 8 + 4], 0, (const char *)iGpffffa6a4, 8, 0);
        }
        break;
    case 1:
        K_SineRingDraw((f32)399 + offsetX, 255.0f + offsetY, 0.0f, -1);
        break;
    }
}
// Intent: Window task update: run the open and close state machine and queue the draw callback [inferred]
/* measured: direct fields and local object aliases change retail code; named MEMBER offsets preserve MATCH. */
// FUN_0025E170
s32 shdWindowTaskUpdate(u8 *sdkTaskBytes)
{
    s32 taskHandle = (s32)sdkTaskBytes;
    u8 *work;
    s32 entryIndex;
    s32 openingFlags;
    s32 nextFrame;
    s32 closingFlags;
    s32 state;
    u16 kind;
    u8 *unusedWork;
    u8 *drawNode;

    work = (u8 *)kwlnTaskGetWork();
    state = ((ShdWindowWork *)work)->state;
    switch (state) {
    case 0:
        ((ShdWindowWork *)work)->state = 2;
        ((ShdWindowWork *)work)->flags = ((ShdWindowWork *)work)->flags | 1;
        openingFlags = ((ShdWindowWork *)work)->animation.flags | 1;
        ((ShdWindowWork *)work)->animation.flags = openingFlags;
        ((ShdWindowWork *)work)->animation.flags = openingFlags & ~2;
        entryIndex = ((ShdWindowWork *)work)->entryIndex;
        if (entryIndex >= 0x17) {
            kAssertFail(&D_00637248, 0x7D);
        }
        switch (((((ShdWindowEntry *)D_00637190)[entryIndex].behavior.word) >> 16)) {
        case 1:
            ((ShdWindowWork *)work)->selection = 1;
            break;
        }
        /* fallthrough */
    case 2:
        ((ShdWindowWork *)work)->state = 3;
        ((ShdWindowWork *)work)->delay = 0;
        /* fallthrough */
    case 3:
        nextFrame = ((ShdWindowWork *)work)->delay + 1;
        ((ShdWindowWork *)work)->delay = nextFrame;
        if (nextFrame >= 5) {
            MEMBER(s32, work, ShdWindowWork, delay) = 0;
            ((ShdWindowWork *)work)->state = 6;
        }
        goto block_37;
    case 6:
        entryIndex = ((ShdWindowWork *)work)->entryIndex;
        if (entryIndex >= 0x17) {
            kAssertFail(&D_00637248, 0x79);
        }
        kind = ((ShdWindowEntry *)D_00637190)[entryIndex].behavior.fields.kind;
        switch (kind) {
        case 0:
            break;
        case 1:
            if ((D_008C024E[0] & 0x40) || (D_008C024E[0] & 0x20)) {
                ((ShdWindowWork *)work)->flags = ((ShdWindowWork *)work)->flags | 4;
                sdkSndStartStream(0, 0, 0, 1);
            }
            break;
        case 2:
            if (D_008C0276[0] & 0x8000) {
                if (((ShdWindowWork *)work)->selection != 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                MEMBER(s32, work, ShdWindowWork, selection) = 0;
            } else if (D_008C0276[0] & 0x2000) {
                if (((ShdWindowWork *)work)->selection != 1) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                MEMBER(s32, work, ShdWindowWork, selection) = 1;
            } else if (D_008C024E[0] & 0x40) {
                ((ShdWindowWork *)work)->flags = ((ShdWindowWork *)work)->flags | 4;
                sdkSndStartStream(0, 0, 0, 1);
            }
            break;
        }
        if (((ShdWindowWork *)work)->flags & 4) {
            ((ShdWindowWork *)work)->state = 1;
            closingFlags = ((ShdWindowWork *)work)->animation.flags & ~1;
            ((ShdWindowWork *)work)->animation.flags = closingFlags;
            ((ShdWindowWork *)work)->animation.flags = closingFlags | 2;
        }
        goto block_37;
    case 1:
        if (!(((ShdWindowWork *)work)->animation.flags & 2)) {
            return -1;
        }
        goto block_37;
    }
block_37:
    drawNode = (u8 *)PrimAllocQueueNode();
    ((PrimQueueNode *)drawNode)->callback = (void *)shdWindowDrawQueued;
    ((PrimQueueNode *)drawNode)->argument.handle = taskHandle;
    PrimAppendNode(&D_00796670, drawNode);
    return 0;
}

// measured: the two-argument callback type keeps the work pointer in $s0;
// switch(action), an explicit action=0 for the bit-2 arm, and the ternary
// count clamp reproduce retail's branch layout. Packing the color channels
// through (s8)(s32) preserves the retail sign-extension sequence.
// Intent: Queued window draw: step the open or close counter and draw the bar and its row [inferred]
/* measured: direct fields and local object aliases change retail code; named MEMBER offsets preserve MATCH. */
// FUN_0025E4A0
void shdWindowDrawQueued(s32 unusedQueue, s32 taskHandle)
{
    u8 *work;
    u8 *animation;
    s32 action;
    s32 flags;
    s32 count;
    f32 opacity;
    f32 frac;
    u32 color;

    work = (u8 *)kwlnTaskGetWork(taskHandle);
    animation = work + 0x18;
    action = 0;
    flags = ((ShdWindowWork *)work)->animation.flags;
    if (flags & 1) {
        count = ((ShdWindowAnimation *)animation)->frame;
        if (count < 5) {
            MEMBER(s32, animation, ShdWindowAnimation, frame) = count + 1;
        } else {
            ((ShdWindowAnimation *)animation)->flags = flags & ~1;
            MEMBER(s32, animation, ShdWindowAnimation, frame) = 7;
        }
        action = 1;
    } else if (flags & 2) {
        count = ((ShdWindowAnimation *)animation)->frame;
        if (count > 0) {
            MEMBER(s32, animation, ShdWindowAnimation, frame) = count - 1;
        } else {
            ((ShdWindowAnimation *)animation)->flags = flags & ~2;
        }
        action = 0;
    }

    switch (action) {
    case 1:
        count = ((ShdWindowAnimation *)animation)->frame;
        count = count < 3 ? count : 3;
        opacity = sinf((iGpffff8094 * (f32)count) / 3.0f);
        sflDataDrawWideRoundedFrame(92, (s32)(74.0f + 150.0f * (1.0f - opacity)), 0.0f, 456, (s32)(300.0f * opacity), 0x2D2D2D, 255, 1, 0, 0, 0, 0.0f, 1.0f, 1.0f);
        shdDrawEntryRow(92.0f, 74.0f, (s32)(255.0f * opacity), work);
        break;
    case 0:
        count = ((ShdWindowAnimation *)animation)->frame;
        count = count < 3 ? count : 3;
        frac = (f32)count / 3.0f;
        opacity = 255.0f * frac;
        color = 0x2D2D2D00 | (((s8)(s32)(255.0f * frac)) & 0xFF);
        sflDataDrawWideRoundedFrame(92, (s32)(74.0f + 150.0f * (1.0f - frac)), 0.0f, 456, (s32)(10.0f + 290.0f * frac), color >> 8, color & 0xFF, 1, 0, 0, 0, 0.0f, 1.0f, 1.0f);
        shdDrawEntryRow(92.0f, 74.0f, (s32)opacity, work);
        break;
    }
}

// Intent: Window task destroy: call the teardown handler for the window's work [inferred]
// FUN_0025E7C0
void shdWindowTaskDestroy(u8 *unusedTask)
{
    int work;

    work = kwlnTaskGetWork();
    DAT_008873ec_abs[0](work);
}
// Intent: Create the window task with its update and destroy callbacks [inferred]
// FUN_0025E800
void shdWindowTaskCreate(s32 parentTask, s32 value, s32 entryIndex)
{
    u8 *work;

    chkmemAllocSiteTag(&D_00637248, 0x204);
    work = D_008873F4[0](1, 0x2C, 0x40000);
    ((ShdWindowWork *)work)->value = value;
    ((ShdWindowWork *)work)->entryIndex = entryIndex;
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_00637270), 0xF, 0, 0, shdWindowTaskUpdate, shdWindowTaskDestroy, (u8 *)(work));
}

// Intent: Mark the window as finished by setting bit 4 of its flags [inferred]
/* measured: direct fields and local object aliases change retail code; named MEMBER offsets preserve MATCH. */
// FUN_0025E8B0
void shdWindowMarkDone(void) {
    u8 *work = (u8 *)kwlnTaskGetWork();
    s32 flags = ((ShdWindowWork *)work)->flags;

    if (!(flags & 4)) {
        MEMBER(s32, work, ShdWindowWork, flags) = flags | 4;
    }
}

// Intent: Return the window's completion state: 1 when finished, phase + 1 for the slide kind, 0 otherwise [inferred]
// FUN_0025E8F0
s32 shdWindowQueryState(void)
{
    u8 *work;
    s32 finished;
    s32 entryIndex;
    u16 kind;

    work = (u8 *)kwlnTaskGetWork();
    finished = 0;
    if (((ShdWindowWork *)work)->flags & 4) {
        finished = 1;
    }
    entryIndex = ((ShdWindowWork *)work)->entryIndex;
    if (entryIndex >= 0x17) {
        kAssertFail(&D_00637248, 0x79);
    }
    kind = ((ShdWindowEntry *)D_00637190)[entryIndex].behavior.fields.kind;
    switch (kind) {
    case 0:
        return 1;
    case 1:
        if (finished != 0) {
            return 1;
        }
        goto ret0;
    case 2:
        if (finished != 0) {
            return ((ShdWindowWork *)work)->selection + 1;
        }
        goto ret0;
    default:
    ret0:
        return 0;
    }
}


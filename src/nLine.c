#include "operand_order_internal.h"
#include "mdl_effect_internal.h"
#include "nline_vertex_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
/* Original translation unit nLine.c (from __FILE__ assert strings). */
#include "type.h"

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

/* Compact defaults use 0x14-byte rows; each set has twenty 0x30-byte animation rows; live records
 * are 0x54 bytes with float slots also written as words. */
typedef union NLineValue { f32 value; s32 bits; u32 unsignedBits; } NLineValue;
typedef struct NLineRecord {
    NLineValue targetX, targetY;
    NLineValue x, y;
    NLineValue deltaX, deltaY;
    NLineValue startX, startY;
    NLineValue targetAlpha, alpha, deltaAlpha, startAlpha;
    NLineValue targetExtent, extent, deltaExtent, startExtent, midExtent;
    s32 midpointReached;
    s16 colorIndex;
    u8 pad4A[2];
    NLineValue startFrame, endFrame;
} NLineRecord;
typedef struct NLineDefault {
    f32 x, y;
    s16 colorIndex;
    u8 pad0A[2];
    f32 alpha, extent;
} NLineDefault;
typedef struct NLineAnimation {
    f32 startX, startY, targetX, targetY;
    f32 startExtent, midExtent, targetExtent;
    s16 colorIndex;
    u8 pad1E[2];
    f32 startAlpha, targetAlpha, startFrame, endFrame;
} NLineAnimation;
typedef struct {
    s16 count;
    s32 colors[5];
    f32 offsets[5];
} NLineDecorationStyle;

typedef struct NLineSet {
    u8 flags;
    u8 pad01[3];
    f32 duration;
    s16 orientation, kind, effect, style;
} NLineSet;
/* D_007523C4/C8/CA/CC/CE are interior aliases; subtract the member offset at those casts to recover
 * the set base. */

/* Vertex buffers are byte-addressed because nLineSetLayer owns their 0x40-byte native layout. */
typedef struct NLineBatch {
    u8 frameVertices[0x100];
    u8 triangleVertices[0x100];
    u8 effectVertices[0x100];
    s32 triangleEnabled;
    u8 alpha;
    u8 pad305;
    s16 effect;
    s16 style;
    s16 hiddenLayer;
    Vec2f origin;
    u8 pad314[0xC];
    u8 decorationVertices[0xCC0];
    s16 vertexCount;
    u8 padFE2[0xE];
} NLineBatch;
typedef struct NLineTable {
    NLineRecord records[20];
    NLineBatch batch;
    s32 setIndex;
    s16 elapsed;
    u8 pad1686[2];
    f32 duration;
    f32 unk168C;
    s32 immediate;
    s32 active;
    u8 pad1698[8];
} NLineTable;
typedef char NLineRecordSize[sizeof(NLineRecord) == 0x54 ? 1 : -1];
typedef char NLineAnimationSize[sizeof(NLineAnimation) == 0x30 ? 1 : -1];
typedef char NLineTableSize[sizeof(NLineTable) == 0x16A0 ? 1 : -1];


extern s32 (*D_00887310[])(s32, void *, s32);
extern void (*D_00887300[])(s32, s32);
extern s32 D_00882FC0[];
extern void (*D_00882FC8[])(void);
extern s32 D_00882FD0[];
extern u8 D_00882FF0[];
extern s16 D_00883988[];
extern s16 D_00884660[];
extern f32 D_0088466C[];
extern s32 D_00884670[];
extern s16 D_00884674[];
extern f32 D_00884678[];
extern f32 D_0088467C[];
extern s32 D_00884680[];
extern s32 D_00884684[];
extern f32 D_008872F8[];
extern u8 D_00752600[];
extern u8 D_00749AC0[];
extern u8 D_00749B30[];
extern u8 D_00749CC0[];
extern u8 D_00749840[];
extern u8 D_007523C0[];
extern u8 D_007523C4[];
extern u8 D_007523C8[];
extern u8 D_007523CA[];
extern u8 D_007523CC[];
extern u8 D_007523CE[];
extern u8 D_007525D4[];
/* gp - 0x4A5C = 0x00764694, GP-relative s16. */
extern s16 iGpffffb5a4;
/* gp - 0x56B0 = 0x00763A40, GP-relative assert string. */
extern char iGpffffa950;
/* gp - 0x56B8 = 0x00763A38, GP-relative name string. */
extern char iGpffffa948;
/* gp - 0x7F6C = 0x00761184, GP-relative f32. */
extern f32 iGpffff8094;
extern f32 fGpffff84a4;
/* gp - 0x7DE0 = 0x00761310, GP-relative f32. */
extern f32 iGpffff8220;

s32 nLineRefreshTask(u8 *unusedTask);
void nLineDrawOriginCallback(void);
void nLineSetDefaultDuration(void);
void nLineInitRecords(void);
void nLineDrawRecords(NLineTable *table, Vec2f position, s32 alpha);
void nLineEmitQuad(u8 *vertices, f32 x, f32 y, f32 width, f32 height, u8 *color);
void nLineFlushLayer(u8 *vertices);
void nLineDrawEffect(u8 *table, Vec2f position, s32 alpha);
void nLineDrawBatch(NLineBatch *batch);
s16 nLineRollStyle(u8 *table, s32 setIndex);
s32 nLineBuildDecoration(u8 *table, f32 x, f32 y, f32 width, f32 height);
void nLineDrawLayers(u8 *work, f32 originX, f32 originY, f32 amount);
u32 RpRandom(void);
void shdEnableBlendFlag(void);
void shdDisableBlendFlag(void);
void RpSkyRenderStateSet(s32, s32);
s32 kwlnGetCamera(void);
f32 sinf(f32);
f32 cosf(f32);

void kAssertFail(void *file, s32 line);
void memset(void *dest, s32 value, s32 size);
void nLineSetRenderStateBase(void);

void nLineDrawFrameAt(u8 *table, f32 offsetX, f32 offsetY, f32 amount);
void nLineDrawFullFrame(u8 *table);
void nLineSweepHorizontal(u8 *table, s32 entering);
void nLineSweepHorizontalAlt(u8 *table, s32 entering);
void nLineSweepVertical(u8 *table, s32 entering);
void nLineSweepVerticalAlt(u8 *table, s32 entering);
void nLineDrawWaveStrip(u8 *table, s32 entering);
void nLineDrawBand(u8 *table, s32 entering);
void nLineDrawScaledFrame(NLineTable *table, f32 durationScale, s32 entering);


// Creates the line-effect refresh task, resets its records and selects the default set; returns the
// task.
// FUN_0034B970
s32 nLineInit(void) {
    s32 task;

    task = (s32)kwlnTaskCreate((const void *)(&iGpffffa948), 0xC7, 0, 0, nLineRefreshTask, 0, (u8 *)(0));
    if (task == 0) {
        kAssertFail(&iGpffffa950, 0x168);
    }
    memset(D_00882FC0, 0, 0x30);
    D_00882FC8[0] = nLineDrawOriginCallback;
    D_00882FD0[0] = 0;
    nLineSetDefaultDuration();
    nLineInitRecords();
    return task;
}

// Sets the default duration of the line effect to 0xB0 frames.
// FUN_0034BA20
void nLineSetDefaultDuration(void) {
    iGpffffb5a4 = 0xB0;
}

/* measured: retail builds the row pointers inside the loop with invariants hoisted, storing to the
 * destination before reading the source. */
#pragma opt_loop_invariants on
// Fills the 20 layer records from the compact defaults table; the untouched fields keep their
// values.
// FUN_0034BA30
void nLineInitRecords(void) {
    u8 *record;
    u8 *defaults;
    s32 recordIndex;
    f32 x;
    f32 y;
    f32 alpha;
    f32 extent;

    D_00884670[0] = 0;
    D_00884674[0] = 0;
    D_00884678[0] = 0;
    D_00884680[0] = 0;
    D_00884684[0] = 0;
    for (recordIndex = 0; recordIndex < 20; recordIndex++) {
        record = D_00882FF0 + recordIndex * 84;
        defaults = D_00749B30 + recordIndex * 20;
        x = ((NLineDefault *)defaults)->x;
        ((NLineRecord *)record)->startX.value = x;
        ((NLineRecord *)record)->x.value = x;
        ((NLineRecord *)record)->targetX.value = x;
        y = ((NLineDefault *)defaults)->y;
        ((NLineRecord *)record)->startY.value = y;
        ((NLineRecord *)record)->y.value = y;
        ((NLineRecord *)record)->targetY.value = y;
        alpha = ((NLineDefault *)defaults)->alpha;
        ((NLineRecord *)record)->startAlpha.value = alpha;
        ((NLineRecord *)record)->alpha.value = alpha;
        ((NLineRecord *)record)->targetAlpha.value = alpha;
        extent = ((NLineDefault *)defaults)->extent;
        ((NLineRecord *)record)->extent.value = extent;
        ((NLineRecord *)record)->targetExtent.value = extent;
        ((NLineRecord *)record)->colorIndex = ((NLineDefault *)defaults)->colorIndex;
        ((NLineRecord *)record)->startFrame.bits = 0;
        ((NLineRecord *)record)->deltaX.bits = 0;
        ((NLineRecord *)record)->deltaY.bits = 0;
    }
}
/* measured: restores the unit setting after the preceding loop-invariant function. */
#pragma opt_loop_invariants off

// Returns the index of the currently selected line set.
// FUN_0034BB10
s32 nLineGetCurrentSet(void) {
    return D_00884670[0];
}

// Selects line set setIndex (0 to 0x23), rebuilds the 20 records from its table, and starts it.
// Returns 1 when the set changed.
// FUN_0034BB20
s32 nLineSelectSet(s32 setIndex) {
    s32 i;
    s32 setOffset;
    u8 *srcBase;
    u8 *dstBase;
    f32 duration;
    f32 value;
    f32 midExtent;
    u8 *record;
    u8 *animation;

    if (D_00884670[0] != setIndex) {
        if (setIndex == 0) {
            D_00884670[0] = setIndex;
            D_00884674[0] = 0;
            D_00884678[0] = ((NLineSet *)(D_007523C4 + setIndex * 0x10 - 4))->duration;
            D_00884680[0] = 0;
            return 1;
        }
        if ((setIndex >= 0) && (setIndex < 0x24)) {
            i = 0;
            setOffset = setIndex * 0x10;
            srcBase = D_00749CC0 + setIndex * 0x3C0;
            duration = ((NLineSet *)(D_007523C0 + setOffset))->duration;
            dstBase = D_00882FF0;
            for (; i < 0x14; i++) {
                record = dstBase + i * 0x54;
                animation = srcBase + i * 0x30;
                ((NLineRecord *)record)->targetX.value = ((NLineAnimation *)animation)->targetX;
                ((NLineRecord *)record)->targetY.value = ((NLineAnimation *)animation)->targetY;
                value = ((NLineAnimation *)animation)->startX;
                ((NLineRecord *)record)->startX.value = value;
                ((NLineRecord *)record)->x.value = value;
                value = ((NLineAnimation *)animation)->startY;
                ((NLineRecord *)record)->startY.value = value;
                ((NLineRecord *)record)->y.value = value;
                ((NLineRecord *)record)->deltaX.value = ((NLineRecord *)record)->targetX.value - ((NLineRecord *)record)->startX.value;
                ((NLineRecord *)record)->deltaY.value = ((NLineRecord *)record)->targetY.value - ((NLineRecord *)record)->startY.value;
                ((NLineRecord *)record)->startExtent.value = ((NLineAnimation *)animation)->startExtent;
                midExtent = ((NLineAnimation *)animation)->midExtent;
                ((NLineRecord *)record)->midExtent.value = midExtent;
                ((NLineRecord *)record)->deltaExtent.value = midExtent - ((NLineRecord *)record)->startExtent.value;
                ((NLineRecord *)record)->targetExtent.value = ((NLineAnimation *)animation)->targetExtent;
                ((NLineRecord *)record)->midpointReached = 0;
                ((NLineRecord *)record)->colorIndex = ((NLineAnimation *)animation)->colorIndex;
                ((NLineRecord *)record)->targetAlpha.value = ((NLineAnimation *)animation)->targetAlpha;
                value = ((NLineAnimation *)animation)->startAlpha;
                ((NLineRecord *)record)->alpha.value = value;
                ((NLineRecord *)record)->startAlpha.value = value;
                ((NLineRecord *)record)->deltaAlpha.value = ((NLineRecord *)record)->targetAlpha.value - ((NLineRecord *)record)->startAlpha.value;
                ((NLineRecord *)record)->startFrame.value = duration * ((NLineAnimation *)animation)->startFrame;
                ((NLineRecord *)record)->endFrame.value = duration * ((NLineAnimation *)animation)->endFrame;
            }
            D_00884660[0] = 0;
            D_00883988[0] = nLineRollStyle(D_00882FF0, setIndex);
            D_00884670[0] = setIndex;
            D_00884674[0] = 0;
            D_00884678[0] = ((NLineSet *)(D_007523C4 + setOffset - 4))->duration;
            D_00884680[0] = 0;
            return 1;
        }
        kAssertFail(&iGpffffa950, 0x1F2);
    }
    return 0;
}

// Selects line set setIndex like nLineSelectSet, but with the immediate flag set and the full-alpha
// record defaults.
// FUN_0034BD60
/* measured: retail hoists the 5.0f constant out of the loop into the preheader; without loop-
 * invariant hoisting it is rebuilt inside the loop. */
#pragma opt_loop_invariants on
s32 nLineSelectSetImmediate(s32 setIndex) {
    s32 i;
    u8 *srcBase;
    u8 *dstBase;
    u8 *record;
    u8 *animation;
    u32 fiveBits;

    if ((D_00884670[0] != setIndex) && (setIndex >= 0) && (setIndex < 0x24)) {
        i = 0;
        srcBase = D_00749CC0 + setIndex * 0x3C0;
        dstBase = D_00882FF0;
        fiveBits = 0x40A00000;
        for (; i < 0x14; i++) {
            f32 value;
            record = dstBase + i * 0x54;
            animation = srcBase + i * 0x30;

            value = ((NLineAnimation *)animation)->targetX;
            ((NLineRecord *)record)->targetX.value = value;
            ((NLineRecord *)record)->x.value = value;
            ((NLineRecord *)record)->startX.value = value;
            value = ((NLineAnimation *)animation)->targetY;
            ((NLineRecord *)record)->targetY.value = value;
            ((NLineRecord *)record)->y.value = value;
            ((NLineRecord *)record)->startY.value = value;
            ((NLineRecord *)record)->deltaX.bits = 0;
            ((NLineRecord *)record)->deltaY.bits = 0;
            ((NLineRecord *)record)->deltaExtent.bits = 0;
            value = ((NLineAnimation *)animation)->targetExtent;
            ((NLineRecord *)record)->targetExtent.value = value;
            ((NLineRecord *)record)->midExtent.value = value;
            ((NLineRecord *)record)->startExtent.value = value;
            ((NLineRecord *)record)->extent.value = value;
            ((NLineRecord *)record)->colorIndex = ((NLineAnimation *)animation)->colorIndex;
            ((NLineRecord *)record)->alpha.bits = 0;
            ((NLineRecord *)record)->startAlpha.bits = 0;
            ((NLineRecord *)record)->targetAlpha.value = ((NLineAnimation *)animation)->targetAlpha;
            ((NLineRecord *)record)->deltaAlpha.value = ((NLineAnimation *)animation)->targetAlpha - ((NLineRecord *)record)->alpha.value;
            ((NLineRecord *)record)->startFrame.bits = 0;
            ((NLineRecord *)record)->endFrame.unsignedBits = fiveBits;
        }
        D_00884660[0] = 0;
        D_00884670[0] = setIndex;
        D_00884674[0] = 0;
        *(u32 *)&D_00884678[0] = fiveBits;
        D_00884680[0] = 1;
        return 1;
    }
    return 0;
}
/* measured: restores the unit setting after func_0034bd60. */
#pragma opt_loop_invariants off

/* measured: retail masks the byte before widening it to wrap, which keeps its load, counter-init
 * and mask order. Per-frame update of the selected set: advances each of the 20 records' sine
 * easing and wraps their positions. */
/* Advance the frame counter and update the sine-eased position, alpha and extent of each of the 20
 * line records, wrapping them if the current set has its wrap flag set. */
// FUN_0034BEA0
void nLineWrapRecord(u8 *record);
void nLineUpdate(void) {
    f32 extentEase;
    f32 elapsed;
    f32 positionEase;
    f32 angle;
    f32 fraction;
    f32 startFrame;
    s32 wrap;
    s32 recordOffset;
    s32 recordIndex;
    NLineRecord *record;
    u8 flags;

    if ((D_00884684[0] == 0) || (D_00884670[0] == 0)) {
        kAssertFail(&iGpffffa950, 0x235);
    }
    if ((f32)D_00884674[0] < D_00884678[0]) {
        D_00884674[0] += 1;
    }
    flags = ((NLineSet *)(D_007523C0 + D_00884670[0] * 0x10))->flags;
    recordIndex = 0;
    flags &= 1;
    wrap = flags;
    for (; recordIndex < 0x14; recordIndex++) {
        recordOffset = recordIndex * 0x54;
        record = (NLineRecord *)(D_00882FF0 + recordOffset);
        startFrame = record->startFrame.value;
        elapsed = (f32)D_00884674[0];
        if (elapsed < startFrame) {
            positionEase = 0.0f;
            extentEase = positionEase;
        } else if (elapsed < record->endFrame.value) {
            elapsed = elapsed - startFrame;
            extentEase = record->endFrame.value - startFrame;
            fraction = elapsed / extentEase;
            angle = fGpffff84a4 * fraction;
            positionEase = sinf(angle);
            if (fraction < 0.5f) {
                extentEase = sinf(2.0f * angle);
            } else {
                if (record->midpointReached == 0) {
                    record->startExtent.value = record->midExtent.value;
                    record->deltaExtent.value = record->targetExtent.value - record->midExtent.value;
                    record->midpointReached = 1;
                }
                extentEase = sinf(2.0f * angle - fGpffff84a4);
            }
        } else {
            positionEase = 1.0f;
            extentEase = positionEase;
        }
        record->x.value = record->startX.value + record->deltaX.value * positionEase;
        record->y.value = record->startY.value + record->deltaY.value * positionEase;
        record->alpha.value = record->startAlpha.value + record->deltaAlpha.value * positionEase;
        record->extent.value = record->startExtent.value + record->deltaExtent.value * extentEase;
        if (wrap != 0) {
            nLineWrapRecord((u8 *)record);
        }
    }
}
// Wraps one record's position into the 640 by 448 screen by adding or subtracting the screen size.
// FUN_0034C120
void nLineWrapRecord(u8 *record) {
    f32 coordinate = ((NLineRecord *)record)->x.value;

    if (coordinate < 0.0f) {
        ((NLineRecord *)record)->targetX.value += 640.0f;
        ((NLineRecord *)record)->startX.value += 640.0f;
    } else if (!(coordinate < 640.0f)) {
        ((NLineRecord *)record)->targetX.value -= 640.0f;
        ((NLineRecord *)record)->startX.value -= 640.0f;
    }
    coordinate = ((NLineRecord *)record)->y.value;
    if (coordinate < 0.0f) {
        ((NLineRecord *)record)->targetY.value += 448.0f;
        ((NLineRecord *)record)->startY.value += 448.0f;
        return;
    }
    if (!(coordinate < 448.0f)) {
        ((NLineRecord *)record)->targetY.value -= 448.0f;
        ((NLineRecord *)record)->startY.value -= 448.0f;
    }
}


// Returns 1 when no set is selected or the selected set has finished its duration.
// FUN_0034C210
s32 nLineIsIdle(void) {
    if ((D_00884670[0] == 0) || !((f32)D_00884674[0] < D_00884678[0])) {
        return 1;
    }
    return 0;
}

// Sets the active flag of the line effect.
// FUN_0034C260
void nLineSetActive(s32 active) {
    D_00884684[0] = active;
}

/* measured: the 64-bit position argument is spilled and its two words read as floats in the loop,
 * which needs loop-invariant hoisting enabled. */
/* Build a temporary table of line records for setIndex positioned around position and scaled by
 * alpha, then draw it with depthOffset applied. */
// FUN_0034C270
/* measured: retail hoists the unsigned opacity conversion out of the loop, which needs loop-
 * invariant hoisting. */
#pragma opt_loop_invariants on
void nLineDrawSet(Vec2f position, s32 alpha, s32 setIndex, f32 depthOffset) {
    u8 table[0x16A0];
    s32 opacity;
    f32 originY;
    f32 originX;
    f32 maxAlpha;
    f32 *srcBase;
    s32 i;
    u8 *record;
    f32 *animation;
    f32 opacityFloat;
    f32 scaledAlpha;
    f32 recordAlpha;
    u8 alphaByte;

    opacity = alpha;
    srcBase = (f32 *)(D_00749CC0 + setIndex * 0x3C0);
    D_0088467C[0] = depthOffset;
    memset(table, 0, 0x16A0);
    if ((setIndex <= 0) || (setIndex >= 0x24)) {
        kAssertFail(&iGpffffa950, 0x2B8);
    }
    ((NLineTable *)table)->setIndex = setIndex;
    ((NLineTable *)table)->elapsed = (s16)(s32)(((NLineSet *)(D_007523C4 + setIndex * 0x10 - 4))->duration);
    i = 0;
    originY = position.y;
    originX = position.x;
    maxAlpha = 255.0f;
    for (; i < 0x14; i++) {
        record = table + i * 0x54;
        animation = srcBase + i * 0xC;
        ((NLineRecord *)record)->x.value = originX + ((NLineAnimation *)animation)->targetX;
        ((NLineRecord *)record)->y.value = originY + ((NLineAnimation *)animation)->targetY;
        ((NLineRecord *)record)->extent.value = ((NLineAnimation *)animation)->targetExtent;
        ((NLineRecord *)record)->colorIndex = ((NLineAnimation *)animation)->colorIndex;
        opacityFloat = (f32)(u32)opacity;
        scaledAlpha = (opacityFloat * ((NLineAnimation *)animation)->targetAlpha) / maxAlpha;
        alphaByte = (u8)scaledAlpha;
        recordAlpha = (f32)alphaByte;
        ((NLineRecord *)record)->alpha.value = recordAlpha;
    }
    nLineDrawRecords((NLineTable *)table, position, opacity);
    D_0088467C[0] = 0.0f;
}
/* measured: restores the unit setting after the preceding draw function. */
#pragma opt_loop_invariants off
// Draws the current record table at the origin.
// FUN_0034C4A0
void nLineDrawCurrent(void) {
    Vec2f origin;
    u8 *clearCursor = (u8 *)&origin;
    s32 remaining = 8;

    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor++;
            remaining--;
        } while (remaining != 0);
    }
    nLineDrawRecords((NLineTable *)D_00882FF0, origin, 0xFF);
}

/* Draws the 20 records of a table at the given position and alpha, one quad per record. Position is
 * passed by value as a Vec2f, as in retail. */
// FUN_0034C500
void nLineDrawRecords(NLineTable *table, Vec2f position, s32 alpha) {
    u8 bytes[4];
    u8 vertices[0x100];
    f32 x;
    f32 y;
    f32 width;
    f32 height;
    s32 recordIndex;
    u8 blue;
    u8 red;
    u8 green;
    u8 opacity;
    u8 *color;
    u8 *record;

    nLineSetRenderStateBase();
    if (((NLineSet *)(D_007523CA + (table->setIndex * 0x10) - 0xA))->kind != 0) {
        nLineDrawEffect((u8 *)table, position, alpha);
        nLineDrawBatch((NLineBatch *)((u8 *)table + 0x690));
    }
    recordIndex = 0;
    for (; recordIndex < 0x14; recordIndex++) {
        record = (u8 *)table + (recordIndex * 0x54);
        x = ((NLineRecord *)record)->x.value;
        y = ((NLineRecord *)record)->y.value;
        if (((NLineSet *)(D_007523C0 + (table->setIndex * 0x10)))->orientation == 0) {
            height = 448.0f;
            width = ((NLineRecord *)record)->extent.value;
        } else {
            height = ((NLineRecord *)record)->extent.value;
            width = 640.0f;
        }
        color = D_00749840 + (((NLineRecord *)record)->colorIndex * 4);
        red = color[0];
        if ((s32)red < 0) {
            red = 0;
        }
        green = color[1];
        if ((s32)green < 0) {
            green = 0;
        }
        blue = color[2];
        if ((s32)blue < 0) {
            blue = 0;
        }
        bytes[0] = red;
        bytes[1] = green;
        bytes[2] = blue;
        opacity = (u8)((NLineRecord *)record)->alpha.value;
        bytes[3] = opacity;
        nLineEmitQuad(vertices, x, y, width, height, bytes);
        nLineFlushLayer(vertices);
    }
}

/* nLineSetLayer takes floats first: (u8 *, f32, f32, f32, f32, u8, u8, u8, u8). Emits one quad as
 * four layer vertices at the position with the given size and colour. */
// FUN_0034C6C0
void nLineEmitQuad(u8 *vertices, f32 x, f32 y, f32 width, f32 height, u8 *color) {
    f32 z;
    f32 scale;

    z = D_008872F8[0] - D_0088467C[0];
    scale = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    nLineSetLayer(vertices, x, y, z, scale, color[0], color[1], color[2], color[3]);
    nLineSetLayer(vertices + 0x40, x, y + height, z, scale, color[0], color[1], color[2], color[3]);
    nLineSetLayer(vertices + 0x80, x + width, y + height, z, scale, color[0], color[1], color[2], color[3]);
    nLineSetLayer(vertices + 0xC0, x + width, y, z, scale, color[0], color[1], color[2], color[3]);
}


// Flushes the 4-vertex layer queued in the given buffer.
// FUN_0034C820
void nLineFlushLayer(u8 *vertices) {
    D_00887310[0](5, vertices, 4);
}


/* Draws the record table's effect for its kind: edge sweeps, frames, decoration and the 640 by 448
 * window. */
// FUN_0034C860
void nLineDrawEffect(u8 *table, Vec2f position, s32 alpha) {
    s32 offset;
    s16 kind;
    s16 effect;
    f32 width1;
    f32 y1;
    f32 z1;
    f32 q1;
    f32 x1;
    f32 extent2;
    f32 width2;
    f32 y2;
    f32 x2;
    f32 z2;
    f32 q2;
    f32 right2;
    f32 start;
    f32 elapsed;
    f32 width3;
    f32 y3;
    f32 x3;
    f32 z3;
    f32 q3;
    f32 right3;
    u8 alpha1;
    u8 alpha2;
    u8 alpha3;

    offset = ((NLineTable *)table)->setIndex * 0x10;
    kind = ((NLineSet *)(D_007523CA + offset - 0xA))->kind;
    effect = ((NLineSet *)(D_007523CC + offset - 0xC))->effect;
    ((NLineTable *)table)->batch.effect = effect;
    ((NLineTable *)table)->batch.origin = position;
    ((NLineTable *)table)->batch.alpha = alpha;
    switch (kind) {
    case 0: break;
    case 1: nLineDrawFullFrame(table); break;
    case 2: nLineSweepHorizontal(table, 1); break;
    case 3: nLineSweepHorizontalAlt(table, 1); break;
    case 4: nLineSweepVertical(table, 1); break;
    case 5: nLineSweepVerticalAlt(table, 1); break;
    case 6: nLineDrawWaveStrip(table, 1); break;
    case 7: nLineSweepHorizontal(table, 0); break;
    case 8: nLineSweepHorizontalAlt(table, 0); break;
    case 9: nLineSweepVertical(table, 0); break;
    case 10: nLineSweepVerticalAlt(table, 0); break;
    case 11: nLineDrawWaveStrip(table, 0); break;
    case 12: nLineDrawBand(table, 1); break;
    case 13: nLineDrawBand(table, 0); break;
    case 14: nLineDrawScaledFrame((NLineTable *)table, 0.5f, 1); break;
    case 15: nLineDrawScaledFrame((NLineTable *)table, 0.5f, 0); break;
    case 16: nLineDrawScaledFrame((NLineTable *)table, 1.0f, 1); break;
    case 17: nLineDrawScaledFrame((NLineTable *)table, 1.0f, 0); break;
    default: kAssertFail(&iGpffffa950, 0x3A9); break;
    }
    switch ((s64)effect) {
    case 0: break;
    case 1:
        width1 = ((NLineRecord *)table)->x.value - position.x;
        y1 = position.y;
        z1 = D_008872F8[0] - D_0088467C[0];
        q1 = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
        alpha1 = alpha & 0xFF;
        nLineSetLayer(table + 0x890, position.x, y1, z1, q1, 255, 255, 129, alpha1);
        nLineSetLayer(table + 0x8D0, position.x, operandOrderAddFloat(y1, 448.0f), z1, q1, 255, 255, 129, alpha1);
        x1 = position.x + width1;
        nLineSetLayer(table + 0x910, x1, operandOrderAddFloat(y1, 448.0f), z1, q1, 255, 255, 129, alpha1);
        nLineSetLayer(table + 0x950, x1, y1, z1, q1, 255, 255, 129, alpha1);
        break;
    case 2:
        extent2 = ((NLineTable *)table)->records[19].x.value;
        width2 = operandOrderSubtract((640.0f - extent2), (position.x));
        y2 = position.y;
        x2 = extent2 + position.x;
        z2 = D_008872F8[0] - D_0088467C[0];
        q2 = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
        alpha2 = alpha & 0xFF;
        nLineSetLayer(table + 0x890, x2, y2, z2, q2, 255, 255, 129, alpha2);
        nLineSetLayer(table + 0x8D0, x2, operandOrderAddFloat(y2, 448.0f), z2, q2, 255, 255, 129, alpha2);
        right2 = x2 + width2;
        nLineSetLayer(table + 0x910, right2, operandOrderAddFloat(y2, 448.0f), z2, q2, 255, 255, 129, alpha2);
        nLineSetLayer(table + 0x950, right2, y2, z2, q2, 255, 255, 129, alpha2);
        break;
    case 3:
        if (((NLineTable *)table)->immediate == 0) {
            start = ((NLineRecord *)table)->startFrame.value;
            elapsed = (f32)((NLineTable *)table)->elapsed;
            if (!(elapsed <= start)) {
                width3 = 840.0f * cosf((iGpffff8094 * (elapsed - start)) / (((NLineRecord *)table)->endFrame.value - start));
            } else {
                width3 = 840.0f;
            }
        } else {
            width3 = 0.0f;
        }
        y3 = position.y;
        x3 = position.x + (((NLineRecord *)table)->x.value - width3);
        z3 = D_008872F8[0] - D_0088467C[0];
        q3 = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
        alpha3 = alpha & 0xFF;
        nLineSetLayer(table + 0x890, x3, y3, z3, q3, 255, 255, 129, alpha3);
        nLineSetLayer(table + 0x8D0, x3, operandOrderAddFloat(y3, 448.0f), z3, q3, 255, 255, 129, alpha3);
        right3 = x3 + (width3 - position.x);
        nLineSetLayer(table + 0x910, right3, operandOrderAddFloat(y3, 448.0f), z3, q3, 255, 255, 129, alpha3);
        nLineSetLayer(table + 0x950, right3, y3, z3, q3, 255, 255, 129, alpha3);
        break;
    case 4: break;
    default: kAssertFail(&iGpffffa950, 0x3DF); break;
    }
}
// Sets the render state and draws the three queued line batches of a table.
// FUN_0034CEF0
void nLineDrawBatch(NLineBatch *batch) {
    void (**drawCallbacks)(s32, void *, s32);

    D_00887300[0](1, 0);
    if (batch->vertexCount > 0) {
        shdEnableBlendFlag();
        if ((u32)batch->vertexCount <= 0x33U) {
            /* no-op */
        } else {
            kAssertFail(&iGpffffa950, 0x3EF);
        }
        D_00887310[0](3, batch->decorationVertices, batch->vertexCount);
        shdDisableBlendFlag();
    }
    drawCallbacks = (void (**)(s32, void *, s32))(u32)D_00887310;
    drawCallbacks[0](5, batch, 4);
    if (batch->triangleEnabled != 0) {
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        drawCallbacks[0](5, batch->triangleVertices, 3);
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
    }
    if (batch->effect != 0) {
        drawCallbacks[0](5, batch->effectVertices, 4);
    }
}
// Draws the full-screen frame at scale 1.
// FUN_0034D040
void nLineDrawFullFrame(u8 *table) {
    nLineDrawFrameAt(table, 0.0f, 0.0f, 1.0f);
}

/* measured: retail shares one counter across loops, reproduced by three separate loop-index locals
 * and the exact lh table access. Sweeps the frame horizontally from the leftmost record edge with
 * an eased fraction. */
/* Sweep the line frame horizontally from the outermost record edge, using an eased fraction of the
 * elapsed time that is reversed when exiting, then draw the frame at that offset. */
// FUN_0034D070
/* measured: retail hoists loop-invariant values in this function, and named screen-width locals do
 * not reproduce that hoisting. */
#pragma opt_loop_invariants on
void nLineSweepHorizontal(u8 *table, s32 entering) {
    f32 coordinate;
    f32 alternateCoordinate;
    f32 wrappedCoordinate;
    f32 elapsed;
    f32 duration;
    f32 amount;
    f32 edge;
    s32 firstIndex;
    s32 secondIndex;
    s32 thirdIndex;

    if (entering != 0) {
        edge = 640.0f;
        firstIndex = 0;
        for (; firstIndex < 0x14; firstIndex++) {
            coordinate = ((NLineRecord *)(table + firstIndex * 0x54))->x.value;
            if (coordinate < edge) {
                edge = coordinate;
            }
        }
    } else if (((NLineSet *)(D_007523C8 + (((NLineTable *)table)->setIndex * 0x10) - 8))->orientation == 1) {
        edge = -640.0f;
        secondIndex = 0;
        for (; secondIndex < 0x14; secondIndex++) {
            alternateCoordinate = ((NLineRecord *)(table + secondIndex * 0x54))->x.value;
            if (!(alternateCoordinate <= edge)) {
                edge = alternateCoordinate;
            }
        }
    } else {
        edge = -640.0f;
        thirdIndex = 0;
        for (; thirdIndex < 0x14; thirdIndex++) {
            wrappedCoordinate = ((NLineRecord *)(table + thirdIndex * 0x54))->x.value - 640.0f;
            if (!(wrappedCoordinate <= edge)) {
                edge = wrappedCoordinate;
            }
        }
    }
    duration = ((NLineTable *)table)->duration / 4.0f;
    if (((NLineTable *)table)->immediate == 0) {
        elapsed = (f32)((NLineTable *)table)->elapsed;
        if (elapsed < duration) {
            amount = (elapsed - duration) / (((NLineSet *)(D_007523C4 + (((NLineTable *)table)->setIndex * 0x10) - 4))->duration - duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    nLineDrawFrameAt(table, edge - ((NLineTable *)table)->batch.origin.x, -((NLineTable *)table)->batch.origin.y, amount);
}
/* measured: restores the unit setting after the preceding horizontal sweep. */
#pragma opt_loop_invariants off
// Horizontal sweep with the opposite edge scan; same algorithm as nLineSweepHorizontal.
// FUN_0034D280
/* measured: retail does not hoist loop invariants in this sweep, and screen-width locals do not
 * reproduce the constant placement. */
#pragma opt_loop_invariants on
void nLineSweepHorizontalAlt(u8 *table, s32 entering) {
    f32 coordinate;
    f32 alternateCoordinate;
    f32 wrappedCoordinate;
    f32 elapsed;
    f32 duration;
    f32 amount;
    f32 edge;
    s32 firstIndex;
    s32 secondIndex;
    s32 thirdIndex;

    if (entering != 0) {
        if (((NLineSet *)(D_007523C8 + (((NLineTable *)table)->setIndex * 0x10) - 8))->orientation == 1) {
            edge = -640.0f;
            firstIndex = 0;
            for (; firstIndex < 0x14; firstIndex++) {
                coordinate = ((NLineRecord *)(table + firstIndex * 0x54))->x.value;
                if (!(coordinate <= edge)) {
                    edge = coordinate;
                }
            }
        } else {
            edge = -640.0f;
            secondIndex = 0;
            for (; secondIndex < 0x14; secondIndex++) {
                alternateCoordinate = ((NLineRecord *)(table + secondIndex * 0x54))->x.value - 640.0f;
                if (!(alternateCoordinate <= edge)) {
                    edge = alternateCoordinate;
                }
            }
        }
    } else {
        edge = 640.0f;
        thirdIndex = 0;
        for (; thirdIndex < 0x14; thirdIndex++) {
            wrappedCoordinate = ((NLineRecord *)(table + thirdIndex * 0x54))->x.value;
            if (wrappedCoordinate < edge) {
                edge = wrappedCoordinate;
            }
        }
    }
    duration = ((NLineTable *)table)->duration / 4.0f;
    if (((NLineTable *)table)->immediate == 0) {
        elapsed = (f32)((NLineTable *)table)->elapsed;
        if (elapsed < duration) {
            amount = (elapsed - duration) / (((NLineSet *)(D_007523C4 + (((NLineTable *)table)->setIndex * 0x10) - 4))->duration - duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    nLineDrawFrameAt(table, edge - ((NLineTable *)table)->batch.origin.x, -((NLineTable *)table)->batch.origin.y, amount);
}
/* measured: restores the unit setting after nLineSweepHorizontalAlt. */
#pragma opt_loop_invariants off

/* Sweeps the frame vertically from the topmost record edge using an eased fraction. */
// FUN_0034D490
/* measured: loop-invariant hoisting lifts the shared 448.0f and 4.0f constants out of the loop as
 * retail does. */
#pragma opt_loop_invariants on
void nLineSweepVertical(u8 *table, s32 entering) {
    f32 coordinate;
    f32 alternateCoordinate;
    f32 wrappedCoordinate;
    f32 elapsed;
    f32 duration;
    f32 amount;
    f32 edge;
    s32 firstIndex;
    s32 secondIndex;
    s32 thirdIndex;

    if (entering != 0) {
        edge = 448.0f;
        firstIndex = 0;
        for (; firstIndex < 0x14; firstIndex++) {
            coordinate = ((NLineRecord *)(table + firstIndex * 0x54))->y.value;
            if (coordinate < edge) {
                edge = coordinate;
            }
        }
    } else if (((NLineSet *)(D_007523C8 + (((NLineTable *)table)->setIndex * 0x10) - 8))->orientation == 1) {
        edge = -448.0f;
        secondIndex = 0;
        for (; secondIndex < 0x14; secondIndex++) {
            alternateCoordinate = ((NLineRecord *)(table + secondIndex * 0x54))->y.value - 448.0f;
            if (!(alternateCoordinate <= edge)) {
                edge = alternateCoordinate;
            }
        }
    } else {
        edge = -448.0f;
        thirdIndex = 0;
        for (; thirdIndex < 0x14; thirdIndex++) {
            wrappedCoordinate = ((NLineRecord *)(table + thirdIndex * 0x54))->y.value;
            if (!(wrappedCoordinate <= edge)) {
                edge = wrappedCoordinate;
            }
        }
    }
    duration = ((NLineTable *)table)->duration / 4.0f;
    if (((NLineTable *)table)->immediate == 0) {
        elapsed = (f32)((NLineTable *)table)->elapsed;
        if (elapsed < duration) {
            amount = (duration - elapsed) / duration;
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    nLineDrawFrameAt(table, -((NLineTable *)table)->batch.origin.x, edge - ((NLineTable *)table)->batch.origin.y, amount);
}
/* measured: restores the unit setting after nLineSweepVertical. */
#pragma opt_loop_invariants off
/* Vertical sweep using the opposite edge scan; same algorithm as nLineSweepVertical. Each of the
 * three extrema scans uses its own loop-index local. */
// FUN_0034D690
/* measured: this function needs loop-invariant hoisting enabled; named screen-height locals do not
 * reproduce retail's constant hoisting. */
#pragma opt_loop_invariants on
void nLineSweepVerticalAlt(u8 *table, s32 entering) {
    f32 coordinate;
    f32 alternateCoordinate;
    f32 wrappedCoordinate;
    f32 elapsed;
    f32 duration;
    f32 amount;
    f32 edge;
    s32 firstIndex;
    s32 secondIndex;
    s32 thirdIndex;

    if (entering != 0) {
        if (((NLineSet *)(D_007523C8 + (((NLineTable *)table)->setIndex * 0x10) - 8))->orientation == 1) {
            edge = -448.0f;
            firstIndex = 0;
            for (; firstIndex < 0x14; firstIndex++) {
                coordinate = ((NLineRecord *)(table + firstIndex * 0x54))->y.value - 448.0f;
                if (!(coordinate <= edge)) {
                    edge = coordinate;
                }
            }
        } else {
            edge = -448.0f;
            secondIndex = 0;
            for (; secondIndex < 0x14; secondIndex++) {
                alternateCoordinate = ((NLineRecord *)(table + secondIndex * 0x54))->y.value;
                if (!(alternateCoordinate <= edge)) {
                    edge = alternateCoordinate;
                }
            }
        }
    } else {
        edge = 448.0f;
        thirdIndex = 0;
        for (; thirdIndex < 0x14; thirdIndex++) {
            wrappedCoordinate = ((NLineRecord *)(table + thirdIndex * 0x54))->y.value;
            if (wrappedCoordinate < edge) {
                edge = wrappedCoordinate;
            }
        }
    }
    duration = ((NLineTable *)table)->duration / 4.0f;
    if (((NLineTable *)table)->immediate == 0) {
        elapsed = (f32)((NLineTable *)table)->elapsed;
        if (elapsed < duration) {
            amount = (duration - elapsed) / duration;
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    nLineDrawFrameAt(table, -((NLineTable *)table)->batch.origin.x, edge - ((NLineTable *)table)->batch.origin.y, amount);
}
/* measured: restores the unit setting after nLineSweepVerticalAlt. */
#pragma opt_loop_invariants off

// Draws the wave strip: four layer quads whose height and offset follow a sine ease.
// FUN_0034D890
void nLineDrawWaveStrip(u8 *table, s32 entering) {
    f32 duration;
    f32 width;
    f32 y;
    f32 x;
    f32 depth;
    f32 reciprocal;
    f32 elapsed;
    f32 scaledAlpha;
    f32 amount;
    f32 alphaFloat;
    s32 alphaWord;
    u8 alpha;
    u8 alphaByte;

    duration = (2.0f * ((NLineTable *)table)->duration) / 3.0f;
    if (((NLineTable *)table)->immediate == 0) {
        elapsed = (f32)((NLineTable *)table)->elapsed;
        if (elapsed < duration) {
            amount = sinf((iGpffff8094 * elapsed) / duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    width = 164.0f * amount;
    alpha = ((NLineTable *)table)->batch.alpha;
    alphaFloat = (f32)(u32)alpha;
    scaledAlpha = alphaFloat * amount;
    alphaWord = (u8)scaledAlpha;
    ((NLineTable *)table)->batch.triangleEnabled = 0;
    y = ((NLineTable *)table)->batch.origin.y;
    x = (247.0f - 82.0f * amount) + ((NLineTable *)table)->batch.origin.x;
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    alphaByte = (u8)alphaWord;
    nLineSetLayer(table + 0x690, x, y, depth, reciprocal,
                  0xFF, 0xE9, 0x2C, alphaByte);
    nLineSetLayer(table + 0x6D0, x, operandOrderAddFloat(y, 448.0f), depth, reciprocal,
                  0xFF, 0xE9, 0x2C, alphaByte);
    nLineSetLayer(table + 0x710, (x + width), operandOrderAddFloat(y, 448.0f),
                  depth, reciprocal, 0xFF, 0xE9, 0x2C, alphaByte);
    nLineSetLayer(table + 0x750, (x + width), y, depth, reciprocal,
                  0xFF, 0xE9, 0x2C, alphaByte);
}

/* Draws a frame scaled by the given amount about the centre and registers its bounds; declaration
 * order and inline multiply boundaries keep the FP register allocation unchanged. */
// FUN_0034DB60
void nLineDrawScaledFrame(NLineTable *table, f32 durationScale, s32 entering) {
    f32 elapsed;
    f32 height;
    f32 width;
    f32 insetX;
    f32 insetY;
    f32 amount;
    f32 left;
    f32 right;
    f32 top;
    f32 depth;
    f32 bottom;
    f32 reciprocal;
    f32 duration;

    duration = table->duration * durationScale;
    if (table->immediate == 0) {
        elapsed = (f32)table->elapsed;
        if (elapsed < duration) {
            amount = sinf((iGpffff8094 * elapsed) / duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    width = operandOrderMultiply(640.0f, amount);
    insetX = (640.0f - width) / 2.0f;
    height = operandOrderMultiply(480.0f, amount);
    insetY = (448.0f - height) / 2.0f;
    table->batch.triangleEnabled = 0;
    top = insetY + table->batch.origin.y;
    left = insetX + table->batch.origin.x;
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    nLineSetLayer(table->batch.frameVertices, left, top, depth, reciprocal, 255, 233, 44, 255);
    bottom = operandOrderAddFloat(top, height);
    nLineSetLayer(table->batch.frameVertices + 0x40, left, bottom, depth, reciprocal, 255, 233, 44, 255);
    right = operandOrderAddFloat(left, width);
    nLineSetLayer(table->batch.frameVertices + 0x80, right, bottom, depth, reciprocal, 255, 233, 44, 255);
    nLineSetLayer(table->batch.frameVertices + 0xC0, right, top, depth, reciprocal, 255, 233, 44, 255);
    table->batch.vertexCount = nLineBuildDecoration((u8 *)table, insetX + table->batch.origin.x, insetY + table->batch.origin.y, width, height);
    nLineDrawLayers((u8 *)table, 0.0f, 0.0f, amount);
}
/* Sets the eased band height from the referenced animation amount. measured: retail does this
 * multiply through an output helper, which keeps the height separate from the alpha conversion; a
 * plain multiply changes float register use. */
static inline void nLineScaleBandHeight(f32 *height, const f32 *amount)
{
    *height = 171.0f * *amount;
}
// Draws the horizontal band whose height follows a sine ease.
// FUN_0034DDF0
void nLineDrawBand(u8 *table, s32 entering) {
    f32 duration;
    f32 height;
    f32 y;
    struct { f32 reciprocal; f32 depth; } projection;
    f32 x;
    f32 elapsed;
    f32 scaledAlpha;
    f32 amount;
    f32 alphaFloat;
    s32 alphaWord;
    u8 alpha;
    u8 alphaByte;

    duration = ((NLineTable *)table)->duration;
    if (((NLineTable *)table)->immediate == 0) {
        elapsed = (f32)((NLineTable *)table)->elapsed;
        if (elapsed < duration) {
            amount = sinf((iGpffff8094 * elapsed) / duration);
        } else {
            amount = 1.0f;
        }
    } else {
        amount = 1.0f;
    }
    if (entering == 0) {
        amount = 1.0f - amount;
    }
    nLineScaleBandHeight(&height, &amount);
    alpha = ((NLineTable *)table)->batch.alpha;
    alphaFloat = (f32)(u32)alpha;
    scaledAlpha = alphaFloat * amount;
    alphaWord = (u8)scaledAlpha;
    ((NLineTable *)table)->batch.triangleEnabled = 0;
    elapsed = iGpffff8220 - (171.0f * amount) / 2.0f;
    y = (elapsed + (((NLineTable *)table)->batch.origin.y));
    x = 77.0f + ((NLineTable *)table)->batch.origin.x;
    projection.depth = D_008872F8[0] - D_0088467C[0];
    projection.reciprocal = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    alphaByte = (u8)alphaWord;
    nLineSetLayer(table + 0x690, x, y, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, alphaByte);
    height = operandOrderAddFloat(y, height);
    nLineSetLayer(table + 0x6D0, x, height, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, alphaByte);
    nLineSetLayer(table + 0x710, operandOrderAddFloat(x, 580.0f), height, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, alphaByte);
    nLineSetLayer(table + 0x750, operandOrderAddFloat(x, 580.0f), y, projection.depth, projection.reciprocal, 0xFF, 0xE9, 0x2C, alphaByte);
}

/* Draws the 640 by 480 frame at the given offset and scale, then registers its bounds. Alpha is
 * read before the camera callback. */
// FUN_0034E0B0
void nLineDrawFrameAt(u8 *table, f32 offsetX, f32 offsetY, f32 amount)
{
    u32 alpha;
    u8 alphaByte;
    f32 x;
    f32 y;
    f32 z;
    f32 scale;
    alpha = ((NLineTable *)table)->batch.alpha;
    y = offsetY + ((NLineTable *)table)->batch.origin.y;
    x = offsetX + ((NLineTable *)table)->batch.origin.x;
    z = D_008872F8[0] - D_0088467C[0];
    scale = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    alphaByte = (u8)alpha;
    nLineSetLayer(table + 0x690, x, y, z, scale, 0xFA, 0xE3, 0x27, alphaByte);
    nLineSetLayer(table + 0x6D0, x, operandOrderAddFloat(y, 480.0f), z, scale, 0xFA, 0xE3, 0x27, alphaByte);
    nLineSetLayer(table + 0x710, operandOrderAddFloat(x, 640.0f), operandOrderAddFloat(y, 480.0f), z, scale, 0xFA, 0xE3, 0x27, alphaByte);
    nLineSetLayer(table + 0x750, operandOrderAddFloat(x, 640.0f), y, z, scale, 0xFA, 0xE3, 0x27, alphaByte);
    ((NLineTable *)table)->batch.vertexCount = nLineBuildDecoration(table, offsetX, offsetY, 640.0f, 448.0f);
    nLineDrawLayers(table, offsetX, offsetY, amount);
}

// Rolls the set's decoration style and stores a random phase for styles 1 to 4. Returns the style.
// FUN_0034E290
s16 nLineRollStyle(u8 *table, s32 setIndex) {
    s16 style;
    s32 randomValue;
    s32 layerCount;

    style = ((NLineSet *)(D_007523CE + setIndex * 0x10 - 0xE))->style;
    switch (style) {
    case 1:
    case 2:
    case 3:
    case 4:
        randomValue = RpRandom() & 0xFFF;
        layerCount = ((NLineDecorationStyle *)(D_007525D4 + style * 0x2C))->count + 1;
        ((NLineTable *)table)->batch.hiddenLayer = (s16)((u32)(layerCount * randomValue) >> 12);
        return style;
    }
    return style;
}

/* Builds the decoration mesh: styles 1-4 form successive V-shaped strips, style 5 draws nested
 * rectangles in reverse layer order. Style records are 44 bytes with up to five color/distance
 * entries. */

/* measured: retail recomputes the previous-entry address through this index reference. Loads the
 * preceding strip distance plus the fixed decoration margin. */
static inline void nLineLoadPreviousMargin(f32 *out, const NLineDecorationStyle *style, const s32 *index)
{
    *out = 30.0f + style->offsets[*index - 1];
}


/* Read the current decoration strip distance into its output coordinate. measured: retail computes
 * the style-base-plus-index address once and shares it between both fields, so a plain lookup
 * reverses the addu operands. */
static inline void nLineLoadCurrentDistance(f32 *out, const NLineDecorationStyle *style, s32 index)
{
    *out = style->offsets[index];
}

// Builds the decoration mesh for the rectangle from its style: V strips for styles 1-4, nested
// rectangles for style 5. Returns the vertex count.
// FUN_0034E360
s32 nLineBuildDecoration(u8 *table, f32 x, f32 y, f32 width, f32 height) {
    u32 stripAlpha;
    u8 stripAlphaByte;
    s32 stripIndex;
    s32 stripCount;
    struct { s32 x; s32 y; } direction;
    f32 shiftX;
    f32 shiftY;
    f32 previousShiftX;
    f32 previousShiftY;
    f32 depth;
    f32 reciprocal;
    s16 mode;
    s16 index;
    Vec2f start;
    u8 *vertices;

    mode = ((NLineTable *)table)->batch.style;
    index = (s16)(mode - 1);
    if (mode == 0) {
        return 0;
    }
    depth = D_008872F8[0] - D_0088467C[0];
    reciprocal = 1.0f / ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
    vertices = table + 0x9B0;
    if (width != 640.0f && height != 448.0f) {
        start.x = x;
        start.y = y;
        x += width;
        y += height;
    } else if (x < 0.0f) {
        start.x = 640.0f + x;
        start.y = y;
        x = start.x;
        y = operandOrderAddLoaded(&y, 448.0f);
        direction.x = 1;
        direction.y = 0;
    } else if (!(x <= 0.0f)) {
        start.x = x;
        start.y = 448.0f + y;
        direction.x = -1;
        direction.y = 0;
    } else if (!(y <= 0.0f)) {
        start.x = x;
        start.y = y;
        x = operandOrderAddLoaded(&x, 640.0f);
        direction.x = 0;
        direction.y = -1;
    } else if (y < 0.0f) {
        start.x = 640.0f + x;
        start.y = y;
        direction.x = 0;
        direction.y = 1;
    } else {
        return 0;
    }
    switch (mode) {
    case 1:
    case 2:
    case 3:
    case 4: {
        NLineDecorationStyle *style;
        s32 count;
        s32 selected;
        Vec2f center;
        Vec2f peakOffset;
        Vec2f gapOffset;
        style = (NLineDecorationStyle *)D_00752600 + index;
        /* Capture the layer count and hidden layer after the camera query. */
        count = style->count;
        selected = ((NLineTable *)table)->batch.hiddenLayer;
        stripIndex = 0;
        stripCount = 0;
        if (count > 0) {
            center.x = (start.x + x) / 2.0f;
            center.y = (start.y + y) / 2.0f;
            peakOffset.y = 200.0f * (f32)direction.y;
            peakOffset.x = 200.0f * (f32)direction.x;
            gapOffset.x = 30.0f * (f32)direction.x;
            gapOffset.y = 30.0f * (f32)direction.y;
            while (stripIndex < count) {
                f32 distance;
                u8 *color;
                nLineLoadCurrentDistance(&distance, style, stripIndex);
                shiftX = (f32)direction.x * distance;
                shiftY = (f32)direction.y * distance;
                color = D_00749AC0 + style->colors[stripIndex] * 4;
                if (stripIndex == selected) {
                    stripAlpha = 0;
                } else {
                    stripAlpha = (u8)((color[3] * ((NLineTable *)table)->batch.alpha) / 255);
                }
                /* Alpha is fixed for this layer; RGB is reloaded per vertex. */
                stripAlphaByte = (u8)stripAlpha;
                if (stripIndex == 0) {
                    nLineSetLayer(vertices + (stripCount++ << 6), x, y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), peakOffset.x + (center.x + shiftX), peakOffset.y + (center.y + shiftY), depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), start.x, start.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                } else {
                    f32 previous;
                    Vec2f peak;
                    Vec2f edge;
                    Vec2f innerPeak;
                    Vec2f other;
                    nLineLoadPreviousMargin(&previous, style, &stripIndex);
                    previousShiftX = (f32)direction.x * previous;
                    previousShiftY = (f32)direction.y * previous;
                    shiftX += gapOffset.x;
                    shiftY += gapOffset.y;
                    nLineSetLayer(vertices + (stripCount++ << 6), x + shiftX, y + shiftY, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    peak.y = peakOffset.y + (center.y + shiftY);
                    peak.x = peakOffset.x + (center.x + shiftX);
                    nLineSetLayer(vertices + (stripCount++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    edge.y = y + previousShiftY;
                    edge.x = x + previousShiftX;
                    nLineSetLayer(vertices + (stripCount++ << 6), edge.x, edge.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), edge.x, edge.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    innerPeak.y = peakOffset.y + (center.y + previousShiftY);
                    innerPeak.x = peakOffset.x + (center.x + previousShiftX);
                    nLineSetLayer(vertices + (stripCount++ << 6), innerPeak.x, innerPeak.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), innerPeak.x, innerPeak.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    other.y = start.y + previousShiftY;
                    other.x = start.x + previousShiftX;
                    nLineSetLayer(vertices + (stripCount++ << 6), other.x, other.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), other.x, other.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), peak.x, peak.y, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                    nLineSetLayer(vertices + (stripCount++ << 6), start.x + shiftX, start.y + shiftY, depth, reciprocal, color[0], color[1], color[2], stripAlphaByte);
                }
                ++stripIndex;
            }
        }
        if (stripCount > 0x33) {
            kAssertFail(&iGpffffa950, 0x67E);
        }
        return stripCount;
    }
    case 5: {
        NLineDecorationStyle *style;
        s32 i;
        s32 n;
        style = (NLineDecorationStyle *)D_00752600 + index;
        i = style->count - 1;
        n = 0;
        while (i >= 0) {
            f32 distance;
            Vec2f topLeft;
            Vec2f bottomRight;
            u8 *color;
            u8 alpha;
            nLineLoadCurrentDistance(&distance, style, i);
            color = D_00749AC0 + style->colors[i] * 4;
            alpha = (u8)((color[3] * ((NLineTable *)table)->batch.alpha) / 255);
            topLeft.y = start.y - distance;
            width = start.x - distance;
            nLineSetLayer(vertices + (n++ << 6), width, topLeft.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            bottomRight.x = x + distance;
            nLineSetLayer(vertices + (n++ << 6), bottomRight.x, topLeft.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            bottomRight.y = y + distance;
            nLineSetLayer(vertices + (n++ << 6), bottomRight.x, bottomRight.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            nLineSetLayer(vertices + (n++ << 6), width, topLeft.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            nLineSetLayer(vertices + (n++ << 6), bottomRight.x, bottomRight.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            nLineSetLayer(vertices + (n++ << 6), width, bottomRight.y, depth, reciprocal, color[0], color[1], color[2], alpha);
            --i;
        }
        if (n > 0x33) {
            kAssertFail(&iGpffffa950, 0x6AC);
        }
        return n;
    }
    default:
        kAssertFail(&iGpffffa950, 0x6AF);
        return 0;
    }
}

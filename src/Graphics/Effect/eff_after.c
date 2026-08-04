#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit eff_after.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

/* 12-byte vector copy; mwcc emits all loads then all stores for a struct
   assignment, matching retail, where per-element statements interleave. */
typedef struct {
    f32 c[3];
} EffAfterVec;

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007146E0[];

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern f32 func_003e4180(void *a0);
extern void func_003e40b0(f32 *a, f32 *b);
extern f32 func_004b7300(void *arg0, s32 arg1);
extern s32 func_004b7800(void *arg0, s32 arg1);
extern f32 func_004bc310(u8 *arg0, s32 arg1);
extern void func_004bb1d0(void *arg0, s32 arg1);
extern void func_004b7dc0(u8 *arg0, s32 arg1, EffAfterVec *arg2);

// FUN_004B7460
void func_004b7460(u8 *data, f32 distance, u32 *section, f32 *fraction) {
    EffAfterVec leadingDelta;
    EffAfterVec trailingDelta;
    u8 *vectorBase;
    EffAfterVec *nextSample;
    EffAfterVec *firstSample;
    s32 firstOffset;
    s32 nextOffset;
    s32 leadingIndex;
    s32 trailingIndex;
    s32 firstIndex;
    s32 nextIndex;
    s32 totalIndex;
    s32 currentSection;
    f32 previous;
    f32 cumulative;
    f32 total;
    f32 scaledLength;
    f32 sectionLength;
    f32 nextX;
    f32 targetDistance = distance;

    total = 0.0f;
    for (totalIndex = 0; totalIndex < *(s32 *)(data + 8) - 1; totalIndex++) {
        total += func_004b7300(data, totalIndex);
    }
    if (total <= 0.0f) {
        *section = 0;
        *fraction = 0.0f;
        return;
    }
    currentSection = 0;
    while (currentSection < *(s32 *)(data + 8) - 1) {
        cumulative = 0.0f;
        for (leadingIndex = 0; leadingIndex < currentSection + 1; leadingIndex++) {
            firstIndex = func_004b7800(data, leadingIndex);
            nextIndex = func_004b7800(data, leadingIndex + 1);
            sectionLength = 0.0f;
            vectorBase = (u8 *)*(s32 *)(data + 0x10);
            firstOffset = firstIndex * 0xC;
            nextOffset = nextIndex * 0xC;
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            leadingDelta.c[0] = nextX - firstSample->c[0];
            leadingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            leadingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += func_003e4180(&leadingDelta.c[0]);
            vectorBase = (u8 *)*(s32 *)(data + 0x14);
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            leadingDelta.c[0] = nextX - firstSample->c[0];
            leadingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            leadingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += func_003e4180(&leadingDelta.c[0]);
            scaledLength = 0.0f;
            scaledLength += sectionLength * *(f32 *)((u8 *)*(void **)*(void **)data + 0x2C);
            cumulative += scaledLength / total;
        }
        if (targetDistance < cumulative) {
            break;
        }
        currentSection++;
    }
    if (currentSection == 0) {
        previous = 0.0f;
    } else {
        previous = 0.0f;
        for (trailingIndex = 0; trailingIndex < currentSection; trailingIndex++) {
            firstIndex = func_004b7800(data, trailingIndex);
            nextIndex = func_004b7800(data, trailingIndex + 1);
            sectionLength = 0.0f;
            vectorBase = (u8 *)*(s32 *)(data + 0x10);
            firstOffset = firstIndex * 0xC;
            nextOffset = nextIndex * 0xC;
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            trailingDelta.c[0] = nextX - firstSample->c[0];
            trailingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            trailingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += func_003e4180(&trailingDelta.c[0]);
            vectorBase = (u8 *)*(s32 *)(data + 0x14);
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            trailingDelta.c[0] = nextX - firstSample->c[0];
            trailingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            trailingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += func_003e4180(&trailingDelta.c[0]);
            scaledLength = 0.0f;
            scaledLength += sectionLength * *(f32 *)((u8 *)*(void **)*(void **)data + 0x2C);
            previous += scaledLength / total;
        }
    }
    *section = currentSection;
    sectionLength = cumulative - previous;
    if (sectionLength <= 0.0f) {
        func_0046d730(D_007146E0, 0x7E);
    }
    *fraction = (targetDistance - previous) / sectionLength;
}
// FUN_004B7830
void func_004b7830(u8 *work, s32 section, s32 side, EffAfterVec *output) {
    typedef struct {
        u8 *config;
        u32 state;
        s32 count;
        s32 cursor;
        EffAfterVec *vectors[2];
    } SurfaceWork;
    SurfaceWork *data = (SurfaceWork *)work;
    EffAfterVec *points[2][2];
    EffAfterVec sideDelta;
    EffAfterVec forward;
    EffAfterVec normal;
    EffAfterVec axis;
    EffAfterVec frameNormal;
    EffAfterVec *point;
    EffAfterVec **pointRow;
    s32 firstIndex;
    u32 selected;
    u32 other;
    f32 projection;

    if (data->count < 2) {
        func_0046d730(D_007146E0, 0xAA);
    }
    if (section == data->count - 1) {
        s32 secondIndex;
        secondIndex = data->cursor - 1 - section;
        if (secondIndex < 0) {
            secondIndex += data->count;
        }
        firstIndex = data->cursor - section;
        if (firstIndex < 0) {
            firstIndex += data->count;
        }
        func_004b7dc0(work, section, (EffAfterVec *)&frameNormal.c[0]);
        points[0][0] = &data->vectors[(other = side & 1)][secondIndex];
        selected = (side + 1) & 1;
        points[0][1] = &data->vectors[selected][secondIndex];
        points[1][0] = &data->vectors[other][firstIndex];
        points[1][1] = &data->vectors[selected][firstIndex];
        pointRow = points[other];
        point = pointRow[selected];
        sideDelta.c[0] = point->c[0] - points[0][0]->c[0];
        sideDelta.c[1] = point->c[1] - points[0][0]->c[1];
        sideDelta.c[2] = point->c[2] - points[0][0]->c[2];
        func_003e40b0(&sideDelta.c[0], &sideDelta.c[0]);
        pointRow = points[selected];
        point = pointRow[other];
        projection = point->c[0];
        forward.c[0] = projection - points[0][0]->c[0];
        forward.c[1] = point->c[1] - points[0][0]->c[1];
        forward.c[2] = point->c[2] - points[0][0]->c[2];
        func_003e40b0(&forward.c[0], &forward.c[0]);
        normal.c[0] = sideDelta.c[1] * forward.c[2] - sideDelta.c[2] * forward.c[1];
        normal.c[1] = sideDelta.c[2] * forward.c[0] - sideDelta.c[0] * forward.c[2];
        normal.c[2] = sideDelta.c[0] * forward.c[1] - sideDelta.c[1] * forward.c[0];
        func_003e40b0(&normal.c[0], &normal.c[0]);
        switch (side) {
        case 0:
            axis.c[0] = normal.c[1] * sideDelta.c[2] - normal.c[2] * sideDelta.c[1];
            axis.c[1] = normal.c[2] * sideDelta.c[0] - normal.c[0] * sideDelta.c[2];
            axis.c[2] = normal.c[0] * sideDelta.c[1] - normal.c[1] * sideDelta.c[0];
            break;
        case 1:
            axis.c[0] = forward.c[1] * normal.c[2] - forward.c[2] * normal.c[1];
            axis.c[1] = forward.c[2] * normal.c[0] - forward.c[0] * normal.c[2];
            axis.c[2] = forward.c[0] * normal.c[1] - forward.c[1] * normal.c[0];
            break;
        }
        projection = axis.c[0] * frameNormal.c[0] + axis.c[1] * frameNormal.c[1] + axis.c[2] * frameNormal.c[2];
        axis.c[0] *= projection;
        axis.c[1] *= projection;
        axis.c[2] *= projection;
        func_003e40b0(&output->c[0], &axis.c[0]);
    } else {
        s32 secondIndex;
        secondIndex = data->cursor - 1 - section;
        if (secondIndex < 0) {
            secondIndex += data->count;
        }
        firstIndex = -2 - section + data->cursor;
        if (firstIndex < 0) {
            firstIndex += data->count;
        }
        func_004b7dc0(work, section, (EffAfterVec *)&frameNormal.c[0]);
        points[0][0] = &data->vectors[(other = side & 1)][secondIndex];
        selected = (side + 1) & 1;
        points[0][1] = &data->vectors[selected][secondIndex];
        points[1][0] = &data->vectors[other][firstIndex];
        points[1][1] = &data->vectors[selected][firstIndex];
        pointRow = points[other];
        point = pointRow[selected];
        sideDelta.c[0] = point->c[0] - points[0][0]->c[0];
        sideDelta.c[1] = point->c[1] - points[0][0]->c[1];
        sideDelta.c[2] = point->c[2] - points[0][0]->c[2];
        func_003e40b0(&sideDelta.c[0], &sideDelta.c[0]);
        pointRow = points[selected];
        point = pointRow[other];
        projection = point->c[0];
        forward.c[0] = projection - points[0][0]->c[0];
        forward.c[1] = point->c[1] - points[0][0]->c[1];
        forward.c[2] = point->c[2] - points[0][0]->c[2];
        func_003e40b0(&forward.c[0], &forward.c[0]);
        normal.c[0] = sideDelta.c[1] * forward.c[2] - sideDelta.c[2] * forward.c[1];
        normal.c[1] = sideDelta.c[2] * forward.c[0] - sideDelta.c[0] * forward.c[2];
        normal.c[2] = sideDelta.c[0] * forward.c[1] - sideDelta.c[1] * forward.c[0];
        func_003e40b0(&normal.c[0], &normal.c[0]);
        switch (side) {
        case 0:
            axis.c[0] = sideDelta.c[1] * normal.c[2] - sideDelta.c[2] * normal.c[1];
            axis.c[1] = sideDelta.c[2] * normal.c[0] - sideDelta.c[0] * normal.c[2];
            axis.c[2] = sideDelta.c[0] * normal.c[1] - sideDelta.c[1] * normal.c[0];
            break;
        case 1:
            axis.c[0] = normal.c[1] * forward.c[2] - normal.c[2] * forward.c[1];
            axis.c[1] = normal.c[2] * forward.c[0] - normal.c[0] * forward.c[2];
            axis.c[2] = normal.c[0] * forward.c[1] - normal.c[1] * forward.c[0];
            break;
        }
        projection = axis.c[0] * frameNormal.c[0] + axis.c[1] * frameNormal.c[1] + axis.c[2] * frameNormal.c[2];
        axis.c[0] *= projection;
        axis.c[1] *= projection;
        axis.c[2] *= projection;
        func_003e40b0(&output->c[0], &axis.c[0]);
    }
}

// FUN_004B7DC0
void func_004b7dc0(u8 *work, s32 section, EffAfterVec *output) {
    typedef struct {
        u8 *config;
        u32 state;
        s32 count;
        s32 cursor;
        EffAfterVec *firstVectors;
        EffAfterVec *secondVectors;
    } FrameWork;
    FrameWork *data = (FrameWork *)work;
    EffAfterVec *firstLeading;
    EffAfterVec *firstTrailing;
    EffAfterVec *secondLeading;
    EffAfterVec *secondTrailing;
    EffAfterVec leadingDelta;
    EffAfterVec secondSide;
    EffAfterVec normal;
    s32 firstIndex;
    f32 leadingLength;
    f32 trailingLength;

    if (data->count < 2) {
        func_0046d730(D_007146E0, 0xF7);
    }
    if (section == data->count - 1) {
        s32 secondIndex;
        firstIndex = data->cursor - 1 - section;
        if (firstIndex < 0) {
            firstIndex += data->count;
        }
        firstLeading = &data->firstVectors[firstIndex];
        firstTrailing = &data->secondVectors[firstIndex];
        secondIndex = data->cursor - section;
        if (secondIndex < 0) {
            secondIndex += data->count;
        }
        secondLeading = &data->firstVectors[secondIndex];
        secondTrailing = &data->secondVectors[secondIndex];
        leadingDelta.c[0] = firstLeading->c[0] - secondLeading->c[0];
        leadingDelta.c[1] = firstLeading->c[1] - secondLeading->c[1];
        leadingDelta.c[2] = firstLeading->c[2] - secondLeading->c[2];
        leadingLength = func_003e4180(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - secondTrailing->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - secondTrailing->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - secondTrailing->c[2];
        trailingLength = func_003e4180(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - firstLeading->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - firstLeading->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - firstLeading->c[2];
        func_003e40b0(&leadingDelta.c[0], &leadingDelta.c[0]);
        secondSide.c[0] = secondTrailing->c[0] - secondLeading->c[0];
        secondSide.c[1] = secondTrailing->c[1] - secondLeading->c[1];
        secondSide.c[2] = secondTrailing->c[2] - secondLeading->c[2];
        func_003e40b0(&secondSide.c[0], &secondSide.c[0]);
        normal.c[0] = leadingDelta.c[1] * secondSide.c[2] - leadingDelta.c[2] * secondSide.c[1];
        normal.c[1] = leadingDelta.c[2] * secondSide.c[0] - leadingDelta.c[0] * secondSide.c[2];
        normal.c[2] = leadingDelta.c[0] * secondSide.c[1] - leadingDelta.c[1] * secondSide.c[0];
        func_003e40b0(&normal.c[0], &normal.c[0]);
        *output = normal;
        if (!(leadingLength <= trailingLength)) {
            output->c[0] = leadingDelta.c[1] * normal.c[2] - leadingDelta.c[2] * normal.c[1];
            output->c[1] = leadingDelta.c[2] * normal.c[0] - leadingDelta.c[0] * normal.c[2];
            output->c[2] = leadingDelta.c[0] * normal.c[1] - leadingDelta.c[1] * normal.c[0];
        } else {
            output->c[0] = normal.c[1] * leadingDelta.c[2] - normal.c[2] * leadingDelta.c[1];
            output->c[1] = normal.c[2] * leadingDelta.c[0] - normal.c[0] * leadingDelta.c[2];
            output->c[2] = normal.c[0] * leadingDelta.c[1] - normal.c[1] * leadingDelta.c[0];
        }
    } else {
        s32 secondIndex;
        firstIndex = data->cursor - 1 - section;
        if (firstIndex < 0) {
            firstIndex += data->count;
        }
        firstLeading = &data->firstVectors[firstIndex];
        firstTrailing = &data->secondVectors[firstIndex];
        secondIndex = -2 - section + data->cursor;
        if (secondIndex < 0) {
            secondIndex += data->count;
        }
        secondLeading = &data->firstVectors[secondIndex];
        secondTrailing = &data->secondVectors[secondIndex];
        leadingDelta.c[0] = firstLeading->c[0] - secondLeading->c[0];
        leadingDelta.c[1] = firstLeading->c[1] - secondLeading->c[1];
        leadingDelta.c[2] = firstLeading->c[2] - secondLeading->c[2];
        leadingLength = func_003e4180(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - secondTrailing->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - secondTrailing->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - secondTrailing->c[2];
        trailingLength = func_003e4180(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - firstLeading->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - firstLeading->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - firstLeading->c[2];
        func_003e40b0(&leadingDelta.c[0], &leadingDelta.c[0]);
        secondSide.c[0] = secondTrailing->c[0] - secondLeading->c[0];
        secondSide.c[1] = secondTrailing->c[1] - secondLeading->c[1];
        secondSide.c[2] = secondTrailing->c[2] - secondLeading->c[2];
        func_003e40b0(&secondSide.c[0], &secondSide.c[0]);
        normal.c[0] = secondSide.c[1] * leadingDelta.c[2] - secondSide.c[2] * leadingDelta.c[1];
        normal.c[1] = secondSide.c[2] * leadingDelta.c[0] - secondSide.c[0] * leadingDelta.c[2];
        normal.c[2] = secondSide.c[0] * leadingDelta.c[1] - secondSide.c[1] * leadingDelta.c[0];
        func_003e40b0(&normal.c[0], &normal.c[0]);
        *output = normal;
        if (!(leadingLength <= trailingLength)) {
            output->c[0] = leadingDelta.c[1] * normal.c[2] - leadingDelta.c[2] * normal.c[1];
            output->c[1] = leadingDelta.c[2] * normal.c[0] - leadingDelta.c[0] * normal.c[2];
            output->c[2] = leadingDelta.c[0] * normal.c[1] - leadingDelta.c[1] * normal.c[0];
        } else {
            output->c[0] = normal.c[1] * leadingDelta.c[2] - normal.c[2] * leadingDelta.c[1];
            output->c[1] = normal.c[2] * leadingDelta.c[0] - normal.c[0] * leadingDelta.c[2];
            output->c[2] = normal.c[0] * leadingDelta.c[1] - normal.c[1] * leadingDelta.c[0];
        }
    }
}
// FUN_004B8350
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b8350);

// FUN_004B8DF0
void func_004b8df0(u8 *arg0, u8 *arg1) {
    u8 *p;
    u8 *q;
    s32 size;

    size = 0;
    size += (*(s32 *)(arg1 + 8) * 3 << 3);
    size += (*(s32 *)(arg1 + 8) * 3 << 4);
    func_0044ea90(D_007146E0, 0x2A5);
    p = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    *(void **)(arg0 + 0x10) = p;
    q = p + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x14) = q;
    q = q + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x18) = q;
    q = q + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x1C) = q;
    q = q + *(s32 *)(arg1 + 8) * 0xC;
    *(void **)(arg0 + 0x20) = q;
    *(void **)(arg0 + 0x24) = q + *(s32 *)(arg1 + 8) * 0xC;
    *(s32 *)(arg0 + 4) = 0;
    *(void **)(arg0 + 0) = arg1;
    *(s32 *)(arg0 + 8) = 0;
    *(s32 *)(arg0 + 0xC) = 0;
    *(s16 *)(arg0 + 0x38) = *(s32 *)(arg1 + 0x10);
}

// FUN_004B8F10
void func_004b8f10(void *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x10));
}

/* measured: 7728B mesh-builder. Retail asm has 63 mula/madda/madd/msub FPU
   sequences (the same multiply-accumulate family as func_004b7dc0/004b7830,
   which floor on the v5 index register and fp-save set) plus 21 lq/sq quadword
   ops and 3 large switch statements. M2C_ERROR in the m2c draft at every FPU
   sequence; the mula/madda/madd dot-product folds cannot be reproduced in plain
   C by b210. FPU-accumulate + quadword-slot floor. */
// FUN_004B8F40
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b8f40);

// FUN_004BAD70
void func_004bad70(u8 *data, EffAfterVec *position, EffAfterVec *normal) {
    typedef struct {
        u8 *config;
        u32 reserved;
        s32 count;
        s32 writeIndex;
        EffAfterVec *positions;
        EffAfterVec *normals;
    } SampleQueue;
    SampleQueue *queue;
    s32 index;

    queue = (SampleQueue *)data;
    index = queue->writeIndex;
    queue->positions[index] = *position;
    queue->normals[index] = *normal;
    if (queue->count < *(s32 *)((u8 *)queue->config + 8)) {
        queue->count++;
    }
    queue->writeIndex++;
    queue->writeIndex %= *(s32 *)((u8 *)queue->config + 8);
    switch (queue->count) {
    case 0:
        func_0046d730(D_007146E0, 0x5BB);
        break;
    case 1:
        break;
    case 2:
        func_004bb1d0(queue, 0);
        break;
    default:
        func_004bb1d0(queue, 1);
        func_004bb1d0(queue, 0);
        break;
    }
}
// FUN_004BB1D0
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004bb1d0);

/* measured: nd 34 from 49 (obj 288B vs window 304B). Logic confirmed, including
   that the two ring-index expressions have DIFFERENT shapes in retail --
   `-2 - arg1 + field0xC` for the first (addiu -2, subu, then addu the field) and
   `(field0xC - 1) - arg1` for the second -- and that both wrap by adding
   field0x8 when negative.

   Two things earned the 49 -> 34: hoisting `arg0 + arg2 * 4` into a local, and
   loading all three floats into temps BEFORE storing any of them, which is
   retail's batch shape (3x lwc1 then 3x swc1); written as three
   load-store pairs b210 interleaves them.

   Residual: the three float temps are register-rotated against retail
   ($f2/$f1/$f0 assigned to offsets +4/+8/+0 rather than +0/+4/+8), one
   commutative `addu` has its operands swapped, and retail RECOMPUTES
   `arg2 * 4 + arg0` for the second access instead of reusing the hoisted base.
   Measured and rejected: inlining the address at both uses (49, worse -- b210
   then emits a spurious `addiu $a0, $a1, 0x10`), `arg2 * 4 + arg0` operand
   order, and declaring the temps in reverse (both 34). Register-rotation
   floor. */
// FUN_004BC1E0 NONMATCHING
#ifdef NON_MATCHING
void func_004bc1e0(u8 *arg0, s32 arg1, s32 arg2)
{
    f32 v[3];
    s32 i;
    f32 *p;
    u8 *base;
    f32 a;
    f32 b;
    f32 c;

    if (arg1 == *(s32 *)(arg0 + 8) - 1) {
        func_0046d730(D_007146E0, 0x6F8);
    }
    i = -2 - arg1 + *(s32 *)(arg0 + 0xC);
    if (i < 0) {
        i += *(s32 *)(arg0 + 8);
    }
    base = arg0 + arg2 * 4;
    p = (f32 *)(*(u8 **)(base + 0x10) + i * 0xC);
    a = p[0];
    b = p[1];
    c = p[2];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    i = *(s32 *)(arg0 + 0xC) - 1 - arg1;
    if (i < 0) {
        i += *(s32 *)(arg0 + 8);
    }
    p = (f32 *)(*(u8 **)(base + 0x10) + i * 0xC);
    v[0] -= p[0];
    v[1] -= p[1];
    v[2] -= p[2];
    func_003e4180(v);
}
#else
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004bc1e0);
#endif

// FUN_004BC310
f32 func_004bc310(u8 *arg0, s32 arg1) {
    EffAfterVec v1;
    EffAfterVec v2;
    EffAfterVec *q;
    f32 d;
    f32 t;
    s32 i;
    s32 j;
    u8 *p;

    if (arg1 == *(s32 *)(arg0 + 8) - 1) {
        func_0046d730(D_007146E0, 0x709);
    }
    i = (*(s32 *)(arg0 + 0xC) - 1) - arg1;
    if (i < 0) {
        i += *(s32 *)(arg0 + 8);
    }
    p = (u8 *)(*(s32 *)(arg0 + 0x14) + i * 0xC);
    v1 = *(EffAfterVec *)p;
    p = (u8 *)(*(s32 *)(arg0 + 0x10) + i * 0xC);
    q = (EffAfterVec *)p;
    t = q->c[0];
    v1.c[0] -= t;
    v1.c[1] -= q->c[1];
    v1.c[2] -= q->c[2];
    func_003e40b0(&v1.c[0], &v1.c[0]);
    j = (-2 - arg1) + *(s32 *)(arg0 + 0xC);
    if (j < 0) {
        j += *(s32 *)(arg0 + 8);
    }
    p = (u8 *)(*(s32 *)(arg0 + 0x14) + j * 0xC);
    v2 = *(EffAfterVec *)p;
    p = (u8 *)(*(s32 *)(arg0 + 0x10) + j * 0xC);
    q = (EffAfterVec *)p;
    t = q->c[0];
    v2.c[0] -= t;
    v2.c[1] -= q->c[1];
    v2.c[2] -= q->c[2];
    func_003e40b0(&v2.c[0], &v2.c[0]);
    d = v1.c[0] * v2.c[0] + v1.c[1] * v2.c[1] + v1.c[2] * v2.c[2];
    return (1.0f - d) / 2.0f;
}

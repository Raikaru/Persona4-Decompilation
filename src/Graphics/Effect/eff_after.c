#include "include_asm.h"
/* Consolidated Persona 4 source units. */
/* Original translation unit eff_after.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

/* 12-byte vector copy; mwcc emits all loads then all stores for a struct
   assignment, matching retail, where per-element statements interleave. */
typedef struct {
    f32 c[3];
} EffAfterVec;
static inline u8 *effAfterOffsetPtr(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007146E0[];

extern void func_0044ea90(u8 *file, s32 line);
extern void func_0046d730(u8 *file, s32 line);
extern f32 RwV3dLength(void *a0);
extern void RwV3dNormalize(f32 *a, f32 *b);
extern f32 func_004b7300(void *arg0, s32 arg1);
extern s32 func_004b7800(void *arg0, s32 arg1);
extern f32 func_004bc310(u8 *arg0, s32 arg1);
extern f32 func_004bc1e0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_004bb1d0(struct EffAfterQueue *queue, s32 section);
extern void func_004b7dc0(u8 *arg0, s32 arg1, EffAfterVec *arg2);
extern void func_004b7830(u8 *arg0, s32 arg1, s32 arg2, EffAfterVec *arg3);
struct RpGeometry;
struct RpTriangle { u16 vertIndex[3]; u16 matIndex; };
struct RpMaterial;
extern const struct RpGeometry *func_003c2130(const struct RpGeometry *, struct RpTriangle *, u16, u16, u16);
extern struct RpGeometry *func_003c2150(struct RpGeometry *, struct RpTriangle *, struct RpMaterial *);
extern struct RpGeometry *func_003c2630(s32 nVtx, s32 nIdx, u32 flags);
extern void func_004bc540(u8 *work, s32 side, u8 *out, f32 t);

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
            sectionLength += RwV3dLength(&leadingDelta.c[0]);
            vectorBase = (u8 *)*(s32 *)(data + 0x14);
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            leadingDelta.c[0] = nextX - firstSample->c[0];
            leadingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            leadingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += RwV3dLength(&leadingDelta.c[0]);
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
            sectionLength += RwV3dLength(&trailingDelta.c[0]);
            vectorBase = (u8 *)*(s32 *)(data + 0x14);
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            trailingDelta.c[0] = nextX - firstSample->c[0];
            trailingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            trailingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += RwV3dLength(&trailingDelta.c[0]);
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
        RwV3dNormalize(&sideDelta.c[0], &sideDelta.c[0]);
        pointRow = points[selected];
        point = pointRow[other];
        projection = point->c[0];
        forward.c[0] = projection - points[0][0]->c[0];
        forward.c[1] = point->c[1] - points[0][0]->c[1];
        forward.c[2] = point->c[2] - points[0][0]->c[2];
        RwV3dNormalize(&forward.c[0], &forward.c[0]);
        normal.c[0] = sideDelta.c[1] * forward.c[2] - sideDelta.c[2] * forward.c[1];
        normal.c[1] = sideDelta.c[2] * forward.c[0] - sideDelta.c[0] * forward.c[2];
        normal.c[2] = sideDelta.c[0] * forward.c[1] - sideDelta.c[1] * forward.c[0];
        RwV3dNormalize(&normal.c[0], &normal.c[0]);
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
        RwV3dNormalize(&output->c[0], &axis.c[0]);
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
        RwV3dNormalize(&sideDelta.c[0], &sideDelta.c[0]);
        pointRow = points[selected];
        point = pointRow[other];
        projection = point->c[0];
        forward.c[0] = projection - points[0][0]->c[0];
        forward.c[1] = point->c[1] - points[0][0]->c[1];
        forward.c[2] = point->c[2] - points[0][0]->c[2];
        RwV3dNormalize(&forward.c[0], &forward.c[0]);
        normal.c[0] = sideDelta.c[1] * forward.c[2] - sideDelta.c[2] * forward.c[1];
        normal.c[1] = sideDelta.c[2] * forward.c[0] - sideDelta.c[0] * forward.c[2];
        normal.c[2] = sideDelta.c[0] * forward.c[1] - sideDelta.c[1] * forward.c[0];
        RwV3dNormalize(&normal.c[0], &normal.c[0]);
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
        RwV3dNormalize(&output->c[0], &axis.c[0]);
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
        leadingLength = RwV3dLength(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - secondTrailing->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - secondTrailing->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - secondTrailing->c[2];
        trailingLength = RwV3dLength(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - firstLeading->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - firstLeading->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - firstLeading->c[2];
        RwV3dNormalize(&leadingDelta.c[0], &leadingDelta.c[0]);
        secondSide.c[0] = secondTrailing->c[0] - secondLeading->c[0];
        secondSide.c[1] = secondTrailing->c[1] - secondLeading->c[1];
        secondSide.c[2] = secondTrailing->c[2] - secondLeading->c[2];
        RwV3dNormalize(&secondSide.c[0], &secondSide.c[0]);
        normal.c[0] = leadingDelta.c[1] * secondSide.c[2] - leadingDelta.c[2] * secondSide.c[1];
        normal.c[1] = leadingDelta.c[2] * secondSide.c[0] - leadingDelta.c[0] * secondSide.c[2];
        normal.c[2] = leadingDelta.c[0] * secondSide.c[1] - leadingDelta.c[1] * secondSide.c[0];
        RwV3dNormalize(&normal.c[0], &normal.c[0]);
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
        leadingLength = RwV3dLength(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - secondTrailing->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - secondTrailing->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - secondTrailing->c[2];
        trailingLength = RwV3dLength(&leadingDelta.c[0]);
        leadingDelta.c[0] = firstTrailing->c[0] - firstLeading->c[0];
        leadingDelta.c[1] = firstTrailing->c[1] - firstLeading->c[1];
        leadingDelta.c[2] = firstTrailing->c[2] - firstLeading->c[2];
        RwV3dNormalize(&leadingDelta.c[0], &leadingDelta.c[0]);
        secondSide.c[0] = secondTrailing->c[0] - secondLeading->c[0];
        secondSide.c[1] = secondTrailing->c[1] - secondLeading->c[1];
        secondSide.c[2] = secondTrailing->c[2] - secondLeading->c[2];
        RwV3dNormalize(&secondSide.c[0], &secondSide.c[0]);
        normal.c[0] = secondSide.c[1] * leadingDelta.c[2] - secondSide.c[2] * leadingDelta.c[1];
        normal.c[1] = secondSide.c[2] * leadingDelta.c[0] - secondSide.c[0] * leadingDelta.c[2];
        normal.c[2] = secondSide.c[0] * leadingDelta.c[1] - secondSide.c[1] * leadingDelta.c[0];
        RwV3dNormalize(&normal.c[0], &normal.c[0]);
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
/* Ribbon vertex attributes and bounding-volume storage. */
typedef struct RwTexCoords { f32 u, v; } AfterTexCoord;
typedef struct RwV3d { f32 x, y, z; } AfterVector3;

// FUN_004B8350
#pragma push
#pragma opt_loop_invariants on
u8 *func_004b8350(u8 *arg0, struct RpMaterial *arg1)
{
    typedef struct RwSphere {
        AfterVector3 center;
        f32 radius;
    } AfterSphere;
    AfterSphere sphere;
    u8 *cfg;
    u8 *obj;
    struct RpTriangle *idx;
    struct RpTriangle *firstStripTriangle;
    struct RpTriangle *secondStripTriangle;
    struct RpTriangle *materialTriangle;
    u8 *col;
    AfterTexCoord *uv;
    AfterTexCoord *p;
    s32 nVtx;
    s32 nIdx;
    u32 flags;
    s32 n;
    s32 last;
    s32 v;
    s32 i;
    f32 t;
    f32 denom;

    flags = 0x4A;
    if ((**(u32 **)(*(s32 *)arg0 + 4) & 1) != 0) {
        flags |= 4;
    }
    nIdx = 0;
    nVtx = 0;
    switch (*(s16 *)(arg0 + 0x38)) {
    case 0:
        n = *(s32 *)(*(u8 **)arg0 + 0xC);
        nIdx = (n - 1) * 2 + 1;
        nVtx = n * 2 + 1;
        break;
    case 1:
        n = *(s32 *)(*(u8 **)arg0 + 0xC);
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    case 2:
        n = *(s32 *)(*(u8 **)arg0 + 0xC);
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    }
    obj = (u8 *)func_003c2630(nVtx, nIdx, flags);
    idx = *(struct RpTriangle **)(obj + 0x2C);
    switch (*(s16 *)(arg0 + 0x38)) {
    case 0:
        for (i = 0; i < *(s32 *)(*(u8 **)arg0 + 0xC) - 1; i++) {
            s32 next;
            s32 mid;

            v = i * 2;
            next = v + 2;
            mid = v + 1;
            func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(idx), v, mid, next);
            func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(idx + 1), mid, v + 3, next);
            idx += 2;
        }
        v = i * 2;
        func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(idx), v, v + 1, v + 2);
        break;
    case 1:
        {
            s32 stripIndex;
            u16 stripVertex;
            firstStripTriangle = idx;
            func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle), 0, 3, 2);
            func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle + 1), 2, 4, 1);
            firstStripTriangle += 2;
            stripVertex = 2;
            for (stripIndex = 0; stripIndex < *(s32 *)(*(u8 **)arg0 + 0xC); stripIndex++) {
                s32 base;
                s32 next;
                s32 a;
                s32 b;

                base = stripVertex;
                next = base + 3;
                a = base + 1;
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle), stripVertex, a, next);
                b = base + 2;
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle + 1), stripVertex, next, b);
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle + 2), a, base + 4, next);
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle + 3), b, next, base + 5);
                firstStripTriangle += 4;
                stripVertex += 3;
            }
            {
                s32 base;
                s32 next;

                base = stripVertex;
                next = base + 3;
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle), stripVertex, base + 1, next);
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(firstStripTriangle + 1), stripVertex, next, base + 2);
            }
        }
        break;
    case 2:
        {
            s32 stripIndex;
            u16 stripVertex;
            secondStripTriangle = idx;
            func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle), 0, 3, 2);
            func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle + 1), 2, 4, 1);
            secondStripTriangle += 2;
            stripVertex = 2;
            for (stripIndex = 0; stripIndex < *(s32 *)(*(u8 **)arg0 + 0xC); stripIndex++) {
                s32 base;
                s32 next;
                s32 a;
                s32 b;

                base = stripVertex;
                next = base + 3;
                a = base + 1;
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle), stripVertex, a, next);
                b = base + 2;
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle + 1), stripVertex, next, b);
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle + 2), a, base + 4, next);
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle + 3), b, next, base + 5);
                secondStripTriangle += 4;
                stripVertex += 3;
            }
            {
                s32 base;
                s32 next;

                base = stripVertex;
                next = base + 3;
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle), stripVertex, base + 1, next);
                func_003c2130((const struct RpGeometry *)obj, (struct RpTriangle *)(secondStripTriangle + 1), stripVertex, next, base + 2);
            }
        }
        break;
    }
    {
        s32 attributeIndex;
        materialTriangle = *(struct RpTriangle **)(obj + 0x2C);
        for (attributeIndex = 0; attributeIndex < nIdx;) {
            func_003c2150((struct RpGeometry *)obj, (struct RpTriangle *)materialTriangle, arg1);
            attributeIndex++;
            materialTriangle++;
        }
        switch (*(s16 *)(arg0 + 0x38)) {
        case 0:
            col = *(u8 **)(obj + 0x30);
            for (attributeIndex = 0; attributeIndex < *(s32 *)(*(u8 **)arg0 + 0xC);) {
                if (attributeIndex == 0) {
                    t = (f32)attributeIndex / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                } else {
                    t = ((f32)attributeIndex - 0.5f) / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                }
                func_004bc540(arg0, 0, col, t);
                attributeIndex++;
                col += 8;
            }
            func_004bc540(arg0, 0, col, 1.0f);
            {
                s32 rightIndex;
                u8 *rightColor;
                rightColor = *(u8 **)(obj + 0x30) + 4;
                for (rightIndex = 0; rightIndex < *(s32 *)(*(u8 **)arg0 + 0xC);) {
                    t = (f32)rightIndex / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                    func_004bc540(arg0, 1, rightColor, t);
                    rightIndex++;
                    rightColor += 8;
                }
            }
            break;
        case 1:
            {
                s32 k;
                u8 *c;

                c = *(u8 **)(obj + 0x30);
                for (k = 0; k < nVtx;) {
                    c[0] = 0;
                    c[1] = 0;
                    c[2] = 0;
                    c[3] = 0;
                    k++;
                    c += 4;
                }
            }
            break;
        case 2:
            {
                s32 k;
                u8 *c;

                c = *(u8 **)(obj + 0x30);
                for (k = 0; k < nVtx;) {
                    c[0] = 0;
                    c[1] = 0;
                    c[2] = 0;
                    c[3] = 0;
                    k++;
                    c += 4;
                }
            }
            break;
        }
        cfg = *(u8 **)arg0;
        if ((**(u32 **)(cfg + 4) & 1) != 0) {
            switch (*(s16 *)(arg0 + 0x38)) {
            case 0:
                uv = *(AfterTexCoord **)(obj + 0x34);
                for (attributeIndex = 0; attributeIndex < *(s32 *)(*(u8 **)arg0 + 0xC);) {
                    if (*(s32 *)(*(u8 **)arg0 + 0xC) - 1 <= 0) {
                        func_0046d730(D_007146E0, 0x226);
                    }
                    if (attributeIndex == 0) {
                        uv[0].u = (f32)attributeIndex / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                    } else {
                        uv[0].u = ((f32)attributeIndex - 0.5f) / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                    }
                    uv[0].v = 0.0f;
                    attributeIndex++;
                    uv += 2;
                }
                uv[0].u = 1.0f;
                uv[0].v = 0.0f;
                {
                    s32 rightIndex;
                    AfterTexCoord *rightUV;
                    rightUV = *(AfterTexCoord **)(obj + 0x34) + 1;
                    for (rightIndex = 0; rightIndex < *(s32 *)(*(u8 **)arg0 + 0xC);) {
                        if (*(s32 *)(*(u8 **)arg0 + 0xC) - 1 <= 0) {
                            func_0046d730(D_007146E0, 0x234);
                        }
                        rightUV[0].u = (f32)rightIndex / (f32)(*(s32 *)(*(u8 **)arg0 + 0xC) - 1);
                        rightUV[0].v = 1.0f;
                        rightIndex++;
                        rightUV += 2;
                    }
                }
                break;
            case 1:
                uv = *(AfterTexCoord **)(obj + 0x34);
                n = *(s32 *)(cfg + 0xC);
                last = n * 3 + 6;
                denom = 0.5f + (f32)n;
                uv[0].u = 0.0f;
                uv[0].v = 0.0f;
                uv[1].u = 0.0f;
                uv[1].v = 1.0f;
                uv[2].u = 0.0f;
                uv[2].v = 0.5f;
                p = (AfterTexCoord *)effAfterOffsetPtr(last * sizeof(AfterTexCoord), (u8 *)uv);
                p[-3].u = 1.0f;
                p[-3].v = 0.0f;
                p[-2].u = 1.0f;
                p[-2].v = 1.0f;
                p[-1].u = 1.0f;
                p[-1].v = 0.5f;
                {
                    AfterTexCoord *q;
                    s32 k;
                    f32 h;
                    f32 step;
                    f32 u;

                    u = 1.0f / denom;
                    step = u;
                    h = 0.5f / denom;
                    q = uv + 3;
                    k = 0;
                    while (k < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                        q[0].u = h;
                        q[0].v = 0.0f;
                        q[1].u = h;
                        q[1].v = 1.0f;
                        q += 3;
                        k++;
                        h += step;
                    }
                    {
                        s32 centerIndex;
                        AfterTexCoord *center;
                        center = uv + 5;
                        centerIndex = 0;
                        while (centerIndex < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                            center[0].u = u;
                            center[0].v = 0.5f;
                            centerIndex++;
                            u += step;
                            center += 3;
                        }
                    }
                }
                break;
            case 2:
                uv = *(AfterTexCoord **)(obj + 0x34);
                n = *(s32 *)(cfg + 0xC);
                last = n * 3 + 6;
                denom = 0.5f + (f32)n;
                uv[0].u = 0.0f;
                uv[0].v = 0.0f;
                uv[1].u = 0.0f;
                uv[1].v = 1.0f;
                uv[2].u = 0.0f;
                uv[2].v = 0.5f;
                p = (AfterTexCoord *)effAfterOffsetPtr(last * sizeof(AfterTexCoord), (u8 *)uv);
                p[-3].u = 1.0f;
                p[-3].v = 0.0f;
                p[-2].u = 1.0f;
                p[-2].v = 1.0f;
                p[-1].u = 1.0f;
                p[-1].v = 0.5f;
                {
                    s32 k;
                    AfterTexCoord *q;
                    f32 u;
                    f32 step;
                    f32 h;

                    u = 1.0f / denom;
                    step = u;
                    h = 0.5f / denom;
                    q = uv + 3;
                    k = 0;
                    while (k < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                        q[0].u = h;
                        q[0].v = 0.0f;
                        q[1].u = h;
                        q[1].v = 1.0f;
                        q += 3;
                        k++;
                        h += step;
                    }
                    {
                        s32 centerIndex;
                        AfterTexCoord *center;
                        center = uv + 5;
                        centerIndex = 0;
                        while (centerIndex < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                            center[0].u = u;
                            center[0].v = 0.5f;
                            centerIndex++;
                            u += step;
                            center += 3;
                        }
                    }
                }
                break;
            }
        }
    }
    sphere.center.x = 0.0f;
    sphere.center.y = 0.0f;
    sphere.center.z = 0.0f;
    sphere.radius = 1000000000;
    *(AfterSphere *)(*(u8 **)(obj + 0x5C) + 4) = sphere;
    return obj;
}
#pragma pop
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
/* Cold 004b8f40 (1932 instrs, frame -0x1A0 s19-s23/s30): no probe_archive */
/* entry; m2c (u8*,void**) + romwright (u8*,int*) agree on signature (pointer */
/* + pointer-to-pointer), m2c has 63 M2C_ERROR (mula/madd/msub) vs rw 0 errors */
/* with counted fors (correct, not do/while). Stripped rw skeleton (FUN_->D_, */
/* true->1, ._4_4_->u32>>32, void*+int->(u8*)*+int, externs stripped): retail */
/* 1932/object 2721 (+40%, +789) edits 4101+6 gate outside (needs 1874-1990). */
/* Surplus is one 436-instr pure lump [503] (duplicated phase where retail */
/* shares) + 21 lq/sq field-by-field (+147) + (u32)float dances (+100) + FPU */
/* mula folds (+63) =746; 2721-746=1975 inside. Front-load (s32) everywhere */
/* (<2^31) + whole u_long128 moves + share duplicated block. Not banked. */
/* Remeasure 2026-09-19: retail 1929 vs object 1877 (-52), words 1895, fnalign 2909 edits. Frame 0x220 vs 0x1A0 (+0x80) with spare $f25-$f31 (7 floats, no GPR diff). Switch spelling on final temp_v0 chain (switch(temp_v0){case 2:{...}break;case 1:{...}break;case 0:{...}break;}) via /var/tmp/effect/after_switch.c measures 2914 edits (+5 vs 2909 if-chain, object 1879 vs 1877) so keep if-chain. Seven live across final-else temp_v0==2 loop calls (func_004b7460 + 3x func_003e40b0): temp_v9 (*(work+0x14)/2.0, retail $f24 at 004BA27C/004BA688), temp_v11 (1/(n+0.5), retail $f21 at 004BA2D0), temp_v7 (0.5/(n+0.5), retail $f20 at 004BA2D4), fStack_28/24/20 (Bezier xyz, retail spills to 0x178/0x17C/0x180 at 004BA4B4 and reloads at 004BA568/004BA6B0), fStack_30 (prev z, retail spills to 0x170 at 004BA320 and reloads at 004BA5C4). First three also held in retail so sinking (duplicate div, cf. distort t0/t1 sink 886->930 +44) would worsen; last four spilled in retail via swc1/lwc1 vs held in regs via scalar promotion (address never taken, so MWCC keeps in callee-saved); legitimate spill without volatile/asm barrier not found (EffAfterVec struct assignment still promotes, volatile banned per lint), and recomputing Bezier after calls duplicates 20+ mula/madd muls vs retail 6 spill loads/stores. Cannot be sunk without worsening; needs declaration/boundary change (array/struct forcing memory) not expression rewrite. */
/* Accum/guard 2026-09-19 (base 2909 edits/1850 words/1877 instrs vs retail 1929): 9 Bezier sites probed as 3 group1 X/Y/Z factored t*(t*(P*t))+u*(t*((3*Q)*t))+u*(u*(R*u))+u*(u*((3*S)*t)) -> 2910 edits (+1)/1849 words (-1)/1876 instrs (-1) tie; same 3 reversed S+R+Q+P -> 2909/1850 tie; 3 dots reversed e*f+c*d+a*b -> 2909/1850 tie; 3 widths temp*(temp*temp) -> 2909/1850 tie; pragmas noprop/prop_off/inv_off -> 1851 (+1)/1861 (+11)/1851 (+1) words worse; 7n fresh temp_v12 for 3 zero-fills -> 2942 edits (+33)/1849 (-1)/1877 tie worse; guards 0 sites (no 2.1474836e9f/0x80000000 in file, residual_signature 0 conversion). Production rewrote 0 sites (floor untouched per 7l, ties recorded). Remaining -52/edits systematic (frame 0x220 vs 0x1A0, 7 extra f25-f31) per existing note, needs declaration/boundary not expression. */
/* measured 004b8f40 (owner, 2026-09-19): fnalign **2909 -> 2907 edits**, count
   1877 -> 1875 against retail 1929, converting a SECOND constant-bound `for` loop
   to `do { } while` after the first conversion was already banked.
   The lever is iterative, which the first sweep hid: it converts the single best loop
   per function, so re-running it after installing finds the next one.  The third pass
   improved 14 more floors, `func_001ed700` by 89 edits on its own. */
/* measured 004b8f40 (2026-09-20): fnalign 2907 -> 1716 edits, words 1848 -> 1807,
   object 1875 -> 1932 instrs against retail 1929 (exact count). Spill gap IS
   reachable from source. regsave_scan showed the object saving $f25-$f31 at frame
   0x220 where retail saves $f20-$f24 at frame 0x1A0. Three composed changes:
   (a) 26 f32 intermediates (fetch/diff/sum/prev/bezier/norm trios) into one
   address-taken struct S (12 -> 6 saved FPRs; address-taken scalars and plain
   arrays do NOT drop saves, the aggregate does); (b) u64 prev/first-point puns
   (uStack_38/68) as plain struct floats (retail has plain moves, no sll/or);
   (c) the three temp_v0 ==2/1/0 dispatch chains rewired to check-2,1,0 with bodies
   laid 0,1,2 via goto (retail checks 2,1,0 with an explicit 0-check but lays out
   bodies 0,1,2; a plain if/else-if lays 2,1,0). Exact retail saved set $f20-$f24
   reproduced two ways (fStack_20 scalar, temp_v10 scalar) but both measure worse in
   words (1812 vs 1807: layout dominates), so the 6-save goto body stands.
   Remaining: 13 hoisted quadword address spills (frame 0x220 vs 0x1A0; retail
   recomputes the ==1/==2-nest addresses per fetch and hoists only the ==0 outer
   address to slot 192 plus $s7) and GPR colouring/member order. Do NOT repeat the
   nine banned accumulator spellings (all neutral/worse) or switch spelling (+5).
   2026-10-08: opt_dead_assignments off with opt_lifetimes on lowers fnalign from 1756 to 1368 edits.
 * 2026-10-09: 1368 -> 1297: the Ghidra stack scalars that share one 16-byte slot are
 * one f32 array local (retail keeps that slot in memory).
 * (cleanup: address-of casts simplified)
 * 1269: type sweep.
 * 1262: conversion lever (pbVar2:(1, 3)).
 * fnalign 1262 -> 1252: the three phase dispatches are switches (cases 0, 1, 2 in written order).
 * fnalign 1252 -> 1236: phase-0 colour loops in the sibling func_004b8350 form (count re-read per use, (f32)i at i == 0, i++ / col += 8 at the bottom).
 * fnalign 1236 -> 1200: phase-1 colours in retail order (hoisted 1/denom step, cursor advanced 4/4/4, four-tap average summed inner-first).
 * fnalign 1200 -> 1195: phase-1 cursor uses u32* post-increments (retail's interleaved advance), (f32)n converted before adding 0.5.
 * fnalign 1195 -> 1190: phase-2 colours in retail order.
 * fnalign 1190 -> 1184: the second 1/denom is recomputed ((f32) cast keeps it out of CSE, as retail).
 * fnalign 1184 -> 1074: phase-B clears in retail order (no offset helper, counters advanced before the cursor, limits computed first).
 * fnalign 1074 -> 1058: phase C without the offset helper.
 * fnalign 1058 -> 1041: phase-C span limit as a switch, segment cache updated first, (f32)i at i == 0.
 * phase-C outer loop test-first.
 * fnalign 1040 -> 854: stack locals declared as retail's vec3 blocks (fraction/section on top, then v188..first, last, the bounding sphere and ctrl[4]); control-point ends built by struct copy.
 * fnalign 1040 -> 643: retail vec3 stack locals (fraction/section, v188, cur, prev, v158, v148, first, last, bound sphere, ctrl[4]); control-point ends, cur/prev/first and the bound sphere copied as structs; strip-loop field loads written directly from work (one shared *(work + 0x10)) so they are not hoisted as invariant addresses.
 * fnalign 643 -> 505: Bezier terms written P0*s*s*s + 3*P1*t*s*s + 3*P2*t*t*s + P3*t*t*t (retail's accumulate order).
 * fnalign 505 -> 487: phase-C strip side offset as a switch (case 0 then 1); segment cache updated at the top of the recompute block.
 * camera-target components read as pfVar16[1]/[2].
 * fnalign 484 -> 404: temp_v2 is s32 (retail keeps its wrap test); case-2 segment cache updated at the top of the recompute block.
 * fnalign 404 -> 279: dot products summed y, x, z; cubes computed in their own statement (retail does not fuse 1 - d^3); case-2 strip loop bottom-tested with the output cursor starting at +9 floats and advanced before prev = cur; tail index from n*3 + 6.
 */
// FUN_004B8F40 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
#pragma opt_propagation on
#pragma opt_loop_invariants on
typedef struct {
    EffAfterVec center;
    f32 radius;
} EffAfterSphere;

void func_004b8f40(u8 *work, void **pp)

{
/* irregular: 5 native warning(s); review required */
  s16 temp_v0;
  u8 *pbVar2;
  f32 *pfVar3;
  u64 *puVar4;
  f32 *pfVar5;
  f32 *pfVar6;
  s32 temp_v1;
  s32 temp_v2;
  s32 temp_v3;
  u32 *puVar10;
  s32 temp_v4;
  u8 *pbVar12;
  u32 *puVar13;
  s32 temp_v5;
  u32 temp_v6;
  f32 *unaff_s3_lo;
  f32 *pfVar16;
  f32 *pfVar17;
  f32 temp_v7;
  f32 temp_v8;
  f32 temp_v9;
  f32 temp_v10;
  f32 temp_v11;
  s32 iStack_d0;
  f32 fraction;
  u32 section;
  EffAfterVec v188;
  EffAfterVec cur;
  EffAfterVec prev;
  EffAfterVec v158;
  EffAfterVec v148;
  EffAfterVec first;
  EffAfterVec last;
  EffAfterSphere bound;
  EffAfterVec ctrl[4];
  
  RpGeometryLock(*pp,0x1a);
  if (((*(u32 *)effAfterOffsetPtr(4, work) & 1) != 0) || ((~*(u32 *)effAfterOffsetPtr(4, work) & 2) != 0)) {
    switch (*(s16 *)effAfterOffsetPtr(0x38, work)) {
    case 0:
    {
      pbVar12 = *(u8 **)(*(u8 **)pp + 0x30);
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC);) {
        if (*(s32 *)(*(u8 **)work + 0xC) - 1 < 1) {
          func_0046d730(D_007146E0,0x3d1);
        }
        if (temp_v5 == 0) {
          fraction = (f32)temp_v5 / (f32)(*(s32 *)(*(u8 **)work + 0xC) - 1);
        }
        else {
          fraction = ((f32)temp_v5 - 0.5f) / (f32)(*(s32 *)(*(u8 **)work + 0xC) - 1);
        }
        func_004bc540(work,0,pbVar12,fraction);
        temp_v5++;
        pbVar12 += 8;
      }
      func_004bc540(work,0,pbVar12,1.0f);
      pbVar12 = *(u8 **)(*(u8 **)pp + 0x30) + 4;
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC);) {
        if (*(s32 *)(*(u8 **)work + 0xC) - 1 < 1) {
          func_0046d730(D_007146E0,0x3dc);
        }
        fraction = (f32)temp_v5 / (f32)(*(s32 *)(*(u8 **)work + 0xC) - 1);
        func_004bc540(work,1,pbVar12,fraction);
        temp_v5++;
        pbVar12 += 8;
      }
    }
    break;
    case 1:
    {
      pbVar12 = *(u8 **)(*(u8 **)pp + 0x30);
      func_004bc540(work,0,pbVar12,0.0f);
      func_004bc540(work,1,pbVar12 + 4,0.0f);
      pbVar12[8] = (u8)((s32)((u32)pbVar12[0] + (u32)pbVar12[4]) >> 1);
      pbVar12[9] = (u8)((s32)((u32)pbVar12[1] + (u32)pbVar12[5]) >> 1);
      pbVar12[10] = (u8)((s32)((u32)pbVar12[2] + (u32)pbVar12[6]) >> 1);
      pbVar12[0xb] = (u8)((s32)((u32)pbVar12[3] + (u32)pbVar12[7]) >> 1);
      temp_v1 = *(s32 *)(*(u8 **)work + 0xC) * 3 + 6;
      func_004bc540(work,0,pbVar12 + (temp_v1 - 3) * 4,1.0f);
      func_004bc540(work,1,pbVar12 + (temp_v1 - 2) * 4,1.0f);
      pbVar2 = temp_v1 * 4 + pbVar12;
      pbVar2[-4] = (u8)((s32)((u32)pbVar2[-0xc] + (u32)pbVar2[-8]) >> 1);
      pbVar2[-3] = (u8)((s32)((u32)pbVar2[-0xb] + (u32)pbVar2[-7]) >> 1);
      pbVar2[-2] = (u8)((s32)((u32)pbVar2[-10] + (u32)pbVar2[-6]) >> 1);
      pbVar2[-1] = (u8)((s32)((u32)pbVar2[-9] + (u32)pbVar2[-5]) >> 1);
      temp_v7 = (f32)*(s32 *)(*(u8 **)work + 0xC);
      temp_v7 = 0.5f + temp_v7;
      temp_v10 = 1.0f / temp_v7;
      puVar10 = (u32 *)(pbVar12 + 0xc);
      temp_v9 = 0.5f / temp_v7;
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC);) {
        func_004bc540(work,0,(u8 *)puVar10++,temp_v9);
        func_004bc540(work,1,(u8 *)puVar10++,temp_v9);
        puVar10++;
        temp_v5++;
        temp_v9 += temp_v10;
      }
      pbVar12 = pbVar12 + 0x14;
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC);) {
        pbVar12[0] = (u8)((s32)((u32)pbVar12[8] + ((u32)pbVar12[4] + ((u32)pbVar12[-8] + (u32)pbVar12[-4]))) >> 2);
        pbVar12[1] = (u8)((s32)((u32)pbVar12[9] + ((u32)pbVar12[5] + ((u32)pbVar12[-7] + (u32)pbVar12[-3]))) >> 2);
        pbVar12[2] = (u8)((s32)((u32)pbVar12[10] + ((u32)pbVar12[6] + ((u32)pbVar12[-6] + (u32)pbVar12[-2]))) >> 2);
        pbVar12[3] = (u8)((s32)((u32)pbVar12[0xb] + ((u32)pbVar12[7] + ((u32)pbVar12[-5] + (u32)pbVar12[-1]))) >> 2);
        temp_v5++;
        pbVar12 += 0xc;
      }
    }
    break;

    case 2:
    {
      pbVar12 = *(u8 **)(*(u8 **)pp + 0x30);
      func_004bc540(work,1,pbVar12,0.0f);
      func_004bc540(work,1,pbVar12 + 4,0.0f);
      temp_v3 = *(s32 *)(*(u8 **)work + 0xC) * 3 + 6;
      func_004bc540(work,1,pbVar12 + (temp_v3 - 3) * 4,1.0f);
      func_004bc540(work,1,pbVar12 + (temp_v3 - 2) * 4,1.0f);
      temp_v9 = (f32)*(s32 *)(*(u8 **)work + 0xC);
      temp_v9 = 0.5f + temp_v9;
      temp_v7 = 1.0f / temp_v9;
      puVar10 = (u32 *)(pbVar12 + 0xc);
      temp_v11 = 0.5f / temp_v9;
      for (temp_v1 = 0; temp_v1 < *(s32 *)(*(u8 **)work + 0xC);) {
        func_004bc540(work,1,(u8 *)puVar10++,temp_v11);
        func_004bc540(work,1,(u8 *)puVar10++,temp_v11);
        puVar10++;
        temp_v1++;
        temp_v11 += temp_v7;
      }
      func_004bc540(work,0,pbVar12 + 8,0.0f);
      func_004bc540(work,0,pbVar12 + (temp_v3 - 1) * 4,1.0f);
      temp_v7 = 1.0f / (f32)temp_v9;
      temp_v11 = temp_v7;
      pbVar12 += 0x14;
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC);) {
        func_004bc540(work,0,pbVar12,temp_v11);
        temp_v5++;
        temp_v11 += temp_v7;
        pbVar12 += 0xc;
      }
    }
    }
    *(u32 *)effAfterOffsetPtr(4, work) = *(u32 *)effAfterOffsetPtr(4, work) | 2;
  }
  if (*(s32 *)(work + 8) < 2) {
    switch (*(s16 *)(work + 0x38)) {
    case 0:
    {
      puVar13 = *(u32 **)(*(u8 **)(*(u8 **)pp + 0x5c) + 0x14);
      puVar10 = puVar13 + *(s32 *)(*(u8 **)pp + 0x14) * 3;
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC) + 1;) {
        if (puVar10 == puVar13) {
          func_0046d730(D_007146E0,0x43c);
        }
        puVar13[0] = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        temp_v5++;
        puVar13 += 6;
      }
      puVar13 = (u32 *)(*(u8 **)(*(u8 **)(*(u8 **)pp + 0x5c) + 0x14) + 0xc);
      for (temp_v5 = 0; temp_v5 < *(s32 *)(*(u8 **)work + 0xC);) {
        if (puVar10 == puVar13) {
          func_0046d730(D_007146E0,0x446);
        }
        puVar13[0] = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        temp_v5++;
        puVar13 += 6;
      }
    }
    break;
    case 1:
    {
      temp_v5 = *(s32 *)(*(u8 **)work + 0xC) * 3 + 6;
      puVar13 = *(u32 **)(*(u8 **)(*(u8 **)pp + 0x5c) + 0x14);
      for (temp_v1 = 0; temp_v1 < temp_v5;) {
        puVar13[0] = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        temp_v1++;
        puVar13 += 3;
      }
    }
    break;
    case 2:
    {
      temp_v5 = *(s32 *)(*(u8 **)work + 0xC) * 3 + 6;
      puVar13 = *(u32 **)(*(u8 **)(*(u8 **)pp + 0x5c) + 0x14);
      for (temp_v1 = 0; temp_v1 < temp_v5;) {
        puVar13[0] = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        temp_v1++;
        puVar13 += 3;
      }
    }
    }
  }
  else {
    switch (*(s16 *)((work) + 0x38)) {
    case 0:
    {
      temp_v5 = *(s32 *)(*(s32 *)(((u8 *)*pp) + 0x5c) + 0x14);
      pfVar17 = (f32 *)(temp_v5 + *(s32 *)(((u8 *)*pp) + 0x14) * 0xc);
      for (temp_v1 = 0; temp_v1 < 2;) {
        pfVar16 = (f32 *)(temp_v5 + temp_v1 * 0xc);
        temp_v6 = 0xffffffff;
        switch (temp_v1) {
        case 0:
          iStack_d0 = *(s32 *)((*(u8 **)work) + 0xc);
          break;
        case 1:
          iStack_d0 = *(s32 *)((*(u8 **)work) + 0xc) - 1;
          break;
        }
        for (temp_v4 = 0; temp_v4 < iStack_d0; temp_v4 = temp_v4 + 1) {
          if (*(s32 *)((*(u8 **)work) + 0xc) - 1 < 1) {
            func_0046d730(D_007146E0,0x480);
          }
          if (temp_v1 == 0) {
            if (temp_v4 == 0) {
              func_004b7460(work,(f32)temp_v4 / (f32)(*(s32 *)((*(u8 **)work) + 0xc) - 1),&section,
                            &fraction);
            }
            else {
              func_004b7460(work,((f32)temp_v4 - 0.5f) /
                                    (f32)(*(s32 *)((*(u8 **)work) + 0xc) - 1),&section,&fraction
                           );
            }
          }
          else {
            func_004b7460(work,(f32)temp_v4 / (f32)(*(s32 *)((*(u8 **)work) + 0xc) - 1),
                          &section,&fraction);
          }
          if (section != temp_v6) {
            temp_v6 = section;
            temp_v3 = (*(s32 *)((work) + 0xc) - 1) - section;
            if (temp_v3 < 0) {
              temp_v3 = temp_v3 + *(s32 *)((work) + 8);
            }
            temp_v2 = (*(s32 *)((work) + 0xc) - 1) - (section + 1);
            if (temp_v2 < 0) {
              temp_v2 = temp_v2 + *(s32 *)((work) + 8);
            }
            temp_v3 = temp_v3 * 0xc;
            pfVar5 = (f32 *)(*(s32 *)(((work) + temp_v1 * 4 + 0x10)) + temp_v3);
            ctrl[0] = *(EffAfterVec *)pfVar5;
            pfVar3 = (f32 *)(*(s32 *)(((work) + temp_v1 * 8 + 0x18)) + temp_v3);
            ctrl[1].c[0] = *pfVar5 - *pfVar3;
            ctrl[1].c[1] = pfVar5[1] - pfVar3[1];
            ctrl[1].c[2] = pfVar5[2] - pfVar3[2];
            pfVar5 = (f32 *)(*(s32 *)(((work) + temp_v1 * 8 + 0x1c)) + temp_v3);
            pfVar3 = (f32 *)(*(s32 *)(((work) + temp_v1 * 4 + 0x10)) + temp_v2 * 0xc);
            ctrl[2].c[0] = *pfVar3 + *pfVar5;
            ctrl[2].c[1] = pfVar3[1] + pfVar5[1];
            ctrl[2].c[2] = pfVar3[2] + pfVar5[2];
            ctrl[3] = *(EffAfterVec *)pfVar3;
          }
          temp_v7 = 1.0f - fraction;
          if (!(pfVar16 < pfVar17)) {
            func_0046d730(D_007146E0,0x49d);
          }
          *pfVar16 = ctrl[0].c[0] * temp_v7 * temp_v7 * temp_v7 + 3.0f * ctrl[1].c[0] * fraction * temp_v7 * temp_v7 + 3.0f * ctrl[2].c[0] * fraction * fraction * temp_v7 + ctrl[3].c[0] * fraction * fraction * fraction;
          pfVar16[1] = ctrl[0].c[1] * temp_v7 * temp_v7 * temp_v7 + 3.0f * ctrl[1].c[1] * fraction * temp_v7 * temp_v7 + 3.0f * ctrl[2].c[1] * fraction * fraction * temp_v7 + ctrl[3].c[1] * fraction * fraction * fraction;
          pfVar16[2] = ctrl[0].c[2] * temp_v7 * temp_v7 * temp_v7 + 3.0f * ctrl[1].c[2] * fraction * temp_v7 * temp_v7 + 3.0f * ctrl[2].c[2] * fraction * fraction * temp_v7 + ctrl[3].c[2] * fraction * fraction * fraction;
          pfVar16 = pfVar16 + 6;
        }
        temp_v4 = *(s32 *)((work) + 0xc) - *(s32 *)((work) + 8);
        if (temp_v4 < 0) {
          temp_v4 = temp_v4 + *(s32 *)((work) + 8);
        }
        if (pfVar17 <= pfVar16) {
          func_0046d730(D_007146E0,0x4ae);
        }
        pfVar3 = (f32 *)(*(s32 *)(((work) + temp_v1 * 4 + 0x10)) + temp_v4 * 0xc);
        temp_v7 = pfVar3[1];
        temp_v9 = pfVar3[2];
        *pfVar16 = *pfVar3;
        pfVar16[1] = temp_v7;
        pfVar16[2] = temp_v9;
        if (*(s32 *)((work) + 8) < *(s32 *)((*(u8 **)work) + 8)) {
          section = 0;
        }
        else {
          section = *(u32 *)((work) + 0xc);
        }
          temp_v1++;
      }
    }
    break;
    case 1:
    {
      temp_v5 = *(s32 *)((*(u8 **)work) + 0xc);
      puVar13 = *(u32 **)(*(s32 *)(((u8 *)*pp) + 0x5c) + 0x14);
      for (temp_v1 = 0; temp_v1 < temp_v5 * 3 + 6; temp_v1 = temp_v1 + 1) {
        *puVar13 = 0;
        puVar13[1] = 0;
        puVar13[2] = 0;
        puVar13 = puVar13 + 3;
      }
      pfVar17 = *(f32 **)(*(s32 *)(((u8 *)*pp) + 0x5c) + 0x14);
      temp_v5 = *(s32 *)((work) + 0xc) - 1;
      if (temp_v5 < 0) {
        temp_v5 = temp_v5 + *(s32 *)((work) + 8);
      }
      pfVar16 = (f32 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x10, work)) + temp_v5 * 0xc);
      temp_v7 = pfVar16[1];
      temp_v9 = pfVar16[2];
      *pfVar17 = *pfVar16;
      pfVar17[1] = temp_v7;
      pfVar17[2] = temp_v9;
      pfVar16 = (f32 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x14, work)) + temp_v5 * 0xc);
      temp_v7 = pfVar16[1];
      temp_v9 = pfVar16[2];
      pfVar17[3] = *pfVar16;
      pfVar17[4] = temp_v7;
      pfVar17[5] = temp_v9;
      pfVar17[6] = *pfVar17 + pfVar17[3];
      pfVar17[7] = pfVar17[1] + pfVar17[4];
      pfVar17[8] = pfVar17[2] + pfVar17[5];
      pfVar17[6] = pfVar17[6] * 0.5f;
      pfVar17[7] = pfVar17[7] * 0.5f;
      pfVar17[8] = pfVar17[8] * 0.5f;
      temp_v5 = *(s32 *)((*(u8 **)work) + 0xc) * 3 + 6;
      temp_v1 = *(s32 *)((work) + 0xc) - *(s32 *)((work) + 8);
      if (temp_v1 < 0) {
        temp_v1 = temp_v1 + *(s32 *)((work) + 8);
      }
      pfVar16 = (f32 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x10, work)) + temp_v1 * 0xc);
      temp_v7 = pfVar16[1];
      temp_v9 = pfVar16[2];
      pfVar17[temp_v5 * 3 - 9] = *pfVar16;
      pfVar17[temp_v5 * 3 - 8] = temp_v7;
      pfVar17[temp_v5 * 3 - 7] = temp_v9;
      pfVar16 = (f32 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x14, work)) + temp_v1 * 0xc);
      temp_v7 = pfVar16[1];
      temp_v9 = pfVar16[2];
      pfVar17[temp_v5 * 3 - 6] = *pfVar16;
      pfVar17[temp_v5 * 3 - 5] = temp_v7;
      pfVar17[temp_v5 * 3 - 4] = temp_v9;
      pfVar17[temp_v5 * 3 - 3] = pfVar17[temp_v5 * 3 - 9] + pfVar17[temp_v5 * 3 - 6];
      pfVar17[temp_v5 * 3 - 2] = pfVar17[temp_v5 * 3 - 8] + pfVar17[temp_v5 * 3 - 5];
      pfVar17[temp_v5 * 3 - 1] = pfVar17[temp_v5 * 3 - 7] + pfVar17[temp_v5 * 3 - 4];
      pfVar17[temp_v5 * 3 - 3] = pfVar17[temp_v5 * 3 - 3] * 0.5f;
      pfVar17[temp_v5 * 3 - 2] = pfVar17[temp_v5 * 3 - 2] * 0.5f;
      pfVar17[temp_v5 * 3 - 1] = pfVar17[temp_v5 * 3 - 1] * 0.5f;
      temp_v5 = *(s32 *)(*(s32 *)(((u8 *)*pp) + 0x5c) + 0x14);
      temp_v7 = (f32)*(s32 *)((*(u8 **)work) + 0xc) + 0.5f;
      temp_v9 = 1.0f / temp_v7;
      for (temp_v1 = 0; temp_v1 < 2; temp_v1 = temp_v1 + 1) {
        switch (temp_v1) {
        case 0:
          unaff_s3_lo = (f32 *)(temp_v5 + 0x24);
          break;
        case 1:
          unaff_s3_lo = (f32 *)(temp_v5 + 0x30);
          break;
        }
        temp_v11 = 0.5f / temp_v7;
        temp_v6 = 0xffffffff;
        for (temp_v4 = 0; temp_v4 < *(s32 *)((*(u8 **)work) + 0xc); temp_v4 = temp_v4 + 1) {
          func_004b7460(work,temp_v11,&section,&fraction);
          if (section != temp_v6) {
            temp_v6 = section;
            temp_v3 = (*(s32 *)((work) + 0xc) - 1) - section;
            if (temp_v3 < 0) {
              temp_v3 = temp_v3 + *(s32 *)((work) + 8);
            }
            temp_v2 = (*(s32 *)((work) + 0xc) - 1) - (section + 1);
            if (temp_v2 < 0) {
              temp_v2 = temp_v2 + *(s32 *)((work) + 8);
            }
            temp_v3 = temp_v3 * 0xc;
            pfVar16 = (f32 *)(*(s32 *)(((work) + temp_v1 * 4 + 0x10)) + temp_v3);
            ctrl[0] = *(EffAfterVec *)pfVar16;
            pfVar17 = (f32 *)(*(s32 *)(((work) + temp_v1 * 8 + 0x18)) + temp_v3);
            ctrl[1].c[0] = *pfVar16 - *pfVar17;
            ctrl[1].c[1] = pfVar16[1] - pfVar17[1];
            ctrl[1].c[2] = pfVar16[2] - pfVar17[2];
            pfVar16 = (f32 *)(*(s32 *)(((work) + temp_v1 * 8 + 0x1c)) + temp_v3);
            pfVar17 = (f32 *)(*(s32 *)(((work) + temp_v1 * 4 + 0x10)) + temp_v2 * 0xc);
            ctrl[2].c[0] = *pfVar17 + *pfVar16;
            ctrl[2].c[1] = pfVar17[1] + pfVar16[1];
            ctrl[2].c[2] = pfVar17[2] + pfVar16[2];
            ctrl[3] = *(EffAfterVec *)pfVar17;
          }
          temp_v8 = 1.0f - fraction;
          *unaff_s3_lo = ctrl[0].c[0] * temp_v8 * temp_v8 * temp_v8 + 3.0f * ctrl[1].c[0] * fraction * temp_v8 * temp_v8 + 3.0f * ctrl[2].c[0] * fraction * fraction * temp_v8 + ctrl[3].c[0] * fraction * fraction * fraction;
          unaff_s3_lo[1] =
               ctrl[0].c[1] * temp_v8 * temp_v8 * temp_v8 + 3.0f * ctrl[1].c[1] * fraction * temp_v8 * temp_v8 + 3.0f * ctrl[2].c[1] * fraction * fraction * temp_v8 + ctrl[3].c[1] * fraction * fraction * fraction;
          unaff_s3_lo[2] =
               ctrl[0].c[2] * temp_v8 * temp_v8 * temp_v8 + 3.0f * ctrl[1].c[2] * fraction * temp_v8 * temp_v8 + 3.0f * ctrl[2].c[2] * fraction * fraction * temp_v8 + ctrl[3].c[2] * fraction * fraction * fraction;
          temp_v11 = temp_v11 + temp_v9;
          unaff_s3_lo = unaff_s3_lo + 9;
        }
        unaff_s3_lo = (f32 *)(temp_v5 + 0x3c);
        for (temp_v4 = 0; temp_v4 < *(s32 *)((*(u8 **)work) + 0xc); temp_v4 = temp_v4 + 1) {
          *unaff_s3_lo = unaff_s3_lo[-6] + unaff_s3_lo[-3];
          unaff_s3_lo[1] = unaff_s3_lo[-5] + unaff_s3_lo[-2];
          unaff_s3_lo[2] = unaff_s3_lo[-4] + unaff_s3_lo[-1];
          *unaff_s3_lo = *unaff_s3_lo + unaff_s3_lo[3];
          unaff_s3_lo[1] = unaff_s3_lo[1] + unaff_s3_lo[4];
          unaff_s3_lo[2] = unaff_s3_lo[2] + unaff_s3_lo[5];
          *unaff_s3_lo = *unaff_s3_lo + unaff_s3_lo[6];
          unaff_s3_lo[1] = unaff_s3_lo[1] + unaff_s3_lo[7];
          unaff_s3_lo[2] = unaff_s3_lo[2] + unaff_s3_lo[8];
          *unaff_s3_lo = *unaff_s3_lo * 0.25f;
          unaff_s3_lo[1] = unaff_s3_lo[1] * 0.25f;
          unaff_s3_lo[2] = unaff_s3_lo[2] * 0.25f;
          unaff_s3_lo = unaff_s3_lo + 9;
        }
      }
    }
    break;
    case 2:
    {
      temp_v9 = *(f32 *)((*(u8 **)work) + 0x14) / 2.0f;
      temp_v5 = func_00457120();
      temp_v5 = *(s32 *)(((u8 *)temp_v5) + 4);
      pfVar16 = (f32 *)(temp_v5 + 0x40);
      pfVar17 = *(f32 **)(*(s32 *)(((u8 *)*pp) + 0x5c) + 0x14);
      temp_v7 = (f32)*(s32 *)((*(u8 **)work) + 0xc) + 0.5f;
      temp_v11 = 1.0f / temp_v7;
      temp_v7 = 0.5f / temp_v7;
      temp_v6 = 0xffffffff;
      temp_v1 = *(s32 *)((work) + 0xc) - 1;
      if (temp_v1 < 0) {
        temp_v1 = temp_v1 + *(s32 *)((work) + 8);
      }
      puVar4 = (u64 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x10, work)) + temp_v1 * 0xc);
      prev.c[0] = *(f32 *)puVar4; prev.c[1] = *(f32 *)(((u8 *)puVar4) + 4);
      prev.c[2] = *(f32 *)(puVar4 + 1);
      pfVar3 = pfVar17 + 9;
      for (temp_v1 = 0; temp_v1 < *(s32 *)((*(u8 **)work) + 0xc);) {
        func_004b7460(work,temp_v7,&section,&fraction);
        if (section != temp_v6) {
          temp_v6 = section;
          temp_v4 = (*(s32 *)((work) + 0xc) - 1) - section;
          if (temp_v4 < 0) {
            temp_v4 = temp_v4 + *(s32 *)((work) + 8);
          }
          temp_v3 = (*(s32 *)((work) + 0xc) - 1) - (section + 1);
          if (temp_v3 < 0) {
            temp_v3 = temp_v3 + *(s32 *)((work) + 8);
          }
          temp_v4 = temp_v4 * 0xc;
          pbVar2 = *(u8 **)(work + 0x10);
          pfVar6 = (f32 *)(pbVar2 + temp_v4);
          ctrl[0] = *(EffAfterVec *)pfVar6;
          pfVar5 = (f32 *)(((u8 *)*(u8 **)((u8 *)(work) + 0x18)) + temp_v4);
          ctrl[1].c[0] = *pfVar6 - *pfVar5;
          ctrl[1].c[1] = pfVar6[1] - pfVar5[1];
          ctrl[1].c[2] = pfVar6[2] - pfVar5[2];
          pfVar6 = (f32 *)(((u8 *)*(u8 **)((u8 *)(work) + 0x1c)) + temp_v4);
          pfVar5 = (f32 *)(pbVar2 + temp_v3 * 0xc);
          ctrl[2].c[0] = *pfVar5 + *pfVar6;
          ctrl[2].c[1] = pfVar5[1] + pfVar6[1];
          ctrl[2].c[2] = pfVar5[2] + pfVar6[2];
          ctrl[3] = *(EffAfterVec *)pfVar5;
        }
        temp_v8 = 1.0f - fraction;
        cur.c[0] = ctrl[0].c[0] * temp_v8 * temp_v8 * temp_v8 + 3.0f * ctrl[1].c[0] * fraction * temp_v8 * temp_v8 + 3.0f * ctrl[2].c[0] * fraction * fraction * temp_v8 + ctrl[3].c[0] * fraction * fraction * fraction;
        cur.c[1] = ctrl[0].c[1] * temp_v8 * temp_v8 * temp_v8 + 3.0f * ctrl[1].c[1] * fraction * temp_v8 * temp_v8 + 3.0f * ctrl[2].c[1] * fraction * fraction * temp_v8 + ctrl[3].c[1] * fraction * fraction * fraction;
        cur.c[2] = ctrl[0].c[2] * temp_v8 * temp_v8 * temp_v8 + 3.0f * ctrl[1].c[2] * fraction * temp_v8 * temp_v8 + 3.0f * ctrl[2].c[2] * fraction * fraction * temp_v8 + ctrl[3].c[2] * fraction * fraction * fraction;
        if (temp_v1 == 0) {
          first = cur;
        }
        v188.c[0] = *pfVar16 - cur.c[0];
        v188.c[1] = pfVar16[1] - cur.c[1];
        v188.c[2] = pfVar16[2] - cur.c[2];
        RwV3dNormalize(&v188.c[0],&v188.c[0]);
        v158.c[0] = prev.c[0] - cur.c[0];
        v158.c[1] = prev.c[1] - cur.c[1];
        v158.c[2] = prev.c[2] - cur.c[2];
        RwV3dNormalize(&v158.c[0],&v158.c[0]);
        v148.c[0] = v188.c[1] * v158.c[2] - v188.c[2] * v158.c[1];
        v148.c[1] = v188.c[2] * v158.c[0] - v188.c[0] * v158.c[2];
        v148.c[2] = v188.c[0] * v158.c[1] - v188.c[1] * v158.c[0];
        RwV3dNormalize(&v148.c[0],&v148.c[0]);
        temp_v8 = v188.c[1] * v158.c[1] + v188.c[0] * v158.c[0] + v188.c[2] * v158.c[2];
        if (temp_v8 < 0.0f) {
          temp_v8 = temp_v8 * -1.0f;
        }
        temp_v8 = temp_v8 * (temp_v8 * temp_v8);
        temp_v8 = temp_v9 * (1.0f - temp_v8);
        v148.c[0] = v148.c[0] * temp_v8;
        v148.c[1] = v148.c[1] * temp_v8;
        v148.c[2] = v148.c[2] * temp_v8;
        pfVar3[0] = cur.c[0] + v148.c[0];
        pfVar3[1] = cur.c[1] + v148.c[1];
        pfVar3[2] = cur.c[2] + v148.c[2];
        pfVar3[3] = cur.c[0] - v148.c[0];
        pfVar3[4] = cur.c[1] - v148.c[1];
        pfVar3[5] = cur.c[2] - v148.c[2];
        pfVar3 += 9;
        prev = cur;
        temp_v7 = temp_v7 + temp_v11;
        temp_v1++;
      }
      temp_v4 = *(s32 *)((*(u8 **)work) + 0xc) * 3 + 6;
      pfVar3 = pfVar17 + (temp_v4 - 3) * 3;
      temp_v1 = *(s32 *)((work) + 0xc) - *(s32 *)((work) + 8);
      if (temp_v1 < 0) {
        temp_v1 = temp_v1 + *(s32 *)((work) + 8);
      }
      pfVar5 = (f32 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x10, work)) + temp_v1 * 0xc);
      cur = *(EffAfterVec *)pfVar5;
      v188.c[0] = *pfVar16 - cur.c[0];
      v188.c[1] = pfVar16[1] - cur.c[1];
      v188.c[2] = pfVar16[2] - cur.c[2];
      RwV3dNormalize(&v188.c[0],&v188.c[0]);
      v158.c[0] = prev.c[0] - cur.c[0];
      v158.c[1] = prev.c[1] - cur.c[1];
      v158.c[2] = prev.c[2] - cur.c[2];
      RwV3dNormalize(&v158.c[0],&v158.c[0]);
      v148.c[0] = v188.c[1] * v158.c[2] - v188.c[2] * v158.c[1];
      v148.c[1] = v188.c[2] * v158.c[0] - v188.c[0] * v158.c[2];
      v148.c[2] = v188.c[0] * v158.c[1] - v188.c[1] * v158.c[0];
      RwV3dNormalize(&v148.c[0],&v148.c[0]);
      temp_v7 = v188.c[1] * v158.c[1] + v188.c[0] * v158.c[0] + v188.c[2] * v158.c[2];
      if (temp_v7 < 0.0f) {
        temp_v7 = temp_v7 * -1.0f;
      }
      temp_v7 = temp_v7 * (temp_v7 * temp_v7);
      temp_v7 = temp_v9 * (1.0f - temp_v7);
      v148.c[0] = v148.c[0] * temp_v7;
      v148.c[1] = v148.c[1] * temp_v7;
      v148.c[2] = v148.c[2] * temp_v7;
      *pfVar3 = cur.c[0] + v148.c[0];
      pfVar3[1] = cur.c[1] + v148.c[1];
      pfVar3[2] = cur.c[2] + v148.c[2];
      pfVar3[3] = cur.c[0] - v148.c[0];
      pfVar3[4] = cur.c[1] - v148.c[1];
      pfVar3[5] = cur.c[2] - v148.c[2];
      pfVar17[temp_v4 * 3 - 3] = pfVar17[temp_v4 * 3 - 9] + pfVar17[temp_v4 * 3 - 6];
      pfVar17[temp_v4 * 3 - 2] = pfVar17[temp_v4 * 3 - 8] + pfVar17[temp_v4 * 3 - 5];
      pfVar17[temp_v4 * 3 - 1] = pfVar17[temp_v4 * 3 - 7] + pfVar17[temp_v4 * 3 - 4];
      pfVar17[temp_v4 * 3 - 3] = pfVar17[temp_v4 * 3 - 3] * 0.5f;
      pfVar17[temp_v4 * 3 - 2] = pfVar17[temp_v4 * 3 - 2] * 0.5f;
      pfVar17[temp_v4 * 3 - 1] = pfVar17[temp_v4 * 3 - 1] * 0.5f;
      temp_v1 = *(s32 *)((work) + 0xc) - 1;
      if (temp_v1 < 0) {
        temp_v1 = temp_v1 + *(s32 *)((work) + 8);
      }
      pfVar3 = (f32 *)(((u8 *)*(u8 **)effAfterOffsetPtr(0x10, work)) + temp_v1 * 0xc);
      last = *(EffAfterVec *)pfVar3;
      v188.c[0] = *pfVar16 - last.c[0];
      v188.c[1] = pfVar16[1] - last.c[1];
      v188.c[2] = pfVar16[2] - last.c[2];
      RwV3dNormalize(&v188.c[0],&v188.c[0]);
      v158.c[0] = last.c[0] - first.c[0];
      v158.c[1] = last.c[1] - first.c[1];
      v158.c[2] = last.c[2] - first.c[2];
      RwV3dNormalize(&v158.c[0],&v158.c[0]);
      v148.c[0] = v188.c[1] * v158.c[2] - v188.c[2] * v158.c[1];
      v148.c[1] = v188.c[2] * v158.c[0] - v188.c[0] * v158.c[2];
      v148.c[2] = v188.c[0] * v158.c[1] - v188.c[1] * v158.c[0];
      RwV3dNormalize(&v148.c[0],&v148.c[0]);
      temp_v7 = v188.c[1] * v158.c[1] + v188.c[0] * v158.c[0] + v188.c[2] * v158.c[2];
      if (temp_v7 < 0.0f) {
        temp_v7 = temp_v7 * -1.0f;
      }
      temp_v7 = temp_v7 * (temp_v7 * temp_v7);
      temp_v9 = temp_v9 * (1.0f - temp_v7);
      v148.c[0] = v148.c[0] * temp_v9;
      v148.c[1] = v148.c[1] * temp_v9;
      v148.c[2] = v148.c[2] * temp_v9;
      *pfVar17 = last.c[0] + v148.c[0];
      pfVar17[1] = last.c[1] + v148.c[1];
      pfVar17[2] = last.c[2] + v148.c[2];
      pfVar17[3] = last.c[0] - v148.c[0];
      pfVar17[4] = last.c[1] - v148.c[1];
      pfVar17[5] = last.c[2] - v148.c[2];
      pfVar17[6] = *pfVar17 + pfVar17[3];
      pfVar17[7] = pfVar17[1] + pfVar17[4];
      pfVar17[8] = pfVar17[2] + pfVar17[5];
      pfVar17[6] = pfVar17[6] * 0.5f;
      pfVar17[7] = pfVar17[7] * 0.5f;
      pfVar17[8] = pfVar17[8] * 0.5f;
      pfVar17 = pfVar17 + 0xf;
      for (temp_v5 = 0; temp_v5 < *(s32 *)((*(u8 **)work) + 0xc); temp_v5 = temp_v5 + 1) {
        *pfVar17 = pfVar17[-6] + pfVar17[-3];
        pfVar17[1] = pfVar17[-5] + pfVar17[-2];
        pfVar17[2] = pfVar17[-4] + pfVar17[-1];
        *pfVar17 = *pfVar17 + pfVar17[3];
        pfVar17[1] = pfVar17[1] + pfVar17[4];
        pfVar17[2] = pfVar17[2] + pfVar17[5];
        *pfVar17 = *pfVar17 + pfVar17[6];
        pfVar17[1] = pfVar17[1] + pfVar17[7];
        pfVar17[2] = pfVar17[2] + pfVar17[8];
        *pfVar17 = *pfVar17 * 0.25f;
        pfVar17[1] = pfVar17[1] * 0.25f;
        pfVar17[2] = pfVar17[2] * 0.25f;
        pfVar17 = pfVar17 + 9;
      }
    }
    }
  }
  func_003c22f0(*pp);
  *(u16 *)effAfterOffsetPtr(0xc, (u8 *)*pp) = *(u16 *)effAfterOffsetPtr(0xc, (u8 *)*pp) | 1;
  bound.center.c[0] = 0.0f;
  bound.center.c[1] = 0.0f;
  bound.center.c[2] = 0.0f;
  bound.radius = (f32)1000000000;
  *(EffAfterSphere *)(*(u8 **)(*(u8 **)pp + 0x5c) + 4) = bound;
  return;
}


#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b8f40);
#endif

/* Ribbon sample queue shared by the sample writer and the offset builder. */
typedef struct {
    f32 mid[3];
    f32 headMid;
    f32 headNext;
    f32 tailMid;
    f32 tailPrev;
    f32 width[2];
    f32 alpha[2];
} EffAfterParam;

typedef struct {
    EffAfterParam *param;
    s32 unk4;
    s32 capacity;
} EffAfterConfig;

typedef struct EffAfterQueue {
    EffAfterConfig *config;
    u32 reserved;
    s32 count;
    s32 writeIndex;
    EffAfterVec *positions;
    EffAfterVec *normals;
    EffAfterVec *positionOffsets[2];
    EffAfterVec *normalOffsets[2];
} EffAfterQueue;

// FUN_004BAD70
void func_004bad70(u8 *data, EffAfterVec *position, EffAfterVec *normal) {
    EffAfterQueue *queue;
    s32 index;

    queue = (EffAfterQueue *)data;
    index = queue->writeIndex;
    queue->positions[index] = *position;
    queue->normals[index] = *normal;
    if (queue->count < queue->config->capacity) {
        queue->count++;
    }
    queue->writeIndex++;
    queue->writeIndex %= queue->config->capacity;
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
/* Builds the scaled offset vectors for one ribbon section and the section
 * after it, for both the position and the normal strip. Each vector blends
 * the sample's own direction with the directions to the neighbouring samples
 * in the ring buffer, then is normalised and scaled by the section width. */
// FUN_004BB1D0
void func_004bb1d0(EffAfterQueue *queue, s32 section)
{
    EffAfterVec acc;
    EffAfterVec dir;
    f32 widths[2];
    f32 alphas[2];
    f32 mid0;
    f32 w0;
    f32 w1;
    f32 a1;
    f32 a0;
    f32 prev0;
    f32 next0;
    f32 scale;
    f32 term;
    f32 scale2;
    f32 mid1;
    f32 next1;
    f32 prev1;
    f32 *pw;
    s32 sel;
    s32 following;

    widths[0] = queue->config->param->width[0];
    alphas[0] = queue->config->param->alpha[0];
    widths[1] = queue->config->param->width[1];
    alphas[1] = queue->config->param->alpha[1];
    sel = !(func_004bc1e0((u8 *)queue, section, 0) > func_004bc1e0((u8 *)queue, section, 1));
    if (queue->count == 2) {
        mid0 = queue->config->param->headMid;
        next0 = queue->config->param->headNext;
        prev0 = 0.0f;
    } else if (section == 0) {
        mid0 = queue->config->param->headMid;
        next0 = queue->config->param->headNext;
        prev0 = 0.0f;
    } else {
        mid0 = queue->config->param->mid[0];
        next0 = queue->config->param->mid[2];
        prev0 = queue->config->param->mid[1];
    }

    /* This section, position side. */
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    pw = &widths[sel & 1];
    w0 = *pw;
    scale = w0 * func_004bc1e0((u8 *)queue, section, 0);
    pw = &alphas[sel & 1];
    a0 = *pw;
    term = a0 * func_004bc310((u8 *)queue, section);
    scale = scale + term;
    func_004b7830((u8 *)queue, section, 0, &dir);
    dir.c[0] *= mid0;
    dir.c[1] *= mid0;
    dir.c[2] *= mid0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (section == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - section;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = queue->writeIndex - section;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->positions[ib].c[0] - queue->positions[ia].c[0];
        dir.c[1] = queue->positions[ib].c[1] - queue->positions[ia].c[1];
        dir.c[2] = queue->positions[ib].c[2] - queue->positions[ia].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= prev0;
    dir.c[1] *= prev0;
    dir.c[2] *= prev0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (section == queue->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - section;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = -2 - section + queue->writeIndex;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->positions[ia].c[0] - queue->positions[ib].c[0];
        dir.c[1] = queue->positions[ia].c[1] - queue->positions[ib].c[1];
        dir.c[2] = queue->positions[ia].c[2] - queue->positions[ib].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= next0;
    dir.c[1] *= next0;
    dir.c[2] *= next0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    RwV3dNormalize(acc.c, acc.c);
    acc.c[0] *= scale;
    acc.c[1] *= scale;
    acc.c[2] *= scale;
    {
        s32 ia = queue->writeIndex - 1 - section;

        if (ia < 0) {
            ia += queue->count;
        }
        queue->positionOffsets[0][ia] = acc;
    }

    /* This section, normal side. */
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    pw = &widths[(sel + 1) & 1];
    w1 = *pw;
    scale = w1 * func_004bc1e0((u8 *)queue, section, 1);
    pw = &alphas[(sel + 1) & 1];
    a1 = *pw;
    term = a1 * func_004bc310((u8 *)queue, section);
    scale = scale + term;
    func_004b7830((u8 *)queue, section, 1, &dir);
    dir.c[0] *= mid0;
    dir.c[1] *= mid0;
    dir.c[2] *= mid0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (section == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - section;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = queue->writeIndex - section;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->normals[ib].c[0] - queue->normals[ia].c[0];
        dir.c[1] = queue->normals[ib].c[1] - queue->normals[ia].c[1];
        dir.c[2] = queue->normals[ib].c[2] - queue->normals[ia].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= prev0;
    dir.c[1] *= prev0;
    dir.c[2] *= prev0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (section == queue->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - section;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = -2 - section + queue->writeIndex;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->normals[ia].c[0] - queue->normals[ib].c[0];
        dir.c[1] = queue->normals[ia].c[1] - queue->normals[ib].c[1];
        dir.c[2] = queue->normals[ia].c[2] - queue->normals[ib].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= next0;
    dir.c[1] *= next0;
    dir.c[2] *= next0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    RwV3dNormalize(acc.c, acc.c);
    acc.c[0] *= scale;
    acc.c[1] *= scale;
    acc.c[2] *= scale;
    {
        s32 ia = queue->writeIndex - 1 - section;

        if (ia < 0) {
            ia += queue->count;
        }
        queue->normalOffsets[0][ia] = acc;
    }

    if (queue->count == 2 || (queue->count == 3 && section == 1)) {
        mid1 = queue->config->param->tailMid;
        next1 = 0.0f;
        prev1 = queue->config->param->tailPrev;
    } else {
        mid1 = queue->config->param->mid[0];
        next1 = queue->config->param->mid[2];
        prev1 = queue->config->param->mid[1];
    }

    /* Following section, position side. */
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    following = section + 1;
    w0 *= func_004bc1e0((u8 *)queue, section, 0);
    term = a0 * func_004bc310((u8 *)queue, section);
    scale2 = w0 + term;
    func_004b7830((u8 *)queue, following, 0, &dir);
    dir.c[0] *= mid1;
    dir.c[1] *= mid1;
    dir.c[2] *= mid1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (following == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - following;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = queue->writeIndex - following;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->positions[ib].c[0] - queue->positions[ia].c[0];
        dir.c[1] = queue->positions[ib].c[1] - queue->positions[ia].c[1];
        dir.c[2] = queue->positions[ib].c[2] - queue->positions[ia].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= prev1;
    dir.c[1] *= prev1;
    dir.c[2] *= prev1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (following == queue->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - following;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = -2 - following + queue->writeIndex;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->positions[ia].c[0] - queue->positions[ib].c[0];
        dir.c[1] = queue->positions[ia].c[1] - queue->positions[ib].c[1];
        dir.c[2] = queue->positions[ia].c[2] - queue->positions[ib].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= next1;
    dir.c[1] *= next1;
    dir.c[2] *= next1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    RwV3dNormalize(acc.c, acc.c);
    acc.c[0] *= scale2;
    acc.c[1] *= scale2;
    acc.c[2] *= scale2;
    {
        s32 ia = queue->writeIndex - 1 - section;

        if (ia < 0) {
            ia += queue->count;
        }
        queue->positionOffsets[1][ia] = acc;
    }

    /* Following section, normal side. */
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    following = section + 1;
    scale2 = w1 * func_004bc1e0((u8 *)queue, section, 1);
    term = a1 * func_004bc310((u8 *)queue, section);
    scale2 = scale2 + term;
    func_004b7830((u8 *)queue, following, 1, &dir);
    dir.c[0] *= mid1;
    dir.c[1] *= mid1;
    dir.c[2] *= mid1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (following == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - following;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = queue->writeIndex - following;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->normals[ib].c[0] - queue->normals[ia].c[0];
        dir.c[1] = queue->normals[ib].c[1] - queue->normals[ia].c[1];
        dir.c[2] = queue->normals[ib].c[2] - queue->normals[ia].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= prev1;
    dir.c[1] *= prev1;
    dir.c[2] *= prev1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (following == queue->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 ia;
        s32 ib;

        ia = queue->writeIndex - 1 - following;
        if (ia < 0) {
            ia += queue->count;
        }
        ib = -2 - following + queue->writeIndex;
        if (ib < 0) {
            ib += queue->count;
        }
        dir.c[0] = queue->normals[ia].c[0] - queue->normals[ib].c[0];
        dir.c[1] = queue->normals[ia].c[1] - queue->normals[ib].c[1];
        dir.c[2] = queue->normals[ia].c[2] - queue->normals[ib].c[2];
        RwV3dNormalize(dir.c, dir.c);
    }
    dir.c[0] *= next1;
    dir.c[1] *= next1;
    dir.c[2] *= next1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    RwV3dNormalize(acc.c, acc.c);
    acc.c[0] *= scale2;
    acc.c[1] *= scale2;
    acc.c[2] *= scale2;
    {
        s32 ia = queue->writeIndex - 1 - section;

        if (ia < 0) {
            ia += queue->count;
        }
        queue->normalOffsets[1][ia] = acc;
    }
}

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
   floor.
   Committed at nd 70. */
// Archived C body: build/WBHygiene_func_004bc1e0_archive.txt; no current park body remains.
/* measured: optimization_level 1 probe for eff_after target. */
#pragma optimization_level 1
// FUN_004BC1E0
f32 func_004bc1e0(u8 *arg0, s32 arg1, s32 arg2)
{
    f32 v[3];
    s32 i;
    s32 offset;
    f32 *p;
    f32 a;
    f32 b;
    f32 c;
    f32 t;

    if (arg1 == *(s32 *)(arg0 + 8) - 1) {
        func_0046d730(D_007146E0, 0x6F8);
    }
    i = -2 - arg1 + *(s32 *)(arg0 + 0xC);
    if (i < 0) {
        i += *(s32 *)(arg0 + 8);
    }
    p = (f32 *)(*(u8 **)(effAfterOffsetPtr(arg2 * 4, arg0) + 0x10) + i * 0xC);
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
    offset = i * 0xC;
    p = (f32 *)(*(u8 **)(effAfterOffsetPtr(arg2 * 4, arg0) + 0x10) + offset);
    t = p[0];
    v[0] -= t;
    t = p[1];
    v[1] -= t;
    t = p[2];
    v[2] -= t;
    return RwV3dLength(v);
}
#pragma optimization_level 2

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
    RwV3dNormalize(&v1.c[0], &v1.c[0]);
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
    RwV3dNormalize(&v2.c[0], &v2.c[0]);
    d = v1.c[0] * v2.c[0] + v1.c[1] * v2.c[1] + v1.c[2] * v2.c[2];
    return (1.0f - d) / 2.0f;
}

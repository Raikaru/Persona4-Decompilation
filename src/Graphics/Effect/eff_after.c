#include "include_asm.h"
/* Original translation unit eff_after.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "effect_mesh_internal.h"
#include "rw_object_internal.h"

#include "effect_after_internal.h"

static inline u8 *effAfterWorkFieldPtr(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_007146E0[];
typedef struct RuntimeCommandWork
{
    u32 flags;
    u16* cursor;
    u16* start;
    u32 unkC;
    EffAfterQueue* target;
    u32 elapsed;
    u16 delay;
    u16 reserved1a;
    u32 duration;
} RuntimeCommandWork;
extern void effMiscProgressStart(u8 *work, f32 duration);
extern void effMiscProgressReset(void* work);

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void kAssertFail(u8 *file, s32 line);
extern f32 RwV3dLength(void *a0);
extern void RwV3dNormalize(f32 *a, f32 *b);
extern f32 Vpad_GetSegmentLength(void *work, s32 section);
extern s32 effAfterHistoryIndex(const EffAfterQueue *work, s32 index);
extern f32 effAfterSectionTurnFactor(u8 *work, s32 section);
extern f32 effAfterSideSegmentLength(u8 *work, s32 section, s32 side);
extern void effAfterQueueSectionOffsets(struct EffAfterQueue *queue, s32 section);
extern void effAfterFrameNormal(u8 *work, s32 section, EffAfterVec *output);
extern void effAfterSideAxis(u8 *work, s32 section, s32 side, EffAfterVec *output);
struct RpGeometry;
struct RpTriangle { u16 vertIndex[3]; u16 matIndex; };
struct RpMaterial;
extern const struct RpGeometry *func_003c2130(const struct RpGeometry *, struct RpTriangle *, u16, u16, u16);
extern struct RpGeometry *func_003c2150(struct RpGeometry *, struct RpTriangle *, struct RpMaterial *);
extern struct RpGeometry *func_003c2630(s32 nVtx, s32 nIdx, u32 flags);
extern void effMiscProgressBlendColor(u8 *work, s32 side, f32 t, u8 *out);

/* Finds the section containing `distance` along the path and the fraction of that section it reaches. */
// FUN_004B7460
void effAfterSectionFraction(u8 *data, f32 distance, u32 *section, f32 *fraction) {
    /* Earlier whole-layout comparison: 697 differing bytes; remaining raw sites are isolated below. */
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
    for (totalIndex = 0; totalIndex < ((EffAfterQueue *)data)->count - 1; totalIndex++) {
        total += Vpad_GetSegmentLength(data, totalIndex);
    }
    if (total <= 0.0f) {
        *section = 0;
        *fraction = 0.0f;
        return;
    }
    currentSection = 0;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    while (currentSection < *(s32 *)(data + 8) - 1) {
        cumulative = 0.0f;
        for (leadingIndex = 0; leadingIndex < currentSection + 1; leadingIndex++) {
            firstIndex = effAfterHistoryIndex((const EffAfterQueue *)data, leadingIndex);
            nextIndex = effAfterHistoryIndex((const EffAfterQueue *)data, leadingIndex + 1);
            sectionLength = 0.0f;
            vectorBase = (u8 *)(s32)((EffAfterQueue *)data)->positions;
            firstOffset = firstIndex * 0xC;
            nextOffset = nextIndex * 0xC;
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            leadingDelta.c[0] = nextX - firstSample->c[0];
            leadingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            leadingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += RwV3dLength(&leadingDelta.c[0]);
            vectorBase = (u8 *)(s32)((EffAfterQueue *)data)->normals;
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            leadingDelta.c[0] = nextX - firstSample->c[0];
            leadingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            leadingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += RwV3dLength(&leadingDelta.c[0]);
            scaledLength = 0.0f;
            scaledLength += sectionLength * ((EffAfterQueue *)data)->config->param->lengthScale;
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
            firstIndex = effAfterHistoryIndex((const EffAfterQueue *)data, trailingIndex);
            nextIndex = effAfterHistoryIndex((const EffAfterQueue *)data, trailingIndex + 1);
            sectionLength = 0.0f;
            vectorBase = (u8 *)(s32)((EffAfterQueue *)data)->positions;
            firstOffset = firstIndex * 0xC;
            nextOffset = nextIndex * 0xC;
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            trailingDelta.c[0] = nextX - firstSample->c[0];
            trailingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            trailingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += RwV3dLength(&trailingDelta.c[0]);
            vectorBase = (u8 *)(s32)((EffAfterQueue *)data)->normals;
            nextSample = (EffAfterVec *)(vectorBase + nextOffset);
            nextX = nextSample->c[0];
            firstSample = (EffAfterVec *)(vectorBase + firstOffset);
            trailingDelta.c[0] = nextX - firstSample->c[0];
            trailingDelta.c[1] = nextSample->c[1] - firstSample->c[1];
            trailingDelta.c[2] = nextSample->c[2] - firstSample->c[2];
            sectionLength += RwV3dLength(&trailingDelta.c[0]);
            scaledLength = 0.0f;
            scaledLength += sectionLength * ((EffAfterQueue *)data)->config->param->lengthScale;
            previous += scaledLength / total;
        }
    }
    *section = currentSection;
    sectionLength = cumulative - previous;
    if (sectionLength <= 0.0f) {
        kAssertFail(D_007146E0, 0x7E);
    }
    *fraction = (targetDistance - previous) / sectionLength;
}
// Returns the ring index that is index steps behind the newest sample, wrapping by the current sample count.
// FUN_004B7800
s32 effAfterHistoryIndex(const EffAfterQueue* work, s32 index)
{
    s32 result;

    result = (s32)work->writeIndex - 1 - index;
    if (result < 0)
    {
        result += (s32)work->count;
    }
    return result;
}
// Side axis of one section: normalised cross products of the side and forward edges, projected onto the section frame normal.
// FUN_004B7830
void effAfterSideAxis(u8 *work, s32 section, s32 side, EffAfterVec *output) {
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
        kAssertFail(D_007146E0, 0xAA);
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
        effAfterFrameNormal(work, section, (EffAfterVec *)&frameNormal.c[0]);
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
        effAfterFrameNormal(work, section, (EffAfterVec *)&frameNormal.c[0]);
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

// Frame normal of one section, derived from its edge vectors in both rings.
// FUN_004B7DC0
void effAfterFrameNormal(u8 *work, s32 section, EffAfterVec *output) {
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
        kAssertFail(D_007146E0, 0xF7);
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
#include "rw_types_internal.h"
typedef RwV3d AfterVector3;

// Builds the ribbon geometry object for one material: vertex and index counts follow the config mode, and the bounding sphere is stored on the morph target.
// FUN_004B8350
#pragma push
#pragma opt_loop_invariants on
u8 *effAfterCreateRibbon(u8 *work, struct RpMaterial *material)
{
    /* Earlier whole-layout comparison: 2017 differing bytes; remaining raw sites are isolated below. */
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
    /* measured: typing the config-pointer load alone changes owner instructions (singleton MISMATCH). */
    if ((((EffAfterMaterial *)((EffAfterConfig *)*(s32 *)work)->material)->flags & 1) != 0) {
        flags |= 4;
    }
    nIdx = 0;
    nVtx = 0;
    switch (((EffAfterQueue *)work)->mode) {
    case 0:
        n = ((EffAfterQueue *)work)->config->sectionCount;
        nIdx = (n - 1) * 2 + 1;
        nVtx = n * 2 + 1;
        break;
    case 1:
        n = ((EffAfterQueue *)work)->config->sectionCount;
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    case 2:
        n = ((EffAfterQueue *)work)->config->sectionCount;
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    }
    obj = (u8 *)func_003c2630(nVtx, nIdx, flags);
    idx = (struct RpTriangle *)((RpGeometry *)obj)->triangles;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    switch (*(s16 *)(work + 0x38)) {
    case 0:
        for (i = 0; i < ((EffAfterQueue *)work)->config->sectionCount - 1; i++) {
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
            for (stripIndex = 0; stripIndex < ((EffAfterQueue *)work)->config->sectionCount; stripIndex++) {
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
            for (stripIndex = 0; stripIndex < ((EffAfterQueue *)work)->config->sectionCount; stripIndex++) {
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
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        materialTriangle = *(struct RpTriangle **)(obj + 0x2C);
        for (attributeIndex = 0; attributeIndex < nIdx;) {
            func_003c2150((struct RpGeometry *)obj, (struct RpTriangle *)materialTriangle, material);
            attributeIndex++;
            materialTriangle++;
        }
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        switch (*(s16 *)(work + 0x38)) {
        case 0:
            col = (u8 *)((RpGeometry *)obj)->colors;
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            for (attributeIndex = 0; attributeIndex < *(s32 *)(*(u8 **)work + 0xC);) {
                if (attributeIndex == 0) {
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    t = (f32)attributeIndex / (f32)(*(s32 *)(*(u8 **)work + 0xC) - 1);
                } else {
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    t = ((f32)attributeIndex - 0.5f) / (f32)(*(s32 *)(*(u8 **)work + 0xC) - 1);
                }
                effMiscProgressBlendColor(work, 0, t, col);
                attributeIndex++;
                col += 8;
            }
            effMiscProgressBlendColor(work, 0, 1.0f, col);
            {
                s32 rightIndex;
                u8 *rightColor;
                /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                rightColor = *(u8 **)(obj + 0x30) + 4;
                for (rightIndex = 0; rightIndex < ((EffAfterQueue *)work)->config->sectionCount;) {
                    t = (f32)rightIndex / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
                    effMiscProgressBlendColor(work, 1, t, rightColor);
                    rightIndex++;
                    rightColor += 8;
                }
            }
            break;
        case 1:
            {
                s32 k;
                u8 *c;

                c = (u8 *)((RpGeometry *)obj)->colors;
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

                c = (u8 *)((RpGeometry *)obj)->colors;
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
        cfg = (u8 *)((EffAfterQueue *)work)->config;
        if ((((EffAfterMaterial *)((EffAfterConfig *)cfg)->material)->flags & 1) != 0) {
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            switch (*(s16 *)(work + 0x38)) {
            case 0:
                uv = (AfterTexCoord *)((RpGeometry *)obj)->texCoords[0];
                for (attributeIndex = 0; attributeIndex < ((EffAfterQueue *)work)->config->sectionCount;) {
                    if (((EffAfterQueue *)work)->config->sectionCount - 1 <= 0) {
                        kAssertFail(D_007146E0, 0x226);
                    }
                    if (attributeIndex == 0) {
                        uv[0].u = (f32)attributeIndex / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
                    } else {
                        uv[0].u = ((f32)attributeIndex - 0.5f) / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
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
                    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
                    rightUV = *(AfterTexCoord **)(obj + 0x34) + 1;
                    for (rightIndex = 0; rightIndex < ((EffAfterQueue *)work)->config->sectionCount;) {
                        if (((EffAfterQueue *)work)->config->sectionCount - 1 <= 0) {
                            kAssertFail(D_007146E0, 0x234);
                        }
                        rightUV[0].u = (f32)rightIndex / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
                        rightUV[0].v = 1.0f;
                        rightIndex++;
                        rightUV += 2;
                    }
                }
                break;
            case 1:
                uv = (AfterTexCoord *)((RpGeometry *)obj)->texCoords[0];
                n = ((EffAfterConfig *)cfg)->sectionCount;
                last = n * 3 + 6;
                denom = 0.5f + (f32)n;
                uv[0].u = 0.0f;
                uv[0].v = 0.0f;
                uv[1].u = 0.0f;
                uv[1].v = 1.0f;
                uv[2].u = 0.0f;
                uv[2].v = 0.5f;
                p = (AfterTexCoord *)effAfterWorkFieldPtr(last * sizeof(AfterTexCoord), (u8 *)uv);
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
                    while (k < ((EffAfterQueue *)work)->config->sectionCount) {
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
                        while (centerIndex < ((EffAfterQueue *)work)->config->sectionCount) {
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
                uv = (AfterTexCoord *)((RpGeometry *)obj)->texCoords[0];
                n = ((EffAfterConfig *)cfg)->sectionCount;
                last = n * 3 + 6;
                denom = 0.5f + (f32)n;
                uv[0].u = 0.0f;
                uv[0].v = 0.0f;
                uv[1].u = 0.0f;
                uv[1].v = 1.0f;
                uv[2].u = 0.0f;
                uv[2].v = 0.5f;
                p = (AfterTexCoord *)effAfterWorkFieldPtr(last * sizeof(AfterTexCoord), (u8 *)uv);
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
                    while (k < ((EffAfterQueue *)work)->config->sectionCount) {
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
                        while (centerIndex < ((EffAfterQueue *)work)->config->sectionCount) {
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
    *(AfterSphere *)&((RpGeometry *)obj)->morphTarget->boundingSphere = sphere;
    return obj;
}
#pragma pop
/* Allocates six capacity-sized vector arrays in one block and initializes the section's sample ring. */
// FUN_004B8DF0
void effAfterAllocVectorBuffers(u8 *work, u8 *config) {
    /* Earlier whole-layout comparison: 215 differing bytes; remaining raw sites are isolated below. */
    u8 *p;
    u8 *q;
    s32 size;

    size = 0;
    size += (((EffAfterConfig *)config)->capacity * 3 << 3);
    size += (((EffAfterConfig *)config)->capacity * 3 << 4);
    chkmemAllocSiteTag(D_007146E0, 0x2A5);
    p = (u8 *)(*jtbl_008873E8)(size, 0x40000);
    ((EffAfterQueue *)work)->positions = (EffAfterVec *)(p);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    q = p + *(s32 *)(config + 8) * 0xC;
    ((EffAfterQueue *)work)->normals = (EffAfterVec *)(q);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    q = q + *(s32 *)(config + 8) * 0xC;
    ((EffAfterQueue *)work)->positionOffsets[0] = (EffAfterVec *)(q);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    q = q + *(s32 *)(config + 8) * 0xC;
    ((EffAfterQueue *)work)->positionOffsets[1] = (EffAfterVec *)(q);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    q = q + *(s32 *)(config + 8) * 0xC;
    ((EffAfterQueue *)work)->normalOffsets[0] = (EffAfterVec *)(q);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    ((EffAfterQueue *)work)->normalOffsets[1] = (EffAfterVec *)(q + *(s32 *)(config + 8) * 0xC);
    ((EffAfterQueue *)work)->flags = 0;
    ((EffAfterQueue *)work)->config = (EffAfterConfig *)(config);
    ((EffAfterQueue *)work)->count = 0;
    ((EffAfterQueue *)work)->writeIndex = 0;
    ((EffAfterQueue *)work)->mode = ((EffAfterConfig *)config)->mode;
}

/* Frees the vector buffer at work+0x10. */
// FUN_004B8F10
void effAfterFreeVectorBuffers(void *work) {
    jtbl_008873EC[0]((void *)((EffAfterQueue *)work)->positions);
}

/* measured: 7728B mesh-builder. Retail asm has 63 mula/madda/madd/msub FPU
   sequences (the same multiply-accumulate family as effAfterFrameNormal/effAfterSideAxis,
   which floor on the v5 index register and fp-save set) plus 21 lq/sq quadword
   ops and 3 large switch statements. Error-marked in the m2c draft at every FPU
   sequence; the mula/madda/madd dot-product folds cannot be reproduced in plain
   C by b210. FPU-accumulate + quadword-slot floor. */
/* Cold 004b8f40 (1932 instrs, frame -0x1A0 s19-s23/s30): no probe_archive */
/* entry; m2c (u8*,void**) + romwright (u8*,int*) agree on signature (pointer */
/* + pointer-to-pointer), m2c has 63 error-marked (mula/madd/msub) vs rw 0 errors */
/* with counted fors (correct, not do/while). Stripped rw skeleton (fn refs->D_, */
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
/* Trail mesh rebuild. Retail adds some table offsets index-first: those sites
   go through effAfterWorkFieldPtr (offset + base), the rest stay base-first u8 *
   arithmetic. The midpoint row is formed inside its first copy after the
   source offset, matching retail's evaluation order. */
#pragma push
#pragma opt_dead_assignments off
#pragma opt_lifetimes on
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_pulloutconstants off
typedef struct {
    EffAfterVec center;
    f32 radius;
} EffAfterSphere;

// Rebuilds the trail mesh from the two vector rings for the current work; the notes above record the measured floor.
// FUN_004B8F40
void effAfterRebuildTrailMesh(u8 *work, void **pp)

{
    /* Earlier whole-layout comparison: 2093 differing bytes; remaining raw sites are isolated below. */
/* irregular: 5 native warning(s); review required */
  s16 mode;
  u8 *byteCursor;
  f32 *cameraPosition;
  u64 *wideCursor;
  f32 *controlEnd;
  f32 *controlStart;
  s32 index;
  s32 firstOffset;
  s32 secondIndex;
  u32 *colorWords;
  s32 sampleIndex;
  u8 *colorBytes;
  u32 *vertexWords;
  s32 countOrAddress;
  u32 cachedSection;
  f32 *outputVertex;
  f32 *vectorCursor;
  f32 *vertexBase;
  f32 blend;
  f32 weight;
  f32 sampleFraction;
  f32 sampleStep;
  f32 halfWidth;
  s32 savedIndex;
  f32 fraction;
  u32 section;
  EffAfterVec toCamera;
  EffAfterVec cur;
  EffAfterVec prev;
  EffAfterVec tangent;
  EffAfterVec sideOffset;
  EffAfterVec first;
  EffAfterVec last;
  EffAfterSphere bound;
  EffAfterVec ctrl[4];
  
  RpGeometryLock(*pp,0x1a);
  if (((((EffAfterQueue *)work)->flags & 1) != 0) || ((~((EffAfterQueue *)work)->flags & 2) != 0)) {
    switch (((EffAfterQueue *)work)->mode) {
    case 0:
    {
      s32 i;
      u8 *col;

      col = (u8 *)((RpGeometry *)*pp)->colors;
      for (i = 0; i < ((EffAfterQueue *)work)->config->sectionCount;) {
        if (((EffAfterQueue *)work)->config->sectionCount - 1 < 1) {
          kAssertFail(D_007146E0,0x3d1);
        }
        if (i == 0) {
          fraction = (f32)i / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
        }
        else {
          fraction = ((f32)i - 0.5f) / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
        }
        effMiscProgressBlendColor(work,0,fraction,col);
        i++;
        col += 8;
      }
      effMiscProgressBlendColor(work,0,1.0f,col);
      col = (u8 *)((RpGeometry *)*pp)->colors + 4;
      for (i = 0; i < ((EffAfterQueue *)work)->config->sectionCount;) {
        if (((EffAfterQueue *)work)->config->sectionCount - 1 < 1) {
          kAssertFail(D_007146E0,0x3dc);
        }
        fraction = (f32)i / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1);
        effMiscProgressBlendColor(work,1,fraction,col);
        i++;
        col += 8;
      }
    }
    break;
    case 1:
    {
      colorBytes = (u8 *)((RpGeometry *)*pp)->colors;
      effMiscProgressBlendColor(work,0,0.0f,colorBytes);
      effMiscProgressBlendColor(work,1,0.0f,colorBytes + 4);
      colorBytes[8] = (u8)((s32)((u32)colorBytes[0] + (u32)colorBytes[4]) >> 1);
      colorBytes[9] = (u8)((s32)((u32)colorBytes[1] + (u32)colorBytes[5]) >> 1);
      colorBytes[10] = (u8)((s32)((u32)colorBytes[2] + (u32)colorBytes[6]) >> 1);
      colorBytes[0xb] = (u8)((s32)((u32)colorBytes[3] + (u32)colorBytes[7]) >> 1);
      index = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      effMiscProgressBlendColor(work,0,1.0f,colorBytes + (index - 3) * 4);
      effMiscProgressBlendColor(work,1,1.0f,colorBytes + (index - 2) * 4);
      byteCursor = effAfterWorkFieldPtr(index * 4, colorBytes);
      byteCursor[-4] = (u8)((s32)((u32)byteCursor[-0xc] + (u32)byteCursor[-8]) >> 1);
      byteCursor[-3] = (u8)((s32)((u32)byteCursor[-0xb] + (u32)byteCursor[-7]) >> 1);
      byteCursor[-2] = (u8)((s32)((u32)byteCursor[-10] + (u32)byteCursor[-6]) >> 1);
      byteCursor[-1] = (u8)((s32)((u32)byteCursor[-9] + (u32)byteCursor[-5]) >> 1);
      blend = 0.5f + (f32)((EffAfterQueue *)work)->config->sectionCount;
      sampleStep = 1.0f / blend;
      colorWords = (u32 *)(colorBytes + 0xc);
      sampleFraction = 0.5f / blend;
      for (countOrAddress = 0; countOrAddress < ((EffAfterQueue *)work)->config->sectionCount;) {
        effMiscProgressBlendColor(work,0,sampleFraction,(u8 *)colorWords++);
        effMiscProgressBlendColor(work,1,sampleFraction,(u8 *)colorWords++);
        colorWords++;
        countOrAddress++;
        sampleFraction += sampleStep;
      }
      {
        s32 j;
        u8 *c;

        c = colorBytes + 0x14;
        for (j = 0; j < ((EffAfterQueue *)work)->config->sectionCount;) {
          c[0] = (u8)((s32)((u32)c[8] + ((u32)c[4] + ((u32)c[-8] + (u32)c[-4]))) >> 2);
          c[1] = (u8)((s32)((u32)c[9] + ((u32)c[5] + ((u32)c[-7] + (u32)c[-3]))) >> 2);
          c[2] = (u8)((s32)((u32)c[10] + ((u32)c[6] + ((u32)c[-6] + (u32)c[-2]))) >> 2);
          c[3] = (u8)((s32)((u32)c[0xb] + ((u32)c[7] + ((u32)c[-5] + (u32)c[-1]))) >> 2);
          j++;
          c += 0xc;
        }
      }
      }
    break;

    case 2:
    {
      s32 i;
      s32 k;
      u8 *col;
      u32 *cur;
      s32 lim;
      f32 den;
      f32 step;
      f32 t;

      col = (u8 *)((RpGeometry *)*pp)->colors;
      effMiscProgressBlendColor(work,1,0.0f,col);
      effMiscProgressBlendColor(work,1,0.0f,col + 4);
      lim = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      effMiscProgressBlendColor(work,1,1.0f,col + (lim - 3) * 4);
      effMiscProgressBlendColor(work,1,1.0f,col + (lim - 2) * 4);
      den = 0.5f + (f32)((EffAfterQueue *)work)->config->sectionCount;
      step = 1.0f / den;
      cur = (u32 *)(col + 0xc);
      t = 0.5f / den;
      for (i = 0; i < ((EffAfterQueue *)work)->config->sectionCount;) {
        effMiscProgressBlendColor(work,1,t,(u8 *)cur++);
        effMiscProgressBlendColor(work,1,t,(u8 *)cur++);
        cur++;
        i++;
        t += step;
      }
      effMiscProgressBlendColor(work,0,0.0f,col + 8);
      effMiscProgressBlendColor(work,0,1.0f,col + (lim - 1) * 4);
      step = 1.0f / (f32)den;
      t = step;
      col += 0x14;
      for (k = 0; k < ((EffAfterQueue *)work)->config->sectionCount;) {
        effMiscProgressBlendColor(work,0,t,col);
        k++;
        t += step;
        col += 0xc;
      }
    }
    }
    *(u32 *)effAfterWorkFieldPtr(4, work) = *(u32 *)effAfterWorkFieldPtr(4, work) | 2;
  }
  /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
  if (*(s32 *)(work + 8) < 2) {
    switch (((EffAfterQueue *)work)->mode) {
    case 0:
    {
      vertexWords = (u32 *)((RpGeometry *)*pp)->morphTarget->vertices;
      colorWords = vertexWords + ((RpGeometry *)*pp)->vertexCount * 3;
      for (countOrAddress = 0; countOrAddress < ((EffAfterQueue *)work)->config->sectionCount + 1;) {
        if (colorWords == vertexWords) {
          kAssertFail(D_007146E0,0x43c);
        }
        vertexWords[0] = 0;
        vertexWords[1] = 0;
        vertexWords[2] = 0;
        countOrAddress++;
        vertexWords += 6;
      }
      vertexWords = (u32 *)((u8 *)((RpGeometry *)*pp)->morphTarget->vertices + 0xc);
      for (countOrAddress = 0; countOrAddress < ((EffAfterQueue *)work)->config->sectionCount;) {
        if (colorWords == vertexWords) {
          kAssertFail(D_007146E0,0x446);
        }
        vertexWords[0] = 0;
        vertexWords[1] = 0;
        vertexWords[2] = 0;
        countOrAddress++;
        vertexWords += 6;
      }
    }
    break;
    case 1:
    {
      countOrAddress = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      vertexWords = (u32 *)((RpGeometry *)*pp)->morphTarget->vertices;
      for (index = 0; index < countOrAddress;) {
        vertexWords[0] = 0;
        vertexWords[1] = 0;
        vertexWords[2] = 0;
        index++;
        vertexWords += 3;
      }
    }
    break;
    case 2:
    {
      countOrAddress = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      vertexWords = (u32 *)((RpGeometry *)*pp)->morphTarget->vertices;
      for (index = 0; index < countOrAddress;) {
        vertexWords[0] = 0;
        vertexWords[1] = 0;
        vertexWords[2] = 0;
        index++;
        vertexWords += 3;
      }
    }
    }
  }
  else {
    switch (((EffAfterQueue *)work)->mode) {
    case 0:
    {
      f32 *out;
      u32 cache;
      s32 side;
      s32 jj;
      s32 base;
      f32 *lim;
      s32 span;
      s32 ia;
      s32 ib;
      f32 *pa;
      f32 *pb;
      f32 s;

      base = (s32)((RpGeometry *)*pp)->morphTarget->vertices;
      lim = (f32 *)(base + ((RpGeometry *)*pp)->vertexCount * 0xc);
      for (side = 0; side < 2;) {
        out = (f32 *)(base + side * 0xc);
        cache = 0xffffffff;
        switch (side) {
        case 0:
          span = ((EffAfterQueue *)work)->config->sectionCount;
          break;
        case 1:
          span = ((EffAfterQueue *)work)->config->sectionCount - 1;
          break;
        }
        for (jj = 0; jj < span;) {
          if (((EffAfterQueue *)work)->config->sectionCount - 1 < 1) {
            kAssertFail(D_007146E0,0x480);
          }
          if (side == 0) {
            if (jj == 0) {
              effAfterSectionFraction(work,(f32)jj / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1),&section,
                            &fraction);
            }
            else {
              effAfterSectionFraction(work,((f32)jj - 0.5f) /
                                    (f32)(((EffAfterQueue *)work)->config->sectionCount - 1),&section,&fraction
                           );
            }
          }
          else {
            effAfterSectionFraction(work,(f32)jj / (f32)(((EffAfterQueue *)work)->config->sectionCount - 1),
                          &section,&fraction);
          }
          if (section != cache) {
            cache = section;
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            ia = (*(s32 *)((work) + 0xc) - 1) - section;
            if (ia < 0) {
              ia = ia + ((EffAfterQueue *)work)->count;
            }
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            ib = (*(s32 *)((work) + 0xc) - 1) - (section + 1);
            if (ib < 0) {
              ib = ib + ((EffAfterQueue *)work)->count;
            }
            ia = ia * 0xc;
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            pa = (f32 *)(*(u8 **)(((work) + side * 4 + 0x10)) + ia);
            ctrl[0] = *(EffAfterVec *)pa;
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            pb = (f32 *)(*(u8 **)(((work) + side * 8 + 0x18)) + ia);
            ctrl[1].c[0] = *pa - *pb;
            ctrl[1].c[1] = pa[1] - pb[1];
            ctrl[1].c[2] = pa[2] - pb[2];
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            pa = (f32 *)(*(u8 **)(((work) + side * 8 + 0x1c)) + ia);
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            pb = (f32 *)(*(u8 **)(((work) + side * 4 + 0x10)) + ib * 0xc);
            ctrl[2].c[0] = *pb + *pa;
            ctrl[2].c[1] = pb[1] + pa[1];
            ctrl[2].c[2] = pb[2] + pa[2];
            ctrl[3] = *(EffAfterVec *)pb;
          }
          s = 1.0f - fraction;
          if (!(out < lim)) {
            kAssertFail(D_007146E0,0x49d);
          }
          *out = ctrl[0].c[0] * s * s * s + 3.0f * ctrl[1].c[0] * fraction * s * s + 3.0f * ctrl[2].c[0] * fraction * fraction * s + ctrl[3].c[0] * fraction * fraction * fraction;
          out[1] = ctrl[0].c[1] * s * s * s + 3.0f * ctrl[1].c[1] * fraction * s * s + 3.0f * ctrl[2].c[1] * fraction * fraction * s + ctrl[3].c[1] * fraction * fraction * fraction;
          out[2] = ctrl[0].c[2] * s * s * s + 3.0f * ctrl[1].c[2] * fraction * s * s + 3.0f * ctrl[2].c[2] * fraction * fraction * s + ctrl[3].c[2] * fraction * fraction * fraction;
          jj++;
          out = out + 6;
        }
        jj = ((EffAfterQueue *)work)->writeIndex - ((EffAfterQueue *)work)->count;
        if (jj < 0) {
          jj = jj + ((EffAfterQueue *)work)->count;
        }
        if (out >= lim) {
          kAssertFail(D_007146E0,0x4ae);
        }
        /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
        pb = (f32 *)(*(s32 *)(((work) + side * 4 + 0x10)) + jj * 0xc);
        *(EffAfterVec *)out = *(EffAfterVec *)pb;
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        if (*(s32 *)((work) + 8) < ((EffAfterQueue *)work)->config->capacity) {
          section = 0;
        }
        else {
          /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
          section = *(u32 *)((work) + 0xc);
        }
          side++;
      }
    }
    break;
    case 1:
    {
      countOrAddress = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      vertexWords = (u32 *)((RpGeometry *)*pp)->morphTarget->vertices;
      for (index = 0; index < countOrAddress;) {
        vertexWords[0] = 0;
        vertexWords[1] = 0;
        vertexWords[2] = 0;
        index++;
        vertexWords += 3;
      }
      vertexBase = ((RpGeometry *)*pp)->morphTarget->vertices;
      countOrAddress = ((EffAfterQueue *)work)->writeIndex - 1;
      if (countOrAddress < 0) {
        countOrAddress = countOrAddress + ((EffAfterQueue *)work)->count;
      }
      vectorCursor = (f32 *)(((u8 *)*(u8 **)effAfterWorkFieldPtr(0x10, work)) + countOrAddress * 0xc);
      *(EffAfterVec *)vertexBase = *(EffAfterVec *)vectorCursor;
      vectorCursor = (f32 *)(((u8 *)*(u8 **)effAfterWorkFieldPtr(0x14, work)) + countOrAddress * 0xc);
      *(EffAfterVec *)&vertexBase[3] = *(EffAfterVec *)vectorCursor;
      vertexBase[6] = *vertexBase + vertexBase[3];
      vertexBase[7] = vertexBase[1] + vertexBase[4];
      vertexBase[8] = vertexBase[2] + vertexBase[5];
      vertexBase[6] = vertexBase[6] * 0.5f;
      vertexBase[7] = vertexBase[7] * 0.5f;
      vertexBase[8] = vertexBase[8] * 0.5f;
      countOrAddress = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
      index = *(s32 *)((work) + 0xc) - *(s32 *)((work) + 8);
      if (index < 0) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        index = index + *(s32 *)((work) + 8);
      }
{
        f32 *row;
        u32 srcOff;

        srcOff = index * 0xc;
        ((EffAfterVec *)(row = (f32 *)effAfterWorkFieldPtr((u32)(countOrAddress * 3) * 4, (u8 *)vertexBase)))[-3] = ((EffAfterQueue *)work)->positions[index];
      ((EffAfterVec *)row)[-2] = ((EffAfterQueue *)work)->normals[index];
      row[-3] = row[-9] + row[-6];
      row[-2] = row[-8] + row[-5];
      row[-1] = row[-7] + row[-4];
      row[-3] = row[-3] * 0.5f;
      row[-2] = row[-2] * 0.5f;
      row[-1] = row[-1] * 0.5f;
      }
      countOrAddress = (s32)((RpGeometry *)*pp)->morphTarget->vertices;
      blend = (f32)((EffAfterQueue *)work)->config->sectionCount + 0.5f;
      sampleStep = 1.0f / blend;
      for (index = 0; index < 2; index = index + 1) {
        switch (index) {
        case 0:
          outputVertex = (f32 *)(countOrAddress + 0x24);
          break;
        case 1:
          outputVertex = (f32 *)(countOrAddress + 0x30);
          break;
        }
        sampleFraction = 0.5f / blend;
        cachedSection = 0xffffffff;
        for (sampleIndex = 0; sampleIndex < ((EffAfterQueue *)work)->config->sectionCount;) {
          effAfterSectionFraction(work,sampleFraction,&section,&fraction);
          if (section != cachedSection) {
            cachedSection = section;
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            firstOffset = (*(s32 *)((work) + 0xc) - 1) - section;
            if (firstOffset < 0) {
              firstOffset = firstOffset + ((EffAfterQueue *)work)->count;
            }
            /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
            secondIndex = (*(s32 *)((work) + 0xc) - 1) - (section + 1);
            if (secondIndex < 0) {
              secondIndex = secondIndex + ((EffAfterQueue *)work)->count;
            }
            firstOffset = firstOffset * 0xc;
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            vectorCursor = (f32 *)(*(u8 **)(((work) + index * 4 + 0x10)) + firstOffset);
            ctrl[0] = *(EffAfterVec *)vectorCursor;
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            vertexBase = (f32 *)(*(u8 **)(((work) + index * 8 + 0x18)) + firstOffset);
            ctrl[1].c[0] = *vectorCursor - *vertexBase;
            ctrl[1].c[1] = vectorCursor[1] - vertexBase[1];
            ctrl[1].c[2] = vectorCursor[2] - vertexBase[2];
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            vectorCursor = (f32 *)(*(u8 **)(((work) + index * 8 + 0x1c)) + firstOffset);
            /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
            vertexBase = (f32 *)(*(u8 **)(((work) + index * 4 + 0x10)) + secondIndex * 0xc);
            ctrl[2].c[0] = *vertexBase + *vectorCursor;
            ctrl[2].c[1] = vertexBase[1] + vectorCursor[1];
            ctrl[2].c[2] = vertexBase[2] + vectorCursor[2];
            ctrl[3] = *(EffAfterVec *)vertexBase;
          }
          weight = 1.0f - fraction;
          *outputVertex = ctrl[0].c[0] * weight * weight * weight + 3.0f * ctrl[1].c[0] * fraction * weight * weight + 3.0f * ctrl[2].c[0] * fraction * fraction * weight + ctrl[3].c[0] * fraction * fraction * fraction;
          outputVertex[1] =
               ctrl[0].c[1] * weight * weight * weight + 3.0f * ctrl[1].c[1] * fraction * weight * weight + 3.0f * ctrl[2].c[1] * fraction * fraction * weight + ctrl[3].c[1] * fraction * fraction * fraction;
          outputVertex[2] =
               ctrl[0].c[2] * weight * weight * weight + 3.0f * ctrl[1].c[2] * fraction * weight * weight + 3.0f * ctrl[2].c[2] * fraction * fraction * weight + ctrl[3].c[2] * fraction * fraction * fraction;
          sampleFraction = sampleFraction + sampleStep;
          sampleIndex++;
          outputVertex = outputVertex + 9;
        }
        outputVertex = (f32 *)(countOrAddress + 0x3c);
        for (sampleIndex = 0; sampleIndex < ((EffAfterQueue *)work)->config->sectionCount;) {
          *outputVertex = outputVertex[-6] + outputVertex[-3];
          outputVertex[1] = outputVertex[-5] + outputVertex[-2];
          outputVertex[2] = outputVertex[-4] + outputVertex[-1];
          *outputVertex = *outputVertex + outputVertex[3];
          outputVertex[1] = outputVertex[1] + outputVertex[4];
          outputVertex[2] = outputVertex[2] + outputVertex[5];
          *outputVertex = *outputVertex + outputVertex[6];
          outputVertex[1] = outputVertex[1] + outputVertex[7];
          outputVertex[2] = outputVertex[2] + outputVertex[8];
          *outputVertex = *outputVertex * 0.25f;
          outputVertex[1] = outputVertex[1] * 0.25f;
          outputVertex[2] = outputVertex[2] * 0.25f;
          sampleIndex++;
          outputVertex = outputVertex + 9;
        }
      }
    }
    break;
    case 2:
    {
      halfWidth = ((EffAfterQueue *)work)->config->width / 2.0f;
      countOrAddress = kwlnGetCamera();
      countOrAddress = (s32)((RwObject *)countOrAddress)->parent;
      cameraPosition = (f32 *)(countOrAddress + 0x40);
      vertexBase = ((RpGeometry *)*pp)->morphTarget->vertices;
      weight = 0.5f + (f32)((EffAfterQueue *)work)->config->sectionCount;
      sampleFraction = 1.0f / weight;
      weight = 0.5f / weight;
      cachedSection = 0xffffffff;
      vectorCursor = vertexBase + 9;
      index = ((EffAfterQueue *)work)->writeIndex - 1;
      if (index < 0) {
        index = index + ((EffAfterQueue *)work)->count;
      }
      prev = ((EffAfterQueue *)work)->positions[index];
      for (index = 0; index < ((EffAfterQueue *)work)->config->sectionCount;) {
        effAfterSectionFraction(work,weight,&section,&fraction);
        if (section != cachedSection) {
          cachedSection = section;
          /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
          sampleIndex = (*(s32 *)((work) + 0xc) - 1) - section;
          if (sampleIndex < 0) {
            sampleIndex = sampleIndex + ((EffAfterQueue *)work)->count;
          }
          /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
          secondIndex = (*(s32 *)((work) + 0xc) - 1) - (section + 1);
          if (secondIndex < 0) {
            secondIndex = secondIndex + ((EffAfterQueue *)work)->count;
          }
          sampleIndex = sampleIndex * 0xc;
          /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
          byteCursor = *(u8 **)(work + 0x10);
          controlStart = (f32 *)(byteCursor + sampleIndex);
          ctrl[0] = *(EffAfterVec *)controlStart;
          controlEnd = (f32 *)(((u8 *)(u8 *)((EffAfterQueue *)work)->positionOffsets[0]) + sampleIndex);
          ctrl[1].c[0] = *controlStart - *controlEnd;
          ctrl[1].c[1] = controlStart[1] - controlEnd[1];
          ctrl[1].c[2] = controlStart[2] - controlEnd[2];
          controlStart = (f32 *)(((u8 *)(u8 *)((EffAfterQueue *)work)->positionOffsets[1]) + sampleIndex);
          controlEnd = (f32 *)(byteCursor + secondIndex * 0xc);
          ctrl[2].c[0] = *controlEnd + *controlStart;
          ctrl[2].c[1] = controlEnd[1] + controlStart[1];
          ctrl[2].c[2] = controlEnd[2] + controlStart[2];
          ctrl[3] = *(EffAfterVec *)controlEnd;
        }
        blend = 1.0f - fraction;
        cur.c[0] = ctrl[0].c[0] * blend * blend * blend + 3.0f * ctrl[1].c[0] * fraction * blend * blend + 3.0f * ctrl[2].c[0] * fraction * fraction * blend + ctrl[3].c[0] * fraction * fraction * fraction;
        cur.c[1] = ctrl[0].c[1] * blend * blend * blend + 3.0f * ctrl[1].c[1] * fraction * blend * blend + 3.0f * ctrl[2].c[1] * fraction * fraction * blend + ctrl[3].c[1] * fraction * fraction * fraction;
        cur.c[2] = ctrl[0].c[2] * blend * blend * blend + 3.0f * ctrl[1].c[2] * fraction * blend * blend + 3.0f * ctrl[2].c[2] * fraction * fraction * blend + ctrl[3].c[2] * fraction * fraction * fraction;
        if (index == 0) {
          first = cur;
        }
        toCamera.c[0] = *cameraPosition - cur.c[0];
        toCamera.c[1] = cameraPosition[1] - cur.c[1];
        toCamera.c[2] = cameraPosition[2] - cur.c[2];
        RwV3dNormalize(&toCamera.c[0],&toCamera.c[0]);
        tangent.c[0] = prev.c[0] - cur.c[0];
        tangent.c[1] = prev.c[1] - cur.c[1];
        tangent.c[2] = prev.c[2] - cur.c[2];
        RwV3dNormalize(&tangent.c[0],&tangent.c[0]);
        sideOffset.c[0] = toCamera.c[1] * tangent.c[2] - toCamera.c[2] * tangent.c[1];
        sideOffset.c[1] = toCamera.c[2] * tangent.c[0] - toCamera.c[0] * tangent.c[2];
        sideOffset.c[2] = toCamera.c[0] * tangent.c[1] - toCamera.c[1] * tangent.c[0];
        RwV3dNormalize(&sideOffset.c[0],&sideOffset.c[0]);
        blend = toCamera.c[0] * tangent.c[0] + toCamera.c[1] * tangent.c[1] + toCamera.c[2] * tangent.c[2];
        if (blend < 0.0f) {
          blend = blend * -1.0f;
        }
        blend = blend * (blend * blend);
        blend = halfWidth * (1.0f - blend);
        sideOffset.c[0] = sideOffset.c[0] * blend;
        sideOffset.c[1] = sideOffset.c[1] * blend;
        sideOffset.c[2] = sideOffset.c[2] * blend;
        vectorCursor[0] = cur.c[0] + sideOffset.c[0];
        vectorCursor[1] = cur.c[1] + sideOffset.c[1];
        vectorCursor[2] = cur.c[2] + sideOffset.c[2];
        vectorCursor[3] = cur.c[0] - sideOffset.c[0];
        vectorCursor[4] = cur.c[1] - sideOffset.c[1];
        vectorCursor[5] = cur.c[2] - sideOffset.c[2];
        vectorCursor += 9;
        prev = cur;
        weight = weight + sampleFraction;
        index++;
      }
      sampleIndex = ((EffAfterQueue *)work)->config->sectionCount * 3 + 6;
      vectorCursor = vertexBase + (sampleIndex - 3) * 3;
      /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
      index = *(s32 *)((work) + 0xc) - ((EffAfterQueue *)work)->count;
      if (index < 0) {
        index = index + ((EffAfterQueue *)work)->count;
      }
      controlEnd = (f32 *)(((u8 *)*(u8 **)effAfterWorkFieldPtr(0x10, work)) + index * 0xc);
      cur = *(EffAfterVec *)controlEnd;
      toCamera.c[0] = *cameraPosition - cur.c[0];
      toCamera.c[1] = cameraPosition[1] - cur.c[1];
      toCamera.c[2] = cameraPosition[2] - cur.c[2];
      RwV3dNormalize(&toCamera.c[0],&toCamera.c[0]);
      tangent.c[0] = prev.c[0] - cur.c[0];
      tangent.c[1] = prev.c[1] - cur.c[1];
      tangent.c[2] = prev.c[2] - cur.c[2];
      RwV3dNormalize(&tangent.c[0],&tangent.c[0]);
      sideOffset.c[0] = toCamera.c[1] * tangent.c[2] - toCamera.c[2] * tangent.c[1];
      sideOffset.c[1] = toCamera.c[2] * tangent.c[0] - toCamera.c[0] * tangent.c[2];
      sideOffset.c[2] = toCamera.c[0] * tangent.c[1] - toCamera.c[1] * tangent.c[0];
      RwV3dNormalize(&sideOffset.c[0],&sideOffset.c[0]);
      weight = toCamera.c[0] * tangent.c[0] + toCamera.c[1] * tangent.c[1] + toCamera.c[2] * tangent.c[2];
      if (weight < 0.0f) {
        weight = weight * -1.0f;
      }
      weight = weight * (weight * weight);
      weight = halfWidth * (1.0f - weight);
      sideOffset.c[0] = sideOffset.c[0] * weight;
      sideOffset.c[1] = sideOffset.c[1] * weight;
      sideOffset.c[2] = sideOffset.c[2] * weight;
      *vectorCursor = cur.c[0] + sideOffset.c[0];
      vectorCursor[1] = cur.c[1] + sideOffset.c[1];
      vectorCursor[2] = cur.c[2] + sideOffset.c[2];
      vectorCursor[3] = cur.c[0] - sideOffset.c[0];
      vectorCursor[4] = cur.c[1] - sideOffset.c[1];
      vectorCursor[5] = cur.c[2] - sideOffset.c[2];
      vertexBase[sampleIndex * 3 - 3] = vertexBase[sampleIndex * 3 - 9] + vertexBase[sampleIndex * 3 - 6];
      vertexBase[sampleIndex * 3 - 2] = vertexBase[sampleIndex * 3 - 8] + vertexBase[sampleIndex * 3 - 5];
      vertexBase[sampleIndex * 3 - 1] = vertexBase[sampleIndex * 3 - 7] + vertexBase[sampleIndex * 3 - 4];
      vertexBase[sampleIndex * 3 - 3] = vertexBase[sampleIndex * 3 - 3] * 0.5f;
      vertexBase[sampleIndex * 3 - 2] = vertexBase[sampleIndex * 3 - 2] * 0.5f;
      vertexBase[sampleIndex * 3 - 1] = vertexBase[sampleIndex * 3 - 1] * 0.5f;
      /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
      index = *(s32 *)((work) + 0xc) - 1;
      if (index < 0) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        index = index + *(s32 *)((work) + 8);
      }
      vectorCursor = (f32 *)(((u8 *)*(u8 **)effAfterWorkFieldPtr(0x10, work)) + index * 0xc);
      last = *(EffAfterVec *)vectorCursor;
      toCamera.c[0] = *cameraPosition - last.c[0];
      toCamera.c[1] = cameraPosition[1] - last.c[1];
      toCamera.c[2] = cameraPosition[2] - last.c[2];
      RwV3dNormalize(&toCamera.c[0],&toCamera.c[0]);
      tangent.c[0] = last.c[0] - first.c[0];
      tangent.c[1] = last.c[1] - first.c[1];
      tangent.c[2] = last.c[2] - first.c[2];
      RwV3dNormalize(&tangent.c[0],&tangent.c[0]);
      sideOffset.c[0] = toCamera.c[1] * tangent.c[2] - toCamera.c[2] * tangent.c[1];
      sideOffset.c[1] = toCamera.c[2] * tangent.c[0] - toCamera.c[0] * tangent.c[2];
      sideOffset.c[2] = toCamera.c[0] * tangent.c[1] - toCamera.c[1] * tangent.c[0];
      RwV3dNormalize(&sideOffset.c[0],&sideOffset.c[0]);
      weight = toCamera.c[0] * tangent.c[0] + toCamera.c[1] * tangent.c[1] + toCamera.c[2] * tangent.c[2];
      if (weight < 0.0f) {
        weight = weight * -1.0f;
      }
      weight = weight * (weight * weight);
      halfWidth = halfWidth * (1.0f - weight);
      sideOffset.c[0] = sideOffset.c[0] * halfWidth;
      sideOffset.c[1] = sideOffset.c[1] * halfWidth;
      sideOffset.c[2] = sideOffset.c[2] * halfWidth;
      *vertexBase = last.c[0] + sideOffset.c[0];
      vertexBase[1] = last.c[1] + sideOffset.c[1];
      vertexBase[2] = last.c[2] + sideOffset.c[2];
      vertexBase[3] = last.c[0] - sideOffset.c[0];
      vertexBase[4] = last.c[1] - sideOffset.c[1];
      vertexBase[5] = last.c[2] - sideOffset.c[2];
      vertexBase[6] = *vertexBase + vertexBase[3];
      vertexBase[7] = vertexBase[1] + vertexBase[4];
      vertexBase[8] = vertexBase[2] + vertexBase[5];
      vertexBase[6] = vertexBase[6] * 0.5f;
      vertexBase[7] = vertexBase[7] * 0.5f;
      vertexBase[8] = vertexBase[8] * 0.5f;
      vertexBase = vertexBase + 0xf;
      for (countOrAddress = 0; countOrAddress < ((EffAfterQueue *)work)->config->sectionCount;) {
        *vertexBase = vertexBase[-6] + vertexBase[-3];
        vertexBase[1] = vertexBase[-5] + vertexBase[-2];
        vertexBase[2] = vertexBase[-4] + vertexBase[-1];
        *vertexBase = *vertexBase + vertexBase[3];
        vertexBase[1] = vertexBase[1] + vertexBase[4];
        vertexBase[2] = vertexBase[2] + vertexBase[5];
        *vertexBase = *vertexBase + vertexBase[6];
        vertexBase[1] = vertexBase[1] + vertexBase[7];
        vertexBase[2] = vertexBase[2] + vertexBase[8];
        *vertexBase = *vertexBase * 0.25f;
        vertexBase[1] = vertexBase[1] * 0.25f;
        vertexBase[2] = vertexBase[2] * 0.25f;
        countOrAddress++;
        vertexBase = vertexBase + 9;
      }
    }
    }
  }
  func_003c22f0(*pp);
  ((RpGeometry *)*pp)->lockedSinceLastInst = ((RpGeometry *)*pp)->lockedSinceLastInst | 1;
  bound.center.c[0] = 0.0f;
  bound.center.c[1] = 0.0f;
  bound.center.c[2] = 0.0f;
  bound.radius = (f32)1000000000;
  *(EffAfterSphere *)&((RpGeometry *)*pp)->morphTarget->boundingSphere = bound;
  return;
}

#pragma pop


// Pushes one position and normal into the sample ring, overwriting the oldest when full, then refreshes section 0 (and section 1 once three samples are queued).
// FUN_004BAD70
void effAfterQueuePush(u8 *data, EffAfterVec *position, EffAfterVec *normal) {
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
        kAssertFail(D_007146E0, 0x5BB);
        break;
    case 1:
        break;
    case 2:
        effAfterQueueSectionOffsets(queue, 0);
        break;
    default:
        effAfterQueueSectionOffsets(queue, 1);
        effAfterQueueSectionOffsets(queue, 0);
        break;
    }
}
// Rewinds the command cursor, clears execution flags and resets the target section's progress work.
// FUN_004BAEA0
void effAfterResetCommand(RuntimeCommandWork* work)
{
    work->cursor = work->start;
    work->flags = 0;
    effMiscProgressReset(work->target);
}
// Runs the command stream at work->cursor until opcode 0; opcode 1 reads a 32-bit duration from two halfwords.
// FUN_004BAED0
void effAfterRunCommands(RuntimeCommandWork* work, u32* unused)
{
    u16* cursor;
    u32 duration;
    u16* durationParts;
    EffAfterQueue* target;
    s32 stop;

    /* Operands are packed halfwords: use a word load only at aligned positions. */
    cursor = work->cursor;
    stop = 0;
    do
    {
        switch (*cursor)
        {
        case 0:
            stop = 1;
            break;
        case 1:
            if ((~work->flags & 1) != 0)
            {
                if ((((u32)(cursor + 1) >> 1) & 1) != 0)
                {
                    durationParts = (u16*)&duration;
                    durationParts[0] = cursor[1];
                    durationParts[1] = cursor[2];
                }
                else
                {
                    /* Packed halfword command operand; this branch alone permits an aligned word load. */
                    duration = *(u32*)(cursor + 1);
                }
                work->flags |= 1;
                work->elapsed = 0;
            }
            else
            {
                work->elapsed++;
            }
            if ((((u32)(cursor + 1) >> 1) & 1) != 0)
            {
                durationParts = (u16*)&duration;
                durationParts[0] = cursor[1];
                durationParts[1] = cursor[2];
            }
            else
            {
                /* Packed halfword command operand; this branch alone permits an aligned word load. */
                duration = *(u32*)(cursor + 1);
            }
            stop = 1;
            if (work->elapsed >= duration)
            {
                cursor += 3;
                work->flags &= ~1;
                stop = 0;
            }
            break;
        case 0x100:
            work->flags |= 2;
            cursor++;
            break;
        case 0x101:
            work->flags &= ~2;
            cursor++;
            break;
        case 0x102:
            target = work->target;
            target->count = 0;
            target->writeIndex = 0;
            cursor++;
            break;
        case 0x200:
            switch (work->delay)
            {
            case 0:
                if (work->duration != 0)
                {
                    effMiscProgressStart((u8 *)work->target, (f32)work->duration / 30.0f);
                }
                break;
            }
            cursor++;
            break;
        case 0x201:
            work->delay = (s16)cursor[1];
            cursor += 2;
            break;
        case 0x202:
            if ((((u32)(cursor + 1) >> 1) & 1) != 0)
            {
                durationParts = (u16*)&duration;
                durationParts[0] = cursor[1];
                durationParts[1] = cursor[2];
            }
            else
            {
                /* Packed halfword command operand; this branch alone permits an aligned word load. */
                duration = *(u32*)(cursor + 1);
            }
            work->duration = duration;
            cursor += 3;
            break;
        case 0x400:
            work->flags |= 8;
            cursor++;
            break;
        }
    } while ((u32)(stop != 0) ^ 1);
    work->cursor = cursor;
}
/* Builds the scaled offset vectors for one ribbon section and the section
 * after it, for both the position and the normal strip. Each vector blends
 * the sample's own direction with the directions to the neighbouring samples
 * in the ring buffer, then is normalised and scaled by the section width. */
// FUN_004BB1D0
void effAfterQueueSectionOffsets(EffAfterQueue *queue, s32 section)
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
    sel = !(effAfterSideSegmentLength((u8 *)queue, section, 0) > effAfterSideSegmentLength((u8 *)queue, section, 1));
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
    scale = w0 * effAfterSideSegmentLength((u8 *)queue, section, 0);
    pw = &alphas[sel & 1];
    a0 = *pw;
    term = a0 * effAfterSectionTurnFactor((u8 *)queue, section);
    scale = scale + term;
    effAfterSideAxis((u8 *)queue, section, 0, &dir);
    dir.c[0] *= mid0;
    dir.c[1] *= mid0;
    dir.c[2] *= mid0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        kAssertFail(D_007146E0, 0x14E);
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
        kAssertFail(D_007146E0, 0x137);
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
    scale = w1 * effAfterSideSegmentLength((u8 *)queue, section, 1);
    pw = &alphas[(sel + 1) & 1];
    a1 = *pw;
    term = a1 * effAfterSectionTurnFactor((u8 *)queue, section);
    scale = scale + term;
    effAfterSideAxis((u8 *)queue, section, 1, &dir);
    dir.c[0] *= mid0;
    dir.c[1] *= mid0;
    dir.c[2] *= mid0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        kAssertFail(D_007146E0, 0x14E);
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
        kAssertFail(D_007146E0, 0x137);
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
    w0 *= effAfterSideSegmentLength((u8 *)queue, section, 0);
    term = a0 * effAfterSectionTurnFactor((u8 *)queue, section);
    scale2 = w0 + term;
    effAfterSideAxis((u8 *)queue, following, 0, &dir);
    dir.c[0] *= mid1;
    dir.c[1] *= mid1;
    dir.c[2] *= mid1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        kAssertFail(D_007146E0, 0x14E);
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
        kAssertFail(D_007146E0, 0x137);
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
    scale2 = w1 * effAfterSideSegmentLength((u8 *)queue, section, 1);
    term = a1 * effAfterSectionTurnFactor((u8 *)queue, section);
    scale2 = scale2 + term;
    effAfterSideAxis((u8 *)queue, following, 1, &dir);
    dir.c[0] *= mid1;
    dir.c[1] *= mid1;
    dir.c[2] *= mid1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (queue->count < 2) {
        kAssertFail(D_007146E0, 0x14E);
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
        kAssertFail(D_007146E0, 0x137);
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
// Length of the segment between two adjacent samples of ring arg2 at section arg1, read through effAfterWorkFieldPtr.
// FUN_004BC1E0
f32 effAfterSideSegmentLength(u8 *work, s32 section, s32 side)
{
    f32 v[3];
    s32 i;
    s32 offset;
    f32 *p;
    f32 a;
    f32 b;
    f32 c;
    f32 t;

    if (section == ((EffAfterQueue *)work)->count - 1) {
        kAssertFail(D_007146E0, 0x6F8);
    }
    i = -2 - section + ((EffAfterQueue *)work)->writeIndex;
    if (i < 0) {
        i += ((EffAfterQueue *)work)->count;
    }
    /* The helper preserves offset-first table addressing; a typed rewrite changes the add order. */
    /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
    p = (f32 *)(*(u8 **)(effAfterWorkFieldPtr(side * 4, work) + 0x10) + i * 0xC);
    a = p[0];
    b = p[1];
    c = p[2];
    v[0] = a;
    v[1] = b;
    v[2] = c;
    i = ((EffAfterQueue *)work)->writeIndex - 1 - section;
    if (i < 0) {
        i += ((EffAfterQueue *)work)->count;
    }
    offset = i * 0xC;
    /* Interleaved side-pointer table: preserve the observed 4/8-byte slot addressing. */
    p = (f32 *)(*(u8 **)(effAfterWorkFieldPtr(side * 4, work) + 0x10) + offset);
    t = p[0];
    v[0] -= t;
    t = p[1];
    v[1] -= t;
    t = p[2];
    v[2] -= t;
    return RwV3dLength(v);
}
#pragma optimization_level 2

// Turn factor of a section: (1 - dot) / 2 of the normalised edge vectors at the section's two ends; 0 for a straight run, 1 for a reversal.
// FUN_004BC310
f32 effAfterSectionTurnFactor(u8 *work, s32 section) {
    /* Earlier whole-layout comparison: 369 differing bytes; remaining raw sites are isolated below. */
    EffAfterVec v1;
    EffAfterVec v2;
    EffAfterVec *q;
    f32 d;
    f32 t;
    s32 i;
    s32 j;
    u8 *p;

    if (section == ((EffAfterQueue *)work)->count - 1) {
        kAssertFail(D_007146E0, 0x709);
    }
    i = (((EffAfterQueue *)work)->writeIndex - 1) - section;
    if (i < 0) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        i += *(s32 *)(work + 8);
    }
    p = (u8 *)((s32)((EffAfterQueue *)work)->normals + i * 0xC);
    v1 = *(EffAfterVec *)p;
    p = (u8 *)((s32)((EffAfterQueue *)work)->positions + i * 0xC);
    q = (EffAfterVec *)p;
    t = q->c[0];
    v1.c[0] -= t;
    v1.c[1] -= q->c[1];
    v1.c[2] -= q->c[2];
    RwV3dNormalize(&v1.c[0], &v1.c[0]);
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    j = (-2 - section) + *(s32 *)(work + 0xC);
    if (j < 0) {
        /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
        j += *(s32 *)(work + 8);
    }
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    p = (u8 *)(*(s32 *)(work + 0x14) + j * 0xC);
    v2 = *(EffAfterVec *)p;
    /* measured: typing this access alone changes owner instructions (singleton MISMATCH). */
    p = (u8 *)(*(s32 *)(work + 0x10) + j * 0xC);
    q = (EffAfterVec *)p;
    t = q->c[0];
    v2.c[0] -= t;
    v2.c[1] -= q->c[1];
    v2.c[2] -= q->c[2];
    RwV3dNormalize(&v2.c[0], &v2.c[0]);
    d = v1.c[0] * v2.c[0] + v1.c[1] * v2.c[1] + v1.c[2] * v2.c[2];
    return (1.0f - d) / 2.0f;
}

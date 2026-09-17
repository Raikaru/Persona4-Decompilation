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
extern f32 func_003e4180(void *a0);
extern void func_003e40b0(f32 *a, f32 *b);
extern f32 func_004b7300(void *arg0, s32 arg1);
extern s32 func_004b7800(void *arg0, s32 arg1);
extern f32 func_004bc310(u8 *arg0, s32 arg1);
extern f32 func_004bc1e0(u8 *arg0, s32 arg1, s32 arg2);
extern void func_004bb1d0(void *arg0, s32 arg1);
extern void func_004b7dc0(u8 *arg0, s32 arg1, EffAfterVec *arg2);
extern void func_004b7830(u8 *arg0, s32 arg1, s32 arg2, EffAfterVec *arg3);
extern s32 func_003c2130(s32 obj, u8 *buf, u16 a, u16 b, u16 c);
extern s32 func_003c2150(s32 obj, u8 *buf, s32 arg2);
extern u8 *func_003c2630(s32 nVtx, s32 nIdx, u32 flags);
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
/* measured: floor for func_004b8350 (obj 2660B vs window 2720B, probe_variants 623 differing words reloc-masked, fnalign 665 vs 679 instrs).
   Frame 0xF0 vs retail 0x100 (-16B, -2.2% emitted, within ~3%); logic confirmed against retail asm (asm/nonmatchings/eff_after/func_004b8350.s via `grep -rl func_004b8350 asm/`),
   and M2C P4_UNIT_004B8350 in src/generated/code1_004b.c (406 draft lines, noise 6 lui-constructed 0.5f/1.0f + int 1e9 via cvt.s.w, no gp-relative loads to bank).
   Phases: flags 0x4A/0x4E, nVtx/nIdx per mode ((n-1)*2+1/n*2+1 vs n*4+4/n*3+6), 19x func_003c2130 sites (case0 2-call loop + tail, case1/2 2+4+2 with sq/lq spills at 0xD0/0xC0/0xB0/0xA0), 1x func_003c2150 loop over nIdx, func_004bc540 colors (case0) else byte-zero, alpha phase (asserts 0x226/0x234, 6-word header/trailer + strided loops), tail vec{0,0,0,(f32)1e9} to *(obj+0x5C).
   Residual is compiler floor per docs/matching.md: quadword-slot spills (retail sq/lq for 32-bit temps vs b210 sw), saved-reg rotation, branch-target shifts from duplicated mode1/2 blocks, and call-site reuse ($a3=2 leftover for first (0,3,2) vs explicit). u16 prototype for func_003c2130 recovers retail andi (vs s16 dsll/dsra) and saves ~40 instrs (710->665). Exhausted s16 vs u16, hoisted vs reloaded n, struct-vs-raw probes.
   No pooled float constants to bank (only lui 0x3F000000/0x3F800000/0x3B9ACA00, no gp-relative loads).
   Unit confirmed via `grep -rl func_004b8350 asm/` -> asm/nonmatchings/eff_after/func_004b8350.s.
   Production stays INCLUDE_ASM fallback; body preserved here as NON_MATCHING seed. */
// FUN_004B8350 NONMATCHING
#ifdef NON_MATCHING
u8 *func_004b8350(u8 *arg0, s32 arg1)
{
    u8 *cfg;
    u8 *obj;
    u8 *idxBase;
    u8 *idxPtr;
    u8 *colorBase;
    u8 *colorPtr;
    u8 *alphaBase;
    u8 *alphaPtr;
    u8 *tailBase;
    s32 n;
    s32 nVtx;
    s32 nIdx;
    s32 flags;
    s32 mode;
    s32 i;
    s32 j;
    s32 base;
    s32 nxt;
    s32 t1;
    s32 t2;
    s32 cur;
    s32 iter;
    f32 t;
    f32 denom;
    f32 inv;
    f32 half;
    f32 curF;
    f32 zeros[4];

    cfg = *(u8 **)arg0;
    flags = 0x4A;
    if ((**(s32 **)(cfg + 4) & 1) != 0) {
        flags = 0x4A | 4;
    }
    nIdx = 0;
    nVtx = 0;
    mode = *(s16 *)(arg0 + 0x38);
    n = *(s32 *)(cfg + 0xC);
    switch (mode) {
    case 0:
        nIdx = (n - 1) * 2 + 1;
        nVtx = n * 2 + 1;
        break;
    case 1:
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    case 2:
        nIdx = n * 4 + 4;
        nVtx = n * 3 + 6;
        break;
    }
    obj = func_003c2630(nVtx, nIdx, flags);
    idxBase = *(u8 **)(obj + 0x2C);
    mode = *(s16 *)(arg0 + 0x38);
    switch (mode) {
    case 0:
        i = 0;
        idxPtr = idxBase;
        while (i < (*(s32 *)(*(u8 **)arg0 + 0xC) - 1)) {
            base = i * 2;
            nxt = base + 2;
            cur = base + 1;
            func_003c2130((s32)obj, idxPtr, base, cur, nxt);
            func_003c2130((s32)obj, idxPtr + 8, cur, base + 3, nxt);
            idxPtr += 0x10;
            i++;
        }
        base = i * 2;
        func_003c2130((s32)obj, idxPtr, base, base + 1, base + 2);
        break;
    case 1:
        func_003c2130((s32)obj, idxBase, 0, 3, 2);
        func_003c2130((s32)obj, idxBase + 8, 2, 4, 1);
        idxPtr = idxBase + 0x10;
        cur = 2;
        iter = 0;
        while (iter < *(s32 *)(*(u8 **)arg0 + 0xC)) {
            base = cur & 0xFFFF;
            nxt = base + 3;
            t1 = base + 1;
            func_003c2130((s32)obj, idxPtr, cur, t1, nxt);
            t2 = base + 2;
            func_003c2130((s32)obj, idxPtr + 8, cur, nxt, t2);
            func_003c2130((s32)obj, idxPtr + 0x10, t1, base + 4, nxt);
            func_003c2130((s32)obj, idxPtr + 0x18, t2, nxt, base + 5);
            idxPtr += 0x20;
            cur = (cur + 3) & 0xFFFF;
            iter++;
        }
        base = cur & 0xFFFF;
        nxt = base + 3;
        func_003c2130((s32)obj, idxPtr, cur, base + 1, nxt);
        func_003c2130((s32)obj, idxPtr + 8, cur, nxt, base + 2);
        break;
    case 2:
        func_003c2130((s32)obj, idxBase, 0, 3, 2);
        func_003c2130((s32)obj, idxBase + 8, 2, 4, 1);
        idxPtr = idxBase + 0x10;
        cur = 2;
        iter = 0;
        while (iter < *(s32 *)(*(u8 **)arg0 + 0xC)) {
            base = cur & 0xFFFF;
            nxt = base + 3;
            t1 = base + 1;
            func_003c2130((s32)obj, idxPtr, cur, t1, nxt);
            t2 = base + 2;
            func_003c2130((s32)obj, idxPtr + 8, cur, nxt, t2);
            func_003c2130((s32)obj, idxPtr + 0x10, t1, base + 4, nxt);
            func_003c2130((s32)obj, idxPtr + 0x18, t2, nxt, base + 5);
            idxPtr += 0x20;
            cur = (cur + 3) & 0xFFFF;
            iter++;
        }
        base = cur & 0xFFFF;
        nxt = base + 3;
        func_003c2130((s32)obj, idxPtr, cur, base + 1, nxt);
        func_003c2130((s32)obj, idxPtr + 8, cur, nxt, base + 2);
        break;
    }
    idxBase = *(u8 **)(obj + 0x2C);
    i = 0;
    while (i < nIdx) {
        func_003c2150((s32)obj, idxBase, arg1);
        i++;
        idxBase += 8;
    }
    mode = *(s16 *)(arg0 + 0x38);
    switch (mode) {
    case 0:
        colorBase = *(u8 **)(obj + 0x30);
        i = 0;
        colorPtr = colorBase;
        while (i < *(s32 *)(*(u8 **)arg0 + 0xC)) {
            n = *(s32 *)(*(u8 **)arg0 + 0xC);
            if (i == 0) {
                t = (f32)i / (f32)(n - 1);
            } else {
                t = ((f32)i - 0.5f) / (f32)(n - 1);
            }
            func_004bc540(arg0, 0, colorPtr, t);
            i++;
            colorPtr += 8;
        }
        func_004bc540(arg0, 0, colorPtr, 1.0f);
        colorPtr = *(u8 **)(obj + 0x30) + 4;
        j = 0;
        while (j < *(s32 *)(*(u8 **)arg0 + 0xC)) {
            n = *(s32 *)(*(u8 **)arg0 + 0xC);
            t = (f32)j / (f32)(n - 1);
            func_004bc540(arg0, 1, colorPtr, t);
            j++;
            colorPtr += 8;
        }
        break;
    case 1:
        colorBase = *(u8 **)(obj + 0x30);
        i = 0;
        colorPtr = colorBase;
        while (i < nVtx) {
            colorPtr[0] = 0;
            colorPtr[1] = 0;
            colorPtr[2] = 0;
            colorPtr[3] = 0;
            i++;
            colorPtr += 4;
        }
        break;
    case 2:
        colorBase = *(u8 **)(obj + 0x30);
        i = 0;
        colorPtr = colorBase;
        while (i < nVtx) {
            colorPtr[0] = 0;
            colorPtr[1] = 0;
            colorPtr[2] = 0;
            colorPtr[3] = 0;
            i++;
            colorPtr += 4;
        }
        break;
    }
    cfg = *(u8 **)arg0;
    if ((**(s32 **)(cfg + 4) & 1) != 0) {
        mode = *(s16 *)(arg0 + 0x38);
        switch (mode) {
        case 0:
            alphaBase = *(u8 **)(obj + 0x34);
            i = 0;
            alphaPtr = alphaBase;
            while (i < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                n = *(s32 *)(*(u8 **)arg0 + 0xC);
                if ((n - 1) <= 0) {
                    func_0046d730(D_007146E0, 0x226);
                }
                if (i == 0) {
                    *(f32 *)(alphaPtr + 0) = (f32)i / (f32)(n - 1);
                } else {
                    *(f32 *)(alphaPtr + 0) = ((f32)i - 0.5f) / (f32)(n - 1);
                }
                *(s32 *)(alphaPtr + 4) = 0;
                i++;
                alphaPtr += 0x10;
            }
            *(s32 *)(alphaPtr + 0) = 0x3F800000;
            *(s32 *)(alphaPtr + 4) = 0;
            alphaPtr = *(u8 **)(obj + 0x34) + 8;
            j = 0;
            while (j < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                n = *(s32 *)(*(u8 **)arg0 + 0xC);
                if ((n - 1) <= 0) {
                    func_0046d730(D_007146E0, 0x234);
                }
                *(f32 *)(alphaPtr + 0) = (f32)j / (f32)(n - 1);
                *(s32 *)(alphaPtr + 4) = 0x3F800000;
                j++;
                alphaPtr += 0x10;
            }
            break;
        case 1:
            alphaBase = *(u8 **)(obj + 0x34);
            n = *(s32 *)(cfg + 0xC);
            denom = 0.5f + (f32)n;
            *(s32 *)(alphaBase + 0) = 0;
            *(s32 *)(alphaBase + 4) = 0;
            *(s32 *)(alphaBase + 8) = 0;
            *(s32 *)(alphaBase + 0xC) = 0x3F800000;
            *(s32 *)(alphaBase + 0x10) = 0;
            *(s32 *)(alphaBase + 0x14) = 0x3F000000;
            tailBase = alphaBase + ((n * 3 + 6) * 8);
            *(s32 *)(tailBase - 0x18) = 0x3F800000;
            *(s32 *)(tailBase - 0x14) = 0;
            *(s32 *)(tailBase - 0x10) = 0x3F800000;
            *(s32 *)(tailBase - 0xC) = 0x3F800000;
            *(s32 *)(tailBase - 8) = 0x3F800000;
            *(s32 *)(tailBase - 4) = 0x3F000000;
            inv = 1.0f / denom;
            half = 0.5f / denom;
            alphaPtr = alphaBase + 0x18;
            i = 0;
            curF = half;
            while (i < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                *(f32 *)(alphaPtr + 0) = curF;
                *(s32 *)(alphaPtr + 4) = 0;
                *(f32 *)(alphaPtr + 8) = curF;
                *(s32 *)(alphaPtr + 0xC) = 0x3F800000;
                alphaPtr += 0x18;
                i++;
                curF += inv;
            }
            alphaPtr = alphaBase + 0x28;
            j = 0;
            curF = inv;
            while (j < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                *(f32 *)(alphaPtr + 0) = curF;
                *(s32 *)(alphaPtr + 4) = 0x3F000000;
                j++;
                curF += inv;
                alphaPtr += 0x18;
            }
            break;
        case 2:
            alphaBase = *(u8 **)(obj + 0x34);
            n = *(s32 *)(cfg + 0xC);
            denom = 0.5f + (f32)n;
            *(s32 *)(alphaBase + 0) = 0;
            *(s32 *)(alphaBase + 4) = 0;
            *(s32 *)(alphaBase + 8) = 0;
            *(s32 *)(alphaBase + 0xC) = 0x3F800000;
            *(s32 *)(alphaBase + 0x10) = 0;
            *(s32 *)(alphaBase + 0x14) = 0x3F000000;
            tailBase = alphaBase + ((n * 3 + 6) * 8);
            *(s32 *)(tailBase - 0x18) = 0x3F800000;
            *(s32 *)(tailBase - 0x14) = 0;
            *(s32 *)(tailBase - 0x10) = 0x3F800000;
            *(s32 *)(tailBase - 0xC) = 0x3F800000;
            *(s32 *)(tailBase - 8) = 0x3F800000;
            *(s32 *)(tailBase - 4) = 0x3F000000;
            inv = 1.0f / denom;
            half = 0.5f / denom;
            alphaPtr = alphaBase + 0x18;
            i = 0;
            curF = half;
            while (i < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                *(f32 *)(alphaPtr + 0) = curF;
                *(s32 *)(alphaPtr + 4) = 0;
                *(f32 *)(alphaPtr + 8) = curF;
                *(s32 *)(alphaPtr + 0xC) = 0x3F800000;
                alphaPtr += 0x18;
                i++;
                curF += inv;
            }
            alphaPtr = alphaBase + 0x28;
            j = 0;
            curF = inv;
            while (j < *(s32 *)(*(u8 **)arg0 + 0xC)) {
                *(f32 *)(alphaPtr + 0) = curF;
                *(s32 *)(alphaPtr + 4) = 0x3F000000;
                j++;
                curF += inv;
                alphaPtr += 0x18;
            }
            break;
        }
    }
    zeros[0] = 0.0f;
    zeros[1] = 0.0f;
    zeros[2] = 0.0f;
    zeros[3] = (f32)1000000000;
    tailBase = *(u8 **)(obj + 0x5C);
    *(f32 *)(tailBase + 4) = zeros[0];
    *(f32 *)(tailBase + 8) = zeros[1];
    *(f32 *)(tailBase + 0xC) = zeros[2];
    *(f32 *)(tailBase + 0x10) = zeros[3];
    return obj;
}
#else
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004b8350);
#endif

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
/* measured: floor for func_004bb1d0 (obj 3952B vs window 4112B, probe_variants 879 differing words reloc-masked).
   Frame 0xA0 matches retail; initial param loads (0x1C->0x78, 0x24->0x70, 0x20->0x7C, 0x28->0x74) match.
   Logic confirmed against retail asm (asm/nonmatchings/eff_after/func_004bb1d0.s via `grep -rl func_004bb1d0 asm/`),
   IDA sub_4BB1D0, and M2C P4_UNIT_004BB1D0 (606 draft lines, noise 0): 4-block ribbon accumulation
   (sec,side,src,dst) = (arg1,0,0x10,0x18), (arg1,1,0x14,0x20), (arg1+1,0,0x10,0x1C), (arg1+1,1,0x14,0x24);
   triple selection (count==2 / section==0 vs else) and (count==2 || (count==3 && section==1) vs else);
   ring indices `-2 - sec + cursor` and `(cursor-1)-sec` with wrap by +count; asserts 0x14E/0x137 for count<2.
   Residual is compiler floor per docs/matching.md: swapped saved regs ($s2/$s1 for work/section,
   $f26 vs $f21 etc. for coeff/pair), scheduling (addiu before c.le.s vs after), and FPU choice
   (madd for scale vs retail mul+mul+add). Exhausted folded-displacement (struct AfterWork vs raw
   work+8 hoisting), reverse-order float/stack allocation, and struct-vs-raw probes.
   No pooled float constants (noise 0; only 0.0f via mtc1 $zero, no gp-relative loads to bank).
   Unit confirmed via `grep -rl func_004bb1d0 asm/` -> asm/nonmatchings/eff_after/func_004bb1d0.s.
   Production stays INCLUDE_ASM fallback; body preserved here as NON_MATCHING seed. */
// FUN_004BB1D0 NONMATCHING
#ifdef NON_MATCHING
void func_004bb1d0(void *arg0, s32 arg1) {
    typedef struct {
        u8 *config;
        s32 unk4;
        s32 count;
        s32 cursor;
        EffAfterVec *src0;
        EffAfterVec *src1;
        EffAfterVec *dst0;
        EffAfterVec *dst1;
        EffAfterVec *dst2;
        EffAfterVec *dst3;
    } AfterWork;
    AfterWork *work = (AfterWork *)arg0;
    EffAfterVec acc;
    EffAfterVec dir;
    f32 widths[2];
    f32 alphas[2];
    f32 coeff0;
    f32 pairA0;
    f32 pairB0;
    f32 pairB1;
    f32 pairA1;
    f32 coeff2;
    f32 coeff1;
    f32 scale;
    s32 sel;
    {
        u8 *param = *(u8 **)work->config;
        widths[0] = *(f32 *)(param + 0x1C);
        alphas[0] = *(f32 *)(param + 0x24);
        widths[1] = *(f32 *)(param + 0x20);
        alphas[1] = *(f32 *)(param + 0x28);
    }
    {
        f32 len0 = func_004bc1e0((u8 *)work, arg1, 0);
        f32 len1 = func_004bc1e0((u8 *)work, arg1, 1);
        s32 tmp = 1;
        if (len0 <= len1) {
            tmp = 0;
        }
        sel = tmp ^ 1;
    }
    if (work->count == 2) {
        u8 *param = *(u8 **)work->config;
        coeff0 = *(f32 *)(param + 0xC);
        coeff1 = *(f32 *)(param + 0x10);
        coeff2 = 0.0f;
    } else if (arg1 == 0) {
        u8 *param = *(u8 **)work->config;
        coeff0 = *(f32 *)(param + 0xC);
        coeff1 = *(f32 *)(param + 0x10);
        coeff2 = 0.0f;
    } else {
        u8 *param = *(u8 **)work->config;
        coeff0 = *(f32 *)(param + 0x0);
        coeff1 = *(f32 *)(param + 0x8);
        coeff2 = *(f32 *)(param + 0x4);
    }
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    pairA0 = widths[sel & 1];
    scale = pairA0 * func_004bc1e0((u8 *)work, arg1, 0);
    pairA1 = alphas[sel & 1];
    scale = scale + pairA1 * func_004bc310((u8 *)work, arg1);
    func_004b7830((u8 *)work, arg1, 0, &dir);
    dir.c[0] *= coeff0;
    dir.c[1] *= coeff0;
    dir.c[2] *= coeff0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (arg1 == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxA = (work->cursor - 1) - arg1;
        s32 idxB;
        EffAfterVec *base;
        if (idxA < 0) {
            idxA += work->count;
        }
        idxB = work->cursor - arg1;
        if (idxB < 0) {
            idxB += work->count;
        }
        base = work->src0;
        dir.c[0] = base[idxB].c[0] - base[idxA].c[0];
        dir.c[1] = base[idxB].c[1] - base[idxA].c[1];
        dir.c[2] = base[idxB].c[2] - base[idxA].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff2;
    dir.c[1] *= coeff2;
    dir.c[2] *= coeff2;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (arg1 == work->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxC = (work->cursor - 1) - arg1;
        s32 idxD;
        EffAfterVec *base;
        if (idxC < 0) {
            idxC += work->count;
        }
        idxD = -2 - arg1 + work->cursor;
        if (idxD < 0) {
            idxD += work->count;
        }
        base = work->src0;
        dir.c[0] = base[idxC].c[0] - base[idxD].c[0];
        dir.c[1] = base[idxC].c[1] - base[idxD].c[1];
        dir.c[2] = base[idxC].c[2] - base[idxD].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff1;
    dir.c[1] *= coeff1;
    dir.c[2] *= coeff1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    func_003e40b0(&acc.c[0], &acc.c[0]);
    acc.c[0] *= scale;
    acc.c[1] *= scale;
    acc.c[2] *= scale;
    {
        s32 idx = (work->cursor - 1) - arg1;
        EffAfterVec *dst;
        if (idx < 0) {
            idx += work->count;
        }
        dst = work->dst0;
        dst[idx] = acc;
    }
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    pairB0 = widths[(sel + 1) & 1];
    scale = pairB0 * func_004bc1e0((u8 *)work, arg1, 1);
    pairB1 = alphas[(sel + 1) & 1];
    scale = scale + pairB1 * func_004bc310((u8 *)work, arg1);
    func_004b7830((u8 *)work, arg1, 1, &dir);
    dir.c[0] *= coeff0;
    dir.c[1] *= coeff0;
    dir.c[2] *= coeff0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (arg1 == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxA = (work->cursor - 1) - arg1;
        s32 idxB;
        EffAfterVec *base;
        if (idxA < 0) {
            idxA += work->count;
        }
        idxB = work->cursor - arg1;
        if (idxB < 0) {
            idxB += work->count;
        }
        base = work->src1;
        dir.c[0] = base[idxB].c[0] - base[idxA].c[0];
        dir.c[1] = base[idxB].c[1] - base[idxA].c[1];
        dir.c[2] = base[idxB].c[2] - base[idxA].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff2;
    dir.c[1] *= coeff2;
    dir.c[2] *= coeff2;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (arg1 == work->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxC = (work->cursor - 1) - arg1;
        s32 idxD;
        EffAfterVec *base;
        if (idxC < 0) {
            idxC += work->count;
        }
        idxD = -2 - arg1 + work->cursor;
        if (idxD < 0) {
            idxD += work->count;
        }
        base = work->src1;
        dir.c[0] = base[idxC].c[0] - base[idxD].c[0];
        dir.c[1] = base[idxC].c[1] - base[idxD].c[1];
        dir.c[2] = base[idxC].c[2] - base[idxD].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff1;
    dir.c[1] *= coeff1;
    dir.c[2] *= coeff1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    func_003e40b0(&acc.c[0], &acc.c[0]);
    acc.c[0] *= scale;
    acc.c[1] *= scale;
    acc.c[2] *= scale;
    {
        s32 idx = (work->cursor - 1) - arg1;
        EffAfterVec *dst;
        if (idx < 0) {
            idx += work->count;
        }
        dst = work->dst2;
        dst[idx] = acc;
    }
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    if (work->count == 2) {
        u8 *param = *(u8 **)work->config;
        coeff2 = *(f32 *)(param + 0x14);
        coeff1 = 0.0f;
        coeff0 = *(f32 *)(param + 0x18);
    } else if (work->count == 3 && arg1 == 1) {
        u8 *param = *(u8 **)work->config;
        coeff2 = *(f32 *)(param + 0x14);
        coeff1 = 0.0f;
        coeff0 = *(f32 *)(param + 0x18);
    } else {
        u8 *param = *(u8 **)work->config;
        coeff2 = *(f32 *)(param + 0x0);
        coeff1 = *(f32 *)(param + 0x8);
        coeff0 = *(f32 *)(param + 0x4);
    }
    sel = arg1 + 1;
    pairA0 = pairA0 * func_004bc1e0((u8 *)work, arg1, 0);
    pairA1 = pairA0 + pairA1 * func_004bc310((u8 *)work, arg1);
    func_004b7830((u8 *)work, sel, 0, &dir);
    dir.c[0] *= coeff2;
    dir.c[1] *= coeff2;
    dir.c[2] *= coeff2;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (sel == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxA = (work->cursor - 1) - sel;
        s32 idxB;
        EffAfterVec *base;
        if (idxA < 0) {
            idxA += work->count;
        }
        idxB = work->cursor - sel;
        if (idxB < 0) {
            idxB += work->count;
        }
        base = work->src0;
        dir.c[0] = base[idxB].c[0] - base[idxA].c[0];
        dir.c[1] = base[idxB].c[1] - base[idxA].c[1];
        dir.c[2] = base[idxB].c[2] - base[idxA].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff0;
    dir.c[1] *= coeff0;
    dir.c[2] *= coeff0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (sel == work->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxC = (work->cursor - 1) - sel;
        s32 idxD;
        EffAfterVec *base;
        if (idxC < 0) {
            idxC += work->count;
        }
        idxD = -2 - sel + work->cursor;
        if (idxD < 0) {
            idxD += work->count;
        }
        base = work->src0;
        dir.c[0] = base[idxC].c[0] - base[idxD].c[0];
        dir.c[1] = base[idxC].c[1] - base[idxD].c[1];
        dir.c[2] = base[idxC].c[2] - base[idxD].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff1;
    dir.c[1] *= coeff1;
    dir.c[2] *= coeff1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    func_003e40b0(&acc.c[0], &acc.c[0]);
    acc.c[0] *= pairA1;
    acc.c[1] *= pairA1;
    acc.c[2] *= pairA1;
    {
        s32 idx = (work->cursor - 1) - arg1;
        EffAfterVec *dst;
        if (idx < 0) {
            idx += work->count;
        }
        dst = work->dst1;
        dst[idx] = acc;
    }
    acc.c[0] = 0.0f;
    acc.c[1] = 0.0f;
    acc.c[2] = 0.0f;
    pairA1 = pairB0 * func_004bc1e0((u8 *)work, arg1, 1);
    pairA1 = pairA1 + pairB1 * func_004bc310((u8 *)work, arg1);
    func_004b7830((u8 *)work, sel, 1, &dir);
    dir.c[0] *= coeff2;
    dir.c[1] *= coeff2;
    dir.c[2] *= coeff2;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x14E);
    }
    if (sel == 0) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxA = (work->cursor - 1) - sel;
        s32 idxB;
        EffAfterVec *base;
        if (idxA < 0) {
            idxA += work->count;
        }
        idxB = work->cursor - sel;
        if (idxB < 0) {
            idxB += work->count;
        }
        base = work->src1;
        dir.c[0] = base[idxB].c[0] - base[idxA].c[0];
        dir.c[1] = base[idxB].c[1] - base[idxA].c[1];
        dir.c[2] = base[idxB].c[2] - base[idxA].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff0;
    dir.c[1] *= coeff0;
    dir.c[2] *= coeff0;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    if (work->count < 2) {
        func_0046d730(D_007146E0, 0x137);
    }
    if (sel == work->count - 1) {
        dir.c[0] = 0.0f;
        dir.c[1] = 0.0f;
        dir.c[2] = 0.0f;
    } else {
        s32 idxC = (work->cursor - 1) - sel;
        s32 idxD;
        EffAfterVec *base;
        if (idxC < 0) {
            idxC += work->count;
        }
        idxD = -2 - sel + work->cursor;
        if (idxD < 0) {
            idxD += work->count;
        }
        base = work->src1;
        dir.c[0] = base[idxC].c[0] - base[idxD].c[0];
        dir.c[1] = base[idxC].c[1] - base[idxD].c[1];
        dir.c[2] = base[idxC].c[2] - base[idxD].c[2];
        func_003e40b0(&dir.c[0], &dir.c[0]);
    }
    dir.c[0] *= coeff1;
    dir.c[1] *= coeff1;
    dir.c[2] *= coeff1;
    acc.c[0] += dir.c[0];
    acc.c[1] += dir.c[1];
    acc.c[2] += dir.c[2];
    func_003e40b0(&acc.c[0], &acc.c[0]);
    acc.c[0] *= pairA1;
    acc.c[1] *= pairA1;
    acc.c[2] *= pairA1;
    {
        s32 idx = (work->cursor - 1) - arg1;
        EffAfterVec *dst;
        if (idx < 0) {
            idx += work->count;
        }
        dst = work->dst3;
        dst[idx] = acc;
    }
}
#else
INCLUDE_ASM("asm/nonmatchings/eff_after", func_004bb1d0);
#endif

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
    return func_003e4180(v);
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

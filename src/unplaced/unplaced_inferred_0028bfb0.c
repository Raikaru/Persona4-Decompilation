
/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_loop_invariants on

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
extern f32 evtLerpFloatIfEnabled(s32, f32, f32, f32);
extern void evtPolygonMovieLerpPose(s32, f32, f32 *, f32 *, f32 *);
s32 evtCheckCondition(u8 *);
typedef struct EvtMatrixPayload { f32 first, second; } EvtMatrixPayload;

// Walks the event node list and reports the first and last nodes matching a key.
// FUN_0028BFB0
void evtFindNodeRange(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3) {
    u8 *node;
    s16 frameOffset;
    s32 frame;

    *arg2 = NULL;
    *arg3 = NULL;
    if (arg0 == NULL) {
        goto done;
    }
    frameOffset = ((EvtNode *)arg0)->frameOffset;
    *arg3 = (u8 *)((EvtNode *)arg0)->childHead;
    goto loop_4_test;
loop_4_body:
    frame = ((s32)(((EvtChildNode *)node)->start) + (frameOffset));
    if (frame > arg1) {
        goto block_8;
    }
    *arg3 = (u8 *)((EvtChildNode *)node)->childNext;
loop_4_test:
    node = *arg3;
    if (node != NULL) {
        goto loop_4_body;
    }
block_8:
    if (node != NULL) {
        *arg2 = (u8 *)((EvtChildNode *)node)->childPrev;
        goto loop_10_test;
    }
    *arg2 = (u8 *)((EvtNode *)arg0)->childTail;
    goto loop_10_test;
loop_10_body:
    if (evtCheckCondition(*arg2) == 1) {
        goto done;
    }
    *arg2 = (u8 *)((EvtChildNode *)*arg2)->childPrev;
loop_10_test:
    if (*arg2 != NULL) {
        goto loop_10_body;
    }
done:
    return;
}

// Interpolates two matrix pairs between their start and end times by the ratio of elapsed time.
// FUN_0028C080
void evtInterpolateNodeMatrices(u8 *work, u8 *owner, s32 frame, u8 *output, f32 *firstValue,
                   f32 *secondValue) {
    u8 *start;
    u8 *end;
    f32 value0;
    f32 endFirst;
    f32 value1;
    f32 endSecond;
    f32 ratio;
    s32 startFrame;
    s32 endFrame;
    s32 count;
    f32 *matrix0;
    f32 *matrix1;
    f32 *dst;
    f32 *src;
    f32 *out;
    s32 i;

    evtFindNodeRange(owner, frame, &start, &end);
    if (start != NULL) {
        startFrame = ((EvtChildNode *)start)->start;
    } else {
        startFrame = ((EvtEventWork *)work)->startFrame;
    }
    if (end != NULL) {
        endFrame = ((EvtChildNode *)end)->start;
    } else {
        endFrame = ((EvtEventWork *)work)->frameLimit;
    }
    if (endFrame - startFrame != 0) {
        ratio = (f32)(frame - startFrame) / (f32)(endFrame - startFrame);
    } else {
        ratio = 0.0f;
    }
    dst = (f32 *)output;
    if (start == NULL) {
        goto no_start;
    }
    matrix0 = (f32 *)((EvtChildNode *)start)->ownedBlock48;
    value0 = ((EvtMatrixPayload *)&((EvtChildNode *)start)->payload)->first;
    value1 = ((EvtMatrixPayload *)&((EvtChildNode *)start)->payload)->second;
    count = ((EvtChildNode *)start)->unk04;
    goto have_start;

no_start:
    {
        f32 value;

        value = iGpffff809c;
        dst[0] = value;
        dst[1] = value;
        dst[2] = value;
        dst[3] = 0.0f;
        dst[4] = 0.0f;
        dst[5] = 0.0f;
        dst[6] = 0.0f;
        dst[7] = 0.0f;
        value = iGpffff8218;
        dst[8] = value;
        dst[9] = value;
        dst[10] = value;
        dst[11] = 0.0f;
        *firstValue = 7.0f;
        *secondValue = 0.0f;
    }
    goto done;
have_start:
    if (end == NULL) {
        goto no_end;
    }
    matrix1 = (f32 *)((EvtChildNode *)end)->ownedBlock48;
    endFirst = ((EvtMatrixPayload *)&((EvtChildNode *)end)->payload)->first;
    endSecond = ((EvtMatrixPayload *)&((EvtChildNode *)end)->payload)->second;
    goto have_end;

no_end:
    for (i = 0; i < 4; i++) {
        src = matrix0 + i;
        out = dst + i;
        out[0] = src[0];
        out[4] = src[4];
        out[8] = src[8];
    }
    *firstValue = value0;
    *secondValue = value1;
    goto done;

have_end:
    if (matrix0 != NULL) {
        goto have_matrix;
    }
    if (matrix1 != NULL) {
        goto have_matrix;
    }
    {
        f32 value;

        value = iGpffff809c;
        dst[0] = value;
        dst[1] = value;
        dst[2] = value;
        dst[3] = 0.0f;
        dst[4] = 0.0f;
        dst[5] = 0.0f;
        dst[6] = 0.0f;
        dst[7] = 0.0f;
        value = iGpffff8218;
        dst[8] = value;
        dst[9] = value;
        dst[10] = value;
        dst[11] = 0.0f;
        *firstValue = 7.0f;
        *secondValue = 0.0f;
    }
    goto done;

have_matrix:
    if (count == 0) {
        for (i = 0; i < 4; i++) {
            src = matrix0 + i;
            out = dst + i;
            out[0] = src[0];
            out[4] = src[4];
            out[8] = src[8];
        }
        *firstValue = value0;
        *secondValue = value1;
    } else {
        evtPolygonMovieLerpPose(count, ratio, matrix0, matrix1, dst);
        *firstValue = evtLerpFloatIfEnabled(count, ratio, value0, endFirst);
        *secondValue = evtLerpFloatIfEnabled(count, ratio, value1, endSecond);
    }

done:
    return;
}

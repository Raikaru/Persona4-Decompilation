/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0028bfb0-0028c080 */

#include "field_transition_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "scene_light_override_internal.h"
#include "evt_internal.h"
extern f32 evtLerpFloatIfEnabled(s32 arg0, f32 arg1, f32 arg2, f32 arg3);
extern void evtPolygonMovieLerpPose(s32 arg0, f32 arg1, f32 *arg2, f32 *arg3,
                          f32 *arg4);
s32 evtCheckCondition(u8 *arg0);
static inline s32 func_0028_sum(u16 arg0, s16 arg1) {
    return (s32)arg0 + arg1;
}

#pragma push
#pragma opt_loop_invariants on
// Finds the node range for a key: walks the event node list and reports the first and last matching nodes [inferred].
// FUN_0028BFB0
void evtFindNodeRange(u8 *arg0, s32 arg1, u8 **arg2, u8 **arg3) {
    u8 *temp_3;
    s16 temp_8;
    s32 temp_6;

    *arg2 = NULL;
    *arg3 = NULL;
    if (arg0 == NULL) {
        goto done;
    }
    temp_8 = *(s16 *)(arg0 + 0x1C);
    *arg3 = *(u8 **)(arg0 + 0x68);
    goto loop_4_test;
loop_4_body:
    temp_6 = func_0028_sum(*(u16 *)temp_3, temp_8);
    if (temp_6 > arg1) {
        goto block_8;
    }
    *arg3 = *(u8 **)(temp_3 + 0x4C);
loop_4_test:
    temp_3 = *arg3;
    if (temp_3 != NULL) {
        goto loop_4_body;
    }
block_8:
    if (temp_3 != NULL) {
        *arg2 = *(u8 **)(temp_3 + 0x50);
        goto loop_10_test;
    }
    *arg2 = *(u8 **)(arg0 + 0x6C);
    goto loop_10_test;
loop_10_body:
    if (evtCheckCondition(*arg2) == 1) {
        goto done;
    }
    *arg2 = *(u8 **)(*arg2 + 0x50);
loop_10_test:
    if (*arg2 != NULL) {
        goto loop_10_body;
    }
done:
    return;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
// Interpolates two matrix pairs between their start and end times, by the ratio of elapsed time [inferred].
// FUN_0028C080
void evtInterpolateNodeMatrices(u8 *arg0, u8 *arg1, s32 arg2, u8 *arg3, f32 *arg4,
                   f32 *arg5) {
    u8 *start;
    u8 *end;
    f32 value0;
    f32 end_value0;
    f32 value1;
    f32 end_value1;
    f32 ratio;
    s32 start_time;
    s32 end_time;
    s32 count;
    f32 *matrix0;
    f32 *matrix1;
    f32 *dst;
    f32 *src;
    f32 *out;
    s32 i;

    evtFindNodeRange(arg1, arg2, &start, &end);
    if (start != NULL) {
        start_time = *(u16 *)start;
    } else {
        start_time = *(s32 *)(arg0 + 0xC);
    }
    if (end != NULL) {
        end_time = *(u16 *)end;
    } else {
        end_time = *(s32 *)(arg0 + 0x10);
    }
    if (end_time - start_time != 0) {
        ratio = (f32)(arg2 - start_time) / (f32)(end_time - start_time);
    } else {
        ratio = 0.0f;
    }
    dst = (f32 *)arg3;
    if (start == NULL) {
        goto no_start;
    }
    matrix0 = *(f32 **)(start + 0x48);
    value0 = *(f32 *)(start + 0x10);
    value1 = *(f32 *)(start + 0x14);
    count = *(s32 *)(start + 4);
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
        *arg4 = 7.0f;
        *arg5 = 0.0f;
    }
    goto done;
have_start:
    if (end == NULL) {
        goto no_end;
    }
    matrix1 = *(f32 **)(end + 0x48);
    end_value0 = *(f32 *)(end + 0x10);
    end_value1 = *(f32 *)(end + 0x14);
    goto have_end;

no_end:
    for (i = 0; i < 4; i++) {
        src = matrix0 + i;
        out = dst + i;
        out[0] = src[0];
        out[4] = src[4];
        out[8] = src[8];
    }
    *arg4 = value0;
    *arg5 = value1;
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
        *arg4 = 7.0f;
        *arg5 = 0.0f;
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
        *arg4 = value0;
        *arg5 = value1;
    } else {
        evtPolygonMovieLerpPose(count, ratio, matrix0, matrix1, dst);
        *arg4 = evtLerpFloatIfEnabled(count, ratio, value0, end_value0);
        *arg5 = evtLerpFloatIfEnabled(count, ratio, value1, end_value1);
    }

done:
    return;
}
#pragma pop

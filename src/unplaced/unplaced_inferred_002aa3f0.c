/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 002aa3f0-002aabf0 */

/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
extern void (*jtbl_008873EC[])(void *);
s32 kwlnTaskGetTaskByName(void *arg0);
extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];
extern void memset(void *dst, s32 value, u32 size);
extern s32 loadingSpinnerTaskUpdate(u8 *arg0);
extern void loadingSpinnerDraw(void);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_003f6690(s32 arg0, s32 *arg1);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern void PrimDrawFlatRectangle(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *arg0, void *arg1);
extern u8 D_007966A0[];
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;

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

extern void sflDataDrawQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s32 centerX, s16 centerY,
                          const struct RwMatrixTag *matrix, void *queue);
extern void RwMatrixRotate(void *arg0, void *arg1, f32 farg0, s32 arg2);
extern void RwMatrixScale(void *arg0, void *arg1, s32 arg2);
extern void func_003e4320(void *arg0, void *arg1, void *arg2);
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
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// FUN_002AA3F0
s32 mcIconTaskPoll(void) {
    s32 r;

    if (kwlnTaskGetTaskByName(&D_00763918) == 0) {
        r = (D_00764634 != 0) ? 1 : 2;
    } else {
        r = 0;
    }
    return r;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Draw the rotating three-colour loading spinner for one frame [inferred]
// FUN_002AA450
void loadingSpinnerDraw(void) {
    s64 bits;
    s32 *state;
    u8 *source;
    P4_002aa450_Work work;
    f32 phase;
    f32 offset;
    f32 ratio;
    f32 angle;
    f32 value;
    f32 scale;
    f32 color_x;
    f32 color_y;
    s32 color_value;
    s32 temp;

    state = (s32 *)D_00882F20;
    bits = *(s64 *)D_0063EDF0;
    value = *(f32 *)D_0063EDF8;
    work.pair0.bits = bits;
    work.pair0.value = value;
    bits = *(s64 *)D_0063EE00;
    value = *(f32 *)D_0063EE08;
    work.pair1.bits = bits;
    work.pair1.value = value;
    bits = *(s64 *)D_0063EE10;
    value = *(f32 *)D_0063EE18;
    work.pair2.bits = bits;
    work.pair2.value = value;
    bits = *(s64 *)D_0063EE20;
    value = *(f32 *)D_0063EE28;
    work.pair3.bits = bits;
    work.pair3.value = value;
    source = D_0063EE30;
    bits = *(s64 *)source;
    source = D_0063EE38;
    value = *(f32 *)source;
    work.pair4.bits = bits;
    work.pair4.value = value;
    ratio = (f32)(*(s32 *)D_00882F2C) / 5.0f;
    bits = *(s32 *)D_00882F28;
    temp = (s32)bits + 1;
    *(s32 *)D_00882F28 = temp;
    if (temp >= 0x3C) {
        state[2] = 0;
    }
    phase = (f32)state[2] / 60.0f;
    scale = 10.0f;
    offset = 1.0f - ratio;
    offset = p4_002aa450_mul(scale, offset);
    offset = -80.0f - offset;
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    func_003e4320(&work.pair3, &work.pair3, work.matrix);
    angle = 360.0f * phase;
    RwMatrixRotate(work.matrix, &work.pair3, angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    color_x = (f32)0x1A3;
    color_y = (f32)0x242;
    color_value = 397;
    sflDataDrawQuad((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    RwMatrixRotate(work.matrix, &work.pair3, 120.0f + angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    sflDataDrawQuad((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFFFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    RwMatrixRotate(work.matrix, &work.pair3, 240.0f + angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    sflDataDrawQuad((s32)color_y, (s32)color_x, 0.0f, 0x18, 0x1F, 0xFF0000, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair1, fGpffff855c, 0);
    RwMatrixRotate(work.matrix, &work.pair2, 357.0f * phase + 3.0f, 2);
    ((f32 *)&work.pair4)[0] *= ratio;
    ((f32 *)&work.pair4)[1] *= ratio;
    ((f32 *)&work.pair4)[2] *= ratio;
    RwMatrixScale(work.matrix, &work.pair4, 2);
    sflDataDrawQuad((s32)color_y, (s32)(color_value - ratio * 2.0f), 0.0f, 0x22, 0x2C,
                  0xE6E6E6, 0xFF, 1, 0x11, 0x16,
                  (const struct RwMatrixTag *)work.matrix, 0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Loading spinner task update: run its show/hide state machine and queue its draw [inferred]
// FUN_002AA890
s32 loadingSpinnerTaskUpdate(u8 *arg0) {
    s32 *state;
    u8 *temp_2;

    state = D_00882F20;
    switch (state[1]) {
    case 0:
        state[1] = 1;
    case 1:
        if ((state[0] & 1) != 0) {
            state[1] = 3;
        }
        break;
    case 3:
        state[1] = 4;
        state[2] = 0;
        state[0] |= 2;
    case 4:
        if ((state[0] & 1) == 0) {
            state[0] |= 4;
        }
        if ((state[0] & 2) != 0) {
            if (state[3] < 5) {
                state[3]++;
            } else {
                state[0] &= ~2;
            }
        } else if ((state[0] & 4) != 0) {
            if (state[3] > 0) {
                state[3]--;
            } else {
                state[0] &= ~4;
                state[1] = 1;
            }
        }
        temp_2 = PrimAllocQueueNode();
        *(void **)(temp_2 + 8) = (void *)loadingSpinnerDraw;
        *(u8 **)(temp_2 + 0x10) = arg0;
        PrimAppendNode(D_007966A0, temp_2);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// FUN_002AAA00
void func_002aaa00(u8 *unusedTask)
{
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Create the loading spinner task and clear its state block [inferred]
// FUN_002AAA10
void loadingSpinnerTaskCreate(void) {
    memset(D_00882F20, 0, 0x10);
    (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_0063EE40), 0xF, 0, 0, loadingSpinnerTaskUpdate, func_002aaa00, (u8 *)(NULL));
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Request the loading spinner to show (sets bit 0 of its state) [inferred]
// FUN_002AAA80
void loadingSpinnerRequestShow(void) {
    D_00882F20[0] |= 1;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Request the loading spinner to hide (clears bit 0 of its state) [inferred]
// FUN_002AAAA0
void loadingSpinnerRequestHide(void) {
    D_00882F20[0] &= ~1;
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Apply the shared title sky base render preset; callers set the pass-specific sky state after it [inferred]
// FUN_002AAAC0
void titleSkyApplyBasePreset(void) {
    void (**base)(s32 arg0, s32 arg1);

    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Title visual draw callback: read a 0x1C packet (rect, depth, colour, flags) and draw a flat rectangle [inferred]
// FUN_002AABF0
void titleVisualDraw(void *arg0, u8 *arg1) {
    P4_002aabf0_Work work;
    u8 *ptr;
    void (**base)(s32 arg0, s32 arg1);
    f32 temp_f20;
    s32 temp_16;
    s32 temp_17;
    s32 temp_17_2;
    s32 temp_18;
    s32 temp_19;
    u8 temp_6;
    u8 temp_7;
    u8 temp_8;
    u8 temp_9;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;
    f32 temp_f3;

    ptr = arg1;
    temp_6 = ptr[0x14];
    temp_7 = ptr[0x15];
    temp_8 = ptr[0x16];
    temp_9 = ptr[0x17];
    work.colors[0] = temp_6;
    work.colors[1] = temp_7;
    work.colors[2] = temp_8;
    work.colors[3] = temp_9;
    temp_f3 = *(f32 *)(ptr + 0);
    temp_f2 = *(f32 *)(ptr + 4);
    temp_f1 = *(f32 *)(ptr + 8);
    temp_f0 = *(f32 *)(ptr + 0xC);
    work.values[0] = temp_f3;
    work.values[1] = temp_f2;
    work.values[2] = temp_f1;
    work.values[3] = temp_f0;
    temp_f20 = *(f32 *)(ptr + 0x10);
    temp_19 = *(s32 *)(ptr + 0x18);
    temp_18 = temp_19 & 0x100;
    if (temp_18 != 0) {
        func_003f6690(3, &work.sp88);
    }
    temp_17 = temp_19 & 0x200;
    if (temp_17 != 0) {
        func_003f6690(2, &work.sp84);
    }
    if (temp_18 != 0) {
        func_003f6690(3, &work.sp88);
    }
    base = D_00887300;
    base[0](0xA, 5);
    base[0](0xB, 6);
    base[0](0xE, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 4);
    base[0](0x14, 1);
    base[0](6, 0);
    base[0](8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
    if (temp_18 != 0) {
        RpSkyRenderStateSet(3, work.sp88);
    }
    if (temp_17 != 0) {
        RpSkyRenderStateSet(2, work.sp84);
    }
    if (temp_19 & 1) {
        base[0](6, 1);
    }
    if (temp_19 & 2) {
        base[0](8, 1);
    }
    if (temp_19 & 4) {
        RpSkyRenderStateSet(3, 0x5000D);
    }
    if (temp_19 & 8) {
        RpSkyRenderStateSet(2, 0x54);
    }
    if (temp_19 & 0x20) {
        RpSkyRenderStateSet(2, 0x58);
    }
    temp_17_2 = temp_19 & 0x40;
    if (temp_17_2 != 0) {
        shdEnableBlendFlag();
    }
    temp_16 = temp_19 & 0x10;
    if (temp_16 != 0) {
        mdlEffectEmitMaskedTagPair();
    }
    PrimDrawFlatRectangle(work.colors, work.values, temp_f20, 0);
    if (temp_16 != 0) {
        mdlEffectEmitTagPair();
    }
    if (temp_17_2 != 0) {
        shdDisableBlendFlag();
    }
    jtbl_008873EC[0](ptr);
}
#pragma pop

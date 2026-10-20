
/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_loop_invariants off

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "operand_order_internal.h"
#include "primitive_queue_internal.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
typedef struct TitleVisualPacket {
    f32 x, y, width, height, depth;
    u8 red, green, blue, alpha;
    s32 flags;
} TitleVisualPacket;

extern void (*jtbl_008873EC[])(void *);
s32 kwlnTaskGetTaskByName(void *);
extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];
extern void memset(void *dst, s32 value, u32 size);
extern s32 loadingSpinnerTaskUpdate(u8 *);
extern void loadingSpinnerDraw(void);
extern void (*D_00887300[])(s32 , s32 );
extern void RpSkyRenderStateSet(s32 , s32 );
extern void RpSkyRenderStateGet(s32 , s32 *);
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
extern void PrimDrawFlatRectangle(u8 *, f32 *, f32 , s32 );
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *, void *);
extern u8 D_007966A0[];
typedef struct TitleVisualDrawState {
    f32 values[4];
    s32 pad80;
    s32 savedStateTwo;
    s32 savedStateThree;
    u8 colors[4];
} TitleVisualDrawState;

typedef struct LoadingSpinnerVector {
    s64 bits;
    f32 value;
} LoadingSpinnerVector;

typedef struct LoadingSpinnerDrawState {
    u8 matrix[0x40];
    LoadingSpinnerVector pair4;
    LoadingSpinnerVector pair3;
    LoadingSpinnerVector pair2;
    LoadingSpinnerVector pair1;
    LoadingSpinnerVector pair0;
} LoadingSpinnerDrawState;

struct RwMatrixTag;

extern void sflDataDrawQuad(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
                          s32 alpha, s32 mode, s32 centerX, s16 centerY,
                          const struct RwMatrixTag *matrix, void *queue);
extern void RwMatrixRotate(void *, void *, f32 , s32 );
extern void RwMatrixScale(void *, void *, s32 );
extern void func_003e4320(void *, void *, void *);
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
#pragma no_branch_likely off
/* Return zero while the memory-card icon task exists; otherwise distinguish pending and completed status. */
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
#pragma no_branch_likely off
// Draws the rotating three-colour loading spinner for one frame.
// FUN_002AA450
void loadingSpinnerDraw(void) {
    s64 bits;
    s32 *state;
    u8 *source;
    LoadingSpinnerDrawState work;
    f32 phase;
    f32 offset;
    f32 ratio;
    f32 angle;
    f32 value;
    f32 scale;
    f32 drawY;
    f32 drawX;
    s32 backdropY;
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
    offset = operandOrderMultiply(scale, offset);
    offset = -80.0f - offset;
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    func_003e4320(&work.pair3, &work.pair3, work.matrix);
    angle = 360.0f * phase;
    RwMatrixRotate(work.matrix, &work.pair3, angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    drawY = (f32)0x1A3;
    drawX = (f32)0x242;
    backdropY = 397;
    sflDataDrawQuad((s32)drawX, (s32)drawY, 0.0f, 0x18, 0x1F, 0xFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    RwMatrixRotate(work.matrix, &work.pair3, 120.0f + angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    sflDataDrawQuad((s32)drawX, (s32)drawY, 0.0f, 0x18, 0x1F, 0xFFFF00, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair0, offset, 0);
    RwMatrixRotate(work.matrix, &work.pair3, 240.0f + angle, 2);
    RwMatrixScale(work.matrix, &work.pair4, 2);
    sflDataDrawQuad((s32)drawX, (s32)drawY, 0.0f, 0x18, 0x1F, 0xFF0000, 0xFF, 1, 0,
                  0, (const struct RwMatrixTag *)work.matrix, 0);
    RwMatrixRotate(work.matrix, &work.pair1, fGpffff855c, 0);
    RwMatrixRotate(work.matrix, &work.pair2, 357.0f * phase + 3.0f, 2);
    ((f32 *)&work.pair4)[0] *= ratio;
    ((f32 *)&work.pair4)[1] *= ratio;
    ((f32 *)&work.pair4)[2] *= ratio;
    RwMatrixScale(work.matrix, &work.pair4, 2);
    sflDataDrawQuad((s32)drawX, (s32)(backdropY - ratio * 2.0f), 0.0f, 0x22, 0x2C,
                  0xE6E6E6, 0xFF, 1, 0x11, 0x16,
                  (const struct RwMatrixTag *)work.matrix, 0);
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Loading spinner task update: runs its show/hide state machine and queues its draw.
// FUN_002AA890
s32 loadingSpinnerTaskUpdate(u8 *task) {
    s32 *state;
    u8 *node;

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
        node = PrimAllocQueueNode();
        ((PrimQueueNode *)node)->callback = (void *)loadingSpinnerDraw;
        ((PrimQueueNode *)node)->argument.data = task;
        PrimAppendNode(D_007966A0, node);
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// FUN_002AAA00
void loadingSpinnerTaskDestroy(u8 *unusedTask)
{
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Create the loading spinner task and clear its state block.
// FUN_002AAA10
void loadingSpinnerTaskCreate(void) {
    memset(D_00882F20, 0, 0x10);
    (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_0063EE40), 0xF, 0, 0, loadingSpinnerTaskUpdate, loadingSpinnerTaskDestroy, (u8 *)(NULL));
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Request the loading spinner to show by setting bit 0 of its state.
// FUN_002AAA80
void loadingSpinnerRequestShow(void) {
    D_00882F20[0] |= 1;
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Request the loading spinner to hide by clearing bit 0 of its state.
// FUN_002AAAA0
void loadingSpinnerRequestHide(void) {
    D_00882F20[0] &= ~1;
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Apply the shared title sky base render preset; callers set the pass-specific sky state after it.
// FUN_002AAAC0
void titleSkyApplyBasePreset(void) {
    void (*(*base)[1])(s32, s32);

    base = (void (*(*)[1])(s32, s32))D_00887300;
    (*base)[0](0xA, 5);
    (*base)[0](0xB, 6);
    (*base)[0](0xE, 0);
    (*base)[0](0xC, 1);
    (*base)[0](7, 2);
    (*base)[0](9, 2);
    (*base)[0](2, 4);
    (*base)[0](0x14, 1);
    (*base)[0](6, 0);
    (*base)[0](8, 0);
    RpSkyRenderStateSet(3, 0x50003);
    RpSkyRenderStateSet(2, 0x44);
    (*base)[0](1, 0);
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Title visual draw callback: reads a packet (rect, depth, colour, flags) and draws a flat
// rectangle.
#pragma opt_propagation off
/* measured: retail keeps the packet values in registers instead of propagating copies, so
 * propagation stays off. */
// FUN_002AABF0
void titleVisualDraw(void *unusedQueue, u8 *packet) {
    TitleVisualDrawState work;
    u8 *ptr;
    void (**base)(s32 unusedQueue, s32 packet);
    f32 depth;
    s32 maskedDraw;
    s32 preserveStateTwo;
    s32 blendFlag;
    s32 preserveStateThree;
    s32 flags;
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
    f32 height;
    f32 width;
    f32 y;
    f32 x;

    ptr = packet;
    red = ((TitleVisualPacket *)ptr)->red;
    green = ((TitleVisualPacket *)ptr)->green;
    blue = ((TitleVisualPacket *)ptr)->blue;
    alpha = ((TitleVisualPacket *)ptr)->alpha;
    work.colors[0] = red;
    work.colors[1] = green;
    work.colors[2] = blue;
    work.colors[3] = alpha;
    x = ((TitleVisualPacket *)ptr)->x;
    y = ((TitleVisualPacket *)ptr)->y;
    width = ((TitleVisualPacket *)ptr)->width;
    height = ((TitleVisualPacket *)ptr)->height;
    work.values[0] = x;
    work.values[1] = y;
    work.values[2] = width;
    work.values[3] = height;
    depth = ((TitleVisualPacket *)ptr)->depth;
    flags = ((TitleVisualPacket *)ptr)->flags;
    preserveStateThree = flags & 0x100;
    if (preserveStateThree != 0) {
        RpSkyRenderStateGet(3, &work.savedStateThree);
    }
    preserveStateTwo = flags & 0x200;
    if (preserveStateTwo != 0) {
        RpSkyRenderStateGet(2, &work.savedStateTwo);
    }
    if (preserveStateThree != 0) {
        RpSkyRenderStateGet(3, &work.savedStateThree);
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
    if (preserveStateThree != 0) {
        RpSkyRenderStateSet(3, work.savedStateThree);
    }
    if (preserveStateTwo != 0) {
        RpSkyRenderStateSet(2, work.savedStateTwo);
    }
    if (flags & 1) {
        base[0](6, 1);
    }
    if (flags & 2) {
        base[0](8, 1);
    }
    if (flags & 4) {
        RpSkyRenderStateSet(3, 0x5000D);
    }
    if (flags & 8) {
        RpSkyRenderStateSet(2, 0x54);
    }
    if (flags & 0x20) {
        RpSkyRenderStateSet(2, 0x58);
    }
    blendFlag = flags & 0x40;
    if (blendFlag != 0) {
        shdEnableBlendFlag();
    }
    maskedDraw = flags & 0x10;
    if (maskedDraw != 0) {
        mdlEffectEmitMaskedTagPair();
    }
    PrimDrawFlatRectangle(work.colors, work.values, depth, 0);
    if (maskedDraw != 0) {
        mdlEffectEmitTagPair();
    }
    if (blendFlag != 0) {
        shdDisableBlendFlag();
    }
    jtbl_008873EC[0](ptr);
}
#pragma pop

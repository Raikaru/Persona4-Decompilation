/* Source unit: src/promoted/code1_002a.c */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

s32 kwlnTaskGetTaskByName(void *arg0);
extern u8 D_0063E918[];
void kwlnTaskDestroyWithHierarchy(s32 arg0);

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];
extern void memset(void *dst, s32 value, u32 size);

extern s32 loadingSpinnerTaskUpdate(u8 *arg0);
extern void loadingSpinnerDraw(void);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern s32 seqYajiTaskUpdate(u8 *arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void func_003f6690(s32 arg0, s32 *arg1);
extern void func_00364c50(void);
extern void func_00364c70(void);
extern void PrimDrawFlatRectangle(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
extern void mdlEffectEmitMaskedTagPair(void);
extern void mdlEffectEmitTagPair(void);
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern u8 *PrimAllocQueueNode(void);
extern void func_00460ac0(void *arg0, void *arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern void func_002a1ef0(u8 *arg0);
extern f32 fGpffff8204;
extern u8 func_002a2780(s32 arg0);
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern void func_002a2980(u8 *arg0);
extern s32 func_002a2c70(u8 *arg0);
extern void func_0029fbb0(u8 *arg0, s32 arg1);
extern s32 func_002a2ca0(u8 *arg0);
extern f32 func_002a2cd0(u8 *arg0);
extern s32 func_002a2c10(u8 *arg0, f32 *arg1);
extern void sdkSpriteDrawNowUnscaled(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4);
extern s32 sdkSpriteDrawNow(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, void * arg3, s32 arg4, s16 arg5, s16 arg6, f32 farg3, f32 farg4, f32 farg5);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
extern u8 nmMesWindowOpenCurrent(u8 *message);
extern void nmMesWindowShowCurrentRecord(s32 arg0);
extern void nmMesWindowSetCurrentParam(s32 arg0);
extern void nmMesWindowSetCurrentFlag(s32 arg0);
extern s32 nmMesWindowCurrentAnim(void);
extern void nmMesWindowResetCurrent(void);
extern s32 nmMesWindowCurrentOpenState(void);
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 nmMesWindowLatchAnimAux(void);
extern void nmMesWindowStepCurrentRelease(void);
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;

extern s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 fclSubClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002bdb50(s32 arg0, s8 arg1);
extern void func_002bdea0(void);
extern s32 func_002e7510(s32 arg0);
extern void fclCombineApplyPackedResult(void);
extern s32 func_003493b0(u8 *arg0);
extern s32 kwlnTaskIsLinked(s32 arg0);
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
typedef signed __int128 s128;
extern s32 (*D_0063E8C0[])(u8 *, s32);
extern s128 D_0063E8D0;
extern u8 D_00882ED0[];
extern u8 D_00882EF0[];
extern u8 *iGpffffb540;
extern u8 iGpffffa7e8;
extern void func_0010d490(u8 *arg0, u8 *arg1);
extern void func_00122520(s32 arg0, s32 arg1);
extern void func_00122640(s32 arg0, s32 arg1);
extern void func_0029ebf0(u8 *arg0, s32 arg1);
extern void func_0029f070(u8 *arg0);
extern void func_002a12e0(u8 *arg0, s32 arg1);
extern s32 strncmp(void *arg0, void *arg1, s32 arg2);



extern void func_002a03b0(u8 *arg0);
typedef struct NameTweenEntry {
    f32 startX, startY, endX, endY, stepX, stepY, rate;
    s8 delay, hold;
    s16 duration;
} NameTweenEntry;
typedef struct NameTweenState {
    NameTweenEntry entries[4];
    s32 current, count, frame;
    u32 flags;
    s32 timer, total;
} NameTweenState;
/* Existing task-work layout. The tween fields are defined by 002a27c0;
 * 0029fbb0 uses the selection pairs, status halfwords and flash flags.
 * State preceding the background tween is outside this renderer's view. */
typedef struct NameEntrySelectionTweens {
    NameTweenState slide, pulse;
} NameEntrySelectionTweens;
typedef struct NameEntryRenderWork {
    /* 0x0000 */ u8 stateBeforeBackground[0x178];
    /* 0x0178 */ NameTweenState background;
    /* 0x0210 */ NameTweenState rowOrigin;
    /* 0x02a8 */ NameTweenState modeTransition;
    /* 0x0340 */ NameTweenState cells[24];
    /* 0x1180 */ NameTweenState rows[6];
    /* 0x1510 */ NameEntrySelectionTweens selection[6];
    /* 0x1c30 */ s32 selectionState[2];
    /* 0x1c38 */ s16 selectionStatus[6][2];
    /* 0x1c50 */ s32 selectionFlash[6];
    /* 0x1c68 */ s32 backgroundFrame;
} NameEntryRenderWork;
typedef char NameTweenEntrySize[(sizeof(NameTweenEntry) == 0x20) ? 1 : -1];
typedef char NameTweenStateSize[(sizeof(NameTweenState) == 0x98) ? 1 : -1];
typedef char NameEntryWorkSize[(sizeof(NameEntryRenderWork) == 0x1c6c) ? 1 : -1];
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on

extern s32 func_002a1a10(u8 *arg0);
#pragma pop
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_common_subs off
#pragma opt_propagation off
extern s32 func_002a1c80(u8 *arg0);
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma no_branch_likely on
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma no_branch_likely off
#pragma opt_loop_invariants on
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
        func_00460ac0(D_007966A0, temp_2);
        break;
    }
    return 0;
}
// FUN_002AAA00
void func_002aaa00(u8 *unusedTask)
{
}

// Intent: Create the loading spinner task and clear its state block [inferred]
// FUN_002AAA10
void loadingSpinnerTaskCreate(void) {
    memset(D_00882F20, 0, 0x10);
    (s32)kwlnTaskCreateChild((void *)(NULL), (const void *)(D_0063EE40), 0xF, 0, 0, loadingSpinnerTaskUpdate, func_002aaa00, (u8 *)(NULL));
}

// Intent: Request the loading spinner to show (sets bit 0 of its state) [inferred]
// FUN_002AAA80
void loadingSpinnerRequestShow(void) {
    D_00882F20[0] |= 1;
}
// Intent: Request the loading spinner to hide (clears bit 0 of its state) [inferred]
// FUN_002AAAA0
void loadingSpinnerRequestHide(void) {
    D_00882F20[0] &= ~1;
}


/* measured: opt_propagation off keeps the D_00887300 base in $s0 and
   reloads the dispatch target before each call, as in retail. */
#pragma opt_propagation off
// FUN_002AAAC0
void func_002aaac0(void) {
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
/* measured: closes the opt_propagation bracket for func_002aaac0. */
#pragma opt_propagation on
/* measured: opt_propagation off preserves the cached dispatch base and retail call-site order. */
#pragma opt_propagation off
// FUN_002AABF0
void func_002aabf0(void *arg0, u8 *arg1) {
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
        func_00364c50();
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
        func_00364c70();
    }
    jtbl_008873EC[0](ptr);
}
/* measured: closes opt_propagation around func_002aabf0. */
#pragma opt_propagation on
// Intent: Seq task update: advance the sequence work each step [inferred]
// FUN_002ABF70
s32 seqYajiTaskUpdate(u8 *arg0) {
    s32 temp_3;
    s8 temp_4;
    u8 *temp_16;
    void *temp_17;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f2;

    temp_16 = *(u8 **)(arg0 + 0x38);
    temp_4 = *(s8 *)(temp_16 + 0);
    switch (temp_4) {
    case 0:
    case 1:
    case 2:
    case 3:
        *(s8 *)(temp_16 + 0) = temp_4 + 1;
        break;
    case 4:
        temp_f0 = 100.0f;
        temp_f1 = 156.0f;
        temp_f2 = 1.0f;
        temp_17 = (void *)*(s32 *)(D_0063EEA0 +
                                   (*(s32 *)(temp_16 + 0x6C0) * 4));
        frFontExDrawText(temp_f0, temp_f1, temp_f2,
                      -1, 0, 0, temp_17, 0, 0);
        if (D_008C027A[0] & 0x8000) {
            *(s32 *)(temp_16 + 0x6C0) =
                fclAddClamped(*(s32 *)(temp_16 + 0x6C0), 1, 3, 0, 1);
        } else if (D_008C027A[0] & 0x2000) {
            *(s32 *)(temp_16 + 0x6C0) =
                fclSubClamped(*(s32 *)(temp_16 + 0x6C0), 1, 0, 3, 1);
        } else if (D_008C024E[0] & 0x40) {
            if (*(s32 *)(temp_16 + 0x6C8) != 0) {
                *(s32 *)(temp_16 + 0x6C8) = 0;
            }
            temp_3 = *(s32 *)(temp_16 + 0x6C0);
            switch (temp_3) {
            case 0:
                *(s32 *)(temp_16 + 0x6C8) = func_002bdb50((s32)arg0, 0);
                break;
            case 1:
                *(s32 *)(temp_16 + 0x6C8) = func_002e7510((s32)arg0);
                break;
            case 2:
                iGpffffb54c = 0;
                *(s32 *)(temp_16 + 0x6C8) = fclCombineTaskCreate(arg0);
                break;
            case 3:
                *(s32 *)(temp_16 + 0x6C8) = func_003493b0(arg0);
                break;
            }
            *(s8 *)(temp_16 + 0) = *(s8 *)(temp_16 + 0) + 1;
        } else if (D_008C024E[0] & 0x10) {
            if (*(s32 *)(temp_16 + 0x6C8) != 0) {
                *(s32 *)(temp_16 + 0x6C8) = 0;
            }
            switch (*(s32 *)(temp_16 + 0x6C0)) {
            case 2:
                iGpffffb54c = 1;
                *(s32 *)(temp_16 + 0x6C8) = fclCombineTaskCreate(arg0);
                break;
            default:
                break;
            }
            *(s8 *)(temp_16 + 0) = *(s8 *)(temp_16 + 0) + 1;
        } else if (D_008C024E[0] & 0x80) {
            sdkSndStartStream(0, 0, 0, 0xA);
        }
        break;
    case 5:
        if (iGpffffb54c == 1) {
            temp_f0 = 20.0f;
            temp_f2 = 1.0f;
            temp_f1 = temp_f0;
            frFontExDrawText(temp_f0, temp_f1, temp_f2,
                          (s32)0x808080FF, 0, 2,
                          (void *)D_0063EEB0, 0, 0);
        }
        if (kwlnTaskIsLinked(*(s32 *)(temp_16 + 0x6C8)) == 0) {
            *(s8 *)(temp_16 + 0) = 0;
            func_002bdea0();
            fclCombineApplyPackedResult();
        }
        break;
    case 6:
        break;
    default:
        break;
    }
    return 0;
}
// Intent: Seq task destroy: dispatch the seq task's teardown handler [inferred]
// FUN_002AC270
void seqYajiTaskDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

// Intent: Create the seq task and initialise its work block [inferred]
// FUN_002AC2A0
void seqYajiTaskCreate(void) {
    u8 *p;

    chkmemAllocSiteTag(D_0063EEC0, 0x4B9);
    p = D_008873F4[0](1, 0x4D78, 0x40000);
    (s32)kwlnTaskCreate((const void *)(D_0063EED0), 0xF, 0, 0, seqYajiTaskUpdate, seqYajiTaskDestroy, (u8 *)(p));
    *(u8 *)(p + 0) = 0;
    *(s32 *)(p + 0x6B4) = 0x3F800000;
    *(s16 *)(p + 0x6B8) = 0x1F;
    *(s16 *)(p + 0x6BA) = 0;
    *(s8 *)(p + 0x6BC) = 1;
    *(s8 *)(p + 0x6BD) = 1;
    *(s32 *)(p + 0x6C0) = 0;
}
// Intent: Clear the SMAP reveal bitmap (24 halfwords) [inferred]
// FUN_002AC360
void smapClearRevealTable(void) {
    s16 i;

    i = 0;
    while (i < 0x18) {
        D_00764658[i] = 0;
        i++;
    }
}
// Intent: Return a pointer to the SMAP reveal bitmap [inferred]
// FUN_002AC3B0
u32 smapRevealTablePtr(void) {
    return (u32)D_00764658;
}
// Intent: Test one SMAP reveal bit: bit index arg0 in row arg1 [inferred]
// FUN_002AC3C0
s64 smapRevealTestBit(s32 arg0, s32 arg1) {
    s32 temp;

    temp = arg0 & 0xff;
    return (s8)(((1 << temp) & 0xffff & D_00764658[arg1 & 0xff]) >> temp);
}

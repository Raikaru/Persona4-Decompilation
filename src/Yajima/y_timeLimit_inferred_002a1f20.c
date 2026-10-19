#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"

extern void (*jtbl_008873EC[])(void *);
extern u16 *D_00764658;

extern u8 D_0063E918[];

extern s32 D_00882F20[];
extern s32 D_00763918;
extern s32 D_00764634;
extern u8 D_0063EE40[];

extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void (*D_00887300[])(s32 arg0, s32 arg1);
extern void PrimDrawFlatRectangle(u8 *arg0, f32 *arg1, f32 arg2, s32 arg3);
extern u8 *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *arg0, void *arg1);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
extern void yTimeLimitDrawCallback(u8 *arg0);
extern f32 fGpffff8204;
extern u32 func_002a27c0(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                         s32 arg4, f32 farg0, s32 arg5, s32 arg6, s32 arg7);
extern u8 D_007485D0[];
extern s32 iGpffffb530;
typedef struct P4_002aabf0_Work {
    f32 values[4];
    s32 pad80;
    s32 sp84;
    s32 sp88;
    u8 colors[4];
} P4_002aabf0_Work;
extern s32 iGpffffb52c;
extern u8 D_0063E630[];
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;

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
extern void datSetHeroNameParts(u8 *arg0, u8 *arg1);
extern void fadeBeginTransition(s32 arg0, s32 arg1);
extern void fadeBeginReturnTransition(s32 arg0, s32 arg1);
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

extern s32 func_002a1a10(u8 *arg0);
#pragma pop
extern s32 func_002a1c80(u8 *arg0);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_002a; members 002a1f20-002a2310 */

/* measured: closes opt_propagation around func_002a1c80. */
/* measured: closes opt_common_subs around func_002a1c80. */
/* measured: closes no_branch_likely around func_002a1c80. */
// Intent: per-frame task update. Queues a draw node (yTimeLimitDrawCallback) while the track is active; returns -1 once the track is done.
// FUN_002A1F20
s32 yTimeLimitTaskUpdate(u8 *arg0) {
    u8 *temp_2;

    if (*(s32 *)(*(u8 **)(arg0 + 0x38) + 4) != 3) {
        temp_2 = PrimAllocQueueNode();
        *(void (**)(u8 *))(temp_2 + 8) = yTimeLimitDrawCallback;
        *(u8 **)(temp_2 + 0x10) = arg0;
        PrimAppendNode(D_00795E60, temp_2);
        goto success;
    }
    return -1;
success:
    return 0;
}

/* measured: opt_loop_invariants on hoists the case-zero store constant into the
   preheader, matching retail's li $v1 before the loop-entry branch. */
/* measured: func_002a1fa0 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: draws the time-limit overlay for a work item (background rectangle, then the state machine that paints each track).
// FUN_002A1FA0
s32 yTimeLimitDraw(u8 *arg0) {

    u8 colors[4];
    s128 sp40;
    f32 *sp40_ptr;
    s32 temp_2_2;
    s32 temp_2_3;
    s32 temp_2_4;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_5;
    s32 var_17;
    s32 var_17_2;
    s32 var_4;
    u8 *temp_16;

    temp_16 = *(u8 **)(arg0 + 0x38);
    sp40_ptr = (f32 *)&sp40;
    sp40 = D_0063E8D0;
    if (iGpffffb540 == 0) {
        return 0;
    }
    colors[0] = 0;
    colors[1] = 0;
    colors[2] = 0;
    colors[3] = 0xFF;
    PrimDrawFlatRectangle(colors, sp40_ptr, 0.0f, 1);
    temp_5 = *(s32 *)(temp_16 + 4);
    switch (temp_5) {
    case 0:
        fadeBeginReturnTransition(1, 1);
        var_4 = 0;
        for (; var_4 < 6; var_4++) {
            *(s16 *)(temp_16 + (var_4 * 4) + 0x1C38) = 3;
            *(s16 *)(temp_16 + (var_4 * 4) + 0x1C3A) = 0;
        }
        *(s32 *)(temp_16 + 0) = 0;
        *(s32 *)(temp_16 + 0x14) = 0;
        *(s32 *)(temp_16 + 4) = 1;
        goto block_39;
    case 1:
        temp_2_2 = *(s32 *)(temp_16 + 0xC);
        if ((temp_2_2 < 3) && (D_0063E8C0[temp_2_2](arg0, temp_5) == 1)) {
            *(s32 *)(temp_16 + 0xC) = *(s32 *)(temp_16 + 0xC) + 1;
        }
        func_002a12e0(arg0, *(s32 *)(temp_16 + 0xC));
        if (*(s32 *)(temp_16 + 0xC) >= 3) {
            *(s32 *)(temp_16 + 0xC) = 0;
            *(s32 *)(temp_16 + 8) = 0;
            *(s32 *)(temp_16 + 0x18) = 0;
            *(s32 *)(temp_16 + 0x14) = 1;
            *(s32 *)(temp_16 + 4) = 2;
            *(s32 *)(temp_16 + 0x1C34) = 0;
            func_0029ebf0(arg0, 0);
        }
        goto block_39;
    case 2:
        temp_2_3 = *(s32 *)(temp_16 + 0x14);
        if (temp_2_3 == 1) {
            func_0029f070(arg0);
            temp_3 = *(s32 *)(temp_16 + 0x14);
            if ((temp_3 != 2) && (temp_3 == 3)) {
                *(s32 *)(temp_16 + 8) = 0;
                *(s32 *)(temp_16 + 0x10) = 0;
            }
            goto block_37;
        }
        if (temp_2_3 == 3) {
            if (*(s32 *)(temp_16 + 8) == 0) {
                temp_2_4 = func_002a1a10(arg0);
                if (temp_2_4 == 0) {
                    var_17 = 0xE;
                    goto loop_25_cond;
loop_25_body:
                    *(s8 *)(D_00882EF0 + var_17) = 0;
                    *(s8 *)(D_00882EF0 + var_17 + 1) = 0;
                    var_17 -= 2;
                    if (var_17 < 0) {
                        goto loop_28_init;
                    }
loop_25_cond:
                    if (strncmp(&iGpffffa7e8,
                                      D_00882EF0 + var_17, 2) == 0) {
                        goto loop_25_body;
                    }
loop_28_init:
                    var_17_2 = 0xE;
                    goto loop_28_cond;
loop_28_body:
                    *(s8 *)(D_00882ED0 + var_17_2) = 0;
                    *(s8 *)(D_00882ED0 + var_17_2 + 1) = 0;
                    var_17_2 -= 2;
                    if (var_17_2 < 0) {
                        goto clear_done;
                    }
loop_28_cond:
                    if (strncmp(&iGpffffa7e8,
                                      D_00882ED0 + var_17_2, 2) == 0) {
                        goto loop_28_body;
                    }
clear_done:
                    datSetHeroNameParts(D_00882EF0, D_00882ED0);
                    *(s32 *)(temp_16 + 0x18) = 0;
                    *(s32 *)(temp_16 + 8) = 1;
                } else if (temp_2_4 == 1) {
                    *(s32 *)(temp_16 + 0x14) = 1;
                }
                goto block_37;
            }
            if (*(s32 *)(temp_16 + 0x18) == 0) {
                fadeBeginTransition(1, 0x1E);
            }
            temp_3_2 = *(s32 *)(temp_16 + 0x18);
            if (temp_3_2 >= 0x1E) {
                *(s32 *)(temp_16 + 0x18) = 0;
                *(s32 *)(temp_16 + 4) = 3;
                goto block_39;
            }
            *(s32 *)(temp_16 + 0x18) = temp_3_2 + 1;
        }
block_37:
        func_002a03b0(arg0);
        goto block_39;
    case 3:
        return -1;
    default:
        goto block_39;
    }
block_39:
    return 0;
}

/* measured: closes opt_loop_invariants around func_002a1fa0. */
// Intent: destructor for the time-limit task. Frees its work block through the free table.
// FUN_002A2310
void yTimeLimitTaskDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}


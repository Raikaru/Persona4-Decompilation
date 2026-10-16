/* Source unit: src/promoted/code1_002a.c */
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
extern s32 func_0025f3f0(f32 farg0, f32 farg1, f32 farg2, s32 arg0, u8 arg1, s32 arg2, s32 arg3, u8 * arg4, s32 arg5);
extern u8 D_00795E60[];
extern u8 D_007966A0[];
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
extern void func_00366960(s32 x, s32 y, f32 z, s32 width, s32 height, s32 rgb,
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

#pragma pop
extern s32 func_002a1c80(u8 *arg0);

/* Source unit: src/promoted/code1_002a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_002a.c; members 002a2e10-002a2e10 */

extern s32 func_002a1fa0(u8 *arg0);
/* measured: closes opt_propagation around func_002a1c80. */
/* measured: closes opt_common_subs around func_002a1c80. */
/* measured: closes no_branch_likely around func_002a1c80. */
/* measured: opt_loop_invariants on hoists the case-zero store constant into the
   preheader, matching retail's li $v1 before the loop-entry branch. */
/* measured: closes opt_loop_invariants around func_002a1fa0. */
// FUN_002A2E10
void func_002a2e10(f32 f0, f32 f1, f32 f2, s32 arg0, u8 arg1, s8 * arg2, s32 arg3, s32 arg4, u8 * arg5) {
    s32 value;

    value = arg2[arg3];
    if (value == 0) {
        value = 10;
    }
    func_0025f3f0(f0, f1, f2, arg0, arg1, value, 0, arg5, 1);
}


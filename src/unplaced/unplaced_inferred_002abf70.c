/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 002abf70-002ac2a0 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 seqYajiTaskUpdate(u8 *arg0);
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;
extern s32 fclAddClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 fclSubClamped(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 func_002bdb50(s32 arg0, s8 arg1);
extern void fclClearMoonFlagEntries(void);
extern s32 shopSystemCreate(s32 arg0);
extern void fclCombineApplyPackedResult(void);
extern s32 func_003493b0(u8 *arg0);
extern s32 kwlnTaskIsLinked(s32 arg0);
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
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
                *(s32 *)(temp_16 + 0x6C8) = shopSystemCreate((s32)arg0);
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
            fclClearMoonFlagEntries();
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
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
// Intent: Seq task destroy: dispatch the seq task's teardown handler [inferred]
// FUN_002AC270
void seqYajiTaskDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma no_branch_likely off
#pragma opt_loop_invariants off
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
#pragma pop

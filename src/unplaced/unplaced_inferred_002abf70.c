
/* Unit optimizer settings shared by the neighboring functions. */
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma opt_loop_invariants off

#include "include_asm.h"
#include "member_access.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "kwln_task_internal.h"
#include "sdk_snd_internal.h"
#include "fr_font_internal.h"
typedef struct SeqYajiLabel { s32 text; } SeqYajiLabel;

typedef struct SeqYajiWork {
    union { s8 state; u8 stateByte; } phase;
    u8 pad01[0x6B3];
    s32 unk6B4;
    s16 unk6B8, unk6BA;
    s8 unk6BC, unk6BD;
    u8 pad6BE[2];
    s32 selection;
    u8 pad6C4[4];
    s32 childTask;
} SeqYajiWork;

extern void (*jtbl_008873EC[])(void *);
extern void chkmemAllocSiteTag(void *, s32 );
extern u8 D_0063EEC0[];
extern u8 D_0063EED0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 seqYajiTaskUpdate(u8 *);
extern u8 D_0063EEA0[];
extern u8 D_0063EEB0[];
extern u16 D_008C024E[];
extern u16 D_008C027A[];
extern s8 iGpffffb54c;
extern s32 fclAddClamped(s32 , s32 , s32 , s32 , s32 );
extern s32 fclSubClamped(s32 , s32 , s32 , s32 , s32 );
extern s32 fclShopCreate(s32 , s8 );
extern void fclClearMoonFlagEntries(void);
extern s32 shopSystemCreate(s32 );
extern void fclCombineApplyPackedResult(void);
extern s32 fclDebugModelCreate(u8 *);
extern s32 kwlnTaskIsLinked(s32 );
#pragma push
#pragma no_branch_likely off
// Seq task update: advances the sequence work each step.
// FUN_002ABF70
s32 seqYajiTaskUpdate(u8 *task) {
    /* measured: retail reloads the work fields in an order that typed accesses do not reproduce. */
    s32 selection;
    s8 state;
    u8 *work;
    void *text;
    f32 x;
    f32 y;
    f32 depth;

    work = (((struct KwlnTask *)task)->work);
    state = ((SeqYajiWork *)work)->phase.state;
    switch (state) {
    case 0:
    case 1:
    case 2:
    case 3:
        ((SeqYajiWork *)work)->phase.state = state + 1;
        break;
    case 4:
        x = 100.0f;
        y = 156.0f;
        depth = 1.0f;
        text = (void *)((SeqYajiLabel *)D_0063EEA0)[((SeqYajiWork *)work)->selection].text;
        frFontExDrawText(x, y, depth,
                      -1, 0, 0, text, 0, 0);
        if (D_008C027A[0] & 0x8000) {
            MEMBER(s32, work, SeqYajiWork, selection) =
                fclAddClamped(MEMBER(s32, work, SeqYajiWork, selection), 1, 3, 0, 1);
        } else if (D_008C027A[0] & 0x2000) {
            MEMBER(s32, work, SeqYajiWork, selection) =
                fclSubClamped(MEMBER(s32, work, SeqYajiWork, selection), 1, 0, 3, 1);
        } else if (D_008C024E[0] & 0x40) {
            if (((SeqYajiWork *)work)->childTask != 0) {
                MEMBER(s32, work, SeqYajiWork, childTask) = 0;
            }
            selection = MEMBER(s32, work, SeqYajiWork, selection);
            switch (selection) {
            case 0:
                MEMBER(s32, work, SeqYajiWork, childTask) = fclShopCreate((s32)task, 0);
                break;
            case 1:
                MEMBER(s32, work, SeqYajiWork, childTask) = shopSystemCreate((s32)task);
                break;
            case 2:
                iGpffffb54c = 0;
                MEMBER(s32, work, SeqYajiWork, childTask) = fclCombineTaskCreate(task);
                break;
            case 3:
                MEMBER(s32, work, SeqYajiWork, childTask) = fclDebugModelCreate(task);
                break;
            }
            ((SeqYajiWork *)work)->phase.state = ((SeqYajiWork *)work)->phase.state + 1;
        } else if (D_008C024E[0] & 0x10) {
            if (((SeqYajiWork *)work)->childTask != 0) {
                MEMBER(s32, work, SeqYajiWork, childTask) = 0;
            }
            switch (MEMBER(s32, work, SeqYajiWork, selection)) {
            case 2:
                iGpffffb54c = 1;
                MEMBER(s32, work, SeqYajiWork, childTask) = fclCombineTaskCreate(task);
                break;
            default:
                break;
            }
            ((SeqYajiWork *)work)->phase.state = ((SeqYajiWork *)work)->phase.state + 1;
        } else if (D_008C024E[0] & 0x80) {
            sdkSndStartStream(0, 0, 0, 0xA);
        }
        break;
    case 5:
        if (iGpffffb54c == 1) {
            x = 20.0f;
            depth = 1.0f;
            y = x;
            frFontExDrawText(x, y, depth,
                          (s32)0x808080FF, 0, 2,
                          (void *)D_0063EEB0, 0, 0);
        }
        if (kwlnTaskIsLinked(((SeqYajiWork *)work)->childTask) == 0) {
            ((SeqYajiWork *)work)->phase.state = 0;
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
#pragma no_branch_likely off
// Seq task destroy: dispatches the task's teardown handler.
// FUN_002AC270
void seqYajiTaskDestroy(u8 *task) {
    jtbl_008873EC[0]((((struct KwlnTask *)task)->work));
}
#pragma pop

#pragma push
#pragma no_branch_likely off
// Create the seq task and initialise its work block.
// FUN_002AC2A0
void seqYajiTaskCreate(void) {
    u8 *p;

    chkmemAllocSiteTag(D_0063EEC0, 0x4B9);
    p = D_008873F4[0](1, 0x4D78, 0x40000);
    (s32)kwlnTaskCreate((const void *)(D_0063EED0), 0xF, 0, 0, seqYajiTaskUpdate, seqYajiTaskDestroy, (u8 *)(p));
    ((SeqYajiWork *)p)->phase.stateByte = 0;
    ((SeqYajiWork *)p)->unk6B4 = 0x3F800000;
    ((SeqYajiWork *)p)->unk6B8 = 0x1F;
    ((SeqYajiWork *)p)->unk6BA = 0;
    ((SeqYajiWork *)p)->unk6BC = 1;
    ((SeqYajiWork *)p)->unk6BD = 1;
    ((SeqYajiWork *)p)->selection = 0;
}
#pragma pop

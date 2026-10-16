/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0035e820-0035f0c0 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
extern void (*D_008873EC[])(void *);
extern void sdkSpriteFreeNode(void *node);
extern void datScreenWipeSetTextureId(u8 *arg0, u16 arg1);
static inline u32 add_offset_first(u32 offset, u32 base)
{
    return offset + base;
}

extern s32 nLineIsIdle(void);
extern void datPortraitSetValue(u8 *arg0, s8 arg1, s32 arg2);
extern void datPortraitSetLabel(s32 arg0, u16 arg1, s32 arg2);
#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Destroy the community overlay: free its eleven sprite nodes and release its work block [inferred]
// FUN_0035E820
void datCommunityOverlayDestroy(u8 *arg0)
{
    u8 *base;
    s32 i;
    s32 *slot;

    base = *(u8 **)(arg0 + 0x38);
    i = 0;
    goto loop_test;
loop_body:
    slot = (s32 *)(base + i * 4 + 0x448);
    if (*slot != 0) {
        sdkSpriteFreeNode((void *)*slot);
        *slot = 0;
    }
    i++;
loop_test:
    if (i < 11) {
        goto loop_body;
    }
    *(s32 *)(base + 0x24) = 0;
    (*D_008873EC)(base);
}
#pragma pop

void datCommunityCursorFeedback(s32 arg0);
void datCommunityFillVisibleRecords(u8 *arg0);
s32 datCommunityIsReady(u8 *arg0);
void datCommunityMenuInit(u8 *arg0);
void datCommunityMenuRelease(u8 *arg0);
s32 datCommunityPanelOpenStep(u8 *arg0);
s32 datCommunityPushValue(s32 arg0, s32 arg1, s16 arg2);
s32 datCommunityRequestExit(void);
void datCommunityResetOffset(u8 *arg0);
void datCommunitySetSlotLayout(u8 *arg0);
s32 datCommunitySetTableMode(u8 *arg0, s32 arg1);
void datScreenWipeSetupSlot(u8 *arg0, s32 arg1, s32 arg2, s32 arg3);
void resrcMngSuppressRender(void);
void resrcMngUnsuppressRender(void);

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community menu state machine: open the menu, wait for it to be ready, run its list and cursor actions, and return 1 when it closes or 2 when the fade ends [inferred]
// FUN_0035E8B0
s32 datCommunityMenuStep(u32 *arg0, s32 *arg1, u8 *arg2)
{
    extern u16 D_008C024E[];
    extern s32 datCommunityRequestExit(void);
    extern s32 datCommunityPushValue(s32, s32, s32);
    extern void datCommunityPortraitSetRecord(u8 *);
    extern void datCommunityPortraitSetSelected(u8 *);
    u8 buf[44];
    f32 alphaF;
    s32 result;
    s32 resultFlag;
    s32 alpha;
    u32 state;

    *arg1 = (resultFlag = 1);
    state = *arg0;
    switch (state) {
    case 0:
        *(f32 *)(arg2 + 4) = 0.0f;
        *(f32 *)(arg2 + 8) = 0.0f;
        *(u8 *)arg2 = 0xFF;
        datCommunityMenuInit(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        if ((datCommunityPanelOpenStep(arg2) & nLineIsIdle()) != 0) {
            *arg0 = 3;
            nLineSelectSet(0x19);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (datCommunityIsReady(arg2) != 0) {
            datCommunityMenuRelease(arg2);
            return 1;
        }
        break;
    case 3:
        if (datCommunityIsReady(arg2) != 0) {
            resrcMngSuppressRender();
            datScreenWipeSetTextureId((u8 *)*(s32 *)(arg2 + 0x1308), 1);
            datScreenWipeSetupSlot((u8 *)*(s32 *)(arg2 + 0x1308), 0, 1, 0);
            *arg0 = 4;
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            datCommunitySetTableMode(arg2, 1);
            *arg0 = 2;
            resrcMngUnsuppressRender();
            nLineSelectSet(0x1B);
            datScreenWipeSetupSlot((u8 *)*(s32 *)(arg2 + 0x1308), 0, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            if (*(s16 *)(arg2 + 0x134) > 0) {
                datCommunitySetTableMode(arg2, 2);
                datCommunitySetSlotLayout(arg2);
                *arg0 = 5;
                datCommunityPushValue((s32)arg2, 2, 0);
                nLineSelectSet(0x1A);
                datScreenWipeSetupSlot((u8 *)*(s32 *)(arg2 + 0x1308), 1, 0, 0);
                datCommunityPortraitSetRecord(arg2);
                datCommunityFillVisibleRecords(arg2);
                datCommunityPortraitSetSelected(arg2);
                sdkSndStartStream(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x10) {
            *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
            *arg0 = 7;
        } else {
            sdkListStateConfigure(buf, 5, *(s16 *)(arg2 + 0x134), *(s16 *)(arg2 + 0x24), *(s16 *)(arg2 + 0x26));
            sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((result = sdkListStateHandleInput(buf)) > 0) {
                datCommunityPushValue((s32)arg2, 1, *(s32 *)(buf + 0x28));
                datCommunityPushValue((s32)arg2, 0, *(s32 *)(buf + 0x24));
                datCommunityCursorFeedback(result);
            }
        }
        break;
    case 5:
        if (datCommunityIsReady(arg2) != 0) {
            datCommunitySetTableMode(arg2, 3);
            *arg0 = 6;
            nLineSelectSet(0x1C);
            datCommunityResetOffset(arg2);
            datScreenWipeSetTextureId((u8 *)*(s32 *)(arg2 + 0x1308), 0);
        }
        break;
    case 6:
        if (datCommunityIsReady(arg2) != 0) {
            if (D_008C024E[0] & 0x20) {
                datCommunitySetTableMode(arg2, 4);
                *arg0 = 3;
                nLineSelectSetImmediate(0x19);
                datPortraitSetLabel(*(s32 *)(arg2 + 0x1310), 0, 0);
                sdkSndStartStream(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                *(s32 *)(arg2 + 0x10) = datCommunityRequestExit();
                *arg0 = 7;
            } else {
                sdkListStateConfigure(buf, 5, *(s16 *)(arg2 + 0x134), *(s16 *)(arg2 + 0x24), *(s16 *)(arg2 + 0x26));
                sdkListStateSetActive(buf, 0);
                sdkListStateSetSecondaryMasks(buf, 8, 4, 0, 0);
                if (sdkListStateHandleInput(buf) != 0) {
                    datCommunityPushValue((s32)arg2, 1, *(s32 *)(buf + 0x28));
                    datCommunityPushValue((s32)arg2, 0, *(s32 *)(buf + 0x24));
                    datCommunityPushValue((s32)arg2, 2, 0);
                    datCommunityPortraitSetRecord(arg2);
                    datCommunityResetOffset(arg2);
                    datCommunityFillVisibleRecords(arg2);
                    datCommunityPortraitSetSelected(arg2);
                    sdkSndStartStream(0, 1, 0, 5);
                } else if (*(s32 *)(arg2 + 0x148) > 1) {
                    sdkListStateConfigure(buf, 8, *(s32 *)(arg2 + 0x148), *(s16 *)(arg2 + 0x28), 0);
                    sdkListStateSetSecondaryMasks(buf, 0x4000, 0x1000, 0, 0);
                    if (sdkListStateHandleInput(buf) != 0) {
                        datCommunityPushValue((s32)arg2, 2, *(s32 *)(buf + 0x24));
                        datCommunityPortraitSetSelected(arg2);
                        sdkSndStartStream(0, 1, 0, 0);
                    }
                }
            }
        }
        break;
    case 7:
        if ((++*(u16 *)(arg2 + 0xC) & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alphaF = (1.0f - ((f32)*(u16 *)(arg2 + 0xC) / 3.0f)) * 255.0f;
            alpha = (u8)alphaF;
            *(u8 *)arg2 = alpha;
            resultFlag = 0;
        }
        if (resultFlag != 0) {
            return 2;
        }
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set the community portrait's value from the selected record's state and kind flags [inferred]
// FUN_0035EF80
void datCommunityPortraitSetRecord(u8 *arg0)
{
    s32 flags;
    s32 kind;
    s8 state;
    u8 *record;

    record = (u8 *)add_offset_first((s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC, (u32)arg0);
    state = *(s8 *)(record + 0x38);
    flags = 0;
    kind = *(s32 *)(record + 0x40);
    switch (kind) {
    case 2:
        flags |= 1;
        break;
    case 3:
        flags |= 2;
        break;
    case 1:
        flags |= 4;
        break;
    }
    datPortraitSetValue((u8 *)*(s32 *)(arg0 + 0x130C), state, flags);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set the community portrait for the selected entry: its label id and kind flags [inferred]
// FUN_0035F020
void datCommunityPortraitSetSelected(u8 *arg0)
{
    s32 flags;
    s32 kind;
    u16 id;
    u8 *record;

    id = *(u16 *)((u8 *)add_offset_first((s32)*(s16 *)(arg0 + 0x28) * 2, (u32)arg0) + 0x136);
    flags = 0;
    record = (u8 *)add_offset_first((s32)(*(s16 *)(arg0 + 0x24) + *(s16 *)(arg0 + 0x26)) * 0xC, (u32)arg0);
    kind = *(s32 *)(record + 0x40);
    switch (kind) {
    case 2:
        flags |= 1;
        break;
    case 3:
        flags |= 2;
        break;
    case 1:
        flags |= 4;
        break;
    }
    datPortraitSetLabel(*(s32 *)(arg0 + 0x1310), id, flags);
}
#pragma pop

s32 datCommunityRequestExit(void);
void resrcMngSuppressRender(void);
void resrcMngUnsuppressRender(void);

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community detail state machine: open the detail panel, handle its cursor and actions, and return 1 when it closes or 2 when the fade ends [inferred]
// FUN_0035F0C0
s32 datCommunityDetailStep(u32 *arg0, s32 *arg1, u8 *arg2)
{
    extern u16 D_008C024E[];
    extern u16 D_008C0276[];
    extern s32 datCommunityRequestExit(void);
    u8 query[0x30];
    f32 alpha;
    s32 resultFlag;
    s32 kind;
    s32 hit;
    s32 value;

    *arg1 = (resultFlag = 1);
    switch (*arg0) {
    case 0:
        *(s32 *)(arg2 + 8) = 0;
        *(s32 *)(arg2 + 0xC) = 0;
        *(u8 *)arg2 = 0xFF;
        cmpConfigInitState(arg2);
        *arg0 = 1;
        *arg1 = 0;
        break;
    case 1:
        if (cmpConfigAdvancePhase(arg2) & nLineIsIdle()) {
            *arg0 = 3;
            nLineSelectSet(0x21);
        } else {
            *arg1 = 0;
        }
        break;
    case 2:
        if (cmpConfigAllRowsMet(arg2) != 0) {
            cmpConfigFreeSprites(arg2);
            return 1;
        }
        break;
    case 3:
        if (cmpConfigAllRowsMet(arg2) != 0) {
            switch (*(s32 *)(arg2 + 0x1C)) {
            case 0:
                resrcMngSuppressRender();
                break;
            case 1:
                break;
            }
            cmpConfigSetMode(arg2, 2);
            *arg0 = 4;
            goto do_state4;
        }
        break;
    case 4:
    do_state4:
        if (D_008C024E[0] & 0x40) {
            kind = *(s32 *)(arg2 + 0x30);
            if (kind == 6) {
                cmpConfigSyncFlags(arg2);
                cmpConfigSetMode(arg2, 1);
                *arg0 = 2;
                nLineSelectSet(0x22);
                switch (*(s32 *)(arg2 + 0x1C)) {
                case 0:
                    resrcMngUnsuppressRender();
                    break;
                case 1:
                    break;
                }
                sdkSndStartStream(0, 0, 0, 1);
            } else if (cmpConfigToggleOption(arg2, kind) != 0) {
                sdkSndStartStream(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            cmpConfigSetMode(arg2, 1);
            *arg0 = 2;
            nLineSelectSet(0x22);
            switch (*(s32 *)(arg2 + 0x1C)) {
            case 0:
                resrcMngUnsuppressRender();
                break;
            case 1:
                break;
            }
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            if (*(s32 *)(arg2 + 0x1C) == 0) {
                *(s32 *)(arg2 + 0x14) = datCommunityRequestExit();
                *arg0 = 5;
            }
        } else {
            sdkListStateConfigure(query, 7, 7, *(s32 *)(arg2 + 0x30), 0);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(query) != 0) {
                cmpConfigSetValue(arg2, 0, *(s32 *)(query + 0x24));
                sdkSndStartStream(0, 1, 0, 0);
            } else {
                kind = *(s32 *)(arg2 + 0x30);
                if (kind != 6) {
                    hit = 0;
                    if (D_008C0276[0] & 0x8000) {
                        hit = cmpConfigSetOption(arg2, kind, 1);
                    } else if (D_008C0276[0] & 0x2000) {
                        hit = cmpConfigSetOption(arg2, kind, 0);
                    }
                    if (hit != 0) {
                        sdkSndStartStream(0, 0, 0, 1);
                    }
                }
            }
        }
        break;
    case 5:
        if ((++*(u16 *)(arg2 + 0x10) & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            alpha = (1.0f - ((f32)*(u16 *)(arg2 + 0x10) / 3.0f)) * 255.0f;
            value = (u8)alpha;
            *(u8 *)arg2 = value;
            resultFlag = 0;
        }
        if (resultFlag != 0) {
            return 2;
        }
        break;
    }
    return 0;
}
#pragma pop

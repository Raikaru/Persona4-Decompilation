/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0035e820-0035f0c0 */

#include "include_asm.h"
#include "member_access.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "kwln_task_internal.h"

/* The list stores 0xC-byte records before its count at +0x134. */
typedef struct DatCommunityRecord {
    s8 state;
    u8 pad1[7];
    s32 kind;
} DatCommunityRecord;

typedef struct DatCommunityListWork {
    u8 alpha;
    u8 pad1[3];
    f32 x, y;
    u16 fadeFrame;
    u8 padE[2];
    s32 background;
    u8 pad14[0x10];
    s16 cursor, scroll, selected;
    u8 pad2A[0xE];
    DatCommunityRecord records[21];
    s16 count;
    u16 ids[9];
    s32 choiceCount;
    u8 pad14C[0x11BC];
    s32 wipeTask, portraitTask, labelTask;
} DatCommunityListWork;

typedef struct DatCommunityOverlayWork {
    u8 pad0[0x24];
    s32 unk24;
    u8 pad28[0x420];
    s32 sprites[11];
} DatCommunityOverlayWork;

/* Config work uses word initialization but halfword fade increments at +0x10. */
typedef struct CmpConfigWork {
    u8 alpha;
    u8 pad1[7];
    s32 unk8, unkC;
    u16 fadeFrame;
    u8 pad12[2];
    s32 background;
    u8 pad18[4];
    s32 mode;
    u8 pad20[0x10];
    s32 selected;
} CmpConfigWork;

/* sdkListState.c initializes 0x2C bytes and publishes cursor/scroll here. */
typedef struct SdkListState {
    u8 pad0[0x24];
    s32 cursor, scroll;
} SdkListState;
extern void (*D_008873EC[])(void *);
extern void sdkSpriteFreeNode(void *node);
extern void datScreenWipeSetTextureId(u8 *task, u16 textureId);
static inline u32 addOffsetFirst(u32 offset, u32 base)
{
    return offset + base;
}

extern s32 nLineIsIdle(void);
extern void datPortraitSetValue(u8 *task, s8 portraitId, s32 flags);
extern void datPortraitSetLabel(s32 taskAddress, u16 labelId, s32 flags);
#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Destroy the community overlay: free its eleven sprite nodes and release its work block [inferred]
// FUN_0035E820
void datCommunityOverlayDestroy(u8 *task)
{
    u8 *base;
    s32 spriteIndex;
    s32 *slot;

    base = ((KwlnTask *)task)->work;
    spriteIndex = 0;
    while (spriteIndex < 11) {
        slot = &((DatCommunityOverlayWork *)base)->sprites[spriteIndex];
        if (*slot != 0) {
            sdkSpriteFreeNode((void *)*slot);
            *slot = 0;
        }
        spriteIndex++;
    }
    ((DatCommunityOverlayWork *)base)->unk24 = 0;
    (*D_008873EC)(base);
}
#pragma pop

void datCommunityCursorFeedback(s32 direction);
void datCommunityFillVisibleRecords(u8 *menuWork);
s32 datCommunityIsReady(u8 *menuWork);
void datCommunityMenuInit(u8 *menuWork);
void datCommunityMenuRelease(u8 *menuWork);
s32 datCommunityPanelOpenStep(u8 *menuWork);
s32 datCommunityPushValue(s32 menuAddress, s32 selectionIndex, s16 value);
s32 datCommunityRequestExit(void);
void datCommunityResetOffset(u8 *menuWork);
void datCommunitySetSlotLayout(u8 *menuWork);
s32 datCommunitySetTableMode(u8 *menuWork, s32 mode);
void datScreenWipeSetupSlot(u8 *task, s32 slotIndex, s32 initialize, s32 reverse);
void resrcMngSuppressRender(void);
void resrcMngUnsuppressRender(void);

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community menu state machine: open the menu, wait for it to be ready, run its list and cursor actions, and return 1 when it closes or 2 when the fade ends [inferred]
// FUN_0035E8B0
s32 datCommunityMenuStep(u32 *phase, s32 *active, u8 *listWork)
{
    extern u16 D_008C024E[];
    extern s32 datCommunityRequestExit(void);
    extern s32 datCommunityPushValue(s32, s32, s32);
    extern void datCommunityPortraitSetRecord(u8 *);
    extern void datCommunityPortraitSetSelected(u8 *);
    u8 query[44];
    f32 alphaF;
    s32 result;
    s32 resultFlag;
    s32 alpha;
    u32 state;

    *active = (resultFlag = 1);
    state = *phase;
    switch (state) {
    case 0:
        ((DatCommunityListWork *)listWork)->x = 0.0f;
        ((DatCommunityListWork *)listWork)->y = 0.0f;
        ((DatCommunityListWork *)listWork)->alpha = 0xFF;
        datCommunityMenuInit(listWork);
        *phase = 1;
        *active = 0;
        break;
    case 1:
        if ((datCommunityPanelOpenStep(listWork) & nLineIsIdle()) != 0) {
            *phase = 3;
            nLineSelectSet(0x19);
        } else {
            *active = 0;
        }
        break;
    case 2:
        if (datCommunityIsReady(listWork) != 0) {
            datCommunityMenuRelease(listWork);
            return 1;
        }
        break;
    case 3:
        if (datCommunityIsReady(listWork) != 0) {
            resrcMngSuppressRender();
            /* measured: typed wipeTask hoists its address across the two calls, adding one instruction. */
            datScreenWipeSetTextureId((u8 *)((DatCommunityListWork *)(listWork))->wipeTask, 1);
            datScreenWipeSetupSlot((u8 *)MEMBER(s32, listWork, DatCommunityListWork, wipeTask), 0, 1, 0);
            *phase = 4;
        }
        break;
    case 4:
        if (D_008C024E[0] & 0x20) {
            datCommunitySetTableMode(listWork, 1);
            *phase = 2;
            resrcMngUnsuppressRender();
            nLineSelectSet(0x1B);
            datScreenWipeSetupSlot((u8 *)((DatCommunityListWork *)(listWork))->wipeTask, 0, 0, 1);
            sdkSndStartStream(0, 2, 0, 4);
        } else if (D_008C024E[0] & 0x40) {
            if (((DatCommunityListWork *)listWork)->count > 0) {
                datCommunitySetTableMode(listWork, 2);
                datCommunitySetSlotLayout(listWork);
                *phase = 5;
                datCommunityPushValue((s32)listWork, 2, 0);
                nLineSelectSet(0x1A);
                datScreenWipeSetupSlot((u8 *)((DatCommunityListWork *)(listWork))->wipeTask, 1, 0, 0);
                datCommunityPortraitSetRecord(listWork);
                datCommunityFillVisibleRecords(listWork);
                datCommunityPortraitSetSelected(listWork);
                sdkSndStartStream(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x10) {
            ((DatCommunityListWork *)listWork)->background = datCommunityRequestExit();
            *phase = 7;
        } else {
            sdkListStateConfigure(query, 5, ((DatCommunityListWork *)listWork)->count, ((DatCommunityListWork *)listWork)->cursor, ((DatCommunityListWork *)listWork)->scroll);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0x2000, 0x8000);
            if ((result = sdkListStateHandleInput(query)) > 0) {
                datCommunityPushValue((s32)listWork, 1, ((SdkListState *)query)->scroll);
                datCommunityPushValue((s32)listWork, 0, ((SdkListState *)query)->cursor);
                datCommunityCursorFeedback(result);
            }
        }
        break;
    case 5:
        if (datCommunityIsReady(listWork) != 0) {
            datCommunitySetTableMode(listWork, 3);
            *phase = 6;
            nLineSelectSet(0x1C);
            datCommunityResetOffset(listWork);
            datScreenWipeSetTextureId((u8 *)((DatCommunityListWork *)(listWork))->wipeTask, 0);
        }
        break;
    case 6:
        if (datCommunityIsReady(listWork) != 0) {
            if (D_008C024E[0] & 0x20) {
                datCommunitySetTableMode(listWork, 4);
                *phase = 3;
                nLineSelectSetImmediate(0x19);
                datPortraitSetLabel(((DatCommunityListWork *)listWork)->labelTask, 0, 0);
                sdkSndStartStream(0, 0, 0, 2);
            } else if (D_008C024E[0] & 0x10) {
                ((DatCommunityListWork *)listWork)->background = datCommunityRequestExit();
                *phase = 7;
            } else {
                sdkListStateConfigure(query, 5, ((DatCommunityListWork *)listWork)->count, ((DatCommunityListWork *)listWork)->cursor, ((DatCommunityListWork *)listWork)->scroll);
                sdkListStateSetActive(query, 0);
                sdkListStateSetSecondaryMasks(query, 8, 4, 0, 0);
                if (sdkListStateHandleInput(query) != 0) {
                    datCommunityPushValue((s32)listWork, 1, ((SdkListState *)query)->scroll);
                    datCommunityPushValue((s32)listWork, 0, ((SdkListState *)query)->cursor);
                    datCommunityPushValue((s32)listWork, 2, 0);
                    datCommunityPortraitSetRecord(listWork);
                    datCommunityResetOffset(listWork);
                    datCommunityFillVisibleRecords(listWork);
                    datCommunityPortraitSetSelected(listWork);
                    sdkSndStartStream(0, 1, 0, 5);
                } else if (((DatCommunityListWork *)listWork)->choiceCount > 1) {
                    sdkListStateConfigure(query, 8, ((DatCommunityListWork *)listWork)->choiceCount, ((DatCommunityListWork *)listWork)->selected, 0);
                    sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
                    if (sdkListStateHandleInput(query) != 0) {
                        datCommunityPushValue((s32)listWork, 2, ((SdkListState *)query)->cursor);
                        datCommunityPortraitSetSelected(listWork);
                        sdkSndStartStream(0, 1, 0, 0);
                    }
                }
            }
        }
        break;
    case 7:
        if ((++((DatCommunityListWork *)listWork)->fadeFrame & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            /* measured: typed fadeFrame eliminates the retail post-increment reload. */
            alphaF = (1.0f - ((f32)MEMBER(u16, listWork, DatCommunityListWork, fadeFrame) / 3.0f)) * 255.0f;
            alpha = (u8)alphaF;
            ((DatCommunityListWork *)listWork)->alpha = alpha;
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
void datCommunityPortraitSetRecord(u8 *listWork)
{
    s32 flags;
    s32 kind;
    s8 state;
    u8 *record;

    record = (u8 *)addOffsetFirst((s32)(((DatCommunityListWork *)listWork)->cursor + ((DatCommunityListWork *)listWork)->scroll) * 0xC, (u32)listWork);
    state = ((DatCommunityRecord *)(record + 0x38))->state;
    flags = 0;
    kind = ((DatCommunityRecord *)(record + 0x38))->kind;
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
    datPortraitSetValue((u8 *)((DatCommunityListWork *)listWork)->portraitTask, state, flags);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Set the community portrait for the selected entry: its label id and kind flags [inferred]
// FUN_0035F020
void datCommunityPortraitSetSelected(u8 *listWork)
{
    s32 flags;
    s32 kind;
    u16 id;
    u8 *record;

    /* measured: direct ids[selected] changes the index/base addu operand order (one differing byte). */
    id = MEMBER(u16, (u8 *)addOffsetFirst((s32)((DatCommunityListWork *)listWork)->selected * 2, (u32)listWork), DatCommunityListWork, ids[0]);
    flags = 0;
    record = (u8 *)addOffsetFirst((s32)(((DatCommunityListWork *)listWork)->cursor + ((DatCommunityListWork *)listWork)->scroll) * 0xC, (u32)listWork);
    kind = ((DatCommunityRecord *)(record + 0x38))->kind;
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
    datPortraitSetLabel(((DatCommunityListWork *)listWork)->labelTask, id, flags);
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
s32 datCommunityDetailStep(u32 *phase, s32 *active, u8 *configWork)
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

    *active = (resultFlag = 1);
    switch (*phase) {
    case 0:
        ((CmpConfigWork *)configWork)->unk8 = 0;
        ((CmpConfigWork *)configWork)->unkC = 0;
        ((CmpConfigWork *)configWork)->alpha = 0xFF;
        cmpConfigInitState(configWork);
        *phase = 1;
        *active = 0;
        break;
    case 1:
        if (cmpConfigAdvancePhase(configWork) & nLineIsIdle()) {
            *phase = 3;
            nLineSelectSet(0x21);
        } else {
            *active = 0;
        }
        break;
    case 2:
        if (cmpConfigAllRowsMet(configWork) != 0) {
            cmpConfigFreeSprites(configWork);
            return 1;
        }
        break;
    case 3:
        if (cmpConfigAllRowsMet(configWork) == 0) {
            break;
        }
        switch (((CmpConfigWork *)configWork)->mode) {
        case 0:
            resrcMngSuppressRender();
            break;
        case 1:
            break;
        }
        cmpConfigSetMode(configWork, 2);
        *phase = 4;
        /* fall through: process input as soon as the detail panel becomes ready */
    case 4:
        /* measured: typed selected changes reloads across option calls (1256 versus 1264 bytes). */
        if (D_008C024E[0] & 0x40) {
            kind = ((CmpConfigWork *)(configWork))->selected;
            if (kind == 6) {
                cmpConfigSyncFlags(configWork);
                cmpConfigSetMode(configWork, 1);
                *phase = 2;
                nLineSelectSet(0x22);
                switch (((CmpConfigWork *)configWork)->mode) {
                case 0:
                    resrcMngUnsuppressRender();
                    break;
                case 1:
                    break;
                }
                sdkSndStartStream(0, 0, 0, 1);
            } else if (cmpConfigToggleOption(configWork, kind) != 0) {
                sdkSndStartStream(0, 0, 0, 1);
            }
        } else if (D_008C024E[0] & 0x20) {
            cmpConfigSetMode(configWork, 1);
            *phase = 2;
            nLineSelectSet(0x22);
            switch (((CmpConfigWork *)configWork)->mode) {
            case 0:
                resrcMngUnsuppressRender();
                break;
            case 1:
                break;
            }
            sdkSndStartStream(0, 0, 0, 2);
        } else if (D_008C024E[0] & 0x10) {
            if (((CmpConfigWork *)configWork)->mode == 0) {
                ((CmpConfigWork *)configWork)->background = datCommunityRequestExit();
                *phase = 5;
            }
        } else {
            sdkListStateConfigure(query, 7, 7, ((CmpConfigWork *)(configWork))->selected, 0);
            sdkListStateSetSecondaryMasks(query, 0x4000, 0x1000, 0, 0);
            if (sdkListStateHandleInput(query) != 0) {
                cmpConfigSetValue(configWork, 0, ((SdkListState *)query)->cursor);
                sdkSndStartStream(0, 1, 0, 0);
            } else {
                kind = MEMBER(s32, configWork, CmpConfigWork, selected);
                if (kind != 6) {
                    hit = 0;
                    if (D_008C0276[0] & 0x8000) {
                        hit = cmpConfigSetOption(configWork, kind, 1);
                    } else if (D_008C0276[0] & 0x2000) {
                        hit = cmpConfigSetOption(configWork, kind, 0);
                    }
                    if (hit != 0) {
                        sdkSndStartStream(0, 0, 0, 1);
                    }
                }
            }
        }
        break;
    case 5:
        if ((++((CmpConfigWork *)configWork)->fadeFrame & 0xFFFF) >= 3) {
            resultFlag = 1;
        } else {
            /* measured: typed fadeFrame eliminates the retail post-increment reload. */
            alpha = (1.0f - ((f32)MEMBER(u16, configWork, CmpConfigWork, fadeFrame) / 3.0f)) * 255.0f;
            value = (u8)alpha;
            ((CmpConfigWork *)configWork)->alpha = value;
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

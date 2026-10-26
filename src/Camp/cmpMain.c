/* Original translation unit cmpMain.c (from __FILE__ assert strings). */
#include "include_asm.h"
#include "sdktask.h"
#include "type.h"
#include "sdk_snd_internal.h"
#include "radar_menu_internal.h"
#include "sdk_list_state.h"

void chkmemAllocSiteTag(void *file, s32 line);
void kAssertFail(void *, s32);
void PrimAppendNode(void *list, void *node);
s32 nLineSelectSet(s32);
void nLineSetActive(s32);
void resrcMngUnsuppressRender(void);
void datGridEffectCreate(s32 style, u8 *color, s32 duration, s32 tailDuration, s64 layout, s32 kind, s32 priority, s32 drawPriority);
void sdkListStateConfigure(void *, s32, s32, s32, s32);
void sdkListStateSetSecondaryMasks(void *, s32, s32, s32, s32);
s32 sdkListStateHandleInput(void *);
void memset(void *dst, s32 value, u32 size);


void func_00440b68();
void cmpMainSetDefaultTableIndex(void);
u8 *H_Cdvd_AcquireDirectory(u8 *path, s32 flags);
s32 H_Cdvd_IsFileLoaded(u8 *cdvd);
void H_Cdvd_Destroy(u8 *cdvd);
s32 sdkSpriteCreateFromName(u32 name);
s32 hMaestroDecodeIsReady(s32 state);

/* Camp-family helpers declared locally; the retail TUs are separate objects. */
void titleSlotTableInit(u8 *);
s32 titleSlotsSettled(u8 *);
void titleSlotSetMode(u8 *, s32);
s32 titleSlotFramesElapsed(u8 *);
void titleFreeSpriteNodes(u8 *);
void titleSelectSlot(u8 *, s32);
s32 radarItemMenuUpdate(u8 *, s32 *, u8 *);
s32 radarRecipientMenuUpdate(u32 *, s32 *, u8 *);
s32 radarTransferMenuUpdate(u8 *, s32 *, u8 *);
s32 radarPersonaMenuUpdate(u8 *, s32 *, u8 *);
s32 radarUpdateState(u32 *, s32 *, u8 *);
s32 cmpSystemMenuUpdate(u32 *, s32 *, u8 *);
s32 datCommunityMenuStep(u8 *, s32 *, u8 *);
s32 titleSlotUpdateAndDraw(u8 *);
s32 radarStepSlotAnimA(u8 *);
s32 cmpSkillMenuUpdate(u8 *);
s32 datCommunityPanelUpdate(u8 *);
s32 cmpEquipMenuUpdate(u8 *);
s32 cmpPersonaMenuUpdate(u8 *);
s32 radarUpdateFrame(u8 *);
s32 datCommunityMenuUpdate(u8 *);
void radarFreeSpriteNodes(u8 *);
void cmpSkillFreeSprites(u8 *);
void radarReleaseSpritesAndEntries(u8 *);
void cmpPersonaMenuRelease(u8 *);
void radarDestroy(u8 *);
void cmpSystemMenuRelease(u8 *);
void datCommunityMenuRelease(u8 *);

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*D_00887300[])(s32, s32);
extern void (*D_00887304[])(s32, void *);
extern u16 D_008C024E[];
extern u8 D_00793E80[];
extern u8 D_005E5890[];
extern u8 D_005E58A0[];
extern u8 D_005E58B0[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern u8 D_005E5810[];
extern u8 D_005E5870[];
extern u8 D_005E5880[];

/* gp - 0x4E14 = 0x007642DC. */
extern u8 *iGpffffb1ec;
/* gp - 0x6348 = string table pointer source. */
extern u8 iGpffff9cb8;
/* gp - 0x6350 / -0x634C = string pointers. */
extern u8 *iGpffff9cb0;
extern u8 *iGpffff9cb4;
/* gp - 0x6340 = string buffer. */
extern u8 iGpffff9cc0;

/* The creator allocates 0x9740 bytes; dispatcher calls establish each embedded
 * menu boundary. The final 0x30-byte node is submitted every task frame. */
typedef struct {
    union { u32 value; s32 signedValue; } state;
    s32 detailState;
    s32 nextState;
    u16 flags;
    u8 pad0E[2];
    s32 activeMenus;
    s32 closingDone;
    TitleSlotMenu title;
    u8 item[0x1BE8];
    u8 skill[0x1338];
    u8 equipment[0x1598];
    u8 community[0x1318];
    u8 persona[0x1CC4];
    u8 other[0x18B0];
    u8 system[0x708];
    u8 pad9708[4];
    s32 nodeNext, nodeTail, drawCallback;
    u8 pad9718[4];
    s32 nodeContext;
    u8 pad9720[0x1C];
    u16 tableIndex;
    u8 pad973E[2];
} CmpMainWork;
typedef char CmpMainWorkSize[sizeof(CmpMainWork) == 0x9740 ? 1 : -1];
/* Six resource names and six sprite handles are followed by the directory load. */
typedef struct {
    u16 state;
    u8 pad02[2];
    u32 resourceNames[6];
    s32 sprites[6];
    u8 *directory;
} CmpAssetLoaderWork;

/* Dispatch the active camp submenu and synchronize its transition/draw mask. */
// FUN_0012C510
s32 cmpMainTaskStep(u8 *unusedTask) {
    u8 *work;
    CmpMainWork *menu;
    u32 state;
    s32 result;
    s32 itemChanged;
    s32 recipientChanged;
    s32 equipmentChanged;
    s32 personaChanged;
    s32 otherChanged;
    s32 systemChanged;
    s32 communityChanged;
    s32 commandOffset;
    u32 commandAddress;
    u8 inputState[0x30];

    work = iGpffffb1ec;
    menu = (CmpMainWork *)work;
    menu->nodeNext = 0;
    menu->nodeTail = 0;
    PrimAppendNode((u8 *)D_00793E80 + menu->tableIndex * 0x30, work + 0x970C);
    state = menu->state.value;
    switch (state) {
    case 0:
        *(s32 *)&menu->title.x = 0;
        *(s32 *)&menu->title.y = 0;
        menu->title.alpha = 0xFF;
        menu->title.selection = 0;
        menu->state.signedValue = 1;
        sdkSndStartStream(0, 2, 0, 3);
        break;
    case 1:
        menu->activeMenus = 1;
        menu->state.signedValue = 2;
        titleSlotTableInit(work + 0x18);
        nLineSelectSet(1);
        break;
    case 2:
        menu->activeMenus = 1;
        if ((titleSlotsSettled(work + 0x18) != 0) && (menu->activeMenus == 1)) {
            if (D_008C024E[0] & 0x40) {
                menu->detailState = 0;
                menu->state.signedValue = 3;
                commandOffset = menu->title.selection * 4;
                commandAddress = commandOffset + (u32)work;
                switch (((CmpMainWork *)commandAddress)->title.commandIds[0]) {
                case 1:
                    menu->nextState = 4;
                    break;
                case 0:
                    menu->nextState = 5;
                    datGridEffectCreate(0, iGpffff9cb0, 0x14, 8, 1, 2, 0xC7, 0xB1);
                    break;
                case 2:
                    menu->nextState = 6;
                    break;
                case 3:
                    menu->nextState = 7;
                    break;
                case 4:
                    menu->nextState = 8;
                    break;
                case 5:
                    menu->nextState = 9;
                    datGridEffectCreate(0, iGpffff9cb4, 0x14, 8, 1, 2, 0xC7, 0xB1);
                    break;
                case 6:
                    menu->nextState = 0xA;
                    break;
                default:
                    kAssertFail(D_005E5890, 0xFD);
                    break;
                }
                titleSlotSetMode(work + 0x18, 3);
                nLineSelectSet(2);
                sdkSndStartStream(0, 2, 0, 3);
            } else if ((D_008C024E[0] & 0x20) || (D_008C024E[0] & 0x10)) {
                titleSlotSetMode(work + 0x18, 3);
                menu->state.signedValue = 3;
                menu->nextState = 0xD;
                menu->closingDone = 0;
                nLineSelectSet(2);
                sdkSndStartStream(0, 2, 0, 4);
            } else {
                sdkListStateConfigure(&inputState, menu->title.slotCount, menu->title.slotCount,
                              menu->title.selection, 0);
                sdkListStateSetSecondaryMasks(&inputState, 0x4000, 0x1000, 0, 0);
                if (sdkListStateHandleInput(&inputState) != 0) {
                    titleSelectSlot(work + 0x18, ((SdkListState *)&inputState)->cursor);
                }
            }
        }
        break;
    case 13:
        if ((titleSlotFramesElapsed(work + 0x18) != 0) && (menu->closingDone != 0)) {
            return -1;
        }
        break;
    case 3:
        result = menu->nextState;
        if ((result < 4) || (result > 0xD)) {
            kAssertFail(D_005E5890, 0x133);
        }
        if (titleSlotFramesElapsed(work + 0x18) != 0) {
            titleFreeSpriteNodes(work + 0x18);
            menu->state.signedValue = menu->nextState;
        }
        break;
    case 4:
        result = radarItemMenuUpdate(work + 4, &itemChanged, work + 0x2BC);
        switch (result) {
        case 0:
            if (itemChanged != 0) {
                menu->activeMenus = 2;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    case 5:
        result = radarRecipientMenuUpdate((u32 *)(work + 4), &recipientChanged, work + 0x1EA4);
        switch (result) {
        case 0:
            if (recipientChanged != 0) {
                menu->activeMenus = 4;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    case 6:
        result = radarTransferMenuUpdate(work + 4, &equipmentChanged, work + 0x31DC);
        switch (result) {
        case 0:
            if (equipmentChanged != 0) {
                menu->activeMenus = 0x10;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    case 7:
        result = radarPersonaMenuUpdate(work + 4, &personaChanged, work + 0x5A8C);
        switch (result) {
        case 0:
            if (personaChanged != 0) {
                menu->activeMenus = 0x20;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    case 8:
        result = radarUpdateState((u32 *)(work + 4), &otherChanged, work + 0x7750);
        switch (result) {
        case 0:
            if (otherChanged != 0) {
                menu->activeMenus = 0x40;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    case 10:
        result = cmpSystemMenuUpdate((u32 *)(work + 4), &systemChanged, work + 0x9000);
        switch (result) {
        case 0:
            if (systemChanged != 0) {
                menu->activeMenus = 0x80;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    case 9:
        result = datCommunityMenuStep(work + 4, &communityChanged, work + 0x4774);
        switch (result) {
        case 0:
            if (communityChanged != 0) {
                menu->activeMenus = 8;
            }
            break;
        case 1:
            menu->detailState = 0;
            menu->state.signedValue = 1;
            break;
        case 2:
            menu->activeMenus = 0;
            return -1;
        }
        break;
    }
    return 0;
}

/* Release the currently active submenu, restore rendering and free the camp work block. */
// FUN_0012CC50
void cmpMainTaskDestroy(u8 *task) {
    u8 *work;
    u32 state;

    work = ((SdkTask *)task)->work;
    nLineSelectSet(0);
    nLineSetActive(0);
    state = *(u32 *)work;
    switch (state) {
    case 0:
    case 1:
    case 2:
        titleFreeSpriteNodes(work + 0x18);
        break;
    case 4:
        radarFreeSpriteNodes(work + 0x2BC);
        break;
    case 5:
        cmpSkillFreeSprites(work + 0x1EA4);
        break;
    case 6:
        radarReleaseSpritesAndEntries(work + 0x31DC);
        break;
    case 7:
        cmpPersonaMenuRelease(work + 0x5A8C);
        break;
    case 8:
        radarDestroy(work + 0x7750);
        break;
    case 10:
        cmpSystemMenuRelease(work + 0x9000);
        break;
    case 9:
        datCommunityMenuRelease(work + 0x4774);
        break;
    case 13:
        /* Retail's jump-table entry 13 targets the post-switch tail directly, so
           this case is EMPTY and must stay a separate label: folding it into the
           assert group below makes entry 13 point at the assert instead, which
           every per-function check still passes -- the instructions are identical
           and only the table DATA differs, so it surfaces solely as a one-word
           image mismatch at link time. */
        break;
    case 11:
    case 12:
    default:
        kAssertFail(D_005E5890, 0x223);
        break;
    }
    resrcMngUnsuppressRender();
    jtbl_008873EC[0](work);
    iGpffffb1ec = 0;
}

/* measured: without opt_propagation off, the D_00887300 table address is reloaded at every call;
 * retail loads the base once and keeps it in a register. */
#pragma opt_propagation off

/* Update enabled submenu animations with render state 0xE temporarily disabled. */
// FUN_0012CD90
void cmpMainUpdateMenus(void) {
    CmpMainWork *menu;
    void (**renderStateSetters)(s32, s32);
    s32 savedRenderState;
    s32 result;
    u8 *work;

    result = 1;
    work = iGpffffb1ec;
    menu = (CmpMainWork *)work;
    if (work != NULL) {
        D_00887304[0](0xE, &savedRenderState);
        renderStateSetters = D_00887300;
        renderStateSetters[0](0xE, 0);
        if (menu->activeMenus & 1) {
            result = titleSlotUpdateAndDraw(work + 0x18);
            if (result != 0) {
                menu->activeMenus &= ~1;
            }
        }
        if (menu->activeMenus & 2) {
            result = radarStepSlotAnimA(work + 0x2BC);
            if (result != 0) {
                menu->activeMenus &= ~2;
            }
        }
        if (menu->activeMenus & 4) {
            result = cmpSkillMenuUpdate(work + 0x1EA4);
            if (result != 0) {
                menu->activeMenus &= ~4;
            }
        }
        if (menu->activeMenus & 8) {
            result = datCommunityPanelUpdate(work + 0x4774);
            if (result != 0) {
                menu->activeMenus &= ~8;
            }
        }
        if (menu->activeMenus & 0x10) {
            result = cmpEquipMenuUpdate(work + 0x31DC);
            if (result != 0) {
                menu->activeMenus &= ~0x10;
            }
        }
        if (menu->activeMenus & 0x20) {
            result = cmpPersonaMenuUpdate(work + 0x5A8C);
            if (result != 0) {
                menu->activeMenus &= ~0x20;
            }
        }
        if (menu->activeMenus & 0x40) {
            result = radarUpdateFrame(work + 0x7750);
            if (result != 0) {
                menu->activeMenus &= ~0x40;
            }
        }
        if (menu->activeMenus & 0x80) {
            result = datCommunityMenuUpdate(work + 0x9000);
            if (result != 0) {
                menu->activeMenus &= ~0x80;
            }
        }
        if ((menu->state.signedValue == 0xD) && (result != 0)) {
            menu->closingDone = 1;
        }
        renderStateSetters[0](0xE, savedRenderState);
    }
}
#pragma opt_propagation on

/* Allocate the camp work block and register its child task and ordering-table callback. */
// FUN_0012D000
s32 cmpMainTaskCreate(s32 parentTask, s16 flags) {
    s32 task;
    u8 *work;

    chkmemAllocSiteTag(D_005E5890, 0x27E);
    work = (u8 *)D_008873F4[0](1, 0x9740, 0x40000);
    if (iGpffffb1ec != 0) {
        kAssertFail(D_005E5890, 0x27F);
    }
    iGpffffb1ec = work;
    if (work == NULL) {
        return 0;
    }
    ((CmpMainWork *)work)->flags = flags;
    task = (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(&iGpffff9cb8), 0xC7, 0, 0, cmpMainTaskStep, cmpMainTaskDestroy, (u8 *)(work));
    nLineSelectSet(0);
    nLineSetActive(1);
    memset(work + 0x970C, 0, 0x30);
    ((CmpMainWork *)work)->drawCallback = (s32)cmpMainUpdateMenus;
    ((CmpMainWork *)work)->nodeContext = 0;
    cmpMainSetDefaultTableIndex();
    return task;
}

// FUN_0012D140
void cmpMainSetDefaultTableIndex(void) {
    ((CmpMainWork *)iGpffffb1ec)->tableIndex = 0xB1;
}

/* Free the asset-loader task work after its resource requests finish. */
// FUN_0012D160
void cmpAssetLoaderDestroy(u8 *task) {
    jtbl_008873EC[0]((void *)((SdkTask *)task)->work);
}

/* Declared here because kwlnTaskCreate below takes this function's address as a
   callback. */
s32 cmpAssetLoaderStep(u8 *);

/* Load the camp directory, request six sprites, then wait until every sprite is ready. */
// FUN_0012D190
s32 cmpAssetLoaderStep(u8 *task) {
    s32 requestIndex;
    s32 readyIndex;
    s32 result;
    u8 *work;
    CmpAssetLoaderWork *menu;
    u8 *slotBase;
    u8 *spriteSlot;

    work = ((SdkTask *)task)->work;
    menu = (CmpAssetLoaderWork *)work;
    switch (menu->state) {
    case 0:
        goto state0;
    case 1:
        goto state1;
    case 2:
        goto state2;
    default:
        goto fail;
    }

state0:
    func_00440b68(&iGpffff9cc0, D_005E5890, 0x2F8);
    menu->directory = H_Cdvd_AcquireDirectory(D_005E58A0, 1);
    if (menu->directory == NULL) {
        kAssertFail(D_005E5890, 0x2F9);
    }
    menu->state += 1;

state1:
    if (H_Cdvd_IsFileLoaded(menu->directory) != 0) {
        for (requestIndex = 0; requestIndex < 6; requestIndex++) {
            slotBase = work + requestIndex * 4;
            spriteSlot = slotBase + 0x1C;
            *(s32 *)spriteSlot = sdkSpriteCreateFromName(((CmpAssetLoaderWork *)(slotBase))->resourceNames[0]);
            if (*(s32 *)spriteSlot == 0) {
                kAssertFail(D_005E5890, 0x30C);
            }
        }
        menu->state += 1;
    } else {
        goto fail;
    }

state2:
    for (readyIndex = 0; readyIndex < 6; readyIndex++) {
        if (hMaestroDecodeIsReady(((CmpAssetLoaderWork *)(work + readyIndex * 4))->sprites[0]) != 0) {
        } else {
            result = 0;
            goto done;
        }
    }
    H_Cdvd_Destroy(menu->directory);
    menu->directory = NULL;
    result = -1;
    goto done;

fail:
    result = 0;

done:
    return result;
}
/* Create the loader task and seed its six resource names. */
// FUN_0012D320
s32 cmpAssetLoaderTaskCreate(void) {
    s32 task;
    u8 *work;
    CmpAssetLoaderWork *menu;

    chkmemAllocSiteTag(D_005E5890, 0x32C);
    work = (u8 *)D_008873F4[0](1, 0x38, 0x40000);
    if (work == NULL) {
        return 0;
    }
    task = (s32)kwlnTaskCreate((const void *)(D_005E58B0), 0xF, 0, 0, cmpAssetLoaderStep, cmpAssetLoaderDestroy, (u8 *)(work));
    *(u16 *)work = 0;
    *(u8 **)&((CmpAssetLoaderWork *)work)->resourceNames[0] = D_005E5830;
    *(u8 **)&((CmpAssetLoaderWork *)work)->resourceNames[1] = D_005E5850;
    *(u8 **)&((CmpAssetLoaderWork *)work)->resourceNames[2] = D_005E57F0;
    *(u8 **)&((CmpAssetLoaderWork *)work)->resourceNames[3] = D_005E5810;
    *(u8 **)&((CmpAssetLoaderWork *)work)->resourceNames[4] = D_005E5870;
    *(u8 **)&((CmpAssetLoaderWork *)work)->resourceNames[5] = D_005E5880;
    return task;
}

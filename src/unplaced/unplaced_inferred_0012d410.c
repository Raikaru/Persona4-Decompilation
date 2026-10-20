
#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "byte_address_internal.h"
#include "radar_menu_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
/* Layout tables supply target position, opacity, scale and transition frames. */
typedef struct TitleSlotTarget {
    f32 x, y;
    u8 alpha;
    u8 pad9;
    u16 scale;
    s32 startFrame, endFrame;
} TitleSlotTarget;

typedef struct RadarSlotTarget {
    f32 x, y;
    f32 scaleX, scaleY;
    u8 alpha;
    u8 pad11[3];
    s32 startFrame, endFrame;
} RadarSlotTarget;

extern u8 *resourceFindByName(char *name);
extern s32 titleSlotSetMode(u8 *, s32 );
extern void sdkSpriteFreeNode(void *node);
extern s32 nLineIsIdle(void);
extern void radarAnimateValue(u8 *, s32 , s32 );
extern void datCommunityEntryStep(u8 *);
extern void radarDrawPanel(u8 *);
extern void radarStepSlotAnimB(u8 *);
extern void radarStepPairAnim(u8 *);
extern void kAssertFail(const void *file, s32 line);
extern s32 datItemCount(s16 itemId);
extern u8 D_005E76C8[];
extern void memset(void *, s32 , s32 );
extern s16 datBuildPartyIdList(void *);
extern u8 *sdkSpriteNewNode(u32 packAddress, u32 recordIndex);
extern u8 D_005E5F40[];
extern u8 D_005E7670[];
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern u8 D_005E76C8[];
extern void titleCollectFlaggedIds(u8 *);
extern s32 titleSetMenuLayout(u8 *, u32 );
#include "btl_shuffle_draw_internal.h"
typedef struct Code12FrameVector { f32 x, y, z; } Code12FrameVector;

typedef union Code12FrameVectorTransfer {
    struct { s64 xy; f32 z; } words;
    f32 value[3];
    Code12FrameVector vector;
} Code12FrameVectorTransfer;

#pragma push
#pragma optimization_level 2
/* Change the selected title slot, preserve the old selection and start layout mode 2. */
// FUN_0012DB80
s32 titleSelectSlot(u8 *menu, s32 selection)
{
    if (selection != ((TitleSlotMenu *)menu)->selection) {
        sdkSndStartStream(0, 1, 0, 0);
        ((TitleSlotMenu *)menu)->previousSelection = ((TitleSlotMenu *)menu)->selection;
        ((TitleSlotMenu *)menu)->selection = selection;
        ((TitleSlotMenu *)menu)->mode = -1;
        titleSlotSetMode(menu, 2);
    }
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* measured: retail hoists loop invariants out of the wrap loop. */
#pragma opt_loop_invariants on
/* Set slot transition endpoints for adjacent moves and wraparound selection. */
// FUN_0012DC00
void titleLayoutSlots(u8 *menu)
{
    s32 previousSelection;
    s32 slotCount;
    s32 selection;
    s32 selectionDelta;
    s32 lastSlot;
    s32 reverseWrap;
    s32 slotIndex;
    s32 reverseIndex;
    s32 wrapIndex;
    s32 opaqueAlpha;
    f32 targetX;
    f32 targetY;
    s32 halfAlpha;
    s32 endFrame;
    MenuSlotAnimation *previousCursor;
    MenuSlotAnimation *previousCursorReverse;
    MenuSlotAnimation *selectedCursor;
    MenuSlotAnimation *selectedCursorReverse;
    MenuSlotAnimation *slotCursor;
    MenuSlotAnimation *selectedWrapCursor;
    MenuSlotAnimation *otherWrapCursor;
    MenuSlotAnimation *selectedReverseCursor;
    MenuSlotAnimation *otherReverseCursor;

    selection = ((TitleSlotMenu *)menu)->selection;
    previousSelection = ((TitleSlotMenu *)menu)->previousSelection;
    slotCount = ((TitleSlotMenu *)menu)->slotCount;
    lastSlot = slotCount - 1;
    reverseWrap = -lastSlot;
    selectionDelta = selection - previousSelection;
    slotIndex = 0;
    goto loop_0012dc00_2_check;
loop_0012dc00_2_body:
    slotCursor = (MenuSlotAnimation *)((u8 *)((slotIndex * 0x30) + menu) + 0x94);
    slotCursor->startFrame.s = 0;
    slotCursor->endFrame.s = 0;
    slotIndex += 1;
loop_0012dc00_2_check:
    if (slotIndex < 0xB) {
        goto loop_0012dc00_2_body;
    }
    if (selectionDelta == 1) {
        previousCursor = (MenuSlotAnimation *)((u8 *)((u8 *)(s32)byteAddressAdd(previousSelection * 0x30, (u8 *)((s32)(u32)menu))) + 0x94);
        previousCursor->targetX.s = 0;
        previousCursor->startY.s = 0;
        previousCursor->targetY.s = 0;
        previousCursor->startAlpha.u = 0xFF;
        previousCursor->targetAlpha = 0xFF;
        previousCursor->endFrame.s = 0;
        selectedCursor = (MenuSlotAnimation *)((u8 *)((u8 *)(s32)byteAddressAdd(selection * 0x30, (u8 *)((s32)(u32)menu))) + 0x94);
        selectedCursor->targetX.s = 0;
        selectedCursor->startY.s = (s32)0xC1700000;
        selectedCursor->targetY.s = (s32)0x40B00000;
        selectedCursor->startAlpha.s = 0x7F;
        selectedCursor->targetAlpha = 0xFF;
        selectedCursor->endFrame.s = 3;
        ((TitleSlotMenu *)menu)->slots[10].startY.s = (s32)0x3F800000;
        ((TitleSlotMenu *)menu)->slots[10].targetY.s = (s32)0x3F800000;
    } else if (selectionDelta == -1) {
        previousCursorReverse = (MenuSlotAnimation *)((u8 *)((u8 *)(s32)byteAddressAdd(previousSelection * 0x30, (u8 *)((s32)(u32)menu))) + 0x94);
        previousCursorReverse->targetX.s = 0;
        previousCursorReverse->startY.s = 0;
        previousCursorReverse->targetY.s = 0;
        previousCursorReverse->startAlpha.u = 0xFF;
        previousCursorReverse->targetAlpha = 0xFF;
        previousCursorReverse->endFrame.s = 0;
        selectedCursorReverse = (MenuSlotAnimation *)((u8 *)((u8 *)(s32)byteAddressAdd(selection * 0x30, (u8 *)((s32)(u32)menu))) + 0x94);
        selectedCursorReverse->targetX.s = 0;
        selectedCursorReverse->startY.s = (s32)0x41700000;
        selectedCursorReverse->targetY.s = (s32)0xC0B00000;
        selectedCursorReverse->startAlpha.s = 0x7F;
        selectedCursorReverse->targetAlpha = 0xFF;
        selectedCursorReverse->endFrame.s = 3;
        ((TitleSlotMenu *)menu)->slots[10].startY.s = 0;
        ((TitleSlotMenu *)menu)->slots[10].targetY.s = 0;
    } else if (selectionDelta == lastSlot) {
        wrapIndex = 0;
        opaqueAlpha = 0xFF;
        targetX = -15.0f;
        targetY = 5.5f;
        halfAlpha = 0x7F;
        endFrame = 3;
        goto loop_0012dc00_13_check;
loop_0012dc00_13_body:
        if (wrapIndex == selection) {
            selectedWrapCursor = (MenuSlotAnimation *)((u8 *)((u8 *)(((s32)(u32)menu) + (wrapIndex * 0x30))) + 0x94);
            selectedWrapCursor->startY.f = targetX;
            selectedWrapCursor->targetY.f = targetY;
            selectedWrapCursor->startAlpha.s = halfAlpha;
            selectedWrapCursor->targetAlpha = opaqueAlpha;
            selectedWrapCursor->endFrame.s = endFrame;
        } else {
            otherWrapCursor = (MenuSlotAnimation *)((u8 *)((u8 *)(((s32)(u32)menu) + (wrapIndex * 0x30))) + 0x94);
            otherWrapCursor->targetX.s = 0;
            otherWrapCursor->startY.s = 0;
            otherWrapCursor->targetY.s = 0;
            otherWrapCursor->startAlpha.u = opaqueAlpha;
            otherWrapCursor->targetAlpha = opaqueAlpha;
            otherWrapCursor->endFrame.s = 0;
        }
        wrapIndex += 1;
loop_0012dc00_13_check:
        if (wrapIndex < slotCount) {
            goto loop_0012dc00_13_body;
        }
        ((TitleSlotMenu *)menu)->slots[10].startY.s = (s32)0x3F800000;
        ((TitleSlotMenu *)menu)->slots[10].targetY.s = (s32)0x3F800000;
    } else if (selectionDelta == reverseWrap) {
        reverseIndex = 0;
        opaqueAlpha = 0xFF;
        targetX = 15.0f;
        targetY = -5.5f;
        endFrame = 3;
        goto loop_0012dc00_21_check;
loop_0012dc00_21_body:
        if (reverseIndex == selection) {
            selectedReverseCursor = (MenuSlotAnimation *)((u8 *)((u8 *)(((s32)(u32)menu) + (reverseIndex * 0x30))) + 0x94);
            selectedReverseCursor->startY.f = targetX;
            selectedReverseCursor->targetY.f = targetY;
            selectedReverseCursor->startAlpha.s = 0;
            selectedReverseCursor->targetAlpha = opaqueAlpha;
            selectedReverseCursor->endFrame.s = endFrame;
        } else {
            otherReverseCursor = (MenuSlotAnimation *)((u8 *)((u8 *)(((s32)(u32)menu) + (reverseIndex * 0x30))) + 0x94);
            otherReverseCursor->targetX.s = 0;
            otherReverseCursor->startY.s = 0;
            otherReverseCursor->targetY.s = 0;
            otherReverseCursor->startAlpha.u = opaqueAlpha;
            otherReverseCursor->targetAlpha = opaqueAlpha;
            otherReverseCursor->endFrame.s = 0;
        }
        reverseIndex += 1;
loop_0012dc00_21_check:
        if (reverseIndex < slotCount) {
            goto loop_0012dc00_21_body;
        }
        ((TitleSlotMenu *)menu)->slots[10].startY.s = 0;
        ((TitleSlotMenu *)menu)->slots[10].targetY.s = 0;
    }
    ((TitleSlotMenu *)menu)->frame = 0;
}
#pragma pop

extern u8 D_005E58C0[];
extern u8 D_005E59A0[];
extern u8 D_005E5A80[];
extern void titleLayoutSlots(u8 *menu);
#pragma push
#pragma optimization_level 2
/* measured: retail hoists loop invariants out of the target-table loops. */
#pragma opt_loop_invariants on
/* Snapshot eleven slot animations and set the target table for the requested mode. */
// FUN_0012DEA0
s32 titleSlotSetMode(u8 *menu, s32 mode)
{
    s32 i;
    s32 i0;
    s32 i1;
    s32 i3;
    u8 *p;
    u8 *src0;
    u8 *dst0;
    u8 *src1;
    u8 *dst1;
    u8 *src3;
    u8 *dst3;
    TitleSlotMenu *slotMenu = (TitleSlotMenu *)(menu);

    if (((TitleSlotMenu *)(menu))->mode == mode) {
        return 0;
    }
    slotMenu->mode = mode;
    ((TitleSlotMenu *)(menu))->frame = 0;
    i = 0;
    while (i < 0xB) {
        p = menu + i * 0x30;
        ((TitleSlotMenu *)(p))->slots[0].startX.f = ((TitleSlotMenu *)(p))->slots[0].currentX.f;
        ((TitleSlotMenu *)(p))->slots[0].startY.f = ((TitleSlotMenu *)(p))->slots[0].currentY.f;
        ((TitleSlotMenu *)(p))->slots[0].startAlpha.u = ((TitleSlotMenu *)(p))->slots[0].currentAlpha;
        ((TitleSlotMenu *)(p))->slots[0].startScaleX = ((TitleSlotMenu *)(p))->slots[0].currentScaleX;
        ((TitleSlotMenu *)(p))->slots[0].startScaleY = ((TitleSlotMenu *)(p))->slots[0].currentScaleY;
        i++;
    }
    switch (mode) {
    case 0:
        i0 = 0;
        while (i0 < 0xB) {
            if (i0 != ((TitleSlotMenu *)(menu))->selection) {
                src0 = D_005E58C0 + i0 * 0x14;
                dst0 = menu + i0 * 0x30;
                ((TitleSlotMenu *)(dst0))->slots[0].targetX.f = ((TitleSlotTarget *)(src0))->x;
                ((TitleSlotMenu *)(dst0))->slots[0].targetY.f = ((TitleSlotTarget *)(src0))->y;
                ((TitleSlotMenu *)(dst0))->slots[0].targetAlpha = ((TitleSlotTarget *)(src0))->alpha;
                ((TitleSlotMenu *)(dst0))->slots[0].targetScaleY = ((TitleSlotTarget *)(src0))->scale;
                ((TitleSlotMenu *)(dst0))->slots[0].startFrame.s = ((TitleSlotTarget *)(src0))->startFrame;
                ((TitleSlotMenu *)(dst0))->slots[0].endFrame.s = ((TitleSlotTarget *)(src0))->endFrame;
            } else {
                dst0 = menu + i0 * 0x30;
                ((TitleSlotMenu *)(dst0))->slots[0].startX.s = 0;
                ((TitleSlotMenu *)(dst0))->slots[0].targetX.s = 0;
                ((TitleSlotMenu *)(dst0))->slots[0].startY.s = 0x41B80000;
                ((TitleSlotMenu *)(dst0))->slots[0].targetY.s = 0;
                ((TitleSlotMenu *)(dst0))->slots[0].startAlpha.u = 0;
                ((TitleSlotMenu *)(dst0))->slots[0].targetAlpha = 0xFF;
                ((TitleSlotMenu *)(dst0))->slots[0].startScaleY = 1;
                ((TitleSlotMenu *)(dst0))->slots[0].targetScaleY = 0x1000;
                ((TitleSlotMenu *)(dst0))->slots[0].startFrame.s = 0xB;
                ((TitleSlotMenu *)(dst0))->slots[0].endFrame.s = 0xD;
            }
            i0++;
        }
        break;
    case 1:
        i1 = 0;
        while (i1 < 0xB) {
            src1 = D_005E59A0 + i1 * 0x14;
            dst1 = menu + i1 * 0x30;
            ((TitleSlotMenu *)(dst1))->slots[0].targetX.f = ((TitleSlotTarget *)(src1))->x;
            ((TitleSlotMenu *)(dst1))->slots[0].targetY.f = ((TitleSlotTarget *)(src1))->y;
            ((TitleSlotMenu *)(dst1))->slots[0].targetAlpha = ((TitleSlotTarget *)(src1))->alpha;
            ((TitleSlotMenu *)(dst1))->slots[0].targetScaleY = ((TitleSlotTarget *)(src1))->scale;
            ((TitleSlotMenu *)(dst1))->slots[0].startFrame.s = ((TitleSlotTarget *)(src1))->startFrame;
            ((TitleSlotMenu *)(dst1))->slots[0].endFrame.s = ((TitleSlotTarget *)(src1))->endFrame;
            i1++;
        }
        break;
    case 2:
        titleLayoutSlots(menu);
        break;
    case 3:
        i3 = 0;
        while (i3 < 0xB) {
            dst3 = menu + i3 * 0x30;
            ((TitleSlotMenu *)(dst3))->slots[0].startX.s = 0;
            ((TitleSlotMenu *)(dst3))->slots[0].startY.s = 0;
            src3 = D_005E5A80 + i3 * 0x14;
            ((TitleSlotMenu *)(dst3))->slots[0].targetX.f = ((TitleSlotTarget *)(src3))->x;
            ((TitleSlotMenu *)(dst3))->slots[0].targetY.f = ((TitleSlotTarget *)(src3))->y;
            ((TitleSlotMenu *)(dst3))->slots[0].targetAlpha = ((TitleSlotTarget *)(src3))->alpha;
            ((TitleSlotMenu *)(dst3))->slots[0].targetScaleY = ((TitleSlotTarget *)(src3))->scale;
            ((TitleSlotMenu *)(dst3))->slots[0].startFrame.s = ((TitleSlotTarget *)(src3))->startFrame;
            ((TitleSlotMenu *)(dst3))->slots[0].endFrame.s = ((TitleSlotTarget *)(src3))->endFrame;
            i3++;
        }
        break;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Free all 21 sprite nodes in the title selector. */
// FUN_0012E150
void titleFreeSpriteNodes(s32 menuAddress)
{
    s32 sprite;
    s32 spriteIndex;
    u8 *spriteCursor;
    u8 *spriteSlot;

    spriteIndex = 0;
    while (spriteIndex < 0x15) {
        spriteCursor = (u8 *)(menuAddress + (spriteIndex * 4));
        spriteSlot = spriteCursor + 0x3C;
        sprite = *(s32 *)spriteSlot;
        if (sprite != 0) {
            sdkSpriteFreeNode((void *)sprite);
            *(s32 *)spriteSlot = 0;
        }
        spriteIndex += 1;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Report whether all eleven slot end frames have elapsed and the external line is idle. */
// FUN_0012E1D0
s32 titleSlotFramesElapsed(u8 *menu)
{
    s32 settled = 1;
    s32 slotIndex = 0;
    s32 frame = ((TitleSlotMenu *)menu)->frame;

    while (slotIndex < 0xB) {
        if (frame < ((TitleSlotMenu *)menu)->slots[slotIndex].endFrame.s) {
            settled = 0;
        }
        slotIndex += 1;
    }
    return settled & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Treat modes 1/2 as settled; otherwise check all slot end frames and line idleness. */
// FUN_0012E250
s32 titleSlotsSettled(u8 *menu)
{
    s32 mode = ((TitleSlotMenu *)menu)->mode;
    s32 settled = 1;
    s32 slotIndex;
    s32 frame;

    if (mode == settled) {
        goto block_early;
    }
    if (mode != 2) {
        goto block_loop;
    }
block_early:
    return 1;
block_loop:
    slotIndex = 0;
    frame = ((TitleSlotMenu *)menu)->frame;
    while (slotIndex < 0xB) {
        if (frame < ((TitleSlotMenu *)menu)->slots[slotIndex].endFrame.s) {
            settled = 0;
        }
        slotIndex += 1;
    }
    return settled & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* measured: retail hoists loop invariants out of the initialization loops. */
#pragma opt_loop_invariants on
/* Initialize the 0x1BE8-byte radar menu, its animation arrays, inventory and sprite nodes. */
// FUN_0012E2F0
s32 titleStateInit(u8 *menu)
{
    s16 i;
    s16 j;
    s16 k;
    s16 m;
    s16 n;
    u8 *target;
    u8 *slotCursor;
    u8 *value;
    u8 *defaultTargets;
    u8 *itemSprites;
    u8 *badgeSprites;
    u8 *extraSprites;
    u8 *spriteSlot;
    s32 resource;
    s32 resourceValue;
    s32 resourceResult;
    s32 resourceState;
    u16 scale;
    s32 spriteIndex;
    s16 ii;

    memset(menu, 0, 0x1BE8);
    ((RadarMenu *)(menu))->x.s = 0;
    ((RadarMenu *)(menu))->y.s = 0;
    ((RadarMenu *)menu)->opacity = 0xFF;
    ((RadarMenu *)(menu))->layout = -1;
    ((RadarMenu *)(menu))->entryFrame = 0;
    ((RadarMenu *)(menu))->mode = 0;
    for (i = 0; i < 3; i++) {
        ((RadarMenu *)(menu + (i * 2)))->selection[0] = 0;
    }
    j = 0;
    defaultTargets = D_005E5F40;
    for (; j < 30; j++) {
        target = defaultTargets + (j * 0x1C);
        slotCursor = menu + (j * 0x30);
        ((RadarMenu *)(slotCursor))->entries[0].currentX.f = ((RadarSlotTarget *)target)->x;
        ((RadarMenu *)(slotCursor))->entries[0].currentY.f = ((RadarSlotTarget *)(target))->y;
        ((RadarMenu *)(slotCursor))->entries[0].currentAlpha = ((RadarSlotTarget *)(target))->alpha;
        scale = (u16)((RadarSlotTarget *)(target))->scaleX;
        ((RadarMenu *)(slotCursor))->entries[0].currentScaleX = scale;
        scale = (u16)((RadarSlotTarget *)(target))->scaleY;
        ((RadarMenu *)(slotCursor))->entries[0].currentScaleY = scale;
    }
    for (k = 0; k < 12; k++) {
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].currentX.s = 0;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].startX.s = 0;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].targetY.s = -1027080192;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].startY.s = -1027080192;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].targetAlpha = 127;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].startAlpha.u = 127;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].startFrame.s = 0;
        ((RadarMenu *)(menu + (k * 0x30)))->scatter[0].endFrame.s = 10;
    }
    for (m = 0; m < 84; m++) {
        ((RadarMenu *)(menu + (m * 0x14)))->grid[0].column = m % 7;
        ((RadarMenu *)(menu + (m * 0x14)))->grid[0].columns = 7;
        ((RadarMenu *)(menu + (m * 0x14)))->grid[0].row = m / 7;
        ((RadarMenu *)(menu + (m * 0x14)))->grid[0].rows = 12;
    }
    for (n = 0; n < 2; n++) {
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].currentX.s = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].startX.s = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].targetY.s = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].startY.s = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].targetAlpha = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].startAlpha.u = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].startFrame.s = 0;
        ((RadarMenu *)(menu + (n * 0x30)))->indicators[0].endFrame.s = 3;
    }
    ((RadarMenu *)(menu))->partyCount = datBuildPartyIdList(menu + 0x34);
    itemSprites = (u8 *)resourceFindByName((char *)D_005E5830);
    if (itemSprites == NULL) {
        kAssertFail(D_005E76C8, 0x1FA);
    }
    badgeSprites = (u8 *)resourceFindByName((char *)D_005E5850);
    if (badgeSprites == NULL) {
        kAssertFail(D_005E76C8, 0x1FC);
    }
    resource = (s32)resourceFindByName((char *)D_005E57F0);
    extraSprites = (u8 *)resource;
    ((RadarMenu *)menu)->spritePack = (u8 *)resource;
    if (extraSprites == NULL) {
        kAssertFail(D_005E76C8, 0x1FE);
    }
    ii = 0;
    while (ii < 51) {
        if (ii < 28) {
            spriteSlot = menu + (ii * 4) + 0x1B18;
            spriteIndex = D_005E7670[ii];
            resource = (s32)sdkSpriteNewNode((u32)itemSprites, spriteIndex);
            *(s32 *)spriteSlot = resource;
        } else if (ii < 49) {
            spriteSlot = menu + (ii * 4) + 0x1B18;
            spriteIndex = D_005E7670[ii];
            resource = (s32)sdkSpriteNewNode((u32)badgeSprites, spriteIndex);
            *(s32 *)spriteSlot = resource;
        } else {
            spriteSlot = menu + (ii * 4) + 0x1B18;
            spriteIndex = D_005E7670[ii];
            resource = (s32)sdkSpriteNewNode((u32)extraSprites, spriteIndex);
            *(s32 *)spriteSlot = resource;
        }
        if (*(s32 *)spriteSlot == 0) {
            kAssertFail(D_005E76C8, 0x20B);
        }
        ii++;
    }
    titleCollectFlaggedIds(menu);
    return titleSetMenuLayout(menu, 0);
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Collect held item IDs 0x300..0x5FF and their counts into the inventory list. */
// FUN_0012E7C0
void titleCollectFlaggedIds(u8 *menu)
{
    s32 itemId;
    s32 itemIndex;
    s64 itemCount;
    s16 candidateIndex;
    s16 entryCount;
    RadarInventoryEntry *entryCursor;

    entryCount = 0;
    candidateIndex = 0;
    goto loop_test;
loop_body:
    itemId = (s32)itemIndex + 0x300;
    itemCount = (s64)(s16)(datItemCount(itemId) & 0xFF);
    if (itemCount != 0) {
        entryCursor = &((RadarMenu *)menu)->inventory[(s16)entryCount];
        entryCursor->id = (s16)itemId;
        entryCursor->count = (s16)itemCount;
        entryCount += 1;
    }
    candidateIndex += 1;
loop_test:
    itemIndex = candidateIndex;
    if (itemIndex < 0x300) {
        goto loop_body;
    }
    ((RadarMenu *)menu)->inventoryCount = entryCount;
    if (entryCount <= 0x300) {
        goto guard_done;
    }
    kAssertFail(D_005E76C8, 0x225);
guard_done:
    ;
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Advance mode 0 to 1 and report whether the menu is in either wait mode. */
// FUN_0012E8B0
s32 titleAdvanceWait(u8 *menu)
{
    s32 mode;
    RadarMenu *radarMenu = (RadarMenu *)(menu);

    mode = ((RadarMenu *)(menu))->mode;
    switch (mode) {
    case 0:
        radarMenu->mode = mode + 1;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Advance the thirty entry animations, then the scatter, indicator and draw passes. */
// FUN_0012E900
s32 radarStepSlotAnimA(u8 *menu) {
    s16 frame;
    s32 slotIndex;
    s32 settled;
    u8 *slotCursor;
    RadarMenu *radarMenu = (RadarMenu *)(menu);

    settled = 1;
    frame = ((RadarMenu *)(menu))->entryFrame;
    if (frame < 0x64) {
        radarMenu->entryFrame = frame + 1;
    }
    slotIndex = 0;
    goto loop_test_0012e900;
loop_body_0012e900:
    slotCursor = menu + (slotIndex * 0x30);
    radarAnimateValue(slotCursor + 0x12D8, radarMenu->entryFrame, 0);
    if (((RadarMenu *)(slotCursor))->entries[0].currentAlpha != 0) {
        settled = 0;
    }
    slotIndex += 1;
loop_test_0012e900:
    if (slotIndex < 0x1E) {
        goto loop_body_0012e900;
    }
    radarStepSlotAnimB(menu);
    radarStepPairAnim(menu);
    radarDrawPanel(menu);
    return settled;
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Advance twelve scatter animations and update all 84 grid entries. */
// FUN_0012FDF0
void radarStepSlotAnimB(u8 *menu)
{
    s16 frame;
    s32 slotIndex;
    s32 gridIndex;
    u8 *slotCursor;
    RadarMenu *radarMenu = (RadarMenu *)(menu);

    frame = ((RadarMenu *)(menu))->scatterFrame;
    if (frame < 0x64) {
        frame += 1;
        radarMenu->scatterFrame = frame;
    }
    for (slotIndex = 0; slotIndex < 0xC; slotIndex++) {
        slotCursor = menu + (slotIndex * 0x30);
        radarAnimateValue(slotCursor + 0x1878, radarMenu->scatterFrame, 0);
    }
    for (gridIndex = 0; gridIndex < 0x54; gridIndex++) {
        slotCursor = menu + (gridIndex * 0x14);
        datCommunityEntryStep(slotCursor + 0xC48);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* measured: a typed menu local stops the counter address from being cached, matching retail.
 * Advance the two indicator animations with the shared capped frame counter. */
/* Advance the shared indicator frame counter, capped at 100, and animate both indicators with it. */
// FUN_0012FEB0
void radarStepPairAnim(u8 *menu)
{
    s32 i;
    u8 *p;
    s32 v;
    RadarMenu *radarMenu = (RadarMenu *)menu;

    v = radarMenu->indicatorFrame;
    if (v < 0x64) {
        radarMenu->indicatorFrame = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = menu + i * 0x30 + 0x1AB8;
        radarAnimateValue(p, radarMenu->indicatorFrame, 0);
    }
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* The selection is passed as a word; the field stores its low halfword. */
/* Push one of three selection halfwords into its previous-selection slot. */
// FUN_0012FF40
s32 radarPushHistoryValue(s32 menuAddress, s32 selectionIndex, s32 selection)
{
    u8 *p;

    p = (u8 *)(s32)byteAddressAdd(selectionIndex * 2, (u8 *)(menuAddress));
    ((RadarMenu *)(p))->previousSelection[0] = ((RadarMenu *)(p))->selection[0];
    ((RadarMenu *)(p))->selection[0] = selection;
    return 1;
}
#pragma pop

extern u8 D_005E5BF0[];
extern u8 D_005E6290[];
extern u8 D_005E65E0[];
extern u8 D_005E6930[];
extern u8 D_005E6C80[];
extern u8 D_005E6FD0[];
extern u8 D_005E7320[];
#pragma push
#pragma optimization_level 2
/* Snapshot thirty entries and apply the layout table, flags and target animation values. */
// FUN_0012FF60
s32 titleSetMenuLayout(u8 *menu, u32 layout)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;
    RadarMenu *radarMenu = (RadarMenu *)(menu);

    table = 0;
    if (layout == ((RadarMenu *)(menu))->layout) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        dst = menu + (i * 0x30);
        ((RadarMenu *)(dst))->entries[0].startX.f = ((RadarMenu *)(dst))->entries[0].currentX.f;
        ((RadarMenu *)(dst))->entries[0].startY.f = ((RadarMenu *)(dst))->entries[0].currentY.f;
        ((RadarMenu *)(dst))->entries[0].startScaleX = ((RadarMenu *)(dst))->entries[0].currentScaleX;
        ((RadarMenu *)(dst))->entries[0].startScaleY = ((RadarMenu *)(dst))->entries[0].currentScaleY;
        ((RadarMenu *)(dst))->entries[0].startAlpha.u = ((RadarMenu *)(dst))->entries[0].currentAlpha;
    }
    switch (layout) {
    case 0:
        ((RadarMenu *)(menu))->flags = 0x447;
        table = D_005E5BF0;
        ((RadarMenu *)(menu))->unkC40 = 0x13;
        break;
    case 1:
        table = D_005E5F40;
        break;
    case 2:
        ((RadarMenu *)(menu))->flags = 0x547;
        table = D_005E6290;
        ((RadarMenu *)(menu))->unkC40 = 0x13;
        break;
    case 3:
        ((RadarMenu *)(menu))->flags = 0x447;
        table = D_005E6290;
        ((RadarMenu *)(menu))->unkC40 = 0x13;
        break;
    case 4:
        ((RadarMenu *)(menu))->flags = 0x2dd;
        table = D_005E65E0;
        ((RadarMenu *)(menu))->previousSelection[2] = ((RadarMenu *)(menu))->selection[2];
        ((RadarMenu *)(menu))->selection[2] = 0;
        ((RadarMenu *)(menu))->entries[8].startY.f = 34.0f * (f32)((RadarMenu *)(menu))->selection[0];
        ((RadarMenu *)(menu))->unkC40 = 0;
        break;
    case 5:
        ((RadarMenu *)(menu))->flags = 0x2ed;
        table = D_005E6C80;
        ((RadarMenu *)(menu))->entries[8].startY.f = 34.0f * (f32)((RadarMenu *)(menu))->selection[0];
        ((RadarMenu *)(menu))->unkC40 = 0;
        break;
    case 6:
        ((RadarMenu *)(menu))->flags = 0x29d;
        table = D_005E6930;
        ((RadarMenu *)(menu))->unkC40 = 0;
        break;
    case 7:
        ((RadarMenu *)(menu))->flags = 0x2ad;
        table = D_005E6FD0;
        ((RadarMenu *)(menu))->unkC40 = 0;
        break;
    case 8:
        ((RadarMenu *)(menu))->flags = 0x547;
        table = D_005E7320;
        ((RadarMenu *)(menu))->unkC40 = 0x14;
        break;
    case 9:
        ((RadarMenu *)(menu))->flags = 0x547;
        table = D_005E7320;
        ((RadarMenu *)(menu))->unkC40 = 0x14;
        break;
    default:
        kAssertFail(D_005E76C8, 0x4ab);
        break;
    }
/* measured: retail hoists loop invariants out of the layout-table copy loop. */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 30; j++) {
            src = table + (j * 0x1c);
            dst = menu + (j * 0x30);
            ((RadarMenu *)(dst))->entries[0].targetX.f = ((RadarSlotTarget *)(src))->x;
            ((RadarMenu *)(dst))->entries[0].targetY.f = ((RadarSlotTarget *)(src))->y;
            ((RadarMenu *)(dst))->entries[0].targetAlpha = ((RadarSlotTarget *)(src))->alpha;
            value = ((RadarSlotTarget *)(src))->scaleX;
            ((RadarMenu *)(dst))->entries[0].targetScaleX = (u16)value;
            value = ((RadarSlotTarget *)(src))->scaleY;
            ((RadarMenu *)(dst))->entries[0].targetScaleY = (u16)value;
            ((RadarMenu *)(dst))->entries[0].startFrame.s = ((RadarSlotTarget *)(src))->startFrame;
            ((RadarMenu *)(dst))->entries[0].endFrame.s = ((RadarSlotTarget *)(src))->endFrame;
        }
        radarMenu->layout = layout;
        ((RadarMenu *)(menu))->entryFrame = 0;
    }
    return 1;
}
#pragma pop

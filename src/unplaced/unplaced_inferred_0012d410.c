/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0012db80-0012ff60 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "radar_menu_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
static inline s32 code1_0012_stride(s32 index, s32 base)
{
    return index + base;
}

static inline s32 code1_0012_stride_loop(s32 base, s32 index)
{
    return base + index;
}

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
#pragma opt_propagation on
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
#pragma opt_propagation on
#pragma optimization_level 2
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
        previousCursor = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride(previousSelection * 0x30, (s32)(u32)menu)) + 0x94);
        previousCursor->targetX.s = 0;
        previousCursor->startY.s = 0;
        previousCursor->targetY.s = 0;
        previousCursor->startAlpha.u = 0xFF;
        previousCursor->targetAlpha = 0xFF;
        previousCursor->endFrame.s = 0;
        selectedCursor = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride(selection * 0x30, (s32)(u32)menu)) + 0x94);
        selectedCursor->targetX.s = 0;
        selectedCursor->startY.s = (s32)0xC1700000;
        selectedCursor->targetY.s = (s32)0x40B00000;
        selectedCursor->startAlpha.s = 0x7F;
        selectedCursor->targetAlpha = 0xFF;
        selectedCursor->endFrame.s = 3;
        ((TitleSlotMenu *)menu)->slots[10].startY.s = (s32)0x3F800000;
        ((TitleSlotMenu *)menu)->slots[10].targetY.s = (s32)0x3F800000;
    } else if (selectionDelta == -1) {
        previousCursorReverse = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride(previousSelection * 0x30, (s32)(u32)menu)) + 0x94);
        previousCursorReverse->targetX.s = 0;
        previousCursorReverse->startY.s = 0;
        previousCursorReverse->targetY.s = 0;
        previousCursorReverse->startAlpha.u = 0xFF;
        previousCursorReverse->targetAlpha = 0xFF;
        previousCursorReverse->endFrame.s = 0;
        selectedCursorReverse = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride(selection * 0x30, (s32)(u32)menu)) + 0x94);
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
            selectedWrapCursor = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride_loop((s32)(u32)menu, wrapIndex * 0x30)) + 0x94);
            selectedWrapCursor->startY.f = targetX;
            selectedWrapCursor->targetY.f = targetY;
            selectedWrapCursor->startAlpha.s = halfAlpha;
            selectedWrapCursor->targetAlpha = opaqueAlpha;
            selectedWrapCursor->endFrame.s = endFrame;
        } else {
            otherWrapCursor = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride_loop((s32)(u32)menu, wrapIndex * 0x30)) + 0x94);
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
            selectedReverseCursor = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride_loop((s32)(u32)menu, reverseIndex * 0x30)) + 0x94);
            selectedReverseCursor->startY.f = targetX;
            selectedReverseCursor->targetY.f = targetY;
            selectedReverseCursor->startAlpha.s = 0;
            selectedReverseCursor->targetAlpha = opaqueAlpha;
            selectedReverseCursor->endFrame.s = endFrame;
        } else {
            otherReverseCursor = (MenuSlotAnimation *)((u8 *)((u8 *)code1_0012_stride_loop((s32)(u32)menu, reverseIndex * 0x30)) + 0x94);
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
/* Snapshot eleven slot animations and set the target table for the requested mode. */
// FUN_0012DEA0
/* Raw offsets preserve the measured match: TitleSlotMenu access changed codegen (nd 468). */
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

    if (*(s32 *)(menu + 0x18) == mode) {
        return 0;
    }
    *(s32 *)(menu + 0x18) = mode;
    *(s16 *)(menu + 0xC) = 0;
    i = 0;
    while (i < 0xB) {
        p = menu + i * 0x30;
        *(f32 *)(p + 0x94) = *(f32 *)(p + 0xA4);
        *(f32 *)(p + 0x98) = *(f32 *)(p + 0xA8);
        *(u8 *)(p + 0xAC) = *(u8 *)(p + 0xAE);
        *(u16 *)(p + 0xB0) = *(u16 *)(p + 0xB4);
        *(u16 *)(p + 0xB6) = *(u16 *)(p + 0xBA);
        i++;
    }
    switch (mode) {
    case 0:
        i0 = 0;
        while (i0 < 0xB) {
            if (i0 != *(s32 *)(menu + 0x10)) {
                src0 = D_005E58C0 + i0 * 0x14;
                dst0 = menu + i0 * 0x30;
                *(f32 *)(dst0 + 0x9C) = *(f32 *)(src0 + 0);
                *(f32 *)(dst0 + 0xA0) = *(f32 *)(src0 + 4);
                *(u8 *)(dst0 + 0xAD) = *(u8 *)(src0 + 8);
                *(u16 *)(dst0 + 0xB8) = *(u16 *)(src0 + 0xA);
                *(s32 *)(dst0 + 0xBC) = *(s32 *)(src0 + 0xC);
                *(s32 *)(dst0 + 0xC0) = *(s32 *)(src0 + 0x10);
            } else {
                dst0 = menu + i0 * 0x30;
                *(s32 *)(dst0 + 0x94) = 0;
                *(s32 *)(dst0 + 0x9C) = 0;
                *(s32 *)(dst0 + 0x98) = 0x41B80000;
                *(s32 *)(dst0 + 0xA0) = 0;
                *(u8 *)(dst0 + 0xAC) = 0;
                *(u8 *)(dst0 + 0xAD) = 0xFF;
                *(u16 *)(dst0 + 0xB6) = 1;
                *(u16 *)(dst0 + 0xB8) = 0x1000;
                *(s32 *)(dst0 + 0xBC) = 0xB;
                *(s32 *)(dst0 + 0xC0) = 0xD;
            }
            i0++;
        }
        break;
    case 1:
        i1 = 0;
        while (i1 < 0xB) {
            src1 = D_005E59A0 + i1 * 0x14;
            dst1 = menu + i1 * 0x30;
            *(f32 *)(dst1 + 0x9C) = *(f32 *)(src1 + 0);
            *(f32 *)(dst1 + 0xA0) = *(f32 *)(src1 + 4);
            *(u8 *)(dst1 + 0xAD) = *(u8 *)(src1 + 8);
            *(u16 *)(dst1 + 0xB8) = *(u16 *)(src1 + 0xA);
            *(s32 *)(dst1 + 0xBC) = *(s32 *)(src1 + 0xC);
            *(s32 *)(dst1 + 0xC0) = *(s32 *)(src1 + 0x10);
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
            *(s32 *)(dst3 + 0x94) = 0;
            *(s32 *)(dst3 + 0x98) = 0;
            src3 = D_005E5A80 + i3 * 0x14;
            *(f32 *)(dst3 + 0x9C) = *(f32 *)(src3 + 0);
            *(f32 *)(dst3 + 0xA0) = *(f32 *)(src3 + 4);
            *(u8 *)(dst3 + 0xAD) = *(u8 *)(src3 + 8);
            *(u16 *)(dst3 + 0xB8) = *(u16 *)(src3 + 0xA);
            *(s32 *)(dst3 + 0xBC) = *(s32 *)(src3 + 0xC);
            *(s32 *)(dst3 + 0xC0) = *(s32 *)(src3 + 0x10);
            i3++;
        }
        break;
    }
    return 1;
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants on
#pragma opt_rebuildconditionals off
/* Initialize the 0x1BE8-byte radar menu, its animation arrays, inventory and sprite nodes. */
// FUN_0012E2F0
/* Raw offsets preserve the measured match: RadarMenu array accesses changed codegen (nd 712). */
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
    *(s32 *)(menu + 4) = 0;
    *(s32 *)(menu + 8) = 0;
    *(u8 *)menu = 0xFF;
    *(s32 *)(menu + 0x30) = -1;
    *(s16 *)(menu + 0x1C) = 0;
    *(s32 *)(menu + 0x18) = 0;
    for (i = 0; i < 3; i++) {
        *(s16 *)(menu + (i * 2) + 0x22) = 0;
    }
    j = 0;
    defaultTargets = D_005E5F40;
    for (; j < 30; j++) {
        target = defaultTargets + (j * 0x1C);
        slotCursor = menu + (j * 0x30);
        *(f32 *)(slotCursor + 0x12E8) = *(f32 *)target;
        *(f32 *)(slotCursor + 0x12EC) = *(f32 *)(target + 4);
        *(u8 *)(slotCursor + 0x12F2) = *(u8 *)(target + 0x10);
        scale = (u16)*(f32 *)(target + 8);
        *(u16 *)(slotCursor + 0x12F8) = scale;
        scale = (u16)*(f32 *)(target + 0xC);
        *(u16 *)(slotCursor + 0x12FE) = scale;
    }
    for (k = 0; k < 12; k++) {
        *(s32 *)(menu + (k * 0x30) + 0x1888) = 0;
        *(s32 *)(menu + (k * 0x30) + 0x1878) = 0;
        *(s32 *)(menu + (k * 0x30) + 0x1884) = -1027080192;
        *(s32 *)(menu + (k * 0x30) + 0x187C) = -1027080192;
        *(u8 *)(menu + (k * 0x30) + 0x1891) = 127;
        *(u8 *)(menu + (k * 0x30) + 0x1890) = 127;
        *(s32 *)(menu + (k * 0x30) + 0x18A0) = 0;
        *(s32 *)(menu + (k * 0x30) + 0x18A4) = 10;
    }
    for (m = 0; m < 84; m++) {
        *(s32 *)(menu + (m * 0x14) + 0xC4C) = m % 7;
        *(s32 *)(menu + (m * 0x14) + 0xC54) = 7;
        *(s32 *)(menu + (m * 0x14) + 0xC50) = m / 7;
        *(s32 *)(menu + (m * 0x14) + 0xC58) = 12;
    }
    for (n = 0; n < 2; n++) {
        *(s32 *)(menu + (n * 0x30) + 0x1AC8) = 0;
        *(s32 *)(menu + (n * 0x30) + 0x1AB8) = 0;
        *(s32 *)(menu + (n * 0x30) + 0x1AC4) = 0;
        *(s32 *)(menu + (n * 0x30) + 0x1ABC) = 0;
        *(u8 *)(menu + (n * 0x30) + 0x1AD1) = 0;
        *(u8 *)(menu + (n * 0x30) + 0x1AD0) = 0;
        *(s32 *)(menu + (n * 0x30) + 0x1AE0) = 0;
        *(s32 *)(menu + (n * 0x30) + 0x1AE4) = 3;
    }
    *(s16 *)(menu + 0x3C) = datBuildPartyIdList(menu + 0x34);
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
    *(u8 **)(menu + 0x1BE4) = (u8 *)resource;
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
#pragma opt_propagation off
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
/* Advance mode 0 to 1 and report whether the menu is in either wait mode. */
// FUN_0012E8B0
/* Raw offsets preserve the measured match: RadarMenu access changed codegen (nd 45). */
s32 titleAdvanceWait(u8 *menu)
{
    s32 mode;

    mode = *(s32 *)(menu + 0x18);
    switch (mode) {
    case 0:
        *(s32 *)(menu + 0x18) = mode + 1;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
/* Advance the thirty entry animations, then the scatter, indicator and draw passes. */
// FUN_0012E900
/* Raw offsets preserve the measured match: RadarMenu access changed codegen (nd 162). */
s32 radarStepSlotAnimA(u8 *menu) {
    s16 frame;
    s32 slotIndex;
    s32 settled;
    u8 *slotCursor;

    settled = 1;
    frame = *(s16 *)(menu + 0x1C);
    if (frame < 0x64) {
        *(s16 *)(menu + 0x1C) = frame + 1;
    }
    slotIndex = 0;
    goto loop_test_0012e900;
loop_body_0012e900:
    slotCursor = menu + (slotIndex * 0x30);
    radarAnimateValue(slotCursor + 0x12D8, *(s16 *)(menu + 0x1C), 0);
    if (*(u8 *)(slotCursor + 0x12F2) != 0) {
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
/* Advance twelve scatter animations and update all 84 grid entries. */
// FUN_0012FDF0
/* Raw offsets preserve the measured match: RadarMenu access changed codegen (nd 147). */
void radarStepSlotAnimB(u8 *menu)
{
    s16 frame;
    s32 slotIndex;
    s32 gridIndex;
    u8 *slotCursor;

    frame = *(s16 *)(menu + 0x1E);
    if (frame < 0x64) {
        frame += 1;
        *(s16 *)(menu + 0x1E) = frame;
    }
    for (slotIndex = 0; slotIndex < 0xC; slotIndex++) {
        slotCursor = menu + (slotIndex * 0x30);
        radarAnimateValue(slotCursor + 0x1878, *(s16 *)(menu + 0x1E), 0);
    }
    for (gridIndex = 0; gridIndex < 0x54; gridIndex++) {
        slotCursor = menu + (gridIndex * 0x14);
        datCommunityEntryStep(slotCursor + 0xC48);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
#pragma opt_common_subs off
/* Advance the two indicator animations with the shared capped frame counter. */
// FUN_0012FEB0
void radarStepPairAnim(u8 *menu)
{
    s32 i;
    u8 *p;
    s32 v;

    v = ((RadarMenu *)menu)->indicatorFrame;
    if (v < 0x64) {
        ((RadarMenu *)menu)->indicatorFrame = v + 1;
    }
    for (i = 0; i < 2; i++) {
        p = menu + i * 0x30 + 0x1AB8;
        radarAnimateValue(p, ((RadarMenu *)menu)->indicatorFrame, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
#pragma opt_common_subs on
/* The selection is passed as a word; the field stores its low halfword. */
/* Push one of three selection halfwords into its previous-selection slot. */
// FUN_0012FF40
/* Raw offsets preserve the measured match: RadarMenu selection arrays changed codegen (nd 1). */
s32 radarPushHistoryValue(s32 menuAddress, s32 selectionIndex, s32 selection)
{
    u8 *p;

    p = (u8 *)code1_0012_stride(selectionIndex * 2, menuAddress);
    *(s16 *)(p + 0x28) = *(s16 *)(p + 0x22);
    *(s16 *)(p + 0x22) = selection;
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
#pragma opt_propagation on
#pragma optimization_level 2
#pragma opt_loop_invariants off
#pragma opt_rebuildconditionals on
#pragma opt_common_subs off
/* Snapshot thirty entries and apply the layout table, flags and target animation values. */
// FUN_0012FF60
/* Raw offsets preserve the measured match: RadarMenu/RadarSlotTarget access changed codegen (nd 663). */
s32 titleSetMenuLayout(u8 *menu, u32 layout)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    table = 0;
    if (layout == *(u32 *)(menu + 0x30)) {
        return 0;
    }
    for (i = 0; i < 30; i++) {
        dst = menu + (i * 0x30);
        *(f32 *)(dst + 0x12d8) = *(f32 *)(dst + 0x12e8);
        *(f32 *)(dst + 0x12dc) = *(f32 *)(dst + 0x12ec);
        *(u16 *)(dst + 0x12f4) = *(u16 *)(dst + 0x12f8);
        *(u16 *)(dst + 0x12fa) = *(u16 *)(dst + 0x12fe);
        *(u8 *)(dst + 0x12f0) = *(u8 *)(dst + 0x12f2);
    }
    switch (layout) {
    case 0:
        *(s32 *)(menu + 0x14) = 0x447;
        table = D_005E5BF0;
        *(s16 *)(menu + 0xc40) = 0x13;
        break;
    case 1:
        table = D_005E5F40;
        break;
    case 2:
        *(s32 *)(menu + 0x14) = 0x547;
        table = D_005E6290;
        *(s16 *)(menu + 0xc40) = 0x13;
        break;
    case 3:
        *(s32 *)(menu + 0x14) = 0x447;
        table = D_005E6290;
        *(s16 *)(menu + 0xc40) = 0x13;
        break;
    case 4:
        *(s32 *)(menu + 0x14) = 0x2dd;
        table = D_005E65E0;
        *(s16 *)(menu + 0x2c) = *(s16 *)(menu + 0x26);
        *(s16 *)(menu + 0x26) = 0;
        *(f32 *)(menu + 0x145c) = 34.0f * (f32)*(s16 *)(menu + 0x22);
        *(s16 *)(menu + 0xc40) = 0;
        break;
    case 5:
        *(s32 *)(menu + 0x14) = 0x2ed;
        table = D_005E6C80;
        *(f32 *)(menu + 0x145c) = 34.0f * (f32)*(s16 *)(menu + 0x22);
        *(s16 *)(menu + 0xc40) = 0;
        break;
    case 6:
        *(s32 *)(menu + 0x14) = 0x29d;
        table = D_005E6930;
        *(s16 *)(menu + 0xc40) = 0;
        break;
    case 7:
        *(s32 *)(menu + 0x14) = 0x2ad;
        table = D_005E6FD0;
        *(s16 *)(menu + 0xc40) = 0;
        break;
    case 8:
        *(s32 *)(menu + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(menu + 0xc40) = 0x14;
        break;
    case 9:
        *(s32 *)(menu + 0x14) = 0x547;
        table = D_005E7320;
        *(s16 *)(menu + 0xc40) = 0x14;
        break;
    default:
        kAssertFail(D_005E76C8, 0x4ab);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table-loop constants and
   stride calculations into retail's preheader (without it, nd is nonzero). */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 30; j++) {
            src = table + (j * 0x1c);
            dst = menu + (j * 0x30);
            *(f32 *)(dst + 0x12e0) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0x12e4) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0x12f1) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0x12f6) = (u16)value;
            value = *(f32 *)(src + 0xc);
            *(u16 *)(dst + 0x12fc) = (u16)value;
            *(s32 *)(dst + 0x1300) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0x1304) = *(s32 *)(src + 0x18);
        }
        *(u32 *)(menu + 0x30) = layout;
        *(s16 *)(menu + 0x1c) = 0;
    }
    return 1;
}
#pragma pop

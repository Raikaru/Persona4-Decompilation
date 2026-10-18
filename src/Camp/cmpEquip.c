#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"

void radarAnimateValue(void *, s32, s32);
void cmpEquipStepTabAnimations(u8 *);
void cmpEquipMenuDraw(u8 *);
s16 datGetEquippedItemByUnit(s16, s16);
s32 datItemCount(s16 id);
s32 datEntryHasFlag(s16, s16);
s32 datIdBand(s16);
s16 datBuildMemberIdListExcluding5(void *);
void memset(void *, s32, s32);
void *resourceFindByName(void *);
s32 sdkSpriteNewNode(void *, s8);
void kAssertFail(void *, s32);
extern u8 D_005E5830[];
extern u8 D_005E5850[];
extern u8 D_005E57F0[];
extern s8 D_005E76E0[];
extern u8 D_005E7BA0[];
extern u8 D_005E7720[];
extern u8 D_005E8020[];
extern u8 D_005E84A0[];
extern u8 D_005E8920[];
extern u8 D_005E8DA0[];
extern u8 D_005E9220[];
extern u8 D_005E96A0[];
extern u8 D_005E9B20[];
extern u8 D_005E9FA0[];
extern u8 D_0064B2E0[];
extern u8 D_0064B2E4[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F4[];
/* The initializer clears 0x1598 bytes. Item records have a four-byte stride;
 * the transition copier establishes 41 row motions followed by three tab motions. */
typedef struct { s16 id, quantity; } CmpEquipListEntry;
typedef struct {
    f32 startX, startY, targetX, targetY, x, y;
    u8 startAlpha, targetAlpha, alpha, unk1B;
    u16 startWidth, targetWidth, width, startHeight, targetHeight, height;
    s32 startFrame, endFrame;
} CmpEquipMotion;
typedef struct {
    f32 x, y, width, height;
    u8 alpha;
    u8 pad11[3];
    s32 startFrame, endFrame;
} CmpEquipLayoutRow;
typedef struct {
    u8 alpha;
    u8 pad01[3];
    f32 x, y;
    u8 pad0C[4];
    s32 background, phase, mode;
    u32 visible;
    s16 frame, angle, tabFrame;
    u8 pad26[2];
    s16 selection[4], previousSelection[4];
    s16 partyIds[8];
    s16 partyCount;
    CmpEquipListEntry items[767];
    s16 itemCount;
    s16 equipped[8][3];
    s16 footerMode, pendingItem, unkC7C, labelId;
    CmpEquipMotion motion[41];
    CmpEquipMotion tabMotion[3];
    s32 sprites[52];
    s32 footerTexture;
    u8 pad1594[4];
} CmpEquipWork;
typedef char CmpEquipWorkSize[sizeof(CmpEquipWork) == 0x1598 ? 1 : -1];
/* measured: both initializers hoist the conversion constants and table bases. */
#pragma opt_loop_invariants on
/* measured: initializer conversion and table setup match the retail window. */
/* Initialize the equipment list, party equipment snapshots, motion records and sprite resources. */
// FUN_001312B0
void cmpEquipMenuInit(u8 *workArea)
{
    s16 equipmentIndex;
    s16 value;
    s32 offset;
    void *asset0;
    void *asset1;
    void *asset2;
    u8 *base;
    s32 *slot;
    s16 spriteIndex;
    s16 selectionIndex;
    s16 tabIndex;
    s16 motionIndex;
    s16 partyIndex;
    s16 equippedId;
    f32 dimension;
    s8 byte;

    memset(workArea, 0, 0x1598);
    base = workArea;
    *(s32 *)&((CmpEquipWork *)base)->x = 0;
    *(s32 *)&((CmpEquipWork *)base)->y = 0;
    *(u8 *)base = 0xFF;
    ((CmpEquipWork *)base)->mode = -1;
    ((CmpEquipWork *)base)->phase = 0;

    for (selectionIndex = 0; selectionIndex < 4; selectionIndex++) {
        ((CmpEquipWork *)(base + selectionIndex * 2))->selection[0] = 0;
    }
    for (motionIndex = 0; motionIndex < 0x29; motionIndex++) {
        offset = motionIndex * 0x1C;
        ((CmpEquipWork *)(base + motionIndex * 0x30))->motion[0].x = ((CmpEquipLayoutRow *)(D_005E7BA0 + offset))->x;
        ((CmpEquipWork *)(base + motionIndex * 0x30))->motion[0].y = ((CmpEquipLayoutRow *)(D_005E7BA0 + offset))->y;
        ((CmpEquipWork *)(base + motionIndex * 0x30))->motion[0].alpha = ((CmpEquipLayoutRow *)(D_005E7BA0 + offset))->alpha;
        dimension = ((CmpEquipLayoutRow *)(D_005E7BA0 + offset))->width;
        ((CmpEquipWork *)(base + motionIndex * 0x30))->motion[0].width = (u16)dimension;
        dimension = ((CmpEquipLayoutRow *)(D_005E7BA0 + offset))->height;
        ((CmpEquipWork *)(base + motionIndex * 0x30))->motion[0].height = (u16)dimension;
    }
    for (tabIndex = 0; tabIndex < 3; tabIndex++) {
        *(s32 *)&((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].x = 0;
        *(s32 *)&((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].startX = 0;
        *(s32 *)&((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].targetY = 0;
        *(s32 *)&((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].startY = 0;
        ((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].targetAlpha = 0;
        ((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].startAlpha = 0;
        ((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].startFrame = 0;
        ((CmpEquipWork *)(base + tabIndex * 0x30))->tabMotion[0].endFrame = 3;
    }
    value = datBuildMemberIdListExcluding5(base + 0x38);
    ((CmpEquipWork *)base)->partyCount = value;
    for (partyIndex = 0; partyIndex < ((CmpEquipWork *)base)->partyCount; partyIndex++) {
        value = ((CmpEquipWork *)(base + partyIndex * 2))->partyIds[0];
        equipmentIndex = 0;
        slot = (s32 *)(base + partyIndex * 6);
        while (equipmentIndex < 3) {
            equippedId = datGetEquippedItemByUnit(value, equipmentIndex);
            ((CmpEquipWork *)slot)->equipped[0][equipmentIndex] = equippedId;
            equipmentIndex++;
        }
    }
    cmpEquipSetMode(base, 0);
    asset0 = resourceFindByName(D_005E5830);
    if (asset0 == 0) {
        kAssertFail(D_005E9FA0, 0x26A);
    }
    asset1 = resourceFindByName(D_005E5850);
    if (asset1 == 0) {
        kAssertFail(D_005E9FA0, 0x26C);
    }
    ((CmpEquipWork *)base)->footerTexture = (s32)(asset2 = resourceFindByName(D_005E57F0));
    if (asset2 == 0) {
        kAssertFail(D_005E9FA0, 0x26E);
    }
    for (spriteIndex = 0; spriteIndex < 0x34; spriteIndex++) {
        if (spriteIndex < 0x29) {
            slot = &((CmpEquipWork *)base)->sprites[spriteIndex];
            byte = D_005E76E0[spriteIndex];
            *slot = sdkSpriteNewNode(asset0, byte);
        } else if (spriteIndex < 0x33) {
            slot = &((CmpEquipWork *)base)->sprites[spriteIndex];
            byte = D_005E76E0[spriteIndex];
            *slot = sdkSpriteNewNode(asset1, byte);
        } else {
            slot = &((CmpEquipWork *)base)->sprites[spriteIndex];
            byte = D_005E76E0[spriteIndex];
            *slot = sdkSpriteNewNode(asset2, byte);
        }
        if (*slot == 0) {
            kAssertFail(D_005E9FA0, 0x27B);
        }
    }
}

/* Build the compatible equipment list, including the selected member's equipped item in its quantity. */
// FUN_00131730
/* The halfword-indexed work view preserves EE address-add operand order;
 * the CmpEquipWork rewrite changed two instruction bytes and was reverted. */
void cmpEquipBuildItemList(s16 *workArea) {
    s16 i;
    s16 count;
    s16 id;
    s32 type;
    s64 equipmentType;
    s32 found;
    s32 filter;
    s16 value;
    s16 *entry;

    id = workArea[workArea[20] + 28];
    type = workArea[21];
    equipmentType = type;
    for (i = 0, count = 0; i < 0x2FF; i++) {
        found = i == datGetEquippedItemByUnit(id, equipmentType);
        if (!found) {
            filter = (u8)datItemCount((s16)i) != 0;
            if (filter) {
                filter = datEntryHasFlag(i, id) != 0;
            }
            if (filter) {
                filter = (s32)type == datIdBand(i);
            }
            if (!filter) {
                goto skip;
            }
        }
        value = found + (u8)datItemCount((s16)i);
        if (value > 99) {
            value = 99;
        }
        entry = &workArea[2 * count];
        entry[37] = i;
        entry[38] = value;
        count++;
    skip:
        ;
    }
    workArea[1571] = count;
    if (count > 0x2FF) {
        kAssertFail(D_005E9FA0, 0x299);
    }
}
// Advances the menu state from 0 to 1; returns 1 for states 0 and 1, 0 otherwise [inferred].
// FUN_001318C0
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpEquipWork rewrite changed 45 instruction bytes and was reverted. */
s32 cmpEquipStateStep(u8 *workArea) {
    s32 v = *(s32 *)(workArea + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(workArea + 0x14) = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

/* Advance row and tab animations, draw the equipment menu, and report whether all rows are transparent. */
// FUN_00131910
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpEquipWork rewrite changed 179 instruction bytes and was reverted. */
s32 cmpEquipMenuUpdate(u8 *workArea) {
    s32 i;
    s32 rv;
    u8 *p;

    rv = 1;
    if (*(s16 *)(workArea + 0x20) < 0x64) {
        *(s16 *)(workArea + 0x20) = *(s16 *)(workArea + 0x20) + 1;
    }
    for (i = 0; i < 0x29; i++) {
        p = workArea + i * 0x30;
        radarAnimateValue(p + 0xC80, *(s16 *)(workArea + 0x20), 0);
        if (*(u8 *)(p + 0xC9A) != 0) {
            rv = 0;
        }
    }
    *(s16 *)(workArea + 0x22) = *(s16 *)(workArea + 0x22) + 1;
    if (*(s16 *)(workArea + 0x22) >= 0x168) {
        *(s16 *)(workArea + 0x22) = 0;
    }
    cmpEquipStepTabAnimations(workArea);
    cmpEquipMenuDraw(workArea);
    return rv;
}
/* Equipment-menu renderer. Whole-owner MWCCPS2 b210 -O2 match (2026-09-30):
 * 10920 bytes plus the retail window's 8-byte zero tail; frame 0x110.
 * Byte/halfword conversion and coordinate snapshots preserve the retail ABI.
 * The two local records hold logical actor/opacity snapshots only. Pointer
 * address accumulation below uses the EE's 32-bit unsigned address domain.
 * opt_lifetimes retains the original call-crossing values; dead assignments
 * remain enabled. Both settings are scoped to this function.
 */
// FUN_00131A00
#pragma push
#pragma opt_lifetimes on
#pragma opt_dead_assignments on
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpEquipWork rewrite changed 8450 instruction bytes and was reverted. */
void cmpEquipMenuDraw(u8 *workArea)

{
    typedef struct { f32 x, y; } Vec2f;
    typedef union { Vec2f xy; s64 packed; } PackedVec2f;
    PackedVec2f drawPosition;
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2f workArea, s32, s32, f32);
    extern void sdkSpriteDrawAt(void *workArea, f32, f32, u8, u8, u8, u8);
    extern void sdkSpriteDrawSized(u8 *workArea, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    extern void datEntryDrawRow(Vec2f workArea, f32, u8, u8 *);
    extern void datEntryReset(u8 *workArea);
    extern u32 datEntryGetFlags(s16 workArea);
    extern s16 datGetEquippedItemByUnit(s16 workArea, s16);
    extern u32 datPersonaNamePart1(s16 workArea);
    extern s32 radarFlagToIconMode(s32 workArea);
    extern void radarDrawPalettePair(u8 *workArea, s64 , s64 , u8);
    extern void radarDrawPaletteSet(u8 *workArea, s64 , s64 , u8);
    extern void radarDrawItemCard(u8 *workArea, s64 , u8, u8 *);
    extern void radarDrawHeaderFrame(u8 *workArea, PackedVec2f , u8, u16);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 extra);
    extern void sdkSpriteDrawFooter(Vec2f workArea, f32, u8, s32, s32);
    extern void kAssertFail(void *workArea, s32);
  s16 itemIndex;
  /* Logical snapshots of values preserved across the draw calls, not external layouts. */
  struct { s16 id; } actor;
  s16 rowValue;
  s16 selectedItemId;
  s8 labelStyle;
  s64 rowSelected;
  u8 alpha;
  struct { u8 value; } opacity;
  u8 *actorPalette;
  s16 rowIcon;
  u8 descriptorAlpha;
  u8 *spriteOrPalette;
  u8 *work;
  u8 *sprite;
  u8 *iconPalette;
  s16 *partyIds;
  u8 *drawSprite;
  typedef struct { u8 r, g, b, a; } CmpEquipColor;
  CmpEquipColor *palette;
  s16 quantity;
  u16 borderWidth;
  u16 borderHeight;
  u32 itemFlags;
  s32 packedColor;
  typedef struct { s16 itemId; s16 quantity; u16 pad04; s16 equippedItemId; u32 unk08; u32 unk0C; u32 unk10; u16 unk14; u16 style; u16 unk18; } CmpEquipItemDescriptor;
  CmpEquipItemDescriptor descriptor;
  s32 rowValueIndex;
  char *labelText;
  u16 borderMode;
  f32 opacityScale;
  f32 originX, originY;
  f32 alphaValue;
  f32 scrollbarY;
  f32 drawY;
  f32 scaleX;
  f32 scaleY;


  work = (u8 *)workArea;
  partyIds = (s16 *)(work + 0x38);
  actor.id = partyIds[*(s16 *)(work + 0x28)];
  sdkRenderStateSetDefault();
  originX = *(f32 *)(work + 4);
  originY = *(f32 *)(work + 8);
  opacityScale = (f32)*work / 255.0f;
  if (*(s32 *)(work + 0x10) != 0) {
    drawPosition.xy.x = originX;
    drawPosition.xy.y = originY;
    alphaValue = opacityScale * 255.0f;
    alpha = (u8)alphaValue;
    nLineDrawSet(drawPosition.xy,alpha,*(s32 *)(work + 0x10),0.0f);
  }
  if ((*(u32 *)(work + 0x1c) & 0x1000) != 0) {
    spriteOrPalette = *(u8 **)(work + 0x157c);
    *(u16 *)(spriteOrPalette + 0x1c) = 0x3d;
    *(u16 *)(spriteOrPalette + 0x1e) = 0x3f;
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1260) + (f32)0x212;
    drawPosition.xy.y = (originY + *(f32 *)(work + 0x1264)) - 3.0f;
    alphaValue = (f32)work[0x126a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    scaleX = (f32)*(u16 *)(work + 0x1270);
    scaleY = (f32)*(u16 *)(work + 0x1276);
    sdkSpriteDrawSized(spriteOrPalette,drawPosition.xy.x,drawPosition.xy.y,0.0f,0xff,0xff,0x81,alpha,(u16)scaleX,(u16)scaleY,0x3d,
                  (f32)(s32)*(s16 *)(work + 0x22),0x3f);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1290) + (f32)0x226;
    drawPosition.xy.y = (originY + *(f32 *)(work + 0x1294)) - 22.0f;
    alphaValue = (f32)work[0x129a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    scaleX = (f32)*(u16 *)(work + 0x12a0);
    scaleY = (f32)*(u16 *)(work + 0x12a6);
    sdkSpriteDrawSized(spriteOrPalette,drawPosition.xy.x,drawPosition.xy.y,0.0f,0xfb,0xa2,0,alpha,(u16)scaleX,(u16)scaleY,0x3d,
                  (f32)(s32)*(s16 *)(work + 0x22),0x3f);
  }
  if ((*(u32 *)(work + 0x1c) & 0x400) != 0) {
    sprite = *(u8 **)(work + 0x158c);
    drawPosition.xy.x = originX + *(f32 *)(work + 0xc90) + 20.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0xc94) + 358.0f;
    alphaValue = (f32)work[0xc9a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x800) != 0) {
    sprite = *(u8 **)(work + 0x158c);
    drawPosition.xy.x = originX + *(f32 *)(work + 0xcc0) + (f32)0x1D1;
    drawPosition.xy.y = originY + *(f32 *)(work + 0xcc4) + 20.0f;
    alphaValue = (f32)work[0xcca];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x80) != 0) {
    sprite = *(u8 **)(work + 0x1564);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x12c0) + 20.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x12c4) + (f32)0x195;
    alphaValue = (f32)work[0x12ca];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x100) != 0) {
    sprite = *(u8 **)(work + 0x1568);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x12f0) + 146.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x12f4) + (f32)0x195;
    alphaValue = (f32)work[0x12fa];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 0x200) != 0) {
    sprite = *(u8 **)(work + 0x1564);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1320) + 20.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1324) + (f32)0x195;
    alphaValue = (f32)work[0x132a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((*(u32 *)(work + 0x1c) & 4) != 0) {
    rowValueIndex = 0;
    while (rowValue = (s16)rowValueIndex, rowValue < *(s16 *)(work + 0x48)) {
      drawPosition.xy.x = originX + *(f32 *)(work + (s16)rowValueIndex * 0x30 + 0x1080) + 35.0f;
      {
      drawPosition.xy.y = 20.0f + (33.0f * (f32)rowValueIndex + (0.0f + (originY + *(f32 *)(work + (s16)rowValueIndex * 0x30 + 0x1084))));
      scaleX = (f32)*(u16 *)(work + (s16)rowValueIndex * 0x30 + 0x1090);
      scaleY = (f32)*(u16 *)(work + (s16)rowValueIndex * 0x30 + 0x1096);
      alphaValue = (f32)work[(s16)rowValueIndex * 0x30 + 0x108a];
    alphaValue *= opacityScale;
      opacity.value = (u8)alphaValue;
      packedColor = opacity.value | 0xffffff00;
      if (*(s16 *)(work + 0x28) == (s16)rowValueIndex) {
        actorPalette = D_0064B2E8;
        labelStyle = 8;
      }
      else {
        actorPalette = D_0064B2E0;
        labelStyle = 6;
      }
      drawSprite = *(u8 **)(work + 0x14c0);
      drawY = drawPosition.xy.y;
      sdkSpriteDrawSized(drawSprite,drawPosition.xy.x,drawY,0.0f,*actorPalette,actorPalette[1],actorPalette[2],
                    opacity.value,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      drawSprite = *(u8 **)(work + 0x14c4);
      sdkSpriteDrawSized(drawSprite,drawPosition.xy.x + 202.0f,drawY,0.0f,*actorPalette,actorPalette[1],
                    actorPalette[2],opacity.value,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      labelText = (char *)datPersonaNamePart1(*(s16 *)(work + rowValue * 2 + 0x38));
      frFontExDrawText(drawPosition.xy.x + 105.0f,drawY,0.0f,packedColor,labelStyle,1,labelText,8,0);
      }
      rowValueIndex = (s32)(s16)(rowValueIndex + 1);
    }
  }
  if ((*(u32 *)(work + 0x1c) & 0x10) != 0) {
    s16 rowCounter;
    u8 *spriteOrPalette;
    for (rowCounter = 0; rowCounter < 3; ++rowCounter) {
      rowSelected = 0;
      if ((*(u32 *)(work + 0x1c) & 0x20) != 0) {
        drawPosition.xy.x = originX + *(f32 *)(work + rowCounter * 0x30 + 0xf90) + 253.0f;
        drawPosition.xy.y = originY + *(f32 *)(work + rowCounter * 0x30 + 0xf94) + 190.0f +
                   (f32)(rowCounter * 0x3f);
        alphaValue = (f32)work[rowCounter * 0x30 + 0xf9a];
    alphaValue *= opacityScale;
        alpha = (u8)alphaValue;
        {
          s64 selectedMode;
          if (*(s16 *)(work + 0x2a) == rowCounter) {
            selectedMode = 1;
            rowSelected = selectedMode;
          } else {
            selectedMode = 0;
          }
          radarDrawPalettePair(work, drawPosition.packed, selectedMode, (u8)(alpha));
        }
      }
      drawPosition.xy.x = originX + *(f32 *)(work + rowCounter * 0x30 + 0xf00) + 253.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + rowCounter * 0x30 + 0xf04) + 190.0f +
                 (f32)(rowCounter * 0x3f);
      alphaValue = (f32)work[rowCounter * 0x30 + 0xf0a];
    alphaValue *= opacityScale;
      alpha = (u8)alphaValue;
      {
      scaleX = (f32)*(u16 *)(work + rowCounter * 0x30 + 0xf10);
      scaleY = (f32)*(u16 *)(work + rowCounter * 0x30 + 0xf16);
      switch (rowCounter) {
      case 0:
        itemFlags = datEntryGetFlags(datGetEquippedItemByUnit(actor.id, 0));
        rowValueIndex = radarFlagToIconMode(itemFlags);
        rowIcon = (s16)rowValueIndex;
        break;
      case 1:
        rowIcon = 0xe;
        break;
      case 2:
        rowIcon = 0xf;
        break;
      }
      if (rowSelected) {
        spriteOrPalette = D_0064B2EC;
        iconPalette = D_0064B2E8;
      }
      else {
        spriteOrPalette = D_0064B2E4;
        iconPalette = D_0064B2E0;
      }
      if (rowIcon < 0xe) {
        sprite = *(u8 **)(work + 0x14c8);
      }
      else {
        sprite = *(u8 **)(work + 0x14cc);
      }
      {
      drawY = drawPosition.xy.y;
      sdkSpriteDrawSized(sprite,drawPosition.xy.x,drawPosition.xy.y,0.0f,*spriteOrPalette,spriteOrPalette[1],spriteOrPalette[2],alpha,
                    (u16)scaleX,(u16)scaleY,0,0.0f,0);
      drawSprite = *(u8 **)(work + rowIcon * 4 + 0x14c0);
      sdkSpriteDrawSized(drawSprite,drawPosition.xy.x + 3.0f,drawY + 2.0f,0.0f,
                    *iconPalette,iconPalette[1],iconPalette[2],alpha,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      }
      }
      drawPosition.xy.x = originX + *(f32 *)(work + rowCounter * 0x30 + 0xe70) + 255.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + rowCounter * 0x30 + 0xe74) + 193.0f +
                 (f32)(rowCounter * 0x3f);
      alphaValue = (f32)work[rowCounter * 0x30 + 0xe7a];
    alphaValue *= opacityScale;
      alpha = (u8)alphaValue;
      drawSprite = *(u8 **)(work + rowCounter * 4 + 0x14d0);
      if (rowSelected) {
        spriteOrPalette = D_0064B2EC;
      }
      else {
        spriteOrPalette = D_0064B2E4;
      }
      sdkSpriteDrawAt(drawSprite,drawPosition.xy.x + 42.0f,drawPosition.xy.y + 1.0f,*spriteOrPalette,
                    spriteOrPalette[1],spriteOrPalette[2],alpha);
      drawPosition.xy.x = drawPosition.xy.x + 42.0f;
      drawPosition.xy.y = drawPosition.xy.y + 24.0f;
      alphaValue = (f32)work[rowCounter * 0x30 + 0xe7a];
    alphaValue *= opacityScale;
      descriptorAlpha = (u8)alphaValue;
      datEntryReset((u8 *)&descriptor);
      if ((*(u32 *)(work + 0x1c) & 0x20) != 0) {
        if (rowSelected) {
          descriptor.style = 3;
        } else {
          descriptor.style = 2;
        }
      } else {
        descriptor.style = 4;
      }
      descriptor.itemId = datGetEquippedItemByUnit(actor.id,rowCounter);
      descriptor.quantity = 0xffff;
      descriptor.unk08 = 0xffffffff;
      descriptor.unk0C = 1;
      descriptor.unk10 = 0;
      descriptor.unk14 = 0;
      descriptor.unk18 = 3;
      datEntryDrawRow(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
    }
  }
  if ((*(u32 *)(work + 0x1c) & 8) != 0) {
    f32 pairY, pairScaleX, pairScaleY;
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1200) + 35.0f;
    {
      drawPosition.xy.y = originY + *(f32 *)(work + 0x1204) + 20.0f;
    alphaValue = (f32)work[0x120a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    pairScaleX = (f32)*(u16 *)(work + 0x1210);
    pairScaleY = (f32)*(u16 *)(work + 0x1216);
    palette = (CmpEquipColor *)D_0064B2F4;
    drawSprite = *(u8 **)(work + 0x14c0);
    pairY = drawPosition.xy.y;
    sdkSpriteDrawSized(drawSprite,drawPosition.xy.x,pairY,0.0f,palette->r,palette->g,
                  palette->b,alpha,(u16)pairScaleX,(u16)pairScaleY,0,0.0f,0);
    drawSprite = *(u8 **)(work + 0x14c4);
    sdkSpriteDrawSized(drawSprite,drawPosition.xy.x + 202.0f,pairY,0.0f,palette->r,palette->g,
                  palette->b,alpha,(u16)pairScaleX,(u16)pairScaleY,0,0.0f,0);
    }
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1230) + 35.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1234) + 20.0f;
    alphaValue = (f32)work[0x123a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    packedColor = (alpha) - 0x100;
    {
      /* EE addresses are 32-bit; accumulate the signed index as an unsigned address. */
      u32 partyAddress = *(s16 *)(work + 0x28) * 2;
      partyAddress += (u32)work;
      labelText = (char *)datPersonaNamePart1(*(s16 *)(partyAddress + 0x38));
    }
    frFontExDrawText(drawPosition.xy.x + 105.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
  }
  if ((*(u32 *)(work + 0x1c) & 2) != 0) {
    u8 headerAlpha, layoutAlpha;
    palette = (CmpEquipColor *)D_0064B2F4;
    alphaValue = (f32)work[0x105a];
    alphaValue *= opacityScale;
    headerAlpha = (u8)alphaValue;
    drawSprite = *(u8 **)(work + 0x1570);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1050) + 18.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1054) + 51.0f;
    sdkSpriteDrawAt(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawSprite = *(u8 **)(work + 0x1574);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1050) + 186.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1054) + 51.0f;
    sdkSpriteDrawAt(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawSprite = *(u8 **)(work + 0x1578);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1050) + (f32)0x25F;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1054) + 90.0f;
    sdkSpriteDrawAt(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1410) + 18.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1414) + 60.0f;
    alphaValue = (f32)work[0x141a];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    packedColor = (alpha) | 0xffffff00;
    labelText = (char *)datPersonaNamePart1(*(s16 *)(work + 0xc7e));
    frFontExDrawText(drawPosition.xy.x + 88.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x13e0) + 18.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x13e4) + 60.0f;
    alphaValue = (f32)work[0x13ea];
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    packedColor = (alpha) | 0xffffff00;
    {
      u32 partyAddress = *(s16 *)(work + 0x28) * 2;
      partyAddress += (u32)work;
      labelText = (char *)datPersonaNamePart1(*(s16 *)(partyAddress + 0x38));
    }
    frFontExDrawText(drawPosition.xy.x + 88.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
    palette = (CmpEquipColor *)D_0064B2E0;
    alphaValue = (f32)work[0x13ba];
    alphaValue *= opacityScale;
    layoutAlpha = (u8)alphaValue;
    rowValue = *(s16 *)(work + 0x2a);
    switch (rowValue) {
    case 0: {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 48.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 96.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x1528),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + (f32)0x171;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x150c),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 460.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x1510),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);

      break;
    }
    case 1: {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 33.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 96.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x152c),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 71.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 103.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x1530),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + (f32)0x171;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x1514),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 460.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 66.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x1518),drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);

      break;
    }
    case 2: {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x13b0) + 34.0f;
      drawPosition.xy.y = originY + *(f32 *)(work + 0x13b4) + 91.0f;
      sdkSpriteDrawAt(*(void **)(work + 0x1534),drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);

      break;
    }
    }
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1020) + 122.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1024) + 94.0f;
    alphaValue = (f32)work[0x102a];
    alphaValue *= opacityScale;
    descriptorAlpha = (u8)alphaValue;
    datEntryReset((u8 *)&descriptor);
    selectedItemId = datGetEquippedItemByUnit(actor.id,*(s16 *)(work + 0x2a));
    descriptor.itemId = selectedItemId;
    descriptor.quantity = 0xffff;
    descriptor.unk08 = 0xffffffff;
    descriptor.unk0C = 1;
    descriptor.unk10 = 1;
    descriptor.unk14 = 1;
    descriptor.style = 4;
    descriptor.unk18 = 3;
    datEntryDrawRow(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x1380) + 122.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x1384) + 94.0f;
    alphaValue = (f32)work[0x138a];
    alphaValue *= opacityScale;
    descriptorAlpha = (u8)alphaValue;
    descriptor.itemId = *(s16 *)(work + 0xc7a);
    datEntryDrawRow(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
  }
  if ((*(u32 *)(work + 0x1c) & 0x2000) != 0) {
    u8 scrollbarAlpha;
    f32 rawAlpha;
    f32 baseX;
    baseX = *(f32 *)(work + 0x1470) + (originX + *(f32 *)(work + 0xe10));
    scrollbarY = *(f32 *)(work + 0x1474) + (originY + *(f32 *)(work + 0xe14));
    rawAlpha = (f32)work[0xe1a];
    rawAlpha *= opacityScale;
    scrollbarAlpha = (u8)rawAlpha;
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = scrollbarY + 133.0f;
    sdkSpriteDrawAt(*(void **)(work + 0x151c),((f32)0x25E + baseX),drawPosition.xy.y,0xff,0xff,0xff,scrollbarAlpha);
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = scrollbarY + 298.0f;
    sdkSpriteDrawAt(*(void **)(work + 0x1520),((f32)0x25E + baseX),drawPosition.xy.y,0xff,0xff,0xff,scrollbarAlpha);
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = scrollbarY + 136.0f;
    if (0 < *(s16 *)(work + 0xc46) - 5) {
      drawPosition.xy.y = drawPosition.xy.y +
                 (f32)(((*(s16 *)(work + 0x2c) * 0x42 + (s32)*(s16 *)(work + 0x2c)) * 2) /
                        (*(s16 *)(work + 0xc46) - 5));
    }
    palette = (CmpEquipColor *)D_0064B2E8;
    sdkSpriteDrawAt(*(void **)(work + 0x1524),drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,palette->b
                  ,scrollbarAlpha);
  }
  if ((*(u32 *)(work + 0x1c) & 1) != 0) {
    u8 panelAlpha;
    if (*(s16 *)(work + 0xc46) == 0) {
      kAssertFail(D_005E9FA0,0x507);
    }
    panelAlpha = work[0x144a];
    if (0 < (s32)panelAlpha) {
      drawPosition.xy.x = originX + *(f32 *)(work + 0x1440);
      drawPosition.xy.y = originY + *(f32 *)(work + 0x1444);
      radarDrawPaletteSet(work, drawPosition.packed, 0, panelAlpha);
    }
    {
    s16 rowIndex;
    s32 lookupIndex;
    u8 rowAlpha;
    for (rowValueIndex = 0; (s16)rowValueIndex < 5; rowValueIndex = (s16)(rowValueIndex + 1)) {
      if ((s32)((s32)(s16)rowValueIndex + (s32)*(s16 *)(work + 0x2c)) < (s32)*(s16 *)(work + 0xc46)) {
        rowIndex = (s16)rowValueIndex;
        drawPosition.xy.x = originX + *(f32 *)(work + rowIndex * 0x30 + 0xd20) + 122.0f;
        drawPosition.xy.y = *(f32 *)(work + rowIndex * 0x30 + 0xd24) + (originY + (f32)(rowIndex * 0x22)) +
                   137.0f;
        alphaValue = (f32)work[rowIndex * 0x30 + 0xd2a];
        alphaValue *= opacityScale;
        rowAlpha = (u8)alphaValue;
        lookupIndex = (s32)((s16 *)work)[0x16] + (s32)rowIndex;
        rowValue = *(s16 *)(work + lookupIndex * 4 + 0x4a);
        quantity = *(s16 *)(work + lookupIndex * 4 + 0x4c);
        datEntryReset((u8 *)&descriptor);
        if (*(s16 *)(work + 0x2e) == rowIndex) {
          descriptor.style = 3;
          radarDrawPaletteSet(work, drawPosition.packed, 1, rowAlpha);
        }
        else {
          descriptor.style = 5;
          radarDrawPaletteSet(work, drawPosition.packed, 0, rowAlpha);
        }
        descriptor.itemId = rowValue;
        descriptor.quantity = quantity;
        descriptor.unk08 = 0xffffffff;
        descriptor.unk0C = 1;
        descriptor.unk10 = 1;
        descriptor.unk14 = 1;
        descriptor.equippedItemId = selectedItemId;
        descriptor.unk18 = 3;
        datEntryDrawRow(drawPosition.xy, 0.0f, rowAlpha, (u8 *)&descriptor);
      }
    }
    }
  }
  if (((*(u32 *)(work + 0x1c) & 0x40) != 0) && (0 < *(s16 *)(work + 0xc46))) {
    borderMode = 0;
    datEntryReset((u8 *)&descriptor);
    drawPosition.xy.x = originX + *(f32 *)(work + 0x14a0) + 124.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0x14a4) + 147.0f;
    descriptor.unk08 = 0xffffffff;
    descriptor.unk14 = 0;
    descriptor.unk0C = 0;
    descriptor.unk10 = 0;
    if (*(f32 *)(work + 0x149c) < 0.0f) {
      borderMode = 1;
    }
    else if (!(*(f32 *)(work + 0x149c) <= 0.0f)) {
      borderMode = 2;
    }
    radarDrawHeaderFrame(workArea, drawPosition, work[0x14aa], borderMode);
    drawPosition.xy.x = originX + *(f32 *)(work + 0xe40) + 124.0f;
    drawPosition.xy.y = originY + *(f32 *)(work + 0xe44) + 147.0f;
    {
      u32 entryAddress = ((s32)*(s16 *)(work + 0x2c) + (s32)*(s16 *)(work + 0x2e)) * 4;
      entryAddress += (u32)work;
      descriptor.itemId = *(s16 *)(entryAddress + 0x4a);
      descriptor.quantity = *(s16 *)(entryAddress + 0x4c);
    }
    descriptor.unk08 = 0xffffffff;
    descriptor.unk0C = 1;
    descriptor.unk10 = 1;
    descriptor.equippedItemId = selectedItemId;
    descriptor.style = 3;
    descriptor.unk14 = 1;
    descriptor.unk18 = 3;
    alphaValue = (f32)work[0xe4a];
    alphaValue *= opacityScale;
    radarDrawItemCard(workArea, drawPosition.packed, (u8)alphaValue, (u8 *)&descriptor);
  }
  drawPosition.xy.x = originX + *(f32 *)(work + 0x1350) + 640.0f;
  drawPosition.xy.y = originY + *(f32 *)(work + 0x1354) + 400.0f;
  alphaValue = (f32)work[0x135a];
  alphaValue *= opacityScale;
  alpha = (u8)alphaValue;
  sdkSpriteDrawFooter(drawPosition.xy, 0.0f, (u8)(alpha), *(s16 *)(work + 0xc78), *(s32 *)(work + 0x1590));
  return;
}
#pragma opt_dead_assignments on

#pragma pop

/* Save the previous cursor value before updating the selected equipment-menu slot. */
// FUN_001344B0
s32 cmpEquipSetSelection(u8 *workArea, s32 slotIndex, s16 selection) {
    /* The offset must be computed before the base is added: writing
       `workArea + slotIndex * 2` makes mwcc emit `addu $v1,$a0,$v0`, retail has
       `addu $v1,$v0,$a0`. */
    s32 off = slotIndex * 2;
    u8 *p = (u8 *)(off + (s32)workArea);

    ((CmpEquipWork *)p)->previousSelection[0] = ((CmpEquipWork *)p)->selection[0];
    ((CmpEquipWork *)p)->selection[0] = selection;
    return 1;
}

/* Advance the three tab transitions with a frame counter capped at 100. */
// FUN_001344D0
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpEquipWork rewrite changed 102 instruction bytes and was reverted. */
void cmpEquipStepTabAnimations(u8 *workArea) {
    s32 i;
    s16 v;

    v = *(s16 *)(workArea + 0x24);
    if (v < 0x64) {
        *(s16 *)(workArea + 0x24) = v + 1;
    }
    for (i = 0; i < 3; i++) {
        radarAnimateValue(workArea + i * 0x30 + 0x1430, *(s16 *)(workArea + 0x24), 0);
    }
}

/* measured: equipment-mode switch and table update match the retail window. */
/* measured: common-subexpression elimination is disabled for the setup and switch layout. */
#pragma opt_common_subs off
/* Snapshot current row poses and apply the selected equipment-menu layout and visibility mask. */
// FUN_00134560
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpEquipWork rewrite changed 614 instruction bytes and was reverted. */
s32 cmpEquipSetMode(u8 *workArea, s32 mode)
{
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    if (mode == *(s32 *)(workArea + 0x18)) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = workArea + i * 0x30;
        *(f32 *)(dst + 0xC80) = *(f32 *)(dst + 0xC90);
        *(f32 *)(dst + 0xC84) = *(f32 *)(dst + 0xC94);
        *(u8 *)(dst + 0xC98) = *(u8 *)(dst + 0xC9A);
        *(u16 *)(dst + 0xC9C) = *(u16 *)(dst + 0xCA0);
        *(u16 *)(dst + 0xCA2) = *(u16 *)(dst + 0xCA6);
    }
    switch (mode) {
    case 0:
        table = D_005E7720;
        *(s32 *)(workArea + 0x1C) = 0x494;
        *(s16 *)(workArea + 0xC78) = 0;
        break;
    case 1:
        table = D_005E7BA0;
        break;
    case 2:
        table = D_005E8020;
        *(s32 *)(workArea + 0x1C) = 0x494;
        *(s16 *)(workArea + 0xC78) = 0;
        break;
    case 3:
        table = D_005E84A0;
        *(s32 *)(workArea + 0x1C) = 0x5BC;
        *(s16 *)(workArea + 0xC78) = 0;
        *(f32 *)(workArea + 0x11F4) =
            30.0f * (f32)*(s16 *)(workArea + 0x28);
        *(f32 *)(workArea + 0x1224) =
            30.0f * (f32)*(s16 *)(workArea + 0x28);
        break;
    case 4:
        table = D_005E8920;
        *(s32 *)(workArea + 0x1C) = 0x538;
        *(s16 *)(workArea + 0xC78) = 0;
        break;
    case 5:
        table = D_005E8DA0;
        *(s32 *)(workArea + 0x1C) = 0x538;
        *(s16 *)(workArea + 0xC78) = 0;
        break;
    case 6:
        table = D_005E9220;
        cmpEquipBuildItemList((s16 *)workArea);
        *(s32 *)(workArea + 0x1C) = 0x3A0B;
        *(s16 *)(workArea + 0xC78) = 3;
        break;
    case 7:
        table = D_005E96A0;
        *(s32 *)(workArea + 0x1C) = 0x3A0B;
        *(s16 *)(workArea + 0xC78) = 3;
        break;
    case 8:
    case 9:
        table = D_005E9B20;
        *(s32 *)(workArea + 0x1C) = 0x3A4A;
        *(s16 *)(workArea + 0xC78) = 4;
        break;
    default:
        kAssertFail(D_005E9FA0, 0x5F8);
        break;
    }
    if (table != 0) {
#pragma opt_common_subs on
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = workArea + j * 0x30;
            *(f32 *)(dst + 0xC88) = *(f32 *)(src + 0);
            *(f32 *)(dst + 0xC8C) = *(f32 *)(src + 4);
            *(u8 *)(dst + 0xC99) = *(u8 *)(src + 0x10);
            value = *(f32 *)(src + 8);
            *(u16 *)(dst + 0xC9E) = (u16)value;
            value = *(f32 *)(src + 0xC);
            *(u16 *)(dst + 0xCA4) = (u16)value;
            *(s32 *)(dst + 0xCA8) = *(s32 *)(src + 0x14);
            *(s32 *)(dst + 0xCAC) = *(s32 *)(src + 0x18);
        }
    }
    *(s32 *)(workArea + 0x18) = mode;
    *(s16 *)(workArea + 0x20) = 0;
    return 1;
}
#pragma opt_loop_invariants off

#include "include_asm.h"
/* Persona 4 USA decompilation - cmpEquip.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"


void radarAnimateValue(void *, s32, s32);
void cmpEquipStepTabAnimations(u8 *);
void cmpEquipMenuDraw(u8 *);
s16 datGetEquippedItemByUnit(s16, s16);
s32 datItemCount(s16 itemId);
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
/* sdkSpriteNewNode allocates this 0x2C-byte sample (sdkSpr.c).
 * The rotating menu decoration overrides its signed pivot coordinates. */
typedef struct SdkSpriteSample {
    u32 packAddress, recordIndex;
    f32 x, y;
    u8 alphaSubtract, fade;
    u8 pad12[2];
    s16 extendX, extendY;
    f32 angle;
    s16 pivotX, pivotY;
    u16 scaleX, scaleY;
    f32 depth;
    u8 red, green, blue, pad2B;
} SdkSpriteSample;
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
    ((CmpEquipWork *)base)->alpha = 0xFF;
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
/* measured: only the indexed party-id lookup changes instruction bytes; the other halfword work accesses now use members. */

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

    id = workArea[workArea[20] + 28]; /* measured: this access-site member rewrite changes instruction bytes. */
    type = ((CmpEquipWork *)workArea)->selection[1];
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
        ((CmpEquipWork *)entry)->items[0].id = i;
        ((CmpEquipWork *)entry)->items[0].quantity = value;
        count++;
    skip:
        ;
    }
    ((CmpEquipWork *)workArea)->itemCount = count;
    if (count > 0x2FF) {
        kAssertFail(D_005E9FA0, 0x299);
    }
}
// Advances the menu state from 0 to 1; returns 1 for states 0 and 1, 0 otherwise [inferred].
// FUN_001318C0
/* Access-site typing is measured independently below; retain the original byte-pointer local. */
s32 cmpEquipStateStep(u8 *workArea) {
    CmpEquipWork *menu = (CmpEquipWork *)workArea;
    s32 v = menu->phase;

    switch (v) {
    case 0:
        v += 1;
        menu->phase = v;
        return 1;
    case 1:
        return 1;
    default:
        return 0;
    }
}

/* Advance row and tab animations, draw the equipment menu, and report whether all rows are transparent. */
// FUN_00131910
/* Historical whole-layout rewrite changed 179 instruction bytes; typed root-local and indexed-field forms now keep MATCH. */
s32 cmpEquipMenuUpdate(u8 *workArea) {
    CmpEquipWork *menu = (CmpEquipWork *)workArea;
    s32 i;
    s32 rv;
    u8 *p;

    rv = 1;
    if (menu->frame < 0x64) {
        menu->frame = menu->frame + 1;
    }
    for (i = 0; i < 0x29; i++) {
        p = workArea + i * 0x30;
        radarAnimateValue(p + 0xC80, menu->frame, 0);
        if (((CmpEquipWork *)(p))->motion[0].alpha != 0) {
            rv = 0;
        }
    }
    menu->angle = menu->angle + 1;
    if (menu->angle >= 0x168) {
        menu->angle = 0;
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
 * use the file baseline. Only the lifetime override is scoped here.
 */
// FUN_00131A00
#pragma push
/* measured: baseline draw has 2445 differing words; lifetime isolation restores MATCH without the redundant dead-assignment setting. */
#pragma opt_lifetimes on
/* Historical whole-layout rewrite changed 8450 instruction bytes; typed root-local and indexed-field forms now keep MATCH. */
void cmpEquipMenuDraw(u8 *workArea)

{
    CmpEquipWork *menu = (CmpEquipWork *)workArea;
    typedef struct { f32 x, y; } Vec2f;
    typedef union { Vec2f xy; s64 packed; } PackedVec2f;
    PackedVec2f drawPosition;
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2f workArea, s32, s32, f32);
    extern void sdkSpriteDrawAt(void *workArea, f32, f32, u8, u8, u8, u8);
    extern void sdkSpriteDrawSized(u8 *workArea, f32, f32, f32, u8, u8, u8, u8, u16, u16, s16, f32, s16);
    extern void datEntryDrawRow(Vec2f workArea, f32, u8, u8 *);
    extern void datEntryReset(u8 *entry);
    extern u32 datEntryGetFlags(s16 itemId);
    extern s16 datGetEquippedItemByUnit(s16 workArea, s16);
    extern u32 datPersonaNamePart1(s16 unitId);
    extern s32 radarFlagToIconMode(s32 flags);
    extern void radarDrawPalettePair(u8 *workArea, s64 , s64 , u8);
    extern void radarDrawPaletteSet(u8 *workArea, s64 , s64 , u8);
    extern void radarDrawItemCard(u8 *workArea, s64 , u8, u8 *);
    extern void radarDrawHeaderFrame(u8 *workArea, PackedVec2f , u8, u16);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id, const char *str, s32 flags, s32 unused);
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
  actor.id = partyIds[menu->selection[0]];
  sdkRenderStateSetDefault();
  originX = menu->x;
  originY = menu->y;
  opacityScale = (f32)*work / 255.0f;
  if (menu->background != 0) {
    drawPosition.xy.x = originX;
    drawPosition.xy.y = originY;
    alphaValue = opacityScale * 255.0f;
    alpha = (u8)alphaValue;
    nLineDrawSet(drawPosition.xy,alpha,menu->background,0.0f);
  }
  if ((menu->visible & 0x1000) != 0) {
    spriteOrPalette = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[47];
    ((SdkSpriteSample *)spriteOrPalette)->pivotX = 0x3d;
    ((SdkSpriteSample *)spriteOrPalette)->pivotY = 0x3f;
    drawPosition.xy.x = originX + menu->motion[31].x + (f32)0x212;
    drawPosition.xy.y = (originY + menu->motion[31].y) - 3.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[31].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    scaleX = (f32)((CmpEquipWork *)(work))->motion[31].width;
    scaleY = (f32)((CmpEquipWork *)(work))->motion[31].height;
    sdkSpriteDrawSized(spriteOrPalette,drawPosition.xy.x,drawPosition.xy.y,0.0f,0xff,0xff,0x81,alpha,(u16)scaleX,(u16)scaleY,0x3d,
                  (f32)(s32)((CmpEquipWork *)(work))->angle,0x3f);
    drawPosition.xy.x = originX + menu->motion[32].x + (f32)0x226;
    drawPosition.xy.y = (originY + menu->motion[32].y) - 22.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[32].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    scaleX = (f32)((CmpEquipWork *)(work))->motion[32].width;
    scaleY = (f32)((CmpEquipWork *)(work))->motion[32].height;
    sdkSpriteDrawSized(spriteOrPalette,drawPosition.xy.x,drawPosition.xy.y,0.0f,0xfb,0xa2,0,alpha,(u16)scaleX,(u16)scaleY,0x3d,
                  (f32)(s32)menu->angle,0x3f);
  }
  if ((menu->visible & 0x400) != 0) {
    sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[51];
    drawPosition.xy.x = originX + menu->motion[0].x + 20.0f;
    drawPosition.xy.y = originY + menu->motion[0].y + 358.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[0].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((menu->visible & 0x800) != 0) {
    sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[51];
    drawPosition.xy.x = originX + menu->motion[1].x + (f32)0x1D1;
    drawPosition.xy.y = originY + menu->motion[1].y + 20.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[1].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((menu->visible & 0x80) != 0) {
    sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[41];
    drawPosition.xy.x = originX + menu->motion[33].x + 20.0f;
    drawPosition.xy.y = originY + menu->motion[33].y + (f32)0x195;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[33].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((menu->visible & 0x100) != 0) {
    sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[42];
    drawPosition.xy.x = originX + menu->motion[34].x + 146.0f;
    drawPosition.xy.y = originY + menu->motion[34].y + (f32)0x195;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[34].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((menu->visible & 0x200) != 0) {
    sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[41];
    drawPosition.xy.x = originX + menu->motion[35].x + 20.0f;
    drawPosition.xy.y = originY + menu->motion[35].y + (f32)0x195;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[35].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    sdkSpriteDrawAt(sprite,drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,alpha);
  }
  if ((menu->visible & 4) != 0) {
    rowValueIndex = 0;
    while (rowValue = (s16)rowValueIndex, rowValue < menu->partyCount) {
      drawPosition.xy.x = originX + ((CmpEquipWork *)(work + (s16)rowValueIndex * 0x30))->motion[21].x + 35.0f;
      {
      drawPosition.xy.y = 20.0f + (33.0f * (f32)rowValueIndex + (0.0f + (originY + ((CmpEquipWork *)(work + (s16)rowValueIndex * 0x30))->motion[21].y)));
      scaleX = (f32)((CmpEquipWork *)(work + (s16)rowValueIndex * 0x30))->motion[21].width;
      scaleY = (f32)((CmpEquipWork *)(work + (s16)rowValueIndex * 0x30))->motion[21].height;
      alphaValue = (f32)((CmpEquipWork *)(work + (s16)rowValueIndex * 0x30))->motion[21].alpha;
    alphaValue *= opacityScale;
      opacity.value = (u8)alphaValue;
      packedColor = opacity.value | 0xffffff00;
      if (menu->selection[0] == (s16)rowValueIndex) {
        actorPalette = D_0064B2E8;
        labelStyle = 8;
      }
      else {
        actorPalette = D_0064B2E0;
        labelStyle = 6;
      }
      drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[0];
      drawY = drawPosition.xy.y;
      sdkSpriteDrawSized(drawSprite,drawPosition.xy.x,drawY,0.0f,*actorPalette,actorPalette[1],actorPalette[2],
                    opacity.value,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[1];
      sdkSpriteDrawSized(drawSprite,drawPosition.xy.x + 202.0f,drawY,0.0f,*actorPalette,actorPalette[1],
                    actorPalette[2],opacity.value,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      labelText = (char *)datPersonaNamePart1(((CmpEquipWork *)(work + rowValue * 2))->partyIds[0]);
      frFontExDrawText(drawPosition.xy.x + 105.0f,drawY,0.0f,packedColor,labelStyle,1,labelText,8,0);
      }
      rowValueIndex = (s32)(s16)(rowValueIndex + 1);
    }
  }
  if ((menu->visible & 0x10) != 0) {
    s16 rowCounter;
    u8 *spriteOrPalette;
    for (rowCounter = 0; rowCounter < 3; ++rowCounter) {
      rowSelected = 0;
      if ((menu->visible & 0x20) != 0) {
        drawPosition.xy.x = originX + ((CmpEquipWork *)(work + rowCounter * 0x30))->motion[16].x + 253.0f;
        drawPosition.xy.y = originY + ((CmpEquipWork *)(work + rowCounter * 0x30))->motion[16].y + 190.0f +
                   (f32)(rowCounter * 0x3f);
        alphaValue = (f32)((CmpEquipWork *)(work + rowCounter * 0x30))->motion[16].alpha;
    alphaValue *= opacityScale;
        alpha = (u8)alphaValue;
        {
          s64 selectedMode;
          if (menu->selection[1] == rowCounter) {
            selectedMode = 1;
            rowSelected = selectedMode;
          } else {
            selectedMode = 0;
          }
          radarDrawPalettePair(work, drawPosition.packed, selectedMode, (u8)(alpha));
        }
      }
      drawPosition.xy.x = originX + ((CmpEquipWork *)(work + rowCounter * 0x30))->motion[13].x + 253.0f;
      drawPosition.xy.y = originY + ((CmpEquipWork *)(work + rowCounter * 0x30))->motion[13].y + 190.0f +
                 (f32)(rowCounter * 0x3f);
      alphaValue = (f32)((CmpEquipWork *)(work + rowCounter * 0x30))->motion[13].alpha;
    alphaValue *= opacityScale;
      alpha = (u8)alphaValue;
      {
      scaleX = (f32)((CmpEquipWork *)(work + rowCounter * 0x30))->motion[13].width;
      scaleY = (f32)((CmpEquipWork *)(work + rowCounter * 0x30))->motion[13].height;
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
        sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[2];
      }
      else {
        sprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[3];
      }
      {
      drawY = drawPosition.xy.y;
      sdkSpriteDrawSized(sprite,drawPosition.xy.x,drawPosition.xy.y,0.0f,*spriteOrPalette,spriteOrPalette[1],spriteOrPalette[2],alpha,
                    (u16)scaleX,(u16)scaleY,0,0.0f,0);
      drawSprite = (u8 *)(u32)((CmpEquipWork *)(work + rowIcon * 4))->sprites[0];
      sdkSpriteDrawSized(drawSprite,drawPosition.xy.x + 3.0f,drawY + 2.0f,0.0f,
                    *iconPalette,iconPalette[1],iconPalette[2],alpha,(u16)scaleX,(u16)scaleY,0,0.0f,0);
      }
      }
      drawPosition.xy.x = originX + ((CmpEquipWork *)(work + rowCounter * 0x30))->motion[10].x + 255.0f;
      drawPosition.xy.y = originY + ((CmpEquipWork *)(work + rowCounter * 0x30))->motion[10].y + 193.0f +
                 (f32)(rowCounter * 0x3f);
      alphaValue = (f32)((CmpEquipWork *)(work + rowCounter * 0x30))->motion[10].alpha;
    alphaValue *= opacityScale;
      alpha = (u8)alphaValue;
      drawSprite = (u8 *)(u32)((CmpEquipWork *)(work + rowCounter * 4))->sprites[4];
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
      alphaValue = (f32)((CmpEquipWork *)(work + rowCounter * 0x30))->motion[10].alpha;
    alphaValue *= opacityScale;
      descriptorAlpha = (u8)alphaValue;
      datEntryReset((u8 *)&descriptor);
      if ((menu->visible & 0x20) != 0) {
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
  if ((menu->visible & 8) != 0) {
    f32 pairY, pairScaleX, pairScaleY;
    drawPosition.xy.x = originX + menu->motion[29].x + 35.0f;
    {
      drawPosition.xy.y = originY + menu->motion[29].y + 20.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[29].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    pairScaleX = (f32)((CmpEquipWork *)(work))->motion[29].width;
    pairScaleY = (f32)((CmpEquipWork *)(work))->motion[29].height;
    palette = (CmpEquipColor *)D_0064B2F4;
    drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[0];
    pairY = drawPosition.xy.y;
    sdkSpriteDrawSized(drawSprite,drawPosition.xy.x,pairY,0.0f,palette->r,palette->g,
                  palette->b,alpha,(u16)pairScaleX,(u16)pairScaleY,0,0.0f,0);
    drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[1];
    sdkSpriteDrawSized(drawSprite,drawPosition.xy.x + 202.0f,pairY,0.0f,palette->r,palette->g,
                  palette->b,alpha,(u16)pairScaleX,(u16)pairScaleY,0,0.0f,0);
    }
    drawPosition.xy.x = originX + menu->motion[30].x + 35.0f;
    drawPosition.xy.y = originY + menu->motion[30].y + 20.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[30].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    packedColor = (alpha) - 0x100;
    {
      /* EE addresses are 32-bit; accumulate the signed index as an unsigned address. */
      u32 partyAddress = menu->selection[0] * 2;
      partyAddress += (u32)work;
      labelText = (char *)datPersonaNamePart1(((CmpEquipWork *)(partyAddress))->partyIds[0]);
    }
    frFontExDrawText(drawPosition.xy.x + 105.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
  }
  if ((menu->visible & 2) != 0) {
    u8 headerAlpha, layoutAlpha;
    palette = (CmpEquipColor *)D_0064B2F4;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[20].alpha;
    alphaValue *= opacityScale;
    headerAlpha = (u8)alphaValue;
    drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[44];
    drawPosition.xy.x = originX + menu->motion[20].x + 18.0f;
    drawPosition.xy.y = originY + menu->motion[20].y + 51.0f;
    sdkSpriteDrawAt(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[45];
    drawPosition.xy.x = originX + menu->motion[20].x + 186.0f;
    drawPosition.xy.y = originY + menu->motion[20].y + 51.0f;
    sdkSpriteDrawAt(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawSprite = (u8 *)(u32)((CmpEquipWork *)(work))->sprites[46];
    drawPosition.xy.x = originX + menu->motion[20].x + (f32)0x25F;
    drawPosition.xy.y = originY + menu->motion[20].y + 90.0f;
    sdkSpriteDrawAt(drawSprite,drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,
                  palette->b,headerAlpha);
    drawPosition.xy.x = originX + menu->motion[40].x + 18.0f;
    drawPosition.xy.y = originY + menu->motion[40].y + 60.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[40].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    packedColor = (alpha) | 0xffffff00;
    labelText = (char *)datPersonaNamePart1(menu->labelId);
    frFontExDrawText(drawPosition.xy.x + 88.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
    drawPosition.xy.x = originX + menu->motion[39].x + 18.0f;
    drawPosition.xy.y = originY + menu->motion[39].y + 60.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[39].alpha;
    alphaValue *= opacityScale;
    alpha = (u8)alphaValue;
    packedColor = (alpha) | 0xffffff00;
    {
      u32 partyAddress = menu->selection[0] * 2;
      partyAddress += (u32)work;
      labelText = (char *)datPersonaNamePart1(((CmpEquipWork *)(partyAddress))->partyIds[0]);
    }
    frFontExDrawText(drawPosition.xy.x + 88.0f,drawPosition.xy.y,0.0f,packedColor,7,1,labelText,8,0);
    palette = (CmpEquipColor *)D_0064B2E0;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[38].alpha;
    alphaValue *= opacityScale;
    layoutAlpha = (u8)alphaValue;
    rowValue = menu->selection[1];
    switch (rowValue) {
    case 0: {
      drawPosition.xy.x = originX + menu->motion[38].x + 48.0f;
      drawPosition.xy.y = originY + menu->motion[38].y + 96.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[26],drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + menu->motion[38].x + (f32)0x171;
      drawPosition.xy.y = originY + menu->motion[38].y + 66.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[19],drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);
      drawPosition.xy.x = originX + menu->motion[38].x + 460.0f;
      drawPosition.xy.y = originY + menu->motion[38].y + 66.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[20],drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);

      break;
    }
    case 1: {
      drawPosition.xy.x = originX + menu->motion[38].x + 33.0f;
      drawPosition.xy.y = originY + menu->motion[38].y + 96.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[27],drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + menu->motion[38].x + 71.0f;
      drawPosition.xy.y = originY + menu->motion[38].y + 103.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[28],drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);
      drawPosition.xy.x = originX + menu->motion[38].x + (f32)0x171;
      drawPosition.xy.y = originY + menu->motion[38].y + 66.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[21],drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);
      drawPosition.xy.x = originX + menu->motion[38].x + 460.0f;
      drawPosition.xy.y = originY + menu->motion[38].y + 66.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[22],drawPosition.xy.x,drawPosition.xy.y,0xff,0xff,0xff,layoutAlpha);

      break;
    }
    case 2: {
      drawPosition.xy.x = originX + menu->motion[38].x + 34.0f;
      drawPosition.xy.y = originY + menu->motion[38].y + 91.0f;
      sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[29],drawPosition.xy.x,drawPosition.xy.y,(u8)palette->r,
                    palette->g,palette->b,layoutAlpha);

      break;
    }
    }
    drawPosition.xy.x = originX + menu->motion[19].x + 122.0f;
    drawPosition.xy.y = originY + menu->motion[19].y + 94.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[19].alpha;
    alphaValue *= opacityScale;
    descriptorAlpha = (u8)alphaValue;
    datEntryReset((u8 *)&descriptor);
    selectedItemId = datGetEquippedItemByUnit(actor.id,menu->selection[1]);
    descriptor.itemId = selectedItemId;
    descriptor.quantity = 0xffff;
    descriptor.unk08 = 0xffffffff;
    descriptor.unk0C = 1;
    descriptor.unk10 = 1;
    descriptor.unk14 = 1;
    descriptor.style = 4;
    descriptor.unk18 = 3;
    datEntryDrawRow(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
    drawPosition.xy.x = originX + menu->motion[37].x + 122.0f;
    drawPosition.xy.y = originY + menu->motion[37].y + 94.0f;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[37].alpha;
    alphaValue *= opacityScale;
    descriptorAlpha = (u8)alphaValue;
    descriptor.itemId = menu->pendingItem;
    datEntryDrawRow(drawPosition.xy, 0.0f, descriptorAlpha, (u8 *)&descriptor);
  }
  if ((menu->visible & 0x2000) != 0) {
    u8 scrollbarAlpha;
    f32 rawAlpha;
    f32 baseX;
    baseX = menu->tabMotion[1].x + (originX + menu->motion[8].x);
    scrollbarY = menu->tabMotion[1].y + (originY + menu->motion[8].y);
    rawAlpha = (f32)menu->motion[8].alpha;
    rawAlpha *= opacityScale;
    scrollbarAlpha = (u8)rawAlpha;
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = scrollbarY + 133.0f;
    sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[23],((f32)0x25E + baseX),drawPosition.xy.y,0xff,0xff,0xff,scrollbarAlpha);
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = scrollbarY + 298.0f;
    sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[24],((f32)0x25E + baseX),drawPosition.xy.y,0xff,0xff,0xff,scrollbarAlpha);
    drawPosition.xy.x = ((f32)0x25E + baseX);
    drawPosition.xy.y = scrollbarY + 136.0f;
    if (0 < menu->itemCount - 5) {
      drawPosition.xy.y = drawPosition.xy.y +
                 (f32)(((menu->selection[2] * 0x42 + (s32)menu->selection[2]) * 2) /
                        (menu->itemCount - 5));
    }
    palette = (CmpEquipColor *)D_0064B2E8;
    sdkSpriteDrawAt((void *)(u32)((CmpEquipWork *)(work))->sprites[25],drawPosition.xy.x,drawPosition.xy.y,palette->r,palette->g,palette->b
                  ,scrollbarAlpha);
  }
  if ((menu->visible & 1) != 0) {
    u8 panelAlpha;
    if (menu->itemCount == 0) {
      kAssertFail(D_005E9FA0,0x507);
    }
    panelAlpha = menu->tabMotion[0].alpha;
    if (0 < (s32)panelAlpha) {
      drawPosition.xy.x = originX + menu->tabMotion[0].x;
      drawPosition.xy.y = originY + menu->tabMotion[0].y;
      radarDrawPaletteSet(work, drawPosition.packed, 0, panelAlpha);
    }
    {
    s16 rowIndex;
    s32 lookupIndex;
    u8 rowAlpha;
    for (rowValueIndex = 0; (s16)rowValueIndex < 5; rowValueIndex = (s16)(rowValueIndex + 1)) {
      if ((s32)((s32)(s16)rowValueIndex + (s32)((CmpEquipWork *)(work))->selection[2]) < (s32)menu->itemCount) {
        rowIndex = (s16)rowValueIndex;
        drawPosition.xy.x = originX + ((CmpEquipWork *)(work + rowIndex * 0x30))->motion[3].x + 122.0f;
        drawPosition.xy.y = ((CmpEquipWork *)(work + rowIndex * 0x30))->motion[3].y + (originY + (f32)(rowIndex * 0x22)) +
                   137.0f;
        alphaValue = (f32)((CmpEquipWork *)(work + rowIndex * 0x30))->motion[3].alpha;
        alphaValue *= opacityScale;
        rowAlpha = (u8)alphaValue;
        lookupIndex = (s32)menu->selection[2] + (s32)rowIndex;
        rowValue = ((CmpEquipWork *)(work + lookupIndex * 4))->items[0].id;
        quantity = ((CmpEquipWork *)(work + lookupIndex * 4))->items[0].quantity;
        datEntryReset((u8 *)&descriptor);
        if (menu->selection[3] == rowIndex) {
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
  if (((menu->visible & 0x40) != 0) && (0 < menu->itemCount)) {
    borderMode = 0;
    datEntryReset((u8 *)&descriptor);
    drawPosition.xy.x = originX + menu->tabMotion[2].x + 124.0f;
    drawPosition.xy.y = originY + menu->tabMotion[2].y + 147.0f;
    descriptor.unk08 = 0xffffffff;
    descriptor.unk14 = 0;
    descriptor.unk0C = 0;
    descriptor.unk10 = 0;
    if (menu->tabMotion[2].targetY < 0.0f) {
      borderMode = 1;
    }
    else if (!(menu->tabMotion[2].targetY <= 0.0f)) {
      borderMode = 2;
    }
    radarDrawHeaderFrame(workArea, drawPosition, menu->tabMotion[2].alpha, borderMode);
    drawPosition.xy.x = originX + menu->motion[9].x + 124.0f;
    drawPosition.xy.y = originY + menu->motion[9].y + 147.0f;
    {
      u32 entryAddress = ((s32)((CmpEquipWork *)(work))->selection[2] + (s32)((CmpEquipWork *)(work))->selection[3]) * 4;
      entryAddress += (u32)work;
      descriptor.itemId = ((CmpEquipWork *)(entryAddress))->items[0].id;
      descriptor.quantity = ((CmpEquipWork *)(entryAddress))->items[0].quantity;
    }
    descriptor.unk08 = 0xffffffff;
    descriptor.unk0C = 1;
    descriptor.unk10 = 1;
    descriptor.equippedItemId = selectedItemId;
    descriptor.style = 3;
    descriptor.unk14 = 1;
    descriptor.unk18 = 3;
    alphaValue = (f32)((CmpEquipWork *)work)->motion[9].alpha;
    alphaValue *= opacityScale;
    radarDrawItemCard(workArea, drawPosition.packed, (u8)alphaValue, (u8 *)&descriptor);
  }
  drawPosition.xy.x = originX + menu->motion[36].x + 640.0f;
  drawPosition.xy.y = originY + menu->motion[36].y + 400.0f;
  alphaValue = (f32)((CmpEquipWork *)work)->motion[36].alpha;
  alphaValue *= opacityScale;
  alpha = (u8)alphaValue;
  sdkSpriteDrawFooter(drawPosition.xy, 0.0f, (u8)(alpha), menu->footerMode, menu->footerTexture);
  return;
}

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
/* Historical whole-layout rewrite changed 102 instruction bytes; typed root-local and indexed-field forms now keep MATCH. */
void cmpEquipStepTabAnimations(u8 *workArea) {
    CmpEquipWork *menu = (CmpEquipWork *)workArea;
    s32 i;
    s16 v;

    v = menu->tabFrame;
    if (v < 0x64) {
        menu->tabFrame = v + 1;
    }
    for (i = 0; i < 3; i++) {
        radarAnimateValue(workArea + i * 0x30 + 0x1430, menu->tabFrame, 0);
    }
}

/* measured: equipment-mode switch and table update match the retail window. */
/* Snapshot current row poses and apply the selected equipment-menu layout and visibility mask. */
// FUN_00134560
/* Historical whole-layout rewrite changed 614 instruction bytes; typed root-local and indexed-field forms now keep MATCH. */
s32 cmpEquipSetMode(u8 *workArea, s32 mode)
{
    CmpEquipWork *menu = (CmpEquipWork *)workArea;
    s32 i;
    s32 j;
    u8 *table;
    u8 *src;
    u8 *dst;
    f32 value;

    if (mode == ((CmpEquipWork *)(workArea))->mode) {
        return 0;
    }
    for (i = 0; i < 0x29; i++) {
        dst = workArea + i * 0x30;
        ((CmpEquipWork *)(dst))->motion[0].startX = ((CmpEquipWork *)(dst))->motion[0].x;
        ((CmpEquipWork *)(dst))->motion[0].startY = ((CmpEquipWork *)(dst))->motion[0].y;
        ((CmpEquipWork *)(dst))->motion[0].startAlpha = ((CmpEquipWork *)(dst))->motion[0].alpha;
        ((CmpEquipWork *)(dst))->motion[0].startWidth = ((CmpEquipWork *)(dst))->motion[0].width;
        ((CmpEquipWork *)(dst))->motion[0].startHeight = ((CmpEquipWork *)(dst))->motion[0].height;
    }
    switch (mode) {
    case 0:
        table = D_005E7720;
        ((CmpEquipWork *)(workArea))->visible = 0x494;
        ((CmpEquipWork *)(workArea))->footerMode = 0;
        break;
    case 1:
        table = D_005E7BA0;
        break;
    case 2:
        table = D_005E8020;
        ((CmpEquipWork *)(workArea))->visible = 0x494;
        ((CmpEquipWork *)(workArea))->footerMode = 0;
        break;
    case 3:
        table = D_005E84A0;
        ((CmpEquipWork *)(workArea))->visible = 0x5BC;
        ((CmpEquipWork *)(workArea))->footerMode = 0;
        ((CmpEquipWork *)(workArea))->motion[29].startY =
            30.0f * (f32)((CmpEquipWork *)(workArea))->selection[0];
        ((CmpEquipWork *)(workArea))->motion[30].startY =
            30.0f * (f32)((CmpEquipWork *)(workArea))->selection[0];
        break;
    case 4:
        table = D_005E8920;
        ((CmpEquipWork *)(workArea))->visible = 0x538;
        ((CmpEquipWork *)(workArea))->footerMode = 0;
        break;
    case 5:
        table = D_005E8DA0;
        ((CmpEquipWork *)(workArea))->visible = 0x538;
        ((CmpEquipWork *)(workArea))->footerMode = 0;
        break;
    case 6:
        table = D_005E9220;
        cmpEquipBuildItemList((s16 *)workArea);
        ((CmpEquipWork *)(workArea))->visible = 0x3A0B;
        ((CmpEquipWork *)(workArea))->footerMode = 3;
        break;
    case 7:
        table = D_005E96A0;
        ((CmpEquipWork *)(workArea))->visible = 0x3A0B;
        ((CmpEquipWork *)(workArea))->footerMode = 3;
        break;
    case 8:
    case 9:
        table = D_005E9B20;
        ((CmpEquipWork *)(workArea))->visible = 0x3A4A;
        ((CmpEquipWork *)(workArea))->footerMode = 4;
        break;
    default:
        kAssertFail(D_005E9FA0, 0x5F8);
        break;
    }
    if (table != 0) {
        for (j = 0; j < 0x29; j++) {
            src = table + j * 0x1C;
            dst = workArea + j * 0x30;
            ((CmpEquipWork *)(dst))->motion[0].targetX = ((CmpEquipLayoutRow *)src)->x;
            ((CmpEquipWork *)(dst))->motion[0].targetY = ((CmpEquipLayoutRow *)src)->y;
            ((CmpEquipWork *)(dst))->motion[0].targetAlpha = ((CmpEquipLayoutRow *)src)->alpha;
            value = ((CmpEquipLayoutRow *)src)->width;
            ((CmpEquipWork *)(dst))->motion[0].targetWidth = (u16)value;
            value = ((CmpEquipLayoutRow *)src)->height;
            ((CmpEquipWork *)(dst))->motion[0].targetHeight = (u16)value;
            ((CmpEquipWork *)(dst))->motion[0].startFrame = ((CmpEquipLayoutRow *)src)->startFrame;
            ((CmpEquipWork *)(dst))->motion[0].endFrame = ((CmpEquipLayoutRow *)src)->endFrame;
        }
    }
    menu->mode = mode;
    menu->frame = 0;
    return 1;
}
#pragma opt_loop_invariants off

#include "include_asm.h"
/* Persona 4 USA decompilation - cmpPersona.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"

typedef struct CmpHead CmpHead;
struct CmpHead {
    u8 _pad00[0x1C];
    s32 flags; // 0x1C
    s16 f20;   // 0x20
    s16 f22;   // 0x22
};

s32 nLineIsIdle(void);
void radarAnimateValue(void*, s32, s32);
void datCommunityEntryStep(void*);
u32 RpRandom(void);
void sdkSpriteFreeNode(void *node);
void kwlnTaskDestroyWithHierarchy(s32);
void nmMesWindowResetCurrent(void);
void datScreenWipeInit(s32, void*, void*);
void datScreenWipeSetTarget(s32, void*, void*);
void datScreenWipeSetColor(s32, s32);
void kAssertFail(void*, s32);
void cmpPersonaMenuStepAnimations(u8*);
void cmpPersonaMenuDraw(u8*);
extern s32 D_005EB580[];
extern u8 D_005EB560[];
extern u8 D_005EB570[];
extern u8 D_005EB578[];
extern s16 D_005EB590[];
extern void shdPersonaLevelUpRoute(u8*);
extern u8 D_005E9FD0[];
extern u8 D_005EA2E0[];
extern u8 D_005EA5F0[];
extern u8 D_005EA900[];
extern u8 D_005EAC10[];
extern u8 D_005EAF20[];
extern u8 D_005EB230[];
typedef struct CmpPair CmpPair;
struct CmpPair {
    f32 x;
    f32 y;
};
void datScreenWipeSetOffset(s32, CmpPair );

/* Both 0x14-byte grids have a signed palette index, integer coordinates,
   and dimensions consumed by cmpGridCellFade. The initializer writes their
   10x12 and 7x12 shapes; inactive cells have a negative kind. */
typedef struct {
    s16 kind;
    s16 reserved;
    s32 column, row;
    s32 columns, rows;
} CmpPersonaGridEntry;

typedef struct {
    u8 red, green, blue, alpha;
} CmpPersonaColor;

/* The transition initializer and copier establish each 0x30-byte record. */
typedef struct {
    f32 sourceX, sourceY, targetX, targetY;
    f32 x, y;
    u8 sourceAlpha, targetAlpha, alpha, flags;
    u16 sourceScaleX, targetScaleX, scaleX;
    u16 sourceScaleY, targetScaleY, scaleY;
    s32 mode, duration;
} CmpPersonaMotion;

typedef struct {
    u8 alpha;
    u8 pad01[3];
    f32 x, y;
    s32 unk0C;
    s32 background;
    s32 phase, mode;
    s32 visible;
    s16 timer, pulseTimer;
    s16 partyIds[8];
    s16 partyCount;
    s16 rosterSlots[12];
    s16 personaCount;
    s16 selected[4];
    s16 previous[4];
    s16 footerMode;
    s16 unk62;
    CmpPersonaGridEntry primaryGrid[120];
    CmpPersonaGridEntry secondaryGrid[84];
    CmpPersonaMotion motion[28];
    CmpPersonaMotion backgroundCells[36];
    void *sprites[23];
    union {void *texture; s32 handle;} footer;
    u8 *portrait;
    u8 *model;
    u8 pad1CBC[8];
} CmpPersonaWork;
typedef char CmpPersonaWorkSize[sizeof(CmpPersonaWork) == 0x1CC4 ? 1 : -1];

/* measured: b210 -O2 with loop-invariant optimization. Independent initialization
   counters and per-resource sprite slots retain the retail loop scopes. The
   command-list boundary forwards a native message pointer to itfMesManager. */
/* Initialize the party and persona grids, transition rows, sprites and portrait/wipe tasks. */
// FUN_001356D0
#pragma push
#pragma opt_loop_invariants on
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpPersonaWork rewrite changed 74 instruction bytes and was reverted. */
void cmpPersonaMenuInit(u8* work) {
 extern void cmpPersonaBuildRosterList(u8* work);
 extern s16 datBuildMemberIdList(s16* work);
 extern void* memset(void* dst, s32 value, u32 size);
 extern u8* resourceFindByName(char* work);
 extern u8* sdkSpriteNewNode(u32 work, u32);
 extern u8 nmMesWindowOpenCurrent(u8* work);
 extern u8* datScreenWipeTaskCreate(s32 work, u16);
 extern u8* shdPersonaTaskCreate(s32 work, s32, s32, s32, s32);
 extern void shdPersonaSetPersonaId(u8* work, s32);
 extern s32 cmpPersonaSetMode(u8* work, s32);
 extern u8 D_005E57F0[];
 extern u8 D_005E5830[];
 extern u8 D_005E5850[];
 extern u8 D_005E9FB0[];
 extern u8 D_005EA2E0[];
 extern u8 D_0064A790[];
 u8* resource0;
 u8* resource2;
 u8* resource1;
 s32* slot;
 u8* p;
 u8* src;

 memset(work, 0, 0x1CC4);
 *(s32*)(work + 4) = 0;
 *(s32*)(work + 8) = 0;
 *(u8*)work = 0xFF;
 *(s32*)(work + 0x18) = -1;
 *(s16*)(work + 0x20) = 0;
 *(s32*)(work + 0x14) = 0;
 {
  s16 i;
  for (i = 0; i < 4; i++) {
   *(s16*)(work + i * 2 + 0x50) = 0;
   *(s16*)(work + i * 2 + 0x58) = 0;
  }
 }
 {
  s16 i;
  for (i = 0; i < 28; i++) {
   src = D_005EA2E0 + i * 0x1C;
   p = work + i * 0x30;
   *(f32*)(p + 0x1064) = *(f32*)(src + 0);
   *(f32*)(p + 0x1068) = *(f32*)(src + 4);
   *(u16*)(p + 0x1074) = (u16)*(f32*)(src + 8);
   *(u16*)(p + 0x107A) = (u16)*(f32*)(src + 0xC);
   *(u8*)(p + 0x106E) = *(u8*)(src + 0x10);
  }
 }
 {
  s16 i;
  for (i = 0; i < 120; i++) {
   p = work + i * 0x14;
   *(s32*)(p + 0x68) = i % 10;
   *(s32*)(p + 0x70) = 10;
   *(s32*)(p + 0x6C) = i / 10;
   *(s32*)(p + 0x74) = 12;
  }
 }
 {
  s16 i;
  for (i = 0; i < 84; i++) {
   p = work + i * 0x14;
   *(s32*)(p + 0x9C8) = i % 7;
   *(s32*)(p + 0x9D0) = 7;
   *(s32*)(p + 0x9CC) = i / 7;
   *(s32*)(p + 0x9D4) = 12;
  }
 }
 {
  s16 i;
  for (i = 0; i < 36; i++) {
   *(s32*)(work + i * 0x30 + 0x15A4) = 0;
   *(s32*)(work + i * 0x30 + 0x1594) = 0;
   *(s32*)(work + i * 0x30 + 0x15A0) = (s32)0xC2C80000;
   *(s32*)(work + i * 0x30 + 0x1598) = (s32)0xC2C80000;
   *(s8*)(work + i * 0x30 + 0x15AD) = 0x7F;
   *(s8*)(work + i * 0x30 + 0x15AC) = 0x7F;
   *(s32*)(work + i * 0x30 + 0x15BC) = 0;
   *(s32*)(work + i * 0x30 + 0x15C0) = 10;
  }
 }
 *(s16*)(work + 0x34) = datBuildMemberIdList((s16*)(work + 0x24));
 resource0 = resourceFindByName((char*)D_005E5830);
 if (resource0 == 0) {
  kAssertFail(&D_005EB580[0], 0x199);
 }
 resource1 = resourceFindByName((char*)D_005E5850);
 if (resource1 == 0) {
  kAssertFail(&D_005EB580[0], 0x19B);
 }
 *(u8**)(work + 0x1CB0) = resource2 = resourceFindByName((char*)D_005E57F0);
 if (resource2 == 0) {
  kAssertFail(&D_005EB580[0], 0x19D);
 }
 {
  s16 i;
  for (i = 0; i < 23; i++) {
   if (i < 6) {
    slot = (s32*)(work + i * 4 + 0x1C54);
    *slot = (s32)sdkSpriteNewNode((u32)resource0, *(u8*)(D_005E9FB0 + i));
   } else if (i < 9) {
    slot = (s32*)(work + i * 4 + 0x1C54);
    *slot = (s32)sdkSpriteNewNode((u32)resource2, *(u8*)(D_005E9FB0 + i));
   } else {
    slot = (s32*)(work + i * 4 + 0x1C54);
    *slot = (s32)sdkSpriteNewNode((u32)resource1, *(u8*)(D_005E9FB0 + i));
   }
   if (*slot == 0) {
    kAssertFail(&D_005EB580[0], 0x1AB);
   }
  }
 }
 nmMesWindowOpenCurrent(D_0064A790);
 cmpPersonaBuildRosterList(work);
 *(s32*)(work + 0x1CB8) = (s32)datScreenWipeTaskCreate(0, 1);
 *(s32*)(work + 0x1CB4) = (s32)shdPersonaTaskCreate(0, 0xC7, 0, 8, 3);
 shdPersonaSetPersonaId(*(u8**)(work + 0x1CB4), 0xB0);
 cmpPersonaSetMode(work, 0);
}

#pragma pop
/* Collect the consecutive active roster slots and record their count. */
// FUN_00135C10
void cmpPersonaBuildRosterList(u8* work) {
    s16 j = 0;
    s16 i = 0;
    while (j < 0xC) {
        if (datPersonaRosterSlotActive(j) == 0) {
            break;
        }
        ((CmpPersonaWork *)((u8*)work + i * 2))->rosterSlots[0] = j;
        i++;
        j++;
    }
    ((CmpPersonaWork *)((u8*)work))->personaCount = i;
}

// Advances the menu state from 0 to 1 and reports done; always returns 1 [inferred].
// FUN_00135CB0
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpPersonaWork rewrite changed 35 instruction bytes and was reverted. */
s32 cmpPersonaStateStep(u8 *work) {
    s32 v = *(s32 *)(work + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(work + 0x14) = v;
        return 1;
    default:
        return 1;
    }
}

/* Advance row transitions, update grid/background animations and draw the persona menu. */
// FUN_00135CF0
/* measured: without opt_common_subs off, mwcc CSEs (u8*)arg0 + 0x20 into a
   callee-saved pointer (nd 40); with it off each access keeps the
   base+offset form like retail (nd 0). */
#pragma opt_common_subs off
s32 cmpPersonaMenuUpdate(u8* work) {
    s32 i;
    s32 result = 1;
    u8* p;
    s32 v = ((CmpPersonaWork *)((u8*)work))->timer;
    if (v < 0x64) {
        ((CmpPersonaWork *)((u8*)work))->timer = v + 1;
    }
    for (i = 0; i < 0x1C; i++) {
        p = (u8*)work + i * 0x30;
        v = ((CmpPersonaWork *)((u8*)work))->timer;
        radarAnimateValue(p + 0x1054, v, 0);
        if (((CmpPersonaWork *)p)->motion[0].alpha != 0) {
            result = 0;
        }
    }
    cmpPersonaMenuStepAnimations(work);
    cmpPersonaMenuDraw(work);
    return result;
}
#pragma opt_common_subs on

/* Draw the persona menu's two colored grids, party rows and portrait pulse.
   Keep the position and complete RGBA snapshots shared between its draw phases.
   measured: all 4576 bytes match in this owner. Propagation-off retains the
   sprite and text-color snapshots; constant pulling-off preserves the retail
   float lifetimes. The 0.3f, 0.6f and pi/2 values are recovered pooled literals,
   not mutable runtime globals. See the recovery archive for the literal audit. */
// FUN_00135DC0
#pragma push
#pragma opt_pulloutconstants off
#pragma opt_propagation off
void cmpPersonaMenuDraw(u8* work)
{
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2f position, s32 alpha, s32 background, f32 depth);
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern void sdkSpriteDrawSized(u8 *sprite, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 width,
                              u16 height, s16 angle, f32 scale, s16 mode);
    extern f32 cmpGridCellFade(u8 *cell, f32 xEdge, f32 yEdge, f32 ceiling);
    extern void sdkSpriteDrawFooter(Vec2f position, f32 depth, u8 alpha, s32 mode, s32 texture);
    extern void RpSkyRenderStateSet(s32 state, s32 value);
    extern void datScreenWipeSetAlpha(u8 *task, u8 alpha);
    extern void datScreenWipeDraw(void *task);
    extern void cmpPersonaDrawRosterRow(u8 *work, s32 index);
    extern u32 datPersonaNamePart1(s16 character);
    extern int frFontExDrawText(f32 x, f32 y, f32 scale, int color, s8 font, int id, const char *text, int flags,
                             int extra);
    extern s32 shdPersonaGetChildTask(u8 *work);
    extern void shdPersonaDrawSineQuad(u8 *work);
    extern void shdPersonaDrawSmoothBar(u8 *work);
    extern void shdPersonaDispCtlSetMode(u8 *work, u8);
    extern void shdPersonaDispCtlGetPosition(u8 *work, u8 *);
    extern s32 shdPersonaDispCtlGetLoadedValue(u8 *work);
    extern f32 cosf(f32 angle);
    extern void shdDrawColourQuad(f32 depth, s32 color, f32 x, f32 y, f32 sourceX, f32 sourceY, f32 width, f32 height,
                              u8 *texture, s32 mode, s32 flag);
    extern void kAssertFail(void *file, s32 line);
    extern CmpPersonaColor D_005EB540[8];
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern s32 D_005EB580[];
    CmpPersonaWork *menu;
    u8 backdropBlue;
    u8 backdropGreen;
    u8 backdropOpacity;
    f32 opacity;
    f32 originX;
    f32 originY;
    CmpPersonaColor tint;
    Vec2f position;
    u8* rowBase;
    CmpPersonaColor *cellColor;
    f32 value;
    u8 drawOpacity;
    f32 width;
    f32 height;
    f32 cellFade;
    f32 opaqueOpacity;

    menu = (CmpPersonaWork *)work;
    sdkRenderStateSetDefault();
    originX = menu->x;
    originY = menu->y;
    opacity = (f32)menu->alpha / 255.0f;
    if (menu->background != 0) {
        position.x = originX;
        position.y = originY;
        value = 255.0f * opacity;
        drawOpacity = (u8)value;
        nLineDrawSet(position, drawOpacity, menu->background, 0.0f);
    }
    if ((menu->visible & 0x40) != 0) {
        s32 gridIndex;
        void *gridSprite;
        u8 gridAlpha;
        CmpPersonaGridEntry *gridCell;
        f32 cellY;
        f32 cellX;
        position.x = 227.0f + (originX + menu->motion[22].x);
        position.y = 9.0f + (originY + menu->motion[22].y);
        value = (f32)menu->motion[22].alpha * opacity;
        gridAlpha = (u8)value;
        gridSprite = menu->sprites[7];
        /* Work-relative row loads preserve the original base/immediate form;
           gridCell and node retain the complete 20-byte cell layout. */
        for (gridIndex = 0; gridIndex < 0x78; gridIndex++) {
            rowBase = work + gridIndex * 0x14;
            gridCell = (CmpPersonaGridEntry *)(rowBase + 0x64);
            if (gridCell->kind >= 0) {
                cellX = position.x + (f32)(((CmpPersonaWork *)rowBase)->primaryGrid[0].column * 44);
                cellY = position.y + (f32)(((CmpPersonaWork *)rowBase)->primaryGrid[0].row * 37);
                cellFade = cmpGridCellFade((u8 *)gridCell, 0.6f, 0.75f, 1.0f);
                cellColor = D_005EB540 + gridCell->kind;
                tint = cellColor[4];
                value = (f32)gridAlpha * cellFade;
                sdkSpriteDrawAt(gridSprite, cellX, cellY, tint.red, tint.green, tint.blue, (u8)value);
            }
        }
    }
    if ((menu->visible & 0x80) != 0) {
        s32 nodeIndex;
        u8 nodeBaseAlpha;
        void *nodeSprite;
        CmpPersonaGridEntry *node;
        f32 cellX;
        f32 cellY;
        position.x = 227.0f + (originX + menu->motion[23].x);
        position.y = 9.0f + (originY + menu->motion[23].y);
        nodeSprite = menu->sprites[8];
        RpSkyRenderStateSet(3, 0x71801);
        RpSkyRenderStateSet(2, 0x48);
        {
            s32 backgroundIndex;
            backgroundIndex = 0;
            value = 190.0f * opacity;
            backdropOpacity = (u8)value;
            tint.red = 0;
            tint.green = 0xFF;
            tint.blue = 0x64;
            backdropBlue = tint.blue;
            backdropGreen = tint.green;
            for (; backgroundIndex < 0x24; backgroundIndex++) {
                rowBase = work + backgroundIndex * 0x30;
                sdkSpriteDrawAt(nodeSprite, position.x + ((CmpPersonaWork *)rowBase)->backgroundCells[0].x,
                              position.y + ((CmpPersonaWork *)rowBase)->backgroundCells[0].y, tint.red, backdropGreen, backdropBlue,
                              backdropOpacity);
            }
        }
        RpSkyRenderStateSet(3, 0x717FB);
        RpSkyRenderStateSet(2, 0x44);
        value = (f32)menu->motion[23].alpha * opacity;
        /* This is the common grid fade. Each cell gets a fresh output alpha;
           the special palette never changes the base used by later cells. */
        nodeBaseAlpha = (u8)value;
        nodeIndex = 0;
        opaqueOpacity = 255.0f * opacity;
        for (; nodeIndex < 0x54; nodeIndex++) {
            u8 cellAlpha;
            rowBase = work + nodeIndex * 0x14;
            node = (CmpPersonaGridEntry *)(rowBase + 0x9C4);
            if (node->kind >= 0) {
                cellX = position.x + (f32)(((CmpPersonaWork *)rowBase)->secondaryGrid[0].column * 44);
                cellY = position.y + (f32)(((CmpPersonaWork *)rowBase)->secondaryGrid[0].row * 37);
                if (node->kind == 3) {
                    value = opaqueOpacity;
                    cellAlpha = (u8)value;
                } else {
                    cellFade = cmpGridCellFade((u8 *)node, 0.3f, 0.3f, 0.6f);
                    value = (f32)nodeBaseAlpha * cellFade;
                    cellAlpha = (u8)value;
                }
                cellColor = D_005EB540 + node->kind;
                tint = *cellColor;
                sdkSpriteDrawAt(nodeSprite, cellX, cellY, tint.red, tint.green, tint.blue, cellAlpha);
            }
        }
    }
    if ((menu->visible & 0x800) != 0) {
        value = 255.0f * opacity;
        datScreenWipeSetAlpha(menu->model, (u8)value);
        datScreenWipeDraw(menu->model);
    }
    if ((menu->visible & 0x2) != 0) {
        s32 rowColor;
        u8 *rowPalette;
        s8 rowStyle;
        u8 rowAlpha;
        s32 rowIndex;
        u8 *rowSprite;
        for (rowIndex = 0; rowIndex < menu->partyCount; rowIndex++) {
            rowBase = work + rowIndex * 0x30;
            position.x = 82.0f + (originX + ((CmpPersonaWork *)rowBase)->motion[14].x);
            position.y = 20.0f + (0.0f + (originY + ((CmpPersonaWork *)rowBase)->motion[14].y) + 33.0f * (f32)rowIndex);
            value = (f32)((CmpPersonaWork *)rowBase)->motion[14].alpha * opacity;
            rowAlpha = (u8)value;
            width = (f32)((CmpPersonaWork *)rowBase)->motion[14].scaleX;
            height = (f32)((CmpPersonaWork *)rowBase)->motion[14].scaleY;
            rowColor = rowAlpha | ~0xFF;
            if (menu->selected[0] == rowIndex) {
                rowPalette = D_0064B2E8;
                rowStyle = 8;
            } else {
                rowPalette = D_0064B2E0;
                rowStyle = 6;
            }
            rowSprite = menu->sprites[0];
            sdkSpriteDrawSized(rowSprite, position.x, position.y, 0.0f, rowPalette[0], rowPalette[1], rowPalette[2],
                          rowAlpha, width, height, 0, 0.0f, 0);
            rowSprite = menu->sprites[1];
            sdkSpriteDrawSized(rowSprite, 202.0f + position.x, position.y, 0.0f, rowPalette[0], rowPalette[1],
                          rowPalette[2], rowAlpha, width, height, 0, 0.0f, 0);
            frFontExDrawText(105.0f + position.x, position.y, 0.0f, rowColor, rowStyle, 1,
                          (const char*)datPersonaNamePart1(((CmpPersonaWork *)(work + rowIndex * 2))->partyIds[0]), 8, 0);
        }
    }
    if ((menu->visible & 0x100) != 0) {
        if (menu->portrait == 0) {
            kAssertFail(D_005EB580, 0x2AD);
        }
        {
            u8 *portraitTask = (u8 *)shdPersonaGetChildTask(menu->portrait);
            shdPersonaDispCtlSetMode(portraitTask, 0xFF);
            shdPersonaDrawSmoothBar(portraitTask);
            shdPersonaDrawSineQuad(portraitTask);
            if ((menu->visible & 0x1000) != 0) {
                s32 textureHandle;
                if ((textureHandle = shdPersonaDispCtlGetLoadedValue(portraitTask)) != 0) {
                    s32 pulseFrame;
                    u8 pulseOpacity;
                    s32 pulseColor;
                    shdPersonaDispCtlGetPosition(portraitTask, (u8 *)&position);
                    /* The position getter runs before the live timer read. */
                    pulseFrame = menu->pulseTimer;
                    if (pulseFrame < 5) {
                        pulseOpacity = 0xCC;
                    } else if (pulseFrame < 0x19) {
                        value = 204.0f * cosf((1.5707964f * (f32)(pulseFrame - 5)) / 20.0f);
                        pulseOpacity = (u8)value;
                    } else {
                        pulseOpacity = 0;
                    }
                    pulseColor = (pulseOpacity & 0xFF) | 0xDCDCDC00;
                    shdDrawColourQuad(0.0f, pulseColor, position.x, position.y, position.x, position.y, 512.0f, 512.0f,
                                  (u8 *)textureHandle, 0, 1);
                    RpSkyRenderStateSet(3, 0x717FB);
                    RpSkyRenderStateSet(2, 0x44);
                }
            }
        }
    }
    if ((menu->visible & 0x1) != 0) {
        position.x = 20.0f + (originX + menu->motion[27].x);
        position.y = 402.0f + (originY + menu->motion[27].y);
        value = (f32)menu->motion[27].alpha * opacity;
        drawOpacity = (u8)value;
        sdkSpriteDrawAt(menu->sprites[6], position.x, position.y, 0xFF, 0xFF, 0xFF, drawOpacity);
    }
    if ((menu->visible & 0x200) != 0) {
        position.x = 20.0f + (originX + menu->motion[25].x);
        position.y = 379.0f + (originY + menu->motion[25].y);
        value = (f32)menu->motion[25].alpha * opacity;
        drawOpacity = (u8)value;
        sdkSpriteDrawAt(menu->sprites[20], position.x, position.y, 0xFF, 0xFF, 0xFF, drawOpacity);
    }
    if ((menu->visible & 0x400) != 0) {
        position.x = 20.0f + (originX + menu->motion[26].x);
        position.y = 379.0f + (originY + menu->motion[26].y);
        value = (f32)menu->motion[26].alpha * opacity;
        drawOpacity = (u8)value;
        sdkSpriteDrawAt(menu->sprites[9], position.x, position.y, 0xFF, 0xFF, 0xFF, drawOpacity);
    }
    if ((menu->visible & 0x4) != 0) {
        s32 personaIndex;
        if (menu->personaCount == 0) {
            kAssertFail(D_005EB580, 0x2FB);
        } else {
            for (personaIndex = 0; personaIndex < (datPersonaRosterCapacity() & 0xFFFF); personaIndex++) {
                cmpPersonaDrawRosterRow(work, personaIndex);
            }
        }
    }
    position.x = 640.0f + (originX + menu->motion[24].x);
    position.y = 400.0f + (originY + menu->motion[24].y);
    value = (f32)menu->motion[24].alpha * opacity;
    drawOpacity = (u8)value;
    sdkSpriteDrawFooter(position, 0.0f, drawOpacity, menu->footerMode, menu->footer.handle);
}
#pragma pop

/* Save the previous cursor value and update one of the four selection slots. */
// FUN_00136FA0
s32 cmpPersonaSetSelection(s16* work, s32 slotIndex, s32 selection) {
    s32 idx = slotIndex * 2;
    s16* p = (s16*)(idx + (s32)work);
    ((CmpPersonaWork *)p)->previous[0] = ((CmpPersonaWork *)p)->selected[0];
    ((CmpPersonaWork *)p)->selected[0] = selection;
    return 1;
}

/* Advance portrait/background transitions and both grid groups; clear the pulse flag at frame 25. */
// FUN_00136FC0
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpPersonaWork rewrite changed 206 instruction bytes and was reverted. */
void cmpPersonaMenuStepAnimations(u8* work) {
    s16 pulseFrame;
    s32 i;

    pulseFrame = *(s16*)(work + 0x22);
    if (pulseFrame < 0x64) {
        *(s16*)(work + 0x22) = pulseFrame + 1;
    }
    if (*(s16*)(work + 0x22) == 0x19) {
        *(s32*)(work + 0x1C) &= ~0x1000;
    }
    for (i = 0; i < 0x24; i++) {
        radarAnimateValue(work + i * 0x30 + 0x1594, *(s16*)(work + 0x22), 0);
    }
    for (i = 0; i < 0x78; i++) {
        datCommunityEntryStep(work + i * 0x14 + 0x64);
    }
    for (i = 0; i < 0x54; i++) {
        datCommunityEntryStep(work + i * 0x14 + 0x9C4);
    }
}

/* measured: opt_propagation off preserves the retail stack-local value-pointer
   address sequence (MATCH); leaving propagation on folds the +0x40 into lh. */
#pragma opt_propagation off
/* Mark the 25 table-selected secondary-grid cells with randomized transition delays. */
// FUN_001370E0
void cmpPersonaScatterGridCells(u8* work) {
    s16 values[0x19];
    s16* src;
    s16* dst;
    s16* value;
    s16 idx;
    s32 count;
    s32 i;
    s32 offset;
    u8* p;

    src = &D_005EB590[0];
    dst = &values[0];
    count = 0x19;
    do {
        idx = *src;
        src++;
        count--;
        *dst = idx;
        dst++;
    } while (count > 0);
    for (i = 0; i < 0x19; i++) {
        offset = i * 2;
        value = (s16*)((u8*)&values[0] + offset);
        idx = *value;
        p = work + idx * 0x14;
        ((CmpPersonaWork *)p)->secondaryGrid[0].kind = 3;
        ((CmpPersonaWork *)p)->secondaryGrid[0].reserved = (s16)(RpRandom() % 0x19 + 0xF);
    }
}
#pragma opt_propagation on


/* measured: opt_common_subs off around the setup/switch and
   opt_loop_invariants on around the table loop reproduce the retail
   register/constant placement (MATCH). Plain `(u16)float` casts use MWCC's
   native overflow-safe conversion sequence (c.le.s 0x4F000000; trunc.w.s;
   mfc1; andi 0xFFFF with the out-of-line subtract/or path). shdPersonaLevelUpRoute
   receives the pointer loaded from 0x1CB4. The switch jump table has case 9
   targeting the default block, so no empty case is needed. */
#pragma opt_common_subs off
/* Snapshot current row poses and apply the persona-menu layout, footer and visibility flags. */
// FUN_001371A0
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpPersonaWork rewrite changed 579 instruction bytes and was reverted. */
s32 cmpPersonaSetMode(u8* work, s32 mode) {
    s32 i;
    s32 j;
    u8* table;
    u8* src;
    u8* dst;
    f32 value;
    table = 0;
    if (*(s32*)(work + 0x18) == mode) {
        return 0;
    }
    for (i = 0; i < 0x1C; i++) {
        dst = work + i * 0x30;
        *(f32*)(dst + 0x1054) = *(f32*)(dst + 0x1064);
        *(f32*)(dst + 0x1058) = *(f32*)(dst + 0x1068);
        *(u16*)(dst + 0x1070) = *(u16*)(dst + 0x1074);
        *(u16*)(dst + 0x1076) = *(u16*)(dst + 0x107A);
        *(u8*)(dst + 0x106C) = *(u8*)(dst + 0x106E);
    }
    switch (mode) {
    case 0:
        table = D_005E9FD0;
        *(s32*)(work + 0x1C) = 0x243;
        *(s16*)(work + 0x60) = 0;
        break;
    case 1:
        table = D_005EA2E0;
        break;
    case 2:
        table = D_005EA5F0;
        *(s32*)(work + 0x1C) = 0xA43;
        *(s16*)(work + 0x60) = 0;
        break;
    case 3:
        table = D_005EA900;
        *(s32*)(work + 0x1C) = 0xFE7;
        *(s16*)(work + 0x60) = 8;
        break;
    case 4:
    case 5:
        table = D_005EAC10;
        *(s32*)(work + 0x1C) = 0x5A5;
        *(s16*)(work + 0x60) = 8;
        break;
    case 6:
        table = D_005EAF20;
        *(s32*)(work + 0x1C) = 0x48D;
        *(s16*)(work + 0x60) = -1;
        shdPersonaLevelUpRoute(*(u8**)(work + 0x1CB4));
        break;
    case 7:
        table = D_005EAF20;
        *(s32*)(work + 0x1C) = 9;
        break;
    case 8:
        table = D_005EB230;
        *(s32*)(work + 0x1C) = 0xA13;
        *(s16*)(work + 0x60) = 0xE;
        shdPersonaLevelUpRoute(*(u8**)(work + 0x1CB4));
        break;
    case 10:
        *(s32*)(work + 0x1C) = 8;
        *(s16*)(work + 0x60) = -1;
        break;
    case 11:
        *(s32*)(work + 0x1C) = 0x5A5;
        *(s16*)(work + 0x60) = 8;
        break;
    case 12:
        *(s32*)(work + 0x1C) = 0x5A5;
        *(s16*)(work + 0x60) = 8;
        break;
    default:
        kAssertFail(D_005EB580, 0x3BA);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table/dst stride multiplies
   out of the j loop to match retail; without it the function mismatches. */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 0x1C; j++) {
            src = table + j * 0x1C;
            dst = work + j * 0x30;
            *(f32*)(dst + 0x105C) = *(f32*)(src + 0);
            *(f32*)(dst + 0x1060) = *(f32*)(src + 4);
            value = *(f32*)(src + 8);
            *(u16*)(dst + 0x1072) = (u16)value;
            value = *(f32*)(src + 0xC);
            *(u16*)(dst + 0x1078) = (u16)value;
            *(u8*)(dst + 0x106D) = *(u8*)(src + 0x10);
            *(s32*)(dst + 0x107C) = *(s32*)(src + 0x14);
            *(s32*)(dst + 0x1080) = *(s32*)(src + 0x18);
        }
    *(s16*)(work + 0x20) = 0;
    *(s32*)(work + 0x18) = mode;
    }
    return 1;
}
/* measured: closes the opt_loop_invariants on scope opened above for
   func_001371a0's table loop. */
#pragma opt_loop_invariants off

/* Move nonselected party rows vertically away from the selected row and fade them out. */
// FUN_001374D0
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void cmpPersonaSetPartyCursor(u8* work) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 8; i++) {
        cur = ((CmpPersonaWork *)((u8*)work))->selected[0];
        if (i == cur) {
            p = (u8*)work + i * 0x30;
            *(s32 *)&((CmpPersonaWork *)p)->motion[14].targetX = 0x44480000;
            *(s32 *)&((CmpPersonaWork *)p)->motion[14].targetY = 0;
            ((CmpPersonaWork *)p)->motion[14].targetAlpha = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)work + i * 0x30;
            *(s32 *)&((CmpPersonaWork *)p)->motion[14].targetX = 0;
            ((CmpPersonaWork *)p)->motion[14].targetY = f;
            ((CmpPersonaWork *)p)->motion[14].targetAlpha = 0;
        }
    }
}
/* measured: see annotation above (func_001374d0). */
#pragma opt_loop_invariants off

/* Snapshot roster row poses and set the selected row's horizontal target offset to 30. */
// FUN_00137570
/* measured: without opt_loop_invariants on, mwcc rematerializes the 0x41F00000
   constant inside the loop body (nd 22); with it the lui hoists to the
   preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void cmpPersonaResetRosterCursor(u8* work) {
    s32 i;
    u8* p;
    s32 c = 0x41F00000;
    for (i = 0; i < 0xC; i++) {
        p = (u8*)work + i * 0x30;
        ((CmpPersonaWork *)p)->motion[2].sourceX = ((CmpPersonaWork *)p)->motion[2].x;
        ((CmpPersonaWork *)p)->motion[2].sourceY = ((CmpPersonaWork *)p)->motion[2].y;
        ((CmpPersonaWork *)p)->motion[2].sourceAlpha = ((CmpPersonaWork *)p)->motion[2].alpha;
        if (((CmpPersonaWork *)((u8*)work))->selected[1] == i) {
            *(s32 *)&((CmpPersonaWork *)p)->motion[2].targetX = c;
        } else {
            *(s32 *)&((CmpPersonaWork *)p)->motion[2].targetX = 0;
        }
    }
    ((CmpPersonaWork *)((u8*)work))->timer = 0;
    ((CmpPersonaWork *)((u8*)work))->visible &= ~0x1000;
}
/* measured: see annotation above (func_00137570). */
#pragma opt_loop_invariants off


/* Randomize background-cell columns and delayed falling transitions, then enable the pulse flag. */
// FUN_001375F0
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
void cmpPersonaRandomizeBackgroundCells(u8 *work)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0x24; i++) {
        if (RpRandom() & 3) {
            p = work + i * 0x30;
            val = (RpRandom() % 7U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            ((CmpPersonaWork *)p)->backgroundCells[0].targetX = f;
            ((CmpPersonaWork *)p)->backgroundCells[0].sourceX = f;
            *(u32 *)&((CmpPersonaWork *)p)->backgroundCells[0].sourceY = 0x43FA0000;
            ((CmpPersonaWork *)p)->backgroundCells[0].y = ((CmpPersonaWork *)p)->backgroundCells[0].sourceY;
            *(s32 *)&((CmpPersonaWork *)p)->backgroundCells[0].targetY = 0xC2C80000;
            q = (u32 *)&((CmpPersonaWork *)p)->backgroundCells[0].mode;
            random = RpRandom() % 10U;
            *q = random;
            ((CmpPersonaWork *)p)->backgroundCells[0].duration = random + 0xA;
        } else {
            p = work + i * 0x30;
            ((CmpPersonaWork *)p)->backgroundCells[0].sourceY = ((CmpPersonaWork *)p)->backgroundCells[0].targetY;
        }
    }
    ((CmpPersonaWork *)work)->pulseTimer = 0;
    ((CmpPersonaWork *)work)->visible |= 0x1000;
}
/* measured: closing O1 probe. */
#pragma optimization_level 2

/* Move nonselected roster rows vertically away from the selected row and fade them out. */
// FUN_00137740
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void cmpPersonaSetRosterCursorMotion(u8* work) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 0xC; i++) {
        cur = ((CmpPersonaWork *)((u8*)work))->selected[1];
        if (i == cur) {
            p = (u8*)work + i * 0x30;
            *(s32 *)&((CmpPersonaWork *)p)->motion[2].targetX = 0x44480000;
            *(s32 *)&((CmpPersonaWork *)p)->motion[2].targetY = 0;
            ((CmpPersonaWork *)p)->motion[2].targetAlpha = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)work + i * 0x30;
            *(s32 *)&((CmpPersonaWork *)p)->motion[2].targetX = 0;
            ((CmpPersonaWork *)p)->motion[2].targetY = f;
            ((CmpPersonaWork *)p)->motion[2].targetAlpha = 0;
        }
    }
}
/* measured: see annotation above (func_00137740). */
#pragma opt_loop_invariants off

/* Free menu sprites, destroy the portrait and wipe tasks, and reset the message window. */
// FUN_001377E0
/* Raw work-relative accesses retain MWCC alias scheduling; the CmpPersonaWork rewrite changed 75 instruction bytes and was reverted. */
void cmpPersonaMenuRelease(u8* work) {
    u8* base = work;
    s32 i;
    s32* p;
    for (i = 0; i < 0x17; i++) {
        p = (s32*)(base + i * 4 + 0x1C54);
        if (*p != 0) {
            sdkSpriteFreeNode((void *)*p);
            *p = 0;
        }
    }
    if (*(s32*)(base + 0x1CB4) != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32*)(base + 0x1CB4));
        *(s32*)(base + 0x1CB4) = 0;
    }
    if (*(s32*)(base + 0x1CB8) != 0) {
        kwlnTaskDestroyWithHierarchy(*(s32*)(base + 0x1CB8));
        *(s32*)(base + 0x1CB8) = 0;
    }
    nmMesWindowResetCurrent();
    *(s32*)(base + 0x1C) = 0;
}

/* The menu initializer and transition copier establish this 0x30-byte
   position/opacity stride. This view starts at the third initialized row. */
typedef struct {
    f32 x;
    f32 y;
    u8 pad08[2];
    u8 alpha;
    u8 pad0B[0x25];
} CmpPersonaRosterRow;

typedef struct {
    u8 alpha;
    u8 pad01[3];
    f32 x;
    f32 y;
    u8 unk0C[0x10B8];
    CmpPersonaRosterRow rows[26];
} CmpPersonaRosterLayout;

/* Eight-byte header followed by two 0x3c-byte records, initialized by
   datPanelReset. The word and halfword views cover its actual header fields. */
typedef union {
    u8 bytes[0x80];
    s16 halves[0x40];
    s32 words[0x20];
} CmpPersonaPanel;

static inline u32 cmpPersonaOffsetAddress(u32 offset, u32 base)
{
    return offset + base;
}

/* measured: b210 -O2 emits 1340 exact bytes followed by four retail zero
   alignment bytes. The menu's typed row view preserves the parent-X load
   before the row-address addition. See the recovery archive for controls. */
// FUN_00137890
void cmpPersonaDrawRosterRow(u8 *work, s32 rowIndex)
{
    extern void datPanelReset(u8 *panel);
    extern void shdPersonaFillStatusBlock(u8 *persona, u8 *record, s32 mode);
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y,
                            u8 red, u8 green, u8 blue, u8 alpha);
    extern s32 func_00105330(s32 character);
    extern void shdPersonaDrawByMode(Vec2f position, u8 alpha, s16 *panel, f32 depth);
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E9[];
    extern u8 D_0064B2EA[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2ED[];
    extern u8 D_0064B2EE[];
    CmpPersonaRosterLayout *menu;
    f32 x;
    f32 y;
    f32 rowY;
    f32 opacity;
    u32 entryAlpha;
    u32 baseAlpha;
    u32 alpha;
    u8 spriteOpacity;
    s32 selected;
    u8 red;
    u8 green;
    u8 blue;
    u8 digitRed;
    u8 digitGreen;
    u8 digitBlue;
    u8 spriteAlpha;
    u8 level;
    CmpPersonaPanel panel;
    Vec2f position;

    if (rowIndex < 0 || rowIndex >= (datPersonaRosterCapacity() & 0xFFFF)) {
        kAssertFail(D_005EB580, 0x478);
    }
    menu = (CmpPersonaRosterLayout *)work;
    x = (menu->x + menu->rows[rowIndex].x) - 10.0f;
    y = 0.0f + (menu->y + menu->rows[rowIndex].y) +
        30.0f * (f32)rowIndex;
    entryAlpha = menu->rows[rowIndex].alpha;
    baseAlpha = menu->alpha;
    opacity = (f32)entryAlpha * ((f32)baseAlpha / 255.0f);
    alpha = spriteOpacity = (u8)opacity;
    if (rowIndex >= ((CmpPersonaWork *)work)->personaCount) {
        position.x = x - 40.0f;
        position.y = y + 21.0f;
        sdkSpriteDrawAt(((CmpPersonaWork *)work)->sprites[4], position.x, position.y,
                      0xFF, 0xE9, 0x2C, spriteOpacity);
        position.x = x + 89.0f;
        position.y = y + 21.0f;
        sdkSpriteDrawAt(((CmpPersonaWork *)work)->sprites[5], position.x, position.y,
                      0xFF, 0xE9, 0x2C, spriteOpacity);
    } else {
        datPanelReset(panel.bytes);
        if (rowIndex == ((CmpPersonaWork *)work)->selected[1]) {
            selected = 1;
            panel.halves[1] = selected;
            red = D_0064B2E8[0];
            green = D_0064B2E9[0];
            blue = D_0064B2EA[0];
            spriteAlpha = (u8)alpha;
            digitRed = D_0064B2EC[0];
            digitGreen = D_0064B2ED[0];
            digitBlue = D_0064B2EE[0];
        } else {
            panel.halves[1] = 0;
            red = 0xFF;
            green = 0xE9;
            blue = 0x2C;
            spriteAlpha = (u8)alpha;
            digitRed = 0xF7;
            digitGreen = 0xAF;
            digitBlue = 0x22;
            selected = 0;
        }
        panel.halves[0] = 2;
        shdPersonaFillStatusBlock((u8 *)datPersonaRosterSlot(((CmpPersonaWork *)((u8 *)cmpPersonaOffsetAddress(rowIndex * 2, (u32)work)))->rosterSlots[0]),
                      panel.bytes + 8, 2);
        position.x = x - 40.0f;
        position.y = y + 21.0f;
        sdkSpriteDrawAt(((CmpPersonaWork *)work)->sprites[2], position.x, position.y,
                      red, green, blue, spriteAlpha);
        position.x = x + 89.0f;
        position.y = y + 21.0f;
        sdkSpriteDrawAt(((CmpPersonaWork *)work)->sprites[3], position.x, position.y,
                      red, green, blue, spriteAlpha);
        level = panel.bytes[12];
        position.x = x + 72.0f;
        rowY = y + 26.0f;
        position.y = rowY;
        do {
            sdkSpriteDrawAt(((CmpPersonaWork *)(work + (level % 10) * 4))->sprites[10],
                          position.x, position.y,
                          digitRed, digitGreen, digitBlue, spriteAlpha);
            position.x -= 22.0f;
            level /= 10U;
        } while (level > 0);
        if (selected != 0) {
            position.x = x + 24.0f;
            position.y = y + 33.0f;
            sdkSpriteDrawAt(((CmpPersonaWork *)work)->sprites[21], position.x, position.y,
                          digitRed, digitGreen, digitBlue, spriteAlpha);
        }
        if (rowIndex == func_00105330(1) && (*(u32 *)&((CmpPersonaWork *)work)->visible & 0x20)) {
            position.x = 22.0f;
            position.y = rowY;
            sdkSpriteDrawAt(((CmpPersonaWork *)work)->sprites[22], position.x, position.y,
                          0xFF, 0x85, 0x1F, spriteAlpha);
        }
        position.x = x + 99.0f;
        position.y = y + 20.0f;
        shdPersonaDrawByMode(position, spriteOpacity, panel.halves, 0.0f);
    }
}
/* Report whether every row transition reached its end frame and the shared line animation is idle. */
// FUN_00137DD0
s32 cmpPersonaRowsSettled(u8* work) {
    s32 result = 1;
    s32 i = 0;
    s32 cmp = ((CmpPersonaWork *)((u8*)work))->timer;
    for (; i < 0x1C; i++) {
        if (cmp < ((CmpPersonaWork *)((u8*)work + i * 0x30))->motion[0].duration) {
            result = 0;
        }
    }
    return result & nLineIsIdle();
}

/* Configure the screen-wipe endpoints, direction, offset and color from its preset table. */
// FUN_00137E50
void cmpPersonaStartScreenWipe(s32 task, s32 presetOrColor, s32 initialize, s32 reverse) {
    u8* start;
    u8* target;
    CmpPair pair;
    if ((presetOrColor < 0) || (presetOrColor > 0)) {
        kAssertFail(&D_005EB580[0], 0x505);
    }
    if (task == 0) {
        kAssertFail(&D_005EB580[0], 0x506);
    }
    if (reverse != 0) {
        target = &D_005EB560[presetOrColor * 0x1C];
        start = target + 8;
    } else {
        start = &D_005EB560[presetOrColor * 0x1C];
        target = start + 8;
    }
    pair = *(CmpPair*)&D_005EB570[presetOrColor * 0x1C];
    presetOrColor = *(s32*)&D_005EB578[presetOrColor * 0x1C];
    if (initialize != 0) {
        datScreenWipeInit(task, start, target);
    } else {
        datScreenWipeSetTarget(task, target, target);
    }
    datScreenWipeSetOffset(task, pair);
    datScreenWipeSetColor(task, presetOrColor);
}

#include "include_asm.h"
/* Persona 4 USA decompilation - cmpPersona.c */
/* Translation unit recovered from embedded __FILE__ strings (retail asserts). */
#include "type.h"
#include "shd_misc_internal.h"

typedef struct CmpHead CmpHead;
struct CmpHead {
    u8 _pad00[0x1C];
    s32 flags; // 0x1C
    s16 f20;   // 0x20
    s16 f22;   // 0x22
};

s32 func_0010abd0(s16 arg0);
s32 func_0034c210(void);
void func_001437b0(void* arg0, s32 arg1, s32 arg2);
void func_0034f5d0(void* arg0);
u32 RpRandom(void);
void func_0046d280(void *node);
void func_00452080(s32 arg0);
void func_002bb4e0(void);
void func_003550d0(s32 arg0, void* arg1, void* arg2);
void func_00355070(s32 arg0, void* arg1, void* arg2);
void func_00355300(s32 arg0, s32 arg1);
void func_0046d730(void* arg0, s32 arg1);
void func_00136fc0(u8* arg0);
void func_00135dc0(u8* arg0);
extern s32 D_005EB580[];
extern u8 D_005EB560[];
extern u8 D_005EB570[];
extern u8 D_005EB578[];
extern s16 D_005EB590[];
extern void func_0011cee0(u8* arg0);
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
void func_003552d0(s32 arg0, CmpPair arg1);

/* measured: b210 -O2 with loop-invariant optimization. Independent initialization
   counters and per-resource sprite slots retain the retail loop scopes. The
   command-list boundary forwards a native message pointer to itfMesManager. */
// FUN_001356D0
#pragma push
#pragma opt_loop_invariants on
void func_001356d0(u8* arg0) {
 extern void func_00135c10(u8* arg0);
 extern s16 func_00353c10(s16* arg0);
 extern void* memset(void* dst, s32 value, u32 size);
 extern u8* func_0046a770(char* arg0);
 extern u8* func_0046d200(u32 arg0, u32 arg1);
 extern u8 func_002baac0(u8* arg0);
 extern u8* func_00354a50(s32 arg0, u16 arg1);
 extern u8* func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
 extern void func_00117580(u8* arg0, s32 arg1);
 extern s32 func_001371a0(u8* arg0, s32 arg1);
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

 memset(arg0, 0, 0x1CC4);
 *(s32*)(arg0 + 4) = 0;
 *(s32*)(arg0 + 8) = 0;
 *(u8*)arg0 = 0xFF;
 *(s32*)(arg0 + 0x18) = -1;
 *(s16*)(arg0 + 0x20) = 0;
 *(s32*)(arg0 + 0x14) = 0;
 {
  s16 i;
  for (i = 0; i < 4; i++) {
   *(s16*)(arg0 + i * 2 + 0x50) = 0;
   *(s16*)(arg0 + i * 2 + 0x58) = 0;
  }
 }
 {
  s16 i;
  for (i = 0; i < 28; i++) {
   src = D_005EA2E0 + i * 0x1C;
   p = arg0 + i * 0x30;
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
   p = arg0 + i * 0x14;
   *(s32*)(p + 0x68) = i % 10;
   *(s32*)(p + 0x70) = 10;
   *(s32*)(p + 0x6C) = i / 10;
   *(s32*)(p + 0x74) = 12;
  }
 }
 {
  s16 i;
  for (i = 0; i < 84; i++) {
   p = arg0 + i * 0x14;
   *(s32*)(p + 0x9C8) = i % 7;
   *(s32*)(p + 0x9D0) = 7;
   *(s32*)(p + 0x9CC) = i / 7;
   *(s32*)(p + 0x9D4) = 12;
  }
 }
 {
  s16 i;
  for (i = 0; i < 36; i++) {
   *(s32*)(arg0 + i * 0x30 + 0x15A4) = 0;
   *(s32*)(arg0 + i * 0x30 + 0x1594) = 0;
   *(s32*)(arg0 + i * 0x30 + 0x15A0) = (s32)0xC2C80000;
   *(s32*)(arg0 + i * 0x30 + 0x1598) = (s32)0xC2C80000;
   *(s8*)(arg0 + i * 0x30 + 0x15AD) = 0x7F;
   *(s8*)(arg0 + i * 0x30 + 0x15AC) = 0x7F;
   *(s32*)(arg0 + i * 0x30 + 0x15BC) = 0;
   *(s32*)(arg0 + i * 0x30 + 0x15C0) = 10;
  }
 }
 *(s16*)(arg0 + 0x34) = func_00353c10((s16*)(arg0 + 0x24));
 resource0 = func_0046a770((char*)D_005E5830);
 if (resource0 == 0) {
  func_0046d730(&D_005EB580[0], 0x199);
 }
 resource1 = func_0046a770((char*)D_005E5850);
 if (resource1 == 0) {
  func_0046d730(&D_005EB580[0], 0x19B);
 }
 *(u8**)(arg0 + 0x1CB0) = resource2 = func_0046a770((char*)D_005E57F0);
 if (resource2 == 0) {
  func_0046d730(&D_005EB580[0], 0x19D);
 }
 {
  s16 i;
  for (i = 0; i < 23; i++) {
   if (i < 6) {
    slot = (s32*)(arg0 + i * 4 + 0x1C54);
    *slot = (s32)func_0046d200((u32)resource0, *(u8*)(D_005E9FB0 + i));
   } else if (i < 9) {
    slot = (s32*)(arg0 + i * 4 + 0x1C54);
    *slot = (s32)func_0046d200((u32)resource2, *(u8*)(D_005E9FB0 + i));
   } else {
    slot = (s32*)(arg0 + i * 4 + 0x1C54);
    *slot = (s32)func_0046d200((u32)resource1, *(u8*)(D_005E9FB0 + i));
   }
   if (*slot == 0) {
    func_0046d730(&D_005EB580[0], 0x1AB);
   }
  }
 }
 func_002baac0(D_0064A790);
 func_00135c10(arg0);
 *(s32*)(arg0 + 0x1CB8) = (s32)func_00354a50(0, 1);
 *(s32*)(arg0 + 0x1CB4) = (s32)func_00117780(0, 0xC7, 0, 8, 3);
 func_00117580(*(u8**)(arg0 + 0x1CB4), 0xB0);
 func_001371a0(arg0, 0);
}

#pragma pop
// FUN_00135C10
void func_00135c10(u8* arg0) {
    s16 j = 0;
    s16 i = 0;
    while (j < 0xC) {
        if (func_0010abd0(j) == 0) {
            break;
        }
        *(s16*)((u8*)arg0 + i * 2 + 0x36) = j;
        i++;
        j++;
    }
    *(s16*)((u8*)arg0 + 0x4E) = i;
}

// FUN_00135CB0
s32 func_00135cb0(u8 *arg0) {
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
        return 1;
    default:
        return 1;
    }
}

// FUN_00135CF0
/* measured: without opt_common_subs off, mwcc CSEs (u8*)arg0 + 0x20 into a
   callee-saved pointer (nd 40); with it off each access keeps the
   base+offset form like retail (nd 0). */
#pragma opt_common_subs off
s32 func_00135cf0(u8* arg0) {
    s32 i;
    s32 result = 1;
    u8* p;
    s32 v = *(s16*)((u8*)arg0 + 0x20);
    if (v < 0x64) {
        *(s16*)((u8*)arg0 + 0x20) = v + 1;
    }
    for (i = 0; i < 0x1C; i++) {
        p = (u8*)arg0 + i * 0x30;
        v = *(s16*)((u8*)arg0 + 0x20);
        func_001437b0(p + 0x1054, v, 0);
        if (*(u8*)(p + 0x106E) != 0) {
            result = 0;
        }
    }
    func_00136fc0(arg0);
    func_00135dc0(arg0);
    return result;
}
#pragma opt_common_subs on

/* Both 0x14-byte grids have a signed palette index, integer coordinates,
   and dimensions consumed by func_0034f720. The initializer writes their
   10x12 and 7x12 shapes; inactive cells have a negative kind. */
typedef struct {
    s16 kind;
    s16 reserved;
    s32 column, row;
    s32 columns, rows;
} PersonaGridEntry;

typedef struct {
    u8 red, green, blue, alpha;
} PersonaMenuColor;

/* The transition initializer and copier establish each 0x30-byte record. */
typedef struct {
    f32 sourceX, sourceY, targetX, targetY;
    f32 x, y;
    u8 sourceAlpha, targetAlpha, alpha, flags;
    u16 sourceScaleX, targetScaleX, scaleX;
    u16 sourceScaleY, targetScaleY, scaleY;
    s32 mode, duration;
} PersonaMenuMotion;

typedef struct {
    u8 alpha;
    u8 _01[3];
    f32 x, y;
    s32 _0c;
    s32 background;
    s32 _14[2];
    s32 visible;
    s16 timer, pulseTimer;
    s16 partyIds[8];
    s16 partyCount;
    u8 _36[0x18];
    s16 personaCount;
    s16 selected[4];
    s16 previous[4];
    s16 footerMode;
    s16 _62;
    PersonaGridEntry primaryGrid[120];
    PersonaGridEntry secondaryGrid[84];
    PersonaMenuMotion motion[28];
    PersonaMenuMotion backgroundCells[36];
    void *sprites[23];
    union {void *texture; s32 handle;} footer;
    u8 *portrait;
    u8 *model;
    u8 _1cbc[8];
} PersonaMenuView;

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
void func_00135dc0(u8* work)
{
    extern void func_0034f1e0(void);
    extern void func_0034c270(Vec2f position, s32 alpha, s32 background, f32 depth);
    extern void func_0034f2e0(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern void func_0034f320(u8 *sprite, f32 x, f32 y, f32 depth, u8 red, u8 green, u8 blue, u8 alpha, u16 width,
                              u16 height, s16 angle, f32 scale, s16 mode);
    extern f32 func_0034f720(u8 *cell, f32 xEdge, f32 yEdge, f32 ceiling);
    extern void func_0034f9d0(Vec2f position, f32 depth, u8 alpha, s32 mode, s32 texture);
    extern void RpSkyRenderStateSet(s32 state, s32 value);
    extern void func_00355410(u8 *task, u8 alpha);
    extern void func_00354ba0(void *task);
    extern void func_00137890(u8 *work, s32 index);
    extern s32 func_0010b5b0(void);
    extern u32 func_0010d6d0(s16 character);
    extern int func_00274ed0(f32 x, f32 y, f32 scale, int color, s8 font, int id, const char *text, int flags,
                             int extra);
    extern s32 func_0011d1e0(u8 *work);
    extern void func_0011dc50(u8 *work);
    extern void func_0011dd50(u8 *work);
    extern void func_0011de40(u8 *work, u8 arg1);
    extern void func_0011e400(u8 *work, u8 *arg1);
    extern s32 func_0011e460(u8 *work);
    extern f32 cosf(f32 angle);
    extern void func_00364680(f32 depth, s32 color, f32 x, f32 y, f32 sourceX, f32 sourceY, f32 width, f32 height,
                              u8 *texture, s32 mode, s32 flag);
    extern void func_0046d730(void *file, s32 line);
    extern PersonaMenuColor D_005EB540[8];
    extern u8 D_0064B2E0[];
    extern u8 D_0064B2E8[];
    extern s32 D_005EB580[];
    PersonaMenuView *menu;
    u8 backdropBlue;
    u8 backdropGreen;
    u8 backdropOpacity;
    f32 opacity;
    f32 originX;
    f32 originY;
    PersonaMenuColor tint;
    Vec2f position;
    u8* rowBase;
    PersonaMenuColor *cellColor;
    f32 value;
    u8 drawOpacity;
    f32 width;
    f32 height;
    f32 cellFade;
    f32 opaqueOpacity;

    menu = (PersonaMenuView *)work;
    func_0034f1e0();
    originX = menu->x;
    originY = menu->y;
    opacity = (f32)menu->alpha / 255.0f;
    if (menu->background != 0) {
        position.x = originX;
        position.y = originY;
        value = 255.0f * opacity;
        drawOpacity = (u8)value;
        func_0034c270(position, drawOpacity, menu->background, 0.0f);
    }
    if ((menu->visible & 0x40) != 0) {
        s32 gridIndex;
        void *gridSprite;
        u8 gridAlpha;
        PersonaGridEntry *gridCell;
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
            gridCell = (PersonaGridEntry *)(rowBase + 0x64);
            if (gridCell->kind >= 0) {
                cellX = position.x + (f32)(*(s32*)(rowBase + 0x68) * 44);
                cellY = position.y + (f32)(*(s32*)(rowBase + 0x6C) * 37);
                cellFade = func_0034f720((u8 *)gridCell, 0.6f, 0.75f, 1.0f);
                cellColor = D_005EB540 + gridCell->kind;
                tint = cellColor[4];
                value = (f32)gridAlpha * cellFade;
                func_0034f2e0(gridSprite, cellX, cellY, tint.red, tint.green, tint.blue, (u8)value);
            }
        }
    }
    if ((menu->visible & 0x80) != 0) {
        s32 nodeIndex;
        u8 nodeBaseAlpha;
        void *nodeSprite;
        PersonaGridEntry *node;
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
                func_0034f2e0(nodeSprite, position.x + *(f32*)(rowBase + 0x15A4),
                              position.y + *(f32*)(rowBase + 0x15A8), tint.red, backdropGreen, backdropBlue,
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
            node = (PersonaGridEntry *)(rowBase + 0x9C4);
            if (node->kind >= 0) {
                cellX = position.x + (f32)(*(s32*)(rowBase + 0x9C8) * 44);
                cellY = position.y + (f32)(*(s32*)(rowBase + 0x9CC) * 37);
                if (node->kind == 3) {
                    value = opaqueOpacity;
                    cellAlpha = (u8)value;
                } else {
                    cellFade = func_0034f720((u8 *)node, 0.3f, 0.3f, 0.6f);
                    value = (f32)nodeBaseAlpha * cellFade;
                    cellAlpha = (u8)value;
                }
                cellColor = D_005EB540 + node->kind;
                tint = *cellColor;
                func_0034f2e0(nodeSprite, cellX, cellY, tint.red, tint.green, tint.blue, cellAlpha);
            }
        }
    }
    if ((menu->visible & 0x800) != 0) {
        value = 255.0f * opacity;
        func_00355410(menu->model, (u8)value);
        func_00354ba0(menu->model);
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
            position.x = 82.0f + (originX + *(f32*)(rowBase + 0x1304));
            position.y = 20.0f + (0.0f + (originY + *(f32*)(rowBase + 0x1308)) + 33.0f * (f32)rowIndex);
            value = (f32)*(u8*)(rowBase + 0x130E) * opacity;
            rowAlpha = (u8)value;
            width = (f32)*(u16*)(rowBase + 0x1314);
            height = (f32)*(u16*)(rowBase + 0x131A);
            rowColor = rowAlpha | ~0xFF;
            if (menu->selected[0] == rowIndex) {
                rowPalette = D_0064B2E8;
                rowStyle = 8;
            } else {
                rowPalette = D_0064B2E0;
                rowStyle = 6;
            }
            rowSprite = menu->sprites[0];
            func_0034f320(rowSprite, position.x, position.y, 0.0f, rowPalette[0], rowPalette[1], rowPalette[2],
                          rowAlpha, width, height, 0, 0.0f, 0);
            rowSprite = menu->sprites[1];
            func_0034f320(rowSprite, 202.0f + position.x, position.y, 0.0f, rowPalette[0], rowPalette[1],
                          rowPalette[2], rowAlpha, width, height, 0, 0.0f, 0);
            func_00274ed0(105.0f + position.x, position.y, 0.0f, rowColor, rowStyle, 1,
                          (const char*)func_0010d6d0(*(s16*)(work + rowIndex * 2 + 0x24)), 8, 0);
        }
    }
    if ((menu->visible & 0x100) != 0) {
        if (menu->portrait == 0) {
            func_0046d730(D_005EB580, 0x2AD);
        }
        {
            u8 *portraitTask = (u8 *)func_0011d1e0(menu->portrait);
            func_0011de40(portraitTask, 0xFF);
            func_0011dd50(portraitTask);
            func_0011dc50(portraitTask);
            if ((menu->visible & 0x1000) != 0) {
                s32 textureHandle;
                if ((textureHandle = func_0011e460(portraitTask)) != 0) {
                    s32 pulseFrame;
                    u8 pulseOpacity;
                    s32 pulseColor;
                    func_0011e400(portraitTask, (u8 *)&position);
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
                    func_00364680(0.0f, pulseColor, position.x, position.y, position.x, position.y, 512.0f, 512.0f,
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
        func_0034f2e0(menu->sprites[6], position.x, position.y, 0xFF, 0xFF, 0xFF, drawOpacity);
    }
    if ((menu->visible & 0x200) != 0) {
        position.x = 20.0f + (originX + menu->motion[25].x);
        position.y = 379.0f + (originY + menu->motion[25].y);
        value = (f32)menu->motion[25].alpha * opacity;
        drawOpacity = (u8)value;
        func_0034f2e0(menu->sprites[20], position.x, position.y, 0xFF, 0xFF, 0xFF, drawOpacity);
    }
    if ((menu->visible & 0x400) != 0) {
        position.x = 20.0f + (originX + menu->motion[26].x);
        position.y = 379.0f + (originY + menu->motion[26].y);
        value = (f32)menu->motion[26].alpha * opacity;
        drawOpacity = (u8)value;
        func_0034f2e0(menu->sprites[9], position.x, position.y, 0xFF, 0xFF, 0xFF, drawOpacity);
    }
    if ((menu->visible & 0x4) != 0) {
        s32 personaIndex;
        if (menu->personaCount == 0) {
            func_0046d730(D_005EB580, 0x2FB);
        } else {
            for (personaIndex = 0; personaIndex < (func_0010b5b0() & 0xFFFF); personaIndex++) {
                func_00137890(work, personaIndex);
            }
        }
    }
    position.x = 640.0f + (originX + menu->motion[24].x);
    position.y = 400.0f + (originY + menu->motion[24].y);
    value = (f32)menu->motion[24].alpha * opacity;
    drawOpacity = (u8)value;
    func_0034f9d0(position, 0.0f, drawOpacity, menu->footerMode, menu->footer.handle);
}
#pragma pop

// FUN_00136FA0
s32 func_00136fa0(s16* arg0, s32 arg1, s32 arg2) {
    s32 idx = arg1 * 2;
    s16* p = (s16*)(idx + (s32)arg0);
    p[0x2C] = p[0x28];
    p[0x28] = arg2;
    return 1;
}

// FUN_00136FC0
void func_00136fc0(u8* arg0) {
    s16 temp_3;
    s32 i;

    temp_3 = *(s16*)(arg0 + 0x22);
    if (temp_3 < 0x64) {
        *(s16*)(arg0 + 0x22) = temp_3 + 1;
    }
    if (*(s16*)(arg0 + 0x22) == 0x19) {
        *(s32*)(arg0 + 0x1C) &= ~0x1000;
    }
    for (i = 0; i < 0x24; i++) {
        func_001437b0(arg0 + i * 0x30 + 0x1594, *(s16*)(arg0 + 0x22), 0);
    }
    for (i = 0; i < 0x78; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x64);
    }
    for (i = 0; i < 0x54; i++) {
        func_0034f5d0(arg0 + i * 0x14 + 0x9C4);
    }
}

/* measured: opt_propagation off preserves the retail stack-local value-pointer
   address sequence (MATCH); leaving propagation on folds the +0x40 into lh. */
#pragma opt_propagation off
// FUN_001370E0
void func_001370e0(u8* arg0) {
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
        p = arg0 + idx * 0x14;
        *(s16*)(p + 0x9C4) = 3;
        *(s16*)(p + 0x9C6) = (s16)(RpRandom() % 0x19 + 0xF);
    }
}
#pragma opt_propagation on


/* measured: opt_common_subs off around the setup/switch and
   opt_loop_invariants on around the table loop reproduce the retail
   register/constant placement (MATCH). Plain `(u16)float` casts use MWCC's
   native overflow-safe conversion sequence (c.le.s 0x4F000000; trunc.w.s;
   mfc1; andi 0xFFFF with the out-of-line subtract/or path). func_0011cee0
   receives the pointer loaded from 0x1CB4. The switch jump table has case 9
   targeting the default block, so no empty case is needed. */
#pragma opt_common_subs off
// FUN_001371A0
s32 func_001371a0(u8* arg0, s32 arg1) {
    s32 i;
    s32 j;
    u8* table;
    u8* src;
    u8* dst;
    f32 value;
    table = 0;
    if (*(s32*)(arg0 + 0x18) == arg1) {
        return 0;
    }
    for (i = 0; i < 0x1C; i++) {
        dst = arg0 + i * 0x30;
        *(f32*)(dst + 0x1054) = *(f32*)(dst + 0x1064);
        *(f32*)(dst + 0x1058) = *(f32*)(dst + 0x1068);
        *(u16*)(dst + 0x1070) = *(u16*)(dst + 0x1074);
        *(u16*)(dst + 0x1076) = *(u16*)(dst + 0x107A);
        *(u8*)(dst + 0x106C) = *(u8*)(dst + 0x106E);
    }
    switch (arg1) {
    case 0:
        table = D_005E9FD0;
        *(s32*)(arg0 + 0x1C) = 0x243;
        *(s16*)(arg0 + 0x60) = 0;
        break;
    case 1:
        table = D_005EA2E0;
        break;
    case 2:
        table = D_005EA5F0;
        *(s32*)(arg0 + 0x1C) = 0xA43;
        *(s16*)(arg0 + 0x60) = 0;
        break;
    case 3:
        table = D_005EA900;
        *(s32*)(arg0 + 0x1C) = 0xFE7;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 4:
    case 5:
        table = D_005EAC10;
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 6:
        table = D_005EAF20;
        *(s32*)(arg0 + 0x1C) = 0x48D;
        *(s16*)(arg0 + 0x60) = -1;
        func_0011cee0(*(u8**)(arg0 + 0x1CB4));
        break;
    case 7:
        table = D_005EAF20;
        *(s32*)(arg0 + 0x1C) = 9;
        break;
    case 8:
        table = D_005EB230;
        *(s32*)(arg0 + 0x1C) = 0xA13;
        *(s16*)(arg0 + 0x60) = 0xE;
        func_0011cee0(*(u8**)(arg0 + 0x1CB4));
        break;
    case 10:
        *(s32*)(arg0 + 0x1C) = 8;
        *(s16*)(arg0 + 0x60) = -1;
        break;
    case 11:
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    case 12:
        *(s32*)(arg0 + 0x1C) = 0x5A5;
        *(s16*)(arg0 + 0x60) = 8;
        break;
    default:
        func_0046d730(D_005EB580, 0x3BA);
        break;
    }
#pragma opt_common_subs on
/* measured: opt_loop_invariants on hoists the table/dst stride multiplies
   out of the j loop to match retail; without it the function mismatches. */
#pragma opt_loop_invariants on
    if (table != 0) {
        for (j = 0; j < 0x1C; j++) {
            src = table + j * 0x1C;
            dst = arg0 + j * 0x30;
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
    *(s16*)(arg0 + 0x20) = 0;
    *(s32*)(arg0 + 0x18) = arg1;
    }
    return 1;
}
/* measured: closes the opt_loop_invariants on scope opened above for
   func_001371a0's table loop. */
#pragma opt_loop_invariants off

// FUN_001374D0
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_001374d0(u8* arg0) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 8; i++) {
        cur = *(s16*)((u8*)arg0 + 0x50);
        if (i == cur) {
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x12FC) = 0x44480000;
            *(s32*)(p + 0x1300) = 0;
            *(u8*)(p + 0x130D) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x12FC) = 0;
            *(f32*)(p + 0x1300) = f;
            *(u8*)(p + 0x130D) = 0;
        }
    }
}
/* measured: see annotation above (func_001374d0). */
#pragma opt_loop_invariants off

// FUN_00137570
/* measured: without opt_loop_invariants on, mwcc rematerializes the 0x41F00000
   constant inside the loop body (nd 22); with it the lui hoists to the
   preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_00137570(u8* arg0) {
    s32 i;
    u8* p;
    s32 c = 0x41F00000;
    for (i = 0; i < 0xC; i++) {
        p = (u8*)arg0 + i * 0x30;
        *(f32*)(p + 0x10B4) = *(f32*)(p + 0x10C4);
        *(f32*)(p + 0x10B8) = *(f32*)(p + 0x10C8);
        *(u8*)(p + 0x10CC) = *(u8*)(p + 0x10CE);
        if (*(s16*)((u8*)arg0 + 0x52) == i) {
            *(s32*)(p + 0x10BC) = c;
        } else {
            *(s32*)(p + 0x10BC) = 0;
        }
    }
    *(s16*)((u8*)arg0 + 0x20) = 0;
    *(s32*)((u8*)arg0 + 0x1C) &= ~0x1000;
}
/* measured: see annotation above (func_00137570). */
#pragma opt_loop_invariants off


// FUN_001375F0
/* measured: probing O1 for retail's extra saved pointer. */
#pragma optimization_level 1
void func_001375f0(u8 *arg0)
{
    f32 f;
    u32 val;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0x24; i++) {
        if (RpRandom() & 3) {
            p = arg0 + i * 0x30;
            val = (RpRandom() % 7U) * 0x2C;
            if (val >= 0) {
                f = (f32)val;
            } else {
                val = (val >> 1) | (val & 1);
                f = (f32)(s32)val;
                f += f;
            }
            *(f32 *)(p + 0x159C) = f;
            *(f32 *)(p + 0x1594) = f;
            *(u32 *)(p + 0x1598) = 0x43FA0000;
            *(f32 *)(p + 0x15A8) = *(f32 *)(p + 0x1598);
            *(s32 *)(p + 0x15A0) = 0xC2C80000;
            q = (u32 *)(p + 0x15BC);
            random = RpRandom() % 10U;
            *q = random;
            *(s32 *)(p + 0x15C0) = random + 0xA;
        } else {
            p = arg0 + i * 0x30;
            *(f32 *)(p + 0x1598) = *(f32 *)(p + 0x15A0);
        }
    }
    *(s16 *)(arg0 + 0x22) = 0;
    *(s32 *)(arg0 + 0x1C) |= 0x1000;
}
/* measured: closing O1 probe. */
#pragma optimization_level 2

// FUN_00137740
/* measured: without opt_loop_invariants on, the 200.0f/-200.0f/0x44480000
   constants are rematerialized inside the loop (nd 39); with it they hoist
   to the preheader like retail (nd 0). */
#pragma opt_loop_invariants on
void func_00137740(u8* arg0) {
    s32 i;
    s16 cur;
    u8* p;
    f32 f;
    for (i = 0; i < 0xC; i++) {
        cur = *(s16*)((u8*)arg0 + 0x52);
        if (i == cur) {
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x10BC) = 0x44480000;
            *(s32*)(p + 0x10C0) = 0;
            *(u8*)(p + 0x10CD) = 0xFF;
        } else {
            f = 200.0f;
            if (i < cur) {
                f = -f;
            }
            p = (u8*)arg0 + i * 0x30;
            *(s32*)(p + 0x10BC) = 0;
            *(f32*)(p + 0x10C0) = f;
            *(u8*)(p + 0x10CD) = 0;
        }
    }
}
/* measured: see annotation above (func_00137740). */
#pragma opt_loop_invariants off

// FUN_001377E0
void func_001377e0(u8* arg0) {
    u8* base = arg0;
    s32 i;
    s32* p;
    for (i = 0; i < 0x17; i++) {
        p = (s32*)(base + i * 4 + 0x1C54);
        if (*p != 0) {
            func_0046d280((void *)*p);
            *p = 0;
        }
    }
    if (*(s32*)(base + 0x1CB4) != 0) {
        func_00452080(*(s32*)(base + 0x1CB4));
        *(s32*)(base + 0x1CB4) = 0;
    }
    if (*(s32*)(base + 0x1CB8) != 0) {
        func_00452080(*(s32*)(base + 0x1CB8));
        *(s32*)(base + 0x1CB8) = 0;
    }
    func_002bb4e0();
    *(s32*)(base + 0x1C) = 0;
}

/* The menu initializer and transition copier establish this 0x30-byte
   position/opacity stride. This view starts at the third initialized row. */
typedef struct {
    f32 x;
    f32 y;
    u8 _08[2];
    u8 alpha;
    u8 _0b[0x25];
} CmpPersonaLayoutRow;

typedef struct {
    u8 alpha;
    u8 _01[3];
    f32 x;
    f32 y;
    u8 _0c[0x10B8];
    CmpPersonaLayoutRow rows[26];
} CmpPersonaLayoutView;

/* Eight-byte header followed by two 0x3c-byte records, initialized by
   func_00115830. The word and halfword views cover its actual header fields. */
typedef union {
    u8 bytes[0x80];
    s16 halves[0x40];
    s32 words[0x20];
} CmpPersonaPanel;

static inline u32 CmpPersonaOffsetAddress(u32 offset, u32 base)
{
    return offset + base;
}

/* measured: b210 -O2 emits 1340 exact bytes followed by four retail zero
   alignment bytes. The menu's typed row view preserves the parent-X load
   before the row-address addition. See the recovery archive for controls. */
// FUN_00137890
void func_00137890(u8 *arg0, s32 arg1)
{
    extern s32 func_0010b5b0(void);
    extern u16 *func_0010ace0(s16 slot);
    extern void func_00115830(u8 *panel);
    extern void func_00115940(u8 *persona, u8 *record, s32 mode);
    extern void func_0034f2e0(void *sprite, f32 x, f32 y,
                            u8 red, u8 green, u8 blue, u8 alpha);
    extern s32 func_00105330(s32 character);
    extern void func_00115c40(Vec2f position, u8 alpha, s16 *panel, f32 depth);
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2E9[];
    extern u8 D_0064B2EA[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B2ED[];
    extern u8 D_0064B2EE[];
    CmpPersonaLayoutView *menu;
    f32 x;
    f32 y;
    f32 row_y;
    f32 opacity;
    u32 entry_alpha;
    u32 base_alpha;
    u32 alpha;
    u8 spriteOpacity;
    s32 selected;
    u8 red;
    u8 green;
    u8 blue;
    u8 digit_red;
    u8 digit_green;
    u8 digit_blue;
    u8 sprite_alpha;
    u8 level;
    CmpPersonaPanel panel;
    Vec2f position;

    if (arg1 < 0 || arg1 >= (func_0010b5b0() & 0xFFFF)) {
        func_0046d730(D_005EB580, 0x478);
    }
    menu = (CmpPersonaLayoutView *)arg0;
    x = (menu->x + menu->rows[arg1].x) - 10.0f;
    y = 0.0f + (menu->y + menu->rows[arg1].y) +
        30.0f * (f32)arg1;
    entry_alpha = menu->rows[arg1].alpha;
    base_alpha = menu->alpha;
    opacity = (f32)entry_alpha * ((f32)base_alpha / 255.0f);
    alpha = spriteOpacity = (u8)opacity;
    if (arg1 >= *(s16 *)(arg0 + 0x4E)) {
        position.x = x - 40.0f;
        position.y = y + 21.0f;
        func_0034f2e0(*(void **)(arg0 + 0x1C64), position.x, position.y,
                      0xFF, 0xE9, 0x2C, spriteOpacity);
        position.x = x + 89.0f;
        position.y = y + 21.0f;
        func_0034f2e0(*(void **)(arg0 + 0x1C68), position.x, position.y,
                      0xFF, 0xE9, 0x2C, spriteOpacity);
    } else {
        func_00115830(panel.bytes);
        if (arg1 == *(s16 *)(arg0 + 0x52)) {
            selected = 1;
            panel.halves[1] = selected;
            red = D_0064B2E8[0];
            green = D_0064B2E9[0];
            blue = D_0064B2EA[0];
            sprite_alpha = (u8)alpha;
            digit_red = D_0064B2EC[0];
            digit_green = D_0064B2ED[0];
            digit_blue = D_0064B2EE[0];
        } else {
            panel.halves[1] = 0;
            red = 0xFF;
            green = 0xE9;
            blue = 0x2C;
            sprite_alpha = (u8)alpha;
            digit_red = 0xF7;
            digit_green = 0xAF;
            digit_blue = 0x22;
            selected = 0;
        }
        panel.halves[0] = 2;
        func_00115940((u8 *)func_0010ace0(*(s16 *)((u8 *)CmpPersonaOffsetAddress(arg1 * 2, (u32)arg0) + 0x36)),
                      panel.bytes + 8, 2);
        position.x = x - 40.0f;
        position.y = y + 21.0f;
        func_0034f2e0(*(void **)(arg0 + 0x1C5C), position.x, position.y,
                      red, green, blue, sprite_alpha);
        position.x = x + 89.0f;
        position.y = y + 21.0f;
        func_0034f2e0(*(void **)(arg0 + 0x1C60), position.x, position.y,
                      red, green, blue, sprite_alpha);
        level = panel.bytes[12];
        position.x = x + 72.0f;
        row_y = y + 26.0f;
        position.y = row_y;
        do {
            func_0034f2e0(*(void **)(arg0 + (level % 10) * 4 + 0x1C7C),
                          position.x, position.y,
                          digit_red, digit_green, digit_blue, sprite_alpha);
            position.x -= 22.0f;
            level /= 10U;
        } while (level > 0);
        if (selected != 0) {
            position.x = x + 24.0f;
            position.y = y + 33.0f;
            func_0034f2e0(*(void **)(arg0 + 0x1CA8), position.x, position.y,
                          digit_red, digit_green, digit_blue, sprite_alpha);
        }
        if (arg1 == func_00105330(1) && (*(u32 *)(arg0 + 0x1C) & 0x20)) {
            position.x = 22.0f;
            position.y = row_y;
            func_0034f2e0(*(void **)(arg0 + 0x1CAC), position.x, position.y,
                          0xFF, 0x85, 0x1F, sprite_alpha);
        }
        position.x = x + 99.0f;
        position.y = y + 20.0f;
        func_00115c40(position, spriteOpacity, panel.halves, 0.0f);
    }
}
// FUN_00137DD0
s32 func_00137dd0(u8* arg0) {
    s32 result = 1;
    s32 i = 0;
    s32 cmp = *(s16*)((u8*)arg0 + 0x20);
    for (; i < 0x1C; i++) {
        if (cmp < *(s32*)((u8*)arg0 + i * 0x30 + 0x1080)) {
            result = 0;
        }
    }
    return result & func_0034c210();
}

// FUN_00137E50
void func_00137e50(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    u8* var_5;
    u8* var_6;
    CmpPair pair;
    if ((arg1 < 0) || (arg1 > 0)) {
        func_0046d730(&D_005EB580[0], 0x505);
    }
    if (arg0 == 0) {
        func_0046d730(&D_005EB580[0], 0x506);
    }
    if (arg3 != 0) {
        var_6 = &D_005EB560[arg1 * 0x1C];
        var_5 = var_6 + 8;
    } else {
        var_5 = &D_005EB560[arg1 * 0x1C];
        var_6 = var_5 + 8;
    }
    pair = *(CmpPair*)&D_005EB570[arg1 * 0x1C];
    arg1 = *(s32*)&D_005EB578[arg1 * 0x1C];
    if (arg2 != 0) {
        func_003550d0(arg0, var_5, var_6);
    } else {
        func_00355070(arg0, var_6, var_6);
    }
    func_003552d0(arg0, pair);
    func_00355300(arg0, arg1);
}

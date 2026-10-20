
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "radar_menu_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "datPersona_internal.h"
extern u32 RpRandom(void);
extern s32 nLineIsIdle(void);
extern void sdkSpriteFreeNode(void *node);
extern void sdkSpriteDrawAt(void *, f32 , f32 ,
                          u8 , u8 , u8 , u8 );
extern void sdkSpriteDrawSized(u8 *, f32 , f32 , f32 ,
                          u8 , u8 , u8 , u8 , u16 ,
                          u16 , s16 , f32 , s16 );
extern void datEntryDrawRow(Vec2f , f32 , u8 , u8 *);
extern void datPanelResetCursor(u8 *);
extern void datPanelDrawByKind(Vec2f , f32 , s32 , u8 *, s32 );
extern s32 datCalcGetLevelById(s32 );
extern f32 fGpffff82cc; /* gp -0x7d34 */
extern u8 D_0064B2E0[];
extern u8 D_0064B2E8[];
extern u8 D_0064B2EC[];
extern u8 D_0064B2F0[];
extern u8 D_0064B2FC[];
extern u8 D_0064B308[];
#pragma push
/* measured: retail hoists loop invariants out of the slot loop. */
#pragma opt_loop_invariants on
// Shift each of the four slots' positions and alphas into their previous values, highlight the
// selected slot, and reset the counter.
// FUN_001302D0
void radarPushSlotState(u8 *menu) {
    s32 i;

    for (i = 0; i < 4; i++) {
        u8 *q = menu + i * 0x30;
        ((RadarMenu *)(q))->entries[17].startX.f = ((RadarMenu *)(q))->entries[17].currentX.f;
        ((RadarMenu *)(q))->entries[17].startY.f = ((RadarMenu *)(q))->entries[17].currentY.f;
        ((RadarMenu *)(q))->entries[17].startAlpha.u = ((RadarMenu *)(q))->entries[17].currentAlpha;
        ((RadarMenu *)(q))->entries[21].startX.f = ((RadarMenu *)(q))->entries[21].currentX.f;
        ((RadarMenu *)(q))->entries[21].startY.f = ((RadarMenu *)(q))->entries[21].currentY.f;
        ((RadarMenu *)(q))->entries[21].startAlpha.u = ((RadarMenu *)(q))->entries[21].currentAlpha;
        if (((RadarMenu *)(menu))->selection[2] == i) {
            ((RadarMenu *)(q))->entries[17].targetX.s = 0x41c80000;
            ((RadarMenu *)(q))->entries[21].targetX.s = 0x41c80000;
        } else {
            ((RadarMenu *)(q))->entries[17].targetX.s = 0;
            ((RadarMenu *)(q))->entries[21].targetX.s = 0;
        }
    }
    ((RadarMenu *)(menu))->entryFrame = 0;
}
#pragma pop

// Reset the indicator's colours and positions, choosing the x offset by comparing two menu
// counters.
// FUN_00130360
void radarResetIndicator(u8 *menu) {
    f32 indicatorY;
    f32 baseY;
    RadarMenu *radarMenu = (RadarMenu *)(menu);

    ((RadarMenu *)(menu))->indicators[0].startX.u = 0x435d0000;
    ((RadarMenu *)(menu))->indicators[0].targetX.u = 0x435d0000;
    ((RadarMenu *)(menu))->indicators[0].currentX.u = 0x435d0000;
    ((RadarMenu *)(menu))->indicators[0].startAlpha.u = 0xff;
    ((RadarMenu *)(menu))->indicators[0].currentAlpha = 0xff;
    ((RadarMenu *)(menu))->indicators[0].targetAlpha = 0;
    ((RadarMenu *)(menu))->indicators[1].targetY.u = 0;
    if (((RadarMenu *)(menu))->selection[1] > ((RadarMenu *)(menu))->previousSelection[1]) {
        indicatorY = 21.0f + ((RadarMenu *)(menu))->entries[9].currentY.f;
        ((RadarMenu *)(menu))->indicators[0].currentY.f = indicatorY;
        ((RadarMenu *)(menu))->indicators[0].startY.f = indicatorY;
        ((RadarMenu *)(menu))->indicators[0].targetY.f = ((RadarMenu *)(menu))->indicators[0].currentY.f - 10.0f;
        ((RadarMenu *)(menu))->indicators[1].startY.u = 0xc1200000;
    } else {
        baseY = 21.0f + ((RadarMenu *)(menu))->entries[14].currentY.f;
        indicatorY = 170.0f + baseY;
        ((RadarMenu *)(menu))->indicators[0].currentY.f = indicatorY;
        ((RadarMenu *)(menu))->indicators[0].startY.f = indicatorY;
        ((RadarMenu *)(menu))->indicators[0].targetY.f = 10.0f + radarMenu->indicators[0].currentY.f;
        ((RadarMenu *)(menu))->indicators[1].startY.u = 0x41200000;
    }
    ((RadarMenu *)(menu))->indicatorFrame = 0;
}

#pragma push
#pragma optimization_level 1
// Randomize the scatter of each of the twelve entries with probability three in four; the others
// keep their current alpha.
// FUN_00130430
void radarRandomizeEntries(u8 *menu)
{
    f32 scatterX;
    u32 columnOffset;
    s32 i;
    u32 random;
    u8 *p;
    u32 *q;

    for (i = 0; i < 0xC; i++) {
        if (RpRandom() & 3) {
            p = menu + i * 0x30;
            columnOffset = (RpRandom() % 6U) * 0x2C;
            if (columnOffset >= 0) {
                scatterX = (f32)columnOffset;
            } else {
                columnOffset = (columnOffset >> 1) | (columnOffset & 1);
                scatterX = (f32)(s32)columnOffset;
                scatterX += scatterX;
            }
            ((RadarMenu *)(p))->scatter[0].targetX.f = scatterX;
            ((RadarMenu *)(p))->scatter[0].startX.f = scatterX;
            ((RadarMenu *)(p))->scatter[0].startY.u = 0x43FA0000;
            ((RadarMenu *)(p))->scatter[0].currentY.f = ((RadarMenu *)(p))->scatter[0].startY.f;
            ((RadarMenu *)(p))->scatter[0].targetY.s = 0xC2C80000;
            q = (u32 *)(p + 0x18A0);
            random = RpRandom() % 10U;
            *q = random;
            ((RadarMenu *)(p))->scatter[0].endFrame.s = random + 0xA;
        } else {
            p = menu + i * 0x30;
            ((RadarMenu *)(p))->scatter[0].startY.f = ((RadarMenu *)(p))->scatter[0].targetY.f;
        }
    }
    ((RadarMenu *)(menu))->scatterFrame = 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Free the 51 sprite nodes in the radar sprite table and clear the sprite count.
// FUN_00130580
void radarFreeSpriteNodes(u8 *menu) {
    s32 i;
    s32 *handle;
    RadarSprite *spriteSlot;
    s32 sprite;

    i = 0;
    while (i < 0x33) {
        spriteSlot = &((RadarMenu *)menu)->sprites[i];
        handle = &spriteSlot->handle;
        sprite = spriteSlot->handle;
        if (sprite != 0) {
            sdkSpriteFreeNode((void *)sprite);
            *handle = 0;
        }
        i++;
    }
    ((RadarMenu *)menu)->flags = 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
// Return 1 when entryFrame is at least the end frame of all 30 entries and the external check
// passes.
// FUN_00130600
s32 radarEntriesCoverValue(u8 *menu) {
    s32 flag = 1;
    s32 i = 0;
    s32 v = ((RadarMenu *)menu)->entryFrame;

    while (i < 0x1e) {
        if (v < ((RadarMenu *)menu)->entries[i].endFrame.s) {
            flag = 0;
        }
        i++;
    }
    return flag & nLineIsIdle();
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* measured: retail keeps the load before the alpha math instead of propagating it. */
#pragma opt_propagation off
// Draw one radar entry row: the panel row with its highlight, the level digits and the icon, at the
// slot position and fade.
// FUN_00130680
void radarDrawEntryRow(u8 *menu, s32 partyIndex)
{
    typedef struct
    {
        s16 id;
        s16 pad2;
        s16 unk4;
        s16 highlight;
        s32 mode;
    } LabelParam;
    typedef struct
    {
        f32 x;
        f32 y;
        u8 pad8[2];
        u8 alpha;
        u8 padB[0x25];
    } LabelSlot;
    s32 id;
    s32 highlight;
    u8 *color0;
    u8 *color1;
    u8 *color2;
    u8 n;
    u8 alpha;
    f32 dim;
    f32 fade;
    f32 x;
    f32 y;
    f32 yoff;
    f32 ty;
    LabelParam param;
    Vec2f pos;
    void *spr;

    id = ((s16 *)(menu + 0x34))[partyIndex];
    dim = 1.0f;
    highlight = 0;
    datPanelResetCursor((u8 *)&param);
    param.mode = 1;
    param.id = id;
    x = ((RadarMenu *)menu)->x.f;
    y = ((RadarMenu *)menu)->y.f;
    fade = (f32)*(u8 *)menu / 255.0f;
    if (((((RadarMenu *)menu)->flags & 0x10) != 0 && ((RadarMenu *)menu)->selection[2] == partyIndex) || (((RadarMenu *)menu)->flags & 0x20) != 0) {
        highlight = 1;
        param.highlight = highlight;
        color0 = D_0064B2E8;
        color1 = D_0064B2EC;
        color2 = D_0064B2FC;
    } else {
        param.highlight = 0;
        color0 = D_0064B2E0;
        color1 = D_0064B2F0;
        color2 = D_0064B308;
        dim = fGpffff82cc;
    }
    pos.x = 67.0f + (x + ((LabelSlot *)(menu + 0x16D8))[partyIndex].x);
    yoff = 75.0f * (f32)partyIndex;
    ty = 24.0f + (y + ((LabelSlot *)(menu + 0x16D8))[partyIndex].y);
    pos.y = ty + yoff;
    ty = ((LabelSlot *)(menu + 0x16D8))[partyIndex].alpha;
    datPanelDrawByKind(pos, 0.0f, (u8)(ty * fade), (u8 *)&param, 0);
    alpha = (f32)(menu + 0x1622)[partyIndex * 0x30] * fade;
    pos.x = 60.0f + (x + ((f32 *)(menu + 0x1618))[partyIndex * 12]);
    ty = y + ((f32 *)(menu + 0x161C))[partyIndex * 12];
    pos.y = 21.0f + (ty + yoff);
    sdkSpriteDrawAt(((RadarMenu *)menu)->sprites[30].object, pos.x, pos.y, color0[0], color0[1], color0[2], alpha);
    if (highlight != 0) {
        pos.x = 2.0f + (x + ((f32 *)(menu + 0x1618))[partyIndex * 12]);
        ty = y + ((f32 *)(menu + 0x161C))[partyIndex * 12];
        pos.y = 27.0f + (ty + yoff);
        sdkSpriteDrawAt(((RadarMenu *)menu)->sprites[31].object, pos.x, pos.y, 0x4C, 0x4C, 0x4C, alpha);
    }
    n = datCalcGetLevelById(id);
    pos.x = 43.0f + (x + ((f32 *)(menu + 0x1618))[partyIndex * 12]);
    ty = y + ((f32 *)(menu + 0x161C))[partyIndex * 12];
    pos.y = 25.0f + (ty + yoff);
    if (n < 10) {
        pos.x -= 11.0f;
    }
    while (n > 0) {
        sdkSpriteDrawAt(((RadarMenu *)menu)->sprites[35 + n % 10].object, pos.x, pos.y, color1[0], color1[1], color1[2], alpha);
        pos.x -= 22.0f;
        n /= 10;
    }
    pos.x = 37.0f + (x + ((f32 *)(menu + 0x1618))[partyIndex * 12]);
    ty = y + ((f32 *)(menu + 0x161C))[partyIndex * 12];
    pos.y = 53.0f + (ty + yoff);
    spr = ((RadarMenu *)menu)->sprites[50].object;
    sdkSpriteDrawAt(spr, pos.x, pos.y, color2[0], color2[1], color2[2], (u8)((f32)alpha * dim));
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* measured: retail keeps the sprite and colour loads in place rather than propagating them. */
#pragma opt_propagation off
// Draw a sprite at the given position and another 340 units to its right, with the given colour.
// FUN_00130C30
void radarDrawSpritePair(u8 *menu, s64 packedPosition, s32 packedColor)
{
    f32 c0;
    s32 p;
    u8 c1;
    u8 c2;
    u8 c3;

    p = ((RadarMenu *)menu)->sprites[18].handle;
    c1 = ((u8 *)&packedColor)[3];
    c2 = ((u8 *)&packedColor)[2];
    c3 = ((u8 *)&packedColor)[1];
    c0 = ((f32 *)&packedPosition)[1];
    sdkSpriteDrawAt((void *)p,
                  ((f32 *)&packedPosition)[0], c0,
                  ((u8 *)&packedColor)[0], c3, c2, c1);
    sdkSpriteDrawAt(((RadarMenu *)menu)->sprites[19].object,
                  340.0f + ((f32 *)&packedPosition)[0], c0,
                  ((u8 *)&packedColor)[0], c3, c2, c1);
}
#pragma pop

#pragma push
#pragma optimization_level 2
/* Draws one radar entry card (background bars, value text and entry row) at the given position and
 * alpha. The original Y component and shared sprite cursor are kept across the draw pairs. */
// FUN_00130CE0
void radarDrawEntryCard(u8 *work, PackedVec2f inputPosition, s32 inputAlpha, s16 *entry)
{
    typedef union {
        f32 f;
        u8 b[4];
    } Color;
    struct {
        Color copy;
        Color current;
    } colors;
    PackedVec2f position;
    PackedVec2f palettePosition;
    f32 opacityValue;
    f32 opacityScale;
    f32 height;
    f32 originalY;
    f32 scaledAlpha;
    f32 alphaValue;
    f32 scaledInputAlpha;
    s32 alphaByte;
    s32 labelAlpha;
    u8 *sprite;

    originalY = inputPosition.xy.y;
    opacityValue = (f32)(u32)((RadarMenu *)work)->opacity;
    opacityScale = opacityValue / 255.0f;
    colors.current.b[0] = 0x14;
    colors.current.b[1] = 0x14;
    colors.current.b[2] = 0x14;
    scaledAlpha = 204.0f * opacityScale;
    alphaByte = (u8)scaledAlpha;
    colors.current.b[3] = alphaByte;
    height = (f32)(u32)((RadarMenu *)work)->entries[16].currentScaleY;
    position.xy.x = inputPosition.xy.x - 1.0f;
    inputPosition.xy.y = 24.0f;
    inputPosition.xy.y += originalY;
    position.xy.y = inputPosition.xy.y;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = ((RadarMenu *)work)->sprites[47].node;
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawSized(sprite, position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
        sprite = ((RadarMenu *)work)->sprites[48].node;
        sdkSpriteDrawSized(sprite, (f32)0x159 + position.xy.x, y, 0.0f,
                      ((u8 *)&colors.current)[0], green, blue, alpha,
                      0x1000, (u16)height, 0, 0.0f, 0);
    }
    {
        f32 x;
        x = 5.0f + inputPosition.xy.x;
        x += ((RadarMenu *)work)->entries[29].currentX.f;
        position.xy.x = x;
    }
    {
        f32 y;
        y = 34.0f + originalY;
        y += ((RadarMenu *)work)->entries[29].currentY.f;
        position.xy.y = y;
    }
    colors.current.b[0] = 0x68;
    colors.current.b[1] = 0x68;
    colors.current.b[2] = 0x68;
    alphaValue = (f32)(u32)inputAlpha;
    scaledInputAlpha = alphaValue * opacityScale;
    colors.current.b[3] = scaledInputAlpha;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = ((RadarMenu *)work)->sprites[45].node;
        alpha = colors.current.b[3];
        blue = colors.current.b[2];
        green = colors.current.b[1];
        y = position.xy.y;
        sdkSpriteDrawAt(sprite, position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
        sdkSpriteDrawAt(((RadarMenu *)work)->sprites[46].object, 330.0f + position.xy.x, y,
                      ((u8 *)&colors.current)[0], green, blue, alpha);
    }
    position.xy.x = inputPosition.xy.x;
    position.xy.y = originalY;
    colors.current.b[0] = D_0064B2E8[0];
    colors.current.b[1] = D_0064B2E8[1];
    colors.current.b[2] = D_0064B2E8[2];
    scaledAlpha = 255.0f * opacityScale;
    alphaByte = (u8)scaledAlpha;
    colors.current.b[3] = alphaByte;
    colors.copy.f = colors.current.f;
    palettePosition.packed = position.packed;
    {
        f32 y;
        u8 alpha;
        u8 blue;
        u8 green;
        sprite = ((RadarMenu *)work)->sprites[18].node;
        alpha = colors.copy.b[3];
        blue = colors.copy.b[2];
        green = colors.copy.b[1];
        y = palettePosition.xy.y;
        sdkSpriteDrawAt(sprite, palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
        sprite = ((RadarMenu *)work)->sprites[19].node;
        sdkSpriteDrawAt(sprite, 340.0f + palettePosition.xy.x,
                      y, colors.copy.b[0], green, blue, alpha);
    }
    position.xy.x = position.xy.x - 2.0f;
    datEntryDrawRow(position.xy, 0.0f, colors.current.b[3], (u8 *)entry);
    position.xy.x = 22.0f + inputPosition.xy.x;
    position.xy.y = 54.0f + originalY;
    labelAlpha = (u8)scaledInputAlpha;
    fclMesWindowDrawItemCategory(0.0f, *entry, (s32)position.xy.x, (s32)position.xy.y,
                  (labelAlpha & 0xFF) | ~0xFF, 1, 8);
}
#pragma pop

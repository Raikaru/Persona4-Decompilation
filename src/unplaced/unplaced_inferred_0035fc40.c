/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0035fc40-0035fd60 */

#include "include_asm.h"
#include "member_access.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "radar_menu_internal.h"
extern s32 datGetFlag(s32 bit);
extern void radarAnimateValue(void *work, s32 frame, s32 mode);
extern void radarStepBarWave(u8 *work);
extern void radarStepValueAnimation(u8 *work);
extern void datCommunityMenuDraw(u8 *work);
#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Panel open step, same body as datCommunityPanelOpenStep: advance from state 0 and report ready from states 0 and 1 [inferred]
// FUN_0035FC40
s32 datCommunityPanelOpenStepAlt(u8 *work)
{
    s32 state = ((RadarMenuWork *)work)->state;

    switch (state) {
    case 0:
        state += 1;
        /* measured: a typed state store shares its address with the load (72 versus 80 bytes). */
        MEMBER(s32, work, RadarMenuWork, state) = state;
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
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Community menu update: animate the 29 menu panels, update their helpers and draw the panel frame; returns 1 when no panel is still animating [inferred]
// FUN_0035FC90
s32 datCommunityMenuUpdate(u8 *work)
{
    s16 counter;
    s32 index;
    s32 allIdle;
    u8 *panel;

    allIdle = 1;
    counter = ((RadarMenuWork *)work)->elapsed;
    /* measured: typing the repeated elapsed accesses grows this update from 208 to 220 bytes. */
    if (counter < 0x64) {
        MEMBER(s16, work, RadarMenuWork, elapsed) = counter + 1;
    }
    index = 0;
    while (index < 0x1D) {
        panel = work + index * 0x30;
        radarAnimateValue(panel + 0x48, MEMBER(s16, work, RadarMenuWork, elapsed), 0);
        if (((MenuSlotAnimation *)(panel + 0x48))->currentAlpha != 0) {
            allIdle = 0;
        }
        index += 1;
    }
    radarStepBarWave(work);
    radarStepValueAnimation(work);
    datCommunityMenuDraw(work);
    return allIdle;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
/* Draw the animated menu panels, eleven-column pip grids and scrolling list.
 * Position, texture and opacity snapshots preserve the values used by each
 * draw group. The label pass uses the final row's alpha; the scrollbar keeps
 * its fractional origin, while the solid primitive requires integer geometry.
 * Measured b210 O2 with scoped lifetime/loop-invariant optimization:
 * 7176 instruction bytes plus the retail window's eight-byte zero tail.
 * See docs/probe_archive/Menu_renderer_0035fd60_20260930.md. */
// Intent: Draw the community menu: its animated panels, pip grids and scrolling list [inferred]
// FUN_0035FD60
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
void datCommunityMenuDraw(u8 *work)
{
    extern void sdkRenderStateSetDefault(void);
    extern void nLineDrawSet(Vec2f position, s32 alpha, s32 setIndex, f32 depthOffset);
    extern void sdkSpriteDrawAt(void *sprite, f32 x, f32 y, u8 red, u8 green, u8 blue, u8 alpha);
    extern void sdkSpriteDrawFooter(Vec2f unusedPosition, f32 depth, u8 alpha, s32 style, s32 packAddress);
    extern void frFontExCopyString(void *src, void *dst, s32 maxlen);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 scale, s32 color, s8 chr, s32 id,
                            const char *str, s32 flags, s32 unused);
    extern void fclMesWindowDrawTableItem(s32 item, f32 x, f32 y, f32 depth,
                              s32 color, s32 font, s32 mode, s32 table);
    extern void radarDrawColumn(s32 rowIndex, u8 *work);
    extern s32 RpSkyRenderStateSet(s32 cmd, void *val);
    extern void effMiscDrawScreenColor(u8 *colors, s32 enabled);
    extern void PrimDrawFlatRectangle(u8 *colorData, f32 *rectangleData, f32 depth, s32 preserveState);
    extern void mdlEffectEmitMaskedTagPair(void);
    extern void mdlEffectEmitTagPair(void);
    extern u8 D_0064B2E8[];
    extern u8 D_0064B2EC[];
    extern u8 D_0064B300[];
    extern u8 D_0064B2E0[];
    extern void *D_0064D448[];
    extern s32 (*D_00887300[])(s32, void *);
    u8 colorBytes[4];
    /* The primitive wrapper copies four words through its float transport view;
     * their actual payload is the integer x, y, width and height. */
    union { s32 integer[4]; f32 transport[4]; } rectangle;
    char text[0x100];
    Vec2f position;
    s32 column;
    s32 pip;
    u8 *entry;
    void *pipSprite;
    void *cursorSprite;
    void *sprite;
    typedef struct { u8 r, g, b, a; } PaletteColor;
    PaletteColor *palette;
    f32 gridX;
    f32 gridY;
    f32 offsetY;
    f32 offsetX;
    f32 opacityScale;
    f32 originX;
    f32 originY;
    s32 background;
    u8 gridAlpha;
    s32 rowOffset;
    s32 textColor;
    s32 itemIndex;
    s32 displayItem;
    u8 opacity;
    u8 labelOpacity;
    u32 lastRowAlpha;
    /* measured: typed drawFlags, selectedHeader, topRow and rowCount retain field
     * addresses across draw calls; keep those repeated accesses byte-addressed.
     * The same applies to panel 3/18 x/y/alpha: typing these grows the 7176-byte
     * body (all layouts typed: 7216 bytes). Other panel and sprite accesses stay typed. */
    sdkRenderStateSetDefault();
    originX = ((RadarMenuWork *)work)->x.f;
    originY = ((RadarMenuWork *)work)->y.f;
    opacityScale = (f32)((RadarMenuWork *)work)->alpha / 255.0f;
    background = ((RadarMenuWork *)work)->background;
    if (background != 0) {
        position.x = originX;
        position.y = originY;
        gridAlpha = (u8)(255.0f * opacityScale);
        nLineDrawSet(position, (u8)gridAlpha, background, 0.0f);
    }
    if (((RadarMenuWork *)(work))->drawFlags & 1) {
        position.x = originX + ((RadarMenuWork *)work)->panels[6].currentX.f + 90.0f;
        position.y = originY + ((RadarMenuWork *)work)->panels[6].currentY.f + 91.0f;
        gridAlpha = (u8)((f32)((RadarMenuWork *)work)->panels[6].currentAlpha * opacityScale);
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[41].node, position.x, position.y, 0xFF, 0xFF, 0xFF, gridAlpha);
    }
    if (MEMBER(s32, work, RadarMenuWork, drawFlags) & 2) {
        gridX = 23.0f + (595.0f + (originX + ((RadarMenuWork *)work)->panels[5].currentX.f));
        gridY = 280.0f + (originY + ((RadarMenuWork *)work)->panels[5].currentY.f);
        gridAlpha = (u8)((f32)((RadarMenuWork *)work)->panels[5].currentAlpha * opacityScale);
        /* The shared pip texture and phase opacity are snapshots for this grid. */
        pipSprite = ((RadarMenuWork *)work)->sprites[8].node;

        for (column = 0; column < 0xB; column++) {
            position.x = gridX - (f32)(column * 0x2D);
            pip = 0;
            entry = work + column * 0xA;
            for (; pip < ((RadarBarTarget *)(entry + 0x5E8))->bound; pip++) {
                if (pip == ((RadarBarTarget *)(entry + 0x5E8))->bound - 1) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0xA4;
                    colorBytes[3] = (u8)(0.6f * (f32)gridAlpha);
                } else if (pip < ((RadarBarTarget *)(entry + 0x5E8))->current) {
                    colorBytes[0] = 0xFE;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0x56;
                    colorBytes[3] = (u8)(0.5f * (f32)gridAlpha);
                } else {
                    continue;
                }
                position.y = gridY - (f32)(pip * 0x11);
                sdkSpriteDrawAt(pipSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
            }
        }
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + ((MenuSlotAnimation *)(entry + 0x48))->currentX.f);
            position.y = 136.0f + (originY + ((MenuSlotAnimation *)(entry + 0x48))->currentY.f + (f32)(column * 0x30));
            opacity = (u8)((f32)((MenuSlotAnimation *)(entry + 0x48))->currentAlpha * opacityScale);
            colorBytes[0] = D_0064B2E8[0];
            colorBytes[1] = D_0064B2E8[1];
            colorBytes[2] = D_0064B2E8[2];
            colorBytes[3] = opacity;
            sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[column * 2 + 1].node, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
        }
        /* Smooth the cursor halfway toward the selected row using its old pair. */
        offsetX = 303.0f + originX;
        offsetY = 133.0f + originY + (f32)(((RadarMenuWork *)(work))->selectedHeader * 0x30);
        position = ((RadarMenuWork *)work)->cursor;
        offsetX = offsetX - position.x;
        offsetY = offsetY - position.y;
        offsetX = offsetX * 0.5f;
        offsetY = offsetY * 0.5f;
        ((RadarMenuWork *)work)->cursor.x = position.x + offsetX;
        ((RadarMenuWork *)work)->cursor.y = position.y + offsetY;
        position.x = ((RadarMenuWork *)work)->panels[4].currentX.f + ((RadarMenuWork *)work)->cursor.x;
        position.y = ((RadarMenuWork *)work)->panels[4].currentY.f + ((RadarMenuWork *)work)->cursor.y;
        lastRowAlpha = (u8)((f32)((RadarMenuWork *)work)->panels[4].currentAlpha * opacityScale);
        cursorSprite = ((RadarMenuWork *)work)->sprites[0].node;
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        sdkSpriteDrawAt(cursorSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], lastRowAlpha);
        mdlEffectEmitMaskedTagPair();
        D_00887300[0](1, 0);
        colorBytes[3] = 0;
        effMiscDrawScreenColor(colorBytes, 0);
        sdkSpriteDrawAt(cursorSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], 0xFF);
        mdlEffectEmitTagPair();
        RpSkyRenderStateSet(3, (void *)0x2D801);
        RpSkyRenderStateSet(2, (void *)0x44);
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + ((MenuSlotAnimation *)(entry + 0x48))->currentX.f);
            position.y = 136.0f + (originY + ((MenuSlotAnimation *)(entry + 0x48))->currentY.f + (f32)(column * 0x30));
            lastRowAlpha = (u8)((f32)((MenuSlotAnimation *)(entry + 0x48))->currentAlpha * opacityScale);
            colorBytes[0] = D_0064B2EC[0];
            colorBytes[1] = D_0064B2EC[1];
            colorBytes[2] = D_0064B2EC[2];
            colorBytes[3] = lastRowAlpha;
            sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[column * 2 + 1].node, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        /* The label pass uses the alpha left by the final animated row. */
        labelOpacity = lastRowAlpha;
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + ((MenuSlotAnimation *)(entry + 0x48))->currentX.f);
            position.y = 136.0f + (originY + ((MenuSlotAnimation *)(entry + 0x48))->currentY.f + (f32)(column * 0x30));
            sprite = ((RadarMenuWork *)work)->sprites[column * 2 + 2].node;
            sdkSpriteDrawAt(sprite, position.x + 4.0f, position.y + 20.0f, 0x80, 0x80, 0x80, labelOpacity);
        }
        position.x = 468.0f + (originX + ((RadarMenuWork *)(work))->panels[3].currentX.f);
        position.y = 139.0f + (originY + ((RadarMenuWork *)(work))->panels[3].currentY.f);
        opacity = (u8)((f32)((RadarMenuWork *)(work))->panels[3].currentAlpha * opacityScale);
        sprite = ((RadarMenuWork *)work)->sprites[7].node;
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        sdkSpriteDrawAt(sprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], opacity);
        position.x = 53.0f + (567.0f + (originX + MEMBER(f32, work, RadarMenuWork, panels[3].currentX.f)));
        position.y = 269.0f + (originY + MEMBER(f32, work, RadarMenuWork, panels[3].currentY.f));
        opacity = (u8)((f32)MEMBER(u8, work, RadarMenuWork, panels[3].currentAlpha) * opacityScale);
        textColor = opacity | ~0xFF;
        frFontExCopyString(D_0064D448[MEMBER(s16, work, RadarMenuWork, selectedHeader)], text, 0x100);
        frFontExDrawText(position.x, position.y, 0.0f, textColor, 7, 1, text, 2, 0);
        position.x = 640.0f + (originX + ((RadarMenuWork *)work)->panels[7].currentX.f);
        position.y = 400.0f + (originY + ((RadarMenuWork *)work)->panels[7].currentY.f);
        opacity = (u8)((f32)((RadarMenuWork *)work)->panels[7].currentAlpha * opacityScale);
        sdkSpriteDrawFooter(position, 0.0f, opacity, ((RadarMenuWork *)work)->footerMode, ((RadarMenuWork *)work)->footerResource);
    }
    if (MEMBER(s32, work, RadarMenuWork, drawFlags) & 4) {
        gridX = 23.0f + (595.0f + (originX + ((RadarMenuWork *)work)->panels[5].currentX.f));
        gridY = 430.0f + (originY + ((RadarMenuWork *)work)->panels[5].currentY.f);
        gridAlpha = (u8)((f32)((RadarMenuWork *)work)->panels[5].currentAlpha * opacityScale);
        /* The shared pip texture and phase opacity are snapshots for this grid. */
        pipSprite = ((RadarMenuWork *)work)->sprites[8].node;
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);

        for (column = 0; column < 0xB; column++) {
            position.x = gridX - (f32)(column * 0x2D);
            pip = 0;
            entry = work + column * 0xA;
            for (; pip < ((RadarBarTarget *)(entry + 0x5E8))->bound; pip++) {
                if (pip == ((RadarBarTarget *)(entry + 0x5E8))->bound - 1) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0xF0;
                    colorBytes[3] = (u8)(0.5f * (f32)gridAlpha);
                } else if (pip < ((RadarBarTarget *)(entry + 0x5E8))->current) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFC;
                    colorBytes[2] = 0x40;
                    colorBytes[3] = (u8)(0.45f * (f32)gridAlpha);
                } else {
                    continue;
                }
                position.y = gridY - (f32)(pip * 0x11);
                sdkSpriteDrawAt(pipSprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
            }
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        position.x = 29.0f + (originX + ((RadarMenuWork *)(work))->panels[18].currentX.f);
        position.y = -13.0f + (54.0f + (originY + ((RadarMenuWork *)(work))->panels[18].currentY.f));
        opacity = (u8)((f32)((RadarMenuWork *)(work))->panels[18].currentAlpha * opacityScale);
        palette = (PaletteColor *)D_0064B2E8;
        sprite = ((RadarMenuWork *)work)->sprites[33].node;
        sdkSpriteDrawAt(sprite, position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sprite = ((RadarMenuWork *)work)->sprites[34].node;
        sdkSpriteDrawAt(sprite, position.x + 73.0f, position.y, palette->r, palette->g, palette->b, opacity);
        palette = (PaletteColor *)D_0064B2EC;
        sprite = ((RadarMenuWork *)work)->sprites[32].node;
        sdkSpriteDrawAt(sprite, position.x + 19.0f, position.y + 2.0f, palette->r, palette->g, palette->b, opacity);
        position.x = 89.0f + (originX + MEMBER(f32, work, RadarMenuWork, panels[18].currentX.f));
        position.y = -13.0f + (86.0f + (originY + MEMBER(f32, work, RadarMenuWork, panels[18].currentY.f)));
        opacity = (u8)((f32)MEMBER(u8, work, RadarMenuWork, panels[18].currentAlpha) * opacityScale);
        palette = (PaletteColor *)D_0064B300;
        sprite = ((RadarMenuWork *)work)->sprites[13].node;
        offsetY = position.y + 4.0f;
        sdkSpriteDrawAt(sprite, position.x - 6.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sprite = ((RadarMenuWork *)work)->sprites[14].node;
        sdkSpriteDrawAt(sprite, position.x + 41.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[10].node, position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[9].node, position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], opacity);
        position.x = 302.0f + (originX + MEMBER(f32, work, RadarMenuWork, panels[18].currentX.f));
        position.y = -13.0f + (79.0f + (originY + MEMBER(f32, work, RadarMenuWork, panels[18].currentY.f)));
        opacity = (u8)((f32)MEMBER(u8, work, RadarMenuWork, panels[18].currentAlpha) * opacityScale);
        palette = (PaletteColor *)D_0064B300;
        sprite = ((RadarMenuWork *)work)->sprites[15].node;
        offsetY = position.y + 11.0f;
        sdkSpriteDrawAt(sprite, position.x - 157.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sprite = ((RadarMenuWork *)work)->sprites[16].node;
        sdkSpriteDrawAt(sprite, position.x + 255.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[12].node, position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[11].node, position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], opacity);
        /* Preserve the unrounded scrollbar origin across all three draws. */
        offsetX = 583.0f + (((RadarMenuWork *)work)->slide.currentX.f + (originX + ((RadarMenuWork *)work)->panels[15].currentX.f));
        offsetY = (-13.0f + (132.0f + (((RadarMenuWork *)work)->slide.currentY.f + (originY + ((RadarMenuWork *)work)->panels[15].currentY.f)))) - 17.0f;
        opacity = (u8)((f32)((RadarMenuWork *)work)->panels[15].currentAlpha * opacityScale);
        position.x = offsetX;
        position.y = offsetY;
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[38].node, position.x, position.y, 0xFF, 0xFF, 0xFF, opacity);
        position.x = offsetX;
        position.y = offsetY + 165.0f;
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[39].node, position.x, position.y, 0xFF, 0xFF, 0xFF, opacity);
        position.x = offsetX;
        position.y = offsetY + 3.0f;
        position.y += (f32)((s32)(((RadarMenuWork *)(work))->topRow * 0x86) / (s32)(((RadarMenuWork *)(work))->rowCount - 6));
        palette = (PaletteColor *)D_0064B2E8;
        sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[37].node, position.x, position.y, palette->r, palette->g, palette->b, opacity);
        for (column = 0; column < 6; column++) {
            if ((MEMBER(s16, work, RadarMenuWork, topRow) + column) < MEMBER(s32, work, RadarMenuWork, rowCount)) {
                radarDrawColumn(column, work);
            }
        }
        offsetX = originX + ((RadarMenuWork *)work)->panels[28].currentX.f;
        offsetY = originY + ((RadarMenuWork *)work)->panels[28].currentY.f;
        opacity = (u8)((f32)((RadarMenuWork *)work)->panels[28].currentAlpha * opacityScale);
        rectangle.integer[0] = (s32)(73.0f + offsetX);
        rectangle.integer[1] = (s32)(297.0f + offsetY);
        rectangle.integer[2] = 0x241;
        rectangle.integer[3] = 0x55;
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        colorBytes[3] = opacity;
        D_00887300[0](1, 0);
        PrimDrawFlatRectangle(colorBytes, rectangle.transport, 0.0f, 0);
        position.x = 212.0f + offsetX;
        position.y = (304.0f + offsetY) - 5.0f;
        itemIndex = (s32)(((RadarMenuWork *)work)->selectedRow + MEMBER(s16, work, RadarMenuWork, topRow));
        if (datGetFlag(itemIndex + 0x100) != 0) {
            if (datGetFlag(itemIndex + 0x140) != 0) {
                textColor = (opacity | 0xADADAD00);
            } else {
                textColor = (opacity | ~0xFF);
            }
            displayItem = itemIndex + 1;
        } else {
            textColor = (opacity | 0xADADAD00);
            displayItem = 0;
        }
        fclMesWindowDrawTableItem(displayItem, (f32)(s32)position.x, (f32)(s32)position.y, 0.0f, textColor, 1, 8, 8);
        if (MEMBER(s32, work, RadarMenuWork, drawFlags) & 8) {
            position.x = 85.0f + (originX + ((RadarMenuWork *)work)->panels[17].currentX.f);
            position.y = 325.0f + (originY + ((RadarMenuWork *)work)->panels[17].currentY.f);
            opacity = (u8)((f32)((RadarMenuWork *)work)->panels[17].currentAlpha * opacityScale);
            sdkSpriteDrawAt(((RadarMenuWork *)work)->sprites[35].node, position.x, position.y, 0xFF, 0xE9, 0x2C, opacity);
        }
        position.x = 640.0f + (originX + ((RadarMenuWork *)work)->panels[27].currentX.f);
        position.y = 400.0f + (originY + ((RadarMenuWork *)work)->panels[27].currentY.f);
        opacity = (u8)((f32)((RadarMenuWork *)work)->panels[27].currentAlpha * opacityScale);
        sdkSpriteDrawFooter(position, 0.0f, opacity, ((RadarMenuWork *)work)->footerMode, ((RadarMenuWork *)work)->footerResource);
    }
}
#pragma pop
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0035fc40-0035fd60 */

#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scr_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
extern s32 datGetFlag(s32 arg0);
extern void radarAnimateValue(void *arg0, s32 arg1, s32 arg2);
extern void radarStepBarWave(u8 *arg0);
extern void radarStepValueAnimation(u8 *arg0);
extern void datCommunityMenuDraw(u8 *arg0);
#pragma push
#pragma optimization_level 2
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Intent: Panel open step, same body as datCommunityPanelOpenStep: advance from state 0 and report ready from states 0 and 1 [inferred]
// FUN_0035FC40
s32 datCommunityPanelOpenStepAlt(u8 *arg0)
{
    s32 v = *(s32 *)(arg0 + 0x14);

    switch (v) {
    case 0:
        v += 1;
        *(s32 *)(arg0 + 0x14) = v;
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
s32 datCommunityMenuUpdate(u8 *arg0)
{
    s16 counter;
    s32 index;
    s32 allIdle;
    u8 *panel;

    allIdle = 1;
    counter = *(s16 *)(arg0 + 0x20);
    if (counter < 0x64) {
        *(s16 *)(arg0 + 0x20) = counter + 1;
    }
    index = 0;
    goto loop_test;
loop_body:
    panel = arg0 + index * 0x30;
    radarAnimateValue(panel + 0x48, *(s16 *)(arg0 + 0x20), 0);
    if (*(u8 *)(panel + 0x62) != 0) {
        allIdle = 0;
    }
    index += 1;
loop_test:
    if (index < 0x1D) {
        goto loop_body;
    }
    radarStepBarWave(arg0);
    radarStepValueAnimation(arg0);
    datCommunityMenuDraw(arg0);
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
    extern void nLineDrawSet(Vec2f position, s32 alpha, s32 background, f32 depth);
    extern void sdkSpriteDrawAt(void *ptr, f32 x, f32 y, u8 r, u8 g, u8 b, u8 a);
    extern void sdkSpriteDrawFooter(Vec2f position, f32 depth, u8 alpha, s32 mode, s32 resource);
    extern void frFontExCopyString(void *src, void *dst, s32 n);
    extern s32 frFontExDrawText(f32 x, f32 y, f32 depth, s32 color, s8 character, s32 font,
                            const char *text, s32 flags, s32 reserved);
    extern void fclMesWindowDrawTableItem(s32 item, f32 x, f32 y, f32 depth,
                              s32 textColor, s32 font, s32 mode, s32 table);
    extern void radarDrawColumn(s32 idx, u8 *ctx);
    extern s32 RpSkyRenderStateSet(s32 cmd, void *val);
    extern void effMiscDrawScreenColor(u8 *color, s32 flags);
    extern void PrimDrawFlatRectangle(u8 *color, f32 *rectangle, f32 depth, s32 flags);
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
    sdkRenderStateSetDefault();
    originX = *(f32 *)(work + 4);
    originY = *(f32 *)(work + 8);
    opacityScale = (f32)*(u8 *)work / 255.0f;
    background = *(s32 *)(work + 0x10);
    if (background != 0) {
        position.x = originX;
        position.y = originY;
        gridAlpha = (u8)(255.0f * opacityScale);
        nLineDrawSet(position, (u8)gridAlpha, background, 0.0f);
    }
    if (*(s32 *)(work + 0x1C) & 1) {
        position.x = originX + *(f32 *)(work + 0x178) + 90.0f;
        position.y = originY + *(f32 *)(work + 0x17C) + 91.0f;
        gridAlpha = (u8)((f32)*(u8 *)(work + 0x182) * opacityScale);
        sdkSpriteDrawAt(*(void **)(work + 0x6FC), position.x, position.y, 0xFF, 0xFF, 0xFF, gridAlpha);
    }
    if (*(s32 *)(work + 0x1C) & 2) {
        gridX = 23.0f + (595.0f + (originX + *(f32 *)(work + 0x148)));
        gridY = 280.0f + (originY + *(f32 *)(work + 0x14C));
        gridAlpha = (u8)((f32)*(u8 *)(work + 0x152) * opacityScale);
        /* The shared pip texture and phase opacity are snapshots for this grid. */
        pipSprite = *(void **)(work + 0x678);

        for (column = 0; column < 0xB; column++) {
            position.x = gridX - (f32)(column * 0x2D);
            pip = 0;
            entry = work + column * 0xA;
            for (; pip < *(s16 *)(entry + 0x5EA); pip++) {
                if (pip == *(s16 *)(entry + 0x5EA) - 1) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0xA4;
                    colorBytes[3] = (u8)(0.6f * (f32)gridAlpha);
                } else if (pip < *(s16 *)(entry + 0x5EE)) {
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
            position.x = 144.0f + (originX + *(f32 *)(entry + 0x58));
            position.y = 136.0f + (originY + *(f32 *)(entry + 0x5C) + (f32)(column * 0x30));
            opacity = (u8)((f32)*(u8 *)(entry + 0x62) * opacityScale);
            colorBytes[0] = D_0064B2E8[0];
            colorBytes[1] = D_0064B2E8[1];
            colorBytes[2] = D_0064B2E8[2];
            colorBytes[3] = opacity;
            sdkSpriteDrawAt(*(void **)(work + column * 8 + 0x65C), position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
        }
        /* Smooth the cursor halfway toward the selected row using its old pair. */
        offsetX = 303.0f + originX;
        offsetY = 133.0f + originY + (f32)(*(s16 *)(work + 0x28) * 0x30);
        position = *(Vec2f *)(work + 0x40);
        offsetX = offsetX - position.x;
        offsetY = offsetY - position.y;
        offsetX = offsetX * 0.5f;
        offsetY = offsetY * 0.5f;
        *(f32 *)(work + 0x40) = position.x + offsetX;
        *(f32 *)(work + 0x44) = position.y + offsetY;
        position.x = *(f32 *)(work + 0x118) + *(f32 *)(work + 0x40);
        position.y = *(f32 *)(work + 0x11C) + *(f32 *)(work + 0x44);
        lastRowAlpha = (u8)((f32)*(u8 *)(work + 0x122) * opacityScale);
        cursorSprite = *(void **)(work + 0x658);
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
            position.x = 144.0f + (originX + *(f32 *)(entry + 0x58));
            position.y = 136.0f + (originY + *(f32 *)(entry + 0x5C) + (f32)(column * 0x30));
            lastRowAlpha = (u8)((f32)*(u8 *)(entry + 0x62) * opacityScale);
            colorBytes[0] = D_0064B2EC[0];
            colorBytes[1] = D_0064B2EC[1];
            colorBytes[2] = D_0064B2EC[2];
            colorBytes[3] = lastRowAlpha;
            sdkSpriteDrawAt(*(void **)(work + column * 8 + 0x65C), position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], colorBytes[3]);
        }
        RpSkyRenderStateSet(3, (void *)0x717FB);
        RpSkyRenderStateSet(2, (void *)0x44);
        /* The label pass uses the alpha left by the final animated row. */
        labelOpacity = lastRowAlpha;
        for (column = 0; column < 3; column++) {
            rowOffset = column * 0x30;
            entry = work + rowOffset;
            position.x = 144.0f + (originX + *(f32 *)(entry + 0x58));
            position.y = 136.0f + (originY + *(f32 *)(entry + 0x5C) + (f32)(column * 0x30));
            sprite = *(void **)(work + column * 8 + 0x660);
            sdkSpriteDrawAt(sprite, position.x + 4.0f, position.y + 20.0f, 0x80, 0x80, 0x80, labelOpacity);
        }
        position.x = 468.0f + (originX + *(f32 *)(work + 0xE8));
        position.y = 139.0f + (originY + *(f32 *)(work + 0xEC));
        opacity = (u8)((f32)*(u8 *)(work + 0xF2) * opacityScale);
        sprite = *(void **)(work + 0x674);
        colorBytes[0] = D_0064B2E8[0];
        colorBytes[1] = D_0064B2E8[1];
        colorBytes[2] = D_0064B2E8[2];
        sdkSpriteDrawAt(sprite, position.x, position.y, colorBytes[0], colorBytes[1], colorBytes[2], opacity);
        position.x = 53.0f + (567.0f + (originX + *(f32 *)(work + 0xE8)));
        position.y = 269.0f + (originY + *(f32 *)(work + 0xEC));
        opacity = (u8)((f32)*(u8 *)(work + 0xF2) * opacityScale);
        textColor = opacity | ~0xFF;
        frFontExCopyString(D_0064D448[*(s16 *)(work + 0x28)], text, 0x100);
        frFontExDrawText(position.x, position.y, 0.0f, textColor, 7, 1, text, 2, 0);
        position.x = 640.0f + (originX + *(f32 *)(work + 0x1A8));
        position.y = 400.0f + (originY + *(f32 *)(work + 0x1AC));
        opacity = (u8)((f32)*(u8 *)(work + 0x1B2) * opacityScale);
        sdkSpriteDrawFooter(position, 0.0f, opacity, *(s16 *)(work + 0x34), *(s32 *)(work + 0x700));
    }
    if (*(s32 *)(work + 0x1C) & 4) {
        gridX = 23.0f + (595.0f + (originX + *(f32 *)(work + 0x148)));
        gridY = 430.0f + (originY + *(f32 *)(work + 0x14C));
        gridAlpha = (u8)((f32)*(u8 *)(work + 0x152) * opacityScale);
        /* The shared pip texture and phase opacity are snapshots for this grid. */
        pipSprite = *(void **)(work + 0x678);
        RpSkyRenderStateSet(3, (void *)0x71801);
        RpSkyRenderStateSet(2, (void *)0x48);

        for (column = 0; column < 0xB; column++) {
            position.x = gridX - (f32)(column * 0x2D);
            pip = 0;
            entry = work + column * 0xA;
            for (; pip < *(s16 *)(entry + 0x5EA); pip++) {
                if (pip == *(s16 *)(entry + 0x5EA) - 1) {
                    colorBytes[0] = 0xFF;
                    colorBytes[1] = 0xFF;
                    colorBytes[2] = 0xF0;
                    colorBytes[3] = (u8)(0.5f * (f32)gridAlpha);
                } else if (pip < *(s16 *)(entry + 0x5EE)) {
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
        position.x = 29.0f + (originX + *(f32 *)(work + 0x3B8));
        position.y = -13.0f + (54.0f + (originY + *(f32 *)(work + 0x3BC)));
        opacity = (u8)((f32)*(u8 *)(work + 0x3C2) * opacityScale);
        palette = (PaletteColor *)D_0064B2E8;
        sprite = *(void **)(work + 0x6DC);
        sdkSpriteDrawAt(sprite, position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sprite = *(void **)(work + 0x6E0);
        sdkSpriteDrawAt(sprite, position.x + 73.0f, position.y, palette->r, palette->g, palette->b, opacity);
        palette = (PaletteColor *)D_0064B2EC;
        sprite = *(void **)(work + 0x6D8);
        sdkSpriteDrawAt(sprite, position.x + 19.0f, position.y + 2.0f, palette->r, palette->g, palette->b, opacity);
        position.x = 89.0f + (originX + *(f32 *)(work + 0x3B8));
        position.y = -13.0f + (86.0f + (originY + *(f32 *)(work + 0x3BC)));
        opacity = (u8)((f32)*(u8 *)(work + 0x3C2) * opacityScale);
        palette = (PaletteColor *)D_0064B300;
        sprite = *(void **)(work + 0x68C);
        offsetY = position.y + 4.0f;
        sdkSpriteDrawAt(sprite, position.x - 6.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sprite = *(void **)(work + 0x690);
        sdkSpriteDrawAt(sprite, position.x + 41.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(*(void **)(work + 0x680), position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(*(void **)(work + 0x67C), position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], opacity);
        position.x = 302.0f + (originX + *(f32 *)(work + 0x3B8));
        position.y = -13.0f + (79.0f + (originY + *(f32 *)(work + 0x3BC)));
        opacity = (u8)((f32)*(u8 *)(work + 0x3C2) * opacityScale);
        palette = (PaletteColor *)D_0064B300;
        sprite = *(void **)(work + 0x694);
        offsetY = position.y + 11.0f;
        sdkSpriteDrawAt(sprite, position.x - 157.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sprite = *(void **)(work + 0x698);
        sdkSpriteDrawAt(sprite, position.x + 255.0f, offsetY, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(*(void **)(work + 0x688), position.x, position.y, palette->r, palette->g, palette->b, opacity);
        sdkSpriteDrawAt(*(void **)(work + 0x684), position.x, position.y, D_0064B2E0[0], D_0064B2E0[1], D_0064B2E0[2], opacity);
        /* Preserve the unrounded scrollbar origin across all three draws. */
        offsetX = 583.0f + (*(f32 *)(work + 0x5C8) + (originX + *(f32 *)(work + 0x328)));
        offsetY = (-13.0f + (132.0f + (*(f32 *)(work + 0x5CC) + (originY + *(f32 *)(work + 0x32C))))) - 17.0f;
        opacity = (u8)((f32)*(u8 *)(work + 0x332) * opacityScale);
        position.x = offsetX;
        position.y = offsetY;
        sdkSpriteDrawAt(*(void **)(work + 0x6F0), position.x, position.y, 0xFF, 0xFF, 0xFF, opacity);
        position.x = offsetX;
        position.y = offsetY + 165.0f;
        sdkSpriteDrawAt(*(void **)(work + 0x6F4), position.x, position.y, 0xFF, 0xFF, 0xFF, opacity);
        position.x = offsetX;
        position.y = offsetY + 3.0f;
        position.y += (f32)((s32)(*(s16 *)(work + 0x2C) * 0x86) / (s32)(*(s32 *)(work + 0x38) - 6));
        palette = (PaletteColor *)D_0064B2E8;
        sdkSpriteDrawAt(*(void **)(work + 0x6EC), position.x, position.y, palette->r, palette->g, palette->b, opacity);
        for (column = 0; column < 6; column++) {
            if ((*(s16 *)(work + 0x2C) + column) < *(s32 *)(work + 0x38)) {
                radarDrawColumn(column, work);
            }
        }
        offsetX = originX + *(f32 *)(work + 0x598);
        offsetY = originY + *(f32 *)(work + 0x59C);
        opacity = (u8)((f32)*(u8 *)(work + 0x5A2) * opacityScale);
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
        itemIndex = (s32)(*(s16 *)(work + 0x2A) + *(s16 *)(work + 0x2C));
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
        if (*(s32 *)(work + 0x1C) & 8) {
            position.x = 85.0f + (originX + *(f32 *)(work + 0x388));
            position.y = 325.0f + (originY + *(f32 *)(work + 0x38C));
            opacity = (u8)((f32)*(u8 *)(work + 0x392) * opacityScale);
            sdkSpriteDrawAt(*(void **)(work + 0x6E4), position.x, position.y, 0xFF, 0xE9, 0x2C, opacity);
        }
        position.x = 640.0f + (originX + *(f32 *)(work + 0x568));
        position.y = 400.0f + (originY + *(f32 *)(work + 0x56C));
        opacity = (u8)((f32)*(u8 *)(work + 0x572) * opacityScale);
        sdkSpriteDrawFooter(position, 0.0f, opacity, *(s16 *)(work + 0x34), *(s32 *)(work + 0x700));
    }
}
#pragma pop

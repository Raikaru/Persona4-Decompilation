/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/g_data/g_data.c); members 001203a0-00120ae0 */

#include "model_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "dat_panel_internal.h"
#include "primitive_point_buffer.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "rw/plcore/barenderstate.h"
extern void PrimDrawFlatRectangle(void *colorData, void *rectangleData, f32 fparg0, s32 preserveState);
extern u8 *resourceFindByName(char *filename);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y,
                          u8 alphaSubtract, u8 red, u8 green, u8 blue, f32 z, s32 setStates);
extern void kAssertFail(const void *file, s32 line);
extern u8 D_005E5830[];
extern u8 D_005E5850[];
typedef struct {
    u8 b[4];
} PanelRgba;

void drawNumberSprites(Vec2f position, f32 depth, PanelRgba color, u32 number, s32 sprites);
// FUN_001203A0
/* measured: b210 -O2 emits all 1856 retail bytes. Lifetime splitting
   separates the depth and HP row values. Coordinate accumulation and
   explicit byte conversions retain retail's separate evaluations.
   Full owner proof: build/cos20335-continuation/field-ui/review-001203a0-final. */
#pragma push
#pragma opt_lifetimes on
void drawUnitStatusPanel(Vec2f origin, f32 depth, s32 opacity, u8 *entry, s32 showMaximum, s32 fullName)
{
    extern u8 *resourceFindByName(char *filename);
    extern void kAssertFail(const void *file, s32 line);
    extern u32 datPersonaDisplayName(s16 unit);
    extern u32 datPersonaNamePart1(s16 unit);
    extern int frFontExDrawTextWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id, const char *str, int flags, int charWidth);
    extern u32 datCalcGetHpById(s16 unit);
    extern u16 datCalcMaxHpById(s16 unit);
    extern u32 datCalcGetSpById(s16 unit);
    extern u16 datCalcMaxSpById(s16 unit);
    extern void sdkSpriteDrawOnceTinted(s32 parent, s32 sprites, s32 index, f32 x, f32 y, u8 alpha, u8 red, u8 green, u8 blue, f32 depth, s32 flags);
    extern void sdkSpriteDrawOnce(s32 parent, s32 sprites, s32 index, f32 x, f32 y, u8 alpha, f32 depth, s32 flags);
    extern void PrimDrawFlatRectangle(void *color, void *rectangle, f32 depth, s32 mode);
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 D_005E4F88[];
    PanelRgba numberColor;
    u8 emptyColor[4];
    PanelRgba hpMaxColor;
    PanelRgba spMaxColor;
    Vec2f point;
    s32 hpRect[4];
    s32 spRect[4];
    s32 panelSprites;
    s32 helpSprites;
    s8 fontStyle;
    s16 unit;
    s32 textColor;
    f32 hpMarkerX;
    f32 spMarkerX;
    f32 spY;
    f32 hpY;
    s16 entryStyle;
    s32 alpha;
    s32 currentHp;
    u8 *name;
    s32 missingHpWidth;
    s32 maximumHp;
    u32 hpNumber;
    u32 maxHpNumber;
    u32 spNumber;
    u32 maxSpNumber;

    panelSprites = (s32)resourceFindByName((char *)D_005E5830);
    helpSprites = (s32)resourceFindByName((char *)D_005E5850);
    if (panelSprites == 0) {
        kAssertFail(D_005E4F88, 0xB1);
    }
    if (helpSprites == 0) {
        kAssertFail(D_005E4F88, 0xB2);
    }
    unit = ((DatPanelEntry*)entry)->unit;
    entryStyle = ((DatPanelEntry*)entry)->style;
    switch (entryStyle) {
    case 0:
        fontStyle = 6;
        numberColor.b[0] = 0xEC;
        numberColor.b[1] = 0x7C;
        numberColor.b[2] = 0;
        break;
    case 1:
        fontStyle = 7;
        numberColor.b[2] = numberColor.b[1] = numberColor.b[0] = 0x2D;
        break;
    case 2:
        fontStyle = 6;
        numberColor.b[0] = 0xEC;
        numberColor.b[1] = 0x7C;
        numberColor.b[2] = 0;
        break;
    default:
        fontStyle = 6;
        numberColor.b[1] = numberColor.b[0] = 0xFF;
        numberColor.b[2] = 0x81;
        break;
    }
    numberColor.b[3] = (u8)opacity;
    point.x = origin.x;
    point.y = origin.y;
    if (((DatPanelEntry*)entry)->kind == 3) {
        point.y = origin.y - 5.0f;
    }
    alpha = opacity & 0xFF;
    textColor = alpha | -0x100;
    if (fullName != 0) {
        name = (u8 *)datPersonaDisplayName(unit);
    } else {
        name = (u8 *)datPersonaNamePart1(unit);
    }
    frFontExDrawTextWithCharWidth(point.x, point.y, 0.0f, textColor, fontStyle, 1, (const char *)name, 0, -1);
    hpNumber = datCalcGetHpById(unit) & 0xFFFF;
    point.x = 30.0f + origin.x;
    point.y = 27.0f + origin.y;
    drawNumberSprites(point, depth, numberColor, hpNumber, panelSprites);
    if (showMaximum != 0) {
        hpMarkerX = 52.0f + origin.x;
        point.x = hpMarkerX;
        hpY = 27.0f;
        hpY += origin.y;
        point.y = hpY;
        sdkSpriteDrawOnceTinted(0, helpSprites, 0x3D, hpMarkerX, hpY, (0xFF - alpha) & 0xFF, 0xFF, 0xA2, 0, depth, 0);
        point.x = 103.0f + origin.x;
        point.y = hpY;
        maxHpNumber = datCalcMaxHpById(unit) & 0xFFFF;
        hpMaxColor.b[0] = 0xFB;
        hpMaxColor.b[1] = 0xA2;
        hpMaxColor.b[2] = 0;
        hpMaxColor.b[3] = (u8)opacity;
        drawNumberSprites(point, depth, hpMaxColor, maxHpNumber, panelSprites);
        point.x = 123.0f + origin.x;
        point.y = 31.0f + origin.y;
    } else {
        point.x = 49.0f + origin.x;
        point.y = 30.0f + origin.y;
    }
    alpha = (u8)opacity;
    alpha = 0xFF - alpha;
    hpY = point.y;
    sdkSpriteDrawOnce(0, panelSprites, 0x4B, point.x, hpY, (u8)alpha, depth, 0);
    sdkSpriteDrawOnce(0, panelSprites, 0x4C, point.x, hpY, alpha & 0xFF, depth, 0);
    currentHp = datCalcGetHpById(unit) & 0xFFFF;
    maximumHp = datCalcMaxHpById(unit) & 0xFFFF;
    missingHpWidth = (s32)((maximumHp - (currentHp & 0xFFFF)) * 0x58) / maximumHp;
    hpRect[2] = missingHpWidth;
    hpRect[3] = 6;
    hpRect[0] = (s32)((95.0f + point.x) - (f32)missingHpWidth);
    hpRect[1] = (s32)(4.0f + hpY);
    emptyColor[2] = emptyColor[1] = emptyColor[0] = 0x2D;
    emptyColor[3] = (u8)opacity;
    PrimDrawFlatRectangle(emptyColor, hpRect, 0.0f, 1);
    spNumber = datCalcGetSpById(unit) & 0xFFFF;
    point.x = 30.0f + origin.x;
    point.y = 43.0f + origin.y;
    drawNumberSprites(point, depth, numberColor, spNumber, panelSprites);
    if (showMaximum != 0) {
        spMarkerX = 52.0f + origin.x;
        point.x = spMarkerX;
        spY = 43.0f;
        spY += origin.y;
        point.y = spY;
        sdkSpriteDrawOnceTinted(0, helpSprites, 0x3D, spMarkerX, spY, (u32)alpha & 0xFFU, 0xFF, 0xA2, 0, depth, 0);
        point.x = 103.0f + origin.x;
        point.y = spY;
        maxSpNumber = datCalcMaxSpById(unit) & 0xFFFF;
        spMaxColor.b[0] = 0xFB;
        spMaxColor.b[1] = 0xA2;
        spMaxColor.b[2] = 0;
        spMaxColor.b[3] = (u8)opacity;
        drawNumberSprites(point, depth, spMaxColor, maxSpNumber, panelSprites);
        point.x = 123.0f + origin.x;
        point.y = 42.0f + origin.y;
    } else {
        point.x = 49.0f + origin.x;
        point.y = 41.0f + origin.y;
    }
    alpha = (u32)opacity & 0xFFU;
    alpha = 0xFFU - (u32)alpha;
    spY = point.y;
    sdkSpriteDrawOnce(0, panelSprites, 0x4B, point.x, spY, (u8)alpha, depth, 0);
    sdkSpriteDrawOnce(0, panelSprites, 0x4D, point.x, spY, alpha & 0xFF, depth, 0);
    {
        s32 currentSp = datCalcGetSpById(unit) & 0xFFFF;
        s32 maximumSp = datCalcMaxSpById(unit) & 0xFFFF;
        s32 missingSpWidth = (s32)((maximumSp - (currentSp & 0xFFFF)) * 0x58) / maximumSp;
        spRect[2] = missingSpWidth;
        spRect[3] = 6;
        spRect[0] = (s32)((95.0f + point.x) - (f32)missingSpWidth);
        spRect[1] = (s32)(4.0f + spY);
    }
    emptyColor[2] = emptyColor[1] = emptyColor[0] = 0x2D;
    emptyColor[3] = (u8)opacity;
    PrimDrawFlatRectangle(emptyColor, &spRect[0], 0.0f, 1);
}
#pragma pop

// FUN_00120AE0
/* Draw decimal digits right-to-left with inverted sprite alpha and sixteen-pixel spacing. */
void drawNumberSprites(Vec2f position, f32 depth, PanelRgba color, u32 number, s32 sprites)
{
    s32 alpha;
    u32 remaining;
    s32 panelSprites;
    u8 blue;
    u8 green;

    remaining = number;
    panelSprites = sprites;
    blue = color.b[2];
    green = color.b[1];
    alpha = 0xFF;
    alpha -= color.b[3];
    do {
        sdkSpriteDrawOnceTinted(0, panelSprites, (remaining % 10U) + 9,
                      position.x, position.y,
                      alpha & 0xFF, color.b[0], green,
                      blue, depth, 0);
        position.x = position.x - 16.0f;
        remaining = remaining / 10U;
    } while (remaining != 0);
}

#include "btl_shuffle_draw_internal.h"

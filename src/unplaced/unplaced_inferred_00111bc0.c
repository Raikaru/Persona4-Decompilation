/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00111bc0-00113800 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
#include "datUnit_internal.h"

/* datEntryReset and the row renderers establish this 0x1C-byte record. */
typedef struct DatItemEntry {
    s16 itemId;
    s16 count;
    s16 unk4;
    s16 comparisonId;
    s32 priceMode;
    s32 showName;
    s32 showStats;
    u16 badgeFlags;
    s16 colorIndex;
    s16 layoutIndex;
    u8 pad1A[2];
} DatItemEntry;

/* Twelve-byte skill row; the first halfword is owned by its caller. */
typedef struct DatSkillCostRow {
    u16 unk0;
    u16 skillId;
    s32 costA;
    s32 costB;
} DatSkillCostRow;

typedef struct DatSkillRows {
    DatSkillCostRow learned[8];
    s16 learnedCount;
    u8 pad62[2];
    DatSkillCostRow learnable[32];
    u16 learnableLevels[32];
    s16 learnableCount;
} DatSkillRows;

typedef struct DatCountLayout {
    f32 countOffset;
    u8 pad4[0xC];
} DatCountLayout;

typedef struct DatNamedEntry {
    s16 kind;
    s16 fontIndex;
    u8 pad4[6];
    u16 id;
} DatNamedEntry;

typedef struct DatEntryRecord {
    s16 kind;
    s16 fontIndex;
    s8 indexA;
    s8 indexB;
    u8 pad6[2];
    u8 data[0x22C];
} DatEntryRecord;

/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u8 *datPersonaGetSkills(void);
extern s32 datPersonaCollectLearnableSkills(u8 *persona, void *outputSkills, void *outputLevels);
typedef struct {
    f32 x;
    f32 y;
} Vec2f;

void datEntryDrawIdName(Vec2f , f32 , u8 , void *, s32 );
void ShdSkill_DrawDescriptor(Vec2f , f32 , u8 , void *, s32 );
void ShdSkill_DrawEntryName(Vec2f , f32 , u8 , void *, s32 );
void datSetFlag(s32, s32);
void datInitDefaultGameState(void);
void sdkPadStartSequence(s32 , s32 , s32 , s32 );
extern s32 iGpffffb19c;
extern s32 datGetFlag(s32 );
extern void H_Pad_StopRumble(void);
extern void memset(u8 *, s32 , s32 );
extern u16 datCalcThresholdKindById(s16 , s32 );
extern u32 datCalcSkillCostById(s16 , s32 );
extern void *datCalcGetIdRecord(u16 );
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 , s32 , f32 x, f32 y,
                          u8 , u8 , u8 , u8 ,
                          f32 z, s32 );
extern u32 datEntryGetFlags(s16 );
extern s32 resourceFindByName(void *name);
extern u16 datEntryGetPrimaryValue(s16 );
extern u16 datEntryGetSecondaryValue(s16 );
extern u16 datEntryGetMiddleBandValue(s16 );
extern u16 datEntryGetLastBandValue(s16 );
extern s32 datIdBand(s16 );
extern s8 D_005E47F0[];
static inline s32 datAddSkillByteOffset(s32 offset, s32 base)
{
    return offset + base;
}

u32 datGetClearedWord(void);

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Carry persistent state across a reset: save the flags, category values and money, reset to the defaults, then restore them with the new end date [inferred]
// FUN_00111BC0
#pragma opt_propagation off
void datCarryOverPersistentState(void)
{
    s32 saved;
    s32 value;
    s32 clearCount;
    s32 result;
    s32 count;
    s8 flag;
    s32 i;
    s32 savedValues[344];
    s32 datGetScriptValue(s32);
    void datSetScriptValue(s32, u32);
    s32 datItemCount(s16);
    s32 datGetFlag(s32);
    void datSetFlag(s32, s32);
    s16 datGetCategoryValueById(s16, s16);
    u32 datGetMoney(void);
    void datSetMoney(u32);
    void datSetCategoryValueById(s16, s16, s16);
    u32 datGetClearedWord(void);
    void func_00110470(u32);
    void fclCombineSaveSnapshot(void);
    void fclCombineRestoreSnapshot(void);
    extern float D_005E4700[4];
    typedef struct { float a; float b; float c; float d; } Vec4;
    saved = iGpffffb19c;
    count = 0;
    flag = 0;
    *(Vec4 *)savedValues = *(Vec4 *)D_005E4700;
    value = datGetScriptValue(0x7C);
    clearCount = (s32)datGetClearedWord() + 1;
    if ((datItemCount(0x4A0) & 0xFF) > 0) {
        savedValues[4] = 0x4A0;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A1) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A1;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A2) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A2;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A3) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A3;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A4) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A4;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A5) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A5;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A6) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A6;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A7) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A7;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A8) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A8;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A9) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4A9;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AA) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4AA;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AB) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4AB;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AC) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4AC;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AD) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4AD;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AE) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4AE;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AF) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4AF;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B0) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4B0;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B1) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4B1;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B2) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4B2;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B3) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x4B3;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x418) & 0xFF) > 0) {
        savedValues[4 + (count & 0xFF)] = 0x418;
        count = (count + 1) & 0xFF;
    }
    if (datGetFlag(0x2F) != 0) {
        flag = 1;
    }
    if (datGetFlag(0x1DD) != 0) {
        flag = 1;
    }
    i = 0;
    goto loop1_check;
loop1:
    savedValues[332 + i] = datGetFlag(i + 0x39);
    i++;
loop1_check:
    if (i < 7) {
        goto loop1;
    }
    result = 0;
    goto loop2_check;
loop2:
    {
        s32 *p = &savedValues[result];
        s32 v = *p;
        if (v == 0) {
            goto loop2_done;
        }
        savedValues[132 + result] = datGetFlag(v);
        result++;
    }
loop2_check:
    if (result < 200) {
        goto loop2;
    }
loop2_done:
    fclCombineSaveSnapshot();
    i = 0;
    goto loop3_check;
loop3:
    ((s16 *)savedValues)[680 + i] = datGetCategoryValueById(1, (s16)i);
    i++;
loop3_check:
    if (i < 5) {
        goto loop3;
    }
    result = (s32)datGetMoney();
    datInitDefaultGameState();
    i = 0;
    goto loop4_check;
loop4:
    datSetFlag(i + 0x39, savedValues[332 + i]);
    i++;
loop4_check:
    if (i < 7) {
        goto loop4;
    }
    i = 0;
    goto loop5_check;
loop5:
    {
        s32 *p = &savedValues[i];
        s32 v = *p;
        if (v == 0) {
            goto loop5_done;
        }
        datSetFlag(v, savedValues[132 + i]);
        i++;
    }
loop5_check:
    if (i < 200) {
        goto loop5;
    }
loop5_done:
    i = 0;
    count &= 0xFF;
    goto loop6_check;
loop6:
    datItemSetCount(((s16 *)savedValues)[8 + i * 2], 1);
    i++;
loop6_check:
    if (i < count) {
        goto loop6;
    }
    if (flag == 1) {
        datSetFlag(0x1DD, 1);
    }
    fclCombineRestoreSnapshot();
    datSetFlag(0x1210, 1);
    datSetScriptValue(0x7C, (u32)value);
    func_00110470((u32)clearCount);
    i = 0;
    goto loop7_check;
loop7:
    datSetCategoryValueById(1, (s16)i, ((s16 *)savedValues)[680 + i]);
    i++;
loop7_check:
    if (i < 5) {
        goto loop7;
    }
    datSetMoney((u32)result);
    datSetFlag(0x800, 1);
    iGpffffb19c = saved;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw one entry row: the name text, the stat value, the count, and the badges, at the entry's position and depth [inferred]
// FUN_00112300
void datEntryDrawRow(Vec2f position, f32 inputDepth, u8 opacity, u8 *inputEntry)
{
    f32 depth;
    u8 *entry;
    u8 buf[256];
    s32 itemTexture;
    s32 badgeTexture;
    union {
        s64 whole;
        f32 values[2];
        Vec2f position;
    } xy;
    f32 rowY;
    s32 nameText;
    
    s32 datItemPrice(s16);
    void sprintf(void *, void *, s32);
    s32 resourceFindByName(void *);
    void kAssertFail(void *, s32);
    void datEntryDrawBadges(Vec2f, f32, u8, u8 *, s32, s32);
    void datEntryDrawStatValue(Vec2f, f32, u8, u8 *, s32);
    void datEntryDrawCount(Vec2f, f32, u8, u8 *, s32);
    extern f32 D_005E4790[];
    extern f32 D_005E4794[];
    extern f32 D_005E479C[];
    extern u8 D_005E5830[];
    extern u8 D_005E5850[];
    extern u8 iGpffff9be0;
    extern u8 iGpffff9bd8;
    extern u8 iGpffff9be8;

    depth = inputDepth;
    entry = inputEntry;
    itemTexture = resourceFindByName(D_005E5830);
    badgeTexture = resourceFindByName(D_005E5850);
    if (itemTexture == 0) {
        kAssertFail(&iGpffff9be0, 0x93);
    }
    if (badgeTexture == 0) {
        kAssertFail(&iGpffff9be0, 0x94);
    }
    if (((DatItemEntry *)entry)->badgeFlags != 0) {
        datEntryDrawBadges(position, depth, opacity, entry, itemTexture, badgeTexture);
        position.x = position.x + 45.0f;
    }
    if (((DatItemEntry *)entry)->showName != 0) {
        badgeTexture = opacity & 0xFF;
        nameText = (s32)datGetItemNameId(((DatItemEntry *)entry)->itemId);
        frFontExDrawTextWithCharWidth(
            position.x,
            position.y,
            depth,
            badgeTexture | ~0xFF,
            ((s8 *)&iGpffff9bd8)[((DatItemEntry *)entry)->colorIndex],
            1,
            (const char *)nameText,
            0,
            -1);
    }
    if (((DatItemEntry *)entry)->showStats != 0) {
        xy.values[0] = position.x +
                       D_005E4790[((DatItemEntry *)entry)->layoutIndex * 4];
        rowY = 9.0f;
        rowY += position.y;
        xy.values[1] = rowY;
        datEntryDrawStatValue(xy.position, depth, opacity, entry, itemTexture);
    }
    if (((DatItemEntry *)entry)->count != -1) {
        xy.position.x = position.x +
                        D_005E4794[((DatItemEntry *)entry)->layoutIndex * 4];
        rowY = 12.0f;
        rowY += position.y;
        xy.position.y = rowY;
        datEntryDrawCount(xy.position, depth, opacity, entry, itemTexture);
    }
    if (((DatItemEntry *)entry)->priceMode != -1) {
        xy.values[0] = position.x +
                       D_005E479C[((DatItemEntry *)entry)->layoutIndex * 4];
        xy.values[1] = position.y;
        itemTexture = ((opacity & 0xFF) * 0xFF) / 255U;
        sprintf(buf, &iGpffff9be8,
                      datItemPrice(((DatItemEntry *)entry)->itemId));
        frFontExDrawText(
            (f32)(s32)xy.values[0],
            (f32)(s32)xy.values[1],
            depth,
            itemTexture | ~0xFF,
            ((s8 *)&iGpffff9bd8)[((DatItemEntry *)entry)->colorIndex],
            0,
            (void *)buf,
            0,
            0);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Reset the entry's fields to their defaults: sentinel -1 for the indices and 3 for the state [inferred]
// FUN_001125D0
void datEntryReset(u8 *entry) {
    s32 enabled;
    s32 defaultValue;

    enabled = 1;
    ((DatItemEntry *)entry)->itemId = enabled;
    defaultValue = -1;
    ((DatItemEntry *)entry)->count = defaultValue;
    ((DatItemEntry *)entry)->comparisonId = defaultValue;
    ((DatItemEntry *)entry)->priceMode = defaultValue;
    ((DatItemEntry *)entry)->showName = enabled;
    ((DatItemEntry *)entry)->showStats = 0;
    defaultValue = 3;
    ((DatItemEntry *)entry)->badgeFlags = defaultValue;
    ((DatItemEntry *)entry)->layoutIndex = 0;
    ((DatItemEntry *)entry)->colorIndex = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw the entry's icons when the flag bits in the state word at 0x14 are set, using the colours from the two colour tables [inferred]
// FUN_00112610
/* Earlier whole-layout typing probe: DatItemEntry access changed codegen (nd 415).; access-site and typed-local forms now match. */
void datEntryDrawBadges(Vec2f position, f32 depth, u8 opacity, u8 *entry, s32 itemTexture, s32 badgeTexture)
{
    typedef struct {
        u8 b[4];
    } Color4;
    extern u8 D_005E4710[];
    extern u8 D_005E4730[];
    void datEntryDrawFlagIcon(s64, f32, Color4, s16, s32, s32);
    Color4 categoryColor;
    Color4 flagColor;
    Vec2f pos;
    s32 flags;
    s32 mode;
    s32 selected;
    u8 *table;
    s32 alpha;
    DatItemEntry *itemEntry = (DatItemEntry *)(entry);

    flags = datEntryGetFlags(((DatItemEntry *)entry)->itemId);
    if (((DatItemEntry *)entry)->badgeFlags & 2) {
        table = &D_005E4710[(((DatItemEntry *)entry)->colorIndex) * 4];
        categoryColor = *(Color4 *)table;
        mode = -1;
        if (flags & 0x3FFF) {
            mode = 2;
            selected = itemTexture;
        } else if (flags & 0xC000) {
            mode = 3;
            selected = itemTexture;
        } else if (flags & 0x10000) {
            mode = 2;
            selected = itemTexture;
        } else if (flags & 0x20000) {
            mode = 2;
            selected = itemTexture;
        } else if (flags & 0x40000) {
            mode = 2;
            selected = itemTexture;
        }
        if (mode != -1) {
            alpha = 255;
            alpha -= opacity & 0xFF;
            sdkSpriteDrawOnceTinted(0, selected, mode, position.x, position.y,
                          alpha & 0xFF,
                          categoryColor.b[0], categoryColor.b[1], categoryColor.b[2],
                          depth, 0);
        }
    }
    if (itemEntry->badgeFlags & 1) {
        table = &D_005E4730[(((DatItemEntry *)entry)->colorIndex) * 4];
        flagColor = *(Color4 *)table;
        flagColor.b[3] = opacity;
        pos.x = position.x + 3.0f;
        pos.y = position.y + 2.0f;
        datEntryDrawFlagIcon(*(s64 *)&pos, depth, flagColor,
                      ((DatItemEntry *)entry)->itemId, itemTexture, badgeTexture);
    }
}
#pragma pop

typedef struct {
    u8 b[4];
} StatColor;

static inline void func_00112830_number(Vec2f pos, f32 depth, u16 value,
                                        StatColor color, s32 tex)
{
    f32 x;

    if (value / 100 != 0) {
        x = 30.0f + pos.x;
    } else {
        x = 22.0f + pos.x;
    }
    do {
        sdkSpriteDrawOnceTinted(0, tex, value % 10 + 0x1E, x, pos.y, 0xFF - color.b[3],
                      color.b[0], color.b[1], color.b[2], depth, 0);
        x -= 15.0f;
        value /= 10;
    } while (value > 0);
}

static inline void func_00112830_arrow(Vec2f pos, f32 depth, StatColor color,
                                       u16 value, u16 prev, s32 tex)
{
    s32 glyph;

    if (value != prev) {
        if (value < prev) {
            glyph = 40;
        } else if (prev < value) {
            glyph = 41;
        }
        sdkSpriteDrawOnceTinted(0, tex, glyph, pos.x, pos.y - 1.0f, 0xFF - color.b[3],
                      color.b[0], color.b[1], color.b[2], depth, 0);
    }
}

#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw a stat value and, when it differs from the previous value, its up or down arrow glyph, then its digits [inferred]
// FUN_00112830
/* Earlier whole-layout typing probe: DatItemEntry access changed codegen (nd 1431).; access-site and typed-local forms now match. */
void datEntryDrawStatValue(Vec2f pos, f32 depth, u8 alpha, u8 *entry, s32 tex)
{
    extern StatColor D_005E4750[];
    StatColor color;
    u16 value;
    s32 i;
    DatItemEntry *itemEntry = (DatItemEntry *)(entry);

    color = D_005E4750[((DatItemEntry *)entry)->colorIndex];
    color.b[3] = alpha;
    switch (datIdBand(((DatItemEntry *)entry)->itemId)) {
    case 0:
        value = datEntryGetPrimaryValue(((DatItemEntry *)entry)->itemId);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (((DatItemEntry *)entry)->comparisonId != -1) {
            func_00112830_arrow(pos, depth, color,
                                datEntryGetPrimaryValue(((DatItemEntry *)entry)->comparisonId), value, tex);
        }
        pos.x += 42.0f;
        value = datEntryGetSecondaryValue(((DatItemEntry *)entry)->itemId);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (itemEntry->comparisonId != -1) {
            func_00112830_arrow(pos, depth, color,
                                datEntryGetSecondaryValue(itemEntry->comparisonId), value, tex);
        }
        break;
    case 1:
        value = datEntryGetMiddleBandValue(((DatItemEntry *)entry)->itemId);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (((DatItemEntry *)entry)->comparisonId != -1) {
            func_00112830_arrow(pos, depth, color,
                                datEntryGetMiddleBandValue(((DatItemEntry *)entry)->comparisonId), value, tex);
        }
        pos.x += 42.0f;
        value = datEntryGetLastBandValue(((DatItemEntry *)entry)->itemId);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (itemEntry->comparisonId != -1) {
            func_00112830_arrow(pos, depth, color,
                                datEntryGetLastBandValue(itemEntry->comparisonId), value, tex);
        }
        break;
    case 2:
        pos.x += 35.0f;
        pos.y += 4.0f;
        for (i = 0; i < 4; i++) {
            sdkSpriteDrawOnceTinted(0, tex, 60, pos.x, pos.y, 0xFF - alpha,
                          color.b[0], color.b[1], color.b[2], depth, 0);
            pos.x += 34.0f;
        }
        break;
    }
}
#pragma pop

typedef struct { u8 r, g, b, a; } FontGlyphColor;

static inline s32 fontDrawLeadingGlyph(const Vec2f *position, f32 depth, u8 opacity, s32 texture,
    const FontGlyphColor *color, u32 *blue, u32 *green)
{
    s32 alpha;

    *blue = color->b;
    *green = color->g;
    alpha = 255 - (opacity & 0xFF);
    sdkSpriteDrawOnceTinted(0, texture, 0x47, position->x, 2.0f + position->y,
                  alpha, color->r, *green, *blue, depth, 0);
    return alpha;
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
/* Native b210 -O2: 440 executable bytes, nine resolved relocations,
 * and eight retail alignment zeros. The leading draw keeps inverse
 * opacity live while the loop retains its blue and green snapshots. */
// Intent: Draw the entry's count as text glyphs, right to left, after the leading glyph [inferred]
// FUN_001130C0
void datEntryDrawCount(Vec2f position, f32 depth, u8 opacity, u8 *entry, s32 texture)
{
    struct {
        s8 text[0x4C];
        FontGlyphColor color;
    } stack;
    s16 count;
    u32 color2;
    u32 color1;
    s32 inverseOpacity;
    s32 characterIndex;
    u8 loopBlue;
    u8 loopGreen;
    u8 *colorEntry;
    extern u8 D_005E4770[];
    extern u8 D_005E4798[];
    extern s32 iGpffff9bec;
    extern s32 sprintf(void *, const void *, ...);
    extern s32 strlen(const void *);

    count = ((DatItemEntry *)entry)->count;
    colorEntry = D_005E4770 + (((DatItemEntry *)entry)->colorIndex * 4);
    stack.color = *(FontGlyphColor *)colorEntry;
    inverseOpacity = fontDrawLeadingGlyph(&position, depth, opacity, texture,
        &stack.color, &color2, &color1);
    sprintf(stack.text, &iGpffff9bec, (s16)count);
    position.x = position.x + (14.0f +
        ((DatCountLayout *)D_005E4798)[((DatItemEntry *)entry)->layoutIndex].countOffset);
    characterIndex = strlen(stack.text) - 1;
    loopBlue = color2;
    loopGreen = color1;
    while (characterIndex >= 0) {
        sdkSpriteDrawOnceTinted(0, texture, stack.text[characterIndex] - 0x27,
                      position.x, position.y, inverseOpacity,
                      stack.color.r, loopGreen, loopBlue, depth, 0);
        position.x -= 14.0f;
        characterIndex--;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw the icon for the first set flag bit, with its sprite mode and id, at the given position [inferred]
// FUN_00113280
void datEntryDrawFlagIcon(Vec2f position, f32 depth, s32 packedColor, s16 itemId, s32 itemTexture,
                   s32 badgeTexture)
{
    f32 scale;
    s32 flags;
    s32 mode;
    s32 id;
    s32 alpha;

    scale = depth;
    flags = datEntryGetFlags(itemId);
    mode = -1;
    if (flags & 0x81) {
        mode = 0x14;
        id = itemTexture;
    } else if (flags & 0x102) {
        mode = 0x15;
        id = itemTexture;
    } else if (flags & 0x204) {
        mode = 0x16;
        id = itemTexture;
    } else if (flags & 0x408) {
        mode = 0x17;
        id = itemTexture;
    } else if (flags & 0x810) {
        mode = 0x18;
        id = itemTexture;
    } else if (flags & 0x1020) {
        mode = 0x19;
        id = itemTexture;
    } else if (flags & 0x2040) {
        mode = 0x1A;
        id = itemTexture;
    } else if (flags & 0x4000) {
        mode = 0x1B;
        id = itemTexture;
    } else if (flags & 0x8000) {
        mode = 0x1C;
        id = itemTexture;
    } else if (flags & 0x10000) {
        mode = 0x1B;
        id = badgeTexture;
    } else if (flags & 0x20000) {
        mode = 0x1C;
        id = badgeTexture;
    } else if (flags & 0x40000) {
        mode = 0x1A;
        id = badgeTexture;
    }
    if (mode != -1) {
        alpha = 0xFF;
        alpha -= ((u8 *)&packedColor)[3];
        sdkSpriteDrawOnceTinted(0, id, mode, position.x, position.y,
                      alpha & 0xFF,
                      ((u8 *)&packedColor)[0], ((u8 *)&packedColor)[1],
                      ((u8 *)&packedColor)[2], scale, 0);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Forward a draw to the subsystem routine only while flag 0x39 is set [inferred]
// FUN_00113480
void datEntryDrawGatedByFlag39(s32 port, s32 sequence, s32 duration, s32 flags)
{
    if (datGetFlag(0x39) != 0) {
        sdkPadStartSequence(port, sequence, duration, flags);
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Stop controller rumble [inferred]
// FUN_00113500
void datStopPadRumble(void) {
    H_Pad_StopRumble();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Fill a skill cost row from the table entry at the index: the skill id at +2, and the cost at +4 or +8 by the threshold kind; return 1 when the entry is present [inferred]
// FUN_00113520
/* Earlier whole-layout typing probe: DatSkillCostRow/DatPersonaRecord access changed codegen (nd 187).; access-site and typed-local forms now match. */
s32 datPersonaFillSkillCostRow(s32 unitId, struct DatPersonaRecord *persona, s32 skillIndex, u8 *row)
{
    s32 costKind;
    u16 skillId;
    u16 rowSkillId;
    DatSkillCostRow *costRow = (DatSkillCostRow *)(row);

    ((DatSkillCostRow *)row)->skillId = 0;
    ((DatSkillCostRow *)row)->costA = 0;
    ((DatSkillCostRow *)row)->costB = 0;
    skillId = ((DatPersonaRecord *)(datAddSkillByteOffset(skillIndex * 2, (s32)persona)))->skills[0];
    if (skillId != 0) {
        costRow->skillId = skillId;
        if (unitId != 0) {
            rowSkillId = costRow->skillId;
            if ((s32)rowSkillId < 0x1B8) {
                costKind = datCalcThresholdKindById((s16)unitId, rowSkillId) & 0xFFFF;
                switch (costKind) {
                case 1:
                    costRow->costA = datCalcSkillCostById((s16)unitId, costRow->skillId);
                    break;
                case 2:
                    costRow->costB = datCalcSkillCostById((s16)unitId, costRow->skillId);
                    break;
                }
            }
        }
        return 1;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Fill the persona's skill rows: up to eight learned skills first, then the learnable skills, with the counts at 0x60 and 0x224 [inferred]
// FUN_00113610
void datPersonaFillSkillRows(s32 personaAddress, u8 *rows)
{
    u16 learnableSkills[32];
    u16 learnableLevels[32];
    u8 *table;
    DatSkillCostRow *entry;
    s16 i;
    s16 j;
    s32 count;
    s32 index;
    u16 value;

    // Old-style call: no argument is passed; datPersonaGetSkills reads the record still in $a0 (mwccps2 hidden-argument liveness).
    table = datPersonaGetSkills();
    i = 0;
    while (i < 8) {
        index = (s32)i * 0xC;
        entry = (DatSkillCostRow *)(rows + index);
        entry->costA = 0;
        entry->costB = 0;
        value = ((u16 *)table)[(s32)i];
        if (value == 0) {
            break;
        }
        entry->skillId = value;
        i++;
    }
    ((DatSkillRows *)rows)->learnedCount = i;
    count = (s16)datPersonaCollectLearnableSkills((u8 *)(u32)personaAddress, learnableSkills, learnableLevels);
    j = 0;
    while (j < count) {
        index = (s32)j * 0xC;
        entry = (DatSkillCostRow *)(rows + 0x64 + index);
        entry->costA = 0;
        entry->costB = 0;
        entry->skillId = learnableSkills[(s32)j];
        ((DatSkillRows *)rows)->learnableLevels[(s32)j] = learnableLevels[(s32)j];
        j++;
    }
    ((DatSkillRows *)rows)->learnableCount = count;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Clear the first three halfwords of a record [inferred]
// FUN_00113730
void datRecordClearHeader(s16 *record) {
    record[0] = 0;
    record[1] = 0;
    record[2] = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Reset a record: zero the two halfword counters, set the two indices at +4 and +5 to -1, and clear the 0x22C bytes from +8 [inferred]
// FUN_00113750
void datRecordResetAll(u8 *record) {
    ((DatEntryRecord *)record)->kind = 0;
    ((DatEntryRecord *)record)->fontIndex = 0;
    ((DatEntryRecord *)record)->indexA = -1;
    ((DatEntryRecord *)record)->indexB = -1;
    memset(((DatEntryRecord *)record)->data, 0, 0x22C);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw an entry by its kind: kind 0 draws the id name, kind 1 the skill descriptor, kind 2 the skill entry name [inferred]
// FUN_00113790
void datEntryDrawByKind(Vec2f position, u8 opacity, void *entry, s32 flags, f32 depth)
{
    s16 kind;

    kind = *(s16 *)entry;
    switch (kind) {
    case 0:
        datEntryDrawIdName(position, depth, opacity, entry, flags);
        return;
    case 1:
        ShdSkill_DrawDescriptor(position, depth, opacity, entry, flags);
        return;
    case 2:
        ShdSkill_DrawEntryName(position, depth, opacity, entry, flags);
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw the record's id name at a position with the given alpha and the font index from the table [inferred]
// FUN_00113800
void datEntryDrawIdName(Vec2f position, f32 depth, u8 opacity, void *entry, s32 flags)
{
    f32 scale;
    s32 color;
    char index;
    void *temp;

    scale = depth;

    temp = datCalcGetIdRecord(((DatNamedEntry *)entry)->id);
    color = -0x100 | (((opacity & 0xFF) * 0xFF) / 255U);
    index = ((char *)D_005E47F0)[((DatNamedEntry *)entry)->fontIndex * 2];
    frFontExDrawText((f32)(s32)position.x, (f32)(s32)position.y, scale, color, index, 1, temp, 0, 0);
}
#pragma pop

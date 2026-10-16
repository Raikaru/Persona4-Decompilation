/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 00111bc0-00113800 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u8 *datPersonaGetSkills(void);
extern s32 datPersonaCollectLearnableSkills(u8 *persona, void *skills, void *levels);
typedef struct {
    f32 x;
    f32 y;
} Vec2f;

void datEntryDrawIdName(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3);
void ShdSkill_DrawDescriptor(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3);
void ShdSkill_DrawEntryName(Vec2f arg0, f32 fparg0, u8 arg1, void *arg2, s32 arg3);
void datSetFlag(s32, s32);
void datInitDefaultGameState(void);
void sdkPadStartSequence(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 iGpffffb19c;
extern s32 datGetFlag(s32 arg0);
extern void H_Pad_StopRumble(void);
extern void memset(u8 *arg0, s32 arg1, s32 arg2);
extern u16 datCalcThresholdKindById(s16 arg0, s32 arg1);
extern u32 datCalcSkillCostById(s16 arg0, s32 arg1);
extern void *datCalcGetIdRecord(u16 arg0);
extern void sdkSpriteDrawOnceTinted(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, u8 arg4, u8 arg5,
                          f32 z, s32 arg6);
extern u32 datEntryGetFlags(s16 arg0);
extern s32 resourceFindByName(void *param);
extern u16 func_001068b0(s16 arg0);
extern u16 func_001068e0(s16 arg0);
extern u16 func_00106940(s16 arg0);
extern u16 func_00106970(s16 arg0);
extern s32 datIdBand(s16 arg0);
extern s8 D_005E47F0[];
static inline s32 p4_00113520_add(s32 offset, s32 base)
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
    s32 end_date;
    s32 result;
    s32 count;
    s8 flag;
    s32 i;
    s32 buf[344];
    s32 func_001064f0(s32);
    void func_00106550(s32, u32);
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
    *(Vec4 *)buf = *(Vec4 *)D_005E4700;
    value = func_001064f0(0x7C);
    end_date = (s32)datGetClearedWord() + 1;
    if ((datItemCount(0x4A0) & 0xFF) > 0) {
        buf[4] = 0x4A0;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A1;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A2;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A3;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A4) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A4;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A5) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A5;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A6) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A6;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A7) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A7;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A8) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A8;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4A9) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4A9;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AA) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AA;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AB) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AB;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AC) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AC;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AD) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AD;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AE) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AE;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4AF) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4AF;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B0) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B0;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B1) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B1;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B2) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B2;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x4B3) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x4B3;
        count = (count + 1) & 0xFF;
    }
    if ((datItemCount(0x418) & 0xFF) > 0) {
        buf[4 + (count & 0xFF)] = 0x418;
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
    buf[332 + i] = datGetFlag(i + 0x39);
    i++;
loop1_check:
    if (i < 7) {
        goto loop1;
    }
    result = 0;
    goto loop2_check;
loop2:
    {
        s32 *p = &buf[result];
        s32 v = *p;
        if (v == 0) {
            goto loop2_done;
        }
        buf[132 + result] = datGetFlag(v);
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
    ((s16 *)buf)[680 + i] = datGetCategoryValueById(1, (s16)i);
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
    datSetFlag(i + 0x39, buf[332 + i]);
    i++;
loop4_check:
    if (i < 7) {
        goto loop4;
    }
    i = 0;
    goto loop5_check;
loop5:
    {
        s32 *p = &buf[i];
        s32 v = *p;
        if (v == 0) {
            goto loop5_done;
        }
        datSetFlag(v, buf[132 + i]);
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
    datItemSetCount(((s16 *)buf)[8 + i * 2], 1);
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
    func_00106550(0x7C, (u32)value);
    func_00110470((u32)end_date);
    i = 0;
    goto loop7_check;
loop7:
    datSetCategoryValueById(1, (s16)i, ((s16 *)buf)[680 + i]);
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
void datEntryDrawRow(Vec2f arg0, f32 inputDepth, u8 arg1, u8 *inputEntry)
{
    f32 fparg0;
    u8 *arg2;
    u8 buf[256];
    s32 temp16;
    s32 temp19;
    union {
        s64 whole;
        f32 values[2];
        Vec2f position;
    } xy;
    f32 temp_1;
    s32 temp_2;
    
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

    fparg0 = inputDepth;
    arg2 = inputEntry;
    temp16 = resourceFindByName(D_005E5830);
    temp19 = resourceFindByName(D_005E5850);
    if (temp16 == 0) {
        kAssertFail(&iGpffff9be0, 0x93);
    }
    if (temp19 == 0) {
        kAssertFail(&iGpffff9be0, 0x94);
    }
    if (*(u16 *)(arg2 + 0x14) != 0) {
        datEntryDrawBadges(arg0, fparg0, arg1, arg2, temp16, temp19);
        arg0.x = arg0.x + 45.0f;
    }
    if (*(s32 *)(arg2 + 0xC) != 0) {
        temp19 = arg1 & 0xFF;
        temp_2 = (s32)datGetItemNameId(*(s16 *)arg2);
        frFontExDrawTextWithCharWidth(
            arg0.x,
            arg0.y,
            fparg0,
            temp19 | ~0xFF,
            *(s8 *)(&iGpffff9bd8 + *(s16 *)(arg2 + 0x16)),
            1,
            (const char *)temp_2,
            0,
            -1);
    }
    if (*(s32 *)(arg2 + 0x10) != 0) {
        xy.values[0] = arg0.x +
                       D_005E4790[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 9.0f;
        temp_1 += arg0.y;
        xy.values[1] = temp_1;
        datEntryDrawStatValue(xy.position, fparg0, arg1, arg2, temp16);
    }
    if (*(s16 *)(arg2 + 2) != -1) {
        xy.position.x = arg0.x +
                        D_005E4794[*(s16 *)(arg2 + 0x18) * 4];
        temp_1 = 12.0f;
        temp_1 += arg0.y;
        xy.position.y = temp_1;
        datEntryDrawCount(xy.position, fparg0, arg1, arg2, temp16);
    }
    if (*(s32 *)(arg2 + 8) != -1) {
        xy.values[0] = arg0.x +
                       D_005E479C[*(s16 *)(arg2 + 0x18) * 4];
        xy.values[1] = arg0.y;
        temp16 = ((arg1 & 0xFF) * 0xFF) / 255U;
        sprintf(buf, &iGpffff9be8,
                      datItemPrice(*(s16 *)arg2));
        frFontExDrawText(
            (f32)(s32)xy.values[0],
            (f32)(s32)xy.values[1],
            fparg0,
            temp16 | ~0xFF,
            *(s8 *)(&iGpffff9bd8 + *(s16 *)(arg2 + 0x16)),
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
void datEntryReset(u8 *arg0) {
    s32 temp_1;
    s32 temp_m1;

    temp_1 = 1;
    *(s16 *)(arg0 + 0) = temp_1;
    temp_m1 = -1;
    *(s16 *)(arg0 + 2) = temp_m1;
    *(s16 *)(arg0 + 6) = temp_m1;
    *(s32 *)(arg0 + 8) = temp_m1;
    *(s32 *)(arg0 + 0xC) = temp_1;
    *(s32 *)(arg0 + 0x10) = 0;
    temp_m1 = 3;
    *(s16 *)(arg0 + 0x14) = temp_m1;
    *(s16 *)(arg0 + 0x18) = 0;
    *(s16 *)(arg0 + 0x16) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw the entry's icons when the flag bits in the state word at 0x14 are set, using the colours from the two colour tables [inferred]
// FUN_00112610
void datEntryDrawBadges(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3, s32 arg4)
{
    typedef struct {
        u8 b[4];
    } Color4;
    extern u8 D_005E4710[];
    extern u8 D_005E4730[];
    void datEntryDrawFlagIcon(s64, f32, Color4, s16, s32, s32);
    Color4 color_a;
    Color4 color_b;
    Vec2f pos;
    s32 flags;
    s32 mode;
    s32 selected;
    u8 *table;
    s32 alpha;

    flags = datEntryGetFlags(*(s16 *)(arg2 + 0));
    if (*(u16 *)(arg2 + 0x14) & 2) {
        table = &D_005E4710[(*(s16 *)(arg2 + 0x16)) * 4];
        color_a = *(Color4 *)table;
        mode = -1;
        if (flags & 0x3FFF) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0xC000) {
            mode = 3;
            selected = arg3;
        } else if (flags & 0x10000) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0x20000) {
            mode = 2;
            selected = arg3;
        } else if (flags & 0x40000) {
            mode = 2;
            selected = arg3;
        }
        if (mode != -1) {
            alpha = 255;
            alpha -= arg1 & 0xFF;
            sdkSpriteDrawOnceTinted(0, selected, mode, arg0.x, arg0.y,
                          alpha & 0xFF,
                          color_a.b[0], color_a.b[1], color_a.b[2],
                          fparg0, 0);
        }
    }
    if (*(u16 *)(arg2 + 0x14) & 1) {
        table = &D_005E4730[(*(s16 *)(arg2 + 0x16)) * 4];
        color_b = *(Color4 *)table;
        color_b.b[3] = arg1;
        pos.x = arg0.x + 3.0f;
        pos.y = arg0.y + 2.0f;
        datEntryDrawFlagIcon(*(s64 *)&pos, fparg0, color_b,
                      *(s16 *)(arg2 + 0), arg3, arg4);
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
void datEntryDrawStatValue(Vec2f pos, f32 depth, u8 alpha, u8 *arg2, s32 tex)
{
    extern StatColor D_005E4750[];
    StatColor color;
    u16 value;
    s32 i;

    color = D_005E4750[*(s16 *)(arg2 + 0x16)];
    color.b[3] = alpha;
    switch (datIdBand(*(s16 *)arg2)) {
    case 0:
        value = func_001068b0(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_001068b0(*(s16 *)(arg2 + 6)), value, tex);
        }
        pos.x += 42.0f;
        value = func_001068e0(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_001068e0(*(s16 *)(arg2 + 6)), value, tex);
        }
        break;
    case 1:
        value = func_00106940(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_00106940(*(s16 *)(arg2 + 6)), value, tex);
        }
        pos.x += 42.0f;
        value = func_00106970(*(s16 *)arg2);
        func_00112830_number(pos, depth, value, color, tex);
        pos.x += 52.0f;
        if (*(s16 *)(arg2 + 6) != -1) {
            func_00112830_arrow(pos, depth, color,
                                func_00106970(*(s16 *)(arg2 + 6)), value, tex);
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
void datEntryDrawCount(Vec2f arg0, f32 fparg0, u8 arg1, u8 *arg2, s32 arg3)
{
    struct {
        s8 text[0x4C];
        FontGlyphColor color;
    } stack;
    s16 temp_21;
    u32 color2;
    u32 color1;
    s32 alpha_byte;
    s32 var_20;
    u8 loop_color2;
    u8 loop_color1;
    u8 *temp_2;
    extern u8 D_005E4770[];
    extern u8 D_005E4798[];
    extern s32 iGpffff9bec;
    extern s32 sprintf(void *, const void *, ...);
    extern s32 strlen(const void *);

    temp_21 = *(s16 *)(arg2 + 2);
    temp_2 = D_005E4770 + (*(s16 *)(arg2 + 0x16) * 4);
    stack.color = *(FontGlyphColor *)temp_2;
    alpha_byte = fontDrawLeadingGlyph(&arg0, fparg0, arg1, arg3,
        &stack.color, &color2, &color1);
    sprintf(stack.text, &iGpffff9bec, (s16)temp_21);
    arg0.x = arg0.x + (14.0f +
        *(f32 *)(D_005E4798 + (*(s16 *)(arg2 + 0x18) * 0x10)));
    var_20 = strlen(stack.text) - 1;
    loop_color2 = color2;
    loop_color1 = color1;
    while (var_20 >= 0) {
        sdkSpriteDrawOnceTinted(0, arg3, stack.text[var_20] - 0x27,
                      arg0.x, arg0.y, alpha_byte,
                      stack.color.r, loop_color1, loop_color2, fparg0, 0);
        arg0.x -= 14.0f;
        var_20--;
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
void datEntryDrawFlagIcon(Vec2f arg0, f32 fparg0, s32 arg1, s16 arg2, s32 arg3,
                   s32 arg4)
{
    f32 scale;
    s32 flags;
    s32 mode;
    s32 id;
    s32 alpha;

    scale = fparg0;
    flags = datEntryGetFlags(arg2);
    mode = -1;
    if (flags & 0x81) {
        mode = 0x14;
        id = arg3;
    } else if (flags & 0x102) {
        mode = 0x15;
        id = arg3;
    } else if (flags & 0x204) {
        mode = 0x16;
        id = arg3;
    } else if (flags & 0x408) {
        mode = 0x17;
        id = arg3;
    } else if (flags & 0x810) {
        mode = 0x18;
        id = arg3;
    } else if (flags & 0x1020) {
        mode = 0x19;
        id = arg3;
    } else if (flags & 0x2040) {
        mode = 0x1A;
        id = arg3;
    } else if (flags & 0x4000) {
        mode = 0x1B;
        id = arg3;
    } else if (flags & 0x8000) {
        mode = 0x1C;
        id = arg3;
    } else if (flags & 0x10000) {
        mode = 0x1B;
        id = arg4;
    } else if (flags & 0x20000) {
        mode = 0x1C;
        id = arg4;
    } else if (flags & 0x40000) {
        mode = 0x1A;
        id = arg4;
    }
    if (mode != -1) {
        alpha = 0xFF;
        alpha -= ((u8 *)&arg1)[3];
        sdkSpriteDrawOnceTinted(0, id, mode, arg0.x, arg0.y,
                      alpha & 0xFF,
                      ((u8 *)&arg1)[0], ((u8 *)&arg1)[1],
                      ((u8 *)&arg1)[2], scale, 0);
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
void datEntryDrawGatedByFlag39(s32 arg0, s32 arg1, s32 arg2, s32 arg3)
{
    if (datGetFlag(0x39) != 0) {
        sdkPadStartSequence(arg0, arg1, arg2, arg3);
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
s32 datPersonaFillSkillCostRow(s32 arg0, struct DatPersonaRecord *arg1, s32 arg2, u8 *arg3)
{
    s32 temp_3;
    u16 temp_2;
    u16 temp_5;

    *(u16 *)(arg3 + 2) = 0;
    *(s32 *)(arg3 + 4) = 0;
    *(s32 *)(arg3 + 8) = 0;
    temp_2 = *(u16 *)(p4_00113520_add(arg2 * 2, (s32)arg1) + 0xC);
    if (temp_2 != 0) {
        *(u16 *)(arg3 + 2) = temp_2;
        if (arg0 != 0) {
            temp_5 = *(u16 *)(arg3 + 2);
            if ((s32)temp_5 < 0x1B8) {
                temp_3 = datCalcThresholdKindById((s16)arg0, temp_5) & 0xFFFF;
                switch (temp_3) {
                case 1:
                    *(s32 *)(arg3 + 4) = datCalcSkillCostById((s16)arg0, *(u16 *)(arg3 + 2));
                    break;
                case 2:
                    *(s32 *)(arg3 + 8) = datCalcSkillCostById((s16)arg0, *(u16 *)(arg3 + 2));
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
void datPersonaFillSkillRows(s32 arg0, u8 *arg1)
{
    u16 sp70[32];
    u16 sp30[32];
    u8 *table;
    u8 *entry;
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
        entry = arg1 + index;
        *(s32 *)(entry + 4) = 0;
        *(s32 *)(entry + 8) = 0;
        value = *(u16 *)(table + ((s32)i * 2));
        if (value == 0) {
            break;
        }
        *(u16 *)(entry + 2) = value;
        i++;
    }
    *(s16 *)(arg1 + 0x60) = i;
    count = (s16)datPersonaCollectLearnableSkills((u8 *)(u32)arg0, sp70, sp30);
    j = 0;
    while (j < count) {
        index = (s32)j * 0xC;
        entry = arg1 + index;
        *(s32 *)(entry + 0x68) = 0;
        *(s32 *)(entry + 0x6C) = 0;
        *(u16 *)(entry + 0x66) = sp70[(s32)j];
        *(u16 *)(arg1 + ((s32)j * 2) + 0x1E4) = sp30[(s32)j];
        j++;
    }
    *(s16 *)(arg1 + 0x224) = count;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Clear the first three halfwords of a record [inferred]
// FUN_00113730
void datRecordClearHeader(s16 *arg0) {
    arg0[0] = 0;
    arg0[1] = 0;
    arg0[2] = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Reset a record: zero the two halfword counters, set the two indices at +4 and +5 to -1, and clear the 0x22C bytes from +8 [inferred]
// FUN_00113750
void datRecordResetAll(u8 *arg0) {
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 2) = 0;
    *(s8 *)(arg0 + 4) = -1;
    *(s8 *)(arg0 + 5) = -1;
    memset(arg0 + 8, 0, 0x22C);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw an entry by its kind: kind 0 draws the id name, kind 1 the skill descriptor, kind 2 the skill entry name [inferred]
// FUN_00113790
void datEntryDrawByKind(Vec2f arg0, u8 arg1, void *arg2, s32 arg3, f32 arg4)
{
    s16 temp_8;

    temp_8 = *(s16 *)arg2;
    switch (temp_8) {
    case 0:
        datEntryDrawIdName(arg0, arg4, arg1, arg2, arg3);
        return;
    case 1:
        ShdSkill_DrawDescriptor(arg0, arg4, arg1, arg2, arg3);
        return;
    case 2:
        ShdSkill_DrawEntryName(arg0, arg4, arg1, arg2, arg3);
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
void datEntryDrawIdName(Vec2f arg0, f32 arg4, u8 arg1, void *arg2, s32 arg3)
{
    f32 scale;
    s32 color;
    char index;
    void *temp;

    scale = arg4;

    temp = datCalcGetIdRecord(*(u16 *)((u8 *)arg2 + 0xA));
    color = -0x100 | (((arg1 & 0xFF) * 0xFF) / 255U);
    index = *(char *)((s32)D_005E47F0 + (*(s16 *)((u8 *)arg2 + 2) * 2));
    frFontExDrawText((f32)(s32)arg0.x, (f32)(s32)arg0.y, scale, color, index, 1, temp, 0, 0);
}
#pragma pop

#include "byte_address_internal.h"
#include "include_asm.h"
#include "type.h"
#include "member_access.h"
#include "fr_font_internal.h"
#include "shd_skill_internal.h"
typedef struct {
    f32 x;
    f32 y;
} Vec2f;
typedef struct {
    u8 b0;
    u8 b1;
    u8 b2;
    u8 b3;
} Color4;


u16 ShdSkill_GetPendingSkill(u8 *pool);
void kAssertFail(void *file, s32 line);
void ShdSkill_RemovePoolEntry(u8 *pool, s32 index, s32 unusedCount, s32 unusedSkill);
s32 datCalcSkillElement(u8 *unit, u16 skillId);
extern char D_005E4800[];
extern char D_005E47F0[];
u8 *func_00243840(s32);

void sdkSpriteDrawOnceTinted(s32 parent, s32 packAddress, s32 recordIndex, f32 x, f32 y, u8 alphaSubtract, u8 red, u8 green, u8 blue, f32 z, s32 setStates);
extern char D_005E5830[];
extern char D_005E5850[];
void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 depth, s32 color, s32 font, s32 mode, s32 item);
u8 *resourceFindByName(char *name);
void ShdSkill_DrawDescriptor(Vec2f position, f32 scale, u8 alpha, void *descriptor, s32 mode);
void ShdSkill_DrawIcon(Vec2f position, f32 scale, Color4 color, u16 skill, s32 texture);

/* Flag, ID and style are re-read after each draw callback, and costs are sampled after the text
 * call. */
// FUN_001138C0
void ShdSkill_DrawDescriptor(Vec2f position, f32 scale, u8 alpha, void *descriptor, s32 mode)
{
    typedef ShdSkillVector PayloadVector;
    typedef union {
        PayloadVector vector;
        struct { u16 tag, id; u32 first, second; } fields;
    } Payload;
    typedef struct { s16 kind, style, flags; Payload data; } Descriptor;
    Descriptor *data = descriptor;
    u8 *texture;
    u8 *helpTexture;
    u8 numberRed, numberGreen, numberBlue;
    u8 unitRed, unitGreen, unitBlue;
    u8 backgroundRed, backgroundGreen, backgroundBlue;
    Color4 iconColor;
    Vec2f iconPosition;
    u32 textAlpha;
    void *text;
    f32 baseY;
    f32 digitY;
    f32 digitX;
    s32 firstCost;
    s32 secondCost;
    s32 index;

    texture = resourceFindByName(D_005E5830);
    if (texture == 0) {
        kAssertFail(D_005E4800, 0xE4);
    }
    helpTexture = resourceFindByName(D_005E5850);
    if (helpTexture == 0) {
        kAssertFail(D_005E4800, 0xE6);
    }
    switch (data->style) {
    case 2:
        numberRed = 236;
        numberGreen = 124;
        numberBlue = 0;
        unitRed = 236;
        unitGreen = 156;
        unitBlue = 0;
        backgroundRed = 255;
        backgroundGreen = 255;
        backgroundBlue = 129;
        break;
    case 3:
        numberRed = 255;
        numberGreen = 255;
        numberBlue = 255;
        unitRed = 176;
        unitGreen = 176;
        unitBlue = 176;
        backgroundRed = 45;
        backgroundGreen = 45;
        backgroundBlue = 45;
        break;
    case 4:
        numberRed = 45;
        numberGreen = 45;
        numberBlue = 45;
        unitRed = 189;
        unitGreen = 96;
        unitBlue = 0;
        backgroundRed = 236;
        backgroundGreen = 124;
        backgroundBlue = 0;
        break;
    default:
        numberRed = 255;
        numberGreen = 255;
        numberBlue = 255;
        unitRed = 255;
        unitGreen = 255;
        unitBlue = 255;
        backgroundRed = 45;
        backgroundGreen = 45;
        backgroundBlue = 45;
        break;
    }
    if (data->flags != 0) {
        if (data->flags & 2) {
            sdkSpriteDrawOnceTinted(0, (s32)texture, 2, position.x, position.y,
                          (255 - alpha) & 0xFF,
                          backgroundRed, backgroundGreen, backgroundBlue, scale, 0);
        }
        if (data->flags & 1) {
            iconPosition.x = 3.0f + position.x;
            iconPosition.y = 2.0f + position.y;
            iconColor.b0 = numberRed;
            iconColor.b1 = numberGreen;
            iconColor.b2 = numberBlue;
            iconColor.b3 = alpha;
            ShdSkill_DrawIcon(iconPosition, scale, iconColor, data->data.fields.id, (s32)helpTexture);
        }
        position.x += 45.0f;
    }
    text = func_00243840(data->data.fields.id);
    textAlpha = alpha & 0xFF;
    baseY = position.y;
    frFontExDrawTextWithCharWidth((f32)(s32)position.x, (f32)(s32)baseY, scale,
                  ((textAlpha * 255) / 255U) | ~0xFF,
                  D_005E47F0[data->style * 2], 1, text, 0, -1);
    digitX = 250.0f + position.x;
    digitY = 10.0f + baseY;
    firstCost = (s32)data->data.fields.first;
    if (firstCost != 0) {
        s32 inverseAlpha = 255 - textAlpha;
        while (firstCost > 0) {
            sdkSpriteDrawOnceTinted(0, (s32)texture, firstCost % 10 + 9, digitX, digitY,
                          inverseAlpha & 0xFF, numberRed, numberGreen, numberBlue, scale, 0);
            firstCost /= 10;
            digitX -= 16.0f;
        }
        sdkSpriteDrawOnceTinted(0, (s32)texture, 86, 268.0f + position.x, 11.0f + baseY,
                      inverseAlpha, unitRed, unitGreen, unitBlue, scale, 0);
    } else {
        secondCost = (s32)data->data.fields.second;
        if (secondCost != 0) {
            s32 inverseAlpha = 255 - textAlpha;
            while (secondCost > 0) {
                sdkSpriteDrawOnceTinted(0, (s32)texture, secondCost % 10 + 9, digitX, digitY,
                              inverseAlpha & 0xFF, numberRed, numberGreen, numberBlue, scale, 0);
                secondCost /= 10;
                digitX -= 16.0f;
            }
            sdkSpriteDrawOnceTinted(0, (s32)texture, 87, 268.0f + position.x, 11.0f + baseY,
                          inverseAlpha, unitRed, unitGreen, unitBlue, scale, 0);
        } else {
            f32 dashY;
            s32 inverseAlpha;
            digitX = 223.0f + position.x;
            dashY = 11.0f + baseY;
            index = 0;
            inverseAlpha = 255 - textAlpha;
            while (index < 4) {
                sdkSpriteDrawOnceTinted(0, (s32)texture, 60, digitX, dashY,
                              inverseAlpha & 0xFF, unitRed, unitGreen, unitBlue, scale, 0);
                digitX += 20.0f;
                index++;
            }
        }
    }
}

/* Draw a skill entry's name at position, using the descriptor's style for the font and alpha for
 * transparency. */
// FUN_00113E30
void ShdSkill_DrawEntryName(Vec2f position, f32 scale, u8 alpha, void *descriptor, s32 unusedMode) {
    f32 depth;
    s32 color;
    s32 index;
    void *text;

    depth = scale;
    text = func_00243840(((ShdSkillDescriptor *)descriptor)->data.fields.id);
    color = (((alpha & 0xFF) * 0xFF) / 255U) | ~0xFF;
    index = *((s8 *)((s32)&D_005E47F0 + (((ShdSkillDescriptor *)descriptor)->style * 2)));
    frFontExDrawTextWithCharWidth((f32)(s32)position.x,
                  (f32)(s32)position.y,
                  depth,
                  color,
                  index,
                  1,
                  text,
                  8,
                  -1);
}

/* The caller draws entries 0..7; the font lookup uses a plain char index. */
// FUN_00113EF0
/* measured: retail output needs both propagation and scalarization disabled; either alone differs. */
#pragma push
#pragma opt_propagation off
#pragma opt_scalarize off
void ShdSkill_DrawListSlot(Vec2f base, f32 scale, u8 alpha, u8 *state, u8 entry, f32 fade)
{
    typedef ShdSkillVector PayloadVector;
    typedef union {
        PayloadVector vector;
        struct { u16 tag, id; u32 first, second; } fields;
    } Payload;
    typedef struct { s16 kind, style, flags; Payload data; } Descriptor;
    Descriptor descriptor;
    Vec2f position;
    f32 baseY;
    f32 drawY;
    s32 selected;
    u8 *texture;
    s32 opacity;
    s32 inverseAlpha;
    u32 textAlpha;
    u32 index;
    u8 red, green, blue;
    s16 style;

    baseY = base.y;
    selected = entry & 0xFF;
    if (selected < 0 || selected >= 8) {
        kAssertFail(D_005E4800, 0x1E1);
    }
    texture = resourceFindByName(D_005E5830);
    if (texture == 0) {
        kAssertFail(D_005E4800, 0x1E4);
    }
    if (((ShdSkillState *)state)->cursor == selected) {
        red = 45;
        green = 45;
        blue = 45;
        style = 3;
    } else if (!(fade <= 0.0f)) {
        red = (u8)(255.0f * (1.0f - fade) + 45.0f * fade);
        green = (u8)(255.0f * (1.0f - fade) + 45.0f * fade);
        blue = (u8)(129.0f * (1.0f - fade) + 45.0f * fade);
        style = 3;
    } else if (((ShdSkillState *)state)->pool.markedSlots & (1U << selected)) {
        red = 192;
        green = 0;
        blue = 0;
        style = 3;
    } else {
        red = 255;
        green = 255;
        blue = 129;
        style = 2;
    }
    opacity = alpha & 0xFF;
    textAlpha = (u32)(opacity * 255) / 255U;
    descriptor.style = 0;
    descriptor.flags = 0;
    descriptor.kind = 2;
    index = entry;
    descriptor.data.vector = MEMBER(PayloadVector, byteAddressAdd((index * 12), state), ShdSkillState, pool.active[0].vector);
    descriptor.style = style;
    position.x = 18.0f + (base.x + (f32)((s32)(index >> 2) * 198));
    drawY = 304.0f + (baseY + (f32)(((s32)index % 4) * 25));
    position.y = drawY;
    inverseAlpha = 255 - opacity;
    sdkSpriteDrawOnceTinted(0, (s32)texture, 90, position.x, drawY, inverseAlpha & 0xFF,
                  red, green, blue, scale, 0);
    sdkSpriteDrawOnceTinted(0, (s32)texture, 91, 192.0f + position.x, drawY, inverseAlpha,
                  red, green, blue, scale, 0);
    if ((s32)index < ((ShdSkillState *)state)->pool.activeCount) {
        position.x += 96.0f;
        position.y -= 2.0f;
        switch (descriptor.kind) {
        case 0: {
            Vec2f textPosition = position;
            const char *text = (const char *)func_00243840(descriptor.data.fields.id);
            frFontExDrawText((f32)(s32)textPosition.x, (f32)(s32)textPosition.y, scale,
                          textAlpha | ~0xFF, ((char *)D_005E47F0)[descriptor.style * 2],
                          1, text, 0, 0);
            break;
        }
        case 1:
            ShdSkill_DrawDescriptor(position, scale, alpha, &descriptor, 1);
            break;
        case 2: {
            Vec2f textPosition = position;
            const char *text = (const char *)func_00243840(descriptor.data.fields.id);
            frFontExDrawTextWithCharWidth((f32)(s32)textPosition.x, (f32)(s32)textPosition.y, scale,
                          textAlpha | ~0xFF, ((char *)D_005E47F0)[descriptor.style * 2],
                          1, text, 8, -1);
            break;
        }
        }
    }
}
#pragma pop

/* Draws the skill detail frame, digit counter and pending-skill markers. Compound u16 narrowing and
 * local declaration order keep digit/label lifetimes across sprite submissions. */
// FUN_00114460
/* measured: retail output needs both propagation and scalarization disabled; either alone differs. */
#pragma push
#pragma opt_propagation off
#pragma opt_scalarize off
void ShdSkill_DrawDetailFrame(Vec2f base, f32 scale, u8 alpha, u8 *state, f32 fade)
{
    typedef ShdSkillVector PayloadVector;
    typedef union {
        PayloadVector vector;
        struct { u16 tag, id; u32 first, second; } fields;
    } Payload;
    typedef struct { s16 kind, style, flags; Payload data; } Descriptor;
    extern char D_005E5810[];
    extern f32 fGpffff8368;
    Descriptor descriptor;
    Vec2f position;
    u8 *panelTexture;
    u16 number;
    u8 *frameTexture;
    u8 *helpTexture;
    f32 baseY;
    f32 nameX;
    f32 nameY;
    f32 firstColumn;
    f32 starsY;
    u8 red, green, blue;
    s16 style;
    u8 drawAlpha;
    s32 inverseAlpha;
    s32 alphaWord;
    s32 color;
    s32 index;

    baseY = base.y;
    panelTexture = resourceFindByName(D_005E5830);
    if (panelTexture == 0) {
        kAssertFail(D_005E4800, 0x243);
    }
    descriptor.style = 2;
    frameTexture = resourceFindByName(D_005E5810);
    if (frameTexture == 0) {
        kAssertFail(D_005E4800, 0x247);
    }
    helpTexture = resourceFindByName(D_005E5850);
    if (helpTexture == 0) {
        kAssertFail(D_005E4800, 0x249);
    }
    if (((ShdSkillState *)state)->pool.pendingCount != 0) {
        if (((ShdSkillState *)state)->cursor == 8) {
            red = 45;
            green = 45;
            blue = 45;
            style = 3;
        } else if (!(fade <= 0.0f)) {
            red = (u8)(255.0f * (1.0f - fade) + 45.0f * fade);
            green = (u8)(255.0f * (1.0f - fade) + 45.0f * fade);
            blue = (u8)(129.0f * (1.0f - fade) + 45.0f * fade);
            style = 3;
        } else {
            red = 255;
            green = 255;
            blue = 129;
            style = 2;
        }
        drawAlpha = alpha;
        firstColumn = (f32)417 + base.x;
        position.x = firstColumn;
        position.y = 304.0f + baseY;
        inverseAlpha = 255 - drawAlpha;
        sdkSpriteDrawOnceTinted(0, (s32)frameTexture, 58, firstColumn, position.y, inverseAlpha & 0xFF,
                      255, 162, 0, scale, 0);
        sdkSpriteDrawOnceTinted(0, (s32)frameTexture, 59, 192.0f + position.x, position.y, inverseAlpha,
                      255, 162, 0, scale, 0);
        position.x = 422.0f + base.x;
        position.y = 310.0f + baseY;
        sdkSpriteDrawOnceTinted(0, (s32)frameTexture, 60, position.x, position.y, inverseAlpha,
                      255, 255, 129, scale, 0);
        sdkSpriteDrawOnceTinted(0, (s32)helpTexture, 42, 76.0f + position.x, 4.0f + position.y, inverseAlpha,
                      255, 255, 129, scale, 0);
        number = ((ShdSkillState *)state)->pool.values[0];
        if ((s32)number < 10) {
            position.x = (f32)538 + base.x;
        } else {
            position.x = (f32)550 + base.x;
        }
        position.y = 306.0f + baseY;
        do {
            sdkSpriteDrawOnceTinted(0, (s32)helpTexture, (s32)number % 10 + 29, position.x, position.y,
                          inverseAlpha, 255, 255, 129, scale, 0);
            number /= 10U;
            position.x -= 22.0f;
        } while ((s32)number > 0);
        position.x = (f32)421 + base.x;
        position.y = (f32)327 + baseY;
        alphaWord = alpha;
        inverseAlpha = 255 - alphaWord;
        sdkSpriteDrawOnceTinted(0, (s32)panelTexture, 92, position.x, position.y, inverseAlpha & 0xFF,
                      red, green, blue, scale, 0);
        sdkSpriteDrawOnceTinted(0, (s32)panelTexture, 93, 182.0f + position.x, position.y, inverseAlpha,
                      red, green, blue, scale, 0);
        index = 0;
        nameX = fGpffff8368 + base.x;
        nameY = (f32)325 + baseY;
        color = ((u32)(alphaWord * 255) / 255U) | ~0xFF;
        starsY = 354.0f + baseY;
        while (index < MEMBER(u16, state, ShdSkillState, pool.pendingCount)) {
            if (index == 0) {
                position.x = nameX;
                position.y = nameY;
                descriptor.data.vector = ((ShdSkillState *)state)->pool.pending[index].vector;
                descriptor.kind = 2;
                descriptor.style = style;
                switch (descriptor.kind) {
                case 0: {
                    Vec2f textPosition = position;
                    const char *text = (const char *)func_00243840(descriptor.data.fields.id);
                    frFontExDrawText((f32)(s32)textPosition.x, (f32)(s32)textPosition.y, scale,
                                  color, ((char *)D_005E47F0)[descriptor.style * 2], 1, text, 0, 0);
                    break;
                }
                case 1:
                    ShdSkill_DrawDescriptor(position, scale, drawAlpha, &descriptor, 1);
                    break;
                case 2: {
                    Vec2f textPosition = position;
                    const char *text = (const char *)func_00243840(descriptor.data.fields.id);
                    frFontExDrawTextWithCharWidth((f32)(s32)textPosition.x, (f32)(s32)textPosition.y, scale,
                                  color, ((char *)D_005E47F0)[descriptor.style * 2], 1, text, 8, -1);
                    break;
                }
                }
            } else if (index < 7) {
                position.x = firstColumn + (f32)((index - 1) * 33);
                position.y = starsY;
                sdkSpriteDrawOnceTinted(0, (s32)frameTexture, 69, position.x, starsY, inverseAlpha,
                              255, 162, 0, scale, 0);
                position.x += 5.0f;
                position.y += 3.0f;
                sdkSpriteDrawOnceTinted(0, (s32)frameTexture, 70, position.x, position.y, inverseAlpha,
                              255, 255, 129, scale, 0);
            }
            index++;
        }
    }
}
#pragma pop

/* Map the skill element to its icon; invalid skills use the fallback icon. */
// FUN_00114CB0
s32 ShdSkill_GetIconId(u16 skill) {
    s16 element;

    if ((skill & 0xFFFF) >= 0x1B8) {
        return 0xC2;
    }
    element = (s16)datCalcSkillElement(0, skill);
    switch (element) {
    case 0:
        return 0xB8;
    case 1:
        return 0xB9;
    case 2:
        return 0xBA;
    case 3:
        return 0xBB;
    case 4:
        return 0xBC;
    case 5:
        return 0xBD;
    case 6:
        return 0xBE;
    case 7:
        return 0xBF;
    case 8:
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 14:
    case 15:
    case 16:
    case 17:
    case 18:
        return 0xC0;
    case -1:
        return -1;
    default:
        kAssertFail(D_005E4800, 0x32E);
        return 0;
    }
}

/* Draw the skill element icon when its lookup returns a positive sprite ID. */
// FUN_00114DC0
void ShdSkill_DrawIcon(Vec2f position, f32 scale, Color4 color, u16 skill, s32 texture) {
    s32 icon;

    icon = ShdSkill_GetIconId(skill);
    if (icon > 0) {
        sdkSpriteDrawOnceTinted(0,
                      texture,
                      icon,
                      position.x,
                      position.y,
                      (0xFF - color.b3) & 0xFF,
                      color.b0,
                      color.b1,
                      color.b2,
                      scale,
                      0);
    }
}
/* Draw the selection borders and optional message for the selected skill. */
// FUN_00114E50
void ShdSkill_DrawSelectionFrame(Vec2f position, f32 scale, u8 alpha, u16 messageId) {
    s32 inverseAlpha;
    s32 opacity;
    s32 texture;
    f32 x;
    f32 y;
    s32 message;

    texture = (s32)resourceFindByName(D_005E5850);
    if (texture == 0) {
        kAssertFail(D_005E4800, 0x353);
    }
    x = 1.0f + position.x;
    y = position.y - 1.0f;
    opacity = alpha;
    inverseAlpha = 0xFF - opacity;
    sdkSpriteDrawOnceTinted(0, texture, 0x61, x, y, inverseAlpha & 0xFF, 0x2D, 0x2D, 0x2D, scale, 0);
    x = 393.0f + position.x;
    y = position.y - 1.0f;
    inverseAlpha = 0xFF - opacity;
    sdkSpriteDrawOnceTinted(0, texture, 0x60, x, y, inverseAlpha & 0xFF, 0x2D, 0x2D, 0x2D, scale, 0);
    x = position.x - 1.0f;
    y = position.y;
    inverseAlpha = 0xFF - opacity;
    sdkSpriteDrawOnceTinted(0, texture, 0x17, x, y, inverseAlpha & 0xFF, 0xFF, 0xA0, 0x0B, scale, 0);
    message = messageId;
    if (message != 0) {
        x = 62.0f + position.x;
        y = 22.0f + position.y;
        itfMesWindowDrawDefaultEntry((f32)(s32)x, (f32)(s32)y, scale, opacity | ~0xFF, 1, 8, message);
    }
}

/* Move between two four-row columns and the optional pending-skill slot; signed remainder keeps
 * negative byte-index behavior. */
// FUN_00115020
s32 ShdSkill_MoveCursor(u8 *state, s32 force) {
    extern u16 D_008C027A[];
    s8 current;
    s8 next;
    s8 previous;
    s32 active;
    u16 count;
    s32 column;

    current = ((ShdSkillState *)state)->cursor;
    next = current;
    previous = ((ShdSkillState *)state)->previousCursor;
    count = ((ShdSkillState *)state)->pool.pendingCount;
    active = force != 0;
    active = active == 0 ? (count > 0) : active;
    if (D_008C027A[0] & 0x1000) {
        if (current < 4) {
            column = (current + 3) % 4;
            next = (s8)column;
        } else if (current < 8) {
            column = (current + 3) % 4;
            next = (s8)(column + 4);
        }
    } else if (D_008C027A[0] & 0x4000) {
        if (current < 4) {
            column = (current + 1) % 4;
            next = (s8)column;
        } else if (current < 8) {
            column = (current + 1) % 4;
            next = (s8)(column + 4);
        }
    } else if (D_008C027A[0] & 0x8000) {
        if (current < 4) {
            if (active != 0) {
                next = 8;
            } else {
                next = (s8)(current + 4);
            }
        } else if (current < 8) {
            next = (s8)(current - 4);
        } else {
            column = previous % 4;
            next = (s8)(column + 4);
        }
    } else if (D_008C027A[0] & 0x2000) {
        if (current < 4) {
            next = (s8)(current + 4);
        } else if ((current < 8) && (active != 0)) {
            next = 8;
        } else {
            column = previous % 4;
            next = (s8)column;
        }
    }
    if (next != current) {
        MEMBER(s8, state, ShdSkillState, previousCursor) = current;
        MEMBER(s8, state, ShdSkillState, cursor) = next;
        return 1;
    }
    return 0;
}

/* Return the selected active or first pending skill; empty active slots return zero. */
// FUN_001152B0
u16 ShdSkill_GetSlotSkillId(u8 *state) {
    s8 cursor;
    s32 byteOffset;
    u16 skill;

    cursor = ((ShdSkillState *)state)->cursor;
    if ((cursor < 0) || (cursor > 8)) {
        kAssertFail(D_005E4800, 0x447);
    }
    if (cursor < 8) {
        if (cursor < (s32) ((ShdSkillState *)state)->pool.activeCount) {
            byteOffset = cursor * 12;
            skill = ((ShdSkillEntry *)(byteOffset + (s32)state + 8))->fields.id;
        } else {
            skill = 0;
        }
    } else {
        if ((cursor - 8) >= (s32) ((ShdSkillState *)state)->pool.pendingCount) {
            kAssertFail(D_005E4800, 0x453);
        }
        skill = ((ShdSkillState *)state)->pool.pending[0].fields.id;
    }
    return skill;
}


/* Find an active skill, or return slot 8 for the first pending skill. */
// FUN_00115380
s16 ShdSkill_FindSlot(u8 *pool, s32 skill) {
    s16 i;
    s32 target;
    s32 count;

    i = 0;
    target = skill & 0xFFFF;
    count = ((ShdSkillPool *)pool)->activeCount;
    for (; i < count; i++) {
        if (target == ((ShdSkillPool *)pool)->active[i].fields.id) {
            return i;
        }
    }
    if (target == (ShdSkill_GetPendingSkill(pool) & 0xFFFF)) {
        return 8;
    }
    return -1;
}

/* Append a skill to the eight active rows and remove its pending-pool entry. */

// FUN_00115420
void ShdSkill_AddActiveSkill(u16 skill, u8 *pool) {
    s32 target;
    s32 value;
    s32 i;
    s32 bound;
    u16 count;

    if (((ShdSkillPool *)pool)->activeCount >= 8) {
        kAssertFail(D_005E4800, 0x472);
    }
    count = ((ShdSkillPool *)pool)->activeCount;
    ((ShdSkillPool *)pool)->activeCount = count + 1;
    ((ShdSkillEntry *)byteAddressAdd((count * 12), pool))->fields.id = (s16)skill;
    i = 0;
    target = skill & 0xFFFF;
    bound = ((ShdSkillPool *)pool)->pendingCount;
    goto loop_test;
loop_body:
    value = ((ShdSkillPool *)pool)->pending[(s16)i].fields.id;
    if (value == target) {
        ShdSkill_RemovePoolEntry(pool, i, bound, target);
        return;
    }
    i = (s16)(i + 1);
loop_test:
    if ((s16)i < bound) {
        goto loop_body;
    }
}

/* measured: retail sign-extends the loop counter at the call, so the counter is a local s16 and
 * ShdSkill_RemovePoolEntry gets a block-scope s16 prototype. */
/* Replace oldSkill with newSkill in the active skill list, then remove newSkill from the pending
 * pool. */
// FUN_00115500
void ShdSkill_ReplaceActiveSkill(u16 oldSkill, u16 newSkill, u8 *pool) {
    extern void ShdSkill_RemovePoolEntry(u8 *, s16, s32, s32);
    s32 target;
    s16 i;
    s16 index;
    s32 value;
    s32 bound;
    i = 0;
    target = oldSkill & 0xFFFF;
    bound = ((ShdSkillPool *)pool)->activeCount;
    goto first_test;
first_body:
    if (target == ((ShdSkillPool *)pool)->active[i].fields.id) {
        index = i;
        goto index_done;
    }
    i++;
first_test:
    if (i < bound) {
        goto first_body;
    }
    if (target == (ShdSkill_GetPendingSkill(pool) & 0xFFFF)) {
        index = 8;
    } else {
        index = -1;
    }
index_done:
    if ((index == -1) || (index >= (s32)MEMBER(u16, pool, ShdSkillPool, activeCount))) {
        kAssertFail(D_005E4800, 0x4A1);
    }
    ((ShdSkillEntry *)byteAddressAdd((index * 12), pool))->fields.id = newSkill;
    {
        s16 j;
        j = 0;
        target = newSkill & 0xFFFF;
        bound = ((ShdSkillPool *)pool)->pendingCount;
        goto second_test;
second_body:
        value = ((ShdSkillPool *)pool)->pending[j].fields.id;
        if (value != target) {
            goto second_continue;
        }
        ShdSkill_RemovePoolEntry(pool, j, bound, target);
        return;
second_continue:
        j++;
second_test:
        if (j < bound) {
            goto second_body;
        }
    }
}

/* Discard the first pending row and compact the parallel row/value arrays; tail clearing uses end-
 * relative integer cursors for the last row and value. */
// FUN_00115760
void ShdSkill_PopPoolEntry(u8 *pool) {
    typedef ShdSkillVector S3f;


    s32 i;
    s32 offset;
    s32 address;

    if (((ShdSkillPool *)pool)->pendingCount <= 0) {
        kAssertFail(D_005E4800, 0x4B7);
    }
    for (i = 0; i < MEMBER(u16, pool, ShdSkillPool, pendingCount) - 1; i++) {
        ((ShdSkillPool *)pool)->pending[i].vector = ((ShdSkillPool *)pool)->pending[i + 1].vector;
        ((ShdSkillPool *)pool)->values[i] = ((ShdSkillPool *)pool)->values[i + 1];
    }
    offset = MEMBER(u16, pool, ShdSkillPool, pendingCount) * 12;
    address = offset + (s32)pool;
    ((ShdSkillEntry *)(address + 0x58))->fields.id = 0;
    offset = MEMBER(u16, pool, ShdSkillPool, pendingCount) * 2;
    address = offset + (s32)pool;
    /* The integer cursor is one halfword beyond the last parallel value. */
    *(u16 *)(address + MEMBER_OFFSET(ShdSkillPool, values) - (s32)sizeof(u16)) = 0;
    MEMBER(u16, pool, ShdSkillPool, pendingCount) -= 1;
}

/* The input local is set before the guard and the loop counter after it, so the entry branch
 * targets the loop pre-jump as in retail. Remove a pending row at index and compact the row and
 * parallel halfword arrays. Tail clearing also uses end-relative integer cursors for the last row
 * and parallel value. */
// FUN_00115670
void ShdSkill_RemovePoolEntry(u8 *pool, s32 index, s32 unusedCount, s32 unusedSkill) {
    typedef ShdSkillVector S3f;


    s32 i;
    s32 input;
    u16 count;
    u8 *entryCursor;
    u8 *valueCursor;

    input = (s64)(s16)index;
    if (input < (s32)((ShdSkillPool *)pool)->pendingCount) {
        goto loop_entry_15670;
    }
    kAssertFail(D_005E4800, 0x4B7);
loop_entry_15670:
    i = input;
    goto loop_test_15670;
loop_body_15670:
    entryCursor = (u8 *)(pool + i * 12);
    ((ShdSkillPool *)entryCursor)->pending[0].vector = ((ShdSkillPool *)entryCursor)->pending[1].vector;
    valueCursor = (u8 *)(pool + i * 2);
    ((ShdSkillPool *)valueCursor)->values[0] = ((ShdSkillPool *)valueCursor)->values[1];
    i += 1;
loop_test_15670:
    count = MEMBER(u16, pool, ShdSkillPool, pendingCount);
    if (i < (s32)(count - 1)) {
        goto loop_body_15670;
    }
    entryCursor = byteAddressAdd((count * 12), pool);
    ((ShdSkillEntry *)(entryCursor + 0x58))->fields.id = 0;
    entryCursor = byteAddressAdd((((ShdSkillPool *)pool)->pendingCount * 2), pool);
    /* The integer cursor is one halfword beyond the last parallel value. */
    *(u16 *)(entryCursor + MEMBER_OFFSET(ShdSkillPool, values) - (s32)sizeof(u16)) = 0;
    ((ShdSkillPool *)pool)->pendingCount = ((ShdSkillPool *)pool)->pendingCount - 1;
}

// FUN_00115750
u16 ShdSkill_GetPendingSkill(u8 *pool) {
    return ((ShdSkillPool *)pool)->pending[0].fields.id;
}


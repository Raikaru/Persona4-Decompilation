#include "include_asm.h"
#include "type.h"
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
static inline u8 *shdSkill_addOff(s32 offset, u8 *base) {
    return (u8 *)(offset + (s32)base);
}

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
u8 *resourceFindByName(char *file);
void ShdSkill_DrawDescriptor(Vec2f position, f32 scale, u8 alpha, void *descriptor, s32 mode);
void ShdSkill_DrawIcon(Vec2f position, f32 scale, Color4 color, u16 skill, s32 texture);

/* 1384/1392 bytes, 23 resolved relocations; eight zero tail bytes.
   Preserve live flag, ID, and style reads across draw callbacks and sample
   costs after the text call. Keep the dash row's Y lifetime separate. */
// FUN_001138C0
#pragma push
#pragma opt_propagation off
#pragma opt_scalarize off
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
#pragma pop

/* measured: re-confirmed nd 5 this wave (reloc-masked; probe_variants reports
   11 unmasked) with the m2c-faithful 9-arg 275020 spelling -- the only
   residual is (a) prologue save order: retail `sd $a0,0x48; mov.s $f20,$f12;
   move $s1,$a1; move $s0,$a2`, mwcc groups `[GPR callee-saves, FP
   callee-saves, spills]` = `move $s1; move $s0; mov.s $f20; sd $a0` (same
   grouping floor as ShdSkill_DrawIcon), and (b) `mov.s $f14,$f20` deferred past
   the a2/a3/t0/t1 setup (retail emits it right after the lb $a1). Everything
   else byte-identical (243840 nested call, cvt pairs into f12/f13, the
   x*255/255U divu + |~0xFF chain, lh->sll->D_005E47F0 byte index). Probed
   this wave: z/depthSnapshot assignment orders, arg1/arg2 locals, lo/hi locals -- all
   nd 5/11. prologue/FP-arg save-order floor. */
/* measured: MATCH, object 184/192. The cluster's float-first interleaving and callee-first local evaluation reproduce the retail body; the remaining 8 bytes are zero tail padding accepted by the verifier. */
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

/* 1384/1392 bytes, 20 resolved relocations; eight zero tail bytes.
   The caller draws entries 0..7. Preserve byte promotion, coordinate-field
   updates, and the plain-char font lookup with scalar propagation disabled. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
// FUN_00113EF0
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
    descriptor.data.vector = *(PayloadVector *)(shdSkill_addOff(index * 12, state) + 8);
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

/* Skill detail frame, digit counter and pending-skill markers.
   2116/2128 bytes, 37 resolved relocations and 12 zero alignment bytes.
   Compound u16 narrowing and the local declaration order preserve the
   digit/label lifetimes across sprite submissions. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
// FUN_00114460
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
        while (index < *(u16 *)(state + 0x22C)) {
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

/* measured: retail prologue value-saves are `sd $a0,0x30; mov.s $f20,$f12; sw
   $a1,0x3c; move $s0,$a3` (stack spills interleaved around the FP save, $s0
   move LAST); mwcc b210 always groups `[callee-GPR move, mov.s $f20, stack
   spills in assignment order]` with the $s0 move FIRST, whatever the source
   ordering (re-measured this wave: 7 spellings incl. all decl/assign orders,
   decl-initialised, lo/hi/z locals, inline derefs -> best nd 3 = assignment
   `colorSnapshot=arg1` before `positionSnapshot=arg0` which fixes the spill order to [a1,a0] but
   leaves the $s0 move first vs retail last; every other spelling nd 4).
   Everything after the prologue matches byte-for-byte (14cb0 call, blez,
   alpha chain, 11-arg d4c0 setup with a3=alpha, f12/f13=arg0 halves,
   t0-t2=arg1 bytes, f14=fparg0, t3=0). prologue-save scheduling floor. */
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
/* measured: best nd 38 (this wave, down from recorded 73) with an `s32 alpha
   local` = inverseAlpha & 0xFF passed as the d4c0 arg4 (a3) -- without it the
   masks are deleted and the arg setup reorders. Residual is five independent
   families: (1) prologue save rotation (4w: retail `sd $a0; mov.s $f21; move
   $s0; move $s3`, mwcc `move $s0; move $s3; mov.s $f21; sd $a0` -- same
   floor as ShdSkill_DrawIcon); (2) retail computes each call's f32 args before
   the alpha chain, mwcc emits the alpha chain first (8w, argument-evaluation
   order; x/y-locals spellings hoist all FP work before call 1, worse);
   (3) retail coalesces inverseAlpha into arg1's $s0 with `andi $a3,$s0,0xff` at
   ALL three calls, mwcc keeps opacity in $s0 / inverseAlpha in $s1 and deletes
   every mask (move $a3,$s1); (4) 2bc860 block: retail does both adds first
   ($f2 then $f1) then both cvt pairs, mwcc interleaves add/cvt and picks
   $f0; (5) mov.s $f14 before addiu $a1/$a2 vs retail after the or $a0.
   Prologue + 0x68 slot, hi hoisted to $f20, 46a770/trap/d4c0 setups and the
   beqz chain otherwise byte-identical. Tried: m2c-faithful (107), hi local
   (76), x/y locals (76), alpha local (38), inverseAlpha-first, decl swaps,
   u8 alpha (79). arg-eval-order + reg-coalescing + FP-scheduling floor. */
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

/* 652/656 bytes, two resolved relocations; four zero tail bytes.
   Native signed remainder preserves negative byte-index behavior.
   The fallback-first ternary keeps active/previous in the retail registers
   without adding a caller argument or a conditional trampoline. */
/* Move between two four-row columns and the optional pending-skill slot. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
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
        *(s8 *)(state + 5) = current;
        *(s8 *)(state + 4) = next;
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

/* measured: retail allocates the s16 loop counter to $a1, the match key
   (`arg0 & 0xFFFF`) to $a3 and the u16 bound (0x224) to $a2, and reuses the
   counter register directly at the ShdSkill_RemovePoolEntry call (`move $a0,$s0; jal`,
   $5 already holds the counter). mwcc b210 pins the s16 counter in $a3 and
   gives the key $a2 / bound $a1 for EVERY spelling tried (10+ probe_variants
   batches: all 6 declaration orders, all 6 def orders, u16/s16 variants of
   key/bound/count, comparison-form swaps, while vs for, inline bound/key
   expressions, for-init placement, bound/key hoisted before the trap). The
   whole function is otherwise byte-identical. nd 23, all in this rotation
   plus the extra dsll32/dsra32 re-extension the call path needs; temp-register
   rotation floor. */
/* Append a skill to the eight active rows and remove its pending-pool entry. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
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
    count = *(u16 *)(pool + 0x60);
    *(u16 *)(pool + 0x60) = count + 1;
    ((ShdSkillEntry *)shdSkill_addOff(count * 12, pool))->fields.id = (s16)skill;
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

/* measured: MATCH, object 368/window 368. The second-loop counter is made a
   block-local s16 and the call uses a block-scope s16 prototype for
   ShdSkill_RemovePoolEntry; this makes b210 retain the counter in $a1 and sign-extend
   through $a0 exactly as retail. The file-scope s32 prototype and helper
   definition remain unchanged so neighboring ShdSkill_AddActiveSkill and
   ShdSkill_RemovePoolEntry stay MATCH. */
/* Replace the matching active skill and remove the replacement from the pending pool. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
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
    if ((index == -1) || (index >= (s32)*(u16 *)(pool + 0x60))) {
        kAssertFail(D_005E4800, 0x4A1);
    }
    ((ShdSkillEntry *)shdSkill_addOff(index * 12, pool))->fields.id = newSkill;
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

/* Discard the first pending row and compact the parallel row/value arrays. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
/* Tail clearing also uses end-relative integer cursors for the last row and parallel value. */
// FUN_00115760
void ShdSkill_PopPoolEntry(u8 *pool) {
    typedef ShdSkillVector S3f;


    s32 i;
    s32 offset;
    s32 address;

    if (((ShdSkillPool *)pool)->pendingCount <= 0) {
        kAssertFail(D_005E4800, 0x4B7);
    }
    for (i = 0; i < *(u16 *)(pool + 0x224) - 1; i++) {
        ((ShdSkillPool *)pool)->pending[i].vector = ((ShdSkillPool *)pool)->pending[i + 1].vector;
        ((ShdSkillPool *)pool)->values[i] = ((ShdSkillPool *)pool)->values[i + 1];
    }
    offset = *(u16 *)(pool + 0x224) * 12;
    address = offset + (s32)pool;
    ((ShdSkillEntry *)(address + 0x58))->fields.id = 0;
    offset = *(u16 *)(pool + 0x224) * 2;
    address = offset + (s32)pool;
    *(u16 *)(address + 0x1E2) = 0;
    *(u16 *)(pool + 0x224) -= 1;
}

/* measured: live MATCH, object 220B/window 224B, normalized_diff 0. Corrected kAssertFail to (void *, s32). The trampoline form initializes a named input local before the guard and assigns the loop counter after the guard; this makes retail's entry branch target the loop pre-jump instead of b210 threading directly to loop_test. */
/* Remove a pending row at index and compact the row and parallel halfword arrays. */
/* measured: remaining byte-offset accesses retain MATCH; their named-field forms change codegen. */
/* Tail clearing also uses end-relative integer cursors for the last row and parallel value. */
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
    count = *(u16 *)(pool + 0x224);
    if (i < (s32)(count - 1)) {
        goto loop_body_15670;
    }
    entryCursor = shdSkill_addOff(count * 12, pool);
    ((ShdSkillEntry *)(entryCursor + 0x58))->fields.id = 0;
    entryCursor = shdSkill_addOff(*(u16 *)(pool + 0x224) * 2, pool);
    *(u16 *)(entryCursor + 0x1E2) = 0;
    ((ShdSkillPool *)pool)->pendingCount = ((ShdSkillPool *)pool)->pendingCount - 1;
}

// FUN_00115750
u16 ShdSkill_GetPendingSkill(u8 *pool) {
    return ((ShdSkillPool *)pool)->pending[0].fields.id;
}


/*
 * Defined unsigned-packing floor: 468B / 480B, 113 masked differing bytes
 * in 47 emitted words, or 49 words after complete relocation resolution.
 * The remaining 12 retail bytes are zero alignment. The previous archived
 * body remeasures 480B / 284 differing bytes under the current owner.
 * Word slot/opacity formals retain the retail absence of entry narrowing;
 * packing and the real glyph wrapper truncate opacity at their byte uses.
 * The selector now has the shared s16 return, and the font family uses its
 * canonical signed-byte character argument and ninth ignored word.
 * Overlay requirements: update the owner's existing callback declaration
 * to this signature and include the compatible declarations below.
 * All 115 existing owner MATCH bodies remain exact. Production stays ASM.
 * Residuals are tone-mask placement and resulting register allocation.
 * Native32 actual glyph-wrapper consumer: 3,168 cases under UBSan traps,
 * all opacity bytes plus signed-word boundaries, both colors, two slots,
 * three finite positions, resource-before-slot selection, cached persona
 * identity across font enable and persona-ID reload after the first glyph.
 * The erased callback boundary still supplies an ignored trailing state;
 * a typed dispatcher migration must treat every callback provider together.
 */
#include "fr_font_internal.h"
extern s16 func_00105f00(s16 arg0);
extern u32 func_0010d6d0(s16 arg0);

void func_00205c20(u8 *work, s32 slot, f32 x, f32 y,
                   s32 opacity, s32 highlighted)
{
    u8 *glyphs;
    u8 *persona;
    u8 tone;

    glyphs = func_00452560(*(s32 *)(work + 0x5B0));
    if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    persona = ((u8 **)(work + 0x17C))[slot];
    func_00272c60(0x40);
    func_00274ed0(
        1.0f + x, (19.0f + y) - 3.0f, 50.0f,
        ((u32)(u8)tone << 24) | ((u32)(u8)tone << 16) | ((u32)(u8)tone << 8) | (u8)opacity,
        0, 1, (const char *)func_0010d6d0(*(s16 *)(persona + 0xA4)), 0, 0);
    func_00272c80(0x40);
    func_00201650(glyphs, 9, 0x3C, 155.0f + x,
                  24.0f + y, tone, tone, tone, opacity);
    func_00201650(
        glyphs, 9, func_00105f00(*(s16 *)(persona + 0xA4)) + 0x3F,
        178.0f + x, 16.0f + y, tone, tone, tone,
        opacity);
}

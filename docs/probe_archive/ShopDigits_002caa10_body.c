/* Faithful recovery only: object 696B / window 704B, nd 36 (fndiff words).
 * There are 34 executable saved-GPR differences and 8 retail zero-tail bytes.
 * Natural compiler spills already match; no dummy wide locals are needed.
 * The real two-byte GP string is space+NUL; text[16] is an inferred bound
 * on real strcpy storage, not proven original source extent.
 * First-use declarations, direct initializers and s16 width storage do not
 * improve the floor. Sharing width-subtraction branches changes the CFG.
 * Reusing one glyph local regresses to 37 real words; O1 regresses to 724B.
 * Keep the production fallback until every executable word closes. */
#include "type.h"
typedef struct { f32 x, y; } Vec2f;
typedef struct { u8 r, g, b, a; } RGBA;
extern u8 D_00793E80[];
extern char iGpffffa884[2];
void *func_0046d200(void *, s32);
f32 func_0046b260(void *);
void func_0046d280(void *);
char *func_00442830(char *, const char *);
s32 func_002b2a30(s32, u8, s32, s32);
void func_0025ec90(f32, f32, f32, s32, s32, s32, s32, s32, void *);

// FUN_002CAA10
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
void func_002caa10(Vec2f position, f32 depth, RGBA color, u32 number_, s16 glyphBase, void *sprite_, s32 style)
{
    char text[16];
    f32 x;
    s32 measuredBase;
    void *glyph;
    s32 digitWidth;
    void *commaGlyph;
    void *sprite;
    u32 number;
    s32 count;
    s16 commaWidth;
    u8 *entry;
    s32 base;
    s32 a;
    s32 b;
    s32 g;
    f32 y;
    s32 comma;

    sprite = sprite_;
    number = number_;
    count = 0;
    x = position.x;
    measuredBase = (s16)glyphBase;
    glyph = func_0046d200(sprite, measuredBase);
    digitWidth = (s16)(s32)(func_0046b260(glyph) - 1.0f);
    func_0046d280(glyph);
    comma = measuredBase + 10;
    commaGlyph = func_0046d200(sprite, comma);
    commaWidth = (s16)(s32)(func_0046b260(commaGlyph) - 1.0f);
    func_0046d280(commaGlyph);
    func_00442830(text, iGpffffa884);
    entry = D_00793E80 + style * 0x30;
    base = (s16)glyphBase;
    a = color.a;
    b = color.b;
    g = color.g;
    y = position.y;
    do {
        func_0025ec90(x, y, depth, func_002b2a30(0xFF, color.r, g, b), a, base + number % 10, (s32)sprite, 1, entry);
        number /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (number != 0) {
                x -= (f32)commaWidth;
                func_0025ec90(x, y, depth, func_002b2a30(0xFF, color.r, g, b), a, comma, (s32)sprite, 1, entry);
                x -= (f32)digitWidth;
            } else {
                x -= (f32)digitWidth;
            }
        } else {
            x -= (f32)digitWidth;
        }
    } while (number != 0);
}
#pragma pop

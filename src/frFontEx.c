/* Source unit: src/frFontEx_00275a40.c */
#include "type.h"
#include "include_asm.h"
#include "fr_font_internal.h"
#include "fr_font_objects.h"
#include "primitive_queue_internal.h"

extern void kAssertFail(const void *file, u32 line);
extern char D_0063BAE8[];
extern char D_0063BC78[];

/* Font lock / busy flag (s16 at gp-0x58E0). */
extern s16 D_00763810;

extern void frFontMoveListToFloat(int list, float x, float y);
extern void frFontSetGlyphColor(u32 list, u32 color);
extern u32 frFontFadeNodes(int list);
extern u32 frFontListRelease(int list);
extern int frFontNodeWidth(int node);
extern void *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, void *node);
extern void memset(void *dst, s32 value, s32 size);

/* Font-height table (P3FES frFontGetHeight port). */
extern s8 D_00763808[8];
extern s8 D_00764670; /* message-window slot state */

/* Cleanup callback registered by the 002755xx draw wrappers. */
extern void frFontExFreeText(s32 unused, int font);

/* Anonymous gp globals (gp-relative stores in retail). */
extern s32 D_007645A0;
extern s32 D_007645A8;

/* frFontExGlyphHeight (retail frFontGetHeight) takes a char parameter; the retail
 * call sites below pass a full int with no sign-extension, so they call through
 * the int-typed alias func_00275a40_typed, which is linked to the same address. */
extern int func_00275a40_typed(int);

/* Ported from the P3FES frFontEx module (frFontSetTextScale / FUN_003B2CB0
 * family, all verified MATCH there).  P4 moved the create call out of the
 * draw routine: frFontExSetScale is the scale-setter, frFontExLayoutText the
 * draw/position/color routine, frFontExCreateText and the frFontExDraw* functions
 * are create+draw wrappers, and frFontExFreeText is the cleanup callback. */

/* Sets the scale of every glyph node in a text list. */
// FUN_00274A20
void frFontExSetScale(int font, f32 scale)
{
    if (font == 0) {
        kAssertFail(D_0063BC78, 0x12);
    }
    while (font != 0) {
        ((FrFontTextRun *)font)->depth.scale = scale;
        font = ((FrFontTextRun *)font)->previous;
    }
}

/* Positions a text list (alignment flags and base position), sets its glyph scale and colour, and returns the list width. */
// FUN_00274A90
s32 frFontExLayoutText(int font, f32 x, f32 y, f32 scale, s32 color, s8 mode,
                  s32 style, s32 flags)
{
    s32 width = 0;
    int node;
    int glyphNode;
    s32 dx;
    s32 dy;

    if ((flags & 0xb) != 0) {
        for (glyphNode = ((FrFontTextRun *)font)->firstGlyph; glyphNode != 0; glyphNode = ((FrFontGlyphData *)glyphNode)->next) {
            width += ((FrFontGlyphData *)glyphNode)->advance;
            width += (int)((FrFontTextRun *)font)->spacing;
        }
    }
    if ((flags & 8) != 0) {
        x -= (f32)(width >> 1);
    }
    else {
        if ((flags & 2) != 0) {
            x -= (f32)width;
        }
    }
    if ((flags & 4) != 0) {
        y -= (f32)func_00275a40_typed(style);
    }
    node = font;
    if (font == 0) {
        kAssertFail(D_0063BAE8, 0x71F);
    }
    while (((FrFontTextRun *)node)->previous != 0) {
        node = ((FrFontTextRun *)node)->previous;
    }
    dx = (s32)(16.0f * x) - ((FrFontTextRun *)node)->x;
    dy = (s32)(8.0f * y) - ((FrFontTextRun *)node)->y;
    while (node != 0) {
        ((FrFontTextRun *)node)->x = ((FrFontTextRun *)node)->x + dx;
        ((FrFontTextRun *)node)->y = ((FrFontTextRun *)node)->y + dy;
        node = ((FrFontTextRun *)node)->next;
    }
    node = font;
    if (font == 0) {
        kAssertFail(D_0063BC78, 0x12);
    }
    while (node != 0) {
        ((FrFontTextRun *)node)->depth.scale = scale;
        node = ((FrFontTextRun *)node)->previous;
    }
    for (; font != 0; font = ((FrFontTextRun *)font)->previous) {
        int glyph;

        for (glyph = ((FrFontTextRun *)font)->firstGlyph; glyph != 0;
             glyph = ((FrFontGlyphData *)glyph)->next) {
            ((FrFontGlyphData *)glyph)->color = color;
        }
    }
    return width;
}

/* Creates and lays out a text list from a string; returns the list handle and optionally its width. */
// FUN_00274CD0
int frFontExCreateText(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int *widthOut)
{
    int font;
    int node;
    int glyphNode;
    s32 width;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    width = 0;
    if ((flags & 0xb) != 0) {
        for (glyphNode = ((FrFontTextRun *)font)->firstGlyph; glyphNode != 0; glyphNode = ((FrFontGlyphData *)glyphNode)->next) {
            width += ((FrFontGlyphData *)glyphNode)->advance;
            width += (int)((FrFontTextRun *)font)->spacing;
        }
    }
    if ((flags & 8) != 0) {
        x -= (f32)(width >> 1);
    }
    else {
        if ((flags & 2) != 0) {
            x -= (f32)width;
        }
    }
    if ((flags & 4) != 0) {
        y -= (f32)func_00275a40_typed(id);
    }
    frFontMoveListToFloat(font, x, y);
    node = font;
    if (font == 0) {
        kAssertFail(D_0063BC78, 0x12);
    }
    while (node != 0) {
        ((FrFontTextRun *)node)->depth.scale = scale;
        node = ((FrFontTextRun *)node)->previous;
    }
    frFontSetGlyphColor(font, color);
    if (widthOut != 0) {
        *widthOut = width;
    }
    return font;
}

/* Creates, lays out, draws and frees a text list. The final word is unused by this variant. */
// FUN_00274ED0
int frFontExDrawText(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused)
{
    int font;
    s32 result;
    s32 layoutWidth;

    /* Retail callers pass this word; this font variant does not use it. */
    (void)unused;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    frFontDrawList((void *)font, 1, 0);
    if ((s8)frFontFadeNodes(font) == 0) {
        frFontListRelease(font);
    }
    return result;
}

/* Like frFontExDrawText, but overrides each glyph width with charWidth. */
// FUN_00275020
int frFontExDrawTextWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int charWidth)
{
    int font;
    s32 result;
    s32 layoutWidth;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        kAssertFail(D_0063BAE8, 0x6C3);
    }
    ((FrFontTextRun *)font)->spacing = charWidth;
    ((FrFontTextRun *)font)->width = frFontNodeWidth(font);
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    frFontDrawList((void *)font, 1, 0);
    if ((s8)frFontFadeNodes(font) == 0) {
        frFontListRelease(font);
    }
    return result;
}

/* Like frFontExDrawTextWithCharWidth, but stores out in D_007645A0 while drawing. */
// FUN_002751A0
int frFontExDrawTextOutA(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int out, int charWidth)
{
    int font;
    s32 result;
    s32 layoutWidth;

    D_007645A0 = out;
    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        kAssertFail(D_0063BAE8, 0x6C3);
    }
    ((FrFontTextRun *)font)->spacing = charWidth;
    ((FrFontTextRun *)font)->width = frFontNodeWidth(font);
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    D_007645A0 = 0;
    frFontDrawList((void *)font, 1, 0);
    if ((s8)frFontFadeNodes(font) == 0) {
        frFontListRelease(font);
    }
    return result;
}

/* Like frFontExDrawTextWithCharWidth, but stores out in D_007645A8 while drawing. */
// FUN_00275330
int frFontExDrawTextOutB(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int out, int charWidth)
{
    int font;
    s32 result;
    s32 layoutWidth;

    D_007645A8 = out;
    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        kAssertFail(D_0063BAE8, 0x6C3);
    }
    ((FrFontTextRun *)font)->spacing = charWidth;
    ((FrFontTextRun *)font)->width = frFontNodeWidth(font);
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    D_007645A8 = 0;
    frFontDrawList((void *)font, 1, 0);
    if ((s8)frFontFadeNodes(font) == 0) {
        frFontListRelease(font);
    }
    return result;
}

/* Cleanup callback: frees a text list. */
// FUN_002754C0
void frFontExFreeText(s32 unused, int font)
{
    frFontDrawList((void *)font, 1, 0);
    if ((s8)frFontFadeNodes(font) == 0) {
        frFontListRelease(font);
    }
}

/* Creates and lays out a text list, then queues its free on the work list param (frFontExFreeText runs later). */
// FUN_00275520
int frFontExDrawTextDeferred(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param)
{
    int font;
    void *work;
    s32 result;
    s32 layoutWidth;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    if (font == 0) {
        kAssertFail(D_0063BC78, 0xE6);
    }
    work = PrimAllocQueueNode();
    ((PrimQueueNode *)work)->callback = (void *)frFontExFreeText;
    ((PrimQueueNode *)work)->argument.handle = font;
    PrimAppendNode(param, work);
    return result;
}

/* Like frFontExDrawTextDeferred, but overrides each glyph width with charWidth. */
// FUN_00275680
int frFontExDrawTextDeferredWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param,
                  int charWidth)
{
    int font;
    void *work;
    s32 result;
    s32 layoutWidth;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        kAssertFail(D_0063BAE8, 0x6C3);
    }
    ((FrFontTextRun *)font)->spacing = charWidth;
    ((FrFontTextRun *)font)->width = frFontNodeWidth(font);
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    if (font == 0) {
        kAssertFail(D_0063BC78, 0xF9);
    }
    work = PrimAllocQueueNode();
    ((PrimQueueNode *)work)->callback = (void *)frFontExFreeText;
    ((PrimQueueNode *)work)->argument.handle = font;
    PrimAppendNode(param, work);
    return result;
}

/* Like frFontExDrawTextDeferred, but stores out in D_007645A8 while laying out. */
// FUN_00275820
int frFontExDrawTextDeferredOutB(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param, int out)
{
    int font;
    void *work;
    s32 result;
    s32 layoutWidth;

    D_007645A8 = out;
    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = (int)frFontCreateTextList((u8 *)str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    layoutWidth = frFontExLayoutText(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = layoutWidth;
    }
    D_007645A8 = 0;
    if (font == 0) {
        kAssertFail(D_0063BC78, 0x128);
    }
    work = PrimAllocQueueNode();
    ((PrimQueueNode *)work)->callback = (void *)frFontExFreeText;
    ((PrimQueueNode *)work)->argument.handle = font;
    PrimAppendNode(param, work);
    return result;
}

/* Copies a string into a zero-filled buffer of maxlen bytes, truncating so the last byte stays zero. */
/* Retail hoists the loop-invariant maxlen-1 bound into the preheader as a
   $v1 temp; without opt_loop_invariants mwcc re-computes it in the loop
   (measured nd22), and spelling the bound as an explicit local hoists it
   but colors the temp $a1 instead of retail's $v1 (measured nd8, 7
   temp-register words). The pragma reproduces retail exactly (nd1 = 1
   padding word). */
/* Zero-fill the destination and copy at most maxlen minus one source bytes, retaining a terminating zero. */
// FUN_00275980
#pragma push
#pragma opt_loop_invariants on

void frFontExCopyString(char *src, char *dst, int maxlen)
{
    int i = 0;

    if (dst == 0 || src == 0 || maxlen == 0) {
        kAssertFail(D_0063BC78, 0x134);
    }
    memset(dst, 0, maxlen);
    for (; src[i] != 0 && maxlen - 1 > i; i++) {
        dst[i] = src[i];
    }
}
#pragma opt_loop_invariants off
#pragma pop

/* Glyph height of a character (retail frFontGetHeight), read from the D_00763808 table. */
// FUN_00275A40
s8 frFontExGlyphHeight(char index)
{
    return D_00763808[index];
}



// FUN_002BB1C0
/* Return the signed message-window slot state set by nmMesWindowAcquire. */
s32 nmMesWindowGetSlotState(s8 index)
{
    return (&D_00764670)[index];
}

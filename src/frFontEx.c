/* Source unit: src/frFontEx_00275a40.c */
#include "type.h"
#include "include_asm.h"

extern void func_0046d730(const void *file, u32 line);
extern char D_0063BAE8[];
extern char D_0063BC78[];

/* Font lock / busy flag (s16 at gp-0x58E0). */
extern s16 D_00763810;

extern int func_002724d0(const char *param_1, int param_2, int param_3,
                         int param_4, int param_5);
extern void func_00272a10(int param_1, float param_2, float param_3);
extern void func_00272ba0(u32 resource, u32 color);
extern int func_00273170(int param_1, u32 param_2, u32 param_3);
extern u32 func_00272cb0(int param_1);
extern u32 func_00271bd0(int param_1);
extern int func_002738d0(int node);
extern void *func_00460990(void);
extern void func_00460ac0(void *param, void *work);
extern void func_0043f9c8(void *dst, s32 value, s32 size);

/* Font-height tables (P3FES frFontGetHeight ports). */
extern s8 D_00763808;
extern s8 D_00764670;

/* Cleanup callback registered by the 002755xx draw wrappers. */
extern void func_002754c0(s32 arg0, int font);

/* Anonymous gp globals (gp-relative stores in retail). */
extern s32 D_007645A0;
extern s32 D_007645A8;

/* func_00275a40 (frFontGetHeight) takes a char parameter; the retail call
 * sites below pass a full int with no sign-extension, so call through an
 * int-typed alias exactly as the P3FES donor does with frFontGetHeightRaw. */
extern int func_00275a40_typed(int);

/* Ported from the P3FES frFontEx module (frFontSetTextScale / FUN_003B2CB0
 * family, all verified MATCH there).  P4 moved the create call out of the
 * draw routine: func_00274a20 is the scale-setter, func_00274a90 the
 * draw/position/color routine, func_00274cd0 and the 00275xxx functions are
 * create+draw wrappers, and func_002754c0 is the cleanup callback. */

// FUN_00274A20
void func_00274a20(int font, f32 scale)
{
    if (font == 0) {
        func_0046d730(D_0063BC78, 0x12);
    }
    while (font != 0) {
        *(f32 *)(font + 0x14) = scale;
        font = *(int *)(font + 0x24);
    }
}

// FUN_00274A90
s32 func_00274a90(int font, f32 x, f32 y, f32 scale, s32 color, s32 mode,
                  s32 style, s32 flags)
{
    s32 width = 0;
    int node;
    int g;
    s32 dx;
    s32 dy;

    if ((flags & 0xb) != 0) {
        for (g = *(int *)(font + 0x1c); g != 0; g = *(int *)(g + 0x28)) {
            width += *(int *)(g + 0xc);
            width += (int)*(char *)(font + 3);
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
        func_0046d730(D_0063BAE8, 0x71F);
    }
    while (*(int *)(node + 0x24) != 0) {
        node = *(int *)(node + 0x24);
    }
    dx = (s32)(16.0f * x) - *(int *)(node + 4);
    dy = (s32)(8.0f * y) - *(int *)(node + 8);
    while (node != 0) {
        *(int *)(node + 4) = *(int *)(node + 4) + dx;
        *(int *)(node + 8) = *(int *)(node + 8) + dy;
        node = *(int *)(node + 0x28);
    }
    node = font;
    if (font == 0) {
        func_0046d730(D_0063BC78, 0x12);
    }
    while (node != 0) {
        *(f32 *)(node + 0x14) = scale;
        node = *(int *)(node + 0x24);
    }
    for (; font != 0; font = *(int *)(font + 0x24)) {
        int glyph;

        for (glyph = *(int *)(font + 0x1c); glyph != 0;
             glyph = *(int *)(glyph + 0x28)) {
            *(u32 *)(glyph + 0x10) = color;
        }
    }
    return width;
}

// FUN_00274CD0
int func_00274cd0(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int *width_out)
{
    int font;
    int node;
    int g;
    s32 width;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    width = 0;
    if ((flags & 0xb) != 0) {
        for (g = *(int *)(font + 0x1c); g != 0; g = *(int *)(g + 0x28)) {
            width += *(int *)(g + 0xc);
            width += (int)*(char *)(font + 3);
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
    func_00272a10(font, x, y);
    node = font;
    if (font == 0) {
        func_0046d730(D_0063BC78, 0x12);
    }
    while (node != 0) {
        *(f32 *)(node + 0x14) = scale;
        node = *(int *)(node + 0x24);
    }
    func_00272ba0(font, color);
    if (width_out != 0) {
        *width_out = width;
    }
    return font;
}

// FUN_00274ED0
int func_00274ed0(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags)
{
    int font;
    s32 result;
    s32 tmp;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    func_00273170(font, 1, 0);
    if ((s8)func_00272cb0(font) == 0) {
        func_00271bd0(font);
    }
    return result;
}

// FUN_00275020
int func_00275020(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int charWidth)
{
    int font;
    s32 result;
    s32 tmp;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        func_0046d730(D_0063BAE8, 0x6C3);
    }
    *(s8 *)(font + 3) = charWidth;
    *(int *)(font + 0xc) = func_002738d0(font);
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    func_00273170(font, 1, 0);
    if ((s8)func_00272cb0(font) == 0) {
        func_00271bd0(font);
    }
    return result;
}

// FUN_002751A0
int func_002751a0(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int out, int charWidth)
{
    int font;
    s32 result;
    s32 tmp;

    D_007645A0 = out;
    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        func_0046d730(D_0063BAE8, 0x6C3);
    }
    *(s8 *)(font + 3) = charWidth;
    *(int *)(font + 0xc) = func_002738d0(font);
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    D_007645A0 = 0;
    func_00273170(font, 1, 0);
    if ((s8)func_00272cb0(font) == 0) {
        func_00271bd0(font);
    }
    return result;
}

// FUN_00275330
int func_00275330(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int out, int charWidth)
{
    int font;
    s32 result;
    s32 tmp;

    D_007645A8 = out;
    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        func_0046d730(D_0063BAE8, 0x6C3);
    }
    *(s8 *)(font + 3) = charWidth;
    *(int *)(font + 0xc) = func_002738d0(font);
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    D_007645A8 = 0;
    func_00273170(font, 1, 0);
    if ((s8)func_00272cb0(font) == 0) {
        func_00271bd0(font);
    }
    return result;
}

// FUN_002754C0
void func_002754c0(s32 arg0, int font)
{
    func_00273170(font, 1, 0);
    if ((s8)func_00272cb0(font) == 0) {
        func_00271bd0(font);
    }
}

// FUN_00275520
int func_00275520(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int unused, void *param)
{
    int font;
    void *work;
    s32 result;
    s32 tmp;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    if (font == 0) {
        func_0046d730(D_0063BC78, 0xE6);
    }
    work = func_00460990();
    *(void **)((char *)work + 0x8) = (void *)func_002754c0;
    *(s32 *)((char *)work + 0x10) = font;
    func_00460ac0(param, work);
    return result;
}

// FUN_00275680
int func_00275680(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int unused, void *param,
                  int charWidth)
{
    int font;
    void *work;
    s32 result;
    s32 tmp;

    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    if (font == 0) {
        func_0046d730(D_0063BAE8, 0x6C3);
    }
    *(s8 *)(font + 3) = charWidth;
    *(int *)(font + 0xc) = func_002738d0(font);
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    if (font == 0) {
        func_0046d730(D_0063BC78, 0xF9);
    }
    work = func_00460990();
    *(void **)((char *)work + 0x8) = (void *)func_002754c0;
    *(s32 *)((char *)work + 0x10) = font;
    func_00460ac0(param, work);
    return result;
}

// FUN_00275820
int func_00275820(f32 x, f32 y, f32 scale, int color, int chr, int id,
                  const char *str, int flags, int unused, void *param, int out)
{
    int font;
    void *work;
    s32 result;
    s32 tmp;

    D_007645A8 = out;
    D_00763810 = (s64)(s16)(D_00763810 | 1) & -3;
    font = func_002724d0(str, id, chr, 0, 0);
    D_00763810 = (s64)(s16)((s16)D_00763810 & -2) | 2;
    tmp = func_00274a90(font, x, y, scale, color, chr, id, flags);
    if (&result != 0) {
        result = tmp;
    }
    D_007645A8 = 0;
    if (font == 0) {
        func_0046d730(D_0063BC78, 0x128);
    }
    work = func_00460990();
    *(void **)((char *)work + 0x8) = (void *)func_002754c0;
    *(s32 *)((char *)work + 0x10) = font;
    func_00460ac0(param, work);
    return result;
}

/* Retail hoists the loop-invariant maxlen-1 bound into the preheader as a
   $v1 temp; without opt_loop_invariants mwcc re-computes it in the loop
   (measured nd22), and spelling the bound as an explicit local hoists it
   but colors the temp $a1 instead of retail's $v1 (measured nd8, 7
   temp-register words). The pragma reproduces retail exactly (nd1 = 1
   padding word). */
// FUN_00275980
#pragma push
#pragma opt_loop_invariants on

void func_00275980(char *src, char *dst, int maxlen)
{
    int i = 0;

    if (dst == 0 || src == 0 || maxlen == 0) {
        func_0046d730(D_0063BC78, 0x134);
    }
    func_0043f9c8(dst, 0, maxlen);
    for (; src[i] != 0 && maxlen - 1 > i; i++) {
        dst[i] = src[i];
    }
}
#pragma opt_loop_invariants off
#pragma pop

// FUN_00275A40
s8 func_00275a40(char param_1)
{
    return (&D_00763808)[param_1];
}



// FUN_002BB1C0
s8 func_002bb1c0(char param_1)
{
    return (&D_00764670)[param_1];
}

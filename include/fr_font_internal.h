#ifndef FR_FONT_INTERNAL_H
#define FR_FONT_INTERNAL_H

#include "type.h"

s32 frFontInitSlotGrid(s32 unused, s32 columns, s32 rows,
                   s32 width, s32 height, s32 aux_size);
s32 frFontDrawList(void *root, u32 mode, u32 unused);

u8 *frFontCreateTextList(u8 *text, s32 style, s8 chr, s32 spacing, u8 *existing);
s32 frFontExLayoutText(int font, f32 x, f32 y, f32 scale, s32 color, s8 mode,
                  s32 style, s32 flags);
int frFontExCreateText(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int *width_out);
int frFontExDrawText(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused);
int frFontExDrawTextWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int charWidth);
int frFontExDrawTextOutA(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int out, int charWidth);
int frFontExDrawTextOutB(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int out, int charWidth);
int frFontExDrawTextDeferred(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param);
int frFontExDrawTextDeferredWithCharWidth(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param,
                  int charWidth);
int frFontExDrawTextDeferredOutB(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param, int out);

#endif

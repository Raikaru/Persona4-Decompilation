#ifndef FR_FONT_INTERNAL_H
#define FR_FONT_INTERNAL_H

#include "type.h"

s32 func_00270fb0(s32 unused, s32 columns, s32 rows,
                   s32 width, s32 height, s32 aux_size);
s32 func_00273170(void *root, u32 mode, u32 unused);

u8 *func_002724d0(u8 *text, s32 style, s8 chr, s32 spacing, u8 *existing);
s32 func_00274a90(int font, f32 x, f32 y, f32 scale, s32 color, s8 mode,
                  s32 style, s32 flags);
int func_00274cd0(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int *width_out);
int func_00274ed0(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int arg8);
int func_00275020(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int charWidth);
int func_002751a0(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int out, int charWidth);
int func_00275330(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int out, int charWidth);
int func_00275520(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param);
int func_00275680(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param,
                  int charWidth);
int func_00275820(f32 x, f32 y, f32 scale, int color, s8 chr, int id,
                  const char *str, int flags, int unused, void *param, int out);

#endif

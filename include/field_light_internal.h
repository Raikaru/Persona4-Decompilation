#ifndef FIELD_LIGHT_INTERNAL_H
#define FIELD_LIGHT_INTERNAL_H

#include "type.h"

/* Four color bytes stored at offset four in a field-light record. */
typedef struct { u8 c[4]; } FieldRgba8;

s32 func_00145d60(u16 id, f32 *point, f32 x, f32 y, f32 z, FieldRgba8 color);
s32 func_00145e90(u16 id, f32 *point, f32 x, f32 y, f32 z, FieldRgba8 color);

#endif

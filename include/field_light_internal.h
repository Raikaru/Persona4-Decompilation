#ifndef FIELD_LIGHT_INTERNAL_H
#define FIELD_LIGHT_INTERNAL_H

#include "type.h"

/* Four color bytes stored at offset four in a field-light record. */
typedef struct { u8 c[4]; } FieldRgba8;

s32 MT_Scene_CreateFldHitLight(u16 resourceId, f32 *position, f32 width, f32 height, f32 angle, FieldRgba8 rgba);
s32 MT_Scene_CreateRes21Light(u16 resourceId, f32 *position, f32 width, f32 height, f32 angle, FieldRgba8 rgba);

#endif

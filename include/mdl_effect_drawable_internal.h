#ifndef MDL_EFFECT_DRAWABLE_INTERNAL_H
#define MDL_EFFECT_DRAWABLE_INTERNAL_H

#include "mdl_effect_internal.h"
#include "mdl_effect_emitter_internal.h"
#include "effect_mesh_internal.h"

/* Kind-specific drawable layouts. The sprite constructors allocate 0xD4 and
 * 0xB0 bytes respectively and copy 0x98 bytes at +0x30 / +0xC. Members below
 * are established by those constructors and their update/draw consumers.
 * Unnamed spans remain bytes; no meaning is inferred from padding alone. */

typedef struct MdlEffectAnimatedSprite {
    u8 position[0x10]; /* +0x0 */
    u8 rotation[0x10]; /* +0x10 */
    f32 scale; /* +0x20 */
    s32 packedColor; /* +0x24 */
    u32 id; /* +0x28 */
    s32 age; /* +0x2C */
    u8 pad30[0x28];
    u16 resource; /* +0x58 */
    u8 pad5A[0x1A];
    u8 cycle; /* +0x74 */
    u8 pad75[0x47];
    s32 duration; /* +0xBC */
    f32 sizeScale; /* +0xC0 */
    u8 hidden; /* +0xC4 */
    u8 padC5[0x3];
    u8 * geometry; /* +0xC8 */
    s32 tlp; /* +0xCC */
    s32 tracks; /* +0xD0 */
} MdlEffectAnimatedSprite;

typedef struct MdlEffectScreenSprite {
    s32 packedColor; /* +0x0 */
    u32 id; /* +0x4 */
    s32 age; /* +0x8 */
    u8 padC[0x28];
    u16 scene; /* +0x34 */
    u8 pad36[0x62];
    s32 duration; /* +0x98 */
    s32 offsetX; /* +0x9C */
    s32 offsetY; /* +0xA0 */
    u8 * geometry; /* +0xA4 */
    s32 tlp; /* +0xA8 */
    s32 tracks; /* +0xAC */
} MdlEffectScreenSprite;

typedef struct MdlEffectModelDrawable {
    f32 x; /* +0x0 */
    f32 y; /* +0x4 */
    f32 progress; /* +0x8 */
    s32 packedColor; /* +0xC */
    u8 pad10[0x28];
    u16 scene; /* +0x38 */
    u8 pad3A[0x36];
    s32 cycleStart; /* +0x70 */
    u32 cycleEnd; /* +0x74 */
    u8 pad78[0x8];
    u8 cycleEnabled; /* +0x80 */
    u8 pad81[0x3];
    f32 offsetX; /* +0x84 */
    f32 offsetY; /* +0x88 */
    f32 offsetZ; /* +0x8C */
    f32 rotationX; /* +0x90 */
    f32 rotationY; /* +0x94 */
    f32 rotationZ; /* +0x98 */
    u32 duration; /* +0x9C */
    u8 padA0[0x1];
    u8 blend; /* +0xA1 */
    u8 padA2[0x2];
    s32 blendMode; /* +0xA4 */
    u8 padA8[0xC];
    u8 * model; /* +0xB4 */
    u8 cycleMode; /* +0xB8 */
} MdlEffectModelDrawable;

typedef struct MdlEffectShakeRecord {
    s32 duration; /* +0x0 */
    u16 amplitude; /* +0x4 */
    u8 pad6[0x2];
    u32 fadeIn; /* +0x8 */
    s32 fadeOut; /* +0xC */
    u8 pad10[0x4];
} MdlEffectShakeRecord;

typedef struct MdlEffectGridInstance {
    u8 position[0x10]; /* +0x0 */
    u8 pad10[0x8];
    u8 parameters[0x40]; /* +0x18 */
    u8 * geometry; /* +0x58 */
} MdlEffectGridInstance;

typedef struct MdlEffectBattleInstance {
    u8 pad0[0x28];
    s32 age; /* +0x28 */
    s32 kind; /* +0x2C */
    s32 work; /* +0x30 */
    u8 pad34[0x4];
    s32 resource; /* +0x38 */
} MdlEffectBattleInstance;

typedef struct MdlEffectLineNovaRecord {
    u8 pad0[0x18];
    s32 kind; /* +0x18 */
    u8 pad1C[0x4];
    u8 * work; /* +0x20 */
    u8 * parameters; /* +0x24 */
} MdlEffectLineNovaRecord;

typedef struct MdlEffectFade {
    u8 pad0[0x2];
    u16 duration; /* +0x2 */
    u16 elapsed; /* +0x4 */
    u8 pad6[0x6];
    u8 * camera; /* +0xC */
} MdlEffectFade;

typedef struct MdlEffectBillboardParameters {
    u8 color[4]; /* +0x0 */
    u8 pad4[0x4];
    f32 angle; /* +0x8 */
    f32 scale; /* +0xC */
    f32 centerX; /* +0x10 */
    f32 centerY; /* +0x14 */
    f32 left; /* +0x18 */
    f32 top; /* +0x1C */
    f32 right; /* +0x20 */
    f32 bottom; /* +0x24 */
} MdlEffectBillboardParameters;

typedef struct MdlEffectWindWork {
    u8 * entries; /* +0x0 */
    u8 * geometry; /* +0x4 */
} MdlEffectWindWork;

typedef struct MdlEffectWindParameters {
    u8 pad0[0x38];
    u32 meshCount; /* +0x38 */
    u8 pad3C[0x3C];
    f32 fadeIn; /* +0x78 */
    f32 fadeOut; /* +0x7C */
    u8 pad80[0xC];
    s32 duration; /* +0x8C */
    f32 width; /* +0x90 */
} MdlEffectWindParameters;

/* Swirl controller 004916F0 reads this suffix after the common 0xC8 prefix. */
typedef struct MdlEffectSwirlParameters {
    MdlEffectEmitterParameters common;
    f32 startRadius, endRadius;
    f32 angularSpeed, angularVariation, angularAcceleration, gravity;
    f32 angleSpan;
    u8 alternateDirection;
} MdlEffectSwirlParameters;


/* Instanced screen-space rectangles carry four-byte colors and XY bounds;
 * the direct draw variant has no angle/scale/center prefix. */
typedef struct MdlEffectScreenRect {
    u8 color[4];
    u32 unk4;
    f32 left, top, right, bottom;
} MdlEffectScreenRect;
/* Six palette entries at +0x3C, indexed by the direction entry's signed face. */
typedef struct MdlEffectPaletteParameters {
    u8 pad0[0x38];
    s32 duration;
    s32 colors[6];
} MdlEffectPaletteParameters;

#endif

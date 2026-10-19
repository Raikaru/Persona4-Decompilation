#ifndef KOSAKA_K_FLDFILTER_INTERNAL_H
#define KOSAKA_K_FLDFILTER_INTERNAL_H

#include "type.h"

/* The 0x12400-byte file holds 256 entries of 0x124 bytes. Each entry has
 * one render-type word followed by an 8-row, 9-column packed-color lattice;
 * FldColorCrossfadeStep reads adjacent corners with a 0x24-byte row stride. */
typedef struct FldFilterEntry {
    u32 type;
    u32 colors[8][9];
} FldFilterEntry;

/* InitQuads writes four vertices per 0x100-byte quad. Coordinates occupy
 * +0x00..08; fog/map texture coordinates use +0x10/+0x14, reciprocal depth
 * uses +0x18, and floating RGBA occupies +0x20..2C. */
typedef struct FldFilterVertex {
    f32 x;
    f32 y;
    f32 z;
    u8 pad0C[4];
    f32 u;
    f32 v;
    f32 reciprocalDepth;
    u8 pad1C[4];
    f32 red;
    f32 green;
    f32 blue;
    f32 alpha;
    u8 pad30[0x10];
} FldFilterVertex;

#endif

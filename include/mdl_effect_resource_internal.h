#ifndef MDL_EFFECT_RESOURCE_INTERNAL_H
#define MDL_EFFECT_RESOURCE_INTERNAL_H

#include "type.h"

/* Resource loader allocates 0x1C bytes before the copied image. Entries in the
 * image are 0x14 bytes; their payload offsets remain relative to the image. */
typedef struct MdlEffectResourceImage {
    s32 streamOffset;
    s32 entryCount;
} MdlEffectResourceImage;
typedef struct MdlEffectResourceEntry {
    s32 payloadOffset;
    u32 unk4;
    s32 flags;
    u32 count;
    s32 kind;
} MdlEffectResourceEntry;
typedef struct MdlEffectTrackResource {
    u8 *image;
    u8 *entries;
    s32 trackCount;
    u32 streamCount;
    s32 references;
    u8 *streams;
    u8 *allocation;
} MdlEffectTrackResource;

/* Primitive records allocate 0x2C bytes. Pointer/handle representations share
 * the payload word; the two source sections can be self-relative. */
typedef struct MdlEffectPrimitiveRecord {
    union { u32 value; s32 signedValue; } tag;
    u16 kind;
    u8 pad6[2];
    union { void *pointer; s32 handle; } instance;
    u16 id;
    u8 padE[0xE];
    u16 sourceKind;
    u8 pad1E[2];
    union { s32 offset; u8 *pointer; } secondary;
    s32 secondaryCount;
    s32 secondaryAllocation;
} MdlEffectPrimitiveRecord;

/* Geometry wrapper fields consumed by multipart cloning and material setters.
 * The 0x48/0x4C halfwords are used signed for loops and unsigned at creation. */
typedef struct MdlEffectMultipartGeometry {
    u32 unk0;
    s32 flags;
    u16 vertexCount;
    u16 trianglesPerPart;
    s32 resource;
    u8 *model;
    u8 pad14[4];
    s32 link[2];
    u8 pad20[0x28];
    union { s16 signedValue; u16 value; } partCount;
    u8 pad4A[2];
    s16 triangleCount;
    u8 pad4E[6];
    u8 *materials;
} MdlEffectMultipartGeometry;
typedef struct MdlEffectGeometryModel { u8 pad0[0x18]; u8 *geometry; } MdlEffectGeometryModel;
typedef struct MdlEffectGeometryData { u8 pad0[0x2C]; u8 *triangles; } MdlEffectGeometryData;

/* Initializer 00484B30 writes the 0x80-byte transform/color state; tree roots
 * allocate 0x90 bytes and child nodes allocate 0xC0 bytes. */
typedef struct MdlEffectState {
    u8 position[0x10];
    u8 rotation[0x10];
    u8 scaleVector[0x10];
    u8 pad30[0x10];
    u8 offset[0x10];
    u8 orientation[0x10];
    f32 scale;
    union { s32 signedValue; u32 value; } packedColor;
    union { s32 signedValue; u32 value; } flags;
    u32 unk6C;
    u32 unk70;
    f32 multiplier;
    u8 pad78[8];
} MdlEffectState;
typedef struct MdlEffectTree {
    MdlEffectState state;
    s32 childCount;
    u32 frame;
    u8 *lastChild;
    u8 *firstChild;
} MdlEffectTree;

typedef struct MdlEffectTrackFrame {
    s16 width, height, originX, originY;
    s16 left, top, right, bottom;
    s16 textureIndex, delay;
    f32 value;
} MdlEffectTrackFrame;
typedef struct MdlEffectTrackChild { s16 entryIndex, delay; u8 pad4[0x14]; } MdlEffectTrackChild;
typedef struct MdlEffectTrackOutput {
    f32 left, top, right, bottom, value;
    u8 *texture;
    f32 u0, v0, u1, v1;
    s16 mode;
    u8 pad2A[2];
    s32 frameValue;
    f32 textureWidth, textureHeight;
} MdlEffectTrackOutput;

#endif

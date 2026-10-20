#ifndef MDL_EFFECT_INTERNAL_H
#define MDL_EFFECT_INTERNAL_H

#include "type.h"
#include "mdl_effect_resource_internal.h"
#include "polygon_track_internal.h"
#include "polygon_thunder_internal.h"

/* mdlEffect_inferred_00481d80 allocates 0x18 + trackCount * 0x14.
 * The resource is shared, with its reference count at +0x10. */
typedef struct MdlEffectTrack {
    u32 unk0;
    u32 frame;
    u32 active; /* Signed frame-delay countdown in the resource playback path. */
    u8 *resource; /* Resource entry, including its frame count at +0xC. */
    u8 *payload;
} MdlEffectTrack;
typedef struct MdlEffectTrackInstance {
    MdlEffectTrackResource *resource;
    s32 flags;
    s32 entryIndex;
    s32 trackCount;
    MdlEffectTrack *tracks;
    s16 active;
    u8 pad16[2];
} MdlEffectTrackInstance;

/* Common fields read by the kind-specific scale appliers. Parameter meaning
 * beyond the common multiplier operation is not established. Three 8-byte
 * entries begin at +0x74; only the first float of each entry is scaled. */
typedef struct MdlEffectScalePair { f32 value; u32 unk4; } MdlEffectScalePair;
typedef struct MdlEffectScaleParameters {
    u8 pad0[0x64];
    f32 unk64;
    f32 unk68;
    u8 pad6C[8];
    MdlEffectScalePair components[3];
    u8 pad8C[0x3C];
    f32 unkC8;
    f32 unkCC;
    f32 unkD0;
    f32 unkD4;
    f32 unkD8;
    f32 unkDC;
    f32 unkE0;
    f32 unkE4;
    f32 unkE8;
    f32 unkEC;
    f32 unkF0;
} MdlEffectScaleParameters;

/* Native Im2D vertex stride is 0x40. Integer zero writes to UV slots retain
 * their word representation, while nonzero UVs and colors are floats. */
typedef union MdlEffectFloatWord { f32 value; s32 bits; } MdlEffectFloatWord;
typedef struct MdlEffectScreenVertex {
    f32 x, y, z;
    u32 unkC;
    MdlEffectFloatWord u, v;
    f32 reciprocalDepth;
    u32 unk1C;
    f32 red, green, blue, alpha;
    u8 pad30[0x10];
} MdlEffectScreenVertex;

/* RenderWare raster prefix and camera clip distances used by effect draws. */
typedef struct MdlEffectRaster {
    u8 pad0[0xC];
    s32 width, height;
} MdlEffectRaster;
typedef struct MdlEffectCamera {
    u32 unk0;
    u8 *frame;
    u8 pad8[0x58];
    s32 raster;
    s32 depthRaster;
    u8 pad68[0x18];
    f32 nearPlane, farPlane;
} MdlEffectCamera;

/* Scheduler payload pointer and per-command counter used by the fade/UI
 * callbacks. Payload layouts differ by callback, so the pointer stays opaque. */
typedef struct MdlEffectCommand {
    f32 position[3];
    u32 unkC;
    f32 orientation[4];
    f32 scale;
    u32 unk24;
    u32 counter;
    u32 unk2C;
    u8 *object;
    u32 unk34;
    u8 *parameters;
} MdlEffectCommand;
typedef struct MdlEffectWindowRect { s16 x; u8 pad2[2]; s16 y; u8 pad6[2]; s16 width; u8 padA[2]; s16 height; } MdlEffectWindowRect;
typedef struct MdlEffectFadeParameters { u8 state; u8 pad1[5]; u16 variant; } MdlEffectFadeParameters;

/* Ring, flash-quad and wind setters share this vector-scale instance prefix.
 * Their dispatch records use the same +0x34 age and +0x38 kind fields. */
typedef struct MdlEffectVectorInstance {
    u8 position[0x10];
    u8 rotation[0x10];
    f32 scale[3];
    u32 unk2C;
    s32 packedColor;
    s32 age;
    union { s32 value; u16 low; } kind;
    u8 *child;
    u8 *parameters;
} MdlEffectVectorInstance;

/* Self-relative parameter blocks become direct pointers when their allocation
 * word is nonzero. Freeing clears the pointer, count and allocation together. */
typedef struct MdlEffectSource {
    u8 pad0[0x10];
    u8 *parameters;
    s32 count;
    union { s32 handle; u8 *pointer; } allocation;
    u32 unk1C;
    u8 *secondaryParameters;
    s32 secondaryCount;
    union { s32 handle; u8 *pointer; } secondaryAllocation;
} MdlEffectSource;

/* List node allocation is 0x14; data blocks allocate 0x10 + payload size.
 * Both counts and pointer words retain their original integer interpretation. */
typedef struct MdlEffectListData {
    u32 payload;
    u32 handle;
    s32 references;
    u32 flags;
} MdlEffectListData;
typedef struct MdlEffectListNode {
    u32 data;
    u16 matrixIndex;
    u8 pad6[2];
    s32 handle;
    u32 previous;
    u32 next;
} MdlEffectListNode;

typedef struct MdlEffectOverlayScale {
    s32 duration;
    f32 startScale;
    f32 endScale;
} MdlEffectOverlayScale;
typedef struct MdlEffectModelCurve {
    u8 pad0[0x2C];
    u32 duration;
    f32 layerWeight;
    f32 scale;
    u16 cameraMode;
} MdlEffectModelCurve;
typedef struct MdlEffectModelReference { u8 *model; u16 matrixIndex; } MdlEffectModelReference;

typedef struct MdlEffectUnitRefresh { s32 cameraMode; u8 refreshUnits; } MdlEffectUnitRefresh;
/* Only the overlay scalar in the battle UI root is recovered here. */
typedef struct MdlEffectUiState { u8 pad0[0xDC]; f32 overlayScale; } MdlEffectUiState;
/* Battle side heads are eight bytes apart; the second word is not used here. */
typedef struct MdlEffectUnitSide { u8 *head; u32 unk4; } MdlEffectUnitSide;
typedef struct MdlEffectBattleState { u8 pad0[0x178]; MdlEffectUnitSide sides[2]; } MdlEffectBattleState;

typedef struct MdlEffectTrackFrames { u8 pad0[0xC]; u32 frameCount; } MdlEffectTrackFrames;
typedef struct MdlEffectSlotTable {
    u8 origin[0x10];
    u8 *firstGeometry;
    u8 *secondGeometry;
    s16 *slots;
    u8 pad1C[0x14];
    u8 **entries;
    u8 *parameters;
} MdlEffectSlotTable;

/* Common scalar-scale prefix of sprite/model drawable instances. Later
 * members are only used by the model drawable and reference-copy paths. */
typedef struct MdlEffectSpriteInstance {
    u8 position[0x10];
    u8 rotation[0x10];
    f32 scale;
    s32 packedColor;
    u32 childCount;
    s32 age;
    u8 pad30[0x60];
    s32 duration;
    u32 unk94;
    s32 *children;
    s32 drawable;
    u8 *model;
    u8 padA4[0x24];
    s32 geometry;
    s32 tlpRef;
    s32 tracks;
} MdlEffectSpriteInstance;

/* Flare draw consumes thirteen 0x10-byte entries per variant (0xD0). */
typedef struct MdlEffectFlareEntry {
    f32 positionFactor;
    f32 sizeFactor;
    u8 texture;
    u8 pad9[3];
    s32 packedColor;
} MdlEffectFlareEntry;
typedef struct MdlEffectFlareInstance {
    u8 position[0x10];
    s32 age;
    s32 packedColor;
    u8 pad18[0x28];
    u16 scene;
    u8 pad42[0xA];
    f32 scale;
    s32 duration;
    u8 variant;
    u8 pad55[3];
    u8 *geometry;
} MdlEffectFlareInstance;

/* Intrusive node fields and the lookup key used by mdlEffectFindNodeById. */
typedef struct MdlEffectNode {
    MdlEffectState state;
    s32 startFrame;
    s32 flags;
    u8 attributes[4];
    u8 *children;
    union { s32 id; u8 *primitive; };
    s32 sourceIndex;
    s32 sourceFlags;
    char name[0x10];
    u8 *next;
    u8 *previous;
    u8 padB4[0xC];
} MdlEffectNode;

/* Randomized quad initializer: source +0x28 is the full side length;
 * generated bounds are centered on the independently jittered X/Y values. */
typedef struct MdlEffectQuadParameters {
    u32 unk0;
    s32 frameRange;
    u32 unk8;
    s32 unkC;
    s32 unk10;
    f32 unk14;
    u32 unk18;
    f32 centerX, centerY, spread;
    s32 size;
} MdlEffectQuadParameters;
typedef struct MdlEffectQuadState {
    u32 unk0;
    s32 unk4;
    s32 unk8;
    f32 unkC;
    u32 unk10;
    f32 centerX, centerY;
    f32 left, top, right, bottom;
} MdlEffectQuadState;
typedef struct MdlEffectQuadEntry {
    u32 frame;
    f32 progress;
    MdlEffectQuadState state;
} MdlEffectQuadEntry;

/* Direction initializer writes a 0x18-byte record; face selection either
 * chooses one of six faces, cycles by record index, or stores -1. */
typedef struct MdlEffectDirectionParameters {
    u8 pad0[0x10];
    u8 randomDirection;
    u8 pad11[3];
    f32 direction[3];
    u32 unk20;
    f32 speed, speedSpread;
    u8 pad2C[8];
    s32 faceMode;
    u8 pad38[0x24];
    u8 *entries;
} MdlEffectDirectionParameters;
typedef struct MdlEffectDirectionEntry {
    f32 direction[3];
    f32 angle;
    f32 speed;
    union { u8 value; s8 signedValue; } face;
    u8 pad15[3];
} MdlEffectDirectionEntry;

/* Helper clone copies 0x98 bytes at +0xC and clones optional geometry at +0xA4. */
typedef struct MdlEffectHelperInstance {
    u32 unk0;
    s32 unk4;
    s32 age;
    u8 parameters[0x98];
    s32 geometry;
} MdlEffectHelperInstance;
typedef struct MdlEffectCameraTexture { u8 pad0[8]; s32 raster; u8 *camera; } MdlEffectCameraTexture;
typedef struct MdlEffectLineNovaInstance { u8 position[0x10]; s32 packedColor; s32 age; s32 kind; } MdlEffectLineNovaInstance;

/* Renderable model fields traversed by flare drawing and frame transforms. */
typedef struct MdlEffectRenderModel {
    u16 flags;
    u8 pad2[0xA];
    void *frame;
    u8 *atomic;
    u32 unk14;
    s32 drawPrevious, drawNext;
    u8 pad20[0x34];
    u8 *materials;
} MdlEffectRenderModel;
typedef struct MdlEffectMaterialList { u8 **materials; s32 count; s32 capacity; } MdlEffectMaterialList;
typedef struct MdlEffectDelayedEntry { u32 unk0; s32 age; u8 pad8[8]; } MdlEffectDelayedEntry;
typedef struct MdlEffectDelayParameters { u8 pad0[0x38]; u32 entryCount; } MdlEffectDelayParameters;

/* Only this word is recovered for the general effect object accessor. */
typedef struct MdlEffectObject { u8 pad0[0x84]; u32 unk84; } MdlEffectObject;
/* Material-color callback input: a geometry wrapper pointer at +0x3C.
 * The concrete effect subtype is not established by this callback alone. */
typedef struct MdlEffectMaterialOwner { u8 pad0[0x3C]; u8 **geometry; } MdlEffectMaterialOwner;

#endif

#ifndef MDL_FILE_INTERNAL_H
#define MDL_FILE_INTERNAL_H

#include "type.h"

/* Partial model-file layouts from the reference, auxiliary-load, motion and
 * track consumers. Motion-state halfwords are the same slots initialized by
 * mdlInitObjectSlots and decremented by mdlTickMotionState. Track records have
 * a 0x10-byte stride; key payload stride remains supplied by each record. */

typedef struct MdlFileAttachment {
    u32 resource; /* +0x0 */
    u32 handle; /* +0x4 */
} MdlFileAttachment;

typedef struct MdlFileSharedResource {
    u8 pad0[0x4];
    s32 references; /* +0x4 */
} MdlFileSharedResource;

typedef struct MdlFileObject {
    u8 * data; /* +0x0 */
    s32 slot; /* +0x4 */
    s32 references; /* +0x8 */
    u16 type; /* +0xC */
    u8 padE[0x2];
    u16 mode; /* +0x10 */
    u16 flags; /* +0x12 */
} MdlFileObject;

typedef struct MdlMotionState {
    u8 * object; /* +0x0 */
    s16 animation; /* +0x4 */
    u16 blendTicks; /* +0x6 */
    s16 retries; /* +0x8 */
    u8 padA[0x2];
    s32 request; /* +0xC */
    u16 flags; /* +0x10 */
    s16 channel; /* +0x12 */
    s16 streamFlags; /* +0x14 */
    s16 waitTicks; /* +0x16 */
    s32 requestValue; /* +0x18 */
    s16 pendingSlot; /* +0x1C */
    s16 pendingChannel; /* +0x1E */
    s16 pendingFlags; /* +0x20 */
    s16 pendingKind; /* +0x22 */
    s16 pendingTicks; /* +0x24 */
    s16 activeSlot; /* +0x26 */
} MdlMotionState;

typedef struct MdlFileAuxiliary {
    s32 reader; /* +0x0 */
    u8 pad4[0x28];
    s32 data; /* +0x2C */
    s32 size; /* +0x30 */
    u8 * textureNames; /* +0x34 */
    u8 * file; /* +0x38 */
    u8 state; /* +0x3C */
    u8 pad3D[0x3];
    s32 archived; /* +0x40 */
} MdlFileAuxiliary;

typedef struct MdlFileModel {
    u8 pad0[0xD4];
    u16 type; /* +0xD4 */
    u16 id; /* +0xD6 */
    s32 flags; /* +0xD8 */
    s32 clump; /* +0xDC: movieNativeSkyDraw passes this to clump renderers */
    s32 drawBuckets; /* +0xE0: optional material-group list */
    s32 skyAlpha; /* +0xE4: RpSkyRenderStateSet state 2 */
    s32 skyTest; /* +0xE8: RpSkyRenderStateSet state 3 */
    u8 padEC[2];
    u8 finished; /* +0xEE */
    u8 padEF[0x108 - 0xEF];
    f32 unk108; /* +0x108: held-frame mode compares this playback value to one */
    u8 pad10C[0x280 - 0x10C];
    u8 colorRed; /* +0x280: model-load flag 0x100 clears RGB */
    u8 colorGreen;
    u8 colorBlue;
    u8 pad283[0x30C - 0x283];
    u8 * auxiliary; /* +0x30C */
} MdlFileModel;

typedef char MdlFileModelPlaybackOffsetCheck[(u32)&((MdlFileModel *)0)->unk108 == 0x108 ? 1 : -1];
typedef char MdlFileModelColorOffsetCheck[(u32)&((MdlFileModel *)0)->colorRed == 0x280 ? 1 : -1];
typedef char MdlFileModelSizeCheck[sizeof(MdlFileModel) == 0x310 ? 1 : -1];

typedef struct MdlFileTrack {
    s32 count; /* +0x0 */
    u8 pad4[0x4];
    s32 stride; /* +0x8 */
    u8 * keys; /* +0xC */
} MdlFileTrack;

typedef struct MdlFileTrackSet {
    u8 pad0[0x50];
    void * targets; /* +0x50 */
} MdlFileTrackSet;

typedef struct MdlFileReference {
    u8 pad0[0x8];
    u16 references; /* +0x8 */
} MdlFileReference;


/* Scalar payloads are time/value pairs (8 bytes) after the stride-based search. */
typedef struct MdlFileScalarKey {
    f32 time, value;
} MdlFileScalarKey;

#endif

#ifndef EFF_GEOMETRY_BLOCK_INTERNAL_H
#define EFF_GEOMETRY_BLOCK_INTERNAL_H

#include "type.h"

/* GeometryBlockCreate allocates 0x48 bytes; multipart blocks extend this prefix
 * to 0x58. Effect consumers use the low halfwords and pointer forms, while the
 * geometry constructors also write packed counts and signed address words.
 * The instance owner at +0x28 is distinct from the draw-node owner at +0x34. */
typedef struct EffGeometryBlock {
    union {
        struct { u16 kind; u16 unk02; };
        union { s16 signedHalf[2]; u16 half[2]; } kindData;
    };
    s32 flags; /* +0x04 */
    union {
        struct { s16 vertexCount; s16 triangleCount; };
        union { s16 signedHalf[2]; u16 half[2]; } vertexCounts;
    };
    union {
        void *frame; /* +0x0C */
        union { s32 signedValue; void *pointer; } frameData;
    };
    union {
        u8 *atomic; /* +0x10 */
        union { s32 signedValue; s32 *words; u8 *bytes; } atomicData;
    };
    union {
        u8 *material; /* +0x14 */
        union { s32 signedValue; s32 *words; u8 *bytes; } materialData;
    };
    union { u32 previous; s32 nodeNext; }; /* +0x18 */
    union { u32 next; s32 nodePrevious; }; /* +0x1C */
    u8 pad20[8];
    u8 *owner; /* +0x28: LineNovaDrawCallback's instance */
    u8 pad2C[4];
    s16 tag; /* +0x30 */
    u8 pad32[2];
    union { u8 *bytes; void *pointer; } drawOwner; /* +0x34 */
    u8 pad38[0x10];
} EffGeometryBlock;

typedef char EffGeometryBlockSizeCheck[sizeof(EffGeometryBlock) == 0x48 ? 1 : -1];
typedef char EffGeometryBlockAtomicOffsetCheck[(u32)&((EffGeometryBlock *)0)->atomic == 0x10 ? 1 : -1];
typedef char EffGeometryBlockOwnerOffsetCheck[(u32)&((EffGeometryBlock *)0)->owner == 0x28 ? 1 : -1];
typedef char EffGeometryBlockDrawOwnerOffsetCheck[(u32)&((EffGeometryBlock *)0)->drawOwner == 0x34 ? 1 : -1];

#endif

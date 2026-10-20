#ifndef K_SHADOW_PROJECTION_INTERNAL_H
#define K_SHADOW_PROJECTION_INTERNAL_H

#include "type.h"
#include "rw_atomic_layout_internal.h"
#include "rw_collision_internal.h"

/* RwV3d is supplied by the unit. ProjectTriangle emits 0x24-byte vertices;
 * DrawProjection and the 0x54d0-byte allocation establish the buffer boundary. */
typedef struct KosakaShadowVertex
{
    RwV3d position;
    u8 color[4];
    RwV3d normal;
    f32 u;
    f32 v;
} KosakaShadowVertex;

typedef struct KosakaShadowProjectionTail
{
    RwV3d direction;                 /* 0x5470 */
    u8 pad547C[4];
    u8 projectionMatrix[0x40];       /* 0x5480 */
    u8 alpha;                       /* 0x54c0 */
    u8 pad54C1[3];
    s32 fadeWithDepth;
    s32 flushCount;
    u8 pad54CC[4];
} KosakaShadowProjectionTail;

typedef struct FldShadowProjectionWork
{
    KosakaShadowVertex vertices[600];
    u32 vertexCount;                 /* 0x5460 */
    u32 triangleCount;
    u8 pad5468[8];
    KosakaShadowProjectionTail tail;
} FldShadowProjectionWork;

/* SDK RpCollisionTriangle layout from rw/sky2/rpcollis.h. Use the existing
 * nominal collision type without pulling in the SDK's duplicate scalar types. */
struct RpCollisionTriangle
{
    RwV3d normal;
    RwV3d point;
    s32 index;
    RwV3d *vertices[3];
};

#endif

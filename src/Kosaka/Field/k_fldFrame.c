/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_00169200)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// FUN_00169200
RwV3d* func_00169200(RwV3d* dst, const RwV3d* point,
                     const RwV3d* start, const RwV3d* end)
{
    RwV3d edge;
    f32 projection;
    f32 edgeLengthSquared;
    f32 fraction;

    edge.x = end->x - start->x;
    edge.y = end->y - start->y;
    edge.z = end->z - start->z;
    projection = point->x * edge.x + point->y * edge.y + point->z * edge.z -
                 (start->x * edge.x + start->y * edge.y + start->z * edge.z);

    if (projection <= 0.0f)
    {
        *dst = *start;
    }
    else
    {
        edgeLengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
        if (projection < edgeLengthSquared)
        {
            fraction = projection / edgeLengthSquared;
            dst->x = edge.x * fraction;
            dst->y = edge.y * fraction;
            dst->z = edge.z * fraction;
            dst->x += start->x;
            dst->y += start->y;
            dst->z += start->z;
        }
        else
        {
            *dst = *end;
        }
    }

    return dst;
}
#endif /* P4_UNIT_00169200 */

#if defined(P4_UNIT_0016A0C0)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

extern void func_00394e70(void* collision, void* state,
                          void* callback, void* param);
extern void* func_00169a30(const RwV3d* point, const void* triangle,
                           void* collector);

// FUN_0016A0C0
void* func_0016a0c0(void* collisionWorld, void* state)
{
    *(void**)((u8*)state + 0xb34) = collisionWorld;
    func_00394e70(collisionWorld, (u8*)state + 0xb18,
                  func_00169a30, state);
    return collisionWorld;
}
#endif /* P4_UNIT_0016A0C0 */

#if defined(P4_UNIT_0016B350)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;

// FUN_0016B350
void* func_0016b350(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = 1;
        raycast->nearestFraction = fraction;
    }
    return unused;
}
#endif /* P4_UNIT_0016B350 */

#if defined(P4_UNIT_0016B430)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;

extern void func_00394e70(void* collision, void* state,
                          void* callback, void* param);
extern void* func_0016b350(f32 fraction, const RwV3d* line,
                           void* unused, FldFrameRaycast* raycast);

// FUN_0016B430
void* func_0016b430(void* collisionWorld, FldFrameRaycast* raycast)
{
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, &raycast->line[0],
                  func_0016b350, raycast);
    return collisionWorld;
}
#endif /* P4_UNIT_0016B430 */

#if defined(P4_UNIT_0016B480)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;

// P3 counterpart fGpffff820c (gp -0x7DF4); P4 retail uses gp -0x7D4C,
// i.e. absolute 0x007690f0 - 0x7d4c = 0x007613a4.
extern f32 fGpffff82b4;
extern void func_003bff30(void* collisionWorld, void* callback, void* param);
extern void* func_0016b430(void* collisionWorld, FldFrameRaycast* raycast);

// FUN_0016B480
u32 func_0016b480(void* collisionWorld, const RwV3d* line,
                  RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy __attribute__((aligned(16)));
    FldFrameIntersection intersection __attribute__((aligned(16)));
    FldFrameRaycast raycast;

    lineCopy = *(const FldFrameLine*)line;
    raycast.hitPointDst = hitPointDst;
    raycast.didHit = 0;
    raycast.nearestFraction = fGpffff82b4;
    intersection.type = 1;
    intersection.line = lineCopy;
    *(FldFrameIntersection*)&raycast.line[0] = intersection;

    if (collisionWorld == NULL)
    {
        return 0;
    }
    func_003bff30(collisionWorld, func_0016b430, &raycast);
    return raycast.didHit;
}
#endif /* P4_UNIT_0016B480 */

#if defined(P4_UNIT_0016B770)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;

// FUN_0016B770
void* func_0016b770(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = 1;
        raycast->nearestFraction = fraction;
    }
    return unused;
}
#endif /* P4_UNIT_0016B770 */

#if defined(P4_UNIT_0016B850)
/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;

extern void func_00394e70(void* collision, void* state,
                          void* callback, void* param);
extern void* func_0016b770(f32 fraction, const RwV3d* line,
                           void* unused, FldFrameRaycast* raycast);

// FUN_0016B850
void* func_0016b850(void* collisionWorld, FldFrameRaycast* raycast)
{
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, &raycast->line[0],
                  func_0016b770, raycast);
    return collisionWorld;
}
#endif /* P4_UNIT_0016B850 */

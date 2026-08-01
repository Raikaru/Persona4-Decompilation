/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0014B5D0)
/* Source unit: src/Kosaka/k_draw_0014b5d0.c (1 function markers) */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

extern RwMatrix* func_003e0670(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern f32 func_0044b950(f32 x, f32 y);
extern f32 gPI;

#pragma push
// FUN_0014B5D0
f32 func_0014b5d0(const RwMatrix* matrix)
{
    RwMatrix normalized;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    return (-func_0044b950(normalized.right.z, normalized.right.x) * 180.0f) / gPI;
}
#pragma pop
#endif /* P4_UNIT_0014B5D0 */

#if defined(P4_UNIT_0014B660)
/* Source unit: src/Kosaka/k_draw_0014b660.c (1 function markers) */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

extern RwMatrix* func_003e0670(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern f32 func_0044b950(f32 x, f32 y);
extern f32 gPI;

#pragma push
// FUN_0014B660
f32 func_0014b660(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    up = &normalized.up;
    return (-func_0044b950(up->z, up->y) * 180.0f) / gPI;
}
#pragma pop
#endif /* P4_UNIT_0014B660 */

#if defined(P4_UNIT_0014B6F0)
/* Source unit: src/Kosaka/k_draw_0014b6f0.c (1 function markers) */
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

extern RwMatrix* func_003e0670(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern f32 func_0044b950(f32 x, f32 y);
extern f32 gPI;

#pragma push
// FUN_0014B6F0
f32 func_0014b6f0(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    up = &normalized.up;
    return (func_0044b950(up->x, up->y) * 180.0f) / gPI;
}
#pragma pop
#endif /* P4_UNIT_0014B6F0 */

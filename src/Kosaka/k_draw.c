/* Consolidated Persona 4 source units. */
/* Whole-file translation unit (functions contiguous in retail). */
#include "include_asm.h"
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

// FUN_0014B5D0
f32 func_0014b5d0(const RwMatrix* matrix)
{
    RwMatrix normalized;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    return (-func_0044b950(normalized.right.z, normalized.right.x) * 180.0f) / gPI;
}

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

// FUN_0014D510
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d510);
// FUN_0014D5E0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d5e0);
// FUN_0014D5F0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d5f0);
// FUN_0014D620
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d620);
// FUN_0014D660
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d660);
// FUN_0014D6D0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d6d0);
// FUN_0014D700
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d700);
// FUN_0014D7C0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d7c0);
// FUN_0014D800
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d800);
// FUN_0014D830
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d830);
// FUN_0014D870
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d870);
// FUN_0014D8E0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d8e0);
// FUN_0014D910
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d910);
// FUN_0014D9D0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014d9d0);
// FUN_0014DA10
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014da10);
// FUN_0014DA20
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014da20);
// FUN_0014DA30
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014da30);
// FUN_0014DB10
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014db10);
// FUN_0014DB80
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014db80);
// FUN_0014DBB0
INCLUDE_ASM("asm/nonmatchings/k_draw", func_0014dbb0);

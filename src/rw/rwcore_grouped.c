/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"
typedef struct RwObjectOwnerLink RwObjectOwnerLink;
typedef struct RwObject RwObject;

/* Canonical grouped function declarations. */
u32 func_003e8110(u32 camera);
u32 func_003e8120(u32 camera);
u8 func_003e9240(RwObjectOwnerLink *param_1);
u32 func_003e9750(int param_1);
u32 func_004125d0(int param_1);
s32 func_0041f208(int param_1);
u32 func_0041f6e0(u32 *param_1);
u32 func_0041f6f0(u32 *param_1);

/* Source unit: src/rw/rwcore_003e8110.c (1 function markers) */

#pragma optimization_level 3
// FUN_003E8110
u32 func_003e8110(u32 camera)
{
    return ((u32 (*)(u32))*(u32 *)(camera + 0x1c))(camera);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e8120.c (1 function markers) */

#pragma optimization_level 3
// FUN_003E8120
u32 func_003e8120(u32 camera)
{
    return ((u32 (*)(u32))*(u32 *)(camera + 0x18))(camera);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9240.c (1 function markers) */
#pragma optimization_level 3
struct RwObjectOwnerLink {
    u8 padding[0xa0];
    RwObject *owner;
};
struct RwObject {
    u8 padding[3];
    u8 type;
};

// FUN_003E9240
u8 func_003e9240(RwObjectOwnerLink *param_1)
{
    return param_1->owner->type & 3;
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_003e9750.c (1 function markers) */
#pragma optimization_level 3

// FUN_003E9750
u32 func_003e9750(int param_1)
{
    return *(u32 *)(param_1 + 0xa0);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004125d0.c (1 function markers) */
#pragma optimization_level 3

// FUN_004125D0
u32 func_004125d0(int param_1)
{
    return *(u32 *)(param_1 + 0x20);
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f208.c (1 function markers) */
#pragma optimization_level 3

// FUN_0041F208
s32 func_0041f208(int param_1)
{
    return *(s32 *)(*(s32 *)(param_1 + 0x40) + 0x878) = 1;
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6e0.c (1 function markers) */
#pragma optimization_level 3

// FUN_0041F6E0
u32 func_0041f6e0(u32 *param_1)
{
    return param_1[3] = param_1[2];
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_0041f6f0.c (1 function markers) */
#pragma optimization_level 3

// FUN_0041F6F0
u32 func_0041f6f0(u32 *param_1)
{
    return param_1[2] = param_1[3];
}
#pragma optimization_level 2

/* Source unit: src/rw/rwcore_004222b0.c (1 function markers) */
#pragma optimization_level 3

// FUN_004222B0
asm u32 QueryIntrContext(void)
{
    .set noreorder
    mfc0 $v0, $12
    xori $v0, $v0, 1
    jr $ra
    andi $v0, $v0, 1
}
#pragma optimization_level 2

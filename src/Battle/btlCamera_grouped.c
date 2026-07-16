/* Grouped verified Persona 4 source units. */
/* The original guards were independently verified before grouping. */
#include "type.h"

/* Canonical grouped function declarations. */
u32 func_001d10d0(void* camera);

/* Source unit: src/Battle/btlCamera_001be8d0.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001BE8D0
void btlCameraSetDefaultDistanceA(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d05b0.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001D05B0
void btlCameraSetDefaultDistanceB(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d0670.c */

void FUN_001be050(f32 angle, f32 distance, void* camera);

// FUN_001D0670
void btlCameraSetDefaultDistanceC(void* camera)
{
    FUN_001be050(45.0f, 200.0f, camera);
}

/* Source unit: src/Battle/btlCamera_001d10d0.c */

// FUN_001D10D0
u32 func_001d10d0(void* camera)
{
    return (*(u16*)((u8*)camera + 0xE) & 1) != 0;
}

/* Source unit: src/Battle/btlCamera_001d12e0.c */

void FUN_0043f9c8(void* memory, s32 value, u32 size);

// FUN_001D12E0
void btlCameraResetWork(void* work)
{
    FUN_0043f9c8(work, 0, 0x14);
}

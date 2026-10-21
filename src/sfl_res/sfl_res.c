#include "include_asm.h"
#include "type.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

/* Vector ranges are contiguous: 0x10..0x1F, 0x20..0x2B, 0x2C..0x37. */
typedef struct SflResource {
    u8 pad00[0x10];
    Vec4 unk10;
    Vec3 unk20;
    Vec3 unk2C;
} SflResource;


/* Copy the resource's second three-component vector from the caller. */
// FUN_0036B5A0
void sflResSetSecondaryVector(void* work, const f32* value)
{
    ((SflResource*)work)->unk2C = *(const Vec3*)value;
}


/* Copy the resource's first three-component vector from the caller. */
// FUN_0036B5C0
void sflResSetPrimaryVector(void* work, const f32* value)
{
    ((SflResource*)work)->unk20 = *(const Vec3*)value;
}


/* Return the resource's second three-component vector through value. */
// FUN_0036B5E0
void sflResGetSecondaryVector(void* work, f32* value)
{
    *(Vec3*)value = ((const SflResource*)work)->unk2C;
}
/* Copy the resource's four-component vector from the caller. */
// FUN_0036B600
void sflResSetVector(void* work, const f32* value)
{
    ((SflResource*)work)->unk10 = *(const Vec4*)value;
}

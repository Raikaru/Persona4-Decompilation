/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0036B5A0)
/* Source unit: src/sfl_res/sfl_res_0036b5a0.c (1 function markers) */
#include "type.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

// FUN_0036B5A0
void func_0036b5a0(void* work, const f32* value)
{
    *(Vec3*)((u8*)work + 0x2c) = *(const Vec3*)value;
}
#endif /* P4_UNIT_0036B5A0 */

#if defined(P4_UNIT_0036B5C0)
/* Source unit: src/sfl_res/sfl_res_0036b5c0.c (1 function markers) */
#include "type.h"

typedef struct Vec3 {
    f32 x;
    f32 y;
    f32 z;
} Vec3;

// FUN_0036B5C0
void func_0036b5c0(void* work, const f32* value)
{
    *(Vec3*)((u8*)work + 0x20) = *(const Vec3*)value;
}
#endif /* P4_UNIT_0036B5C0 */

#if defined(P4_UNIT_0036B600)
/* Source unit: src/sfl_res/sfl_res_0036b600.c (1 function markers) */
#include "type.h"

typedef struct Vec4 {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} Vec4;

// FUN_0036B600
void func_0036b600(void* work, const f32* value)
{
    *(Vec4*)((u8*)work + 0x10) = *(const Vec4*)value;
}
#endif /* P4_UNIT_0036B600 */

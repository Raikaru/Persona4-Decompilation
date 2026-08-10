/* Source unit: src/sfl_res/sfl_res_0036b5a0.c (1 function markers) */
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



// FUN_0036B5A0
void func_0036b5a0(void* work, const f32* value)
{
    *(Vec3*)((u8*)work + 0x2c) = *(const Vec3*)value;
}



// FUN_0036B5C0
void func_0036b5c0(void* work, const f32* value)
{
    *(Vec3*)((u8*)work + 0x20) = *(const Vec3*)value;
}



// FUN_0036B5E0
void func_0036b5e0(void* work, f32* value)
{
    *(Vec3*)value = *(const Vec3*)((u8*)work + 0x2c);
}
// FUN_0036B600
void func_0036b600(void* work, const f32* value)
{
    *(Vec4*)((u8*)work + 0x10) = *(const Vec4*)value;
}

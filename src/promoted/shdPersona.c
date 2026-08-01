/* Consolidated Persona 4 source units. */
/* Original translation unit shdPersona.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

void func_0011e230(s32);
void func_0011e3c0(s32, s32);

typedef struct {
    f32 x;
    f32 y;
} Vec2f;

extern void (*jtbl_008873EC[])(u8 *);



// FUN_0011D100
void func_0011d100(u8 *arg0, f32 *arg1)
{
    u8 *temp_3;

    temp_3 = *(u8 **)(arg0 + 0x38);
    if (arg1 == NULL) {
        *(f32 *)(temp_3 + 0x4FC) = 0.0f;
        *(f32 *)(temp_3 + 0x500) = 0.0f;
        return;
    }
    *(f32 *)(temp_3 + 0x4FC) = arg1[0];
    *(f32 *)(temp_3 + 0x500) = arg1[1];
}



// FUN_0011D170
void func_0011d170(u8 *arg0, s32 arg1, s32 arg2)
{
    func_0011e230(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8));
    func_0011e3c0(*(s32 *)(*(u8 **)(arg0 + 0x38) + 0x4F8), arg2);
}



// FUN_0011DE80
f32 func_0011de80(u8 *arg0, Vec2f *arg1)
{
    u8 *temp_2;

    temp_2 = *(u8 **)(arg0 + 0x38);
    *arg1 = *(Vec2f *)(temp_2 + 0x28);
    return (f32)(*(s32 *)(temp_2 + 0x10)) / 10.0f;
}



// FUN_0011DF90
void func_0011df90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}



// FUN_0011FB90
void func_0011fb90(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}

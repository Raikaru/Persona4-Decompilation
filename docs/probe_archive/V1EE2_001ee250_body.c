#include "include_asm.h"
#include "type.h"

extern void func_00195850(u8 *arg0, f32 *arg1);
extern void func_001ec790(void *work, s32 x, s32 z, f32 radius);
extern u8 *iGpffffb3ac;

// FUN_001EE250
void func_001ee250(u8 *arg0, u8 *arg1) {
    f32 center[3];
    f32 radius;
    s32 x;
    s32 z;
    s32 tileX;
    s32 tileZ;

    func_00195850(arg0, center);
    radius = *(f32 *)(arg0 + 0x90) * *(f32 *)(arg0 + 0x2C);
    x = (s32)(center[0] + 1750.0f);
    z = (s32)(center[2] + 1750.0f);
    tileX = x / 25;
    tileZ = z / 25;
    if (x % 25 >= 13)
        tileX++;
    if (z % 25 >= 13)
        tileZ++;
    func_001ec790(arg0, tileX, tileZ, radius);
    if (arg1 != 0) {
        *(f32 *)(arg1 + 0) = (f32)(tileX * 25 - 1750);
        *(s32 *)(arg1 + 4) = 0;
        *(f32 *)(arg1 + 8) = (f32)(tileZ * 25 - 1750);
    }
    *(s16 *)(arg0 + 0x508) = (s16)tileX;
    *(s16 *)(arg0 + 0x50A) = (s16)tileZ;
    *(f32 *)(arg0 + 0x50C) = radius;
    *(s32 *)(arg0 + 0x9C) |= 4;
    *(s32 *)(arg0 + 0x9D0) = 0;
    if (*(u8 **)(iGpffffb3ac + 0x318) != 0) {
        *(u8 **)(*(u8 **)(iGpffffb3ac + 0x318) + 0x4C8) = arg0 + 0x508;
        *(u8 **)(arg0 + 0x9D4) = *(u8 **)(iGpffffb3ac + 0x318);
    } else {
        *(u8 **)(arg0 + 0x9D4) = 0;
    }
    *(u8 **)(iGpffffb3ac + 0x318) = arg0 + 0x508;
}

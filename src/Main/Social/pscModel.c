/* Consolidated Persona 4 source units. */
/* Original translation unit pscModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "include_asm.h"
#include "type.h"

extern void* func_00457120(void);
extern void func_0046d730(u8 *file, s32 line);
extern u8 D_0064E480[];
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);

// FUN_003694D0
INCLUDE_ASM("asm/nonmatchings/pscModel", func_003694d0);




// FUN_0036A6B0
void func_0036a6b0(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    out[0] = panelScale * (camera[0] * (1.0f + (-source[0] / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-source[1] / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}



// FUN_0036A790
f32 func_0036a790(const f32* value, f32 scale)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    return (6.0f * value[11] * (f32)(size[0] >> 1)) / (panelScale * camera[0]);
}

// FUN_0036A820
void func_0036a820(u8 *arg0, s16 arg1)
{
    if (*(s32 *)(arg0 + 4) != 0) {
        func_0046d730(D_0064E480, 0x524);
    }
    *(u16 *)(arg0 + 0x174) = arg1;
}

// FUN_0036A880
void func_0036a880(u8 *arg0, s32 arg1, s32 arg2)
{
    if (*(s32 *)(arg0 + 4) != 1) {
        func_0046d730(D_0064E480, 0x52F);
    }
    *(s32 *)(arg0 + 0x170) = arg1;
    *(s32 *)(arg0 + 0x174) = arg2;
}
// FUN_0036A900
INCLUDE_ASM("asm/nonmatchings/pscModel", func_0036a900);
// FUN_0036AA20
INCLUDE_ASM("asm/nonmatchings/pscModel", func_0036aa20);

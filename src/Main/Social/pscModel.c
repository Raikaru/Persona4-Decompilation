/* Consolidated Persona 4 source units. */
/* Original translation unit pscModel.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"

extern void* func_00457120(void);
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);



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

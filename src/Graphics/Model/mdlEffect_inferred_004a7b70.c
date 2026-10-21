#include "mdl_effect_drawable_internal.h"
#include "btl_action_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} PolygonWindColor;
extern PolygonWindColor iGpffffbb64;
extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
extern u8 D_0071413C[];
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern f32 D_00922D80[];
extern u32 D_00922D90[];
extern f32 D_00922D94[];
extern f32 D_00922D98[];

extern u8 D_00714130[];
extern u8 D_00714140[];
extern u8 D_00714138[];
extern u8 D_00714010[];
extern u8 D_00714024[];
extern u8 D_00714020[];
extern u8 D_00714018[];

extern u8 D_00714144[];

extern void mdlEffectApplyShakeEnvelope(u8 *record, s32 elapsed);


extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void memcpy(void *dst, void *src, u32 size);
extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                          void *indices, s32 flags);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- the caller's (u16, s32) prototype is needed; the definition's (s32, void *)
// changes FlashQuadCopyAllocFromRecord's code.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
/* measured: scopes this function's optimizer settings separately from the rest of the file so
 * retail's instruction order is kept. */
#pragma push
/* measured: retail keeps the partial-product copy, its instruction order, unfilled delay slots, in-
 * loop half/zero constants, no extra preheader test, and normal calls instead of tail calls. */
#pragma tailcall off
#pragma pop
/* Allocate a 0x14-byte shake record, clear its duration and copy the remaining 0x10 bytes. */
// FUN_004A7B70
void *mdlEffectCloneShakeRecord(void *record)
{
    u8 *src;
    void *dst;

    src = (u8 *)record;
    chkmemAllocSiteTag(D_00714350, 0x249);
    dst = jtbl_008873E8[0](0x14, 0x40000);
    *(u32 *)dst = 0;
    memcpy((u8 *)dst + 4, src + 4, 0x10);
    return dst;
}

/* Clear the shake record duration. */
// FUN_004A7BF0
void mdlEffectResetShakeDuration(u8 *record)
{
    ((MdlEffectShakeRecord *)record)->duration = 0;
}

/* Compute the shake fade envelope and publish its axis amplitudes and active flag. */
// FUN_004A7C00
void mdlEffectApplyShakeEnvelope(u8 *record, s32 elapsed)
{
    f32 scaledValue;
    f32 fadeInDuration;
    f32 fadeOutDuration;
    f32 amplitude;
    f32 fade;
    s32 fadeOutTicks;
    s32 duration;
    s32 amplitudeWord;
    u32 frame;
    s32 interval;

    frame = elapsed;
    duration = ((MdlEffectShakeRecord *)record)->duration;
    fade = 1.0f;
    if (duration < (s32)frame) {
        if (duration != 0) {
            return;
        }
    }
    if (duration > 0) {
        interval = ((MdlEffectShakeRecord *)record)->fadeIn;
        if ((u32)frame < interval) {
            scaledValue = (f32)(s32)frame;
            fadeInDuration = (f32)(u32)interval;
            fade = scaledValue / fadeInDuration;
        } else {
            fadeOutTicks = ((MdlEffectShakeRecord *)record)->fadeOut;
            if ((u32)(duration - fadeOutTicks) < (u32)frame) {
                if (fadeOutTicks != 0) {
                    interval = duration - (s32)frame;
                    scaledValue = (f32)interval;
                    fadeOutDuration = (f32)(u32)fadeOutTicks;
                    fade = scaledValue / fadeOutDuration;
                } else {
                    fade = 0.0f;
                }
            }
        }
    }
    amplitudeWord = ((MdlEffectShakeRecord *)record)->amplitude;
    amplitude = (f32)(u16)amplitudeWord;
    scaledValue = 10.0f * amplitude;
    fGpffffbb74 = scaledValue;
    fGpffffbb70 = (f32)((4.0f * scaledValue) / 10.0f);
    iGpffffb10c = fade;
    iGpffffbb68 = 1;
}


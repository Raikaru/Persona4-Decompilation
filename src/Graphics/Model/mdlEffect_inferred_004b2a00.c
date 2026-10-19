#include "mdl_effect_drawable_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "btl_shuffle_draw_internal.h"
#include "effect_update_internal.h"
#include "effect_vu0_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern s32 kwlnGetCamera(void);
extern s32 iGpffffbb9c;
/* gp - 0x4460 = 0x00764c90: base of a 0x1C-strided per-type handler table */
extern u8 *iGpffffbba0;
/* gp - 0x445C = 0x00764c94: enable predicate, called through the pointer */
extern s32 (*iGpffffbba4)(void);


extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Code1_004bColor;
extern Code1_004bColor iGpffffbb64;

/* Framed tail-jump compiler floors (24-byte save/restore/jump windows):
   func_004bd628, func_004bd640, func_004bd658, func_004bd670,
   func_004bd688, and func_004bd6a0.  Plain C cannot emit this ABI shape. */



extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *input, s32 value);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 input, u32 value);
extern s32 RpSkyRenderStateSet(s32 command, void *value);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

/* Source unit: src/promoted/code1_004b.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004b.c; members 004b2a00-004b2a00 */

extern s32 effCrossfadeCaptureDisplay(u8 *input);
#pragma push
#pragma pop
/* measured: close the opt_propagation bracket around func_004b2780. */
/* Native b210 recovery: 1016 executable bytes and eight zero alignment bytes.
   Native unsigned conversions retain the retail paths. The raster declaration
   precedes opacity, and the render-state table keeps its address while each
   call reloads its callback. Four PS2 vertices own the complete draw buffer.
   For initialized positive-duration state 3, elapsed is below duration.
   Float operation order is retained. See Crossfade_004b2a00_20260922.md. */
/* Draw the stored camera raster over the screen with alpha falling from 255 over the fade duration. */
// FUN_004B2A00
#pragma push
void mdlEffectDrawCameraFade(u8 *fade) {
    BtlShuffleSkyVertex vertices[4];
    u8 *raster;
    s32 opacity;
    f32 screenDepth;
    f32 reciprocalFar;
    f32 alphaFloat;
    f32 duration;
    f32 alpha0;
    f32 alpha1;
    f32 alpha2;
    f32 alpha3;
    f32 colorValue;
    s32 addressMode;
    s32 vertexCount;
    u32 elapsed;
    s32 durationFrames;
    s32 convertedAlpha;
    uintptr_t stateInterface;

    elapsed = ((MdlEffectFade *)fade)->elapsed;
    alphaFloat = (f32)(u32)elapsed;
    durationFrames = ((MdlEffectFade *)fade)->duration;
    duration = (f32)(u32)durationFrames;
    alphaFloat = 255.0f * (1.0f - (alphaFloat / duration));
    convertedAlpha = (u8)alphaFloat;
    opacity = convertedAlpha & 0xFF;
    raster = (u8 *)((MdlEffectCamera *)((MdlEffectFade *)fade)->camera)->raster;
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    stateInterface = (uintptr_t)D_00887300;
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)0xE, (void *)0);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)6, (void *)0);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)8, (void *)0);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)9, (void *)2);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)0xC, (void *)1);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)1, (void *)(u32)raster);
    addressMode = 3;
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)addressMode, (void *)addressMode);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)4, (void *)3);
    screenDepth = *(f32 *)D_008872FC_abs;
    reciprocalFar = 1.0f / ((MdlEffectCamera *)((u8 *)(u32)kwlnGetCamera()))->farPlane;
    vertices[0].u.els.scrVertex.x = 0.0f;
    vertices[0].u.els.scrVertex.y = 0.0f;
    vertices[0].u.els.scrVertex.z = screenDepth;
    colorValue = 255.0f;
    vertices[0].u.els.color.r = colorValue;
    vertices[0].u.els.color.g = colorValue;
    vertices[0].u.els.color.b = colorValue;
    alpha0 = (f32)(u32)opacity;
    vertices[0].u.els.color.a = alpha0;
    vertices[0].u.els.recipZ = reciprocalFar;
    vertices[0].u.els.u = 0.0f;
    vertices[0].u.els.v = 0.0f;
    vertices[1].u.els.scrVertex.x = 0.0f;
    vertices[1].u.els.scrVertex.y = 448.0f;
    vertices[1].u.els.scrVertex.z = screenDepth;
    colorValue = 255.0f;
    vertices[1].u.els.color.r = colorValue;
    vertices[1].u.els.color.g = colorValue;
    vertices[1].u.els.color.b = colorValue;
    alpha1 = (f32)(u32)opacity;
    vertices[1].u.els.color.a = alpha1;
    vertices[1].u.els.recipZ = reciprocalFar;
    vertices[1].u.els.u = 0.0f;
    vertices[1].u.els.v = 1.0f;
    vertices[2].u.els.scrVertex.x = 640.0f;
    vertices[2].u.els.scrVertex.y = 0.0f;
    vertices[2].u.els.scrVertex.z = screenDepth;
    colorValue = 255.0f;
    vertices[2].u.els.color.r = colorValue;
    vertices[2].u.els.color.g = colorValue;
    vertices[2].u.els.color.b = colorValue;
    alpha2 = (f32)(u32)opacity;
    vertices[2].u.els.color.a = alpha2;
    vertices[2].u.els.recipZ = reciprocalFar;
    vertices[2].u.els.u = 1.0f;
    vertices[2].u.els.v = 0.0f;
    vertices[3].u.els.scrVertex.x = 640.0f;
    vertices[3].u.els.scrVertex.y = 448.0f;
    vertices[3].u.els.scrVertex.z = screenDepth;
    colorValue = 255.0f;
    vertices[3].u.els.color.r = colorValue;
    vertices[3].u.els.color.g = colorValue;
    vertices[3].u.els.color.b = colorValue;
    alpha3 = (f32)(u32)opacity;
    vertices[3].u.els.color.a = alpha3;
    vertices[3].u.els.recipZ = reciprocalFar;
    colorValue = 1.0f;
    vertices[3].u.els.u = colorValue;
    vertices[3].u.els.v = colorValue;
    vertexCount = 4;
    D_00887310_abs[0](rwPRIMTYPETRISTRIP, vertices, vertexCount);
    (*(BtlShuffleRenderStateSet *)stateInterface)((RwRenderState)1, (void *)0);
}
#pragma pop

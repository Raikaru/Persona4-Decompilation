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
extern void LineNovaUpdateCameraQuads(void);

/* func_004bd628, func_004bd640, func_004bd658, func_004bd670, func_004bd688 and func_004bd6a0 are
 * framed tail-jump wrappers that plain C cannot emit. */


extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 effect, u32 value);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

extern s32 effCrossfadeCaptureDisplay(u8 *object);
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Store the global battle-effect value. */
// FUN_004B3250
void mdlEffectSetGlobalValue(s32 value)
{
    iGpffffbb9c = value;
}

/* Apply the global material tint, install the camera-quad callback and bind the owning effect. */
// FUN_004B3260
void mdlEffectPrepareLineNova(u8 *effect) {
    u8 *work;
    u8 *geometry;
    u8 *dst;

    work = ((MdlEffectLineNovaRecord *)effect)->work;
    geometry = ((MdlEffectWindWork *)work)->geometry;
    if (iGpffffbb64.c3 != 0xFF) {
        dst = ((EffGeometryBlock *)geometry)->material;
        *(Code1_004bColor *)&((RpMaterial *)dst)->color = iGpffffbb64;
    } else {
        iGpffffbb64.c3 = 0xFE;
        dst = ((EffGeometryBlock *)geometry)->material;
        *(Code1_004bColor *)&((RpMaterial *)dst)->color = iGpffffbb64;
        iGpffffbb64.c3 = 0xFF;
    }
    *(void (**)(void))(geometry + 0x20) = LineNovaUpdateCameraQuads;
    /* The draw callback follows the geometry block's owner back-pointer to this instance. */
    ((EffGeometryBlock *)geometry)->owner = effect;
}


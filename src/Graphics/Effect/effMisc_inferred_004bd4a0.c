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

/* func_004bd628 through func_004bd6a0 are framed tail-jump wrappers kept as assembly; plain C
 * cannot emit this shape. */


extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern u8 D_00714658[];

extern u8 D_007568C8[];
extern u8 D_00756900[];
extern void func_004bd6a0(u8 *object, s32 value);
extern f32 iGpffff836c;
extern u8 iGpffffb118;
extern u8 D_00713408[];
extern void *(*jtbl_008873E8[])(u32 size, u32 alignment);
extern u8 D_008872FC_abs[];
extern BtlShuffleRenderStateSet D_00887300[];
extern BtlShuffleRenderPrimitive D_00887310_abs[];

extern void (*jtbl_008873EC[])(void *);
/* The six framed tail-jump wrappers listed above are intentionally retained
   as assembly fallbacks; all ordinary small wrappers below are source-backed. */

typedef struct {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} EffMiscVector;
#pragma push
#pragma pop
#pragma push
#pragma pop
/* Normalize both quaternions and return their clamped dot product, not acos. Identical normalized
 * inputs take the explicit zero-return path in retail. */
// FUN_004BD4A0
f32 effMiscQuatAngle(u8 *firstQuaternion, u8 *secondQuaternion)
{
    EffMiscVector a;
    EffMiscVector b;
    f32 firstLength;
    f32 secondLength;
    f32 dot;

    a = *(EffMiscVector *)firstQuaternion;
    b = *(EffMiscVector *)secondQuaternion;
    firstLength = a.x * a.x + a.y * a.y + a.z * a.z + a.w * a.w;
    firstLength = __sqrt(firstLength, 0.0f);
    a.x = a.x / firstLength;
    a.y = a.y / firstLength;
    a.z = a.z / firstLength;
    a.w = a.w / firstLength;
    secondLength = b.x * b.x + b.y * b.y + b.z * b.z + b.w * b.w;
    secondLength = __sqrt(secondLength, 0.0f);
    b.x = b.x / secondLength;
    b.y = b.y / secondLength;
    b.z = b.z / secondLength;
    b.w = b.w / secondLength;
    if ((a.x == b.x) && (a.y == b.y) && (a.z == b.z) && (a.w == b.w)) {
        return 0.0f;
    }
    dot = a.x * b.x + a.y * b.y + a.z * b.z + a.w * b.w;
    if (dot > 1.0f) {
        dot = 1.0f;
    } else if (dot < -1.0f) {
        dot = -1.0f;
    }
    return dot;
}


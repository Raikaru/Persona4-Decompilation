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


// lint: allow H011 -- callers need the (u16, s32) shape; the definition's (s32, void *) signature
// changes their code.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
#pragma push
/* measured: O3 merges the partial-product copy before forming the multiply-add, which retail does
 * not do. measured: retail keeps its own instruction order and leaves delay slots unfilled.
 * measured: retail rebuilds the half value and the zero inside the loop. measured: retail has no
 * extra loop preheader test. measured: retail uses plain calls and returns, with no tail-call
 * conversion. */
#pragma tailcall off
#pragma pop
/* Resolve the source parameters and copy them into a new 0x14-byte shake record with a cleared duration. */
// FUN_004A7A90
void *mdlEffectCreateRecordFromRelPtrA(void *source)
{
    u8 *src;
    void *dst;

    src = mdlEffectResolveRelPtrA(source);
    chkmemAllocSiteTag(D_00714350, 0x249);
    dst = jtbl_008873E8[0](0x14, 0x40000);
    *(u32 *)dst = 0;
    memcpy((u8 *)dst + 4, src, 0x10);
    return dst;
}


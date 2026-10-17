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
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
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



extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.
extern u8 *FlashQuadCopyAlloc(u16 arg0, s32 arg1);

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a1950-004a1950 */

// Allocates a flash quad copy from a record: kind at +0x38 and parameters at +0x40, with the kind's table hooks applied to the result. Unlike FlashQuadCopyAllocFromParent, no relative pointer is resolved.
// FUN_004A1950
void *FlashQuadCopyAllocFromRecord(void *source) {
    u8 *arg0 = (u8 *)source;
    s32 index;
    s32 stride;
    u8 *result;
    s32 temp;

    index = *(s32 *)(arg0 + 0x38);
    if (*(s32 *)(D_0071401C + (index * 0x1C)) == 0) {
        temp = *(s32 *)(arg0 + 0x40);
        index = (u16)index;
        result = FlashQuadCopyAlloc((u16)index, temp);
        stride = (u16)index * 0x1C;
        *(s32 *)(result + 0x3C) =
            (*(s32 (**)(s32, s32))(D_00714014 + stride))(temp, 0);
        (*(void (**)(u8 *))(D_00714010 + stride))(result);
    } else {
        result = FlashQuadCopyAlloc((u16)index, *(s32 *)(arg0 + 0x40));
        *(s32 *)(result + 0x3C) =
            (*(s32 (**)(u8 *))(D_0071401C + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
        (*(void (**)(u8 *))(D_00714010 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(result);
    }
    return result;
}


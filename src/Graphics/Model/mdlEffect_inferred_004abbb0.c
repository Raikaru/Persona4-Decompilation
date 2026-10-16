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
extern u8 *mdlEffectCreateGridForRecord(u8 *arg0);
extern u8 D_0071413C[];
extern f32 iGpffff8080;
extern void mdlDestroyModelObject();


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
extern void mdlInitIdentityMatrix(void *arg0);
extern s32 mdlLayerIsPresent(void *arg0, s32 arg1);
extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
extern void mdlSetResetCallback(void *arg0, void (*arg1)(void), void *arg2);
extern void EffModelResetCallback(void);
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *mdlFindModelObject(u32 arg0, u16 arg1, u32 arg2);
extern void *mdlCreateModelObjectFromMemory(u32 arg0, u16 arg1, void *arg2, u32 arg3, u32 arg4);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Source unit: src/promoted/code1_004a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004a.c; members 004abbb0-004abd60 */

extern s32 mdlEffectProjectBillboardQuad(u8 *arg0, u8 *arg1);
extern void func_004a8250(u8 *arg0, u8 *arg1);
extern void func_004a8440(u8 *arg0, u8 *arg1);
extern void func_004a86c0(u8 *arg0, u8 *arg1);
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: close loop-invariant hoisting after mdlEffectCreateGridForRecord. */
#pragma push
#pragma tailcall off
/* measured: restore the enclosing options; owner verification is 92/92 MATCH. */
#pragma pop
/* measured: loop-invariant conversion preloads for func_004a7e30. */
/* measured: close the loop-invariant bracket after func_004a7e30. */
/* measured: loop-invariant conversion preloads for func_004a8250. */
/* measured: close loop-invariant conversion scope for func_004a8250. */
/* measured: loop-invariant conversion preloads for func_004a8440. */
/* measured: close loop-invariant conversion scope for func_004a8440. */
/* measured: loop-invariant conversion preloads for func_004a86c0. */
/* measured: close loop-invariant conversion scope for func_004a86c0. */
// FUN_004ABBB0
void func_004abbb0(u8 *arg0)
{
    mdlInitIdentityMatrix(arg0);
    if (mdlLayerIsPresent(arg0, 0) != 0) {
        mdlDispatchAnimIfPresent(arg0, 0, 0, 0, 0);
        mdlSetLayerWeight(arg0, 0, 1.0f);
    }
    *(s32 *)(arg0 + 0xD8) &= ~2;
    mdlSetResetCallback(arg0, EffModelResetCallback, arg0);
}

/* Measured: scoped propagation preserves constant-first model lookup arguments. */
#pragma push
// FUN_004ABC50
u8 *func_004abc50(u8 *arg0, s32 arg1)
{
    u8 *temp_2;
    u32 lookupType;

    goto loop_004abc50_check;
loop_004abc50_body:
    iGpffffbb90 += 1;
loop_004abc50_check:
    lookupType = 6;
    if (mdlFindModelObject(lookupType, iGpffffbb90, 0) != 0) {
        goto loop_004abc50_body;
    }
    temp_2 = mdlCreateModelObjectFromMemory(6, iGpffffbb90, arg0, (u32)arg1, 1);
    mdlInitIdentityMatrix(temp_2);
    if (mdlLayerIsPresent(temp_2, 0) != 0) {
        mdlDispatchAnimIfPresent(temp_2, 0, 0, 0, 0);
        mdlSetLayerWeight(temp_2, 0, 1.0f);
    }
    *(s32 *)(temp_2 + 0xD8) &= ~2;
    mdlSetResetCallback(temp_2, EffModelResetCallback, temp_2);
    iGpffffbb90 += 1;
    return temp_2;
}

#pragma pop
// FUN_004ABD60
void func_004abd60(void)
{
    mdlDestroyModelObject();
}


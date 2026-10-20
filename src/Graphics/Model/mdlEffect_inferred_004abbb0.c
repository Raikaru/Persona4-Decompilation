#include "mdl_file_internal.h"
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

extern u16 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                          void *indices, s32 flags);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern void mdlInitIdentityMatrix(void *matrixWords);
extern s32 mdlLayerIsPresent(void *model, s32 layer);
extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
extern void mdlSetResetCallback(void *model, void (*size)(void), void *count);
extern void EffModelResetCallback(void);
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *mdlFindModelObject(u32 type, u16 id, u32 flags);
extern void *mdlCreateModelObjectFromMemory(u32 type, u16 id, void *memory, u32 size, u32 flags);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004abbb0-004abd60 */

extern s32 mdlEffectProjectBillboardQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectBuildRectQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectBuildOffsetQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectBuildDirectRectQuad(u8 *parameters, u8 *vertices);
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
/* Initialize the model transform and first animation layer, clear flag 2 and install the effect reset callback. */
// FUN_004ABBB0
void EffModelInit(u8 *model)
{
    mdlInitIdentityMatrix(model);
    if (mdlLayerIsPresent(model, 0) != 0) {
        mdlDispatchAnimIfPresent(model, 0, 0, 0, 0);
        mdlSetLayerWeight(model, 0, 1.0f);
    }
    ((MdlFileModel *)model)->flags &= ~2;
    mdlSetResetCallback(model, EffModelResetCallback, model);
}

/* Measured: scoped propagation preserves constant-first model lookup arguments. */
#pragma push
/* Find an unused type-six model ID, create from memory and initialize its first animation layer. */
// FUN_004ABC50
u8 *mdlEffectCreateUniqueModel(u8 *model, s32 size)
{
    u8 *createdModel;
    u32 lookupType;

    goto loop_004abc50_check;
loop_004abc50_body:
    iGpffffbb90 += 1;
loop_004abc50_check:
    lookupType = 6;
    if (mdlFindModelObject(lookupType, iGpffffbb90, 0) != 0) {
        goto loop_004abc50_body;
    }
    createdModel = mdlCreateModelObjectFromMemory(6, iGpffffbb90, model, (u32)size, 1);
    mdlInitIdentityMatrix(createdModel);
    if (mdlLayerIsPresent(createdModel, 0) != 0) {
        mdlDispatchAnimIfPresent(createdModel, 0, 0, 0, 0);
        mdlSetLayerWeight(createdModel, 0, 1.0f);
    }
    ((MdlFileModel *)createdModel)->flags &= ~2;
    mdlSetResetCallback(createdModel, EffModelResetCallback, createdModel);
    iGpffffbb90 += 1;
    return createdModel;
}

#pragma pop
/* Forward model destruction to mdlDestroyModelObject. */
// FUN_004ABD60
void mdlEffectDestroyModel(void)
{
    mdlDestroyModelObject();
}


#include "rw_camera_internal.h"
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
extern void kAssertFail(u8 *file, s32 line);
extern s32 func_003e9320(void);
extern s32 kwlnGetCamera(void);
extern void func_003e9830(s32 input, s32 value);
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
extern u8 *func_003e9c10(u8 *input, const f32 *translation, s32 combineOp);


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
/* Clear shake state, create its frame and attach that frame to the active camera frame. */
// FUN_004A77B0
void mdlEffectInitializeShakeFrame(void) {
    if (D_00724C70 != 0) {
        kAssertFail(D_00714350, 0x1E9);
    }
    D_00724C58 = 0;
    D_00724C5C = 0;
    D_00724C60 = 0;
    D_00724C64 = 0;
    D_00724C78[0] = 0.0f;
    D_00724C7C = 0.0f;
    D_00724C70 = func_003e9320();
    func_003e9830(D_00724C70, *(s32 *)&((MdlEffectCamera *)(u32)kwlnGetCamera())->frame);
}

/* Randomize and clamp the two shake displacements, then translate the retained camera-relative
 * frame. */
// FUN_004A7830
#pragma push
/* measured: O3 merges the partial-product copy before the multiply-accumulate forms, as retail
 * does. */
#pragma optimization_level 3
/* measured: retail keeps its original instruction order and leaves branch delay slots unfilled. */
#pragma schedule off
/* measured: retail recomputes the half-value and the zero constant inside the loop instead of
 * hoisting them out. */
#pragma opt_loop_invariants off
/* measured: retail has no extra preheader test before the loop, so loop rotation stays off. */
#pragma opt_rotateloops off
/* measured: retail uses normal calls and returns here, not tail calls. */
#pragma tailcall off
/* measured: preserve the declared magnitude instead of CSE's late ABS temp. */
#pragma opt_common_subs off
/* measured: keeps the half-value computed before the RNG call and the explicit load snapshots from
 * being propagated away. */
#pragma opt_propagation off
void mdlEffectUpdateShakeFrame(void)
{
    f32 *axisThreshold;

    extern f32 fabsf(f32 input);
    f32 delta[2];
    f32 initial[2] = {0.6f, 0.6f};
    f32 vec[3];
    s32 idx;
    s32 axisOffset;
    f32 *axisDisplacement;
    f32 *axisAmplitude;
    f32 amplitude;
    f32 step;
    f32 horizontalDisplacement;
    f32 magnitude;
    f32 percentScale;
    f32 signZero;
    f32 displacement;
    f32 randomSample;
    u8 *cameraFrame;

    if (*(u8 *)&D_00724C58 == 0) {
        return;
    }
    *(u8 *)&D_00724C58 = 0;
    percentScale = 0.01f;
    delta[0] = percentScale * fGpffffbb70;
    delta[1] = percentScale * fGpffffbb74;
    for (idx = 0; idx < 2; idx++) {
        axisOffset = idx * 4;
        axisAmplitude = (f32 *)((u8 *)delta + axisOffset);
        amplitude = *axisAmplitude;
        if (amplitude != 0.0f) {
            step = 0.5f;
            randomSample = effMiscRandFloat(0);
            {
                const f32 weightedRandom = 0.5f * (amplitude * randomSample);
                signZero = 0.0f;
                step = step * amplitude + weightedRandom;
            }
            axisDisplacement = (f32 *)((u8 *)D_00724C78 + axisOffset);
            displacement = *axisDisplacement;
            magnitude = fabsf(displacement);
            if (!(magnitude < (amplitude * *(axisThreshold = (f32 *)((u8 *)initial + axisOffset))))) {
                if (displacement <= signZero) {
                    *axisDisplacement = displacement + step;
                } else {
                    *axisDisplacement = displacement - step;
                }
            } else {
                f32 random2 = effMiscRandFloat(0);
                magnitude = step * (random2 - 0.5f);
                *axisDisplacement = 0.0f + *axisDisplacement + 2.0f * magnitude;
            }
            displacement = -amplitude;
            if (*axisDisplacement < displacement) {
                *axisDisplacement = displacement;
            }
            if (!(*axisDisplacement <= amplitude)) {
                *axisDisplacement = amplitude;
            }
        }
    }
    cameraFrame = (u8 *)((RwCamera *)((u8 *)(u32)kwlnGetCamera()))->object.object.parent;
    horizontalDisplacement = D_00724C78[0];
    magnitude = iGpffffb10c;
    vec[0] = magnitude * ((((RwMatrixTag *)cameraFrame)->up.x) * horizontalDisplacement);
    vec[1] = magnitude * ((D_00724C7C) + (((RwMatrixTag *)cameraFrame)->up.y) * horizontalDisplacement);
    vec[2] = magnitude * ((((RwMatrixTag *)cameraFrame)->up.z) * horizontalDisplacement);
    func_003e9c10((u8 *)D_00724C70, vec, 0);
}
#pragma pop

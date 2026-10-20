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
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
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


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004a77b0-004a7830 */

extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: testing loop-invariant hoisting for the retail preheader. */
/* measured: close loop-invariant hoisting after mdlEffectCreateGridForRecord. */
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
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    func_003e9830(D_00724C70, *(s32 *)(((u8 *)(u32)kwlnGetCamera()) + 4));
}

/* Matched: 7 -> 2 -> 0 fnalign edits; 532/544 bytes, frame 0x70.
 * CSE/propagation off preserve the amplitude and scalar snapshots. Level 3's
 * early copy coalescer (004be350) removes weightedRandom's FCOPY before the
 * MULA peephole, leaving signZero between MULA and MADD as in retail.
 * Disable scheduling, loop-invariant hoisting and loop rotation. Keep the
 * magnitude/sign-reference/current declaration order for $f3/$f2/$f1.
 * The magnitude does not need an artificial post-comparison lifetime. */
/* Randomize and clamp the two shake displacements, then translate the retained camera-relative frame. */
// FUN_004A7830
/* measured: isolate this zero-edit pipeline from the other 91 functions. */
#pragma push
/* measured: O3 coalesces the partial-product copy before MULA formation. */
/* measured: func_004a7830 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 3
/* measured: retain retail instruction order and unfilled delay slots. */
/* measured: func_004a7830 MATCH -> MISMATCH without this pragma. */
#pragma schedule off
/* measured: keep the half-value and zero materializations inside the loop. */
/* measured: func_004a7830 MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants off
/* measured: disabling the extra preheader test closes the final 5 edits. */
/* measured: func_004a7830 MATCH -> MISMATCH without this pragma. */
#pragma opt_rotateloops off
/* measured: retain the baseline call/return policy in the zero-edit O3 scope. */
#pragma tailcall off
/* measured: preserve the declared magnitude instead of CSE's late ABS temp. */
/* measured: func_004a7830 MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: preserve the pre-RNG half-value and explicit load snapshots. */
/* measured: func_004a7830 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void mdlEffectUpdateShakeFrame(void)
{
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
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            if (!(magnitude < (amplitude * *(f32 *)((u8 *)initial + axisOffset)))) {
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

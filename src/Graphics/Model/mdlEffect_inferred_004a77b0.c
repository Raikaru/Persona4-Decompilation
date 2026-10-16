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
extern u8 *func_004a6c00(u8 *arg0);
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
extern void kAssertFail(u8 *arg0, s32 arg1);
extern s32 func_003e9320(void);
extern s32 func_00457120(void);
extern void func_003e9830(s32 arg0, s32 arg1);
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
extern u8 *func_003e9c10(u8 *arg0, const f32 *translation, s32 combineOp);



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


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes func_004a1950 MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Source unit: src/promoted/code1_004a.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004a.c; members 004a77b0-004a7830 */

extern u8 *func_004a6c00(u8 *arg0);
/* measured: the sibling 004a3010 body matches this loop and byte-copy shape. */
/* measured: closes the opt_loop_invariants scope for 004a1ca0 at the file baseline. */
/* measured: loop-invariant hoisting recovers the shared fade constants and
   replication strides. The 4-byte color assignment preserves retail's
   load-all/store-all byte copy. Separate loop locals keep the saved-register
   allocation exact. */
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: testing loop-invariant hoisting for the retail preheader. */
/* measured: close loop-invariant hoisting after func_004a6c00. */
// FUN_004A77B0
void func_004a77b0(void) {
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
    func_003e9830(D_00724C70, *(s32 *)(((u8 *)(u32)func_00457120()) + 4));
}

/* Matched: 7 -> 2 -> 0 fnalign edits; 532/544 bytes, frame 0x70.
 * CSE/propagation off preserve the amplitude and scalar snapshots. Level 3's
 * early copy coalescer (004be350) removes weightedRandom's FCOPY before the
 * MULA peephole, leaving signZero between MULA and MADD as in retail.
 * Disable scheduling, loop-invariant hoisting and loop rotation. Keep the
 * magnitude/sign-reference/current declaration order for $f3/$f2/$f1.
 * The magnitude does not need an artificial post-comparison lifetime. */
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
void func_004a7830(void)
{
    extern f32 fabsf(f32 arg0);
    f32 delta[2];
    f32 initial[2] = {0.6f, 0.6f};
    f32 vec[3];
    s32 idx;
    s32 temp_17;
    f32 *temp_16;
    f32 *axisAmplitude;
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f4;
    f32 temp_f3;
    f32 percentScale;
    f32 signZero;
    f32 temp_f1;
    f32 randomSample;
    u8 *temp_2;

    if (*(u8 *)&D_00724C58 == 0) {
        return;
    }
    *(u8 *)&D_00724C58 = 0;
    percentScale = 0.01f;
    delta[0] = percentScale * fGpffffbb70;
    delta[1] = percentScale * fGpffffbb74;
    for (idx = 0; idx < 2; idx++) {
        temp_17 = idx * 4;
        axisAmplitude = (f32 *)((u8 *)delta + temp_17);
        temp_f20 = *axisAmplitude;
        if (temp_f20 != 0.0f) {
            temp_f21 = 0.5f;
            randomSample = effMiscRandFloat(0);
            {
                const f32 weightedRandom = 0.5f * (temp_f20 * randomSample);
                signZero = 0.0f;
                temp_f21 = temp_f21 * temp_f20 + weightedRandom;
            }
            temp_16 = (f32 *)((u8 *)D_00724C78 + temp_17);
            temp_f1 = *temp_16;
            temp_f3 = fabsf(temp_f1);
            if (!(temp_f3 < (temp_f20 * *(f32 *)((u8 *)initial + temp_17)))) {
                if (temp_f1 <= signZero) {
                    *temp_16 = temp_f1 + temp_f21;
                } else {
                    *temp_16 = temp_f1 - temp_f21;
                }
            } else {
                f32 random2 = effMiscRandFloat(0);
                temp_f3 = temp_f21 * (random2 - 0.5f);
                *temp_16 = 0.0f + *temp_16 + 2.0f * temp_f3;
            }
            temp_f1 = -temp_f20;
            if (*temp_16 < temp_f1) {
                *temp_16 = temp_f1;
            }
            if (!(*temp_16 <= temp_f20)) {
                *temp_16 = temp_f20;
            }
        }
    }
    temp_2 = *(u8 **)(((u8 *)(u32)func_00457120()) + 4);
    temp_f4 = D_00724C78[0];
    temp_f3 = iGpffffb10c;
    vec[0] = temp_f3 * ((*(f32 *)(temp_2 + 0x10)) * temp_f4);
    vec[1] = temp_f3 * ((D_00724C7C) + (*(f32 *)(temp_2 + 0x14)) * temp_f4);
    vec[2] = temp_f3 * ((*(f32 *)(temp_2 + 0x18)) * temp_f4);
    func_003e9c10((u8 *)D_00724C70, vec, 0);
}


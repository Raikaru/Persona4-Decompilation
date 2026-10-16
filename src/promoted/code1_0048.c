#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

extern u_long128 mdlEffectStoreQuadA(s32 emitter, u32 *position);
extern u_long128 mdlEffectStoreQuadB(s32 emitter, u32 *rotation);
extern void func_003c02e0(u8 *arg0);
extern void func_003c4220(s32 arg0);
extern void func_003e9390(s32 arg0);
void func_003e9cb0(void *frame, void *matrix, u32 flags);
extern void func_004823e0(u8 *arg0);
extern void func_00481f30(u8 *arg0, s32 arg1);
extern void func_004861f0(u8 *arg0, f32 *arg1);
extern void effMiscQuatMultiplyVU(void);
extern void mdlEffectAimDirection(u8 *arg0, u8 *arg1);
extern f32 func_0044b920(f32 arg0);
extern f32 func_0044b950(f32 arg0, f32 arg1);
extern f32 fabsf(f32 value);
extern void effMiscEulerToQuatVU(f32 arg0, f32 arg1, f32 arg2);
extern void effMiscBuildRotationVU(void);
extern void func_00486400(u8 *arg0, f32 arg1);
extern void func_00484790(u8 *arg0);
extern void func_004847e0(u8 *arg0);
extern u8 *func_00482230(s32 *arg0);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
s32 TnGetOffset1C(s32 arg0);
extern void PrimAppendNode(s32 arg0, void *arg1);
extern void func_003c42b0(void *arg0, s32 arg1);
extern s32 func_003c2150(u8 *arg0, u8 *arg1, s32 arg2);
extern u8 *func_003c22f0(u8 *arg0);
extern u8 *GeometryCreateMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern s32 TnUploadStreamTagged(s32 arg0);
extern void func_003ef3a0(void *arg0);
extern void kAssertFail(void *file, s32 line);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern void func_00485630(u8 *arg0);
extern void func_00485870(u8 *arg0);
extern void func_00492d10(void *object);
extern void ParticleUpdateScaled(u8 *arg0, f32 arg1);
extern void ParticleProjectVertices(u8 *arg0, f32 arg1);
void GeometryMatrixBuildCombined();
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern void *memset(void *dst, s32 value, u32 size);
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;
extern void func_00494f90(u8 *arg0);
extern void func_00494740(u8 *arg0, u16 arg1, void *arg2, f32 arg3);
extern void func_004940d0(u8 *arg0, u16 arg1, void *arg2);
extern void func_00494ff0(u8 *arg0);


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_loop_invariants off














typedef struct Code48InitialState {
    f32 vector00[4];
    f32 vector10[4];
    u_long128 quad20;
    u8 unknown30[0x10];
    f32 vector40[4];
    f32 vector50[4];
    f32 scalar60;
    u32 word64;
    u32 word68;
    u32 unknown6c;
    u32 unknown70;
    f32 scalar74;
    u32 unknown78[2];
} Code48InitialState;
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma pop
extern void func_00486330(u8 *arg0, u8 *arg1);
extern void func_004865c0(u8 *arg0, s32 arg1);
#pragma opt_propagation off
#pragma opt_propagation on



/* Packed-word to VU bridge. $2 is quadword scratch; C owns addresses and storage. */
static inline void model_normalize_packed_color(const u32 *source, f32 scale)
{
    u32 scaleBits;
    __asm__ volatile(
        "lw $2, 0(%1)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2 $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 %0, %2\n"
        "nop\n"
        "qmtc2 %0, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        : "=&r"(scaleBits)
        : "r"(source), "f"(scale), "m"(*source)
        : "$2", "$vf2", "$vf10", "memory");
}

    #pragma optimization_level 1
    #pragma optimization_level 2
#pragma optimization_level 1
#pragma optimization_level 2
#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop
/* The fields consumed by the packed-color interpolator. */
typedef struct EffectPackedColorKeys {
    u8 mode;
    u8 pad01[3];
    u32 startColor;
    u32 endColor;
    u32 firstMiddleColor;
    f32 firstFraction;
    u32 secondMiddleColor;
    f32 secondFraction;
} EffectPackedColorKeys;

typedef struct EffectPackedOpacityKeys {
    u32 alpha;
    u32 field04;
    f32 fadeInFraction;
    f32 fadeOutFraction;
} EffectPackedOpacityKeys;

/* Fade against integer frame boundaries, retaining full opacity between ramps.
 * measured: the returning helper preserves native division-wait boundaries. */
static inline f32 effect_color_opacity(s32 frame, s32 duration, s32 fadeIn, s32 fadeOut, f32 fullOpacity)
{
    if (frame < fadeIn) {
        return (f32)frame / (f32)fadeIn;
    }
    if (fadeOut < frame) {
        return (f32)(duration - frame) / (f32)(duration - fadeOut);
    }
    return fullOpacity;
}

#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma opt_loop_invariants on

#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop

#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on

#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
/* Cone emitter: complete direction, aligned XYZ scale representation and
 * particle snapshots, with ordinary C random and integration calculations.
 * One real variation value is reused by the direction/speed/size/angle stages;
 * its measured lifetime and the scoped optimization inputs preserve retail.
 * Proof: docs/probe_archive/Cone_emitter_0048e2f0_20261005/README.md.
 * Native b210: 2244/2256 bytes, 20 resolved references, twelve zero tail bytes. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on

#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on

#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop

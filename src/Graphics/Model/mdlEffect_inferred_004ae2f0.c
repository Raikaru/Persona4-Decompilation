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

extern u16 *GeometryCreateTableGridMultiPart(s32 parameters, s32 entry, s32 elapsed, s32 flags,
                          void *data, s32 options);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004ae2f0-004ae2f0 */

extern s32 mdlEffectProjectBillboardQuad(u8 *parameters, u8 *entry);
extern void mdlEffectBuildRectQuad(u8 *parameters, u8 *entry);
extern void mdlEffectBuildOffsetQuad(u8 *parameters, u8 *entry);
extern void mdlEffectBuildDirectRectQuad(u8 *parameters, u8 *entry);
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
/* Measured: scoped propagation preserves constant-first model lookup arguments. */
#pragma push
#pragma pop
/* Interpolate the six-color palette by elapsed time and multiply it into the live VU color. */
// FUN_004AE2F0
void mdlEffectMultiplyPaletteColorVU(u8 *parameters, u8 *entry, s32 elapsed)
{
    s32 nextColor;
    s32 currentColor;
    s32 fixedColor;
    s32 colorIndex;
    s32 segmentDuration;
    s32 quotient;
    s32 remainder;
    f32 fraction;

    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    segmentDuration = *(s32 *)(parameters + 0x38) / 6;
    if (segmentDuration > 0) {
        __asm__ volatile(
            ".set noreorder\n"
            "vmove.xyzw $vf12, $vf10\n"
            ".set reorder\n"
            :
            :
            : "$vf12", "memory");
        quotient = elapsed / segmentDuration;
        remainder = elapsed % segmentDuration;
        fraction = (f32)remainder / (f32)segmentDuration;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        colorIndex = (*(s8 *)(entry + 0x14) + quotient) % 6;
        nextColor = ((s32 *)p4_add_u32(((colorIndex + 1) % 6) * 4, (u32)parameters))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lwc1 $f0, -0x7e0c($gp)\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "mfc1 $2, $f0\n"
            "nop\n"
            "qmtc2.ni $2, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            ".set reorder\n"
            :
            : "r"(&nextColor)
            : "$2", "$vf2", "$vf11", "memory");
        currentColor = ((s32 *)p4_add_u32(colorIndex * 4, (u32)parameters))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf10\n"
            "vitof0.xyzw $vf10, $vf10\n"
            "mfc1 $3, $f0\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            ".set reorder\n"
            :
            : "r"(&currentColor)
            : "$2", "$3", "$vf2", "$vf10", "memory");
        __asm__ volatile(
            ".set noreorder\n"
            "mfc1 $3, %0\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf10, $vf10, $vf2x\n"
            "mfc1 $3, %1\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vadd.xyzw $vf10, $vf10, $vf11\n"
            "vmove.xyzw $vf11, $vf12\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            ".set reorder\n"
            :
            : "f"(1.0f - fraction), "f"(fraction)
            : "$3", "$vf2", "$vf10", "$vf11", "$vf12", "memory");
    } else {
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        fixedColor = ((s32 *)p4_add_u32(*(s8 *)(entry + 0x14) * 4, (u32)parameters))[0xF];
        __asm__ volatile(
            ".set noreorder\n"
            "lw $3, -0x7e0c($gp)\n"
            "lw $2, 0(%0)\n"
            "pextlb $2, $0, $2\n"
            "pextlh $2, $0, $2\n"
            "qmtc2.ni $2, $vf11\n"
            "vitof0.xyzw $vf11, $vf11\n"
            "nop\n"
            "qmtc2.ni $3, $vf2\n"
            "vmulx.xyzw $vf11, $vf11, $vf2x\n"
            "vmul.xyzw $vf10, $vf10, $vf11\n"
            ".set reorder\n"
            :
            : "r"(&fixedColor)
            : "$2", "$3", "$vf2", "$vf10", "$vf11", "memory");
    }
}


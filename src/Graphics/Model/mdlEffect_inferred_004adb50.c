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
extern u8 *mdlEffectCreateGridForRecord(u8 *instance);
extern u8 D_0071413C[];
extern void func_004adb50();
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
 
extern s32 mdlCopyIndexedMatrix(u8 *instance, s32 value, u8 *count);
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 instance, s32 value, s32 count, s32 flags,
                          void *data, s32 options);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern void mdlSetLayerWeight(void *instance, s32 value, f32 count);
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004adb50-004adb50 */

extern s32 mdlEffectProjectBillboardQuad(u8 *instance, u8 *value);
extern void mdlEffectBuildRectQuad(u8 *instance, u8 *value);
extern void mdlEffectBuildOffsetQuad(u8 *instance, u8 *value);
extern void mdlEffectBuildDirectRectQuad(u8 *instance, u8 *value);
extern void mdlEffectUpdateAndDrawModelChildren(u8 *instance);
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
// FUN_004ADB50
/* measured: object 816B/window 816B, nd 0. K&R definition so the unprototyped
   caller func_004adfa0 stays byte-exact. The VU0 colour-pack island and the
   `color = *(s32 *)&packedColor` read are the effModel.c EffModelUpdate idiom - reading
   the packed word through its address is what makes b210 reload it into $s5
   right after the island and, with it, rank the saved registers as retail does
   (n $s4, instance $s3, objs $s2, count $s1, total $s0; a plain `color = packedColor`
   read left the load floating and flipped the whole ranking). Locals in
   declaration order; the loop is a goto loop with `objs++`; `zero` is a hoisted
   0.0f local ($f20); `t = call / 10.0f; speed = t * field` for the mul.s order. */
void func_004adb50(instance)
u8 *instance;
{
    extern void mdlEffectBuildBasisRows(void *instance, void *value);
    extern void mdlApplyModelMatrix(void *instance, void *value, s32 count);
    extern void mdlScale(void *instance, void *value, s32 count);
    extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
    extern void mdlAdvanceModelFromFlags(void *instance);
    extern s32 mdlEffectSamplePackedColor(u8 *instance, u8 *value, s32 count, s32 flags);
    extern f32 mdlEffectSampleScalarKeys(void *instance, u32 value, u32 count);
    extern void mdlEffectSetChildPositions(void *instance, f32 *value);
    extern void effMiscMatrixToQuatVU(f32 *instance);
    extern void mdlEffectSetChildRotations(void *instance, void *value);
    extern void mdlEffectSetChildScales(void *instance, f32 value);
    extern void mdlEffectApplyPackedColor(u8 *instance, s32 value);
    extern void mdlEffectCommitTreeFrame(void *instance);
    extern f32 D_00761134;
    s32 baseColor;
    s32 sampledColor;
    s32 packedColor;
    f32 vec[3];
    f32 pos[4];
    u8 out[0x10];
    u8 frame[0x40];
    f32 mat[16];
    u32 n;
    s32 *objs;
    s32 count;
    s32 total;
    u32 i;
    f32 uniformScale;
    f32 speed;
    s32 color;
    f32 scale;
    f32 zero;
    f32 t;
    s32 *pt;

    count = ((MdlEffectSpriteInstance *)instance)->age;
    total = ((MdlEffectSpriteInstance *)instance)->duration;
    n = ((MdlEffectSpriteInstance *)instance)->childCount;
    objs = ((MdlEffectSpriteInstance *)instance)->children;
    if (count < total || total == 0) {
        mdlEffectBuildBasisRows(frame, instance + 0x10);
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlApplyModelMatrix(*(void **)(instance + 0xA0), frame, 0);
        uniformScale = ((MdlEffectSpriteInstance *)instance)->scale;
        vec[2] = uniformScale;
        vec[1] = uniformScale;
        vec[0] = uniformScale;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlScale(*(void **)(instance + 0xA0), vec, 2);
        vec[0] = ((f32 *)((MdlEffectSpriteInstance *)instance)->position)[0];
        vec[1] = ((f32 *)((MdlEffectSpriteInstance *)instance)->position)[1];
        vec[2] = ((f32 *)((MdlEffectSpriteInstance *)instance)->position)[2];
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlTranslateMatrix((RwMatrix *)*(void **)(instance + 0xA0), (const RwV3d *)vec, 2);
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlSetLayerWeight(*(void **)(instance + 0xA0), 0, *(f32 *)&((MdlEffectSpriteInstance *)instance)->unk94);
        mdlAdvanceModelFromFlags((void *)((MdlEffectSpriteInstance *)instance)->model);
        if (((MdlEffectSpriteInstance *)instance)->drawable != 0) {
            color = mdlEffectSamplePackedColor(instance + 0x30, instance + 0x54, count, total);
            baseColor = ((MdlEffectSpriteInstance *)instance)->packedColor;
            pt = &baseColor;
            scale = D_00761134;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2.ni $2, $vf10   \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vmove.xyzw $vf11, $vf10 \n"
                :
                : "r"(pt), "f"(scale)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            sampledColor = color;
            __asm__ volatile(
                "lw $2, 0(%0)          \n"
                "pextlb $2, $0, $2     \n"
                "pextlh $2, $0, $2     \n"
                "qmtc2.ni $2, $vf10   \n"
                "vitof0.xyzw $vf10, $vf10 \n"
                "mfc1 $2, %1           \n"
                "nop                   \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vmul.xyzw $vf10, $vf10, $vf11 \n"
                "lui $2, 0x437F        \n"
                "qmtc2.ni $2, $vf2     \n"
                "vmulx.xyzw $vf10, $vf10, $vf2x \n"
                "vftoi0.xyzw $vf10, $vf10 \n"
                "qmfc2.ni $2, $vf10    \n"
                "ppach $2, $0, $2      \n"
                "ppacb $2, $0, $2      \n"
                "sw $2, 0x134($sp)     \n"
                :
                : "r"(&sampledColor), "f"(scale)
                : "$2", "$vf2", "$vf10", "$vf11", "memory");
            color = *(s32 *)&packedColor;
            t = mdlEffectSampleScalarKeys(instance + 0x64, count, total) / 10.0f;
            speed = t * ((MdlEffectSpriteInstance *)instance)->scale;
            i = 0;
            zero = 0.0f;
            goto loop_check;
loop_body:

                if (mdlCopyIndexedMatrix(((MdlEffectSpriteInstance *)instance)->model, i, frame) != 0) {
                    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
                    pos[0] = *(f32 *)(frame + 0x30);
                    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
                    pos[1] = *(f32 *)(frame + 0x34);
                    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
                    pos[2] = *(f32 *)(frame + 0x38);
                    pos[3] = zero;
                    mdlEffectSetChildPositions((void *)*objs, pos);
                    mat[0] = ((RwMatrixTag *)frame)->right.x;
                    mat[1] = ((RwMatrixTag *)frame)->right.y;
                    mat[2] = ((RwMatrixTag *)frame)->right.z;
                    mat[3] = zero;
                    mat[4] = ((RwMatrixTag *)frame)->up.x;
                    mat[5] = ((RwMatrixTag *)frame)->up.y;
                    mat[6] = ((RwMatrixTag *)frame)->up.z;
                    mat[7] = zero;
                    mat[8] = ((RwMatrixTag *)frame)->at.x;
                    mat[9] = ((RwMatrixTag *)frame)->at.y;
                    mat[10] = ((RwMatrixTag *)frame)->at.z;
                    mat[11] = zero;
                    mat[12] = ((RwMatrixTag *)frame)->pos.x;
                    mat[13] = ((RwMatrixTag *)frame)->pos.y;
                    mat[14] = ((RwMatrixTag *)frame)->pos.z;
                    mat[15] = zero;
                    effMiscMatrixToQuatVU(mat);
                    __asm__ volatile("sqc2 $vf10, 0(%0)" : : "r"(out) : "$vf10", "memory");
                    mdlEffectSetChildRotations((void *)*objs, out);
                    mdlEffectSetChildScales((void *)*objs, speed);
                    mdlEffectApplyPackedColor((void *)*objs, color);
                    mdlEffectCommitTreeFrame((void *)*objs);
                }
                i += 1;
                objs += 1;
loop_check:
                if (i < n) {
                    goto loop_body;
                }
        }
    }
    ((MdlEffectSpriteInstance *)instance)->age += 1;
}


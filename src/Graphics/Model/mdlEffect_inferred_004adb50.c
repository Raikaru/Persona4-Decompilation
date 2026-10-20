#include "rw_camera_internal.h"
#include "mdl_effect_drawable_internal.h"
#include "btl_action_internal.h"
#include "effect_geometry_internal.h"
#include "rw_geometry_internal.h"
#include "model_motion_internal.h"
#include "include_asm.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "member_access.h"
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
extern void mdlEffectUpdateModelChildTransforms();
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
 
extern s32 mdlCopyIndexedMatrix(u8 *model, s32 index, u8 *destination);
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                          void *indices, s32 flags);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- FlashQuadCopyAllocFromRecord depends on the caller's (u16, s32) shape; the
// definition's (s32, void *) changes its codegen.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

extern s32 mdlEffectProjectBillboardQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectBuildRectQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectBuildOffsetQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectBuildDirectRectQuad(u8 *parameters, u8 *vertices);
extern void mdlEffectUpdateAndDrawModelChildren(u8 *instance);
#pragma push
#pragma tailcall off
#pragma pop
/* measured: retail preloads loop-invariant conversions in func_004a7e30, func_004a8250,
 * func_004a8440 and func_004a86c0, and keeps constant-first model lookup arguments. */
#pragma push
#pragma pop
/* Animate the source model and propagate its indexed transforms, sampled scale and color to child trees. */
// FUN_004ADB50
/* K&R definition because func_004adfa0 calls it unprototyped; reading color through its address
 * keeps retail's reload and saved-register order. */
void mdlEffectUpdateModelChildTransforms(instance)
u8 *instance;
{
    extern void mdlEffectBuildBasisRows(void *output, void *orientation);
    extern void mdlApplyModelMatrix(void *model, void *matrix, s32 combineOp);
    extern void mdlScale(void *model, void *scale, s32 combineOp);
    extern RwMatrix *mdlTranslateMatrix(RwMatrix *matrix, const RwV3d *translation, int combineOp);
    extern void mdlAdvanceModelFromFlags(void *model);
    extern s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
    extern f32 mdlEffectSampleScalarKeys(void *keys, u32 frame, u32 duration);
    extern void mdlEffectSetChildPositions(void *effect, f32 *value);
    extern void effMiscMatrixToQuatVU(f32 *matrix);
    extern void mdlEffectSetChildRotations(void *effect, void *value);
    extern void mdlEffectSetChildScales(void *effect, f32 value);
    extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
    extern void mdlEffectCommitTreeFrame(void *effect);
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
    MdlEffectSpriteInstance *sprite;

    sprite = (MdlEffectSpriteInstance *)instance;
    count = ((MdlEffectSpriteInstance *)instance)->age;
    total = ((MdlEffectSpriteInstance *)instance)->duration;
    n = ((MdlEffectSpriteInstance *)instance)->childCount;
    objs = ((MdlEffectSpriteInstance *)instance)->children;
    if (count < total || total == 0) {
        mdlEffectBuildBasisRows(frame, instance + 0x10);
        mdlApplyModelMatrix((void *)sprite->model, frame, 0);
        uniformScale = ((MdlEffectSpriteInstance *)instance)->scale;
        vec[2] = uniformScale;
        vec[1] = uniformScale;
        vec[0] = uniformScale;
        mdlScale((void *)sprite->model, vec, 2);
        vec[0] = ((f32 *)((MdlEffectSpriteInstance *)instance)->position)[0];
        vec[1] = ((f32 *)((MdlEffectSpriteInstance *)instance)->position)[1];
        vec[2] = ((f32 *)((MdlEffectSpriteInstance *)instance)->position)[2];
        mdlTranslateMatrix((RwMatrix *)sprite->model, (const RwV3d *)vec, 2);
        mdlSetLayerWeight((void *)sprite->model, 0, *(f32 *)&((MdlEffectSpriteInstance *)instance)->unk94);
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
                    pos[0] = MEMBER(f32, frame, RwMatrixTag, pos.x);
                    pos[1] = MEMBER(f32, frame, RwMatrixTag, pos.y);
                    pos[2] = MEMBER(f32, frame, RwMatrixTag, pos.z);
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


#include "member_access.h"
#include "rw_camera_internal.h"
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
static inline u32 p4_add_u32(u32 left, u32 right)
{
    return left + right;
}
extern PolygonWindColor iGpffffbb64;
extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
extern u8 D_0071413C[];
extern s32 TnGetOffset38(u16 slotIndex);
extern void EffModelDrawableUpdate();
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern s32 kwlnGetCamera(void);
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


extern void mdlSetLayerTime(u8 *model, s32 layer, f32 frameValue);

extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 partCount, s32 rowCount, s32 trianglesPerRow, s32 verticesPerRow,
                          void *indices, s32 flags);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
extern u8 D_0071401C[];
extern u8 D_00714014[];


// lint: allow H011 -- measured: aligning this extern to the definition's (s32, void *) makes FlashQuadCopyAllocFromRecord MISMATCH (verify, 137/138); the caller's (u16, s32) shape is load-bearing.

extern u16 iGpffffbb90;
extern f32 fGpffffbb74;
extern f32 fGpffffbb70;
extern f32 iGpffffb10c;
extern s8 iGpffffbb68;
extern void *(*jtbl_008873E8[])(u32 size, u32 align);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_004a; members 004acb50-004ad450 */

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
/* Measured: scoped propagation preserves constant-first model lookup arguments. */
#pragma push
#pragma pop
/* Sets layer 0 time of the model object at +0xB4 to 0. */
// FUN_004ACB50
void EffModelDrawableResetLayerTime(u8 *drawable) {
    mdlSetLayerTime(((MdlEffectModelDrawable *)drawable)->model, 0, 0.0f);
}

/* Moves the layer time to the cycle window edge when the frame index passes it, and sets the progress at +0x08 to 1.0. */
// FUN_004ACB80
void EffModelDrawableRollCycle(u8 *drawable)
{
    extern f32 mdlGetLayerWeight(s32 model, s32 layer);
    f32 layerTime;
    u32 frameCount;
    u32 cycleEnd;
    u32 nextFrame;

    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    layerTime = mdlGetLayerWeight(MEMBER(s32, drawable, MdlEffectModelDrawable, model), 0);
    nextFrame = (u32)layerTime + 1;
    frameCount = ((MdlEffectModelDrawable *)drawable)->duration;
    if (frameCount >= nextFrame || frameCount == 0) {
        if (((MdlEffectModelDrawable *)drawable)->cycleMode == 1) {
            if (((MdlEffectModelDrawable *)drawable)->cycleEnd <= nextFrame) {
                mdlSetLayerTime(((MdlEffectModelDrawable *)drawable)->model, 0,
                              (f32)((MdlEffectModelDrawable *)drawable)->cycleStart - 1.0f);
            }
        } else if (((MdlEffectModelDrawable *)drawable)->cycleEnabled != 0 &&
                   (u32)((MdlEffectModelDrawable *)drawable)->cycleStart <= nextFrame) {
            cycleEnd = ((MdlEffectModelDrawable *)drawable)->cycleEnd;
            if (nextFrame < cycleEnd) {
                mdlSetLayerTime(((MdlEffectModelDrawable *)drawable)->model, 0,
                              (f32)(s32)cycleEnd - 1.0f);
            }
        }
        ((MdlEffectModelDrawable *)drawable)->progress = 1.0f;
    }
}

/* measured: an s64-aligned union gives retail's ld/lwc1 Vec3 copies; the
   three-argument helper signature keeps frame_index/frame_count in a1/a2. */
/* Per-frame draw callback on the model object: derives a screen-space scale and offset from the camera, rotates by +0x90/+0x94/+0x98, writes the translated origin into the model matrix, then updates the model matrix and item slots. */
// FUN_004ACCC0
void EffModelDrawCallback(u8 *drawable)
{
    struct Vec3 {
        f32 x;
        f32 y;
        f32 z;
    };
    union BasisConst {
        struct Vec3 value;
        s64 align;
    };
    struct Frame {
        f32 matrix[16];
        struct Vec3 transformed;
        s32 pad4c;
        struct Vec3 scale;
        s32 pad5c;
    };
    struct Vec3 basis1;
    struct Vec3 basis2;
    struct Vec3 basis3;
    struct Frame frame;
    extern union BasisConst D_007144C8[];
    extern union BasisConst D_007144D8[];
    extern union BasisConst D_007144E8[];
    extern f32 mdlGetLayerWeight(s32 model, s32 layer);
    extern f32 mdlEffectSampleScalarKeys(u8 *keys, s32 frame, s32 duration);
    extern u8 *func_003e9700(s32 drawable);
    extern u8 *mdlGetMatrix(s32 model);
    extern u8 *RwMatrixMultiply(void *drawable, void *state, void *count);
    extern void RwMatrixRotate(void *drawable, void *state, f32 fparg0, s32 count);
    extern void RwMatrixScale(void *drawable, void *state, s32 count);
    extern void func_003e4320(void *drawable, void *state, void *count);
    extern void mdlUpdateModelMatrix(s32 model);
    extern void mdlPrepareItemSlots(s32 model);
    s32 frame_count;
    u32 frame_index;
    u8 *node;
    u8 *camera;
    u8 *matrix;
    u8 *object;
    f32 depth;
    f32 width;
    f32 near_height;
    f32 scale;
    f32 far_z;
    f32 temp;

    basis1 = D_007144C8[0].value;
    basis2 = D_007144D8[0].value;
    basis3 = D_007144E8[0].value;
    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    frame_index = (u32)mdlGetLayerWeight(MEMBER(s32, drawable, MdlEffectModelDrawable, model), 0);
    frame_count = (s32)((MdlEffectModelDrawable *)drawable)->duration;
    if (frame_count >= (s32)frame_index || frame_count == 0) {
        scale = mdlEffectSampleScalarKeys(drawable + 0x44, frame_index, frame_count) / 10.0f;
        node = ((u8 *)(u32)kwlnGetCamera()) + 0x68;
        camera = ((u8 *)(u32)kwlnGetCamera());
        near_height = ((RwCamera *)camera)->nearPlane;
        camera = ((u8 *)(u32)kwlnGetCamera());
        far_z = ((RwCamera *)camera)->farPlane;
        depth = (((f32)-0xFFFF * near_height) * far_z) /
                (((f32)-0xFFFF * far_z) -
                 (-31.0f * (far_z - near_height)));
        width = 2.0f * (((f32 *)node)[0] * depth);
        near_height = 2.0f * (((f32 *)node)[1] * depth);
        camera = ((u8 *)(u32)kwlnGetCamera());
        matrix = func_003e9700((s32)((RwCamera *)camera)->object.object.parent);
        RwMatrixRotate(frame.matrix, &basis1,
                      ((MdlEffectModelDrawable *)drawable)->rotationX, 0);
        if (((MdlEffectModelDrawable *)drawable)->rotationY != 0.0f) {
            RwMatrixRotate(frame.matrix, &basis2,
                          ((MdlEffectModelDrawable *)drawable)->rotationY, 2);
        }
        if (((MdlEffectModelDrawable *)drawable)->rotationZ != 0.0f) {
            RwMatrixRotate(frame.matrix, &basis3,
                          ((MdlEffectModelDrawable *)drawable)->rotationZ, 2);
        }
        temp = (width / 640.0f) * scale;
        frame.scale.z = temp;
        frame.scale.y = temp;
        frame.scale.x = temp;
        RwMatrixScale(frame.matrix, &frame.scale, 2);
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        object = mdlGetMatrix(MEMBER(s32, drawable, MdlEffectModelDrawable, model));
        RwMatrixMultiply(object, frame.matrix, matrix);
        frame.scale.x =
            width * (0.5f + (-(f32)(((MdlEffectModelDrawable *)drawable)->x +
                                    ((MdlEffectModelDrawable *)drawable)->offsetX) /
                              640.0f));
        frame.scale.y =
            near_height * (0.5f + (-(f32)(((MdlEffectModelDrawable *)drawable)->y +
                                          ((MdlEffectModelDrawable *)drawable)->offsetY) /
                                    448.0f));
        frame.scale.z = ((MdlEffectModelDrawable *)drawable)->offsetZ + depth;
        func_003e4320(&frame.transformed, &frame.scale, matrix);
        scale = ((RwMatrixTag *)matrix)->pos.x + frame.transformed.x;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        object = mdlGetMatrix(MEMBER(s32, drawable, MdlEffectModelDrawable, model));
        ((RwMatrixTag *)object)->pos.x = scale;
        scale = ((RwMatrixTag *)matrix)->pos.y + frame.transformed.y;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        object = mdlGetMatrix(MEMBER(s32, drawable, MdlEffectModelDrawable, model));
        ((RwMatrixTag *)object)->pos.y = scale;
        scale = ((RwMatrixTag *)matrix)->pos.z + frame.transformed.z;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        object = mdlGetMatrix(MEMBER(s32, drawable, MdlEffectModelDrawable, model));
        ((RwMatrixTag *)object)->pos.z = scale;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlUpdateModelMatrix(MEMBER(s32, drawable, MdlEffectModelDrawable, model));
        mdlPrepareItemSlots((s32)((MdlEffectModelDrawable *)drawable)->model);
    }
}

/* measured: effModel EffModelUpdate VU0 colour-pack idiom with D_00761134 (1/255) scale; */
/* measured: plain `(u32)layerTime` gives retail's `lui $3,0x8000; or` (no D_80000001, unlike */
/* measured: the `+1` siblings); `appliedColor = *(s32 *)&packedColor` forces the packed word back through */
/* measured: memory so the `lw $2,0x50; sw $2,0x5C` copy survives and the saved ranking stays */
/* measured: drawable $s3, state $s2, frame_index $s1, frame_count $s0 with frame 0x60. */
/* measured: probe c: 0 differing words, object 528B/window 528B. */
/* Samples a packed colour with func_0048abd0, applies it to the model object at +0xB4, sets alpha-blend flags from +0xA0/+0xA4, sets the layer weight from +0x08, attaches the owner and queues the model for draw. */
// FUN_004AD030
void EffModelDrawableUpdate(s32 drawable, u8 *state)
{
    extern f32 mdlGetLayerWeight(s32 model, s32 layer);
    extern s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
    extern void mdlSetColor(void *model, s32 *color);
    extern f32 mdlEffectSampleScalarKeys(void *keys, u32 frame, u32 duration);
    extern void mdlSetLayerWeight(void *model, s32 layer, f32 speed);
    extern s32 TnGetTableBase(void);
    extern void mdlSetAttachedOwner(void *model, s32 owner);
    extern void mdlQueueModelForDraw(s32 queue, void *model);
    extern f32 D_00761134;
    s32 appliedColor;
    s32 baseColor;
    s32 sampledColor;
    s32 packedColor;
    f32 layerTime;
    u32 frame_index;
    u32 frame_count;
    s32 color;

    layerTime = mdlGetLayerWeight((s32)((MdlEffectModelDrawable *)state)->model, 0);
    frame_index = (u32)layerTime;
    frame_count = ((MdlEffectModelDrawable *)state)->duration;
    if ((frame_count >= frame_index) || (frame_count == 0)) {
        color = mdlEffectSamplePackedColor(state + 0x10, state + 0x34, frame_index, frame_count);
        baseColor = ((MdlEffectModelDrawable *)state)->packedColor;
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
            : "r"(&baseColor), "f"(D_00761134)
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
            "sw $2, 80($sp)        \n"
            :
            : "r"(&sampledColor), "f"(D_00761134)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        appliedColor = *(s32 *)&packedColor;
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlSetColor(MEMBER(u8 *, state, MdlEffectModelDrawable, model), &appliedColor);
        mdlEffectSampleScalarKeys(state + 0x44, frame_index, frame_count);
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        ((MdlFileModel *)MEMBER(u8 *, state, MdlEffectModelDrawable, model))->flags &= ~0x100;
        if ((((MdlEffectModelDrawable *)state)->blend != 0) && (((MdlEffectModelDrawable *)state)->blendMode == 0)) {
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            ((MdlFileModel *)*(u8 * *)&((MdlEffectModelDrawable *)state)->model)->flags |= 0x18;
        } else {
            /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
            ((MdlFileModel *)MEMBER(u8 *, state, MdlEffectModelDrawable, model))->flags &= ~0x18;
        }
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlSetLayerWeight(MEMBER(u8 *, state, MdlEffectModelDrawable, model), 0, ((MdlEffectModelDrawable *)state)->progress);
        /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
        mdlSetAttachedOwner(MEMBER(u8 *, state, MdlEffectModelDrawable, model), TnGetTableBase());
        mdlQueueModelForDraw(drawable, ((MdlEffectModelDrawable *)state)->model);
        /* The progress float is cleared through its integer zero bit pattern; retain that representation. */
        MEMBER(s32, state, MdlEffectModelDrawable, progress) = 0;
    }
}

/* Runs EffModelDrawableUpdate with the offset from TnGetOffset38(+0x38). */
// FUN_004AD240
void EffModelDrawableUpdateByOffset(u8 *drawable) {
    EffModelDrawableUpdate(TnGetOffset38(((MdlEffectModelDrawable *)drawable)->scene), drawable);
}

/* Rolls the cycle as EffModelDrawableRollCycle does, then runs EffModelDrawableUpdate with the offset from TnGetOffset38(+0x38). */
// FUN_004AD280
void EffModelDrawableRollAndUpdate(u8 *drawable)
{
    extern f32 mdlGetLayerWeight(s32 model, s32 layer);
    f32 layerTime;
    u32 nextFrame;
    u32 frameCount;
    u32 cycleEnd;

    /* measured: access-site typing changed owner MATCH to MISMATCH; retain the byte-shaped load/store for MWCC aliasing and scheduling. */
    layerTime = mdlGetLayerWeight(MEMBER(s32, drawable, MdlEffectModelDrawable, model), 0);
    nextFrame = (u32)layerTime + 1;
    frameCount = ((MdlEffectModelDrawable *)drawable)->duration;
    if (frameCount >= nextFrame || frameCount == 0) {
        if (((MdlEffectModelDrawable *)drawable)->cycleMode == 1) {
            if (((MdlEffectModelDrawable *)drawable)->cycleEnd <= nextFrame) {
                mdlSetLayerTime(((MdlEffectModelDrawable *)drawable)->model, 0,
                              (f32)((MdlEffectModelDrawable *)drawable)->cycleStart - 1.0f);
            }
        } else if (((MdlEffectModelDrawable *)drawable)->cycleEnabled != 0 &&
                   (u32)((MdlEffectModelDrawable *)drawable)->cycleStart <= nextFrame) {
            cycleEnd = ((MdlEffectModelDrawable *)drawable)->cycleEnd;
            if (nextFrame < cycleEnd) {
                mdlSetLayerTime(((MdlEffectModelDrawable *)drawable)->model, 0,
                              (f32)(s32)cycleEnd - 1.0f);
            }
        }
        ((MdlEffectModelDrawable *)drawable)->progress = 1.0f;
    }
    EffModelDrawableUpdate(TnGetOffset38(((MdlEffectModelDrawable *)drawable)->scene), drawable);
}

/* Copies the first two floats of state into +0x00 and +0x04 of the drawable. */
// FUN_004AD3E0
void EffModelDrawableSetPosition(u8 *drawable, f32 *state) {
    ((MdlEffectModelDrawable *)drawable)->x = state[0];
    ((MdlEffectModelDrawable *)drawable)->y = state[1];
}

/* Stores the lookup index at +0x0C of the drawable. */
// FUN_004AD400
void EffModelDrawableSetLookupIndex(u8 *drawable, s32 state) {
    ((MdlEffectModelDrawable *)drawable)->packedColor = state;
}

/* Returns 1 when no model object is attached or the model byte at +0xEE equals 1, otherwise 0. */
// FUN_004AD410
s32 EffModelDrawableIsFinished(u8 *drawable) {
    u8 *p;
    s32 result;
    p = ((MdlEffectModelDrawable *)drawable)->model;
    if (p != NULL) {
        result = (((MdlFileModel *)p)->finished ^ 1U) < 1U;
    } else {
        result = 1;
    }
    return result;
}

/* Returns nonzero when the cycle flag at +0xB8 of the drawable is set. */
// FUN_004AD440
s32 EffModelDrawableHasCycle(u8 *drawable) {
    return ((MdlEffectModelDrawable *)drawable)->cycleMode != 0;
}

/* Clears the cycle flag at +0xB8 of the drawable. */
// FUN_004AD450
void EffModelDrawableClearCycle(u8 *drawable) {
    ((MdlEffectModelDrawable *)drawable)->cycleMode = 0;
}


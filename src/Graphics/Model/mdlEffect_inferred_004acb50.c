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
extern s32 TnGetOffset38(u16 arg0);
extern void func_004ad030();
extern f32 iGpffff8080;


extern s32 D_00724C70;
extern s8 D_00724C58;
extern s16 D_00724C5C;
extern s32 D_00724C60;
extern s32 D_00724C64;
extern f32 D_00724C78[2];
extern f32 D_00724C7C;
extern u8 D_00714350[];
extern s32 func_00457120(void);
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


extern void mdlSetLayerTime(u8 *arg0, s32 arg1, f32 arg2);

extern u8 D_00714368[];
extern f32 D_008872F8[];
 
extern f32 fGpffff80f4;
extern f32 fGpffff81f4;

extern u16 *GeometryCreateTableGridMultiPart(s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          void *arg4, s32 arg5);
extern u8 D_00713408[];
extern u8 D_007141A0[];
extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
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
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_004a.c; members 004acb50-004ad450 */

extern s32 func_004a7e30(u8 *arg0, u8 *arg1);
extern void func_004a8250(u8 *arg0, u8 *arg1);
extern void func_004a8440(u8 *arg0, u8 *arg1);
extern void func_004a86c0(u8 *arg0, u8 *arg1);
/* measured: restores the file's O2 loop-invariant baseline. */
/* measured: close loop-invariant hoisting after func_004a6c00. */
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
// FUN_004ACB50
void func_004acb50(u8 *arg0) {
    mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0, 0.0f);
}

// FUN_004ACB80
void func_004acb80(u8 *arg0)
{
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    f32 temp_f0;
    u32 temp_3;
    u32 temp_3_2;
    u32 temp_4;

    temp_f0 = mdlGetLayerWeight(*(s32 *)(arg0 + 0xB4), 0);
    temp_4 = (u32)temp_f0 + 1;
    temp_3 = *(u32 *)(arg0 + 0x9C);
    if (temp_3 >= temp_4 || temp_3 == 0) {
        if (*(u8 *)(arg0 + 0xB8) == 1) {
            if (*(u32 *)(arg0 + 0x74) <= temp_4) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)*(s32 *)(arg0 + 0x70) - 1.0f);
            }
        } else if (*(u8 *)(arg0 + 0x80) != 0 &&
                   *(u32 *)(arg0 + 0x70) <= temp_4) {
            temp_3_2 = *(u32 *)(arg0 + 0x74);
            if (temp_4 < temp_3_2) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)(s32)temp_3_2 - 1.0f);
            }
        }
        *(f32 *)(arg0 + 8) = 1.0f;
    }
}

/* measured: an s64-aligned union gives retail's ld/lwc1 Vec3 copies; the
   three-argument helper signature keeps frame_index/frame_count in a1/a2. */
// FUN_004ACCC0
void func_004accc0(u8 *arg0)
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
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    extern f32 func_0048aff0(u8 *arg0, s32 arg1, s32 arg2);
    extern u8 *func_003e9700(s32 arg0);
    extern u8 *mdlGetMatrix(s32 arg0);
    extern u8 *RwMatrixMultiply(void *arg0, void *arg1, void *arg2);
    extern void RwMatrixRotate(void *arg0, void *arg1, f32 fparg0, s32 arg2);
    extern void RwMatrixScale(void *arg0, void *arg1, s32 arg2);
    extern void func_003e4320(void *arg0, void *arg1, void *arg2);
    extern void mdlUpdateModelMatrix(s32 arg0);
    extern void func_0047a320(s32 arg0);
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
    frame_index = (u32)mdlGetLayerWeight(*(s32 *)(arg0 + 0xB4), 0);
    frame_count = *(s32 *)(arg0 + 0x9C);
    if (frame_count >= (s32)frame_index || frame_count == 0) {
        scale = func_0048aff0(arg0 + 0x44, frame_index, frame_count) / 10.0f;
        node = ((u8 *)(u32)func_00457120()) + 0x68;
        camera = ((u8 *)(u32)func_00457120());
        near_height = *(f32 *)(camera + 0x80);
        camera = ((u8 *)(u32)func_00457120());
        far_z = *(f32 *)(camera + 0x84);
        depth = (((f32)-0xFFFF * near_height) * far_z) /
                (((f32)-0xFFFF * far_z) -
                 (-31.0f * (far_z - near_height)));
        width = 2.0f * (*(f32 *)(node + 0) * depth);
        near_height = 2.0f * (*(f32 *)(node + 4) * depth);
        camera = ((u8 *)(u32)func_00457120());
        matrix = func_003e9700(*(s32 *)(camera + 4));
        RwMatrixRotate(frame.matrix, &basis1,
                      *(f32 *)(arg0 + 0x90), 0);
        if (*(f32 *)(arg0 + 0x94) != 0.0f) {
            RwMatrixRotate(frame.matrix, &basis2,
                          *(f32 *)(arg0 + 0x94), 2);
        }
        if (*(f32 *)(arg0 + 0x98) != 0.0f) {
            RwMatrixRotate(frame.matrix, &basis3,
                          *(f32 *)(arg0 + 0x98), 2);
        }
        temp = (width / 640.0f) * scale;
        frame.scale.z = temp;
        frame.scale.y = temp;
        frame.scale.x = temp;
        RwMatrixScale(frame.matrix, &frame.scale, 2);
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        RwMatrixMultiply(object, frame.matrix, matrix);
        frame.scale.x =
            width * (0.5f + (-(f32)(*(f32 *)(arg0 + 0) +
                                    *(f32 *)(arg0 + 0x84)) /
                              640.0f));
        frame.scale.y =
            near_height * (0.5f + (-(f32)(*(f32 *)(arg0 + 4) +
                                          *(f32 *)(arg0 + 0x88)) /
                                    448.0f));
        frame.scale.z = *(f32 *)(arg0 + 0x8C) + depth;
        func_003e4320(&frame.transformed, &frame.scale, matrix);
        scale = *(f32 *)(matrix + 0x30) + frame.transformed.x;
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        *(f32 *)(object + 0x30) = scale;
        scale = *(f32 *)(matrix + 0x34) + frame.transformed.y;
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        *(f32 *)(object + 0x34) = scale;
        scale = *(f32 *)(matrix + 0x38) + frame.transformed.z;
        object = mdlGetMatrix(*(s32 *)(arg0 + 0xB4));
        *(f32 *)(object + 0x38) = scale;
        mdlUpdateModelMatrix(*(s32 *)(arg0 + 0xB4));
        func_0047a320(*(s32 *)(arg0 + 0xB4));
    }
}

/* measured: effModel func_004ac300 VU0 colour-pack idiom with D_00761134 (1/255) scale; */
/* measured: plain `(u32)temp_f0` gives retail's `lui $3,0x8000; or` (no D_80000001, unlike */
/* measured: the `+1` siblings); `sp5C = *(s32 *)&sp50` forces the packed word back through */
/* measured: memory so the `lw $2,0x50; sw $2,0x5C` copy survives and the saved ranking stays */
/* measured: arg0 $s3, arg1 $s2, frame_index $s1, frame_count $s0 with frame 0x60. */
/* measured: probe c: 0 differing words, object 528B/window 528B. */
// FUN_004AD030
void func_004ad030(s32 arg0, u8 *arg1)
{
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    extern s32 func_0048abd0(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
    extern void mdlSetColor(void *arg0, s32 *arg1);
    extern f32 func_0048aff0(void *arg0, u32 arg1, u32 arg2);
    extern void mdlSetLayerWeight(void *arg0, s32 arg1, f32 arg2);
    extern s32 TnGetTableBase(void);
    extern void mdlSetAttachedOwner(void *arg0, s32 arg1);
    extern void mdlQueueModelForDraw(s32 arg0, void *arg1);
    extern f32 D_00761134;
    s32 sp5C;
    s32 sp58;
    s32 sp54;
    s32 sp50;
    f32 temp_f0;
    u32 frame_index;
    u32 frame_count;
    s32 color;

    temp_f0 = mdlGetLayerWeight(*(s32 *)(arg1 + 0xB4), 0);
    frame_index = (u32)temp_f0;
    frame_count = *(u32 *)(arg1 + 0x9C);
    if ((frame_count >= frame_index) || (frame_count == 0)) {
        color = func_0048abd0(arg1 + 0x10, arg1 + 0x34, frame_index, frame_count);
        sp58 = *(s32 *)(arg1 + 0xC);
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
            : "r"(&sp58), "f"(D_00761134)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp54 = color;
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
            : "r"(&sp54), "f"(D_00761134)
            : "$2", "$vf2", "$vf10", "$vf11", "memory");
        sp5C = *(s32 *)&sp50;
        mdlSetColor(*(u8 **)(arg1 + 0xB4), &sp5C);
        func_0048aff0(arg1 + 0x44, frame_index, frame_count);
        *(s32 *)(*(u8 **)(arg1 + 0xB4) + 0xD8) &= ~0x100;
        if ((*(u8 *)(arg1 + 0xA1) != 0) && (*(s32 *)(arg1 + 0xA4) == 0)) {
            *(s32 *)(*(u8 **)(arg1 + 0xB4) + 0xD8) |= 0x18;
        } else {
            *(s32 *)(*(u8 **)(arg1 + 0xB4) + 0xD8) &= ~0x18;
        }
        mdlSetLayerWeight(*(u8 **)(arg1 + 0xB4), 0, *(f32 *)(arg1 + 8));
        mdlSetAttachedOwner(*(u8 **)(arg1 + 0xB4), TnGetTableBase());
        mdlQueueModelForDraw(arg0, *(u8 **)(arg1 + 0xB4));
        *(s32 *)(arg1 + 8) = 0;
    }
}

// FUN_004AD240
void func_004ad240(u8 *arg0) {
    func_004ad030(TnGetOffset38(*(u16 *)(arg0 + 0x38)), arg0);
}

// FUN_004AD280
void func_004ad280(u8 *arg0)
{
    extern f32 mdlGetLayerWeight(s32 arg0, s32 arg1);
    f32 temp_f0;
    u32 var_3;
    u32 temp_2;
    u32 temp_2_2;

    temp_f0 = mdlGetLayerWeight(*(s32 *)(arg0 + 0xB4), 0);
    var_3 = (u32)temp_f0 + 1;
    temp_2 = *(u32 *)(arg0 + 0x9C);
    if (temp_2 >= var_3 || temp_2 == 0) {
        if (*(u8 *)(arg0 + 0xB8) == 1) {
            if (*(u32 *)(arg0 + 0x74) <= var_3) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)*(s32 *)(arg0 + 0x70) - 1.0f);
            }
        } else if (*(u8 *)(arg0 + 0x80) != 0 &&
                   *(u32 *)(arg0 + 0x70) <= var_3) {
            temp_2_2 = *(u32 *)(arg0 + 0x74);
            if (var_3 < temp_2_2) {
                mdlSetLayerTime(*(u8 **)(arg0 + 0xB4), 0,
                              (f32)(s32)temp_2_2 - 1.0f);
            }
        }
        *(f32 *)(arg0 + 8) = 1.0f;
    }
    func_004ad030(TnGetOffset38(*(u16 *)(arg0 + 0x38)), arg0);
}

// FUN_004AD3E0
void func_004ad3e0(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x0) = arg1[0];
    *(f32 *)(arg0 + 0x4) = arg1[1];
}

// FUN_004AD400
void func_004ad400(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0xC) = arg1;
}

// FUN_004AD410
s32 func_004ad410(u8 *arg0) {
    u8 *p;
    s32 result;
    p = *(u8 **)(arg0 + 0xB4);
    if (p != NULL) {
        result = (*(u8 *)(p + 0xEE) ^ 1U) < 1U;
    } else {
        result = 1;
    }
    return result;
}

// FUN_004AD440
s32 func_004ad440(u8 *arg0) {
    return *(u8 *)(arg0 + 0xB8) != 0;
}

// FUN_004AD450
void func_004ad450(u8 *arg0) {
    *(u8 *)(arg0 + 0xB8) = 0;
}


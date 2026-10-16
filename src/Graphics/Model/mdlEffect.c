#include "include_asm.h"
#include "rw_geometry_internal.h"
/* Source unit: src/Graphics/Model/mdlFile_0047d2d0.c (1 function markers) */
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_update_internal.h"
extern void *func_004b1950(void *source);
extern f32 effMiscRandFloat(EffRandState *state);
extern void *func_004a5910(void *source);
extern void *func_004a5e50(void *source);
extern void *func_004a6d90(void *source);
extern void *func_004a6e10(void *source);
extern u8 *RingCreateKindInstance(u16 kind, u8 *parameters);
extern RpGeometry *RpGeometryLock(RpGeometry *geometry, s32 lockMode);
extern u8 *ThunderTextureForIndex(u16 kind, u8 *parameters);
extern void *func_00498b20(void *source);
extern void *func_0049a5e0(void *source);
extern s32 func_002be1b0(s16 item);
extern void free(void *ptr);

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern void mdlEffectListReleaseNodes(u32 *param_1);

extern void func_004b11d0(s32 arg0, s32 arg1);

extern void func_004b1170();

extern void func_004b13f0(void *object, s32 *color);

extern void func_004b13d0(float param_1, u8 param_2[][16]);
extern void mdlEffectListReleaseHandles(u32 *param_1);
extern void func_004b1150_i(int param_1);
extern u32 func_004b1130_u32(u32 param_1);
extern u32 func_004b11b0();

extern void func_004824a0(int *param_1, u8 *param_2, float *param_3);


extern void ParticleProjectVertices(float param_1, int param_2);
extern void func_00487fb0_evt(float param_1);

extern void func_00492e30(u16 *emitter, f32 scale);

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern void func_003f3eb0(s32 arg0, s32 arg1);
extern u8 *iGpffffb884;
extern u64 iGpffffb8c8;
extern u64 iGpffffb8e8;

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern u8 D_007131E8[];
/* Defined below in this file; called at line 54, above its definition. */
extern void mdlEffectListClear(u32 *param_1);
extern s32 func_00457120(void);
extern u8 *func_003e9700(s32 arg0);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void memset(void *dest, s32 value, s32 size);
extern s32 mdlCopyIndexedMatrix(void *arg0, s32 arg1, void *arg2);
extern void func_003e0670(void *matrixOut, void *matrixIn);
extern void RtQuatConvertFromMatrix(void *arg0, void *arg1);
extern void func_004b12e0(s32 arg0, void *arg1);

extern void effMiscNormalizeVU(void);
extern void effMiscBuildRotationVU(void);
typedef struct RwV3d { f32 x, y, z; } RwV3d;
typedef struct RwMatrixTag {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} RwMatrix;
typedef struct RwFrame RwFrame;
typedef struct RwTexture RwTexture;
typedef struct RpMaterial RpMaterial;
typedef struct RpGeometry RpGeometry;
/* Same combine contract as the existing frame-transform provider. */
typedef enum RwOpCombineType {
    rwCOMBINEREPLACE = 0,
    rwCOMBINEPRECONCAT,
    rwCOMBINEPOSTCONCAT,
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7FFFFFFF
} RwOpCombineType;
extern RwV3d *func_003e42a0(RwV3d *out, const RwV3d *in, const RwMatrix *matrix);
extern f32 D_00713D10[];
extern f32 D_00713D14[];
extern f32 D_00713D18[];
extern f32 cosf(void);
extern f32 sinf(f32 param_1);
static inline u8 *mdlEffect_camera_matrix(u8 *base)
{
    return base + 0x20;
}






extern void datEntryDrawGatedByFlag39(s32 a0, s32 a1, s32 a2, s32 a3);
extern void (*jtbl_008873EC[])(void *ptr);
extern void func_004abd60(s32 arg0);
// Intent: release the UI handle stored at *arg0, then free its block. [inferred]
// FUN_00200720
void btlUiReleaseHandle(s32 *arg0) {
    s32 temp_4;

    temp_4 = *arg0;
    if (temp_4 != 0) {
        func_004abd60(temp_4);
    }
    jtbl_008873EC[0](arg0);
}


// Intent: set the window rectangle from the four 16-bit fields of the state block. [inferred]
// FUN_00200C70
void btlUiSetWindowRect(u8 *arg0)
{
    u8 *temp_7;

    temp_7 = *(u8 **)(arg0 + 0x38);
    if (*(s32 *)(arg0 + 0x28) == 0) {
        datEntryDrawGatedByFlag39(*(s16 *)(temp_7 + 0),
                      *(s16 *)(temp_7 + 4),
                      *(s16 *)(temp_7 + 8),
                      *(s16 *)(temp_7 + 0xC));
    }
}


extern void func_002b5120(s32 arg0, u8 *arg1);
extern u32 datEntryGetFlags(s16 item);
extern s32 func_002be1e0(s32 arg0);
extern void (*D_00887300[])(s32 arg0, s32 arg1);
/* measured: a typed vtable base local with propagation disabled reproduces the
   retail single D_00887300 address hoist and saved-register frame. */
#pragma opt_propagation off
/* measured: restores opt_propagation after func_002b5120. */
#pragma opt_propagation on
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
/* Preserve the signed-halfword zero test without merging it with the
   preceding sentinel comparison. */
#pragma push
#pragma opt_common_subs off
#pragma pop
#pragma push
#pragma opt_dead_assignments off
#pragma pop
#pragma push
#pragma opt_propagation off
#pragma opt_common_subs on
#pragma opt_common_subs on
#pragma pop
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma push
#pragma opt_propagation off
#pragma pop
// FUN_002BE1B0
s32 func_002be1b0(s16 item)
{
    return func_002be1e0(datEntryGetFlags(item));
}


/* Allocates an empty effect list and clears its head. */
// FUN_0047D1A0
u32 mdlEffectListCreate(void)
{
    u32 temp_2;

    chkmemAllocSiteTag(D_007131E8, 0x2D);
    temp_2 = (u32)(*jtbl_008873E8)(4, 0x40000);
    mdlEffectListClear((u32 *)temp_2);
    return temp_2;
}

/* Defined below in this file; called at line 61, above its definition. */
extern u32 *mdlEffectListAppendNode(u32 *list, u32 *arg1, u16 arg2);

/* Creates a list and appends a reference to each source node. */
// FUN_0047D200
u32 *mdlEffectListCopy(u32 **arg0)
{
    u32 *temp;
    u32 *cur;

    chkmemAllocSiteTag(D_007131E8, 0x2D);
    temp = (u32 *)(*jtbl_008873E8)(4, 0x40000);
    mdlEffectListClear(temp);
    cur = (u32 *)*arg0;
    if (cur == NULL) {
        return temp;
    }
    while (cur[4] != 0) {
        cur = (u32 *)cur[4];
    }
    while (cur != NULL) {
        mdlEffectListAppendNode(temp, cur, *(u16 *)((u8 *)cur + 4));
        cur = (u32 *)cur[3];
    }
    return temp;
}
/* Releases every node, then frees the list head. */
// FUN_0047D2D0
void mdlEffectListDestroy(u32 *param_1)
{
  mdlEffectListReleaseNodes(param_1);

  DAT_008873ec_abs[0](param_1);
}




/* Clears a list head to the empty state. */
// FUN_0047D310
void mdlEffectListClear(u32 *param_1)
{
    *param_1 = 0;
}

/* Appends a node that owns a fresh copy of the given data block. */
// FUN_0047D320
u32 *mdlEffectListAppendBlock(u32 **arg0, s32 arg1, u32 arg2, u16 arg3, u32 arg4)
{
    u32 base;
    u32 head;
    u32 *data;
    u32 *node;

    chkmemAllocSiteTag(D_007131E8, 0x7F);
    data = (u32 *)(base = (u32)jtbl_008873E8,
                   ((void *(*)(u32, u32))*(u32 *)base)(arg2 + 0x10, 0x40000));
    data[0] = (u32)((u8 *)data + 0x10);
    data[1] = 0;
    data[3] = arg4;
    data[2] = 1;
    memcpy((void *)data[0], (const void *)arg1, arg2);
    chkmemAllocSiteTag(D_007131E8, 0x66);
    node = (u32 *)((void *(*)(u32, u32))*(u32 *)base)(0x14, 0x40000);
    memset(node, 0, 0x14);
    node[3] = 0;
    head = (u32)*arg0;
    if (head != 0) {
        ((u32 *)head)[3] = (u32)node;
        head = (u32)*arg0;
        node[4] = head;
    } else {
        node[4] = 0;
    }
    *arg0 = node;
    node[0] = (u32)data;
    *(u16 *)((u8 *)node + 4) = arg3;
    return node;
}

/* Appends a node that shares an existing data block and bumps its refcount. */
// FUN_0047D460
u32 *mdlEffectListAppendNode(u32 *list, u32 *arg1, u16 arg2)
{
    u32 head;
    u32 *data;
    u32 *node;

    chkmemAllocSiteTag(D_007131E8, 0x66);
    node = (u32 *)(*jtbl_008873E8)(0x14, 0x40000);
    memset(node, 0, 0x14);
    node[3] = 0;
    head = *list;
    if (head != 0) {
        ((u32 *)head)[3] = (u32)node;
        head = *list;
        node[4] = head;
    } else {
        node[4] = 0;
    }
    *list = (u32)node;
    node[0] = arg1[0];
    *(u16 *)((u8 *)node + 4) = arg2;
    data = *(u32 **)arg1;
    data[2] = data[2] + 1;
    return node;
}

/* measured: nd 14 floor. ALL non-float code matches byte-for-byte, including
   the MtxRow {f32 x,y,z; s32 flag;} out[4] layout (holes at 0x5C/0x6C/0x7C),
   the 8x8-byte copy loop (t0/t1 temps, dst/count/src preheader), the identity
   branch, sp4C |= 0x20003, and the in[12..14] -> f2/f1/f0 temp loads. Residual
   is only the FP math: (1) BOTH sqrt/mula chains emit mula x, madda y where
   retail has mula y, madda x -- same loads, same regs (x->f5, y->f6), and the
   term order is compiler-canonical in my compile regardless of source
   expression order (y*y + x*x + z*z + w*w) or decl order (tried x,y,z,w and
   y,x,z,w); (2) block-2 reloads: mwcc loads y,z,w,x assigning x->f11, z->f12
   where retail loads y,x,z,w with x->f12, z->f11 -- the fresh-reg assignment
   order flips, cascading into 6 mul.s rows. Also tried id-local vs inline
   node+8 loads, out as f32[16], and three copy-loop spellings; the retained
   shapes are the best. mula/madda term-order floor, cf. btlShuffleDraw
   func_00377930 note. */
// Rebuilds each node's transform. Walks the node list at *arg0 (next pointer +0x10, key +0x08, matrix index +0x04); a matrix copied from arg1 by mdlCopyIndexedMatrix feeds a quaternion-derived 3x3 rotation, with the identity basis for indices of 1000 or more. The 4-row result goes to func_004b12e0 under the key, then func_004b1190 runs on the same key.
// FUN_0047D540
void mdlEffectListBuildTransforms(u8 **arg0, u8 *arg1)
{
    extern f32 sqrtf(f32 x);
    f32 in[16];
    struct Vec3 { f32 x; f32 y; f32 z; };
    struct MtxRow { f32 x; f32 y; f32 z; s32 flag; } out[4];
    f32 quat[4];
    f32 length;
    f32 factor;
    f32 x2;
    f32 y2;
    f32 z2;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 wx;
    f32 wy;
    f32 wz;
    u8 *node;

    node = *arg0;
    while (node != NULL) {
        if (*(u32 *)(node + 8) == 0) {
            break;
        }
        if (mdlCopyIndexedMatrix(arg1, *(u16 *)(node + 4), in) == 0) {
            u32 *src;
            u32 *dst;
            s32 count;
            u32 temp1;
            u32 temp2;
            dst = (u32 *)in;
            count = 8;
            src = (u32 *)arg1;
            do {
                temp1 = src[0];
                temp2 = src[1];
                src += 2;
                count--;
                dst[0] = temp1;
                dst[1] = temp2;
                dst += 2;
            } while (count > 0);
            }
            if (*(u16 *)(node + 4) >= 1000) {
                out[2].z = 1.0f;
                out[1].y = 1.0f;
                out[0].x = 1.0f;
                out[1].x = 0.0f;
                out[0].z = 0.0f;
                out[0].y = 0.0f;
                out[2].y = 0.0f;
                out[2].x = 0.0f;
                out[1].z = 0.0f;
                out[3].z = 0.0f;
                out[3].y = 0.0f;
                out[3].x = 0.0f;
                out[0].flag |= 0x20003;
                *(struct Vec3 *)&out[3] = *(struct Vec3 *)&in[12];
            } else {
                func_003e0670(in, in);
                RtQuatConvertFromMatrix(quat, in);
                length = sqrtf(quat[0] * quat[0] + quat[1] * quat[1] +
                                quat[2] * quat[2] + quat[3] * quat[3]);
                if (length != 0.0f) {
                    quat[0] /= length;
                    quat[1] /= length;
                    quat[2] /= length;
                    quat[3] /= length;
                }
                factor = 2.0f / (quat[0] * quat[0] + quat[1] * quat[1] +
                                 quat[2] * quat[2] + quat[3] * quat[3]);
                x2 = quat[0] * factor;
                y2 = quat[1] * factor;
                z2 = quat[2] * factor;
                wx = x2 * quat[3];
                wy = y2 * quat[3];
                wz = z2 * quat[3];
                xx = quat[0] * x2;
                yy = quat[1] * y2;
                zz = quat[2] * z2;
                yz = quat[1] * z2;
                xz = quat[2] * x2;
                xy = quat[0] * y2;
                out[0].x = 1.0f - (yy + zz);
                out[0].y = xy + wz;
                out[0].z = xz - wy;
                out[1].x = xy - wz;
                out[1].y = 1.0f - (zz + xx);
                out[1].z = yz + wx;
                out[2].x = xz + wy;
                out[2].y = yz - wx;
                out[2].z = 1.0f - (xx + yy);
                out[3].x = 0.0f; out[3].y = 0.0f; out[3].z = 0.0f;
                out[0].flag = 3;
                *(struct Vec3 *)&out[3] = *(struct Vec3 *)&in[12];
            }
            func_004b12e0(*(u32 *)(node + 8), (u8 *)out);
            func_004b1190(*(u8 **)(node + 8));
            node = *(u8 **)(node + 16);
    }
}
/* Calls func_004b11d0 with each node's payload and the first argument. */
// FUN_0047D7E0
void mdlEffectListInvokeEach(s32 arg0, u8 **arg1)
{
    s32 temp_5;
    u8 *var_16;

    var_16 = *arg1;
    while (var_16 != NULL) {
        temp_5 = *(s32 *)(var_16 + 8);
        if (temp_5 != 0) {
            func_004b11d0(arg0, temp_5);
        }
        var_16 = *(u8 **)(var_16 + 0x10);
    }
}



/* Calls func_004b1170 on each node whose data block has flag bit 1 set. */
// FUN_0047D840
void mdlEffectListCallFlagged(u32 *param_1)
{
  int *piVar1;

  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {

    if ((piVar1[2] != 0) && ((*(u32 *)(*piVar1 + 0xc) & 1) != 0)) {

      func_004b1170(piVar1[2]);
    }


  }

  return;

}



/* Applies a colour to each node's payload through func_004b13f0. */
// FUN_0047D8A0
void mdlEffectListSetColor(u8 **arg0, s32 *arg1)
{
    s32 temp_4;
    u8 *var_16;

    var_16 = *arg0;
    while (var_16 != NULL) {
        temp_4 = *(s32 *)(var_16 + 8);
        if (temp_4 != 0) {
            func_004b13f0((void *)temp_4, arg1);
        }
        var_16 = *(u8 **)(var_16 + 0x10);
    }
}



/* Averages the three vector components and applies the result as a uniform scale via func_004b13d0. */
// FUN_0047D900
void mdlEffectListSetUniformScale(int *param_1,float *param_2)
{
    int current;
    float average;

    average = (param_2[0] + param_2[1] + param_2[2]) / 3.0f;
    for (current = *param_1; current != 0; current = *(int*)(current + 0x10)) {
        if (*(int*)(current + 8) != 0) {
            func_004b13d0(average,(u8 (*)[16])*(u32*)(current + 8));
        }
    }
}



/* Drops one reference per node, frees blocks whose count reaches zero, and clears the head. */
// FUN_0047D990
void mdlEffectListReleaseNodes(u32 *param_1)
{
    int *current;
    int *next;

    mdlEffectListReleaseHandles(param_1);
    current = (int*)*param_1;
    while (current != 0) {
        next = (int*)current[4];
        *(int*)(*current + 8) = *(int*)(*current + 8) - 1;
        if (*(int*)(*current + 8) == 0) {
            ((void (*)())DAT_008873ec_abs[0])(*current);
        }
        ((void (*)())DAT_008873ec_abs[0])(current);
        current = next;
    }
    *param_1 = 0;
}




/* Releases each node's handle, then acquires a new handle from its payload. */
// FUN_0047DA30
void mdlEffectListRefreshHandles(u32 *param_1)
{
    int *current;
    u32 value;

    for (current = (int*)*param_1; current != 0; current = (int*)current[4]) {
        if (current[2] != 0) {
            if (current[2] == *(int*)(*current + 4)) {
                *(u32*)(*current + 4) = 0;
            }
            func_004b1150_i(current[2]);
        }
        if (((u32*)*current)[1] == 0) {
            value = func_004b1130_u32(*(u32*)*current);
            current[2] = value;
            *(u32*)(*current + 4) = value;
        } else {
            value = func_004b11b0((u64*)((u32*)*current)[1]);
            current[2] = value;
        }
    }
}




/* Releases each node's handle and clears it, also clearing the payload's back-reference when it matches. */
// FUN_0047DAE0
void mdlEffectListReleaseHandles(u32 *param_1)
{
  int *piVar1;

  for (piVar1 = (int *)*param_1; piVar1 != (int *)0x0; piVar1 = (int *)piVar1[4]) {

    if (piVar1[2] != 0) {

      if (piVar1[2] == *(int *)(*piVar1 + 4)) {

        *(u32 *)(*piVar1 + 4) = 0;

      }

      func_004b1150_i(piVar1[2]);

      piVar1[2] = 0;

    }

  }

  return;

}




/* Copies arg1 bytes from arg0 into a new reference-counted block and returns a wrapper that points at it. */
// FUN_0047DB50
u32 *mdlEffectListWrapCopy(s32 arg0, s32 arg1)
{
    u32 *node;
    u32 *wrap;
    u32 base;

    chkmemAllocSiteTag(D_007131E8, 0x18A);
    node = (u32 *)(base = (u32)jtbl_008873E8,
                   ((void *(*)(u32, u32))*(u32 *)base)(arg1 + 0x10, 0x40000));
    node[0] = (u32)((u8 *)node + 0x10);
    node[1] = 1;
    memcpy((void *)node[0], (void *)arg0, (u32)arg1);
    chkmemAllocSiteTag(D_007131E8, 0x17C);
    wrap = (u32 *)((void *(*)(u32, u32))*(u32 *)base)(8, 0x40000);
    memset(wrap, 0, 8);
    wrap[0] = (u32)node;
    return wrap;
}
/* Makes a new wrapper that shares the payload of *arg0 and bumps its reference count. */
// FUN_0047DC30
u32 *mdlEffectListWrapShared(u32 **arg0)
{
    u32 *obj;
    u32 *temp;

    chkmemAllocSiteTag(D_007131E8, 0x17C);
    temp = (u32 *)(*jtbl_008873E8)(8, 0x40000);
    memset(temp, 0, 8);
    obj = *arg0;
    temp[0] = (u32)obj;
    obj[1] = obj[1] + 1;
    return temp;
}
extern u_long128 mdlEffectStoreQuadA(s32 emitter, u32 *position);
extern u_long128 mdlEffectStoreQuadB(s32 emitter, u32 *rotation);
void func_003e9cb0(void *frame, void *matrix, u32 flags);
extern void func_004823e0(u8 *arg0);
extern void func_00484790(u8 *arg0);
extern void func_004847e0(u8 *arg0);
extern void func_00492d10(void *object);
extern void ParticleUpdateScaled(u8 *arg0, f32 arg1);
void GeometryMatrixBuildCombined();
extern char D_00713CE0[];
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
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
// FUN_00481EE0
void func_00481ee0(u8 **arg0)
{
    func_004823e0(*arg0);
    jtbl_008873EC[0](arg0);
}


// Calls func_004824a0 for the sub-object at +0x10 of the first argument and writes the result to the float array in the second.
// FUN_00482700
void mdlEffectEvalSubPose(int param_1, float *param_2)
{
  func_004824a0((int *)(u32)param_1, (u8 *)(u32)*(u32 *)(param_1 + 0x10), param_2);
}


/* Removing this loses 0x00482730 (MATCH nd0 -> MISMATCH nd45) - measured W161. */

// Sets each entry's frame to param_2 modulo the entry's frame count (+0x0C of the entry's block) and marks it active (+0x08 = 1). The loop is built with opt_loop_invariants on, as measured.
// FUN_00482730
/* measured: opt_loop_invariants on is required for mdlEffectWrapTrackFrames (MATCH nd0). */
#pragma opt_loop_invariants on
void mdlEffectWrapTrackFrames(int param_1, u32 param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;

  iVar1 = *(int *)(param_1 + 0xc);
  for (iVar3 = 0; iVar3 < iVar1; iVar3 = iVar3 + 1) {
    iVar2 = *(int *)(param_1 + 0x10) + iVar3 * 0x14;
    *(u32 *)(iVar2 + 4) = param_2 % *(u32 *)(*(int *)(iVar2 + 0xc) + 0xc);
    *(u32 *)(iVar2 + 8) = 1;
  }
  return;
}


/* measured: opt_loop_invariants off closes the mdlEffectWrapTrackFrames bracket. */
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_loop_invariants off
// FUN_00484350
void func_00484350(u8 *arg0)
{
    RwMatrix matrix;

    GeometryMatrixBuild(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}


// FUN_004843A0
void func_004843a0(u8 *arg0)
{
    RwMatrix matrix;

    GeometryMatrixBuildCombined(&matrix);
    func_003e9cb0(*(void **)(arg0 + 0xC), &matrix, 0);
}


// Resolves the self-relative pointer at +0x10 of the source: returns it as-is when the flag at +0x18 is set; otherwise treats it as an offset and returns source+offset, or NULL for a zero offset.
// FUN_00484490
void *mdlEffectResolveRelPtrA(void *source)
{
  u8 *param_1 = source;
  u8 *value;

  if (*(int *)(param_1 + 0x18) == 0) {
    goto check;
  }

  value = *(u8 **)(param_1 + 0x10);
  goto done;
check:
  value = *(u8 **)(param_1 + 0x10);
  if (value == 0) {
    goto zero;
  }

  value = (u8 *)((u32)param_1 + (u32)value);
  goto done;
zero:
  value = 0;
done:
  return value;
}



// Resolves the self-relative pointer at +0x20 of the source: returns it as-is when the flag at +0x28 is set; otherwise treats it as an offset and returns source+offset, or NULL for a zero offset.
// FUN_004844D0
void *mdlEffectResolveRelPtrB(void *source)
{
  u8 *param_1 = source;
  u8 *value;

  if (*(int *)(param_1 + 0x28) == 0) {
    goto check;
  }

  value = *(u8 **)(param_1 + 0x20);
  goto done;
check:
  value = *(u8 **)(param_1 + 0x20);
  if (value == 0) {
    goto zero;
  }

  value = (u8 *)((u32)param_1 + (u32)value);
  goto done;
zero:
  value = 0;
done:
  return value;
}



// FUN_00484790
void func_00484790(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[6];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x10) = 0;
        *(s32 *)(arg0 + 0x14) = 0;
        *(u8 **)(arg0 + 0x18) = NULL;
    }
}


// FUN_004847E0
void func_004847e0(u8 *arg0)
{
    u8 *node;

    node = ((u8 **)arg0)[10];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        *(s32 *)(arg0 + 0x20) = 0;
        *(s32 *)(arg0 + 0x24) = 0;
        *(u8 **)(arg0 + 0x28) = NULL;
    }
}


// FUN_00484B30
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma opt_propagation off
u_long128 func_00484b30(u8 *arg0)
{
    Code48InitialState *state = (Code48InitialState *)(void *)arg0;
    const u_long128 *quadSource;
    u_long128 quad;

    memset(state, 0, sizeof(*state));
    __asm__ volatile("sqc2 vf0, 0(%0)" : : "r"(state) : "memory");
    __asm__ volatile("sqc2 vf0, 16(%0)" : : "r"(state) : "memory");
    __asm__ volatile("sqc2 vf0, 64(%0)" : : "r"(state) : "memory");
    state->vector40[1] = 5.0f;
    __asm__ volatile("sqc2 vf0, 80(%0)" : : "r"(state) : "memory");
    quadSource = (const u_long128 *)(const void *)D_00713CE0;
    quad = *quadSource;
    state->quad20 = quad;
    state->scalar60 = 1.0f;
    state->scalar74 = 1.0f;
    state->word64 = 0xFFFFFFFF;
    state->word68 = 0x80;
    return quad;
}


/* Copies one 0x90-byte record from source to destination. */
// FUN_00486710
void mdlEffectCopyRecord(u8 *destination, u8 *source)
{
  memcpy(destination, source, 0x90);
}



/* Walks the node list at root+0x8c (linked through +0xac) and returns the node whose id at +0x90 matches identifier, or NULL. */
// FUN_00486740
u8 *mdlEffectFindNodeById(u8 *root, s32 identifier)
{
  u8 *node;

  node = *(u8 **)(root + 0x8c);
  while (node != NULL) {
    if (*(s32 *)(node + 0x90) == identifier) {
      return node;
    }
    node = *(u8 **)(node + 0xac);
  }

  return NULL;
}



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
#pragma opt_propagation off
#pragma opt_propagation on
    #pragma optimization_level 1
    #pragma optimization_level 2
#pragma optimization_level 1
/* measured: closes optimization_level 1 for the parked 00486970 body. */
#pragma optimization_level 2
// FUN_00489E00
void func_00489e00(u8 *arg0)
{
    u8 *temp_4;

    temp_4 = *(u8 **)(arg0 + 0x4C);
    if (temp_4 != 0) {
        func_00492d10(temp_4);
        ParticleUpdateScaled(arg0, 1.0f);
    }
}


// Calls func_00487fb0_evt with 1.0f; the callee is not yet named.
// FUN_00489E50
void mdlEffectSetUnitWeight(void)
{
  func_00487fb0_evt(1.0f);
}



// FUN_00489EE0
void func_00489ee0(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(*(s32 *)(instance + 0x4C), position);
}


// FUN_00489F10
void func_00489f10(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(*(s32 *)(instance + 0x4C), rotation);
}


// Stores param_1 at +0x08 of the record param_2, then calls func_00492e30 with the record emitter at +0x4C and the same scale.
// FUN_00489F50
void mdlEffectSetScaleAndNotify(f32 param_1, int param_2)
{
  *(f32 *)(param_2 + 8) = param_1;
  func_00492e30((u16 *)*(u32 *)(param_2 + 0x4c), param_1);
  return;
}


/* Retail's 368-byte Catmull-Rom interpolator builds tangents and returns its VU0 vector in vf10. */

/* measured: enable MWCCPS2's MMI builtins and O1; _pcpyld on u64 locals
 * reproduces the 00489f80 packet skeleton (object 116/window 128,
 * normalized_diff 0) and the 0048a000/0048a0e0/0048a070 packet skeletons. */
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* measured: optimization_level 1 is required with the VU0 pragmas above;
   at -O2 the packet stores are reordered and the pcpyld pairs are folded. */
#pragma optimization_level 1
// Appends a 0x20-byte packet pair to iGpffffb884: a tag quad with reg 0x8001, then a 0x4C register quad with iGpffffb8c8 OR'd with a 0x00FFFFFF high mask (layout measured against retail).
// FUN_00489F80
void mdlEffectEmitMaskedTagPair(void)
{
    u8 *packet;
    u_long128 packed;
    u64 a, c, b;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = iGpffffb884;
    *(u_long128 *)packet = packed;
    c = 0x4C;
    b = iGpffffb8c8 | 0x00FFFFFF00000000ULL;
    packed = _pcpyld(c, b);
    *(u_long128 *)(packet + 0x10) = packed;
    iGpffffb884 = iGpffffb884 + 0x20;
}
// Appends the same packet pair as mdlEffectEmitMaskedTagPair, with iGpffffb8c8 used unmasked in the register quad.
// FUN_0048A000
void mdlEffectEmitTagPair(void)
{
    u8 *packet;
    u_long128 packed;
    u64 a, c, b;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = iGpffffb884;
    *(u_long128 *)packet = packed;
    c = 0x4C;
    b = iGpffffb8c8;
    packed = _pcpyld(c, b);
    *(u_long128 *)(packet + 0x10) = packed;
    iGpffffb884 = iGpffffb884 + 0x20;
}
// Appends a 0x20-byte packet pair to iGpffffb884: a tag quad, then a register quad with the data taken from the argument (tag 8).
// FUN_0048A070
void mdlEffectEmitValuePacket(u64 arg0)
{
    u8 *packet;
    u_long128 packed;
    u64 a, c, b;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = iGpffffb884;
    *(u_long128 *)packet = packed;
    c = 8;
    packed = _pcpyld(c, arg0);
    *(u_long128 *)(packet + 0x10) = packed;
    iGpffffb884 = iGpffffb884 + 0x20;
}
// Appends a 0x20-byte packet pair to iGpffffb884: a tag quad, then a register quad with the data taken from iGpffffb8e8 (tag 8).
// FUN_0048A0E0
void mdlEffectEmitSlotPacket(void)
{
    u8 *packet;
    u_long128 packed;
    u64 a, c, b;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = iGpffffb884;
    *(u_long128 *)packet = packed;
    c = 8;
    b = iGpffffb8e8;
    packed = _pcpyld(c, b);
    *(u_long128 *)(packet + 0x10) = packed;
    iGpffffb884 = iGpffffb884 + 0x20;
}
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off
// Loads arg1 into VU0, normalises it, builds the rotation basis, writes its three rows to arg0 at +0x00, +0x10 and +0x20, and zeroes the words at +0x30 to +0x38.
// FUN_0048A150
void mdlEffectBuildBasisRows(u8 *arg0, u8 *arg1)
{
    f32 work[4];
    u8 *base;

    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(arg1)
        : "$vf10", "memory");
    effMiscNormalizeVU();
    effMiscBuildRotationVU();
    base = (u8 *)work;
    __asm__ volatile(
        "sqc2 $vf28, 0(%0) \n"
        :
        : "r"(base)
        : "$vf28", "memory");
    *(f32 *)(arg0 + 0) = work[0];
    *(f32 *)(arg0 + 4) = work[1];
    *(f32 *)(arg0 + 8) = work[2];
    __asm__ volatile(
        "sqc2 $vf29, 0(%0) \n"
        :
        : "r"(base)
        : "$vf29", "memory");
    *(f32 *)(arg0 + 0x10) = work[0];
    *(f32 *)(arg0 + 0x14) = work[1];
    *(f32 *)(arg0 + 0x18) = work[2];
    __asm__ volatile(
        "sqc2 $vf30, 0(%0) \n"
        :
        : "r"(base)
        : "$vf30", "memory");
    *(f32 *)(arg0 + 0x20) = work[0];
    *(f32 *)(arg0 + 0x24) = work[1];
    *(f32 *)(arg0 + 0x28) = work[2];
    *(s32 *)(arg0 + 0x30) = 0;
    *(s32 *)(arg0 + 0x34) = 0;
    *(s32 *)(arg0 + 0x38) = 0;
}
// Copies the three floats at +0x20 of the current camera object into the output and zeroes the word at +0x0C.
// FUN_0048A1F0
void mdlEffectCopyCameraOrigin(u8 *arg0)
{
    u8 *obj;

    obj = func_003e9700(*(s32 *)((u8 *)(u32)func_00457120() + 4));
    *(f32 *)(arg0 + 0) = *(f32 *)(obj + 0x20);
    *(f32 *)(arg0 + 4) = *(f32 *)(obj + 0x24);
    *(f32 *)(arg0 + 8) = *(f32 *)(obj + 0x28);
    *(s32 *)(arg0 + 0xC) = 0;
}
// Copies the three floats at +0x30 of the current camera object into the output and zeroes the word at +0x0C.
// FUN_0048A250
void mdlEffectCopyCameraAim(u8 *arg0)
{
    u8 *obj;

    obj = func_003e9700(*(s32 *)((u8 *)(u32)func_00457120() + 4));
    *(f32 *)(arg0 + 0) = *(f32 *)(obj + 0x30);
    *(f32 *)(arg0 + 4) = *(f32 *)(obj + 0x34);
    *(f32 *)(arg0 + 8) = *(f32 *)(obj + 0x38);
    *(s32 *)(arg0 + 0xC) = 0;
}
// Writes the normalised vector from arg0 to the camera point at +0x30 of the current camera object into arg1, using VU0.
// FUN_0048A2B0
void mdlEffectAimDirection(u8 *arg0, u8 *arg1)
{
    u8 *obj;
    f32 temp[4];

    obj = func_003e9700(*(s32 *)((u8 *)(u32)func_00457120() + 4));
    temp[0] = *(f32 *)(obj + 0x30);
    temp[1] = *(f32 *)(obj + 0x34);
    temp[2] = *(f32 *)(obj + 0x38);
    temp[3] = 0.0f;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0)         \n"
        :
        : "r"(arg0)
        : "$vf10", "memory");
    __asm__ volatile(
        "lqc2 $vf11, 0(%0)         \n"
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq                   \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        "sqc2 $vf10, 0(%1)         \n"
        :
        : "r"(temp), "r"(arg1)
        : "$vf10", "$vf11", "$vf2", "ACC", "Q", "memory");
}
// Builds an axis-angle rotation matrix from the angle and the axis in VU0 (vf10), loading its three rows into vf28 to vf30 through a 0x40-byte scratch block.
// FUN_0048A340
void mdlEffectAxisAngleBasisVU(f32 param_1)
{
    f32 temp_f20;
    f32 temp_f21;
    f32 temp_f0;
    f32 one;
    f32 x;
    f32 y;
    f32 z;
    f32 square;
    f32 blend;
    f32 factor;
    f32 xy;
    f32 xz;
    f32 zterm;
    f32 yterm;
    f32 xyterm;
    f32 xzterm;
    f32 yzterm;
    f32 xterm;
    u8 raw[0x50];

    temp_f21 = param_1;
    temp_f20 = cosf();
    temp_f0 = sinf(temp_f21);
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw)
        : "$vf10", "memory");

    x = *(f32 *)(raw + 0x0);
    square = x * x;
    one = 1.0f;
    blend = one - square;
    blend = blend * temp_f20 + square;
    *(f32 *)(raw + 0x10) = blend;
    y = *(f32 *)(raw + 0x4);
    xy = x * y;
    factor = one - temp_f20;
    z = *(f32 *)(raw + 0x8);
    zterm = z * temp_f0;
    xyterm = xy * factor;
    blend = zterm + xyterm;
    *(f32 *)(raw + 0x14) = blend;
    xz = x * z;
    yterm = y * temp_f0;
    xzterm = xz * factor;
    blend = xzterm - yterm;
    *(f32 *)(raw + 0x18) = blend;
    *(s32 *)(raw + 0x1c) = 0;
    blend = xyterm - zterm;
    *(f32 *)(raw + 0x20) = blend;
    square = y * y;
    blend = one - square;
    blend = blend * temp_f20 + square;
    *(f32 *)(raw + 0x24) = blend;
    yzterm = y * z;
    xterm = x * temp_f0;
    yzterm = yzterm * factor;
    blend = xterm + yzterm;
    *(f32 *)(raw + 0x28) = blend;
    *(s32 *)(raw + 0x2c) = 0;
    blend = yterm + xzterm;
    *(f32 *)(raw + 0x30) = blend;
    blend = yzterm - xterm;
    *(f32 *)(raw + 0x34) = blend;
    square = z * z;
    blend = one - square;
    blend = blend * temp_f20 + square;
    *(f32 *)(raw + 0x38) = blend;
    *(s32 *)(raw + 0x3c) = 0;
    __asm__ volatile(
        "lqc2 $vf28, 0(%0) \n"
        "lqc2 $vf29, 0x10(%0) \n"
        "lqc2 $vf30, 0x20(%0) \n"
        :
        : "r"(raw + 0x10)
        : "$vf28", "$vf29", "$vf30", "memory");
}
/* Projects VF10 into screen coordinates and returns camera-space depth. */
// Anchor depth: projects the anchor and returns its camera-space depth.
// FUN_0048A460
f32 mdlEffectProjectAnchorDepth(void)
{
    RwV3d transformed, input;
    f32 depth;
    f32 output[4] __attribute__((aligned(16)));
    __asm__ volatile(
        "sqc2 $vf10, 0(%1) \n"
        : "=m"(*(f32 (*)[4])D_00713D10)
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    input.x = D_00713D10[0];
    input.y = D_00713D14[0];
    input.z = D_00713D18[0];
    func_003e42a0(&transformed, &input,
                  (const RwMatrix *)mdlEffect_camera_matrix((u8 *)(u32)func_00457120()));
    depth = transformed.z;
    output[0] = 640.0f * (transformed.x / depth);
    output[1] = 448.0f * (transformed.y / depth);
    output[2] = 0.0f;
    output[3] = 0.0f;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(output), "m"(*(f32 (*)[4])output)
        : "$vf10", "memory");
    return depth;
}
// Projects the anchor through the camera matrix and returns 1 when it lies inside the 640x448 screen rectangle and between the camera near and far distances (+0x80, +0x84); otherwise 0.
// FUN_0048A510
s32 mdlEffectAnchorOnScreen(void)
{
    u8 raw[0x40];
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f3;
    u8 *ptr;

    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    *(f32 *)(raw + 0x20) = D_00713D10[0];
    *(f32 *)(raw + 0x24) = D_00713D14[0];
    *(f32 *)(raw + 0x28) = D_00713D18[0];
    func_003e42a0((RwV3d *)(raw + 0x30), (const RwV3d *)(raw + 0x20),
                  (const RwMatrix *)mdlEffect_camera_matrix((u8 *)(u32)func_00457120()));
    ptr = (u8 *)(u32)func_00457120();
    temp_f20 = *(f32 *)(ptr + 0x80);
    ptr = (u8 *)(u32)func_00457120();
    temp_f0 = *(f32 *)(ptr + 0x84);
    temp_f1 = *(f32 *)(raw + 0x38);
    if ((temp_f1 <= temp_f20) || !(temp_f1 < temp_f0)) {
        return 0;
    }
    temp_f3 = 640.0f * (*(f32 *)(raw + 0x30) / temp_f1);
    *(f32 *)(raw + 0x18) = temp_f3;
    temp_f1 = 448.0f * (*(f32 *)(raw + 0x34) / temp_f1);
    *(f32 *)(raw + 0x1c) = temp_f1;
    if (!(temp_f3 < 0.0f) && !(temp_f1 < 0.0f) &&
        (temp_f3 <= 640.0f) && (temp_f1 <= 448.0f)) {
        *(f32 *)(raw + 0) = temp_f3;
        *(f32 *)(raw + 4) = temp_f1;
        *(f32 *)(raw + 8) = 0.0f;
        *(f32 *)(raw + 0xc) = 0.0f;
        __asm__ volatile(
            "lqc2 $vf10, 0(%0) \n"
            :
            : "r"(raw)
            : "$vf10", "memory");
        return 1;
    }
    return 0;
}
// Projects the anchor and returns its on-screen scale: 650 times the input over the projected depth, clamped to 1500; 0 when the depth is outside the camera near and far range.
// FUN_0048A650
f32 mdlEffectAnchorScreenScale(f32 fparg0)
{
    u8 raw[0x50];
    f32 temp_f22;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f0;
    f32 temp_f1;
    u8 *ptr;

    temp_f20 = fparg0;
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw + 0x10)
        : "$vf10", "memory");
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    *(f32 *)(raw + 0x30) = D_00713D10[0];
    *(f32 *)(raw + 0x34) = D_00713D14[0];
    *(f32 *)(raw + 0x38) = D_00713D18[0];
    func_003e42a0((RwV3d *)(raw + 0x40), (const RwV3d *)(raw + 0x30),
                  (const RwMatrix *)mdlEffect_camera_matrix((u8 *)(u32)func_00457120()));
    temp_f22 = *(f32 *)(raw + 0x48);
    temp_f1 = *(f32 *)(raw + 0x40) / temp_f22;
    temp_f0 = 640.0f * temp_f1;
    *(f32 *)(raw + 0) = temp_f0;
    temp_f1 = *(f32 *)(raw + 0x44) / temp_f22;
    temp_f0 = 448.0f * temp_f1;
    *(f32 *)(raw + 4) = temp_f0;
    *(s32 *)(raw + 8) = 0;
    *(s32 *)(raw + 0xc) = 0;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw)
        : "$vf10", "memory");
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw + 0x20)
        : "$vf10", "memory");
    ptr = (u8 *)(u32)func_00457120();
    temp_f21 = *(f32 *)(ptr + 0x80);
    ptr = (u8 *)(u32)func_00457120();
    temp_f0 = *(f32 *)(ptr + 0x84);
    if ((temp_f22 <= temp_f21) || !(temp_f22 < temp_f0)) {
        return 0.0f;
    }
    ptr = (u8 *)(u32)func_00457120();
    ptr = *(u8 **)(ptr + 4);
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw + 0x10)
        : "$vf10", "memory");
    *(f32 *)&D_00713D10[0] = *(f32 *)(ptr + 0x40);
    *(f32 *)&D_00713D14[0] = *(f32 *)(ptr + 0x44);
    *(f32 *)&D_00713D18[0] = *(f32 *)(ptr + 0x48);
    __asm__ volatile(
        "lqc2 $vf11, 0(%1) \n"
        "vsub.xyzw $vf10, $vf10, $vf11 \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        ".word 0x4A0203BD \n"
        "vwaitq \n"
        "cfc2.ni $2, $vi22 \n"
        "mtc1 $2, %0 \n"
        : "=f"(temp_f1)
        : "r"(&D_00713D10)
        : "$vf10", "$vf11", "$vf2", "$2", "Q", "memory");
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw + 0x20)
        : "$vf10", "memory");
    temp_f0 = (650.0f * temp_f20) / temp_f1;
    temp_f1 = 1500.0f;
    if (!(temp_f0 <= temp_f1)) {
        temp_f0 = temp_f1;
    }
    return temp_f0;
}
// Catmull-Rom point builder: forms two tangent vectors from four consecutive points in VU0, then blends them at t into the output at param_2.
// FUN_0048A810
void mdlEffectCatmullRomVU(float param_1, u8 (*param_2)[16])
{
  float work[7][4];
  float square;
  float cube;
  float coefficient;

  square = param_1 * param_1;
  cube = square * param_1;

  work[4][0] = 0.5f;
  work[4][1] = 0.5f;
  work[4][2] = 0.5f;

  /* VU0 builds the two Catmull-Rom tangent vectors in work[6] and work[5]. */
  asm volatile (
      ".set noreorder                         \n"
      "lqc2        $vf10, 0x10($a0)           \n"
      "lqc2        $vf11, 0x0($a0)            \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "lqc2        $vf10, 0x20($a0)           \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      "addiu       $v1, $sp, 0x40              \n"
      "lqc2        $vf11, 0x0($v1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "addiu       $a2, $sp, 0x60              \n"
      "sqc2        $vf10, 0x0($a2)            \n"
      "lqc2        $vf10, 0x20($a0)           \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "lqc2        $vf10, 0x30($a0)           \n"
      "lqc2        $vf11, 0x20($a0)           \n"
      "vsub.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      "lqc2        $vf11, 0x0($v1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "addiu       $a1, $sp, 0x50              \n"
      "sqc2        $vf10, 0x0($a1)            \n"
      ".set reorder"
      :
      :
      : "memory"
  );

  coefficient = cube * 2.0f - square * 3.0f + 1.0f;
  work[0][0] = coefficient;
  work[0][1] = coefficient;
  work[0][2] = coefficient;

  coefficient = param_1 + (cube - square * 2.0f);
  work[1][0] = coefficient;
  work[1][1] = coefficient;
  work[1][2] = coefficient;

  coefficient = cube - square;
  work[2][0] = coefficient;
  work[2][1] = coefficient;
  work[2][2] = coefficient;

  coefficient = cube * -2.0f + square * 3.0f;
  work[3][0] = coefficient;
  work[3][1] = coefficient;
  work[3][2] = coefficient;

  /* VU0 evaluates the Hermite basis and leaves the interpolated vector in vf10. */
  asm volatile (
      ".set noreorder                         \n"
      "addiu       $v1, $sp, 0x0               \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x10($a0)           \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vmove.xyzw  $vf12, $vf10               \n"
      "addiu       $v1, $sp, 0x10              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x0($a2)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf12, $vf12, $vf10        \n"
      "addiu       $v1, $sp, 0x20              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x0($a1)            \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf12, $vf12, $vf10        \n"
      "addiu       $v1, $sp, 0x30              \n"
      "lqc2        $vf10, 0x0($v1)            \n"
      "lqc2        $vf11, 0x20($a0)           \n"
      "vmul.xyzw   $vf10, $vf10, $vf11        \n"
      "vadd.xyzw   $vf10, $vf10, $vf12        \n"
      ".set reorder"
      :
      :
      : "memory"
  );
}



#pragma push
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop
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
// FUN_0048C440
void func_0048c440(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048c440_check;
loop_0048c440_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048c440_check:
    if (var_7 < 3U) {
        goto loop_0048c440_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
// FUN_0048CD60
void func_0048cd60(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048cd60_check;
loop_0048cd60_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048cd60_check:
    if (var_7 < 3U) {
        goto loop_0048cd60_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
// FUN_0048D820
void func_0048d820(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048d820_check;
loop_0048d820_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048d820_check:
    if (var_7 < 3U) {
        goto loop_0048d820_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
    *(f32 *)(temp_6 + 0xF0) = *(f32 *)(temp_5 + 0xF0) * fparg0;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
// FUN_0048E270
void func_0048e270(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048e270_check;
loop_0048e270_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048e270_check:
    if (var_7 < 3U) {
        goto loop_0048e270_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
// FUN_0048EBC0
void func_0048ebc0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048ebc0_check;
loop_0048ebc0_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048ebc0_check:
    if (var_7 < 3U) {
        goto loop_0048ebc0_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
// FUN_0048F560
void func_0048f560(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_0048f560_check;
loop_0048f560_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0048_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_0048f560_check:
    if (var_7 < 3U) {
        goto loop_0048f560_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}


extern void (*D_00713E70[])(u8 *object);
extern void (*D_00713E78[])(u8 *object);
extern void (*D_00713E7C[])(u8 *object);
extern void (*D_00713E80[])(u8 *object);
extern void (*D_00713F18[])(void *state);
extern void (*D_00713F10[])(u8 *object);
extern void (*D_00713F1C[])(u8 *object);
extern void (*D_00713F20[])(u8 *object);
extern void (*D_00713D54[])(u8 *emitter, f32 scale);
typedef struct EffRandState EffRandState;
extern u32 effMiscRand(EffRandState *state);
static inline f32 code1_0049_mul(f32 left, f32 right) {
    return left * right;
}
extern void func_00484280(u8 *object, s32 resource);
// FUN_00490360
void func_00490360(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490360_check;
loop_00490360_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490360_check:
    if (var_7 < 3U) {
        goto loop_00490360_body;
    }
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
// FUN_00490BB0
void func_00490bb0(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00490bb0_check;
loop_00490bb0_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00490bb0_check:
    if (var_7 < 3U) {
        goto loop_00490bb0_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
    *(f32 *)(temp_6 + 0xE8) = *(f32 *)(temp_5 + 0xE8) * fparg0;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma pop
// FUN_00491660
void func_00491660(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00491660_check;
loop_00491660_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00491660_check:
    if (var_7 < 3U) {
        goto loop_00491660_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xD0) = *(f32 *)(temp_5 + 0xD0) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
    *(f32 *)(temp_6 + 0xE4) = *(f32 *)(temp_5 + 0xE4) * fparg0;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
// FUN_00492080
void func_00492080(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492080_check;
loop_00492080_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492080_check:
    if (var_7 < 3U) {
        goto loop_00492080_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xDC) = *(f32 *)(temp_5 + 0xDC) * fparg0;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
// FUN_00492A80
void func_00492a80(u8 *arg0, f32 fparg0) {
    s32 temp_4;
    u32 var_7;
    u8 *temp_5;
    u8 *temp_6;

    temp_6 = *(u8 **)(arg0 + 0x20);
    temp_5 = *(u8 **)(arg0 + 0x24);
    *(f32 *)(temp_6 + 0x64) = *(f32 *)(temp_5 + 0x64) * fparg0;
    *(f32 *)(temp_6 + 0x68) = *(f32 *)(temp_5 + 0x68) * fparg0;
    var_7 = 0;
    goto loop_00492a80_check;
loop_00492a80_body:
    temp_4 = var_7 * 8;
    *(f32 *)(temp_6 + temp_4 + 0x74) =
        code1_0049_mul(*(f32 *)(temp_5 + temp_4 + 0x74), fparg0);
    var_7 += 1;
loop_00492a80_check:
    if (var_7 < 3U) {
        goto loop_00492a80_body;
    }
    *(f32 *)(temp_6 + 0xC8) = *(f32 *)(temp_5 + 0xC8) * fparg0;
    *(f32 *)(temp_6 + 0xCC) = *(f32 *)(temp_5 + 0xCC) * fparg0;
    *(f32 *)(temp_6 + 0xD4) = *(f32 *)(temp_5 + 0xD4) * fparg0;
    *(f32 *)(temp_6 + 0xD8) = *(f32 *)(temp_5 + 0xD8) * fparg0;
    *(f32 *)(temp_6 + 0xE0) = *(f32 *)(temp_5 + 0xE0) * fparg0;
}


// FUN_00492CD0
void func_00492cd0(u8 *arg0)
{
    jtbl_008873EC[0](*(void **)(arg0 + 0x28));
}


// FUN_00492D00
void func_00492d00(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}


/* measured: probing opt_loop_invariants for the preheader -1 and loop branch. */
#pragma opt_loop_invariants on
// FUN_00492D10
void func_00492d10(void *object) {
    u8 *arg0 = object;
    extern void (*D_00713D50[])(u8 *emitter);
    u32 count;
    u32 var_6;
    u8 *var_5;

    if (*(s32 *)(arg0 + 0x10) == 0) {
        count = *(u32 *)(arg0 + 8);
        var_5 = *(u8 **)(arg0 + 0x18);
        var_6 = 0;
        goto loop_00492d10_check;
loop_00492d10_body:
        *(s32 *)(var_5 + 0x10) = -1;
        var_5 += 0x20;
        var_6 += 1;
loop_00492d10_check:
        if (var_6 < count) {
            goto loop_00492d10_body;
        }
    }
    D_00713D50[*(u16 *)arg0 * 4](arg0);
    *(s32 *)(arg0 + 0x10) = *(s32 *)(arg0 + 0x10) + 1;
}


// Loads the 128-bit quad at +0x20 of the object at param_1 into *param_2 and returns it.
// FUN_00492DB0
u_long128 mdlEffectLoadQuadA(int param_1, u32 *param_2)
{
  u_long128 value = *(u_long128 *)(*(int *)(param_1 + 0x20));
  *(u_long128 *)param_2 = value;
  return value;
}


/* measured: opt_propagation off preserves mdlEffectStoreQuadA's 128-bit load/store ordering (MATCH nd0). */
#pragma opt_propagation off

// Stores the 128-bit quad at *param_2 into +0x20 of the object at param_1 and returns it.
// FUN_00492DD0
u_long128 mdlEffectStoreQuadA(int param_1, u32 *param_2)
{
  u_long128 *dst;
  u_long128 value;

  dst = *(u_long128 **)(param_1 + 0x20);
  value = *(u_long128 *)param_2;
  *dst = value;
  return value;
}

/* measured: opt_propagation on closes the mdlEffectStoreQuadA bracket. */
#pragma opt_propagation on


// Loads the 128-bit quad at +0x30 of the object at param_1 into *param_2 and returns it.
// FUN_00492DF0
u_long128 mdlEffectLoadQuadB(int param_1, u32 *param_2)
{
  return *(u_long128 *)param_2 =
      *(u_long128 *)(*(int *)(param_1 + 0x20) + 0x10);
}


/* measured: opt_propagation off preserves mdlEffectStoreQuadB's 128-bit load/store ordering (MATCH nd0). */
#pragma opt_propagation off

// Stores the 128-bit quad at *param_2 into +0x30 of the object at param_1 and returns it.
// FUN_00492E10
u_long128 mdlEffectStoreQuadB(int param_1, u32 *param_2)
{
  u_long128 *dst;
  u_long128 value;

  dst = (u_long128 *)(*(int *)(param_1 + 0x20) + 0x10);
  value = *(u_long128 *)param_2;
  *dst = value;
  return value;
}
/* measured: opt_propagation on closes the mdlEffectStoreQuadB bracket. */
#pragma opt_propagation on



/* measured: closes opt_loop_invariants at its prior file baseline. */
#pragma opt_loop_invariants off
// FUN_00492E30
void func_00492e30(u16 *arg0, f32 scale) {
    D_00713D54[*arg0 * 4]((u8 *)arg0, scale);
}


/* Stores 0 in the slot-table entry for param_2 (table at +0x18); -1 is the free state. */
// FUN_004946D0
void mdlEffectSlotSetZero(u8 *param_1, u16 param_2)
{
  u32 index;
  u8 *base;

  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  *(u16 *)(base + index) = 0;

  return;
}



/* Stores -1 (the free state) in the slot-table entry for param_2. */
// FUN_004946F0
void mdlEffectSlotRelease(u8 *param_1, u16 param_2)
{
  s16 value;
  u32 index;
  u8 *base;

  value = -1;
  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  *(s16 *)(base + index) = value;

  return;

}



/* Returns 1 when the slot-table entry for param_2 holds -1 (free). */
// FUN_00494710
s32 mdlEffectSlotIsFree(u8 *param_1, u16 param_2)
{
  u32 index;
  u8 *base;
  s16 value;

  index = (param_2 & 0xffff) * 2;
  base = *(u8 **)(param_1 + 0x18);
  value = *(s16 *)(base + index);

  return value == -1;
}



#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma opt_pulloutconstants off
#pragma pop
#pragma push
#pragma opt_loop_invariants on
#pragma pop
// FUN_00494F90
void func_00494f90(u8 *arg0) {
    mdlEffectCopyCameraOrigin(arg0);
    RpGeometryLock(*(RpGeometry **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x10)) + 0x10)) + 0x18), 0xA);
    RpGeometryLock(*(RpGeometry **)((u8 *)(*(u8 **)((u8 *)(*(u8 **)(arg0 + 0x14)) + 0x10)) + 0x18), 0xA);
}


// FUN_00494FF0
void func_00494ff0(u8 *arg0) {
    extern void func_003c22f0(void *);
    u8 *temp_16;
    u8 *temp_17;
    u8 *temp_17_2;
    u8 *temp_18;

    temp_18 = *(u8 **)(arg0 + 0x14);
    temp_17 = *(u8 **)(*(u8 **)(temp_18 + 0x10) + 0x18);
    func_003c22f0(temp_17);
    if (*(u16 *)temp_18 & 4) {
        *(u16 *)(temp_17 + 0xC) = *(u16 *)(temp_17 + 0xC) | 1;
    }
    temp_17_2 = *(u8 **)(arg0 + 0x10);
    temp_16 = *(u8 **)(*(u8 **)(temp_17_2 + 0x10) + 0x18);
    func_003c22f0(temp_16);
    if (*(u16 *)temp_17_2 & 4) {
        *(u16 *)(temp_16 + 0xC) = *(u16 *)(temp_16 + 0xC) | 1;
    }
}


// FUN_00495090
void func_00495090(u8 *arg0, u32 arg1)
{
    func_00484280(*(u8 **)(arg0 + 0x10), (s32)arg1);
    func_00484280(*(u8 **)(arg0 + 0x14), (s32)arg1);
}


// FUN_004950E0
void func_004950e0(u8 *arg0) {
    u32 temp_16;
    u8 *var_18;
    u32 var_17;

    var_18 = *(u8 **)(*(u8 ***)(arg0 + 0x30));
    temp_16 = *(u32 *)(*(u8 **)(arg0 + 0x34) + 0x38);
    var_17 = 0;
    goto loop_004950e0_check;
loop_004950e0_body:
    *(s32 *)(var_18 + 4) = -1 - (effMiscRand(0) & 3);
    var_17 += 1;
    var_18 += 0x10;
loop_004950e0_check:
    if (var_17 < temp_16) {
        goto loop_004950e0_body;
    }
}


/* Calls kind slot +0x08 with the object itself, then frees it through the allocator free table; the kind index is at +0x2C. */
// FUN_00498AC0
void ThunderInstanceDestroy(u8 *arg0) {
    D_00713E78[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    jtbl_008873EC[0](arg0);
}


// FUN_00498B20
void *func_00498b20(void *source) {
    u8 *arg0 = source;

    return ThunderTextureForIndex(*(u16 *)(arg0 + 0x2C), *(u8 **)(arg0 + 0x34));
}


/* Calls kind slot +0x00 with the object, then clears the counter at +0x28. */
// FUN_00498B50
void ThunderInstanceStop(u8 *arg0) {
    D_00713E70[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    *(s32 *)(arg0 + 0x28) = 0;
}


/* Calls kind slot +0x0C with the object, then increments the counter at +0x28. */
// FUN_00498BA0
void ThunderInstanceAdvance(u8 *arg0) {
    D_00713E7C[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    *(s32 *)(arg0 + 0x28) = *(s32 *)(arg0 + 0x28) + 1;
}


/* Calls kind slot +0x10 with the object when the counter at +0x28 is positive. */
// FUN_00498C00
void ThunderInstanceUpdateIfActive(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x28) > 0) {
        D_00713E80[*(s32 *)(arg0 + 0x2C) * 6](arg0);
    }
}


/* Copies the 16-byte quad at arg1 to the object base and returns it. */
// FUN_00498CE0
u_long128 ThunderSetFirstQuad(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}


/* Copies the 16-byte quad at arg1 to +0x10 of the object and returns it. */
// FUN_00498CF0
u_long128 ThunderSetSecondQuad(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}


// FUN_00498D00
void func_00498d00(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}


// FUN_00498D10
void func_00498d10(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
}


/* Calls kind slot +0x08 on the child at +0x3C, then frees the object; the kind index is at +0x38. */
// FUN_0049A570
void RingInstanceDestroy(u8 *arg0) {
    D_00713F18[*(s32 *)(arg0 + 0x38) * 6](*(void **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}


// FUN_0049A5E0
void *func_0049a5e0(void *source) {
    u8 *arg0 = source;

    return RingCreateKindInstance(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
}


/* Calls kind slot +0x00 with the object, then clears the counter at +0x34. */
// FUN_0049A610
void RingInstanceStop(u8 *arg0) {
    D_00713F10[*(s32 *)(arg0 + 0x38) * 6](arg0);
    *(s32 *)(arg0 + 0x34) = 0;
}


/* Calls kind slot +0x0C with the object, then increments the counter at +0x34. */
// FUN_0049A660
void RingInstanceAdvance(u8 *arg0) {
    D_00713F1C[*(s32 *)(arg0 + 0x38) * 6](arg0);
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}


/* Calls kind slot +0x10 with the object when the counter at +0x34 is positive. */
// FUN_0049A6C0
void RingInstanceUpdateIfActive(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        D_00713F20[*(s32 *)(arg0 + 0x38) * 6](arg0);
    }
}


/* Copies the 16-byte quad at arg1 to the object base and returns it. */
// FUN_0049A7A0
u_long128 RingSetFirstQuad(u_long128 *arg0, u_long128 *arg1) {
    return *arg0 = *arg1;
}


/* Copies the 16-byte quad at arg1 to +0x10 of the object and returns it. */
// FUN_0049A7B0
u_long128 RingSetSecondQuad(u_long128 *arg0, u_long128 *arg1) {
    return arg0[1] = *arg1;
}


// FUN_0049A7C0
void func_0049a7c0(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}


/* Writes the same float to +0x20, +0x24 and +0x28, giving a uniform scale. */
// FUN_0049A7D0
void RingSetUniformScale(u8 *arg0, f32 fparg0) {
    *(f32 *)(arg0 + 0x20) = fparg0;
    *(f32 *)(arg0 + 0x24) = fparg0;
    *(f32 *)(arg0 + 0x28) = fparg0;
}


/* Copies the three floats of arg1 into +0x20, +0x24 and +0x28. */
// FUN_0049A7F0
void RingSetVec3(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}


extern void func_004a5ef0(u8 *arg0, u8 *arg1);
extern void func_004ade80(u8 *arg0);
extern void func_004a5fc0(u8 *arg0);
extern u8 *func_004a6c00(u8 *arg0);
extern u8 *WindAllocKindEntry(u16 arg0, u8 *arg1);
extern u8 D_0071413C[];
extern void func_004adb50();
extern void func_004ade80(u8 *arg0);
extern f32 iGpffff8080;
extern void (*D_008873ec[])(void *);
extern s32 D_00724C70;
extern s8 D_00724C58;
extern f32 D_00922D80[];
extern u8 *func_00401b80(void);
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
extern void func_004a7c00(u8 *arg0, s32 arg1);
extern void mdlSetLayerTime(u8 *arg0, s32 arg1, f32 arg2);
extern f32 fGpffff80f4;
extern void func_004a5ef0(u8 *arg0, u8 *arg1);
extern u8 *GeometryCloneBlock(s32 arg0);
extern void mdlSetResetCallback(void *arg0, void (*arg1)(void), void *arg2);
extern void func_00485fe0(s32 arg0);
extern void *func_004a5bb0(void *source);
/* Calls kind destroy slot +0x08 on the child at +0x3C, then frees arg0 through the allocator free table. */
// FUN_004A18E0
void FlashQuadDestroy(u8 *arg0) {
    (*(void (**)(u8 *))(D_00714018 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(*(u8 **)(arg0 + 0x3C));
    jtbl_008873EC[0](arg0);
}


/* Calls kind slot +0x00 with no argument, then clears the counter at +0x34. */
// FUN_004A1AA0
void FlashQuadStop(u8 *arg0) {
    (*(void (**)(void))(D_00714010 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}


/* Calls kind slot +0x10 with no argument, then increments the counter at +0x34. */
// FUN_004A1AF0
void FlashQuadAdvance(u8 *arg0) {
    (*(void (**)(void))(D_00714020 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    (*(s32 *)(arg0 + 0x34))++;
}


/* Calls kind slot +0x14 with no argument when the counter at +0x34 is positive. */
// FUN_004A1B50
void FlashQuadUpdateIfActive(u8 *arg0) {
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714024 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}


/* Calls kind slot +0x10, increments the counter at +0x34, then calls kind slot +0x14 with arg0 when the counter is positive. */
// FUN_004A1BA0
void FlashQuadAdvanceAndUpdate(u8 *arg0) {
    (*(void (**)(void))(D_00714020 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    (*(s32 *)(arg0 + 0x34))++;
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(u8 *))(D_00714024 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    }
}


/* Copies the 16-byte quad at arg1 to +0x00 and returns it. */
// FUN_004A1C30
u_long128 FlashQuadSetFirstQuad(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}


/* Copies the 16-byte quad at arg1 to +0x10 and returns it. */
// FUN_004A1C40
u_long128 FlashQuadSetSecondQuad(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}


// FUN_004A1C50
void func_004a1c50(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x30) = arg1;
}


/* Writes the same float to +0x20, +0x24 and +0x28, giving a uniform scale. */
// FUN_004A1C60
void FlashQuadSetUniformScale(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
    *(f32 *)(arg0 + 0x24) = arg1;
    *(f32 *)(arg0 + 0x28) = arg1;
}


/* Copies the three floats of arg1 into +0x20, +0x24 and +0x28. */
// FUN_004A1C80
void FlashQuadSetVec3(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
/* measured: restores the file's O2 loop-invariant baseline. */
#pragma opt_loop_invariants off
/* Calls kind slot +0x08 with the object, then frees it through the allocator free table. The kind index is at +0x38. */
// FUN_004A58B0
void WindInstanceDestroy(u8 *arg0)
{
    (*(void (**)(u8 *))(D_00714138 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    jtbl_008873EC[0](arg0);
}


// FUN_004A5910
void *func_004a5910(void *source)
{
    u8 *arg0 = (u8 *)source;
    u8 *temp_16;

    temp_16 = WindAllocKindEntry(*(u16 *)(arg0 + 0x38), *(u8 **)(arg0 + 0x40));
    *(s32 *)(temp_16 + 0x3C) =
        (*(s32 (**)(u8 *))(D_0071413C + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    (*(void (**)(u8 *))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(temp_16);
    return temp_16;
}


/* Calls kind slot +0x00 with no argument, then clears the counter at +0x34. The kind index is at +0x38. */
// FUN_004A59B0
void WindInstanceStop(u8 *arg0)
{
    (*(void (**)(void))(D_00714130 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = 0;
}


/* Calls kind slot +0x10 with no argument, then increments the counter at +0x34. */
// FUN_004A5A00
void WindInstanceAdvance(u8 *arg0)
{
    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    *(s32 *)(arg0 + 0x34) = *(s32 *)(arg0 + 0x34) + 1;
}


/* Calls kind slot +0x14 with no argument when the counter at +0x34 is positive. */
// FUN_004A5A60
void WindInstanceUpdateIfActive(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x34) > 0) {
        (*(void (**)(void))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    }
}


/* Calls kind slot +0x10 with no argument, increments the counter at +0x34, then calls kind slot +0x14 with the object when the counter is positive. The kind index is at +0x38. */
// FUN_004A5AB0
void WindInstanceAdvanceAndUpdate(u8 *arg0)
{
    s32 temp_3;

    (*(void (**)(void))(D_00714140 + (*(s32 *)(arg0 + 0x38) * 0x1C)))();
    temp_3 = *(s32 *)(arg0 + 0x34) + 1;
    *(s32 *)(arg0 + 0x34) = temp_3;
    if (temp_3 > 0) {
        (*(void (**)(u8 *))(D_00714144 + (*(s32 *)(arg0 + 0x38) * 0x1C)))(arg0);
    }
}


/* Copies the 16-byte quad at arg1 to the object base and returns it. */
// FUN_004A5B40
u_long128 WindSetFirstQuad(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}


/* Copies the 16-byte quad at arg1 to +0x10 of the object and returns it. */
// FUN_004A5B50
u_long128 WindSetSecondQuad(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}


// FUN_004A5B60
void func_004a5b60(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x30) = arg1;
}


/* Writes the same float to +0x20, +0x24 and +0x28, giving a uniform scale. */
// FUN_004A5B70
void WindSetUniformScale(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
    *(f32 *)(arg0 + 0x24) = arg1;
    *(f32 *)(arg0 + 0x28) = arg1;
}


/* Copies the three floats of arg1 into +0x20, +0x24 and +0x28. */
// FUN_004A5B90
void WindSetVec3(u8 *arg0, f32 *arg1) {
    *(f32 *)(arg0 + 0x20) = arg1[0];
    *(f32 *)(arg0 + 0x24) = arg1[1];
    *(f32 *)(arg0 + 0x28) = arg1[2];
}


// FUN_004A5E50
void *func_004a5e50(void *source)
{
    u8 *arg0 = (u8 *)source;
    u8 *temp_16;
    u8 *temp_2;
    u8 *temp_3;

    temp_16 = func_004a5bb0(NULL);
    temp_2 = GeometryCloneBlock(*(s32 *)(arg0 + 0xC8));
    *(u8 **)(temp_16 + 0xC8) = temp_2;
    temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2 + 0x10) + 0x18) + 0x30);
    *(s32 *)(temp_3 + 0) = -1;
    *(s32 *)(temp_3 + 4) = -1;
    *(s32 *)(temp_3 + 8) = -1;
    *(s32 *)(temp_3 + 0xC) = -1;
    memcpy(temp_16 + 0x30, arg0 + 0x30, 0x98);
    func_004a5ef0(temp_16, arg0);
    return temp_16;
}


// FUN_004A5F90
void func_004a5f90(u8 *arg0)
{
    *(s32 *)(arg0 + 0x2C) = 0;
}


// FUN_004A5FA0
void func_004a5fa0(u8 *arg0) {
    (*(s32 *)(arg0 + 0x2C))++;
}


// FUN_004A6B90
void func_004a6b90(u8 *arg0) {
    (*(s32 *)(arg0 + 0x2C))++;
    func_004a5fc0(arg0);
}


// FUN_004A6BC0
u_long128 func_004a6bc0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}


// FUN_004A6BD0
u_long128 func_004a6bd0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}


// FUN_004A6BE0
void func_004a6be0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}


// FUN_004A6BF0
void func_004a6bf0(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
}


#pragma opt_loop_invariants on
/* measured: close loop-invariant hoisting after func_004a6c00. */
#pragma opt_loop_invariants off
// FUN_004A6D90
void *func_004a6d90(void *source) {
    u8 *temp;
    temp = mdlEffectResolveRelPtrA(source);
    return func_004a6c00(temp);
}


// FUN_004A6E10
void *func_004a6e10(void *source) {
    u8 *arg0 = (u8 *)source;
    return func_004a6c00(arg0 + 0x18);
}


// FUN_004A6E40
void func_004a6e40(u8 *arg0)
{
    *(s32 *)(arg0 + 0x10) = 0;
}


/* Increments the u32 counter at +0x10 of the record by one. */
// FUN_004A6E50
void mdlEffectIncrementCounter(int param_1)
{
  *(u32 *)(param_1 + 0x10) = *(u32 *)(param_1 + 0x10) + 1;
}



// FUN_004A6E70
/* Render the model flare entries around the projected source position.
 * measured with native b210 -O2: 2276/2288 bytes, 53 resolved relocations.
 * Assembly is confined to the packed-color and vector MMI/COP2 bridges. */
#pragma push
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* measured: keep outer-loop material and scale values at their use sites. */
#pragma opt_loop_invariants off
void mdlEffectRenderFlares(u8 *arg0)
{
    extern s32 func_0048abd0(u8 *a, u8 *b, s32 c, s32 d);
    extern RpGeometry *func_003c22f0(RpGeometry *geometry);
    extern RpMaterial *RpMaterialSetTexture(RpMaterial *material, RwTexture *texture);
    extern s32 TnSlotObject(u16 b);
    extern s32 TnGetOffset38(u16 b);
    extern void func_00460ac0(u8 *a, u8 *b);
    extern RwFrame *func_003e9cb0(RwFrame *frame, const RwMatrix *matrix, RwOpCombineType combine);
    extern s32 func_00457120(void);
    extern RwMatrix *RwFrameGetLTM(RwFrame *frame);
    extern f32 sqrtf(f32 x);
    extern u8 D_007141B0[];
    extern f32 D_00922D80[];
    typedef struct { u8 c0; u8 c1; u8 c2; u8 c3; } MdlCol;
    extern MdlCol iGpffffbb64;
    extern f32 fGpffff8044;
    f32 normalization;
    f32 proj[4] __attribute__((aligned(16)));
    f32 gmul[4] __attribute__((aligned(16)));
    f32 dist;
    f32 scale;
    f32 dx;
    f32 dy;
    f32 maxD;
    s32 cnt10;
    s32 cnt50;
    u8 *listBase;
    union { s32 word; MdlCol rgba; } color;
    const u32 *colorSource;
    u32 colA;
    s32 colB;
    u8 *entry;
    u8 *vtxCur;
    u8 *vtxBase;
    u32 *auxCur;
    u32 outer;
    u32 inner;
    s32 tmpX;
    s32 tmpY;
    f32 fx;
    f32 fy;
    f32 f0;
    f32 f1;
    f32 vx0;
    f32 vy0;
    f32 gw;
    s32 isz;
    s32 packed;
    s32 entryColor;
    s32 outWord;
    u8 *slot;
    f32 *fp;
    u32 j;

    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(arg0),
        "m"(*(f32 (*)[4])arg0) : "$vf10", "memory");
    if (mdlEffectAnchorOnScreen() == 0) {
        return;
    }
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(proj) : "r"(proj)
        : "$vf10", "memory");
    dx = proj[0] - 320.0f;
    dy = proj[1] - 224.0f;
    cnt50 = *(s32 *)(arg0 + 0x50);
    cnt10 = *(s32 *)(arg0 + 0x10);
    listBase = *(u8 **)(arg0 + 0x58);
    if (!(cnt50 <= 0 || cnt10 < cnt50)) {
        return;
    }
    dist = sqrtf(dx * dx + dy * dy);
    if (dist <= 0.0f) {
        return;
    }
    maxD = sqrtf(152576.0f); /* Squared distance from screen center to its corner. */
    scale = (maxD - dist) / maxD;
    scale = scale * *(f32 *)(arg0 + 0x4C);
    colA = func_0048abd0(arg0 + 0x18, arg0 + 0x3C, cnt10, cnt50);
    colorSource = &colA;
    normalization = fGpffff8044;
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf11\n"
        "vitof0.xyzw $vf11, $vf11\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf11, $vf11, $vf2x\n"
        :
        : "r"(colorSource), "f"(normalization), "m"(colA)
        : "$2", "$vf11", "$vf2", "memory");
    colB = *(s32 *)(arg0 + 0x14);
    __asm__ volatile(
        "lw $2, 0(%0)\n"
        "pextlb $2, $zero, $2\n"
        "pextlh $2, $zero, $2\n"
        "qmtc2.ni $2, $vf10\n"
        "vitof0.xyzw $vf10, $vf10\n"
        "mfc1 $2, %1\n"
        "nop\n"
        "qmtc2.ni $2, $vf2\n"
        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
        "vmul.xyzw $vf10, $vf10, $vf11\n"
        :
        : "r"(&colB), "f"(normalization), "m"(colB)
        : "$2", "$vf10", "$vf2", "memory");
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(gmul) : "r"(gmul)
        : "$vf10", "memory");
    {
        u8 *p = *(u8 **)(listBase + 0x10);
        u8 *q = *(u8 **)(p + 0x18);
        RpGeometryLock((RpGeometry *)q, 0xFF2);
        vtxCur = *(u8 **)(*(u8 **)(*(u8 **)(listBase + 0x10) + 0x18) + 0x5C);
        vtxCur = *(u8 **)(vtxCur + 0x14);
        vtxBase = vtxCur;
        auxCur = *(u32 **)(*(u8 **)(*(u8 **)(listBase + 0x10) + 0x18) + 0x34);
        entry = D_007141B0 + (s32)*(u8 *)(arg0 + 0x54) * 0xD0;
        outer = 0;
        while (outer < 13) {
            if ((*(s32 *)(entry + 0xC) & 0xFF000000) == 0) {
                auxCur = (u32 *)((u8 *)auxCur + 0x80);
/* measured: hoist the four position-record source bases for this loop. */
#pragma opt_loop_invariants on
                for (inner = 0; inner < 4; inner++) {
                    *(RwV3d *)(vtxCur + 0x0) = *(const RwV3d *)D_00922D80;
                    *(RwV3d *)(vtxCur + 0xC) = *(const RwV3d *)D_00922D80;
                    *(RwV3d *)(vtxCur + 0x18) = *(const RwV3d *)D_00922D80;
                    *(RwV3d *)(vtxCur + 0x24) = *(const RwV3d *)D_00922D80;
                    vtxCur += 0x30;
                }
/* measured: restore the outer loop's unhoisted material and scale values. */
#pragma opt_loop_invariants off
                {
                    if (iGpffffbb64.c3 != 0xFF) {
                        u8 *tbl = *(u8 **)(listBase + 0x54);
                        u8 *sl = *(u8 **)(tbl + (outer & 0xFFFF) * 4);
                        *(MdlCol *)(sl + 4) = iGpffffbb64;
                    } else {
                        u8 *tbl;
                        u8 *sl;
                        iGpffffbb64.c3 = 0xFE;
                        tbl = *(u8 **)(listBase + 0x54);
                        sl = *(u8 **)(tbl + (outer & 0xFFFF) * 4);
                        *(MdlCol *)(sl + 4) = iGpffffbb64;
                        iGpffffbb64.c3 = 0xFF;
                    }
                }
            } else {
                s32 idx;
                s32 dev = TnSlotObject(*(u8 *)(entry + 8));
                idx = (outer & 0xFFFF) * 4;
                RpMaterialSetTexture(*(RpMaterial **)(*(u8 **)(listBase + 0x54) + idx), (RwTexture *)(u32)dev);
                fx = dx * *(f32 *)(entry + 0x0);
                fy = dy * *(f32 *)(entry + 0x0);
                tmpX = (s32)(320.0f + fx);
                tmpY = (s32)(224.0f + fy);
                f0 = sqrtf(fx * fx + fy * fy);
                f1 = f0 / dist;
                f1 = f1 * scale;
                f0 = 128.0f;
                f0 = f0 * *(f32 *)(entry + 4);
                f0 = f0 * f1;
                isz = (s32)(0.5f * f0);
                packed = ((u32)(255.0f * sqrtf(f1)) << 24) | 0xFFFFFF;
                normalization = fGpffff8044;
                __asm__ volatile(
                    "lw $2, 0(%0)\n"
                    "pextlb $2, $zero, $2\n"
                    "pextlh $2, $zero, $2\n"
                    "qmtc2.ni $2, $vf11\n"
                    "vitof0.xyzw $vf11, $vf11\n"
                    "mfc1 $2, %1\n"
                    "nop\n"
                    "qmtc2.ni $2, $vf2\n"
                    "vmulx.xyzw $vf11, $vf11, $vf2x\n"
                    :
                    : "r"(&packed), "f"(normalization), "m"(packed)
                    : "$2", "$vf11", "$vf2", "memory");
                entryColor = *(s32 *)(entry + 0xC);
                __asm__ volatile(
                    "lw $2, 0(%0)\n"
                    "pextlb $2, $zero, $2\n"
                    "pextlh $2, $zero, $2\n"
                    "qmtc2.ni $2, $vf10\n"
                    "vitof0.xyzw $vf10, $vf10\n"
                    "mfc1 $2, %1\n"
                    "nop\n"
                    "qmtc2.ni $2, $vf2\n"
                    "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                    "vmul.xyzw $vf10, $vf10, $vf11\n"
                    :
                    : "r"(&entryColor), "f"(normalization), "m"(entryColor)
                    : "$2", "$vf10", "$vf2", "memory");
                __asm__ volatile(
                    "lqc2 $vf11, 0(%0)\n"
                    "vmul.xyzw $vf10, $vf10, $vf11\n"
                    : : "r"(gmul), "m"(gmul) : "$vf10", "$vf11", "memory");
                {
                    u32 colorWork = 0x437F0000U; /* Binary32 255.0f for the VU color scale. */
                    __asm__ volatile(
                        "qmtc2.ni %0, $vf2\n"
                        "vmulx.xyzw $vf10, $vf10, $vf2x\n"
                        "vftoi0.xyzw $vf10, $vf10\n"
                        "qmfc2.ni %0, $vf10\n"
                        "ppach %0, $zero, %0\n"
                        "ppacb %0, $zero, %0\n"
                        "sw %0, outWord\n"
                        : "+r"(colorWork), "=m"(outWord)
                        : : "$vf2", "$vf10", "memory");
                }
                {
                    color.word = outWord;
                    if (color.rgba.c3 != 0xFF) {
                        slot = *(u8 **)(*(u8 **)(listBase + 0x54) + idx);
                        *(MdlCol *)(slot + 4) = color.rgba;
                    } else {
                        color.rgba.c3 = 0xFE;
                        slot = *(u8 **)(*(u8 **)(listBase + 0x54) + idx);
                        *(MdlCol *)(slot + 4) = color.rgba;
                        color.rgba.c3 = 0xFF;
                    }
                }
                auxCur[0] = 0;
                auxCur[1] = 0;
                auxCur[2] = 0x3F700000;
                auxCur[3] = 0;
                auxCur[4] = 0;
                auxCur[5] = 0x3F700000;
                auxCur[6] = 0x3F700000;
                auxCur[7] = 0x3F700000;
                isz = (isz >> 1) - 1;
                vx0 = (f32)(tmpX - isz);
                *(f32 *)(vtxCur + 0x0) = vx0;
                vy0 = (f32)(tmpY - isz);
                *(f32 *)(vtxCur + 0x4) = vy0;
                gw = (f32)isz;
                *(f32 *)(vtxCur + 0xC) = *(f32 *)(vtxCur + 0x0) + gw;
                *(f32 *)(vtxCur + 0x10) = *(f32 *)(vtxCur + 0x4);
                *(f32 *)(vtxCur + 0x18) = *(f32 *)(vtxCur + 0x0);
                *(f32 *)(vtxCur + 0x1C) = *(f32 *)(vtxCur + 0x4) + gw;
                *(f32 *)(vtxCur + 0x24) = *(f32 *)(vtxCur + 0x0) + gw;
                *(f32 *)(vtxCur + 0x28) = *(f32 *)(vtxCur + 0x4) + gw;
                auxCur[8] = 0x3F700000;
                auxCur[9] = 0;
                auxCur[10] = 0;
                auxCur[11] = 0;
                auxCur[12] = 0x3F700000;
                auxCur[13] = 0x3F700000;
                auxCur[14] = 0;
                auxCur[15] = 0x3F700000;
                {
                    f32 vx1 = (f32)tmpX;
                    *(f32 *)(vtxCur + 0x30) = vx1;
                    *(f32 *)(vtxCur + 0x34) = vy0;
                    *(f32 *)(vtxCur + 0x3C) = *(f32 *)(vtxCur + 0x30) + gw;
                    *(f32 *)(vtxCur + 0x40) = *(f32 *)(vtxCur + 0x34);
                    *(f32 *)(vtxCur + 0x48) = *(f32 *)(vtxCur + 0x30);
                    *(f32 *)(vtxCur + 0x4C) = *(f32 *)(vtxCur + 0x34) + gw;
                    *(f32 *)(vtxCur + 0x54) = *(f32 *)(vtxCur + 0x30) + gw;
                    *(f32 *)(vtxCur + 0x58) = *(f32 *)(vtxCur + 0x34) + gw;
                }
                auxCur[16] = 0;
                auxCur[17] = 0x3F700000;
                auxCur[18] = 0x3F700000;
                auxCur[19] = 0x3F700000;
                auxCur[20] = 0;
                auxCur[21] = 0;
                auxCur[22] = 0x3F700000;
                auxCur[23] = 0;
                {
                    f32 vy1 = (f32)tmpY;
                    *(f32 *)(vtxCur + 0x60) = vx0;
                    *(f32 *)(vtxCur + 0x64) = vy1;
                    *(f32 *)(vtxCur + 0x6C) = *(f32 *)(vtxCur + 0x60) + gw;
                    *(f32 *)(vtxCur + 0x70) = *(f32 *)(vtxCur + 0x64);
                    *(f32 *)(vtxCur + 0x78) = *(f32 *)(vtxCur + 0x60);
                    *(f32 *)(vtxCur + 0x7C) = *(f32 *)(vtxCur + 0x64) + gw;
                    *(f32 *)(vtxCur + 0x84) = *(f32 *)(vtxCur + 0x60) + gw;
                    *(f32 *)(vtxCur + 0x88) = *(f32 *)(vtxCur + 0x64) + gw;
                }
                auxCur[24] = 0x3F700000;
                auxCur[25] = 0x3F700000;
                auxCur[26] = 0;
                auxCur[27] = 0x3F700000;
                auxCur[28] = 0x3F700000;
                auxCur[29] = 0;
                auxCur[30] = 0;
                auxCur[31] = 0;
                {
                    f32 vx1 = (f32)tmpX;
                    f32 vy1 = (f32)tmpY;
                    *(f32 *)(vtxCur + 0x90) = vx1;
                    *(f32 *)(vtxCur + 0x94) = vy1;
                    *(f32 *)(vtxCur + 0x9C) = *(f32 *)(vtxCur + 0x90) + gw;
                    *(f32 *)(vtxCur + 0xA0) = *(f32 *)(vtxCur + 0x94);
                    *(f32 *)(vtxCur + 0xA8) = *(f32 *)(vtxCur + 0x90);
                    *(f32 *)(vtxCur + 0xAC) = *(f32 *)(vtxCur + 0x94) + gw;
                    *(f32 *)(vtxCur + 0xB4) = *(f32 *)(vtxCur + 0x90) + gw;
                    *(f32 *)(vtxCur + 0xB8) = *(f32 *)(vtxCur + 0x94) + gw;
                }
                vtxCur += 0xC0;
                auxCur += 0x20;
            }
            outer++;
            entry += 0x10;
        }
    }
    {
        u8 *window = ((u8 *)(u32)func_00457120()) + 0x68;
        f32 nearPlane = *(f32 *)(((u8 *)(u32)func_00457120()) + 0x80);
        f32 farPlane = *(f32 *)(((u8 *)(u32)func_00457120()) + 0x84);
        f32 span = farPlane - nearPlane;
        f32 deviceDepth = (f32)(s32)0xFFFF0001;
        f32 denominator = deviceDepth * farPlane - -255.0f * span;
        f32 numerator;
        f32 k2 = (numerator = deviceDepth * nearPlane, numerator * farPlane) / denominator;
        f32 fA = 2.0f * (*(f32 *)(window + 0) * k2);
        f32 fB = 2.0f * (*(f32 *)(window + 4) * k2);
        f32 fC;
        j = 0;
        fC = 1.0f + k2;
        fp = (f32 *)vtxBase;
/* measured: retain the screen dimensions across the projection loop. */
#pragma opt_loop_invariants on
        while (j < 0xD0) {
            fp[0] = (-fp[0] / 640.0f + 0.5f) * fA;
            fp[1] = (-fp[1] / 448.0f + 0.5f) * fB;
            fp[2] = fC;
            fp += 3;
            j++;
        }
    }
    {
        u8 *p = *(u8 **)(listBase + 0x10);
        u8 *q = *(u8 **)(p + 0x18);
        func_003c22f0((RpGeometry *)q);
        if ((*(u16 *)listBase & 4) != 0) {
            *(u16 *)(q + 0xC) |= 1;
        }
        {
            u8 *r = (u8 *)((u8 *)(u32)func_00457120());
            RwMatrix *s2 = RwFrameGetLTM(*(RwFrame **)(r + 4));
            func_003e9cb0(*(RwFrame **)(listBase + 0xC), s2, rwCOMBINEREPLACE);
        }
        {
            u16 id = *(u16 *)(arg0 + 0x40);
            u8 *wd = (u8 *)(u32)TnGetOffset38(id);
            *(s32 *)(listBase + 0x18) = 0;
            *(s32 *)(listBase + 0x1C) = 0;
            func_00460ac0(wd, listBase + 0x18);
        }
    }
}
#pragma pop
/* Increments the counter at +0x10 and renders the flares via mdlEffectRenderFlares. */
// FUN_004A7760
void mdlEffectIncrementAndRender(u8 *arg0) {
    (*(s32 *)(arg0 + 0x10))++;
    mdlEffectRenderFlares(arg0);
}
/* Copies one 128-bit value from *arg1 into *arg0 and returns it. */
// FUN_004A7790
u_long128 mdlEffectStoreQuad(u_long128 *arg0, u_long128 *arg1)
{
    return *arg0 = *arg1;
}
// Stores param_2 at word 5 (+0x14) of the record at param_1.
// FUN_004A77A0
void mdlEffectSetWord5(u32 *param_1, u32 param_2)
{
  param_1[5] = param_2;
}



#pragma push
#pragma optimization_level 3
#pragma schedule off
#pragma opt_loop_invariants off
#pragma opt_rotateloops off
#pragma tailcall off
#pragma opt_common_subs off
#pragma opt_propagation off
/* measured: restore the enclosing options; owner verification is 92/92 MATCH. */
#pragma pop
// FUN_004A7A50
void func_004a7a50(void) {
    func_003e9c10((u8 *)D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}


// FUN_004A7B10
void func_004a7b10(s32 arg0) {
    func_003e9c10((u8 *)D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)arg0);
}


// FUN_004A7DA0
void func_004a7da0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}


// FUN_004A7DF0
void func_004a7df0(s32 *arg0) {
    func_004a7c00((u8 *)arg0 + 4, *arg0);
    *arg0 += 1;
}


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
// FUN_004A8A50
void func_004a8a50(u8 *arg0, u8 *arg1)
{
    f32 temp_f1;
    f32 temp_f21;
    f32 temp_f20;
    f32 temp_f22;
    u8 *temp_16;

    *(u32 *)arg1 = effMiscRand(0) % (u32)(*(s32 *)(arg0 + 4) + 1);
    *(f32 *)(arg1 + 4) = fGpffff80f4;
    temp_16 = arg1 + 8;
    *(s32 *)(arg1 + 0x10) = *(s32 *)(arg0 + 0x10);
    *(f32 *)(arg1 + 0x14) = *(f32 *)(arg0 + 0x14);
    *(s32 *)(arg1 + 0xC) = *(s32 *)(arg0 + 0xC);
    temp_f20 = 0.5f * (f32)*(s32 *)(arg0 + 0x28);
    temp_f21 = *(f32 *)(arg0 + 0x24);
    temp_f22 = *(f32 *)(arg0 + 0x1C) +
               temp_f21 * (2.0f * (effMiscRandFloat(0) - 0.5f));
    temp_f1 = *(f32 *)(arg0 + 0x20) +
              temp_f21 * (2.0f * (effMiscRandFloat(0) - 0.5f));
    *(f32 *)(temp_16 + 0x14) = temp_f22;
    *(f32 *)(temp_16 + 0x18) = temp_f1;
    *(f32 *)(temp_16 + 0x1C) = temp_f22 - temp_f20;
    *(f32 *)(temp_16 + 0x20) = temp_f1 - temp_f20;
    *(f32 *)(temp_16 + 0x24) = temp_f22 + temp_f20;
    *(f32 *)(temp_16 + 0x28) = temp_f1 + temp_f20;
}


// FUN_004ABB60
void func_004abb60(void)
{
    u8 *temp_2;

    temp_2 = func_00401b80();
    *(u8 **)&D_00922D90[0] = temp_2;
    D_00922D94[0] = (f32)*(s32 *)(temp_2 + 0xC);
    D_00922D98[0] = (f32)*(s32 *)(temp_2 + 0x10);
}


#pragma push
#pragma opt_propagation off
#pragma pop
// FUN_004ADAB0
void func_004adab0(u8 *arg0)
{
    s32 *var_18;
    u32 temp_16;
    u32 var_17;

    if (*(s32 *)(arg0 + 0x9C) != 0) {
        temp_16 = *(u32 *)(arg0 + 0x28);
        var_18 = *(s32 **)(arg0 + 0x98);
        var_17 = 0;
        goto loop_004adab0_check;
loop_004adab0_body:
        func_00485fe0(*var_18);
        var_18++;
        var_17 += 1;
loop_004adab0_check:
        if (var_17 < temp_16) {
            goto loop_004adab0_body;
        }
    }
    mdlSetLayerTime((u8 *)*(s32 *)(arg0 + 0xA0), 0, 0.0f);
    *(s32 *)(arg0 + 0x2C) = 0;
}


// FUN_004ADFA0
void func_004adfa0(u8 *arg0) {
    func_004adb50();
    func_004ade80(arg0);
}


// FUN_004ADFE0
u_long128 func_004adfe0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)arg0 = value;
    return value;
}


// FUN_004ADFF0
u_long128 func_004adff0(u8 *arg0, u8 *arg1) {
    u_long128 value;
    value = *(u_long128 *)arg1;
    *(u_long128 *)(arg0 + 0x10) = value;
    return value;
}


// FUN_004AE000
void func_004ae000(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x24) = arg1;
}


// FUN_004AE010
void func_004ae010(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x20) = arg1;
}


/* Writes the four colour bytes at param_2 into bytes +4..+7 of every entry in the record's entry table. */
// FUN_004AE020
u32 *mdlEffectSetAllColors(u32 *param_1, u8 *param_2)
{
  u32 *t2;
  int t1;
  int t3;
  u8 *t0;

  u8 c0;
  u8 c1;
  u8 c2;
  u8 c3;

  t2 = *(u32 **)((u8 *)param_1 + 0x18);
  t1 = t2[9];
  t3 = 0;
  goto check;
loop:
  t0 = *(u8 **)(t2[8] + t3 * 4);
  c0 = param_2[0];
  c1 = param_2[1];
  c2 = param_2[2];
  c3 = param_2[3];
  c0 = c0;
  c1 = c1;
  c2 = c2;
  c3 = c3;
  t0[4] = c0;
  t0[5] = c1;
  t0[6] = c2;
  t0[7] = c3;
  t3 = t3 + 1;
check:
  if (t3 < t1) goto loop;
  return param_1;
}



// Sets bit 0x40 in the word at +0x08 of the record at +0x18 of param_1 and returns param_1.
// FUN_004AE080
void *mdlEffectSetFlag40(void *param_1, void *data)
{
  u32 *p;

  p = *(u32 **)((u8 *)param_1 + 0x18);
  p[2] = p[2] | 0x40;
  return param_1;
}



// FUN_004AE0A0
void func_004ae0a0(u8 *arg0, u8 *arg1)
{
    f32 sp40[4];
    f32 temp_f0;
    s32 temp_4;

    if (*(u8 *)(arg0 + 0x10) == 0) {
        sp40[0] = *(f32 *)(arg0 + 0x14);
        sp40[1] = *(f32 *)(arg0 + 0x18);
        sp40[2] = *(f32 *)(arg0 + 0x1C);
    } else {
        sp40[0] = 2.0f * (effMiscRandFloat(0) - 0.5f);
        sp40[1] = 2.0f * (effMiscRandFloat(0) - 0.5f);
        sp40[2] = 2.0f * (effMiscRandFloat(0) - 0.5f);
    }
    __asm__ volatile(
        "lqc2 $vf10, 0(%1) \n"
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vaddy.x $vf2, $vf2, $vf2y \n"
        "vaddz.x $vf2, $vf2, $vf2z \n"
        ".word 0x4A0203BD \n"
        "vwaitq \n"
        "cfc2.ni $2, $vi22 \n"
        "mtc1 $2, %0 \n"
        : "=f"(temp_f0)
        : "r"(sp40)
        : "$2", "$vf2", "$vf10", "Q", "memory");
    if (temp_f0 == 0.0f) {
        goto normalized_zero;
    }
    __asm__ volatile(
        "vmul.xyz $vf2, $vf10, $vf10 \n"
        "vmulax.w $ACC, $vf0, $vf2x \n"
        "vmadday.w $ACC, $vf0, $vf2y \n"
        "vmaddz.w $vf2, $vf0, $vf2z \n"
        "vrsqrt $Q, $vf0w, $vf2w \n"
        "vwaitq \n"
        "vmulq.xyz $vf10, $vf10, $Q \n"
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(sp40)
        : "$vf0", "$vf2", "$vf10", "ACC", "Q", "memory");
    *(f32 *)(arg1 + 0) = sp40[0];
    *(f32 *)(arg1 + 4) = sp40[1];
    *(f32 *)(arg1 + 8) = sp40[2];
    goto normalized_done;
normalized_zero:
    *(f32 *)(arg1 + 0) = 0.0f;
    *(f32 *)(arg1 + 4) = 1.0f;
    *(f32 *)(arg1 + 8) = 0.0f;
normalized_done:
    temp_f0 = *(f32 *)(arg0 + 0x28);
    temp_f0 = (1.0f - temp_f0) + temp_f0 * effMiscRandFloat(0);
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg0 + 0x24) * temp_f0;
    *(f32 *)(arg1 + 0x0C) = iGpffff8080 * effMiscRandFloat(0);
    temp_4 = *(s32 *)(arg0 + 0x34);
    switch (temp_4) {
    case 1:
        *(u8 *)(arg1 + 0x14) = (u8)(effMiscRand(0) % 6);
        break;
    case 2:
        *(u8 *)(arg1 + 0x14) =
            (u8)(((u32)((u8 *)arg1 - *(u8 **)(arg0 + 0x5C)) / 0x18) % 6);
        break;
    default:
        *(s8 *)(arg1 + 0x14) = -1;
        break;
    }
}


// FUN_004AF5E0
void func_004af5e0(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(*(s32 *)(instance + 0x58), position);
}


// FUN_004AF610
void func_004af610(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(*(s32 *)(instance + 0x58), rotation);
}


// FUN_004AF640
void func_004af640(u8 *arg0, s32 arg1) {
    *(s32 *)(arg0 + 0x4) = arg1;
}


// FUN_004AF650
void func_004af650(u8 *arg0, f32 arg1) {
    *(f32 *)(arg0 + 0x8) = arg1;
    func_00492e30(*(u16 **)(arg0 + 0x58), arg1);
}


extern void func_004b1a00(u8 *arg0, u8 *arg1);
extern s32 iGpffffbb98;
extern s32 iGpffffbb94;
extern s32 D_00922DA0[];
extern s16 D_00922DA4[];
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern void func_004861f0(void *arg0, f32 *arg1);
extern void func_004b1ad0(u8 *arg0);
extern void func_003efd20(u8 *arg0, s32 arg1);
extern void func_003e9390(s32 arg0);
extern void func_003ec330(s32 arg0);
extern void func_0040fcd0(s32 arg0, s32 arg1);
extern void func_003e8440(u8 *arg0);
extern void func_004b1a00(u8 *arg0, u8 *arg1);
extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern void func_004866e0(u8 *arg0, u32 *arg1);
extern void func_00486330(u8 *arg0, void *arg1);
extern void effMiscEulerToQuatVU(f32 arg0, f32 arg1, f32 arg2);
extern f32 iGpffff836c;
extern void func_004866f0(u8 *arg0, u32 *arg1);
extern void func_004865c0(u8 *arg0, s32 arg1);
extern u32 func_00486700(void *object);
typedef signed __int128 s128;
extern void *func_004b16c0(void *opaqueSource);
typedef signed __int128 s128;
typedef signed __int128 s128;
// FUN_004B1090
void func_004b1090(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(*(s32 *)(instance + 0x5c), position);
}


// FUN_004B10C0
void func_004b10c0(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(*(s32 *)(instance + 0x5c), rotation);
}


// FUN_004B10F0
void func_004b10f0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x4) = arg1;
}


// FUN_004B1100
void func_004b1100(u8 *arg0, f32 arg1)
{
    *(f32 *)(arg0 + 8) = arg1;
    func_00492e30(*(u16 **)(arg0 + 0x5c), arg1);
}


// FUN_004B1250
void func_004b1250(void *arg0, f32 *arg1)
{
    f32 work[4];

    work[0] = arg1[0];
    work[1] = arg1[1];
    work[2] = arg1[2];
    work[3] = 0.0f;
    func_004861f0(arg0, work);
}


// FUN_004B1290
void func_004b1290(u8 *arg0, f32 arg1, f32 arg2, f32 arg3)
{
    u8 scratch[16];

    effMiscEulerToQuatVU(iGpffff836c * arg1, iGpffff836c * arg2, iGpffff836c * arg3);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(scratch) : "memory");
    func_00486330(arg0, scratch);
}


// FUN_004B13F0
void func_004b13f0(void *object, s32 *arg1) {
    func_004865c0(object, *arg1);
}


// FUN_004B1470
void func_004b1470(u8 *arg0, u8 *arg1)
{
    struct {
        f32 projected[3];
        u32 alignment;
        u8 vector[16];
    } scratch;

    func_004866f0(arg0, (u32 *)scratch.vector);
    mdlEffectBuildBasisRows(arg1, scratch.vector);
    func_004866e0(arg0, (u32 *)scratch.projected);
    *(f32 *)(arg1 + 0x30) = scratch.projected[0];
    *(f32 *)(arg1 + 0x34) = scratch.projected[1];
    *(f32 *)(arg1 + 0x38) = scratch.projected[2];
}


// FUN_004B14F0
void func_004b14f0(void *object, s32 *arg1) {
    *arg1 = func_00486700(object);
}


// Returns the word at +0x84 of the object at param_1.
// FUN_004B1580
u32 mdlEffectGetWord84(int param_1)
{
  return *(u32 *)(param_1 + 0x84);
}



// FUN_004B1590
void mdlEffectSeqStart(s32 arg0, s16 arg1)
{
    D_00922DA0[0] = arg0;
    D_00922DA4[0] = arg1;
    D_00922DA8[0] = 0;
    D_00922DAC[0] = 0;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}


// FUN_004B1600
void mdlEffectSeqStep(void)
{
    s32 temp_5;
    s32 limit;

    if (iGpffffbb98 != 0) {
        limit = D_00922DA0[0];
        if ((iGpffffbb94 < limit) || (limit == 0)) {
            temp_5 = iGpffffbb94;
            func_004a7c00((u8 *)&D_00922DA0[0], temp_5);
        } else {
            func_004a7a50();
            iGpffffbb98 = 0;
        }
        iGpffffbb94 = iGpffffbb94 + 1;
    }
}


// FUN_004B1950
void *func_004b1950(void *opaqueSource) {
    u8 *arg0 = opaqueSource;
    s32 temp_4;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_3;

    temp_2 = func_004b16c0(NULL);
    *(s32 *)(temp_2 + 4) = *(s32 *)(arg0 + 4);
    memcpy(temp_2 + 0xC, arg0 + 0xC, 0x98);
    temp_4 = *(s32 *)(arg0 + 0xA4);
    if (temp_4 != 0) {
        temp_2_2 = GeometryCloneBlock(temp_4);
        *(u8 **)(temp_2 + 0xA4) = temp_2_2;
        temp_3 = *(u8 **)(*(u8 **)(*(u8 **)(temp_2_2 + 0x10) + 0x18) + 0x30);
        *(s32 *)(temp_3 + 0) = -1;
        *(s32 *)(temp_3 + 4) = -1;
        *(s32 *)(temp_3 + 8) = -1;
        *(s32 *)(temp_3 + 0xC) = -1;
    }
    func_004b1a00(temp_2, arg0);
    return temp_2;
}


// FUN_004B1AA0
void func_004b1aa0(u8 *arg0)
{
    *(s32 *)(arg0 + 0x8) = 0;
}


// FUN_004B1AB0
void func_004b1ab0(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 8) + 1;
}


#pragma push
#pragma opt_loop_invariants on
#pragma pop
// FUN_004B2740
void func_004b2740(u8 *arg0)
{
    *(s32 *)(arg0 + 8) = *(s32 *)(arg0 + 8) + 1;
    func_004b1ad0(arg0);
}


// Stores param_2 into the word at *param_1.
// FUN_004B2770
void mdlEffectStoreWord(u32 *param_1, u32 param_2)
{
  *param_1 = param_2;
}
#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma pop
// FUN_004B2E00
void func_004b2e00(u8 *object) {
    u8 *base;
    u8 *temp_2;
    u8 *temp_3;
    u8 *temp_4;
    s32 *slot_1;
    s32 *slot_2;
    s32 temp_17;
    s32 temp_4_2;
    s32 temp_4_3;

    base = object;
    temp_4 = *(u8 **)(base + 0xC);
    if (temp_4 != NULL) {
        temp_17 = *(s32 *)(temp_4 + 4);
        if (temp_17 != 0) {
            func_003efd20(temp_4, 0);
            func_003e9390(temp_17);
        }
        temp_3 = *(u8 **)(base + 0xC);
        slot_1 = (s32 *)(temp_3 + 0x64);
        temp_4_2 = *(s32 *)(temp_3 + 0x64);
        if (temp_4_2 != 0) {
            *slot_1 = 0;
            func_003ec330(temp_4_2);
        }
        temp_2 = *(u8 **)(base + 0xC);
        slot_2 = (s32 *)(temp_2 + 0x60);
        if (*(s32 *)(temp_2 + 0x60) != 0) {
            *slot_2 = 0;
        }
        func_003e8440(*(u8 **)(base + 0xC));
        *(u8 **)(base + 0xC) = NULL;
    }
    temp_4_3 = *(s32 *)(base + 8);
    if (temp_4_3 != 0) {
        func_0040fcd0(temp_4_3, 0);
        func_003ec330(*(s32 *)(base + 8));
        *(s32 *)(base + 8) = 0;
    }
}


/* Calls kind slot +0x00 with the object, then clears the counter at +0x14. The kind index is at +0x18. */
// FUN_004B4F40
void LineNovaInstanceStop(u8 *arg0)
{
    ((void (*)(void *))(*(u32 *)(D_00714650 + (*(s32 *)(arg0 + 0x18) * 24))))(arg0);
    *(s32 *)(arg0 + 0x14) = 0;
}


/* Calls kind slot +0x0C with the object, then increments the counter at +0x14. */
// FUN_004B4F90
void LineNovaInstanceAdvance(void *param_1) {
    ((void (*)(void *))(*(u32 *)(D_0071465C + *(s32 *)((char *)param_1 + 0x18) * 24)))(param_1);
    *(s32 *)((char *)param_1 + 0x14) += 1;
}


/* Calls kind slot +0x10 with the object when the counter at +0x14 is positive. */
// FUN_004B4FF0
void LineNovaInstanceUpdateIfActive(u8 *arg0)
{
    if (*(s32 *)(arg0 + 0x14) > 0) {
        ((void (*)(void *))(*(u32 *)(D_00714660 + (*(s32 *)(arg0 + 0x18) * 24))))(arg0);
    }
}


/* Calls kind slot +0x0C, increments the counter at +0x14, then calls kind slot +0x10 when the counter is positive. The kind index is at +0x18. */
// FUN_004B5040
void LineNovaInstanceAdvanceAndUpdate(void *param_1) {
    u8 *object;

    object = param_1;
    ((void (*)(void *))(*(u32 *)(D_0071465C + *(s32 *)(object + 0x18) * 24)))(object);
    *(s32 *)(object + 0x14) += 1;
    if (*(s32 *)(object + 0x14) > 0) {
        ((void (*)(void *))(*(u32 *)(D_00714660 + *(s32 *)(object + 0x18) * 24)))(object);
    }
}


// FUN_004B50D0
s128 func_004b50d0(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


// FUN_004B50E0
void func_004b50e0(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x10) = arg1;
}


// FUN_004B5750
s128 func_004b5750(s128 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *arg0 = temp;
    return temp;
}


// FUN_004B5760
s128 func_004b5760(u8 *arg0, s128 *arg1) {
    s128 temp = *arg1; /* measured: without the local, MWCC reloads after the store */
    *(s128 *)(arg0 + 0x10) = temp;
    return temp;
}


// FUN_004B5770
void func_004b5770(u8 *arg0, s32 arg1)
{
    *(s32 *)(arg0 + 0x24) = arg1;
}


// FUN_004B5780
void func_004b5780(u8 *arg0, f32 arg1)
{
    *(f32 *)(arg0 + 0x20) = arg1;
}



#include "rw_types_internal.h"
#include "include_asm.h"
#include "rw_geometry_internal.h"
/* Source unit: src/Graphics/Model/mdlFile_0047d2d0.c (1 function markers) */
#include "type.h"
#include "mdl_effect_internal.h"
#include "effect_instance_internal.h"
#include "effect_update_internal.h"
extern void *mdlEffectCloneHelperInstance(void *opaqueSource);
extern f32 effMiscRandFloat(EffRandState *state);
extern void *WindCreateKindEntryAlt(void *source);
extern void *mdlEffectCloneInstance(void *source);
extern void *mdlEffectCreateGridForObject(void *source);
extern void *mdlEffectCreateGridFromInstance(void *source);
extern u8 *RingCreateKindInstance(u16 kind, u8 *parameters);
extern RpGeometry *RpGeometryLock(RpGeometry *geometry, s32 lockMode);
extern u8 *ThunderTextureForIndex(u16 kind, u8 *parameters);
extern void *ThunderTextureForRecord(void *source);
extern void *RingCreateInstanceForRecord(void *source);
extern s32 datEntryEvaluateFlags(s16 item);
extern void free(void *ptr);

typedef int (*code)();
extern code DAT_008873ec_abs[];
extern void mdlEffectListReleaseNodes(u32 *list);

extern void mdlEffectFlushWithTable(s32 table, s32 effect);

extern void mdlEffectStart();

extern void mdlEffectSetPackedColor(void *object, s32 *packedColor);

extern void mdlEffectSetUniformScale(float value, u8 data[][16]);
extern void mdlEffectListReleaseHandles(u32 *list);
extern void mdlEffectDestroy(int model);
extern u32 mdlEffectCreateFromResource(u32 resource);
extern u32 mdlEffectClone();

extern void mdlEffectAdvanceTrackQuad(int *player, u8 *track, float *output);


extern void ParticleProjectVertices(u8 *particle, f32 scale);
extern void func_00487fb0_evt(float value);

extern void EffEmitterApplyScale(u16 *emitter, f32 scale);

typedef unsigned int u_long128 __attribute__((mode(TI)));
extern void func_003f3eb0(s32 input, s32 data);
extern u8 *iGpffffb884;
extern u64 iGpffffb8c8;
extern u64 iGpffffb8e8;

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern u8 D_007131E8[];
/* Defined below in this file; called at line 54, above its definition. */
extern void mdlEffectListClear(u32 *list);
extern s32 kwlnGetCamera(void);
extern u8 *func_003e9700(s32 input);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void memset(void *dest, s32 value, s32 size);
extern s32 mdlCopyIndexedMatrix(void *model, s32 index, void *destination);
extern void func_003e0670(void *matrixOut, void *matrixIn);
extern void RtQuatConvertFromMatrix(void *input, void *data);
extern void mdlEffectSetMatrixPose(u8 *effect, u8 *matrix);
typedef struct { u8 c0; u8 c1; u8 c2; u8 c3; } MdlCol;
extern MdlCol iGpffffbb64;

extern void effMiscNormalizeVU(void);
extern void effMiscBuildRotationVU(void);
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
/* Native frame prefix: object and dirty-list link precede the aligned modelling matrix. */
struct RwFrame { u8 objectAndDirtyLink[0x10]; RwMatrix modelling; };
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
extern f32 sinf(f32 value);
static inline u8 *mdlEffect_camera_matrix(u8 *base)
{
    return base + 0x20;
}






extern void datEntryDrawGatedByFlag39(s32 port, s32 sequence, s32 duration, s32 flags);
extern void (*jtbl_008873EC[])(void *ptr);
extern void mdlEffectDestroyModel(s32 input);
extern void func_00182b40(void);
extern void FldNoiseEmitPlain();
/* measured: loop-invariant hoisting keeps the retail stride/base preheader for
   the 0x750 slot scan. */
#pragma opt_loop_invariants on
/* measured: close loop-invariant hoisting around the slot scan. */
#pragma opt_loop_invariants off
/* measured probe: opt_propagation off tests caching the repeated render callback base. */
#pragma opt_propagation off
/* measured probe: restore opt_propagation after func_00182b40. */
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma pop
#pragma opt_propagation off
/* measured: closing the single-function callback-base bracket. */
#pragma opt_propagation on
#pragma push
#pragma opt_lifetimes on
#pragma opt_loop_invariants on
#pragma pop
/* measured probe: O1 test for target byte-copy register allocation. */
#pragma optimization_level 1
/* measured probe: restore optimization level after target O1 test. */
#pragma optimization_level 2
/* measured: VU0 MMI builtins and O1 reproduce the target's pcpyld/sq packet. */
#pragma enable_vu0_registers on
/* measured: bind MMI packet registers as in retail. */
#pragma vu0_mmi_reg_binding on
/* measured: O1 preserves the target's packet construction order. */
#pragma optimization_level 1
/* measured: restore the file's O2 baseline after the target. */
#pragma optimization_level 2
/* measured: stop binding MMI packet registers after the target. */
#pragma vu0_mmi_reg_binding off
/* measured: stop VU0 register mode after the target. */
#pragma enable_vu0_registers off
/* measured: enable_vu0_registers + vu0_mmi_reg_binding with optimization_level 1
   reproduces the sibling 112-byte pcpyld/sq skeleton; direct _pcpyld on separate
   u64 pairs gives the retail register order and reload. */
#pragma enable_vu0_registers on
#pragma vu0_mmi_reg_binding on
/* measured: optimization_level 1 is required with the VU0 pragmas above;
   at -O2 the packet stores are reordered and the pcpyld pairs are folded. */
#pragma optimization_level 1
// FUN_00185370
void FldNoiseEmitPlain(void)
{
    u_long128 *packet;
    u_long128 packed;
    u64 a, b, c, d;

    func_003f3eb0((s32)0x80000000, 2);
    a = 0xE;
    b = 0x1000000000008001ULL;
    packed = _pcpyld(a, b);
    packet = (u_long128 *)(u32)iGpffffb884;
    *packet = packed;
    c = 0x4C;
    d = iGpffffb8c8;
    packed = _pcpyld(c, d);
    packet[1] = packed;
    iGpffffb884 += 0x20;
}

#pragma optimization_level 2

// Intent: release the UI handle stored at *input, then free its block. [inferred]
// FUN_00200720
void btlUiReleaseHandle(s32 *handleBlock) {
    s32 handle;

    handle = *handleBlock;
    if (handle != 0) {
        mdlEffectDestroyModel(handle);
    }
    jtbl_008873EC[0](handleBlock);
}


// Intent: set the window rectangle from the four 16-bit fields of the state block. [inferred]
// FUN_00200C70
void btlUiSetWindowRect(u8 *command)
{
    u8 *rectangle;

    rectangle = ((MdlEffectCommand *)command)->parameters;
    if (((MdlEffectCommand *)command)->counter == 0) {
        datEntryDrawGatedByFlag39(((MdlEffectWindowRect *)rectangle)->x,
                      ((MdlEffectWindowRect *)rectangle)->y,
                      ((MdlEffectWindowRect *)rectangle)->width,
                      ((MdlEffectWindowRect *)rectangle)->height);
    }
}


extern void fclFadeRectSetRenderStates(s32 unusedQueue, u8 *work);
extern u32 datEntryGetFlags(s16 itemId);
extern s32 fclFirstSetBitIndex(s32 flags);
extern void (*D_00887300[])(s32 input, s32 data);
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
/* Evaluates the entry flags through func_002be1e0. */
// FUN_002BE1B0
s32 datEntryEvaluateFlags(s16 item)
{
    return fclFirstSetBitIndex(datEntryGetFlags(item));
}


/* Allocates an empty effect list and clears its head. */
// FUN_0047D1A0
u32 mdlEffectListCreate(void)
{
    u32 list;

    chkmemAllocSiteTag(D_007131E8, 0x2D);
    list = (u32)(*jtbl_008873E8)(4, 0x40000);
    mdlEffectListClear((u32 *)list);
    return list;
}

/* Defined below in this file; called at line 61, above its definition. */
extern u32 *mdlEffectListAppendNode(u32 *list, u32 *sourceNode, u16 matrixIndex);

/* Creates a list and appends a reference to each source node. */
// FUN_0047D200
u32 *mdlEffectListCopy(u32 **source)
{
    u32 *list;
    u32 *cur;

    chkmemAllocSiteTag(D_007131E8, 0x2D);
    list = (u32 *)(*jtbl_008873E8)(4, 0x40000);
    mdlEffectListClear(list);
    cur = (u32 *)*source;
    if (cur == NULL) {
        return list;
    }
    while (cur[4] != 0) {
        cur = (u32 *)cur[4];
    }
    while (cur != NULL) {
        mdlEffectListAppendNode(list, cur, ((MdlEffectListNode *)cur)->matrixIndex);
        cur = (u32 *)cur[3];
    }
    return list;
}
/* Releases every node, then frees the list head. */
// FUN_0047D2D0
void mdlEffectListDestroy(u32 *list)
{
  mdlEffectListReleaseNodes(list);

  DAT_008873ec_abs[0](list);
}




/* Clears a list head to the empty state. */
// FUN_0047D310
void mdlEffectListClear(u32 *list)
{
    *list = 0;
}

/* Appends a node that owns a fresh copy of the given data block. */
// FUN_0047D320
u32 *mdlEffectListAppendBlock(u32 **list, s32 source, u32 size, u16 matrixIndex, u32 flags)
{
    u32 base;
    u32 head;
    u32 *data;
    u32 *node;

    chkmemAllocSiteTag(D_007131E8, 0x7F);
    data = (u32 *)(base = (u32)jtbl_008873E8,
                   ((void *(*)(u32, u32))*(u32 *)base)(size + 0x10, 0x40000));
    data[0] = (u32)((u8 *)data + 0x10);
    data[1] = 0;
    data[3] = flags;
    data[2] = 1;
    memcpy((void *)data[0], (const void *)source, size);
    chkmemAllocSiteTag(D_007131E8, 0x66);
    node = (u32 *)((void *(*)(u32, u32))*(u32 *)base)(0x14, 0x40000);
    memset(node, 0, 0x14);
    node[3] = 0;
    head = (u32)*list;
    if (head != 0) {
        ((u32 *)head)[3] = (u32)node;
        head = (u32)*list;
        node[4] = head;
    } else {
        node[4] = 0;
    }
    *list = node;
    node[0] = (u32)data;
    ((MdlEffectListNode *)node)->matrixIndex = matrixIndex;
    return node;
}

/* Appends a node that shares an existing data block and bumps its refcount. */
// FUN_0047D460
u32 *mdlEffectListAppendNode(u32 *list, u32 *sourceNode, u16 matrixIndex)
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
    node[0] = sourceNode[0];
    ((MdlEffectListNode *)node)->matrixIndex = matrixIndex;
    data = *(u32 **)sourceNode;
    data[2] = data[2] + 1;
    return node;
}

/* measured: nd 14 floor. ALL non-float code matches byte-for-byte, including
   the MtxRow {f32 x,y,z; s32 flag;} out[4] layout (holes at 0x5C/0x6C/0x7C),
   the 8x8-byte copy loop (t0/t1 temps, dst/count/src preheader), the identity
   branch, out[0].flag |= 0x20003, and the in[12..14] -> f2/f1/f0 temp loads. Residual
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
// Rebuilds each node's transform. Walks the node list at *input (next pointer +0x10, key +0x08, matrix index +0x04); a matrix copied from data by mdlCopyIndexedMatrix feeds a quaternion-derived 3x3 rotation, with the identity basis for indices of 1000 or more. The 4-row result goes to func_004b12e0 under the key, then func_004b1190 runs on the same key.
// FUN_0047D540
void mdlEffectListBuildTransforms(u8 **list, u8 *model)
{
    /* measured: The remaining +4 matrix-index and +8 handle loads intentionally stay byte-addressed: replacing each with MdlEffectListNode members changed the owning-file instruction bytes (measured individually). */
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

    node = *list;
    while (node != NULL) {
        if (((MdlEffectListNode *)node)->handle == 0) {
            break;
        }
        if (mdlCopyIndexedMatrix(model, ((MdlEffectListNode *)node)->matrixIndex, in) == 0) {
            u32 *src;
            u32 *dst;
            s32 count;
            u32 temp1;
            u32 temp2;
            dst = (u32 *)in;
            count = 8;
            src = (u32 *)model;
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
            mdlEffectSetMatrixPose((u8 *)*(u32 *)(node + 8), (u8 *)out);
            mdlEffectCommitAndAdvance(*(u8 **)(node + 8));
            node = (u8 *)((MdlEffectListNode *)node)->next;
    }
}
/* Calls func_004b11d0 with each node's payload and the first argument. */
// FUN_0047D7E0
void mdlEffectListInvokeEach(s32 context, u8 **list)
{
    s32 payload;
    u8 *node;

    node = *list;
    while (node != NULL) {
        payload = ((MdlEffectListNode *)node)->handle;
        if (payload != 0) {
            mdlEffectFlushWithTable(context, payload);
        }
        node = (u8 *)((MdlEffectListNode *)node)->next;
    }
}



/* Calls func_004b1170 on each node whose data block has flag bit 1 set. */
// FUN_0047D840
void mdlEffectListCallFlagged(u32 *list)
{
  int *node;

  for (node = (int *)*list; node != (int *)0x0; node = (int *)node[4]) {

    if ((node[2] != 0) && ((((MdlEffectListData *)*node)->flags & 1) != 0)) {

      mdlEffectStart(node[2]);
    }


  }

  return;

}



/* Applies a colour to each node's payload through mdlEffectSetPackedColor. */
// FUN_0047D8A0
void mdlEffectListSetColor(u8 **list, s32 *color)
{
    s32 payload;
    u8 *node;

    node = *list;
    while (node != NULL) {
        payload = ((MdlEffectListNode *)node)->handle;
        if (payload != 0) {
            mdlEffectSetPackedColor((void *)payload, color);
        }
        node = (u8 *)((MdlEffectListNode *)node)->next;
    }
}



/* Averages the three vector components and applies the result as a uniform scale via func_004b13d0. */
// FUN_0047D900
void mdlEffectListSetUniformScale(int *list,float *scale)
{
    int current;
    float average;

    average = (scale[0] + scale[1] + scale[2]) / 3.0f;
    for (current = *list; current != 0; current = ((MdlEffectListNode *)current)->next) {
        if (((MdlEffectListNode *)current)->handle != 0) {
            mdlEffectSetUniformScale(average,(u8 (*)[16])((MdlEffectListNode *)current)->handle);
        }
    }
}



/* Drops one reference per node, frees blocks whose count reaches zero, and clears the head. */
// FUN_0047D990
void mdlEffectListReleaseNodes(u32 *list)
{
    int *current;
    int *next;

    mdlEffectListReleaseHandles(list);
    current = (int*)*list;
    while (current != 0) {
        next = (int*)current[4];
        ((MdlEffectListData *)*current)->references = ((MdlEffectListData *)*current)->references - 1;
        if (((MdlEffectListData *)*current)->references == 0) {
            ((void (*)())DAT_008873ec_abs[0])(*current);
        }
        ((void (*)())DAT_008873ec_abs[0])(current);
        current = next;
    }
    *list = 0;
}




/* Releases each node's handle, then acquires a new handle from its payload. */
// FUN_0047DA30
void mdlEffectListRefreshHandles(u32 *list)
{
    int *current;
    u32 value;

    for (current = (int*)*list; current != 0; current = (int*)current[4]) {
        if (current[2] != 0) {
            if (current[2] == ((MdlEffectListData *)*current)->handle) {
                ((MdlEffectListData *)*current)->handle = 0;
            }
            mdlEffectDestroy(current[2]);
        }
        if (((u32*)*current)[1] == 0) {
            value = mdlEffectCreateFromResource(*(u32*)*current);
            current[2] = value;
            ((MdlEffectListData *)*current)->handle = value;
        } else {
            value = mdlEffectClone((u64*)((u32*)*current)[1]);
            current[2] = value;
        }
    }
}




/* Releases each node's handle and clears it, also clearing the payload's back-reference when it matches. */
// FUN_0047DAE0
void mdlEffectListReleaseHandles(u32 *list)
{
  int *node;

  for (node = (int *)*list; node != (int *)0x0; node = (int *)node[4]) {

    if (node[2] != 0) {

      if (node[2] == ((MdlEffectListData *)*node)->handle) {

        ((MdlEffectListData *)*node)->handle = 0;

      }

      mdlEffectDestroy(node[2]);

      node[2] = 0;

    }

  }

  return;

}




/* Copies data bytes from input into a new reference-counted block and returns a wrapper that points at it. */
// FUN_0047DB50
u32 *mdlEffectListWrapCopy(s32 source, s32 size)
{
    u32 *node;
    u32 *wrap;
    u32 base;

    chkmemAllocSiteTag(D_007131E8, 0x18A);
    node = (u32 *)(base = (u32)jtbl_008873E8,
                   ((void *(*)(u32, u32))*(u32 *)base)(size + 0x10, 0x40000));
    node[0] = (u32)((u8 *)node + 0x10);
    node[1] = 1;
    memcpy((void *)node[0], (void *)source, (u32)size);
    chkmemAllocSiteTag(D_007131E8, 0x17C);
    wrap = (u32 *)((void *(*)(u32, u32))*(u32 *)base)(8, 0x40000);
    memset(wrap, 0, 8);
    wrap[0] = (u32)node;
    return wrap;
}
/* Makes a new wrapper that shares the payload of *input and bumps its reference count. */
// FUN_0047DC30
u32 *mdlEffectListWrapShared(u32 **source)
{
    u32 *obj;
    u32 *wrapper;

    chkmemAllocSiteTag(D_007131E8, 0x17C);
    wrapper = (u32 *)(*jtbl_008873E8)(8, 0x40000);
    memset(wrapper, 0, 8);
    obj = *source;
    wrapper[0] = (u32)obj;
    obj[1] = obj[1] + 1;
    return wrapper;
}
extern u_long128 mdlEffectStoreQuadA(s32 instance, u32 *quadData);
extern u_long128 mdlEffectStoreQuadB(s32 instance, u32 *quadData);
void func_003e9cb0(void *frame, void *transform, u32 combine);
extern void mdlEffectReleaseTrackResource(u8 *resource);
extern void mdlEffectReleasePrimarySource(u8 *instance);
extern void mdlEffectReleaseSecondarySource(u8 *instance);
extern void mdlEffectAdvanceEmitter(void *object);
extern void ParticleUpdateScaled(u8 *particle, f32 scale);
void GeometryMatrixBuildCombined();
extern char D_00713CE0[];
static inline f32 MulF32(f32 left, f32 right) {
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
/* Releases the shared track resource, then frees its playback instance. */
// FUN_00481EE0
void mdlEffectReleaseTrackInstance(u8 **instance)
{
    mdlEffectReleaseTrackResource(*instance);
    jtbl_008873EC[0](instance);
}


// Calls func_004824a0 for the sub-object at +0x10 of the first argument and writes the result to the float array in the second.
// FUN_00482700
void mdlEffectEvalSubPose(int instance, float *output)
{
  mdlEffectAdvanceTrackQuad((int *)(u32)instance, (u8 *)(u32)((MdlEffectTrackInstance *)instance)->tracks, output);
}


/* Removing this loses 0x00482730 (MATCH nd0 -> MISMATCH nd45) - measured W161. */

// Sets each entry's frame to data modulo the entry's frame count (+0x0C of the entry's block) and marks it active (+0x08 = 1). The loop is built with opt_loop_invariants on, as measured.
// FUN_00482730
/* measured: opt_loop_invariants on is required for mdlEffectWrapTrackFrames (MATCH nd0). */
#pragma opt_loop_invariants on
void mdlEffectWrapTrackFrames(int instance, u32 frame)
{
  int trackCount;
  MdlEffectTrack *track;
  int trackIndex;

  trackCount = ((MdlEffectTrackInstance *)instance)->trackCount;
  for (trackIndex = 0; trackIndex < trackCount; trackIndex = trackIndex + 1) {
    track = ((MdlEffectTrackInstance *)instance)->tracks + trackIndex;
    track->frame = frame % ((MdlEffectTrackFrames *)track->resource)->frameCount;
    track->active = 1;
  }
  return;
}


/* measured: opt_loop_invariants off closes the mdlEffectWrapTrackFrames bracket. */
#pragma opt_loop_invariants off

#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma opt_propagation on
#pragma opt_loop_invariants off
// Builds a matrix with GeometryMatrixBuild and passes it, with the pointer at +0xC of input, to func_003e9cb0.
// FUN_00484350
void mdlEffectApplyGeometryMatrix(u8 *instance)
{
    RwMatrix matrix;

    GeometryMatrixBuild(&matrix);
    func_003e9cb0(((MdlEffectRenderModel *)instance)->frame, &matrix, 0);
}


// Same as mdlEffectApplyGeometryMatrix, but builds the matrix with GeometryMatrixBuildCombined.
// FUN_004843A0
void mdlEffectApplyCombinedGeometryMatrix(u8 *instance)
{
    RwMatrix matrix;

    GeometryMatrixBuildCombined(&matrix);
    func_003e9cb0(((MdlEffectRenderModel *)instance)->frame, &matrix, 0);
}


// Resolves the self-relative pointer at +0x10 of the source: returns it as-is when the flag at +0x18 is set; otherwise treats it as an offset and returns source+offset, or NULL for a zero offset.
// FUN_00484490
void *mdlEffectResolveRelPtrA(void *source)
{
  u8 *instance = source;
  u8 *value;

  if (((MdlEffectSource *)instance)->allocation.handle != 0) {
    value = ((MdlEffectSource *)instance)->parameters;
  } else {
    value = ((MdlEffectSource *)instance)->parameters;
    if (value != 0) {
      value = (u8 *)((u32)instance + (u32)value);
    } else {
      value = 0;
    }
  }
  return value;
}



// Resolves the self-relative pointer at +0x20 of the source: returns it as-is when the flag at +0x28 is set; otherwise treats it as an offset and returns source+offset, or NULL for a zero offset.
// FUN_004844D0
void *mdlEffectResolveRelPtrB(void *source)
{
  u8 *instance = source;
  u8 *value;

  if (((MdlEffectSource *)instance)->secondaryAllocation.handle != 0) {
    value = ((MdlEffectSource *)instance)->secondaryParameters;
  } else {
    value = ((MdlEffectSource *)instance)->secondaryParameters;
    if (value != 0) {
      value = (u8 *)((u32)instance + (u32)value);
    } else {
      value = 0;
    }
  }
  return value;
}



/* Frees the primary source allocation and clears its pointer, count and allocation word. */
// FUN_00484790
void mdlEffectReleasePrimarySource(u8 *instance)
{
    u8 *node;

    node = ((u8 **)instance)[6];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        ((MdlEffectSource *)instance)->parameters = 0;
        ((MdlEffectSource *)instance)->count = 0;
        ((MdlEffectSource *)instance)->allocation.pointer = NULL;
    }
}


/* Frees the secondary source allocation and clears its pointer, count and allocation word. */
// FUN_004847E0
void mdlEffectReleaseSecondarySource(u8 *instance)
{
    u8 *node;

    node = ((u8 **)instance)[10];
    if (node != NULL) {
        (*jtbl_008873EC)(node);
        ((MdlEffectSource *)instance)->secondaryParameters = 0;
        ((MdlEffectSource *)instance)->secondaryCount = 0;
        ((MdlEffectSource *)instance)->secondaryAllocation.pointer = NULL;
    }
}


/* Clears the state block and sets VU identity vectors, default scales and packed color fields. */
// FUN_00484B30
/* measured: MWCCPS2 b210 -O2, 120B/window 128B, three relocations,
 * eight zero alignment bytes. IDA retains the result that Ghidra drops:
 * retail leaves the copied quadword in v0 through return. Preserve that
 * live-out; the current C callers discard it. The four hardware vf0 stores
 * produce (0,0,0,1), not a zero quadword. */
#pragma push
#pragma opt_propagation off
u_long128 mdlEffectInitParticleState(u8 *instance)
{
    Code48InitialState *state = (Code48InitialState *)(void *)instance;
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


extern void mdlEffectCommitTreeFrame(u8 *effect);
extern void mdlEffectFlushTreeFrame(u8 *effect);
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
/* Runs the two child-effect processing passes on the supplied object. */
// FUN_00485AE0
void mdlEffectAdvanceAndDrawChildren(s32 instance)
{
    mdlEffectCommitTreeFrame((u8 *)instance);
    mdlEffectFlushTreeFrame((u8 *)instance);
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

  node = ((MdlEffectNode *)root)->children;
  while (node != NULL) {
    if (((MdlEffectNode *)node)->id == identifier) {
      return node;
    }
    node = ((MdlEffectNode *)node)->next;
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
// Releases the emitter at +0x4C and updates the particle with a unit scale.
// FUN_00489E00
void ParticleReleaseEmitterAndUpdate(u8 *instance)
{
    u8 *emitter;

    emitter = ((EffParticleInstance *)instance)->emitter.bytes;
    if (emitter != 0) {
        mdlEffectAdvanceEmitter(emitter);
        ParticleUpdateScaled(instance, 1.0f);
    }
}


// Calls func_00487fb0_evt with 1.0f; the callee is not yet named.
// FUN_00489E50
void mdlEffectSetUnitWeight(void)
{
  func_00487fb0_evt(1.0f);
}



#pragma opt_propagation off
#pragma opt_propagation on
    #pragma optimization_level 1
    #pragma optimization_level 2
#pragma optimization_level 1
#pragma optimization_level 2
// Releases the emitter at +0x4C, updates the particle, then projects its vertices.
// FUN_00489E80
void ParticleReleaseEmitterAndProject(u8 *instance)
{
    u8 *emitter;

    emitter = ((EffParticleInstance *)instance)->emitter.bytes;
    if (emitter != 0) {
        mdlEffectAdvanceEmitter(emitter);
        ParticleUpdateScaled(instance, 1.0f);
    }
    ParticleProjectVertices(instance, 1.0f);
}


// Stores the position quad into the particle's emitter at +0x4C.
// FUN_00489EE0
void ParticleSetEmitterPosition(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA(((EffParticleInstance *)instance)->emitter.handle, position);
}


// Stores the rotation quad into the particle's emitter at +0x4C.
// FUN_00489F10
void ParticleSetEmitterRotation(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB(((EffParticleInstance *)instance)->emitter.handle, rotation);
}


// Stores value at +0x08 of the record data, then calls EffEmitterApplyScale with the record emitter at +0x4C and the same scale.
// FUN_00489F50
void mdlEffectSetScaleAndNotify(f32 scale, int instance)
{
  ((EffParticleInstance *)instance)->scale.value = scale;
  EffEmitterApplyScale((u16 *)((EffParticleInstance *)instance)->emitter.bits, scale);
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
    ((u_long128 *)packet)[1] = packed;
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
    ((u_long128 *)packet)[1] = packed;
    iGpffffb884 = iGpffffb884 + 0x20;
}
// Appends a 0x20-byte packet pair to iGpffffb884: a tag quad, then a register quad with the data taken from the argument (tag 8).
// FUN_0048A070
void mdlEffectEmitValuePacket(u64 instance)
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
    packed = _pcpyld(c, instance);
    ((u_long128 *)packet)[1] = packed;
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
    ((u_long128 *)packet)[1] = packed;
    iGpffffb884 = iGpffffb884 + 0x20;
}
#pragma optimization_level 2
#pragma vu0_mmi_reg_binding off
#pragma enable_vu0_registers off
// Loads data into VU0, normalises it, builds the rotation basis, writes its three rows to input at +0x00, +0x10 and +0x20, and zeroes the words at +0x30 to +0x38.
// FUN_0048A150
void mdlEffectBuildBasisRows(u8 *output, u8 *orientation)
{
    f32 work[4];
    u8 *base;

    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(orientation)
        : "$vf10", "memory");
    effMiscNormalizeVU();
    effMiscBuildRotationVU();
    base = (u8 *)work;
    __asm__ volatile(
        "sqc2 $vf28, 0(%0) \n"
        :
        : "r"(base)
        : "$vf28", "memory");
    ((RwMatrix *)output)->right.x = work[0];
    ((RwMatrix *)output)->right.y = work[1];
    ((RwMatrix *)output)->right.z = work[2];
    __asm__ volatile(
        "sqc2 $vf29, 0(%0) \n"
        :
        : "r"(base)
        : "$vf29", "memory");
    ((RwMatrix *)output)->up.x = work[0];
    ((RwMatrix *)output)->up.y = work[1];
    ((RwMatrix *)output)->up.z = work[2];
    __asm__ volatile(
        "sqc2 $vf30, 0(%0) \n"
        :
        : "r"(base)
        : "$vf30", "memory");
    ((RwMatrix *)output)->at.x = work[0];
    ((RwMatrix *)output)->at.y = work[1];
    ((RwMatrix *)output)->at.z = work[2];
    ((MdlEffectFloatWord *)&((RwMatrix *)output)->pos)[0].bits = 0;
    ((MdlEffectFloatWord *)&((RwMatrix *)output)->pos)[1].bits = 0;
    ((MdlEffectFloatWord *)&((RwMatrix *)output)->pos)[2].bits = 0;
}
// Copies the three floats at +0x20 of the current camera object into the output and zeroes the word at +0x0C.
// FUN_0048A1F0
void mdlEffectCopyCameraOrigin(u8 *output)
{
    u8 *obj;

    obj = func_003e9700((s32)((MdlEffectCamera *)(u32)kwlnGetCamera())->frame);
    ((EffectVuVector *)output)->lane[0] = ((RwMatrix *)obj)->at.x;
    ((EffectVuVector *)output)->lane[1] = ((RwMatrix *)obj)->at.y;
    ((EffectVuVector *)output)->lane[2] = ((RwMatrix *)obj)->at.z;
    ((MdlEffectFloatWord *)output)[3].bits = 0;
}
// Copies the three floats at +0x30 of the current camera object into the output and zeroes the word at +0x0C.
// FUN_0048A250
void mdlEffectCopyCameraAim(u8 *output)
{
    u8 *obj;

    obj = func_003e9700((s32)((MdlEffectCamera *)(u32)kwlnGetCamera())->frame);
    ((EffectVuVector *)output)->lane[0] = ((RwMatrix *)obj)->pos.x;
    ((EffectVuVector *)output)->lane[1] = ((RwMatrix *)obj)->pos.y;
    ((EffectVuVector *)output)->lane[2] = ((RwMatrix *)obj)->pos.z;
    ((MdlEffectFloatWord *)output)[3].bits = 0;
}
// Writes the normalised vector from input to the camera point at +0x30 of the current camera object into data, using VU0.
// FUN_0048A2B0
void mdlEffectAimDirection(u8 *position, u8 *output)
{
    u8 *obj;
    f32 temp[4];

    obj = func_003e9700((s32)((MdlEffectCamera *)(u32)kwlnGetCamera())->frame);
    temp[0] = ((RwMatrix *)obj)->pos.x;
    temp[1] = ((RwMatrix *)obj)->pos.y;
    temp[2] = ((RwMatrix *)obj)->pos.z;
    temp[3] = 0.0f;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0)         \n"
        :
        : "r"(position)
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
        : "r"(temp), "r"(output)
        : "$vf10", "$vf11", "$vf2", "ACC", "Q", "memory");
}
// Builds an axis-angle rotation matrix from the angle and the axis in VU0 (vf10), loading its three rows into vf28 to vf30 through a 0x40-byte scratch block.
// FUN_0048A340
void mdlEffectAxisAngleBasisVU(f32 angle)
{
    f32 cosine;
    f32 savedAngle;
    f32 sine;
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

    savedAngle = angle;
    cosine = cosf();
    sine = sinf(savedAngle);
    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw)
        : "$vf10", "memory");

    x = ((MdlEffectFloatWord *)raw)[0].value;
    square = x * x;
    one = 1.0f;
    blend = one - square;
    blend = blend * cosine + square;
    ((MdlEffectFloatWord *)raw)[4].value = blend;
    y = ((MdlEffectFloatWord *)raw)[1].value;
    xy = x * y;
    factor = one - cosine;
    z = ((MdlEffectFloatWord *)raw)[2].value;
    zterm = z * sine;
    xyterm = xy * factor;
    blend = zterm + xyterm;
    ((MdlEffectFloatWord *)raw)[5].value = blend;
    xz = x * z;
    yterm = y * sine;
    xzterm = xz * factor;
    blend = xzterm - yterm;
    ((MdlEffectFloatWord *)raw)[6].value = blend;
    ((MdlEffectFloatWord *)raw)[7].bits = 0;
    blend = xyterm - zterm;
    ((MdlEffectFloatWord *)raw)[8].value = blend;
    square = y * y;
    blend = one - square;
    blend = blend * cosine + square;
    ((MdlEffectFloatWord *)raw)[9].value = blend;
    yzterm = y * z;
    xterm = x * sine;
    yzterm = yzterm * factor;
    blend = xterm + yzterm;
    ((MdlEffectFloatWord *)raw)[10].value = blend;
    ((MdlEffectFloatWord *)raw)[11].bits = 0;
    blend = yterm + xzterm;
    ((MdlEffectFloatWord *)raw)[12].value = blend;
    blend = yzterm - xterm;
    ((MdlEffectFloatWord *)raw)[13].value = blend;
    square = z * z;
    blend = one - square;
    blend = blend * cosine + square;
    ((MdlEffectFloatWord *)raw)[14].value = blend;
    ((MdlEffectFloatWord *)raw)[15].bits = 0;
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
                  (const RwMatrix *)mdlEffect_camera_matrix((u8 *)(u32)kwlnGetCamera()));
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
    f32 farPlane;
    f32 depthOrY;
    f32 nearPlane;
    f32 screenX;
    u8 *ptr;

    __asm__ volatile(
        "sqc2 $vf10, 0(%0) \n"
        :
        : "r"(&D_00713D10)
        : "$vf10", "memory");
    ((MdlEffectFloatWord *)raw)[8].value = D_00713D10[0];
    ((MdlEffectFloatWord *)raw)[9].value = D_00713D14[0];
    ((MdlEffectFloatWord *)raw)[10].value = D_00713D18[0];
    func_003e42a0((RwV3d *)(raw + 0x30), (const RwV3d *)(raw + 0x20),
                  (const RwMatrix *)mdlEffect_camera_matrix((u8 *)(u32)kwlnGetCamera()));
    ptr = (u8 *)(u32)kwlnGetCamera();
    nearPlane = ((MdlEffectCamera *)ptr)->nearPlane;
    ptr = (u8 *)(u32)kwlnGetCamera();
    farPlane = ((MdlEffectCamera *)ptr)->farPlane;
    depthOrY = ((MdlEffectFloatWord *)raw)[14].value;
    if ((depthOrY <= nearPlane) || !(depthOrY < farPlane)) {
        return 0;
    }
    screenX = 640.0f * (((MdlEffectFloatWord *)raw)[12].value / depthOrY);
    ((MdlEffectFloatWord *)raw)[6].value = screenX;
    depthOrY = 448.0f * (((MdlEffectFloatWord *)raw)[13].value / depthOrY);
    ((MdlEffectFloatWord *)raw)[7].value = depthOrY;
    if (!(screenX < 0.0f) && !(depthOrY < 0.0f) &&
        (screenX <= 640.0f) && (depthOrY <= 448.0f)) {
        ((MdlEffectFloatWord *)raw)[0].value = screenX;
        ((MdlEffectFloatWord *)raw)[1].value = depthOrY;
        ((MdlEffectFloatWord *)raw)[2].value = 0.0f;
        ((MdlEffectFloatWord *)raw)[3].value = 0.0f;
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
f32 mdlEffectAnchorScreenScale(f32 inputScale)
{
    /* measured: The scratch +0x44 Y load stays raw: typing this one lane changed the instruction bytes; the other scratch lanes and camera/frame fields are typed (measured individually). */
    u8 raw[0x50];
    f32 depth;
    f32 nearPlane;
    f32 savedScale;
    f32 scaledValue;
    f32 distanceOrRatio;
    u8 *ptr;

    savedScale = inputScale;
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
    ((MdlEffectFloatWord *)raw)[12].value = D_00713D10[0];
    ((MdlEffectFloatWord *)raw)[13].value = D_00713D14[0];
    ((MdlEffectFloatWord *)raw)[14].value = D_00713D18[0];
    func_003e42a0((RwV3d *)(raw + 0x40), (const RwV3d *)(raw + 0x30),
                  (const RwMatrix *)mdlEffect_camera_matrix((u8 *)(u32)kwlnGetCamera()));
    depth = ((MdlEffectFloatWord *)raw)[18].value;
    distanceOrRatio = ((MdlEffectFloatWord *)raw)[16].value / depth;
    scaledValue = 640.0f * distanceOrRatio;
    ((MdlEffectFloatWord *)raw)[0].value = scaledValue;
    distanceOrRatio = *(f32 *)(raw + 0x44) / depth;
    scaledValue = 448.0f * distanceOrRatio;
    ((MdlEffectFloatWord *)raw)[1].value = scaledValue;
    ((MdlEffectFloatWord *)raw)[2].bits = 0;
    ((MdlEffectFloatWord *)raw)[3].bits = 0;
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
    ptr = (u8 *)(u32)kwlnGetCamera();
    nearPlane = ((MdlEffectCamera *)ptr)->nearPlane;
    ptr = (u8 *)(u32)kwlnGetCamera();
    scaledValue = ((MdlEffectCamera *)ptr)->farPlane;
    if ((depth <= nearPlane) || !(depth < scaledValue)) {
        return 0.0f;
    }
    ptr = (u8 *)(u32)kwlnGetCamera();
    ptr = ((MdlEffectCamera *)ptr)->frame;
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw + 0x10)
        : "$vf10", "memory");
    *(f32 *)&D_00713D10[0] = ((RwFrame *)ptr)->modelling.pos.x;
    *(f32 *)&D_00713D14[0] = ((RwFrame *)ptr)->modelling.pos.y;
    *(f32 *)&D_00713D18[0] = ((RwFrame *)ptr)->modelling.pos.z;
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
        : "=f"(distanceOrRatio)
        : "r"(&D_00713D10)
        : "$vf10", "$vf11", "$vf2", "$2", "Q", "memory");
    __asm__ volatile(
        "lqc2 $vf10, 0(%0) \n"
        :
        : "r"(raw + 0x20)
        : "$vf10", "memory");
    scaledValue = (650.0f * savedScale) / distanceOrRatio;
    distanceOrRatio = 1500.0f;
    if (!(scaledValue <= distanceOrRatio)) {
        scaledValue = distanceOrRatio;
    }
    return scaledValue;
}
// Catmull-Rom point builder: forms two tangent vectors from four consecutive points in VU0, then blends them at t into the output at data.
// FUN_0048A810
void mdlEffectCatmullRomVU(float progress, u8 (*points)[16])
{
  float work[7][4];
  float square;
  float cube;
  float coefficient;

  square = progress * progress;
  cube = square * progress;

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

  coefficient = progress + (cube - square * 2.0f);
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
/* Scale applier for emitter kind 1 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. */
// FUN_0048C440
void EffWaveApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkCC = ((MdlEffectScaleParameters *)sourceParameters)->unkCC * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD4 = ((MdlEffectScaleParameters *)sourceParameters)->unkD4 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD8 = ((MdlEffectScaleParameters *)sourceParameters)->unkD8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE0 = ((MdlEffectScaleParameters *)sourceParameters)->unkE0 * scale;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
/* Scale applier for emitter kind 2 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. */
// FUN_0048CD60
void EffMotionApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD0 = ((MdlEffectScaleParameters *)sourceParameters)->unkD0 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD8 = ((MdlEffectScaleParameters *)sourceParameters)->unkD8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkDC = ((MdlEffectScaleParameters *)sourceParameters)->unkDC * scale;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
/* Scale applier for emitter kind 3 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. Each stored float is multiplied by fparg0 through MulF32. */
// FUN_0048D820
void EffEmitterKind3ApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkCC = ((MdlEffectScaleParameters *)sourceParameters)->unkCC * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD4 = ((MdlEffectScaleParameters *)sourceParameters)->unkD4 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE4 = ((MdlEffectScaleParameters *)sourceParameters)->unkE4 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkF0 = ((MdlEffectScaleParameters *)sourceParameters)->unkF0 * scale;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
/* Scale applier for emitter kind 4 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. Each stored float is multiplied by fparg0 through MulF32. */
// FUN_0048E270
void EffEmitterKind4ApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD0 = ((MdlEffectScaleParameters *)sourceParameters)->unkD0 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE4 = ((MdlEffectScaleParameters *)sourceParameters)->unkE4 * scale;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
/* Scale applier for emitter kind 5 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. */
// FUN_0048EBC0
void EffConeApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD8 = ((MdlEffectScaleParameters *)sourceParameters)->unkD8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE0 = ((MdlEffectScaleParameters *)sourceParameters)->unkE0 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE4 = ((MdlEffectScaleParameters *)sourceParameters)->unkE4 * scale;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
/* Scale applier for emitter kind 6 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. */
// FUN_0048F560
void EffConeAngleApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD8 = ((MdlEffectScaleParameters *)sourceParameters)->unkD8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE0 = ((MdlEffectScaleParameters *)sourceParameters)->unkE0 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE4 = ((MdlEffectScaleParameters *)sourceParameters)->unkE4 * scale;
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
extern void mdlEffectAppendGeometryPrimitive(u8 *source, s32 texture);
/* Scale applier for emitter kind 7 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. */
// FUN_00490360
void EffBezierApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
/* Scale applier for emitter kind 8 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. Each stored float is multiplied by fparg0 through MulF32. */
// FUN_00490BB0
void EffEmitterKind8ApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkDC = ((MdlEffectScaleParameters *)sourceParameters)->unkDC * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE4 = ((MdlEffectScaleParameters *)sourceParameters)->unkE4 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE8 = ((MdlEffectScaleParameters *)sourceParameters)->unkE8 * scale;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
#pragma opt_propagation off
#pragma pop
/* Scale applier for emitter kind 9 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. Each stored float is multiplied by fparg0 through MulF32. */
// FUN_00491660
void EffEmitterKind9ApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD0 = ((MdlEffectScaleParameters *)sourceParameters)->unkD0 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkDC = ((MdlEffectScaleParameters *)sourceParameters)->unkDC * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE4 = ((MdlEffectScaleParameters *)sourceParameters)->unkE4 * scale;
}


#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
#pragma pop
/* Scale applier for emitter kind 10 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. Each stored float is multiplied by fparg0 through MulF32. */
// FUN_00492080
void EffEmitterKind10ApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkCC = ((MdlEffectScaleParameters *)sourceParameters)->unkCC * scale;
    ((MdlEffectScaleParameters *)parameters)->unkDC = ((MdlEffectScaleParameters *)sourceParameters)->unkDC * scale;
}


#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
#pragma pop
/* Scale applier for emitter kind 11 (word 1 of the D_00713D54 record). Writes the scaled fields of the record at +0x24 into the record at +0x20. */
// FUN_00492A80
void EffSwayParticleApplyScale(u8 *emitter, f32 scale) {
    u32 componentIndex;
    u8 *sourceParameters;
    u8 *parameters;

    parameters = ((EffTrackPath *)emitter)->parameters;
    sourceParameters = ((EffTrackPath *)emitter)->originalParameters;
    ((MdlEffectScaleParameters *)parameters)->unk64 = ((MdlEffectScaleParameters *)sourceParameters)->unk64 * scale;
    ((MdlEffectScaleParameters *)parameters)->unk68 = ((MdlEffectScaleParameters *)sourceParameters)->unk68 * scale;
    componentIndex = 0;
    while (componentIndex < 3U) {
        ((MdlEffectScaleParameters *)parameters)->components[componentIndex].value =
            MulF32(((MdlEffectScaleParameters *)sourceParameters)->components[componentIndex].value, scale);
        componentIndex += 1;
    }
    ((MdlEffectScaleParameters *)parameters)->unkC8 = ((MdlEffectScaleParameters *)sourceParameters)->unkC8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkCC = ((MdlEffectScaleParameters *)sourceParameters)->unkCC * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD4 = ((MdlEffectScaleParameters *)sourceParameters)->unkD4 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkD8 = ((MdlEffectScaleParameters *)sourceParameters)->unkD8 * scale;
    ((MdlEffectScaleParameters *)parameters)->unkE0 = ((MdlEffectScaleParameters *)sourceParameters)->unkE0 * scale;
}


/* Frees the emitter allocation stored at +0x28. */
// FUN_00492CD0
void mdlEffectFreeEmitterAllocation(u8 *instance)
{
    jtbl_008873EC[0](((EffTrackPath *)instance)->allocation);
}


/* Resets the emitter tick counter to zero. */
// FUN_00492D00
void mdlEffectResetEmitterTicks(u8 *instance)
{
    ((EffTrackPath *)instance)->ticks.signedValue = 0;
}


/* measured: probing opt_loop_invariants for the preheader -1 and loop branch. */
#pragma opt_loop_invariants on
/* On the first tick, marks samples inactive; dispatches the kind update and advances the tick counter. */
// FUN_00492D10
void mdlEffectAdvanceEmitter(void *object) {
    /* measured: The final +0x10 tick read/write stays raw: the typed increment changed instruction bytes, while the earlier tick test and all sample fields remained MATCH (measured). */
    u8 *emitter = object;
    extern void (*D_00713D50[])(u8 *emitter);
    u32 count;
    u32 sampleIndex;
    u8 *sample;

    if (((EffTrackPath *)emitter)->ticks.signedValue == 0) {
        count = ((EffTrackPath *)emitter)->totalCount;
        sample = ((EffTrackPath *)emitter)->samples;
        sampleIndex = 0;
        while (sampleIndex < count) {
            ((EffTrackSample *)sample)->mode = -1;
            sample += 0x20;
            sampleIndex += 1;
        }
    }
    D_00713D50[*(u16 *)emitter * 4](emitter);
    *(s32 *)(emitter + 0x10) = *(s32 *)(emitter + 0x10) + 1;
}


// Loads the 128-bit quad at +0x20 of the object at value into *data and returns it.
// FUN_00492DB0
u_long128 mdlEffectLoadQuadA(int instance, u32 *quadData)
{
  u_long128 value = ((u_long128 *)((EffTrackPath *)instance)->parameters)[0];
  *(u_long128 *)quadData = value;
  return value;
}


/* measured: opt_propagation off preserves mdlEffectStoreQuadA's 128-bit load/store ordering (MATCH nd0). */
#pragma opt_propagation off

// Stores the 128-bit quad at *data into +0x20 of the object at value and returns it.
// FUN_00492DD0
u_long128 mdlEffectStoreQuadA(int instance, u32 *quadData)
{
  u_long128 *dst;
  u_long128 value;

  dst = (u_long128 *)((EffTrackPath *)instance)->parameters;
  value = *(u_long128 *)quadData;
  *dst = value;
  return value;
}

/* measured: opt_propagation on closes the mdlEffectStoreQuadA bracket. */
#pragma opt_propagation on


// Loads the 128-bit quad at +0x30 of the object at value into *data and returns it.
// FUN_00492DF0
u_long128 mdlEffectLoadQuadB(int instance, u32 *quadData)
{
  return *(u_long128 *)quadData =
      ((u_long128 *)((EffTrackPath *)instance)->parameters)[1];
}


/* measured: opt_propagation off preserves mdlEffectStoreQuadB's 128-bit load/store ordering (MATCH nd0). */
#pragma opt_propagation off

// Stores the 128-bit quad at *data into +0x30 of the object at value and returns it.
// FUN_00492E10
u_long128 mdlEffectStoreQuadB(int instance, u32 *quadData)
{
  u_long128 *dst;
  u_long128 value;

  dst = (u_long128 *)((EffTrackPath *)instance)->parameters + 1;
  value = *(u_long128 *)quadData;
  *dst = value;
  return value;
}
/* measured: opt_propagation on closes the mdlEffectStoreQuadB bracket. */
#pragma opt_propagation on



/* measured: closes opt_loop_invariants at its prior file baseline. */
#pragma opt_loop_invariants off
/* Applies a scale to an emitter record: dispatches on the emitter kind (u16 at +0) through the scale table D_00713D54. */
// FUN_00492E30
void EffEmitterApplyScale(u16 *emitter, f32 scale) {
    D_00713D54[*emitter * 4]((u8 *)emitter, scale);
}


extern void mdlEffectDestroyMultipartGeometry(u8 *source);
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma opt_common_subs off
#pragma opt_common_subs on
#pragma opt_propagation on
#pragma push
#pragma opt_loop_invariants on
#pragma opt_pulloutconstants off
#pragma pop
/* Releases both owned geometry blocks and frees the containing object. */
// FUN_00494680
void mdlEffectDestroyGeometryPair(void *instance)
{
    mdlEffectDestroyMultipartGeometry(((MdlEffectSlotTable *)instance)->firstGeometry);
    mdlEffectDestroyMultipartGeometry(((MdlEffectSlotTable *)instance)->secondGeometry);
    jtbl_008873EC[0](instance);
}


/* Stores 0 in the slot-table entry for data (table at +0x18); -1 is the free state. */
// FUN_004946D0
void mdlEffectSlotSetZero(u8 *instance, u16 slotIndex)
{
  u32 index;
  s16 *base;

  index = slotIndex & 0xffff;
  base = ((MdlEffectSlotTable *)instance)->slots;
  base[index] = 0;

  return;
}



/* Stores -1 (the free state) in the slot-table entry for data. */
// FUN_004946F0
void mdlEffectSlotRelease(u8 *instance, u16 slotIndex)
{
  s16 value;
  u32 index;
  s16 *base;

  value = -1;
  index = slotIndex & 0xffff;
  base = ((MdlEffectSlotTable *)instance)->slots;
  base[index] = value;

  return;

}



/* Returns 1 when the slot-table entry for data holds -1 (free). */
// FUN_00494710
s32 mdlEffectSlotIsFree(u8 *instance, u16 slotIndex)
{
  u32 index;
  s16 *base;
  s16 value;

  index = slotIndex & 0xffff;
  base = ((MdlEffectSlotTable *)instance)->slots;
  value = base[index];

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
// Copies the camera origin, then locks the geometry under the sub-objects at +0x10 and +0x14.
// FUN_00494F90
void mdlEffectCopyOriginAndLockGeometry(u8 *instance) {
    mdlEffectCopyCameraOrigin(instance);
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)((MdlEffectSlotTable *)instance)->firstGeometry)->atomic)->geometry, 0xA);
    RpGeometryLock(((RpAtomic *)((EffGeometryBlock *)((MdlEffectSlotTable *)instance)->secondGeometry)->atomic)->geometry, 0xA);
}


/* Unlocks the two geometries and marks their lock word when the owning block has flag 4. */
// FUN_00494FF0
void mdlEffectUnlockGeometryPair(u8 *instance) {
    extern void func_003c22f0(void *);
    u8 *firstGeometry;
    u8 *secondGeometry;
    u8 *firstBlock;
    u8 *secondBlock;

    secondBlock = ((MdlEffectSlotTable *)instance)->secondGeometry;
    secondGeometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)secondBlock)->atomic)->geometry;
    func_003c22f0(secondGeometry);
    if (*(u16 *)secondBlock & 4) {
        ((RpGeometry *)secondGeometry)->lockedSinceLastInst = ((RpGeometry *)secondGeometry)->lockedSinceLastInst | 1;
    }
    firstBlock = ((MdlEffectSlotTable *)instance)->firstGeometry;
    firstGeometry = (u8 *)((RpAtomic *)((EffGeometryBlock *)firstBlock)->atomic)->geometry;
    func_003c22f0(firstGeometry);
    if (*(u16 *)firstBlock & 4) {
        ((RpGeometry *)firstGeometry)->lockedSinceLastInst = ((RpGeometry *)firstGeometry)->lockedSinceLastInst | 1;
    }
}


/* Passes the supplied resource value to both geometry blocks. */
// FUN_00495090
void mdlEffectSetGeometryPairResource(u8 *instance, u32 value)
{
    mdlEffectAppendGeometryPrimitive(((MdlEffectSlotTable *)instance)->firstGeometry, (s32)value);
    mdlEffectAppendGeometryPrimitive(((MdlEffectSlotTable *)instance)->secondGeometry, (s32)value);
}


/* Initializes each 0x10-byte entry age to a random value from -1 through -4. */
// FUN_004950E0
void mdlEffectRandomizeEntryDelays(u8 *instance) {
    u32 entryCount;
    u8 *entry;
    u32 entryIndex;

    entry = *((MdlEffectSlotTable *)instance)->entries;
    entryCount = ((MdlEffectDelayParameters *)((MdlEffectSlotTable *)instance)->parameters)->entryCount;
    entryIndex = 0;
    while (entryIndex < entryCount) {
        ((MdlEffectDelayedEntry *)entry)->age = -1 - (effMiscRand(0) & 3);
        entryIndex += 1;
        entry += 0x10;
    }
}


/* Calls kind slot +0x08 with the object itself, then frees it through the allocator free table; the kind index is at +0x2C. */
// FUN_00498AC0
void ThunderInstanceDestroy(u8 *instance) {
    D_00713E78[((EffThunderInstance *)instance)->kind * 6](instance);
    jtbl_008873EC[0](instance);
}


// Thunder texture for a record: kind at +0x2C and the texture table at +0x34. Unlike ThunderTextureForObject, no relative pointer is resolved.
// FUN_00498B20
void *ThunderTextureForRecord(void *source) {
    u8 *instance = source;

    return ThunderTextureForIndex(((EffThunderInstance *)instance)->kind, ((EffThunderInstance *)instance)->parameters.bytes);
}


/* Calls kind slot +0x00 with the object, then clears the counter at +0x28. */
// FUN_00498B50
void ThunderInstanceStop(u8 *instance) {
    D_00713E70[((EffThunderInstance *)instance)->kind * 6](instance);
    ((EffThunderInstance *)instance)->age.signedValue = 0;
}


/* Calls kind slot +0x0C with the object, then increments the counter at +0x28. */
// FUN_00498BA0
void ThunderInstanceAdvance(u8 *instance) {
    D_00713E7C[((EffThunderInstance *)instance)->kind * 6](instance);
    ((EffThunderInstance *)instance)->age.signedValue = ((EffThunderInstance *)instance)->age.signedValue + 1;
}


/* Calls kind slot +0x10 with the object when the counter at +0x28 is positive. */
// FUN_00498C00
void ThunderInstanceUpdateIfActive(u8 *instance) {
    if (((EffThunderInstance *)instance)->age.signedValue > 0) {
        D_00713E80[((EffThunderInstance *)instance)->kind * 6](instance);
    }
}


/* Copies the 16-byte quad at data to the object base and returns it. */
// FUN_00498CE0
u_long128 ThunderSetFirstQuad(u_long128 *destination, u_long128 *source) {
    return *destination = *source;
}


/* Copies the 16-byte quad at data to +0x10 of the object and returns it. */
// FUN_00498CF0
u_long128 ThunderSetSecondQuad(u_long128 *destination, u_long128 *source) {
    return destination[1] = *source;
}




// Stores the packed colour word at +0x24. Called through the kind 15 (thunder) +0x30 slot with the packed colour.
// FUN_00498D00
void ThunderSetPackedColor(u8 *instance, s32 packedColor) {
    ((EffThunderInstance *)instance)->packedColor.signedValue = packedColor;
}


// Stores the float at +0x20. Called through the kind 15 (thunder) +0x28 slot.
// FUN_00498D10
void ThunderSetScale(u8 *instance, f32 scale) {
    ((EffThunderInstance *)instance)->scale.value = scale;
}


#pragma push
#pragma opt_loop_invariants on
#pragma pop
/* Sets the child material color, temporarily replacing alpha 255 with 254. */
// FUN_00498D20
void mdlEffectSetThunderMaterialColor(u8 *instance) {
    u8 *geometryBlock;
    u8 *material;
    u8 *opaqueMaterial;

    geometryBlock = *((MdlEffectMaterialOwner *)instance)->geometry;
    if (iGpffffbb64.c3 != 0xFF) {
        material = ((EffGeometryBlock *)geometryBlock)->material;
        *(MdlCol *)&((RpMaterial *)material)->color = iGpffffbb64;
        return;
    }
    iGpffffbb64.c3 = 0xFE;
    opaqueMaterial = ((EffGeometryBlock *)geometryBlock)->material;
    *(MdlCol *)&((RpMaterial *)opaqueMaterial)->color = iGpffffbb64;
    iGpffffbb64.c3 = 0xFF;
}


/* Calls kind slot +0x08 on the child at +0x3C, then frees the object; the kind index is at +0x38. */
// FUN_0049A570
void RingInstanceDestroy(u8 *instance) {
    D_00713F18[((MdlEffectVectorInstance *)instance)->kind.value * 6](((MdlEffectVectorInstance *)instance)->child);
    jtbl_008873EC[0](instance);
}


// Ring instance for a record: kind at +0x38 and parameters at +0x40. Unlike RingCreateKindInstanceFromObject, no relative pointer is resolved.
// FUN_0049A5E0
void *RingCreateInstanceForRecord(void *source) {
    u8 *instance = source;

    return RingCreateKindInstance(((MdlEffectVectorInstance *)instance)->kind.low, ((MdlEffectVectorInstance *)instance)->parameters);
}


/* Calls kind slot +0x00 with the object, then clears the counter at +0x34. */
// FUN_0049A610
void RingInstanceStop(u8 *instance) {
    D_00713F10[((MdlEffectVectorInstance *)instance)->kind.value * 6](instance);
    ((MdlEffectVectorInstance *)instance)->age = 0;
}


/* Calls kind slot +0x0C with the object, then increments the counter at +0x34. */
// FUN_0049A660
void RingInstanceAdvance(u8 *instance) {
    D_00713F1C[((MdlEffectVectorInstance *)instance)->kind.value * 6](instance);
    ((MdlEffectVectorInstance *)instance)->age = ((MdlEffectVectorInstance *)instance)->age + 1;
}


/* Calls kind slot +0x10 with the object when the counter at +0x34 is positive. */
// FUN_0049A6C0
void RingInstanceUpdateIfActive(u8 *instance) {
    if (((MdlEffectVectorInstance *)instance)->age > 0) {
        D_00713F20[((MdlEffectVectorInstance *)instance)->kind.value * 6](instance);
    }
}


/* Copies the 16-byte quad at data to the object base and returns it. */
// FUN_0049A7A0
u_long128 RingSetFirstQuad(u_long128 *destination, u_long128 *source) {
    return *destination = *source;
}


/* Copies the 16-byte quad at data to +0x10 of the object and returns it. */
// FUN_0049A7B0
u_long128 RingSetSecondQuad(u_long128 *destination, u_long128 *source) {
    return destination[1] = *source;
}


// Stores the packed colour word at +0x30. Called through the kind 14 (ring) +0x30 slot with the packed colour.
// FUN_0049A7C0
void RingSetPackedColor(u8 *instance, s32 packedColor) {
    ((MdlEffectVectorInstance *)instance)->packedColor = packedColor;
}


/* Writes the same float to +0x20, +0x24 and +0x28, giving a uniform scale. */
// FUN_0049A7D0
void RingSetUniformScale(u8 *instance, f32 scale) {
    ((MdlEffectVectorInstance *)instance)->scale[0] = scale;
    ((MdlEffectVectorInstance *)instance)->scale[1] = scale;
    ((MdlEffectVectorInstance *)instance)->scale[2] = scale;
}


/* Copies the three floats of data into +0x20, +0x24 and +0x28. */
// FUN_0049A7F0
void RingSetVec3(u8 *instance, f32 *scale) {
    ((MdlEffectVectorInstance *)instance)->scale[0] = scale[0];
    ((MdlEffectVectorInstance *)instance)->scale[1] = scale[1];
    ((MdlEffectVectorInstance *)instance)->scale[2] = scale[2];
}


extern void mdlEffectCopyReferences(u8 *destination, u8 *source);
extern void mdlEffectDrawModelChildren(u8 *instance);
extern void EffSpriteUpdate(u8 *instance);
extern u8 *mdlEffectCreateGridForRecord(u8 *parameters);
extern u8 *WindAllocKindEntry(u16 kind, u8 *parameters);
extern u8 D_0071413C[];
extern void func_004adb50();
extern void mdlEffectDrawModelChildren(u8 *instance);
extern f32 iGpffff8080;
extern void (*D_008873ec[])(void *);
extern s32 D_00724C70;
extern s8 D_00724C58;
extern f32 D_00922D80[];
extern u8 *RpSkyGetDisplayBufferRaster(void);
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
extern void mdlEffectApplyShakeEnvelope(u8 *record, s32 elapsed);
extern void mdlSetLayerTime(u8 *model, s32 layer, f32 frameValue);
extern f32 fGpffff80f4;
extern void mdlEffectCopyReferences(u8 *destination, u8 *source);
extern u8 *GeometryCloneBlock(s32 source);
extern void mdlSetResetCallback(void *input, void (*data)(void), void *options);
extern void mdlEffectStartChildren(s32 effect);
extern void *mdlEffectCreateInstance(void *source);


/* Calls kind destroy slot +0x08 on the child at +0x3C, then frees input through the allocator free table. */
// FUN_004A18E0
void FlashQuadDestroy(u8 *instance) {
    (*(void (**)(u8 *))(D_00714018 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))(((MdlEffectVectorInstance *)instance)->child);
    jtbl_008873EC[0](instance);
}


/* Calls kind slot +0x00 with no argument, then clears the counter at +0x34. */
// FUN_004A1AA0
void FlashQuadStop(u8 *instance) {
    (*(void (**)(void))(D_00714010 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    ((MdlEffectVectorInstance *)instance)->age = 0;
}


/* Calls kind slot +0x10 with no argument, then increments the counter at +0x34. */
// FUN_004A1AF0
void FlashQuadAdvance(u8 *instance) {
    (*(void (**)(void))(D_00714020 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    (((MdlEffectVectorInstance *)instance)->age)++;
}


/* Calls kind slot +0x14 with no argument when the counter at +0x34 is positive. */
// FUN_004A1B50
void FlashQuadUpdateIfActive(u8 *instance) {
    if (((MdlEffectVectorInstance *)instance)->age > 0) {
        (*(void (**)(void))(D_00714024 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    }
}


/* Calls kind slot +0x10, increments the counter at +0x34, then calls kind slot +0x14 with input when the counter is positive. */
// FUN_004A1BA0
void FlashQuadAdvanceAndUpdate(u8 *instance) {
    /* measured: The second kind load at +0x38 stays raw: its typed form changes instruction bytes after the callback; the first dispatch and age accesses are typed (measured individually). */
    (*(void (**)(void))(D_00714020 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    (((MdlEffectVectorInstance *)instance)->age)++;
    if (((MdlEffectVectorInstance *)instance)->age > 0) {
        (*(void (**)(u8 *))(D_00714024 + (*(s32 *)(instance + 0x38) * 0x1C)))(instance);
    }
}


/* Copies the 16-byte quad at data to +0x00 and returns it. */
// FUN_004A1C30
u_long128 FlashQuadSetFirstQuad(u8 *destination, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    *(u_long128 *)destination = value;
    return value;
}


/* Copies the 16-byte quad at data to +0x10 and returns it. */
// FUN_004A1C40
u_long128 FlashQuadSetSecondQuad(u8 *destination, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    ((u_long128 *)destination)[1] = value;
    return value;
}


/* Stores the flash-quad packed color at +0x30. */
// FUN_004A1C50
void mdlEffectSetFlashQuadColor(u8 *instance, s32 value) {
    ((MdlEffectVectorInstance *)instance)->packedColor = value;
}


/* Writes the same float to +0x20, +0x24 and +0x28, giving a uniform scale. */
// FUN_004A1C60
void FlashQuadSetUniformScale(u8 *destination, f32 source) {
    ((MdlEffectVectorInstance *)destination)->scale[0] = source;
    ((MdlEffectVectorInstance *)destination)->scale[1] = source;
    ((MdlEffectVectorInstance *)destination)->scale[2] = source;
}


/* Copies the three floats of data into +0x20, +0x24 and +0x28. */
// FUN_004A1C80
void FlashQuadSetVec3(u8 *destination, f32 *source) {
    ((MdlEffectVectorInstance *)destination)->scale[0] = source[0];
    ((MdlEffectVectorInstance *)destination)->scale[1] = source[1];
    ((MdlEffectVectorInstance *)destination)->scale[2] = source[2];
}


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
/* measured: restores the file's O2 loop-invariant baseline. */
#pragma opt_loop_invariants off
/* Calls kind slot +0x08 with the object, then frees it through the allocator free table. The kind index is at +0x38. */
// FUN_004A58B0
void WindInstanceDestroy(u8 *instance)
{
    (*(void (**)(u8 *))(D_00714138 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))(instance);
    jtbl_008873EC[0](instance);
}


/* Same role as WindCreateKindEntry (effPolygonWind.c): allocates a kind entry through WindAllocKindEntry. This copy reads the kind index from +0x38 directly, with no kind switch, stores the result of table D_0071413C at +0x3C of the new entry, then calls table D_00714130 on it. */
// FUN_004A5910
void *WindCreateKindEntryAlt(void *source)
{
    /* measured: The two callback kind loads at +0x38 stay raw: typing either changed instruction bytes; the initial kind/parameter reads and child write are typed (measured individually). */
    u8 *descriptor = (u8 *)source;
    u8 *instance;

    instance = WindAllocKindEntry(((MdlEffectVectorInstance *)descriptor)->kind.low, ((MdlEffectVectorInstance *)descriptor)->parameters);
    ((MdlEffectVectorInstance *)instance)->child = (u8 *)
        (*(s32 (**)(u8 *))(D_0071413C + (*(s32 *)(descriptor + 0x38) * 0x1C)))(descriptor);
    (*(void (**)(u8 *))(D_00714130 + (*(s32 *)(descriptor + 0x38) * 0x1C)))(instance);
    return instance;
}


/* Calls kind slot +0x00 with no argument, then clears the counter at +0x34. The kind index is at +0x38. */
// FUN_004A59B0
void WindInstanceStop(u8 *instance)
{
    (*(void (**)(void))(D_00714130 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    ((MdlEffectVectorInstance *)instance)->age = 0;
}


/* Calls kind slot +0x10 with no argument, then increments the counter at +0x34. */
// FUN_004A5A00
void WindInstanceAdvance(u8 *instance)
{
    (*(void (**)(void))(D_00714140 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    ((MdlEffectVectorInstance *)instance)->age = ((MdlEffectVectorInstance *)instance)->age + 1;
}


/* Calls kind slot +0x14 with no argument when the counter at +0x34 is positive. */
// FUN_004A5A60
void WindInstanceUpdateIfActive(u8 *instance)
{
    if (((MdlEffectVectorInstance *)instance)->age > 0) {
        (*(void (**)(void))(D_00714144 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    }
}


/* Calls kind slot +0x10 with no argument, increments the counter at +0x34, then calls kind slot +0x14 with the object when the counter is positive. The kind index is at +0x38. */
// FUN_004A5AB0
void WindInstanceAdvanceAndUpdate(u8 *instance)
{
    /* measured: The final kind load at +0x38 stays raw: typing it changed instruction bytes; the first dispatch and age accesses are typed (measured individually). */
    s32 age;

    (*(void (**)(void))(D_00714140 + (((MdlEffectVectorInstance *)instance)->kind.value * 0x1C)))();
    age = ((MdlEffectVectorInstance *)instance)->age + 1;
    ((MdlEffectVectorInstance *)instance)->age = age;
    if (age > 0) {
        (*(void (**)(u8 *))(D_00714144 + (*(s32 *)(instance + 0x38) * 0x1C)))(instance);
    }
}


/* Copies the 16-byte quad at data to the object base and returns it. */
// FUN_004A5B40
u_long128 WindSetFirstQuad(u8 *destination, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    *(u_long128 *)destination = value;
    return value;
}


/* Copies the 16-byte quad at data to +0x10 of the object and returns it. */
// FUN_004A5B50
u_long128 WindSetSecondQuad(u8 *destination, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    ((u_long128 *)destination)[1] = value;
    return value;
}


/* Stores the wind instance packed color at +0x30. */
// FUN_004A5B60
void mdlEffectSetWindColor(u8 *instance, s32 value)
{
    ((MdlEffectVectorInstance *)instance)->packedColor = value;
}


/* Writes the same float to +0x20, +0x24 and +0x28, giving a uniform scale. */
// FUN_004A5B70
void WindSetUniformScale(u8 *instance, f32 scale) {
    ((MdlEffectVectorInstance *)instance)->scale[0] = scale;
    ((MdlEffectVectorInstance *)instance)->scale[1] = scale;
    ((MdlEffectVectorInstance *)instance)->scale[2] = scale;
}


/* Copies the three floats of data into +0x20, +0x24 and +0x28. */
// FUN_004A5B90
void WindSetVec3(u8 *instance, f32 *scale) {
    ((MdlEffectVectorInstance *)instance)->scale[0] = scale[0];
    ((MdlEffectVectorInstance *)instance)->scale[1] = scale[1];
    ((MdlEffectVectorInstance *)instance)->scale[2] = scale[2];
}


extern void primQuad3D(f32 *pos, u8 *col, s32 size, f32 saveAndRestoreRenderState);
extern void primAxisLine3D(f32 *mat, s32 length, f32 saveAndRestoreRenderState);
extern s32 mdlEffectShareTrackInstance(s32 source);
extern void TlpRelease(s32 work);
extern s32 TlpAddRef(s32 work);
// Destroys an instance: releases its +0xCC table handle and +0xD0 record reference, destroys its geometry block, and frees the instance.
// FUN_004A5DE0
void mdlEffectDestroyInstance(u8 *instance) {
    s32 tlpRef;
    s32 trackInstance;

    tlpRef = (s32)(((MdlEffectSpriteInstance *)instance)->tlpRef);
    if (tlpRef != 0) {
        TlpRelease(tlpRef);
    }
    trackInstance = (s32)(((MdlEffectSpriteInstance *)instance)->tracks);
    if (trackInstance != 0) {
        mdlEffectReleaseTrackInstance((u8 **)trackInstance);
    }
    GeometryBlockDestroy(((MdlEffectSpriteInstance *)instance)->geometry);
    (*jtbl_008873EC)(instance);
}


// Clones an instance: a blank instance from mdlEffectCreateInstance takes a clone of the geometry block, a copy of the 0x98-byte record, and the source's references.
// FUN_004A5E50
void *mdlEffectCloneInstance(void *source)
{
    u8 *original = (u8 *)source;
    u8 *clone;
    u8 *geometryBlock;
    u8 *colors;

    clone = mdlEffectCreateInstance(NULL);
    geometryBlock = GeometryCloneBlock(((MdlEffectSpriteInstance *)original)->geometry);
    ((MdlEffectSpriteInstance *)clone)->geometry = (s32)geometryBlock;
    colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometryBlock)->atomic)->geometry->colors;
    ((s32 *)colors)[0] = -1;
    ((s32 *)colors)[1] = -1;
    ((s32 *)colors)[2] = -1;
    ((s32 *)colors)[3] = -1;
    memcpy(clone + 0x30, original + 0x30, 0x98);
    mdlEffectCopyReferences(clone, original);
    return clone;
}


// Takes new references from the source: when its +0xD0 record reference is set, releases the destination's +0xD0 and stores a fresh reference from it; otherwise, when +0xCC is set, releases the destination's +0xCC and takes a new TlpAddRef on it.
// FUN_004A5EF0
void mdlEffectCopyReferences(u8 *destination, u8 *source)
{
    /* measured: The reference assignment lines retain raw +0xCC/+0xD0 loads/stores: typing either source or destination separately changed instruction bytes; all reference tests are typed (measured individually). */
    s32 oldTrackInstance;
    s32 oldTlpRef;

    if (((MdlEffectSpriteInstance *)source)->tracks != 0) {
        oldTrackInstance = ((MdlEffectSpriteInstance *)destination)->tracks;
        if (oldTrackInstance != 0) {
            mdlEffectReleaseTrackInstance((u8 **)oldTrackInstance);
        }
        *(s32 *)(destination + 0xD0) = mdlEffectShareTrackInstance(*(s32 *)(source + 0xD0));
        return;
    }
    if (((MdlEffectSpriteInstance *)source)->tlpRef != 0) {
        oldTlpRef = ((MdlEffectSpriteInstance *)destination)->tlpRef;
        if (oldTlpRef != 0) {
            TlpRelease(oldTlpRef);
        }
        *(s32 *)(destination + 0xCC) = TlpAddRef(*(s32 *)(source + 0xCC));
    }
}


/* Sets the sprite frame counter at +0x2C to zero. */
// FUN_004A5F90
void EffSpriteClearFrameCount(u8 *instance)
{
    ((MdlEffectSpriteInstance *)instance)->age = 0;
}


/* Increments the sprite frame counter at +0x2C. */
// FUN_004A5FA0
void EffSpriteIncrementFrameCount(u8 *instance) {
    (((MdlEffectSpriteInstance *)instance)->age)++;
}


/* Increments the sprite frame counter at +0x2C, then runs the sprite update. */
// FUN_004A6B90
void EffSpriteAdvanceFrame(u8 *instance) {
    (((MdlEffectSpriteInstance *)instance)->age)++;
    EffSpriteUpdate(instance);
}


/* Identical body to WindSetFirstQuad. Slot 0 of the 16-byte table at 0x00713660, which has no decompiled reader yet, so the sprite owner is inferred from the adjacent sprite functions. */
// FUN_004A6BC0
u_long128 EffSpriteSetFirstQuad(u8 *destination, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    *(u_long128 *)destination = value;
    return value;
}


/* Identical body to WindSetSecondQuad. Slot 1 of the 16-byte table at 0x00713660, which has no decompiled reader yet, so the sprite owner is inferred from the adjacent sprite functions. */
// FUN_004A6BD0
u_long128 EffSpriteSetSecondQuad(u8 *destination, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    ((u_long128 *)destination)[1] = value;
    return value;
}


// Stores the packed colour word at +0x24. The record dispatch calls the kind 9 +0x30 slot with the packed colour.
// FUN_004A6BE0
void mdlEffectInstanceSetPackedColor(u8 *instance, s32 packedColor)
{
    ((MdlEffectSpriteInstance *)instance)->packedColor = packedColor;
}


// Stores the float at +0x20. Called through the kind 9 +0x28 slot.
// FUN_004A6BF0
void mdlEffectInstanceSetScale(u8 *instance, f32 scale) {
    ((MdlEffectSpriteInstance *)instance)->scale = scale;
}


#pragma opt_loop_invariants on
/* measured: close loop-invariant hoisting after mdlEffectCreateGridForRecord. */
#pragma opt_loop_invariants off
// Resolves the source's relative pointer A and creates the grid object from that record.
// FUN_004A6D90
void *mdlEffectCreateGridForObject(void *source) {
    u8 *temp;
    temp = mdlEffectResolveRelPtrA(source);
    return mdlEffectCreateGridForRecord(temp);
}


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
// Releases the grid geometry at +0x58 through func_004841c0 and frees the object: the destroy counterpart of mdlEffectCreateGridForRecord, which allocates the object with that geometry at +0x58.
// FUN_004A6DC0
void mdlEffectDestroyGridObject(u8 *instance)
{
    mdlEffectDestroyMultipartGeometry((u8 *)((MdlEffectFlareInstance *)instance)->geometry);
    jtbl_008873EC[0](instance);
}


// Creates the grid object from the record embedded at +0x18 of the source instance.
// FUN_004A6E10
void *mdlEffectCreateGridFromInstance(void *source) {
    u8 *instance = (u8 *)source;
    return mdlEffectCreateGridForRecord(instance + 0x18);
}


/* Resets the flare age counter to zero. */
// FUN_004A6E40
void mdlEffectResetFlareAge(u8 *instance)
{
    ((MdlEffectFlareInstance *)instance)->age = 0;
}


/* Increments the u32 counter at +0x10 of the record by one. */
// FUN_004A6E50
void mdlEffectIncrementCounter(int instance)
{
  ((MdlEffectFlareInstance *)instance)->age = ((MdlEffectFlareInstance *)instance)->age + 1;
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
void mdlEffectRenderFlares(u8 *instance)
{
    /* measured: Remaining byte-addressed geometry/material reloads and entry-color load preserve MATCH: whole-line and inner-pointer typing each changed instruction bytes; other model fields, entries and native vertices are typed (measured individually). */
    extern s32 mdlEffectSamplePackedColor(u8 *colorData, u8 *opacityData, s32 frame, s32 duration);
    extern RpGeometry *func_003c22f0(RpGeometry *geometry);
    extern RpMaterial *RpMaterialSetTexture(RpMaterial *material, RwTexture *texture);
    extern s32 TnSlotObject(u16 slotIndex);
    extern s32 TnGetOffset38(u16 slotIndex);
    extern void PrimAppendNode(u8 *list, u8 *node);
    extern RwFrame *func_003e9cb0(RwFrame *frame, const RwMatrix *transform, RwOpCombineType combine);
    extern s32 kwlnGetCamera(void);
    extern RwMatrix *RwFrameGetLTM(RwFrame *frame);
    extern f32 sqrtf(f32 x);
    extern u8 D_007141B0[];
    extern f32 D_00922D80[];
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

    __asm__ volatile("lqc2 $vf10, 0(%0)" : : "r"(instance),
        "m"(*(f32 (*)[4])instance) : "$vf10", "memory");
    if (mdlEffectAnchorOnScreen() == 0) {
        return;
    }
    __asm__ volatile("sqc2 $vf10, 0(%1)" : "=m"(proj) : "r"(proj)
        : "$vf10", "memory");
    dx = proj[0] - 320.0f;
    dy = proj[1] - 224.0f;
    cnt50 = ((MdlEffectFlareInstance *)instance)->duration;
    cnt10 = ((MdlEffectFlareInstance *)instance)->age;
    listBase = ((MdlEffectFlareInstance *)instance)->geometry;
    if (!(cnt50 <= 0 || cnt10 < cnt50)) {
        return;
    }
    dist = sqrtf(dx * dx + dy * dy);
    if (dist <= 0.0f) {
        return;
    }
    maxD = sqrtf(152576.0f); /* Squared distance from screen center to its corner. */
    scale = (maxD - dist) / maxD;
    scale = scale * ((MdlEffectFlareInstance *)instance)->scale;
    colA = mdlEffectSamplePackedColor(instance + 0x18, instance + 0x3C, cnt10, cnt50);
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
    colB = ((MdlEffectFlareInstance *)instance)->packedColor;
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
        u8 *p = ((MdlEffectRenderModel *)listBase)->atomic;
        u8 *q = (u8 *)((RpAtomic *)p)->geometry;
        RpGeometryLock((RpGeometry *)q, 0xFF2);
        vtxCur = *(u8 **)(*(u8 **)(*(u8 **)(listBase + 0x10) + 0x18) + 0x5C);
        vtxCur = (u8 *)((RpMorphTarget *)vtxCur)->vertices;
        vtxBase = vtxCur;
        auxCur = *(u32 **)(*(u8 **)(*(u8 **)(listBase + 0x10) + 0x18) + 0x34);
        entry = D_007141B0 + (s32)((MdlEffectFlareInstance *)instance)->variant * 0xD0;
        outer = 0;
        while (outer < 13) {
            if ((((MdlEffectFlareEntry *)entry)->packedColor & 0xFF000000) == 0) {
                auxCur = (u32 *)((u8 *)auxCur + 0x80);
/* measured: hoist the four position-record source bases for this loop. */
#pragma opt_loop_invariants on
                for (inner = 0; inner < 4; inner++) {
                    ((RwV3d *)vtxCur)[0] = *(const RwV3d *)D_00922D80;
                    ((RwV3d *)vtxCur)[1] = *(const RwV3d *)D_00922D80;
                    ((RwV3d *)vtxCur)[2] = *(const RwV3d *)D_00922D80;
                    ((RwV3d *)vtxCur)[3] = *(const RwV3d *)D_00922D80;
                    vtxCur += 0x30;
                }
/* measured: restore the outer loop's unhoisted material and scale values. */
#pragma opt_loop_invariants off
                {
                    if (iGpffffbb64.c3 != 0xFF) {
                        u8 *tbl = ((MdlEffectRenderModel *)listBase)->materials;
                        u8 *sl = ((u8 **)tbl)[outer & 0xFFFF];
                        *(MdlCol *)&((RpMaterial *)sl)->color = iGpffffbb64;
                    } else {
                        u8 *tbl;
                        u8 *sl;
                        iGpffffbb64.c3 = 0xFE;
                        tbl = ((MdlEffectRenderModel *)listBase)->materials;
                        sl = ((u8 **)tbl)[outer & 0xFFFF];
                        *(MdlCol *)&((RpMaterial *)sl)->color = iGpffffbb64;
                        iGpffffbb64.c3 = 0xFF;
                    }
                }
            } else {
                s32 idx;
                s32 dev = TnSlotObject(((MdlEffectFlareEntry *)entry)->texture);
                idx = (outer & 0xFFFF) * 4;
                RpMaterialSetTexture(*(RpMaterial **)(*(u8 **)(listBase + 0x54) + idx), (RwTexture *)(u32)dev);
                fx = dx * ((MdlEffectFlareEntry *)entry)->positionFactor;
                fy = dy * ((MdlEffectFlareEntry *)entry)->positionFactor;
                tmpX = (s32)(320.0f + fx);
                tmpY = (s32)(224.0f + fy);
                f0 = sqrtf(fx * fx + fy * fy);
                f1 = f0 / dist;
                f1 = f1 * scale;
                f0 = 128.0f;
                f0 = f0 * ((MdlEffectFlareEntry *)entry)->sizeFactor;
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
                        slot = *(u8 **)(((MdlEffectRenderModel *)listBase)->materials + idx);
                        *(MdlCol *)&((RpMaterial *)slot)->color = color.rgba;
                    } else {
                        color.rgba.c3 = 0xFE;
                        slot = *(u8 **)(((MdlEffectRenderModel *)listBase)->materials + idx);
                        *(MdlCol *)&((RpMaterial *)slot)->color = color.rgba;
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
                ((RwV3d *)vtxCur)[0].x = vx0;
                vy0 = (f32)(tmpY - isz);
                ((RwV3d *)vtxCur)[0].y = vy0;
                gw = (f32)isz;
                ((RwV3d *)vtxCur)[1].x = ((RwV3d *)vtxCur)[0].x + gw;
                ((RwV3d *)vtxCur)[1].y = ((RwV3d *)vtxCur)[0].y;
                ((RwV3d *)vtxCur)[2].x = ((RwV3d *)vtxCur)[0].x;
                ((RwV3d *)vtxCur)[2].y = ((RwV3d *)vtxCur)[0].y + gw;
                ((RwV3d *)vtxCur)[3].x = ((RwV3d *)vtxCur)[0].x + gw;
                ((RwV3d *)vtxCur)[3].y = ((RwV3d *)vtxCur)[0].y + gw;
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
                    ((RwV3d *)vtxCur)[4].x = vx1;
                    ((RwV3d *)vtxCur)[4].y = vy0;
                    ((RwV3d *)vtxCur)[5].x = ((RwV3d *)vtxCur)[4].x + gw;
                    ((RwV3d *)vtxCur)[5].y = ((RwV3d *)vtxCur)[4].y;
                    ((RwV3d *)vtxCur)[6].x = ((RwV3d *)vtxCur)[4].x;
                    ((RwV3d *)vtxCur)[6].y = ((RwV3d *)vtxCur)[4].y + gw;
                    ((RwV3d *)vtxCur)[7].x = ((RwV3d *)vtxCur)[4].x + gw;
                    ((RwV3d *)vtxCur)[7].y = ((RwV3d *)vtxCur)[4].y + gw;
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
                    ((RwV3d *)vtxCur)[8].x = vx0;
                    ((RwV3d *)vtxCur)[8].y = vy1;
                    ((RwV3d *)vtxCur)[9].x = ((RwV3d *)vtxCur)[8].x + gw;
                    ((RwV3d *)vtxCur)[9].y = ((RwV3d *)vtxCur)[8].y;
                    ((RwV3d *)vtxCur)[10].x = ((RwV3d *)vtxCur)[8].x;
                    ((RwV3d *)vtxCur)[10].y = ((RwV3d *)vtxCur)[8].y + gw;
                    ((RwV3d *)vtxCur)[11].x = ((RwV3d *)vtxCur)[8].x + gw;
                    ((RwV3d *)vtxCur)[11].y = ((RwV3d *)vtxCur)[8].y + gw;
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
                    ((RwV3d *)vtxCur)[12].x = vx1;
                    ((RwV3d *)vtxCur)[12].y = vy1;
                    ((RwV3d *)vtxCur)[13].x = ((RwV3d *)vtxCur)[12].x + gw;
                    ((RwV3d *)vtxCur)[13].y = ((RwV3d *)vtxCur)[12].y;
                    ((RwV3d *)vtxCur)[14].x = ((RwV3d *)vtxCur)[12].x;
                    ((RwV3d *)vtxCur)[14].y = ((RwV3d *)vtxCur)[12].y + gw;
                    ((RwV3d *)vtxCur)[15].x = ((RwV3d *)vtxCur)[12].x + gw;
                    ((RwV3d *)vtxCur)[15].y = ((RwV3d *)vtxCur)[12].y + gw;
                }
                vtxCur += 0xC0;
                auxCur += 0x20;
            }
            outer++;
            entry += 0x10;
        }
    }
    {
        u8 *window = ((u8 *)(u32)kwlnGetCamera()) + 0x68;
        f32 nearPlane = ((MdlEffectCamera *)(u32)kwlnGetCamera())->nearPlane;
        f32 farPlane = ((MdlEffectCamera *)(u32)kwlnGetCamera())->farPlane;
        f32 span = farPlane - nearPlane;
        f32 deviceDepth = (f32)(s32)0xFFFF0001;
        f32 denominator = deviceDepth * farPlane - -255.0f * span;
        f32 numerator;
        f32 k2 = (numerator = deviceDepth * nearPlane, numerator * farPlane) / denominator;
        f32 fA = 2.0f * (((f32 *)window)[0] * k2);
        f32 fB = 2.0f * (((f32 *)window)[1] * k2);
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
        u8 *q = (u8 *)((RpAtomic *)p)->geometry;
        func_003c22f0((RpGeometry *)q);
        if ((*(u16 *)listBase & 4) != 0) {
            ((RpGeometry *)q)->lockedSinceLastInst |= 1;
        }
        {
            u8 *r = (u8 *)((u8 *)(u32)kwlnGetCamera());
            RwMatrix *s2 = RwFrameGetLTM((RwFrame *)((MdlEffectCamera *)r)->frame);
            func_003e9cb0(((MdlEffectRenderModel *)listBase)->frame, s2, rwCOMBINEREPLACE);
        }
        {
            u16 id = ((MdlEffectFlareInstance *)instance)->scene;
            u8 *wd = (u8 *)(u32)TnGetOffset38(id);
            ((MdlEffectRenderModel *)listBase)->drawPrevious = 0;
            ((MdlEffectRenderModel *)listBase)->drawNext = 0;
            PrimAppendNode(wd, listBase + 0x18);
        }
    }
}
#pragma pop
/* Increments the counter at +0x10 and renders the flares via mdlEffectRenderFlares. */
// FUN_004A7760
void mdlEffectIncrementAndRender(u8 *instance) {
    (((MdlEffectFlareInstance *)instance)->age)++;
    mdlEffectRenderFlares(instance);
}
/* Copies one 128-bit value from *data into *input and returns it. */
// FUN_004A7790
u_long128 mdlEffectStoreQuad(u_long128 *destination, u_long128 *source)
{
    return *destination = *source;
}
// Stores data at word 5 (+0x14) of the record at value.
// FUN_004A77A0
void mdlEffectSetWord5(u32 *instance, u32 value)
{
  instance[5] = value;
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
/* Replaces the shared frame translation and clears its active flag. */
// FUN_004A7A50
void mdlEffectResetSequenceFrame(void) {
    func_003e9c10((u8 *)D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
}


/* Resets the shared frame translation and active flag, then frees callback storage. */
// FUN_004A7B10
void mdlEffectReleaseSequenceFrame(s32 instance) {
    func_003e9c10((u8 *)D_00724C70, D_00922D80, 0);
    D_00724C58 = 0;
    D_008873ec[0]((void *)instance);
}


/* Applies the sequence payload at its current frame and increments the stored frame counter. */
// FUN_004A7DA0
void mdlEffectAdvanceSequenceCallback(s32 *instance) {
    mdlEffectApplyShakeEnvelope((u8 *)instance + 4, *instance);
    *instance += 1;
}


// FUN_004A7DF0
void mdlEffectStepSequenceCallback(s32 *instance) {
    mdlEffectApplyShakeEnvelope((u8 *)instance + 4, *instance);
    *instance += 1;
}


#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
/* Chooses a starting frame and independently jittered quad center, then computes its square bounds. */
// FUN_004A8A50
void mdlEffectInitRandomQuad(u8 *parameters, u8 *entry)
{
    f32 centerY;
    f32 spread;
    f32 halfSize;
    f32 centerX;
    u8 *rectangle;

    *(u32 *)entry = effMiscRand(0) % (u32)(((MdlEffectQuadParameters *)parameters)->frameRange + 1);
    ((MdlEffectQuadEntry *)entry)->progress = fGpffff80f4;
    rectangle = entry + 8;
    ((MdlEffectQuadEntry *)entry)->state.unk8 = ((MdlEffectQuadParameters *)parameters)->unk10;
    ((MdlEffectQuadEntry *)entry)->state.unkC = ((MdlEffectQuadParameters *)parameters)->unk14;
    ((MdlEffectQuadEntry *)entry)->state.unk4 = ((MdlEffectQuadParameters *)parameters)->unkC;
    halfSize = 0.5f * (f32)((MdlEffectQuadParameters *)parameters)->size;
    spread = ((MdlEffectQuadParameters *)parameters)->spread;
    centerX = ((MdlEffectQuadParameters *)parameters)->centerX +
               spread * (2.0f * (effMiscRandFloat(0) - 0.5f));
    centerY = ((MdlEffectQuadParameters *)parameters)->centerY +
              spread * (2.0f * (effMiscRandFloat(0) - 0.5f));
    ((MdlEffectQuadState *)rectangle)->centerX = centerX;
    ((MdlEffectQuadState *)rectangle)->centerY = centerY;
    ((MdlEffectQuadState *)rectangle)->left = centerX - halfSize;
    ((MdlEffectQuadState *)rectangle)->top = centerY - halfSize;
    ((MdlEffectQuadState *)rectangle)->right = centerX + halfSize;
    ((MdlEffectQuadState *)rectangle)->bottom = centerY + halfSize;
}


/* Caches the display-buffer raster pointer and its floating-point width and height. */
// FUN_004ABB60
void mdlEffectCacheDisplayRaster(void)
{
    u8 *raster;

    raster = RpSkyGetDisplayBufferRaster();
    *(u8 **)&D_00922D90[0] = raster;
    D_00922D94[0] = (f32)((MdlEffectRaster *)raster)->width;
    D_00922D98[0] = (f32)((MdlEffectRaster *)raster)->height;
}


#pragma push
#pragma opt_propagation off
#pragma pop
// Resets a drawable: when its entry count at +0x9C is nonzero, runs func_00485fe0 on each entry of the list at +0x98 (count at +0x28); then zeroes the model layer time at +0xA0 and clears the counter at +0x2C.
// FUN_004ADAB0
void EffModelDrawableReset(u8 *instance)
{
    s32 *child;
    u32 childCount;
    u32 childIndex;

    if (((MdlEffectSpriteInstance *)instance)->drawable != 0) {
        childCount = ((MdlEffectSpriteInstance *)instance)->childCount;
        child = ((MdlEffectSpriteInstance *)instance)->children;
        childIndex = 0;
        while (childIndex < childCount) {
            mdlEffectStartChildren(*child);
            child++;
            childIndex += 1;
        }
    }
    mdlSetLayerTime((u8 *)((MdlEffectSpriteInstance *)instance)->model, 0, 0.0f);
    ((MdlEffectSpriteInstance *)instance)->age = 0;
}


#pragma push
#pragma optimization_level 3
#pragma schedule off
#pragma opt_loop_invariants off
#pragma opt_rotateloops off
#pragma tailcall off
#pragma opt_common_subs off
#pragma opt_propagation off
#pragma pop
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma opt_loop_invariants on
#pragma opt_loop_invariants off
#pragma push
#pragma opt_propagation off
#pragma pop
/* Draws diagnostic model matrices or processes child effects while the drawable duration allows it. */
// FUN_004ADE80
void mdlEffectDrawModelChildren(u8 *instance)
{
    u8 frame[0x50];
    s32 *child;
    s32 duration;
    u32 childCount;
    u32 matrixIndex;
    u32 childIndex;

    if (((MdlEffectSpriteInstance *)instance)->drawable == 0) {
        frame[0x4C] = 0xFF;
        frame[0x4D] = 0xFF;
        frame[0x4E] = 0;
        frame[0x4F] = 0xFF;
        matrixIndex = 0;
        while (matrixIndex < (u32)((MdlEffectSpriteInstance *)instance)->childCount) {
            if (mdlCopyIndexedMatrix(((MdlEffectSpriteInstance *)instance)->model, matrixIndex, frame) != 0) {
                primQuad3D((f32 *)(frame + 0x30), frame + 0x4C, 1, 4.0f);
                primAxisLine3D((f32 *)frame, 1, 30.0f);
            }
            matrixIndex += 1;
        }
        return;
    }
    duration = ((MdlEffectSpriteInstance *)instance)->duration;
    childCount = ((MdlEffectSpriteInstance *)instance)->childCount;
    child = ((MdlEffectSpriteInstance *)instance)->children;
    if ((((MdlEffectSpriteInstance *)instance)->age < duration) || (duration == 0)) {
        childIndex = 0;
        while (childIndex < childCount) {
            mdlEffectFlushTreeFrame((u8 *)*child);
            child++;
            childIndex += 1;
        }
    }
}


/* Runs the model-effect update pass followed by the child drawing pass. */
// FUN_004ADFA0
void mdlEffectUpdateAndDrawModelChildren(u8 *instance) {
    func_004adb50();
    mdlEffectDrawModelChildren(instance);
}


// Copies the 16-byte vector at data to +0x00. Called through the kind table's +0x20 position slot.
// FUN_004ADFE0
u_long128 EffModelDrawableStorePosition(u8 *instance, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    *(u_long128 *)instance = value;
    return value;
}


// Copies the 16-byte vector at data to +0x10. Called through the kind table's +0x24 rotation slot.
// FUN_004ADFF0
u_long128 EffModelDrawableStoreRotation(u8 *instance, u8 *source) {
    u_long128 value;
    value = *(u_long128 *)source;
    ((u_long128 *)instance)[1] = value;
    return value;
}


// Stores the packed colour word at +0x24. Called through the kind table's +0x30 slot with the packed colour.
// FUN_004AE000
void EffModelDrawableSetPackedColor(u8 *instance, s32 packedColor) {
    ((MdlEffectSpriteInstance *)instance)->packedColor = packedColor;
}


// Stores the float at +0x20. Called through the kind table's +0x28 slot.
// FUN_004AE010
void EffModelDrawableSetScale(u8 *instance, f32 scale) {
    ((MdlEffectSpriteInstance *)instance)->scale = scale;
}


/* Writes the four colour bytes at data into bytes +4..+7 of every entry in the record's entry table. */
// FUN_004AE020
u32 *mdlEffectSetAllColors(u32 *instance, u8 *value)
{
  RpGeometry *geometry;
  int materialCount;
  int materialIndex;
  u8 *material;

  u8 red;
  u8 green;
  u8 blue;
  u8 alpha;

  geometry = ((RpAtomic *)instance)->geometry;
  materialCount = ((MdlEffectMaterialList *)&geometry->materials)->count;
  materialIndex = 0;
  while (materialIndex < materialCount) {
    material = geometry->materials[materialIndex];
    red = value[0];
    green = value[1];
    blue = value[2];
    alpha = value[3];
    red = red;
    green = green;
    blue = blue;
    alpha = alpha;
    material[4] = red;
    material[5] = green;
    material[6] = blue;
    material[7] = alpha;
    materialIndex = materialIndex + 1;
  }
  return instance;
}



// Sets bit 0x40 in the word at +0x08 of the record at +0x18 of value and returns value.
// FUN_004AE080
void *mdlEffectSetFlag40(void *instance, void *data)
{
  u32 *p;

  p = (u32 *)((RpAtomic *)instance)->geometry;
  p[2] = p[2] | 0x40;
  return instance;
}



/* Normalizes a fixed or random direction, randomizes speed and angle, and selects a face index. */
// FUN_004AE0A0
void mdlEffectInitDirectionEntry(u8 *parameters, u8 *entry)
{
    f32 direction[4];
    f32 lengthOrScale;
    s32 faceMode;

    if (((MdlEffectDirectionParameters *)parameters)->randomDirection == 0) {
        direction[0] = ((MdlEffectDirectionParameters *)parameters)->direction[0];
        direction[1] = ((MdlEffectDirectionParameters *)parameters)->direction[1];
        direction[2] = ((MdlEffectDirectionParameters *)parameters)->direction[2];
    } else {
        direction[0] = 2.0f * (effMiscRandFloat(0) - 0.5f);
        direction[1] = 2.0f * (effMiscRandFloat(0) - 0.5f);
        direction[2] = 2.0f * (effMiscRandFloat(0) - 0.5f);
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
        : "=f"(lengthOrScale)
        : "r"(direction)
        : "$2", "$vf2", "$vf10", "Q", "memory");
    if (lengthOrScale == 0.0f) {
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
        : "r"(direction)
        : "$vf0", "$vf2", "$vf10", "ACC", "Q", "memory");
    ((MdlEffectDirectionEntry *)entry)->direction[0] = direction[0];
    ((MdlEffectDirectionEntry *)entry)->direction[1] = direction[1];
    ((MdlEffectDirectionEntry *)entry)->direction[2] = direction[2];
    goto normalized_done;
normalized_zero:
    ((MdlEffectDirectionEntry *)entry)->direction[0] = 0.0f;
    ((MdlEffectDirectionEntry *)entry)->direction[1] = 1.0f;
    ((MdlEffectDirectionEntry *)entry)->direction[2] = 0.0f;
normalized_done:
    lengthOrScale = ((MdlEffectDirectionParameters *)parameters)->speedSpread;
    lengthOrScale = (1.0f - lengthOrScale) + lengthOrScale * effMiscRandFloat(0);
    ((MdlEffectDirectionEntry *)entry)->speed = ((MdlEffectDirectionParameters *)parameters)->speed * lengthOrScale;
    ((MdlEffectDirectionEntry *)entry)->angle = iGpffff8080 * effMiscRandFloat(0);
    faceMode = ((MdlEffectDirectionParameters *)parameters)->faceMode;
    switch (faceMode) {
    case 1:
        ((MdlEffectDirectionEntry *)entry)->face.value = (u8)(effMiscRand(0) % 6);
        break;
    case 2:
        ((MdlEffectDirectionEntry *)entry)->face.value =
            (u8)(((u32)((u8 *)entry - ((MdlEffectDirectionParameters *)parameters)->entries) / 0x18) % 6);
        break;
    default:
        ((MdlEffectDirectionEntry *)entry)->face.signedValue = -1;
        break;
    }
}


// Stores the position quad into the record at +0x58 through mdlEffectStoreQuadA, the same record ObjectParticleAppendNode reads. DistortParticleStorePosition stores the same way at +0x5c.
// FUN_004AF5E0
void ObjectParticleStorePosition(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA((s32)((ObjectParticleInstance *)instance)->list, position);
}


// Stores the rotation quad into the record at +0x58 through mdlEffectStoreQuadB, the same record ObjectParticleAppendNode reads.
// FUN_004AF610
void ObjectParticleStoreRotation(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB((s32)((ObjectParticleInstance *)instance)->list, rotation);
}


// Stores the packed colour word at +0x4. The record dispatch calls it through the kind table's +0x30 slot with the packed colour; this is the object-particle kind's entry.
// FUN_004AF640
void ObjectParticleSetPackedColor(u8 *instance, s32 packedColor) {
    ((ObjectParticleInstance *)instance)->packedColour = packedColor;
}


// Stores the scale at +0x08 and applies it to the emitter at +0x58, the object-particle twin of DistortParticleSetScale (emitter at +0x5c).
// FUN_004AF650
void ObjectParticleSetScale(u8 *instance, f32 scale) {
    ((ObjectParticleInstance *)instance)->field_0x08 = scale;
    EffEmitterApplyScale((u16 *)((ObjectParticleInstance *)instance)->list, scale);
}


extern void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source);
extern s32 iGpffffbb98; /* sequence playback enabled */
extern s32 iGpffffbb94; /* current sequence frame */
extern s32 D_00922DA0[]; /* sequence duration; zero leaves it unbounded */
extern s16 D_00922DA4[]; /* sequence selector */
extern s32 D_00922DA8[];
extern s32 D_00922DAC[];
extern void mdlEffectSetChildPositions(void *effect, f32 *value);
extern void mdlEffectUpdateScreenSprite(u8 *instance);
extern void func_003efd20(u8 *input, s32 data);
extern void func_003e9390(s32 input);
extern void func_003ec330(s32 input);
extern void RpSkyTexCacheRasterLock(s32 input, s32 data);
extern void func_003e8440(u8 *input);
extern void mdlEffectScreenSpriteCopyResource(u8 *destination, u8 *source);
extern u8 D_0071465C[];
extern u8 D_00714650[];
extern u8 D_00714660[];
extern void mdlEffectGetPositionVec(u8 *object, u32 *output);
extern void mdlEffectSetChildRotations(u8 *effect, void *value);
extern void effMiscEulerToQuatVU(f32 angleX, f32 angleY, f32 angleZ);
extern f32 iGpffff836c;
extern void mdlEffectGetOrientationVec(u8 *object, u32 *output);
extern void mdlEffectApplyPackedColor(u8 *effect, s32 value);
extern u32 mdlEffectGetPackedColorWord(void *object);
typedef signed __int128 s128;
extern void *mdlEffectCreateScreenSprite(void *opaqueSource);
typedef signed __int128 s128;
typedef signed __int128 s128;
/* Distort particle setter: stores the position quad into the emitter at instance+0x5C.
 * effDistortParticle.c creates that emitter in the same slot (func_00492b20 with the
 * instance's kind), so the setter belongs to the distort instance. */
// FUN_004B1090
void DistortParticleStorePosition(u8 *instance, u32 *position)
{
    mdlEffectStoreQuadA((s32)((DistortParticleInstance *)instance)->list, position);
}


/* Stores the rotation quad in the distortion-particle emitter. */
// FUN_004B10C0
void DistortParticleStoreRotation(u8 *instance, u32 *rotation)
{
    mdlEffectStoreQuadB((s32)((DistortParticleInstance *)instance)->list, rotation);
}


// Stores the packed colour word at +0x4. The record dispatch calls it through the kind table's +0x30 slot with the packed colour; this is the distort kind's entry.
// FUN_004B10F0
void DistortParticleSetPackedColor(u8 *instance, s32 packedColor)
{
    ((EffParticleInstance *)instance)->packedColor.signedValue = packedColor;
}


/* Stores the distortion-particle scale and applies it to its emitter. */
// FUN_004B1100
void DistortParticleSetScale(u8 *instance, f32 scale)
{
    ((EffParticleInstance *)instance)->scale.value = scale;
    EffEmitterApplyScale((u16 *)((DistortParticleInstance *)instance)->list, scale);
}


/* Extends a three-component position with a zero fourth lane before applying it to the children. */
// FUN_004B1250
void mdlEffectSetChildPositionVec(void *object, f32 *position)
{
    f32 work[4];

    work[0] = position[0];
    work[1] = position[1];
    work[2] = position[2];
    work[3] = 0.0f;
    mdlEffectSetChildPositions(object, work);
}


// Converts the Euler angles data..flags, each scaled by iGpffff836c, to a quaternion and passes it with input to 00486330.
// FUN_004B1290
void mdlEffectSetEulerRotation(u8 *object, f32 angleX, f32 angleY, f32 angleZ)
{
    u8 scratch[16];

    effMiscEulerToQuatVU(iGpffff836c * angleX, iGpffff836c * angleY, iGpffff836c * angleZ);
    __asm__ volatile("sqc2 vf10, 0(%0)" : : "r"(scratch) : "memory");
    mdlEffectSetChildRotations(object, scratch);
}




// Sets the object's packed colour to *data through mdlEffectApplyPackedColor.
// FUN_004B13F0
void mdlEffectSetPackedColor(void *object, s32 *packedColor) {
    mdlEffectApplyPackedColor(object, *packedColor);
}


// Builds the object's basis rows from the orientation vector at +0x50 and writes its position (the first three floats of +0x40) into the matrix translation at +0x30..+0x38.
// FUN_004B1470
void mdlEffectBuildObjectMatrix(u8 *object, u8 *matrix)
{
    struct {
        f32 projected[3];
        u32 alignment;
        u8 vector[16];
    } scratch;

    mdlEffectGetOrientationVec(object, (u32 *)scratch.vector);
    mdlEffectBuildBasisRows(matrix, scratch.vector);
    mdlEffectGetPositionVec(object, (u32 *)scratch.projected);
    ((RwMatrix *)matrix)->pos.x = scratch.projected[0];
    ((RwMatrix *)matrix)->pos.y = scratch.projected[1];
    ((RwMatrix *)matrix)->pos.z = scratch.projected[2];
}


// Reads the object's packed colour through mdlEffectGetPackedColorWord into *data.
// FUN_004B14F0
void mdlEffectGetPackedColor(void *object, s32 *color) {
    *color = mdlEffectGetPackedColorWord(object);
}


// Returns the word at +0x84 of the object at value.
// FUN_004B1580
u32 mdlEffectGetWord84(int instance)
{
  return ((MdlEffectObject *)instance)->unk84;
}



/* Initializes the sequence duration/id and enables playback from frame zero. */
// FUN_004B1590
void mdlEffectSeqStart(s32 duration, s16 sequenceId)
{
    D_00922DA0[0] = duration;
    D_00922DA4[0] = sequenceId;
    D_00922DA8[0] = 0;
    D_00922DAC[0] = 0;
    iGpffffbb94 = 0;
    iGpffffbb98 = 1;
}


/* Applies the active sequence at the current frame, resetting the frame resource at its duration. */
// FUN_004B1600
void mdlEffectSeqStep(void)
{
    s32 frame;
    s32 limit;

    if (iGpffffbb98 != 0) {
        limit = D_00922DA0[0];
        if ((iGpffffbb94 < limit) || (limit == 0)) {
            frame = iGpffffbb94;
            mdlEffectApplyShakeEnvelope((u8 *)&D_00922DA0[0], frame);
        } else {
            mdlEffectResetSequenceFrame();
            iGpffffbb98 = 0;
        }
        iGpffffbb94 = iGpffffbb94 + 1;
    }
}




/* Copies helper parameters, clones optional geometry, initializes its colors and copies its references. */
// FUN_004B1950
void *mdlEffectCloneHelperInstance(void *opaqueSource) {
    u8 *source = opaqueSource;
    s32 geometry;
    u8 *clone;
    u8 *geometryBlock;
    u8 *colors;

    clone = mdlEffectCreateScreenSprite(NULL);
    ((MdlEffectHelperInstance *)clone)->unk4 = ((MdlEffectHelperInstance *)source)->unk4;
    memcpy(clone + 0xC, source + 0xC, 0x98);
    geometry = ((MdlEffectHelperInstance *)source)->geometry;
    if (geometry != 0) {
        geometryBlock = GeometryCloneBlock(geometry);
        ((MdlEffectHelperInstance *)clone)->geometry = (s32)geometryBlock;
        colors = (u8 *)((RpAtomic *)((EffGeometryBlock *)geometryBlock)->atomic)->geometry->colors;
        ((s32 *)colors)[0] = -1;
        ((s32 *)colors)[1] = -1;
        ((s32 *)colors)[2] = -1;
        ((s32 *)colors)[3] = -1;
    }
    mdlEffectScreenSpriteCopyResource(clone, source);
    return clone;
}




/* Resets the helper age counter to zero. */
// FUN_004B1AA0
void mdlEffectResetHelperAge(u8 *instance)
{
    ((MdlEffectHelperInstance *)instance)->age = 0;
}


/* Increments the helper age counter. */
// FUN_004B1AB0
void mdlEffectIncrementHelperAge(u8 *instance)
{
    ((MdlEffectHelperInstance *)instance)->age = ((MdlEffectHelperInstance *)instance)->age + 1;
}


#pragma push
#pragma opt_loop_invariants on
#pragma pop
/* Increments the helper age and invokes its processing pass. */
// FUN_004B2740
void mdlEffectAdvanceHelper(u8 *instance)
{
    ((MdlEffectHelperInstance *)instance)->age = ((MdlEffectHelperInstance *)instance)->age + 1;
    mdlEffectUpdateScreenSprite(instance);
}


// Stores data into the word at *value.
// FUN_004B2770
void mdlEffectStoreWord(u32 *instance, u32 value)
{
  *instance = value;
}
#pragma push
#pragma opt_loop_invariants on
#pragma pop


#pragma opt_propagation off
#pragma opt_propagation on
#pragma push
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma pop
/* Detaches and releases camera frame/raster resources, then unlocks and releases the texture raster. */
// FUN_004B2E00
void mdlEffectReleaseCameraTexture(u8 *object) {
    /* measured: Repeated camera/raster loads and clearing stores remain raw: individually typed versions changed instruction bytes; the initial ownership reads and camera fields are typed (measured individually). */
    u8 *base;
    u8 *cameraWithRaster;
    u8 *cameraWithDepth;
    u8 *camera;
    s32 *slot_1;
    s32 *slot_2;
    s32 frame;
    s32 depthRaster;
    s32 textureRaster;

    base = object;
    camera = ((MdlEffectCameraTexture *)base)->camera;
    if (camera != NULL) {
        frame = (s32)((MdlEffectCamera *)camera)->frame;
        if (frame != 0) {
            func_003efd20(camera, 0);
            func_003e9390(frame);
        }
        cameraWithDepth = *(u8 **)(base + 0xC);
        slot_1 = (s32 *)(cameraWithDepth + 0x64);
        depthRaster = ((MdlEffectCamera *)cameraWithDepth)->depthRaster;
        if (depthRaster != 0) {
            *slot_1 = 0;
            func_003ec330(depthRaster);
        }
        cameraWithRaster = *(u8 **)(base + 0xC);
        slot_2 = (s32 *)(cameraWithRaster + 0x60);
        if (((MdlEffectCamera *)cameraWithRaster)->raster != 0) {
            *slot_2 = 0;
        }
        func_003e8440(*(u8 **)(base + 0xC));
        *(u8 **)(base + 0xC) = NULL;
    }
    textureRaster = ((MdlEffectCameraTexture *)base)->raster;
    if (textureRaster != 0) {
        RpSkyTexCacheRasterLock(textureRaster, 0);
        func_003ec330(*(s32 *)(base + 8));
        *(s32 *)(base + 8) = 0;
    }
}


/* Calls kind slot +0x00 with the object, then clears the counter at +0x14. The kind index is at +0x18. */
// FUN_004B4F40
void LineNovaInstanceStop(u8 *instance)
{
    ((void (**)(void *))D_00714650)[((MdlEffectLineNovaInstance *)instance)->kind * 6](instance);
    ((MdlEffectLineNovaInstance *)instance)->age = 0;
}


/* Calls kind slot +0x0C with the object, then increments the counter at +0x14. */
// FUN_004B4F90
void LineNovaInstanceAdvance(void *instance) {
    ((void (**)(void *))D_0071465C)[((MdlEffectLineNovaInstance *)instance)->kind * 6](instance);
    ((MdlEffectLineNovaInstance *)instance)->age += 1;
}


/* Calls kind slot +0x10 with the object when the counter at +0x14 is positive. */
// FUN_004B4FF0
void LineNovaInstanceUpdateIfActive(u8 *instance)
{
    if (((MdlEffectLineNovaInstance *)instance)->age > 0) {
        ((void (**)(void *))D_00714660)[((MdlEffectLineNovaInstance *)instance)->kind * 6](instance);
    }
}


/* Calls kind slot +0x0C, increments the counter at +0x14, then calls kind slot +0x10 when the counter is positive. The kind index is at +0x18. */
// FUN_004B5040
void LineNovaInstanceAdvanceAndUpdate(void *instance) {
    /* measured: The final +0x18 kind reload stays raw: typing it changed instruction bytes after the first callback; both callback tables and the age accesses are typed (measured individually). */
    u8 *object;

    object = instance;
    ((void (**)(void *))D_0071465C)[((MdlEffectLineNovaInstance *)object)->kind * 6](object);
    ((MdlEffectLineNovaInstance *)object)->age += 1;
    if (((MdlEffectLineNovaInstance *)object)->age > 0) {
        ((void (**)(void *))D_00714660)[*(s32 *)(object + 0x18) * 6](object);
    }
}


/* Copies and returns the position quadword, retaining the measured load-before-store temporary. */
// FUN_004B50D0
s128 mdlEffectStoreLineNovaPosition(s128 *instance, s128 *value) {
    s128 position = *value; /* measured: without the local, MWCC reloads after the store */
    *instance = position;
    return position;
}


/* Stores the line-nova packed color at +0x10. */
// FUN_004B50E0
void mdlEffectSetLineNovaColor(u8 *instance, s32 value)
{
    ((MdlEffectLineNovaInstance *)instance)->packedColor = value;
}


// Copies the 16-byte vector at data to +0x0. Called through the kind 33 +0x20 position slot.
// FUN_004B5750
s128 EffBattleStorePosition(s128 *instance, s128 *value) {
    s128 position = *value; /* measured: without the local, MWCC reloads after the store */
    *instance = position;
    return position;
}


// Copies the 16-byte vector at data to +0x10. Called through the kind 33 +0x24 rotation slot.
// FUN_004B5760
s128 EffBattleStoreRotation(u8 *instance, s128 *value) {
    s128 rotation = *value; /* measured: without the local, MWCC reloads after the store */
    ((s128 *)instance)[1] = rotation;
    return rotation;
}


// Stores the packed colour word at +0x24. The record dispatch calls the kind 33 +0x30 slot with the packed colour.
// FUN_004B5770
void EffBattleSetPackedColor(u8 *instance, s32 packedColor)
{
    ((MdlEffectSpriteInstance *)instance)->packedColor = packedColor;
}


// Stores the float at +0x20. Called through the kind 33 +0x28 slot.
// FUN_004B5780
void EffBattleSetScale(u8 *instance, f32 scale)
{
    ((MdlEffectSpriteInstance *)instance)->scale = scale;
}



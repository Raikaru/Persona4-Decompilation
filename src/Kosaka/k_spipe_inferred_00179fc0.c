#include "btl_target_state_packet_internal.h"
#include "mt_scene_internal.h"
#include "rw_geometry_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
struct RpGeometry;
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct RwRGBA RwRGBA;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
struct Model;
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;
extern s32 *MT_Scene_GetFrameState(void);
/* measured: Cmd_PickEncounter needs this call unprototyped - retail masks $a2 (b)
   before the two lhu loads and $a3 (a) after them, which is the default-
   promotion order of an old-style call with a u16 local for b and an explicit
   (u16) cast on a; any prototyped u16 parameter hoists the a3 mask before the
   loads (nd4). Sole caller in this unit. */
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 FldMap_IsCurrentInBandA(void);
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
extern u8 D_007EF9B0[];
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
void func_0017d240(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                    s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern u8 *MT_Scene_GetResListHead(s32 arg0);

extern void *mdlGetMatrix(void *arg0);
extern void mdlScale(void *arg0, void *arg1, s32 arg2);
extern s32 RwEngineGetMatrixTolerances(f32 *arg0);
extern u8 *RwMatrixOptimize(void *arg0, f32 *arg1);
extern u8 *RwMatrixUpdate(void *arg0);
extern void mdlUpdateModelMatrix(void *arg0);
extern void mdlPrepareItemSlots(void *arg0);
extern s32 FldShadow_DrawProjection(u8 *arg0, s32 arg1, s32 arg2, void *arg3,
                         f32 farg0, f32 farg1, s32 arg4, u8 *arg5);
extern u8 D_007EFA00[];
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                           f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6,
                           void *arg7, s32 arg8,
                           f32 arg9, f32 arg10, f32 arg11,
                           s32 arg12, void *arg13, f32 arg14);
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern s32 D_005F1930[];
extern s32 D_005F1934[];

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;





/* measured: ONE real defect, and it is the `slt $at` family. Retail emits
   `slti $at,$v0,4; bnez $at` where b210 emits `slti $v0,$v0,4; bnez $v0`,
   reusing the dead call result as the comparison destination. obj 92B vs
   window 96B, so the reported count also includes one padding word.
   `#pragma schedule off` and hoisting the call result into a local both leave
   it unchanged.

   Do NOT record this as a blanket floor. A census of the retail image shows the
   $at form in 276 first-party functions that ALREADY MATCH, so it is reachable
   from C -- it appears when the comparison feeds a short-circuit `&&`/`||`
   chain, or when its source register is still live afterwards (see the matched
   datCalc func_00231ef0: `if (arg1 > 99 && !(*(u16 *)arg0 & 4))` compiles to
   `andi $v1; slti $at,$v1,0x64; bnez $at`). What is NOT reachable is this
   shape: a single bare comparison on a dead call result, where b210 always
   recycles the source register. 359 of the remaining first-party ASM functions
   contain an $at comparison, so the distinction is worth knowing before writing
/* SOLVED by tools/permute.py; this previously carried a `slt $at` floor note
   and sat under #ifdef NON_MATCHING. The permuter found the shape from the
   preserved body. */

/* Source unit: src/promoted/code1_0017.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0017.c; members 00179fc0-0017abd0 */

typedef struct RwV3d { f32 x, y, z; } RwV3d;
struct RwMatrixTag;
typedef struct FldShadowProjectionWork FldShadowProjectionWork;
typedef struct FldShadowAtomicContext {
    void *geometry;
    FldShadowProjectionWork *work;
    void *atomic;
} FldShadowAtomicContext;
enum RwOpCombineType
{
    rwCOMBINEREPLACE = 0,   /**<Replace -
                                all previous transformations are lost */
    rwCOMBINEPRECONCAT,     /**<Pre-concatenation -
                                the given transformation is applied
                                before all others */
    rwCOMBINEPOSTCONCAT,    /**<Post-concatenation -
                                the given transformation is applied
                                after all others */
    rwOPCOMBINETYPEFORCEENUMSIZEINT = 0x7fffffff
};
enum RwPrimitiveType
{
    rwPRIMTYPENAPRIMTYPE = 0,   /**<Invalid primative type */
    rwPRIMTYPELINELIST = 1,     /**<Unconnected line segments, each line is specified by
                                 * both its start and end index, independently of other lines
                                 * (for example, 3 segments specified as 0-1, 2-3, 4-5) */
    rwPRIMTYPEPOLYLINE = 2,     /**<Connected line segments, each line's start index
                                 * (except the first) is specified by the index of the end of
                                 * the previous segment (for example, 3 segments specified as
                                 * 0-1, 1-2, 2-3) */
    rwPRIMTYPETRILIST = 3,      /**<Unconnected triangles: each triangle is specified by
                                 * three indices, independently of other triangles (for example,
                                 * 3 triangles specified as 0-1-2, 3-4-5, 6-7-8) */
    rwPRIMTYPETRISTRIP = 4,     /**<Connected triangles sharing an edge with, at most, one
                                 * other forming a series (for example, 3 triangles specified
                                 * as 0-2-1, 1-2-3-, 2-4-3) */
    rwPRIMTYPETRIFAN = 5 ,      /**<Connected triangles sharing an edge with, at most,
                                 * two others forming a fan (for example, 3 triangles specified
                                 * as 0-2-1, 0-3-2, 0-4-3) */
    rwPRIMTYPEPOINTLIST = 6,    /**<Points 1, 2, 3, etc. This is not
                                 * supported by the default RenderWare
                                 * immediate or retained-mode pipelines
                                 * (except on PlayStation 2), it is intended
                                 * for use by user-created pipelines */
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7fffffff
};
struct _RxObjSpace3DVertex;
/* Retain the source's existing function-scoped propagation setting. */
/* measured: FldShadow_DrawProjection MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00179FC0
s32 FldShadow_DrawProjection(u8 *arg0, s32 arg1, s32 arg2, void *arg3, f32 farg0, f32 farg1, s32 arg4, u8 *arg5) {
    extern struct RwMatrixTag *func_003e0960(struct RwMatrixTag *, const struct RwMatrixTag *);
    extern struct RwMatrixTag *RwMatrixScale(struct RwMatrixTag *, const RwV3d *, enum RwOpCombineType);
    extern struct RwMatrixTag *RwMatrixTranslate(struct RwMatrixTag *, const RwV3d *, enum RwOpCombineType);
    extern s32 FldFrameTask_GetTileX(u8 *);
    extern s32 FldFrameTask_GetTileZ(u8 *);
    extern void *func_00410420(struct _RxObjSpace3DVertex *, u32, struct RwMatrixTag *, u32);
    extern s32 func_004106a0(enum RwPrimitiveType);
    extern s32 func_004104d0(void);
    RwV3d scale;
    RwV3d translation;
    FldShadowAtomicContext ctx;
    u16 ids[8];
    u8 *allocs[8];
    f32 f21;
    u8 *tmp;
    u8 *p;
    s32 v1;
    s32 v2;
    s32 gp_val;
    u8 *alloc;
    void *v;
    FieldRenderStateSetFunction *base;
    s32 outerIndex;
    s32 count;
    tmp = MT_Scene_GetResListHead(0xC);
    base = D_00887300;
    base[0]((RwRenderState)(1), (void *)(arg1));
    base[0]((RwRenderState)(2), (void *)(3));
    base[0]((RwRenderState)(0xC), (void *)(1));
    base[0]((RwRenderState)(9), (void *)(2));
    base[0]((RwRenderState)(0xA), (void *)(5));
    if (farg0 < 0.0f) {
        farg0 = -farg0;
        base[0]((RwRenderState)(0xB), (void *)(5));
    } else {
        base[0]((RwRenderState)(0xB), (void *)(6));
    }
    p = *(u8 **)(arg0 + 4) + 0x10;
    *(RwV3d *)(arg5 + 0x5470) = *(RwV3d *)(p + 0x20);
    f21 = *(f32 *)(arg0 + 0x68);
    func_003e0960((struct RwMatrixTag *)(arg5 + 0x5480), (struct RwMatrixTag *)p);
    scale.y = -0.5f / f21;
    scale.x = scale.y;
    scale.z = 1.0f / (farg1 + f21);
    RwMatrixScale((struct RwMatrixTag *)(arg5 + 0x5480), &scale, rwCOMBINEPOSTCONCAT);
    translation.y = 0.5f;
    translation.x = 0.5f;
    translation.z = 0.0f;
    RwMatrixTranslate((struct RwMatrixTag *)(arg5 + 0x5480), &translation, rwCOMBINEPOSTCONCAT);
    *(s32 *)(arg5 + 0x54C4) = arg4;
    {
        const u8 alpha = (u8)(255.0f * farg0);
        *(u8 *)(arg5 + 0x54C0) = alpha;
    }
    *(s32 *)(arg5 + 0x54C8) = 0;
    *(u32 *)(arg5 + 0x5460) = 0;
    if (arg2 == 0) {
        p = *(u8 **)(tmp + 0x1A0);
        {
            void *preferred = *(void **)(p + 0x10);
            if (preferred != NULL)
                v = preferred;
            else
                v = *(void **)(p + 8);
        }
        func_00394d70(v, arg3, FldShadow_ProjectTriangle, arg5);
    } else if (arg2 == 1) {
        count = 0;
        ctx.geometry = arg3;
        ctx.work = (FldShadowProjectionWork *)arg5;
        if (FldMap_IsCurrentInBandA() == 1) goto alloc_path;
        gp_val = *(s32 *)iGpffff9db0;
        if (gp_val < 0x33) goto check_second;
        if (gp_val <= 0x3A) goto alloc_path;
check_second:
        if (gp_val < 0x47) goto else_path;
        if (gp_val >= 0x4F) goto else_path;
        goto alloc_path;
alloc_path:
        {
            alloc = (u8 *)MT_Scene_GetRes(0x400);
            if (alloc == NULL) {
                return 0;
            }
            v1 = FldFrameTask_GetTileX(*(u8 **)(alloc + 0x220));
            v2 = FldFrameTask_GetTileZ(*(u8 **)(alloc + 0x220));
            v2 = v2 * 0x100;
            v1 = v1 * 0x10;
            ids[0] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + v2 + v1 + 0x56);
            allocs[0] = (u8 *)MT_Scene_GetRes(ids[0]);
            if (allocs[0] != NULL) {
                count++;
            }
            ids[1] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + v2 + v1 + 0x66);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[1];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[1]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            ids[2] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + v2 + v1 + 0x46);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[2];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[2]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            ids[3] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + v2 + v1 + 0x156);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[3];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[3]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            ids[4] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + v2 + v1 - 0xAA);
            {
            s32 i;
            s32 current;
            i = 0;
            current = ids[4];
            for (; i < count; i++) {
                if (current == ids[i]) {
                    break;
                }
            }
            if (i >= count) {
                allocs[count] = (u8 *)MT_Scene_GetRes(ids[4]);
                if (allocs[count] != NULL) {
                    count++;
                }
            }
            }
            goto join_path;
        }
else_path:
        allocs[0] = tmp;
        count++;
join_path:;
        {
            for (outerIndex = 0; outerIndex < count; outerIndex++) {
                u8 **entry = &allocs[outerIndex];
                u8 *object = *entry;
                void *clump = *(void **)(*(u8 **)(object + 0x1A0) + 0x10);
                if (clump != NULL) {
                    RpClumpForAllAtomics(clump, FldShadow_ProjectAtomic, &ctx);
                } else {
                    u32 k;
                    for (k = 0; k < *(u32 *)(*(u8 **)(object + 0x1A0) + 0x18); k++) {
                        RpClumpForAllAtomics(*(void **)(*(u8 **)(*entry + 0x1A0) + k * 4 + 0x1C),
                                             FldShadow_ProjectAtomic, &ctx);
                    }
                }
            }
        }
    }
    *(u32 *)(arg5 + 0x5464) = (*(u32 *)(arg5 + 0x5460) + *(u32 *)(arg5 + 0x54C8) * 600) / 3U;
    if (*(u32 *)(arg5 + 0x5460) != 0) {
        FieldRenderStateSetFunction *drawBase = D_00887300;
        drawBase[0]((RwRenderState)(1), (void *)(arg1));
        drawBase[0]((RwRenderState)(0xE), (void *)(0));
        drawBase[0]((RwRenderState)(6), (void *)(1));
        drawBase[0]((RwRenderState)(8), (void *)(0));
        if (func_00410420((struct _RxObjSpace3DVertex *)arg5, *(u32 *)(arg5 + 0x5460), 0, 0x19) != 0) {
            func_004106a0(rwPRIMTYPETRILIST);
            func_004104d0();
        }
        if (iGpffffba48 == 1) {
            base[0]((RwRenderState)(0xE), (void *)(1));
        }
        *(u32 *)(arg5 + 0x5460) = 0;
    }
    base = D_00887300;
    base[0]((RwRenderState)(0xB), (void *)(6));
    base[0]((RwRenderState)(0xA), (void *)(5));
    return 1;
}

// FUN_0017A700
/* measured: opt_propagation off preserves the second-branch descriptor
   pointer materialisation and grouped float-load order; object matches
   the 464-byte retail window. */
void FldShadow_CmdProjectBounds(u8 *arg0, u8 *arg1)
{
    struct
    {
        f32 values[6];
        s32 type;
    } sp40;
    f32 temp_f1;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f0;
    f32 *temp_3;
    u8 *temp_17;
    u8 *temp_2;

    temp_17 = MT_Scene_GetResListHead(0xC);
    sp40.type = 4;
    temp_f20 = *(f32 *)(arg1 + 0x18);
    sp40.values[0] = temp_f20 +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x30);
    sp40.values[1] = temp_f20 +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x34);
    sp40.values[2] = temp_f20 +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x38);
    sp40.values[3] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x30) - temp_f20;
    sp40.values[4] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x34) - temp_f20;
    sp40.values[5] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(arg1 + 0x10)) + 0x38) - temp_f20;
    if (temp_17 != NULL) {
        if ((*(s32 *)(*(u8 **)(temp_17 + 0x1A0)) & 1) != 0) {
            FldShadow_DrawProjection(*(u8 **)(arg1 + 0x44),
                          *(s32 *)(arg1 + 0x40),
                          0,
                          &sp40,
                          1.0f,
                          *(f32 *)(arg1 + 0x18) / 2.0f,
                          0,
                          *(u8 **)(arg1 + 0x4C));
        } else {
            sp40.type = 3;
            temp_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
            temp_3 = sp40.values;
            temp_f2 = *(f32 *)(temp_2 + 0x30);
            temp_f1 = *(f32 *)(temp_2 + 0x34);
            temp_f0 = *(f32 *)(temp_2 + 0x38);
            sp40.values[0] = temp_f2;
            sp40.values[1] = temp_f1;
            sp40.values[2] = temp_f0;
            temp_f1 = *(f32 *)(arg1 + 0x18);
            sp40.values[3] = temp_f1;
            FldShadow_DrawProjection(*(u8 **)(arg1 + 0x44),
                          *(s32 *)(arg1 + 0x40),
                          1,
                          temp_3,
                          1.0f,
                          temp_f1 / 2.0f,
                          0,
                          *(u8 **)(arg1 + 0x4C));
        }
        if (iGpffffba48 == 1)
            D_00887300[0]((RwRenderState)0xE, (void *)1);
    }
}

// FUN_0017A8D0
void FldShadow_CmdBeginFlip(u8 *arg0, u8 *arg1)
{
    u8 stack[0x6C];
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    s32 temp_2;
    s32 temp_3;
    s32 temp_3_2;
    s32 temp_4;
    s8 *var_3;
    s32 var_2;
    s32 var_4_2;
    u8 *var_6;
    s32 var_5;
    u8 *temp_2_2;
    u8 *temp_3_3;
    u8 *temp_3_4;
    u8 *temp_3_5;
    u8 *var_2_2;
    u8 *var_6_2;
    u8 *var_5_2;
    s32 var_4;

    var_3 = (s8 *)(stack + 0x60);
    var_2 = 0xC;
    if (var_3 != NULL) {
        do {
            *var_3 = 0;
            var_3 += 1;
            var_2 -= 1;
        } while (var_2 != 0);
    }
    var_2_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
    var_6 = arg1 + 0x80;
    var_5 = 8;
    do {
        temp_4 = *(s32 *)(var_2_2 + 0);
        temp_3 = *(s32 *)(var_2_2 + 4);
        var_2_2 += 8;
        var_5 -= 1;
        *(s32 *)(var_6 + 0) = temp_4;
        *(s32 *)(var_6 + 4) = temp_3;
        var_6 += 8;
    } while (var_5 > 0);
    var_6_2 = arg1 + 0x80;
    var_5_2 = stack;
    var_4 = 8;
    do {
        temp_3_2 = *(s32 *)(var_6_2 + 0);
        temp_2 = *(s32 *)(var_6_2 + 4);
        var_6_2 += 8;
        var_4 -= 1;
        *(s32 *)(var_5_2 + 0) = temp_3_2;
        *(s32 *)(var_5_2 + 4) = temp_2;
        var_5_2 += 8;
    } while (var_4 > 0);
    if (!(*(f32 *)(arg1 + 0xCC) <= *(f32 *)(arg1 + 0xD4))) {
        *(s32 *)(stack + 0x50) = 0x3F800000;
        *(s32 *)(stack + 0x54) = 0x3F800000;
        *(s32 *)(stack + 0x58) = 0xBF800000;
        temp_f0 = *(f32 *)(arg1 + 0xC8);
        temp_f1 = temp_f0 + temp_f0;
        temp_f0 = *(f32 *)(stack + 0x38);
        *(f32 *)(stack + 0x38) = temp_f1 - temp_f0;
    } else {
        *(s32 *)(stack + 0x50) = 0xBF800000;
        *(s32 *)(stack + 0x54) = 0x3F800000;
        *(s32 *)(stack + 0x58) = 0x3F800000;
        temp_f0 = *(f32 *)(arg1 + 0xC0);
        temp_f1 = temp_f0 + temp_f0;
        temp_f0 = *(f32 *)(stack + 0x30);
        *(f32 *)(stack + 0x30) = temp_f1 - temp_f0;
    }
    var_4_2 = 0;
    goto loop_11_cond;
loop_11_body:
    temp_3_3 = *(u8 **)(arg1 + 0x10) + (var_4_2 * 0xC);
    *(u8 *)(temp_3_3 + 0x28C) &= ~1;
    var_4_2 += 1;
loop_11_cond:
    if (var_4_2 < 5)
        goto loop_11_body;
    *(s32 *)(*(u8 **)(arg1 + 0x10) + 0xD8) |= 4;
    mdlScale(*(u8 **)(arg1 + 0x10), stack + 0x50, 2);
    temp_2_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
    temp_f1 = *(f32 *)(stack + 0x30);
    temp_f0 = *(f32 *)(stack + 0x34);
    temp_f2 = *(f32 *)(stack + 0x38);
    *(f32 *)(temp_2_2 + 0x30) = temp_f1;
    *(f32 *)(temp_2_2 + 0x34) = temp_f0;
    *(f32 *)(temp_2_2 + 0x38) = temp_f2;
    RwEngineGetMatrixTolerances((f32 *)(stack + 0x40));
    RwMatrixOptimize(mdlGetMatrix(*(u8 **)(arg1 + 0x10)),
                  (f32 *)(stack + 0x40));
    RwMatrixUpdate(mdlGetMatrix(*(u8 **)(arg1 + 0x10)));
    *(s32 *)(*(u8 **)(arg1 + 0x10) + 0xD8) |= 0x40;
    mdlUpdateModelMatrix(*(u8 **)(arg1 + 0x10));
    mdlPrepareItemSlots(*(u8 **)(arg1 + 0x10));
}

// FUN_0017AAE0
void FldShadow_CmdEndFlip(u8 *arg0, u8 *arg1)
{
    u8 *var_5;
    s32 temp_3;
    s32 temp_4_2;
    s32 var_6;
    s32 var_5_2;
    u8 *temp_4;
    u8 *temp_4_3;
    u8 *temp_4_4;
    u8 *var_2;

    temp_4 = *(u8 **)(arg1 + 0x10);
    *(s32 *)(temp_4 + 0xD8) &= ~0x40;
    D_00887300[0]((RwRenderState)0x14, (void *)2);
    var_2 = mdlGetMatrix(*(u8 **)(arg1 + 0x10));
    var_5 = arg1 + 0x80;
    var_5_2 = 8;
    do {
        temp_4_2 = *(s32 *)var_5;
        temp_3 = *(s32 *)(var_5 + 4);
        var_5 += 8;
        var_5_2 -= 1;
        *(s32 *)var_2 = temp_4_2;
        *(s32 *)(var_2 + 4) = temp_3;
        var_2 += 8;
    } while (var_5_2 > 0);
    temp_4_3 = *(u8 **)(arg1 + 0x10);
    *(s32 *)(temp_4_3 + 0xD8) &= ~4;
    mdlUpdateModelMatrix(*(u8 **)(arg1 + 0x10));
    mdlPrepareItemSlots(*(u8 **)(arg1 + 0x10));
    var_5_2 = 0;
    goto loop_4_cond;
loop_4_body:
    temp_4_4 = *(u8 **)(arg1 + 0x10) + (var_5_2 * 0xC);
    *(u8 *)(temp_4_4 + 0x28C) |= 1;
    var_5_2 += 1;
loop_4_cond:
    if (var_5_2 < 5)
        goto loop_4_body;
}

// FUN_0017ABD0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
void FldShadow_CmdRender(u8 *arg0, u8 *arg1)
{
    FieldRenderStateSetFunction *base;
    u8 *temp_4;

    base = D_00887300;
    base[0]((RwRenderState)7, (void *)2);
    base[0]((RwRenderState)6, (void *)1);
    base[0]((RwRenderState)8, (void *)0);
    if (iGpffffba48 == 1) {
        base[0]((RwRenderState)0xE, (void *)1);
    }
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    temp_4 = *(u8 **)(*(u8 **)(arg1 + 0x50) + 4);
    (*(void (**)(u8 *))(temp_4 + 0x48))(temp_4);
    if (iGpffffba48 == 1) {
        base[0]((RwRenderState)0xE, (void *)1);
    }
}


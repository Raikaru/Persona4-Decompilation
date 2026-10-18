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
void FldSmapTileQueueQuad(u8 *value, u8 *other, s32 flags, s32 data, s32 mode,
                    s32 work, s32 count, f32 position, f32 width, f32 height);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern u8 *MT_Scene_GetResListHead(s32 value);

extern void *mdlGetMatrix(void *value);
extern void mdlScale(void *value, void *other, s32 flags);
extern s32 RwEngineGetMatrixTolerances(f32 *value);
extern u8 *RwMatrixOptimize(void *value, f32 *other);
extern u8 *RwMatrixUpdate(void *value);
extern void mdlUpdateModelMatrix(void *value);
extern void mdlPrepareItemSlots(void *value);
extern s32 FldShadow_DrawProjection(u8 *value, s32 other, s32 flags, void *data,
                         f32 factor, f32 distance, s32 mode, u8 *work);
extern u8 D_007EFA00[];
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void FldRc_QueueScreenQuad(u8 *value, u8 *other,
                           f32 flags, f32 data, f32 mode, f32 work, f32 count,
                           void *position, s32 width,
                           f32 height, f32 depth, f32 scale,
                           s32 blend, void *context, f32 opacity);
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

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0017; members 00179fc0-0017abd0 */

#include "rw_types_internal.h"
#include "Kosaka/k_shadow_layout_internal.h"
#include "Kosaka/k_shadow_projection_internal.h"
struct RwMatrixTag;

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
/* Set up projection coordinates, traverse world or atomic collision, and flush the vertex buffer. */
// FUN_00179FC0
/* Layout: caster fields follow FldShadowCaster; the projection buffer follows
 * FldShadowProjectionWork. Typed fields changed this function's instructions in
 * the owning file, so preserve byte accesses and the existing two-word matrix copies. */
s32 FldShadow_DrawProjection(u8 *camera, s32 raster, s32 collisionKind, void *intersection, f32 opacity, f32 depth, s32 fadeWithDepth, u8 *workData) {
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
    FldShadowAtomicContext context;
    u16 ids[8];
    u8 *resources[8];
    f32 viewWindow;
    u8 *sceneResource;
    u8 *source;
    s32 tileXOffset;
    s32 tileZOffset;
    s32 mapId;
    u8 *tileResource;
    void *collisionWorld;
    FieldRenderStateSetFunction *renderStates;
    s32 resourceIndex;
    s32 count;
    sceneResource = MT_Scene_GetResListHead(0xC);
    renderStates = D_00887300;
    renderStates[0]((RwRenderState)(1), (void *)(raster));
    renderStates[0]((RwRenderState)(2), (void *)(3));
    renderStates[0]((RwRenderState)(0xC), (void *)(1));
    renderStates[0]((RwRenderState)(9), (void *)(2));
    renderStates[0]((RwRenderState)(0xA), (void *)(5));
    if (opacity < 0.0f) {
        opacity = -opacity;
        renderStates[0]((RwRenderState)(0xB), (void *)(5));
    } else {
        renderStates[0]((RwRenderState)(0xB), (void *)(6));
    }
    source = *(u8 **)(camera + 4) + 0x10;
    *(RwV3d *)(workData + 0x5470) = *(RwV3d *)(source + 0x20);
    viewWindow = *(f32 *)(camera + 0x68);
    func_003e0960((struct RwMatrixTag *)(workData + 0x5480), (struct RwMatrixTag *)source);
    scale.y = -0.5f / viewWindow;
    scale.x = scale.y;
    scale.z = 1.0f / (depth + viewWindow);
    RwMatrixScale((struct RwMatrixTag *)(workData + 0x5480), &scale, rwCOMBINEPOSTCONCAT);
    translation.y = 0.5f;
    translation.x = 0.5f;
    translation.z = 0.0f;
    RwMatrixTranslate((struct RwMatrixTag *)(workData + 0x5480), &translation, rwCOMBINEPOSTCONCAT);
    *(s32 *)(workData + 0x54C4) = fadeWithDepth;
    {
        const u8 alpha = (u8)(255.0f * opacity);
        *(u8 *)(workData + 0x54C0) = alpha;
    }
    *(s32 *)(workData + 0x54C8) = 0;
    *(u32 *)(workData + 0x5460) = 0;
    if (collisionKind == 0) {
        source = *(u8 **)(sceneResource + 0x1A0);
        {
            void *preferred = *(void **)(source + 0x10);
            if (preferred != NULL)
                collisionWorld = preferred;
            else
                collisionWorld = *(void **)(source + 8);
        }
        func_00394d70(collisionWorld, intersection, FldShadow_ProjectTriangle, workData);
    } else if (collisionKind == 1) {
        count = 0;
        context.geometry = intersection;
        context.work = (FldShadowProjectionWork *)workData;
        if (FldMap_IsCurrentInBandA() == 1) goto alloc_path;
        mapId = *(s32 *)iGpffff9db0;
        if (mapId < 0x33) goto check_second;
        if (mapId <= 0x3A) goto alloc_path;
check_second:
        if (mapId < 0x47) goto else_path;
        if (mapId >= 0x4F) goto else_path;
        goto alloc_path;
alloc_path:
        {
            tileResource = (u8 *)MT_Scene_GetRes(0x400);
            if (tileResource == NULL) {
                return 0;
            }
            tileXOffset = FldFrameTask_GetTileX(*(u8 **)(tileResource + 0x220));
            tileZOffset = FldFrameTask_GetTileZ(*(u8 **)(tileResource + 0x220));
            tileZOffset = tileZOffset * 0x100;
            tileXOffset = tileXOffset * 0x10;
            /* Frame-grid origin/bounds remain unknown; retain the five neighbor
             * ID offsets, with 0x10-column and 0x100-row strides. */
            ids[0] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + 0x56);
            resources[0] = (u8 *)MT_Scene_GetRes(ids[0]);
            if (resources[0] != NULL) {
                count++;
            }
            ids[1] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + 0x66);
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
                resources[count] = (u8 *)MT_Scene_GetRes(ids[1]);
                if (resources[count] != NULL) {
                    count++;
                }
            }
            }
            ids[2] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + 0x46);
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
                resources[count] = (u8 *)MT_Scene_GetRes(ids[2]);
                if (resources[count] != NULL) {
                    count++;
                }
            }
            }
            ids[3] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + 0x156);
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
                resources[count] = (u8 *)MT_Scene_GetRes(ids[3]);
                if (resources[count] != NULL) {
                    count++;
                }
            }
            }
            ids[4] = *(u16 *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset - 0xAA);
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
                resources[count] = (u8 *)MT_Scene_GetRes(ids[4]);
                if (resources[count] != NULL) {
                    count++;
                }
            }
            }
            goto join_path;
        }
else_path:
        resources[0] = sceneResource;
        count++;
join_path:;
        {
            for (resourceIndex = 0; resourceIndex < count; resourceIndex++) {
                u8 **entry = &resources[resourceIndex];
                u8 *object = *entry;
                void *clump = *(void **)(*(u8 **)(object + 0x1A0) + 0x10);
                if (clump != NULL) {
                    RpClumpForAllAtomics(clump, FldShadow_ProjectAtomic, &context);
                } else {
                    u32 k;
                    for (k = 0; k < *(u32 *)(*(u8 **)(object + 0x1A0) + 0x18); k++) {
                        RpClumpForAllAtomics(*(void **)(*(u8 **)(*entry + 0x1A0) + k * 4 + 0x1C),
                                             FldShadow_ProjectAtomic, &context);
                    }
                }
            }
        }
    }
    *(u32 *)(workData + 0x5464) = (*(u32 *)(workData + 0x5460) + *(u32 *)(workData + 0x54C8) * 600) / 3U;
    if (*(u32 *)(workData + 0x5460) != 0) {
        FieldRenderStateSetFunction *drawBase = D_00887300;
        drawBase[0]((RwRenderState)(1), (void *)(raster));
        drawBase[0]((RwRenderState)(0xE), (void *)(0));
        drawBase[0]((RwRenderState)(6), (void *)(1));
        drawBase[0]((RwRenderState)(8), (void *)(0));
        if (func_00410420((struct _RxObjSpace3DVertex *)workData, *(u32 *)(workData + 0x5460), 0, 0x19) != 0) {
            func_004106a0(rwPRIMTYPETRILIST);
            func_004104d0();
        }
        if (iGpffffba48 == 1) {
            renderStates[0]((RwRenderState)(0xE), (void *)(1));
        }
        *(u32 *)(workData + 0x5460) = 0;
    }
    renderStates = D_00887300;
    renderStates[0]((RwRenderState)(0xB), (void *)(6));
    renderStates[0]((RwRenderState)(0xA), (void *)(5));
    return 1;
}

/* Build a box or sphere intersection around the caster model and project its shadow. */
// FUN_0017A700
/* measured: opt_propagation off preserves the second-branch descriptor
   pointer materialisation and grouped float-load order; object matches
   the 464-byte retail window. */
/* Layout: caster fields follow FldShadowCaster; the projection buffer follows
 * FldShadowProjectionWork. Typed fields changed this function's instructions in
 * the owning file, so preserve byte accesses and the existing two-word matrix copies. */
void FldShadow_CmdProjectBounds(u8 *unused, u8 *caster)
{
    struct
    {
        f32 values[6];
        s32 type;
    } intersection;
    f32 componentY;
    f32 extent;
    f32 componentX;
    f32 componentZ;
    f32 *sphereValues;
    u8 *sceneResource;
    u8 *matrix;

    sceneResource = MT_Scene_GetResListHead(0xC);
    intersection.type = 4;
    extent = *(f32 *)(caster + 0x18);
    intersection.values[0] = extent +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x30);
    intersection.values[1] = extent +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x34);
    intersection.values[2] = extent +
                     *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x38);
    intersection.values[3] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x30) - extent;
    intersection.values[4] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x34) - extent;
    intersection.values[5] =
        *(f32 *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x38) - extent;
    if (sceneResource != NULL) {
        if ((*(s32 *)(*(u8 **)(sceneResource + 0x1A0)) & 1) != 0) {
            FldShadow_DrawProjection(*(u8 **)(caster + 0x44),
                          *(s32 *)(caster + 0x40),
                          0,
                          &intersection,
                          1.0f,
                          *(f32 *)(caster + 0x18) / 2.0f,
                          0,
                          *(u8 **)(caster + 0x4C));
        } else {
            intersection.type = 3;
            matrix = mdlGetMatrix(*(u8 **)(caster + 0x10));
            sphereValues = intersection.values;
            componentX = *(f32 *)(matrix + 0x30);
            componentY = *(f32 *)(matrix + 0x34);
            componentZ = *(f32 *)(matrix + 0x38);
            intersection.values[0] = componentX;
            intersection.values[1] = componentY;
            intersection.values[2] = componentZ;
            componentY = *(f32 *)(caster + 0x18);
            intersection.values[3] = componentY;
            FldShadow_DrawProjection(*(u8 **)(caster + 0x44),
                          *(s32 *)(caster + 0x40),
                          1,
                          sphereValues,
                          1.0f,
                          componentY / 2.0f,
                          0,
                          *(u8 **)(caster + 0x4C));
        }
        if (iGpffffba48 == 1)
            D_00887300[0]((RwRenderState)0xE, (void *)1);
    }
}

/* Save the model matrix, reflect it across the configured axis, and disable item-slot drawing. */
// FUN_0017A8D0
/* Layout: caster fields follow FldShadowCaster; the projection buffer follows
 * FldShadowProjectionWork. Typed fields changed this function's instructions in
 * the owning file, so preserve byte accesses and the existing two-word matrix copies. */
void FldShadow_CmdBeginFlip(u8 *unused, u8 *caster)
{
    /* Scratch layout: matrix 0x00, tolerances 0x40, reflection scale 0x50,
     * and the original twelve-byte zeroed tail at 0x60. */
    u8 scratch[0x6C];
    f32 positionZ;
    f32 component;
    f32 coordinate;
    s32 secondCopiedWord;
    s32 secondSavedWord;
    s32 firstCopiedWord;
    s32 firstSavedWord;
    s8 *clearCursor;
    s32 clearBytes;
    s32 slotIndex;
    u8 *savedCursor;
    s32 savePairs;
    u8 *matrix;
    u8 *slot;
    u8 *unusedMatrix;
    u8 *unusedSlot;
    u8 *modelCursor;
    u8 *copyCursor;
    u8 *scratchCursor;
    s32 copyPairs;

    clearCursor = (s8 *)(scratch + 0x60);
    clearBytes = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearBytes -= 1;
        } while (clearBytes != 0);
    }
    modelCursor = mdlGetMatrix(*(u8 **)(caster + 0x10));
    savedCursor = caster + 0x80;
    savePairs = 8;
    do {
        firstSavedWord = *(s32 *)(modelCursor + 0);
        secondSavedWord = *(s32 *)(modelCursor + 4);
        modelCursor += 8;
        savePairs -= 1;
        *(s32 *)(savedCursor + 0) = firstSavedWord;
        *(s32 *)(savedCursor + 4) = secondSavedWord;
        savedCursor += 8;
    } while (savePairs > 0);
    copyCursor = caster + 0x80;
    scratchCursor = scratch;
    copyPairs = 8;
    do {
        firstCopiedWord = *(s32 *)(copyCursor + 0);
        secondCopiedWord = *(s32 *)(copyCursor + 4);
        copyCursor += 8;
        copyPairs -= 1;
        *(s32 *)(scratchCursor + 0) = firstCopiedWord;
        *(s32 *)(scratchCursor + 4) = secondCopiedWord;
        scratchCursor += 8;
    } while (copyPairs > 0);
    if (!(*(f32 *)(caster + 0xCC) <= *(f32 *)(caster + 0xD4))) {
        *(s32 *)(scratch + 0x50) = 0x3F800000;
        *(s32 *)(scratch + 0x54) = 0x3F800000;
        *(s32 *)(scratch + 0x58) = 0xBF800000;
        coordinate = *(f32 *)(caster + 0xC8);
        component = coordinate + coordinate;
        coordinate = *(f32 *)(scratch + 0x38);
        *(f32 *)(scratch + 0x38) = component - coordinate;
    } else {
        *(s32 *)(scratch + 0x50) = 0xBF800000;
        *(s32 *)(scratch + 0x54) = 0x3F800000;
        *(s32 *)(scratch + 0x58) = 0x3F800000;
        coordinate = *(f32 *)(caster + 0xC0);
        component = coordinate + coordinate;
        coordinate = *(f32 *)(scratch + 0x30);
        *(f32 *)(scratch + 0x30) = component - coordinate;
    }
    slotIndex = 0;
    goto loop_11_cond;
loop_11_body:
    slot = *(u8 **)(caster + 0x10) + (slotIndex * 0xC);
    *(u8 *)(slot + 0x28C) &= ~1;
    slotIndex += 1;
loop_11_cond:
    if (slotIndex < 5)
        goto loop_11_body;
    /* Model flag 4 selects the reflected pass; 0x40 requests matrix propagation. */
    *(s32 *)(*(u8 **)(caster + 0x10) + 0xD8) |= 4;
    mdlScale(*(u8 **)(caster + 0x10), scratch + 0x50, 2);
    matrix = mdlGetMatrix(*(u8 **)(caster + 0x10));
    component = *(f32 *)(scratch + 0x30);
    coordinate = *(f32 *)(scratch + 0x34);
    positionZ = *(f32 *)(scratch + 0x38);
    *(f32 *)(matrix + 0x30) = component;
    *(f32 *)(matrix + 0x34) = coordinate;
    *(f32 *)(matrix + 0x38) = positionZ;
    RwEngineGetMatrixTolerances((f32 *)(scratch + 0x40));
    RwMatrixOptimize(mdlGetMatrix(*(u8 **)(caster + 0x10)),
                  (f32 *)(scratch + 0x40));
    RwMatrixUpdate(mdlGetMatrix(*(u8 **)(caster + 0x10)));
    *(s32 *)(*(u8 **)(caster + 0x10) + 0xD8) |= 0x40;
    mdlUpdateModelMatrix(*(u8 **)(caster + 0x10));
    mdlPrepareItemSlots(*(u8 **)(caster + 0x10));
}

/* Restore the saved model matrix and re-enable the five item slots after reflection. */
// FUN_0017AAE0
/* Layout: caster fields follow FldShadowCaster; the projection buffer follows
 * FldShadowProjectionWork. Typed fields changed this function's instructions in
 * the owning file, so preserve byte accesses and the existing two-word matrix copies. */
void FldShadow_CmdEndFlip(u8 *unused, u8 *caster)
{
    u8 *savedCursor;
    s32 secondWord;
    s32 firstWord;
    s32 unusedPairs;
    s32 index;
    u8 *model;
    u8 *restoredModel;
    u8 *slot;
    u8 *matrixCursor;

    model = *(u8 **)(caster + 0x10);
    *(s32 *)(model + 0xD8) &= ~0x40;
    D_00887300[0]((RwRenderState)0x14, (void *)2);
    matrixCursor = mdlGetMatrix(*(u8 **)(caster + 0x10));
    savedCursor = caster + 0x80;
    index = 8;
    do {
        firstWord = *(s32 *)savedCursor;
        secondWord = *(s32 *)(savedCursor + 4);
        savedCursor += 8;
        index -= 1;
        *(s32 *)matrixCursor = firstWord;
        *(s32 *)(matrixCursor + 4) = secondWord;
        matrixCursor += 8;
    } while (index > 0);
    restoredModel = *(u8 **)(caster + 0x10);
    *(s32 *)(restoredModel + 0xD8) &= ~4;
    mdlUpdateModelMatrix(*(u8 **)(caster + 0x10));
    mdlPrepareItemSlots(*(u8 **)(caster + 0x10));
    index = 0;
    goto loop_4_cond;
loop_4_body:
    slot = *(u8 **)(caster + 0x10) + (index * 0xC);
    *(u8 *)(slot + 0x28C) |= 1;
    index += 1;
loop_4_cond:
    if (index < 5)
        goto loop_4_body;
}

/* Render the caster ring atomic with the shadow render-state configuration. */
// FUN_0017ABD0
/* measured: opt_propagation off keeps the cached D_00887300 base in $s0. */
void FldShadow_CmdRender(u8 *unused, u8 *caster)
{
    FieldRenderStateSetFunction *renderStates;
    u8 *atomic;

    renderStates = D_00887300;
    renderStates[0]((RwRenderState)7, (void *)2);
    renderStates[0]((RwRenderState)6, (void *)1);
    renderStates[0]((RwRenderState)8, (void *)0);
    if (iGpffffba48 == 1) {
        renderStates[0]((RwRenderState)0xE, (void *)1);
    }
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    atomic = ((FldShadowRing *)(u8 *)((FldShadowCaster *)caster)->ring)->atomic;
    ((struct RpAtomic *)atomic)->renderCallBack((struct RpAtomic *)atomic);
    if (iGpffffba48 == 1) {
        renderStates[0]((RwRenderState)0xE, (void *)1);
    }
}


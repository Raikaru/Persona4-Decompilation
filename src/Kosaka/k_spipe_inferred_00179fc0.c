#include "member_access.h"
#include "field_frame_internal.h"
#include "resrc_manager_internal.h"
#include "model_battle_internal.h"
#include "Kosaka/k_fldResource_internal.h"
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
/* Cmd_PickEncounter is called unprototyped so its u16 arguments get old-style default promotion,
 * matching retail's masking order. */
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
void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                    s32 height, s32 flags, f32 x, f32 y, f32 depth);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern u8 *MT_Scene_GetResListHead(s32 resourceType);

extern void *mdlGetMatrix(void *model);
extern void mdlScale(void *model, void *scale, s32 combineOp);
extern s32 RwEngineGetMatrixTolerances(f32 *value);
extern u8 *RwMatrixOptimize(void *value, f32 *other);
extern u8 *RwMatrixUpdate(void *value);
extern void mdlUpdateModelMatrix(void *model);
extern void mdlPrepareItemSlots(void *model);
extern s32 FldShadow_DrawProjection(u8 *camera, s32 raster, s32 collisionKind, void *intersection,
                         f32 opacity, f32 depth, s32 fadeWithDepth, u8 *workData);
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


#include "rw_types_internal.h"
#include "Kosaka/k_shadow_layout_internal.h"
#include "Kosaka/k_shadow_projection_internal.h"
struct RwMatrixTag;

typedef struct FldShadowAtomicContext {
    void *geometry;
    FldShadowProjectionWork *work;
    void *atomic;
} FldShadowAtomicContext;
/* Granule of the native matrix-copy loops: eight pairs transfer all 0x40 bytes. */
typedef struct FldShadowWordPair { s32 first, second; } FldShadowWordPair;
typedef struct FldShadowMirrorScratch {
    RwMatrixTag matrix;
    f32 tolerances[3];
    u8 pad4C[4];
    union { RwV3d value; s32 bits[3]; } scale;
    u8 pad5C[4];
    u8 tail[12];
} FldShadowMirrorScratch;
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
/* measured: retail code for FldShadow_DrawProjection is compiled without constant/copy propagation. */
#pragma opt_propagation off
/* Set up projection coordinates, traverse world or atomic collision, and flush the vertex buffer. */
// FUN_00179FC0
/* Typed camera, projection-work, and resource aliases retain callback reloads and the five-cell stencil. */
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
    RwCamera *shadowCamera = (RwCamera *)camera;
    FldShadowProjectionWork *projection = (FldShadowProjectionWork *)workData;
    ResrcRecord *scene;
    RwMatrixTag *sourceMatrix;
    FldResource *field;
    sceneResource = MT_Scene_GetResListHead(0xC);
    scene = (ResrcRecord *)sceneResource;
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
    source = (u8 *)shadowCamera->object.object.parent + 0x10;
    sourceMatrix = (RwMatrixTag *)source;
    projection->tail.direction = sourceMatrix->at;
    viewWindow = shadowCamera->viewWindow[0];
    func_003e0960((struct RwMatrixTag *)(workData + 0x5480), (struct RwMatrixTag *)source);
    scale.y = -0.5f / viewWindow;
    scale.x = scale.y;
    scale.z = 1.0f / (depth + viewWindow);
    RwMatrixScale((struct RwMatrixTag *)(workData + 0x5480), &scale, rwCOMBINEPOSTCONCAT);
    translation.y = 0.5f;
    translation.x = 0.5f;
    translation.z = 0.0f;
    RwMatrixTranslate((struct RwMatrixTag *)(workData + 0x5480), &translation, rwCOMBINEPOSTCONCAT);
    projection->tail.fadeWithDepth = fadeWithDepth;
    {
        const u8 alpha = (u8)(255.0f * opacity);
        projection->tail.alpha = alpha;
    }
    projection->tail.flushCount = 0;
    projection->vertexCount = 0;
    if (collisionKind == 0) {
        source = (u8 *)scene->handle1A0;
        field = (FldResource *)source;
        {
            void *preferred = (void *)field->alternateObject;
            if (preferred != NULL)
                collisionWorld = preferred;
            else
                collisionWorld = (void *)field->primaryObject;
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
            ResrcRecord *tile;
            tileResource = (u8 *)MT_Scene_GetRes(0x400);
            tile = (ResrcRecord *)tileResource;
            if (tileResource == NULL) {
                return 0;
            }
            tileXOffset = FldFrameTask_GetTileX((u8 *)tile->handle220);
            tileZOffset = FldFrameTask_GetTileZ((u8 *)tile->handle220);
            tileZOffset = tileZOffset * 0x100;
            tileXOffset = tileXOffset * 0x10;
            /* Test the center, adjacent columns, and adjacent rows of the 0x10/0x100-stride cell grid. */
            ids[0] = ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + MEMBER_OFFSET(FldFrame, cells[0][0])))->resourceId;
            resources[0] = (u8 *)MT_Scene_GetRes(ids[0]);
            if (resources[0] != NULL) {
                count++;
            }
            ids[1] = ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + MEMBER_OFFSET(FldFrame, cells[0][1])))->resourceId;
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
            ids[2] = ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + MEMBER_OFFSET(FldFrame, cells[0][0]) - sizeof(FldFrameCell)))->resourceId;
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
            ids[3] = ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + MEMBER_OFFSET(FldFrame, cells[1][0])))->resourceId;
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
            ids[4] = ((FldFrameCell *)((u8 *)MT_Scene_GetFrameState() + tileZOffset + tileXOffset + MEMBER_OFFSET(FldFrame, cells[0][0]) - sizeof(((FldFrame *)0)->cells[0])))->resourceId;
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
                ResrcRecord *resource = (ResrcRecord *)object;
                void *clump = (void *)((FldResource *)(u8 *)resource->handle1A0)->alternateObject;
                if (clump != NULL) {
                    RpClumpForAllAtomics(clump, FldShadow_ProjectAtomic, &context);
                } else {
                    u32 k;
                    for (k = 0; k < ((FldResource *)(u8 *)resource->handle1A0)->clumpCount; k++) {
                        RpClumpForAllAtomics((void *)((FldResource *)(u8 *)((ResrcRecord *)*entry)->handle1A0)->clumps[k],
                                             FldShadow_ProjectAtomic, &context);
                    }
                }
            }
        }
    }
    projection->triangleCount = (projection->vertexCount + (u32)projection->tail.flushCount * 600) / 3U;
    if (projection->vertexCount != 0) {
        FieldRenderStateSetFunction *drawBase = D_00887300;
        drawBase[0]((RwRenderState)(1), (void *)(raster));
        drawBase[0]((RwRenderState)(0xE), (void *)(0));
        drawBase[0]((RwRenderState)(6), (void *)(1));
        drawBase[0]((RwRenderState)(8), (void *)(0));
        if (func_00410420((struct _RxObjSpace3DVertex *)workData, projection->vertexCount, 0, 0x19) != 0) {
            func_004106a0(rwPRIMTYPETRILIST);
            func_004104d0();
        }
        if (iGpffffba48 == 1) {
            renderStates[0]((RwRenderState)(0xE), (void *)(1));
        }
        projection->vertexCount = 0;
    }
    renderStates = D_00887300;
    renderStates[0]((RwRenderState)(0xB), (void *)(6));
    renderStates[0]((RwRenderState)(0xA), (void *)(5));
    return 1;
}

/* Build a box or sphere intersection around the caster model and project its shadow. */
// FUN_0017A700
/* The raster argument reads the handle's native signed word, not a converted pointer. */
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
    FldShadowCaster *shadow = (FldShadowCaster *)caster;
    ResrcRecord *scene;
    RwMatrixTag *modelMatrix;

    sceneResource = MT_Scene_GetResListHead(0xC);
    scene = (ResrcRecord *)sceneResource;
    intersection.type = 4;
    extent = shadow->height;
    intersection.values[0] = extent +
                     ((RwMatrixTag *)mdlGetMatrix(shadow->model))->pos.x;
    intersection.values[1] = extent +
                     ((RwMatrixTag *)mdlGetMatrix(shadow->model))->pos.y;
    intersection.values[2] = extent +
                     ((RwMatrixTag *)mdlGetMatrix(shadow->model))->pos.z;
    intersection.values[3] =
        ((RwMatrixTag *)mdlGetMatrix(shadow->model))->pos.x - extent;
    intersection.values[4] =
        ((RwMatrixTag *)mdlGetMatrix(shadow->model))->pos.y - extent;
    intersection.values[5] =
        ((RwMatrixTag *)mdlGetMatrix(shadow->model))->pos.z - extent;
    if (sceneResource != NULL) {
        if ((((FldResource *)(u8 *)scene->handle1A0)->flags & 1) != 0) {
            FldShadow_DrawProjection(shadow->camera,
                          *(s32 *)&shadow->raster,
                          0,
                          &intersection,
                          1.0f,
                          shadow->height / 2.0f,
                          0,
                          shadow->projection);
        } else {
            intersection.type = 3;
            matrix = mdlGetMatrix(shadow->model);
            modelMatrix = (RwMatrixTag *)matrix;
            sphereValues = intersection.values;
            componentX = modelMatrix->pos.x;
            componentY = modelMatrix->pos.y;
            componentZ = modelMatrix->pos.z;
            intersection.values[0] = componentX;
            intersection.values[1] = componentY;
            intersection.values[2] = componentZ;
            componentY = shadow->height;
            intersection.values[3] = componentY;
            FldShadow_DrawProjection(shadow->camera,
                          *(s32 *)&shadow->raster,
                          1,
                          sphereValues,
                          1.0f,
                          componentY / 2.0f,
                          0,
                          shadow->projection);
        }
        if (iGpffffba48 == 1)
            D_00887300[0]((RwRenderState)0xE, (void *)1);
    }
}

/* Save the model matrix, reflect it across the configured axis, and disable item-slot drawing. */
// FUN_0017A8D0
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
    FldShadowWordPair *savedCursor;
    s32 savePairs;
    u8 *matrix;
    MdlWpnSlot *slot;
    u8 *unusedMatrix;
    u8 *unusedSlot;
    FldShadowWordPair *modelCursor;
    FldShadowWordPair *copyCursor;
    FldShadowWordPair *scratchCursor;
    s32 copyPairs;
    FldShadowCaster *shadow = (FldShadowCaster *)caster;
    RwMatrixTag *modelMatrix;

    clearCursor = (s8 *)(scratch + 0x60);
    clearBytes = 0xC;
    if (clearCursor != NULL) {
        do {
            *clearCursor = 0;
            clearCursor += 1;
            clearBytes -= 1;
        } while (clearBytes != 0);
    }
    modelCursor = (FldShadowWordPair *)mdlGetMatrix(shadow->model);
    savedCursor = (FldShadowWordPair *)shadow->savedMatrix;
    savePairs = 8;
    do {
        firstSavedWord = modelCursor->first;
        secondSavedWord = modelCursor->second;
        modelCursor += 1;
        savePairs -= 1;
        savedCursor->first = firstSavedWord;
        savedCursor->second = secondSavedWord;
        savedCursor += 1;
    } while (savePairs > 0);
    copyCursor = (FldShadowWordPair *)shadow->savedMatrix;
    scratchCursor = (FldShadowWordPair *)scratch;
    copyPairs = 8;
    do {
        firstCopiedWord = copyCursor->first;
        secondCopiedWord = copyCursor->second;
        copyCursor += 1;
        copyPairs -= 1;
        scratchCursor->first = firstCopiedWord;
        scratchCursor->second = secondCopiedWord;
        scratchCursor += 1;
    } while (copyPairs > 0);
    if (!(shadow->mirrorAxis.axis.x <= shadow->mirrorAxis.axis.z)) {
        ((FldShadowMirrorScratch *)scratch)->scale.bits[0] = 0x3F800000;
        ((FldShadowMirrorScratch *)scratch)->scale.bits[1] = 0x3F800000;
        ((FldShadowMirrorScratch *)scratch)->scale.bits[2] = 0xBF800000;
        coordinate = shadow->mirrorPoint.z;
        component = coordinate + coordinate;
        coordinate = ((FldShadowMirrorScratch *)scratch)->matrix.pos.z;
        MEMBER(f32, scratch, FldShadowMirrorScratch, matrix.pos.z) = component - coordinate;
    } else {
        ((FldShadowMirrorScratch *)scratch)->scale.bits[0] = 0xBF800000;
        ((FldShadowMirrorScratch *)scratch)->scale.bits[1] = 0x3F800000;
        ((FldShadowMirrorScratch *)scratch)->scale.bits[2] = 0x3F800000;
        coordinate = shadow->mirrorPoint.x;
        component = coordinate + coordinate;
        coordinate = ((FldShadowMirrorScratch *)scratch)->matrix.pos.x;
        MEMBER(f32, scratch, FldShadowMirrorScratch, matrix.pos.x) = component - coordinate;
    }
    slotIndex = 0;
    goto loop_11_cond;
loop_11_body:
    slot = &((Model *)shadow->model)->attachedWpns[slotIndex];
    slot->flags &= ~1;
    slotIndex += 1;
loop_11_cond:
    if (slotIndex < 5)
        goto loop_11_body;
    /* Model flag 4 selects the reflected pass; 0x40 requests matrix propagation. */
    ((Model *)shadow->model)->flags |= 4;
    mdlScale(shadow->model, scratch + 0x50, 2);
    matrix = mdlGetMatrix(shadow->model);
    modelMatrix = (RwMatrixTag *)matrix;
    component = ((FldShadowMirrorScratch *)scratch)->matrix.pos.x;
    coordinate = ((FldShadowMirrorScratch *)scratch)->matrix.pos.y;
    positionZ = ((FldShadowMirrorScratch *)scratch)->matrix.pos.z;
    modelMatrix->pos.x = component;
    modelMatrix->pos.y = coordinate;
    modelMatrix->pos.z = positionZ;
    RwEngineGetMatrixTolerances((f32 *)(scratch + 0x40));
    RwMatrixOptimize(mdlGetMatrix(shadow->model),
                  (f32 *)(scratch + 0x40));
    RwMatrixUpdate(mdlGetMatrix(shadow->model));
    ((Model *)shadow->model)->flags |= 0x40;
    mdlUpdateModelMatrix(shadow->model);
    mdlPrepareItemSlots(shadow->model);
}

/* Restore the saved model matrix and re-enable the five item slots after reflection. */
// FUN_0017AAE0
/* Walk the saved and live matrices with the native two-word copy granule, retaining all eight transfers. */
void FldShadow_CmdEndFlip(u8 *unused, u8 *caster)
{
    FldShadowWordPair *savedCursor;
    s32 secondWord;
    s32 firstWord;
    s32 unusedPairs;
    s32 index;
    u8 *model;
    u8 *restoredModel;
    MdlWpnSlot *slot;
    FldShadowWordPair *matrixCursor;
    FldShadowCaster *shadow = (FldShadowCaster *)caster;
    Model *shadowModel;

    model = shadow->model;
    shadowModel = (Model *)model;
    shadowModel->flags &= ~0x40;
    D_00887300[0]((RwRenderState)0x14, (void *)2);
    matrixCursor = (FldShadowWordPair *)mdlGetMatrix(shadow->model);
    savedCursor = (FldShadowWordPair *)shadow->savedMatrix;
    index = 8;
    do {
        firstWord = savedCursor->first;
        secondWord = savedCursor->second;
        savedCursor += 1;
        index -= 1;
        matrixCursor->first = firstWord;
        matrixCursor->second = secondWord;
        matrixCursor += 1;
    } while (index > 0);
    restoredModel = shadow->model;
    shadowModel = (Model *)restoredModel;
    shadowModel->flags &= ~4;
    mdlUpdateModelMatrix(shadow->model);
    mdlPrepareItemSlots(shadow->model);
    index = 0;
    goto loop_4_cond;
loop_4_body:
    slot = &((Model *)shadow->model)->attachedWpns[index];
    slot->flags |= 1;
    index += 1;
loop_4_cond:
    if (index < 5)
        goto loop_4_body;
}

/* Render the caster ring atomic with the shadow render-state configuration. */
// FUN_0017ABD0
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


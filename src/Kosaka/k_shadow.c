#include "member_access.h"
#include "mt_scene_internal.h"
/* Original translation unit k_shadow.c (from __FILE__ strings). This include/extern prologue is a
 * minimal required set; the full prologue crashes the compiler on FldShadow_CreateCaster. */
#include "sdk_task_registration.h"
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);
extern u8 *MT_Scene_GetResListHead(s32 resourceType);
#include "field_shadow_internal.h"
#include "rw/plcore/barenderstate.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw_types_internal.h"
#include "Kosaka/k_shadow_layout_internal.h"
#include "resrc_manager_internal.h"
#include "primitive_queue_internal.h"
#include "rw_camera_internal.h"
#include "rw_geometry_layout_internal.h"
#include "rw_atomic_layout_internal.h"
#include "rw_frame_internal.h"
#include "rw_texture_internal.h"
#include "model_battle_internal.h"
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
extern u8 D_005F1910[];
extern f32 sinf(f32 value);
extern f32 cosf(f32 value);
extern f32 iGpffff8304;
extern FieldRenderStateSetFunction D_00887300[];
void FldShadow_CmdProjectBounds(u8 *unused, u8 *caster);
void FldShadow_CmdBeginFlip(u8 *unused, u8 *caster);
void FldShadow_CmdEndFlip(u8 *unused, u8 *caster);
void FldShadow_CmdRender(u8 *unused, u8 *caster);
extern void *SceneDraw_GetList4Matrix(void);
extern f32 iGpffff8214;
extern f32 iGpffff826c;
extern f32 iGpffff8360;
extern u32 iGpffff9f4c;
extern u32 iGpffff9f50;
extern u32 iGpffffb308;
extern u32 iGpffffb30c;
extern s32 iGpffffba48;
extern u8 *K_Clump_GetLightA(void);
extern u8 *K_Clump_GetLightB(void);
extern u8 *K_Clump_GetLightC(void);
extern u8 *func_003e9700(u8 *);
extern u8 *func_003e81c0(u8 *, f32);
extern u8 *func_003e8180(u8 *, f32);
typedef struct FldShadowBoundsAccum {
    RwV3d center;
    f32 radius;
    s32 count;
    void *largestAtomic;
} FldShadowBoundsAccum;
/* SpawnCasterTask allocates 0x40 bytes; saved light flags occupy its final words. */
typedef struct FldShadowDrawQueue
{
    s32 state;
    u8 queue[0x30];
    s32 savedLightA;
    s32 savedLightC;
    s32 savedLightB;
} FldShadowDrawQueue;

/* Advance caster setup, then queue the projection or mirrored-model commands. */
// FUN_0017ACC0
s32 FldShadow_StepCasterSetup(u8 *task)
{
    extern s32 mdlPrepareModel(u8 *model);
    extern void *mdlGetClump(void *model);
    extern void mdlSetBattleStateFlag(void *model);
    extern u8 *func_003c4140(void);
    extern struct RpGeometry *func_003c2630(s32 vertices, s32 triangles, u32 format);
    extern const struct RpGeometry *func_003c2130(const struct RpGeometry *geometry,
        struct RpTriangle *triangle, u16 a, u16 b, u16 c);
    extern struct RpGeometry *func_003c2150(struct RpGeometry *geometry,
        struct RpTriangle *triangle, struct RpMaterial *material);
    extern const struct RpMorphTarget *func_003c1d40(const struct RpMorphTarget *morph, RwSphere *sphere);
    extern u8 *func_003c00e0(void);
    extern struct RpAtomic *func_003c0210(struct RpAtomic *atomic, struct RpGeometry *geometry, u32 flags);
    extern s32 func_003c2a80(struct RpGeometry *geometry);
    extern struct RwFrame *func_003e9320(void);
    extern struct RwFrame *func_003e9df0(struct RwFrame *frame);
    extern u8 *PrimAllocQueueNode(void);
    extern void PrimAppendNode(u8 *list, u8 *node);
    extern void mdlQueueModelForDraw(void *queue, u8 *model);
    extern RwRGBA iGpffff9f48;
    extern f32 fGpffff82bc;
    extern u8 D_00794330[];
    u8 *caster;
    u8 *resource;
    s32 flags;
    s32 state;
    FldShadowCaster *shadow;

    caster = (u8 *)((KwlnTask *)task)->work;
    shadow = (FldShadowCaster *)caster;
    resource = ((FldShadowCaster *)caster)->resource;
    /* Resource flag 2 gates shadow work; 0x10000000 additionally gates kind three. */
    flags = (s32)((ResrcRecord *)resource)->unk28;
    if ((flags & 2) == 0)
        return 0;
    if (((((ResrcRecord *)resource)->resTypeId & 0xFFC00) >> 10) == 3 && (flags & 0x10000000) == 0)
        return 0;
    if (((FldShadowCaster *)caster)->disabled == 1)
        return 0;
    state = ((FldShadowCaster *)caster)->state;
    switch (state) {
    case 0:
        switch (((FldShadowCaster *)caster)->mode) {
        case 0:
            ((FldShadowCaster *)caster)->state = state + 1;
            break;
        case 1:
            if (mdlPrepareModel(((FldShadowCaster *)caster)->model) != 0) {
                FldShadowBoundsAccum bounds;

                memset(&bounds, 0, sizeof(bounds));
                RpClumpForAllAtomics(mdlGetClump(shadow->model), FldShadow_AccumulateAtomicBounds, &bounds);
                ((FldShadowCaster *)caster)->largestAtomic = bounds.largestAtomic;
                ((FldShadowCaster *)caster)->height = 90.0f;
                ((FldShadowCaster *)caster)->center = bounds.center;
                ((FldShadowCaster *)caster)->center.x = 0.0f;
                ((FldShadowCaster *)caster)->center.z = 0.0f;
                ((FldShadowCaster *)caster)->radius = bounds.radius;
                ((FldShadowCaster *)caster)->state += 1;
            }
            break;
        case 2:
            if (mdlPrepareModel(((FldShadowCaster *)caster)->model) != 0) {
                mdlSetBattleStateFlag(shadow->model);
                ((FldShadowCaster *)caster)->state += 1;
            }
            break;
        case 4:
        case 3:
            if (mdlPrepareModel(((FldShadowCaster *)caster)->model) != 0) {
                u8 *geometry;
                u8 *triangle;
                s32 triangleIndex;
                f32 angle;
                f32 *vertices;
                f32 height;
                s32 vertexIndex;
                f32 *vertex;
                u8 *colors;
                u8 *morph;
                RwSphere sphere;
                struct RpGeometry *ringGeometry;

                ((FldShadowRing *)((u8 *)((FldShadowCaster *)caster)->ring))->material = func_003c4140();
                ((struct RpMaterial *)(((FldShadowRing *)((u8 *)shadow->ring))->material))->color = iGpffff9f48;
                geometry = (u8 *)func_003c2630(0x22, 0x20, 0x4A);
                ringGeometry = (struct RpGeometry *)geometry;
                triangle = (u8 *)((struct RpGeometry *)geometry)->triangles;
                for (triangleIndex = 0; triangleIndex < 32; triangleIndex++) {
                    func_003c2130((struct RpGeometry *)geometry, (struct RpTriangle *)triangle,
                                 0, (u16)(triangleIndex + 2), (u16)(triangleIndex + 1));
                    func_003c2150((struct RpGeometry *)geometry, (struct RpTriangle *)triangle,
                                 (struct RpMaterial *)((FldShadowRing *)((u8 *)shadow->ring))->material);
                    triangle += 8;
                }
                if (((((FldShadowCaster *)caster)->resourceId & 0xFFC00) >> 10) == 1)
                    height = 5.0f;
                else
                    height = 2.0f;
                vertices = (f32 *)((struct RpMorphTarget *)((u8 *)((struct RpGeometry *)geometry)->morphTarget))->verts;
                angle = 0.0f;
                vertices[0] = 0.0f;
                vertices[1] = height;
                vertices[2] = 0.0f;
                for (vertexIndex = 0; vertexIndex < 32; vertexIndex++) {
                    vertex = (f32 *)((u8 *)vertices + vertexIndex * 12);
                    vertex[3] = ((FldShadowRing *)((f32 *)shadow->ring))->radius * cosf(angle);
                    vertex[4] = height;
                    vertex[5] = ((FldShadowRing *)((f32 *)shadow->ring))->radius * sinf(angle);
                    angle += fGpffff82bc;
                }
                vertices[vertexIndex * 3 + 3] = ((FldShadowRing *)((f32 *)shadow->ring))->radius * cosf(0.0f);
                vertices[vertexIndex * 3 + 4] = height;
                vertices[vertexIndex * 3 + 5] = ((FldShadowRing *)((f32 *)shadow->ring))->radius * sinf(0.0f);
                colors = (u8 *)((struct RpGeometry *)geometry)->preLitLum;
                colors[0] = 0;
                colors[1] = 0;
                colors[2] = 0;
                if (((shadow->resourceId & 0xFFC00) >> 10) == 1 && (shadow->resourceId & 0x3FF) >= 0x64)
                    colors[3] = 255;
                else
                    colors[3] = 150;
                {
                    s32 i;
                    for (i = 0; i < 33; i++) {
                        u8 *color = colors + i * 4;
                        color[4] = 0;
                        color[5] = 0;
                        color[6] = 0;
                        color[7] = 0;
                    }
                }
                func_003c22f0((struct RpGeometry *)geometry);
                morph = (u8 *)ringGeometry->morphTarget;
                func_003c1d40((struct RpMorphTarget *)morph, &sphere);
                ((struct RpMorphTarget *)morph)->boundingSphere = sphere;
                ((FldShadowRing *)((u8 *)shadow->ring))->atomic = func_003c00e0();
                func_003c0210((struct RpAtomic *)((FldShadowRing *)((u8 *)shadow->ring))->atomic, (struct RpGeometry *)geometry, 0);
                func_003c2a80((struct RpGeometry *)geometry);
                RpAtomicSetFrame((struct RpAtomic *)((FldShadowRing *)((u8 *)shadow->ring))->atomic, func_003e9320());
                func_003e9df0(((struct RpAtomic *)(((FldShadowRing *)((u8 *)shadow->ring))->atomic))->frame);
                ((FldShadowCaster *)caster)->state += 1;
            }
            break;
        }
        break;
    case 1:
        switch (((FldShadowCaster *)caster)->mode) {
        case 0:
            break;
        case 1:
            {
                u8 *command = PrimAllocQueueNode();
                ((PrimQueueNode *)command)->callback = (void *)FldShadow_CmdProjectBounds;
                ((PrimQueueDrawNode *)command)->begin.argument.data = caster;
                PrimAppendNode(D_00794330, command);
            }
            break;
        case 2:
            break;
        case 4:
            {
                u8 *command = PrimAllocQueueNode();
                ((PrimQueueNode *)command)->callback = (void *)FldShadow_CmdBeginFlip;
                ((PrimQueueDrawNode *)command)->begin.argument.data = caster;
                PrimAppendNode(D_00794330, command);
                mdlQueueModelForDraw(D_00794330, ((FldShadowCaster *)caster)->model);
                command = PrimAllocQueueNode();
                ((PrimQueueNode *)command)->callback = (void *)FldShadow_CmdEndFlip;
                ((PrimQueueDrawNode *)command)->begin.argument.data = caster;
                PrimAppendNode(D_00794330, command);
            }
            break;
        case 3:
            {
                RwV3d position;
                u8 *command;
                position = ((RwMatrixTag *)((u8 *)mdlGetMatrix(((FldShadowCaster *)caster)->model)))->pos;
                func_003e9c10((u8 *)((struct RpAtomic *)(((FldShadowRing *)((u8 *)((FldShadowCaster *)caster)->ring))->atomic))->frame, &position.x, 0);
                command = PrimAllocQueueNode();
                ((PrimQueueNode *)command)->callback = (void *)FldShadow_CmdRender;
                ((PrimQueueDrawNode *)command)->begin.argument.data = caster;
                PrimAppendNode(D_00794330, command);
            }
            break;
        }
        break;
    case 2:
        return -1;
    }
    return 0;
}
/* Release each mode-specific camera, raster, projection buffer, and ring allocation. */
// FUN_0017B350
void FldShadow_ReleaseCaster(u8 *task)
{
    u8 *camera;
    s32 frame;
    s32 zRaster;
    u16 mode;
    u8 *caster;
    u8 *projection;
    FldShadowCaster *shadow;
    RwCamera *shadowCamera;

    caster = MEMBER(u8 *, task, KwlnTask, work);
    shadow = (FldShadowCaster *)caster;
    mode = ((FldShadowCaster *)caster)->mode;
    switch (mode) {
    case 1:
        func_003cbc60(K_Clump_GetWorld(), ((FldShadowCaster *)caster)->camera);
        camera = shadow->camera;
        shadowCamera = (RwCamera *)camera;
        if (camera != NULL) {
            frame = (s32)((RwCamera *)camera)->object.object.parent;
            if (frame != 0) {
                func_003efd20(camera, 0);
                func_003e9390(frame);
            }
            zRaster = (s32)((RwCamera *)camera)->zBuffer;
            if (zRaster != 0) {
                shadowCamera->zBuffer = NULL;
                func_003ec330(zRaster);
            }
            if ((s32)((RwCamera *)camera)->frameBuffer != 0)
                shadowCamera->frameBuffer = NULL;
            func_003e8440(camera);
        }
        RpSkyTexCacheRasterLock((u8 *)(s32)((FldShadowCaster *)caster)->raster, 0);
        func_003ec330((s32)shadow->raster);
        func_003ef080(((FldShadowCaster *)caster)->texture, 0);
        func_003ef3a0(shadow->texture);
        projection = ((FldShadowCaster *)caster)->projection;
        if (projection != NULL)
            jtbl_008873EC[0](projection);
    case 4:
    case 3:
        break;
    }
    if ((u8 *)((FldShadowCaster *)caster)->ring != NULL) {
        if ((s32)((FldShadowRing *)((u8 *)((FldShadowCaster *)caster)->ring))->material != 0)
            func_003c4220((s32)((FldShadowRing *)((u8 *)((FldShadowCaster *)caster)->ring))->material);
        if (((FldShadowRing *)((u8 *)shadow->ring))->atomic != NULL) {
            func_003e9390((s32)((struct RpAtomic *)(((FldShadowRing *)((u8 *)shadow->ring))->atomic))->frame);
            func_003c02e0(((FldShadowRing *)((u8 *)shadow->ring))->atomic);
        }
        jtbl_008873EC[0]((u8 *)shadow->ring);
    }
    jtbl_008873EC[0]((u8 *)((KwlnTask *)task)->work);
}
extern u8 D_005F18D0[];
extern const u64 D_005F18B0;
extern const f32 D_005F18B8;
extern u8 *func_003ef2e0(void *raster);
extern u8 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003e84a0(void);
extern f32 fabsf(f32 x);
extern s32 FldShadow_StepCasterSetup(u8 *task);

/* measured: retail output needs loop-invariant hoisting on and copy propagation off for this
 * function. */
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Allocate a caster and initialize render-to-texture or ring resources for its mode. */
// FUN_0017B510
/* measured: retail reloads the slot callback pointers each time, and the ring-radius setup goes
 * through a typed caster alias. */
void *FldShadow_CreateCaster(u8 *parentTask, u16 resourceId, u16 requestedMode)
{
    u8 *caster;
    void *task;
    u8 *node;
    s32 resourceIndex;
    u8 **texture;
    u8 *raster;
    u8 *camera;
    u8 *zRaster;
    u8 *resource;
    RwV3d pos;
    void *(**table)(size_t, size_t, u32);
    u16 *mode;
    FldShadowCaster *shadow;

    resourceIndex = 0;
    chkmemAllocSiteTag(D_005F18C0, 0x5E6);
    table = D_008873F4;
    caster = table[0](1, 0xE0, 0x40000);
    shadow = (FldShadowCaster *)caster;
    if (caster == NULL) {
        return NULL;
    }

    task = kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F18D0), 0x10, 0, 0, FldShadow_StepCasterSetup, FldShadow_ReleaseCaster, (u8 *)(caster));
    ((FldShadowCaster *)caster)->resourceId = resourceId;
    mode = &((FldShadowCaster *)caster)->mode;
    *mode = requestedMode;

    for (node = MT_Scene_GetResListHead(0x13); node != NULL; node = (u8 *)((ResrcRecord *)node)->next) {
        if (resourceIndex == 0) {
            f32 x = ((ResrcRecord *)node)->placement[0];
            f32 y = ((ResrcRecord *)node)->placement[1];
            f32 z = ((ResrcRecord *)node)->placement[2];
            ((FldShadowCaster *)caster)->mirrorPoint.x = x;
            ((FldShadowCaster *)caster)->mirrorPoint.y = y;
            ((FldShadowCaster *)caster)->mirrorPoint.z = z;
        }
        if (resourceIndex == 1) {
            if (fabsf(((FldShadowCaster *)caster)->mirrorPoint.x - ((ResrcRecord *)node)->placement[0]) >
                fabsf(((FldShadowCaster *)caster)->mirrorPoint.z - ((ResrcRecord *)node)->placement[2])) {
                ((FldShadowCaster *)caster)->mirrorAxis.bits[0] = 0x3F800000;
                ((FldShadowCaster *)caster)->mirrorAxis.bits[1] = 0;
                ((FldShadowCaster *)caster)->mirrorAxis.bits[2] = 0;
            } else {
                ((FldShadowCaster *)caster)->mirrorAxis.bits[0] = 0;
                ((FldShadowCaster *)caster)->mirrorAxis.bits[1] = 0;
                ((FldShadowCaster *)caster)->mirrorAxis.bits[2] = 0x3F800000;
            }
            *mode = 4;
        }
        resourceIndex++;
    }

    switch (*mode) {
    case 1: {
        u8 **rasterSlot;
        u8 **frameSlot;
        u8 **cameraSlot;

        texture = &((FldShadowCaster *)caster)->texture;
        *texture = func_003ef2e0(NULL);
        if (*texture == NULL) {
            kAssertFail(D_005F18C0, 0x622);
        }
        ((RwTexture *)(((FldShadowCaster *)caster)->texture))->filterAddressing = (((RwTexture *)(((FldShadowCaster *)caster)->texture))->filterAddressing & ~0xFF) | 2;
        ((RwTexture *)(((FldShadowCaster *)caster)->texture))->filterAddressing = (((RwTexture *)(((FldShadowCaster *)caster)->texture))->filterAddressing & 0xFFFF00FF) | 0x3300;

        raster = func_003ec590(128, 128, 32, 0x505);
        if (raster != NULL) {
            RpSkyTexCacheRasterLock(raster, 1);
        }
        rasterSlot = &((FldShadowCaster *)caster)->raster;
        ((FldShadowCaster *)caster)->raster = raster;
        func_003ef080(*texture, raster);

        camera = func_003e84a0();
        if (camera != NULL) {
            u64 positionXY = D_005F18B0;
            f32 positionZ = D_005F18B8;
            *(u64 *)&pos = positionXY;
            pos.z = positionZ;
            func_003efd20(camera, (u8 *)func_003e9320());
            frameSlot = (u8 **)&((RwCamera *)camera)->object.object.parent;
            func_003e9df0((struct RwFrame *)((RwCamera *)(camera))->object.object.parent);
            func_003e9c10(*frameSlot, (const f32 *)&pos, 0);
            if (*frameSlot != NULL) {
                zRaster = func_003ec590(128, 128, 0, 1);
                if (zRaster != NULL) {
                    ((RwCamera *)camera)->zBuffer = (RwRaster *)zRaster;
                    RwCameraSetProjectionType(camera, 2);
                    goto camera_registered;
                }
            }
        }

        FldShadow_DestroyCamera(camera);
        camera = NULL;

camera_registered:
        cameraSlot = &((FldShadowCaster *)caster)->camera;
        ((FldShadowCaster *)caster)->camera = camera;
        {
            s32 world = K_Clump_GetWorld();
            func_003cbc10(world, *cameraSlot);
        }
        ((RwCamera *)*cameraSlot)->frameBuffer = (RwRaster *)*rasterSlot;

        chkmemAllocSiteTag(D_005F18C0, 0x62F);
        ((FldShadowCaster *)caster)->projection = table[0](1, 0x54D0, 0x40000);
        break;
    }

    /* Modes three/four use a 32-segment fan; mode four also mirrors the model. */
    case 4:
    case 3:
        chkmemAllocSiteTag(D_005F18C0, 0x634);
        ((FldShadowCaster *)caster)->ring = (FldShadowRing *)table[0](1, 0xC, 0x40000);
        ((FldShadowRing *)((f32 *)shadow->ring))->radius = 30.0f;
        break;
    }

    if ((((u16)resourceId & 0xFFC00) >> 10) == 1) {
        resource = (u8 *)MT_Scene_GetRes(resourceId);
        ((FldShadowCaster *)caster)->resource = resource;
        if (resource == NULL) {
            kAssertFail(D_005F18C0, 0x63F);
        }
        ((FldShadowCaster *)caster)->model = ((ResrcRecord *)resource)->modelHandle164;
    } else if ((((u16)resourceId & 0xFFC00) >> 10) == 3) {
        resource = (u8 *)MT_Scene_GetRes(resourceId);
        ((FldShadowCaster *)caster)->resource = resource;
        if (resource == NULL) {
            kAssertFail(D_005F18C0, 0x648);
        }
        ((FldShadowCaster *)caster)->model = ((ResrcRecord *)resource)->modelHandle164;
    }

    return task;
}
#pragma opt_propagation on
/* measured: restores the unit setting after the preceding task setup function. */
#pragma opt_loop_invariants off

// FUN_0017B990
void FldShadow_SetCasterFlag(u8 *task, s32 disabled)
{
    ((FldShadowCaster *)((KwlnTask *)task)->work)->disabled = disabled;
}
/* Resize the ring geometry, retaining its closing vertex and mode-dependent height. */
// FUN_0017B9A0
void FldShadow_SetRingParticles(u8 *task, f32 radius)
{
    u8 *state;
    s32 object;
    f32 *particles;
    f32 *entry;
    s32 index;
    f32 angle;
    f32 speed;
    FldShadowCaster *shadow;

    state = (u8 *)((KwlnTask *)task)->work;
    shadow = (FldShadowCaster *)state;
    if ((u8 *)((FldShadowCaster *)state)->ring != NULL) {
        ((FldShadowRing *)((f32 *)((FldShadowCaster *)state)->ring))->radius = radius;
        object = (s32)((FldShadowRing *)((s32)shadow->ring))->atomic;
        if (object != 0) {
            object = (s32)((struct RpAtomic *)object)->geometry;
            RpGeometryLock((u8 *)object, 0xFFF);
            if (((((FldShadowCaster *)state)->resourceId & 0xFFC00) >> 10) == 1)
                speed = 5.0f;
            else
                speed = 2.0f;
            particles = (f32 *)((struct RpMorphTarget *)((s32)((struct RpGeometry *)object)->morphTarget))->verts;
            angle = 0.0f;
            particles[0] = 0.0f;
            particles[1] = speed;
            particles[2] = 0.0f;
            for (index = 0; index < 0x20; index++) {
                entry = (f32 *)((u8 *)particles + index * 0xC);
                entry[3] =
                    ((FldShadowRing *)((s32)shadow->ring))->radius * cosf(angle);
                entry[4] = speed;
                entry[5] =
                    ((FldShadowRing *)((s32)shadow->ring))->radius * sinf(angle);
                angle += iGpffff8304;
            }
            particles[index * 3 + 3] =
                ((FldShadowRing *)((s32)shadow->ring))->radius * cosf(0.0f);
            particles[index * 3 + 4] = speed;
            particles[index * 3 + 5] =
                ((FldShadowRing *)((s32)shadow->ring))->radius * sinf(0.0f);
            func_003c22f0((struct RpGeometry *)object);
        }
    }
}

/* Disable three light flags while preserving their previous values in task work. */
// FUN_0017BB50
void FldShadow_SaveFrameSlots(u8 *unused, u8 *state)
{
    ((FldShadowDrawQueue *)state)->savedLightB = K_Clump_GetLightB()[2];
    K_Clump_GetLightB()[2] = 0;
    K_Clump_GetLightB();
    ((FldShadowDrawQueue *)state)->savedLightC = K_Clump_GetLightC()[2];
    K_Clump_GetLightC()[2] = 0;
    K_Clump_GetLightC();
    ((FldShadowDrawQueue *)state)->savedLightA = K_Clump_GetLightA()[2];
    K_Clump_GetLightA()[2] = 0;
    K_Clump_GetLightA();
}


/* Restore the saved low-byte light flags after the shadow draw queue. */
// FUN_0017BBE0
void FldShadow_RestoreFrameSlots(u8 *unused, u8 *state)
{
    u8 lightFlags;

    lightFlags = (u8)((FldShadowDrawQueue *)state)->savedLightB;
    K_Clump_GetLightB()[2] = lightFlags;
    K_Clump_GetLightB();
    lightFlags = (u8)((FldShadowDrawQueue *)state)->savedLightC;
    K_Clump_GetLightC()[2] = lightFlags;
    K_Clump_GetLightC();
    lightFlags = (u8)((FldShadowDrawQueue *)state)->savedLightA;
    K_Clump_GetLightA()[2] = lightFlags;
    K_Clump_GetLightA();
}

/* Place the scene-resource shadow camera and save the model color before rendering. */
// FUN_0017BC60
void FldShadow_UpdateSceneShadow(u8 *unused, u8 *state)
{
    RwV3d position;
    f32 localTolerance[3];
    f32 sceneTolerance[3];
    f32 viewWindow[2];
    RwV3d translation;
    u8 *data;
    u8 *camera;
    u8 **frameSlot;
    u8 *frame;
    f32 height;
    f32 scaledHeight;
    ResrcRecord *record = (ResrcRecord *)state;

    data = (u8 *)((KwlnTask *)((u8 *)((ResrcRecord *)state)->handle224))->work;
    camera = ((FldShadowCaster *)data)->camera;
    height = ((FldShadowCaster *)data)->height;
    position = ((RwMatrixTag *)((u8 *)mdlGetMatrix(((ResrcRecord *)state)->modelHandle164)))->pos;
    if (((FldShadowCaster *)((u8 *)((KwlnTask *)((u8 *)record->handle224))->work))->state > 0) {
        /* The resource basis is a RenderWare matrix stored in the state at 0x190. */
        if (((ResrcRecord *)state)->unk28 & 0x80000000U) {
            frameSlot = (u8 **)&((RwCamera *)camera)->object.object.parent;
            frame = *frameSlot;
            ((RwFrame *)frame)->modelling.right = ((RwMatrixTag *)(state + 0x190))->right;
            ((RwFrame *)frame)->modelling.up = ((RwMatrixTag *)(state + 0x190))->up;
            ((RwFrame *)frame)->modelling.at = ((RwMatrixTag *)(state + 0x190))->at;
            RwEngineGetMatrixTolerances(localTolerance);
            RwMatrixOptimize(frame + 0x10, localTolerance);
            RwMatrixUpdate(frame + 0x10);
        } else {
            u8 *basis = SceneDraw_GetList4Matrix();
            frameSlot = (u8 **)&((RwCamera *)camera)->object.object.parent;
            frame = *frameSlot;
            ((RwFrame *)frame)->modelling.right = ((RwMatrixTag *)basis)->right;
            ((RwFrame *)frame)->modelling.up = ((RwMatrixTag *)basis)->up;
            ((RwFrame *)frame)->modelling.at = ((RwMatrixTag *)basis)->at;
            RwEngineGetMatrixTolerances(sceneTolerance);
            RwMatrixOptimize(frame + 0x10, sceneTolerance);
            RwMatrixUpdate(frame + 0x10);
        }
        scaledHeight = iGpffff826c * height;
        func_003e81c0(camera, 10.0f * scaledHeight);
        func_003e8180(camera, iGpffff8214 * scaledHeight);
        if (FldMap_IsCurrentInEitherBand() == 1) {
            viewWindow[0] = 2.0f * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        } else {
            viewWindow[0] = iGpffff8360 * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        }
        RwCameraSetViewWindow(camera, viewWindow);
        position.y += height / 2.0f;
        frame = *frameSlot;
        translation.x = -((RwFrame *)frame)->modelling.pos.x;
        translation.y = -((RwFrame *)frame)->modelling.pos.y;
        translation.z = -((RwFrame *)frame)->modelling.pos.z;
        translation.x += position.x;
        translation.y += position.y;
        translation.z += position.z;
        translation.x = (0.0f + translation.x) + ((RwFrame *)frame)->modelling.at.x * (-0.5f * ((RwCamera *)camera)->farPlane);
        translation.y = (0.0f + translation.y) + ((RwFrame *)frame)->modelling.at.y * (-0.5f * ((RwCamera *)camera)->farPlane);
        translation.z = (0.0f + translation.z) + ((RwFrame *)frame)->modelling.at.z * (-0.5f * ((RwCamera *)camera)->farPlane);
        func_003e9c10(frame, (const f32 *)&translation, 2);
        {
            u8 *matrix = func_003e9700(frame);
            func_003e0670(matrix, matrix);
        }
        RwCameraClear(camera, &iGpffffb308, 3);
        if (func_003e8120((u32)camera)) {
            RwRGBA *savedColor = (RwRGBA *)((u8 *)((KwlnTask *)((u8 *)record->handle224))->work + 0x48);
            *savedColor = *(RwRGBA *)mdlGetColor(record->modelHandle164);
            mdlSetColor((u8 *)record->modelHandle164, &iGpffff9f4c);
        } else {
            kAssertFail(D_005F18C0, 0x764);
        }
    }
}
/* Restore scene-model color and finish the camera pass with three gradient strips. */
// FUN_0017C010
void FldShadow_DrawBlobPacket(u8 *packet, s32 stateAddress, void *callbackSelf)
{
    extern u32 K_FldShadow_Draw(f32, f32, f32, f32,
                               const RwRGBA *, const RwRGBA *, f32, f32);
    extern void *mdlGetMatrix(void *);
    extern void mdlSetColor(struct Model *, const RwRGBA *);
    extern u32 func_003e8110(u32 camera);
    extern u8 D_005F18F0[], D_005F18F4[], D_005F18F8[], D_005F18FC[];
    extern f32 D_008872F8[];
    u8 *state = (u8 *)stateAddress;
    void *base;
    u8 *camera;
    void *constant;
    ResrcRecord *record = (ResrcRecord *)state;
    RwCamera *shadowCamera;

    camera = (u8 *)((KwlnTask *)((u8 *)((ResrcRecord *)state)->handle224))->work;
    camera = ((FldShadowCaster *)camera)->camera;
    shadowCamera = (RwCamera *)camera;
    mdlGetMatrix(((ResrcRecord *)state)->modelHandle164);
    if (((FldShadowCaster *)((KwlnTask *)((u8 *)record->handle224))->work)->state > 0) {
        mdlSetColor((struct Model *)record->modelHandle164,
                    (const RwRGBA *)(s32)((u8 *)((KwlnTask *)((u8 *)record->handle224))->work + 0x48));
        base = (void *)D_00887300;
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEFOGENABLE, (void *)0);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEZTESTENABLE, (void *)0);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEZWRITEENABLE, (void *)0);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATESHADEMODE, (void *)2);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATETEXTURERASTER, (void *)0);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        constant = (void *)D_008872F8;
        K_FldShadow_Draw(0.0f, 0.0f, 128.0f, 48.0f,
                         (const RwRGBA *)D_005F18F0, (const RwRGBA *)D_005F18F4,
                         *(f32 *)constant, 1.0f / ((RwCamera *)camera)->nearPlane);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x3C803);
        K_FldShadow_Draw(0.0f, 48.0f, 128.0f, 76.0f,
                         (const RwRGBA *)D_005F18F4, (const RwRGBA *)D_005F18F8,
                         *(f32 *)constant, 1.0f / shadowCamera->nearPlane);
        K_FldShadow_Draw(0.0f, 76.0f, 128.0f, 128.0f,
                         (const RwRGBA *)D_005F18F8, (const RwRGBA *)D_005F18FC,
                         *(f32 *)constant, 1.0f / shadowCamera->nearPlane);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATECULLMODE, (void *)2);
        if (iGpffffba48 == 1)
            (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEFOGENABLE, (void *)1);
        func_003e8110((u32)camera);
    }
}


/* Place the model-resource shadow camera and temporarily disable its five item slots. */
// FUN_0017C270
/* Camera, height and position are snapshotted early, while frame, model and resource-chain pointers
 * are reloaded after callbacks. */
void FldShadow_UpdateModelShadow(u8 *unused, u8 *state)
{
    RwV3d position;
    f32 localTolerance[3];
    f32 sceneTolerance[3];
    f32 viewWindow[2];
    RwV3d translation;
    u8 *data;
    u8 *camera;
    u8 **frameSlot;
    u8 *frame;
    f32 height;
    f32 scaledHeight;
    s32 i;
    ResrcRecord *record = (ResrcRecord *)state;

    data = (u8 *)((KwlnTask *)((u8 *)((ResrcRecord *)state)->handle230))->work;
    camera = ((FldShadowCaster *)data)->camera;
    height = ((FldShadowCaster *)data)->height;
    position = ((RwMatrixTag *)((u8 *)mdlGetMatrix(((ResrcRecord *)state)->modelHandle164)))->pos;
    if (((FldShadowCaster *)((u8 *)((KwlnTask *)((u8 *)record->handle230))->work))->state > 0) {
        /* The resource basis is a RenderWare matrix with interleaved 16-byte axis slots at +0x190. */
        if (((ResrcRecord *)state)->unk28 & 0x80000000U) {
            frameSlot = (u8 **)&((RwCamera *)camera)->object.object.parent;
            frame = *frameSlot;
            ((RwFrame *)frame)->modelling.right = ((RwMatrixTag *)(state + 0x190))->right;
            ((RwFrame *)frame)->modelling.up = ((RwMatrixTag *)(state + 0x190))->up;
            ((RwFrame *)frame)->modelling.at = ((RwMatrixTag *)(state + 0x190))->at;
            RwEngineGetMatrixTolerances(localTolerance);
            RwMatrixOptimize(frame + 0x10, localTolerance);
            RwMatrixUpdate(frame + 0x10);
        } else {
            u8 *basis = SceneDraw_GetList4Matrix();
            frameSlot = (u8 **)&((RwCamera *)camera)->object.object.parent;
            frame = *frameSlot;
            ((RwFrame *)frame)->modelling.right = ((RwMatrixTag *)basis)->right;
            ((RwFrame *)frame)->modelling.up = ((RwMatrixTag *)basis)->up;
            ((RwFrame *)frame)->modelling.at = ((RwMatrixTag *)basis)->at;
            RwEngineGetMatrixTolerances(sceneTolerance);
            RwMatrixOptimize(frame + 0x10, sceneTolerance);
            RwMatrixUpdate(frame + 0x10);
        }
        scaledHeight = iGpffff826c * height;
        func_003e81c0(camera, 10.0f * scaledHeight);
        func_003e8180(camera, iGpffff8214 * scaledHeight);
        if (FldMap_IsCurrentInEitherBand() == 1) {
            viewWindow[0] = 2.0f * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        } else {
            viewWindow[0] = iGpffff8360 * (iGpffff826c * height);
            viewWindow[1] = viewWindow[0];
        }
        RwCameraSetViewWindow(camera, viewWindow);
        position.y += height / 2.0f;
        frame = *frameSlot;
        translation.x = -((RwFrame *)frame)->modelling.pos.x;
        translation.y = -((RwFrame *)frame)->modelling.pos.y;
        translation.z = -((RwFrame *)frame)->modelling.pos.z;
        translation.x += position.x;
        translation.y += position.y;
        translation.z += position.z;
        translation.x = (0.0f + translation.x) + ((RwFrame *)frame)->modelling.at.x * (-0.5f * ((RwCamera *)camera)->farPlane);
        translation.y = (0.0f + translation.y) + ((RwFrame *)frame)->modelling.at.y * (-0.5f * ((RwCamera *)camera)->farPlane);
        translation.z = (0.0f + translation.z) + ((RwFrame *)frame)->modelling.at.z * (-0.5f * ((RwCamera *)camera)->farPlane);
        func_003e9c10(frame, (const f32 *)&translation, 2);
        {
            u8 *matrix = func_003e9700(frame);
            func_003e0670(matrix, matrix);
        }
        RwCameraClear(camera, &iGpffffb30c, 3);
        if (func_003e8120((u32)camera)) {
            RwRGBA *savedColor = (RwRGBA *)((u8 *)((KwlnTask *)((u8 *)record->handle230))->work + 0x48);
            *savedColor = *(RwRGBA *)mdlGetColor(record->modelHandle164);
            mdlSetColor((u8 *)record->modelHandle164, &iGpffff9f50);
            for (i = 0; i < 5; i++) {
                ((Model *)(u8 *)record->modelHandle164)->attachedWpns[i].flags &= ~1;
            }
            ((Model *)((u8 *)record->modelHandle164))->flags |= 4;
        } else {
            kAssertFail(D_005F18C0, 0x7F6);
        }
    }
}

/* Restore model flags, item slots, and color, then finish the shadow camera pass. */
// FUN_0017C670
void FldShadow_DrawBlobModel(u8 *packet, s32 stateAddress, void *callbackSelf)
{
    u8 *state = (u8 *)stateAddress;
    extern void *mdlGetMatrix(void *);
    extern void mdlSetColor(struct Model *, const RwRGBA *);
    extern u32 func_003e8110(u32 camera);
    extern u32 K_FldShadow_Draw(f32, f32, f32, f32,
                               const RwRGBA *, const RwRGBA *, f32, f32);
    extern u8 D_005F1900[];
    extern u8 D_005F1904[];
    extern u8 D_005F1908[];
    extern u8 D_005F190C[];
    extern f32 D_008872F8[];
    void *base;
    u8 *camera;
    void *constant;
    s32 i;
    ResrcRecord *record = (ResrcRecord *)state;
    RwCamera *shadowCamera;

    camera = (u8 *)((KwlnTask *)((u8 *)((ResrcRecord *)state)->handle230))->work;
    camera = ((FldShadowCaster *)camera)->camera;
    shadowCamera = (RwCamera *)camera;
    mdlGetMatrix(((ResrcRecord *)state)->modelHandle164);
    if (((FldShadowCaster *)((KwlnTask *)((u8 *)record->handle230))->work)->state > 0) {
        ((Model *)((u8 *)record->modelHandle164))->flags &= ~4;
        for (i = 0; i < 5; i++)
            ((Model *)(u8 *)record->modelHandle164)->attachedWpns[i].flags |= 1;
        mdlSetColor((struct Model *)record->modelHandle164,
                      (const RwRGBA *)(s32)((u8 *)((KwlnTask *)((u8 *)record->handle230))->work + 0x48));
        base = (void *)D_00887300;
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEFOGENABLE, (void *)0);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEZTESTENABLE, (void *)0);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEZWRITEENABLE, (void *)0);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATESHADEMODE, (void *)2);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATETEXTURERASTER, (void *)0);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        constant = (void *)D_008872F8;
        K_FldShadow_Draw(0.0f, 0.0f, 128.0f, 48.0f,
                         (const RwRGBA *)D_005F1900, (const RwRGBA *)D_005F1904,
                         *(f32 *)constant, 1.0f / ((RwCamera *)camera)->nearPlane);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x3C803);
        K_FldShadow_Draw(0.0f, 48.0f, 128.0f, 76.0f,
                         (const RwRGBA *)D_005F1904, (const RwRGBA *)D_005F1908,
                         *(f32 *)constant, 1.0f / shadowCamera->nearPlane);
        K_FldShadow_Draw(0.0f, 76.0f, 128.0f, 128.0f,
                         (const RwRGBA *)D_005F1908, (const RwRGBA *)D_005F190C,
                         *(f32 *)constant, 1.0f / shadowCamera->nearPlane);
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x717FB);
        (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATECULLMODE, (void *)2);
        if (iGpffffba48 == 1)
            (*(FieldRenderStateSetFunction *)base)(rwRENDERSTATEFOGENABLE, (void *)1);
        func_003e8110((u32)camera);
    }
}


/* Build and flush the shadow command queue for scene and model resource lists. */
// FUN_0017C930
s32 FldShadow_CasterStep(u8 *task)
{
    extern u8 *MT_Scene_GetResListHead(s32);
    extern s32 FldMap_IsCurrentInEitherBand(void);
    extern s32 FldDayEventActive(void);
    extern u8 *PrimAllocQueueNode(void);
    extern void PrimClearNodes(void *, s32);
    extern void PrimAppendNode(void *, void *);
    extern void sdkOtFlushBuckets(void *);
    extern void mdlQueueModelForDraw(void *, void *);
    extern void FldShadow_SaveFrameSlots(u8 *, u8 *);
    extern void FldShadow_RestoreFrameSlots(u8 *);
    extern void FldShadow_DrawBlobPacket(u8 *, s32, void *);

    extern void FldShadow_UpdateModelShadow(u8 *, u8 *);
    extern void FldShadow_DrawBlobModel(u8 *, s32, void *);
    u8 *sceneResources;
    u8 *modelResources;
    u8 *state;
    s32 phase;
    s32 i;
    u8 *command;
    u8 *modelSlot;

    state = (u8 *)((KwlnTask *)task)->work;
    sceneResources = MT_Scene_GetResListHead(1);
    modelResources = MT_Scene_GetResListHead(3);
    phase = ((FldShadowDrawQueue *)state)->state;
    switch (phase) {
    case 0:
        ((FldShadowDrawQueue *)state)->state = phase + 1;
        break;
    case 1: {
        PrimClearNodes(state + 4, 1);
        command = PrimAllocQueueNode();
        ((PrimQueueDrawNode *)command)->begin.callback = (void *)FldShadow_SaveFrameSlots;
        ((PrimQueueDrawNode *)command)->begin.argument.data = state;
        PrimAppendNode(state + 4, command);
        while (sceneResources != NULL) {
            ResrcRecord *sceneResource = (ResrcRecord *)sceneResources;
            if (((s32)((ResrcRecord *)sceneResources)->unk28 & 2) != 0 &&
                ((FldShadowCaster *)((u8 *)((KwlnTask *)((u8 *)((ResrcRecord *)sceneResources)->handle224))->work))->mode == 1) {
                command = PrimAllocQueueNode();
                ((PrimQueueDrawNode *)command)->begin.callback = (void *)FldShadow_UpdateSceneShadow;
                ((PrimQueueDrawNode *)command)->begin.argument.data = sceneResources;
                PrimAppendNode(state + 4, command);
                if (((FldShadowCaster *)((u8 *)((KwlnTask *)((u8 *)sceneResource->handle224))->work))->state > 0) {
                    if (FldMap_IsCurrentInEitherBand() == 1 || FldDayEventActive() == 1) {
                        i = 0;
                        while (i < 5) {
                            modelSlot = (u8 *)&((Model *)((ResrcRecord *)sceneResources)->modelHandle164)->attachedWpns[i];
                            ((MdlWpnSlot *)modelSlot)->flags = ((MdlWpnSlot *)modelSlot)->flags & 0xFE;
                            i += 1;
                        }
                    }
                    ((Model *)((u8 *)((ResrcRecord *)sceneResources)->modelHandle164))->flags = ((Model *)((u8 *)((ResrcRecord *)sceneResources)->modelHandle164))->flags | 4;
                    mdlQueueModelForDraw(state + 4, (u8 *)((ResrcRecord *)sceneResources)->modelHandle164);
                    ((Model *)((u8 *)sceneResource->modelHandle164))->flags = ((Model *)((u8 *)sceneResource->modelHandle164))->flags & ~4;
                    if (FldMap_IsCurrentInEitherBand() == 1 || FldDayEventActive() == 1) {
                        i = 0;
                        while (i < 5) {
                            modelSlot = (u8 *)&((Model *)(u8 *)sceneResource->modelHandle164)->attachedWpns[i];
                            ((MdlWpnSlot *)modelSlot)->flags = ((MdlWpnSlot *)modelSlot)->flags | 1;
                            i += 1;
                        }
                    }
                }
                command = PrimAllocQueueNode();
                ((PrimQueueDrawNode *)command)->begin.endCallback = (void *)FldShadow_DrawBlobPacket;
                ((PrimQueueDrawNode *)command)->endArgument.data = sceneResources;
                PrimAppendNode(state + 4, command);
            }
            sceneResources = (u8 *)((ResrcRecord *)sceneResources)->next;
        }
        while (modelResources != NULL) {
            ResrcRecord *modelResource = (ResrcRecord *)modelResources;
            if (((s32)((ResrcRecord *)modelResources)->unk28 & 2) != 0 &&
                ((FldShadowCaster *)((u8 *)((KwlnTask *)((u8 *)((ResrcRecord *)modelResources)->handle230))->work))->mode == 1) {
                command = PrimAllocQueueNode();
                ((PrimQueueDrawNode *)command)->begin.callback = (void *)FldShadow_UpdateModelShadow;
                ((PrimQueueDrawNode *)command)->begin.argument.data = sceneResources;
                PrimAppendNode(state + 4, command);
                if (((FldShadowCaster *)((u8 *)((KwlnTask *)((u8 *)modelResource->handle230))->work))->state > 0) {
                    mdlQueueModelForDraw(state + 4, (u8 *)((ResrcRecord *)modelResources)->modelHandle164);
                }
                command = PrimAllocQueueNode();
                ((PrimQueueDrawNode *)command)->begin.endCallback = (void *)FldShadow_DrawBlobModel;
                ((PrimQueueDrawNode *)command)->endArgument.data = sceneResources;
                PrimAppendNode(state + 4, command);
            }
            modelResources = (u8 *)((ResrcRecord *)modelResources)->next;
        }
        command = PrimAllocQueueNode();
        ((PrimQueueDrawNode *)command)->begin.endCallback = (void *)FldShadow_RestoreFrameSlots;
        ((PrimQueueDrawNode *)command)->endArgument.data = state;
        PrimAppendNode(state + 4, command);
        sdkOtFlushBuckets(state + 4);
        break;
    }
    case 2:
        return -1;
    default:
        break;
    }
    return 0;
}

// FUN_0017CC90
void FldShadow_CasterDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
/* Allocate the 0x40-byte shadow-queue work and attach its task to the parent. */
// FUN_0017CCC0
s32 FldShadow_SpawnCasterTask(u8 *parentTask) {
    u8 *work;

    chkmemAllocSiteTag(D_005F18C0, 0x8E5);
    work = D_008873F4[0](1, 0x40, 0x40000);
    if (work == NULL) {
        return 0;
    }
    return (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F1910), 8, 0, 0, FldShadow_CasterStep, FldShadow_CasterDestroy, (u8 *)(work));
}


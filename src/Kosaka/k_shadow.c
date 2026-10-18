#include "mt_scene_internal.h"
/* Source unit: "k_shadow.c" (bare __FILE__ string; span 0x0017B510..0x0017CCC0). */
/* Prologue is the minimal set found by delta-debugging the committed code1 prologue
   against the span (measured: all 14 functions MATCH). The full prologue ICEs in
   InterferenceGraph.c line 400 while compiling FldShadow_CreateCaster. The trigger is not
   isolated to one declaration: removing any kept declaration breaks compile or match,
   so the whole minimal set is required. */
#include "sdk_task_registration.h"
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern void (*jtbl_008873EC[])(void *);
extern u8 *MT_Scene_GetResListHead(s32 value);
#include "field_shadow_internal.h"
#include "rw/plcore/barenderstate.h"
#include "Kosaka/k_fldFrame_internal.h"
#include "rw_types_internal.h"
#include "Kosaka/k_shadow_layout_internal.h"
typedef struct RwSphere
{
    RwV3d center;
    f32 radius;
} RwSphere;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
extern u8 D_005F1910[];
extern f32 sinf(f32 value);
extern f32 cosf(f32 value);
extern f32 iGpffff8304;
extern FieldRenderStateSetFunction D_00887300[];
void FldShadow_CmdProjectBounds(u8 *value, u8 *other);
void FldShadow_CmdBeginFlip(u8 *value, u8 *other);
void FldShadow_CmdEndFlip(u8 *value, u8 *other);
void FldShadow_CmdRender(u8 *value, u8 *other);
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
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
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
    extern void PrimAppendNode(u8 *pool, u8 *node);
    extern void mdlQueueModelForDraw(void *pool, u8 *model);
    extern RwRGBA iGpffff9f48;
    extern f32 fGpffff82bc;
    extern u8 D_00794330[];
    u8 *caster;
    u8 *resource;
    s32 flags;
    s32 state;

    caster = *(u8 **)(task + 0x38);
    resource = *(u8 **)(caster + 0xC);
    /* Resource flag 2 gates shadow work; 0x10000000 additionally gates kind three. */
    flags = *(s32 *)(resource + 0x28);
    if ((flags & 2) == 0)
        return 0;
    if (((*(u16 *)resource & 0xFFC00) >> 10) == 3 && (flags & 0x10000000) == 0)
        return 0;
    if (*(s32 *)(caster + 4) == 1)
        return 0;
    state = *(s32 *)caster;
    switch (state) {
    case 0:
        switch (*(u16 *)(caster + 0xA)) {
        case 0:
            *(s32 *)caster = state + 1;
            break;
        case 1:
            if (mdlPrepareModel(*(u8 **)(caster + 0x10)) != 0) {
                FldShadowBoundsAccum bounds;

                memset(&bounds, 0, sizeof(bounds));
                RpClumpForAllAtomics(mdlGetClump(*(u8 **)(caster + 0x10)), FldShadow_AccumulateAtomicBounds, &bounds);
                *(void **)(caster + 0x14) = bounds.largestAtomic;
                *(f32 *)(caster + 0x18) = 90.0f;
                *(RwV3d *)(caster + 0x2C) = bounds.center;
                *(f32 *)(caster + 0x2C) = 0.0f;
                *(f32 *)(caster + 0x34) = 0.0f;
                *(f32 *)(caster + 0x38) = bounds.radius;
                *(s32 *)caster += 1;
            }
            break;
        case 2:
            if (mdlPrepareModel(*(u8 **)(caster + 0x10)) != 0) {
                mdlSetBattleStateFlag(*(u8 **)(caster + 0x10));
                *(s32 *)caster += 1;
            }
            break;
        case 4:
        case 3:
            if (mdlPrepareModel(*(u8 **)(caster + 0x10)) != 0) {
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

                *(u8 **)(*(u8 **)(caster + 0x50) + 8) = func_003c4140();
                *(RwRGBA *)(*(u8 **)(*(u8 **)(caster + 0x50) + 8) + 4) = iGpffff9f48;
                geometry = (u8 *)func_003c2630(0x22, 0x20, 0x4A);
                triangle = *(u8 **)(geometry + 0x2C);
                for (triangleIndex = 0; triangleIndex < 32; triangleIndex++) {
                    func_003c2130((struct RpGeometry *)geometry, (struct RpTriangle *)triangle,
                                 0, (u16)(triangleIndex + 2), (u16)(triangleIndex + 1));
                    func_003c2150((struct RpGeometry *)geometry, (struct RpTriangle *)triangle,
                                 *(struct RpMaterial **)(*(u8 **)(caster + 0x50) + 8));
                    triangle += 8;
                }
                if (((*(u16 *)(caster + 8) & 0xFFC00) >> 10) == 1)
                    height = 5.0f;
                else
                    height = 2.0f;
                vertices = *(f32 **)(*(u8 **)(geometry + 0x5C) + 0x14);
                angle = 0.0f;
                vertices[0] = 0.0f;
                vertices[1] = height;
                vertices[2] = 0.0f;
                for (vertexIndex = 0; vertexIndex < 32; vertexIndex++) {
                    vertex = (f32 *)((u8 *)vertices + vertexIndex * 12);
                    vertex[3] = **(f32 **)(caster + 0x50) * cosf(angle);
                    vertex[4] = height;
                    vertex[5] = **(f32 **)(caster + 0x50) * sinf(angle);
                    angle += fGpffff82bc;
                }
                vertices[vertexIndex * 3 + 3] = **(f32 **)(caster + 0x50) * cosf(0.0f);
                vertices[vertexIndex * 3 + 4] = height;
                vertices[vertexIndex * 3 + 5] = **(f32 **)(caster + 0x50) * sinf(0.0f);
                colors = *(u8 **)(geometry + 0x30);
                colors[0] = 0;
                colors[1] = 0;
                colors[2] = 0;
                if (((*(u16 *)(caster + 8) & 0xFFC00) >> 10) == 1 && (*(u16 *)(caster + 8) & 0x3FF) >= 0x64)
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
                morph = *(u8 **)(geometry + 0x5C);
                func_003c1d40((struct RpMorphTarget *)morph, &sphere);
                *(RwSphere *)(morph + 4) = sphere;
                *(u8 **)(*(u8 **)(caster + 0x50) + 4) = func_003c00e0();
                func_003c0210(*(struct RpAtomic **)(*(u8 **)(caster + 0x50) + 4), (struct RpGeometry *)geometry, 0);
                func_003c2a80((struct RpGeometry *)geometry);
                RpAtomicSetFrame(*(struct RpAtomic **)(*(u8 **)(caster + 0x50) + 4), func_003e9320());
                func_003e9df0(*(struct RwFrame **)(*(u8 **)(*(u8 **)(caster + 0x50) + 4) + 4));
                *(s32 *)caster += 1;
            }
            break;
        }
        break;
    case 1:
        switch (*(u16 *)(caster + 0xA)) {
        case 0:
            break;
        case 1:
            {
                u8 *command = PrimAllocQueueNode();
                *(void (**)(u8 *, u8 *))(command + 8) = FldShadow_CmdProjectBounds;
                *(u8 **)(command + 0x10) = caster;
                PrimAppendNode(D_00794330, command);
            }
            break;
        case 2:
            break;
        case 4:
            {
                u8 *command = PrimAllocQueueNode();
                *(void (**)(u8 *, u8 *))(command + 8) = FldShadow_CmdBeginFlip;
                *(u8 **)(command + 0x10) = caster;
                PrimAppendNode(D_00794330, command);
                mdlQueueModelForDraw(D_00794330, *(u8 **)(caster + 0x10));
                command = PrimAllocQueueNode();
                *(void (**)(u8 *, u8 *))(command + 8) = FldShadow_CmdEndFlip;
                *(u8 **)(command + 0x10) = caster;
                PrimAppendNode(D_00794330, command);
            }
            break;
        case 3:
            {
                RwV3d position;
                u8 *command;
                position = *(RwV3d *)((u8 *)mdlGetMatrix(*(u8 **)(caster + 0x10)) + 0x30);
                func_003e9c10(*(u8 **)(*(u8 **)(*(u8 **)(caster + 0x50) + 4) + 4), &position.x, 0);
                command = PrimAllocQueueNode();
                *(void (**)(u8 *, u8 *))(command + 8) = FldShadow_CmdRender;
                *(u8 **)(command + 0x10) = caster;
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
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
void FldShadow_ReleaseCaster(u8 *task)
{
    u8 *camera;
    s32 frame;
    s32 zRaster;
    u16 mode;
    u8 *caster;
    u8 *projection;

    caster = *(u8 **)(task + 0x38);
    mode = *(u16 *)(caster + 0xA);
    switch (mode) {
    case 1:
        func_003cbc60(K_Clump_GetWorld(), *(u8 **)(caster + 0x44));
        camera = *(u8 **)(caster + 0x44);
        if (camera != NULL) {
            frame = *(s32 *)(camera + 4);
            if (frame != 0) {
                func_003efd20(camera, 0);
                func_003e9390(frame);
            }
            zRaster = *(s32 *)(camera + 0x64);
            if (zRaster != 0) {
                *(s32 *)(camera + 0x64) = 0;
                func_003ec330(zRaster);
            }
            if (*(s32 *)(camera + 0x60) != 0)
                *(s32 *)(camera + 0x60) = 0;
            func_003e8440(camera);
        }
        RpSkyTexCacheRasterLock((u8 *)*(s32 *)(caster + 0x40), 0);
        func_003ec330(*(s32 *)(caster + 0x40));
        func_003ef080(*(u8 **)(caster + 0x3C), 0);
        func_003ef3a0(*(u8 **)(caster + 0x3C));
        projection = *(u8 **)(caster + 0x4C);
        if (projection != NULL)
            jtbl_008873EC[0](projection);
    case 4:
    case 3:
        break;
    }
    if (*(u8 **)(caster + 0x50) != NULL) {
        if (*(s32 *)(*(u8 **)(caster + 0x50) + 8) != 0)
            func_003c4220(*(s32 *)(*(u8 **)(caster + 0x50) + 8));
        if (*(u8 **)(*(u8 **)(caster + 0x50) + 4) != NULL) {
            func_003e9390(*(s32 *)(*(u8 **)(*(u8 **)(caster + 0x50) + 4) + 4));
            func_003c02e0(*(u8 **)(*(u8 **)(caster + 0x50) + 4));
        }
        jtbl_008873EC[0](*(u8 **)(caster + 0x50));
    }
    jtbl_008873EC[0](*(u8 **)(task + 0x38));
}
extern u8 D_005F18D0[];
extern const u64 D_005F18B0;
extern const f32 D_005F18B8;
extern u8 *func_003ef2e0(void *raster);
extern u8 *func_003ec590(s32 width, s32 height, s32 depth, s32 flags);
extern u8 *func_003e84a0(void);
extern f32 fabsf(f32 x);
extern s32 FldShadow_StepCasterSetup(u8 *task);

/* measured: b510 matches only with loop-invariant hoisting on and propagation off (14/14). */
#pragma opt_loop_invariants on
#pragma opt_propagation off
/* Allocate a caster and initialize render-to-texture or ring resources for its mode. */
// FUN_0017B510
/* Measured: 1148 executable bytes, 48 resolved relocations, four zero
   alignment bytes. Slot pointers retain the retail callback reloads. */
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
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

    resourceIndex = 0;
    chkmemAllocSiteTag(D_005F18C0, 0x5E6);
    table = D_008873F4;
    caster = table[0](1, 0xE0, 0x40000);
    if (caster == NULL) {
        return NULL;
    }

    task = kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_005F18D0), 0x10, 0, 0, FldShadow_StepCasterSetup, FldShadow_ReleaseCaster, (u8 *)(caster));
    *(u16 *)(caster + 0x8) = resourceId;
    mode = (u16 *)(caster + 0xA);
    *mode = requestedMode;

    for (node = MT_Scene_GetResListHead(0x13); node != NULL; node = *(u8 **)(node + 0x138)) {
        if (resourceIndex == 0) {
            f32 x = *(f32 *)(node + 0x140);
            f32 y = *(f32 *)(node + 0x144);
            f32 z = *(f32 *)(node + 0x148);
            *(f32 *)(caster + 0xC0) = x;
            *(f32 *)(caster + 0xC4) = y;
            *(f32 *)(caster + 0xC8) = z;
        }
        if (resourceIndex == 1) {
            if (fabsf(*(f32 *)(caster + 0xC0) - *(f32 *)(node + 0x140)) >
                fabsf(*(f32 *)(caster + 0xC8) - *(f32 *)(node + 0x148))) {
                *(u32 *)(caster + 0xCC) = 0x3F800000;
                *(u32 *)(caster + 0xD0) = 0;
                *(u32 *)(caster + 0xD4) = 0;
            } else {
                *(u32 *)(caster + 0xCC) = 0;
                *(u32 *)(caster + 0xD0) = 0;
                *(u32 *)(caster + 0xD4) = 0x3F800000;
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

        texture = (u8 **)(caster + 0x3C);
        *texture = func_003ef2e0(NULL);
        if (*texture == NULL) {
            kAssertFail(D_005F18C0, 0x622);
        }
        *(u32 *)(*(u8 **)(caster + 0x3C) + 0x50) = (*(u32 *)(*(u8 **)(caster + 0x3C) + 0x50) & ~0xFF) | 2;
        *(u32 *)(*(u8 **)(caster + 0x3C) + 0x50) = (*(u32 *)(*(u8 **)(caster + 0x3C) + 0x50) & 0xFFFF00FF) | 0x3300;

        raster = func_003ec590(128, 128, 32, 0x505);
        if (raster != NULL) {
            RpSkyTexCacheRasterLock(raster, 1);
        }
        rasterSlot = (u8 **)(caster + 0x40);
        *(u8 **)(caster + 0x40) = raster;
        func_003ef080(*texture, raster);

        camera = func_003e84a0();
        if (camera != NULL) {
            u64 positionXY = D_005F18B0;
            f32 positionZ = D_005F18B8;
            *(u64 *)&pos = positionXY;
            pos.z = positionZ;
            func_003efd20(camera, (u8 *)func_003e9320());
            frameSlot = (u8 **)(camera + 0x4);
            func_003e9df0(*(struct RwFrame **)(camera + 0x4));
            func_003e9c10(*frameSlot, (const f32 *)&pos, 0);
            if (*frameSlot != NULL) {
                zRaster = func_003ec590(128, 128, 0, 1);
                if (zRaster != NULL) {
                    *(u8 **)(camera + 0x64) = zRaster;
                    RwCameraSetProjectionType(camera, 2);
                    goto camera_registered;
                }
            }
        }

        FldShadow_DestroyCamera(camera);
        camera = NULL;

camera_registered:
        cameraSlot = (u8 **)(caster + 0x44);
        *(u8 **)(caster + 0x44) = camera;
        {
            s32 world = K_Clump_GetWorld();
            func_003cbc10(world, *cameraSlot);
        }
        *(u8 **)(*cameraSlot + 0x60) = *rasterSlot;

        chkmemAllocSiteTag(D_005F18C0, 0x62F);
        *(u8 **)(caster + 0x4C) = table[0](1, 0x54D0, 0x40000);
        break;
    }

    /* Modes three/four use a 32-segment fan; mode four also mirrors the model. */
    case 4:
    case 3:
        chkmemAllocSiteTag(D_005F18C0, 0x634);
        *(f32 **)(caster + 0x50) = (f32 *)table[0](1, 0xC, 0x40000);
        **(f32 **)(caster + 0x50) = 30.0f;
        break;
    }

    if ((((u16)resourceId & 0xFFC00) >> 10) == 1) {
        resource = (u8 *)MT_Scene_GetRes(resourceId);
        *(u8 **)(caster + 0xC) = resource;
        if (resource == NULL) {
            kAssertFail(D_005F18C0, 0x63F);
        }
        *(void **)(caster + 0x10) = *(void **)(resource + 0x164);
    } else if ((((u16)resourceId & 0xFFC00) >> 10) == 3) {
        resource = (u8 *)MT_Scene_GetRes(resourceId);
        *(u8 **)(caster + 0xC) = resource;
        if (resource == NULL) {
            kAssertFail(D_005F18C0, 0x648);
        }
        *(void **)(caster + 0x10) = *(void **)(resource + 0x164);
    }

    return task;
}
/* measured: the span functions after b510 match only with the default schedule restored (14/14). */
#pragma opt_propagation on
/* measured: restore loop-invariant hoisting off after b510 so the following span functions match (14/14). */
#pragma opt_loop_invariants off

// FUN_0017B990
void FldShadow_SetCasterFlag(u8 *task, s32 disabled)
{
    ((FldShadowCaster *)((KwlnTask *)task)->work)->disabled = disabled;
}
/* Resize the ring geometry, retaining its closing vertex and mode-dependent height. */
// FUN_0017B9A0
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
void FldShadow_SetRingParticles(u8 *task, f32 radius)
{
    u8 *state;
    s32 object;
    f32 *particles;
    f32 *entry;
    s32 index;
    f32 angle;
    f32 speed;

    state = *(u8 **)(task + 0x38);
    if (*(u8 **)(state + 0x50) != NULL) {
        **(f32 **)(state + 0x50) = radius;
        object = *(s32 *)(*(s32 *)(state + 0x50) + 4);
        if (object != 0) {
            object = *(s32 *)(object + 0x18);
            RpGeometryLock((u8 *)object, 0xFFF);
            if (((*(u16 *)(state + 8) & 0xFFC00) >> 10) == 1)
                speed = 5.0f;
            else
                speed = 2.0f;
            particles = *(f32 **)(*(s32 *)(object + 0x5C) + 0x14);
            angle = 0.0f;
            particles[0] = 0.0f;
            particles[1] = speed;
            particles[2] = 0.0f;
            for (index = 0; index < 0x20; index++) {
                entry = (f32 *)((u8 *)particles + index * 0xC);
                entry[3] =
                    *(f32 *)(*(s32 *)(state + 0x50)) * cosf(angle);
                entry[4] = speed;
                entry[5] =
                    *(f32 *)(*(s32 *)(state + 0x50)) * sinf(angle);
                angle += iGpffff8304;
            }
            particles[index * 3 + 3] =
                *(f32 *)(*(s32 *)(state + 0x50)) * cosf(0.0f);
            particles[index * 3 + 4] = speed;
            particles[index * 3 + 5] =
                *(f32 *)(*(s32 *)(state + 0x50)) * sinf(0.0f);
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

/*
 * measured: 940/944 bytes, 29 resolved relocations, four zero alignment bytes.
 * Keep the frame-slot reload after camera callbacks, separate matrix-result
 * lifetime, and component-wise scaled increment's operand order.
 */
/* Place the scene-resource shadow camera and save the model color before rendering. */
// FUN_0017BC60
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
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

    data = *(u8 **)(*(u8 **)(state + 0x224) + 0x38);
    camera = *(u8 **)(data + 0x44);
    height = *(f32 *)(data + 0x18);
    position = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(state + 0x164)) + 0x30);
    if (*(s32 *)(*(u8 **)(*(u8 **)(state + 0x224) + 0x38)) > 0) {
        if (*(u32 *)(state + 0x28) & 0x80000000U) {
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(RwV3d *)(frame + 0x10) = *(RwV3d *)(state + 0x190);
            *(RwV3d *)(frame + 0x20) = *(RwV3d *)(state + 0x1A0);
            *(RwV3d *)(frame + 0x30) = *(RwV3d *)(state + 0x1B0);
            RwEngineGetMatrixTolerances(localTolerance);
            RwMatrixOptimize(frame + 0x10, localTolerance);
            RwMatrixUpdate(frame + 0x10);
        } else {
            u8 *basis = SceneDraw_GetList4Matrix();
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(RwV3d *)(frame + 0x10) = *(RwV3d *)(basis + 0);
            *(RwV3d *)(frame + 0x20) = *(RwV3d *)(basis + 0x10);
            *(RwV3d *)(frame + 0x30) = *(RwV3d *)(basis + 0x20);
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
        translation.x = -*(f32 *)(frame + 0x40);
        translation.y = -*(f32 *)(frame + 0x44);
        translation.z = -*(f32 *)(frame + 0x48);
        translation.x += position.x;
        translation.y += position.y;
        translation.z += position.z;
        translation.x = (0.0f + translation.x) + *(f32 *)(frame + 0x30) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.y = (0.0f + translation.y) + *(f32 *)(frame + 0x34) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.z = (0.0f + translation.z) + *(f32 *)(frame + 0x38) * (-0.5f * *(f32 *)(camera + 0x84));
        func_003e9c10(frame, (const f32 *)&translation, 2);
        {
            u8 *matrix = func_003e9700(frame);
            func_003e0670(matrix, matrix);
        }
        RwCameraClear(camera, &iGpffffb308, 3);
        if (func_003e8120((u32)camera)) {
            RwRGBA *savedColor = (RwRGBA *)(*(u8 **)(*(u8 **)(state + 0x224) + 0x38) + 0x48);
            *savedColor = *(RwRGBA *)mdlGetColor(*(void **)(state + 0x164));
            mdlSetColor(*(u8 **)(state + 0x164), &iGpffff9f4c);
        } else {
            kAssertFail(D_005F18C0, 0x764);
        }
    }
}
/* Restore scene-model color and finish the camera pass with three gradient strips. */
// FUN_0017C010
/* measured: 608/608 bytes and 29 resolved relocations. The shared draw
   signature preserves both packet-end callbacks and the real provider. */
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
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

    camera = *(u8 **)(*(u8 **)(state + 0x224) + 0x38);
    camera = *(u8 **)(camera + 0x44);
    mdlGetMatrix(*(void **)(state + 0x164));
    if (*(s32 *)*(u8 **)(*(u8 **)(state + 0x224) + 0x38) > 0) {
        mdlSetColor(*(struct Model **)(state + 0x164),
                    (const RwRGBA *)(s32)(*(u8 **)(*(u8 **)(state + 0x224) + 0x38) + 0x48));
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
                         *(f32 *)constant, 1.0f / *(f32 *)(camera + 0x80));
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x3C803);
        K_FldShadow_Draw(0.0f, 48.0f, 128.0f, 76.0f,
                         (const RwRGBA *)D_005F18F4, (const RwRGBA *)D_005F18F8,
                         *(f32 *)constant, 1.0f / *(f32 *)(camera + 0x80));
        K_FldShadow_Draw(0.0f, 76.0f, 128.0f, 128.0f,
                         (const RwRGBA *)D_005F18F8, (const RwRGBA *)D_005F18FC,
                         *(f32 *)constant, 1.0f / *(f32 *)(camera + 0x80));
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
/* measured: 1016/1024 bytes; 29 independently resolved relocations and eight
   zero alignment bytes. Preserve the early camera/height/position snapshots
   and the later frame, model and resource-chain reloads across callbacks. */
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
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

    data = *(u8 **)(*(u8 **)(state + 0x230) + 0x38);
    camera = *(u8 **)(data + 0x44);
    height = *(f32 *)(data + 0x18);
    position = *(RwV3d *)((u8 *)mdlGetMatrix(*(void **)(state + 0x164)) + 0x30);
    if (*(s32 *)(*(u8 **)(*(u8 **)(state + 0x230) + 0x38)) > 0) {
        if (*(u32 *)(state + 0x28) & 0x80000000U) {
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(RwV3d *)(frame + 0x10) = *(RwV3d *)(state + 0x190);
            *(RwV3d *)(frame + 0x20) = *(RwV3d *)(state + 0x1A0);
            *(RwV3d *)(frame + 0x30) = *(RwV3d *)(state + 0x1B0);
            RwEngineGetMatrixTolerances(localTolerance);
            RwMatrixOptimize(frame + 0x10, localTolerance);
            RwMatrixUpdate(frame + 0x10);
        } else {
            u8 *basis = SceneDraw_GetList4Matrix();
            frameSlot = (u8 **)(camera + 4);
            frame = *frameSlot;
            *(RwV3d *)(frame + 0x10) = *(RwV3d *)(basis + 0);
            *(RwV3d *)(frame + 0x20) = *(RwV3d *)(basis + 0x10);
            *(RwV3d *)(frame + 0x30) = *(RwV3d *)(basis + 0x20);
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
        translation.x = -*(f32 *)(frame + 0x40);
        translation.y = -*(f32 *)(frame + 0x44);
        translation.z = -*(f32 *)(frame + 0x48);
        translation.x += position.x;
        translation.y += position.y;
        translation.z += position.z;
        translation.x = (0.0f + translation.x) + *(f32 *)(frame + 0x30) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.y = (0.0f + translation.y) + *(f32 *)(frame + 0x34) * (-0.5f * *(f32 *)(camera + 0x84));
        translation.z = (0.0f + translation.z) + *(f32 *)(frame + 0x38) * (-0.5f * *(f32 *)(camera + 0x84));
        func_003e9c10(frame, (const f32 *)&translation, 2);
        {
            u8 *matrix = func_003e9700(frame);
            func_003e0670(matrix, matrix);
        }
        RwCameraClear(camera, &iGpffffb30c, 3);
        if (func_003e8120((u32)camera)) {
            RwRGBA *savedColor = (RwRGBA *)(*(u8 **)(*(u8 **)(state + 0x230) + 0x38) + 0x48);
            *savedColor = *(RwRGBA *)mdlGetColor(*(void **)(state + 0x164));
            mdlSetColor(*(u8 **)(state + 0x164), &iGpffff9f50);
            for (i = 0; i < 5; i++) {
                *(u8 *)(*(u8 **)(state + 0x164) + i * 0xC + 0x28C) &= ~1;
            }
            *(s32 *)(*(u8 **)(state + 0x164) + 0xD8) |= 4;
        } else {
            kAssertFail(D_005F18C0, 0x7F6);
        }
    }
}

/* Restore model flags, item slots, and color, then finish the shadow camera pass. */
// FUN_0017C670
/* Layout: task work is at 0x38; caster fields follow FldShadowCaster.
 * Measured typed rewrite changed this function's instructions; retain byte accesses
 * and callback reloads to preserve the whole-file match. */
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

    camera = *(u8 **)(*(u8 **)(state + 0x230) + 0x38);
    camera = *(u8 **)(camera + 0x44);
    mdlGetMatrix(*(void **)(state + 0x164));
    if (*(s32 *)*(u8 **)(*(u8 **)(state + 0x230) + 0x38) > 0) {
        *(s32 *)(*(u8 **)(state + 0x164) + 0xD8) &= ~4;
        for (i = 0; i < 5; i++)
            *(u8 *)(*(u8 **)(state + 0x164) + i * 0xC + 0x28C) |= 1;
        mdlSetColor(*(struct Model **)(state + 0x164),
                      (const RwRGBA *)(s32)(*(u8 **)(*(u8 **)(state + 0x230) + 0x38) + 0x48));
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
                         *(f32 *)constant, 1.0f / *(f32 *)(camera + 0x80));
        RpSkyRenderStateSet(2, (void *)0x44);
        RpSkyRenderStateSet(3, (void *)0x3C803);
        K_FldShadow_Draw(0.0f, 48.0f, 128.0f, 76.0f,
                         (const RwRGBA *)D_005F1904, (const RwRGBA *)D_005F1908,
                         *(f32 *)constant, 1.0f / *(f32 *)(camera + 0x80));
        K_FldShadow_Draw(0.0f, 76.0f, 128.0f, 128.0f,
                         (const RwRGBA *)D_005F1908, (const RwRGBA *)D_005F190C,
                         *(f32 *)constant, 1.0f / *(f32 *)(camera + 0x80));
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
/* Layout: the 0x40-byte queue work stores light flags at 0x34/0x38/0x3c;
 * resource links are at 0x138, model at 0x164, caster tasks at 0x224/0x230.
 * Measured typed rewrite changed instructions, so retain these byte accesses. */
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

    state = *(u8 **)(task + 0x38);
    sceneResources = MT_Scene_GetResListHead(1);
    modelResources = MT_Scene_GetResListHead(3);
    phase = *(s32 *)state;
    switch (phase) {
    case 0:
        *(s32 *)state = phase + 1;
        break;
    case 1: {
        PrimClearNodes(state + 4, 1);
        command = PrimAllocQueueNode();
        *(void **)(command + 8) = (void *)FldShadow_SaveFrameSlots;
        *(u8 **)(command + 0x10) = state;
        PrimAppendNode(state + 4, command);
        while (sceneResources != NULL) {
            if ((*(s32 *)(sceneResources + 0x28) & 2) != 0 &&
                *(u16 *)(*(u8 **)(*(u8 **)(sceneResources + 0x224) + 0x38) + 0xA) == 1) {
                command = PrimAllocQueueNode();
                *(void **)(command + 8) = (void *)FldShadow_UpdateSceneShadow;
                *(u8 **)(command + 0x10) = sceneResources;
                PrimAppendNode(state + 4, command);
                if (*(s32 *)(*(u8 **)(*(u8 **)(sceneResources + 0x224) + 0x38)) > 0) {
                    if (FldMap_IsCurrentInEitherBand() == 1 || FldDayEventActive() == 1) {
                        i = 0;
                        while (i < 5) {
                            modelSlot = *(u8 **)(sceneResources + 0x164) + i * 0xC;
                            *(u8 *)(modelSlot + 0x28C) = *(u8 *)(modelSlot + 0x28C) & 0xFE;
                            i += 1;
                        }
                    }
                    *(s32 *)(*(u8 **)(sceneResources + 0x164) + 0xD8) = *(s32 *)(*(u8 **)(sceneResources + 0x164) + 0xD8) | 4;
                    mdlQueueModelForDraw(state + 4, *(u8 **)(sceneResources + 0x164));
                    *(s32 *)(*(u8 **)(sceneResources + 0x164) + 0xD8) = *(s32 *)(*(u8 **)(sceneResources + 0x164) + 0xD8) & ~4;
                    if (FldMap_IsCurrentInEitherBand() == 1 || FldDayEventActive() == 1) {
                        i = 0;
                        while (i < 5) {
                            modelSlot = *(u8 **)(sceneResources + 0x164) + i * 0xC;
                            *(u8 *)(modelSlot + 0x28C) = *(u8 *)(modelSlot + 0x28C) | 1;
                            i += 1;
                        }
                    }
                }
                command = PrimAllocQueueNode();
                *(void **)(command + 0xC) = (void *)FldShadow_DrawBlobPacket;
                *(u8 **)(command + 0x14) = sceneResources;
                PrimAppendNode(state + 4, command);
            }
            sceneResources = *(u8 **)(sceneResources + 0x138);
        }
        while (modelResources != NULL) {
            if ((*(s32 *)(modelResources + 0x28) & 2) != 0 &&
                *(u16 *)(*(u8 **)(*(u8 **)(modelResources + 0x230) + 0x38) + 0xA) == 1) {
                command = PrimAllocQueueNode();
                *(void **)(command + 8) = (void *)FldShadow_UpdateModelShadow;
                *(u8 **)(command + 0x10) = sceneResources;
                PrimAppendNode(state + 4, command);
                if (*(s32 *)(*(u8 **)(*(u8 **)(modelResources + 0x230) + 0x38)) > 0) {
                    mdlQueueModelForDraw(state + 4, *(u8 **)(modelResources + 0x164));
                }
                command = PrimAllocQueueNode();
                *(void **)(command + 0xC) = (void *)FldShadow_DrawBlobModel;
                *(u8 **)(command + 0x14) = sceneResources;
                PrimAppendNode(state + 4, command);
            }
            modelResources = *(u8 **)(modelResources + 0x138);
        }
        command = PrimAllocQueueNode();
        *(void **)(command + 0xC) = (void *)FldShadow_RestoreFrameSlots;
        *(u8 **)(command + 0x14) = state;
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


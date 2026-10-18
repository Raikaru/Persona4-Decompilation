/* Source unit: src/Kosaka/k_spipe_00178c20.c */
#include "include_asm.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_collision_internal.h"

typedef struct RwV3d RwV3d;
struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
};

typedef struct RwRGBA RwRGBA;
struct RwRGBA
{
    u8 r;
    u8 g;
    u8 b;
    u8 a;
};

typedef struct RwRGBAReal RwRGBAReal;
struct RwRGBAReal
{
    f32 r;
    f32 g;
    f32 b;
    f32 a;
};

typedef struct RwSky2DVertexFields RwSky2DVertexFields;
struct RwSky2DVertexFields
{
    RwV3d scrVertex;     // 0x00
    f32 camVertex_z;     // 0x0c
    f32 u;               // 0x10
    f32 v;               // 0x14
    f32 recipZ;          // 0x18
    f32 pad1;            // 0x1c
    RwRGBAReal color;    // 0x20
    RwV3d objNormal;     // 0x30
    f32 pad2;            // 0x3c
};

typedef union RwSky2DVertexStorage RwSky2DVertexStorage;
union RwSky2DVertexStorage
{
    RwSky2DVertexFields els;
    u64 qWords[8];
};

typedef struct RwSky2DVertex RwSky2DVertex;
struct RwSky2DVertex
{
    RwSky2DVertexStorage u; // 0x00
};

typedef RwSky2DVertex RwIm2DVertex;

/* rwGlobals.device.fpIm2DRenderPrimitive lives at 0x00887310 in P4 retail. */
#define RwIm2DRenderPrimitive(primType, vertices, numVertices) \
    (*(s32 (**)(s32, void*, s32))0x00887310)((primType), (vertices), (numVertices))


typedef struct RwObject RwObject;
struct RwObject
{
    u8 type;         // 0x00
    u8 subType;      // 0x01
    u8 flags;        // 0x02
    u8 privateFlags; // 0x03
    void* parent;    // 0x04
};

typedef struct RwLLLink RwLLLink;
struct RwLLLink
{
    void* next; // 0x00
    void* prev; // 0x04
};

typedef struct RwObjectHasFrame RwObjectHasFrame;
struct RwObjectHasFrame
{
    RwObject object; // 0x00
    RwLLLink lFrame; // 0x08
    void* sync;      // 0x10
};

typedef struct RwFrame RwFrame;
typedef struct RwRaster RwRaster;

typedef struct RwCamera RwCamera;
struct RwCamera
{
    RwObjectHasFrame object;   // 0x00
    void* projType;            // 0x14
    void* beginUpdate;         // 0x18
    void* endUpdate;           // 0x1c
    u8 viewMatrix[0x40];       // 0x20
    RwRaster* frameBuffer;     // 0x60
    RwRaster* zBuffer;         // 0x64
    void* viewWindow;          // 0x68
    void* recipViewWindow;     // 0x70
    void* viewOffset;          // 0x78
    f32 nearPlane;             // 0x80
    f32 farPlane;              // 0x84
    f32 fogPlane;              // 0x88
    f32 zScale;                // 0x8c
    f32 zShift;                // 0x90
    void* frustumPlanes;       // 0x94
};

extern void* func_003efd20(RwCamera* camera, RwFrame* frame);
extern void* func_003e9390(void* frame);
extern void* func_003ec330(void* raster);
extern void* func_003e8440(void* camera);

typedef struct RwSphere RwSphere;
struct RwSphere
{
    RwV3d center; // 0x00
    f32 radius;   // 0x0c
};

typedef struct FldShadowBoundsAccum
{
    RwV3d center;          // 0x00
    f32 radius;            // 0x0c
    s32 count;             // 0x10
    void* largestAtomic;   // 0x14
} FldShadowBoundsAccum;

extern RwSphere* func_003bfae0(void* atomic);

#include "Kosaka/k_shadow_projection_internal.h"

typedef struct FldShadowAtomicContext
{
    struct RpIntersection* intersection; // 0x00
    FldShadowProjectionWork* work;        // 0x04
    struct RpAtomic* atomic;             // 0x08
} FldShadowAtomicContext;



/* RenderWare immediate-mode interfaces used by both projection callbacks. */
struct RwMatrixTag;
struct _RxObjSpace3DVertex;
enum RwPrimitiveType {
    rwPRIMTYPENAPRIMTYPE = 0,
    rwPRIMTYPELINELIST = 1,
    rwPRIMTYPEPOLYLINE = 2,
    rwPRIMTYPETRILIST = 3,
    rwPRIMTYPETRISTRIP = 4,
    rwPRIMTYPETRIFAN = 5,
    rwPRIMTYPEPOINTLIST = 6,
    rwPRIMITIVETYPEFORCEENUMSIZEINT = 0x7fffffff
};
extern RwV3d *func_003e42e0(RwV3d *projected, const RwV3d *positions,
                           s32 count, const struct RwMatrixTag *matrix);
extern struct RwMatrixTag *func_003e9700(RwFrame *frame);
extern void *func_00410420(struct _RxObjSpace3DVertex *vertices, u32 count,
                          struct RwMatrixTag *matrix, u32 flags);
extern s32 func_004106a0(enum RwPrimitiveType primitive);
extern s32 func_004104d0(void);

/* Draw a four-vertex screen strip with independent top and bottom colors. */
// FUN_00178C20
u32 K_FldShadow_Draw(f32 xLeft, f32 yTop,
                  f32 xRight, f32 yBot,
                  const RwRGBA* topColor, const RwRGBA* botColor,
                  f32 zBufferNear, f32 recipZ)
{
    RwIm2DVertex vertices[4];

    vertices[0].u.els.scrVertex.x = xLeft;
    vertices[0].u.els.scrVertex.y = yTop;
    vertices[0].u.els.scrVertex.z = zBufferNear;
    vertices[0].u.els.color.r = topColor->r;
    vertices[0].u.els.color.g = topColor->g;
    vertices[0].u.els.color.b = topColor->b;
    vertices[0].u.els.color.a = topColor->a;
    vertices[0].u.els.recipZ = recipZ;

    vertices[1].u.els.scrVertex.x = xLeft;
    vertices[1].u.els.scrVertex.y = yBot;
    vertices[1].u.els.scrVertex.z = zBufferNear;
    vertices[1].u.els.color.r = botColor->r;
    vertices[1].u.els.color.g = botColor->g;
    vertices[1].u.els.color.b = botColor->b;
    vertices[1].u.els.color.a = botColor->a;
    vertices[1].u.els.recipZ = recipZ;

    vertices[2].u.els.scrVertex.x = xRight;
    vertices[2].u.els.scrVertex.y = yTop;
    vertices[2].u.els.scrVertex.z = zBufferNear;
    vertices[2].u.els.color.r = topColor->r;
    vertices[2].u.els.color.g = topColor->g;
    vertices[2].u.els.color.b = topColor->b;
    vertices[2].u.els.color.a = topColor->a;
    vertices[2].u.els.recipZ = recipZ;

    vertices[3].u.els.scrVertex.x = xRight;
    vertices[3].u.els.scrVertex.y = yBot;
    vertices[3].u.els.scrVertex.z = zBufferNear;
    vertices[3].u.els.color.r = botColor->r;
    vertices[3].u.els.color.g = botColor->g;
    vertices[3].u.els.color.b = botColor->b;
    vertices[3].u.els.color.a = botColor->a;
    vertices[3].u.els.recipZ = recipZ;

    RwIm2DRenderPrimitive(4, vertices, 4);

    return 1;
}



/* Detach and destroy the camera frame and Z raster, leaving the color raster owned by its caller. */
// FUN_001790A0
void FldShadow_DestroyCamera(RwCamera* camera)
{
    RwFrame* frame;
    RwRaster* zBuffer;

    if (camera == NULL)
    {
        return;
    }

    frame = (RwFrame*)camera->object.object.parent;
    if (frame != NULL)
    {
        func_003efd20(camera, NULL);
        func_003e9390(frame);
    }

    zBuffer = camera->zBuffer;
    if (zBuffer != NULL)
    {
        camera->zBuffer = NULL;
        func_003ec330(zBuffer);
    }

    if (camera->frameBuffer != NULL)
    {
        camera->frameBuffer = NULL;
    }
    func_003e8440(camera);
}



/* Sum atomic radii and retain the center/atomic selected by the running-radius comparison. */
// FUN_00179130
void* FldShadow_AccumulateAtomicBounds(void* atomic, void* data)
{
    FldShadowBoundsAccum* accum = data;
    const RwSphere* sphere;

    sphere = func_003bfae0(atomic);
    if (sphere->radius > accum->radius)
    {
        sphere = func_003bfae0(atomic);
        accum->center = sphere->center;
        accum->largestAtomic = atomic;
    }
    sphere = func_003bfae0(atomic);
    accum->radius += sphere->radius;
    accum->count++;
    return atomic;
}



/* measured: MATCH nd0 obj1668/win1680 (12B 3-word zero tail only); V12 u32 c0/c1/c2; MAC dot mula/madda/madd + 1.5f mul+add unfused + adda/msub color exact. */
/* Cull backfaces/outside triangles, project UVs, and emit three alpha-modulated vertices.
 * Flush at 600 vertices; the 1.5-unit normal offset displaces output from collision surfaces. */
// FUN_001791D0
struct RpCollisionTriangle* FldShadow_ProjectTriangle(
    struct RpIntersection* intersection, struct RpWorldSector* sector,
    struct RpCollisionTriangle* tri, f32 distance, void* data)
{
    u8* savedTriangle = (u8*)tri;
    FldShadowProjectionWork* work = data;
    KosakaShadowProjectionTail* base = &work->tail;
    RwV3d positions[3];
    RwV3d projected[3];
    RwV3d firstPosition;
    RwV3d secondPosition;
    RwV3d thirdPosition;
    f32 component;
    RwV3d* normal = (RwV3d*)savedTriangle;
    RwV3d* direction = &base->direction;
    f32 dot;
    f32 normalOffsetX;
    f32 normalOffsetY;
    f32 normalOffsetZ;
    u32 vertexCount;
    KosakaShadowVertex* output;
    dot = normal->x * direction->x + normal->y * direction->y + normal->z * direction->z;
    if (dot > 0.0f) {
        return (struct RpCollisionTriangle*)savedTriangle;
    }
    positions[0] = *((struct RpCollisionTriangle*)savedTriangle)->vertices[0];
    positions[1] = *((struct RpCollisionTriangle*)savedTriangle)->vertices[1];
    positions[2] = *((struct RpCollisionTriangle*)savedTriangle)->vertices[2];
    func_003e42e0(projected, positions, 3, (const struct RwMatrixTag *)base->projectionMatrix);
    normalOffsetX = 1.5f * normal->x;
    normalOffsetY = 1.5f * normal->y;
    normalOffsetZ = 1.5f * normal->z;
    positions[0].x += normalOffsetX;
    positions[0].y += normalOffsetY;
    positions[0].z += normalOffsetZ;
    positions[1].x += normalOffsetX;
    positions[1].y += normalOffsetY;
    positions[1].z += normalOffsetZ;
    positions[2].x += normalOffsetX;
    positions[2].y += normalOffsetY;
    positions[2].z += normalOffsetZ;
    if (!((projected[0].z >= 0.0f || projected[1].z >= 0.0f || projected[2].z >= 0.0f) &&
        (projected[0].x >= 0.0f || projected[1].x >= 0.0f || projected[2].x >= 0.0f) &&
        (projected[0].x <= 1.0f || projected[1].x <= 1.0f || projected[2].x <= 1.0f) &&
        (projected[0].y >= 0.0f || projected[1].y >= 0.0f || projected[2].y >= 0.0f) &&
        (projected[0].y <= 1.0f || projected[1].y <= 1.0f || projected[2].y <= 1.0f))) {
        return (struct RpCollisionTriangle*)savedTriangle;
    }
    vertexCount = work->vertexCount;
    if (vertexCount > 0x255U) {
        if (func_00410420((struct _RxObjSpace3DVertex *)work, vertexCount, 0, 0x19) != 0) {
            func_004106a0(3);
            func_004104d0();
        }
        (base->flushCount)++;
        work->vertexCount = 0;
    }
    output = &work->vertices[work->vertexCount];
    component = positions[0].x; firstPosition.x = component;
    component = positions[0].y; firstPosition.y = component;
    component = positions[0].z; firstPosition.z = component;
    output[0].position = firstPosition;
    component = positions[1].x; secondPosition.x = component;
    component = positions[1].y; secondPosition.y = component;
    component = positions[1].z; secondPosition.z = component;
    output[1].position = secondPosition;
    component = positions[2].x; thirdPosition.x = component;
    component = positions[2].y; thirdPosition.y = component;
    component = positions[2].z; thirdPosition.z = component;
    output[2].position = thirdPosition;
    output[0].u = projected[0].x;
    output[1].u = projected[1].x;
    output[2].u = projected[2].x;
    output[0].v = projected[0].y;
    output[1].v = projected[1].y;
    output[2].v = projected[2].y;
    if (base->fadeWithDepth != 0) {
        {
            f32 z0 = projected[0].z;
            f32 firstFade = 1.0f - z0 * z0;
            u32 firstAlpha;
            if (firstFade < 0.0f) {
                firstAlpha = 0;
            } else {
                u8 firstBaseAlpha = base->alpha;
                f32 firstAlphaScale = (f32)(u32)firstBaseAlpha;
                firstAlpha = (u8)(firstFade * firstAlphaScale);
            }
            output[0].color[0] = firstAlpha;
            output[0].color[1] = firstAlpha;
            output[0].color[2] = firstAlpha;
            output[0].color[3] = firstAlpha;
        }
        {
            f32 z1 = projected[1].z;
            f32 secondFade = 1.0f - z1 * z1;
            u32 secondAlpha;
            if (secondFade < 0.0f) {
                secondAlpha = 0;
            } else {
                u8 secondBaseAlpha = base->alpha;
                f32 secondAlphaScale = (f32)(u32)secondBaseAlpha;
                secondAlpha = (u8)(secondFade * secondAlphaScale);
            }
            output[1].color[0] = secondAlpha;
            output[1].color[1] = secondAlpha;
            output[1].color[2] = secondAlpha;
            output[1].color[3] = secondAlpha;
        }
        {
            f32 z2 = projected[2].z;
            f32 thirdFade = 1.0f - z2 * z2;
            u32 thirdAlpha;
            if (thirdFade < 0.0f) {
                thirdAlpha = 0;
            } else {
                u8 thirdBaseAlpha = base->alpha;
                f32 thirdAlphaScale = (f32)(u32)thirdBaseAlpha;
                thirdAlpha = (u8)(thirdFade * thirdAlphaScale);
            }
            output[2].color[0] = thirdAlpha;
            output[2].color[1] = thirdAlpha;
            output[2].color[2] = thirdAlpha;
            output[2].color[3] = thirdAlpha;
        }
    } else {
        u8 b = base->alpha;
        output[0].color[0] = b;
        output[0].color[1] = b;
        output[0].color[2] = b;
        output[0].color[3] = b;
        output[1].color[0] = b;
        output[1].color[1] = b;
        output[1].color[2] = b;
        output[1].color[3] = b;
        output[2].color[0] = b;
        output[2].color[1] = b;
        output[2].color[2] = b;
        output[2].color[3] = b;
    }
    (work->vertexCount) += 3;
    return (struct RpCollisionTriangle*)savedTriangle;
}
/* Skinned twin of FldShadow_ProjectTriangle: each vertex is first transformed by its
   atomic's frame matrix, then projected and emitted the same way. */
// FUN_00179860
struct RpCollisionTriangle* FldShadow_ProjectSkinnedTriangle(
    struct RpIntersection* intersection, struct RpCollisionTriangle* triangle,
    f32 distance, void* data)
{
    FldShadowAtomicContext* context = data;
    KosakaShadowProjectionTail* base = &context->work->tail;
    RwV3d normal;
    RwV3d positions[3];
    RwV3d projected[3];
    RwV3d skinned[3];
    RwV3d firstPosition;
    RwV3d secondPosition;
    RwV3d thirdPosition;
    f32 component;
    RwV3d* direction = &base->direction;
    f32 dot;
    f32 normalOffsetX;
    f32 normalOffsetY;
    f32 normalOffsetZ;
    u32 vertexCount;
    KosakaShadowVertex* output;
    s32 i;

    normal = *(const RwV3d*)triangle;
    for (i = 0; i < 3; i++) {
        func_003e42e0(&skinned[i], ((const struct RpCollisionTriangle*)triangle)->vertices[i], 1,
                      func_003e9700((RwFrame*)((struct RpAtomic*)context->atomic)->frame));
    }
    dot = normal.x * direction->x + normal.y * direction->y + normal.z * direction->z;
    if (dot > 0.0f) {
        return triangle;
    }
    positions[0] = skinned[0];
    positions[1] = skinned[1];
    positions[2] = skinned[2];
    func_003e42e0(projected, positions, 3, (const struct RwMatrixTag *)base->projectionMatrix);
    normalOffsetX = 1.5f * normal.x;
    normalOffsetY = 1.5f * normal.y;
    normalOffsetZ = 1.5f * normal.z;
    positions[0].x += normalOffsetX;
    positions[0].y += normalOffsetY;
    positions[0].z += normalOffsetZ;
    positions[1].x += normalOffsetX;
    positions[1].y += normalOffsetY;
    positions[1].z += normalOffsetZ;
    positions[2].x += normalOffsetX;
    positions[2].y += normalOffsetY;
    positions[2].z += normalOffsetZ;
    if (!((projected[0].z >= 0.0f || projected[1].z >= 0.0f || projected[2].z >= 0.0f) &&
        (projected[0].x >= 0.0f || projected[1].x >= 0.0f || projected[2].x >= 0.0f) &&
        (projected[0].x <= 1.0f || projected[1].x <= 1.0f || projected[2].x <= 1.0f) &&
        (projected[0].y >= 0.0f || projected[1].y >= 0.0f || projected[2].y >= 0.0f) &&
        (projected[0].y <= 1.0f || projected[1].y <= 1.0f || projected[2].y <= 1.0f))) {
        return triangle;
    }
    vertexCount = context->work->vertexCount;
    if (vertexCount > 0x255U) {
        if (func_00410420((struct _RxObjSpace3DVertex *)context->work, vertexCount, 0, 0x19) != 0) {
            func_004106a0(3);
            func_004104d0();
        }
        (base->flushCount)++;
        context->work->vertexCount = 0;
    }
    output = &context->work->vertices[context->work->vertexCount];
    component = positions[0].x; firstPosition.x = component;
    component = positions[0].y; firstPosition.y = component;
    component = positions[0].z; firstPosition.z = component;
    output[0].position = firstPosition;
    component = positions[1].x; secondPosition.x = component;
    component = positions[1].y; secondPosition.y = component;
    component = positions[1].z; secondPosition.z = component;
    output[1].position = secondPosition;
    component = positions[2].x; thirdPosition.x = component;
    component = positions[2].y; thirdPosition.y = component;
    component = positions[2].z; thirdPosition.z = component;
    output[2].position = thirdPosition;
    output[0].u = projected[0].x;
    output[1].u = projected[1].x;
    output[2].u = projected[2].x;
    output[0].v = projected[0].y;
    output[1].v = projected[1].y;
    output[2].v = projected[2].y;
    if (base->fadeWithDepth != 0) {
        {
            f32 z0 = projected[0].z;
            f32 firstFade = 1.0f - z0 * z0;
            u32 firstAlpha;
            if (firstFade < 0.0f) {
                firstAlpha = 0;
            } else {
                u8 firstBaseAlpha = base->alpha;
                f32 firstAlphaScale = (f32)(u32)firstBaseAlpha;
                firstAlpha = (u8)(firstFade * firstAlphaScale);
            }
            output[0].color[0] = firstAlpha;
            output[0].color[1] = firstAlpha;
            output[0].color[2] = firstAlpha;
            output[0].color[3] = firstAlpha;
        }
        {
            f32 z1 = projected[1].z;
            f32 secondFade = 1.0f - z1 * z1;
            u32 secondAlpha;
            if (secondFade < 0.0f) {
                secondAlpha = 0;
            } else {
                u8 secondBaseAlpha = base->alpha;
                f32 secondAlphaScale = (f32)(u32)secondBaseAlpha;
                secondAlpha = (u8)(secondFade * secondAlphaScale);
            }
            output[1].color[0] = secondAlpha;
            output[1].color[1] = secondAlpha;
            output[1].color[2] = secondAlpha;
            output[1].color[3] = secondAlpha;
        }
        {
            f32 z2 = projected[2].z;
            f32 thirdFade = 1.0f - z2 * z2;
            u32 thirdAlpha;
            if (thirdFade < 0.0f) {
                thirdAlpha = 0;
            } else {
                u8 thirdBaseAlpha = base->alpha;
                f32 thirdAlphaScale = (f32)(u32)thirdBaseAlpha;
                thirdAlpha = (u8)(thirdFade * thirdAlphaScale);
            }
            output[2].color[0] = thirdAlpha;
            output[2].color[1] = thirdAlpha;
            output[2].color[2] = thirdAlpha;
            output[2].color[3] = thirdAlpha;
        }
    } else {
        u8 b = base->alpha;
        output[0].color[0] = b;
        output[0].color[1] = b;
        output[0].color[2] = b;
        output[0].color[3] = b;
        output[1].color[0] = b;
        output[1].color[1] = b;
        output[1].color[2] = b;
        output[1].color[3] = b;
        output[2].color[0] = b;
        output[2].color[1] = b;
        output[2].color[2] = b;
        output[2].color[3] = b;
    }
    (context->work->vertexCount) += 3;
    return triangle;
}
/* Project every collision triangle of this atomic using its frame transform. */
// FUN_00179F70
void* FldShadow_ProjectAtomic(void* atomic, void* data)
{
    FldShadowAtomicContext* context = data;
    context->atomic = atomic;
    func_00394e70(atomic, context->intersection, FldShadow_ProjectSkinnedTriangle, context);
    return atomic;
}

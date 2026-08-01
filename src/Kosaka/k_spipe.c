/* Source unit: src/Kosaka/k_spipe_00178c20.c */
#include "type.h"

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

typedef union RwSky2DVertexAlignementOverlay RwSky2DVertexAlignementOverlay;
union RwSky2DVertexAlignementOverlay
{
    RwSky2DVertexFields els;
    u64 qWords[8];
};

typedef struct RwSky2DVertex RwSky2DVertex;
struct RwSky2DVertex
{
    RwSky2DVertexAlignementOverlay u; // 0x00
};

typedef RwSky2DVertex RwIm2DVertex;

/* rwGlobals.device.fpIm2DRenderPrimitive lives at 0x00887310 in P4 retail. */
#define RwIm2DRenderPrimitive(primType, vertices, numVertices) \
    (*(u32 (**)(u32, void*, u32))0x00887310)((primType), (vertices), (numVertices))


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

typedef struct FldShadowProjectionWork FldShadowProjectionWork;
typedef struct FldShadowTriangle FldShadowTriangle;

typedef struct FldShadowAtomicContext
{
    void* geometry;                       // 0x00
    FldShadowProjectionWork* work;        // 0x04
    void* atomic;                         // 0x08
} FldShadowAtomicContext;

extern void* func_00394e70(void* atomic, void* geometry, void* callback, void* context);
extern void* func_00179860(void* ignored, const FldShadowTriangle* triangle,
                           FldShadowAtomicContext* context);


// FUN_00178C20
u32 K_FldShadow_Draw(f32 xLeft, f32 yTop,
                  f32 xRight, f32 yBot,
                  f32 zBufferNear, f32 recipZ,
                  const RwRGBA* topColor, const RwRGBA* botColor)
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



// FUN_001790A0
void func_001790a0(RwCamera* camera)
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



// FUN_00179130
void* func_00179130(void* atomic, FldShadowBoundsAccum* accum)
{
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



// FUN_00179F70
void* func_00179f70(void* atomic, FldShadowAtomicContext* context)
{
    context->atomic = atomic;
    func_00394e70(atomic, context->geometry, func_00179860, context);
    return atomic;
}

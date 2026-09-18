/* Source unit: src/Kosaka/k_spipe_00178c20.c */
#include "include_asm.h"
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



/* measured: MATCH nd0 obj1668/win1680 (12B 3-word zero tail only); V12 u32 c0/c1/c2; MAC dot mula/madda/madd + 1.5f mul+add unfused + adda/msub color exact. */
// FUN_001791D0
void* func_001791d0(void* ignored0, void* ignored1, u8* tri, u8* work)
{
    extern void func_003e42e0(void* dst, void* src, s32 n, void* mat);
    extern s32 func_00410420(void* w, u32 c, s32 z, s32 v);
    extern void func_004106a0(s32 v);
    extern void func_004104d0(void);
    u8* triSaved = tri;
    u8* workSaved = work;
    u8* base = workSaved + 0x5470;
    RwV3d src[3];
    RwV3d dst[3];
    RwV3d tmp0;
    RwV3d tmp1;
    RwV3d tmp2;
    f32 t;
    RwV3d* triNormal = (RwV3d*)triSaved;
    RwV3d* workVec = (RwV3d*)base;
    f32 dot;
    f32 f15x;
    f32 f15y;
    f32 f15z;
    u32 cnt;
    u8* out;
    dot = triNormal->x * workVec->x + triNormal->y * workVec->y + triNormal->z * workVec->z;
    if (dot > 0.0f) {
        return triSaved;
    }
    src[0] = *(RwV3d*)(*(u8**)(triSaved + 0x1C));
    src[1] = *(RwV3d*)(*(u8**)(triSaved + 0x20));
    src[2] = *(RwV3d*)(*(u8**)(triSaved + 0x24));
    func_003e42e0(dst, src, 3, base + 0x10);
    f15x = 1.5f * triNormal->x;
    f15y = 1.5f * triNormal->y;
    f15z = 1.5f * triNormal->z;
    src[0].x += f15x;
    src[0].y += f15y;
    src[0].z += f15z;
    src[1].x += f15x;
    src[1].y += f15y;
    src[1].z += f15z;
    src[2].x += f15x;
    src[2].y += f15y;
    src[2].z += f15z;
    if (!((dst[0].z >= 0.0f || dst[1].z >= 0.0f || dst[2].z >= 0.0f) &&
        (dst[0].x >= 0.0f || dst[1].x >= 0.0f || dst[2].x >= 0.0f) &&
        (dst[0].x <= 1.0f || dst[1].x <= 1.0f || dst[2].x <= 1.0f) &&
        (dst[0].y >= 0.0f || dst[1].y >= 0.0f || dst[2].y >= 0.0f) &&
        (dst[0].y <= 1.0f || dst[1].y <= 1.0f || dst[2].y <= 1.0f))) {
        return triSaved;
    }
    cnt = *(u32*)(workSaved + 0x5460);
    if (cnt > 0x255U) {
        if (func_00410420(workSaved, cnt, 0, 0x19) != 0) {
            func_004106a0(3);
            func_004104d0();
        }
        (*(s32*)(base + 0x58))++;
        *(u32*)(workSaved + 0x5460) = 0;
    }
    out = workSaved + (*(u32*)(workSaved + 0x5460)) * 0x24;
    t = src[0].x; tmp0.x = t;
    t = src[0].y; tmp0.y = t;
    t = src[0].z; tmp0.z = t;
    *(RwV3d*)out = tmp0;
    t = src[1].x; tmp1.x = t;
    t = src[1].y; tmp1.y = t;
    t = src[1].z; tmp1.z = t;
    *(RwV3d*)(out + 0x24) = tmp1;
    t = src[2].x; tmp2.x = t;
    t = src[2].y; tmp2.y = t;
    t = src[2].z; tmp2.z = t;
    *(RwV3d*)(out + 0x48) = tmp2;
    *(f32*)(out + 0x1C) = dst[0].x;
    *(f32*)(out + 0x40) = dst[1].x;
    *(f32*)(out + 0x64) = dst[2].x;
    *(f32*)(out + 0x20) = dst[0].y;
    *(f32*)(out + 0x44) = dst[1].y;
    *(f32*)(out + 0x68) = dst[2].y;
    if (*(s32*)(base + 0x54) != 0) {
        {
            f32 z0 = dst[0].z;
            f32 t0 = 1.0f - z0 * z0;
            u32 c0;
            if (t0 < 0.0f) {
                c0 = 0;
            } else {
                u8 b0 = *(u8*)(base + 0x50);
                f32 bf0 = (f32)(u32)b0;
                c0 = (u8)(t0 * bf0);
            }
            *(u8*)(out + 0x0C) = c0;
            *(u8*)(out + 0x0D) = c0;
            *(u8*)(out + 0x0E) = c0;
            *(u8*)(out + 0x0F) = c0;
        }
        {
            f32 z1 = dst[1].z;
            f32 t1 = 1.0f - z1 * z1;
            u32 c1;
            if (t1 < 0.0f) {
                c1 = 0;
            } else {
                u8 b1 = *(u8*)(base + 0x50);
                f32 bf1 = (f32)(u32)b1;
                c1 = (u8)(t1 * bf1);
            }
            *(u8*)(out + 0x30) = c1;
            *(u8*)(out + 0x31) = c1;
            *(u8*)(out + 0x32) = c1;
            *(u8*)(out + 0x33) = c1;
        }
        {
            f32 z2 = dst[2].z;
            f32 t2 = 1.0f - z2 * z2;
            u32 c2;
            if (t2 < 0.0f) {
                c2 = 0;
            } else {
                u8 b2 = *(u8*)(base + 0x50);
                f32 bf2 = (f32)(u32)b2;
                c2 = (u8)(t2 * bf2);
            }
            *(u8*)(out + 0x54) = c2;
            *(u8*)(out + 0x55) = c2;
            *(u8*)(out + 0x56) = c2;
            *(u8*)(out + 0x57) = c2;
        }
    } else {
        u8 b = *(u8*)(base + 0x50);
        *(u8*)(out + 0x0C) = b;
        *(u8*)(out + 0x0D) = b;
        *(u8*)(out + 0x0E) = b;
        *(u8*)(out + 0x0F) = b;
        *(u8*)(out + 0x30) = b;
        *(u8*)(out + 0x31) = b;
        *(u8*)(out + 0x32) = b;
        *(u8*)(out + 0x33) = b;
        *(u8*)(out + 0x54) = b;
        *(u8*)(out + 0x55) = b;
        *(u8*)(out + 0x56) = b;
        *(u8*)(out + 0x57) = b;
    }
    (*(u32*)(workSaved + 0x5460)) += 3;
    return triSaved;
}
/* measured: floor v20_bound MISMATCH nd660 obj1800/win1808 (8B 2-word zero tail, >=1754 threshold, not draft); fnalign 450/450 exact, probe 243w, first diff off 220; overflow cnt>0x255U adopted (-2), loop stays exclusive; schedule/subs-off rejected; MAC dot/adda-msub/u8-f staged idioms adopted, no asm. */
/* re-measured 00179860: `python3 -E -s tools/measure_guarded.py src/Kosaka/k_spipe.c func_00179860`
   reports 243 differing words today.  The figures in the note above are
   from earlier bodies and no longer describe what is banked here; they
   are kept only as history.  Flagged by `tools/floorboard.py --audit`. */
// FUN_00179860 NONMATCHING
#ifdef NON_MATCHING
void* func_00179860(void* ignored, const FldShadowTriangle* triangle, FldShadowAtomicContext* context)
{
    extern void* func_003e9700(void* arg);
    extern void func_003e42e0(void* dst, void* src, s32 count, void* mtx);
    extern s32 func_00410420(void* verts, u32 count, void* mtx, s32 flags);
    extern void func_004106a0(s32 arg);
    extern void func_004104d0(void);
    typedef struct { f32 x, y, z; } Vec3;
    typedef struct { f32 x, y, z; u8 col[4]; u8 pad[12]; f32 u, v; } OutVert;
    Vec3 tri;
    Vec3 t0;
    Vec3 t1;
    Vec3 t2;
    Vec3 cpy[3];
    Vec3 proj[3];
    Vec3 tmp[3];
    s32 i;
    u8* wbase;
    wbase = *(u8**)((u8*)context + 4) + 0x5470;
    tri = *(const Vec3*)triangle;
    for (i = 0; i < 3; i++) {
        func_003e42e0(&tmp[i], *(void**)((const u8*)triangle + 0x1C + i * 4), 1, func_003e9700(*(void**)((u8*)(*(void**)((u8*)context + 8)) + 4)));
    }
    {
        f32 px = *(f32*)(wbase + 0);
        f32 py = *(f32*)(wbase + 4);
        f32 pz = *(f32*)(wbase + 8);
        f32 dot = tri.x * px + tri.y * py + tri.z * pz;
        if (dot > 0.0f) {
            return (void*)triangle;
        }
    }
    cpy[0] = tmp[0];
    cpy[1] = tmp[1];
    cpy[2] = tmp[2];
    func_003e42e0(proj, cpy, 3, wbase + 0x10);
    {
        f32 sx = 1.5f * tri.x;
        f32 sy = 1.5f * tri.y;
        f32 sz = 1.5f * tri.z;
        cpy[0].x += sx; cpy[0].y += sy; cpy[0].z += sz;
        cpy[1].x += sx; cpy[1].y += sy; cpy[1].z += sz;
        cpy[2].x += sx; cpy[2].y += sy; cpy[2].z += sz;
    }
    if ((proj[0].z < 0.0f && proj[1].z < 0.0f && proj[2].z < 0.0f) ||
        (proj[0].x < 0.0f && proj[1].x < 0.0f && proj[2].x < 0.0f) ||
        (proj[0].x > 1.0f && proj[1].x > 1.0f && proj[2].x > 1.0f) ||
        (proj[0].y < 0.0f && proj[1].y < 0.0f && proj[2].y < 0.0f) ||
        (proj[0].y > 1.0f && proj[1].y > 1.0f && proj[2].y > 1.0f)) {
        return (void*)triangle;
    }
    {
        u8* w = wbase - 0x5470;
        u32 cnt = *(u32*)(w + 0x5460);
        if (cnt > 0x255U) {
            if (func_00410420(w, cnt, 0, 25) != 0) {
                func_004106a0(3);
                func_004104d0();
            }
            *(s32*)(wbase + 0x58) += 1;
            *(u32*)(w + 0x5460) = 0;
        }
    }
    {
        u8* w = wbase - 0x5470;
        OutVert* base = (OutVert*)(w + (*(u32*)(w + 0x5460)) * 0x24);
        t0 = cpy[0];
        base[0].x = t0.x; base[0].y = t0.y; base[0].z = t0.z;
        t1 = cpy[1];
        base[1].x = t1.x; base[1].y = t1.y; base[1].z = t1.z;
        t2 = cpy[2];
        base[2].x = t2.x; base[2].y = t2.y; base[2].z = t2.z;
        base[0].u = proj[0].x; base[1].u = proj[1].x; base[2].u = proj[2].x;
        base[0].v = proj[0].y; base[1].v = proj[1].y; base[2].v = proj[2].y;
        if (*(s32*)(wbase + 0x54) != 0) {
            u8 av = *(u8*)(wbase + 0x50);
            f32 tt0 = 1.0f - proj[0].z * proj[0].z;
            if (tt0 < 0.0f) {
                base[0].col[0] = 0; base[0].col[1] = 0; base[0].col[2] = 0; base[0].col[3] = 0;
            } else {
                u8 cc0 = (u8)(tt0 * (f32)av);
                base[0].col[0] = cc0; base[0].col[1] = cc0; base[0].col[2] = cc0; base[0].col[3] = cc0;
            }
            {
                f32 tt1 = 1.0f - proj[1].z * proj[1].z;
                if (tt1 < 0.0f) {
                    base[1].col[0] = 0; base[1].col[1] = 0; base[1].col[2] = 0; base[1].col[3] = 0;
                } else {
                    u8 cc1 = (u8)(tt1 * (f32)av);
                    base[1].col[0] = cc1; base[1].col[1] = cc1; base[1].col[2] = cc1; base[1].col[3] = cc1;
                }
            }
            {
                f32 tt2 = 1.0f - proj[2].z * proj[2].z;
                if (tt2 < 0.0f) {
                    base[2].col[0] = 0; base[2].col[1] = 0; base[2].col[2] = 0; base[2].col[3] = 0;
                } else {
                    u8 cc2 = (u8)(tt2 * (f32)av);
                    base[2].col[0] = cc2; base[2].col[1] = cc2; base[2].col[2] = cc2; base[2].col[3] = cc2;
                }
            }
        } else {
            u8 av = *(u8*)(wbase + 0x50);
            base[0].col[0] = av; base[0].col[1] = av; base[0].col[2] = av; base[0].col[3] = av;
            base[1].col[0] = av; base[1].col[1] = av; base[1].col[2] = av; base[1].col[3] = av;
            base[2].col[0] = av; base[2].col[1] = av; base[2].col[2] = av; base[2].col[3] = av;
        }
        *(u32*)(w + 0x5460) += 3;
    }
    return (void*)triangle;
}
#else
INCLUDE_ASM("asm/nonmatchings/k_spipe", func_00179860);
#endif
// FUN_00179F70
void* func_00179f70(void* atomic, FldShadowAtomicContext* context)
{
    context->atomic = atomic;
    func_00394e70(atomic, context->geometry, func_00179860, context);
    return atomic;
}

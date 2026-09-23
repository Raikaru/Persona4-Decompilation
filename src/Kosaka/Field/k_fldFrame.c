/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "include_asm.h"
#include "type.h"
#include "Kosaka/k_clump_internal.h"
#include "Kosaka/k_fldFrame_internal.h"

typedef unsigned int u_long128 __attribute__((mode(TI)));
typedef struct RwFrame RwFrame;
typedef struct RwMatrixTag RwMatrix;
extern u8* iGpffff9db0;
extern s32 MT_Scene_GetRes(s32 arg0);
extern u8* func_001452b0(s32 arg0);
extern s32 func_0014a160(void);
extern s32 func_0014a200(void);
extern s32 func_0014a270(void);
extern s32* func_00155280(void);
extern s32 func_001687d0(s32 arg0);
extern s32 func_001687e0(s32 arg0);
extern s32 func_00169780(void* collisionWorld, f32* origin,
                         f32* vector, f32 fraction);
extern s32 func_0016a110(s32 collisionWorld, f32* origin,
                         f32* vector, f32 fraction, s32 fieldId);
extern RwMatrix* func_003e9700(RwFrame* frame);
extern s32 func_00457120(void);

/* PS2 RenderWare rpcollis.h: collision callbacks retain the distance argument
 * even when the query recomputes its own plane distance. */
typedef struct RpAtomic RpAtomic;
typedef struct RpWorld RpWorld;
typedef struct RpWorldSector RpWorldSector;
typedef struct RpIntersection RpIntersection;
typedef struct RpCollisionTriangle {
    RwV3d normal;
    RwV3d point;
    s32 index;
    RwV3d *vertices[3];
} RpCollisionTriangle;

/* RenderWare intersection payload: its largest members are two vectors. */
struct RpIntersection
{
    union
    {
        struct { RwV3d start; RwV3d end; } line;
        RwV3d point;
        struct { RwV3d center; f32 radius; } sphere;
        struct { RwV3d sup; RwV3d inf; } box;
        void *object;
    } t;
    s32 type;
};

/* Shared field collision state; the world and atomic producers use the same
 * parallel arrays and retain the atomic beside the intersection copy. */
typedef struct FldFrameCollisionCollector
{
    RwV3d points[64];
    RwV3d normals[64];
    f32 distances[64];
    RwV3d corrections[64];
    s32 flags[64];
    s32 mode;
    s32 count;
    s32 hitCount;
    RwV3d direction;
    RpIntersection intersection;
    RpAtomic *atomic;
} FldFrameCollisionCollector;
typedef RpCollisionTriangle *(*FldFrameWorldTriangleCallback)(
    RpIntersection *, RpWorldSector *, RpCollisionTriangle *, f32, void *);

extern RpWorld *func_00394d70(RpWorld *world, RpIntersection *intersection,
                              FldFrameWorldTriangleCallback callback, void *data);
extern f32 RwV3dNormalize(f32* dst, const f32* src);
extern void* memset(void* dst, s32 value, u32 size);

typedef RpCollisionTriangle *(*FldFrameGeometryTriangleCallback)(
    RpIntersection *, RpCollisionTriangle *, f32, void *);

extern RpAtomic *func_00394e70(RpAtomic *atomic, RpIntersection *intersection,
    FldFrameGeometryTriangleCallback callback, void *data);
extern RpCollisionTriangle *func_00169a30(RpIntersection *intersection,
    RpCollisionTriangle *triangle, f32 callbackDistance, void *data);

// 44 bytes. Callback state passed through RenderWare field raycasts.
typedef struct FldFrameRaycast
{
    RwV3d* hitPointDst;    // 0x00
    u32 didHit;            // 0x04
    RwV3d line[2];         // 0x08
    u32 intersectionType;  // 0x20. RpIntersection line type.
    f32 nearestFraction;   // 0x24
    void* hitObject;       // 0x28
} FldFrameRaycast;
extern RpCollisionTriangle *func_0016b350(RpIntersection *intersection,
    RpCollisionTriangle *triangle, f32 fraction, void *data);

// P3 counterpart fGpffff820c (gp -0x7DF4); P4 retail uses gp -0x7D4C,
// i.e. absolute 0x007690f0 - 0x7d4c = 0x007613a4.
extern f32 fGpffff82b4;
extern void* func_0016b430(void* collisionWorld, void* data);
extern RpCollisionTriangle *func_0016b770(RpIntersection *intersection,
    RpCollisionTriangle *triangle, f32 fraction, void *data);





// FUN_00169200
RwV3d* func_00169200(RwV3d* dst, const RwV3d* point,
                     const RwV3d* start, const RwV3d* end)
{
    RwV3d edge;
    f32 projection;
    f32 edgeLengthSquared;
    f32 fraction;

    edge.x = end->x - start->x;
    edge.y = end->y - start->y;
    edge.z = end->z - start->z;
    projection = point->x * edge.x + point->y * edge.y + point->z * edge.z -
                 (start->x * edge.x + start->y * edge.y + start->z * edge.z);

    if (projection <= 0.0f)
    {
        *dst = *start;
    }
    else
    {
        edgeLengthSquared = edge.x * edge.x + edge.y * edge.y + edge.z * edge.z;
        if (projection < edgeLengthSquared)
        {
            fraction = projection / edgeLengthSquared;
            dst->x = edge.x * fraction;
            dst->y = edge.y * fraction;
            dst->z = edge.z * fraction;
            dst->x += start->x;
            dst->y += start->y;
            dst->z += start->z;
        }
        else
        {
            *dst = *end;
        }
    }

    return dst;
}



static inline s32 fldFrameFindPlane(u8 *context, const RwV3d *normal)
{
    s32 index;
    s32 count;
    f32 *record;

    index = 0;
    count = *(s32 *)(context + 0xB04);
    while (index < count) {
        record = (f32 *)(context + 12 * index);
        if (record[192] == normal->x && record[193] == normal->y && record[194] == normal->z)
            return index;
        index++;
    }
    return -1;
}

/* measured: b210 -O2, 1112 executable bytes and eight retail zero bytes;
 * all three call relocations resolve. The shared plane search preserves the
 * separate failed-comparison and found-index exits. Edge records use the
 * collector base first; interior records retain their scaled-index order. */
// FUN_00169320
RpCollisionTriangle *func_00169320(RpIntersection *intersection, RpWorldSector *sector,
                    RpCollisionTriangle *collision, f32 callbackDistance, void *data)
{
    /* A sphere center begins the intersection input union. */
    RwV3d *point = (RwV3d *)intersection;
    RwV3d *triangle = &collision->normal;
    u8 *context = data;
    extern f32 fabsf(f32 x);
    extern s32 K_FldFrame_IsPointInTriangle(f32 *arg0, f32 **arg1, f32 *arg2);
    extern f32 RwV3dLength(f32 *vec);

    RwV3d projected;
    RwV3d edgePoint;
    RwV3d delta;
    RwV3d* firstVertex;
    f32 projection;
    f32 distance;
    f32 edgeDistance;
    s32 i;
    f32 tx;
    f32 ty;
    f32 tz;
    ty = collision->normal.y;
    tx = collision->normal.x;
    tz = collision->normal.z;
    firstVertex = collision->vertices[0];
    projection = firstVertex->x * tx + firstVertex->y * ty + firstVertex->z * tz - (point->x * tx + point->y * ty + point->z * tz);
    projected.x = tx * projection;
    projected.y = ty * projection;
    projected.z = tz * projection;
    projected.x += point->x;
    projected.y += point->y;
    projected.z += point->z;
    if (K_FldFrame_IsPointInTriangle(&projected.x, (f32 **)((u8 *)collision + 0x1C), &triangle->x) != 0)
    {
        distance = fabsf(projection);
        {
        s32 index;
        s32 count;
        f32* record;
        f32* fraction;
        index = fldFrameFindPlane(context, triangle);
        count = *(s32 *)(context + 0xB04);
        if (index >= 0)
        {
            fraction = (f32*)((u8*)(4 * index) + (u32)context + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * index);
                *(RwV3d*)record = projected;
                *(RwV3d*)(record + 192) = *triangle;
                *fraction = distance;
            }
        }
        else
        {
            fraction = (f32*)((u8*)(4 * count) + (u32)context + 0x600);
            if (distance < *fraction)
            {
                record = (f32*)(context + 12 * count);
                *(RwV3d*)record = projected;
                record = (f32*)((u8*)(12 * *(s32*)(context + 0xb04)) + (u32)context);
                *(RwV3d*)(record + 192) = *triangle;
                fraction = (f32*)((u8*)(4 * *(s32*)(context + 0xb04)) + (u32)context + 0x600);
                *fraction = distance;
                (*(s32*)(context + 0xb04))++;
            }
        }
    }
    }
    else
    {
        for (i = 0; i < 3; i++)
        {
            func_00169200(&edgePoint, &projected, *(RwV3d**)((u8*)collision + 0x1c + 4 * i), *(RwV3d**)((u8*)collision + 0x1c + 4 * ((i + 1) % 3)));
            delta.x = point->x - edgePoint.x;
            delta.y = point->y - edgePoint.y;
            delta.z = point->z - edgePoint.z;
            edgeDistance = RwV3dLength((f32*)&delta);
            {
            s32 index;
            s32 count;
            f32* record;
            f32* fraction;
            index = fldFrameFindPlane(context, triangle);
            count = *(s32 *)(context + 0xB04);
            if (index >= 0)
            {
                fraction = (f32*)(context + 4 * index + 0x600);
                if (edgeDistance < *fraction)
                {
                    record = (f32*)(context + 12 * index);
                    *(RwV3d*)record = edgePoint;
                    *(RwV3d*)(record + 192) = *triangle;
                    *fraction = edgeDistance;
                }
            }
            else
            {
                fraction = (f32*)(context + 4 * count + 0x600);
                if (edgeDistance < *fraction)
                {
                    record = (f32*)(context + 12 * count);
                    *(RwV3d*)record = projected;
                    record = (f32*)(context + 12 * *(s32*)(context + 0xb04));
                    *(RwV3d*)(record + 192) = *triangle;
                    fraction = (f32*)(context + 4 * *(s32*)(context + 0xb04) + 0x600);
                    *fraction = edgeDistance;
                    (*(s32*)(context + 0xb04))++;
                }
            }
            }
        }
    }
    return collision;
}
/* Collect world-sphere contacts and remove inward motion from the displacement.
 * The complete work layout retains the shared collector and aligned query copies.
 * measured: b210 -O2 emits 680 bytes plus the eight-byte retail zero suffix.
 * Expression reuse fuses the staged projection; propagation-off retains its
 * component snapshots. Signed post-normalization scaling preserves the distance
 * address's separate lifetime. All addresses remain inside the complete work. */
// FUN_00169780
#pragma push
#pragma opt_common_subs on
#pragma opt_propagation off
s32 func_00169780(void* collisionWorld, f32* origin, f32* vector, f32 radius)
{
    typedef struct FldFrameSphereWork
    {
        FldFrameCollisionCollector collector;
        RwV3d zero;
        union
        {
            u_long128 bits;
            struct
            {
                RwV3d center;
                f32 radius;
            } sphere;
        } input;
        union
        {
            u_long128 bits;
            RpIntersection intersection;
        } query;
        union
        {
            RwV3d vector;
            f32 components[3];
        } delta;
    } FldFrameSphereWork;
    FldFrameSphereWork work;
    f32 adjustX;
    f32 adjustY;
    f32 adjustZ;
    f32 correction;
    f32 dot;
    s32 result;
    s32 i;

    result = 0;
    work.input.sphere.center.x = origin[0] + vector[0];
    work.input.sphere.center.y = origin[1] + vector[1];
    work.input.sphere.center.z = origin[2] + vector[2];
    work.input.sphere.radius = radius;
    work.query.intersection.type = 3;
    work.query.bits = work.input.bits;
    for (i = 0; i < 64; i++)
    {
        u8* record = (u8*)&work + sizeof(RwV3d) * i;
        memset(record, 0, 12);
        memset(record + sizeof(work.collector.points), 0, 12);
        work.collector.distances[i] = fGpffff82b4;
    }
    work.collector.count = 0;
    if (collisionWorld == NULL)
    {
        return 0;
    }
    func_00394d70(collisionWorld, &work.query.intersection, func_00169320, &work.collector);
    for (i = 0; i < work.collector.count; i++)
    {
        const u8* distanceEntry;
        distanceEntry = (const u8*)&work + i * sizeof(f32);
        if (*(const f32*)(distanceEntry + 0x600) < fGpffff82b4)
        {
            RwV3d* point = &work.collector.points[i];
            f32 dx;
            f32 dy;
            f32 dz;
            f32* direction;
            f32 oldZ;
            f32 oldX;
            f32 zero;

            work.delta.vector.x = work.query.intersection.t.sphere.center.x - point->x;
            work.delta.vector.y = work.query.intersection.t.sphere.center.y - point->y;
            work.delta.vector.z = work.query.intersection.t.sphere.center.z - point->z;
            direction = work.delta.components;
            RwV3dNormalize(direction, direction);
            /* The signed contact displacement is recomputed after normalization. */
            distanceEntry = (const u8*)&work + i * (s32)sizeof(f32);
            correction = work.query.intersection.t.sphere.radius - *(const f32*)(distanceEntry + 0x600);
            dx = work.delta.vector.x;
            adjustX = dx * correction;
            dy = work.delta.vector.y;
            adjustY = dy * correction;
            dz = work.delta.vector.z;
            adjustZ = dz * correction;
            oldZ = vector[2];
            oldX = vector[0];
            /* Retain the Y, X, Z accumulator and comparison-value lifetimes. */
            dot = vector[1] * dy;
            zero = 0.0f;
            dot += oldX * dx;
            dot += oldZ * dz;
            if (dot < zero)
            {
                adjustX = dx * dot;
                adjustY = dy * dot;
                adjustZ = dz * dot;
                vector[0] = oldX - adjustX;
                vector[1] -= adjustY;
                vector[2] -= adjustZ;
                result = 1;
            }
            oldX = vector[0];
            zero = 0.0f;
            if (oldX == zero && vector[1] == zero && vector[2] == zero)
            {
                vector[0] = oldX + adjustX;
                vector[1] += adjustY;
                vector[2] += adjustZ;
                result = 1;
            }
        }
    }
    return result;
}

#pragma pop
/* Keep the scaled offset and collector address in the integer domain
 * until the resulting address points into the collector storage. */
static inline u8 *fldFrameCollectorOffset(u32 offset, FldFrameCollisionCollector *collector)
{
    return (u8 *)(offset + (uintptr_t)collector);
}

static inline s32 fldFrameFindLocalPlane(FldFrameCollisionCollector *collector, const RwV3d *normal)
{
    s32 index;
    s32 count;
    const u8 *record;
    f32 nx;
    f32 ny;
    f32 nz;

    index = 0;
    nx = normal->x;
    ny = normal->y;
    nz = normal->z;
    count = collector->count;
    while (index < count)
    {
        record = (const u8 *)collector + sizeof(RwV3d) * index;
        if (*(const f32 *)(record + 0x300) == nx &&
            *(const f32 *)(record + 0x304) == ny &&
            *(const f32 *)(record + 0x308) == nz)
        {
            return index;
        }
        index++;
    }
    return -1;
}

/* Transform an atomic triangle to world space and merge its nearest plane
 * contact into the shared collector. Existing edge contacts use the closest
 * edge point; new edge contacts retain the plane projection, as retail does.
 * measured: b210 -O2 emits 1668 bytes plus a 12-byte retail zero suffix.
 * Removing propagation-off changes eight words; removing loop-invariants-on
 * changes the vertex-pointer addition at +0xAC. The interior path uses
 * the offset helper for distance and flag addresses. */
#pragma push
#pragma opt_propagation off
#pragma opt_loop_invariants on
// FUN_00169A30
RpCollisionTriangle *func_00169a30(RpIntersection *intersection,
    RpCollisionTriangle *triangle, f32 callbackDistance, void *data)
{
    extern f32 fabsf(f32 value);
    extern s32 K_FldFrame_IsPointInTriangle(f32 *point, f32 **vertices, f32 *normal);
    extern f32 RwV3dLength(f32 *vector);
    extern RwV3d *func_003e4360(RwV3d *dst, const RwV3d *src, s32 count, const void *matrix);
    extern RwV3d *func_003e42e0(RwV3d *dst, const RwV3d *src, s32 count, const void *matrix);
    extern f32 D_0076122C;
    const RwV3d *point = &intersection->t.sphere.center;
    FldFrameCollisionCollector *collector = data;
    RwV3d projected;
    RwV3d normal;
    f32 *vertexPointers[3];
    RwV3d edgePoint;
    RwV3d delta;
    union
    {
        RwV3d vector;
        f32 components[3];
    } vertices[3];
    s32 i;
    void *matrix;
    f32 dot;
    f32 projection;
    f32 distance;
    f32 edgeDistance;
    f32 nx;
    f32 ny;
    f32 nz;

    normal = triangle->normal;
    matrix = func_003e9700(*(RwFrame **)((u8 *)collector->atomic + 4));
    func_003e4360(&normal, &triangle->normal, 1, matrix);
    RwV3dNormalize(&normal.x, &normal.x);
    for (i = 0; i < 3; i++)
    {
        func_003e42e0(&vertices[i].vector, triangle->vertices[i], 1, matrix);
        vertexPointers[i] = vertices[i].components;
    }
    /* Retail 00169B14..00169B38 reads direction before testing mode.
     * Mode-one sphere queries leave it unwritten; preserve that original
     * omission. See Retained_color_and_sphere_20260922_worker6.md. */
    dot = normal.x * collector->direction.x +
          normal.y * collector->direction.y +
          normal.z * collector->direction.z;
    if (dot >= 0.0f && collector->mode == 0)
    {
        return triangle;
    }
    if (fabsf(normal.y) > D_0076122C)
    {
        return triangle;
    }
    ny = normal.y;
    nx = normal.x;
    nz = normal.z;
    projection = vertexPointers[0][0] * nx + vertexPointers[0][1] * ny + vertexPointers[0][2] * nz -
                 (point->x * nx + point->y * ny + point->z * nz);
    projected.x = nx * projection;
    projected.y = ny * projection;
    projected.z = nz * projection;
    projected.x += point->x;
    projected.y += point->y;
    projected.z += point->z;
    if (K_FldFrame_IsPointInTriangle(&projected.x, vertexPointers, &normal.x) != 0)
    {
        s32 index;
        s32 count;
        u8 *record;
        f32 *fraction;
        u8 *fbase;
        s32 *flag;
        distance = fabsf(projection);
        index = fldFrameFindLocalPlane(collector, &normal);
        count = collector->count;
        if (index >= 0)
        {
            fbase = fldFrameCollectorOffset(4 * index, collector);
            fraction = (f32 *)(fbase + 0x600);
            if (distance < *fraction)
            {
                record = (u8 *)collector + 12 * index;
                *(RwV3d *)record = projected;
                *(RwV3d *)(record + 0x300) = normal;
                *fraction = distance;
                if (collector->mode == 1)
                {
                    flag = (s32 *)(fbase + 0xA00);
                    if (*flag == 0)
                    {
                        collector->hitCount++;
                    }
                    *flag = 1;
                }
            }
        }
        else
        {
            fraction = (f32 *)(fldFrameCollectorOffset(4 * count, collector) + 0x600);
            if (distance < *fraction)
            {
                record = (u8 *)collector + 12 * count;
                *(RwV3d *)record = projected;
                record = fldFrameCollectorOffset(12 * collector->count, collector);
                *(RwV3d *)(record + 0x300) = normal;
                fraction = (f32 *)(fldFrameCollectorOffset(4 * collector->count, collector) + 0x600);
                *fraction = distance;
                if (collector->mode == 1)
                {
                    if (*(s32 *)(fldFrameCollectorOffset(4 * collector->count, collector) + 0xA00) == 0)
                    {
                        collector->hitCount++;
                    }
                    {
                        s32 hitFlag = 1;
                        *(s32 *)(fldFrameCollectorOffset(4 * collector->count, collector) + 0xA00) = hitFlag;
                    }
                }
                collector->count++;
            }
        }
    }
    else
    {
        s32 edge;
        for (edge = 0; edge < 3; edge++)
        {
            s32 index;
            s32 count;
            u8 *record;
            f32 *fraction;
            u8 *fbase;
            s32 *flag;
            func_00169200(&edgePoint, &projected, (RwV3d *)vertexPointers[edge], (RwV3d *)vertexPointers[(edge + 1) % 3]);
            delta.x = point->x - edgePoint.x;
            delta.y = point->y - edgePoint.y;
            delta.z = point->z - edgePoint.z;
            edgeDistance = RwV3dLength(&delta.x);
            index = fldFrameFindLocalPlane(collector, &normal);
            count = collector->count;
            if (index >= 0)
            {
                fbase = (u8 *)collector + 4 * index;
                fraction = (f32 *)(fbase + 0x600);
                if (edgeDistance < *fraction)
                {
                    record = (u8 *)collector + 12 * index;
                    *(RwV3d *)record = edgePoint;
                    *(RwV3d *)(record + 0x300) = normal;
                    *fraction = edgeDistance;
                    if (collector->mode == 1)
                    {
                        flag = (s32 *)(fbase + 0xA00);
                        if (*flag == 0)
                        {
                            collector->hitCount++;
                        }
                        *flag = 1;
                    }
                }
            }
            else
            {
                fraction = (f32 *)((u8 *)collector + 4 * count + 0x600);
                if (edgeDistance < *fraction)
                {
                    record = (u8 *)collector + 12 * count;
                    *(RwV3d *)record = projected;
                    record = (u8 *)collector + 12 * collector->count;
                    *(RwV3d *)(record + 0x300) = normal;
                    fraction = (f32 *)((u8 *)collector + 4 * collector->count + 0x600);
                    *fraction = edgeDistance;
                    if (collector->mode == 1)
                    {
                        if (*(s32 *)((u8 *)collector + 4 * collector->count + 0xA00) == 0)
                        {
                            collector->hitCount++;
                        }
                        *(s32 *)((u8 *)collector + 4 * collector->count + 0xA00) = 1;
                    }
                    collector->count++;
                }
            }
        }
    }
    return triangle;
}
#pragma pop
// FUN_0016A0C0
void* func_0016a0c0(void* collisionWorld, void* state)
{
    FldFrameCollisionCollector *collector = state;
    collector->atomic = collisionWorld;
    func_00394e70(collisionWorld, &collector->intersection,
                  func_00169a30, collector);
    return collisionWorld;
}



/* measured: guarded floor from retail + m2c + romwright (fnalign retail 532/object 532 exact, 0% deviation, within 3% banking gate; probe_variants 411 -> 403 via 200 decl orders -> 251 via opt_loop_invariants on, 500 orders no further; pragma sweep loop_invariants on wins, schedule/common/propagation combos regress; float splits and line scalar/direct regress, =+ ties; frame 0xc80 with points[64]/normals[64] (192 floats each), fracs[64], extra[64] (192), flags[64]; romwright --types two RwV3d + float; line[1]=origin then line[0]=line[1] +=400/-=600; fieldId (u16)low + (low & 0x3ff) keeps double-andi; 7-word do-while query copy; Y,X,Z dots per 00169a30; production stays ASM per banking rule. */
// FUN_0016A110 NONMATCHING
#ifdef NON_MATCHING
#pragma push
#pragma opt_loop_invariants on
s32 func_0016a110(s32 collisionWorld, f32 *origin, f32 *vector, f32 fraction, s32 fieldId)
{
    extern void *mdlGetClump(void *model);
    extern f32 RwV3dLength(f32 *vec);
    extern u8 D_007E8020[];
    extern f32 fGpffff82b8;
    extern u32 func_0016b480(void *cw, const RwV3d *line, RwV3d *hit);
    typedef struct FldFrameWork6A110
    {
        RwV3d points[64];
        RwV3d normals[64];
        f32 fracs[64];
        RwV3d extra[64];
        s32 flags[64];
        s32 mode;
        s32 count;
        s32 hitCount;
        RwV3d normDir;
        u8 scratch[0x20];
        u8 zero[0x18];
        f32 input[4];
        union
        {
            u_long128 bits;
            f32 f[4];
        } copy;
        u8 tail[8];
        s32 type;
    } FldFrameWork6A110;
    f32 qy;
    f32 neg;
    RwV3d hit;
    s32 k;
    s32 allHit;
    s32 i;
    f32 scale;
    RwV3d delta;
    FldFrameWork6A110 work;
    s32 result;
    RwV3d scaled;
    u8 *list10;
    u8 *list3;
    RwV3d line[2];
    s32 m;
    f32 qz;
    f32 qfrac;
    f32 dot;
    s32 n;
    s32 j;
    result = 0;
    list10 = func_001452b0(10);
    list3 = func_001452b0(3);
    func_001452b0(1);
    work.input[0] = origin[0] + vector[0];
    work.input[1] = origin[1] + vector[1];
    work.input[2] = origin[2] + vector[2];
    work.input[3] = fraction;
    work.type = 3;
    work.copy.bits = *(u_long128 *)work.input;
    for (i = 0; i < 64; i++)
    {
        memset(&work.points[i], 0, 12);
        memset(&work.normals[i], 0, 12);
        work.fracs[i] = fGpffff82b4;
        work.flags[i] = 0;
    }
    work.hitCount = 0;
    work.count = 0;
    {
        s32 *src = (s32 *)&work.copy;
        s32 *dst = (s32 *)work.scratch;
        s32 cnt = 7;
        do
        {
            s32 v = *src;
            src++;
            cnt--;
            *dst = v;
            dst++;
        } while (cnt > 0);
    }
    RwV3dNormalize((f32 *)&work.normDir, (const f32 *)vector);
    memset(work.zero, 0, 12);
    if (collisionWorld == 0)
    {
        return 0;
    }
    work.mode = 1;
    func_003bff30((void *)collisionWorld, func_0016a0c0, work.points);
    while (list10 != NULL)
    {
        if (((*(s32 *)(list10 + 0x28) & 2) != 0) && (*(s32 *)(list10 + 0x150) == 1))
        {
            void *target = mdlGetClump(*(void **)(list10 + 0x144));
            func_003bff30(target, func_0016a0c0, work.points);
            line[1].x = origin[0];
            line[1].y = origin[1];
            line[1].z = origin[2];
            line[0] = line[1];
            line[0].y += 400.0f;
            line[1].y -= 600.0f;
            target = mdlGetClump(*(void **)(list10 + 0x144));
            if (func_0016b480(target, line, &hit) == 1)
            {
                vector[1] = -((origin[1] - fraction) - hit.y);
            }
        }
        list10 = *(u8 **)(list10 + 0x138);
    }
    work.mode = 0;
    func_0014a200();
    func_0014a200();
    {
        u16 low = (u16)fieldId;
        if ((low & 0x3ff) == 0)
        {
        for (j = 0; ; j++)
        {
            u8 *entry = *(u8 **)(D_007E8020 + j * 4);
            if (entry == NULL)
            {
                break;
            }
            {
                s32 present = *(s32 *)(entry + 0x48) != 0;
                if (present != 0)
                {
                    present = *(s32 *)(entry + 0x54) != 0;
                }
                if (present != 0)
                {
                    u8 *other = *(u8 **)(entry + 0x54);
                    if (((*(s32 *)(other + 0x28) & 2) != 0) && ((*(s32 *)(entry + 0x40) & 2) == 0))
                    {
                        void *id = *(void **)(other + 0x228);
                        if (id != 0)
                        {
                            void *target = mdlGetClump(id);
                            func_003bff30(target, func_0016a0c0, work.points);
                        }
                    }
                }
            }
        }
        }
    }
    while (list3 != NULL)
    {
        if (((*(s32 *)(list3 + 0x28) & 2) != 0) && (*(s32 *)(list3 + 0x22c) != 0))
        {
            void *target = mdlGetClump(*(void **)(list3 + 0x22c));
            func_003bff30(target, func_0016a0c0, work.points);
        }
        list3 = *(u8 **)(list3 + 0x138);
    }
    for (k = 0; ; k++)
    {
        u8 *entry = *(u8 **)(D_007E8020 + k * 4 + 0x20);
        if (entry == NULL)
        {
            break;
        }
        if (*(s32 *)entry != 0)
        {
            void *id = *(void **)(entry + 0x164);
            if (id != 0)
            {
                void *target = mdlGetClump(id);
                func_003bff30(target, func_0016a0c0, work.points);
            }
        }
    }
    n = 0;
    allHit = 1;
    while (n < work.count)
    {
        if (work.flags[n] == 0)
        {
            allHit = 0;
            break;
        }
        n++;
    }
    qy = work.copy.f[1];
    qz = work.copy.f[2];
    qfrac = work.copy.f[3];
    for (i = 0; i < work.count; i++)
    {
        if (work.fracs[i] < fGpffff82b4)
        {
            delta.x = work.copy.f[0] - work.points[i].x;
            delta.y = qy - work.points[i].y;
            delta.z = qz - work.points[i].z;
            RwV3dNormalize((f32 *)&delta, (const f32 *)&delta);
            scale = qfrac - work.fracs[i];
            scaled.x = delta.x * scale;
            scaled.y = delta.y * scale;
            scaled.z = delta.z * scale;
            if (work.flags[i] == 1)
            {
                work.extra[i] = scaled;
            }
            else
            {
                for (m = 0; m < work.count; m++)
                {
                    if (work.flags[m] == 1)
                    {
                        f32 d = scaled.y * work.extra[m].y + scaled.x * work.extra[m].x + scaled.z * work.extra[m].z;
                        if (d < 0.0f)
                        {
                            scaled.x += work.extra[m].x;
                            scaled.y += work.extra[m].y;
                            scaled.z += work.extra[m].z;
                        }
                    }
                }
            }
            neg = -1.0f;
            if (allHit == 1)
            {
                neg = vector[1] * work.normals[i].y + vector[0] * work.normals[i].x + vector[2] * work.normals[i].z;
            }
            dot = vector[1] * delta.y + vector[0] * delta.x + vector[2] * delta.z;
            if ((dot < 0.0f || work.flags[i] == 1) && neg < 0.0f)
            {
                vector[0] += scaled.x;
                vector[1] += scaled.y;
                vector[2] += scaled.z;
                result = 1;
            }
            if (vector[0] == 0.0f && vector[1] == 0.0f && vector[2] == 0.0f)
            {
                vector[0] += scaled.x;
                vector[1] += scaled.y;
                vector[2] += scaled.z;
                result = 1;
            }
        }
    }
    if (allHit == 0 && work.count >= 2)
    {
        RwV3dLength((f32 *)vector);
        for (n = 0; n < work.count - 1; n++)
        {
            for (m = n + 1; m < work.count; m++)
            {
                f32 d = work.normals[n].y * work.normals[m].y + work.normals[n].x * work.normals[m].x + work.normals[n].z * work.normals[m].z;
                if (d < fGpffff82b8)
                {
                    vector[0] = 0.0f;
                    vector[1] = 0.0f;
                    vector[2] = 0.0f;
                    return result;
                }
            }
        }
    }
    return result;
}
#pragma pop
#else
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016a110);
#endif
// FUN_0016A960
s32 func_0016a960(f32* origin, f32* vector, f32 fraction, s32 fieldId)
{
    u8* object;
    s32 collisionWorld;
    object = *(u8**)(iGpffff9db0 + 0x28);

    if (object == NULL)
    {
        return 0;
    }
    if ((*(s32*)object & 1) != 0)
    {
        return func_00169780((void*)(*(s32*)(object + 0xc)), origin, vector, fraction);
    }

    collisionWorld = 0;
    if (func_0014a200() == 1 ||
        (*(s32*)iGpffff9db0 >= 0x33 && *(s32*)iGpffff9db0 < 0x4f))
    {
        u8* entry;
        u8* field;
    s32 fieldX;
    s32 fieldY;
        s32 fieldFlags;
        entry = (u8*)func_001452b0(0xc);
        field = (u8*)MT_Scene_GetRes(fieldId);
        fieldFlags = fieldId & 0xffff;
        if (fieldFlags == 0xffff)
        {
            object = (u8*)((u8*)func_003e9700((RwFrame*)(
                *(u8**)((u8*)((u8*)(uintptr_t)func_00457120()) + 4))));
            fieldX = (s32)((*(f32*)(object + 0x30) + 600.0f) / 1200.0f);
            fieldY = (s32)((*(f32*)(object + 0x38) + 600.0f) / 1200.0f);
        }
        else
        {
            if (((fieldFlags & 0xffc00) >> 10) == 1)
            {
                s32* coordinate;
                coordinate = (s32*)(field + 0x220);
                fieldX = func_001687d0(*coordinate);
                fieldY = func_001687e0(*coordinate);
            }
            else
            {
                s32* coordinate;
                coordinate = (s32*)(field + 0x228);
                fieldX = func_001687d0(*coordinate);
                fieldY = func_001687e0(*coordinate);
            }
        }
        {
            u32 key;
            key = *(u16*)((u8*)func_00155280() + (fieldY << 8) +
                          (fieldX << 4) + 0x56);
            while (entry != NULL)
            {
                if (*(u16*)entry == key)
                {
                    collisionWorld = *(s32*)(*(u8**)(entry + 0x1a0) + 8);
                    break;
                }
                entry = *(u8**)(entry + 0x138);
            }
        }
    }
    else
    {
        collisionWorld = *(s32*)(*(u8**)(iGpffff9db0 + 0x28) + 8);
    }
    return func_0016a110(collisionWorld, origin, vector, fraction, fieldId);
}
/* 1216/1216 bytes with all relocations resolved. The sphere query shares
 * the callback collector and retains each neighbor coordinate across both
 * table reads. Contact accumulation uses its own counter and accepted value.
 * Retail leaves direction and the unused sphere payload words unwritten;
 * see Retained_color_and_sphere_20260922_worker6.md for exact store coverage.
 * Both scoped settings are part of the retained b210 -O2 measurement. */
// FUN_0016ABC0
#pragma push
#pragma opt_loop_invariants on
#pragma opt_propagation off
s32 func_0016abc0(void* collisionWorld, const RwV3d* point, f32 radius, RwV3d* normal, RwV3d* vector)
{
    extern u8* func_001452b0(s32 arg0);
    extern void* memset(void* dst, s32 value, u32 size);
    extern s32 func_0014a200(void);
    extern s32 func_0014a270(void);
    extern s32 func_00457120(void);
    extern RwMatrix* func_003e9700(RwFrame* frame);
    extern s32* func_00155280(void);
    extern void* mdlGetClump(void* model);
    extern f32 RwV3dNormalize(f32* dst, const f32* src);
    extern f32 D_007615DC;
    extern s32 D_005F1650[];
    typedef struct FldFrameQueryWork
    {
        FldFrameCollisionCollector collector;
        RwV3d zero;
        union
        {
            u_long128 bits;
            f32 components[4];
        } input;
        union
        {
            u_long128 bits;
            RpIntersection intersection;
        } query;
    } FldFrameQueryWork;
    FldFrameQueryWork work;
    s32 result;
    u8* list;
    s32 i;
    s32 foundCount;
    f32 threshold;
    f32 px, py, pz;

    result = 0;
    list = func_001452b0(10);
    func_001452b0(3);
    func_001452b0(1);
    px = point->x;
    py = point->y;
    pz = point->z;
    work.input.components[0] = px;
    work.input.components[1] = py;
    work.input.components[2] = pz;
    work.input.components[3] = radius;
    work.query.intersection.type = 3;
    work.query.bits = work.input.bits;
    for (i = 0; i < 64; i++)
    {
        u8* rec = ((u8 *)&work.collector) + 12 * i;
        memset(rec, 0, 12);
        memset(rec + 0x300, 0, 12);
        *(f32*)(((u8 *)&work.collector) + 0x600 + 4 * i) = D_007615DC;
        *(s32*)(((u8 *)&work.collector) + 0xa00 + 4 * i) = 0;
    }
    work.collector.hitCount = 0;
    work.collector.count = 0;
    /* The retail seven-word copy includes two unused payload words. */
    work.collector.intersection = work.query.intersection;
    memset(&work.zero, 0, 12);
    if (collisionWorld == 0)
        return 0;
    work.collector.mode = 1;
    func_003bff30(collisionWorld, func_0016a0c0, ((u8 *)&work.collector));
    if (func_0014a200() == 1 || func_0014a270() == 1)
    {
        const u8* dimensions;
        f32 positionX;
        f32 translatedX;
        s32 x;
        s32 z;
        s32 j;
        dimensions = (const u8*)((u8*)func_003e9700((RwFrame*)(*(u8**)((u8*)((u8*)(uintptr_t)func_00457120()) + 4))));
        positionX = *(const f32*)(dimensions + 0x30);
        translatedX = 600.0f + positionX;
        x = (s32)(translatedX / 1200.0f);
        z = (s32)((*(const f32*)(dimensions + 0x38) + 600.0f) / 1200.0f);
        for (j = 0; j < 4; j++)
        {
            s32* offsets = &D_005F1650[2 * j];
            s32* zOffset = offsets + 1;
            void* table;
            table = func_00155280();
            if (*(u8*)((u8*)table + ((z + *zOffset) * 256) + 16 * (x + offsets[0]) + 84) == 1)
            {
                u16 id;
                void* target;
                u8* node;
                offsets = &D_005F1650[2U * j];
                table = func_00155280();
                id = *(u16*)((u8*)table + ((z + *zOffset) * 256) + 16 * (x + offsets[0]) + 86);
                target = 0;
                node = func_001452b0(12);
                while (node != 0)
                {
                    if (*(u16*)node == id)
                    {
                        target = *(void**)(*(u8**)(node + 0x1a0) + 8);
                        break;
                    }
                    node = *(u8**)(node + 0x138);
                }
                if (target != 0)
                    func_003bff30(target, func_0016a0c0, ((u8 *)&work.collector));
            }
        }
        while (list != 0)
        {
            if ((*(s32*)(list + 0x28) & 2) != 0 && *(s32*)(list + 0x150) == 1)
            {
                func_003bff30(mdlGetClump(*(void**)(list + 0x144)),
                              func_0016a0c0, &work.collector);
            }
            list = *(u8**)(list + 0x138);
        }
    }
    normal->x = 0.0f;
    normal->y = 0.0f;
    normal->z = 0.0f;
    vector->x = 0.0f;
    vector->y = 0.0f;
    vector->z = 0.0f;
    {
        s32 contact = 0;
        s32 accepted;
        foundCount = 0;
        accepted = 1;
        threshold = D_007615DC;
        for (; contact < work.collector.count; contact++)
        {
            if (*(f32*)(((u8 *)&work.collector) + 0x600 + 4 * contact) < threshold)
            {
                const u8 *entry = (const u8 *)&work + 12 * contact;
                normal->x += *(const f32 *)(entry + 0x300);
                normal->y += *(const f32 *)(entry + 0x304);
                normal->z += *(const f32 *)(entry + 0x308);
                {
                    f32 currentX = vector->x;
                    f32 contactX = *(const f32 *)(entry + 0x0);
                    vector->x = currentX + contactX;
                }
                vector->y += *(const f32 *)(entry + 0x4);
                vector->z += *(const f32 *)(entry + 0x8);
                foundCount++;
                result = accepted;
            }
        }
    }
    if (result == 1)
    {
        RwV3dNormalize(&normal->x, &normal->x);
        threshold = (f32)foundCount;
        vector->x /= threshold;
        vector->y /= threshold;
        vector->z /= threshold;
    }
    return result;
}

#pragma pop
/* 476/480 bytes; ten resolved relocations; four zero alignment bytes.
 * Write the preferred/fallback selection through the caller's real output. */
#pragma push
#pragma opt_loop_invariants on
#pragma opt_common_subs on
extern s32 func_0016abc0(void* collisionWorld, const RwV3d* point, f32 radius,
                         RwV3d* normal, RwV3d* vector);

typedef struct FldSelectionResource
{
    u32 flags;
    u32 unknown04;
    void* fallback;
    u32 unknown0c;
    u32 unknown10;
    void* preferred;
} FldSelectionResource;
typedef struct FldSelectionNode
{
    u16 id;
    u8 unknown002[0x136];
    struct FldSelectionNode* next;
    u8 unknown13c[0x64];
    FldSelectionResource* resource;
} FldSelectionNode;

static inline void fldFrameSelectWorld(FldSelectionResource* selected, void** dst)
{
    void* world = selected->preferred;
    if (world != 0)
    {
        *dst = world;
        return;
    }
    *dst = selected->fallback;
}

// FUN_0016B080
s32 func_0016b080(const RwV3d* point, f32 radius, RwV3d* normal, RwV3d* vector)
{
    s32 result;
    void* collisionWorld;
    s32 fieldX;
    s32 fieldZ;
    u16 key;

    FldSelectionResource* object;
    result = 0;
    object = *(FldSelectionResource**)(iGpffff9db0 + 0x28);
    if (object == NULL)
        return result;
    if ((object->flags & 1) == 0)
    {
        collisionWorld = 0;
        if (func_0014a200() == 1 || func_0014a270() == 1)
        {
            u8* map;
            FldSelectionNode* node;
            map = ((u8*)func_003e9700((RwFrame*)(*(u8**)(((u8*)(uintptr_t)func_00457120()) + 4))));
            fieldX = (s32)((((const RwV3d*)(map + 0x30))->x + 600.0f) / 1200.0f);
            fieldZ = (s32)((((const RwV3d*)(map + 0x30))->z + 600.0f) / 1200.0f);
            key = *(u16*)((u8*)func_00155280() + (fieldZ * 256) +
                         (fieldX * 16) + 0x56);
            for (node = (FldSelectionNode*)func_001452b0(12); node != NULL;
                 node = node->next)
            {
                if (node->id == key)
                {
                    FldSelectionResource* selected = node->resource;
                    fldFrameSelectWorld(selected, &collisionWorld);
                    break;
                }
            }
            result = func_0016abc0(collisionWorld, point, radius, normal, vector);
        }
        else
        {
            FldSelectionResource* selected = *(FldSelectionResource**)(iGpffff9db0 + 0x28);
            void* fallbackWorld;
            fldFrameSelectWorld(selected, &fallbackWorld);
            result = func_0016abc0(fallbackWorld, point, radius, normal, vector);
        }
    }
    return result;
}
#pragma pop

/* measured: propagation probe for func_0016b260 register scheduling. */
#pragma opt_propagation off
// FUN_0016B260
RpCollisionTriangle *func_0016b260(RpIntersection *intersection,
                    RpWorldSector *sector, RpCollisionTriangle *collision,
                    f32 distance, void *data)
{
    const RwV3d *line = (const RwV3d *)intersection;
    const void *triangle = collision;
    FldFrameRaycast *raycast = data;
    typedef struct FldFrameLine
    {
        RwV3d start;
        RwV3d end;
    } FldFrameLine;
    RwV3d delta;
    FldFrameLine lineCopy;
    const RwV3d* normal;
    const RwV3d* point;
    f32 startX;
    f32 deltaX;
    f32 startY;
    f32 deltaY;
    f32 startZ;
    f32 deltaZ;
    f32 normalX;
    f32 normalY;
    f32 normalZ;
    f32 numerator;
    f32 denominator;
    f32 fraction;

    lineCopy = *(const FldFrameLine*)line;
    startX = lineCopy.start.x;
    deltaX = startX - lineCopy.end.x;
    startY = lineCopy.start.y;
    deltaY = startY - lineCopy.end.y;
    startZ = lineCopy.start.z;
    deltaZ = startZ - lineCopy.end.z;
    normal = (const RwV3d*)triangle;
    normalY = normal->y;
    normalX = normal->x;
    normalZ = normal->z;
    denominator = normalX * deltaX + normalY * deltaY + normalZ * deltaZ;
    point = *(const RwV3d**)((const u8*)triangle + 0x1c);
    numerator = -(-(normalX * point->x + normalY * point->y +
                    normalZ * point->z) +
                   (normalX * startX + normalY * startY +
                    normalZ * startZ));
    fraction = numerator / denominator;
    raycast->hitPointDst->x = fraction * deltaX + startX;
    raycast->hitPointDst->y = fraction * deltaY + startY;
    raycast->hitPointDst->z = fraction * deltaZ + startZ;
    raycast->didHit = 1;
    return 0;
}
#pragma opt_propagation on
// FUN_0016B350
RpCollisionTriangle *func_0016b350(RpIntersection *intersection,
    RpCollisionTriangle *triangle, f32 fraction, void *data)
{
    const RwV3d *line = (const RwV3d *)intersection;
    FldFrameRaycast *raycast = data;
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = 1;
        raycast->nearestFraction = fraction;
    }
    return triangle;
}



// FUN_0016B430
void* func_0016b430(void* collisionWorld, void* data)
{
    FldFrameRaycast* raycast = data;
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, (RpIntersection *)&raycast->line[0],
                  func_0016b350, raycast);
    return collisionWorld;
}



// FUN_0016B480
u32 func_0016b480(void* collisionWorld, const RwV3d* line,
                  RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy __attribute__((aligned(16)));
    FldFrameIntersection intersection __attribute__((aligned(16)));
    FldFrameRaycast raycast;

    lineCopy = *(const FldFrameLine*)line;
    raycast.hitPointDst = hitPointDst;
    raycast.didHit = 0;
    raycast.nearestFraction = fGpffff82b4;
    intersection.type = 1;
    intersection.line = lineCopy;
    *(FldFrameIntersection*)&raycast.line[0] = intersection;

    if (collisionWorld == NULL)
    {
        return 0;
    }
    func_003bff30(collisionWorld, func_0016b430, &raycast);
    return raycast.didHit;
}



/* Snapshot both endpoints before any provider call. Grid lookup uses start X/Z;
   the non-grid path reloads the root after the mode query. Branch-local full
   raycast state reproduces all 560 retail bytes and 12 relocations without
   artificial alignment. A hit writes all three destination components. */
// FUN_0016B540
u32 func_0016b540(const RwV3d* line, RwV3d* hitPointDst)
{
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    typedef struct FldFrameIntersection
    {
        FldFrameLine line;
        u32 type;
    } FldFrameIntersection;
    FldFrameLine lineCopy;
    u8* object;
    void* collisionWorld;

    lineCopy = *(const FldFrameLine*)line;
    object = *(u8**)(iGpffff9db0 + 0x28);
    if (object == NULL)
    {
        return 0;
    }
    if ((*(u32*)object & 1) != 0)
    {
        FldFrameIntersection intersection;
        FldFrameRaycast raycast;
        u32 result;
        collisionWorld = *(void**)(object + 0xc);
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = 0;
        intersection.type = 1;
        intersection.line = lineCopy;
        if (collisionWorld == NULL)
        {
            result = 0;
        }
        else
        {
            func_00394d70(collisionWorld, (RpIntersection *)&intersection, func_0016b260, &raycast);
            result = raycast.didHit;
        }
        return result;
    }
    else
    {
        FldFrameIntersection intersection;
        FldFrameRaycast raycast;
        collisionWorld = NULL;
        if (func_0014a160() != 0)
        {
            u8* entry;
            u32 key;
            entry = func_001452b0(0xc);
            key = *(u16*)((u8*)func_00155280() +
                         (s32)((600.0f + lineCopy.point[0].z) / 1200.0f) * 0x100 +
                         (s32)((600.0f + lineCopy.point[0].x) / 1200.0f) * 0x10 + 0x56);
            while (entry != NULL)
            {
                if (*(u16*)entry == key)
                {
                    collisionWorld = *(void**)(*(u8**)(entry + 0x1a0) + 8);
                    break;
                }
                entry = *(u8**)(entry + 0x138);
            }
        }
        else
        {
            collisionWorld = *(void**)(*(u8**)(iGpffff9db0 + 0x28) + 8);
        }
        raycast.hitPointDst = hitPointDst;
        raycast.didHit = 0;
        raycast.nearestFraction = fGpffff82b4;
        intersection.type = 1;
        intersection.line = lineCopy;
        *(FldFrameIntersection*)&raycast.line[0] = intersection;
        if (collisionWorld == NULL)
        {
            return 0;
        }
        func_003bff30(collisionWorld, func_0016b430, &raycast);
        return raycast.didHit;
    }
}
// FUN_0016B770
RpCollisionTriangle *func_0016b770(RpIntersection *intersection,
    RpCollisionTriangle *triangle, f32 fraction, void *data)
{
    const RwV3d *line = (const RwV3d *)intersection;
    FldFrameRaycast *raycast = data;
    typedef struct FldFrameLine
    {
        RwV3d point[2];
    } FldFrameLine;
    FldFrameLine lineCopy;
    RwV3d segment;

    lineCopy = *(const FldFrameLine*)line;
    if (raycast->nearestFraction > fraction)
    {
        segment.x = lineCopy.point[1].x - lineCopy.point[0].x;
        segment.y = lineCopy.point[1].y - lineCopy.point[0].y;
        segment.z = lineCopy.point[1].z - lineCopy.point[0].z;
        segment.x *= fraction;
        segment.y *= fraction;
        segment.z *= fraction;
        segment.x += lineCopy.point[0].x;
        segment.y += lineCopy.point[0].y;
        segment.z += lineCopy.point[0].z;
        *raycast->hitPointDst = segment;
        raycast->didHit = 1;
        raycast->nearestFraction = fraction;
    }
    return triangle;
}



// FUN_0016B850
void* func_0016b850(void* collisionWorld, void* data)
{
    FldFrameRaycast* raycast = data;
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, (RpIntersection *)&raycast->line[0],
                  func_0016b770, raycast);
    return collisionWorld;
}

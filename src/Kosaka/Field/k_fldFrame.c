/* Source unit: src/Kosaka/Field/k_fldFrame.c */
#include "include_asm.h"
#include "type.h"

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
typedef unsigned int u_long128 __attribute__((mode(TI)));
extern u8* iGpffff9db0;
extern s32 func_00145270(s32 arg0);
extern u8* func_001452b0(s32 arg0);
extern s32 func_0014a200(void);
extern s32 func_0014a270(void);
extern void* func_00155280(void);
extern s32 func_001687d0(s32 arg0);
extern s32 func_001687e0(s32 arg0);
extern s32 func_00169780(s32 collisionWorld, f32* origin,
                         f32* vector, f32 fraction);
extern s32 func_0016a110(s32 collisionWorld, f32* origin,
                         f32* vector, f32 fraction, s32 fieldId);
extern u8* func_003e9700(s32 arg0);
extern u8* func_00457120(void);

extern void func_00394d70(s32 collisionWorld, s32 intersection,
                          void* callback, s32 param);
extern void func_003e40b0(f32* dst, const f32* src);
extern void func_0043f9c8(void* dst, s32 value, s32 size);

extern void func_00394e70(void* collision, void* state,
                          void* callback, void* param);
extern void* func_00169a30(const RwV3d* point, const void* triangle,
                           void* collector);

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
extern void* func_0016b350(f32 fraction, const RwV3d* line,
                           void* unused, FldFrameRaycast* raycast);

// P3 counterpart fGpffff820c (gp -0x7DF4); P4 retail uses gp -0x7D4C,
// i.e. absolute 0x007690f0 - 0x7d4c = 0x007613a4.
extern f32 fGpffff82b4;
extern void func_003bff30(void* collisionWorld, void* callback, void* param);
extern void* func_0016b430(void* collisionWorld, FldFrameRaycast* raycast);
extern void* func_0016b770(f32 fraction, const RwV3d* line,
                           void* unused, FldFrameRaycast* raycast);





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



// FUN_00169320
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_00169320);
// FUN_00169780
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_00169780);
// FUN_00169A30
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_00169a30);
// FUN_0016A0C0
void* func_0016a0c0(void* collisionWorld, void* state)
{
    *(void**)((u8*)state + 0xb34) = collisionWorld;
    func_00394e70(collisionWorld, (u8*)state + 0xb18,
                  func_00169a30, state);
    return collisionWorld;
}



// FUN_0016A110
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016a110);
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
        return func_00169780(*(s32*)(object + 0xc), origin, vector, fraction);
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
        field = (u8*)func_00145270(fieldId);
        fieldFlags = fieldId & 0xffff;
        if (fieldFlags == 0xffff)
        {
            object = (u8*)func_003e9700(
                *(s32*)((u8*)func_00457120() + 4));
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
// FUN_0016ABC0
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016abc0);
// FUN_0016B080
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016b080);
// FUN_0016B260
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016b260);
// FUN_0016B350
void* func_0016b350(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
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
    return unused;
}



// FUN_0016B430
void* func_0016b430(void* collisionWorld, FldFrameRaycast* raycast)
{
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, &raycast->line[0],
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



// FUN_0016B540
INCLUDE_ASM("asm/nonmatchings/k_fldFrame", func_0016b540);
// FUN_0016B770
void* func_0016b770(f32 fraction, const RwV3d* line,
                    void* unused, FldFrameRaycast* raycast)
{
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
    return unused;
}



// FUN_0016B850
void* func_0016b850(void* collisionWorld, FldFrameRaycast* raycast)
{
    raycast->hitObject = collisionWorld;
    func_00394e70(collisionWorld, &raycast->line[0],
                  func_0016b770, raycast);
    return collisionWorld;
}

#include "include_asm.h"
#include "rw_geometry_internal.h"
#include "type.h"
#include "effect_instance_internal.h"
#include "effect_vu0_internal.h"
#include "mdl_effect_resource_internal.h"
typedef unsigned int u_long128 __attribute__((mode(TI)));

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

// 64 bytes. Layout from P3FES include/rw/rwplcore.h.
typedef struct RwMatrix
{
    RwV3d right;   // 0x00
    u32 flags;     // 0x0c
    RwV3d up;      // 0x10
    u32 pad1;      // 0x1c
    RwV3d at;      // 0x20
    u32 pad2;      // 0x2c
    RwV3d pos;     // 0x30
    u32 pad3;      // 0x3c
} RwMatrix;

/* RenderWare rpworld.h: eight bytes, with the material index after the vertices. */
typedef struct RpTriangle {
    u16 vertIndex[3];
    s16 matIndex;
} RpTriangle;

extern void func_003c02e0(u8 *source);
extern void func_003c4220(s32 source);
extern void func_003e9390(s32 source);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
s32 TnGetOffset1C(s32 slotIndex);
extern void PrimAppendNode(s32 list, void *node);
extern void func_003c42b0(void *source, s32 texture);
extern s32 func_003c2150(u8 *source, u8 *texture, s32 output);
extern u8 *func_003c22f0(u8 *source);
extern u8 *GeometryCreateMultiPart(s32 partCount, s32 verticesPerPart, s32 trianglesPerPart, s32 flags);
extern u8 D_007132F0[];
extern u8 D_00713470[];
extern u8 D_00713488[];
extern u8 D_0071348C[];
extern u8 D_00713480[];
extern u8 D_00713494[];
extern u8 D_00713490[];
extern u8 D_0071349C[];
extern u8 D_007134A0[];
extern u8 D_007134A8[];
extern u8 D_007134B0[];
extern char D_00713CE0[];
extern f32 fGpffff8044;


extern void (*jtbl_008873EC[])(void *);
static inline f32 code1_0048_mul(f32 left, f32 right) {
    return left * right;
}
static inline void code1_0048_call(s32 (*fn)(s32), s32 value) {
    fn(value);
}

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0048; members 00484010-004842d0 */

/* Clone multipart geometry, retaining textures and rebuilding material indices. */
// FUN_00484010
u8 *mdlEffectCloneMultipartGeometry(u8 *source)
{
    u8 *clone;
    u8 *materials;
    s32 partIndex;
    u8 *sourceGeometry;
    u8 *cloneGeometry;
    u8 *triangle;
    u8 *materialSlot;
    s32 index;
    MdlEffectMultipartGeometry *geometry;

    clone = GeometryCreateMultiPart(
        ((MdlEffectMultipartGeometry *)source)->partCount.value,
        ((MdlEffectMultipartGeometry *)source)->vertexCount,
        ((MdlEffectMultipartGeometry *)source)->trianglesPerPart,
        ((MdlEffectMultipartGeometry *)source)->flags);
    materials = ((MdlEffectMultipartGeometry *)clone)->materials;
    sourceGeometry = ((MdlEffectGeometryModel *)((MdlEffectMultipartGeometry *)source)->model)->geometry;
    cloneGeometry = ((MdlEffectGeometryModel *)((MdlEffectMultipartGeometry *)clone)->model)->geometry;
    geometry = (MdlEffectMultipartGeometry *)source;

    index = 0;
    while (index < geometry->partCount.signedValue) {
        u8 *p;

        p = ((u8 **)((MdlEffectMultipartGeometry *)source)->materials)[index];
        if (*(s32 *)p != 0) {
            func_003c42b0(((void **)materials)[index], *(s32 *)p);
        }
        index += 1;
    }

    RpGeometryLock((RpGeometry *)sourceGeometry, 1);

    {
        u8 *src;
        u8 *dst;
        s32 triangleIndex;

        src = ((MdlEffectGeometryData *)sourceGeometry)->triangles;
        dst = ((MdlEffectGeometryData *)cloneGeometry)->triangles;
        triangle = dst;
        for (triangleIndex = 0; triangleIndex < ((MdlEffectMultipartGeometry *)source)->triangleCount; triangleIndex++) {
            ((RpTriangle *)dst)->vertIndex[0] = ((RpTriangle *)src)->vertIndex[0];
            ((RpTriangle *)dst)->vertIndex[1] = ((RpTriangle *)src)->vertIndex[1];
            ((RpTriangle *)dst)->vertIndex[2] = ((RpTriangle *)src)->vertIndex[2];
            src += 8;
            dst += 8;
        }
    }

    partIndex = 0;
    while (partIndex < geometry->partCount.signedValue) {
        index = 0;
        materialSlot = (u8 *)(materials + partIndex * 4);
        while (index < (s16)geometry->trianglesPerPart) {
            func_003c2150(cloneGeometry, triangle, *(s32 *)materialSlot);
            triangle += 8;
            index += 1;
        }
        partIndex += 1;
    }

    func_003c22f0(sourceGeometry);
    return clone;
}

/* Release the model, resource and each material before freeing the wrapper. */
// FUN_004841C0
void mdlEffectDestroyMultipartGeometry(u8 *source)
{
    s32 model;
    s32 resource;
    s32 index;
    MdlEffectMultipartGeometry *geometry;

    geometry = (MdlEffectMultipartGeometry *)source;
    model = *(s32 *)&((MdlEffectMultipartGeometry *)source)->model;
    if (model != 0) {
        func_003c02e0((u8 *)model);
    }
    resource = ((MdlEffectMultipartGeometry *)source)->resource;
    if (resource != 0) {
        func_003e9390(resource);
    }
    if (geometry->materials != NULL) {
        index = 0;
        goto loop_004841c0_check;
loop_004841c0_body:
        func_003c4220(((s32 *)((MdlEffectMultipartGeometry *)source)->materials)[(u16)index]);
        index = (index + 1) & 0xFFFF;
loop_004841c0_check:
        if ((index & 0xFFFF) < ((MdlEffectMultipartGeometry *)source)->partCount.signedValue) {
            goto loop_004841c0_body;
        }
    }
    jtbl_008873EC[0](source);
}

/* Append the wrapper's embedded link to the stream's primitive list. */
// FUN_00484280
void mdlEffectAppendGeometryPrimitive(u8 *source, s32 texture)
{
    s32 list;

    list = TnGetOffset1C(texture);
    ((MdlEffectMultipartGeometry *)source)->link[0] = 0;
    ((MdlEffectMultipartGeometry *)source)->link[1] = 0;
    PrimAppendNode(list, source + 0x18);
}

/* Assign the same texture handle to all multipart materials. */
// FUN_004842D0
void mdlEffectSetGeometryTexture(u8 *source, s32 texture)
{
    s32 index;

    index = 0;
    goto loop_004842d0_check;
loop_004842d0_body:
    func_003c42b0(((void **)((MdlEffectMultipartGeometry *)source)->materials)[(u16)index], texture);
    index = (index + 1) & 0xFFFF;
loop_004842d0_check:
    if ((index & 0xFFFF) < ((MdlEffectMultipartGeometry *)source)->partCount.signedValue) {
        goto loop_004842d0_body;
    }
}























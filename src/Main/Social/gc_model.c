/* Consolidated Persona 4 source units. */
/* Build with -DP4_UNIT_<address> to select one original source unit. */

#if defined(P4_UNIT_0036A6B0)
/* Source unit: src/Main/Social/gc_model_0036a6b0.c (1 function markers) */
#include "type.h"

extern void* func_00457120(void);
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);

// FUN_0036A6B0
void func_0036a6b0(s32 unused, const f32* source, f32 scale, void* viewport)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;
    f32* out = viewport;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    out[0] = panelScale * (camera[0] * (1.0f + (-source[0] / (f32)(size[0] >> 1))));
    out[1] = panelScale * (camera[1] * (1.0f + (-source[1] / (f32)(size[1] >> 1))));
    out[2] = panelScale;
}
#endif /* P4_UNIT_0036A6B0 */

#if defined(P4_UNIT_0036A790)
/* Source unit: src/Main/Social/gc_model_0036a790.c (1 function markers) */
#include "type.h"

extern void* func_00457120(void);
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);

// FUN_0036A790
f32 func_0036a790(const f32* value, f32 scale)
{
    s32 size[8];
    f32* camera;
    f32 panelScale = scale;

    camera = (f32*)((u8*)func_00457120() + 0x68);
    func_003e8970(size, func_003e89c0());
    return (6.0f * value[11] * (f32)(size[0] >> 1)) / (panelScale * camera[0]);
}
#endif /* P4_UNIT_0036A790 */

#if defined(P4_UNIT_0036ABD0)
/* Source unit: src/Main/Social/gc_model_0036abd0.c (1 function markers) */
#include "type.h"

typedef struct PanelVec3 {
    f32 x;
    f32 y;
    f32 z;
} PanelVec3;
typedef struct PanelQuaternion {
    f32 x;
    f32 y;
    f32 z;
    f32 w;
} PanelQuaternion;
typedef struct PanelVideoMode {
    s32 width;
    s32 height;
    s32 depth;
    u32 flags;
    s32 refreshRate;
    s32 format;
} PanelVideoMode;
typedef struct PanelMatrix {
    PanelVec3 right;
    u32 flags;
    PanelVec3 up;
    u32 pad1;
    PanelVec3 at;
    u32 pad2;
    PanelVec3 pos;
    u32 pad3;
} PanelMatrix;
typedef struct PanelTransform {
    u8 unknown00[0x10];
    PanelQuaternion rotation;
    PanelVec3 translation;
    PanelVec3 scale;
    void* model;
} PanelTransform;
typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
typedef struct RwMatrix {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} RwMatrix;

extern void* func_00457120(void);
extern void* func_003e89c0(void);
extern void func_003e8970(void* viewport, void* cameraData);
extern void RwMatrixScale(RwMatrix* matrix, const RwV3d* scale, u32 combine);
extern void* func_003e0f80(void);
extern void func_003e0e20(void* matrix, void* source, s32 mode);
extern void func_003e0f40(void* matrix);
extern void RwMatrixTranslate(RwMatrix* matrix, const RwV3d* translation, u32 combine);
extern void* func_003e9700(void* model);

// FUN_0036ABD0
void func_0036abd0(PanelMatrix* output, const PanelTransform* transform)
{
    const PanelVec3* cameraScale;
    PanelMatrix* rotation;
    PanelVec3 scale;
    PanelVideoMode viewport;
    f32 aspectRatio;
    f32 factor;
    f32 scaledX;
    f32 scaledY;
    f32 scaledZ;
    f32 xx;
    f32 yy;
    f32 zz;
    f32 xy;
    f32 xz;
    f32 yz;
    f32 xw;
    f32 yw;
    f32 zw;
    void* camera;
    void* viewportData;

    camera = func_00457120();
    cameraScale = (const PanelVec3*)((u8*)camera + 0x68);
    viewportData = func_003e89c0();
    func_003e8970(&viewport, viewportData);

    aspectRatio = (f32)viewport.width * cameraScale->y /
                  ((f32)viewport.height * cameraScale->x);
    scale.x = transform->scale.x;
    scale.y = aspectRatio * transform->scale.y;
    scale.z = transform->scale.z;
    RwMatrixScale((RwMatrix*)output, (const RwV3d*)&scale, 0);

    rotation = (PanelMatrix*)func_003e0f80();
    factor = 2.0f /
             (transform->rotation.x * transform->rotation.x +
              transform->rotation.y * transform->rotation.y +
              transform->rotation.z * transform->rotation.z +
              transform->rotation.w * transform->rotation.w);
    scaledX = transform->rotation.x * factor;
    scaledY = transform->rotation.y * factor;
    scaledZ = transform->rotation.z * factor;
    xw = scaledX * transform->rotation.w;
    yw = scaledY * transform->rotation.w;
    zw = scaledZ * transform->rotation.w;
    xx = transform->rotation.x * scaledX;
    yy = transform->rotation.y * scaledY;
    zz = transform->rotation.z * scaledZ;
    yz = transform->rotation.y * scaledZ;
    xz = transform->rotation.z * scaledX;
    xy = transform->rotation.x * scaledY;

    rotation->right.x = 1.0f - (yy + zz);
    rotation->right.y = xy + zw;
    rotation->right.z = xz - yw;
    rotation->up.x = xy - zw;
    rotation->up.y = 1.0f - (zz + xx);
    rotation->up.z = yz + xw;
    rotation->at.x = xz + yw;
    rotation->at.y = yz - xw;
    rotation->at.z = 1.0f - (xx + yy);
    rotation->pos.x = 0.0f;
    rotation->pos.y = 0.0f;
    rotation->pos.z = 0.0f;
    rotation->flags = 3;

    func_003e0e20(output, rotation, 2);
    func_003e0f40(rotation);
    RwMatrixTranslate((RwMatrix*)output, (const RwV3d*)&transform->translation, 2);
    if (transform->model != NULL)
    {
        func_003e0e20(output, func_003e9700(transform->model), 2);
    }
}
#endif /* P4_UNIT_0036ABD0 */

#if defined(P4_UNIT_0036B470)
/* Source unit: src/Main/Social/gc_model_0036b470.c (1 function markers) */
#include "type.h"

typedef struct RwV3d {
    f32 x;
    f32 y;
    f32 z;
} RwV3d;
typedef struct RwMatrix {
    RwV3d right;
    u32 flags;
    RwV3d up;
    u32 pad1;
    RwV3d at;
    u32 pad2;
    RwV3d pos;
    u32 pad3;
} RwMatrix;

extern const RwV3d D_0064E4D0;
extern void* func_003e0f80(void);
extern RwMatrix* RwMatrixRotate(RwMatrix* matrix, const RwV3d* axis, f32 angle, u32 combine);
extern void func_00410420(void* vertices, u32 count, void* matrix, u32 stride);
extern void (*D_00887300[])(u32 state, u32 value);
extern u16 D_00884690[];
extern void func_00410520(u32 primitive, void* indices, u32 count);
extern void func_004104d0(void);
extern void func_003e0f40(void* matrix);

// FUN_0036B470
void func_0036b470(u32* work, const f32* vertices)
{
    RwV3d axis;
    RwMatrix* matrix;
    u32* destination;
    s32 count;
    const u32* source;
    u32 x;
    u32 y;

    axis = D_0064E4D0;
    if ((*work & 1) != 0) {
        matrix = (RwMatrix*)func_003e0f80();
        count = 8;
        source = (const u32*)vertices;
        destination = (u32*)matrix;
        do {
            x = source[0];
            y = source[1];
            source += 2;
            count -= 1;
            destination[0] = x;
            destination[1] = y;
            destination += 2;
        } while (count > 0);
        RwMatrixRotate(matrix, &axis, 180.0f, 1);
    } else {
        matrix = (RwMatrix*)vertices;
    }
    func_00410420(work + 1, 0x44, matrix, 3);
    (*D_00887300)(1, 0);
    func_00410520(3, D_00884690, 0x138);
    func_004104d0();
    if ((*work & 1) != 0) {
        func_003e0f40(matrix);
    }
}
#endif /* P4_UNIT_0036B470 */

#include "primitive_queue_internal.h"
#include "kwln_task_internal.h"
/* Whole-file translation unit (functions contiguous in retail). */
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "scene_event_internal.h"
#include "rw/plcore/barenderstate.h"
extern u8 D_00887300_abs[];
typedef s32 (*KDrawFunc)(RwRenderState state, void *value);
extern s32 RpSkyRenderStateSet(s32 state, void *value);
extern void primAxisLine3D(f32 mat, u8 *length, s32 saveAndRestoreRenderState);
extern void primCylinderLine3D(f32 *position, f32 radius, f32 height, u8 *color, s32 setStates);
extern u8 iGpffff9dd4;
typedef struct { u8 c[4]; } Rgba8;

typedef struct RwV3d
{
    f32 x;
    f32 y;
    f32 z;
} RwV3d;

typedef struct RwMatrix
{
    RwV3d right;    // 0x00
    u32 flags;      // 0x0c
    RwV3d up;       // 0x10
    u32 pad1;       // 0x1c
    RwV3d at;       // 0x20
    u32 pad2;       // 0x2c
    RwV3d pos;      // 0x30
    u32 pad3;       // 0x3c
} RwMatrix;

extern RwMatrix* func_003e0670(RwMatrix* matrixOut, RwMatrix* matrixIn);
extern f32 func_0044b950(f32 left, f32 right);
extern f32 gPI;

extern void chkmemAllocSiteTag(u8 *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);

extern void *PrimAllocQueueNode(void);
extern void PrimAppendNode(void *list, void *node);
extern void (*jtbl_008873EC[])(void *);
extern void primSphereLine3D(u8 *center, f32 radius, u8 *color, s32 preserveState);
extern u8 D_005EFBC8[];
extern u8 D_005EFBD8[];
extern u8 D_005EFBE8[];
extern u8 D_005EFBF8[];
extern u8 D_005EFC08[];
extern s32 FldEventQueueDraw(u8 *);
extern void KDraw_GroupTaskDestroy(u8 *);
extern void KDraw_DrawCylinder(u8 *, u8 *);
extern void KDraw_DrawAxes(u8 *, u8 *);

/* Allocation extents and setters below establish these task-work layouts. */
typedef struct KDrawGroupWork {
    u32 flags;
    s32 unk04;
    Rgba8 color;
    s32 curve;
    u8 pad10[0x100];
    s32 drawList;
} KDrawGroupWork;
typedef struct KDrawSphereWork {
    u32 flags;
    SVec3 center;
    Rgba8 color;
    s32 drawList;
} KDrawSphereWork;
typedef struct KDrawCylinderWork {
    u32 flags;
    SVec3 center;
    f32 radius;
    f32 height;
    s32 drawList;
} KDrawCylinderWork;
typedef struct KDrawAxesWork {
    RwMatrix matrix;
    u8 pad40[4];
    s32 enabled;
    Rgba8 color;
    void *drawList;
} KDrawAxesWork;

/* Normalize the matrix before extracting yaw in degrees from its right axis. */
// FUN_0014B5D0
f32 KDraw_MatrixYawDeg(const RwMatrix* matrix)
{
    RwMatrix normalized;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    return (-func_0044b950(normalized.right.z, normalized.right.x) * 180.0f) / gPI;
}

/* Normalize the matrix before extracting pitch in degrees from its up axis. */
// FUN_0014B660
f32 KDraw_MatrixPitchDeg(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    up = &normalized.up;
    return (-func_0044b950(up->z, up->y) * 180.0f) / gPI;
}

/* Normalize the matrix before extracting roll in degrees from its up axis. */
// FUN_0014B6F0
f32 KDraw_MatrixRollDeg(const RwMatrix* matrix)
{
    RwMatrix normalized;
    RwV3d* up;

    normalized = *matrix;
    func_003e0670(&normalized, &normalized);
    up = &normalized.up;
    return (func_0044b950(up->x, up->y) * 180.0f) / gPI;
}

/* Create a debug curve-marker task and record its curve and primitive-queue handles. */
// FUN_0014D510
s32 KDraw_CreateGroupTask(s32 parent, s32 curve, s32 drawList)
{
    u8 *workMemory;
    s32 taskHandle;

    chkmemAllocSiteTag(D_005EFBC8, 0x72);
    workMemory = D_008873F4[0](1, 0x114, 0x40000);
    if (workMemory == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005EFBD8), 0xF, 0, 0, FldEventQueueDraw, KDraw_GroupTaskDestroy, (u8 *)(workMemory));
    ((KDrawGroupWork *)workMemory)->curve = curve;
    ((KDrawGroupWork *)workMemory)->unk04 = 0x14;
    ((KDrawGroupWork *)workMemory)->drawList = drawList;
    return taskHandle;
}

// FUN_0014D5E0
void KDraw_SetGroupFlags(u8 *task, u32 flags)
{
    ((KDrawGroupWork *)((KwlnTask *)task)->work)->flags = flags;
}

// FUN_0014D5F0
void KDraw_SetGroupColor(u8 *task, u8 *color) {
    u8 *p = ((KwlnTask *)task)->work;

    ((KDrawGroupWork *)p)->color = *(Rgba8 *)color;
}

// FUN_0014D620
void KDraw_DrawSphere(u8 *queue, u8 *work)
{
    primSphereLine3D(work + 4, 10.0f, work + 0x10, 1);
}

/* Enqueue the sphere draw callback only while its work flags are nonzero. */
// FUN_0014D660
s32 KDraw_UpdateSphere(u8 *task)
{
    u8 *work;
    u8 *obj;

    work = ((KwlnTask *)task)->work;
    if ((s32)((KDrawSphereWork *)work)->flags == 0) {
        return 0;
    }
    obj = PrimAllocQueueNode();
    ((PrimQueueNode *)obj)->callback = KDraw_DrawSphere;
    ((PrimQueueNode *)obj)->argument.data = work;
    PrimAppendNode((void *)((KDrawSphereWork *)work)->drawList, obj);
    return 0;
}

// FUN_0014D6D0
void KDraw_DestroySphere(u8 *task)
{
    jtbl_008873EC[0]((void *)((KwlnTask *)task)->work);
}

/* Create a debug sphere task attached to the supplied primitive queue. */
// FUN_0014D700
s32 KDraw_CreateSphereTask(s32 parent, s32 drawList)
{
    u8 *workMemory;
    s32 taskHandle;

    chkmemAllocSiteTag(D_005EFBC8, 0x16E);
    workMemory = D_008873F4[0](1, 0x18, 0x40000);
    if (workMemory == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005EFBE8), 0xF, 0, 0, KDraw_UpdateSphere, KDraw_DestroySphere, (u8 *)(workMemory));
    ((KDrawSphereWork *)workMemory)->drawList = drawList;
    return taskHandle;
}

// FUN_0014D7C0
void KDraw_SetSphereFlags(u8 *task, u32 flags)
{
    ((KDrawSphereWork *)((KwlnTask *)task)->work)->flags = flags;
}

// FUN_0014D7D0
void KDraw_SetSphereCenter(u8 *task, u8 *center) {
    ((KDrawSphereWork *)((KwlnTask *)task)->work)->center = *(SVec3 *)center;
}
// FUN_0014D800
void KDraw_SetSphereColor(u8 *task, u8 *color) {
    u8 *p = ((KwlnTask *)task)->work;

    ((KDrawSphereWork *)p)->color = *(Rgba8 *)color;
}

/* Retail computes the position pointer and reads both floats before loading the color address; this
 * argument order cannot be reproduced from C. */
// FUN_0014D830
void KDraw_DrawCylinder(u8 *queue, u8 *work)
{
    primCylinderLine3D((f32 *)(work + 4), ((KDrawCylinderWork *)work)->radius, ((KDrawCylinderWork *)work)->height,
                  &iGpffff9dd4, 1);
}
/* Enqueue the cylinder draw callback only while its work flags are nonzero. */
// FUN_0014D870
s32 KDraw_UpdateCylinder(u8 *task)
{
    u8 *work;
    u8 *obj;

    work = ((KwlnTask *)task)->work;
    if ((s32)((KDrawCylinderWork *)work)->flags == 0) {
        return 0;
    }
    obj = PrimAllocQueueNode();
    ((PrimQueueNode *)obj)->callback = KDraw_DrawCylinder;
    ((PrimQueueNode *)obj)->argument.data = work;
    PrimAppendNode((void *)((KDrawCylinderWork *)work)->drawList, obj);
    return 0;
}

// FUN_0014D8E0
void KDraw_DestroyCylinder(u8 *task)
{
    jtbl_008873EC[0]((void *)((KwlnTask *)task)->work);
}

/* Create a debug cylinder task attached to the supplied primitive queue. */
// FUN_0014D910
s32 KDraw_CreateCylinderTask(s32 parent, s32 drawList)
{
    u8 *workMemory;
    s32 taskHandle;

    chkmemAllocSiteTag(D_005EFBC8, 0x1DF);
    workMemory = D_008873F4[0](1, 0x1C, 0x40000);
    if (workMemory == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)(D_005EFBF8), 0xF, 0, 0, KDraw_UpdateCylinder, KDraw_DestroyCylinder, (u8 *)(workMemory));
    ((KDrawCylinderWork *)workMemory)->drawList = drawList;
    return taskHandle;
}

// FUN_0014D9D0
void KDraw_SetCylinderFlags(u8 *task, u32 flags)
{
    ((KDrawCylinderWork *)((KwlnTask *)task)->work)->flags = flags;
}

// FUN_0014D9E0
void KDraw_SetCylinderCenter(u8 *task, u8 *center) {
    ((KDrawCylinderWork *)((KwlnTask *)task)->work)->center = *(SVec3 *)center;
}
// FUN_0014DA10
void KDraw_SetCylinderRadius(u8 *task, f32 radius)
{
    ((KDrawCylinderWork *)((KwlnTask *)task)->work)->radius = radius;
}

// FUN_0014DA20
void KDraw_SetCylinderHeight(u8 *task, f32 height)
{
    ((KDrawCylinderWork *)((KwlnTask *)task)->work)->height = height;
}

/* Set the immediate-render states, then draw axes and a sphere at the matrix position. */
// FUN_0014DA30
void KDraw_DrawAxes(u8 *queue, u8 *work)
{
    KDrawFunc *tbl = (KDrawFunc *)D_00887300_abs;

    (*tbl)((RwRenderState)7, (void *)2);
    (*tbl)((RwRenderState)6, (void *)1);
    (*tbl)((RwRenderState)8, (void *)0);
    (*tbl)((RwRenderState)0xC, (void *)1);
    RpSkyRenderStateSet(2, (void *)0x44);
    RpSkyRenderStateSet(3, (void *)0x717FB);
    primAxisLine3D(60.0f, work, 1);
    primSphereLine3D(work + 0x30, 20.0f, work + 0x48, 1);
}
/* Enqueue the axes callback only while the axes work is enabled. */
// FUN_0014DB10
s32 KDraw_UpdateAxes(u8 *task)
{
    u8 *work;
    u8 *obj;

    work = ((KwlnTask *)task)->work;
    if (((KDrawAxesWork *)work)->enabled == 0) {
        return 0;
    }
    obj = PrimAllocQueueNode();
    ((PrimQueueNode *)obj)->callback = KDraw_DrawAxes;
    ((PrimQueueNode *)obj)->argument.data = work;
    PrimAppendNode(((KDrawAxesWork *)work)->drawList, obj);
    return 0;
}

// FUN_0014DB80
void KDraw_DestroyAxes(u8 *task)
{
    jtbl_008873EC[0]((void *)((KwlnTask *)task)->work);
}

/* Parent is forwarded to task creation; drawList is retained for PrimAppendNode. */
// FUN_0014DBB0
s32 KDraw_CreateAxesTask(void *parent, void *drawList)
{
    u8 *workMemory;
    s32 taskHandle;

    chkmemAllocSiteTag(D_005EFBC8, 0x30E);
    workMemory = D_008873F4[0](1, 0x50, 0x40000);
    if (workMemory == NULL) {
        return 0;
    }
    taskHandle = (s32)kwlnTaskCreateChild(parent, (const void *)(D_005EFC08), 0xF, 0, 0, KDraw_UpdateAxes, KDraw_DestroyAxes, (u8 *)(workMemory));
    ((KDrawAxesWork *)workMemory)->matrix.at.z = 1.0f;
    ((KDrawAxesWork *)workMemory)->matrix.up.y = 1.0f;
    ((KDrawAxesWork *)workMemory)->matrix.right.x = 1.0f;
    ((KDrawAxesWork *)workMemory)->matrix.up.x = 0;
    ((KDrawAxesWork *)workMemory)->matrix.right.z = 0;
    ((KDrawAxesWork *)workMemory)->matrix.right.y = 0;
    ((KDrawAxesWork *)workMemory)->matrix.at.y = 0;
    ((KDrawAxesWork *)workMemory)->matrix.at.x = 0;
    ((KDrawAxesWork *)workMemory)->matrix.up.z = 0;
    ((KDrawAxesWork *)workMemory)->matrix.pos.z = 0;
    ((KDrawAxesWork *)workMemory)->matrix.pos.y = 0;
    ((KDrawAxesWork *)workMemory)->matrix.pos.x = 0;
    ((KDrawAxesWork *)workMemory)->matrix.flags |= 0x20003;
    ((KDrawAxesWork *)workMemory)->color.c[0] = 0xFF;
    ((KDrawAxesWork *)workMemory)->color.c[1] = 0;
    ((KDrawAxesWork *)workMemory)->color.c[2] = 0;
    ((KDrawAxesWork *)workMemory)->color.c[3] = 0xFF;
    ((KDrawAxesWork *)workMemory)->drawList = drawList;
    ((KDrawAxesWork *)workMemory)->enabled = 1;
    return taskHandle;
}

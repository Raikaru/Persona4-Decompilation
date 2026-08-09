/* Source unit: src/Kosaka/k_view_004577d0.c */
#include "include_asm.h"
#include "type.h"

/* Ported from P3FES src/Kosaka/k_view.c K_View_SetFov FUN_001a4580 (verified
 * MATCH there). Globals map to P4 retail: gPI 00761174, gAspectRatio 0076111c. */
typedef struct RwV2d
{
    f32 x;
    f32 y;
} RwV2d;

typedef struct RwCamera
{
    u8 unknown00[0x68];
    RwV2d viewWindow; /* 0x68 */
} RwCamera;

#define DEG_TO_RAD(deg) (gPI * (deg) / 180.0f)

extern f32 gPI;
extern f32 gAspectRatio;
extern f32 tanf(f32 x);
extern RwCamera* RwCameraSetViewWindow(RwCamera* camera, const RwV2d* viewWindow);

#define RAD_TO_DEG(rad) (gRadToDegFactor * (rad))

extern f32 gRadToDegFactor;
extern f32 atanf(f32 x);

/* Ported from P3FES src/Kosaka/k_view.c FUN_001a4050 (verified MATCH there). */
typedef struct KwlnTask KwlnTask;
typedef void (*KWindowEntryCallback)(void* value);
typedef struct KWindowEntry
{
    s32 id;                         /* 0x000 */
    s32 type;                       /* 0x004 */
    char name[0x100];               /* 0x008 */
    char text[0x100];               /* 0x108 */
    s32 intValue;                   /* 0x208 */
    f32 floatValue;                 /* 0x20c */
    s32 minValue;                   /* 0x210 */
    s32 maxValue;                   /* 0x214 */
    s32 flags;                      /* 0x218 */
    KWindowEntryCallback callback;  /* 0x21c */
    void* callbackValue;            /* 0x220 */
    struct KWindowEntry* previous;  /* 0x224 */
    struct KWindowEntry* next;      /* 0x228 */
} KWindowEntry;

extern KWindowEntry* func_00470d10(KwlnTask* task, s32 id);



// FUN_004577D0
void K_View_SetFov(RwCamera* camera, f32 fov)
{
    RwV2d viewWindow;

    viewWindow.y = tanf(DEG_TO_RAD(fov) / 2.0f);
    viewWindow.x = gAspectRatio * viewWindow.y;

    RwCameraSetViewWindow(camera, &viewWindow);
}



// FUN_00457850
f32 K_View_GetFov(RwCamera* camera)
{
    f32 x;
    RwV2d* viewWindow;

    viewWindow = &camera->viewWindow;

    // Retained unused retail call; removing it changes the matched instruction sequence.
    atanf(viewWindow->x);
    x = atanf(viewWindow->y) * 2.0f;

    return RAD_TO_DEG(x);
}



// FUN_00470A90
void func_00470a90(KwlnTask* task, u32 id, KWindowEntryCallback callback)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_00470d10(task, id);
    if (entry != NULL)
    {
        entry->callback = callback;
    }
}



// FUN_00470AD0
INCLUDE_ASM("asm/nonmatchings/k_view", func_00470ad0);
// FUN_00470B40
INCLUDE_ASM("asm/nonmatchings/k_view", func_00470b40);
// FUN_00470BD0
s32* func_00470bd0(KwlnTask* task, u32 id)
{
    KWindowEntry* entry;

    entry = (KWindowEntry*)func_00470d10(task, id);
    if (entry != NULL)
    {
        goto found;
    }
    return NULL;
found:
    return &entry->intValue;
}

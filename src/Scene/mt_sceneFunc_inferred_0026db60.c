#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
#include "scene_render_internal.h"
#include "scene_resource_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern void MT_Scene_StopShake();

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 MT_SceneManager_TaskUpdate(u8 *unusedTask);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern void MT_Scene_ShakeStopTask(u8 *unusedTask);
extern s32 MT_SceneManager_DrawUpdate(u8 *unusedTask);
extern u8 *MT_Scene_GetResListHead(s32 resourceType);
extern void mtSceneDrawSortedUnits(u8 *resource);
extern void MT_Scene_UpdateShake(void);
extern void MT_Scene_UpdateResource(u8 *resourceData);
extern void MT_Scene_UpdateCameraResource(u8 *resource);
extern void mdlEffectFlushWithTable(void *table, s32 effect);
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *, s32, s32,
                           s32 (*)(u8 **arg0, u8 **arg1));
extern void chkmemAllocSiteTag(void *file, s32 line);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *memcpy(void *, const void *, u32);
extern u8 D_0088152F[];
typedef struct { s32 value[19]; } Code1_00267800ShapeTable;
extern Code1_00267800ShapeTable D_00638FD0;
typedef union { f32 value[19]; u32 words[19]; } Code1_00267800ScaleTable;
extern Code1_00267800ScaleTable D_00639020;
extern f32 fGpffff8218;
extern f32 fGpffff84a4;
extern f32 fGpffff8574;
extern f32 fGpffff82fc;
typedef struct {
    u8 pad18[0x18];
    s32 field18;
    s32 field1C;
    s32 field20;
} Code1_00263220State;

extern void PrimDrawContour(f32 x, f32 y, f32 depth,
                          s32 rgb, s32 alpha, s32 unusedMode, s32 shape,
                          s32 originX, s32 originY,
                          f32 rotation, f32 scaleX, f32 scaleY);
extern char iGpffffa6c4;
extern s32 (*D_00887300[])(RwRenderState state, void *value);
extern u8 D_00881530[];
extern u8 D_0063BA30[];
typedef struct { s32 a, b, c, d; } Quad4;
typedef void (*Code1_0026Callback)(f32, f32, f32, s32, u8, s8 *, s32, s32, u8 *);
static inline u32 *rbRingNextNode(s32 offset, u32 *base)
{
    return (u32 *)((u8 *)base + offset + 8);
}



extern u8 D_00637420[];





extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void calDrawWeather(s32 x, s32 y, f32 depth, u8 opacity,
                           s32 weather, s32 highlight, f32 scaleX, f32 scaleY,
                           s32 clipLeft, s32 clipWidth, s32 font,
                           s32 forcedHighlight);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;
extern f32 RwV3dLength(f32 *);
extern u8 *func_003e9700(s32);
extern u8 *kwlnGetCamera(void);
extern void mdlEffectBuildObjectMatrix(s32 object, f32 *matrix);

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0026; members 0026db60-0026e010 */

extern f32 D_007612C4;
/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. shdSpriteDrawNowEx's
 * colour parameter is declared u32 here (H011): retail converts arg2 for each
 * call and keeps the per-case colour copies in $fp/$s7. */
#pragma push
#pragma pop
#pragma push
#pragma pop
#pragma push
#pragma pop
/* measured: optimization-level probe for 00263220 register colouring */
/* measured: closes optimization-level probe for 00263220 */
/* measured: opt_loop_invariants on hoists (u8)opacity into the sq/lq spill retail has (269 -> 253 words on the shape before the statement-ordered font word; off it stays inside the fade block). */
#pragma push
#pragma pop
/* The switch arms are in retail's jump-table order. Locals whose live ranges
 * are disjoint share one variable (temp_18_2/temp_3, temp_17_10/temp_16_2,
 * temp_19_2/temp_17_3, fadeAlpha/temp_17_9, temp_22/temp_17), as retail's
 * register reuse across the cases shows. In case 7's day loop the date is
 * `temp_20` and the `* 0x5E` column is `var_2`, both dead outside that loop:
 * retail's register numbering follows which variable each value lives in, and
 * these give the $s3/$s4/$s5 order of the product, date and font word. The
 * render-state table goes through a u32 local, both fade rectangles are
 * {x,y,w,h} structs copied into the 16-byte argument, the case-5 and case-7
 * fallback tails are separate copies, and `temp_3_2 > 1` gives the slti $at
 * form. opt_lifetimes on is measured (102 -> 85 edits without the other levers). */
#pragma push
#pragma pop
/* measured: closes the optimization_level bracket (nd 0). */
/* Copy complete table objects; renderer callbacks may change the item index. */
/* measured: 1296B/1296B.  Scalar out-parameters and CefV3 locals give the
   retail frame; the s8 count local and the named segment index give the
   hoisted point base under opt_loop_invariants; the control-point counters
   are block-scoped so the sampling counter k is coloured first. */
#pragma push
/* measured: without it the point base is recomputed per iteration (271). */
#pragma pop
/* measured: optimization_level 1 register-coloring probe for func_0026db60. */
/* measured: func_0026db60 MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 1
/* measured: opt_propagation off probe for func_0026db60 loop test ordering. */
// Intent: Update step of the SceneManager task, which holds the scene resource lists (retail task name "SceneManager Task") [inferred]
// FUN_0026DB60
s32 MT_SceneManager_TaskUpdate(u8 *unusedTask)
{
    s32 resourceType;
    u8 *resource;
    s32 selected;
    s32 enabled;
    u8 *camera;
    MT_Scene_UpdateShake();
    resourceType = 1;
    goto outer_test;
outer_body:
    resource = MT_Scene_GetResListHead(resourceType);
    goto inner_test;
inner_body:
    MT_Scene_UpdateResource(resource);
    resource = *(u8 * *)&((ResrcHeader *)resource)->next;
inner_test:
    if (resource != NULL) {
        goto inner_body;
    }
    resourceType += 1;
outer_test:
    if (resourceType < 0x16) {
        goto outer_body;
    }
    camera = MT_Scene_GetResListHead(7);
    enabled = 1;
    goto second_test;
second_body:
    selected = ((ResrcRecord *)camera)->cameraRes[0];
    if (selected == enabled) {
        MT_Scene_UpdateCameraResource(camera);
        goto second_exit;
    }
    camera = *(u8 * *)&((ResrcHeader *)camera)->next;
second_test:
    if (camera != NULL) {
        goto second_body;
    }
second_exit:
    return 0;
}

/* measured: closes opt_propagation off probe for func_0026db60. */
/* measured: closes optimization_level 1 register-coloring probe for func_0026db60. */
/* measured: mtSceneUnitDepthCompare, rbRingBufCreate MATCH -> MISMATCH without this pragma. */
#pragma optimization_level 2
// FUN_0026DC30
void MT_Scene_ShakeStopTask(u8 *unusedTask)
{
    MT_Scene_StopShake();
}

/* measured: opt_propagation off probe for mtSceneUnitDepthCompare float load scheduling. */
/* measured: mtSceneUnitDepthCompare MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_0026DC50
/* Compare effect-resource distances from the active camera, truncating the distance difference to s32. */
s32 mtSceneUnitDepthCompare(u8 **left, u8 **right)
{
    struct DC50Frame {
        f32 rightMatrixStart[3];
        u8 pad4C[0x24];
        f32 rightMatrixPosition[3];
        u8 pad7C[4];
        f32 leftMatrixStart[3];
        u8 pad8C[0x24];
        f32 leftMatrixPosition[3];
        u8 padBC[4];
        f32 cameraPosition[3];
        u8 padCC[4];
        f32 rightDelta[3];
        u8 padDC[4];
        f32 leftDelta[3];
        u8 padEC[4];
    } frame;
    f32 leftDistance;
    f32 cameraY;
    f32 cameraZ;
    f32 cameraX;
    f32 *leftPosition;
    f32 *rightPosition;
    f32 savedCameraY;
    f32 savedCameraZ;
    u8 *rightResource;
    u8 *cameraOrResource;

    cameraOrResource = kwlnGetCamera();
    cameraOrResource = func_003e9700(((SceneRenderObject *)cameraOrResource)->frame);
    cameraX = ((struct RwMatrix *)cameraOrResource)->pos.x;
    cameraY = ((struct RwMatrix *)cameraOrResource)->pos.y;
    cameraZ = ((struct RwMatrix *)cameraOrResource)->pos.z;
    frame.cameraPosition[0] = cameraX;
    frame.cameraPosition[1] = cameraY;
    frame.cameraPosition[2] = cameraZ;
    rightResource = *right;
    cameraOrResource = *left;
    mdlEffectBuildObjectMatrix(*(s32 *)&((SceneEffectUpdate *)cameraOrResource)->effect, frame.leftMatrixStart);
    mdlEffectBuildObjectMatrix(*(s32 *)&((ResrcRecord *)rightResource)->slotHandle[1], frame.rightMatrixStart);
    leftPosition = frame.leftMatrixPosition;
    rightPosition = frame.rightMatrixPosition;
    frame.leftDelta[0] = leftPosition[0] - frame.cameraPosition[0];
    savedCameraY = frame.cameraPosition[1];
    frame.leftDelta[1] = leftPosition[1] - savedCameraY;
    savedCameraZ = frame.cameraPosition[2];
    frame.leftDelta[2] = leftPosition[2] - savedCameraZ;
    frame.rightDelta[0] = rightPosition[0] - frame.cameraPosition[0];
    frame.rightDelta[1] = rightPosition[1] - frame.cameraPosition[1];
    frame.rightDelta[2] = rightPosition[2] - frame.cameraPosition[2];
    leftDistance = RwV3dLength(frame.leftDelta);
    return (s32)(leftDistance - RwV3dLength(frame.rightDelta));
}

/* measured: closes opt_propagation off probe for mtSceneUnitDepthCompare. */
// FUN_0026DD60
/* Collect active mode-0 effects, sort them by camera distance, queue them and release the temporary array. */
void mtSceneDrawSortedUnits(u8 *resource)
{
    s32 outputIndex;
    u32 *result;
    s32 count;
    u8 *base;
    s32 index;

    count = 0;
    base = resource;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)&((ResrcHeader *)resource)->flags & 2) {
        if (*(s32 *)&((ResrcRecord *)resource)->slotHandle[1] != 0) {
            switch (*(s8 *)&((ResrcRecord *)resource)->slotHandle[0]) {
            case 0:
                count += 1;
                break;
            }
        }
    }
loop_7_next:
    resource = *(u8 * *)&((ResrcHeader *)resource)->next;
loop_7_test:
    if (resource != NULL) {
        goto loop_7_body;
    }
    if (count != 0) {
        chkmemAllocSiteTag(D_0063B580, 0x96);
        result = (u32 *)jtbl_008873E8[0](count * 4, 0x40000);
        index = 0;
        resource = base;
        goto loop_16_test;
loop_16_body:
        if (*(s32 *)&((ResrcHeader *)resource)->flags & 2) {
            if (*(s32 *)&((ResrcRecord *)resource)->slotHandle[1] != 0) {
                switch (*(s8 *)&((ResrcRecord *)resource)->slotHandle[0]) {
                case 0:
                    result[index] = (u32)resource;
                    index += 1;
                    break;
                }
            }
        }
loop_16_next:
        resource = *(u8 * *)&((ResrcHeader *)resource)->next;
        goto loop_16_test;
loop_16_test:
        if (resource != NULL) {
            goto loop_16_body;
        }
        qsort(result, count, 4, mtSceneUnitDepthCompare);
        outputIndex = 0;
        goto loop_19_test;
loop_19_body:
        mdlEffectFlushWithTable(D_005DC7D0,
                      *(s32 *)&((ResrcRecord *)result[outputIndex])->slotHandle[1]);
        outputIndex += 1;
loop_19_test:
        if (outputIndex < count) {
            goto loop_19_body;
        }
        jtbl_008873EC[0]((u8 *)result);
    }
}

// Intent: Draw step of the SceneManager task (retail task name "SceneManager Draw"), walking the resource list [inferred]
// FUN_0026DEE0
s32 MT_SceneManager_DrawUpdate(u8 *unusedTask)
{
    s32 effectHandle;
    s8 drawMode;
    u8 *resource;

    resource = MT_Scene_GetResListHead(6);
    mtSceneDrawSortedUnits(resource);
    goto loop_test;
loop_body:
    if (*(s32 *)&((ResrcHeader *)resource)->flags & 2) {
        effectHandle = *(s32 *)&((ResrcRecord *)resource)->slotHandle[1];
        if (effectHandle != 0) {
            drawMode = *(s8 *)&((ResrcRecord *)resource)->slotHandle[0];
            switch (drawMode) {
            case 0:
                break;
            case 1:
                mdlEffectFlushWithTable(D_005DC824, effectHandle);
                break;
            }
        }
    }
    resource = *(u8 * *)&((ResrcHeader *)resource)->next;
loop_test:
    if (resource != NULL) {
        goto loop_body;
    }
    return 0;
}

// Intent: Creates the SceneManager task pair (retail names "SceneManager Task" and "SceneManager Draw") and returns the parent task [inferred]
// FUN_0026DF80
s32 MT_SceneManager_Create(void)
{
    s32 parentTask;

    parentTask = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_0063B5A0), 0x10, 0, 0, MT_SceneManager_TaskUpdate, MT_Scene_ShakeStopTask, (u8 *)(0));
    (s32)kwlnTaskCreateChild((void *)(parentTask), (const void *)(D_0063B5C0), 0x10, 0, 0, MT_SceneManager_DrawUpdate, 0, (u8 *)(0));
    return parentTask;
}

/* Allocate a header and count+1 linked records, including the wrap record.
   measured: a u32 allocation base expresses the header as one word and
   gives retail's saved-register assignment without pragmas. Keep the
   pointer-value copy call and byte-stride helper. Exact 204B plus 4B zero tail. */
// Intent: Allocates a ring buffer of count nodes at size-byte stride (rbRingBuf.c alloc site) [inferred]
// FUN_0026E010
s32 rbRingBufCreate(s32 size, s32 count)
{
    u8 *allocated;
    u32 *base;
    u32 *node;
    u32 *next;
    s32 i;

    chkmemAllocSiteTag(D_0063B5D8, 0x36);
    allocated = jtbl_008873E8[0]((size + 8) * (count + 1) + 4, 0x40000);
    base = (u32 *)allocated;
    memcpy(base, &allocated, 4);
    node = base + 1;
    i = 0;
    while (i < count) {
        node[0] = i;
        next = rbRingNextNode(size, node);
        node[1] = (u32)next;
        node = next;
        i++;
    }
    node[0] = count;
    node[1] = (u32)(base + 1);
    return (s32)(base + 1);
}


#include "include_asm.h"
#include "list_item_internal.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "rw/plcore/barenderstate.h"
#include "primitive_point_buffer.h"
#include "scene_event_internal.h"
extern s32 iGpffffb4bc;
extern s32 iGpffffa730;
extern void MT_Scene_StopShake();

extern u8 D_0063B5A0[];
extern u8 D_0063B5C0[];
extern s32 MT_SceneManager_TaskUpdate(u8 *task);
extern f32 fGpffff82d4;
extern f32 fGpffff83d0;
extern f32 fGpffff842c;
extern void MT_Scene_ShakeStopTask(u8 *task);
extern s32 MT_SceneManager_DrawUpdate(u8 *task);
extern u8 *MT_Scene_GetResListHead(s32 arg0);
extern void mtSceneDrawSortedUnits(u8 *arg0);
extern void MT_Scene_UpdateShake(void);
extern void MT_Scene_UpdateResource(u8 *arg0);
extern void MT_Scene_UpdateCameraResource(u8 *arg0);
extern void func_004b11d0(void *arg0, s32 arg1);
extern char D_005DC824[];
extern char D_0063B5D8[];
extern char D_005DC7D0[];
extern char D_0063B580[];
extern void qsort(u32 *arg0, s32 arg1, s32 arg2,
                           s32 (*arg3)(u8 **arg0, u8 **arg1));
extern void chkmemAllocSiteTag(void *arg0, s32 arg1);
extern u8 *(*jtbl_008873E8[])(s32 arg0, s32 arg1);
extern void *memcpy(void *arg0, const void *arg1, u32 arg2);
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
static inline f32 mtSceneMulF32(f32 left, f32 right)
{
    return left * right;
}
extern void PrimDrawContour(f32 fparg0, f32 fparg1, f32 fparg2,
                          s32 arg0, s32 arg1, s32 arg2, s32 arg3,
                          s32 arg4, s32 arg5,
                          f32 fparg3, f32 fparg4, f32 fparg5);
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
static inline u8 *mtSceneBytePairAt(u8 *base, u32 index)
{
    return base + index;
}


extern u8 D_00637420[];





extern void (*jtbl_008873EC[])(void *);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00638FA0[];
extern u8 D_00638FB0[];
extern u8 D_00638F90[];
extern char D_00637348[];
extern void calDrawWeather(s32 arg0, s32 arg1, f32 fparg0, u8 arg2,
                           s32 arg3, s32 arg4, f32 fparg1, f32 fparg2,
                           s32 arg5, s32 arg6, s32 arg7,
                           s32 arg_sp0);
extern char D_0063BA50[];
extern char D_0063BA80[];
extern s32 D_008815B0[];
extern u8 iGpffffa734;
extern f32 RwV3dLength(f32 *arg0);
extern u8 *func_003e9700(s32 arg0);
extern u8 *kwlnGetCamera(void);
extern void func_004b1470(s32 arg0, f32 *arg1);

/* Source unit: src/promoted/code1_0026.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0026.c; members 0026db60-0026e010 */

extern f32 D_007612C4;
/* Three trail-segment layouts (arg4 0/1/2). The 0xC0-byte point tables are
 * struct copies; each loop's i = 0 precedes the invariant scale products,
 * which opt_loop_invariants hoists while the (s16) conversion of the second
 * product stays in the loop as in retail. The closing call's position
 * arguments are computed before its D_007612C4 products. func_0025f430's
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
    s32 var_17;
    u8 *var_16;
    s32 temp_4;
    s32 temp_3;
    u8 *var_2;
    MT_Scene_UpdateShake();
    var_17 = 1;
    goto outer_test;
outer_body:
    var_16 = MT_Scene_GetResListHead(var_17);
    goto inner_test;
inner_body:
    MT_Scene_UpdateResource(var_16);
    var_16 = *(u8 **)(var_16 + 0x138);
inner_test:
    if (var_16 != NULL) {
        goto inner_body;
    }
    var_17 += 1;
outer_test:
    if (var_17 < 0x16) {
        goto outer_body;
    }
    var_2 = MT_Scene_GetResListHead(7);
    temp_3 = 1;
    goto second_test;
second_body:
    temp_4 = *(s32 *)(var_2 + 0x148);
    if (temp_4 == temp_3) {
        MT_Scene_UpdateCameraResource(var_2);
        goto second_exit;
    }
    var_2 = *(u8 **)(var_2 + 0x138);
second_test:
    if (var_2 != NULL) {
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
s32 mtSceneUnitDepthCompare(u8 **arg0, u8 **arg1)
{
    struct DC50Frame {
        f32 v40[3];
        u8 pad4C[0x24];
        f32 v70[3];
        u8 pad7C[4];
        f32 v80[3];
        u8 pad8C[0x24];
        f32 vB0[3];
        u8 padBC[4];
        f32 vC0[3];
        u8 padCC[4];
        f32 vD0[3];
        u8 padDC[4];
        f32 vE0[3];
        u8 padEC[4];
    } frame;
    f32 temp_f20;
    f32 temp_f2;
    f32 temp_f1;
    f32 temp_f0;
    f32 *temp_B0;
    f32 *temp_70;
    f32 temp_c1;
    f32 temp_c2;
    u8 *temp_16;
    u8 *temp_2;

    temp_2 = kwlnGetCamera();
    temp_2 = func_003e9700(*(s32 *)(temp_2 + 4));
    temp_f0 = *(f32 *)(temp_2 + 0x30);
    temp_f2 = *(f32 *)(temp_2 + 0x34);
    temp_f1 = *(f32 *)(temp_2 + 0x38);
    frame.vC0[0] = temp_f0;
    frame.vC0[1] = temp_f2;
    frame.vC0[2] = temp_f1;
    temp_16 = *arg1;
    temp_2 = *arg0;
    func_004b1470(*(s32 *)(temp_2 + 0x144), frame.v80);
    func_004b1470(*(s32 *)(temp_16 + 0x144), frame.v40);
    temp_B0 = frame.vB0;
    temp_70 = frame.v70;
    frame.vE0[0] = temp_B0[0] - frame.vC0[0];
    temp_c1 = frame.vC0[1];
    frame.vE0[1] = temp_B0[1] - temp_c1;
    temp_c2 = frame.vC0[2];
    frame.vE0[2] = temp_B0[2] - temp_c2;
    frame.vD0[0] = temp_70[0] - frame.vC0[0];
    frame.vD0[1] = temp_70[1] - frame.vC0[1];
    frame.vD0[2] = temp_70[2] - frame.vC0[2];
    temp_f20 = RwV3dLength(frame.vE0);
    return (s32)(temp_f20 - RwV3dLength(frame.vD0));
}

/* measured: closes opt_propagation off probe for mtSceneUnitDepthCompare. */
// FUN_0026DD60
void mtSceneDrawSortedUnits(u8 *arg0)
{
    s32 output_index;
    u32 *result;
    s32 count;
    u8 *base;
    s32 index;

    count = 0;
    base = arg0;
    goto loop_7_test;
loop_7_body:
    if (*(s32 *)(arg0 + 0x28) & 2) {
        if (*(s32 *)(arg0 + 0x144) != 0) {
            switch (*(s8 *)(arg0 + 0x140)) {
            case 0:
                count += 1;
                break;
            }
        }
    }
loop_7_next:
    arg0 = *(u8 **)(arg0 + 0x138);
loop_7_test:
    if (arg0 != NULL) {
        goto loop_7_body;
    }
    if (count != 0) {
        chkmemAllocSiteTag(D_0063B580, 0x96);
        result = (u32 *)jtbl_008873E8[0](count * 4, 0x40000);
        index = 0;
        arg0 = base;
        goto loop_16_test;
loop_16_body:
        if (*(s32 *)(arg0 + 0x28) & 2) {
            if (*(s32 *)(arg0 + 0x144) != 0) {
                switch (*(s8 *)(arg0 + 0x140)) {
                case 0:
                    result[index] = (u32)arg0;
                    index += 1;
                    break;
                }
            }
        }
loop_16_next:
        arg0 = *(u8 **)(arg0 + 0x138);
        goto loop_16_test;
loop_16_test:
        if (arg0 != NULL) {
            goto loop_16_body;
        }
        qsort(result, count, 4, mtSceneUnitDepthCompare);
        output_index = 0;
        goto loop_19_test;
loop_19_body:
        func_004b11d0(D_005DC7D0,
                      *(s32 *)((u8 *)result[output_index] + 0x144));
        output_index += 1;
loop_19_test:
        if (output_index < count) {
            goto loop_19_body;
        }
        jtbl_008873EC[0]((u8 *)result);
    }
}

// Intent: Draw step of the SceneManager task (retail task name "SceneManager Draw"), walking the resource list [inferred]
// FUN_0026DEE0
s32 MT_SceneManager_DrawUpdate(u8 *unusedTask)
{
    s32 temp_5;
    s8 temp_3;
    u8 *var_16;

    var_16 = MT_Scene_GetResListHead(6);
    mtSceneDrawSortedUnits(var_16);
    goto loop_test;
loop_body:
    if (*(s32 *)(var_16 + 0x28) & 2) {
        temp_5 = *(s32 *)(var_16 + 0x144);
        if (temp_5 != 0) {
            temp_3 = *(s8 *)(var_16 + 0x140);
            switch (temp_3) {
            case 0:
                break;
            case 1:
                func_004b11d0(D_005DC824, temp_5);
                break;
            }
        }
    }
    var_16 = *(u8 **)(var_16 + 0x138);
loop_test:
    if (var_16 != NULL) {
        goto loop_body;
    }
    return 0;
}

// Intent: Creates the SceneManager task pair (retail names "SceneManager Task" and "SceneManager Draw") and returns the parent task [inferred]
// FUN_0026DF80
s32 MT_SceneManager_Create(void)
{
    s32 temp_2;

    temp_2 = (s32)kwlnTaskCreateChild((void *)(0), (const void *)(D_0063B5A0), 0x10, 0, 0, MT_SceneManager_TaskUpdate, MT_Scene_ShakeStopTask, (u8 *)(0));
    (s32)kwlnTaskCreateChild((void *)(temp_2), (const void *)(D_0063B5C0), 0x10, 0, 0, MT_SceneManager_DrawUpdate, 0, (u8 *)(0));
    return temp_2;
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


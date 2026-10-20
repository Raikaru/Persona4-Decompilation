/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 001853e0-00186640 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "sdktask.h"
#include "primitive_queue_internal.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
#include "rw_types_internal.h"
#include "rw_raster_internal.h"
typedef struct RwTexture RwTexture;

typedef struct RwTexDictionary RwTexDictionary;

#include "scene_event_internal.h"
extern void mdlEffectEmitTagPair();
extern void (*D_00887300[])(s32, s32);
extern void RpSkyRenderStateSet(s32, s32);
extern void mdlEffectEmitMaskedTagPair(void);
extern void FldNoiseEmitTagged(void);
extern void FldNoiseEmitPlain();
extern void (*jtbl_008873EC[])(void *);
extern RwTexDictionary *func_003ef6d0(void);
extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern f32 sinf(f32);
extern u8 *PrimQueueDrawPrimitive(void *, s32, void *, s32);
extern s32 FldNoiseUpdate(u8 *task);
extern void FldNoiseDestroy(u8 *);
extern u8 D_005F1DF8[];
extern u8 D_005F1E08[];
/* Sky2's complete 0x40-byte vertex record, with its native quadword
 * alignment. Fields follow rw/sky2/rwplcore.h; unused components stay intact. */
typedef struct {
    f32 x, y, z, cameraZ;
    f32 u, v, reciprocalZ, reservedFog;
    f32 red, green, blue, alpha;
    f32 normalX, normalY, normalZ, reservedAlignment;
} GridDrawVertex __attribute__((aligned(16)));

typedef struct { f32 u, v; } FldNoiseUv;

typedef struct {
    s32 state;
    s32 blocked;
    s32 phases[7][10];
    GridDrawVertex grid[7][10][4];
    GridDrawVertex bands[14][1][4];
    GridDrawVertex overlay[4];
    f32 uvValues[8];
    GridDrawVertex cover[4];
    GridDrawVertex rings[3][66];
    RwTexture *textures[2];
    u8 *raster;
} GridDrawWork;

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_001853E0
#pragma opt_propagation off
/* Install the grid render state and bind the first noise texture raster. */
void FldNoiseRenderStateA(u8 *task, u8 *work)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x54);
    value = (s32 *)((GridDrawWork *)work)->textures[0];
    base[0](1, *value);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_001854F0
#pragma opt_propagation off
/* Install the strip render state, bind the second noise texture raster and emit its tag. */
void FldNoiseRenderStateB(u8 *task, u8 *work)
{
    s32 *value;
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 1);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 1);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x54);
    value = (s32 *)((GridDrawWork *)work)->textures[1];
    base[0](1, *value);
    FldNoiseEmitTagged();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00185600
/* Emit the pending untagged field-noise packet. */
void FldNoiseFlush(void)
{
    FldNoiseEmitPlain();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00185620
#pragma opt_propagation off
/* Measured: typed field access changed the retail instruction image; retain byte accesses at the documented work-layout offsets. */
/* Install the overlay render state, bind the captured display raster and emit its tag. */
void FldNoiseOverlayDraw(u8 *task, u8 *work)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x54);
    base[0](1, *(s32 *)(work + 0x88C8));
    FldNoiseEmitTagged();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00185730
#pragma opt_propagation off
/* Install the untextured ring/cover render state and emit the masked effect tag. */
void FldNoiseRenderStateSetup(void)
{
    void (**base)(s32, s32);

    base = D_00887300;
    base[0](0xE, 0);
    base[0](6, 0);
    base[0](8, 0);
    base[0](0xC, 1);
    base[0](7, 2);
    base[0](9, 2);
    base[0](2, 3);
    RpSkyRenderStateSet(3, 0x717FB);
    RpSkyRenderStateSet(2, 0x44);
    base[0](1, 0);
    mdlEffectEmitMaskedTagPair();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00185830
/* Emit the paired tags used by the ring primitives. */
void FldNoiseEmitRings(void)
{
    mdlEffectEmitTagPair();
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Build the grid, horizontal strips and three concentric ring pairs, then
 * queue their draw and state callbacks. The constant reciprocal depth is
 * 1/1000, matching each vertex's depth and the retail literal at 0x761304.
 * Separate loop lifetimes and complete work/vertex records recover the
 * retail 0x90 frame without artificial storage. */
// FUN_00185850
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Raw access: The queue API has a second callback payload at +0x14, beyond the canonical PrimQueueNode header; retain that packet-specific raw store. */
s32 FldNoiseUpdate(u8 *task)
{
    extern u8 D_00794930[];
    extern u8 D_005F1DA0[];
    extern u8 D_005F1DC0[];
    extern u8 D_005F1DE0[];
    extern f32 iGpffff8424;
    extern f32 fGpffff84d4;
    extern f32 fGpffff84d8;
    extern f32 fGpffff84dc;
    extern s32 uGpffffb314;
    extern u32 RpRandom(void);
    extern RwTexDictionary *func_003ef6d0(void);
    extern RwTexture *func_003ef650(RwTexDictionary *, const char *);
    extern s32 RpSkyGetDisplayBufferRaster(void);
    extern f32 cosf(f32 angle);
    extern f32 sinf(f32 angle);
    extern u8 *PrimAllocQueueNode(void);
    extern void PrimAppendNode(u8 *, u8 *);
    extern u8 *PrimQueueDrawPrimitive(void *task, s32, void *, s32);
    extern void FldNoiseRenderStateA(u8 *task, u8 *);
    extern void FldNoiseRenderStateB(u8 *task, u8 *);
    extern void FldNoiseFlush(void);
    extern void FldNoiseOverlayDraw(u8 *task, u8 *);
    extern void FldNoiseRenderStateSetup(void);
    extern void FldNoiseEmitRings(void);
    u8 *node;

    GridDrawWork *work;
    s32 index;
    u32 randomValue;
    u8 *callbackNode;
    s32 *phaseSlot;
    s32 vertex;
    s32 corner;
    s32 column;
    f32 value;
    f32 value2;

    work = (GridDrawWork *)((SdkTask *)task)->work;
    if (work->blocked != 0) {
        return 0;
    }
    switch (work->state) {
    case 0:
        work->textures[0] = func_003ef650(func_003ef6d0(), (const char *)D_005F1DC0);
        work->textures[1] = func_003ef650(func_003ef6d0(), (const char *)D_005F1DE0);
        node = (u8 *)RpSkyGetDisplayBufferRaster();
        work->raster = node;
        for (index = 0; index < 7; index = index + 1) {
            column = 0;
            while (column < 10) {
                work->grid[index][column][0].x = (float)(column << 6);
                work->grid[index][column][0].y = (float)(index << 6);
                work->grid[index][column][0].z = 1000.0f;
                value2 = (float)((column + 1) * 0x40);
                work->grid[index][column][1].x = value2;
                work->grid[index][column][1].y = (float)(index << 6);
                work->grid[index][column][1].z = 1000.0f;
                work->grid[index][column][2].x = (float)(column << 6);
                work->grid[index][column][2].y = (f32)((index + 1) * 0x40);
                work->grid[index][column][2].z = 1000.0f;
                work->grid[index][column][3].x = value2;
                work->grid[index][column][3].y = (f32)((index + 1) * 0x40);
                work->grid[index][column][3].z = 1000.0f;
                work->grid[index][column][0].reciprocalZ = 0.001f;
                work->grid[index][column][1].reciprocalZ = 0.001f;
                work->grid[index][column][2].reciprocalZ = 0.001f;
                work->grid[index][column][3].reciprocalZ = 0.001f;
                work->grid[index][column][0].red = 255.0f;
                work->grid[index][column][0].green = 255.0f;
                work->grid[index][column][0].blue = 255.0f;
                work->grid[index][column][0].alpha = 64.0f;
                work->grid[index][column][1].red = 255.0f;
                work->grid[index][column][1].green = 255.0f;
                work->grid[index][column][1].blue = 255.0f;
                work->grid[index][column][1].alpha = 64.0f;
                work->grid[index][column][2].red = 255.0f;
                work->grid[index][column][2].green = 255.0f;
                work->grid[index][column][2].blue = 255.0f;
                work->grid[index][column][2].alpha = 64.0f;
                work->grid[index][column][3].red = 255.0f;
                work->grid[index][column][3].green = 255.0f;
                work->grid[index][column][3].blue = 255.0f;
                work->grid[index][column][3].alpha = 64.0f;
                randomValue = RpRandom();
                work->phases[index][column] = randomValue & 3;
                column++;
            }
        }
        for (index = 0; index < 0xe; index = index + 1) {
            column = 0;
            while (column < 1) {
                work->bands[index][column][0].x = (float)(column * 0x280);
                work->bands[index][column][0].y = (float)(index << 5);
                work->bands[index][column][0].z = 1000.0f;
                value = (float)((column + 1) * 0x280);
                work->bands[index][column][1].x = value;
                work->bands[index][column][1].y = (float)(index << 5);
                work->bands[index][column][1].z = 1000.0f;
                work->bands[index][column][2].x = (float)(column * 0x280);
                work->bands[index][column][2].y = (f32)((index + 1) * 0x20);
                work->bands[index][column][2].z = 1000.0f;
                work->bands[index][column][3].x = value;
                work->bands[index][column][3].y = (f32)((index + 1) * 0x20);
                work->bands[index][column][3].z = 1000.0f;
                work->bands[index][column][0].reciprocalZ = 0.001f;
                work->bands[index][column][1].reciprocalZ = 0.001f;
                work->bands[index][column][2].reciprocalZ = 0.001f;
                work->bands[index][column][3].reciprocalZ = 0.001f;
                work->bands[index][column][0].red = 255.0f;
                work->bands[index][column][0].green = 255.0f;
                work->bands[index][column][0].blue = 255.0f;
                work->bands[index][column][0].alpha = 32.0f;
                work->bands[index][column][1].red = 255.0f;
                work->bands[index][column][1].green = 255.0f;
                work->bands[index][column][1].blue = 255.0f;
                work->bands[index][column][1].alpha = 32.0f;
                work->bands[index][column][2].red = 255.0f;
                work->bands[index][column][2].green = 255.0f;
                work->bands[index][column][2].blue = 255.0f;
                work->bands[index][column][2].alpha = 32.0f;
                work->bands[index][column][3].red = 255.0f;
                work->bands[index][column][3].green = 255.0f;
                work->bands[index][column][3].blue = 255.0f;
                work->bands[index][column][3].alpha = 32.0f;
                work->bands[index][column][0].u = 0.0f;
                work->bands[index][column][0].v = 0.0f;
                work->bands[index][column][1].u = 1.0f;
                work->bands[index][column][1].v = 0.0f;
                work->bands[index][column][2].u = 0.0f;
                work->bands[index][column][2].v = 1.0f;
                work->bands[index][column][3].u = 1.0f;
                work->bands[index][column][3].v = 1.0f;
                column = column + 1;
            }
        }
        index = 0;
        value2 = 0.0f;
        for (; index < 0x42; index = index + 2) {
            work->rings[0][index + 0].x = (cosf(value2) * 850.0f * 0.5f + 320.0f);
            value = (float)sinf(value2);
            work->rings[0][index + 0].y = (value * 750.0f * 0.5f + 224.0f);
            work->rings[0][index + 0].z = 1000.0f;
            work->rings[0][index + 0].reciprocalZ = 0.001f;
            work->rings[0][index + 0].red = 0.0f;
            work->rings[0][index + 0].green = 255.0f;
            work->rings[0][index + 0].blue = 0.0f;
            work->rings[0][index + 0].alpha = 128.0f;
            value = 450.0f * cosf(value2);
            work->rings[0][index + 1].x = (value * 0.5f + 320.0f);
            value = 250.0f * sinf(value2);
            work->rings[0][index + 1].y = (value * 0.5f + 224.0f);
            work->rings[0][index + 1].z = 1000.0f;
            work->rings[0][index + 1].reciprocalZ = 0.001f;
            work->rings[0][index + 1].red = 0.0f;
            work->rings[0][index + 1].green = 255.0f;
            work->rings[0][index + 1].blue = 0.0f;
            work->rings[0][index + 1].alpha = 0.0f;
            value2 = value2 + fGpffff84d4;
        }
        value2 = 0.0f;
        work->cover[0].x = 0.0f;
        work->cover[0].y = 0.0f;
        work->cover[0].z = 1000.0f;
        work->cover[1].x = 640.0f;
        work->cover[1].y = 0.0f;
        work->cover[1].z = 1000.0f;
        work->cover[2].x = 0.0f;
        work->cover[2].y = 448.0f;
        work->cover[2].z = 1000.0f;
        work->cover[3].x = 640.0f;
        work->cover[3].y = 448.0f;
        work->cover[3].z = 1000.0f;
        work->cover[0].reciprocalZ = 0.001f;
        work->cover[1].reciprocalZ = 0.001f;
        work->cover[2].reciprocalZ = 0.001f;
        work->cover[3].reciprocalZ = 0.001f;
        work->cover[0].red = 255.0f;
        work->cover[0].green = 255.0f;
        work->cover[0].blue = 255.0f;
        work->cover[0].alpha = 0.0f;
        work->cover[1].red = 255.0f;
        work->cover[1].green = 255.0f;
        work->cover[1].blue = 255.0f;
        work->cover[1].alpha = 0.0f;
        work->cover[2].red = 255.0f;
        work->cover[2].green = 255.0f;
        work->cover[2].blue = 255.0f;
        work->cover[2].alpha = 0.0f;
        work->cover[3].red = 255.0f;
        work->cover[3].green = 255.0f;
        work->cover[3].blue = 255.0f;
        work->cover[3].alpha = 0.0f;
        for (index = 0; index < 0x42; index = index + 2) {
            work->rings[1][index + 0].x = (cosf(value2) * 850.0f * 0.5f + 320.0f);
            value = (float)sinf(value2);
            work->rings[1][index + 0].y = (value * 750.0f * 0.5f + 224.0f);
            work->rings[1][index + 0].z = 1000.0f;
            work->rings[1][index + 0].reciprocalZ = 0.001f;
            work->rings[1][index + 0].red = 0.0f;
            work->rings[1][index + 0].green = 255.0f;
            work->rings[1][index + 0].blue = 0.0f;
            work->rings[1][index + 0].alpha = 64.0f;
            value = 500.0f * cosf(value2);
            work->rings[1][index + 1].x = (value * 0.5f + 320.0f);
            value = 300.0f * sinf(value2);
            work->rings[1][index + 1].y = (value * 0.5f + 224.0f);
            work->rings[1][index + 1].z = 1000.0f;
            work->rings[1][index + 1].reciprocalZ = 0.001f;
            work->rings[1][index + 1].red = 0.0f;
            work->rings[1][index + 1].green = 255.0f;
            work->rings[1][index + 1].blue = 0.0f;
            work->rings[1][index + 1].alpha = 0.0f;
            value2 = value2 + fGpffff84d4;
        }
        index = 0;
        value2 = 0.0f;
        for (; index < 0x42; index = index + 2) {
            work->rings[2][index + 0].x = (cosf(value2) * 850.0f * 0.5f + 320.0f);
            value = (float)sinf(value2);
            work->rings[2][index + 0].y = (value * 750.0f * 0.5f + 224.0f);
            work->rings[2][index + 0].z = 1000.0f;
            work->rings[2][index + 0].reciprocalZ = 0.001f;
            work->rings[2][index + 0].red = 0.0f;
            work->rings[2][index + 0].green = 255.0f;
            work->rings[2][index + 0].blue = 0.0f;
            work->rings[2][index + 0].alpha = 240.0f;
            value = 450.0f * cosf(value2);
            work->rings[2][index + 1].x = (value * 0.5f + 320.0f);
            value = 250.0f * sinf(value2);
            work->rings[2][index + 1].y = (value * 0.5f + 224.0f);
            work->rings[2][index + 1].z = 1000.0f;
            work->rings[2][index + 1].reciprocalZ = 0.001f;
            work->rings[2][index + 1].red = 0.0f;
            work->rings[2][index + 1].green = 255.0f;
            work->rings[2][index + 1].blue = 0.0f;
            work->rings[2][index + 1].alpha = 0.0f;
            value2 = value2 + fGpffff84d4;
        }
        work->overlay[0].x = 0.0f;
        work->overlay[0].y = 0.0f;
        work->overlay[0].z = 1000.0f;
        work->overlay[1].x = 640.0f;
        work->overlay[1].y = 0.0f;
        work->overlay[1].z = 1000.0f;
        work->overlay[2].x = 0.0f;
        work->overlay[2].y = 448.0f;
        work->overlay[2].z = 1000.0f;
        work->overlay[3].x = 640.0f;
        work->overlay[3].y = 448.0f;
        work->overlay[3].z = 1000.0f;
        work->overlay[0].reciprocalZ = 0.001f;
        work->overlay[1].reciprocalZ = 0.001f;
        work->overlay[2].reciprocalZ = 0.001f;
        work->overlay[3].reciprocalZ = 0.001f;
        work->overlay[0].red = 255.0f;
        work->overlay[0].green = 255.0f;
        work->overlay[0].blue = 255.0f;
        work->overlay[0].alpha = 96.0f;
        work->overlay[1].red = 255.0f;
        work->overlay[1].green = 255.0f;
        work->overlay[1].blue = 255.0f;
        work->overlay[1].alpha = 96.0f;
        work->overlay[2].red = 255.0f;
        work->overlay[2].green = 255.0f;
        work->overlay[2].blue = 255.0f;
        work->overlay[2].alpha = 96.0f;
        work->overlay[3].red = 255.0f;
        work->overlay[3].green = 255.0f;
        work->overlay[3].blue = 255.0f;
        work->overlay[3].alpha = 96.0f;
        work->uvValues[2] = (0.5f / (float)((RwRaster *)work->raster)->width);
        work->uvValues[3] = (0.5f / (float)((RwRaster *)work->raster)->height);
        work->uvValues[4] = (fGpffff84d8 / (float)((RwRaster *)work->raster)->width);
        work->uvValues[5] = (fGpffff84dc / (float)((RwRaster *)work->raster)->height);
        work->uvValues[1] = iGpffff8424;
        work->overlay[0].u = (work->uvValues[2] + work->uvValues[1]);
        work->overlay[0].v = (work->uvValues[3] + work->uvValues[1]);
        work->overlay[1].u = (work->uvValues[4] - work->uvValues[1]);
        work->overlay[1].v = (work->uvValues[3] + work->uvValues[1]);
        work->overlay[2].u = (work->uvValues[2] + work->uvValues[1]);
        work->overlay[2].v = (work->uvValues[5] - work->uvValues[1]);
        work->overlay[3].u = (work->uvValues[4] - work->uvValues[1]);
        work->overlay[3].v = (work->uvValues[5] - work->uvValues[1]);
        work->state = work->state + 1;
        break;
    case 1:
        node = PrimQueueDrawPrimitive(D_00794930,4,work->cover,4);
        *(void (**)(void))(node + 8) = FldNoiseRenderStateSetup;
        ((PrimQueueNode *)node)->argument.data = (u8 *)work;
        node = PrimQueueDrawPrimitive(D_00794930,4,work->rings[2],0x42);
        *(void (**)(void))(node + 8) = FldNoiseRenderStateSetup;
        ((PrimQueueNode *)node)->argument.data = (u8 *)work;
        *(void (**)(void))(node + 0xc) = FldNoiseEmitRings;
        *(GridDrawWork **)(node + 0x14) = work;
        node = PrimQueueDrawPrimitive(D_00794930,4,work->overlay,4);
        *(void (**)(u8 *, u8 *))(node + 8) = FldNoiseOverlayDraw;
        ((PrimQueueNode *)node)->argument.data = (u8 *)work;
        callbackNode = (u8 *)PrimAllocQueueNode();
        *(void (**)(void))(callbackNode + 8) = FldNoiseFlush;
        ((PrimQueueNode *)callbackNode)->argument.data = (u8 *)work;
        PrimAppendNode(D_00794930,callbackNode);
        node = PrimQueueDrawPrimitive(D_00794930,4,work->cover,4);
        *(void (**)(void))(node + 8) = FldNoiseRenderStateSetup;
        ((PrimQueueNode *)node)->argument.data = (u8 *)work;
        node = PrimQueueDrawPrimitive(D_00794930,4,work->rings[1],0x42);
        *(void (**)(void))(node + 8) = FldNoiseRenderStateSetup;
        ((PrimQueueNode *)node)->argument.data = (u8 *)work;
        *(void (**)(void))(node + 0xc) = FldNoiseEmitRings;
        *(GridDrawWork **)(node + 0x14) = work;
        callbackNode = (u8 *)PrimAllocQueueNode();
        *(void (**)(u8 *, u8 *))(callbackNode + 8) = FldNoiseRenderStateB;
        ((PrimQueueNode *)callbackNode)->argument.data = (u8 *)work;
        PrimAppendNode(D_00794930,callbackNode);
        for (index = 0; index < 0xe; index = index + 1) {
            for (column = 0; column < 1; column = column + 1) {
                PrimQueueDrawPrimitive(D_00794930,4,work->bands[index][column],4);
            }
        }
        callbackNode = (u8 *)PrimAllocQueueNode();
        *(void (**)(void))(callbackNode + 8) = FldNoiseFlush;
        ((PrimQueueNode *)callbackNode)->argument.data = (u8 *)work;
        PrimAppendNode(D_00794930,callbackNode);
        node = PrimQueueDrawPrimitive(D_00794930,4,work->rings[0],0x42);
        *(void (**)(void))(node + 0xc) = FldNoiseEmitRings;
        *(GridDrawWork **)(node + 0x14) = work;
        uGpffffb314 = uGpffffb314 != 0 ^ 1;
        callbackNode = (u8 *)PrimAllocQueueNode();
        *(void (**)(u8 *, u8 *))(callbackNode + 8) = FldNoiseRenderStateA;
        ((PrimQueueNode *)callbackNode)->argument.data = (u8 *)work;
        PrimAppendNode(D_00794930,callbackNode);
        for (index = 0; index < 7; index = index + 1) {
            for (column = 0; column < 10; column = column + 1) {
                phaseSlot = &work->phases[index][column];
                corner = work->phases[index][column];
                vertex = 0;
                while (vertex < 4) {
                    if (corner >= 4) {
                        corner = 0;
                    }
                    work->grid[index][column][vertex].u =
                        ((const FldNoiseUv *)D_005F1DA0)[corner].u;
                    work->grid[index][column][vertex].v =
                        ((const FldNoiseUv *)D_005F1DA0)[corner].v;
                    vertex++;
                    corner = corner + 1;
                }
                if (uGpffffb314 != 0) {
                    *phaseSlot = *phaseSlot + 1;
                }
                if (*phaseSlot >= 4) {
                    *phaseSlot = 0;
                }
                PrimQueueDrawPrimitive(D_00794930,4,work->grid[index][column],4);
            }
        }
        break;
    }
    return 0;
}
#pragma pop
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00186610
/* Free the dynamically allocated noise work block through the allocator release hook. */
void FldNoiseDestroy(u8 *task)
{
    jtbl_008873EC[0]((void *)((SdkTask *)task)->work);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_00186640
/* Allocate the 0x88D0-byte noise work block and create its child task. */
s32 FldNoiseTaskCreate(u8 *task)
{
    chkmemAllocSiteTag(&D_005F1DF8, 0x299);
    return (s32)kwlnTaskCreateChild((void *)(task), (const void *)(&D_005F1E08), 0xF, 0, 0, FldNoiseUpdate, FldNoiseDestroy, (u8 *)(D_008873F4[0](1, 0x88D0, 0x40000)));
}
#pragma pop

extern u32 RpRandom(void);

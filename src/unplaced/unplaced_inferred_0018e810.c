/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018e810-0018f390 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
#include "member_access.h"
#include "kwln_task_internal.h"
#include "message_frame_internal.h"
#include "g_data_internal.h"
#include "field_frame_internal.h"
#include "field_panel_internal.h"
#include "field_npc_control_internal.h"
#include "rw_types_internal.h"
#include "scene_event_internal.h"
extern void (*jtbl_008873EC[])(void *);
extern s32 iGpffffb268;
extern s32 iGpffffb250;
extern s16 iGpffffb390;
extern s16 iGpffffb394;
extern s16 iGpffffb398;
extern s16 iGpffffb39c;
extern s16 iGpffffb3a0;
extern s32 iGpffffb3a4;
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
extern const KWindowEntryDescriptor D_005F5830[];
extern const KWindowEntryDescriptor D_005F5730[];
extern u8 D_007E3720[];
extern u8 D_007966D0[];
extern s64 iGpffff9fd0;
extern s32 iGpffffb240;
extern void FldBoardGenerate(s32 mode, s32 seed, s32 unused);
extern void FldSmapTileQueueByType(u8 *queue, u8 *context, s32 tileType, s32 variant,
                           f32 x, f32 y, f32 depth, s32 flags);
extern void FldRc_QueueScreenQuad(u8 *queue, u8 *quad,
                          f32 left, f32 top, f32 depthOffset, f32 width,
                          f32 height, u8 *color, s32 texture,
                          f32 uMin, f32 vMin, f32 uMax, s32 orientation,
                          f32 vMax);
extern u16 D_008C024E[];
extern s32 *MT_Scene_GetFrameState(void);
extern void chkmemAllocSiteTag(const void *file, s32 line);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 FldMapTestUpdate(u8 *task);
extern void FldMapTestDestroy(u8 *task);
extern u8 D_005F57B0[];
extern u8 D_005F57C0[];
extern s32 kwlnGetCurrentWorkValue(void);
/* One 0x4A-byte pad record; the pads start at 0x8C0240 (sdkPadInit). */
typedef struct {
    u8 unk00[0xC];
    u16 level;
    u16 trigger;
    u8 unk10[2];
    u16 repeat;
    u8 unk14[0x36];
} PadStatus;

typedef struct {
    u8 r, g, b, a;
} PanelColor;

typedef struct {
    u8 occupied;
    u8 flags;
    u16 resourceId;
    u8 shape;
    u8 rotation;
    u8 unknown06[10];
} MapTestCell;

typedef struct {
    u8 header[0x54];
    MapTestCell cells[24][16];
} MapTestGrid;

/* Work allocation is 0x1B440 bytes; each grid cell owns a 0x120-byte draw packet. */
typedef struct FldMapTestWork {
    s32 state;
    s32 mode;
    u8 pad08[8];
    u8 packets[24][16][0x120];
    u8 pad1B010[0x420];
    s32 variant;
    u8 *entries;
    KwlnTask *menuTask;
    u8 pad1B43C[4];
} FldMapTestWork;

typedef struct FldMapTestEntry {
    u8 pad00[8];
    u8 unk08, unk09;
    u8 pad0A[6];
} FldMapTestEntry;

typedef struct FldViewerWork {
    s32 state;
    KwlnTask *menuTask;
} FldViewerWork;

/* Requests 9 and 10 use separate portions of the same 0x20-byte packet. */
typedef struct FldViewerRequest {
    u16 values[3];
    s16 value06, value08;
    u8 pad0A[2];
    s32 arguments[3];
    u8 pad18[8];
} FldViewerRequest;

/* Unit settings shared by the map-test and viewer task routines. */
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Drive the board-generation menu, then render the generated grid for inspection. */
// FUN_0018E810
s32 FldMapTestUpdate(u8 *task)
{
    FldMapTestWork *mapWork;
    extern PadStatus D_008C0240[2];
    extern s64 iGpffff9fd0;
    extern PanelColor iGpffff9fd8;
    extern char iGpffff9fdc[3];
    extern s32 iGpffffb240;
    extern void FldBoardGenerate(s32 mode, s32 seed, s32 unused);
    PanelColor color;
    /* Entry-table bytes 8/9 and frame bytes 4A/4B retain their byte layout; meanings unproven. */
    u8 *work;
    s32 menuValue;

    work = ((KwlnTask *)task)->work;
    mapWork = (FldMapTestWork *)work;
    switch (((FldMapTestWork *)work)->state) {
    case 0:
        ((FldMapTestWork *)work)->menuTask = sdkLboxCreate((KwlnTask *)task, 0x100, 0x40);
        sdkLboxAddDescriptors(mapWork->menuTask, D_005F5730, 4);
        sdkLboxSetVisibleRows((u8 *)mapWork->menuTask, 0x14);
        sdkLboxSetState((u8 *)mapWork->menuTask, 4);
        sdkLboxSetSelection((u8 *)mapWork->menuTask, 1);
        ((FldMapTestWork *)work)->entries = D_007E3720;
        ((FldMapTestWork *)work)->state += 1;
        break;
    case 1:
        if (D_008C0240[0].trigger & 0x40) {
            switch (sdkLboxGetSelectedId((u8 *)((FldMapTestWork *)work)->menuTask)) {
            case 0:
                /* Measured: adding a byte-pointer cast swaps addu operands; keep these column reads cast-free. */
                ((FldFrame *)MT_Scene_GetFrameState())->unk48[2] =
                    *(((FldMapTestWork *)work)->entries +
                      *sdkLboxGetValuePtr(mapWork->menuTask, 3) * 0x10 + MEMBER_OFFSET(FldMapTestEntry, unk08));
                ((FldFrame *)MT_Scene_GetFrameState())->unk48[3] =
                    *(mapWork->entries +
                      *sdkLboxGetValuePtr(mapWork->menuTask, 3) * 0x10 + MEMBER_OFFSET(FldMapTestEntry, unk09));
                ((FldMapTestWork *)work)->mode = 2;
                menuValue = *sdkLboxGetValuePtr(mapWork->menuTask, 0);
                FldBoardGenerate(mapWork->mode, menuValue, 0);
                kwlnTaskDestroyWithHierarchy(mapWork->menuTask);
                ((FldMapTestWork *)work)->state += 1;
                break;
            case 1:
                ((FldFrame *)MT_Scene_GetFrameState())->unk48[2] =
                    *(((FldMapTestWork *)work)->entries +
                      *sdkLboxGetValuePtr(mapWork->menuTask, 3) * 0x10 + MEMBER_OFFSET(FldMapTestEntry, unk08));
                ((FldFrame *)MT_Scene_GetFrameState())->unk48[3] =
                    *(mapWork->entries +
                      *sdkLboxGetValuePtr(mapWork->menuTask, 3) * 0x10 + MEMBER_OFFSET(FldMapTestEntry, unk09));
                ((FldMapTestWork *)work)->mode = 0;
                menuValue = *sdkLboxGetValuePtr(mapWork->menuTask, 1);
                FldBoardGenerate(mapWork->mode, menuValue, 0);
                kwlnTaskDestroyWithHierarchy(mapWork->menuTask);
                ((FldMapTestWork *)work)->state += 1;
                break;
            case 2:
                ((FldFrame *)MT_Scene_GetFrameState())->unk48[2] =
                    *(((FldMapTestWork *)work)->entries +
                      *sdkLboxGetValuePtr(mapWork->menuTask, 3) * 0x10 + MEMBER_OFFSET(FldMapTestEntry, unk08));
                ((FldFrame *)MT_Scene_GetFrameState())->unk48[3] =
                    *(mapWork->entries +
                      *sdkLboxGetValuePtr(mapWork->menuTask, 3) * 0x10 + MEMBER_OFFSET(FldMapTestEntry, unk09));
                ((FldMapTestWork *)work)->mode = 1;
                menuValue = *sdkLboxGetValuePtr(mapWork->menuTask, 2);
                FldBoardGenerate(mapWork->mode, menuValue, 0);
                kwlnTaskDestroyWithHierarchy(mapWork->menuTask);
                ((FldMapTestWork *)work)->state += 1;
                break;
            }
        }
        break;
    case 2:
        ((FldMapTestWork *)work)->state += 1;
        break;
    case 3:
        ((FldMapTestWork *)work)->state += 1;
        break;
    case 4:
        if (D_008C0240[0].trigger & 0x8000) {
            ((FldMapTestWork *)work)->variant -= 1;
        } else if (D_008C0240[0].trigger & 0x2000) {
            ((FldMapTestWork *)work)->variant += 1;
        }
        if (((FldMapTestWork *)work)->variant < 0) {
            mapWork->variant = 3;
        }
        if (mapWork->variant > 3) {
            mapWork->variant = 0;
        }
        if (D_008C0240[0].trigger & 0x40) {
            FldBoardGenerate(((FldMapTestWork *)work)->mode, 0, 0);
        }
        sdkDbprtQueueText(iGpffff9fd0, iGpffff9fdc, iGpffffb240);
        {
            s32 y;
            s32 x;
            s32 screenRow;
            s32 rowOffset;
            u8 *panels;
            s32 type;
            s32 column;
            f32 screenX;
            f32 screenY;

            for (y = 0; y < 0x18; y++) {
                for (x = 0, rowOffset = y * 0x100, screenRow = y * 0x12,
                     panels = work + y * 0x1200; x < 0x10; x++) {
                    if (((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][x].occupied != 0 &&
                        (((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][x].flags & 0xF) == 1) {
                        column = x;
                        type = ((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][column].shape;
                        screenX = (f32)(x * 0x12);
                        screenY = (f32)screenRow;
                        FldSmapTileQueueByType(D_007966D0, panels + x * 0x120 + 0x10, type, 0, screenX, screenY, 0.0f, ((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][column].rotation);
                    }
                    if (((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][x].occupied == 2) {
                        color = iGpffff9fd8;
                        FldRc_QueueScreenQuad(D_007966D0, panels + x * 0x120 + 0x10,
                                      (f32)(x * 0x12), (f32)screenRow, 0.0f, 18.0f, 18.0f,
                                      (u8 *)&color, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
                    }
                }
            }
        }
        if (D_008C0240[0].trigger & 0x20) {
            ((FldMapTestWork *)work)->state = 0;
        }
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018EF20
void FldMapTestDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Attach a map-test task with storage for all per-cell render packets. */
// FUN_0018EF50
void FldMapTestTaskCreate(s32 parent)
{
    chkmemAllocSiteTag(&D_005F57B0, 0x101);
    (s32)kwlnTaskCreateChild((void *)((u8 *)parent), (const void *)(&D_005F57C0), 0xF, 0, 0, FldMapTestUpdate, FldMapTestDestroy, (u8 *)(D_008873F4[0](1, 0x1B440, 0x40000)));
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Edit viewer parameters and submit command 9 or 10; wait until it completes. */
// FUN_0018EFE0
s32 FldViewerUpdate(u8 *task)
{
    FldViewerWork *viewerWork;
    /* Four stack-packet accesses retain MEMBER: direct fields and a typed request pointer change the instruction image. */
    u8 packet[0x20];
    u8 *work;
    s32 hidden;

    work = ((KwlnTask *)task)->work;
    viewerWork = (FldViewerWork *)work;
    switch (((FldViewerWork *)work)->state) {
    case 0:
        ((FldViewerWork *)work)->menuTask = sdkLboxCreate((KwlnTask *)task, 0xDC, 0xA0);
        sdkLboxAddDescriptors(viewerWork->menuTask, D_005F5830, 0xB);
        hidden = iGpffffb268 != 0;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 5) = hidden ^ 1;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 0) = iGpffffb3a0;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 1) = iGpffffb39c;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 2) = iGpffffb398;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 3) = iGpffffb394;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 4) = iGpffffb390;
        *sdkLboxGetValuePtr(viewerWork->menuTask, 6) = iGpffffb250;
        sdkLboxSetVisibleRows((u8 *)viewerWork->menuTask, 0x14);
        sdkLboxSetState((u8 *)viewerWork->menuTask, 4);
        sdkLboxSetSelection((u8 *)viewerWork->menuTask, 1);
        ((FldViewerWork *)work)->state += 1;
        break;
    case 1:
        iGpffffb268 = *sdkLboxGetValuePtr(((FldViewerWork *)work)->menuTask, 5) != 1;
        iGpffffb250 = *sdkLboxGetValuePtr(viewerWork->menuTask, 6);
        if (D_008C024E[0] & 0x40) {
            if (*sdkLboxGetValuePtr(viewerWork->menuTask, 8) == -1) {
                ((FldViewerRequest *)packet)->values[0] =
                    (u16)*sdkLboxGetValuePtr(viewerWork->menuTask, 0);
                ((FldViewerRequest *)packet)->values[1] =
                    (u16)*sdkLboxGetValuePtr(viewerWork->menuTask, 1);
                ((FldViewerRequest *)packet)->values[2] =
                    (u16)*sdkLboxGetValuePtr(viewerWork->menuTask, 2);
                ((FldViewerRequest *)packet)->value06 =
                    (s16)*sdkLboxGetValuePtr(viewerWork->menuTask, 3);
                ((FldViewerRequest *)packet)->value08 =
                    (s16)*sdkLboxGetValuePtr(viewerWork->menuTask, 4);
                iGpffffb3a0 = ((FldViewerRequest *)packet)->values[0];
                iGpffffb39c = MEMBER(u16, packet, FldViewerRequest, values[1]);
                iGpffffb398 = MEMBER(u16, packet, FldViewerRequest, values[2]);
                iGpffffb394 = MEMBER(s16, packet, FldViewerRequest, value06);
                iGpffffb390 = MEMBER(s16, packet, FldViewerRequest, value08);
                sequenceRequest(9, packet, 0x1C, 0);
                sdkLboxSetSelection((u8 *)viewerWork->menuTask, 0);
                ((FldViewerWork *)work)->state = 2;
            } else {
                ((FldViewerRequest *)packet)->arguments[0] =
                    *sdkLboxGetValuePtr(viewerWork->menuTask, 8);
                ((FldViewerRequest *)packet)->arguments[1] =
                    *sdkLboxGetValuePtr(viewerWork->menuTask, 9);
                ((FldViewerRequest *)packet)->arguments[2] =
                    *sdkLboxGetValuePtr(viewerWork->menuTask, 0xA);
                sequenceRequest(0xA, packet, 0x1C, 0);
                sdkLboxSetSelection((u8 *)viewerWork->menuTask, 0);
                ((FldViewerWork *)work)->state = 2;
            }
        } else if (D_008C024E[0] & 0x20) {
            ((FldViewerWork *)work)->state = 3;
        }
        break;
    case 2:
        if (kwlnGetCurrentWorkValue() == 0) {
            iGpffffb3a4 = 0;
            sdkLboxSetSelection((u8 *)((FldViewerWork *)work)->menuTask, 1);
            ((FldViewerWork *)work)->state = 1;
        }
        break;
    case 3:
        return -1;
    default:
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018F390
void FldViewerDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
#pragma pop

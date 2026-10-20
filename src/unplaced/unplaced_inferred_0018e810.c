/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018e810-0018f390 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
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
extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *handle);
extern const KWindowEntryDescriptor D_005F5830[];
extern const KWindowEntryDescriptor D_005F5730[];
extern u8 D_007E3720[];
extern u8 D_007966D0[];
extern s64 iGpffff9fd0;
extern s32 iGpffffb240;
extern void FldBoardGenerate(s32 mode, s32 value, s32 option);
extern void FldSmapTileQueueByType(u8 *queue, u8 *context, s32 tileType, s32 variant,
                           f32 x, f32 y, f32 depth, s32 flags);
extern void FldRc_QueueScreenQuad(u8 *queue, u8 *quad,
                          f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                          f32 fparg4, u8 *color, s32 texture,
                          f32 fparg5, f32 fparg6, f32 fparg7, s32 orientation,
                          f32 arg_sp0);
extern u16 D_008C024E[];
extern s32 *MT_Scene_GetFrameState(void);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
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

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018E810
/* Drive the board-generation menu, then render the generated grid for inspection. */
s32 FldMapTestUpdate(u8 *task)
{
    extern PadStatus D_008C0240[2];
    extern s64 iGpffff9fd0;
    extern PanelColor iGpffff9fd8;
    extern char iGpffff9fdc[3];
    extern s32 iGpffffb240;
    extern void FldBoardGenerate(s32 mode, s32 value, s32 option);
    PanelColor color;
    /* Entry-table bytes 8/9 and frame bytes 4A/4B retain their byte layout; meanings unproven. */
    u8 *work;
    s32 menuValue;

    /* Typed work fields alter MWCC scheduling; retain the proven scalar offsets. */
    work = *(u8 **)(task + 0x38);
    switch (*(s32 *)work) {
    case 0:
        *(KwlnTask **)(work + 0x1B438) = sdkLboxCreate((KwlnTask *)task, 0x100, 0x40);
        sdkLboxAddDescriptors(*(KwlnTask **)(work + 0x1B438), D_005F5730, 4);
        sdkLboxSetVisibleRows(*(u8 **)(work + 0x1B438), 0x14);
        sdkLboxSetState(*(u8 **)(work + 0x1B438), 4);
        sdkLboxSetSelection(*(u8 **)(work + 0x1B438), 1);
        *(u8 **)(work + 0x1B434) = D_007E3720;
        *(s32 *)work += 1;
        break;
    case 1:
        if (D_008C0240[0].trigger & 0x40) {
            switch (sdkLboxGetSelectedId(*(u8 **)(work + 0x1B438))) {
            case 0:
                *((u8 *)MT_Scene_GetFrameState() + 0x4A) =
                    *(*(u8 **)(work + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)MT_Scene_GetFrameState() + 0x4B) =
                    *(*(u8 **)(work + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(work + 0x4) = 2;
                menuValue = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 0);
                FldBoardGenerate(*(s32 *)(work + 0x4), menuValue, 0);
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(work + 0x1B438));
                *(s32 *)work += 1;
                break;
            case 1:
                *((u8 *)MT_Scene_GetFrameState() + 0x4A) =
                    *(*(u8 **)(work + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)MT_Scene_GetFrameState() + 0x4B) =
                    *(*(u8 **)(work + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(work + 0x4) = 0;
                menuValue = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 1);
                FldBoardGenerate(*(s32 *)(work + 0x4), menuValue, 0);
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(work + 0x1B438));
                *(s32 *)work += 1;
                break;
            case 2:
                *((u8 *)MT_Scene_GetFrameState() + 0x4A) =
                    *(*(u8 **)(work + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)MT_Scene_GetFrameState() + 0x4B) =
                    *(*(u8 **)(work + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(work + 0x4) = 1;
                menuValue = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1B438), 2);
                FldBoardGenerate(*(s32 *)(work + 0x4), menuValue, 0);
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(work + 0x1B438));
                *(s32 *)work += 1;
                break;
            }
        }
        break;
    case 2:
        *(s32 *)work += 1;
        break;
    case 3:
        *(s32 *)work += 1;
        break;
    case 4:
        if (D_008C0240[0].trigger & 0x8000) {
            *(s32 *)(work + 0x1B430) -= 1;
        } else if (D_008C0240[0].trigger & 0x2000) {
            *(s32 *)(work + 0x1B430) += 1;
        }
        if (*(s32 *)(work + 0x1B430) < 0) {
            *(s32 *)(work + 0x1B430) = 3;
        }
        if (*(s32 *)(work + 0x1B430) > 3) {
            *(s32 *)(work + 0x1B430) = 0;
        }
        if (D_008C0240[0].trigger & 0x40) {
            FldBoardGenerate(*(s32 *)(work + 0x4), 0, 0);
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
            *(s32 *)work = 0;
        }
        break;
    }
    return 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018EF50
/* Attach a map-test task with storage for all per-cell render packets. */
void FldMapTestTaskCreate(s32 parent)
{
    chkmemAllocSiteTag(&D_005F57B0, 0x101);
    (s32)kwlnTaskCreateChild((void *)((u8 *)parent), (const void *)(&D_005F57C0), 0xF, 0, 0, FldMapTestUpdate, FldMapTestDestroy, (u8 *)(D_008873F4[0](1, 0x1B440, 0x40000)));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018EFE0
/* Edit viewer parameters and submit command 9 or 10; wait until it completes. */
s32 FldViewerUpdate(u8 *task)
{
    /* Command payload: halfwords at 0..8, words at C..14; struct access loses MATCH. */
    u8 packet[0x20];
    u8 *work;
    s32 hidden;

    /* Typed work fields alter MWCC scheduling; retain the proven scalar offsets. */
    work = *(u8 **)(task + 0x38);
    switch (*(s32 *)work) {
    case 0:
        *(KwlnTask **)(work + 0x4) = sdkLboxCreate((KwlnTask *)task, 0xDC, 0xA0);
        sdkLboxAddDescriptors(*(KwlnTask **)(work + 0x4), D_005F5830, 0xB);
        hidden = iGpffffb268 != 0;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 5) = hidden ^ 1;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 0) = iGpffffb3a0;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 1) = iGpffffb39c;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 2) = iGpffffb398;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 3) = iGpffffb394;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 4) = iGpffffb390;
        *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 6) = iGpffffb250;
        sdkLboxSetVisibleRows(*(u8 **)(work + 4), 0x14);
        sdkLboxSetState(*(u8 **)(work + 4), 4);
        sdkLboxSetSelection(*(u8 **)(work + 4), 1);
        *(s32 *)work += 1;
        break;
    case 1:
        iGpffffb268 = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 5) != 1;
        iGpffffb250 = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 6);
        if (D_008C024E[0] & 0x40) {
            if (*sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 8) == -1) {
                *(u16 *)(packet + 0) =
                    (u16)*sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 0);
                *(u16 *)(packet + 0x2) =
                    (u16)*sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 1);
                *(u16 *)(packet + 0x4) =
                    (u16)*sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 2);
                *(s16 *)(packet + 0x6) =
                    (s16)*sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 3);
                *(s16 *)(packet + 0x8) =
                    (s16)*sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 4);
                iGpffffb3a0 = *(u16 *)(packet + 0);
                iGpffffb39c = *(u16 *)(packet + 0x2);
                iGpffffb398 = *(u16 *)(packet + 0x4);
                iGpffffb394 = *(s16 *)(packet + 0x6);
                iGpffffb390 = *(s16 *)(packet + 0x8);
                sequenceRequest(9, packet, 0x1C, 0);
                sdkLboxSetSelection(*(u8 **)(work + 4), 0);
                *(s32 *)work = 2;
            } else {
                *(s32 *)(packet + 0xC) =
                    *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 8);
                *(s32 *)(packet + 0x10) =
                    *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 9);
                *(s32 *)(packet + 0x14) =
                    *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x4), 0xA);
                sequenceRequest(0xA, packet, 0x1C, 0);
                sdkLboxSetSelection(*(u8 **)(work + 4), 0);
                *(s32 *)work = 2;
            }
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)work = 3;
        }
        break;
    case 2:
        if (kwlnGetCurrentWorkValue() == 0) {
            iGpffffb3a4 = 0;
            sdkLboxSetSelection(*(u8 **)(work + 4), 1);
            *(s32 *)work = 1;
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
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018F390
void FldViewerDestroy(u8 *task)
{
    jtbl_008873EC[0](((KwlnTask *)task)->work);
}
#pragma pop

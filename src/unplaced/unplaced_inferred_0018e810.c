/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018e810-0018f390 */

#include "field_transition_internal.h"
#include "sdk_lbox_internal.h"
#include "sdk_dbprt.h"
#include "model_motion_internal.h"
#include "Kosaka/k_clump_internal.h"
#include "sdk_task_registration.h"
#include "include_asm.h"
#include "type.h"
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
extern void FldBoardGenerate(s32 mode, s32 value, s32 arg2);
extern void FldSmapTileQueueByType(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                           f32 arg5, f32 arg6, f32 arg7, s32 arg4);
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                          f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                          f32 fparg4, u8 *arg2, s32 arg3,
                          f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                          f32 arg_sp0);
extern u16 D_008C024E[];
extern s32 *MT_Scene_GetFrameState(void);
extern void chkmemAllocSiteTag(const void *msg, s32 id);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern s32 FldMapTestUpdate(u8 *arg0);
extern void FldMapTestDestroy(u8 *arg0);
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
s32 FldMapTestUpdate(u8 *arg0)
{
    extern PadStatus D_008C0240[2];
    extern s64 iGpffff9fd0;
    extern PanelColor iGpffff9fd8;
    extern char iGpffff9fdc[3];
    extern s32 iGpffffb240;
    extern void FldBoardGenerate(s32 mode, s32 value, s32 arg2);
    PanelColor color;
    u8 *state;
    s32 v0;

    state = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)state) {
    case 0:
        *(KwlnTask **)(state + 0x1B438) = sdkLboxCreate((KwlnTask *)arg0, 0x100, 0x40);
        sdkLboxAddDescriptors(*(KwlnTask **)(state + 0x1B438), D_005F5730, 4);
        sdkLboxSetVisibleRows(*(u8 **)(state + 0x1B438), 0x14);
        sdkLboxSetState(*(u8 **)(state + 0x1B438), 4);
        sdkLboxSetSelection(*(u8 **)(state + 0x1B438), 1);
        *(u8 **)(state + 0x1B434) = D_007E3720;
        *(s32 *)state += 1;
        break;
    case 1:
        if (D_008C0240[0].trigger & 0x40) {
            switch (sdkLboxGetSelectedId(*(u8 **)(state + 0x1B438))) {
            case 0:
                *((u8 *)MT_Scene_GetFrameState() + 0x4A) =
                    *(*(u8 **)(state + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)MT_Scene_GetFrameState() + 0x4B) =
                    *(*(u8 **)(state + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(state + 4) = 2;
                v0 = *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 0);
                FldBoardGenerate(*(s32 *)(state + 4), v0, 0);
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 1:
                *((u8 *)MT_Scene_GetFrameState() + 0x4A) =
                    *(*(u8 **)(state + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)MT_Scene_GetFrameState() + 0x4B) =
                    *(*(u8 **)(state + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(state + 4) = 0;
                v0 = *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 1);
                FldBoardGenerate(*(s32 *)(state + 4), v0, 0);
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            case 2:
                *((u8 *)MT_Scene_GetFrameState() + 0x4A) =
                    *(*(u8 **)(state + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 8);
                *((u8 *)MT_Scene_GetFrameState() + 0x4B) =
                    *(*(u8 **)(state + 0x1B434) +
                      *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 3) * 0x10 + 9);
                *(s32 *)(state + 4) = 1;
                v0 = *sdkLboxGetValuePtr(*(KwlnTask **)(state + 0x1B438), 2);
                FldBoardGenerate(*(s32 *)(state + 4), v0, 0);
                kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(state + 0x1B438));
                *(s32 *)state += 1;
                break;
            }
        }
        break;
    case 2:
        *(s32 *)state += 1;
        break;
    case 3:
        *(s32 *)state += 1;
        break;
    case 4:
        if (D_008C0240[0].trigger & 0x8000) {
            *(s32 *)(state + 0x1B430) -= 1;
        } else if (D_008C0240[0].trigger & 0x2000) {
            *(s32 *)(state + 0x1B430) += 1;
        }
        if (*(s32 *)(state + 0x1B430) < 0) {
            *(s32 *)(state + 0x1B430) = 3;
        }
        if (*(s32 *)(state + 0x1B430) > 3) {
            *(s32 *)(state + 0x1B430) = 0;
        }
        if (D_008C0240[0].trigger & 0x40) {
            FldBoardGenerate(*(s32 *)(state + 4), 0, 0);
        }
        func_00450340(iGpffff9fd0, iGpffff9fdc, iGpffffb240);
        {
            s32 y;
            s32 x;
            s32 ty;
            s32 rowOffset;
            u8 *panels;
            s32 type;
            s32 off;
            f32 fx;
            f32 fy;

            for (y = 0; y < 0x18; y++) {
                for (x = 0, rowOffset = y * 0x100, ty = y * 0x12,
                     panels = state + y * 0x1200; x < 0x10; x++) {
                    if (((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][x].occupied != 0 &&
                        (((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][x].flags & 0xF) == 1) {
                        off = x;
                        type = ((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][off].shape;
                        fx = (f32)(x * 0x12);
                        fy = (f32)ty;
                        FldSmapTileQueueByType(D_007966D0, panels + x * 0x120 + 0x10, type, 0, fx, fy, 0.0f, ((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][off].rotation);
                    }
                    if (((MapTestGrid *)(rowOffset + (intptr_t)MT_Scene_GetFrameState()))->cells[0][x].occupied == 2) {
                        color = iGpffff9fd8;
                        FldRc_QueueScreenQuad(D_007966D0, panels + x * 0x120 + 0x10,
                                      (f32)(x * 0x12), (f32)ty, 0.0f, 18.0f, 18.0f,
                                      (u8 *)&color, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
                    }
                }
            }
        }
        if (D_008C0240[0].trigger & 0x20) {
            *(s32 *)state = 0;
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
void FldMapTestDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018EF50
void FldMapTestTaskCreate(s32 arg0)
{
    chkmemAllocSiteTag(&D_005F57B0, 0x101);
    (s32)kwlnTaskCreateChild((void *)((u8 *)arg0), (const void *)(&D_005F57C0), 0xF, 0, 0, FldMapTestUpdate, FldMapTestDestroy, (u8 *)(D_008873F4[0](1, 0x1B440, 0x40000)));
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation off
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018EFE0
s32 FldViewerUpdate(u8 *arg0)
{
    u8 packet[0x20];
    u8 *temp_16;
    s32 temp_17;

    temp_16 = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)temp_16) {
    case 0:
        *(KwlnTask **)(temp_16 + 4) = sdkLboxCreate((KwlnTask *)arg0, 0xDC, 0xA0);
        sdkLboxAddDescriptors(*(KwlnTask **)(temp_16 + 4), D_005F5830, 0xB);
        temp_17 = iGpffffb268 != 0;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 5) = temp_17 ^ 1;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 0) = iGpffffb3a0;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 1) = iGpffffb39c;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 2) = iGpffffb398;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 3) = iGpffffb394;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 4) = iGpffffb390;
        *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 6) = iGpffffb250;
        sdkLboxSetVisibleRows(*(u8 **)(temp_16 + 4), 0x14);
        sdkLboxSetState(*(u8 **)(temp_16 + 4), 4);
        sdkLboxSetSelection(*(u8 **)(temp_16 + 4), 1);
        *(s32 *)temp_16 += 1;
        break;
    case 1:
        iGpffffb268 = *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 5) != 1;
        iGpffffb250 = *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 6);
        if (D_008C024E[0] & 0x40) {
            if (*sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 8) == -1) {
                *(u16 *)(packet + 0) =
                    (u16)*sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 0);
                *(u16 *)(packet + 2) =
                    (u16)*sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 1);
                *(u16 *)(packet + 4) =
                    (u16)*sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 2);
                *(s16 *)(packet + 6) =
                    (s16)*sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 3);
                *(s16 *)(packet + 8) =
                    (s16)*sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 4);
                iGpffffb3a0 = *(u16 *)(packet + 0);
                iGpffffb39c = *(u16 *)(packet + 2);
                iGpffffb398 = *(u16 *)(packet + 4);
                iGpffffb394 = *(s16 *)(packet + 6);
                iGpffffb390 = *(s16 *)(packet + 8);
                func_001029a0(9, packet, 0x1C, 0);
                sdkLboxSetSelection(*(u8 **)(temp_16 + 4), 0);
                *(s32 *)temp_16 = 2;
            } else {
                *(s32 *)(packet + 0xC) =
                    *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 8);
                *(s32 *)(packet + 0x10) =
                    *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 9);
                *(s32 *)(packet + 0x14) =
                    *sdkLboxGetValuePtr(*(KwlnTask **)(temp_16 + 4), 0xA);
                func_001029a0(0xA, packet, 0x1C, 0);
                sdkLboxSetSelection(*(u8 **)(temp_16 + 4), 0);
                *(s32 *)temp_16 = 2;
            }
        } else if (D_008C024E[0] & 0x20) {
            *(s32 *)temp_16 = 3;
        }
        break;
    case 2:
        if (kwlnGetCurrentWorkValue() == 0) {
            iGpffffb3a4 = 0;
            sdkLboxSetSelection(*(u8 **)(temp_16 + 4), 1);
            *(s32 *)temp_16 = 1;
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
void FldViewerDestroy(u8 *arg0)
{
    jtbl_008873EC[0](*(u8 **)(arg0 + 0x38));
}
#pragma pop

/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018f8a0-0018f950 */

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
static inline s32 code1_0018_shift4(s32 value)
{
    return value << 4;
}

static inline s32 code1_0018_add2(s32 first, s32 second)
{
    return first + second;
}

extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *handle);
extern u8 D_007966D0[];
extern void FldSmapTileQueueByType(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3,
                           f32 arg5, f32 arg6, f32 arg7, s32 arg4);
extern void FldRc_QueueScreenQuad(u8 *arg0, u8 *arg1,
                          f32 fparg0, f32 fparg1, f32 fparg2, f32 fparg3,
                          f32 fparg4, u8 *arg2, s32 arg3,
                          f32 fparg5, f32 fparg6, f32 fparg7, s32 arg4,
                          f32 arg_sp0);
extern void FldSmapTileQueueQuad(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4,
                          s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9);
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

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018F8A0
void FldMapTestCellsClear(u8 *arg0, u16 arg1, u16 arg2)
{
    s32 var_9;
    s32 var_8;
    u8 *temp_5;
    u8 *temp_6;
    u8 *temp_7;
    u8 *field;

    temp_7 = (u8 *)code1_0018_add2(
        code1_0018_shift4(arg1 & 0xFFFF),
        ((arg2 & 0xFFFF) << 8) + (s32)arg0);
    if (temp_7[0x2C] != 0 && (temp_7[0x2D] & 0xF) != 0) {
        var_9 = 0;
        while (var_9 < (s32)temp_7[0x33]) {
            var_8 = 0;
            temp_6 = temp_7 + (var_9 << 8);
            while (var_8 < (s32)temp_7[0x32]) {
                temp_5 = temp_6 + var_8 * 0x10;
                field = temp_5 + 0x2C;
                if (*field != 0) {
                    *field = 0;
                    temp_5[0x2D] = 0;
                }
                var_8 += 1;
            }
            var_9 += 1;
        }
    }
}
#pragma pop

extern const KWindowEntryDescriptor D_005F5FD0[];
extern void kwlnSetColorRgba(u8 arg0, u8 arg1, u8 arg2, u8 arg3);
extern s32 sdkLboxAddEntry(u8 *arg0, u8 *arg1);
extern void sprintf(void *dst, const char *fmt, ...);
extern u8 *FldStepLoadFilePair(s32 arg0, s32 arg1);
extern s32 FldStepLoadHandleIsDone(u8 *arg0);
extern void FldStepLoadHandleDestroy(u8 *arg0);
extern s32 func_0015c630(u8 *arg0);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void FldTileRotateAttributes(void *arg0, u32 mask);
typedef struct {
    s16 data[0x2B];
} FieldPanelShape;

void FldMapTestCellsFill(u8 *arg0, s16 *arg1, u16 arg2, u16 arg3, s16 arg4);

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018F950
s32 K_MapEditTask(u8 *arg0)
{
    extern PadStatus D_008C0240[2];
    extern FieldPanelShape D_005F5AC0[];
    static PanelColor board_color = {0x40, 0x40, 0x40, 0xFF};
    static PanelColor icon_color = {0x40, 0x40, 0x40, 0xFF};
    u8 *work;
    u8 *image;
    s32 value;
    u8 text[0x48];
    FieldPanelShape shape;
    PanelColor icon;
    PanelColor board;

    work = *(u8 **)(arg0 + 0x38);
    switch (*(s32 *)work) {
    case 0:
        kwlnSetColorRgba(0, 0x52, 0x76, 0xFF);
        *(s32 *)(work + 0x1D00) = 1;
        *(s32 *)work += 1;
        break;
    case 1:
        *(KwlnTask **)(work + 0x1CD10) = sdkLboxCreate((KwlnTask *)arg0, 0xDC, 0xC8);
        sdkLboxAddDescriptors(*(KwlnTask **)(work + 0x1CD10), D_005F5FD0, 2);
        sdkLboxSetSelection(*(u8 **)(work + 0x1CD10), 1);
        *(s32 *)work += 1;
        break;
    case 2:
        if (D_008C0240[0].trigger & 0x40) {
            *(s16 *)(work + 0x28) = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1CD10), 0);
            *(s16 *)(work + 0x2A) = *sdkLboxGetValuePtr(*(KwlnTask **)(work + 0x1CD10), 1);
            kwlnTaskDestroyWithHierarchy(*(KwlnTask **)(work + 0x1CD10));
            *(u8 **)(work + 0x1CD14) = FldStepLoadFilePair(*(u16 *)(work + 0x28), *(u16 *)(work + 0x2A));
            *(s32 *)(work + 0x1CD10) = sdkLboxCreateEx(arg0, 0x22E, 0x28, 2);
            sprintf(text, "%d-%d", *(u16 *)(work + 0x28), *(u16 *)(work + 0x2A));
            sdkLboxSetState(*(u8 **)(work + 0x1CD10), 1);
            sdkLboxAddEntry(*(u8 **)(work + 0x1CD10), text);
            sdkLboxSetSelection(*(u8 **)(work + 0x1CD10), 1);
            *(s32 *)work += 1;
        }
        break;
    case 3:
        if (FldStepLoadHandleIsDone(*(u8 **)(work + 0x1CD14)) != 0) {
            image = *(u8 **)(work + 0x1CD14);
            if (image != NULL) {
                memcpy(work + 0x2C, *(u8 **)(image + 0x110) + 4, *(s32 *)(image + 0x118) - 4);
                FldStepLoadHandleDestroy(*(u8 **)(work + 0x1CD14));
                *(u8 **)(work + 0x1CD14) = NULL;
            }
            *(s32 *)work += 1;
        }
        break;
    case 4:
        if (D_008C0240[0].repeat & 0x1000) {
            if (*(s32 *)(work + 0x1AB4) > 0) {
                *(s32 *)(work + 0x1AB4) -= 1;
            }
        } else if (D_008C0240[0].repeat & 0x4000) {
            if (*(s32 *)(work + 0x1AB4) < 0x17) {
                *(s32 *)(work + 0x1AB4) += 1;
            }
        }
        if (D_008C0240[0].repeat & 0x8000) {
            if (*(s32 *)(work + 0x1AB0) > 0) {
                *(s32 *)(work + 0x1AB0) -= 1;
            }
        } else if (D_008C0240[0].repeat & 0x2000) {
            if (*(s32 *)(work + 0x1AB0) < 0xF) {
                *(s32 *)(work + 0x1AB0) += 1;
            }
        }
        if (D_008C0240[0].repeat & 1) {
            value = *(s32 *)(work + 0x1D00) - 1;
            *(s32 *)(work + 0x1D00) = value;
            if (value <= 0) {
                *(s32 *)(work + 0x1D00) = 0xE;
            }
        } else if (D_008C0240[0].repeat & 2) {
            value = *(s32 *)(work + 0x1D00) + 1;
            *(s32 *)(work + 0x1D00) = value;
            if (value > 0xE) {
                *(s32 *)(work + 0x1D00) = 1;
            }
        }
        if (D_008C0240[0].repeat & 8) {
            value = *(s32 *)(work + 0x1AB8) - 1;
            *(s32 *)(work + 0x1AB8) = value;
            if (value < 0) {
                *(s32 *)(work + 0x1AB8) = 3;
            }
        } else if (D_008C0240[0].repeat & 4) {
            value = *(s32 *)(work + 0x1AB8) + 1;
            *(s32 *)(work + 0x1AB8) = value;
            if (value > 3) {
                *(s32 *)(work + 0x1AB8) = 0;
            }
        }
        if (D_008C0240[0].trigger & 0x40) {
            shape = D_005F5AC0[*(s32 *)(work + 0x1D00)];
            FldTileRotateAttributes(&shape, 1 << *(s32 *)(work + 0x1AB8));
            FldMapTestCellsFill(work, shape.data, *(s32 *)(work + 0x1AB0), *(s32 *)(work + 0x1AB4),
                          *(s32 *)(work + 0x1AB8));
        } else if (D_008C0240[0].trigger & 0x20) {
            FldMapTestCellsClear(work, *(s32 *)(work + 0x1AB0), *(s32 *)(work + 0x1AB4));
        } else if (D_008C0240[1].trigger & 0x40) {
            func_0015c630(work + 0x28);
        }
        board = board_color;
        FldRc_QueueScreenQuad(D_007966D0, work + 0x1870, 80.0f, 6.0f, 0.0f, 288.0f, 432.0f,
                      (u8 *)&board, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
        icon = icon_color;
        FldRc_QueueScreenQuad(D_007966D0, work + 0x1BE0, 452.0f, 52.0f, 0.0f, 70.0f, 70.0f,
                      (u8 *)&icon, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
        FldSmapTileQueueQuad(D_007966D0, work + 0x1AC0, *(s32 *)(work + 0x1D00), 0, 0x36, 0x36,
                      *(s32 *)(work + 0x1AB8), 460.0f, 60.0f, 0.0f);
        {
            s32 y;

            for (y = 0; y < 0x18; y++) {
                s32 x = 0;
                u8 *cells = work + (y << 8);
                f32 fy = 6.0f + (f32)(y * 0x12);
                u8 *panels = work + y * 0x1200;

                for (; x < 0x10; x++) {
                    u8 *cell = cells + x * 0x10;

                    if (cell[0x2C] != 0 && (cell[0x2D] & 0xF) == 1) {
                        FldSmapTileQueueByType(D_007966D0, panels + x * 0x120 + 0x1D10, cell[0x30], 0,
                                      80.0f + (f32)(x * 0x12), fy, 0.0f, cell[0x31]);
                    }
                }
            }
        }
        FldSmapTileQueueByType(D_007966D0, work + 0x1990, *(s32 *)(work + 0x1D00), 0,
                      80.0f + 18.0f * (f32)*(s32 *)(work + 0x1AB0),
                      6.0f + 18.0f * (f32)*(s32 *)(work + 0x1AB4), 0.0f, *(s32 *)(work + 0x1AB8));
        break;
    case 5:
        return -1;
    }
    return 0;
}
#pragma pop

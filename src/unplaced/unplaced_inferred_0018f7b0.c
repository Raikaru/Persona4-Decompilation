/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018f8a0-0018f950 */

#include "field_transition_internal.h"
#include "member_access.h"
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
#include "h_cdvd_request_internal.h"
/* Allocated as 0x1CD20 bytes by K_MapEdit_Create. Cell rows occupy 0x100 bytes. */
typedef struct FldMapEditorWork {
    s32 state;
    s32 dictionaries[9];
    union { s16 signedId; u16 id; } field;
    union { s16 signedId; u16 id; } room;
    FldFrameCell cells[24][16];
    u8 pad182C[0x1AB0 - 0x182C];
    s32 cursorColumn, cursorRow, rotation;
    u8 pad1ABC[0x1D00 - 0x1ABC];
    s32 tileType;
    u8 pad1D04[0x1CD10 - 0x1D04];
    union { KwlnTask *task; u8 *bytes; s32 handle; } list;
    u8 *loadHandle;
    u8 pad1CD18[8];
} FldMapEditorWork;

static inline s32 fldMapCellColumnOffset(s32 value)
{
    return value << 4;
}

static inline s32 fldMapCellAddOffset(s32 first, s32 second)
{
    return first + second;
}

extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
extern u8 D_007966D0[];
extern void FldSmapTileQueueByType(u8 *queue, u8 *context, s32 tileType, s32 variant,
                           f32 x, f32 y, f32 depth, s32 flags);
extern void FldRc_QueueScreenQuad(u8 *queue, u8 *quad,
                          f32 left, f32 top, f32 depthOffset, f32 width,
                          f32 height, u8 *color, s32 texture,
                          f32 uMin, f32 vMin, f32 uMax, s32 orientation,
                          f32 vMax);
extern void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                          s32 height, s32 flags, f32 x, f32 y, f32 depth);
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
/* Clear occupied cells in the selected shape's rectangular footprint.
 * Empty selections and cells without shape flags leave the grid unchanged. */
// FUN_0018F8A0
void FldMapTestCellsClear(u8 *work, u16 column, u16 row)
{
    s32 rowIndex;
    s32 columnIndex;
    u8 *cellBase;
    u8 *rowBase;
    u8 *selectedBase;
    u8 *occupied;

    selectedBase = (u8 *)fldMapCellAddOffset(
        fldMapCellColumnOffset(column & 0xFFFF),
        ((row & 0xFFFF) << 8) + (s32)work);
    if (((FldFrameCell *)(selectedBase + 0x2C))->occupied != 0 && (((FldFrameCell *)(selectedBase + 0x2C))->flags & 0xF) != 0) {
        rowIndex = 0;
        while (rowIndex < (s32)((FldFrameCell *)(selectedBase + 0x2C))->shapeZ) {
            columnIndex = 0;
            rowBase = selectedBase + (rowIndex << 8);
            while (columnIndex < (s32)((FldFrameCell *)(selectedBase + 0x2C))->shapeX) {
                cellBase = rowBase + columnIndex * 0x10;
                occupied = &((FldFrameCell *)(cellBase + 0x2C))->occupied;
                if (*occupied != 0) {
                    *occupied = 0;
                    ((FldFrameCell *)(cellBase + 0x2C))->flags = 0;
                }
                columnIndex += 1;
            }
            rowIndex += 1;
        }
    }
}
#pragma pop

extern const KWindowEntryDescriptor D_005F5FD0[];
extern void kwlnSetColorRgba(u8 red, u8 green, u8 blue, u8 alpha);
extern s32 sdkLboxAddEntry(u8 *task, u8 *text);
extern void sprintf(void *dst, const char *fmt, ...);
extern u8 *FldStepLoadFilePair(s32 fieldId, s32 roomId);
extern s32 FldStepLoadHandleIsDone(u8 *handle);
extern void FldStepLoadHandleDestroy(u8 *handle);
extern s32 fldStepLoadHandleAlwaysReady(u8 *unusedHandle);
extern void *memcpy(void *dst, const void *src, u32 size);
extern void FldTileRotateAttributes(void *templateData, u32 directionMask);
typedef struct {
    s16 data[0x2B];
} FieldPanelShape;

void FldMapTestCellsFill(u8 *grid, s16 *shapeData, u16 x, u16 y, s16 rotation);

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
// FUN_0018F950
/* Load a field grid, edit cell shapes/orientations, and queue its preview quads. */
s32 K_MapEditTask(u8 *task)
{
    extern PadStatus D_008C0240[2];
    extern FieldPanelShape D_005F5AC0[];
    static PanelColor boardColor = {0x40, 0x40, 0x40, 0xFF};
    static PanelColor iconColor = {0x40, 0x40, 0x40, 0xFF};
    /* The editor fields are proven by cursor/menu uses; MEMBER preserves measured reloads. */
    u8 *work;
    /* HCdvdRequest supplies the loaded cell payload and its byte size. */
    u8 *image;
    s32 value;
    u8 text[0x48];
    FieldPanelShape shape;
    PanelColor icon;
    PanelColor board;

    work = ((KwlnTask *)task)->work;
    switch (*(s32 *)work) {
    case 0:
        kwlnSetColorRgba(0, 0x52, 0x76, 0xFF);
        ((FldMapEditorWork *)(work))->tileType = 1;
        *(s32 *)work += 1;
        break;
    case 1:
        ((FldMapEditorWork *)(work))->list.task = sdkLboxCreate((KwlnTask *)task, 0xDC, 0xC8);
        sdkLboxAddDescriptors(MEMBER(KwlnTask *, work, FldMapEditorWork, list.task), D_005F5FD0, 2);
        sdkLboxSetSelection(MEMBER(u8 *, work, FldMapEditorWork, list.bytes), 1);
        *(s32 *)work += 1;
        break;
    case 2:
        if (D_008C0240[0].trigger & 0x40) {
            ((FldMapEditorWork *)(work))->field.signedId = *sdkLboxGetValuePtr(((FldMapEditorWork *)(work))->list.task, 0);
            ((FldMapEditorWork *)(work))->room.signedId = *sdkLboxGetValuePtr(MEMBER(KwlnTask *, work, FldMapEditorWork, list.task), 1);
            kwlnTaskDestroyWithHierarchy(MEMBER(KwlnTask *, work, FldMapEditorWork, list.task));
            ((FldMapEditorWork *)(work))->loadHandle = FldStepLoadFilePair(MEMBER(u16, work, FldMapEditorWork, field.id), MEMBER(u16, work, FldMapEditorWork, room.id));
            MEMBER(s32, work, FldMapEditorWork, list.handle) = sdkLboxCreateEx(task, 0x22E, 0x28, 2);
            sprintf(text, "%d-%d", MEMBER(u16, work, FldMapEditorWork, field.id), MEMBER(u16, work, FldMapEditorWork, room.id));
            sdkLboxSetState(MEMBER(u8 *, work, FldMapEditorWork, list.bytes), 1);
            sdkLboxAddEntry(MEMBER(u8 *, work, FldMapEditorWork, list.bytes), text);
            sdkLboxSetSelection(MEMBER(u8 *, work, FldMapEditorWork, list.bytes), 1);
            *(s32 *)work += 1;
        }
        break;
    case 3:
        if (FldStepLoadHandleIsDone(((FldMapEditorWork *)(work))->loadHandle) != 0) {
            image = MEMBER(u8 *, work, FldMapEditorWork, loadHandle);
            if (image != NULL) {
                memcpy(work + 0x2C, (u8 *)((HCdvdRequest *)(image))->data + 4, ((HCdvdRequest *)(image))->signedSize - 4);
                FldStepLoadHandleDestroy(MEMBER(u8 *, work, FldMapEditorWork, loadHandle));
                MEMBER(u8 *, work, FldMapEditorWork, loadHandle) = NULL;
            }
            *(s32 *)work += 1;
        }
        break;
    case 4:
        if (D_008C0240[0].repeat & 0x1000) {
            if (((FldMapEditorWork *)(work))->cursorRow > 0) {
                MEMBER(s32, work, FldMapEditorWork, cursorRow) -= 1;
            }
        } else if (D_008C0240[0].repeat & 0x4000) {
            if (((FldMapEditorWork *)(work))->cursorRow < 0x17) {
                MEMBER(s32, work, FldMapEditorWork, cursorRow) += 1;
            }
        }
        if (D_008C0240[0].repeat & 0x8000) {
            if (((FldMapEditorWork *)(work))->cursorColumn > 0) {
                MEMBER(s32, work, FldMapEditorWork, cursorColumn) -= 1;
            }
        } else if (D_008C0240[0].repeat & 0x2000) {
            if (((FldMapEditorWork *)(work))->cursorColumn < 0xF) {
                MEMBER(s32, work, FldMapEditorWork, cursorColumn) += 1;
            }
        }
        if (D_008C0240[0].repeat & 1) {
            value = ((FldMapEditorWork *)(work))->tileType - 1;
            ((FldMapEditorWork *)(work))->tileType = value;
            if (value <= 0) {
                MEMBER(s32, work, FldMapEditorWork, tileType) = 0xE;
            }
        } else if (D_008C0240[0].repeat & 2) {
            value = ((FldMapEditorWork *)(work))->tileType + 1;
            ((FldMapEditorWork *)(work))->tileType = value;
            if (value > 0xE) {
                MEMBER(s32, work, FldMapEditorWork, tileType) = 1;
            }
        }
        if (D_008C0240[0].repeat & 8) {
            value = ((FldMapEditorWork *)(work))->rotation - 1;
            ((FldMapEditorWork *)(work))->rotation = value;
            if (value < 0) {
                MEMBER(s32, work, FldMapEditorWork, rotation) = 3;
            }
        } else if (D_008C0240[0].repeat & 4) {
            value = ((FldMapEditorWork *)(work))->rotation + 1;
            ((FldMapEditorWork *)(work))->rotation = value;
            if (value > 3) {
                MEMBER(s32, work, FldMapEditorWork, rotation) = 0;
            }
        }
        if (D_008C0240[0].trigger & 0x40) {
            shape = D_005F5AC0[((FldMapEditorWork *)(work))->tileType];
            FldTileRotateAttributes(&shape, 1 << ((FldMapEditorWork *)(work))->rotation);
            FldMapTestCellsFill(work, shape.data, ((FldMapEditorWork *)(work))->cursorColumn, ((FldMapEditorWork *)(work))->cursorRow,
                          MEMBER(s32, work, FldMapEditorWork, rotation));
        } else if (D_008C0240[0].trigger & 0x20) {
            FldMapTestCellsClear(work, ((FldMapEditorWork *)(work))->cursorColumn, ((FldMapEditorWork *)(work))->cursorRow);
        } else if (D_008C0240[1].trigger & 0x40) {
            fldStepLoadHandleAlwaysReady(work + 0x28);
        }
        board = boardColor;
        FldRc_QueueScreenQuad(D_007966D0, work + 0x1870, 80.0f, 6.0f, 0.0f, 288.0f, 432.0f,
                      (u8 *)&board, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
        icon = iconColor;
        FldRc_QueueScreenQuad(D_007966D0, work + 0x1BE0, 452.0f, 52.0f, 0.0f, 70.0f, 70.0f,
                      (u8 *)&icon, 0, 0.0f, 0.0f, 0.0f, 0, 0.0f);
        FldSmapTileQueueQuad(D_007966D0, work + 0x1AC0, ((FldMapEditorWork *)(work))->tileType, 0, 0x36, 0x36,
                      ((FldMapEditorWork *)(work))->rotation, 460.0f, 60.0f, 0.0f);
        {
            s32 y;

            for (y = 0; y < 0x18; y++) {
                s32 x = 0;
                u8 *cells = work + (y << 8);
                f32 screenY = 6.0f + (f32)(y * 0x12);
                u8 *panels = work + y * 0x1200;

                for (; x < 0x10; x++) {
                    u8 *cell = cells + x * 0x10;

                    if (((FldFrameCell *)(cell + 0x2C))->occupied != 0 && (((FldFrameCell *)(cell + 0x2C))->flags & 0xF) == 1) {
                        FldSmapTileQueueByType(D_007966D0, panels + x * 0x120 + 0x1D10, ((FldFrameCell *)(cell + 0x2C))->type, 0,
                                      80.0f + (f32)(x * 0x12), screenY, 0.0f, ((FldFrameCell *)(cell + 0x2C))->kind);
                    }
                }
            }
        }
        FldSmapTileQueueByType(D_007966D0, work + 0x1990, MEMBER(s32, work, FldMapEditorWork, tileType), 0,
                      80.0f + 18.0f * (f32)((FldMapEditorWork *)(work))->cursorColumn,
                      6.0f + 18.0f * (f32)((FldMapEditorWork *)(work))->cursorRow, 0.0f, MEMBER(s32, work, FldMapEditorWork, rotation));
        break;
    case 5:
        return -1;
    }
    return 0;
}
#pragma pop

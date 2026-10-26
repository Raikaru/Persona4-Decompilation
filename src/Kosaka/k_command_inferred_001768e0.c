#include "Kosaka/k_field_state_internal.h"
#include "mdl_file_internal.h"
#include "resrc_manager_internal.h"
#include "btl_target_state_packet_internal.h"
#include "Kosaka/k_command_internal.h"
#include "mt_scene_internal.h"
#include "field_transition_internal.h"
#include "model_callbacks_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "field_shadow_internal.h"
#include "rw_atomic_internal.h"
#include "Kosaka/k_clump_internal.h"
struct RpGeometry;
#include "sdk_snd_internal.h"
#include "rw/plcore/barenderstate.h"
typedef struct RwRGBA RwRGBA;
typedef s32 (*FieldRenderStateSetFunction)(RwRenderState, void *);
struct Model;
typedef struct
{
    f32 first;
    s32 pad;
    f32 second;
} F2_0017;
typedef struct
{
    u8 pad_00178590[0x144];
    u8 *field_144;
} S_00178590;
typedef struct
{
    f32 x;
    f32 y;
    f32 z;
} Vec3_00178590;
typedef struct
{
    u8 red;
    u8 green;
    u8 blue;
    u8 alpha;
} FieldColor_0017;
extern s32 *MT_Scene_GetFrameState(void);
/* measured: left unprototyped because retail applies default argument promotion order when masking
 * the u16 arguments in Cmd_PickEncounter. */
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
/* These linker aliases begin inside FldPartySlot, at active and resource respectively.
 * Each array advances by the complete 0x750-byte slot stride without rebasing the symbol. */
typedef struct FldPartyActiveColumn {
    s32 active;
    u8 stridePad04[0x74C];
} FldPartyActiveColumn;
typedef struct FldPartyResourceColumn {
    union { s32 address; u16 *id; };
    u8 stridePad04[0x74C];
} FldPartyResourceColumn;
extern FldPartyActiveColumn D_007EF9F8[];
extern FldPartyResourceColumn D_007EFA04[];
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern u8 D_007EF9B0[];
extern u8 D_005F18C0[];
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_005F1910[];
extern u8 D_007F1740[];
extern u8 D_005F1950[];
extern u8 D_005F1A60[];
extern u8 D_005F1A64[];
extern u16 D_008C024E[];
void FldSmapTileQueueQuad(u8 *queue, u8 *context, s32 tileType, s32 variant, s32 width,
                    s32 height, s32 flags, f32 x, f32 y, f32 depth);

extern f32 iGpffff8304;
extern char D_005E5850[];
extern f32 iGpffff82fc;
extern u8 D_00794E70[];


extern u8 *MT_Scene_GetResListHead(s32 resourceType);

extern s64 datGetPartyId(s32 idx);
extern s32 FldShadow_DrawProjection(u8 *camera, s32 raster, s32 collisionKind, void *intersection,
                         f32 opacity, f32 depth, s32 fadeWithDepth, u8 *workData);
extern u8 D_007EFA00[];
extern u8 D_005F1970[];
extern u8 D_005F1974[];
extern u8 D_005F1978[];
extern u8 D_005F197C[];
extern u8 D_005F1AE0[];
extern u8 D_005F1B00[];
extern u8 iGpffff9f54;
extern f32 iGpffff826c;
extern f32 iGpffff8214;
extern f32 iGpffff8360;
extern u32 iGpffffb308;
extern u32 iGpffff9f4c;
extern u32 iGpffffb30c;
extern u32 iGpffff9f50;
extern s32 D_005F1930[];
extern s32 D_005F1934[];

extern u8 *D_007643D0;
extern FieldRenderStateSetFunction D_00887300[];
extern s32 iGpffffba48;


/* Resolve a party slot to its active field resource and return its resource identifier. Slot data
 * is read through typed 0x750-stride column arrays, not a pointer to the slot start. */
// FUN_001768E0
s32 Cmd_GetFieldPartyValue(void)
{
    s32 slotAddress;
    s32 candidatePresent;
    s32 slotIndex;
    u16 candidateId;
    s32 partyIndex;
    u16 resourceId;
    s32 selectedPresent;

    partyIndex = scrGetParamInt(0);
    resourceId = 0;
    if (partyIndex != 0) {
        slotIndex = 0;
        goto loop_8_cond;
loop_8_body:
        candidatePresent = 0;
        slotAddress = (s32)((u8 *)D_007EF9B0 + (slotIndex * 0x750));
        if (((FldPartySlot *)slotAddress)->active != 0) {
            if ((s32)((FldPartySlot *)slotAddress)->resource != 0)
                candidatePresent = 1;
        }
        candidatePresent = (candidatePresent != 0);
        if ((candidatePresent != 1) ||
            (candidateId = ((FldPartySlot *)slotAddress)->memberId,
             candidateId != (s16)datGetPartyId(partyIndex - 1))) {
            slotIndex += 1;
            goto loop_8_cond;
        }
        goto loop_8_found;
loop_8_cond:
        if (slotIndex < 4)
            goto loop_8_body;
loop_8_found:
        ;
        if (slotIndex >= 4) {
            scrSetReturnInt(0);
            return 1;
        }
        partyIndex = slotIndex;
    }
block_12:
    selectedPresent = 0;
    if ((D_007EF9F8[partyIndex].active != 0) &&
        (D_007EFA04[partyIndex].address != 0))
        selectedPresent = 1;
    selectedPresent = (selectedPresent != 0);
    if (selectedPresent == 1)
        resourceId = *D_007EFA04[partyIndex].id;
    scrSetReturnInt(resourceId & 0xFFFF);
    return 1;
}

/* Count the linked NPC resource records and publish the result to the script. */
// FUN_00176A50
s32 Cmd_CountResListEntries(void)
{
    u8 *node;
    s32 count;

    node = (u8 *)MT_Scene_GetResListHead(3);
    count = 0;
    while (node != NULL) {
        count += 1;
        node = (u8 *)((ResrcRecord *)node)->next;
    }
    scrSetReturnInt(count);
    return 1;
}

/* Find a resource by list index and derive its level from its model identifier. */
// FUN_00176AB0
s32 Cmd_GetResListEntryLevel(void)
{
    s32 targetIndex;
    s32 resourceIndex;
    s32 level;
    u16 modelId;
    u8 *resource;

    targetIndex = scrGetParamInt(0);
    resource = MT_Scene_GetResListHead(3);
    level = 0;
    resourceIndex = 0;
    goto loop_3_cond;
loop_3_body:
    if (targetIndex == resourceIndex)
        goto loop_3_done;
    resourceIndex += 1;
    resource = (u8 *)((ResrcRecord *)resource)->next;
loop_3_cond:
    if (resource != NULL)
        goto loop_3_body;
loop_3_done:
    if (resource != NULL) {
        modelId = ((MdlFileModel *)((u8 *)((ResrcRecord *)resource)->modelHandle164))->id;
        level = (modelId / 50) + 1;
        if ((s32)modelId > 0x1F4)
            level = 0;
    }
    scrSetReturnInt(level);
    return 1;
}

/* Return the active field identifier, or zero when no root field task exists. */
// FUN_00176B60
s32 Cmd_GetCurrentFieldMajorId(void) {
    s32 fieldId;

    fieldId = 0;
    if (((FldSceneTasks *)MT_Scene_GetFrameState())->root != 0) {
        fieldId = FldLoadTaskFieldId((u8 *)((FldSceneTasks *)MT_Scene_GetFrameState())->root) & 0xFFFF;
    }
    scrSetReturnInt(fieldId);
    return 1;
}

/* Return the active room identifier, or zero when no root field task exists. */
// FUN_00176BC0
s32 Cmd_GetCurrentFieldMinorId(void) {
    s32 roomId;

    roomId = 0;
    if (((FldSceneTasks *)MT_Scene_GetFrameState())->root != 0) {
        roomId = FldLoadTaskRoomId((u8 *)((FldSceneTasks *)MT_Scene_GetFrameState())->root) & 0xFFFF;
    }
    scrSetReturnInt(roomId);
    return 1;
}


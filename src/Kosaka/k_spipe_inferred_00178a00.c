#include "btl_target_state_packet_internal.h"
#include "Kosaka/k_command_internal.h"
#include "mt_scene_internal.h"
#include "rw_geometry_internal.h"
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
/* Cmd_PickEncounter is called unprototyped so its u16 arguments get old-style default promotion,
 * matching retail's masking order. */
extern s32 iGpffffb284;
extern s32 iGpffffb300;
extern s32 iGpffffb304;
extern u8 gMtScene[];
extern u8 *iGpffff9db0;
extern s32 D_007EF9F8[];
extern u32 D_007EFA04[];
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


/* Script getters share this sparse state view: the current record pointer is
 * read at 0x160. Only fields observed by these getters are represented. */
typedef struct SpipeRecord
{
    u16 unk00;
    u16 id;
    u8 level;
    u8 unk05;
    u8 kind;
    u8 flags;
    s32 state;
} SpipeRecord;
typedef struct SpipeScriptState
{
    u8 pad00[8];
    s32 finished;
    u16 stateIndex;
    u8 pad0E[0x152];
    SpipeRecord *record;
} SpipeScriptState;

/* Return the current state index through the script VM result slot. */
// FUN_00178A00
s32 K_Spipe_GetStateIndex(void)
{
    scrSetReturnInt(((SpipeScriptState *)D_007643D0)->stateIndex);
    return 1;
}

/* Map the record ID ranges to script bands, with state overriding to band four. */
// FUN_00178A30
s32 K_Spipe_GetRecordBand(void)
{
    u16 recordId;
    SpipeRecord *record;

    record = ((SpipeScriptState *)D_007643D0)->record;
    if (record->state != 0) {
        scrSetReturnInt(4);
    } else {
        recordId = record->id;
        if ((s32)recordId >= 0x500) {
            scrSetReturnInt(3);
        } else if ((s32)recordId >= 0x400) {
            scrSetReturnInt(2);
        } else if ((s32)recordId >= 0x300) {
            scrSetReturnInt(1);
        } else {
            scrSetReturnInt(0);
        }
    }
    return 1;
}

/* Publish whether bit zero enables the current record through the script result slot. */
// FUN_00178AF0
s32 K_Spipe_IsRecordEnabled(void)
{
    scrSetReturnInt((((SpipeScriptState *)D_007643D0)->record->flags & 1) != 0);
    return 1;
}

/* Report the record state, preserving the original zero-result path. */
// FUN_00178B30
s32 K_Spipe_GetRecordState(void)
{
  s32 value;
  s32 result;
  u8 *state = D_007643D0;
  /* Preserve the existing empty condition: changing this matching-required
     shape is outside the readability-only cutover. */
  if (value && value) {}
  result = 0;
  value = ((SpipeScriptState *)state)->record->state;
  if (value)
    result = value;
  scrSetReturnInt(result);
  return 1;
}

/* Publish the current record's halfword identifier through the script result slot. */
// FUN_00178B70
s32 K_Spipe_GetRecordId(void)
{
    scrSetReturnInt(((SpipeScriptState *)D_007643D0)->record->id);
    return 1;
}

/* Publish the current record's byte-sized kind, widened to an unsigned script value. */
// FUN_00178BA0
s32 K_Spipe_GetRecordKind(void)
{
    scrSetReturnInt((u16)((SpipeScriptState *)D_007643D0)->record->kind);
    return 1;
}

/* Publish the current record's byte-sized level, widened to an unsigned script value. */
// FUN_00178BD0
s32 K_Spipe_GetRecordLevel(void)
{
    scrSetReturnInt((u16)((SpipeScriptState *)D_007643D0)->record->level);
    return 1;
}

/* Mark the active pipe state finished and detach it from the script-facing global. */
// FUN_00178C00
/* Returns the stored constant because retail stores the 1 from the return-value register. */
s32 K_Spipe_Finish(void)
{
    ((SpipeScriptState *)D_007643D0)->finished = 1;
    D_007643D0 = 0;
    return 1;
}


/* Inferred unit: no __FILE__ evidence; boundaries from absence of callee, caller or P3 twin evidence; members 0018c610-0018c610 */

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
typedef struct RwTexture RwTexture;

#include "scene_event_internal.h"
typedef struct RpMaterial *(*MaterialCallback)(struct RpMaterial *, void *);

extern s32 K_Clump_MatUsrDataHasData(u8 *material, u8 *name);
extern struct RpMaterial *func_003c42b0(struct RpMaterial *material, RwTexture *texture);
extern u8 D_005F5438[];
typedef struct MaterialTextureContext {
    s32 found;
    RwTexture *texture;
} MaterialTextureContext;

/* Unit settings for the material texture callback. */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma optimization_level 2
#pragma enable_vu0_registers off
#pragma vu0_mmi_reg_binding off
/* Replace the texture only on materials carrying the mipmap user-data tag. */
// FUN_0018C610
struct RpMaterial *FldRcMaterialSetMipmapTex(struct RpMaterial *material, void *data) {
    MaterialTextureContext *context = data;

    if (K_Clump_MatUsrDataHasData((u8 *)material, D_005F5438) != 0) {
        context->found = 1;
        func_003c42b0(material, context->texture);
    }
    return material;
}
#pragma pop

#ifndef MODEL_BATTLE_INTERNAL_H
#define MODEL_BATTLE_INTERNAL_H

#include "type.h"
#include "mdl_file_internal.h"
#include "mdl_attachment_internal.h"

/* Partial Model layout, using the canonical member names from mdlManager.c.
 * Its layer blend is at 0xEC + 0x1C; the remaining fields are shared by the
 * battle-state setters and mdlManager's draw/motion state consumers. */
typedef struct Model {
    u8 pad00[0xD8];
    s32 flags;
    u8 padDC[0xF4 - 0xDC];
    f32 layerSpeed;              /* 0xF4: layers[0].speed, mdlSetLayerWeight */
    u8 padF8[0x108 - 0xF8];
    f32 layerBlend;              /* 0x108: layers[0].blend */
    u8 pad10C[0x260 - 0x10C];
    u8 drawFlags;
    u8 pad261[0x274 - 0x261];
    f32 limit;
    f32 targetLimit;
    f32 limitRate;
    u8 pad280[0x28C - 0x280];
    MdlWpnSlot attachedWpns[5];
    u8 pad2C8[0x2D0 - 0x2C8];
    MdlMotionState motion;
    void *queue;                 /* 0x2F8 */
} Model;

#endif

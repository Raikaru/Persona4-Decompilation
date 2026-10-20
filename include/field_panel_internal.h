#ifndef FIELD_PANEL_INTERNAL_H
#define FIELD_PANEL_INTERNAL_H
#include "type.h"

/* Sky2 primitive vertices use a 0x40-byte record in both panel quads. */
typedef struct FldPanelVertex {
    f32 x, y, z, cameraZ;
    f32 u, v, reciprocalZ, fog;
    f32 red, green, blue, alpha;
    f32 normalX, normalY, normalZ, reserved;
} FldPanelVertex;

/* Field 2D panel task work, allocated as 0x230 bytes in FldPanel2dTaskCreate.
 * The eight vertices at +0x20 form two four-vertex primitive quads. */
typedef struct FldPanel2dWork {
    s32 state;             /* 0x00: update step, 0 setup, 1 slide in, 2 draw, 3 idle */
    s32 hidden;            /* 0x04: 1 suppresses the update (FldPanel2dSetState) */
    s32 side;              /* 0x08: 0 or 1, the text slot currently shown */
    s32 blinkTimer;        /* 0x0C: frames of the side-change animation */
    union { const char *text[2]; s32 textHandles[2]; }; /* 0x10: alternating text slots */
    union { f32 slotX[2]; s32 slotXBits[2]; }; /* 0x18: coordinates, also initialized by word bits */
    FldPanelVertex vertices[8]; /* 0x20: two Sky2 primitive quads */
    s32 animFrame;         /* 0x220: frame counter of the slide-in */
    f32 posX;              /* 0x224 */
    f32 posY;              /* 0x228 */
    f32 alpha;             /* 0x22C: sine-eased progress; the draw step runs once it reaches 1.0 */
} FldPanel2dWork;

#endif

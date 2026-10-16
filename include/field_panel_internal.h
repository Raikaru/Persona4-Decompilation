#ifndef FIELD_PANEL_INTERNAL_H
#define FIELD_PANEL_INTERNAL_H
#include "type.h"

/* Field 2D panel task work, the 0x230-byte block at task+0x38 (allocated in
 * FldPanel2dTaskCreate). The panel task is stored in FldFrame.panelTask. The
 * 0x200 bytes at 0x20 hold the primitive quads and their per-quad state; their
 * exact layout is not typed here. */
typedef struct FldPanel2dWork {
    s32 state;             /* 0x00: update step, 0 setup, 1 slide in, 2 draw, 3 idle */
    s32 hidden;            /* 0x04: 1 suppresses the update (FldPanel2dSetState) */
    s32 side;              /* 0x08: 0 or 1, the text slot currently shown */
    s32 blinkTimer;        /* 0x0C: frames of the side-change animation */
    const char *text[2];   /* 0x10: text for each slot, drawn by FldPanel2dUpdate */
    f32 slotX[2];          /* 0x18: horizontal position per slot */
    u8 unk20[0x200];       /* 0x20: primitive quads, measured extent */
    s32 animFrame;         /* 0x220: frame counter of the slide-in */
    f32 posX;              /* 0x224 */
    f32 posY;              /* 0x228 */
    f32 alpha;             /* 0x22C: sine-eased progress; the draw step runs once it reaches 1.0 */
} FldPanel2dWork;

#endif

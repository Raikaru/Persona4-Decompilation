#ifndef RADAR_MENU_INTERNAL_H
#define RADAR_MENU_INTERNAL_H

#include "type.h"

/* radarAnimateValue (001437B0) interpolates the three snapshots and clamps
 * its frame to [startFrame, endFrame]. Word aliases preserve constant bit
 * stores used by the initialization code, without converting float values. */
typedef union MenuAnimValue {
    f32 f;
    s32 s;
    u32 u;
} MenuAnimValue;

typedef union MenuAnimAlpha {
    u8 u;
    s8 s;
} MenuAnimAlpha;

typedef struct MenuSlotAnimation {
    MenuAnimValue startX;       /* 0x00 */
    MenuAnimValue startY;       /* 0x04 */
    MenuAnimValue targetX;      /* 0x08 */
    MenuAnimValue targetY;      /* 0x0C */
    MenuAnimValue currentX;     /* 0x10 */
    MenuAnimValue currentY;     /* 0x14 */
    MenuAnimAlpha startAlpha;   /* 0x18 */
    u8 targetAlpha;             /* 0x19 */
    u8 currentAlpha;            /* 0x1A */
    u8 pad1B;
    u16 startScaleX;            /* 0x1C */
    u16 targetScaleX;           /* 0x1E */
    u16 currentScaleX;          /* 0x20 */
    u16 startScaleY;            /* 0x22 */
    u16 targetScaleY;           /* 0x24 */
    u16 currentScaleY;          /* 0x26 */
    MenuAnimValue startFrame;   /* 0x28: signed frame, also stored as a word */
    MenuAnimValue endFrame;     /* 0x2C */
} MenuSlotAnimation;

typedef union RadarSprite {
    s32 handle;
    u8 *node;
    void *object;
} RadarSprite;

typedef struct RadarInventoryEntry {
    s16 id;
    s16 count;
} RadarInventoryEntry;

typedef struct RadarGridEntry {
    s32 unk0;
    s32 column;
    s32 row;
    s32 columns;
    s32 rows;
} RadarGridEntry;

/* titleStateInit clears exactly 0x1BE8 bytes. The loops establish all array
 * strides/counts; the slot and indicator renderers establish the subfields. */
typedef struct RadarMenu {
    u8 opacity;                         /* 0x0000 */
    u8 pad1[3];
    MenuAnimValue x;
    MenuAnimValue y;
    u8 padC[4];
    s32 unk10;
    s32 flags;                          /* 0x0014 */
    s32 mode;
    s16 entryFrame;                     /* 0x001C */
    s16 scatterFrame;
    s16 indicatorFrame;
    s16 selection[3];                   /* 0x0022 */
    s16 previousSelection[3];           /* 0x0028 */
    u8 pad2E[2];
    u32 layout;                         /* 0x0030 */
    s16 partyIds[4];
    s16 partyCount;                     /* 0x003C */
    RadarInventoryEntry inventory[768]; /* 0x003E */
    s16 inventoryCount;                 /* 0x0C3E */
    s16 unkC40;
    u8 padC42[6];
    RadarGridEntry grid[84];            /* 0x0C48 */
    MenuSlotAnimation entries[30];      /* 0x12D8 */
    MenuSlotAnimation scatter[12];      /* 0x1878 */
    MenuSlotAnimation indicators[2];    /* 0x1AB8 */
    RadarSprite sprites[51];            /* 0x1B18 */
    u8 *spritePack;                     /* 0x1BE4 */
} RadarMenu;

/* Separate eleven-slot title selector; it is not a RadarMenu. */
typedef struct TitleSlotMenu {
    u8 pad0[0xC];
    s16 frame;
    u8 padE[2];
    s32 selection;
    s32 previousSelection;
    s32 mode;
    u8 pad1C[0x1C];
    s32 slotCount;                      /* 0x38 */
    s32 sprites[21];                    /* 0x3C */
    u8 pad90[4];
    MenuSlotAnimation slots[11];        /* 0x94 */
} TitleSlotMenu;

/* The cmpSystem/community panel menu is a separate allocation from RadarMenu.
 * Its 29 animations use the same radarAnimateValue 0x30-byte block. Release
 * establishes 42 sprite handles at +0x658 and an optional child at +0x704. */
#include "fcl_draw_types.h"

typedef struct RadarBarTarget {
    s16 target, bound, countdown, current, stepCountdown;
} RadarBarTarget;

typedef struct RadarMenuWork {
    u8 alpha;
    u8 pad1[3];
    MenuAnimValue x, y;
    u16 fadeFrame;
    u8 padE[2];
    s32 background;
    s32 state;
    u8 pad18[4];
    s32 drawFlags;
    s16 elapsed, topWaveFrame, bottomWaveFrame, slideElapsed;
    s16 selectedHeader, selectedRow, topRow;
    u8 pad2E[4];
    s16 previousTopRow, footerMode;
    u8 pad36[2];
    s32 rowCount;
    s8 messageSlot;
    u8 pad3D[3];
    FclVec2 cursor;
    MenuSlotAnimation panels[29];
    MenuSlotAnimation slide;
    RadarBarTarget bars[11];
    u8 pad656[2];
    RadarSprite sprites[42];
    s32 footerResource;
    RadarSprite configTask;
} RadarMenuWork;

#endif

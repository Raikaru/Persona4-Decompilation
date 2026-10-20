#ifndef CAMP_MENU_INTERNAL_H
#define CAMP_MENU_INTERNAL_H

#include "radar_menu_internal.h"
#include "sfl_persona_internal.h"

/* The camp radar owns 0x18B0 bytes (radarInitState). Its 41 animation
 * records share the 0x30-byte format used by radarAnimateValue. */
typedef struct CampGridEntry {
    s16 id;
    u8 pad2[2];
    s32 column;
    s32 row;
    s32 columns;
    s32 rows;
} CampGridEntry;

typedef struct CampMenu {
    u8 opacity;
    u8 pad1[3];
    MenuAnimValue x;
    MenuAnimValue y;
    u16 fadeFrame;
    u8 padE[2];
    s32 background;
    s32 stage;
    s32 mode;
    s32 flags;
    s16 frame;
    s16 partyIds[8];
    s16 partyCount;
    s16 selection[2];
    s16 labelKind;
    u8 pad3A[2];
    RadarSprite wipeTask;
    MenuSlotAnimation entries[41]; /* 0x40 */
    u8 pad7F0[0x7B0];
    CampGridEntry grid[108];       /* 0xFA0 */
    RadarSprite sprites[25];       /* 0x1810 */
    u8 *spritePack;                /* 0x1874 */
    union { s32 primaryLabels[7]; SflPersonaState primaryLabelState; };
    union { s32 secondaryLabels[7]; SflPersonaState secondaryLabelState; };
} CampMenu;

/* Mode tables contain 41 records; scales are converted from float to u16. */
typedef struct CampSlotLayout {
    f32 x, y;
    f32 scaleX, scaleY;
    u8 alpha;
    u8 pad11[3];
    s32 startFrame;
    s32 endFrame;
} CampSlotLayout;

#endif

#ifndef DAT_PANEL_INTERNAL_H
#define DAT_PANEL_INTERNAL_H

#include "type.h"
#include "fcl_draw_types.h"

/* Reset and draw readers establish the halfword cursor/style and kind word.
 * The first halfword selects the unit; +4 selects the comparison item. */
typedef struct DatPanelEntry {
    s16 unit;
    u8 pad02[2];
    s16 item;
    s16 style;
    s32 kind;
} DatPanelEntry;

void datPanelDrawByKind(FclVec2 origin, f32 depth, s32 opacity, u8 *entry, s32 fullName);

#endif

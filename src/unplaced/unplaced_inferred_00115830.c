
#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"

/* Panel record: an eight-byte header followed by two 0x3C-byte blocks. */
typedef struct DatPanel {
    s16 kind;
    s16 unk2;
    s32 unk4;
    u8 primary[0x3C];
    u8 secondary[0x3C];
} DatPanel;
extern void memset(u8 *, s32 , s32 );
#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Reset a panel: zero both 0x3C-byte sub-blocks and set the header to 1, 0, 0.
// FUN_00115830
void datPanelReset(u8 *panelBytes) {
    DatPanel *panel = (DatPanel *)panelBytes;
    memset(panel->primary, 0, 0x3C);
    memset(panel->secondary, 0, 0x3C);
    panel->kind = 1;
    panel->unk2 = 0;
    panel->unk4 = 0;
}
#pragma pop

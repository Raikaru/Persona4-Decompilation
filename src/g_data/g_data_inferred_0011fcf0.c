/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/g_data/g_data.c); members 0011fcf0-0011fdf0 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
#include "dat_panel_internal.h"
#include "kwln_task_internal.h"
typedef struct {
    f32 x;
    f32 y;
} Vec2f;

void datPanelDrawCompareIcon(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3);
void drawUnitStatusPanel(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3, s32 arg4_2);
typedef struct KwlnTask KwlnTask;

extern s32 kwlnTaskDestroyWithHierarchy(KwlnTask *task);
extern void sdkSpriteDrawOnceAux(s32 parent, s32 arg0, s32 arg1, f32 x, f32 y,
                          u8 arg2, u8 arg3, f32 z, s32 arg4);
extern s32 resourceFindByName(void *param);
extern u16 datEntryGetPrimaryValue(s16 arg0);
extern u16 datEntryGetMiddleBandValue(s16 arg0);
extern u16 datEntryGetLastBandValue(s16 arg0);
extern s32 datEntryHasFlag(s16 arg0, s16 arg1);
extern s32 datIdBand(s16 arg0);
extern s16 datGetEquippedItemByUnit(s16 arg0, s16 arg1);
/* lint: allow H011 -- kept local: owner-header prototype is not a drop-in for this TU yet; retype its callers first */
extern u8 *datPersonaDisplayName(s16 arg0);
extern u8 D_005E4F70[];
static inline s64 p4_0011_signext16(s16 arg0)
{
    return (s64)arg0;
}

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Return whether the stage field at +8 of the work block is 8; the meaning of stage 8 is not established [inferred]
// FUN_0011FCF0
s32 datBlockStageIsEight(u8 *task) {
    return ((DatPanelEntry*)((KwlnTask*)task)->work)->kind == 8;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Destroy a task and its hierarchy through the kwln task destroy call; same body as shdPersonaDestroyTask [inferred]
// FUN_0011FD10
void kwlnTaskDestroyHierarchyAlt(s32 task) {
    kwlnTaskDestroyWithHierarchy((KwlnTask *)task);
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Reset a panel's cursor: index at +4 to -1 and the count at +6 to 0 [inferred]
// FUN_0011FD30
void datPanelResetCursor(u8 *entry) {
    ((DatPanelEntry*)entry)->item = -1;
    ((DatPanelEntry*)entry)->style = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw a panel row by its kind: kind 0 draws the comparison icon, kinds 1 and 2 the status panel, kind 3 the status panel in variant 1 [inferred]
// FUN_0011FD50
void datPanelDrawByKind(Vec2f origin, f32 depth, s32 opacity, u8 *entry, s32 fullName)
{
    s32 kind;

    kind = ((DatPanelEntry*)entry)->kind;
    switch (kind) {
    case 0:
        datPanelDrawCompareIcon(origin, depth, opacity, entry, kind);
        return;
    case 1:
        drawUnitStatusPanel(origin, depth, opacity, entry, 0, fullName);
        return;
    case 2:
        drawUnitStatusPanel(origin, depth, opacity, entry, 0, fullName);
        return;
    case 3:
        drawUnitStatusPanel(origin, depth, opacity, entry, 1, fullName);
        return;
    }
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw a comparison icon for an entry: sprite 4 when equal to the reference value of its band (always for band 3), 1 when higher, 2 when lower, 3 when no reference applies [inferred]
// FUN_0011FDF0
void datPanelDrawCompareIcon(Vec2f origin, f32 depth, s32 opacity, u8 *entry, s32 unusedKind)
{
    s16 itemId;
    s32 resourceOrColor;
    s32 firstComparison;
    s32 secondComparison;
    s32 thirdComparison;
    s32 firstValue;
    s32 secondValue;
    s32 thirdValue;
    s32 alpha;
    s32 mode;

    resourceOrColor = resourceFindByName(D_005E4F70);
    itemId = ((DatPanelEntry*)entry)->item;
    if (resourceOrColor == 0) {
        resourceOrColor = opacity & 0xFF;
        frFontExDrawText((f32)(s32)origin.x, (f32)(s32)origin.y, depth,
                      resourceOrColor | -0x100, 0, 4,
                      (const char *)datPersonaDisplayName(((DatPanelEntry*)entry)->unit), 0, 0);
        return;
    }
    if (p4_0011_signext16(itemId) == -1) {
        alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, resourceOrColor, 3, origin.x, origin.y, 0, alpha, depth, 1);
        return;
    }
    if (datEntryHasFlag(itemId, ((DatPanelEntry*)entry)->unit) == 0) {
        alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, resourceOrColor, 3, origin.x, origin.y, 0, alpha, depth, 1);
        return;
    }
    mode = datIdBand(itemId);
    switch (mode) {
    case 0:
        firstValue = datEntryGetPrimaryValue(itemId) & 0xFFFF;
        if (firstValue == (datEntryGetPrimaryValue(datGetEquippedItemByUnit(((DatPanelEntry*)entry)->unit, 0)) & 0xFFFF)) {
            alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, resourceOrColor, 4, origin.x, origin.y, 0, alpha, depth, 1);
            return;
        }
        firstComparison = datEntryGetPrimaryValue(itemId) & 0xFFFF;
        if (firstComparison >= (datEntryGetPrimaryValue(datGetEquippedItemByUnit(((DatPanelEntry*)entry)->unit, 0)) & 0xFFFF)) {
            alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, resourceOrColor, 1, origin.x, origin.y, 0, alpha, depth, 1);
            return;
        }
        alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, resourceOrColor, 2, origin.x, origin.y, 0, alpha, depth, 1);
        return;
    case 1:
        secondValue = datEntryGetMiddleBandValue(itemId) & 0xFFFF;
        if (secondValue >= (datEntryGetMiddleBandValue(datGetEquippedItemByUnit(((DatPanelEntry*)entry)->unit, 1)) & 0xFFFF)) {
            alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, resourceOrColor, 4, origin.x, origin.y, 0, alpha, depth, 1);
            return;
        }
        secondComparison = datEntryGetMiddleBandValue(itemId) & 0xFFFF;
        if (secondComparison >= (datEntryGetMiddleBandValue(datGetEquippedItemByUnit(((DatPanelEntry*)entry)->unit, 1)) & 0xFFFF)) {
            alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, resourceOrColor, 1, origin.x, origin.y, 0, alpha, depth, 1);
            return;
        }
        alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, resourceOrColor, 2, origin.x, origin.y, 0, alpha, depth, 1);
        return;
    case 2:
        thirdValue = datEntryGetLastBandValue(itemId) & 0xFFFF;
        if (thirdValue >= (datEntryGetLastBandValue(datGetEquippedItemByUnit(((DatPanelEntry*)entry)->unit, 2)) & 0xFFFF)) {
            alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, resourceOrColor, 4, origin.x, origin.y, 0, alpha, depth, 1);
            return;
        }
        thirdComparison = datEntryGetLastBandValue(itemId) & 0xFFFF;
        if (thirdComparison >= (datEntryGetLastBandValue(datGetEquippedItemByUnit(((DatPanelEntry*)entry)->unit, 2)) & 0xFFFF)) {
            alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, resourceOrColor, 1, origin.x, origin.y, 0, alpha, depth, 1);
            return;
        }
        alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, resourceOrColor, 2, origin.x, origin.y, 0, alpha, depth, 1);
        return;
    case 3:
        alpha = (0xFF - (opacity & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, resourceOrColor, 4, origin.x, origin.y, 0, alpha, depth, 1);
        return;
    }
}
#pragma pop

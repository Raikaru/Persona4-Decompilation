/* Inferred unit: no __FILE__ evidence; boundaries from callee/caller votes (src/g_data/g_data.c); members 0011fcf0-0011fdf0 */

#include "list_item_internal.h"
#include "include_asm.h"
#include "type.h"
#include "fr_font_internal.h"
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
extern u16 func_001068b0(s16 arg0);
extern u16 func_00106940(s16 arg0);
extern u16 func_00106970(s16 arg0);
extern s32 datEntryHasFlag(s16 arg0, s16 arg1);
extern s32 datIdBand(s16 arg0);
extern s16 func_00106cd0(s16 arg0, s16 arg1);
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
s32 datBlockStageIsEight(u8 *arg0) {
    return *(s32 *)(*(u8 **)(arg0 + 0x38) + 8) == 8;
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
void datPanelResetCursor(u8 *arg0) {
    *(s16 *)(arg0 + 4) = -1;
    *(s16 *)(arg0 + 6) = 0;
}
#pragma pop

#pragma push
#pragma opt_loop_invariants off
#pragma opt_propagation on
#pragma opt_common_subs on
#pragma opt_rebuildconditionals on
// Intent: Draw a panel row by its kind: kind 0 draws the comparison icon, kinds 1 and 2 the status panel, kind 3 the status panel in variant 1 [inferred]
// FUN_0011FD50
void datPanelDrawByKind(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3)
{
    s32 temp_7;

    temp_7 = *(s32 *)(arg2 + 8);
    switch (temp_7) {
    case 0:
        datPanelDrawCompareIcon(arg0, arg4, arg1, arg2, temp_7);
        return;
    case 1:
        drawUnitStatusPanel(arg0, arg4, arg1, arg2, 0, arg3);
        return;
    case 2:
        drawUnitStatusPanel(arg0, arg4, arg1, arg2, 0, arg3);
        return;
    case 3:
        drawUnitStatusPanel(arg0, arg4, arg1, arg2, 1, arg3);
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
void datPanelDrawCompareIcon(Vec2f arg0, f32 arg4, s32 arg1, u8 *arg2, s32 arg3)
{
    s16 temp_17;
    s32 temp_2;
    s32 temp_17_2;
    s32 temp_17_3;
    s32 temp_17_4;
    s32 temp_20;
    s32 temp_20_2;
    s32 temp_20_3;
    s32 alpha;
    s32 mode;

    temp_2 = resourceFindByName(D_005E4F70);
    temp_17 = *(s16 *)(arg2 + 4);
    if (temp_2 == 0) {
        temp_2 = arg1 & 0xFF;
        frFontExDrawText((f32)(s32)arg0.x, (f32)(s32)arg0.y, arg4,
                      temp_2 | -0x100, 0, 4,
                      (const char *)datPersonaDisplayName(*(s16 *)arg2), 0, 0);
        return;
    }
    if (p4_0011_signext16(temp_17) == -1) {
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 3, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
    if (datEntryHasFlag(temp_17, *(s16 *)arg2) == 0) {
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 3, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
    mode = datIdBand(temp_17);
    switch (mode) {
    case 0:
        temp_20 = func_001068b0(temp_17) & 0xFFFF;
        if (temp_20 == (func_001068b0(func_00106cd0(*(s16 *)arg2, 0)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_2 = func_001068b0(temp_17) & 0xFFFF;
        if (temp_17_2 >= (func_001068b0(func_00106cd0(*(s16 *)arg2, 0)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 1:
        temp_20_2 = func_00106940(temp_17) & 0xFFFF;
        if (temp_20_2 >= (func_00106940(func_00106cd0(*(s16 *)arg2, 1)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_3 = func_00106940(temp_17) & 0xFFFF;
        if (temp_17_3 >= (func_00106940(func_00106cd0(*(s16 *)arg2, 1)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 2:
        temp_20_3 = func_00106970(temp_17) & 0xFFFF;
        if (temp_20_3 >= (func_00106970(func_00106cd0(*(s16 *)arg2, 2)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        temp_17_4 = func_00106970(temp_17) & 0xFFFF;
        if (temp_17_4 >= (func_00106970(func_00106cd0(*(s16 *)arg2, 2)) & 0xFFFF)) {
            alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
            sdkSpriteDrawOnceAux(0, temp_2, 1, arg0.x, arg0.y, 0, alpha, arg4, 1);
            return;
        }
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 2, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    case 3:
        alpha = (0xFF - (arg1 & 0xFF)) & 0xFF;
        sdkSpriteDrawOnceAux(0, temp_2, 4, arg0.x, arg0.y, 0, alpha, arg4, 1);
        return;
    }
}
#pragma pop

#include "btl_skill_target_internal.h"
#include "list_item_internal.h"
#include "btl_motion_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "btl_packet_create_internal.h"
typedef struct BtlPacket BtlPacket;
#include "btl_skill_internal.h"
#include "sdk_snd_internal.h"
#include "shd_misc_internal.h"
#include "btl_panel_internal.h"
#include "fr_font_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
typedef struct BtlUnit BtlUnit;
typedef struct BtlAction BtlAction;

extern s32 cmmCommunityForArcana(s16 arg0);
extern u16 func_00107ac0(s32 arg0);
extern void btlSelectionResetSubList(u8 *arg0, u8 *arg1);
extern u16 btlSelectionConfirmSubList(u8 *arg0, u8 *arg1);
extern void btlSelectionDrawCurrentLabel(u8 *selection, s32 workAddress, u8 *drawState);
extern void func_00209f90(void);
extern void func_0020a5c0(void);
extern void btlSelectionUpdateWindow();

extern u32 datGetFlag(s32 arg0);
extern u32 datCalcChkBadStatus(s32 arg0, u32 arg1);

extern void memset(void *destination, s32 value, u32 size);
extern void btlSelectionSetRepeat(u8 *arg0, s16 *arg1);
extern u32 datGetItemNameId(s16 arg0);
extern s32 func_001eb860(void);

typedef struct {
    u8 pad0[2];
    s16 field2;
    s16 field4;
    s16 field6;
    s16 field8;
} P4_00202D20;
static inline f32 func_0020_mul(f32 left, f32 right)
{
    return left * right;
}
static inline u8 *p4_002091f0_add(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u32 kwlnTaskGetWork();
extern f32 fGpffff815c;
extern f32 fGpffff83b0;
extern u8 *datPersonaRosterSlot(s16 arg0);
extern s32 datPersonaGetLeadSlot(void);
extern s32 datPersonaGetLevel(u8 *arg0);
extern u8 *datPersonaGetRow(u16 arg0);
extern u16 frFontSetFlagBits(s16 arg0);
extern u16 frFontClearFlagBits(u16 arg0);

extern u32 func_001d8bc0(void *arg0);
extern void func_0011b360(u8 *arg0);
extern s32 func_0011ba00(u8 *arg0);
extern void func_0011b480(u8 *arg0, s32 arg1, u32 arg2, s8 arg3);
extern void func_0011bb90(u8 *arg0);
extern void func_0011bc70(u8 *arg0);
extern void func_0011c180(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
extern void func_0011c2c0(u8 *arg0, s32 arg1, s32 arg2, s8 arg3);
extern u32 func_0011c610(u8 *arg0);
extern void func_0011c630(u8 *arg0);
extern void func_0011c6e0(u8 *arg0, s32 arg1);
extern void func_0011caf0(u8 *arg0);
extern void btlUiDrawSpriteEntry(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void btlPanelSetCountdown(s32 arg0, s32 arg1);
extern void btlPanelStartEntry(s32 arg0, s32 arg1);





extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*jtbl_008873E8[])(u32 size, u32 align);
extern u8 D_00626C30[];
extern u8 D_00626500[];
extern u8 D_006265B0[];
extern void memset(void *dst, s32 value, u32 size);

extern void memcpy(void *dst, const void *src, u32 size);
extern u8 D_00625240[];
extern f32 fGpffff8184;
extern f32 fGpffff84a4;
extern f32 fGpffff81a8;
extern f32 cosf(f32 fparg0);
extern f32 sinf(f32 fparg0);
typedef void (*BattleSelectionDraw)(u8 *work, s32 slot, f32 x, f32 y,
                                    u8 opacity, s32 highlighted, s32 showDetail);
extern void btlSelectionDrawSlideIn(u8 *work, u8 *state, f32 x, f32 y,
                         BattleSelectionDraw drawSelection);

extern void btlPanelDrawSkillEntry(u8 *arg0, s32 arg1, f32 fx, f32 fy, u8 arg2, s32 arg3, s32 arg4);
extern void btlSelectionDrawList(u8 *arg0, u8 *arg1, f32 farg0, f32 farg1,
                          BattleSelectionDraw callback);
extern void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 show_detail);
extern void btlPanelDrawCircle(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color);
extern void func_0045d6e0(u8 *arg0, f32 *arg1, f32 fparg0, s32 arg2);
typedef struct {
    u8 c0;
    u8 c1;
    u8 c2;
    u8 c3;
} Color4;
typedef struct {
    s32 value3;
    s32 value0;
    s32 value1;
    s32 value2;
    u8 pad[0xC];
    Color4 colors;
} Work4;
extern void RpSkyRenderStateSet(s32 arg0, s32 arg1);
extern void (*D_00887300[])(u32 arg0, u32 arg1);
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern s32 func_00457120(void);
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void btlUiSetRenderMode(s32 arg0);
extern void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern u16 datCalcUnderlyingSkillId(s64 arg0);
extern void btlSelectionRefreshList(u16 *flags, u8 *work);
extern s32 btlSelectionHandleInput(u8 *selection, s32 workAddress, u8 **nextPanel);
extern void btlSelectionDrawCommands(u8 *selection, s32 workAddress, u8 *drawState);
extern void btlPanelDrawStrip(s32 index, f32 x, f32 y, f32 depth, f32 angle, s32 extend);
extern void btlSelectionSaveCursor();
extern void btlSelectionDrawBar(u8 *unused, u8 *arg1, f32 *arg2);
extern u8 *func_001b0c80(s32 arg0);
extern u8 *iGpffffb3ac;

extern s32 D_00881444_abs[];
extern void btlPanelUpdate(void *arg0);
extern s32 datCalcIsLowHp(u8 *arg0);
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern void btlSelectionUpdateTransition(u8 *arg0);
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern void btlPanelInitWork(u8 *arg0, s32 arg1);
extern void btlPanelDrawFrame(s32 arg0, u8 *arg1);
extern void btlSelectionUpdateTransition(u8 *arg0);
extern void btlPanelDrawBackdropGrid(s32 arg0, u8 *arg1);
extern void func_0020b5a0(void);
extern void btlPanelDrawSkyFrame(s32 arg0, u8 *arg1);
extern void btlSelectionInitTransition(u8 *arg0, s32 arg1);
extern void btlSelectionDrawTargetFrame(u8 *arg0, u8 *arg1);
extern u8 D_006253B0[];

/* Source unit: src/promoted/code1_0020.c */
/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in src/promoted/code1_0020.c; members 00202c60-0020bfd0 */

extern void btlUiSetOrigin(u8 *arg0, f32 fparg0, f32 fparg1);
extern void btlUiSetRenderStates(void);
extern void btlUiDrawSpriteEntry(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0, f32 fparg1);
extern void btlUiSetScale(u8 *arg0, f32 fparg0, f32 fparg1);
extern void btlUiSetRenderMode(s32 arg0);
extern void btlUiSetAlpha(u8 *arg0, f32 fparg0);
extern void btlUiSelectEffect(s32 arg0, u32 arg1);
extern void btlSelectionDispatchTargetMode(s32 arg0, u8 *arg1, u8 *arg2);
extern void btlSelectionSwapRowState(u8 *arg0, u8 *arg1);
typedef struct BattleSelectionInput {
    u16 flags;
    s16 first;
    s16 selected;
    s16 pageSize;
    s16 count;
    u8 padding[0x22];
    u16 previous;
    u16 next;
    u16 previousPage;
    u16 nextPage;
} BattleSelectionInput;
typedef struct {
    s32 (*draw)(s32 primitive, void *vertices, s32 count);
} BattlePanelPrimitiveDispatch;
extern f32 fGpffff836c;
extern void func_00364c50(void);
extern void func_00364c70(void);
typedef struct { u8 b0, b1, b2, b3; } BattleSkillIconColor;
extern void ShdSkill_DrawIcon(Vec2f position, f32 scale,
                          BattleSkillIconColor color, u16 skill, s32 texture);
extern u32 datCalcSkillCost(u8 *unit, s32 skill);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skill);
extern u16 datCalcThresholdKind(u8 *unit, s32 skill);
extern s16 func_00105f00(s16 arg0);
extern u32 func_0010d6d0(s16 arg0);
extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 mode,
                         s32 style, s32 flags, s32 handle, s32 index);
typedef struct BattleRenderDispatch {
    void (*setState)(u32 state, u32 value);
} BattleRenderDispatch;
extern s32 func_00106600(s16 id);
extern u16 *datPersonaGetRecord(u16 id);
extern u16 datPersonaGetSkillAt(u8 *persona, s16 slot);
extern s32 datCalcIsFlaggedPersonaSkill(s32 id);
extern u8 *iGpffffb3b8;
typedef struct {
    s16 id;
    u8 quantity;
    u8 reserved;
} BattleListItem;
typedef struct {
    u8 prefix[0x194];
    u16 skills[8];
    u16 skillCount;
    BattleListItem items[256];
    u16 itemCount;
} BattleListWork;
static inline void battleMenuExtendedStrip(BattleRenderDispatch *renderer,
                                          f32 x, f32 y, f32 progress)
{
    void (**setState)(u32, u32);
    setState = &renderer->setState;
    (*setState)(6, 1);
    btlPanelDrawStrip(3, x, y, 110.0f, progress * 90.0f, 1);
    (*setState)(6, 0);
}
struct FrFontNode;
extern u16 func_0010f8c0(s32 arg0);
extern s32 func_0019f0f0(u8 *arg0);
extern void func_001d8010(u8 *arg0, u8 *arg1);
extern void btlPanelReleaseText(s32 task);
extern void func_00216d40(s32 task);
extern void btlPanelSetTarget(u8 *task, s32 arg1);
extern void btlSelectionSetRowIdle(u8 *arg0);
extern u16 D_008C024E[];
/* measured: caching D_00887300 in s0 reproduces retail's one-time
   lui/addiu vtable materialization across these callback calls. */
/* measured: close the vtable propagation probe and restore default state. */
/* Keep the opacity base ahead of byte promotion, matching retail order. */
#pragma push
#pragma pop
/* Measured: 676/688 bytes, seven resolved relocations and twelve zero alignment bytes.
 * Snapshot inputs before providers; reload the skill fields and final output
 * metadata at their retail callback boundaries. */
#pragma push
#pragma pop
/* measured: opt_rebuildconditionals off tested for callback completion. */
/* measured: restore conditional rebuilding after callback completion. */
// Intent: initialise a selection block with its callbacks and owner. [inferred]
// FUN_00202C60
void btlSelectionInit(u8 *arg0, s16 arg1, s16 arg2, void *arg3, void *arg4, void *arg5, void *arg6, u8 *arg7) {
    memset(arg0, 0, 0x34);
    *(s16 *)(arg0 + 6) = arg1;
    *(s16 *)(arg0 + 8) = arg2;
    *(void **)(arg0 + 0xC) = arg3;
    *(void **)(arg0 + 0x10) = arg4;
    *(void **)(arg0 + 0x14) = arg5;
    *(void **)(arg0 + 0x1C) = arg6;
    *(u8 **)(arg0 + 0x28) = arg7;
    *(u16 *)(arg0 + 0) |= 8;
    btlSelectionSetRepeat(arg0, NULL);
}

// Intent: recompute the visible selection window (first row and page) from the selected index. [inferred]
// FUN_00202D20
void btlSelectionUpdateWindow(u8 *arg0, s64 arg1, s64 arg2)
{
    s32 temp_3;
    s16 temp_7;
    s16 temp_8_2;
    s32 temp_8;
    s32 temp_9;
    s64 var_6;

    var_6 = arg2;
    temp_8 = (s16)var_6;
    if ((temp_8 > 0) && (*(s16 *)(arg0 + 8) < (temp_8 + *(s16 *)(arg0 + 6)))) {
        var_6 = 0;
    }
    temp_9 = (s16)arg1;
    if (*(s16 *)(arg0 + 8) <= temp_9) {
        *(s16 *)(arg0 + 2) = 0;
        *(s16 *)(arg0 + 4) = 0;
        return;
    }
    temp_8_2 = *(s16 *)(arg0 + 8);
    temp_7 = *(s16 *)(arg0 + 6);
    if (temp_9 < ((s16)var_6 + temp_7)) {
        *(s16 *)(arg0 + 2) = (u16)var_6;
        *(s16 *)(arg0 + 4) = (u16)arg1;
        return;
    }
    if (temp_9 < (temp_7 - 1)) {
        *(s16 *)(arg0 + 2) = 0;
        *(s16 *)(arg0 + 4) = (u16)arg1;
        return;
    }
    temp_3 = temp_8_2 - temp_7;
    if (temp_3 < temp_9) {
        *(s16 *)(arg0 + 2) = temp_3;
        *(s16 *)(arg0 + 4) = (u16)arg1;
        return;
    }
    *(s16 *)(arg0 + 2) = (s16)(temp_9 - 1);
    *(s16 *)(arg0 + 4) = (u16)arg1;
}

// Intent: set the key-repeat masks from a table or the default repeat values. [inferred]
// FUN_00202E00
void btlSelectionSetRepeat(u8 *arg0, s16 *arg1)
{
    if (arg1 != NULL) {
        memcpy(arg0 + 0x2C, arg1, 8);
        return;
    }
    *(s16 *)(arg0 + 0x2C) = 0x1000;
    *(s16 *)(arg0 + 0x2E) = 0x4000;
    *(u16 *)(arg0 + 0x30) = 0x8000;
    *(s16 *)(arg0 + 0x32) = 0x2000;
}

// Intent: store the owner pointer of a selection block. [inferred]
// FUN_00202E60
void btlSelectionSetOwner(u8 *arg0, void *arg1)
{
    *(s32 *)(arg0 + 0x18) = (s32)arg1;
}

#pragma push
/* measured: btlSelectionReadInput MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: read the selection input and return the action code (1 to 4) or 0. [inferred]
// FUN_00202E70
s32 btlSelectionReadInput(u8 *arg0)
{
    extern u16 D_008C024E[];
    extern u16 D_008C0276[];
    extern u16 D_008C027A[];
    BattleSelectionInput *selection;
    s32 count;
    u32 repeat;
    u32 flags;

    selection = (BattleSelectionInput *)arg0;
    count = selection->count;
    if (selection->selected >= count) {
        s32 first;
        selection->selected = count - 1;
        first = selection->count - selection->pageSize;
        selection->first = (u16)first;
        if ((s16)first < 0) {
            selection->first = 0;
        }
    }
    if (D_008C024E[0] & 0x40) {
        return 2;
    }
    if (D_008C024E[0] & 0x20) {
        return 1;
    }
    if (D_008C024E[0] & 0x80) {
        return 3;
    }
    flags = selection->flags;
    if ((flags & 4) != 0 && (D_008C024E[0] & 4) != 0) {
        return 4;
    }
    repeat = D_008C027A[0];
    if ((repeat & selection->previous) != 0 ||
        ((flags & 1) != 0 && (repeat & selection->previousPage) != 0)) {
        s32 moved;
        s32 page;
        s32 single;
        s16 amount;
        s32 steps;
        s16 i;

        moved = 1;
        page = (repeat & selection->previousPage) != 0;
        single = !page;
        if (single != 0) {
            amount = 1;
        } else {
            amount = selection->pageSize;
        }
        steps = amount;
        for (i = 0; i < steps; ++i) {
            s32 first;
            s32 selected;
            first = selection->first;
            selected = selection->selected;
            if (selected <= first + 1) {
                if (first > 0) {
                    selection->first = first - 1;
                    selection->selected = selection->selected - 1;
                } else if (selected == 1) {
                    selection->selected = 0;
                } else {
                    if ((selection->flags & 2) == 0 ||
                        (D_008C0276[0] & selection->previous) != 0 ||
                        (page != 0 && (D_008C0276[0] & selection->previousPage) != 0)) {
                        s32 lastPage;
                        lastPage = selection->count - selection->pageSize;
                        selection->first = (u16)lastPage;
                        if ((s16)lastPage < 0) {
                            selection->first = 0;
                        }
                        selection->selected = selection->count - 1;
                    } else {
                        moved = 0;
                        selection->first = 0;
                        selection->selected = 0;
                    }
                    break;
                }
            } else {
                selection->selected = selected - 1;
            }
        }
        if (moved != 0 && (selection->flags & 8) != 0) {
            if (page == 0) {
                func_0045af60(0, 0, 0, 0);
            } else {
                func_0045af60(0, 0, 0, 5);
            }
        }
        return (u16)(single != 0 ? 5 : 7);
    } else if ((repeat & selection->next) != 0 ||
               ((flags & 1) != 0 && (repeat & selection->nextPage) != 0)) {
        s32 moved;
        s32 page;
        s32 single;
        s16 amount;
        s32 steps;
        s16 i;

        moved = 1;
        page = (repeat & selection->nextPage) != 0;
        single = !page;
        if (single != 0) {
            amount = 1;
        } else {
            amount = selection->pageSize;
        }
        steps = amount;
        for (i = 0; i < steps; ++i) {
            s32 pageSize;
            s32 first;
            s32 selected;
            pageSize = selection->pageSize;
            first = selection->first;
            selected = selection->selected;
            if (selected >= first + pageSize - 2 ||
                selected >= selection->count - 2) {
                s32 count;
                s32 lastPage;
                count = selection->count;
                lastPage = count - pageSize;
                if (first < lastPage) {
                    ++selection->first;
                    ++selection->selected;
                } else if (selected < count - 1) {
                    ++selection->selected;
                } else {
                    if ((selection->flags & 2) == 0 ||
                        (D_008C0276[0] & selection->next) != 0 ||
                        (page != 0 && (D_008C0276[0] & selection->nextPage) != 0)) {
                        selection->first = 0;
                        selection->selected = 0;
                    } else {
                        moved = 0;
                        if (count < pageSize) {
                            lastPage = 0;
                        }
                        selection->first = (u16)lastPage;
                        selection->selected = selection->count - 1;
                    }
                    break;
                }
            } else {
                selection->selected = selected + 1;
            }
        }
        if (moved != 0 && (selection->flags & 8) != 0) {
            if (page == 0) {
                func_0045af60(0, 0, 0, 0);
            } else {
                func_0045af60(0, 0, 0, 5);
            }
        }
        return (u16)(single != 0 ? 6 : 8);
    }
    return 0;
}

#pragma pop
// Intent: start a callback list at the given node and run each node's init callback. [inferred]
// FUN_00203360
void btlListStart(u8 *arg0, u8 *arg1) {
    u8 *temp_16;
    u8 *var_4;

    *(s32 *)(arg0 + 0) = 0;
    *(s32 *)(arg0 + 4) = 0;
    *(s32 *)(arg0 + 0x10) = 0;
    *(u8 **)(arg0 + 0xC) = arg1;
    *(u8 **)(arg0 + 8) = arg1;
    var_4 = arg1;
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0xC))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
}

// Intent: flush a callback list by running each node's exit callback and clearing the head. [inferred]
// FUN_002033C0
void btlListFlush(u8 *arg0) {
    u8 *temp_16;
    u8 *var_4;

    var_4 = *(u8 **)(arg0 + 8);
    while (var_4 != NULL) {
        temp_16 = *(u8 **)(var_4 + 0x24);
        (*(void (**)(u8 *, s32))(var_4 + 0x1C))(var_4, *(s32 *)(var_4 + 0x28));
        var_4 = temp_16;
    }
    *(u8 **)(arg0 + 8) = NULL;
}

// Intent: advance the callback list according to the node's result code (stay, push, pop). [inferred]
// FUN_00203420
s32 btlListStep(u8 *arg0)
{
    u8 *sp4C;
    u8 *temp_17;
    s32 temp_16;
    u8 *temp_4;

    temp_17 = *(u8 **)(arg0 + 0xC);
    sp4C = *(u8 **)(temp_17 + 0x24);
    temp_16 = (*(s32 (**)(u8 *, s32, u8 **))(temp_17 + 0x10))(
        temp_17, *(s32 *)(temp_17 + 0x28), &sp4C) & 0xFFFF;
    switch (temp_16) {
    case 1:
        break;
    case 2:
        if (*(u8 **)(temp_17 + 0x20) != NULL) {
            if (*(void (**)(u8 *, s32))(temp_17 + 0x1C) != NULL) {
                (*(void (**)(u8 *, s32))(temp_17 + 0x1C))(
                    temp_17, *(s32 *)(temp_17 + 0x28));
            }
            *(u8 **)(arg0 + 0x10) = *(u8 **)(arg0 + 0xC);
            *(u8 **)(arg0 + 0xC) = *(u8 **)(temp_17 + 0x20);
            *(s32 *)(*(u8 **)(temp_17 + 0x20) + 0x24) = 0;
            temp_4 = *(u8 **)(temp_17 + 0x20);
            if (*(void (**)(u8 *, s32))(temp_4 + 0xC) != NULL) {
                (*(void (**)(u8 *, s32))(temp_4 + 0xC))(
                    temp_4, *(s32 *)(temp_4 + 0x28));
            }
        }
        break;
    case 3:
        if (sp4C != NULL) {
            if (*(void (**)(u8 *, s32))(temp_17 + 0x1C) != NULL) {
                (*(void (**)(u8 *, s32))(temp_17 + 0x1C))(
                    temp_17, *(s32 *)(temp_17 + 0x28));
            }
            *(u8 **)(arg0 + 0x10) = *(u8 **)(arg0 + 0xC);
            *(u8 **)(arg0 + 0xC) = sp4C;
            *(u8 **)(sp4C + 0x20) = temp_17;
            *(u8 **)(temp_17 + 0x24) = sp4C;
            *(s32 *)(sp4C + 0x24) = 0;
            if (*(void (**)(u8 *, s32))(sp4C + 0xC) != NULL) {
                (*(void (**)(u8 *, s32))(sp4C + 0xC))(
                    sp4C, *(s32 *)(sp4C + 0x28));
            }
        }
        break;
    case 4:
    case 5:
        break;
    }
    return temp_16;
}

// Intent: run each list node's update callback with the list owner. [inferred]
// FUN_002035A0
void btlListDispatchUpdate(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        (*(void (**)(u8 *, s32, u8 *))(var_16 + 0x14))(var_16, *(s32 *)(var_16 + 0x28), arg0);
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}

// Intent: run each list node's optional callback with the list owner. [inferred]
// FUN_00203600
void btlListDispatchNotify(u8 *arg0) {
    u8 *var_16;

    var_16 = *(u8 **)(arg0 + 8);
    while (var_16 != NULL) {
        void (*fn)(u8 *, s32, u8 *) = *(void (**)(u8 *, s32, u8 *))(var_16 + 0x18);
        if (fn != NULL) {
            fn(var_16, *(s32 *)(var_16 + 0x28), arg0);
        }
        var_16 = *(u8 **)(var_16 + 0x24);
    }
}

/* measured: callback materialisation residual remains. Committed at nd 73. */
// Intent: initialise the battle panel task state and its selection block. [inferred]
// FUN_00203670
void btlPanelInit(s32 unused, s32 arg1)
{
    struct {
        s16 values[2];
        s32 pad;
    } sp38;
    s32 temp_4;
    s32 mask;
    u8 *temp_2;
    u8 *temp_16;
    u8 *temp_18;
    temp_2 = (u8 *)kwlnTaskGetWork();
    temp_16 = temp_2 + 0x9C;
    *(s32 *)(temp_2 + 0x214) = arg1;
    *(s16 *)(temp_2 + 0x9C) = 1;
    *(s16 *)(temp_2 + 0xA4) = 0;
    mask = -3;
    *(s16 *)(temp_2 + 0xA6) = mask;
    *(s16 *)(temp_2 + 0xA8) = 0;
    *(s16 *)(temp_2 + 0xAA) = -9;
    *(s16 *)(temp_2 + 0xAE) = 0;
    *(s16 *)(temp_2 + 0xB0) = 0;
    *(s16 *)(temp_2 + 0xBC) = 0;
    *(s16 *)(temp_2 + 0xBE) = 0;
    *(s16 *)(temp_2 + 0xB2) = 0;
    *(s16 *)(temp_2 + 0xB4) = 0;
    temp_4 = *(s32 *)(temp_2 + 0xA0);
    temp_4 &= mask;
    *(s32 *)(temp_2 + 0xA0) = temp_4;
    temp_4 = temp_4 & 0xFFFFFFFEU;
    *(s32 *)(temp_2 + 0xA0) = temp_4;
    btlSelectionInit(temp_16 + 0x40, 8, 8,
                  (void *)btlSelectionRefreshList, (void *)btlSelectionHandleInput,
                  (void *)btlSelectionDrawCommands, (void *)btlSelectionSaveCursor, temp_16);
    temp_18 = temp_16 + 0x40;
    btlSelectionSetOwner(temp_18, (void *)btlSelectionDrawBar);
    memset((s16 *)&sp38, 0, 8);
    sp38.values[0] = 0x1000;
    sp38.values[1] = 0x4000;
    btlSelectionSetRepeat(temp_16 + 0x40, (s16 *)&sp38);
    btlSelectionUpdateWindow(temp_16 + 0x40, 3, 0);
    btlListStart(temp_16 + 0x2C, temp_16 + 0x40);
    *(s32 *)(temp_16 + 0x2C) = 0;
    *(s32 *)(temp_16 + 0x30) = 0;
}

/* This and the selection helpers take the caller's task explicitly. Retail
 * forwards that argument to the work getter; an empty C parameter list loses
 * the contract even when the argument register happens to retain the value. */
// Intent: set the panel task state to active. [inferred]
// FUN_002037B0
void btlPanelSetActive(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    *(s16 *)(p + 0x9C) = 1;
}

// Intent: return the panel task state. [inferred]
// FUN_002037E0
u16 btlPanelGetState(void) {
    return *(u16 *)((u8 *)kwlnTaskGetWork() + 0x9C);
}

/* measured: opt_propagation off probe for 00203810 evaluation order. */
/* measured: func_00203810 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00203810
s32 func_00203810(void)
{
    u8 *p;
    u8 *base;
    s32 field;

    p = (u8 *)kwlnTaskGetWork();
    base = p + 0x9C;
    field = *(s32 *)(p + 0xD4);
    base += 0x40;
    return (s32)(field == (s32)base);
}

/* measured: close opt_propagation after func_00203810 probe. */
/* measured: btlPanelDrawCircle, btlPanelDrawOutlineFill MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: report whether the panel task is ready (state below 2). [inferred]
// FUN_00203850
s32 btlPanelIsReady(void)
{
    return *(s16 *)((u8 *)kwlnTaskGetWork() + 0xAA) < 2;
}

// FUN_00203880
void func_00203880(s32 unusedTask, s32 unusedAction)
{
}

// Intent: set the panel task state to closing. [inferred]
// FUN_00203890
void btlPanelSetClosing(void) {
    u8 *p;

    p = (u8 *)kwlnTaskGetWork();
    *(s16 *)(p + 0x9C) = 4;
}

// Intent: reset the panel task state, list and sub-task pointers. [inferred]
// FUN_002038C0
void btlPanelReset(s32 task) {
    u8 *b = (u8 *)kwlnTaskGetWork((void *)task) + 0x9C;

    *(s32 *)(b + 4) &= ~2;
    btlListFlush(b + 0x2C);
    if (*(s32 *)(b + 0x5A8) != 0) {
        func_0011b360(*(u8 **)(b + 0x5A8));
        *(s32 *)(b + 0x5A8) = 0;
        *(s16 *)(b + 0x5AC) = -1;
    }
    *(s32 *)(b + 0x178) = 0;
    *(s16 *)b = 0;
}

/* The outline and fill use separate initialization cursors and renderer
 * phases. Each fill edge writes a pair of adjacent 64-byte vertices. */
#pragma push
/* measured: btlPanelDrawOutlineFill MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: draw a 19-point curved panel outline and its fill quad with the given scale and colour. [inferred]
// FUN_00203930
void btlPanelDrawOutlineFill(u8 *unused, f32 scaleX, f32 scaleY, u8 r, u8 g, u8 b, s32 a)
{
    extern f32 fGpffff8488;
    extern f32 fGpffff848c;
    extern f32 fGpffff8490;
    extern f32 fGpffff8494;
    extern f32 D_006267F0[][2];
    extern f32 D_00626930[][2];
    extern f32 D_006269E0[][2];
    extern f32 D_00626A90[][2];
    extern f32 D_00626B30[][2];
    extern void func_00364c50(void);
    extern void func_00364c70(void);
    f32 hi[80][16];
    f32 lo[42][16];
    f32 base;
    f32 reciprocal;
    f32 sx2;
    f32 sy2;
    f32 sx3;
    f32 sy3;
    u32 vertex;
    BattlePanelPrimitiveDispatch *draw;

    scaleX *= fGpffff8488;
    scaleY *= fGpffff848c;
    sx2 = fGpffff8490 * scaleX;
    sy2 = fGpffff8490 * scaleY;
    sx3 = fGpffff8494 * scaleX;
    sy3 = fGpffff8494 * scaleY;
    base = D_008872F8[0];
    reciprocal = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    D_00887300[0](1, 0);
    if ((a & 0xFF) == 0xFF) {
        func_00364c50();
        {
            u32 init;
            for (init = 0; init < 80; init++) {
                f32 *out = hi[init];
                out[2] = base;
                out[6] = reciprocal;
                out[8] = (f32)r;
                out[9] = (f32)g;
                out[10] = (f32)b;
                ((s32 *)out)[11] = 0x437F0000;
            }
        }
        vertex = 0;
        {
            s32 i;
            for (i = 0; (u32)i < 20; i++) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * point[0];
                out[1] = (0.0f + 211.0f) - scaleY * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * -point[0];
                out[1] = (0.0f + 211.0f) - scaleY * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 1; (u32)i < 20; i++) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * -point[0];
                out[1] = (0.0f + 211.0f) + scaleY * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * point[0];
                out[1] = (0.0f + 211.0f) + scaleY * point[1];
                vertex++;
            }
        }
        draw = (BattlePanelPrimitiveDispatch *)D_00887310;
        draw->draw(2, hi, vertex);
        vertex = 0;
        {
            s32 i;
            for (i = 0; (u32)i < 20; i++) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx2 * point[0];
                out[1] = (0.0f + 211.0f) - sy2 * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx2 * -point[0];
                out[1] = (0.0f + 211.0f) - sy2 * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 1; (u32)i < 20; i++) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx2 * -point[0];
                out[1] = (0.0f + 211.0f) + sy2 * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_006267F0[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx2 * point[0];
                out[1] = (0.0f + 211.0f) + sy2 * point[1];
                vertex++;
            }
        }
        draw->draw(2, hi, vertex);
        vertex = 0;
        {
            s32 i;
            for (i = 0; (u32)i < 20; i++) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * point[0];
                out[1] = (0.0f + 211.0f) - scaleY * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * -point[0];
                out[1] = (0.0f + 211.0f) - scaleY * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 1; (u32)i < 20; i++) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * -point[0];
                out[1] = (0.0f + 211.0f) + scaleY * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + scaleX * point[0];
                out[1] = (0.0f + 211.0f) + scaleY * point[1];
                vertex++;
            }
        }
        draw->draw(2, hi, vertex);
        vertex = 0;
        {
            s32 i;
            for (i = 0; (u32)i < 20; i++) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx3 * point[0];
                out[1] = (0.0f + 211.0f) - sy3 * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx3 * -point[0];
                out[1] = (0.0f + 211.0f) - sy3 * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 1; (u32)i < 20; i++) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx3 * -point[0];
                out[1] = (0.0f + 211.0f) + sy3 * point[1];
                vertex++;
            }
        }
        {
            s32 i;
            for (i = 18; i >= 0; i--) {
                f32 *point = D_00626890[i];
                f32 *out = hi[vertex];
                out[0] = (0.0f + 320.0f) + sx3 * point[0];
                out[1] = (0.0f + 211.0f) + sy3 * point[1];
                vertex++;
            }
        }
        draw->draw(2, hi, vertex);
        func_00364c70();
    }
    {
        u32 init;
        for (init = 0; init < 42; init++) {
            f32 *out = lo[init];
            out[2] = base;
            out[6] = reciprocal;
            out[8] = (f32)r;
            out[9] = (f32)g;
            out[10] = (f32)b;
            out[11] = (f32)(u32)a;
        }
    }
    {
        u32 idx;
        u32 cursor;
        cursor = 0;
        idx = 0;
        while (idx < 21) {
            f32 *point = D_00626930[idx];
            f32 *point2;
            f32 (*out)[16] = &lo[cursor];
            out[0][0] = (0.0f + 320.0f) + sx2 * point[0];
            out[0][1] = (0.0f + 211.0f) - sy2 * point[1];
            point2 = D_006269E0[idx];
            out[1][0] = (0.0f + 320.0f) + sx3 * point2[0];
            out[1][1] = (0.0f + 211.0f) - sy3 * point2[1];
            cursor += 2;
            idx++;
        }
    }
    draw = (BattlePanelPrimitiveDispatch *)D_00887310;
    draw->draw(4, lo, 42);
    {
        u32 idx;
        u32 cursor;
        cursor = 0;
        idx = 0;
        while (idx < 21) {
            f32 *point = D_00626930[idx];
            f32 *point2;
            f32 (*out)[16] = &lo[cursor];
            out[0][0] = (0.0f + 320.0f) + sx2 * point[0];
            out[0][1] = (0.0f + 211.0f) + sy2 * point[1];
            point2 = D_006269E0[idx];
            out[1][0] = (0.0f + 320.0f) + sx3 * point2[0];
            out[1][1] = (0.0f + 211.0f) + sy3 * point2[1];
            cursor += 2;
            idx++;
        }
    }
    draw->draw(4, lo, 42);
    {
        u32 idx;
        u32 cursor;
        cursor = 0;
        idx = 0;
        while (idx < 19) {
            f32 *point = D_00626A90[idx];
            f32 *point2;
            f32 (*out)[16] = &lo[cursor];
            out[0][0] = (0.0f + 320.0f) + sx2 * point[0];
            out[0][1] = (0.0f + 211.0f) - sy2 * point[1];
            point2 = D_00626B30[idx];
            out[1][0] = (0.0f + 320.0f) + sx3 * point2[0];
            out[1][1] = (0.0f + 211.0f) - sy3 * point2[1];
            cursor += 2;
            idx++;
        }
    }
    draw->draw(4, lo, 38);
    {
        u32 idx;
        u32 cursor;
        cursor = 0;
        idx = 0;
        while (idx < 19) {
            f32 *point = D_00626A90[idx];
            f32 *point2;
            f32 (*out)[16] = &lo[cursor];
            out[0][0] = (0.0f + 320.0f) + sx2 * -point[0];
            out[0][1] = (0.0f + 211.0f) - sy2 * point[1];
            point2 = D_00626B30[idx];
            out[1][0] = (0.0f + 320.0f) + sx3 * -point2[0];
            out[1][1] = (0.0f + 211.0f) - sy3 * point2[1];
            cursor += 2;
            idx++;
        }
    }
    draw->draw(4, lo, 38);
}

#pragma pop
/*
 * measured: 916/928 bytes, 15 resolved relocations, 12 zero alignment bytes.
 * The initialization loop covers 81 real vertex records; the four geometry
 * phases supply 77 vertices. Keep each quadrant cursor's separate lifetime.
 */
// Intent: draw an 81-vertex radial disc with the given scale, depth and colour. [inferred]
// FUN_00204690
#pragma push
/* measured: btlPanelDrawCircle MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlPanelDrawCircle(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color)
{
    f32 vertices[81][16];
    u32 alpha = ((u8 *)&color)[3];
    u32 blue = ((u8 *)&color)[2];
    u32 green = ((u8 *)&color)[1];
    u32 red = ((u8 *)&color)[0];
    f32 reciprocal;
    f32 transformedDepth;
    u32 vertex;
    u32 initialize;
    scaleX *= fGpffff82e0;
    scaleY *= fGpffff82e4;
    transformedDepth = D_008872F8[0] - depth;
    reciprocal = 1.0f / *(f32 *)((u8 *)(u32)func_00457120() + 0x80);
    for (initialize = 0; initialize < 81; initialize++) {
        f32 *out = vertices[initialize];
        out[2] = transformedDepth;
        out[6] = reciprocal;
        out[8] = (f32)red;
        out[9] = (f32)green;
        out[10] = (f32)blue;
        out[11] = (f32)alpha;
    }
    vertex = 0;
    vertices[0][0] = 320.0f;
    vertices[0][1] = 211.0f;
    {
        s32 i;
        for (i = 0; (u32)i < 20; i++) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * point[0];
            out[1] = (0.0f + 211.0f) - scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 18; i >= 0; i--) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * -point[0];
            out[1] = (0.0f + 211.0f) - scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 1; (u32)i < 20; i++) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * -point[0];
            out[1] = (0.0f + 211.0f) + scaleY * point[1];
            vertex++;
        }
    }
    {
        s32 i;
        for (i = 18; i >= 0; i--) {
            f32 *point = D_00626890[i];
            f32 *out = vertices[vertex];
            out[0] = (0.0f + 320.0f) + scaleX * point[0];
            out[1] = (0.0f + 211.0f) + scaleY * point[1];
            vertex++;
        }
    }
    D_00887310[0](5, vertices, vertex);
}

#pragma pop
/* measured: opt_propagation off probe for callback cache in func_00204a30. */
/* measured: btlPanelDrawBackdrop MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: set up the sky render state and draw the backdrop disc. [inferred]
// FUN_00204A30
void btlPanelDrawBackdrop(u8 *arg0, f32 fparg0, f32 fparg1)
{
    void (**base)(u32, u32);
    Work4 work;

    base = D_00887300;
    base[0](8, 1);
    base[0](6, 0);
    base[0](1, 0);
    RpSkyRenderStateSet(3, 0x32801);
    work.colors.c0 = 0;
    work.colors.c1 = -1;
    work.colors.c2 = 0;
    work.colors.c3 = 0x30;
    work.value3 = 0;
    work.value0 = 0;
    work.value1 = 0x280;
    work.value2 = 0x1C0;
    func_0045d6e0((u8 *)&work.colors, (f32 *)(void *)&work.value3, 0.0f, 0);
    work.colors.c0 = 0xFF;
    work.colors.c1 = 0xFF;
    work.colors.c2 = 0xFF;
    work.colors.c3 = 0x20;
    btlPanelDrawCircle(arg0, fparg0, fparg1, 100.0f, *(s32 *)(void *)&work.colors);
    RpSkyRenderStateSet(3, 0x717FB);
    base[0](8, 0);
}

/* measured: close callback cache probe for func_00204a30. */
/* measured: btlPanelDrawBackdropGrid, btlPanelDrawFrame, btlSelectionDrawBar, btlSelectionDrawCommands, btlSelectionDrawCurrentLabel, btlSelectionDrawItemPanel, btlSelectionDrawList, btlSelectionDrawSkillPanel, btlSelectionDrawSlideIn, btlSelectionDrawSwapPanel, btlSelectionDrawTitle, btlSelectionHandleInput, btlSelectionHandleSkillInput, btlSelectionOpenSubList MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
/* 460/464 bytes; 13 resolved relocations; four zero alignment bytes.
 * Forward byte opacity and reload the render-state callback for every call. */
#pragma push
/* measured: btlPanelDrawSpriteGrid MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: draw a 3 by 5 grid of sprite frames with the given opacity. [inferred]
// FUN_00204B80
void btlPanelDrawSpriteGrid(u8 *arg0, f32 farg0, f32 farg1, u8 opacity)
{
    extern u8 D_00764564;
    s16 row;
    s16 column;
    s16 frame;
    f32 x;
    f32 y;

    {
        void (**state)(u32, u32);
        state = D_00887300;
        state[0](6, 1);
    }
    btlUiSetOrigin(arg0, 36.0f, 19.0f);
    btlUiSetAlpha(arg0, 50.0f);
    btlUiSetRenderMode(2);
    y = 0.0f;
    row = 0;
    while (row < 3) {
        x = 0.0f;
        column = 0;
        while (column < 5) {
            frame = D_00764564 % 4;
            D_00764564++;
            btlUiDrawSpriteFaded(arg0, 15, frame, x, y, 255, 255, 255, opacity);
            x += 126.0f;
            column++;
        }
        y += 126.0f;
        row++;
    }
    btlUiSetRenderMode(0);
    btlUiSetAlpha(arg0, 0.0f);
    {
        void (**state)(u32, u32);
        state = D_00887300;
        state[0](6, 0);
        state[0](1, 0);
    }
}

#pragma pop
// Intent: clear the task's flag word and its active bit. [inferred]
// FUN_00204D50
void btlPanelClearFlag(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    u8 *temp_2;

    temp_2 = (u8 *)kwlnTaskGetWork((void *)task);
    *(s16 *)(temp_2 + 0xAC) = 0;
    *(s32 *)(temp_2 + 0xA0) &= ~1;
}

// Intent: set the active bit of the task's state word. [inferred]
// FUN_00204D90
void btlPanelSetFlag(void)
{
    u8 *p;

    p = (u8 *)kwlnTaskGetWork();
    *(s32 *)(p + 0xA0) = *(s32 *)(p + 0xA0) | 0x1;
}

// Intent: draw a rotated battle-panel strip with an optional transparent extension. [inferred]
// FUN_00204DC0
#pragma push
/* measured: btlPanelDrawStrip MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void btlPanelDrawStrip(s32 index, f32 inputX, f32 inputY, f32 depth, f32 angle, s32 extend)
{
    f32 vertices[4][16];
    s32 (**draw)(s32, void *, s32);
    void (**state)(u32, u32);
    f32 reciprocal;
    f32 cosine;
    f32 sine;
    f32 radians;
    f32 width;
    f32 margin;
    f32 halfWidth;
    f32 x;
    f32 y;
    f32 zero;
    f32 leftX;
    f32 leftY;
    f32 product;
    f32 sinOffset;
    f32 cosOffset;
    f32 displacement;
    {
        void (**initialState)(u32, u32);
        initialState = D_00887300;
        initialState[0](1, 0);
    }
    reciprocal = 1.0f / *(f32 *)(func_00457120() + 0x80);
    depth = D_008872F8[0] - depth;
    radians = fGpffff836c * angle;
    cosine = cosf(radians);
    sine = sinf(radians);
    width = 86.0f;
    x = inputX + 97.0f;
    y = inputY + ((0.0f + 312.0f) + 15.0f * (f32)((s16)index - 3));
    margin = 64.0f;
    halfWidth = width + margin;
    zero = 0.0f;
    {
        struct { f32 x, y; } offset;
        offset.x = zero + halfWidth;
        offset.y = 8.0f;
        sinOffset = offset.y * sine;
        vertices[0][0] = x + offset.x * cosine - sinOffset;
        cosOffset = offset.y * cosine;
        displacement = y + offset.x * sine;
        vertices[0][1] = displacement + cosOffset;
        vertices[0][2] = depth;
        offset.x = zero - halfWidth;
        product = offset.x * cosine;
        leftX = x + product;
        vertices[1][0] = leftX - sinOffset;
        product = offset.x * sine;
        leftY = y + product;
        vertices[1][1] = leftY + cosOffset;
        vertices[1][2] = depth;
        offset.y = -8.0f;
        sinOffset = offset.y * sine;
        vertices[3][0] = leftX - sinOffset;
        cosOffset = offset.y * cosine;
        vertices[3][1] = leftY + cosOffset;
        vertices[3][2] = depth;
        offset.x = zero + halfWidth;
        vertices[2][0] = x + offset.x * cosine - sinOffset;
        displacement = y + offset.x * sine;
        vertices[2][1] = displacement + cosOffset;
        vertices[2][2] = depth;
    }
    vertices[0][8] = 27.0f;
    vertices[0][9] = 27.0f;
    vertices[0][10] = 27.0f;
    vertices[0][11] = 255.0f;
    vertices[1][8] = 27.0f;
    vertices[1][9] = 27.0f;
    vertices[1][10] = 27.0f;
    vertices[1][11] = 255.0f;
    vertices[2][8] = 27.0f;
    vertices[2][9] = 27.0f;
    vertices[2][10] = 27.0f;
    vertices[2][11] = 255.0f;
    vertices[3][8] = 27.0f;
    vertices[3][9] = 27.0f;
    vertices[3][10] = 27.0f;
    vertices[3][11] = 255.0f;
    vertices[0][6] = reciprocal;
    vertices[1][6] = reciprocal;
    vertices[2][6] = reciprocal;
    vertices[3][6] = reciprocal;
    func_00364c50();
    draw = D_00887310;
    draw[0](4, vertices, 4);
    func_00364c70();
    if (extend != 0) {
        state = D_00887300;
        state[0](8, 1);
        zero = 0.0f;
        {
            struct { f32 x, y; } offset;
            offset.x = zero + halfWidth;
            offset.y = zero;
            vertices[0][0] = x + offset.x * cosine - offset.y * sine;
            vertices[0][1] = y + offset.x * sine + offset.y * cosine;
            offset.x = offset.y - halfWidth;
            offset.y = zero;
            product = offset.x * cosine;
            leftX = x + product;
            vertices[1][0] = leftX - offset.y * sine;
            product = offset.x * sine;
            leftY = y + product;
            vertices[1][1] = leftY + offset.y * cosine;
            offset.y = -800.0f;
            sinOffset = offset.y * sine;
            vertices[3][0] = leftX - sinOffset;
            cosOffset = offset.y * cosine;
            vertices[3][1] = leftY + cosOffset;
            offset.x = zero + halfWidth;
            vertices[2][0] = x + offset.x * cosine - sinOffset;
            displacement = y + offset.x * sine;
            vertices[2][1] = displacement + cosOffset;
        }
        vertices[0][8] = 27.0f;
        vertices[0][9] = 27.0f;
        vertices[0][10] = 27.0f;
        vertices[0][11] = 0.0f;
        vertices[1][8] = 27.0f;
        vertices[1][9] = 27.0f;
        vertices[1][10] = 27.0f;
        vertices[1][11] = 0.0f;
        vertices[2][8] = 27.0f;
        vertices[2][9] = 27.0f;
        vertices[2][10] = 27.0f;
        vertices[2][11] = 0.0f;
        vertices[3][8] = 27.0f;
        vertices[3][9] = 27.0f;
        vertices[3][10] = 27.0f;
        vertices[3][11] = 0.0f;
        draw[0](4, vertices, 4);
        state[0](8, 0);
    }
}

#pragma pop
// Intent: draw one skill row (icon, name and cost digits) at the given position. [inferred]
// FUN_00205170
#pragma push
/* measured: btlPanelDrawSkillEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: btlPanelDrawSkillEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
void btlPanelDrawSkillEntry(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 showDetail)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern void func_002bc860(f32 x, f32 y, f32 z, s32 color,
                              s32 mode, s32 flags, s32 skill);
    u8 *glyphs;
    u8 *unit;
    s32 skill;
    u8 tone;
    s32 cost;
    s32 alpha;
    s32 tens;
    s32 hundreds;
    s32 radix;
    f32 textX;
    f32 digitY;
    f32 digitX;
    Vec2f iconPosition;
    BattleSkillIconColor iconColor;

    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(work + 0x5B0));
    unit = *(u8 **)(*(u8 **)(*(u8 **)(work + 0x178) + 0x30) + 0xA64);
    skill = *(s16 *)(p4_002091f0_add((u32)(slot * 2), work) + 0x194);
    if (skill >= 0x1B8 || datCalcThresholdTrigger(unit, (u16)skill) != 0) {
        if (highlighted != 0) {
            tone = 0x6E;
        } else {
            tone = 0x96;
        }
    } else if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    iconPosition.x = x;
    iconPosition.y = y;
    iconColor.b0 = tone;
    iconColor.b1 = tone;
    iconColor.b2 = tone;
    iconColor.b3 = opacity;
    ShdSkill_DrawIcon(iconPosition, 50.0f, iconColor, (u16)skill,
                  *(s32 *)(glyphs + 0x60));
    frFontSetFlagBits(0x40);
    alpha = opacity & 0xFF;
    textX = 42.0f + x;
    {
        f32 textY = (2.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawTextWithCharWidth(textX, textY, depth,
                      alpha | ((high << 24) | (high << 16) | ((u32)(u8)tone << 8)),
                      0, 1, (const char *)iGpffffb448 + skill * 0x13, 0, -1);
    }
    frFontClearFlagBits(0x40);
    if (skill < 0x1B8) {
        cost = datCalcSkillCost(unit, (u16)skill);
        if (cost != 0) {
            digitY = 10.0f + y;
            digitX = 262.0f + x;
            btlUiDrawSpriteFaded(glyphs, 0xC, (cost % 10) + 9,
                          32.0f + digitX, digitY, tone, tone, tone, opacity);
            radix = 10;
            tens = cost / radix;
            if (tens != 0) {
                btlUiDrawSpriteFaded(glyphs, 0xC, (tens % radix) + 9,
                              16.0f + digitX, digitY, tone, tone, tone, opacity);
            }
            hundreds = cost / 100;
            if (hundreds != 0) {
                btlUiDrawSpriteFaded(glyphs, 0xC, (hundreds % 10) + 9,
                              digitX, digitY, tone, tone, tone, opacity);
            }
            if ((datCalcThresholdKind(unit, (u16)skill) & 0xFFFF) == 1) {
                btlUiDrawSpriteFaded(glyphs, 0xC, 0x56, 310.0f + x, 12.0f + y,
                              tone, tone, tone, opacity);
            } else {
                btlUiDrawSpriteFaded(glyphs, 0xC, 0x57, 310.0f + x, 12.0f + y,
                              tone, tone, tone, opacity);
            }
        }
    }
    if (showDetail != 0) {
        frFontSetFlagBits(0x40);
        func_002bc860(10.0f + ((2.0f + textX) - 1.0f), 36.0f + y,
                      0.0f, alpha | ~0xFF, 1, 0, skill);
        frFontClearFlagBits(0x40);
    }
}

#pragma pop
/* 888/896 bytes; twelve resolved relocations and eight zero alignment bytes.
 * Narrow the promoted row ID at helper boundaries. The four-byte color
 * has byte and packed-word views; reload the signed number after drawing. */
#pragma push
/* measured: btlPanelDrawEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* measured: btlPanelDrawEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: btlPanelDrawEntry MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: draw one entry row (icon, name, digit and optional detail label). [inferred]
// FUN_002055D0
void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 show_detail)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern void func_00113280(Vec2f arg0, f32 fparg0, s32 arg1,
                              s16 arg2, s32 arg3, s32 arg4);
    u8 *glyphs;
    u8 tone;
    s32 off;
    s32 id;
    s32 digit;
    s32 masked;
    s32 tens;
    s32 radix;
    f32 digit_y;
    f32 digit_x;
    f32 fx;
    const char *name;
    Vec2f pos;
    union {
        Color4 bytes;
        s32 word;
    } color;

    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(work + 0x5B0));
    off = slot * 4;
    id = *(s16 *)(p4_002091f0_add((u32)off, work) + 0x1A6);
    if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    pos.x = x;
    pos.y = y;
    color.bytes.c0 = tone;
    color.bytes.c1 = tone;
    color.bytes.c2 = tone;
    color.bytes.c3 = opacity;
    func_00113280(pos, 50.0f, color.word, id,
                  *(s32 *)(glyphs + 0x5C), *(s32 *)(glyphs + 0x60));
    frFontSetFlagBits(0x40);
    masked = opacity & 0xFF;
    fx = 42.0f + x;
    name = (const char *)datGetItemNameId(id);
    {
        f32 text_y = (2.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawTextWithCharWidth(fx, text_y, depth,
                      (high << 24) | (high << 16) |
                          ((u32)(u8)tone << 8) | masked,
                      0, 1, name, 0, -1);
    }
    frFontClearFlagBits(0x40);
    btlUiDrawSpriteFaded(glyphs, 0xC, 0x47, (374.0f + x) - 97.0f,
                  (157.0f + y) - 145.0f, tone, tone, tone, opacity);
    digit = *(s8 *)(p4_002091f0_add((u32)off, work) + 0x1A8);
    digit_y = (155.0f + y) - 145.0f;
    digit_x = (398.0f + x) - 97.0f;
    btlUiDrawSpriteFaded(glyphs, 0xC, (digit % 10) + 9, 16.0f + digit_x,
                  digit_y, tone, tone, tone, opacity);
    radix = 10;
    tens = digit / radix;
    if (tens != 0) {
        btlUiDrawSpriteFaded(glyphs, 0xC, (tens % radix) + 9, digit_x, digit_y,
                      tone, tone, tone, opacity);
    }
    if (show_detail != 0) {
        frFontSetFlagBits(0x40);
        {
            s32 labelX;
            s32 labelY;
            s32 item;
            labelX = (s32)(10.0f + ((2.0f + fx) - 1.0f));
            labelY = (s32)(36.0f + y);
            item = (s16)id;
            func_002bc4b0(0.0f, item, labelX, labelY, masked | ~0xFF, 1, 0);
        }
        frFontClearFlagBits(0x40);
    }
}

#pragma pop
/* 712/720 bytes; twelve resolved relocations; eight zero alignment bytes.
 * Keep the shared decimal divisor and the branch-local byte tones. */
#pragma push
/* measured: btlPanelDrawPersonaLevel MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: btlPanelDrawPersonaLevel MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: draw a persona row with its lead marker, level digits and name. [inferred]
// FUN_00205950
void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 showDetail)
{
    extern u32 kwlnTaskGetWork(void *task);
    u8 *glyphs;
    u8 *persona;
    u8 tone;
    s32 level;
    s32 tens;
    s32 radix;
    f32 digit_y;
    f32 digit_x;
    const char *name;

    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(work + 0x5B0));
    persona = datPersonaRosterSlot((s16)slot);
    if (slot == (s16)datPersonaGetLeadSlot()) {
        btlUiDrawSpriteFaded(glyphs, 13, 0x2B, -11.0f + x, 6.0f + y,
                      0xF3, 0, 0xB, opacity);
        if (highlighted != 0) {
            tone = 0x6E;
        } else {
            tone = 0x96;
        }
    } else if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    btlUiDrawSpriteFaded(glyphs, 13, 0x2A, 33.0f + x, 12.0f + y,
                  tone, tone, tone, opacity);
    level = (u8)datPersonaGetLevel(persona);
    digit_y = 5.0f + y;
    digit_x = 63.0f + x;
    btlUiDrawSpriteFaded(glyphs, 13, level % 10 + 0x1D, 22.0f + digit_x,
                  digit_y, tone, tone, tone, opacity);
    radix = 10;
    tens = level / radix;
    if (tens != 0) {
        btlUiDrawSpriteFaded(glyphs, 13, tens % radix + 0x1D, digit_x,
                      digit_y, tone, tone, tone, opacity);
    }
    frFontSetFlagBits(0x40);
    name = (const char *)datPersonaGetRow(*(u16 *)(persona + 2));
    {
        f32 text_x = 151.0f + x;
        f32 text_y = (4.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawTextWithCharWidth(
            text_x, text_y, depth,
            (high << 24) | (high << 16) | ((u32)(u8)tone << 8) | (u8)opacity,
            0, 1, name, 0, -1);
    }
    frFontClearFlagBits(0x40);
}

#pragma pop
/* 468/480 bytes; eight resolved relocations; twelve zero alignment bytes.
 * Keep branch-local tones and the two-channel cache after text coordinates. */
#pragma push
/* measured: btlPanelDrawPersonaName MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
/* measured: btlPanelDrawPersonaName MATCH -> MISMATCH without this pragma. */
#pragma opt_common_subs off
/* measured: btlPanelDrawPersonaName MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: draw a persona name and its two sprite marks. [inferred]
// FUN_00205C20
void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 showDetail)
{
    extern u32 kwlnTaskGetWork(void *task);
    u8 *glyphs;
    u8 *persona;
    u8 tone;
    const char *name;

    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(work + 0x5B0));
    if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    persona = ((u8 **)(work + 0x17C))[slot];
    frFontSetFlagBits(0x40);
    name = (const char *)func_0010d6d0(*(s16 *)(persona + 0xA4));
    {
        f32 text_x = 1.0f + x;
        f32 text_y = (19.0f + y) - 3.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawText(
            text_x, text_y, depth,
            (high << 24) | (high << 16) | ((u32)(u8)tone << 8) | (u8)opacity,
            0, 1, name, 0, 0);
    }
    frFontClearFlagBits(0x40);
    btlUiDrawSpriteFaded(glyphs, 9, 0x3C, 155.0f + x,
                  24.0f + y, tone, tone, tone, opacity);
    btlUiDrawSpriteFaded(
        glyphs, 9, func_00105f00(*(s16 *)(persona + 0xA4)) + 0x3F,
        178.0f + x, 16.0f + y, tone, tone, tone,
        opacity);
}

#pragma pop
/* 488/496 bytes; seven resolved relocations; eight zero alignment bytes.
 * Preserve the two narrow tone assignments instead of rebuilding a merge. */
#pragma push
/* measured: btlPanelDrawListRow MATCH -> MISMATCH without this pragma. */
#pragma opt_rebuildconditionals off
// Intent: draw one list row with its marker sprites and optional text. [inferred]
// FUN_00205E00
void btlPanelDrawListRow(u8 *panel, s32 index, f32 x, f32 y,
                   u8 opacity, s32 selected, s32 draw_text)
{
    u8 *work;
    u8 color;
    f32 line_y;

    work = (u8 *)kwlnTaskGetWork(*(void **)(panel + 0x5B0));
    if (selected != 0) color = 0x1B;
    else color = 0xFF;
    line_y = 8.0f + y;
    btlUiDrawSpriteFaded(work, 9, 0x3C, 48.0f + x, line_y, color, color, color, opacity);
    btlUiDrawSpriteFaded(work, 9, 0x3C, 270.0f + x, line_y, color, color, color, opacity);
    btlUiDrawSpriteFaded(work, 9, (s32)((u32)index + 0x3FU), 71.0f + x, y,
                  color, color, color, opacity);
    if (draw_text != 0) {
        frFontSetFlagBits(0x40);
        itfMesWindowDrawEntry(10.0f + (2.0f + (42.0f + x) - 1.0f), 36.0f + y, 0.0f,
                      (s32)(0xFFFFFF00U | (u8)opacity), 1, 0, 0,
                      *(s32 *)(work + 0x98), index);
        frFontClearFlagBits(0x40);
    }
}

#pragma pop
#pragma push
/* Native b210 O2: 3548/3552 bytes; 28 resolved relocations and
 * four zero alignment bytes. Distinct literal/cached bounds and
 * successive coordinate work preserve the original evaluation
 * order. See docs/probe_archive/Battle_selection_00205ff0_20260923.md. */
// Intent: draw the battle selection list, rows and highlight, through the render callback. [inferred]
// FUN_00205FF0
void btlSelectionDrawList(u8 *state, u8 *selectionState, f32 inputScaleX, f32 scaleY, BattleSelectionDraw callback)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern f32 fGpffff809c;
    extern f32 fGpffff8198;
    BattleSelectionInput *list;
    BattleSelectionDraw drawSelection;
    BattleRenderDispatch *renderer;
    u8 *glyphs;
    f32 slideProgress;
    f32 offsetX;
    f32 offsetY;
    f32 selectedOffsetY;
    f32 unitOrScrollX;
    f32 clipProgress;
    f32 upperEdgeY;
    f32 verticalWork;
    f32 horizontalWork;
    /* These are successive real work values: the incoming scale is consumed
     * before the selected-row displacement replaces it; the easing slope is
     * consumed before progress and its rescaled opacity phase replace it.
     * Keeping this declaration order reproduces the retail saved registers. */
    f32 scaleOrRowY;
    f32 easingWork;
    s32 showPrompt;
    s32 showScroll;
    s32 sliding;
    s32 row;
    s32 count;
    /* The rectangle is copied as four float-sized words by the primitive
     * wrapper, then interpreted as signed integer coordinates by its builder.
     * Both complete views cover the same sixteen-byte object. The twelve-byte
     * gap preserves retail's color placement at sp+0xFC; it is never read. */
    struct {
        union {
            s32 coordinates[4];
            f32 words[4];
        } rectangle;
        u8 unused[12];
        Color4 colors;
    } clip;

    list = (BattleSelectionInput *)selectionState;
    scaleOrRowY = inputScaleX;
    drawSelection = callback;
    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(state + 0x5B0));
    showScroll = 1;
    showPrompt = 1;
    if (*(s32 *)(state + 4) & 4) {
        f32 raw;
        f32 clamped;
        verticalWork = 4.0f;
        raw = (f32)*(s16 *)(state + 0x16) / verticalWork;
        unitOrScrollX = 1.0f;
        clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
        easingWork = 2.0f;
        slideProgress = (easingWork * clamped) - (clamped * clamped);
        offsetX = 0.0f;
        offsetY = -50.0f * slideProgress;
        selectedOffsetY = offsetY;
    } else {
        f32 raw;
        f32 clamped;
        verticalWork = 4.0f;
        unitOrScrollX = 1.0f;
        raw = unitOrScrollX - (f32)*(s16 *)(state + 0x16) / verticalWork;
        clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
        easingWork = 2.0f;
        slideProgress = unitOrScrollX - ((easingWork * clamped) - (clamped * clamped));
        offsetX = 0.0f;
        offsetY = -50.0f * slideProgress;
        selectedOffsetY = offsetY;
    }
    sliding = slideProgress > 0.0f;
    if (selectionState == state + 0xDC) {
        selectedOffsetY += 16.0f;
        showScroll = 0;
        showPrompt = 0;
    }
    btlUiSetOrigin(glyphs, scaleOrRowY, scaleY);
    btlUiSetAlpha(glyphs, 50.0f);
    if (showPrompt != 0) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x18, 261.0f, 410.0f, 0x21, 0x21, 0x21, 0xFF);
        btlUiDrawSpriteFaded(glyphs, 9, 0x2A, 261.0f, 410.0f, 0xFF, 0x7F, 0xE9, 0xFF);
        if (selectionState != state + 0x144) {
            if (*(s32 *)(state + 4) & 4) {
                btlUiDrawSpriteEntry(glyphs, 9, 0x2B, 283.0f, 410.0f);
            } else {
                btlUiDrawSpriteEntry(glyphs, 9, 0x2C, 283.0f, 410.0f);
            }
        } else {
            btlUiDrawSpriteEntry(glyphs, 9, 0x4D, 283.0f, 413.0f);
        }
    }
    {
        f32 raw;
        f32 clamped;
        raw = (f32)*(s16 *)(state + 0x20) / verticalWork;
        clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
        clipProgress = unitOrScrollX - ((easingWork * clamped) - (clamped * clamped));
    }
    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(6, 1);
    verticalWork = 70.0f * clipProgress;
    upperEdgeY = 129.0f + offsetY + verticalWork;
    horizontalWork = 476.0f + offsetX;
    btlUiDrawSpriteEntry(glyphs, 9, 0x26, horizontalWork, upperEdgeY);
    verticalWork = (274.0f + offsetY) - verticalWork;
    btlUiDrawSpriteEntry(glyphs, 9, 0x26, horizontalWork, verticalWork);
    if (!(clipProgress <= 0.0f)) {
        BattleRenderDispatch *clipRenderer;
        clipRenderer = (BattleRenderDispatch *)D_00887300;
        clipRenderer->setState(1, 0);
        clipRenderer->setState(8, 1);
        clip.colors.c0 = 0;
        clip.colors.c1 = 0;
        clip.colors.c2 = 0xFF;
        clip.colors.c3 = 0;
        clip.rectangle.coordinates[0] = (s32)(32.0f + offsetX);
        clip.rectangle.coordinates[2] = 0x1E0;
        clip.rectangle.coordinates[3] = 0x46;
        clip.rectangle.coordinates[1] = (s32)(8.0f + (upperEdgeY - 70.0f));
        func_0045d6e0((u8 *)&clip.colors, clip.rectangle.words, 0.0f, 0);
        clip.rectangle.coordinates[1] = (s32)(3.0f + verticalWork);
        func_0045d6e0((u8 *)&clip.colors, clip.rectangle.words, 0.0f, 0);
        clipRenderer->setState(8, 0);
    }
    {
        f32 translation;
        f32 x;
        x = (f32)0x1DF;
        translation = offsetX;
        x += translation;
        btlUiDrawSpriteFaded(glyphs, 9, 0x24, x, 135.0f + offsetY, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    renderer->setState(6, 0);
    {
        f32 raw;
        f32 clamped;
        raw = (f32)*(s16 *)(state + 0x22) / 10.0f;
        clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
        clamped = 1.0f - ((easingWork * clamped) - (clamped * clamped));
        {
            f32 bright;
            f32 y;
            f32 x;
            u32 alpha;
            bright = (1.0f - clamped) * 255.0f;
            alpha = (u8)bright;
            y = 113.0f + offsetY;
            x = (410.0f + offsetX) - clamped * 200.0f;
            btlUiDrawSpriteFaded(glyphs, 9, 0x29, x, y, 0x1B, 0x1B, 0x1B, (u8)alpha);
        }
    }
    renderer->setState(6, 1);
    {
        s32 available;
        s32 visible;
        available = list->count;
        visible = list->pageSize;
        count = (s16)(available < visible ? available : visible);
    }
    row = 0;
    if (count > 0) {
        s32 flag;
        f32 rowX;
        f32 highlightX;
        rowX = 97.0f + offsetX;
        highlightX = (f32)0x1DF;
        highlightX += offsetX;
        for (; row < count; row++) {
            s32 slot = list->first + row;
            f32 rowY = 31.0f * (f32)row + 145.0f + offsetY;
            if (list->selected == slot) {
                if (sliding != 0) {
                    goto next_iter;
                }
                btlUiDrawSpriteEntry(glyphs, 9, 0x27, highlightX, 31.0f * (f32)row + 143.0f + selectedOffsetY);
                flag = 1;
                goto do_cb;
            } else {
                flag = 0;
            }
        do_cb:
            drawSelection(state, slot, rowX, rowY, 0xFF, flag, 0);
        next_iter:
            ;
        }
    }
    if (sliding != 0) {
        f32 slideDistance;
        f32 selectionX;
        f32 selectionY;
        s32 showDetail;
        if (*(s32 *)(state + 4) & 4) {
            f32 raw;
            f32 clamped;
            raw = (f32)*(s16 *)(state + 0x18) / 7.0f;
            clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
            easingWork = (easingWork * clamped) - (clamped * clamped);
            slideDistance = -410.0f;
        } else {
            f32 raw;
            f32 clamped;
            raw = 1.0f - (f32)*(s16 *)(state + 0x18) / 7.0f;
            clamped = raw > 1.0f ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
            easingWork = unitOrScrollX - ((easingWork * clamped) - (clamped * clamped));
            slideDistance = -530.0f;
        }
        {
            horizontalWork = slideDistance * (1.0f - easingWork);
            scaleOrRowY = 31.0f * (f32)(list->selected - list->first);
            selectionX = 97.0f + offsetX;
            selectionY = 145.0f + offsetY + scaleOrRowY;
            btlUiDrawSpriteFaded(glyphs, 9, 0x25, 489.0f + horizontalWork,
                          50.0f + (88.0f + scaleOrRowY + offsetY), 0x28, 0x28, 0x28, 0xF2);
            btlUiDrawSpriteEntry(glyphs, 9, 0x26, 486.0f + horizontalWork,
                          50.0f + (214.0f + scaleOrRowY + offsetY));
            showDetail = 1;
            if (easingWork < 1.0f) {
                if (!(easingWork <= fGpffff809c)) {
                    f32 rowY;
                    easingWork = (easingWork - fGpffff809c) / fGpffff8198;
                    rowY = 50.0f + (120.0f + scaleOrRowY + offsetY) - (unitOrScrollX - easingWork) * 25.0f;
                    btlUiDrawSpriteFaded(glyphs, 9, 0x28, 68.0f, rowY, 0xF3, 0, 0x0B, 0xFF);
                    {
                        u32 alpha;
                        f32 opacity;
                        opacity = 255.0f * easingWork;
                        alpha = (u8)opacity;
                        drawSelection(state, list->selected, selectionX, selectionY, (u8)alpha, 1, 1);
                    }
                }
                showDetail = 0;
            } else {
                btlUiDrawSpriteFaded(glyphs, 9, 0x28, 68.0f,
                              50.0f + (120.0f + scaleOrRowY + offsetY), 0xF3, 0, 0x0B, 0xFF);
            }
            {
                f32 limitedHighlightX;
                f32 translation;
                f32 x;
                if (horizontalWork < -10.0f) {
                    limitedHighlightX = 0.0f;
                } else {
                    limitedHighlightX = 10.0f + horizontalWork;
                }
                x = (f32)0x1DF;
                translation = offsetX;
                x += translation;
                btlUiDrawSpriteEntry(glyphs, 9, 0x27, x + limitedHighlightX,
                              143.0f + scaleOrRowY + selectedOffsetY);
                drawSelection(state, list->selected, selectionX, selectionY, 0xFF, 1, showDetail);
            }
        }
    }
    if (showScroll != 0) {
        unitOrScrollX = (f32)0x1CD + offsetX;
        btlUiDrawSpriteEntry(glyphs, 9, 0x2D, unitOrScrollX, 164.0f + offsetY);
        btlUiDrawSpriteEntry(glyphs, 9, 0x2E, unitOrScrollX, 236.0f + offsetY);
        {
            f32 ratio;
            s32 pageSize;
            s32 count;
            pageSize = list->pageSize;
            count = list->count;
            if (pageSize < count) {
                ratio = (f32)list->first / (f32)(count - pageSize);
            } else {
                ratio = 0.0f;
            }
            btlUiDrawSpriteEntry(glyphs, 9, 0x2F, (f32)0x1CF + offsetX, ratio * 57.0f + 166.0f + offsetY);
        }
    }
    renderer->setState(6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
}

#pragma pop
/* 868/880 bytes; seventeen resolved relocations and twelve zero alignment
 * bytes. Retain the renderer base separately for each drawing phase and
 * the float values between the easing product and integer pixel origin. */
// Intent: draw the selection panel's eased slide-in and its selection list. [inferred]
// FUN_00206DD0
void btlSelectionDrawSlideIn(u8 *work, u8 *selection, f32 x, f32 y,
                   BattleSelectionDraw drawSelection)
{
    u8 *glyphs;
    f32 progress;
    f32 clamped;
    f32 scale;
    f32 remainingFraction;
    f32 remaining;
    f32 slideProduct;
    f32 slideOffset;
    f32 row;
    s32 rect[4];
    Color4 color;
    BattleRenderDispatch *renderer;

    glyphs = (u8 *)kwlnTaskGetWork(*(s32 *)(work + 0x5B0));
    btlUiSetOrigin(glyphs, x, y);

    progress = (f32)(*(s16 *)(work + 0x1A)) / 4.0f;
    if (progress > 1.0f) {
        clamped = 1.0f;
    } else if (progress < 0.0f) {
        clamped = 0.0f;
    } else {
        clamped = progress;
    }

    scale = (2.0f * clamped) - (clamped * clamped);
    if (scale <= 0.0f) {
        return;
    }

    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(8, 1);
    if (scale < 1.0f) {
        renderer->setState(1, 0);
        color.c0 = 0;
        color.c1 = 0;
        color.c2 = 0xFF;
        color.c3 = 0;
        rect[0] = 0x6E;
        rect[1] = 0x14D;
        rect[2] = 0x17C;
        rect[3] = 0x25;
        func_0045d6e0((u8 *)&color, (f32 *)rect, 0.0f, 0);
    }

    btlUiSetAlpha(glyphs, 170.0f);
    btlUiSetScale(glyphs, 1.0f, scale);
    remainingFraction = 1.0f - scale;
    remaining = remainingFraction;
    slideProduct = 18.5f * remaining;
    slideOffset = slideProduct;
    row = (f32)0x14D + slideOffset;
    btlUiDrawSpriteEntry(glyphs, 9, 0x30, 110.0f, row);
    btlUiDrawSpriteEntry(glyphs, 9, 0x31, 470.0f, row);

    btlUiSetScale(glyphs, 1.0f, 1.0f);
    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(8, 0);
    btlUiSetAlpha(glyphs, 150.0f);
    renderer->setState(6, 1);
    drawSelection(work, *(s16 *)(selection + 4), 127.0f, 338.0f, 0xFF, 0, 0);
    renderer->setState(6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    btlUiDrawSpriteEntry(glyphs, 9, 0x32, 215.0f, 412.0f);
    btlUiDrawSpriteEntry(glyphs, 9, 0x33, 193.0f, 412.0f);
    btlUiDrawSpriteEntry(glyphs, 9, 0x33, (f32)0x19D, 412.0f);
}

/* 472/480 bytes; eight resolved relocations; eight zero alignment bytes.
 * Store each accepted signed item ID before its second quantity query. */
// Intent: refresh the selection's skill and item lists from the unit and persona data. [inferred]
// FUN_00207140
void btlSelectionRefreshList(u16 *flags, u8 *work)
{
    u8 *action;
    u8 *unit;
    u8 *persona;
    u16 skillSlot;
    u16 skillCount;
    u16 skill;
    u16 itemCount;
    u16 itemSlot;

    if (datGetFlag(0x3C) != 0) {
        action = *(u8 **)(*(u8 **)(work + 0x178) + 0x3F0);
        if (action != NULL) {
            btlSelectionUpdateWindow((u8 *)flags, *(s16 *)(action + 2), *(s16 *)action);
        }
    }
    *flags |= 4;
    *flags |= 2;
    skillCount = 0;
    unit = *(u8 **)(*(u8 **)(work + 0x178) + 0x30);
    if (unit[0xA2] == 0) {
        persona = (u8 *)datPersonaGetRecord(*(u16 *)(unit + 0xA4));
        for (skillSlot = 0; skillSlot < 8; skillSlot++) {
            skill = datPersonaGetSkillAt(persona, (s16)skillSlot);
            if (skill != 0 && skill < 0x1B8 && (*(u8 *)(skill * 0x28 + iGpffffb3b8 + 1) & 2)) {
                *(u16 *)(work + skillCount * 2 + 0x194) = skill;
                skillCount++;
            }
        }
    }
    *(u16 *)(work + 0x1A4) = skillCount;
    itemCount = 0;
    for (itemSlot = 0; itemSlot < 0x100; itemSlot++) {
        if (func_00106600((s16)(itemSlot + 0x300)) != 0 &&
            datCalcIsFlaggedPersonaSkill((u16)(itemSlot + 0x300)) != 0) {
            ((BattleListWork *)work)->items[itemCount].id = itemSlot + 0x300;
            ((BattleListWork *)work)->items[itemCount].quantity = func_00106600((s16)(itemSlot + 0x300));
            itemCount++;
        }
    }
    *(u16 *)(work + 0x5A6) = itemCount;
}

/* 2008/2016 bytes, with eight zero alignment bytes. The callback receives
   the same integer work address passed by btlListStep; its local byte view
   and unsigned party-count store preserve retail's register and store order.
   See docs/probe_archive/Battle_menu_00207320_20260922.md. */
#pragma push
/* measured: btlSelectionHandleInput MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: handle selection input and return the next panel state. [inferred]
// FUN_00207320
s32 btlSelectionHandleInput(u8 *selection, s32 workAddress, u8 **nextPanel)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern u16 *datPersonaGetRecord(u16 character);
    extern s32 func_001f0620(u8 *arg0, s64 arg1);
    extern s32 btlActionRunTargetCallback(s32 arg0, u16 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern s32 datCalcDefaultSkillId(u8 *unit);
    extern u8 *func_00117780(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
    extern u16 datPersonaCountValidMembers(void);
    extern void btlSelectionInit(u8 *arg0, s16 arg1, s16 arg2, void *a, void *b, void *c, void *d, u8 *arg7);
    extern void btlSelectionSetOwner(u8 *arg0, void *arg1);
    extern void btlUiSelectEffect(s32 arg0, u32 arg1);
    extern void btlSelectionResetState(u8 *arg0, u8 *arg1);
    extern u16 btlSelectionHandleSkillInput(u8 *arg0, u8 *arg1);
    extern void btlSelectionDrawSkillPanel(u8 *arg0, s32 arg1, f32 *arg2);
    extern void btlSelectionStepAnim(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void btlSelectionSaveCursorSecond(u8 *arg0, u8 *arg1);
    extern void btlSelectionResetPageState(u8 *arg0, u8 *arg1);
    extern u16 btlSelectionHandleItemInput(u8 *arg0, u8 *arg1);
    extern void btlSelectionDrawItemPanel(u8 *arg0, s32 arg1, f32 *arg2);
    extern void btlSelectionStepItemAnim(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void btlSelectionSaveCursorThird(u8 *arg0, u8 *arg1);
    extern void btlSelectionResetSubListState(u8 *arg0, u8 *arg1);
    extern u16 btlSelectionOpenSubList(u8 *arg0, s32 arg1, u8 **arg2);
    extern void btlSelectionDrawTitle(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void btlSelectionDrawPersonaList(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void btlSelectionSaveCursorFourth(u8 *arg0, u8 *arg1);
    extern void btlSelectionResetCursorState(u16 *arg0, u8 *arg1);
    extern u16 btlSelectionHandleSwapInput(u8 *arg0, u8 *arg1);
    extern void btlSelectionDrawSwapPanel(u8 *arg0, u8 *arg1, f32 *arg2);
    extern void btlSelectionDrawLevelList(s32 arg0, u8 *arg1, f32 *arg2);
    extern void func_0020ad70(void);
    u8 *work;
    u8 *panel;
    u8 *action;
    u8 *unit;
    s32 input;
    s16 subAction;
    s32 partyCount;

    work = (u8 *)(u32)workAddress;
    if (*(s16 *)(kwlnTaskGetWork(*(void **)(work + 0x5B0)) + 0xAA) < 2) {
        return 1;
    }
    if (*(s16 *)(work + 0x14) != 0) {
        return 1;
    }
    input = btlSelectionReadInput(selection) & 0xFFFF;
    if (input == 1) {
    if (*(s16 *)(selection + 4) != 3) {
        func_0045af60(0, 0, 0, 2);
    }
    *(s16 *)(selection + 4) = 3;
    *(s16 *)(selection + 2) = 0;
    } else if (input == 4) {
    if (func_001f0620(*(u8 **)(work + 0x178), 0xA) == 0) {
        return 1;
    }
    func_0045af60(0, 0, 0, 3);
    *(s16 *)(*(u8 **)(work + 0x178) + 0x6C) = 0xA;
    if (datGetFlag(0x38) != 0) {
        subAction = 0x10B;
    } else {
        subAction = 0x110;
    }
    *(s16 *)(*(u8 **)(work + 0x178) + 0x6E) = subAction;
    return 4;
    } else if (input == 5) {
    *(s16 *)(work + 0x14) = -3;
    } else if (input == 6) {
    *(s16 *)(work + 0x14) = 3;
    } else if (input == 2) {
    switch (*(s16 *)(selection + 4)) {
    case 3:
        if (func_001f0620(*(u8 **)(work + 0x178), 1) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6C) = 1;
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6E) =
            datCalcDefaultSkillId(*(u8 **)(*(u8 **)(*(u8 **)(work + 0x178) + 0x30) + 0xA64));
        break;
    case 4:
        if (func_001f0620(*(u8 **)(work + 0x178), 2) == 0) {
            if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(*(u8 **)(work + 0x178) + 0x30) + 0xA64), 8) != 0) {
                btlUiSelectEffect((s32)(u32)*(u8 **)(*(u8 **)(work + 0x178) + 0x30), 0x90);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        datPersonaGetRecord(*(u16 *)(*(u8 **)(*(u8 **)(work + 0x178) + 0x30) + 0xA4));
        btlSelectionInit(work + 0x74, 4, *(s16 *)(work + 0x1A4), btlSelectionResetState,
                      btlSelectionHandleSkillInput, btlSelectionDrawSkillPanel, btlSelectionSaveCursorSecond, work);
        panel = work + 0x74;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionStepAnim);
        *(s16 *)(work + 0x10) = 0;
        *(s32 *)(work + 4) = *(s32 *)(work + 4) & ~4;
        return 3;
    case 6:
        if (func_001f0620(*(u8 **)(work + 0x178), 3) == 0 || *(s16 *)(work + 0x5A6) == 0) {
            if (*(s16 *)(work + 0x5A6) == 0) {
                btlUiSelectEffect((s32)(u32)*(u8 **)(*(u8 **)(work + 0x178) + 0x30), 0x92);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        btlSelectionInit(work + 0xA8, 4, *(s16 *)(work + 0x5A6), btlSelectionResetPageState, btlSelectionHandleItemInput,
                      btlSelectionDrawItemPanel, btlSelectionSaveCursorThird, work);
        panel = work + 0xA8;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionStepItemAnim);
        *(s16 *)(work + 0x10) = 0;
        *(s32 *)(work + 4) = *(s32 *)(work + 4) & ~4;
        return 3;
    case 1:
        if (func_001f0620(*(u8 **)(work + 0x178), 4) == 0) {
            if ((s32)(func_001ef720(1, 0) & 0xFFFF) < 2) {
                btlUiSelectEffect((s32)(u32)*(u8 **)(*(u8 **)(work + 0x178) + 0x30), 0x93);
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        partyCount = 0;
        for (unit = *(u8 **)(iGpffffb3ac + 0x17C); unit != NULL; unit = *(u8 **)(unit + 0xA68)) {
            if (*(u16 *)(unit + 0xA4) != 1) {
                *(u8 **)(work + (partyCount & 0xFFFF) * 4 + 0x17C) = unit;
                partyCount = (partyCount + 1) & 0xFFFF;
            }
        }
        *(u16 *)(work + 0x18C) = partyCount;
        btlSelectionInit(work + 0xDC, 3, (s16)partyCount, btlSelectionResetSubListState, btlSelectionOpenSubList,
                      btlSelectionDrawTitle, btlSelectionSaveCursorFourth, work);
        panel = work + 0xDC;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionDrawPersonaList);
        *(s16 *)(work + 0x10) = 0;
        *(s32 *)(work + 4) = *(s32 *)(work + 4) & ~4;
        return 3;
    case 5:
        if (func_001f0620(*(u8 **)(work + 0x178), 5) == 0) {
            if (datCalcChkBadStatus(*(s32 *)(*(u8 **)(*(u8 **)(work + 0x178) + 0x30) + 0xA64), 8) != 0) {
                btlUiSelectEffect((s32)(u32)*(u8 **)(*(u8 **)(work + 0x178) + 0x30), 0x91);
            } else {
                action = *(u8 **)(work + 0x178);
                if (!(*(u16 *)(action + 0x18) & 0x400)) {
                    btlUiSelectEffect((s32)(u32)*(u8 **)(action + 0x30), 0x95);
                }
            }
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(u8 **)(work + 0x5A8) = func_00117780(*(s32 *)(work + 0x5B0), 0xF, 1, 8, 8);
        *(s16 *)(work + 0x5AC) = -1;
        btlSelectionInit(work + 0x144, 4, (s16)datPersonaCountValidMembers(), btlSelectionResetCursorState,
                      btlSelectionHandleSwapInput, btlSelectionDrawSwapPanel, func_0020ad70, work);
        panel = work + 0x144;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionDrawLevelList);
        *(s16 *)(work + 0x10) = 0;
        *(s32 *)(work + 4) = *(s32 *)(work + 4) & ~4;
        return 3;
    case 7:
        if (func_001f0620(*(u8 **)(work + 0x178), 6) == 0) {
            btlActionRunTargetCallback((s32)(u32)*(u8 **)(work + 0x178), 5, 0, 0, 2);
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6C) = 6;
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6E) = 0;
        break;
    case 2:
        if (func_001f0620(*(u8 **)(work + 0x178), 7) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6C) = 7;
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6E) = 0;
        break;
    case 0:
        if (func_001f0620(*(u8 **)(work + 0x178), 0xA) == 0) {
            func_0045af60(0, 0xF, 0, 8);
            return 1;
        }
        func_0045af60(0, 0, 0, 3);
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6C) = 0xA;
        if (datGetFlag(0x38) != 0) {
            subAction = 0x10B;
        } else {
            subAction = 0x110;
        }
        *(s16 *)(*(u8 **)(work + 0x178) + 0x6E) = subAction;
        break;
    default:
        break;
    }
    return 4;
    }
    return 1;
}

#pragma pop
// Intent: draw the growing command circles, enabled command rows and mode hints. [inferred]
// FUN_00207B00
void btlSelectionDrawCommands(u8 *selection, s32 workAddress, u8 *drawState)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern s32 func_001f0620(u8 *selection, s64 work);
    extern s32 func_001eb860(void);
    extern f64 func_0044dcd8(f32 value);
    extern f64 func_0044b310(f64 value);
    extern s16 D_00626BD0[];
    u8 *work;
    f32 *origin;
    u8 *glyphs;
    u32 menuFlags;
    s32 showCommands;
    f32 rotationProgress;
    f32 offsetX;
    f32 offsetY;
    f32 completeProgress;
    s16 selectedCommand;
    s32 row;
    s16 command;
    s32 available;
    u32 opacity;
    Vec2f position;
    union {
        Color4 bytes;
        s32 word;
    } color;
    BattleRenderDispatch *renderer;
    f32 translationX;
    struct {
        Vec2f center;
        f32 progress;
    } circle;

    work = (u8 *)(u32)workAddress;
    origin = (f32 *)drawState;
    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(work + 0x5B0));
    menuFlags = *(u32 *)(iGpffffb3ac + 0xC) & 0x10000;
    if (*(u8 **)(work + 0x38) != work + 0x40 || *(u16 *)work != 1 || menuFlags != 0) {
        rotationProgress = (f32)*(s16 *)(work + 0x12) / 6.0f;
        offsetX = -10.0f;
        offsetY = 28.0f;
        showCommands = 0;
    } else {
        showCommands = 1;
        offsetX = -10.0f;
        offsetY = 28.0f;
    }
    translationX = offsetX;
    btlUiSetOrigin(glyphs, origin[0] + offsetX, origin[1] + offsetY);
    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(8, 1);
    renderer->setState(1, 0);
    {
        f32 outlineGrowth;
        f32 t;
        f32 u;
        if ((s16)(*(s16 *)(work + 0xC) - 2) < 2) {
            t = (f32)(s16)(*(s16 *)(work + 0xC) - 2) / 2.0f;
            completeProgress = 1.0f;
            if (t > completeProgress) {
                u = completeProgress;
            } else if (t < 0.0f) {
                u = 0.0f;
            } else {
                u = t;
            }
            outlineGrowth = u * 2.0f - u * u;
        } else {
            completeProgress = 1.0f;
            outlineGrowth = completeProgress;
        }
        circle.center.x = 96.0f + translationX;
        position.x = circle.center.x;
        circle.center.y = 318.0f + offsetY;
        position.y = circle.center.y;
        color.bytes.c0 = 0x1B;
        color.bytes.c1 = 0x1B;
        color.bytes.c2 = 0x1B;
        color.bytes.c3 = 0xFF;
        func_00365f00(position, 150.0f, color.word, color.word, outlineGrowth * 81.0f, 0.0f, 0x30, 1.0f, 1.0f, 1);
    }
    if (*(s16 *)(work + 0xC) < 2) {
        f32 t;
        f32 u;
        t = (f32)*(s16 *)(work + 0xC) / 2.0f;
        if (t > completeProgress) {
            u = completeProgress;
        } else if (t < 0.0f) {
            u = 0.0f;
        } else {
            u = t;
        }
        circle.progress = u * 2.0f - u * u;
    } else {
        circle.progress = completeProgress;
    }
    position.x = circle.center.x;
    position.y = circle.center.y;
    color.bytes.c0 = 0xFE;
    color.bytes.c1 = 0xFF;
    color.bytes.c2 = 0x22;
    color.bytes.c3 = 0xFF;
    {
        f32 radius;
        radius = circle.progress * 78.0f;
        func_00365f00(position, 150.0f, color.word, color.word, radius, 0.0f, 0x30, 1.0f, 1.0f, 1);
        color.bytes.c3 = 0;
        func_00365f00(position, 150.0f, color.word, color.word, radius + 1.0f, 0.0f, 0x30, 1.0f, 1.0f, 1);
    }
    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(8, 0);
    renderer->setState(6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    if (showCommands != 0) {
        f32 t;
        u8 drawOpacity;
        t = (f32)*(s16 *)(work + 0xE) / 2.0f;
        if (t > completeProgress) {
            circle.progress = completeProgress;
        } else if (t < 0.0f) {
            circle.progress = 0.0f;
        } else {
            circle.progress = t;
        }
        opacity = (u8)(255.0f * circle.progress);
        drawOpacity = (u8)opacity;
        if (drawOpacity != 0) {
            f32 rowY;
            rowY = 259.0f;
            command = 0;
            row = 0;
            for (; row < 8; row++, command++) {
                u8 tone;
                available = func_001f0620(*(u8 **)(work + 0x178), D_00626BD0[command]);
                if (available != 0 && (command != 6 || *(s16 *)(work + 0x5A6) > 0)) {
                    tone = 0x1B;
                } else {
                    tone = 0x96;
                }
                func_0044b310(func_0044dcd8((f32)*(s16 *)(work + 0x14) / 3.0f));
                btlUiDrawSpriteFaded(glyphs, 9, command + 8, 52.0f, rowY - completeProgress, tone, tone, tone, drawOpacity);
                rowY += 15.0f;
            }
            selectedCommand = *(s16 *)(selection + 4);
            renderer = (BattleRenderDispatch *)D_00887300;
            renderer->setState(6, 1);
            btlPanelDrawStrip(3, translationX, ((f32)selectedCommand - 3.0f) * 15.0f + offsetY, 110.0f, 0.0f, 0);
            renderer->setState(6, 0);
            if ((u8)opacity == 0xFF) {
                u8 c1;
                u8 c2;
                u8 c3;
                available = func_001f0620(*(u8 **)(work + 0x178), D_00626BD0[selectedCommand]);
                if (available != 0 && (selectedCommand != 6 || *(s16 *)(work + 0x5A6) > 0)) {
                    c1 = 0xFE;
                    c2 = 0xFF;
                    c3 = 0x22;
                } else {
                    c1 = 0x62;
                    c2 = 0x62;
                    c3 = 0x62;
                }
                btlUiDrawSpriteFaded(glyphs, 9, selectedCommand, 33.0f, (f32)selectedCommand * 15.0f + 258.0f, c1, c2, c3, 0xFF);
                btlUiDrawSpriteEntry(glyphs, 9, selectedCommand + 0x10, 196.0f - translationX, ((f32)0x19B - offsetY) - completeProgress);
            }
        } else {
            renderer = (BattleRenderDispatch *)D_00887300;
            renderer->setState(6, 1);
            btlPanelDrawStrip(3, translationX, offsetY, 110.0f, (completeProgress - circle.progress) * 45.0f, 0);
            renderer->setState(6, 0);
        }
        if (circle.progress >= completeProgress && menuFlags == 0 && func_001eb860() != 0) {
            btlUiDrawSpriteFaded(glyphs, 9, 0x18, 110.0f, 383.0f, 0x1B, 0x1B, 0x1B, 0xFF);
            btlUiDrawSpriteEntry(glyphs, 9, 0x1C, 110.0f, 383.0f);
            btlUiDrawSpriteFaded(glyphs, 9, 0x1A, 129.0f, 383.0f, 0x1B, 0x1B, 0x1B, 0xFF);
            btlUiDrawSpriteEntry(glyphs, 9, 0x19, 129.0f, 383.0f);
        }
    } else {
        BattleRenderDispatch *modeRenderer;
        /* This phase acquires the table independently of earlier circle draws. */
        modeRenderer = (BattleRenderDispatch *)D_00887300;
        battleMenuExtendedStrip(modeRenderer, translationX, offsetY, rotationProgress);
        if (menuFlags == 0) {
            s32 showHints;
            if (*(u16 *)work == 2 && *(u16 *)(*(u8 **)(work + 0x178) + 0x6C) == 10) {
                selectedCommand = 0;
            } else {
                selectedCommand = *(s16 *)(selection + 4);
            }
            switch (selectedCommand) {
            case 3:
                btlUiSetOrigin(glyphs, origin[0], origin[1]);
                btlUiDrawSpriteFaded(glyphs, 9, 0x20, 75.0f, 317.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                renderer = (BattleRenderDispatch *)D_00887300;
                renderer->setState(6, 1);
                btlUiSetAlpha(glyphs, 120.0f);
                btlUiDrawSpriteFaded(glyphs, 9, 0x36, 8.0f, 297.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                renderer->setState(6, 0);
                btlUiSetAlpha(glyphs, 0.0f);
                btlUiSetOrigin(glyphs, origin[0] + translationX, origin[1] + offsetY);
                showHints = 1;
                break;
            case 0:
                btlUiSetOrigin(glyphs, origin[0], origin[1]);
                btlUiDrawSpriteFaded(glyphs, 9, 0x1E, 75.0f, 317.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                renderer = (BattleRenderDispatch *)D_00887300;
                renderer->setState(6, 1);
                btlUiSetAlpha(glyphs, 120.0f);
                btlUiDrawSpriteFaded(glyphs, 9, 0x34, 8.0f, 297.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                renderer->setState(6, 0);
                btlUiSetOrigin(glyphs, origin[0] + translationX, origin[1] + offsetY);
                showHints = 1;
                break;
            default:
                showHints = 0;
            }
            if (showHints != 0) {
                btlUiDrawSpriteEntry(glyphs, 9, 0x32, 215.0f - translationX, 412.0f - offsetY);
                btlUiDrawSpriteEntry(glyphs, 9, 0x33, 193.0f - translationX, 412.0f - offsetY);
                btlUiDrawSpriteEntry(glyphs, 9, 0x33, 413.0f - translationX, 412.0f - offsetY);
                if (circle.progress >= completeProgress && menuFlags == 0 && func_001eb860() != 0) {
                    btlUiDrawSpriteFaded(glyphs, 9, 0x18, 110.0f, 383.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                    btlUiDrawSpriteEntry(glyphs, 9, 0x1C, 110.0f, 383.0f);
                    btlUiDrawSpriteFaded(glyphs, 9, 0x1A, 129.0f, 383.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                    btlUiDrawSpriteEntry(glyphs, 9, 0x19, 129.0f, 383.0f);
                }
            }
        }
    }
    available = *(s16 *)(work + 0x14);
    if (available > 0) {
        *(s16 *)(work + 0x14) = available - 1;
        return;
    }
    if (available < 0) {
        *(s16 *)(work + 0x14) = available + 1;
    }
}

/* measured: the float argument to func_0045d6e0 is 0.0f - retail only ever clears
   $f12, and that hoisted zero is also the `<= 0.0f` compare operand and the
   accumulator seed of the adda.s/madd.s (the old archive passed temp_f4, nd10). */
// Intent: draw the selection's progress bar, scaled by the eased progress. [inferred]
// FUN_00208870
void btlSelectionDrawBar(u8 *unused, u8 *arg1, f32 *arg2)
{
    s32 values[4];
    Color4 color;
    f32 temp_f0;
    f32 temp_f1;
    f32 temp_f3;
    f32 temp_f4;

    btlUiSetOrigin((u8 *)kwlnTaskGetWork(*(void **)(arg1 + 0x5B0)), arg2[0], arg2[1]);
    temp_f0 = (f32)*(s16 *)(arg1 + 0xE) / 2.0f;
    if (temp_f0 > 1.0f) {
        temp_f1 = 1.0f;
    } else if (temp_f0 < 0.0f) {
        temp_f1 = 0.0f;
    } else {
        temp_f1 = temp_f0;
    }
    temp_f3 = temp_f1 * 2.0f - temp_f1 * temp_f1;
    if (temp_f3 <= 0.0f) {
        return;
    }
    color.c0 = 0xB4;
    color.c1 = 0;
    color.c2 = 0;
    color.c3 = 0xFF;
    values[0] = -10;
    temp_f4 = (1.0f - temp_f3) * 11.0f + 410.0f;
    values[1] = (s32)temp_f4;
    values[2] = 0x294;
    values[3] = (s32)(temp_f3 * 22.0f);
    func_0045d6e0((u8 *)&color, (f32 *)values, 0.0f, 0);
}

// Intent: save the selected row and page to the cursor record when the flag is set. [inferred]
// FUN_002089E0
void btlSelectionSaveCursor(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (datGetFlag(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[1] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[0] = *(s16 *)(arg0 + 2);
}

// Intent: reset the selection flags and cursor state to the top of the list. [inferred]
// FUN_00208A50
void btlSelectionResetState(u8 *arg0, u8 *arg1)
{
    u8 *p;

    func_0045af60(0, 0, 0, 3);
    if (datGetFlag(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            btlSelectionUpdateWindow(arg0, *(s16 *)(p + 6), *(s16 *)(p + 4));
        }
    }
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}

/* 500/512 bytes; twelve zero alignment bytes.
 * The shared four-byte record type preserves the flags-table load order. */
// Intent: handle the skill list input and return the next state (confirm, cancel or toggle). [inferred]
// FUN_00208B00
u16 btlSelectionHandleSkillInput(u8 *arg0, u8 *arg1)
{
    extern s32 datCalcThresholdTrigger(u8 *arg0, s32 arg1);
    extern s32 func_0023df70(s32 arg0);
    s32 temp_2;
    u16 var_16;
    u16 temp_16;
    s32 idx2;

    var_16 = btlSelectionReadInput(arg0) & 0xFFFF;
    switch (var_16) {
    case 2:
        idx2 = (s32)*(s16 *)(arg0 + 4) * 2;
        temp_16 = *(u16 *)(idx2 + (u32)arg1 + 0x194);
        if (datCalcThresholdTrigger(*(u8 **)(*(u8 **)(*(u8 **)(arg1 + 0x178) +
                                           0x30) + 0xA64),
                          temp_16) == 0) {
            if ((func_0023df70(temp_16) != 0) &&
                ((iGpffffb3bc[temp_16 & 0xFFFF].flags & 0x8000) == 0)) {
                *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 1;
            } else {
                *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 2;
            }
            *(u16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) = temp_16;
            *(s16 *)(arg1 + 0x1A) = 0;
            var_16 = 4;
        } else {
            func_0045af60(0, 15, 0, 8);
            var_16 = 1;
        }
        break;
    case 3:
        temp_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2;
        if ((temp_2 & 4) != 0) {
            func_0045af60(1, 13, 2, 23);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            func_0045af60(0, 0, 0, 2);
            *(s32 *)(arg1 + 4) &= ~4;
            var_16 = 1;
        } else {
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        }
        break;
    default:
        var_16 = 1;
        break;
    }
    return var_16;
}

/* 716/720 bytes; eighteen resolved relocations and four zero alignment bytes.
 * btlListDispatchUpdate forwards the signed state word at node+0x28. Convert that
 * real input to a pointer here; a pointer parameter swaps two entry moves. */
// Intent: draw the skill panel and advance its slide-in timer. [inferred]
// FUN_00208D00
void btlSelectionDrawSkillPanel(u8 *arg0, s32 arg1, f32 *arg2)
{
    u8 *state = (u8 *)arg1;
    u8 *temp;
    s16 temp_2;

    temp = (u8 *)kwlnTaskGetWork(*(void **)(state + 0x5B0));
    btlUiSetOrigin(temp, arg2[0], arg2[1]);
    if (*(u16 *)state == 2) {
        btlUiDrawSpriteFaded(temp, 9, 0x49, 77.0f, 314.0f, 0xFE, 0xFF, 0x22, 0xFF);
        btlUiDrawSpriteFaded(temp, 9, 0x4A, 93.0f, 314.0f, 0x1B, 0x1B, 0x1B, 0xFF);
        btlSelectionDrawSlideIn(state, arg0, arg2[0], arg2[1], btlPanelDrawSkillEntry);
    } else {
        btlUiDrawSpriteFaded(temp, 9, 0x21, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    btlUiSetAlpha(temp, 120.0f);
    btlUiDrawSpriteFaded(temp, 9, 0x37, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    btlUiSetAlpha(temp, 0.0f);
    temp_2 = *(s16 *)(state + 0x1A);
    if (temp_2 < 4) {
        *(s16 *)(state + 0x1A) = temp_2 + 1;
    }
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: advance the selection's animation counters, clamped to their limits. [inferred]
// FUN_00208FD0
void btlSelectionStepAnim(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)(arg1 + 2) != 2) {
        btlSelectionDrawList(arg1, arg0, arg2[0], arg2[1], btlPanelDrawSkillEntry);
    }
    temp_3 = *(s16 *)(arg1 + 0x20);
    if (temp_3 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x22);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_3_3 = *(s16 *)(arg1 + 0x16);
        if (temp_3_3 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
        }
        temp_3_4 = *(s16 *)(arg1 + 0x18);
        if (temp_3_4 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
        }
    } else {
        temp_3_5 = *(s16 *)(arg1 + 0x16);
        if (temp_3_5 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
        }
        temp_3_6 = *(s16 *)(arg1 + 0x18);
        if (temp_3_6 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
        }
    }
}

// Intent: save the selected row and page to the second cursor slot when the flag is set. [inferred]
// FUN_002090D0
void btlSelectionSaveCursorSecond(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (datGetFlag(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[3] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[2] = *(s16 *)(arg0 + 2);
}

// Intent: reset the selection flags, page window and counters for the list. [inferred]
// FUN_00209140
void btlSelectionResetPageState(u8 *arg0, u8 *arg1)
{
    u8 *p;

    func_0045af60(0, 0, 0, 3);
    if (datGetFlag(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            btlSelectionUpdateWindow(arg0, *(s16 *)(p + 0xA), *(s16 *)(p + 8));
        }
    }
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}

/* Reconstructed state dispatch and return width; candidate is byte-exact. */
// Intent: handle the item list input and return the next state. [inferred]
// FUN_002091F0
u16 btlSelectionHandleItemInput(u8 *arg0, u8 *arg1)
{
    s32 temp_2;
    u16 value;

    value = btlSelectionReadInput(arg0) & 0xFFFF;
    switch (value) {
    case 2:
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 3;
        temp_2 = *(s16 *)(p4_002091f0_add((u32)(*(s16 *)(arg0 + 4) * 4), arg1) + 0x1A6);
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x70) = temp_2;
        *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6E) =
            datCalcUnderlyingSkillId(*(u16 *)(*(u8 **)(arg1 + 0x178) + 0x70));
        *(s16 *)(arg1 + 0x1A) = 0;
        value = 4;
        break;
    case 3:
        temp_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2;
        if ((temp_2 & 4) != 0) {
            func_0045af60(1, 0xD, 2, 0x17);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            func_0045af60(0, 0, 0, 2);
            *(s32 *)(arg1 + 4) &= ~4;
            value = 1;
        } else {
            func_0045af60(0, 0, 0, 4);
            value = 2;
        }
        break;
    default:
        value = 1;
        break;
    }
    return value;
}

/* 716/720 bytes; eighteen resolved relocations and four zero alignment bytes.
 * btlListDispatchUpdate forwards the signed state word at node+0x28. Convert that
 * input locally; preserve the position and callback-table reloads. */
// Intent: draw the item panel and advance its slide-in timer. [inferred]
// FUN_00209370
void btlSelectionDrawItemPanel(u8 *arg0, s32 arg1, f32 *arg2)
{
    u8 *state = (u8 *)arg1;
    u8 *temp;
    s16 temp_2;

    temp = (u8 *)kwlnTaskGetWork(*(void **)(state + 0x5B0));
    btlUiSetOrigin(temp, arg2[0], arg2[1]);
    if (*(u16 *)state == 2) {
        btlUiDrawSpriteFaded(temp, 9, 0x49, 77.0f, 314.0f, 0xFE, 0xFF, 0x22, 0xFF);
        btlUiDrawSpriteFaded(temp, 9, 0x4A, 93.0f, 314.0f, 0x1B, 0x1B, 0x1B, 0xFF);
        btlSelectionDrawSlideIn(state, arg0, arg2[0], arg2[1], btlPanelDrawEntry);
    } else {
        btlUiDrawSpriteFaded(temp, 9, 0x23, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    btlUiSetAlpha(temp, 120.0f);
    btlUiDrawSpriteFaded(temp, 9, 0x39, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    btlUiSetAlpha(temp, 0.0f);
    temp_2 = *(s16 *)(state + 0x1A);
    if (temp_2 < 4) {
        *(s16 *)(state + 0x1A) = temp_2 + 1;
    }
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: advance the item list animation counters, clamped to their limits. [inferred]
// FUN_00209640
void btlSelectionStepItemAnim(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)(arg1 + 2) != 2) {
        btlSelectionDrawList(arg1, arg0, arg2[0], arg2[1],
                      btlPanelDrawEntry);
        temp_3 = *(s16 *)(arg1 + 0x20);
        if (temp_3 < 4) {
            *(s16 *)(arg1 + 0x20) = temp_3 + 1;
        }
        temp_3_2 = *(s16 *)(arg1 + 0x22);
        if (temp_3_2 < 0xA) {
            *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            temp_3_3 = *(s16 *)(arg1 + 0x16);
            if (temp_3_3 < 4) {
                *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
            }
            temp_3_4 = *(s16 *)(arg1 + 0x18);
            if (temp_3_4 < 7) {
                *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
            }
        } else {
            temp_3_5 = *(s16 *)(arg1 + 0x16);
            if (temp_3_5 > 0) {
                *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
            }
            temp_3_6 = *(s16 *)(arg1 + 0x18);
            if (temp_3_6 > 0) {
                *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
            }
        }
    }
}

// Intent: save the selected row and page to the third cursor slot when the flag is set. [inferred]
// FUN_00209740
void btlSelectionSaveCursorThird(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (datGetFlag(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[5] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[4] = *(s16 *)(arg0 + 2);
}

// Intent: reset the sub-list window and counters when the sub-list is not active. [inferred]
// FUN_002097B0
void btlSelectionResetSubListState(u8 *arg0, u8 *arg1)
{
    u8 *p;

    if (datGetFlag(0x3C) != 0) {
        p = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x3F0);
        if (p != NULL) {
            btlSelectionUpdateWindow(arg0, *(s16 *)(p + 0xE), *(s16 *)(p + 0xC));
        }
    }
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    if (*(s32 *)(arg1 + 0x3C) != (s32)(arg1 + 0x110)) {
        func_0045af60(0, 0, 0, 3);
        *(s16 *)(arg1 + 0x20) = 0;
        *(s16 *)(arg1 + 0x22) = 0;
        *(s16 *)(arg1 + 0x16) = 0;
        *(s16 *)(arg1 + 0x18) = 0;
    }
}

// Intent: handle the persona sub-list input and open the sub-list selection. [inferred]
// FUN_00209870
u16 btlSelectionOpenSubList(u8 *arg0, s32 arg1, u8 **arg2)
{
    u16 temp_4;
    u16 var_2;
    u16 result;
    u8 **out;
    u8 *base;
    u8 *temp_2;
    u8 *temp_4_2;

    out = (u8 **)arg2;
    base = (u8 *)(u32)arg1;
    temp_4 = btlSelectionReadInput(arg0) & 0xFFFF;
    switch (temp_4) {
    case 2:
        temp_2 = *(u8 **)(p4_002091f0_add(
            (u32)(*(s16 *)(arg0 + 4) * 4), base) + 0x17C);
        *(u8 **)(base + 0x190) = temp_2;
        if ((func_00107ac0(cmmCommunityForArcana(*(s16 *)(temp_2 + 0xA4)) &
                           0xFFFF) & 0xFFFF) >= 0) {
            var_2 = 5;
        } else {
            var_2 = 4;
        }
        btlSelectionInit(base + 0x110, 4, (s16)var_2,
                      (void *)btlSelectionResetSubList, (void *)btlSelectionConfirmSubList,
                      (void *)func_00209f90, (void *)func_0020a5c0, base);
        temp_4_2 = base + 0x110;
        *out = temp_4_2;
        btlSelectionSetOwner(temp_4_2, (void *)btlSelectionDrawCurrentLabel);
        *(s32 *)(base + 4) &= ~4;
        return 3;
    case 1:
        func_0045af60(0, 0, 0, 4);
        result = 2;
        goto done;
    default:
        result = 1;
        goto done;
    }
done:
    return result;
}

// Intent: draw the title strip for the selection sub-list and advance its timers. [inferred]
// FUN_002099C0
void btlSelectionDrawTitle(u8 *arg0, u8 *arg1, f32 *arg2)
{
    u8 *temp;

    temp = (u8 *)kwlnTaskGetWork(*(void **)(arg1 + 0x5B0));
    btlUiSetOrigin(temp, arg2[0], arg2[1]);
    btlUiDrawSpriteFaded(temp, 9, 0x1F, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    btlUiSetAlpha(temp, 120.0f);
    btlUiDrawSpriteFaded(temp, 9, 0x35, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    btlUiSetAlpha(temp, 0.0f);
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: draw the persona name list when the sub-list is open, and step its counters. [inferred]
// FUN_00209BC0
void btlSelectionDrawPersonaList(u8 *arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u8 **)(arg1 + 0x38) == arg1 + 0xDC) {
        if (*(u16 *)arg1 != 2) {
            btlSelectionDrawList(arg1, arg0, arg2[0], arg2[1],
                          btlPanelDrawPersonaName);
        }
        temp_3 = *(s16 *)(arg1 + 0x20);
        if (temp_3 < 4) {
            *(s16 *)(arg1 + 0x20) = temp_3 + 1;
        }
        temp_3_2 = *(s16 *)(arg1 + 0x22);
        if (temp_3_2 < 0xA) {
            *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
        }
        if ((*(s32 *)(arg1 + 4) & 4) != 0) {
            temp_3_3 = *(s16 *)(arg1 + 0x16);
            if (temp_3_3 < 4) {
                *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
            }
            temp_3_4 = *(s16 *)(arg1 + 0x18);
            if (temp_3_4 < 7) {
                *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
            }
        } else {
            temp_3_5 = *(s16 *)(arg1 + 0x16);
            if (temp_3_5 > 0) {
                *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
            }
            temp_3_6 = *(s16 *)(arg1 + 0x18);
            if (temp_3_6 > 0) {
                *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
            }
        }
    }
}

// Intent: save the selected row and page to the fourth cursor slot when the flag is set. [inferred]
// FUN_00209CD0
void btlSelectionSaveCursorFourth(u8 *arg0, u8 *arg1)
{
    s16 *p;

    if (datGetFlag(60) == 0) {
        return;
    }
    p = *(s16 **)(*(u8 **)(arg1 + 376) + 1008);
    if (p == NULL) {
        return;
    }
    p[7] = *(s16 *)(arg0 + 4);
    (*(s16 **)(*(u8 **)(arg1 + 376) + 1008))[6] = *(s16 *)(arg0 + 2);
}

// Intent: reset the sub-list cursor fields and window. [inferred]
// FUN_00209D40
void btlSelectionResetSubList(u8 *arg0, u8 *arg1)
{
    func_0045af60(0, 0, 0, 3);
    btlSelectionUpdateWindow(arg0, 0, 0);
    *(u16 *)arg0 |= 1;
    *(u16 *)arg0 |= 2;
    *(s16 *)(arg1 + 0x1C) = 0;
    *(s16 *)(arg1 + 0x1E) = 0;
}

// Intent: handle the sub-list input, store the chosen value and enqueue its packet. [inferred]
// FUN_00209DC0
u16 btlSelectionConfirmSubList(u8 *arg0, u8 *arg1)
{
    extern s16 func_00105f00(s16 arg0);
    extern void func_00105e30(s16 arg0, s16 arg1);
    extern u8 *func_001b0c80(s32 arg0);
    extern u8 *func_001f99c0(u8 *arg0, u16 arg1, s32 arg2, s32 arg3,
                              s32 arg4);
    extern s64 btlPacketEnqueue(u8 *arg0, u32 arg1);
    s16 temp_16;
    u8 *temp_2;
    s32 temp_2_2;
    s32 temp_3;
    u16 var_16;

    var_16 = btlSelectionReadInput(arg0) & 0xFFFF;
    switch (var_16) {
    case 2:
        temp_16 = *(s16 *)(arg0 + 4);
        if (temp_16 !=
            func_00105f00(*(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4))) {
            func_00105e30(
                *(s16 *)(*(u8 **)(arg1 + 0x190) + 0xA4), temp_16);
            temp_2 = func_001b0c80(*(s32 *)(arg1 + 0x190));
            if (temp_2 != NULL) {
                btlPacketEnqueue(
                    func_001f99c0(temp_2, 2, *(s16 *)(arg0 + 4), 0, 0), 1);
            }
        }
        *(s32 *)(arg1 + 4) &= ~4;
        *(s16 *)(arg1 + 0x16) = 0;
        *(s16 *)(arg1 + 0x18) = 0;
        func_0045af60(0, 15, 0, 1);
        var_16 = 2;
        break;
    case 1:
        temp_3 = *(s32 *)(arg1 + 4);
        if ((temp_3 & 4) != 0) {
            *(s32 *)(arg1 + 4) = temp_3 & ~4;
            var_16 = 1 & 0xFFFF;
        } else {
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        }
        break;
    case 3:
        temp_2_2 = *(s32 *)(arg1 + 4) ^ 4;
        *(s32 *)(arg1 + 4) = temp_2_2;
        if ((temp_2_2 & 4) != 0) {
            func_0045af60(1, 13, 2, 23);
        } else {
            func_0045af60(0, 0, 0, 2);
        }
        break;
    default:
        var_16 = 1 & 0xFFFF;
        break;
    }
    return var_16;
}

// FUN_00209F90
void func_00209f90(void)
{
}

// Intent: draw the current character label and advance its bounded panel timers. [inferred]
// FUN_00209FA0
void btlSelectionDrawCurrentLabel(u8 *selection, s32 workAddress, u8 *drawState)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern s16 func_00105f00(s16 selection);
    extern u32 func_0010d6d0(s16 selection);
    extern s32 frFontNodeWidth(struct FrFontNode *node);
    extern void frFontMoveListTo(s32 node, s32 x, s32 y);
    extern s32 frFontListKeepOrRelease(s32 node);
    BattleRenderDispatch *renderer;
    s32 rect[4];
    Color4 color;
    f32 *origin;
    u8 *work;
    u8 *glyphs;
    u8 *font;
    f32 remaining;
    f32 rowOffset;
    u8 alpha;
    s32 nameX16;
    s32 nameWidth;
    u32 nameAddress;
    s32 iconFrame;
    origin = (f32 *)drawState;
    work = (u8 *)(u32)workAddress;
    glyphs = (u8 *)kwlnTaskGetWork(*(void **)(work + 0x5B0));
    btlUiSetOrigin(glyphs, origin[0], origin[1]);
    if (*(u16 *)work != 2) {
        btlSelectionDrawList(work, selection, origin[0], origin[1], btlPanelDrawListRow);
    }
    {
        s16 frame20;
        s16 frame22;
        s16 openingFrame16;
        s16 openingFrame18;
        s16 closingFrame16;
        s16 closingFrame18;
        frame20 = *(s16 *)(work + 0x20);
        if (frame20 < 4) {
            *(s16 *)(work + 0x20) = frame20 + 1;
        }
        frame22 = *(s16 *)(work + 0x22);
        if (frame22 < 0xA) {
            *(s16 *)(work + 0x22) = frame22 + 1;
        }
        if ((*(s32 *)(work + 4) & 4) != 0) {
            openingFrame16 = *(s16 *)(work + 0x16);
            if (openingFrame16 < 4) {
                *(s16 *)(work + 0x16) = openingFrame16 + 1;
            }
            openingFrame18 = *(s16 *)(work + 0x18);
            if (openingFrame18 < 7) {
                *(s16 *)(work + 0x18) = openingFrame18 + 1;
            }
        } else {
            closingFrame16 = *(s16 *)(work + 0x16);
            if (closingFrame16 > 0) {
                *(s16 *)(work + 0x16) = closingFrame16 - 1;
            }
            closingFrame18 = *(s16 *)(work + 0x18);
            if (closingFrame18 > 0) {
                *(s16 *)(work + 0x18) = closingFrame18 - 1;
            }
        }
    }
    {
        f32 clamped;
        f32 progress;
        progress = (f32)*(s16 *)(work + 0x1C) / 5.0f;
        if (progress > 1.0f) {
            clamped = 1.0f;
        } else if (progress < 0.0f) {
            clamped = 0.0f;
        } else {
            clamped = progress;
        }
        remaining = 1.0f - (2.0f * clamped - clamped * clamped);
    }
    rowOffset = 36.0f * remaining;
    btlUiDrawSpriteFaded(glyphs, 9, 0x4E, 491.0f, 324.0f + rowOffset, 0xFE, 0xFF, 0x22, 0xFF);
    if (remaining > 0.0f) {
        renderer = (BattleRenderDispatch *)D_00887300;
        renderer->setState(1, 0);
        renderer->setState(8, 1);
        color.c0 = 0;
        color.c1 = 0;
        color.c2 = 0xFF;
        color.c3 = 0;
        rect[0] = 0x64;
        {
            f32 row;
            f32 top;
            row = 330.0f + rowOffset;
            top = row - 40.0f;
            rect[1] = (s32)top;
        }
        rect[2] = 0x1A4;
        rect[3] = 0x28;
        func_0045d6e0((u8 *)&color, (f32 *)rect, 0.0f, 0);
        renderer->setState(8, 0);
    }
    renderer = (BattleRenderDispatch *)D_00887300;
    renderer->setState(6, 1);
    btlUiSetAlpha(glyphs, 50.0f);
    btlUiDrawSpriteFaded(glyphs, 9, 0x3B, 493.0f, 330.0f, 0x1B, 0x1B, 0x1B, 0xFF);
    iconFrame = (s16)func_00105f00(*(s16 *)(*(u8 **)(work + 0x190) + 0xA4)) + 0x3F;
    btlUiDrawSpriteFaded(glyphs, 9, iconFrame, 168.0f, 334.0f, 0xFE, 0xFF, 0x22, 0xFF);
    frFontSetFlagBits(0x40);
    nameAddress = func_0010d6d0(*(s16 *)(*(u8 **)(work + 0x190) + 0xA4));
    font = (u8 *)(u32)frFontExCreateText(357.0f, 332.0f, 50.0f, -1, 0, 1, (const char *)nameAddress, 0, NULL);
    nameWidth = frFontNodeWidth((struct FrFontNode *)font);
    {
        f32 center;
        f32 widthSpace;
        f32 halfSpace;
        widthSpace = 138.0f - (f32)nameWidth;
        halfSpace = 0.5f * widthSpace;
        center = 357.0f + halfSpace;
        widthSpace = 16.0f * center;
        nameX16 = (s32)widthSpace;
    }
    frFontMoveListTo((s32)(u32)font, nameX16, 0xA60);
    frFontDrawList(font, 1, 0);
    frFontListKeepOrRelease((s32)(u32)font);
    frFontClearFlagBits(0x40);
    renderer->setState(6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    {
        f32 clamped;
        f32 progress;
        f32 eased;
        f32 remainingFraction;
        f32 visibleFraction;
        progress = (f32)*(s16 *)(work + 0x1E) / 10.0f;
        if (progress > 1.0f) {
            clamped = 1.0f;
        } else if (progress < 0.0f) {
            clamped = 0.0f;
        } else {
            clamped = progress;
        }
        eased = 2.0f * clamped - clamped * clamped;
        remainingFraction = 1.0f - eased;
        visibleFraction = 1.0f - remainingFraction;
        alpha = (u8)(255.0f * visibleFraction);
        btlUiDrawSpriteFaded(glyphs, 9, 0x44, 402.0f - 150.0f * remainingFraction, 308.0f, 0xFE, 0xFF, 0x22, alpha);
    }
    {
        s16 frame1c;
        s16 frame1e;
        frame1c = *(s16 *)(work + 0x1C);
        if (frame1c < 5) {
            *(s16 *)(work + 0x1C) = frame1c + 1;
        }
        frame1e = *(s16 *)(work + 0x1E);
        if (frame1e < 0xA) {
            *(s16 *)(work + 0x1E) = frame1e + 1;
        }
    }
}

// FUN_0020A5C0
void func_0020a5c0(void)
{
}

// Intent: reset the selection flags and window fields for the cursor state. [inferred]
// FUN_0020A5D0
void btlSelectionResetCursorState(u16 *arg0, u8 *arg1) {
    func_0045af60(0, 0, 0, 3);
    *arg0 |= 1;
    *arg0 |= 2;
    *(s16 *)(arg1 + 0x20) = 0;
    *(s16 *)(arg1 + 0x22) = 0;
    *(s16 *)(arg1 + 0x16) = 0;
    *(s16 *)(arg1 + 0x18) = 0;
}

// Intent: handle the swap input for the persona roster and start or finish the swap task. [inferred]
// FUN_0020A640
/* measured: 1064/1072 bytes; 35 independently resolved relocations and eight
   zero alignment bytes. Separate stats/task snapshots preserve the retail
   argument-load order without narrowing the persona lookup return type. */
u16 btlSelectionHandleSwapInput(u8 *arg0, u8 *arg1)
{
    s16 sp48[4];
    s16 temp_16;
    u8 *temp_2;
    u16 var_16;
    u8 *stats;
    u8 *task;

    var_16 = (u16)(btlSelectionReadInput(arg0) & 0xFFFF);
    switch (var_16) {
    case 2:
        temp_16 = *(s16 *)(arg0 + 4);
        if (temp_16 != (s16)datPersonaGetLeadSlot()) {
            temp_2 = datPersonaRosterSlot(temp_16);
            *(s16 *)(*(u8 **)(arg1 + 0x178) + 0x6C) = 5;
            *(u16 *)(*(u8 **)(arg1 + 0x178) + 0x74) = *(u16 *)((u8 *)temp_2 + 2);
            func_0011b360(*(u8 **)(arg1 + 0x5A8));
            *(u8 **)(arg1 + 0x5A8) = NULL;
            *(s16 *)(arg1 + 0x5AC) = -1;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
            func_00213c70(*(u8 **)(arg1 + 0x5B0));
            var_16 = 4;
        } else {
            func_0045af60(0, 15, 0, 8);
            var_16 = 1;
        }
        break;

    case 3:
        if (*(s16 *)(arg1 + 0x5AC) == -1) {
            if (func_0011ba00(*(u8 **)(arg1 + 0x5A8)) == 0) {
                temp_2 = datPersonaRosterSlot(*(s16 *)(arg0 + 4));
                *(s32 *)(iGpffffb3ac + 0xC) &= ~0x2000;
                *(s32 *)(iGpffffb3ac + 0xC) &= ~0x20000;
                stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                task = *(u8 **)(arg1 + 0x5A8);
                func_0011b480(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                func_0011bb90(*(u8 **)(arg1 + 0x5A8));
                func_00213ca0(*(u8 **)(arg1 + 0x5B0));
                memset(sp48, 0, 8);
                sp48[0] = 4;
                sp48[1] = 8;
                btlSelectionSetRepeat(arg0, sp48);
                *(u16 *)arg0 &= ~2;
                *(u16 *)arg0 &= ~1;
                *(u16 *)arg0 &= ~8;
                *(s16 *)(arg1 + 0x5AC) = *(s16 *)(arg0 + 4);
            }
        } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) == 0) {
            func_0011c630(*(u8 **)(arg1 + 0x5A8));
        } else {
            func_0011c6e0(*(u8 **)(arg1 + 0x5A8), 1);
        }
        break;

    case 1:
        if (*(s16 *)(arg1 + 0x5AC) == -1) {
            func_0011b360(*(u8 **)(arg1 + 0x5A8));
            *(u8 **)(arg1 + 0x5A8) = NULL;
            *(s16 *)(arg1 + 0x5AC) = -1;
            func_0045af60(0, 0, 0, 4);
            var_16 = 2;
        } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) == 0) {
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x2000;
            *(s32 *)(iGpffffb3ac + 0xC) |= 0x20000;
            func_0011bc70(*(u8 **)(arg1 + 0x5A8));
            *(s16 *)(arg1 + 0x5AC) = -1;
            btlSelectionSetRepeat(arg0, NULL);
            func_00213c70(*(u8 **)(arg1 + 0x5B0));
            *(u16 *)arg0 |= 2;
            *(u16 *)arg0 |= 1;
            *(u16 *)arg0 |= 8;
            func_0045af60(0, 0, 0, 4);
            var_16 = 1;
        } else {
            func_0011c6e0(*(u8 **)(arg1 + 0x5A8), 1);
        }
        break;

    default:
        if (*(s16 *)(arg1 + 0x5AC) != -1) {
            if (*(s16 *)(arg1 + 0x5AC) != *(s16 *)(arg0 + 4)) {
                temp_2 = datPersonaRosterSlot(*(s16 *)(arg0 + 4));
                if (var_16 == 5) {
                    stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                    task = *(u8 **)(arg1 + 0x5A8);
                    func_0011c180(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                } else {
                    stats = *(u8 **)(*(u8 **)(arg1 + 0x178) + 0x30);
                    task = *(u8 **)(arg1 + 0x5A8);
                    func_0011c2c0(task, *(u16 *)(stats + 0xA4), (u32)temp_2, 0);
                }
                *(s16 *)(arg1 + 0x5AC) = *(s16 *)(arg0 + 4);
            } else if (func_0011c610(*(u8 **)(arg1 + 0x5A8)) != 0) {
                func_0011caf0(*(u8 **)(arg1 + 0x5A8));
            }
        }
        var_16 = 1;
        break;
    }

    return var_16;
}

/* 508/512 bytes, 13 resolved relocations, four zero alignment bytes.
 * As in func_002099c0, reuse the consumed position view for the callback
 * table base; each state change still reloads the callback slot.
 */
// Intent: draw the swap panel and advance its slide-in timer. [inferred]
// FUN_0020AA70
void btlSelectionDrawSwapPanel(u8 *arg0, u8 *arg1, f32 *arg2)
{
    u8 *temp;

    temp = (u8 *)kwlnTaskGetWork(*(void **)(arg1 + 0x5B0));
    btlUiSetOrigin(temp, arg2[0], arg2[1]);
    btlUiDrawSpriteFaded(temp, 9, 0x22, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    arg2 = (f32 *)D_00887300;
    ((void (**)(u32, u32))arg2)[0](6, 1);
    btlUiSetAlpha(temp, 120.0f);
    btlUiDrawSpriteFaded(temp, 9, 0x38, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))arg2)[0](6, 0);
    btlUiSetAlpha(temp, 0.0f);
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(temp, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(temp, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(temp, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: draw the persona level list and advance its timers. [inferred]
// FUN_0020AC70
void btlSelectionDrawLevelList(s32 arg0, u8 *arg1, f32 *arg2)
{
    s16 temp_3;
    s16 temp_3_2;
    s16 temp_3_3;
    s16 temp_3_4;
    s16 temp_3_5;
    s16 temp_3_6;

    if (*(u16 *)arg1 != 2) {
        btlSelectionDrawList(arg1, (u8 *)arg0, arg2[0], arg2[1],
                      btlPanelDrawPersonaLevel);
    }
    temp_3 = *(s16 *)(arg1 + 0x20);
    if (temp_3 < 4) {
        *(s16 *)(arg1 + 0x20) = temp_3 + 1;
    }
    temp_3_2 = *(s16 *)(arg1 + 0x22);
    if (temp_3_2 < 0xA) {
        *(s16 *)(arg1 + 0x22) = temp_3_2 + 1;
    }
    if ((*(s32 *)(arg1 + 4) & 4) != 0) {
        temp_3_3 = *(s16 *)(arg1 + 0x16);
        if (temp_3_3 < 4) {
            *(s16 *)(arg1 + 0x16) = temp_3_3 + 1;
        }
        temp_3_4 = *(s16 *)(arg1 + 0x18);
        if (temp_3_4 < 7) {
            *(s16 *)(arg1 + 0x18) = temp_3_4 + 1;
        }
    } else {
        temp_3_5 = *(s16 *)(arg1 + 0x16);
        if (temp_3_5 > 0) {
            *(s16 *)(arg1 + 0x16) = temp_3_5 - 1;
        }
        temp_3_6 = *(s16 *)(arg1 + 0x18);
        if (temp_3_6 > 0) {
            *(s16 *)(arg1 + 0x18) = temp_3_6 - 1;
        }
    }
}

// FUN_0020AD70
void func_0020ad70(void)
{
}

// Intent: initialise a panel work block, clearing it and setting its task pointer. [inferred]
// FUN_0020AD80
void btlPanelInitWork(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x5B4);
    *(s32 *)(arg0 + 0x5B0) = arg1;
    *(s16 *)(arg0 + 0) = 0;
    *(s16 *)(arg0 + 0x5AC) = -1;
}

/*
 * measured: 968/976 bytes, 11 resolved relocations, eight zero alignment bytes.
 * Preserve the 4,5,0 source case order and all reloads after callbacks.
 */
// Intent: advance the panel's animation counters and low-HP pulse for one frame. [inferred]
// FUN_0020ADD0
void btlPanelUpdate(void *arg0)
{
    u8 *state = arg0;
    if (*(u32 *)(state + 4) & 1) {
        if (*(s16 *)(state + 0xA) < 11) ++*(s16 *)(state + 0xA);
    } else {
        if (*(s16 *)(state + 8) < 19) ++*(s16 *)(state + 8);
        if (*(s16 *)(state + 0xA) < 6) ++*(s16 *)(state + 0xA);
        else if (*(s16 *)(state + 0xA) > 6) --*(s16 *)(state + 0xA);
    }
    if (*(s16 *)(state + 0xC) < 4) ++*(s16 *)(state + 0xC);
    if (*(s16 *)(state + 0xE) < 2) ++*(s16 *)(state + 0xE);
    else if (!(*(u32 *)(state + 4) & 2)) {
        *(u32 *)(state + 4) |= 2;
        *(s16 *)(state + 0x10) = 0;
    }
    if (*(u16 *)state == 1 && *(s16 *)(state + 8) == 8) {
        func_0045af60(1, 15, 2, 26);
    }
    if (*(u8 **)(state + 0x38) == state + 0x40) {
        if (*(u16 *)state == 1) {
            if (*(s16 *)(state + 0x12) > 0) --*(s16 *)(state + 0x12);
        } else {
            if (*(s16 *)(state + 0x12) < 3) ++*(s16 *)(state + 0x12);
        }
    } else {
        if (!(*(u32 *)(state + 4) & 1)) {
            if (*(s16 *)(state + 0x12) < 3) ++*(s16 *)(state + 0x12);
            else if (*(s16 *)(state + 0x12) > 3) --*(s16 *)(state + 0x12);
        } else {
            if (*(s16 *)(state + 0x12) < 6) ++*(s16 *)(state + 0x12);
        }
    }
    *(u16 *)(state + 2) = *(u16 *)state;
    if (*(u16 *)state == 1 && !(*(u32 *)(iGpffffb3ac + 0xC) & 0x10000)) {
        switch (btlListStep(state + 0x2C) & 0xFFFF) {
        case 4: *(u16 *)state = 2; break;
        case 5: *(u16 *)state = 0; break;
        case 0: break;
        }
        if (*(u8 **)(state + 0x178) != 0 &&
            *(u8 **)(*(u8 **)(state + 0x178) + 0x30) != 0 &&
            *(u8 **)(*(u8 **)(*(u8 **)(state + 0x178) + 0x30) + 0xA64) != 0) {
            f32 pulse;
            if (datCalcIsLowHp(*(u8 **)(*(u8 **)(*(u8 **)(state + 0x178) + 0x30) + 0xA64))) {
                pulse = sinf(fGpffff8478 * fGpffffb478);
                fGpffffb478 += 2.0f;
                if (!(fGpffffb478 < 180.0f)) fGpffffb478 -= 180.0f;
            } else {
                pulse = 0.0f;
                fGpffffb478 = 0.0f;
            }
            state[0x24] = (u8)(150.0f * pulse) + 10;
            state[0x25] = 10;
            state[0x26] = 10;
            state[0x28] = (u8)(160.0f * pulse);
            state[0x29] = 0;
            state[0x2A] = 0;
        }
    }
}

// Intent: draw the panel frame, scaled outlines and the list dispatch when the panel is active. [inferred]
// FUN_0020B1A0
void btlPanelDrawFrame(s32 arg0, u8 *arg1)
{
    extern void btlPanelDrawOutlineFill(u8 *arg0, f32 fparg0, f32 fparg1,
                              u8 arg1, u8 arg2, u8 arg3, s32 arg4);
    u8 *temp_2;
    s16 temp_3;
    s16 temp_4;
    f32 temp_f12;
    f32 temp_f20;

    temp_2 = (u8 *)kwlnTaskGetWork(*(void **)(arg1 + 0x5B0));
    if ((*(s32 *)temp_2 & 1) != 0) {
        if (*(u16 *)arg1 != 0) {
            if (*(s16 *)(arg1 + 0x5AC) == -1) {
                btlUiSetRenderStates();
                temp_f12 = (f32)*(s16 *)(arg1 + 8) / 19.0f;
                if (temp_f12 < 1.0f) {
                    temp_f12 = (temp_f12 * 2.0f -
                                temp_f12 * temp_f12) *
                               1.5f;
                    btlPanelDrawOutlineFill(
                        temp_2, temp_f12, temp_f12,
                        *(u8 *)(arg1 + 0x24), *(u8 *)(arg1 + 0x25),
                        *(u8 *)(arg1 + 0x26), 0x4C);
                }
                temp_3 = *(s16 *)(arg1 + 0xA);
                if (temp_3 < 7) {
                    temp_f12 = (f32)(6 - temp_3) / 6.0f;
                    if (temp_f12 < 1.0f) {
                        temp_f20 = 1.0f -
                                   (temp_f12 * 2.0f -
                                    temp_f12 * temp_f12);
                    }
                } else {
                    temp_4 = temp_3 - 6;
                    temp_f12 = (f32)temp_4 / 5.0f;
                    if (temp_f12 < 1.0f) {
                        temp_f20 =
                            (temp_f12 * 2.0f -
                             temp_f12 * temp_f12) *
                                0.25f +
                            1.0f;
                    }
                }
                btlPanelDrawOutlineFill(
                    temp_2, temp_f20, temp_f20,
                    *(u8 *)(arg1 + 0x24), *(u8 *)(arg1 + 0x25),
                    *(u8 *)(arg1 + 0x26), 0xFF);
                btlListDispatchUpdate(arg1 + 0x2C);
            }
        }
    }
}

// Intent: draw the backdrop, the sprite grid and the notify dispatch when the panel is active. [inferred]
// FUN_0020B3A0
void btlPanelDrawBackdropGrid(s32 arg0, u8 *arg1)
{
    extern void btlPanelDrawSpriteGrid(u8 *arg0, f32 farg0, f32 farg1, u8 arg1);
    extern u8 D_00626BE0[];
    u8 *temp_2;
    s16 temp_3;
    s16 temp_4;
    f32 temp_f20;

    temp_2 = (u8 *)kwlnTaskGetWork(*(void **)(arg1 + 0x5B0));
    if ((*(s32 *)temp_2 & 1) != 0) {
        if (*(u16 *)arg1 != 0) {
            if (*(s16 *)(arg1 + 0x5AC) == -1) {
                btlUiSetRenderStates();
                temp_3 = *(s16 *)(arg1 + 0xA);
                if (temp_3 < 7) {
                    if (((f32)(6 - temp_3) / 6.0f) < 1.0f) {
                        temp_f20 = 1.0f -
                            ((f32)(6 - temp_3) / 6.0f * 2.0f -
                             (f32)(6 - temp_3) / 6.0f *
                                 ((f32)(6 - temp_3) / 6.0f));
                    }
                } else {
                    temp_4 = temp_3 - 6;
                    if (((f32)temp_4 / 5.0f) < 1.0f) {
                        temp_f20 =
                            ((f32)temp_4 / 5.0f * 2.0f -
                             (f32)temp_4 / 5.0f *
                                 ((f32)temp_4 / 5.0f)) *
                                0.25f +
                            1.0f;
                    }
                }
                btlPanelDrawBackdrop(temp_2, temp_f20, temp_f20);
                if (((*(s32 *)(arg1 + 4) & 2) != 0) &&
                    (*(u16 *)arg1 != 2) &&
                    (*(s16 *)(arg1 + 0xA) < 7)) {
                    btlPanelDrawSpriteGrid(temp_2, 1.0f, 1.0f,
                                  D_00626BE0[*(s16 *)(arg1 + 0x10)]);
                    if ((u32)(s16)(*(s16 *)(arg1 + 0x10) += 1) >= 0x14) {
                        *(s16 *)(arg1 + 0x10) = 0x13;
                    }
                }
                btlListDispatchNotify(arg1 + 0x2C);
            }
        }
    }
}

// FUN_0020B5A0
void func_0020b5a0(void)
{
}

/* measured: opt_propagation off keeps D_00887300 cached across its callback sequence. */
/* measured: btlPanelDrawSkyFrame MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: set the sky render states and draw the sky frame when the panel is active. [inferred]
// FUN_0020B5B0
void btlPanelDrawSkyFrame(s32 arg0, u8 *arg1)
{
    extern void func_0045c870(u8 *arg0, s32 arg1);
    u8 *temp_2;
    void (**base)(u32, u32);
    u8 work[4];

    temp_2 = (u8 *)kwlnTaskGetWork(*(void **)(arg1 + 0x5B0));
    if (((*(u32 *)temp_2 & 1) != 0) &&
        (*(u16 *)arg1 != 0) &&
        (*(s16 *)(arg1 + 0x5AC) == -1)) {
        RpSkyRenderStateSet(2, 0x44);
        RpSkyRenderStateSet(3, 0x717FB);
        base = D_00887300;
        base[0](0xE, 0);
        base[0](6, 0);
        base[0](8, 0);
        base[0](9, 2);
        base[0](0xC, 1);
        base[0](1, 0);
        work[0] = 0;
        work[1] = 0;
        work[2] = 0;
        work[3] = 0;
        func_0045c870(work, 0);
    }
}

/* measured: restore opt_propagation after func_0020b5b0. */
/* measured: btlSelectionMarkTargets, btlSelectionResetUnitFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: mark the targets for the selected skill, setting each unit's skill element and buff or ailment flags. [inferred]
// FUN_0020B6D0
extern u32 btlEffectCollectGenusMask(u8 *arg0);
extern u16 *datPersonaGetRecord(u16 arg0);
extern s32 datPersonaFindSkillSlot(u8 *arg0, u16 arg1);
extern u16 func_0010f8c0(s32 arg0);
extern s32 datCalcSkillElement(u8 *arg0, u16 arg1);
extern s32 datCalcElementBit(s16 arg0);
extern s8 datCalcGetBuffStatus(u8 *arg0, s32 arg1);
extern s32 datCalcAilmentChance(u8 *arg0, s32 arg1);
extern s32 func_001f0950(s32 arg0, s32 arg1);
extern void btlSelectionSetRowState(u8 *arg0, s16 arg1);
extern void btlSelectionSetRowIdle(u8 *arg0);

void btlSelectionMarkTargets(s32 arg0, u8 *arg1, u8 *arg2, s16 arg3)
{
    extern u32 kwlnTaskGetWork(void *task);
    u16 spD0;
    u32 spC0;
    u32 spB0;
    u32 spA0;
    u8 *temp_2_3;
    u8 *temp_2;
    s32 temp_2_2;
    s32 var_20;
    s32 var_23;
    s32 var_2;
    s32 var_30;
    u16 var_19;
    s32 temp_18;
    s32 temp_3;
    u16 temp_16;
    u8 *temp_16_2;
    u8 *temp_22;

    temp_2 = (u8 *)kwlnTaskGetWork((void *)arg0);
    temp_2_3 = temp_2 + 0x710;
    *(s32 *)(temp_2 + 0x718) = (s32)arg1;
    *(s32 *)(temp_2 + 0x71C) = 0;
    *(u8 **)(temp_2 + 0x720) = arg2;
    *(s16 *)(temp_2 + 0x724) = arg3;
    *(s16 *)(temp_2_3 + 4) = 1;
    *(u8 *)(arg2 + 0x3C) |= 1;
    if ((btlEffectCollectGenusMask(arg2) & 0xFFFF) == 1) {
        *(u16 *)temp_2_3 |= 2;
    } else {
        *(u16 *)temp_2_3 &= 0xFFFD;
    }
    switch (arg3) {
    case 0x110:
    case 0x10B:
        var_30 = 1;
        break;
    default:
        var_30 = 0;
        break;
    }
    var_23 = 0;
    if (arg3 >= 0) {
        if (datGetFlag(0x38) != 0) {
            var_2 = 5;
        } else {
            var_2 = 8;
        }
        if (datPersonaFindSkillSlot((u8 *)datPersonaGetRecord(var_2 & 0xFFFF), 0x10C) != -1) {
            var_23 = 1;
        }
    }
    spC0 = *(u16 *)(arg2 + 0x38);
    temp_16 = (u16)arg3;
    spB0 = func_0010f8c0(temp_16) & 0xFFFF;
    var_20 = 0;
    spD0 = temp_16 & 0xFFFF;
    goto loop_condition;
loop_body:
    temp_22 = *(u8 **)(arg2 + var_20 * 4);
    temp_16_2 = *(u8 **)(temp_22 + 0x30);
    if (var_30 != 0) {
        var_19 = 3;
    } else {
        var_19 = 0;
        temp_18 = (s16)datCalcSkillElement(*(u8 **)(temp_16_2 + 0xA64), spD0);
        temp_2_2 = datCalcElementBit((s64)(s16)temp_18);
        if (!(temp_2_2 & 0xE0001)) {
            if (temp_2_2 & 2) {
                if ((s8)datCalcGetBuffStatus(*(u8 **)(temp_16_2 + 0xA64), 0x10) > 0) {
                    var_19 = 1;
                }
            } else if (!(temp_2_2 & 0x40) &&
                       (s8)datCalcGetBuffStatus(*(u8 **)(temp_16_2 + 0xA64), 0x11) > 0) {
                var_19 = 1;
            }
        }
        if ((var_23 != 0) && !(var_19 & 0xFFFF)) {
            spA0 = datCalcAilmentChance(*(u8 **)(temp_16_2 + 0xA64), temp_18);
            var_2 = (u16)temp_18;
            temp_3 = *(u16 *)(temp_16_2 + 0xA4);
            if (func_001f0950(temp_3, var_2) != 0) {
                if ((spA0 & 0x02000000) != 0) {
                    var_19 = 1;
                } else if ((spA0 & 0x05000000) != 0) {
                    var_19 = 2;
                }
            }
        }
    }
    btlSelectionSetRowState(*(u8 **)(temp_22 + 0x30) + 0xA48, (s16)var_19);
    if (spB0 != 0) {
        btlSelectionSetRowIdle(*(u8 **)(temp_22 + 0x30) + 0xA48);
    }
    var_20 += 1;
loop_condition:
    if (var_20 < (s32)spC0) {
        goto loop_body;
    }
    *(s16 *)(temp_2_3 + 2) = 0;
}

// Intent: return the target mark stored in the selection task. [inferred]
// FUN_0020BA00
u16 btlSelectionGetTargetMark(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    return *(u16 *)((u8 *)kwlnTaskGetWork((void *)task) + 0x712);
}

// Intent: clear the target mark stored in the selection task. [inferred]
// FUN_0020BA30
void btlSelectionClearTargetMark(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    *(s16 *)((u8 *)kwlnTaskGetWork((void *)task) + 0x712) = 0;
}

/* Both selection accessors return the formation entry read by 001d8bc0.
 * Their action callers consume this address, so the result must be explicit. */
// Intent: return the formation entry for the selection task's current target. [inferred]
// FUN_0020BA60
u32 btlSelectionGetFormationEntry(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    return func_001d8bc0(*(u8 **)((u8 *)kwlnTaskGetWork((void *)task) + 0x720));
}

// Intent: return the formation entry for the selection task's current target (duplicate of btlSelectionGetFormationEntry). [inferred]
// FUN_0020BA90
u32 btlSelectionGetFormationEntryAlt(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    return func_001d8bc0(*(u8 **)((u8 *)kwlnTaskGetWork((void *)task) + 0x720));
}

// Intent: clear the buff flag on every party unit and mark the selection task as ready. [inferred]
// FUN_0020BAC0
/* measured: retail keeps the ~0x200 mask live in the loop preheader; plain -O2
   rematerialises it inside the body (nd 41 -> byte-exact with the hoist). */
/* measured: btlSelectionResetUnitFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlSelectionResetUnitFlags(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *w = (u8 *)kwlnTaskGetWork((void *)task) + 0x710;
    s32 mask = ~0x200;
    u8 *p = *(u8 **)(D_0076449C + 0x178);

    while (p != NULL) {
        *(s32 *)(p + 0xA10) &= mask;
        p = *(u8 **)(p + 0xA6C);
    }
    *(s16 *)(w + 2) = 3;
}

/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
// Intent: initialise a transition block and record its task. [inferred]
// FUN_0020BB20
void btlSelectionInitTransition(u8 *arg0, s32 arg1) {
    memset(arg0, 0, 0x1C);
    *(s32 *)(arg0 + 0x18) = arg1;
    *(s16 *)(arg0 + 2) = 3;
}

/* 512/512 bytes; seventeen fully resolved relocations.
 * The transition helpers explicitly forward their task to its work getter. */
// Intent: advance a selection transition and commit the chosen target. [inferred]
// FUN_0020BB70
void btlSelectionUpdateTransition(u8 *arg0)
{
    u8 *selected;
    if (*(u16 *)(arg0 + 2) == 0) {
        if ((*(u16 *)arg0 & 1) == 0) {
            if (*(u16 *)(arg0 + 4) > 0) {
                --*(u16 *)(arg0 + 4);
            } else if (D_008C024E[0] & 0x20) {
                func_0045af60(0, 0, 0, 2);
                btlPanelReleaseText(*(s32 *)(arg0 + 0x18));
                *(u16 *)(arg0 + 2) = 2;
            } else if (D_008C024E[0] & 0x40) {
                btlPanelReleaseText(*(s32 *)(arg0 + 0x18));
                *(u16 *)(arg0 + 2) = 1;
            } else {
                func_001d8010(*(u8 **)(arg0 + 8), *(u8 **)(arg0 + 0x10));
                if (*(u8 *)(*(u8 **)(arg0 + 0x10) + 0x3C) & 1) {
                    if ((u16)func_0010f8c0(*(u16 *)(arg0 + 0x14)) == 0) {
                        selected = (u8 *)func_001d8bc0(*(u8 **)(arg0 + 0x10));
                        btlPanelStartEntry(*(s32 *)(arg0 + 0x18), func_0019f0f0(*(u8 **)(selected + 0x30)));
                        btlPanelSetCountdown(*(s32 *)(arg0 + 0x18), -1);
                        func_00216d40(*(s32 *)(arg0 + 0x18));
                        btlPanelSetTarget(*(u8 **)(arg0 + 0x18), *(s32 *)(selected + 0x30));
                        if (*(u8 **)(arg0 + 0xC) == NULL) {
                            btlSelectionSetRowIdle(*(u8 **)(selected + 0x30) + 0xA48);
                        } else if (*(u8 **)(arg0 + 0xC) != selected) {
                            func_0045af60(0, 0, 0, 0);
                            btlSelectionSwapRowState(*(u8 **)(*(u8 **)(arg0 + 0xC) + 0x30) + 0xA48, *(u8 **)(selected + 0x30) + 0xA48);
                        }
                        *(u8 **)(arg0 + 0xC) = selected;
                    }
                    *(u8 *)(*(u8 **)(arg0 + 0x10) + 0x3C) &= 0xFE;
                }
            }
        } else {
            btlPanelReleaseText(*(s32 *)(arg0 + 0x18));
            *(u8 *)(*(u8 **)(arg0 + 0x10) + 0x3C) |= 1;
        }
    }
}

// Intent: draw the target frame for each unit in the current selection while the panel is active. [inferred]
// FUN_0020BD70
void btlSelectionDrawTargetFrame(u8 *arg0, u8 *arg1)
{
    typedef struct {
        u8 pad[8];
        f32 sp48[2];
        f32 sp50[2];
    } Frame;
    extern u32 kwlnTaskGetWork(void *arg0);
    extern void btlUiSetRenderStates(void);
    extern u8 *func_001b1560(void);
    extern void btlUnitGetAttachedSphereCenter(u8 *arg0, f32 *arg1);
    extern s32 btlTargetFindInRange(f32 *arg0, f32 *arg1);
    extern void btlUiSetOrigin(u8 *arg0, f32 fparg0, f32 fparg1);
    extern void btlUiDrawSpriteFaded(u8 *arg0, s32 arg1, s32 arg2, f32 fparg0,
                               f32 fparg1, s32 arg5, s32 arg6, s32 arg7,
                               s32 arg8);
    extern void btlUiSetRenderMode(s32 arg0);
    extern void btlSelectionDispatchTargetMode(s32 arg0, u8 *arg1, u8 *arg2);
    Frame frame;
    u8 *temp_2;
    u8 *temp_2_2;
    u8 *temp_6;
    u16 temp_4;
    s32 temp_16;
    s32 var_17;

    temp_2 = (u8 *)kwlnTaskGetWork(*(u8 **)(arg1 + 0x18));
    if ((*(u32 *)temp_2 & 1) != 0) {
        if ((*(u16 *)arg1 & 1) == 0) {
            temp_4 = *(u16 *)(arg1 + 2);
            if ((temp_4 != 3) && (*(u16 *)(arg1 + 4) <= 0)) {
                btlUiSetRenderStates();
                temp_16 = *(u16 *)(*(u8 **)(arg1 + 0x10) + 0x38);
                var_17 = 0;
                while (var_17 < (s32)temp_16) {
                    temp_6 = *(u8 **)(*(u8 **)(*(u8 **)(arg1 + 0x10) +
                                              var_17 * 4) +
                                      0x30);
                    btlSelectionDispatchTargetMode(*(s32 *)(arg1 + 0x18), temp_6 + 0xA48,
                                  temp_6);
                    var_17 += 1;
                }
            }
        } else {
            temp_2_2 = func_001b1560();
            if (temp_2_2 != NULL) {
                btlUnitGetAttachedSphereCenter(*(u8 **)(temp_2_2 + 0x30), frame.sp50);
                if (btlTargetFindInRange(frame.sp50, frame.sp48) != 0) {
                    btlUiSetOrigin(temp_2, frame.sp48[0] - 46.0f,
                                  frame.sp48[1] - 17.0f);
                    btlUiSetRenderMode(2);
                    btlUiDrawSpriteFaded(temp_2, 10, 0x51, 0.0f, 0.0f,
                                  0x52, 0xF3, 0, 0xFF);
                    btlUiDrawSpriteFaded(temp_2, 10, 0x52, 84.0f, 0.0f,
                                  0x52, 0xF3, 0, 0xFF);
                    btlUiSetRenderMode(0);
                    btlUiDrawSpriteFaded(temp_2, 10, 0x4F, 14.0f, 2.0f,
                                  0x0D, 0x1B, 0, 0xFF);
                }
            }
        }
    }
}

// Intent: set the active bit on the selection task's flag word. [inferred]
// FUN_0020BF60
void btlSelectionSetTargetFlag(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    *(u16 *)(p + 0x710) |= 1;
}

// Intent: clear the active bit on the selection task's flag word. [inferred]
// FUN_0020BF90
void btlSelectionClearTargetFlag(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *p;

    p = (u8 *)kwlnTaskGetWork((void *)task);
    *(u16 *)(p + 0x710) &= 0xFFFE;
}

// Intent: set a selection row's state and reset its counter. [inferred]
// FUN_0020BFC0
void btlSelectionSetRowState(u8 *arg0, s16 arg1)
{
    *(s16 *)(arg0 + 0) = arg1;
    *(s16 *)(arg0 + 2) = 0;
}

// Intent: reset a selection row's counter and mark it idle. [inferred]
// FUN_0020BFD0
void btlSelectionSetRowIdle(u8 *arg0)
{
    *(s16 *)(arg0 + 4) = 0;
    *(s16 *)(arg0 + 2) = 1;
}


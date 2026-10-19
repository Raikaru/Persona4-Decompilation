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
#include "datPersona_internal.h"
#include "btl_ui_task_internal.h"
#include "btl_action_internal.h"
#include "rw_camera_internal.h"
#include "datCalc_internal.h"
#include "btl_hud_internal.h"

typedef struct RwMatrix RwMatrix;
typedef struct RwV3d RwV3d;
typedef struct BtlUnit BtlUnit;
typedef struct BtlAction BtlAction;

extern s32 cmmCommunityForArcana(s16 context);
extern u16 cmmCommunityRecordValue(s32 context);
extern void btlSelectionResetSubList(u8 *context, u8 *value);
extern u16 btlSelectionConfirmSubList(u8 *context, u8 *value);
extern void btlSelectionDrawCurrentLabel(u8 *selection, s32 workAddress, u8 *drawState);
extern void btlSelectionDrawSubList(void);
extern void btlSelectionEndSubList(void);
extern void btlSelectionUpdateWindow();

extern u32 datGetFlag(s32 context);

extern void memset(void *destination, s32 value, u32 size);
extern void btlSelectionSetRepeat(u8 *context, s16 *value);
extern u32 datGetItemNameId(s16 context);
extern s32 func_001eb860(void);

static inline u8 *btlSelectionAddByteOffset(u32 offset, u8 *base)
{
    return (u8 *)((u32)offset + (u32)base);
}


extern u32 kwlnTaskGetWork();
extern f32 fGpffff815c;
extern f32 fGpffff83b0;
extern s32 datPersonaGetLevel(u8 *context);
extern u16 frFontSetFlagBits(s16 context);
extern u16 frFontClearFlagBits(u16 context);

extern u32 btlFormationCurrentEntry(void *context);
extern void shdPersonaFinishPhase(u8 *context);
extern s32 shdPersonaIsTransitioning(u8 *context);
extern void shdPersonaSetDisplayState(u8 *context, s32 value, u32 option, s8 flags);
extern void shdPersonaStartSlideIn(u8 *context);
extern void shdPersonaBeginClose(u8 *context);
extern void shdPersonaBeginDisplayAndEndSelection(u8 *context, s32 value, s32 option, s8 flags);
extern void shdPersonaBeginDisplay(u8 *context, s32 value, s32 option, s8 flags);
extern u32 shdPersonaIsSelectionActive(u8 *context);
extern void shdPersonaBeginSelection(u8 *context);
extern void shdPersonaEndSelection(u8 *context, s32 value);
extern void shdPersonaStepSelectionCursor(u8 *context);
extern void btlUiDrawSpriteEntry(u8 *context, s32 value, s32 option, f32 x, f32 y);
extern u8 *D_0076449C;
extern s32 iGpffffb448;
extern s32 D_0062656C[];
extern void btlPanelSetCountdown(s32 context, s32 value);
extern void btlPanelStartEntry(s32 context, s32 value);





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
extern f32 cosf(f32 x);
extern f32 sinf(f32 x);
typedef void (*BtlSelectionDraw)(u8 *work, s32 slot, f32 x, f32 y,
                                    u8 opacity, s32 highlighted, s32 showDetail);
extern void btlSelectionDrawSlideIn(u8 *work, u8 *state, f32 x, f32 y,
                         BtlSelectionDraw drawSelection);

extern void btlPanelDrawSkillEntry(u8 *context, s32 value, f32 fx, f32 fy, u8 option, s32 flags, s32 extra);
extern void btlSelectionDrawList(u8 *context, u8 *value, f32 x, f32 y,
                          BtlSelectionDraw callback);
extern void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                         u8 opacity, s32 highlighted, s32 show_detail);
extern void btlPanelDrawCircle(u8 *unused, f32 scaleX, f32 scaleY, f32 depth, s32 color);
extern void PrimDrawFlatRectangle(u8 *context, f32 *value, f32 x, s32 option);
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
extern void RpSkyRenderStateSet(s32 context, s32 value);
extern void (*D_00887300[])(u32 context, u32 value);
extern f32 fGpffff82e0, fGpffff82e4;
extern f32 D_008872F8[];
extern f32 D_00626890[][2];
extern s32 kwlnGetCamera(void);
extern s32 (*D_00887310[])(s32 primType, void *vertices, s32 count);


extern void btlUiSetRenderMode(s32 context);
extern void btlPanelDrawPersonaName(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern void btlPanelDrawPersonaLevel(u8 *work, s32 slot, f32 x, f32 y,
                          u8 opacity, s32 highlighted, s32 showDetail);
extern u16 datCalcUnderlyingSkillId(s64 context);
extern void btlSelectionRefreshList(u16 *flags, u8 *work);
extern s32 btlSelectionHandleInput(u8 *selection, s32 workAddress, u8 **nextPanel);
extern void btlSelectionDrawCommands(u8 *selection, s32 workAddress, u8 *drawState);
extern void btlPanelDrawStrip(s32 index, f32 x, f32 y, f32 depth, f32 angle, s32 extend);
extern void btlSelectionSaveCursor();
extern void btlSelectionDrawBar(u8 *unused, u8 *value, f32 *option);
extern u8 *btlActionFindByUnit(s32 context);
extern u8 *iGpffffb3ac;

extern s32 D_00881444_abs[];
extern void btlPanelUpdate(void *context);
extern f32 fGpffff8478;
extern f32 fGpffffb478;
extern void btlSelectionUpdateTransition(u8 *context);
extern u8 D_00794810[];
extern u8 D_00794870[];
extern u8 D_00794FF0[];
extern u8 D_00795020[];
extern u8 D_00795080[];

extern void btlPanelInitWork(u8 *context, s32 value);
extern void btlPanelDrawFrame(s32 context, u8 *value);
extern void btlSelectionUpdateTransition(u8 *context);
extern void btlPanelDrawBackdropGrid(s32 context, u8 *value);
extern void btlPanelDrawDetail(void);
extern void btlPanelDrawSkyFrame(s32 context, u8 *value);
extern void btlSelectionInitTransition(u8 *context, s32 value);
extern void btlSelectionDrawTargetFrame(u8 *context, u8 *value);
extern u8 D_006253B0[];

/* Inferred unit: no __FILE__ evidence; boundaries from scheduler/gap breaks in former bucket code1_0020; members 00202c60-0020bfd0 */

extern void btlUiSetOrigin(u8 *context, f32 x, f32 y);
extern void btlUiSetRenderStates(void);
extern void btlUiDrawSpriteEntry(u8 *context, s32 value, s32 option, f32 x, f32 y);
extern void btlUiSetScale(u8 *context, f32 x, f32 y);
extern void btlUiSetRenderMode(s32 context);
extern void btlUiSetAlpha(u8 *context, f32 x);
extern void btlUiSelectEffect(s32 context, u32 value);
extern void btlSelectionDispatchTargetMode(s32 context, u8 *value, u8 *option);
extern void btlSelectionSwapRowState(u8 *context, u8 *value);
typedef struct BtlSelection {
    u16 flags;
    s16 first;
    s16 selected;
    s16 pageSize;
    s16 count;
    u8 pad0A[2];
    void *initialize;            /* 0x0C: callback ABI depends on dispatch phase */
    void *handleInput;
    void *draw;
    void *notify;
    void *saveCursor;
    u8 *parent;                 /* 0x20 */
    u8 *child;
    u8 *owner;
    u16 previous;
    u16 next;
    u16 previousPage;
    u16 nextPage;
} BtlSelection;
typedef struct {
    s32 (*draw)(s32 primitive, void *vertices, s32 count);
} BtlPanelPrimitiveDispatch;
extern f32 fGpffff836c;
extern void shdEnableBlendFlag(void);
extern void shdDisableBlendFlag(void);
typedef struct { u8 b0, b1, b2, b3; } BtlSkillIconColor;
extern void ShdSkill_DrawIcon(Vec2f position, f32 scale,
                          BtlSkillIconColor color, u16 skill, s32 texture);
extern u32 datCalcSkillCost(u8 *unit, s32 skill);
extern s32 datCalcThresholdTrigger(u8 *unit, s32 skill);
extern u16 datCalcThresholdKind(u8 *unit, s32 skill);
extern s16 datGetUnitAiTactic(s16 context);
extern u32 datPersonaNamePart1(s16 context);
extern s32 itfMesWindowDrawEntry(f32 x, f32 y, f32 scale, s32 color, s32 mode,
                         s32 style, s32 flags, s32 handle, s32 index);
typedef struct BtlPanelRenderDispatch {
    void (*setState)(u32 state, u32 value);
} BtlPanelRenderDispatch;
extern s32 datItemCount(s16 id);
extern s32 datCalcIsFlaggedPersonaSkill(s32 id);
extern u8 *iGpffffb3b8;
typedef struct {
    s16 id;
    u8 quantity;
    u8 reserved;
} BtlPanelItem;

/* Resource slots in BtlUiSprite's opaque +0x5C span, consumed by icon draws. */
typedef struct BtlPanelIconResources {
    s32 itemTexture;
    s32 skillTexture;
    u8 pad08[8];
} BtlPanelIconResources;

/* The action's opaque command tail holds the selected item and persona ids. */
typedef struct BtlPanelActionChoice {
    u16 item;
    u8 pad02[2];
    u16 persona;
} BtlPanelActionChoice;

/* btlListStart resets this 0x14-byte stack/list state independently of nodes. */
typedef struct BtlSelectionList {
    s32 unk00;
    s32 unk04;
    u8 *head;
    u8 *current;
    u8 *previous;
} BtlSelectionList;

/* Four saved {first row, selected row} pairs, reached through action+0x3F0. */
typedef struct BtlSelectionCursorRecord {
    struct {
        s16 first;
        s16 selected;
    } slots[4];
} BtlSelectionCursorRecord;

/* btlPanelInitWork clears 0x5B4 bytes; six selection nodes occupy 40..177.
 * Counter names follow their drawing consumers, not guessed game states. */
typedef struct {
    u16 state;
    u16 previousState;
    s32 flags;
    s16 outlineFrame;
    s16 scaleFrame;
    s16 circleFrame;
    s16 commandFrame;
    s16 gridFrame;
    s16 stripFrame;
    s16 cursorSlide;
    s16 listFrame;
    s16 detailFrame;
    s16 slideFrame;
    s16 labelFrame;
    s16 labelTitleFrame;
    s16 clipFrame;
    s16 titleFrame;
    u8 outlineColor[4];
    u8 pulseColor[4];
    BtlSelectionList list;       /* 0x2C */
    BtlSelection selections[6]; /* 0x40 */
    u8 *action;                  /* 0x178 */
    u8 *partyUnits[4];
    u16 partyCount;
    u8 pad18E[2];
    u8 *selectedUnit;
    u16 skills[8];
    u16 skillCount;
    BtlPanelItem items[256];
    u16 itemCount;
    u8 *personaTask;
    s16 personaSlot;
    u8 pad5AE[2];
    s32 task;
} BtlPanelWork;

/* btlSelectionInitTransition clears 0x1C bytes and installs state/task. */
typedef struct BtlSelectionTransition {
    u16 flags;
    u16 state;
    u16 delay;
    u8 pad06[2];
    u8 *action;
    u8 *previousAction;
    u8 *targets;
    u16 skill;
    u8 pad16[2];
    s32 task;
} BtlSelectionTransition;

/* Embedded at BtlUnit+0xA48; the row setters establish all three halfwords. */
typedef struct BtlSelectionRow {
    s16 state;
    s16 counter;
    s16 idleFrame;
} BtlSelectionRow;

typedef char BtlSelectionSizeCheck[sizeof(BtlSelection) == 0x34 ? 1 : -1];
typedef char BtlPanelWorkSizeCheck[sizeof(BtlPanelWork) == 0x5B4 ? 1 : -1];
typedef char BtlSelectionTransitionSizeCheck[sizeof(BtlSelectionTransition) == 0x1C ? 1 : -1];

static inline void btlPanelDrawExtendedStrip(BtlPanelRenderDispatch *renderer,
                                          f32 x, f32 y, f32 progress)
{
    void (**setState)(u32, u32);
    setState = &renderer->setState;
    (*setState)(6, 1);
    btlPanelDrawStrip(3, x, y, 110.0f, progress * 90.0f, 1);
    (*setState)(6, 0);
}
struct FrFontNode;
extern u16 datGetSkillPropertyByte(s32 context);
extern s32 btlUnitGetDataRowAlt(u8 *context);
extern void btlEffectSelectNeighbourTarget(u8 *context, u8 *value);
extern void btlPanelReleaseText(s32 task);
extern void btlPanelMarkEntryTimed(s32 task);
extern void btlPanelSetTarget(u8 *task, s32 value);
extern void btlSelectionSetRowIdle(u8 *context);
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
void btlSelectionInit(u8 *selection, s16 pageSize, s16 count, void *initialize, void *handleInput, void *draw, void *saveCursor, u8 *owner) {
    memset(selection, 0, 0x34);
    ((BtlSelection *)selection)->pageSize = pageSize;
    ((BtlSelection *)selection)->count = count;
    ((BtlSelection *)selection)->initialize = initialize;
    ((BtlSelection *)selection)->handleInput = handleInput;
    ((BtlSelection *)selection)->draw = draw;
    ((BtlSelection *)selection)->saveCursor = saveCursor;
    ((BtlSelection *)selection)->owner = owner;
    ((BtlSelection *)selection)->flags |= 8;
    btlSelectionSetRepeat(selection, NULL);
}

// Intent: recompute the visible selection window (first row and page) from the selected index. [inferred]
// FUN_00202D20
void btlSelectionUpdateWindow(u8 *selection, s64 selectedIndex, s64 firstIndex)
{
    s32 lastFirst;
    s16 pageSize;
    s16 count;
    s32 requestedFirst;
    s32 selected;
    s64 first;

    first = firstIndex;
    requestedFirst = (s16)first;
    if ((requestedFirst > 0) && (((BtlSelection *)selection)->count < (requestedFirst + ((BtlSelection *)selection)->pageSize))) {
        first = 0;
    }
    selected = (s16)selectedIndex;
    if (((BtlSelection *)selection)->count <= selected) {
        ((BtlSelection *)selection)->first = 0;
        ((BtlSelection *)selection)->selected = 0;
        return;
    }
    count = ((BtlSelection *)selection)->count;
    pageSize = ((BtlSelection *)selection)->pageSize;
    if (selected < ((s16)first + pageSize)) {
        ((BtlSelection *)selection)->first = (u16)first;
        ((BtlSelection *)selection)->selected = (u16)selectedIndex;
        return;
    }
    if (selected < (pageSize - 1)) {
        ((BtlSelection *)selection)->first = 0;
        ((BtlSelection *)selection)->selected = (u16)selectedIndex;
        return;
    }
    lastFirst = count - pageSize;
    if (lastFirst < selected) {
        ((BtlSelection *)selection)->first = lastFirst;
        ((BtlSelection *)selection)->selected = (u16)selectedIndex;
        return;
    }
    ((BtlSelection *)selection)->first = (s16)(selected - 1);
    ((BtlSelection *)selection)->selected = (u16)selectedIndex;
}

// Intent: set the key-repeat masks from a table or the default repeat values. [inferred]
// FUN_00202E00
void btlSelectionSetRepeat(u8 *selection, s16 *repeatMasks)
{
    if (repeatMasks != NULL) {
        memcpy(selection + 0x2C, repeatMasks, 8);
        return;
    }
    ((BtlSelection *)selection)->previous = 0x1000;
    ((BtlSelection *)selection)->next = 0x4000;
    ((BtlSelection *)selection)->previousPage = 0x8000;
    ((BtlSelection *)selection)->nextPage = 0x2000;
}

// Intent: store the owner pointer of a selection block. [inferred]
// FUN_00202E60
void btlSelectionSetOwner(u8 *selection, void *callback)
{
    ((BtlSelection *)selection)->notify = callback;
}

#pragma push
/* measured: btlSelectionReadInput MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
// Intent: read the selection input and return the action code (1 to 4) or 0. [inferred]
// FUN_00202E70
s32 btlSelectionReadInput(u8 *input)
{
    extern u16 D_008C024E[];
    extern u16 D_008C0276[];
    extern u16 D_008C027A[];
    BtlSelection *selection;
    s32 count;
    u32 repeat;
    u32 flags;

    selection = (BtlSelection *)input;
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
                sdkSndStartStream(0, 0, 0, 0);
            } else {
                sdkSndStartStream(0, 0, 0, 5);
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
                sdkSndStartStream(0, 0, 0, 0);
            } else {
                sdkSndStartStream(0, 0, 0, 5);
            }
        }
        return (u16)(single != 0 ? 6 : 8);
    }
    return 0;
}

#pragma pop
// Intent: start a callback list at the given node and run each node's init callback. [inferred]
// FUN_00203360
void btlListStart(u8 *list, u8 *head) {
    u8 *next;
    u8 *node;

    ((BtlSelectionList *)list)->unk00 = 0;
    ((BtlSelectionList *)list)->unk04 = 0;
    ((BtlSelectionList *)list)->previous = 0;
    ((BtlSelectionList *)list)->current = head;
    ((BtlSelectionList *)list)->head = head;
    node = head;
    while (node != NULL) {
        next = ((BtlSelection *)node)->child;
        ((void (*)(u8 *, s32))((BtlSelection *)node)->initialize)(node, (s32)((BtlSelection *)node)->owner);
        node = next;
    }
}

// Intent: flush a callback list by running each node's exit callback and clearing the head. [inferred]
// FUN_002033C0
/* measured: typing the remaining head read changed eight compared bytes; keep its byte-addressed load. */
void btlListFlush(u8 *list) {
    u8 *next;
    u8 *node;

    node = *(u8 **)(list + 8);
    while (node != NULL) {
        next = ((BtlSelection *)node)->child;
        ((void (*)(u8 *, s32))((BtlSelection *)node)->saveCursor)(node, (s32)((BtlSelection *)node)->owner);
        node = next;
    }
    ((BtlSelectionList *)list)->head = NULL;
}

// Intent: advance the callback list according to the node's result code (stay, push, pop). [inferred]
// FUN_00203420
/* measured: independently typing the remaining list/node links, owner words and callback accesses
 * lost MATCH; keep those byte aliases alongside the typed fields. */
s32 btlListStep(u8 *list)
{
    u8 *next;
    u8 *current;
    s32 result;
    u8 *previous;

    current = ((BtlSelectionList *)list)->current;
    next = ((BtlSelection *)current)->child;
    result = ((s32 (*)(u8 *, s32, u8 **))((BtlSelection *)current)->handleInput)(
        current, *(s32 *)(current + 0x28), &next) & 0xFFFF;
    switch (result) {
    case 1:
        break;
    case 2:
        if (((BtlSelection *)current)->parent != NULL) {
            if ((void (*)(u8 *, s32))((BtlSelection *)current)->saveCursor != NULL) {
                ((void (*)(u8 *, s32))((BtlSelection *)current)->saveCursor)(
                    current, *(s32 *)(current + 0x28));
            }
            *(u8 **)(list + 0x10) = *(u8 **)(list + 0xC);
            *(u8 **)(list + 0xC) = *(u8 **)(current + 0x20);
            *(s32 *)(*(u8 **)(current + 0x20) + 0x24) = 0;
            previous = *(u8 **)(current + 0x20);
            if ((void (*)(u8 *, s32))((BtlSelection *)previous)->initialize != NULL) {
                ((void (*)(u8 *, s32))((BtlSelection *)previous)->initialize)(
                    previous, (s32)((BtlSelection *)previous)->owner);
            }
        }
        break;
    case 3:
        if (next != NULL) {
            if ((void (*)(u8 *, s32))((BtlSelection *)current)->saveCursor != NULL) {
                ((void (*)(u8 *, s32))((BtlSelection *)current)->saveCursor)(
                    current, *(s32 *)(current + 0x28));
            }
            *(u8 **)(list + 0x10) = *(u8 **)(list + 0xC);
            *(u8 **)(list + 0xC) = next;
            ((BtlSelection *)next)->parent = current;
            *(u8 **)(current + 0x24) = next;
            ((BtlSelection *)next)->child = 0;
            if ((void (*)(u8 *, s32))((BtlSelection *)next)->initialize != NULL) {
                ((void (*)(u8 *, s32))((BtlSelection *)next)->initialize)(
                    next, (s32)((BtlSelection *)next)->owner);
            }
        }
        break;
    case 4:
    case 5:
        break;
    }
    return result;
}

// Intent: run each list node's update callback with the list owner. [inferred]
// FUN_002035A0
/* measured: typing the callback owner word at node+0x28 changed eight compared bytes; retain its
 * signed address load. */
void btlListDispatchUpdate(u8 *list) {
    u8 *node;

    node = ((BtlSelectionList *)list)->head;
    while (node != NULL) {
        ((void (*)(u8 *, s32, u8 *))((BtlSelection *)node)->draw)(node, *(s32 *)(node + 0x28), list);
        node = ((BtlSelection *)node)->child;
    }
}

// Intent: run each list node's optional callback with the list owner. [inferred]
// FUN_00203600
/* measured: typing the callback owner word at node+0x28 changed eight compared bytes; retain its
 * signed address load. */
void btlListDispatchNotify(u8 *list) {
    u8 *node;

    node = ((BtlSelectionList *)list)->head;
    while (node != NULL) {
        void (*fn)(u8 *, s32, u8 *) = (void (*)(u8 *, s32, u8 *))((BtlSelection *)node)->notify;
        if (fn != NULL) {
            fn(node, *(s32 *)(node + 0x28), list);
        }
        node = ((BtlSelection *)node)->child;
    }
}

/* measured: callback materialisation residual remains. Committed at nd 73. */
// Intent: initialise the battle panel task state and its selection block. [inferred]
// FUN_00203670
void btlPanelInit(s32 unused, s32 actionAddress)
{
    struct {
        s16 values[2];
        s32 pad;
    } repeatMasks;
    s32 flags;
    s32 mask;
    u8 *taskWork;
    u8 *panel;
    u8 *selection;
    taskWork = (u8 *)kwlnTaskGetWork();
    panel = taskWork + 0x9C;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->action = (u8 *)actionAddress;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->state = 1;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->outlineFrame = 0;
    mask = -3;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->scaleFrame = mask;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->circleFrame = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->commandFrame = -9;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->stripFrame = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->cursorSlide = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->clipFrame = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->titleFrame = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->listFrame = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->detailFrame = 0;
    flags = ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->flags;
    flags &= mask;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->flags = flags;
    flags = flags & 0xFFFFFFFEU;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->flags = flags;
    btlSelectionInit(panel + 0x40, 8, 8,
                  (void *)btlSelectionRefreshList, (void *)btlSelectionHandleInput,
                  (void *)btlSelectionDrawCommands, (void *)btlSelectionSaveCursor, panel);
    selection = panel + 0x40;
    btlSelectionSetOwner(selection, (void *)btlSelectionDrawBar);
    memset((s16 *)&repeatMasks, 0, 8);
    repeatMasks.values[0] = 0x1000;
    repeatMasks.values[1] = 0x4000;
    btlSelectionSetRepeat(panel + 0x40, (s16 *)&repeatMasks);
    btlSelectionUpdateWindow(panel + 0x40, 3, 0);
    btlListStart(panel + 0x2C, panel + 0x40);
    ((BtlPanelWork *)panel)->list.unk00 = 0;
    ((BtlPanelWork *)panel)->list.unk04 = 0;
}

/* This and the selection helpers take the caller's task explicitly. Retail
 * forwards that argument to the work getter; an empty C parameter list loses
 * the contract even when the argument register happens to retain the value. */
// Intent: set the panel task state to active. [inferred]
// FUN_002037B0
void btlPanelSetActive(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *taskWork;

    taskWork = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->state = 1;
}

// Intent: return the panel task state. [inferred]
// FUN_002037E0
u16 btlPanelGetState(void) {
    return ((BtlPanelWork *)((BtlUiTaskWork *)(u8 *)kwlnTaskGetWork())->panel)->state;
}

/* measured: opt_propagation off probe for 00203810 evaluation order. */
/* measured: func_00203810 MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// FUN_00203810
/* Return whether the current panel list node is the embedded command-selection node. */
s32 btlPanelIsCommandSelectionActive(void)
{
    u8 *taskWork;
    u8 *selectionAddress;
    s32 currentAddress;

    taskWork = (u8 *)kwlnTaskGetWork();
    selectionAddress = taskWork + 0x9C;
    currentAddress = (s32)((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->list.current;
    selectionAddress += 0x40;
    return (s32)(currentAddress == (s32)selectionAddress);
}

/* measured: close opt_propagation after func_00203810 probe. */
/* measured: btlPanelDrawCircle, btlPanelDrawOutlineFill MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
// Intent: report whether the panel task is ready (state below 2). [inferred]
// FUN_00203850
s32 btlPanelIsReady(void)
{
    return ((BtlPanelWork *)((BtlUiTaskWork *)(u8 *)kwlnTaskGetWork())->panel)->commandFrame < 2;
}

// FUN_00203880
/* Empty target-action notification handler; both caller-supplied addresses are unused. */
void btlPanelOnTargetAction(s32 unusedTask, s32 unusedAction)
{
}

// Intent: set the panel task state to closing. [inferred]
// FUN_00203890
void btlPanelSetClosing(void) {
    u8 *taskWork;

    taskWork = (u8 *)kwlnTaskGetWork();
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->state = 4;
}

// Intent: reset the panel task state, list and sub-task pointers. [inferred]
// FUN_002038C0
/* measured: typing the remaining persona-task test at panel+0x5A8 lost MATCH; retain its integer-
 * address interpretation. */
void btlPanelReset(s32 task) {
    u8 *panel = (u8 *)kwlnTaskGetWork((void *)task) + 0x9C;

    ((BtlPanelWork *)panel)->flags &= ~2;
    btlListFlush(panel + 0x2C);
    if (((BtlPanelWork *)panel)->personaTask != 0) {
        shdPersonaFinishPhase(((BtlPanelWork *)panel)->personaTask);
        *(s32 *)(panel + 0x5A8) = 0;
        ((BtlPanelWork *)panel)->personaSlot = -1;
    }
    ((BtlPanelWork *)panel)->action = 0;
    *(s16 *)panel = 0;
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
    extern void shdEnableBlendFlag(void);
    extern void shdDisableBlendFlag(void);
    f32 hi[80][16];
    f32 lo[42][16];
    f32 base;
    f32 reciprocal;
    f32 sx2;
    f32 sy2;
    f32 sx3;
    f32 sy3;
    u32 vertex;
    BtlPanelPrimitiveDispatch *draw;

    scaleX *= fGpffff8488;
    scaleY *= fGpffff848c;
    sx2 = fGpffff8490 * scaleX;
    sy2 = fGpffff8490 * scaleY;
    sx3 = fGpffff8494 * scaleX;
    sy3 = fGpffff8494 * scaleY;
    base = D_008872F8[0];
    reciprocal = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
    D_00887300[0](1, 0);
    if ((a & 0xFF) == 0xFF) {
        shdEnableBlendFlag();
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
        draw = (BtlPanelPrimitiveDispatch *)D_00887310;
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
        shdDisableBlendFlag();
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
    draw = (BtlPanelPrimitiveDispatch *)D_00887310;
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
    reciprocal = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
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
/* The rectangle wrapper consumes integer coordinate bits through its float-word interface; the
 * RGBA cast likewise passes four packed bytes without numeric conversion. */
void btlPanelDrawBackdrop(u8 *glyphs, f32 scaleX, f32 scaleY)
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
    PrimDrawFlatRectangle((u8 *)&work.colors, (f32 *)(void *)&work.value3, 0.0f, 0);
    work.colors.c0 = 0xFF;
    work.colors.c1 = 0xFF;
    work.colors.c2 = 0xFF;
    work.colors.c3 = 0x20;
    btlPanelDrawCircle(glyphs, scaleX, scaleY, 100.0f, *(s32 *)(void *)&work.colors);
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
void btlPanelDrawSpriteGrid(u8 *glyphs, f32 unusedScaleX, f32 unusedScaleY, u8 opacity)
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
    btlUiSetOrigin(glyphs, 36.0f, 19.0f);
    btlUiSetAlpha(glyphs, 50.0f);
    btlUiSetRenderMode(2);
    y = 0.0f;
    row = 0;
    while (row < 3) {
        x = 0.0f;
        column = 0;
        while (column < 5) {
            frame = D_00764564 % 4;
            D_00764564++;
            btlUiDrawSpriteFaded(glyphs, 15, frame, x, y, 255, 255, 255, opacity);
            x += 126.0f;
            column++;
        }
        y += 126.0f;
        row++;
    }
    btlUiSetRenderMode(0);
    btlUiSetAlpha(glyphs, 0.0f);
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
    u8 *taskWork;

    taskWork = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->gridFrame = 0;
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->flags &= ~1;
}

// Intent: set the active bit of the task's state word. [inferred]
// FUN_00204D90
void btlPanelSetFlag(void)
{
    u8 *taskWork;

    taskWork = (u8 *)kwlnTaskGetWork();
    ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->flags = ((BtlPanelWork *)((BtlUiTaskWork *)taskWork)->panel)->flags | 0x1;
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
    reciprocal = 1.0f / ((RwCamera *)(u32)kwlnGetCamera())->nearPlane;
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
    shdEnableBlendFlag();
    draw = D_00887310;
    draw[0](4, vertices, 4);
    shdDisableBlendFlag();
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
/* measured: typed skill indexing changed two compared bytes. The byte-offset helper retains the
 * retail index-before-base address order. */
void btlPanelDrawSkillEntry(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 showDetail)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern void itfMesWindowDrawDefaultEntry(f32 x, f32 y, f32 z, s32 color,
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
    BtlSkillIconColor iconColor;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)work)->task);
    unit = (u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit->datUnit;
    skill = *(s16 *)(btlSelectionAddByteOffset((u32)(slot * 2), work) + 0x194);
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
                  ((BtlPanelIconResources *)((BtlUiSprite *)glyphs)->pad5C)->skillTexture);
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
        itfMesWindowDrawDefaultEntry(10.0f + ((2.0f + textX) - 1.0f), 36.0f + y,
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
/* measured: independently typing the remaining item id/quantity indexing lost MATCH; retain the
 * shared byte offset and signed quantity load. */
void btlPanelDrawEntry(u8 *work, s32 slot, f32 x, f32 y,
                   u8 opacity, s32 highlighted, s32 showDetail)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern void datEntryDrawFlagIcon(Vec2f context, f32 x, s32 value,
                              s16 option, s32 flags, s32 extra);
    u8 *glyphs;
    u8 tone;
    s32 itemOffset;
    s32 id;
    s32 digit;
    s32 alpha;
    s32 tens;
    s32 radix;
    f32 digitY;
    f32 digitX;
    f32 textX;
    const char *name;
    Vec2f pos;
    union {
        Color4 bytes;
        s32 word;
    } color;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)work)->task);
    itemOffset = slot * 4;
    id = *(s16 *)(btlSelectionAddByteOffset((u32)itemOffset, work) + 0x1A6);
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
    datEntryDrawFlagIcon(pos, 50.0f, color.word, id,
                  ((BtlPanelIconResources *)((BtlUiSprite *)glyphs)->pad5C)->itemTexture, ((BtlPanelIconResources *)((BtlUiSprite *)glyphs)->pad5C)->skillTexture);
    frFontSetFlagBits(0x40);
    alpha = opacity & 0xFF;
    textX = 42.0f + x;
    name = (const char *)datGetItemNameId(id);
    {
        f32 textY = (2.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawTextWithCharWidth(textX, textY, depth,
                      (high << 24) | (high << 16) |
                          ((u32)(u8)tone << 8) | alpha,
                      0, 1, name, 0, -1);
    }
    frFontClearFlagBits(0x40);
    btlUiDrawSpriteFaded(glyphs, 0xC, 0x47, (374.0f + x) - 97.0f,
                  (157.0f + y) - 145.0f, tone, tone, tone, opacity);
    digit = *(s8 *)(btlSelectionAddByteOffset((u32)itemOffset, work) + 0x1A8);
    digitY = (155.0f + y) - 145.0f;
    digitX = (398.0f + x) - 97.0f;
    btlUiDrawSpriteFaded(glyphs, 0xC, (digit % 10) + 9, 16.0f + digitX,
                  digitY, tone, tone, tone, opacity);
    radix = 10;
    tens = digit / radix;
    if (tens != 0) {
        btlUiDrawSpriteFaded(glyphs, 0xC, (tens % radix) + 9, digitX, digitY,
                      tone, tone, tone, opacity);
    }
    if (showDetail != 0) {
        frFontSetFlagBits(0x40);
        {
            s32 labelX;
            s32 labelY;
            s32 item;
            labelX = (s32)(10.0f + ((2.0f + textX) - 1.0f));
            labelY = (s32)(36.0f + y);
            item = (s16)id;
            fclMesWindowDrawItemCategory(0.0f, item, labelX, labelY, alpha | ~0xFF, 1, 0);
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
    f32 digitY;
    f32 digitX;
    const char *name;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)work)->task);
    persona = (u8 *)datPersonaRosterSlot((s16)slot);
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
    digitY = 5.0f + y;
    digitX = 63.0f + x;
    btlUiDrawSpriteFaded(glyphs, 13, level % 10 + 0x1D, 22.0f + digitX,
                  digitY, tone, tone, tone, opacity);
    radix = 10;
    tens = level / radix;
    if (tens != 0) {
        btlUiDrawSpriteFaded(glyphs, 13, tens % radix + 0x1D, digitX,
                      digitY, tone, tone, tone, opacity);
    }
    frFontSetFlagBits(0x40);
    name = (const char *)datPersonaGetRow(((DatPersonaRecord *)persona)->id);
    {
        f32 textX = 151.0f + x;
        f32 textY = (4.0f + y) - 1.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawTextWithCharWidth(
            textX, textY, depth,
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

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)work)->task);
    if (highlighted != 0) {
        tone = 0x1B;
    } else {
        tone = 0xFF;
    }
    persona = ((u8 **)(work + 0x17C))[slot];
    frFontSetFlagBits(0x40);
    name = (const char *)datPersonaNamePart1((s16)((BtlUnit *)persona)->charId);
    {
        f32 textX = 1.0f + x;
        f32 textY = (19.0f + y) - 3.0f;
        f32 depth = 50.0f;
        u32 high = (u8)tone;
        frFontExDrawText(
            textX, textY, depth,
            (high << 24) | (high << 16) | ((u32)(u8)tone << 8) | (u8)opacity,
            0, 1, name, 0, 0);
    }
    frFontClearFlagBits(0x40);
    btlUiDrawSpriteFaded(glyphs, 9, 0x3C, 155.0f + x,
                  24.0f + y, tone, tone, tone, opacity);
    btlUiDrawSpriteFaded(
        glyphs, 9, datGetUnitAiTactic((s16)((BtlUnit *)persona)->charId) + 0x3F,
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
                   u8 opacity, s32 selected, s32 drawText)
{
    u8 *work;
    u8 color;
    f32 lineY;

    work = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task);
    if (selected != 0) color = 0x1B;
    else color = 0xFF;
    lineY = 8.0f + y;
    btlUiDrawSpriteFaded(work, 9, 0x3C, 48.0f + x, lineY, color, color, color, opacity);
    btlUiDrawSpriteFaded(work, 9, 0x3C, 270.0f + x, lineY, color, color, color, opacity);
    btlUiDrawSpriteFaded(work, 9, (s32)((u32)index + 0x3FU), 71.0f + x, y,
                  color, color, color, opacity);
    if (drawText != 0) {
        frFontSetFlagBits(0x40);
        itfMesWindowDrawEntry(10.0f + (2.0f + (42.0f + x) - 1.0f), 36.0f + y, 0.0f,
                      (s32)(0xFFFFFF00U | (u8)opacity), 1, 0, 0,
                      ((BtlUiTaskWork *)work)->messageWindow, index);
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
/* measured: typing the remaining flags read independently lost MATCH; other panel fields remain typed. */
void btlSelectionDrawList(u8 *state, u8 *selectionState, f32 inputScaleX, f32 scaleY, BtlSelectionDraw callback)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern f32 fGpffff809c;
    extern f32 fGpffff8198;
    BtlSelection *list;
    BtlSelectionDraw drawSelection;
    BtlPanelRenderDispatch *renderer;
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

    list = (BtlSelection *)selectionState;
    scaleOrRowY = inputScaleX;
    drawSelection = callback;
    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)state)->task);
    showScroll = 1;
    showPrompt = 1;
    if (*(s32 *)(state + 4) & 4) {
        f32 raw;
        f32 clamped;
        verticalWork = 4.0f;
        raw = (f32)((BtlPanelWork *)state)->listFrame / verticalWork;
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
        raw = unitOrScrollX - (f32)((BtlPanelWork *)state)->listFrame / verticalWork;
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
            if (((BtlPanelWork *)state)->flags & 4) {
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
        raw = (f32)((BtlPanelWork *)state)->clipFrame / verticalWork;
        clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
        clipProgress = unitOrScrollX - ((easingWork * clamped) - (clamped * clamped));
    }
    renderer = (BtlPanelRenderDispatch *)D_00887300;
    renderer->setState(6, 1);
    verticalWork = 70.0f * clipProgress;
    upperEdgeY = 129.0f + offsetY + verticalWork;
    horizontalWork = 476.0f + offsetX;
    btlUiDrawSpriteEntry(glyphs, 9, 0x26, horizontalWork, upperEdgeY);
    verticalWork = (274.0f + offsetY) - verticalWork;
    btlUiDrawSpriteEntry(glyphs, 9, 0x26, horizontalWork, verticalWork);
    if (!(clipProgress <= 0.0f)) {
        BtlPanelRenderDispatch *clipRenderer;
        clipRenderer = (BtlPanelRenderDispatch *)D_00887300;
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
        PrimDrawFlatRectangle((u8 *)&clip.colors, clip.rectangle.words, 0.0f, 0);
        clip.rectangle.coordinates[1] = (s32)(3.0f + verticalWork);
        PrimDrawFlatRectangle((u8 *)&clip.colors, clip.rectangle.words, 0.0f, 0);
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
        raw = (f32)((BtlPanelWork *)state)->titleFrame / 10.0f;
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
        if (((BtlPanelWork *)state)->flags & 4) {
            f32 raw;
            f32 clamped;
            raw = (f32)((BtlPanelWork *)state)->detailFrame / 7.0f;
            clamped = raw > unitOrScrollX ? unitOrScrollX : (raw < 0.0f ? 0.0f : raw);
            easingWork = (easingWork * clamped) - (clamped * clamped);
            slideDistance = -410.0f;
        } else {
            f32 raw;
            f32 clamped;
            raw = 1.0f - (f32)((BtlPanelWork *)state)->detailFrame / 7.0f;
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
                   BtlSelectionDraw drawSelection)
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
    BtlPanelRenderDispatch *renderer;

    glyphs = (u8 *)kwlnTaskGetWork(((BtlPanelWork *)work)->task);
    btlUiSetOrigin(glyphs, x, y);

    progress = (f32)(((BtlPanelWork *)work)->slideFrame) / 4.0f;
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

    renderer = (BtlPanelRenderDispatch *)D_00887300;
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
        PrimDrawFlatRectangle((u8 *)&color, (f32 *)rect, 0.0f, 0);
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
    renderer = (BtlPanelRenderDispatch *)D_00887300;
    renderer->setState(8, 0);
    btlUiSetAlpha(glyphs, 150.0f);
    renderer->setState(6, 1);
    drawSelection(work, ((BtlSelection *)selection)->selected, 127.0f, 338.0f, 0xFF, 0, 0);
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
/* The +0x3F0 saved-cursor pointer has no member in the shared action layout: its cursor/target-
 * storage union is not established there, so this pointer slot remains raw. */
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
        action = *(u8 **)(((BtlPanelWork *)work)->action + 0x3F0);
        if (action != NULL) {
            btlSelectionUpdateWindow((u8 *)flags, ((BtlSelectionCursorRecord *)action)->slots[0].selected, *(s16 *)action);
        }
    }
    *flags |= 4;
    *flags |= 2;
    skillCount = 0;
    unit = (u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit;
    if (unit[0xA2] == 0) {
        persona = (u8 *)datPersonaGetRecord(((BtlUnit *)unit)->charId);
        for (skillSlot = 0; skillSlot < 8; skillSlot++) {
            skill = datPersonaGetSkillAt((DatPersonaRecord *)persona, (s16)skillSlot);
            if (skill != 0 && skill < 0x1B8 && (((DatSkillEntry *)iGpffffb3b8)[skill].flags01 & 2)) {
                ((BtlPanelWork *)work)->skills[skillCount] = skill;
                skillCount++;
            }
        }
    }
    ((BtlPanelWork *)work)->skillCount = skillCount;
    itemCount = 0;
    for (itemSlot = 0; itemSlot < 0x100; itemSlot++) {
        if (datItemCount((s16)(itemSlot + 0x300)) != 0 &&
            datCalcIsFlaggedPersonaSkill((u16)(itemSlot + 0x300)) != 0) {
            ((BtlPanelWork *)work)->items[itemCount].id = itemSlot + 0x300;
            ((BtlPanelWork *)work)->items[itemCount].quantity = datItemCount((s16)(itemSlot + 0x300));
            itemCount++;
        }
    }
    ((BtlPanelWork *)work)->itemCount = itemCount;
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
/* measured: independently typing the remaining task/action, selected-row and panel-counter reads
 * lost MATCH, including signed skill/item-count reads. Keep those accesses byte-addressed. */
s32 btlSelectionHandleInput(u8 *selection, s32 workAddress, u8 **nextPanel)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern s32 func_001f0620(u8 *context, s64 value);
    extern s32 btlActionRunTargetCallback(s32 context, u16 value, s32 option, s32 flags, s32 extra);
    extern s32 datCalcDefaultSkillId(u8 *unit);
    extern u8 *shdPersonaTaskCreate(s32 context, s32 value, s32 option, s32 flags, s32 extra);
    extern void btlSelectionInit(u8 *context, s16 value, s16 option, void *a, void *b, void *c, void *d, u8 *blue);
    extern void btlSelectionSetOwner(u8 *context, void *value);
    extern void btlUiSelectEffect(s32 context, u32 value);
    extern void btlSelectionResetState(u8 *context, u8 *value);
    extern u16 btlSelectionHandleSkillInput(u8 *context, u8 *value);
    extern void btlSelectionDrawSkillPanel(u8 *context, s32 value, f32 *option);
    extern void btlSelectionStepAnim(u8 *context, u8 *value, f32 *option);
    extern void btlSelectionSaveCursorSecond(u8 *context, u8 *value);
    extern void btlSelectionResetPageState(u8 *context, u8 *value);
    extern u16 btlSelectionHandleItemInput(u8 *context, u8 *value);
    extern void btlSelectionDrawItemPanel(u8 *context, s32 value, f32 *option);
    extern void btlSelectionStepItemAnim(u8 *context, u8 *value, f32 *option);
    extern void btlSelectionSaveCursorThird(u8 *context, u8 *value);
    extern void btlSelectionResetSubListState(u8 *context, u8 *value);
    extern u16 btlSelectionOpenSubList(u8 *context, s32 value, u8 **option);
    extern void btlSelectionDrawTitle(u8 *context, u8 *value, f32 *option);
    extern void btlSelectionDrawPersonaList(u8 *context, u8 *value, f32 *option);
    extern void btlSelectionSaveCursorFourth(u8 *context, u8 *value);
    extern void btlSelectionResetCursorState(u16 *context, u8 *value);
    extern u16 btlSelectionHandleSwapInput(u8 *context, u8 *value);
    extern void btlSelectionDrawSwapPanel(u8 *context, u8 *value, f32 *option);
    extern void btlSelectionDrawLevelList(s32 context, u8 *value, f32 *option);
    extern void btlSelectionEndSwapList(void);
    u8 *work;
    u8 *panel;
    u8 *action;
    u8 *unit;
    s32 input;
    s16 subAction;
    s32 partyCount;

    work = (u8 *)(u32)workAddress;
    if (((BtlPanelWork *)((BtlUiTaskWork *)(u32)kwlnTaskGetWork(*(void **)(work + 0x5B0)))->panel)->commandFrame < 2) {
        return 1;
    }
    if (*(s16 *)(work + 0x14) != 0) {
        return 1;
    }
    input = btlSelectionReadInput(selection) & 0xFFFF;
    if (input == 1) {
    if (*(s16 *)(selection + 4) != 3) {
        sdkSndStartStream(0, 0, 0, 2);
    }
    ((BtlSelection *)selection)->selected = 3;
    ((BtlSelection *)selection)->first = 0;
    } else if (input == 4) {
    if (func_001f0620(*(u8 **)(work + 0x178), 0xA) == 0) {
        return 1;
    }
    sdkSndStartStream(0, 0, 0, 3);
    ((BtlAction *)*(u8 **)(work + 0x178))->unk_6c = 0xA;
    if (datGetFlag(0x38) != 0) {
        subAction = 0x10B;
    } else {
        subAction = 0x110;
    }
    ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6e = subAction;
    return 4;
    } else if (input == 5) {
    ((BtlPanelWork *)work)->cursorSlide = -3;
    } else if (input == 6) {
    ((BtlPanelWork *)work)->cursorSlide = 3;
    } else if (input == 2) {
    switch (((BtlSelection *)selection)->selected) {
    case 3:
        if (func_001f0620(((BtlPanelWork *)work)->action, 1) == 0) {
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6c = 1;
        ((BtlAction *)*(u8 **)(work + 0x178))->unk_6e =
            datCalcDefaultSkillId((u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit->datUnit);
        break;
    case 4:
        if (func_001f0620(*(u8 **)(work + 0x178), 2) == 0) {
            if (datCalcChkBadStatus((DatUnit *)((BtlAction *)*(u8 **)(work + 0x178))->unit->datUnit, 8) != 0) {
                btlUiSelectEffect((s32)(u32)(u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit, 0x90);
            }
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        datPersonaGetRecord(((BtlAction *)((BtlPanelWork *)work)->action)->unit->charId);
        btlSelectionInit(work + 0x74, 4, *(s16 *)(work + 0x1A4), btlSelectionResetState,
                      btlSelectionHandleSkillInput, btlSelectionDrawSkillPanel, btlSelectionSaveCursorSecond, work);
        panel = work + 0x74;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionStepAnim);
        ((BtlPanelWork *)work)->gridFrame = 0;
        ((BtlPanelWork *)work)->flags = ((BtlPanelWork *)work)->flags & ~4;
        return 3;
    case 6:
        if (func_001f0620(*(u8 **)(work + 0x178), 3) == 0 || *(s16 *)(work + 0x5A6) == 0) {
            if ((s16)((BtlPanelWork *)work)->itemCount == 0) {
                btlUiSelectEffect((s32)(u32)(u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit, 0x92);
            }
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        btlSelectionInit(work + 0xA8, 4, ((BtlPanelWork *)work)->itemCount, btlSelectionResetPageState, btlSelectionHandleItemInput,
                      btlSelectionDrawItemPanel, btlSelectionSaveCursorThird, work);
        panel = work + 0xA8;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionStepItemAnim);
        ((BtlPanelWork *)work)->gridFrame = 0;
        ((BtlPanelWork *)work)->flags = ((BtlPanelWork *)work)->flags & ~4;
        return 3;
    case 1:
        if (func_001f0620(*(u8 **)(work + 0x178), 4) == 0) {
            if ((s32)(func_001ef720(1, 0) & 0xFFFF) < 2) {
                btlUiSelectEffect((s32)(u32)(u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit, 0x93);
            }
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        partyCount = 0;
        for (unit = ((BtlBattleState *)iGpffffb3ac)->unitLists[1]; unit != NULL; unit = (u8 *)((BtlUnit *)unit)->prevUnit) {
            if (((BtlUnit *)unit)->charId != 1) {
                ((BtlPanelWork *)work)->partyUnits[partyCount & 0xFFFF] = unit;
                partyCount = (partyCount + 1) & 0xFFFF;
            }
        }
        ((BtlPanelWork *)work)->partyCount = partyCount;
        btlSelectionInit(work + 0xDC, 3, (s16)partyCount, btlSelectionResetSubListState, btlSelectionOpenSubList,
                      btlSelectionDrawTitle, btlSelectionSaveCursorFourth, work);
        panel = work + 0xDC;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionDrawPersonaList);
        ((BtlPanelWork *)work)->gridFrame = 0;
        ((BtlPanelWork *)work)->flags = ((BtlPanelWork *)work)->flags & ~4;
        return 3;
    case 5:
        if (func_001f0620(*(u8 **)(work + 0x178), 5) == 0) {
            if (datCalcChkBadStatus((DatUnit *)((BtlAction *)*(u8 **)(work + 0x178))->unit->datUnit, 8) != 0) {
                btlUiSelectEffect((s32)(u32)(u8 *)((BtlAction *)((BtlPanelWork *)work)->action)->unit, 0x91);
            } else {
                action = ((BtlPanelWork *)work)->action;
                if (!(((BtlAction *)action)->flags & 0x400)) {
                    btlUiSelectEffect((s32)(u32)(u8 *)((BtlAction *)action)->unit, 0x95);
                }
            }
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        ((BtlPanelWork *)work)->personaTask = shdPersonaTaskCreate(((BtlPanelWork *)work)->task, 0xF, 1, 8, 8);
        ((BtlPanelWork *)work)->personaSlot = -1;
        btlSelectionInit(work + 0x144, 4, (s16)datPersonaCountValidMembers(), btlSelectionResetCursorState,
                      btlSelectionHandleSwapInput, btlSelectionDrawSwapPanel, btlSelectionEndSwapList, work);
        panel = work + 0x144;
        *nextPanel = panel;
        btlSelectionSetOwner(panel, btlSelectionDrawLevelList);
        ((BtlPanelWork *)work)->gridFrame = 0;
        ((BtlPanelWork *)work)->flags = ((BtlPanelWork *)work)->flags & ~4;
        return 3;
    case 7:
        if (func_001f0620(*(u8 **)(work + 0x178), 6) == 0) {
            btlActionRunTargetCallback((s32)(u32)((BtlPanelWork *)work)->action, 5, 0, 0, 2);
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6c = 6;
        ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6e = 0;
        break;
    case 2:
        if (func_001f0620(((BtlPanelWork *)work)->action, 7) == 0) {
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6c = 7;
        ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6e = 0;
        break;
    case 0:
        if (func_001f0620(*(u8 **)(work + 0x178), 0xA) == 0) {
            sdkSndStartStream(0, 0xF, 0, 8);
            return 1;
        }
        sdkSndStartStream(0, 0, 0, 3);
        ((BtlAction *)*(u8 **)(work + 0x178))->unk_6c = 0xA;
        if (datGetFlag(0x38) != 0) {
            subAction = 0x10B;
        } else {
            subAction = 0x110;
        }
        ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6e = subAction;
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
/* measured: typing the remaining circle/cursor counter reads independently lost MATCH; their
 * stores and the other panel fields remain typed. */
void btlSelectionDrawCommands(u8 *selection, s32 workAddress, u8 *drawState)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern s32 func_001f0620(u8 *selection, s64 work);
    extern s32 func_001eb860(void);
    extern f64 fptodp(f32 value);
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
    BtlPanelRenderDispatch *renderer;
    f32 translationX;
    struct {
        Vec2f center;
        f32 progress;
    } circle;

    work = (u8 *)(u32)workAddress;
    origin = (f32 *)drawState;
    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)work)->task);
    menuFlags = ((BtlBattleState *)iGpffffb3ac)->flags & 0x10000;
    if (((BtlPanelWork *)work)->list.current != work + 0x40 || *(u16 *)work != 1 || menuFlags != 0) {
        rotationProgress = (f32)((BtlPanelWork *)work)->stripFrame / 6.0f;
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
    renderer = (BtlPanelRenderDispatch *)D_00887300;
    renderer->setState(8, 1);
    renderer->setState(1, 0);
    {
        f32 outlineGrowth;
        f32 t;
        f32 u;
        if ((s16)(*(s16 *)(work + 0xC) - 2) < 2) {
            t = (f32)(s16)(((BtlPanelWork *)work)->circleFrame - 2) / 2.0f;
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
        shdDrawRadialFan(position, 150.0f, color.word, color.word, outlineGrowth * 81.0f, 0.0f, 0x30, 1.0f, 1.0f, 1);
    }
    if (((BtlPanelWork *)work)->circleFrame < 2) {
        f32 t;
        f32 u;
        t = (f32)((BtlPanelWork *)work)->circleFrame / 2.0f;
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
        shdDrawRadialFan(position, 150.0f, color.word, color.word, radius, 0.0f, 0x30, 1.0f, 1.0f, 1);
        color.bytes.c3 = 0;
        shdDrawRadialFan(position, 150.0f, color.word, color.word, radius + 1.0f, 0.0f, 0x30, 1.0f, 1.0f, 1);
    }
    renderer = (BtlPanelRenderDispatch *)D_00887300;
    renderer->setState(8, 0);
    renderer->setState(6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    if (showCommands != 0) {
        f32 t;
        u8 drawOpacity;
        t = (f32)((BtlPanelWork *)work)->commandFrame / 2.0f;
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
                available = func_001f0620(((BtlPanelWork *)work)->action, D_00626BD0[command]);
                if (available != 0 && (command != 6 || (s16)((BtlPanelWork *)work)->itemCount > 0)) {
                    tone = 0x1B;
                } else {
                    tone = 0x96;
                }
                func_0044b310(fptodp((f32)((BtlPanelWork *)work)->cursorSlide / 3.0f));
                btlUiDrawSpriteFaded(glyphs, 9, command + 8, 52.0f, rowY - completeProgress, tone, tone, tone, drawOpacity);
                rowY += 15.0f;
            }
            selectedCommand = ((BtlSelection *)selection)->selected;
            renderer = (BtlPanelRenderDispatch *)D_00887300;
            renderer->setState(6, 1);
            btlPanelDrawStrip(3, translationX, ((f32)selectedCommand - 3.0f) * 15.0f + offsetY, 110.0f, 0.0f, 0);
            renderer->setState(6, 0);
            if ((u8)opacity == 0xFF) {
                u8 red;
                u8 green;
                u8 blue;
                available = func_001f0620(((BtlPanelWork *)work)->action, D_00626BD0[selectedCommand]);
                if (available != 0 && (selectedCommand != 6 || (s16)((BtlPanelWork *)work)->itemCount > 0)) {
                    red = 0xFE;
                    green = 0xFF;
                    blue = 0x22;
                } else {
                    red = 0x62;
                    green = 0x62;
                    blue = 0x62;
                }
                btlUiDrawSpriteFaded(glyphs, 9, selectedCommand, 33.0f, (f32)selectedCommand * 15.0f + 258.0f, red, green, blue, 0xFF);
                btlUiDrawSpriteEntry(glyphs, 9, selectedCommand + 0x10, 196.0f - translationX, ((f32)0x19B - offsetY) - completeProgress);
            }
        } else {
            renderer = (BtlPanelRenderDispatch *)D_00887300;
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
        BtlPanelRenderDispatch *modeRenderer;
        /* This phase acquires the table independently of earlier circle draws. */
        modeRenderer = (BtlPanelRenderDispatch *)D_00887300;
        btlPanelDrawExtendedStrip(modeRenderer, translationX, offsetY, rotationProgress);
        if (menuFlags == 0) {
            s32 showHints;
            if (*(u16 *)work == 2 && ((BtlAction *)((BtlPanelWork *)work)->action)->unk_6c == 10) {
                selectedCommand = 0;
            } else {
                selectedCommand = ((BtlSelection *)selection)->selected;
            }
            switch (selectedCommand) {
            case 3:
                btlUiSetOrigin(glyphs, origin[0], origin[1]);
                btlUiDrawSpriteFaded(glyphs, 9, 0x20, 75.0f, 317.0f, 0x1B, 0x1B, 0x1B, 0xFF);
                renderer = (BtlPanelRenderDispatch *)D_00887300;
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
                renderer = (BtlPanelRenderDispatch *)D_00887300;
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
        ((BtlPanelWork *)work)->cursorSlide = available - 1;
        return;
    }
    if (available < 0) {
        ((BtlPanelWork *)work)->cursorSlide = available + 1;
    }
}

/* measured: the float argument to PrimDrawFlatRectangle is 0.0f - retail only ever clears
   $f12, and that hoisted zero is also the `<= 0.0f` compare operand and the
   accumulator seed of the adda.s/madd.s (the old archive passed temp_f4, nd10). */
// Intent: draw the selection's progress bar, scaled by the eased progress. [inferred]
// FUN_00208870
void btlSelectionDrawBar(u8 *unused, u8 *panel, f32 *origin)
{
    s32 values[4];
    Color4 color;
    f32 progress;
    f32 clamped;
    f32 eased;
    f32 top;

    btlUiSetOrigin((u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task), origin[0], origin[1]);
    progress = (f32)((BtlPanelWork *)panel)->commandFrame / 2.0f;
    if (progress > 1.0f) {
        clamped = 1.0f;
    } else if (progress < 0.0f) {
        clamped = 0.0f;
    } else {
        clamped = progress;
    }
    eased = clamped * 2.0f - clamped * clamped;
    if (eased <= 0.0f) {
        return;
    }
    color.c0 = 0xB4;
    color.c1 = 0;
    color.c2 = 0;
    color.c3 = 0xFF;
    values[0] = -10;
    top = (1.0f - eased) * 11.0f + 410.0f;
    values[1] = (s32)top;
    values[2] = 0x294;
    values[3] = (s32)(eased * 22.0f);
    PrimDrawFlatRectangle((u8 *)&color, (f32 *)values, 0.0f, 0);
}

// Intent: save the selected row and page to the cursor record when the flag is set. [inferred]
// FUN_002089E0
/* The action+0x3F0 cursor pointer remains raw: its union with target storage is not described by
 * the shared action type. measured: typing the remaining parent-action read independently lost
 * MATCH. */
void btlSelectionSaveCursor(u8 *selection, u8 *panel)
{
    s16 *cursor;

    if (datGetFlag(60) == 0) {
        return;
    }
    cursor = *(s16 **)(*(u8 **)(panel + 376) + 1008);
    if (cursor == NULL) {
        return;
    }
    cursor[1] = ((BtlSelection *)selection)->selected;
    (*(s16 **)(((BtlPanelWork *)panel)->action + 1008))[0] = ((BtlSelection *)selection)->first;
}

// Intent: reset the selection flags and cursor state to the top of the list. [inferred]
// FUN_00208A50
/* The +0x3F0 saved-cursor pointer remains raw because the shared action layout does not establish
 * its union with target storage; the cursor record itself is typed. */
void btlSelectionResetState(u8 *selection, u8 *panel)
{
    u8 *cursor;

    sdkSndStartStream(0, 0, 0, 3);
    if (datGetFlag(0x3C) != 0) {
        cursor = *(u8 **)(((BtlPanelWork *)panel)->action + 0x3F0);
        if (cursor != NULL) {
            btlSelectionUpdateWindow(selection, ((BtlSelectionCursorRecord *)cursor)->slots[1].selected, ((BtlSelectionCursorRecord *)cursor)->slots[1].first);
        }
    }
    *(u16 *)selection |= 1;
    *(u16 *)selection |= 2;
    ((BtlPanelWork *)panel)->clipFrame = 0;
    ((BtlPanelWork *)panel)->titleFrame = 0;
    ((BtlPanelWork *)panel)->listFrame = 0;
    ((BtlPanelWork *)panel)->detailFrame = 0;
}

/* 500/512 bytes; twelve zero alignment bytes.
 * The shared four-byte record type preserves the flags-table load order. */
// Intent: handle the skill list input and return the next state (confirm, cancel or toggle). [inferred]
// FUN_00208B00
/* measured: typed skill indexing changed two compared bytes; independently typing the remaining
 * action/unit/flags reads also lost MATCH. Preserve these byte-cursor accesses. */
u16 btlSelectionHandleSkillInput(u8 *selection, u8 *panel)
{
    extern s32 datCalcThresholdTrigger(u8 *selection, s32 panel);
    extern s32 datCalcUsesWeaponProperties(s32 selection);
    s32 flags;
    u16 result;
    u16 skill;
    s32 skillOffset;

    result = btlSelectionReadInput(selection) & 0xFFFF;
    switch (result) {
    case 2:
        skillOffset = (s32)((BtlSelection *)selection)->selected * 2;
        skill = *(u16 *)(skillOffset + (u32)panel + 0x194);
        if (datCalcThresholdTrigger(*(u8 **)(*(u8 **)(*(u8 **)(panel + 0x178) +
                                           0x30) + 0xA64),
                          skill) == 0) {
            if ((datCalcUsesWeaponProperties(skill) != 0) &&
                ((iGpffffb3bc[skill & 0xFFFF].flags & 0x8000) == 0)) {
                ((BtlAction *)*(u8 **)(panel + 0x178))->unk_6c = 1;
            } else {
                ((BtlAction *)((BtlPanelWork *)panel)->action)->unk_6c = 2;
            }
            ((BtlAction *)((BtlPanelWork *)panel)->action)->unk_6e = skill;
            ((BtlPanelWork *)panel)->slideFrame = 0;
            result = 4;
        } else {
            sdkSndStartStream(0, 15, 0, 8);
            result = 1;
        }
        break;
    case 3:
        flags = ((BtlPanelWork *)panel)->flags ^ 4;
        ((BtlPanelWork *)panel)->flags = flags;
        if ((flags & 4) != 0) {
            sdkSndStartStream(1, 13, 2, 23);
        } else {
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(panel + 4) & 4) != 0) {
            sdkSndStartStream(0, 0, 0, 2);
            ((BtlPanelWork *)panel)->flags &= ~4;
            result = 1;
        } else {
            sdkSndStartStream(0, 0, 0, 4);
            result = 2;
        }
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

/* 716/720 bytes; eighteen resolved relocations and four zero alignment bytes.
 * btlListDispatchUpdate forwards the signed state word at node+0x28. Convert that
 * real input to a pointer here; a pointer parameter swaps two entry moves. */
// Intent: draw the skill panel and advance its slide-in timer. [inferred]
// FUN_00208D00
/* measured: typing the slide-counter read at panel+0x1A independently lost MATCH; its update store remains typed. */
void btlSelectionDrawSkillPanel(u8 *selection, s32 panelAddress, f32 *originOrRenderer)
{
    u8 *state = (u8 *)panelAddress;
    u8 *glyphs;
    s16 slideFrame;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)state)->task);
    btlUiSetOrigin(glyphs, originOrRenderer[0], originOrRenderer[1]);
    if (*(u16 *)state == 2) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x49, 77.0f, 314.0f, 0xFE, 0xFF, 0x22, 0xFF);
        btlUiDrawSpriteFaded(glyphs, 9, 0x4A, 93.0f, 314.0f, 0x1B, 0x1B, 0x1B, 0xFF);
        btlSelectionDrawSlideIn(state, selection, originOrRenderer[0], originOrRenderer[1], btlPanelDrawSkillEntry);
    } else {
        btlUiDrawSpriteFaded(glyphs, 9, 0x21, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    originOrRenderer = (f32 *)D_00887300;
    ((void (**)(u32, u32))originOrRenderer)[0](6, 1);
    btlUiSetAlpha(glyphs, 120.0f);
    btlUiDrawSpriteFaded(glyphs, 9, 0x37, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))originOrRenderer)[0](6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    slideFrame = *(s16 *)(state + 0x1A);
    if (slideFrame < 4) {
        ((BtlPanelWork *)state)->slideFrame = slideFrame + 1;
    }
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(glyphs, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: advance the selection's animation counters, clamped to their limits. [inferred]
// FUN_00208FD0
/* measured: independently typing the remaining +0x16/+0x18/+0x20/+0x22 counter reads lost MATCH;
 * their update stores remain typed. */
void btlSelectionStepAnim(u8 *selection, u8 *panel, f32 *origin)
{
    s16 clipFrame;
    s16 titleFrame;
    s16 openingListFrame;
    s16 openingDetailFrame;
    s16 closingListFrame;
    s16 closingDetailFrame;

    if (((BtlPanelWork *)panel)->previousState != 2) {
        btlSelectionDrawList(panel, selection, origin[0], origin[1], btlPanelDrawSkillEntry);
    }
    clipFrame = *(s16 *)(panel + 0x20);
    if (clipFrame < 4) {
        ((BtlPanelWork *)panel)->clipFrame = clipFrame + 1;
    }
    titleFrame = *(s16 *)(panel + 0x22);
    if (titleFrame < 0xA) {
        ((BtlPanelWork *)panel)->titleFrame = titleFrame + 1;
    }
    if ((((BtlPanelWork *)panel)->flags & 4) != 0) {
        openingListFrame = *(s16 *)(panel + 0x16);
        if (openingListFrame < 4) {
            ((BtlPanelWork *)panel)->listFrame = openingListFrame + 1;
        }
        openingDetailFrame = *(s16 *)(panel + 0x18);
        if (openingDetailFrame < 7) {
            ((BtlPanelWork *)panel)->detailFrame = openingDetailFrame + 1;
        }
    } else {
        closingListFrame = *(s16 *)(panel + 0x16);
        if (closingListFrame > 0) {
            ((BtlPanelWork *)panel)->listFrame = closingListFrame - 1;
        }
        closingDetailFrame = *(s16 *)(panel + 0x18);
        if (closingDetailFrame > 0) {
            ((BtlPanelWork *)panel)->detailFrame = closingDetailFrame - 1;
        }
    }
}

// Intent: save the selected row and page to the second cursor slot when the flag is set. [inferred]
// FUN_002090D0
/* The action+0x3F0 cursor pointer remains raw: its union with target storage is not described by
 * the shared action type. measured: typing the remaining parent-action read independently lost
 * MATCH. */
void btlSelectionSaveCursorSecond(u8 *selection, u8 *panel)
{
    s16 *cursor;

    if (datGetFlag(60) == 0) {
        return;
    }
    cursor = *(s16 **)(*(u8 **)(panel + 376) + 1008);
    if (cursor == NULL) {
        return;
    }
    cursor[3] = ((BtlSelection *)selection)->selected;
    (*(s16 **)(((BtlPanelWork *)panel)->action + 1008))[2] = ((BtlSelection *)selection)->first;
}

// Intent: reset the selection flags, page window and counters for the list. [inferred]
// FUN_00209140
/* The +0x3F0 saved-cursor pointer remains raw because the shared action layout does not establish
 * its union with target storage; the cursor record itself is typed. */
void btlSelectionResetPageState(u8 *selection, u8 *panel)
{
    u8 *cursor;

    sdkSndStartStream(0, 0, 0, 3);
    if (datGetFlag(0x3C) != 0) {
        cursor = *(u8 **)(((BtlPanelWork *)panel)->action + 0x3F0);
        if (cursor != NULL) {
            btlSelectionUpdateWindow(selection, ((BtlSelectionCursorRecord *)cursor)->slots[2].selected, ((BtlSelectionCursorRecord *)cursor)->slots[2].first);
        }
    }
    *(u16 *)selection |= 1;
    *(u16 *)selection |= 2;
    ((BtlPanelWork *)panel)->clipFrame = 0;
    ((BtlPanelWork *)panel)->titleFrame = 0;
    ((BtlPanelWork *)panel)->listFrame = 0;
    ((BtlPanelWork *)panel)->detailFrame = 0;
}

/* Reconstructed state dispatch and return width; candidate is byte-exact. */
// Intent: handle the item list input and return the next state. [inferred]
// FUN_002091F0
/* measured: typed item indexing changed two compared bytes; typing the remaining action/flags
 * reads independently also lost MATCH. */
u16 btlSelectionHandleItemInput(u8 *selection, u8 *panel)
{
    s32 itemOrFlags;
    u16 result;

    result = btlSelectionReadInput(selection) & 0xFFFF;
    switch (result) {
    case 2:
        ((BtlAction *)((BtlPanelWork *)panel)->action)->unk_6c = 3;
        itemOrFlags = *(s16 *)(btlSelectionAddByteOffset((u32)(((BtlSelection *)selection)->selected * 4), panel) + 0x1A6);
        ((BtlPanelActionChoice *)((BtlAction *)((BtlPanelWork *)panel)->action)->unk_70)->item = itemOrFlags;
        ((BtlAction *)*(u8 **)(panel + 0x178))->unk_6e =
            datCalcUnderlyingSkillId(((BtlPanelActionChoice *)((BtlAction *)((BtlPanelWork *)panel)->action)->unk_70)->item);
        ((BtlPanelWork *)panel)->slideFrame = 0;
        result = 4;
        break;
    case 3:
        itemOrFlags = ((BtlPanelWork *)panel)->flags ^ 4;
        ((BtlPanelWork *)panel)->flags = itemOrFlags;
        if ((itemOrFlags & 4) != 0) {
            sdkSndStartStream(1, 0xD, 2, 0x17);
        } else {
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    case 1:
        if ((*(s32 *)(panel + 4) & 4) != 0) {
            sdkSndStartStream(0, 0, 0, 2);
            ((BtlPanelWork *)panel)->flags &= ~4;
            result = 1;
        } else {
            sdkSndStartStream(0, 0, 0, 4);
            result = 2;
        }
        break;
    default:
        result = 1;
        break;
    }
    return result;
}

/* 716/720 bytes; eighteen resolved relocations and four zero alignment bytes.
 * btlListDispatchUpdate forwards the signed state word at node+0x28. Convert that
 * input locally; preserve the position and callback-table reloads. */
// Intent: draw the item panel and advance its slide-in timer. [inferred]
// FUN_00209370
/* measured: typing the slide-counter read at panel+0x1A independently lost MATCH; its update store remains typed. */
void btlSelectionDrawItemPanel(u8 *selection, s32 panelAddress, f32 *originOrRenderer)
{
    u8 *state = (u8 *)panelAddress;
    u8 *glyphs;
    s16 slideFrame;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)state)->task);
    btlUiSetOrigin(glyphs, originOrRenderer[0], originOrRenderer[1]);
    if (*(u16 *)state == 2) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x49, 77.0f, 314.0f, 0xFE, 0xFF, 0x22, 0xFF);
        btlUiDrawSpriteFaded(glyphs, 9, 0x4A, 93.0f, 314.0f, 0x1B, 0x1B, 0x1B, 0xFF);
        btlSelectionDrawSlideIn(state, selection, originOrRenderer[0], originOrRenderer[1], btlPanelDrawEntry);
    } else {
        btlUiDrawSpriteFaded(glyphs, 9, 0x23, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    }
    originOrRenderer = (f32 *)D_00887300;
    ((void (**)(u32, u32))originOrRenderer)[0](6, 1);
    btlUiSetAlpha(glyphs, 120.0f);
    btlUiDrawSpriteFaded(glyphs, 9, 0x39, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))originOrRenderer)[0](6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    slideFrame = *(s16 *)(state + 0x1A);
    if (slideFrame < 4) {
        ((BtlPanelWork *)state)->slideFrame = slideFrame + 1;
    }
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(glyphs, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: advance the item list animation counters, clamped to their limits. [inferred]
// FUN_00209640
/* measured: independently typing the remaining +0x16/+0x18/+0x20/+0x22 counter reads lost MATCH;
 * their update stores remain typed. */
void btlSelectionStepItemAnim(u8 *selection, u8 *panel, f32 *origin)
{
    s16 clipFrame;
    s16 titleFrame;
    s16 openingListFrame;
    s16 openingDetailFrame;
    s16 closingListFrame;
    s16 closingDetailFrame;

    if (((BtlPanelWork *)panel)->previousState != 2) {
        btlSelectionDrawList(panel, selection, origin[0], origin[1],
                      btlPanelDrawEntry);
        clipFrame = *(s16 *)(panel + 0x20);
        if (clipFrame < 4) {
            ((BtlPanelWork *)panel)->clipFrame = clipFrame + 1;
        }
        titleFrame = *(s16 *)(panel + 0x22);
        if (titleFrame < 0xA) {
            ((BtlPanelWork *)panel)->titleFrame = titleFrame + 1;
        }
        if ((((BtlPanelWork *)panel)->flags & 4) != 0) {
            openingListFrame = *(s16 *)(panel + 0x16);
            if (openingListFrame < 4) {
                ((BtlPanelWork *)panel)->listFrame = openingListFrame + 1;
            }
            openingDetailFrame = *(s16 *)(panel + 0x18);
            if (openingDetailFrame < 7) {
                ((BtlPanelWork *)panel)->detailFrame = openingDetailFrame + 1;
            }
        } else {
            closingListFrame = *(s16 *)(panel + 0x16);
            if (closingListFrame > 0) {
                ((BtlPanelWork *)panel)->listFrame = closingListFrame - 1;
            }
            closingDetailFrame = *(s16 *)(panel + 0x18);
            if (closingDetailFrame > 0) {
                ((BtlPanelWork *)panel)->detailFrame = closingDetailFrame - 1;
            }
        }
    }
}

// Intent: save the selected row and page to the third cursor slot when the flag is set. [inferred]
// FUN_00209740
/* The action+0x3F0 cursor pointer remains raw: its union with target storage is not described by
 * the shared action type. measured: typing the remaining parent-action read independently lost
 * MATCH. */
void btlSelectionSaveCursorThird(u8 *selection, u8 *panel)
{
    s16 *cursor;

    if (datGetFlag(60) == 0) {
        return;
    }
    cursor = *(s16 **)(*(u8 **)(panel + 376) + 1008);
    if (cursor == NULL) {
        return;
    }
    cursor[5] = ((BtlSelection *)selection)->selected;
    (*(s16 **)(((BtlPanelWork *)panel)->action + 1008))[4] = ((BtlSelection *)selection)->first;
}

// Intent: reset the sub-list window and counters when the sub-list is not active. [inferred]
// FUN_002097B0
/* The +0x3F0 cursor pointer remains raw because the shared action layout does not establish its
 * union with target storage. measured: typing the previous-node address comparison independently
 * lost MATCH. */
void btlSelectionResetSubListState(u8 *selection, u8 *panel)
{
    u8 *cursor;

    if (datGetFlag(0x3C) != 0) {
        cursor = *(u8 **)(((BtlPanelWork *)panel)->action + 0x3F0);
        if (cursor != NULL) {
            btlSelectionUpdateWindow(selection, ((BtlSelectionCursorRecord *)cursor)->slots[3].selected, ((BtlSelectionCursorRecord *)cursor)->slots[3].first);
        }
    }
    *(u16 *)selection |= 1;
    *(u16 *)selection |= 2;
    if (*(s32 *)(panel + 0x3C) != (s32)(panel + 0x110)) {
        sdkSndStartStream(0, 0, 0, 3);
        ((BtlPanelWork *)panel)->clipFrame = 0;
        ((BtlPanelWork *)panel)->titleFrame = 0;
        ((BtlPanelWork *)panel)->listFrame = 0;
        ((BtlPanelWork *)panel)->detailFrame = 0;
    }
}

// Intent: handle the persona sub-list input and open the sub-list selection. [inferred]
// FUN_00209870
/* measured: typed party-unit indexing changed two compared bytes; retain the index-before-base byte-offset helper. */
u16 btlSelectionOpenSubList(u8 *selection, s32 panelAddress, u8 **nextPanel)
{
    u16 input;
    u16 count;
    u16 result;
    u8 **out;
    u8 *base;
    u8 *unit;
    u8 *subList;

    out = (u8 **)nextPanel;
    base = (u8 *)(u32)panelAddress;
    input = btlSelectionReadInput(selection) & 0xFFFF;
    switch (input) {
    case 2:
        unit = *(u8 **)(btlSelectionAddByteOffset(
            (u32)(((BtlSelection *)selection)->selected * 4), base) + 0x17C);
        ((BtlPanelWork *)base)->selectedUnit = unit;
        if ((cmmCommunityRecordValue(cmmCommunityForArcana((s16)((BtlUnit *)unit)->charId) &
                           0xFFFF) & 0xFFFF) >= 0) {
            count = 5;
        } else {
            count = 4;
        }
        btlSelectionInit(base + 0x110, 4, (s16)count,
                      (void *)btlSelectionResetSubList, (void *)btlSelectionConfirmSubList,
                      (void *)btlSelectionDrawSubList, (void *)btlSelectionEndSubList, base);
        subList = base + 0x110;
        *out = subList;
        btlSelectionSetOwner(subList, (void *)btlSelectionDrawCurrentLabel);
        ((BtlPanelWork *)base)->flags &= ~4;
        return 3;
    case 1:
        sdkSndStartStream(0, 0, 0, 4);
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
void btlSelectionDrawTitle(u8 *selection, u8 *panel, f32 *originOrRenderer)
{
    u8 *glyphs;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task);
    btlUiSetOrigin(glyphs, originOrRenderer[0], originOrRenderer[1]);
    btlUiDrawSpriteFaded(glyphs, 9, 0x1F, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    originOrRenderer = (f32 *)D_00887300;
    ((void (**)(u32, u32))originOrRenderer)[0](6, 1);
    btlUiSetAlpha(glyphs, 120.0f);
    btlUiDrawSpriteFaded(glyphs, 9, 0x35, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))originOrRenderer)[0](6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(glyphs, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: draw the persona name list when the sub-list is open, and step its counters. [inferred]
// FUN_00209BC0
/* measured: independently typing the remaining +0x16/+0x18/+0x20/+0x22 counter reads lost MATCH;
 * their update stores remain typed. */
void btlSelectionDrawPersonaList(u8 *selection, u8 *panel, f32 *origin)
{
    s16 clipFrame;
    s16 titleFrame;
    s16 openingListFrame;
    s16 openingDetailFrame;
    s16 closingListFrame;
    s16 closingDetailFrame;

    if (((BtlPanelWork *)panel)->list.current == panel + 0xDC) {
        if (*(u16 *)panel != 2) {
            btlSelectionDrawList(panel, selection, origin[0], origin[1],
                          btlPanelDrawPersonaName);
        }
        clipFrame = *(s16 *)(panel + 0x20);
        if (clipFrame < 4) {
            ((BtlPanelWork *)panel)->clipFrame = clipFrame + 1;
        }
        titleFrame = *(s16 *)(panel + 0x22);
        if (titleFrame < 0xA) {
            ((BtlPanelWork *)panel)->titleFrame = titleFrame + 1;
        }
        if ((((BtlPanelWork *)panel)->flags & 4) != 0) {
            openingListFrame = *(s16 *)(panel + 0x16);
            if (openingListFrame < 4) {
                ((BtlPanelWork *)panel)->listFrame = openingListFrame + 1;
            }
            openingDetailFrame = *(s16 *)(panel + 0x18);
            if (openingDetailFrame < 7) {
                ((BtlPanelWork *)panel)->detailFrame = openingDetailFrame + 1;
            }
        } else {
            closingListFrame = *(s16 *)(panel + 0x16);
            if (closingListFrame > 0) {
                ((BtlPanelWork *)panel)->listFrame = closingListFrame - 1;
            }
            closingDetailFrame = *(s16 *)(panel + 0x18);
            if (closingDetailFrame > 0) {
                ((BtlPanelWork *)panel)->detailFrame = closingDetailFrame - 1;
            }
        }
    }
}

// Intent: save the selected row and page to the fourth cursor slot when the flag is set. [inferred]
// FUN_00209CD0
/* The action+0x3F0 cursor pointer remains raw: its union with target storage is not described by
 * the shared action type. measured: typing the remaining parent-action read independently lost
 * MATCH. */
void btlSelectionSaveCursorFourth(u8 *selection, u8 *panel)
{
    s16 *cursor;

    if (datGetFlag(60) == 0) {
        return;
    }
    cursor = *(s16 **)(*(u8 **)(panel + 376) + 1008);
    if (cursor == NULL) {
        return;
    }
    cursor[7] = ((BtlSelection *)selection)->selected;
    (*(s16 **)(((BtlPanelWork *)panel)->action + 1008))[6] = ((BtlSelection *)selection)->first;
}

// Intent: reset the sub-list cursor fields and window. [inferred]
// FUN_00209D40
void btlSelectionResetSubList(u8 *selection, u8 *panel)
{
    sdkSndStartStream(0, 0, 0, 3);
    btlSelectionUpdateWindow(selection, 0, 0);
    *(u16 *)selection |= 1;
    *(u16 *)selection |= 2;
    ((BtlPanelWork *)panel)->labelFrame = 0;
    ((BtlPanelWork *)panel)->labelTitleFrame = 0;
}

// Intent: handle the sub-list input, store the chosen value and enqueue its packet. [inferred]
// FUN_00209DC0
/* measured: independently typing the remaining selected-row, selected-unit and flags reads lost
 * MATCH; preserve their byte-addressed loads. */
u16 btlSelectionConfirmSubList(u8 *selection, u8 *panel)
{
    extern s16 datGetUnitAiTactic(s16 selection);
    extern void datSetUnitAiTactic(s16 selection, s16 panel);
    extern u8 *btlActionFindByUnit(s32 selection);
    extern u8 *func_001f99c0(u8 *selection, u16 panel, s32 option, s32 flags,
                              s32 extra);
    extern s64 btlPacketEnqueue(u8 *selection, u32 panel);
    s16 selected;
    u8 *action;
    s32 toggledFlags;
    s32 flags;
    u16 result;

    result = btlSelectionReadInput(selection) & 0xFFFF;
    switch (result) {
    case 2:
        selected = *(s16 *)(selection + 4);
        if (selected !=
            datGetUnitAiTactic(*(s16 *)(*(u8 **)(panel + 0x190) + 0xA4))) {
            datSetUnitAiTactic(
                (s16)((BtlUnit *)((BtlPanelWork *)panel)->selectedUnit)->charId, selected);
            action = btlActionFindByUnit(*(s32 *)(panel + 0x190));
            if (action != NULL) {
                btlPacketEnqueue(
                    func_001f99c0(action, 2, ((BtlSelection *)selection)->selected, 0, 0), 1);
            }
        }
        ((BtlPanelWork *)panel)->flags &= ~4;
        ((BtlPanelWork *)panel)->listFrame = 0;
        ((BtlPanelWork *)panel)->detailFrame = 0;
        sdkSndStartStream(0, 15, 0, 1);
        result = 2;
        break;
    case 1:
        flags = *(s32 *)(panel + 4);
        if ((flags & 4) != 0) {
            ((BtlPanelWork *)panel)->flags = flags & ~4;
            result = 1 & 0xFFFF;
        } else {
            sdkSndStartStream(0, 0, 0, 4);
            result = 2;
        }
        break;
    case 3:
        toggledFlags = ((BtlPanelWork *)panel)->flags ^ 4;
        ((BtlPanelWork *)panel)->flags = toggledFlags;
        if ((toggledFlags & 4) != 0) {
            sdkSndStartStream(1, 13, 2, 23);
        } else {
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    default:
        result = 1 & 0xFFFF;
        break;
    }
    return result;
}

// FUN_00209F90
/* Empty draw callback for the persona-command sub-list; its notify callback draws the detail. */
void btlSelectionDrawSubList(void)
{
}

// Intent: draw the current character label and advance its bounded panel timers. [inferred]
// FUN_00209FA0
/* measured: independently typing the remaining counter and selected-unit reads lost MATCH;
 * preserve those byte aliases while keeping their update stores typed. */
void btlSelectionDrawCurrentLabel(u8 *selection, s32 workAddress, u8 *drawState)
{
    extern u32 kwlnTaskGetWork(void *task);
    extern s16 datGetUnitAiTactic(s16 selection);
    extern u32 datPersonaNamePart1(s16 selection);
    extern s32 frFontNodeWidth(struct FrFontNode *node);
    extern void frFontMoveListTo(s32 node, s32 x, s32 y);
    extern s32 frFontListKeepOrRelease(s32 node);
    BtlPanelRenderDispatch *renderer;
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
    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)work)->task);
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
            ((BtlPanelWork *)work)->clipFrame = frame20 + 1;
        }
        frame22 = *(s16 *)(work + 0x22);
        if (frame22 < 0xA) {
            ((BtlPanelWork *)work)->titleFrame = frame22 + 1;
        }
        if ((((BtlPanelWork *)work)->flags & 4) != 0) {
            openingFrame16 = *(s16 *)(work + 0x16);
            if (openingFrame16 < 4) {
                ((BtlPanelWork *)work)->listFrame = openingFrame16 + 1;
            }
            openingFrame18 = *(s16 *)(work + 0x18);
            if (openingFrame18 < 7) {
                ((BtlPanelWork *)work)->detailFrame = openingFrame18 + 1;
            }
        } else {
            closingFrame16 = *(s16 *)(work + 0x16);
            if (closingFrame16 > 0) {
                ((BtlPanelWork *)work)->listFrame = closingFrame16 - 1;
            }
            closingFrame18 = *(s16 *)(work + 0x18);
            if (closingFrame18 > 0) {
                ((BtlPanelWork *)work)->detailFrame = closingFrame18 - 1;
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
        renderer = (BtlPanelRenderDispatch *)D_00887300;
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
        PrimDrawFlatRectangle((u8 *)&color, (f32 *)rect, 0.0f, 0);
        renderer->setState(8, 0);
    }
    renderer = (BtlPanelRenderDispatch *)D_00887300;
    renderer->setState(6, 1);
    btlUiSetAlpha(glyphs, 50.0f);
    btlUiDrawSpriteFaded(glyphs, 9, 0x3B, 493.0f, 330.0f, 0x1B, 0x1B, 0x1B, 0xFF);
    iconFrame = (s16)datGetUnitAiTactic(*(s16 *)(*(u8 **)(work + 0x190) + 0xA4)) + 0x3F;
    btlUiDrawSpriteFaded(glyphs, 9, iconFrame, 168.0f, 334.0f, 0xFE, 0xFF, 0x22, 0xFF);
    frFontSetFlagBits(0x40);
    nameAddress = datPersonaNamePart1((s16)((BtlUnit *)((BtlPanelWork *)work)->selectedUnit)->charId);
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
            ((BtlPanelWork *)work)->labelFrame = frame1c + 1;
        }
        frame1e = *(s16 *)(work + 0x1E);
        if (frame1e < 0xA) {
            ((BtlPanelWork *)work)->labelTitleFrame = frame1e + 1;
        }
    }
}

// FUN_0020A5C0
/* Empty exit callback for the persona-command sub-list. */
void btlSelectionEndSubList(void)
{
}

// Intent: reset the selection flags and window fields for the cursor state. [inferred]
// FUN_0020A5D0
void btlSelectionResetCursorState(u16 *selection, u8 *panel) {
    sdkSndStartStream(0, 0, 0, 3);
    *selection |= 1;
    *selection |= 2;
    ((BtlPanelWork *)panel)->clipFrame = 0;
    ((BtlPanelWork *)panel)->titleFrame = 0;
    ((BtlPanelWork *)panel)->listFrame = 0;
    ((BtlPanelWork *)panel)->detailFrame = 0;
}

// Intent: handle the swap input for the persona roster and start or finish the swap task. [inferred]
// FUN_0020A640
/* measured: 1064/1072 bytes; 35 independently resolved relocations and eight
   zero alignment bytes. Separate stats/task snapshots preserve the retail
   argument-load order without narrowing the persona lookup return type. */
/* measured: independently typing the remaining persona-task/slot and selected-row reads lost
 * MATCH; retain these byte aliases across the display callbacks. */
u16 btlSelectionHandleSwapInput(u8 *selection, u8 *panel)
{
    s16 repeatMasks[4];
    s16 selected;
    u8 *persona;
    u16 result;
    u8 *stats;
    u8 *task;

    result = (u16)(btlSelectionReadInput(selection) & 0xFFFF);
    switch (result) {
    case 2:
        selected = ((BtlSelection *)selection)->selected;
        if (selected != (s16)datPersonaGetLeadSlot()) {
            persona = (u8 *)datPersonaRosterSlot(selected);
            ((BtlAction *)((BtlPanelWork *)panel)->action)->unk_6c = 5;
            ((BtlPanelActionChoice *)((BtlAction *)((BtlPanelWork *)panel)->action)->unk_70)->persona = ((DatPersonaRecord *)persona)->id;
            shdPersonaFinishPhase(*(u8 **)(panel + 0x5A8));
            ((BtlPanelWork *)panel)->personaTask = NULL;
            ((BtlPanelWork *)panel)->personaSlot = -1;
            ((BtlBattleState *)iGpffffb3ac)->flags |= 0x2000;
            ((BtlBattleState *)iGpffffb3ac)->flags |= 0x20000;
            btlEncounterEntrySetActive((u8 *)((BtlPanelWork *)panel)->task);
            result = 4;
        } else {
            sdkSndStartStream(0, 15, 0, 8);
            result = 1;
        }
        break;

    case 3:
        if (*(s16 *)(panel + 0x5AC) == -1) {
            if (shdPersonaIsTransitioning(*(u8 **)(panel + 0x5A8)) == 0) {
                persona = (u8 *)datPersonaRosterSlot(*(s16 *)(selection + 4));
                ((BtlBattleState *)iGpffffb3ac)->flags &= ~0x2000;
                ((BtlBattleState *)iGpffffb3ac)->flags &= ~0x20000;
                stats = (u8 *)((BtlAction *)((BtlPanelWork *)panel)->action)->unit;
                task = *(u8 **)(panel + 0x5A8);
                shdPersonaSetDisplayState(task, ((BtlUnit *)stats)->charId, (u32)persona, 0);
                shdPersonaStartSlideIn(((BtlPanelWork *)panel)->personaTask);
                btlEncounterEntryClearActive((u8 *)((BtlPanelWork *)panel)->task);
                memset(repeatMasks, 0, 8);
                repeatMasks[0] = 4;
                repeatMasks[1] = 8;
                btlSelectionSetRepeat(selection, repeatMasks);
                *(u16 *)selection &= ~2;
                *(u16 *)selection &= ~1;
                *(u16 *)selection &= ~8;
                ((BtlPanelWork *)panel)->personaSlot = ((BtlSelection *)selection)->selected;
            }
        } else if (shdPersonaIsSelectionActive(*(u8 **)(panel + 0x5A8)) == 0) {
            shdPersonaBeginSelection(((BtlPanelWork *)panel)->personaTask);
        } else {
            shdPersonaEndSelection(((BtlPanelWork *)panel)->personaTask, 1);
        }
        break;

    case 1:
        if (*(s16 *)(panel + 0x5AC) == -1) {
            shdPersonaFinishPhase(*(u8 **)(panel + 0x5A8));
            ((BtlPanelWork *)panel)->personaTask = NULL;
            ((BtlPanelWork *)panel)->personaSlot = -1;
            sdkSndStartStream(0, 0, 0, 4);
            result = 2;
        } else if (shdPersonaIsSelectionActive(*(u8 **)(panel + 0x5A8)) == 0) {
            ((BtlBattleState *)iGpffffb3ac)->flags |= 0x2000;
            ((BtlBattleState *)iGpffffb3ac)->flags |= 0x20000;
            shdPersonaBeginClose(((BtlPanelWork *)panel)->personaTask);
            ((BtlPanelWork *)panel)->personaSlot = -1;
            btlSelectionSetRepeat(selection, NULL);
            btlEncounterEntrySetActive((u8 *)((BtlPanelWork *)panel)->task);
            *(u16 *)selection |= 2;
            *(u16 *)selection |= 1;
            *(u16 *)selection |= 8;
            sdkSndStartStream(0, 0, 0, 4);
            result = 1;
        } else {
            shdPersonaEndSelection(((BtlPanelWork *)panel)->personaTask, 1);
        }
        break;

    default:
        if (*(s16 *)(panel + 0x5AC) != -1) {
            if (*(s16 *)(panel + 0x5AC) != *(s16 *)(selection + 4)) {
                persona = (u8 *)datPersonaRosterSlot(*(s16 *)(selection + 4));
                if (result == 5) {
                    stats = (u8 *)((BtlAction *)((BtlPanelWork *)panel)->action)->unit;
                    task = ((BtlPanelWork *)panel)->personaTask;
                    shdPersonaBeginDisplayAndEndSelection(task, ((BtlUnit *)stats)->charId, (u32)persona, 0);
                } else {
                    stats = (u8 *)((BtlAction *)((BtlPanelWork *)panel)->action)->unit;
                    task = ((BtlPanelWork *)panel)->personaTask;
                    shdPersonaBeginDisplay(task, ((BtlUnit *)stats)->charId, (u32)persona, 0);
                }
                ((BtlPanelWork *)panel)->personaSlot = ((BtlSelection *)selection)->selected;
            } else if (shdPersonaIsSelectionActive(*(u8 **)(panel + 0x5A8)) != 0) {
                shdPersonaStepSelectionCursor(((BtlPanelWork *)panel)->personaTask);
            }
        }
        result = 1;
        break;
    }

    return result;
}

/* 508/512 bytes, 13 resolved relocations, four zero alignment bytes.
 * As in btlSelectionDrawTitle, reuse the consumed position view for the callback
 * table base; each state change still reloads the callback slot.
 */
// Intent: draw the swap panel and advance its slide-in timer. [inferred]
// FUN_0020AA70
void btlSelectionDrawSwapPanel(u8 *selection, u8 *panel, f32 *originOrRenderer)
{
    u8 *glyphs;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task);
    btlUiSetOrigin(glyphs, originOrRenderer[0], originOrRenderer[1]);
    btlUiDrawSpriteFaded(glyphs, 9, 0x22, 75.0f, (f32)0x13D, 0x1B, 0x1B, 0x1B, 0xFF);
    originOrRenderer = (f32 *)D_00887300;
    ((void (**)(u32, u32))originOrRenderer)[0](6, 1);
    btlUiSetAlpha(glyphs, 120.0f);
    btlUiDrawSpriteFaded(glyphs, 9, 0x38, 8.0f, (f32)0x129, 0x1B, 0x1B, 0x1B, 0xFF);
    ((void (**)(u32, u32))originOrRenderer)[0](6, 0);
    btlUiSetAlpha(glyphs, 0.0f);
    if (func_001eb860() != 0) {
        btlUiDrawSpriteFaded(glyphs, 9, 0x18, 100.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x1C, 100.0f, (f32)0x19B);
        btlUiDrawSpriteFaded(glyphs, 9, 0x1A, 119.0f, (f32)0x19B, 0x1B, 0x1B, 0x1B, 0xFF);
        btlUiDrawSpriteEntry(glyphs, 9, 0x19, 119.0f, (f32)0x19B);
    }
}

// Intent: draw the persona level list and advance its timers. [inferred]
// FUN_0020AC70
/* measured: independently typing the remaining +0x16/+0x18/+0x20/+0x22 counter reads lost MATCH;
 * their update stores remain typed. */
void btlSelectionDrawLevelList(s32 selection, u8 *panel, f32 *origin)
{
    s16 clipFrame;
    s16 titleFrame;
    s16 openingListFrame;
    s16 openingDetailFrame;
    s16 closingListFrame;
    s16 closingDetailFrame;

    if (*(u16 *)panel != 2) {
        btlSelectionDrawList(panel, (u8 *)selection, origin[0], origin[1],
                      btlPanelDrawPersonaLevel);
    }
    clipFrame = *(s16 *)(panel + 0x20);
    if (clipFrame < 4) {
        ((BtlPanelWork *)panel)->clipFrame = clipFrame + 1;
    }
    titleFrame = *(s16 *)(panel + 0x22);
    if (titleFrame < 0xA) {
        ((BtlPanelWork *)panel)->titleFrame = titleFrame + 1;
    }
    if ((((BtlPanelWork *)panel)->flags & 4) != 0) {
        openingListFrame = *(s16 *)(panel + 0x16);
        if (openingListFrame < 4) {
            ((BtlPanelWork *)panel)->listFrame = openingListFrame + 1;
        }
        openingDetailFrame = *(s16 *)(panel + 0x18);
        if (openingDetailFrame < 7) {
            ((BtlPanelWork *)panel)->detailFrame = openingDetailFrame + 1;
        }
    } else {
        closingListFrame = *(s16 *)(panel + 0x16);
        if (closingListFrame > 0) {
            ((BtlPanelWork *)panel)->listFrame = closingListFrame - 1;
        }
        closingDetailFrame = *(s16 *)(panel + 0x18);
        if (closingDetailFrame > 0) {
            ((BtlPanelWork *)panel)->detailFrame = closingDetailFrame - 1;
        }
    }
}

// FUN_0020AD70
/* Empty exit callback for the persona-swap selection. */
void btlSelectionEndSwapList(void)
{
}

// Intent: initialise a panel work block, clearing it and setting its task pointer. [inferred]
// FUN_0020AD80
void btlPanelInitWork(u8 *panel, s32 task) {
    memset(panel, 0, 0x5B4);
    ((BtlPanelWork *)panel)->task = task;
    ((BtlPanelWork *)panel)->state = 0;
    ((BtlPanelWork *)panel)->personaSlot = -1;
}

/*
 * measured: 968/976 bytes, 11 resolved relocations, eight zero alignment bytes.
 * Preserve the 4,5,0 source case order and all reloads after callbacks.
 */
// Intent: advance the panel's animation counters and low-HP pulse for one frame. [inferred]
// FUN_0020ADD0
/* measured: independently typing the remaining flag and counter reads lost MATCH even with their
 * stores typed. Preserve the byte-addressed tests. */
void btlPanelUpdate(void *panel)
{
    u8 *state = panel;
    if (*(u32 *)(state + 4) & 1) {
        if (*(s16 *)(state + 0xA) < 11) ++((BtlPanelWork *)state)->scaleFrame;
    } else {
        if (*(s16 *)(state + 8) < 19) ++((BtlPanelWork *)state)->outlineFrame;
        if (*(s16 *)(state + 0xA) < 6) ++((BtlPanelWork *)state)->scaleFrame;
        else if (*(s16 *)(state + 0xA) > 6) --((BtlPanelWork *)state)->scaleFrame;
    }
    if (*(s16 *)(state + 0xC) < 4) ++((BtlPanelWork *)state)->circleFrame;
    if (*(s16 *)(state + 0xE) < 2) ++((BtlPanelWork *)state)->commandFrame;
    else if (!(*(u32 *)(state + 4) & 2)) {
        ((BtlPanelWork *)state)->flags |= 2;
        ((BtlPanelWork *)state)->gridFrame = 0;
    }
    if (*(u16 *)state == 1 && ((BtlPanelWork *)state)->outlineFrame == 8) {
        sdkSndStartStream(1, 15, 2, 26);
    }
    if (((BtlPanelWork *)state)->list.current == state + 0x40) {
        if (*(u16 *)state == 1) {
            if (*(s16 *)(state + 0x12) > 0) --((BtlPanelWork *)state)->stripFrame;
        } else {
            if (*(s16 *)(state + 0x12) < 3) ++((BtlPanelWork *)state)->stripFrame;
        }
    } else {
        if (!(((BtlPanelWork *)state)->flags & 1)) {
            if (*(s16 *)(state + 0x12) < 3) ++((BtlPanelWork *)state)->stripFrame;
            else if (*(s16 *)(state + 0x12) > 3) --((BtlPanelWork *)state)->stripFrame;
        } else {
            if (*(s16 *)(state + 0x12) < 6) ++((BtlPanelWork *)state)->stripFrame;
        }
    }
    ((BtlPanelWork *)state)->previousState = *(u16 *)state;
    if (*(u16 *)state == 1 && !(((BtlBattleState *)iGpffffb3ac)->flags & 0x10000)) {
        switch (btlListStep(state + 0x2C) & 0xFFFF) {
        case 4: *(u16 *)state = 2; break;
        case 5: *(u16 *)state = 0; break;
        case 0: break;
        }
        if (((BtlPanelWork *)state)->action != 0 &&
            (u8 *)((BtlAction *)((BtlPanelWork *)state)->action)->unit != 0 &&
            (u8 *)((BtlAction *)((BtlPanelWork *)state)->action)->unit->datUnit != 0) {
            f32 pulse;
            if (datCalcIsLowHp((DatUnit *)((BtlAction *)((BtlPanelWork *)state)->action)->unit->datUnit)) {
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
void btlPanelDrawFrame(s32 unused, u8 *panel)
{
    extern void btlPanelDrawOutlineFill(u8 *unused, f32 x, f32 y,
                              u8 panel, u8 option, u8 flags, s32 extra);
    u8 *glyphs;
    s16 frame;
    s16 growthFrame;
    f32 progress;
    f32 scale;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task);
    if ((*(s32 *)glyphs & 1) != 0) {
        if (*(u16 *)panel != 0) {
            if (((BtlPanelWork *)panel)->personaSlot == -1) {
                btlUiSetRenderStates();
                progress = (f32)((BtlPanelWork *)panel)->outlineFrame / 19.0f;
                if (progress < 1.0f) {
                    progress = (progress * 2.0f -
                                progress * progress) *
                               1.5f;
                    btlPanelDrawOutlineFill(
                        glyphs, progress, progress,
                        ((BtlPanelWork *)panel)->outlineColor[0], ((BtlPanelWork *)panel)->outlineColor[1],
                        ((BtlPanelWork *)panel)->outlineColor[2], 0x4C);
                }
                frame = ((BtlPanelWork *)panel)->scaleFrame;
                if (frame < 7) {
                    progress = (f32)(6 - frame) / 6.0f;
                    if (progress < 1.0f) {
                        scale = 1.0f -
                                   (progress * 2.0f -
                                    progress * progress);
                    }
                } else {
                    growthFrame = frame - 6;
                    progress = (f32)growthFrame / 5.0f;
                    if (progress < 1.0f) {
                        scale =
                            (progress * 2.0f -
                             progress * progress) *
                                0.25f +
                            1.0f;
                    }
                }
                btlPanelDrawOutlineFill(
                    glyphs, scale, scale,
                    ((BtlPanelWork *)panel)->outlineColor[0], ((BtlPanelWork *)panel)->outlineColor[1],
                    ((BtlPanelWork *)panel)->outlineColor[2], 0xFF);
                btlListDispatchUpdate(panel + 0x2C);
            }
        }
    }
}

// Intent: draw the backdrop, the sprite grid and the notify dispatch when the panel is active. [inferred]
// FUN_0020B3A0
/* measured: independently typing the remaining scale/grid counter reads lost MATCH; their other
 * accesses remain typed. */
void btlPanelDrawBackdropGrid(s32 unused, u8 *panel)
{
    extern void btlPanelDrawSpriteGrid(u8 *unused, f32 x, f32 y, u8 panel);
    extern u8 D_00626BE0[];
    u8 *glyphs;
    s16 frame;
    s16 growthFrame;
    f32 scale;

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task);
    if ((*(s32 *)glyphs & 1) != 0) {
        if (*(u16 *)panel != 0) {
            if (((BtlPanelWork *)panel)->personaSlot == -1) {
                btlUiSetRenderStates();
                frame = *(s16 *)(panel + 0xA);
                if (frame < 7) {
                    if (((f32)(6 - frame) / 6.0f) < 1.0f) {
                        scale = 1.0f -
                            ((f32)(6 - frame) / 6.0f * 2.0f -
                             (f32)(6 - frame) / 6.0f *
                                 ((f32)(6 - frame) / 6.0f));
                    }
                } else {
                    growthFrame = frame - 6;
                    if (((f32)growthFrame / 5.0f) < 1.0f) {
                        scale =
                            ((f32)growthFrame / 5.0f * 2.0f -
                             (f32)growthFrame / 5.0f *
                                 ((f32)growthFrame / 5.0f)) *
                                0.25f +
                            1.0f;
                    }
                }
                btlPanelDrawBackdrop(glyphs, scale, scale);
                if (((((BtlPanelWork *)panel)->flags & 2) != 0) &&
                    (*(u16 *)panel != 2) &&
                    (((BtlPanelWork *)panel)->scaleFrame < 7)) {
                    btlPanelDrawSpriteGrid(glyphs, 1.0f, 1.0f,
                                  D_00626BE0[*(s16 *)(panel + 0x10)]);
                    if ((u32)(s16)(*(s16 *)(panel + 0x10) += 1) >= 0x14) {
                        ((BtlPanelWork *)panel)->gridFrame = 0x13;
                    }
                }
                btlListDispatchNotify(panel + 0x2C);
            }
        }
    }
}

// FUN_0020B5A0
/* Empty detail-node render callback registered by the battle UI task. */
void btlPanelDrawDetail(void)
{
}

/* measured: opt_propagation off keeps D_00887300 cached across its callback sequence. */
/* measured: btlPanelDrawSkyFrame MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation off
// Intent: set the sky render states and draw the sky frame when the panel is active. [inferred]
// FUN_0020B5B0
void btlPanelDrawSkyFrame(s32 unused, u8 *panel)
{
    extern void effMiscDrawScreenColor(u8 *unused, s32 panel);
    u8 *glyphs;
    void (**base)(u32, u32);
    u8 work[4];

    glyphs = (u8 *)kwlnTaskGetWork((void *)((BtlPanelWork *)panel)->task);
    if (((*(u32 *)glyphs & 1) != 0) &&
        (*(u16 *)panel != 0) &&
        (((BtlPanelWork *)panel)->personaSlot == -1)) {
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
        effMiscDrawScreenColor(work, 0);
    }
}

/* measured: restore opt_propagation after func_0020b5b0. */
/* measured: btlSelectionMarkTargets, btlSelectionResetUnitFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_propagation on
extern u32 btlEffectCollectGenusMask(u8 *context);
extern u16 datGetSkillPropertyByte(s32 context);
extern s32 datCalcSkillElement(u8 *context, u16 value);
extern s32 datCalcElementBit(s16 context);
extern s8 datCalcGetBuffStatus(u8 *context, s32 value);
extern s32 datCalcGetElementAffinity(u8 *context, s32 value);
extern s32 func_001f0950(s32 context, s32 value);
extern void btlSelectionSetRowState(u8 *context, s16 value);
extern void btlSelectionSetRowIdle(u8 *context);

// Intent: mark the targets for the selected skill, setting each unit's skill element and buff or ailment flags. [inferred]
// FUN_0020B6D0
/* measured: independently typing the remaining skill store and action/unit reads lost MATCH; keep
 * these byte aliases across the status queries. */
void btlSelectionMarkTargets(s32 task, u8 *action, u8 *targets, s16 skill)
{
    extern u32 kwlnTaskGetWork(void *task);
    u16 skillId;
    u32 targetCount;
    u32 isSpecial;
    u32 affinity;
    u8 *transition;
    u8 *taskWork;
    s32 elementMask;
    s32 targetIndex;
    s32 checkAffinity;
    s32 lookupId;
    s32 isEscape;
    u16 rowState;
    s32 element;
    s32 character;
    u16 skillBits;
    u8 *unit;
    u8 *targetAction;

    taskWork = (u8 *)kwlnTaskGetWork((void *)task);
    transition = taskWork + 0x710;
    ((BtlSelectionTransition *)((BtlUiTaskWork *)taskWork)->selection)->action = action;
    ((BtlSelectionTransition *)((BtlUiTaskWork *)taskWork)->selection)->previousAction = 0;
    ((BtlSelectionTransition *)((BtlUiTaskWork *)taskWork)->selection)->targets = targets;
    *(s16 *)(taskWork + 0x724) = skill;
    ((BtlSelectionTransition *)transition)->delay = 1;
    ((BtlTargetSelection *)targets)->flags |= 1;
    if ((btlEffectCollectGenusMask(targets) & 0xFFFF) == 1) {
        *(u16 *)transition |= 2;
    } else {
        *(u16 *)transition &= 0xFFFD;
    }
    switch (skill) {
    case 0x110:
    case 0x10B:
        isEscape = 1;
        break;
    default:
        isEscape = 0;
        break;
    }
    checkAffinity = 0;
    if (skill >= 0) {
        if (datGetFlag(0x38) != 0) {
            lookupId = 5;
        } else {
            lookupId = 8;
        }
        if (datPersonaFindSkillSlot((u8 *)datPersonaGetRecord(lookupId & 0xFFFF), 0x10C) != -1) {
            checkAffinity = 1;
        }
    }
    targetCount = ((BtlTargetSelection *)targets)->count;
    skillBits = (u16)skill;
    isSpecial = datGetSkillPropertyByte(skillBits) & 0xFFFF;
    targetIndex = 0;
    skillId = skillBits & 0xFFFF;
    goto loop_condition;
loop_body:
    targetAction = ((BtlTargetSelection *)targets)->entries[targetIndex];
    unit = (u8 *)((BtlAction *)targetAction)->unit;
    if (isEscape != 0) {
        rowState = 3;
    } else {
        rowState = 0;
        element = (s16)datCalcSkillElement((u8 *)((BtlUnit *)unit)->datUnit, skillId);
        elementMask = datCalcElementBit((s64)(s16)element);
        if (!(elementMask & 0xE0001)) {
            if (elementMask & 2) {
                if ((s8)datCalcGetBuffStatus(*(u8 **)(unit + 0xA64), 0x10) > 0) {
                    rowState = 1;
                }
            } else if (!(elementMask & 0x40) &&
                       (s8)datCalcGetBuffStatus(*(u8 **)(unit + 0xA64), 0x11) > 0) {
                rowState = 1;
            }
        }
        if ((checkAffinity != 0) && !(rowState & 0xFFFF)) {
            affinity = datCalcGetElementAffinity(*(u8 **)(unit + 0xA64), element);
            lookupId = (u16)element;
            character = ((BtlUnit *)unit)->charId;
            if (func_001f0950(character, lookupId) != 0) {
                if ((affinity & 0x02000000) != 0) {
                    rowState = 1;
                } else if ((affinity & 0x05000000) != 0) {
                    rowState = 2;
                }
            }
        }
    }
    btlSelectionSetRowState(*(u8 **)(targetAction + 0x30) + 0xA48, (s16)rowState);
    if (isSpecial != 0) {
        btlSelectionSetRowIdle(*(u8 **)(targetAction + 0x30) + 0xA48);
    }
    targetIndex += 1;
loop_condition:
    if (targetIndex < (s32)targetCount) {
        goto loop_body;
    }
    ((BtlSelectionTransition *)transition)->state = 0;
}

// Intent: return the target mark stored in the selection task. [inferred]
// FUN_0020BA00
u16 btlSelectionGetTargetMark(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    return ((BtlSelectionTransition *)((BtlUiTaskWork *)(u8 *)kwlnTaskGetWork((void *)task))->selection)->state;
}

// Intent: clear the target mark stored in the selection task. [inferred]
// FUN_0020BA30
void btlSelectionClearTargetMark(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    ((BtlSelectionTransition *)((BtlUiTaskWork *)(u8 *)kwlnTaskGetWork((void *)task))->selection)->state = 0;
}

/* Both selection accessors return the formation entry read by 001d8bc0.
 * Their action callers consume this address, so the result must be explicit. */
// Intent: return the formation entry for the selection task's current target. [inferred]
// FUN_0020BA60
u32 btlSelectionGetFormationEntry(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    return btlFormationCurrentEntry(((BtlSelectionTransition *)((BtlUiTaskWork *)(u8 *)kwlnTaskGetWork((void *)task))->selection)->targets);
}

// Intent: return the formation entry for the selection task's current target (duplicate of btlSelectionGetFormationEntry). [inferred]
// FUN_0020BA90
u32 btlSelectionGetFormationEntryAlt(s32 task)
{
    extern u32 kwlnTaskGetWork(void *task);
    return btlFormationCurrentEntry(((BtlSelectionTransition *)((BtlUiTaskWork *)(u8 *)kwlnTaskGetWork((void *)task))->selection)->targets);
}

// Intent: clear the buff flag on every party unit and mark the selection task as ready. [inferred]
// FUN_0020BAC0
/* measured: retail keeps the ~0x200 mask live in the loop preheader; plain -O2
   rematerialises it inside the body (nd 41 -> byte-exact with the hoist). */
/* measured: btlSelectionResetUnitFlags MATCH -> MISMATCH without this pragma. */
#pragma opt_loop_invariants on
void btlSelectionResetUnitFlags(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *transition = (u8 *)kwlnTaskGetWork((void *)task) + 0x710;
    s32 mask = ~0x200;
    u8 *unit = ((BtlBattleState *)D_0076449C)->unitLists[0];

    while (unit != NULL) {
        ((BtlPortraitState *)((BtlUnit *)unit)->unk_a10)->flags &= mask;
        unit = (u8 *)((BtlUnit *)unit)->nextUnit;
    }
    ((BtlSelectionTransition *)transition)->state = 3;
}

/* measured: closes the hoist bracket opened above and restores the -O2
   baseline for the rest of the file. */
// Intent: initialise a transition block and record its task. [inferred]
// FUN_0020BB20
void btlSelectionInitTransition(u8 *transition, s32 task) {
    memset(transition, 0, 0x1C);
    ((BtlSelectionTransition *)transition)->task = task;
    ((BtlSelectionTransition *)transition)->state = 3;
}

/* 512/512 bytes; seventeen fully resolved relocations.
 * The transition helpers explicitly forward their task to its work getter. */
// Intent: advance a selection transition and commit the chosen target. [inferred]
// FUN_0020BB70
/* measured: independently typing the remaining transition, target and selected-action accesses
 * lost MATCH. Retain their byte-addressed callback-boundary loads/stores. */
void btlSelectionUpdateTransition(u8 *transition)
{
    u8 *selected;
    if (*(u16 *)(transition + 2) == 0) {
        if ((*(u16 *)transition & 1) == 0) {
            if (*(u16 *)(transition + 4) > 0) {
                --((BtlSelectionTransition *)transition)->delay;
            } else if (D_008C024E[0] & 0x20) {
                sdkSndStartStream(0, 0, 0, 2);
                btlPanelReleaseText(((BtlSelectionTransition *)transition)->task);
                ((BtlSelectionTransition *)transition)->state = 2;
            } else if (D_008C024E[0] & 0x40) {
                btlPanelReleaseText(((BtlSelectionTransition *)transition)->task);
                ((BtlSelectionTransition *)transition)->state = 1;
            } else {
                btlEffectSelectNeighbourTarget(((BtlSelectionTransition *)transition)->action, *(u8 **)(transition + 0x10));
                if (*(u8 *)(*(u8 **)(transition + 0x10) + 0x3C) & 1) {
                    if ((u16)datGetSkillPropertyByte(((BtlSelectionTransition *)transition)->skill) == 0) {
                        selected = (u8 *)btlFormationCurrentEntry(((BtlSelectionTransition *)transition)->targets);
                        btlPanelStartEntry(*(s32 *)(transition + 0x18), btlUnitGetDataRowAlt((u8 *)((BtlAction *)selected)->unit));
                        btlPanelSetCountdown(*(s32 *)(transition + 0x18), -1);
                        btlPanelMarkEntryTimed(*(s32 *)(transition + 0x18));
                        btlPanelSetTarget((u8 *)((BtlSelectionTransition *)transition)->task, *(s32 *)(selected + 0x30));
                        if (*(u8 **)(transition + 0xC) == NULL) {
                            btlSelectionSetRowIdle(*(u8 **)(selected + 0x30) + 0xA48);
                        } else if (*(u8 **)(transition + 0xC) != selected) {
                            sdkSndStartStream(0, 0, 0, 0);
                            btlSelectionSwapRowState(*(u8 **)(((BtlSelectionTransition *)transition)->previousAction + 0x30) + 0xA48, *(u8 **)(selected + 0x30) + 0xA48);
                        }
                        ((BtlSelectionTransition *)transition)->previousAction = selected;
                    }
                    ((BtlTargetSelection *)((BtlSelectionTransition *)transition)->targets)->flags &= 0xFE;
                }
            }
        } else {
            btlPanelReleaseText(((BtlSelectionTransition *)transition)->task);
            ((BtlTargetSelection *)((BtlSelectionTransition *)transition)->targets)->flags |= 1;
        }
    }
}

// Intent: draw the target frame for each unit in the current selection while the panel is active. [inferred]
// FUN_0020BD70
/* measured: independently typing the remaining task/target reads lost MATCH; retain those byte
 * aliases. Target entry arrays themselves are typed. */
void btlSelectionDrawTargetFrame(u8 *unused, u8 *transition)
{
    typedef struct {
        u8 pad[8];
        f32 screenPosition[2];
        f32 sphereCenter[2];
    } Frame;
    extern u32 kwlnTaskGetWork(void *unused);
    extern void btlUiSetRenderStates(void);
    extern u8 *btlActionGetQueueSecond(void);
    extern void btlUnitGetAttachedSphereCenter(u8 *unused, f32 *transition);
    extern s32 btlTargetFindInRange(f32 *unused, f32 *transition);
    extern void btlUiSetOrigin(u8 *unused, f32 x, f32 y);
    extern void btlUiDrawSpriteFaded(u8 *unused, s32 transition, s32 option, f32 x,
                               f32 y, s32 red, s32 green, s32 blue,
                               s32 alpha);
    extern void btlUiSetRenderMode(s32 unused);
    extern void btlSelectionDispatchTargetMode(s32 unused, u8 *transition, u8 *option);
    Frame frame;
    u8 *glyphs;
    u8 *action;
    u8 *unit;
    u16 state;
    s32 targetCount;
    s32 targetIndex;

    glyphs = (u8 *)kwlnTaskGetWork(*(u8 **)(transition + 0x18));
    if ((*(u32 *)glyphs & 1) != 0) {
        if ((*(u16 *)transition & 1) == 0) {
            state = ((BtlSelectionTransition *)transition)->state;
            if ((state != 3) && (((BtlSelectionTransition *)transition)->delay <= 0)) {
                btlUiSetRenderStates();
                targetCount = *(u16 *)(*(u8 **)(transition + 0x10) + 0x38);
                targetIndex = 0;
                while (targetIndex < (s32)targetCount) {
                    unit = *(u8 **)(((BtlTargetSelection *)((BtlSelectionTransition *)transition)->targets)->entries[targetIndex] +
                                      0x30);
                    btlSelectionDispatchTargetMode(((BtlSelectionTransition *)transition)->task, unit + 0xA48,
                                  unit);
                    targetIndex += 1;
                }
            }
        } else {
            action = btlActionGetQueueSecond();
            if (action != NULL) {
                btlUnitGetAttachedSphereCenter((u8 *)((BtlAction *)action)->unit, frame.sphereCenter);
                if (btlTargetFindInRange(frame.sphereCenter, frame.screenPosition) != 0) {
                    btlUiSetOrigin(glyphs, frame.screenPosition[0] - 46.0f,
                                  frame.screenPosition[1] - 17.0f);
                    btlUiSetRenderMode(2);
                    btlUiDrawSpriteFaded(glyphs, 10, 0x51, 0.0f, 0.0f,
                                  0x52, 0xF3, 0, 0xFF);
                    btlUiDrawSpriteFaded(glyphs, 10, 0x52, 84.0f, 0.0f,
                                  0x52, 0xF3, 0, 0xFF);
                    btlUiSetRenderMode(0);
                    btlUiDrawSpriteFaded(glyphs, 10, 0x4F, 14.0f, 2.0f,
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
    u8 *taskWork;

    taskWork = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlSelectionTransition *)((BtlUiTaskWork *)taskWork)->selection)->flags |= 1;
}

// Intent: clear the active bit on the selection task's flag word. [inferred]
// FUN_0020BF90
void btlSelectionClearTargetFlag(s32 task) {
    extern u32 kwlnTaskGetWork(void *task);
    u8 *taskWork;

    taskWork = (u8 *)kwlnTaskGetWork((void *)task);
    ((BtlSelectionTransition *)((BtlUiTaskWork *)taskWork)->selection)->flags &= 0xFFFE;
}

// Intent: set a selection row's state and reset its counter. [inferred]
// FUN_0020BFC0
void btlSelectionSetRowState(u8 *row, s16 state)
{
    ((BtlSelectionRow *)row)->state = state;
    ((BtlSelectionRow *)row)->counter = 0;
}

// Intent: reset a selection row's counter and mark it idle. [inferred]
// FUN_0020BFD0
void btlSelectionSetRowIdle(u8 *row)
{
    ((BtlSelectionRow *)row)->idleFrame = 0;
    ((BtlSelectionRow *)row)->counter = 1;
}


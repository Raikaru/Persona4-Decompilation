/* Original translation unit y_fclItemShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */

#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "type.h"
#include "evt_internal.h"
#include "fcl_draw_types.h"
#include "sdktask.h"
#include "fcl_object_internal.h"
#include "primitive_queue_internal.h"
#include "h_cdvd_request_internal.h"

/* The controller allocates 0x42C bytes. Panel loops cover 90 base sprites
   followed by 15 extra slots; the band arrays each contain 36 elements. */
typedef struct FclItemShopWork {
    s8 state;
    s8 menuSelection;
    s8 descriptionShown;
    s8 quantity;
    s16 selectedItem;
    s16 cursorRow;
    s8 messageSlot;
    s8 discountDay;
    u8 pad0A[2];
    s32 spriteFile;
    u8 *panels[105];
    u8 pad1B4[0x1C];
    f32 moneyStartX;
    f32 moneyStartY;
    f32 moneyEndX;
    f32 moneyEndY;
    f32 moneyX;
    f32 moneyY;
    s16 moneyDuration;
    s16 moneyElapsed;
    s16 unk1EC;
    u8 pad1EE[0xBA];
    f32 bandAngle;
    s32 bandElapsed;
    s32 bandFadeElapsed;
    u8 bandAlpha[36];
    s8 bandActive[36];
    f32 bandPosition[36];
    s16 bandDelay[36];
    s16 bandStartDelay;
    s16 bandFadeFrames[36];
    s16 bandStep;
    f32 scrollStep;
    s8 moonItemsUnlocked;
    s8 cursorMoved;
    u8 pad426[2];
    void *directory;
} FclItemShopWork;

/* Shop panels append their signed sprite origin to the shared 0x100-byte
   sprite work. The allocation and width/height stores prove the 0x104 extent. */
typedef struct FclItemShopPanel {
    FclObject object;
    s16 centerX;
    s16 centerY;
} FclItemShopPanel;


extern void (*jtbl_008873EC[])(void *ptr);
#include "fcl_color.h"

extern void *(*D_008873F4[])(size_t, size_t, u32);

typedef FclVec2 F2_0033;

extern u32 fclGetMoney(void);
extern s32 fclDecimalDigitCount(s32 value);
extern void fclBustupObjSetAnchorValue(void *, f32);
extern void fclBustupObjStartPosition(void *, F2_0033, F2_0033, u32, u32, s64);
extern f32 D_0064A1D8[];
extern f32 D_0064A1E0[];
extern f32 D_0064A1E8[];
extern f32 D_0064A0E8[];
extern f32 D_0064A2A0[];
extern f32 D_0064A2A8[];
extern f32 D_0064A338[];
extern f32 D_0064A094[];
extern f32 D_0064A1F0[];
extern f32 D_0064A1F8[];
extern f32 D_0064A200[];
extern f32 D_0064A208[];
extern f32 D_0064A220[];
extern f32 D_0064A228[];
extern f32 D_0064A230[];
extern f32 D_0064A318[];
extern f32 D_0064A320[];
extern f32 D_0064A340[];
extern f32 D_0064A348[];
extern f32 D_0064A350[];
extern f32 D_0064A358[];
extern void fclBustupObjStartPositionMode(u8 *task, F2_0033 start, F2_0033 end, u32 easing, s8 mode, u32 duration, s16 delay);
extern void itemShopTalkCreate(u8 *parent);
void fclItemShopStartExit(u8 *shopTask);


extern f32 iGpffff8504;
extern u8 D_00793E80[];
extern f32 D_0064A090[];
extern f32 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];

s32 fclItemShopUpdate(u8 *shopTask);
extern void fclCombineInitRenderStates(void);
extern s32 fclItemShopPanelUpdate(u8 *task);
void chkmemAllocSiteTag(const void *, u32);

void yListDestroy(void);
void H_Cdvd_Destroy(void *);
void sdkSpriteRelease(void *);
s32 datItemPrice(s64);
void *sdkSpriteNewNode(void *, s32, ...);
void yListCreate(s32, s32, s32, s32);
f32 sdkSpriteScaledWidth(void *);
f32 sdkSpriteScaledHeight(void *);
void sdkSpriteFreeNode(void *);
s32 fclBustupObjTestFlagBit(void *, s32);
void fclBustupObjChangeFlagBit(u8 *task, s32 bit, s8 clear);
f32 fclEaseInterpolate(s32, f32, f32, f32, f32);
s32 fclPackRgba(u8, u8, u8, u8);
extern s32 frFontExDrawTextDeferred(f32 x, f32 y, f32 scale, s32 color, s32 chr, s32 id, s32 str, s32 flags, s32 unused, void *param);
extern u32 datGetItemNameId(s16 itemId);
extern s32 datItemCount(s16 itemId);
extern void fclShopDrawNumber(F2_0033 position, f32 depth, FclDrawColor color, u32 inputNumber, s16 glyphBase, void *spriteResource,
                          s32 style);
extern void fclMesWindowDraw(s32 item, s32 color, s32 font, s32 mode, s32 table, s32 listIndex, f32 x, f32 y, f32 depth);
extern s32 yListCount(void);
extern u8 *fclBustupObjGetWork(u8 *task);
extern void fclBustupObjSetAnchorMode(u8 *task, s32 mode);
extern f32 D_0064A2B0[];
extern f32 D_0064A2B8[];
extern u8 D_00795E60[];
extern u32 fclItemShopDiscountedPrice(void *task, s32 itemId);
s32 fclAddClamped(s32, s32, s32, s32, s8);
s32 fclSubClamped(s32, s32, s32, s32, s8);
void memcpy(void *, s32, s32);
s32 fclSpriteUpdateTweens(void *);
void *PrimAllocQueueNode(void);
void PrimAppendNode(void *, void *);
s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);
extern u8 D_00795FE0[];
extern u8 D_0064A360[];
extern u8 D_0064A3A0[];
extern u8 D_00763A18[];
extern void fclCombineDrawMoney(u8 *, u8 *);
extern s32 sdkSpriteRequestLoad(void *);
extern void func_00440b68(void *, void *, s32);
extern void *H_Cdvd_AcquireDirectory(void *, s32);
extern s32 hMaestroDecodeIsReady(s32);
extern s32 H_Cdvd_IsFileLoaded(void *);
extern u8 *fclItemShopPanelCreate(void *, s32, s32);
extern s32 fadeStatus(void);
extern s32 nmMesWindowSlotStatus(s8 slotIndex);
extern void nmMesWindowStepSlotRelease(s32 slotIndex);
extern void nmMesWindowDestroySlot(s8 slotIndex);
extern s8 nmMesWindowAcquire(s32 message);
extern s32 nmMesWindowShowSlotRecord(s8 slotIndex, s32 recordIndex);
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 calGetDayEntryForMonthDay(s32 month, s32 day);
extern s32 kwlnTaskGetTaskByName(void *name);
extern u8 D_0064A3C0[];
extern f32 fclBustupDrawRotatingBand(F2_0033 pos, s16 angleStep, f32 angleOffset, u8 alpha, s8 highlight);
extern void fadeBeginTransition(s32 mode, s32 duration);
extern f32 iGpffff8424;
extern f32 iGpffff851c;
extern f32 iGpffff84cc;
extern f32 D_0064A210[];
extern f32 D_0064A218[];
extern void sdkSndStartStream(s32, s32, s32, s32);
extern s32 nmMesWindowGetSlotState(s8 index);
extern void fclAddMoney(s32 value);
void fclItemShopDrawList(u8 *shopTask);
extern void fclBustupStartSlide(void *task);
extern u16 D_008C024E[];
extern f32 D_0064A290[];
extern f32 D_0064A298[];
extern f32 D_0064A328[];
extern f32 D_0064A330[];
extern u16 D_008C027A[];
extern u8 D_007950B0[];
extern char iGpffffa930;
extern void FldRc_ReleaseCachedObject(void);
extern u16 D_008C0276[];
extern s32 yListLastIndex(void);
extern s16 yListStepIndex(s16, s16, s16, s16, s16);
extern void yListAdvanceCursorScroll(s32, s32, s32, s32, void *, void *);
extern void yListRetreatCursorScroll(s32, s32, s32, s32, void *, void *);
extern void sprintf(void *dst, void *fmt, s32 val);
extern void nmMesWindowSetSlotString(s8 slotIndex, s32 variable, void *text);
extern void nmMesWindowSetSlotParam(s8 slotIndex, s32 recordIndex);
extern void nmMesWindowSetSlotFlag(s8 slotIndex, s32 cursor);
extern void nmMesWindowRequestRefresh(void);

// Drive resource loading, menu/list transitions, purchase confirmation and exit.
/* Access-site layouts cover shop state, panel tweens, queue packets and loaded
   message data; only individually measured alias-sensitive accesses remain raw. */
/* The shared SDK update signature accepts fclItemShopUpdate directly at the
   fclItemShopCreate registration site. */
// FUN_00332BB0
/* Object 37380/window 37392 (retail tail is zero padding). The loops that
   retail colours apart keep their own counters; the case 5 slot loop needs its
   counter and slot index as block locals for retail's $s5/$s4 colouring.
   measured: normalized_diff 0; opt_loop_invariants on hoists the 140/340/20/10
   and (s8)1 loop constants into the preheaders as retail does. */
#pragma opt_loop_invariants on
s32 fclItemShopUpdate(u8 *shopTask) {
    /* Earlier whole-local typing produced 38232B versus 37380B; the retained
       byte sites below were each remeasured independently after access-site typing. */
    u8 *work = ((SdkTask *)shopTask)->work;
    s16 extraPanel;
    s16 i;
    s16 introPanel;
    s16 introBand;
    s16 introBandDelay;
    s16 skipIntroPanel;
    s16 skipIntroBand;
    s16 fadeBand;
    s16 activeBand;
    s16 listRevealPanel;
    s16 menuRevealPanel;
    s16 confirmationBand;
    s16 returnBand;
    s16 exitPanel;
    s8 bandStillActive = 0;
    s16 panelIndex;
    void *task;
    F2_0033 *tbl;
    void *font;
    s64 layer0;
    s64 layer1;
    s64 layer2;
    s64 layer3;
    s32 index;
    f32 *coords;
    s32 slot;
    f32 *slotPos;
    void *slotFont;
    char buf[128];
    void *labelFont;
    void *rowFont;
    void *capFont;
    void *cardFont;
    void *iconFont;
    s32 rowIndex;
    s32 listIndex;
    s32 cardIndex;

    task = PrimAllocQueueNode();
    ((PrimQueueNode *)task)->callback = (void *)fclCombineDrawMoney;
    ((PrimQueueNode *)task)->argument.data = work;
    PrimAppendNode(D_00795FE0, task);
    switch (((FclItemShopWork *)work)->state) {
    case 0:
        ((FclItemShopWork *)work)->spriteFile = sdkSpriteRequestLoad(D_0064A360);
        func_00440b68("%s %d", D_0064A380, 0x17B);
        ((FclItemShopWork *)work)->directory = H_Cdvd_AcquireDirectory(D_0064A3A0, 0);
        ((FclItemShopWork *)work)->state = 1;
        /* fallthrough */
    case 1:
        if (hMaestroDecodeIsReady(((FclItemShopWork *)work)->spriteFile) == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(((FclItemShopWork *)work)->directory) == 0) {
            break;
        }
        ((FclItemShopWork *)work)->state = 2;
        for (panelIndex = 0; panelIndex < 0x5A; panelIndex++) {
            if ((&((FclItemShopWork *)work)->panels[0])[panelIndex] != 0) {
                (&((FclItemShopWork *)work)->panels[0])[panelIndex] = 0;
            }
            (&((FclItemShopWork *)work)->panels[0])[panelIndex] = fclItemShopPanelCreate(shopTask, (u16)panelIndex, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        }
        for (extraPanel = 0; extraPanel < 0xF; extraPanel++) {
            if ((&((FclItemShopWork *)work)->panels[90])[extraPanel] != 0) {
                (&((FclItemShopWork *)work)->panels[90])[extraPanel] = 0;
            }
        }
        ((FclItemShopWork *)work)->panels[90] = fclItemShopPanelCreate(shopTask, 0x2B, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[91] = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[92] = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[93] = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            (&((FclItemShopWork *)work)->panels[94])[panelIndex] = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[94])[panelIndex], 13, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[94])[panelIndex], 0.0f, 0.0f, 0, 0, 0);
        }
        ((FclItemShopWork *)work)->panels[99] = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[98] = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[100] = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[101] = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[102] = fclItemShopPanelCreate(shopTask, 0x40, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->panels[103] = fclItemShopPanelCreate(shopTask, 0x41, *(s32 *)(work + 0xC)); /* measured: access-site fields lose this function's MATCH. */
        if (yListCount() > 5) {
            ((FclItemShopWork *)work)->scrollStep = 108.0f / (f32)(yListCount() - 5);
        }
        ((FclItemShopWork *)work)->discountDay = 0;
        if ((s8)calGetDayEntryForMonthDay(fclCalendarMonth(), (u8)fclCalendarDay()) == 1) {
            *(s8 *)(work + 9) = 1; /* measured: access-site fields lose this function's MATCH. */
        }
        break;
    case 2:
        FldRc_ReleaseCachedObject();
        for (i = 0; i < 0x24; i++) {
            ((FclItemShopWork *)work)->bandActive[i] = 1;
        }
        ((FclItemShopWork *)work)->bandStep = 1;
        tbl = (F2_0033 *)D_0064A290;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[64], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x110), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x110), 17.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x110), 0x63); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A298;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[65], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x114), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x114), 17.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x114), 0x63); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A290;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[102], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1A8), fclMakeVec2(-0x125, tbl->y), fclMakeVec2(200.0f + tbl->x, tbl->y), 2, /* measured: access-site fields lose this function's MATCH. */
                      0x14, 0);
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x1A8)))->color = fclMakeDrawColor(0, 0, 0, 0xFF); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x1A8), 16.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x1A8), 0x63); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A298;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[103], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1AC), fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(200.0f + tbl->x, tbl->y), 2, /* measured: access-site fields lose this function's MATCH. */
                      0x14, 0);
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x1AC)))->color = fclMakeDrawColor(0, 0, 0, 0xFF); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x1AC), 16.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x1AC), 0x63); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[0], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(0x28A, D_0064A090[1]), fclMakeVec2(D_0064A090[0], D_0064A090[1]), /* measured: access-site fields lose this function's MATCH. */
                      0, 0x1E, 0xA);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 3, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartTween(*(u8 **)(work + 0x10), 720.0f, 0.0f, 0, 0x1E, 0xA); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x10), 36.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x10), 0x62); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A338;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[85], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x164), 0, 0xFF, 0, 0, 0x2B); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartUniformRevealScale(*(void **)(work + 0x164), 0.1f, 1.0f, 0, 0xF, 0x2B); /* measured: access-site fields lose this function's MATCH. */
        labelFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, 0x55);
        fclBustupObjStartPosition(*(void **)(work + 0x164), /* measured: access-site fields lose this function's MATCH. */
                      fclMakeVec2((sdkSpriteScaledWidth(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (sdkSpriteScaledHeight(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      fclMakeVec2(tbl->x, tbl->y), 0, 0xF, 0x2B);
        sdkSpriteFreeNode(labelFont);
        fclBustupObjSetAnchorValue(*(void **)(work + 0x164), 69.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x164), 0x56); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->bandStartDelay = 0x2D;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[40], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0xB0), 0, 0xFF, 0, 7, 0x3F); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartUniformRevealScale(*(void **)(work + 0xB0), 0.1f, 1.0f, 0, 0xF, 0x3F); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xB0), 52.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xB0), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        for (introPanel = 0; introPanel < 3; introPanel++) {
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[91])[introPanel], 0, 0);
            fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[91])[introPanel], 0, 0xFF, 0, 7, 0x3F);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[91])[introPanel], 0.1f, 1.0f, 0, 0xF, 0x3F);
            fclBustupObjStartTween((&((FclItemShopWork *)work)->panels[91])[introPanel], (f32)((introPanel + 1) * 0x5A), (f32)((introPanel + 1) * 0x5A), 0, 0, 0);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[91])[introPanel], (f32)(introPanel + 0x31));
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[91])[introPanel], 0x5B);
            ((FclItemShopPanel *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[91])[introPanel]))->centerX = ((FclItemShopPanel *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[91])[introPanel]))->centerY = 0;
        }
        ((FclItemShopWork *)work)->moneyStartX = 0x28A;
        ((FclItemShopWork *)work)->moneyStartY = 15.0f;
        ((FclItemShopWork *)work)->moneyEndX = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
        ((FclItemShopWork *)work)->moneyEndY = 15.0f;
        ((FclItemShopWork *)work)->moneyDuration = 10;
        tbl = (F2_0033 *)D_0064A1D8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[41], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xB4), fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0xF, 0x16); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xB4), 47.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xB4), 0x61); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A1E0;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[42], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xB8), fclMakeVec2(-200.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 9, 0x1C); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xB8), 33.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xB8), 0x61); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A1E8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[43], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xBC), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(153.0f, tbl->y), 0, 0xF, 0x19); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xBC), 48.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xBC), 0x61); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[90], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x178), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(203.0f, tbl->y), 0, 0xF, 0x19); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x178), 48.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x178), 0x61); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A0E8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[11], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x3C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartAlpha(*(void **)(work + 0x3C), 0, 0xFF, 0, 0xA, 0x28); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x3C), 46.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x3C), 0x62); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[1], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x14), 0, 0xFF, 0, 5, 0x28); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x14), 30.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x14), 0x63); /* measured: access-site fields lose this function's MATCH. */
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            layer0 = (s16)(panelIndex * 3 + 0x2D);
            rowIndex = panelIndex + 3;
            coords = (f32 *)((u8 *)D_0064A090 + rowIndex * 8);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0.7f, 1.0f, 0, 5, layer0);
            fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0, 0xFF, 0, 5, layer0);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[3])[panelIndex], (f32)(panelIndex + 0x1A));
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0x63);
            rowFont = sdkSpriteNewNode(*(void **)(work + 0xC), rowIndex); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[3])[panelIndex],
                          fclMakeVec2((sdkSpriteScaledWidth(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (sdkSpriteScaledHeight(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          fclMakeVec2(coords[0], coords[1]), 0, 5, layer0);
            sdkSpriteFreeNode(rowFont);
        }
        ((FclItemShopWork *)work)->state = 3;
        for (i = 0; i < 0x24; i++) {
            ((FclItemShopWork *)work)->bandActive[i] = 1;
        }
        /* fallthrough */
    case 3:
        ((FclItemShopWork *)work)->bandStartDelay = fclSubClamped(*(s16 *)(work + 0x3D4), 1, 0, 0, 1); /* measured: access-site fields lose this function's MATCH. */
        if (*(s16 *)(work + 0x3D4) == 0) { /* measured: access-site fields lose this function's MATCH. */
            for (introBand = 0; introBand < 0x24; introBand++) {
                *(u8 *)(work + introBand + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f); /* measured: access-site fields lose this function's MATCH. */
                if (*(s8 *)(work + introBand + 0x2D8) == 1) { /* measured: access-site fields lose this function's MATCH. */
                    ((FclItemShopWork *)work)->bandPosition[introBand] =
                        fclBustupDrawRotatingBand(fclMakeVec2(23.0f, 225.0f), (s16)(introBand * 10), ((FclItemShopWork *)work)->bandAngle, *(u8 *)(work + introBand + 0x2B4), 1); /* measured: access-site fields lose this function's MATCH. */
                }
            }
            ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 720.0f);
            *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), ((FclItemShopWork *)work)->bandStep, 0x2D0, 1, 2); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 3], 2) == 0) {
                fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 3], 0xAB);
            }
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[40], 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0xB0), 4) == 0) { /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 0);
            fclBustupObjSetAnchorValue(*(void **)(work + 0x58), 80.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x58), 0x3D); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 0);
            fclBustupObjSetAnchorValue(*(void **)(work + 0x5C), 81.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x5C), 0x3D); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A2A0;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 0);
            fclBustupObjSetAnchorValue(*(void **)(work + 0x118), 82.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x118), 0x3E); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A2A8;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 0);
            fclBustupObjSetAnchorValue(*(void **)(work + 0x11C), 83.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x11C), 0x3E); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0, 1);
                fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[12])[panelIndex], (f32)(panelIndex + 0x4A));
                fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0x3F);
            }
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
            for (introBandDelay = 0; introBandDelay < 0x24; introBandDelay++) {
                if (!(*(f32 *)(work + introBandDelay * 4 + 0x2FC) < 140.0f) && ((FclItemShopWork *)work)->bandPosition[introBandDelay] < 340.0f) { /* measured: access-site fields lose this function's MATCH. */
                    ((FclItemShopWork *)work)->bandActive[introBandDelay] = 0;
                } else if (!(*(f32 *)(work + introBandDelay * 4 + 0x2FC) < 140.0f)) { /* measured: access-site fields lose this function's MATCH. */
                    ((FclItemShopWork *)work)->bandDelay[introBandDelay] = (*(f32 *)(work + introBandDelay * 4 + 0x2FC) - 340.0f) / 10.0f; /* measured: access-site fields lose this function's MATCH. */
                } else {
                    ((FclItemShopWork *)work)->bandDelay[introBandDelay] = (20.0f + *(f32 *)(work + introBandDelay * 4 + 0x2FC)) / 10.0f; /* measured: access-site fields lose this function's MATCH. */
                }
                ((FclItemShopWork *)work)->bandFadeFrames[introBandDelay] = 0;
                ((FclItemShopWork *)work)->bandFadeElapsed = 0;
            }
            ((FclItemShopWork *)work)->state = 4;
            break;
        }
        if (!(D_008C024E[0] & 0x40) && !(D_008C024E[0] & 0x20) && !(D_008C024E[0] & 0x10) && !(D_008C024E[0] & 0x80)) {
            break;
        }
        tbl = (F2_0033 *)D_0064A290;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[102]))->anchorPosition = fclMakeVec2(200.0f + tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1A8), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A298;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[103]))->anchorPosition = fclMakeVec2(200.0f + tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1AC), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[0]))->anchorPosition = fclMakeVec2(D_0064A090[0], D_0064A090[1]);
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x10)))->tweenValue = 0.0f; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 3, 1); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A338;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[85]))->alpha = 0xFF;
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x164)))->scaleX = 1.0f; /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x164)))->scale = 1.0f; /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x164)))->anchorPosition = fclMakeVec2(tbl->x, tbl->y); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 2, 1); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 4, 1); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xB0)))->alpha = 0xFF; /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xB0)))->scaleX = 1.0f; /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xB0)))->scale = 1.0f; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 2, 1); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 4, 1); /* measured: access-site fields lose this function's MATCH. */
        for (skipIntroPanel = 0; skipIntroPanel < 3; skipIntroPanel++) {
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel]))->alpha = 0xFF;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel]))->scaleX = 1.0f;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel]))->scale = 1.0f;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel]))->tweenValue = (skipIntroPanel + 1) * 0x5A;
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel], 2, 1);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel], 3, 1);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[91])[skipIntroPanel], 4, 1);
        }
        ((FclItemShopWork *)work)->moneyX = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
        ((FclItemShopWork *)work)->moneyY = 15.0f;
        ((FclItemShopWork *)work)->moneyElapsed = 10;
        tbl = (F2_0033 *)D_0064A1D8;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[41]))->anchorPosition = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB4), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A1E0;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[42]))->anchorPosition = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB8), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A1E8;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[43]))->anchorPosition = fclMakeVec2(153.0f, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xBC), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[90]))->anchorPosition = fclMakeVec2(203.0f, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x178), 1, 1); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[11]))->alpha = 0xFF;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x3C), 2, 1); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[1]))->alpha = 0xFF;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x14), 2, 1); /* measured: access-site fields lose this function's MATCH. */
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            coords = (f32 *)((u8 *)D_0064A090 + (panelIndex + 3) * 8);
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[3])[panelIndex]))->anchorPosition = fclMakeVec2(coords[0], coords[1]);
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[3])[panelIndex]))->scaleX = 1.0f;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[3])[panelIndex]))->scale = 1.0f;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[3])[panelIndex]))->alpha = 0xFF;
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[panelIndex], 2, 1);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[panelIndex], 1, 1);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[panelIndex], 4, 1);
        }
        for (i = 0; i < 0x24; i++) {
            ((FclItemShopWork *)work)->bandAlpha[i] = 0xFF;
            ((FclItemShopWork *)work)->bandActive[i] = 1;
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 0);
        fclBustupObjSetAnchorValue(*(void **)(work + 0x58), 80.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x58), 0x3D); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 0);
        fclBustupObjSetAnchorValue(*(void **)(work + 0x5C), 81.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x5C), 0x3D); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A2A0;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 0);
        fclBustupObjSetAnchorValue(*(void **)(work + 0x118), 82.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x118), 0x3E); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)), /* measured: access-site fields lose this function's MATCH. */
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A2A8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 0);
        fclBustupObjSetAnchorValue(*(void **)(work + 0x11C), 83.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x11C), 0x3E); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), /* measured: access-site fields lose this function's MATCH. */
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
            fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[panelIndex + 12], (f32)(panelIndex + 0x4A));
            fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 12], 0x3F);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
        for (skipIntroBand = 0; skipIntroBand < 0x24; skipIntroBand++) {
            if (!(*(f32 *)(work + skipIntroBand * 4 + 0x2FC) < 140.0f) && ((FclItemShopWork *)work)->bandPosition[skipIntroBand] < 340.0f) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandActive[skipIntroBand] = 0;
            } else if (!(*(f32 *)(work + skipIntroBand * 4 + 0x2FC) < 140.0f)) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandDelay[skipIntroBand] = (*(f32 *)(work + skipIntroBand * 4 + 0x2FC) - 340.0f) / 10.0f; /* measured: access-site fields lose this function's MATCH. */
            } else {
                ((FclItemShopWork *)work)->bandDelay[skipIntroBand] = (20.0f + *(f32 *)(work + skipIntroBand * 4 + 0x2FC)) / 10.0f; /* measured: access-site fields lose this function's MATCH. */
            }
            ((FclItemShopWork *)work)->bandFadeFrames[skipIntroBand] = 0;
            ((FclItemShopWork *)work)->bandFadeElapsed = 0;
        }
        ((FclItemShopWork *)work)->state = 4;
        break;
    case 4:
        ((FclItemShopWork *)work)->moneyX =
            fclEaseInterpolate(0, ((FclItemShopWork *)work)->moneyStartX, ((FclItemShopWork *)work)->moneyEndX, ((FclItemShopWork *)work)->moneyElapsed, 10.0f);
        *(s16 *)(work + 0x1EA) = fclAddClamped(*(s16 *)(work + 0x1EA), 1, 10, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        for (fadeBand = 0; fadeBand < 0x24; fadeBand++) {
            if (*(s8 *)(work + fadeBand + 0x2D8) == 1) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandDelay[fadeBand] = fclSubClamped(((FclItemShopWork *)work)->bandDelay[fadeBand], 1, 0, 0, 1);
                if (((FclItemShopWork *)work)->bandDelay[fadeBand] == 0) {
                    *(u8 *)(work + fadeBand + 0x2B4) = fclEaseInterpolate(0, 255.0f, 0.0f, *(s16 *)(work + fadeBand * 2 + 0x3D6), 15.0f); /* measured: access-site fields lose this function's MATCH. */
                    *(s16 *)(work + fadeBand * 2 + 0x3D6) = fclAddClamped(*(s16 *)(work + fadeBand * 2 + 0x3D6), 1, 0xF, 1, 1); /* measured: access-site fields lose this function's MATCH. */
                }
                ((FclItemShopWork *)work)->bandPosition[fadeBand] = fclBustupDrawRotatingBand(fclMakeVec2(23.0f, 225.0f), (s16)(fadeBand * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, *(u8 *)(work + fadeBand + 0x2B4), 1); /* measured: access-site fields lose this function's MATCH. */
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 720.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), ((FclItemShopWork *)work)->bandStep, 0x2D0, 1, 2); /* measured: access-site fields lose this function's MATCH. */
        for (activeBand = 0; activeBand < 0x24; activeBand++) {
            if (!(((FclItemShopWork *)work)->bandPosition[activeBand] < 140.0f) && ((FclItemShopWork *)work)->bandPosition[activeBand] < 340.0f) {
                ((FclItemShopWork *)work)->bandActive[activeBand] = 0;
            } else if (((FclItemShopWork *)work)->bandFadeFrames[activeBand] == 0xF) {
                ((FclItemShopWork *)work)->bandActive[activeBand] = 0;
            }
            if (((FclItemShopWork *)work)->bandActive[activeBand] == 1) {
                bandStillActive = 1;
            }
        }
        if (bandStillActive != 0) {
            break;
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[20], 0, 0);
        fclBustupObjSetAnchorValue(*(void **)(work + 0x60), 14.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x60), 0x64); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[85], 0, 1);
        *(s32 *)(work + 0x2AC) = 0; /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->state = 5;
        if (((FclItemShopWork *)work)->moonItemsUnlocked == 1) {
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 2); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->state = 6;
        } else if (((FclItemShopWork *)work)->discountDay == 1) {
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 3); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->state = 7;
        } else {
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 4); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->state = 7;
        }
        break;
    case 6:
        if (nmMesWindowSlotStatus(((FclItemShopWork *)work)->messageSlot) != 0) {
            nmMesWindowStepSlotRelease(*(s8 *)(work + 8)); /* measured: access-site fields lose this function's MATCH. */
            break;
        }
        nmMesWindowDestroySlot(*(s8 *)(work + 8)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->state = 5;
        if (((FclItemShopWork *)work)->discountDay == 1) {
            *(s8 *)(work + 8) = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 3); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->state = 7;
        }
        break;
    case 7:
        if (nmMesWindowSlotStatus(((FclItemShopWork *)work)->messageSlot) != 0) {
            nmMesWindowStepSlotRelease(*(s8 *)(work + 8)); /* measured: access-site fields lose this function's MATCH. */
            break;
        }
        nmMesWindowDestroySlot(*(s8 *)(work + 8)); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->state = 5;
        break;
    case 5:
        if (D_008C027A[0] & 0x4000) {
            ((FclItemShopWork *)work)->menuSelection = fclAddClamped(*(s8 *)(work + 1), 1, 2, 0, 2); /* measured: access-site fields lose this function's MATCH. */
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
            }
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            ((FclItemShopWork *)work)->menuSelection = fclSubClamped(*(s8 *)(work + 1), 1, 0, 2, 2); /* measured: access-site fields lose this function's MATCH. */
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
            }
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C024E[0] & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            switch (((FclItemShopWork *)work)->menuSelection) {
            case 0:
                {
                    s16 n;
                    s32 slot;

                    for (n = 0; n < 4; n++) {
                        slot = n + 3;
                        slotPos = (f32 *)((u8 *)D_0064A090 + slot * 8);
                        fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[3])[n], 1.0f, 0.5f, 0, 3, n);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[n], 0xFF, 0, 0, 3, n);
                        slotFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, slot);
                        fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[3])[n], fclMakeVec2(slotPos[0], slotPos[1]),
                                      fclMakeVec2((sdkSpriteScaledWidth(slotFont) / 10.0f) * 1.5f + slotPos[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(slotFont) / 10.0f) * 1.5f + slotPos[1] + 0.0f),
                                      0, 3, n);
                        sdkSpriteFreeNode(slotFont);
                    }
                }
                fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[1], 0, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x14), 0xFF, 0, 0, 6, 0); /* measured: access-site fields lose this function's MATCH. */
                tbl = (F2_0033 *)D_0064A1D8;
                fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[41], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(-180.0f, tbl->y), 0, 0xD,
                              5);
                tbl = (F2_0033 *)D_0064A1E0;
                fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[42], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(-200.0f, tbl->y), 0, 0xD,
                              8);
                tbl = (F2_0033 *)D_0064A1E8;
                fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[43], fclMakeVec2(153.0f, tbl->y), fclMakeVec2(-100.0f, tbl->y), 0, 0xD,
                              5);
                fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[90], fclMakeVec2(203.0f, tbl->y), fclMakeVec2(-50.0f, tbl->y), 0, 0xD,
                              5);
                tbl = (F2_0033 *)D_0064A0E8;
                fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[11], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(-200.0f, tbl->y), 0, 0xD,
                              5);
                fclBustupObjStartUniformRevealScale(((FclItemShopWork *)work)->panels[40], 1.0f, 4.5f, 0, 0x14, 0);
                for (panelIndex = 0; panelIndex < 3; panelIndex++) {
                    fclBustupObjStartUniformRevealScale(((FclItemShopWork *)work)->panels[panelIndex + 91], 1.0f, 4.5f, 0, 0x14, 0);
                }
                fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[64], 84.0f);
                fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[65], 84.0f);
                fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[20], 83.0f);
                ((FclItemShopWork *)work)->state = 9;
                break;
            case 1:
                for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                    fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[panelIndex + 3], 0xFF, 0, 0, 5, 0);
                }
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[0], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[64], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[65], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[1], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[41], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[42], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[43], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[90], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[11], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[40], 0xFF, 0, 0, 5, 0);
                for (panelIndex = 0; panelIndex < 3; panelIndex++) {
                    fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[panelIndex + 91], 0xFF, 0, 0, 5, 0);
                }
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[18], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[19], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[66], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[67], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[12], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[16], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[14], 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[20], 0xFF, 0, 0, 5, 0);
                itemShopTalkCreate(shopTask);
                ((FclItemShopWork *)work)->state = 0x10;
                break;
            case 2:
                fclItemShopStartExit(shopTask);
                break;
            }
        } else if (D_008C024E[0] & 0x20) {
            fclItemShopStartExit(shopTask);
            sdkSndStartStream(0, 0, 0, 2);
        }
        tbl = (F2_0033 *)D_0064A2A0;
        fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[66], fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A2A8;
        fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[67], fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), /* measured: access-site fields lose this function's MATCH. */
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        switch (*(s8 *)(work + 1)) { /* measured: access-site fields lose this function's MATCH. */
        case 0:
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
            break;
        case 1:
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[12], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[16], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
            break;
        case 2:
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[12], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[17], 0, 0);
            break;
        }
        break;
    case 9:
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[1], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[3], 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 1) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[4], 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x20), 2) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x20), 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[5], 4) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x24), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x24), 1) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[6], 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x28), 2) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x28), 1) != 0) { /* measured: access-site fields lose this function's MATCH. */
            break;
        }
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[64], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[65], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[20], 0, 1);
        fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[40], 0x65);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 91], 0x65);
        }
        for (listRevealPanel = 0; listRevealPanel < 4; listRevealPanel++) {
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[94])[listRevealPanel], 13, 0);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[94])[listRevealPanel], 0, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[94])[listRevealPanel], 0.1f, 2.7f, 0, 0xC, 0);
            fclBustupObjStartTween((&((FclItemShopWork *)work)->panels[94])[listRevealPanel], 0.0f, listRevealPanel * 0x5A, 0, 0, 0);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[94])[listRevealPanel], 1.0f);
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[94])[listRevealPanel], 0x64);
            ((FclItemShopPanel *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[94])[listRevealPanel]))->centerX = ((FclItemShopPanel *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[94])[listRevealPanel]))->centerY = 0;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[94])[listRevealPanel]))->alpha = 2;
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[0], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(D_0064A090[0], D_0064A090[1]), fclMakeVec2(428.0f, 241.0f), /* measured: access-site fields lose this function's MATCH. */
                      0, 0xF, 0);
        fclBustupObjStartTween(*(u8 **)(work + 0x10), -360.0f, 0.0f, 0, 0xF, 0); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A320;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[82], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x158), 0, 0xFF, 0, 0, 0xF); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartUniformRevealScale(*(void **)(work + 0x158), 0.1f, 1.0f, 0, 8, 0xF); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x158), 45.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x158), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        labelFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, 0x52);
        fclBustupObjStartPosition(*(void **)(work + 0x158), /* measured: access-site fields lose this function's MATCH. */
                      fclMakeVec2((sdkSpriteScaledWidth(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (sdkSpriteScaledHeight(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      fclMakeVec2(tbl->x, tbl->y), 0, 8, 0xF);
        sdkSpriteFreeNode(labelFont);
        tbl = (F2_0033 *)D_0064A200;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[46], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xC8), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0x14, 5); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xC8), 42.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xC8), 0x61); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A1F0;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[44], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xC0), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 8, 5); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xC0), 43.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xC0), 0x61); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A1F8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[45], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xC4), fclMakeVec2(980.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 8, 5); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartTween(*(u8 **)(work + 0xC4), 0.0f, -90.0f, 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xC4)))->targetTween = ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xC4)))->startTween = /* measured: access-site fields lose this function's MATCH. */
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xC4)))->tweenValue = -90.0f; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xC4), 44.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xC4), 0x61); /* measured: access-site fields lose this function's MATCH. */
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            layer1 = (s16)(panelIndex * 3 + 0xF);
            listIndex = panelIndex + 7;
            coords = (f32 *)((u8 *)D_0064A090 + listIndex * 8);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0.7f, 1.0f, 0, 5, layer1);
            fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0, 0xFF, 0, 5, layer1);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[7])[panelIndex], (f32)(panelIndex + 0x1A));
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0x63);
            rowFont = sdkSpriteNewNode(*(void **)(work + 0xC), listIndex); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[7])[panelIndex],
                          fclMakeVec2((sdkSpriteScaledWidth(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (sdkSpriteScaledHeight(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          fclMakeVec2(coords[0], coords[1]), 0, 5, layer1);
            sdkSpriteFreeNode(rowFont);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[2], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x18), 0, 0xFF, 0, 0x14, 0xA); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x18), 21.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x18), 0x64); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A208;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[47], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xCC), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xCC), 68.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xCC), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A210;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[48], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xD0), fclMakeVec2(1064.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xD0), 60.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xD0), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A218;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[49], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xD4), fclMakeVec2(1064.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xD4), 59.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xD4), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[80], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x150), 0, 0xFF, 0, 0, 0xA); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x150), 56.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x150), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[98], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x198), 0, 0xFF, 0, 0, 0xA); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x198), 57.0f); /* measured: access-site fields lose this function's MATCH. */
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
            (u8)datItemCount((s16)yListValueAt(((FclItemShopWork *)work)->selectedItem)) % 10 + 0x46;
        fclBustupObjSetAnchorMode(*(void **)(work + 0x198), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x198)))->color = fclMakeDrawColor(0x7E, 0, 8, 0xFF); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x19C), 0, 0xFF, 0, 0, 0xA); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjStartPosition(*(void **)(work + 0x19C), fclMakeVec2(552.0f, 185.0f), fclMakeVec2(552.0f, 185.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x19C), 57.0f); /* measured: access-site fields lose this function's MATCH. */
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x19C), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x19C)))->color = fclMakeDrawColor(0x7E, 0, 8, 0xFF); /* measured: access-site fields lose this function's MATCH. */
        if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) { /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 21], 0, 0);
            fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[panelIndex + 21], 0, 0xFF, 0, 0xA, 0x19);
            fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[panelIndex + 21], 15.0f);
            fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 21], 0x64);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[24], 0, 1);
        tbl = (F2_0033 *)D_0064A228;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[51], 0, 1);
        fclBustupObjStartPosition(*(void **)(work + 0xDC), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xDC), 66.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xDC), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A230;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[52], 0, 1);
        fclBustupObjStartPosition(*(void **)(work + 0xE0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xE0), 67.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xE0), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        tbl = (F2_0033 *)D_0064A220;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[50], 0, 1);
        fclBustupObjStartPosition(*(void **)(work + 0xD8), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xD8), 61.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xD8), 0x5B); /* measured: access-site fields lose this function's MATCH. */
        if (((FclItemShopWork *)work)->moonItemsUnlocked == 1) {
            capFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x51); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A318;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[81], 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x154), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartTween(*(u8 **)(work + 0x154), -90.0f, 0.0f, 0, 7, 0xA); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorValue(*(void **)(work + 0x154), 40.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x154), 0x62); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x154)))->centerX = 0; /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x154)))->centerY = sdkSpriteScaledHeight(capFont); /* measured: access-site fields lose this function's MATCH. */
            sdkSpriteFreeNode(capFont);
        }
        if (((FclItemShopWork *)work)->discountDay == 1) {
            tbl = (F2_0033 *)D_0064A340;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[86], 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x168), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartTween(*(u8 **)(work + 0x168), 150.0f, 0.0f, 0, 0xA, 0x1B); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x168)))->centerX = 0x231 - tbl->x; /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x168)))->centerY = 470.0f - tbl->y; /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorValue(*(void **)(work + 0x168), 24.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x168), 0x63); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A348;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[87], 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x16C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartAlpha(*(void **)(work + 0x16C), 0xFF, 0x33, 0, 0x14, 0x34); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartUniformRevealScale(*(void **)(work + 0x16C), 0.0f, 1.0f, 0, 0, 0x25); /* measured: access-site fields lose this function's MATCH. */
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x16C)))->tweenValue = 0.0f; /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorValue(*(void **)(work + 0x16C), 23.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x16C), 0x63); /* measured: access-site fields lose this function's MATCH. */
            labelFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x58); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A350;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[88], 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x170), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x + sdkSpriteScaledWidth(labelFont) / 2.0f, tbl->y + sdkSpriteScaledHeight(labelFont) / 2.0f),
                          fclMakeVec2(tbl->x - 4.0f, tbl->y - 3.0f), 0, 5, 0x23);
            fclBustupObjStartUniformRevealScale(*(void **)(work + 0x170), 0.0f, 1.05f, 2, 5, 0x23); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartAlpha(*(void **)(work + 0x170), 0, 0xFF, 0, 0, 0x23); /* measured: access-site fields lose this function's MATCH. */
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x170)))->tweenValue = 0.0f; /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorValue(*(void **)(work + 0x170), 22.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x170), 0x63); /* measured: access-site fields lose this function's MATCH. */
            sdkSpriteFreeNode(labelFont);
            tbl = (F2_0033 *)D_0064A358;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[89], 0, 0);
            fclBustupObjStartPositionMode(*(u8 **)(work + 0x174), fclMakeVec2(0x113 + tbl->x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, tbl->y - 120.0f), 1, 0, 0xE, 0x20);
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x174)))->tweenValue = 0.0f; /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorValue(*(void **)(work + 0x174), 9.0f); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjSetAnchorMode(*(void **)(work + 0x174), 0x64); /* measured: access-site fields lose this function's MATCH. */
        }
        ((FclItemShopWork *)work)->descriptionShown = 0;
        ((FclItemShopWork *)work)->state = 0xA;
        break;
    case 8:
        break;
    case 10:
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[88], 4) == 0) {
            fclBustupObjStartUniformRevealScale(*(void **)(work + 0x170), 0.0f, 1.0f, 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[94], 4) != 0) {
            break;
        }
        fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[40], 0x5B);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 91], 0x5B);
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 94], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 91], 0, 1);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 0, 1); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->bandFadeElapsed = 0;
        for (i = 0; i < 0x24; i++) {
            ((FclItemShopWork *)work)->bandActive[i] = 1;
        }
        ((FclItemShopWork *)work)->state = 0xB;
        break;
    case 11:
        ((FclItemShopWork *)work)->quantity = 1;
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[88], 4) == 0) {
            tbl = (F2_0033 *)D_0064A350;
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x170)))->anchorPosition = fclMakeVec2(tbl->x, tbl->y); /* measured: access-site fields lose this function's MATCH. */
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x170)))->scaleX = 1.0f; /* measured: access-site fields lose this function's MATCH. */
            ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x170)))->scale = 1.0f; /* measured: access-site fields lose this function's MATCH. */
        }
        for (panelIndex = 0; panelIndex < 0x24; panelIndex++) {
            *(u8 *)(work + panelIndex + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f); /* measured: access-site fields lose this function's MATCH. */
            if (*(s8 *)(work + panelIndex + 0x2D8) == 1) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandPosition[panelIndex] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(panelIndex * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, *(u8 *)(work + panelIndex + 0x2B4), 0); /* measured: access-site fields lose this function's MATCH. */
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[47], 1) == 0) {
            fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                          fclItemShopDiscountedPrice(shopTask, yListValueAt(((FclItemShopWork *)work)->selectedItem)), 0x35, (void *)((FclItemShopWork *)work)->spriteFile, 0xAB);
            fclItemShopDrawList(shopTask);
            tbl = (F2_0033 *)D_0064A218;
            ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[49]))->anchorPosition.y =
                (f32)(*(s16 *)(work + 4) - ((FclItemShopWork *)work)->cursorRow) * ((FclItemShopWork *)work)->scrollStep + tbl->y + 0.0f; /* measured: access-site fields lose this function's MATCH. */
        }
        *(u16 *)(fclBustupObjGetWork(((FclItemShopWork *)work)->panels[98]) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
            (u8)datItemCount((s16)yListValueAt(((FclItemShopWork *)work)->selectedItem)) % 10 + 0x46;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
        if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) { /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[82], 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x158), 4) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[46], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[44], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[45], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[7], 4) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[8], 4) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[9], 4) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[10], 4) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[2], 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0xCC), 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[48], 1) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[49], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[80], 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x198), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x19C), 2) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[21], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[22], 2) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[23], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[24], 2) != 0) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && ((FclItemShopWork *)work)->cursorMoved == 0) {
            sdkSndStartStream(0, 0, 0, 0);
            if (*(s16 *)(work + 4) == 0) { /* measured: access-site fields lose this function's MATCH. */
                *(s16 *)(work + 4) = yListLastIndex(); /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->cursorRow = fclAddClamped(0, *(s16 *)(work + 4), 4, 0, 1); /* measured: access-site fields lose this function's MATCH. */
            } else {
                *(s16 *)(work + 4) = fclSubClamped(*(s16 *)(work + 4), 1, 0, (s16)yListCount(), 2); /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->cursorRow =
                    yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListCount(), 5, -1); /* measured: access-site fields lose this function's MATCH. */
            }
            *(s8 *)(work + 0x425) = 1; /* measured: access-site fields lose this function's MATCH. */
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s16 *)(work + 4) != 0) { /* measured: access-site fields lose this function's MATCH. */
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s16 *)(work + 4) = fclSubClamped(*(s16 *)(work + 4), 1, 0, 0, 1); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->cursorRow = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListCount(), 5, -1); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->cursorMoved = 1;
        } else if ((D_008C0276[0] & 0x4000) && ((FclItemShopWork *)work)->cursorMoved == 0) {
            sdkSndStartStream(0, 0, 0, 0);
            *(s16 *)(work + 4) = fclAddClamped(*(s16 *)(work + 4), 1, yListLastIndex(), 0, 2); /* measured: access-site fields lose this function's MATCH. */
            if (*(s16 *)(work + 4) == 0) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->cursorRow = 0;
            } else if (yListLastIndex() >= 5) {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(), 5, 1); /* measured: access-site fields lose this function's MATCH. */
            } else {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(), /* measured: access-site fields lose this function's MATCH. */
                                                   (s16)yListCount(), 1);
            }
            *(s8 *)(work + 0x425) = 1; /* measured: access-site fields lose this function's MATCH. */
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s16 *)(work + 4) != yListLastIndex()) { /* measured: access-site fields lose this function's MATCH. */
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s16 *)(work + 4) = fclAddClamped(*(s16 *)(work + 4), 1, yListLastIndex(), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            if (yListLastIndex() >= 5) {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(), 5, 1); /* measured: access-site fields lose this function's MATCH. */
            } else {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(), /* measured: access-site fields lose this function's MATCH. */
                                                   (s16)yListCount(), 1);
            }
            ((FclItemShopWork *)work)->cursorMoved = 1;
        } else {
            if ((D_008C027A[0] & 8) || (D_008C027A[0] & 0x2000)) {
                if (*(s16 *)(work + 4) != yListLastIndex()) { /* measured: access-site fields lose this function's MATCH. */
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll(*(s16 *)(work + 4), ((FclItemShopWork *)work)->cursorRow, yListCount(), 5, work + 4, work + 6); /* measured: access-site fields lose this function's MATCH. */
            } else if ((D_008C027A[0] & 4) || (D_008C027A[0] & 0x8000)) {
                if (*(s16 *)(work + 4) != 0) { /* measured: access-site fields lose this function's MATCH. */
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListRetreatCursorScroll(*(s16 *)(work + 4), ((FclItemShopWork *)work)->cursorRow, yListCount(), 5, work + 4, work + 6); /* measured: access-site fields lose this function's MATCH. */
            } else if (D_008C024E[0] & 0x40) {
                if (fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))) <= fclGetMoney() && /* measured: access-site fields lose this function's MATCH. */
                    (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) < 0x63) { /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A210;
                    fclBustupObjStartPosition(*(void **)(work + 0xD0), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD0)))->anchorPosition.x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x - 0x193, tbl->y), 0, 7, 0);
                    tbl = (F2_0033 *)D_0064A218;
                    fclBustupObjStartPosition(*(void **)(work + 0xD4), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.x, /* measured: access-site fields lose this function's MATCH. */
                                                ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x - 0x193, ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), /* measured: access-site fields lose this function's MATCH. */
                                  0, 7, 0);
                    tbl = (F2_0033 *)D_0064A328;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[83], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x15C), fclMakeVec2(tbl->x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x, tbl->y - 7.0f), 1, 0xA, 7);
                    fclBustupObjStartAlpha(*(void **)(work + 0x15C), 0, 0xFF, 0, 0xA, 7); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x15C), 54.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorMode(*(void **)(work + 0x15C), 0x5B); /* measured: access-site fields lose this function's MATCH. */
                    ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x15C)))->mode = 1; /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A330;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[84], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x160), fclMakeVec2(tbl->x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x, 7.0f + tbl->y), 1, 0xA, 7);
                    fclBustupObjStartAlpha(*(void **)(work + 0x160), 0, 0xFF, 0, 0xA, 7); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x160), 55.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorMode(*(void **)(work + 0x160), 0x5B); /* measured: access-site fields lose this function's MATCH. */
                    ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x160)))->mode = 1; /* measured: access-site fields lose this function's MATCH. */
                    ((FclItemShopWork *)work)->state = 0xC;
                    *(s8 *)(work + 3) = 1; /* measured: access-site fields lose this function's MATCH. */
                    sdkSndStartStream(0, 0, 0, 1);
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            } else if (D_008C024E[0] & 0x80) {
                if (((FclItemShopWork *)work)->descriptionShown == 0) {
                    sdkSndStartStream(0, 1, 0, 3);
                }
                if (*(s8 *)(work + 2) == 1) { /* measured: access-site fields lose this function's MATCH. */
                    sdkSndStartStream(0, 1, 0, 4);
                }
                *(s8 *)(work + 2) ^= 1; /* measured: access-site fields lose this function's MATCH. */
            } else if (D_008C024E[0] & 0x20) {
                if (((FclItemShopWork *)work)->descriptionShown == 1) {
                    *(s8 *)(work + 2) = 0; /* measured: access-site fields lose this function's MATCH. */
                    sdkSndStartStream(0, 1, 0, 4);
                } else {
                    sdkSndStartStream(0, 0, 0, 2);
                    tbl = (F2_0033 *)D_0064A320;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x158), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartAlpha(*(void **)(work + 0x158), 0xFF, 0, 0, 5, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartUniformRevealScale(*(void **)(work + 0x158), 1.0f, 0.6f, 0, 5, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x158), 45.0f); /* measured: access-site fields lose this function's MATCH. */
                    cardFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, 0x52);
                    fclBustupObjStartPosition(*(void **)(work + 0x158), fclMakeVec2(tbl->x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2((sdkSpriteScaledWidth(cardFont) / 10.0f) * 2.0f + tbl->x + 0.0f,
                                                (sdkSpriteScaledHeight(cardFont) / 10.0f) * 2.0f + tbl->y + 0.0f),
                                  0, 5, 0);
                    sdkSpriteFreeNode(cardFont);
                    tbl = (F2_0033 *)D_0064A200;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xC8), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0xC8), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xF, 0);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xC8), 42.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A1F0;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xC0), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0xC0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xC, 0);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xC0), 43.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A1F8;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xC4), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0xC4), fclMakeVec2(tbl->x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(320.0f + tbl->x, tbl->y), 0, 0xC, 0);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xC4), 44.0f); /* measured: access-site fields lose this function's MATCH. */
                    for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                        layer2 = (s16)(panelIndex * 2);
                        cardIndex = panelIndex + 7;
                        coords = (f32 *)((u8 *)D_0064A090 + cardIndex * 8);
                        fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[7])[panelIndex], 1.0f, 0.7f, 0, 4, layer2);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0xFF, 0, 0, 4, layer2);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[7])[panelIndex], (f32)(panelIndex + 0x1A));
                        font = sdkSpriteNewNode(*(void **)(work + 0xC), cardIndex); /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[7])[panelIndex], fclMakeVec2(coords[0], coords[1]),
                                      fclMakeVec2((sdkSpriteScaledWidth(font) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(font) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      0, 4, layer2);
                        sdkSpriteFreeNode(font);
                    }
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x18), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartAlpha(*(void **)(work + 0x18), 0xFF, 0, 0, 5, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x18), 21.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A208;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xCC), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0xCC), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xA, 0);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xCC), 68.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A210;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xD0), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0xD0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(1064.0f, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xA, 0);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xD0), 60.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A218;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xD4), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0xD4), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x, ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(1064.0f, ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), 0, 0xA, /* measured: access-site fields lose this function's MATCH. */
                                  0);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xD4), 59.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartAlpha(*(void **)(work + 0x150), 0xFF, 0, 0, 0, 5); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x150), 56.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x198), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x198), 0xFF, 0, 0, 0, 5); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x198), 57.0f); /* measured: access-site fields lose this function's MATCH. */
                    *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
                        (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0x19C), fclMakeVec2(552.0f, 185.0f), fclMakeVec2(552.0f, 185.0f), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x19C), 0xFF, 0, 0, 0, 5); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x19C), 57.0f); /* measured: access-site fields lose this function's MATCH. */
                    *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
                        (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
                    if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) { /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1); /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), /* measured: access-site fields lose this function's MATCH. */
                                      fclMakeVec2(0x243, 185.0f), 0, 0, 0);
                    }
                    for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[21])[panelIndex], 0xFF, 0, 0, 5, 0);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[21])[panelIndex], 15.0f);
                    }
                    if (*(s8 *)(work + 2) == 1) { /* measured: access-site fields lose this function's MATCH. */
                        tbl = (F2_0033 *)D_0064A228;
                        fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[51], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(0x2A3, tbl->y),
                                      0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A230;
                        fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[52], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(0x413, tbl->y),
                                      0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A220;
                        fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[50], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(0x2AD, tbl->y),
                                      0, 0xA, 0);
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[68], 0, 1);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[69], 0, 1);
                    if (((FclItemShopWork *)work)->moonItemsUnlocked == 1) {
                        fclBustupObjStartTween(((FclItemShopWork *)work)->panels[81], 0.0f, 180.0f, 0, 7, 0);
                    }
                    if (((FclItemShopWork *)work)->discountDay == 1) {
                        fclBustupObjStartTween(((FclItemShopWork *)work)->panels[86], 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A348;
                        ((FclItemShopPanel *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[87]))->centerX = 0x231 - tbl->x;
                        ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x16C)))->centerY = 470.0f - tbl->y; /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartTween(*(u8 **)(work + 0x16C), 0.0f, -150.0f, 0, 0xA, 0); /* measured: access-site fields lose this function's MATCH. */
                        tbl = (F2_0033 *)D_0064A350;
                        ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x170)))->centerX = 0x231 - tbl->x; /* measured: access-site fields lose this function's MATCH. */
                        ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x170)))->centerY = 470.0f - tbl->y; /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartTween(*(u8 **)(work + 0x170), 0.0f, -150.0f, 0, 0xA, 0); /* measured: access-site fields lose this function's MATCH. */
                        tbl = (F2_0033 *)D_0064A358;
                        ((FclItemShopPanel *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[89]))->centerX = 0x231 - tbl->x;
                        ((FclItemShopPanel *)fclBustupObjGetWork(*(void **)(work + 0x174)))->centerY = 470.0f - tbl->y; /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartTween(*(u8 **)(work + 0x174), 0.0f, -30.0f, 0, 2, 0); /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartPositionMode(*(u8 **)(work + 0x174), ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x174)))->anchorPosition, /* measured: access-site fields lose this function's MATCH. */
                                      fclMakeVec2(-300.0f + tbl->x, 250.0f + tbl->y), 0, 2, 0x14, 1);
                    }
                    *(s32 *)(work + 0x2B0) = 0; /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[0], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(428.0f, 241.0f), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(D_0064A090[0], D_0064A090[1]), 0, 0xF, 5);
                    fclBustupObjStartTween(*(u8 **)(work + 0x10), 720.0f, 0.0f, 0, 0xF, 5); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A1D8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[41], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xB4), fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xF, 0xC);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xB4), 47.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A1E0;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[42], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xB8), fclMakeVec2(-200.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, /* measured: access-site fields lose this function's MATCH. */
                                  9, 0xC);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xB8), 33.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A1E8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[43], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xBC), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(153.0f, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xF, 0x18);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xBC), 48.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[90], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x178), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(203.0f, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0xF, 0x18);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x178), 48.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A0E8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[11], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x3C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x3C), 0, 0xFF, 0, 0xF, 0x25); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x3C), 46.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A290;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[64], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x110), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0x14, 0xC);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x110), 17.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A298;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[65], 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x114), fclMakeVec2(0x305, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, /* measured: access-site fields lose this function's MATCH. */
                                  0x14, 0xC);
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x114), 17.0f); /* measured: access-site fields lose this function's MATCH. */
                    for (fadeBand = 0; fadeBand < 4; fadeBand++) {
                        layer3 = (s16)(fadeBand * 3 + 0x14);
                        index = fadeBand + 3;
                        coords = (f32 *)((u8 *)D_0064A090 + index * 8);
                        fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0, 0);
                        fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0.7f, 1.0f, 0, 4, layer3);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0, 0xFF, 0, 4, layer3);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0, 0xFF, 0, 0, layer3);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[3])[fadeBand], (f32)(fadeBand + 0x1A));
                        iconFont = sdkSpriteNewNode(*(void **)(work + 0xC), index); /* measured: access-site fields lose this function's MATCH. */
                        fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[3])[fadeBand],
                                      fclMakeVec2((sdkSpriteScaledWidth(iconFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(iconFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      fclMakeVec2(coords[0], coords[1]), 0, 4, layer3);
                        sdkSpriteFreeNode(iconFont);
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[1], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x14), 0, 0xFF, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x14), 30.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[40], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0xB0), 0, 0xFF, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartUniformRevealScale(*(void **)(work + 0xB0), 0.35f, 1.0f, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0xB0), 52.0f); /* measured: access-site fields lose this function's MATCH. */
                    for (menuRevealPanel = 0; menuRevealPanel < 3; menuRevealPanel++) {
                        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], 0, 0);
                        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], 0, 0xFF, 0, 0xA, 0x14);
                        fclBustupObjStartUniformRevealScale(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], 0.35f, 1.0f, 0, 0xA, 0x14);
                        fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], (f32)(menuRevealPanel + 0x31));
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x58), 0, 0xFF, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x58), 80.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x5C), 0, 0xFF, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x5C), 81.0f); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A2A0;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x118), 0, 0xFF, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x118), 82.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    tbl = (F2_0033 *)D_0064A2A8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x11C), 0, 0xFF, 0, 0xA, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x11C), 83.0f); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), /* measured: access-site fields lose this function's MATCH. */
                                  fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
                    for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                        fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0, 1);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0, 0xFF, 0, 0xA, 0x14);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[12])[panelIndex], (f32)(panelIndex + 0x4A));
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[20], 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x60), 0, 0xFF, 0, 0xF, 0x14); /* measured: access-site fields lose this function's MATCH. */
                    fclBustupObjSetAnchorValue(*(void **)(work + 0x60), 14.0f); /* measured: access-site fields lose this function's MATCH. */
                    ((FclItemShopWork *)work)->state = 0xE;
                }
            }
            ((FclItemShopWork *)work)->cursorMoved = 0;
        }
        break;
    case 12:
        for (panelIndex = 0; panelIndex < 0x24; panelIndex++) {
            *(u8 *)(work + panelIndex + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f); /* measured: access-site fields lose this function's MATCH. */
            if (*(s8 *)(work + panelIndex + 0x2D8) == 1) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandPosition[panelIndex] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(panelIndex * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, *(u8 *)(work + panelIndex + 0x2B4), 0); /* measured: access-site fields lose this function's MATCH. */
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                      ((FclItemShopWork *)work)->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(((FclItemShopWork *)work)->selectedItem)), 0x35,
                      (void *)((FclItemShopWork *)work)->spriteFile, 0xAB);
        fclItemShopDrawList(shopTask);
        *(u16 *)(fclBustupObjGetWork(((FclItemShopWork *)work)->panels[98]) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
        if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) { /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[48], 1) != 0) {
            break;
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[100], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1A0), fclMakeVec2(0x167, 134.0f), fclMakeVec2(0x167, 134.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x1A0), 57.0f); /* measured: access-site fields lose this function's MATCH. */
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x1A0)) + 0xF8) = *(s8 *)(work + 3) % 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x1A0), 0x61); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[101], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1A4), fclMakeVec2(332.0f, 134.0f), fclMakeVec2(332.0f, 134.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0x1A4), 57.0f); /* measured: access-site fields lose this function's MATCH. */
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x1A4)) + 0xF8) = *(s8 *)(work + 3) / 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x1A4), 0x61); /* measured: access-site fields lose this function's MATCH. */
        if (*(s8 *)(work + 3) / 10 == 0) { /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A4), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartPosition(*(void **)(work + 0x1A0), fclMakeVec2(346.0f, 134.0f), fclMakeVec2(346.0f, 134.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[36], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xA0), fclMakeVec2(45.0f, 133.0f), fclMakeVec2(45.0f, 133.0f), 0, 0, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorValue(*(void **)(work + 0xA0), 53.0f); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0xA0), 0x61); /* measured: access-site fields lose this function's MATCH. */
        frFontExDrawTextDeferred(82.0f, 132.0f, 58.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      datGetItemNameId((s16)yListValueAt(*(s16 *)(work + 4))), 0, 0, D_007950B0); /* measured: access-site fields lose this function's MATCH. */
        if (D_008C024E[0] & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            sprintf(buf, "%d", *(s8 *)(work + 3)); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowSetSlotString(*(s8 *)(work + 8), 1, buf); /* measured: access-site fields lose this function's MATCH. */
            sprintf(buf, "%d", *(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4)))); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowSetSlotString(*(s8 *)(work + 8), 2, buf); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 1); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowSetSlotParam(*(s8 *)(work + 8), 0); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowSetSlotFlag(*(s8 *)(work + 8), 0); /* measured: access-site fields lose this function's MATCH. */
            nmMesWindowRequestRefresh();
            ((FclItemShopWork *)work)->state = 0xD;
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s8 *)(work + 3) != (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))))) { /* measured: access-site fields lose this function's MATCH. */
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclAddClamped(*(s8 *)(work + 3), 1, /* measured: access-site fields lose this function's MATCH. */
                                              (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4)))), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            if (*(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))) > fclGetMoney()) { /* measured: access-site fields lose this function's MATCH. */
                *(s8 *)(work + 3) = fclGetMoney() / fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))); /* measured: access-site fields lose this function's MATCH. */
            }
            tbl = (F2_0033 *)D_0064A328;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[83], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s8 *)(work + 3) != 1) { /* measured: access-site fields lose this function's MATCH. */
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclSubClamped(*(s8 *)(work + 3), 1, 1, 0x63, 1); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A330;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[84], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x2000) {
            if (*(s8 *)(work + 3) != (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))))) { /* measured: access-site fields lose this function's MATCH. */
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclAddClamped(*(s8 *)(work + 3), 0xA, /* measured: access-site fields lose this function's MATCH. */
                                              (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4)))), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            if (*(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))) > fclGetMoney()) { /* measured: access-site fields lose this function's MATCH. */
                *(s8 *)(work + 3) = fclGetMoney() / fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))); /* measured: access-site fields lose this function's MATCH. */
            }
            tbl = (F2_0033 *)D_0064A328;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[83], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x8000) {
            if (*(s8 *)(work + 3) != 1) { /* measured: access-site fields lose this function's MATCH. */
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclSubClamped(*(s8 *)(work + 3), 0xA, 1, 0x63, 1); /* measured: access-site fields lose this function's MATCH. */
            tbl = (F2_0033 *)D_0064A330;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[84], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C024E[0] & 0x20) {
            sdkSndStartStream(0, 0, 0, 2);
            tbl = (F2_0033 *)D_0064A210;
            fclBustupObjStartPosition(*(void **)(work + 0xD0), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD0)))->anchorPosition.x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[49],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.x, /* measured: access-site fields lose this function's MATCH. */
                                        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), 0, 7, 0); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->state = 0xB;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[83], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[84], 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A0), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A4), 0, 1); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(*(void **)(work + 0xA0), 0, 1); /* measured: access-site fields lose this function's MATCH. */
        }
        break;
    case 13:
        for (confirmationBand = 0; confirmationBand < 0x24; confirmationBand++) {
            *(u8 *)(work + confirmationBand + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f); /* measured: access-site fields lose this function's MATCH. */
            if (*(s8 *)(work + confirmationBand + 0x2D8) == 1) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandPosition[confirmationBand] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(confirmationBand * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, *(u8 *)(work + confirmationBand + 0x2B4), 0); /* measured: access-site fields lose this function's MATCH. */
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                      ((FclItemShopWork *)work)->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(((FclItemShopWork *)work)->selectedItem)), 0x35,
                      (void *)((FclItemShopWork *)work)->spriteFile, 0xAB);
        fclItemShopDrawList(shopTask);
        frFontExDrawTextDeferred(82.0f, 132.0f, 58.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      datGetItemNameId((s16)yListValueAt(*(s16 *)(work + 4))), 0, 0, D_00795E60); /* measured: access-site fields lose this function's MATCH. */
        if (nmMesWindowSlotStatus(((FclItemShopWork *)work)->messageSlot) != 0) {
            nmMesWindowStepSlotRelease(*(s8 *)(work + 8)); /* measured: access-site fields lose this function's MATCH. */
            break;
        }
        ((FclItemShopWork *)work)->state = 0xC;
        if (!nmMesWindowGetSlotState(*(s8 *)(work + 8))) { /* measured: access-site fields lose this function's MATCH. */
            datItemSetCount((s16)yListValueAt(*(s16 *)(work + 4)), /* measured: access-site fields lose this function's MATCH. */
                          (u8)(*(s8 *)(work + 3) + (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))))); /* measured: access-site fields lose this function's MATCH. */
            fclAddMoney(fclGetMoney() -
                          *(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, (s16)yListValueAt(*(s16 *)(work + 4)))); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->moneyX = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
            *(u16 *)(fclBustupObjGetWork(((FclItemShopWork *)work)->panels[98]) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
                (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
            *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) = /* measured: access-site fields lose this function's MATCH. */
                (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46; /* measured: access-site fields lose this function's MATCH. */
            if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) { /* measured: access-site fields lose this function's MATCH. */
                fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1); /* measured: access-site fields lose this function's MATCH. */
                fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, /* measured: access-site fields lose this function's MATCH. */
                              0);
            }
            tbl = (F2_0033 *)D_0064A210;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[48],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD0)))->anchorPosition.x, tbl->y), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[49],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.x, /* measured: access-site fields lose this function's MATCH. */
                                        ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(tbl->x, ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0xD4)))->anchorPosition.y), 0, 7, 0); /* measured: access-site fields lose this function's MATCH. */
            ((FclItemShopWork *)work)->state = 0xB;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[83], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[84], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[100], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[101], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[36], 0, 1);
            sdkSndStartStream(0, 0, 0, 6);
        }
        nmMesWindowDestroySlot(*(s8 *)(work + 8)); /* measured: access-site fields lose this function's MATCH. */
        break;
    case 14:
        for (returnBand = 0; returnBand < 0x24; returnBand++) {
            *(u8 *)(work + returnBand + 0x2B4) = fclEaseInterpolate(0, 255.0f, 0.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 5.0f); /* measured: access-site fields lose this function's MATCH. */
            if (*(s8 *)(work + returnBand + 0x2D8) == 1) { /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopWork *)work)->bandPosition[returnBand] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(returnBand * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, *(u8 *)(work + returnBand + 0x2B4), 0); /* measured: access-site fields lose this function's MATCH. */
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2); /* measured: access-site fields lose this function's MATCH. */
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 5, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[0], 1) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x10), 3) == 0 && /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[41], 1) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[42], 1) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[64], 1) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[65], 1) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[3], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[4], 4) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[5], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[6], 4) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[1], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[40], 4) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0xB0), 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[91], 2) == 0 && /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x17C), 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[92], 2) == 0 && /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x180), 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[93], 2) == 0 && /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x184), 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[18], 2) == 0 && /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[19], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[66], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[67], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[12], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[13], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[14], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[15], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[16], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[17], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[20], 2) == 0) {
            ((FclItemShopWork *)work)->state = 5;
        } else if (fclBustupObjTestFlagBit(*(void **)(work + 0x10), 1) != 0 && (D_008C024E[0] & 0x20)) { /* measured: access-site fields lose this function's MATCH. */
            sdkSndStartStream(0, 0, 0, 2);
            ((FclItemShopWork *)work)->moneyStartX = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
            ((FclItemShopWork *)work)->moneyStartY = 15.0f;
            ((FclItemShopWork *)work)->moneyEndX = 0x28A;
            ((FclItemShopWork *)work)->moneyEndY = 15.0f;
            ((FclItemShopWork *)work)->moneyElapsed = 0;
            fclBustupObjStartPosition(*(void **)(work + 0x10), ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x10)))->anchorPosition, /* measured: access-site fields lose this function's MATCH. */
                          fclMakeVec2(0x28A, ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x10)))->anchorPosition.y), 0, 0xA, 0); /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjStartTween(*(u8 **)(work + 0x10), ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x10)))->tweenValue, /* measured: access-site fields lose this function's MATCH. */
                          ((FclObject *)fclBustupObjGetWork(*(void **)(work + 0x10)))->targetTween, 0, 0xA, 0); /* measured: access-site fields lose this function's MATCH. */
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[41]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[42]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[43]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[90]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[11]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[64]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[65]);
            for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                fclBustupStartSlide(((FclItemShopWork *)work)->panels[panelIndex + 3]);
            }
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[1]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[40]);
            for (panelIndex = 0; panelIndex < 3; panelIndex++) {
                fclBustupStartSlide(((FclItemShopWork *)work)->panels[panelIndex + 91]);
            }
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[18]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[19]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[66]);
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[67]);
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupStartSlide(((FclItemShopWork *)work)->panels[panelIndex + 12]);
            }
            fclBustupStartSlide(((FclItemShopWork *)work)->panels[20]);
            fadeBeginTransition(1, 0xA);
            ((FclItemShopWork *)work)->state = 0xF;
        }
        break;
    case 15:
        if (fadeStatus() == 0) {
            break;
        }
        return -1;
    case 16:
        if (kwlnTaskGetTaskByName(D_0064A3C0) != 0) {
            break;
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[panelIndex + 3], 0, 0xFF, 0, 5, 0);
        }
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[0], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[64], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[65], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[1], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[41], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[42], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[43], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[90], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[11], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[40], 0, 0xFF, 0, 5, 0);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[panelIndex + 91], 0, 0xFF, 0, 5, 0);
        }
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[18], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[19], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[66], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[67], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[12], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[16], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[14], 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[20], 0, 0xFF, 0, 5, 0);
        ((FclItemShopWork *)work)->state = 5;
        break;
    case 17:
        ((FclItemShopWork *)work)->moneyX =
            fclEaseInterpolate(0, ((FclItemShopWork *)work)->moneyStartX, ((FclItemShopWork *)work)->moneyEndX, ((FclItemShopWork *)work)->moneyElapsed, 10.0f);
        *(s16 *)(work + 0x1EA) = fclAddClamped(*(s16 *)(work + 0x1EA), 1, 10, 1, 1); /* measured: access-site fields lose this function's MATCH. */
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[panelIndex + 94]))->tweenValue = 0.01f;
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[1], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[3], 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 1) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[4], 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x20), 2) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x20), 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[5], 4) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x24), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x24), 1) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[6], 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x28), 2) != 0 || /* measured: access-site fields lose this function's MATCH. */
            fclBustupObjTestFlagBit(*(void **)(work + 0x28), 1) != 0) { /* measured: access-site fields lose this function's MATCH. */
            break;
        }
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 1);
        fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[40], 0x65);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 91], 0x65);
        }
        fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[64], 0x65);
        fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[65], 0x65);
        fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[20], 0x65);
        for (exitPanel = 0; exitPanel < 4; exitPanel++) {
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[94])[exitPanel], 13, 0);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[94])[exitPanel], 0, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[94])[exitPanel], 0.1f, 2.7f, 0, 0xA, 0);
            fclBustupObjStartTween((&((FclItemShopWork *)work)->panels[94])[exitPanel], 0.0f, exitPanel * 0x5A, 0, 0, 0);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[94])[exitPanel], 1.0f);
            ((FclItemShopPanel *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[94])[exitPanel]))->centerX = ((FclItemShopPanel *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[94])[exitPanel]))->centerY = 0;
            ((FclObject *)fclBustupObjGetWork((&((FclItemShopWork *)work)->panels[94])[exitPanel]))->alpha = 2;
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[94])[exitPanel], 0x64);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[0], 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(D_0064A090[0], D_0064A090[1]), fclMakeVec2(0x28A, 241.0f), /* measured: access-site fields lose this function's MATCH. */
                      0, 0xA, 0);
        fclBustupObjStartTween(*(u8 **)(work + 0x10), -720.0f, 0.0f, 0, 0xA, 0); /* measured: access-site fields lose this function's MATCH. */
        fclBustupObjSetAnchorMode(*(void **)(work + 0x10), 0x62); /* measured: access-site fields lose this function's MATCH. */
        fadeBeginTransition(1, 0x1E);
        ((FclItemShopWork *)work)->state = 0x12;
        break;
    case 18:
        if (fadeStatus() == 0) {
            break;
        }
        return -1;
    }
    return 0;
}
#pragma opt_loop_invariants off /* measured: restore the baseline */

// Item shop task destroy: releases the item list, the CDVD and sprite handles, then calls the destroy jump-table entry.
// FUN_0033BDC0
void fclItemShopDestroy(u8 *shopTask) {
    /* Earlier whole-local typing grew 128B to 132B; only the two independently
       measured byte accesses below remain necessary. */
    u8 *work = ((SdkTask *)shopTask)->work;

    yListDestroy();
    if ((s32)((FclItemShopWork *)work)->directory != 0) {
        H_Cdvd_Destroy((void *)(s32)((FclItemShopWork *)work)->directory);
    }
    if (((FclItemShopWork *)work)->spriteFile != 0) {
        sdkSpriteRelease((void *)((FclItemShopWork *)work)->spriteFile);
        *(s32 *)(work + 0xC) = 0; /* measured: access-site fields lose this function's MATCH. */
    }
    jtbl_008873EC[0](*(void **)((u8 *)shopTask + 0x38)); /* measured: access-site fields lose this function's MATCH. */
}

// Creates the item shop task under task: allocates the 0x42C-byte work, sets the initial layout values and item flags, then registers the update and destroy callbacks.
/* measured: object_size 324/window 336, normalized_diff 0 (retail tail is
   zero padding). MWCCPS2 needs opt_loop_invariants on to hoist the loop's
   `1` constant before the entry jump, matching retail's preheader materialisation. */
#pragma opt_loop_invariants on
// FUN_0033BE40
u8 *fclItemShopCreate(u8 *shopTask) {
    /* Earlier whole-local typing grew 324B to 336B; access-site fields match
       except the individually measured moon-item store below. */
    s32 i;
    s32 one;
    u8 *createdTask;
    s8 *allocatedWork;

    chkmemAllocSiteTag(D_0064A380, 0x958);
    allocatedWork = (s8 *)D_008873F4[0](1, 0x42C, 0x40000);
    createdTask = kwlnTaskCreateChild((void *)(shopTask), (const void *)(D_0064A3D8), 0xF, 0, 0, fclItemShopUpdate, fclItemShopDestroy, (u8 *)((u8 *)allocatedWork));
    ((FclItemShopWork *)allocatedWork)->state = 0;
    ((FclItemShopWork *)allocatedWork)->spriteFile = 0;
    ((FclItemShopWork *)allocatedWork)->moneyX = (f32)0x28A;
    ((FclItemShopWork *)allocatedWork)->moneyY = 15.0f;
    ((FclItemShopWork *)allocatedWork)->moneyElapsed = 0;
    ((FclItemShopWork *)allocatedWork)->unk1EC = 0;
    ((FclItemShopWork *)allocatedWork)->menuSelection = 0;
    ((FclItemShopWork *)allocatedWork)->bandFadeElapsed = 0;
    ((FclItemShopWork *)allocatedWork)->bandAngle = 0.0f;
    ((FclItemShopWork *)allocatedWork)->bandElapsed = 0;
    ((FclItemShopWork *)allocatedWork)->moonItemsUnlocked = 0;
    one = 1;
    i = 0;
    while ((s16)i < 0x24) {
        ((FclItemShopWork *)allocatedWork)->bandActive[(s16)i] = one;
        i = (s16)(i + 1);
    }
    if (fclUnlockMoonPhaseItems() == 1) {
        *(s8 *)(allocatedWork + 0x424) = 1; /* measured: access-site fields lose this function's MATCH. */
    }
    yListCreate(0x10000, 0, 2, 1);
    return createdTask;
}
/* measured: closes the opt_loop_invariants scope required by func_0033be40. */
#pragma opt_loop_invariants off

/* Start the shop exit animation, including money-position interpolation. */
// FUN_0033BF90
void fclItemShopStartExit(u8 *shopTask) {
    /* Earlier whole-local typing changed register allocation at unchanged size;
       access-site fields retain only the independently measured exceptions below. */
    s32 i;
    u8 *work;
    s32 itemIndex;
    s64 layer;
    f32 *coords;
    u8 *item;
    void *font;
    register u8 *table;
    f32 x;
    f32 y;
    F2_0033 pos0;
    F2_0033 pos1;
    F2_0033 pos2;
    F2_0033 pos3;
    F2_0033 pos4;
    F2_0033 pos5;
    F2_0033 pos6;
    F2_0033 pos7;
    F2_0033 pos8;
    F2_0033 pos9;
    F2_0033 pos10;
    F2_0033 pos11;

    work = ((SdkTask *)shopTask)->work;
    i = 0;
    while ((s16)i < 4) {
        layer = (s64)(s16)((s16)i * 3);
        itemIndex = (s16)i + 3;
        coords = (f32 *)((u8 *)D_0064A090 + (itemIndex * 8));
        item = work + (s16)i * 4 + 0x1C; /* measured: a typed panel-slot cursor changes this function's instructions. */
        fclBustupObjStartUniformRevealScale((void *)*(s32 *)item, 1.0f, 0.5f, 0, 10, layer);
        fclBustupObjStartAlpha((void *)*(s32 *)item, 0xFF, 0, 0, 10, layer);
        fclBustupObjSetAnchorMode((void *)*(s32 *)item, 0xAC);
        font = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, itemIndex);
        pos0 = fclMakeVec2(coords[0], coords[1]);
        x = (sdkSpriteScaledWidth(font) / 10.0f) * 1.5f + coords[0] + 0.0f;
        y = (sdkSpriteScaledHeight(font) / 10.0f) * 1.5f + coords[1] + 0.0f;
        pos1 = fclMakeVec2(x, y);
        fclBustupObjStartPosition((void *)*(s32 *)item, pos0, pos1, 0, 10, layer);
        sdkSpriteFreeNode(font);
        i = (s16)(i + 1);
    }
    fclBustupObjChangeFlagBit((void *)(s32)((FclItemShopWork *)work)->panels[1], 0, 0);
    fclBustupObjStartAlpha((void *)*(s32 *)(work + 0x14), 0xFF, 0, 0, 10, 0); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorMode((void *)*(s32 *)(work + 0x14), 0xAC); /* measured: access-site fields lose this function's MATCH. */
    table = (u8 *)D_0064A1D8;
    pos2 = fclMakeVec2(((F2_0033 *)table)->x, ((F2_0033 *)table)->y);
    pos3 = fclMakeVec2(-180.0f, *(f32 *)(table + 4)); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[41], pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    pos4 = fclMakeVec2(((F2_0033 *)table)->x, ((F2_0033 *)table)->y);
    pos5 = fclMakeVec2(-200.0f, *(f32 *)(table + 4)); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[42], pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    pos6 = fclMakeVec2(153.0f, ((F2_0033 *)table)->y);
    pos7 = fclMakeVec2(-100.0f, *(f32 *)(table + 4)); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[43], pos6, pos7, 0, 0x14, 0);
    pos8 = fclMakeVec2(203.0f, *(f32 *)(table + 4)); /* measured: access-site fields lose this function's MATCH. */
    pos9 = fclMakeVec2(-50.0f, *(f32 *)(table + 4)); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[90], pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    pos10 = fclMakeVec2(((F2_0033 *)table)->x, ((F2_0033 *)table)->y);
    pos11 = fclMakeVec2(-200.0f, *(f32 *)(table + 4)); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[11], pos10, pos11, 0, 0xF, 0);
    fclBustupObjStartUniformRevealScale((void *)*(s32 *)(work + 0xB0), 1.0f, 4.5f, 0, 0xF, 0); /* measured: access-site fields lose this function's MATCH. */
    i = 0;
    while ((s16)i < 3) {
        fclBustupObjStartUniformRevealScale((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 1.0f, 4.5f, 0, 0xF, 0); /* measured: access-site fields lose this function's MATCH. */
        i = (s16)(i + 1);
    }
    fclBustupObjSetAnchorValue((void *)*(s32 *)(work + 0x110), 84.0f); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorValue((void *)*(s32 *)(work + 0x114), 84.0f); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorValue((void *)*(s32 *)(work + 0x60), 83.0f); /* measured: access-site fields lose this function's MATCH. */
    ((FclItemShopWork *)work)->moneyStartX = 580.0f - (f32)fclDecimalDigitCount(fclGetMoney()) * 21.0f;
    ((FclItemShopWork *)work)->moneyStartY = 15.0f;
    ((FclItemShopWork *)work)->moneyEndX = (f32)0x28A;
    ((FclItemShopWork *)work)->moneyEndY = 15.0f;
    ((FclItemShopWork *)work)->moneyElapsed = 0;
    ((FclItemShopWork *)work)->state = 0x11;
}

/* Item list panel: the selected-item header, or five scrolling item rows with
   their frame, name and price. Shaping that matters: the frame and name
   draws are inline helpers (their float y parameters live in $f20 and the
   shared row top is one int that retail spills), the price goes out through
   its own pos/colour pair, the cursor tables are read through an F2_0033
   pointer (kept in $s1 across the reset call), and the shaded colour is
   written `green = blue = 0` (the andi on $zero). */
static inline void fclShopDrawItemFrame(u8 *p, f32 y, u8 red, u8 green, u8 blue)
{
    sdkSpriteDrawQueued(44.0f, y, 62.0f, fclPackRgba(0xFF, red, green, blue), 0xFF, 0x24,
                  (void *)((FclItemShopWork *)p)->spriteFile, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

static inline void fclShopDrawItemName(s16 item, f32 y, u8 red, u8 green, u8 blue)
{
    frFontExDrawTextDeferred(78.0f, y, 62.0f, fclPackRgba(red, green, blue, 0xFF), 0, 1,
                  datGetItemNameId((s16)yListValueAt(item)), 0, 0, D_00795E60);
}

// Draws the item list rows from index i up to bound: each row shows its item name and price in its highlight colour.
// FUN_0033C490
void fclItemShopDrawList(u8 *shopTask)
{
    /* Access-site typing preserves the byte cursor; remaining raw reads are
       individually measured exceptions, not a whole-layout fallback. */
    u8 *p;
    s32 color;
    u32 value;
    s16 i;
    s16 row;
    s32 bound;
    u8 red;
    u8 green;
    u8 blue;
    u32 price;
    s32 y;
    s32 top;
    f32 fy;
    F2_0033 *tbl;
    F2_0033 pos1;
    FclDrawColor col1;
    F2_0033 pos2;
    FclDrawColor col2;

    p = ((SdkTask *)shopTask)->work;
    if (((FclItemShopWork *)p)->descriptionShown == 1) {
        sdkSpriteDrawQueued(44.0f, 77.0f, 62.0f, fclPackRgba(0xFF, 0x26, 0x26, 0x26), 0xFF, 0x24,
                      (void *)((FclItemShopWork *)p)->spriteFile, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
        color = fclPackRgba(0x26, 0x26, 0x26, 0xFF);
        value = datGetItemNameId((s16)yListValueAt(((FclItemShopWork *)p)->selectedItem));
        frFontExDrawTextDeferred(78.0f, 77.0f, 62.0f, color, 0, 1, value, 0, 0, D_00795E60);
        pos1 = fclMakeVec2(406.0f, 84.0f);
        col1 = fclMakeDrawColor(0x26, 0x26, 0x26, 0xFF);
        fclShopDrawNumber(pos1, 62.0f, col1,
                      fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(p + 4))), 0x19, /* measured: access-site fields lose this function's MATCH. */
                      *(void **)(p + 0xC), 0xAB); /* measured: access-site fields lose this function's MATCH. */
        fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(*(s16 *)(p + 4))), -1, 1, 0, 4, 0xAA, /* measured: access-site fields lose this function's MATCH. */
                      71.0f, 135.0f, 62.0f);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[68], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[69], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[51], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[52], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[23], 0, 1);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[24], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[50], 0, 0);
        return;
    }
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[51], 0, 1);
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[52], 0, 1);
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[23], 0, 0);
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[24], 0, 1);
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[50], 0, 1);
    tbl = (F2_0033 *)D_0064A2B0;
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[68], 0, 0);
    fy = tbl->x;
    ((FclObject *)fclBustupObjGetWork(*(u8 **)(p + 0x120)))->anchorPosition.x = fy; /* measured: access-site fields lose this function's MATCH. */
    fy = tbl->y + (f32)(((FclItemShopWork *)p)->cursorRow * 28);
    ((FclObject *)fclBustupObjGetWork(*(u8 **)(p + 0x120)))->anchorPosition.y = fy; /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorValue(*(void **)(p + 0x120), 63.0f); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorMode(*(u8 **)(p + 0x120), 0x5B); /* measured: access-site fields lose this function's MATCH. */
    tbl = (F2_0033 *)D_0064A2B8;
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[69], 0, 0);
    fy = tbl->x;
    ((FclObject *)fclBustupObjGetWork(*(u8 **)(p + 0x124)))->anchorPosition.x = fy; /* measured: access-site fields lose this function's MATCH. */
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28); /* measured: access-site fields lose this function's MATCH. */
    ((FclObject *)fclBustupObjGetWork(*(u8 **)(p + 0x124)))->anchorPosition.y = fy; /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorValue(*(void **)(p + 0x124), 63.0f); /* measured: access-site fields lose this function's MATCH. */
    fclBustupObjSetAnchorMode(*(u8 **)(p + 0x124), 0x5B); /* measured: access-site fields lose this function's MATCH. */
    i = ((FclItemShopWork *)p)->selectedItem - *(s16 *)(p + 6); /* measured: access-site fields lose this function's MATCH. */
    row = 0;
    bound = i + 5;
    for (; i < bound; i++, row++) {
        if (i >= yListCount()) {
            continue;
        }
        red = green = blue = 0xFF;
        if (i == *(s16 *)(p + 4)) { /* measured: access-site fields lose this function's MATCH. */
            red = green = blue = 0x26;
        } else {
            price = fclItemShopDiscountedPrice(shopTask, yListValueAt(i));
            if (fclGetMoney() < price) {
                red = 0x4F;
                green = blue = 0;
            } else if ((u8)datItemCount((s16)yListValueAt(i)) == 0x63) {
                red = 0x4F;
                green = blue = 0;
            } else if ((u8)clndGetMoonPhase(yListValueAt(i)) & 1) {
                red = 0x9F;
                blue = 0x2F;
            }
        }
        y = row * 28;
        top = y + 0x4D;
        fclShopDrawItemFrame(p, (f32)top, red, green, blue);
        fclShopDrawItemName(i, (f32)top, red, green, blue);
        pos2 = fclMakeVec2(406.0f, (f32)(y + 0x54));
        col2 = fclMakeDrawColor(red, green, blue, 0xFF);
        fclShopDrawNumber(pos2, 62.0f, col2, fclItemShopDiscountedPrice(shopTask, yListValueAt(i)),
                      0x19, *(void **)(p + 0xC), 0xAB); /* measured: access-site fields lose this function's MATCH. */
    }
}
// Discount days reduce the selected item price by 20 percent, using unsigned division.
// FUN_0033CBC0
u32 fclItemShopDiscountedPrice(void *task, s32 itemId) {
    u8 *work = ((SdkTask *)task)->work;
    u32 discount = (u32)((s32)(((FclItemShopWork *)work)->discountDay * (s32)datItemPrice((s64)(s16)itemId)) * 0x14) / 100U;

    return (u32)datItemPrice((s64)(s16)(s32)itemId) - discount;
}

// Update panel position tweens and queue its sprite with current color and scale.
/* The packed sprite ABI starts at work+4 and copies 0xF0 bytes; its ordinary
   fields are typed independently, retaining only measured alias-sensitive sites. */
/* measured: 1216B/1216B MATCH (304 instrs, 0 edits + 9 reloc-only). Re-probed from scratch: floats-first func_0025ecd0 spelling (f32,f32,f32 first, then color/ints, then f32,f32,f32, pointer last) with u16 0xF8 load (lhu) and inline s16/2 division gives retail scheduling; shift+temp hoisting was +33, s16 F8 was +2 (35), archive ints-first is a compile error under this prototype. Mixed-arg orders tested explicitly. */
// FUN_0033CC40
s32 fclItemShopPanelUpdate(u8 *task) {
    /* Earlier whole-local typing grew 1216B to 1252B; access-site fields now
       match except the independently measured byte accesses below. */
    f32 minimumScale;
    f32 scaleY;
    f32 scaleX;
    s16 delay;
    s16 elapsed;
    s16 duration;
    s8 positionMode;
    s8 completedMode;
    u8 *queueNode;
    u8 *panelWork;

    panelWork = ((SdkTask *)task)->work;
    memcpy(panelWork + 4, fclSpriteUpdateTweens(panelWork + 4), 0xF0);
    if (fclBustupObjTestFlagBit((u8 *)task, 0xA) == 1) {
        delay = ((FclObject *)panelWork)->positionDelay;
        if (delay == 0) {
            positionMode = ((FclObject *)panelWork)->mode;
            switch (positionMode) {
            case 0:
                ((FclObject *)panelWork)->anchorPosition.x = fclEaseInterpolate(
                    0, ((FclObject *)panelWork)->targetPosition.x, ((FclObject *)panelWork)->positionEnd.x,
                    (f32)((FclObject *)panelWork)->positionDuration, (f32)((FclObject *)panelWork)->positionFrames);
                ((FclObject *)panelWork)->anchorPosition.y = fclEaseInterpolate(
                    ((FclObject *)panelWork)->positionEase, ((FclObject *)panelWork)->targetPosition.y,
                    ((FclObject *)panelWork)->positionEnd.y, (f32)*(s16 *)(panelWork + 0x36), /* measured: access-site fields lose this function's MATCH. */
                    (f32)(*(s16 *)(panelWork + 0x34) / 2)); /* measured: access-site fields lose this function's MATCH. */
                break;
            case 1:
                ((FclObject *)panelWork)->anchorPosition.x = fclEaseInterpolate(
                    ((FclObject *)panelWork)->positionEase, ((FclObject *)panelWork)->targetPosition.x,
                    ((FclObject *)panelWork)->positionEnd.x, (f32)((FclObject *)panelWork)->positionDuration,
                    (f32)(((FclObject *)panelWork)->positionFrames / 2));
                ((FclObject *)panelWork)->anchorPosition.y = fclEaseInterpolate(
                    0, ((FclObject *)panelWork)->targetPosition.y, ((FclObject *)panelWork)->positionEnd.y,
                    (f32)*(s16 *)(panelWork + 0x36), (f32)*(s16 *)(panelWork + 0x34)); /* measured: access-site fields lose this function's MATCH. */
                break;
            case 2:
                ((FclObject *)panelWork)->anchorPosition.x = fclEaseInterpolate(
                    1, ((FclObject *)panelWork)->targetPosition.x, ((FclObject *)panelWork)->positionEnd.x,
                    (f32)((FclObject *)panelWork)->positionDuration, (f32)((FclObject *)panelWork)->positionFrames);
                ((FclObject *)panelWork)->anchorPosition.y = fclEaseInterpolate(
                    2, ((FclObject *)panelWork)->targetPosition.y, ((FclObject *)panelWork)->positionEnd.y,
                    (f32)*(s16 *)(panelWork + 0x36), (f32)*(s16 *)(panelWork + 0x34)); /* measured: access-site fields lose this function's MATCH. */
                *(f32 *)(panelWork + 0x30) = (f32)( /* measured: access-site fields lose this function's MATCH. */
                    *(f32 *)(panelWork + 0x30) - /* measured: access-site fields lose this function's MATCH. */
                    fclEaseInterpolate(1, 0.0f, 100.0f,
                                  (f32)*(s16 *)(panelWork + 0x36), (f32)(*(s16 *)(panelWork + 0x34) / 2))); /* measured: access-site fields lose this function's MATCH. */
                break;
            }
            duration = ((FclObject *)panelWork)->positionFrames;
            elapsed = ((FclObject *)panelWork)->positionDuration;
            if (elapsed < duration) {
                *(s16 *)(panelWork + 0x36) = fclAddClamped( /* measured: access-site fields lose this function's MATCH. */
                    (s32)elapsed, 1, (s32)duration, 0, 1);
            } else {
                ((FclObject *)panelWork)->anchorPosition.x = ((FclObject *)panelWork)->positionEnd.x;
                ((FclObject *)panelWork)->anchorPosition.y = ((FclObject *)panelWork)->positionEnd.y;
                completedMode = *(s8 *)(panelWork + 0x3B); /* measured: access-site fields lose this function's MATCH. */
                if (completedMode == 0) {
                    *(f32 *)(panelWork + 0x30) = ((FclObject *)panelWork)->targetPosition.y; /* measured: access-site fields lose this function's MATCH. */
                } else if (completedMode == 1) {
                    *(f32 *)(panelWork + 0x2C) = ((FclObject *)panelWork)->targetPosition.x; /* measured: access-site fields lose this function's MATCH. */
                }
                fclBustupObjChangeFlagBit((u8 *)task, 0xA, 1);
            }
        } else {
            *(s16 *)(panelWork + 0x38) = fclSubClamped(delay, 1, 0, 0, 1); /* measured: access-site fields lose this function's MATCH. */
        }
    }
    if (fclBustupObjTestFlagBit((u8 *)task, 0) == 1) {
        if (fclBustupObjTestFlagBit((u8 *)task, 0xD) == 1) {
            queueNode = (u8 *)PrimAllocQueueNode();
            ((PrimQueueNode *)queueNode)->callback = (void *)fclCombineInitRenderStates;
            ((PrimQueueNode *)queueNode)->argument.handle = 0;
            PrimAppendNode(
                (void *)((u8 *)D_00793E80 +
                         (((FclObject *)panelWork)->anchorMode * 0x30)),
                queueNode);
            sdkSpriteDrawQueued(
                ((FclObject *)panelWork)->anchorPosition.x, ((FclObject *)panelWork)->anchorPosition.y,
                ((FclObject *)panelWork)->anchorValue,
                fclPackRgba(0xFF, ((FclObject *)panelWork)->color.c0,
                              ((FclObject *)panelWork)->color.c1, ((FclObject *)panelWork)->color.c2),
                ((FclObject *)panelWork)->alpha, (u16)((FclObject *)panelWork)->anchorIndex,
                (void *)*(s32 *)(panelWork + 0xF4), 0, /* measured: access-site fields lose this function's MATCH. */
                ((FclItemShopPanel *)panelWork)->centerX, ((FclItemShopPanel *)panelWork)->centerY,
                ((FclObject *)panelWork)->tweenValue,
                ((FclObject *)panelWork)->scaleX, ((FclObject *)panelWork)->scale,
                (void *)((u8 *)D_00793E80 + (*(s32 *)(panelWork + 0xFC) * 0x30))); /* measured: access-site fields lose this function's MATCH. */
        } else {
            scaleX = ((FclObject *)panelWork)->scaleX;
            minimumScale = iGpffff8504;
            if (!(scaleX < minimumScale)) {
                scaleY = ((FclObject *)panelWork)->scale;
                if (!(scaleY < minimumScale)) {
                    sdkSpriteDrawQueued(
                        ((FclObject *)panelWork)->anchorPosition.x, ((FclObject *)panelWork)->anchorPosition.y,
                        ((FclObject *)panelWork)->anchorValue,
                        fclPackRgba(0xFF, ((FclObject *)panelWork)->color.c0,
                                      ((FclObject *)panelWork)->color.c1,
                                      ((FclObject *)panelWork)->color.c2),
                        ((FclObject *)panelWork)->alpha, (u16)((FclObject *)panelWork)->anchorIndex,
                        (void *)*(s32 *)(panelWork + 0xF4), 1, /* measured: access-site fields lose this function's MATCH. */
                        ((FclItemShopPanel *)panelWork)->centerX, ((FclItemShopPanel *)panelWork)->centerY,
                        ((FclObject *)panelWork)->tweenValue,
                        scaleX, scaleY,
                        (void *)((u8 *)D_00793E80 + (((FclObject *)panelWork)->anchorMode * 0x30)));
                }
            }
        }
    }
    return 0;
}

// Item panel task destroy: calls the destroy jump-table entry for its work block.
// FUN_0033D100
void fclItemShopPanelDestroy(u8 *task) {
    jtbl_008873EC[0](((SdkTask *)task)->work);
}

// Allocate a 0x104-byte panel and initialize position, alpha, scale and sprite bounds.
/* Position, color and scale initializers walk interleaved tween triplets in
   the packed FclObject payload rather than one homogeneous member array. */
// FUN_0033D130
/* Counter must be s32 with explicit (s16) casts at each use to reproduce
   retail's $a3 counter coloring and the per-use dsll32/dsra32 normalization.
   measured: without this pragma mwcc rematerializes the 0xFF / 0x3F800000
   constants inside the loop body (nd 50+); with it they hoist to the
   preheader exactly as retail does (nd 0). */
#pragma opt_loop_invariants on
u8 *fclItemShopPanelCreate(void *task, s32 panelIndex, s32 spriteFile) {
    s32 i;
    u8 *createdTask;
    u8 *work;
    f32 *itemData;
    void *r;

    chkmemAllocSiteTag(D_0064A380, 0xACA);
    work = D_008873F4[0](1, 0x104, 0x40000);
    createdTask = kwlnTaskCreateChild((void *)(task), (const void *)(D_0064A3F0), 0xF, 0, 0, fclItemShopPanelUpdate, fclItemShopPanelDestroy, (u8 *)(work));
    work[0] = 0;
    ((FclItemShopPanel *)work)->object.anchorIndex = panelIndex;
    ((FclItemShopPanel *)work)->object.spriteResource = spriteFile;
    itemData = (f32 *)((u8 *)D_0064A090 + ((panelIndex & 0xFFFF) * 8));
    for (i = 0; (s16)i < 3; i = (s16)(i + 1)) {
        *(f32 *)(work + (s16)i * 8 + 0x1C) = itemData[0]; /* interleaved tween triplets, not a homogeneous member array. */
        *(f32 *)(work + (s16)i * 8 + 0x20) = itemData[1]; /* interleaved tween triplets, not a homogeneous member array. */
        work[(s16)i + 0x60] = 0xFF;
        *(s32 *)(work + (s16)i * 4 + 0x8C) = 0x3F800000; /* interleaved tween triplets, not a homogeneous member array. */
        *(s32 *)(work + (s16)i * 4 + 0x98) = 0x3F800000; /* interleaved tween triplets, not a homogeneous member array. */
        *(s32 *)(work + (s16)i * 4 + 0xBC) = 0; /* interleaved tween triplets, not a homogeneous member array. */
        work[(s16)i * 4 + 0x73] = 0xFF;
        work[(s16)i * 4 + 0x72] = 0xFF;
        work[(s16)i * 4 + 0x71] = 0xFF;
    }
    ((FclItemShopPanel *)work)->object.anchorValue = 100.0f;
    ((FclItemShopPanel *)work)->object.anchorMode = 0x55;
    ((FclItemShopPanel *)work)->object.spriteFlags = 0;
    r = sdkSpriteNewNode((void *)*(s32 *)(work + 0xF4), 0, itemData, i); /* measured: access-site fields lose this function's MATCH. */
    ((FclItemShopPanel *)work)->centerX = (s16)(s32)(sdkSpriteScaledWidth(r) / 2.0f);
    ((FclItemShopPanel *)work)->centerY = (s16)(s32)(sdkSpriteScaledHeight(r) / 2.0f);
    sdkSpriteFreeNode(r);
    return createdTask;
}
/* measured: see annotation above (func_0033d130). */
#pragma opt_loop_invariants off

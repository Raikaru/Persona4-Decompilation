/* Original translation unit y_fclItemShopDraw.c (from __FILE__ assert strings). */

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
#include "member_access.h"

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

/* Shop panels append their signed sprite origin to the shared 0x100-byte sprite work, giving a
 * 0x104-byte panel. */
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
s32 datItemPrice(s16);
void *sdkSpriteNewNode(void *, s32, ...);
void yListCreate(s32, s32, s32, s32);
f32 sdkSpriteScaledWidth(void *);
f32 sdkSpriteScaledHeight(void *);
void sdkSpriteFreeNode(void *);
s32 fclBustupObjTestFlagBit(void *, s32);
void fclBustupObjChangeFlagBit(u8 *task, s32 bit, s8 clear);
f32 fclEaseInterpolate(s64, f32, f32, f32, f32);
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
extern void nmMesWindowDestroySlot(s64 slotIndex);
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
extern void nmMesWindowSetSlotParam(s64 slotIndex, s32 recordIndex);
extern void nmMesWindowSetSlotFlag(s64 slotIndex, s32 cursor);
extern void nmMesWindowRequestRefresh(void);

// Drive resource loading, menu/list transitions, purchase confirmation and exit.
// FUN_00332BB0
/* Loops that retail colours apart keep their own counters; the case 5 slot loop keeps its counter
 * and slot index as block locals. measured: opt_loop_invariants hoists the 140/340/20/10 and (s8)1
 * loop constants into the preheaders as retail does. */
#pragma opt_loop_invariants on
s32 fclItemShopUpdate(u8 *shopTask) {
    FclItemShopWork *shopFields = (FclItemShopWork *)((SdkTask *)shopTask)->work;
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
            (&((FclItemShopWork *)work)->panels[0])[panelIndex] = fclItemShopPanelCreate(shopTask, (u16)panelIndex, shopFields->spriteFile);
        }
        for (extraPanel = 0; extraPanel < 0xF; extraPanel++) {
            if ((&((FclItemShopWork *)work)->panels[90])[extraPanel] != 0) {
                (&((FclItemShopWork *)work)->panels[90])[extraPanel] = 0;
            }
        }
        ((FclItemShopWork *)work)->panels[90] = fclItemShopPanelCreate(shopTask, 0x2B, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[91] = fclItemShopPanelCreate(shopTask, 0x28, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[92] = fclItemShopPanelCreate(shopTask, 0x28, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[93] = fclItemShopPanelCreate(shopTask, 0x28, shopFields->spriteFile);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            (&((FclItemShopWork *)work)->panels[94])[panelIndex] = fclItemShopPanelCreate(shopTask, 0x28, shopFields->spriteFile);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[94])[panelIndex], 13, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[94])[panelIndex], 0.0f, 0.0f, 0, 0, 0);
        }
        ((FclItemShopWork *)work)->panels[99] = fclItemShopPanelCreate(shopTask, 0x46, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[98] = fclItemShopPanelCreate(shopTask, 0x46, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[100] = fclItemShopPanelCreate(shopTask, 0x46, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[101] = fclItemShopPanelCreate(shopTask, 0x46, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[102] = fclItemShopPanelCreate(shopTask, 0x40, shopFields->spriteFile);
        ((FclItemShopWork *)work)->panels[103] = fclItemShopPanelCreate(shopTask, 0x41, shopFields->spriteFile);
        if (yListCount() > 5) {
            ((FclItemShopWork *)work)->scrollStep = 108.0f / (f32)(yListCount() - 5);
        }
        ((FclItemShopWork *)work)->discountDay = 0;
        if ((s8)calGetDayEntryForMonthDay(fclCalendarMonth(), (u8)fclCalendarDay()) == 1) {
            shopFields->discountDay = 1;
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
        fclBustupObjStartPosition(shopFields->panels[64], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[64], 17.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[64], 0x63);
        tbl = (F2_0033 *)D_0064A298;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[65], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[65], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[65], 17.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[65], 0x63);
        tbl = (F2_0033 *)D_0064A290;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[102], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[102], fclMakeVec2(-0x125, tbl->y), fclMakeVec2(200.0f + tbl->x, tbl->y), 2,
                      0x14, 0);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[102]))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
        fclBustupObjSetAnchorValue(shopFields->panels[102], 16.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[102], 0x63);
        tbl = (F2_0033 *)D_0064A298;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[103], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[103], fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(200.0f + tbl->x, tbl->y), 2,
                      0x14, 0);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[103]))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
        fclBustupObjSetAnchorValue(shopFields->panels[103], 16.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[103], 0x63);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[0], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[0], fclMakeVec2(0x28A, D_0064A090[1]), fclMakeVec2(D_0064A090[0], D_0064A090[1]),
                      0, 0x1E, 0xA);
        fclBustupObjChangeFlagBit(shopFields->panels[0], 3, 0);
        fclBustupObjStartTween(shopFields->panels[0], 720.0f, 0.0f, 0, 0x1E, 0xA);
        fclBustupObjSetAnchorValue(shopFields->panels[0], 36.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[0], 0x62);
        tbl = (F2_0033 *)D_0064A338;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[85], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[85], 0, 0xFF, 0, 0, 0x2B);
        fclBustupObjStartUniformRevealScale(shopFields->panels[85], 0.1f, 1.0f, 0, 0xF, 0x2B);
        labelFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, 0x55);
        fclBustupObjStartPosition(shopFields->panels[85],
                      fclMakeVec2((sdkSpriteScaledWidth(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (sdkSpriteScaledHeight(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      fclMakeVec2(tbl->x, tbl->y), 0, 0xF, 0x2B);
        sdkSpriteFreeNode(labelFont);
        fclBustupObjSetAnchorValue(shopFields->panels[85], 69.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[85], 0x56);
        ((FclItemShopWork *)work)->bandStartDelay = 0x2D;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[40], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[40], 0, 0xFF, 0, 7, 0x3F);
        fclBustupObjStartUniformRevealScale(shopFields->panels[40], 0.1f, 1.0f, 0, 0xF, 0x3F);
        fclBustupObjSetAnchorValue(shopFields->panels[40], 52.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[40], 0x5B);
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
        fclBustupObjStartPosition(shopFields->panels[41], fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0xF, 0x16);
        fclBustupObjSetAnchorValue(shopFields->panels[41], 47.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[41], 0x61);
        tbl = (F2_0033 *)D_0064A1E0;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[42], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[42], fclMakeVec2(-200.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 9, 0x1C);
        fclBustupObjSetAnchorValue(shopFields->panels[42], 33.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[42], 0x61);
        tbl = (F2_0033 *)D_0064A1E8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[43], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[43], fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(153.0f, tbl->y), 0, 0xF, 0x19);
        fclBustupObjSetAnchorValue(shopFields->panels[43], 48.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[43], 0x61);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[90], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[90], fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(203.0f, tbl->y), 0, 0xF, 0x19);
        fclBustupObjSetAnchorValue(shopFields->panels[90], 48.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[90], 0x61);
        tbl = (F2_0033 *)D_0064A0E8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[11], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[11], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[11], 0, 0xFF, 0, 0xA, 0x28);
        fclBustupObjSetAnchorValue(shopFields->panels[11], 46.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[11], 0x62);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[1], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[1], 0, 0xFF, 0, 5, 0x28);
        fclBustupObjSetAnchorValue(shopFields->panels[1], 30.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[1], 0x63);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            layer0 = (s16)(panelIndex * 3 + 0x2D);
            rowIndex = panelIndex + 3;
            coords = (f32 *)((u8 *)D_0064A090 + rowIndex * 8);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0.7f, 1.0f, 0, 5, layer0);
            fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0, 0xFF, 0, 5, layer0);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[3])[panelIndex], (f32)(panelIndex + 0x1A));
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[3])[panelIndex], 0x63);
            rowFont = sdkSpriteNewNode((void *)shopFields->spriteFile, rowIndex);
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
        ((FclItemShopWork *)work)->bandStartDelay = fclSubClamped(shopFields->bandStartDelay, 1, 0, 0, 1);
        if (shopFields->bandStartDelay == 0) {
            for (introBand = 0; introBand < 0x24; introBand++) {
                MEMBER(u8, work + introBand, FclItemShopWork, bandAlpha[0]) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f);
                if (MEMBER(s8, work + introBand, FclItemShopWork, bandActive[0]) == 1) {
                    ((FclItemShopWork *)work)->bandPosition[introBand] =
                        fclBustupDrawRotatingBand(fclMakeVec2(23.0f, 225.0f), (s16)(introBand * 10), ((FclItemShopWork *)work)->bandAngle, MEMBER(u8, work + introBand, FclItemShopWork, bandAlpha[0]), 1);
                }
            }
            ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 720.0f);
            shopFields->bandElapsed = fclAddClamped(shopFields->bandElapsed, ((FclItemShopWork *)work)->bandStep, 0x2D0, 1, 2);
            ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(shopFields->bandFadeElapsed, 1, 0xF, 1, 1);
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 3], 2) == 0) {
                fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 3], 0xAB);
            }
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[40], 2) == 0 && fclBustupObjTestFlagBit(shopFields->panels[40], 4) == 0) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 0);
            fclBustupObjSetAnchorValue(shopFields->panels[18], 80.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[18], 0x3D);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 0);
            fclBustupObjSetAnchorValue(shopFields->panels[19], 81.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[19], 0x3D);
            tbl = (F2_0033 *)D_0064A2A0;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 0);
            fclBustupObjSetAnchorValue(shopFields->panels[66], 82.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[66], 0x3E);
            fclBustupObjStartPosition(shopFields->panels[66], fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)),
                          fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
            tbl = (F2_0033 *)D_0064A2A8;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 0);
            fclBustupObjSetAnchorValue(shopFields->panels[67], 83.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[67], 0x3E);
            fclBustupObjStartPosition(shopFields->panels[67], fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)),
                          fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0, 1);
                fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[12])[panelIndex], (f32)(panelIndex + 0x4A));
                fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0x3F);
            }
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
            for (introBandDelay = 0; introBandDelay < 0x24; introBandDelay++) {
                if (!(shopFields->bandPosition[introBandDelay] < 140.0f) && ((FclItemShopWork *)work)->bandPosition[introBandDelay] < 340.0f) {
                    ((FclItemShopWork *)work)->bandActive[introBandDelay] = 0;
                } else if (!(shopFields->bandPosition[introBandDelay] < 140.0f)) {
                    ((FclItemShopWork *)work)->bandDelay[introBandDelay] = (shopFields->bandPosition[introBandDelay] - 340.0f) / 10.0f;
                } else {
                    ((FclItemShopWork *)work)->bandDelay[introBandDelay] = (20.0f + shopFields->bandPosition[introBandDelay]) / 10.0f;
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
        fclBustupObjChangeFlagBit(shopFields->panels[102], 1, 1);
        tbl = (F2_0033 *)D_0064A298;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[103]))->anchorPosition = fclMakeVec2(200.0f + tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(shopFields->panels[103], 1, 1);
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[0]))->anchorPosition = fclMakeVec2(D_0064A090[0], D_0064A090[1]);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[0]))->tweenValue = 0.0f;
        fclBustupObjChangeFlagBit(shopFields->panels[0], 1, 1);
        fclBustupObjChangeFlagBit(shopFields->panels[0], 3, 1);
        tbl = (F2_0033 *)D_0064A338;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[85]))->alpha = 0xFF;
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[85]))->scaleX = 1.0f;
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[85]))->scale = 1.0f;
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[85]))->anchorPosition = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(shopFields->panels[85], 2, 1);
        fclBustupObjChangeFlagBit(shopFields->panels[85], 1, 1);
        fclBustupObjChangeFlagBit(shopFields->panels[85], 4, 1);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[40]))->alpha = 0xFF;
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[40]))->scaleX = 1.0f;
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[40]))->scale = 1.0f;
        fclBustupObjChangeFlagBit(shopFields->panels[40], 2, 1);
        fclBustupObjChangeFlagBit(shopFields->panels[40], 4, 1);
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
        fclBustupObjChangeFlagBit(shopFields->panels[41], 1, 1);
        tbl = (F2_0033 *)D_0064A1E0;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[42]))->anchorPosition = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(shopFields->panels[42], 1, 1);
        tbl = (F2_0033 *)D_0064A1E8;
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[43]))->anchorPosition = fclMakeVec2(153.0f, tbl->y);
        fclBustupObjChangeFlagBit(shopFields->panels[43], 1, 1);
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[90]))->anchorPosition = fclMakeVec2(203.0f, tbl->y);
        fclBustupObjChangeFlagBit(shopFields->panels[90], 1, 1);
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[11]))->alpha = 0xFF;
        fclBustupObjChangeFlagBit(shopFields->panels[11], 2, 1);
        ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[1]))->alpha = 0xFF;
        fclBustupObjChangeFlagBit(shopFields->panels[1], 2, 1);
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
        fclBustupObjSetAnchorValue(shopFields->panels[18], 80.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[18], 0x3D);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[19], 81.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[19], 0x3D);
        tbl = (F2_0033 *)D_0064A2A0;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[66], 82.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[66], 0x3E);
        fclBustupObjStartPosition(shopFields->panels[66], fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
        tbl = (F2_0033 *)D_0064A2A8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[67], 83.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[67], 0x3E);
        fclBustupObjStartPosition(shopFields->panels[67], fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
            fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[panelIndex + 12], (f32)(panelIndex + 0x4A));
            fclBustupObjSetAnchorMode(((FclItemShopWork *)work)->panels[panelIndex + 12], 0x3F);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
        for (skipIntroBand = 0; skipIntroBand < 0x24; skipIntroBand++) {
            if (!(shopFields->bandPosition[skipIntroBand] < 140.0f) && ((FclItemShopWork *)work)->bandPosition[skipIntroBand] < 340.0f) {
                ((FclItemShopWork *)work)->bandActive[skipIntroBand] = 0;
            } else if (!(shopFields->bandPosition[skipIntroBand] < 140.0f)) {
                ((FclItemShopWork *)work)->bandDelay[skipIntroBand] = (shopFields->bandPosition[skipIntroBand] - 340.0f) / 10.0f;
            } else {
                ((FclItemShopWork *)work)->bandDelay[skipIntroBand] = (20.0f + shopFields->bandPosition[skipIntroBand]) / 10.0f;
            }
            ((FclItemShopWork *)work)->bandFadeFrames[skipIntroBand] = 0;
            ((FclItemShopWork *)work)->bandFadeElapsed = 0;
        }
        ((FclItemShopWork *)work)->state = 4;
        break;
    case 4:
        ((FclItemShopWork *)work)->moneyX =
            fclEaseInterpolate(0, ((FclItemShopWork *)work)->moneyStartX, ((FclItemShopWork *)work)->moneyEndX, ((FclItemShopWork *)work)->moneyElapsed, 10.0f);
        shopFields->moneyElapsed = fclAddClamped(shopFields->moneyElapsed, 1, 10, 1, 1);
        for (fadeBand = 0; fadeBand < 0x24; fadeBand++) {
            if (shopFields->bandActive[fadeBand] == 1) {
                ((FclItemShopWork *)work)->bandDelay[fadeBand] = fclSubClamped(((FclItemShopWork *)work)->bandDelay[fadeBand], 1, 0, 0, 1);
                if (((FclItemShopWork *)work)->bandDelay[fadeBand] == 0) {
                    shopFields->bandAlpha[fadeBand] = fclEaseInterpolate(0, 255.0f, 0.0f, shopFields->bandFadeFrames[fadeBand], 15.0f);
                    shopFields->bandFadeFrames[fadeBand] = fclAddClamped(shopFields->bandFadeFrames[fadeBand], 1, 0xF, 1, 1);
                }
                ((FclItemShopWork *)work)->bandPosition[fadeBand] = fclBustupDrawRotatingBand(fclMakeVec2(23.0f, 225.0f), (s16)(fadeBand * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, shopFields->bandAlpha[fadeBand], 1);
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 720.0f);
        shopFields->bandElapsed = fclAddClamped(shopFields->bandElapsed, ((FclItemShopWork *)work)->bandStep, 0x2D0, 1, 2);
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
        fclBustupObjSetAnchorValue(shopFields->panels[20], 14.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[20], 0x64);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[85], 0, 1);
        shopFields->bandElapsed = 0;
        ((FclItemShopWork *)work)->state = 5;
        if (((FclItemShopWork *)work)->moonItemsUnlocked == 1) {
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(shopFields->messageSlot, 2);
            ((FclItemShopWork *)work)->state = 6;
        } else if (((FclItemShopWork *)work)->discountDay == 1) {
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(shopFields->messageSlot, 3);
            ((FclItemShopWork *)work)->state = 7;
        } else {
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(shopFields->messageSlot, 4);
            ((FclItemShopWork *)work)->state = 7;
        }
        break;
    case 6:
        if (nmMesWindowSlotStatus(((FclItemShopWork *)work)->messageSlot) != 0) {
            nmMesWindowStepSlotRelease(shopFields->messageSlot);
            break;
        }
        nmMesWindowDestroySlot(shopFields->messageSlot);
        ((FclItemShopWork *)work)->state = 5;
        if (((FclItemShopWork *)work)->discountDay == 1) {
            shopFields->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            nmMesWindowShowSlotRecord(shopFields->messageSlot, 3);
            ((FclItemShopWork *)work)->state = 7;
        }
        break;
    case 7:
        if (nmMesWindowSlotStatus(((FclItemShopWork *)work)->messageSlot) != 0) {
            nmMesWindowStepSlotRelease(shopFields->messageSlot);
            break;
        }
        nmMesWindowDestroySlot(shopFields->messageSlot);
        ((FclItemShopWork *)work)->state = 5;
        break;
    case 5:
        if (D_008C027A[0] & 0x4000) {
            ((FclItemShopWork *)work)->menuSelection = fclAddClamped(shopFields->menuSelection, 1, 2, 0, 2);
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[panelIndex + 12], 0, 1);
            }
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            ((FclItemShopWork *)work)->menuSelection = fclSubClamped(shopFields->menuSelection, 1, 0, 2, 2);
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
                fclBustupObjStartAlpha(shopFields->panels[1], 0xFF, 0, 0, 6, 0);
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
                      fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
        tbl = (F2_0033 *)D_0064A2A8;
        fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[67], fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
        switch (shopFields->menuSelection) {
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
            fclBustupObjTestFlagBit(shopFields->panels[3], 2) != 0 || fclBustupObjTestFlagBit(shopFields->panels[3], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[4], 4) != 0 || fclBustupObjTestFlagBit(shopFields->panels[4], 2) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[4], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[5], 4) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[5], 2) != 0 || fclBustupObjTestFlagBit(shopFields->panels[5], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[6], 4) != 0 || fclBustupObjTestFlagBit(shopFields->panels[6], 2) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[6], 1) != 0) {
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
        fclBustupObjStartPosition(shopFields->panels[0], fclMakeVec2(D_0064A090[0], D_0064A090[1]), fclMakeVec2(428.0f, 241.0f),
                      0, 0xF, 0);
        fclBustupObjStartTween(shopFields->panels[0], -360.0f, 0.0f, 0, 0xF, 0);
        tbl = (F2_0033 *)D_0064A320;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[82], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[82], 0, 0xFF, 0, 0, 0xF);
        fclBustupObjStartUniformRevealScale(shopFields->panels[82], 0.1f, 1.0f, 0, 8, 0xF);
        fclBustupObjSetAnchorValue(shopFields->panels[82], 45.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[82], 0x5B);
        labelFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, 0x52);
        fclBustupObjStartPosition(shopFields->panels[82],
                      fclMakeVec2((sdkSpriteScaledWidth(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (sdkSpriteScaledHeight(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      fclMakeVec2(tbl->x, tbl->y), 0, 8, 0xF);
        sdkSpriteFreeNode(labelFont);
        tbl = (F2_0033 *)D_0064A200;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[46], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[46], fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0x14, 5);
        fclBustupObjSetAnchorValue(shopFields->panels[46], 42.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[46], 0x61);
        tbl = (F2_0033 *)D_0064A1F0;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[44], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[44], fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 8, 5);
        fclBustupObjSetAnchorValue(shopFields->panels[44], 43.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[44], 0x61);
        tbl = (F2_0033 *)D_0064A1F8;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[45], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[45], fclMakeVec2(980.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 8, 5);
        fclBustupObjStartTween(shopFields->panels[45], 0.0f, -90.0f, 0, 0, 0);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[45]))->targetTween = ((FclObject *)fclBustupObjGetWork(shopFields->panels[45]))->startTween =
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[45]))->tweenValue = -90.0f;
        fclBustupObjSetAnchorValue(shopFields->panels[45], 44.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[45], 0x61);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            layer1 = (s16)(panelIndex * 3 + 0xF);
            listIndex = panelIndex + 7;
            coords = (f32 *)((u8 *)D_0064A090 + listIndex * 8);
            fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0, 0);
            fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0.7f, 1.0f, 0, 5, layer1);
            fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0, 0xFF, 0, 5, layer1);
            fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[7])[panelIndex], (f32)(panelIndex + 0x1A));
            fclBustupObjSetAnchorMode((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0x63);
            rowFont = sdkSpriteNewNode((void *)shopFields->spriteFile, listIndex);
            fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[7])[panelIndex],
                          fclMakeVec2((sdkSpriteScaledWidth(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (sdkSpriteScaledHeight(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          fclMakeVec2(coords[0], coords[1]), 0, 5, layer1);
            sdkSpriteFreeNode(rowFont);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[2], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[2], 0, 0xFF, 0, 0x14, 0xA);
        fclBustupObjSetAnchorValue(shopFields->panels[2], 21.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[2], 0x64);
        tbl = (F2_0033 *)D_0064A208;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[47], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[47], fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5);
        fclBustupObjSetAnchorValue(shopFields->panels[47], 68.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[47], 0x5B);
        tbl = (F2_0033 *)D_0064A210;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[48], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[48], fclMakeVec2(1064.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5);
        fclBustupObjSetAnchorValue(shopFields->panels[48], 60.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[48], 0x5B);
        tbl = (F2_0033 *)D_0064A218;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[49], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[49], fclMakeVec2(1064.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5);
        fclBustupObjSetAnchorValue(shopFields->panels[49], 59.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[49], 0x5B);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[80], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[80], 0, 0xFF, 0, 0, 0xA);
        fclBustupObjSetAnchorValue(shopFields->panels[80], 56.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[80], 0x5B);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[98], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[98], 0, 0xFF, 0, 0, 0xA);
        fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[98], 57.0f);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[98]))->anchorIndex =
            (u8)datItemCount((s16)yListValueAt(((FclItemShopWork *)work)->selectedItem)) % 10 + 0x46;
        fclBustupObjSetAnchorMode(shopFields->panels[98], 0x5B);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[98]))->color = fclMakeDrawColor(0x7E, 0, 8, 0xFF);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
        fclBustupObjStartAlpha(shopFields->panels[99], 0, 0xFF, 0, 0, 0xA);
        fclBustupObjStartPosition(shopFields->panels[99], fclMakeVec2(552.0f, 185.0f), fclMakeVec2(552.0f, 185.0f), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[99], 57.0f);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[99]))->anchorIndex =
            (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 + 0x46;
        fclBustupObjSetAnchorMode(shopFields->panels[99], 0x5B);
        ((FclObject *)fclBustupObjGetWork(shopFields->panels[99]))->color = fclMakeDrawColor(0x7E, 0, 8, 0xFF);
        if ((u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 == 0) {
            fclBustupObjChangeFlagBit(shopFields->panels[99], 0, 1);
            fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
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
        fclBustupObjStartPosition(shopFields->panels[51], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[51], 66.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[51], 0x5B);
        tbl = (F2_0033 *)D_0064A230;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[52], 0, 1);
        fclBustupObjStartPosition(shopFields->panels[52], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[52], 67.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[52], 0x5B);
        tbl = (F2_0033 *)D_0064A220;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[50], 0, 1);
        fclBustupObjStartPosition(shopFields->panels[50], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[50], 61.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[50], 0x5B);
        if (((FclItemShopWork *)work)->moonItemsUnlocked == 1) {
            capFont = sdkSpriteNewNode((void *)shopFields->spriteFile, 0x51);
            tbl = (F2_0033 *)D_0064A318;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[81], 0, 0);
            fclBustupObjStartPosition(shopFields->panels[81], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
            fclBustupObjStartTween(shopFields->panels[81], -90.0f, 0.0f, 0, 7, 0xA);
            fclBustupObjSetAnchorValue(shopFields->panels[81], 40.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[81], 0x62);
            ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[81]))->centerX = 0;
            ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[81]))->centerY = sdkSpriteScaledHeight(capFont);
            sdkSpriteFreeNode(capFont);
        }
        if (((FclItemShopWork *)work)->discountDay == 1) {
            tbl = (F2_0033 *)D_0064A340;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[86], 0, 0);
            fclBustupObjStartPosition(shopFields->panels[86], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
            fclBustupObjStartTween(shopFields->panels[86], 150.0f, 0.0f, 0, 0xA, 0x1B);
            ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[86]))->centerX = 0x231 - tbl->x;
            ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[86]))->centerY = 470.0f - tbl->y;
            fclBustupObjSetAnchorValue(shopFields->panels[86], 24.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[86], 0x63);
            tbl = (F2_0033 *)D_0064A348;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[87], 0, 0);
            fclBustupObjStartPosition(shopFields->panels[87], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
            fclBustupObjStartAlpha(shopFields->panels[87], 0xFF, 0x33, 0, 0x14, 0x34);
            fclBustupObjStartUniformRevealScale(shopFields->panels[87], 0.0f, 1.0f, 0, 0, 0x25);
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[87]))->tweenValue = 0.0f;
            fclBustupObjSetAnchorValue(shopFields->panels[87], 23.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[87], 0x63);
            labelFont = sdkSpriteNewNode((void *)shopFields->spriteFile, 0x58);
            tbl = (F2_0033 *)D_0064A350;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[88], 0, 0);
            fclBustupObjStartPosition(shopFields->panels[88],
                          fclMakeVec2(tbl->x + sdkSpriteScaledWidth(labelFont) / 2.0f, tbl->y + sdkSpriteScaledHeight(labelFont) / 2.0f),
                          fclMakeVec2(tbl->x - 4.0f, tbl->y - 3.0f), 0, 5, 0x23);
            fclBustupObjStartUniformRevealScale(shopFields->panels[88], 0.0f, 1.05f, 2, 5, 0x23);
            fclBustupObjStartAlpha(shopFields->panels[88], 0, 0xFF, 0, 0, 0x23);
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[88]))->tweenValue = 0.0f;
            fclBustupObjSetAnchorValue(shopFields->panels[88], 22.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[88], 0x63);
            sdkSpriteFreeNode(labelFont);
            tbl = (F2_0033 *)D_0064A358;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[89], 0, 0);
            fclBustupObjStartPositionMode(shopFields->panels[89], fclMakeVec2(0x113 + tbl->x, tbl->y),
                          fclMakeVec2(tbl->x, tbl->y - 120.0f), 1, 0, 0xE, 0x20);
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[89]))->tweenValue = 0.0f;
            fclBustupObjSetAnchorValue(shopFields->panels[89], 9.0f);
            fclBustupObjSetAnchorMode(shopFields->panels[89], 0x64);
        }
        ((FclItemShopWork *)work)->descriptionShown = 0;
        ((FclItemShopWork *)work)->state = 0xA;
        break;
    case 8:
        break;
    case 10:
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[88], 4) == 0) {
            fclBustupObjStartUniformRevealScale(shopFields->panels[88], 0.0f, 1.0f, 0, 0, 0);
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
        fclBustupObjChangeFlagBit(shopFields->panels[40], 0, 1);
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
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[88]))->anchorPosition = fclMakeVec2(tbl->x, tbl->y);
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[88]))->scaleX = 1.0f;
            ((FclObject *)fclBustupObjGetWork(shopFields->panels[88]))->scale = 1.0f;
        }
        for (panelIndex = 0; panelIndex < 0x24; panelIndex++) {
            shopFields->bandAlpha[panelIndex] = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f);
            if (shopFields->bandActive[panelIndex] == 1) {
                ((FclItemShopWork *)work)->bandPosition[panelIndex] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(panelIndex * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, shopFields->bandAlpha[panelIndex], 0);
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        shopFields->bandElapsed = fclAddClamped(shopFields->bandElapsed, 1, 1000, 1, 2);
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(shopFields->bandFadeElapsed, 1, 0xF, 1, 1);
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[47], 1) == 0) {
            fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                          fclItemShopDiscountedPrice(shopTask, yListValueAt(((FclItemShopWork *)work)->selectedItem)), 0x35, (void *)((FclItemShopWork *)work)->spriteFile, 0xAB);
            fclItemShopDrawList(shopTask);
            tbl = (F2_0033 *)D_0064A218;
            ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[49]))->anchorPosition.y =
                (f32)(shopFields->selectedItem - ((FclItemShopWork *)work)->cursorRow) * ((FclItemShopWork *)work)->scrollStep + tbl->y + 0.0f;
        }
        *(u16 *)&((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[98]))->anchorIndex =
            (u8)datItemCount((s16)yListValueAt(((FclItemShopWork *)work)->selectedItem)) % 10 + 0x46;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[99]))->anchorIndex =
            (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 + 0x46;
        if ((u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 == 0) {
            fclBustupObjChangeFlagBit(shopFields->panels[99], 0, 1);
            fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[82], 1) != 0 || fclBustupObjTestFlagBit(shopFields->panels[82], 4) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[46], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[44], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[45], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[7], 4) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[8], 4) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[9], 4) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[10], 4) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[2], 2) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[47], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[48], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[49], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[80], 2) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[98], 2) != 0 || fclBustupObjTestFlagBit(shopFields->panels[99], 2) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[21], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[22], 2) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[23], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[24], 2) != 0) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && ((FclItemShopWork *)work)->cursorMoved == 0) {
            sdkSndStartStream(0, 0, 0, 0);
            if (shopFields->selectedItem == 0) {
                shopFields->selectedItem = yListLastIndex();
                ((FclItemShopWork *)work)->cursorRow = fclAddClamped(0, shopFields->selectedItem, 4, 0, 1);
            } else {
                shopFields->selectedItem = fclSubClamped(shopFields->selectedItem, 1, 0, (s16)yListCount(), 2);
                ((FclItemShopWork *)work)->cursorRow =
                    yListStepIndex(shopFields->selectedItem, shopFields->cursorRow, (s16)yListCount(), 5, -1);
            }
            shopFields->cursorMoved = 1;
        } else if (D_008C027A[0] & 0x1000) {
            if (shopFields->selectedItem != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            shopFields->selectedItem = fclSubClamped(shopFields->selectedItem, 1, 0, 0, 1);
            ((FclItemShopWork *)work)->cursorRow = yListStepIndex(shopFields->selectedItem, shopFields->cursorRow, (s16)yListCount(), 5, -1);
            ((FclItemShopWork *)work)->cursorMoved = 1;
        } else if ((D_008C0276[0] & 0x4000) && ((FclItemShopWork *)work)->cursorMoved == 0) {
            sdkSndStartStream(0, 0, 0, 0);
            shopFields->selectedItem = fclAddClamped(shopFields->selectedItem, 1, yListLastIndex(), 0, 2);
            if (shopFields->selectedItem == 0) {
                ((FclItemShopWork *)work)->cursorRow = 0;
            } else if (yListLastIndex() >= 5) {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(shopFields->selectedItem, shopFields->cursorRow, (s16)yListLastIndex(), 5, 1);
            } else {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(shopFields->selectedItem, shopFields->cursorRow, (s16)yListLastIndex(),
                                                   (s16)yListCount(), 1);
            }
            shopFields->cursorMoved = 1;
        } else if (D_008C027A[0] & 0x4000) {
            if (shopFields->selectedItem != yListLastIndex()) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            shopFields->selectedItem = fclAddClamped(shopFields->selectedItem, 1, yListLastIndex(), 0, 1);
            if (yListLastIndex() >= 5) {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(shopFields->selectedItem, shopFields->cursorRow, (s16)yListLastIndex(), 5, 1);
            } else {
                ((FclItemShopWork *)work)->cursorRow = yListStepIndex(shopFields->selectedItem, shopFields->cursorRow, (s16)yListLastIndex(),
                                                   (s16)yListCount(), 1);
            }
            ((FclItemShopWork *)work)->cursorMoved = 1;
        } else {
            if ((D_008C027A[0] & 8) || (D_008C027A[0] & 0x2000)) {
                if (shopFields->selectedItem != yListLastIndex()) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll(shopFields->selectedItem, ((FclItemShopWork *)work)->cursorRow, yListCount(), 5, work + 4, work + 6);
            } else if ((D_008C027A[0] & 4) || (D_008C027A[0] & 0x8000)) {
                if (shopFields->selectedItem != 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListRetreatCursorScroll(shopFields->selectedItem, ((FclItemShopWork *)work)->cursorRow, yListCount(), 5, work + 4, work + 6);
            } else if (D_008C024E[0] & 0x40) {
                if (fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem)) <= fclGetMoney() &&
                    (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) < 0x63) {
                    tbl = (F2_0033 *)D_0064A210;
                    fclBustupObjStartPosition(shopFields->panels[48],
                                  fclMakeVec2(((FclObject *)fclBustupObjGetWork(shopFields->panels[48]))->anchorPosition.x, tbl->y),
                                  fclMakeVec2(tbl->x - 0x193, tbl->y), 0, 7, 0);
                    tbl = (F2_0033 *)D_0064A218;
                    fclBustupObjStartPosition(shopFields->panels[49],
                                  fclMakeVec2(((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.x,
                                                ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y),
                                  fclMakeVec2(tbl->x - 0x193, ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y),
                                  0, 7, 0);
                    tbl = (F2_0033 *)D_0064A328;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[83], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[83], fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2(tbl->x, tbl->y - 7.0f), 1, 0xA, 7);
                    fclBustupObjStartAlpha(shopFields->panels[83], 0, 0xFF, 0, 0xA, 7);
                    fclBustupObjSetAnchorValue(shopFields->panels[83], 54.0f);
                    fclBustupObjSetAnchorMode(shopFields->panels[83], 0x5B);
                    ((FclObject *)fclBustupObjGetWork(shopFields->panels[83]))->mode = 1;
                    tbl = (F2_0033 *)D_0064A330;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[84], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[84], fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2(tbl->x, 7.0f + tbl->y), 1, 0xA, 7);
                    fclBustupObjStartAlpha(shopFields->panels[84], 0, 0xFF, 0, 0xA, 7);
                    fclBustupObjSetAnchorValue(shopFields->panels[84], 55.0f);
                    fclBustupObjSetAnchorMode(shopFields->panels[84], 0x5B);
                    ((FclObject *)fclBustupObjGetWork(shopFields->panels[84]))->mode = 1;
                    ((FclItemShopWork *)work)->state = 0xC;
                    shopFields->quantity = 1;
                    sdkSndStartStream(0, 0, 0, 1);
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            } else if (D_008C024E[0] & 0x80) {
                if (((FclItemShopWork *)work)->descriptionShown == 0) {
                    sdkSndStartStream(0, 1, 0, 3);
                }
                if (shopFields->descriptionShown == 1) {
                    sdkSndStartStream(0, 1, 0, 4);
                }
                shopFields->descriptionShown ^= 1;
            } else if (D_008C024E[0] & 0x20) {
                if (((FclItemShopWork *)work)->descriptionShown == 1) {
                    shopFields->descriptionShown = 0;
                    sdkSndStartStream(0, 1, 0, 4);
                } else {
                    sdkSndStartStream(0, 0, 0, 2);
                    tbl = (F2_0033 *)D_0064A320;
                    fclBustupObjChangeFlagBit(shopFields->panels[82], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[82], 0xFF, 0, 0, 5, 0);
                    fclBustupObjStartUniformRevealScale(shopFields->panels[82], 1.0f, 0.6f, 0, 5, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[82], 45.0f);
                    cardFont = sdkSpriteNewNode((void *)((FclItemShopWork *)work)->spriteFile, 0x52);
                    fclBustupObjStartPosition(shopFields->panels[82], fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2((sdkSpriteScaledWidth(cardFont) / 10.0f) * 2.0f + tbl->x + 0.0f,
                                                (sdkSpriteScaledHeight(cardFont) / 10.0f) * 2.0f + tbl->y + 0.0f),
                                  0, 5, 0);
                    sdkSpriteFreeNode(cardFont);
                    tbl = (F2_0033 *)D_0064A200;
                    fclBustupObjChangeFlagBit(shopFields->panels[46], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[46], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0,
                                  0xF, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[46], 42.0f);
                    tbl = (F2_0033 *)D_0064A1F0;
                    fclBustupObjChangeFlagBit(shopFields->panels[44], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[44], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0,
                                  0xC, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[44], 43.0f);
                    tbl = (F2_0033 *)D_0064A1F8;
                    fclBustupObjChangeFlagBit(shopFields->panels[45], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[45], fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2(320.0f + tbl->x, tbl->y), 0, 0xC, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[45], 44.0f);
                    for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                        layer2 = (s16)(panelIndex * 2);
                        cardIndex = panelIndex + 7;
                        coords = (f32 *)((u8 *)D_0064A090 + cardIndex * 8);
                        fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[7])[panelIndex], 1.0f, 0.7f, 0, 4, layer2);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[7])[panelIndex], 0xFF, 0, 0, 4, layer2);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[7])[panelIndex], (f32)(panelIndex + 0x1A));
                        font = sdkSpriteNewNode((void *)shopFields->spriteFile, cardIndex);
                        fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[7])[panelIndex], fclMakeVec2(coords[0], coords[1]),
                                      fclMakeVec2((sdkSpriteScaledWidth(font) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(font) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      0, 4, layer2);
                        sdkSpriteFreeNode(font);
                    }
                    fclBustupObjChangeFlagBit(shopFields->panels[2], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[2], 0xFF, 0, 0, 5, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[2], 21.0f);
                    tbl = (F2_0033 *)D_0064A208;
                    fclBustupObjChangeFlagBit(shopFields->panels[47], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[47], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0,
                                  0xA, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[47], 68.0f);
                    tbl = (F2_0033 *)D_0064A210;
                    fclBustupObjChangeFlagBit(shopFields->panels[48], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[48], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(1064.0f, tbl->y), 0,
                                  0xA, 0);
                    fclBustupObjSetAnchorValue(shopFields->panels[48], 60.0f);
                    tbl = (F2_0033 *)D_0064A218;
                    fclBustupObjChangeFlagBit(shopFields->panels[49], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[49],
                                  fclMakeVec2(tbl->x, ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y),
                                  fclMakeVec2(1064.0f, ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y), 0, 0xA,
                                  0);
                    fclBustupObjSetAnchorValue(shopFields->panels[49], 59.0f);
                    fclBustupObjStartAlpha(shopFields->panels[80], 0xFF, 0, 0, 0, 5);
                    fclBustupObjSetAnchorValue(shopFields->panels[80], 56.0f);
                    fclBustupObjChangeFlagBit(shopFields->panels[98], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0,
                                  0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[98], 0xFF, 0, 0, 0, 5);
                    fclBustupObjSetAnchorValue(shopFields->panels[98], 57.0f);
                    *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[98]))->anchorIndex =
                        (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) % 10 + 0x46;
                    fclBustupObjChangeFlagBit(shopFields->panels[99], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[99], fclMakeVec2(552.0f, 185.0f), fclMakeVec2(552.0f, 185.0f), 0,
                                  0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[99], 0xFF, 0, 0, 0, 5);
                    fclBustupObjSetAnchorValue(shopFields->panels[99], 57.0f);
                    *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[99]))->anchorIndex =
                        (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 + 0x46;
                    if ((u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 == 0) {
                        fclBustupObjChangeFlagBit(shopFields->panels[99], 0, 1);
                        fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f),
                                      fclMakeVec2(0x243, 185.0f), 0, 0, 0);
                    }
                    for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[21])[panelIndex], 0xFF, 0, 0, 5, 0);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[21])[panelIndex], 15.0f);
                    }
                    if (shopFields->descriptionShown == 1) {
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
                        ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[87]))->centerY = 470.0f - tbl->y;
                        fclBustupObjStartTween(shopFields->panels[87], 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A350;
                        ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[88]))->centerX = 0x231 - tbl->x;
                        ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[88]))->centerY = 470.0f - tbl->y;
                        fclBustupObjStartTween(shopFields->panels[88], 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A358;
                        ((FclItemShopPanel *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[89]))->centerX = 0x231 - tbl->x;
                        ((FclItemShopPanel *)fclBustupObjGetWork(shopFields->panels[89]))->centerY = 470.0f - tbl->y;
                        fclBustupObjStartTween(shopFields->panels[89], 0.0f, -30.0f, 0, 2, 0);
                        fclBustupObjStartPositionMode(shopFields->panels[89], ((FclObject *)fclBustupObjGetWork(shopFields->panels[89]))->anchorPosition,
                                      fclMakeVec2(-300.0f + tbl->x, 250.0f + tbl->y), 0, 2, 0x14, 1);
                    }
                    shopFields->bandFadeElapsed = 0;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[0], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[0], fclMakeVec2(428.0f, 241.0f),
                                  fclMakeVec2(D_0064A090[0], D_0064A090[1]), 0, 0xF, 5);
                    fclBustupObjStartTween(shopFields->panels[0], 720.0f, 0.0f, 0, 0xF, 5);
                    tbl = (F2_0033 *)D_0064A1D8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[41], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[41], fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0xF, 0xC);
                    fclBustupObjSetAnchorValue(shopFields->panels[41], 47.0f);
                    tbl = (F2_0033 *)D_0064A1E0;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[42], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[42], fclMakeVec2(-200.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1,
                                  9, 0xC);
                    fclBustupObjSetAnchorValue(shopFields->panels[42], 33.0f);
                    tbl = (F2_0033 *)D_0064A1E8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[43], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[43], fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(153.0f, tbl->y), 0,
                                  0xF, 0x18);
                    fclBustupObjSetAnchorValue(shopFields->panels[43], 48.0f);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[90], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[90], fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(203.0f, tbl->y), 0,
                                  0xF, 0x18);
                    fclBustupObjSetAnchorValue(shopFields->panels[90], 48.0f);
                    tbl = (F2_0033 *)D_0064A0E8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[11], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[11], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[11], 0, 0xFF, 0, 0xF, 0x25);
                    fclBustupObjSetAnchorValue(shopFields->panels[11], 46.0f);
                    tbl = (F2_0033 *)D_0064A290;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[64], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[64], fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0x14, 0xC);
                    fclBustupObjSetAnchorValue(shopFields->panels[64], 17.0f);
                    tbl = (F2_0033 *)D_0064A298;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[65], 0, 0);
                    fclBustupObjStartPosition(shopFields->panels[65], fclMakeVec2(0x305, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0x14, 0xC);
                    fclBustupObjSetAnchorValue(shopFields->panels[65], 17.0f);
                    for (fadeBand = 0; fadeBand < 4; fadeBand++) {
                        layer3 = (s16)(fadeBand * 3 + 0x14);
                        index = fadeBand + 3;
                        coords = (f32 *)((u8 *)D_0064A090 + index * 8);
                        fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0, 0);
                        fclBustupObjStartUniformRevealScale((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0.7f, 1.0f, 0, 4, layer3);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0, 0xFF, 0, 4, layer3);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[3])[fadeBand], 0, 0xFF, 0, 0, layer3);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[3])[fadeBand], (f32)(fadeBand + 0x1A));
                        iconFont = sdkSpriteNewNode((void *)shopFields->spriteFile, index);
                        fclBustupObjStartPosition((&((FclItemShopWork *)work)->panels[3])[fadeBand],
                                      fclMakeVec2((sdkSpriteScaledWidth(iconFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(iconFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      fclMakeVec2(coords[0], coords[1]), 0, 4, layer3);
                        sdkSpriteFreeNode(iconFont);
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[1], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[1], 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[1], 30.0f);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[40], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[40], 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjStartUniformRevealScale(shopFields->panels[40], 0.35f, 1.0f, 0, 0xA, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[40], 52.0f);
                    for (menuRevealPanel = 0; menuRevealPanel < 3; menuRevealPanel++) {
                        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], 0, 0);
                        fclBustupObjStartAlpha(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], 0, 0xFF, 0, 0xA, 0x14);
                        fclBustupObjStartUniformRevealScale(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], 0.35f, 1.0f, 0, 0xA, 0x14);
                        fclBustupObjSetAnchorValue(((FclItemShopWork *)work)->panels[menuRevealPanel + 91], (f32)(menuRevealPanel + 0x31));
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[18], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[18], 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[18], 80.0f);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[19], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[19], 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[19], 81.0f);
                    tbl = (F2_0033 *)D_0064A2A0;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[66], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[66], 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[66], 82.0f);
                    fclBustupObjStartPosition(shopFields->panels[66], fclMakeVec2(tbl->x, tbl->y + (f32)(((FclItemShopWork *)work)->menuSelection * 30)),
                                  fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
                    tbl = (F2_0033 *)D_0064A2A8;
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[67], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[67], 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[67], 83.0f);
                    fclBustupObjStartPosition(shopFields->panels[67], fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)),
                                  fclMakeVec2(tbl->x, tbl->y + (f32)(shopFields->menuSelection * 30)), 0, 0, 0);
                    for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                        fclBustupObjChangeFlagBit((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0, 1);
                        fclBustupObjStartAlpha((&((FclItemShopWork *)work)->panels[12])[panelIndex], 0, 0xFF, 0, 0xA, 0x14);
                        fclBustupObjSetAnchorValue((&((FclItemShopWork *)work)->panels[12])[panelIndex], (f32)(panelIndex + 0x4A));
                    }
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[15], 0, 0);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[13], 0, 0);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[14], 0, 0);
                    fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[20], 0, 0);
                    fclBustupObjStartAlpha(shopFields->panels[20], 0, 0xFF, 0, 0xF, 0x14);
                    fclBustupObjSetAnchorValue(shopFields->panels[20], 14.0f);
                    ((FclItemShopWork *)work)->state = 0xE;
                }
            }
            ((FclItemShopWork *)work)->cursorMoved = 0;
        }
        break;
    case 12:
        for (panelIndex = 0; panelIndex < 0x24; panelIndex++) {
            shopFields->bandAlpha[panelIndex] = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f);
            if (shopFields->bandActive[panelIndex] == 1) {
                ((FclItemShopWork *)work)->bandPosition[panelIndex] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(panelIndex * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, shopFields->bandAlpha[panelIndex], 0);
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        shopFields->bandElapsed = fclAddClamped(shopFields->bandElapsed, 1, 1000, 1, 2);
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(shopFields->bandFadeElapsed, 1, 0xF, 1, 1);
        fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                      ((FclItemShopWork *)work)->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(((FclItemShopWork *)work)->selectedItem)), 0x35,
                      (void *)((FclItemShopWork *)work)->spriteFile, 0xAB);
        fclItemShopDrawList(shopTask);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[98]))->anchorIndex =
            (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) % 10 + 0x46;
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[99]))->anchorIndex =
            (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 + 0x46;
        if ((u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 == 0) {
            fclBustupObjChangeFlagBit(shopFields->panels[99], 0, 1);
            fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[48], 1) != 0) {
            break;
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[100], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[100], fclMakeVec2(0x167, 134.0f), fclMakeVec2(0x167, 134.0f), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[100], 57.0f);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[100]))->anchorIndex = shopFields->quantity % 10 + 0x46;
        fclBustupObjSetAnchorMode(shopFields->panels[100], 0x61);
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[101], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[101], fclMakeVec2(332.0f, 134.0f), fclMakeVec2(332.0f, 134.0f), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[101], 57.0f);
        *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[101]))->anchorIndex = shopFields->quantity / 10 + 0x46;
        fclBustupObjSetAnchorMode(shopFields->panels[101], 0x61);
        if (shopFields->quantity / 10 == 0) {
            fclBustupObjChangeFlagBit(shopFields->panels[101], 0, 1);
            fclBustupObjStartPosition(shopFields->panels[100], fclMakeVec2(346.0f, 134.0f), fclMakeVec2(346.0f, 134.0f), 0, 0, 0);
        }
        fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[36], 0, 0);
        fclBustupObjStartPosition(shopFields->panels[36], fclMakeVec2(45.0f, 133.0f), fclMakeVec2(45.0f, 133.0f), 0, 0, 0);
        fclBustupObjSetAnchorValue(shopFields->panels[36], 53.0f);
        fclBustupObjSetAnchorMode(shopFields->panels[36], 0x61);
        frFontExDrawTextDeferred(82.0f, 132.0f, 58.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      datGetItemNameId((s16)yListValueAt(shopFields->selectedItem)), 0, 0, D_007950B0);
        if (D_008C024E[0] & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            ((FclItemShopWork *)work)->messageSlot = nmMesWindowAcquire((s32)((HCdvdRequest *)(u8 *)((FclItemShopWork *)work)->directory)->data);
            sprintf(buf, "%d", shopFields->quantity);
            nmMesWindowSetSlotString(shopFields->messageSlot, 1, buf);
            sprintf(buf, "%d", shopFields->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem)));
            nmMesWindowSetSlotString(shopFields->messageSlot, 2, buf);
            nmMesWindowShowSlotRecord(shopFields->messageSlot, 1);
            nmMesWindowSetSlotParam(shopFields->messageSlot, 0);
            nmMesWindowSetSlotFlag(shopFields->messageSlot, 0);
            nmMesWindowRequestRefresh();
            ((FclItemShopWork *)work)->state = 0xD;
        } else if (D_008C027A[0] & 0x1000) {
            if (shopFields->quantity != (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            shopFields->quantity = fclAddClamped(shopFields->quantity, 1,
                                              (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem))), 0, 1);
            if (shopFields->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem)) > fclGetMoney()) {
                shopFields->quantity = fclGetMoney() / fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem));
            }
            tbl = (F2_0033 *)D_0064A328;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[83], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x4000) {
            if (shopFields->quantity != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            shopFields->quantity = fclSubClamped(shopFields->quantity, 1, 1, 0x63, 1);
            tbl = (F2_0033 *)D_0064A330;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[84], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x2000) {
            if (shopFields->quantity != (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            shopFields->quantity = fclAddClamped(shopFields->quantity, 0xA,
                                              (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem))), 0, 1);
            if (shopFields->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem)) > fclGetMoney()) {
                shopFields->quantity = fclGetMoney() / fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem));
            }
            tbl = (F2_0033 *)D_0064A328;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[83], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x8000) {
            if (shopFields->quantity != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            shopFields->quantity = fclSubClamped(shopFields->quantity, 0xA, 1, 0x63, 1);
            tbl = (F2_0033 *)D_0064A330;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[84], fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C024E[0] & 0x20) {
            sdkSndStartStream(0, 0, 0, 2);
            tbl = (F2_0033 *)D_0064A210;
            fclBustupObjStartPosition(shopFields->panels[48],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(shopFields->panels[48]))->anchorPosition.x, tbl->y),
                          fclMakeVec2(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[49],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.x,
                                        ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y),
                          fclMakeVec2(tbl->x, ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y), 0, 7, 0);
            ((FclItemShopWork *)work)->state = 0xB;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[83], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[84], 0, 1);
            fclBustupObjChangeFlagBit(shopFields->panels[100], 0, 1);
            fclBustupObjChangeFlagBit(shopFields->panels[101], 0, 1);
            fclBustupObjChangeFlagBit(shopFields->panels[36], 0, 1);
        }
        break;
    case 13:
        for (confirmationBand = 0; confirmationBand < 0x24; confirmationBand++) {
            shopFields->bandAlpha[confirmationBand] = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 15.0f);
            if (shopFields->bandActive[confirmationBand] == 1) {
                ((FclItemShopWork *)work)->bandPosition[confirmationBand] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(confirmationBand * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, shopFields->bandAlpha[confirmationBand], 0);
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        shopFields->bandElapsed = fclAddClamped(shopFields->bandElapsed, 1, 1000, 1, 2);
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(shopFields->bandFadeElapsed, 1, 0xF, 1, 1);
        fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                      ((FclItemShopWork *)work)->quantity * fclItemShopDiscountedPrice(shopTask, yListValueAt(((FclItemShopWork *)work)->selectedItem)), 0x35,
                      (void *)((FclItemShopWork *)work)->spriteFile, 0xAB);
        fclItemShopDrawList(shopTask);
        frFontExDrawTextDeferred(82.0f, 132.0f, 58.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      datGetItemNameId((s16)yListValueAt(shopFields->selectedItem)), 0, 0, D_00795E60);
        if (nmMesWindowSlotStatus(((FclItemShopWork *)work)->messageSlot) != 0) {
            nmMesWindowStepSlotRelease(shopFields->messageSlot);
            break;
        }
        ((FclItemShopWork *)work)->state = 0xC;
        if (!nmMesWindowGetSlotState(shopFields->messageSlot)) {
            datItemSetCount((s16)yListValueAt(shopFields->selectedItem),
                          (u8)(shopFields->quantity + (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem))));
            fclAddMoney(fclGetMoney() -
                          shopFields->quantity * fclItemShopDiscountedPrice(shopTask, (s16)yListValueAt(shopFields->selectedItem)));
            ((FclItemShopWork *)work)->moneyX = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
            *(u16 *)&((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[98]))->anchorIndex =
                (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) % 10 + 0x46;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[99], 0, 0);
            *(u16 *)&((FclObject *)fclBustupObjGetWork(shopFields->panels[99]))->anchorIndex =
                (u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 + 0x46;
            if ((u8)datItemCount((s16)yListValueAt(shopFields->selectedItem)) / 10 == 0) {
                fclBustupObjChangeFlagBit(shopFields->panels[99], 0, 1);
                fclBustupObjStartPosition(shopFields->panels[98], fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0,
                              0);
            }
            tbl = (F2_0033 *)D_0064A210;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[48],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(shopFields->panels[48]))->anchorPosition.x, tbl->y),
                          fclMakeVec2(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            fclBustupObjStartPosition(((FclItemShopWork *)work)->panels[49],
                          fclMakeVec2(((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.x,
                                        ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y),
                          fclMakeVec2(tbl->x, ((FclObject *)fclBustupObjGetWork(shopFields->panels[49]))->anchorPosition.y), 0, 7, 0);
            ((FclItemShopWork *)work)->state = 0xB;
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[83], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[84], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[100], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[101], 0, 1);
            fclBustupObjChangeFlagBit(((FclItemShopWork *)work)->panels[36], 0, 1);
            sdkSndStartStream(0, 0, 0, 6);
        }
        nmMesWindowDestroySlot(shopFields->messageSlot);
        break;
    case 14:
        for (returnBand = 0; returnBand < 0x24; returnBand++) {
            shopFields->bandAlpha[returnBand] = fclEaseInterpolate(0, 255.0f, 0.0f, (f32)((FclItemShopWork *)work)->bandFadeElapsed, 5.0f);
            if (shopFields->bandActive[returnBand] == 1) {
                ((FclItemShopWork *)work)->bandPosition[returnBand] = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(returnBand * 10),
                                                               ((FclItemShopWork *)work)->bandAngle, shopFields->bandAlpha[returnBand], 0);
            }
        }
        ((FclItemShopWork *)work)->bandAngle = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)((FclItemShopWork *)work)->bandElapsed, 1000.0f);
        shopFields->bandElapsed = fclAddClamped(shopFields->bandElapsed, 1, 1000, 1, 2);
        ((FclItemShopWork *)work)->bandFadeElapsed = fclAddClamped(shopFields->bandFadeElapsed, 1, 5, 1, 1);
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[0], 1) == 0 && fclBustupObjTestFlagBit(shopFields->panels[0], 3) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[41], 1) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[42], 1) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[64], 1) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[65], 1) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[3], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[4], 4) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[5], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[6], 4) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[1], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[40], 4) == 0 &&
            fclBustupObjTestFlagBit(shopFields->panels[40], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[91], 2) == 0 &&
            fclBustupObjTestFlagBit(shopFields->panels[91], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[92], 2) == 0 &&
            fclBustupObjTestFlagBit(shopFields->panels[92], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[93], 2) == 0 &&
            fclBustupObjTestFlagBit(shopFields->panels[93], 4) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[18], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[19], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[66], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[67], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[12], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[13], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[14], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[15], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[16], 2) == 0 &&
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[17], 2) == 0 && fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[20], 2) == 0) {
            ((FclItemShopWork *)work)->state = 5;
        } else if (fclBustupObjTestFlagBit(shopFields->panels[0], 1) != 0 && (D_008C024E[0] & 0x20)) {
            sdkSndStartStream(0, 0, 0, 2);
            ((FclItemShopWork *)work)->moneyStartX = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
            ((FclItemShopWork *)work)->moneyStartY = 15.0f;
            ((FclItemShopWork *)work)->moneyEndX = 0x28A;
            ((FclItemShopWork *)work)->moneyEndY = 15.0f;
            ((FclItemShopWork *)work)->moneyElapsed = 0;
            fclBustupObjStartPosition(shopFields->panels[0], ((FclObject *)fclBustupObjGetWork(shopFields->panels[0]))->anchorPosition,
                          fclMakeVec2(0x28A, ((FclObject *)fclBustupObjGetWork(shopFields->panels[0]))->anchorPosition.y), 0, 0xA, 0);
            fclBustupObjStartTween(shopFields->panels[0], ((FclObject *)fclBustupObjGetWork(shopFields->panels[0]))->tweenValue,
                          ((FclObject *)fclBustupObjGetWork(shopFields->panels[0]))->targetTween, 0, 0xA, 0);
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
        shopFields->moneyElapsed = fclAddClamped(shopFields->moneyElapsed, 1, 10, 1, 1);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            ((FclObject *)fclBustupObjGetWork(((FclItemShopWork *)work)->panels[panelIndex + 94]))->tweenValue = 0.01f;
        }
        if (fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[1], 2) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[3], 4) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[3], 2) != 0 || fclBustupObjTestFlagBit(shopFields->panels[3], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[4], 4) != 0 || fclBustupObjTestFlagBit(shopFields->panels[4], 2) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[4], 1) != 0 || fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[5], 4) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[5], 2) != 0 || fclBustupObjTestFlagBit(shopFields->panels[5], 1) != 0 ||
            fclBustupObjTestFlagBit(((FclItemShopWork *)work)->panels[6], 4) != 0 || fclBustupObjTestFlagBit(shopFields->panels[6], 2) != 0 ||
            fclBustupObjTestFlagBit(shopFields->panels[6], 1) != 0) {
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
        fclBustupObjStartPosition(shopFields->panels[0], fclMakeVec2(D_0064A090[0], D_0064A090[1]), fclMakeVec2(0x28A, 241.0f),
                      0, 0xA, 0);
        fclBustupObjStartTween(shopFields->panels[0], -720.0f, 0.0f, 0, 0xA, 0);
        fclBustupObjSetAnchorMode(shopFields->panels[0], 0x62);
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
/* measured: restores the unit's loop-invariant setting. */
#pragma opt_loop_invariants off

// Item shop task destroy: releases the item list, the CDVD and sprite handles, then calls the destroy jump-table entry.
// FUN_0033BDC0
void fclItemShopDestroy(u8 *shopTask) {
    FclItemShopWork *shopFields = (FclItemShopWork *)((SdkTask *)shopTask)->work;
    SdkTask *taskFields = (SdkTask *)shopTask;
    u8 *work = ((SdkTask *)shopTask)->work;

    yListDestroy();
    if ((s32)((FclItemShopWork *)work)->directory != 0) {
        H_Cdvd_Destroy((void *)(s32)((FclItemShopWork *)work)->directory);
    }
    if (((FclItemShopWork *)work)->spriteFile != 0) {
        sdkSpriteRelease((void *)((FclItemShopWork *)work)->spriteFile);
        shopFields->spriteFile = 0;
    }
    jtbl_008873EC[0](taskFields->work);
}

// measured: loop invariants must be on so the loop's constant 1 is hoisted before the entry jump,
// as retail does.
#pragma opt_loop_invariants on
/* Allocate the item shop work, start it as a child task of shopTask, and reset its money, menu and
 * band state. Also unlock the moon-phase items if they are available. */
// FUN_0033BE40
u8 *fclItemShopCreate(u8 *shopTask) {
    FclItemShopWork *shopFields;
    s32 i;
    s32 one;
    u8 *createdTask;
    s8 *allocatedWork;

    chkmemAllocSiteTag(D_0064A380, 0x958);
    allocatedWork = (s8 *)D_008873F4[0](1, 0x42C, 0x40000);
    shopFields = (FclItemShopWork *)allocatedWork;
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
        shopFields->moonItemsUnlocked = 1;
    }
    yListCreate(0x10000, 0, 2, 1);
    return createdTask;
}
/* measured: restores the unit setting after func_0033be40. */
#pragma opt_loop_invariants off

/* Start the shop exit animation, including money-position interpolation. */
// FUN_0033BF90
void fclItemShopStartExit(u8 *shopTask) {
    F2_0033 *positionFields;
    FclItemShopWork *shopFields = (FclItemShopWork *)((SdkTask *)shopTask)->work;
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
        item = (u8 *)&MEMBER(u8 *, work + (s16)i * 4, FclItemShopWork, panels[3]);
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
    fclBustupObjStartAlpha((void *)(s32)shopFields->panels[1], 0xFF, 0, 0, 10, 0);
    fclBustupObjSetAnchorMode((void *)(s32)shopFields->panels[1], 0xAC);
    table = (u8 *)D_0064A1D8;
    positionFields = (F2_0033 *)table;
    pos2 = fclMakeVec2(((F2_0033 *)table)->x, ((F2_0033 *)table)->y);
    pos3 = fclMakeVec2(-180.0f, positionFields->y);
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[41], pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    positionFields = (F2_0033 *)table;
    pos4 = fclMakeVec2(((F2_0033 *)table)->x, ((F2_0033 *)table)->y);
    pos5 = fclMakeVec2(-200.0f, positionFields->y);
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[42], pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    positionFields = (F2_0033 *)table;
    pos6 = fclMakeVec2(153.0f, ((F2_0033 *)table)->y);
    pos7 = fclMakeVec2(-100.0f, positionFields->y);
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[43], pos6, pos7, 0, 0x14, 0);
    pos8 = fclMakeVec2(203.0f, positionFields->y);
    pos9 = fclMakeVec2(-50.0f, positionFields->y);
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[90], pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    positionFields = (F2_0033 *)table;
    pos10 = fclMakeVec2(((F2_0033 *)table)->x, ((F2_0033 *)table)->y);
    pos11 = fclMakeVec2(-200.0f, MEMBER(f32, table, F2_0033, y));
    fclBustupObjStartPosition((void *)(s32)((FclItemShopWork *)work)->panels[11], pos10, pos11, 0, 0xF, 0);
    fclBustupObjStartUniformRevealScale((void *)MEMBER(s32, work, FclItemShopWork, panels[40]), 1.0f, 4.5f, 0, 0xF, 0);
    i = 0;
    while ((s16)i < 3) {
        fclBustupObjStartUniformRevealScale((void *)MEMBER(s32, work + (s16)i * 4, FclItemShopWork, panels[91]), 1.0f, 4.5f, 0, 0xF, 0);
        i = (s16)(i + 1);
    }
    fclBustupObjSetAnchorValue((void *)MEMBER(s32, work, FclItemShopWork, panels[64]), 84.0f);
    fclBustupObjSetAnchorValue((void *)MEMBER(s32, work, FclItemShopWork, panels[65]), 84.0f);
    fclBustupObjSetAnchorValue((void *)MEMBER(s32, work, FclItemShopWork, panels[20]), 83.0f);
    ((FclItemShopWork *)work)->moneyStartX = 580.0f - (f32)fclDecimalDigitCount(fclGetMoney()) * 21.0f;
    ((FclItemShopWork *)work)->moneyStartY = 15.0f;
    ((FclItemShopWork *)work)->moneyEndX = (f32)0x28A;
    ((FclItemShopWork *)work)->moneyEndY = 15.0f;
    ((FclItemShopWork *)work)->moneyElapsed = 0;
    ((FclItemShopWork *)work)->state = 0x11;
}

/* Item list panel: draws either the selected-item header or five scrolling item rows, each with its
 * frame, name and price. */
static inline void fclShopDrawItemFrame(u8 *p, f32 y, u8 red, u8 green, u8 blue)
{
    sdkSpriteDrawQueued(44.0f, y, 62.0f, fclPackRgba(0xFF, red, green, blue), 0xFF, 0x24,
                  (void *)((FclItemShopWork *)p)->spriteFile, 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
}

/* Resolve and draw the selected list item name with the supplied tint. */
static inline void fclShopDrawItemName(s16 item, f32 y, u8 red, u8 green, u8 blue)
{
    frFontExDrawTextDeferred(78.0f, y, 62.0f, fclPackRgba(red, green, blue, 0xFF), 0, 1,
                  datGetItemNameId((s16)yListValueAt(item)), 0, 0, D_00795E60);
}

// Draws the item list rows from index i up to bound: each row shows its item name and price in its highlight colour.
// FUN_0033C490
void fclItemShopDrawList(u8 *shopTask)
{
    FclItemShopWork *shopFields = (FclItemShopWork *)((SdkTask *)shopTask)->work;
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
                      fclItemShopDiscountedPrice(shopTask, yListValueAt(shopFields->selectedItem)), 0x19,
                      (void *)shopFields->spriteFile, 0xAB);
        fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(shopFields->selectedItem)), -1, 1, 0, 4, 0xAA,
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
    ((FclObject *)fclBustupObjGetWork(shopFields->panels[68]))->anchorPosition.x = fy;
    fy = tbl->y + (f32)(((FclItemShopWork *)p)->cursorRow * 28);
    ((FclObject *)fclBustupObjGetWork(shopFields->panels[68]))->anchorPosition.y = fy;
    fclBustupObjSetAnchorValue(shopFields->panels[68], 63.0f);
    fclBustupObjSetAnchorMode(shopFields->panels[68], 0x5B);
    tbl = (F2_0033 *)D_0064A2B8;
    fclBustupObjChangeFlagBit(((FclItemShopWork *)p)->panels[69], 0, 0);
    fy = tbl->x;
    ((FclObject *)fclBustupObjGetWork(shopFields->panels[69]))->anchorPosition.x = fy;
    fy = tbl->y + (f32)(shopFields->cursorRow * 28);
    ((FclObject *)fclBustupObjGetWork(shopFields->panels[69]))->anchorPosition.y = fy;
    fclBustupObjSetAnchorValue(shopFields->panels[69], 63.0f);
    fclBustupObjSetAnchorMode(shopFields->panels[69], 0x5B);
    i = ((FclItemShopWork *)p)->selectedItem - shopFields->cursorRow;
    row = 0;
    bound = i + 5;
    for (; i < bound; i++, row++) {
        if (i >= yListCount()) {
            continue;
        }
        red = green = blue = 0xFF;
        if (i == shopFields->selectedItem) {
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
                      0x19, (void *)shopFields->spriteFile, 0xAB);
    }
}
// Discount days reduce the selected item price by 20 percent, using unsigned division.
// FUN_0033CBC0
u32 fclItemShopDiscountedPrice(void *task, s32 itemId) {
    u8 *work = ((SdkTask *)task)->work;
    u32 discount = (u32)((s32)(((FclItemShopWork *)work)->discountDay * (s32)datItemPrice((s64)(s16)itemId)) * 0x14) / 100U;

    return (u32)datItemPrice((s64)(s16)(s32)itemId) - discount;
}

// Update panel position tweens and queue its sprite with current color and scale. The packed sprite
// data starts at work+4 and is 0xF0 bytes long.
// FUN_0033CC40
s32 fclItemShopPanelUpdate(u8 *task) {
    FclObject *panelFields = (FclObject *)((SdkTask *)task)->work;
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
                    ((FclObject *)panelWork)->positionEnd.y, (f32)panelFields->positionDuration,
                    (f32)(panelFields->positionFrames / 2));
                break;
            case 1:
                ((FclObject *)panelWork)->anchorPosition.x = fclEaseInterpolate(
                    ((FclObject *)panelWork)->positionEase, ((FclObject *)panelWork)->targetPosition.x,
                    ((FclObject *)panelWork)->positionEnd.x, (f32)((FclObject *)panelWork)->positionDuration,
                    (f32)(((FclObject *)panelWork)->positionFrames / 2));
                ((FclObject *)panelWork)->anchorPosition.y = fclEaseInterpolate(
                    0, ((FclObject *)panelWork)->targetPosition.y, ((FclObject *)panelWork)->positionEnd.y,
                    (f32)panelFields->positionDuration, (f32)panelFields->positionFrames);
                break;
            case 2:
                ((FclObject *)panelWork)->anchorPosition.x = fclEaseInterpolate(
                    1, ((FclObject *)panelWork)->targetPosition.x, ((FclObject *)panelWork)->positionEnd.x,
                    (f32)((FclObject *)panelWork)->positionDuration, (f32)((FclObject *)panelWork)->positionFrames);
                ((FclObject *)panelWork)->anchorPosition.y = fclEaseInterpolate(
                    2, ((FclObject *)panelWork)->targetPosition.y, ((FclObject *)panelWork)->positionEnd.y,
                    (f32)panelFields->positionDuration, (f32)panelFields->positionFrames);
                panelFields->anchorPosition.y = (f32)(
                    panelFields->anchorPosition.y -
                    fclEaseInterpolate(1, 0.0f, 100.0f,
                                  (f32)panelFields->positionDuration, (f32)(panelFields->positionFrames / 2)));
                break;
            }
            duration = ((FclObject *)panelWork)->positionFrames;
            elapsed = ((FclObject *)panelWork)->positionDuration;
            if (elapsed < duration) {
                panelFields->positionDuration = fclAddClamped(
                    (s32)elapsed, 1, (s32)duration, 0, 1);
            } else {
                ((FclObject *)panelWork)->anchorPosition.x = ((FclObject *)panelWork)->positionEnd.x;
                ((FclObject *)panelWork)->anchorPosition.y = ((FclObject *)panelWork)->positionEnd.y;
                completedMode = panelFields->mode;
                if (completedMode == 0) {
                    panelFields->anchorPosition.y = ((FclObject *)panelWork)->targetPosition.y;
                } else if (completedMode == 1) {
                    panelFields->anchorPosition.x = ((FclObject *)panelWork)->targetPosition.x;
                }
                fclBustupObjChangeFlagBit((u8 *)task, 0xA, 1);
            }
        } else {
            panelFields->positionDelay = fclSubClamped(delay, 1, 0, 0, 1);
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
                (void *)MEMBER(s32, panelWork, FclObject, spriteResource), 0,
                ((FclItemShopPanel *)panelWork)->centerX, ((FclItemShopPanel *)panelWork)->centerY,
                ((FclObject *)panelWork)->tweenValue,
                ((FclObject *)panelWork)->scaleX, ((FclObject *)panelWork)->scale,
                (void *)((u8 *)D_00793E80 + (panelFields->anchorMode * 0x30)));
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
                        (void *)MEMBER(s32, panelWork, FclObject, spriteResource), 1,
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
/* measured: with loop-invariant hoisting on, the 0xFF and 1.0f constants are loaded before the loop
 * as in retail. The s32 counter with (s16) casts at each use matches retail's sign handling. */
#pragma opt_loop_invariants on
u8 *fclItemShopPanelCreate(void *task, s32 panelIndex, s32 spriteFile) {
    FclObject *panelFields;
    s32 i;
    u8 *createdTask;
    u8 *work;
    f32 *itemData;
    void *r;

    chkmemAllocSiteTag(D_0064A380, 0xACA);
    work = D_008873F4[0](1, 0x104, 0x40000);
    panelFields = (FclObject *)work;
    createdTask = kwlnTaskCreateChild((void *)(task), (const void *)(D_0064A3F0), 0xF, 0, 0, fclItemShopPanelUpdate, fclItemShopPanelDestroy, (u8 *)(work));
    work[0] = 0;
    ((FclItemShopPanel *)work)->object.anchorIndex = panelIndex;
    ((FclItemShopPanel *)work)->object.spriteResource = spriteFile;
    itemData = (f32 *)((u8 *)D_0064A090 + ((panelIndex & 0xFFFF) * 8));
    for (i = 0; (s16)i < 3; i = (s16)(i + 1)) {
        panelFields->positionKeys[(s16)i].x = itemData[0]; /* interleaved tween triplets, not a homogeneous member array. */
        panelFields->positionKeys[(s16)i].y = itemData[1]; /* interleaved tween triplets, not a homogeneous member array. */
        work[(s16)i + 0x60] = 0xFF;
        panelFields->scaleXKeys[(s16)i] = 1.0f; /* interleaved tween triplets, not a homogeneous member array. */
        panelFields->scaleYKeys[(s16)i] = 1.0f; /* interleaved tween triplets, not a homogeneous member array. */
        panelFields->tweenKeys[(s16)i] = 0.0f; /* interleaved tween triplets, not a homogeneous member array. */
        work[(s16)i * 4 + 0x73] = 0xFF;
        work[(s16)i * 4 + 0x72] = 0xFF;
        work[(s16)i * 4 + 0x71] = 0xFF;
    }
    ((FclItemShopPanel *)work)->object.anchorValue = 100.0f;
    ((FclItemShopPanel *)work)->object.anchorMode = 0x55;
    ((FclItemShopPanel *)work)->object.spriteFlags = 0;
    r = sdkSpriteNewNode((void *)(s32)panelFields->spriteResource, 0, itemData, i);
    ((FclItemShopPanel *)work)->centerX = (s16)(s32)(sdkSpriteScaledWidth(r) / 2.0f);
    ((FclItemShopPanel *)work)->centerY = (s16)(s32)(sdkSpriteScaledHeight(r) / 2.0f);
    sdkSpriteFreeNode(r);
    return createdTask;
}
/* measured: restores the unit setting after func_0033d130. */
#pragma opt_loop_invariants off

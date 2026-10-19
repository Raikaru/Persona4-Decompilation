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
extern s32 fclDecimalDigitCount(s32 task);
extern void func_0033d3c0(void *, f32);
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
extern void fclBustupObjStartPositionMode(u8 *task, F2_0033 p1, F2_0033 p2, u32 arg3, s8 arg4, u32 arg5, s16 arg6);
extern void itemShopTalkCreate(u8 *task);
void fclItemShopStartExit(u8 *task);


extern f32 iGpffff8504;
extern u8 D_00793E80[];
extern f32 D_0064A090[];
extern f32 D_0064A380[];
extern u8 D_0064A3D8[];
extern u8 D_0064A3F0[];

s32 fclItemShopUpdate(u8 *task);
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
void fclBustupObjChangeFlagBit(u8 *task, s32 arg1, s8 arg2);
f32 fclEaseInterpolate(s32, f32, f32, f32, f32);
s32 fclPackRgba(u8, u8, u8, u8);
extern s32 frFontExDrawTextDeferred(f32 task, f32 arg1, f32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8, void *arg9);
extern u32 datGetItemNameId(s16 task);
extern s32 datItemCount(s16 task);
extern void fclShopDrawNumber(F2_0033 position, f32 depth, FclDrawColor color, u32 number, s16 glyphBase, void *sprite,
                          s32 style);
extern void fclMesWindowDraw(s32 task, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, f32 arg6, f32 arg7, f32 arg8);
extern s32 yListCount(void);
extern u8 *fclBustupObjGetWork(u8 *task);
extern void func_0033d3d0(u8 *task, s32 arg1);
extern f32 D_0064A2B0[];
extern f32 D_0064A2B8[];
extern u8 D_00795E60[];
extern u32 fclItemShopDiscountedPrice(void *task, s32 arg1);
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
extern s32 func_0046a750(s32);
extern s32 H_Cdvd_IsFileLoaded(void *);
extern u8 *fclItemShopPanelCreate(void *, s32, s32);
extern s32 fadeStatus(void);
extern s32 nmMesWindowSlotStatus(s8 task);
extern void nmMesWindowStepSlotRelease(s32 task);
extern void nmMesWindowDestroySlot(s8 task);
extern s8 nmMesWindowAcquire(s32 task);
extern s32 nmMesWindowShowSlotRecord(s8 task, s32 arg1);
extern u8 fclCalendarMonth(void);
extern s32 fclCalendarDay(void);
extern s32 calGetDayEntryForMonthDay(s32 task, s32 arg1);
extern s32 kwlnTaskGetTaskByName(void *task);
extern u8 D_0064A3C0[];
extern f32 fclBustupDrawRotatingBand(F2_0033 pos, s16 angleStep, f32 angleOffset, u8 alpha, s8 highlight);
extern void fadeBeginTransition(s32 task, s32 arg1);
extern f32 iGpffff8424;
extern f32 iGpffff851c;
extern f32 iGpffff84cc;
extern f32 D_0064A210[];
extern f32 D_0064A218[];
extern void sdkSndStartStream(s32, s32, s32, s32);
extern s32 nmMesWindowGetSlotState(s8 task);
extern void fclAddMoney(s32 task);
void fclItemShopDrawList(u8 *task);
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
extern void nmMesWindowSetSlotString(s8 task, s32 arg1, void *arg2);
extern void nmMesWindowSetSlotParam(s8 task, s32 arg1);
extern void nmMesWindowSetSlotFlag(s8 task, s32 arg1);
extern void nmMesWindowRequestRefresh(void);

// Drive resource loading, menu/list transitions, purchase confirmation and exit.
/* Remaining sprite-work offsets address tween spans not exposed by FclObject;
   queue nodes use +8 callback/+0x10 data, and the directory message record is +0x110. */
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
    /* Raw work offsets follow FclItemShopWork above. A typed rewrite produced
       38232B instead of the matched 37380B; retain this measured byte form. */
    u8 *work = *(u8 **)(shopTask + 0x38);
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
    *(void **)((u8 *)task + 8) = (void *)fclCombineDrawMoney;
    *(void **)((u8 *)task + 0x10) = work;
    PrimAppendNode(D_00795FE0, task);
    switch (*(s8 *)(work + 0)) {
    case 0:
        *(s32 *)(work + 0xC) = sdkSpriteRequestLoad(D_0064A360);
        func_00440b68("%s %d", D_0064A380, 0x17B);
        *(void **)(work + 0x428) = H_Cdvd_AcquireDirectory(D_0064A3A0, 0);
        *(s8 *)(work + 0) = 1;
        /* fallthrough */
    case 1:
        if (func_0046a750(*(s32 *)(work + 0xC)) == 0) {
            break;
        }
        if (H_Cdvd_IsFileLoaded(*(void **)(work + 0x428)) == 0) {
            break;
        }
        *(s8 *)(work + 0) = 2;
        for (panelIndex = 0; panelIndex < 0x5A; panelIndex++) {
            if (*(void **)(work + panelIndex * 4 + 0x10) != 0) {
                *(void **)(work + panelIndex * 4 + 0x10) = 0;
            }
            *(void **)(work + panelIndex * 4 + 0x10) = fclItemShopPanelCreate(shopTask, (u16)panelIndex, *(s32 *)(work + 0xC));
        }
        for (extraPanel = 0; extraPanel < 0xF; extraPanel++) {
            if (*(void **)(work + extraPanel * 4 + 0x178) != 0) {
                *(void **)(work + extraPanel * 4 + 0x178) = 0;
            }
        }
        *(void **)(work + 0x178) = fclItemShopPanelCreate(shopTask, 0x2B, *(s32 *)(work + 0xC));
        *(void **)(work + 0x17C) = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC));
        *(void **)(work + 0x180) = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC));
        *(void **)(work + 0x184) = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC));
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            *(void **)(work + panelIndex * 4 + 0x188) = fclItemShopPanelCreate(shopTask, 0x28, *(s32 *)(work + 0xC));
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x188), 13, 0);
            fclBustupObjStartUniformRevealScale(*(void **)(work + panelIndex * 4 + 0x188), 0.0f, 0.0f, 0, 0, 0);
        }
        *(void **)(work + 0x19C) = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x198) = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1A0) = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1A4) = fclItemShopPanelCreate(shopTask, 0x46, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1A8) = fclItemShopPanelCreate(shopTask, 0x40, *(s32 *)(work + 0xC));
        *(void **)(work + 0x1AC) = fclItemShopPanelCreate(shopTask, 0x41, *(s32 *)(work + 0xC));
        if (yListCount() > 5) {
            *(f32 *)(work + 0x420) = 108.0f / (f32)(yListCount() - 5);
        }
        *(s8 *)(work + 9) = 0;
        if ((s8)calGetDayEntryForMonthDay(fclCalendarMonth(), (u8)fclCalendarDay()) == 1) {
            *(s8 *)(work + 9) = 1;
        }
        break;
    case 2:
        FldRc_ReleaseCachedObject();
        for (i = 0; i < 0x24; i++) {
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        *(s16 *)(work + 0x41E) = 1;
        tbl = (F2_0033 *)D_0064A290;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x110), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x110), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x110), 17.0f);
        func_0033d3d0(*(void **)(work + 0x110), 0x63);
        tbl = (F2_0033 *)D_0064A298;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x114), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x114), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x114), 17.0f);
        func_0033d3d0(*(void **)(work + 0x114), 0x63);
        tbl = (F2_0033 *)D_0064A290;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1A8), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1A8), fclMakeVec2(-0x125, tbl->y), fclMakeVec2(200.0f + tbl->x, tbl->y), 2,
                      0x14, 0);
        *(FclDrawColor *)(fclBustupObjGetWork(*(void **)(work + 0x1A8)) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
        func_0033d3c0(*(void **)(work + 0x1A8), 16.0f);
        func_0033d3d0(*(void **)(work + 0x1A8), 0x63);
        tbl = (F2_0033 *)D_0064A298;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1AC), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1AC), fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(200.0f + tbl->x, tbl->y), 2,
                      0x14, 0);
        *(FclDrawColor *)(fclBustupObjGetWork(*(void **)(work + 0x1AC)) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
        func_0033d3c0(*(void **)(work + 0x1AC), 16.0f);
        func_0033d3d0(*(void **)(work + 0x1AC), 0x63);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(0x28A, D_0064A090[1]), fclMakeVec2(D_0064A090[0], D_0064A090[1]),
                      0, 0x1E, 0xA);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 3, 0);
        fclBustupObjStartTween(*(u8 **)(work + 0x10), 720.0f, 0.0f, 0, 0x1E, 0xA);
        func_0033d3c0(*(void **)(work + 0x10), 36.0f);
        func_0033d3d0(*(void **)(work + 0x10), 0x62);
        tbl = (F2_0033 *)D_0064A338;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x164), 0, 0xFF, 0, 0, 0x2B);
        fclBustupObjStartUniformRevealScale(*(void **)(work + 0x164), 0.1f, 1.0f, 0, 0xF, 0x2B);
        labelFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x55);
        fclBustupObjStartPosition(*(void **)(work + 0x164),
                      fclMakeVec2((sdkSpriteScaledWidth(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (sdkSpriteScaledHeight(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      fclMakeVec2(tbl->x, tbl->y), 0, 0xF, 0x2B);
        sdkSpriteFreeNode(labelFont);
        func_0033d3c0(*(void **)(work + 0x164), 69.0f);
        func_0033d3d0(*(void **)(work + 0x164), 0x56);
        *(s16 *)(work + 0x3D4) = 0x2D;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0xB0), 0, 0xFF, 0, 7, 0x3F);
        fclBustupObjStartUniformRevealScale(*(void **)(work + 0xB0), 0.1f, 1.0f, 0, 0xF, 0x3F);
        func_0033d3c0(*(void **)(work + 0xB0), 52.0f);
        func_0033d3d0(*(void **)(work + 0xB0), 0x5B);
        for (introPanel = 0; introPanel < 3; introPanel++) {
            fclBustupObjChangeFlagBit(*(void **)(work + introPanel * 4 + 0x17C), 0, 0);
            fclBustupObjStartAlpha(*(void **)(work + introPanel * 4 + 0x17C), 0, 0xFF, 0, 7, 0x3F);
            fclBustupObjStartUniformRevealScale(*(void **)(work + introPanel * 4 + 0x17C), 0.1f, 1.0f, 0, 0xF, 0x3F);
            fclBustupObjStartTween(*(u8 **)(work + introPanel * 4 + 0x17C), (f32)((introPanel + 1) * 0x5A), (f32)((introPanel + 1) * 0x5A), 0, 0, 0);
            func_0033d3c0(*(void **)(work + introPanel * 4 + 0x17C), (f32)(introPanel + 0x31));
            func_0033d3d0(*(void **)(work + introPanel * 4 + 0x17C), 0x5B);
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + introPanel * 4 + 0x17C)) + 0x100) = *(s16 *)(fclBustupObjGetWork(*(void **)(work + introPanel * 4 + 0x17C)) + 0x102) = 0;
        }
        *(f32 *)(work + 0x1D0) = 0x28A;
        *(f32 *)(work + 0x1D4) = 15.0f;
        *(f32 *)(work + 0x1D8) = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
        *(f32 *)(work + 0x1DC) = 15.0f;
        *(s16 *)(work + 0x1E8) = 10;
        tbl = (F2_0033 *)D_0064A1D8;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB4), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xB4), fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0xF, 0x16);
        func_0033d3c0(*(void **)(work + 0xB4), 47.0f);
        func_0033d3d0(*(void **)(work + 0xB4), 0x61);
        tbl = (F2_0033 *)D_0064A1E0;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB8), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xB8), fclMakeVec2(-200.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 9, 0x1C);
        func_0033d3c0(*(void **)(work + 0xB8), 33.0f);
        func_0033d3d0(*(void **)(work + 0xB8), 0x61);
        tbl = (F2_0033 *)D_0064A1E8;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xBC), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xBC), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(153.0f, tbl->y), 0, 0xF, 0x19);
        func_0033d3c0(*(void **)(work + 0xBC), 48.0f);
        func_0033d3d0(*(void **)(work + 0xBC), 0x61);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x178), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x178), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(203.0f, tbl->y), 0, 0xF, 0x19);
        func_0033d3c0(*(void **)(work + 0x178), 48.0f);
        func_0033d3d0(*(void **)(work + 0x178), 0x61);
        tbl = (F2_0033 *)D_0064A0E8;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x3C), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x3C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x3C), 0, 0xFF, 0, 0xA, 0x28);
        func_0033d3c0(*(void **)(work + 0x3C), 46.0f);
        func_0033d3d0(*(void **)(work + 0x3C), 0x62);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x14), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x14), 0, 0xFF, 0, 5, 0x28);
        func_0033d3c0(*(void **)(work + 0x14), 30.0f);
        func_0033d3d0(*(void **)(work + 0x14), 0x63);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            layer0 = (s16)(panelIndex * 3 + 0x2D);
            rowIndex = panelIndex + 3;
            coords = (f32 *)((u8 *)D_0064A090 + rowIndex * 8);
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x1C), 0, 0);
            fclBustupObjStartUniformRevealScale(*(void **)(work + panelIndex * 4 + 0x1C), 0.7f, 1.0f, 0, 5, layer0);
            fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x1C), 0, 0xFF, 0, 5, layer0);
            func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x1C), (f32)(panelIndex + 0x1A));
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x1C), 0x63);
            rowFont = sdkSpriteNewNode(*(void **)(work + 0xC), rowIndex);
            fclBustupObjStartPosition(*(void **)(work + panelIndex * 4 + 0x1C),
                          fclMakeVec2((sdkSpriteScaledWidth(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (sdkSpriteScaledHeight(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          fclMakeVec2(coords[0], coords[1]), 0, 5, layer0);
            sdkSpriteFreeNode(rowFont);
        }
        *(s8 *)(work + 0) = 3;
        for (i = 0; i < 0x24; i++) {
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        /* fallthrough */
    case 3:
        *(s16 *)(work + 0x3D4) = fclSubClamped(*(s16 *)(work + 0x3D4), 1, 0, 0, 1);
        if (*(s16 *)(work + 0x3D4) == 0) {
            for (introBand = 0; introBand < 0x24; introBand++) {
                *(u8 *)(work + introBand + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
                if (*(s8 *)(work + introBand + 0x2D8) == 1) {
                    *(f32 *)(work + introBand * 4 + 0x2FC) =
                        fclBustupDrawRotatingBand(fclMakeVec2(23.0f, 225.0f), (s16)(introBand * 10), *(f32 *)(work + 0x2A8), *(u8 *)(work + introBand + 0x2B4), 1);
                }
            }
            *(f32 *)(work + 0x2A8) = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 720.0f);
            *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), *(s16 *)(work + 0x41E), 0x2D0, 1, 2);
            *(s32 *)(work + 0x2B0) = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            if (fclBustupObjTestFlagBit(*(void **)(work + panelIndex * 4 + 0x1C), 2) == 0) {
                func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x1C), 0xAB);
            }
        }
        if (fclBustupObjTestFlagBit(*(void **)(work + 0xB0), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0xB0), 4) == 0) {
            fclBustupObjChangeFlagBit(*(void **)(work + 0x58), 0, 0);
            func_0033d3c0(*(void **)(work + 0x58), 80.0f);
            func_0033d3d0(*(void **)(work + 0x58), 0x3D);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x5C), 0, 0);
            func_0033d3c0(*(void **)(work + 0x5C), 81.0f);
            func_0033d3d0(*(void **)(work + 0x5C), 0x3D);
            tbl = (F2_0033 *)D_0064A2A0;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x118), 0, 0);
            func_0033d3c0(*(void **)(work + 0x118), 82.0f);
            func_0033d3d0(*(void **)(work + 0x118), 0x3E);
            fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                          fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
            tbl = (F2_0033 *)D_0064A2A8;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x11C), 0, 0);
            func_0033d3c0(*(void **)(work + 0x11C), 83.0f);
            func_0033d3d0(*(void **)(work + 0x11C), 0x3E);
            fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                          fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
                func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x40), (f32)(panelIndex + 0x4A));
                func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x40), 0x3F);
            }
            fclBustupObjChangeFlagBit(*(void **)(work + 0x4C), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x44), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x48), 0, 0);
            for (introBandDelay = 0; introBandDelay < 0x24; introBandDelay++) {
                if (!(*(f32 *)(work + introBandDelay * 4 + 0x2FC) < 140.0f) && *(f32 *)(work + introBandDelay * 4 + 0x2FC) < 340.0f) {
                    *(s8 *)(work + introBandDelay + 0x2D8) = 0;
                } else if (!(*(f32 *)(work + introBandDelay * 4 + 0x2FC) < 140.0f)) {
                    *(s16 *)(work + introBandDelay * 2 + 0x38C) = (*(f32 *)(work + introBandDelay * 4 + 0x2FC) - 340.0f) / 10.0f;
                } else {
                    *(s16 *)(work + introBandDelay * 2 + 0x38C) = (20.0f + *(f32 *)(work + introBandDelay * 4 + 0x2FC)) / 10.0f;
                }
                *(s16 *)(work + introBandDelay * 2 + 0x3D6) = 0;
                *(s32 *)(work + 0x2B0) = 0;
            }
            *(s8 *)(work + 0) = 4;
            break;
        }
        if (!(D_008C024E[0] & 0x40) && !(D_008C024E[0] & 0x20) && !(D_008C024E[0] & 0x10) && !(D_008C024E[0] & 0x80)) {
            break;
        }
        tbl = (F2_0033 *)D_0064A290;
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x1A8)) + 0x2C) = fclMakeVec2(200.0f + tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1A8), 1, 1);
        tbl = (F2_0033 *)D_0064A298;
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x1AC)) + 0x2C) = fclMakeVec2(200.0f + tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1AC), 1, 1);
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x10)) + 0x2C) = fclMakeVec2(D_0064A090[0], D_0064A090[1]);
        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x10)) + 0xC4) = 0.0f;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 1, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 3, 1);
        tbl = (F2_0033 *)D_0064A338;
        *(u8 *)(fclBustupObjGetWork(*(void **)(work + 0x164)) + 0x62) = 0xFF;
        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x164)) + 0x94) = 1.0f;
        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x164)) + 0xA0) = 1.0f;
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x164)) + 0x2C) = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 2, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 1, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 4, 1);
        *(u8 *)(fclBustupObjGetWork(*(void **)(work + 0xB0)) + 0x62) = 0xFF;
        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xB0)) + 0x94) = 1.0f;
        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xB0)) + 0xA0) = 1.0f;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 2, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 4, 1);
        for (skipIntroPanel = 0; skipIntroPanel < 3; skipIntroPanel++) {
            *(u8 *)(fclBustupObjGetWork(*(void **)(work + skipIntroPanel * 4 + 0x17C)) + 0x62) = 0xFF;
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + skipIntroPanel * 4 + 0x17C)) + 0x94) = 1.0f;
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + skipIntroPanel * 4 + 0x17C)) + 0xA0) = 1.0f;
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + skipIntroPanel * 4 + 0x17C)) + 0xC4) = (skipIntroPanel + 1) * 0x5A;
            fclBustupObjChangeFlagBit(*(void **)(work + skipIntroPanel * 4 + 0x17C), 2, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + skipIntroPanel * 4 + 0x17C), 3, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + skipIntroPanel * 4 + 0x17C), 4, 1);
        }
        *(f32 *)(work + 0x1E0) = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
        *(f32 *)(work + 0x1E4) = 15.0f;
        *(s16 *)(work + 0x1EA) = 10;
        tbl = (F2_0033 *)D_0064A1D8;
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0xB4)) + 0x2C) = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB4), 1, 1);
        tbl = (F2_0033 *)D_0064A1E0;
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0xB8)) + 0x2C) = fclMakeVec2(tbl->x, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB8), 1, 1);
        tbl = (F2_0033 *)D_0064A1E8;
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0xBC)) + 0x2C) = fclMakeVec2(153.0f, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0xBC), 1, 1);
        *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x178)) + 0x2C) = fclMakeVec2(203.0f, tbl->y);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x178), 1, 1);
        *(u8 *)(fclBustupObjGetWork(*(void **)(work + 0x3C)) + 0x62) = 0xFF;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x3C), 2, 1);
        *(u8 *)(fclBustupObjGetWork(*(void **)(work + 0x14)) + 0x62) = 0xFF;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x14), 2, 1);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            coords = (f32 *)((u8 *)D_0064A090 + (panelIndex + 3) * 8);
            *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + panelIndex * 4 + 0x1C)) + 0x2C) = fclMakeVec2(coords[0], coords[1]);
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + panelIndex * 4 + 0x1C)) + 0x94) = 1.0f;
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + panelIndex * 4 + 0x1C)) + 0xA0) = 1.0f;
            *(u8 *)(fclBustupObjGetWork(*(void **)(work + panelIndex * 4 + 0x1C)) + 0x62) = 0xFF;
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x1C), 2, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x1C), 1, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x1C), 4, 1);
        }
        for (i = 0; i < 0x24; i++) {
            *(u8 *)(work + i + 0x2B4) = 0xFF;
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x58), 0, 0);
        func_0033d3c0(*(void **)(work + 0x58), 80.0f);
        func_0033d3d0(*(void **)(work + 0x58), 0x3D);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x5C), 0, 0);
        func_0033d3c0(*(void **)(work + 0x5C), 81.0f);
        func_0033d3d0(*(void **)(work + 0x5C), 0x3D);
        tbl = (F2_0033 *)D_0064A2A0;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x118), 0, 0);
        func_0033d3c0(*(void **)(work + 0x118), 82.0f);
        func_0033d3d0(*(void **)(work + 0x118), 0x3E);
        fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        tbl = (F2_0033 *)D_0064A2A8;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x11C), 0, 0);
        func_0033d3c0(*(void **)(work + 0x11C), 83.0f);
        func_0033d3d0(*(void **)(work + 0x11C), 0x3E);
        fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
            func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x40), (f32)(panelIndex + 0x4A));
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x40), 0x3F);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x4C), 0, 0);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x44), 0, 0);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x48), 0, 0);
        for (skipIntroBand = 0; skipIntroBand < 0x24; skipIntroBand++) {
            if (!(*(f32 *)(work + skipIntroBand * 4 + 0x2FC) < 140.0f) && *(f32 *)(work + skipIntroBand * 4 + 0x2FC) < 340.0f) {
                *(s8 *)(work + skipIntroBand + 0x2D8) = 0;
            } else if (!(*(f32 *)(work + skipIntroBand * 4 + 0x2FC) < 140.0f)) {
                *(s16 *)(work + skipIntroBand * 2 + 0x38C) = (*(f32 *)(work + skipIntroBand * 4 + 0x2FC) - 340.0f) / 10.0f;
            } else {
                *(s16 *)(work + skipIntroBand * 2 + 0x38C) = (20.0f + *(f32 *)(work + skipIntroBand * 4 + 0x2FC)) / 10.0f;
            }
            *(s16 *)(work + skipIntroBand * 2 + 0x3D6) = 0;
            *(s32 *)(work + 0x2B0) = 0;
        }
        *(s8 *)(work + 0) = 4;
        break;
    case 4:
        *(f32 *)(work + 0x1E0) =
            fclEaseInterpolate(0, *(f32 *)(work + 0x1D0), *(f32 *)(work + 0x1D8), *(s16 *)(work + 0x1EA), 10.0f);
        *(s16 *)(work + 0x1EA) = fclAddClamped(*(s16 *)(work + 0x1EA), 1, 10, 1, 1);
        for (fadeBand = 0; fadeBand < 0x24; fadeBand++) {
            if (*(s8 *)(work + fadeBand + 0x2D8) == 1) {
                *(s16 *)(work + fadeBand * 2 + 0x38C) = fclSubClamped(*(s16 *)(work + fadeBand * 2 + 0x38C), 1, 0, 0, 1);
                if (*(s16 *)(work + fadeBand * 2 + 0x38C) == 0) {
                    *(u8 *)(work + fadeBand + 0x2B4) = fclEaseInterpolate(0, 255.0f, 0.0f, *(s16 *)(work + fadeBand * 2 + 0x3D6), 15.0f);
                    *(s16 *)(work + fadeBand * 2 + 0x3D6) = fclAddClamped(*(s16 *)(work + fadeBand * 2 + 0x3D6), 1, 0xF, 1, 1);
                }
                *(f32 *)(work + fadeBand * 4 + 0x2FC) = fclBustupDrawRotatingBand(fclMakeVec2(23.0f, 225.0f), (s16)(fadeBand * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + fadeBand + 0x2B4), 1);
            }
        }
        *(f32 *)(work + 0x2A8) = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 720.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), *(s16 *)(work + 0x41E), 0x2D0, 1, 2);
        for (activeBand = 0; activeBand < 0x24; activeBand++) {
            if (!(*(f32 *)(work + activeBand * 4 + 0x2FC) < 140.0f) && *(f32 *)(work + activeBand * 4 + 0x2FC) < 340.0f) {
                *(s8 *)(work + activeBand + 0x2D8) = 0;
            } else if (*(s16 *)(work + activeBand * 2 + 0x3D6) == 0xF) {
                *(s8 *)(work + activeBand + 0x2D8) = 0;
            }
            if (*(s8 *)(work + activeBand + 0x2D8) == 1) {
                bandStillActive = 1;
            }
        }
        if (bandStillActive != 0) {
            break;
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x60), 0, 0);
        func_0033d3c0(*(void **)(work + 0x60), 14.0f);
        func_0033d3d0(*(void **)(work + 0x60), 0x64);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x164), 0, 1);
        *(s32 *)(work + 0x2AC) = 0;
        *(s8 *)(work + 0) = 5;
        if (*(s8 *)(work + 0x424) == 1) {
            *(s8 *)(work + 8) = nmMesWindowAcquire(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 2);
            *(s8 *)(work + 0) = 6;
        } else if (*(s8 *)(work + 9) == 1) {
            *(s8 *)(work + 8) = nmMesWindowAcquire(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 3);
            *(s8 *)(work + 0) = 7;
        } else {
            *(s8 *)(work + 8) = nmMesWindowAcquire(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 4);
            *(s8 *)(work + 0) = 7;
        }
        break;
    case 6:
        if (nmMesWindowSlotStatus(*(s8 *)(work + 8)) != 0) {
            nmMesWindowStepSlotRelease(*(s8 *)(work + 8));
            break;
        }
        nmMesWindowDestroySlot(*(s8 *)(work + 8));
        *(s8 *)(work + 0) = 5;
        if (*(s8 *)(work + 9) == 1) {
            *(s8 *)(work + 8) = nmMesWindowAcquire(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 3);
            *(s8 *)(work + 0) = 7;
        }
        break;
    case 7:
        if (nmMesWindowSlotStatus(*(s8 *)(work + 8)) != 0) {
            nmMesWindowStepSlotRelease(*(s8 *)(work + 8));
            break;
        }
        nmMesWindowDestroySlot(*(s8 *)(work + 8));
        *(s8 *)(work + 0) = 5;
        break;
    case 5:
        if (D_008C027A[0] & 0x4000) {
            *(s8 *)(work + 1) = fclAddClamped(*(s8 *)(work + 1), 1, 2, 0, 2);
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
            }
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            *(s8 *)(work + 1) = fclSubClamped(*(s8 *)(work + 1), 1, 0, 2, 2);
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
            }
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C024E[0] & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            switch (*(s8 *)(work + 1)) {
            case 0:
                {
                    s16 n;
                    s32 slot;

                    for (n = 0; n < 4; n++) {
                        slot = n + 3;
                        slotPos = (f32 *)((u8 *)D_0064A090 + slot * 8);
                        fclBustupObjStartUniformRevealScale(*(void **)(work + n * 4 + 0x1C), 1.0f, 0.5f, 0, 3, n);
                        fclBustupObjStartAlpha(*(void **)(work + n * 4 + 0x1C), 0xFF, 0, 0, 3, n);
                        slotFont = sdkSpriteNewNode(*(void **)(work + 0xC), slot);
                        fclBustupObjStartPosition(*(void **)(work + n * 4 + 0x1C), fclMakeVec2(slotPos[0], slotPos[1]),
                                      fclMakeVec2((sdkSpriteScaledWidth(slotFont) / 10.0f) * 1.5f + slotPos[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(slotFont) / 10.0f) * 1.5f + slotPos[1] + 0.0f),
                                      0, 3, n);
                        sdkSpriteFreeNode(slotFont);
                    }
                }
                fclBustupObjChangeFlagBit(*(void **)(work + 0x14), 0, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x14), 0xFF, 0, 0, 6, 0);
                tbl = (F2_0033 *)D_0064A1D8;
                fclBustupObjStartPosition(*(void **)(work + 0xB4), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(-180.0f, tbl->y), 0, 0xD,
                              5);
                tbl = (F2_0033 *)D_0064A1E0;
                fclBustupObjStartPosition(*(void **)(work + 0xB8), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(-200.0f, tbl->y), 0, 0xD,
                              8);
                tbl = (F2_0033 *)D_0064A1E8;
                fclBustupObjStartPosition(*(void **)(work + 0xBC), fclMakeVec2(153.0f, tbl->y), fclMakeVec2(-100.0f, tbl->y), 0, 0xD,
                              5);
                fclBustupObjStartPosition(*(void **)(work + 0x178), fclMakeVec2(203.0f, tbl->y), fclMakeVec2(-50.0f, tbl->y), 0, 0xD,
                              5);
                tbl = (F2_0033 *)D_0064A0E8;
                fclBustupObjStartPosition(*(void **)(work + 0x3C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(-200.0f, tbl->y), 0, 0xD,
                              5);
                fclBustupObjStartUniformRevealScale(*(void **)(work + 0xB0), 1.0f, 4.5f, 0, 0x14, 0);
                for (panelIndex = 0; panelIndex < 3; panelIndex++) {
                    fclBustupObjStartUniformRevealScale(*(void **)(work + panelIndex * 4 + 0x17C), 1.0f, 4.5f, 0, 0x14, 0);
                }
                func_0033d3c0(*(void **)(work + 0x110), 84.0f);
                func_0033d3c0(*(void **)(work + 0x114), 84.0f);
                func_0033d3c0(*(void **)(work + 0x60), 83.0f);
                *(s8 *)(work + 0) = 9;
                break;
            case 1:
                for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                    fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x1C), 0xFF, 0, 0, 5, 0);
                }
                fclBustupObjStartAlpha(*(void **)(work + 0x10), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x110), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x114), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x14), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0xB4), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0xB8), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0xBC), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x178), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x3C), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0xB0), 0xFF, 0, 0, 5, 0);
                for (panelIndex = 0; panelIndex < 3; panelIndex++) {
                    fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x17C), 0xFF, 0, 0, 5, 0);
                }
                fclBustupObjStartAlpha(*(void **)(work + 0x58), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x5C), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x118), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x11C), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x40), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x50), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x48), 0xFF, 0, 0, 5, 0);
                fclBustupObjStartAlpha(*(void **)(work + 0x60), 0xFF, 0, 0, 5, 0);
                itemShopTalkCreate(shopTask);
                *(s8 *)(work + 0) = 0x10;
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
        fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        tbl = (F2_0033 *)D_0064A2A8;
        fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                      fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
        switch (*(s8 *)(work + 1)) {
        case 0:
            fclBustupObjChangeFlagBit(*(void **)(work + 0x4C), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x44), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x48), 0, 0);
            break;
        case 1:
            fclBustupObjChangeFlagBit(*(void **)(work + 0x40), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x50), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x48), 0, 0);
            break;
        case 2:
            fclBustupObjChangeFlagBit(*(void **)(work + 0x40), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x44), 0, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x54), 0, 0);
            break;
        }
        break;
    case 9:
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x14), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 1) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x20), 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x20), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x20), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x24), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x24), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x24), 1) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x28), 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x28), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x28), 1) != 0) {
            break;
        }
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x58), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x5C), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x118), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x11C), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x110), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x114), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x60), 0, 1);
        func_0033d3d0(*(void **)(work + 0xB0), 0x65);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x17C), 0x65);
        }
        for (listRevealPanel = 0; listRevealPanel < 4; listRevealPanel++) {
            fclBustupObjChangeFlagBit(*(void **)(work + listRevealPanel * 4 + 0x188), 13, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + listRevealPanel * 4 + 0x188), 0, 0);
            fclBustupObjStartUniformRevealScale(*(void **)(work + listRevealPanel * 4 + 0x188), 0.1f, 2.7f, 0, 0xC, 0);
            fclBustupObjStartTween(*(u8 **)(work + listRevealPanel * 4 + 0x188), 0.0f, listRevealPanel * 0x5A, 0, 0, 0);
            func_0033d3c0(*(void **)(work + listRevealPanel * 4 + 0x188), 1.0f);
            func_0033d3d0(*(void **)(work + listRevealPanel * 4 + 0x188), 0x64);
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + listRevealPanel * 4 + 0x188)) + 0x100) = *(s16 *)(fclBustupObjGetWork(*(void **)(work + listRevealPanel * 4 + 0x188)) + 0x102) = 0;
            *(u8 *)(fclBustupObjGetWork(*(void **)(work + listRevealPanel * 4 + 0x188)) + 0x62) = 2;
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(D_0064A090[0], D_0064A090[1]), fclMakeVec2(428.0f, 241.0f),
                      0, 0xF, 0);
        fclBustupObjStartTween(*(u8 **)(work + 0x10), -360.0f, 0.0f, 0, 0xF, 0);
        tbl = (F2_0033 *)D_0064A320;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x158), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x158), 0, 0xFF, 0, 0, 0xF);
        fclBustupObjStartUniformRevealScale(*(void **)(work + 0x158), 0.1f, 1.0f, 0, 8, 0xF);
        func_0033d3c0(*(void **)(work + 0x158), 45.0f);
        func_0033d3d0(*(void **)(work + 0x158), 0x5B);
        labelFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x52);
        fclBustupObjStartPosition(*(void **)(work + 0x158),
                      fclMakeVec2((sdkSpriteScaledWidth(labelFont) / 10.0f) * 5.0f + tbl->x + 0.0f,
                                    (sdkSpriteScaledHeight(labelFont) / 10.0f) * 5.0f + tbl->y + 0.0f),
                      fclMakeVec2(tbl->x, tbl->y), 0, 8, 0xF);
        sdkSpriteFreeNode(labelFont);
        tbl = (F2_0033 *)D_0064A200;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xC8), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xC8), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0x14, 5);
        func_0033d3c0(*(void **)(work + 0xC8), 42.0f);
        func_0033d3d0(*(void **)(work + 0xC8), 0x61);
        tbl = (F2_0033 *)D_0064A1F0;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xC0), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xC0), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 8, 5);
        func_0033d3c0(*(void **)(work + 0xC0), 43.0f);
        func_0033d3d0(*(void **)(work + 0xC0), 0x61);
        tbl = (F2_0033 *)D_0064A1F8;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xC4), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xC4), fclMakeVec2(980.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 8, 5);
        fclBustupObjStartTween(*(u8 **)(work + 0xC4), 0.0f, -90.0f, 0, 0, 0);
        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xC4)) + 0xBC) = *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xC4)) + 0xC0) =
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xC4)) + 0xC4) = -90.0f;
        func_0033d3c0(*(void **)(work + 0xC4), 44.0f);
        func_0033d3d0(*(void **)(work + 0xC4), 0x61);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            layer1 = (s16)(panelIndex * 3 + 0xF);
            listIndex = panelIndex + 7;
            coords = (f32 *)((u8 *)D_0064A090 + listIndex * 8);
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x2C), 0, 0);
            fclBustupObjStartUniformRevealScale(*(void **)(work + panelIndex * 4 + 0x2C), 0.7f, 1.0f, 0, 5, layer1);
            fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x2C), 0, 0xFF, 0, 5, layer1);
            func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x2C), (f32)(panelIndex + 0x1A));
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x2C), 0x63);
            rowFont = sdkSpriteNewNode(*(void **)(work + 0xC), listIndex);
            fclBustupObjStartPosition(*(void **)(work + panelIndex * 4 + 0x2C),
                          fclMakeVec2((sdkSpriteScaledWidth(rowFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                        (sdkSpriteScaledHeight(rowFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                          fclMakeVec2(coords[0], coords[1]), 0, 5, layer1);
            sdkSpriteFreeNode(rowFont);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x18), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x18), 0, 0xFF, 0, 0x14, 0xA);
        func_0033d3c0(*(void **)(work + 0x18), 21.0f);
        func_0033d3d0(*(void **)(work + 0x18), 0x64);
        tbl = (F2_0033 *)D_0064A208;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xCC), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xCC), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5);
        func_0033d3c0(*(void **)(work + 0xCC), 68.0f);
        func_0033d3d0(*(void **)(work + 0xCC), 0x5B);
        tbl = (F2_0033 *)D_0064A210;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xD0), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xD0), fclMakeVec2(1064.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5);
        func_0033d3c0(*(void **)(work + 0xD0), 60.0f);
        func_0033d3d0(*(void **)(work + 0xD0), 0x5B);
        tbl = (F2_0033 *)D_0064A218;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xD4), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xD4), fclMakeVec2(1064.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1, 0xA, 5);
        func_0033d3c0(*(void **)(work + 0xD4), 59.0f);
        func_0033d3d0(*(void **)(work + 0xD4), 0x5B);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x150), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x150), 0, 0xFF, 0, 0, 0xA);
        func_0033d3c0(*(void **)(work + 0x150), 56.0f);
        func_0033d3d0(*(void **)(work + 0x150), 0x5B);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x198), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x198), 0, 0xFF, 0, 0, 0xA);
        fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x198), 57.0f);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) =
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x198), 0x5B);
        *(FclDrawColor *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0x79) = fclMakeDrawColor(0x7E, 0, 8, 0xFF);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x19C), 0, 0xFF, 0, 0, 0xA);
        fclBustupObjStartPosition(*(void **)(work + 0x19C), fclMakeVec2(552.0f, 185.0f), fclMakeVec2(552.0f, 185.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x19C), 57.0f);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) =
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x19C), 0x5B);
        *(FclDrawColor *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0x79) = fclMakeDrawColor(0x7E, 0, 8, 0xFF);
        if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) {
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1);
            fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x64), 0, 0);
            fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x64), 0, 0xFF, 0, 0xA, 0x19);
            func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x64), 15.0f);
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x64), 0x64);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x70), 0, 1);
        tbl = (F2_0033 *)D_0064A228;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xDC), 0, 1);
        fclBustupObjStartPosition(*(void **)(work + 0xDC), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xDC), 66.0f);
        func_0033d3d0(*(void **)(work + 0xDC), 0x5B);
        tbl = (F2_0033 *)D_0064A230;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xE0), 0, 1);
        fclBustupObjStartPosition(*(void **)(work + 0xE0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xE0), 67.0f);
        func_0033d3d0(*(void **)(work + 0xE0), 0x5B);
        tbl = (F2_0033 *)D_0064A220;
        fclBustupObjChangeFlagBit(*(void **)(work + 0xD8), 0, 1);
        fclBustupObjStartPosition(*(void **)(work + 0xD8), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xD8), 61.0f);
        func_0033d3d0(*(void **)(work + 0xD8), 0x5B);
        if (*(s8 *)(work + 0x424) == 1) {
            capFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x51);
            tbl = (F2_0033 *)D_0064A318;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x154), 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x154), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
            fclBustupObjStartTween(*(u8 **)(work + 0x154), -90.0f, 0.0f, 0, 7, 0xA);
            func_0033d3c0(*(void **)(work + 0x154), 40.0f);
            func_0033d3d0(*(void **)(work + 0x154), 0x62);
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x154)) + 0x100) = 0;
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x154)) + 0x102) = sdkSpriteScaledHeight(capFont);
            sdkSpriteFreeNode(capFont);
        }
        if (*(s8 *)(work + 9) == 1) {
            tbl = (F2_0033 *)D_0064A340;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x168), 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x168), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
            fclBustupObjStartTween(*(u8 **)(work + 0x168), 150.0f, 0.0f, 0, 0xA, 0x1B);
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x168)) + 0x100) = 0x231 - tbl->x;
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x168)) + 0x102) = 470.0f - tbl->y;
            func_0033d3c0(*(void **)(work + 0x168), 24.0f);
            func_0033d3d0(*(void **)(work + 0x168), 0x63);
            tbl = (F2_0033 *)D_0064A348;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x16C), 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x16C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0, 0, 0);
            fclBustupObjStartAlpha(*(void **)(work + 0x16C), 0xFF, 0x33, 0, 0x14, 0x34);
            fclBustupObjStartUniformRevealScale(*(void **)(work + 0x16C), 0.0f, 1.0f, 0, 0, 0x25);
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x16C)) + 0xC4) = 0.0f;
            func_0033d3c0(*(void **)(work + 0x16C), 23.0f);
            func_0033d3d0(*(void **)(work + 0x16C), 0x63);
            labelFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x58);
            tbl = (F2_0033 *)D_0064A350;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x170), 0, 0);
            fclBustupObjStartPosition(*(void **)(work + 0x170),
                          fclMakeVec2(tbl->x + sdkSpriteScaledWidth(labelFont) / 2.0f, tbl->y + sdkSpriteScaledHeight(labelFont) / 2.0f),
                          fclMakeVec2(tbl->x - 4.0f, tbl->y - 3.0f), 0, 5, 0x23);
            fclBustupObjStartUniformRevealScale(*(void **)(work + 0x170), 0.0f, 1.05f, 2, 5, 0x23);
            fclBustupObjStartAlpha(*(void **)(work + 0x170), 0, 0xFF, 0, 0, 0x23);
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x170)) + 0xC4) = 0.0f;
            func_0033d3c0(*(void **)(work + 0x170), 22.0f);
            func_0033d3d0(*(void **)(work + 0x170), 0x63);
            sdkSpriteFreeNode(labelFont);
            tbl = (F2_0033 *)D_0064A358;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x174), 0, 0);
            fclBustupObjStartPositionMode(*(u8 **)(work + 0x174), fclMakeVec2(0x113 + tbl->x, tbl->y),
                          fclMakeVec2(tbl->x, tbl->y - 120.0f), 1, 0, 0xE, 0x20);
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x174)) + 0xC4) = 0.0f;
            func_0033d3c0(*(void **)(work + 0x174), 9.0f);
            func_0033d3d0(*(void **)(work + 0x174), 0x64);
        }
        *(s8 *)(work + 2) = 0;
        *(s8 *)(work + 0) = 0xA;
        break;
    case 8:
        break;
    case 10:
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x170), 4) == 0) {
            fclBustupObjStartUniformRevealScale(*(void **)(work + 0x170), 0.0f, 1.0f, 0, 0, 0);
        }
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x188), 4) != 0) {
            break;
        }
        func_0033d3d0(*(void **)(work + 0xB0), 0x5B);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x17C), 0x5B);
        }
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            fclBustupObjChangeFlagBit(*(void **)((work + panelIndex * 4) + 0x188), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)((work + panelIndex * 4) + 0x17C), 0, 1);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 0, 1);
        *(s32 *)(work + 0x2B0) = 0;
        for (i = 0; i < 0x24; i++) {
            *(s8 *)(work + i + 0x2D8) = 1;
        }
        *(s8 *)(work + 0) = 0xB;
        break;
    case 11:
        *(s8 *)(work + 3) = 1;
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x170), 4) == 0) {
            tbl = (F2_0033 *)D_0064A350;
            *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x170)) + 0x2C) = fclMakeVec2(tbl->x, tbl->y);
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x170)) + 0x94) = 1.0f;
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x170)) + 0xA0) = 1.0f;
        }
        for (panelIndex = 0; panelIndex < 0x24; panelIndex++) {
            *(u8 *)(work + panelIndex + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + panelIndex + 0x2D8) == 1) {
                *(f32 *)(work + panelIndex * 4 + 0x2FC) = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(panelIndex * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + panelIndex + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        if (fclBustupObjTestFlagBit(*(void **)(work + 0xCC), 1) == 0) {
            fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                          fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))), 0x35, *(void **)(work + 0xC), 0xAB);
            fclItemShopDrawList(shopTask);
            tbl = (F2_0033 *)D_0064A218;
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30) =
                (f32)(*(s16 *)(work + 4) - *(s16 *)(work + 6)) * *(f32 *)(work + 0x420) + tbl->y + 0.0f;
        }
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) =
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 0);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) =
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46;
        if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) {
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1);
            fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        }
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x158), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x158), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0xC8), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0xC0), 1) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0xC4), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x2C), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x30), 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x34), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x38), 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x18), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0xCC), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0xD0), 1) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0xD4), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x150), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x198), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x19C), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x64), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x68), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x6C), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x70), 2) != 0) {
            break;
        }
        if ((D_008C0276[0] & 0x1000) && *(s8 *)(work + 0x425) == 0) {
            sdkSndStartStream(0, 0, 0, 0);
            if (*(s16 *)(work + 4) == 0) {
                *(s16 *)(work + 4) = yListLastIndex();
                *(s16 *)(work + 6) = fclAddClamped(0, *(s16 *)(work + 4), 4, 0, 1);
            } else {
                *(s16 *)(work + 4) = fclSubClamped(*(s16 *)(work + 4), 1, 0, (s16)yListCount(), 2);
                *(s16 *)(work + 6) =
                    yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListCount(), 5, -1);
            }
            *(s8 *)(work + 0x425) = 1;
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s16 *)(work + 4) != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s16 *)(work + 4) = fclSubClamped(*(s16 *)(work + 4), 1, 0, 0, 1);
            *(s16 *)(work + 6) = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListCount(), 5, -1);
            *(s8 *)(work + 0x425) = 1;
        } else if ((D_008C0276[0] & 0x4000) && *(s8 *)(work + 0x425) == 0) {
            sdkSndStartStream(0, 0, 0, 0);
            *(s16 *)(work + 4) = fclAddClamped(*(s16 *)(work + 4), 1, yListLastIndex(), 0, 2);
            if (*(s16 *)(work + 4) == 0) {
                *(s16 *)(work + 6) = 0;
            } else if (yListLastIndex() >= 5) {
                *(s16 *)(work + 6) = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(), 5, 1);
            } else {
                *(s16 *)(work + 6) = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(),
                                                   (s16)yListCount(), 1);
            }
            *(s8 *)(work + 0x425) = 1;
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s16 *)(work + 4) != yListLastIndex()) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s16 *)(work + 4) = fclAddClamped(*(s16 *)(work + 4), 1, yListLastIndex(), 0, 1);
            if (yListLastIndex() >= 5) {
                *(s16 *)(work + 6) = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(), 5, 1);
            } else {
                *(s16 *)(work + 6) = yListStepIndex(*(s16 *)(work + 4), *(s16 *)(work + 6), (s16)yListLastIndex(),
                                                   (s16)yListCount(), 1);
            }
            *(s8 *)(work + 0x425) = 1;
        } else {
            if ((D_008C027A[0] & 8) || (D_008C027A[0] & 0x2000)) {
                if (*(s16 *)(work + 4) != yListLastIndex()) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll(*(s16 *)(work + 4), *(s16 *)(work + 6), yListCount(), 5, work + 4, work + 6);
            } else if ((D_008C027A[0] & 4) || (D_008C027A[0] & 0x8000)) {
                if (*(s16 *)(work + 4) != 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListRetreatCursorScroll(*(s16 *)(work + 4), *(s16 *)(work + 6), yListCount(), 5, work + 4, work + 6);
            } else if (D_008C024E[0] & 0x40) {
                if (fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))) <= fclGetMoney() &&
                    (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) < 0x63) {
                    tbl = (F2_0033 *)D_0064A210;
                    fclBustupObjStartPosition(*(void **)(work + 0xD0),
                                  fclMakeVec2(*(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD0)) + 0x2C), tbl->y),
                                  fclMakeVec2(tbl->x - 0x193, tbl->y), 0, 7, 0);
                    tbl = (F2_0033 *)D_0064A218;
                    fclBustupObjStartPosition(*(void **)(work + 0xD4),
                                  fclMakeVec2(*(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x2C),
                                                *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)),
                                  fclMakeVec2(tbl->x - 0x193, *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)),
                                  0, 7, 0);
                    tbl = (F2_0033 *)D_0064A328;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x15C), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x15C), fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2(tbl->x, tbl->y - 7.0f), 1, 0xA, 7);
                    fclBustupObjStartAlpha(*(void **)(work + 0x15C), 0, 0xFF, 0, 0xA, 7);
                    func_0033d3c0(*(void **)(work + 0x15C), 54.0f);
                    func_0033d3d0(*(void **)(work + 0x15C), 0x5B);
                    *(s8 *)(fclBustupObjGetWork(*(void **)(work + 0x15C)) + 0x3B) = 1;
                    tbl = (F2_0033 *)D_0064A330;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x160), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x160), fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2(tbl->x, 7.0f + tbl->y), 1, 0xA, 7);
                    fclBustupObjStartAlpha(*(void **)(work + 0x160), 0, 0xFF, 0, 0xA, 7);
                    func_0033d3c0(*(void **)(work + 0x160), 55.0f);
                    func_0033d3d0(*(void **)(work + 0x160), 0x5B);
                    *(s8 *)(fclBustupObjGetWork(*(void **)(work + 0x160)) + 0x3B) = 1;
                    *(s8 *)(work + 0) = 0xC;
                    *(s8 *)(work + 3) = 1;
                    sdkSndStartStream(0, 0, 0, 1);
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            } else if (D_008C024E[0] & 0x80) {
                if (*(s8 *)(work + 2) == 0) {
                    sdkSndStartStream(0, 1, 0, 3);
                }
                if (*(s8 *)(work + 2) == 1) {
                    sdkSndStartStream(0, 1, 0, 4);
                }
                *(s8 *)(work + 2) ^= 1;
            } else if (D_008C024E[0] & 0x20) {
                if (*(s8 *)(work + 2) == 1) {
                    *(s8 *)(work + 2) = 0;
                    sdkSndStartStream(0, 1, 0, 4);
                } else {
                    sdkSndStartStream(0, 0, 0, 2);
                    tbl = (F2_0033 *)D_0064A320;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x158), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x158), 0xFF, 0, 0, 5, 0);
                    fclBustupObjStartUniformRevealScale(*(void **)(work + 0x158), 1.0f, 0.6f, 0, 5, 0);
                    func_0033d3c0(*(void **)(work + 0x158), 45.0f);
                    cardFont = sdkSpriteNewNode(*(void **)(work + 0xC), 0x52);
                    fclBustupObjStartPosition(*(void **)(work + 0x158), fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2((sdkSpriteScaledWidth(cardFont) / 10.0f) * 2.0f + tbl->x + 0.0f,
                                                (sdkSpriteScaledHeight(cardFont) / 10.0f) * 2.0f + tbl->y + 0.0f),
                                  0, 5, 0);
                    sdkSpriteFreeNode(cardFont);
                    tbl = (F2_0033 *)D_0064A200;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xC8), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xC8), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0,
                                  0xF, 0);
                    func_0033d3c0(*(void **)(work + 0xC8), 42.0f);
                    tbl = (F2_0033 *)D_0064A1F0;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xC0), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xC0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0,
                                  0xC, 0);
                    func_0033d3c0(*(void **)(work + 0xC0), 43.0f);
                    tbl = (F2_0033 *)D_0064A1F8;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xC4), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xC4), fclMakeVec2(tbl->x, tbl->y),
                                  fclMakeVec2(320.0f + tbl->x, tbl->y), 0, 0xC, 0);
                    func_0033d3c0(*(void **)(work + 0xC4), 44.0f);
                    for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                        layer2 = (s16)(panelIndex * 2);
                        cardIndex = panelIndex + 7;
                        coords = (f32 *)((u8 *)D_0064A090 + cardIndex * 8);
                        fclBustupObjStartUniformRevealScale(*(void **)(work + panelIndex * 4 + 0x2C), 1.0f, 0.7f, 0, 4, layer2);
                        fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x2C), 0xFF, 0, 0, 4, layer2);
                        func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x2C), (f32)(panelIndex + 0x1A));
                        font = sdkSpriteNewNode(*(void **)(work + 0xC), cardIndex);
                        fclBustupObjStartPosition(*(void **)(work + panelIndex * 4 + 0x2C), fclMakeVec2(coords[0], coords[1]),
                                      fclMakeVec2((sdkSpriteScaledWidth(font) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(font) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      0, 4, layer2);
                        sdkSpriteFreeNode(font);
                    }
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x18), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x18), 0xFF, 0, 0, 5, 0);
                    func_0033d3c0(*(void **)(work + 0x18), 21.0f);
                    tbl = (F2_0033 *)D_0064A208;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xCC), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xCC), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(660.0f, tbl->y), 0,
                                  0xA, 0);
                    func_0033d3c0(*(void **)(work + 0xCC), 68.0f);
                    tbl = (F2_0033 *)D_0064A210;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xD0), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xD0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(1064.0f, tbl->y), 0,
                                  0xA, 0);
                    func_0033d3c0(*(void **)(work + 0xD0), 60.0f);
                    tbl = (F2_0033 *)D_0064A218;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xD4), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xD4),
                                  fclMakeVec2(tbl->x, *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)),
                                  fclMakeVec2(1064.0f, *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)), 0, 0xA,
                                  0);
                    func_0033d3c0(*(void **)(work + 0xD4), 59.0f);
                    fclBustupObjStartAlpha(*(void **)(work + 0x150), 0xFF, 0, 0, 0, 5);
                    func_0033d3c0(*(void **)(work + 0x150), 56.0f);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x198), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0,
                                  0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x198), 0xFF, 0, 0, 0, 5);
                    func_0033d3c0(*(void **)(work + 0x198), 57.0f);
                    *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) =
                        (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x19C), fclMakeVec2(552.0f, 185.0f), fclMakeVec2(552.0f, 185.0f), 0,
                                  0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x19C), 0xFF, 0, 0, 0, 5);
                    func_0033d3c0(*(void **)(work + 0x19C), 57.0f);
                    *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) =
                        (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46;
                    if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) {
                        fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1);
                        fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f),
                                      fclMakeVec2(0x243, 185.0f), 0, 0, 0);
                    }
                    for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                        fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x64), 0xFF, 0, 0, 5, 0);
                        func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x64), 15.0f);
                    }
                    if (*(s8 *)(work + 2) == 1) {
                        tbl = (F2_0033 *)D_0064A228;
                        fclBustupObjStartPosition(*(void **)(work + 0xDC), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(0x2A3, tbl->y),
                                      0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A230;
                        fclBustupObjStartPosition(*(void **)(work + 0xE0), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(0x413, tbl->y),
                                      0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A220;
                        fclBustupObjStartPosition(*(void **)(work + 0xD8), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(0x2AD, tbl->y),
                                      0, 0xA, 0);
                    }
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x120), 0, 1);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x124), 0, 1);
                    if (*(s8 *)(work + 0x424) == 1) {
                        fclBustupObjStartTween(*(u8 **)(work + 0x154), 0.0f, 180.0f, 0, 7, 0);
                    }
                    if (*(s8 *)(work + 9) == 1) {
                        fclBustupObjStartTween(*(u8 **)(work + 0x168), 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A348;
                        *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x16C)) + 0x100) = 0x231 - tbl->x;
                        *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x16C)) + 0x102) = 470.0f - tbl->y;
                        fclBustupObjStartTween(*(u8 **)(work + 0x16C), 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A350;
                        *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x170)) + 0x100) = 0x231 - tbl->x;
                        *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x170)) + 0x102) = 470.0f - tbl->y;
                        fclBustupObjStartTween(*(u8 **)(work + 0x170), 0.0f, -150.0f, 0, 0xA, 0);
                        tbl = (F2_0033 *)D_0064A358;
                        *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x174)) + 0x100) = 0x231 - tbl->x;
                        *(s16 *)(fclBustupObjGetWork(*(void **)(work + 0x174)) + 0x102) = 470.0f - tbl->y;
                        fclBustupObjStartTween(*(u8 **)(work + 0x174), 0.0f, -30.0f, 0, 2, 0);
                        fclBustupObjStartPositionMode(*(u8 **)(work + 0x174), *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x174)) + 0x2C),
                                      fclMakeVec2(-300.0f + tbl->x, 250.0f + tbl->y), 0, 2, 0x14, 1);
                    }
                    *(s32 *)(work + 0x2B0) = 0;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(428.0f, 241.0f),
                                  fclMakeVec2(D_0064A090[0], D_0064A090[1]), 0, 0xF, 5);
                    fclBustupObjStartTween(*(u8 **)(work + 0x10), 720.0f, 0.0f, 0, 0xF, 5);
                    tbl = (F2_0033 *)D_0064A1D8;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xB4), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xB4), fclMakeVec2(-180.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0xF, 0xC);
                    func_0033d3c0(*(void **)(work + 0xB4), 47.0f);
                    tbl = (F2_0033 *)D_0064A1E0;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xB8), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xB8), fclMakeVec2(-200.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 1,
                                  9, 0xC);
                    func_0033d3c0(*(void **)(work + 0xB8), 33.0f);
                    tbl = (F2_0033 *)D_0064A1E8;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xBC), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0xBC), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(153.0f, tbl->y), 0,
                                  0xF, 0x18);
                    func_0033d3c0(*(void **)(work + 0xBC), 48.0f);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x178), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x178), fclMakeVec2(-50.0f, tbl->y), fclMakeVec2(203.0f, tbl->y), 0,
                                  0xF, 0x18);
                    func_0033d3c0(*(void **)(work + 0x178), 48.0f);
                    tbl = (F2_0033 *)D_0064A0E8;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x3C), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x3C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x3C), 0, 0xFF, 0, 0xF, 0x25);
                    func_0033d3c0(*(void **)(work + 0x3C), 46.0f);
                    tbl = (F2_0033 *)D_0064A290;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x110), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x110), fclMakeVec2(660.0f, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0x14, 0xC);
                    func_0033d3c0(*(void **)(work + 0x110), 17.0f);
                    tbl = (F2_0033 *)D_0064A298;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x114), 0, 0);
                    fclBustupObjStartPosition(*(void **)(work + 0x114), fclMakeVec2(0x305, tbl->y), fclMakeVec2(tbl->x, tbl->y), 0,
                                  0x14, 0xC);
                    func_0033d3c0(*(void **)(work + 0x114), 17.0f);
                    for (fadeBand = 0; fadeBand < 4; fadeBand++) {
                        layer3 = (s16)(fadeBand * 3 + 0x14);
                        index = fadeBand + 3;
                        coords = (f32 *)((u8 *)D_0064A090 + index * 8);
                        fclBustupObjChangeFlagBit(*(void **)(work + fadeBand * 4 + 0x1C), 0, 0);
                        fclBustupObjStartUniformRevealScale(*(void **)(work + fadeBand * 4 + 0x1C), 0.7f, 1.0f, 0, 4, layer3);
                        fclBustupObjStartAlpha(*(void **)(work + fadeBand * 4 + 0x1C), 0, 0xFF, 0, 4, layer3);
                        fclBustupObjStartAlpha(*(void **)(work + fadeBand * 4 + 0x1C), 0, 0xFF, 0, 0, layer3);
                        func_0033d3c0(*(void **)(work + fadeBand * 4 + 0x1C), (f32)(fadeBand + 0x1A));
                        iconFont = sdkSpriteNewNode(*(void **)(work + 0xC), index);
                        fclBustupObjStartPosition(*(void **)(work + fadeBand * 4 + 0x1C),
                                      fclMakeVec2((sdkSpriteScaledWidth(iconFont) / 10.0f) * 1.5f + coords[0] + 0.0f,
                                                    (sdkSpriteScaledHeight(iconFont) / 10.0f) * 1.5f + coords[1] + 0.0f),
                                      fclMakeVec2(coords[0], coords[1]), 0, 4, layer3);
                        sdkSpriteFreeNode(iconFont);
                    }
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x14), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x14), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x14), 30.0f);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0xB0), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0xB0), 0, 0xFF, 0, 0xA, 0x14);
                    fclBustupObjStartUniformRevealScale(*(void **)(work + 0xB0), 0.35f, 1.0f, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0xB0), 52.0f);
                    for (menuRevealPanel = 0; menuRevealPanel < 3; menuRevealPanel++) {
                        fclBustupObjChangeFlagBit(*(void **)(work + menuRevealPanel * 4 + 0x17C), 0, 0);
                        fclBustupObjStartAlpha(*(void **)(work + menuRevealPanel * 4 + 0x17C), 0, 0xFF, 0, 0xA, 0x14);
                        fclBustupObjStartUniformRevealScale(*(void **)(work + menuRevealPanel * 4 + 0x17C), 0.35f, 1.0f, 0, 0xA, 0x14);
                        func_0033d3c0(*(void **)(work + menuRevealPanel * 4 + 0x17C), (f32)(menuRevealPanel + 0x31));
                    }
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x58), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x58), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x58), 80.0f);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x5C), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x5C), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x5C), 81.0f);
                    tbl = (F2_0033 *)D_0064A2A0;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x118), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x118), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x118), 82.0f);
                    fclBustupObjStartPosition(*(void **)(work + 0x118), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                                  fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
                    tbl = (F2_0033 *)D_0064A2A8;
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x11C), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x11C), 0, 0xFF, 0, 0xA, 0x14);
                    func_0033d3c0(*(void **)(work + 0x11C), 83.0f);
                    fclBustupObjStartPosition(*(void **)(work + 0x11C), fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)),
                                  fclMakeVec2(tbl->x, tbl->y + (f32)(*(s8 *)(work + 1) * 30)), 0, 0, 0);
                    for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                        fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
                        fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x40), 0, 0xFF, 0, 0xA, 0x14);
                        func_0033d3c0(*(void **)(work + panelIndex * 4 + 0x40), (f32)(panelIndex + 0x4A));
                    }
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x4C), 0, 0);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x44), 0, 0);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x48), 0, 0);
                    fclBustupObjChangeFlagBit(*(void **)(work + 0x60), 0, 0);
                    fclBustupObjStartAlpha(*(void **)(work + 0x60), 0, 0xFF, 0, 0xF, 0x14);
                    func_0033d3c0(*(void **)(work + 0x60), 14.0f);
                    *(s8 *)(work + 0) = 0xE;
                }
            }
            *(s8 *)(work + 0x425) = 0;
        }
        break;
    case 12:
        for (panelIndex = 0; panelIndex < 0x24; panelIndex++) {
            *(u8 *)(work + panelIndex + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + panelIndex + 0x2D8) == 1) {
                *(f32 *)(work + panelIndex * 4 + 0x2FC) = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(panelIndex * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + panelIndex + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                      *(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))), 0x35,
                      *(void **)(work + 0xC), 0xAB);
        fclItemShopDrawList(shopTask);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) =
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46;
        fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 0);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) =
            (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46;
        if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) {
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1);
            fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0, 0);
        }
        if (fclBustupObjTestFlagBit(*(void **)(work + 0xD0), 1) != 0) {
            break;
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1A0), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1A0), fclMakeVec2(0x167, 134.0f), fclMakeVec2(0x167, 134.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x1A0), 57.0f);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x1A0)) + 0xF8) = *(s8 *)(work + 3) % 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x1A0), 0x61);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x1A4), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x1A4), fclMakeVec2(332.0f, 134.0f), fclMakeVec2(332.0f, 134.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0x1A4), 57.0f);
        *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x1A4)) + 0xF8) = *(s8 *)(work + 3) / 10 + 0x46;
        func_0033d3d0(*(void **)(work + 0x1A4), 0x61);
        if (*(s8 *)(work + 3) / 10 == 0) {
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A4), 0, 1);
            fclBustupObjStartPosition(*(void **)(work + 0x1A0), fclMakeVec2(346.0f, 134.0f), fclMakeVec2(346.0f, 134.0f), 0, 0, 0);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0xA0), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0xA0), fclMakeVec2(45.0f, 133.0f), fclMakeVec2(45.0f, 133.0f), 0, 0, 0);
        func_0033d3c0(*(void **)(work + 0xA0), 53.0f);
        func_0033d3d0(*(void **)(work + 0xA0), 0x61);
        frFontExDrawTextDeferred(82.0f, 132.0f, 58.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      datGetItemNameId((s16)yListValueAt(*(s16 *)(work + 4))), 0, 0, D_007950B0);
        if (D_008C024E[0] & 0x40) {
            sdkSndStartStream(0, 0, 0, 1);
            *(s8 *)(work + 8) = nmMesWindowAcquire(*(s32 *)(*(u8 **)(work + 0x428) + 0x110));
            sprintf(buf, "%d", *(s8 *)(work + 3));
            nmMesWindowSetSlotString(*(s8 *)(work + 8), 1, buf);
            sprintf(buf, "%d", *(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))));
            nmMesWindowSetSlotString(*(s8 *)(work + 8), 2, buf);
            nmMesWindowShowSlotRecord(*(s8 *)(work + 8), 1);
            nmMesWindowSetSlotParam(*(s8 *)(work + 8), 0);
            nmMesWindowSetSlotFlag(*(s8 *)(work + 8), 0);
            nmMesWindowRequestRefresh();
            *(s8 *)(work + 0) = 0xD;
        } else if (D_008C027A[0] & 0x1000) {
            if (*(s8 *)(work + 3) != (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclAddClamped(*(s8 *)(work + 3), 1,
                                              (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4)))), 0, 1);
            if (*(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))) > fclGetMoney()) {
                *(s8 *)(work + 3) = fclGetMoney() / fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4)));
            }
            tbl = (F2_0033 *)D_0064A328;
            fclBustupObjStartPosition(*(void **)(work + 0x15C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x4000) {
            if (*(s8 *)(work + 3) != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclSubClamped(*(s8 *)(work + 3), 1, 1, 0x63, 1);
            tbl = (F2_0033 *)D_0064A330;
            fclBustupObjStartPosition(*(void **)(work + 0x160), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x2000) {
            if (*(s8 *)(work + 3) != (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))))) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclAddClamped(*(s8 *)(work + 3), 0xA,
                                              (s16)(0x63 - (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4)))), 0, 1);
            if (*(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))) > fclGetMoney()) {
                *(s8 *)(work + 3) = fclGetMoney() / fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4)));
            }
            tbl = (F2_0033 *)D_0064A328;
            fclBustupObjStartPosition(*(void **)(work + 0x15C), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, tbl->y - 7.0f), 1,
                          0xA, 0);
        } else if (D_008C027A[0] & 0x8000) {
            if (*(s8 *)(work + 3) != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            *(s8 *)(work + 3) = fclSubClamped(*(s8 *)(work + 3), 0xA, 1, 0x63, 1);
            tbl = (F2_0033 *)D_0064A330;
            fclBustupObjStartPosition(*(void **)(work + 0x160), fclMakeVec2(tbl->x, tbl->y), fclMakeVec2(tbl->x, 7.0f + tbl->y), 1,
                          0xA, 0);
        } else if (D_008C024E[0] & 0x20) {
            sdkSndStartStream(0, 0, 0, 2);
            tbl = (F2_0033 *)D_0064A210;
            fclBustupObjStartPosition(*(void **)(work + 0xD0),
                          fclMakeVec2(*(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD0)) + 0x2C), tbl->y),
                          fclMakeVec2(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            fclBustupObjStartPosition(*(void **)(work + 0xD4),
                          fclMakeVec2(*(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x2C),
                                        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)),
                          fclMakeVec2(tbl->x, *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)), 0, 7, 0);
            *(s8 *)(work + 0) = 0xB;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x15C), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x160), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A0), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A4), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0xA0), 0, 1);
        }
        break;
    case 13:
        for (confirmationBand = 0; confirmationBand < 0x24; confirmationBand++) {
            *(u8 *)(work + confirmationBand + 0x2B4) = fclEaseInterpolate(0, 0.0f, 255.0f, (f32)*(s32 *)(work + 0x2B0), 15.0f);
            if (*(s8 *)(work + confirmationBand + 0x2D8) == 1) {
                *(f32 *)(work + confirmationBand * 4 + 0x2FC) = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(confirmationBand * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + confirmationBand + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 0xF, 1, 1);
        fclShopDrawNumber(fclMakeVec2(0x253, 78.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF),
                      *(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(work + 4))), 0x35,
                      *(void **)(work + 0xC), 0xAB);
        fclItemShopDrawList(shopTask);
        frFontExDrawTextDeferred(82.0f, 132.0f, 58.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0, 1,
                      datGetItemNameId((s16)yListValueAt(*(s16 *)(work + 4))), 0, 0, D_00795E60);
        if (nmMesWindowSlotStatus(*(s8 *)(work + 8)) != 0) {
            nmMesWindowStepSlotRelease(*(s8 *)(work + 8));
            break;
        }
        *(s8 *)(work + 0) = 0xC;
        if (!nmMesWindowGetSlotState(*(s8 *)(work + 8))) {
            datItemSetCount((s16)yListValueAt(*(s16 *)(work + 4)),
                          (u8)(*(s8 *)(work + 3) + (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4)))));
            fclAddMoney(fclGetMoney() -
                          *(s8 *)(work + 3) * fclItemShopDiscountedPrice(shopTask, (s16)yListValueAt(*(s16 *)(work + 4))));
            *(f32 *)(work + 0x1E0) = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
            *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x198)) + 0xF8) =
                (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) % 10 + 0x46;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 0);
            *(u16 *)(fclBustupObjGetWork(*(void **)(work + 0x19C)) + 0xF8) =
                (u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 + 0x46;
            if ((u8)datItemCount((s16)yListValueAt(*(s16 *)(work + 4))) / 10 == 0) {
                fclBustupObjChangeFlagBit(*(void **)(work + 0x19C), 0, 1);
                fclBustupObjStartPosition(*(void **)(work + 0x198), fclMakeVec2(0x243, 185.0f), fclMakeVec2(0x243, 185.0f), 0, 0,
                              0);
            }
            tbl = (F2_0033 *)D_0064A210;
            fclBustupObjStartPosition(*(void **)(work + 0xD0),
                          fclMakeVec2(*(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD0)) + 0x2C), tbl->y),
                          fclMakeVec2(tbl->x, tbl->y), 0, 7, 0);
            tbl = (F2_0033 *)D_0064A218;
            fclBustupObjStartPosition(*(void **)(work + 0xD4),
                          fclMakeVec2(*(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x2C),
                                        *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)),
                          fclMakeVec2(tbl->x, *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0xD4)) + 0x30)), 0, 7, 0);
            *(s8 *)(work + 0) = 0xB;
            fclBustupObjChangeFlagBit(*(void **)(work + 0x15C), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x160), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A0), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0x1A4), 0, 1);
            fclBustupObjChangeFlagBit(*(void **)(work + 0xA0), 0, 1);
            sdkSndStartStream(0, 0, 0, 6);
        }
        nmMesWindowDestroySlot(*(s8 *)(work + 8));
        break;
    case 14:
        for (returnBand = 0; returnBand < 0x24; returnBand++) {
            *(u8 *)(work + returnBand + 0x2B4) = fclEaseInterpolate(0, 255.0f, 0.0f, (f32)*(s32 *)(work + 0x2B0), 5.0f);
            if (*(s8 *)(work + returnBand + 0x2D8) == 1) {
                *(f32 *)(work + returnBand * 4 + 0x2FC) = fclBustupDrawRotatingBand(fclMakeVec2(400.0f, 220.0f), (s16)(returnBand * 10),
                                                               *(f32 *)(work + 0x2A8), *(u8 *)(work + returnBand + 0x2B4), 0);
            }
        }
        *(f32 *)(work + 0x2A8) = fclEaseInterpolate(0, 0.0f, 360.0f, (f32)*(s32 *)(work + 0x2AC), 1000.0f);
        *(s32 *)(work + 0x2AC) = fclAddClamped(*(s32 *)(work + 0x2AC), 1, 1000, 1, 2);
        *(s32 *)(work + 0x2B0) = fclAddClamped(*(s32 *)(work + 0x2B0), 1, 5, 1, 1);
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x10), 1) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x10), 3) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0xB4), 1) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0xB8), 1) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x110), 1) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x114), 1) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 4) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x20), 4) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x24), 4) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x28), 4) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x14), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0xB0), 4) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0xB0), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x17C), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x17C), 4) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x180), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x180), 4) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x184), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x184), 4) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x58), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x5C), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x118), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x11C), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x40), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x44), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x48), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x4C), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x50), 2) == 0 &&
            fclBustupObjTestFlagBit(*(void **)(work + 0x54), 2) == 0 && fclBustupObjTestFlagBit(*(void **)(work + 0x60), 2) == 0) {
            *(s8 *)(work + 0) = 5;
        } else if (fclBustupObjTestFlagBit(*(void **)(work + 0x10), 1) != 0 && (D_008C024E[0] & 0x20)) {
            sdkSndStartStream(0, 0, 0, 2);
            *(f32 *)(work + 0x1D0) = 580.0f - 21.0f * (f32)fclDecimalDigitCount(fclGetMoney()) + 0.0f;
            *(f32 *)(work + 0x1D4) = 15.0f;
            *(f32 *)(work + 0x1D8) = 0x28A;
            *(f32 *)(work + 0x1DC) = 15.0f;
            *(s16 *)(work + 0x1EA) = 0;
            fclBustupObjStartPosition(*(void **)(work + 0x10), *(F2_0033 *)(fclBustupObjGetWork(*(void **)(work + 0x10)) + 0x2C),
                          fclMakeVec2(0x28A, *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x10)) + 0x30)), 0, 0xA, 0);
            fclBustupObjStartTween(*(u8 **)(work + 0x10), *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x10)) + 0xC4),
                          *(f32 *)(fclBustupObjGetWork(*(void **)(work + 0x10)) + 0xBC), 0, 0xA, 0);
            fclBustupStartSlide(*(void **)(work + 0xB4));
            fclBustupStartSlide(*(void **)(work + 0xB8));
            fclBustupStartSlide(*(void **)(work + 0xBC));
            fclBustupStartSlide(*(void **)(work + 0x178));
            fclBustupStartSlide(*(void **)(work + 0x3C));
            fclBustupStartSlide(*(void **)(work + 0x110));
            fclBustupStartSlide(*(void **)(work + 0x114));
            for (panelIndex = 0; panelIndex < 4; panelIndex++) {
                fclBustupStartSlide(*(void **)(work + panelIndex * 4 + 0x1C));
            }
            fclBustupStartSlide(*(void **)(work + 0x14));
            fclBustupStartSlide(*(void **)(work + 0xB0));
            for (panelIndex = 0; panelIndex < 3; panelIndex++) {
                fclBustupStartSlide(*(void **)(work + panelIndex * 4 + 0x17C));
            }
            fclBustupStartSlide(*(void **)(work + 0x58));
            fclBustupStartSlide(*(void **)(work + 0x5C));
            fclBustupStartSlide(*(void **)(work + 0x118));
            fclBustupStartSlide(*(void **)(work + 0x11C));
            for (panelIndex = 0; panelIndex < 6; panelIndex++) {
                fclBustupStartSlide(*(void **)(work + panelIndex * 4 + 0x40));
            }
            fclBustupStartSlide(*(void **)(work + 0x60));
            fadeBeginTransition(1, 0xA);
            *(s8 *)(work + 0) = 0xF;
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
            fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x1C), 0, 0xFF, 0, 5, 0);
        }
        fclBustupObjStartAlpha(*(void **)(work + 0x10), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x110), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x114), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x14), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0xB4), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0xB8), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0xBC), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x178), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x3C), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0xB0), 0, 0xFF, 0, 5, 0);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            fclBustupObjStartAlpha(*(void **)(work + panelIndex * 4 + 0x17C), 0, 0xFF, 0, 5, 0);
        }
        fclBustupObjStartAlpha(*(void **)(work + 0x58), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x5C), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x118), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x11C), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x40), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x50), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x48), 0, 0xFF, 0, 5, 0);
        fclBustupObjStartAlpha(*(void **)(work + 0x60), 0, 0xFF, 0, 5, 0);
        *(s8 *)(work + 0) = 5;
        break;
    case 17:
        *(f32 *)(work + 0x1E0) =
            fclEaseInterpolate(0, *(f32 *)(work + 0x1D0), *(f32 *)(work + 0x1D8), *(s16 *)(work + 0x1EA), 10.0f);
        *(s16 *)(work + 0x1EA) = fclAddClamped(*(s16 *)(work + 0x1EA), 1, 10, 1, 1);
        for (panelIndex = 0; panelIndex < 4; panelIndex++) {
            *(f32 *)(fclBustupObjGetWork(*(void **)(work + panelIndex * 4 + 0x188)) + 0xC4) = 0.01f;
        }
        if (fclBustupObjTestFlagBit(*(void **)(work + 0x14), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x1C), 1) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x20), 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x20), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x20), 1) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x24), 4) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x24), 2) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x24), 1) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x28), 4) != 0 || fclBustupObjTestFlagBit(*(void **)(work + 0x28), 2) != 0 ||
            fclBustupObjTestFlagBit(*(void **)(work + 0x28), 1) != 0) {
            break;
        }
        for (panelIndex = 0; panelIndex < 6; panelIndex++) {
            fclBustupObjChangeFlagBit(*(void **)(work + panelIndex * 4 + 0x40), 0, 1);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x58), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x5C), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x118), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(work + 0x11C), 0, 1);
        func_0033d3d0(*(void **)(work + 0xB0), 0x65);
        for (panelIndex = 0; panelIndex < 3; panelIndex++) {
            func_0033d3d0(*(void **)(work + panelIndex * 4 + 0x17C), 0x65);
        }
        func_0033d3d0(*(void **)(work + 0x110), 0x65);
        func_0033d3d0(*(void **)(work + 0x114), 0x65);
        func_0033d3d0(*(void **)(work + 0x60), 0x65);
        for (exitPanel = 0; exitPanel < 4; exitPanel++) {
            fclBustupObjChangeFlagBit(*(void **)(work + exitPanel * 4 + 0x188), 13, 0);
            fclBustupObjChangeFlagBit(*(void **)(work + exitPanel * 4 + 0x188), 0, 0);
            fclBustupObjStartUniformRevealScale(*(void **)(work + exitPanel * 4 + 0x188), 0.1f, 2.7f, 0, 0xA, 0);
            fclBustupObjStartTween(*(u8 **)(work + exitPanel * 4 + 0x188), 0.0f, exitPanel * 0x5A, 0, 0, 0);
            func_0033d3c0(*(void **)(work + exitPanel * 4 + 0x188), 1.0f);
            *(s16 *)(fclBustupObjGetWork(*(void **)(work + exitPanel * 4 + 0x188)) + 0x100) = *(s16 *)(fclBustupObjGetWork(*(void **)(work + exitPanel * 4 + 0x188)) + 0x102) = 0;
            *(u8 *)(fclBustupObjGetWork(*(void **)(work + exitPanel * 4 + 0x188)) + 0x62) = 2;
            func_0033d3d0(*(void **)(work + exitPanel * 4 + 0x188), 0x64);
        }
        fclBustupObjChangeFlagBit(*(void **)(work + 0x10), 0, 0);
        fclBustupObjStartPosition(*(void **)(work + 0x10), fclMakeVec2(D_0064A090[0], D_0064A090[1]), fclMakeVec2(0x28A, 241.0f),
                      0, 0xA, 0);
        fclBustupObjStartTween(*(u8 **)(work + 0x10), -720.0f, 0.0f, 0, 0xA, 0);
        func_0033d3d0(*(void **)(work + 0x10), 0x62);
        fadeBeginTransition(1, 0x1E);
        *(s8 *)(work + 0) = 0x12;
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
    /* Raw work offsets follow FclItemShopWork above. A typed rewrite produced
       132B for a 128B retail window; retain this measured byte form. */
    u8 *work = *(u8 **)(shopTask + 0x38);

    yListDestroy();
    if (*(s32 *)(work + 0x428) != 0) {
        H_Cdvd_Destroy((void *)*(s32 *)(work + 0x428));
    }
    if (*(s32 *)(work + 0xC) != 0) {
        sdkSpriteRelease((void *)*(s32 *)(work + 0xC));
        *(s32 *)(work + 0xC) = 0;
    }
    jtbl_008873EC[0](*(void **)((u8 *)shopTask + 0x38));
}

// Creates the item shop task under task: allocates the 0x42C-byte work, sets the initial layout values and item flags, then registers the update and destroy callbacks.
/* measured: object_size 324/window 336, normalized_diff 0 (retail tail is
   zero padding). MWCCPS2 needs opt_loop_invariants on to hoist the loop's
   `1` constant before the entry jump, matching retail's preheader materialisation. */
#pragma opt_loop_invariants on
// FUN_0033BE40
u8 *fclItemShopCreate(u8 *shopTask) {
    /* Raw work offsets follow FclItemShopWork above. A typed rewrite produced
       336B instead of the matched 324B; retain this measured byte form. */
    s32 i;
    s32 one;
    u8 *createdTask;
    s8 *allocatedWork;

    chkmemAllocSiteTag(D_0064A380, 0x958);
    allocatedWork = (s8 *)D_008873F4[0](1, 0x42C, 0x40000);
    createdTask = kwlnTaskCreateChild((void *)(shopTask), (const void *)(D_0064A3D8), 0xF, 0, 0, fclItemShopUpdate, fclItemShopDestroy, (u8 *)((u8 *)allocatedWork));
    *(s8 *)(allocatedWork + 0) = 0;
    *(s32 *)(allocatedWork + 0xC) = 0;
    *(f32 *)(allocatedWork + 0x1E0) = (f32)0x28A;
    *(s32 *)(allocatedWork + 0x1E4) = 0x41700000;
    *(s16 *)(allocatedWork + 0x1EA) = 0;
    *(s16 *)(allocatedWork + 0x1EC) = 0;
    *(s8 *)(allocatedWork + 1) = 0;
    *(s32 *)(allocatedWork + 0x2B0) = 0;
    *(s32 *)(allocatedWork + 0x2A8) = 0;
    *(s32 *)(allocatedWork + 0x2AC) = 0;
    *(s8 *)(allocatedWork + 0x424) = 0;
    one = 1;
    i = 0;
    while ((s16)i < 0x24) {
        *(s8 *)(allocatedWork + (s16)i + 0x2D8) = one;
        i = (s16)(i + 1);
    }
    if (fclUnlockMoonPhaseItems() == 1) {
        *(s8 *)(allocatedWork + 0x424) = 1;
    }
    yListCreate(0x10000, 0, 2, 1);
    return createdTask;
}
/* measured: closes the opt_loop_invariants scope required by func_0033be40. */
#pragma opt_loop_invariants off

/* Start the shop exit animation, including money-position interpolation. */
// FUN_0033BF90
void fclItemShopStartExit(u8 *shopTask) {
    /* Raw work offsets follow FclItemShopWork above. A typed rewrite produced
       different register allocation at unchanged size; retain this measured byte form. */
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

    work = *(u8 **)(shopTask + 0x38);
    i = 0;
    while ((s16)i < 4) {
        layer = (s64)(s16)((s16)i * 3);
        itemIndex = (s16)i + 3;
        coords = (f32 *)((u8 *)D_0064A090 + (itemIndex * 8));
        item = work + (s16)i * 4 + 0x1C;
        fclBustupObjStartUniformRevealScale((void *)*(s32 *)item, 1.0f, 0.5f, 0, 10, layer);
        fclBustupObjStartAlpha((void *)*(s32 *)item, 0xFF, 0, 0, 10, layer);
        func_0033d3d0((void *)*(s32 *)item, 0xAC);
        font = sdkSpriteNewNode((void *)*(s32 *)(work + 0xC), itemIndex);
        pos0 = fclMakeVec2(coords[0], coords[1]);
        x = (sdkSpriteScaledWidth(font) / 10.0f) * 1.5f + coords[0] + 0.0f;
        y = (sdkSpriteScaledHeight(font) / 10.0f) * 1.5f + coords[1] + 0.0f;
        pos1 = fclMakeVec2(x, y);
        fclBustupObjStartPosition((void *)*(s32 *)item, pos0, pos1, 0, 10, layer);
        sdkSpriteFreeNode(font);
        i = (s16)(i + 1);
    }
    fclBustupObjChangeFlagBit((void *)*(s32 *)(work + 0x14), 0, 0);
    fclBustupObjStartAlpha((void *)*(s32 *)(work + 0x14), 0xFF, 0, 0, 10, 0);
    func_0033d3d0((void *)*(s32 *)(work + 0x14), 0xAC);
    table = (u8 *)D_0064A1D8;
    pos2 = fclMakeVec2(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos3 = fclMakeVec2(-180.0f, *(f32 *)(table + 4));
    fclBustupObjStartPosition((void *)*(s32 *)(work + 0xB4), pos2, pos3, 0, 0x14, 0);
    table = (u8 *)D_0064A1E0;
    pos4 = fclMakeVec2(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos5 = fclMakeVec2(-200.0f, *(f32 *)(table + 4));
    fclBustupObjStartPosition((void *)*(s32 *)(work + 0xB8), pos4, pos5, 0, 10, 0);
    table = (u8 *)D_0064A1E8;
    pos6 = fclMakeVec2(153.0f, *(f32 *)(table + 4));
    pos7 = fclMakeVec2(-100.0f, *(f32 *)(table + 4));
    fclBustupObjStartPosition((void *)*(s32 *)(work + 0xBC), pos6, pos7, 0, 0x14, 0);
    pos8 = fclMakeVec2(203.0f, *(f32 *)(table + 4));
    pos9 = fclMakeVec2(-50.0f, *(f32 *)(table + 4));
    fclBustupObjStartPosition((void *)*(s32 *)(work + 0x178), pos8, pos9, 0, 0x14, 0);
    table = (u8 *)D_0064A0E8;
    pos10 = fclMakeVec2(*(f32 *)(table + 0), *(f32 *)(table + 4));
    pos11 = fclMakeVec2(-200.0f, *(f32 *)(table + 4));
    fclBustupObjStartPosition((void *)*(s32 *)(work + 0x3C), pos10, pos11, 0, 0xF, 0);
    fclBustupObjStartUniformRevealScale((void *)*(s32 *)(work + 0xB0), 1.0f, 4.5f, 0, 0xF, 0);
    i = 0;
    while ((s16)i < 3) {
        fclBustupObjStartUniformRevealScale((void *)*(s32 *)(work + (s16)i * 4 + 0x17C), 1.0f, 4.5f, 0, 0xF, 0);
        i = (s16)(i + 1);
    }
    func_0033d3c0((void *)*(s32 *)(work + 0x110), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x114), 84.0f);
    func_0033d3c0((void *)*(s32 *)(work + 0x60), 83.0f);
    *(f32 *)(work + 0x1D0) = 580.0f - (f32)fclDecimalDigitCount(fclGetMoney()) * 21.0f;
    *(s32 *)(work + 0x1D4) = 0x41700000;
    *(f32 *)(work + 0x1D8) = (f32)0x28A;
    *(s32 *)(work + 0x1DC) = 0x41700000;
    *(s16 *)(work + 0x1EA) = 0;
    *(s8 *)(work + 0) = 0x11;
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
                  *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
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
    /* Raw work offsets follow FclItemShopWork above. A typed rewrite produced
       1888B for a 1840B retail window; retain this measured byte form. */
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

    p = *(u8 **)(shopTask + 0x38);
    if (*(s8 *)(p + 2) == 1) {
        sdkSpriteDrawQueued(44.0f, 77.0f, 62.0f, fclPackRgba(0xFF, 0x26, 0x26, 0x26), 0xFF, 0x24,
                      *(void **)(p + 0xC), 1, 0, 0, 0.0f, 1.0f, 1.0f, D_00795E60);
        color = fclPackRgba(0x26, 0x26, 0x26, 0xFF);
        value = datGetItemNameId((s16)yListValueAt(*(s16 *)(p + 4)));
        frFontExDrawTextDeferred(78.0f, 77.0f, 62.0f, color, 0, 1, value, 0, 0, D_00795E60);
        pos1 = fclMakeVec2(406.0f, 84.0f);
        col1 = fclMakeDrawColor(0x26, 0x26, 0x26, 0xFF);
        fclShopDrawNumber(pos1, 62.0f, col1,
                      fclItemShopDiscountedPrice(shopTask, yListValueAt(*(s16 *)(p + 4))), 0x19,
                      *(void **)(p + 0xC), 0xAB);
        fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(*(s16 *)(p + 4))), -1, 1, 0, 4, 0xAA,
                      71.0f, 135.0f, 62.0f);
        fclBustupObjChangeFlagBit(*(void **)(p + 0x120), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(p + 0x124), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(p + 0xDC), 0, 0);
        fclBustupObjChangeFlagBit(*(void **)(p + 0xE0), 0, 0);
        fclBustupObjChangeFlagBit(*(void **)(p + 0x6C), 0, 1);
        fclBustupObjChangeFlagBit(*(void **)(p + 0x70), 0, 0);
        fclBustupObjChangeFlagBit(*(void **)(p + 0xD8), 0, 0);
        return;
    }
    fclBustupObjChangeFlagBit(*(void **)(p + 0xDC), 0, 1);
    fclBustupObjChangeFlagBit(*(void **)(p + 0xE0), 0, 1);
    fclBustupObjChangeFlagBit(*(void **)(p + 0x6C), 0, 0);
    fclBustupObjChangeFlagBit(*(void **)(p + 0x70), 0, 1);
    fclBustupObjChangeFlagBit(*(void **)(p + 0xD8), 0, 1);
    tbl = (F2_0033 *)D_0064A2B0;
    fclBustupObjChangeFlagBit(*(void **)(p + 0x120), 0, 0);
    fy = tbl->x;
    *(f32 *)(fclBustupObjGetWork(*(u8 **)(p + 0x120)) + 0x2C) = fy;
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28);
    *(f32 *)(fclBustupObjGetWork(*(u8 **)(p + 0x120)) + 0x30) = fy;
    func_0033d3c0(*(void **)(p + 0x120), 63.0f);
    func_0033d3d0(*(u8 **)(p + 0x120), 0x5B);
    tbl = (F2_0033 *)D_0064A2B8;
    fclBustupObjChangeFlagBit(*(void **)(p + 0x124), 0, 0);
    fy = tbl->x;
    *(f32 *)(fclBustupObjGetWork(*(u8 **)(p + 0x124)) + 0x2C) = fy;
    fy = tbl->y + (f32)(*(s16 *)(p + 6) * 28);
    *(f32 *)(fclBustupObjGetWork(*(u8 **)(p + 0x124)) + 0x30) = fy;
    func_0033d3c0(*(void **)(p + 0x124), 63.0f);
    func_0033d3d0(*(u8 **)(p + 0x124), 0x5B);
    i = *(s16 *)(p + 4) - *(s16 *)(p + 6);
    row = 0;
    bound = i + 5;
    for (; i < bound; i++, row++) {
        if (i >= yListCount()) {
            continue;
        }
        red = green = blue = 0xFF;
        if (i == *(s16 *)(p + 4)) {
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
                      0x19, *(void **)(p + 0xC), 0xAB);
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
/* The shared FclObject exposes only part of this tween payload: remaining byte
   accesses retain the packed sprite ABI (work+4, copied as 0xF0 bytes). */
/* measured: 1216B/1216B MATCH (304 instrs, 0 edits + 9 reloc-only). Re-probed from scratch: floats-first func_0025ecd0 spelling (f32,f32,f32 first, then color/ints, then f32,f32,f32, pointer last) with u16 0xF8 load (lhu) and inline s16/2 division gives retail scheduling; shift+temp hoisting was +33, s16 F8 was +2 (35), archive ints-first is a compile error under this prototype. Mixed-arg orders tested explicitly. */
// FUN_0033CC40
s32 fclItemShopPanelUpdate(u8 *task) {
    /* FclItemShopPanel fields grew this callback to 1252B (retail 1216B);
       keep the packed byte accesses and their measured evaluation order. */
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
        delay = *(s16 *)(panelWork + 0x38);
        if (delay == 0) {
            positionMode = *(s8 *)(panelWork + 0x3B);
            switch (positionMode) {
            case 0:
                *(f32 *)(panelWork + 0x2C) = fclEaseInterpolate(
                    0, *(f32 *)(panelWork + 0x1C), *(f32 *)(panelWork + 0x24),
                    (f32)*(s16 *)(panelWork + 0x36), (f32)*(s16 *)(panelWork + 0x34));
                *(f32 *)(panelWork + 0x30) = fclEaseInterpolate(
                    *(s8 *)(panelWork + 0x3A), *(f32 *)(panelWork + 0x20),
                    *(f32 *)(panelWork + 0x28), (f32)*(s16 *)(panelWork + 0x36),
                    (f32)(*(s16 *)(panelWork + 0x34) / 2));
                break;
            case 1:
                *(f32 *)(panelWork + 0x2C) = fclEaseInterpolate(
                    *(s8 *)(panelWork + 0x3A), *(f32 *)(panelWork + 0x1C),
                    *(f32 *)(panelWork + 0x24), (f32)*(s16 *)(panelWork + 0x36),
                    (f32)(*(s16 *)(panelWork + 0x34) / 2));
                *(f32 *)(panelWork + 0x30) = fclEaseInterpolate(
                    0, *(f32 *)(panelWork + 0x20), *(f32 *)(panelWork + 0x28),
                    (f32)*(s16 *)(panelWork + 0x36), (f32)*(s16 *)(panelWork + 0x34));
                break;
            case 2:
                *(f32 *)(panelWork + 0x2C) = fclEaseInterpolate(
                    1, *(f32 *)(panelWork + 0x1C), *(f32 *)(panelWork + 0x24),
                    (f32)*(s16 *)(panelWork + 0x36), (f32)*(s16 *)(panelWork + 0x34));
                *(f32 *)(panelWork + 0x30) = fclEaseInterpolate(
                    2, *(f32 *)(panelWork + 0x20), *(f32 *)(panelWork + 0x28),
                    (f32)*(s16 *)(panelWork + 0x36), (f32)*(s16 *)(panelWork + 0x34));
                *(f32 *)(panelWork + 0x30) = (f32)(
                    *(f32 *)(panelWork + 0x30) -
                    fclEaseInterpolate(1, 0.0f, 100.0f,
                                  (f32)*(s16 *)(panelWork + 0x36), (f32)(*(s16 *)(panelWork + 0x34) / 2)));
                break;
            }
            duration = *(s16 *)(panelWork + 0x34);
            elapsed = *(s16 *)(panelWork + 0x36);
            if (elapsed < duration) {
                *(s16 *)(panelWork + 0x36) = fclAddClamped(
                    (s32)elapsed, 1, (s32)duration, 0, 1);
            } else {
                *(f32 *)(panelWork + 0x2C) = *(f32 *)(panelWork + 0x24);
                *(f32 *)(panelWork + 0x30) = *(f32 *)(panelWork + 0x28);
                completedMode = *(s8 *)(panelWork + 0x3B);
                if (completedMode == 0) {
                    *(f32 *)(panelWork + 0x30) = *(f32 *)(panelWork + 0x20);
                } else if (completedMode == 1) {
                    *(f32 *)(panelWork + 0x2C) = *(f32 *)(panelWork + 0x1C);
                }
                fclBustupObjChangeFlagBit((u8 *)task, 0xA, 1);
            }
        } else {
            *(s16 *)(panelWork + 0x38) = fclSubClamped(delay, 1, 0, 0, 1);
        }
    }
    if (fclBustupObjTestFlagBit((u8 *)task, 0) == 1) {
        if (fclBustupObjTestFlagBit((u8 *)task, 0xD) == 1) {
            queueNode = (u8 *)PrimAllocQueueNode();
            *(void **)(queueNode + 8) = (void *)fclCombineInitRenderStates;
            *(s32 *)(queueNode + 0x10) = 0;
            PrimAppendNode(
                (void *)((u8 *)D_00793E80 +
                         (*(s32 *)(panelWork + 0xFC) * 0x30)),
                queueNode);
            sdkSpriteDrawQueued(
                *(f32 *)(panelWork + 0x2C), *(f32 *)(panelWork + 0x30),
                *(f32 *)(panelWork + 8),
                fclPackRgba(0xFF, *(u8 *)(panelWork + 0x79),
                              *(u8 *)(panelWork + 0x7A), *(u8 *)(panelWork + 0x7B)),
                *(u8 *)(panelWork + 0x62), *(u16 *)(panelWork + 0xF8),
                (void *)*(s32 *)(panelWork + 0xF4), 0,
                *(s16 *)(panelWork + 0x100), *(s16 *)(panelWork + 0x102),
                *(f32 *)(panelWork + 0xC4),
                *(f32 *)(panelWork + 0x94), *(f32 *)(panelWork + 0xA0),
                (void *)((u8 *)D_00793E80 + (*(s32 *)(panelWork + 0xFC) * 0x30)));
        } else {
            scaleX = *(f32 *)(panelWork + 0x94);
            minimumScale = iGpffff8504;
            if (!(scaleX < minimumScale)) {
                scaleY = *(f32 *)(panelWork + 0xA0);
                if (!(scaleY < minimumScale)) {
                    sdkSpriteDrawQueued(
                        *(f32 *)(panelWork + 0x2C), *(f32 *)(panelWork + 0x30),
                        *(f32 *)(panelWork + 8),
                        fclPackRgba(0xFF, *(u8 *)(panelWork + 0x79),
                                      *(u8 *)(panelWork + 0x7A),
                                      *(u8 *)(panelWork + 0x7B)),
                        *(u8 *)(panelWork + 0x62), *(u16 *)(panelWork + 0xF8),
                        (void *)*(s32 *)(panelWork + 0xF4), 1,
                        *(s16 *)(panelWork + 0x100), *(s16 *)(panelWork + 0x102),
                        *(f32 *)(panelWork + 0xC4),
                        scaleX, scaleY,
                        (void *)((u8 *)D_00793E80 + (*(s32 *)(panelWork + 0xFC) * 0x30)));
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
/* Raw stores initialize the packed tween arrays inside FclObject, whose shared
   declaration intentionally leaves those payload spans opaque. */
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
    *(s32 *)(work + 0xF4) = spriteFile;
    itemData = (f32 *)((u8 *)D_0064A090 + ((panelIndex & 0xFFFF) * 8));
    for (i = 0; (s16)i < 3; i = (s16)(i + 1)) {
        *(f32 *)(work + (s16)i * 8 + 0x1C) = itemData[0];
        *(f32 *)(work + (s16)i * 8 + 0x20) = itemData[1];
        work[(s16)i + 0x60] = 0xFF;
        *(s32 *)(work + (s16)i * 4 + 0x8C) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0x98) = 0x3F800000;
        *(s32 *)(work + (s16)i * 4 + 0xBC) = 0;
        work[(s16)i * 4 + 0x73] = 0xFF;
        work[(s16)i * 4 + 0x72] = 0xFF;
        work[(s16)i * 4 + 0x71] = 0xFF;
    }
    *(s32 *)(work + 8) = 0x42C80000;
    ((FclItemShopPanel *)work)->object.anchorMode = 0x55;
    ((FclItemShopPanel *)work)->object.spriteFlags = 0;
    r = sdkSpriteNewNode((void *)*(s32 *)(work + 0xF4), 0, itemData, i);
    ((FclItemShopPanel *)work)->centerX = (s16)(s32)(sdkSpriteScaledWidth(r) / 2.0f);
    ((FclItemShopPanel *)work)->centerY = (s16)(s32)(sdkSpriteScaledHeight(r) / 2.0f);
    sdkSpriteFreeNode(r);
    return createdTask;
}
/* measured: see annotation above (func_0033d130). */
#pragma opt_loop_invariants off

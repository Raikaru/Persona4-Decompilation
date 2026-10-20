#include "member_access.h"
#include "fcl_object_internal.h"
#include "kwln_task_internal.h"
#include "primitive_queue_internal.h"
/* measured: this unit declared the colour packer with u8 parameters (see fcl_color.h). */
#include "list_item_internal.h"
#include "fcl_scale_transition.h"
#include "fcl_animation_internal.h"
#include "fcl_color.h"
#include "include_asm.h"
#include "sdk_task_registration.h"
#include "fcl_draw_task.h"
/* Original translation unit y_fclShopDraw.c (recovered from embedded __FILE__ assert strings; see tools/tu_audit.py). */
#include "type.h"
#include "fr_font_internal.h"
s32 sdkSndStartStream(s16, s16, s16, s16);

typedef FclVec2 Vec2f;
typedef struct { u8 r, g, b, a; } RGBA;
/* Shop task allocation: 002ca830 requests 0x1174 bytes. The panel handles
 * occupy C38..F14, followed by the three yList children. The row fade tables
 * have nine entries; tab slides use 0x20-byte row / 0xA0-byte tab strides.
 * The last tab's last record is only a six-byte prefix, not a full record. */
typedef union FclShopPanel { void *pointer; s32 word; } FclShopPanel;

typedef struct FclShopWork {
    s8 state;
    u8 pad01;
    s16 cursor;
    s16 scroll;
    u8 pad06;
    s8 category;
    s8 unitSelection;
    s8 unitCount;
    u8 pad0A[2];
    f32 scrollStep;
    s8 messageSlot;
    s8 tab;
    s16 quantity;
    s8 inputBusy;
    u8 pad15;
    s16 unlockedItems[0x600];
    s16 unlockCount;
    s16 unlockIndex;
    s8 cueTimer;
    u8 padC1B[5];
    union { u32 totalPrice; s32 totalPriceSigned; };
    s8 detailMode;
    u8 padC25;
    s16 unkC26;
    void *valuePanels[4];
    /* EE task handles are consumed both as pointers and signed words. */
    FclShopPanel panels[0xB8];
    void *lists[3];
    u8 padF24[4];
    union { u32 word; s32 signedWord; void *pointer; } spriteResource;
    void *loadedFile;
    s8 ready;
    u8 padF31[3];
    f32 centerX;
    f32 centerY;
    s16 colorFrame;
    FclDrawColor savedColors[2];
    s16 rowDelay[9];
    s16 rowFrame[9];
    u8 rowAlpha[9];
    s8 unitIds[9];
    s8 unitIcons[9];
    u8 padF85[0x1B];
    s16 slideWords[0xE4];
    s8 savedCursor[3];
    s8 savedScroll[3];
    union { u8 previousTab; s8 previousTabSigned; };
    u8 pad116F;
    s16 slideTimer;
} FclShopWork;
typedef char FclShopWorkSize[sizeof(FclShopWork) == 0x1174 ? 1 : -1];

static inline f32 shopAdd(f32 left, f32 right) { return left + right; }


/* Shop's loaded CDVD request supplies the message data at +0x110. The
 * request's remaining fields are not read by this translation unit. */
typedef struct FclShopMessageFile {
    u8 pad00[0x110];
    void *messages;
} FclShopMessageFile;
/* Category cursor positions are three-float records in D_0063F9F0. */
typedef struct FclShopTabPosition {
    Vec2f position;
    f32 width;
} FclShopTabPosition;

/* Item panel allocation is 0x104 bytes (002e0300); the shared sprite
 * object is followed by pivots initialized from the resource dimensions. */
typedef struct FclShopItemPanel {
    FclObject object;
    s16 pivotX;
    s16 pivotY;
} FclShopItemPanel;
typedef char FclShopItemPanelSize[sizeof(FclShopItemPanel) == 0x104 ? 1 : -1];

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00795E60[];
extern u8 D_00793E80[]; /* 0x30-byte primitive/render-layer records */
extern char iGpffffa884[2];
extern u8 D_0063FAC0[];
extern u8 D_0063FB30[];
extern u8 D_0063FB70[];
extern u8 D_0063F560[]; /* per-sprite base positions, two floats per entry */
extern u8 D_0063F9F0[]; /* category cursor position/width records */
extern f32 fGpffff8504;
extern f32 D_0063F650[];
extern f32 D_0063F658[];
extern f32 D_0063F5B0[];
extern f32 D_0063F5D0[];
extern f32 D_0063F5D8[];
extern f32 D_0063F5E0[];
extern f32 D_0063F5F0[];
extern f32 D_0063F5F8[];
extern f32 D_0063F880[];
extern f32 D_0063F890[];
extern const s8 D_00748908[];
extern u8 D_00795E30[];
extern u8 D_00794EA0[];
extern u8 D_00794ED0[];
extern u8 D_0063FB50[];

s32 fclShopStateUpdate(u8 *task);
void fclMiscInitRenderStates(void);
s32 datPersonaNamePart1(s16);
void datClampUnitHpSp(s32);
s32 datItemMoonGateFirst(s16);
void chkmemAllocSiteTag(const void *, u32);

s32 fclShopItemPanelUpdate(u8 *task);
void memcpy(void *, s32, s32);
s32 fclSpriteUpdateTweens(void *);
void *PrimAllocQueueNode(void);
void PrimAppendNode(void *, void *);
/* measured: the second parameter is u8 - a u8 lvalue passed to a u8 parameter is a
   plain load and materialises in slot order (li $a0 before lbu $a1); passed to an
   s32 parameter it counts as a conversion and is hoisted ahead of the constant. */
s32 fclPackRgba(u8, u8, u8, u8);
s32 sdkSpriteDrawQueued(f32, f32, f32, s32, u8, s32, void *, s32, s16, s16, f32, f32, f32, void *);


void fclObjChangeFlagBit(u8 *, u32, s8);
void fclObjStartPosition(u8 *, Vec2f, Vec2f, u32, u32, s16);
/* The position constructor fclMakeVec2 (fcl_draw_types.h) returns its
   Vec2f by value. Used as a call argument it yields a compiler temporary,
   which is what fclShopDrawItemDetail's frame layout and saved-register colouring
   require; `sp = fclMakeVec2(x, y)` into a whole local writes it directly. */
void *yListCreateChild(void *, s32, s32, s32, s32);
char *strcpy(char *, const char *);
u8 *sdkSpriteNewNode(u32, u32);

f32 sdkSpriteScaledWidth(u8 *);
f32 sdkSpriteScaledHeight(u8 *);
void sdkSpriteFreeNode(void *);
void sdkSpriteRelease(void *);
void H_Cdvd_Destroy(void *);
void yListDestroy(void);
s64 nmMesWindowAcquire(void *);
void nmMesWindowSetSlotString(s8, s32, void *);
s32 nmMesWindowShowSlotRecord(s8, s32);
void nmMesWindowSetSlotParam(s32, s32);
void nmMesWindowSetSlotFlag(s32, s32);
void nmMesWindowRequestRefresh(void);

s32 fclShopPlaySound(void *, s32, void *, s8);
s32 fclShopPlaySoundParams(void *, s32, void *, void *, s8);
u32 RpRandom(void);
void memset(void *, s32, s32);
/* measured: floats first - retail materialises $f12-$f14 before $a0..$t1. */
void sdkSpriteDrawQueuedUnscaled(f32, f32, f32, s32, u8, s32, void *, s32, void *);
void fclObjStartSlideFade(u8 *, s64, f32, f32, s32, s32, s64);
void fclObjSetAnchorPosition(u8 *, s32, f32);
s32 yListCountFor(void *);
void fclDrawEquipSprite(s32, Vec2f, f32, s32, u8, s32, u8 *);
u32 datGetItemNameId(s16);

s16 datGetEquippedItemByUnit(s16, s16);
/* measured: the item getters take s16, as defined in g_data.c (each callee
   re-extends $a0). A value already typed s16 passes raw; fclShopStateUpdate's int
   ids are extended at every call, and an explicit (s32) widening before an s16
   parameter reproduces the single extension retail emits (func_002df020,
   fclShopDrawScrollThumb, fclShopDrawItemCompare, func_002d5040, fclShopListInputStep). */
u32 datEntryGetFlags(s16);
u16 datEntryGetPrimaryValue(s16);
u16 datEntryGetSecondaryValue(s16);
u16 datEntryGetMiddleBandValue(s16);
u16 datEntryGetLastBandValue(s16);
s32 fclDecimalDigitCount(s32);
void fclDrawNumber(Vec2f, f32, FclDrawColor, s32, s16, u32, s32, s32, s32, s32, s32);
u8 *resourceFindByName(char *);
s32 yListValueAtFor(u8 *, s32);
s32 datItemCount(s16 itemId);
u16 datItemValue(s16);
void fclMesWindowDraw(s32, s32, s32, s32, s32, s32, f32, f32, f32);
void fclDrawEquipHelpSprite(s32, Vec2f, f32, s32, u8, s32, u8 *);
void fclObjSetAnchorAlphaFull(void *, s32, f32);
void fclShopDrawItemText(void *, s8, Vec2f, void *);
void fclShopSlideIndicator(void *, s8);
void fclShopDrawSwingCursor(void *);
s32 yListCount(void);
s32 yListLastIndex(void);
s32 fclAddClamped(s32, s32, s32, s32, s8);
s32 fclSubClamped(s32, s32, s32, s32, s8);
s16 yListStepIndex(s16, s16, s16, s16, s16);
void yListAdvanceCursorScroll(s32, s32, s32, s32, s16 *, s16 *);
void yListRetreatCursorScroll(s32, s32, s32, s32, s16 *, s16 *);
void fclObjStartColor(void *, FclDrawColor, FclDrawColor, s32, s32, s32);
void fclObjSetHoldTimer(void *, f32, s16);
void fclDrawResourceSprite(s32, Vec2f, f32, s32, u8, s32, u8 *);
u32 fclGetMoney(void);
u32 datItemPrice(s16);
s8 yListKind(void);
f32 fclEaseInterpolate(s32, f32, f32, f32, f32);
s32 yListLastIndexFor(void *);
extern f32 D_0063F9C0[];
extern f32 D_0063F9C8[];
extern f32 D_0063F9D0[];
extern f32 D_0063F888[];
extern f32 D_0063F5A0[];
extern f32 D_0063F5A8[];
extern f32 D_0063F5B8[];
extern f32 D_0063F778[];
extern f32 D_0063F780[];
extern f32 D_0063F788[];
extern f32 D_0063F790[];
extern f32 D_0063F798[];
extern f32 D_0063F7A0[];
extern f32 D_0063F7B0[];
extern f32 D_0063F7B8[];
extern f32 D_0063F8C0[];
extern f32 D_0063FA40[];
extern s16 D_0063FA44[];
extern s16 D_0063FA46[];
extern u8 D_0063FA48[];
extern u8 D_0063FA50[];
extern u8 D_0063FA58[];
extern u8 D_0063FA60[];
extern u8 D_0063FA68[];
extern u16 D_008C024E[]; /* confirm/cancel and detail-toggle input mask */
extern u16 D_008C0276[]; /* cursor input mask used for wraparound steps */
extern u16 D_008C027A[]; /* navigation repeat and tab input mask */
extern f32 fGpffff852c;

/* measured: MATCH. Retail builds most positions and colours as struct-return
   temporaries inside the consuming call (fclObjStartPosition(h, fclMakeVec2(..),
   fclMakeVec2(..), ..), *(FclDrawColor *)(.. + 0x79) = fclMakeDrawColor(..)),
   and b210 lays the frame out as named locals, then temporaries in creation
   order, then arrays: the three second-position copies at sp+0x150..0x167 are
   one Vec2f[3] declared ahead of the sprintf buffers. Declaration order of the
   saved-register locals follows the retail registers. */
/* Advance shop loading, menu animations, purchase/sale transactions and message slots; return -1 when closing finishes. */
/* measured: the earlier native-layout trial was 49728B yet MISMATCH due to
 * field-address sharing and index/base addu order. Grouped typed-local and
 * array-base probes now retain MATCH without additional pragmas. Only 32
 * indexed accesses still require MEMBER to preserve aliasing/address order;
 * access-site, typed-local and array/stride singleton results are recorded
 * in build/readability_names/FullEvent19.culprits.tsv.
 * The earlier opt_common_subs-off trial was 51212B and still MISMATCH. */
// FUN_002BE530
s32 fclShopStateUpdate(u8 *task)
{
    typedef struct { s32 itemId; s32 unk04; } ShopArgPair;
    extern void fclShopDrawItemRows(void *, s8, f32, f32);
    extern void fclShopDrawScrollThumb(void *);
    extern s8 fclObjHasStatusFlags(void *);
    extern s32 sdkSndStartStream(s16, s16, s16, s16);
    extern s32 hMaestroDecodeIsReady(s32);
    extern u8 D_0063FAA0[];
    extern u8 D_0063FAD0[];
    extern u8 D_00795FE0[];
    extern char iGpffffa878[8];
    extern char iGpffffa880[8];
    extern f32 fGpffff8520;
    extern f32 fGpffff8524;
    extern f32 fGpffff8528;
    extern f32 fGpffff8170;
    extern u8 D_0063F7C8[];
    extern u8 D_0063F7D0[];
    extern u8 D_0063F9F0[]; /* category cursor position/width records */
    extern u8 D_0063F688[];
    extern u8 D_0063F690[];
    extern u8 D_0063FAF0[];
    extern u8 D_0063FB10[];
    extern void fclDrawMoneyDisplay(void);
    extern s32 sdkSpriteRequestLoad(void *);
    extern void func_00440b68(const void *, const void *, s32);
    extern void *H_Cdvd_AcquireDirectory(const void *, s32);
    extern s32 H_Cdvd_IsFileLoaded(void *);
    extern s32 datGetFlag(s32);
    extern void datSetFlag(s32, s32);
    extern s32 datItemMoonGateSecond(s16);
    extern void datAssignEquippedItem(s16, s16, s16);
    extern s64 calGetDayEntryForMonthDay(s32, s32);
    extern s32 fclSelectBoundedFallback(s32, s32, s32, s32);
    extern s32 nmMesWindowShowSlotRecordStyle1(s64, s32);
    extern s32 nmMesWindowGetSlotState(s8);
    extern void nmMesWindowDestroySlot(s8);
    extern s32 nmMesWindowSlotStatus(s8);
    extern void nmMesWindowStepSlotRelease(s32);
    extern void yListCreate(s32, s32, s32, s32);
    extern s32 yListAuxValueAtFor(void *, s32);
    extern u8 fclCalendarMonth(void);
    extern s32 fclCalendarDay(void);
    extern void fclAddMoney(s32);
    extern void weaponShopTalkCreate(u8 *);
    extern s32 sprintf(char *, const char *, ...);
    extern s32 kwlnTaskGetTaskByName(void *);
    extern u8 sdkSndStartChannel(s16, const char *);
    extern void fclShopPlayItemCue(void *task);
    extern s32 fclShopIsSpecialItem(u16 itemId);
    extern void fclShopItemPanelDestroy(u8 *task);
    extern void fclShopSlideInFromLeft(void *task);
    extern void fclShopDrawItemList(void *task, s8 drawOnly);
    extern void fclShopDrawBuyList(void *task, s8 inputMode);
    extern s32 fclShopListInputStep(void *task);
    extern void fclShopSlideInFromRight(void *task);
    extern s8 fclShopUpdateTabs(void *task, s8 selectedTab);
    extern s32 fclShopStatusFlagToCode(s16 flags);
    extern void fclShopDrawStats(void *task);
    extern void fclShopStartHeaderBars(void *task);
    extern void fclShopStartRowPositions(void *task);
    extern void fclShopStartSelectionShake(void *task);
    extern void fclShopHideSelectionSprites(void *task);
    extern void fclShopSlideInFromAbove(void *task);
    extern void fclShopStartRevealSprites(void *task);
    extern void fclShopLayoutPanels(void *task);
    extern void fclShopDrawItemCompare(void *task);
    extern void fclShopDrawItemDetail(void *task, s16 itemId, s32 auxValue);
    extern void fclShopStartRevealByMode(void *task);
    extern s32 fclShopItemPanelCreate(s32 parent, s16 spriteIndex, u32 spriteResource);
    ShopArgPair messageItem;
    ShopArgPair messageItem2;
    ShopArgPair messageItem3;
    ShopArgPair messageItem4;
    ShopArgPair messageItem5;
    ShopArgPair messageItem6;
    ShopArgPair messageItem7;
    ShopArgPair messageItem8;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4[3];
    char quantityText[0x80];
    char quantityText2[0x10];
    s32 savedScroll;
    s32 savedCursor;
    s32 textColor;
    s32 textColor2;
    s16 itemId;
    s16 index;
    s16 index2;
    s16 index3;
    s32 widenedItemId;
    s16 index4;
    s16 index5;
    s16 index6;
    s32 itemId2;
    s32 totalSalePrice;
    s16 itemId3;
    s32 step;
    s16 index8;
    s16 index9;
    s16 index10;
    void *objectWork;
    void *objectWork2;
    void *objectWork3;
    s32 quantity;
    s32 quantity2;
    s32 scrollBeforeSale;
    s32 tabIndex;
    s32 tabIndex2;
    s16 itemId4;
    s32 panelPivotX;
    s32 detailPivotX;
    s16 index11;
    s16 index12;
    s16 index13;
    s16 index14;
    s16 index15;
    s16 index16;
    void *sprite;
    f32 *positionTable;
    void *objectWork4;
    void *sprite2;
    f32 *positionTable2;
    void *objectWork5;
    void *objectWork6;
    void *objectWork7;
    f32 *positionTable3;
    u8 *work;
    u8 itemFlags;
    f32 *positionTable4;
    f32 *positionTable5;
    s32 previousCursor;
    s32 previousCursorAfterRepeat;
    s32 price;
    s32 panelPivotY;
    s32 detailPivotY;
    s16 itemId5;
    s32 tabIndex3;
    s32 saleItemId;
    s32 stockItemId;
    s32 cursorAfterSale;
    s16 index17;
    s16 index18;
    s16 index19;
    s16 index20;
    s16 index21;
    s16 index22;
    s16 index23;
    s16 index24;
    s16 index25;
    s16 index26;
    s16 index27;
    s16 index28;
    s16 index29;
    s16 index30;
    s16 index31;
    s16 index32;
    s16 index33;
    s16 index34;
    s16 index35;
    s16 index36;
    s16 index37;
    s16 index38;
    s16 index39;
    s16 index40;
    s16 index41;
    s16 index42;
    s32 tabIndex4;
    s32 tabIndex5;
    u32 price2;
    void *objectWork8;
    f32 *positionTable6;
    f32 *positionTable7;
    void *objectWork9;
    void *objectWork10;
    void *objectWork11;
    void *sprite3;
    void *sprite4;
    void *sprite5;
    void *sprite6;
    void *sprite7;
    void *sprite8;
    void *sprite9;
    void *sprite10;
    f32 *tbl;
    void *pos;
    f32 channelValue;
    f32 channelValue2;
    f32 channelValue3;
    f32 channelValue4;
    f32 channelValue5;
    f32 channelValue6;
    f32 channelValue7;
    f32 channelValue8;
    f32 channelValue9;
    f32 channelValue10;
    f32 channelValue11;
    f32 channelValue12;
    f32 coordinate9;
    f32 coordinate10;
    f32 coordinate11;
    f32 coordinate12;
    f32 coordinate13;
    f32 coordinate14;
    f32 coordinate15;
    f32 objectWork12;
    f32 objectWork13;
    f32 coordinate16;
    f32 coordinate17;
    f32 coordinate18;
    f32 coordinate19;
    f32 coordinate20;
    f32 coordinate21;
    f32 coordinate22;
    f32 coordinate23;
    f32 pivotX;
    f32 pivotY;
    f32 channelStart;
    f32 channelStart2;
    f32 channelStart3;
    f32 channelStart4;
    f32 channelStart5;
    f32 channelStart6;
    f32 channelStart7;
    f32 channelStart8;
    f32 channelStart9;
    f32 channelStart10;
    f32 channelStart11;
    f32 channelStart12;
    f32 channelStart13;
    f32 channelStart14;
    f32 channelStart15;
    f32 channelStart16;
    f32 channelStart17;
    f32 channelStart18;
    s32 slideFramesRemaining;
    s32 reverseSlideFramesRemaining;
    s32 lastIndex;
    s32 lastIndex2;
    s32 nextUnlockIndex;
    s32 colorFrame;
    s32 colorFrame2;
    s32 colorFrame3;
    s32 colorFrame4;
    s32 colorFrame5;
    s32 colorFrame6;
    s32 price3;
    s32 price4;
    s32 itemId6;
    s32 calendarDate;
    s32 cursorBeforeSale;
    s16 index43;
    s8 state;
    s8 category;
    s8 category2;
    s8 category3;
    s8 category4;
    s8 tabIndex6;
    s8 tabIndex7;
    s8 greenChannel124;
    s8 blueChannel125;
    s8 redChannel126;
    s8 greenChannel127;
    s8 blueChannel128;
    s8 redChannel129;
    s8 greenChannel130;
    s8 blueChannel131;
    s8 redChannel132;
    s8 greenChannel133;
    s8 blueChannel134;
    s8 redChannel140;
    u32 money;
    u8 green;
    u8 blue;
    u8 red;
    u8 green2;
    u8 blue2;
    u8 red2;
    u8 green3;
    u8 blue3;
    u8 red3;
    u8 green4;
    u8 blue4;
    u8 red4;
    u8 green5;
    u8 blue5;
    u8 red5;
    u8 green6;
    u8 blue6;
    u8 red6;
    void *drawNode;
    void *sprite11;
    void *sprite12;
    void *sprite13;
    void *sprite14;
    void *sprite15;
    void *sprite16;
    void *sprite17;
    void *sprite18;
    void *sprite19;
    void *sprite20;
    void *sprite21;
    void *sprite22;
    void *sprite23;
    void *sprite24;
    void *sprite25;
    void *sprite26;
    void *sprite27;
    void *sprite28;
    void *sprite29;
    FclShopWork *shopWork;

    work = ((void*)((struct KwlnTask *)task)->work);
    shopWork = (FclShopWork *)work;
    step = 0;
    drawNode = PrimAllocQueueNode();
    ((PrimQueueNode *)drawNode)->callback = fclDrawMoneyDisplay;
    ((PrimQueueNode *)drawNode)->argument.data = work;
    PrimAppendNode(D_00795FE0, drawNode);
    state = ((FclShopWork *)work)->state;
    switch (state) {                             /* switch 1 */
    case 0x9:                                       /* switch 1 */
        (((FclShopWork *)work)->spriteResource.signedWord) = sdkSpriteRequestLoad(&D_0063FAA0);
        func_00440b68(iGpffffa878, D_0063FAC0, 0x147);
        (((FclShopWork *)work)->loadedFile) = H_Cdvd_AcquireDirectory(D_0063FAD0, 0);
        ((FclShopWork *)work)->state = 0xA;
        /* fallthrough */
    case 0xA:                                       /* switch 1 */
        if ((hMaestroDecodeIsReady((shopWork->spriteResource.signedWord)) != 0) && (H_Cdvd_IsFileLoaded((((FclShopWork *)work)->loadedFile)) != 0)) {
            ((FclShopWork *)work)->state = 0xB;
            ((FclShopWork *)work)->ready = 1;
            for (index17 = 0; index17 < 0x91; index17++) {
                (((FclShopWork *)work)->panels[(index17)].word) = fclShopItemPanelCreate((s32) task, index17, (((FclShopWork *)work)->spriteResource.word));
            }
            (((FclShopWork *)work)->panels[0x91].word) = fclShopItemPanelCreate((s32) task, 6, (((FclShopWork *)work)->spriteResource.word));
            (((FclShopWork *)work)->panels[0x92].word) = fclShopItemPanelCreate((s32) task, 0xA, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0x93].word) = fclShopItemPanelCreate((s32) task, 0x1D, (shopWork->spriteResource.word));
            for (index35 = 0; index35 < 3; index35++) {
                (((FclShopWork *)work)->panels[(index35) + 0x94].word) = fclShopItemPanelCreate((s32) task, (s16) ((s16) ((index35 + 0x61))), (shopWork->spriteResource.word));
            }
            for (index36 = 0; index36 < 4; index36++) {
                (((FclShopWork *)work)->panels[(index36) + 0x97].word) = fclShopItemPanelCreate((s32) task, (s16) ((s16) ((index36 + 0x19))), (shopWork->spriteResource.word));
            }
            (((FclShopWork *)work)->panels[0x9B].word) = fclShopItemPanelCreate((s32) task, 0x1D, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0x9C].word) = fclShopItemPanelCreate((s32) task, 0x1D, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0x9D].word) = fclShopItemPanelCreate((s32) task, 0x20, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0x9E].word) = fclShopItemPanelCreate((s32) task, 0x21, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0x9F].word) = fclShopItemPanelCreate((s32) task, 3, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA0].word) = fclShopItemPanelCreate((s32) task, 4, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA1].word) = fclShopItemPanelCreate((s32) task, 3, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA2].word) = fclShopItemPanelCreate((s32) task, 4, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA3].word) = fclShopItemPanelCreate((s32) task, 3, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA4].word) = fclShopItemPanelCreate((s32) task, 4, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA7].word) = fclShopItemPanelCreate((s32) task, 3, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA8].word) = fclShopItemPanelCreate((s32) task, 4, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA5].word) = fclShopItemPanelCreate((s32) task, 5, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA9].word) = fclShopItemPanelCreate((s32) task, 0x2B, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xAA].word) = fclShopItemPanelCreate((s32) task, 0x2C, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xA6].word) = fclShopItemPanelCreate((s32) task, 0x5F, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB7].word) = fclShopItemPanelCreate((s32) task, 0x5F, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xAB].word) = fclShopItemPanelCreate((s32) task, 0x65, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xAC].word) = fclShopItemPanelCreate((s32) task, 0x66, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xAD].word) = fclShopItemPanelCreate((s32) task, 0xA, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xAE].word) = fclShopItemPanelCreate((s32) task, 0xA, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xAF].word) = fclShopItemPanelCreate((s32) task, 0x12, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB0].word) = fclShopItemPanelCreate((s32) task, 0xE, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB1].word) = fclShopItemPanelCreate((s32) task, 0x13, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB2].word) = fclShopItemPanelCreate((s32) task, 0xF, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB3].word) = fclShopItemPanelCreate((s32) task, 0x10, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB4].word) = fclShopItemPanelCreate((s32) task, 0x8C, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB5].word) = fclShopItemPanelCreate((s32) task, 0x8D, (shopWork->spriteResource.word));
            (((FclShopWork *)work)->panels[0xB6].word) = fclShopItemPanelCreate((s32) task, 0x8E, (shopWork->spriteResource.word));
            sprite23 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x48));
            pivotX = 632.0f + sdkSpriteScaledWidth(sprite23);
            sdkSpriteFreeNode(sprite23);
            sprite29 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x47));
            pivotY = 136.0f + sdkSpriteScaledHeight(sprite29);
            sdkSpriteFreeNode(sprite29);
            coordinate9 = (f32) 0x1A3;
            ((FclShopWork *)work)->centerX = (f32) (coordinate9 + ((pivotX - coordinate9) / 2.0f));
            ((FclShopWork *)work)->centerY = (f32) (65.0f + ((pivotY - 65.0f) / 2.0f));
            (((FclShopWork *)work)->unitIds[0]) = 1;
            (((FclShopWork *)work)->unitIcons[0]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit(1, 0)))));
            (((FclShopWork *)work)->unitCount) = 1;
            if (datGetFlag(0x30) != 0) {
                (shopWork->unitIds[shopWork->unitCount]) = 2;
                (shopWork->unitIcons[shopWork->unitCount]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitCount]), 0)))));
                (shopWork->unitCount) = (s8) ((shopWork->unitCount) + 1);
            }
            if (datGetFlag(0x31) != 0) {
                (shopWork->unitIds[shopWork->unitCount]) = 3;
                (shopWork->unitIcons[shopWork->unitCount]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitCount]), 0)))));
                (((FclShopWork *)work)->unitCount) = (s8) ((((FclShopWork *)work)->unitCount) + 1);
            }
            if (datGetFlag(0x32) != 0) {
                (shopWork->unitIds[shopWork->unitCount]) = 4;
                (shopWork->unitIcons[shopWork->unitCount]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitCount]), 0)))));
                (shopWork->unitCount) = (s8) ((shopWork->unitCount) + 1);
            }
            if (datGetFlag(0x33) != 0) {
                (shopWork->unitIds[shopWork->unitCount]) = 6;
                (shopWork->unitIcons[shopWork->unitCount]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitCount]), 0)))));
                (((FclShopWork *)work)->unitCount) = (s8) ((((FclShopWork *)work)->unitCount) + 1);
            }
            if (datGetFlag(0x35) != 0) {
                (shopWork->unitIds[shopWork->unitCount]) = 8;
                (shopWork->unitIcons[shopWork->unitCount]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitCount]), 0)))));
                (shopWork->unitCount) = (s8) ((shopWork->unitCount) + 1);
            }
            if (datGetFlag(0x36) != 0) {
                (shopWork->unitIds[shopWork->unitCount]) = 7;
                (shopWork->unitIcons[shopWork->unitCount]) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitCount]), 0)))));
                (((FclShopWork *)work)->unitCount) = (s8) ((((FclShopWork *)work)->unitCount) + 1);
            }
            for (index43 = 0; index43 < 9; index43++) {
                (((FclShopWork *)work)->rowDelay[index43]) = (s16) (index43 * 3);
                (((FclShopWork *)work)->rowFrame[index43]) = 0;
                (((FclShopWork *)work)->rowAlpha[(index43)]) = 0;
            }
            (((FclShopWork *)work)->unitSelection) = 0;
        }
        break;
    case 0xC:                                       /* switch 1 */
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            nmMesWindowDestroySlot((shopWork->messageSlot));
            datSetFlag(0x1324, 1);
            ((FclShopWork *)work)->state = 0xD;
        }
        break;
    case 0xD:                                       /* switch 1 */
        if ((yListCountFor((((FclShopWork *)work)->lists[0])) > D_00748908[0]) && (datGetFlag(0x1324) == 0)) {
            (((FclShopWork *)work)->messageSlot) = nmMesWindowAcquire((((FclShopMessageFile *)((FclShopWork *)work)->loadedFile)->messages));
            nmMesWindowShowSlotRecordStyle1((shopWork->messageSlot), 0xB);
            ((FclShopWork *)work)->state = 0xC;
            return 0;
        }
        if (((s8) (calGetDayEntryForMonthDay((fclCalendarMonth() & 0xFF), (u8)fclCalendarDay() & 0xFF))) == 1) {
            calendarDate = (s16) ((((u8)fclCalendarDay() & 0xFF) + ((fclCalendarMonth() & 0xFF) * 0x64)));
            if ((calendarDate >= 0x190) && (calendarDate < 0x207)) {
                (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 0xC, (((FclShopMessageFile *)((FclShopWork *)work)->loadedFile)->messages), 0);
            } else {
                (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 0xD, (((FclShopMessageFile *)((FclShopWork *)work)->loadedFile)->messages), 0);
            }
        } else {
            (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 0xC, (((FclShopMessageFile *)((FclShopWork *)work)->loadedFile)->messages), 0);
        }
        ((FclShopWork *)work)->state = 0xF;
        break;
    case 0xF:                                       /* switch 1 */
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            nmMesWindowDestroySlot((shopWork->messageSlot));
            ((FclShopWork *)work)->state = 0xE;
        }
        break;
    case 0xE:                                       /* switch 1 */
        (((FclShopWork *)work)->category) = 0;
        positionTable7 = (f32 *)(D_0063F9F0 + ((((FclShopWork *)work)->category) * 0xC));
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x3].pointer), 0x41, 126.0f);
        coordinate16 = positionTable7[0];
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.x) = coordinate16;
        coordinate17 = positionTable7[1];
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y) = coordinate17;
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
        fclObjStartPosition((shopWork->panels[0x3].pointer), fclMakeVec2(positionTable7[0] - 80.0f, positionTable7[1]), fclMakeVec2(positionTable7[0], positionTable7[1]), 0, 3, (s16) ((s16) (((shopWork->category) + 1))));
        fclObjStartAlpha((shopWork->panels[0x3].pointer), 0U, 0xFFU, 0U, 3, (s16) (((shopWork->category) + 1)));
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x4].pointer), 0x41, 127.0f);
        coordinate18 = positionTable7[0] + positionTable7[2];
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.x) = coordinate18;
        coordinate19 = positionTable7[1];
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y) = coordinate19;
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
        fclObjStartPosition((shopWork->panels[0x4].pointer), fclMakeVec2((positionTable7[0] + positionTable7[2]) - 80.0f, positionTable7[1]), fclMakeVec2(positionTable7[0] + positionTable7[2], positionTable7[1]), 0, 3, (s16) ((s16) (((shopWork->category) + 1))));
        fclObjStartAlpha((shopWork->panels[0x4].pointer), 0U, 0xFFU, 0U, 3, (s16) (((shopWork->category) + 1)));
        fclShopStartSelectionShake(task);
        for (index4 = 0; index4 < 7; index4++) {
            positionTable2 = (f32 *)(D_0063F560 + ((index4 + 0x3A) * 8));
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[(index4) + 0x3A].pointer), 0x56, (f32) (index4 + 0x64));
            if (index4 > 0) {
                ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index4) + 0x3A].pointer)))->color = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
            }
            fclObjStartPosition((((FclShopWork *)work)->panels[(index4) + 0x3A].pointer), fclMakeVec2(80.0f + positionTable2[0], positionTable2[1]), fclMakeVec2(positionTable2[0], positionTable2[1]), 0, 3, index4);
            fclObjStartAlpha((((FclShopWork *)work)->panels[(index4) + 0x3A].pointer), 0U, 0xFFU, 0U, 3, index4);
        }
        ((FclObject *)fclObjectGetWork(((&shopWork->panels[0x3B].pointer)[(shopWork->category)])))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x1].pointer), 0x41, 184.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x1].pointer)))->color = fclMakeDrawColor(0x5A, 0, 2, 0xFF);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x0].pointer), 0x56, 182.0f);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x2].pointer), 0x56, 183.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x2].pointer)))->color = fclMakeDrawColor(0xFE, 0xBE, 0x1E, 0xFF);
        sprite14 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(2));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x2].pointer)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite14) / 2.0f))));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x2].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite14) / 2.0f))));
        sdkSpriteFreeNode(sprite14);
        fclObjStartTween((shopWork->panels[0x2].pointer), -90.0f, -90.0f, 0, 0, 0);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x5].pointer), 0x40, 191.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
        sprite15 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(5));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite15))));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotY) = (s16) ((s16) ((sdkSpriteScaledHeight(sprite15))));
        sdkSpriteFreeNode(sprite15);
        fclObjStartAlpha((shopWork->panels[0x5].pointer), 0U, 0xA0U, 0U, 4, 4);
        fclObjStartTween((shopWork->panels[0x5].pointer), 0.0f, fGpffff8520, 0, 4, 4);
        fclObjStartPosition((shopWork->panels[0x5].pointer), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6].pointer), 0x40, 192.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->color = fclMakeDrawColor(0xFF, 0xBE, 0x22, 0xFF);
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.x) = 110.0f;
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.y) = -50.0f;
        sprite16 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite16))));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotY) = 0;
        fclObjStartTween((shopWork->panels[0x6].pointer), -90.0f, fGpffff8524, 0, 4, 0);
        sdkSpriteFreeNode(sprite16);
        fclObjStartAlpha((shopWork->panels[0x6].pointer), 0U, 0xFFU, 0U, 4, 0);
        fclObjSetAnchorPosition((void *) (((FclShopWork *)work)->panels[0x91].word), 0x40, 190.0f);
        (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.x) = 180.0f;
        (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.y) = 30.0f;
        ((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->color = fclMakeDrawColor(0xED, 0x81, 3, 0xFF);
        sprite17 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
        (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite17))));
        (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotY) = 0;
        sdkSpriteFreeNode(sprite17);
        fclObjStartTween((void *) (shopWork->panels[0x91].word), -85.0f, fGpffff8528, 0, 4, 2);
        fclObjStartAlpha((void *) (shopWork->panels[0x91].word), 0U, 0xFFU, 0U, 4, 2);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6C].pointer), 0x41, 46.0f);
        fclObjStartAlpha((shopWork->panels[0x6C].pointer), 0U, 0xFFU, 0U, 6, 0);
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x6C].pointer)))->anchorPosition.x) = 198.0f;
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x6C].pointer)))->anchorPosition.y) = (f32) 0x151;
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6D].pointer), 0x41, 146.0f);
        fclObjStartAlpha((shopWork->panels[0x6D].pointer), 0U, 0xFFU, 0U, 6, 0);
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x6D].pointer)))->anchorPosition.x) = 216.0f;
        (((FclObject *)fclObjectGetWork((shopWork->panels[0x6D].pointer)))->anchorPosition.y) = 368.0f;
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x55].pointer), 0x3F, 207.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x55].pointer)))->color = fclMakeDrawColor(0xFF, 0xAE, 0, 0xFF);
        fclObjStartTween((shopWork->panels[0x55].pointer), 0.0f, 360.0f, 0, 0x708, 0);
        fclObjChangeFlagBit((shopWork->panels[0x55].pointer), 6, 0);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x56].pointer), 0x3D, 209.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x56].pointer)))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        sprite18 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x56));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x56].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite18))));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x56].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite18) / 2.0f))));
        sdkSpriteFreeNode(sprite18);
        fclObjStartTween((shopWork->panels[0x56].pointer), 0.0f, 360.0f, 0, 0x5A0, 0);
        fclObjChangeFlagBit((shopWork->panels[0x56].pointer), 6, 0);
        fclObjStartAlpha((shopWork->panels[0x56].pointer), 0U, 0xFFU, 0U, 0xA, 0);
        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x57].pointer), 0x3D, 210.0f);
        ((FclObject *)fclObjectGetWork((shopWork->panels[0x57].pointer)))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        sprite = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x57));
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x57].pointer)))->pivotX) = 0;
        (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x57].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite) / 2.0f))));
        sdkSpriteFreeNode(sprite);
        fclObjStartTween((shopWork->panels[0x57].pointer), 0.0f, 360.0f, 0, 0x5A0, 0);
        fclObjChangeFlagBit((shopWork->panels[0x57].pointer), 6, 0);
        fclObjStartAlpha((shopWork->panels[0x57].pointer), 0U, 0xFFU, 0U, 0xA, 0);
        for (index37 = 0x59; index37 < 0x60; index37++) {
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index37)].pointer)))->color = fclMakeDrawColor(0xFF, 0xAE, 0, 0xFF);
        }
        for (index38 = 0x64; index38 < 0x67; index38++) {
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index38)].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
        }
        ((FclShopWork *)work)->state = 0x10;
        ((FclShopWork *)work)->unkC26 = 1;
        break;
    case 0x10:                                      /* switch 1 */
        if (D_008C027A[0] & 0x4000) {
            (((FclShopWork *)work)->category) = fclAddClamped((s32) (shopWork->category), 1, 5, 0, 2);
            fclShopStartSelectionShake(task);
            positionTable5 = (f32 *)(D_0063F9F0 + ((shopWork->category) * 0xC));
            coordinate20 = positionTable5[0];
            (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x3].pointer)))->anchorPosition.x) = coordinate20;
            coordinate21 = positionTable5[1];
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y) = coordinate21;
            coordinate22 = positionTable5[0] + positionTable5[2];
            (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x4].pointer)))->anchorPosition.x) = coordinate22;
            coordinate23 = positionTable5[1];
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y) = coordinate23;
            fclObjStartPosition((shopWork->panels[0x3].pointer), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y)), 1, 2, 0);
            fclObjStartPosition((shopWork->panels[0x4].pointer), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y)), 1, 2, 0);
            for (index39 = 0; index39 < 6; index39++) {
                ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index39) + 0x3B].pointer)))->color = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
            }
            ((FclObject *)fclObjectGetWork(((&shopWork->panels[0x3B].pointer)[(shopWork->category)])))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            (((FclShopWork *)work)->category) = fclSubClamped((s32) (shopWork->category), 1, 0, 5, 2);
            fclShopStartSelectionShake(task);
            positionTable4 = (f32 *)(D_0063F9F0 + ((shopWork->category) * 0xC));
            coordinate10 = positionTable4[0];
            (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x3].pointer)))->anchorPosition.x) = coordinate10;
            coordinate11 = positionTable4[1];
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y) = coordinate11;
            coordinate12 = positionTable4[0] + positionTable4[2];
            (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x4].pointer)))->anchorPosition.x) = coordinate12;
            coordinate13 = positionTable4[1];
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y) = coordinate13;
            fclObjStartPosition((shopWork->panels[0x3].pointer), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->anchorPosition.y)), 1, 2, 0);
            fclObjStartPosition((shopWork->panels[0x4].pointer), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->anchorPosition.y)), 1, 2, 0);
            for (index40 = 0; index40 < 6; index40++) {
                ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index40) + 0x3B].pointer)))->color = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
            }
            ((FclObject *)fclObjectGetWork(((&shopWork->panels[0x3B].pointer)[(shopWork->category)])))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C024E[0] & 0x40) {
            fclObjStartTween((((FclShopWork *)work)->panels[0x3].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x3].pointer)))->tweenValue), 0.0f, 0, 2, 0);
            fclObjStartTween((((FclShopWork *)work)->panels[0x4].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x4].pointer)))->tweenValue), 0.0f, 0, 2, 0);
            for (index11 = 0; index11 < 2; index11++) {
                (((FclShopWork *)work)->savedColors[index11].c0) = (u8) (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index11) + 0x3].pointer)))->color.c0);
                (((FclShopWork *)work)->savedColors[index11].c1) = (u8) (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index11) + 0x3].pointer)))->color.c1);
                (((FclShopWork *)work)->savedColors[index11].c2) = (u8) (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index11) + 0x3].pointer)))->color.c2);
            }
            (((FclShopWork *)work)->colorFrame) = 0;
            ((FclShopWork *)work)->state = 0x12;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            for (index41 = 0; index41 < 7; index41++) {
                fclObjStartAlpha((((FclShopWork *)work)->panels[(index41) + 0x3A].pointer), 0xFFU, 0U, 0U, 5, (s16) ((index41 * 2)));
            }
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x3].pointer), 0xFFU, 0U, 0U, 0, (s16) ((((((FclShopWork *)work)->category) * 2) + 2)));
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x4].pointer), 0xFFU, 0U, 0U, 0, (s16) ((((shopWork->category) * 2) + 2)));
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x5].pointer), 0x40, 191.0f);
            sprite19 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(5));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite19) / 2.0f))));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite19) / 2.0f))));
            sdkSpriteFreeNode(sprite19);
            fclObjStartTween((shopWork->panels[0x5].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->tweenValue), 5.0f + (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->tweenValue), 0, 0xA, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->anchorPosition.x) = 14.0f;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->anchorPosition.y) = 164.0f;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6].pointer), 0x40, 192.0f);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.x) = 320.0f;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.y) = 130.0f;
            sprite20 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite20) / 2.0f))));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite20) / 2.0f))));
            fclObjStartTween((shopWork->panels[0x6].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->tweenValue), (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->tweenValue) - 5.0f, 0, 0xA, 0);
            sdkSpriteFreeNode(sprite20);
            fclObjSetAnchorPosition((void *) (((FclShopWork *)work)->panels[0x91].word), 0x40, 190.0f);
            (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.x) = 320.0f;
            (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.y) = 187.0f;
            sprite21 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
            (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite21) / 2.0f))));
            (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite21) / 2.0f))));
            sdkSpriteFreeNode(sprite21);
            fclObjStartTween((void *) (shopWork->panels[0x91].word), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->tweenValue), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->tweenValue) - 5.0f, 0, 0xA, 0);
            for (index42 = 0; index42 < 3; index42++) {
                fclObjStartAlpha((((FclShopWork *)work)->panels[(index42)].pointer), 0xFFU, 0U, 0U, 0xA, 0);
            }
            (shopWork->category) = 5;
            ((FclShopWork *)work)->state = 0x13;
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    case 0x11:                                      /* switch 1 */
        for (index18 = 0x55; index18 < 0x58; index18++) {
            if (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[index18].pointer), 1))) == 0) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[index18].pointer), 3, 0);
            }
        }
        for (index19 = 0x59; index19 < 0x60; index19++) {
            if (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[index19].pointer), 1))) == 0) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[index19].pointer), 3, 0);
            }
        }
        if ((((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x55].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x56].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x57].pointer), 1))) == 0)) {
            ((FclShopWork *)work)->state = 0x10;
        }
        break;
    case 0x12:                                      /* switch 1 */
        for (step = 0; ((s16) (step)) < 2; step = (s16) ((step + 1))) {
            objectWork8 = fclObjectGetWork((((FclShopWork *)work)->panels[((s16) (step)) + 0x3].pointer));
            red2 = (((FclShopWork *)work)->savedColors[(s16) (step)].c0);
            channelStart = (f32) red2;
            (((FclObject *)objectWork8)->color.c0) = (u8) fclEaseInterpolate(1, channelStart, 255.0f, (f32) (((FclShopWork *)work)->colorFrame), 3.0f);
            green3 = (((FclShopWork *)work)->savedColors[(s16) (step)].c1);
            channelStart11 = (f32) green3;
            (((FclObject *)objectWork8)->color.c1) = (u8) fclEaseInterpolate(1, channelStart11, 226.0f, (f32) (shopWork->colorFrame), 3.0f);
            blue3 = (((FclShopWork *)work)->savedColors[(s16) (step)].c2);
            channelStart12 = (f32) blue3;
            (((FclObject *)objectWork8)->color.c2) = (u8) fclEaseInterpolate(1, channelStart12, 145.0f, (f32) (shopWork->colorFrame), 3.0f);
        }
        colorFrame4 = (((FclShopWork *)work)->colorFrame);
        if (colorFrame4 < 6) {
            (shopWork->colorFrame) = fclAddClamped((s32) colorFrame4, 1, 6, 0, 1);
        } else {
            for (index20 = 0; index20 < 2; index20++) {
                ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index20) + 0x3].pointer)))->color = ((FclShopWork *)work)->savedColors[(index20)];
            }
            for (index21 = 0; index21 < 7; index21++) {
                fclObjStartAlpha((((FclShopWork *)work)->panels[(index21) + 0x3A].pointer), 0xFFU, 0U, 0U, 5, (s16) ((index21 * 2)));
            }
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x3].pointer), 0xFFU, 0U, 0U, 0, (s16) ((((((FclShopWork *)work)->category) * 2) + 2)));
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x4].pointer), 0xFFU, 0U, 0U, 0, (s16) ((((shopWork->category) * 2) + 2)));
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x5].pointer), 0x40, 191.0f);
            sprite22 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(5));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite22) / 2.0f))));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite22) / 2.0f))));
            sdkSpriteFreeNode(sprite22);
            fclObjStartTween((shopWork->panels[0x5].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->tweenValue), 5.0f + (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->tweenValue), 0, 0xA, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->anchorPosition.x) = 14.0f;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->anchorPosition.y) = 164.0f;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6].pointer), 0x40, 192.0f);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.x) = 320.0f;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.y) = 130.0f;
            sprite24 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite24) / 2.0f))));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite24) / 2.0f))));
            fclObjStartTween((shopWork->panels[0x6].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->tweenValue), (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->tweenValue) - 5.0f, 0, 0xA, 0);
            sdkSpriteFreeNode(sprite24);
            fclObjSetAnchorPosition((void *) (((FclShopWork *)work)->panels[0x91].word), 0x40, 190.0f);
            (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.x) = 320.0f;
            (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.y) = 187.0f;
            sprite25 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
            (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotX) = (s16) ((s16) (((sdkSpriteScaledWidth(sprite25) / 2.0f))));
            (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotY) = (s16) ((s16) (((sdkSpriteScaledHeight(sprite25) / 2.0f))));
            sdkSpriteFreeNode(sprite25);
            fclObjStartTween((void *) (shopWork->panels[0x91].word), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->tweenValue), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->tweenValue) - 5.0f, 0, 0xA, 0);
            if ((shopWork->category) != 5) {
                pos = fclObjectGetWork((((FclShopWork *)work)->panels[0x56].pointer));
                fclObjStartPosition((shopWork->panels[0x56].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(-262.0f, -56.0f), 0, 0xA, 0);
                pos = fclObjectGetWork((((FclShopWork *)work)->panels[0x57].pointer));
                fclObjStartPosition((shopWork->panels[0x57].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(-9.0f, -56.0f), 0, 0xA, 0);
                pos = fclObjectGetWork((((FclShopWork *)work)->panels[0x55].pointer));
                fclObjStartPosition((shopWork->panels[0x55].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(312.0f, -141.0f), 0, 0xA, 0);
                fclObjStartTween((shopWork->panels[0x55].pointer), 0.0f, 360.0f, 0, 0x708, 0);
                fclObjChangeFlagBit((shopWork->panels[0x55].pointer), 6, 0);
            }
            for (index22 = 0; index22 < 3; index22++) {
                fclObjStartAlpha((((FclShopWork *)work)->panels[(index22)].pointer), 0xFFU, 0U, 0U, 0xA, 0);
            }
            ((FclShopWork *)work)->state = 0x13;
        }
        break;
    case 0x13:                                      /* switch 1 */
        for (index23 = 0x55; index23 < 0x58; index23++) {
            if (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[index23].pointer), 1))) == 0) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[index23].pointer), 3, 0);
            }
        }
        for (index24 = 0x59; index24 < 0x60; index24++) {
            if (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[index24].pointer), 1))) == 0) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[index24].pointer), 3, 0);
            }
        }
        if ((((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x5].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x6].pointer)))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x55].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x56].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x57].pointer), 1))) == 0) && (((s8) (fclObjHasStatusFlags((void *) (((FclShopWork *)work)->panels[0x91].word)))) == 0)) {
            fclObjStartTween((shopWork->panels[0x5].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->tweenValue), 0.0f, 0, 7, 6);
            pos = fclObjectGetWork((shopWork->panels[0x5].pointer));
            fclObjStartPosition((shopWork->panels[0x5].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(-400.0f, 450.0f), 0, 7, 6);
            fclObjStartAlpha((shopWork->panels[0x5].pointer), 0xFFU, 0U, 0U, 7, 6);
            fclObjStartTween((shopWork->panels[0x6].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->tweenValue), 30.0f + (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->tweenValue), 0, 7, 5);
            pos = fclObjectGetWork((shopWork->panels[0x6].pointer));
            fclObjStartPosition((shopWork->panels[0x6].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(700.0f, (f32) 0x2EE), 0, 7, 5);
            fclObjStartAlpha((shopWork->panels[0x6].pointer), 0xFFU, 0U, 0U, 7, 5);
            pos = fclObjectGetWork((void *) (shopWork->panels[0x91].word));
            fclObjStartPosition((void *) (shopWork->panels[0x91].word), ((FclObject *)pos)->anchorPosition, fclMakeVec2(700.0f, (f32) 0x2EE), 0, 7, 3);
            fclObjStartTween((void *) (shopWork->panels[0x91].word), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->tweenValue), 30.0f + (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->tweenValue), 0, 7, 3);
            fclObjStartAlpha((void *) (shopWork->panels[0x91].word), 0xFFU, 0U, 0U, 7, 3);
            category = (((FclShopWork *)work)->category);
            switch (category) {                    /* switch 2 */
            case 0:                                 /* switch 2 */
            case 1:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                fclShopSlideInFromAbove(task);
                break;
            case 3:                                 /* switch 2 */
                fclShopStartRevealSprites(task);
                (((FclShopWork *)work)->totalPrice) = 0;
                for (index25 = 1; index25 < yListCountFor((((FclShopWork *)work)->lists[0])); index25++) {
                    itemId4 = yListValueAtFor((shopWork->lists[0]), (s32) index25);
                    yListAuxValueAtFor((shopWork->lists[0]), (s32) index25);
                    widenedItemId = (s16) (itemId4);
                    fclAddClamped(clndGetMoonPhase(widenedItemId) & 0xFF, datItemCount(itemId4) & 0xFF, 0xFF, 0, 1);
                    price4 = (shopWork->totalPriceSigned) + ((datItemPrice(widenedItemId) / 5U) * (datItemCount(itemId4) & 0xFF));
                    (shopWork->totalPriceSigned) = price4;
                    (shopWork->totalPriceSigned) = fclAddClamped(price4, 0, 0x98967F, 0, 1);
                }
                break;
            case 4:                                 /* switch 2 */
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6C].pointer), 0, 1);
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6D].pointer), 0, 1);
                fclObjStartAlpha((shopWork->panels[0x55].pointer), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((shopWork->panels[0x56].pointer), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((shopWork->panels[0x57].pointer), 0xFFU, 0U, 0U, 0xA, 0);
                weaponShopTalkCreate(task);
                ((FclShopWork *)work)->state = 0x35;
                break;
            case 5:                                 /* switch 2 */
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6C].pointer), 0, 1);
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6D].pointer), 0, 1);
                fclObjStartAlpha((shopWork->panels[0x55].pointer), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((shopWork->panels[0x56].pointer), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((shopWork->panels[0x57].pointer), 0xFFU, 0U, 0U, 0xA, 0);
                ((FclShopWork *)work)->state = 0x37;
                break;
            }
        }
        break;
    case 0x14:                                      /* switch 1 */
        if (((s8) (fclObjHasStatusFlags((void *) (((FclShopWork *)work)->panels[0xA7].word)))) == 0) {
            fclObjStartPosition((void *) (shopWork->panels[0xA7].word), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.y)), 1, 4, 0);
            fclObjStartPosition((void *) (((FclShopWork *)work)->panels[0xA8].word), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.y)), 1, 4, 0);
            ((FclShopWork *)work)->state = 0x15;
        }
        /* fallthrough */
    case 0x15:                                      /* switch 1 */
        if (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x4A].pointer)))) == 0) {
            fclShopDrawItemCompare(task);
        }
        if (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x8].pointer)))) == 0) {
            if (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x5].pointer)))) != 0) {
                step = 1;
            }
            if (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x6].pointer)))) != 0) {
                step = 1;
            }
            if (((s8) (fclObjHasStatusFlags((void *) (((FclShopWork *)work)->panels[0x91].word)))) != 0) {
                step = 1;
            }
            if (((FclShopWork *)work)->state == 0x14) {
                step = 1;
            }
            for (index12 = 0; index12 < ((((FclShopWork *)work)->unitCount)); index12++) {
                if (((&((FclShopWork *)work)->rowDelay[0x0])[index12]) != 0) {
                    ((&((FclShopWork *)work)->rowDelay[0x0])[index12]) = fclSubClamped(((&((FclShopWork *)work)->rowDelay[0x0])[index12]), 1, 0, 0, 1);
                    step = 1;
                } else {
                    ((&((FclShopWork *)work)->rowAlpha[0x0])[index12]) = (u8) fclEaseInterpolate(0, 0.0f, 255.0f, (f32) ((&((FclShopWork *)work)->rowFrame[0x0])[index12]), 6.0f);
                    ((&((FclShopWork *)work)->rowFrame[0x0])[index12]) = fclAddClamped((s32) ((&((FclShopWork *)work)->rowFrame[0x0])[index12]), 1, 6, 0, 1);
                    textColor = fclPackRgba(0xECU, 0x7FU, 0U, ((&((FclShopWork *)work)->rowAlpha[0x0])[index12]));
                    if ((((FclShopWork *)work)->unitSelection) == index12) {
                        textColor = fclPackRgba(0x2DU, 0x2DU, 0x2DU, ((&((FclShopWork *)work)->rowAlpha[0x0])[index12]));
                    }
                    fclShopDrawItemText(task, ((&((FclShopWork *)work)->unitIds[0x0])[index12]), fclMakeVec2(71.0f,  86.0f + 35.0f * (f32) index12), (void *) textColor);
                }
            }
            if (((s16) (step)) == 0) {
                if (D_008C027A[0] & 0x4000) {
                    (((FclShopWork *)work)->unitSelection) = fclAddClamped((s32) (shopWork->unitSelection), 1, (((FclShopWork *)work)->unitCount) - 1, 0, 2);
                    fclShopDrawSwingCursor(task);
                    coordinate14 =  78.0f + 35.0f * (f32) (shopWork->unitSelection);
                    (((FclObject *)fclObjectGetWork((void *) (((FclShopWork *)work)->panels[0xA8].word)))->anchorPosition.y) = coordinate14;
                    (((FclObject *)fclObjectGetWork((void *) (((FclShopWork *)work)->panels[0xA7].word)))->anchorPosition.y) = coordinate14;
                    fclObjStartPosition((void *) (shopWork->panels[0xA7].word), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.y)), 1, 2, 0);
                    fclObjStartPosition((void *) (shopWork->panels[0xA8].word), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.y)), 1, 2, 0);
                    sdkSndStartStream(0, 0, 0, 0);
                } else if (D_008C027A[0] & 0x1000) {
                    (((FclShopWork *)work)->unitSelection) = fclSubClamped((s32) (shopWork->unitSelection), 1, 0, (((FclShopWork *)work)->unitCount) - 1, 2);
                    fclShopDrawSwingCursor(task);
                    coordinate15 =  78.0f + 35.0f * (f32) (shopWork->unitSelection);
                    (((FclObject *)fclObjectGetWork((void *) (((FclShopWork *)work)->panels[0xA8].word)))->anchorPosition.y) = coordinate15;
                    (((FclObject *)fclObjectGetWork((void *) (((FclShopWork *)work)->panels[0xA7].word)))->anchorPosition.y) = coordinate15;
                    fclObjStartPosition((void *) (shopWork->panels[0xA7].word), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->anchorPosition.y)), 1, 2, 0);
                    fclObjStartPosition((void *) (shopWork->panels[0xA8].word), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.y) - 4.0f), fclMakeVec2((((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.x), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->anchorPosition.y)), 1, 2, 0);
                    sdkSndStartStream(0, 0, 0, 0);
                } else if (D_008C024E[0] & 0x20) {
                    sdkSndStartStream(0, 0, 0, 2);
                    tbl = (f32 *) D_0063F5A0;
                    fclObjStartPosition((shopWork->panels[0x8].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
                    fclObjStartAlpha((shopWork->panels[0x8].pointer), 0xCCU, 0U, 0U, 2, 0);
                    tbl = (f32 *) D_0063F5A8;
                    fclObjStartPosition((((FclShopWork *)work)->panels[0x9].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
                    fclObjStartAlpha((shopWork->panels[0x9].pointer), 0xCCU, 0U, 0U, 2, 0);
                    tbl = (f32 *) D_0063F7B0;
                    fclObjStartPosition((shopWork->panels[0x4A].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 400.0f + tbl[1]), 2, 4, 0);
                    tbl = (f32 *) D_0063F7B8;
                    fclObjStartPosition((((FclShopWork *)work)->panels[0x4B].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 400.0f + tbl[1]), 2, 4, 0);
                    fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6C].pointer), 0, 1);
                    fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6E].pointer), 0, 1);
                    fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x41].pointer), 0, 1);
                    for (index8 = 0; index8 < 6; index8++) {
                        positionTable6 = (f32 *)(D_0063F560 + ((index8 + 0x43) * 8));
                        fclObjStartPosition((((FclShopWork *)work)->panels[(index8) + 0x43].pointer), fclMakeVec2(positionTable6[0], positionTable6[1]), fclMakeVec2(positionTable6[0], 700.0f), 2, 5, 0);
                    }
                    fclObjChangeFlagBit((void *) (((FclShopWork *)work)->panels[0xA7].word), 0, 1);
                    fclObjChangeFlagBit((void *) (((FclShopWork *)work)->panels[0xA8].word), 0, 1);
                    fclShopLayoutPanels(task);
                    for (index26 = 0; index26 < 7; index26++) {
                        fclObjChangeFlagBit((((FclShopWork *)work)->panels[(index26) + 0x3A].pointer), 0, 0);
                    }
                    fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x3].pointer), 0, 0);
                    fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x4].pointer), 0, 0);
                    fclObjSetAnchorPosition((shopWork->panels[0x6C].pointer), 0x41, 46.0f);
                    fclObjStartAlpha((shopWork->panels[0x6C].pointer), 0U, 0xFFU, 0U, 6, 0);
                    (((FclObject *)fclObjectGetWork((shopWork->panels[0x6C].pointer)))->anchorPosition.x) = 198.0f;
                    (((FclObject *)fclObjectGetWork((shopWork->panels[0x6C].pointer)))->anchorPosition.y) = (f32) 0x151;
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6D].pointer), 0x41, 146.0f);
                    fclObjStartAlpha((shopWork->panels[0x6D].pointer), 0U, 0xFFU, 0U, 6, 0);
                    (((FclObject *)fclObjectGetWork((shopWork->panels[0x6D].pointer)))->anchorPosition.x) = 216.0f;
                    (((FclObject *)fclObjectGetWork((shopWork->panels[0x6D].pointer)))->anchorPosition.y) = 368.0f;
                    fclObjSetAnchorPosition((shopWork->panels[0x5].pointer), 0x40, 191.0f);
                    sprite26 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(5));
                    (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite26))));
                    (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotY) = (s16) ((s16) ((sdkSpriteScaledHeight(sprite26))));
                    sdkSpriteFreeNode(sprite26);
                    fclObjStartAlpha((shopWork->panels[0x5].pointer), 0U, 0xCCU, 0U, 4, 4);
                    fclObjStartTween((shopWork->panels[0x5].pointer), 0.0f, fGpffff8520, 0, 4, 4);
                    fclObjStartPosition((shopWork->panels[0x5].pointer), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
                    fclObjSetAnchorPosition((shopWork->panels[0x6].pointer), 0x40, 192.0f);
                    (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.x) = 110.0f;
                    (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.y) = -50.0f;
                    sprite27 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
                    (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite27))));
                    (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotY) = 0;
                    fclObjStartTween((shopWork->panels[0x6].pointer), -90.0f, fGpffff8524, 0, 4, 4);
                    fclObjStartAlpha((shopWork->panels[0x6].pointer), 0U, 0xFFU, 0U, 4, 4);
                    sdkSpriteFreeNode(sprite27);
                    fclObjSetAnchorPosition((void *) (shopWork->panels[0x91].word), 0x40, 190.0f);
                    (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.x) = 180.0f;
                    (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.y) = 30.0f;
                    sprite28 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
                    (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite28))));
                    (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotY) = 0;
                    sdkSpriteFreeNode(sprite28);
                    fclObjStartTween((void *) (shopWork->panels[0x91].word), -85.0f, fGpffff8528, 0, 4, 2);
                    fclObjStartAlpha((void *) (shopWork->panels[0x91].word), 0U, 0xFFU, 0U, 4, 2);
                    for (index = 0; index < 7; index++) {
                        positionTable = (f32 *)(D_0063F560 + ((index + 0x3A) * 8));
                        fclObjSetAnchorPosition((((FclShopWork *)work)->panels[(index) + 0x3A].pointer), 0x56, (f32) (index + 0x64));
                        if (index > 0) {
                            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index) + 0x3A].pointer)))->color = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
                        }
                        fclObjStartPosition((((FclShopWork *)work)->panels[(index) + 0x3A].pointer), fclMakeVec2(80.0f + positionTable[0], positionTable[1]), fclMakeVec2(positionTable[0], positionTable[1]), 0, 3, index);
                        fclObjStartAlpha((((FclShopWork *)work)->panels[(index) + 0x3A].pointer), 0U, 0xFFU, 0U, 3, index);
                    }
                    ((FclObject *)fclObjectGetWork(((&shopWork->panels[0x3B].pointer)[(((FclShopWork *)work)->category)])))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    fclObjStartAlpha((shopWork->panels[0x3].pointer), 0U, 0xFFU, 0U, 0, (s64) (shopWork->category));
                    fclObjStartAlpha((shopWork->panels[0x4].pointer), 0U, 0xFFU, 0U, 0, (s64) (shopWork->category));
                    for (index27 = 0; index27 < 3; index27++) {
                        fclObjStartAlpha((((FclShopWork *)work)->panels[(index27)].pointer), 0U, 0xFFU, 0U, 0xA, 0);
                    }
                    fclShopStartSelectionShake(task);
                    ((FclShopWork *)work)->state = 0x11;
                } else if (D_008C024E[0] & 0x40) {
                    fclObjStartTween((void *) (((FclShopWork *)work)->panels[0xA7].word), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA7].word)))->tweenValue), 0.0f, 0, 2, 0);
                    fclObjStartTween((void *) (((FclShopWork *)work)->panels[0xA8].word), (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0xA8].word)))->tweenValue), 0.0f, 0, 2, 0);
                    for (index13 = 0; index13 < 2; index13++) {
                        ((&((FclShopWork *)work)->savedColors[0x0])[index13].c0) = (u8) (((FclObject *)fclObjectGetWork(((&((FclShopWork *)work)->panels[0xA7])[index13].pointer)))->color.c0);
                        ((&((FclShopWork *)work)->savedColors[0x0])[index13].c1) = (u8) (((FclObject *)fclObjectGetWork(((&((FclShopWork *)work)->panels[0xA7])[index13].pointer)))->color.c1);
                        ((&((FclShopWork *)work)->savedColors[0x0])[index13].c2) = (u8) (((FclObject *)fclObjectGetWork(((&((FclShopWork *)work)->panels[0xA7])[index13].pointer)))->color.c2);
                    }
                    (((FclShopWork *)work)->colorFrame) = 0;
                    ((FclShopWork *)work)->state = 0x16;
                    sdkSndStartStream(0, 0, 0, 1);
                }
            }
        }
        break;
    case 0x16:                                      /* switch 1 */
        fclShopDrawItemCompare(task);
        for (step = 0; ((s16) (step)) < (((FclShopWork *)work)->unitCount); step = (s16) ((step + 1))) {
            if ((MEMBER(s16, work + ((s16) step) * 2, FclShopWork, rowDelay[0])) != 0) { /* measured: typing each remaining site here changes 22961 code bytes. */
                (MEMBER(s16, work + ((s16) step) * 2, FclShopWork, rowDelay[0])) = fclSubClamped((MEMBER(s16, work + ((s16) step) * 2, FclShopWork, rowDelay[0])), 1, 0, 0, 1); /* measured: typing each remaining site here changes 22981-23023 code bytes. */
            } else {
                (MEMBER(u8, work + ((s16) step), FclShopWork, rowAlpha[0])) = (u8) fclEaseInterpolate(0, 0.0f, 255.0f, (f32) (MEMBER(s16, work + (((s16) step) * 2), FclShopWork, rowFrame[0])), 6.0f); /* measured: typing each remaining site here changes 22921-22930 code bytes. */
                (MEMBER(s16, work + (((s16) step) * 2), FclShopWork, rowFrame[0])) = fclAddClamped((s32) (MEMBER(s16, work + (((s16) step) * 2), FclShopWork, rowFrame[0])), 1, 6, 0, 1); /* measured: typing each remaining site here changes 22809-22825 code bytes. */
                textColor2 = fclPackRgba(0xECU, 0x7FU, 0U, (MEMBER(u8, work + ((s16) step), FclShopWork, rowAlpha[0]))); /* measured: typing each remaining site here changes 22807 code bytes. */
                if ((((FclShopWork *)work)->unitSelection) == ((s16) step)) {
                    textColor2 = fclPackRgba(0x2DU, 0x2DU, 0x2DU, (MEMBER(u8, work + ((s16) step), FclShopWork, rowAlpha[0]))); /* measured: typing each remaining site here changes 22779 code bytes. */
                }
                fclShopDrawItemText(task, (MEMBER(s8, work + ((s16) step), FclShopWork, unitIds[0])), fclMakeVec2(71.0f,  86.0f + 35.0f * (f32) step), (void *) textColor2); /* measured: typing each remaining site here changes 22716 code bytes. */
            }
        }
        for (index9 = 0; index9 < 2; index9++) {
            objectWork9 = fclObjectGetWork((MEMBER(void *, work + ((index9) * 4), FclShopWork, panels[0xA7].pointer))); /* measured: typing each remaining site here changes 22631 code bytes. */
            red3 = (MEMBER(u8, work + ((index9) * 4), FclShopWork, savedColors[0].c0)); /* measured: typing each remaining site here changes 22628 code bytes. */
            channelStart13 = (f32) red3;
            (((FclObject *)objectWork9)->color.c0) = (u8) fclEaseInterpolate(1, channelStart13, 255.0f, (f32) (((FclShopWork *)work)->colorFrame), 3.0f);
            green4 = (MEMBER(u8, work + ((index9) * 4), FclShopWork, savedColors[0].c1)); /* measured: typing each remaining site here changes 22489 code bytes. */
            channelStart14 = (f32) green4;
            (((FclObject *)objectWork9)->color.c1) = (u8) fclEaseInterpolate(1, channelStart14, 226.0f, (f32) (shopWork->colorFrame), 3.0f);
            blue4 = (MEMBER(u8, work + ((index9) * 4), FclShopWork, savedColors[0].c2)); /* measured: typing each remaining site here changes 22346 code bytes. */
            channelStart15 = (f32) blue4;
            (((FclObject *)objectWork9)->color.c2) = (u8) fclEaseInterpolate(1, channelStart15, 145.0f, (f32) (shopWork->colorFrame), 3.0f);
        }
        colorFrame5 = (((FclShopWork *)work)->colorFrame);
        if (colorFrame5 < 6) {
            (shopWork->colorFrame) = fclAddClamped((s32) colorFrame5, 1, 6, 0, 1);
        } else {
            for (index14 = 0; index14 < 2; index14++) {
                ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[(index14) + 0xA7].pointer)))->color = ((FclShopWork *)work)->savedColors[(index14)];
            }
            tbl = (f32 *) D_0063F7C8;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x4D].pointer), 0x41, 38.0f);
            fclObjStartTween((shopWork->panels[0x4D].pointer), -105.0f, 27.0f, 0, 5, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x4D].pointer)))->color = fclMakeDrawColor(0x97, 0xF, 0, 0xFF);
            panelPivotX = (s16) (((173.0f - tbl[0])));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x4D].pointer)))->pivotX) = (s16) panelPivotX;
            panelPivotY = (s16) ((((f32) 0x223 - tbl[1])));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x4D].pointer)))->pivotY) = (s16) panelPivotY;
            tbl = (f32 *) D_0063F780;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x44].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(-130.0f, tbl[1] - 50.0f), 0, 7, 3);
            fclObjStartTween((shopWork->panels[0x44].pointer), 0.0f, -20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F778;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x43].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0] - 200.0f, -130.0f), 0, 7, 3);
            fclObjStartTween((shopWork->panels[0x43].pointer), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F788;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x45].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0] - 40.0f, (f32) 0x226), 0, 7, 3);
            fclObjStartTween((shopWork->panels[0x45].pointer), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F798;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x47].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(40.0f + tbl[0], (f32) 0x226), 0, 7, 3);
            fclObjStartTween((shopWork->panels[0x47].pointer), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F790;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x46].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(40.0f + tbl[0], -150.0f), 0, 7, 3);
            fclObjStartTween((shopWork->panels[0x46].pointer), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F7A0;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x48].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(40.0f + tbl[0], -200.0f), 0, 7, 3);
            fclObjStartTween((shopWork->panels[0x48].pointer), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F7B0;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x4A].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2((f32) 0x29E + tbl[0], tbl[1] - 300.0f), 1, 0xA, 3);
            fclObjStartTween((shopWork->panels[0x4A].pointer), fGpffff852c, 60.0f, 1, 4, 3);
            tbl = (f32 *) D_0063F7B8;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x4B].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2((f32) 0x29E + tbl[0], tbl[1] - 300.0f), 1, 4, 3);
            fclObjStartTween((shopWork->panels[0x4B].pointer), fGpffff852c, 60.0f, 1, 4, 3);
            tbl = (f32 *) D_0063F5A0;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x8].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
            fclObjStartAlpha((shopWork->panels[0x8].pointer), 0xCCU, 0U, 0U, 2, 0);
            tbl = (f32 *) D_0063F5A8;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x9].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
            fclObjStartAlpha((shopWork->panels[0x9].pointer), 0xCCU, 0U, 0U, 2, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x41].pointer), 0, 1);
            fclObjChangeFlagBit((void *) (((FclShopWork *)work)->panels[0xA7].word), 0, 1);
            fclObjChangeFlagBit((void *) (((FclShopWork *)work)->panels[0xA8].word), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6C].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6E].pointer), 0, 1);
            ((FclShopWork *)work)->state = 0x17;
        }
        break;
    case 0x17:                                      /* switch 1 */
        if (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x4D].pointer), 3))) == 0) {
            fclObjStartTween((shopWork->panels[0x4D].pointer), 27.0f, -14.0f, 0, 3, 0);
            tbl = (f32 *) D_0063F5B8;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0xB].pointer), 0x41, 157.0f);
            fclObjStartPosition((shopWork->panels[0xB].pointer), fclMakeVec2(tbl[0], -300.0f + tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 7, 0);
            fclObjStartAlpha((shopWork->panels[0xB].pointer), 0U, 0xCCU, 0U, 7, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0xB].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjStartTween((shopWork->panels[0xB].pointer), 0.0f, -4.0f, 0, 0, 0);
            detailPivotX = (s16) (((320.0f - tbl[0])));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0xB].pointer)))->pivotX) = (s16) detailPivotX;
            detailPivotY = (s16) (((tbl[1] - 83.0f)));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0xB].pointer)))->pivotY) = (s16) detailPivotY;
            fclObjStartRevealScale((shopWork->panels[0xB].pointer), 1.0f, 1.5f, 1.0f, 1.0f, 0, 0, 0);
            ((FclShopWork *)work)->state = 0x18;
        }
        break;
    case 0x18:                                      /* switch 1 */
        if (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0xB].pointer)))) == 0) {
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x7D].pointer), 0x41, 152.0f);
            fclObjStartAlpha((shopWork->panels[0x7D].pointer), 0U, 0xCCU, 0U, 5, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x7D].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x7E].pointer), 0x41, 152.0f);
            fclObjStartAlpha((shopWork->panels[0x7E].pointer), 0U, 0xCCU, 0U, 5, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x7E].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x4E].pointer), 0x41, 7.0f);
            fclObjStartAlpha((shopWork->panels[0x4E].pointer), 0U, 0xFFU, 0U, 0xA, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x4E].pointer)))->anchorPosition = fclMakeVec2(46.0f, 294.0f);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x51].pointer), 0x41, 8.0f);
            fclObjStartAlpha((shopWork->panels[0x51].pointer), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x68].pointer), 0x41, 45.0f);
            fclObjStartAlpha((shopWork->panels[0x68].pointer), 0U, 0xFFU, 0U, 6, 0);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6C].pointer), 0x41, 46.0f);
            fclObjStartAlpha((shopWork->panels[0x6C].pointer), 0U, 0xFFU, 0U, 6, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6C].pointer)))->anchorPosition.x) = (f32) 0x17F;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6C].pointer)))->anchorPosition.y) = 404.0f;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6E].pointer), 0x41, 47.0f);
            fclObjStartAlpha((shopWork->panels[0x6E].pointer), 0U, 0xFFU, 0U, 6, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6E].pointer)))->anchorPosition.x) = 446.0f;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6E].pointer)))->anchorPosition.y) = 404.0f;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6B].pointer), 0x41, 47.0f);
            fclObjStartAlpha((shopWork->panels[0x6B].pointer), 0U, 0xFFU, 0U, 6, 0);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6A].pointer), 0x41, 47.0f);
            objectWork10 = fclObjectGetWork((shopWork->panels[0x6B].pointer));
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x6A].pointer)))->anchorPosition = ((FclObject *)objectWork10)->anchorPosition;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6A].pointer)))->alpha) = 0xFF;
            fclObjChangeFlagBit((shopWork->panels[0x6A].pointer), 0, 1);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x15].pointer), 0x41, 139.0f);
            fclObjStartAlpha((shopWork->panels[0x15].pointer), 0U, 0xFFU, 0U, 6, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x15].pointer)))->color = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x16].pointer), 0x41, 140.0f);
            fclObjStartAlpha((shopWork->panels[0x16].pointer), 0U, 0xFFU, 0U, 6, 0);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x16].pointer)))->color = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
            (((FclShopWork *)work)->scroll) = 0;
            (((FclShopWork *)work)->cursor) = 0;
            category2 = (((FclShopWork *)work)->category);
            switch (category2) {                    /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                yListCreate(1 << ((s16) (((((s8 *)(work + MEMBER_OFFSET(FclShopWork, unitIcons[0x0])))[((FclShopWork *)work)->unitSelection]) - 0x14))), 1 << ((((FclShopWork *)work)->unitIds[(((FclShopWork *)work)->unitSelection)]) + 4), 2, 2);
                break;
            case 1:                                 /* switch 3 */
                yListCreate(0x4000, 1 << ((shopWork->unitIds[((FclShopWork *)work)->unitSelection]) + 4), 2, 2);
                break;
            case 2:                                 /* switch 3 */
                yListCreate(0x8000, 1 << ((shopWork->unitIds[((FclShopWork *)work)->unitSelection]) + 4), 2, 2);
                break;
            }
            ((FclShopWork *)work)->state = 0x1B;
        }
        break;
    case 0x1B:                                      /* switch 1 */
        fclShopDrawItemList(task, 0);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        break;
    case 0x1C:                                      /* switch 1 */
        fclShopDrawItemList(task, 1);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        for (index2 = 0; index2 < 2; index2++) {
            objectWork2 = fclObjectGetWork((((FclShopWork *)work)->panels[0x64].pointer));
            objectWork4 = fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer));
            red4 = (MEMBER(u8, work + ((index2) * 4), FclShopWork, savedColors[0].c0)); /* measured: typing each remaining site here changes 196 code bytes. */
            channelStart16 = (f32) red4;
            channelValue12 = fclEaseInterpolate(1, channelStart16, 255.0f, (f32) (((FclShopWork *)work)->colorFrame), 3.0f);
            redChannel140 = (u8) channelValue12;
            (((FclObject *)objectWork4)->color.c0) = redChannel140;
            (((FclObject *)objectWork2)->color.c0) = redChannel140;
            green5 = (MEMBER(u8, work + ((index2) * 4), FclShopWork, savedColors[0].c1)); /* measured: typing each remaining site here changes 18880 code bytes. */
            channelStart17 = (f32) green5;
            channelValue = fclEaseInterpolate(1, channelStart17, 226.0f, (f32) (shopWork->colorFrame), 3.0f);
            greenChannel124 = (u8) channelValue;
            (((FclObject *)objectWork4)->color.c1) = greenChannel124;
            (((FclObject *)objectWork2)->color.c1) = greenChannel124;
            blue5 = (MEMBER(u8, work + ((index2) * 4), FclShopWork, savedColors[0].c2)); /* measured: typing each remaining site here changes 18737 code bytes. */
            channelStart18 = (f32) blue5;
            channelValue2 = fclEaseInterpolate(1, channelStart18, 145.0f, (f32) (shopWork->colorFrame), 3.0f);
            blueChannel125 = (u8) channelValue2;
            (((FclObject *)objectWork4)->color.c2) = blueChannel125;
            (((FclObject *)objectWork2)->color.c2) = blueChannel125;
        }
        colorFrame6 = (((FclShopWork *)work)->colorFrame);
        if (colorFrame6 < 6) {
            (shopWork->colorFrame) = fclAddClamped((s32) colorFrame6, 1, 6, 0, 1);
        } else {
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x64].pointer)))->color = ((FclShopWork *)work)->savedColors[0];
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer)))->color = ((FclShopWork *)work)->savedColors[1];
            messageItem.itemId = yListValueAt((shopWork->cursor));
            messageItem.unk04 = 0;
            (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 1, &messageItem, 1);
            ((FclShopWork *)work)->state = 0x1D;
            fclShopStartHeaderBars(task);
            fclObjChangeFlagBit((shopWork->panels[0x64].pointer), 0, 1);
            fclObjChangeFlagBit((shopWork->panels[0x66].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 1);
        }
        break;
    case 0x1D:                                      /* switch 1 */
        fclShopDrawStats(task);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        fclShopDrawItemText(task, (shopWork->unitIds[((FclShopWork *)work)->unitSelection]), fclMakeVec2(51.0f, 48.0f), (void *) fclPackRgba(0xFFU, 0xFFU, 0xFFU, 0xFFU));
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else if (nmMesWindowGetSlotState((shopWork->messageSlot)) == 0) {
            sdkSndStartStream(0, 0, 0, 6);
            nmMesWindowDestroySlot((shopWork->messageSlot));
            fclAddMoney(fclGetMoney() - datItemPrice((s16) ((s16) (yListValueAt((shopWork->cursor))))));
            messageItem2.itemId = yListValueAt((shopWork->cursor));
            messageItem2.unk04 = 0;
            (shopWork->messageSlot) = fclShopPlaySound(task, 4, &messageItem2, 1);
            ((FclShopWork *)work)->state = 0x1E;
        } else {
            fclShopStartRowPositions(task);
            nmMesWindowDestroySlot((shopWork->messageSlot));
            ((FclShopWork *)work)->state = 0x1B;
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 0);
        }
        break;
    case 0x1E:                                      /* switch 1 */
        fclShopDrawStats(task);
        fclShopDrawItemText(task, (shopWork->unitIds[((FclShopWork *)work)->unitSelection]), fclMakeVec2(51.0f, 48.0f), (void *) fclPackRgba(0xFFU, 0xFFU, 0xFFU, 0xFFU));
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            if (nmMesWindowGetSlotState((shopWork->messageSlot)) == 0) {
                sdkSndStartStream(0, 0, 0, 7);
                nmMesWindowDestroySlot((shopWork->messageSlot));
                messageItem3.itemId = (s32) ((s16) (datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitSelection]), (s16) (((FclShopWork *)work)->category))));
                messageItem3.unk04 = 0;
                (shopWork->messageSlot) = fclShopPlaySound(task, 5, &messageItem3, 1);
                ((FclShopWork *)work)->state = 0x1F;
            } else {
                nmMesWindowDestroySlot((shopWork->messageSlot));
                datItemSetCount(((s16) (yListValueAt((shopWork->cursor)))), ((datItemCount((s16) ((s16) (yListValueAt((shopWork->cursor))))) & 0xFF) + 1) & 0xFF);
                ((FclShopWork *)work)->state = 0x1B;
            }
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 0);
            if (yListCount() > 5) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x64].pointer), 0, 0);
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x66].pointer), 0, 0);
            }
            fclShopStartRowPositions(task);
        }
        break;
    case 0x1F:                                      /* switch 1 */
        fclShopDrawStats(task);
        fclShopDrawItemList(task, 1);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            if (nmMesWindowGetSlotState((shopWork->messageSlot)) == 0) {
                fclAddMoney(fclGetMoney() + (datItemPrice(datGetEquippedItemByUnit((s16) (shopWork->unitIds[((FclShopWork *)work)->unitSelection]), (s16) (((FclShopWork *)work)->category))) >> 2));
                sdkSndStartStream(0, 0, 0, 6);
            } else {
                datItemSetCount(datGetEquippedItemByUnit((s16) (shopWork->unitIds[((FclShopWork *)work)->unitSelection]), (s16) (((FclShopWork *)work)->category)), ((datItemCount(datGetEquippedItemByUnit((s16) (shopWork->unitIds[shopWork->unitSelection]), (s16) (shopWork->category))) & 0xFF) + 1) & 0xFF);
            }
            datAssignEquippedItem((s16) (shopWork->unitIds[shopWork->unitSelection]), (s16) (shopWork->category), (s16) ((s16) (yListValueAt((shopWork->cursor)))));
            nmMesWindowDestroySlot((shopWork->messageSlot));
            ((FclShopWork *)work)->state = 0x1B;
        }
        break;
    case 0x20:                                      /* switch 1 */
        fclShopDrawItemList(task, 1);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        if ((((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x64].pointer), 9))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x66].pointer), 9))) == 0)) {
            fclObjStartTween((((FclShopWork *)work)->panels[0x4D].pointer), -14.0f, 110.0f, 0, 4, 0);
            tbl = (f32 *) D_0063F7D0;
            fclObjStartUniformRevealScale((((FclShopWork *)work)->panels[0x4E].pointer), 1.0f, 1.5f, 0, 5, 0);
            fclObjStartAlpha((shopWork->panels[0x4E].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x4E].pointer)))->alpha), 0U, 0U, 5, 0);
            sprite2 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(0x4E));
            fclObjStartPosition((shopWork->panels[0x4E].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0] - 2.5f * (sdkSpriteScaledWidth(sprite2) / 10.0f), tbl[1] - 2.5f * (sdkSpriteScaledHeight(sprite2) / 10.0f)), 0, 5, 0);
            sdkSpriteFreeNode(sprite2);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x51].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x51].pointer)))->alpha), 0U, 0U, 5, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x15].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x15].pointer)))->alpha), 0U, 0U, 5, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x16].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x16].pointer)))->alpha), 0U, 0U, 5, 0);
            pos = fclObjectGetWork((shopWork->panels[0x64].pointer));
            objectWork12 = (((FclObject *)fclObjectGetWork((shopWork->panels[0x64].pointer)))->anchorPosition.x) - 1000.0f;
            fclObjStartPosition((shopWork->panels[0x64].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(objectWork12, (((FclObject *)fclObjectGetWork((shopWork->panels[0x64].pointer)))->anchorPosition.y)), 2, 3, 0);
            pos = fclObjectGetWork((shopWork->panels[0x66].pointer));
            objectWork13 = (((FclObject *)fclObjectGetWork((shopWork->panels[0x66].pointer)))->anchorPosition.x) - 1000.0f;
            fclObjStartPosition((shopWork->panels[0x66].pointer), ((FclObject *)pos)->anchorPosition, fclMakeVec2(objectWork13, (((FclObject *)fclObjectGetWork((shopWork->panels[0x66].pointer)))->anchorPosition.y)), 2, 3, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6B].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6A].pointer), 0, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0xB].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0xB].pointer)))->alpha), 0U, 0U, 0xA, 0);
            tbl = (f32 *) D_0063F5B0;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0xA].pointer), 0x41, 109.0f);
            fclObjStartPosition((shopWork->panels[0xA].pointer), fclMakeVec2(660.0f + tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0xA].pointer)))->alpha) = 0xCC;
            ((FclObject *)fclObjectGetWork((shopWork->panels[0xA].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
            tbl = (f32 *) D_0063F5F0;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x12].pointer), 0x41, 109.0f);
            fclObjStartPosition((shopWork->panels[0x12].pointer), fclMakeVec2(660.0f + tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x12].pointer)))->alpha) = 0xCC;
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x12].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
            tbl = (f32 *) D_0063F5D0;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0xE].pointer), 0x41, 111.0f);
            fclObjStartPosition((shopWork->panels[0xE].pointer), fclMakeVec2(660.0f + tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0xE].pointer)))->alpha) = 0xCC;
            ((FclObject *)fclObjectGetWork((shopWork->panels[0xE].pointer)))->color = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjSetAnchorPosition((void *) (((FclShopWork *)work)->panels[0x92].word), 0x41, 109.0f);
            fclObjStartPosition((void *) (shopWork->panels[0x92].word), fclMakeVec2((f32) -0x266, 242.0f), fclMakeVec2(86.0f, 242.0f), 0, 4, 6);
            ((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x92].word)))->color = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            tbl = (f32 *) D_0063F5F8;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x13].pointer), 0x41, 112.0f);
            fclObjStartPosition((shopWork->panels[0x13].pointer), fclMakeVec2(tbl[0] - 700.0f, tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x13].pointer)))->color = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            tbl = (f32 *) D_0063F5D8;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0xF].pointer), 0x41, 113.0f);
            fclObjStartPosition((shopWork->panels[0xF].pointer), fclMakeVec2(tbl[0] - 700.0f, tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            tbl = (f32 *) D_0063F5E0;
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x10].pointer), 0x41, 114.0f);
            fclObjStartPosition((shopWork->panels[0x10].pointer), fclMakeVec2(tbl[0] - 700.0f, tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            ((FclShopWork *)work)->state = 0x21;
        }
        break;
    case 0x21:                                      /* switch 1 */
        if (fclShopListInputStep(task) == 1) {
            if ((D_008C0276[0] & 0x1000) && ((((FclShopWork *)work)->inputBusy) == 0)) {
                sdkSndStartStream(0, 0, 0, 0);
                if ((((FclShopWork *)work)->cursor) == 0) {
                    lastIndex = yListLastIndex();
                    (shopWork->cursor) = lastIndex;
                    (((FclShopWork *)work)->scroll) = fclAddClamped(0, (s32) ((s16) ((s64) lastIndex)), 4, 0, 1);
                } else {
                    (shopWork->cursor) = fclSubClamped((s32) (shopWork->cursor), 1, 0, yListCount(), 2);
                    (((FclShopWork *)work)->scroll) = yListStepIndex((s32) (shopWork->cursor), (s32) (shopWork->scroll), (s32) ((s16) (yListCount())), 5, -1);
                }
                (shopWork->inputBusy) = 1;
                return 0;
            }
            if (D_008C027A[0] & 0x1000) {
                if (yListCount() > 0) {
                    if ((((FclShopWork *)work)->cursor) != 0) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    (shopWork->cursor) = fclSubClamped((s32) (shopWork->cursor), 1, 0, 0, 1);
                    (((FclShopWork *)work)->scroll) = yListStepIndex((s32) (shopWork->cursor), (s32) (shopWork->scroll), (s32) ((s16) (yListCount())), 5, -1);
                    (((FclShopWork *)work)->inputBusy) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C0276[0] & 0x4000) && ((((FclShopWork *)work)->inputBusy) == 0)) {
                sdkSndStartStream(0, 0, 0, 0);
                lastIndex2 = fclAddClamped((s32) (((FclShopWork *)work)->cursor), 1, yListLastIndex(), 0, 2);
                (shopWork->cursor) = lastIndex2;
                if (((s16) ((s64) lastIndex2)) == 0) {
                    (((FclShopWork *)work)->scroll) = 0;
                } else if (yListLastIndex() >= 5) {
                    (((FclShopWork *)work)->scroll) = yListStepIndex((s32) (shopWork->cursor), (s32) (shopWork->scroll), (s32) ((s16) (yListLastIndex())), 5, 1);
                } else {
                    (((FclShopWork *)work)->scroll) = yListStepIndex((s32) (shopWork->cursor), (s32) (shopWork->scroll), (s32) ((s16) (yListLastIndex())), (s32) ((s16) (yListCount())), 1);
                }
                (shopWork->inputBusy) = 1;
                return 0;
            }
            if (D_008C027A[0] & 0x4000) {
                if (yListCount() > 0) {
                    previousCursor = (((FclShopWork *)work)->cursor);
                    if (previousCursor != yListLastIndex()) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    (shopWork->cursor) = fclAddClamped((s32) (shopWork->cursor), 1, yListLastIndex(), 0, 1);
                    if (yListLastIndex() >= 5) {
                        (((FclShopWork *)work)->scroll) = yListStepIndex((s32) (shopWork->cursor), (s32) (shopWork->scroll), (s32) ((s16) (yListLastIndex())), 5, 1);
                    } else {
                        (((FclShopWork *)work)->scroll) = yListStepIndex((s32) (shopWork->cursor), (s32) (shopWork->scroll), (s32) ((s16) (yListLastIndex())), (s32) ((s16) (yListCount())), 1);
                    }
                    (((FclShopWork *)work)->inputBusy) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
                previousCursorAfterRepeat = (((FclShopWork *)work)->cursor);
                if (previousCursorAfterRepeat != yListLastIndex()) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll((s32) (shopWork->cursor), (s32) (((FclShopWork *)work)->scroll), yListCount(), 5, &shopWork->cursor, &shopWork->scroll);
            } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
                if ((((FclShopWork *)work)->cursor) != 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListRetreatCursorScroll((s32) (shopWork->cursor), (s32) (((FclShopWork *)work)->scroll), yListCount(), 5, &shopWork->cursor, &shopWork->scroll);
            } else if (D_008C027A[0] & 8) {
                (((FclShopWork *)work)->cursor) = 0;
                (((FclShopWork *)work)->scroll) = 0;
                (((FclShopWork *)work)->unitSelection) = fclAddClamped((s32) (shopWork->unitSelection), 1, (((FclShopWork *)work)->unitCount) - 1, 0, 2);
                category3 = (((FclShopWork *)work)->category);
                switch (category3) {                /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    yListRebuild(1 << ((s16) (((shopWork->unitIcons[shopWork->unitSelection]) - 0x14))), 1 << ((((FclShopWork *)work)->unitIds[(shopWork->unitSelection)]) + 4), 2, 2);
                    break;
                case 1:                             /* switch 4 */
                    yListRebuild(0x4000, 1 << ((shopWork->unitIds[shopWork->unitSelection]) + 4), 2, 2);
                    break;
                case 2:                             /* switch 4 */
                    yListRebuild(0x8000, 1 << ((shopWork->unitIds[shopWork->unitSelection]) + 4), 2, 2);
                    break;
                }
                fclShopSlideInFromLeft(task);
                fclShopSlideIndicator(task, 0);
                sdkSndStartStream(0, 0, 0, 5);
            } else if (D_008C027A[0] & 4) {
                (((FclShopWork *)work)->cursor) = 0;
                (((FclShopWork *)work)->scroll) = 0;
                (((FclShopWork *)work)->unitSelection) = fclSubClamped((s32) (shopWork->unitSelection), 1, 0, (((FclShopWork *)work)->unitCount) - 1, 2);
                category4 = (((FclShopWork *)work)->category);
                switch (category4) {                /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    yListRebuild(1 << ((s16) (((shopWork->unitIcons[shopWork->unitSelection]) - 0x14))), 1 << ((((FclShopWork *)work)->unitIds[(shopWork->unitSelection)]) + 4), 2, 2);
                    break;
                case 1:                             /* switch 5 */
                    yListRebuild(0x4000, 1 << ((shopWork->unitIds[shopWork->unitSelection]) + 4), 2, 2);
                    break;
                case 2:                             /* switch 5 */
                    yListRebuild(0x8000, 1 << ((shopWork->unitIds[shopWork->unitSelection]) + 4), 2, 2);
                    break;
                }
                fclShopSlideInFromLeft(task);
                fclShopSlideIndicator(task, 0);
                sdkSndStartStream(0, 0, 0, 5);
            } else if (D_008C024E[0] & 0x20) {
                fclShopSlideInFromRight(task);
                ((FclShopWork *)work)->state = 0x22;
                fclObjStartTween((((FclShopWork *)work)->panels[0x7D].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x7D].pointer)))->tweenValue), 0.0f, 0, 2, 0);
                fclObjStartTween((((FclShopWork *)work)->panels[0x7E].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x7E].pointer)))->tweenValue), 0.0f, 0, 2, 0);
                sdkSndStartStream(0, 1, 0, 4);
            } else if (D_008C024E[0] & 0x80) {
                fclShopSlideInFromRight(task);
                ((FclShopWork *)work)->state = 0x22;
                fclObjStartTween((((FclShopWork *)work)->panels[0x7D].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x7D].pointer)))->tweenValue), 0.0f, 0, 2, 0);
                fclObjStartTween((((FclShopWork *)work)->panels[0x7E].pointer), (((FclObject *)fclObjectGetWork((shopWork->panels[0x7E].pointer)))->tweenValue), 0.0f, 0, 2, 0);
                sdkSndStartStream(0, 1, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if (yListCount() > 0) {
                    if ((datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))) <= fclGetMoney()) && ((datItemCount((s16) ((s16) (yListValueAt((shopWork->cursor))))) & 0xFF) < 0x63)) {
                        messageItem4.itemId = yListValueAt((shopWork->cursor));
                        messageItem4.unk04 = 0;
                        (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 1, &messageItem4, 1);
                        ((FclShopWork *)work)->state = 0x23;
                        sdkSndStartStream(0, 0, 0, 1);
                    } else {
                        sdkSndStartStream(0, 0, 0, 8);
                    }
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            }
block_368:
            (((FclShopWork *)work)->inputBusy) = 0;
            break;
        }
        break;
    case 0x22:                                      /* switch 1 */
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((((FclShopWork *)work)->cursor))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        fclShopDrawItemList(task, 0);
        if ((((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x4E].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x51].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x15].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x16].pointer)))) == 0)) {
            ((FclShopWork *)work)->state = 0x1B;
        }
        break;
    case 0x23:                                      /* switch 1 */
        fclShopListInputStep(task);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else if (nmMesWindowGetSlotState((shopWork->messageSlot)) == 0) {
            sdkSndStartStream(0, 0, 0, 6);
            nmMesWindowDestroySlot((shopWork->messageSlot));
            fclShopSlideInFromRight(task);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x64].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x66].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 1);
            messageItem5.itemId = yListValueAt((((FclShopWork *)work)->cursor));
            messageItem5.unk04 = 0;
            (shopWork->messageSlot) = fclShopPlaySound(task, 4, &messageItem5, 1);
            fclShopStartHeaderBars(task);
            fclAddMoney(fclGetMoney() - datItemPrice((s16) ((s16) (yListValueAt((shopWork->cursor))))));
            ((FclShopWork *)work)->state = 0x1E;
        } else {
            nmMesWindowDestroySlot((shopWork->messageSlot));
            ((FclShopWork *)work)->state = 0x21;
        }
        break;
    case 0x24:                                      /* switch 1 */
        (((FclShopWork *)work)->quantity) = 1;
        if (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0xB].pointer)))) == 0) {
            fclShopDrawBuyList(task, 0);
        }
        break;
    case 0x25:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        fclShopDrawScrollThumb(task);
        for (step = 0; ((s16) (step)) < 2; step = (s16) ((step + 1))) {
            objectWork5 = fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer));
            objectWork11 = fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer));
            red5 = (MEMBER(u8, work + (((s16) (step)) * 4), FclShopWork, savedColors[0].c0)); /* measured: typing each remaining site here changes 13132 code bytes. */
            channelStart2 = (f32) red5;
            channelValue3 = fclEaseInterpolate(1, channelStart2, 255.0f, (f32) (((FclShopWork *)work)->colorFrame), 3.0f);
            redChannel126 = (u8) channelValue3;
            (((FclObject *)objectWork11)->color.c0) = redChannel126;
            (((FclObject *)objectWork5)->color.c0) = redChannel126;
            green6 = (MEMBER(u8, work + (((s16) (step)) * 4), FclShopWork, savedColors[0].c1)); /* measured: typing each remaining site here changes 13131 code bytes. */
            channelStart3 = (f32) green6;
            channelValue4 = fclEaseInterpolate(1, channelStart3, 226.0f, (f32) (shopWork->colorFrame), 3.0f);
            greenChannel127 = (u8) channelValue4;
            (((FclObject *)objectWork11)->color.c1) = greenChannel127;
            (((FclObject *)objectWork5)->color.c1) = greenChannel127;
            blue6 = (MEMBER(u8, work + (((s16) (step)) * 4), FclShopWork, savedColors[0].c2)); /* measured: typing each remaining site here changes 12988 code bytes. */
            channelStart4 = (f32) blue6;
            channelValue5 = fclEaseInterpolate(1, channelStart4, 145.0f, (f32) (shopWork->colorFrame), 3.0f);
            blueChannel128 = (u8) channelValue5;
            (((FclObject *)objectWork11)->color.c2) = blueChannel128;
            (((FclObject *)objectWork5)->color.c2) = blueChannel128;
        }
        colorFrame = (((FclShopWork *)work)->colorFrame);
        if (colorFrame < 6) {
            (shopWork->colorFrame) = fclAddClamped((s32) colorFrame, 1, 6, 0, 1);
        } else {
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer)))->color = ((FclShopWork *)work)->savedColors[0];
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer)))->color = ((FclShopWork *)work)->savedColors[1];
            tabIndex6 = (((FclShopWork *)work)->tab);
            if ((tabIndex6 == 0) && ((((FclShopWork *)work)->cursor) == 0)) {
                totalSalePrice = 0;
                for (index15 = 1; index15 < yListCountFor((((FclShopWork *)work)->lists[(shopWork->tab)])); index15++) {
                    itemId6 = yListValueAtFor((((FclShopWork *)work)->lists[(shopWork->tab)]), (s32) index15);
                    totalSalePrice += (datItemPrice(itemId6) / 5U) * (datItemCount(itemId6) & 0xFF);
                }
                sprintf(quantityText, iGpffffa880, fclAddClamped(totalSalePrice, 0, 0x98967F, 0, 1));
                (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 6, quantityText, 1);
                ((FclShopWork *)work)->state = 0x2E;
            } else if (yListCountFor(((&shopWork->lists[0])[tabIndex6])) > 0) {
                fclObjStartAlpha((shopWork->panels[0x65].pointer), 0xFFU, 0U, 0U, 5, 0);
                fclObjStartAlpha((shopWork->panels[0x66].pointer), 0xFFU, 0U, 0U, 5, 0);
                if (((FclShopWork *)work)->detailMode == 0) {
                    sprite3 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(0x2A));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x2A].pointer), 0x56, 16.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x2A].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x2A].pointer), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((shopWork->panels[0x2A].pointer), fclMakeVec2(63.0f, 143.0f + 2.5f * (sdkSpriteScaledHeight(sprite3) / 10.0f)), fclMakeVec2(63.0f, 143.0f), 0, 5, 0);
                    fclObjStartAlpha((shopWork->panels[0x2A].pointer), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x2A].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite3);
                    sprite4 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x2C));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x2C].pointer), 0x56, 18.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x2C].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x2C].pointer), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((shopWork->panels[0x2C].pointer), fclMakeVec2((f32) 0x222, 143.0f + 2.5f * (sdkSpriteScaledHeight(sprite4) / 10.0f)), fclMakeVec2((f32) 0x222, 143.0f), 0, 5, 0);
                    fclObjStartAlpha((shopWork->panels[0x2C].pointer), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x2C].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite4);
                    sprite5 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x27));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x27].pointer), 0x41, 20.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x27].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x27].pointer), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((shopWork->panels[0x27].pointer), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((shopWork->panels[0x27].pointer), fclMakeVec2(46.0f, 132.0f + 2.0f * (sdkSpriteScaledHeight(sprite5) / 10.0f)), fclMakeVec2(46.0f, 132.0f), 2, 4, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x27].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite5);
                    sprite6 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x29));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x29].pointer), 0x41, 21.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x29].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x29].pointer), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((shopWork->panels[0x29].pointer), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((shopWork->panels[0x29].pointer), fclMakeVec2((f32) 0x232, 132.0f + 2.0f * (sdkSpriteScaledHeight(sprite6) / 10.0f)), fclMakeVec2((f32) 0x232, 132.0f), 2, 4, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x29].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite6);
                } else {
                    sprite7 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(0x2B));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x2B].pointer), 0x56, 16.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x2B].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x2B].pointer), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((shopWork->panels[0x2B].pointer), fclMakeVec2(67.0f, 140.0f + 2.5f * (sdkSpriteScaledHeight(sprite7) / 10.0f)), fclMakeVec2(67.0f, 140.0f), 0, 5, 0);
                    fclObjStartAlpha((shopWork->panels[0x2B].pointer), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x2B].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite7);
                    sprite8 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x2C));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x2C].pointer), 0x56, 18.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x2C].pointer)))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x2C].pointer), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((shopWork->panels[0x2C].pointer), fclMakeVec2((f32) 0x22F, 140.0f + 2.5f * (sdkSpriteScaledHeight(sprite8) / 10.0f)), fclMakeVec2((f32) 0x22F, 140.0f), 0, 5, 0);
                    fclObjStartAlpha((shopWork->panels[0x2C].pointer), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x2C].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite8);
                    sprite9 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x28));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x28].pointer), 0x41, 20.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x28].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x28].pointer), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((shopWork->panels[0x28].pointer), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((shopWork->panels[0x28].pointer), fclMakeVec2(48.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight(sprite9) / 10.0f)), fclMakeVec2(48.0f, 127.0f), 2, 4, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x28].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite9);
                    sprite10 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(0x29));
                    fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x29].pointer), 0x41, 21.0f);
                    ((FclObject *)fclObjectGetWork((shopWork->panels[0x29].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((shopWork->panels[0x29].pointer), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((shopWork->panels[0x29].pointer), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((shopWork->panels[0x29].pointer), fclMakeVec2(584.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight(sprite10) / 10.0f)), fclMakeVec2(584.0f, 127.0f), 2, 4, 0);
                    fclObjSetHoldTimer((shopWork->panels[0x29].pointer), 6.0f, 3);
                    sdkSpriteFreeNode(sprite10);
                }
                tbl = (f32 *) D_0063F688;
                fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x25].pointer), 0x57, 14.0f);
                fclObjStartPosition((shopWork->panels[0x25].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1] - 7.0f), 1, 0xA, 2);
                fclObjStartAlpha((shopWork->panels[0x25].pointer), 0U, 0xFFU, 0U, 0xA, 2);
                (((FclObject *)fclObjectGetWork((shopWork->panels[0x25].pointer)))->mode) = 1;
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x25].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                (((FclObject *)fclObjectGetWork((shopWork->panels[0x25].pointer)))->colorLoop) = 1;
                tbl = (f32 *) D_0063F690;
                fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x26].pointer), 0x57, 15.0f);
                fclObjStartPosition((shopWork->panels[0x26].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 7.0f + tbl[1]), 1, 0xA, 2);
                fclObjStartAlpha((shopWork->panels[0x26].pointer), 0U, 0xFFU, 0U, 0xA, 2);
                (((FclObject *)fclObjectGetWork((shopWork->panels[0x26].pointer)))->mode) = 1;
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x26].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                (((FclObject *)fclObjectGetWork((shopWork->panels[0x26].pointer)))->colorLoop) = 1;
                fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x24].pointer), 0x57, 15.0f);
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x24].pointer)))->color = fclMakeDrawColor(0xDF, 0x6C, 0, 0xFF);
                fclObjStartAlpha((shopWork->panels[0x24].pointer), 0U, 0xFFU, 0U, 4, 2);
                ((FclShopWork *)work)->state = 0x27;
            }
        }
        break;
    case 0x27:                                      /* switch 1 */
        itemId5 = yListValueAtFor(((&shopWork->lists[0])[(((FclShopWork *)work)->tab)]), (s32) (((FclShopWork *)work)->cursor));
        tabIndex = yListAuxValueAtFor(((&shopWork->lists[0])[(shopWork->tab)]), (s32) (shopWork->cursor)) & 0xFF;
        fclShopDrawBuyList(task, 2);
        fclShopDrawItemDetail(task, itemId5, tabIndex);
        fclShopDrawScrollThumb(task);
        if (D_008C027A[0] & 0x1000) {
            quantity = (((FclShopWork *)work)->quantity);
            if (quantity != (datItemCount(itemId5) & 0xFF)) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (shopWork->quantity) = fclAddClamped((s32) (shopWork->quantity), 1, datItemCount(itemId5) & 0xFF, 1, 1);
            tbl = (f32 *) D_0063F688;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x25].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1] - 7.0f), 1, 0xA, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x25].pointer)))->colorLoop) = 1;
        } else if (D_008C027A[0] & 0x2000) {
            quantity2 = (((FclShopWork *)work)->quantity);
            if (quantity2 != (datItemCount(itemId5) & 0xFF)) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (shopWork->quantity) = fclAddClamped((s32) (shopWork->quantity), 0xA, datItemCount(itemId5) & 0xFF, 1, 1);
            tbl = (f32 *) D_0063F688;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x25].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1] - 7.0f), 1, 0xA, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x25].pointer)))->colorLoop) = 1;
        } else if (D_008C027A[0] & 0x4000) {
            if ((((FclShopWork *)work)->quantity) != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (shopWork->quantity) = fclSubClamped((s32) (shopWork->quantity), 1, 1, datItemCount(itemId5) & 0xFF, 1);
            tbl = (f32 *) D_0063F690;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x26].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 7.0f + tbl[1]), 1, 0xA, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x26].pointer)))->colorLoop) = 1;
        } else if (D_008C027A[0] & 0x8000) {
            if ((((FclShopWork *)work)->quantity) != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (shopWork->quantity) = fclSubClamped((s32) (shopWork->quantity), 0xA, 1, datItemCount(itemId5) & 0xFF, 1);
            tbl = (f32 *) D_0063F690;
            fclObjStartPosition((((FclShopWork *)work)->panels[0x26].pointer), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 7.0f + tbl[1]), 1, 0xA, 0);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x26].pointer)))->colorLoop) = 1;
        } else if (D_008C024E[0] & 0x40) {
            messageItem6.itemId = (s32) ((s16) (itemId5));
            messageItem6.unk04 = 0;
            sprintf(quantityText2, iGpffffa880, (((FclShopWork *)work)->quantity));
            (((FclShopWork *)work)->messageSlot) = fclShopPlaySoundParams(task, 2, &messageItem6, quantityText2, 1);
            ((FclShopWork *)work)->state = 0x28;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            sdkSndStartStream(0, 0, 0, 2);
            fclShopStartRevealByMode(task);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x25].pointer), 0xFFU, 0U, 0U, 5, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x26].pointer), 0xFFU, 0U, 0U, 5, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x24].pointer), 0, 1);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x65].pointer), 0U, 0xFFU, 0U, 5, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x66].pointer), 0U, 0xFFU, 0U, 5, 0);
            ((FclShopWork *)work)->state = 0x24;
            if (((FclShopWork *)work)->detailMode == 1) {
                ((FclShopWork *)work)->state = 0x31;
            }
        }
        break;
    case 0x28:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        itemId3 = yListValueAtFor(((&shopWork->lists[0])[(((FclShopWork *)work)->tab)]), (s32) (((FclShopWork *)work)->cursor));
        tabIndex3 = (s16) (yListAuxValueAtFor(((&shopWork->lists[0])[(shopWork->tab)]), (s32) (shopWork->cursor)));
        tabIndex2 = yListCountFor(((&shopWork->lists[0])[(shopWork->tab)]));
        savedCursor = (shopWork->cursor);
        savedScroll = (((FclShopWork *)work)->scroll);
        fclShopDrawItemDetail(task, itemId3, tabIndex3 & 0xFF);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            (((FclShopWork *)work)->unlockCount) = 0;
            (((FclShopWork *)work)->unlockIndex) = 0;
            if (nmMesWindowGetSlotState((shopWork->messageSlot)) == 0) {
                sdkSndStartStream(0, 0, 0, 6);
                if (datEntryGetKind(itemId3) == 5) {
                    saleItemId = (s16) (itemId3);
                    datSetStateTableEntry(saleItemId, fclAddClamped(clndGetMoonPhase(saleItemId) & 0xFF, (s32) (((FclShopWork *)work)->quantity), 0xFF, 0, 1) & 0xFF);
                    for (index28 = 0; index28 < 0x2FF; index28++) {
                        if (!(clndGetMoonPhase(index28) & 0xFF)) {
                            if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateFirst(index28) & 0xFFF00) >> 8), datItemMoonGateFirst(index28) & 0xFF) == 1) {
                                if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateSecond(index28) & 0xFFF00) >> 8), datItemMoonGateSecond(index28) & 0xFF) == 1) {
                                    (((FclShopWork *)work)->unlockedItems[(((FclShopWork *)work)->unlockCount)]) = index28;
                                    (((FclShopWork *)work)->unlockCount) = (s16) ((((FclShopWork *)work)->unlockCount) + 1);
                                }
                            }
                        }
                    }
                }
                price2 = datItemPrice((s32) itemId3) / 5U;
                money = fclGetMoney();
                fclAddMoney(money + ((((FclShopWork *)work)->quantity) * price2));
                datItemSetCount(itemId3, ((datItemCount(itemId3) & 0xFF) - (shopWork->quantity)) & 0xFF);
                tabIndex7 = (shopWork->tab);
                switch (tabIndex7) {                /* switch 6; irregular */
                case 0:                             /* switch 6 */
                    yListRebuildFor(((&shopWork->lists[0])[tabIndex7]), 0x40000, 0, 4, 0);
                    (((FclShopWork *)work)->totalPrice) = 0;
                    for (index10 = 1; index10 < yListCountFor((((FclShopWork *)work)->lists[(shopWork->tab)])); index10++) {
                        itemId = yListValueAtFor((((FclShopWork *)work)->lists[(shopWork->tab)]), (s32) index10);
                        yListAuxValueAtFor((((FclShopWork *)work)->lists[(shopWork->tab)]), (s32) index10);
                        stockItemId = (s16) (itemId);
                        fclAddClamped((clndGetMoonPhase(stockItemId) & 0xFF), datItemCount(itemId) & 0xFF, 0xFF, 0, 1);
                        price3 = (shopWork->totalPriceSigned) + ((datItemPrice(stockItemId) / 5U) * (datItemCount(itemId) & 0xFF));
                        (shopWork->totalPriceSigned) = price3;
                        (shopWork->totalPriceSigned) = fclAddClamped(price3, 0, 0x98967F, 0, 1);
                    }
                    break;
                case 1:                             /* switch 6 */
                    yListRebuildFor(((&shopWork->lists[0])[tabIndex7]), 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:                             /* switch 6 */
                    yListRebuildFor(((&shopWork->lists[0])[tabIndex7]), 0x10000, 0, 1, 0);
                    break;
                }
                if (tabIndex2 != yListCountFor(((&shopWork->lists[0])[(shopWork->tab)]))) {
                    cursorBeforeSale = (s16) ((s64) savedCursor);
                    if ((cursorBeforeSale - ((s16) ((s64) savedScroll))) > 0) {
                        cursorAfterSale = (s16) (fclSubClamped((s32) cursorBeforeSale, 1, 0, 0, 1));
                        (shopWork->cursor) = 0;
                        (shopWork->cursor) = fclAddClamped((s32) (shopWork->cursor), (s32) ((s16) (cursorAfterSale)), yListLastIndexFor(((&shopWork->lists[0])[(shopWork->tab)])), 0, 1);
                    } else {
                        (shopWork->cursor) = fclAddClamped((s32) (shopWork->cursor), 0, yListLastIndexFor(((&shopWork->lists[0])[(shopWork->tab)])), 0, 1);
                    }
                    (shopWork->scroll) = fclAddClamped((s32) (shopWork->scroll), 0, yListLastIndexFor(((&shopWork->lists[0])[(shopWork->tab)])), 0, 1);
                }
                fclShopUpdateTabs(task, (s8) (s32) (shopWork->tab));
            }
            fclShopStartRevealByMode(task);
            nmMesWindowDestroySlot((shopWork->messageSlot));
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x25].pointer), 0xFFU, 0U, 0U, 5, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x26].pointer), 0xFFU, 0U, 0U, 5, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x24].pointer), 0, 1);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x65].pointer), 0U, 0xFFU, 0U, 5, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x66].pointer), 0U, 0xFFU, 0U, 5, 0);
            ((FclShopWork *)work)->state = 0x24;
            if (((FclShopWork *)work)->detailMode == 1) {
                if (yListCountFor(((&shopWork->lists[0])[(shopWork->tab)])) <= D_00748908[(shopWork->tab)]) {
                    fclShopHideSelectionSprites(task);
                } else {
                    ((FclShopWork *)work)->state = 0x31;
                }
            }
            if ((shopWork->unlockCount) > 0) {
                (((FclShopWork *)work)->cueTimer) = 0;
                fclShopPlayItemCue(task);
                ((FclShopWork *)work)->state = 0x29;
            }
        }
        break;
    case 0x2E:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            (((FclShopWork *)work)->unlockCount) = 0;
            (((FclShopWork *)work)->unlockIndex) = 0;
            if (nmMesWindowGetSlotState((shopWork->messageSlot)) == 0) {
                nmMesWindowDestroySlot((shopWork->messageSlot));
                sdkSndStartStream(0, 0, 0, 6);
                for (index16 = 1; index16 < yListCountFor((((FclShopWork *)work)->lists[(((FclShopWork *)work)->tab)])); index16++) {
                    itemId2 = yListValueAtFor((((FclShopWork *)work)->lists[(shopWork->tab)]), (s32) index16);
                    yListAuxValueAtFor((((FclShopWork *)work)->lists[(shopWork->tab)]), (s32) index16);
                    datSetStateTableEntry(itemId2, fclAddClamped((clndGetMoonPhase(itemId2) & 0xFF), datItemCount(itemId2) & 0xFF, 0xFF, 0, 1) & 0xFF);
                    price = (datItemPrice(itemId2) / 5U) * (datItemCount(itemId2) & 0xFF);
                    money = fclGetMoney();
                    fclAddMoney(money + price);
                    datItemSetCount(itemId2, 0);
                }
                (((FclShopWork *)work)->totalPrice) = 0;
                for (index29 = 0; index29 < 0x2FF; index29++) {
                    if (!(clndGetMoonPhase(index29) & 0xFF)) {
                        if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateFirst(index29) & 0xFFF00) >> 8), datItemMoonGateFirst(index29) & 0xFF) == 1) {
                            if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateSecond(index29) & 0xFFF00) >> 8), datItemMoonGateSecond(index29) & 0xFF) == 1) {
                                (((FclShopWork *)work)->unlockedItems[(((FclShopWork *)work)->unlockCount)]) = index29;
                                (((FclShopWork *)work)->unlockCount) = (s16) ((((FclShopWork *)work)->unlockCount) + 1);
                            }
                        }
                    }
                }
                yListRebuildFor(((&shopWork->lists[0])[(shopWork->tab)]), 0x40000, 0, 4, 0);
                (shopWork->totalPriceSigned) = 0;
                (((FclShopWork *)work)->cursor) = fclAddClamped((s32) (shopWork->cursor), 0, yListLastIndexFor(((&shopWork->lists[0])[(shopWork->tab)])), 0, 1);
                scrollBeforeSale = (((FclShopWork *)work)->scroll);
                if (fclSelectBoundedFallback((s32) (shopWork->scroll), 5, yListCountFor(((&shopWork->lists[0])[(shopWork->tab)])), yListLastIndexFor(((&shopWork->lists[0])[(shopWork->tab)]))) < scrollBeforeSale) {
                    (shopWork->scroll) = fclSelectBoundedFallback((s32) (shopWork->scroll), 5, (s32) ((s16) (yListCountFor(((&shopWork->lists[0])[(shopWork->tab)])))), (s32) ((s16) (yListLastIndexFor(((&shopWork->lists[0])[(shopWork->tab)])))));
                }
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x82].pointer), 0, 1);
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x83].pointer), 0, 1);
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x84].pointer), 0, 1);
                fclShopUpdateTabs(task, (s8) (s32) (shopWork->tab));
                ((FclShopWork *)work)->state = 0x24;
                if (((FclShopWork *)work)->detailMode == 1) {
                    fclShopHideSelectionSprites(task);
                }
                if ((shopWork->unlockCount) > 0) {
                    (((FclShopWork *)work)->cueTimer) = 0;
                    fclShopPlayItemCue(task);
                    ((FclShopWork *)work)->state = 0x29;
                }
            } else {
                nmMesWindowDestroySlot((shopWork->messageSlot));
                ((FclShopWork *)work)->state = 0x24;
                if (((FclShopWork *)work)->detailMode == 1) {
                    fclShopHideSelectionSprites(task);
                }
            }
        }
        break;
    case 0x29:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        fclShopDrawScrollThumb(task);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            nmMesWindowDestroySlot((shopWork->messageSlot));
            sdkSndStartChannel(2, (const char *) D_0063FAF0);
            ((FclShopWork *)work)->state = 0x2A;
        }
        break;
    case 0x2A:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        fclShopDrawScrollThumb(task);
        (((FclShopWork *)work)->cueTimer) = fclAddClamped((s32) (shopWork->cueTimer), 1, 0x3C, 0, 1);
        if ((shopWork->cueTimer) >= 0x3C) {
            (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 0xA, NULL, 0);
            ((FclShopWork *)work)->state = 0x2B;
            (shopWork->cueTimer) = 0;
        }
        break;
    case 0x2B:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        fclShopDrawScrollThumb(task);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            nmMesWindowDestroySlot((shopWork->messageSlot));
            messageItem7.itemId = (s32) ((&shopWork->unlockedItems[0])[(((FclShopWork *)work)->unlockIndex)]);
            messageItem7.unk04 = 0;
            (shopWork->messageSlot) = fclShopPlaySound(task, 3, &messageItem7, 0);
            ((FclShopWork *)work)->state = 0x2D;
        }
        break;
    case 0x2C:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        fclShopDrawScrollThumb(task);
        messageItem8.itemId = (s32) ((&shopWork->unlockedItems[0])[(((FclShopWork *)work)->unlockIndex)]);
        messageItem8.unk04 = 0;
        (((FclShopWork *)work)->messageSlot) = fclShopPlaySound(task, 3, &messageItem8, 0);
        ((FclShopWork *)work)->state = 0x2D;
        break;
    case 0x2D:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        fclShopDrawScrollThumb(task);
        if (nmMesWindowSlotStatus((((FclShopWork *)work)->messageSlot)) != 0) {
            nmMesWindowStepSlotRelease((shopWork->messageSlot));
        } else {
            itemFlags = clndGetMoonPhase(((&shopWork->unlockedItems[0])[(((FclShopWork *)work)->unlockIndex)]));
            datSetStateTableEntry(((&shopWork->unlockedItems[0])[(shopWork->unlockIndex)]), itemFlags | 1);
            nmMesWindowDestroySlot((shopWork->messageSlot));
            nextUnlockIndex = (shopWork->unlockIndex) + 1;
            (shopWork->unlockIndex) = nextUnlockIndex;
            if (((s16) ((s64) nextUnlockIndex)) >= (((FclShopWork *)work)->unlockCount)) {
                ((FclShopWork *)work)->state = 0x24;
                if (((FclShopWork *)work)->detailMode == 1) {
                    ((FclShopWork *)work)->state = 0x31;
                }
            } else {
                fclShopPlayItemCue(task);
                ((FclShopWork *)work)->state = 0x29;
            }
        }
        break;
    case 0x26:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        for (index5 = 0; index5 < 2; index5++) {
            objectWork3 = fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer));
            objectWork6 = fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer));
            red6 = (MEMBER(u8, work + ((index5) * 4), FclShopWork, savedColors[0].c0)); /* measured: typing each remaining site here changes 5862 code bytes. */
            channelStart5 = (f32) red6;
            channelValue6 = fclEaseInterpolate(1, channelStart5, 255.0f, (f32) (((FclShopWork *)work)->colorFrame), 3.0f);
            redChannel129 = (u8) channelValue6;
            (((FclObject *)objectWork6)->color.c0) = redChannel129;
            (((FclObject *)objectWork3)->color.c0) = redChannel129;
            green = (MEMBER(u8, work + ((index5) * 4), FclShopWork, savedColors[0].c1)); /* measured: typing each remaining site here changes 5865 code bytes. */
            channelStart6 = (f32) green;
            channelValue7 = fclEaseInterpolate(1, channelStart6, 226.0f, (f32) (shopWork->colorFrame), 3.0f);
            greenChannel130 = (u8) channelValue7;
            (((FclObject *)objectWork6)->color.c1) = greenChannel130;
            (((FclObject *)objectWork3)->color.c1) = greenChannel130;
            blue = (MEMBER(u8, work + ((index5) * 4), FclShopWork, savedColors[0].c2)); /* measured: typing each remaining site here changes 5724 code bytes. */
            channelStart7 = (f32) blue;
            channelValue8 = fclEaseInterpolate(1, channelStart7, 145.0f, (f32) (shopWork->colorFrame), 3.0f);
            blueChannel131 = (u8) channelValue8;
            (((FclObject *)objectWork6)->color.c2) = blueChannel131;
            (((FclObject *)objectWork3)->color.c2) = blueChannel131;
        }
        colorFrame2 = (((FclShopWork *)work)->colorFrame);
        if (colorFrame2 < 6) {
            (shopWork->colorFrame) = fclAddClamped((s32) colorFrame2, 1, 6, 0, 1);
        } else {
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer)))->color = ((FclShopWork *)work)->savedColors[0];
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer)))->color = ((FclShopWork *)work)->savedColors[1];
            position = ((FclObject *)fclObjectGetWork((shopWork->panels[0x65].pointer)))->anchorPosition;
            fclObjStartPosition((shopWork->panels[0x65].pointer), position, fclMakeVec2(position.x - 1000.0f, position.y), 1, 3, 0);
            position4[2] = ((FclObject *)fclObjectGetWork((shopWork->panels[0x66].pointer)))->anchorPosition;
            fclObjStartPosition((shopWork->panels[0x66].pointer), position4[2], fclMakeVec2(position4[2].x - 1000.0f, position4[2].y), 1, 3, 0);
            ((FclShopWork *)work)->state = 0x2F;
        }
        break;
    case 0x2F:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        for (index6 = 0; index6 < 2; index6++) {
            objectWork = fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer));
            objectWork7 = fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer));
            red = (MEMBER(u8, work + ((index6) * 4), FclShopWork, savedColors[0].c0)); /* measured: typing each remaining site here changes 5102 code bytes. */
            channelStart8 = (f32) red;
            channelValue9 = fclEaseInterpolate(1, channelStart8, 255.0f, (f32) (((FclShopWork *)work)->colorFrame), 3.0f);
            redChannel132 = (u8) channelValue9;
            (((FclObject *)objectWork7)->color.c0) = redChannel132;
            (((FclObject *)objectWork)->color.c0) = redChannel132;
            green2 = (MEMBER(u8, work + ((index6) * 4), FclShopWork, savedColors[0].c1)); /* measured: typing each remaining site here changes 5105 code bytes. */
            channelStart9 = (f32) green2;
            channelValue10 = fclEaseInterpolate(1, channelStart9, 226.0f, (f32) (shopWork->colorFrame), 3.0f);
            greenChannel133 = (u8) channelValue10;
            (((FclObject *)objectWork7)->color.c1) = greenChannel133;
            (((FclObject *)objectWork)->color.c1) = greenChannel133;
            blue2 = (MEMBER(u8, work + ((index6) * 4), FclShopWork, savedColors[0].c2)); /* measured: typing each remaining site here changes 4964 code bytes. */
            channelStart10 = (f32) blue2;
            channelValue11 = fclEaseInterpolate(1, channelStart10, 145.0f, (f32) (shopWork->colorFrame), 3.0f);
            blueChannel134 = (u8) channelValue11;
            (((FclObject *)objectWork7)->color.c2) = blueChannel134;
            (((FclObject *)objectWork)->color.c2) = blueChannel134;
        }
        colorFrame3 = (((FclShopWork *)work)->colorFrame);
        if (colorFrame3 < 6) {
            (shopWork->colorFrame) = fclAddClamped((s32) colorFrame3, 1, 6, 0, 1);
        } else {
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer)))->color = ((FclShopWork *)work)->savedColors[0];
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer)))->color = ((FclShopWork *)work)->savedColors[1];
            position2 = ((FclObject *)fclObjectGetWork((shopWork->panels[0x65].pointer)))->anchorPosition;
            fclObjStartPosition((shopWork->panels[0x65].pointer), position2, fclMakeVec2(position2.x - 1000.0f, position2.y), 1, 3, 0);
            position4[1] = ((FclObject *)fclObjectGetWork((shopWork->panels[0x66].pointer)))->anchorPosition;
            fclObjStartPosition((shopWork->panels[0x66].pointer), position4[1], fclMakeVec2(position4[1].x - 1000.0f, position4[1].y), 1, 3, 0);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x86].pointer), 0x41, 109.0f);
            fclObjStartPosition((shopWork->panels[0x86].pointer), fclMakeVec2((f32) -0x271, 124.0f), fclMakeVec2(75.0f, 124.0f), 0, 4, 5);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x86].pointer)))->color = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x87].pointer), 0x41, 112.0f);
            fclObjStartPosition((shopWork->panels[0x87].pointer), fclMakeVec2((f32) -0x271, (f32) 0x11D), fclMakeVec2(75.0f, (f32) 0x11D), 0, 4, 5);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x87].pointer)))->color = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x88].pointer), 0x41, 113.0f);
            fclObjStartPosition((shopWork->panels[0x88].pointer), fclMakeVec2(-117.0f, 128.0f), fclMakeVec2((f32) 0x247, 128.0f), 0, 4, 5);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x89].pointer), 0x41, 114.0f);
            fclObjStartPosition((shopWork->panels[0x89].pointer), fclMakeVec2((f32) -0x2FD, 128.0f), fclMakeVec2(-65.0f, 128.0f), 0, 4, 5);
            ((FclShopWork *)work)->detailMode = 1;
            ((FclShopWork *)work)->state = 0x30;
        }
        break;
    case 0x30:                                      /* switch 1 */
        fclShopDrawBuyList(task, 2);
        if ((((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x65].pointer), 9))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x66].pointer), 9))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x86].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x87].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x88].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x89].pointer)))) == 0)) {
            for (index30 = 0; index30 < 3; index30++) {
                fclObjSetAnchorPosition((MEMBER(void *, work + ((index30) * 4), FclShopWork, panels[0x61].pointer)), 0x41, 95.0f); /* measured: typing each remaining site here changes 49 code bytes. */
                ((FclObject *)fclObjectGetWork((MEMBER(void *, work + ((index30) * 4), FclShopWork, panels[0x61].pointer))))->color = fclMakeDrawColor(0xFF, 0xEF, 0x80, 0xFF); /* measured: typing each remaining site here changes 49 code bytes. */
            }
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x61].pointer)))->anchorPosition = fclMakeVec2(89.0f, 163.0f);
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x62].pointer)))->anchorPosition = fclMakeVec2((f32) 0x1D1, 163.0f);
            ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x63].pointer)))->anchorPosition = fclMakeVec2((f32) 0x22E, 163.0f);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x1D].pointer), 0x56, 91.0f);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x1D].pointer)))->anchorPosition = fclMakeVec2((f32) 0x1DF, 167.0f);
            ((FclObject *)fclObjectGetWork((shopWork->panels[0x1D].pointer)))->color = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
            fclObjSetAnchorPosition((void *) (((FclShopWork *)work)->panels[0x93].word), 0x56, 91.0f);
            ((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x93].word)))->color = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
            ((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x93].word)))->anchorPosition = fclMakeVec2((f32) 0x1DF, 217.0f);
            if (yListCountFor(((&shopWork->lists[0])[(((FclShopWork *)work)->tab)])) >= 2) {
                fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x17].pointer), 0x41, 88.0f);
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x17].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x17].pointer)))->anchorPosition = fclMakeVec2((f32) 0x247, 136.0f);
                fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x18].pointer), 0x41, 89.0f);
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x18].pointer)))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                ((FclObject *)fclObjectGetWork((shopWork->panels[0x18].pointer)))->anchorPosition = fclMakeVec2((f32) 0x247, 272.0f);
            }
            ((FclShopWork *)work)->state = 0x31;
        }
        break;
    case 0x31:                                      /* switch 1 */
        fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x1A].pointer), 0, 1);
        fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x1C].pointer), 0, 1);
        fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x19].pointer), 0, 1);
        fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x1B].pointer), 0, 1);
        fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x20].pointer), 0, 1);
        fclObjChangeFlagBit((void *) (((FclShopWork *)work)->panels[0x9D].word), 0, 1);
        fclShopDrawBuyList(task, 1);
        fclShopDrawScrollThumb(task);
        if ((((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x80].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x23].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x22].pointer), 1))) == 0) && ((D_008C0276[0] & 0x80) || (D_008C0276[0] & 0x20))) {
            sdkSndStartStream(0, 1, 0, 4);
            fclShopHideSelectionSprites(task);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6B].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6A].pointer), 0, 1);
            position3 = ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x65].pointer)))->anchorPosition;
            tbl = (f32 *) D_0063F888;
            fclObjStartPosition((shopWork->panels[0x65].pointer), fclMakeVec2(700.0f + tbl[0], position3.y), fclMakeVec2(tbl[0], position3.y), 1, 3, 2);
            position4[0] = ((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x66].pointer)))->anchorPosition;
            tbl = (f32 *) D_0063F890;
            fclObjStartPosition((shopWork->panels[0x66].pointer), fclMakeVec2(700.0f + tbl[0], position4[0].y), fclMakeVec2(tbl[0], position4[0].y), 1, 3, 2);
            ((FclShopWork *)work)->state = 0x24;
        }
        break;
    case 0x32:                                      /* switch 1 */
        ((FclShopWork *)work)->state = 0x24;
        break;
    case 0x33:                                      /* switch 1 */
        if (yListCountFor(((&shopWork->lists[0])[(((FclShopWork *)work)->tab)])) > 5) {
            if (yListCountFor(((&shopWork->lists[0])[tabIndex4 = (shopWork->tab)])) > D_00748908[tabIndex4]) {
                if (yListCountFor(((&shopWork->lists[0])[tabIndex4])) > 5) {
                    ((FclShopWork *)work)->scrollStep = (f32) (104.0f / (f32) (yListCountFor(((&shopWork->lists[0])[(shopWork->tab)])) - 5));
                }
                fclDrawEquipSprite(0x36, fclMakeVec2((f32) 0x221,  142.0f + ((FclShopWork *)work)->scrollStep * (f32) ((((FclShopWork *)work)->cursor) - (((FclShopWork *)work)->scroll))), 138.0f, fclPackRgba(0xFFU, 0xFEU, 0xC6U, 0x31U), (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x15].pointer)))->alpha), 0, D_00794EA0);
            }
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 0);
        } else {
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 1);
        }
        fclShopDrawItemRows(task, (shopWork->previousTabSigned), 80.0f, (f32) 0x352);
        fclShopDrawItemRows(task, (s8) (s32) (shopWork->tab), (f32) -0x352, 80.0f);
        slideFramesRemaining = fclSubClamped((s32) (((FclShopWork *)work)->slideTimer), 1, 0, 0, 1);
        (shopWork->slideTimer) = slideFramesRemaining;
        if (((s16) ((s64) slideFramesRemaining)) == 0) {
            ((FclShopWork *)work)->state = 0x24;
        }
        break;
    case 0x34:                                      /* switch 1 */
        if (yListCountFor(((&shopWork->lists[0])[(((FclShopWork *)work)->tab)])) > 5) {
            if (yListCountFor(((&shopWork->lists[0])[tabIndex5 = (shopWork->tab)])) > D_00748908[tabIndex5]) {
                if (yListCountFor(((&shopWork->lists[0])[tabIndex5])) > 5) {
                    ((FclShopWork *)work)->scrollStep = (f32) (104.0f / (f32) (yListCountFor(((&shopWork->lists[0])[(shopWork->tab)])) - 5));
                }
                fclDrawEquipSprite(0x36, fclMakeVec2((f32) 0x221,  142.0f + ((FclShopWork *)work)->scrollStep * (f32) ((((FclShopWork *)work)->cursor) - (((FclShopWork *)work)->scroll))), 138.0f, fclPackRgba(0xFFU, 0xFEU, 0xC6U, 0x31U), (((FclObject *)fclObjectGetWork((((FclShopWork *)work)->panels[0x15].pointer)))->alpha), 0, D_00794EA0);
            }
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 0);
        } else {
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x15].pointer), 0, 1);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x16].pointer), 0, 1);
        }
        fclShopDrawItemRows(task, (shopWork->previousTabSigned), 80.0f, (f32) -0x352);
        fclShopDrawItemRows(task, (s8) (s32) (shopWork->tab), (f32) 0x352, 80.0f);
        reverseSlideFramesRemaining = fclSubClamped((s32) (((FclShopWork *)work)->slideTimer), 1, 0, 0, 1);
        (shopWork->slideTimer) = reverseSlideFramesRemaining;
        if (((s16) ((s64) reverseSlideFramesRemaining)) == 0) {
            ((FclShopWork *)work)->state = 0x24;
        }
        break;
    case 0x35:                                      /* switch 1 */
        if (kwlnTaskGetTaskByName(D_0063FB10) == 0) {
            for (index31 = 0; index31 < 7; index31++) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[(index31) + 0x3A].pointer), 0, 0);
            }
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x3].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x4].pointer), 0, 0);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6D].pointer), 0, 0);
            for (index32 = 0; index32 < 3; index32++) {
                fclObjStartAlpha((((FclShopWork *)work)->panels[(index32)].pointer), 0U, 0xFFU, 0U, 0xA, 0);
            }
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x55].pointer), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x56].pointer), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjStartAlpha((((FclShopWork *)work)->panels[0x57].pointer), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x5].pointer), 0x40, 191.0f);
            sprite11 = sdkSpriteNewNode((u32)((void *) (((FclShopWork *)work)->spriteResource.signedWord)), (u32)(5));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite11))));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x5].pointer)))->pivotY) = (s16) ((s16) ((sdkSpriteScaledHeight(sprite11))));
            sdkSpriteFreeNode(sprite11);
            fclObjStartAlpha((shopWork->panels[0x5].pointer), 0U, 0xCCU, 0U, 4, 4);
            fclObjStartTween((shopWork->panels[0x5].pointer), 0.0f, fGpffff8520, 0, 4, 4);
            fclObjStartPosition((shopWork->panels[0x5].pointer), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
            fclObjSetAnchorPosition((((FclShopWork *)work)->panels[0x6].pointer), 0x40, 192.0f);
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.x) = 110.0f;
            (((FclObject *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->anchorPosition.y) = -50.0f;
            sprite12 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite12))));
            (((FclShopItemPanel *)fclObjectGetWork((shopWork->panels[0x6].pointer)))->pivotY) = 0;
            fclObjStartTween((shopWork->panels[0x6].pointer), -90.0f, fGpffff8524, 0, 4, 4);
            fclObjStartAlpha((shopWork->panels[0x6].pointer), 0U, 0xFFU, 0U, 4, 4);
            sdkSpriteFreeNode(sprite12);
            fclObjSetAnchorPosition((void *) (((FclShopWork *)work)->panels[0x91].word), 0x40, 190.0f);
            (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.x) = 180.0f;
            (((FclObject *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->anchorPosition.y) = 30.0f;
            sprite13 = sdkSpriteNewNode((u32)((void *) (shopWork->spriteResource.signedWord)), (u32)(6));
            (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotX) = (s16) ((s16) ((sdkSpriteScaledWidth(sprite13))));
            (((FclShopItemPanel *)fclObjectGetWork((void *) (shopWork->panels[0x91].word)))->pivotY) = 0;
            sdkSpriteFreeNode(sprite13);
            fclObjStartTween((void *) (shopWork->panels[0x91].word), -85.0f, fGpffff8528, 0, 4, 2);
            fclObjStartAlpha((void *) (shopWork->panels[0x91].word), 0U, 0xFFU, 0U, 4, 2);
            for (index3 = 0; index3 < 7; index3++) {
                positionTable3 = (f32 *)(D_0063F560 + ((index3 + 0x3A) * 8));
                fclObjSetAnchorPosition((MEMBER(void *, work + (index3 * 4), FclShopWork, panels[0x3A].pointer)), 0x56, (f32) (index3 + 0x64)); /* measured: typing each remaining site here changes 67 code bytes. */
                if (index3 > 0) {
                    ((FclObject *)fclObjectGetWork((MEMBER(void *, work + (index3 * 4), FclShopWork, panels[0x3A].pointer))))->color = fclMakeDrawColor(0xED, 0x80, 0, 0xFF); /* measured: typing each remaining site here changes 62 code bytes. */
                }
                fclObjStartPosition((MEMBER(void *, work + ((index3) * 4), FclShopWork, panels[0x3A].pointer)), fclMakeVec2(80.0f + positionTable3[0], positionTable3[1]), fclMakeVec2(positionTable3[0], positionTable3[1]), 0, 3, index3); /* measured: typing each remaining site here changes 866 code bytes. */
                fclObjStartAlpha((MEMBER(void *, work + ((index3) * 4), FclShopWork, panels[0x3A].pointer)), 0U, 0xFFU, 0U, 3, index3); /* measured: typing each remaining site here changes 868 code bytes. */
            }
            ((FclObject *)fclObjectGetWork(((&shopWork->panels[0x3B].pointer)[(((FclShopWork *)work)->category)])))->color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclObjStartAlpha((shopWork->panels[0x3].pointer), 0U, 0xFFU, 0U, 0, (s64) (shopWork->category));
            fclObjStartAlpha((shopWork->panels[0x4].pointer), 0U, 0xFFU, 0U, 0, (s64) (shopWork->category));
            fclShopStartSelectionShake(task);
            fclShopLayoutPanels(task);
            fclObjChangeFlagBit((((FclShopWork *)work)->panels[0x6C].pointer), 0, 0);
            fclObjChangeFlagBit((shopWork->panels[0x6D].pointer), 0, 0);
            ((FclShopWork *)work)->state = 0x36;
        }
        break;
    case 0x36:                                      /* switch 1 */
        for (index33 = 0x55; index33 < 0x58; index33++) {
            if (((s8) (fclObjTestFlagBit(((&((FclShopWork *)work)->panels[0x0])[index33].pointer), 1))) == 0) {
                fclObjChangeFlagBit(((&((FclShopWork *)work)->panels[0x0])[index33].pointer), 3, 0);
            }
        }
        for (index34 = 0x59; index34 < 0x60; index34++) {
            if (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[index34].pointer), 1))) == 0) {
                fclObjChangeFlagBit((((FclShopWork *)work)->panels[index34].pointer), 3, 0);
            }
        }
        if ((((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x55].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x56].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x57].pointer), 1))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x5].pointer), 2))) == 0) && (((s8) (fclObjTestFlagBit((((FclShopWork *)work)->panels[0x6].pointer), 2))) == 0)) {
            ((FclShopWork *)work)->state = 0x10;
        }
        break;
    case 0x37:                                      /* switch 1 */
        if ((((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x5].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x6].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((void *) (((FclShopWork *)work)->panels[0x91].word)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x0].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x1].pointer)))) == 0) && (((s8) (fclObjHasStatusFlags((((FclShopWork *)work)->panels[0x2].pointer)))) == 0)) {
            return -1;
        }
        break;
    }
    return 0;
}

// Clamp HP/SP for the listed units, release the shop resources and list, then free the shop work.
// FUN_002CA770
void fclShopDrawDestroy(u8 *task) {
    struct KwlnTask *shopTask = (struct KwlnTask *)task;
    s16 i;
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;

    /* measured: access-site unitIds indexing matches; native work->unitIds[i] had commuted two addu words. */
    for (i = 0; i < work->unitCount; i++) {
        datClampUnitHpSp(((FclShopWork *)work)->unitIds[(i)]);
    }
    if (work->spriteResource.pointer) {
        sdkSpriteRelease(work->spriteResource.pointer);
        work->spriteResource.pointer = (void *)(0);
    }
    if (work->loadedFile) {
        H_Cdvd_Destroy(work->loadedFile);
    }
    yListDestroy();
    /* Reload the task work after releasing its resource and list children. */
    jtbl_008873EC[0](shopTask->work);
}

// Creates the shop draw task under arg0: allocates the work block, creates the four value sprites and three list children, and clears the sprite and state fields.
// FUN_002CA830
s32 fclShopDrawCreate(s32 parent) {
    FclVec2 position;
    FclVec2 position2;
    FclVec2 position3;
    FclVec2 position4;
    s32 childTask;
    FclShopWork *workBlock;

    chkmemAllocSiteTag(&D_0063FAC0, 0xC47);
    workBlock = D_008873F4[0](1, 0x1174, 0x40000);
    childTask = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)((char *)&D_0063FB30), 0xF, 0, 0, fclShopStateUpdate, fclShopDrawDestroy, (u8 *)(workBlock));
    workBlock->state = 9;
    position = fclMakeVec2(240.0f, 20.0f);
    workBlock->valuePanels[0] = (void *)fclSpriteSpawnChild(childTask, position);
    workBlock->detailMode = 0;
    position2 = fclMakeVec2(50.0f, 30.0f);
    workBlock->valuePanels[1] = (void *)fclSpriteSpawnChild(childTask, position2);
    position3 = fclMakeVec2(50.0f, 30.0f);
    workBlock->valuePanels[2] = (void *)fclSpriteSpawnChild(childTask, position3);
    position4 = fclMakeVec2(50.0f, 30.0f);
    workBlock->valuePanels[3] = (void *)fclSpriteSpawnChild(childTask, position4);
    workBlock->spriteResource.word = 0;
    workBlock->ready = 0;
    workBlock->lists[0] = yListCreateChild((void *)childTask, 0x40000, 0, 4, 0);
    workBlock->lists[1] = yListCreateChild((void *)childTask, 0xFFFF, 0x1FE0, 1, 0);
    workBlock->lists[2] = yListCreateChild((void *)childTask, 0x10000, 0, 1, 0);
    return childTask;
}

// Sets the shop draw work's mode byte (the first byte of the work block) to arg1.
// FUN_002CAA00
void fclShopDrawSetMode(void *task, s8 state) {
    ((FclShopWork *)((struct KwlnTask *)task)->work)->state = state;
}

/* Measured: 696/704 bytes, fourteen resolved relocations, eight zero
   alignment bytes. Separate glyph acquisition/release scopes preserve
   the saved-register allocation and callback order. */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
/* Draw a right-aligned sprite number with a comma every three digits, measuring the two glyph widths from the resource. */
// FUN_002CAA10
void fclShopDrawNumber(Vec2f position, f32 depth, RGBA color, u32 inputNumber, s16 glyphBase, void *spriteResource, s32 style)
{
    char text[16];
    f32 x;
    u32 number;
    s32 digitWidth;
    void *sprite;
    s32 count;
    s16 commaWidth;
    u8 *renderLayer;
    s32 baseGlyph;
    u8 alpha;
    u8 blue;
    u8 green;
    f32 y;
    s32 comma;

    sprite = spriteResource;
    number = inputNumber;
    count = 0;
    x = position.x;
    {
        void *glyph;
        s32 measuredBase;
        measuredBase = (s16)glyphBase;
        glyph = sdkSpriteNewNode((u32)(sprite), (u32)(measuredBase));
        digitWidth = (s16)(s32)(sdkSpriteScaledWidth(glyph) - 1.0f);
        sdkSpriteFreeNode(glyph);
        comma = measuredBase + 10;
    }
    {
        void *commaGlyph;
        commaGlyph = sdkSpriteNewNode((u32)(sprite), (u32)(comma));
        commaWidth = (s16)(s32)(sdkSpriteScaledWidth(commaGlyph) - 1.0f);
        sdkSpriteFreeNode(commaGlyph);
    }
    strcpy(text, iGpffffa884);
    renderLayer = D_00793E80 + style * 0x30;
    baseGlyph = (s16)glyphBase;
    alpha = color.a;
    blue = color.b;
    green = color.g;
    y = position.y;
    do {
        sdkSpriteDrawQueuedUnscaled(x, y, depth, fclPackRgba(0xFF, color.r, green, blue), alpha, baseGlyph + number % 10, sprite, 1, renderLayer);
        number /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (number != 0) {
                x -= (f32)commaWidth;
                sdkSpriteDrawQueuedUnscaled(x, y, depth, fclPackRgba(0xFF, color.r, green, blue), alpha, comma, sprite, 1, renderLayer);
                x -= (f32)digitWidth;
            } else {
                x -= (f32)digitWidth;
            }
        } else {
            x -= (f32)digitWidth;
        }
    } while (number != 0);
}
#pragma pop

/* measured: object 536B/window 544B, nd 0. Signature (u64, f32, RGBA, s32, s16, u32,
   s32, s32, s32, s32, s32): fparg0 second so it homes to $f22 right after $a0; RGBA
   by value so the colour bytes are lbu from the $a1 home slot; arg5/arg6 are s32
   (dsll32 in place). Stack layout is first-use order high-to-low: 16-byte memset
   target 0xD0, arg1 0xCC, arg0 0xC0, arg3 0xBE, arg7 0xB8. Byte colour locals
   agree with the packer and wrapper contracts. `arg4 = arg4_` before `count = 0`
   so $t0 homes last, comma local declared last for $s7, count s32 with (s8) cast,
   the three `x -= arg2` branches spelled out. */
/* Draw a right-aligned number with caller-supplied digit/comma spacing, separate glyph resources and a render-layer index. */
// FUN_002CACD0
void fclDrawNumber(Vec2f position, f32 depth, FclDrawColor color, s32 digitWidth, s16 commaWidth, u32 inputNumber, s32 digitGlyph, s32 commaGlyph, s32 digitResource, s32 commaResource, s32 style)
{
    u8 textBuffer[16];
    u32 number;
    s32 count;
    u8 *renderLayer;
    f32 x;
    f32 y;
    s32 baseGlyph;
    u8 alpha;
    u8 blue;
    u8 green;
    s32 comma;

    number = inputNumber;
    count = 0;
    x = position.x;
    memset(textBuffer, 0, 1);
    renderLayer = D_00793E80 + style * 0x30;
    baseGlyph = (s16)digitGlyph;
    alpha = color.c3;
    blue = color.c2;
    green = color.c1;
    y = position.y;
    comma = (s16)commaGlyph;
    do {
        sdkSpriteDrawQueuedUnscaled(x, y, depth, fclPackRgba(0xFF, color.c0, green, blue), alpha, baseGlyph + number % 10, (void *)(u32)digitResource, 1, renderLayer);
        number /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (number != 0) {
                x -= (f32)commaWidth;
                sdkSpriteDrawQueuedUnscaled(x, y, depth, fclPackRgba(0xFF, color.c0, green, blue), alpha, comma, (void *)(u32)commaResource, 1, renderLayer);
                x -= (f32)digitWidth;
            } else {
                x -= (f32)digitWidth;
            }
        } else {
            x -= (f32)digitWidth;
        }
    } while (number != 0);
}
/* Swap the detail-panel groups with paired horizontal exit and entrance animations. */
// FUN_002CAEF0
void fclShopSlideInFromLeft(void *task) {
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    Vec2f position20;
    Vec2f position21;
    Vec2f position22;
    Vec2f position23;
    Vec2f position24;
    Vec2f position25;
    Vec2f position26;
    Vec2f position27;
    Vec2f position28;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    FclShopWork *work;
    u8 *objectWork;
    Vec2f *basePosition;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    basePosition = (Vec2f *)D_0063F5B0;
    fclObjSetAnchorAlphaFull(work->panels[0xAD].pointer, 0x41, 109.0f);
    position = fclMakeVec2(basePosition->x, basePosition->y);
    position2 = fclMakeVec2(basePosition->x - 750.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xAD].pointer, position, position2, 0, 4, 0);
    ((FclObject *)fclObjectGetWork(work->panels[0xAD].pointer))->alpha = 0xCC;
    c0 = fclMakeDrawColor(0, 0, 0, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0xAD].pointer);
    ((FclObject *)objectWork)->color = c0;

    basePosition = (Vec2f *)D_0063F5F0;
    fclObjSetAnchorAlphaFull(work->panels[0xAF].pointer, 0x41, 109.0f);
    position3 = fclMakeVec2(basePosition->x, basePosition->y);
    position4 = fclMakeVec2(basePosition->x - 750.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xAF].pointer, position3, position4, 0, 4, 0);
    ((FclObject *)fclObjectGetWork(work->panels[0xAF].pointer))->alpha = 0xCC;
    c1 = fclMakeDrawColor(0, 0, 0, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0xAF].pointer);
    ((FclObject *)objectWork)->color = c1;

    basePosition = (Vec2f *)D_0063F5D0;
    fclObjSetAnchorAlphaFull(work->panels[0xB0].pointer, 0x41, 111.0f);
    position5 = fclMakeVec2(basePosition->x, basePosition->y);
    position6 = fclMakeVec2(basePosition->x - 750.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xB0].pointer, position5, position6, 0, 4, 0);
    ((FclObject *)fclObjectGetWork(work->panels[0xB0].pointer))->alpha = 0xCC;
    c2 = fclMakeDrawColor(0, 0, 0, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0xB0].pointer);
    ((FclObject *)objectWork)->color = c2;

    fclObjSetAnchorAlphaFull(work->panels[0xAE].pointer, 0x41, 109.0f);
    position7 = fclMakeVec2(86.0f, 242.0f);
    position8 = fclMakeVec2(786.0f, 242.0f);
    fclObjStartPosition(work->panels[0xAE].pointer, position7, position8, 0, 4, 0);
    c3 = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0xAE].pointer);
    ((FclObject *)objectWork)->color = c3;

    basePosition = (Vec2f *)D_0063F5F8;
    fclObjSetAnchorAlphaFull(work->panels[0xB1].pointer, 0x41, 112.0f);
    position9 = fclMakeVec2(basePosition->x, basePosition->y);
    position10 = fclMakeVec2(basePosition->x + 700.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xB1].pointer, position9, position10, 0, 4, 0);
    c4 = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0xB1].pointer);
    ((FclObject *)objectWork)->color = c4;

    basePosition = (Vec2f *)D_0063F5D8;
    fclObjSetAnchorAlphaFull(work->panels[0xB2].pointer, 0x41, 113.0f);
    position11 = fclMakeVec2(basePosition->x, basePosition->y);
    position12 = fclMakeVec2(basePosition->x + 700.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xB2].pointer, position11, position12, 0, 4, 0);

    basePosition = (Vec2f *)D_0063F5E0;
    fclObjSetAnchorAlphaFull(work->panels[0xB3].pointer, 0x41, 114.0f);
    position13 = fclMakeVec2(basePosition->x, basePosition->y);
    position14 = fclMakeVec2(basePosition->x + 700.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xB3].pointer, position13, position14, 0, 4, 0);

    basePosition = (Vec2f *)D_0063F5B0;
    position15 = fclMakeVec2(basePosition->x + 660.0f, basePosition->y);
    position16 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0xA].pointer, position15, position16, 0, 4, 6);
    basePosition = (Vec2f *)D_0063F5F0;
    position17 = fclMakeVec2(basePosition->x + 660.0f, basePosition->y);
    position18 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x12].pointer, position17, position18, 0, 4, 6);
    basePosition = (Vec2f *)D_0063F5D0;
    position19 = fclMakeVec2(basePosition->x + 660.0f, basePosition->y);
    position20 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0xE].pointer, position19, position20, 0, 4, 6);
    position21 = fclMakeVec2(-614.0f, 242.0f);
    position22 = fclMakeVec2(86.0f, 242.0f);
    fclObjStartPosition(work->panels[0x92].pointer, position21, position22, 0, 4, 6);
    basePosition = (Vec2f *)D_0063F5F8;
    position23 = fclMakeVec2(basePosition->x - 700.0f, basePosition->y);
    position24 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x13].pointer, position23, position24, 0, 4, 6);
    basePosition = (Vec2f *)D_0063F5D8;
    position25 = fclMakeVec2(basePosition->x - 700.0f, basePosition->y);
    position26 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0xF].pointer, position25, position26, 0, 4, 6);
    basePosition = (Vec2f *)D_0063F5E0;
    position27 = fclMakeVec2(basePosition->x - 700.0f, basePosition->y);
    position28 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x10].pointer, position27, position28, 0, 4, 6);
}

// Returns 1 when the shop draw work's state byte (+0xF30) is 1, meaning the shop draw is ready.
// FUN_002CB6A0
s32 fclShopDrawIsReady(void *task) {
    return ((FclShopWork *)((struct KwlnTask *)task)->work)->ready == 1;
}

/* MATCHED func_002cb6c0: a ShopMenuWork overlay (object pointers, sel/count,
   the kind/icon/timer tables) makes `kind[sel]` index as retail's idx+work;
   FclDrawColor results stored whole and passed by value (func_002e0970 takes
   two colours); func_002e2740/func_002e26a0 return int (re-narrowed with (s16)
   where retail re-extends), yListStepIndex takes its real s16 arguments;
   (u8)clndGetMoonPhase(..) & 1 keeps both masks; pad and D_0063FA40..46
   globals as arrays (absolute lui addressing, not $gp); the D60 pair stored as
   `field_100 = field_102 = 0` (retail's dsll32 of $zero); scoped
   opt_loop_invariants on for the row loop and the table-reset loop. */
/* Six spin-parameter tables (D_0063FA48..68, 8 bytes each) shared by the
   shop panel intro setups. */
typedef struct {
    f32 angle;
    s16 speed;
    s16 frames;
} ShopSpinParam;

#pragma push
#pragma opt_loop_invariants on
/* Draw the five-row purchase list; drawOnly suppresses its navigation, confirmation and comparison input handling. */
// FUN_002CB6C0
void fclShopDrawItemList(void *task, s8 drawOnly) {
    s32 sdkSndStartStream(s16, s16, s16, s16);
    FclDrawColor rowColor;
    FclDrawColor glow0a;
    FclDrawColor glow0b;
    FclDrawColor glow1a;
    FclDrawColor glow1b;
    FclDrawColor color;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    FclDrawColor color9;
    FclDrawColor color10;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    Vec2f position20;
    Vec2f position21;
    Vec2f position22;
    Vec2f position23;
    Vec2f position24;
    Vec2f position25;
    Vec2f position26;
    Vec2f position27;
    Vec2f position28;
    Vec2f position29;
    Vec2f position30;
    Vec2f position31;
    Vec2f position32;
    Vec2f position33;
    Vec2f position34;
    Vec2f pos;
    FclShopWork *work;
    u8 *objectWork;
    Vec2f *basePosition;
    ShopSpinParam *spinParameters;
    s16 start;
    s16 itemIndex;
    s16 row;
    s16 i;
    s32 rowY;
    s32 textColor;
    s32 iconColor;
    s32 icon;
    u32 price;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    if (yListCount() > 5) {
        if (yListCount() > 5) {
            work->scrollStep = 104.0f / (f32)(yListCount() - 5);
        }
        position = fclMakeVec2((f32)0x221, 142.0f + work->scrollStep * (f32)(work->cursor - work->scroll));
        fclDrawEquipSprite(0x36, position, 138.0f, fclPackRgba(0xFF, 0xFE, 0xC6, 0x31), ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha, 0, D_00794EA0);
        fclObjChangeFlagBit(work->panels[0x15].pointer, 0, 0);
        fclObjChangeFlagBit(work->panels[0x16].pointer, 0, 0);
    } else {
        fclObjChangeFlagBit(work->panels[0x15].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x16].pointer, 0, 1);
    }
    position2 = fclMakeVec2(51.0f, 48.0f);
    fclShopDrawItemText(task, work->unitIds[work->unitSelection], position2, (void *)fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
    if (fclObjTestFlagBit(work->panels[0x64].pointer, 1) == 0) {
        u8 alpha;

        basePosition = (Vec2f *)D_0063F880;
        fclObjSetAnchorPosition(work->panels[0x64].pointer, 0x41, 124.0f);
        alpha = ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha;
        ((FclObject *)fclObjectGetWork(work->panels[0x64].pointer))->alpha = alpha;
        ((FclObject *)fclObjectGetWork(work->panels[0x64].pointer))->anchorPosition.y = basePosition->y + (f32)(work->scroll << 5);
    }
    if (fclObjTestFlagBit(work->panels[0x66].pointer, 1) == 0) {
        u8 alpha;

        basePosition = (Vec2f *)D_0063F890;
        fclObjSetAnchorPosition(work->panels[0x66].pointer, 0x41, 125.0f);
        alpha = ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha;
        ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->alpha = alpha;
        ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->anchorPosition.y = basePosition->y + (f32)(work->scroll << 5);
    }
    switch (work->category) {
    case 0:
        icon = work->unitIcons[work->unitSelection] & 0xFFFF;
        break;
    case 1:
    case 2:
        icon = (work->category + 0x1A) & 0xFFFF;
        break;
    }
    if (yListKind() != 0) {
        return;
    }
    start = work->cursor - work->scroll;
    for (itemIndex = start, row = 0; itemIndex < start + 5; itemIndex++, row++) {
        if (itemIndex < yListCount()) {
            textColor = fclPackRgba(0xFF, 0xAE, 0, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
            iconColor = fclPackRgba(0, 0xFF, 0xAE, 0);
            rowColor = fclMakeDrawColor(0xFF, 0xAE, 0, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
            price = datItemPrice((s16)yListValueAt(itemIndex));
            if (price > fclGetMoney() || (datItemCount((s16)yListValueAt(itemIndex)) & 0xFF) == 0x63) {
                textColor = fclPackRgba(0xA6, 0x7F, 0x2B, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                iconColor = fclPackRgba(0, 0xA6, 0x7F, 0x2B);
                rowColor = fclMakeDrawColor(0xA6, 0x7F, 0x2B, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                if ((u8)clndGetMoonPhase(yListValueAt(itemIndex)) & 1) {
                    textColor = fclPackRgba(0xA8, 0x9C, 0x4C, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                    iconColor = fclPackRgba(0, 0xA8, 0x9C, 0x4C);
                    rowColor = fclMakeDrawColor(0xA8, 0x9C, 0x4C, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                }
                if (itemIndex == work->cursor) {
                    textColor = fclPackRgba(0x9E, 0x73, 0x1D, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                    iconColor = fclPackRgba(0, 0x9E, 0x73, 0x1D);
                    rowColor = fclMakeDrawColor(0x9E, 0x73, 0x1D, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                }
            } else if (itemIndex == work->cursor) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                rowColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
            } else if ((u8)clndGetMoonPhase(yListValueAt(itemIndex)) & 1) {
                textColor = fclPackRgba(0xFF, 0xEF, 0x81, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                iconColor = fclPackRgba(0, 0xFF, 0xEF, 0x81);
                rowColor = fclMakeDrawColor(0xFF, 0xEF, 0x81, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
            }
            if ((u8)clndGetMoonPhase(yListValueAt(itemIndex)) & 1) {
                position3 = fclMakeVec2(91.0f, (f32)((row << 5) + 0x7A));
                fclDrawResourceSprite(0x49, position3, 65.0f, fclPackRgba(0, 0xFF, 0x66, 0), ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha, 0, D_00794EA0);
            }
            rowY = row << 5;
            position4 = fclMakeVec2(146.0f, (f32)(rowY + 0x85));
            fclDrawEquipSprite(icon, position4, 69.0f, iconColor, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha, 0, D_00795E60);
            position5 = fclMakeVec2(189.0f, 132.0f + (f32)rowY);
            pos = *(Vec2f *)&position5;
            frFontExDrawTextDeferredWithCharWidth(pos.x, pos.y, 70.0f, textColor, 0, 1, ((void *)datGetItemNameId((s16)yListValueAt(itemIndex))), 0, 0, D_00795E30, -1);
            position6 = fclMakeVec2(498.0f, 142.0f + (f32)rowY);
            fclDrawNumber(position6, 70.0f, rowColor, 0x10, 5, datItemPrice((s16)yListValueAt(itemIndex)), 9, 0x7B,
                          (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->spriteResource.pointer, 0xA9);
        }
    }
    if (drawOnly == 1) {
        return;
    }
    if ((D_008C0276[0] & 0x1000) && work->inputBusy == 0) {
        sdkSndStartStream(0, 0, 0, 0);
        if (work->cursor == 0) {
            work->cursor = yListLastIndex();
            work->scroll = fclAddClamped(0, work->cursor, 4, 0, 1);
        } else {
            work->cursor = fclSubClamped(work->cursor, 1, 0, yListCount(), 2);
            work->scroll = yListStepIndex(work->cursor, work->scroll, yListCount(), 5, -1);
        }
        work->inputBusy = 1;
        return;
    }
    if (D_008C027A[0] & 0x1000) {
        if (yListCount() > 0) {
            if (work->cursor != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            work->cursor = fclSubClamped(work->cursor, 1, 0, 0, 1);
            work->scroll = yListStepIndex(work->cursor, work->scroll, yListCount(), 5, -1);
            work->inputBusy = 1;
            return;
        }
    } else if ((D_008C0276[0] & 0x4000) && work->inputBusy == 0) {
        sdkSndStartStream(0, 0, 0, 0);
        work->cursor = fclAddClamped(work->cursor, 1, yListLastIndex(), 0, 2);
        if (work->cursor == 0) {
            work->scroll = 0;
        } else if (yListLastIndex() >= 5) {
            work->scroll = yListStepIndex(work->cursor, work->scroll, yListLastIndex(), 5, 1);
        } else {
            work->scroll = yListStepIndex(work->cursor, work->scroll, yListLastIndex(), yListCount(), 1);
        }
        work->inputBusy = 1;
        return;
    } else if (D_008C027A[0] & 0x4000) {
        if (yListCount() > 0) {
            if (work->cursor != yListLastIndex()) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            work->cursor = fclAddClamped(work->cursor, 1, yListLastIndex(), 0, 1);
            if (yListLastIndex() >= 5) {
                work->scroll = yListStepIndex(work->cursor, work->scroll, yListLastIndex(), 5, 1);
            } else {
                work->scroll = yListStepIndex(work->cursor, work->scroll, yListLastIndex(), yListCount(), 1);
            }
            work->inputBusy = 1;
            return;
        }
    } else if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
        if (work->cursor != yListLastIndex()) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        yListAdvanceCursorScroll(work->cursor, work->scroll, yListCount(), 5, &work->cursor, &work->scroll);
    } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
        if (work->cursor != 0) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        yListRetreatCursorScroll(work->cursor, work->scroll, yListCount(), 5, &work->cursor, &work->scroll);
    } else if (D_008C027A[0] & 8) {
        sdkSndStartStream(0, 0, 0, 5);
        work->cursor = 0;
        work->scroll = 0;
        work->unitSelection = fclAddClamped(work->unitSelection, 1, work->unitCount - 1, 0, 2);
        switch (work->category) {
        case 0:
            yListRebuild(1 << (s16)(work->unitIcons[work->unitSelection] - 0x14),
                          1 << (work->unitIds[work->unitSelection] + 4), 2, 2);
            break;
        case 1:
            yListRebuild(0x4000, 1 << (work->unitIds[work->unitSelection] + 4), 2, 2);
            break;
        case 2:
            yListRebuild(0x8000, 1 << (work->unitIds[work->unitSelection] + 4), 2, 2);
            break;
        }
        fclShopSlideIndicator(task, 0);
    } else if (D_008C027A[0] & 4) {
        sdkSndStartStream(0, 0, 0, 5);
        work->cursor = 0;
        work->scroll = 0;
        work->unitSelection = fclSubClamped(work->unitSelection, 1, 0, work->unitCount - 1, 2);
        switch (work->category) {
        case 0:
            yListRebuild(1 << (s16)(work->unitIcons[work->unitSelection] - 0x14),
                          1 << (work->unitIds[work->unitSelection] + 4), 2, 2);
            break;
        case 1:
            yListRebuild(0x4000, 1 << (work->unitIds[work->unitSelection] + 4), 2, 2);
            break;
        case 2:
            yListRebuild(0x8000, 1 << (work->unitIds[work->unitSelection] + 4), 2, 2);
            break;
        }
        fclShopSlideIndicator(task, 1);
    } else if (D_008C024E[0] & 0x40) {
        if (yListCount() > 0) {
            price = datItemPrice((s16)yListValueAt(work->cursor));
            if (price <= fclGetMoney() && (datItemCount((s16)yListValueAt(work->cursor)) & 0xFF) < 0x63) {
                sdkSndStartStream(0, 0, 0, 1);
                work->savedColors[0] = ((FclObject *)fclObjectGetWork(work->panels[0x64].pointer))->color;
                work->savedColors[1] = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color;
                work->colorFrame = 0;
                work->state = 0x1C;
            } else {
                sdkSndStartStream(0, 0, 0, 8);
            }
        } else {
            sdkSndStartStream(0, 0, 0, 8);
        }
    } else if (D_008C024E[0] & 0x80) {
        if (yListCount() > 0) {
            sdkSndStartStream(0, 1, 0, 3);
            glow0a = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
            glow0b = fclMakeDrawColor(0xFF, 0xE2, 0x91, 0xFF);
            fclObjStartColor(work->panels[0x64].pointer, glow0a, glow0b, 1, 4, 0);
            ((FclObject *)fclObjectGetWork(work->panels[0x64].pointer))->colorLoop = 1;
            glow1a = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
            glow1b = fclMakeDrawColor(0xFF, 0xE2, 0x91, 0xFF);
            fclObjStartColor(work->panels[0x66].pointer, glow1a, glow1b, 1, 4, 0);
            ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->colorLoop = 1;
            {
                void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x7D));

                ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7D].pointer))->pivotX = (s16)sdkSpriteScaledWidth(sprite);
                ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7D].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
                ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7E].pointer))->pivotX = 0;
                ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7E].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
                fclObjStartTween(work->panels[0x7D].pointer, 0.0f, -4.0f, 0, 2, 0);
                fclObjStartTween(work->panels[0x7E].pointer, 0.0f, -4.0f, 0, 2, 0);
                ((FclObject *)fclObjectGetWork(work->panels[0x7D].pointer))->tweenLoop = 0;
                ((FclObject *)fclObjectGetWork(work->panels[0x7E].pointer))->tweenLoop = 0;
                sdkSpriteFreeNode(sprite);
            }
            work->state = 0x20;
        }
    } else if (D_008C024E[0] & 0x20) {
        sdkSndStartStream(0, 0, 0, 2);
        fclObjStartTween(work->panels[0x4D].pointer, -14.0f, 110.0f, 0, 0xA, 0);
        fclObjStartAlpha(work->panels[0x7D].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x7D].pointer))->alpha, 0, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x7E].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x7E].pointer))->alpha, 0, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x4E].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x4E].pointer))->alpha, 0, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x51].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x51].pointer))->alpha, 0, 0, 5, 0);
        fclObjChangeFlagBit(work->panels[0x68].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x6C].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x6E].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x6B].pointer, 0, 1);
        fclObjStartAlpha(work->panels[0x15].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha, 0, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x16].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x16].pointer))->alpha, 0, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x64].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x64].pointer))->alpha, 0, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x66].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->alpha, 0, 0, 5, 0);
        basePosition = (Vec2f *)D_0063F5B8;
        position7 = fclMakeVec2(basePosition->x, basePosition->y);
        position8 = fclMakeVec2(basePosition->x, 300.0f + basePosition->y);
        fclObjStartPosition(work->panels[0xB].pointer, position7, position8, 0, 0xA, 0);
        fclObjStartAlpha(work->panels[0xB].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xB].pointer))->alpha, 0, 0, 0xA, 0);
        basePosition = (Vec2f *)D_0063F5A0;
        fclObjSetAnchorPosition(work->panels[0x8].pointer, 0x40, 162.0f);
        position9 = fclMakeVec2(basePosition->x, basePosition->y - 450.0f);
        position10 = fclMakeVec2(basePosition->x, basePosition->y);
        fclObjStartPosition(work->panels[0x8].pointer, position9, position10, 0, 4, 0);
        fclObjStartAlpha(work->panels[0x8].pointer, 0, 0xCC, 0, 2, 0);
        color = fclMakeDrawColor(0, 0, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x8].pointer);
        ((FclObject *)objectWork)->color = color;
        basePosition = (Vec2f *)D_0063F5A8;
        fclObjSetAnchorPosition(work->panels[0x9].pointer, 0x40, 163.0f);
        position11 = fclMakeVec2(basePosition->x, basePosition->y - 450.0f);
        position12 = fclMakeVec2(basePosition->x, basePosition->y);
        fclObjStartPosition(work->panels[0x9].pointer, position11, position12, 0, 4, 0);
        fclObjStartAlpha(work->panels[0x9].pointer, 0, 0xCC, 0, 2, 0);
        color2 = fclMakeDrawColor(0, 0, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9].pointer);
        ((FclObject *)objectWork)->color = color2;
        for (i = 0; i < work->unitCount; i++) {
            work->rowDelay[i] = 0;
            work->rowFrame[i] = 6;
            work->rowAlpha[i] = 0xFF;
        }
        fclObjChangeFlagBit(work->panels[0xA7].pointer, 0, 0);
        fclObjStartAlpha(work->panels[0xA7].pointer, 0, 0xFF, 0, 4, 0);
        position13 = fclMakeVec2(47.0f, 78.0f + 35.0f * (f32)work->unitSelection);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA7].pointer);
        ((FclObject *)objectWork)->anchorPosition = position13;
        fclObjChangeFlagBit(work->panels[0xA8].pointer, 0, 0);
        fclObjStartAlpha(work->panels[0xA8].pointer, 0, 0xFF, 0, 4, 0);
        position14 = fclMakeVec2(126.0f, 78.0f + 35.0f * (f32)work->unitSelection);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA8].pointer);
        ((FclObject *)objectWork)->anchorPosition = position14;
        fclShopDrawSwingCursor(task);
        fclObjSetAnchorPosition(work->panels[0x41].pointer, 0x41, 128.0f);
        fclObjStartAlpha(work->panels[0x41].pointer, 0, 0xFF, 0, 0xA, 0);
        basePosition = (Vec2f *)D_0063F7B0;
        fclObjSetAnchorPosition(work->panels[0x4A].pointer, 0x41, 78.0f);
        position15 = fclMakeVec2(basePosition->x, basePosition->y - (f32)0x226);
        position16 = fclMakeVec2(basePosition->x, basePosition->y);
        fclObjStartPosition(work->panels[0x4A].pointer, position15, position16, 2, 4, 0);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4A].pointer))->pivotX = ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4A].pointer))->pivotY = 0;
        fclObjStartTween(work->panels[0x4A].pointer, -5.0f, fGpffff852c, 2, 2, 2);
        color3 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x4A].pointer);
        ((FclObject *)objectWork)->color = color3;
        basePosition = (Vec2f *)D_0063F7B8;
        fclObjSetAnchorPosition(work->panels[0x4B].pointer, 0x41, 78.0f);
        position17 = fclMakeVec2(basePosition->x, basePosition->y - (f32)0x226);
        position18 = fclMakeVec2(basePosition->x, basePosition->y);
        fclObjStartPosition(work->panels[0x4B].pointer, position17, position18, 2, 4, 0);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4B].pointer))->pivotX = -0x32;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4B].pointer))->pivotY = -0xDB;
        fclObjStartTween(work->panels[0x4B].pointer, -5.0f, fGpffff852c, 2, 2, 2);
        basePosition = (Vec2f *)D_0063F8C0;
        fclObjSetAnchorPosition(work->panels[0x6C].pointer, 0x41, 46.0f);
        fclObjStartAlpha(work->panels[0x6C].pointer, 0, 0xFF, 0, 6, 0);
        ((FclObject *)fclObjectGetWork(work->panels[0x6C].pointer))->anchorPosition.x = basePosition->x;
        ((FclObject *)fclObjectGetWork(work->panels[0x6C].pointer))->anchorPosition.y = basePosition->y;
        fclObjSetAnchorPosition(work->panels[0x6E].pointer, 0x41, 47.0f);
        fclObjStartAlpha(work->panels[0x6E].pointer, 0, 0xFF, 0, 6, 0);
        ((FclObject *)fclObjectGetWork(work->panels[0x6E].pointer))->anchorPosition.x = 147.0f;
        ((FclObject *)fclObjectGetWork(work->panels[0x6E].pointer))->anchorPosition.y = 376.0f;
        {
            void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x44));

            basePosition = (Vec2f *)D_0063F780;
            fclObjSetAnchorPosition(work->panels[0x44].pointer, 0x56, 53.0f);
            position19 = fclMakeVec2(basePosition->x, -130.0f);
            position20 = fclMakeVec2(basePosition->x, basePosition->y);
            fclObjStartPosition(work->panels[0x44].pointer, position19, position20, 2, 5, 0);
            color4 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x44].pointer);
            ((FclObject *)objectWork)->color = color4;
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x44].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x44].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
            fclObjSetHoldTimer(work->panels[0x44].pointer, (f32)D_0063FA44[0], D_0063FA46[0]);
            fclObjStartTween(work->panels[0x44].pointer, D_0063FA40[0], 0.0f, 2, D_0063FA46[0] + 5, 0);
            sdkSpriteFreeNode(sprite);
        }
        {
            void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x43));

            basePosition = (Vec2f *)D_0063F778;
            spinParameters = (ShopSpinParam *)D_0063FA48;
            fclObjSetAnchorPosition(work->panels[0x43].pointer, 0x56, 54.0f);
            position21 = fclMakeVec2(basePosition->x, -189.0f);
            position22 = fclMakeVec2(basePosition->x, basePosition->y);
            fclObjStartPosition(work->panels[0x43].pointer, position21, position22, 2, 5, 3);
            color5 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x43].pointer);
            ((FclObject *)objectWork)->color = color5;
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x43].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x43].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
            fclObjSetHoldTimer(work->panels[0x43].pointer, (f32)spinParameters->speed, spinParameters->frames);
            fclObjStartTween(work->panels[0x43].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 3);
            sdkSpriteFreeNode(sprite);
        }
        {
            void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x45));

            basePosition = (Vec2f *)D_0063F788;
            spinParameters = (ShopSpinParam *)D_0063FA50;
            fclObjSetAnchorPosition(work->panels[0x45].pointer, 0x56, 55.0f);
            position23 = fclMakeVec2(basePosition->x, -75.0f);
            position24 = fclMakeVec2(basePosition->x, basePosition->y);
            fclObjStartPosition(work->panels[0x45].pointer, position23, position24, 2, 5, 1);
            color6 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x45].pointer);
            ((FclObject *)objectWork)->color = color6;
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x45].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x45].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
            fclObjSetHoldTimer(work->panels[0x45].pointer, (f32)spinParameters->speed, spinParameters->frames);
            fclObjStartTween(work->panels[0x45].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 1);
            sdkSpriteFreeNode(sprite);
        }
        {
            void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x46));

            basePosition = (Vec2f *)D_0063F790;
            spinParameters = (ShopSpinParam *)D_0063FA58;
            fclObjSetAnchorPosition(work->panels[0x46].pointer, 0x56, 56.0f);
            position25 = fclMakeVec2(basePosition->x, -165.0f);
            position26 = fclMakeVec2(basePosition->x, basePosition->y);
            fclObjStartPosition(work->panels[0x46].pointer, position25, position26, 2, 5, 4);
            color7 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x46].pointer);
            ((FclObject *)objectWork)->color = color7;
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x46].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x46].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
            ((FclObject *)fclObjectGetWork(work->panels[0x46].pointer))->tweenValue = 0.0f;
            fclObjSetHoldTimer(work->panels[0x46].pointer, (f32)spinParameters->speed, spinParameters->frames);
            fclObjStartTween(work->panels[0x46].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 4);
            sdkSpriteFreeNode(sprite);
        }
        {
            void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x47));

            basePosition = (Vec2f *)D_0063F798;
            spinParameters = (ShopSpinParam *)D_0063FA60;
            fclObjSetAnchorPosition(work->panels[0x47].pointer, 0x56, 57.0f);
            position27 = fclMakeVec2(basePosition->x, -126.0f);
            position28 = fclMakeVec2(basePosition->x, basePosition->y);
            fclObjStartPosition(work->panels[0x47].pointer, position27, position28, 2, 5, 2);
            color8 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x47].pointer);
            ((FclObject *)objectWork)->color = color8;
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x47].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x47].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
            ((FclObject *)fclObjectGetWork(work->panels[0x47].pointer))->tweenValue = 0.0f;
            fclObjSetHoldTimer(work->panels[0x47].pointer, (f32)spinParameters->speed, spinParameters->frames);
            fclObjStartTween(work->panels[0x47].pointer, spinParameters->angle, 0.0f, 1, spinParameters->frames + 5, 2);
            sdkSpriteFreeNode(sprite);
        }
        {
            void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x48));

            basePosition = (Vec2f *)D_0063F7A0;
            spinParameters = (ShopSpinParam *)D_0063FA68;
            fclObjSetAnchorPosition(work->panels[0x48].pointer, 0x56, 58.0f);
            position29 = fclMakeVec2(basePosition->x, -197.0f);
            position30 = fclMakeVec2(basePosition->x, basePosition->y);
            fclObjStartPosition(work->panels[0x48].pointer, position29, position30, 2, 5, 5);
            color9 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x48].pointer);
            ((FclObject *)objectWork)->color = color9;
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x48].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
            ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x48].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
            ((FclObject *)fclObjectGetWork(work->panels[0x48].pointer))->tweenValue = 0.0f;
            fclObjSetHoldTimer(work->panels[0x48].pointer, (f32)spinParameters->speed, spinParameters->frames);
            fclObjStartTween(work->panels[0x48].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 5);
            sdkSpriteFreeNode(sprite);
        }
        basePosition = (Vec2f *)D_0063F7B0;
        fclObjSetAnchorPosition(work->panels[0x4A].pointer, 0x41, 78.0f);
        position31 = fclMakeVec2(basePosition->x, basePosition->y - (f32)0x226);
        position32 = fclMakeVec2(basePosition->x, basePosition->y);
        fclObjStartPosition(work->panels[0x4A].pointer, position31, position32, 2, 4, 0);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4A].pointer))->pivotX = ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4A].pointer))->pivotY = 0;
        fclObjStartTween(work->panels[0x4A].pointer, -5.0f, fGpffff852c, 2, 2, 2);
        color10 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x4A].pointer);
        ((FclObject *)objectWork)->color = color10;
        basePosition = (Vec2f *)D_0063F7B8;
        fclObjSetAnchorPosition(work->panels[0x4B].pointer, 0x41, 78.0f);
        position33 = fclMakeVec2(basePosition->x, basePosition->y - (f32)0x226);
        position34 = fclMakeVec2(basePosition->x, basePosition->y);
        fclObjStartPosition(work->panels[0x4B].pointer, position33, position34, 2, 4, 0);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4B].pointer))->pivotX = -0x32;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4B].pointer))->pivotY = -0xDB;
        fclObjStartTween(work->panels[0x4B].pointer, -5.0f, fGpffff852c, 2, 2, 2);
        work->state = 0x15;
    }
    work->inputBusy = 0;
}
#pragma pop

/* measured 002cdf80 (owner, width-selected from m2c-adapted V8): 3545 against retail 3460
   (+2.5%, band 3356-3563 PASS, 18 of headroom), 2042 edits (+36 reloc-only), 3047 differing words.
   regsave_scan: retail 3460 instrs, frame 0x220 vs object 0x290, body saves spare $f21 $f22.
   calls 374 matching retail 374 (81x 04e0, 47x 26f0, 34x 2970, 19x 04f0, 18x 0660,
   17x 09e0, 16x 45af60, 15x 2a60/0620, 13x 0b20, 9x 0700, 8x 0570, 7x 2a30/2d50, 6x 46a770/05a0/3560,
   5x 2830/2cb0, 4x cacd0/2d00, 3x 46d200/46b260/46d280/0940, 2x 106a90/0ca0/2b2f90/2d4760/2d7c10,
   1x 2700/2a00/106880/1067f0/275680/106600/2b2e70/2b3050/46b2f0/2dd230); lwc1 66 / swc1 18,
   mtc1 115, add.s 28, madd 1 / adda 1 (142.0f + work[0xC] * (s16)(work[2]-work[4]) via plain C),
   cvt.s.w 17, no HW (ldr 9 / ldl 9 as *(u64*)(s1+0x2C) per file rule 1, lq 10 / sq 10 / sd 9 for spills),
   dsll32/dsra32 80/80 (retail 80/80), nop 589 (17.0%), 177 branches (56 b + 121 cond, all delay slots
   empty), 1 jr (return, no switch). Adapted from /tmp/cold_cdf80/m2c.c (876 lines) with u8* work,
   Vec2f/u64 slots, s16/s8 widths via plain casts, RGBA via separate bytes pending, FMA via plain C,
   0620 u64 via *(u64*)(s1+0x2C), cacd0 11-arg (phantom stack arg dropped), 2670 0-arg, GP floats as 0.0f,
   D_0063FAA0 local extern. Width selection (individual bisection, cf. 001a7720): V8 all-s64-ish 3581
   (+3.5%, 18 over top, 1896 edits, 3080 words) FAIL; narrow temp_18 (s64->s32, 10 uses) 3545 (-36, PASS,
   2042 edits, 3047 words) LANDING; narrow temp_17_4 (9 uses) 3576 (-5, 1888 edits) FAIL. temp_18 models
   $s2 from $v0 after void 2700 (retail dsll32/dsra32 16, uninitialized in C, saves 36 vs s64); sp1A4/sp1DC
   added as f32 (Vec2f halves), 35 missing u8 bytes added. Production guarded (edits 2042). */
/* measured 002cdf80 (owner, 2026-09-19): fnalign **2042 -> 2040 edits**, count
   3545 -> 3543 against retail 3460, by writing m2c's top-tested `loop_N:` /
   `if (cond) { ...; goto loop_N; }` as the `do { } while (cond)` retail actually
   emits.  The m2c shape tests at the TOP of every iteration; retail's only compare is
   at the bottom, ending in `bnez ..., .-N`, with no guard before the first pass.
   Swept across the 44 first-party floors carrying the pattern: 21 improved in-gate,
   2 improved but fell outside the band and were left alone (func_0037da60 574 -> 569,
   func_002e4ac0 334 -> 329), and 7 got worse - notably func_002ac750 842 -> 857 and
   func_00468ff0 310 -> 323 - so it is measured per loop, not applied on sight. */
/* measured 002cdf80 (owner, 2026-09-20): fnalign **2040 -> 2025 edits** (-15), count
   3543 -> 3506 against retail 3460 (+46, +1.3%, band 3356-3563 PASS with 57 headroom),
   frame 0x290 -> 0x280, __floatdisf removed (1 jal). No unsuffixed doubles
   (grep -nE '[0-9]+\\.[0-9]+([^fFeE0-9]|$)' on extracted body: 0 hits, ruled out first
   per assignment). The over-long object is recomputation retail hoists (reverse of the
   usual body-hoists/retail-recomputes direction): hoist work+index*4 duplicate
   (temp_2_24 = temp_3_10 instead of recomputing work+var_19_5*4, -4/+ -10 edits) and
   hoist 2830 results with same args in same iteration (369's dispatch + 397/398/404's
   275680/106a90/106600 chain share one temp_17 via temp_17_4, -19/-7 edits, combined
   -23/-4 vs baseline), plus narrow var_19_5/temp_18_5 s64->s32 for the 0..7 loop
   (removes s64->float __floatdisf helper + dsll32/dsra32 extends + daddiu/dsll, -7/-11).
   Rejected hoists that worsen edits (retail recomputes them, usual direction):
   46a770(FB50/FAA0) per-branch duplicates (-10 count but +18/+16 edits),
   D_0063F888/DCC-DD0 float (-5/+16), 2a30 0x2D duplicate (-6/+4), 04e0 E44/E48/E40
   per-branch duplicates (+5 count from new spill). Repro: measure_guarded
   --save-candidate + fnalign --candidate <path> --quiet. */

static inline void shopDrawLabel(f32 size, const char *text, Vec2f pos, s32 color)
{
    frFontExDrawTextDeferredWithCharWidth(pos.x, pos.y, size, color, 0, 1, text, 0, 0, D_00795E30, -1);
}

/* func_002cdf80 (shop buy list: draw + input) best draft, 2026-09-26.
   fnalign: retail 3459 vs object 3459 instrs, 2 edits (+88 reloc-only), measured with
   `python3 tools/fnalign.py src/Event/Fcl/y_fclShopDraw.c func_002cdf80 --candidate <this file> --quiet`
   (still 2 edits after the prototypes were reconciled on 2026-09-26).
   Needs shopDrawLabel (static inline in y_fclShopDraw.c) moved above func_002cdf80.
   The only residual is the 0x43 loop test: this body tests `j < 6`, retail tests
   `i < 0x49` and keeps `j` as a dead counter. See ShopDraw_002cdf80_20260926.md. */


/* Slide timing uses six-byte prefixes at 0x20-byte row / 0xA0-byte tab
 * strides; the final prefix ends at 0x1166 before the saved selections. */


#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
/* Draw the sale inventory and process tab/list/detail input according to inputMode; proceeds use one fifth of retail price. */
// FUN_002CDF80
void fclShopDrawBuyList(void *task, s8 inputMode) {
    extern u8 D_0063FAA0[];
    extern f32 fGpffff8520;
    extern f32 fGpffff8524;
    extern f32 fGpffff8528;
    s8 fclObjHasStatusFlags(u8 *);
    s8 yListKindFor(void *);
    void yListRetreatCursorScrollDefaultIndex(s32, s32, s32, s64, s32, s16 *, s16 *);
    s8 fclShopUpdateTabs(void *, s8);
    void fclShopDrawSelectRow(void *, s16);
    void fclShopLayoutPanels(void *);
    FclShopWork *work;
    s32 itemId;
    s16 i;
    s32 textColor;
    s32 iconColor;
    s32 lineColor;
    u8 *objectWork;
    Vec2f *basePosition;
    struct { s16 object; s16 ordinal; } cursor;
    s8 n;
    u32 price;
    u32 unitProceeds;
    u32 flags;
    s16 start;
    s16 itemIndex;
    s16 row;
    s32 rowY;
    u8 *objectWorkForSlide;
    FclDrawColor rowColor;
    FclDrawColor bar0;
    FclDrawColor bar1;
    FclDrawColor bar2;
    FclDrawColor white0;
    FclDrawColor white1;
    FclDrawColor color;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    void *leftSprite;
    void *rightSprite;
    void *detailSprite;
    s16 top;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    top = yListLastIndexFor(work->lists[work->tab]);
    itemId = yListValueAtFor(work->lists[work->tab], work->cursor);
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(work->panels[i + 0x82].pointer, 0, 1);
    }
    if (yListKindFor(work->lists[work->tab]) != 0) {
        goto clear;
    }
    if (yListCountFor(work->lists[work->tab]) <= D_00748908[work->tab]) {
        fclObjSetAnchorPosition(work->panels[0x8C].pointer, 0x57, 117.0f);
        bar0 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x8C].pointer);
        ((FclObject *)objectWork)->color = bar0;
        fclObjSetAnchorPosition(work->panels[0x8D].pointer, 0x56, 118.0f);
        bar1 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x8D].pointer);
        ((FclObject *)objectWork)->color = bar1;
        fclObjSetAnchorPosition(work->panels[0x8E].pointer, 0x56, 119.0f);
        bar2 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x8E].pointer);
        ((FclObject *)objectWork)->color = bar2;
        fclObjChangeFlagBit(work->panels[0x65].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x66].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x15].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x16].pointer, 0, 1);
    } else {
        if (yListCountFor(work->lists[work->tab]) > 5) {
            if (yListCountFor(work->lists[work->tab]) > 5) {
                work->scrollStep = 104.0f / (f32)(yListCountFor(work->lists[work->tab]) - 5);
            }
            position4 = fclMakeVec2((f32)0x221, 142.0f + work->scrollStep * (f32)(work->cursor - work->scroll));
            fclDrawEquipSprite(0x36, position4, 138.0f, fclPackRgba(0xFF, 0xFE, 0xC6, 0x31), ((FclObject *)fclObjectGetWork(work->panels[0x17].pointer))->alpha, 0, D_00794EA0);
            fclObjChangeFlagBit(work->panels[0x15].pointer, 0, 0);
            fclObjChangeFlagBit(work->panels[0x16].pointer, 0, 0);
        } else {
            fclObjChangeFlagBit(work->panels[0x15].pointer, 0, 1);
            fclObjChangeFlagBit(work->panels[0x16].pointer, 0, 1);
        }
        if (work->tab == 0 && work->cursor == 0) {
            position5 = fclMakeVec2((f32)0x24E, 61.0f);
            white0 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
            fclDrawNumber(position5, 1.0f, white0, 0x11, 5, work->totalPrice, 0x70, 0x7A,
                          (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xAA);
        } else {
            price = datItemPrice((s16)itemId) / 5;
            position6 = fclMakeVec2((f32)0x24E, 61.0f);
            white1 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
            fclDrawNumber(position6, 1.0f, white1, 0x11, 5, work->quantity * price, 0x70, 0x7A,
                          (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xAA);
        }
        basePosition = (Vec2f *)D_0063F888;
        if (fclObjTestFlagBit(work->panels[0x65].pointer, 1) == 0) {
            ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->anchorPosition.y = basePosition->y + (f32)(work->scroll * 32);
        }
        if (fclObjTestFlagBit(work->panels[0x66].pointer, 1) == 0) {
            ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->anchorPosition.y = basePosition->y + (f32)(work->scroll * 32);
        }
        fclObjChangeFlagBit(work->panels[0x8C].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x8D].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x8E].pointer, 0, 1);
        n = (s8)fclAddClamped(0, yListCountFor(work->lists[work->tab]), 5, 0, 1);
        start = work->cursor - work->scroll;
        for (itemIndex = start, row = 0; itemIndex < start + n; itemIndex++, row++) {
            if (itemIndex < yListCountFor(work->lists[work->tab])) {
                textColor = fclPackRgba(0xFF, 0xAE, 0, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                iconColor = fclPackRgba(0, 0xFF, 0xAE, 0);
                rowColor = fclMakeDrawColor(0xFF, 0xAE, 0, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                lineColor = fclPackRgba(0, 0xFE, 0xC7, 0x31);
                if (itemIndex == work->cursor) {
                    textColor = fclPackRgba(0x2D, 0x2D, 0x2D, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                    iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                    rowColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, ((FclObject *)fclObjectGetWork(work->panels[0x15].pointer))->alpha);
                    lineColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                }
                if (work->tab == 0 && itemIndex == 0) {
                    if (yListCountFor(work->lists[work->tab]) > 1) {
                        {
                            s16 i2;

                            for (i2 = 0; i2 < 3; i2++) {
                                fclDrawEquipSprite(0x3C, fclMakeVec2((f32)((i2 << 5) + 0x6F), 143.0f), 115.0f, lineColor, 0xFF, 0, D_00795E60);
                                fclDrawEquipSprite(0x3C, fclMakeVec2((f32)((i2 << 5) + 0x1A1), 143.0f), 115.0f, lineColor, 0xFF, 0, D_00795E60);
                            }
                        }
                        fclObjSetAnchorPosition(work->panels[0x83].pointer, 0x56, 121.0f);
                        color = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                        objectWork = (u8 *)fclObjectGetWork(work->panels[0x83].pointer);
                        ((FclObject *)objectWork)->color = color;
                        if (itemIndex == work->cursor) {
                            color2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                            objectWork = (u8 *)fclObjectGetWork(work->panels[0x83].pointer);
                            ((FclObject *)objectWork)->color = color2;
                        }
                        fclObjSetAnchorPosition(work->panels[0x84].pointer, 0x56, 122.0f);
                        color3 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                        objectWork = (u8 *)fclObjectGetWork(work->panels[0x84].pointer);
                        ((FclObject *)objectWork)->color = color3;
                        if (itemIndex == work->cursor) {
                            color4 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                            objectWork = (u8 *)fclObjectGetWork(work->panels[0x84].pointer);
                            ((FclObject *)objectWork)->color = color4;
                        }
                        fclObjSetAnchorPosition(work->panels[0x82].pointer, 0x57, 120.0f);
                        color5 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                        objectWork = (u8 *)fclObjectGetWork(work->panels[0x82].pointer);
                        ((FclObject *)objectWork)->color = color5;
                        if (itemIndex == work->cursor) {
                            color6 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                            objectWork = (u8 *)fclObjectGetWork(work->panels[0x82].pointer);
                            ((FclObject *)objectWork)->color = color6;
                        }
                    }
                } else {
                    basePosition = (Vec2f *)D_0063F888;
                    rowY = row << 5;
                    position2 = fclMakeVec2(basePosition->x, basePosition->y + (f32)rowY);
                    position = fclMakeVec2(10.0f + position2.x, 9.0f + position2.y);
                    position3 = fclMakeVec2(70.0f, 126.0f + (f32)rowY);
                    if (row == work->scroll) {
                        f32 mx = 10.0f + ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->anchorPosition.x;

                        position = fclMakeVec2(mx, 9.0f + ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->anchorPosition.y);
                        position3 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->anchorPosition;
                    }
                    flags = datEntryGetFlags((s16)yListValueAtFor(work->lists[work->tab], itemIndex));
                    if (flags & 0x81) {
                        fclDrawEquipSprite(0x14, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x102) {
                        fclDrawEquipSprite(0x15, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x204) {
                        fclDrawEquipSprite(0x16, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x408) {
                        fclDrawEquipSprite(0x17, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x810) {
                        fclDrawEquipSprite(0x18, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x1020) {
                        fclDrawEquipSprite(0x19, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x2040) {
                        fclDrawEquipSprite(0x1A, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x4000) {
                        fclDrawEquipSprite(0x1B, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x8000) {
                        fclDrawEquipSprite(0x1C, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x40000) {
                        fclDrawEquipHelpSprite(0x1A, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else {
                        fclDrawEquipHelpSprite(0x1B, position, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    }
                    shopDrawLabel(115.0f, ((void *)datGetItemNameId((s16)yListValueAtFor(work->lists[work->tab], itemIndex))), fclMakeVec2(53.0f + position3.x, 7.0f + position3.y), textColor);
                    unitProceeds = datItemPrice((s16)yListValueAtFor(work->lists[work->tab], itemIndex)) / 5;
                    fclDrawNumber(fclMakeVec2(372.0f + position3.x, 16.0f + position3.y), 115.0f, rowColor, 0x10, 5, unitProceeds, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->spriteResource.pointer, 0xA9);
                    fclDrawEquipSprite(0x47, fclMakeVec2(400.0f + position3.x, 18.0f + position3.y), 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    fclDrawNumber(fclMakeVec2((f32)0x1AF + position3.x, 16.0f + position3.y), 115.0f, rowColor, 0x10, 5, datItemCount((s16)yListValueAtFor(work->lists[work->tab], itemIndex)) & 0xFF, 9, 0x7B,
                                  (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->spriteResource.pointer, 0xA9);
                }
            }
        }
    }
    if (inputMode != 2 && fclObjTestFlagBit(work->panels[0x65].pointer, 1) == 0 && fclObjTestFlagBit(work->panels[0x66].pointer, 1) == 0
        && fclObjHasStatusFlags(work->panels[0x43].pointer) == 0 && fclObjHasStatusFlags(work->panels[0x44].pointer) == 0
        && fclObjHasStatusFlags(work->panels[0x45].pointer) == 0 && fclObjHasStatusFlags(work->panels[0x46].pointer) == 0
        && fclObjHasStatusFlags(work->panels[0x47].pointer) == 0 && fclObjHasStatusFlags(work->panels[0x48].pointer) == 0) {
        if ((D_008C0276[0] & 0x1000) && work->inputBusy == 0) {
            if (yListCountFor(work->lists[work->tab]) > D_00748908[work->tab]) {
                if (inputMode == 1 && work->tab == 0 && work->cursor == 1) {
                    sdkSndStartStream(0, 0, 0, 0);
                    work->cursor = fclSubClamped(work->cursor, 1, 0, (s16)yListCountFor(work->lists[work->tab]), 2);
                    work->scroll = yListStepIndex(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, -1);
                }
                if (work->cursor == 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                    work->cursor = top;
                    work->scroll = fclAddClamped(0, top, 4, 0, 1);
                } else {
                    sdkSndStartStream(0, 0, 0, 0);
                    work->cursor = fclSubClamped(work->cursor, 1, 0, (s16)yListCountFor(work->lists[work->tab]), 2);
                    work->scroll = yListStepIndex(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, -1);
                }
                work->inputBusy = 1;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (yListCountFor(work->lists[work->tab]) > D_00748908[work->tab] && (inputMode != 1 || work->tab != 0 || work->cursor != 1)) {
                if (yListCountFor(work->lists[work->tab]) > 0) {
                    if (work->cursor != 0) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    work->cursor = fclSubClamped(work->cursor, 1, 0, 0, 1);
                    work->scroll = yListStepIndex(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, -1);
                }
                work->inputBusy = 1;
            }
        } else if ((D_008C0276[0] & 0x4000) && work->inputBusy == 0) {
            if (yListCountFor(work->lists[work->tab]) > D_00748908[work->tab]) {
                sdkSndStartStream(0, 0, 0, 0);
                work->cursor = fclAddClamped(work->cursor, 1, top, 0, 2);
                if (work->cursor == 0) {
                    work->scroll = 0;
                    if (work->tab == 0 && work->detailMode == 1) {
                        work->cursor = 1;
                        work->scroll = 1;
                    }
                } else if (top >= 5) {
                    work->scroll = yListStepIndex(work->cursor, work->scroll, top, 5, 1);
                } else {
                    work->scroll = yListStepIndex(work->cursor, work->scroll, top, yListCountFor(work->lists[work->tab]), 1);
                }
                work->inputBusy = 1;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (yListCountFor(work->lists[work->tab]) > D_00748908[work->tab]) {
                if (yListCountFor(work->lists[work->tab]) > 0) {
                    if (work->cursor != top) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    work->cursor = fclAddClamped(work->cursor, 1, top, 0, 1);
                    if (top >= 5) {
                        work->scroll = yListStepIndex(work->cursor, work->scroll, top, 5, 1);
                    } else {
                        work->scroll = yListStepIndex(work->cursor, work->scroll, top, yListCountFor(work->lists[work->tab]), 1);
                    }
                    work->inputBusy = 1;
                }
                return;
            }
        } else if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
            if (yListCountFor(work->lists[work->tab]) > D_00748908[work->tab]) {
                if (work->cursor != top) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, &work->cursor, &work->scroll);
                goto clear;
            }
        } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
            n = D_00748908[work->tab];
            if (n < yListCountFor(work->lists[work->tab])) {
                if (work->detailMode == 0) {
                    if (work->cursor != 0) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    yListRetreatCursorScroll(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, &work->cursor, &work->scroll);
                } else {
                    if (work->cursor != n) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    if (work->tab == 0) {
                        yListRetreatCursorScrollDefaultIndex(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, 1, &work->cursor, &work->scroll);
                    } else {
                        yListRetreatCursorScroll(work->cursor, work->scroll, yListCountFor(work->lists[work->tab]), 5, &work->cursor, &work->scroll);
                    }
                }
                goto clear;
            }
        } else if (D_008C027A[0] & 8) {
            if (work->detailMode != 1) {
                {
                    s16 si;
                    s16 sj;

                    for (sj = 0; sj < 3; sj++) {
                        for (si = 0; si < 5; si++) {
                            ((s16 *)((u8 *)(work) + 0xFA0 + (sj) * 0xA0 + (si) * 0x20))[1] = 0;
                            ((s16 *)((u8 *)(work) + 0xFA0 + (sj) * 0xA0 + (si) * 0x20))[0] = 4;
                            ((s16 *)((u8 *)(work) + 0xFA0 + (sj) * 0xA0 + (si) * 0x20))[2] = si;
                        }
                    }
                }
                work->savedCursor[work->tab] = work->cursor;
                work->savedScroll[work->tab] = work->scroll;
                work->previousTab = work->tab;
                if (yListCountFor(work->lists[work->tab]) >= 5) {
                    work->slideTimer = (work->slideWords + work->tab * 0x50)[(4) * 0x10] + 4;
                } else {
                    work->slideTimer = (work->slideWords + work->tab * 0x50)[(yListCountFor(work->lists[work->tab])) * 0x10] + yListCountFor(work->lists[work->tab]);
                }
                work->tab = fclAddClamped(work->tab, 1, 2, 0, 2);
                fclShopUpdateTabs(task, (s32)work->tab);
                fclShopDrawSelectRow(task, work->tab);
                work->cursor = 0;
                work->scroll = 0;
                work->savedCursor[work->tab] = 0;
                work->savedScroll[work->tab] = 0;
                if (yListCountFor(work->lists[work->tab]) >= 5) {
                    work->slideTimer = (work->slideWords + work->tab * 0x50)[(4) * 0x10] + 4;
                } else {
                    if (work->slideTimer < (s16)((work->slideWords + work->tab * 0x50)[(yListCountFor(work->lists[work->tab])) * 0x10] + yListCountFor(work->lists[work->tab]))) {
                        work->slideTimer = (work->slideWords + work->tab * 0x50)[(yListCountFor(work->lists[work->tab])) * 0x10] + yListCountFor(work->lists[work->tab]);
                    }
                }
                n = work->tab;
                switch (n) {
                case 0:
                    yListRebuildFor(work->lists[n], 0x40000, 0, 4, 0);
                    break;
                case 1:
                    yListRebuildFor(work->lists[n], 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:
                    yListRebuildFor(work->lists[n], 0x10000, 0, 1, 0);
                    break;
                }
                work->state = 0x33;
                sdkSndStartStream(0, 0, 0, 5);
                goto clear;
            }
        } else if (D_008C027A[0] & 4) {
            if (work->detailMode != 1) {
                {
                    s16 si;
                    s16 sj;

                    for (sj = 0; sj < 3; sj++) {
                        for (si = 0; si < 5; si++) {
                            ((s16 *)((u8 *)(work) + 0xFA0 + (sj) * 0xA0 + (si) * 0x20))[1] = 0;
                            ((s16 *)((u8 *)(work) + 0xFA0 + (sj) * 0xA0 + (si) * 0x20))[0] = 4;
                            ((s16 *)((u8 *)(work) + 0xFA0 + (sj) * 0xA0 + (si) * 0x20))[2] = si;
                        }
                    }
                }
                work->savedCursor[work->tab] = work->cursor;
                work->savedScroll[work->tab] = work->scroll;
                work->previousTab = work->tab;
                if (yListCountFor(work->lists[work->tab]) >= 5) {
                    work->slideTimer = (work->slideWords + work->tab * 0x50)[(4) * 0x10] + 4;
                } else {
                    work->slideTimer = (work->slideWords + work->tab * 0x50)[(yListCountFor(work->lists[work->tab])) * 0x10] + yListCountFor(work->lists[work->tab]);
                }
                work->tab = fclSubClamped(work->tab, 1, 0, 2, 2);
                fclShopUpdateTabs(task, (s32)work->tab);
                fclShopDrawSelectRow(task, work->tab);
                work->cursor = 0;
                work->scroll = 0;
                work->savedCursor[work->tab] = 0;
                work->savedScroll[work->tab] = 0;
                if (yListCountFor(work->lists[work->tab]) >= 5) {
                    work->slideTimer = (work->slideWords + work->tab * 0x50)[(4) * 0x10] + 4;
                } else {
                    if (work->slideTimer < (s16)((work->slideWords + work->tab * 0x50)[(yListCountFor(work->lists[work->tab])) * 0x10] + yListCountFor(work->lists[work->tab]))) {
                        work->slideTimer = (work->slideWords + work->tab * 0x50)[(yListCountFor(work->lists[work->tab])) * 0x10] + yListCountFor(work->lists[work->tab]);
                    }
                }
                n = work->tab;
                switch (n) {
                case 0:
                    yListRebuildFor(work->lists[n], 0x40000, 0, 4, 0);
                    break;
                case 1:
                    yListRebuildFor(work->lists[n], 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:
                    yListRebuildFor(work->lists[n], 0x10000, 0, 1, 0);
                    break;
                }
                work->state = 0x34;
                sdkSndStartStream(0, 0, 0, 5);
                goto clear;
            }
        } else if (D_008C024E[0] & 0x40) {
            if (yListCountFor(work->lists[work->tab]) <= D_00748908[work->tab]) {
                sdkSndStartStream(0, 0, 0, 8);
                return;
            }
            work->quantity = 1;
            if (work->tab == 0 && work->cursor - work->scroll == 0 && yListCountFor(work->lists[work->tab]) < 2) {
                sdkSndStartStream(0, 0, 0, 8);
                return;
            }
            if (yListCountFor(work->lists[work->tab]) > 0) {
                work->savedColors[0].c0 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->color.c0;
                work->savedColors[0].c1 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->color.c1;
                work->savedColors[0].c2 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->color.c2;
                work->savedColors[1].c0 = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color.c0;
                work->savedColors[1].c1 = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color.c1;
                work->savedColors[1].c2 = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color.c2;
                work->colorFrame = 0;
                work->state = 0x25;
                sdkSndStartStream(0, 0, 0, 1);
            }
            goto clear;
        } else if (D_008C024E[0] & 0x80) {
            if (yListCountFor(work->lists[work->tab]) > D_00748908[work->tab] && inputMode != 1) {
                if (fclObjTestFlagBit(work->panels[0x80].pointer, 1) == 1 || fclObjTestFlagBit(work->panels[0x23].pointer, 1) == 1
                    || fclObjTestFlagBit(work->panels[0x22].pointer, 1) == 1) {
                    return;
                }
                if ((work->tab != 0 || work->cursor != 0) && yListCountFor(work->lists[work->tab]) > 0) {
                    work->savedColors[0].c0 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->color.c0;
                    work->savedColors[0].c1 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->color.c1;
                    work->savedColors[0].c2 = ((FclObject *)fclObjectGetWork(work->panels[0x65].pointer))->color.c2;
                    work->savedColors[1].c0 = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color.c0;
                    work->savedColors[1].c1 = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color.c1;
                    work->savedColors[1].c2 = ((FclObject *)fclObjectGetWork(work->panels[0x66].pointer))->color.c2;
                    work->colorFrame = 0;
                    fclObjStartSlideFade(work->panels[0xA3].pointer, 3, 1.0f, fGpffff8504, 6, 0, 0);
                    fclObjStartSlideFade(work->panels[0xA4].pointer, 4, 1.0f, fGpffff8504, 6, 0, 0);
                    fclObjStartSlideFade(work->panels[0x80].pointer, 0x80, 1.0f, fGpffff8504, 6, 0, 0);
                    fclObjStartSlideFade(work->panels[0x9F].pointer, 3, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjStartSlideFade(work->panels[0xA0].pointer, 4, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjStartSlideFade(work->panels[0x23].pointer, 0x23, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjStartSlideFade(work->panels[0xA1].pointer, 3, 1.0f, fGpffff8504, 6, 2, 0);
                    fclObjStartSlideFade(work->panels[0xA2].pointer, 4, 1.0f, fGpffff8504, 6, 2, 0);
                    fclObjStartSlideFade(work->panels[0x22].pointer, 0x22, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjChangeFlagBit(work->panels[0x69].pointer, 0, 1);
                    fclObjChangeFlagBit(work->panels[0x6B].pointer, 0, 1);
                    fclObjChangeFlagBit(work->panels[0x6A].pointer, 0, 0);
                    work->state = 0x2F;
                    sdkSndStartStream(0, 1, 0, 3);
                }
                goto clear;
            }
        } else if (D_008C024E[0] & 0x20) {
            if (inputMode != 1) {
                sdkSndStartStream(0, 0, 0, 2);
                basePosition = (Vec2f *)D_0063F5B8;
                fclObjStartPosition(work->panels[0xB].pointer, fclMakeVec2(basePosition->x, basePosition->y), fclMakeVec2(basePosition->x, 300.0f + basePosition->y), 0, 0xA, 0);
                fclObjStartAlpha(work->panels[0xB].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xB].pointer))->alpha, 0, 0, 0xA, 0);
                fclObjSetAnchorPosition(work->panels[0x4F].pointer, 0x56, 11.0f);
                fclObjStartAlpha(work->panels[0x4F].pointer, 0xFF, 0, 0, 0xA, 0);
                fclObjSetAnchorPosition(work->panels[0x52].pointer, 0x56, 9.0f);
                fclObjStartAlpha(work->panels[0x52].pointer, 0xFF, 0, 0, 0xA, 0);
                {
                    for (cursor.object = 0x43, cursor.ordinal = 0; cursor.object < 0x49; cursor.object++, cursor.ordinal++) {
                        fclObjStartPosition(work->panels[cursor.object].pointer, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[cursor.object].pointer))->anchorPosition.x, ((FclObject *)fclObjectGetWork(work->panels[cursor.object].pointer))->anchorPosition.y), fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[cursor.object].pointer))->anchorPosition.x, 170.0f + ((FclObject *)fclObjectGetWork(work->panels[cursor.object].pointer))->anchorPosition.y), 1, 5, 0);
                    }
                }
                fclObjStartAlpha(work->panels[0x15].pointer, 0xFF, 0, 0, 6, 0);
                fclObjStartAlpha(work->panels[0x16].pointer, 0xFF, 0, 0, 6, 0);
                {
                    s16 k;

                    for (k = 0; k < 3; k++) {
                        fclObjChangeFlagBit(work->panels[k + 0x82].pointer, 0, 1);
                    }
                }
                fclObjChangeFlagBit(work->panels[0x65].pointer, 0, 1);
                fclObjChangeFlagBit(work->panels[0x66].pointer, 0, 1);
                objectWorkForSlide = fclObjectGetWork(work->panels[0xA3].pointer);
                fclObjStartPosition(work->panels[0xA3].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0xA3].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA3].pointer))->anchorPosition.y), 2, 0xF, 0);
                objectWorkForSlide = fclObjectGetWork(work->panels[0xA4].pointer);
                fclObjStartPosition(work->panels[0xA4].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0xA4].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA4].pointer))->anchorPosition.y), 2, 0xF, 0);
                objectWorkForSlide = fclObjectGetWork(work->panels[0x80].pointer);
                fclObjStartPosition(work->panels[0x80].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0x80].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0x80].pointer))->anchorPosition.y), 2, 0xF, 0);
                objectWorkForSlide = fclObjectGetWork(work->panels[0x9F].pointer);
                fclObjStartPosition(work->panels[0x9F].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0x9F].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0x9F].pointer))->anchorPosition.y), 2, 0xF, 1);
                objectWorkForSlide = fclObjectGetWork(work->panels[0xA0].pointer);
                fclObjStartPosition(work->panels[0xA0].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0xA0].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA0].pointer))->anchorPosition.y), 2, 0xF, 1);
                objectWorkForSlide = fclObjectGetWork(work->panels[0x23].pointer);
                fclObjStartPosition(work->panels[0x23].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0x23].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0x23].pointer))->anchorPosition.y), 2, 0xF, 1);
                objectWorkForSlide = fclObjectGetWork(work->panels[0xA1].pointer);
                fclObjStartPosition(work->panels[0xA1].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0xA1].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA1].pointer))->anchorPosition.y), 2, 0xF, 2);
                objectWorkForSlide = fclObjectGetWork(work->panels[0xA2].pointer);
                fclObjStartPosition(work->panels[0xA2].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0xA2].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA2].pointer))->anchorPosition.y), 2, 0xF, 2);
                objectWorkForSlide = fclObjectGetWork(work->panels[0x22].pointer);
                fclObjStartPosition(work->panels[0x22].pointer, ((FclObject *)objectWorkForSlide)->anchorPosition, fclMakeVec2(((FclObject *)fclObjectGetWork(work->panels[0x22].pointer))->anchorPosition.x, 500.0f + ((FclObject *)fclObjectGetWork(work->panels[0x22].pointer))->anchorPosition.y), 2, 0xF, 2);
                {
                    s16 i5;

                    for (i5 = 0x8C; i5 < 0x8F; i5++) {
                        if (fclObjTestFlagBit(work->panels[i5].pointer, 0) == 1) {
                            fclObjChangeFlagBit(work->panels[i5].pointer, 0, 1);
                        }
                    }
                }
                {
                    s16 i6;

                    for (i6 = 0; i6 < 3; i6++) {
                        fclObjStartAlpha(work->panels[i6].pointer, 0, 0xFF, 0, 0xA, 0);
                    }
                }
                {
                    for (cursor.ordinal = 0; cursor.ordinal < 7; cursor.ordinal++) {
                        basePosition = (Vec2f *)D_0063F560 + (cursor.ordinal + 0x3A);
                        fclObjSetAnchorPosition(work->panels[cursor.ordinal + 0x3A].pointer, 0x56, (f32)(cursor.ordinal + 0x64));
                        if (cursor.ordinal > 0) {
                            color7 = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
                            objectWork = (u8 *)fclObjectGetWork(work->panels[cursor.ordinal + 0x3A].pointer);
                            ((FclObject *)objectWork)->color = color7;
                        }
                        fclObjStartPosition(work->panels[cursor.ordinal + 0x3A].pointer, fclMakeVec2(80.0f + basePosition->x, basePosition->y), fclMakeVec2(basePosition->x, basePosition->y), 0, 3, cursor.ordinal);
                        fclObjStartAlpha(work->panels[cursor.ordinal + 0x3A].pointer, 0, 0xFF, 0, 3, cursor.ordinal);
                    }
                }
                color8 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                objectWork = (u8 *)fclObjectGetWork(work->panels[work->category + 0x3B].pointer);
                ((FclObject *)objectWork)->color = color8;
                fclObjStartAlpha(work->panels[0x3].pointer, 0, 0xFF, 0, 0, work->category);
                fclObjStartAlpha(work->panels[0x4].pointer, 0, 0xFF, 0, 0, work->category);
                {
                    s16 i8;

                    for (i8 = 0; i8 < 3; i8++) {
                        fclObjStartAlpha(work->panels[i8].pointer, 0, 0xFF, 0, 0xA, 0);
                    }
                }
                fclObjSetAnchorPosition(work->panels[0x6C].pointer, 0x41, 46.0f);
                fclObjStartAlpha(work->panels[0x6C].pointer, 0, 0xFF, 0, 6, 0);
                ((FclObject *)fclObjectGetWork(work->panels[0x6C].pointer))->anchorPosition.x = 198.0f;
                ((FclObject *)fclObjectGetWork(work->panels[0x6C].pointer))->anchorPosition.y = (f32)0x151;
                fclObjSetAnchorPosition(work->panels[0x6D].pointer, 0x41, 146.0f);
                fclObjStartAlpha(work->panels[0x6D].pointer, 0, 0xFF, 0, 6, 0);
                ((FclObject *)fclObjectGetWork(work->panels[0x6D].pointer))->anchorPosition.x = 216.0f;
                ((FclObject *)fclObjectGetWork(work->panels[0x6D].pointer))->anchorPosition.y = 368.0f;
                fclObjSetAnchorPosition(work->panels[0x69].pointer, 0x41, 49.0f);
                fclObjStartAlpha(work->panels[0x69].pointer, 0xFF, 0, 0, 0xA, 0);
                fclObjSetAnchorPosition(work->panels[0x6E].pointer, 0x41, 47.0f);
                fclObjStartAlpha(work->panels[0x6E].pointer, 0xFF, 0, 0, 0xA, 0);
                fclObjStartPosition(work->panels[0x6E].pointer, fclMakeVec2((f32)0x103, 404.0f), fclMakeVec2((f32)0x103, 404.0f), 0, 0, 0);
                fclObjSetAnchorPosition(work->panels[0x6B].pointer, 0x41, 47.0f);
                fclObjStartAlpha(work->panels[0x6B].pointer, 0xFF, 0, 0, 0xA, 0);
                fclObjStartPosition(work->panels[0x6B].pointer, fclMakeVec2(338.0f, 404.0f), fclMakeVec2(338.0f, 404.0f), 0, 0, 0);
                ((FclObject *)fclObjectGetWork(work->panels[0x6C].pointer))->anchorPosition.x = 198.0f;
                ((FclObject *)fclObjectGetWork(work->panels[0x6C].pointer))->anchorPosition.y = (f32)0x151;
                fclObjSetAnchorPosition(work->panels[0x5].pointer, 0x40, 191.0f);
                {
                    leftSprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(5));
                    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x5].pointer))->pivotX = sdkSpriteScaledWidth(leftSprite);
                    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x5].pointer))->pivotY = sdkSpriteScaledHeight(leftSprite);
                    sdkSpriteFreeNode(leftSprite);
                }
                fclObjStartAlpha(work->panels[0x5].pointer, 0, 0xCC, 0, 4, 4);
                fclObjStartTween(work->panels[0x5].pointer, 0.0f, fGpffff8520, 0, 4, 4);
                fclObjStartPosition(work->panels[0x5].pointer, fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
                fclObjSetAnchorPosition(work->panels[0x6].pointer, 0x40, 192.0f);
                ((FclObject *)fclObjectGetWork(work->panels[0x6].pointer))->anchorPosition.x = 110.0f;
                ((FclObject *)fclObjectGetWork(work->panels[0x6].pointer))->anchorPosition.y = -50.0f;
                {
                    rightSprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(6));
                    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x6].pointer))->pivotX = sdkSpriteScaledWidth(rightSprite);
                    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x6].pointer))->pivotY = 0;
                    fclObjStartTween(work->panels[0x6].pointer, -90.0f, fGpffff8524, 0, 4, 4);
                    fclObjStartAlpha(work->panels[0x6].pointer, 0, 0xFF, 0, 4, 4);
                    sdkSpriteFreeNode(rightSprite);
                }
                fclObjSetAnchorPosition(work->panels[0x91].pointer, 0x40, 190.0f);
                ((FclObject *)fclObjectGetWork(work->panels[0x91].pointer))->anchorPosition.x = 180.0f;
                ((FclObject *)fclObjectGetWork(work->panels[0x91].pointer))->anchorPosition.y = 30.0f;
                {
                    detailSprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(6));
                    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x91].pointer))->pivotX = sdkSpriteScaledWidth(detailSprite);
                    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x91].pointer))->pivotY = 0;
                    sdkSpriteFreeNode(detailSprite);
                }
                fclObjStartTween(work->panels[0x91].pointer, -85.0f, fGpffff8528, 0, 4, 2);
                fclObjStartAlpha(work->panels[0x91].pointer, 0, 0xFF, 0, 4, 2);
                fclShopLayoutPanels(task);
                work->state = 0x11;
            clear:
                work->inputBusy = 0;
            }
        } else {
            goto clear;
        }
    }
}
#pragma pop


/* MATCHED fclShopListInputStep: written over the shared ShopMenuWork overlay with
   one named slot per retail stack address (27 FclDrawColor, 57 Vec2f, the
   0x130/0x128/0x110/... label positions copied via *(Vec2f *)&); both
   work[7] dispatches as 0/1/2 switches; each loop gets its own s16 counter;
   the DBC/E88 handle arrays addressed as work + i*4 (retail CSEs that sum);
   stat deltas computed once into `d`; datItemValue takes s16 and the
   second-switch stat reads widen func_00106cd0's s16 result with (s32), as
   retail re-extends only there; the E60 handle loaded before the shared
   fGpffff8530 argument. */
/* Draw the selected and currently equipped items and their stat differences; return 1 once the detail panels finish entering. */
// FUN_002D1590
s32 fclShopListInputStep(void *task)
{
    extern s8 fclObjHasStatusFlags(void *);
    extern f32 fGpffff8530;
    extern f32 D_0063F620[];
    extern f32 D_0063F628[];
    extern f32 D_0063F630[];
    extern f32 D_0063F638[];
    extern f32 D_0063F640[];
    extern f32 D_0063F648[];
    extern f32 D_0063F660[];
    extern f32 D_0063F668[];
    extern f32 D_0063F9B0[];
    extern u8 D_0063FAA0[];
    FclDrawColor color;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    FclDrawColor color9;
    FclDrawColor color10;
    FclDrawColor color11;
    FclDrawColor color12;
    FclDrawColor color13;
    FclDrawColor color14;
    FclDrawColor color15;
    FclDrawColor color16;
    FclDrawColor color17;
    FclDrawColor color18;
    FclDrawColor color19;
    FclDrawColor color20;
    FclDrawColor color21;
    FclDrawColor color22;
    FclDrawColor color23;
    FclDrawColor color24;
    FclDrawColor color25;
    FclDrawColor color26;
    FclDrawColor color27;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    Vec2f position20;
    Vec2f position21;
    Vec2f position22;
    Vec2f position23;
    Vec2f position24;
    Vec2f position25;
    Vec2f position26;
    Vec2f position27;
    Vec2f position28;
    Vec2f position29;
    Vec2f position30;
    Vec2f position31;
    Vec2f position32;
    Vec2f position33;
    Vec2f position34;
    Vec2f position35;
    Vec2f position36;
    Vec2f position37;
    Vec2f position38;
    Vec2f position39;
    Vec2f position40;
    Vec2f position41;
    Vec2f position42;
    Vec2f position43;
    Vec2f position44;
    Vec2f position45;
    Vec2f position46;
    Vec2f position47;
    Vec2f position48;
    Vec2f position49;
    Vec2f position50;
    Vec2f position51;
    Vec2f position52;
    Vec2f position53;
    Vec2f position54;
    Vec2f position55;
    Vec2f position56;
    Vec2f position57;
    FclShopWork *work;
    u8 *objectWork;
    Vec2f *basePosition;
    s32 iconColor;
    s32 textColor;
    s32 white;
    s16 dash;
    s16 mark;
    s16 dash2;
    s16 slot;
    s16 k;
    u32 price;
    s32 statValue;
    s32 equippedStat;
    s32 statDelta;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    color2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    *(FclDrawColor *)&color = *(FclDrawColor *)&color2;
    iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
    textColor = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
    position = fclMakeVec2(51.0f, 48.0f);
    fclShopDrawItemText(task, work->unitIds[work->unitSelection], position, (void *)fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
    position2 = fclMakeVec2((f32)0x24E, 61.0f);
    color3 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    fclDrawNumber(position2, 1.0f, color3, 0x11, 5, datItemPrice((s16)yListValueAt(work->cursor)), 0x70, 0x7A,
                  (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xAA);
    if (fclObjHasStatusFlags(work->panels[0xA].pointer) == 0 && fclObjHasStatusFlags(work->panels[0x12].pointer) == 0 && fclObjHasStatusFlags(work->panels[0xE].pointer) == 0 &&
        fclObjHasStatusFlags(work->panels[0x13].pointer) == 0 && fclObjHasStatusFlags(work->panels[0xF].pointer) == 0 && fclObjHasStatusFlags(work->panels[0x10].pointer) == 0) {
        price = datItemPrice((s16)yListValueAt(work->cursor));
        if (price > fclGetMoney() || (datItemCount((s16)yListValueAt(work->cursor)) & 0xFF) == 0x63) {
            iconColor = fclPackRgba(0, 0xA6, 0x7F, 0x2B);
            color = fclMakeDrawColor(0xA6, 0x7F, 0x2B, 0xFF);
            textColor = fclPackRgba(0xA6, 0x7F, 0x2B, 0xFF);
        }
        position3 = fclMakeVec2(129.0f, 255.0f);
        position34 = *(Vec2f *)&position3;
        frFontExDrawTextDeferredWithCharWidth(position34.x, position34.y, 70.0f, textColor, 0, 1, ((void *)datGetItemNameId((s16)yListValueAt(work->cursor))), 0, 0, D_00794ED0, -1);
        if (datItemValue((s16)yListValueAt(work->cursor)) == 0) {
            for (dash = 0; dash < 0xF; dash++) {
                position4 = fclMakeVec2((f32)(dash * 0x16 + 0x6F), (f32)0x12B);
                fclDrawEquipSprite(0x3C, position4, 86.0f, fclPackRgba(0xFF, 0xFF, 0xC7, 0x31), 0xFF, 0, D_00794ED0);
            }
        } else {
            fclMesWindowDraw(datItemValue((s16)yListValueAt(work->cursor)), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0x57, 109.0f, 290.0f, 70.0f);
        }
        switch (work->category) {
        case 0:
            fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(work->cursor)), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 0, 0x57, 109.0f, 324.0f, 70.0f);
            position5 = fclMakeVec2(86.0f, 256.0f);
            fclDrawEquipSprite(work->unitIcons[work->unitSelection], position5, 69.0f, iconColor, 0xFF, 0, D_00794ED0);
            fclObjSetAnchorPosition(work->panels[0x1A].pointer, 0x57, 83.0f);
            color4 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x1A].pointer);
            ((FclObject *)objectWork)->color = color4;
            fclObjSetAnchorPosition(work->panels[0x1C].pointer, 0x57, 82.0f);
            color5 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x1C].pointer);
            ((FclObject *)objectWork)->color = color5;
            position6 = fclMakeVec2((f32)0x206, 324.0f);
            position35 = *(Vec2f *)&position6;
            statValue = datEntryGetPrimaryValue((s16)yListValueAt(work->cursor));
            equippedStat = datEntryGetPrimaryValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0));
            statDelta = datEntryGetPrimaryValue((s16)yListValueAt(work->cursor)) - equippedStat;
            if (statDelta < 0) {
                position36 = fclMakeVec2(12.0f + position35.x, position35.y - 18.0f);
                fclDrawEquipSprite(0x29, position36, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (statDelta > 0) {
                position37 = fclMakeVec2(12.0f + position35.x, position35.y - 18.0f);
                fclDrawEquipSprite(0x28, position37, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            position50 = fclMakeVec2(position35.x + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), position35.y);
            color20 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position50, 22.0f, color20, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            position7 = fclMakeVec2((f32)0x206, 374.0f);
            position38 = *(Vec2f *)&position7;
            statValue = datEntryGetSecondaryValue((s16)yListValueAt(work->cursor));
            equippedStat = datEntryGetSecondaryValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0));
            statDelta = datEntryGetSecondaryValue((s16)yListValueAt(work->cursor)) - equippedStat;
            if (statDelta < 0) {
                position39 = fclMakeVec2(12.0f + position38.x, position38.y - 18.0f);
                fclDrawEquipSprite(0x29, position39, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (statDelta > 0) {
                position40 = fclMakeVec2(12.0f + position38.x, position38.y - 18.0f);
                fclDrawEquipSprite(0x28, position40, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            position51 = fclMakeVec2(position38.x + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), position38.y);
            color21 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position51, 22.0f, color21, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 1:
            fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(work->cursor)), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 1, 0x57, 109.0f, 324.0f, 70.0f);
            position8 = fclMakeVec2(86.0f, 256.0f);
            fclDrawEquipSprite(0x1B, position8, 69.0f, iconColor, 0xFF, 0, D_00794ED0);
            fclObjSetAnchorPosition(work->panels[0x19].pointer, 0x57, 81.0f);
            color6 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x19].pointer);
            ((FclObject *)objectWork)->color = color6;
            fclObjSetAnchorPosition(work->panels[0x1B].pointer, 0x57, 80.0f);
            color7 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x1B].pointer);
            ((FclObject *)objectWork)->color = color7;
            position9 = fclMakeVec2((f32)0x206, 324.0f);
            position41 = *(Vec2f *)&position9;
            statValue = datEntryGetMiddleBandValue((s16)yListValueAt(work->cursor));
            equippedStat = datEntryGetMiddleBandValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1));
            statDelta = datEntryGetMiddleBandValue((s16)yListValueAt(work->cursor)) - equippedStat;
            if (statDelta < 0) {
                position42 = fclMakeVec2(12.0f + position41.x, position41.y - 18.0f);
                fclDrawEquipSprite(0x29, position42, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (statDelta > 0) {
                position43 = fclMakeVec2(12.0f + position41.x, position41.y - 18.0f);
                fclDrawEquipSprite(0x28, position43, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            position52 = fclMakeVec2(position41.x + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), position41.y);
            color22 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position52, 22.0f, color22, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            position10 = fclMakeVec2((f32)0x206, 374.0f);
            position44 = *(Vec2f *)&position10;
            statValue = datEntryGetLastBandValue((s16)yListValueAt(work->cursor));
            equippedStat = datEntryGetLastBandValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1));
            statDelta = datEntryGetLastBandValue((s16)yListValueAt(work->cursor)) - equippedStat;
            if (statDelta < 0) {
                position45 = fclMakeVec2(12.0f + position44.x, position44.y - 18.0f);
                fclDrawEquipSprite(0x29, position45, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (statDelta > 0) {
                position46 = fclMakeVec2(12.0f + position44.x, position44.y - 18.0f);
                fclDrawEquipSprite(0x28, position46, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            position53 = fclMakeVec2(position44.x + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), position44.y);
            color23 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position53, 22.0f, color23, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 2:
            fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(work->cursor)), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 2, 0x57, 109.0f, 324.0f, 70.0f);
            position11 = fclMakeVec2(86.0f, 256.0f);
            fclDrawEquipSprite(0x1C, position11, 69.0f, iconColor, 0xFF, 0, D_00794ED0);
            basePosition = (Vec2f *)D_0063F660;
            fclObjSetAnchorPosition(work->panels[0x20].pointer, 0x57, 84.0f);
            ((FclObject *)fclObjectGetWork(work->panels[0x20].pointer))->alpha = 0x7F;
            position12 = fclMakeVec2(basePosition->x, basePosition->y);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x20].pointer);
            ((FclObject *)objectWork)->anchorPosition = position12;
            fclObjSetAnchorPosition(work->panels[0x9D].pointer, 0x57, 84.0f);
            ((FclObject *)fclObjectGetWork(work->panels[0x9D].pointer))->alpha = 0x7F;
            position13 = fclMakeVec2(basePosition->x, 50.0f + basePosition->y);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x9D].pointer);
            ((FclObject *)objectWork)->anchorPosition = position13;
            break;
        }
        if ((u8)clndGetMoonPhase(yListValueAt(work->cursor)) & 1) {
            position14 = fclMakeVec2(37.0f, 243.0f);
            fclDrawResourceSprite(0x49, position14, 65.0f, fclPackRgba(0, 0xFF, 0x66, 0), 0xFF, 0, D_00794EA0);
        }
        basePosition = (Vec2f *)D_0063F9B0;
        fclObjSetAnchorPosition(work->panels[0x8A].pointer, 0x56, 94.0f);
        position15 = fclMakeVec2(basePosition->x, basePosition->y);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x8A].pointer);
        ((FclObject *)objectWork)->anchorPosition = position15;
        objectWork = (u8 *)work->panels[0x8A].pointer;
        fclObjStartTween(objectWork, fGpffff8530, fGpffff8530, 0, 0, 0);
        for (mark = 0; mark < 3; mark++) {
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[mark + 0x61].pointer, 0x41, 95.0f);
            color8 = fclMakeDrawColor(0xFF, 0xEF, 0x80, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(((FclShopWork *)work)->panels[mark + 0x61].pointer);
            ((FclObject *)objectWork)->color = color8;
        }
        fclObjSetAnchorPosition(work->panels[0x1D].pointer, 0x56, 91.0f);
        color9 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x1D].pointer);
        ((FclObject *)objectWork)->color = color9;
        fclObjSetAnchorPosition(work->panels[0x93].pointer, 0x56, 91.0f);
        color10 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x93].pointer);
        ((FclObject *)objectWork)->color = color10;
        position16 = fclMakeVec2(468.0f, 338.0f);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x93].pointer);
        ((FclObject *)objectWork)->anchorPosition = position16;
        if (yListCount() >= 2) {
            fclObjSetAnchorPosition(work->panels[0x17].pointer, 0x41, 88.0f);
            color11 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x17].pointer);
            ((FclObject *)objectWork)->color = color11;
            basePosition = (Vec2f *)D_0063F620;
            fclObjSetAnchorPosition(work->panels[0x18].pointer, 0x41, 89.0f);
            color12 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x18].pointer);
            ((FclObject *)objectWork)->color = color12;
            work->scrollStep = 91.0f / (f32)(yListCount() - 1);
            position17 = fclMakeVec2(basePosition->x - 1.0f, 264.0f + work->scrollStep * (f32)work->cursor);
            fclDrawEquipSprite(0x36, position17, 87.0f, fclPackRgba(0xFF, 0xFF, 0x6D, 0x31), ((FclObject *)fclObjectGetWork(work->panels[0x18].pointer))->alpha, 0, D_00794EA0);
        }
        position18 = fclMakeVec2((f32)0x219, 266.0f);
        fclDrawNumber(position18, 70.0f, color, 0x10, 5, datItemPrice((s16)yListValueAt(work->cursor)), 9, 0x7B,
                      (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->spriteResource.pointer, 0xA9);
        if (datItemValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], work->category)) == 0) {
            for (dash2 = 0; dash2 < 0xF; dash2++) {
                position19 = fclMakeVec2((f32)(dash2 * 0x16 + 0x6F), 134.0f);
                fclDrawEquipSprite(0x3C, position19, 86.0f, fclPackRgba(0xFF, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00794ED0);
            }
        } else {
            fclMesWindowDraw(datItemValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], work->category)), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0xAA, 109.0f, 124.0f, 70.0f);
        }
        switch (work->category) {
        case 0:
            white = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
            position20 = fclMakeVec2(129.0f, 89.0f);
            position47 = *(Vec2f *)&position20;
            frFontExDrawTextDeferredWithCharWidth(position47.x, position47.y, 70.0f, white, 0, 1, ((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0))), 0, 0, D_00794ED0, -1);
            position21 = fclMakeVec2(86.0f, 90.0f);
            fclDrawEquipSprite(work->unitIcons[work->unitSelection], position21, 69.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0, D_00794ED0);
            fclMesWindowDraw((s16)datItemBankOffset(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 1, 0, 0, 0x57, 109.0f, 158.0f, 70.0f);
            basePosition = (Vec2f *)D_0063F630;
            fclObjSetAnchorPosition(work->panels[0x98].pointer, 0x57, 83.0f);
            color13 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x98].pointer);
            ((FclObject *)objectWork)->color = color13;
            position22 = fclMakeVec2(basePosition->x, basePosition->y - 166.0f);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x98].pointer);
            ((FclObject *)objectWork)->anchorPosition = position22;
            basePosition = (Vec2f *)D_0063F640;
            fclObjSetAnchorPosition(work->panels[0x9A].pointer, 0x57, 82.0f);
            color14 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x9A].pointer);
            ((FclObject *)objectWork)->color = color14;
            position23 = fclMakeVec2(basePosition->x, basePosition->y - 166.0f);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x9A].pointer);
            ((FclObject *)objectWork)->anchorPosition = position23;
            statValue = datEntryGetPrimaryValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0));
            position54 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), 158.0f);
            color24 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position54, 22.0f, color24, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            statValue = datEntryGetSecondaryValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0));
            position55 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), 208.0f);
            color25 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position55, 22.0f, color25, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 1:
            white = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
            position24 = fclMakeVec2(129.0f, 89.0f);
            position48 = *(Vec2f *)&position24;
            frFontExDrawTextDeferredWithCharWidth(position48.x, position48.y, 70.0f, white, 0, 1, ((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1))), 0, 0, D_00794ED0, -1);
            position25 = fclMakeVec2(86.0f, 90.0f);
            fclDrawEquipSprite(0x1B, position25, 69.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0, D_00794ED0);
            fclMesWindowDraw((s16)datItemBankOffset(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 1, 0, 1, 0x57, 109.0f, 158.0f, 70.0f);
            basePosition = (Vec2f *)D_0063F628;
            fclObjSetAnchorPosition(work->panels[0x97].pointer, 0x57, 81.0f);
            color15 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x97].pointer);
            ((FclObject *)objectWork)->color = color15;
            position26 = fclMakeVec2(basePosition->x, basePosition->y - 166.0f);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x97].pointer);
            ((FclObject *)objectWork)->anchorPosition = position26;
            basePosition = (Vec2f *)D_0063F638;
            fclObjSetAnchorPosition(work->panels[0x99].pointer, 0x57, 80.0f);
            color16 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x99].pointer);
            ((FclObject *)objectWork)->color = color16;
            position27 = fclMakeVec2(basePosition->x, basePosition->y - 166.0f);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x99].pointer);
            ((FclObject *)objectWork)->anchorPosition = position27;
            statValue = datEntryGetMiddleBandValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1));
            position56 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), 158.0f);
            color26 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position56, 22.0f, color26, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            statValue = datEntryGetLastBandValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1));
            position57 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(statValue) - 1) * 8), 208.0f);
            color27 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(position57, 22.0f, color27, 0xF, 0, statValue, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 2:
            white = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
            position28 = fclMakeVec2(129.0f, 89.0f);
            position49 = *(Vec2f *)&position28;
            frFontExDrawTextDeferredWithCharWidth(position49.x, position49.y, 70.0f, white, 0, 1, ((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 2))), 0, 0, D_00794ED0, -1);
            position29 = fclMakeVec2(86.0f, 90.0f);
            fclDrawEquipSprite(0x1C, position29, 69.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0, D_00794ED0);
            fclMesWindowDraw((s16)datItemBankOffset(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 2)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 1, 0, 2, 0x57, 109.0f, 158.0f, 70.0f);
            basePosition = (Vec2f *)D_0063F668;
            fclObjSetAnchorPosition(work->panels[0x21].pointer, 0x57, 85.0f);
            fclObjSetAnchorPosition(work->panels[0x9E].pointer, 0x57, 85.0f);
            position30 = fclMakeVec2(basePosition->x, 50.0f + basePosition->y);
            objectWork = (u8 *)fclObjectGetWork(work->panels[0x9E].pointer);
            ((FclObject *)objectWork)->anchorPosition = position30;
            break;
        }
        for (slot = 0; slot < 3; slot++) {
            basePosition = (Vec2f *)(D_0063F560 + (slot + 0x61) * 8);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[slot + 0x94].pointer, 0x41, 95.0f);
            color17 = fclMakeDrawColor(0xE7, 0xE5, 0xE7, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(((FclShopWork *)work)->panels[slot + 0x94].pointer);
            ((FclObject *)objectWork)->color = color17;
            position31 = fclMakeVec2(basePosition->x, basePosition->y - 166.0f);
            objectWork = (u8 *)fclObjectGetWork(((FclShopWork *)work)->panels[slot + 0x94].pointer);
            ((FclObject *)objectWork)->anchorPosition = position31;
        }
        basePosition = (Vec2f *)D_0063F648;
        fclObjSetAnchorPosition(work->panels[0x9B].pointer, 0x56, 91.0f);
        color18 = fclMakeDrawColor(0xB0, 0xAE, 0xAF, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9B].pointer);
        ((FclObject *)objectWork)->color = color18;
        position32 = fclMakeVec2(basePosition->x, basePosition->y - 166.0f);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9B].pointer);
        ((FclObject *)objectWork)->anchorPosition = position32;
        fclObjSetAnchorPosition(work->panels[0x9C].pointer, 0x56, 91.0f);
        color19 = fclMakeDrawColor(0xB0, 0xAE, 0xAF, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9C].pointer);
        ((FclObject *)objectWork)->color = color19;
        position33 = fclMakeVec2(468.0f, 172.0f);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9C].pointer);
        ((FclObject *)objectWork)->anchorPosition = position33;
        return 1;
    }
    fclObjChangeFlagBit(work->panels[0x19].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x1A].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x1B].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x1C].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x20].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9D].pointer, 0, 1);
    for (k = 0; k < 3; k++) {
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[k + 0x61].pointer, 0, 1);
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[k + 0x94].pointer, 0, 1);
    }
    fclObjChangeFlagBit(work->panels[0x1D].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x93].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x17].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x18].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x97].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x98].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x99].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9A].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x21].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9E].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9B].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9C].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x8A].pointer, 0, 1);
    return 0;
}

/* measured: fclShopSlideInFromRight's full body was reconstructed (all call shapes,
   u64 slot pairs, switch, loops) and compiles; nd 462 with inline
   D_0063F5xx[0]/[1] globals. Retail caches each absolute global base in $s0
   across the fclMakeVec2/fclObjStartPosition groups; mwcc b210 rematerialises
   lui/addiu per load (D_00887300-family global-address-hoist floor, cf.
   func_002d7300 note). A Vec2f* base local makes mwcc cache the base but then
   work moves to $s2 and the frame grows 0x10 (all 19 u64 slots shift +0x10),
   nd ~470; tried both declaration orders and block-scoped i/t. Also: the
   fclObjStartAlpha colour-byte args need a u8 prototype for lbu/0xFF codegen.
   Four-attempt budget exhausted. */
/* measured: recipe B re-test 2026-08-03: single Vec2f *b re-assigned per
   group (retail re-hoists its $s0 base per group) WORKS here: nd 462 -> 9.
   Also needed: field_4 retyped u32 -> s16 (retail reads it with lh; the u32
   read produced lw + bltz/dup on (f32)(field_4<<5) AND hoisted a work+4
   address into a 3rd saved reg, frame 0xD0 -> 0xE0); plain i++ s16 loops
   (explicit (s16)/(s32) casts double the dsll32/dsra32 pairs). Residual 9
   words: (1) loop index addu operand order (obj addu $v0,$v0,$s1 vs retail
   $s1,$v0; u32-arithmetic spelling does not change it); (2) func_002e0690
   arg materialization - retail f12, $4, mov.s f13, $5-$7; mwcc emits $5-$7
   then mov.s; (3) the sp58 f32-pair stores: mwcc always loads in reverse
   store order (lwc1 0x5C before 0x58, first-loaded binds $f1) - tried f32
   temps in all declaration/assignment orders. Scheduling floor. */
/* MATCHED 2026-09-18.  The last 4 words were `mov.s $f13, $f12` three slots
   late.  b210 emits call-argument setup in source order, so retail's copy
   landing between `lw $a0` and `move $a1` means func_002e0690's two floats
   are arguments 2 and 3, not 5 and 6; the EABI gives integer and float
   arguments separate register files, so the reordered prototype is the same
   ABI and leaves the MATCHed callee in src/promoted/code1_002e.c byte-exact.
   Everything else here was already exact: switch dispatch, Vec2f-by-value
   arguments, and the raw u64 stack slots. */
/* Slide the comparison panels out and restore the inventory cursor and indicator sprites. */
// FUN_002D3EE0
void fclShopSlideInFromRight(void *task) {
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    FclShopWork *work;
    u8 *objectWork;
    Vec2f *basePosition;
    s16 i;
    s8 category;
    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    basePosition = (Vec2f *)D_0063F5B0;
    fclObjSetAnchorPosition(work->panels[0xA].pointer, 0x41, 109.0f);
    position = fclMakeVec2(basePosition->x, basePosition->y);
    position2 = fclMakeVec2(basePosition->x - 740.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xA].pointer, position, position2, 0, 4, 0);
    basePosition = (Vec2f *)D_0063F5F0;
    fclObjSetAnchorPosition(work->panels[0x12].pointer, 0x41, 109.0f);
    position3 = fclMakeVec2(basePosition->x, basePosition->y);
    position4 = fclMakeVec2(basePosition->x - 740.0f, basePosition->y);
    fclObjStartPosition(work->panels[0x12].pointer, position3, position4, 0, 4, 0);
    basePosition = (Vec2f *)D_0063F5D0;
    fclObjSetAnchorPosition(work->panels[0xE].pointer, 0x41, 111.0f);
    position5 = fclMakeVec2(basePosition->x, basePosition->y);
    position6 = fclMakeVec2(basePosition->x - 740.0f, basePosition->y);
    fclObjStartPosition(work->panels[0xE].pointer, position5, position6, 0, 4, 0);
    /* measured: access-site handle indexing matches; native indexed members had commuted four addu words. */
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[(i) + 0x94].pointer, 0, 1);
    }
    fclObjChangeFlagBit(work->panels[0x9B].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9C].pointer, 0, 1);
    category = work->category;
    switch (category) {
    case 0:
        fclObjChangeFlagBit(work->panels[0x1A].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x1C].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x98].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x9A].pointer, 0, 1);
        break;
    case 1:
        fclObjChangeFlagBit(work->panels[0x19].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x1B].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x97].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x99].pointer, 0, 1);
        break;
    case 2:
        fclObjChangeFlagBit(work->panels[0x20].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x9D].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x21].pointer, 0, 1);
        fclObjChangeFlagBit(work->panels[0x9E].pointer, 0, 1);
        break;
    }
        fclObjSetAnchorPosition(work->panels[0x92].pointer, 0x41, 109.0f);
    position7 = fclMakeVec2(86.0f, 242.0f);
    position8 = fclMakeVec2(826.0f, 242.0f);
    fclObjStartPosition(work->panels[0x92].pointer, position7, position8, 0, 4, 0);
    basePosition = (Vec2f *)D_0063F5F8;
    fclObjSetAnchorPosition(work->panels[0x13].pointer, 0x41, 112.0f);
    position9 = fclMakeVec2(basePosition->x, basePosition->y);
    position10 = fclMakeVec2(740.0f + basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x13].pointer, position9, position10, 0, 4, 0);
    basePosition = (Vec2f *)D_0063F5D8;
    fclObjSetAnchorPosition(work->panels[0xF].pointer, 0x41, 113.0f);
    position11 = fclMakeVec2(basePosition->x, basePosition->y);
    position12 = fclMakeVec2(740.0f + basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0xF].pointer, position11, position12, 0, 4, 0);
    basePosition = (Vec2f *)D_0063F5E0;
    fclObjSetAnchorPosition(work->panels[0x10].pointer, 0x41, 114.0f);
    position13 = fclMakeVec2(basePosition->x, basePosition->y);
    position14 = fclMakeVec2(740.0f + basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x10].pointer, position13, position14, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[(i) + 0x61].pointer, 0, 1);
    }
    fclObjChangeFlagBit(work->panels[0x1D].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x93].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x17].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x18].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x8A].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x6A].pointer, 0, 1);
    fclObjStartTween(work->panels[0x4D].pointer, -110.0f, -14.0f, 0, 4, 0);
    fclObjStartUniformRevealScale(work->panels[0x4E].pointer, 1.0f, 1.0f, 0, 0, 0);
    fclObjStartAlpha(work->panels[0x4E].pointer, 0, 0xFF, 0, 8, 6);
    position15 = fclMakeVec2(46.0f, 294.0f);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x4E].pointer);
    ((FclObject *)objectWork)->anchorPosition = *(Vec2f *)&position15;
    fclObjStartAlpha(work->panels[0x51].pointer, 0, 0xFF, 0, 8, 6);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x15].pointer);
    fclObjStartAlpha(work->panels[0x15].pointer, ((FclObject *)objectWork)->alpha, 0xFF, 0, 8, 0);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x16].pointer);
    fclObjStartAlpha(work->panels[0x16].pointer, ((FclObject *)objectWork)->alpha, 0xFF, 0, 8, 0);
    basePosition = (Vec2f *)D_0063F880;
    position16 = fclMakeVec2(700.0f + basePosition->x, basePosition->y + (f32)(work->scroll << 5));
    position17 = fclMakeVec2(basePosition->x, basePosition->y + (f32)(work->scroll << 5));
    fclObjStartPosition(work->panels[0x64].pointer, position16, position17, 1, 3, 3);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x15].pointer);
    fclObjStartAlpha(work->panels[0x64].pointer, ((FclObject *)objectWork)->alpha, 0xFF, 0, 8, 0);
    basePosition = (Vec2f *)D_0063F890;
    position18 = fclMakeVec2(700.0f + basePosition->x, basePosition->y + (f32)(work->scroll << 5));
    position19 = fclMakeVec2(basePosition->x, basePosition->y + (f32)(work->scroll << 5));
    fclObjStartPosition(work->panels[0x66].pointer, position18, position19, 1, 3, 3);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x15].pointer);
    fclObjStartAlpha(work->panels[0x66].pointer, ((FclObject *)objectWork)->alpha, 0xFF, 0, 8, 0);
    fclObjStartAlpha(work->panels[0xB].pointer, 0, 0xCC, 0, 8, 0);
    fclObjChangeFlagBit(work->panels[0x6B].pointer, 0, 0);
}

/* Colour rows are u8[4] (r, g, b, pad).  Both setters address the g/b
   bytes through component pointers: the selected-tab path stores through
   the g/b addresses again after the second yListCountFor call, and retail
   keeps exactly those addresses live in saved registers ($s0/$s6/$s7/$fp).
   A local RGBA struct array instead grows the frame by 0x20. */
#define SHOP_SET_RGB(rgb, r, g, b) do { \
    u8 *g_ = &(rgb)[1];                  \
    u8 *b_ = &(rgb)[2];                  \
    (rgb)[0] = (r);                      \
    *g_ = (g);                           \
    *b_ = (b);                           \
} while (0)
#define SHOP_SET_GRAY(rgb, v) do {       \
    u8 *b_ = &(rgb)[2];                  \
    u8 *g_ = &(rgb)[1];                  \
    (rgb)[0] = *g_ = *b_ = (v);          \
} while (0)
#define SHOP_SPRITE(handle) ((FclObject *)fclObjectGetWork(handle))

/* measured: MATCH (1,996 code bytes in the 2,000-byte window).  Sets the
   three shop tabs' priority, y and colour; the selected tab is highlighted
   and tabs whose stock is exhausted are greyed out. */
// FUN_002D4760
s8 fclShopUpdateTabs(void *task, s8 selectedTab) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s16 i;
    s16 j;
    s32 sel;
    FclShopWork *work;
    u8 *ca;
    u8 *cb;
    s16 *row;
    u8 r;
    u8 g;
    u8 b;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    colorA[0][0] = colorA[2][0] = 0xBD;
    colorA[0][1] = colorA[2][1] = 0x68;
    colorA[0][2] = colorA[2][2] = 3;
    primary[0] = primary[2] = 0x56;
    y[0][0] = y[2][0] = 0x86;
    y[0][1] = y[2][1] = 0x87;
    colorB[0][0] = colorB[2][0] = 0x2D;
    colorB[0][1] = colorB[2][1] = 0x2D;
    colorB[0][2] = colorB[2][2] = 0x2D;
    secondary[0] = secondary[2] = primary[0] + 1;
    thirdY[0] = thirdY[2] = 0x85;
    colorA[1][0] = 0x90;
    colorA[1][1] = 0x4F;
    colorA[1][2] = 1;
    primary[1] = 0x41;
    y[1][0] = 0x89;
    y[1][1] = 0x8A;
    colorB[1][0] = 0x2D;
    colorB[1][1] = 0x2D;
    colorB[1][2] = 0x2D;
    secondary[1] = primary[1] + 1;
    thirdY[1] = 0x88;
    /* The F18 handles are read by byte offset: work->field_F18[i] adds
       the index before the base (addu v1, v0, work) and misses by one word. */
    for (i = 0, sel = selectedTab; i < 3; i++) {
        if (yListCountFor(((FclShopWork *)work)->lists[(i)]) <= D_00748908[i]) {
            SHOP_SET_GRAY(colorA[i], 0x2D);
            if (i == 1) {
                SHOP_SET_GRAY(colorA[i], 0);
            }
            SHOP_SET_GRAY(colorB[i], 0x6F);
        }
        if (i == sel) {
            SHOP_SET_RGB(colorA[i], 0xFF, 0x96, 1);
            primary[i] = 0x57;
            row = y[i];
            row[0] = 0x83;
            row[1] = 0x84;
            SHOP_SET_RGB(colorB[i], 0xFF, 0xF2, 0x95);
            secondary[i] = primary[i] + 1;
            thirdY[i] = 0x82;
            if (yListCountFor(((FclShopWork *)work)->lists[(i)]) <= D_00748908[i]) {
                SHOP_SET_GRAY(colorA[i], 0x9C);
                SHOP_SET_GRAY(colorB[i], 0xFF);
            }
        }
    }
    /* Colour bytes of the first sprite are kept in r/g/b for the second. */
    for (j = 0; j < 3; j++) {
        switch (j) {
        case 0:
            SHOP_SPRITE(work->panels[0xA3].pointer)->anchorMode = primary[j];
            row = y[j];
            SHOP_SPRITE(work->panels[0xA3].pointer)->anchorValue = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->panels[0xA3].pointer)->color.c0 = r;
            g = ca[1];
            SHOP_SPRITE(work->panels[0xA3].pointer)->color.c1 = g;
            b = ca[2];
            SHOP_SPRITE(work->panels[0xA3].pointer)->color.c2 = b;
            SHOP_SPRITE(work->panels[0xA4].pointer)->anchorMode = primary[j];
            SHOP_SPRITE(work->panels[0xA4].pointer)->anchorValue = row[1];
            SHOP_SPRITE(work->panels[0xA4].pointer)->color.c0 = r;
            SHOP_SPRITE(work->panels[0xA4].pointer)->color.c1 = g;
            SHOP_SPRITE(work->panels[0xA4].pointer)->color.c2 = b;
            SHOP_SPRITE(work->panels[0x80].pointer)->anchorMode = secondary[j];
            SHOP_SPRITE(work->panels[0x80].pointer)->anchorValue = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->panels[0x80].pointer)->color.c0 = cb[0];
            SHOP_SPRITE(work->panels[0x80].pointer)->color.c1 = cb[1];
            SHOP_SPRITE(work->panels[0x80].pointer)->color.c2 = cb[2];
            break;
        case 1:
            SHOP_SPRITE(work->panels[0x9F].pointer)->anchorMode = primary[j];
            row = y[j];
            SHOP_SPRITE(work->panels[0x9F].pointer)->anchorValue = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->panels[0x9F].pointer)->color.c0 = r;
            g = ca[1];
            SHOP_SPRITE(work->panels[0x9F].pointer)->color.c1 = g;
            b = ca[2];
            SHOP_SPRITE(work->panels[0x9F].pointer)->color.c2 = b;
            SHOP_SPRITE(work->panels[0xA0].pointer)->anchorMode = primary[j];
            SHOP_SPRITE(work->panels[0xA0].pointer)->anchorValue = row[1];
            SHOP_SPRITE(work->panels[0xA0].pointer)->color.c0 = r;
            SHOP_SPRITE(work->panels[0xA0].pointer)->color.c1 = g;
            SHOP_SPRITE(work->panels[0xA0].pointer)->color.c2 = b;
            SHOP_SPRITE(work->panels[0x23].pointer)->anchorMode = secondary[j];
            SHOP_SPRITE(work->panels[0x23].pointer)->anchorValue = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->panels[0x23].pointer)->color.c0 = cb[0];
            SHOP_SPRITE(work->panels[0x23].pointer)->color.c1 = cb[1];
            SHOP_SPRITE(work->panels[0x23].pointer)->color.c2 = cb[2];
            break;
        case 2:
            SHOP_SPRITE(work->panels[0xA1].pointer)->anchorMode = primary[j];
            row = y[j];
            SHOP_SPRITE(work->panels[0xA1].pointer)->anchorValue = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->panels[0xA1].pointer)->color.c0 = r;
            g = ca[1];
            SHOP_SPRITE(work->panels[0xA1].pointer)->color.c1 = g;
            b = ca[2];
            SHOP_SPRITE(work->panels[0xA1].pointer)->color.c2 = b;
            SHOP_SPRITE(work->panels[0xA2].pointer)->anchorMode = primary[j];
            SHOP_SPRITE(work->panels[0xA2].pointer)->anchorValue = row[1];
            SHOP_SPRITE(work->panels[0xA2].pointer)->color.c0 = r;
            SHOP_SPRITE(work->panels[0xA2].pointer)->color.c1 = g;
            SHOP_SPRITE(work->panels[0xA2].pointer)->color.c2 = b;
            SHOP_SPRITE(work->panels[0x22].pointer)->anchorMode = secondary[j];
            SHOP_SPRITE(work->panels[0x22].pointer)->anchorValue = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->panels[0x22].pointer)->color.c0 = cb[0];
            SHOP_SPRITE(work->panels[0x22].pointer)->color.c1 = cb[1];
            SHOP_SPRITE(work->panels[0x22].pointer)->color.c2 = cb[2];
            break;
        }
    }
    return selectedTab;
}

/* Return the icon code for the first matching equipment-flag group; the order of the overlapping tests is significant. */
// FUN_002D4F30
s32 fclShopStatusFlagToCode(s16 flags) {
    if (flags & 0x81) return 0x14;
    if (flags & 0x102) return 0x15;
    if (flags & 0x204) return 0x16;
    if (flags & 0x408) return 0x17;
    if (flags & 0x810) return 0x18;
    if (flags & 0x1020) return 0x19;
    if (flags & 0x2040) return 0x1A;
    if (flags & 0x4000) return 0x1B;
    if (flags & 0x8000) return 0x1C;
    if (flags & 0x40000) return 0x1D;
    return 0;
}

/* Draws an item label in the D_00795E30 font.  The inlined call binds its
   arguments right to left: colour, the position constructor (copied into
   the parameter slot), the name lookup, and finally the size. */


static inline s16 shopStatDelta(u32 item, u32 cur)
{
    return item - cur;
}

/* One stat number (22.0f, right-aligned by its digit count). */
static inline void shopDrawStat(u32 value, f32 x, f32 y)
{
    fclDrawNumber(fclMakeVec2(x + (f32)((s16)(fclDecimalDigitCount(value) - 1) * 8), y), 22.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0xF, 0, value, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
}

// Draws the item's stat block: stat numbers with their deltas, labels, and the per-row slots.
/* measured: MATCH, window 1108 words/4432B (1106 code words + 2 alignment).
   Built on the func_002df020/fclShopDrawItemCompare levers: a switch on work[7]
   written 0, 1, 2; Vec2f-returning fclMakeVec2 and the colour calls used
   directly as arguments; labels through the inlined shopDrawLabel.  The
   stat numbers go through the inlined shopDrawStat, which puts their
   fclMakeVec2 temporaries below the label parameter copies as in retail,
   but each stat's x base and value are assigned to the function locals `x`
   and `value` first (x before value, as retail evaluates them).  Passing
   the expressions straight to the helper is instruction-exact but colours
   `work` into $s0 below the short-lived values (95 words, every one the
   $s0/$s1 swap); writing the draws without the helper fixes the registers
   but lays the temporaries out in call order (38 words).  The (s32) casts on the stat ids give retail's dsll32/dsra32 before the s16
   getters (the deltas pass the func_00106cd0 result unextended); the deltas
   evaluate `cur` first through shopStatDelta; case 2 zeroes with
   `dB = dA = 0`. */
/* Compare the selected item with the selected unit's equipment, drawing category-specific values and signed improvement arrows. */
// FUN_002D5040
void fclShopDrawStats(void *task) {
    s16 firstStatDelta;
    s16 secondStatDelta;
    FclShopWork *work;
    u32 value;
    f32 x;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    fclDrawEquipSprite(fclShopStatusFlagToCode((s16)datEntryGetFlags((s32)yListValueAt(work->cursor))) & 0xFFFF, fclMakeVec2(37.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x, 35.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.y), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    shopDrawLabel(31.0f, (const char *)((void *)datGetItemNameId((s32)yListValueAt(work->cursor))), fclMakeVec2(79.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x, 34.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.y), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    shopDrawLabel(31.0f, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], work->category))), fclMakeVec2(79.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x, 34.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.y), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    switch (work->category) {
    case 0:
        x = 51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x);
        value = datEntryGetPrimaryValue((s32)yListValueAt(work->cursor)) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        x = 87.0f + (51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x));
        value = datEntryGetSecondaryValue((s32)yListValueAt(work->cursor)) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        fclDrawEquipSprite(work->unitIcons[work->unitSelection], fclMakeVec2(37.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x, 35.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.y), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        x = 51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x);
        value = datEntryGetPrimaryValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        x = 87.0f + (51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x));
        value = datEntryGetSecondaryValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        firstStatDelta = shopStatDelta((datEntryGetPrimaryValue((s32)yListValueAt(work->cursor)) & 0xFFFF), datEntryGetPrimaryValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0)) & 0xFFFF);
        secondStatDelta = shopStatDelta((datEntryGetSecondaryValue((s32)yListValueAt(work->cursor)) & 0xFFFF), datEntryGetSecondaryValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0)) & 0xFFFF);
        break;
    case 1:
        x = 51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x);
        value = datEntryGetMiddleBandValue((s32)yListValueAt(work->cursor)) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        x = 87.0f + (51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x));
        value = datEntryGetLastBandValue((s32)yListValueAt(work->cursor)) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        fclDrawEquipSprite(0x1B, fclMakeVec2(37.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x, 35.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.y), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        x = 51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x);
        value = datEntryGetMiddleBandValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        x = 87.0f + (51.0f + (296.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x));
        value = datEntryGetLastBandValue((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        firstStatDelta = shopStatDelta((datEntryGetMiddleBandValue((s32)yListValueAt(work->cursor)) & 0xFFFF), datEntryGetMiddleBandValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1)) & 0xFFFF);
        secondStatDelta = shopStatDelta((datEntryGetLastBandValue((s32)yListValueAt(work->cursor)) & 0xFFFF), datEntryGetLastBandValue(datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1)) & 0xFFFF);
        break;
    case 2:
        fclDrawEquipSprite(0x1C, fclMakeVec2(37.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.x, 35.0f + ((FclObject *)fclObjectGetWork(work->panels[0xA9].pointer))->anchorPosition.y), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        firstStatDelta = secondStatDelta = 0;
        break;
    }
    if (firstStatDelta > 0) {
        fclDrawEquipSprite(0x28, fclMakeVec2(360.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x, 245.0f), 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (firstStatDelta < 0) {
        fclDrawEquipSprite(0x29, fclMakeVec2(360.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x, 245.0f), 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
    if (secondStatDelta > 0) {
        fclDrawEquipSprite(0x28, fclMakeVec2(87.0f + (360.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x), 245.0f), 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (secondStatDelta < 0) {
        fclDrawEquipSprite(0x29, fclMakeVec2(87.0f + (360.0f + ((FclObject *)fclObjectGetWork(work->panels[0x2B].pointer))->anchorPosition.x), 245.0f), 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
}

/* measured: full body reconstructed (19 RGBA color groups + 0a60/2a60/04e0/
   2970/0620 chains, 48 u64 slots, 2 ifs + 3-case switch); frame 0x200 and all
   slot offsets matched; best nd 895 (obj only 2 words over window). Three
   residual families: (1) D_0063F658/D_0063F650 (f32[2]) base: retail hoists it
   into $s0 across the group's calls (lwc1 ($s0)/4($s0)); mwcc b210
   rematerialises lui+lwc1 per access even with named f32* base locals --
   same D_00887300 family as the func_002d7300 note. (2) color bytes: retail
   batches 4 lbu then 4 sb in address order into $a2/$a1/$a0/$v1; mwcc emits
   scrambled load order (g,b,a,r) for every spelling tried (array, u8 scalars,
   RGBA struct, explicit r/g/b/a temps). (3) work[7] if/switch: retail reloads
   lb 7($s1) per site; mwcc hoists addiu $s0,$s1,7. Global-address-hoist +
   scheduling floor. */
/* Animate the two comparison headers, stat labels and their supporting sprites into place for the current category. */
// FUN_002D6190
void fclShopStartHeaderBars(void *task) {
    FclDrawColor color;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    FclDrawColor color9;
    FclDrawColor color10;
    FclDrawColor color11;
    FclDrawColor color12;
    FclDrawColor color13;
    FclDrawColor color14;
    FclDrawColor color15;
    FclDrawColor color16;
    FclDrawColor color17;
    FclDrawColor color18;
    FclDrawColor color19;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    Vec2f position20;
    Vec2f position21;
    Vec2f position22;
    Vec2f position23;
    Vec2f position24;
    Vec2f position25;
    Vec2f position26;
    Vec2f position27;
    Vec2f position28;
    Vec2f position29;
    Vec2f position30;
    Vec2f position31;
    Vec2f position32;
    Vec2f position33;
    Vec2f position34;
    Vec2f position35;
    Vec2f position36;
    Vec2f position37;
    Vec2f position38;
    Vec2f position39;
    Vec2f position40;
    Vec2f position41;
    Vec2f position42;
    Vec2f position43;
    Vec2f position44;
    Vec2f position45;
    Vec2f position46;
    Vec2f position47;
    Vec2f position48;
    FclShopWork *work;
    u8 *objectWork;
    Vec2f *basePosition;
    s8 category;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    fclObjSetAnchorAlphaFull(work->panels[0x2B].pointer, 0x56, 35.0f);
    color = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0x2B].pointer));
    ((FclObject *)objectWork)->color = color;
    position = fclMakeVec2((f32) -0x212, 208.0f);
    position2 = fclMakeVec2(70.0f, 208.0f);
    fclObjStartPosition(work->panels[0x2B].pointer, position, position2, 0, 8, 0);
    fclObjSetAnchorAlphaFull(work->panels[0x2C].pointer, 0x56, 35.0f);
    color2 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0x2C].pointer));
    ((FclObject *)objectWork)->color = color2;
    position3 = fclMakeVec2(-37.0f, 208.0f);
    position4 = fclMakeVec2((f32) 0x233, 208.0f);
    fclObjStartPosition(work->panels[0x2C].pointer, position3, position4, 0, 8, 0);
    basePosition = (Vec2f *)D_0063F658;
    fclObjSetAnchorAlphaFull(work->panels[0x1F].pointer, 0x57, 33.0f);
    color3 = fclMakeDrawColor(0xF7, 0x94, 0x1D, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0x1F].pointer));
    ((FclObject *)objectWork)->color = color3;
    position5 = fclMakeVec2(basePosition->x - 600.0f, basePosition->y);
    position6 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x1F].pointer, position5, position6, 0, 8, 0);
    if (work->category != 2) {
        fclObjSetAnchorAlphaFull(work->panels[0x1D].pointer, 0x57, 30.0f);
        color4 = fclMakeDrawColor(0xFF, 0xEF, 0x81, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x1D].pointer));
        ((FclObject *)objectWork)->color = color4;
        position7 = fclMakeVec2(-232.0f, 227.0f);
        position8 = fclMakeVec2(368.0f, 227.0f);
        fclObjStartPosition(work->panels[0x1D].pointer, position7, position8, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x93].pointer, 0x57, 30.0f);
        color5 = fclMakeDrawColor(0xFF, 0xEF, 0x81, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x93].pointer));
        ((FclObject *)objectWork)->color = color5;
        position9 = fclMakeVec2(468.0f, 338.0f);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x93].pointer));
        ((FclObject *)objectWork)->anchorPosition = *(Vec2f *)&position9;
        position10 = fclMakeVec2(-145.0f, 227.0f);
        position11 = fclMakeVec2((f32) 0x1C7, 227.0f);
        fclObjStartPosition(work->panels[0x93].pointer, position10, position11, 0, 8, 0);
    }
    fclObjSetAnchorAlphaFull(work->panels[0xA9].pointer, 0x56, 35.0f);
    color6 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0xA9].pointer));
    ((FclObject *)objectWork)->color = color6;
    position12 = fclMakeVec2((f32) 0x29E, 94.0f);
    position13 = fclMakeVec2(70.0f, 94.0f);
    fclObjStartPosition(work->panels[0xA9].pointer, position12, position13, 0, 8, 0);
    fclObjSetAnchorAlphaFull(work->panels[0xAA].pointer, 0x56, 35.0f);
    color7 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0xAA].pointer));
    ((FclObject *)objectWork)->color = color7;
    position14 = fclMakeVec2((f32) 0x48B, 94.0f);
    position15 = fclMakeVec2((f32) 0x233, 94.0f);
    fclObjStartPosition(work->panels[0xAA].pointer, position14, position15, 0, 8, 0);
    basePosition = (Vec2f *)D_0063F650;
    fclObjSetAnchorAlphaFull(work->panels[0x1E].pointer, 0x57, 34.0f);
    color8 = fclMakeDrawColor(0xB0, 0xAF, 0xAF, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0x1E].pointer));
    ((FclObject *)objectWork)->color = color8;
    position16 = fclMakeVec2(600.0f + basePosition->x, basePosition->y);
    position17 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0x1E].pointer, position16, position17, 0, 8, 0);
    fclObjSetAnchorAlphaFull(work->panels[0x26].pointer, 0x57, 32.0f);
    color9 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
    objectWork = (u8 *)(fclObjectGetWork(work->panels[0x26].pointer));
    ((FclObject *)objectWork)->color = color9;
    position18 = fclMakeVec2((f32) 0x395, 178.0f);
    position19 = fclMakeVec2((f32) 0x13D, 178.0f);
    fclObjStartPosition(work->panels[0x26].pointer, position18, position19, 0, 8, 0);
    if (work->category != 2) {
        fclObjSetAnchorAlphaFull(work->panels[0x9B].pointer, 0x57, 30.0f);
        color10 = fclMakeDrawColor(0xB0, 0xAF, 0xAF, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x9B].pointer));
        ((FclObject *)objectWork)->color = color10;
        position20 = fclMakeVec2(968.0f, 113.0f);
        position21 = fclMakeVec2(368.0f, 113.0f);
        fclObjStartPosition(work->panels[0x9B].pointer, position20, position21, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x9C].pointer, 0x57, 30.0f);
        color11 = fclMakeDrawColor(0xB0, 0xAF, 0xAF, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x9C].pointer));
        ((FclObject *)objectWork)->color = color11;
        position22 = fclMakeVec2(468.0f, 338.0f);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x9C].pointer));
        ((FclObject *)objectWork)->anchorPosition = *(Vec2f *)&position22;
        position23 = fclMakeVec2((f32) 0x41F, 113.0f);
        position24 = fclMakeVec2((f32) 0x1C7, 113.0f);
        fclObjStartPosition(work->panels[0x9C].pointer, position23, position24, 0, 8, 0);
    }
    category = (s8)(work->category);
    switch (category) {                               /* irregular */
    case 0:
        fclObjSetAnchorAlphaFull(work->panels[0x1A].pointer, 0x58, 27.0f);
        color12 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x1A].pointer));
        ((FclObject *)objectWork)->color = color12;
        position25 = fclMakeVec2(-230.0f, 234.0f);
        position26 = fclMakeVec2(370.0f, 234.0f);
        fclObjStartPosition(work->panels[0x1A].pointer, position25, position26, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x1C].pointer, 0x58, 26.0f);
        color13 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x1C].pointer));
        ((FclObject *)objectWork)->color = color13;
        position27 = fclMakeVec2(-143.0f, 234.0f);
        position28 = fclMakeVec2((f32) 0x1C9, 234.0f);
        fclObjStartPosition(work->panels[0x1C].pointer, position27, position28, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x98].pointer, 0x58, 27.0f);
        color14 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x98].pointer));
        ((FclObject *)objectWork)->color = color14;
        position29 = fclMakeVec2((f32) 0x3CA, 121.0f);
        position30 = fclMakeVec2(370.0f, 121.0f);
        fclObjStartPosition(work->panels[0x98].pointer, position29, position30, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x9A].pointer, 0x58, 26.0f);
        color15 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x9A].pointer));
        ((FclObject *)objectWork)->color = color15;
        position31 = fclMakeVec2((f32) 0x421, 121.0f);
        position32 = fclMakeVec2((f32) 0x1C9, 121.0f);
        fclObjStartPosition(work->panels[0x9A].pointer, position31, position32, 0, 8, 0);
        return;
    case 1:
        fclObjSetAnchorAlphaFull(work->panels[0x19].pointer, 0x58, 25.0f);
        color16 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x19].pointer));
        ((FclObject *)objectWork)->color = color16;
        position33 = fclMakeVec2(-230.0f, 234.0f);
        position34 = fclMakeVec2(370.0f, 234.0f);
        fclObjStartPosition(work->panels[0x19].pointer, position33, position34, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x1B].pointer, 0x58, 24.0f);
        color17 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x1B].pointer));
        ((FclObject *)objectWork)->color = color17;
        position35 = fclMakeVec2(-143.0f, 234.0f);
        position36 = fclMakeVec2((f32) 0x1C9, 234.0f);
        fclObjStartPosition(work->panels[0x1B].pointer, position35, position36, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x97].pointer, 0x58, 25.0f);
        color18 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x97].pointer));
        ((FclObject *)objectWork)->color = color18;
        position37 = fclMakeVec2((f32) 0x3CA, 121.0f);
        position38 = fclMakeVec2(370.0f, 121.0f);
        fclObjStartPosition(work->panels[0x97].pointer, position37, position38, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x99].pointer, 0x58, 24.0f);
        color19 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        objectWork = (u8 *)(fclObjectGetWork(work->panels[0x99].pointer));
        ((FclObject *)objectWork)->color = color19;
        position39 = fclMakeVec2((f32) 0x421, 122.0f);
        position40 = fclMakeVec2((f32) 0x1C9, 120.0f);
        fclObjStartPosition(work->panels[0x99].pointer, position39, position40, 0, 8, 0);
        return;
    case 2:
        fclObjSetAnchorAlphaFull(work->panels[0x20].pointer, 0x58, 28.0f);
        ((FclObject *)fclObjectGetWork(work->panels[0x20].pointer))->alpha = 0x7F;
        position41 = fclMakeVec2(-233.0f, 225.0f);
        position42 = fclMakeVec2((f32) 0x16F, 225.0f);
        fclObjStartPosition(work->panels[0x20].pointer, position41, position42, 0, 8, 0);
        fclObjSetAnchorPosition(work->panels[0x9D].pointer, 0x58, 28.0f);
        ((FclObject *)fclObjectGetWork(work->panels[0x9D].pointer))->alpha = 0x7F;
        position43 = fclMakeVec2(-146.0f, 225.0f);
        position44 = fclMakeVec2(454.0f, 225.0f);
        fclObjStartPosition(work->panels[0x9D].pointer, position43, position44, 0, 8, 0);
        fclObjSetAnchorAlphaFull(work->panels[0x21].pointer, 0x58, 29.0f);
        ((FclObject *)fclObjectGetWork(work->panels[0x21].pointer))->alpha = 0xFF;
        position45 = fclMakeVec2((f32) 0x3C7, 111.0f);
        position46 = fclMakeVec2((f32) 0x16F, 111.0f);
        fclObjStartPosition(work->panels[0x21].pointer, position45, position46, 0, 8, 0);
        fclObjSetAnchorPosition(work->panels[0x9E].pointer, 0x58, 29.0f);
        ((FclObject *)fclObjectGetWork(work->panels[0x9E].pointer))->alpha = 0xFF;
        position47 = fclMakeVec2((f32) 0x41E, 111.0f);
        position48 = fclMakeVec2(454.0f, 111.0f);
        fclObjStartPosition(work->panels[0x9E].pointer, position47, position48, 0, 8, 0);
        return;
    }
}

/* measured: full body reconstructed (45 u64 slots, 22 2970/0620 chains, 3-case
   switch on work[7]) with D_0063F650/D_0063F658 redeclared f32[] and read via
   `Vec2f *base = (Vec2f *)D_0063F658;` - this DOES reproduce retail's $s1 base
   hoist (frame 0x1A0, ra/s1/s0, all slot offsets byte-match; the func_002d6190
   note's d658/d650 hoist floor does not apply to this shape). Four variants,
   best nd 70 (obj 2316B vs window 2320B): every fclObjStartPosition site loads
   arg1/arg2 (ld *(u64 *)&sp198/*(u64 *)&sp190) BEFORE arg0 (lw 0xCE4($s0)) where retail loads
   arg0 first - a 2-instruction pre-jal ordering swap at each of 22 sites.
   func_002df4c0 (matched) has the identical call shape with u64 slots and
   retail order lw-first, so the s64-vs-u64 slot type or slot offset likely
   drives the scheduler; untested within budget. Pre-jal arg-order floor. */
/* lever-1 audit (this wave): func_002d7300 is void (void *arg0) -- confirmed
   by generated-draft call sites. D_0063F650/D_0063F658 are f32[] (matches
   the note's Vec2f*(f32[]) reading); fclObjStartPosition (void*,u64,u64,s32,s32,
   s16) and fclObjectGetWork(void*) match m2c. No extern-width defect. */
/* MATCHED: Vec2f *base over f32[] D_0063F658/D_0063F650 reproduces the $s1 base hoist; (f32)int casts + float literals reproduce every 2970 chain. */
/* Slide the comparison headers and category-specific stat labels back out toward the screen edges. */
// FUN_002D7300
void fclShopStartRowPositions(void *task) {
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    Vec2f position20;
    Vec2f position21;
    Vec2f position22;
    Vec2f position23;
    Vec2f position24;
    Vec2f position25;
    Vec2f position26;
    Vec2f position27;
    Vec2f position28;
    Vec2f position29;
    Vec2f position30;
    Vec2f position31;
    Vec2f position32;
    Vec2f position33;
    Vec2f position34;
    Vec2f position35;
    Vec2f position36;
    Vec2f position37;
    Vec2f position38;
    Vec2f position39;
    Vec2f position40;
    Vec2f position41;
    Vec2f position42;
    Vec2f position43;
    Vec2f position44;
    Vec2f position45;
    Vec2f position46;
    u8 *work;
    Vec2f *basePosition;
    s8 category;

    work = ((struct KwlnTask *)task)->work;
    position = fclMakeVec2(70.0f, 208.0f);
    position2 = fclMakeVec2((f32)0x29E, 208.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x2B].pointer, position, position2, 0, 8, 0);
    position3 = fclMakeVec2((f32)0x233, 208.0f);
    position4 = fclMakeVec2((f32)0x48B, 208.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x2C].pointer, position3, position4, 0, 8, 0);
    basePosition = (Vec2f *)D_0063F658;
    position5 = fclMakeVec2(basePosition->x, basePosition->y);
    position6 = fclMakeVec2(600.0f + basePosition->x, basePosition->y);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x1F].pointer, position5, position6, 0, 8, 0);
    position7 = fclMakeVec2(368.0f, 227.0f);
    position8 = fclMakeVec2(968.0f, 227.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x1D].pointer, position7, position8, 0, 8, 0);
    position9 = fclMakeVec2((f32)0x1C7, 227.0f);
    position10 = fclMakeVec2((f32)0x41F, 227.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x93].pointer, position9, position10, 0, 8, 0);
    position11 = fclMakeVec2(70.0f, 94.0f);
    position12 = fclMakeVec2((f32)-0x212, 94.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0xA9].pointer, position11, position12, 0, 8, 0);
    position13 = fclMakeVec2((f32)0x233, 94.0f);
    position14 = fclMakeVec2(-37.0f, 94.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0xAA].pointer, position13, position14, 0, 8, 0);
    basePosition = (Vec2f *)D_0063F650;
    position15 = fclMakeVec2(basePosition->x, basePosition->y);
    position16 = fclMakeVec2(basePosition->x - 600.0f, basePosition->y);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x1E].pointer, position15, position16, 0, 8, 0);
    position17 = fclMakeVec2((f32)0x13D, 178.0f);
    position18 = fclMakeVec2((f32)-0x11B, 178.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x26].pointer, position17, position18, 0, 8, 0);
    position19 = fclMakeVec2(368.0f, 113.0f);
    position20 = fclMakeVec2(-232.0f, 113.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x9B].pointer, position19, position20, 0, 8, 0);
    position21 = fclMakeVec2((f32)0x1C7, 113.0f);
    position22 = fclMakeVec2(-145.0f, 113.0f);
    fclObjStartPosition(((FclShopWork *)work)->panels[0x9C].pointer, position21, position22, 0, 8, 0);
    category = ((FclShopWork *)work)->category;
    switch (category) {
    case 0:
        position23 = fclMakeVec2(370.0f, 234.0f);
        position24 = fclMakeVec2((f32)0x3CA, 234.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x1A].pointer, position23, position24, 0, 8, 0);
        position25 = fclMakeVec2((f32)0x1C9, 234.0f);
        position26 = fclMakeVec2((f32)0x421, 234.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x1C].pointer, position25, position26, 0, 8, 0);
        position27 = fclMakeVec2(370.0f, 121.0f);
        position28 = fclMakeVec2(-230.0f, 121.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x98].pointer, position27, position28, 0, 8, 0);
        position29 = fclMakeVec2((f32)0x1C9, 121.0f);
        position30 = fclMakeVec2(-143.0f, 121.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x9A].pointer, position29, position30, 0, 8, 0);
        return;
    case 1:
        position31 = fclMakeVec2(370.0f, 234.0f);
        position32 = fclMakeVec2((f32)0x3CA, 234.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x19].pointer, position31, position32, 0, 8, 0);
        position33 = fclMakeVec2((f32)0x1C9, 234.0f);
        position34 = fclMakeVec2((f32)0x421, 234.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x1B].pointer, position33, position34, 0, 8, 0);
        position35 = fclMakeVec2(370.0f, 121.0f);
        position36 = fclMakeVec2(-230.0f, 121.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x97].pointer, position35, position36, 0, 8, 0);
        position37 = fclMakeVec2((f32)0x1C9, 120.0f);
        position38 = fclMakeVec2(-143.0f, 122.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x99].pointer, position37, position38, 0, 8, 0);
        return;
    case 2:
        position39 = fclMakeVec2((f32)0x16F, 225.0f);
        position40 = fclMakeVec2((f32)0x3C7, 225.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x20].pointer, position39, position40, 0, 8, 0);
        position41 = fclMakeVec2(454.0f, 225.0f);
        position42 = fclMakeVec2((f32)0x41E, 225.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x9D].pointer, position41, position42, 0, 8, 0);
        position43 = fclMakeVec2((f32)0x16F, 111.0f);
        position44 = fclMakeVec2(-233.0f, 111.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x21].pointer, position43, position44, 0, 8, 0);
        position45 = fclMakeVec2(454.0f, 111.0f);
        position46 = fclMakeVec2(-146.0f, 111.0f);
        fclObjStartPosition(((FclShopWork *)work)->panels[0x9E].pointer, position45, position46, 0, 8, 0);
        return;
    }
}


// Reset the tab tweens, then tilt the selected tab's three sprites to -3.
// FUN_002D7C10
void fclShopDrawSelectRow(void *task, s16 selectedTab) {
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    s32 sprite;

    sprite = (s32)sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(4));
    sdkSpriteScaledWidth((u8 *)sprite);
    sdkSpriteScaledHeight((u8 *)sprite);
    sdkSpriteFreeNode((u8 *)sprite);
    fclObjStartTween(work->panels[0xA3].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xA3].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0xA4].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xA4].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0x23].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x23].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0x9F].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x9F].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0xA0].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xA0].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0x22].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x22].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0xA1].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xA1].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0xA2].pointer, ((FclObject *)fclObjectGetWork(work->panels[0xA2].pointer))->tweenValue, 0.0f, 0, 2, 0);
    fclObjStartTween(work->panels[0x80].pointer, ((FclObject *)fclObjectGetWork(work->panels[0x80].pointer))->tweenValue, 0.0f, 0, 2, 0);
    switch ((s32)selectedTab) {
    case 0:
        fclObjStartTween(work->panels[0xA3].pointer, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->panels[0xA4].pointer, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->panels[0x80].pointer, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 1:
        fclObjStartTween(work->panels[0x9F].pointer, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->panels[0xA0].pointer, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->panels[0x23].pointer, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 2:
        fclObjStartTween(work->panels[0xA1].pointer, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->panels[0xA2].pointer, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->panels[0x22].pointer, 0.0f, -3.0f, 0, 2, 0);
        break;
    }
}

/* Set the paired category cursors' pivots and start a shared alternating swing of 1.0 through 2.9 units. */
// FUN_002D7F90
void fclShopStartSelectionShake(void *task) {
    s16 pivotX;
    FclShopTabPosition *tabPosition;
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    s32 sprite;
    s16 pivotY;
    u32 randomStep;
    f32 value;
    f32 swing;

    tabPosition = (FclShopTabPosition *)(D_0063F9F0 + (s32)work->category * 12);
    sprite = (s32)sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(4));
    pivotX = (s16)(s32)((tabPosition->width + sdkSpriteScaledWidth((u8 *)sprite)) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x3].pointer))->pivotX = pivotX;
    pivotY = (s16)(s32)(sdkSpriteScaledHeight((u8 *)sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x3].pointer))->pivotY = pivotY;
    value = (f32)pivotX;
    pivotX = (s16)(s32)(value - tabPosition->width);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4].pointer))->pivotX = pivotX;
    pivotY = (s16)(s32)(sdkSpriteScaledHeight((u8 *)sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x4].pointer))->pivotY = pivotY;
    randomStep = RpRandom() % 20U;
    value = (f32)randomStep;
    swing = shopAdd(value / 10.0f, 1.0f);
    if (!(((FclObject *)fclObjectGetWork(work->panels[0x3].pointer))->tweenValue <= 0.0f)) {
        swing = swing * -1.0f;
    }
    fclObjStartTween(work->panels[0x3].pointer, 0.0f, swing, 0, 0, 0);
    fclObjStartTween(work->panels[0x4].pointer, 0.0f, swing, 0, 0, 0);
    sdkSpriteFreeNode((u8 *)sprite);
}

// Start both indicator tweens at +/-4 and enable repetition; direction 1 chooses the negative value.
// FUN_002D8200
void fclShopSlideIndicator(void *task, s8 direction) {
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    s32 sprite;
    s16 pivot;
    f32 swing;

    fclObjectGetWork(work->panels[0x8A].pointer);
    swing = 4.0f;
    if (direction == 1) {
        swing = swing * -1.0f;
    }
    sprite = (s32)sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x7D));
    pivot = (s16)(s32)sdkSpriteScaledWidth((u8 *)sprite);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7D].pointer))->pivotX = pivot;
    pivot = (s16)(s32)(sdkSpriteScaledHeight((u8 *)sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7D].pointer))->pivotY = pivot;
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7E].pointer))->pivotX = 0;
    pivot = (s16)(s32)(sdkSpriteScaledHeight((u8 *)sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x7E].pointer))->pivotY = pivot;
    fclObjStartTween(work->panels[0x7D].pointer, 0.0f, swing, 0, 4, 0);
    fclObjStartTween(work->panels[0x7E].pointer, 0.0f, swing, 0, 4, 0);
    ((FclObject *)fclObjectGetWork(work->panels[0x7D].pointer))->tweenLoop = 1;
    ((FclObject *)fclObjectGetWork(work->panels[0x7E].pointer))->tweenLoop = 1;
    sdkSpriteFreeNode((u8 *)sprite);
}


/* fclShopDrawSwingCursor's body; fclShopSlideInFromAbove inlines it (retail re-reads the work
   pointer from the kept arg0 there). */
static inline void shopSwingCursor(void *task) {
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    s32 sprite;
    s16 pivotY;
    s16 pivotX;
    u32 randomStep;
    f32 value;
    f32 swing;

    sprite = (s32)sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(4));
    pivotX = (s16)(s32)((sdkSpriteScaledWidth((u8 *)sprite) + 79.0f) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA7].pointer))->pivotX = pivotX;
    pivotY = (s16)(s32)(sdkSpriteScaledHeight((u8 *)sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA7].pointer))->pivotY = pivotY;
    pivotY = (s16)(pivotX - 0x4F);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA8].pointer))->pivotX = pivotY;
    pivotY = (s16)(s32)(sdkSpriteScaledHeight((u8 *)sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA8].pointer))->pivotY = pivotY;
    randomStep = RpRandom() % 20U;
    value = (f32)randomStep;
    swing = shopAdd(value / 10.0f, 1.0f);
    if (!(((FclObject *)fclObjectGetWork(work->panels[0xA7].pointer))->tweenValue <= 0.0f)) {
        swing = swing * -1.0f;
    }
    fclObjStartTween(work->panels[0xA7].pointer, 0.0f, swing, 0, 0, 0);
    fclObjStartTween(work->panels[0xA8].pointer, 0.0f, swing, 0, 0, 0);
    sdkSpriteFreeNode((u8 *)sprite);
}

// Entry point for the cursor swing: runs the cursor animation step for this shop work.
// FUN_002D83C0
void fclShopDrawSwingCursor(void *task) {
    shopSwingCursor(task);
}

/* Hide expanded comparison sprites, slide out four detail panels, restore the tabs and clear detailMode. */
// FUN_002D8600
void fclShopHideSelectionSprites(void *task) {
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    s16 i;
    u8 *objectWork;
    Vec2f panelPosition;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f panelPosition4;
    Vec2f panelPosition3;
    Vec2f panelPosition2;

    fclObjChangeFlagBit(work->panels[0x1A].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x1C].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x19].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x1B].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x20].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x9D].pointer, 0, 1);
    /* measured: typed panels[i + 0x61] commutes the loop addu (two bytes). */
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[i + 0x61].pointer, 0, 1);
    }
    fclObjChangeFlagBit(work->panels[0x1D].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x93].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x17].pointer, 0, 1);
    fclObjChangeFlagBit(work->panels[0x18].pointer, 0, 1);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x86].pointer);
    panelPosition = ((FclObject *)objectWork)->anchorPosition;
    position = fclMakeVec2(740.0f + panelPosition.x, panelPosition.y);
    fclObjStartPosition(work->panels[0x86].pointer, panelPosition, position, 0, 4, 0);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x87].pointer);
    panelPosition2 = ((FclObject *)objectWork)->anchorPosition;
    position2 = fclMakeVec2(740.0f + panelPosition2.x, panelPosition2.y);
    fclObjStartPosition(work->panels[0x87].pointer, panelPosition2, position2, 0, 4, 0);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x88].pointer);
    panelPosition3 = ((FclObject *)objectWork)->anchorPosition;
    position3 = fclMakeVec2(740.0f + panelPosition3.x, panelPosition3.y);
    fclObjStartPosition(work->panels[0x88].pointer, panelPosition3, position3, 0, 4, 0);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x89].pointer);
    panelPosition4 = ((FclObject *)objectWork)->anchorPosition;
    position4 = fclMakeVec2(740.0f + panelPosition4.x, panelPosition4.y);
    fclObjStartPosition(work->panels[0x89].pointer, panelPosition4, position4, 0, 4, 0);
    fclObjStartSlideFade(work->panels[0xA3].pointer, 3, fGpffff8504, 1.0f, 6, 0, 1);
    fclObjStartSlideFade(work->panels[0xA4].pointer, 4, fGpffff8504, 1.0f, 6, 0, 1);
    fclObjStartSlideFade(work->panels[0x80].pointer, 0x80, fGpffff8504, 1.0f, 6, 0, 1);
    fclObjStartSlideFade(work->panels[0x9F].pointer, 3, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjStartSlideFade(work->panels[0xA0].pointer, 4, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjStartSlideFade(work->panels[0x23].pointer, 0x23, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjStartSlideFade(work->panels[0xA1].pointer, 3, fGpffff8504, 1.0f, 6, 2, 1);
    fclObjStartSlideFade(work->panels[0xA2].pointer, 4, fGpffff8504, 1.0f, 6, 2, 1);
    fclObjStartSlideFade(work->panels[0x22].pointer, 0x22, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjChangeFlagBit(work->panels[0x69].pointer, 0, 0);
    fclObjChangeFlagBit(work->panels[0x6B].pointer, 0, 0);
    fclObjChangeFlagBit(work->panels[0x6A].pointer, 0, 1);
    work->detailMode = 0;
}

/* MATCHED func_002d8a60: file-local ShopListWork overlay (list[3] at 0xF18,
   ShopSlide slides[2][5] at 0xFA0, select/scroll s8[3] at 0x1168/0x116B) so
   indexed fields fold into base+index with displacement; scoped
   opt_loop_invariants on hoists the per-list bases and the `start + 5` bound
   like retail; `idx = arg1` for the list/table accesses, bare `arg1` elsewhere;
   func_002e2830 is an int-returning callee re-narrowed with (s16) at each use;
   the second fclDrawNumber value stays an inline argument so only the first
   (digits) is spilled, as in retail. */


/* measured: using the complete FclShopWork plus six-byte slide-prefix
 * accesses changes the saved-register allocation (267 differing bytes with
 * typed prefixes, 131 with separate scalar addresses). Retain the existing
 * narrow row-renderer declaration and its 0x20-byte row / 0xA0-byte tab
 * addressing. Only duration/timer/delay are read from each slide record. */
typedef struct {
    s16 duration;
    s16 timer;
    s16 delay;
    u8 pad6[0x1A];
} FclShopRowSlide;
typedef struct {
    u8 pad0[2];
    s16 cursor;
    u8 pad4[0xD];
    s8 active;
    u8 pad12[0xDBA];
    void *mark0;
    void *mark1;
    u8 padDD4[0x6C];
    void *frame0;
    void *frame1;
    void *frame2;
    u8 padE4C[0x1C];
    void *bar0[3];
    u8 padE74[0x70];
    void *mark2;
    void *mark3;
    u8 padEEC[0x1C];
    void *bar1[3];
    u8 padF14[4];
    void *list[3];
    u8 padF24[4];
    void *font;
    u8 padF2C[0x74];
    FclShopRowSlide slides[2][5];
    u8 pad10E0[0x88];
    s8 select[3];
    s8 scroll[3];
} FclShopListWork;
#pragma push
#pragma opt_loop_invariants on
/* Draw up to five inventory rows for a sliding tab, advancing each row's delay/timer and preserving its saved selection. */
// FUN_002D8A60
void fclShopDrawItemRows(void *task, s8 tabIndex, f32 x, f32 y) {
    FclDrawColor color;
    FclDrawColor color2;
    FclDrawColor color3;
    FclDrawColor color4;
    FclDrawColor color5;
    FclDrawColor color6;
    FclDrawColor color7;
    FclDrawColor color8;
    FclDrawColor color9;
    FclDrawColor color10;
    FclDrawColor color11;
    FclDrawColor color12;
    FclDrawColor color13;
    FclDrawColor color14;
    FclDrawColor color15;
    FclDrawColor color16;
    FclDrawColor color17;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f pos;
    FclShopListWork *work;
    u8 *objectWork;
    Vec2f *base;
    s32 listIndex;
    s32 count;
    s16 start;
    s16 itemIndex;
    s16 row;
    s16 i;
    f32 rowX;
    s32 textColor;
    s32 iconColor;
    s32 lineColor;
    u32 flags;
    u32 unitProceeds;

    work = (FclShopListWork*)((struct KwlnTask *)task)->work;
    listIndex = tabIndex;
    count = yListCountFor(work->list[listIndex]);
    yListLastIndexFor(work->list[listIndex]);
    if (yListCountFor(work->list[listIndex]) <= D_00748908[listIndex]) {
        rowX = fclEaseInterpolate(0, x, y, (f32)work->slides[tabIndex][0].timer, (f32)work->slides[tabIndex][0].duration);
        work->slides[tabIndex][0].timer = fclAddClamped(work->slides[tabIndex][0].timer, 1, work->slides[tabIndex][0].duration, 0, 1);
        if (tabIndex == work->active) {
            base = (Vec2f *)D_0063F9C0;
            fclObjSetAnchorPosition(work->bar0[0], 0x57, 117.0f);
            color2 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->bar0[0]);
            ((FclObject *)objectWork)->color = color2;
            ((FclObject *)fclObjectGetWork(work->bar0[0]))->anchorPosition.y = base->y;
            ((FclObject *)fclObjectGetWork(work->bar0[0]))->anchorPosition.x = 86.0f + rowX;
            base = (Vec2f *)D_0063F9C8;
            fclObjSetAnchorPosition(work->bar0[1], 0x56, 118.0f);
            color3 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->bar0[1]);
            ((FclObject *)objectWork)->color = color3;
            ((FclObject *)fclObjectGetWork(work->bar0[1]))->anchorPosition.y = base->y;
            ((FclObject *)fclObjectGetWork(work->bar0[1]))->anchorPosition.x = rowX - 10.0f;
            base = (Vec2f *)D_0063F9D0;
            fclObjSetAnchorPosition(work->bar0[2], 0x56, 119.0f);
            color4 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->bar0[2]);
            ((FclObject *)objectWork)->color = color4;
            ((FclObject *)fclObjectGetWork(work->bar0[2]))->anchorPosition.y = base->y;
            ((FclObject *)fclObjectGetWork(work->bar0[2]))->anchorPosition.x = 440.0f + rowX;
            fclObjChangeFlagBit(work->mark0, 0, 1);
            fclObjChangeFlagBit(work->mark1, 0, 1);
            return;
        }
        {
            base = (Vec2f *)D_0063F9C0;
            fclObjSetAnchorPosition(work->bar1[0], 0x57, 117.0f);
            color5 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->bar1[0]);
            ((FclObject *)objectWork)->color = color5;
            ((FclObject *)fclObjectGetWork(work->bar1[0]))->anchorPosition.y = base->y;
            ((FclObject *)fclObjectGetWork(work->bar1[0]))->anchorPosition.x = 86.0f + rowX;
            base = (Vec2f *)D_0063F9C8;
            fclObjSetAnchorPosition(work->bar1[1], 0x56, 118.0f);
            color6 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->bar1[1]);
            ((FclObject *)objectWork)->color = color6;
            ((FclObject *)fclObjectGetWork(work->bar1[1]))->anchorPosition.y = base->y;
            ((FclObject *)fclObjectGetWork(work->bar1[1]))->anchorPosition.x = rowX - 10.0f;
            base = (Vec2f *)D_0063F9D0;
            fclObjSetAnchorPosition(work->bar1[2], 0x56, 119.0f);
            color7 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            objectWork = (u8 *)fclObjectGetWork(work->bar1[2]);
            ((FclObject *)objectWork)->color = color7;
            ((FclObject *)fclObjectGetWork(work->bar1[2]))->anchorPosition.y = base->y;
            ((FclObject *)fclObjectGetWork(work->bar1[2]))->anchorPosition.x = 440.0f + rowX;
            fclObjChangeFlagBit(work->mark2, 0, 1);
            fclObjChangeFlagBit(work->mark3, 0, 1);
        }
        return;
    }
    fclAddClamped(0, count, 5, 0, 1);
    start = work->select[tabIndex] - work->scroll[tabIndex];
    if (start < 0) {
        start = 0;
    }

    for (itemIndex = start, row = 0; itemIndex < start + 5; itemIndex++, row++) {
        rowX = x;
        if (work->slides[tabIndex][row].delay > 0) {
            work->slides[tabIndex][row].delay = fclSubClamped(work->slides[tabIndex][row].delay, 1, 0, 0, 1);
        } else {
            rowX = fclEaseInterpolate(0, x, y, (f32)work->slides[tabIndex][row].timer, (f32)work->slides[tabIndex][row].duration);
            work->slides[tabIndex][row].timer = fclAddClamped(work->slides[tabIndex][row].timer, 1, work->slides[tabIndex][row].duration, 0, 1);
        }
        if (row == work->scroll[tabIndex]) {

            if (tabIndex == work->active) {
                base = (Vec2f *)D_0063F888;
                fclObjSetAnchorPosition(work->mark0, 0x41, 143.0f);
                color8 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                objectWork = (u8 *)fclObjectGetWork(work->mark0);
                ((FclObject *)objectWork)->color = color8;
                ((FclObject *)fclObjectGetWork(work->mark0))->alpha = 0xFF;
                ((FclObject *)fclObjectGetWork(work->mark0))->anchorPosition.y = base->y + (f32)(work->scroll[tabIndex] << 5);
                ((FclObject *)fclObjectGetWork(work->mark0))->anchorPosition.x = rowX - 10.0f;
                fclObjSetAnchorPosition(work->mark1, 0x41, 143.0f);
                color9 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                objectWork = (u8 *)fclObjectGetWork(work->mark1);
                ((FclObject *)objectWork)->color = color9;
                ((FclObject *)fclObjectGetWork(work->mark1))->alpha = 0xFF;
                ((FclObject *)fclObjectGetWork(work->mark1))->anchorPosition.y = base->y + (f32)(work->scroll[tabIndex] << 5);
                ((FclObject *)fclObjectGetWork(work->mark1))->anchorPosition.x = 444.0f + rowX;
                fclObjChangeFlagBit(work->bar0[0], 0, 1);
                fclObjChangeFlagBit(work->bar0[1], 0, 1);
                fclObjChangeFlagBit(work->bar0[2], 0, 1);
            } else {
                base = (Vec2f *)D_0063F888;
                fclObjSetAnchorPosition(work->mark2, 0x41, 143.0f);
                color10 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                objectWork = (u8 *)fclObjectGetWork(work->mark2);
                ((FclObject *)objectWork)->color = color10;
                ((FclObject *)fclObjectGetWork(work->mark2))->alpha = 0xFF;
                ((FclObject *)fclObjectGetWork(work->mark2))->anchorPosition.y = base->y + (f32)(work->scroll[tabIndex] << 5);
                ((FclObject *)fclObjectGetWork(work->mark2))->anchorPosition.x = rowX - 10.0f;
                fclObjSetAnchorPosition(work->mark3, 0x41, 143.0f);
                color11 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                objectWork = (u8 *)fclObjectGetWork(work->mark3);
                ((FclObject *)objectWork)->color = color11;
                ((FclObject *)fclObjectGetWork(work->mark3))->alpha = 0xFF;
                ((FclObject *)fclObjectGetWork(work->mark3))->anchorPosition.y = base->y + (f32)(work->scroll[tabIndex] << 5);
                ((FclObject *)fclObjectGetWork(work->mark3))->anchorPosition.x = 444.0f + rowX;
                fclObjChangeFlagBit(work->bar1[0], 0, 1);
                fclObjChangeFlagBit(work->bar1[1], 0, 1);
                fclObjChangeFlagBit(work->bar1[2], 0, 1);
            }
        }
        if (itemIndex < yListCountFor(work->list[listIndex])) {
            textColor = fclPackRgba(0xFF, 0xAE, 0, 0xFF);
            iconColor = fclPackRgba(0, 0xFF, 0xAE, 0);
            color = fclMakeDrawColor(0xFF, 0xAE, 0, 0xFF);
            lineColor = fclPackRgba(0, 0xFE, 0xC7, 0x31);
            if (itemIndex == work->select[tabIndex]) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
                iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                color = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                lineColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
            }
            if (tabIndex == 0 && itemIndex == 0) {
                if (yListCountFor(work->list[listIndex]) > 1) {
                    for (i = 0; i < 3; i++) {
                        position = fclMakeVec2(31.0f + rowX + (f32)(i * 32), 143.0f);
                        fclDrawEquipSprite(0x3C, position, 141.0f, lineColor, 0xFF, 0, D_00795E60);
                        position2 = fclMakeVec2((f32)0x151 + rowX + (f32)(i * 32), 143.0f);
                        fclDrawEquipSprite(0x3C, position2, 141.0f, lineColor, 0xFF, 0, D_00795E60);
                    }
                    fclObjSetAnchorPosition(work->frame1, 0x56, 142.0f);
                    color12 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                    objectWork = (u8 *)fclObjectGetWork(work->frame1);
                    ((FclObject *)objectWork)->color = color12;
                    if (itemIndex == work->cursor) {
                        color13 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                        objectWork = (u8 *)fclObjectGetWork(work->frame1);
                        ((FclObject *)objectWork)->color = color13;
                    }
                    ((FclObject *)fclObjectGetWork(work->frame1))->anchorPosition.x = 128.0f + rowX;
                    fclObjSetAnchorPosition(work->frame2, 0x56, 142.0f);
                    color14 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                    objectWork = (u8 *)fclObjectGetWork(work->frame2);
                    ((FclObject *)objectWork)->color = color14;
                    if (itemIndex == work->cursor) {
                        color15 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                        objectWork = (u8 *)fclObjectGetWork(work->frame2);
                        ((FclObject *)objectWork)->color = color15;
                    }
                    ((FclObject *)fclObjectGetWork(work->frame2))->anchorPosition.x = (f32)0x133 + rowX;
                    fclObjSetAnchorPosition(work->frame0, 0x57, 141.0f);
                    color16 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    objectWork = (u8 *)fclObjectGetWork(work->frame0);
                    ((FclObject *)objectWork)->color = color16;
                    if (itemIndex == work->cursor) {
                        color17 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                        objectWork = (u8 *)fclObjectGetWork(work->frame0);
                        ((FclObject *)objectWork)->color = color17;
                    }
                    ((FclObject *)fclObjectGetWork(work->frame0))->anchorPosition.x = 144.0f + rowX;
                }
            } else {
                flags = datEntryGetFlags((s16)yListValueAtFor(work->list[listIndex], itemIndex));
                if (flags & 0x81) {
                    position3 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x14, position3, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x102) {
                    position4 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x15, position4, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x204) {
                    position5 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x16, position5, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x408) {
                    position6 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x17, position6, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x810) {
                    position7 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x18, position7, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x1020) {
                    position8 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x19, position8, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x2040) {
                    position9 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x1A, position9, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x4000) {
                    position10 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x1B, position10, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x8000) {
                    position11 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x1C, position11, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x40000) {
                    position12 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipHelpSprite(0x1A, position12, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else {
                    position13 = fclMakeVec2(rowX, 135.0f + (f32)(row * 32));
                    fclDrawEquipHelpSprite(0x1B, position13, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                }
                position14 = fclMakeVec2(43.0f + rowX, 133.0f + (f32)(row * 32));
                pos = *(Vec2f *)&position14; /* word-aligned view: lwc1/swc1 copy, not ld/sd */
                frFontExDrawTextDeferredWithCharWidth(pos.x, pos.y, 141.0f, textColor, 0, 1,
                              ((void *)datGetItemNameId((s16)yListValueAtFor(work->list[listIndex], itemIndex))),
                              0, 0, D_00795E30, -1);
                unitProceeds = datItemPrice((s16)yListValueAtFor(work->list[listIndex], itemIndex)) / 5;
                position15 = fclMakeVec2(362.0f + rowX, 142.0f + (f32)(row * 32));
                fclDrawNumber(position15, 141.0f, color, 0x10, 5, unitProceeds, 9, 0x7B,
                              (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->font, 0xA9);
                position16 = fclMakeVec2(390.0f + rowX, 144.0f + (f32)(row * 32));
                fclDrawEquipSprite(0x47, position16, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                position17 = fclMakeVec2((f32)0x1A5 + rowX, 142.0f + (f32)(row * 32));
                fclDrawNumber(position17, 141.0f, color, 0x10, 5,
                              datItemCount((s16)yListValueAtFor(work->list[listIndex], itemIndex)) & 0xFF, 9, 0x7B,
                              (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->font, 0xA9);
            }
        }
    }
}
#pragma pop

/* Start the equipment/unit-selection introduction, including row fades, paired cursors and decorative sprite tweens. */
/* measured: the earlier native task-work trial hoisted work+8 and changed
 * allocation. Retaining the u32-shaped task address in the typed reload and
 * a typed panel-array base preserves MATCH with the inlined cursor helper.
 * The original u8 * cursor remains alongside the field-only typed alias;
 * the earlier opt_common_subs-off trial was 4988B and still MISMATCH. */
// FUN_002DA0A0
void fclShopSlideInFromAbove(void *task) {
    u8 *work;
    Vec2f *basePosition;
    ShopSpinParam *spinParameters;
    s16 i;
    void *sprite;
    void *sprite2;
    void *sprite3;
    void *sprite4;
    void *sprite5;
    void *sprite6;
    s32 row;
    Vec2f p0;
    Vec2f p1;
    Vec2f p2;
    Vec2f p3;
    Vec2f p4;
    Vec2f p5;
    Vec2f p6;
    Vec2f p7;
    Vec2f p8;
    Vec2f p9;
    Vec2f p10;
    Vec2f p11;
    Vec2f p12;
    Vec2f p13;
    Vec2f p14;
    Vec2f p15;
    Vec2f p16;
    Vec2f p17;
    Vec2f p18;
    Vec2f p19;
    Vec2f p20;
    Vec2f p21;
    Vec2f p22;
    Vec2f p23;
    FclShopWork *shopWork;

    work = ((struct KwlnTask *)(u32)task)->work;
    shopWork = (FclShopWork *)work;
    fclObjChangeFlagBit(((FclShopWork *)work)->panels[0x6D].pointer, 0, 1);

    basePosition = (Vec2f *)D_0063F5A0;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x8].pointer, 0x41, 162.0f);
    p0 = fclMakeVec2(basePosition->x, basePosition->y - 450.0f);
    p1 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(((FclShopPanel *)(work + MEMBER_OFFSET(FclShopWork, panels[0x8])))->pointer, p0, p1, 0, 4, 0);
    fclObjStartAlpha(shopWork->panels[0x8].pointer, 0, 0xCC, 0, 2, 0);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x8].pointer))->color = fclMakeDrawColor(0, 0, 0, 0xFF);

    basePosition = (Vec2f *)D_0063F5A8;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x9].pointer, 0x41, 163.0f);
    p2 = fclMakeVec2(basePosition->x, basePosition->y - 450.0f);
    p3 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x9].pointer, p2, p3, 0, 4, 0);
    fclObjStartAlpha(shopWork->panels[0x9].pointer, 0, 0xCC, 0, 2, 0);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x9].pointer))->color = fclMakeDrawColor(0, 0, 0, 0xFF);

    for (i = 0; i < ((FclShopWork *)work)->unitCount; i++) {
        ((FclShopWork *)work)->rowDelay[(i)] = 0;
        ((FclShopWork *)work)->rowFrame[(i)] = 0;
        ((FclShopWork *)work)->rowAlpha[(i)] = 0;
    }

    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0xA7].pointer, 0x41, 126.0f);
    row = ((FclShopWork *)work)->unitSelection;
    p4 = fclMakeVec2(47.0f, (78.0f + 35.0f * (f32)(s32)row) - 450.0f);
    p5 = fclMakeVec2(47.0f, 78.0f + 35.0f * (f32)row);
    fclObjStartPosition(shopWork->panels[0xA7].pointer, p4, p5, 0, 6, (&shopWork->rowDelay[0])[(s8)row]);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0xA7].pointer))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0xA8].pointer, 0x41, 127.0f);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0xA8].pointer))->color = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
    p6 = fclMakeVec2(126.0f, (78.0f + 35.0f * (f32)shopWork->unitSelection) - 450.0f);
    p7 = fclMakeVec2(126.0f, 78.0f + 35.0f * (f32)shopWork->unitSelection);
    fclObjStartPosition(shopWork->panels[0xA8].pointer, p6, p7, 0, 6, 0);
    shopSwingCursor(task);

    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x41].pointer, 0x41, 128.0f);
    fclObjStartAlpha(shopWork->panels[0x41].pointer, 0, 0xFF, 0, 0xA, 0);

    basePosition = (Vec2f *)D_0063F7B0;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x4A].pointer, 0x41, 78.0f);
    p8 = fclMakeVec2(basePosition->x, basePosition->y - (f32)0x226);
    p9 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x4A].pointer, p8, p9, 2, 4, 0);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x4A].pointer))->pivotX = ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x4A].pointer))->pivotY = 0;
    fclObjStartTween(shopWork->panels[0x4A].pointer, -5.0f, fGpffff852c, 2, 2, 2);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x4A].pointer))->color = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);

    basePosition = (Vec2f *)D_0063F7B8;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x4B].pointer, 0x41, 78.0f);
    p10 = fclMakeVec2(basePosition->x, basePosition->y - (f32)0x226);
    p11 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x4B].pointer, p10, p11, 2, 4, 0);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x4B].pointer))->pivotX = -50;
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x4B].pointer))->pivotY = -219;
    fclObjStartTween(shopWork->panels[0x4B].pointer, -5.0f, fGpffff852c, 2, 2, 2);

    basePosition = (Vec2f *)D_0063F8C0;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x6C].pointer, 0x41, 46.0f);
    fclObjStartAlpha(shopWork->panels[0x6C].pointer, 0, 0xFF, 0, 6, 0);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x6C].pointer))->anchorPosition.x = basePosition->x;
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x6C].pointer))->anchorPosition.y = basePosition->y;

    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x6E].pointer, 0x41, 47.0f);
    fclObjStartAlpha(shopWork->panels[0x6E].pointer, 0, 0xFF, 0, 6, 0);

    sprite = sdkSpriteNewNode((u32)(((FclShopWork *)work)->spriteResource.pointer), (u32)(0x44));
    basePosition = (Vec2f *)D_0063F780;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x44].pointer, 0x56, 53.0f);
    p12 = fclMakeVec2(basePosition->x, -130.0f);
    p13 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x44].pointer, p12, p13, 2, 5, 0);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x44].pointer))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x44].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x44].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
    fclObjSetHoldTimer(shopWork->panels[0x44].pointer, (f32)D_0063FA44[0], D_0063FA46[0]);
    fclObjStartTween(shopWork->panels[0x44].pointer, D_0063FA40[0], 0.0f, 2, D_0063FA46[0] + 5, 0);
    sdkSpriteFreeNode(sprite);

    sprite2 = sdkSpriteNewNode((u32)(shopWork->spriteResource.pointer), (u32)(0x43));
    basePosition = (Vec2f *)D_0063F778;
    spinParameters = (ShopSpinParam *)D_0063FA48;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x43].pointer, 0x56, 54.0f);
    p14 = fclMakeVec2(basePosition->x, -189.0f);
    p15 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x43].pointer, p14, p15, 2, 5, 3);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x43].pointer))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x43].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite2) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x43].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite2) / 2.0f);
    fclObjSetHoldTimer(shopWork->panels[0x43].pointer, (f32)spinParameters->speed, spinParameters->frames);
    fclObjStartTween(shopWork->panels[0x43].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 3);
    sdkSpriteFreeNode(sprite2);

    sprite3 = sdkSpriteNewNode((u32)(shopWork->spriteResource.pointer), (u32)(0x45));
    basePosition = (Vec2f *)D_0063F788;
    spinParameters = (ShopSpinParam *)D_0063FA48 + 1;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x45].pointer, 0x56, 55.0f);
    p16 = fclMakeVec2(basePosition->x, -75.0f);
    p17 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x45].pointer, p16, p17, 2, 5, 1);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x45].pointer))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x45].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite3) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x45].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite3) / 2.0f);
    fclObjSetHoldTimer(shopWork->panels[0x45].pointer, (f32)spinParameters->speed, spinParameters->frames);
    fclObjStartTween(shopWork->panels[0x45].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 1);
    sdkSpriteFreeNode(sprite3);

    sprite4 = sdkSpriteNewNode((u32)(shopWork->spriteResource.pointer), (u32)(0x46));
    basePosition = (Vec2f *)D_0063F790;
    spinParameters = (ShopSpinParam *)D_0063FA48 + 2;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x46].pointer, 0x56, 56.0f);
    p18 = fclMakeVec2(basePosition->x, -165.0f);
    p19 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x46].pointer, p18, p19, 2, 5, 4);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x46].pointer))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x46].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite4) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x46].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite4) / 2.0f);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x46].pointer))->tweenValue = 0.0f;
    fclObjSetHoldTimer(shopWork->panels[0x46].pointer, (f32)spinParameters->speed, spinParameters->frames);
    fclObjStartTween(shopWork->panels[0x46].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 4);
    sdkSpriteFreeNode(sprite4);

    sprite5 = sdkSpriteNewNode((u32)(shopWork->spriteResource.pointer), (u32)(0x47));
    basePosition = (Vec2f *)D_0063F798;
    spinParameters = (ShopSpinParam *)D_0063FA48 + 3;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x47].pointer, 0x56, 57.0f);
    p20 = fclMakeVec2(basePosition->x, -126.0f);
    p21 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x47].pointer, p20, p21, 2, 5, 2);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x47].pointer))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x47].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite5) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x47].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite5) / 2.0f);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x47].pointer))->tweenValue = 0.0f;
    fclObjSetHoldTimer(shopWork->panels[0x47].pointer, (f32)spinParameters->speed, spinParameters->frames);
    fclObjStartTween(shopWork->panels[0x47].pointer, spinParameters->angle, 0.0f, 1, spinParameters->frames + 5, 2);
    sdkSpriteFreeNode(sprite5);

    sprite6 = sdkSpriteNewNode((u32)(shopWork->spriteResource.pointer), (u32)(0x48));
    basePosition = (Vec2f *)D_0063F7A0;
    spinParameters = (ShopSpinParam *)D_0063FA48 + 4;
    fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x48].pointer, 0x56, 58.0f);
    p22 = fclMakeVec2(basePosition->x, -197.0f);
    p23 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(shopWork->panels[0x48].pointer, p22, p23, 2, 5, 5);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x48].pointer))->color = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x48].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite6) / 2.0f);
    ((FclShopItemPanel *)fclObjectGetWork(shopWork->panels[0x48].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite6) / 2.0f);
    ((FclObject *)fclObjectGetWork(shopWork->panels[0x48].pointer))->tweenValue = 0.0f;
    fclObjSetHoldTimer(shopWork->panels[0x48].pointer, (f32)spinParameters->speed, spinParameters->frames);
    fclObjStartTween(shopWork->panels[0x48].pointer, spinParameters->angle, 0.0f, 2, spinParameters->frames + 5, 5);
    sdkSpriteFreeNode(sprite6);
    ((FclShopWork *)work)->state = 0x14;
}

/* MATCHED func_002db400: FclDrawColor results stored whole, Vec2f slots
   passed to fclObjStartPosition by value, the six spin tables read through a
   ShopSpinParam view (angle/speed/frames), func_002e09b0 called with its real
   (void *, f32, s16) order, `func_002e26f0(..) <= D_00748908[n]` with the call
   first, and each func_0046d200 handle scoped to its own block so the handle
   takes $s2 and the table base $s1 as in retail. */
/* Build the three sale lists and their tab/list intro animations, then reset the cursor and select the first tab. */
// FUN_002DB400
void fclShopStartRevealSprites(void *task) {
    extern u8 D_0063FA70[];
    extern u8 D_0063FA78[];
    extern u8 D_0063FA80[];
    extern u8 D_0063FA88[];
    extern u8 D_0063FA90[];
    extern u8 D_0063FA98[];
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    FclDrawColor c5;
    FclDrawColor c6;
    FclDrawColor c7;
    FclDrawColor c8;
    FclDrawColor c9;
    FclDrawColor c10;
    FclDrawColor c11;
    FclDrawColor c12;
    FclDrawColor c13;
    FclDrawColor c14;
    FclDrawColor c15;
    FclDrawColor c16;
    FclDrawColor c17;
    FclDrawColor c18;
    FclDrawColor c19;
    FclDrawColor c20;
    FclDrawColor c21;
    FclDrawColor c22;
    FclDrawColor c23;
    FclDrawColor c24;
    FclDrawColor c25;
    FclDrawColor c26;
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    Vec2f position17;
    Vec2f position18;
    Vec2f position19;
    Vec2f position20;
    Vec2f position21;
    Vec2f position22;
    Vec2f position23;
    Vec2f position24;
    Vec2f position25;
    Vec2f position26;
    Vec2f position27;
    Vec2f position28;
    Vec2f position29;
    Vec2f position30;
    Vec2f position31;
    Vec2f position32;
    Vec2f position33;
    Vec2f position34;
    Vec2f position35;
    Vec2f position36;
    Vec2f position37;
    Vec2f position38;
    Vec2f position39;
    Vec2f position40;
    FclShopWork *work;
    Vec2f *basePosition;
    u8 *objectWork;
    ShopSpinParam *spinParameters;
    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    fclObjChangeFlagBit(work->panels[0x6D].pointer, 0, 1);
    basePosition = (Vec2f *)D_0063F5B8;
    fclObjSetAnchorPosition(work->panels[0xB].pointer, 0x41, 157.0f);
    position = fclMakeVec2(basePosition->x, -300.0f + basePosition->y);
    position2 = fclMakeVec2(basePosition->x, basePosition->y);
    fclObjStartPosition(work->panels[0xB].pointer, position, position2, 0, 7, 0);
    fclObjStartAlpha(work->panels[0xB].pointer, 0U, 0xCCU, 0U, 7, 0);
    c0 = fclMakeDrawColor(0, 0, 0, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0xB].pointer);
    ((FclObject *)objectWork)->color = c0;
    fclObjStartTween(work->panels[0xB].pointer, 0.0f, -4.0f, 0, 0, 0);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xB].pointer))->pivotX = (s16)(320.0f - basePosition->x);
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xB].pointer))->pivotY = (s16)(basePosition->y - 83.0f);
    fclObjStartRevealScale(work->panels[0xB].pointer, 1.0f, 1.5f, 1.0f, 1.0f, 0, 0, 0);
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x44));
        spinParameters = (ShopSpinParam *)D_0063FA70;
        fclObjSetAnchorPosition(work->panels[0x44].pointer, 0x56, 53.0f);
        position3 = fclMakeVec2((f32) 0x271, -200.0f);
        position4 = fclMakeVec2((f32) 0x271, 300.0f);
        fclObjStartPosition(work->panels[0x44].pointer, position3, position4, 2, 5, 5);
        c1 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x44].pointer);
        ((FclObject *)objectWork)->color = c1;
        ((FclObject *)fclObjectGetWork(work->panels[0x44].pointer))->tweenValue = 0.0f;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x44].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x44].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
        fclObjSetHoldTimer(work->panels[0x44].pointer, (f32) spinParameters->speed, spinParameters->frames);
        fclObjStartTween(work->panels[0x44].pointer, 180.0f + spinParameters->angle, 180.0f, 0, spinParameters->frames + 5, 5);
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x43));
        spinParameters = (ShopSpinParam *)D_0063FA78;
        fclObjSetAnchorPosition(work->panels[0x43].pointer, 0x56, 54.0f);
        position5 = fclMakeVec2(506.0f, -149.0f);
        position6 = fclMakeVec2(506.0f, (f32) 0x15F);
        fclObjStartPosition(work->panels[0x43].pointer, position5, position6, 2, 5, 2);
        c2 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x43].pointer);
        ((FclObject *)objectWork)->color = c2;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x43].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x43].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
        fclObjSetHoldTimer(work->panels[0x43].pointer, (f32) spinParameters->speed, spinParameters->frames);
        fclObjStartTween(work->panels[0x43].pointer, 180.0f + spinParameters->angle, 180.0f, 0, spinParameters->frames + 5, 2);
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x45));
        spinParameters = (ShopSpinParam *)D_0063FA80;
        fclObjSetAnchorPosition(work->panels[0x45].pointer, 0x56, 55.0f);
        position7 = fclMakeVec2(592.0f, -191.0f);
        position8 = fclMakeVec2(592.0f, (f32) 0x135);
        fclObjStartPosition(work->panels[0x45].pointer, position7, position8, 2, 5, 4);
        c3 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x45].pointer);
        ((FclObject *)objectWork)->color = c3;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x45].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x45].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
        fclObjSetHoldTimer(work->panels[0x45].pointer, (f32) spinParameters->speed, spinParameters->frames);
        fclObjStartTween(work->panels[0x45].pointer, 180.0f + spinParameters->angle, 180.0f, 0, spinParameters->frames + 5, 4);
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x46));
        spinParameters = (ShopSpinParam *)D_0063FA88;
        fclObjSetAnchorPosition(work->panels[0x46].pointer, 0x56, 56.0f);
        position9 = fclMakeVec2((f32) 0x1D3, -123.0f);
        position10 = fclMakeVec2((f32) 0x1D3, (f32) 0x179);
        fclObjStartPosition(work->panels[0x46].pointer, position9, position10, 2, 5, 1);
        c4 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x46].pointer);
        ((FclObject *)objectWork)->color = c4;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x46].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x46].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
        fclObjSetHoldTimer(work->panels[0x46].pointer, (f32) spinParameters->speed, spinParameters->frames);
        fclObjStartTween(work->panels[0x46].pointer, 180.0f + spinParameters->angle, 180.0f, 0, spinParameters->frames + 5, 1);
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x47));
        spinParameters = (ShopSpinParam *)D_0063FA90;
        fclObjSetAnchorPosition(work->panels[0x47].pointer, 0x56, 57.0f);
        position11 = fclMakeVec2((f32) 0x225, -221.0f);
        position12 = fclMakeVec2((f32) 0x225, (f32) 0x117);
        fclObjStartPosition(work->panels[0x47].pointer, position11, position12, 2, 5, 3);
        c5 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x47].pointer);
        ((FclObject *)objectWork)->color = c5;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x47].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x47].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
        fclObjSetHoldTimer(work->panels[0x47].pointer, (f32) spinParameters->speed, spinParameters->frames);
        fclObjStartTween(work->panels[0x47].pointer, 180.0f + spinParameters->angle, 180.0f, 0, spinParameters->frames + 5, 3);
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x48));
        spinParameters = (ShopSpinParam *)D_0063FA98;
        fclObjSetAnchorPosition(work->panels[0x48].pointer, 0x56, 58.0f);
        position13 = fclMakeVec2((f32) 0x195, -113.0f);
        position14 = fclMakeVec2((f32) 0x195, (f32) 0x183);
        fclObjStartPosition(work->panels[0x48].pointer, position13, position14, 2, 5, 0);
        c6 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x48].pointer);
        ((FclObject *)objectWork)->color = c6;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x48].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) / 2.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x48].pointer))->pivotY = (s16)(sdkSpriteScaledHeight(sprite) / 2.0f);
        fclObjSetHoldTimer(work->panels[0x48].pointer, (f32) spinParameters->speed, spinParameters->frames);
        fclObjStartTween(work->panels[0x48].pointer, 180.0f + spinParameters->angle, 180.0f, 0, spinParameters->frames + 5, 0);
        sdkSpriteFreeNode(sprite);
    }
    fclObjSetAnchorPosition(work->panels[0x4F].pointer, 0x56, 11.0f);
    fclObjStartAlpha(work->panels[0x4F].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    fclObjSetAnchorPosition(work->panels[0x52].pointer, 0x56, 9.0f);
    fclObjStartAlpha(work->panels[0x52].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    yListRebuildFor(work->lists[0], 0x40000, 0, 4, 0);
    yListRebuildFor(work->lists[1], 0xFFFF, 0x1FE0, 1, 0);
    yListRebuildFor(work->lists[2], 0x10000, 0, 1, 0);
    fclObjSetAnchorPosition(work->panels[0x15].pointer, 0x41, 139.0f);
    fclObjStartAlpha(work->panels[0x15].pointer, 0U, 0xFFU, 0U, 6, 7);
    c7 = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x15].pointer);
    ((FclObject *)objectWork)->color = c7;
    fclObjSetAnchorPosition(work->panels[0x16].pointer, 0x41, 140.0f);
    fclObjStartAlpha(work->panels[0x16].pointer, 0U, 0xFFU, 0U, 6, 7);
    c8 = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x16].pointer);
    ((FclObject *)objectWork)->color = c8;
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(3));
        fclObjSetAnchorPosition(work->panels[0xA3].pointer, 0x56, 131.0f);
        position15 = fclMakeVec2(24.0f, -60.0f);
        position16 = fclMakeVec2(24.0f, 48.0f);
        fclObjStartPosition(work->panels[0xA3].pointer, position15, position16, 2, 7, 5);
        ((FclObject *)fclObjectGetWork(work->panels[0xA3].pointer))->alpha = 0xFF;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA3].pointer))->pivotX = 0x55;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA3].pointer))->pivotY = 0x17;
        fclObjStartTween(work->panels[0xA3].pointer, -3.0f, -3.0f, 0, 0, 0);
        c9 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA3].pointer);
        ((FclObject *)objectWork)->color = c9;
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(4));
        fclObjSetAnchorPosition(work->panels[0xA4].pointer, 0x56, 132.0f);
        position17 = fclMakeVec2(64.0f, -60.0f);
        position18 = fclMakeVec2(64.0f, 48.0f);
        fclObjStartPosition(work->panels[0xA4].pointer, position17, position18, 2, 7, 5);
        ((FclObject *)fclObjectGetWork(work->panels[0xA4].pointer))->alpha = 0xFF;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA4].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) - 85.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA4].pointer))->pivotY = 0x17;
        fclObjStartTween(work->panels[0xA4].pointer, -3.0f, -3.0f, 0, 0, 0);
        c10 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA4].pointer);
        ((FclObject *)objectWork)->color = c10;
        sdkSpriteFreeNode(sprite);
    }
    fclObjSetAnchorPosition(work->panels[0x80].pointer, 0x57, 130.0f);
    position19 = fclMakeVec2(52.0f, -60.0f);
    position20 = fclMakeVec2(52.0f, 59.0f);
    fclObjStartPosition(work->panels[0x80].pointer, position19, position20, 2, 7, 5);
    fclObjStartTween(work->panels[0x80].pointer, -3.0f, -3.0f, 0, 0, 0);
    ((FclObject *)fclObjectGetWork(work->panels[0x80].pointer))->alpha = 0xFF;
    c11 = fclMakeDrawColor(0xFF, 0xF2, 0x95, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x80].pointer);
    ((FclObject *)objectWork)->color = c11;
    if (yListCountFor(work->lists[0]) <= D_00748908[0]) {
        c12 = fclMakeDrawColor(0x9C, 0x9C, 0x9C, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA3].pointer);
        ((FclObject *)objectWork)->color = c12;
        c13 = fclMakeDrawColor(0x9C, 0x9C, 0x9C, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA4].pointer);
        ((FclObject *)objectWork)->color = c13;
        c14 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x80].pointer);
        ((FclObject *)objectWork)->color = c14;
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(3));
        fclObjSetAnchorPosition(work->panels[0x9F].pointer, 0x41, 137.0f);
        position21 = fclMakeVec2(146.0f, -60.0f);
        position22 = fclMakeVec2(146.0f, 40.0f);
        fclObjStartPosition(work->panels[0x9F].pointer, position21, position22, 2, 7, 5);
        ((FclObject *)fclObjectGetWork(work->panels[0x9F].pointer))->alpha = 0xFF;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x9F].pointer))->pivotX = 0x55;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x9F].pointer))->pivotY = 0x17;
        c15 = fclMakeDrawColor(0xBD, 0x68, 3, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9F].pointer);
        ((FclObject *)objectWork)->color = c15;
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(4));
        fclObjSetAnchorPosition(work->panels[0xA0].pointer, 0x41, 138.0f);
        position23 = fclMakeVec2(186.0f, -60.0f);
        position24 = fclMakeVec2(186.0f, 40.0f);
        fclObjStartPosition(work->panels[0xA0].pointer, position23, position24, 2, 7, 5);
        ((FclObject *)fclObjectGetWork(work->panels[0xA0].pointer))->alpha = 0xFF;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA0].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) - 85.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA0].pointer))->pivotY = 0x17;
        c16 = fclMakeDrawColor(0xBD, 0x68, 3, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA0].pointer);
        ((FclObject *)objectWork)->color = c16;
        sdkSpriteFreeNode(sprite);
    }
    fclObjSetAnchorPosition(work->panels[0x23].pointer, 0x56, 136.0f);
    position25 = fclMakeVec2(188.0f, -60.0f);
    position26 = fclMakeVec2(188.0f, 51.0f);
    fclObjStartPosition(work->panels[0x23].pointer, position25, position26, 2, 7, 5);
    ((FclObject *)fclObjectGetWork(work->panels[0x23].pointer))->alpha = 0xFF;
    c17 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x23].pointer);
    ((FclObject *)objectWork)->color = c17;
    if (yListCountFor(work->lists[1]) <= D_00748908[1]) {
        c18 = fclMakeDrawColor(0, 0, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x9F].pointer);
        ((FclObject *)objectWork)->color = c18;
        c19 = fclMakeDrawColor(0, 0, 0, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA0].pointer);
        ((FclObject *)objectWork)->color = c19;
        c20 = fclMakeDrawColor(0x6F, 0x6F, 0x6F, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x23].pointer);
        ((FclObject *)objectWork)->color = c20;
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(3));
        fclObjSetAnchorPosition(work->panels[0xA1].pointer, 0x56, 134.0f);
        position27 = fclMakeVec2(268.0f, -60.0f);
        position28 = fclMakeVec2(268.0f, 48.0f);
        fclObjStartPosition(work->panels[0xA1].pointer, position27, position28, 2, 7, 5);
        ((FclObject *)fclObjectGetWork(work->panels[0xA1].pointer))->alpha = 0xFF;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA1].pointer))->pivotX = 0x55;
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA1].pointer))->pivotY = 0x17;
        c21 = fclMakeDrawColor(0x90, 0x4F, 1, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA1].pointer);
        ((FclObject *)objectWork)->color = c21;
        sdkSpriteFreeNode(sprite);
    }
    {
        void *sprite = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(4));
        fclObjSetAnchorPosition(work->panels[0xA2].pointer, 0x56, 135.0f);
        position29 = fclMakeVec2(308.0f, -60.0f);
        position30 = fclMakeVec2(308.0f, 48.0f);
        fclObjStartPosition(work->panels[0xA2].pointer, position29, position30, 2, 7, 5);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA2].pointer))->pivotX = (s16)(sdkSpriteScaledWidth(sprite) - 85.0f);
        ((FclShopItemPanel *)fclObjectGetWork(work->panels[0xA2].pointer))->pivotY = 0x17;
        ((FclObject *)fclObjectGetWork(work->panels[0xA2].pointer))->alpha = 0xFF;
        c22 = fclMakeDrawColor(0x90, 0x4F, 1, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA2].pointer);
        ((FclObject *)objectWork)->color = c22;
        sdkSpriteFreeNode(sprite);
    }
    fclObjSetAnchorPosition(work->panels[0x22].pointer, 0x57, 133.0f);
    position31 = fclMakeVec2(288.0f, -60.0f);
    position32 = fclMakeVec2(288.0f, 59.0f);
    fclObjStartPosition(work->panels[0x22].pointer, position31, position32, 2, 7, 5);
    ((FclObject *)fclObjectGetWork(work->panels[0x22].pointer))->alpha = 0xFF;
    ((FclShopItemPanel *)fclObjectGetWork(work->panels[0x22].pointer))->pivotX = 0x23;
    c23 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    objectWork = (u8 *)fclObjectGetWork(work->panels[0x22].pointer);
    ((FclObject *)objectWork)->color = c23;
    if (yListCountFor(work->lists[2]) <= D_00748908[2]) {
        c24 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA1].pointer);
        ((FclObject *)objectWork)->color = c24;
        c25 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0xA2].pointer);
        ((FclObject *)objectWork)->color = c25;
        c26 = fclMakeDrawColor(0x6F, 0x6F, 0x6F, 0xFF);
        objectWork = (u8 *)fclObjectGetWork(work->panels[0x22].pointer);
        ((FclObject *)objectWork)->color = c26;
    }
    fclObjSetAnchorPosition(work->panels[0x69].pointer, 0x57, 49.0f);
    fclObjStartAlpha(work->panels[0x69].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    fclObjSetAnchorPosition(work->panels[0x6C].pointer, 0x57, 46.0f);
    fclObjStartAlpha(work->panels[0x6C].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    position33 = fclMakeVec2(196.0f, 404.0f);
    position34 = fclMakeVec2(196.0f, 404.0f);
    fclObjStartPosition(work->panels[0x6C].pointer, position33, position34, 0, 0, 0);
    fclObjSetAnchorPosition(work->panels[0x6E].pointer, 0x57, 47.0f);
    fclObjStartAlpha(work->panels[0x6E].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    position35 = fclMakeVec2((f32) 0x103, 404.0f);
    position36 = fclMakeVec2((f32) 0x103, 404.0f);
    fclObjStartPosition(work->panels[0x6E].pointer, position35, position36, 0, 0, 0);
    fclObjSetAnchorPosition(work->panels[0x6B].pointer, 0x57, 47.0f);
    fclObjStartAlpha(work->panels[0x6B].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    position37 = fclMakeVec2(338.0f, 404.0f);
    position38 = fclMakeVec2(338.0f, 404.0f);
    fclObjStartPosition(work->panels[0x6B].pointer, position37, position38, 0, 0, 0);
    fclObjSetAnchorPosition(work->panels[0x6A].pointer, 0x57, 47.0f);
    fclObjStartAlpha(work->panels[0x6A].pointer, 0U, 0xFFU, 0U, 0xA, 0);
    position39 = fclMakeVec2(338.0f, 404.0f);
    position40 = fclMakeVec2(338.0f, 404.0f);
    fclObjStartPosition(work->panels[0x6A].pointer, position39, position40, 0, 0, 0);
    fclObjChangeFlagBit(work->panels[0x6A].pointer, 0, 1);
    fclObjSetAnchorPosition(work->panels[0x65].pointer, 0x41, 123.0f);
    fclObjStartAlpha(work->panels[0x65].pointer, 0U, 0xFFU, 0U, 6, 7);
    fclObjSetAnchorPosition(work->panels[0x66].pointer, 0x41, 125.0f);
    fclObjStartAlpha(work->panels[0x66].pointer, 0U, 0xFFU, 0U, 6, 7);
    work->tab = 0;
    work->cursor = 0;
    work->scroll = 0;
    ((FclShopWork *)work)->state = 0x24;
}
/* Position the three decorative background panels and start the large panel's repeating 360-unit tween. */
// FUN_002DD230
void fclShopLayoutPanels(void *task) {
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    void *objectWork;

    objectWork = fclObjectGetWork(work->panels[0x56].pointer);
    position = fclMakeVec2(311.0f, -17.0f);
    fclObjStartPosition(work->panels[0x56].pointer, ((FclObject *)objectWork)->anchorPosition, position, 0, 0xA, 0);
    objectWork = fclObjectGetWork(work->panels[0x57].pointer);
    position2 = fclMakeVec2(564.0f, -17.0f);
    fclObjStartPosition(work->panels[0x57].pointer, ((FclObject *)objectWork)->anchorPosition, position2, 0, 0xA, 0);
    objectWork = fclObjectGetWork(work->panels[0x55].pointer);
    position3 = fclMakeVec2(-610.0f, -620.0f);
    fclObjStartPosition(work->panels[0x55].pointer, ((FclObject *)objectWork)->anchorPosition, position3, 0, 0xA, 0);
    fclObjChangeFlagBit(work->panels[0x55].pointer, 3, 1);
    fclObjStartTween(work->panels[0x55].pointer, 0.0f, 360.0f, 0, 0x708, 0);
    fclObjChangeFlagBit(work->panels[0x55].pointer, 6, 0);
}

/* A stat number drawn at a precomputed position.  Retail calls the stat
   getter twice per number and uses only the second result (masked); `raw`
   keeps the first call.  Nesting shopDrawStat puts its fclMakeVec2 and
   colour temporaries below all four position-parameter copies, as in
   retail. */
static inline void shopDrawStatAt(u32 raw, u32 value, Vec2f pos)
{
    shopDrawStat(value, pos.x, pos.y);
}

/* measured: MATCH, window 1148 words/4592B.  Written with the
   func_002d5040/fclShopDrawItemCompare levers (Vec2f constructor and colour calls as
   arguments, inlined label and stat helpers).  The prototype set this needs
   is one consistent contract: the item-table getters (func_001068b0,
   func_001068e0, func_00106940, func_00106970, func_00106600, datItemValue)
   take int, as retail passes the int item id to them unextended, and
   func_00106cd0 returns int; call sites that retail narrows (the
   datItemPrice argument here, the func_00106cd0 results in
   func_002d5040/fclShopDrawItemCompare) carry an explicit (s16).  The slot pointer is
   indexed as ((FclShopWork *)work)->lists[(kind)], which gives retail's
   `addu idx, idx, work`.  The outer dispatch is a switch written 1, 2, 0
   (retail tests 0, 2, 1); the inner one owns jtbl_007489F0 (cases 20-28). */
/* Draw the expanded sale-item description, stats and proportional scroll thumb; do nothing outside detail mode. */
/* measured: the earlier native task-work trial was 4596B versus the 4592B
 * window. Keeping the byte cursor and adding a field-only typed local
 * preserves MATCH for every shop field and list-array access here. */
// FUN_002DD3B0
void fclShopDrawScrollThumb(void *task) {
    u8 *work;
    s16 itemId;
    s16 dashIndex;
    u32 unitProceeds;
    f32 y;
    FclShopWork *shopWork;

    work = ((struct KwlnTask *)task)->work;
    shopWork = (FclShopWork *)work;
    if (((FclShopWork *)work)->detailMode == 0) {
        return;
    }
    if (yListCountFor((&shopWork->lists[0])[((FclShopWork *)work)->tab]) >= 2) {
        if (shopWork->tab == 0) {
            if (yListCountFor((&shopWork->lists[0])[shopWork->tab]) >= 3) {
                ((FclShopWork *)work)->scrollStep = 91.0f / (f32)(yListCountFor((&shopWork->lists[0])[shopWork->tab]) - 2);
            } else {
                ((FclShopWork *)work)->scrollStep = 91.0f;
            }
            y = 146.0f + shopWork->scrollStep * (f32)(((FclShopWork *)work)->cursor - 1);
        } else {
            ((FclShopWork *)work)->scrollStep = 91.0f / (f32)(yListCountFor((&shopWork->lists[0])[shopWork->tab]) - 1);
            y = 146.0f + shopWork->scrollStep * (f32)((FclShopWork *)work)->cursor;
        }
        fclDrawEquipSprite(0x36, fclMakeVec2((f32)0x246, y), 88.0f, fclPackRgba(0xFF, 0xFF, 0x6D, 0x31), ((FclObject *)fclObjectGetWork(((FclShopWork *)work)->panels[0x17].pointer))->alpha, 0, D_00794EA0);
        fclObjChangeFlagBit(shopWork->panels[0x17].pointer, 0, 0);
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[0x18].pointer, 0, 0);
    } else {
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[0x17].pointer, 0, 1);
        fclObjChangeFlagBit(((FclShopWork *)work)->panels[0x18].pointer, 0, 1);
    }
    itemId = yListValueAtFor((&shopWork->lists[0])[shopWork->tab], ((FclShopWork *)work)->cursor);
    shopDrawLabel(70.0f, (const char *)((void *)datGetItemNameId(itemId)), fclMakeVec2(129.0f, 134.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    unitProceeds = datItemPrice((s32)itemId) / 5U;
    fclDrawNumber(fclMakeVec2(486.0f, 145.0f), 70.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, unitProceeds, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), ((FclShopWork *)work)->spriteResource.signedWord, 0xA9);
    fclDrawEquipSprite(0x47, fclMakeVec2((f32)0x202, 147.0f), 70.0f, fclPackRgba(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    fclDrawNumber(fclMakeVec2((f32)0x221, 145.0f), 70.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, datItemCount(itemId) & 0xFF, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), shopWork->spriteResource.signedWord, 0xA9);
    if (datItemValue(itemId) == 0) {
        for (dashIndex = 0; dashIndex < 15; dashIndex++) {
            fclDrawEquipSprite(0x3C, fclMakeVec2((f32)(dashIndex * 22 + 111), 178.0f), 86.0f, fclPackRgba(0xFF, 0xFF, 0xC7, 0x31), 0xFF, 0, D_00794ED0);
        }
    } else {
        fclMesWindowDraw(datItemValue(itemId), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0x57, 109.0f, 169.0f, 70.0f);
    }
    switch (shopWork->tab) {
    case 1:
        fclDrawEquipSprite(fclShopStatusFlagToCode((s16)datEntryGetFlags(itemId)) & 0xFFFF, fclMakeVec2(86.0f, 135.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        switch ((s16)fclShopStatusFlagToCode((s16)datEntryGetFlags(itemId))) {
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            fclMesWindowDraw((s16)datItemBankOffset(itemId), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 0, 0x57, 109.0f, 201.0f, 70.0f);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x1A].pointer, 0x57, 83.0f);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x1A].pointer))->color = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x1A].pointer))->anchorPosition = fclMakeVec2((f32)0x1E1, 174.0f);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x1C].pointer, 0x57, 82.0f);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x1C].pointer))->color = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x1C].pointer))->anchorPosition = fclMakeVec2((f32)0x1E1, 224.0f);
            shopDrawStatAt(datEntryGetPrimaryValue(itemId), datEntryGetPrimaryValue(itemId) & 0xFFFF, fclMakeVec2((f32)0x20E, 202.0f));
            shopDrawStatAt(datEntryGetSecondaryValue(itemId), datEntryGetSecondaryValue(itemId) & 0xFFFF, fclMakeVec2((f32)0x20E, 252.0f));
            break;
        case 27:
            fclMesWindowDraw((s16)datItemBankOffset(itemId), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 1, 0x57, 109.0f, 201.0f, 70.0f);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x19].pointer, 0x57, 81.0f);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x19].pointer))->color = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x19].pointer))->anchorPosition = fclMakeVec2((f32)0x1E1, 174.0f);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x1B].pointer, 0x57, 80.0f);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x1B].pointer))->color = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x1B].pointer))->anchorPosition = fclMakeVec2((f32)0x1E1, 224.0f);
            shopDrawStatAt(datEntryGetMiddleBandValue(itemId), datEntryGetMiddleBandValue(itemId) & 0xFFFF, fclMakeVec2((f32)0x20E, 202.0f));
            shopDrawStatAt(datEntryGetLastBandValue(itemId), datEntryGetLastBandValue(itemId) & 0xFFFF, fclMakeVec2((f32)0x20E, 252.0f));
            break;
        case 28:
            fclMesWindowDraw((s16)datItemBankOffset(itemId), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 2, 0x57, 109.0f, 201.0f, 70.0f);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x20].pointer, 0x57, 84.0f);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x20].pointer))->alpha = 0x7F;
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x20].pointer))->anchorPosition = fclMakeVec2(478.0f, 166.0f);
            fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x9D].pointer, 0x57, 84.0f);
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x9D].pointer))->alpha = 0x7F;
            ((FclObject *)fclObjectGetWork(shopWork->panels[0x9D].pointer))->anchorPosition = fclMakeVec2((f32)0x1DD, 216.0f);
            break;
        }
        break;
    case 2:
    case 0:
        if (shopWork->tab == 2) {
            fclDrawEquipHelpSprite(0x1B, fclMakeVec2(86.0f, 135.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            fclMesWindowDraw((s16)datItemBankOffset(itemId), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 4, 0x57, 109.0f, 201.0f, 70.0f);
        } else {
            fclDrawEquipHelpSprite(0x1A, fclMakeVec2(86.0f, 135.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            fclMesWindowDraw((s16)datItemBankOffset(itemId), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 7, 0x57, 109.0f, 201.0f, 70.0f);
        }
        fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x20].pointer, 0x56, 84.0f);
        ((FclObject *)fclObjectGetWork(shopWork->panels[0x20].pointer))->alpha = 0x7F;
        ((FclObject *)fclObjectGetWork(shopWork->panels[0x20].pointer))->anchorPosition = fclMakeVec2(478.0f, 166.0f);
        fclObjSetAnchorPosition(((FclShopWork *)work)->panels[0x9D].pointer, 0x56, 84.0f);
        ((FclObject *)fclObjectGetWork(shopWork->panels[0x9D].pointer))->alpha = 0x7F;
        ((FclObject *)fclObjectGetWork(shopWork->panels[0x9D].pointer))->anchorPosition = fclMakeVec2((f32)0x1DD, 216.0f);
        break;
    }
}

/* measured: MATCH, window 672 words/2688B.  Built on the func_002df020
   levers (Vec2f-returning fclMakeVec2 used as an argument, colour calls
   as arguments, an inlined label call).  What remained was b210's float
   register choice: `size` (70.0f, $f22) and `x` ((f32)0x177, $f21) are
   assigned in both arms of the first dispatch -- two reaching definitions,
   so they are not propagated and survive into the later groups -- and
   `labelSize` ($f20) is set at the first group's label call itself, as the
   last-bound inline argument, then reused by the later groups' labels.
   Written as plain literals, b210 merges the label and `size` 70.0f values
   and keeps neither in a register (567 words); with `labelSize` assigned as
   a statement before the call it loads $f20 before the colour and name
   calls instead of after them (517). */
/* Draw the selected unit's three equipment categories, highlighting the currently active category. */
// FUN_002DE5A0
void fclShopDrawItemCompare(void *task) {
    FclShopWork *work;
    f32 size;
    f32 x;
    f32 labelSize;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    fclDrawEquipSprite(work->unitIcons[work->unitSelection], fclMakeVec2(378.0f, 245.0f), 69.0f, fclPackRgba(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (work->category == 0) {
        size = 70.0f;
        x = (f32)0x177;
        fclDrawEquipSprite(2, fclMakeVec2(x, 243.0f), 70.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(5, fclMakeVec2(420.0f, 246.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize = 70.0f, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0))), fclMakeVec2(420.0f, (f32)0x10F), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    } else {
        size = 70.0f;
        x = (f32)0x177;
        fclDrawEquipSprite(2, fclMakeVec2(x, 243.0f), 70.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(5, fclMakeVec2(420.0f, 246.0f), 69.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize = 70.0f, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 0))), fclMakeVec2(420.0f, (f32)0x10F), fclPackRgba(0xFF, 0xEF, 0x81, 0xFF));
    }
    fclDrawEquipSprite(0x1B, fclMakeVec2(378.0f, (f32)0x12F), 69.0f, fclPackRgba(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (work->category == 1) {
        fclDrawEquipSprite(3, fclMakeVec2(x, (f32)0x12D), size, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(6, fclMakeVec2(420.0f, (f32)0x131), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1))), fclMakeVec2(420.0f, 330.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    } else {
        fclDrawEquipSprite(3, fclMakeVec2(x, (f32)0x12D), size, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(6, fclMakeVec2(420.0f, (f32)0x131), 69.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 1))), fclMakeVec2(420.0f, 330.0f), fclPackRgba(0xFF, 0xEF, 0x81, 0xFF));
    }
    fclDrawEquipSprite(0x1C, fclMakeVec2(378.0f, 368.0f), 69.0f, fclPackRgba(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (work->category == 2) {
        fclDrawEquipSprite(3, fclMakeVec2(x, 366.0f), size, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(7, fclMakeVec2(420.0f, (f32)0x171), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 2))), fclMakeVec2(420.0f, 394.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    } else {
        fclDrawEquipSprite(3, fclMakeVec2(x, 366.0f), size, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(7, fclMakeVec2(420.0f, (f32)0x171), 69.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)datGetEquippedItemByUnit(work->unitIds[work->unitSelection], 2))), fclMakeVec2(420.0f, 394.0f), fclPackRgba(0xFF, 0xEF, 0x81, 0xFF));
    }
}

/* measured: MATCH, window 296 words/1184B.  The levers that closed the old
   219-word floor: (1) the three-way dispatch is a switch written 0,1,2 (b210
   tests the last-written case first, giving retail's beq 2 / beq 1 / beqz 0
   / b join); (2) fclMakeVec2 is a Vec2f-returning constructor used directly
   as an argument, so each position is a compiler temporary -- that is what
   puts `work` in $s1 above the call-result values in $s0 and lays the
   temporaries out below the named `pos`; (3) colours come straight from the
   u8-parameter fclMakeDrawColor as FclDrawColor values (no byte copy), which
   also keeps the lbu 0x62 alpha load in argument-slot order; (4) the
   second counter's base position is the 8-byte gp object uGpffffa888
   (0x00763978); (5) the name goes through the inlined shopDrawLabel, whose
   right-to-left argument binding gives retail's colour / constructor copy /
   name order.
   arg1 is an s16 item id: it is passed unchanged to datEntryGetFlags and
   datGetItemNameId, and widened with (s32) for datItemPrice, which retail
   re-extends. */
// Draw an item's sale quantity, unit proceeds and category icon, plus the list-supplied auxiliary value.
// FUN_002DF020
void fclShopDrawItemDetail(void *task, s16 itemId, s32 auxValue) {
    extern u8 D_0063FAA0[];
    extern Vec2f uGpffffa888;
    FclShopWork *work;
    u32 count;
    Vec2f pos;

    work = (FclShopWork*)((struct KwlnTask *)task)->work;
    switch (work->tab) {
        case 0:
            fclDrawEquipHelpSprite(0x1A, fclMakeVec2(97.0f, 178.0f), 13.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            break;
        case 1:
            fclDrawEquipSprite(fclShopStatusFlagToCode((s16)datEntryGetFlags(itemId)) & 0xFFFF, fclMakeVec2(97.0f, 178.0f), 13.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            break;
        case 2:
            fclDrawEquipHelpSprite(0x1B, fclMakeVec2(97.0f, 178.0f), 13.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            break;
        }
    shopDrawLabel(13.0f, (const char *)((void *)datGetItemNameId(itemId)), fclMakeVec2(140.0f, 178.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    count = datItemPrice((s32)itemId) / 5U;
    fclDrawNumber(fclMakeVec2(448.0f, 185.0f), 13.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, count, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), work->spriteResource.signedWord, 0xA9);
    fclDrawEquipSprite(0x47, fclMakeVec2(476.0f, 187.0f), 13.0f, fclPackRgba(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    pos = uGpffffa888;
    if (work->quantity < 10) {
        pos.x = pos.x - 8.0f;
    }
    fclDrawNumber(pos, 13.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, work->quantity, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), work->spriteResource.signedWord, 0xA9);
    fclDrawNumber(fclMakeVec2((f32)0x1F1, 247.0f), 1.0f, fclMakeDrawColor(0xDF, 0x6C, 0, ((FclObject *)fclObjectGetWork(work->panels[0x24].pointer))->alpha), 0x1B, 0, auxValue & 0xFF, 0x2F, 0, (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xA9);
}

/* Collapse the quantity-popup sprites selected by compact versus expanded detail mode. */
// FUN_002DF4C0
void fclShopStartRevealByMode(void *task) {
    Vec2f position;
    Vec2f position2;
    Vec2f position3;
    Vec2f position4;
    Vec2f position5;
    Vec2f position6;
    Vec2f position7;
    Vec2f position8;
    Vec2f position9;
    Vec2f position10;
    Vec2f position11;
    Vec2f position12;
    Vec2f position13;
    Vec2f position14;
    Vec2f position15;
    Vec2f position16;
    FclShopWork *work = (FclShopWork*)((struct KwlnTask *)task)->work;
    void *r;

    if (work->detailMode == 1) {
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x2B));
        fclObjStartRevealScale(work->panels[0x2B].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        position = fclMakeVec2(67.0f, 140.0f);
        position2 = fclMakeVec2(67.0f, 140.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x2B].pointer, position, position2, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x2B].pointer, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x2C));
        fclObjStartRevealScale(work->panels[0x2C].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        position3 = fclMakeVec2((f32)0x22F, 140.0f);
        position4 = fclMakeVec2((f32)0x22F, 140.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x2C].pointer, position3, position4, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x2C].pointer, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x28));
        fclObjStartRevealScale(work->panels[0x28].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x28].pointer, 0xFF, 0, 0, 5, 0);
        position5 = fclMakeVec2(48.0f, 127.0f);
        position6 = fclMakeVec2(48.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x28].pointer, position5, position6, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x29));
        fclObjStartRevealScale(work->panels[0x29].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x29].pointer, 0xFF, 0, 0, 5, 0);
        position7 = fclMakeVec2(584.0f, 127.0f);
        position8 = fclMakeVec2(584.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x29].pointer, position7, position8, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
    } else {
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x2A));
        fclObjStartRevealScale(work->panels[0x2A].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        position9 = fclMakeVec2(63.0f, 148.0f);
        position10 = fclMakeVec2(63.0f, 148.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x2A].pointer, position9, position10, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x2A].pointer, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x2C));
        fclObjStartRevealScale(work->panels[0x2C].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        position11 = fclMakeVec2((f32)0x222, 148.0f);
        position12 = fclMakeVec2((f32)0x222, 148.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x2C].pointer, position11, position12, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x2C].pointer, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x27));
        fclObjStartRevealScale(work->panels[0x27].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x27].pointer, 0xFF, 0, 0, 5, 0);
        position13 = fclMakeVec2(46.0f, 136.0f);
        position14 = fclMakeVec2(46.0f, 136.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x27].pointer, position13, position14, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->spriteResource.pointer), (u32)(0x29));
        fclObjStartRevealScale(work->panels[0x29].pointer, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->panels[0x29].pointer, 0xFF, 0, 0, 5, 0);
        position15 = fclMakeVec2((f32)0x232, 136.0f);
        position16 = fclMakeVec2((f32)0x232, 136.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->panels[0x29].pointer, position15, position16, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
    }
}

// Returns 1 when item id arg0 is one of the shop's special items (18 fixed ids); else 0.
// FUN_002DFD00
s32 fclShopIsSpecialItem(u16 itemId) {
    if (itemId == 0x540 || itemId == 0x503 || itemId == 0x596 || itemId == 0x517 ||
        itemId == 0x52C || itemId == 0x555 || itemId == 0x54D || itemId == 0x54B ||
        itemId == 0x56A || itemId == 0x519 || itemId == 0x598 || itemId == 0x582 ||
        itemId == 0x599 || itemId == 0x51A || itemId == 0x59A || itemId == 0x580 ||
        itemId == 0x559 || itemId == 0x59B) {
        return 1;
    }
    return 0;
}

// Show the next unlocked-stock message: record 8 for a special item id, otherwise record 7.
// FUN_002DFE00
void fclShopPlayItemCue(void *task) {
    s32 unlockDescriptor;
    s32 unlockIndex;
    u16 itemId;
    u32 messageParameters[2];
    FclShopWork *work = (FclShopWork *)((struct KwlnTask *)task)->work;

    unlockIndex = work->unlockIndex;
    unlockDescriptor = datItemMoonGateFirst(work->unlockedItems[unlockIndex]);
    itemId = (u16)((unlockDescriptor & 0xFFF00) >> 8);
    messageParameters[0] = itemId;
    messageParameters[1] = 0;
    if (fclShopIsSpecialItem(itemId) == 0) {
        work->messageSlot = fclShopPlaySound(task, 7, messageParameters, 0);
    } else {
        work->messageSlot = fclShopPlaySound(task, 8, messageParameters, 0);
    }
}

// Acquire a message slot, set its record and optional string parameters, optionally request refresh, and return the slot.
// FUN_002DFEC0
s32 fclShopPlaySound(void *task, s32 recordId, void *parameters, s8 refresh) {
    s8 handle;
    s32 slot;
    void *messageFile;

    messageFile = ((FclShopWork *)((struct KwlnTask *)task)->work)->loadedFile;
    handle = (s8)nmMesWindowAcquire(((FclShopMessageFile *)messageFile)->messages);
    slot = handle;
    if (parameters != 0) {
        nmMesWindowSetSlotString(handle, 0, parameters);
    }
    nmMesWindowShowSlotRecord(handle, (s16)recordId);
    if (refresh == 1) {
        nmMesWindowSetSlotParam(slot, 0);
        nmMesWindowSetSlotFlag(slot, 0);
        nmMesWindowRequestRefresh();
    }
    return slot;
}

// Show a message with two string parameter sets; refresh == 1 clears its slot controls and requests a refresh. Return the slot.
// FUN_002DFF90
s32 fclShopPlaySoundParams(void *task, s32 recordId, void *parameters, void *extraParameters, s8 refresh) {
    s8 handle;
    s32 slot;
    void *messageFile;

    messageFile = ((FclShopWork *)((struct KwlnTask *)task)->work)->loadedFile;
    handle = (s8)nmMesWindowAcquire(((FclShopMessageFile *)messageFile)->messages);
    slot = handle;
    nmMesWindowSetSlotString(handle, 0, parameters);
    nmMesWindowSetSlotString(handle, 1, extraParameters);
    nmMesWindowShowSlotRecord(handle, (s16)recordId);
    if (refresh == 1) {
        nmMesWindowSetSlotParam(slot, 0);
        nmMesWindowSetSlotFlag(slot, 0);
        nmMesWindowRequestRefresh();
    }
    return slot;
}

// Draw the unit name 77 pixels to the right of position, using the caller's packed color.
// FUN_002E0080
void fclShopDrawItemText(void *task, s8 unitId, Vec2f position, void *color) {
    frFontExDrawTextDeferred(77.0f + position.x, position.y, 1.0f, (s32)(u32)color, 0, 1,
                  (const char *)datPersonaNamePart1(unitId), 8, 0, D_00795E60);
}

// Refresh the 0xF0-byte tween state and submit the panel sprite with its color, scales, pivots and render-layer record.
/* measured: 452B/464B, only three zero-tail words. Canonical byte color and
   opacity parameters preserve constant-first loads and the float-first draw
   argument sequence. Distinct p+4 spellings preserve both retail addresses. */
// FUN_002E0100
s32 fclShopItemPanelUpdate(u8 *task) {
    FclShopItemPanel *work = (FclShopItemPanel*)((struct KwlnTask *)task)->work;

    memcpy((u8 *)work + 4, fclSpriteUpdateTweens(&work->object.spriteFlags), 0xF0);
    if (fclObjTestFlagBit(task, 0) == 1) {
        if (fclObjTestFlagBit(task, 0xD) == 1) {
            void *drawNode = PrimAllocQueueNode();
            ((PrimQueueNode *)drawNode)->callback = fclMiscInitRenderStates;
            ((PrimQueueNode *)drawNode)->argument.handle = 0;
            PrimAppendNode(&D_00793E80[work->object.anchorMode * 0x30], drawNode);
            sdkSpriteDrawQueued(
                work->object.anchorPosition.x, work->object.anchorPosition.y, work->object.anchorValue,
                fclPackRgba(0xFF, work->object.color.c0, work->object.color.c1, work->object.color.c2),
                work->object.alpha,
                work->object.anchorIndex,
                (void *)work->object.spriteResource,
                0,
                work->pivotX,
                work->pivotY,
                work->object.tweenValue,
                work->object.scaleX,
                work->object.scale,
                &D_00793E80[work->object.anchorMode * 0x30]);
        } else {
            sdkSpriteDrawQueued(
                work->object.anchorPosition.x, work->object.anchorPosition.y, work->object.anchorValue,
                fclPackRgba(0xFF, work->object.color.c0, work->object.color.c1, work->object.color.c2),
                work->object.alpha,
                work->object.anchorIndex,
                (void *)work->object.spriteResource,
                1,
                work->pivotX,
                work->pivotY,
                work->object.tweenValue,
                work->object.scaleX,
                work->object.scale,
                &D_00793E80[work->object.anchorMode * 0x30]);
        }
    }
    return 0;
}
// Item panel task destroy: calls the shop work's destroy jump-table entry.
// FUN_002E02D0
void fclShopItemPanelDestroy(u8 *task) {
    jtbl_008873EC[0]((void*)((struct KwlnTask *)task)->work);
}

// Creates the item panel task under arg0 (allocates the 0x104-byte work, registers its update and destroy callbacks, and loads the resource entries for index arg1).
/* The promoted resource index supplies both the table lookup and SDK sprite lookup. */
/* Seed all three keys of each position, alpha, scale, tween and color channel;
 * initialize pivots from the selected sprite's dimensions. */
// FUN_002E0300
/* measured: retail hoists the loop-invariant 0xFF and 1.0f into the preheader. */
#pragma opt_loop_invariants on
s32 fclShopItemPanelCreate(s32 parent, s16 spriteIndex, u32 spriteResource) {
    s32 childTask;
    s32 resourceIndex;
    FclShopItemPanel *panelWork;
    Vec2f *basePosition;
    s16 channelIndex;
    void *sprite;
    chkmemAllocSiteTag(&D_0063FAC0, 0x1D6A);
    panelWork = D_008873F4[0](1, 0x104, 0x40000);
    childTask = (s32)kwlnTaskCreateChild((void *)(parent), (const void *)((char *)&D_0063FB70), 0xF, 0, 0, fclShopItemPanelUpdate, fclShopItemPanelDestroy, (u8 *)(panelWork));
    panelWork->object.unk00[0] = 0;
    panelWork->object.anchorIndex = spriteIndex;
    panelWork->object.spriteResource = spriteResource;
    resourceIndex = spriteIndex;
    basePosition = (Vec2f *)D_0063F560 + resourceIndex;
    for (channelIndex = 0; channelIndex < 3; channelIndex++) {
        panelWork->object.positionKeys[channelIndex].x = basePosition->x;
        panelWork->object.positionKeys[channelIndex].y = basePosition->y;
        panelWork->object.alphaKeys[channelIndex] = 0xFF;
        panelWork->object.scaleYKeys[channelIndex] = 1.0f;
        panelWork->object.scaleXKeys[channelIndex] = 1.0f;
        panelWork->object.tweenKeys[channelIndex] = 0.0f;
        panelWork->object.colorKeys[channelIndex].c2 = 0xFF;
        panelWork->object.colorKeys[channelIndex].c1 = 0xFF;
        panelWork->object.colorKeys[channelIndex].c0 = 0xFF;
    }
    panelWork->object.anchorValue = 100.0f;
    panelWork->object.anchorMode = 0x55;
    panelWork->object.spriteFlags = 0;
    sprite = sdkSpriteNewNode((u32)(panelWork->object.spriteResource), (u32)resourceIndex);
    panelWork->pivotX = (s32)(sdkSpriteScaledWidth(sprite) / 2.0f);
    panelWork->pivotY = (s32)(sdkSpriteScaledHeight(sprite) / 2.0f);
    sdkSpriteFreeNode(sprite);
    return childTask;
}
// measured: closes the opt_loop_invariants bracket opened above and restores
// the -O2 baseline for the rest of the file.
#pragma opt_loop_invariants off

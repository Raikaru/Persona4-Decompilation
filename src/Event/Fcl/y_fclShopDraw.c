#include "fcl_object_internal.h"
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
typedef unsigned int u_long128 __attribute__((mode(TI)));
/* Mes-window slot byte of the shop work (work + 0x10), kept as byte offset. */
static inline s8 *fclShopMesSlot(u8 *work)
{
    return (s8 *)(work + 0x10);
}
/* Loaded-file pointer slot of the shop work (work + 0xF2C), kept as byte offset. */
static inline void **fclShopLoadedFile(u8 *work)
{
    return (void **)(work + 0xF2C);
}
/* Sprite resource handle of the shop work (work + 0xF28): loaded by sdkSpriteRequestLoad. */
static inline s32 *fclShopSpriteResource(u8 *work)
{
    return (s32 *)(work + 0xF28);
}
static inline f32 shopAdd(f32 left, f32 right) { return left + right; }
typedef struct {
    u8 pad0a[2];
    s16 field_2;
    s16 field_4;
    f32 field_8;
    u8 pad1a[5];
    s8 field_11;
    s16 field_12;
    u8 pad1b[0x18];
    f32 field_2C;
    f32 field_30;
    u8 pad2[0x2E];
    u8 field_62;
    u8 pad3[0x16];
    u8 field_79;
    u8 field_7A;
    u8 field_7B;
    u8 pad4[0x18];
    f32 field_94;
    u8 pad5[0x8];
    f32 field_A0;
    u8 pad6[0x20];
    f32 field_C4;
    u8 pad7[0x7];
    u8 field_CF;
    u8 pad8[0x24];
    u32 field_F4;
    s16 field_F8;
    u8 pad9[0x2];
    u32 field_FC;
    s16 field_100;
    s16 field_102;
    u8 padA1a1a[0xB20];
    s8 field_C24;
    u8 padA1a1b[0x1F];
    void *field_C44;
    void *field_C48;
    u8 padA1a2a[0x14];
    void *field_C60;
    void *field_C64;
    u8 padA1a2b[8];
    void *field_C70;
    void *field_C74;
    void *field_C78;
    u8 padA1a2c[4];
    void *field_C80;
    void *field_C84;
    u8 padA1a2d[4];
    void *field_C8C;
    void *field_C90;
    void *field_C94;
    void *field_C98;
    void *field_C9C;
    void *field_CA0;
    void *field_CA4;
    void *field_CA8;
    void *field_CAC;
    void *field_CB0;
    void *field_CB4;
    void *field_CB8;
    void *field_CBC;
    void *field_CC0;
    void *field_CC4;
    void *field_CC8;
    u8 padA2b1[4];
    void *field_CD0;
    void *field_CD4;
    void *field_CD8;
    void *field_CDC;
    void *field_CE0;
    void *field_CE4;
    void *field_CE8;
    u8 padA2b3a[0x80];
    void *field_D6C;
    void *field_D70;
    u8 padA2b3b[8];
    void *field_D7C;
    u8 padA2b3c[0xC];
    void *field_D8C;
    void *field_D90;
    void *field_D94;
    u8 padB1[0x24];
    void *field_DBC[3];
    void *field_DC8;
    u8 padB2a1[4];
    void *field_DD0;
    u8 padB2a2[8];
    void *field_DDC;
    void *field_DE0;
    void *field_DE4;
    u8 padB2b[0x44];
    void *field_E2C;
    void *field_E30;
    u8 padC1[4];
    void *field_E38;
    u8 padC2a[0x14];
    void *field_E50;
    void *field_E54;
    void *field_E58;
    void *field_E5C;
    void *field_E60;
    u8 padD1a1[0x1C];
    void *field_E80;
    void *field_E84;
    u8 padD1a2a[4];
    u8 padD1a2b[8];
    void *field_E94;
    void *field_E98;
    void *field_E9C;
    void *field_EA0;
    void *field_EA4;
    void *field_EA8;
    void *field_EAC;
    void *field_EB0;
    void *field_EB4;
    void *field_EB8;
    void *field_EBC;
    void *field_EC0;
    void *field_EC4;
    void *field_EC8;
    u8 padD1b[8];
    void *field_ED4;
    void *field_ED8;
    void *field_EDC;
    void *field_EE0;
    u8 padD2a[8];
    void *field_EEC;
    void *field_EF0;
    void *field_EF4;
    void *field_EF8;
    void *field_EFC;
    void *field_F00;
    void *field_F04;
    u8 padD2b2[0x10];
    void *field_F18[3];
    u8 padD2b[4];
    void *field_F28;
} ShopWork;

extern void (*jtbl_008873EC[])(void *ptr);
extern void *(*D_008873F4[])(size_t, size_t, u32);
extern u8 D_00795E60[];
extern u8 D_00793E80[];
extern char iGpffffa884[2];
extern u8 D_0063FAC0[];
extern u8 D_0063FB30[];
extern u8 D_0063FB70[];
extern u8 D_0063F560[];
extern u8 D_0063F9F0[];
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

s32 fclShopStateUpdate(u8 *arg0);
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

s16 func_00106cd0(s16, s16);
/* measured: the item getters take s16, as defined in g_data.c (each callee
   re-extends $a0). A value already typed s16 passes raw; fclShopStateUpdate's int
   ids are extended at every call, and an explicit (s32) widening before an s16
   parameter reproduces the single extension retail emits (func_002df020,
   fclShopDrawScrollThumb, fclShopDrawItemCompare, func_002d5040, fclShopListInputStep). */
u32 datEntryGetFlags(s16);
u16 func_001068b0(s16);
u16 func_001068e0(s16);
u16 func_00106940(s16);
u16 func_00106970(s16);
s32 fclDecimalDigitCount(s32);
void fclDrawNumber(Vec2f, f32, FclDrawColor, s32, s16, u32, s32, s32, s32, s32, s32);
u8 *resourceFindByName(char *);
s32 yListValueAtFor(u8 *, s32);
s32 datItemCount(s16 id);
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
extern u16 D_008C024E[];
extern u16 D_008C0276[];
extern u16 D_008C027A[];
extern f32 fGpffff852c;

/* measured: MATCH. Retail builds most positions and colours as struct-return
   temporaries inside the consuming call (fclObjStartPosition(h, fclMakeVec2(..),
   fclMakeVec2(..), ..), *(FclDrawColor *)(.. + 0x79) = fclMakeDrawColor(..)),
   and b210 lays the frame out as named locals, then temporaries in creation
   order, then arrays: the three second-position copies at sp+0x150..0x167 are
   one Vec2f[3] declared ahead of the sprintf buffers. Declaration order of the
   saved-register locals follows the retail registers. */
// FUN_002BE530
s32 fclShopStateUpdate(u8 *arg0)
{
    typedef struct { s32 v0; s32 v1; } ShopArgPair;
    extern void fclShopDrawItemRows(void *, s8, f32, f32);
    extern void fclShopDrawScrollThumb(void *);
    extern s8 fclObjHasStatusFlags(void *);
    extern s32 sdkSndStartStream(s16, s16, s16, s16);
    extern s32 func_0046a750(s32);
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
    extern u8 D_0063F9F0[];
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
    extern void func_00106d40(s16, s16, s16);
    extern s64 calGetDayEntryForMonthDay(s32, s32);
    extern s32 func_002b32a0(s32, s32, s32, s32);
    extern s32 nmMesWindowShowSlotRecordStyle1(s64, s32);
    extern s32 func_002bb1c0(s8);
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
    extern void fclShopPlayItemCue(void *arg0);
    extern s32 fclShopIsSpecialItem(u16 arg0);
    extern void fclShopItemPanelDestroy(u8 *task);
    extern void fclShopSlideInFromLeft(void *arg0);
    extern void fclShopDrawItemList(void *arg0, s8 arg1);
    extern void fclShopDrawBuyList(void *arg0, s8 arg1);
    extern s32 fclShopListInputStep(void *arg0);
    extern void fclShopSlideInFromRight(void *arg0);
    extern s8 fclShopUpdateTabs(void *arg0, s8 arg1);
    extern s32 fclShopStatusFlagToCode(s16 arg0);
    extern void fclShopDrawStats(void *arg0);
    extern void fclShopStartHeaderBars(void *arg0);
    extern void fclShopStartRowPositions(void *arg0);
    extern void fclShopStartSelectionShake(void *arg0);
    extern void fclShopHideSelectionSprites(void *arg0);
    extern void fclShopSlideInFromAbove(void *arg0);
    extern void fclShopStartRevealSprites(void *arg0);
    extern void fclShopLayoutPanels(void *arg0);
    extern void fclShopDrawItemCompare(void *arg0);
    extern void fclShopDrawItemDetail(void *arg0, s16 arg1, s32 arg2);
    extern void fclShopStartRevealByMode(void *arg0);
    extern s32 fclShopItemPanelCreate(s32 arg0, s16 arg1, u32 arg2);
    ShopArgPair sp6A0;
    ShopArgPair sp698;
    ShopArgPair sp690;
    ShopArgPair sp688;
    ShopArgPair sp680;
    ShopArgPair sp678;
    ShopArgPair sp670;
    ShopArgPair sp668;
    Vec2f sp660;
    Vec2f sp658;
    Vec2f sp650;
    Vec2f spP[3];
    char spD0[0x80];
    char spC0[0x10];
    s32 temp_30;
    s32 temp_23_2;
    s32 temp_22_2;
    s32 var_22;
    s32 temp_21_3;
    s32 temp_21_4;
    s32 var_21_2;
    s16 temp_21_5;
    s16 var_21;
    s16 var_21_3;
    s16 var_21_4;
    u32 temp_21_2;
    s32 temp_20;
    s16 var_20;
    s16 var_20_2;
    s16 var_20_3;
    s32 temp_19_8;
    s32 temp_19_3;
    s32 var_19_4;
    s32 temp_19;
    s32 temp_19_11;
    s32 temp_19_2;
    s32 temp_19_5;
    s16 temp_19_7;
    s32 var_19;
    s16 var_19_2;
    s16 var_19_3;
    s16 var_19_5;
    u32 temp_19_4;
    void *temp_19_10;
    void *temp_19_6;
    void *temp_19_9;
    s32 temp_18_52;
    s32 temp_18_53;
    s32 temp_18_57;
    s32 temp_18_51;
    s32 temp_18_54;
    s32 temp_18_55;
    s32 temp_18_56;
    s32 temp_18;
    s32 temp_18_10;
    s32 temp_18_12;
    s32 temp_18_13;
    s32 temp_18_14;
    s32 temp_18_15;
    s32 temp_18_16;
    s32 temp_18_17;
    s32 temp_18_18;
    s32 temp_18_19;
    s32 temp_18_21;
    s32 temp_18_22;
    s32 temp_18_25;
    s32 temp_18_26;
    s32 temp_18_27;
    s32 temp_18_28;
    s32 temp_18_2;
    s32 temp_18_30;
    s32 temp_18_31;
    s16 temp_18_32;
    s32 temp_18_33;
    s32 temp_18_34;
    s32 temp_18_35;
    s32 temp_18_36;
    s32 temp_18_3;
    s32 temp_18_40;
    s32 temp_18_41;
    s32 temp_18_5;
    s32 temp_18_60;
    s32 temp_18_61;
    s32 temp_18_62;
    s32 temp_18_6;
    s32 temp_18_7;
    s32 temp_18_8;
    s32 temp_18_9;
    s16 var_18;
    s16 var_18_2;
    s16 var_18_3;
    s16 var_18_4;
    s16 var_18_5;
    s16 var_18_6;
    u32 temp_18_42;
    u32 temp_18_44;
    u32 temp_18_45;
    u32 temp_18_46;
    u32 temp_18_47;
    u32 temp_18_49;
    void *temp_18_11;
    void *temp_18_20;
    void *temp_18_29;
    f32 *temp_18_37;
    void *temp_18_43;
    void *temp_18_48;
    f32 *temp_18_4;
    void *temp_18_50;
    void *temp_18_58;
    void *temp_18_59;
    f32 *temp_18_63;
    u8 *work;
    u8 temp_3_flag;
    u32 temp_17_2;
    f32 *temp_16_12;
    f32 *temp_16_7;
    s32 temp_16_55;
    s32 temp_16_58;
    s32 temp_16_60;
    s32 temp_16;
    s32 temp_16_2;
    s32 temp_16_83;
    s32 temp_16_85;
    s32 temp_16_86;
    s32 temp_16_91;
    s32 temp_16_93;
    s32 temp_16_39;
    s32 temp_16_43;
    s32 temp_16_44;
    s32 temp_16_4;
    s32 temp_16_52;
    s32 temp_16_57;
    s32 temp_16_59;
    s32 temp_16_5;
    s32 temp_16_65;
    s32 temp_16_6;
    s16 temp_16_74;
    s32 temp_16_75;
    s32 temp_16_76;
    s32 temp_16_78;
    s32 temp_16_79;
    s32 temp_16_81;
    s32 temp_16_82;
    s32 temp_16_87;
    s32 temp_16_94;
    s16 var_16;
    s16 var_16_10;
    s16 var_16_11;
    s16 var_16_12;
    s16 var_16_13;
    s16 var_16_14;
    s16 var_16_15;
    s16 var_16_16;
    s16 var_16_17;
    s16 var_16_18;
    s16 var_16_19;
    s16 var_16_20;
    s16 var_16_21;
    s16 var_16_22;
    s16 var_16_23;
    s16 var_16_24;
    s16 var_16_25;
    s16 var_16_26;
    s16 var_16_2;
    s16 var_16_3;
    s16 var_16_4;
    s16 var_16_5;
    s16 var_16_6;
    s16 var_16_7;
    s16 var_16_8;
    s16 var_16_9;
    s32 temp_16_90;
    s32 temp_16_92;
    u32 temp_16_50;
    u32 temp_16_54;
    u32 temp_16_61;
    u32 temp_16_63;
    u32 temp_16_77;
    u32 temp_16_80;
    u32 temp_16_84;
    void *temp_16_10;
    void *temp_16_11;
    void *temp_16_13;
    void *temp_16_14;
    void *temp_16_15;
    void *temp_16_16;
    void *temp_16_18;
    void *temp_16_19;
    void *temp_16_20;
    void *temp_16_21;
    void *temp_16_22;
    void *temp_16_23;
    void *temp_16_24;
    void *temp_16_25;
    void *temp_16_26;
    void *temp_16_27;
    void *temp_16_28;
    void *temp_16_30;
    void *temp_16_31;
    void *temp_16_32;
    void *temp_16_33;
    void *temp_16_34;
    void *temp_16_35;
    void *temp_16_36;
    void *temp_16_37;
    f32 *temp_16_38;
    f32 *temp_16_3;
    void *temp_16_41;
    void *temp_16_45;
    void *temp_16_46;
    void *temp_16_47;
    void *temp_16_49;
    void *temp_16_51;
    void *temp_16_53;
    void *temp_16_56;
    void *temp_16_62;
    void *temp_16_64;
    void *temp_16_66;
    void *temp_16_67;
    void *temp_16_68;
    void *temp_16_69;
    void *temp_16_70;
    void *temp_16_71;
    void *temp_16_72;
    void *temp_16_73;
    void *temp_16_8;
    void *temp_16_9;
    void **temp_hp;
    f32 *tbl;
    void *pos;
    f32 temp_f0;
    f32 temp_f0_10;
    f32 temp_f0_11;
    f32 temp_f0_12;
    f32 temp_f0_13;
    f32 temp_f0_14;
    f32 temp_f0_15;
    f32 temp_f0_16;
    f32 temp_f0_17;
    f32 temp_f0_18;
    f32 temp_f0_19;
    f32 temp_f0_20;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f0_9;
    f32 temp_f1;
    f32 temp_f20_10;
    f32 temp_f20_11;
    f32 temp_f20_12;
    f32 temp_f20_13;
    f32 temp_f20_14;
    f32 temp_f20_15;
    f32 temp_f20_16;
    f32 temp_f20_17;
    f32 temp_f20_2;
    f32 temp_f20_3;
    f32 temp_f20_4;
    f32 temp_f20_5;
    f32 temp_f20_6;
    f32 temp_f20_7;
    f32 temp_f20_8;
    f32 temp_f20_9;
    f32 temp_f21;
    f32 temp_f20;
    f32 var_f12;
    f32 var_f12_10;
    f32 var_f12_11;
    f32 var_f12_12;
    f32 var_f12_13;
    f32 var_f12_14;
    f32 var_f12_15;
    f32 var_f12_16;
    f32 var_f12_17;
    f32 var_f12_18;
    f32 var_f12_2;
    f32 var_f12_3;
    f32 var_f12_4;
    f32 var_f12_5;
    f32 var_f12_6;
    f32 var_f12_7;
    f32 var_f12_8;
    f32 var_f12_9;
    s32 temp_2_129;
    s32 temp_2_130;
    s32 temp_2_76;
    s32 temp_2_77;
    s32 temp_2_98;
    s32 temp_4_10;
    s32 temp_4_15;
    s32 temp_4_16;
    s32 temp_4_3;
    s32 temp_4_6;
    s32 temp_4_7;
    s32 temp_4_8;
    s32 temp_4_9;
    s32 temp_4_12;
    s32 temp_4_5;
    s32 temp_2_85;
    s32 temp_3_10;
    s32 temp_3_11;
    s32 temp_3_13;
    s32 temp_3_14;
    s32 temp_3_21;
    s32 temp_3_22;
    s32 temp_3_24;
    s32 temp_3_25;
    s32 temp_3_2;
    s32 temp_3_4;
    s32 temp_3_5;
    s32 temp_3_6;
    s32 temp_3_7;
    s32 temp_3_8;
    s32 temp_3_9;
    s32 temp_4;
    s32 temp_4_11;
    s32 temp_4_13;
    s32 temp_4_14;
    s32 temp_4_2;
    s32 temp_4_4;
    s16 var_5;
    s8 temp_2_2;
    s8 temp_2_44;
    s8 temp_2_5;
    s8 temp_2_65;
    s8 temp_2_78;
    s8 temp_2_79;
    s8 temp_2_97;
    s8 temp_3_18;
    s8 temp_3_19;
    s8 var_3;
    s8 var_3_10;
    s8 var_3_11;
    s8 var_3_12;
    s8 var_3_13;
    s8 var_3_14;
    s8 var_3_15;
    s8 var_3_16;
    s8 var_3_17;
    s8 var_3_18;
    s8 var_3_19;
    s8 var_3_20;
    s8 var_3_2;
    s8 var_3_3;
    s8 var_3_6;
    s8 var_3_7;
    s8 var_3_8;
    s8 var_3_9;
    u32 temp_2_yen;
    u8 temp_2_100;
    u8 temp_2_101;
    u8 temp_2_106;
    u8 temp_2_107;
    u8 temp_2_108;
    u8 temp_2_35;
    u8 temp_2_36;
    u8 temp_2_37;
    u8 temp_2_53;
    u8 temp_2_54;
    u8 temp_2_55;
    u8 temp_2_66;
    u8 temp_2_67;
    u8 temp_2_68;
    u8 temp_2_80;
    u8 temp_2_81;
    u8 temp_2_82;
    u8 temp_2_99;
    u8 temp_5_2;
    u8 temp_6;
    u8 var_3_4;
    u8 var_3_5;
    void *temp_2;
    void *temp_2_102;
    void *temp_2_103;
    void *temp_2_104;
    void *temp_2_105;
    void *temp_2_109;
    void *temp_2_10;
    void *temp_2_110;
    void *temp_2_111;
    void *temp_2_112;
    void *temp_2_113;
    void *temp_2_114;
    void *temp_2_115;
    void *temp_2_116;
    void *temp_2_117;
    void *temp_2_118;
    void *temp_2_119;
    void *temp_2_11;
    void *temp_2_120;
    void *temp_2_121;
    void *temp_2_122;
    void *temp_2_123;
    void *temp_2_124;
    void *temp_2_125;
    void *temp_2_126;
    void *temp_2_127;
    void *temp_2_128;
    void *temp_2_12;
    void *temp_2_131;
    void *temp_2_132;
    void *temp_2_133;
    void *temp_2_134;
    void *temp_2_136;
    void *temp_2_13;
    void *temp_2_14;
    void *temp_2_15;
    void *temp_2_16;
    void *temp_2_17;
    void *temp_2_18;
    void *temp_2_19;
    void *temp_2_20;
    void *temp_2_21;
    void *temp_2_22;
    void *temp_2_23;
    void *temp_2_24;
    void *temp_2_25;
    void *temp_2_26;
    void *temp_2_27;
    void *temp_2_28;
    void *temp_2_29;
    void *temp_2_30;
    void *temp_2_31;
    void *temp_2_32;
    void *temp_2_38;
    void *temp_2_39;
    void *temp_2_3;
    void *temp_2_40;
    void *temp_2_41;
    void *temp_2_46;
    void *temp_2_47;
    void *temp_2_48;
    void *temp_2_49;
    void *temp_2_4;
    void *temp_2_51;
    void *temp_2_56;
    void *temp_2_57;
    void *temp_2_58;
    void *temp_2_59;
    void *temp_2_60;
    void *temp_2_61;
    void *temp_2_62;
    void *temp_2_63;
    void *temp_2_64;
    void *temp_2_69;
    void *temp_2_6;
    void *temp_2_70;
    void *temp_2_71;
    void *temp_2_72;
    void *temp_2_73;
    void *temp_2_74;
    void *temp_2_75;
    void *temp_2_7;
    void *temp_2_83;
    void *temp_2_84;
    void *temp_2_86;
    void *temp_2_87;
    void *temp_2_88;
    void *temp_2_89;
    void *temp_2_8;
    void *temp_2_90;
    void *temp_2_91;
    void *temp_2_92;
    void *temp_2_93;
    void *temp_2_94;
    void *temp_2_95;
    void *temp_2_96;

    work = (*(void * *)(arg0 + 0x38));
    var_19 = 0;
    temp_2 = PrimAllocQueueNode();
    (*(void * *)((u8 *)temp_2 + 8)) = fclDrawMoneyDisplay;
    (*(void * *)((u8 *)temp_2 + 0x10)) = work;
    PrimAppendNode(D_00795FE0, temp_2);
    temp_2_2 = (*(s8 *)(work + 0));
    switch (temp_2_2) {                             /* switch 1 */
    case 0x9:                                       /* switch 1 */
        (*fclShopSpriteResource(work)) = sdkSpriteRequestLoad(&D_0063FAA0);
        func_00440b68(iGpffffa878, D_0063FAC0, 0x147);
        (*fclShopLoadedFile(work)) = H_Cdvd_AcquireDirectory(D_0063FAD0, 0);
        (*(s8 *)(work + 0)) = 0xA;
        /* fallthrough */
    case 0xA:                                       /* switch 1 */
        if ((func_0046a750((*fclShopSpriteResource(work))) != 0) && (H_Cdvd_IsFileLoaded((*fclShopLoadedFile(work))) != 0)) {
            (*(s8 *)(work + 0)) = 0xB;
            (*(s8 *)(work + 0xF30)) = 1;
            for (var_16 = 0; var_16 < 0x91; var_16++) {
                (*(s32 *)((u8 *)((work + (var_16 * 4))) + 0xC38)) = fclShopItemPanelCreate((s32) arg0, var_16, (*(u32 *)(work + 0xF28)));
            }
            (*(s32 *)(work + 0xE7C)) = fclShopItemPanelCreate((s32) arg0, 6, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xE80)) = fclShopItemPanelCreate((s32) arg0, 0xA, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xE84)) = fclShopItemPanelCreate((s32) arg0, 0x1D, (*(u32 *)(work + 0xF28)));
            for (var_16_2 = 0; var_16_2 < 3; var_16_2++) {
                (*(s32 *)((u8 *)((work + (var_16_2 * 4))) + 0xE88)) = fclShopItemPanelCreate((s32) arg0, (s16) ((s16) ((var_16_2 + 0x61))), (*(u32 *)(work + 0xF28)));
            }
            for (var_16_3 = 0; var_16_3 < 4; var_16_3++) {
                (*(s32 *)((u8 *)((work + (var_16_3 * 4))) + 0xE94)) = fclShopItemPanelCreate((s32) arg0, (s16) ((s16) ((var_16_3 + 0x19))), (*(u32 *)(work + 0xF28)));
            }
            (*(s32 *)(work + 0xEA4)) = fclShopItemPanelCreate((s32) arg0, 0x1D, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEA8)) = fclShopItemPanelCreate((s32) arg0, 0x1D, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEAC)) = fclShopItemPanelCreate((s32) arg0, 0x20, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEB0)) = fclShopItemPanelCreate((s32) arg0, 0x21, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEB4)) = fclShopItemPanelCreate((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEB8)) = fclShopItemPanelCreate((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEBC)) = fclShopItemPanelCreate((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEC0)) = fclShopItemPanelCreate((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEC4)) = fclShopItemPanelCreate((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEC8)) = fclShopItemPanelCreate((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xED4)) = fclShopItemPanelCreate((s32) arg0, 3, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xED8)) = fclShopItemPanelCreate((s32) arg0, 4, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xECC)) = fclShopItemPanelCreate((s32) arg0, 5, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEDC)) = fclShopItemPanelCreate((s32) arg0, 0x2B, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEE0)) = fclShopItemPanelCreate((s32) arg0, 0x2C, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xED0)) = fclShopItemPanelCreate((s32) arg0, 0x5F, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF14)) = fclShopItemPanelCreate((s32) arg0, 0x5F, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEE4)) = fclShopItemPanelCreate((s32) arg0, 0x65, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEE8)) = fclShopItemPanelCreate((s32) arg0, 0x66, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEEC)) = fclShopItemPanelCreate((s32) arg0, 0xA, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEF0)) = fclShopItemPanelCreate((s32) arg0, 0xA, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEF4)) = fclShopItemPanelCreate((s32) arg0, 0x12, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEF8)) = fclShopItemPanelCreate((s32) arg0, 0xE, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xEFC)) = fclShopItemPanelCreate((s32) arg0, 0x13, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF00)) = fclShopItemPanelCreate((s32) arg0, 0xF, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF04)) = fclShopItemPanelCreate((s32) arg0, 0x10, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF08)) = fclShopItemPanelCreate((s32) arg0, 0x8C, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF0C)) = fclShopItemPanelCreate((s32) arg0, 0x8D, (*(u32 *)(work + 0xF28)));
            (*(s32 *)(work + 0xF10)) = fclShopItemPanelCreate((s32) arg0, 0x8E, (*(u32 *)(work + 0xF28)));
            temp_2_3 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x48));
            temp_f21 = 632.0f + sdkSpriteScaledWidth(temp_2_3);
            sdkSpriteFreeNode(temp_2_3);
            temp_2_4 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x47));
            temp_f20 = 136.0f + sdkSpriteScaledHeight(temp_2_4);
            sdkSpriteFreeNode(temp_2_4);
            temp_f1 = (f32) 0x1A3;
            (*(f32 *)(work + 0xF34)) = (f32) (temp_f1 + ((temp_f21 - temp_f1) / 2.0f));
            (*(f32 *)(work + 0xF38)) = (f32) (65.0f + ((temp_f20 - 65.0f) / 2.0f));
            (*(s8 *)(work + 0xF73)) = 1;
            (*(s8 *)(work + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0(1, 0)))));
            (*(s8 *)(work + 9)) = 1;
            if (datGetFlag(0x30) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 2;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (datGetFlag(0x31) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 3;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (datGetFlag(0x32) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 4;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (datGetFlag(0x33) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 6;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (datGetFlag(0x35) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 8;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            if (datGetFlag(0x36) != 0) {
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)) = 7;
                (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF7C)) = fclShopStatusFlagToCode((s16) ((s16) (datEntryGetFlags(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 9)) + (u32)work)) + 0xF73)), 0)))));
                (*(s8 *)(work + 9)) = (s8) ((*(s8 *)(work + 9)) + 1);
            }
            for (var_5 = 0; var_5 < 9; var_5++) {
                (*(s16 *)(work + (var_5 * 2) + 0xF46)) = (s16) (var_5 * 3);
                (*(s16 *)(work + (var_5 * 2) + 0xF58)) = 0;
                (*(s8 *)((u8 *)((work + var_5)) + 0xF6A)) = 0;
            }
            (*(s8 *)(work + 8)) = 0;
        }
        break;
    case 0xC:                                       /* switch 1 */
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            datSetFlag(0x1324, 1);
            (*(s8 *)(work + 0)) = 0xD;
        }
        break;
    case 0xD:                                       /* switch 1 */
        if ((yListCountFor((*(void * *)(work + 0xF18))) > D_00748908[0]) && (datGetFlag(0x1324) == 0)) {
            (*fclShopMesSlot(work)) = nmMesWindowAcquire((*(void * *)((u8 *)((*fclShopLoadedFile(work))) + 0x110)));
            nmMesWindowShowSlotRecordStyle1((*fclShopMesSlot(work)), 0xB);
            (*(s8 *)(work + 0)) = 0xC;
            return 0;
        }
        if (((s8) (calGetDayEntryForMonthDay((fclCalendarMonth() & 0xFF), (u8)fclCalendarDay() & 0xFF))) == 1) {
            temp_3_2 = (s16) ((((u8)fclCalendarDay() & 0xFF) + ((fclCalendarMonth() & 0xFF) * 0x64)));
            if ((temp_3_2 >= 0x190) && (temp_3_2 < 0x207)) {
                (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 0xC, (*(void * *)((u8 *)((*fclShopLoadedFile(work))) + 0x110)), 0);
            } else {
                (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 0xD, (*(void * *)((u8 *)((*fclShopLoadedFile(work))) + 0x110)), 0);
            }
        } else {
            (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 0xC, (*(void * *)((u8 *)((*fclShopLoadedFile(work))) + 0x110)), 0);
        }
        (*(s8 *)(work + 0)) = 0xF;
        break;
    case 0xF:                                       /* switch 1 */
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            (*(s8 *)(work + 0)) = 0xE;
        }
        break;
    case 0xE:                                       /* switch 1 */
        (*(s8 *)(work + 7)) = 0;
        temp_16_3 = (f32 *)(D_0063F9F0 + ((*(s8 *)(work + 7)) * 0xC));
        fclObjSetAnchorPosition((*(void * *)(work + 0xC44)), 0x41, 126.0f);
        temp_f20_2 = temp_16_3[0];
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x2C)) = temp_f20_2;
        temp_f20_3 = temp_16_3[1];
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30)) = temp_f20_3;
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC44))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
        fclObjStartPosition((*(void * *)(work + 0xC44)), fclMakeVec2(temp_16_3[0] - 80.0f, temp_16_3[1]), fclMakeVec2(temp_16_3[0], temp_16_3[1]), 0, 3, (s16) ((s16) (((*(s8 *)(work + 7)) + 1))));
        fclObjStartAlpha((*(void * *)(work + 0xC44)), 0U, 0xFFU, 0U, 3, (s16) (((*(s8 *)(work + 7)) + 1)));
        fclObjSetAnchorPosition((*(void * *)(work + 0xC48)), 0x41, 127.0f);
        temp_f20_4 = temp_16_3[0] + temp_16_3[2];
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x2C)) = temp_f20_4;
        temp_f20_5 = temp_16_3[1];
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30)) = temp_f20_5;
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC48))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
        fclObjStartPosition((*(void * *)(work + 0xC48)), fclMakeVec2((temp_16_3[0] + temp_16_3[2]) - 80.0f, temp_16_3[1]), fclMakeVec2(temp_16_3[0] + temp_16_3[2], temp_16_3[1]), 0, 3, (s16) ((s16) (((*(s8 *)(work + 7)) + 1))));
        fclObjStartAlpha((*(void * *)(work + 0xC48)), 0U, 0xFFU, 0U, 3, (s16) (((*(s8 *)(work + 7)) + 1)));
        fclShopStartSelectionShake(arg0);
        for (var_20 = 0; var_20 < 7; var_20++) {
            temp_18_4 = (f32 *)(D_0063F560 + ((var_20 + 0x3A) * 8));
            fclObjSetAnchorPosition((*(void * *)(work + (var_20 * 4) + 0xD20)), 0x56, (f32) (var_20 + 0x64));
            if (var_20 > 0) {
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + (var_20 * 4) + 0xD20))) + 0x79) = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
            }
            fclObjStartPosition((*(void * *)(work + ((var_20) * 4) + 0xD20)), fclMakeVec2(80.0f + temp_18_4[0], temp_18_4[1]), fclMakeVec2(temp_18_4[0], temp_18_4[1]), 0, 3, var_20);
            fclObjStartAlpha((*(void * *)(work + ((var_20) * 4) + 0xD20)), 0U, 0xFFU, 0U, 3, var_20);
        }
        *(FclDrawColor *)((u8 *)fclObjectGetWork((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))])) + 0x79) = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        fclObjSetAnchorPosition((*(void * *)(work + 0xC3C)), 0x41, 184.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC3C))) + 0x79) = fclMakeDrawColor(0x5A, 0, 2, 0xFF);
        fclObjSetAnchorPosition((*(void * *)(work + 0xC38)), 0x56, 182.0f);
        fclObjSetAnchorPosition((*(void * *)(work + 0xC40)), 0x56, 183.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC40))) + 0x79) = fclMakeDrawColor(0xFE, 0xBE, 0x1E, 0xFF);
        temp_2_13 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(2));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC40)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_13) / 2.0f))));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC40)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_13) / 2.0f))));
        sdkSpriteFreeNode(temp_2_13);
        fclObjStartTween((*(void * *)(work + 0xC40)), -90.0f, -90.0f, 0, 0, 0);
        fclObjSetAnchorPosition((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC4C))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
        temp_2_15 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(5));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_15))));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) ((s16) ((sdkSpriteScaledHeight(temp_2_15))));
        sdkSpriteFreeNode(temp_2_15);
        fclObjStartAlpha((*(void * *)(work + 0xC4C)), 0U, 0xA0U, 0U, 4, 4);
        fclObjStartTween((*(void * *)(work + 0xC4C)), 0.0f, fGpffff8520, 0, 4, 4);
        fclObjStartPosition((*(void * *)(work + 0xC4C)), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
        fclObjSetAnchorPosition((*(void * *)(work + 0xC50)), 0x40, 192.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC50))) + 0x79) = fclMakeDrawColor(0xFF, 0xBE, 0x22, 0xFF);
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x2C)) = 110.0f;
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x30)) = -50.0f;
        temp_2_17 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_17))));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x102)) = 0;
        fclObjStartTween((*(void * *)(work + 0xC50)), -90.0f, fGpffff8524, 0, 4, 0);
        sdkSpriteFreeNode(temp_2_17);
        fclObjStartAlpha((*(void * *)(work + 0xC50)), 0U, 0xFFU, 0U, 4, 0);
        fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
        (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 180.0f;
        (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 30.0f;
        *(FclDrawColor *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C))) + 0x79) = fclMakeDrawColor(0xED, 0x81, 3, 0xFF);
        temp_2_19 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
        (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_19))));
        (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = 0;
        sdkSpriteFreeNode(temp_2_19);
        fclObjStartTween((void *) (*(s32 *)(work + 0xE7C)), -85.0f, fGpffff8528, 0, 4, 2);
        fclObjStartAlpha((void *) (*(s32 *)(work + 0xE7C)), 0U, 0xFFU, 0U, 4, 2);
        fclObjSetAnchorPosition((*(void * *)(work + 0xDE8)), 0x41, 46.0f);
        fclObjStartAlpha((*(void * *)(work + 0xDE8)), 0U, 0xFFU, 0U, 6, 0);
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE8)))) + 0x2C)) = 198.0f;
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE8)))) + 0x30)) = (f32) 0x151;
        fclObjSetAnchorPosition((*(void * *)(work + 0xDEC)), 0x41, 146.0f);
        fclObjStartAlpha((*(void * *)(work + 0xDEC)), 0U, 0xFFU, 0U, 6, 0);
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDEC)))) + 0x2C)) = 216.0f;
        (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDEC)))) + 0x30)) = 368.0f;
        fclObjSetAnchorPosition((*(void * *)(work + 0xD8C)), 0x3F, 207.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xD8C))) + 0x79) = fclMakeDrawColor(0xFF, 0xAE, 0, 0xFF);
        fclObjStartTween((*(void * *)(work + 0xD8C)), 0.0f, 360.0f, 0, 0x708, 0);
        fclObjChangeFlagBit((*(void * *)(work + 0xD8C)), 6, 0);
        fclObjSetAnchorPosition((*(void * *)(work + 0xD90)), 0x3D, 209.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xD90))) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        temp_2_22 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x56));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD90)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_22))));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD90)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_22) / 2.0f))));
        sdkSpriteFreeNode(temp_2_22);
        fclObjStartTween((*(void * *)(work + 0xD90)), 0.0f, 360.0f, 0, 0x5A0, 0);
        fclObjChangeFlagBit((*(void * *)(work + 0xD90)), 6, 0);
        fclObjStartAlpha((*(void * *)(work + 0xD90)), 0U, 0xFFU, 0U, 0xA, 0);
        fclObjSetAnchorPosition((*(void * *)(work + 0xD94)), 0x3D, 210.0f);
        *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xD94))) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        temp_18_11 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x57));
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD94)))) + 0x100)) = 0;
        (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD94)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_18_11) / 2.0f))));
        sdkSpriteFreeNode(temp_18_11);
        fclObjStartTween((*(void * *)(work + 0xD94)), 0.0f, 360.0f, 0, 0x5A0, 0);
        fclObjChangeFlagBit((*(void * *)(work + 0xD94)), 6, 0);
        fclObjStartAlpha((*(void * *)(work + 0xD94)), 0U, 0xFFU, 0U, 0xA, 0);
        for (var_16_4 = 0x59; var_16_4 < 0x60; var_16_4++) {
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)((u8 *)((work + (var_16_4 * 4))) + 0xC38))) + 0x79) = fclMakeDrawColor(0xFF, 0xAE, 0, 0xFF);
        }
        for (var_16_5 = 0x64; var_16_5 < 0x67; var_16_5++) {
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)((u8 *)((work + (var_16_5 * 4))) + 0xC38))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
        }
        (*(s8 *)(work + 0)) = 0x10;
        (*(s16 *)(work + 0xC26)) = 1;
        break;
    case 0x10:                                      /* switch 1 */
        if (D_008C027A[0] & 0x4000) {
            (*(s8 *)(work + 7)) = fclAddClamped((s32) (*(s8 *)(work + 7)), 1, 5, 0, 2);
            fclShopStartSelectionShake(arg0);
            temp_16_7 = (f32 *)(D_0063F9F0 + ((*(s8 *)(work + 7)) * 0xC));
            temp_f20_6 = temp_16_7[0];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x2C)) = temp_f20_6;
            temp_f20_7 = temp_16_7[1];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30)) = temp_f20_7;
            temp_f20_8 = temp_16_7[0] + temp_16_7[2];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x2C)) = temp_f20_8;
            temp_f20_9 = temp_16_7[1];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30)) = temp_f20_9;
            fclObjStartPosition((*(void * *)(work + 0xC44)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC44))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC44))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30))), 1, 2, 0);
            fclObjStartPosition((*(void * *)(work + 0xC48)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC48))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC48))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30))), 1, 2, 0);
            for (var_16_6 = 0; var_16_6 < 6; var_16_6++) {
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)((u8 *)((work + (var_16_6 * 4))) + 0xD24))) + 0x79) = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
            }
            *(FclDrawColor *)((u8 *)fclObjectGetWork((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))])) + 0x79) = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C027A[0] & 0x1000) {
            (*(s8 *)(work + 7)) = fclSubClamped((s32) (*(s8 *)(work + 7)), 1, 0, 5, 2);
            fclShopStartSelectionShake(arg0);
            temp_16_12 = (f32 *)(D_0063F9F0 + ((*(s8 *)(work + 7)) * 0xC));
            temp_f20_10 = temp_16_12[0];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x2C)) = temp_f20_10;
            temp_f20_11 = temp_16_12[1];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30)) = temp_f20_11;
            temp_f20_12 = temp_16_12[0] + temp_16_12[2];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x2C)) = temp_f20_12;
            temp_f20_13 = temp_16_12[1];
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30)) = temp_f20_13;
            fclObjStartPosition((*(void * *)(work + 0xC44)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC44))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC44))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0x30))), 1, 2, 0);
            fclObjStartPosition((*(void * *)(work + 0xC48)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC48))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC48))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0x30))), 1, 2, 0);
            for (var_16_7 = 0; var_16_7 < 6; var_16_7++) {
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)((u8 *)((work + (var_16_7 * 4))) + 0xD24))) + 0x79) = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
            }
            *(FclDrawColor *)((u8 *)fclObjectGetWork((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))])) + 0x79) = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            sdkSndStartStream(0, 0, 0, 0);
        } else if (D_008C024E[0] & 0x40) {
            fclObjStartTween((*(void * *)(work + 0xC44)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC44)))) + 0xC4)), 0.0f, 0, 2, 0);
            fclObjStartTween((*(void * *)(work + 0xC48)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC48)))) + 0xC4)), 0.0f, 0, 2, 0);
            for (var_18 = 0; var_18 < 2; var_18++) {
                (*(u8 *)(work + ((var_18) * 4) + 0xF3E)) = (u8) (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + ((var_18) * 4) + 0xC44)))) + 0x79));
                (*(u8 *)(work + ((var_18) * 4) + 0xF3F)) = (u8) (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + ((var_18) * 4) + 0xC44)))) + 0x7A));
                (*(u8 *)(work + ((var_18) * 4) + 0xF40)) = (u8) (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + ((var_18) * 4) + 0xC44)))) + 0x7B));
            }
            (*(s16 *)(work + 0xF3C)) = 0;
            (*(s8 *)(work + 0)) = 0x12;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            for (var_16_8 = 0; var_16_8 < 7; var_16_8++) {
                fclObjStartAlpha((*(void * *)((u8 *)((work + (var_16_8 * 4))) + 0xD20)), 0xFFU, 0U, 0U, 5, (s16) ((var_16_8 * 2)));
            }
            fclObjStartAlpha((*(void * *)(work + 0xC44)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            fclObjStartAlpha((*(void * *)(work + 0xC48)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            fclObjSetAnchorPosition((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
            temp_2_30 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(5));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_30) / 2.0f))));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_30) / 2.0f))));
            sdkSpriteFreeNode(temp_2_30);
            fclObjStartTween((*(void * *)(work + 0xC4C)), (*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC4C))) + 0xC4)), 5.0f + (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0xC4)), 0, 0xA, 0);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x2C)) = 14.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x30)) = 164.0f;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC50)), 0x40, 192.0f);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x30)) = 130.0f;
            temp_2_31 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_31) / 2.0f))));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_31) / 2.0f))));
            fclObjStartTween((*(void * *)(work + 0xC50)), (*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC50))) + 0xC4)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            sdkSpriteFreeNode(temp_2_31);
            fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
            (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 187.0f;
            temp_2_32 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
            (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_32) / 2.0f))));
            (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_32) / 2.0f))));
            sdkSpriteFreeNode(temp_2_32);
            fclObjStartTween((void *) (*(s32 *)(work + 0xE7C)), (*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C))) + 0xC4)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            for (var_16_9 = 0; var_16_9 < 3; var_16_9++) {
                fclObjStartAlpha((*(void * *)((u8 *)((work + (var_16_9 * 4))) + 0xC38)), 0xFFU, 0U, 0U, 0xA, 0);
            }
            (*(s8 *)(work + 7)) = 5;
            (*(s8 *)(work + 0)) = 0x13;
            sdkSndStartStream(0, 0, 0, 2);
        }
        break;
    case 0x11:                                      /* switch 1 */
        for (var_16_10 = 0x55; var_16_10 < 0x58; var_16_10++) {
            if (((s8) (fclObjTestFlagBit((*(void * *)(work + (var_16_10 * 4) + 0xC38)), 1))) == 0) {
                fclObjChangeFlagBit((*(void * *)(work + (var_16_10 * 4) + 0xC38)), 3, 0);
            }
        }
        for (var_16_11 = 0x59; var_16_11 < 0x60; var_16_11++) {
            if (((s8) (fclObjTestFlagBit((*(void * *)(work + (var_16_11 * 4) + 0xC38)), 1))) == 0) {
                fclObjChangeFlagBit((*(void * *)(work + (var_16_11 * 4) + 0xC38)), 3, 0);
            }
        }
        if ((((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD8C)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD90)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD94)), 1))) == 0)) {
            (*(s8 *)(work + 0)) = 0x10;
        }
        break;
    case 0x12:                                      /* switch 1 */
        for (var_19 = 0; ((s16) (var_19)) < 2; var_19 = (s16) ((var_19 + 1))) {
            temp_16_20 = fclObjectGetWork((*(void * *)(work + (((s16) (var_19)) * 4) + 0xC44)));
            temp_2_35 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3E));
            var_f12 = (f32) temp_2_35;
            (*(s8 *)((u8 *)temp_16_20 + 0x79)) = (u8) fclEaseInterpolate(1, var_f12, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            temp_2_36 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3F));
            var_f12_2 = (f32) temp_2_36;
            (*(s8 *)((u8 *)temp_16_20 + 0x7A)) = (u8) fclEaseInterpolate(1, var_f12_2, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            temp_2_37 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF40));
            var_f12_3 = (f32) temp_2_37;
            (*(s8 *)((u8 *)temp_16_20 + 0x7B)) = (u8) fclEaseInterpolate(1, var_f12_3, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
        }
        temp_4_3 = (*(s16 *)(work + 0xF3C));
        if (temp_4_3 < 6) {
            (*(s16 *)(work + 0xF3C)) = fclAddClamped((s32) temp_4_3, 1, 6, 0, 1);
        } else {
            for (var_16_12 = 0; var_16_12 < 2; var_16_12++) {
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + ((var_16_12) * 4) + 0xC44))) + 0x79) = *(FclDrawColor *)(work + ((var_16_12) * 4) + 0xF3E);
            }
            for (var_16_13 = 0; var_16_13 < 7; var_16_13++) {
                fclObjStartAlpha((*(void * *)((u8 *)((work + (var_16_13 * 4))) + 0xD20)), 0xFFU, 0U, 0U, 5, (s16) ((var_16_13 * 2)));
            }
            fclObjStartAlpha((*(void * *)(work + 0xC44)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            fclObjStartAlpha((*(void * *)(work + 0xC48)), 0xFFU, 0U, 0U, 0, (s16) ((((*(s8 *)(work + 7)) * 2) + 2)));
            fclObjSetAnchorPosition((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
            temp_2_39 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(5));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_39) / 2.0f))));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_39) / 2.0f))));
            sdkSpriteFreeNode(temp_2_39);
            fclObjStartTween((*(void * *)(work + 0xC4C)), (*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC4C))) + 0xC4)), 5.0f + (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0xC4)), 0, 0xA, 0);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x2C)) = 14.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x30)) = 164.0f;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC50)), 0x40, 192.0f);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x30)) = 130.0f;
            temp_2_40 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_40) / 2.0f))));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_40) / 2.0f))));
            fclObjStartTween((*(void * *)(work + 0xC50)), (*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC50))) + 0xC4)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            sdkSpriteFreeNode(temp_2_40);
            fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
            (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 320.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 187.0f;
            temp_2_41 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
            (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) ((s16) (((sdkSpriteScaledWidth(temp_2_41) / 2.0f))));
            (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = (s16) ((s16) (((sdkSpriteScaledHeight(temp_2_41) / 2.0f))));
            sdkSpriteFreeNode(temp_2_41);
            fclObjStartTween((void *) (*(s32 *)(work + 0xE7C)), (*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C))) + 0xC4)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0xC4)) - 5.0f, 0, 0xA, 0);
            if ((*(s8 *)(work + 7)) != 5) {
                pos = fclObjectGetWork((*(void * *)(work + 0xD90)));
                fclObjStartPosition((*(void * *)(work + 0xD90)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(-262.0f, -56.0f), 0, 0xA, 0);
                pos = fclObjectGetWork((*(void * *)(work + 0xD94)));
                fclObjStartPosition((*(void * *)(work + 0xD94)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(-9.0f, -56.0f), 0, 0xA, 0);
                pos = fclObjectGetWork((*(void * *)(work + 0xD8C)));
                fclObjStartPosition((*(void * *)(work + 0xD8C)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(312.0f, -141.0f), 0, 0xA, 0);
                fclObjStartTween((*(void * *)(work + 0xD8C)), 0.0f, 360.0f, 0, 0x708, 0);
                fclObjChangeFlagBit((*(void * *)(work + 0xD8C)), 6, 0);
            }
            for (var_16_14 = 0; var_16_14 < 3; var_16_14++) {
                fclObjStartAlpha((*(void * *)((u8 *)((work + (var_16_14 * 4))) + 0xC38)), 0xFFU, 0U, 0U, 0xA, 0);
            }
            (*(s8 *)(work + 0)) = 0x13;
        }
        break;
    case 0x13:                                      /* switch 1 */
        for (var_16_15 = 0x55; var_16_15 < 0x58; var_16_15++) {
            if (((s8) (fclObjTestFlagBit((*(void * *)(work + (var_16_15 * 4) + 0xC38)), 1))) == 0) {
                fclObjChangeFlagBit((*(void * *)(work + (var_16_15 * 4) + 0xC38)), 3, 0);
            }
        }
        for (var_16_16 = 0x59; var_16_16 < 0x60; var_16_16++) {
            if (((s8) (fclObjTestFlagBit((*(void * *)(work + (var_16_16 * 4) + 0xC38)), 1))) == 0) {
                fclObjChangeFlagBit((*(void * *)(work + (var_16_16 * 4) + 0xC38)), 3, 0);
            }
        }
        if ((((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC4C))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC50))))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD8C)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD90)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD94)), 1))) == 0) && (((s8) (fclObjHasStatusFlags((void *) (*(s32 *)(work + 0xE7C))))) == 0)) {
            fclObjStartTween((*(void * *)(work + 0xC4C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0xC4)), 0.0f, 0, 7, 6);
            pos = fclObjectGetWork((*(void * *)(work + 0xC4C)));
            fclObjStartPosition((*(void * *)(work + 0xC4C)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(-400.0f, 450.0f), 0, 7, 6);
            fclObjStartAlpha((*(void * *)(work + 0xC4C)), 0xFFU, 0U, 0U, 7, 6);
            fclObjStartTween((*(void * *)(work + 0xC50)), (*(f32 *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC50))) + 0xC4)), 30.0f + (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0xC4)), 0, 7, 5);
            pos = fclObjectGetWork((*(void * *)(work + 0xC50)));
            fclObjStartPosition((*(void * *)(work + 0xC50)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(700.0f, (f32) 0x2EE), 0, 7, 5);
            fclObjStartAlpha((*(void * *)(work + 0xC50)), 0xFFU, 0U, 0U, 7, 5);
            pos = fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)));
            fclObjStartPosition((void *) (*(s32 *)(work + 0xE7C)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(700.0f, (f32) 0x2EE), 0, 7, 3);
            fclObjStartTween((void *) (*(s32 *)(work + 0xE7C)), (*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C))) + 0xC4)), 30.0f + (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0xC4)), 0, 7, 3);
            fclObjStartAlpha((void *) (*(s32 *)(work + 0xE7C)), 0xFFU, 0U, 0U, 7, 3);
            temp_2_44 = (*(s8 *)(work + 7));
            switch (temp_2_44) {                    /* switch 2 */
            case 0:                                 /* switch 2 */
            case 1:                                 /* switch 2 */
            case 2:                                 /* switch 2 */
                fclShopSlideInFromAbove(arg0);
                break;
            case 3:                                 /* switch 2 */
                fclShopStartRevealSprites(arg0);
                (*(s32 *)(work + 0xC20)) = 0;
                for (var_16_17 = 1; var_16_17 < yListCountFor((*(void * *)(work + 0xF18))); var_16_17++) {
                    temp_18_32 = yListValueAtFor((*(void * *)(work + 0xF18)), (s32) var_16_17);
                    yListAuxValueAtFor((*(void * *)(work + 0xF18)), (s32) var_16_17);
                    temp_20 = (s16) (temp_18_32);
                    fclAddClamped(clndGetMoonPhase(temp_20) & 0xFF, datItemCount(temp_18_32) & 0xFF, 0xFF, 0, 1);
                    temp_4_5 = (*(s32 *)(work + 0xC20)) + ((datItemPrice(temp_20) / 5U) * (datItemCount(temp_18_32) & 0xFF));
                    (*(s32 *)(work + 0xC20)) = temp_4_5;
                    (*(s32 *)(work + 0xC20)) = fclAddClamped(temp_4_5, 0, 0x98967F, 0, 1);
                }
                break;
            case 4:                                 /* switch 2 */
                fclObjChangeFlagBit((*(void * *)(work + 0xDE8)), 0, 1);
                fclObjChangeFlagBit((*(void * *)(work + 0xDEC)), 0, 1);
                fclObjStartAlpha((*(void * *)(work + 0xD8C)), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((*(void * *)(work + 0xD90)), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((*(void * *)(work + 0xD94)), 0xFFU, 0U, 0U, 0xA, 0);
                weaponShopTalkCreate(arg0);
                (*(s8 *)(work + 0)) = 0x35;
                break;
            case 5:                                 /* switch 2 */
                fclObjChangeFlagBit((*(void * *)(work + 0xDE8)), 0, 1);
                fclObjChangeFlagBit((*(void * *)(work + 0xDEC)), 0, 1);
                fclObjStartAlpha((*(void * *)(work + 0xD8C)), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((*(void * *)(work + 0xD90)), 0xFFU, 0U, 0U, 0xA, 0);
                fclObjStartAlpha((*(void * *)(work + 0xD94)), 0xFFU, 0U, 0U, 0xA, 0);
                (*(s8 *)(work + 0)) = 0x37;
                break;
            }
        }
        break;
    case 0x14:                                      /* switch 1 */
        if (((s8) (fclObjHasStatusFlags((void *) (*(s32 *)(work + 0xED4))))) == 0) {
            fclObjStartPosition((void *) (*(s32 *)(work + 0xED4)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED4))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED4))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30))), 1, 4, 0);
            fclObjStartPosition((void *) (*(s32 *)(work + 0xED8)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED8))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED8))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30))), 1, 4, 0);
            (*(s8 *)(work + 0)) = 0x15;
        }
        /* fallthrough */
    case 0x15:                                      /* switch 1 */
        if (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xD60))))) == 0) {
            fclShopDrawItemCompare(arg0);
        }
        if (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC58))))) == 0) {
            if (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC4C))))) != 0) {
                var_19 = 1;
            }
            if (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC50))))) != 0) {
                var_19 = 1;
            }
            if (((s8) (fclObjHasStatusFlags((void *) (*(s32 *)(work + 0xE7C))))) != 0) {
                var_19 = 1;
            }
            if ((*(s8 *)(work + 0)) == 0x14) {
                var_19 = 1;
            }
            for (var_18_2 = 0; var_18_2 < ((*(s8 *)(work + 9))); var_18_2++) {
                if ((*(s16 *)(work + var_18_2 * 2 + 0xF46)) != 0) {
                    (*(s16 *)(work + var_18_2 * 2 + 0xF46)) = fclSubClamped((*(s16 *)(work + var_18_2 * 2 + 0xF46)), 1, 0, 0, 1);
                    var_19 = 1;
                } else {
                    (*(u8 *)(work + var_18_2 + 0xF6A)) = (u8) fclEaseInterpolate(0, 0.0f, 255.0f, (f32) (*(s16 *)(work + (var_18_2 * 2) + 0xF58)), 6.0f);
                    (*(s16 *)(work + (var_18_2 * 2) + 0xF58)) = fclAddClamped((s32) (*(s16 *)(work + (var_18_2 * 2) + 0xF58)), 1, 6, 0, 1);
                    var_22 = fclPackRgba(0xECU, 0x7FU, 0U, (*(u8 *)(work + var_18_2 + 0xF6A)));
                    if ((*(s8 *)(work + 8)) == var_18_2) {
                        var_22 = fclPackRgba(0x2DU, 0x2DU, 0x2DU, (*(u8 *)(work + var_18_2 + 0xF6A)));
                    }
                    fclShopDrawItemText(arg0, (*(s8 *)(work + var_18_2 + 0xF73)), fclMakeVec2(71.0f,  86.0f + 35.0f * (f32) var_18_2), (void *) var_22);
                }
            }
            if (((s16) (var_19)) == 0) {
                if (D_008C027A[0] & 0x4000) {
                    (*(s8 *)(work + 8)) = fclAddClamped((s32) (*(s8 *)(work + 8)), 1, (*(s8 *)(work + 9)) - 1, 0, 2);
                    fclShopDrawSwingCursor(arg0);
                    temp_f20_14 =  78.0f + 35.0f * (f32) (*(s8 *)(work + 8));
                    (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) = temp_f20_14;
                    (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) = temp_f20_14;
                    fclObjStartPosition((void *) (*(s32 *)(work + 0xED4)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED4))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED4))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30))), 1, 2, 0);
                    fclObjStartPosition((void *) (*(s32 *)(work + 0xED8)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED8))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED8))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30))), 1, 2, 0);
                    sdkSndStartStream(0, 0, 0, 0);
                } else if (D_008C027A[0] & 0x1000) {
                    (*(s8 *)(work + 8)) = fclSubClamped((s32) (*(s8 *)(work + 8)), 1, 0, (*(s8 *)(work + 9)) - 1, 2);
                    fclShopDrawSwingCursor(arg0);
                    temp_f20_15 =  78.0f + 35.0f * (f32) (*(s8 *)(work + 8));
                    (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) = temp_f20_15;
                    (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) = temp_f20_15;
                    fclObjStartPosition((void *) (*(s32 *)(work + 0xED4)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED4))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED4))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0x30))), 1, 2, 0);
                    fclObjStartPosition((void *) (*(s32 *)(work + 0xED8)), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED8))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30)) - 4.0f), fclMakeVec2((*(f32 *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xED8))) + 0x2C)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0x30))), 1, 2, 0);
                    sdkSndStartStream(0, 0, 0, 0);
                } else if (D_008C024E[0] & 0x20) {
                    sdkSndStartStream(0, 0, 0, 2);
                    tbl = (f32 *) D_0063F5A0;
                    fclObjStartPosition((*(void * *)(work + 0xC58)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xC58)), 0xCCU, 0U, 0U, 2, 0);
                    tbl = (f32 *) D_0063F5A8;
                    fclObjStartPosition((*(void * *)(work + 0xC5C)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xC5C)), 0xCCU, 0U, 0U, 2, 0);
                    tbl = (f32 *) D_0063F7B0;
                    fclObjStartPosition((*(void * *)(work + 0xD60)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 400.0f + tbl[1]), 2, 4, 0);
                    tbl = (f32 *) D_0063F7B8;
                    fclObjStartPosition((*(void * *)(work + 0xD64)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 400.0f + tbl[1]), 2, 4, 0);
                    fclObjChangeFlagBit((*(void * *)(work + 0xDE8)), 0, 1);
                    fclObjChangeFlagBit((*(void * *)(work + 0xDF0)), 0, 1);
                    fclObjChangeFlagBit((*(void * *)(work + 0xD3C)), 0, 1);
                    for (var_19_2 = 0; var_19_2 < 6; var_19_2++) {
                        temp_16_38 = (f32 *)(D_0063F560 + ((var_19_2 + 0x43) * 8));
                        fclObjStartPosition((*(void * *)((u8 *)((work + (var_19_2 * 4))) + 0xD44)), fclMakeVec2(temp_16_38[0], temp_16_38[1]), fclMakeVec2(temp_16_38[0], 700.0f), 2, 5, 0);
                    }
                    fclObjChangeFlagBit((void *) (*(s32 *)(work + 0xED4)), 0, 1);
                    fclObjChangeFlagBit((void *) (*(s32 *)(work + 0xED8)), 0, 1);
                    fclShopLayoutPanels(arg0);
                    for (var_16_18 = 0; var_16_18 < 7; var_16_18++) {
                        fclObjChangeFlagBit((*(void * *)((u8 *)((work + (var_16_18 * 4))) + 0xD20)), 0, 0);
                    }
                    fclObjChangeFlagBit((*(void * *)(work + 0xC44)), 0, 0);
                    fclObjChangeFlagBit((*(void * *)(work + 0xC48)), 0, 0);
                    fclObjSetAnchorPosition((*(void * *)(work + 0xDE8)), 0x41, 46.0f);
                    fclObjStartAlpha((*(void * *)(work + 0xDE8)), 0U, 0xFFU, 0U, 6, 0);
                    (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE8)))) + 0x2C)) = 198.0f;
                    (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE8)))) + 0x30)) = (f32) 0x151;
                    fclObjSetAnchorPosition((*(void * *)(work + 0xDEC)), 0x41, 146.0f);
                    fclObjStartAlpha((*(void * *)(work + 0xDEC)), 0U, 0xFFU, 0U, 6, 0);
                    (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDEC)))) + 0x2C)) = 216.0f;
                    (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDEC)))) + 0x30)) = 368.0f;
                    fclObjSetAnchorPosition((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
                    temp_2_46 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(5));
                    (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_46))));
                    (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) ((s16) ((sdkSpriteScaledHeight(temp_2_46))));
                    sdkSpriteFreeNode(temp_2_46);
                    fclObjStartAlpha((*(void * *)(work + 0xC4C)), 0U, 0xCCU, 0U, 4, 4);
                    fclObjStartTween((*(void * *)(work + 0xC4C)), 0.0f, fGpffff8520, 0, 4, 4);
                    fclObjStartPosition((*(void * *)(work + 0xC4C)), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
                    fclObjSetAnchorPosition((*(void * *)(work + 0xC50)), 0x40, 192.0f);
                    (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x2C)) = 110.0f;
                    (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x30)) = -50.0f;
                    temp_2_47 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
                    (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_47))));
                    (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x102)) = 0;
                    fclObjStartTween((*(void * *)(work + 0xC50)), -90.0f, fGpffff8524, 0, 4, 4);
                    fclObjStartAlpha((*(void * *)(work + 0xC50)), 0U, 0xFFU, 0U, 4, 4);
                    sdkSpriteFreeNode(temp_2_47);
                    fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
                    (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 180.0f;
                    (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 30.0f;
                    temp_2_48 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
                    (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_48))));
                    (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = 0;
                    sdkSpriteFreeNode(temp_2_48);
                    fclObjStartTween((void *) (*(s32 *)(work + 0xE7C)), -85.0f, fGpffff8528, 0, 4, 2);
                    fclObjStartAlpha((void *) (*(s32 *)(work + 0xE7C)), 0U, 0xFFU, 0U, 4, 2);
                    for (var_21 = 0; var_21 < 7; var_21++) {
                        temp_18_37 = (f32 *)(D_0063F560 + ((var_21 + 0x3A) * 8));
                        fclObjSetAnchorPosition((*(void * *)(work + (var_21 * 4) + 0xD20)), 0x56, (f32) (var_21 + 0x64));
                        if (var_21 > 0) {
                            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + (var_21 * 4) + 0xD20))) + 0x79) = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
                        }
                        fclObjStartPosition((*(void * *)(work + ((var_21) * 4) + 0xD20)), fclMakeVec2(80.0f + temp_18_37[0], temp_18_37[1]), fclMakeVec2(temp_18_37[0], temp_18_37[1]), 0, 3, var_21);
                        fclObjStartAlpha((*(void * *)(work + ((var_21) * 4) + 0xD20)), 0U, 0xFFU, 0U, 3, var_21);
                    }
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))])) + 0x79) = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    fclObjStartAlpha((*(void * *)(work + 0xC44)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
                    fclObjStartAlpha((*(void * *)(work + 0xC48)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
                    for (var_16_19 = 0; var_16_19 < 3; var_16_19++) {
                        fclObjStartAlpha((*(void * *)((u8 *)((work + (var_16_19 * 4))) + 0xC38)), 0U, 0xFFU, 0U, 0xA, 0);
                    }
                    fclShopStartSelectionShake(arg0);
                    (*(s8 *)(work + 0)) = 0x11;
                } else if (D_008C024E[0] & 0x40) {
                    fclObjStartTween((void *) (*(s32 *)(work + 0xED4)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED4)))) + 0xC4)), 0.0f, 0, 2, 0);
                    fclObjStartTween((void *) (*(s32 *)(work + 0xED8)), (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xED8)))) + 0xC4)), 0.0f, 0, 2, 0);
                    for (var_18_3 = 0; var_18_3 < 2; var_18_3++) {
                        (*(u8 *)(work + ((var_18_3) * 4) + 0xF3E)) = (u8) (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + ((var_18_3) * 4) + 0xED4)))) + 0x79));
                        (*(u8 *)(work + ((var_18_3) * 4) + 0xF3F)) = (u8) (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + ((var_18_3) * 4) + 0xED4)))) + 0x7A));
                        (*(u8 *)(work + ((var_18_3) * 4) + 0xF40)) = (u8) (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + ((var_18_3) * 4) + 0xED4)))) + 0x7B));
                    }
                    (*(s16 *)(work + 0xF3C)) = 0;
                    (*(s8 *)(work + 0)) = 0x16;
                    sdkSndStartStream(0, 0, 0, 1);
                }
            }
        }
        break;
    case 0x16:                                      /* switch 1 */
        fclShopDrawItemCompare(arg0);
        for (var_19 = 0; ((s16) (var_19)) < (*(s8 *)(work + 9)); var_19 = (s16) ((var_19 + 1))) {
            if ((*(s16 *)(work + ((s16) var_19) * 2 + 0xF46)) != 0) {
                (*(s16 *)(work + ((s16) var_19) * 2 + 0xF46)) = fclSubClamped((*(s16 *)(work + ((s16) var_19) * 2 + 0xF46)), 1, 0, 0, 1);
            } else {
                (*(u8 *)(work + ((s16) var_19) + 0xF6A)) = (u8) fclEaseInterpolate(0, 0.0f, 255.0f, (f32) (*(s16 *)(work + (((s16) var_19) * 2) + 0xF58)), 6.0f);
                (*(s16 *)(work + (((s16) var_19) * 2) + 0xF58)) = fclAddClamped((s32) (*(s16 *)(work + (((s16) var_19) * 2) + 0xF58)), 1, 6, 0, 1);
                var_21_2 = fclPackRgba(0xECU, 0x7FU, 0U, (*(u8 *)(work + ((s16) var_19) + 0xF6A)));
                if ((*(s8 *)(work + 8)) == ((s16) var_19)) {
                    var_21_2 = fclPackRgba(0x2DU, 0x2DU, 0x2DU, (*(u8 *)(work + ((s16) var_19) + 0xF6A)));
                }
                fclShopDrawItemText(arg0, (*(s8 *)(work + ((s16) var_19) + 0xF73)), fclMakeVec2(71.0f,  86.0f + 35.0f * (f32) var_19), (void *) var_21_2);
            }
        }
        for (var_19_3 = 0; var_19_3 < 2; var_19_3++) {
            temp_16_41 = fclObjectGetWork((*(void * *)(work + ((var_19_3) * 4) + 0xED4)));
            temp_2_53 = (*(u8 *)(work + ((var_19_3) * 4) + 0xF3E));
            var_f12_4 = (f32) temp_2_53;
            (*(s8 *)((u8 *)temp_16_41 + 0x79)) = (u8) fclEaseInterpolate(1, var_f12_4, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            temp_2_54 = (*(u8 *)(work + ((var_19_3) * 4) + 0xF3F));
            var_f12_5 = (f32) temp_2_54;
            (*(s8 *)((u8 *)temp_16_41 + 0x7A)) = (u8) fclEaseInterpolate(1, var_f12_5, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            temp_2_55 = (*(u8 *)(work + ((var_19_3) * 4) + 0xF40));
            var_f12_6 = (f32) temp_2_55;
            (*(s8 *)((u8 *)temp_16_41 + 0x7B)) = (u8) fclEaseInterpolate(1, var_f12_6, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
        }
        temp_4_8 = (*(s16 *)(work + 0xF3C));
        if (temp_4_8 < 6) {
            (*(s16 *)(work + 0xF3C)) = fclAddClamped((s32) temp_4_8, 1, 6, 0, 1);
        } else {
            for (var_18_4 = 0; var_18_4 < 2; var_18_4++) {
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + ((var_18_4) * 4) + 0xED4))) + 0x79) = *(FclDrawColor *)(work + ((var_18_4) * 4) + 0xF3E);
            }
            tbl = (f32 *) D_0063F7C8;
            fclObjSetAnchorPosition((*(void * *)(work + 0xD6C)), 0x41, 38.0f);
            fclObjStartTween((*(void * *)(work + 0xD6C)), -105.0f, 27.0f, 0, 5, 0);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xD6C))) + 0x79) = fclMakeDrawColor(0x97, 0xF, 0, 0xFF);
            temp_18_40 = (s16) (((173.0f - tbl[0])));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD6C)))) + 0x100)) = (s16) temp_18_40;
            temp_16_43 = (s16) ((((f32) 0x223 - tbl[1])));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD6C)))) + 0x102)) = (s16) temp_16_43;
            tbl = (f32 *) D_0063F780;
            fclObjStartPosition((*(void * *)(work + 0xD48)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(-130.0f, tbl[1] - 50.0f), 0, 7, 3);
            fclObjStartTween((*(void * *)(work + 0xD48)), 0.0f, -20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F778;
            fclObjStartPosition((*(void * *)(work + 0xD44)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0] - 200.0f, -130.0f), 0, 7, 3);
            fclObjStartTween((*(void * *)(work + 0xD44)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F788;
            fclObjStartPosition((*(void * *)(work + 0xD4C)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0] - 40.0f, (f32) 0x226), 0, 7, 3);
            fclObjStartTween((*(void * *)(work + 0xD4C)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F798;
            fclObjStartPosition((*(void * *)(work + 0xD54)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(40.0f + tbl[0], (f32) 0x226), 0, 7, 3);
            fclObjStartTween((*(void * *)(work + 0xD54)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F790;
            fclObjStartPosition((*(void * *)(work + 0xD50)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(40.0f + tbl[0], -150.0f), 0, 7, 3);
            fclObjStartTween((*(void * *)(work + 0xD50)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F7A0;
            fclObjStartPosition((*(void * *)(work + 0xD58)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(40.0f + tbl[0], -200.0f), 0, 7, 3);
            fclObjStartTween((*(void * *)(work + 0xD58)), 0.0f, 20.0f, 0, 7, 3);
            tbl = (f32 *) D_0063F7B0;
            fclObjStartPosition((*(void * *)(work + 0xD60)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2((f32) 0x29E + tbl[0], tbl[1] - 300.0f), 1, 0xA, 3);
            fclObjStartTween((*(void * *)(work + 0xD60)), fGpffff852c, 60.0f, 1, 4, 3);
            tbl = (f32 *) D_0063F7B8;
            fclObjStartPosition((*(void * *)(work + 0xD64)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2((f32) 0x29E + tbl[0], tbl[1] - 300.0f), 1, 4, 3);
            fclObjStartTween((*(void * *)(work + 0xD64)), fGpffff852c, 60.0f, 1, 4, 3);
            tbl = (f32 *) D_0063F5A0;
            fclObjStartPosition((*(void * *)(work + 0xC58)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
            fclObjStartAlpha((*(void * *)(work + 0xC58)), 0xCCU, 0U, 0U, 2, 0);
            tbl = (f32 *) D_0063F5A8;
            fclObjStartPosition((*(void * *)(work + 0xC5C)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 500.0f + tbl[1]), 0, 4, 0);
            fclObjStartAlpha((*(void * *)(work + 0xC5C)), 0xCCU, 0U, 0U, 2, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xD3C)), 0, 1);
            fclObjChangeFlagBit((void *) (*(s32 *)(work + 0xED4)), 0, 1);
            fclObjChangeFlagBit((void *) (*(s32 *)(work + 0xED8)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xDE8)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xDF0)), 0, 1);
            (*(s8 *)(work + 0)) = 0x17;
        }
        break;
    case 0x17:                                      /* switch 1 */
        if (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD6C)), 3))) == 0) {
            fclObjStartTween((*(void * *)(work + 0xD6C)), 27.0f, -14.0f, 0, 3, 0);
            tbl = (f32 *) D_0063F5B8;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC64)), 0x41, 157.0f);
            fclObjStartPosition((*(void * *)(work + 0xC64)), fclMakeVec2(tbl[0], -300.0f + tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 7, 0);
            fclObjStartAlpha((*(void * *)(work + 0xC64)), 0U, 0xCCU, 0U, 7, 0);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC64))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjStartTween((*(void * *)(work + 0xC64)), 0.0f, -4.0f, 0, 0, 0);
            temp_18_41 = (s16) (((320.0f - tbl[0])));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC64)))) + 0x100)) = (s16) temp_18_41;
            temp_16_44 = (s16) (((tbl[1] - 83.0f)));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC64)))) + 0x102)) = (s16) temp_16_44;
            fclObjStartRevealScale((*(void * *)(work + 0xC64)), 1.0f, 1.5f, 1.0f, 1.0f, 0, 0, 0);
            (*(s8 *)(work + 0)) = 0x18;
        }
        break;
    case 0x18:                                      /* switch 1 */
        if (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC64))))) == 0) {
            fclObjSetAnchorPosition((*(void * *)(work + 0xE2C)), 0x41, 152.0f);
            fclObjStartAlpha((*(void * *)(work + 0xE2C)), 0U, 0xCCU, 0U, 5, 0);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xE2C))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjSetAnchorPosition((*(void * *)(work + 0xE30)), 0x41, 152.0f);
            fclObjStartAlpha((*(void * *)(work + 0xE30)), 0U, 0xCCU, 0U, 5, 0);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xE30))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjSetAnchorPosition((*(void * *)(work + 0xD70)), 0x41, 7.0f);
            fclObjStartAlpha((*(void * *)(work + 0xD70)), 0U, 0xFFU, 0U, 0xA, 0);
            *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xD70))) + 0x2C) = fclMakeVec2(46.0f, 294.0f);
            fclObjSetAnchorPosition((*(void * *)(work + 0xD7C)), 0x41, 8.0f);
            fclObjStartAlpha((*(void * *)(work + 0xD7C)), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjSetAnchorPosition((*(void * *)(work + 0xDD8)), 0x41, 45.0f);
            fclObjStartAlpha((*(void * *)(work + 0xDD8)), 0U, 0xFFU, 0U, 6, 0);
            fclObjSetAnchorPosition((*(void * *)(work + 0xDE8)), 0x41, 46.0f);
            fclObjStartAlpha((*(void * *)(work + 0xDE8)), 0U, 0xFFU, 0U, 6, 0);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE8)))) + 0x2C)) = (f32) 0x17F;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE8)))) + 0x30)) = 404.0f;
            fclObjSetAnchorPosition((*(void * *)(work + 0xDF0)), 0x41, 47.0f);
            fclObjStartAlpha((*(void * *)(work + 0xDF0)), 0U, 0xFFU, 0U, 6, 0);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDF0)))) + 0x2C)) = 446.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDF0)))) + 0x30)) = 404.0f;
            fclObjSetAnchorPosition((*(void * *)(work + 0xDE4)), 0x41, 47.0f);
            fclObjStartAlpha((*(void * *)(work + 0xDE4)), 0U, 0xFFU, 0U, 6, 0);
            fclObjSetAnchorPosition((*(void * *)(work + 0xDE0)), 0x41, 47.0f);
            temp_16_45 = fclObjectGetWork((*(void * *)(work + 0xDE4)));
            *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDE0))) + 0x2C) = *(Vec2f *)((u8 *)temp_16_45 + 0x2C);
            (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDE0)))) + 0x62)) = 0xFF;
            fclObjChangeFlagBit((*(void * *)(work + 0xDE0)), 0, 1);
            fclObjSetAnchorPosition((*(void * *)(work + 0xC8C)), 0x41, 139.0f);
            fclObjStartAlpha((*(void * *)(work + 0xC8C)), 0U, 0xFFU, 0U, 6, 0);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC8C))) + 0x79) = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
            fclObjSetAnchorPosition((*(void * *)(work + 0xC90)), 0x41, 140.0f);
            fclObjStartAlpha((*(void * *)(work + 0xC90)), 0U, 0xFFU, 0U, 6, 0);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC90))) + 0x79) = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
            (*(s16 *)(work + 4)) = 0;
            (*(s16 *)(work + 2)) = 0;
            temp_2_65 = (*(s8 *)(work + 7));
            switch (temp_2_65) {                    /* switch 3; irregular */
            case 0:                                 /* switch 3 */
                yListCreate(1 << ((s16) (((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF7C)) - 0x14))), 1 << ((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF73)) + 4), 2, 2);
                break;
            case 1:                                 /* switch 3 */
                yListCreate(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                break;
            case 2:                                 /* switch 3 */
                yListCreate(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                break;
            }
            (*(s8 *)(work + 0)) = 0x1B;
        }
        break;
    case 0x1B:                                      /* switch 1 */
        fclShopDrawItemList(arg0, 0);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        break;
    case 0x1C:                                      /* switch 1 */
        fclShopDrawItemList(arg0, 1);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        for (var_21_3 = 0; var_21_3 < 2; var_21_3++) {
            temp_19_6 = fclObjectGetWork((*(void * *)(work + 0xDC8)));
            temp_18_43 = fclObjectGetWork((*(void * *)(work + 0xDD0)));
            temp_2_66 = (*(u8 *)(work + ((var_21_3) * 4) + 0xF3E));
            var_f12_7 = (f32) temp_2_66;
            temp_f0_9 = fclEaseInterpolate(1, var_f12_7, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_9 = (u8) temp_f0_9;
            (*(s8 *)((u8 *)temp_18_43 + 0x79)) = var_3_9;
            (*(s8 *)((u8 *)temp_19_6 + 0x79)) = var_3_9;
            temp_2_67 = (*(u8 *)(work + ((var_21_3) * 4) + 0xF3F));
            var_f12_8 = (f32) temp_2_67;
            temp_f0_10 = fclEaseInterpolate(1, var_f12_8, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_10 = (u8) temp_f0_10;
            (*(s8 *)((u8 *)temp_18_43 + 0x7A)) = var_3_10;
            (*(s8 *)((u8 *)temp_19_6 + 0x7A)) = var_3_10;
            temp_2_68 = (*(u8 *)(work + ((var_21_3) * 4) + 0xF40));
            var_f12_9 = (f32) temp_2_68;
            temp_f0_11 = fclEaseInterpolate(1, var_f12_9, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_11 = (u8) temp_f0_11;
            (*(s8 *)((u8 *)temp_18_43 + 0x7B)) = var_3_11;
            (*(s8 *)((u8 *)temp_19_6 + 0x7B)) = var_3_11;
        }
        temp_4_9 = (*(s16 *)(work + 0xF3C));
        if (temp_4_9 < 6) {
            (*(s16 *)(work + 0xF3C)) = fclAddClamped((s32) temp_4_9, 1, 6, 0, 1);
        } else {
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDC8))) + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x79) = *(FclDrawColor *)(work + 0xF42);
            sp6A0.v0 = yListValueAt((*(s16 *)(work + 2)));
            sp6A0.v1 = 0;
            (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 1, &sp6A0, 1);
            (*(s8 *)(work + 0)) = 0x1D;
            fclShopStartHeaderBars(arg0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDC8)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xDD0)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 1);
        }
        break;
    case 0x1D:                                      /* switch 1 */
        fclShopDrawStats(arg0);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        fclShopDrawItemText(arg0, (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), fclMakeVec2(51.0f, 48.0f), (void *) fclPackRgba(0xFFU, 0xFFU, 0xFFU, 0xFFU));
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else if (func_002bb1c0((*fclShopMesSlot(work))) == 0) {
            sdkSndStartStream(0, 0, 0, 6);
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            fclAddMoney(fclGetMoney() - datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))));
            sp698.v0 = yListValueAt((*(s16 *)(work + 2)));
            sp698.v1 = 0;
            (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 4, &sp698, 1);
            (*(s8 *)(work + 0)) = 0x1E;
        } else {
            fclShopStartRowPositions(arg0);
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            (*(s8 *)(work + 0)) = 0x1B;
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 0);
        }
        break;
    case 0x1E:                                      /* switch 1 */
        fclShopDrawStats(arg0);
        fclShopDrawItemText(arg0, (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), fclMakeVec2(51.0f, 48.0f), (void *) fclPackRgba(0xFFU, 0xFFU, 0xFFU, 0xFFU));
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            if (func_002bb1c0((*fclShopMesSlot(work))) == 0) {
                sdkSndStartStream(0, 0, 0, 7);
                nmMesWindowDestroySlot((*fclShopMesSlot(work)));
                sp690.v0 = (s32) ((s16) (func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)))));
                sp690.v1 = 0;
                (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 5, &sp690, 1);
                (*(s8 *)(work + 0)) = 0x1F;
            } else {
                nmMesWindowDestroySlot((*fclShopMesSlot(work)));
                datItemSetCount(((s16) (yListValueAt((*(s16 *)(work + 2))))), ((datItemCount((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))) & 0xFF) + 1) & 0xFF);
                (*(s8 *)(work + 0)) = 0x1B;
            }
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 0);
            if (yListCount() > 5) {
                fclObjChangeFlagBit((*(void * *)(work + 0xDC8)), 0, 0);
                fclObjChangeFlagBit((*(void * *)(work + 0xDD0)), 0, 0);
            }
            fclShopStartRowPositions(arg0);
        }
        break;
    case 0x1F:                                      /* switch 1 */
        fclShopDrawStats(arg0);
        fclShopDrawItemList(arg0, 1);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            if (func_002bb1c0((*fclShopMesSlot(work))) == 0) {
                fclAddMoney(fclGetMoney() + (datItemPrice(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)))) >> 2));
                sdkSndStartStream(0, 0, 0, 6);
            } else {
                datItemSetCount(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7))), ((datItemCount(func_00106cd0((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)))) & 0xFF) + 1) & 0xFF);
            }
            func_00106d40((s16) (*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)), (s16) (*(s8 *)(work + 7)), (s16) ((s16) (yListValueAt((*(s16 *)(work + 2))))));
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            (*(s8 *)(work + 0)) = 0x1B;
        }
        break;
    case 0x20:                                      /* switch 1 */
        fclShopDrawItemList(arg0, 1);
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        if ((((s8) (fclObjTestFlagBit((*(void * *)(work + 0xDC8)), 9))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xDD0)), 9))) == 0)) {
            fclObjStartTween((*(void * *)(work + 0xD6C)), -14.0f, 110.0f, 0, 4, 0);
            tbl = (f32 *) D_0063F7D0;
            fclObjStartUniformRevealScale((*(void * *)(work + 0xD70)), 1.0f, 1.5f, 0, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xD70)), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD70)))) + 0x62)), 0U, 0U, 5, 0);
            temp_18_48 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x4E));
            fclObjStartPosition((*(void * *)(work + 0xD70)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0] - 2.5f * (sdkSpriteScaledWidth(temp_18_48) / 10.0f), tbl[1] - 2.5f * (sdkSpriteScaledHeight(temp_18_48) / 10.0f)), 0, 5, 0);
            sdkSpriteFreeNode(temp_18_48);
            fclObjStartAlpha((*(void * *)(work + 0xD7C)), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xD7C)))) + 0x62)), 0U, 0U, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xC8C)), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC8C)))) + 0x62)), 0U, 0U, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xC90)), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC90)))) + 0x62)), 0U, 0U, 5, 0);
            pos = fclObjectGetWork((*(void * *)(work + 0xDC8)));
            temp_f20_16 = (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDC8)))) + 0x2C)) - 1000.0f;
            fclObjStartPosition((*(void * *)(work + 0xDC8)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(temp_f20_16, (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDC8)))) + 0x30))), 2, 3, 0);
            pos = fclObjectGetWork((*(void * *)(work + 0xDD0)));
            temp_f20_17 = (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDD0)))) + 0x2C)) - 1000.0f;
            fclObjStartPosition((*(void * *)(work + 0xDD0)), *(Vec2f *)((u8 *)pos + 0x2C), fclMakeVec2(temp_f20_17, (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xDD0)))) + 0x30))), 2, 3, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDE4)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xDE0)), 0, 0);
            fclObjStartAlpha((*(void * *)(work + 0xC64)), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC64)))) + 0x62)), 0U, 0U, 0xA, 0);
            tbl = (f32 *) D_0063F5B0;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC60)), 0x41, 109.0f);
            fclObjStartPosition((*(void * *)(work + 0xC60)), fclMakeVec2(660.0f + tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC60)))) + 0x62)) = 0xCC;
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC60))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
            tbl = (f32 *) D_0063F5F0;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC80)), 0x41, 109.0f);
            fclObjStartPosition((*(void * *)(work + 0xC80)), fclMakeVec2(660.0f + tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC80)))) + 0x62)) = 0xCC;
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC80))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
            tbl = (f32 *) D_0063F5D0;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC70)), 0x41, 111.0f);
            fclObjStartPosition((*(void * *)(work + 0xC70)), fclMakeVec2(660.0f + tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC70)))) + 0x62)) = 0xCC;
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC70))) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);
            fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE80)), 0x41, 109.0f);
            fclObjStartPosition((void *) (*(s32 *)(work + 0xE80)), fclMakeVec2((f32) -0x266, 242.0f), fclMakeVec2(86.0f, 242.0f), 0, 4, 6);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE80))) + 0x79) = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            tbl = (f32 *) D_0063F5F8;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC84)), 0x41, 112.0f);
            fclObjStartPosition((*(void * *)(work + 0xC84)), fclMakeVec2(tbl[0] - 700.0f, tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC84))) + 0x79) = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            tbl = (f32 *) D_0063F5D8;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC74)), 0x41, 113.0f);
            fclObjStartPosition((*(void * *)(work + 0xC74)), fclMakeVec2(tbl[0] - 700.0f, tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            tbl = (f32 *) D_0063F5E0;
            fclObjSetAnchorPosition((*(void * *)(work + 0xC78)), 0x41, 114.0f);
            fclObjStartPosition((*(void * *)(work + 0xC78)), fclMakeVec2(tbl[0] - 700.0f, tbl[1]), fclMakeVec2(tbl[0], tbl[1]), 0, 4, 6);
            (*(s8 *)(work + 0)) = 0x21;
        }
        break;
    case 0x21:                                      /* switch 1 */
        if (fclShopListInputStep(arg0) == 1) {
            if ((D_008C0276[0] & 0x1000) && ((*(s8 *)(work + 0x14)) == 0)) {
                sdkSndStartStream(0, 0, 0, 0);
                if ((*(s16 *)(work + 2)) == 0) {
                    temp_2_76 = yListLastIndex();
                    (*(s16 *)(work + 2)) = temp_2_76;
                    (*(s16 *)(work + 4)) = fclAddClamped(0, (s32) ((s16) ((s64) temp_2_76)), 4, 0, 1);
                } else {
                    (*(s16 *)(work + 2)) = fclSubClamped((s32) (*(s16 *)(work + 2)), 1, 0, yListCount(), 2);
                    (*(s16 *)(work + 4)) = yListStepIndex((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (yListCount())), 5, -1);
                }
                (*(s8 *)(work + 0x14)) = 1;
                return 0;
            }
            if (D_008C027A[0] & 0x1000) {
                if (yListCount() > 0) {
                    if ((*(s16 *)(work + 2)) != 0) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    (*(s16 *)(work + 2)) = fclSubClamped((s32) (*(s16 *)(work + 2)), 1, 0, 0, 1);
                    (*(s16 *)(work + 4)) = yListStepIndex((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (yListCount())), 5, -1);
                    (*(s8 *)(work + 0x14)) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C0276[0] & 0x4000) && ((*(s8 *)(work + 0x14)) == 0)) {
                sdkSndStartStream(0, 0, 0, 0);
                temp_2_77 = fclAddClamped((s32) (*(s16 *)(work + 2)), 1, yListLastIndex(), 0, 2);
                (*(s16 *)(work + 2)) = temp_2_77;
                if (((s16) ((s64) temp_2_77)) == 0) {
                    (*(s16 *)(work + 4)) = 0;
                } else if (yListLastIndex() >= 5) {
                    (*(s16 *)(work + 4)) = yListStepIndex((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (yListLastIndex())), 5, 1);
                } else {
                    (*(s16 *)(work + 4)) = yListStepIndex((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (yListLastIndex())), (s32) ((s16) (yListCount())), 1);
                }
                (*(s8 *)(work + 0x14)) = 1;
                return 0;
            }
            if (D_008C027A[0] & 0x4000) {
                if (yListCount() > 0) {
                    temp_16_58 = (*(s16 *)(work + 2));
                    if (temp_16_58 != yListLastIndex()) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    (*(s16 *)(work + 2)) = fclAddClamped((s32) (*(s16 *)(work + 2)), 1, yListLastIndex(), 0, 1);
                    if (yListLastIndex() >= 5) {
                        (*(s16 *)(work + 4)) = yListStepIndex((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (yListLastIndex())), 5, 1);
                    } else {
                        (*(s16 *)(work + 4)) = yListStepIndex((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), (s32) ((s16) (yListLastIndex())), (s32) ((s16) (yListCount())), 1);
                    }
                    (*(s8 *)(work + 0x14)) = 1;
                    return 0;
                }
                goto block_368;
            }
            if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
                temp_16_60 = (*(s16 *)(work + 2));
                if (temp_16_60 != yListLastIndex()) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), yListCount(), 5, (s16 *)(work + 2), (s16 *)(work + 4));
            } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
                if ((*(s16 *)(work + 2)) != 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListRetreatCursorScroll((s32) (*(s16 *)(work + 2)), (s32) (*(s16 *)(work + 4)), yListCount(), 5, (s16 *)(work + 2), (s16 *)(work + 4));
            } else if (D_008C027A[0] & 8) {
                (*(s16 *)(work + 2)) = 0;
                (*(s16 *)(work + 4)) = 0;
                (*(s8 *)(work + 8)) = fclAddClamped((s32) (*(s8 *)(work + 8)), 1, (*(s8 *)(work + 9)) - 1, 0, 2);
                temp_2_78 = (*(s8 *)(work + 7));
                switch (temp_2_78) {                /* switch 4; irregular */
                case 0:                             /* switch 4 */
                    yListRebuild(1 << ((s16) (((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF7C)) - 0x14))), 1 << ((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF73)) + 4), 2, 2);
                    break;
                case 1:                             /* switch 4 */
                    yListRebuild(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                case 2:                             /* switch 4 */
                    yListRebuild(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                }
                fclShopSlideInFromLeft(arg0);
                fclShopSlideIndicator(arg0, 0);
                sdkSndStartStream(0, 0, 0, 5);
            } else if (D_008C027A[0] & 4) {
                (*(s16 *)(work + 2)) = 0;
                (*(s16 *)(work + 4)) = 0;
                (*(s8 *)(work + 8)) = fclSubClamped((s32) (*(s8 *)(work + 8)), 1, 0, (*(s8 *)(work + 9)) - 1, 2);
                temp_2_79 = (*(s8 *)(work + 7));
                switch (temp_2_79) {                /* switch 5; irregular */
                case 0:                             /* switch 5 */
                    yListRebuild(1 << ((s16) (((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF7C)) - 0x14))), 1 << ((*(s8 *)((u8 *)((*(s8 *)(work + 8)) + (u32)work) + 0xF73)) + 4), 2, 2);
                    break;
                case 1:                             /* switch 5 */
                    yListRebuild(0x4000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                case 2:                             /* switch 5 */
                    yListRebuild(0x8000, 1 << ((*(s8 *)((u8 *)(((*(s8 *)(work + 8)) + (u32)work)) + 0xF73)) + 4), 2, 2);
                    break;
                }
                fclShopSlideInFromLeft(arg0);
                fclShopSlideIndicator(arg0, 0);
                sdkSndStartStream(0, 0, 0, 5);
            } else if (D_008C024E[0] & 0x20) {
                fclShopSlideInFromRight(arg0);
                (*(s8 *)(work + 0)) = 0x22;
                fclObjStartTween((*(void * *)(work + 0xE2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xE2C)))) + 0xC4)), 0.0f, 0, 2, 0);
                fclObjStartTween((*(void * *)(work + 0xE30)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xE30)))) + 0xC4)), 0.0f, 0, 2, 0);
                sdkSndStartStream(0, 1, 0, 4);
            } else if (D_008C024E[0] & 0x80) {
                fclShopSlideInFromRight(arg0);
                (*(s8 *)(work + 0)) = 0x22;
                fclObjStartTween((*(void * *)(work + 0xE2C)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xE2C)))) + 0xC4)), 0.0f, 0, 2, 0);
                fclObjStartTween((*(void * *)(work + 0xE30)), (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xE30)))) + 0xC4)), 0.0f, 0, 2, 0);
                sdkSndStartStream(0, 1, 0, 4);
            } else if (D_008C024E[0] & 0x40) {
                if (yListCount() > 0) {
                    if ((datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))) <= fclGetMoney()) && ((datItemCount((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))) & 0xFF) < 0x63)) {
                        sp688.v0 = yListValueAt((*(s16 *)(work + 2)));
                        sp688.v1 = 0;
                        (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 1, &sp688, 1);
                        (*(s8 *)(work + 0)) = 0x23;
                        sdkSndStartStream(0, 0, 0, 1);
                    } else {
                        sdkSndStartStream(0, 0, 0, 8);
                    }
                } else {
                    sdkSndStartStream(0, 0, 0, 8);
                }
            }
block_368:
            (*(s8 *)(work + 0x14)) = 0;
            break;
        }
        break;
    case 0x22:                                      /* switch 1 */
        fclDrawNumber(fclMakeVec2((f32) 0x24E, 61.0f), 1.0f, fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF), 0x11, 5, datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))), 0x70, 0x7A, (s32) resourceFindByName((char *)(&D_0063FAA0)), (s32) resourceFindByName((char *)(&D_0063FAA0)), 0xAA);
        fclShopDrawItemList(arg0, 0);
        if ((((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xD70))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xD7C))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC8C))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC90))))) == 0)) {
            (*(s8 *)(work + 0)) = 0x1B;
        }
        break;
    case 0x23:                                      /* switch 1 */
        fclShopListInputStep(arg0);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else if (func_002bb1c0((*fclShopMesSlot(work))) == 0) {
            sdkSndStartStream(0, 0, 0, 6);
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            fclShopSlideInFromRight(arg0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDC8)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xDD0)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 1);
            sp680.v0 = yListValueAt((*(s16 *)(work + 2)));
            sp680.v1 = 0;
            (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 4, &sp680, 1);
            fclShopStartHeaderBars(arg0);
            fclAddMoney(fclGetMoney() - datItemPrice((s16) ((s16) (yListValueAt((*(s16 *)(work + 2)))))));
            (*(s8 *)(work + 0)) = 0x1E;
        } else {
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            (*(s8 *)(work + 0)) = 0x21;
        }
        break;
    case 0x24:                                      /* switch 1 */
        (*(s16 *)(work + 0x12)) = 1;
        if (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC64))))) == 0) {
            fclShopDrawBuyList(arg0, 0);
        }
        break;
    case 0x25:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawScrollThumb(arg0);
        for (var_19 = 0; ((s16) (var_19)) < 2; var_19 = (s16) ((var_19 + 1))) {
            temp_18_50 = fclObjectGetWork((*(void * *)(work + 0xDCC)));
            temp_16_64 = fclObjectGetWork((*(void * *)(work + 0xDD0)));
            temp_2_80 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3E));
            var_f12_10 = (f32) temp_2_80;
            temp_f0_12 = fclEaseInterpolate(1, var_f12_10, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_12 = (u8) temp_f0_12;
            (*(s8 *)((u8 *)temp_16_64 + 0x79)) = var_3_12;
            (*(s8 *)((u8 *)temp_18_50 + 0x79)) = var_3_12;
            temp_2_81 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF3F));
            var_f12_11 = (f32) temp_2_81;
            temp_f0_13 = fclEaseInterpolate(1, var_f12_11, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_13 = (u8) temp_f0_13;
            (*(s8 *)((u8 *)temp_16_64 + 0x7A)) = var_3_13;
            (*(s8 *)((u8 *)temp_18_50 + 0x7A)) = var_3_13;
            temp_2_82 = (*(u8 *)(work + (((s16) (var_19)) * 4) + 0xF40));
            var_f12_12 = (f32) temp_2_82;
            temp_f0_14 = fclEaseInterpolate(1, var_f12_12, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_14 = (u8) temp_f0_14;
            (*(s8 *)((u8 *)temp_16_64 + 0x7B)) = var_3_14;
            (*(s8 *)((u8 *)temp_18_50 + 0x7B)) = var_3_14;
        }
        temp_4_10 = (*(s16 *)(work + 0xF3C));
        if (temp_4_10 < 6) {
            (*(s16 *)(work + 0xF3C)) = fclAddClamped((s32) temp_4_10, 1, 6, 0, 1);
        } else {
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDCC))) + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x79) = *(FclDrawColor *)(work + 0xF42);
            temp_3_18 = (*(s8 *)(work + 0x11));
            if ((temp_3_18 == 0) && ((*(s16 *)(work + 2)) == 0)) {
                var_19_4 = 0;
                for (var_18_5 = 1; var_18_5 < yListCountFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18))); var_18_5++) {
                    temp_2_85 = yListValueAtFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_18_5);
                    var_19_4 += (datItemPrice(temp_2_85) / 5U) * (datItemCount(temp_2_85) & 0xFF);
                }
                sprintf(spD0, iGpffffa880, fclAddClamped(var_19_4, 0, 0x98967F, 0, 1));
                (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 6, spD0, 1);
                (*(s8 *)(work + 0)) = 0x2E;
            } else if (yListCountFor((((void**)(work + 0xF18))[temp_3_18])) > 0) {
                fclObjStartAlpha((*(void * *)(work + 0xDCC)), 0xFFU, 0U, 0U, 5, 0);
                fclObjStartAlpha((*(void * *)(work + 0xDD0)), 0xFFU, 0U, 0U, 5, 0);
                if ((*(s8 *)(work + 0xC24)) == 0) {
                    temp_16_66 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x2A));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCE0)), 0x56, 16.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCE0))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCE0)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCE0)), fclMakeVec2(63.0f, 143.0f + 2.5f * (sdkSpriteScaledHeight(temp_16_66) / 10.0f)), fclMakeVec2(63.0f, 143.0f), 0, 5, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCE0)), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCE0)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_66);
                    temp_16_67 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x2C));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCE8)), 0x56, 18.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCE8))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCE8)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCE8)), fclMakeVec2((f32) 0x222, 143.0f + 2.5f * (sdkSpriteScaledHeight(temp_16_67) / 10.0f)), fclMakeVec2((f32) 0x222, 143.0f), 0, 5, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCE8)), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCE8)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_67);
                    temp_16_68 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x27));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCD4)), 0x41, 20.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCD4))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCD4)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCD4)), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCD4)), fclMakeVec2(46.0f, 132.0f + 2.0f * (sdkSpriteScaledHeight(temp_16_68) / 10.0f)), fclMakeVec2(46.0f, 132.0f), 2, 4, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCD4)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_68);
                    temp_16_69 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x29));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCDC)), 0x41, 21.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCDC))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCDC)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCDC)), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCDC)), fclMakeVec2((f32) 0x232, 132.0f + 2.0f * (sdkSpriteScaledHeight(temp_16_69) / 10.0f)), fclMakeVec2((f32) 0x232, 132.0f), 2, 4, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCDC)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_69);
                } else {
                    temp_16_70 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x2B));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCE4)), 0x56, 16.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCE4))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCE4)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCE4)), fclMakeVec2(67.0f, 140.0f + 2.5f * (sdkSpriteScaledHeight(temp_16_70) / 10.0f)), fclMakeVec2(67.0f, 140.0f), 0, 5, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCE4)), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCE4)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_70);
                    temp_16_71 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x2C));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCE8)), 0x56, 18.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCE8))) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCE8)), 1.0f, 1.0f, 0.5f, 1.0f, 0, 5, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCE8)), fclMakeVec2((f32) 0x22F, 140.0f + 2.5f * (sdkSpriteScaledHeight(temp_16_71) / 10.0f)), fclMakeVec2((f32) 0x22F, 140.0f), 0, 5, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCE8)), 0U, 0xFFU, 0U, 0, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCE8)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_71);
                    temp_16_72 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x28));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCD8)), 0x41, 20.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCD8))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCD8)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCD8)), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCD8)), fclMakeVec2(48.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight(temp_16_72) / 10.0f)), fclMakeVec2(48.0f, 127.0f), 2, 4, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCD8)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_72);
                    temp_16_73 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(0x29));
                    fclObjSetAnchorPosition((*(void * *)(work + 0xCDC)), 0x41, 21.0f);
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCDC))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                    fclObjStartRevealScale((*(void * *)(work + 0xCDC)), 1.0f, 1.0f, fGpffff8170, 1.0f, 2, 4, 0);
                    fclObjStartAlpha((*(void * *)(work + 0xCDC)), 0U, 0xFFU, 0U, 4, 0);
                    fclObjStartPosition((*(void * *)(work + 0xCDC)), fclMakeVec2(584.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight(temp_16_73) / 10.0f)), fclMakeVec2(584.0f, 127.0f), 2, 4, 0);
                    fclObjSetHoldTimer((*(void * *)(work + 0xCDC)), 6.0f, 3);
                    sdkSpriteFreeNode(temp_16_73);
                }
                tbl = (f32 *) D_0063F688;
                fclObjSetAnchorPosition((*(void * *)(work + 0xCCC)), 0x57, 14.0f);
                fclObjStartPosition((*(void * *)(work + 0xCCC)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1] - 7.0f), 1, 0xA, 2);
                fclObjStartAlpha((*(void * *)(work + 0xCCC)), 0U, 0xFFU, 0U, 0xA, 2);
                (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCCC)))) + 0x3B)) = 1;
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCCC))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCCC)))) + 0x85)) = 1;
                tbl = (f32 *) D_0063F690;
                fclObjSetAnchorPosition((*(void * *)(work + 0xCD0)), 0x57, 15.0f);
                fclObjStartPosition((*(void * *)(work + 0xCD0)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 7.0f + tbl[1]), 1, 0xA, 2);
                fclObjStartAlpha((*(void * *)(work + 0xCD0)), 0U, 0xFFU, 0U, 0xA, 2);
                (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCD0)))) + 0x3B)) = 1;
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCD0))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCD0)))) + 0x85)) = 1;
                fclObjSetAnchorPosition((*(void * *)(work + 0xCC8)), 0x57, 15.0f);
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCC8))) + 0x79) = fclMakeDrawColor(0xDF, 0x6C, 0, 0xFF);
                fclObjStartAlpha((*(void * *)(work + 0xCC8)), 0U, 0xFFU, 0U, 4, 2);
                (*(s8 *)(work + 0)) = 0x27;
            }
        }
        break;
    case 0x27:                                      /* switch 1 */
        temp_16_74 = yListValueAtFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2)));
        temp_18_51 = yListAuxValueAtFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2))) & 0xFF;
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawItemDetail(arg0, temp_16_74, temp_18_51);
        fclShopDrawScrollThumb(arg0);
        if (D_008C027A[0] & 0x1000) {
            temp_18_52 = (*(s16 *)(work + 0x12));
            if (temp_18_52 != (datItemCount(temp_16_74) & 0xFF)) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = fclAddClamped((s32) (*(s16 *)(work + 0x12)), 1, datItemCount(temp_16_74) & 0xFF, 1, 1);
            tbl = (f32 *) D_0063F688;
            fclObjStartPosition((*(void * *)(work + 0xCCC)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1] - 7.0f), 1, 0xA, 0);
            (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCCC)))) + 0x85)) = 1;
        } else if (D_008C027A[0] & 0x2000) {
            temp_18_53 = (*(s16 *)(work + 0x12));
            if (temp_18_53 != (datItemCount(temp_16_74) & 0xFF)) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = fclAddClamped((s32) (*(s16 *)(work + 0x12)), 0xA, datItemCount(temp_16_74) & 0xFF, 1, 1);
            tbl = (f32 *) D_0063F688;
            fclObjStartPosition((*(void * *)(work + 0xCCC)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], tbl[1] - 7.0f), 1, 0xA, 0);
            (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCCC)))) + 0x85)) = 1;
        } else if (D_008C027A[0] & 0x4000) {
            if ((*(s16 *)(work + 0x12)) != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = fclSubClamped((s32) (*(s16 *)(work + 0x12)), 1, 1, datItemCount(temp_16_74) & 0xFF, 1);
            tbl = (f32 *) D_0063F690;
            fclObjStartPosition((*(void * *)(work + 0xCD0)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 7.0f + tbl[1]), 1, 0xA, 0);
            (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCD0)))) + 0x85)) = 1;
        } else if (D_008C027A[0] & 0x8000) {
            if ((*(s16 *)(work + 0x12)) != 1) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            (*(s16 *)(work + 0x12)) = fclSubClamped((s32) (*(s16 *)(work + 0x12)), 0xA, 1, datItemCount(temp_16_74) & 0xFF, 1);
            tbl = (f32 *) D_0063F690;
            fclObjStartPosition((*(void * *)(work + 0xCD0)), fclMakeVec2(tbl[0], tbl[1]), fclMakeVec2(tbl[0], 7.0f + tbl[1]), 1, 0xA, 0);
            (*(s8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xCD0)))) + 0x85)) = 1;
        } else if (D_008C024E[0] & 0x40) {
            sp678.v0 = (s32) ((s16) (temp_16_74));
            sp678.v1 = 0;
            sprintf(spC0, iGpffffa880, (*(s16 *)(work + 0x12)));
            (*fclShopMesSlot(work)) = fclShopPlaySoundParams(arg0, 2, &sp678, spC0, 1);
            (*(s8 *)(work + 0)) = 0x28;
            sdkSndStartStream(0, 0, 0, 1);
        } else if (D_008C024E[0] & 0x20) {
            sdkSndStartStream(0, 0, 0, 2);
            fclShopStartRevealByMode(arg0);
            fclObjStartAlpha((*(void * *)(work + 0xCCC)), 0xFFU, 0U, 0U, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xCD0)), 0xFFU, 0U, 0U, 5, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xCC8)), 0, 1);
            fclObjStartAlpha((*(void * *)(work + 0xDCC)), 0U, 0xFFU, 0U, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xDD0)), 0U, 0xFFU, 0U, 5, 0);
            (*(s8 *)(work + 0)) = 0x24;
            if ((*(s8 *)(work + 0xC24)) == 1) {
                (*(s8 *)(work + 0)) = 0x31;
            }
        }
        break;
    case 0x28:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        temp_19_7 = yListValueAtFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2)));
        temp_16_75 = (s16) (yListAuxValueAtFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), (s32) (*(s16 *)(work + 2))));
        temp_18_54 = yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]));
        temp_23_2 = (*(s16 *)(work + 2));
        temp_30 = (*(s16 *)(work + 4));
        fclShopDrawItemDetail(arg0, temp_19_7, temp_16_75 & 0xFF);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            (*(s16 *)(work + 0xC16)) = 0;
            (*(s16 *)(work + 0xC18)) = 0;
            if (func_002bb1c0((*fclShopMesSlot(work))) == 0) {
                sdkSndStartStream(0, 0, 0, 6);
                if (func_00106850(temp_19_7) == 5) {
                    temp_16_76 = (s16) (temp_19_7);
                    datSetStateTableEntry(temp_16_76, fclAddClamped(clndGetMoonPhase(temp_16_76) & 0xFF, (s32) (*(s16 *)(work + 0x12)), 0xFF, 0, 1) & 0xFF);
                    for (var_16_20 = 0; var_16_20 < 0x2FF; var_16_20++) {
                        if (!(clndGetMoonPhase(var_16_20) & 0xFF)) {
                            if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateFirst(var_16_20) & 0xFFF00) >> 8), datItemMoonGateFirst(var_16_20) & 0xFF) == 1) {
                                if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateSecond(var_16_20) & 0xFFF00) >> 8), datItemMoonGateSecond(var_16_20) & 0xFF) == 1) {
                                    (*(s16 *)((u8 *)((work + ((*(s16 *)(work + 0xC16)) * 2))) + 0x16)) = var_16_20;
                                    (*(s16 *)(work + 0xC16)) = (s16) ((*(s16 *)(work + 0xC16)) + 1);
                                }
                            }
                        }
                    }
                }
                temp_16_77 = datItemPrice((s32) temp_19_7) / 5U;
                temp_2_yen = fclGetMoney();
                fclAddMoney(temp_2_yen + ((*(s16 *)(work + 0x12)) * temp_16_77));
                datItemSetCount(temp_19_7, ((datItemCount(temp_19_7) & 0xFF) - (*(s16 *)(work + 0x12))) & 0xFF);
                temp_3_19 = (*(s8 *)(work + 0x11));
                switch (temp_3_19) {                /* switch 6; irregular */
                case 0:                             /* switch 6 */
                    yListRebuildFor((((void**)(work + 0xF18))[temp_3_19]), 0x40000, 0, 4, 0);
                    (*(s32 *)(work + 0xC20)) = 0;
                    for (var_19_5 = 1; var_19_5 < yListCountFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18))); var_19_5++) {
                        temp_21_5 = yListValueAtFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_19_5);
                        yListAuxValueAtFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_19_5);
                        temp_16_79 = (s16) (temp_21_5);
                        fclAddClamped((clndGetMoonPhase(temp_16_79) & 0xFF), datItemCount(temp_21_5) & 0xFF, 0xFF, 0, 1);
                        temp_4_12 = (*(s32 *)(work + 0xC20)) + ((datItemPrice(temp_16_79) / 5U) * (datItemCount(temp_21_5) & 0xFF));
                        (*(s32 *)(work + 0xC20)) = temp_4_12;
                        (*(s32 *)(work + 0xC20)) = fclAddClamped(temp_4_12, 0, 0x98967F, 0, 1);
                    }
                    break;
                case 1:                             /* switch 6 */
                    yListRebuildFor((((void**)(work + 0xF18))[temp_3_19]), 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:                             /* switch 6 */
                    yListRebuildFor((((void**)(work + 0xF18))[temp_3_19]), 0x10000, 0, 1, 0);
                    break;
                }
                if (temp_18_54 != yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]))) {
                    temp_4_13 = (s16) ((s64) temp_23_2);
                    if ((temp_4_13 - ((s16) ((s64) temp_30))) > 0) {
                        temp_16_81 = (s16) (fclSubClamped((s32) temp_4_13, 1, 0, 0, 1));
                        (*(s16 *)(work + 2)) = 0;
                        (*(s16 *)(work + 2)) = fclAddClamped((s32) (*(s16 *)(work + 2)), (s32) ((s16) (temp_16_81)), yListLastIndexFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                    } else {
                        (*(s16 *)(work + 2)) = fclAddClamped((s32) (*(s16 *)(work + 2)), 0, yListLastIndexFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                    }
                    (*(s16 *)(work + 4)) = fclAddClamped((s32) (*(s16 *)(work + 4)), 0, yListLastIndexFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                }
                fclShopUpdateTabs(arg0, (s8) (s32) (*(s8 *)(work + 0x11)));
            }
            fclShopStartRevealByMode(arg0);
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            fclObjStartAlpha((*(void * *)(work + 0xCCC)), 0xFFU, 0U, 0U, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xCD0)), 0xFFU, 0U, 0U, 5, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xCC8)), 0, 1);
            fclObjStartAlpha((*(void * *)(work + 0xDCC)), 0U, 0xFFU, 0U, 5, 0);
            fclObjStartAlpha((*(void * *)(work + 0xDD0)), 0U, 0xFFU, 0U, 5, 0);
            (*(s8 *)(work + 0)) = 0x24;
            if ((*(s8 *)(work + 0xC24)) == 1) {
                if (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) <= D_00748908[(*(s8 *)(work + 0x11))]) {
                    fclShopHideSelectionSprites(arg0);
                } else {
                    (*(s8 *)(work + 0)) = 0x31;
                }
            }
            if ((*(s16 *)(work + 0xC16)) > 0) {
                (*(s8 *)(work + 0xC1A)) = 0;
                fclShopPlayItemCue(arg0);
                (*(s8 *)(work + 0)) = 0x29;
            }
        }
        break;
    case 0x2E:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            (*(s16 *)(work + 0xC16)) = 0;
            (*(s16 *)(work + 0xC18)) = 0;
            if (func_002bb1c0((*fclShopMesSlot(work))) == 0) {
                nmMesWindowDestroySlot((*fclShopMesSlot(work)));
                sdkSndStartStream(0, 0, 0, 6);
                for (var_18_6 = 1; var_18_6 < yListCountFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18))); var_18_6++) {
                    temp_19_8 = yListValueAtFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_18_6);
                    yListAuxValueAtFor((*(void * *)((u8 *)((work + ((*(s8 *)(work + 0x11)) * 4))) + 0xF18)), (s32) var_18_6);
                    datSetStateTableEntry(temp_19_8, fclAddClamped((clndGetMoonPhase(temp_19_8) & 0xFF), datItemCount(temp_19_8) & 0xFF, 0xFF, 0, 1) & 0xFF);
                    temp_16_85 = (datItemPrice(temp_19_8) / 5U) * (datItemCount(temp_19_8) & 0xFF);
                    temp_2_yen = fclGetMoney();
                    fclAddMoney(temp_2_yen + temp_16_85);
                    datItemSetCount(temp_19_8, 0);
                }
                (*(s32 *)(work + 0xC20)) = 0;
                for (var_16_21 = 0; var_16_21 < 0x2FF; var_16_21++) {
                    if (!(clndGetMoonPhase(var_16_21) & 0xFF)) {
                        if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateFirst(var_16_21) & 0xFFF00) >> 8), datItemMoonGateFirst(var_16_21) & 0xFF) == 1) {
                            if (fclMoonPhaseAtLeast(((s32) (datItemMoonGateSecond(var_16_21) & 0xFFF00) >> 8), datItemMoonGateSecond(var_16_21) & 0xFF) == 1) {
                                (*(s16 *)((u8 *)((work + ((*(s16 *)(work + 0xC16)) * 2))) + 0x16)) = var_16_21;
                                (*(s16 *)(work + 0xC16)) = (s16) ((*(s16 *)(work + 0xC16)) + 1);
                            }
                        }
                    }
                }
                yListRebuildFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]), 0x40000, 0, 4, 0);
                (*(s32 *)(work + 0xC20)) = 0;
                (*(s16 *)(work + 2)) = fclAddClamped((s32) (*(s16 *)(work + 2)), 0, yListLastIndexFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), 0, 1);
                temp_18_57 = (*(s16 *)(work + 4));
                if (func_002b32a0((s32) (*(s16 *)(work + 4)), 5, yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])), yListLastIndexFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))]))) < temp_18_57) {
                    (*(s16 *)(work + 4)) = func_002b32a0((s32) (*(s16 *)(work + 4)), 5, (s32) ((s16) (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])))), (s32) ((s16) (yListLastIndexFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])))));
                }
                fclObjChangeFlagBit((*(void * *)(work + 0xE40)), 0, 1);
                fclObjChangeFlagBit((*(void * *)(work + 0xE44)), 0, 1);
                fclObjChangeFlagBit((*(void * *)(work + 0xE48)), 0, 1);
                fclShopUpdateTabs(arg0, (s8) (s32) (*(s8 *)(work + 0x11)));
                (*(s8 *)(work + 0)) = 0x24;
                if ((*(s8 *)(work + 0xC24)) == 1) {
                    fclShopHideSelectionSprites(arg0);
                }
                if ((*(s16 *)(work + 0xC16)) > 0) {
                    (*(s8 *)(work + 0xC1A)) = 0;
                    fclShopPlayItemCue(arg0);
                    (*(s8 *)(work + 0)) = 0x29;
                }
            } else {
                nmMesWindowDestroySlot((*fclShopMesSlot(work)));
                (*(s8 *)(work + 0)) = 0x24;
                if ((*(s8 *)(work + 0xC24)) == 1) {
                    fclShopHideSelectionSprites(arg0);
                }
            }
        }
        break;
    case 0x29:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawScrollThumb(arg0);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            sdkSndStartChannel(2, (const char *) D_0063FAF0);
            (*(s8 *)(work + 0)) = 0x2A;
        }
        break;
    case 0x2A:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawScrollThumb(arg0);
        (*(s8 *)(work + 0xC1A)) = fclAddClamped((s32) (*(s8 *)(work + 0xC1A)), 1, 0x3C, 0, 1);
        if ((*(s8 *)(work + 0xC1A)) >= 0x3C) {
            (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 0xA, NULL, 0);
            (*(s8 *)(work + 0)) = 0x2B;
            (*(s8 *)(work + 0xC1A)) = 0;
        }
        break;
    case 0x2B:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawScrollThumb(arg0);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            sp670.v0 = (s32) (((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]);
            sp670.v1 = 0;
            (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 3, &sp670, 0);
            (*(s8 *)(work + 0)) = 0x2D;
        }
        break;
    case 0x2C:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawScrollThumb(arg0);
        sp668.v0 = (s32) (((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]);
        sp668.v1 = 0;
        (*fclShopMesSlot(work)) = fclShopPlaySound(arg0, 3, &sp668, 0);
        (*(s8 *)(work + 0)) = 0x2D;
        break;
    case 0x2D:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        fclShopDrawScrollThumb(arg0);
        if (nmMesWindowSlotStatus((*fclShopMesSlot(work))) != 0) {
            nmMesWindowStepSlotRelease((*fclShopMesSlot(work)));
        } else {
            temp_3_flag = clndGetMoonPhase((((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]));
            datSetStateTableEntry((((s16 *)(work + 0x16))[(*(s16 *)(work + 0xC18))]), temp_3_flag | 1);
            nmMesWindowDestroySlot((*fclShopMesSlot(work)));
            temp_2_98 = (*(s16 *)(work + 0xC18)) + 1;
            (*(s16 *)(work + 0xC18)) = temp_2_98;
            if (((s16) ((s64) temp_2_98)) >= (*(s16 *)(work + 0xC16))) {
                (*(s8 *)(work + 0)) = 0x24;
                if ((*(s8 *)(work + 0xC24)) == 1) {
                    (*(s8 *)(work + 0)) = 0x31;
                }
            } else {
                fclShopPlayItemCue(arg0);
                (*(s8 *)(work + 0)) = 0x29;
            }
        }
        break;
    case 0x26:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        for (var_20_2 = 0; var_20_2 < 2; var_20_2++) {
            temp_19_9 = fclObjectGetWork((*(void * *)(work + 0xDCC)));
            temp_18_58 = fclObjectGetWork((*(void * *)(work + 0xDD0)));
            temp_2_99 = (*(u8 *)(work + ((var_20_2) * 4) + 0xF3E));
            var_f12_13 = (f32) temp_2_99;
            temp_f0_15 = fclEaseInterpolate(1, var_f12_13, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_15 = (u8) temp_f0_15;
            (*(s8 *)((u8 *)temp_18_58 + 0x79)) = var_3_15;
            (*(s8 *)((u8 *)temp_19_9 + 0x79)) = var_3_15;
            temp_2_100 = (*(u8 *)(work + ((var_20_2) * 4) + 0xF3F));
            var_f12_14 = (f32) temp_2_100;
            temp_f0_16 = fclEaseInterpolate(1, var_f12_14, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_16 = (u8) temp_f0_16;
            (*(s8 *)((u8 *)temp_18_58 + 0x7A)) = var_3_16;
            (*(s8 *)((u8 *)temp_19_9 + 0x7A)) = var_3_16;
            temp_2_101 = (*(u8 *)(work + ((var_20_2) * 4) + 0xF40));
            var_f12_15 = (f32) temp_2_101;
            temp_f0_17 = fclEaseInterpolate(1, var_f12_15, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_17 = (u8) temp_f0_17;
            (*(s8 *)((u8 *)temp_18_58 + 0x7B)) = var_3_17;
            (*(s8 *)((u8 *)temp_19_9 + 0x7B)) = var_3_17;
        }
        temp_4_15 = (*(s16 *)(work + 0xF3C));
        if (temp_4_15 < 6) {
            (*(s16 *)(work + 0xF3C)) = fclAddClamped((s32) temp_4_15, 1, 6, 0, 1);
        } else {
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDCC))) + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x79) = *(FclDrawColor *)(work + 0xF42);
            sp660 = *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDCC))) + 0x2C);
            fclObjStartPosition((*(void * *)(work + 0xDCC)), sp660, fclMakeVec2(sp660.x - 1000.0f, sp660.y), 1, 3, 0);
            spP[2] = *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x2C);
            fclObjStartPosition((*(void * *)(work + 0xDD0)), spP[2], fclMakeVec2(spP[2].x - 1000.0f, spP[2].y), 1, 3, 0);
            (*(s8 *)(work + 0)) = 0x2F;
        }
        break;
    case 0x2F:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        for (var_20_3 = 0; var_20_3 < 2; var_20_3++) {
            temp_19_10 = fclObjectGetWork((*(void * *)(work + 0xDCC)));
            temp_18_59 = fclObjectGetWork((*(void * *)(work + 0xDD0)));
            temp_2_106 = (*(u8 *)(work + ((var_20_3) * 4) + 0xF3E));
            var_f12_16 = (f32) temp_2_106;
            temp_f0_18 = fclEaseInterpolate(1, var_f12_16, 255.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_18 = (u8) temp_f0_18;
            (*(s8 *)((u8 *)temp_18_59 + 0x79)) = var_3_18;
            (*(s8 *)((u8 *)temp_19_10 + 0x79)) = var_3_18;
            temp_2_107 = (*(u8 *)(work + ((var_20_3) * 4) + 0xF3F));
            var_f12_17 = (f32) temp_2_107;
            temp_f0_19 = fclEaseInterpolate(1, var_f12_17, 226.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_19 = (u8) temp_f0_19;
            (*(s8 *)((u8 *)temp_18_59 + 0x7A)) = var_3_19;
            (*(s8 *)((u8 *)temp_19_10 + 0x7A)) = var_3_19;
            temp_2_108 = (*(u8 *)(work + ((var_20_3) * 4) + 0xF40));
            var_f12_18 = (f32) temp_2_108;
            temp_f0_20 = fclEaseInterpolate(1, var_f12_18, 145.0f, (f32) (*(s16 *)(work + 0xF3C)), 3.0f);
            var_3_20 = (u8) temp_f0_20;
            (*(s8 *)((u8 *)temp_18_59 + 0x7B)) = var_3_20;
            (*(s8 *)((u8 *)temp_19_10 + 0x7B)) = var_3_20;
        }
        temp_4_16 = (*(s16 *)(work + 0xF3C));
        if (temp_4_16 < 6) {
            (*(s16 *)(work + 0xF3C)) = fclAddClamped((s32) temp_4_16, 1, 6, 0, 1);
        } else {
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDCC))) + 0x79) = *(FclDrawColor *)(work + 0xF3E);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x79) = *(FclDrawColor *)(work + 0xF42);
            sp658 = *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDCC))) + 0x2C);
            fclObjStartPosition((*(void * *)(work + 0xDCC)), sp658, fclMakeVec2(sp658.x - 1000.0f, sp658.y), 1, 3, 0);
            spP[1] = *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x2C);
            fclObjStartPosition((*(void * *)(work + 0xDD0)), spP[1], fclMakeVec2(spP[1].x - 1000.0f, spP[1].y), 1, 3, 0);
            fclObjSetAnchorPosition((*(void * *)(work + 0xE50)), 0x41, 109.0f);
            fclObjStartPosition((*(void * *)(work + 0xE50)), fclMakeVec2((f32) -0x271, 124.0f), fclMakeVec2(75.0f, 124.0f), 0, 4, 5);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xE50))) + 0x79) = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            fclObjSetAnchorPosition((*(void * *)(work + 0xE54)), 0x41, 112.0f);
            fclObjStartPosition((*(void * *)(work + 0xE54)), fclMakeVec2((f32) -0x271, (f32) 0x11D), fclMakeVec2(75.0f, (f32) 0x11D), 0, 4, 5);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xE54))) + 0x79) = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
            fclObjSetAnchorPosition((*(void * *)(work + 0xE58)), 0x41, 113.0f);
            fclObjStartPosition((*(void * *)(work + 0xE58)), fclMakeVec2(-117.0f, 128.0f), fclMakeVec2((f32) 0x247, 128.0f), 0, 4, 5);
            fclObjSetAnchorPosition((*(void * *)(work + 0xE5C)), 0x41, 114.0f);
            fclObjStartPosition((*(void * *)(work + 0xE5C)), fclMakeVec2((f32) -0x2FD, 128.0f), fclMakeVec2(-65.0f, 128.0f), 0, 4, 5);
            (*(s8 *)(work + 0xC24)) = 1;
            (*(s8 *)(work + 0)) = 0x30;
        }
        break;
    case 0x30:                                      /* switch 1 */
        fclShopDrawBuyList(arg0, 2);
        if ((((s8) (fclObjTestFlagBit((*(void * *)(work + 0xDCC)), 9))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xDD0)), 9))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xE50))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xE54))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xE58))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xE5C))))) == 0)) {
            for (var_16_22 = 0; var_16_22 < 3; var_16_22++) {
                fclObjSetAnchorPosition((*(void * *)(work + ((var_16_22) * 4) + 0xDBC)), 0x41, 95.0f);
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + ((var_16_22) * 4) + 0xDBC))) + 0x79) = fclMakeDrawColor(0xFF, 0xEF, 0x80, 0xFF);
            }
            *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDBC))) + 0x2C) = fclMakeVec2(89.0f, 163.0f);
            *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDC0))) + 0x2C) = fclMakeVec2((f32) 0x1D1, 163.0f);
            *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDC4))) + 0x2C) = fclMakeVec2((f32) 0x22E, 163.0f);
            fclObjSetAnchorPosition((*(void * *)(work + 0xCAC)), 0x56, 91.0f);
            *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCAC))) + 0x2C) = fclMakeVec2((f32) 0x1DF, 167.0f);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xCAC))) + 0x79) = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
            fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE84)), 0x56, 91.0f);
            *(FclDrawColor *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE84))) + 0x79) = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
            *(Vec2f *)((u8 *)fclObjectGetWork((void *) (*(s32 *)(work + 0xE84))) + 0x2C) = fclMakeVec2((f32) 0x1DF, 217.0f);
            if (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) >= 2) {
                fclObjSetAnchorPosition((*(void * *)(work + 0xC94)), 0x41, 88.0f);
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC94))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC94))) + 0x2C) = fclMakeVec2((f32) 0x247, 136.0f);
                fclObjSetAnchorPosition((*(void * *)(work + 0xC98)), 0x41, 89.0f);
                *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC98))) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
                *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xC98))) + 0x2C) = fclMakeVec2((f32) 0x247, 272.0f);
            }
            (*(s8 *)(work + 0)) = 0x31;
        }
        break;
    case 0x31:                                      /* switch 1 */
        fclObjChangeFlagBit((*(void * *)(work + 0xCA0)), 0, 1);
        fclObjChangeFlagBit((*(void * *)(work + 0xCA8)), 0, 1);
        fclObjChangeFlagBit((*(void * *)(work + 0xC9C)), 0, 1);
        fclObjChangeFlagBit((*(void * *)(work + 0xCA4)), 0, 1);
        fclObjChangeFlagBit((*(void * *)(work + 0xCB8)), 0, 1);
        fclObjChangeFlagBit((void *) (*(s32 *)(work + 0xEAC)), 0, 1);
        fclShopDrawBuyList(arg0, 1);
        fclShopDrawScrollThumb(arg0);
        if ((((s8) (fclObjTestFlagBit((*(void * *)(work + 0xE38)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xCC4)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xCC0)), 1))) == 0) && ((D_008C0276[0] & 0x80) || (D_008C0276[0] & 0x20))) {
            sdkSndStartStream(0, 1, 0, 4);
            fclShopHideSelectionSprites(arg0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDE4)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDE0)), 0, 1);
            sp650 = *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDCC))) + 0x2C);
            tbl = (f32 *) D_0063F888;
            fclObjStartPosition((*(void * *)(work + 0xDCC)), fclMakeVec2(700.0f + tbl[0], sp650.y), fclMakeVec2(tbl[0], sp650.y), 1, 3, 2);
            spP[0] = *(Vec2f *)((u8 *)fclObjectGetWork((*(void * *)(work + 0xDD0))) + 0x2C);
            tbl = (f32 *) D_0063F890;
            fclObjStartPosition((*(void * *)(work + 0xDD0)), fclMakeVec2(700.0f + tbl[0], spP[0].y), fclMakeVec2(tbl[0], spP[0].y), 1, 3, 2);
            (*(s8 *)(work + 0)) = 0x24;
        }
        break;
    case 0x32:                                      /* switch 1 */
        (*(s8 *)(work + 0)) = 0x24;
        break;
    case 0x33:                                      /* switch 1 */
        if (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) > 5) {
            if (yListCountFor((((void**)(work + 0xF18))[temp_16_90 = (*(s8 *)(work + 0x11))])) > D_00748908[temp_16_90]) {
                if (yListCountFor((((void**)(work + 0xF18))[temp_16_90])) > 5) {
                    (*(f32 *)(work + 0xC)) = (f32) (104.0f / (f32) (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) - 5));
                }
                fclDrawEquipSprite(0x36, fclMakeVec2((f32) 0x221,  142.0f + (*(f32 *)(work + 0xC)) * (f32) ((*(s16 *)(work + 2)) - (*(s16 *)(work + 4)))), 138.0f, fclPackRgba(0xFFU, 0xFEU, 0xC6U, 0x31U), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC8C)))) + 0x62)), 0, D_00794EA0);
            }
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 0);
        } else {
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 1);
        }
        fclShopDrawItemRows(arg0, (*(s8 *)(work + 0x116E)), 80.0f, (f32) 0x352);
        fclShopDrawItemRows(arg0, (s8) (s32) (*(s8 *)(work + 0x11)), (f32) -0x352, 80.0f);
        temp_2_129 = fclSubClamped((s32) (*(s16 *)(work + 0x1170)), 1, 0, 0, 1);
        (*(s16 *)(work + 0x1170)) = temp_2_129;
        if (((s16) ((s64) temp_2_129)) == 0) {
            (*(s8 *)(work + 0)) = 0x24;
        }
        break;
    case 0x34:                                      /* switch 1 */
        if (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) > 5) {
            if (yListCountFor((((void**)(work + 0xF18))[temp_16_92 = (*(s8 *)(work + 0x11))])) > D_00748908[temp_16_92]) {
                if (yListCountFor((((void**)(work + 0xF18))[temp_16_92])) > 5) {
                    (*(f32 *)(work + 0xC)) = (f32) (104.0f / (f32) (yListCountFor((((void**)(work + 0xF18))[(*(s8 *)(work + 0x11))])) - 5));
                }
                fclDrawEquipSprite(0x36, fclMakeVec2((f32) 0x221,  142.0f + (*(f32 *)(work + 0xC)) * (f32) ((*(s16 *)(work + 2)) - (*(s16 *)(work + 4)))), 138.0f, fclPackRgba(0xFFU, 0xFEU, 0xC6U, 0x31U), (*(u8 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC8C)))) + 0x62)), 0, D_00794EA0);
            }
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 0);
        } else {
            fclObjChangeFlagBit((*(void * *)(work + 0xC8C)), 0, 1);
            fclObjChangeFlagBit((*(void * *)(work + 0xC90)), 0, 1);
        }
        fclShopDrawItemRows(arg0, (*(s8 *)(work + 0x116E)), 80.0f, (f32) -0x352);
        fclShopDrawItemRows(arg0, (s8) (s32) (*(s8 *)(work + 0x11)), (f32) 0x352, 80.0f);
        temp_2_130 = fclSubClamped((s32) (*(s16 *)(work + 0x1170)), 1, 0, 0, 1);
        (*(s16 *)(work + 0x1170)) = temp_2_130;
        if (((s16) ((s64) temp_2_130)) == 0) {
            (*(s8 *)(work + 0)) = 0x24;
        }
        break;
    case 0x35:                                      /* switch 1 */
        if (kwlnTaskGetTaskByName(D_0063FB10) == 0) {
            for (var_16_23 = 0; var_16_23 < 7; var_16_23++) {
                fclObjChangeFlagBit((*(void * *)((u8 *)((work + (var_16_23 * 4))) + 0xD20)), 0, 0);
            }
            fclObjChangeFlagBit((*(void * *)(work + 0xC44)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xC48)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDEC)), 0, 0);
            for (var_16_24 = 0; var_16_24 < 3; var_16_24++) {
                fclObjStartAlpha((*(void * *)((u8 *)((work + (var_16_24 * 4))) + 0xC38)), 0U, 0xFFU, 0U, 0xA, 0);
            }
            fclObjStartAlpha((*(void * *)(work + 0xD8C)), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjStartAlpha((*(void * *)(work + 0xD90)), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjStartAlpha((*(void * *)(work + 0xD94)), 0U, 0xFFU, 0U, 0xA, 0);
            fclObjSetAnchorPosition((*(void * *)(work + 0xC4C)), 0x40, 191.0f);
            temp_2_131 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(5));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_131))));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC4C)))) + 0x102)) = (s16) ((s16) ((sdkSpriteScaledHeight(temp_2_131))));
            sdkSpriteFreeNode(temp_2_131);
            fclObjStartAlpha((*(void * *)(work + 0xC4C)), 0U, 0xCCU, 0U, 4, 4);
            fclObjStartTween((*(void * *)(work + 0xC4C)), 0.0f, fGpffff8520, 0, 4, 4);
            fclObjStartPosition((*(void * *)(work + 0xC4C)), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
            fclObjSetAnchorPosition((*(void * *)(work + 0xC50)), 0x40, 192.0f);
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x2C)) = 110.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x30)) = -50.0f;
            temp_2_132 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_132))));
            (*(s16 *)((u8 *)(fclObjectGetWork((*(void * *)(work + 0xC50)))) + 0x102)) = 0;
            fclObjStartTween((*(void * *)(work + 0xC50)), -90.0f, fGpffff8524, 0, 4, 4);
            fclObjStartAlpha((*(void * *)(work + 0xC50)), 0U, 0xFFU, 0U, 4, 4);
            sdkSpriteFreeNode(temp_2_132);
            fclObjSetAnchorPosition((void *) (*(s32 *)(work + 0xE7C)), 0x40, 190.0f);
            (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x2C)) = 180.0f;
            (*(f32 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x30)) = 30.0f;
            temp_2_133 = sdkSpriteNewNode((u32)((void *) (*fclShopSpriteResource(work))), (u32)(6));
            (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x100)) = (s16) ((s16) ((sdkSpriteScaledWidth(temp_2_133))));
            (*(s16 *)((u8 *)(fclObjectGetWork((void *) (*(s32 *)(work + 0xE7C)))) + 0x102)) = 0;
            sdkSpriteFreeNode(temp_2_133);
            fclObjStartTween((void *) (*(s32 *)(work + 0xE7C)), -85.0f, fGpffff8528, 0, 4, 2);
            fclObjStartAlpha((void *) (*(s32 *)(work + 0xE7C)), 0U, 0xFFU, 0U, 4, 2);
            for (var_21_4 = 0; var_21_4 < 7; var_21_4++) {
                temp_18_63 = (f32 *)(D_0063F560 + ((var_21_4 + 0x3A) * 8));
                fclObjSetAnchorPosition((*(void * *)(work + (var_21_4 * 4) + 0xD20)), 0x56, (f32) (var_21_4 + 0x64));
                if (var_21_4 > 0) {
                    *(FclDrawColor *)((u8 *)fclObjectGetWork((*(void * *)(work + (var_21_4 * 4) + 0xD20))) + 0x79) = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
                }
                fclObjStartPosition((*(void * *)(work + ((var_21_4) * 4) + 0xD20)), fclMakeVec2(80.0f + temp_18_63[0], temp_18_63[1]), fclMakeVec2(temp_18_63[0], temp_18_63[1]), 0, 3, var_21_4);
                fclObjStartAlpha((*(void * *)(work + ((var_21_4) * 4) + 0xD20)), 0U, 0xFFU, 0U, 3, var_21_4);
            }
            *(FclDrawColor *)((u8 *)fclObjectGetWork((((void * *)(work + 0xD24))[(*(s8 *)(work + 7))])) + 0x79) = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclObjStartAlpha((*(void * *)(work + 0xC44)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
            fclObjStartAlpha((*(void * *)(work + 0xC48)), 0U, 0xFFU, 0U, 0, (s64) (*(s8 *)(work + 7)));
            fclShopStartSelectionShake(arg0);
            fclShopLayoutPanels(arg0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDE8)), 0, 0);
            fclObjChangeFlagBit((*(void * *)(work + 0xDEC)), 0, 0);
            (*(s8 *)(work + 0)) = 0x36;
        }
        break;
    case 0x36:                                      /* switch 1 */
        for (var_16_25 = 0x55; var_16_25 < 0x58; var_16_25++) {
            if (((s8) (fclObjTestFlagBit((*(void * *)(work + (var_16_25 * 4) + 0xC38)), 1))) == 0) {
                fclObjChangeFlagBit((*(void * *)(work + (var_16_25 * 4) + 0xC38)), 3, 0);
            }
        }
        for (var_16_26 = 0x59; var_16_26 < 0x60; var_16_26++) {
            if (((s8) (fclObjTestFlagBit((*(void * *)(work + (var_16_26 * 4) + 0xC38)), 1))) == 0) {
                fclObjChangeFlagBit((*(void * *)(work + (var_16_26 * 4) + 0xC38)), 3, 0);
            }
        }
        if ((((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD8C)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD90)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xD94)), 1))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xC4C)), 2))) == 0) && (((s8) (fclObjTestFlagBit((*(void * *)(work + 0xC50)), 2))) == 0)) {
            (*(s8 *)(work + 0)) = 0x10;
        }
        break;
    case 0x37:                                      /* switch 1 */
        if ((((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC4C))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC50))))) == 0) && (((s8) (fclObjHasStatusFlags((void *) (*(s32 *)(work + 0xE7C))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC38))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC3C))))) == 0) && (((s8) (fclObjHasStatusFlags((*(void * *)(work + 0xC40))))) == 0)) {
            return -1;
        }
        break;
    }
    return 0;
}

// Destroys the shop draw task: releases the glyph sprites, the sprite and CDVD handles, and the list, then frees the work block.
// FUN_002CA770
void fclShopDrawDestroy(u8 *arg0) {
    s16 i;
    void *work = *(void **)((u8 *)arg0 + 0x38);

    for (i = 0; i < *(s8 *)((u8 *)work + 9); i++) {
        datClampUnitHpSp(*(s8 *)((u8 *)work + i + 0xF73));
    }
    if (*(void **)((u8 *)work + 0xF28)) {
        sdkSpriteRelease(*(void **)((u8 *)work + 0xF28));
        *(u32 *)((s32)work + 0xF28) = 0;
    }
    if (*(void **)((u8 *)work + 0xF2C)) {
        H_Cdvd_Destroy(*(void **)((u8 *)work + 0xF2C));
    }
    yListDestroy();
    jtbl_008873EC[0](*(void **)((s32)arg0 + 0x38));
}

// Creates the shop draw task under arg0: allocates the work block, creates the four value sprites and three list children, and clears the sprite and state fields.
// FUN_002CA830
s32 fclShopDrawCreate(s32 arg0) {
    FclVec2 sp48;
    FclVec2 sp40;
    FclVec2 sp38;
    FclVec2 sp30;
    s32 temp_17;
    u8 *temp_2;

    chkmemAllocSiteTag(&D_0063FAC0, 0xC47);
    temp_2 = D_008873F4[0](1, 0x1174, 0x40000);
    temp_17 = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)((char *)&D_0063FB30), 0xF, 0, 0, fclShopStateUpdate, fclShopDrawDestroy, (u8 *)(temp_2));
    *(s8 *)(temp_2 + 0) = 9;
    sp48 = fclMakeVec2(240.0f, 20.0f);
    *(void **)(temp_2 + 0xC28) = (void *)fclSpriteSpawnChild(temp_17, sp48);
    *(s8 *)(temp_2 + 0xC24) = 0;
    sp40 = fclMakeVec2(50.0f, 30.0f);
    *(void **)(temp_2 + 0xC2C) = (void *)fclSpriteSpawnChild(temp_17, sp40);
    sp38 = fclMakeVec2(50.0f, 30.0f);
    *(void **)(temp_2 + 0xC30) = (void *)fclSpriteSpawnChild(temp_17, sp38);
    sp30 = fclMakeVec2(50.0f, 30.0f);
    *(void **)(temp_2 + 0xC34) = (void *)fclSpriteSpawnChild(temp_17, sp30);
    *(u32 *)(temp_2 + 0xF28) = 0;
    *(s8 *)(temp_2 + 0xF30) = 0;
    *(void **)(temp_2 + 0xF18) = yListCreateChild((void *)temp_17, 0x40000, 0, 4, 0);
    *(void **)(temp_2 + 0xF1C) = yListCreateChild((void *)temp_17, 0xFFFF, 0x1FE0, 1, 0);
    *(void **)(temp_2 + 0xF20) = yListCreateChild((void *)temp_17, 0x10000, 0, 1, 0);
    return temp_17;
}

// Sets the shop draw work's mode byte (the first byte of the work block) to arg1.
// FUN_002CAA00
void fclShopDrawSetMode(void *arg0, s8 arg1) {
    *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38)) = arg1;
}

/* Measured: 696/704 bytes, fourteen resolved relocations, eight zero
   alignment bytes. Separate glyph acquisition/release scopes preserve
   the saved-register allocation and callback order. */
#pragma push
#pragma opt_loop_invariants off
#pragma opt_common_subs off
// FUN_002CAA10
void fclShopDrawNumber(Vec2f position, f32 depth, RGBA color, u32 number_, s16 glyphBase, void *sprite_, s32 style)
{
    char text[16];
    f32 x;
    u32 number;
    s32 digitWidth;
    void *sprite;
    s32 count;
    s16 commaWidth;
    u8 *entry;
    s32 base;
    u8 a;
    u8 b;
    u8 g;
    f32 y;
    s32 comma;

    sprite = sprite_;
    number = number_;
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
    entry = D_00793E80 + style * 0x30;
    base = (s16)glyphBase;
    a = color.a;
    b = color.b;
    g = color.g;
    y = position.y;
    do {
        sdkSpriteDrawQueuedUnscaled(x, y, depth, fclPackRgba(0xFF, color.r, g, b), a, base + number % 10, sprite, 1, entry);
        number /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (number != 0) {
                x -= (f32)commaWidth;
                sdkSpriteDrawQueuedUnscaled(x, y, depth, fclPackRgba(0xFF, color.r, g, b), a, comma, sprite, 1, entry);
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
// FUN_002CACD0
void fclDrawNumber(Vec2f arg0, f32 fparg0, FclDrawColor arg1, s32 arg2, s16 arg3, u32 arg4_, s32 arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9)
{
    u8 spD0[16];
    u32 arg4;
    s32 count;
    u8 *entry;
    f32 x;
    f32 y;
    s32 base;
    u8 a;
    u8 b;
    u8 g;
    s32 comma;

    arg4 = arg4_;
    count = 0;
    x = arg0.x;
    memset(spD0, 0, 1);
    entry = D_00793E80 + arg9 * 0x30;
    base = (s16)arg5;
    a = arg1.c3;
    b = arg1.c2;
    g = arg1.c1;
    y = arg0.y;
    comma = (s16)arg6;
    do {
        sdkSpriteDrawQueuedUnscaled(x, y, fparg0, fclPackRgba(0xFF, arg1.c0, g, b), a, base + arg4 % 10, (void *)(u32)arg7, 1, entry);
        arg4 /= 10;
        count = (s8)(count + 1);
        if (count % 3 == 0) {
            if (arg4 != 0) {
                x -= (f32)arg3;
                sdkSpriteDrawQueuedUnscaled(x, y, fparg0, fclPackRgba(0xFF, arg1.c0, g, b), a, comma, (void *)(u32)arg8, 1, entry);
                x -= (f32)arg2;
            } else {
                x -= (f32)arg2;
            }
        } else {
            x -= (f32)arg2;
        }
    } while (arg4 != 0);
}
// FUN_002CAEF0
void fclShopSlideInFromLeft(void *arg0) {
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    Vec2f sp50;
    Vec2f sp48;
    Vec2f sp40;
    Vec2f sp38;
    FclDrawColor c0;
    FclDrawColor c1;
    FclDrawColor c2;
    FclDrawColor c3;
    FclDrawColor c4;
    u8 *work;
    u8 *t;
    Vec2f *base;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    base = (Vec2f *)D_0063F5B0;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEEC), 0x41, 109.0f);
    sp110 = fclMakeVec2(base->x, base->y);
    sp108 = fclMakeVec2(base->x - 750.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xEEC), sp110, sp108, 0, 4, 0);
    ((u8 *)fclObjectGetWork(*(void **)(work + 0xEEC)))[0x62] = 0xCC;
    c0 = fclMakeDrawColor(0, 0, 0, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEEC));
    ((FclObject *)t)->color = c0;

    base = (Vec2f *)D_0063F5F0;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEF4), 0x41, 109.0f);
    sp100 = fclMakeVec2(base->x, base->y);
    spF8 = fclMakeVec2(base->x - 750.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xEF4), sp100, spF8, 0, 4, 0);
    ((u8 *)fclObjectGetWork(*(void **)(work + 0xEF4)))[0x62] = 0xCC;
    c1 = fclMakeDrawColor(0, 0, 0, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEF4));
    ((FclObject *)t)->color = c1;

    base = (Vec2f *)D_0063F5D0;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEF8), 0x41, 111.0f);
    spF0 = fclMakeVec2(base->x, base->y);
    spE8 = fclMakeVec2(base->x - 750.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xEF8), spF0, spE8, 0, 4, 0);
    ((u8 *)fclObjectGetWork(*(void **)(work + 0xEF8)))[0x62] = 0xCC;
    c2 = fclMakeDrawColor(0, 0, 0, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEF8));
    ((FclObject *)t)->color = c2;

    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEF0), 0x41, 109.0f);
    spE0 = fclMakeVec2(86.0f, 242.0f);
    spD8 = fclMakeVec2(786.0f, 242.0f);
    fclObjStartPosition(*(void **)(work + 0xEF0), spE0, spD8, 0, 4, 0);
    c3 = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEF0));
    ((FclObject *)t)->color = c3;

    base = (Vec2f *)D_0063F5F8;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEFC), 0x41, 112.0f);
    spD0 = fclMakeVec2(base->x, base->y);
    spC8 = fclMakeVec2(base->x + 700.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xEFC), spD0, spC8, 0, 4, 0);
    c4 = fclMakeDrawColor(0xFF, 0xCB, 0x35, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEFC));
    ((FclObject *)t)->color = c4;

    base = (Vec2f *)D_0063F5D8;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xF00), 0x41, 113.0f);
    spC0 = fclMakeVec2(base->x, base->y);
    spB8 = fclMakeVec2(base->x + 700.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xF00), spC0, spB8, 0, 4, 0);

    base = (Vec2f *)D_0063F5E0;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xF04), 0x41, 114.0f);
    spB0 = fclMakeVec2(base->x, base->y);
    spA8 = fclMakeVec2(base->x + 700.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xF04), spB0, spA8, 0, 4, 0);

    base = (Vec2f *)D_0063F5B0;
    spA0 = fclMakeVec2(base->x + 660.0f, base->y);
    sp98 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC60), spA0, sp98, 0, 4, 6);
    base = (Vec2f *)D_0063F5F0;
    sp90 = fclMakeVec2(base->x + 660.0f, base->y);
    sp88 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC80), sp90, sp88, 0, 4, 6);
    base = (Vec2f *)D_0063F5D0;
    sp80 = fclMakeVec2(base->x + 660.0f, base->y);
    sp78 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC70), sp80, sp78, 0, 4, 6);
    sp70 = fclMakeVec2(-614.0f, 242.0f);
    sp68 = fclMakeVec2(86.0f, 242.0f);
    fclObjStartPosition(*(void **)(work + 0xE80), sp70, sp68, 0, 4, 6);
    base = (Vec2f *)D_0063F5F8;
    sp60 = fclMakeVec2(base->x - 700.0f, base->y);
    sp58 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC84), sp60, sp58, 0, 4, 6);
    base = (Vec2f *)D_0063F5D8;
    sp50 = fclMakeVec2(base->x - 700.0f, base->y);
    sp48 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC74), sp50, sp48, 0, 4, 6);
    base = (Vec2f *)D_0063F5E0;
    sp40 = fclMakeVec2(base->x - 700.0f, base->y);
    sp38 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC78), sp40, sp38, 0, 4, 6);
}

// Returns 1 when the shop draw work's state byte (+0xF30) is 1, meaning the shop draw is ready.
// FUN_002CB6A0
s32 fclShopDrawIsReady(void *arg0) {
    return *(s8 *)(*(u32 *)((u8 *)arg0 + 0x38) + 0xF30) == 1;
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
/* Shop menu work block (task + 0x38) as seen by the list/panel draws. */
typedef struct {
    s8 state;
    u8 pad1[0x1];
    s16 f2;
    s16 f4;
    u8 pad6[0x1];
    s8 f7;
    s8 sel;
    s8 count;
    u8 padA[0x2];
    f32 fC;
    u8 pad10[0x4];
    s8 f14;
    u8 pad15[0xC43];
    void *fC58;
    void *fC5C;
    void *fC60;
    void *fC64;
    u8 padC68[0x8];
    void *fC70;
    void *fC74;
    void *fC78;
    u8 padC7C[0x4];
    void *fC80;
    void *fC84;
    u8 padC88[0x4];
    void *fC8C;
    void *fC90;
    void *fC94;
    void *fC98;
    void *fC9C;
    void *fCA0;
    void *fCA4;
    void *fCA8;
    void *fCAC;
    u8 padCB0[0x8];
    void *fCB8;
    void *fCBC;
    u8 padCC0[0x7C];
    void *fD3C;
    u8 padD40[0x4];
    void *fD44;
    void *fD48;
    void *fD4C;
    void *fD50;
    void *fD54;
    void *fD58;
    u8 padD5C[0x4];
    void *fD60;
    void *fD64;
    u8 padD68[0x4];
    void *fD6C;
    void *fD70;
    u8 padD74[0x8];
    void *fD7C;
    u8 padD80[0x3C];
    void *fDBC[3];
    void *fDC8;
    u8 padDCC[0x4];
    void *fDD0;
    u8 padDD4[0x4];
    void *fDD8;
    u8 padDDC[0x8];
    void *fDE4;
    void *fDE8;
    u8 padDEC[0x4];
    void *fDF0;
    u8 padDF4[0x38];
    void *fE2C;
    void *fE30;
    u8 padE34[0x2C];
    void *fE60;
    u8 padE64[0x20];
    void *fE84;
    void *fE88[3];
    void *fE94;
    void *fE98;
    void *fE9C;
    void *fEA0;
    void *fEA4;
    void *fEA8;
    void *fEAC;
    void *fEB0;
    u8 padEB4[0x20];
    void *fED4;
    void *fED8;
    u8 padEDC[0x4C];
    void *fF28;
    u8 padF2C[0x10];
    s16 fF3C;
    FclDrawColor fF3E;
    FclDrawColor fF42;
    s16 timer[9];
    s16 wait[9];
    u8 flash[9];
    s8 kind[9];
    s8 icon[9];
} ShopMenuWork;
#pragma push
#pragma opt_loop_invariants on
// FUN_002CB6C0
void fclShopDrawItemList(void *arg0, s8 arg1) {
    s32 sdkSndStartStream(s16, s16, s16, s16);
    FclDrawColor rowColor;
    FclDrawColor glow0a;
    FclDrawColor glow0b;
    FclDrawColor glow1a;
    FclDrawColor glow1b;
    FclDrawColor c218;
    FclDrawColor c214;
    FclDrawColor c210;
    FclDrawColor c20C;
    FclDrawColor c208;
    FclDrawColor c204;
    FclDrawColor c200;
    FclDrawColor c1FC;
    FclDrawColor c1F8;
    FclDrawColor c1F4;
    Vec2f sp1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    Vec2f sp1C8;
    Vec2f sp1C0;
    Vec2f sp1B8;
    Vec2f sp1B0;
    Vec2f sp1A8;
    Vec2f sp1A0;
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f pos;
    ShopMenuWork *work;
    u8 *t;
    Vec2f *b;
    ShopSpinParam *fa;
    s16 start;
    s16 cur;
    s16 row;
    s16 i;
    s32 rowY;
    s32 textColor;
    s32 iconColor;
    s32 icon;
    u32 stock;

    work = *(ShopMenuWork **)((u8 *)arg0 + 0x38);
    if (yListCount() > 5) {
        if (yListCount() > 5) {
            work->fC = 104.0f / (f32)(yListCount() - 5);
        }
        sp1E8 = fclMakeVec2((f32)0x221, 142.0f + work->fC * (f32)(work->f2 - work->f4));
        fclDrawEquipSprite(0x36, sp1E8, 138.0f, fclPackRgba(0xFF, 0xFE, 0xC6, 0x31), ((u8 *)fclObjectGetWork(work->fC8C))[0x62], 0, D_00794EA0);
        fclObjChangeFlagBit(work->fC8C, 0, 0);
        fclObjChangeFlagBit(work->fC90, 0, 0);
    } else {
        fclObjChangeFlagBit(work->fC8C, 0, 1);
        fclObjChangeFlagBit(work->fC90, 0, 1);
    }
    sp1E0 = fclMakeVec2(51.0f, 48.0f);
    fclShopDrawItemText(arg0, work->kind[work->sel], sp1E0, (void *)fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
    if (fclObjTestFlagBit(work->fDC8, 1) == 0) {
        u8 alpha;

        b = (Vec2f *)D_0063F880;
        fclObjSetAnchorPosition(work->fDC8, 0x41, 124.0f);
        alpha = ((u8 *)fclObjectGetWork(work->fC8C))[0x62];
        ((u8 *)fclObjectGetWork(work->fDC8))[0x62] = alpha;
        ((ShopWork *)fclObjectGetWork(work->fDC8))->field_30 = b->y + (f32)(work->f4 << 5);
    }
    if (fclObjTestFlagBit(work->fDD0, 1) == 0) {
        u8 alpha;

        b = (Vec2f *)D_0063F890;
        fclObjSetAnchorPosition(work->fDD0, 0x41, 125.0f);
        alpha = ((u8 *)fclObjectGetWork(work->fC8C))[0x62];
        ((u8 *)fclObjectGetWork(work->fDD0))[0x62] = alpha;
        ((ShopWork *)fclObjectGetWork(work->fDD0))->field_30 = b->y + (f32)(work->f4 << 5);
    }
    switch (work->f7) {
    case 0:
        icon = work->icon[work->sel] & 0xFFFF;
        break;
    case 1:
    case 2:
        icon = (work->f7 + 0x1A) & 0xFFFF;
        break;
    }
    if (yListKind() != 0) {
        return;
    }
    start = work->f2 - work->f4;
    for (cur = start, row = 0; cur < start + 5; cur++, row++) {
        if (cur < yListCount()) {
            textColor = fclPackRgba(0xFF, 0xAE, 0, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
            iconColor = fclPackRgba(0, 0xFF, 0xAE, 0);
            rowColor = fclMakeDrawColor(0xFF, 0xAE, 0, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
            stock = datItemPrice((s16)yListValueAt(cur));
            if (stock > fclGetMoney() || (datItemCount((s16)yListValueAt(cur)) & 0xFF) == 0x63) {
                textColor = fclPackRgba(0xA6, 0x7F, 0x2B, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                iconColor = fclPackRgba(0, 0xA6, 0x7F, 0x2B);
                rowColor = fclMakeDrawColor(0xA6, 0x7F, 0x2B, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                if ((u8)clndGetMoonPhase(yListValueAt(cur)) & 1) {
                    textColor = fclPackRgba(0xA8, 0x9C, 0x4C, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                    iconColor = fclPackRgba(0, 0xA8, 0x9C, 0x4C);
                    rowColor = fclMakeDrawColor(0xA8, 0x9C, 0x4C, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                }
                if (cur == work->f2) {
                    textColor = fclPackRgba(0x9E, 0x73, 0x1D, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                    iconColor = fclPackRgba(0, 0x9E, 0x73, 0x1D);
                    rowColor = fclMakeDrawColor(0x9E, 0x73, 0x1D, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                }
            } else if (cur == work->f2) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                rowColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
            } else if ((u8)clndGetMoonPhase(yListValueAt(cur)) & 1) {
                textColor = fclPackRgba(0xFF, 0xEF, 0x81, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
                iconColor = fclPackRgba(0, 0xFF, 0xEF, 0x81);
                rowColor = fclMakeDrawColor(0xFF, 0xEF, 0x81, ((u8 *)fclObjectGetWork(work->fC8C))[0x62]);
            }
            if ((u8)clndGetMoonPhase(yListValueAt(cur)) & 1) {
                sp1D8 = fclMakeVec2(91.0f, (f32)((row << 5) + 0x7A));
                fclDrawResourceSprite(0x49, sp1D8, 65.0f, fclPackRgba(0, 0xFF, 0x66, 0), ((u8 *)fclObjectGetWork(work->fC8C))[0x62], 0, D_00794EA0);
            }
            rowY = row << 5;
            sp1D0 = fclMakeVec2(146.0f, (f32)(rowY + 0x85));
            fclDrawEquipSprite(icon, sp1D0, 69.0f, iconColor, ((u8 *)fclObjectGetWork(work->fC8C))[0x62], 0, D_00795E60);
            sp1C8 = fclMakeVec2(189.0f, 132.0f + (f32)rowY);
            pos = *(Vec2f *)&sp1C8;
            frFontExDrawTextDeferredWithCharWidth(pos.x, pos.y, 70.0f, textColor, 0, 1, ((void *)datGetItemNameId((s16)yListValueAt(cur))), 0, 0, D_00795E30, -1);
            sp1C0 = fclMakeVec2(498.0f, 142.0f + (f32)rowY);
            fclDrawNumber(sp1C0, 70.0f, rowColor, 0x10, 5, datItemPrice((s16)yListValueAt(cur)), 9, 0x7B,
                          (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->fF28, 0xA9);
        }
    }
    if (arg1 == 1) {
        return;
    }
    if ((D_008C0276[0] & 0x1000) && work->f14 == 0) {
        sdkSndStartStream(0, 0, 0, 0);
        if (work->f2 == 0) {
            work->f2 = yListLastIndex();
            work->f4 = fclAddClamped(0, work->f2, 4, 0, 1);
        } else {
            work->f2 = fclSubClamped(work->f2, 1, 0, yListCount(), 2);
            work->f4 = yListStepIndex(work->f2, work->f4, yListCount(), 5, -1);
        }
        work->f14 = 1;
        return;
    }
    if (D_008C027A[0] & 0x1000) {
        if (yListCount() > 0) {
            if (work->f2 != 0) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            work->f2 = fclSubClamped(work->f2, 1, 0, 0, 1);
            work->f4 = yListStepIndex(work->f2, work->f4, yListCount(), 5, -1);
            work->f14 = 1;
            return;
        }
    } else if ((D_008C0276[0] & 0x4000) && work->f14 == 0) {
        sdkSndStartStream(0, 0, 0, 0);
        work->f2 = fclAddClamped(work->f2, 1, yListLastIndex(), 0, 2);
        if (work->f2 == 0) {
            work->f4 = 0;
        } else if (yListLastIndex() >= 5) {
            work->f4 = yListStepIndex(work->f2, work->f4, yListLastIndex(), 5, 1);
        } else {
            work->f4 = yListStepIndex(work->f2, work->f4, yListLastIndex(), yListCount(), 1);
        }
        work->f14 = 1;
        return;
    } else if (D_008C027A[0] & 0x4000) {
        if (yListCount() > 0) {
            if (work->f2 != yListLastIndex()) {
                sdkSndStartStream(0, 0, 0, 0);
            }
            work->f2 = fclAddClamped(work->f2, 1, yListLastIndex(), 0, 1);
            if (yListLastIndex() >= 5) {
                work->f4 = yListStepIndex(work->f2, work->f4, yListLastIndex(), 5, 1);
            } else {
                work->f4 = yListStepIndex(work->f2, work->f4, yListLastIndex(), yListCount(), 1);
            }
            work->f14 = 1;
            return;
        }
    } else if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
        if (work->f2 != yListLastIndex()) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        yListAdvanceCursorScroll(work->f2, work->f4, yListCount(), 5, &work->f2, &work->f4);
    } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
        if (work->f2 != 0) {
            sdkSndStartStream(0, 0, 0, 0);
        }
        yListRetreatCursorScroll(work->f2, work->f4, yListCount(), 5, &work->f2, &work->f4);
    } else if (D_008C027A[0] & 8) {
        sdkSndStartStream(0, 0, 0, 5);
        work->f2 = 0;
        work->f4 = 0;
        work->sel = fclAddClamped(work->sel, 1, work->count - 1, 0, 2);
        switch (work->f7) {
        case 0:
            yListRebuild(1 << (s16)(work->icon[work->sel] - 0x14),
                          1 << (work->kind[work->sel] + 4), 2, 2);
            break;
        case 1:
            yListRebuild(0x4000, 1 << (work->kind[work->sel] + 4), 2, 2);
            break;
        case 2:
            yListRebuild(0x8000, 1 << (work->kind[work->sel] + 4), 2, 2);
            break;
        }
        fclShopSlideIndicator(arg0, 0);
    } else if (D_008C027A[0] & 4) {
        sdkSndStartStream(0, 0, 0, 5);
        work->f2 = 0;
        work->f4 = 0;
        work->sel = fclSubClamped(work->sel, 1, 0, work->count - 1, 2);
        switch (work->f7) {
        case 0:
            yListRebuild(1 << (s16)(work->icon[work->sel] - 0x14),
                          1 << (work->kind[work->sel] + 4), 2, 2);
            break;
        case 1:
            yListRebuild(0x4000, 1 << (work->kind[work->sel] + 4), 2, 2);
            break;
        case 2:
            yListRebuild(0x8000, 1 << (work->kind[work->sel] + 4), 2, 2);
            break;
        }
        fclShopSlideIndicator(arg0, 1);
    } else if (D_008C024E[0] & 0x40) {
        if (yListCount() > 0) {
            stock = datItemPrice((s16)yListValueAt(work->f2));
            if (stock <= fclGetMoney() && (datItemCount((s16)yListValueAt(work->f2)) & 0xFF) < 0x63) {
                sdkSndStartStream(0, 0, 0, 1);
                work->fF3E = *(FclDrawColor *)((u8 *)fclObjectGetWork(work->fDC8) + 0x79);
                work->fF42 = *(FclDrawColor *)((u8 *)fclObjectGetWork(work->fDD0) + 0x79);
                work->fF3C = 0;
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
            fclObjStartColor(work->fDC8, glow0a, glow0b, 1, 4, 0);
            ((u8 *)fclObjectGetWork(work->fDC8))[0x85] = 1;
            glow1a = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
            glow1b = fclMakeDrawColor(0xFF, 0xE2, 0x91, 0xFF);
            fclObjStartColor(work->fDD0, glow1a, glow1b, 1, 4, 0);
            ((u8 *)fclObjectGetWork(work->fDD0))[0x85] = 1;
            {
                void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x7D));

                ((ShopWork *)fclObjectGetWork(work->fE2C))->field_100 = (s16)sdkSpriteScaledWidth(r);
                ((ShopWork *)fclObjectGetWork(work->fE2C))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
                ((ShopWork *)fclObjectGetWork(work->fE30))->field_100 = 0;
                ((ShopWork *)fclObjectGetWork(work->fE30))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
                fclObjStartTween(work->fE2C, 0.0f, -4.0f, 0, 2, 0);
                fclObjStartTween(work->fE30, 0.0f, -4.0f, 0, 2, 0);
                ((ShopWork *)fclObjectGetWork(work->fE2C))->field_CF = 0;
                ((ShopWork *)fclObjectGetWork(work->fE30))->field_CF = 0;
                sdkSpriteFreeNode(r);
            }
            work->state = 0x20;
        }
    } else if (D_008C024E[0] & 0x20) {
        sdkSndStartStream(0, 0, 0, 2);
        fclObjStartTween(work->fD6C, -14.0f, 110.0f, 0, 0xA, 0);
        fclObjStartAlpha(work->fE2C, ((u8 *)fclObjectGetWork(work->fE2C))[0x62], 0, 0, 5, 0);
        fclObjStartAlpha(work->fE30, ((u8 *)fclObjectGetWork(work->fE30))[0x62], 0, 0, 5, 0);
        fclObjStartAlpha(work->fD70, ((u8 *)fclObjectGetWork(work->fD70))[0x62], 0, 0, 5, 0);
        fclObjStartAlpha(work->fD7C, ((u8 *)fclObjectGetWork(work->fD7C))[0x62], 0, 0, 5, 0);
        fclObjChangeFlagBit(work->fDD8, 0, 1);
        fclObjChangeFlagBit(work->fDE8, 0, 1);
        fclObjChangeFlagBit(work->fDF0, 0, 1);
        fclObjChangeFlagBit(work->fDE4, 0, 1);
        fclObjStartAlpha(work->fC8C, ((u8 *)fclObjectGetWork(work->fC8C))[0x62], 0, 0, 5, 0);
        fclObjStartAlpha(work->fC90, ((u8 *)fclObjectGetWork(work->fC90))[0x62], 0, 0, 5, 0);
        fclObjStartAlpha(work->fDC8, ((u8 *)fclObjectGetWork(work->fDC8))[0x62], 0, 0, 5, 0);
        fclObjStartAlpha(work->fDD0, ((u8 *)fclObjectGetWork(work->fDD0))[0x62], 0, 0, 5, 0);
        b = (Vec2f *)D_0063F5B8;
        sp1B8 = fclMakeVec2(b->x, b->y);
        sp1B0 = fclMakeVec2(b->x, 300.0f + b->y);
        fclObjStartPosition(work->fC64, sp1B8, sp1B0, 0, 0xA, 0);
        fclObjStartAlpha(work->fC64, ((u8 *)fclObjectGetWork(work->fC64))[0x62], 0, 0, 0xA, 0);
        b = (Vec2f *)D_0063F5A0;
        fclObjSetAnchorPosition(work->fC58, 0x40, 162.0f);
        sp1A8 = fclMakeVec2(b->x, b->y - 450.0f);
        sp1A0 = fclMakeVec2(b->x, b->y);
        fclObjStartPosition(work->fC58, sp1A8, sp1A0, 0, 4, 0);
        fclObjStartAlpha(work->fC58, 0, 0xCC, 0, 2, 0);
        c218 = fclMakeDrawColor(0, 0, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fC58);
        ((FclObject *)t)->color = c218;
        b = (Vec2f *)D_0063F5A8;
        fclObjSetAnchorPosition(work->fC5C, 0x40, 163.0f);
        sp198 = fclMakeVec2(b->x, b->y - 450.0f);
        sp190 = fclMakeVec2(b->x, b->y);
        fclObjStartPosition(work->fC5C, sp198, sp190, 0, 4, 0);
        fclObjStartAlpha(work->fC5C, 0, 0xCC, 0, 2, 0);
        c214 = fclMakeDrawColor(0, 0, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fC5C);
        ((FclObject *)t)->color = c214;
        for (i = 0; i < work->count; i++) {
            work->timer[i] = 0;
            work->wait[i] = 6;
            work->flash[i] = 0xFF;
        }
        fclObjChangeFlagBit(work->fED4, 0, 0);
        fclObjStartAlpha(work->fED4, 0, 0xFF, 0, 4, 0);
        sp188 = fclMakeVec2(47.0f, 78.0f + 35.0f * (f32)work->sel);
        t = (u8 *)fclObjectGetWork(work->fED4);
        ((FclObject *)t)->anchorPosition = sp188;
        fclObjChangeFlagBit(work->fED8, 0, 0);
        fclObjStartAlpha(work->fED8, 0, 0xFF, 0, 4, 0);
        sp180 = fclMakeVec2(126.0f, 78.0f + 35.0f * (f32)work->sel);
        t = (u8 *)fclObjectGetWork(work->fED8);
        ((FclObject *)t)->anchorPosition = sp180;
        fclShopDrawSwingCursor(arg0);
        fclObjSetAnchorPosition(work->fD3C, 0x41, 128.0f);
        fclObjStartAlpha(work->fD3C, 0, 0xFF, 0, 0xA, 0);
        b = (Vec2f *)D_0063F7B0;
        fclObjSetAnchorPosition(work->fD60, 0x41, 78.0f);
        sp178 = fclMakeVec2(b->x, b->y - (f32)0x226);
        sp170 = fclMakeVec2(b->x, b->y);
        fclObjStartPosition(work->fD60, sp178, sp170, 2, 4, 0);
        ((ShopWork *)fclObjectGetWork(work->fD60))->field_100 = ((ShopWork *)fclObjectGetWork(work->fD60))->field_102 = 0;
        fclObjStartTween(work->fD60, -5.0f, fGpffff852c, 2, 2, 2);
        c210 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fD60);
        ((FclObject *)t)->color = c210;
        b = (Vec2f *)D_0063F7B8;
        fclObjSetAnchorPosition(work->fD64, 0x41, 78.0f);
        sp168 = fclMakeVec2(b->x, b->y - (f32)0x226);
        sp160 = fclMakeVec2(b->x, b->y);
        fclObjStartPosition(work->fD64, sp168, sp160, 2, 4, 0);
        ((ShopWork *)fclObjectGetWork(work->fD64))->field_100 = -0x32;
        ((ShopWork *)fclObjectGetWork(work->fD64))->field_102 = -0xDB;
        fclObjStartTween(work->fD64, -5.0f, fGpffff852c, 2, 2, 2);
        b = (Vec2f *)D_0063F8C0;
        fclObjSetAnchorPosition(work->fDE8, 0x41, 46.0f);
        fclObjStartAlpha(work->fDE8, 0, 0xFF, 0, 6, 0);
        ((ShopWork *)fclObjectGetWork(work->fDE8))->field_2C = b->x;
        ((ShopWork *)fclObjectGetWork(work->fDE8))->field_30 = b->y;
        fclObjSetAnchorPosition(work->fDF0, 0x41, 47.0f);
        fclObjStartAlpha(work->fDF0, 0, 0xFF, 0, 6, 0);
        ((ShopWork *)fclObjectGetWork(work->fDF0))->field_2C = 147.0f;
        ((ShopWork *)fclObjectGetWork(work->fDF0))->field_30 = 376.0f;
        {
            void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x44));

            b = (Vec2f *)D_0063F780;
            fclObjSetAnchorPosition(work->fD48, 0x56, 53.0f);
            sp158 = fclMakeVec2(b->x, -130.0f);
            sp150 = fclMakeVec2(b->x, b->y);
            fclObjStartPosition(work->fD48, sp158, sp150, 2, 5, 0);
            c20C = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fD48);
            ((FclObject *)t)->color = c20C;
            ((ShopWork *)fclObjectGetWork(work->fD48))->field_100 = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD48))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
            fclObjSetHoldTimer(work->fD48, (f32)D_0063FA44[0], D_0063FA46[0]);
            fclObjStartTween(work->fD48, D_0063FA40[0], 0.0f, 2, D_0063FA46[0] + 5, 0);
            sdkSpriteFreeNode(r);
        }
        {
            void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x43));

            b = (Vec2f *)D_0063F778;
            fa = (ShopSpinParam *)D_0063FA48;
            fclObjSetAnchorPosition(work->fD44, 0x56, 54.0f);
            sp148 = fclMakeVec2(b->x, -189.0f);
            sp140 = fclMakeVec2(b->x, b->y);
            fclObjStartPosition(work->fD44, sp148, sp140, 2, 5, 3);
            c208 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fD44);
            ((FclObject *)t)->color = c208;
            ((ShopWork *)fclObjectGetWork(work->fD44))->field_100 = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD44))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
            fclObjSetHoldTimer(work->fD44, (f32)fa->speed, fa->frames);
            fclObjStartTween(work->fD44, fa->angle, 0.0f, 2, fa->frames + 5, 3);
            sdkSpriteFreeNode(r);
        }
        {
            void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x45));

            b = (Vec2f *)D_0063F788;
            fa = (ShopSpinParam *)D_0063FA50;
            fclObjSetAnchorPosition(work->fD4C, 0x56, 55.0f);
            sp138 = fclMakeVec2(b->x, -75.0f);
            sp130 = fclMakeVec2(b->x, b->y);
            fclObjStartPosition(work->fD4C, sp138, sp130, 2, 5, 1);
            c204 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fD4C);
            ((FclObject *)t)->color = c204;
            ((ShopWork *)fclObjectGetWork(work->fD4C))->field_100 = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD4C))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
            fclObjSetHoldTimer(work->fD4C, (f32)fa->speed, fa->frames);
            fclObjStartTween(work->fD4C, fa->angle, 0.0f, 2, fa->frames + 5, 1);
            sdkSpriteFreeNode(r);
        }
        {
            void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x46));

            b = (Vec2f *)D_0063F790;
            fa = (ShopSpinParam *)D_0063FA58;
            fclObjSetAnchorPosition(work->fD50, 0x56, 56.0f);
            sp128 = fclMakeVec2(b->x, -165.0f);
            sp120 = fclMakeVec2(b->x, b->y);
            fclObjStartPosition(work->fD50, sp128, sp120, 2, 5, 4);
            c200 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fD50);
            ((FclObject *)t)->color = c200;
            ((ShopWork *)fclObjectGetWork(work->fD50))->field_100 = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD50))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD50))->field_C4 = 0.0f;
            fclObjSetHoldTimer(work->fD50, (f32)fa->speed, fa->frames);
            fclObjStartTween(work->fD50, fa->angle, 0.0f, 2, fa->frames + 5, 4);
            sdkSpriteFreeNode(r);
        }
        {
            void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x47));

            b = (Vec2f *)D_0063F798;
            fa = (ShopSpinParam *)D_0063FA60;
            fclObjSetAnchorPosition(work->fD54, 0x56, 57.0f);
            sp118 = fclMakeVec2(b->x, -126.0f);
            sp110 = fclMakeVec2(b->x, b->y);
            fclObjStartPosition(work->fD54, sp118, sp110, 2, 5, 2);
            c1FC = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fD54);
            ((FclObject *)t)->color = c1FC;
            ((ShopWork *)fclObjectGetWork(work->fD54))->field_100 = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD54))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD54))->field_C4 = 0.0f;
            fclObjSetHoldTimer(work->fD54, (f32)fa->speed, fa->frames);
            fclObjStartTween(work->fD54, fa->angle, 0.0f, 1, fa->frames + 5, 2);
            sdkSpriteFreeNode(r);
        }
        {
            void *r = sdkSpriteNewNode((u32)(work->fF28), (u32)(0x48));

            b = (Vec2f *)D_0063F7A0;
            fa = (ShopSpinParam *)D_0063FA68;
            fclObjSetAnchorPosition(work->fD58, 0x56, 58.0f);
            sp108 = fclMakeVec2(b->x, -197.0f);
            sp100 = fclMakeVec2(b->x, b->y);
            fclObjStartPosition(work->fD58, sp108, sp100, 2, 5, 5);
            c1F8 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fD58);
            ((FclObject *)t)->color = c1F8;
            ((ShopWork *)fclObjectGetWork(work->fD58))->field_100 = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD58))->field_102 = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
            ((ShopWork *)fclObjectGetWork(work->fD58))->field_C4 = 0.0f;
            fclObjSetHoldTimer(work->fD58, (f32)fa->speed, fa->frames);
            fclObjStartTween(work->fD58, fa->angle, 0.0f, 2, fa->frames + 5, 5);
            sdkSpriteFreeNode(r);
        }
        b = (Vec2f *)D_0063F7B0;
        fclObjSetAnchorPosition(work->fD60, 0x41, 78.0f);
        spF8 = fclMakeVec2(b->x, b->y - (f32)0x226);
        spF0 = fclMakeVec2(b->x, b->y);
        fclObjStartPosition(work->fD60, spF8, spF0, 2, 4, 0);
        ((ShopWork *)fclObjectGetWork(work->fD60))->field_100 = ((ShopWork *)fclObjectGetWork(work->fD60))->field_102 = 0;
        fclObjStartTween(work->fD60, -5.0f, fGpffff852c, 2, 2, 2);
        c1F4 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fD60);
        ((FclObject *)t)->color = c1F4;
        b = (Vec2f *)D_0063F7B8;
        fclObjSetAnchorPosition(work->fD64, 0x41, 78.0f);
        spE8 = fclMakeVec2(b->x, b->y - (f32)0x226);
        spE0 = fclMakeVec2(b->x, b->y);
        fclObjStartPosition(work->fD64, spE8, spE0, 2, 4, 0);
        ((ShopWork *)fclObjectGetWork(work->fD64))->field_100 = -0x32;
        ((ShopWork *)fclObjectGetWork(work->fD64))->field_102 = -0xDB;
        fclObjStartTween(work->fD64, -5.0f, fGpffff852c, 2, 2, 2);
        work->state = 0x15;
    }
    work->f14 = 0;
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
typedef struct {
    s16 f0;
    s16 f2;
    s16 f4;
} ShopBuySlidePrefix;
typedef struct {
    u8 state;
    u8 pad1;
    s16 cursor;
    s16 scroll;
    u8 pad6;
    s8 f7;
    u8 pad8[4];
    f32 step;
    u8 pad10;
    s8 sel;
    s16 qty;
    s8 busy;
    u8 pad15[0xC0B];
    u32 fC20;
    s8 fC24;
    u8 padC25[0x13];
    void *obj[0xB8];
    void *list[3];
    u8 padF24[4];
    void *font;
    u8 padF2C[0x10];
    s16 fF3C;
    u8 fF3E[3];
    u8 padF41;
    u8 fF42[3];
    u8 padF45[0x5B];
    /* Fifteen six-byte prefixes, at 0x20-byte item/0xA0-byte group
     * strides. The final prefix ends at 0x1166; selection starts 0x1168. */
    s16 slideWords[0xE4];
    s8 select[3];
    s8 scrollSave[3];
    u8 f116E;
    u8 pad116F;
    s16 f1170;
} ShopBuyWork;

typedef char ShopBuyWorkSize[sizeof(ShopBuyWork) == 0x1174 ? 1 : -1];
typedef char ShopBuySlidePrefixSize[sizeof(ShopBuySlidePrefix) == 6 ? 1 : -1];

/* Address a six-byte prefix within the complete allocated work object.
 * There is no array of complete 0x20-byte records at its truncated tail. */

#define O(off) obj[((off) - 0xC38) / 4]
#pragma push
#pragma opt_loop_invariants on
#pragma opt_lifetimes on
// FUN_002CDF80
void fclShopDrawBuyList(void *arg0, s8 arg1) {
    extern u8 D_0063FAA0[];
    extern f32 fGpffff8520;
    extern f32 fGpffff8524;
    extern f32 fGpffff8528;
    s8 fclObjHasStatusFlags(u8 *);
    s8 yListKindFor(void *);
    void func_002b3050(s32, s32, s32, s64, s32, s16 *, s16 *);
    s8 fclShopUpdateTabs(void *, s8);
    void fclShopDrawSelectRow(void *, s16);
    void fclShopLayoutPanels(void *);
    ShopBuyWork *work;
    s32 item;
    s16 i;
    s32 textColor;
    s32 iconColor;
    s32 lineColor;
    u8 *t;
    Vec2f *b;
    struct { s16 object; s16 ordinal; } cursor;
    s8 n;
    u32 price;
    u32 digits;
    u32 flags;
    s16 start;
    s16 cur;
    s16 row;
    s32 rowY;
    u8 *e;
    FclDrawColor rowColor;
    FclDrawColor bar0;
    FclDrawColor bar1;
    FclDrawColor bar2;
    FclDrawColor white0;
    FclDrawColor white1;
    FclDrawColor c204;
    FclDrawColor c200;
    FclDrawColor c1FC;
    FclDrawColor c1F8;
    FclDrawColor c1F4;
    FclDrawColor c1F0;
    FclDrawColor c1EC;
    FclDrawColor c1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    Vec2f sp1C8;
    Vec2f sp1C0;
    Vec2f sp1B8;
    void *r0;
    void *r1;
    void *r2;
    s16 top;

    work = *(ShopBuyWork **)((u8 *)arg0 + 0x38);
    top = yListLastIndexFor(work->list[work->sel]);
    item = yListValueAtFor(work->list[work->sel], work->cursor);
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(work->obj[i + 0x82], 0, 1);
    }
    if (yListKindFor(work->list[work->sel]) != 0) {
        goto clear;
    }
    if (yListCountFor(work->list[work->sel]) <= D_00748908[work->sel]) {
        fclObjSetAnchorPosition(work->O(0xE68), 0x57, 117.0f);
        bar0 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        t = (u8 *)fclObjectGetWork(work->O(0xE68));
        ((FclObject *)t)->color = bar0;
        fclObjSetAnchorPosition(work->O(0xE6C), 0x56, 118.0f);
        bar1 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
        t = (u8 *)fclObjectGetWork(work->O(0xE6C));
        ((FclObject *)t)->color = bar1;
        fclObjSetAnchorPosition(work->O(0xE70), 0x56, 119.0f);
        bar2 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
        t = (u8 *)fclObjectGetWork(work->O(0xE70));
        ((FclObject *)t)->color = bar2;
        fclObjChangeFlagBit(work->O(0xDCC), 0, 1);
        fclObjChangeFlagBit(work->O(0xDD0), 0, 1);
        fclObjChangeFlagBit(work->O(0xC8C), 0, 1);
        fclObjChangeFlagBit(work->O(0xC90), 0, 1);
    } else {
        if (yListCountFor(work->list[work->sel]) > 5) {
            if (yListCountFor(work->list[work->sel]) > 5) {
                work->step = 104.0f / (f32)(yListCountFor(work->list[work->sel]) - 5);
            }
            sp1C8 = fclMakeVec2((f32)0x221, 142.0f + work->step * (f32)(work->cursor - work->scroll));
            fclDrawEquipSprite(0x36, sp1C8, 138.0f, fclPackRgba(0xFF, 0xFE, 0xC6, 0x31), ((u8 *)fclObjectGetWork(work->O(0xC94)))[0x62], 0, D_00794EA0);
            fclObjChangeFlagBit(work->O(0xC8C), 0, 0);
            fclObjChangeFlagBit(work->O(0xC90), 0, 0);
        } else {
            fclObjChangeFlagBit(work->O(0xC8C), 0, 1);
            fclObjChangeFlagBit(work->O(0xC90), 0, 1);
        }
        if (work->sel == 0 && work->cursor == 0) {
            sp1C0 = fclMakeVec2((f32)0x24E, 61.0f);
            white0 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
            fclDrawNumber(sp1C0, 1.0f, white0, 0x11, 5, work->fC20, 0x70, 0x7A,
                          (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xAA);
        } else {
            price = datItemPrice((s16)item) / 5;
            sp1B8 = fclMakeVec2((f32)0x24E, 61.0f);
            white1 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
            fclDrawNumber(sp1B8, 1.0f, white1, 0x11, 5, work->qty * price, 0x70, 0x7A,
                          (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xAA);
        }
        b = (Vec2f *)D_0063F888;
        if (fclObjTestFlagBit(work->O(0xDCC), 1) == 0) {
            ((ShopWork *)fclObjectGetWork(work->O(0xDCC)))->field_30 = b->y + (f32)(work->scroll * 32);
        }
        if (fclObjTestFlagBit(work->O(0xDD0), 1) == 0) {
            ((ShopWork *)fclObjectGetWork(work->O(0xDD0)))->field_30 = b->y + (f32)(work->scroll * 32);
        }
        fclObjChangeFlagBit(work->O(0xE68), 0, 1);
        fclObjChangeFlagBit(work->O(0xE6C), 0, 1);
        fclObjChangeFlagBit(work->O(0xE70), 0, 1);
        n = (s8)fclAddClamped(0, yListCountFor(work->list[work->sel]), 5, 0, 1);
        start = work->cursor - work->scroll;
        for (cur = start, row = 0; cur < start + n; cur++, row++) {
            if (cur < yListCountFor(work->list[work->sel])) {
                textColor = fclPackRgba(0xFF, 0xAE, 0, ((u8 *)fclObjectGetWork(work->O(0xC8C)))[0x62]);
                iconColor = fclPackRgba(0, 0xFF, 0xAE, 0);
                rowColor = fclMakeDrawColor(0xFF, 0xAE, 0, ((u8 *)fclObjectGetWork(work->O(0xC8C)))[0x62]);
                lineColor = fclPackRgba(0, 0xFE, 0xC7, 0x31);
                if (cur == work->cursor) {
                    textColor = fclPackRgba(0x2D, 0x2D, 0x2D, ((u8 *)fclObjectGetWork(work->O(0xC8C)))[0x62]);
                    iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                    rowColor = fclMakeDrawColor(0x2D, 0x2D, 0x2D, ((u8 *)fclObjectGetWork(work->O(0xC8C)))[0x62]);
                    lineColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                }
                if (work->sel == 0 && cur == 0) {
                    if (yListCountFor(work->list[work->sel]) > 1) {
                        {
                            s16 i2;

                            for (i2 = 0; i2 < 3; i2++) {
                                fclDrawEquipSprite(0x3C, fclMakeVec2((f32)((i2 << 5) + 0x6F), 143.0f), 115.0f, lineColor, 0xFF, 0, D_00795E60);
                                fclDrawEquipSprite(0x3C, fclMakeVec2((f32)((i2 << 5) + 0x1A1), 143.0f), 115.0f, lineColor, 0xFF, 0, D_00795E60);
                            }
                        }
                        fclObjSetAnchorPosition(work->O(0xE44), 0x56, 121.0f);
                        c204 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                        t = (u8 *)fclObjectGetWork(work->O(0xE44));
                        ((FclObject *)t)->color = c204;
                        if (cur == work->cursor) {
                            c200 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                            t = (u8 *)fclObjectGetWork(work->O(0xE44));
                            ((FclObject *)t)->color = c200;
                        }
                        fclObjSetAnchorPosition(work->O(0xE48), 0x56, 122.0f);
                        c1FC = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                        t = (u8 *)fclObjectGetWork(work->O(0xE48));
                        ((FclObject *)t)->color = c1FC;
                        if (cur == work->cursor) {
                            c1F8 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                            t = (u8 *)fclObjectGetWork(work->O(0xE48));
                            ((FclObject *)t)->color = c1F8;
                        }
                        fclObjSetAnchorPosition(work->O(0xE40), 0x57, 120.0f);
                        c1F4 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                        t = (u8 *)fclObjectGetWork(work->O(0xE40));
                        ((FclObject *)t)->color = c1F4;
                        if (cur == work->cursor) {
                            c1F0 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                            t = (u8 *)fclObjectGetWork(work->O(0xE40));
                            ((FclObject *)t)->color = c1F0;
                        }
                    }
                } else {
                    b = (Vec2f *)D_0063F888;
                    rowY = row << 5;
                    sp1D8 = fclMakeVec2(b->x, b->y + (f32)rowY);
                    sp1E0 = fclMakeVec2(10.0f + sp1D8.x, 9.0f + sp1D8.y);
                    sp1D0 = fclMakeVec2(70.0f, 126.0f + (f32)rowY);
                    if (row == work->scroll) {
                        f32 mx = 10.0f + ((ShopWork *)fclObjectGetWork(work->O(0xDCC)))->field_2C;

                        sp1E0 = fclMakeVec2(mx, 9.0f + ((ShopWork *)fclObjectGetWork(work->O(0xDCC)))->field_30);
                        sp1D0 = *(Vec2f *)((u8 *)fclObjectGetWork(work->O(0xDCC)) + 0x2C);
                    }
                    flags = datEntryGetFlags((s16)yListValueAtFor(work->list[work->sel], cur));
                    if (flags & 0x81) {
                        fclDrawEquipSprite(0x14, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x102) {
                        fclDrawEquipSprite(0x15, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x204) {
                        fclDrawEquipSprite(0x16, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x408) {
                        fclDrawEquipSprite(0x17, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x810) {
                        fclDrawEquipSprite(0x18, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x1020) {
                        fclDrawEquipSprite(0x19, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x2040) {
                        fclDrawEquipSprite(0x1A, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x4000) {
                        fclDrawEquipSprite(0x1B, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x8000) {
                        fclDrawEquipSprite(0x1C, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else if (flags & 0x40000) {
                        fclDrawEquipHelpSprite(0x1A, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    } else {
                        fclDrawEquipHelpSprite(0x1B, sp1E0, 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    }
                    shopDrawLabel(115.0f, ((void *)datGetItemNameId((s16)yListValueAtFor(work->list[work->sel], cur))), fclMakeVec2(53.0f + sp1D0.x, 7.0f + sp1D0.y), textColor);
                    digits = datItemPrice((s16)yListValueAtFor(work->list[work->sel], cur)) / 5;
                    fclDrawNumber(fclMakeVec2(372.0f + sp1D0.x, 16.0f + sp1D0.y), 115.0f, rowColor, 0x10, 5, digits, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->font, 0xA9);
                    fclDrawEquipSprite(0x47, fclMakeVec2(400.0f + sp1D0.x, 18.0f + sp1D0.y), 115.0f, iconColor, 0xFF, 0, D_00795E60);
                    fclDrawNumber(fclMakeVec2((f32)0x1AF + sp1D0.x, 16.0f + sp1D0.y), 115.0f, rowColor, 0x10, 5, datItemCount((s16)yListValueAtFor(work->list[work->sel], cur)) & 0xFF, 9, 0x7B,
                                  (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->font, 0xA9);
                }
            }
        }
    }
    if (arg1 != 2 && fclObjTestFlagBit(work->O(0xDCC), 1) == 0 && fclObjTestFlagBit(work->O(0xDD0), 1) == 0
        && fclObjHasStatusFlags(work->O(0xD44)) == 0 && fclObjHasStatusFlags(work->O(0xD48)) == 0
        && fclObjHasStatusFlags(work->O(0xD4C)) == 0 && fclObjHasStatusFlags(work->O(0xD50)) == 0
        && fclObjHasStatusFlags(work->O(0xD54)) == 0 && fclObjHasStatusFlags(work->O(0xD58)) == 0) {
        if ((D_008C0276[0] & 0x1000) && work->busy == 0) {
            if (yListCountFor(work->list[work->sel]) > D_00748908[work->sel]) {
                if (arg1 == 1 && work->sel == 0 && work->cursor == 1) {
                    sdkSndStartStream(0, 0, 0, 0);
                    work->cursor = fclSubClamped(work->cursor, 1, 0, (s16)yListCountFor(work->list[work->sel]), 2);
                    work->scroll = yListStepIndex(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, -1);
                }
                if (work->cursor == 0) {
                    sdkSndStartStream(0, 0, 0, 0);
                    work->cursor = top;
                    work->scroll = fclAddClamped(0, top, 4, 0, 1);
                } else {
                    sdkSndStartStream(0, 0, 0, 0);
                    work->cursor = fclSubClamped(work->cursor, 1, 0, (s16)yListCountFor(work->list[work->sel]), 2);
                    work->scroll = yListStepIndex(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, -1);
                }
                work->busy = 1;
            }
        } else if (D_008C027A[0] & 0x1000) {
            if (yListCountFor(work->list[work->sel]) > D_00748908[work->sel] && (arg1 != 1 || work->sel != 0 || work->cursor != 1)) {
                if (yListCountFor(work->list[work->sel]) > 0) {
                    if (work->cursor != 0) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    work->cursor = fclSubClamped(work->cursor, 1, 0, 0, 1);
                    work->scroll = yListStepIndex(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, -1);
                }
                work->busy = 1;
            }
        } else if ((D_008C0276[0] & 0x4000) && work->busy == 0) {
            if (yListCountFor(work->list[work->sel]) > D_00748908[work->sel]) {
                sdkSndStartStream(0, 0, 0, 0);
                work->cursor = fclAddClamped(work->cursor, 1, top, 0, 2);
                if (work->cursor == 0) {
                    work->scroll = 0;
                    if (work->sel == 0 && work->fC24 == 1) {
                        work->cursor = 1;
                        work->scroll = 1;
                    }
                } else if (top >= 5) {
                    work->scroll = yListStepIndex(work->cursor, work->scroll, top, 5, 1);
                } else {
                    work->scroll = yListStepIndex(work->cursor, work->scroll, top, yListCountFor(work->list[work->sel]), 1);
                }
                work->busy = 1;
            }
        } else if (D_008C027A[0] & 0x4000) {
            if (yListCountFor(work->list[work->sel]) > D_00748908[work->sel]) {
                if (yListCountFor(work->list[work->sel]) > 0) {
                    if (work->cursor != top) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    work->cursor = fclAddClamped(work->cursor, 1, top, 0, 1);
                    if (top >= 5) {
                        work->scroll = yListStepIndex(work->cursor, work->scroll, top, 5, 1);
                    } else {
                        work->scroll = yListStepIndex(work->cursor, work->scroll, top, yListCountFor(work->list[work->sel]), 1);
                    }
                    work->busy = 1;
                }
                return;
            }
        } else if ((D_008C027A[0] & 2) || (D_008C027A[0] & 0x2000)) {
            if (yListCountFor(work->list[work->sel]) > D_00748908[work->sel]) {
                if (work->cursor != top) {
                    sdkSndStartStream(0, 0, 0, 0);
                }
                yListAdvanceCursorScroll(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, &work->cursor, &work->scroll);
                goto clear;
            }
        } else if ((D_008C027A[0] & 1) || (D_008C027A[0] & 0x8000)) {
            n = D_00748908[work->sel];
            if (n < yListCountFor(work->list[work->sel])) {
                if (work->fC24 == 0) {
                    if (work->cursor != 0) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    yListRetreatCursorScroll(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, &work->cursor, &work->scroll);
                } else {
                    if (work->cursor != n) {
                        sdkSndStartStream(0, 0, 0, 0);
                    }
                    if (work->sel == 0) {
                        func_002b3050(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, 1, &work->cursor, &work->scroll);
                    } else {
                        yListRetreatCursorScroll(work->cursor, work->scroll, yListCountFor(work->list[work->sel]), 5, &work->cursor, &work->scroll);
                    }
                }
                goto clear;
            }
        } else if (D_008C027A[0] & 8) {
            if (work->fC24 != 1) {
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
                work->select[work->sel] = work->cursor;
                work->scrollSave[work->sel] = work->scroll;
                work->f116E = work->sel;
                if (yListCountFor(work->list[work->sel]) >= 5) {
                    work->f1170 = (work->slideWords + work->sel * 0x50)[(4) * 0x10] + 4;
                } else {
                    work->f1170 = (work->slideWords + work->sel * 0x50)[(yListCountFor(work->list[work->sel])) * 0x10] + yListCountFor(work->list[work->sel]);
                }
                work->sel = fclAddClamped(work->sel, 1, 2, 0, 2);
                fclShopUpdateTabs(arg0, (s32)work->sel);
                fclShopDrawSelectRow(arg0, work->sel);
                work->cursor = 0;
                work->scroll = 0;
                work->select[work->sel] = 0;
                work->scrollSave[work->sel] = 0;
                if (yListCountFor(work->list[work->sel]) >= 5) {
                    work->f1170 = (work->slideWords + work->sel * 0x50)[(4) * 0x10] + 4;
                } else {
                    if (work->f1170 < (s16)((work->slideWords + work->sel * 0x50)[(yListCountFor(work->list[work->sel])) * 0x10] + yListCountFor(work->list[work->sel]))) {
                        work->f1170 = (work->slideWords + work->sel * 0x50)[(yListCountFor(work->list[work->sel])) * 0x10] + yListCountFor(work->list[work->sel]);
                    }
                }
                n = work->sel;
                switch (n) {
                case 0:
                    yListRebuildFor(work->list[n], 0x40000, 0, 4, 0);
                    break;
                case 1:
                    yListRebuildFor(work->list[n], 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:
                    yListRebuildFor(work->list[n], 0x10000, 0, 1, 0);
                    break;
                }
                work->state = 0x33;
                sdkSndStartStream(0, 0, 0, 5);
                goto clear;
            }
        } else if (D_008C027A[0] & 4) {
            if (work->fC24 != 1) {
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
                work->select[work->sel] = work->cursor;
                work->scrollSave[work->sel] = work->scroll;
                work->f116E = work->sel;
                if (yListCountFor(work->list[work->sel]) >= 5) {
                    work->f1170 = (work->slideWords + work->sel * 0x50)[(4) * 0x10] + 4;
                } else {
                    work->f1170 = (work->slideWords + work->sel * 0x50)[(yListCountFor(work->list[work->sel])) * 0x10] + yListCountFor(work->list[work->sel]);
                }
                work->sel = fclSubClamped(work->sel, 1, 0, 2, 2);
                fclShopUpdateTabs(arg0, (s32)work->sel);
                fclShopDrawSelectRow(arg0, work->sel);
                work->cursor = 0;
                work->scroll = 0;
                work->select[work->sel] = 0;
                work->scrollSave[work->sel] = 0;
                if (yListCountFor(work->list[work->sel]) >= 5) {
                    work->f1170 = (work->slideWords + work->sel * 0x50)[(4) * 0x10] + 4;
                } else {
                    if (work->f1170 < (s16)((work->slideWords + work->sel * 0x50)[(yListCountFor(work->list[work->sel])) * 0x10] + yListCountFor(work->list[work->sel]))) {
                        work->f1170 = (work->slideWords + work->sel * 0x50)[(yListCountFor(work->list[work->sel])) * 0x10] + yListCountFor(work->list[work->sel]);
                    }
                }
                n = work->sel;
                switch (n) {
                case 0:
                    yListRebuildFor(work->list[n], 0x40000, 0, 4, 0);
                    break;
                case 1:
                    yListRebuildFor(work->list[n], 0xFFFF, 0x1FE0, 1, 0);
                    break;
                case 2:
                    yListRebuildFor(work->list[n], 0x10000, 0, 1, 0);
                    break;
                }
                work->state = 0x34;
                sdkSndStartStream(0, 0, 0, 5);
                goto clear;
            }
        } else if (D_008C024E[0] & 0x40) {
            if (yListCountFor(work->list[work->sel]) <= D_00748908[work->sel]) {
                sdkSndStartStream(0, 0, 0, 8);
                return;
            }
            work->qty = 1;
            if (work->sel == 0 && work->cursor - work->scroll == 0 && yListCountFor(work->list[work->sel]) < 2) {
                sdkSndStartStream(0, 0, 0, 8);
                return;
            }
            if (yListCountFor(work->list[work->sel]) > 0) {
                work->fF3E[0] = ((u8 *)fclObjectGetWork(work->O(0xDCC)))[0x79];
                work->fF3E[1] = ((u8 *)fclObjectGetWork(work->O(0xDCC)))[0x7A];
                work->fF3E[2] = ((u8 *)fclObjectGetWork(work->O(0xDCC)))[0x7B];
                work->fF42[0] = ((u8 *)fclObjectGetWork(work->O(0xDD0)))[0x79];
                work->fF42[1] = ((u8 *)fclObjectGetWork(work->O(0xDD0)))[0x7A];
                work->fF42[2] = ((u8 *)fclObjectGetWork(work->O(0xDD0)))[0x7B];
                work->fF3C = 0;
                work->state = 0x25;
                sdkSndStartStream(0, 0, 0, 1);
            }
            goto clear;
        } else if (D_008C024E[0] & 0x80) {
            if (yListCountFor(work->list[work->sel]) > D_00748908[work->sel] && arg1 != 1) {
                if (fclObjTestFlagBit(work->O(0xE38), 1) == 1 || fclObjTestFlagBit(work->O(0xCC4), 1) == 1
                    || fclObjTestFlagBit(work->O(0xCC0), 1) == 1) {
                    return;
                }
                if ((work->sel != 0 || work->cursor != 0) && yListCountFor(work->list[work->sel]) > 0) {
                    work->fF3E[0] = ((u8 *)fclObjectGetWork(work->O(0xDCC)))[0x79];
                    work->fF3E[1] = ((u8 *)fclObjectGetWork(work->O(0xDCC)))[0x7A];
                    work->fF3E[2] = ((u8 *)fclObjectGetWork(work->O(0xDCC)))[0x7B];
                    work->fF42[0] = ((u8 *)fclObjectGetWork(work->O(0xDD0)))[0x79];
                    work->fF42[1] = ((u8 *)fclObjectGetWork(work->O(0xDD0)))[0x7A];
                    work->fF42[2] = ((u8 *)fclObjectGetWork(work->O(0xDD0)))[0x7B];
                    work->fF3C = 0;
                    fclObjStartSlideFade(work->O(0xEC4), 3, 1.0f, fGpffff8504, 6, 0, 0);
                    fclObjStartSlideFade(work->O(0xEC8), 4, 1.0f, fGpffff8504, 6, 0, 0);
                    fclObjStartSlideFade(work->O(0xE38), 0x80, 1.0f, fGpffff8504, 6, 0, 0);
                    fclObjStartSlideFade(work->O(0xEB4), 3, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjStartSlideFade(work->O(0xEB8), 4, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjStartSlideFade(work->O(0xCC4), 0x23, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjStartSlideFade(work->O(0xEBC), 3, 1.0f, fGpffff8504, 6, 2, 0);
                    fclObjStartSlideFade(work->O(0xEC0), 4, 1.0f, fGpffff8504, 6, 2, 0);
                    fclObjStartSlideFade(work->O(0xCC0), 0x22, 1.0f, fGpffff8504, 6, 1, 0);
                    fclObjChangeFlagBit(work->O(0xDDC), 0, 1);
                    fclObjChangeFlagBit(work->O(0xDE4), 0, 1);
                    fclObjChangeFlagBit(work->O(0xDE0), 0, 0);
                    work->state = 0x2F;
                    sdkSndStartStream(0, 1, 0, 3);
                }
                goto clear;
            }
        } else if (D_008C024E[0] & 0x20) {
            if (arg1 != 1) {
                sdkSndStartStream(0, 0, 0, 2);
                b = (Vec2f *)D_0063F5B8;
                fclObjStartPosition(work->O(0xC64), fclMakeVec2(b->x, b->y), fclMakeVec2(b->x, 300.0f + b->y), 0, 0xA, 0);
                fclObjStartAlpha(work->O(0xC64), ((u8 *)fclObjectGetWork(work->O(0xC64)))[0x62], 0, 0, 0xA, 0);
                fclObjSetAnchorPosition(work->O(0xD74), 0x56, 11.0f);
                fclObjStartAlpha(work->O(0xD74), 0xFF, 0, 0, 0xA, 0);
                fclObjSetAnchorPosition(work->O(0xD80), 0x56, 9.0f);
                fclObjStartAlpha(work->O(0xD80), 0xFF, 0, 0, 0xA, 0);
                {
                    for (cursor.object = 0x43, cursor.ordinal = 0; cursor.object < 0x49; cursor.object++, cursor.ordinal++) {
                        fclObjStartPosition(work->obj[cursor.object], fclMakeVec2(((ShopWork *)fclObjectGetWork(work->obj[cursor.object]))->field_2C, ((ShopWork *)fclObjectGetWork(work->obj[cursor.object]))->field_30), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->obj[cursor.object]))->field_2C, 170.0f + ((ShopWork *)fclObjectGetWork(work->obj[cursor.object]))->field_30), 1, 5, 0);
                    }
                }
                fclObjStartAlpha(work->O(0xC8C), 0xFF, 0, 0, 6, 0);
                fclObjStartAlpha(work->O(0xC90), 0xFF, 0, 0, 6, 0);
                {
                    s16 k;

                    for (k = 0; k < 3; k++) {
                        fclObjChangeFlagBit(work->obj[k + 0x82], 0, 1);
                    }
                }
                fclObjChangeFlagBit(work->O(0xDCC), 0, 1);
                fclObjChangeFlagBit(work->O(0xDD0), 0, 1);
                e = fclObjectGetWork(work->O(0xEC4));
                fclObjStartPosition(work->O(0xEC4), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xEC4)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xEC4)))->field_30), 2, 0xF, 0);
                e = fclObjectGetWork(work->O(0xEC8));
                fclObjStartPosition(work->O(0xEC8), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xEC8)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xEC8)))->field_30), 2, 0xF, 0);
                e = fclObjectGetWork(work->O(0xE38));
                fclObjStartPosition(work->O(0xE38), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xE38)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xE38)))->field_30), 2, 0xF, 0);
                e = fclObjectGetWork(work->O(0xEB4));
                fclObjStartPosition(work->O(0xEB4), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xEB4)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xEB4)))->field_30), 2, 0xF, 1);
                e = fclObjectGetWork(work->O(0xEB8));
                fclObjStartPosition(work->O(0xEB8), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xEB8)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xEB8)))->field_30), 2, 0xF, 1);
                e = fclObjectGetWork(work->O(0xCC4));
                fclObjStartPosition(work->O(0xCC4), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xCC4)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xCC4)))->field_30), 2, 0xF, 1);
                e = fclObjectGetWork(work->O(0xEBC));
                fclObjStartPosition(work->O(0xEBC), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xEBC)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xEBC)))->field_30), 2, 0xF, 2);
                e = fclObjectGetWork(work->O(0xEC0));
                fclObjStartPosition(work->O(0xEC0), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xEC0)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xEC0)))->field_30), 2, 0xF, 2);
                e = fclObjectGetWork(work->O(0xCC0));
                fclObjStartPosition(work->O(0xCC0), *(Vec2f *)(e + 0x2C), fclMakeVec2(((ShopWork *)fclObjectGetWork(work->O(0xCC0)))->field_2C, 500.0f + ((ShopWork *)fclObjectGetWork(work->O(0xCC0)))->field_30), 2, 0xF, 2);
                {
                    s16 i5;

                    for (i5 = 0x8C; i5 < 0x8F; i5++) {
                        if (fclObjTestFlagBit(work->obj[i5], 0) == 1) {
                            fclObjChangeFlagBit(work->obj[i5], 0, 1);
                        }
                    }
                }
                {
                    s16 i6;

                    for (i6 = 0; i6 < 3; i6++) {
                        fclObjStartAlpha(work->obj[i6], 0, 0xFF, 0, 0xA, 0);
                    }
                }
                {
                    for (cursor.ordinal = 0; cursor.ordinal < 7; cursor.ordinal++) {
                        b = (Vec2f *)D_0063F560 + (cursor.ordinal + 0x3A);
                        fclObjSetAnchorPosition(work->obj[cursor.ordinal + 0x3A], 0x56, (f32)(cursor.ordinal + 0x64));
                        if (cursor.ordinal > 0) {
                            c1EC = fclMakeDrawColor(0xED, 0x80, 0, 0xFF);
                            t = (u8 *)fclObjectGetWork(work->obj[cursor.ordinal + 0x3A]);
                            ((FclObject *)t)->color = c1EC;
                        }
                        fclObjStartPosition(work->obj[cursor.ordinal + 0x3A], fclMakeVec2(80.0f + b->x, b->y), fclMakeVec2(b->x, b->y), 0, 3, cursor.ordinal);
                        fclObjStartAlpha(work->obj[cursor.ordinal + 0x3A], 0, 0xFF, 0, 3, cursor.ordinal);
                    }
                }
                c1E8 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                t = (u8 *)fclObjectGetWork(work->obj[work->f7 + 0x3B]);
                ((FclObject *)t)->color = c1E8;
                fclObjStartAlpha(work->O(0xC44), 0, 0xFF, 0, 0, work->f7);
                fclObjStartAlpha(work->O(0xC48), 0, 0xFF, 0, 0, work->f7);
                {
                    s16 i8;

                    for (i8 = 0; i8 < 3; i8++) {
                        fclObjStartAlpha(work->obj[i8], 0, 0xFF, 0, 0xA, 0);
                    }
                }
                fclObjSetAnchorPosition(work->O(0xDE8), 0x41, 46.0f);
                fclObjStartAlpha(work->O(0xDE8), 0, 0xFF, 0, 6, 0);
                ((ShopWork *)fclObjectGetWork(work->O(0xDE8)))->field_2C = 198.0f;
                ((ShopWork *)fclObjectGetWork(work->O(0xDE8)))->field_30 = (f32)0x151;
                fclObjSetAnchorPosition(work->O(0xDEC), 0x41, 146.0f);
                fclObjStartAlpha(work->O(0xDEC), 0, 0xFF, 0, 6, 0);
                ((ShopWork *)fclObjectGetWork(work->O(0xDEC)))->field_2C = 216.0f;
                ((ShopWork *)fclObjectGetWork(work->O(0xDEC)))->field_30 = 368.0f;
                fclObjSetAnchorPosition(work->O(0xDDC), 0x41, 49.0f);
                fclObjStartAlpha(work->O(0xDDC), 0xFF, 0, 0, 0xA, 0);
                fclObjSetAnchorPosition(work->O(0xDF0), 0x41, 47.0f);
                fclObjStartAlpha(work->O(0xDF0), 0xFF, 0, 0, 0xA, 0);
                fclObjStartPosition(work->O(0xDF0), fclMakeVec2((f32)0x103, 404.0f), fclMakeVec2((f32)0x103, 404.0f), 0, 0, 0);
                fclObjSetAnchorPosition(work->O(0xDE4), 0x41, 47.0f);
                fclObjStartAlpha(work->O(0xDE4), 0xFF, 0, 0, 0xA, 0);
                fclObjStartPosition(work->O(0xDE4), fclMakeVec2(338.0f, 404.0f), fclMakeVec2(338.0f, 404.0f), 0, 0, 0);
                ((ShopWork *)fclObjectGetWork(work->O(0xDE8)))->field_2C = 198.0f;
                ((ShopWork *)fclObjectGetWork(work->O(0xDE8)))->field_30 = (f32)0x151;
                fclObjSetAnchorPosition(work->O(0xC4C), 0x40, 191.0f);
                {
                    r0 = sdkSpriteNewNode((u32)(work->font), (u32)(5));
                    *(s16 *)((u8 *)fclObjectGetWork(work->O(0xC4C)) + 0x100) = sdkSpriteScaledWidth(r0);
                    *(s16 *)((u8 *)fclObjectGetWork(work->O(0xC4C)) + 0x102) = sdkSpriteScaledHeight(r0);
                    sdkSpriteFreeNode(r0);
                }
                fclObjStartAlpha(work->O(0xC4C), 0, 0xCC, 0, 4, 4);
                fclObjStartTween(work->O(0xC4C), 0.0f, fGpffff8520, 0, 4, 4);
                fclObjStartPosition(work->O(0xC4C), fclMakeVec2(-240.0f, 400.0f), fclMakeVec2(-240.0f, 310.0f), 0, 4, 4);
                fclObjSetAnchorPosition(work->O(0xC50), 0x40, 192.0f);
                ((ShopWork *)fclObjectGetWork(work->O(0xC50)))->field_2C = 110.0f;
                ((ShopWork *)fclObjectGetWork(work->O(0xC50)))->field_30 = -50.0f;
                {
                    r1 = sdkSpriteNewNode((u32)(work->font), (u32)(6));
                    *(s16 *)((u8 *)fclObjectGetWork(work->O(0xC50)) + 0x100) = sdkSpriteScaledWidth(r1);
                    *(s16 *)((u8 *)fclObjectGetWork(work->O(0xC50)) + 0x102) = 0;
                    fclObjStartTween(work->O(0xC50), -90.0f, fGpffff8524, 0, 4, 4);
                    fclObjStartAlpha(work->O(0xC50), 0, 0xFF, 0, 4, 4);
                    sdkSpriteFreeNode(r1);
                }
                fclObjSetAnchorPosition(work->O(0xE7C), 0x40, 190.0f);
                ((ShopWork *)fclObjectGetWork(work->O(0xE7C)))->field_2C = 180.0f;
                ((ShopWork *)fclObjectGetWork(work->O(0xE7C)))->field_30 = 30.0f;
                {
                    r2 = sdkSpriteNewNode((u32)(work->font), (u32)(6));
                    *(s16 *)((u8 *)fclObjectGetWork(work->O(0xE7C)) + 0x100) = sdkSpriteScaledWidth(r2);
                    *(s16 *)((u8 *)fclObjectGetWork(work->O(0xE7C)) + 0x102) = 0;
                    sdkSpriteFreeNode(r2);
                }
                fclObjStartTween(work->O(0xE7C), -85.0f, fGpffff8528, 0, 4, 2);
                fclObjStartAlpha(work->O(0xE7C), 0, 0xFF, 0, 4, 2);
                fclShopLayoutPanels(arg0);
                work->state = 0x11;
            clear:
                work->busy = 0;
            }
        } else {
            goto clear;
        }
    }
}
#pragma pop
#undef O

/* MATCHED fclShopListInputStep: written over the shared ShopMenuWork overlay with
   one named slot per retail stack address (27 FclDrawColor, 57 Vec2f, the
   0x130/0x128/0x110/... label positions copied via *(Vec2f *)&); both
   work[7] dispatches as 0/1/2 switches; each loop gets its own s16 counter;
   the DBC/E88 handle arrays addressed as work + i*4 (retail CSEs that sum);
   stat deltas computed once into `d`; datItemValue takes s16 and the
   second-switch stat reads widen func_00106cd0's s16 result with (s32), as
   retail re-extends only there; the E60 handle loaded before the shared
   fGpffff8530 argument. */
// FUN_002D1590
s32 fclShopListInputStep(void *arg0)
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
    FclDrawColor c2AC;
    FclDrawColor c2A8;
    FclDrawColor c2A4;
    FclDrawColor c2A0;
    FclDrawColor c29C;
    FclDrawColor c298;
    FclDrawColor c294;
    FclDrawColor c290;
    FclDrawColor c28C;
    FclDrawColor c288;
    FclDrawColor c284;
    FclDrawColor c280;
    FclDrawColor c27C;
    FclDrawColor c278;
    FclDrawColor c274;
    FclDrawColor c270;
    FclDrawColor c26C;
    FclDrawColor c268;
    FclDrawColor c264;
    FclDrawColor c260;
    FclDrawColor c25C;
    FclDrawColor c258;
    FclDrawColor c254;
    FclDrawColor c250;
    FclDrawColor c24C;
    FclDrawColor c248;
    FclDrawColor c244;
    Vec2f sp238;
    Vec2f sp230;
    Vec2f sp228;
    Vec2f sp220;
    Vec2f sp218;
    Vec2f sp210;
    Vec2f sp208;
    Vec2f sp200;
    Vec2f sp1F8;
    Vec2f sp1F0;
    Vec2f sp1E8;
    Vec2f sp1E0;
    Vec2f sp1D8;
    Vec2f sp1D0;
    Vec2f sp1C8;
    Vec2f sp1C0;
    Vec2f sp1B8;
    Vec2f sp1B0;
    Vec2f sp1A8;
    Vec2f sp1A0;
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    ShopMenuWork *work;
    u8 *t;
    Vec2f *b;
    s32 colA;
    s32 colB;
    s32 white;
    s16 dash;
    s16 mark;
    s16 dash2;
    s16 slot;
    s16 k;
    u32 stock;
    s32 uA;
    s32 uB;
    s32 d;

    work = *(ShopMenuWork **)((u8 *)arg0 + 0x38);
    c2A8 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    *(FclDrawColor *)&c2AC = *(FclDrawColor *)&c2A8;
    colA = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
    colB = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
    sp238 = fclMakeVec2(51.0f, 48.0f);
    fclShopDrawItemText(arg0, work->kind[work->sel], sp238, (void *)fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF));
    sp230 = fclMakeVec2((f32)0x24E, 61.0f);
    c2A4 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
    fclDrawNumber(sp230, 1.0f, c2A4, 0x11, 5, datItemPrice((s16)yListValueAt(work->f2)), 0x70, 0x7A,
                  (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xAA);
    if (fclObjHasStatusFlags(work->fC60) == 0 && fclObjHasStatusFlags(work->fC80) == 0 && fclObjHasStatusFlags(work->fC70) == 0 &&
        fclObjHasStatusFlags(work->fC84) == 0 && fclObjHasStatusFlags(work->fC74) == 0 && fclObjHasStatusFlags(work->fC78) == 0) {
        stock = datItemPrice((s16)yListValueAt(work->f2));
        if (stock > fclGetMoney() || (datItemCount((s16)yListValueAt(work->f2)) & 0xFF) == 0x63) {
            colA = fclPackRgba(0, 0xA6, 0x7F, 0x2B);
            c2AC = fclMakeDrawColor(0xA6, 0x7F, 0x2B, 0xFF);
            colB = fclPackRgba(0xA6, 0x7F, 0x2B, 0xFF);
        }
        sp228 = fclMakeVec2(129.0f, 255.0f);
        sp130 = *(Vec2f *)&sp228;
        frFontExDrawTextDeferredWithCharWidth(sp130.x, sp130.y, 70.0f, colB, 0, 1, ((void *)datGetItemNameId((s16)yListValueAt(work->f2))), 0, 0, D_00794ED0, -1);
        if (datItemValue((s16)yListValueAt(work->f2)) == 0) {
            for (dash = 0; dash < 0xF; dash++) {
                sp220 = fclMakeVec2((f32)(dash * 0x16 + 0x6F), (f32)0x12B);
                fclDrawEquipSprite(0x3C, sp220, 86.0f, fclPackRgba(0xFF, 0xFF, 0xC7, 0x31), 0xFF, 0, D_00794ED0);
            }
        } else {
            fclMesWindowDraw(datItemValue((s16)yListValueAt(work->f2)), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0x57, 109.0f, 290.0f, 70.0f);
        }
        switch (work->f7) {
        case 0:
            fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(work->f2)), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 0, 0x57, 109.0f, 324.0f, 70.0f);
            sp218 = fclMakeVec2(86.0f, 256.0f);
            fclDrawEquipSprite(work->icon[work->sel], sp218, 69.0f, colA, 0xFF, 0, D_00794ED0);
            fclObjSetAnchorPosition(work->fCA0, 0x57, 83.0f);
            c2A0 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fCA0);
            ((FclObject *)t)->color = c2A0;
            fclObjSetAnchorPosition(work->fCA8, 0x57, 82.0f);
            c29C = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fCA8);
            ((FclObject *)t)->color = c29C;
            sp210 = fclMakeVec2((f32)0x206, 324.0f);
            sp128 = *(Vec2f *)&sp210;
            uA = func_001068b0((s16)yListValueAt(work->f2));
            uB = func_001068b0(func_00106cd0(work->kind[work->sel], 0));
            d = func_001068b0((s16)yListValueAt(work->f2)) - uB;
            if (d < 0) {
                sp120 = fclMakeVec2(12.0f + sp128.x, sp128.y - 18.0f);
                fclDrawEquipSprite(0x29, sp120, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (d > 0) {
                sp118 = fclMakeVec2(12.0f + sp128.x, sp128.y - 18.0f);
                fclDrawEquipSprite(0x28, sp118, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            spB0 = fclMakeVec2(sp128.x + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), sp128.y);
            c260 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(spB0, 22.0f, c260, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            sp208 = fclMakeVec2((f32)0x206, 374.0f);
            sp110 = *(Vec2f *)&sp208;
            uA = func_001068e0((s16)yListValueAt(work->f2));
            uB = func_001068e0(func_00106cd0(work->kind[work->sel], 0));
            d = func_001068e0((s16)yListValueAt(work->f2)) - uB;
            if (d < 0) {
                sp108 = fclMakeVec2(12.0f + sp110.x, sp110.y - 18.0f);
                fclDrawEquipSprite(0x29, sp108, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (d > 0) {
                sp100 = fclMakeVec2(12.0f + sp110.x, sp110.y - 18.0f);
                fclDrawEquipSprite(0x28, sp100, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            spA8 = fclMakeVec2(sp110.x + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), sp110.y);
            c25C = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(spA8, 22.0f, c25C, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 1:
            fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(work->f2)), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 1, 0x57, 109.0f, 324.0f, 70.0f);
            sp200 = fclMakeVec2(86.0f, 256.0f);
            fclDrawEquipSprite(0x1B, sp200, 69.0f, colA, 0xFF, 0, D_00794ED0);
            fclObjSetAnchorPosition(work->fC9C, 0x57, 81.0f);
            c298 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fC9C);
            ((FclObject *)t)->color = c298;
            fclObjSetAnchorPosition(work->fCA4, 0x57, 80.0f);
            c294 = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fCA4);
            ((FclObject *)t)->color = c294;
            sp1F8 = fclMakeVec2((f32)0x206, 324.0f);
            spF8 = *(Vec2f *)&sp1F8;
            uA = func_00106940((s16)yListValueAt(work->f2));
            uB = func_00106940(func_00106cd0(work->kind[work->sel], 1));
            d = func_00106940((s16)yListValueAt(work->f2)) - uB;
            if (d < 0) {
                spF0 = fclMakeVec2(12.0f + spF8.x, spF8.y - 18.0f);
                fclDrawEquipSprite(0x29, spF0, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (d > 0) {
                spE8 = fclMakeVec2(12.0f + spF8.x, spF8.y - 18.0f);
                fclDrawEquipSprite(0x28, spE8, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            spA0 = fclMakeVec2(spF8.x + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), spF8.y);
            c258 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(spA0, 22.0f, c258, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            sp1F0 = fclMakeVec2((f32)0x206, 374.0f);
            spE0 = *(Vec2f *)&sp1F0;
            uA = func_00106970((s16)yListValueAt(work->f2));
            uB = func_00106970(func_00106cd0(work->kind[work->sel], 1));
            d = func_00106970((s16)yListValueAt(work->f2)) - uB;
            if (d < 0) {
                spD8 = fclMakeVec2(12.0f + spE0.x, spE0.y - 18.0f);
                fclDrawEquipSprite(0x29, spD8, 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
            } else if (d > 0) {
                spD0 = fclMakeVec2(12.0f + spE0.x, spE0.y - 18.0f);
                fclDrawEquipSprite(0x28, spD0, 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
            }
            sp98 = fclMakeVec2(spE0.x + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), spE0.y);
            c254 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(sp98, 22.0f, c254, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 2:
            fclMesWindowDraw((s16)datItemBankOffset((s16)yListValueAt(work->f2)), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 2, 0x57, 109.0f, 324.0f, 70.0f);
            sp1E8 = fclMakeVec2(86.0f, 256.0f);
            fclDrawEquipSprite(0x1C, sp1E8, 69.0f, colA, 0xFF, 0, D_00794ED0);
            b = (Vec2f *)D_0063F660;
            fclObjSetAnchorPosition(work->fCB8, 0x57, 84.0f);
            ((u8 *)fclObjectGetWork(work->fCB8))[0x62] = 0x7F;
            sp1E0 = fclMakeVec2(b->x, b->y);
            t = (u8 *)fclObjectGetWork(work->fCB8);
            ((FclObject *)t)->anchorPosition = sp1E0;
            fclObjSetAnchorPosition(work->fEAC, 0x57, 84.0f);
            ((u8 *)fclObjectGetWork(work->fEAC))[0x62] = 0x7F;
            sp1D8 = fclMakeVec2(b->x, 50.0f + b->y);
            t = (u8 *)fclObjectGetWork(work->fEAC);
            ((FclObject *)t)->anchorPosition = sp1D8;
            break;
        }
        if ((u8)clndGetMoonPhase(yListValueAt(work->f2)) & 1) {
            sp1D0 = fclMakeVec2(37.0f, 243.0f);
            fclDrawResourceSprite(0x49, sp1D0, 65.0f, fclPackRgba(0, 0xFF, 0x66, 0), 0xFF, 0, D_00794EA0);
        }
        b = (Vec2f *)D_0063F9B0;
        fclObjSetAnchorPosition(work->fE60, 0x56, 94.0f);
        sp1C8 = fclMakeVec2(b->x, b->y);
        t = (u8 *)fclObjectGetWork(work->fE60);
        ((FclObject *)t)->anchorPosition = sp1C8;
        t = (u8 *)work->fE60;
        fclObjStartTween(t, fGpffff8530, fGpffff8530, 0, 0, 0);
        for (mark = 0; mark < 3; mark++) {
            fclObjSetAnchorPosition(*(void **)((u8 *)work + mark * 4 + 0xDBC), 0x41, 95.0f);
            c290 = fclMakeDrawColor(0xFF, 0xEF, 0x80, 0xFF);
            t = (u8 *)fclObjectGetWork(*(void **)((u8 *)work + mark * 4 + 0xDBC));
            ((FclObject *)t)->color = c290;
        }
        fclObjSetAnchorPosition(work->fCAC, 0x56, 91.0f);
        c28C = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fCAC);
        ((FclObject *)t)->color = c28C;
        fclObjSetAnchorPosition(work->fE84, 0x56, 91.0f);
        c288 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fE84);
        ((FclObject *)t)->color = c288;
        sp1C0 = fclMakeVec2(468.0f, 338.0f);
        t = (u8 *)fclObjectGetWork(work->fE84);
        ((FclObject *)t)->anchorPosition = sp1C0;
        if (yListCount() >= 2) {
            fclObjSetAnchorPosition(work->fC94, 0x41, 88.0f);
            c284 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fC94);
            ((FclObject *)t)->color = c284;
            b = (Vec2f *)D_0063F620;
            fclObjSetAnchorPosition(work->fC98, 0x41, 89.0f);
            c280 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fC98);
            ((FclObject *)t)->color = c280;
            work->fC = 91.0f / (f32)(yListCount() - 1);
            sp1B8 = fclMakeVec2(b->x - 1.0f, 264.0f + work->fC * (f32)work->f2);
            fclDrawEquipSprite(0x36, sp1B8, 87.0f, fclPackRgba(0xFF, 0xFF, 0x6D, 0x31), ((u8 *)fclObjectGetWork(work->fC98))[0x62], 0, D_00794EA0);
        }
        sp1B0 = fclMakeVec2((f32)0x219, 266.0f);
        fclDrawNumber(sp1B0, 70.0f, c2AC, 0x10, 5, datItemPrice((s16)yListValueAt(work->f2)), 9, 0x7B,
                      (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->fF28, 0xA9);
        if (datItemValue(func_00106cd0(work->kind[work->sel], work->f7)) == 0) {
            for (dash2 = 0; dash2 < 0xF; dash2++) {
                sp1A8 = fclMakeVec2((f32)(dash2 * 0x16 + 0x6F), 134.0f);
                fclDrawEquipSprite(0x3C, sp1A8, 86.0f, fclPackRgba(0xFF, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00794ED0);
            }
        } else {
            fclMesWindowDraw(datItemValue(func_00106cd0(work->kind[work->sel], work->f7)), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0xAA, 109.0f, 124.0f, 70.0f);
        }
        switch (work->f7) {
        case 0:
            white = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
            sp1A0 = fclMakeVec2(129.0f, 89.0f);
            spC8 = *(Vec2f *)&sp1A0;
            frFontExDrawTextDeferredWithCharWidth(spC8.x, spC8.y, 70.0f, white, 0, 1, ((void *)datGetItemNameId((s32)func_00106cd0(work->kind[work->sel], 0))), 0, 0, D_00794ED0, -1);
            sp198 = fclMakeVec2(86.0f, 90.0f);
            fclDrawEquipSprite(work->icon[work->sel], sp198, 69.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0, D_00794ED0);
            fclMesWindowDraw((s16)datItemBankOffset(func_00106cd0(work->kind[work->sel], 0)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 1, 0, 0, 0x57, 109.0f, 158.0f, 70.0f);
            b = (Vec2f *)D_0063F630;
            fclObjSetAnchorPosition(work->fE98, 0x57, 83.0f);
            c27C = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fE98);
            ((FclObject *)t)->color = c27C;
            sp190 = fclMakeVec2(b->x, b->y - 166.0f);
            t = (u8 *)fclObjectGetWork(work->fE98);
            ((FclObject *)t)->anchorPosition = sp190;
            b = (Vec2f *)D_0063F640;
            fclObjSetAnchorPosition(work->fEA0, 0x57, 82.0f);
            c278 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fEA0);
            ((FclObject *)t)->color = c278;
            sp188 = fclMakeVec2(b->x, b->y - 166.0f);
            t = (u8 *)fclObjectGetWork(work->fEA0);
            ((FclObject *)t)->anchorPosition = sp188;
            uA = func_001068b0((s32)func_00106cd0(work->kind[work->sel], 0));
            sp90 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), 158.0f);
            c250 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(sp90, 22.0f, c250, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            uA = func_001068e0((s32)func_00106cd0(work->kind[work->sel], 0));
            sp88 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), 208.0f);
            c24C = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(sp88, 22.0f, c24C, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 1:
            white = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
            sp180 = fclMakeVec2(129.0f, 89.0f);
            spC0 = *(Vec2f *)&sp180;
            frFontExDrawTextDeferredWithCharWidth(spC0.x, spC0.y, 70.0f, white, 0, 1, ((void *)datGetItemNameId((s32)func_00106cd0(work->kind[work->sel], 1))), 0, 0, D_00794ED0, -1);
            sp178 = fclMakeVec2(86.0f, 90.0f);
            fclDrawEquipSprite(0x1B, sp178, 69.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0, D_00794ED0);
            fclMesWindowDraw((s16)datItemBankOffset(func_00106cd0(work->kind[work->sel], 1)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 1, 0, 1, 0x57, 109.0f, 158.0f, 70.0f);
            b = (Vec2f *)D_0063F628;
            fclObjSetAnchorPosition(work->fE94, 0x57, 81.0f);
            c274 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fE94);
            ((FclObject *)t)->color = c274;
            sp170 = fclMakeVec2(b->x, b->y - 166.0f);
            t = (u8 *)fclObjectGetWork(work->fE94);
            ((FclObject *)t)->anchorPosition = sp170;
            b = (Vec2f *)D_0063F638;
            fclObjSetAnchorPosition(work->fE9C, 0x57, 80.0f);
            c270 = fclMakeDrawColor(0xE7, 0xE5, 0xE6, 0xFF);
            t = (u8 *)fclObjectGetWork(work->fE9C);
            ((FclObject *)t)->color = c270;
            sp168 = fclMakeVec2(b->x, b->y - 166.0f);
            t = (u8 *)fclObjectGetWork(work->fE9C);
            ((FclObject *)t)->anchorPosition = sp168;
            uA = func_00106940((s32)func_00106cd0(work->kind[work->sel], 1));
            sp80 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), 158.0f);
            c248 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(sp80, 22.0f, c248, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            uA = func_00106970((s32)func_00106cd0(work->kind[work->sel], 1));
            sp78 = fclMakeVec2(518.0f + (f32)((s16)(fclDecimalDigitCount(uA) - 1) * 8), 208.0f);
            c244 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            fclDrawNumber(sp78, 22.0f, c244, 0xF, 0, uA, 0x1E, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), (s32)resourceFindByName((char *)(D_0063FB50)), 0xA9);
            break;
        case 2:
            white = fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF);
            sp160 = fclMakeVec2(129.0f, 89.0f);
            spB8 = *(Vec2f *)&sp160;
            frFontExDrawTextDeferredWithCharWidth(spB8.x, spB8.y, 70.0f, white, 0, 1, ((void *)datGetItemNameId((s32)func_00106cd0(work->kind[work->sel], 2))), 0, 0, D_00794ED0, -1);
            sp158 = fclMakeVec2(86.0f, 90.0f);
            fclDrawEquipSprite(0x1C, sp158, 69.0f, fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 0xFF, 0, D_00794ED0);
            fclMesWindowDraw((s16)datItemBankOffset(func_00106cd0(work->kind[work->sel], 2)), fclPackRgba(0xFF, 0xFF, 0xFF, 0xFF), 1, 0, 2, 0x57, 109.0f, 158.0f, 70.0f);
            b = (Vec2f *)D_0063F668;
            fclObjSetAnchorPosition(work->fCBC, 0x57, 85.0f);
            fclObjSetAnchorPosition(work->fEB0, 0x57, 85.0f);
            sp150 = fclMakeVec2(b->x, 50.0f + b->y);
            t = (u8 *)fclObjectGetWork(work->fEB0);
            ((FclObject *)t)->anchorPosition = sp150;
            break;
        }
        for (slot = 0; slot < 3; slot++) {
            b = (Vec2f *)(D_0063F560 + (slot + 0x61) * 8);
            fclObjSetAnchorPosition(*(void **)((u8 *)work + slot * 4 + 0xE88), 0x41, 95.0f);
            c26C = fclMakeDrawColor(0xE7, 0xE5, 0xE7, 0xFF);
            t = (u8 *)fclObjectGetWork(*(void **)((u8 *)work + slot * 4 + 0xE88));
            ((FclObject *)t)->color = c26C;
            sp148 = fclMakeVec2(b->x, b->y - 166.0f);
            t = (u8 *)fclObjectGetWork(*(void **)((u8 *)work + slot * 4 + 0xE88));
            ((FclObject *)t)->anchorPosition = sp148;
        }
        b = (Vec2f *)D_0063F648;
        fclObjSetAnchorPosition(work->fEA4, 0x56, 91.0f);
        c268 = fclMakeDrawColor(0xB0, 0xAE, 0xAF, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fEA4);
        ((FclObject *)t)->color = c268;
        sp140 = fclMakeVec2(b->x, b->y - 166.0f);
        t = (u8 *)fclObjectGetWork(work->fEA4);
        ((FclObject *)t)->anchorPosition = sp140;
        fclObjSetAnchorPosition(work->fEA8, 0x56, 91.0f);
        c264 = fclMakeDrawColor(0xB0, 0xAE, 0xAF, 0xFF);
        t = (u8 *)fclObjectGetWork(work->fEA8);
        ((FclObject *)t)->color = c264;
        sp138 = fclMakeVec2(468.0f, 172.0f);
        t = (u8 *)fclObjectGetWork(work->fEA8);
        ((FclObject *)t)->anchorPosition = sp138;
        return 1;
    }
    fclObjChangeFlagBit(work->fC9C, 0, 1);
    fclObjChangeFlagBit(work->fCA0, 0, 1);
    fclObjChangeFlagBit(work->fCA4, 0, 1);
    fclObjChangeFlagBit(work->fCA8, 0, 1);
    fclObjChangeFlagBit(work->fCB8, 0, 1);
    fclObjChangeFlagBit(work->fEAC, 0, 1);
    for (k = 0; k < 3; k++) {
        fclObjChangeFlagBit(*(void **)((u8 *)work + k * 4 + 0xDBC), 0, 1);
        fclObjChangeFlagBit(*(void **)((u8 *)work + k * 4 + 0xE88), 0, 1);
    }
    fclObjChangeFlagBit(work->fCAC, 0, 1);
    fclObjChangeFlagBit(work->fE84, 0, 1);
    fclObjChangeFlagBit(work->fC94, 0, 1);
    fclObjChangeFlagBit(work->fC98, 0, 1);
    fclObjChangeFlagBit(work->fE94, 0, 1);
    fclObjChangeFlagBit(work->fE98, 0, 1);
    fclObjChangeFlagBit(work->fE9C, 0, 1);
    fclObjChangeFlagBit(work->fEA0, 0, 1);
    fclObjChangeFlagBit(work->fCBC, 0, 1);
    fclObjChangeFlagBit(work->fEB0, 0, 1);
    fclObjChangeFlagBit(work->fEA4, 0, 1);
    fclObjChangeFlagBit(work->fEA8, 0, 1);
    fclObjChangeFlagBit(work->fE60, 0, 1);
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
// FUN_002D3EE0
void fclShopSlideInFromRight(void *arg0) {
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    Vec2f sp50;
    Vec2f sp48;
    Vec2f sp40;
    Vec2f sp38;
    ShopWork *work;
    u8 *t;
    Vec2f *b;
    s16 i;
    s8 v7;
    work = *(ShopWork **)((u8 *)arg0 + 0x38);
    b = (Vec2f *)D_0063F5B0;
    fclObjSetAnchorPosition(work->field_C60, 0x41, 109.0f);
    spC8 = fclMakeVec2(b->x, b->y);
    spC0 = fclMakeVec2(b->x - 740.0f, b->y);
    fclObjStartPosition(work->field_C60, spC8, spC0, 0, 4, 0);
    b = (Vec2f *)D_0063F5F0;
    fclObjSetAnchorPosition(work->field_C80, 0x41, 109.0f);
    spB8 = fclMakeVec2(b->x, b->y);
    spB0 = fclMakeVec2(b->x - 740.0f, b->y);
    fclObjStartPosition(work->field_C80, spB8, spB0, 0, 4, 0);
    b = (Vec2f *)D_0063F5D0;
    fclObjSetAnchorPosition(work->field_C70, 0x41, 111.0f);
    spA8 = fclMakeVec2(b->x, b->y);
    spA0 = fclMakeVec2(b->x - 740.0f, b->y);
    fclObjStartPosition(work->field_C70, spA8, spA0, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(*(void **)((u8 *)work + 0xE88 + i * 4), 0, 1);
    }
    fclObjChangeFlagBit(work->field_EA4, 0, 1);
    fclObjChangeFlagBit(work->field_EA8, 0, 1);
    v7 = *(s8 *)((u8 *)work + 7);
    switch (v7) {
    case 0:
        fclObjChangeFlagBit(work->field_CA0, 0, 1);
        fclObjChangeFlagBit(work->field_CA8, 0, 1);
        fclObjChangeFlagBit(work->field_E98, 0, 1);
        fclObjChangeFlagBit(work->field_EA0, 0, 1);
        break;
    case 1:
        fclObjChangeFlagBit(work->field_C9C, 0, 1);
        fclObjChangeFlagBit(work->field_CA4, 0, 1);
        fclObjChangeFlagBit(work->field_E94, 0, 1);
        fclObjChangeFlagBit(work->field_E9C, 0, 1);
        break;
    case 2:
        fclObjChangeFlagBit(work->field_CB8, 0, 1);
        fclObjChangeFlagBit(work->field_EAC, 0, 1);
        fclObjChangeFlagBit(work->field_CBC, 0, 1);
        fclObjChangeFlagBit(work->field_EB0, 0, 1);
        break;
    }
        fclObjSetAnchorPosition(work->field_E80, 0x41, 109.0f);
    sp98 = fclMakeVec2(86.0f, 242.0f);
    sp90 = fclMakeVec2(826.0f, 242.0f);
    fclObjStartPosition(work->field_E80, sp98, sp90, 0, 4, 0);
    b = (Vec2f *)D_0063F5F8;
    fclObjSetAnchorPosition(work->field_C84, 0x41, 112.0f);
    sp88 = fclMakeVec2(b->x, b->y);
    sp80 = fclMakeVec2(740.0f + b->x, b->y);
    fclObjStartPosition(work->field_C84, sp88, sp80, 0, 4, 0);
    b = (Vec2f *)D_0063F5D8;
    fclObjSetAnchorPosition(work->field_C74, 0x41, 113.0f);
    sp78 = fclMakeVec2(b->x, b->y);
    sp70 = fclMakeVec2(740.0f + b->x, b->y);
    fclObjStartPosition(work->field_C74, sp78, sp70, 0, 4, 0);
    b = (Vec2f *)D_0063F5E0;
    fclObjSetAnchorPosition(work->field_C78, 0x41, 114.0f);
    sp68 = fclMakeVec2(b->x, b->y);
    sp60 = fclMakeVec2(740.0f + b->x, b->y);
    fclObjStartPosition(work->field_C78, sp68, sp60, 0, 4, 0);
    for (i = 0; i < 3; i++) {
        fclObjChangeFlagBit(*(void **)((u8 *)work + 0xDBC + i * 4), 0, 1);
    }
    fclObjChangeFlagBit(work->field_CAC, 0, 1);
    fclObjChangeFlagBit(work->field_E84, 0, 1);
    fclObjChangeFlagBit(work->field_C94, 0, 1);
    fclObjChangeFlagBit(work->field_C98, 0, 1);
    fclObjChangeFlagBit(work->field_E60, 0, 1);
    fclObjChangeFlagBit(work->field_DE0, 0, 1);
    fclObjStartTween(work->field_D6C, -110.0f, -14.0f, 0, 4, 0);
    fclObjStartUniformRevealScale(work->field_D70, 1.0f, 1.0f, 0, 0, 0);
    fclObjStartAlpha(work->field_D70, 0, 0xFF, 0, 8, 6);
    sp58 = fclMakeVec2(46.0f, 294.0f);
    t = (u8 *)fclObjectGetWork(work->field_D70);
    ((FclObject *)t)->anchorPosition = *(Vec2f *)&sp58;
    fclObjStartAlpha(work->field_D7C, 0, 0xFF, 0, 8, 6);
    t = (u8 *)fclObjectGetWork(work->field_C8C);
    fclObjStartAlpha(work->field_C8C, t[0x62], 0xFF, 0, 8, 0);
    t = (u8 *)fclObjectGetWork(work->field_C90);
    fclObjStartAlpha(work->field_C90, t[0x62], 0xFF, 0, 8, 0);
    b = (Vec2f *)D_0063F880;
    sp50 = fclMakeVec2(700.0f + b->x, b->y + (f32)(work->field_4 << 5));
    sp48 = fclMakeVec2(b->x, b->y + (f32)(work->field_4 << 5));
    fclObjStartPosition(work->field_DC8, sp50, sp48, 1, 3, 3);
    t = (u8 *)fclObjectGetWork(work->field_C8C);
    fclObjStartAlpha(work->field_DC8, t[0x62], 0xFF, 0, 8, 0);
    b = (Vec2f *)D_0063F890;
    sp40 = fclMakeVec2(700.0f + b->x, b->y + (f32)(work->field_4 << 5));
    sp38 = fclMakeVec2(b->x, b->y + (f32)(work->field_4 << 5));
    fclObjStartPosition(work->field_DD0, sp40, sp38, 1, 3, 3);
    t = (u8 *)fclObjectGetWork(work->field_C8C);
    fclObjStartAlpha(work->field_DD0, t[0x62], 0xFF, 0, 8, 0);
    fclObjStartAlpha(work->field_C64, 0, 0xCC, 0, 8, 0);
    fclObjChangeFlagBit(work->field_DE4, 0, 0);
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
/* The sprite record behind a draw handle: only the fields the shop tabs set. */
typedef struct {
    u8 pad0[0x8];
    f32 y;              /* 0x08 */
    u8 pad0C[0x6D];
    u8 r;               /* 0x79 */
    u8 g;               /* 0x7A */
    u8 b;               /* 0x7B */
    u8 pad7C[0x80];
    u32 priority;       /* 0xFC */
} ShopSprite;
#define SHOP_SPRITE(handle) ((ShopSprite *)fclObjectGetWork(handle))

/* measured: MATCH (1,996 code bytes in the 2,000-byte window).  Sets the
   three shop tabs' priority, y and colour; the selected tab is highlighted
   and tabs whose stock is exhausted are greyed out. */
// FUN_002D4760
s8 fclShopUpdateTabs(void *arg0, s8 arg1) {
    u8 colorA[3][4];
    u8 colorB[3][4];
    s16 primary[3];
    s16 secondary[3];
    s16 y[3][2];
    s16 thirdY[3];
    s16 i;
    s16 j;
    s32 sel;
    ShopWork *work;
    u8 *ca;
    u8 *cb;
    s16 *row;
    u8 r;
    u8 g;
    u8 b;

    work = *(ShopWork **)((u8 *)arg0 + 0x38);
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
    for (i = 0, sel = arg1; i < 3; i++) {
        if (yListCountFor(*(void **)((u8 *)work + 0xF18 + i * 4)) <= D_00748908[i]) {
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
            if (yListCountFor(*(void **)((u8 *)work + 0xF18 + i * 4)) <= D_00748908[i]) {
                SHOP_SET_GRAY(colorA[i], 0x9C);
                SHOP_SET_GRAY(colorB[i], 0xFF);
            }
        }
    }
    /* Colour bytes of the first sprite are kept in r/g/b for the second. */
    for (j = 0; j < 3; j++) {
        switch (j) {
        case 0:
            SHOP_SPRITE(work->field_EC4)->priority = primary[j];
            row = y[j];
            SHOP_SPRITE(work->field_EC4)->y = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->field_EC4)->r = r;
            g = ca[1];
            SHOP_SPRITE(work->field_EC4)->g = g;
            b = ca[2];
            SHOP_SPRITE(work->field_EC4)->b = b;
            SHOP_SPRITE(work->field_EC8)->priority = primary[j];
            SHOP_SPRITE(work->field_EC8)->y = row[1];
            SHOP_SPRITE(work->field_EC8)->r = r;
            SHOP_SPRITE(work->field_EC8)->g = g;
            SHOP_SPRITE(work->field_EC8)->b = b;
            SHOP_SPRITE(work->field_E38)->priority = secondary[j];
            SHOP_SPRITE(work->field_E38)->y = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->field_E38)->r = cb[0];
            SHOP_SPRITE(work->field_E38)->g = cb[1];
            SHOP_SPRITE(work->field_E38)->b = cb[2];
            break;
        case 1:
            SHOP_SPRITE(work->field_EB4)->priority = primary[j];
            row = y[j];
            SHOP_SPRITE(work->field_EB4)->y = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->field_EB4)->r = r;
            g = ca[1];
            SHOP_SPRITE(work->field_EB4)->g = g;
            b = ca[2];
            SHOP_SPRITE(work->field_EB4)->b = b;
            SHOP_SPRITE(work->field_EB8)->priority = primary[j];
            SHOP_SPRITE(work->field_EB8)->y = row[1];
            SHOP_SPRITE(work->field_EB8)->r = r;
            SHOP_SPRITE(work->field_EB8)->g = g;
            SHOP_SPRITE(work->field_EB8)->b = b;
            SHOP_SPRITE(work->field_CC4)->priority = secondary[j];
            SHOP_SPRITE(work->field_CC4)->y = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->field_CC4)->r = cb[0];
            SHOP_SPRITE(work->field_CC4)->g = cb[1];
            SHOP_SPRITE(work->field_CC4)->b = cb[2];
            break;
        case 2:
            SHOP_SPRITE(work->field_EBC)->priority = primary[j];
            row = y[j];
            SHOP_SPRITE(work->field_EBC)->y = row[0];
            ca = colorA[j];
            r = ca[0];
            SHOP_SPRITE(work->field_EBC)->r = r;
            g = ca[1];
            SHOP_SPRITE(work->field_EBC)->g = g;
            b = ca[2];
            SHOP_SPRITE(work->field_EBC)->b = b;
            SHOP_SPRITE(work->field_EC0)->priority = primary[j];
            SHOP_SPRITE(work->field_EC0)->y = row[1];
            SHOP_SPRITE(work->field_EC0)->r = r;
            SHOP_SPRITE(work->field_EC0)->g = g;
            SHOP_SPRITE(work->field_EC0)->b = b;
            SHOP_SPRITE(work->field_CC0)->priority = secondary[j];
            SHOP_SPRITE(work->field_CC0)->y = thirdY[j];
            cb = colorB[j];
            SHOP_SPRITE(work->field_CC0)->r = cb[0];
            SHOP_SPRITE(work->field_CC0)->g = cb[1];
            SHOP_SPRITE(work->field_CC0)->b = cb[2];
            break;
        }
    }
    return arg1;
}

// FUN_002D4F30
s32 fclShopStatusFlagToCode(s16 arg0) {
    if (arg0 & 0x81) return 0x14;
    if (arg0 & 0x102) return 0x15;
    if (arg0 & 0x204) return 0x16;
    if (arg0 & 0x408) return 0x17;
    if (arg0 & 0x810) return 0x18;
    if (arg0 & 0x1020) return 0x19;
    if (arg0 & 0x2040) return 0x1A;
    if (arg0 & 0x4000) return 0x1B;
    if (arg0 & 0x8000) return 0x1C;
    if (arg0 & 0x40000) return 0x1D;
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
// FUN_002D5040
void fclShopDrawStats(void *arg0) {
    s16 dB;
    s16 dA;
    u8 *work;
    u32 value;
    f32 x;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    fclDrawEquipSprite(fclShopStatusFlagToCode((s16)datEntryGetFlags((s32)yListValueAt(*(s16 *)(work + 2)))) & 0xFFFF, fclMakeVec2(37.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C), 35.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x30)), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
    shopDrawLabel(31.0f, (const char *)((void *)datGetItemNameId((s32)yListValueAt(*(s16 *)(work + 2)))), fclMakeVec2(79.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C), 34.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x30)), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    shopDrawLabel(31.0f, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), *(s8 *)(work + 7)))), fclMakeVec2(79.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C), 34.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x30)), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    switch (*(s8 *)(work + 7)) {
    case 0:
        x = 51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C));
        value = func_001068b0((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        x = 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C)));
        value = func_001068e0((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        fclDrawEquipSprite(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), fclMakeVec2(37.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x30)), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        x = 51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C));
        value = func_001068b0((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        x = 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C)));
        value = func_001068e0((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        dB = shopStatDelta((func_001068b0((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF), func_001068b0(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF);
        dA = shopStatDelta((func_001068e0((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF), func_001068e0(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0)) & 0xFFFF);
        break;
    case 1:
        x = 51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C));
        value = func_00106940((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        x = 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C)));
        value = func_00106970((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF;
        shopDrawStat(value, x, (f32)0x107);
        fclDrawEquipSprite(0x1B, fclMakeVec2(37.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x30)), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        x = 51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C));
        value = func_00106940((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        x = 87.0f + (51.0f + (296.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C)));
        value = func_00106970((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF;
        shopDrawStat(value, x, 149.0f);
        dB = shopStatDelta((func_00106940((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF), func_00106940(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF);
        dA = shopStatDelta((func_00106970((s32)yListValueAt(*(s16 *)(work + 2))) & 0xFFFF), func_00106970(func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1)) & 0xFFFF);
        break;
    case 2:
        fclDrawEquipSprite(0x1C, fclMakeVec2(37.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x2C), 35.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEDC)) + 0x30)), 31.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        dB = dA = 0;
        break;
    }
    if (dB > 0) {
        fclDrawEquipSprite(0x28, fclMakeVec2(360.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C), 245.0f), 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dB < 0) {
        fclDrawEquipSprite(0x29, fclMakeVec2(360.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C), 245.0f), 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
    }
    if (dA > 0) {
        fclDrawEquipSprite(0x28, fclMakeVec2(87.0f + (360.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C)), 245.0f), 23.0f, fclPackRgba(0, 0xFA, 0x22, 0x3A), 0xFF, 0, D_00795E60);
    } else if (dA < 0) {
        fclDrawEquipSprite(0x29, fclMakeVec2(87.0f + (360.0f + *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCE4)) + 0x2C)), 245.0f), 23.0f, fclPackRgba(0, 0x67, 0x67, 0x67), 0xFF, 0, D_00795E60);
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
// FUN_002D6190
void fclShopStartHeaderBars(void *arg0) {
    FclDrawColor sp1FC;
    FclDrawColor sp1F8;
    FclDrawColor sp1F4;
    FclDrawColor sp1F0;
    FclDrawColor sp1EC;
    FclDrawColor sp1E8;
    FclDrawColor sp1E4;
    FclDrawColor sp1E0;
    FclDrawColor sp1DC;
    FclDrawColor sp1D8;
    FclDrawColor sp1D4;
    FclDrawColor sp1D0;
    FclDrawColor sp1CC;
    FclDrawColor sp1C8;
    FclDrawColor sp1C4;
    FclDrawColor sp1C0;
    FclDrawColor sp1BC;
    FclDrawColor sp1B8;
    FclDrawColor sp1B4;
    Vec2f sp1A8;
    Vec2f sp1A0;
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    Vec2f sp50;
    Vec2f sp48;
    Vec2f sp40;
    Vec2f sp38;
    Vec2f sp30;
    u8 *work;
    u8 *t;
    Vec2f *base;
    s8 temp_4;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xCE4), 0x56, 35.0f);
    sp1FC = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCE4)));
    ((FclObject *)t)->color = sp1FC;
    sp1A8 = fclMakeVec2((f32) -0x212, 208.0f);
    sp1A0 = fclMakeVec2(70.0f, 208.0f);
    fclObjStartPosition(*(void **)(work + 0xCE4), sp1A8, sp1A0, 0, 8, 0);
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xCE8), 0x56, 35.0f);
    sp1F8 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCE8)));
    ((FclObject *)t)->color = sp1F8;
    sp198 = fclMakeVec2(-37.0f, 208.0f);
    sp190 = fclMakeVec2((f32) 0x233, 208.0f);
    fclObjStartPosition(*(void **)(work + 0xCE8), sp198, sp190, 0, 8, 0);
    base = (Vec2f *)D_0063F658;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xCB4), 0x57, 33.0f);
    sp1F4 = fclMakeDrawColor(0xF7, 0x94, 0x1D, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCB4)));
    ((FclObject *)t)->color = sp1F4;
    sp188 = fclMakeVec2(base->x - 600.0f, base->y);
    sp180 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xCB4), sp188, sp180, 0, 8, 0);
    if (*(s8 *)(work + 7) != 2) {
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xCAC), 0x57, 30.0f);
        sp1F0 = fclMakeDrawColor(0xFF, 0xEF, 0x81, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCAC)));
        ((FclObject *)t)->color = sp1F0;
        sp178 = fclMakeVec2(-232.0f, 227.0f);
        sp170 = fclMakeVec2(368.0f, 227.0f);
        fclObjStartPosition(*(void **)(work + 0xCAC), sp178, sp170, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xE84), 0x57, 30.0f);
        sp1EC = fclMakeDrawColor(0xFF, 0xEF, 0x81, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xE84)));
        ((FclObject *)t)->color = sp1EC;
        sp168 = fclMakeVec2(468.0f, 338.0f);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xE84)));
        ((FclObject *)t)->anchorPosition = *(Vec2f *)&sp168;
        sp160 = fclMakeVec2(-145.0f, 227.0f);
        sp158 = fclMakeVec2((f32) 0x1C7, 227.0f);
        fclObjStartPosition(*(void **)(work + 0xE84), sp160, sp158, 0, 8, 0);
    }
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEDC), 0x56, 35.0f);
    sp1E8 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xEDC)));
    ((FclObject *)t)->color = sp1E8;
    sp150 = fclMakeVec2((f32) 0x29E, 94.0f);
    sp148 = fclMakeVec2(70.0f, 94.0f);
    fclObjStartPosition(*(void **)(work + 0xEDC), sp150, sp148, 0, 8, 0);
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xEE0), 0x56, 35.0f);
    sp1E4 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xEE0)));
    ((FclObject *)t)->color = sp1E4;
    sp140 = fclMakeVec2((f32) 0x48B, 94.0f);
    sp138 = fclMakeVec2((f32) 0x233, 94.0f);
    fclObjStartPosition(*(void **)(work + 0xEE0), sp140, sp138, 0, 8, 0);
    base = (Vec2f *)D_0063F650;
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xCB0), 0x57, 34.0f);
    sp1E0 = fclMakeDrawColor(0xB0, 0xAF, 0xAF, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCB0)));
    ((FclObject *)t)->color = sp1E0;
    sp130 = fclMakeVec2(600.0f + base->x, base->y);
    sp128 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xCB0), sp130, sp128, 0, 8, 0);
    fclObjSetAnchorAlphaFull(*(void **)(work + 0xCD0), 0x57, 32.0f);
    sp1DC = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
    t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCD0)));
    ((FclObject *)t)->color = sp1DC;
    sp120 = fclMakeVec2((f32) 0x395, 178.0f);
    sp118 = fclMakeVec2((f32) 0x13D, 178.0f);
    fclObjStartPosition(*(void **)(work + 0xCD0), sp120, sp118, 0, 8, 0);
    if (*(s8 *)(work + 7) != 2) {
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xEA4), 0x57, 30.0f);
        sp1D8 = fclMakeDrawColor(0xB0, 0xAF, 0xAF, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xEA4)));
        ((FclObject *)t)->color = sp1D8;
        sp110 = fclMakeVec2(968.0f, 113.0f);
        sp108 = fclMakeVec2(368.0f, 113.0f);
        fclObjStartPosition(*(void **)(work + 0xEA4), sp110, sp108, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xEA8), 0x57, 30.0f);
        sp1D4 = fclMakeDrawColor(0xB0, 0xAF, 0xAF, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xEA8)));
        ((FclObject *)t)->color = sp1D4;
        sp100 = fclMakeVec2(468.0f, 338.0f);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xEA8)));
        ((FclObject *)t)->anchorPosition = *(Vec2f *)&sp100;
        spF8 = fclMakeVec2((f32) 0x41F, 113.0f);
        spF0 = fclMakeVec2((f32) 0x1C7, 113.0f);
        fclObjStartPosition(*(void **)(work + 0xEA8), spF8, spF0, 0, 8, 0);
    }
    temp_4 = (s8)(*(s8 *)(work + 7));
    switch (temp_4) {                               /* irregular */
    case 0:
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xCA0), 0x58, 27.0f);
        sp1D0 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCA0)));
        ((FclObject *)t)->color = sp1D0;
        spE8 = fclMakeVec2(-230.0f, 234.0f);
        spE0 = fclMakeVec2(370.0f, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xCA0), spE8, spE0, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xCA8), 0x58, 26.0f);
        sp1CC = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCA8)));
        ((FclObject *)t)->color = sp1CC;
        spD8 = fclMakeVec2(-143.0f, 234.0f);
        spD0 = fclMakeVec2((f32) 0x1C9, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xCA8), spD8, spD0, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xE98), 0x58, 27.0f);
        sp1C8 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xE98)));
        ((FclObject *)t)->color = sp1C8;
        spC8 = fclMakeVec2((f32) 0x3CA, 121.0f);
        spC0 = fclMakeVec2(370.0f, 121.0f);
        fclObjStartPosition(*(void **)(work + 0xE98), spC8, spC0, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xEA0), 0x58, 26.0f);
        sp1C4 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xEA0)));
        ((FclObject *)t)->color = sp1C4;
        spB8 = fclMakeVec2((f32) 0x421, 121.0f);
        spB0 = fclMakeVec2((f32) 0x1C9, 121.0f);
        fclObjStartPosition(*(void **)(work + 0xEA0), spB8, spB0, 0, 8, 0);
        return;
    case 1:
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xC9C), 0x58, 25.0f);
        sp1C0 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xC9C)));
        ((FclObject *)t)->color = sp1C0;
        spA8 = fclMakeVec2(-230.0f, 234.0f);
        spA0 = fclMakeVec2(370.0f, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xC9C), spA8, spA0, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xCA4), 0x58, 24.0f);
        sp1BC = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xCA4)));
        ((FclObject *)t)->color = sp1BC;
        sp98 = fclMakeVec2(-143.0f, 234.0f);
        sp90 = fclMakeVec2((f32) 0x1C9, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xCA4), sp98, sp90, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xE94), 0x58, 25.0f);
        sp1B8 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xE94)));
        ((FclObject *)t)->color = sp1B8;
        sp88 = fclMakeVec2((f32) 0x3CA, 121.0f);
        sp80 = fclMakeVec2(370.0f, 121.0f);
        fclObjStartPosition(*(void **)(work + 0xE94), sp88, sp80, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xE9C), 0x58, 24.0f);
        sp1B4 = fclMakeDrawColor(0xE7, 0xE6, 0xE6, 0xFFU);
        t = (u8 *)(fclObjectGetWork(*(void **)(work + 0xE9C)));
        ((FclObject *)t)->color = sp1B4;
        sp78 = fclMakeVec2((f32) 0x421, 122.0f);
        sp70 = fclMakeVec2((f32) 0x1C9, 120.0f);
        fclObjStartPosition(*(void **)(work + 0xE9C), sp78, sp70, 0, 8, 0);
        return;
    case 2:
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xCB8), 0x58, 28.0f);
        ((u8 *)fclObjectGetWork(*(void **)(work + 0xCB8)))[0x62] = 0x7F;
        sp68 = fclMakeVec2(-233.0f, 225.0f);
        sp60 = fclMakeVec2((f32) 0x16F, 225.0f);
        fclObjStartPosition(*(void **)(work + 0xCB8), sp68, sp60, 0, 8, 0);
        fclObjSetAnchorPosition(*(void **)(work + 0xEAC), 0x58, 28.0f);
        ((u8 *)fclObjectGetWork(*(void **)(work + 0xEAC)))[0x62] = 0x7F;
        sp58 = fclMakeVec2(-146.0f, 225.0f);
        sp50 = fclMakeVec2(454.0f, 225.0f);
        fclObjStartPosition(*(void **)(work + 0xEAC), sp58, sp50, 0, 8, 0);
        fclObjSetAnchorAlphaFull(*(void **)(work + 0xCBC), 0x58, 29.0f);
        ((u8 *)fclObjectGetWork(*(void **)(work + 0xCBC)))[0x62] = 0xFF;
        sp48 = fclMakeVec2((f32) 0x3C7, 111.0f);
        sp40 = fclMakeVec2((f32) 0x16F, 111.0f);
        fclObjStartPosition(*(void **)(work + 0xCBC), sp48, sp40, 0, 8, 0);
        fclObjSetAnchorPosition(*(void **)(work + 0xEB0), 0x58, 29.0f);
        ((u8 *)fclObjectGetWork(*(void **)(work + 0xEB0)))[0x62] = 0xFF;
        sp38 = fclMakeVec2((f32) 0x41E, 111.0f);
        sp30 = fclMakeVec2(454.0f, 111.0f);
        fclObjStartPosition(*(void **)(work + 0xEB0), sp38, sp30, 0, 8, 0);
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
// FUN_002D7300
void fclShopStartRowPositions(void *arg0) {
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    Vec2f sp50;
    Vec2f sp48;
    Vec2f sp40;
    Vec2f sp38;
    Vec2f sp30;
    u8 *work;
    Vec2f *base;
    s8 temp_4;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    sp198 = fclMakeVec2(70.0f, 208.0f);
    sp190 = fclMakeVec2((f32)0x29E, 208.0f);
    fclObjStartPosition(*(void **)(work + 0xCE4), sp198, sp190, 0, 8, 0);
    sp188 = fclMakeVec2((f32)0x233, 208.0f);
    sp180 = fclMakeVec2((f32)0x48B, 208.0f);
    fclObjStartPosition(*(void **)(work + 0xCE8), sp188, sp180, 0, 8, 0);
    base = (Vec2f *)D_0063F658;
    sp178 = fclMakeVec2(base->x, base->y);
    sp170 = fclMakeVec2(600.0f + base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xCB4), sp178, sp170, 0, 8, 0);
    sp168 = fclMakeVec2(368.0f, 227.0f);
    sp160 = fclMakeVec2(968.0f, 227.0f);
    fclObjStartPosition(*(void **)(work + 0xCAC), sp168, sp160, 0, 8, 0);
    sp158 = fclMakeVec2((f32)0x1C7, 227.0f);
    sp150 = fclMakeVec2((f32)0x41F, 227.0f);
    fclObjStartPosition(*(void **)(work + 0xE84), sp158, sp150, 0, 8, 0);
    sp148 = fclMakeVec2(70.0f, 94.0f);
    sp140 = fclMakeVec2((f32)-0x212, 94.0f);
    fclObjStartPosition(*(void **)(work + 0xEDC), sp148, sp140, 0, 8, 0);
    sp138 = fclMakeVec2((f32)0x233, 94.0f);
    sp130 = fclMakeVec2(-37.0f, 94.0f);
    fclObjStartPosition(*(void **)(work + 0xEE0), sp138, sp130, 0, 8, 0);
    base = (Vec2f *)D_0063F650;
    sp128 = fclMakeVec2(base->x, base->y);
    sp120 = fclMakeVec2(base->x - 600.0f, base->y);
    fclObjStartPosition(*(void **)(work + 0xCB0), sp128, sp120, 0, 8, 0);
    sp118 = fclMakeVec2((f32)0x13D, 178.0f);
    sp110 = fclMakeVec2((f32)-0x11B, 178.0f);
    fclObjStartPosition(*(void **)(work + 0xCD0), sp118, sp110, 0, 8, 0);
    sp108 = fclMakeVec2(368.0f, 113.0f);
    sp100 = fclMakeVec2(-232.0f, 113.0f);
    fclObjStartPosition(*(void **)(work + 0xEA4), sp108, sp100, 0, 8, 0);
    spF8 = fclMakeVec2((f32)0x1C7, 113.0f);
    spF0 = fclMakeVec2(-145.0f, 113.0f);
    fclObjStartPosition(*(void **)(work + 0xEA8), spF8, spF0, 0, 8, 0);
    temp_4 = *(s8 *)(work + 7);
    switch (temp_4) {
    case 0:
        spE8 = fclMakeVec2(370.0f, 234.0f);
        spE0 = fclMakeVec2((f32)0x3CA, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xCA0), spE8, spE0, 0, 8, 0);
        spD8 = fclMakeVec2((f32)0x1C9, 234.0f);
        spD0 = fclMakeVec2((f32)0x421, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xCA8), spD8, spD0, 0, 8, 0);
        spC8 = fclMakeVec2(370.0f, 121.0f);
        spC0 = fclMakeVec2(-230.0f, 121.0f);
        fclObjStartPosition(*(void **)(work + 0xE98), spC8, spC0, 0, 8, 0);
        spB8 = fclMakeVec2((f32)0x1C9, 121.0f);
        spB0 = fclMakeVec2(-143.0f, 121.0f);
        fclObjStartPosition(*(void **)(work + 0xEA0), spB8, spB0, 0, 8, 0);
        return;
    case 1:
        spA8 = fclMakeVec2(370.0f, 234.0f);
        spA0 = fclMakeVec2((f32)0x3CA, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xC9C), spA8, spA0, 0, 8, 0);
        sp98 = fclMakeVec2((f32)0x1C9, 234.0f);
        sp90 = fclMakeVec2((f32)0x421, 234.0f);
        fclObjStartPosition(*(void **)(work + 0xCA4), sp98, sp90, 0, 8, 0);
        sp88 = fclMakeVec2(370.0f, 121.0f);
        sp80 = fclMakeVec2(-230.0f, 121.0f);
        fclObjStartPosition(*(void **)(work + 0xE94), sp88, sp80, 0, 8, 0);
        sp78 = fclMakeVec2((f32)0x1C9, 120.0f);
        sp70 = fclMakeVec2(-143.0f, 122.0f);
        fclObjStartPosition(*(void **)(work + 0xE9C), sp78, sp70, 0, 8, 0);
        return;
    case 2:
        sp68 = fclMakeVec2((f32)0x16F, 225.0f);
        sp60 = fclMakeVec2((f32)0x3C7, 225.0f);
        fclObjStartPosition(*(void **)(work + 0xCB8), sp68, sp60, 0, 8, 0);
        sp58 = fclMakeVec2(454.0f, 225.0f);
        sp50 = fclMakeVec2((f32)0x41E, 225.0f);
        fclObjStartPosition(*(void **)(work + 0xEAC), sp58, sp50, 0, 8, 0);
        sp48 = fclMakeVec2((f32)0x16F, 111.0f);
        sp40 = fclMakeVec2(-233.0f, 111.0f);
        fclObjStartPosition(*(void **)(work + 0xCBC), sp48, sp40, 0, 8, 0);
        sp38 = fclMakeVec2(454.0f, 111.0f);
        sp30 = fclMakeVec2(-146.0f, 111.0f);
        fclObjStartPosition(*(void **)(work + 0xEB0), sp38, sp30, 0, 8, 0);
        return;
    }
}



// Draws the shop row for selection index arg1: resets the row's scaled-sprite positions, then moves the chosen row's sprites down by 3.
// FUN_002D7C10
void fclShopDrawSelectRow(void *arg0, s16 arg1) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;

    r = (s32)sdkSpriteNewNode((u32)(work->field_F28), (u32)(4));
    sdkSpriteScaledWidth((u8 *)r);
    sdkSpriteScaledHeight((u8 *)r);
    sdkSpriteFreeNode((u8 *)r);
    fclObjStartTween(work->field_EC4, ((ShopWork *)fclObjectGetWork(work->field_EC4))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_EC8, ((ShopWork *)fclObjectGetWork(work->field_EC8))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_CC4, ((ShopWork *)fclObjectGetWork(work->field_CC4))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_EB4, ((ShopWork *)fclObjectGetWork(work->field_EB4))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_EB8, ((ShopWork *)fclObjectGetWork(work->field_EB8))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_CC0, ((ShopWork *)fclObjectGetWork(work->field_CC0))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_EBC, ((ShopWork *)fclObjectGetWork(work->field_EBC))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_EC0, ((ShopWork *)fclObjectGetWork(work->field_EC0))->field_C4, 0.0f, 0, 2, 0);
    fclObjStartTween(work->field_E38, ((ShopWork *)fclObjectGetWork(work->field_E38))->field_C4, 0.0f, 0, 2, 0);
    switch ((s32)arg1) {
    case 0:
        fclObjStartTween(work->field_EC4, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->field_EC8, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->field_E38, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 1:
        fclObjStartTween(work->field_EB4, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->field_EB8, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->field_CC4, 0.0f, -3.0f, 0, 2, 0);
        break;
    case 2:
        fclObjStartTween(work->field_EBC, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->field_EC0, 0.0f, -3.0f, 0, 2, 0);
        fclObjStartTween(work->field_CC0, 0.0f, -3.0f, 0, 2, 0);
        break;
    }
}

// FUN_002D7F90
void fclShopStartSelectionShake(void *arg0) {
    s16 v1;
    u8 *p;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v2;
    u32 hi;
    f32 f1;
    f32 f20;

    p = D_0063F9F0 + (s32)*(s8 *)((u8 *)work + 7) * 12;
    r = (s32)sdkSpriteNewNode((u32)(work->field_F28), (u32)(4));
    v1 = (s16)(s32)((*(f32 *)(p + 8) + sdkSpriteScaledWidth((u8 *)r)) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_C44))->field_100 = v1;
    v2 = (s16)(s32)(sdkSpriteScaledHeight((u8 *)r) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_C44))->field_102 = v2;
    f1 = (f32)v1;
    v1 = (s16)(s32)(f1 - *(f32 *)(p + 8));
    ((ShopWork *)fclObjectGetWork(work->field_C48))->field_100 = v1;
    v2 = (s16)(s32)(sdkSpriteScaledHeight((u8 *)r) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_C48))->field_102 = v2;
    hi = RpRandom() % 20U;
    f1 = (f32)hi;
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (!(((ShopWork *)fclObjectGetWork(work->field_C44))->field_C4 <= 0.0f)) {
        f20 = f20 * -1.0f;
    }
    fclObjStartTween(work->field_C44, 0.0f, f20, 0, 0, 0);
    fclObjStartTween(work->field_C48, 0.0f, f20, 0, 0, 0);
    sdkSpriteFreeNode((u8 *)r);
}

// Slides the shop indicator by 4 units (up for arg1 == 0, down for arg1 == 1) on the first sprite node.
// FUN_002D8200
void fclShopSlideIndicator(void *arg0, s8 arg1) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v;
    f32 f20;

    fclObjectGetWork(work->field_E60);
    f20 = 4.0f;
    if (arg1 == 1) {
        f20 = f20 * -1.0f;
    }
    r = (s32)sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x7D));
    v = (s16)(s32)sdkSpriteScaledWidth((u8 *)r);
    ((ShopWork *)fclObjectGetWork(work->field_E2C))->field_100 = v;
    v = (s16)(s32)(sdkSpriteScaledHeight((u8 *)r) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_E2C))->field_102 = v;
    ((ShopWork *)fclObjectGetWork(work->field_E30))->field_100 = 0;
    v = (s16)(s32)(sdkSpriteScaledHeight((u8 *)r) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_E30))->field_102 = v;
    fclObjStartTween(work->field_E2C, 0.0f, f20, 0, 4, 0);
    fclObjStartTween(work->field_E30, 0.0f, f20, 0, 4, 0);
    ((ShopWork *)fclObjectGetWork(work->field_E2C))->field_CF = 1;
    ((ShopWork *)fclObjectGetWork(work->field_E30))->field_CF = 1;
    sdkSpriteFreeNode((u8 *)r);
}


/* fclShopDrawSwingCursor's body; fclShopSlideInFromAbove inlines it (retail re-reads the work
   pointer from the kept arg0 there). */
static inline void shopSwingCursor(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s32 r;
    s16 v2;
    s16 v1;
    u32 hi;
    f32 f1;
    f32 f20;

    r = (s32)sdkSpriteNewNode((u32)(work->field_F28), (u32)(4));
    v1 = (s16)(s32)((sdkSpriteScaledWidth((u8 *)r) + 79.0f) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_ED4))->field_100 = v1;
    v2 = (s16)(s32)(sdkSpriteScaledHeight((u8 *)r) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_ED4))->field_102 = v2;
    v2 = (s16)(v1 - 0x4F);
    ((ShopWork *)fclObjectGetWork(work->field_ED8))->field_100 = v2;
    v2 = (s16)(s32)(sdkSpriteScaledHeight((u8 *)r) / 2.0f);
    ((ShopWork *)fclObjectGetWork(work->field_ED8))->field_102 = v2;
    hi = RpRandom() % 20U;
    f1 = (f32)hi;
    f20 = shopAdd(f1 / 10.0f, 1.0f);
    if (!(((ShopWork *)fclObjectGetWork(work->field_ED4))->field_C4 <= 0.0f)) {
        f20 = f20 * -1.0f;
    }
    fclObjStartTween(work->field_ED4, 0.0f, f20, 0, 0, 0);
    fclObjStartTween(work->field_ED8, 0.0f, f20, 0, 0, 0);
    sdkSpriteFreeNode((u8 *)r);
}

// Entry point for the cursor swing: runs the cursor animation step for this shop work.
// FUN_002D83C0
void fclShopDrawSwingCursor(void *arg0) {
    shopSwingCursor(arg0);
}

// FUN_002D8600
void fclShopHideSelectionSprites(void *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    s16 i;
    u8 *t;
    Vec2f grp1;
    Vec2f sp60;
    Vec2f sp58;
    Vec2f sp50;
    Vec2f sp48;
    Vec2f grp4;
    Vec2f grp3;
    Vec2f grp2;

    fclObjChangeFlagBit(work->field_CA0, 0, 1);
    fclObjChangeFlagBit(work->field_CA8, 0, 1);
    fclObjChangeFlagBit(work->field_C9C, 0, 1);
    fclObjChangeFlagBit(work->field_CA4, 0, 1);
    fclObjChangeFlagBit(work->field_CB8, 0, 1);
    fclObjChangeFlagBit(work->field_EAC, 0, 1);
    for (i = 0; i < 3; i++) {
        s32 off = (s32)i * 4;
        fclObjChangeFlagBit(*(void **)((u8 *)work + 0xDBC + off), 0, 1);
    }
    fclObjChangeFlagBit(work->field_CAC, 0, 1);
    fclObjChangeFlagBit(work->field_E84, 0, 1);
    fclObjChangeFlagBit(work->field_C94, 0, 1);
    fclObjChangeFlagBit(work->field_C98, 0, 1);
    t = (u8 *)fclObjectGetWork(work->field_E50);
    grp1 = ((FclObject *)t)->anchorPosition;
    sp60 = fclMakeVec2(740.0f + grp1.x, grp1.y);
    fclObjStartPosition(work->field_E50, grp1, sp60, 0, 4, 0);
    t = (u8 *)fclObjectGetWork(work->field_E54);
    grp2 = ((FclObject *)t)->anchorPosition;
    sp58 = fclMakeVec2(740.0f + grp2.x, grp2.y);
    fclObjStartPosition(work->field_E54, grp2, sp58, 0, 4, 0);
    t = (u8 *)fclObjectGetWork(work->field_E58);
    grp3 = ((FclObject *)t)->anchorPosition;
    sp50 = fclMakeVec2(740.0f + grp3.x, grp3.y);
    fclObjStartPosition(work->field_E58, grp3, sp50, 0, 4, 0);
    t = (u8 *)fclObjectGetWork(work->field_E5C);
    grp4 = ((FclObject *)t)->anchorPosition;
    sp48 = fclMakeVec2(740.0f + grp4.x, grp4.y);
    fclObjStartPosition(work->field_E5C, grp4, sp48, 0, 4, 0);
    fclObjStartSlideFade(work->field_EC4, 3, fGpffff8504, 1.0f, 6, 0, 1);
    fclObjStartSlideFade(work->field_EC8, 4, fGpffff8504, 1.0f, 6, 0, 1);
    fclObjStartSlideFade(work->field_E38, 0x80, fGpffff8504, 1.0f, 6, 0, 1);
    fclObjStartSlideFade(work->field_EB4, 3, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjStartSlideFade(work->field_EB8, 4, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjStartSlideFade(work->field_CC4, 0x23, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjStartSlideFade(work->field_EBC, 3, fGpffff8504, 1.0f, 6, 2, 1);
    fclObjStartSlideFade(work->field_EC0, 4, fGpffff8504, 1.0f, 6, 2, 1);
    fclObjStartSlideFade(work->field_CC0, 0x22, fGpffff8504, 1.0f, 6, 1, 1);
    fclObjChangeFlagBit(work->field_DDC, 0, 0);
    fclObjChangeFlagBit(work->field_DE4, 0, 0);
    fclObjChangeFlagBit(work->field_DE0, 0, 1);
    *(s8 *)((u8 *)work + 0xC24) = 0;
}

/* MATCHED func_002d8a60: file-local ShopListWork overlay (list[3] at 0xF18,
   ShopSlide slides[2][5] at 0xFA0, select/scroll s8[3] at 0x1168/0x116B) so
   indexed fields fold into base+index with displacement; scoped
   opt_loop_invariants on hoists the per-list bases and the `start + 5` bound
   like retail; `idx = arg1` for the list/table accesses, bare `arg1` elsewhere;
   func_002e2830 is an int-returning callee re-narrowed with (s16) at each use;
   the second fclDrawNumber value stays an inline argument so only the first
   (digits) is spilled, as in retail. */
typedef struct {
    s16 duration;
    s16 timer;
    s16 delay;
    u8 pad6[0x1A];
} ShopSlide;
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
    ShopSlide slides[2][5];
    u8 pad10E0[0x88];
    s8 select[3];
    s8 scroll[3];
} ShopListWork;
#pragma push
#pragma opt_loop_invariants on
// FUN_002D8A60
void fclShopDrawItemRows(void *arg0, s8 arg1, f32 x, f32 y) {
    FclDrawColor c20C;
    FclDrawColor c208;
    FclDrawColor c204;
    FclDrawColor c200;
    FclDrawColor c1FC;
    FclDrawColor c1F8;
    FclDrawColor c1F4;
    FclDrawColor c1F0;
    FclDrawColor c1EC;
    FclDrawColor c1E8;
    FclDrawColor c1E4;
    FclDrawColor c1E0;
    FclDrawColor c1DC;
    FclDrawColor c1D8;
    FclDrawColor c1D4;
    FclDrawColor c1D0;
    FclDrawColor c1CC;
    Vec2f sp1C0;
    Vec2f sp1B8;
    Vec2f sp1B0;
    Vec2f sp1A8;
    Vec2f sp1A0;
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f pos;
    ShopListWork *work;
    u8 *t;
    Vec2f *base;
    s32 idx;
    s32 count;
    s16 start;
    s16 cur;
    s16 row;
    s16 i;
    f32 fx;
    s32 textColor;
    s32 iconColor;
    s32 lineColor;
    u32 flags;
    u32 digits;

    work = *(ShopListWork **)((u8 *)arg0 + 0x38);
    idx = arg1;
    count = yListCountFor(work->list[idx]);
    yListLastIndexFor(work->list[idx]);
    if (yListCountFor(work->list[idx]) <= D_00748908[idx]) {
        fx = fclEaseInterpolate(0, x, y, (f32)work->slides[arg1][0].timer, (f32)work->slides[arg1][0].duration);
        work->slides[arg1][0].timer = fclAddClamped(work->slides[arg1][0].timer, 1, work->slides[arg1][0].duration, 0, 1);
        if (arg1 == work->active) {
            base = (Vec2f *)D_0063F9C0;
            fclObjSetAnchorPosition(work->bar0[0], 0x57, 117.0f);
            c208 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            t = (u8 *)fclObjectGetWork(work->bar0[0]);
            ((FclObject *)t)->color = c208;
            ((ShopWork *)fclObjectGetWork(work->bar0[0]))->field_30 = base->y;
            ((ShopWork *)fclObjectGetWork(work->bar0[0]))->field_2C = 86.0f + fx;
            base = (Vec2f *)D_0063F9C8;
            fclObjSetAnchorPosition(work->bar0[1], 0x56, 118.0f);
            c204 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            t = (u8 *)fclObjectGetWork(work->bar0[1]);
            ((FclObject *)t)->color = c204;
            ((ShopWork *)fclObjectGetWork(work->bar0[1]))->field_30 = base->y;
            ((ShopWork *)fclObjectGetWork(work->bar0[1]))->field_2C = fx - 10.0f;
            base = (Vec2f *)D_0063F9D0;
            fclObjSetAnchorPosition(work->bar0[2], 0x56, 119.0f);
            c200 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            t = (u8 *)fclObjectGetWork(work->bar0[2]);
            ((FclObject *)t)->color = c200;
            ((ShopWork *)fclObjectGetWork(work->bar0[2]))->field_30 = base->y;
            ((ShopWork *)fclObjectGetWork(work->bar0[2]))->field_2C = 440.0f + fx;
            fclObjChangeFlagBit(work->mark0, 0, 1);
            fclObjChangeFlagBit(work->mark1, 0, 1);
            return;
        }
        {
            base = (Vec2f *)D_0063F9C0;
            fclObjSetAnchorPosition(work->bar1[0], 0x57, 117.0f);
            c1FC = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
            t = (u8 *)fclObjectGetWork(work->bar1[0]);
            ((FclObject *)t)->color = c1FC;
            ((ShopWork *)fclObjectGetWork(work->bar1[0]))->field_30 = base->y;
            ((ShopWork *)fclObjectGetWork(work->bar1[0]))->field_2C = 86.0f + fx;
            base = (Vec2f *)D_0063F9C8;
            fclObjSetAnchorPosition(work->bar1[1], 0x56, 118.0f);
            c1F8 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            t = (u8 *)fclObjectGetWork(work->bar1[1]);
            ((FclObject *)t)->color = c1F8;
            ((ShopWork *)fclObjectGetWork(work->bar1[1]))->field_30 = base->y;
            ((ShopWork *)fclObjectGetWork(work->bar1[1]))->field_2C = fx - 10.0f;
            base = (Vec2f *)D_0063F9D0;
            fclObjSetAnchorPosition(work->bar1[2], 0x56, 119.0f);
            c1F4 = fclMakeDrawColor(0x6B, 0x6B, 0x6B, 0xFF);
            t = (u8 *)fclObjectGetWork(work->bar1[2]);
            ((FclObject *)t)->color = c1F4;
            ((ShopWork *)fclObjectGetWork(work->bar1[2]))->field_30 = base->y;
            ((ShopWork *)fclObjectGetWork(work->bar1[2]))->field_2C = 440.0f + fx;
            fclObjChangeFlagBit(work->mark2, 0, 1);
            fclObjChangeFlagBit(work->mark3, 0, 1);
        }
        return;
    }
    fclAddClamped(0, count, 5, 0, 1);
    start = work->select[arg1] - work->scroll[arg1];
    if (start < 0) {
        start = 0;
    }

    for (cur = start, row = 0; cur < start + 5; cur++, row++) {
        fx = x;
        if (work->slides[arg1][row].delay > 0) {
            work->slides[arg1][row].delay = fclSubClamped(work->slides[arg1][row].delay, 1, 0, 0, 1);
        } else {
            fx = fclEaseInterpolate(0, x, y, (f32)work->slides[arg1][row].timer, (f32)work->slides[arg1][row].duration);
            work->slides[arg1][row].timer = fclAddClamped(work->slides[arg1][row].timer, 1, work->slides[arg1][row].duration, 0, 1);
        }
        if (row == work->scroll[arg1]) {

            if (arg1 == work->active) {
                base = (Vec2f *)D_0063F888;
                fclObjSetAnchorPosition(work->mark0, 0x41, 143.0f);
                c1F0 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                t = (u8 *)fclObjectGetWork(work->mark0);
                ((FclObject *)t)->color = c1F0;
                ((ShopWork *)fclObjectGetWork(work->mark0))->field_62 = 0xFF;
                ((ShopWork *)fclObjectGetWork(work->mark0))->field_30 = base->y + (f32)(work->scroll[arg1] << 5);
                ((ShopWork *)fclObjectGetWork(work->mark0))->field_2C = fx - 10.0f;
                fclObjSetAnchorPosition(work->mark1, 0x41, 143.0f);
                c1EC = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                t = (u8 *)fclObjectGetWork(work->mark1);
                ((FclObject *)t)->color = c1EC;
                ((ShopWork *)fclObjectGetWork(work->mark1))->field_62 = 0xFF;
                ((ShopWork *)fclObjectGetWork(work->mark1))->field_30 = base->y + (f32)(work->scroll[arg1] << 5);
                ((ShopWork *)fclObjectGetWork(work->mark1))->field_2C = 444.0f + fx;
                fclObjChangeFlagBit(work->bar0[0], 0, 1);
                fclObjChangeFlagBit(work->bar0[1], 0, 1);
                fclObjChangeFlagBit(work->bar0[2], 0, 1);
            } else {
                base = (Vec2f *)D_0063F888;
                fclObjSetAnchorPosition(work->mark2, 0x41, 143.0f);
                c1E8 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                t = (u8 *)fclObjectGetWork(work->mark2);
                ((FclObject *)t)->color = c1E8;
                ((ShopWork *)fclObjectGetWork(work->mark2))->field_62 = 0xFF;
                ((ShopWork *)fclObjectGetWork(work->mark2))->field_30 = base->y + (f32)(work->scroll[arg1] << 5);
                ((ShopWork *)fclObjectGetWork(work->mark2))->field_2C = fx - 10.0f;
                fclObjSetAnchorPosition(work->mark3, 0x41, 143.0f);
                c1E4 = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
                t = (u8 *)fclObjectGetWork(work->mark3);
                ((FclObject *)t)->color = c1E4;
                ((ShopWork *)fclObjectGetWork(work->mark3))->field_62 = 0xFF;
                ((ShopWork *)fclObjectGetWork(work->mark3))->field_30 = base->y + (f32)(work->scroll[arg1] << 5);
                ((ShopWork *)fclObjectGetWork(work->mark3))->field_2C = 444.0f + fx;
                fclObjChangeFlagBit(work->bar1[0], 0, 1);
                fclObjChangeFlagBit(work->bar1[1], 0, 1);
                fclObjChangeFlagBit(work->bar1[2], 0, 1);
            }
        }
        if (cur < yListCountFor(work->list[idx])) {
            textColor = fclPackRgba(0xFF, 0xAE, 0, 0xFF);
            iconColor = fclPackRgba(0, 0xFF, 0xAE, 0);
            c20C = fclMakeDrawColor(0xFF, 0xAE, 0, 0xFF);
            lineColor = fclPackRgba(0, 0xFE, 0xC7, 0x31);
            if (cur == work->select[arg1]) {
                textColor = fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF);
                iconColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
                c20C = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                lineColor = fclPackRgba(0, 0x2D, 0x2D, 0x2D);
            }
            if (arg1 == 0 && cur == 0) {
                if (yListCountFor(work->list[idx]) > 1) {
                    for (i = 0; i < 3; i++) {
                        sp1C0 = fclMakeVec2(31.0f + fx + (f32)(i * 32), 143.0f);
                        fclDrawEquipSprite(0x3C, sp1C0, 141.0f, lineColor, 0xFF, 0, D_00795E60);
                        sp1B8 = fclMakeVec2((f32)0x151 + fx + (f32)(i * 32), 143.0f);
                        fclDrawEquipSprite(0x3C, sp1B8, 141.0f, lineColor, 0xFF, 0, D_00795E60);
                    }
                    fclObjSetAnchorPosition(work->frame1, 0x56, 142.0f);
                    c1E0 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                    t = (u8 *)fclObjectGetWork(work->frame1);
                    ((FclObject *)t)->color = c1E0;
                    if (cur == work->cursor) {
                        c1DC = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                        t = (u8 *)fclObjectGetWork(work->frame1);
                        ((FclObject *)t)->color = c1DC;
                    }
                    ((ShopWork *)fclObjectGetWork(work->frame1))->field_2C = 128.0f + fx;
                    fclObjSetAnchorPosition(work->frame2, 0x56, 142.0f);
                    c1D8 = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                    t = (u8 *)fclObjectGetWork(work->frame2);
                    ((FclObject *)t)->color = c1D8;
                    if (cur == work->cursor) {
                        c1D4 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                        t = (u8 *)fclObjectGetWork(work->frame2);
                        ((FclObject *)t)->color = c1D4;
                    }
                    ((ShopWork *)fclObjectGetWork(work->frame2))->field_2C = (f32)0x133 + fx;
                    fclObjSetAnchorPosition(work->frame0, 0x57, 141.0f);
                    c1D0 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
                    t = (u8 *)fclObjectGetWork(work->frame0);
                    ((FclObject *)t)->color = c1D0;
                    if (cur == work->cursor) {
                        c1CC = fclMakeDrawColor(0xFE, 0xC7, 0x31, 0xFF);
                        t = (u8 *)fclObjectGetWork(work->frame0);
                        ((FclObject *)t)->color = c1CC;
                    }
                    ((ShopWork *)fclObjectGetWork(work->frame0))->field_2C = 144.0f + fx;
                }
            } else {
                flags = datEntryGetFlags((s16)yListValueAtFor(work->list[idx], cur));
                if (flags & 0x81) {
                    sp1B0 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x14, sp1B0, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x102) {
                    sp1A8 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x15, sp1A8, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x204) {
                    sp1A0 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x16, sp1A0, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x408) {
                    sp198 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x17, sp198, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x810) {
                    sp190 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x18, sp190, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x1020) {
                    sp188 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x19, sp188, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x2040) {
                    sp180 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x1A, sp180, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x4000) {
                    sp178 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x1B, sp178, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x8000) {
                    sp170 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipSprite(0x1C, sp170, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else if (flags & 0x40000) {
                    sp168 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipHelpSprite(0x1A, sp168, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                } else {
                    sp160 = fclMakeVec2(fx, 135.0f + (f32)(row * 32));
                    fclDrawEquipHelpSprite(0x1B, sp160, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                }
                sp158 = fclMakeVec2(43.0f + fx, 133.0f + (f32)(row * 32));
                pos = *(Vec2f *)&sp158; /* word-aligned view: lwc1/swc1 copy, not ld/sd */
                frFontExDrawTextDeferredWithCharWidth(pos.x, pos.y, 141.0f, textColor, 0, 1,
                              ((void *)datGetItemNameId((s16)yListValueAtFor(work->list[idx], cur))),
                              0, 0, D_00795E30, -1);
                digits = datItemPrice((s16)yListValueAtFor(work->list[idx], cur)) / 5;
                sp150 = fclMakeVec2(362.0f + fx, 142.0f + (f32)(row * 32));
                fclDrawNumber(sp150, 141.0f, c20C, 0x10, 5, digits, 9, 0x7B,
                              (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->font, 0xA9);
                sp148 = fclMakeVec2(390.0f + fx, 144.0f + (f32)(row * 32));
                fclDrawEquipSprite(0x47, sp148, 141.0f, iconColor, 0xFF, 0, D_00795E60);
                sp140 = fclMakeVec2((f32)0x1A5 + fx, 142.0f + (f32)(row * 32));
                fclDrawNumber(sp140, 141.0f, c20C, 0x10, 5,
                              datItemCount((s16)yListValueAtFor(work->list[idx], cur)) & 0xFF, 9, 0x7B,
                              (s32)resourceFindByName((char *)(D_0063FB50)), (s32)work->font, 0xA9);
            }
        }
    }
}
#pragma pop

// FUN_002DA0A0
void fclShopSlideInFromAbove(void *arg0) {
    u8 *work;
    Vec2f *base;
    ShopSpinParam *fa;
    void *r;
    s16 i;
    void *r0;
    void *r1;
    void *r2;
    void *r3;
    void *r4;
    void *r5;
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

    work = *(u8 **)((u32)arg0 + 0x38);
    fclObjChangeFlagBit(*(void **)(work + 0xDEC), 0, 1);

    base = (Vec2f *)D_0063F5A0;
    fclObjSetAnchorPosition(*(void **)(work + 0xC58), 0x41, 162.0f);
    p0 = fclMakeVec2(base->x, base->y - 450.0f);
    p1 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC58), p0, p1, 0, 4, 0);
    fclObjStartAlpha(*(void **)(work + 0xC58), 0, 0xCC, 0, 2, 0);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC58)) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);

    base = (Vec2f *)D_0063F5A8;
    fclObjSetAnchorPosition(*(void **)(work + 0xC5C), 0x41, 163.0f);
    p2 = fclMakeVec2(base->x, base->y - 450.0f);
    p3 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC5C), p2, p3, 0, 4, 0);
    fclObjStartAlpha(*(void **)(work + 0xC5C), 0, 0xCC, 0, 2, 0);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC5C)) + 0x79) = fclMakeDrawColor(0, 0, 0, 0xFF);

    for (i = 0; i < *(s8 *)(work + 9); i++) {
        *(s16 *)(work + i * 2 + 0xF46) = 0;
        *(s16 *)(work + i * 2 + 0xF58) = 0;
        *(s8 *)(work + i + 0xF6A) = 0;
    }

    fclObjSetAnchorPosition(*(void **)(work + 0xED4), 0x41, 126.0f);
    row = *(s8 *)(work + 8);
    p4 = fclMakeVec2(47.0f, (78.0f + 35.0f * (f32)(s32)row) - 450.0f);
    p5 = fclMakeVec2(47.0f, 78.0f + 35.0f * (f32)row);
    fclObjStartPosition(*(void **)(work + 0xED4), p4, p5, 0, 6, ((s16 *)(work + 0xF46))[(s8)row]);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xED4)) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
    fclObjSetAnchorPosition(*(void **)(work + 0xED8), 0x41, 127.0f);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xED8)) + 0x79) = fclMakeDrawColor(0xFE, 0xC6, 0x31, 0xFF);
    p6 = fclMakeVec2(126.0f, (78.0f + 35.0f * (f32)*(s8 *)(work + 8)) - 450.0f);
    p7 = fclMakeVec2(126.0f, 78.0f + 35.0f * (f32)*(s8 *)(work + 8));
    fclObjStartPosition(*(void **)(work + 0xED8), p6, p7, 0, 6, 0);
    shopSwingCursor(arg0);

    fclObjSetAnchorPosition(*(void **)(work + 0xD3C), 0x41, 128.0f);
    fclObjStartAlpha(*(void **)(work + 0xD3C), 0, 0xFF, 0, 0xA, 0);

    base = (Vec2f *)D_0063F7B0;
    fclObjSetAnchorPosition(*(void **)(work + 0xD60), 0x41, 78.0f);
    p8 = fclMakeVec2(base->x, base->y - (f32)0x226);
    p9 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD60), p8, p9, 2, 4, 0);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD60)) + 0x100) = *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD60)) + 0x102) = 0;
    fclObjStartTween(*(void **)(work + 0xD60), -5.0f, fGpffff852c, 2, 2, 2);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD60)) + 0x79) = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);

    base = (Vec2f *)D_0063F7B8;
    fclObjSetAnchorPosition(*(void **)(work + 0xD64), 0x41, 78.0f);
    p10 = fclMakeVec2(base->x, base->y - (f32)0x226);
    p11 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD64), p10, p11, 2, 4, 0);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD64)) + 0x100) = -50;
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD64)) + 0x102) = -219;
    fclObjStartTween(*(void **)(work + 0xD64), -5.0f, fGpffff852c, 2, 2, 2);

    base = (Vec2f *)D_0063F8C0;
    fclObjSetAnchorPosition(*(void **)(work + 0xDE8), 0x41, 46.0f);
    fclObjStartAlpha(*(void **)(work + 0xDE8), 0, 0xFF, 0, 6, 0);
    *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xDE8)) + 0x2C) = base->x;
    *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xDE8)) + 0x30) = base->y;

    fclObjSetAnchorPosition(*(void **)(work + 0xDF0), 0x41, 47.0f);
    fclObjStartAlpha(*(void **)(work + 0xDF0), 0, 0xFF, 0, 6, 0);

    r0 = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x44));
    base = (Vec2f *)D_0063F780;
    fclObjSetAnchorPosition(*(void **)(work + 0xD48), 0x56, 53.0f);
    p12 = fclMakeVec2(base->x, -130.0f);
    p13 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD48), p12, p13, 2, 5, 0);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD48)) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD48)) + 0x100) = (s16)(sdkSpriteScaledWidth(r0) / 2.0f);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD48)) + 0x102) = (s16)(sdkSpriteScaledHeight(r0) / 2.0f);
    fclObjSetHoldTimer(*(void **)(work + 0xD48), (f32)D_0063FA44[0], D_0063FA46[0]);
    fclObjStartTween(*(void **)(work + 0xD48), D_0063FA40[0], 0.0f, 2, D_0063FA46[0] + 5, 0);
    sdkSpriteFreeNode(r0);

    r1 = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x43));
    base = (Vec2f *)D_0063F778;
    fa = (ShopSpinParam *)D_0063FA48;
    fclObjSetAnchorPosition(*(void **)(work + 0xD44), 0x56, 54.0f);
    p14 = fclMakeVec2(base->x, -189.0f);
    p15 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD44), p14, p15, 2, 5, 3);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD44)) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD44)) + 0x100) = (s16)(sdkSpriteScaledWidth(r1) / 2.0f);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD44)) + 0x102) = (s16)(sdkSpriteScaledHeight(r1) / 2.0f);
    fclObjSetHoldTimer(*(void **)(work + 0xD44), (f32)fa->speed, fa->frames);
    fclObjStartTween(*(void **)(work + 0xD44), fa->angle, 0.0f, 2, fa->frames + 5, 3);
    sdkSpriteFreeNode(r1);

    r2 = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x45));
    base = (Vec2f *)D_0063F788;
    fa = (ShopSpinParam *)D_0063FA48 + 1;
    fclObjSetAnchorPosition(*(void **)(work + 0xD4C), 0x56, 55.0f);
    p16 = fclMakeVec2(base->x, -75.0f);
    p17 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD4C), p16, p17, 2, 5, 1);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD4C)) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD4C)) + 0x100) = (s16)(sdkSpriteScaledWidth(r2) / 2.0f);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD4C)) + 0x102) = (s16)(sdkSpriteScaledHeight(r2) / 2.0f);
    fclObjSetHoldTimer(*(void **)(work + 0xD4C), (f32)fa->speed, fa->frames);
    fclObjStartTween(*(void **)(work + 0xD4C), fa->angle, 0.0f, 2, fa->frames + 5, 1);
    sdkSpriteFreeNode(r2);

    r3 = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x46));
    base = (Vec2f *)D_0063F790;
    fa = (ShopSpinParam *)D_0063FA48 + 2;
    fclObjSetAnchorPosition(*(void **)(work + 0xD50), 0x56, 56.0f);
    p18 = fclMakeVec2(base->x, -165.0f);
    p19 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD50), p18, p19, 2, 5, 4);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD50)) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD50)) + 0x100) = (s16)(sdkSpriteScaledWidth(r3) / 2.0f);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD50)) + 0x102) = (s16)(sdkSpriteScaledHeight(r3) / 2.0f);
    *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD50)) + 0xC4) = 0.0f;
    fclObjSetHoldTimer(*(void **)(work + 0xD50), (f32)fa->speed, fa->frames);
    fclObjStartTween(*(void **)(work + 0xD50), fa->angle, 0.0f, 2, fa->frames + 5, 4);
    sdkSpriteFreeNode(r3);

    r4 = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x47));
    base = (Vec2f *)D_0063F798;
    fa = (ShopSpinParam *)D_0063FA48 + 3;
    fclObjSetAnchorPosition(*(void **)(work + 0xD54), 0x56, 57.0f);
    p20 = fclMakeVec2(base->x, -126.0f);
    p21 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD54), p20, p21, 2, 5, 2);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD54)) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD54)) + 0x100) = (s16)(sdkSpriteScaledWidth(r4) / 2.0f);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD54)) + 0x102) = (s16)(sdkSpriteScaledHeight(r4) / 2.0f);
    *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD54)) + 0xC4) = 0.0f;
    fclObjSetHoldTimer(*(void **)(work + 0xD54), (f32)fa->speed, fa->frames);
    fclObjStartTween(*(void **)(work + 0xD54), fa->angle, 0.0f, 1, fa->frames + 5, 2);
    sdkSpriteFreeNode(r4);

    r5 = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x48));
    base = (Vec2f *)D_0063F7A0;
    fa = (ShopSpinParam *)D_0063FA48 + 4;
    fclObjSetAnchorPosition(*(void **)(work + 0xD58), 0x56, 58.0f);
    p22 = fclMakeVec2(base->x, -197.0f);
    p23 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xD58), p22, p23, 2, 5, 5);
    *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD58)) + 0x79) = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD58)) + 0x100) = (s16)(sdkSpriteScaledWidth(r5) / 2.0f);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD58)) + 0x102) = (s16)(sdkSpriteScaledHeight(r5) / 2.0f);
    *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD58)) + 0xC4) = 0.0f;
    fclObjSetHoldTimer(*(void **)(work + 0xD58), (f32)fa->speed, fa->frames);
    fclObjStartTween(*(void **)(work + 0xD58), fa->angle, 0.0f, 2, fa->frames + 5, 5);
    sdkSpriteFreeNode(r5);
    *(s8 *)work = 0x14;
}

/* MATCHED func_002db400: FclDrawColor results stored whole, Vec2f slots
   passed to fclObjStartPosition by value, the six spin tables read through a
   ShopSpinParam view (angle/speed/frames), func_002e09b0 called with its real
   (void *, f32, s16) order, `func_002e26f0(..) <= D_00748908[n]` with the call
   first, and each func_0046d200 handle scoped to its own block so the handle
   takes $s2 and the table base $s1 as in retail. */
// FUN_002DB400
void fclShopStartRevealSprites(void *arg0) {
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
    Vec2f sp198;
    Vec2f sp190;
    Vec2f sp188;
    Vec2f sp180;
    Vec2f sp178;
    Vec2f sp170;
    Vec2f sp168;
    Vec2f sp160;
    Vec2f sp158;
    Vec2f sp150;
    Vec2f sp148;
    Vec2f sp140;
    Vec2f sp138;
    Vec2f sp130;
    Vec2f sp128;
    Vec2f sp120;
    Vec2f sp118;
    Vec2f sp110;
    Vec2f sp108;
    Vec2f sp100;
    Vec2f spF8;
    Vec2f spF0;
    Vec2f spE8;
    Vec2f spE0;
    Vec2f spD8;
    Vec2f spD0;
    Vec2f spC8;
    Vec2f spC0;
    Vec2f spB8;
    Vec2f spB0;
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    u8 *work;
    Vec2f *base;
    u8 *t;
    ShopSpinParam *fa;
    work = *(u8 **)((u8 *)arg0 + 0x38);
    fclObjChangeFlagBit(*(void **)(work + 0xDEC), 0, 1);
    base = (Vec2f *)D_0063F5B8;
    fclObjSetAnchorPosition(*(void **)(work + 0xC64), 0x41, 157.0f);
    sp198 = fclMakeVec2(base->x, -300.0f + base->y);
    sp190 = fclMakeVec2(base->x, base->y);
    fclObjStartPosition(*(void **)(work + 0xC64), sp198, sp190, 0, 7, 0);
    fclObjStartAlpha(*(void **)(work + 0xC64), 0U, 0xCCU, 0U, 7, 0);
    c0 = fclMakeDrawColor(0, 0, 0, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xC64));
    ((FclObject *)t)->color = c0;
    fclObjStartTween(*(void **)(work + 0xC64), 0.0f, -4.0f, 0, 0, 0);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC64)) + 0x100) = (s16)(320.0f - base->x);
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC64)) + 0x102) = (s16)(base->y - 83.0f);
    fclObjStartRevealScale(*(void **)(work + 0xC64), 1.0f, 1.5f, 1.0f, 1.0f, 0, 0, 0);
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x44));
        fa = (ShopSpinParam *)D_0063FA70;
        fclObjSetAnchorPosition(*(void **)(work + 0xD48), 0x56, 53.0f);
        sp188 = fclMakeVec2((f32) 0x271, -200.0f);
        sp180 = fclMakeVec2((f32) 0x271, 300.0f);
        fclObjStartPosition(*(void **)(work + 0xD48), sp188, sp180, 2, 5, 5);
        c1 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xD48));
        ((FclObject *)t)->color = c1;
        *(f32 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD48)) + 0xC4) = 0.0f;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD48)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD48)) + 0x102) = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
        fclObjSetHoldTimer(*(void **)(work + 0xD48), (f32) fa->speed, fa->frames);
        fclObjStartTween(*(void **)(work + 0xD48), 180.0f + fa->angle, 180.0f, 0, fa->frames + 5, 5);
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x43));
        fa = (ShopSpinParam *)D_0063FA78;
        fclObjSetAnchorPosition(*(void **)(work + 0xD44), 0x56, 54.0f);
        sp178 = fclMakeVec2(506.0f, -149.0f);
        sp170 = fclMakeVec2(506.0f, (f32) 0x15F);
        fclObjStartPosition(*(void **)(work + 0xD44), sp178, sp170, 2, 5, 2);
        c2 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xD44));
        ((FclObject *)t)->color = c2;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD44)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD44)) + 0x102) = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
        fclObjSetHoldTimer(*(void **)(work + 0xD44), (f32) fa->speed, fa->frames);
        fclObjStartTween(*(void **)(work + 0xD44), 180.0f + fa->angle, 180.0f, 0, fa->frames + 5, 2);
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x45));
        fa = (ShopSpinParam *)D_0063FA80;
        fclObjSetAnchorPosition(*(void **)(work + 0xD4C), 0x56, 55.0f);
        sp168 = fclMakeVec2(592.0f, -191.0f);
        sp160 = fclMakeVec2(592.0f, (f32) 0x135);
        fclObjStartPosition(*(void **)(work + 0xD4C), sp168, sp160, 2, 5, 4);
        c3 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xD4C));
        ((FclObject *)t)->color = c3;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD4C)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD4C)) + 0x102) = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
        fclObjSetHoldTimer(*(void **)(work + 0xD4C), (f32) fa->speed, fa->frames);
        fclObjStartTween(*(void **)(work + 0xD4C), 180.0f + fa->angle, 180.0f, 0, fa->frames + 5, 4);
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x46));
        fa = (ShopSpinParam *)D_0063FA88;
        fclObjSetAnchorPosition(*(void **)(work + 0xD50), 0x56, 56.0f);
        sp158 = fclMakeVec2((f32) 0x1D3, -123.0f);
        sp150 = fclMakeVec2((f32) 0x1D3, (f32) 0x179);
        fclObjStartPosition(*(void **)(work + 0xD50), sp158, sp150, 2, 5, 1);
        c4 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xD50));
        ((FclObject *)t)->color = c4;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD50)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD50)) + 0x102) = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
        fclObjSetHoldTimer(*(void **)(work + 0xD50), (f32) fa->speed, fa->frames);
        fclObjStartTween(*(void **)(work + 0xD50), 180.0f + fa->angle, 180.0f, 0, fa->frames + 5, 1);
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x47));
        fa = (ShopSpinParam *)D_0063FA90;
        fclObjSetAnchorPosition(*(void **)(work + 0xD54), 0x56, 57.0f);
        sp148 = fclMakeVec2((f32) 0x225, -221.0f);
        sp140 = fclMakeVec2((f32) 0x225, (f32) 0x117);
        fclObjStartPosition(*(void **)(work + 0xD54), sp148, sp140, 2, 5, 3);
        c5 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xD54));
        ((FclObject *)t)->color = c5;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD54)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD54)) + 0x102) = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
        fclObjSetHoldTimer(*(void **)(work + 0xD54), (f32) fa->speed, fa->frames);
        fclObjStartTween(*(void **)(work + 0xD54), 180.0f + fa->angle, 180.0f, 0, fa->frames + 5, 3);
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(0x48));
        fa = (ShopSpinParam *)D_0063FA98;
        fclObjSetAnchorPosition(*(void **)(work + 0xD58), 0x56, 58.0f);
        sp138 = fclMakeVec2((f32) 0x195, -113.0f);
        sp130 = fclMakeVec2((f32) 0x195, (f32) 0x183);
        fclObjStartPosition(*(void **)(work + 0xD58), sp138, sp130, 2, 5, 0);
        c6 = fclMakeDrawColor(0xE4, 0xFF, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xD58));
        ((FclObject *)t)->color = c6;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD58)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) / 2.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xD58)) + 0x102) = (s16)(sdkSpriteScaledHeight(r) / 2.0f);
        fclObjSetHoldTimer(*(void **)(work + 0xD58), (f32) fa->speed, fa->frames);
        fclObjStartTween(*(void **)(work + 0xD58), 180.0f + fa->angle, 180.0f, 0, fa->frames + 5, 0);
        sdkSpriteFreeNode(r);
    }
    fclObjSetAnchorPosition(*(void **)(work + 0xD74), 0x56, 11.0f);
    fclObjStartAlpha(*(void **)(work + 0xD74), 0U, 0xFFU, 0U, 0xA, 0);
    fclObjSetAnchorPosition(*(void **)(work + 0xD80), 0x56, 9.0f);
    fclObjStartAlpha(*(void **)(work + 0xD80), 0U, 0xFFU, 0U, 0xA, 0);
    yListRebuildFor(*(void **)(work + 0xF18), 0x40000, 0, 4, 0);
    yListRebuildFor(*(void **)(work + 0xF1C), 0xFFFF, 0x1FE0, 1, 0);
    yListRebuildFor(*(void **)(work + 0xF20), 0x10000, 0, 1, 0);
    fclObjSetAnchorPosition(*(void **)(work + 0xC8C), 0x41, 139.0f);
    fclObjStartAlpha(*(void **)(work + 0xC8C), 0U, 0xFFU, 0U, 6, 7);
    c7 = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xC8C));
    ((FclObject *)t)->color = c7;
    fclObjSetAnchorPosition(*(void **)(work + 0xC90), 0x41, 140.0f);
    fclObjStartAlpha(*(void **)(work + 0xC90), 0U, 0xFFU, 0U, 6, 7);
    c8 = fclMakeDrawColor(0xCE, 0x71, 2, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xC90));
    ((FclObject *)t)->color = c8;
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(3));
        fclObjSetAnchorPosition(*(void **)(work + 0xEC4), 0x56, 131.0f);
        sp128 = fclMakeVec2(24.0f, -60.0f);
        sp120 = fclMakeVec2(24.0f, 48.0f);
        fclObjStartPosition(*(void **)(work + 0xEC4), sp128, sp120, 2, 7, 5);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC4)) + 0x62) = 0xFF;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC4)) + 0x100) = 0x55;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC4)) + 0x102) = 0x17;
        fclObjStartTween(*(void **)(work + 0xEC4), -3.0f, -3.0f, 0, 0, 0);
        c9 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEC4));
        ((FclObject *)t)->color = c9;
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(4));
        fclObjSetAnchorPosition(*(void **)(work + 0xEC8), 0x56, 132.0f);
        sp118 = fclMakeVec2(64.0f, -60.0f);
        sp110 = fclMakeVec2(64.0f, 48.0f);
        fclObjStartPosition(*(void **)(work + 0xEC8), sp118, sp110, 2, 7, 5);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC8)) + 0x62) = 0xFF;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC8)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) - 85.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC8)) + 0x102) = 0x17;
        fclObjStartTween(*(void **)(work + 0xEC8), -3.0f, -3.0f, 0, 0, 0);
        c10 = fclMakeDrawColor(0xFF, 0x96, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEC8));
        ((FclObject *)t)->color = c10;
        sdkSpriteFreeNode(r);
    }
    fclObjSetAnchorPosition(*(void **)(work + 0xE38), 0x57, 130.0f);
    sp108 = fclMakeVec2(52.0f, -60.0f);
    sp100 = fclMakeVec2(52.0f, 59.0f);
    fclObjStartPosition(*(void **)(work + 0xE38), sp108, sp100, 2, 7, 5);
    fclObjStartTween(*(void **)(work + 0xE38), -3.0f, -3.0f, 0, 0, 0);
    *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xE38)) + 0x62) = 0xFF;
    c11 = fclMakeDrawColor(0xFF, 0xF2, 0x95, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xE38));
    ((FclObject *)t)->color = c11;
    if (yListCountFor(*(void **)(work + 0xF18)) <= D_00748908[0]) {
        c12 = fclMakeDrawColor(0x9C, 0x9C, 0x9C, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEC4));
        ((FclObject *)t)->color = c12;
        c13 = fclMakeDrawColor(0x9C, 0x9C, 0x9C, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEC8));
        ((FclObject *)t)->color = c13;
        c14 = fclMakeDrawColor(0xFF, 0xFF, 0xFF, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xE38));
        ((FclObject *)t)->color = c14;
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(3));
        fclObjSetAnchorPosition(*(void **)(work + 0xEB4), 0x41, 137.0f);
        spF8 = fclMakeVec2(146.0f, -60.0f);
        spF0 = fclMakeVec2(146.0f, 40.0f);
        fclObjStartPosition(*(void **)(work + 0xEB4), spF8, spF0, 2, 7, 5);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEB4)) + 0x62) = 0xFF;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEB4)) + 0x100) = 0x55;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEB4)) + 0x102) = 0x17;
        c15 = fclMakeDrawColor(0xBD, 0x68, 3, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEB4));
        ((FclObject *)t)->color = c15;
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(4));
        fclObjSetAnchorPosition(*(void **)(work + 0xEB8), 0x41, 138.0f);
        spE8 = fclMakeVec2(186.0f, -60.0f);
        spE0 = fclMakeVec2(186.0f, 40.0f);
        fclObjStartPosition(*(void **)(work + 0xEB8), spE8, spE0, 2, 7, 5);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEB8)) + 0x62) = 0xFF;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEB8)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) - 85.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEB8)) + 0x102) = 0x17;
        c16 = fclMakeDrawColor(0xBD, 0x68, 3, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEB8));
        ((FclObject *)t)->color = c16;
        sdkSpriteFreeNode(r);
    }
    fclObjSetAnchorPosition(*(void **)(work + 0xCC4), 0x56, 136.0f);
    spD8 = fclMakeVec2(188.0f, -60.0f);
    spD0 = fclMakeVec2(188.0f, 51.0f);
    fclObjStartPosition(*(void **)(work + 0xCC4), spD8, spD0, 2, 7, 5);
    *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCC4)) + 0x62) = 0xFF;
    c17 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xCC4));
    ((FclObject *)t)->color = c17;
    if (yListCountFor(*(void **)(work + 0xF1C)) <= D_00748908[1]) {
        c18 = fclMakeDrawColor(0, 0, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEB4));
        ((FclObject *)t)->color = c18;
        c19 = fclMakeDrawColor(0, 0, 0, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEB8));
        ((FclObject *)t)->color = c19;
        c20 = fclMakeDrawColor(0x6F, 0x6F, 0x6F, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xCC4));
        ((FclObject *)t)->color = c20;
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(3));
        fclObjSetAnchorPosition(*(void **)(work + 0xEBC), 0x56, 134.0f);
        spC8 = fclMakeVec2(268.0f, -60.0f);
        spC0 = fclMakeVec2(268.0f, 48.0f);
        fclObjStartPosition(*(void **)(work + 0xEBC), spC8, spC0, 2, 7, 5);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEBC)) + 0x62) = 0xFF;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEBC)) + 0x100) = 0x55;
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEBC)) + 0x102) = 0x17;
        c21 = fclMakeDrawColor(0x90, 0x4F, 1, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEBC));
        ((FclObject *)t)->color = c21;
        sdkSpriteFreeNode(r);
    }
    {
        void *r = sdkSpriteNewNode((u32)(*(void **)(work + 0xF28)), (u32)(4));
        fclObjSetAnchorPosition(*(void **)(work + 0xEC0), 0x56, 135.0f);
        spB8 = fclMakeVec2(308.0f, -60.0f);
        spB0 = fclMakeVec2(308.0f, 48.0f);
        fclObjStartPosition(*(void **)(work + 0xEC0), spB8, spB0, 2, 7, 5);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC0)) + 0x100) = (s16)(sdkSpriteScaledWidth(r) - 85.0f);
        *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC0)) + 0x102) = 0x17;
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEC0)) + 0x62) = 0xFF;
        c22 = fclMakeDrawColor(0x90, 0x4F, 1, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEC0));
        ((FclObject *)t)->color = c22;
        sdkSpriteFreeNode(r);
    }
    fclObjSetAnchorPosition(*(void **)(work + 0xCC0), 0x57, 133.0f);
    spA8 = fclMakeVec2(288.0f, -60.0f);
    spA0 = fclMakeVec2(288.0f, 59.0f);
    fclObjStartPosition(*(void **)(work + 0xCC0), spA8, spA0, 2, 7, 5);
    *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCC0)) + 0x62) = 0xFF;
    *(s16 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCC0)) + 0x100) = 0x23;
    c23 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
    t = (u8 *)fclObjectGetWork(*(void **)(work + 0xCC0));
    ((FclObject *)t)->color = c23;
    if (yListCountFor(*(void **)(work + 0xF20)) <= D_00748908[2]) {
        c24 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEBC));
        ((FclObject *)t)->color = c24;
        c25 = fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xEC0));
        ((FclObject *)t)->color = c25;
        c26 = fclMakeDrawColor(0x6F, 0x6F, 0x6F, 0xFF);
        t = (u8 *)fclObjectGetWork(*(void **)(work + 0xCC0));
        ((FclObject *)t)->color = c26;
    }
    fclObjSetAnchorPosition(*(void **)(work + 0xDDC), 0x57, 49.0f);
    fclObjStartAlpha(*(void **)(work + 0xDDC), 0U, 0xFFU, 0U, 0xA, 0);
    fclObjSetAnchorPosition(*(void **)(work + 0xDE8), 0x57, 46.0f);
    fclObjStartAlpha(*(void **)(work + 0xDE8), 0U, 0xFFU, 0U, 0xA, 0);
    sp98 = fclMakeVec2(196.0f, 404.0f);
    sp90 = fclMakeVec2(196.0f, 404.0f);
    fclObjStartPosition(*(void **)(work + 0xDE8), sp98, sp90, 0, 0, 0);
    fclObjSetAnchorPosition(*(void **)(work + 0xDF0), 0x57, 47.0f);
    fclObjStartAlpha(*(void **)(work + 0xDF0), 0U, 0xFFU, 0U, 0xA, 0);
    sp88 = fclMakeVec2((f32) 0x103, 404.0f);
    sp80 = fclMakeVec2((f32) 0x103, 404.0f);
    fclObjStartPosition(*(void **)(work + 0xDF0), sp88, sp80, 0, 0, 0);
    fclObjSetAnchorPosition(*(void **)(work + 0xDE4), 0x57, 47.0f);
    fclObjStartAlpha(*(void **)(work + 0xDE4), 0U, 0xFFU, 0U, 0xA, 0);
    sp78 = fclMakeVec2(338.0f, 404.0f);
    sp70 = fclMakeVec2(338.0f, 404.0f);
    fclObjStartPosition(*(void **)(work + 0xDE4), sp78, sp70, 0, 0, 0);
    fclObjSetAnchorPosition(*(void **)(work + 0xDE0), 0x57, 47.0f);
    fclObjStartAlpha(*(void **)(work + 0xDE0), 0U, 0xFFU, 0U, 0xA, 0);
    sp68 = fclMakeVec2(338.0f, 404.0f);
    sp60 = fclMakeVec2(338.0f, 404.0f);
    fclObjStartPosition(*(void **)(work + 0xDE0), sp68, sp60, 0, 0, 0);
    fclObjChangeFlagBit(*(void **)(work + 0xDE0), 0, 1);
    fclObjSetAnchorPosition(*(void **)(work + 0xDCC), 0x41, 123.0f);
    fclObjStartAlpha(*(void **)(work + 0xDCC), 0U, 0xFFU, 0U, 6, 7);
    fclObjSetAnchorPosition(*(void **)(work + 0xDD0), 0x41, 125.0f);
    fclObjStartAlpha(*(void **)(work + 0xDD0), 0U, 0xFFU, 0U, 6, 7);
    *(s8 *)(work + 0x11) = 0;
    *(s16 *)(work + 2) = 0;
    *(s16 *)(work + 4) = 0;
    *(s8 *)work = 0x24;
}
// FUN_002DD230
void fclShopLayoutPanels(void *arg0) {
    Vec2f sp48;
    Vec2f sp40;
    Vec2f sp38;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    void *s1;

    s1 = fclObjectGetWork(work->field_D90);
    sp48 = fclMakeVec2(311.0f, -17.0f);
    fclObjStartPosition(work->field_D90, *(Vec2f *)((u8 *)s1 + 0x2C), sp48, 0, 0xA, 0);
    s1 = fclObjectGetWork(work->field_D94);
    sp40 = fclMakeVec2(564.0f, -17.0f);
    fclObjStartPosition(work->field_D94, *(Vec2f *)((u8 *)s1 + 0x2C), sp40, 0, 0xA, 0);
    s1 = fclObjectGetWork(work->field_D8C);
    sp38 = fclMakeVec2(-610.0f, -620.0f);
    fclObjStartPosition(work->field_D8C, *(Vec2f *)((u8 *)s1 + 0x2C), sp38, 0, 0xA, 0);
    fclObjChangeFlagBit(work->field_D8C, 3, 1);
    fclObjStartTween(work->field_D8C, 0.0f, 360.0f, 0, 0x708, 0);
    fclObjChangeFlagBit(work->field_D8C, 6, 0);
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
   indexed as ((void **)(work + 0xF18))[kind], which gives retail's
   `addu idx, idx, work`.  The outer dispatch is a switch written 1, 2, 0
   (retail tests 0, 2, 1); the inner one owns jtbl_007489F0 (cases 20-28). */
// FUN_002DD3B0
void fclShopDrawScrollThumb(void *arg0) {
    u8 *work;
    s16 id;
    s16 j;
    u32 count;
    f32 y;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    if (*(s8 *)(work + 0xC24) == 0) {
        return;
    }
    if (yListCountFor(((void **)(work + 0xF18))[*(s8 *)(work + 0x11)]) >= 2) {
        if (*(s8 *)(work + 0x11) == 0) {
            if (yListCountFor(((void **)(work + 0xF18))[*(s8 *)(work + 0x11)]) >= 3) {
                *(f32 *)(work + 0xC) = 91.0f / (f32)(yListCountFor(((void **)(work + 0xF18))[*(s8 *)(work + 0x11)]) - 2);
            } else {
                *(f32 *)(work + 0xC) = 91.0f;
            }
            y = 146.0f + *(f32 *)(work + 0xC) * (f32)(*(s16 *)(work + 2) - 1);
        } else {
            *(f32 *)(work + 0xC) = 91.0f / (f32)(yListCountFor(((void **)(work + 0xF18))[*(s8 *)(work + 0x11)]) - 1);
            y = 146.0f + *(f32 *)(work + 0xC) * (f32)*(s16 *)(work + 2);
        }
        fclDrawEquipSprite(0x36, fclMakeVec2((f32)0x246, y), 88.0f, fclPackRgba(0xFF, 0xFF, 0x6D, 0x31), *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC94)) + 0x62), 0, D_00794EA0);
        fclObjChangeFlagBit(*(void **)(work + 0xC94), 0, 0);
        fclObjChangeFlagBit(*(void **)(work + 0xC98), 0, 0);
    } else {
        fclObjChangeFlagBit(*(void **)(work + 0xC94), 0, 1);
        fclObjChangeFlagBit(*(void **)(work + 0xC98), 0, 1);
    }
    id = yListValueAtFor(((void **)(work + 0xF18))[*(s8 *)(work + 0x11)], *(s16 *)(work + 2));
    shopDrawLabel(70.0f, (const char *)((void *)datGetItemNameId(id)), fclMakeVec2(129.0f, 134.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    count = datItemPrice((s32)id) / 5U;
    fclDrawNumber(fclMakeVec2(486.0f, 145.0f), 70.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, count, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), *fclShopSpriteResource(work), 0xA9);
    fclDrawEquipSprite(0x47, fclMakeVec2((f32)0x202, 147.0f), 70.0f, fclPackRgba(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    fclDrawNumber(fclMakeVec2((f32)0x221, 145.0f), 70.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, datItemCount(id) & 0xFF, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), *fclShopSpriteResource(work), 0xA9);
    if (datItemValue(id) == 0) {
        for (j = 0; j < 15; j++) {
            fclDrawEquipSprite(0x3C, fclMakeVec2((f32)(j * 22 + 111), 178.0f), 86.0f, fclPackRgba(0xFF, 0xFF, 0xC7, 0x31), 0xFF, 0, D_00794ED0);
        }
    } else {
        fclMesWindowDraw(datItemValue(id), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF), 1, 0, 3, 0x57, 109.0f, 169.0f, 70.0f);
    }
    switch (*(s8 *)(work + 0x11)) {
    case 1:
        fclDrawEquipSprite(fclShopStatusFlagToCode((s16)datEntryGetFlags(id)) & 0xFFFF, fclMakeVec2(86.0f, 135.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        switch ((s16)fclShopStatusFlagToCode((s16)datEntryGetFlags(id))) {
        case 20:
        case 21:
        case 22:
        case 23:
        case 24:
        case 25:
        case 26:
            fclMesWindowDraw((s16)datItemBankOffset(id), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 0, 0x57, 109.0f, 201.0f, 70.0f);
            fclObjSetAnchorPosition(*(void **)(work + 0xCA0), 0x57, 83.0f);
            *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCA0)) + 0x79) = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCA0)) + 0x2C) = fclMakeVec2((f32)0x1E1, 174.0f);
            fclObjSetAnchorPosition(*(void **)(work + 0xCA8), 0x57, 82.0f);
            *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCA8)) + 0x79) = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCA8)) + 0x2C) = fclMakeVec2((f32)0x1E1, 224.0f);
            shopDrawStatAt(func_001068b0(id), func_001068b0(id) & 0xFFFF, fclMakeVec2((f32)0x20E, 202.0f));
            shopDrawStatAt(func_001068e0(id), func_001068e0(id) & 0xFFFF, fclMakeVec2((f32)0x20E, 252.0f));
            break;
        case 27:
            fclMesWindowDraw((s16)datItemBankOffset(id), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 1, 0x57, 109.0f, 201.0f, 70.0f);
            fclObjSetAnchorPosition(*(void **)(work + 0xC9C), 0x57, 81.0f);
            *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC9C)) + 0x79) = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xC9C)) + 0x2C) = fclMakeVec2((f32)0x1E1, 174.0f);
            fclObjSetAnchorPosition(*(void **)(work + 0xCA4), 0x57, 80.0f);
            *(FclDrawColor *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCA4)) + 0x79) = fclMakeDrawColor(0xFE, 0xEF, 0x80, 0xFF);
            *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCA4)) + 0x2C) = fclMakeVec2((f32)0x1E1, 224.0f);
            shopDrawStatAt(func_00106940(id), func_00106940(id) & 0xFFFF, fclMakeVec2((f32)0x20E, 202.0f));
            shopDrawStatAt(func_00106970(id), func_00106970(id) & 0xFFFF, fclMakeVec2((f32)0x20E, 252.0f));
            break;
        case 28:
            fclMesWindowDraw((s16)datItemBankOffset(id), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 2, 0x57, 109.0f, 201.0f, 70.0f);
            fclObjSetAnchorPosition(*(void **)(work + 0xCB8), 0x57, 84.0f);
            *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCB8)) + 0x62) = 0x7F;
            *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCB8)) + 0x2C) = fclMakeVec2(478.0f, 166.0f);
            fclObjSetAnchorPosition(*(void **)(work + 0xEAC), 0x57, 84.0f);
            *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEAC)) + 0x62) = 0x7F;
            *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEAC)) + 0x2C) = fclMakeVec2((f32)0x1DD, 216.0f);
            break;
        }
        break;
    case 2:
    case 0:
        if (*(s8 *)(work + 0x11) == 2) {
            fclDrawEquipHelpSprite(0x1B, fclMakeVec2(86.0f, 135.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            fclMesWindowDraw((s16)datItemBankOffset(id), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 4, 0x57, 109.0f, 201.0f, 70.0f);
        } else {
            fclDrawEquipHelpSprite(0x1A, fclMakeVec2(86.0f, 135.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
            fclMesWindowDraw((s16)datItemBankOffset(id), fclPackRgba(0xDF, 0x6C, 0, 0xFF), 1, 0, 7, 0x57, 109.0f, 201.0f, 70.0f);
        }
        fclObjSetAnchorPosition(*(void **)(work + 0xCB8), 0x56, 84.0f);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCB8)) + 0x62) = 0x7F;
        *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCB8)) + 0x2C) = fclMakeVec2(478.0f, 166.0f);
        fclObjSetAnchorPosition(*(void **)(work + 0xEAC), 0x56, 84.0f);
        *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEAC)) + 0x62) = 0x7F;
        *(Vec2f *)((u8 *)fclObjectGetWork(*(void **)(work + 0xEAC)) + 0x2C) = fclMakeVec2((f32)0x1DD, 216.0f);
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
// FUN_002DE5A0
void fclShopDrawItemCompare(void *arg0) {
    u8 *work;
    f32 size;
    f32 x;
    f32 labelSize;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    fclDrawEquipSprite(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF7C), fclMakeVec2(378.0f, 245.0f), 69.0f, fclPackRgba(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 0) {
        size = 70.0f;
        x = (f32)0x177;
        fclDrawEquipSprite(2, fclMakeVec2(x, 243.0f), 70.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(5, fclMakeVec2(420.0f, 246.0f), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize = 70.0f, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0))), fclMakeVec2(420.0f, (f32)0x10F), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    } else {
        size = 70.0f;
        x = (f32)0x177;
        fclDrawEquipSprite(2, fclMakeVec2(x, 243.0f), 70.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(5, fclMakeVec2(420.0f, 246.0f), 69.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize = 70.0f, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 0))), fclMakeVec2(420.0f, (f32)0x10F), fclPackRgba(0xFF, 0xEF, 0x81, 0xFF));
    }
    fclDrawEquipSprite(0x1B, fclMakeVec2(378.0f, (f32)0x12F), 69.0f, fclPackRgba(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 1) {
        fclDrawEquipSprite(3, fclMakeVec2(x, (f32)0x12D), size, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(6, fclMakeVec2(420.0f, (f32)0x131), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1))), fclMakeVec2(420.0f, 330.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    } else {
        fclDrawEquipSprite(3, fclMakeVec2(x, (f32)0x12D), size, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(6, fclMakeVec2(420.0f, (f32)0x131), 69.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 1))), fclMakeVec2(420.0f, 330.0f), fclPackRgba(0xFF, 0xEF, 0x81, 0xFF));
    }
    fclDrawEquipSprite(0x1C, fclMakeVec2(378.0f, 368.0f), 69.0f, fclPackRgba(0, 0xFF, 0x96, 0), 0xFF, 0, D_00795E60);
    if (*(s8 *)(work + 7) == 2) {
        fclDrawEquipSprite(3, fclMakeVec2(x, 366.0f), size, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(7, fclMakeVec2(420.0f, (f32)0x171), 69.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2))), fclMakeVec2(420.0f, 394.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    } else {
        fclDrawEquipSprite(3, fclMakeVec2(x, 366.0f), size, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        fclDrawEquipSprite(7, fclMakeVec2(420.0f, (f32)0x171), 69.0f, fclPackRgba(0, 0xFF, 0xEF, 0x80), 0xFF, 0, D_00795E30);
        shopDrawLabel(labelSize, (const char *)((void *)datGetItemNameId((s32)func_00106cd0(*(s8 *)((u8 *)(*(s8 *)(work + 8) + (u32)work) + 0xF73), 2))), fclMakeVec2(420.0f, 394.0f), fclPackRgba(0xFF, 0xEF, 0x81, 0xFF));
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
// Draws the item detail block (header, name, count, and the flag icon) for item arg1; arg2 is the draw alpha/mode.
// FUN_002DF020
void fclShopDrawItemDetail(void *arg0, s16 arg1, s32 arg2) {
    extern u8 D_0063FAA0[];
    extern Vec2f uGpffffa888;
    u8 *work;
    u32 count;
    Vec2f pos;

    work = *(u8 **)((u8 *)arg0 + 0x38);
    switch (*(s8 *)(work + 0x11)) {
    case 0:
        fclDrawEquipHelpSprite(0x1A, fclMakeVec2(97.0f, 178.0f), 13.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        break;
    case 1:
        fclDrawEquipSprite(fclShopStatusFlagToCode((s16)datEntryGetFlags(arg1)) & 0xFFFF, fclMakeVec2(97.0f, 178.0f), 13.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        break;
    case 2:
        fclDrawEquipHelpSprite(0x1B, fclMakeVec2(97.0f, 178.0f), 13.0f, fclPackRgba(0, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E30);
        break;
    }
    shopDrawLabel(13.0f, (const char *)((void *)datGetItemNameId(arg1)), fclMakeVec2(140.0f, 178.0f), fclPackRgba(0x2D, 0x2D, 0x2D, 0xFF));
    count = datItemPrice((s32)arg1) / 5U;
    fclDrawNumber(fclMakeVec2(448.0f, 185.0f), 13.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, count, 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), *fclShopSpriteResource(work), 0xA9);
    fclDrawEquipSprite(0x47, fclMakeVec2(476.0f, 187.0f), 13.0f, fclPackRgba(0x2D, 0x2D, 0x2D, 0x2D), 0xFF, 0, D_00795E60);
    pos = uGpffffa888;
    if (*(s16 *)(work + 0x12) < 10) {
        pos.x = pos.x - 8.0f;
    }
    fclDrawNumber(pos, 13.0f, fclMakeDrawColor(0x2D, 0x2D, 0x2D, 0xFF), 0x10, 5, *(s16 *)(work + 0x12), 9, 0x7B, (s32)resourceFindByName((char *)(D_0063FB50)), *fclShopSpriteResource(work), 0xA9);
    fclDrawNumber(fclMakeVec2((f32)0x1F1, 247.0f), 1.0f, fclMakeDrawColor(0xDF, 0x6C, 0, *(u8 *)((u8 *)fclObjectGetWork(*(void **)(work + 0xCC8)) + 0x62)), 0x1B, 0, arg2 & 0xFF, 0x2F, 0, (s32)resourceFindByName((char *)(D_0063FAA0)), (s32)resourceFindByName((char *)(D_0063FAA0)), 0xA9);
}

// FUN_002DF4C0
void fclShopStartRevealByMode(void *arg0) {
    Vec2f spA8;
    Vec2f spA0;
    Vec2f sp98;
    Vec2f sp90;
    Vec2f sp88;
    Vec2f sp80;
    Vec2f sp78;
    Vec2f sp70;
    Vec2f sp68;
    Vec2f sp60;
    Vec2f sp58;
    Vec2f sp50;
    Vec2f sp48;
    Vec2f sp40;
    Vec2f sp38;
    Vec2f sp30;
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);
    void *r;

    if (work->field_C24 == 1) {
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x2B));
        fclObjStartRevealScale(work->field_CE4, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        spA8 = fclMakeVec2(67.0f, 140.0f);
        spA0 = fclMakeVec2(67.0f, 140.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CE4, spA8, spA0, 0, 5, 0);
        fclObjStartAlpha(work->field_CE4, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x2C));
        fclObjStartRevealScale(work->field_CE8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        sp98 = fclMakeVec2((f32)0x22F, 140.0f);
        sp90 = fclMakeVec2((f32)0x22F, 140.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CE8, sp98, sp90, 0, 5, 0);
        fclObjStartAlpha(work->field_CE8, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x28));
        fclObjStartRevealScale(work->field_CD8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->field_CD8, 0xFF, 0, 0, 5, 0);
        sp88 = fclMakeVec2(48.0f, 127.0f);
        sp80 = fclMakeVec2(48.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CD8, sp88, sp80, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x29));
        fclObjStartRevealScale(work->field_CDC, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->field_CDC, 0xFF, 0, 0, 5, 0);
        sp78 = fclMakeVec2(584.0f, 127.0f);
        sp70 = fclMakeVec2(584.0f, 127.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CDC, sp78, sp70, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
    } else {
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x2A));
        fclObjStartRevealScale(work->field_CE0, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        sp68 = fclMakeVec2(63.0f, 148.0f);
        sp60 = fclMakeVec2(63.0f, 148.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CE0, sp68, sp60, 0, 5, 0);
        fclObjStartAlpha(work->field_CE0, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x2C));
        fclObjStartRevealScale(work->field_CE8, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        sp58 = fclMakeVec2((f32)0x222, 148.0f);
        sp50 = fclMakeVec2((f32)0x222, 148.0f + 5.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CE8, sp58, sp50, 0, 5, 0);
        fclObjStartAlpha(work->field_CE8, 0xFF, 0, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x27));
        fclObjStartRevealScale(work->field_CD4, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->field_CD4, 0xFF, 0, 0, 5, 0);
        sp48 = fclMakeVec2(46.0f, 136.0f);
        sp40 = fclMakeVec2(46.0f, 136.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CD4, sp48, sp40, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
        r = sdkSpriteNewNode((u32)(work->field_F28), (u32)(0x29));
        fclObjStartRevealScale(work->field_CDC, 1.0f, 1.0f, 1.0f, 0.0f, 0, 5, 0);
        fclObjStartAlpha(work->field_CDC, 0xFF, 0, 0, 5, 0);
        sp38 = fclMakeVec2((f32)0x232, 136.0f);
        sp30 = fclMakeVec2((f32)0x232, 136.0f + 2.0f * (sdkSpriteScaledHeight((u8 *)r) / 10.0f));
        fclObjStartPosition(work->field_CDC, sp38, sp30, 0, 5, 0);
        sdkSpriteFreeNode((u8 *)r);
    }
}

// Returns 1 when item id arg0 is one of the shop's special items (18 fixed ids); else 0.
// FUN_002DFD00
s32 fclShopIsSpecialItem(u16 arg0) {
    if (arg0 == 0x540 || arg0 == 0x503 || arg0 == 0x596 || arg0 == 0x517 ||
        arg0 == 0x52C || arg0 == 0x555 || arg0 == 0x54D || arg0 == 0x54B ||
        arg0 == 0x56A || arg0 == 0x519 || arg0 == 0x598 || arg0 == 0x582 ||
        arg0 == 0x599 || arg0 == 0x51A || arg0 == 0x59A || arg0 == 0x580 ||
        arg0 == 0x559 || arg0 == 0x59B) {
        return 1;
    }
    return 0;
}

// Plays the cue for item arg0: a special item uses cue 8, any other item cue 7, through fclShopPlaySound.
// FUN_002DFE00
void fclShopPlayItemCue(void *arg0) {
    s32 r;
    s32 idx;
    u16 v;
    u32 t[2];
    void *work = *(void **)((u8 *)arg0 + 0x38);

    idx = *(s16 *)((u8 *)work + 0xC18) * 2;
    r = datItemMoonGateFirst(*(s16 *)(idx + (u32)work + 0x16));
    v = (u16)((r & 0xFFF00) >> 8);
    t[0] = v;
    t[1] = 0;
    if (fclShopIsSpecialItem(v) == 0) {
        *(s8 *)((u8 *)work + 0x10) = fclShopPlaySound(arg0, 7, t, 0);
    } else {
        *(s8 *)((u8 *)work + 0x10) = fclShopPlaySound(arg0, 8, t, 0);
    }
}

// Plays a sound through a fresh handle: sets its cue (arg1), optional parameters (arg2), and when arg3 is 1 stops it at once; returns the handle.
// FUN_002DFEC0
s32 fclShopPlaySound(void *arg0, s32 arg1, void *arg2, s8 arg3) {
    s8 handle;
    s32 v;
    void *t;

    t = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 0xF2C);
    handle = (s8)nmMesWindowAcquire(*(void **)((u8 *)t + 0x110));
    v = handle;
    if (arg2 != 0) {
        nmMesWindowSetSlotString(handle, 0, arg2);
    }
    nmMesWindowShowSlotRecord(handle, (s16)arg1);
    if (arg3 == 1) {
        nmMesWindowSetSlotParam(v, 0);
        nmMesWindowSetSlotFlag(v, 0);
        nmMesWindowRequestRefresh();
    }
    return v;
}

// Plays a sound through a fresh handle with two parameter sets (arg2 and arg3); arg4 == 1 stops it at once. Returns the handle.
// FUN_002DFF90
s32 fclShopPlaySoundParams(void *arg0, s32 arg1, void *arg2, void *arg3, s8 arg4) {
    s8 handle;
    s32 v;
    void *t;

    t = *(void **)((u8 *)*(void **)((u8 *)arg0 + 0x38) + 0xF2C);
    handle = (s8)nmMesWindowAcquire(*(void **)((u8 *)t + 0x110));
    v = handle;
    nmMesWindowSetSlotString(handle, 0, arg2);
    nmMesWindowSetSlotString(handle, 1, arg3);
    nmMesWindowShowSlotRecord(handle, (s16)arg1);
    if (arg4 == 1) {
        nmMesWindowSetSlotParam(v, 0);
        nmMesWindowSetSlotFlag(v, 0);
        nmMesWindowRequestRefresh();
    }
    return v;
}

// Draws an item name label at position arg2 (x offset 77), with the name taken from the item table entry for arg1.
// FUN_002E0080
void fclShopDrawItemText(void *arg0, s8 arg1, Vec2f arg2, void *arg3) {
    frFontExDrawTextDeferred(77.0f + arg2.x, arg2.y, 1.0f, (s32)(u32)arg3, 0, 1,
                  (const char *)datPersonaNamePart1(arg1), 8, 0, D_00795E60);
}

// Item panel task update: copies the 0xF0-byte item block into the work, then draws the panel's sprite pair depending on the two state checks.
/* measured: 452B/464B, only three zero-tail words. Canonical byte color and
   opacity parameters preserve constant-first loads and the float-first draw
   argument sequence. Distinct p+4 spellings preserve both retail addresses. */
// FUN_002E0100
s32 fclShopItemPanelUpdate(u8 *arg0) {
    ShopWork *work = *(ShopWork **)((u8 *)arg0 + 0x38);

    memcpy((u8 *)work + 4, fclSpriteUpdateTweens(&work->field_4), 0xF0);
    if (fclObjTestFlagBit(arg0, 0) == 1) {
        if (fclObjTestFlagBit(arg0, 0xD) == 1) {
            void *t = PrimAllocQueueNode();
            *(void (**)(void))((u8 *)t + 8) = fclMiscInitRenderStates;
            *(s32 *)((u8 *)t + 0x10) = 0;
            PrimAppendNode(&D_00793E80[work->field_FC * 0x30], t);
            sdkSpriteDrawQueued(
                work->field_2C, work->field_30, work->field_8,
                fclPackRgba(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                0,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        } else {
            sdkSpriteDrawQueued(
                work->field_2C, work->field_30, work->field_8,
                fclPackRgba(0xFF, work->field_79, work->field_7A, work->field_7B),
                work->field_62,
                work->field_F8,
                (void *)work->field_F4,
                1,
                work->field_100,
                work->field_102,
                work->field_C4,
                work->field_94,
                work->field_A0,
                &D_00793E80[work->field_FC * 0x30]);
        }
    }
    return 0;
}
// Item panel task destroy: calls the shop work's destroy jump-table entry.
// FUN_002E02D0
void fclShopItemPanelDestroy(u8 *arg0) {
    jtbl_008873EC[0](*(void **)((u8 *)arg0 + 0x38));
}

// Creates the item panel task under arg0 (allocates the 0x104-byte work, registers its update and destroy callbacks, and loads the resource entries for index arg1).
/* The promoted resource index supplies both the table lookup and SDK sprite lookup. */
// FUN_002E0300
/* measured: retail hoists the loop-invariant 0xFF and 1.0f into the preheader. */
#pragma opt_loop_invariants on
s32 fclShopItemPanelCreate(s32 arg0, s16 arg1, u32 arg2) {
    s32 r;
    s32 resourceIndex;
    u8 *w;
    u8 *src;
    s16 i;
    void *h;
    chkmemAllocSiteTag(&D_0063FAC0, 0x1D6A);
    w = D_008873F4[0](1, 0x104, 0x40000);
    r = (s32)kwlnTaskCreateChild((void *)(arg0), (const void *)((char *)&D_0063FB70), 0xF, 0, 0, fclShopItemPanelUpdate, fclShopItemPanelDestroy, (u8 *)(w));
    w[0] = 0;
    *(s16 *)(w + 0xF8) = arg1;
    *(u32 *)(w + 0xF4) = arg2;
    resourceIndex = arg1;
    src = D_0063F560 + resourceIndex * 8;
    for (i = 0; i < 3; i++) {
        *(f32 *)(w + i * 8 + 0x1C) = *(f32 *)src;
        *(f32 *)(w + i * 8 + 0x20) = *(f32 *)(src + 4);
        w[i + 0x60] = 0xFF;
        *(f32 *)(w + i * 4 + 0x98) = 1.0f;
        *(f32 *)(w + i * 4 + 0x8C) = 1.0f;
        *(s32 *)(w + i * 4 + 0xBC) = 0;
        w[i * 4 + 0x73] = 0xFF;
        w[i * 4 + 0x72] = 0xFF;
        w[i * 4 + 0x71] = 0xFF;
    }
    *(f32 *)(w + 8) = 100.0f;
    *(u32 *)(w + 0xFC) = 0x55;
    *(s16 *)(w + 4) = 0;
    h = sdkSpriteNewNode((u32)(*(void **)(w + 0xF4)), (u32)resourceIndex);
    *(s16 *)(w + 0x100) = (s32)(sdkSpriteScaledWidth(h) / 2.0f);
    *(s16 *)(w + 0x102) = (s32)(sdkSpriteScaledHeight(h) / 2.0f);
    sdkSpriteFreeNode(h);
    return r;
}
// measured: closes the opt_loop_invariants bracket opened above and restores
// the -O2 baseline for the rest of the file.
#pragma opt_loop_invariants off
